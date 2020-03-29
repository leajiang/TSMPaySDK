//
//  HYAlipayManager.h
//  HYPayManager
//
//  Created by lejiang on 2020/3/26.
//  Copyright © 2020 lejiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// 支付宝开放平台文档
/// https://opendocs.alipay.com/open/204/105295

@interface HYAlipayManager : NSObject

+ (instancetype)shareManager;

    // 重要说明
    // 这里只是为了方便直接向商户展示支付宝的整个支付流程；所以Demo中加签过程直接放在客户端完成；
    // 真实App里，privateKey等数据严禁放在客户端，加签过程务必要放在服务端完成；
    // 防止商户私密数据泄露，造成不必要的资金损失，及面临各种安全风险；
    /*============================================================================*/
    /*=======================需要填写商户app申请的===================================*/
    /*============================================================================*/
    //NSString *appID = @"";
    
    // 如下私钥，rsa2PrivateKey 或者 rsaPrivateKey 只需要填入一个
    // 如果商户两个都设置了，优先使用 rsa2PrivateKey
    // rsa2PrivateKey 可以保证商户交易在更加安全的环境下进行，建议使用 rsa2PrivateKey
    // 获取 rsa2PrivateKey，建议使用支付宝提供的公私钥生成工具生成，
    // 工具地址：https://doc.open.alipay.com/docs/doc.htm?treeId=291&articleId=106097&docType=1
    // NSString *rsa2PrivateKey = @"";
    // NSString *rsaPrivateKey = @"";
    /*============================================================================*/
    /*============================================================================*/
    /*============================================================================*/

/// 支付宝支付方法
/// @param appID 商户app申请的 appID
/// @param rsa2PrivateKey 如上
/// @param rsaPrivateKey 如上
/// @param commodityTitle 商品名字
/// @param commoditySubject 商品详细内容
/// @param tradeNO 商品订单号
/// @param totalAmount 商品金额
/// @param appScheme 应用注册scheme,在AliSDKDemo-Info.plist定义URL types
- (void)startAliPay:(NSString *)appID rsa2PrivateKey:(NSString *)rsa2PrivateKey rsaPrivateKey:(NSString *)rsaPrivateKey commodityTitle:(NSString *)commodityTitle commoditySubject:(NSString *)commoditySubject tradeNO:(NSString *)tradeNO totalAmount:(CGFloat)totalAmount appScheme:(NSString *)appScheme;

/// 支付跳转支付宝钱包进行支付，处理支付结果
-(void)processOrderWithPaymentResult:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
