//
//  header_bid_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "normal_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_ONETEN_AD

NormalLoader::NormalLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    ad_source_service_ = std::make_shared<AdSourceService>();
}

void NormalLoader::Flow(std::shared_ptr<AdSource> ad_source) {
    super_class::Flow(ad_source);
    
    if (ad_source->GetType() == AdSource::Type::kNormal) {
        printf("NormalLoader Flow\n");
        ad_source_service_->Load(ad_source, [=](int32_t categroy_type, ONETEN::Error* error) {
            if (!error) {
                std::string placement_id;
                ONETEN_AD::OnetenAdSDK::GetInstance().EndAdLoad(placement_id);
                return;
            }
            ONETEN_AD::OnetenAdSDK::GetInstance().GetWaterfallLoader()->StartFlow(ad_source->GetLevel() + 1);
        });
    }
}

void NormalLoader::End() {
    super_class::End();
    
    printf("NormalLoader End\n");
};


END_NAMESPACE_ONETEN_AD
