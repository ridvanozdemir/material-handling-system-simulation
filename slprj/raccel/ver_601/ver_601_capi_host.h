#include "__cf_ver_601.h"
#ifndef RTW_HEADER_ver_601_cap_host_h_
#define RTW_HEADER_ver_601_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } ver_601_host_DataMapInfo_T
;
#ifdef __cplusplus
extern "C" {
#endif
void ver_601_host_InitializeDataMapInfo ( ver_601_host_DataMapInfo_T *
dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
