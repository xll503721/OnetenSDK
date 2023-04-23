//
//  platform.cc
//  OneTenSDK
//
//  Created by li zhixuan on 2023/4/9.
//

#include "platform.h"
#include <string/string.h>

BEGIN_NAMESPACE_ONETEN

std::string trim(std::string str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), str.end());

    return str;
}

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

void replace_all(std::string& str, const std::string& from, const std::string& to) {
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
}

Platform::PlatformInit Platform::init_fun_ = nullptr;
Platform::PlatformPerform Platform::perform_fun_ = nullptr;

Platform::Platform(const std::string& class_name):platform_obj_(nullptr) {
    Init(class_name);
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

void Platform::Init(const std::string& class_name) {
    if (!init_fun_) {
        return nullptr;
    }
    
    platform_obj_ = init_fun_(class_name);
    if (!platform_obj_) {
        
    }
}

void Platform::Perform(const std::string& method_name, const std::string& params_name, ONETEN::Platform::Var* params, ...) {
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
    
    perform_fun_(platform_obj_, method_name, params_name_vector, params_vector);
}


END_NAMESPACE_ONETEN
