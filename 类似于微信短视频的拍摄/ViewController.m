//
//  ViewController.m
//  类似于微信短视频的拍摄
//
//  Created by DR_Kun on 2018/6/14.
//  Copyright © 2018年 DR_Kun. All rights reserved.
//

#import "ViewController.h"
//view
#import "JoyRecordView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


#pragma mark --- Action

- (IBAction)buttonClicked:(UIButton *)sender {
    UIWindow *keyW = [UIApplication sharedApplication].keyWindow;
    CGRect viewFrame = keyW.bounds;
    JoyRecordView *recoreView = [[JoyRecordView alloc] initWithFrame:CGRectMake(0, viewFrame.size.height, viewFrame.size.width, viewFrame.size.height)];
    [recoreView registCompletedAction:^(BOOL isImage, NSURL *videoUrl) {
        NSMutableDictionary *param = [NSMutableDictionary dictionary];
        [param setValue:[videoUrl absoluteString] forKey:@"url"];
        if (isImage) {
            [param setValue:@"image" forKey:@"type"];
        }else {
            [param setValue:@"video" forKey:@"type"];
        }

    }];

    [keyW addSubview:recoreView];
    [UIView animateWithDuration:0.2 animations:^{
        recoreView.frame = CGRectMake(0, 0, viewFrame.size.width, viewFrame.size.height);
    }];

}
- (IBAction)clearCacheClicked:(UIButton *)sender {
    [JoyRecordView clearAllCacheData];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
