//
//  header_bid_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "normal_loader.h"

#include <ad/oneten_ad_sdk.h>
#include <ad/entity/cache.h>

BEGIN_NAMESPACE_ONETEN_AD

NormalLoader::NormalLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    otlog_info << "";
    ad_source_service_ = std::make_shared<AdSourceService>();
}

void NormalLoader::Flow(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement) {
    super_class::Flow(ad_source, placement);
    otlog_info << "";
    
    if (ad_source->GetType() == AdSource::Type::kNormal) {
        ad_source_service_->Load(ad_source, [=](int32_t categroy_type, ONETEN::Error* error) {
            if (!error) {
                ONETEN_AD::OnetenAdSDK::GetInstance().GetCacheLoader()->Save(ad_source, placement);
                
                ONETEN_AD::OnetenAdSDK::GetInstance().EndAdLoad(placement->Identifier());
                return;
            }
            ONETEN_AD::OnetenAdSDK::GetInstance().GetWaterfallLoader()->StartFlow(ad_source->GetLevel() + 1, placement);
        });
        
        ad_source_service_->Show([=](int32_t categroy_type, ONETEN::Error* error) {
            if (!error) {
                ONETEN_AD::OnetenAdSDK::GetInstance().DidShowAd(placement->Identifier());
            }
        });
        
        ad_source_service_->Dismiss([=](int32_t categroy_type, ONETEN::Error* error) {
            if (!error) {
                ONETEN_AD::OnetenAdSDK::GetInstance().DidCloseAd(placement->Identifier());
            }
        });
        
        ad_source_service_->Click([=](int32_t categroy_type, ONETEN::Error* error) {
            if (!error) {
                ONETEN_AD::OnetenAdSDK::GetInstance().DidClickAd(placement->Identifier());
                return;
            }
        });
    }
}

void NormalLoader::End() {
    super_class::End();
    otlog_info << "";
};


END_NAMESPACE_ONETEN_AD
