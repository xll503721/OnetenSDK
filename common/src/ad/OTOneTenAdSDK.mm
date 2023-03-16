//
//  OTOneTenAdSDK.m
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/11.
//

#import "OTOneTenAdSDK.h"
#include "oneten_ad_sdk.h"

@implementation OTOneTenAdSDK

+ (OTOneTenAdSDK *)defalutAdSDK {
    static OTOneTenAdSDK *shareInstance = nil;
    static dispatch_once_t onceToken ;
    
    dispatch_once(&onceToken, ^{
        shareInstance = [[OTOneTenAdSDK alloc] init];
    }) ;
    return shareInstance;
}

- (void)startWithAppId:(NSString *)appId {
    _appId = appId;
    TENONE_AD::OnetenAdSDK::GetInstance().Start(appId.UTF8String);
}

- (void)loadWithPlacementId:(NSString *)placementId {
    TENONE_AD::OnetenAdSDK::GetInstance().LoadAd(placementId.UTF8String, nullptr);
}

- (BOOL)showWithSuperView:(UIView *)view placementId:(NSString *)placementId error:(NSError **)error {
    TENONE_AD::OnetenAdSDK::GetInstance().ShowAd(placementId.UTF8String, nullptr);
}

@end
