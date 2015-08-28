#ifndef __TB_DEF__
#define __TB_DEF__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
    #define C_BEGIN_DECLS extern "C"{
    #define C_END_DECLS  }
#else
    #define C_BEGIN_DECLS
    #define C_END_DECLS
#endif

#define TBBOOL_TRUE  1
#define TBBOOL_FALSE 0

typedef void					TBVoid;
typedef long					TBLong;
typedef unsigned long			TBULong;
typedef unsigned short			TBUShort;
typedef short					TBShort;
typedef char					TBChar;
typedef unsigned char			TBByte;
typedef long					TBBool;
typedef float					TBFloat;
typedef double					TBDouble;
typedef unsigned short			TBWord;
typedef unsigned long			TBDWord;
typedef void*					TBHandle;
typedef	TBLong					TBRESULT;
typedef TBDWord					TBRgb;
typedef long long				TBLongLong;
typedef	signed	 char			TBInt8;
typedef	unsigned char			TBUInt8;


typedef	int16_t			 TBInt16;
typedef	uint16_t	     TBUInt16;

typedef	int32_t	         TBInt32;
typedef	uint32_t	     TBUInt32;

typedef	int64_t	         TBInt64;
typedef	uint64_t	     TBUInt64;


typedef int						TBInt;
typedef unsigned int			TBUInt;

//#######################################################################
#define g_return_value_if_null(x,value)    \
if(NULL == (x)){                           \
    return (value);                        \
}

#define g_return_negvalue_if_null(x)   g_return_value_if_null((x),-1)

#define g_return_if_null(x)           \
if(NULL == (x)){                      \
    return;                           \
}

#define g_return_if_null_Error(x , srcP,code , extra , preve)   \
if(NULL == (x)){                                                \
    ERROR_CODE_SET(srcP,code, extra , preve);                   \
    COPY_ERROR_DATA_VAR(srcP);                                  \
    return;                                                     \
}


#define g_return_if_failed(logic,ret)         \
if( !(logic)){                                \
          return (ret);                       \
}

#define g_return_if_failed_Error(logic,ret ,srcP,code, extra , preve)        \
if( !(logic)){                                                         \
        ERROR_CODE_SET(srcP,code, extra , preve);                      \
        COPY_ERROR_DATA_VAR(srcP);                                     \
        return (ret);                                                  \
}


#define g_return_if_failed_NoValue(logic)               \
if( !(logic)){                                          \
          return ;                                      \
}


#define g_return_if_failed_NoValue_Error(logic ,srcP,code, extra , preve)  \
if( !(logic)){                                                          \
        ERROR_CODE_SET(srcP,code, extra , preve);                      \
        COPY_ERROR_DATA_VAR(srcP);                                     \
        return ;                                      \
}

#endif //__TB_DEF__
