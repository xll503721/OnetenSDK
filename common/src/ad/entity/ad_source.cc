//
//  placement.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#include "ad_source.h"
#include <ad/oneten_ad_sdk.h>
#include <string/string.h>

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
    otlog_info << "";
    delegate_ = delegate;
    
    BASE_PLATFORM::Platform::Var category_type = 1;
    BASE_PLATFORM::Platform::Var ad_source_type = 2;
    
    std::unordered_map<std::string, BASE_PLATFORM::Platform::Var> map;
    
    BASE_PLATFORM::Platform::Var var(1);
    map["1"] = var;
    
    std::vector<BASE_PLATFORM::Platform::Var> vector;
    BASE_PLATFORM::Platform::Var user_info = &map;
    
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

void AdSource::Parse(const std::string& json_string) {
    json_.Parse(json_string.c_str(), json_string.size());
    BASE_JSON::Json clazz_name = json_["class_name"];
    if (clazz_name.IsString()) {
        clazz_name_ = clazz_name.AsString();
    }
}

std::string AdSource::Identifier() {
    
}

std::shared_ptr<BASE_PLATFORM::Platform> AdSource::GetPlatform() {
    return platform_;
}

#pragma mark - AdSourceDelegate
void AdSource::LoadCompletion(int32_t categroy_type, ONETEN::Error* error) {
    if (delegate_) {
        delegate_->LoadCompletion(categroy_type, error);
    }
}

END_NAMESPACE_ONETEN_AD
