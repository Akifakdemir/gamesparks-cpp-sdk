LOCAL_PATH := $(call my-dir)
MODULE_PATH := $(LOCAL_PATH)

CPP_DEPS_PATH := ../../dependencies

include $(CLEAR_VARS)
LOCAL_MODULE    := libcrypto
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/x86/libcrypto.a
else
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/libcrypto.a
endif
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := libssl 
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/x86/libssl.a
else
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/libssl.a
endif
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libGamesparks

EASTL_SRC_DIR := $(GS_SRC_PRIVATE)/deps/eastl/src 

LOCAL_C_INCLUDES := \
	"../../include/" \
	"../../dependencies/openssl/include" \
	"../../dependencies/eastl/include" \
	"../../dependencies/cjson" \
	"../../dependencies/hmac" \
	"../../dependencies/easywsclient" \
	"../../dependencies/google" \


LOCAL_SRC_FILES := \
	$(wildcard ../../src/*.cpp) \
	$(wildcard ../../include/*.h) \
	$(wildcard ../../dependencies/cjson/*.cpp) \
	$(wildcard ../../dependencies/eastl/src/*.cpp) \
	$(wildcard ../../dependencies/easywsclient/*.cpp) \
	$(wildcard ../../dependencies/hmac/*.c) \
	$(wildcard ../../dependencies/google/*.cpp) \
	$(wildcard ../../samples/extra/EASTLMem.cpp) \


LOCAL_CFLAGS += -DSESSION_CERTS
LOCAL_CFLAGS += -DSSL_SUPPORT
LOCAL_CFLAGS += -fPIC
LOCAL_CFLAGS += -DGS_USE_EASTL=1
#LOCAL_CFLAGS +=  -fexceptions

LOCAL_CFLAGS +=  -Wno-psabi 
#LOCAL_CFLAGS += -fno-rrti 
LOCAL_CFLAGS += -fno-exceptions

LOCAL_STATIC_LIBRARIES := libssl
LOCAL_STATIC_LIBRARIES += libcrypto

include $(BUILD_STATIC_LIBRARY)
