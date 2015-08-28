/*
 * JNIHelper.c
 */
#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <util_include/JNIHelper.h>
#include <util_include/PlatformLog.h>
#include <util_include/TBDefine.h>
#include <util_include/TBMem.h>


//返回值需要释放
unsigned char* jstringToUChars(JNIEnv* env, jstring value){
	if(value != NULL){
		const unsigned char* tmpChar = (*env)->GetStringUTFChars(env,value,0);
		if(tmpChar != NULL){
			int size = strlen(tmpChar) + 1;
			unsigned char* result = malloc(sizeof(unsigned char) * size);
			if(result){
				memset(result,0,sizeof(unsigned char) * size);
				memcpy(result,tmpChar,strlen(tmpChar));
				(*env)->ReleaseStringUTFChars(env,value,tmpChar);
			}
			return result;
		}
	}
	return NULL;
}

//返回值需要释放
unsigned char* jstringToUCharsWithItemSize(JNIEnv* env, jstring value, int* resultSize){
	if(value != NULL){
		//反射getBytes
		jclass clsstring = (*env)->FindClass(env,"java/lang/String"); //找到JString 类
		jmethodID mid = (*env)->GetMethodID(env,clsstring, "getBytes", "(Ljava/lang/String;)[B"); //得到getBytes方法
		jstring strencode = (*env)->NewStringUTF(env,"UTF-8");//编码
		if(NULL != clsstring && NULL != mid && NULL != strencode){
			jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,value, mid,strencode); //jstr 为传入的字符
			if(NULL != barr){
				jsize size = (*env)->GetArrayLength(env,barr); //得到数组长度
				jbyte* array = (*env)->GetByteArrayElements(env,barr,0);//jbyte  signed char
				if(NULL != array){
					unsigned char* result = malloc(sizeof(unsigned char) * (size + 1));
					if(result){
						memset(result,0,sizeof(unsigned char) * (size + 1));
						memcpy(result,array,size);
						(*env)-> ReleaseByteArrayElements(env, barr, array, 0);
						*resultSize = size;
						return result;
					}
				}
			}
		}
	}
	return NULL;
}

jstring uCharsToJstring(JNIEnv* env, const unsigned char* value){
    return (*env)->NewStringUTF(env, value);
}

jbyteArray uCharsToJByteArray(JNIEnv* env, const unsigned char* value){
	if(NULL != value){
		jsize size = strlen(value);
		jbyteArray byteArray = (*env)->NewByteArray(env,size);
		if(NULL != byteArray){
			(*env)->SetByteArrayRegion(env,byteArray,0,size,value);
		}
		return byteArray;
	}
	return NULL;
}

//返回值需要释放
unsigned char** convertJstringArray(JNIEnv* env,jobjectArray array,int* arrayLen){
	int size = (*env)->GetArrayLength(env,array);
	unsigned char** resultArray = malloc(sizeof(unsigned char*) * size);
	if(resultArray){
		memset(resultArray,0,sizeof(unsigned char*) * size);
		jstring item = NULL;
		int i = 0;
		for(;i < size; i++){
			item = (jstring)(*env)->GetObjectArrayElement(env,array,i);
			if(item != NULL){
				resultArray[i] = jstringToUChars(env,item);
			}else{
				//空字符串
				resultArray[i] = malloc(sizeof(unsigned char));
				if(resultArray[i]){
					memset(resultArray[i],0,sizeof(unsigned char));
				}
			}
		}
		*arrayLen = size;
	}
	return resultArray;
}

//返回值需要释放
unsigned char** convertJstringArrayWithItemSize(JNIEnv* env,jobjectArray array,int* itemSize){
	int size = (*env)->GetArrayLength(env,array);
	unsigned char** resultArray = malloc(sizeof(unsigned char*) * size);
		if(resultArray){
			memset(resultArray,0,sizeof(unsigned char*) * size);
			jstring item = NULL;
			int i = 0;
			for(;i < size; i++){
				item = (jstring)(*env)->GetObjectArrayElement(env,array,i);
				if(item != NULL){
					resultArray[i] = jstringToUCharsWithItemSize(env,item,&itemSize[i]);
				}else{
					//空字符串
					resultArray[i] = malloc(sizeof(unsigned char));
					if(resultArray[i]){
						memset(resultArray[i],0,sizeof(unsigned char));
					}
				}
			}
		}
	return resultArray;
}

jbyteArray byte2ByteArray(JNIEnv* env, unsigned char *data, unsigned int size)
{
    jbyteArray bytes = (*env)->NewByteArray(env, size);
    (*env)->SetByteArrayRegion(env, bytes, 0, size, (jbyte*)data);
    return bytes;
}

pByte convertJstringTopByte(JNIEnv* env, jstring stringValue) {
    pByte pByteData = NULL;
    unsigned char* tmpChars = jstringToUChars(env, stringValue);
    if (tmpChars != NULL) {
        int tmpCharsSize = strlen(tmpChars) + 1;
        pByteData = g_newByteSize(tmpCharsSize);
        if (pByteData != NULL) {
            pByteData->append(pByteData, tmpChars, tmpCharsSize);
        }
        //Make sure to free tmpChars.
        TBMemFree(tmpChars);
        tmpChars = NULL;
    }
    return pByteData;
}

pByte* convertJstringArrayTopByteArray(JNIEnv* env, jobjectArray array, int* arrayLen) {
    int size = (*env)->GetArrayLength(env, array);
    pByte* resultArray = malloc(sizeof(pByte) * size);
    if(NULL == resultArray)
    	return NULL;
    memset(resultArray, 0, sizeof(pByte) * size);

    jstring item = NULL;
    unsigned char* tmpChars = NULL;
    int i = 0;
    for(; i < size; i++){
        item = (jstring) (*env)->GetObjectArrayElement(env, array, i);
        if (item != NULL) {
            tmpChars = jstringToUChars(env, item);
            if (tmpChars != NULL) {
                int tmpCharsSize = strlen(tmpChars) + 1;
                pByte byteData = g_newByteSize(tmpCharsSize);
                if (byteData != NULL) {
                    byteData->append(byteData, tmpChars, tmpCharsSize);
                    resultArray[i] = byteData;
                } else {
                    resultArray[i] = NULL;
                }

                //Make sure to free tmpChars.
                TBMemFree(tmpChars);
                tmpChars = NULL;
            } else {
                resultArray[i] = NULL;
            }
        } else {
            resultArray[i] = NULL;
        }
    }

    *arrayLen = size;
    return resultArray;
}

jstring strtoJstring(JNIEnv* env, unsigned char * data)
{
    jclass strClass = (*env)->FindClass(env, "java/lang/String");
    jmethodID actorID = (*env)->GetMethodID(env, strClass, "<init>", "([BLjava/lang/String;)V");
    jbyteArray bytes = (*env)->NewByteArray(env, strlen(data));
    (*env)->SetByteArrayRegion(env, bytes, 0, strlen(data), (jbyte*)data);
    jstring encoding = (*env)->NewStringUTF(env, "utf-8");
    return (jstring)(*env)->NewObject(env, strClass, actorID, bytes, encoding);
}

jbyteArray pByteToJByteArray(JNIEnv* env, pByte value)
{
    if(value != NULL && value->array != NULL) {
        jsize size = value->length;
        if(size <= 0){
            LOGE("pByteToJByteArray[size <= 0]");
            return NULL;
        }
        jbyteArray byteArray = (*env)->NewByteArray(env, size);
        if(byteArray != NULL){
            (*env)->SetByteArrayRegion(env, byteArray, 0 /*offset*/, size /*length*/, value->array/*buffer*/);
        }

        return byteArray;

    } else {
        return NULL;
    }
}

pByte jByteArrayTopByte(JNIEnv* env, jbyteArray value)
{
	LOGI("jByteArrayTopByte begin");
	//减少分配内存次数
	if (value == NULL) {
		return NULL;
	}
	jsize size = (*env) -> GetArrayLength(env, value);
	pByte byteData = g_newByteSize(size);
	g_return_if_failed(byteData != NULL,NULL);
	jByteArrayTopByteNMA(env, value, byteData);

	LOGI("jByteArrayTopByte end");
    return byteData;
}

void jByteArrayTopByteNMA(JNIEnv* env, jbyteArray value ,pByte byte){
	g_return_if_null(env );
	g_return_if_null(value);
	g_return_if_null(byte);
	LOGI("jByteArrayTopByteNMA[begin]");

	jbyte * arrayBody = (*env)->GetByteArrayElements(env,value,0);//jbyte  signed char
	jsize   size = (*env) -> GetArrayLength(env, value);

	if(arrayBody != NULL){
		byte->append(byte,arrayBody,size);
		(*env)-> ReleaseByteArrayElements(env, value, arrayBody, 0);
	}
	LOGI("jByteArrayTopByteNMA[end]");
}

jint runJavaStaticMethodForInt(JavaVM * vm, jclass cls, jmethodID methodId, jint defaultResult){
	JNIEnv* env = NULL;
	jint result   = defaultResult;
	jint AttatedT = JNI_FALSE;

	if(!vm || !methodId || !cls){
		LOGE("runJavaStaticMethodForInt, input error!");
		return result;
	}

	if((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK){
		//LOGE("runJavaStaticMethodForInt, GetEnv Failed");
		if((*vm)->AttachCurrentThread(vm, &env, NULL) != JNI_OK){
			LOGE("runJavaStaticMethodForInt, AttachCurrentThread Failed");
			return result;
		}else{
			//LOGI("runJavaStaticMethodForInt, AttachCurrentThread");
			AttatedT = JNI_TRUE;
		}
	}

	if(env != NULL){
		result = (*env)->CallStaticIntMethod(env, cls, methodId);
	}else{
		LOGE("runJavaStaticMethodForInt, GetEnv Failed");
	}

	if(AttatedT){
		(*vm)->DetachCurrentThread(vm);
	}

	return result;
}


jint runJavaStaticMethodForBoolean(JavaVM * vm, jclass cls, jmethodID methodId, jint defaultResult){
	JNIEnv* env = NULL;
	jint result   = defaultResult;
	jint AttatedT = JNI_FALSE;

	if(!vm || !methodId || !cls){
		LOGE("runJavaStaticMethodForBoolean, input error!");
		return result;
	}

	if((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK){
		//LOGE("runJavaStaticMethodForBoolean, GetEnv Failed");
		if((*vm)->AttachCurrentThread(vm, &env, NULL) != JNI_OK){
			LOGE("runJavaStaticMethodForBoolean, AttachCurrentThread Failed");
			return result;
		}else{
			//LOGI("runJavaStaticMethodForBoolean, AttachCurrentThread");
			AttatedT = JNI_TRUE;
		}
	}

	if(env != NULL){
		result = (*env)->CallStaticBooleanMethod(env, cls, methodId);
	}else{
		LOGE("runJavaStaticMethodForBoolean, GetEnv Failed");
	}

	if(AttatedT){
		(*vm)->DetachCurrentThread(vm);
	}

	return result;
}

char* runJavaStaticMethodForString(JavaVM * vm, jclass cls, jmethodID methodId){
	//LOGI("runJavaStaticMethodForString vm=%d cls=%d methodId=%d", (int)vm, (int)cls, (int)methodId);
	JNIEnv* env = NULL;
	jint AttatedT = JNI_FALSE;
	char * result = NULL;
	if(!vm || !cls || !methodId){
		//LOGE("runJavaStaticMethodForString, input error!");
		return NULL;
	}

	if((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_4) != JNI_OK){
		//LOGE("runJavaStaticMethodForString, GetEnv Failed");
		if((*vm)->AttachCurrentThread(vm, &env, NULL) != JNI_OK){
			//LOGE("runJavaStaticMethodForString, AttachCurrentThread Failed");
			return NULL;
		}else{
			//LOGI("runJavaStaticMethodForString, AttachCurrentThread");
			AttatedT = JNI_TRUE;
		}
	}
	if(env != NULL){
		jstring jstrResult = (jstring)(*env)->CallStaticObjectMethod(env, cls, methodId);
		if(jstrResult != NULL){
			result = (char*)jstringToUChars(env, jstrResult);
			(*env)->DeleteLocalRef(env, jstrResult);
		}
	}else{
		LOGE("runJavaStaticMethodForString, GetEnv Failed");
	}

	if(AttatedT){
		(*vm)->DetachCurrentThread(vm);
	}

	return result;
}

void ThrowException(JNIEnv* env, int errorcode, char* error_desc)
{
	jclass exceptionClass = (*env)->FindClass(env, "com/alibaba/wireless/security/open/SecException");
	jmethodID constructor = (*env)->GetMethodID(env, exceptionClass, "<init>", "(Ljava/lang/String;I)V");
	if(constructor == 0){
		LOGE("find contructor of com/alibaba/wireless/security/open/SecException failed");
		return;
	}

	jstring desc =	(*env)->NewStringUTF(env, error_desc);
	jobject obj = (*env)->NewObject(env, exceptionClass, constructor, desc, errorcode);

	(*env)->Throw(env, obj);
}
