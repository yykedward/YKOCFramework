#!/bin/bash
set -euo pipefail

# ============================================================
# YKOCFramework XCFramework Builder
#
# Builds a universal XCFramework for iOS device (arm64) and
# simulator (arm64 + x86_64), then packages for distribution.
# ============================================================

readonly PROJECT_NAME="YKOCFramework"
readonly SCHEME_NAME="YKOCFramework"
readonly PROJECT_PATH="./${PROJECT_NAME}.xcodeproj"
readonly BUILD_DIR="./build"
readonly OUTPUT_DIR="./XCFramework"
readonly DERIVED_DATA="${BUILD_DIR}/DerivedData"

# ---- terminal colors ----
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[1;33m'
readonly CYAN='\033[0;36m'
readonly NC='\033[0m'

declare START_TIME

# ============================================================
# Logging helpers
# ============================================================

_timestamp() { date "+%H:%M:%S"; }

log_info()    { printf "${CYAN}[%s] INFO${NC}  %s\n" "$(_timestamp)" "$*"; }
log_success() { printf "${GREEN}[%s] OK${NC}    %s\n" "$(_timestamp)" "$*"; }
log_warn()    { printf "${YELLOW}[%s] WARN${NC}  %s\n" "$(_timestamp)" "$*" >&2; }
log_error()   { printf "${RED}[%s] ERROR${NC} %s\n" "$(_timestamp)" "$*" >&2; }

# ============================================================
# Cleanup — guaranteed to run on exit
# ============================================================

cleanup() {
    local code=$?
    if [ -d "${BUILD_DIR}" ]; then
        rm -rf "${BUILD_DIR}"
    fi
    if [ $code -ne 0 ]; then
        echo ""
        log_error "Build failed (exit code ${code})"
    fi
    exit $code
}

trap cleanup EXIT INT TERM

# ============================================================
# Pre-flight validation
# ============================================================

validate_prerequisites() {
    local missing=0

    log_info "Checking environment..."

    if ! command -v xcodebuild &>/dev/null; then
        log_error "xcodebuild not found — install Xcode or Xcode CLT"
        missing=1
    fi

    if [ ! -d "${PROJECT_PATH}" ]; then
        log_error "Project not found at ${PROJECT_PATH}"
        missing=1
    fi

    if ! xcodebuild -project "${PROJECT_PATH}" -list 2>/dev/null | grep -qF "${SCHEME_NAME}"; then
        log_error "Scheme '${SCHEME_NAME}' not found in project"
        missing=1
    fi

    if [ $missing -ne 0 ]; then
        exit 1
    fi

    log_success "Environment ready"
}

# ============================================================
# Build for a single SDK
# ============================================================

build_for_sdk() {
    local sdk="$1"      # iphoneos | iphonesimulator
    local label="$2"    # human-readable label

    log_info "Building ${label}..."

    xcodebuild build \
        -project "${PROJECT_PATH}" \
        -scheme "${SCHEME_NAME}" \
        -configuration Release \
        -sdk "${sdk}" \
        -derivedDataPath "${DERIVED_DATA}" \
        SKIP_INSTALL=NO \
        BUILD_LIBRARY_FOR_DISTRIBUTION=YES \
        ONLY_ACTIVE_ARCH=NO \
        CODE_SIGNING_ALLOWED=NO

    log_success "${label} build finished"
}

# Resolve the framework path xcodebuild produced for a given SDK
framework_path_for_sdk() {
    local sdk="$1"
    echo "${DERIVED_DATA}/Build/Products/Release-${sdk}/${PROJECT_NAME}.framework"
}

# ============================================================
# Framework integrity check
# ============================================================

verify_framework() {
    local fw="$1"
    local label="$2"

    log_info "Verifying ${label} framework..."

    if [ ! -d "${fw}" ]; then
        log_error "Framework bundle missing: ${fw}"
        exit 1
    fi

    local binary="${fw}/${PROJECT_NAME}"
    if [ ! -f "${binary}" ]; then
        log_error "Binary missing inside framework: ${binary}"
        exit 1
    fi

    local filetype
    filetype=$(file -b "${binary}")
    if ! echo "${filetype}" | grep -q "Mach-O.*dynamically linked shared library"; then
        log_error "Binary is not a Mach-O dynamic library: ${filetype}"
        exit 1
    fi

    if [ ! -f "${fw}/Info.plist" ]; then
        log_error "Info.plist missing in framework"
        exit 1
    fi

    local size
    size=$(wc -c < "${binary}" | tr -d ' ')
    log_success "${label} framework OK (binary: ${size} bytes)"
}

# ============================================================
# XCFramework packaging
# ============================================================

package_xcframework() {
    local device_fw="$1"
    local sim_fw="$2"
    local output="$3"

    log_info "Packaging XCFramework..."

    rm -rf "${output}"

    xcodebuild -create-xcframework \
        -framework "${device_fw}" \
        -framework "${sim_fw}" \
        -output "${output}"

    if [ ! -d "${output}" ] || [ ! -f "${output}/Info.plist" ]; then
        log_error "XCFramework creation failed — output missing or incomplete"
        exit 1
    fi

    log_success "XCFramework packaged"
}

# ============================================================
# Main
# ============================================================

main() {
    START_TIME=$(date +%s)

    echo ""
    echo "=========================================="
    echo "  ${PROJECT_NAME} XCFramework Builder"
    echo "=========================================="
    echo ""

    # 1. validate
    validate_prerequisites

    # 2. clean previous outputs (keep build dir for trap cleanup at end)
    if [ -d "${OUTPUT_DIR}" ]; then
        log_info "Removing previous XCFramework output..."
        rm -rf "${OUTPUT_DIR}"
    fi

    # 3. build device (arm64)
    build_for_sdk "iphoneos" "Device (arm64)"
    local device_fw
    device_fw=$(framework_path_for_sdk "iphoneos")
    verify_framework "${device_fw}" "Device"

    # 4. build simulator (arm64 + x86_64)
    build_for_sdk "iphonesimulator" "Simulator (arm64, x86_64)"
    local sim_fw
    sim_fw=$(framework_path_for_sdk "iphonesimulator")
    verify_framework "${sim_fw}" "Simulator"

    # 5. package
    mkdir -p "${OUTPUT_DIR}"
    local output
    output="${OUTPUT_DIR}/${PROJECT_NAME}.xcframework"
    package_xcframework "${device_fw}" "${sim_fw}" "${output}"

    # 6. summary
    local elapsed
    elapsed=$(($(date +%s) - START_TIME))

    echo ""
    echo "=========================================="
    log_success "Done in ${elapsed}s"
    echo ""
    echo "  Output  ${output}"
    echo "=========================================="
    echo ""
}

main "$@"
