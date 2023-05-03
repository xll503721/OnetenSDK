//
//  OTOneTenAdSDK.m
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/11.
//

#import "OTOnetenAdSDK.h"
#include "oneten_ad_sdk.h"
#include "oneten_ad_sdk_delegate.h"

@interface OTOnetenAdSDK ()

@property ONETEN_AD::AdSDKDelegate sdk_delegate;

@end

@implementation OTOnetenAdSDK

- (instancetype)init
{
    self = [super init];
    if (self) {
        _sdk_delegate.SetOCPrt((__bridge void *)self);
    }
    return self;
}

- (void)startWithAppId:(NSString *)appId {
    _appId = appId;
    ONETEN_AD::OnetenAdSDK::GetInstance().Register(appId.UTF8String);
}

- (void)loadWithPlacementId:(NSString *)placementId {
    [self loadWithPlacementId:placementId userInfo:nil];
}

- (void)loadWithPlacementId:(NSString *)placementId userInfo:(NSDictionary<NSString *, NSString *> *)userInfo {
    std::map<std::string, std::string> user_info;
    for (int i = 0; i < userInfo.allKeys.count; i++) {
        NSString *key = userInfo.allKeys[i];
        NSString *value = userInfo.allValues[i];
        
        std::string c_key(key.UTF8String);
        std::string c_value(value.UTF8String);
        user_info[c_key] = c_value;
    }
    ONETEN_AD::OnetenAdSDK::GetInstance().StartAdLoad(placementId.UTF8String, user_info, _sdk_delegate);
}

- (OTAdViewController *)showWithSuperView:(UIView *)view placementId:(NSString *)placementId error:(NSError **)error {
    bool isReady = ONETEN_AD::OnetenAdSDK::GetInstance().IsReady(placementId.UTF8String);
    if (!isReady) {
        *error = [NSError errorWithDomain:@"ad show" code:1000 userInfo:@{}];
        return nil;
    }
    
    OTAdViewController *adViewController = [[OTAdViewController alloc] init];
    ONETEN_AD::OnetenAdSDK::GetInstance().ShowAd(placementId.UTF8String, _sdk_delegate);
    return adViewController;
}

@end

BEGIN_NAMESPACE_ONETEN_AD

void AdSDKDelegate::SetOCPrt(void *prt) {
    oc_prt_ = prt;
}

void AdSDKDelegate::LoadSucceed() {
    if (oc_prt_) {
        OTOnetenAdSDK *ad_sdk = (__bridge OTOnetenAdSDK *)oc_prt_;
        if (ad_sdk.loadCompletion) {
            ad_sdk.loadCompletion(@"", nil, nil);
        }
        
    }
}

END_NAMESPACE_ONETEN_AD
