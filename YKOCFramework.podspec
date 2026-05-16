
Pod::Spec.new do |spec|
  spec.name         = "YKOCFramework"
  spec.version      = "1.2.0"
  spec.summary      = "A short description of YKOCFramework."
  spec.description      = <<-DESC
                    所有内容
                       DESC
                       
  spec.homepage     = "https://github.com/yykedward/YKOCFramework"
  
  spec.author       = { "edward" => "534272374@qq.com" }
  spec.source       = { :git => "https://github.com/yykedward/YKOCFramework.git",:tag => spec.version.to_s }
  spec.ios.deployment_target = "12.0"
  spec.framework = 'Foundation', 'CoreFoundation', 'Security'
  spec.vendored_frameworks = "XCFramework/YKOCFramework.xcframework"


end
