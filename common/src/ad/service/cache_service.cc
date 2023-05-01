//
//  OTAdSourceService.m
//  oneten_ad_service
//
//  Created by li zhixuan on 2023/3/26.
//

#include "cache_service.h"
#include <ad/entity/cache.h>

BEGIN_NAMESPACE_ONETEN_AD

CacheService::~CacheService() {

}

void CacheService::Save(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement) {
    std::shared_ptr<Cache> cache = std::make_shared<Cache>(ad_source, placement);
    
}

END_NAMESPACE_ONETEN_AD
