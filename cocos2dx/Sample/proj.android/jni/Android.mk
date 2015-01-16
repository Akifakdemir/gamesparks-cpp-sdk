LOCAL_PATH := $(call my-dir)
BASE_SDK_DIR := $(nodir $(LOCAL_PATH))../../../../base

include $(CLEAR_VARS)
LOCAL_MODULE    := libcrypto 
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := $(BASE_SDK_DIR)/dependencies/openssl/libAndroid/x86/libcrypto.a
else
	LOCAL_SRC_FILES := $(BASE_SDK_DIR)/dependencies/openssl/libAndroid/libcrypto.a
endif
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := libssl 
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := $(BASE_SDK_DIR)/dependencies/openssl/libAndroid/x86/libssl.a
else
	LOCAL_SRC_FILES := $(BASE_SDK_DIR)/dependencies/openssl/libAndroid/libssl.a
endif
include $(PREBUILT_STATIC_LIBRARY)


# *GS* link against the gamesparks static library
include $(CLEAR_VARS)
LOCAL_MODULE    := libGamesparks
LOCAL_SRC_FILES = $(BASE_SDK_DIR)/build/Android/$(TARGET_ARCH_ABI)/libGamesparks.a
include $(PREBUILT_STATIC_LIBRARY)



include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp

# *GS* we have to add gs to the include directories
LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../Classes \
	$(LOCAL_PATH)/../../../../base/include \
	$(LOCAL_PATH)/../../../../base/dependencies/cjson

LOCAL_STATIC_LIBRARIES := \
	cocos2dx_static \
	libssl \
	libcrypto \
	libGamesparks

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
