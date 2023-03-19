//
//  main_loader.cc
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/11.
//

#include "main_loader.h"

BEGIN_NAMESPACE_TENONE_AD

MainLoader::MainLoader(std::shared_ptr<LoaderInterface> loader)
:mainloader_(loader) {
}

void MainLoader::Start(const std::string& placement_id) {
    if (mainloader_) {
        mainloader_->Start(placement_id);
    }
}

void MainLoader::Flow(std::shared_ptr<AdSource> ad_source) {
    if (mainloader_) {
        mainloader_->Flow(ad_source);
    }
}

void MainLoader::Classify(std::shared_ptr<Placement> placement) {
    if (mainloader_) {
        mainloader_->Classify(placement);
    }
}

void MainLoader::End() {
    if (mainloader_) {
        mainloader_->End();
    }
}

END_NAMESPACE_TENONE_AD
