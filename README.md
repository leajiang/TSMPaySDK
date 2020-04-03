# TSMPaySDK

#第 1 步：获取最新版本的 Xcode

    要想使用TSMPaySDK for iOS 开发项目，您需要 8.0 版或更高版本的 Xcode。

#第 2 步：获取 CocoaPods

    $ sudo gem install cocoapods

#第 3 步：使用 CocoaPods 安装 SDK

    pod 'TSMPaySDK'

#第 4 步：开始接入

    1.SDK初始化
    OC使用
    在AppDelegate.m文件引入头文件
    #import <TSMPaySDK/TSMPaySDK.h>
    -(BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
    {  
       [HYAlipayManager registerApp:@"key" secretKey:@"secret"];
    ……
    }
    -(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
        
        if ([url.host isEqualToString:@"safepay"]) {
            //必须调用（sdk会返回支付状态）
            [HYAlipayManager.shareManager processOrderWithPaymentResult:url];
        }
        return YES;
    }
    -(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
        if ([url.host isEqualToString:@"safepay"]) {
            //必须调用（sdk会返回支付状态）
            [HYAlipayManager.shareManager processOrderWithPaymentResult:url];
        }
        return YES;
    }
    
    swift使用
    在AppDelegate.swift文件引入头文件
    import TSMPaySDK
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        HYAlipayManager.registerApp("key", secretKey: "secret")
        return true
    }
    
    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any) -> Bool {
        if let host = url.host,host == "safepay" {
            //必须调用（sdk会返回支付状态）
            HYAlipayManager.share().processOrder(withPaymentResult: url)
        }
        return true
    }
    func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        if let host = url.host,host == "safepay" {
            //必须调用（sdk会返回支付状态）
            HYAlipayManager.share().processOrder(withPaymentResult: url)
        }
        return true
    }
    
    2.开始支付（目前sdk中只接入支付宝，入参请查看具体详情）
    /// 支付宝支付方法
    /// @param userId 用户ID（暂时直传）
    /// @param outTradeNo 业务订单号（业务请求方系统内单号）
    /// @param tradeAmount 交易金额
    /// @param subject 订单标题
    /// @param notifyUrl 接入商后台结果通知地址
    /// @param appScheme 应用注册scheme,在Info.plist定义URL types
    /// @param completionHandler 支付后回调（resultStatus=9000时支付成功，其他失败并返回错误提示）
    - (void)startAliPayByUserId:(NSString *)userId outTradeNo:(NSString *)outTradeNo tradeAmount:(CGFloat)tradeAmount subject:(NSString *)subject notifyUrl:(NSString *)notifyUrl appScheme:(NSString *)appScheme completionHandler:(void(^)(id result))completionHandler;
    
    3.查询支付状态
    /// 支付状态查询(SDK只能查询一天以内产生的订单)
    /// @param outTradeNo 业务订单号(接入商系统)
    /// @param callBack 支付状态
    /// OPEN:初始状态(创建时状态，待支付)
    /// PAYING:支付中
    /// SUCCESS:成功
    /// CLOSED:已关闭
    /// INVALID:无效订单(超时或取消等其他)
    /// 为空则请求失败
    - (void)orderStatusByoutTradeNo:(NSString *)outTradeNo callBack:(void(^)(NSString *status))callBack;
