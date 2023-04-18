//
//  YKUserModel.h
//  YKOCFramework
//
//  Created by edward on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YKUserModel : NSObject

//MARK: readonly
///
@property (nonatomic, copy, readonly) NSString *Id;
///
@property (nonatomic, assign, readonly) NSInteger type;
///
@property (nonatomic, assign, readonly) NSInteger sex;
///
@property (nonatomic, assign, readonly) NSInteger exp;
///
@property (nonatomic, assign, readonly) NSInteger status;

//MARK: readwrite
///
@property (nonatomic, copy, readwrite) NSString *nickname;
///
@property (nonatomic, copy, readwrite) NSString *avatar;


- (instancetype _Nonnull )init NS_UNAVAILABLE __SWIFT_UNAVAILABLE;
+ (instancetype _Nonnull )new NS_UNAVAILABLE __SWIFT_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
