//
//  JGAFImageCache.h
//  JGAFImageCache
//
//  Created by Jamin Guy on 3/28/13.
//  Copyright (c) 2013 Jamin Guy. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
  JGAFImageCacheCacheTypeMemory = 0,
  JGAFImageCacheCacheTypeDisk,
  JGAFImageCacheCacheTypeNetworkRequest
} JGAFImageCacheCacheType;

@interface JGAFImageCache : NSObject

#ifndef JGAFImageCache_LOGGING_ENABLED
#define JGAFImageCache_LOGGING_ENABLED 0
#endif

#define JGAFImageCache_DEFAULT_EXPIRATION_INTERVAL -604800 // Default is 7 days: -604800.

// When the app enters the background extra time will be requested within which to
// delete files from disk that are older than this number in seconds.
@property(nonatomic, assign) NSTimeInterval fileExpirationInterval;
// If the http response status code is not in the 400-499 range a retry can be
// initiated, default: 0.
@property(nonatomic, assign) NSInteger maxNumberOfRetries;
// Number of seconds to wait between retries, default 0.0.
@property(nonatomic, assign) NSTimeInterval retryDelay;

+ (JGAFImageCache *)sharedInstance;
- (void)imageForURL:(NSString *)url
         completion:(void (^)(UIImage *image, JGAFImageCacheCacheType cacheType))completion;
- (void)clearAllData;
- (void)saveImageToMemoryForKey:(UIImage *)image key:(NSString *)key;
+ (void)saveImageToDiskForKey:(UIImage *)image key:(NSString *)key;

@end
