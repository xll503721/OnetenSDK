//
//  OTOneTenAdSDK.h
//  SDKCommon
//
//  Created by li zhixuan on 2022/12/11.
//

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OTAdViewController.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^LoadCompletion) (NSString *placementId, NSError *error, NSDictionary<NSString *, id> *userInfo);

@interface OTOnetenAdSDK : NSObject

@property (nonatomic, readonly) NSString *appId;
@property (nonatomic, strong) LoadCompletion loadCompletion;

/// init app id
/// @param appId appId description
- (void)startWithAppId:(NSString *)appId;

- (void)loadWithPlacementId:(NSString *)placementId userInfo:(nullable NSDictionary<NSString *, NSString *> *)userInfo;
- (void)loadWithPlacementId:(NSString *)placementId;

- (OTAdViewController *)showWithSuperView:(UIView *)view placementId:(NSString *)placementId error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END

#endif

