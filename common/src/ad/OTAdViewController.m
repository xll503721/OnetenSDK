//
//  OTAdViewController.m
//  oneten_ad
//
//  Created by li zhixuan on 2023/4/5.
//

#import "OTAdViewController.h"

@interface OTAdViewController ()

@property (nonatomic, strong) id<OTAdSourceProtocol> adSource;
@property (nonatomic, assign) OTAdSourceCategroyType category;

@property (nonatomic, assign) BOOL isShowing;

@end

@implementation OTAdViewController

- (instancetype)initWithAdSource:(id<OTAdSourceProtocol>)adSource category:(OTAdSourceCategroyType)category
{
    self = [super init];
    if (self) {
        _adSource = adSource;
        _category = category;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)willMoveToParentViewController:(UIViewController *)parent {
    [super willMoveToParentViewController:parent];
    
    if (!self.isShowing) {
        self.isShowing = !self.isShowing;
        if ([self.adSource respondsToSelector:@selector(showWithCategroyType:rootViewController:)]) {
            [self.adSource showWithCategroyType:self.category rootViewController:self];
        }
    }
}

@end
