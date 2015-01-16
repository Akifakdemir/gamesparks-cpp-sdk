


BUILD_ROOT=$(pushd $(dirname $BASH_SOURCE[0]) > /dev/null && pwd -P && popd > /dev/null)

echo BUILD_ROOT "$BUILD_ROOT"

DEPENDENCIES_ROOT="$BUILD_ROOT/dependencies"
CMAKE_ROOT="$DEPENDENCIES_ROOT/cmake"
NDK_ROOT="$DEPENDENCIES_ROOT/android-ndk"
BUILD_DIR="$BUILD_ROOT/../../build"
PACKAGING_OUTPUT_DIRECTORY="$BUILD_ROOT/../../dist"
