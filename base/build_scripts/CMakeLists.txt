CMAKE_MINIMUM_REQUIRED (VERSION 2.8.12)

PROJECT (Gamesparks) 

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/CMakeIncludes")
include("create_source_groups_macro.cmake")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/tools/cmake/")

FILE(GLOB_RECURSE SOURCES
	"${PROJECT_SOURCE_DIR}/../src/*.cpp"
	"${PROJECT_SOURCE_DIR}/../include/*.h"
	"${PROJECT_SOURCE_DIR}/../dependencies/*.c"
	"${PROJECT_SOURCE_DIR}/../dependencies/*.cpp"
	"${PROJECT_SOURCE_DIR}/../dependencies/*.h"
	"${PROJECT_SOURCE_DIR}/../dependencies/*.hpp"
)

IF(NOT USE_EASTL)
	FILE(GLOB_RECURSE EASTL_SOURCES
		"${PROJECT_SOURCE_DIR}/../dependencies/eastl/*.c"
		"${PROJECT_SOURCE_DIR}/../dependencies/eastl/*.cpp"
		"${PROJECT_SOURCE_DIR}/../dependencies/eastl/*.h"
		"${PROJECT_SOURCE_DIR}/../dependencies/eastl/*.hpp"
	)

	list(REMOVE_ITEM SOURCES ${EASTL_SOURCES})
ENDIF()



create_source_groups( SOURCES )

IF (APPLE)
	set(OPENSSL_DIR "openssl-1.0.1j")
ELSE (APPLE)
	set(OPENSSL_DIR "openssl")
ENDIF()

include_directories(
	"${PROJECT_SOURCE_DIR}/../include/"
	"${PROJECT_SOURCE_DIR}/../dependencies/${OPENSSL_DIR}/include"
	"${PROJECT_SOURCE_DIR}/../dependencies/eastl/include"
	"${PROJECT_SOURCE_DIR}/../dependencies/cjson"
	"${PROJECT_SOURCE_DIR}/../dependencies/hmac"
	"${PROJECT_SOURCE_DIR}/../dependencies/easywsclient"
	"${PROJECT_SOURCE_DIR}/../dependencies/google"
)

option(BUILD_IOS "Build iOS static lib" OFF)


IF(NO_STL_FUNCTIONAL)
	ADD_DEFINITIONS(-DSTL_FUNCTIONAL_SUPPORTED=0)
ELSE(NO_STL_FUNCTIONAL)
	ADD_DEFINITIONS(-DSTL_FUNCTIONAL_SUPPORTED=1)
ENDIF()

IF(USE_EASTL)
	ADD_DEFINITIONS(-DGS_USE_EASTL=1)
ENDIF()

#C++ Dialect needs to be set to std-c++-11
#cmake -DBUILD_IOS=1 ../gsCpp -GXcode
IF (APPLE)
	#find_package(OpenSSL REQUIRED)

	#message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
	#message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")
	set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
	
	#
	IF (BUILD_IOS)
		ADD_DEFINITIONS(-DIOS)
		set (WS_LIBS	"${PROJECT_SOURCE_DIR}/../dependencies/${OPENSSL_DIR}/libIOS/libcrypto.a"
						"${PROJECT_SOURCE_DIR}/../dependencies/${OPENSSL_DIR}/libIOS/libssl.a"
					)

		set(SOURCES ${SOURCES} "${PROJECT_SOURCE_DIR}/../src/GSIosHelper.mm")
	ELSE (BUILD_IOS)
		set (WS_LIBS	"${PROJECT_SOURCE_DIR}/../dependencies/${OPENSSL_DIR}/libOSX/libcrypto.a"
						"${PROJECT_SOURCE_DIR}/../dependencies/${OPENSSL_DIR}/libOSX/libssl.a"
					)
	ENDIF()

	
ELSEIF (WIN32)
	IF (${CMAKE_SIZEOF_VOID_P} MATCHES 4)   # Windows 32 bit
		set (WS_LIBS	"${PROJECT_SOURCE_DIR}/../dependencies/openssl/libVSWin32/ssleay32.lib"
						"${PROJECT_SOURCE_DIR}/../dependencies/openssl/libVSWin32/libeay32.lib"
						wsock32 ws2_32)
	ELSE (${CMAKE_SIZEOF_VOID_P} MATCHES 4) # Not Windows 32 Bit, e.g. 64 Bit
		set (WS_LIBS	"${PROJECT_SOURCE_DIR}/../dependencies/openssl/libVSWin64/ssleay32.lib"
						"${PROJECT_SOURCE_DIR}/../dependencies/openssl/libVSWin64/libeay32.lib"
						wsock32 ws2_32)
	ENDIF (${CMAKE_SIZEOF_VOID_P} MATCHES 4)


	# avoid warnings about depricated sprintf
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
ENDIF()


IF (${BUILD_IOS} STREQUAL "1")
	if (NOT DEFINED IOS_PLATFORM)
		set (IOS_PLATFORM "OS")
	endif (NOT DEFINED IOS_PLATFORM)
	set (IOS_PLATFORM ${IOS_PLATFORM} CACHE STRING "Type of iOS Platform")

	if (${IOS_PLATFORM} STREQUAL "OS")
		set(CMAKE_OSX_ARCHITECTURES "armv6" "armv7" "armv7s" "arm64")
		set(CMAKE_IOS_DEVELOPER_ROOT "/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer")
		set(CMAKE_OSX_SYSROOT ${CMAKE_IOS_DEVELOPER_ROOT}/SDKs/iPhoneOS.sdk)
		set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphoneos")
	else (${IOS_PLATFORM} STREQUAL "OS")
		set (CMAKE_OSX_ARCHITECTURES "i386" "x86_64")
		set(CMAKE_IOS_DEVELOPER_ROOT "/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer")
		set(CMAKE_OSX_SYSROOT ${CMAKE_IOS_DEVELOPER_ROOT}/SDKs/iPhoneSimulator.sdk)
		set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphonesimulator")
	endif (${IOS_PLATFORM} STREQUAL "OS")
ENDIF()

# GS Lib
ADD_LIBRARY (Gamesparks ${SOURCES})
target_include_directories (
	Gamesparks
	PUBLIC
	"${PROJECT_SOURCE_DIR}/../include/"
	"${PROJECT_SOURCE_DIR}/../dependencies/cjson"
)
ADD_DEFINITIONS(-DSESSION_CERTS)
#ADD_DEFINITIONS(-DGS_USE_EASTL=1)

IF (APPLE)
	# set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
	# set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
	# set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
ENDIF()

if (BUILD_IOS)
set(SAMPLE_EXTRA_ARG "MACOSX_BUNDLE")
endif(BUILD_IOS)

#IF (NOT BUILD_IOS)
#
#	Samples
#
file(GLOB SAMPLE_FILES "${PROJECT_SOURCE_DIR}/../samples/*.cpp")

# export variable to parent scope
set(WS_LIBS ${WS_LIBS} PARENT_SCOPE)

#IF(NOT BUILD_IOS)
foreach(SAMPLE_FILE ${SAMPLE_FILES})
	#add_test(validate_${i}, "validator", ${SAMPLE_FILE})

	get_filename_component(SAMPLE_NAME ${SAMPLE_FILE} NAME_WE)

	IF (USE_EASTL)
		set(SAMPLE_EXTRA_FILES 
		"${PROJECT_SOURCE_DIR}/../samples/extra/EASTLMem.cpp"
		)
	ELSE (USE_EASTL)
		set(SAMPLE_EXTRA_FILES "")
	ENDIF()

	# add extra sources for simulator
	IF ("${BUILD_IOS}" STREQUAL "1")
		if (${IOS_PLATFORM} STREQUAL "SIMULATOR")
			set(SAMPLE_EXTRA_FILES ${SAMPLE_EXTRA_FILES} "${PROJECT_SOURCE_DIR}/../samples/extra/UNIX2003_Fix.c")
		endif()
	ENDIF()


	if (BUILD_IOS)
	set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.\${PRODUCT_NAME:identifier}")
	endif()

	ADD_EXECUTABLE (
		${SAMPLE_NAME}
		${SAMPLE_EXTRA_ARG}
		${SAMPLE_FILE}
		"${PROJECT_SOURCE_DIR}/../samples/sample_configuration.h"
		"${PROJECT_SOURCE_DIR}/../samples/extra/usleep.cpp"
		${SAMPLE_EXTRA_FILES}
		#"${PROJECT_SOURCE_DIR}/../samples/extra/UNIX2003_Fix.c"
	)

	TARGET_LINK_LIBRARIES (${SAMPLE_NAME} Gamesparks ${WS_LIBS})

	if (BUILD_IOS)
		set_target_properties(${SAMPLE_NAME} PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iOS Developer")
		TARGET_LINK_LIBRARIES (${SAMPLE_NAME} Gamesparks "-framework Foundation")
	endif()
endforeach()
#ENDIF()
#ENDIF()
