//
//  cache_loader.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#ifndef ONETEN_AD_SDK_CACHE_LOADER_H
#define ONETEN_AD_SDK_CACHE_LOADER_H

#include "main_loader.h"

#include <ad/service/cache_service.h>

BEGIN_NAMESPACE_ONETEN_AD

class CacheLoader: public MainLoader {
    
public:
    CacheLoader(std::shared_ptr<LoaderInterface> loader);
    void Save(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement);
    void End();
    
private:
    using super_class = MainLoader;
    
    std::shared_ptr<CacheService> cache_service_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_CACHE_LOADER_H */
