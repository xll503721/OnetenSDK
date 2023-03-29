//
//  placement_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/3.
//

#include "placement_loader.h"

#include "../oneten_ad_sdk.h"

BEGIN_NAMESPACE_ONETEN_AD

PlacementLoader::PlacementLoader(std::shared_ptr<LoaderInterface> loader): MainLoader(loader) {
    
}

void PlacementLoader::Start(const std::string& placement_id) {
    super_class::Start(placement_id);
    printf("PlacementLoader Start\n");
    
    ONETEN_AD::OnetenAdSDK::GetInstance().GetWaterfallLoader()->Classify(nullptr);
}

void PlacementLoader::RequestPlacement(const std::string& placement_id) {
    printf("PlacementLoader RequestPlacement\n");
}

void PlacementLoader::End() {
    super_class::End();
    
    printf("PlacementLoader End\n");
};


END_NAMESPACE_ONETEN_AD
