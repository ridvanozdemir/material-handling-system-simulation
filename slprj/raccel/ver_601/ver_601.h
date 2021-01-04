#include "__cf_ver_601.h"
#ifndef RTW_HEADER_ver_601_h_
#define RTW_HEADER_ver_601_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef ver_601_COMMON_INCLUDES_
#define ver_601_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sl_fileio_rtw.h"
#include "simtarget/slSimTgtSlFileioRTW.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "ver_601_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME ver_601
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (17) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T fjz03whqln ; real_T lyuuaf4tgc ; real_T hlobqmbxfo ;
real_T mmyhljpfw5 ; real_T hdisprwwrk ; real_T meacvw3wyh ; real_T phezy3hqfx
; real_T dyv5pzuc22 ; real_T l3ps3eg1j1 ; real_T cymbcyaldc ; real_T
ibeao3ybvp ; real_T pt5pd0qwow ; real_T ozrcr5iiuo ; real_T btro1bqhix ;
real_T emk21lju5k ; int8_T oammtswjc1 ; boolean_T gtqj3hxf4f ; } B ; typedef
struct { real_T edcnujmoj4 ; real_T agj0darvmg ; real_T dha2h4fzg4 ; real_T
lxmk43h4lz ; real_T lbcota5ce1 ; real_T hgtf5d3a2d ; real_T jz0awjjmoc ;
real_T bkczy0k22h ; real_T gkgilqv5uk ; real_T hyn40d4jsd ; real_T fl5filc1dn
; real_T m3uontosom ; real_T ovn0rvfncf ; real_T gk030fyem1 ; real_T
dbqcs5iwcz ; real_T ose2snqy5h ; real_T fuq40i2njw ; real_T bqdwzeq2un ;
real_T nagfunplg2 ; real_T l2l0wvnhlk ; real_T fsdjwl2m1y ; real_T itxyfreth3
; real_T fcpu5l1c2n ; real_T hicdijuwpt ; real_T m4fcbiifke ; real_T
dryt1of0li ; real_T pej45uuf3h ; real_T akc05dbtqw ; real_T hpiuttxiw3 ;
real_T gsqk3o01dv ; real_T oszkfcwwh0 ; real_T haoggbus1r ; real_T b0rkuyehww
; real_T pvwjary3r4 ; real_T jx5ffpwvpg ; real_T lwi0qugjmt ; real_T
duavnka4jn ; real_T n1xsz5yxgo ; real_T ldyhoi3th0 ; real_T aszdge2bj3 ;
real_T inpsrydjdv ; real_T a024nxxsmy ; real_T ogcd4vjlyh ; real_T onyupqnfyz
; real_T dhgjnuwu0n ; real_T om5rxt5ou1 ; real_T mydlrme20h ; real_T
a5rmrgdlob ; real_T exrpopdo5k ; real_T fpjy00u0dg ; real_T anokgjixfy ;
real_T kdkvsetk22 ; real_T moin2xmq0s ; real_T hjcje1ohom ; real_T ngmlzhmidv
; real_T gmh5wpll4a ; real_T pw2kiq0uix ; real_T letkwdwdyo ; real_T
hxuj2eo4vo ; real_T oj5qzckq3s ; real_T bydzynpfs0 ; real_T h4x14diodv ;
real_T fdntrno1m0 ; real_T ka1uo1vch2 ; real_T amraafkuwm ; real_T par4aypkbr
; real_T gy0j0dfq0e ; real_T li03emxpnp ; real_T nxvvvn3icx ; real_T
jgql3zds1d ; real_T ks5dixrmib ; real_T agngepcllk ; real_T dujirvadqc ;
real_T k3z1hawdyy ; real_T aom1nwsm5u ; real_T co2wqvk3mm ; real_T dndx30bwcx
; real_T dpja13yknf ; real_T eidy4zo3j4 ; real_T bxadpccvt4 ; real_T
ncxtztfcfw ; real_T pzbesvy3oi ; real_T hvmeczysda ; real_T n43ygibiis ;
real_T aoj4uh13bn ; real_T meo1exeijs ; real_T ii1wiv1gpg ; real_T ojv0czdmdm
; real_T je1nwbypcu ; real_T jz1r0f4m1o ; real_T fssgd3gtc2 ; real_T
ke53mrcucn ; real_T feyyhv1ejg ; real_T nmcds41rle ; real_T cv2caqkyag ;
real_T m1mjnutiuz ; real_T ipxserfze1 ; real_T kh5cubf4hz ; real_T is0ttfnzdk
; real_T elursf1bof ; real_T lvz4sjoyft ; real_T mxh5c4jpih ; real_T
pgr4czd04f ; struct { void * FilePtr ; } cc2apx5p5r ; int32_T eehtav505d ;
int32_T kqu2dnmhtb ; uint32_T ptm4o5g5f4 ; uint32_T oduzdpbmb1 ; uint32_T
k14hmzc4fq ; uint32_T arawbmvmg3 ; uint32_T hjmhy1z112 ; uint32_T alka02fkkl
; uint32_T pqpmykxnn5 ; uint32_T kwodmegsry ; uint32_T jrqsouduhq ; uint32_T
fytwey2u0r ; uint32_T au5vabt2mi ; uint32_T d0meibhcuc ; uint32_T gifcjoukwi
; uint32_T kfz44rkzff ; uint32_T nefya5plsy ; uint32_T hf3qsopuk3 ; uint32_T
o1seehfrez ; uint32_T kzdd5niaph ; uint32_T djm3iwzgxu ; uint32_T pswmykzdp2
; uint32_T kvj4ix352l ; uint32_T cr2htc3uno ; uint32_T itegyx3jit ; uint32_T
g35rdmxw02 ; uint32_T ekxosmzqx4 ; uint32_T onm520xe2d ; uint32_T myjlktzzs4
; uint32_T g5rtgto115 ; uint32_T pr3zhyc5rf ; struct { int_T Count ; int_T
Decimation ; } e0xe1ifujj ; uint16_T fbk2lrgz23 ; int8_T mfpoxsltwf ; uint8_T
kw0muczhpa ; uint8_T l4obor5hlr ; uint8_T mfdtmwnr1k ; uint8_T oif5r1h22y ;
uint8_T fd4yepuw3r ; uint8_T hzd0mt5thm ; uint8_T pdrmdwg3jy ; uint8_T
emslxlwkut ; uint8_T bfyhmul5qc ; uint8_T gdkpis41ue ; uint8_T fibxlrf25e ;
uint8_T pa3b0d42cq ; uint8_T ibbxyb4rh0 ; uint8_T kbkjspnsdq ; uint8_T
o1bk5bv40q ; uint8_T mz2yvfypvs ; uint8_T ncq15skmxi ; uint8_T o0phaggmga ;
uint8_T eluhozh2mg ; uint8_T owwx1zpbev ; uint8_T dzgke5dtts ; uint8_T
nsceihis4p ; uint8_T ieyrxl1u2b ; uint8_T heqx2n2bs3 ; uint8_T gkrx454lti ;
uint8_T fy3nfeqxeh ; uint8_T kftebazjtb ; uint8_T e5d3vh5mtr ; uint8_T
am55xe0sw3 ; uint8_T n4yhk0zzjt ; uint8_T muqm3n4moh ; uint8_T kac1izqly2 ;
uint8_T k1gwjhv2mz ; uint8_T kmzoyidp5h ; uint8_T ftsj02ku3o ; uint8_T
e2cyjfx3wk ; uint8_T old3xy41za ; uint8_T gxappx4nlx ; uint8_T b353cpbioc ;
uint8_T fg2yv0b13x ; uint8_T drpukoqm3q ; uint8_T opbrwbl3ga ; uint8_T
kxrjhxe0ou ; uint8_T f0utxalh2x ; uint8_T pqcjonzr4v ; uint8_T o2wxdztuaa ;
uint8_T ni4lgririy ; uint8_T cglv5jdbhe ; uint8_T mtmrtegtf1 ; uint8_T
fussrez5qj ; uint8_T j1ugige0vf ; uint8_T mmakc333ez ; uint8_T irnttpsjl3 ;
uint8_T cghs2fki2b ; uint8_T gp4cddax2b ; uint8_T hosixhznoe ; uint8_T
kevtffqy21 ; uint8_T c55dplmdoj ; uint8_T o3f5tl0sya ; uint8_T g4tcltg5yk ; }
DW ; typedef struct { ZCSigState od24vpcvoq ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
bolge_sure_Value ; real_T asan1_Value ; real_T asan2_Value ; real_T
asan3_Value ; real_T asan4_Value ; real_T RandomNumber_Minimum ; real_T
RandomNumber_Maximum ; real_T RandomNumber_Seed ; real_T as_sure_Value ;
real_T sinyalizasyonaktif_Value ; real_T sinyalizasyonaktifdegil_Value ;
real_T yuk_Value ; real_T PulseGenerator_Amp ; real_T PulseGenerator_Period ;
real_T PulseGenerator_Duty ; real_T PulseGenerator_PhaseDelay ; real_T
son_Value ; uint8_T ManualSwitch_CurrentSetting ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern PrevZCX
rtPrevZCX ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
ver_601_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
