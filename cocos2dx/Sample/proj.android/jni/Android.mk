LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := libcrypto 
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := ../../../GameSparksSDK/dependencies/openssl/libAndroid/x86/libcrypto.a
else
	LOCAL_SRC_FILES := ../../../GameSparksSDK/dependencies/openssl/libAndroid/arm/libcrypto.a
endif
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := libssl 
ifeq ($(TARGET_ARCH),x86)
	LOCAL_SRC_FILES := ../../../GameSparksSDK/dependencies/openssl/libAndroid/x86/libssl.a
else
	LOCAL_SRC_FILES := ../../../GameSparksSDK/dependencies/openssl/libAndroid/arm/libssl.a
endif
include $(PREBUILT_STATIC_LIBRARY)


include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := \
			hellocpp/main.cpp \
			../../Classes/AppDelegate.cpp \
			../../Classes/HelloWorldScene.cpp \
			../../Classes/ScreenLog.cpp \
			../../../GameSparksSDK/dependencies/easywsclient/easywsclient.cpp \
			../../../GameSparksSDK/dependencies/google/timesupport.cpp \
			../../../GameSparksSDK/dependencies/cjson/cJSON.cpp \
			../../../GameSparksSDK/dependencies/hmac/hmac_sha2.c \
			../../../GameSparksSDK/dependencies/hmac/sha2.c \
			../../../GameSparksSDK/src/GS.cpp \
			../../../GameSparksSDK/src/GSConnection.cpp \
			../../../GameSparksSDK/src/GSData.cpp \
			../../../GameSparksSDK/src/GSDateTime.cpp \
			../../../GameSparksSDK/src/GSIosHelper.mm \
			../../../GameSparksSDK/src/GSMessage.cpp \
			../../../GameSparksSDK/src/GSRequest.cpp \
			../../../GameSparksSDK/src/GSTypedResponse.cpp \
			../../../GameSparksSDK/src/GSUtil.cpp \
			../../../GameSparksSDK/src/IGSPlatform.cpp

# *GS* we have to add gs to the include directories
LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../Classes \
	$(LOCAL_PATH)/../../../GameSparksSDK/include \
	$(LOCAL_PATH)/../../../GameSparksSDK/dependencies/cjson \
	$(LOCAL_PATH)/../../../GameSparksSDK/dependencies/google \
	$(LOCAL_PATH)/../../../GameSparksSDK/dependencies/easywsclient \
	$(LOCAL_PATH)/../../../GameSparksSDK/dependencies/hmac \
	$(LOCAL_PATH)/../../../GameSparksSDK/dependencies/openssl/include

LOCAL_STATIC_LIBRARIES := \
	cocos2dx_static \
	libssl \
	libcrypto

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
