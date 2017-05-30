//
//  NCDevicePath.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 29/03/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCVertex.h"

@interface NCDevicePath : NSObject
@property (nonatomic, strong) NSArray *path;
@property (nonatomic, assign) float lenght;
@end
