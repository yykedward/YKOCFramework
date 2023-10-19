//
//  YKOpenAI.h
//  YKOCFramework
//
//  Created by edward on 2023/4/28.
//  Copyright © 2023 Edward（本内容遵循MIT协议）. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YKOpenAI : NSObject

+ (void)requestAIWithQuestion:(NSString *)question complate:(void(^)(NSString *result, NSError *error))complate;

@end

NS_ASSUME_NONNULL_END
