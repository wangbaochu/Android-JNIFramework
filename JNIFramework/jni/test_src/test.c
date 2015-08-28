/*
 *  Created on: 2014-10-29
 */

#include <unistd.h>
#include <jni.h>
#include "util_include/JNIHelper.h"
#include "util_include/PlatformLog.h"
#include "util_include/TBErrorCode.h"
#include "test.h"

#define NELEMLen(x) ( (int) ( sizeof(x) / sizeof( (x)[0]) ) )

/* Class name in JAVA layer */
TBUInt8 gClassName[80] = {
        'c','o','m','/',
        'o','p','e','n','/',
        'j','n','i','f','r','a','m','e','w','o','r','k','/',
        'J','N','I','T','e','s','t',0};
JavaVM* globalJavaVM = NULL;
jclass globalJavaClass = NULL;

/** Release the global reference object */
void releaseGlobalReference(JNIEnv* env) {
    if (globalJavaVM != NULL) {
        (*env)->DeleteGlobalRef(env, globalJavaVM);
        globalJavaVM = NULL;
    }

    if (globalJavaClass != NULL) {
        (*env)->DeleteGlobalRef(env, globalJavaClass);
        globalJavaClass = NULL;
    }
}

/**
 * Called by JNI_OnLoad to register the java-native method.
 */
int registerTestMethods(JNIEnv* env) {
	TBUInt8 javaTest1Func[64] = {'J','N','I','T','e','s','t','1',0};
	TBUInt8 javaTest2Func[64] = {'J','N','I','T','e','s','t','2',0};
	TBUInt8 javaTest3Func[64] = {'J','N','I','T','e','s','t','3',0};

	JNINativeMethod methods[] = {
			{javaTest1Func,  "(Ljava/lang/String;Ljava/lang/String;)Z", (TBVoid*)startTest1},
			{javaTest2Func,  "()Z",                                     (TBVoid*)startTest2},
			{javaTest3Func,  "([Ljava/lang/String;[B)[B",               (TBVoid*)startTest3}
	};

	jclass clazz = (*env)->FindClass(env, gClassName);
	if(clazz == NULL){
		LOGE("registerTestMethods [CLASS NOT FOUND]");
		return JNI_ERR;
	}

	if((*env)->RegisterNatives(env, clazz, methods, NELEMLen(methods)) < 0) {
		LOGE("registerTestMethods [RegisterNatives < 0]");
		return JNI_ERR;
	}
	LOGI("registerTestMethods [Success]");

	(*env)->GetJavaVM(env, &globalJavaVM);
    globalJavaClass = (jclass) (*env)->NewGlobalRef(env, clazz);
    (*env)->DeleteLocalRef(env,clazz);

	return JNI_OK;
}

/**
 * Called by JNI_OnLoad to unregister the java-native method.
 */
int unregisterTestMethods(JNIEnv* env){
    int result = JNI_OK;
    jclass clazz = (*env)->FindClass(env, gClassName);
    if (clazz == NULL){
        LOGE("unregisterTestMethods [clazz == NULL]");
        result = JNI_ERR;
    } else {
        if((*env)->UnregisterNatives(env, clazz) < 0){
            LOGE("unregisterTestMethods [clazz == NULL]");
            result = JNI_ERR;
        }
    }

    if (result == JNI_OK) {
	    LOGE("unregisterTestMethods [success]");
    }

    releaseGlobalReference(env);
	return result;
}

/**
 * Call to JAVA layer function: JNITest#javaFunctionTest1().
 */
pByte runJavaFunctionTest1(TBUInt8* stringData, pByte byteData)
{
    if (globalJavaVM != NULL && globalJavaClass != NULL) {
        JNIEnv *env = NULL;
        jint AttatedT = JNI_FALSE;

        //1.Attache current thread and obtain the JNIEnv
        if ((*globalJavaVM)->GetEnv(globalJavaVM, (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
            LOGE("runJavaFunctionTest1, GetEnv Failed");
            if ((*globalJavaVM)->AttachCurrentThread(globalJavaVM, &env, NULL) != JNI_OK) {
                LOGE("runJavaFunctionTest1: AttachCurrentThread() failed.");
                return NULL;
            } else {
                LOGI("runJavaFunctionTest1, AttachCurrentThread");
                AttatedT = JNI_TRUE;
            }
        }

        //2.Obtain jmethodID
        jmethodID methodID = (*env)->GetStaticMethodID(env, globalJavaClass, "javaFunctionTest1", "(Ljava/lang/String;[B)[B");
        if (methodID == NULL || (*env)->ExceptionCheck(env)) {
            (*env)->ExceptionClear(env);
            LOGE("runJavaFunctionTest1: GetStaticMethodID() failed");

            if (AttatedT) {
                (*globalJavaVM)->DetachCurrentThread(globalJavaVM);
            }
            return NULL;
        }

        //3.Call the JAVA method.
        jstring jStringData = (*env)->NewStringUTF(env, stringData);
        jbyteArray dataJavaArray = (*env)->NewByteArray(env, byteData->length);
        if (dataJavaArray != NULL){
            (*env)->SetByteArrayRegion(env, dataJavaArray ,0, byteData->length, byteData->array);
        }

        pByte javaResult = NULL;
        jbyteArray response = (*env)->CallStaticObjectMethod(env, globalJavaClass, methodID, jStringData, dataJavaArray);
        if(response != NULL){
            javaResult = jByteArrayTopByte(env, response);
            (*env)->DeleteLocalRef(env, response);
            response = NULL;
        }
        if( javaResult != NULL && javaResult->length == 0){
            g_freeByte(javaResult);
            javaResult = NULL;
        }

        //4.Release local reference objects
        if (jStringData != NULL) {
            (*env)->DeleteLocalRef(env, jStringData);
            jStringData = NULL;
        }
        if(dataJavaArray != NULL){
            (*env)->DeleteLocalRef(env, dataJavaArray);
            dataJavaArray = NULL;
        }

        //6.Detach current thread
        if(AttatedT){
            (*globalJavaVM)->DetachCurrentThread(globalJavaVM);
        }

        return javaResult;
    }

    return NULL;
}

//#################################################################
//########### The mapping of JNINativeMethod ######################
//#################################################################
static jboolean startTest1(JNIEnv* env, jobject thiz, jstring str1, jstring str2)
{
    TBUInt8* str1Name = NULL;
    TBUInt8* str2Name = NULL;
    jboolean result = TBBOOL_FALSE;

    str1Name = jstringToUChars(env, str1);
    if (str1Name == NULL) {
        LOGI("startTest1 str1 = null");
        goto FAILED;
    } else {
        LOGI("startTest1 str1 = %s", str1Name);
    }

    str2Name = jstringToUChars(env, str2);
    if (str2Name == NULL) {
        LOGI("startTest1 str2 = null");
        goto FAILED;
    } else {
        result = TBBOOL_TRUE;
        LOGI("startTest1 str2 = %s", str2Name);
    }

FAILED:
    free(str1Name);
    free(str2Name);
    return result;
}

static jboolean startTest2()
{
    LOGI("startTest2...");

    //Call back to java function
    TBUInt8* str = "C layer call native startTest2() success!";
    TBUInt8* helloStr = "hello world";
    pByte byteData = g_newByteSize(64);
    if (byteData != NULL) {
        byteData->append(byteData, helloStr, strlen(helloStr));
    } else {
        return TBBOOL_FALSE;
    }

    pByte result = runJavaFunctionTest1(str, byteData);
    if (result != NULL) {
        if (result->array != NULL) {
            LOGI("runJavaFunctionTest1 return = %s", result->array);
        }
        g_freeByte(result);
    }

    g_freeByte(byteData);
    return TBBOOL_TRUE;
}

static jbyteArray startTest3(JNIEnv* env, jobject thiz, jobjectArray stringData, jbyteArray byteData) {
    int arrayLen = 0;
    TBUInt8** strDataArray = convertJstringArray(env, stringData, &arrayLen);
    if (strDataArray != NULL) {
        if (arrayLen > 0) {
            int i = 0;
            for(; i < arrayLen; i++){
                LOGI("strDataArray[%d] = %s", i, strDataArray[i]);
                free(strDataArray[i]);
            }
        }
        //Remember to free
        free(strDataArray);
    }

    pByte pByteData = jByteArrayTopByte(env, byteData);
    if (pByteData != NULL){
        LOGI("jbyteArray == %s", pByteData->array);
        g_freeByte(pByteData);
    }

    char* result = "Call native startTest3() success!";
    return (jbyteArray)uCharsToJByteArray(env, result);
}


