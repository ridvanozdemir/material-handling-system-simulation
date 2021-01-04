#include "__cf_ver_601.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ver_601_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "ver_601.h"
#include "ver_601_capi.h"
#include "ver_601_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"ver_601/monoray" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 1 ,
TARGET_STRING ( "ver_601/monoray" ) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 ,
0 } , { 2 , 1 , TARGET_STRING ( "ver_601/monoray" ) , TARGET_STRING ( "" ) ,
2 , 0 , 0 , 0 , 0 } , { 3 , 1 , TARGET_STRING ( "ver_601/monoray" ) ,
TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"ver_601/monoray/is_active_c3_ver_601" ) , TARGET_STRING (
"is_active_c3_ver_601" ) , 0 , 1 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"ver_601/monoray/is_c3_ver_601" ) , TARGET_STRING ( "is_c3_ver_601" ) , 0 , 1
, 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.is_active_m1" ) , TARGET_STRING ( "is_active_m1" ) , 0
, 1 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r4.is_r4" ) , TARGET_STRING ( "is_r4" ) , 0 , 1 , 0 ,
0 , 1 } , { 8 , 0 , TARGET_STRING ( "ver_601/monoray/m3.m1.r4.is_active_r4" )
, TARGET_STRING ( "is_active_r4" ) , 0 , 1 , 0 , 0 , 1 } , { 9 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.m1.r5.is_r5" ) , TARGET_STRING ( "is_r5"
) , 0 , 1 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r5.is_active_r5" ) , TARGET_STRING ( "is_active_r5" )
, 0 , 1 , 0 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r8.is_r8" ) , TARGET_STRING ( "is_r8" ) , 0 , 1 , 0 ,
0 , 1 } , { 12 , 0 , TARGET_STRING ( "ver_601/monoray/m3.m1.r8.is_active_r8"
) , TARGET_STRING ( "is_active_r8" ) , 0 , 1 , 0 , 0 , 1 } , { 13 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.m1.r9.is_r9" ) , TARGET_STRING ( "is_r9"
) , 0 , 1 , 0 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r9.is_active_r9" ) , TARGET_STRING ( "is_active_r9" )
, 0 , 1 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r6.is_r6" ) , TARGET_STRING ( "is_r6" ) , 0 , 1 , 0 ,
0 , 1 } , { 16 , 0 , TARGET_STRING ( "ver_601/monoray/m3.m1.r6.is_active_r6"
) , TARGET_STRING ( "is_active_r6" ) , 0 , 1 , 0 , 0 , 1 } , { 17 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.m1.r7.is_r7" ) , TARGET_STRING ( "is_r7"
) , 0 , 1 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r7.is_active_r7" ) , TARGET_STRING ( "is_active_r7" )
, 0 , 1 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r3.is_r3" ) , TARGET_STRING ( "is_r3" ) , 0 , 1 , 0 ,
0 , 1 } , { 20 , 0 , TARGET_STRING ( "ver_601/monoray/m3.m1.r3.is_active_r3"
) , TARGET_STRING ( "is_active_r3" ) , 0 , 1 , 0 , 0 , 1 } , { 21 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.m1.r20.is_r20" ) , TARGET_STRING (
"is_r20" ) , 0 , 1 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r20.is_active_r20" ) , TARGET_STRING ( "is_active_r20"
) , 0 , 1 , 0 , 0 , 1 } , { 23 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r24.is_r24" ) , TARGET_STRING ( "is_r24" ) , 0 , 1 , 0
, 0 , 1 } , { 24 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r24.is_active_r24" ) , TARGET_STRING ( "is_active_r24"
) , 0 , 1 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.tictoc.is_tictoc" ) , TARGET_STRING ( "is_tictoc" ) ,
0 , 1 , 0 , 0 , 1 } , { 26 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.tictoc.is_active_tictoc" ) , TARGET_STRING (
"is_active_tictoc" ) , 0 , 1 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r2.is_r2" ) , TARGET_STRING ( "is_r2" ) , 0 , 1 , 0 ,
0 , 1 } , { 28 , 0 , TARGET_STRING ( "ver_601/monoray/m3.m1.r2.is_active_r2"
) , TARGET_STRING ( "is_active_r2" ) , 0 , 1 , 0 , 0 , 1 } , { 29 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.m1.r21.is_r21" ) , TARGET_STRING (
"is_r21" ) , 0 , 1 , 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r21.is_active_r21" ) , TARGET_STRING ( "is_active_r21"
) , 0 , 1 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r18.is_r18" ) , TARGET_STRING ( "is_r18" ) , 0 , 1 , 0
, 0 , 1 } , { 32 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r18.is_active_r18" ) , TARGET_STRING ( "is_active_r18"
) , 0 , 1 , 0 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r1.is_r1" ) , TARGET_STRING ( "is_r1" ) , 0 , 1 , 0 ,
0 , 1 } , { 34 , 0 , TARGET_STRING ( "ver_601/monoray/m3.m1.r1.is_active_r1"
) , TARGET_STRING ( "is_active_r1" ) , 0 , 1 , 0 , 0 , 1 } , { 35 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.m1.r19.is_r19" ) , TARGET_STRING (
"is_r19" ) , 0 , 1 , 0 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r19.is_active_r19" ) , TARGET_STRING ( "is_active_r19"
) , 0 , 1 , 0 , 0 , 1 } , { 37 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r22.is_r22" ) , TARGET_STRING ( "is_r22" ) , 0 , 1 , 0
, 0 , 1 } , { 38 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r22.is_active_r22" ) , TARGET_STRING ( "is_active_r22"
) , 0 , 1 , 0 , 0 , 1 } , { 39 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r17.is_r17" ) , TARGET_STRING ( "is_r17" ) , 0 , 1 , 0
, 0 , 1 } , { 40 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r17.is_active_r17" ) , TARGET_STRING ( "is_active_r17"
) , 0 , 1 , 0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r12.is_r12" ) , TARGET_STRING ( "is_r12" ) , 0 , 1 , 0
, 0 , 1 } , { 42 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r12.is_active_r12" ) , TARGET_STRING ( "is_active_r12"
) , 0 , 1 , 0 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r15.is_r15" ) , TARGET_STRING ( "is_r15" ) , 0 , 1 , 0
, 0 , 1 } , { 44 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r15.is_active_r15" ) , TARGET_STRING ( "is_active_r15"
) , 0 , 1 , 0 , 0 , 1 } , { 45 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r14.is_r14" ) , TARGET_STRING ( "is_r14" ) , 0 , 1 , 0
, 0 , 1 } , { 46 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r14.is_active_r14" ) , TARGET_STRING ( "is_active_r14"
) , 0 , 1 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r10.is_r10" ) , TARGET_STRING ( "is_r10" ) , 0 , 1 , 0
, 0 , 1 } , { 48 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r10.is_active_r10" ) , TARGET_STRING ( "is_active_r10"
) , 0 , 1 , 0 , 0 , 1 } , { 49 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r11.is_r11" ) , TARGET_STRING ( "is_r11" ) , 0 , 1 , 0
, 0 , 1 } , { 50 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r11.is_active_r11" ) , TARGET_STRING ( "is_active_r11"
) , 0 , 1 , 0 , 0 , 1 } , { 51 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r16.is_r16" ) , TARGET_STRING ( "is_r16" ) , 0 , 1 , 0
, 0 , 1 } , { 52 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r16.is_active_r16" ) , TARGET_STRING ( "is_active_r16"
) , 0 , 1 , 0 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r23.is_r23" ) , TARGET_STRING ( "is_r23" ) , 0 , 1 , 0
, 0 , 1 } , { 54 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r23.is_active_r23" ) , TARGET_STRING ( "is_active_r23"
) , 0 , 1 , 0 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r13.is_r13" ) , TARGET_STRING ( "is_r13" ) , 0 , 1 , 0
, 0 , 1 } , { 56 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r13.is_active_r13" ) , TARGET_STRING ( "is_active_r13"
) , 0 , 1 , 0 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r25.is_r25" ) , TARGET_STRING ( "is_r25" ) , 0 , 1 , 0
, 0 , 1 } , { 58 , 0 , TARGET_STRING (
"ver_601/monoray/m3.m1.r25.is_active_r25" ) , TARGET_STRING ( "is_active_r25"
) , 0 , 1 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"ver_601/monoray/m3.rdn.is_active_rdn" ) , TARGET_STRING ( "is_active_rdn" )
, 0 , 1 , 0 , 0 , 1 } , { 60 , 0 , TARGET_STRING (
"ver_601/monoray/m3.rdn.is.is_is" ) , TARGET_STRING ( "is_is" ) , 0 , 1 , 0 ,
0 , 1 } , { 61 , 0 , TARGET_STRING ( "ver_601/monoray/m3.rdn.is.is_active_is"
) , TARGET_STRING ( "is_active_is" ) , 0 , 1 , 0 , 0 , 1 } , { 62 , 0 ,
TARGET_STRING ( "ver_601/monoray/m3.rdn.dindan.is_dindan" ) , TARGET_STRING (
"is_dindan" ) , 0 , 1 , 0 , 0 , 1 } , { 63 , 0 , TARGET_STRING (
"ver_601/monoray/m3.rdn.dindan.is_active_dindan" ) , TARGET_STRING (
"is_active_dindan" ) , 0 , 1 , 0 , 0 , 1 } , { 64 , 0 , TARGET_STRING (
"ver_601/Clock" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 65 , 0 ,
TARGET_STRING ( "ver_601/as_sure" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
3 } , { 66 , 0 , TARGET_STRING ( "ver_601/asan1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 3 } , { 67 , 0 , TARGET_STRING ( "ver_601/asan2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 68 , 0 , TARGET_STRING (
"ver_601/asan3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 69 , 0 ,
TARGET_STRING ( "ver_601/asan4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3
} , { 70 , 0 , TARGET_STRING ( "ver_601/bolge_sure" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 3 } , { 71 , 0 , TARGET_STRING ( "ver_601/yuk" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 72 , 0 , TARGET_STRING (
"ver_601/Relational Operator1" ) , TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 2 }
, { 73 , 0 , TARGET_STRING ( "ver_601/Girdi" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 3 } , { 74 , 0 , TARGET_STRING ( "ver_601/Manual Switch" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 75 , 0 , TARGET_STRING (
"ver_601/Random Number" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 76 , TARGET_STRING (
"ver_601/as_sure" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 77 ,
TARGET_STRING ( "ver_601/asan1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 78 , TARGET_STRING ( "ver_601/asan2" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 79 , TARGET_STRING ( "ver_601/asan3" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 80 , TARGET_STRING ( "ver_601/asan4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING ( "ver_601/bolge_sure" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 82 , TARGET_STRING (
"ver_601/sinyalizasyon aktif" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
83 , TARGET_STRING ( "ver_601/sinyalizasyon aktif degil" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 84 , TARGET_STRING ( "ver_601/son" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
"ver_601/yuk" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 86 ,
TARGET_STRING ( "ver_601/Pulse Generator" ) , TARGET_STRING ( "Amplitude" ) ,
0 , 0 , 0 } , { 87 , TARGET_STRING ( "ver_601/Pulse Generator" ) ,
TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"ver_601/Pulse Generator" ) , TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } ,
{ 89 , TARGET_STRING ( "ver_601/Pulse Generator" ) , TARGET_STRING (
"PhaseDelay" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING ( "ver_601/Manual Switch"
) , TARGET_STRING ( "CurrentSetting" ) , 1 , 0 , 0 } , { 91 , TARGET_STRING (
"ver_601/Random Number" ) , TARGET_STRING ( "Minimum" ) , 0 , 0 , 0 } , { 92
, TARGET_STRING ( "ver_601/Random Number" ) , TARGET_STRING ( "Maximum" ) , 0
, 0 , 0 } , { 93 , TARGET_STRING ( "ver_601/Random Number" ) , TARGET_STRING
( "Seed" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static
const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 ,
0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . pt5pd0qwow , & rtB . ozrcr5iiuo ,
& rtB . btro1bqhix , & rtB . emk21lju5k , & rtDW . kw0muczhpa , & rtDW .
l4obor5hlr , & rtDW . mfdtmwnr1k , & rtDW . oif5r1h22y , & rtDW . fd4yepuw3r
, & rtDW . hzd0mt5thm , & rtDW . pdrmdwg3jy , & rtDW . emslxlwkut , & rtDW .
bfyhmul5qc , & rtDW . gdkpis41ue , & rtDW . fibxlrf25e , & rtDW . pa3b0d42cq
, & rtDW . ibbxyb4rh0 , & rtDW . kbkjspnsdq , & rtDW . o1bk5bv40q , & rtDW .
mz2yvfypvs , & rtDW . ncq15skmxi , & rtDW . o0phaggmga , & rtDW . eluhozh2mg
, & rtDW . owwx1zpbev , & rtDW . dzgke5dtts , & rtDW . nsceihis4p , & rtDW .
ieyrxl1u2b , & rtDW . heqx2n2bs3 , & rtDW . gkrx454lti , & rtDW . fy3nfeqxeh
, & rtDW . kftebazjtb , & rtDW . e5d3vh5mtr , & rtDW . am55xe0sw3 , & rtDW .
n4yhk0zzjt , & rtDW . muqm3n4moh , & rtDW . kac1izqly2 , & rtDW . k1gwjhv2mz
, & rtDW . kmzoyidp5h , & rtDW . ftsj02ku3o , & rtDW . e2cyjfx3wk , & rtDW .
old3xy41za , & rtDW . gxappx4nlx , & rtDW . b353cpbioc , & rtDW . fg2yv0b13x
, & rtDW . drpukoqm3q , & rtDW . opbrwbl3ga , & rtDW . kxrjhxe0ou , & rtDW .
f0utxalh2x , & rtDW . pqcjonzr4v , & rtDW . o2wxdztuaa , & rtDW . ni4lgririy
, & rtDW . cglv5jdbhe , & rtDW . mtmrtegtf1 , & rtDW . fussrez5qj , & rtDW .
j1ugige0vf , & rtDW . mmakc333ez , & rtDW . irnttpsjl3 , & rtDW . cghs2fki2b
, & rtDW . gp4cddax2b , & rtDW . hosixhznoe , & rtDW . kevtffqy21 , & rtDW .
c55dplmdoj , & rtDW . o3f5tl0sya , & rtDW . g4tcltg5yk , & rtB . ibeao3ybvp ,
& rtB . phezy3hqfx , & rtB . lyuuaf4tgc , & rtB . hlobqmbxfo , & rtB .
mmyhljpfw5 , & rtB . hdisprwwrk , & rtB . fjz03whqln , & rtB . l3ps3eg1j1 , &
rtB . gtqj3hxf4f , & rtB . cymbcyaldc , & rtB . dyv5pzuc22 , & rtB .
meacvw3wyh , & rtP . as_sure_Value , & rtP . asan1_Value , & rtP .
asan2_Value , & rtP . asan3_Value , & rtP . asan4_Value , & rtP .
bolge_sure_Value , & rtP . sinyalizasyonaktif_Value , & rtP .
sinyalizasyonaktifdegil_Value , & rtP . son_Value , & rtP . yuk_Value , & rtP
. PulseGenerator_Amp , & rtP . PulseGenerator_Period , & rtP .
PulseGenerator_Duty , & rtP . PulseGenerator_PhaseDelay , & rtP .
ManualSwitch_CurrentSetting , & rtP . RandomNumber_Minimum , & rtP .
RandomNumber_Maximum , & rtP . RandomNumber_Seed , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 }
, { "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.1 , 0.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , - 1 , 0 } , { ( const void *
) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
1 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 0 , 0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ;
static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 76 , (
NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 18 , rtModelParameters ,
0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 2863782131U
, 2862256862U , 4011033938U , 1389313984U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * ver_601_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ver_601_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ver_601_host_InitializeDataMapInfo ( ver_601_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
