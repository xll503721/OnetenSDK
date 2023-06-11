//
//  TENAdvertSource.h
//  ONETEN_AD_sdk
//
//  Created by li zhixuan on 2022/11/10.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, OTAdSourceType) {
    OTAdSourceTypeC2S,
    OTAdSourceTypeS2S,
    OTAdSourceTypeNormal,
};

typedef NS_ENUM(NSUInteger, OTAdSourceStyleType) {
    OTAdSourceStyleTypeSplash,
    OTAdSourceStyleTypeInterstitial,
    OTAdSourceStyleTypeBanner,
    OTAdSourceStyleTypeRewardedVideo,
    OTAdSourceStyleTypeNative,
};

typedef NS_ENUM(NSUInteger, OTAdSourceCategroyLoadStatusType) {
    OTAdSourceCategroyLoadStatusTypeSucceed,
    OTAdSourceCategroyLoadStatusTypeFailed,
};

@protocol OTPlatformProtocol <NSObject>

@property void* rawPrt;

@end

#pragma mark - OTAdSourceDelegate

@protocol OTAdSourceDelegate <NSObject>

- (void)adWillLoadWithstyleType:(OTAdSourceStyleType)styleType adSourceObject:(id)adSourceObject;
- (void)adDidLoadWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error;

- (void)adWillShowWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error;
- (void)adDidShowWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error;

- (void)adWillDismissWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error;
- (void)adDidDismissWithstyleType:(OTAdSourceStyleType)styleType error:(NSError *)error;

- (void)adWillCloseWithstyleType:(OTAdSourceStyleType)styleType;
- (void)adDidCloseWithstyleType:(OTAdSourceStyleType)styleType;

- (void)adDidClickWithstyleType:(OTAdSourceStyleType)styleType;

@property (nonatomic, readonly) id adSourceObject;

@end

#pragma mark - OTAdSourceProtocol

@protocol OTAdSourceProtocol <NSObject>

@required

@property (nonatomic, strong) id<OTAdSourceDelegate> delegate;

- (BOOL)isReadyWithStyle:(OTAdSourceStyleType)styleType;
- (void)showWithStyleType:(OTAdSourceStyleType)styleType rootViewController:(UIViewController *)viewController;

- (void)loadWithStyleType:(OTAdSourceStyleType)styleType adSourceType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

@optional

/// start load interstitial ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadInterstitialWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load splash ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadSplashWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load banner ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadBannerWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load rewarded video ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadRewardedVideoWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load navite ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadNaviteWithType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

- (void)sendWinNotificationWithType:(OTAdSourceStyleType)styleType userInfo:(NSDictionary *)userInfo;
- (void)sendLossNotificationWithType:(OTAdSourceStyleType)styleType userInfo:(NSDictionary *)userInfo;

@end
