//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIImage.h>

#include <minbase/minimg.h>

@interface SSImageConverter : NSObject

+ (UIImage *) uiImageFromSampleBuffer:(CMSampleBufferRef)sampleBuffer
                          orientation:(AVCaptureVideoOrientation)orientation;

+ (UIImage *) uiImageFromMinImg:(const MinImg *)minImg shouldCopy:(BOOL)shouldCopy;

+ (UIImageOrientation) imageOrientationFromVideoOrientation:(AVCaptureVideoOrientation)videoOrientation;

+ (int) copyMinImg:(MinImg &)outMinImg fromSampleBuffer:(CMSampleBufferRef)sampleBuffer
       orientation:(AVCaptureVideoOrientation)orientation;

+ (int) copyToPixelBuffer:(CVPixelBufferRef)pixelBuffer fromMinImg:(const MinImg *)minImg;

+ (int) rotatesNumberForOrientation:(AVCaptureVideoOrientation)orientation;

@end
