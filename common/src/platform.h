//
//  platform.h
//  OneTenSDK
//
//  Created by li zhixuan on 2023/4/9.
//

#include "oneten_object.h"

#ifndef TENONE_SDK_PLATFORM_H
#define TENONE_SDK_PLATFORM_H

#define PLATFORM_DECLARE \
std::shared_ptr<ONETEN::Platform> platform_;\

#define PLATFORM_INIT(class_name) \
platform_ = std::make_shared<ONETEN::Platform>(class_name);\

#define PLATFORM_PERFORM(...) \
std::string parmas_str = #__VA_ARGS__;\
platform_->Perform(__func__, parmas_str, ##__VA_ARGS__);\

BEGIN_NAMESPACE_ONETEN

class Platform: OnetenObject {
    
public:
    enum class PlatformType {
        kPlatformTypeiOS,
        kPlatformTypeMac,
        kPlatformTypeAndroid,
    };
    
    Platform() = default;
    Platform(const std::string& class_name);
    
    using PlatformInit = std::function<void* (const std::string& class_name)>;
    using PlatformPerform = std::function<void (const void* platform_obj, const std::string& method_name, const std::vector<std::string>& parmas_name, const std::vector<void*>& parmas)>;
    
    static bool isPlatform(PlatformType type);
    static PlatformType platform();
    
    static void SetInitMehtod(PlatformInit method);
    static void SetPerformMehtod(PlatformPerform method);
    
    void Init(const std::string& class_name);
    void Perform(const std::string& method_name, const std::string& params_name, void* params, ...);
    
public:
    
    static PlatformInit init_fun_;
    static PlatformPerform perform_fun_;
    
private:
    
    void* platform_obj_;
};

END_NAMESPACE_ONETEN

#endif /* TENONE_SDK_PLATFORM_H */
