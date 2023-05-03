//
//  placement_cache.h
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/5/3.
//

#ifndef ONETEN_AD_SDK_PLACEMENT_CACHE_H
#define ONETEN_AD_SDK_PLACEMENT_CACHE_H

#include "entity_interface.h"
#include "ad_source_cache.h"
#include "placement.h"

BEGIN_NAMESPACE_ONETEN_AD

class PlacementCache: public EntityInterface {
    
public:
    std::string Identifier() override;
    
    static std::shared_ptr<PlacementCache> Convert(std::shared_ptr<Placement> placement);
    
    bool AddAdSourceCache(std::shared_ptr<AdSourceCache> ad_source_cache);
    
    using AdSourceCacheList = std::vector<std::shared_ptr<AdSourceCache>>;
    AdSourceCacheList GetAdSourceCaches();
    
private:
    
    std::map<std::string, AdSourceCacheList> ad_source_caches_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_PLACEMENT_CACHE_H */
