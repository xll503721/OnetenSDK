//
//  OTAdSource.h
//  oneten_ad_entity
//
//  Created by li zhixuan on 2023/4/8.
//

#import <Foundation/Foundation.h>
#import "OTAdSourceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface OTAdSourceObjectDelegate : NSObject <OTPlatformProtocol, OTAdSourceDelegate>

@property void* rawPrt;

@property (nonatomic, readonly) id adSourceObject;

@end

NS_ASSUME_NONNULL_END
