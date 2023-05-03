//
//  placement_cache.cc
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/5/3.
//

#include "placement_cache.h"

BEGIN_NAMESPACE_ONETEN_AD

std::shared_ptr<PlacementCache> PlacementCache::Convert(std::shared_ptr<Placement> placement) {
    std::shared_ptr<PlacementCache> placement_cache;
    return placement_cache;
}

std::string PlacementCache::Identifier() {
    
}

bool PlacementCache::AddAdSourceCache(std::shared_ptr<AdSourceCache> ad_source_cache) {
    AdSourceCacheList list;
    if (ad_source_caches_.find(ad_source_cache->Identifier()) == ad_source_caches_.end()) {
        list = ad_source_caches_[ad_source_cache->Identifier()];
    }
    list.push_back(ad_source_cache);
    ad_source_caches_[ad_source_cache->Identifier()] = list;
}

PlacementCache::AdSourceCacheList PlacementCache::GetAdSourceCaches() {
    AdSourceCacheList list;
    for (auto it_map = ad_source_caches_.begin(); it_map != ad_source_caches_.end(); it_map ++) {
        auto ad_source_cache_list = it_map->second;
        for (int i = 0; i < ad_source_cache_list.size(); i++) {
            auto ad_source_cache = ad_source_cache_list[i];
            list.push_back(ad_source_cache);
        }
    }
    return list;
}

END_NAMESPACE_ONETEN_AD
