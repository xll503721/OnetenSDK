//
//  TENAdSDK.h
//  tenone_ad_sdk
//
//  Created by li zhixuan on 2022/12/11.
//

#import <Foundation/Foundation.h>
//#import "TENAdvertCategory.h"
//#import "TENAdvertSourceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

//@class TENAdvertView;

//typedef void (^Completion) (TENAdvertView *view, TENAdvertSourceCategroyLoadStatusType type, NSDictionary<id, id> *userInfo);

@interface TENAdSDK : NSObject

@property (nonatomic, strong) NSObject *obj;

+ (TENAdSDK *)defalutAdSDK;

- (void)test;

//- (void)loadWithPlacementId:(NSString *)placementId category:(TENAdvertSourceCategroyType)type completionHandler:(Completion)completion;

@end

NS_ASSUME_NONNULL_END
