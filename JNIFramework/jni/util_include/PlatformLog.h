#ifndef __PLATFORM_LOG_H__
#define __PLATFORM_LOG_H__

//#ifdef ENABLE_ANDROID_LOG
    #include <android/log.h>
    #define LOG_TAG "JNIFramework"
    #define LOGE(...)   __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
    #define LOGI(...)   __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
    #define LOGD(...)   __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
//#else
//    #define LOGE(...)
//    #define LOGI(...)
//    #define LOGD(...)
//#endif

#endif
