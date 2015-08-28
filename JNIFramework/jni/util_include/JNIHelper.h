/*
 * JniHelper.h
 */
#ifndef JNIHELPER_H_
#define JNIHELPER_H_
#include <jni.h>
#include <util_include/Byte.h>

#define  GetObjectGlobalRef(env, obj)      (*env)->NewGlobalRef(env, obj);
#define  ReleaseObjectGlobalRef(env, obj)  (*env)->DeleteGlobalRef(env, obj);
#define  GetObjectLocalRef(env, obj)       (*env)->NewLocalRef(env, obj);
#define  ReleaseObjectLocalRef(env, obj)   (*env)->DeleteLocalRef(env, obj);

//返回值需要释放
unsigned char * jstringToUChars(JNIEnv* env,jstring value);
jstring uCharsToJstring(JNIEnv* env,const unsigned char* value);

//返回值需要释放
unsigned char** convertJstringArray(JNIEnv* env,jobjectArray array,int* arrayLen);
unsigned char** convertJstringArrayWithItemSize(JNIEnv* env,jobjectArray array,int* itemSize);
jbyteArray byte2ByteArray(JNIEnv* env, unsigned char *data, unsigned int size);
pByte convertJstringTopByte(JNIEnv* env, jstring stringValue);
pByte* convertJstringArrayTopByteArray(JNIEnv* env, jobjectArray array, int* arrayLen);
jstring strtoJstring(JNIEnv* env, unsigned char* data);
jbyteArray pByteToJByteArray(JNIEnv* env, pByte value);
pByte jByteArrayTopByte(JNIEnv* env,jbyteArray value);
void  jByteArrayTopByteNMA(JNIEnv* env,jbyteArray value ,pByte byte);

jint  runJavaStaticMethodForBoolean(JavaVM * vm, jclass cls, jmethodID methodId, jint defaultResult);
char* runJavaStaticMethodForString(JavaVM * vm, jclass cls, jmethodID methodId);


void ThrowException(JNIEnv* env, int errorcode, char* error_desc);

#endif /* JNIHELPER_H_ */
