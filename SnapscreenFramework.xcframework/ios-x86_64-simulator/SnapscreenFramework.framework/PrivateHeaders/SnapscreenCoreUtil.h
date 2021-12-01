//
//  SnapscreenCoreUtil.h
//  SnapscreenCore
//
//  Created by Martin Fitzka-Reichart on 14.11.21.
//

#import <Foundation/Foundation.h>
#include <snapscreen_wrappers/preprocessing_wrap.h>
#include <snapscreen_wrappers/features_wrap.h>

NS_ASSUME_NONNULL_BEGIN

@interface SnapscreenCoreUtil : NSObject {
    @public std::unique_ptr<snapscreenwrap::ImagePreprocessorWrap> imagePreprocessor_;
    @public std::unique_ptr<snapscreenwrap::ScreenQuadrangleFinderWrap> quadrangleFinder_;
    @public std::unique_ptr<snapscreenwrap::FeaturesExtractorWrap> featuresExtractor_;
}

+ (instancetype) sharedUtil;

@property dispatch_queue_t processingQueue;

@end

NS_ASSUME_NONNULL_END
