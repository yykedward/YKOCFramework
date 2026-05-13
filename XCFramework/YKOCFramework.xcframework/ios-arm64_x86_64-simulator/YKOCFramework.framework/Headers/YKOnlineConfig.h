#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YKOnlineConfig : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 拉取在线配置（第一层 YKNetwork → 第二层 Pastebin 保底）
+ (void)updateConfigWithComplete:(nullable void (^)(BOOL success, NSDictionary * _Nullable config))complete;

/// 获取全部配置（内存 → 磁盘 → nil）
+ (nullable NSDictionary *)allConfig;

/// 获取单个配置值
+ (nullable NSString *)configForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
