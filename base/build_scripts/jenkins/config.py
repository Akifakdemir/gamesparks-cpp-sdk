import os

BUILD_ROOT = os.path.abspath(os.path.join(__file__, '..'))

print('BUILD_ROOT is: "%(BUILD_ROOT)s"' % locals())

DEPENDENCIES_ROOT          = os.path.join(BUILD_ROOT, "dependencies")
CMAKE_ROOT                 = os.path.join(DEPENDENCIES_ROOT, "cmake")
NDK_ROOT                   = os.path.join(DEPENDENCIES_ROOT, "android-ndk")
BUILD_DIR                  = os.path.join(BUILD_ROOT, "build")
PACKAGING_OUTPUT_DIRECTORY = os.path.join(BUILD_ROOT, "dist")
