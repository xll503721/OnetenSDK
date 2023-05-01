//
//  cache_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "cache_loader.h"

#include <ad/oneten_ad_sdk.h>

BEGIN_NAMESPACE_ONETEN_AD

CacheLoader::CacheLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    cache_service_ = std::make_shared<CacheService>();
}

void CacheLoader::Save(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement) {
    super_class::Save(ad_source, placement);
    
    cache_service_->Save(ad_source, placement);
}

void CacheLoader::End() {
    super_class::End();
};


END_NAMESPACE_ONETEN_AD
