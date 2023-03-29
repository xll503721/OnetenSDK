//
//  OTOneTenAdSDK.m
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/11.
//

#import "OTOneTenAdSDK.h"
#include "oneten_ad_sdk.h"

@interface OTOneTenAdSDK ()

//@property ONETEN_AD::OneTenAdSDK sdk;

@end

@implementation OTOneTenAdSDK

+ (OTOneTenAdSDK *)defalutAdSDK {
    static OTOneTenAdSDK *shareInstance = nil;
    static dispatch_once_t onceToken ;
    
    dispatch_once(&onceToken, ^{
        shareInstance = [[OTOneTenAdSDK alloc] init];
    }) ;
    return shareInstance;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        
    }
    return self;
}

- (void)startWithAppId:(NSString *)appId {
    _appId = appId;
    ONETEN_AD::OnetenAdSDK::GetInstance().Register(appId.UTF8String);
}

- (void)loadWithPlacementId:(NSString *)placementId {
    ONETEN_AD::OnetenAdSDK::GetInstance().StartAdLoad(placementId.UTF8String, nullptr);
}

- (BOOL)showWithSuperView:(UIView *)view placementId:(NSString *)placementId error:(NSError **)error {
    ONETEN_AD::OnetenAdSDK::GetInstance().ShowAd(placementId.UTF8String, nullptr);
}

@end

BEGIN_NAMESPACE_ONETEN_AD

//void OneTenAdSDK::LoadCompletion() {
//    
//}

END_NAMESPACE_ONETEN_AD
