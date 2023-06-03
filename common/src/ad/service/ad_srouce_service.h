//
//  ad_srouce_service.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/11/6.
//

#ifndef ONETEN_AD_SDK_AD_SOURCE_SERVICE_H
#define ONETEN_AD_SDK_AD_SOURCE_SERVICE_H

#include "../entity/ad_source.h"
#include <error.h>

BEGIN_NAMESPACE_ONETEN_AD

class AdSourceService: public ONETEN::Object, public AdSourceDelegate {
    
public:
    ~AdSourceService();
    using LoadCompletionInvoke = std::function<void(int32_t categroy_type, ONETEN::Error* error)>;
    using ShowCompletionInvoke = std::function<void(int32_t categroy_type, ONETEN::Error* error)>;
    using DismissCompletionInvoke = std::function<void(int32_t categroy_type, ONETEN::Error* error)>;
    using ClickCompletionInvoke = std::function<void(int32_t categroy_type, ONETEN::Error* error)>;
    
    std::shared_ptr<AdSourceService> shared_from_this() {
        return std::static_pointer_cast<AdSourceService>(ONETEN::Object::shared_from_this());
    }
    
    void Load(std::shared_ptr<AdSource> ad_source, LoadCompletionInvoke load_complete);
    void Show(ShowCompletionInvoke show_complete);
    void Dismiss(DismissCompletionInvoke dismiss_complete);
    void Click(ClickCompletionInvoke click_complete);
    
private:
    void LoadCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    void ShowCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    void CloseCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    void ClickCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    
private:
    void* ad_source_service_ios_;
    LoadCompletionInvoke load_complete_;
    ShowCompletionInvoke show_complete_;
    DismissCompletionInvoke dismiss_complete_;
    ClickCompletionInvoke click_complete_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_SERVICE_H */
