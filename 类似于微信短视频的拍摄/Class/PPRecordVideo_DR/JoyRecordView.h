//
//  JoyRecordView.h
//  LW
//
//  Created by wangguopeng on 2017/5/3.
//  Copyright © 2017年 joymake. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface JoyRecordView : UIView

//@property (nonatomic, copy) void(^startRecordBlock)(void);
//@property (nonatomic, copy) void(^endRecordBlock)(void);
//@property (nonatomic, copy) void(^switchCameraBlock)(void);
//@property (nonatomic, copy) void(^flashLightControlBlock)(void);
//@property (nonatomic, copy) void(^cancleRecordBlock)(void);

@property (nonatomic, copy) void(^scanMMetaBlock)(NSString *str);

#pragma mark --- 回调传出image或vedioUrl
- (void)registCompletedAction:(void(^)(BOOL isImage, NSURL *videoUrl))completedAction;

#pragma mark 屏幕旋转
-(void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;

#pragma mark 销毁页面
- (void)leaveout:(UIButton *)btn;

#pragma mark --- 清除所有的缓存文件
+ (void)clearAllCacheData;

@end

@class AVPlayer;
@interface JoyPlayerView : UIView
@property (nonatomic, strong) CALayer     *playerLayer;
@property (nonatomic, strong) AVPlayer    *player;
@property (nonatomic, strong) NSURL       *playUrl;
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIButton    *cancelButton;
@property (nonatomic, strong) UIButton    *doneButton;
@property (nonatomic, copy) void(^saveResourceComplete)(BOOL iSimage, NSURL *sourceUrl);
//@property (nonatomic, copy) void(^didSaveResourceBlock)(UIImage *image, NSString *videoUrl);

@property (nonatomic, copy) void(^playCancleBlock)(void);
@end


