//
//  oneten_ad_sdk.hpp
//  SDKCommon
//
//  Created by li zhixuan on 2023/3/16.
//

#ifndef ONETEN_AD_SDK_AD_SDK_H
#define ONETEN_AD_SDK_AD_SDK_H

#include "oneten_object.h"

#include "ad/loader/loader.h"
#include "oneten_ad_sdk_delegate.h"

BEGIN_NAMESPACE_ONETEN_AD

#pragma mark - OnetenAdSDK

class OnetenAdSDK: OnetenObject {
    
public:
    static OnetenAdSDK &GetInstance();
    void Register(const std::string& app_id);
    void StartAdLoad(const std::string& placement_id, AdSDKDelegate& delegate);
    void EndAdLoad(const std::string& placement_id);
    bool IsReady(const std::string& placement_id);
    void ShowAd(const std::string& placement_id, AdSDKDelegate& delegate);
    
    std::shared_ptr<LoaderInterface> GetMainLoader();
    std::shared_ptr<LoaderInterface> GetWaterfallLoader();
    std::shared_ptr<LoaderInterface> GetRequestLoader();
    std::shared_ptr<LoaderInterface> GetCacheLoader();
    
    
    
private:
    OnetenAdSDK();
    ~OnetenAdSDK();
    
    std::shared_ptr<LoaderInterface> start_loader_;
    std::shared_ptr<LoaderInterface> waterfall_loader_;
    std::shared_ptr<LoaderInterface> request_loader_;
    std::shared_ptr<LoaderInterface> cache_loader_;
    
    AdSDKDelegate* delegate_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SDK_H */
