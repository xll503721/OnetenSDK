//
//  platform.h
//  OneTenSDK
//
//  Created by li zhixuan on 2023/4/9.
//

#include "oneten_object.h"

#ifndef TENONE_SDK_PLATFORM_H
#define TENONE_SDK_PLATFORM_H

BEGIN_NAMESPACE_ONETEN

#define PLATFORM_DECLARE \
std::shared_ptr<ONETEN::Platform> platform_;\

#define PLATFORM_INIT(class_name) \
platform_ = std::make_shared<ONETEN::Platform>(class_name);\

#define PLATFORM_PERFORM(...) \
std::string parmas_str = #__VA_ARGS__;\
platform_->Perform(__func__, parmas_str, ##__VA_ARGS__, NULL);\

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
            kTypeDouble,
            kTypeString,
            kTypeMap,
            kTypeVector
        };
        Var() = default;
        Var(int32_t value) {
            value_.int32_ = value;
            type_ = Type::kTypeInt;
        }
        
        Var(double value) {
            value_.double_ = value;
            type_ = Type::kTypeDouble;
        }
        
        Var(std::unordered_map<std::string, Var>* value) {
            value_.map_ = value;
            type_ = Type::kTypeMap;
        }
        
        Var(std::vector<Var>* value) {
            value_.vector_ = value;
            type_ = Type::kTypeVector;
        }
        
        Type GetType() {
            return type_;
        }
        
        int32_t GetDataInt32() {
            return value_.int32_;
        }
        
        std::unordered_map<std::string, Var>* GetDataMap() {
            return value_.map_;
        }
        
    private:
        union ValueHolder {
            int64_t int64_;
            int32_t int32_;
            bool boolean_;
            double double_;
            float float_;
            void* ptr_;
            std::unordered_map<std::string, Var>* map_;
            std::vector<Var>* vector_;
        } value_;
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
    void Perform(const std::string& method_name, const std::string& params_name, ONETEN::Platform::Var* params, ...) __attribute__((sentinel(0,1)));
    
public:
    
    static PlatformInit init_fun_;
    static PlatformPerform perform_fun_;
    
private:
    
    void* platform_obj_;
};

END_NAMESPACE_ONETEN

#endif /* TENONE_SDK_PLATFORM_H */
