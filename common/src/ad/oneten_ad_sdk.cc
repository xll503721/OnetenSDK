//
//  oneten_ad_sdk.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2023/3/16.
//

#include "oneten_ad_sdk.h"

BEGIN_NAMESPACE_TENONE_AD

OnetenAdSDK &OnetenAdSDK::GetInstance() {
    static OnetenAdSDK ad_sdk;
    return ad_sdk;
}

OnetenAdSDK::OnetenAdSDK() {
}

OnetenAdSDK::~OnetenAdSDK() {
}

void OnetenAdSDK::Start(const std::string& app_id) {
    printf("%s", app_id.c_str());
    
}

void OnetenAdSDK::LoadAd(const std::string& placement_id, void* delegate) {
    
}

bool OnetenAdSDK::IsReady(const std::string& placement_id) {
    
}

void OnetenAdSDK::ShowAd(const std::string& placement_id, void* delegate) {
    
}

END_NAMESPACE_TENONE_AD
