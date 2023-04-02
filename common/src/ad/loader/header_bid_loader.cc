//
//  header_bid_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "header_bid_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_ONETEN_AD

HeaderBidLoader::HeaderBidLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    ad_source_service_ = std::make_shared<AdSourceService>();
}

void HeaderBidLoader::Flow(std::shared_ptr<AdSource> ad_source) {
    super_class::Flow(ad_source);
    
    if (ad_source->GetType() == AdSource::Type::kS2S ||
        ad_source->GetType() == AdSource::Type::kC2S) {
        printf("HeaderBidLoader Flow\n");
        
        ad_source_service_->Load(ad_source, [=](int categroy_type, ONETEN::Error* error) {
            if (!error) {
                std::string placement_id;
                ONETEN_AD::OnetenAdSDK::GetInstance().EndAdLoad(placement_id);
                return;
            }
            ONETEN_AD::OnetenAdSDK::GetInstance().GetWaterfallLoader()->StartFlow(ad_source->GetLevel() + 1);
        });
    }
}

void HeaderBidLoader::End() {
    super_class::End();
    
    printf("HeaderBidLoader End\n");
};


END_NAMESPACE_ONETEN_AD
