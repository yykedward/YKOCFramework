//
//  YKFrameworkTranslation.h
//  YKOCFramework_main
//
//  Created by edward on 2023/11/9.
//  Copyright © 2023 Edward（本内容遵循MIT协议）. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, YKFrameworkTranslationType) {
    YKFrameworkTranslationTypeEN       = 0,///英语
    YKFrameworkTranslationTypeRU       = 1,///俄语
    YKFrameworkTranslationTypeDE       = 2,///德语
    YKFrameworkTranslationTypeTR       = 3,///土耳其语
    YKFrameworkTranslationTypePT       = 4,///葡萄牙语
    YKFrameworkTranslationTypeID       = 5,///印尼语
    YKFrameworkTranslationTypeTH       = 6,///泰语
};


NS_ASSUME_NONNULL_BEGIN

@interface YKFrameworkTranslation : NSObject

+ (void)transplationWith:(nonnull NSString *)content type:(YKFrameworkTranslationType)type complete:(nullable void (^)(NSString *result))complete;

@end

NS_ASSUME_NONNULL_END
