//
//  placement.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#include "ad_source.h"
#include "../oneten_ad_sdk.h"
#include <OTOnetenSDK.h>

BEGIN_NAMESPACE_ONETEN_AD

AdSource::AdSource() {
    level_ = 0;
    clazz_name_ = "TENSigmobSource";
    
    PLATFORM_INIT(clazz_name_)
}

AdSource::Type AdSource::GetType() {
    return AdSource::Type::kNormal;
}

void AdSource::Test(std::string test, std::string test2) {
    
}

void AdSource::Load() {
    void* category_type;
    void* ad_source_type;
    void* user_info;
    PLATFORM_PERFORM(category_type, ad_source_type, user_info)
    
//    platform_->Perform("", nullptr);
}

void AdSource::SetLevel(int32_t level) {
    level_ = level;
}

int32_t AdSource::GetLevel() {
    return level_;
}

std::string AdSource::GetClassName() {
    return clazz_name_;
}

void AdSource::Parse(std::string json_string) {
    
}

END_NAMESPACE_ONETEN_AD
