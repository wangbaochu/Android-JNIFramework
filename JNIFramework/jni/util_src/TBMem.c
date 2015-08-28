
#include <util_include/TBMem.h>

C_BEGIN_DECLS

TBVoid * Sec_malloc(TBUInt numB){
	if(numB <= 0){
		return NULL;
	}

	return malloc(numB);

}


TBVoid Sec_free(TBVoid * ptr){
	if(ptr == NULL){
		return;
	}

	free(ptr);
}


TBVoid  * Sec_realloc(TBVoid * adr , TBUInt newSize){
	if(adr == NULL){
		return NULL;
	}

	if(newSize <= 0){
		return adr;
	}

	return realloc(adr, newSize);
}

TBVoid * Sec_memset(TBVoid * src , TBInt c , TBUInt size){
	if(src == NULL){
		return src;
	}
	if(size <= 0){
		return src;
	}
	return memset(src, c, size);
}



TBVoid * Sec_memcpy(TBVoid * des , const TBVoid*  src , TBUInt size){
	if(src == NULL || des == NULL){
		return NULL;
	}
	if(size <= 0){
		return des;
	}
	return memcpy(des, src, size);
}


TBVoid * Sec_memmove(TBVoid * des , const TBVoid*  src , TBUInt size){
	if(src == NULL || des == NULL){
		return NULL;
	}
	if(size <= 0){
		return des;
	}
	return memmove(des, src, size);
}


TBInt Sec_memcmp(const TBVoid * c1 , const TBVoid*  c2 , TBUInt size){
	if(c1 == NULL || c2 == NULL){
		return -1;
	}
	if(size <= 0){
		return -1;
	}
	return memcmp(c1, c2, size);
}



C_END_DECLS








