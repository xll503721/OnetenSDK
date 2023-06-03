//
//  placement.cpp
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#include "ad_source.h"
#include <ad/oneten_ad_sdk.h>
#include <string/string.h>
#include <thread/thread_pool.h>

BEGIN_NAMESPACE_ONETEN_AD

AdSource::AdSource(std::shared_ptr<BASE_JSON::Json> json):
level_(0),
json_(json) {
    Parse();
}

AdSource::~AdSource() {
    
}

AdSource::Type AdSource::GetType() {
    return AdSource::Type::kNormal;
}

void AdSource::InitSDK() {
    
}

void AdSource::Load(std::shared_ptr<AdSourceDelegate> delegate) {
    otlog_info << "";
    delegate_ = delegate;
    
    BASE_THREAD::ThreadPool::DefaultPool().Schedule(BASE_THREAD::Thread::Type::kMain, [=] () {
        auto category_type = PLATFORM_VAR_GENERATE(static_cast<int32_t>(category_));
        auto ad_source_type = PLATFORM_VAR_GENERATE(2);
        
        std::unordered_map<std::string, BASE_PLATFORM::Platform::Var> map;
        map["1"] = PLATFORM_VAR_GENERATE(1);
        
        std::vector<BASE_PLATFORM::Platform::Var> vector;
        BASE_PLATFORM::Platform::Var user_info = &map;
        PLATFORM_INVOKE(&category_type, &ad_source_type, &user_info)
    });
}

void AdSource::SetLevel(int32_t level) {
    level_ = level;
}

int32_t AdSource::GetLevel() {
    return level_;
}

std::string AdSource::GetClassName() {
    return clazz_name_;
}

void AdSource::Parse() {
    BASE_JSON::Json clazz_name = json_->operator[]("clazz_name");
    if (clazz_name.IsString()) {
        clazz_name_ = clazz_name.AsString();
        SET_PLATFORM_GENERATE_NAME(clazz_name_)
    }
    
    BASE_JSON::Json id = json_->operator[]("id");
    if (id.IsString()) {
        identifier_ = id.AsString();
    }
    
    BASE_JSON::Json category = json_->operator[]("category");
    if (category.IsInteger()) {
        category_ = static_cast<Category>(category.AsInteger());
    }
}

std::string AdSource::Identifier() {
    
}

#pragma mark - getter

std::shared_ptr<BASE_JSON::Json> AdSource::GetJson() {
    return json_;
}

#pragma mark - AdSourceDelegate
void AdSource::LoadCompletion(int32_t categroy_type, ONETEN::Error* error) {
    if (error) {
        otlog_info << "failed";
    } else {
        otlog_info << "success";
    }
    if (delegate_) {
        BASE_THREAD::ThreadPool::DefaultPool().Schedule(BASE_THREAD::Thread::Type::kOther, [=] () {
            delegate_->LoadCompletion(categroy_type, error);
        });
    }
}

void AdSource::ShowCompletion(int32_t categroy_type, ONETEN::Error* error) {
    if (error) {
        otlog_info << "failed";
    } else {
        otlog_info << "success";
    }
    if (delegate_) {
        BASE_THREAD::ThreadPool::DefaultPool().Schedule(BASE_THREAD::Thread::Type::kOther, [=] () {
            delegate_->ShowCompletion(categroy_type, error);
        });
    }
}

void AdSource::CloseCompletion(int32_t categroy_type, ONETEN::Error* error) {
    if (error) {
        otlog_info << "failed";
    } else {
        otlog_info << "success";
    }
    if (delegate_) {
        BASE_THREAD::ThreadPool::DefaultPool().Schedule(BASE_THREAD::Thread::Type::kOther, [=] () {
            delegate_->CloseCompletion(categroy_type, error);
        });
    }
}

void AdSource::ClickCompletion(int32_t categroy_type, ONETEN::Error* error) {
    if (error) {
        otlog_info << "failed";
    } else {
        otlog_info << "success";
    }
    if (delegate_) {
        BASE_THREAD::ThreadPool::DefaultPool().Schedule(BASE_THREAD::Thread::Type::kOther, [=] () {
            delegate_->ClickCompletion(categroy_type, error);
        });
    }
}

END_NAMESPACE_ONETEN_AD
