#import "OTOneTenSDK.h"

//#include "tenone_sdk.h"
//#include "ONETEN_AD_sdk.h"

#import "OTOneTenAdSDK.h"

#import "OTAdSourceProtocol.h"

@implementation OTOneTenSDK

+ (void)initAppId:(NSString *)appId type:(OTOneTenSDKType)type {
    bool isiOS = isPlatform(OneTenPlatformType::kOneTenPlatformTypeiOS);
    

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
