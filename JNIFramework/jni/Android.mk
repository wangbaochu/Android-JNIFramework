###################################
#  libjnitool.a component
###################################
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_C_INCLUDES :=	$(LOCAL_PATH)/util_include
LOCAL_SRC_FILES := util_src/JNIHelper.c \
                   util_src/Byte.c \
                   util_src/TBMem.c
LOCAL_MODULE     := jnitool 
include $(BUILD_STATIC_LIBRARY)


###################################
#  libjniFramework.so component
###################################
include $(CLEAR_VARS)     
LOCAL_C_INCLUDES :=	$(LOCAL_PATH)/util_include \
                    $(LOCAL_PATH)/test_include
LOCAL_SRC_FILES  := test_src/test.c \
                    test_src/JNIGlobalInit.c
LOCAL_STATIC_LIBRARIES := libjnitool 

#LOCAL_CFLAGS += -DENABLE_ANDROID_LOG
#LOCAL_CFLAGS := -fvisibility=hidden	
#LOCAL_CFLAGS += -DHAVE_PTHREADS -DANDROID -pie -fPIE
#LOCAL_LDFLAGS += -pie -fPIE #Android 5.0 BUILD_EXECUTABLE need this flag

LOCAL_LDLIBS := -llog -lz -ldl
LOCAL_MODULE := jniFramework
include $(BUILD_SHARED_LIBRARY)
#include $(PREBUILT_STATIC_LIBRARY)
#include $(BUILD_EXECUTABLE)

