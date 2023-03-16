//
//  OTOneTenAdSDK.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/11.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "TENAdvertCategory.h"
//#import "TENAdvertSourceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

//@class TENAdvertView;

typedef void (^LoadCompletion) (NSString *placementId, NSError *error, NSDictionary<NSString *, id> *userInfo);

@interface OTOneTenAdSDK : NSObject

+ (OTOneTenAdSDK *)defalutAdSDK;

@property (nonatomic, readonly) NSString *appId;
@property (nonatomic, strong) LoadCompletion loadCompletion;

/// init app id
/// @param appId appId description
- (void)startWithAppId:(NSString *)appId;

- (void)loadWithPlacementId:(NSString *)placementId;

- (BOOL)showWithSuperView:(UIView *)view placementId:(NSString *)placementId error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
