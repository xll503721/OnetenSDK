//
//  main_loader.cc
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/11.
//

#include "main_loader.h"

BEGIN_NAMESPACE_ONETEN_AD

MainLoader::~MainLoader() {
    
}

MainLoader::MainLoader(std::shared_ptr<LoaderInterface> loader)
:mainloader_(loader) {
}

void MainLoader::Start(const std::string& placement_id) {
    if (mainloader_) {
        mainloader_->Start(placement_id);
    }
}

void MainLoader::Classify(std::shared_ptr<Placement> placement) {
    if (mainloader_) {
        mainloader_->Classify(placement);
    }
}

void MainLoader::StartFlow(int32_t level, std::shared_ptr<Placement> placement) {
    if (mainloader_) {
        mainloader_->StartFlow(level, placement);
    }
}

void MainLoader::Flow(std::shared_ptr<AdSource> ad_source, std::shared_ptr<Placement> placement) {
    if (mainloader_) {
        mainloader_->Flow(ad_source, placement);
    }
}

void MainLoader::End() {
    if (mainloader_ && !mainloader_->GetIsEndInvoke()) {
        mainloader_->SetIsEndInvoke(true);
        mainloader_->End();
    }
}

bool MainLoader::GetIsEndInvoke() {
    return is_end_invoke_;
}

bool MainLoader::SetIsEndInvoke(bool is_end_invoke) {
    is_end_invoke_ = is_end_invoke;
}

END_NAMESPACE_ONETEN_AD
