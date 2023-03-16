#import "OTOneTenSDK.h"

//#include "tenone_sdk.h"
//#include "tenone_ad_sdk.h"

#import "OTOneTenAdSDK.h"

@implementation OTOneTenSDK

+ (void)initAppId:(NSString *)appId type:(OTOneTenSDKType)type {
    switch (type) {
        case OTOneTenSDKTypeAd: {
            [[OTOneTenAdSDK defalutAdSDK] startWithAppId:appId];
        }
            break;
            
        default:
            break;
    }
}

@end
