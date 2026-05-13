#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YKConfig : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 配置项目通道凭证（需在发起网络请求前调用）
/// @param appKey   服务端分配的应用公钥（fa_project.app_key）
/// @param appSecret 应用密钥（fa_project.app_secret）
+ (void)setAppKey:(NSString *)appKey appSecret:(NSString *)appSecret;

@end

NS_ASSUME_NONNULL_END
