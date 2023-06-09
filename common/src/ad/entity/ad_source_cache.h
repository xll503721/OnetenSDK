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
#include <json/json.h>

BEGIN_NAMESPACE_ONETEN_AD

class AdSourceCache: public EntityInterface {
    
public:
    AdSourceCache() = default;
    AdSourceCache(std::shared_ptr<AdSource> ad_source);
    
    static std::shared_ptr<AdSourceCache> Convert(std::shared_ptr<AdSource> ad_source);
    
    std::string Identifier() override;
    AdSource::Style GetStyle();
    bool IsReady();
    
private:
    void Parse();
    
private:
    PLATFORM_GENERATE()
    std::shared_ptr<BASE_JSON::Json> json_;
    
    AdSource::Style style_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_CACHE_H */
