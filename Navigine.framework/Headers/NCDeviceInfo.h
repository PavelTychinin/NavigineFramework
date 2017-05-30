//
//  NCDeviceInfo.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 29/03/2017.
//  Copyright © 2017 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NCDeviceInfo : NSObject <NSCoding>
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSDate *time;
@property (nonatomic, assign) NSInteger location;
@property (nonatomic, assign) NSInteger subLocation;
@property (nonatomic, assign) float x;
@property (nonatomic, assign) float kx;
@property (nonatomic, assign) float y;
@property (nonatomic, assign) float ky;
@property (nonatomic, assign) float z;
@property (nonatomic, assign) float r;
@property (nonatomic, assign) float azimuth;
@property (nonatomic, assign) float pith;
@property (nonatomic, assign) float roll;
@property (nonatomic, strong) NSArray *paths;
@property (nonatomic, strong) NSArray *zones;
@property (nonatomic, strong) NSError *error;
@end
