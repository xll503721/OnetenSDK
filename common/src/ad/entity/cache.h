//
//  cache.hpp
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/4/30.
//

#ifndef ONETEN_AD_SDK_CACHE_H
#define ONETEN_AD_SDK_CACHE_H

#include "placement_cache.h"
#include "ad_source_cache.h"
#include "entity_interface.h"

BEGIN_NAMESPACE_ONETEN_AD

template<typename T>
class Cache: public EntityInterface {
    
public:
    
    virtual T get(const std::string& key) = 0;
    
protected:
    std::shared_ptr<PlacementCache> placement_cache_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_CACHE_H */
