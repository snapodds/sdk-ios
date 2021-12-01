//
//  SnapscreenQuadrangleDetector+Private.h
//  SnapscreenCore
//
//  Created by Martin Fitzka-Reichart on 14.11.21.
//

#ifndef SnapscreenQuadrangleDetector_Private_h
#define SnapscreenQuadrangleDetector_Private_h
#import "SnapscreenQuadrangleDetector.h"

@class SnapscreenQuadrangle, SSImageWrap;

@interface SnapscreenQuadrangleDetector()

- (SnapscreenQuadrangle* _Nullable) detectQuadrangleInImageWrap: (SSImageWrap* _Nullable) image;

@end

#endif /* SnapscreenQuadrangleDetector_Private_h */
