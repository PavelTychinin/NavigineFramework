//
//  NavigineSDK.h
//  NavigineSDK
//
//  Created by Pavel Tychinin on 22.09.14.
//  Copyright (c) 2015 Navigine. All rights reserved.
//
#import <CoreGraphics/CGGeometry.h>

#import "NCDeviceInfo.h"
#import "NCDevicePath.h"
#import "NCVenue.h"
#import "NCLocation.h"

typedef NS_ENUM(NSInteger, NCBluetoothState) {
  NCBluetoothStateUnknown = 0,                // State unknown, update imminent
  NCBluetoothStatePoweredOff,                 // Bluetooth is currently powered off.
  NCBluetoothStateUnsupported,                // The platform doesn't support the Bluetooth Low Energy Central/Client role
  NCBluetoothStateUnauthorized,               // The application is not authorized to use the Bluetooth Low Energy Central/Client role.
  NCBluetoothStateLocationDenied,             // User has explicitly denied authorization for this application, or
                                              // location services are disabled in Settings.
  NCBluetoothStateLocationNotDetermined,      // User has not yet made a choice with regards to this application
  NCBluetoothStateLocationRestricted,         // This application is not authorized to use location services.
  NCBluetoothStateLocationAuthorizedAlways,   // User has granted authorization to use their location at any time
  NCBluetoothStateLocationAuthorizedWhenInUse // User has granted authorization to use their location only when your app
                                              // is visible to them
};

/**
 *  Protocol is used for getting pushes in timeout
 */
@protocol NavigineCoreDelegate;
@protocol NCBluetoothStateDelegate;

@interface NavigineCore : NSObject

@property (nonatomic, strong) NSString *userHash;
@property (nonatomic, strong) NSString *server;
@property (nonatomic, strong) NCLocation *location;

@property (nonatomic, strong, readonly) NCDeviceInfo *deviceInfo;
@property (nonatomic, assign, readonly) NCBluetoothState bluetoothState;

@property (nonatomic, weak) NSObject <NavigineCoreDelegate> *delegate;
@property (nonatomic, weak) NSObject <NCBluetoothStateDelegate> *btStateDelegate;

- (id) initWithUserHash:(NSString *)userHash;

- (id) initWithUserHash:(NSString *)userHash
                 server:(NSString *)server;

/**
 *  Function is used for downloading location and start navigation
 *
 *  @param userHash     userID ID from web site.
 *  @param location     location location name from web site.
 *  @param forced       the boolean flag.
 If set, the content data would be loaded even if the same version has been downloaded already earlier.
 If flag is not set, the download process compares the current downloaded version with the last version on the server.
 If server version equals to the current downloaded version, the re-downloading is not done.
 *  @param processBlock show downloading process
 *  @param successBlock run when download complete successfull
 *  @param failBlock    show error message and stop downloading
 */

- (void) downloadLocationById :(NSInteger)locationId
                  forceReload :(BOOL) forced
                 processBlock :(void(^)(NSInteger loadProcess))processBlock
                 successBlock :(void(^)(NSDictionary *userInfo))successBlock
                    failBlock :(void(^)(NSError *error))failBlock;

- (void) downloadLocationByName :(NSString *)location
                    forceReload :(BOOL) forced
                   processBlock :(void(^)(NSInteger loadProcess))processBlock
                   successBlock :(void(^)(NSDictionary *userInfo))successBlock
                      failBlock :(void(^)(NSError *error))failBlock;

/**
 *  Function is used for starting Navigine service.
 */
- (void) startNavigine;

/**
 *  Function is used for forced termination of Navigine service.
 */
- (void) stopNavigine;

/**
 *  Function is used for creating a content download process from the server.
 Download is done in a separate thread in the non-blocking mode.
 Function startLocationLoader doesn't wait until download is finished and returns immediately.
 *
 *  @param userHash   userID ID from web site.
 *
 *  @param location location location name from web site.
 *
 *  @param forced   the boolean flag.
 If set, the content data would be loaded even if the same version has been downloaded already earlier.
 If flag is not set, the download process compares the current downloaded version with the last version on the server.
 If server version equals to the current downloaded version, the re-downloading is not done.
 *
 *  @return the download process identifier. This number is used further for checking the download process state and for download process terminating.
 */
- (int)startLocationLoaderByUserHash: (NSString *)userHash
                        locationId: (NSInteger)locationId
                            forced: (BOOL) forced;

- (int)startLocationLoaderByUserHash: (NSString *)userHash
                      locationName: (NSString *)location
                            forced: (BOOL) forced;

/**
 *  Function is used for checking the download process state and progress.
 *
 *  @param loaderId download process identifier.
 *
 *  @return Integer number — the download process state:
 •	values in interval [0, 99] mean that download is in progress.
 In that case the value shows the download progress percentage;
 •	value 100 means that download has been successfully finished;
 •	other values mean that download process is impossible for some reason.
 */
- (int) checkLocationLoader :(int)loaderId;

/**
 *  Function is used for forced termination of download process which has been started earlier.
 Function should be called when download process is finished (successfully or not) or by a timeout.
 *
 *  @param loaderId download process identifier.
 */
- (void) stopLocationLoader :(int)loaderId;

/**
 *  Function is used for checking the download process state and progress.
 *
 *  @param location - location location name from web site.
 *  @param error - error if archive invalid.
 */

- (void) loadArchiveById :(NSInteger)locationId
                   error :(NSError * __autoreleasing *)error;

- (void) loadArchiveByName :(NSString *)location
                     error :(NSError * __autoreleasing *)error;

/**
 *  Function is used for making route from one position to other.
 *
 *  @param startPoint start vertex.
 *  @param endPoint  end vertex.
 *
 *  @return NSArray object – array with NCVertex structures.
 */
- (NCDevicePath *) makeRouteFrom: (NCVertex *)startPoint
                              to: (NCVertex *)endPoint;

- (void) setTarget:(NCVertex *)target;
- (void) cancelTarget;

- (void) setGraphTag:(NSString *)tag;
- (NSString *)getGraphTag;
- (NSString *)getGraphDescription:(NSString *)tag;
- (NSArray *)getGraphTags;
- (void) addTatget:(NCVertex *)target;
- (void) cancelTargets;

/**
 *  Function is used for cheking pushes from web site
 */
- (void) startPushManager;

/**
 *  Function is used for cheking venues from web site
 */
- (void) startVenueManager;

/**
 *  Function is used for converting local coordinates to GPS coordinates
 *
 *  @param x         x
 *  @param y         y
 *  @param azimuth   azimuth
 *  @param latitude  latitude
 *  @param longitude longitude
 *  @param data      GPS coordinates
 */
- (void) localToGps: (float) x :(float) y :(float) azimuth :(double) latitude :(double) longitude :(double*) data;

/**
 *  Function is used for sending data to server using POST sequests
 */
- (void) startSendingPostRequests;
/**
 * Function is used to stop sending data to server
 */
- (void) stopSendingPostRequests;

- (void) registerToken:(NSData *)token;

@end

@protocol NavigineCoreDelegate <NSObject>
@optional

/**
 *  Tells the delegate that push in range. Function is called by the timeout of the web site.
 *
 *  @param title   title of push.
 *  @param content content of push.
 *  @param image   url path to image of push.
 *  @param id      push id.
 */
- (void) didRangePushWithTitle :(NSString *)title
                       content :(NSString *)content
                         image :(NSString *)image
                            id :(NSInteger) id;
/**
 *  Function is used for checking venues from web site.
 *
 *  @param venues     NSArray object – array with NCVenue structures.
 *  @param categories NSArray object – array with NCCategories structures.
 */
- (void) didRangeVenues :(NSArray *)venues :(NSArray *)categories;

/**
 * Tells the delegate if point enter the zone
 *
 * @param id zone id
 */
- (void) didEnterZoneWithId:(NSInteger) id;

/**
 * Tells the delegate if point came out of the zone
 *
 * @param id zone id
 */
- (void) didExitZoneWithId:(NSInteger) id;


- (void) didRangeBeacons:(NSArray *)beacons;
- (void) getLatitude: (double)latitude Longitude:(double)longitude;

- (void) beaconFounded: (NCBeacon *)beacon error:(NSError **)error;
- (void) measuringBeaconWithProcess: (NSInteger) process;

@end

@protocol NCBluetoothStateDelegate <NSObject>
@optional
- (void) didChangeBluetoothState: (NCBluetoothState) state;
@end
