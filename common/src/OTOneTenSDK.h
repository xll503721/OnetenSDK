//
//  OTOneTenSdk.h
//  OnTen
//
//  Created by li zhixuan on 2022/10/29.
//

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, OTOneTenSDKType) {
    OTOneTenSDKTypeAd,
    OTOneTenSDKTypeIm,
    OTOneTenSDKTypeAudio,
    OTOneTenSDKTypeVideo,
};

@interface OTOneTenSDK : NSObject

+ (void)initAppId:(NSString *)appId type:(OTOneTenSDKType)type;

@end

#endif
