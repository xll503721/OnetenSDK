//
//  waterfall_loader.cc
//  TenoneSDK
//
//  Created by li zhixuan on 2022/11/5.
//

#include "waterfall_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_TENONE_AD

WaterfallLoader::WaterfallLoader(std::shared_ptr<LoaderInterface> loader):MainLoader(loader) {
    
}

void WaterfallLoader::Classify(std::shared_ptr<Placement> placement) {
    super_class::Classify(placement);
    
    printf("WaterfallLoader Classify\n");
    
    TENONE_AD::OnetenAdSDK::GetInstance().GetMainLoader()->Flow(nullptr);
//    std::vector<std::shared_ptr<AdSource>> ad_sources = placement->GetRequestAdSources();
//    for (std::shared_ptr<AdSource> ad_source: ad_sources) {
//        TENONE_AD::OnetenAdSDK::GetInstance().GetMainLoader()->Flow(ad_source);
//    }
}


END_NAMESPACE_TENONE_AD
