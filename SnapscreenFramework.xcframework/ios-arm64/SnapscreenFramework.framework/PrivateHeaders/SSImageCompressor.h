//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

#ifdef __cplusplus

#include <snapscreen_wrappers/image_view.h>

#endif

@interface SSImageCompressor : NSObject

#ifdef __cplusplus

+ (NSData *) compressedWebpImageDataFromImage:(const snapscreenwrap::ImageView &)image
                                      quality:(float)quality
                                     lossless:(BOOL)lossless;

+ (NSData *) compressedJpegImageDataFromImage:(const snapscreenwrap::ImageView &)image
                                      quality:(float)quality;

#endif

+ (UIImage *) imageFromCompressedData:(NSData *)data;

@end
