#import "OTOnetenSDK.h"
#import "OTOnetenAdSDK.h"
#import "OTAdSourceProtocol.h"
#import <objc/runtime.h>

#include "ad/oneten_ad_sdk.h"

#define OTOnetenMsgSend(...) ((void (*)(void *, SEL, void *))objc_msgSend)(__VA_ARGS__)

@interface OTOnetenSDK ()

@end

@implementation OTOnetenSDK

+ (OTOnetenSDK *)defalutSDK {
    static OTOnetenSDK *shareInstance = nil;
    static dispatch_once_t onceToken ;
    
    dispatch_once(&onceToken, ^{
        shareInstance = [[OTOnetenSDK alloc] init];
    }) ;
    return shareInstance;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _adSDK = [[OTOnetenAdSDK alloc] init];
        [self _setPlatformInfo];
    }
    return self;
}

- (void)_setPlatformInfo {
    ONETEN::Platform::SetInitMehtod([=] (const std::string& class_name) {
        NSString *className = [NSString stringWithUTF8String:class_name.c_str()];
        id obj = [self platformInitWithClazzName:className];
        return (__bridge_retained void *)obj;
    });
    ONETEN::Platform::SetPerformMehtod([=] (const void* platform_obj, const std::string& method_name, const std::vector<std::string>& params_name, const std::vector<ONETEN::Platform::Var*>& params){
        if (!platform_obj) {
            return;
        }
        
        NSMutableArray<NSString *> *paramStrings = @[].mutableCopy;
        NSString *methodName = [[NSString stringWithUTF8String:method_name.c_str()] lowercaseString];
        for (int32_t i = 0; i < params_name.size(); i++) {
            std::string name = params_name[i];
            __block NSString *ocName = [NSString stringWithUTF8String:name.c_str()];
            
            NSArray<NSString *> *names = [ocName componentsSeparatedByString:@"_"];
            if (names.count > 0) {
                ocName = @"";
                [names enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    NSString *firstWord = obj;
                    if (idx != 0 || i == 0) {
                        firstWord = [firstWord capitalizedString];
                    }
                    ocName = [ocName stringByAppendingString:firstWord];
                }];
            }
            
            [paramStrings addObject:ocName];
        }
        
        methodName = [methodName stringByAppendingFormat:@"With%@", paramStrings.firstObject];
        [paramStrings removeObjectAtIndex:0];
        if (paramStrings.count > 0) {
            NSString *allParamsString = [paramStrings componentsJoinedByString:@":"];
            methodName = [methodName stringByAppendingFormat:@":%@:", allParamsString];
        }
        
        NSMutableArray<id> *ocParmas = @[].mutableCopy;
        for (ONETEN::Platform::Var* param: params) {
            auto type = param->GetType();
            switch (type) {
                case ONETEN::Platform::Var::Type::kTypeInt: {
                    [ocParmas addObject:[NSNumber numberWithInt:param->GetData()]];
                }
                    break;
                    
                default:
                    break;
            }
        }
        
        [self platformPerformWithObject:(__bridge id)platform_obj selectorString:methodName params:ocParmas];
    });
}

- (instancetype)platformInitWithClazzName:(NSString *)clazzName {
    Class clazz = NSClassFromString(clazzName);
    if (!clazz) {
        return nil;
    }
    
    id obj = [[clazz alloc] init];
    return obj;
}

- (id)platformPerformWithObject:(id)obj selectorString:(NSString *)selectorString params:(NSArray *)params {
    SEL selector = NSSelectorFromString(selectorString);
    if (![obj respondsToSelector:selector]) {
        //alert
        return;
    }
    
    NSMethodSignature *methodSignature = [obj methodSignatureForSelector:selector];
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
    [invocation setTarget:obj];
    [invocation setSelector:selector];
    
    __block int32_t argIndex = 2;
    [params enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [invocation setArgument:&obj atIndex:argIndex];
        argIndex++;
    }];
    
    [invocation invoke];
}

- (void)initAppId:(NSString *)appId type:(OTOneTenSDKType)type {
//    bool isiOS = ONETEN::Platform::isPlatform(ONETEN::Platform::PlatformType::kPlatformTypeiOS);
    
//    ONETEN::Platform::init_fun_ = nullptr;
    switch (type) {
        case OTOneTenSDKTypeAd: {
            [self.adSDK startWithAppId:appId];
        }
            break;
            
        default:
            break;
    }
}

@end
