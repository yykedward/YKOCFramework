#!/bin/bash

# ===================== 配置项（根据你的工程修改） =====================
PROJECT_NAME="YKOCFramework" # 改为你的工程名
PROJECT_PATH="./${PROJECT_NAME}.xcodeproj"
BUILD_DIR="./build"
OUTPUT_DIR="./XCFramework"
TARGET_NAME="YKOCFramework" # 改为你的target名
# =====================================================================

# ========== 新增：防并发 - 检查是否有xcodebuild进程在运行 ==========
if pgrep -x "xcodebuild" > /dev/null; then
    echo "⚠️ 发现有xcodebuild进程正在运行，先终止它..."
    killall xcodebuild
    sleep 2 # 等待进程终止
fi

# ========== 新增：清理Xcode的DerivedData临时目录（可选，按需开启） ==========
# 注意：替换为你自己的DerivedData路径，或注释掉这行（上面已手动删除过可忽略）
# rm -rf /Users/edward/Library/Developer/Xcode/DerivedData/YKOCFramework-*

# 1. 清理之前的编译产物（保留原有逻辑）
rm -rf "${BUILD_DIR}"
rm -rf "${OUTPUT_DIR}"

# 2. 编译真机版本（原有逻辑，建议添加 -quiet 减少日志，可选）
xcodebuild -project "${PROJECT_PATH}" -scheme "${TARGET_NAME}" -configuration Release -sdk iphoneos \
            BUILD_DIR="${BUILD_DIR}" \
            BUILD_ROOT="${BUILD_DIR}" \
            SKIP_INSTALL=NO \
            BUILD_LIBRARY_FOR_DISTRIBUTION=YES \
            -quiet # 新增：静默编译，减少日志干扰

# 3. 编译模拟器版本（原有逻辑，添加 -quiet）
xcodebuild -project "${PROJECT_PATH}" -scheme "${TARGET_NAME}" -configuration Release -sdk iphonesimulator \
            BUILD_DIR="${BUILD_DIR}" \
            BUILD_ROOT="${BUILD_DIR}" \
            SKIP_INSTALL=NO \
            BUILD_LIBRARY_FOR_DISTRIBUTION=YES \
            -quiet # 新增：静默编译

# 4. 合并为XCFramework（原有逻辑）
xcodebuild -create-xcframework \
            -framework "${BUILD_DIR}/Release-iphoneos/${TARGET_NAME}.framework" \
            -framework "${BUILD_DIR}/Release-iphonesimulator/${TARGET_NAME}.framework" \
            -output "${OUTPUT_DIR}/${TARGET_NAME}.xcframework"

# 5. 清理临时文件（原有逻辑）
rm -rf "${BUILD_DIR}"

# 6. 提示完成
echo "✅ XCFramework已生成，路径：${OUTPUT_DIR}/${TARGET_NAME}.xcframework"
