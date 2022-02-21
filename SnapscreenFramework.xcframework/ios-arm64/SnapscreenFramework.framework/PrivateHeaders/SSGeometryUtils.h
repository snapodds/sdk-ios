//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <snapscreen_wrappers/common.h>

@interface SSGeometryUtils : NSObject

+ (BOOL) isQuadrangleConvex:(CGPoint [4])quadrangle;

+ (CGRect) centeredRect:(CGRect)rect inPoint:(CGPoint)point;

+ (CGPoint) boundedPoint:(CGPoint)point inFrame:(CGRect)frame;

@end
