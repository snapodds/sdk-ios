//
//  SnapscreenUtil.h
//  SnapscreenFramework
//
//  Created by Martin Fitzka-Reichart on 15.11.21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SnapscreenUtil : NSObject
    
+ (UIImage* _Nullable) uiImageFromSampleBuffer: (CMSampleBufferRef) sampleBuffer orientation: (AVCaptureVideoOrientation) orientation;

@end

NS_ASSUME_NONNULL_END
