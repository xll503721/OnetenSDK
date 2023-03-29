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

typedef NS_ENUM(NSUInteger, OTAdSourceCategroyType) {
    OTAdSourceCategroyTypeSplash,
    OTAdSourceCategroyTypeInterstitial,
    OTAdSourceCategroyTypeBanner,
    OTAdSourceCategroyTypeRewardedVideo,
    OTAdSourceCategroyTypeNative,
};

typedef NS_ENUM(NSUInteger, OTAdSourceCategroyLoadStatusType) {
    OTAdSourceCategroyLoadStatusTypeSucceed,
    OTAdSourceCategroyLoadStatusTypeFailed,
};

@protocol OTAdSourceDelegate <NSObject>

- (void)adDidLoadWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error;

@end

@protocol OTAdSourceProtocol <NSObject>

@required

/// init advert source, should init sdk
/// @param userInfo info
- (instancetype)initWithDelegate:(id<OTAdSourceDelegate>)delegate userInfo:(NSDictionary<id, id> *)userInfo;

- (BOOL)isReadyWithType:(OTAdSourceCategroyType)categroyType;
- (void)showInView:(UIView *)superView categroyType:(OTAdSourceCategroyType)categroyType;

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

- (void)sendWinNotificationWithType:(OTAdSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo;
- (void)sendLossNotificationWithType:(OTAdSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo;

@end
