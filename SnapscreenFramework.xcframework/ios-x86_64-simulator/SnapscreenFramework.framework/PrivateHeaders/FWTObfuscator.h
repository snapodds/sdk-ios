//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

#import <Foundation/Foundation.h>
#define __obfuscated

extern NSString * const FWTObfuscatorErrorDomain;

@interface FWTObfuscator : NSObject

+ (instancetype)defaultObfuscator;
@property (nonatomic, copy) NSString *encryptionKey;

- (void)setClassAsKey:(Class)classRef;

@end
