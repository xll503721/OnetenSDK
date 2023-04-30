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

class AdSourceService: public ONETEN::OnetenObject, public AdSourceDelegate {
    
public:
    ~AdSourceService();
    using LoadCompletionInvoke = std::function<void(int32_t categroy_type, ONETEN::Error* error)>;
    
    std::shared_ptr<AdSourceService> shared_from_this() {
        return std::static_pointer_cast<AdSourceService>(ONETEN::OnetenObject::shared_from_this());
    }
    
    void Load(std::shared_ptr<AdSource> ad_source, LoadCompletionInvoke load_complete);
    
    void LoadCompletion(int32_t categroy_type, ONETEN::Error* error = nullptr) override;
    
private:
    void* ad_source_service_ios_;
    LoadCompletionInvoke load_complete_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_SERVICE_H */
