#ifndef __TB_MEM__
#define __TB_MEM__

#include <util_include/TBDefine.h>

#ifdef __cplusplus
extern "C" {
#endif

#define   SECURITY_MEM_FUNC  0


#if  !(SECURITY_MEM_FUNC)


#define TBMemAlloc(size)	\
({	\
    void* buf = malloc(size); \
    if (buf) { \
        memset(buf, 0, size); \
    } \
    buf; \
})


#define TBMemFree       free

#define TBMemRealloc	realloc

#define TBMemSet		memset

#define TBMemCpy		memcpy

#define TBMemMov		memmove

#define TBMemCmp		memcmp



#else



#define TBMemAlloc    Sec_malloc

#define TBMemFree    Sec_free

#define TBMemRealloc  Sec_realloc

#define TBMemSet      Sec_memset

#define TBMemCpy      Sec_memcpy

#define TBMemMov      Sec_memmove

#define TBMemCmp      Sec_memcmp



#endif



#ifdef __cplusplus
}
#endif


#endif //__TB_MEM__
