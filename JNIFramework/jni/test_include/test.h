/*
 *  Created on: 2014-10-29
 *      Author: Baochu,Wang
 */

#ifndef ANTIHOOK_JNI_H_
#define ANTIHOOK_JNI_H_

#include <jni.h>
#include "util_include/TBDefine.h"
#include "util_include/Byte.h"

int registerTestMethods(JNIEnv* env);
int unregisterTestMethods(JNIEnv* env);

static jboolean startTest1(JNIEnv* env, jobject thiz, jstring str1, jstring str2);
static jboolean startTest2();
static jbyteArray startTest3(JNIEnv* env, jobject thiz, jobjectArray stringData, jbyteArray byteData);

/**
 * Call to JAVA layer function.
 */
pByte runJavaFunctionTest1(TBUInt8* stringData, pByte byteData);

#endif /* ANTIHOOK_JNI_H_ */
