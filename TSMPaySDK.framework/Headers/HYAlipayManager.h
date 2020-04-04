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

/// SDK初始化
+ (void)registerApp:(nonnull NSString *)appKey secretKey:(nonnull NSString *)secretKey;

/// 支付宝支付方法
/// @param userId 用户ID（暂时直传）
/// @param outTradeNo 业务订单号（业务请求方系统内单号）
/// @param tradeAmount 交易金额
/// @param subject 订单标题
/// @param notifyUrl 接入商后台结果通知地址
/// @param appScheme 应用注册scheme,在Info.plist定义URL types
/// @param completionHandler 支付后回调（resultStatus=9000时支付成功，其他失败并返回错误提示）
- (void)startAliPayByUserId:(nullable NSString *)userId
                 outTradeNo:(nonnull NSString *)outTradeNo
                tradeAmount:(CGFloat)tradeAmount
                    subject:(nonnull NSString *)subject
                  notifyUrl:(nonnull NSString *)notifyUrl
                  appScheme:(nonnull NSString *)appScheme
          completionHandler:(nonnull void(^)(id result))completionHandler;

/// 支付状态查询(SDK只能查询一天以内产生的订单)
/// @param outTradeNo 业务订单号(接入商系统)
/// @param callBack 支付状态
/// OPEN:初始状态(创建时状态，待支付)
/// PAYING:支付中
/// SUCCESS:成功
/// CLOSED:已关闭
/// INVALID:无效订单(超时或取消等其他)
/// 返回空则请求失败
- (void)orderStatusByoutTradeNo:(nonnull NSString *)outTradeNo callBack:(nonnull void(^)(NSString *status))callBack;

/// 支付跳转支付宝钱包进行支付，处理支付结果
-(void)processOrderWithPaymentResult:(nonnull NSURL *)url;

@end

NS_ASSUME_NONNULL_END
