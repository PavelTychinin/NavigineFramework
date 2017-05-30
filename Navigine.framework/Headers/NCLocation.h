//
//  NCLocation.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 11/03/15.
//  Copyright (c) 2015 Navigine. All rights reserved.
//

#import "NCSublocation.h"

@interface NCLocation :NSObject<NSCoding>

/**
 *  Location id in personal account
 */
@property (nonatomic,assign) NSInteger      id;

/**
 *  Location name in personal account
 */
@property (nonatomic,copy)   NSString       *name;

/**
 *  Name of archive file
 */
@property (nonatomic,copy)   NSString       *archiveFile;

/**
 *  Archive version
 */
@property (nonatomic,assign) NSInteger      version;

/**
 *  Array with sublocations of your location
 */
@property (nonatomic,strong) NSMutableArray *sublocations;

/**
 *  NCLocationViewController
 */
@property (nonatomic,copy) UIViewController *viewController;

/**
*  Is local modified Archive
*/
@property (nonatomic,assign) BOOL modified;


- (id) initWithLocation :(NCLocation *)location;

/**
 *  Function is used for getting sublocation at id or nil error
 *
 *  @param id 
 *
 *  @return Sublocation object or nil
 */
- (NCSublocation *)subLocationAtId: (NSInteger) id;

/**
 *  Function is used for getting sublocation at index or nil error
 *
 *  @param index the ordinal sublocation in admin panel
 *
 *  @return Sublocation object or nil
 */
- (NCSublocation *)subLocationAtIndex: (NSInteger) index;


@end
