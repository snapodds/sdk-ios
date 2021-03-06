//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <AVFoundation/AVFoundation.h>
#include <snapscreen_wrappers/image_view.h>

// ARC-supporting image wrapper useful for memory management in async environment

@interface SSImageWrap : NSObject

@property (nonatomic, assign) AVCaptureVideoOrientation orientation;

- (instancetype) initWithSampleBuffer: (CMSampleBufferRef) sampleBuffer orientation: (AVCaptureVideoOrientation) orientation;
- (instancetype) initWithImageData: (NSData*) data orientation: (AVCaptureVideoOrientation) orientation;

- (MinImg *) minImg;
- (snapscreenwrap::ImageView &) imageView;

- (void) deleteImage;

- (UIImage *) uiImageShouldCopy:(BOOL)shouldCopy;

@end
