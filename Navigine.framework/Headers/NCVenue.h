//
//  NCVenue.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 17/06/15.
//  Copyright (c) 2015 Navigine. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NCCategory.h"

/**
 *  Structure with venues content
 */
@interface NCVenue : NSObject <NSCoding>

@property(nonatomic, assign) NSInteger  id;
@property(nonatomic, assign) NSInteger  locationId;
@property(nonatomic, assign) NSInteger  sublocationId;  // sublocation id of venue
@property(nonatomic, strong) NSString   *name;      // name of venue
@property(nonatomic, strong) NSNumber   *kX;
@property(nonatomic, strong) NSNumber   *kY;
@property(nonatomic, strong) NSString   *image;     // url path to image of venue content
@property(nonatomic, strong) NSString   *phone;     // phone number of venue
@property(nonatomic, strong) NSString   *descript;  // other info about venue
@property(nonatomic, strong) NSString   *alias;  // other info about venue
@property(nonatomic, strong) NCCategory *category;

@end
