//
//  YKUserManager.h
//  YKOCFramework
//
//  Created by edward on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import "YKUserModel.h"

NS_ASSUME_NONNULL_BEGIN

#define updateTokenNotificationKeyName @"YKFRAMEWORK_USERMANAGER_TOKEN_UPDATE"
#define updateUserNotificationKeyName @"YKFRAMEWORK_USERMANAGER_USER_UPDATE"

@interface YKUserManager : NSObject

+ (YKUserModel *)currentModel;

+ (NSString *)currentToken;

+ (void)loginWith:(NSString *)phone password:(NSString *)password finishCallBack:(void(^_Nullable)(NSError *error))finishCallBack;

+ (void)registWith:(NSString *)phone password:(NSString *)password rpsd:(NSString *)rpsd finishCallBack:(void (^_Nullable)(NSError * _Nullable error))finishCallBack;

+ (void)registGuestWithFinishCallBack:(void(^_Nullable)(NSError * _Nullable error))finishCallBack;

+ (void)reloadInfoWithFinishCallBack:(void(^_Nullable)(NSError *error))finishCallBack;

+ (void)logout;

- (instancetype _Nonnull )init NS_UNAVAILABLE __SWIFT_UNAVAILABLE;
+ (instancetype _Nonnull )new NS_UNAVAILABLE __SWIFT_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
