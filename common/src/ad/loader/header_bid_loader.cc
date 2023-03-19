//
//  header_bid_loader.cc
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/3.
//

#include "header_bid_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_TENONE_AD

HeaderBidLoader::HeaderBidLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    
}

void HeaderBidLoader::Flow(std::shared_ptr<AdSource> ad_source) {
    super_class::Flow(ad_source);
    printf("HeaderBidLoader Flow\n");
    
    
}

void HeaderBidLoader::End() {
    super_class::End();
};


END_NAMESPACE_TENONE_AD
