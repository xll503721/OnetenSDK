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
    virtual void ShowCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) = 0;
    virtual void CloseCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) = 0;
    virtual void ClickCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) = 0;
};

class AdSource: public AdSourceDelegate, public EntityInterface {
public:
    enum class RequestType {
        kS2S,
        kC2S,
        kNormal,
    };
    
    enum class Style {
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
    
    AdSource(std::shared_ptr<BASE_JSON::Json> json);
    virtual ~AdSource();
    RequestType GetRequestType();
    
    void Load(std::shared_ptr<AdSourceDelegate> delegate);
    void SetLevel(int32_t level);
    int32_t GetLevel();
    
    std::string GetClassName();
    void Parse();
    
    void InitSDK();
    
    std::shared_ptr<BASE_JSON::Json> GetJson();

    std::string Identifier() override;
    void LoadCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    void ShowCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    void CloseCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    void ClickCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    
private:
    RequestType type_;
    Style style_;
    
    int32_t level_;
    std::string clazz_name_;
    std::shared_ptr<BASE_JSON::Json> json_;
    
    PLATFORM_GENERATE()
    
public:
    std::shared_ptr<AdSourceDelegate> delegate_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_H */
