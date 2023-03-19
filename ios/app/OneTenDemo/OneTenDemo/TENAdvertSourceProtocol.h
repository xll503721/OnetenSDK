//
//  TENAdvertSource.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/11/10.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TENAdvertSourceRequestType) {
    TENAdvertSourceRequestTypeC2S,
    TENAdvertSourceRequestTypeS2S,
};

typedef NS_ENUM(NSUInteger, TENAdvertSourceCategroyType) {
    TENAdvertSourceCategroyTypeSplash,
    TENAdvertSourceCategroyTypeInterstitial,
    TENAdvertSourceCategroyTypeBanner,
    TENAdvertSourceCategroyTypeRewardedVideo,
    TENAdvertSourceCategroyTypeNative,
};

typedef NS_ENUM(NSUInteger, TENAdvertSourceCategroyLoadStatusType) {
    TENAdvertSourceCategroyLoadStatusTypeSucceed,
    TENAdvertSourceCategroyLoadStatusTypeFailed,
};

@protocol TENAdvertSourceDelegate <NSObject>

- (void)adDidLoadWithCategroyType:(TENAdvertSourceCategroyType)categroyType error:(NSError *)error;

@end

@protocol TENAdvertSourceProtocol <NSObject>

@required

/// init advert source, should init sdk
/// @param userInfo info
- (instancetype)initWithDelegate:(id<TENAdvertSourceDelegate>)delegate userInfo:(NSDictionary<id, id> *)userInfo;

- (BOOL)isReadyWithType:(TENAdvertSourceCategroyType)categroyType;
- (void)showInView:(UIView *)superView categroyType:(TENAdvertSourceCategroyType)categroyType;

@optional
/// start load interstitial ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadInterstitialWithType:(TENAdvertSourceRequestType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load splash ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadSplashWithType:(TENAdvertSourceRequestType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load banner ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadBannerWithType:(TENAdvertSourceRequestType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load rewarded video ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadRewardedVideoWithType:(TENAdvertSourceRequestType)type userInfo:(NSDictionary<id, id> *)userInfo;

/// start load navite ad
/// @param type c2s s2s
/// @param userInfo info
- (void)loadNaviteWithType:(TENAdvertSourceRequestType)type userInfo:(NSDictionary<id, id> *)userInfo;

- (void)sendWinNotificationWithType:(TENAdvertSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo;
- (void)sendLossNotificationWithType:(TENAdvertSourceCategroyType)categroyType userInfo:(NSDictionary *)userInfo;

@end
