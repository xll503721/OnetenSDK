//
//  OTAdSourceService.m
//  oneten_ad_service
//
//  Created by li zhixuan on 2023/3/26.
//

#import "ad_srouce_service.h"
#import <objc/runtime.h>

@interface OTAdSourceService ()<OTAdSourceDelegate>

- (void)loadWithClassName:(NSString *)name;

@property ONETEN_AD::AdSourceService* rawPrt;

@property (nonatomic, strong) id<OTAdSourceProtocol> adSource;

@end

@implementation OTAdSourceService

- (void)loadWithClassName:(NSString *)name {
    Class clazz = NSClassFromString(name);
    id<OTAdSourceProtocol> adSource = [clazz alloc];
    if ([adSource conformsToProtocol:@protocol(OTAdSourceProtocol)]) {

    }

    if (![adSource respondsToSelector:@selector(initWithDelegate:userInfo:)]) {
        //alert
        return;
    }

    self.adSource = [adSource initWithDelegate:self userInfo:nil];

    if (![adSource respondsToSelector:@selector(loadInterstitialWithType:userInfo:)]) {
        //alert
        return;
    }
    [adSource loadInterstitialWithType:OTAdSourceTypeNormal userInfo:nil];
}

#pragma mark - OTAdSourceDelegate

- (void)adDidLoadWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error {
    self.rawPrt->LoadCompletion((int)categroyType, @"".UTF8String);
}

@end

BEGIN_NAMESPACE_ONETEN_AD

AdSourceService::~AdSourceService() {
    CFBridgingRelease(ad_source_service_ios_);
    ad_source_service_ios_ = nullptr;
}

void* AdSourceService::GetAdSourceServicePlatform() {
    if (!ad_source_service_ios_) {
        OTAdSourceService *adSourceService = [[OTAdSourceService alloc] init];
        ad_source_service_ios_ = (__bridge_retained void *)(adSourceService);
        adSourceService.rawPrt = this;
    }
    return ad_source_service_ios_;
}

void AdSourceService::Load(std::shared_ptr<AdSource> ad_source, std::function<void()> load_complete) {
    load_complete_ = load_complete;
    
    void *ad_source_service_platform = GetAdSourceServicePlatform();
    OTAdSourceService *adSourceService = (__bridge OTAdSourceService *)ad_source_service_platform;
    NSString *className = [NSString stringWithUTF8String:ad_source->GetClassName().c_str()];
    [adSourceService loadWithClassName:className];
}

void AdSourceService::LoadCompletion(int categroy_type, const std::string& error_msg) {
    if (load_complete_) {
        load_complete_();
    }
}

END_NAMESPACE_ONETEN_AD
