//
//  cache.hpp
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/4/30.
//

#ifndef ONETEN_AD_SDK_CACHE_H
#define ONETEN_AD_SDK_CACHE_H

#include "placement.h"
#include "ad_source.h"
#include "entity_interface.h"
#include <oneten_object.h>

BEGIN_NAMESPACE_ONETEN_AD

class Cache: public ONETEN::Object, public EntityInterface {
    
public:
    Cache(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement);
    
    std::string Identifier() override;
    
private:
    std::shared_ptr<Placement> placement_;
    std::shared_ptr<AdSource> ad_source_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_CACHE_H */
