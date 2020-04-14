Pod::Spec.new do |spec|
spec.name         = 'TSMPaySDK'
spec.version      = '1.0.4'
spec.license      = { :type => 'MIT' }
spec.homepage     = 'https://github.com/leajiang/TSMPaySDK'
spec.authors      = { "jiangle" => "649498510@qq.com" }
spec.summary      = 'jiangle.'
spec.source       = { :git => 'https://github.com/leajiang/TSMPaySDK.git', :tag =>'1.0.4'  }
spec.platform     = :ios, '8.0'
spec.vendored_frameworks = 'TSMPaySDK.framework','AlipaySDK.framework'
spec.frameworks   = 'UIKit','AVFoundation','Foundation','libc++.tbd','libz.tbd','SystemConfiguration','CoreTelephony','QuartzCore','CoreText','CoreGraphics','CFNetwork','CoreMotion'
spec.resource = "Resources/AlipaySDK.bundle"

spec.dependency 'AFNetworking'
spec.dependency 'AlicloudPush'
end
