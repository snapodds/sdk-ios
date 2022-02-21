//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SnapscreenQuadrangle;

@interface SnapscreenQuadrangleDetector : NSObject

- (SnapscreenQuadrangle* _Nullable) detectQuadrangleInSampleBuffer: (CMSampleBufferRef) sampleBuffer orientation: (AVCaptureVideoOrientation) orientation;
- (SnapscreenQuadrangle* _Nullable) detectQuadrangleForImageData: (NSData*) imageData orientation: (AVCaptureVideoOrientation) orientation;

@end

NS_ASSUME_NONNULL_END
