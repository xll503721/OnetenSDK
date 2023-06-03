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

@protocol OTPlatformProtocol <NSObject>

@property void* rawPrt;

@end

#pragma mark - OTAdSourceDelegate

@protocol OTAdSourceDelegate <NSObject>

- (void)adWillLoadWithCategroyType:(OTAdSourceCategroyType)categroyType adSourceObject:(id)adSourceObject;
- (void)adDidLoadWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error;

- (void)adWillShowWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error;
- (void)adDidShowWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error;

- (void)adWillDismissWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error;
- (void)adDidDismissWithCategroyType:(OTAdSourceCategroyType)categroyType error:(NSError *)error;

- (void)adWillCloseWithCategroyType:(OTAdSourceCategroyType)categroyType;
- (void)adDidCloseWithCategroyType:(OTAdSourceCategroyType)categroyType;

- (void)adDidClickWithCategroyType:(OTAdSourceCategroyType)categroyType;

@property (nonatomic, readonly) id adSourceObject;

@end

#pragma mark - OTAdSourceProtocol

@protocol OTAdSourceProtocol <NSObject>

@required

@property (nonatomic, strong) id<OTAdSourceDelegate> delegate;

- (BOOL)isReadyWithType:(OTAdSourceCategroyType)categroyType;
- (void)showWithCategroyType:(OTAdSourceCategroyType)categroyType rootViewController:(UIViewController *)viewController;

- (void)loadWithCategoryType:(OTAdSourceCategroyType)categroyType adSourceType:(OTAdSourceType)type userInfo:(NSDictionary<id, id> *)userInfo;

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
