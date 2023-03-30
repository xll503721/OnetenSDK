//
//  OTOneTenAdSDK.m
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/11.
//

#import "OTOneTenAdSDK.h"
#include "oneten_ad_sdk.h"
#include "oneten_ad_sdk_delegate.h"

@interface OTOneTenAdSDK ()

@property ONETEN_AD::AdSDKDelegate sdk_delegate;

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
        _sdk_delegate.SetOCPrt((__bridge_retained void *)self);
    }
    return self;
}

- (void)startWithAppId:(NSString *)appId {
    _appId = appId;
    ONETEN_AD::OnetenAdSDK::GetInstance().Register(appId.UTF8String);
}

- (void)loadWithPlacementId:(NSString *)placementId {
    ONETEN_AD::OnetenAdSDK::GetInstance().StartAdLoad(placementId.UTF8String, _sdk_delegate);
}

- (BOOL)showWithSuperView:(UIView *)view placementId:(NSString *)placementId error:(NSError **)error {
    ONETEN_AD::OnetenAdSDK::GetInstance().ShowAd(placementId.UTF8String, _sdk_delegate);
}

@end

BEGIN_NAMESPACE_ONETEN_AD

void AdSDKDelegate::SetOCPrt(void *prt) {
    oc_prt_ = prt;
}

void AdSDKDelegate::LoadSucceed() {
    if ([OTOneTenAdSDK defalutAdSDK].loadCompletion) {
        [OTOneTenAdSDK defalutAdSDK].loadCompletion(@"", nil, @{});
    }
}

END_NAMESPACE_ONETEN_AD
