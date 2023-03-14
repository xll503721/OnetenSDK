//
//  TENOneSdk.h
//  TenOne
//
//  Created by li zhixuan on 2022/10/29.
//

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TENOneSdkType) {
    TENOneSdkTypeAdvert,
    TENOneSdkTypeInstantMessaging,
    TENOneSdkTypeAudio,
    TENOneSdkTypeVideo,
};

@interface TENOneSdk : NSObject

+ (void)initAppId:(NSString *)appId type:(TENOneSdkType)type;

@end

#endif
