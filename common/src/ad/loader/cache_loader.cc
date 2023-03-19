//
//  cache_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "cache_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_TENONE_AD

CacheLoader::CacheLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    
}

void CacheLoader::Save() {
    super_class::Save();
    printf("CacheLoader Save\n");
    
}

void CacheLoader::End() {
    super_class::End();
};


END_NAMESPACE_TENONE_AD