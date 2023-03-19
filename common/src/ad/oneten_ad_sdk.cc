//
//  oneten_ad_sdk.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2023/3/16.
//

#include "oneten_ad_sdk.h"
#include "loader/main_loader.h"
#include "loader/waterfall_loader.h"
#include "loader/header_bid_loader.h"
#include "loader/placement_loader.h"
#include "loader/normal_loader.h"
#include "loader/cache_loader.h"

BEGIN_NAMESPACE_TENONE_AD

OnetenAdSDK &OnetenAdSDK::GetInstance() {
    static OnetenAdSDK ad_sdk;
    return ad_sdk;
}

OnetenAdSDK::OnetenAdSDK() {
}

OnetenAdSDK::~OnetenAdSDK() {
}

void OnetenAdSDK::Start(const std::string& app_id) {
//    printf("%s", app_id.c_str());
}

std::shared_ptr<LoaderInterface> OnetenAdSDK::GetMainLoader() {
    return main_loader_;
}

void OnetenAdSDK::LoadAd(const std::string& placement_id, void* delegate) {
    std::shared_ptr<MainLoader> main_loader = std::make_shared<MainLoader>(nullptr);
    std::shared_ptr<PlacementLoader> placement_loader = std::make_shared<PlacementLoader>(main_loader);
    std::shared_ptr<WaterfallLoader> waterfall_loader = std::make_shared<WaterfallLoader>(placement_loader);
    std::shared_ptr<HeaderBidLoader> header_bid_loader = std::make_shared<HeaderBidLoader>(waterfall_loader);
    std::shared_ptr<NormalLoader> normal_loader = std::make_shared<NormalLoader>(header_bid_loader);
    std::shared_ptr<CacheLoader> cache_loader = std::make_shared<CacheLoader>(normal_loader);
    
    main_loader_ = cache_loader;
    
    main_loader_->Start(placement_id);
}

bool OnetenAdSDK::IsReady(const std::string& placement_id) {
    
}

void OnetenAdSDK::ShowAd(const std::string& placement_id, void* delegate) {
    
}

END_NAMESPACE_TENONE_AD
