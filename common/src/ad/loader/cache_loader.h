//
//  cache_loader.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#ifndef ONETEN_AD_SDK_CACHE_LOADER_H
#define ONETEN_AD_SDK_CACHE_LOADER_H

#include "main_loader.h"

BEGIN_NAMESPACE_ONETEN_AD

class CacheLoader: public MainLoader {
    
private:
    using super_class = MainLoader;
    
public:
    CacheLoader(std::shared_ptr<LoaderInterface> loader);
    void Save();
    void End();
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_CACHE_LOADER_H */
