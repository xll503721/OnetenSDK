//
//  ad_source_cache.cc
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/5/3.
//

#include "ad_source_cache.h"

BEGIN_NAMESPACE_ONETEN_AD

AdSourceCache::AdSourceCache(std::shared_ptr<AdSource> ad_source):
platform_(ad_source->GetPlatform()),
json_(ad_source->GetJson()) {
    Parse();
}

std::string AdSourceCache::Identifier() {
    return identifier_;
}

std::shared_ptr<AdSourceCache> AdSourceCache::Convert(std::shared_ptr<AdSource> ad_source) {
    std::shared_ptr<AdSourceCache> ad_source_cache = std::make_shared<AdSourceCache>(ad_source);
    return ad_source_cache;
}

AdSource::Style AdSourceCache::GetStyle() {
    return style_;
}

void AdSourceCache::Parse() {
    BASE_JSON::Json id = json_->operator[]("id");
    if (id.IsString()) {
        identifier_ = id.AsString();
    }
    
    BASE_JSON::Json style = json_->operator[]("style");
    if (style.IsInteger()) {
        style_ = static_cast<AdSource::Style>(style.AsInteger());
    }
    json_ = nullptr;
}

bool AdSourceCache::IsReady() {
    auto style = PLATFORM_VAR_GENERATE(static_cast<int32_t>(GetStyle()));
    PLATFORM_INVOKE(&style)
    return static_cast<bool>(GET_PLATFORM_INVOKE_RESULT);
}

END_NAMESPACE_ONETEN_AD
