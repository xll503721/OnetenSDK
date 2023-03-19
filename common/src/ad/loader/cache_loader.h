//
//  cache_loader.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/3.
//

#ifndef TENONE_AD_SDK_CACHE_LOADER_H
#define TENONE_AD_SDK_CACHE_LOADER_H

#include "main_loader.h"

BEGIN_NAMESPACE_TENONE_AD

class CacheLoader: public MainLoader {
    
private:
    using super_class = MainLoader;
    
public:
    CacheLoader(std::shared_ptr<LoaderInterface> loader);
    void Save();
    void End();
};

END_NAMESPACE_TENONE_AD

#endif /* TENONE_AD_SDK_CACHE_LOADER_H */
