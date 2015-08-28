
#include <util_include/Byte.h>
#include <util_include/PlatformLog.h>
#include <util_include/TBErrorCode.h>
#include <util_include/TBMem.h>

pByte g_newByte(){
	//LOGI("g_newByte","enter enter enter!");
	ByteArray* byte = (ByteArray *)TBMemAlloc(sizeof(ByteArray));
	g_return_if_failed(NULL != byte,NULL);

	byte ->size = DEFAULT_SIZE;

	byte->array = NULL;

	byte->array = (TBUInt8 *)TBMemAlloc(sizeof(TBUInt8) * DEFAULT_SIZE);
	//g_return_if_failed(NULL != byte->array,byte);
	if(byte->array == NULL){
	    TBMemFree(byte);
	    return NULL;
	}

	byte->length = 0;
	//LOGI("g_newByte","memory allocate success!");
	/*��ʼ��*/
	byte->append = append;
	byte->increase = increase;
	byte->findIndex = findIndex;
	byte->findPostion = findPostion;

	byte->clearData = clearData;
	byte->convertToUChar = convertToUChar;
	byte->cloneSelf = cloneSelf;
	byte->appendUInt8 = appendUInt8;
	byte->setPosData = setPosData;
	byte->appendByte = appendByte;
	byte->ReplaceUChar = ReplaceUChar;
	byte->TruncByteData = TruncByteData;

	//LOGIFORMAT("g_newByte","byte->append:{%p},appendt: {%p}\n",byte->append,append);
	return byte;
}
/**
 * ָ����С��ʼ�����캯��
 */
pByte g_newByteSize(TBInt bufferSize){
	//LOGI("g_newByte-bufferSize","enter enter enter!");
	ByteArray* byte = (ByteArray *)TBMemAlloc(sizeof(ByteArray));
	g_return_if_failed(NULL != byte,NULL);

	byte ->size = bufferSize;
	byte->array = NULL;
	byte->array = (TBUInt8 *)TBMemAlloc(sizeof(TBUInt8) * bufferSize);
	//g_return_if_failed(NULL != byte->array,byte);
	if(byte->array == NULL){
	    TBMemFree(byte);
	    return NULL;
	}

	byte->length = 0;
	//LOGI("g_newByte-bufferSize","memory allocate success!");
	/*��ʼ��*/
	byte->append = append;
	byte->increase = increase;
	byte->findIndex = findIndex;
	byte->findPostion = findPostion;

	byte->clearData = clearData;
	byte->convertToUChar = convertToUChar;
	byte->cloneSelf = cloneSelf;

	byte->appendUInt8 = appendUInt8;
	byte->setPosData = setPosData;
	byte->appendByte = appendByte;
	byte->ReplaceUChar = ReplaceUChar;
	byte->TruncByteData = TruncByteData;

	//LOGIFORMAT("g_newByte-bufferSize","byte->append:{%p},appendt: {%p}\n",byte->append,append);
	return byte;
}

TBVoid g_freeByte(pByte  byte){
	g_return_if_null(byte);
	if(NULL != byte->array){
		TBMemFree(byte->array);
		byte->array = NULL;
		//LOGI("g_freeByte","g_freeByte[child]");
	}
    TBMemFree(byte);
    byte = NULL;
    //LOGI("g_freeByte","g_freeByte!");
}


TBVoid g_freeByteArray(pByte byte)
{
	g_return_if_null(byte);
    TBUInt32 index = 0;
    TBUInt32 arraySize = byte -> length / sizeof(pByte);
    for ( ;  index < arraySize; ++index) {
        pByte subString = ((pByte*)(byte -> array))[index];
        g_freeByte(subString);
        subString = NULL;
    }
    
    g_freeByte(byte);
    byte = NULL;
}

static TBVoid append(pByte byte,const TBUInt8 * buffer,TBInt length){
	TBInt i = 0;

	g_return_if_null(byte);
	g_return_if_null(buffer);
	g_return_if_failed_NoValue( length > 0);

	if(byte->length+length > byte->size -1) {
	    TBInt ret = increase(byte,length);
	    if (ret < 0) {
	        return;
	    }
	}

	for(i = 0; i < length;i ++){
		byte->array[byte->length + i] = buffer[i];
	}
	byte->length += length;
}

static TBInt increase(pByte byte,TBInt length){
	TBInt size =0 ;
	//LOGE("-----append[increase]-----","-----append[increase][begin]-----");
	g_return_negvalue_if_null(byte);
	if(NULL == byte->array){
		size = length > DEFAULT_SIZE?length:DEFAULT_SIZE;
		byte->array = (TBUInt8 *)TBMemAlloc(sizeof(TBUInt8) * size);
		g_return_negvalue_if_null(byte->array);
		byte ->length = 0;
		byte->size = size;
		return 0;
	}
	TBUInt8 * newBuffer = (TBUInt8 *)TBMemRealloc(byte->array,sizeof(TBUInt8)*(byte->size + length + DEFAULT_SIZE));
    g_return_if_failed(NULL != newBuffer,-1);
    byte->array = newBuffer;
    memset(byte -> array + byte -> size, 0, length + DEFAULT_SIZE);
    byte ->size = byte->size + length + DEFAULT_SIZE;
    //LOGE("-----append[increase]-----","-----append[increase][end]-----");
    return 0;
}

static TBUInt8  findIndex(pByte byte,TBInt pos ,TBInt * err){
	if(byte == NULL || pos >= byte->length || pos < 0){
		if(err){
			*err = ECINVALIDP;
		}
		return -1;//�з���:�Զ��������,-1���ܱ�ʾ����:�ÿ��Թ�עerr����������
	}
	return  byte->array[pos];
}
//�� off ��ʼ����
static TBInt findPostion(pByte byte,TBInt off , TBUInt8 data){
	TBInt i = 0;
	g_return_negvalue_if_null(byte);
	g_return_if_failed( off < byte->length , -1);
	g_return_if_failed( off >= 0 , -1);

    for(i = off ; i < byte->length ; i ++){
       if(byte->array[i] == data){
    	   return i ;//��������
       }
    }
    return -1;
}

static TBInt clearData(pByte byte){
	g_return_negvalue_if_null(byte);
	g_return_if_failed(NULL != byte->array,-1);

	/*���ͷ��ڴ�*/
	TBMemSet(byte->array,0,byte->size);
	byte->length = 0;
	return 0;
}

TBUInt8*  convertToUChar(pByte byte){
	TBUInt8*  data = NULL;
	int i = 0;
	g_return_value_if_null(byte,NULL);

	data = (TBUInt8 *)TBMemAlloc(sizeof(TBUInt8) * (byte->length + 1));
	g_return_value_if_null(data,NULL);

	data[byte->length] = 0;

	for(i = 0;i < byte->length ; i++){
		data[i] =  byte ->array[i];
	}

	return data;
}

pByte  cloneSelf(pByte byte){
	g_return_value_if_null(byte,NULL);

	pByte  clone = g_newByteSize(byte -> length + 1);
	g_return_value_if_null(clone,NULL);

	clone ->append(clone,byte -> array,byte -> length);

	return clone;
}

TBVoid appendUInt8(pByte byte,const TBUInt8  data){

	append(byte, &data,1);
}


TBVoid setPosData(pByte byte,TBInt pos,const TBUInt8  data){
	g_return_if_null(byte);
	g_return_if_failed_NoValue((pos >= 0 && pos < byte->length));

	byte -> array[pos] = data;
}

TBVoid appendByte(pByte thiz,const pByte src){

	g_return_if_null(thiz);
	g_return_if_null(src);
	g_return_if_null(src -> array);

	append(thiz,src -> array,src -> length );

}

TBVoid ReplaceUChar(pByte thiz,TBUInt8 srcData ,TBUInt8 data){
	g_return_if_null(thiz);
	g_return_if_null(thiz -> array);
	TBInt  i = 0;
	for(i = 0; i < thiz -> length ; i ++){
		if(thiz -> array[i] == srcData){//'&'
			thiz -> array[i] = data;
		}
	}

}

TBVoid TruncByteData(pByte thiz,TBInt off , TBInt len){
	g_return_if_null(thiz);
	g_return_if_failed_NoValue(off >=0 && off < thiz ->length);
	g_return_if_failed_NoValue(off + len <= thiz ->length);
	memmove(thiz ->array + off,thiz ->array + off + len , thiz ->length - (off + len) );
	thiz ->length = thiz ->length - len; //����Len
}
/**
 * end is excluded
 */
TBVoid SubByteArray(pByte thiz , pByte  buf ,TBInt begin , TBInt end){

	g_return_if_null(thiz);
	g_return_if_null(buf);

	g_return_if_failed_NoValue( ( (begin >= 0) && (end <= thiz -> length) ) );

	buf -> append(buf ,thiz -> array + begin , end - begin );
}
/**
 * end is excluded
 */
TBVoid SubByteArrayTBUInt8(pByte thiz , TBUInt8 *  buf ,TBInt begin , TBInt end){

	g_return_if_null(thiz);
	g_return_if_null(buf);

	g_return_if_failed_NoValue( ( (begin >= 0) && (end <= thiz -> length) ) );

	memcpy( buf ,thiz -> array + begin ,  end - begin );
}

