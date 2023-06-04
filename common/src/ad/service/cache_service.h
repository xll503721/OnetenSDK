//
//  ad_srouce_service.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef ONETEN_AD_SDK_CACHE_SERVICE_H
#define ONETEN_AD_SDK_CACHE_SERVICE_H

#include <ad/entity/ad_source.h>
#include <ad/entity/placement.h>
#include <ad/entity/placement_cache.h>
#include <ad/model/cache_model.h>
#include <error.h>

BEGIN_NAMESPACE_ONETEN_AD

class CacheService: public ONETEN::Object {
    
public:
    CacheService();
    virtual ~CacheService();
    
    std::shared_ptr<CacheService> shared_from_this() {
        return std::static_pointer_cast<CacheService>(ONETEN::Object::shared_from_this());
    }
    
    void Save(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement);
    void Remove(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement);
    
    std::shared_ptr<AdSourceCache> GetHighestPrice(const std::string& placement_id);
    
private:
    void Sort(std::shared_ptr<AdSourceCache> obj1, std::shared_ptr<AdSourceCache> obj2);
    
private:
    std::shared_ptr<CacheModel> cacheModel_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_SERVICE_H */
