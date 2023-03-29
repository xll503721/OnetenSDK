//
//  TENSigmobSource.m
//  ONETEN_AD_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#import "TENSigmobSource.h"

#define AppId @"6877"//应用ID
#define AppKey @"eccdcdbd9adbd4a7"//应用key
#define FullScreenVideoAdPlacementId @"f21b862c1cd"//插屏广告位ID

@interface TENSigmobSource ()<WindIntersititialAdDelegate, OTAdSourceProtocol>

@property (nonatomic, strong) WindIntersititialAd *intersititialAd;
@property (nonatomic, strong) WindSplashAdView *splashAdView;
@property (nonatomic, strong) WindNativeAdsManager *nativeAdsManager;
@property (nonatomic, strong) WindRewardVideoAd *rewardVideoAd;

@property (nonatomic, strong) NSMutableDictionary *sigmobAdDictionary;

@property (nonatomic, weak) id<OTAdSourceDelegate> delegate;

@end

@implementation TENSigmobSource

- (instancetype)initWithDelegate:(id<OTAdSourceDelegate>)delegate userInfo:(NSDictionary<id, id> *)userInfo
{
    self = [super init];
    if (self) {
        _delegate = delegate;
        _sigmobAdDictionary = @{}.mutableCopy;
        WindAdOptions *option = [[WindAdOptions alloc] initWithAppId:AppId appKey:AppKey];
        [WindAds startWithOptions:option];
    }
    return self;
}

- (BOOL)isReadyWithType:(OTAdSourceCategroyType)categroyType {
    switch (categroyType) {
        case OTAdSourceCategroyTypeInterstitial: {
            return [self.intersititialAd isAdReady];
        }
            break;
        case OTAdSourceCategroyTypeSplash: {
            return [self.splashAdView isAdValid];
        }
            break;
        case OTAdSourceCategroyTypeRewardedVideo: {
            return [self.rewardVideoAd isAdReady];
        }
            break;
        case OTAdSourceCategroyTypeNative: {
            
        }
            break;
            
        default:
            break;
    }
    return NO;
}

- (void)showInView:(UIView *)superView categroyType:(OTAdSourceCategroyType)categroyType {
    switch (categroyType) {
        case OTAdSourceCategroyTypeInterstitial: {
            [self.intersititialAd showAdFromRootViewController:(UIViewController *)superView.nextResponder options:nil];
        }
            break;
        case OTAdSourceCategroyTypeSplash: {
            [superView addSubview:self.splashAdView];
        }
            break;
        case OTAdSourceCategroyTypeRewardedVideo: {
            
        }
            break;
        case OTAdSourceCategroyTypeNative: {
            
        }
            break;
            
        default:
            break;
    }
}

#pragma mark - Interstitial
- (void)loadInterstitialWithType:(OTAdSourceType)type userInfo:(NSDictionary *)userInfo {
    WindAdRequest *request = [WindAdRequest request];
    request.userId = @"user_id";
    request.placementId = FullScreenVideoAdPlacementId;
    
    self.intersititialAd = [[WindIntersititialAd alloc] initWithRequest:request];
    self.intersititialAd.delegate = self;
    if (type == OTAdSourceTypeS2S) {
        [self.intersititialAd loadAdDataWithBidToken:[WindAds getSdkToken]];
        return;
    }
    if (type == OTAdSourceTypeC2S) {
        [self.intersititialAd setCurrency:@"USD"];
        [self.intersititialAd setBidFloor:100];
    }
    [self.intersititialAd loadAdData];
    self.sigmobAdDictionary[@(OTAdSourceCategroyTypeInterstitial)] = self.intersititialAd;
}

#pragma mark - Interstitial Delegate
- (void)intersititialAdDidLoad:(WindIntersititialAd *)intersititialAd {
    NSLog(@"回调成功");
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidLoadWithCategroyType:error:)]) {
        [self.delegate adDidLoadWithCategroyType:OTAdSourceCategroyTypeInterstitial error:nil];
    }
}

- (void)intersititialAdDidLoad:(WindIntersititialAd *)intersititialAd didFailWithError:(NSError *)error {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidLoadWithCategroyType:error:)]) {
        [self.delegate adDidLoadWithCategroyType:OTAdSourceCategroyTypeInterstitial error:error];
    }
}

#pragma mark - Splash
- (void)loadSplashWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    
}

#pragma mark - Banner
- (void)loadBannerWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    
}

#pragma mark - RewardedVideo
- (void)loadRewardedVideoWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    
}

#pragma mark - Navite
- (void)loadNaviteWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    
}

#pragma mark - Send Win Loss
- (void)sendWinNotificationWithType:(OTAdSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo {
    id<WindBiddingProtocol> ad = self.sigmobAdDictionary[@(categroyType)];
    [ad sendWinNotificationWithInfo:@{}];
}

- (void)sendLossNotificationWithType:(OTAdSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo {
    id<WindBiddingProtocol> ad = self.sigmobAdDictionary[@(categroyType)];
    [ad sendLossNotificationWithInfo:@{}];
}

@end
