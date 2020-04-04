Pod::Spec.new do |spec|
spec.name         = 'TSMPaySDK'
spec.version      = '1.0.3'
spec.license      = { :type => 'MIT' }
spec.homepage     = 'https://github.com/leajiang/TSMPaySDK'
spec.authors      = { "jiangle" => "649498510@qq.com" }
spec.summary      = 'jiangle.'
spec.source       = { :git => 'https://github.com/leajiang/TSMPaySDK.git', :tag =>'1.0.3'  }
spec.platform     = :ios, '8.0'
spec.vendored_frameworks = 'TSMPaySDK.framework'
spec.frameworks   = 'UIKit','AVFoundation','Foundation'

spec.dependency 'AlipaySDK-iOS'
spec.dependency 'AFNetworking'
end
