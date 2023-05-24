//
//  placement.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef ONETEN_AD_SDK_AD_SOURCE_H
#define ONETEN_AD_SDK_AD_SOURCE_H

#include <oneten_object.h>
#include <error.h>
#include "entity_interface.h"
#include <json/json.h>

BEGIN_NAMESPACE_ONETEN_AD

class AdSourceDelegate {
    
public:
    virtual void LoadCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) = 0;
};

class AdSource: public AdSourceDelegate, public EntityInterface {
public:
    enum class Type {
        kS2S,
        kC2S,
        kNormal,
    };
    
    enum class Category {
        kSplash,
        kInterstitial,
        kBanner,
        kRewardedVideo,
        kNative,
    };
    
    using this_class = AdSource;
    
    std::shared_ptr<AdSource> shared_from_this() {
        return std::static_pointer_cast<AdSource>(ONETEN::Object::shared_from_this());
    }
    
    AdSource();
    virtual ~AdSource();
    Type GetType();
    
    void Load(std::shared_ptr<AdSourceDelegate> delegate);
    void SetLevel(int32_t level);
    int32_t GetLevel();
    
    std::string GetClassName();
    void Parse(const std::string& json_string);
    
    void InitSDK();
    
    void LoadCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    std::string Identifier() override;
    
    std::shared_ptr<BASE_PLATFORM::Platform> GetPlatform();
    
private:
    Type type_;
    int32_t level_;
    std::string clazz_name_;
    BASE_JSON::Json json_;
    PLATFORM_DECLARE
    
public:
    std::shared_ptr<AdSourceDelegate> delegate_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_H */
