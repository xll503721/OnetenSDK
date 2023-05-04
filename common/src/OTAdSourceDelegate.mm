//
//  OTAdSource.m
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/4/8.
//

#import "OTAdSourceDelegate.h"
#import "OTAdSourceProtocol.h"
#include <ad/entity/ad_source.h>

@interface OTAdSourceDelegate ()

@property (nonatomic, strong) id adSourceObject;

@end

@implementation OTAdSourceDelegate

- (void)adWillLoadWithCategroyType:(OTAdSourceCategroyType)categroyType adSourceObject:(id)adSourceObject {
    self.adSourceObject = adSourceObject;
}

- (void)adDidLoadWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error {
    ONETEN_AD::AdSource* ad_source = static_cast<ONETEN_AD::AdSource *>(_rawPrt);
    if (ad_source) {
        std::map<std::string, std::string> user_info;
        ONETEN::Error *c_error = nullptr;
        if (error) {
            ONETEN::Error cc_error(static_cast<int32_t>(error.code), error.localizedDescription.UTF8String, user_info);
            c_error = &cc_error;
        }
        ad_source->LoadCompletion((int32_t)categroyType, c_error);
    }
}

@end
