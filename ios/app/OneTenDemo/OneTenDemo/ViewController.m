//
//  ViewController.m
//  OneTenDemo
//
//  Created by li zhixuan on 2023/2/19.
//

#import "ViewController.h"
#import <OneTenSDK/OTOneTen.h>


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [OTOneTenSDK initAppId:@"111" type:OTOneTenSDKTypeAd];
    
    
}


@end
