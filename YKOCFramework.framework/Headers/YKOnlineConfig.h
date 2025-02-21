//
//  YKOnlineConfig.h
//  YKOCFramework
//
//  Created by edward on 2017/5/16.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString * _Nonnull const YKOC_KEY_ONLINE_PARAMS; ///< 在线参数数据缓存
FOUNDATION_EXTERN NSString * _Nonnull const YKOC_KEY_ONLINE_LOAD_TIME; ///< 上次成功更新在线参数缓存的时间
FOUNDATION_EXTERN const NSTimeInterval YKOC_DefaultCacheVaildTime; ///< 缓存默认数据有效时间：5分钟

@interface YKOnlineConfig : NSObject


- (instancetype _Nonnull )init NS_UNAVAILABLE __SWIFT_UNAVAILABLE;
+ (instancetype _Nonnull )new NS_UNAVAILABLE __SWIFT_UNAVAILABLE;

#pragma mark - 在线参数

/**
 更新在线参数缓存，程序启动时调用（缓存有效时间默认为5分钟）
 */
+ (void)updateOnlineConfig;


/**
 更新在线参数缓存，程序启动时调用（可自定义缓存有效时间）

 @param cacheVaildTime 缓存有效时间（缓存有效期间不再请求接口数据，默认值：YKOC_DefaultCacheVaildTime）
 @param complete 请求完成回调
 */
+ (void)updateOnlineConfigWithCacheVaildTime:(NSTimeInterval)cacheVaildTime complete:(nullable void (^)(BOOL success, NSDictionary * _Nullable result))complete;

/** 返回全部数据 */
+ (nullable NSDictionary *)getConfigParams;

/** 返回对应数据 */
+ (nullable NSString *)getConfigParams:(nonnull NSString *)key;

@end
