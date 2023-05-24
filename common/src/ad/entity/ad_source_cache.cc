//
//  ad_source_cache.cc
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/5/3.
//

#include "ad_source_cache.h"

BEGIN_NAMESPACE_ONETEN_AD

AdSourceCache::AdSourceCache(std::shared_ptr<AdSource> ad_source):
platform_(ad_source->GetPlatform()) {
    
}

std::string AdSourceCache::Identifier() {
    return "2222";
}

std::shared_ptr<AdSourceCache> AdSourceCache::Convert(std::shared_ptr<AdSource> ad_source) {
    std::shared_ptr<AdSourceCache> ad_source_cache = std::make_shared<AdSourceCache>(ad_source);
    return ad_source_cache;
}

void* AdSourceCache::GetPlatformObj() {
    return platform_->GetPlatformObj();
}

AdSource::Category AdSourceCache::GetCategory() {
    return AdSource::Category::kInterstitial;
}

bool AdSourceCache::IsReady() {
    BASE_PLATFORM::Platform::Var type = 1;
    
    PLATFORM_PERFORM(&type);
    return static_cast<bool>(GET_PLATFORM_PERFORM_RESULT);
}

END_NAMESPACE_ONETEN_AD
