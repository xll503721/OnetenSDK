//
//  header_bid_loader.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#ifndef ONETEN_AD_SDK_HEADER_BID_LOADER_H
#define ONETEN_AD_SDK_HEADER_BID_LOADER_H

#include "main_loader.h"
#include "../service/ad_srouce_service.h"

BEGIN_NAMESPACE_ONETEN_AD

class HeaderBidLoader: public MainLoader {
    
private:
    using super_class = MainLoader;
    
    std::shared_ptr<AdSourceService> ad_source_service_;
    
public:
    HeaderBidLoader(std::shared_ptr<LoaderInterface> loader);
    void Flow(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement);
    void End();
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_HEADER_BID_LOADER_H */
