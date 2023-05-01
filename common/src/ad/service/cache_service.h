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
#include <error.h>

BEGIN_NAMESPACE_ONETEN_AD

class CacheService: public ONETEN::Object {
    
public:
    virtual ~CacheService();
    
    std::shared_ptr<CacheService> shared_from_this() {
        return std::static_pointer_cast<CacheService>(ONETEN::Object::shared_from_this());
    }
    
    void Save(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement);
    
private:

};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_SERVICE_H */
