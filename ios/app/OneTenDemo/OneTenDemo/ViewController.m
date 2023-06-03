//
//  ViewController.m
//  OneTenDemo
//
//  Created by li zhixuan on 2023/2/19.
//

#import "ViewController.h"
#import <OneTenSDK/OTOneTen.h>
#import <OneTenSDK/OTOneTenAdSDK.h>
#import <WindSDK/WindSDK.h>

#define AppId @"6877"//应用ID
#define AppKey @"eccdcdbd9adbd4a7"//应用key
#define FullScreenVideoAdPlacementId @"f21b862c1cd"//插屏广告位ID

@interface ViewController ()<WindIntersititialAdDelegate>

@property (nonatomic, strong) OTAdViewController *adViewController;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[OTOnetenSDK defalutSDK] initAppId:@"111" type:OTOneTenSDKTypeAd];
    
    [[OTOnetenSDK defalutSDK].adSDK setStageCallBack:^(OTOnetenAdSDKStageType stageType, NSString * _Nonnull placementId, NSError * _Nullable error, NSDictionary<NSString *,id> * _Nullable userInfo) {
        if (stageType == OTOnetenAdSDKStageTypeLoaded) {
            [self showAdViewController];
        }
        
        if (stageType == OTOnetenAdSDKStageTypeDismiss) {
            [self.adViewController.view removeFromSuperview];
            [self.adViewController removeFromParentViewController];
            [self.adViewController dismissViewControllerAnimated:YES completion:nil];
        }
    }];
}

- (void)showAdViewController {
    NSError *error;
    self.adViewController = [[OTOnetenSDK defalutSDK].adSDK showWithPlacementId:@"" error:&error];
    if (error) {
        return;
    }
    
    self.adViewController.view.frame = self.view.frame;
    self.adViewController.frame = self.view.frame;
    [self.view addSubview:self.adViewController.view];
    [self addChildViewController:self.adViewController];
}


@end
