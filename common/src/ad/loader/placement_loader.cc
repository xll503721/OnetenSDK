//
//  placement_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "placement_loader.h"

#include <ad/oneten_ad_sdk.h>
#include <ad/entity/placement.h>

BEGIN_NAMESPACE_ONETEN_AD

PlacementLoader::PlacementLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    otlog_info << "";
}

void PlacementLoader::Start(const std::string& placement_id) {
    super_class::Start(placement_id);
    otlog_info << "";
    
    std::shared_ptr<Placement> placement = std::make_shared<Placement>();
    ONETEN_AD::OnetenAdSDK::GetInstance().GetWaterfallLoader()->Classify(placement);
}

void PlacementLoader::RequestPlacement(const std::string& placement_id) {
    otlog_info << "";
}

void PlacementLoader::End() {
    super_class::End();
    otlog_info << "";
};


END_NAMESPACE_ONETEN_AD
