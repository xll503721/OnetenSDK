//
//  header_bid_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "normal_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_TENONE_AD

NormalLoader::NormalLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    
}

void NormalLoader::Flow(std::shared_ptr<AdSource> ad_source) {
    super_class::Flow(ad_source);
    printf("NormalLoader Flow\n");
    
    TENONE_AD::OnetenAdSDK::GetInstance().GetMainLoader()->Save();
}

void NormalLoader::End() {
    super_class::End();
};


END_NAMESPACE_TENONE_AD
