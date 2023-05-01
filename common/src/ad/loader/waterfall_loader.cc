//
//  waterfall_loader.cc
//  TenoneSDK
//
//  Created by li zhixuan on 2022/11/5.
//

#include "waterfall_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_ONETEN_AD

WaterfallLoader::WaterfallLoader(std::shared_ptr<LoaderInterface> loader):MainLoader(loader) {
    
}

void WaterfallLoader::Classify(std::shared_ptr<Placement> placement) {
    super_class::Classify(placement);
    
    placement_ = placement;
    
    printf("WaterfallLoader Classify\n");
    
    StartFlow(0, placement_);
}

void WaterfallLoader::StartFlow(int32_t level, std::shared_ptr<Placement> placement) {
    super_class::StartFlow(level, placement);
    
    printf("WaterfallLoader StartFlow\n");
    InternalStartFlow(level, placement);
}

void WaterfallLoader::InternalStartFlow(int32_t level, std::shared_ptr<Placement> placement) {
    std::vector<std::shared_ptr<AdSource>> ad_sources = placement_->GetRequestAdSources();
    if (level == ad_sources.size()) {
        std::string placement_id;
        ONETEN_AD::OnetenAdSDK::GetInstance().EndAdLoad(placement_id);
        return;
    }
    
    if (ad_sources.size() > level) {
        std::shared_ptr<AdSource> ad_source = ad_sources[level];
        ONETEN_AD::OnetenAdSDK::GetInstance().GetRequestLoader()->Flow(ad_source, placement);
    }
}

void WaterfallLoader::End() {
    super_class::End();
    
    printf("WaterfallLoader End\n");
};

END_NAMESPACE_ONETEN_AD
