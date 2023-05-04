//
//  ad_source_cache.h
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/5/3.
//

#ifndef ONETEN_AD_SDK_AD_SOURCE_CACHE_H
#define ONETEN_AD_SDK_AD_SOURCE_CACHE_H

#include "entity_interface.h"
#include "ad_source.h"
#include <platform.h>

BEGIN_NAMESPACE_ONETEN_AD

class AdSourceCache: public EntityInterface {
    
public:
    AdSourceCache() = default;
    AdSourceCache(std::shared_ptr<AdSource> ad_source);
    
    static std::shared_ptr<AdSourceCache> Convert(std::shared_ptr<AdSource> ad_source);
    
    std::string Identifier() override;
    
    void* GetPlatformObj();
    
    AdSource::Category GetCategory();
    
private:
    PLATFORM_DECLARE
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_CACHE_H */
