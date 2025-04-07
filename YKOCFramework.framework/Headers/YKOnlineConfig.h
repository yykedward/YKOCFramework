//
//  YKOnlineConfig.h
//  YKOCFramework
//
//  Created by edward on 2017/5/16.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString * _Nonnull const YKOC_KEY_ONLINE_PARAMS; ///< 在线参数数据缓存

@interface YKOnlineConfig : NSObject


- (instancetype _Nonnull )init NS_UNAVAILABLE __SWIFT_UNAVAILABLE;
+ (instancetype _Nonnull )new NS_UNAVAILABLE __SWIFT_UNAVAILABLE;

#pragma mark - 在线参数

/**
 获取在线参数缓存
 
 @param complete 请求完成回调
 */
+ (void)updateOnlineConfigWithComplete:(nullable void (^)(BOOL success, NSDictionary * _Nullable result))complete;

/** 返回全部数据 */
+ (nullable NSDictionary *)getConfigParams;

/** 返回对应数据 */
+ (nullable NSString *)getConfigParams:(nonnull NSString *)key;

@end
