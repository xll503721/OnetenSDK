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
    
    class Var {
    public:
        enum class Type {
            kTypeInt,
            kTypeBool,
            kTypeLong,
            kTypeFloat,
            kTypeMap,
            kTypeVector
        };
        Var() = default;
        Var(int32_t value) {
            data_ = value;
            type_ = Type::kTypeInt;
        }
        
        Var& operator=(int32_t value) {
            data_ = value;
        }
        
        Type GetType() {
            return type_;
        }
        
        int32_t GetData() {
            return data_;
        }
        
    private:
        int32_t data_;
        Type type_;
    };
    
    Platform() = default;
    Platform(const std::string& class_name);
    
    using PlatformInit = std::function<void* (const std::string& class_name)>;
    using PlatformPerform = std::function<void (const void* platform_obj, const std::string& method_name, const std::vector<std::string>& params_name, const std::vector<ONETEN::Platform::Var*>& params)>;
    
    static bool isPlatform(PlatformType type);
    static PlatformType platform();
    
    static void SetInitMehtod(PlatformInit method);
    static void SetPerformMehtod(PlatformPerform method);
    
    void Init(const std::string& class_name);
    void Perform(const std::string& method_name, const std::string& params_name, ONETEN::Platform::Var* params, ...);
    
public:
    
    static PlatformInit init_fun_;
    static PlatformPerform perform_fun_;
    
private:
    
    void* platform_obj_;
};

END_NAMESPACE_ONETEN

#endif /* TENONE_SDK_PLATFORM_H */
