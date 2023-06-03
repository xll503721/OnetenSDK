//
//  OTAdViewController.m
//  oneten_ad
//
//  Created by li zhixuan on 2023/4/5.
//

#import "OTAdViewController.h"
#import "OTOnetenSDK.h"

@interface OTAdView : UIView

@end

@implementation OTAdView

@end


@interface OTAdViewController ()

@property (nonatomic, strong) id<OTAdSourceProtocol> adSource;
@property (nonatomic, assign) OTAdSourceCategroyType category;

@property (nonatomic, assign) BOOL isShowing;

@end

@implementation OTAdViewController

- (void)dealloc {
    
}

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
    
    OTAdView *view = [[OTAdView alloc] initWithFrame:self.view.bounds];
    self.view = view;
}

- (void)willMoveToParentViewController:(UIViewController *)parent {
    [super willMoveToParentViewController:parent];
    
    if (!self.isShowing) {
        self.isShowing = !self.isShowing;
        
        if (self.category == OTAdSourceCategroyTypeSplash && [self.adSource.delegate.adSourceObject isKindOfClass:[UIView class]]) {
            UIView *splashView = (UIView *)self.adSource.delegate.adSourceObject;
            splashView.frame = self.frame;
            [self.view addSubview:splashView];
        }
        
        if ([self.adSource respondsToSelector:@selector(showWithCategroyType:rootViewController:)]) {
            [self.adSource showWithCategroyType:self.category rootViewController:self];
        }
    }
}

@end
