//
//  OTAdSource.m
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/4/8.
//

#import "OTAdSourceObjectDelegate.h"
#import "OTAdSourceProtocol.h"
#include <ad/entity/ad_source.h>

@interface OTAdSourceObjectDelegate ()

@end

@implementation OTAdSourceObjectDelegate

- (void)adWillLoadWithstyleType:(OTAdSourceStyleType)styleType adSourceObject:(id)adSourceObject {
    _adSourceObject = adSourceObject;
}

- (void)adDidLoadWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error {
    ONETEN_AD::AdSource* ad_source = static_cast<ONETEN_AD::AdSource *>(_rawPrt);
    if (ad_source) {
        std::map<std::string, std::string> user_info;
        if (error) {
            ONETEN::Error c_error(static_cast<int32_t>(error.code), error.localizedDescription.UTF8String, user_info);
            ad_source->LoadCompletion((int32_t)styleType, &c_error);
            return;
        }
        ad_source->LoadCompletion((int32_t)styleType);
    }
}

- (void)adWillShowWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error {
    
}

- (void)adDidShowWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error {
    ONETEN_AD::AdSource* ad_source = static_cast<ONETEN_AD::AdSource *>(_rawPrt);
    if (ad_source) {
        std::map<std::string, std::string> user_info;
        ONETEN::Error *c_error = nullptr;
        if (error) {
            ONETEN::Error cc_error(static_cast<int32_t>(error.code), error.localizedDescription.UTF8String, user_info);
            c_error = &cc_error;
        }
        ad_source->ShowCompletion((int32_t)styleType, c_error);
    }
}

- (void)adWillDismissWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error {
    ONETEN_AD::AdSource* ad_source = static_cast<ONETEN_AD::AdSource *>(_rawPrt);
    if (ad_source) {
        std::map<std::string, std::string> user_info;
        ONETEN::Error *c_error = nullptr;
        if (error) {
            ONETEN::Error cc_error(static_cast<int32_t>(error.code), error.localizedDescription.UTF8String, user_info);
            c_error = &cc_error;
        }
        ad_source->CloseCompletion((int32_t)styleType, c_error);
    }
}

- (void)adDidDismissWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error {
    ONETEN_AD::AdSource* ad_source = static_cast<ONETEN_AD::AdSource *>(_rawPrt);
    if (ad_source) {
        std::map<std::string, std::string> user_info;
        ONETEN::Error *c_error = nullptr;
        if (error) {
            ONETEN::Error cc_error(static_cast<int32_t>(error.code), error.localizedDescription.UTF8String, user_info);
            c_error = &cc_error;
        }
        ad_source->CloseCompletion((int32_t)styleType, c_error);
    }
}

- (void)adWillCloseWithstyleType:(OTAdSourceStyleType)styleType {
    
}

- (void)adDidCloseWithstyleType:(OTAdSourceStyleType)styleType {
    
}

- (void)adDidClickWithstyleType:(OTAdSourceStyleType)styleType {
    
}

@end
