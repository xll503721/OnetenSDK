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
    
}

std::string AdSourceCache::Identifier() {
    return identifier_;
}

std::shared_ptr<AdSourceCache> AdSourceCache::Convert(std::shared_ptr<AdSource> ad_source) {
    std::shared_ptr<AdSourceCache> ad_source_cache = std::make_shared<AdSourceCache>(ad_source);
    return ad_source_cache;
}

AdSource::Category AdSourceCache::GetCategory() {
    return AdSource::Category::kInterstitial;
}

void* AdSourceCache::GetPlatformObj() {
    return platform_->GetPlatformObj();
}

bool AdSourceCache::IsReady() {
    auto type = PLATFORM_VAR_GENERATE(static_cast<int32_t>(GetCategory()));
    PLATFORM_INVOKE(&type)
    return static_cast<bool>(GET_PLATFORM_INVOKE_RESULT->GetBool());
}

END_NAMESPACE_ONETEN_AD
