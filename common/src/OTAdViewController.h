//
//  OTAdViewController.h
//  oneten_ad
//
//  Created by li zhixuan on 2023/4/5.
//

#import <UIKit/UIKit.h>
#import "OTAdSourceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface OTAdViewController : UIViewController

- (instancetype)initWithAdSource:(id<OTAdSourceProtocol>)adSource category:(OTAdSourceCategroyType)category;

@property (nonatomic, assign) CGRect frame;

@end

NS_ASSUME_NONNULL_END
