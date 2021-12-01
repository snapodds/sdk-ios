//
//  SSGeometryUtils.h
//  SnapscreenKit
//
//  Created by Tim Chernov on 17/07/15.
//  Copyright © 2016 Snapscreen Application GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import <snapscreen_wrappers/common.h>

@interface SSGeometryUtils : NSObject

+ (BOOL) isQuadrangleConvex:(CGPoint [4])quadrangle;

+ (CGRect) centeredRect:(CGRect)rect inPoint:(CGPoint)point;

+ (CGPoint) boundedPoint:(CGPoint)point inFrame:(CGRect)frame;

@end
