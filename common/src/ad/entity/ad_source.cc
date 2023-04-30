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
}

AdSource::~AdSource() {
    
}

AdSource::Type AdSource::GetType() {
    return AdSource::Type::kNormal;
}

void AdSource::InitSDK() {
    PLATFORM_INIT_DELEGATE(clazz_name_, shared_from_this())
}

void AdSource::Load(std::shared_ptr<AdSourceDelegate> delegate) {
    delegate_ = delegate;
    
    ONETEN::Platform::Var category_type = 1;
    ONETEN::Platform::Var ad_source_type = 2;
    
    std::unordered_map<std::string, ONETEN::Platform::Var> map;
    
    ONETEN::Platform::Var var(1);
    map["1"] = var;
    
    std::vector<ONETEN::Platform::Var> vector;
    ONETEN::Platform::Var user_info = &map;
    
    PLATFORM_PERFORM(&category_type, &ad_source_type, &user_info);
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

void AdSource::LoadCompletion(int32_t categroy_type, ONETEN::Error* error) {
    if (delegate_) {
        delegate_->LoadCompletion(categroy_type);
    }
}

END_NAMESPACE_ONETEN_AD
