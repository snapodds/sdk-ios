//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SnapscreenQuadrangle, SnapscreenFingerprintResult;

@interface SnapscreenFingerprintCalculator : NSObject

- (SnapscreenFingerprintResult* _Nullable) calculateFingerprintForSampleBuffer: (CMSampleBufferRef) sampleBuffer orientation: (AVCaptureVideoOrientation) orientation quadrangle: (SnapscreenQuadrangle* _Nullable) quadrangle timestamp: (long long) timestamp quality: (float) quality;
- (SnapscreenFingerprintResult* _Nullable) calculateFingerprintForImageData: (NSData*) imageData orientation: (AVCaptureVideoOrientation) orientation quadrangle: (SnapscreenQuadrangle* _Nullable) quadrangle timestamp: (long long) timestamp quality: (float) quality;

- (void) check;

@end

NS_ASSUME_NONNULL_END
