#import "OTOnetenSDK.h"
#import "OTOnetenAdSDK.h"
#import "OTAdSourceProtocol.h"
#import <objc/runtime.h>

#include "ad/oneten_ad_sdk.h"

#define OTOnetenMsgSend(...) ((void (*)(void *, SEL, void *))objc_msgSend)(__VA_ARGS__)

static NSString *kOTOnetenSDKPrefix = @"OT";
static NSString *kOTOnetenSDKDelegate = @"ObjectDelegate";

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
    ONETEN::Platform::SetInitMehtod([=] (const std::string& file_name, const std::string& class_name, void* c_plus_plus_obj) {
        NSString *className = [NSString stringWithUTF8String:class_name.c_str()];
        id target = [self platformInitWithClazzName:className];
        
        if (c_plus_plus_obj) {
            NSString *fileName = [[NSString stringWithUTF8String:file_name.c_str()] lowercaseString];
            NSArray<NSString *> *fileNames = [fileName componentsSeparatedByString:@"_"];
            __block NSString *ocFileName = (NSString *)kOTOnetenSDKPrefix;
            [fileNames enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                ocFileName = [ocFileName stringByAppendingString:[obj capitalizedString]];
            }];
            ocFileName = [ocFileName stringByAppendingString:kOTOnetenSDKDelegate];
            
            id<OTPlatformProtocol> delegate = (id<OTPlatformProtocol>)[self platformInitWithClazzName:ocFileName];
            SEL selector = @selector(setDelegate:);
            if ([target respondsToSelector:selector]) {
                //only set, no alloc，new，copy or mutableCopy,
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
                [target performSelector:selector withObject:delegate];
#pragma clang diagnostic pop
            }
            
            SEL setRawPrtSelector = @selector(setRawPrt:);
            if ([delegate respondsToSelector:setRawPrtSelector]) {
                delegate.rawPrt = c_plus_plus_obj;
            }
        }
        
        return (__bridge_retained void *)target;
    });
    
    ONETEN::Platform::SetPerformMehtod([=] (const void* platform_obj, const std::string& file_name, const std::string& method_name, bool is_set_delegate, const std::vector<std::string>& params_name, const std::vector<ONETEN::Platform::Var*>& params) -> void* {
        if (!platform_obj) {
            return nullptr;
        }
        
        NSMutableArray<NSString *> *paramStrings = @[].mutableCopy;
        NSString *methodName = [NSString stringWithUTF8String:method_name.c_str()];
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
        
        methodName = [methodName stringByAppendingFormat:@"With%@:", paramStrings.firstObject];
        [paramStrings removeObjectAtIndex:0];
        if (paramStrings.count > 0) {
            NSString *allParamsString = [paramStrings componentsJoinedByString:@":"];
            methodName = [methodName stringByAppendingFormat:@"%@:", allParamsString];
        }
        
        id target = (__bridge id)platform_obj;
        SEL selector = NSSelectorFromString(methodName);
        if (![target respondsToSelector:selector]) {
            //alert
            return nullptr;
        }
        
        NSMethodSignature *methodSignature = [target methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        [invocation setTarget:target];
        [invocation setSelector:selector];
        
        __block int32_t argIndex = 2;
        NSMutableArray<id> *ocParmas = @[].mutableCopy;
        for (ONETEN::Platform::Var* param: params) {
            auto type = param->GetType();
            switch (type) {
                case ONETEN::Platform::Var::Type::kTypeInt: {
                    int32_t var = param->GetDataInt32();
                    [invocation setArgument:&var atIndex:argIndex];
                }
                    break;
                case ONETEN::Platform::Var::Type::kTypeMap: {
                    std::unordered_map<std::string, ONETEN::Platform::Var>* var_map = param->GetDataMap();
                    NSMutableDictionary<NSString *, id> *var_dict = [NSMutableDictionary dictionary];
                    for (auto iter = var_map->begin(); iter != var_map->end(); ++iter) {
                        NSString *key = [NSString stringWithUTF8String:iter->first.c_str()];
                        auto value = iter->second;

                        id ocValue = nil;
                        switch (value.GetType()) {
                            case ONETEN::Platform::Var::Type::kTypeInt:
                                ocValue = [NSNumber numberWithInt:value.GetDataInt32()];
                                break;

                            default:
                                break;
                        }
                        if (ocValue) {
                            var_dict[key] = ocValue;
                        }
                    }
                    
                    [invocation setArgument:&var_dict atIndex:argIndex];
                }
                    break;
                    
                default:
                    break;
            }
            argIndex++;
        }
        
        [invocation invoke];
        
        if (methodSignature.methodReturnLength) {
            __autoreleasing id returnValue = nil;
            [invocation getReturnValue:&returnValue];
            return (__bridge void *)returnValue;
        }
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
