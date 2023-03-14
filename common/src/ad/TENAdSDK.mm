//
//  TENAdSDK.m
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/11.
//

#import "TENAdSDK.h"
//#include "tenone_ad_sdk.h"

@implementation TENAdSDK

+ (TENAdSDK *)defalutAdSDK {
    static TENAdSDK *shareInstance = nil;
    static dispatch_once_t onceToken ;
    
    dispatch_once(&onceToken, ^{
        shareInstance = [[TENAdSDK alloc] init];
    }) ;
    return shareInstance;
}

- (void)test {
    NSLog(@"11");
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _obj = [NSObject new];
    }
    return self;
}

//
//- (void)loadWithPlacementId:(NSString *)placementId category:(TENAdvertSourceCategroyType)type completionHandler:(Completion)completion {
//    TENONE_AD::TenoneAdSdk::GetInstance().LoadAdvert(placementId.UTF8String, (__bridge  void *)[completion copy]);
//}

@end
