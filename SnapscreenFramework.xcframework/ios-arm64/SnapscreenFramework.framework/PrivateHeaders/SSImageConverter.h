//
//  SSImageConverter.h
//  SnapscreenKit
//
//  Created by Tim Chernov on 04/06/15.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
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
