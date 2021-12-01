//
//  SSImageCompressor.h
//  SnapscreenKit
//
//  Created by Tim Chernov on 23/06/15.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
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
