//
//  platform.cc
//  OneTenSDK
//
//  Created by li zhixuan on 2023/4/9.
//

#include "platform.h"
#include <string/string.h>
#include <storage/memory/storage_memory.h>
#include <ad/entity/ad_source.h>

BEGIN_NAMESPACE_ONETEN

Platform::PlatformInit Platform::init_fun_ = nullptr;
Platform::PlatformPerform Platform::perform_fun_ = nullptr;

Platform::Platform(const std::string& class_name, std::shared_ptr<void> c_plus_plus_obj):
platform_obj_(nullptr),
c_plus_plus_obj_(c_plus_plus_obj) {
}

bool Platform::isPlatform(PlatformType type) {
    bool is_platform = false;
    switch (type) {
#ifdef OS_IOS
        case PlatformType::kPlatformTypeiOS: {
            is_platform = true;
        }
            break;
#endif
#ifdef OS_MAX
        case PlatformType::kPlatformTypeMac: {

            is_platform = true;
        }
            break;
#endif
#ifdef OS_ANDROID
        case PlatformType::kPlatformTypeAndroid: {
            is_platform = true;
        }
            break;
#endif
            
        default:
            break;
    }
    return is_platform;
}

Platform::PlatformType Platform::platform() {
#ifdef OS_IOS
    return PlatformType::kPlatformTypeiOS;
#endif
#ifdef OS_MAX
    return PlatformType::kPlatformTypeMac;
#endif
#ifdef OS_ANDROID
    return PlatformType::kPlatformTypeAndroid;
#endif
}

void Platform::SetInitMehtod(PlatformInit method) {
    init_fun_ = method;
}

void Platform::SetPerformMehtod(PlatformPerform method) {
    perform_fun_ = method;
}

void Platform::Init(const std::string& file_name, const std::string& class_name, void* c_plus_plus_obj) {
    if (!init_fun_) {
        return nullptr;
    }
    
    auto file_name_string = file_name;
    BASE_STRING::ReplaceAll(file_name_string, ".cc", "");
    
    platform_obj_ = init_fun_(file_name_string, class_name, c_plus_plus_obj);
    if (!platform_obj_) {
        
    }
}

void Platform::Perform(const std::string& file_name, const std::string& method_name, bool is_set_delegate, const std::string& params_name, ONETEN::Platform::Var* params, ...) {
    if (!platform_obj_) {
        return;
    }

    std::vector<ONETEN::Platform::Var*> params_vector;
    params_vector.push_back(params);
    
    va_list args;
    va_start(args, params);
    ONETEN::Platform::Var* arg;
    while ((arg = va_arg(args, ONETEN::Platform::Var*))) {
        params_vector.push_back((arg));
    }
    va_end(args);

    auto params_name_string = params_name;
    BASE_STRING::ReplaceAll(params_name_string, "&", "");
    BASE_STRING::ReplaceAll(params_name_string, " ", "");
    std::vector<std::string> params_name_vector = BASE_STRING::Split(params_name_string, ",");
    
    auto file_name_string = file_name;
    BASE_STRING::ReplaceAll(file_name_string, ".cc", "");
    
    perform_fun_(platform_obj_, file_name_string, method_name, is_set_delegate, params_name_vector, params_vector);
}

void* Platform::GetPlatformObj() {
    return platform_obj_;
}

END_NAMESPACE_ONETEN
