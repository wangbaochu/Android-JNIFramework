#ifndef  __TBERRORCODE_H__
#define  __TBERRORCODE_H__

#include <util_include/TBDefine.h>

#define ECOK							    0

#define EUNKNOWN					        -1

#define ECERROR                         EUNKNOWN
#define ECBase						    ECERROR

#define ECINVALIDP				        (ECBase-1)
#define ECUNSUPPORT				        (ECBase-2)
#define ECNOMEM          				(ECBase-3)
#define ECBADSTATE					    (ECBase-4)
#define ECEXPIRED					    (ECBase-5)
#define ECNOTREADY					    (ECBase-6)
#define ECNOSPACE					    (ECBase-7)
#define ECFNOEXIST					    (ECBase-8)
#define ECTIMEOUT					    (ECBase-9)
#define ECALREADYE					    (ECBase-10)
#define ECNOPERM					    (ECBase-11)
#define ECIO						    (ECBase-12)
#define ECOPENFAIL					    (ECBase-13)
#define ECREADFAIL				        (ECBase-14)
#define ECWRITEFAIL				        (ECBase-15)
#define ECSEEKFAIL				        (ECBase-16)

#define ECORIGINAL_PUBKEY_NULL			(ECBase-17)
#define ECSTATIC_PUBKEY_NULL			(ECBase-18)
#define ECPUBKEY_NOT_EQUAL			    (ECBase-19)
#define ECPUBKEY_CONVERT_FAIL			(ECBase-20)

#define EC_Zip_Archive_Open_Failed               (ECBase-21)  //-22

#define EC_Zip_Archive_Index_FileName_Null       (ECBase-22)  //-23

#define EC_Zip_Archive_File_RSA_Open_Failed      (ECBase-23)  //-24

#define EC_Zip_Archive_File_Data_Open_Failed     (ECBase-24)  //-25

#define EC_Package_Name_Null                     (ECBase-25)  //-26

#define EC_Byte_To_Uint8_Error                   (ECBase-26)  //-27

#define EC_RsAData_Null                   (ECBase-27)  //-28

#define EC_Get_Cert_Data_Null             (ECBase-28)  //-29

#define EC_Get_PubKey_Data_Null           (ECBase-29)

#define EC_Get_Method_ID_Null             (ECBase-30)

#define EC_Get_Object_Class_Null          (ECBase-31)

#define EC_JString_To_UInt8_Failed        (ECBase-32)

#define EC_Byte_To_Hex_Failed             (ECBase-33)

#define EC_JByteArray_To_Byte_Failed      (ECBase-40)

#define EC_Byte_To_JByteArray_Failed      (ECBase-41)

#define EC_UInt8_To_JByteArray_Failed     (ECBase-42)

#define EC_UInt8_To_JString_Failed        (ECBase-43)

#define EC_Base_64_Encode_Failed          (ECBase-44)

#define EC_Base_64_Decode_Failed          (ECBase-45)

#define EC_Get_PubKey_Data_Null_Test      (ECBase-46)

#define EC_Being_Debug                    (ECBase-47)

#define EC_Parse_Pubkey_Func_Null         (ECBase-48)

#define EC_Confuse_Ret_NE                 (ECBase-49)

#define EC_Zip_Stat_Exp                   (ECBase-50)

#define EC_Sys_Stat_Err                   (ECBase-51)

#define EC_File_NO_R_P                    (ECBase-52)

#define EC_File_NO_W_P                    (ECBase-53)

#define EC_File_NO_X_P                    (ECBase-54)

#define EC_File_Dup_Err                   (ECBase-55)

#define EC_File_Zip_No_Entry              (ECBase-56)

#define EC_Buffer_Notenough               (ECBase-57)

#define EC_Data_Type_Match_Err            (ECBase-58)

#define EC_Assert_M_FJava_Err             (ECBase-59)

#define EC_Assert_File_Notfind_Err        (ECBase-60)

#define EC_MD5_Digest_Failed              (ECBase-61)

#define EC_SHA1_Digest_Failed              (ECBase-62)

//zip补充
#define EC_Zip_Archive_GlobalInfo_Get_Failed	 (ECBase-63)

#define EC_Zip_Archive_Entry_File_Info_Get_Failed	 (ECBase-64)

#define EC_Zip_Archive_Entry_File_Open_Failed	 (ECBase-65)

#define EC_Zip_Archive_Entry_File_Read_Failed	 (ECBase-66)

#define EC_Zip_Archive_Locate_File_Failed	(ECBase-67)

#define EC_Zip_Archive_Entry_File_Set_Offset_Failed (ECBase - 68)

#define EC_Zip_Archive_Entry_File_Goto_Failed (ECBase - 69)

#define EC_PUBLIC_MAX                  EC_STATIC_BASE


#define EC_STATIC_BASE                                -100

#define EC_STATIC_Read_Data_Ret_Null                  (EC_STATIC_BASE - 1)

#define EC_STATIC_Map_Buf_Serialize_None_Data         (EC_STATIC_BASE - 2)

#define EC_STATIC_Get_Data_Dir_Error                  (EC_STATIC_BASE - 3)

#define EC_STATIC_Have_No_Value_ForKey                (EC_STATIC_BASE - 4)

#define EC_STATIC_Have_Base64_Ret_Null                (EC_STATIC_BASE - 5)

#define EC_STATIC_Ext_PublicKet_Null                  (EC_STATIC_BASE - 6)

#define EC_STATIC_Gen_Key_Null                        (EC_STATIC_BASE - 7)

#define EC_STATIC_Aes_Decrypt_Failed                  (EC_STATIC_BASE - 9)


#define EC_STATIC_Extra_Data_No_Key                   (EC_STATIC_BASE - 10)

#define EC_STATIC_Get_Value_Null                      (EC_STATIC_BASE - 11)

#define EC_STATIC_Get_Secret_By_Extra                 (EC_STATIC_BASE - 12)

#define EC_STATIC_File_Format_Error                   (EC_STATIC_BASE - 13)

#define EC_STATIC_Have_No_NonSensitive                (EC_STATIC_BASE - 14)

#define EC_STATIC_Have_No_Sensitive                   (EC_STATIC_BASE - 15)

#define EC_STATIC_Sensitive_Parser_NoInit             (EC_STATIC_BASE - 16)

#define EC_STATIC_Blowfish_Decryp_Fialed              (EC_STATIC_BASE - 17)

#define EC_STATIC_GET_GLOBAL_APK_Failed               (EC_STATIC_BASE - 18)

#define EC_STATIC_COMPARE_PUBKEY__Failed              (EC_STATIC_BASE - 19)

#define EC_STATIC_MAX                    EC_DYNAMIC_BASE
//////////////////////////////////////////////////////////////////////////


#define EC_DYNAMIC_BASE                  -200

#define EC_DYNAMIC_TInt_To_Str_Failed                  (EC_DYNAMIC_BASE - 1)

#define EC_DYNAMIC_Float_To_Str_Failed                 (EC_DYNAMIC_BASE - 2)

#define EC_DYNAMIC_Long_To_Str_Failed                  (EC_DYNAMIC_BASE - 3)

#define EC_DYNAMIC_Get_No_Key                          (EC_DYNAMIC_BASE - 4)

#define EC_DYNAMIC_Get_Data_Failed                     (EC_DYNAMIC_BASE - 5)

#define EC_DYNAMIC_Get_Data_No_Data                    (EC_DYNAMIC_BASE - 6)

#define EC_DYNAMIC_Get_Bool_Data_Illegal               (EC_DYNAMIC_BASE - 7)

#define EC_DYNAMIC_Decode_Data_Failed                  (EC_DYNAMIC_BASE - 8)

#define EC_DYNAMIC_And_DataType_ToKey_Failed           (EC_DYNAMIC_BASE - 9)

#define EC_DYNAMIC_Get_Imsi_Imei_Failed                (EC_DYNAMIC_BASE - 10)

#define EC_DYNAMIC_Get_Java_Str_Data_Failed            (EC_DYNAMIC_BASE - 11)

#define EC_DYNAMIC_May_Not_Store_Key                   (EC_DYNAMIC_BASE - 12)

#define EC_DYNAMIC_Get_Aes_Key_Failed                  (EC_DYNAMIC_BASE - 13)

#define EC_DYNAMIC_Imei_Imsi_Obsure_Failed             (EC_DYNAMIC_BASE - 14)

#define EC_DYNAMIC_Null_PubKey                         (EC_DYNAMIC_BASE - 15)

#define EC_DYNAMIC_Secret_Process_Null                 (EC_DYNAMIC_BASE - 16)

#define EC_DYNAMIC_Aes_Encrypt_Failed                  (EC_DYNAMIC_BASE - 17)

#define EC_DYNAMIC_Aes_Decrypt_Failed                  (EC_DYNAMIC_BASE - 18)




#define EC_DYNAMIC_MAX                   EC_SIGN_BASE
//////////////////////////////////////////////////////////////////////////
#define EC_SIGN_BASE                                         -300

#define EC_SIGN_Get_Sign_Null                                (EC_SIGN_BASE - 1)

#define EC_SIGN_Get_Sign_AppSecret_Null                      (EC_SIGN_BASE - 2)

#define EC_SIGN_Get_Sign_AppKey_Null                         (EC_SIGN_BASE - 3)

#define EC_SIGN_Get_Sign_Top_No_Data                         (EC_SIGN_BASE - 4)








#define EC_SIGN_MAX                       EC_CHECK_BASE
///////////////////////////////////////////////////////////////////////////

#define EC_CHECK_BASE                      -400

#define EC_CHECK_Obsure_Data_Null                  (EC_CHECK_BASE - 1)

#define EC_SEC_BODY_BASE                      -500

#define EC_SEC_BODY_NOT_INIT                  (EC_SEC_BODY_BASE - 1)



#define EC_CHECK_MAX                       -600 + 1

//APK Validity Check

#define EC_PKG_VALIDITY_CHECK_BASE	-700

#define EC_PKG_VALIDITY_CHECK_VERSION_INVALID	(EC_PKG_VALIDITY_CHECK_BASE - 1)

#define EC_PKG_VALIDITY_GET_DEX_SHA1_MAINIFEST_FAILED	(EC_PKG_VALIDITY_CHECK_BASE - 2)

#define EC_PKG_VALIDITY_REPORT_DATA_FAILED	(EC_PKG_VALIDITY_CHECK_BASE - 3)

////////////////////////////////////////////////////////////

#define  FUNCTION_NAME_LEN    48

struct __SErrorInformation{
	TBInt8    functionName[FUNCTION_NAME_LEN];
	TBInt32   errorCode;
	TBInt32   extraData;
	TBInt32   preserve;

};

typedef  struct __SErrorInformation   SErrorInformation  , * pSErrorInformation;

extern TBVoid CopyErrorInformationData(pSErrorInformation des ,pSErrorInformation src);


///////////////////////////////////////////////////////
#define  DECLARE_ERROR_DATA_VAR1(pSrc,STR)           \
         SErrorInformation  varError;   \
		 memset( varError.functionName  , 0 , FUNCTION_NAME_LEN);          \
		 TBInt  minSize = (FUNCTION_NAME_LEN - 1) > strlen(#STR) ? strlen(#STR) : (FUNCTION_NAME_LEN - 1); \
		 strncpy( varError.functionName ,  #STR , minSize );           \
		 varError. errorCode = ECOK;



#define ERROR_CODE_SET1(pSrc,code, extra , preserve1)     \
		varError.errorCode = (TBInt32)(code);                    \
		varError.extraData  =  (TBInt32)(extra) ;                 \
		varError.preserve = (TBInt32)(preserve1) ;




#define  COPY_ERROR_DATA_VAR1(parent)  {    \
		 pSErrorInformation  parentP = (pSErrorInformation)parent;  \
		 pSErrorInformation  var = (pSErrorInformation)(&varError);   \
		 CopyErrorInformationData(parentP , var);                \
}

//////////////////////////////////////////////////////////////////
#define DECLARE_ERROR_DATA_VAR2(pSrc ,STR)  do{                  \
		 pSErrorInformation  infoT = (pSErrorInformation)pSrc;  \
		 if( infoT != NULL){                                    \
			 memset( infoT -> functionName  , 0 , FUNCTION_NAME_LEN);     \
			 TBInt  minSize = (FUNCTION_NAME_LEN - 1) > strlen(#STR) ? strlen(#STR) : (FUNCTION_NAME_LEN - 1); \
			 strncpy( (char*)infoT->functionName ,  "T-" , 2 );             \
			 strncat( (char*)infoT->functionName ,  #STR , minSize -2 );             \
             infoT -> errorCode = ECOK;                               \
         	 infoT -> extraData = 0  ;              \
             infoT -> preserve  = 0 ;             \
		 }                                                     \
}while(0)



#define ERROR_CODE_SET2(pSrc,code, extra , preserve2)  do{           \
		pSErrorInformation  infoT = (pSErrorInformation)pSrc;  \
		LOGI("-----ERROR_CODE_SET2 [errorcode = %d]-----",code);\
		if(infoT != NULL){                                  \
			LOGIFORMAT("-----ERROR_CODE_SET2-----","-----[%d,%d,%d]-----",infoT -> errorCode,infoT -> extraData,infoT -> preserve);\
			infoT -> errorCode = (TBInt32)(code) ;                \
			infoT -> extraData = (TBInt32)(extra)  ;              \
			infoT -> preserve = (TBInt32)(preserve2) ;             \
			LOGIFORMAT("-----ERROR_CODE_SET2-----","-----[%d,%d,%d]-----",infoT -> errorCode,infoT -> extraData,infoT -> preserve);\
		}                                                     \
}while(0)

#define COPY_ERROR_DATA_VAR2(pSrc)   do{             \
		pSErrorInformation  infoT = (pSErrorInformation)pSrc;  \
		if(infoT != NULL) {                                      \
             TBInt  funlen = (TBInt)strlen(__func__);                     \
			 TBInt  minSize = (FUNCTION_NAME_LEN - 1) > funlen ? funlen : (FUNCTION_NAME_LEN - 1); \
			 strncpy( (char*)infoT->functionName ,  __func__ , minSize );  \
			 infoT->functionName[minSize]  = 0;    \
		}                                          \
}while(0)



#define  GLOBAL_STORE_ERROR_CODE_INFO   1


#if   GLOBAL_STORE_ERROR_CODE_INFO

#define   DECLARE_ERROR_DATA_VAR(pSrc ,STR)              DECLARE_ERROR_DATA_VAR2(pSrc ,STR)
#define   ERROR_CODE_SET(pSrc,code, extra , preserve)    ERROR_CODE_SET2(pSrc,code, extra , preserve)
#define   COPY_ERROR_DATA_VAR(pSrc)                      COPY_ERROR_DATA_VAR2(pSrc)

#else

#define   DECLARE_ERROR_DATA_VAR(pSrc ,STR)              DECLARE_ERROR_DATA_VAR1(pSrc,STR)
#define   ERROR_CODE_SET(pSrc,code, extra , preserve)    ERROR_CODE_SET1(pSrc,code, extra , preserve)
#define   COPY_ERROR_DATA_VAR(pSrc)                      COPY_ERROR_DATA_VAR1(pSrc)


#endif

#endif /*__TBERRORCODE_H__*/



