//
//  placement.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#include "ad_source.h"
BEGIN_NAMESPACE_ONETEN_AD

AdSource::AdSource() {
    level_ = 0;
    clazz_name_ = "TENSigmobSource";
}

AdSource::Type AdSource::GetType() {
    return AdSource::Type::kNormal;
}

void AdSource::Load() {
    
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

END_NAMESPACE_ONETEN_AD
