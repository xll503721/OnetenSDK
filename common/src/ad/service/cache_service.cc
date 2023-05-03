//
//  OTAdSourceService.m
//  oneten_ad_service
//
//  Created by li zhixuan on 2023/3/26.
//

#include "cache_service.h"
#include <ad/entity/placement_cache.h>
#include <ad/entity/ad_source_cache.h>
#include <ad/model/model_factory.h>

BEGIN_NAMESPACE_ONETEN_AD

CacheService::~CacheService() {
}

CacheService::CacheService() {
    std::shared_ptr<Model> model = ModelFactory::GetInstance().GetModel(ModelFactory::ModelType::kModelTypeCacheModel);
    cacheModel_ = std::static_pointer_cast<CacheModel>(model);
}

void CacheService::Save(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement) {
    auto placement_cache = PlacementCache::Convert(placement);
    auto ad_source_cache = AdSourceCache::Convert(ad_source);
    
    placement_cache->AddAdSourceCache(ad_source_cache);
    cacheModel_->Save(placement_cache);
}

std::shared_ptr<PlacementCache> CacheService::GetHighestPrice(const std::string& placement_id) {
    
    std::shared_ptr<EntityInterface> entity = cacheModel_->Read(placement_id);
    std::shared_ptr<PlacementCache> placement_cache = std::static_pointer_cast<PlacementCache>(entity);
    
}

void CacheService::Sort(std::shared_ptr<AdSourceCache> obj1, std::shared_ptr<AdSourceCache> obj2) {
    
}

END_NAMESPACE_ONETEN_AD
