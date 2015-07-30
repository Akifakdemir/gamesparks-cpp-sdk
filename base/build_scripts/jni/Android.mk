LOCAL_PATH := $(call my-dir)
MODULE_PATH := $(LOCAL_PATH)

CPP_DEPS_PATH := ../../dependencies

include $(CLEAR_VARS)
LOCAL_MODULE    := libcrypto
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/x86/libcrypto.a
else
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/arm/libcrypto.a
endif
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := libssl 
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/x86/libssl.a
else
	LOCAL_SRC_FILES := $(CPP_DEPS_PATH)/openssl/libAndroid/arm/libssl.a
endif
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libGamesparks

LOCAL_C_INCLUDES := \
	"../../include/" \
	"../../dependencies/openssl/include" \
	"../../dependencies/cjson" \
	"../../dependencies/hmac" \
	"../../dependencies/easywsclient" \
	"../../dependencies/google" \


LOCAL_SRC_FILES := \
	$(wildcard ../../src/*.cpp) \
	$(wildcard ../../include/*.h) \
	$(wildcard ../../dependencies/cjson/*.cpp) \
	$(wildcard ../../dependencies/easywsclient/*.cpp) \
	$(wildcard ../../dependencies/hmac/*.c) \
	$(wildcard ../../dependencies/google/*.cpp) \


LOCAL_CFLAGS += -DSESSION_CERTS
LOCAL_CFLAGS += -DSSL_SUPPORT

LOCAL_STATIC_LIBRARIES := libssl
LOCAL_STATIC_LIBRARIES += libcrypto

include $(BUILD_STATIC_LIBRARY)
