//
//  YKUserManager.h
//  YKOCFramework_main
//
//  Created by edward on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import "YKUserModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface YKUserManager : NSObject

+ (YKUserModel *)currentModel;

+ (NSString *)currentToken;

+ (void)loginWith:(NSString *)phone password:(NSString *)password finishCallBack:(void(^)(NSError *error))finishCallBack;

+ (void)registWith:(NSString *)phone password:(NSString *)password rpsd:(NSString *)rpsd finishCallBack:(void (^)(NSError * _Nullable error))finishCallBack;

+ (void)registGuestWithFinishCallBack:(void(^)(NSError * _Nullable error))finishCallBack;

+ (void)reloadInfoWithFinishCallBack:(void(^)(NSError *error))finishCallBack;

+ (void)logout;

- (instancetype _Nonnull )init NS_UNAVAILABLE __SWIFT_UNAVAILABLE;
+ (instancetype _Nonnull )new NS_UNAVAILABLE __SWIFT_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
