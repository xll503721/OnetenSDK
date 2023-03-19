//
//  oneten_ad_sdk.hpp
//  SDKCommon
//
//  Created by li zhixuan on 2023/3/16.
//

#ifndef oneten_ad_sdk_h
#define oneten_ad_sdk_h

#include "oneten_object.h"

#include "loader/loader.h"

BEGIN_NAMESPACE_TENONE_AD

class OnetenAdSDK: OnetenObject {
    
public:
    static OnetenAdSDK &GetInstance();
    void Start(const std::string& app_id);
    void LoadAd(const std::string& placement_id, void* delegate);
    bool IsReady(const std::string& placement_id);
    void ShowAd(const std::string& placement_id, void* delegate);
    
    std::shared_ptr<LoaderInterface> GetMainLoader();
    
private:
    OnetenAdSDK();
    ~OnetenAdSDK();
    
    std::shared_ptr<LoaderInterface> main_loader_;
};

END_NAMESPACE_TENONE_AD

#endif /* oneten_ad_sdk_h */
