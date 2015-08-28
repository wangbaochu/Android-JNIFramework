/*
 * JNIGlobalInit.c
 *
 *  Created on: 2014-4-15
 *      Author: Baochu,Wang
 */
#include <stddef.h>
#include <jni.h>
#include <util_include/PlatformLog.h>
#include "test.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	jint result = JNI_ERR;
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK || env == NULL) {
		LOGE("GetEnv Failed");
		return result;
	}

	//注册函数
	if (registerTestMethods(env) < 0) {
		LOGE("registerTestMethods Failed");
		return result;
	}

	result = JNI_VERSION_1_4;
    return result;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
	JNIEnv* env = NULL;
	if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		return;
	}

	//注销函数
	if (unregisterTestMethods(env) < 0) {
		LOGE("unregisterTestMethods Failed");
	}
}

