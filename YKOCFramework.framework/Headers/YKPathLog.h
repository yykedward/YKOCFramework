//
//  YKPathLog.h
//  YKOCFramework
//
//  Created by edward on 2021/3/23.
//  Copyright © 2021 com.Edward. All rights reserved.
//
// version 1.0.0

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, YKPathLogMode) {
    YKPathLogModeDEBUG                 = 0,///测试模式
    YKPathLogModeRELEASE               = 1,///正式模式
};


NS_ASSUME_NONNULL_BEGIN


@interface YKPathLog : NSObject

/** 发送成功DEBUG调试消息*/
FOUNDATION_EXTERN NSString * const kYKPathDigDEBUGNotification;

- (instancetype)init NS_UNAVAILABLE;

/// 注册埋点
/// @param clientId 注册Id
+ (void)registWithClientId:(NSString *)clientId;

/// 设置模式默认(RELEASE)
/// @param mode 模式
+ (void)setMode:(YKPathLogMode)mode;

/// 添加埋点
/// @param point 埋点记录标签
/// @param name 记录名称
/// @param params 额外参数
+ (void)addPoint:(NSString *)point name:(NSString *)name params:(NSDictionary * _Nullable)params;

/// 开始记录埋点
/// @param key 记录点标签
+ (void)beginTimeDig:(NSString *)key;

/// 结束记录埋点
/// @param key 记录点标签
/// @param name 记录名称
/// @param params 额外参数
+ (void)endTimeDig:(NSString *)key name:(NSString *)name params:(NSDictionary * _Nullable)params;


@end

NS_ASSUME_NONNULL_END
