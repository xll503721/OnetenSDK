//
//  TENSigmobSource.m
//  ONETEN_AD_sdk
//
//  Created by li zhixuan on 2022/11/6.
//

#import "TENSigmobSource.h"
#import "OTAdSourceProtocol.h"

#define AppId @"6877"//应用ID
#define AppKey @"eccdcdbd9adbd4a7"//应用key
#define FullScreenVideoAdPlacementId @"f21b862c1cd"//插屏广告位ID
#define SplashAdPlacementId @"ea1f8f9bd12"//开屏广告位ID

@interface TENSigmobSource ()<WindIntersititialAdDelegate, WindSplashAdViewDelegate, OTAdSourceProtocol>

//@property (nonatomic, strong) WindIntersititialAd *intersititialAd;
//@property (nonatomic, strong) WindSplashAdView *splashAdView;
//@property (nonatomic, strong) WindNativeAdsManager *nativeAdsManager;
//@property (nonatomic, strong) WindRewardVideoAd *rewardVideoAd;

@end

@implementation TENSigmobSource

- (void)dealloc {
    
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        static dispatch_once_t onceToken ;
        dispatch_once(&onceToken, ^{
            WindAdOptions *option = [[WindAdOptions alloc] initWithAppId:AppId appKey:AppKey];
            [WindAds startWithOptions:option];
            [WindAds setDebugEnable:NO];
        });
    }
    return self;
}

- (BOOL)isReadyWithStyle:(OTAdSourceStyleType)styleType {
    switch (styleType) {
        case OTAdSourceStyleTypeInterstitial: {
            if ([self.delegate.adSourceObject isKindOfClass:[WindIntersititialAd class]]) {
                return [(WindIntersititialAd *)self.delegate.adSourceObject isAdReady];
            }
        }
            break;
        case OTAdSourceStyleTypeSplash: {
            if ([self.delegate.adSourceObject isKindOfClass:[WindSplashAdView class]]) {
                return [(WindSplashAdView *)self.delegate.adSourceObject isAdValid];
            }
        }
            break;
        case OTAdSourceStyleTypeRewardedVideo: {
            
        }
            break;
        case OTAdSourceStyleTypeNative: {
            
        }
            break;
            
        default:
            break;
    }
    return NO;
}

- (void)showWithStyleType:(OTAdSourceStyleType)styleType rootViewController:(UIViewController *)viewController {
    switch (styleType) {
        case OTAdSourceStyleTypeInterstitial: {
            if ([self.delegate.adSourceObject isKindOfClass:[WindIntersititialAd class]]) {
                return [(WindIntersititialAd *)self.delegate.adSourceObject showAdFromRootViewController:viewController options:nil];
            }
        }
            break;
        case OTAdSourceStyleTypeSplash: {
            if ([self.delegate.adSourceObject isKindOfClass:[WindSplashAdView class]]) {
                [(WindSplashAdView *)self.delegate.adSourceObject setRootViewController:viewController];
            }
        }
            break;
        case OTAdSourceStyleTypeRewardedVideo: {
            
        }
            break;
        case OTAdSourceStyleTypeNative: {
            
        }
            break;
            
        default:
            break;
    }
}

- (void)loadWithStyleType:(OTAdSourceStyleType)styleType adSourceType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    switch (styleType) {
        case OTAdSourceStyleTypeInterstitial:
            [self loadInterstitialWithType:type userInfo:userInfo];
            break;
        case OTAdSourceStyleTypeSplash:
            [self loadSplashWithType:type userInfo:userInfo];
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

    WindIntersititialAd *intersititialAd = [[WindIntersititialAd alloc] initWithRequest:request];
    intersititialAd.delegate = self;
    if (type == OTAdSourceTypeS2S) {
        [intersititialAd loadAdDataWithBidToken:[WindAds getSdkToken]];
        return;
    }
    if (type == OTAdSourceTypeC2S) {
        [intersititialAd setCurrency:@"USD"];
        [intersititialAd setBidFloor:100];
    }
    [intersititialAd loadAdData];
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(adWillLoadWithstyleType:adSourceObject:)]) {
        [self.delegate adWillLoadWithstyleType:OTAdSourceStyleTypeInterstitial adSourceObject:intersititialAd];
    }
}

#pragma mark - Interstitial Delegate
- (void)intersititialAdDidLoad:(WindIntersititialAd *)intersititialAd {
    NSLog(@"回调成功");
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidLoadWithstyleType:error:)]) {
        [self.delegate adDidLoadWithstyleType:OTAdSourceStyleTypeInterstitial error:nil];
    }
}

- (void)intersititialAdDidLoad:(WindIntersititialAd *)intersititialAd didFailWithError:(NSError *)error {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidLoadWithstyleType:error:)]) {
        [self.delegate adDidLoadWithstyleType:OTAdSourceStyleTypeInterstitial error:error];
    }
}

- (void)intersititialAdWillVisible:(WindIntersititialAd *)intersititialAd {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidShowWithstyleType:error:)]) {
        [self.delegate adWillShowWithstyleType:OTAdSourceStyleTypeSplash error:nil];
    }
}

- (void)intersititialAdDidVisible:(WindIntersititialAd *)intersititialAd {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidShowWithstyleType:error:)]) {
        [self.delegate adDidShowWithstyleType:OTAdSourceStyleTypeSplash error:nil];
    }
}

- (void)intersititialAdDidClick:(WindIntersititialAd *)intersititialAd {
    
}

- (void)intersititialAdDidClickSkip:(WindIntersititialAd *)intersititialAd {
    
}

- (void)intersititialAdDidClose:(WindIntersititialAd *)intersititialAd {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidDismissWithstyleType:error:)]) {
        [self.delegate adDidDismissWithstyleType:OTAdSourceStyleTypeSplash error:nil];
    }
}

- (void)intersititialAdDidPlayFinish:(WindIntersititialAd *)intersititialAd didFailWithError:(NSError *)error {
    
}

- (void)intersititialAdServerResponse:(WindIntersititialAd *)intersititialAd isFillAd:(BOOL)isFillAd {
    
}

#pragma mark - Splash
- (void)loadSplashWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    WindAdRequest *request = [WindAdRequest request];
    request.placementId = SplashAdPlacementId;
    request.userId = @"your user id";
    WindSplashAdView *splashAdView = [[WindSplashAdView alloc] initWithRequest:request];
    splashAdView.delegate = self;
    [splashAdView loadAdData];
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(adWillLoadWithstyleType:adSourceObject:)]) {
        [self.delegate adWillLoadWithstyleType:OTAdSourceStyleTypeInterstitial adSourceObject:splashAdView];
    }
}

#pragma mark - WindMillSplashAdDelegate
- (void)onSplashAdDidLoad:(WindSplashAdView *)splashAdView {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidLoadWithstyleType:error:)]) {
        [self.delegate adDidLoadWithstyleType:OTAdSourceStyleTypeSplash error:nil];
    }
}

- (void)onSplashAdLoadFail:(WindSplashAdView *)splashAdView error:(NSError *)error {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidLoadWithstyleType:error:)]) {
        [self.delegate adDidLoadWithstyleType:OTAdSourceStyleTypeSplash error:error];
    }
}

- (void)onSplashAdSuccessPresentScreen:(WindSplashAdView *)splashAdView {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidShowWithstyleType:error:)]) {
        [self.delegate adDidShowWithstyleType:OTAdSourceStyleTypeSplash error:nil];
    }
}

- (void)onSplashAdFailToPresent:(WindSplashAdView *)splashAdView withError:(NSError *)error {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidShowWithstyleType:error:)]) {
        [self.delegate adDidShowWithstyleType:OTAdSourceStyleTypeSplash error:error];
    }
}

- (void)onSplashAdClicked:(WindSplashAdView *)splashAdView {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidClickWithstyleType:)]) {
        [self.delegate adDidClickWithstyleType:OTAdSourceStyleTypeSplash];
    }
}

- (void)onSplashAdSkiped:(WindSplashAdView *)splashAdView {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidCloseWithstyleType:)]) {
        [self.delegate adDidCloseWithstyleType:OTAdSourceStyleTypeSplash];
    }
}

- (void)onSplashAdClosed:(WindSplashAdView *)splashAdView {
    if (self.delegate && [self.delegate respondsToSelector:@selector(adDidDismissWithstyleType:error:)]) {
        [self.delegate adDidDismissWithstyleType:OTAdSourceStyleTypeSplash error:nil];
    }
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
- (void)sendWinNotificationWithType:(OTAdSourceStyleType)styleType userInfo:(NSDictionary *)userInfo {
}

- (void)sendLossNotificationWithType:(OTAdSourceStyleType)styleType userInfo:(NSDictionary *)userInfo {
}

@end
