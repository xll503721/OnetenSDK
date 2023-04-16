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

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import "OTAdSourceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface OTAdSourceService : NSObject

@end

NS_ASSUME_NONNULL_END

#endif

BEGIN_NAMESPACE_ONETEN_AD

class AdSourceService {
    
public:
    ~AdSourceService();
    using LoadCompletionInvoke = std::function<void(int categroy_type, ONETEN::Error* error)>;
    
    
    void Load(std::shared_ptr<AdSource> ad_source, LoadCompletionInvoke load_complete);
    
    void LoadCompletion(int categroy_type, ONETEN::Error* error);
    
private:
    void* GetAdSourceServicePlatform();
    
private:
    void* ad_source_service_ios_;
    LoadCompletionInvoke load_complete_;
};

END_NAMESPACE_ONETEN_AD

#endif /* ONETEN_AD_SDK_AD_SOURCE_SERVICE_H */
