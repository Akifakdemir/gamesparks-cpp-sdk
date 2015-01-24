IF (NOT TAG)
	message( "You need to set the tag of the visual studio build where the cmake should take the gtest binaries from.")
	message( "Valid tags are for example: win32_vs2013, win64_vs2013")
	message( "example: cmake -G Visual Studio 12 -DTAG:STRING=win32_vs2013")
	#message(FATAR_ERROR)
ENDIF()

CMAKE_MINIMUM_REQUIRED (VERSION 2.8) 

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../../base/build_scripts/CMakeIncludes")
include("create_source_groups_macro.cmake")
include("iterate_subdirs.cmake")


# GTEST definition
SET(GTEST_VERSION "1.7.0")
SET(GTEST_ROOT  "${PROJECT_SOURCE_DIR}/../dependencies/gtest-${GTEST_VERSION}")
SET(GTEST_SRC "${GTEST_ROOT}/src")
SET(GTEST_INC "${GTEST_ROOT}/include")

IF (APPLE)
	SET(GTEST_LIB_NAME "libgtest.a")
ELSE(APPLE)
	SET(GTEST_LIB_NAME "gtest.lib")
ENDIF()

SET(GTEST_LIB_DEBUG "${PROJECT_SOURCE_DIR}/../build/dependencies/gtest/${TAG}/Debug/${GTEST_LIB_NAME}")
SET(GTEST_LIB_RELEASE "${PROJECT_SOURCE_DIR}/../build/dependencies/gtest/${TAG}/Release/${GTEST_LIB_NAME}")
SET(GTEST_MAIN "${GTEST_SRC}/gtest_main.cc")

# Add all tests for the BaseSDK
SET(BASE_TEST_ROOT "${PROJECT_SOURCE_DIR}/../tests/base")
SUBDIRLIST(SUBDIRS ${BASE_TEST_ROOT})

if (${TARGET_OS} STREQUAL "IOS")
  message("Targeting ${TARGET_OS} with architecture: ${TARGET_ARCH}")
  set(CMAKE_OSX_ARCHITECTURES ${TARGET_ARCH})
  set(SDKVER "8.1")
  set(DEVROOT "/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer")
  set(SDKROOT "${DEVROOT}/SDKs/iPhoneOS${SDKVER}.sdk")

  if(EXISTS ${SDKROOT})
      set(CMAKE_OSX_SYSROOT "${SDKROOT}")
  else()
      message("Warning, iOS Base SDK path not found: " ${SDKROOT})
  endif()

  set(CMAKE_XCODE_EFFECTIVE_PLATFORMS "-iphoneos;-iphonesimulator")
elseif (${TARGET_OS} STREQUAL "OSX")
  set(CMAKE_OSX_ARCHITECTURES ${TARGET_ARCH})
endif()

# Iterate through all folders to create separated test projects and executables 
FOREACH(subdir ${SUBDIRS})

	SET(TEST_NAME "TEST_${subdir}")
	SET(TEST_ROOT "${BASE_TEST_ROOT}/${subdir}")
	message("Add test: " ${subdir} " from " ${TEST_ROOT})
	
	file(GLOB TEST_FILES "${TEST_ROOT}/*.cc" "${TEST_ROOT}/*.h" "${TEST_ROOT}/*.cpp")
	

IF (WIN32)
	# gtest is using unicode, we try to match there requirements here
	ADD_DEFINITIONS(-D_UNICODE -DUNICODE)

	# gtest is linking against the static runtime, we have to switch it here to match
	#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    #set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

    ADD_DEFINITIONS("/MP") # enable multi cpu compilation
ENDIF()

	include_directories(
		${BASE_TEST_ROOT}
		${GTEST_INC}
	)

	ADD_EXECUTABLE (
		${TEST_NAME}
		${TEST_FILES}
		${GTEST_MAIN} # Add the gtest main, dont use another one 
	)

	target_link_libraries(
		${TEST_NAME}
		debug ${GTEST_LIB_DEBUG} 
		optimized ${GTEST_LIB_RELEASE} 
	)
ENDFOREACH()