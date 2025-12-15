//
//  YKWeather.h
//  YKOCFramework_main
//
//  Created by edward on 2025/4/7.
//  Copyright © 2025 Edward（本内容遵循MIT协议）. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YKWeather : NSObject

/**
 更新在线参数缓存，程序启动时调用（可自定义缓存有效时间）
 
 @param longitude 精度
 @param latitude 维度
 @param complete 请求完成回调
 */
+ (void)weatherWithLongitude:(NSString *)longitude latitude:(NSString *)latitude complete:(nullable void (^)(BOOL success, NSDictionary * _Nullable result))complete;


@end

NS_ASSUME_NONNULL_END
