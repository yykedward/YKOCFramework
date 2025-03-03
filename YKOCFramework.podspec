
Pod::Spec.new do |spec|
  spec.name         = "YKOCFramework"
  spec.version      = "1.0.14"
  spec.summary      = "A short description of YKOCFramework."
  spec.description      = <<-DESC
                    所有内容
                       DESC
                       
  spec.homepage     = "https://github.com/yykedward/YKOCFramework"
  
  spec.author       = { "edward" => "534272374@qq.com" }
  spec.source       = { :git => "https://github.com/yykedward/YKOCFramework.git",:tag => spec.version.to_s }
  spec.ios.deployment_target = "11.0"
  spec.framework = 'Foundation', 'CoreFoundation', 'Security'

  spec.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  
  spec.static_framework  =  false
  spec.vendored_frameworks = 'YKOCFramework.framework'


end
