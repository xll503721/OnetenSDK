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

@property (nonatomic, strong) WindIntersititialAd *intersititialAd;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[OTOnetenSDK defalutSDK] initAppId:@"111" type:OTOneTenSDKTypeAd];
    
    [[OTOnetenSDK defalutSDK].adSDK setLoadCompletion:^(NSString * _Nonnull placementId, NSError * _Nonnull error, NSDictionary<NSString *,id> * _Nonnull userInfo) {
        
    }];
    
    [[OTOnetenSDK defalutSDK].adSDK loadWithPlacementId:@"" userInfo:@{}];
    
    NSError *error;
    [[OTOnetenSDK defalutSDK].adSDK showWithSuperView:self.view placementId:@"" error:&error];
    if (error) {
        
    }
}


@end
