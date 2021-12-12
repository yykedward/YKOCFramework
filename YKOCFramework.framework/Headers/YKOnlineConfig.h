//
//  YKOnlineConfig.h
//  YKOCFramework
//
//  Created by edward on 2017/5/16.
//
// version 1.0.0

#import <Foundation/Foundation.h>

FOUNDATION_EXTERN NSString *const YKOC_KEY_ONLINE_PARAMS; ///< 在线参数数据缓存
FOUNDATION_EXTERN NSString *const YKOC_KEY_ONLINE_LOAD_TIME; ///< 上次成功更新在线参数缓存的时间
FOUNDATION_EXTERN const NSTimeInterval YKOC_DefaultCacheVaildTime; ///< 缓存默认数据有效时间：5分钟

FOUNDATION_EXTERN NSString *const YKOC_KEY_APPSTORE_VERSION; ///< 在线参数设置的应用最新版本号(公用参数key)

@interface YKOnlineConfig : NSObject

#pragma mark - 在线参数

/**
 更新在线参数缓存，程序启动时调用（缓存有效时间默认为5分钟）

 @param appkey 传入应用的appid
 */
+ (void)updateOnlineConfigWithAppkey:(NSString *)appkey;


/**
 更新在线参数缓存，程序启动时调用（可自定义缓存有效时间）

 @param appkey 传入应用的appid
 @param cacheVaildTime 缓存有效时间（缓存有效期间不再请求接口数据，默认值：YKOC_DefaultCacheVaildTime）
 @param complete 请求完成回调
 */
+ (void)updateOnlineConfigWithAppkey:(NSString *)appkey cacheVaildTime:(NSTimeInterval)cacheVaildTime complete:(void (^)(BOOL success))complete;

/** 返回全部数据 */
+ (NSDictionary *)getConfigParams;

/** 返回对应数据 */
+ (NSString *)getConfigParams:(NSString *)key;

#pragma mark - 其他铺助方法

/**
 将json格式字符串转为字典

 @param jsonStr json格式字符串
 @return 转换结果字典，结果可能为nil
 */
+ (NSDictionary *)getDictFromJson:(NSString *)jsonStr;


@end
