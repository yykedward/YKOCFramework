
Pod::Spec.new do |spec|
  spec.name         = "YKOCFramework"
  spec.version      = "1.0.0"
  spec.summary      = "A short description of YKOCFramework."
  spec.description      = <<-DESC
                    所有内容
                       DESC
                       
  spec.homepage     = "http://9k6h9ngp2g.shhttp.cn/ykcocoapods/ykocframework"
  
  #spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  
  spec.author       = { "edward" => "534272374@qq.com" }
  spec.source       = { :git => "http://9k6h9ngp2g.shhttp.cn/ykcocoapods/ykocframework.git",:tag => spec.version.to_s }
  spec.ios.deployment_target = "11.0"
  spec.framework  = "Foundation","UIKit"
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  
  # 是否是静态库 这个地方很重要 假如不写这句打出来的包 就是动态库 不能使用
  spec.static_framework  =  true
  spec.vendored_frameworks = 'YKOCFramework.framework'


end
