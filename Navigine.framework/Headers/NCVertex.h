//
//  NCVertex.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 17/06/15.
//  Copyright (c) 2015 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Struсture with vertex content
 */
@interface NCVertex : NSObject <NSCoding>
@property (nonatomic, assign) NSInteger sublocationId;
@property (nonatomic, strong) NSString  *name;
@property (nonatomic, strong) NSNumber  *x;
@property (nonatomic, strong) NSNumber  *y;
@property (nonatomic, strong) NSNumber  *kX;
@property (nonatomic, strong) NSNumber  *kY;
@property (nonatomic, assign) BOOL      external;
@end
