#ifndef __BYTE_H__
#define __BYTE_H__

#include "TBDefine.h"

C_BEGIN_DECLS

#define  DEFAULT_SIZE  100

typedef  struct _Byte   ByteArray ,*pByte;

struct _Byte{
	TBUInt8 * array;
	TBInt length;
	TBInt size;

	TBVoid (*append)(pByte  byte,const TBUInt8 * buffer,TBInt length);
	TBVoid (*appendUInt8)(pByte byte,const TBUInt8  data);

	TBInt (*increase)(pByte  byte,TBInt length);
	TBUInt8  (*findIndex)(pByte byte,TBInt pos,TBInt * err);
	TBInt (*findPostion)(pByte byte,TBInt off ,TBUInt8 data);

	TBInt (*clearData)(pByte byte);

	TBUInt8*  (*convertToUChar)(pByte byte);

	pByte  (*cloneSelf)(pByte byte);

	TBVoid (*setPosData)(pByte byte,TBInt pos,const TBUInt8  data);
	TBVoid (*appendByte)(pByte thiz,const pByte src);

	TBVoid (*ReplaceUChar)(pByte thiz,TBUInt8 srcData,TBUInt8 data);
	TBVoid (*TruncByteData)(pByte thiz,TBInt off , TBInt len);

};

extern pByte g_newByte();
extern pByte g_newByteSize(TBInt bufferSize);

extern TBVoid g_freeByte(pByte  byte);
extern TBVoid g_freeByteArray(pByte byte);

static TBVoid append(pByte byte,const TBUInt8 * buffer,TBInt length);

static TBVoid appendUInt8(pByte byte,const TBUInt8  data);

static TBInt increase(pByte byte,TBInt length);

static TBUInt8  findIndex(pByte byte,TBInt pos ,TBInt * err);

static TBInt findPostion(pByte byte,TBInt off ,TBUInt8 data);

static TBInt clearData(pByte byte);

static TBUInt8*  convertToUChar(pByte byte);

static pByte  cloneSelf(pByte byte);

static TBVoid setPosData(pByte byte,TBInt pos,const TBUInt8  data);

static TBVoid appendByte(pByte thiz,const pByte src);

static TBVoid ReplaceUChar(pByte thiz,TBUInt8 srcData,TBUInt8 data);

static TBVoid TruncByteData(pByte thiz,TBInt off , TBInt len);

extern TBVoid SubByteArray(pByte thiz , pByte  buf ,TBInt begin , TBInt end);

extern TBVoid SubByteArrayTBUInt8(pByte thiz , TBUInt8*  buf ,TBInt begin , TBInt end);


#define  CHECK_PBYTE_OVERFLOW(pByteTemp,numTemp,errInfo)  do{   \
		if(pByteTemp->length + numTemp > pByteTemp->size){                \
			ERROR_CODE_SET(errInfo,EC_Buffer_Notenough  , pByteTemp->length + numTemp ,pByteTemp->size);       \
			COPY_ERROR_DATA_VAR(errInfo);                                                                    \
		}                                                                                                    \
}while(0)


#define  GetpByteRemainingBuffer(pByteTemp)  (pByteTemp->array + pByteTemp-> length)
#define  GetpByteRemainingLength(pByteTemp)  (pByteTemp->size - pByteTemp-> length)


#define  GetpByteBuffer(pByteTemp)  (pByteTemp->array)

#define  GetpByteLength(pByteTemp)  (pByteTemp->length)

#define  GetpByteSize(pByteTemp)    (pByteTemp->size)


#define  SetpByteLength(pByteTemp , lengthTemp)    (pByteTemp->length = lengthTemp)

#define  IncpByteLength(pByteTemp , lengthTemp)    (pByteTemp->length += lengthTemp)

C_END_DECLS

#endif
