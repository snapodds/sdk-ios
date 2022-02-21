//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SnapscreenUtil : NSObject
    
+ (UIImage* _Nullable) uiImageFromSampleBuffer: (CMSampleBufferRef) sampleBuffer orientation: (AVCaptureVideoOrientation) orientation;

+ (NSData* _Nullable) compressedWebpImageDataFromImageWrap: (NSObject* _Nullable) imageWrap quality: (CGFloat) quality;


@end

NS_ASSUME_NONNULL_END
