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

@interface TENSigmobSource ()<WindIntersititialAdDelegate, OTAdSourceProtocol>

//@property (nonatomic, strong) WindIntersititialAd *intersititialAd;
//@property (nonatomic, strong) WindSplashAdView *splashAdView;
//@property (nonatomic, strong) WindNativeAdsManager *nativeAdsManager;
//@property (nonatomic, strong) WindRewardVideoAd *rewardVideoAd;

@property (nonatomic, strong) id<OTAdSourceDelegate> delegate;

@end

@implementation TENSigmobSource

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

- (BOOL)isReadyWithType:(OTAdSourceCategroyType)categroyType {
    switch (categroyType) {
        case OTAdSourceCategroyTypeInterstitial: {
            if ([self.delegate.adSourceObject isKindOfClass:[WindIntersititialAd class]]) {
                return [(WindIntersititialAd *)self.delegate.adSourceObject isAdReady];
            }
        }
            break;
        case OTAdSourceCategroyTypeSplash: {
            
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
    return NO;
}

- (void)showWithCategroyType:(OTAdSourceCategroyType)categroyType rootViewController:(UIViewController *)viewController {
    switch (categroyType) {
        case OTAdSourceCategroyTypeInterstitial: {
            if ([self.delegate.adSourceObject isKindOfClass:[WindIntersititialAd class]]) {
                return [(WindIntersititialAd *)self.delegate.adSourceObject showAdFromRootViewController:viewController options:nil];
            }
        }
            break;
        case OTAdSourceCategroyTypeSplash: {
            
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

- (void)loadWithCategoryType:(OTAdSourceCategroyType)categroyType adSourceType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo {
    switch (categroyType) {
        case OTAdSourceCategroyTypeInterstitial:
            [self loadInterstitialWithType:type userInfo:userInfo];
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
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(adWillLoadWithCategroyType:adSourceObject:)]) {
        [self.delegate adWillLoadWithCategroyType:OTAdSourceCategroyTypeInterstitial adSourceObject:intersititialAd];
    }
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
}

- (void)sendLossNotificationWithType:(OTAdSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo {
}


@end
