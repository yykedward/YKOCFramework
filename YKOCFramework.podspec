
Pod::Spec.new do |spec|
  spec.name         = "YKOCFramework"
  spec.version      = "1.0.13"
  spec.summary      = "A short description of YKOCFramework."
  spec.description      = <<-DESC
                    所有内容
                       DESC
                       
  spec.homepage     = "https://github.com/yykedward/YKOCFramework"
  
  #spec.license      = { :type => 'MIT', :file => 'LICENSE' }
  
  spec.author       = { "edward" => "534272374@qq.com" }
  spec.source       = { :git => "https://github.com/yykedward/YKOCFramework.git",:tag => spec.version.to_s }
  spec.ios.deployment_target = "11.0"
  spec.framework = 'UIKit', 'Foundation', 'CoreFoundation', 'Security'
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  
  spec.static_framework  =  false
  spec.vendored_frameworks = 'YKOCFramework.framework'


end
