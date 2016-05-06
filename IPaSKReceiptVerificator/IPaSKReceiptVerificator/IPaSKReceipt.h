//
//  IPaSKReceipt.h
//  IPaSKReceiptVerificator
//
//  Created by IPa Chen on 2015/2/20.
//  Copyright (c) 2015年 A Magic Studio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <openssl/pkcs7.h>
#define IPaStoreKitErrorDomain @"com.IPaStoreKit"
#define IPaStoreKitErrorCodeUnableToCompleteVerification 200
#ifdef DEBUG
#define IPaSKLog(...) NSLog(@"IPaStoreKit: %@", [NSString stringWithFormat:__VA_ARGS__]);
#else
#define IPaSKLog(...)
#endif

//int ASN1ReadInteger(const uint8_t **pp, long omax);
//NSData* ASN1ReadOctectString(const uint8_t **pp, long omax);
//NSString* ASN1ReadString(const uint8_t **pp, long omax, int expectedTag, NSStringEncoding encoding);
//NSString* ASN1ReadUTF8String(const uint8_t **pp, long omax);
//NSString* ASN1ReadIA5SString(const uint8_t **pp, long omax);

@import StoreKit;

@interface IPaSKReceipt : NSObject
- (int) ASN1ReadInteger:(const uint8_t **)pp omax:(long)omax;
- (NSData*) ASN1ReadOctectString:(const uint8_t **)pp omax:(long)omax;
- (NSString*) ASN1ReadString:(const uint8_t **)pp omax:(long) omax expectedTag:(int) expectedTag encoding:(NSStringEncoding) encoding;
- (NSString*) ASN1ReadUTF8String:(const uint8_t **)pp omax:(long) omax;
- (NSString*) ASN1ReadIA5SString:(const uint8_t **)pp omax:(long) omax;



- (void)enumerateASN1Attributes:(const uint8_t*)p length:(long)tlength usingBlock:(void (^)(NSData *data, int type))block;

- (NSDate*)formatRFC3339String:(NSString*)string;
@end
