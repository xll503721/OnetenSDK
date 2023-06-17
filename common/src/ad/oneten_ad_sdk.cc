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

#include <ad/model/placement_model.h>
#include <ad/model/cache_model.h>
#include <ad/model/model_factory.h>

#include <thread/thread_pool.h>
#include <storage/database/database.h>
#include <device/device.h>

BEGIN_NAMESPACE_ONETEN_AD

thread_local std::shared_ptr<LoaderInterface> OnetenAdSDK::start_loader_ = nullptr;
thread_local std::shared_ptr<LoaderInterface> OnetenAdSDK::waterfall_loader_ = nullptr;
thread_local std::shared_ptr<LoaderInterface> OnetenAdSDK::request_loader_ = nullptr;
thread_local std::shared_ptr<LoaderInterface> OnetenAdSDK::cache_loader_ = nullptr;

static const std::string database_name = "sdk_db";

OnetenAdSDK &OnetenAdSDK::GetInstance() {
    static OnetenAdSDK ad_sdk;
    return ad_sdk;
}

OnetenAdSDK::OnetenAdSDK() {
    REGISTER_MODEL(PlacementModel)
    REGISTER_MODEL(CacheModel)
    
    cache_service_ = std::make_shared<CacheService>();
    
    auto db = BASE_STORAGE_DATABASE::DataBase(BASE_DEVICE::Device::DefaultInstance().GetFile()->GetCachesPath() + "/" + database_name);
    const char* sql_create_table =
            "CREATE TABLE IF NOT EXISTS Users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "name TEXT,"
            "age INTEGER);";
    db.CreateTable(sql_create_table);
    
    const char* sql_insert_data = "Users";
    auto age = PLATFORM_VAR_GENERATE(1);
    auto name = PLATFORM_VAR_GENERATE("Alice");
    std::map<std::string, BASE_PLATFORM::Platform::Var> map;
    map["name"] = name;
    map["age"] = age;
    
    BASE_PLATFORM::Platform::Var row_var = &map;
    db.Insert(sql_insert_data, row_var);
    
    auto select_age = PLATFORM_VAR_GENERATE(0);
    auto select_name = PLATFORM_VAR_GENERATE("");
    std::map<std::string, BASE_PLATFORM::Platform::Var> select_map;
    select_map["name"] = select_name;
    select_map["age"] = select_age;
    
    BASE_PLATFORM::Platform::Var select_row_var = &select_map;
    db.Select(sql_insert_data, select_row_var);
    printf("");
}

OnetenAdSDK::~OnetenAdSDK() {
}

void OnetenAdSDK::Register(const std::string& app_id) {
//    printf("%s", app_id.c_str());
}

std::shared_ptr<LoaderInterface> OnetenAdSDK::GetMainLoader() {
    otlog_info << "start loader:" << start_loader_;
    return start_loader_;
}

std::shared_ptr<LoaderInterface> OnetenAdSDK::GetWaterfallLoader() {
    otlog_info << "waterfall loader:" << waterfall_loader_;
    return waterfall_loader_;
}

std::shared_ptr<LoaderInterface> OnetenAdSDK::GetCacheLoader() {
    otlog_info << "cache loader:" << cache_loader_;
    return cache_loader_;
}

std::shared_ptr<LoaderInterface> OnetenAdSDK::GetRequestLoader() {
    otlog_info << "request loader:" << request_loader_;
    return request_loader_;
}

void OnetenAdSDK::StartAdLoad(const std::string& placement_id, std::map<std::string, std::string>& user_info, AdSDKDelegate& delegate) {
    delegate_ = &delegate;
    user_info_ = user_info;
    
    BASE_THREAD::ThreadPool::DefaultPool().Schedule(BASE_THREAD::Thread::Type::kOther, [=](){
        otlog_info << "placement id:" << placement_id;
        std::shared_ptr<MainLoader> start_main_loader = std::make_shared<MainLoader>(nullptr);
        std::shared_ptr<PlacementLoader> placement_loader = std::make_shared<PlacementLoader>(start_main_loader);
        
        std::shared_ptr<MainLoader> waterfall_main_loader = std::make_shared<MainLoader>(nullptr);
        std::shared_ptr<WaterfallLoader> waterfall_loader = std::make_shared<WaterfallLoader>(waterfall_main_loader);
        
        std::shared_ptr<MainLoader> request_main_loader = std::make_shared<MainLoader>(nullptr);
        std::shared_ptr<HeaderBidLoader> header_bid_loader = std::make_shared<HeaderBidLoader>(request_main_loader);
        std::shared_ptr<NormalLoader> normal_loader = std::make_shared<NormalLoader>(header_bid_loader);
        
        std::shared_ptr<MainLoader> save_main_loader = std::make_shared<MainLoader>(nullptr);
        std::shared_ptr<CacheLoader> cache_loader = std::make_shared<CacheLoader>(save_main_loader);
        
        start_loader_ = placement_loader;
        waterfall_loader_ = waterfall_loader;
        request_loader_ = normal_loader;
        cache_loader_ = cache_loader;
        
        start_loader_->Start(placement_id);
    });
}

void OnetenAdSDK::EndAdLoad(const std::string& placement_id) {
    start_loader_->End();
    waterfall_loader_->End();
    request_loader_->End();
    cache_loader_->End();
    
    if (delegate_) {
        delegate_->LoadSucceed();
    }
}

void OnetenAdSDK::DidShowAd(const std::string& placement_id) {
    if (delegate_) {
        delegate_->ShowSucceed();
    }
}

void OnetenAdSDK::DidCloseAd(const std::string& placement_id) {
    if (delegate_) {
        delegate_->CloseSucceed();
    }
}

void OnetenAdSDK::DidClickAd(const std::string& placement_id) {
    if (delegate_) {
        delegate_->ClickSucceed();
    }
}

bool OnetenAdSDK::IsReady(const std::string& placement_id) {
    auto cache = cache_service_->GetHighestPrice(placement_id);
    bool isReady = (cache && cache->IsReady());
    otlog_info << "placement id:" << placement_id << ", is ready:" << isReady;
    return isReady;
}

std::shared_ptr<AdSourceCache> OnetenAdSDK::ShowAd(const std::string& placement_id, AdSDKDelegate& delegate) {
    auto cache = cache_service_->GetHighestPrice(placement_id);
    return cache;
}

END_NAMESPACE_ONETEN_AD
