//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#ifndef SnapscreenQuadrangleDetector_Private_h
#define SnapscreenQuadrangleDetector_Private_h
#import "SnapscreenQuadrangleDetector.h"

@class SnapscreenQuadrangle, SSImageWrap;

@interface SnapscreenQuadrangleDetector()

- (SnapscreenQuadrangle* _Nullable) detectQuadrangleInImageWrap: (SSImageWrap* _Nullable) image;

@end

#endif /* SnapscreenQuadrangleDetector_Private_h */
