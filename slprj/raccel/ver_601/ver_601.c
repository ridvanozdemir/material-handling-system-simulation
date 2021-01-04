#include "__cf_ver_601.h"
#include "rt_logging_mmi.h"
#include "ver_601_capi.h"
#include <math.h>
#include "ver_601.h"
#include "ver_601_private.h"
#include "ver_601_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 1 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.0 (R2018b) 24-May-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\ver_601\\ver_601_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
#define aa0hc32krx ((uint8_T)2U)
#define aeo4ffm5zc ((uint8_T)9U)
#define bk2bboevdp ((uint8_T)4U)
#define cdft0q3m4g ((uint8_T)0U)
#define cfnk1zy155 ((uint8_T)5U)
#define czin04fozg ((uint8_T)4U)
#define fbytblsldw ((uint8_T)4U)
#define fmplmpxgsw ((uint8_T)7U)
#define g0lwoaqxms ((uint8_T)4U)
#define hlcrpoffhz ((uint8_T)1U)
#define jwlyizg1jy ((uint8_T)2U)
#define jzcf2bvbvd ((uint8_T)2U)
#define k0a5k1g3ch ((uint8_T)1U)
#define k2uhxvrxt2 ((uint8_T)2U)
#define k5zrvk1dey ((uint8_T)4U)
#define knryymok1t ((uint8_T)1U)
#define kwq0vz0dvl ((uint8_T)1U)
#define kz2wpg12hz ((uint8_T)2U)
#define kz2wpg12hzi ((uint8_T)3U)
#define mq4imkamiu ((uint8_T)3U)
#define nf2hhlk5rk ((uint8_T)1U)
#define ngyyamqnyw (0)
#define ojrfsbgx5t ((uint8_T)1U)
#define okrajdjvhr ((uint8_T)6U)
#define pp45ie1dfb ((uint8_T)8U)
#define pvqi0hqwtl ((uint8_T)3U)
#define pvqi0hqwtlg ((uint8_T)4U)
B rtB ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; static void l2jeuong43 ( void ) ; static void
pyssgzzdik ( void ) ; static void guamzpeoof ( void ) ; static void
fghwxucwgg ( void ) ; static void cnc1nbhrvi ( void ) ; static void
h2tw1qgz5x ( void ) ; static void bikaalqz1f ( void ) ; static void
obdota2gkr ( void ) ; static void in50rsyvpk ( void ) ; static void
lifoch2utp ( void ) ; static void oxd5zogtmd ( void ) ; static void
pko2z4wjth ( void ) ; static void gif0alc3qv ( void ) ; static void
nbvb4sjfgq ( void ) ; static void pzqinf52tu ( void ) ; static void
kqs1gahoze ( void ) ; static void i1umftraii ( void ) ; static void
dcu0gngzvk ( void ) ; static void kgbrhjvpyf ( void ) ; real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo ; uint32_T hi ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } static void l2jeuong43 ( void ) { switch (
rtDW . n4yhk0zzjt ) { case nf2hhlk5rk : rtDW . n4yhk0zzjt = kz2wpg12hz ; rtDW
. kfz44rkzff = 0U ; rtDW . agj0darvmg = 0.0 ; rtDW . gsqk3o01dv = 0.0 ; rtDW
. oszkfcwwh0 = 0.0 ; break ; case kz2wpg12hz : if ( ( rtDW . lxmk43h4lz > 0.0
) && ( rtDW . kfz44rkzff >= 10U ) ) { rtDW . n4yhk0zzjt = pvqi0hqwtl ; rtDW .
kfz44rkzff = 0U ; rtDW . agj0darvmg = 1.0 ; } break ; default : if ( ( rtDW .
lxmk43h4lz > 0.0 ) && ( rtDW . fsdjwl2m1y == 1.0 ) && ( rtDW . dryt1of0li ==
0.0 ) && ( rtDW . kfz44rkzff >= ( uint32_T ) muDoubleScalarCeil ( rtB .
phezy3hqfx * 10.0 ) ) ) { rtDW . n4yhk0zzjt = nf2hhlk5rk ; rtDW . fsdjwl2m1y
= 1.0 ; rtDW . pgr4czd04f = rtDW . lxmk43h4lz ; rtDW . dryt1of0li = 1.0 ; }
break ; } } static void pyssgzzdik ( void ) { switch ( rtDW . heqx2n2bs3 ) {
case nf2hhlk5rk : rtDW . heqx2n2bs3 = kz2wpg12hz ; rtDW . dha2h4fzg4 = 0.0 ;
rtDW . pej45uuf3h = 0.0 ; rtDW . hpiuttxiw3 = 0.0 ; rtDW . akc05dbtqw = 0.0 ;
break ; case kz2wpg12hz : if ( rtDW . dha2h4fzg4 == 1.0 ) { rtDW . heqx2n2bs3
= pvqi0hqwtl ; rtDW . au5vabt2mi = 0U ; rtDW . dha2h4fzg4 = 1.0 ; } break ;
default : if ( ( rtDW . au5vabt2mi >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . gkgilqv5uk == 0.0 ) ) { rtDW . heqx2n2bs3 =
nf2hhlk5rk ; rtDW . gkgilqv5uk = 1.0 ; rtDW . hicdijuwpt = rtDW . pej45uuf3h
; rtDW . fcpu5l1c2n = rtDW . akc05dbtqw ; rtDW . itxyfreth3 = rtDW .
hpiuttxiw3 ; } break ; } } static void guamzpeoof ( void ) { switch ( rtDW .
mz2yvfypvs ) { case nf2hhlk5rk : rtDW . mz2yvfypvs = kz2wpg12hz ; rtDW .
gkgilqv5uk = 0.0 ; rtDW . hicdijuwpt = 0.0 ; rtDW . itxyfreth3 = 0.0 ; rtDW .
fcpu5l1c2n = 0.0 ; break ; case kz2wpg12hz : if ( rtDW . gkgilqv5uk == 1.0 )
{ rtDW . mz2yvfypvs = pvqi0hqwtl ; rtDW . kwodmegsry = 0U ; rtDW . gkgilqv5uk
= 1.0 ; } break ; default : if ( ( rtDW . kwodmegsry >= ( uint32_T )
muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . is0ttfnzdk ==
0.0 ) ) { rtDW . mz2yvfypvs = nf2hhlk5rk ; rtDW . is0ttfnzdk = 1.0 ; rtDW .
ipxserfze1 = rtDW . hicdijuwpt ; rtDW . kh5cubf4hz = rtDW . fcpu5l1c2n ; rtDW
. elursf1bof = rtDW . itxyfreth3 ; } break ; } } static void fghwxucwgg (
void ) { switch ( rtDW . oif5r1h22y ) { case nf2hhlk5rk : rtDW . oif5r1h22y =
kz2wpg12hz ; rtDW . hyn40d4jsd = 0.0 ; rtDW . letkwdwdyo = 0.0 ; rtDW .
oj5qzckq3s = 0.0 ; rtDW . hxuj2eo4vo = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . hyn40d4jsd == 1.0 ) { rtDW . oif5r1h22y = pvqi0hqwtl ; rtDW .
oduzdpbmb1 = 0U ; rtDW . hyn40d4jsd = 1.0 ; } break ; case pvqi0hqwtl : if (
( rtDW . letkwdwdyo == 1.0 ) && ( rtDW . oduzdpbmb1 >= ( uint32_T )
muDoubleScalarCeil ( rtB . phezy3hqfx * 10.0 ) ) ) { rtDW . oif5r1h22y =
fbytblsldw ; rtDW . oduzdpbmb1 = 0U ; rtB . pt5pd0qwow ++ ; } else { if ( (
rtDW . oduzdpbmb1 >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln *
10.0 ) ) && ( rtDW . bkczy0k22h == 0.0 ) && ( rtDW . letkwdwdyo != 1.0 ) ) {
rtDW . oif5r1h22y = nf2hhlk5rk ; rtDW . bkczy0k22h = 1.0 ; rtDW . bydzynpfs0
= rtDW . letkwdwdyo ; rtDW . h4x14diodv = rtDW . hxuj2eo4vo ; rtDW .
fdntrno1m0 = rtDW . oj5qzckq3s ; } } break ; default : if ( ( rtDW .
oduzdpbmb1 >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . bkczy0k22h == 0.0 ) ) { rtDW . letkwdwdyo = 0.0 ; rtDW .
oj5qzckq3s = 0.0 ; rtDW . oif5r1h22y = nf2hhlk5rk ; rtDW . bkczy0k22h = 1.0 ;
rtDW . bydzynpfs0 = rtDW . letkwdwdyo ; rtDW . h4x14diodv = rtDW . hxuj2eo4vo
; rtDW . fdntrno1m0 = rtDW . oj5qzckq3s ; } break ; } } static void
cnc1nbhrvi ( void ) { switch ( rtDW . hzd0mt5thm ) { case k0a5k1g3ch : rtDW .
hzd0mt5thm = kz2wpg12hzi ; rtDW . bkczy0k22h = 0.0 ; rtDW . bydzynpfs0 = 0.0
; rtDW . fdntrno1m0 = 0.0 ; rtDW . h4x14diodv = 0.0 ; break ; case k2uhxvrxt2
: rtDW . hzd0mt5thm = kz2wpg12hzi ; rtDW . bkczy0k22h = 0.0 ; rtDW .
bydzynpfs0 = 0.0 ; rtDW . fdntrno1m0 = 0.0 ; rtDW . h4x14diodv = 0.0 ; break
; case kz2wpg12hzi : if ( rtDW . bkczy0k22h == 1.0 ) { rtDW . hzd0mt5thm =
pvqi0hqwtlg ; rtDW . k14hmzc4fq = 0U ; rtDW . bkczy0k22h = 1.0 ; } break ;
default : if ( ( ( rtDW . bydzynpfs0 == 4.0 ) || ( rtDW . bydzynpfs0 == 0.0 )
) && ( rtDW . k14hmzc4fq >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . l2l0wvnhlk == 0.0 ) && ( rtB . dyv5pzuc22
== 1.0 ) ) { rtDW . hzd0mt5thm = k2uhxvrxt2 ; rtDW . l2l0wvnhlk = 1.0 ; rtDW
. gy0j0dfq0e = rtDW . bydzynpfs0 ; rtDW . li03emxpnp = rtDW . h4x14diodv ;
rtDW . nxvvvn3icx = rtDW . fdntrno1m0 ; } else { if ( ( rtDW . k14hmzc4fq >=
( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW .
hgtf5d3a2d == 0.0 ) ) { rtDW . hzd0mt5thm = k0a5k1g3ch ; rtDW . hgtf5d3a2d =
1.0 ; rtDW . ka1uo1vch2 = rtDW . bydzynpfs0 ; rtDW . amraafkuwm = rtDW .
h4x14diodv ; rtDW . par4aypkbr = rtDW . fdntrno1m0 ; } } break ; } } static
void h2tw1qgz5x ( void ) { switch ( rtDW . pa3b0d42cq ) { case nf2hhlk5rk :
rtDW . pa3b0d42cq = kz2wpg12hz ; rtDW . hgtf5d3a2d = 0.0 ; rtDW . ka1uo1vch2
= 0.0 ; rtDW . par4aypkbr = 0.0 ; rtDW . amraafkuwm = 0.0 ; break ; case
kz2wpg12hz : if ( rtDW . hgtf5d3a2d == 1.0 ) { rtDW . pa3b0d42cq = pvqi0hqwtl
; rtDW . alka02fkkl = 0U ; rtDW . hgtf5d3a2d = 1.0 ; } break ; default : if (
( rtDW . alka02fkkl >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln *
10.0 ) ) && ( rtDW . lbcota5ce1 == 0.0 ) ) { rtDW . pa3b0d42cq = nf2hhlk5rk ;
rtDW . lbcota5ce1 = 1.0 ; rtDW . co2wqvk3mm = rtDW . ka1uo1vch2 ; rtDW .
haoggbus1r = rtDW . amraafkuwm ; rtDW . b0rkuyehww = rtDW . par4aypkbr ; }
break ; } } static void bikaalqz1f ( void ) { switch ( rtDW . kbkjspnsdq ) {
case nf2hhlk5rk : rtDW . kbkjspnsdq = kz2wpg12hz ; rtDW . lbcota5ce1 = 0.0 ;
rtDW . co2wqvk3mm = 0.0 ; rtDW . b0rkuyehww = 0.0 ; rtDW . haoggbus1r = 0.0 ;
break ; case kz2wpg12hz : if ( rtDW . lbcota5ce1 == 1.0 ) { rtDW . kbkjspnsdq
= pvqi0hqwtl ; rtDW . pqpmykxnn5 = 0U ; rtDW . lbcota5ce1 = 1.0 ; } break ;
case pvqi0hqwtl : if ( ( rtDW . co2wqvk3mm == 2.0 ) && ( rtDW . pqpmykxnn5 >=
( uint32_T ) muDoubleScalarCeil ( rtB . phezy3hqfx * 10.0 ) ) ) { rtDW .
kbkjspnsdq = czin04fozg ; rtDW . pqpmykxnn5 = 0U ; rtB . ozrcr5iiuo ++ ; }
else { if ( ( rtDW . pqpmykxnn5 >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . jz0awjjmoc == 0.0 ) ) { rtDW . kbkjspnsdq =
nf2hhlk5rk ; rtDW . jz0awjjmoc = 1.0 ; rtDW . ks5dixrmib = rtDW . co2wqvk3mm
; rtDW . dujirvadqc = rtDW . haoggbus1r ; rtDW . aom1nwsm5u = rtDW .
b0rkuyehww ; } } break ; default : if ( ( rtDW . pqpmykxnn5 >= ( uint32_T )
muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . jz0awjjmoc ==
0.0 ) ) { rtDW . co2wqvk3mm = 0.0 ; rtDW . b0rkuyehww = 0.0 ; rtDW .
kbkjspnsdq = nf2hhlk5rk ; rtDW . jz0awjjmoc = 1.0 ; rtDW . ks5dixrmib = rtDW
. co2wqvk3mm ; rtDW . dujirvadqc = rtDW . haoggbus1r ; rtDW . aom1nwsm5u =
rtDW . b0rkuyehww ; } break ; } } static void obdota2gkr ( void ) { switch (
rtDW . emslxlwkut ) { case nf2hhlk5rk : rtDW . emslxlwkut = kz2wpg12hz ; rtDW
. jz0awjjmoc = 0.0 ; rtDW . ks5dixrmib = 0.0 ; rtDW . aom1nwsm5u = 0.0 ; rtDW
. dujirvadqc = 0.0 ; break ; case kz2wpg12hz : if ( rtDW . jz0awjjmoc == 1.0
) { rtDW . emslxlwkut = pvqi0hqwtl ; rtDW . arawbmvmg3 = 0U ; rtDW .
jz0awjjmoc = 1.0 ; } break ; default : if ( ( rtDW . arawbmvmg3 >= ( uint32_T
) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . fl5filc1dn ==
0.0 ) ) { rtDW . emslxlwkut = nf2hhlk5rk ; rtDW . fl5filc1dn = 1.0 ; rtDW .
jgql3zds1d = rtDW . ks5dixrmib ; rtDW . agngepcllk = rtDW . dujirvadqc ; rtDW
. k3z1hawdyy = rtDW . aom1nwsm5u ; } break ; } } static void in50rsyvpk (
void ) { switch ( rtDW . gdkpis41ue ) { case nf2hhlk5rk : rtDW . gdkpis41ue =
kz2wpg12hz ; rtDW . fl5filc1dn = 0.0 ; rtDW . jgql3zds1d = 0.0 ; rtDW .
k3z1hawdyy = 0.0 ; rtDW . agngepcllk = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . fl5filc1dn == 1.0 ) { rtDW . gdkpis41ue = pvqi0hqwtl ; rtDW .
hjmhy1z112 = 0U ; rtDW . fl5filc1dn = 1.0 ; } break ; default : if ( ( rtDW .
hjmhy1z112 >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . meo1exeijs == 0.0 ) ) { rtDW . gdkpis41ue = nf2hhlk5rk ; rtDW .
meo1exeijs = 1.0 ; rtDW . ii1wiv1gpg = rtDW . jgql3zds1d ; rtDW . ojv0czdmdm
= rtDW . agngepcllk ; rtDW . aoj4uh13bn = rtDW . k3z1hawdyy ; } break ; } }
static void lifoch2utp ( void ) { switch ( rtDW . f0utxalh2x ) { case
nf2hhlk5rk : rtDW . f0utxalh2x = kz2wpg12hz ; rtDW . gk030fyem1 = 0.0 ; rtDW
. pvwjary3r4 = 0.0 ; rtDW . lwi0qugjmt = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . gk030fyem1 == 1.0 ) { rtDW . f0utxalh2x = pvqi0hqwtl ; rtDW .
kvj4ix352l = 0U ; rtDW . gk030fyem1 = 1.0 ; } break ; default : if ( ( rtDW .
kvj4ix352l >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . m3uontosom == 0.0 ) ) { rtDW . f0utxalh2x = nf2hhlk5rk ; rtDW .
m3uontosom = 1.0 ; rtDW . duavnka4jn = rtDW . pvwjary3r4 ; rtDW . n1xsz5yxgo
= rtDW . jx5ffpwvpg ; rtDW . hjcje1ohom = rtDW . lwi0qugjmt ; } break ; } }
static void oxd5zogtmd ( void ) { switch ( rtDW . o2wxdztuaa ) { case
nf2hhlk5rk : rtDW . o2wxdztuaa = kz2wpg12hz ; rtDW . m3uontosom = 0.0 ; rtDW
. duavnka4jn = 0.0 ; rtDW . hjcje1ohom = 0.0 ; rtDW . n1xsz5yxgo = 0.0 ;
break ; case kz2wpg12hz : if ( rtDW . m3uontosom == 1.0 ) { rtDW . o2wxdztuaa
= pvqi0hqwtl ; rtDW . cr2htc3uno = 0U ; rtDW . m3uontosom = 1.0 ; } break ;
default : if ( ( rtDW . cr2htc3uno >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . ovn0rvfncf == 0.0 ) ) { rtDW . o2wxdztuaa =
nf2hhlk5rk ; rtDW . ovn0rvfncf = 1.0 ; rtDW . inpsrydjdv = rtDW . duavnka4jn
; rtDW . anokgjixfy = rtDW . n1xsz5yxgo ; rtDW . exrpopdo5k = rtDW .
hjcje1ohom ; } break ; } } static void pko2z4wjth ( void ) { switch ( rtDW .
gxappx4nlx ) { case nf2hhlk5rk : rtDW . gxappx4nlx = kz2wpg12hz ; rtDW .
ovn0rvfncf = 0.0 ; rtDW . inpsrydjdv = 0.0 ; rtDW . exrpopdo5k = 0.0 ; rtDW .
anokgjixfy = 0.0 ; break ; case kz2wpg12hz : if ( rtDW . ovn0rvfncf == 1.0 )
{ rtDW . gxappx4nlx = pvqi0hqwtl ; rtDW . kzdd5niaph = 0U ; rtDW . ovn0rvfncf
= 1.0 ; } break ; case pvqi0hqwtl : if ( ( rtDW . inpsrydjdv == 3.0 ) && (
rtDW . kzdd5niaph >= ( uint32_T ) muDoubleScalarCeil ( rtB . phezy3hqfx *
10.0 ) ) ) { rtDW . gxappx4nlx = k5zrvk1dey ; rtDW . kzdd5niaph = 0U ; rtB .
btro1bqhix ++ ; } else { if ( ( rtDW . kzdd5niaph >= ( uint32_T )
muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . ose2snqy5h ==
0.0 ) ) { rtDW . gxappx4nlx = nf2hhlk5rk ; rtDW . ose2snqy5h = 1.0 ; rtDW .
aszdge2bj3 = rtDW . inpsrydjdv ; rtDW . pw2kiq0uix = rtDW . anokgjixfy ; rtDW
. fpjy00u0dg = rtDW . exrpopdo5k ; } } break ; default : if ( ( rtDW .
kzdd5niaph >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . ose2snqy5h == 0.0 ) ) { rtDW . inpsrydjdv = 0.0 ; rtDW .
exrpopdo5k = 0.0 ; rtDW . gxappx4nlx = nf2hhlk5rk ; rtDW . ose2snqy5h = 1.0 ;
rtDW . aszdge2bj3 = rtDW . inpsrydjdv ; rtDW . pw2kiq0uix = rtDW . anokgjixfy
; rtDW . fpjy00u0dg = rtDW . exrpopdo5k ; } break ; } } static void
gif0alc3qv ( void ) { switch ( rtDW . mmakc333ez ) { case nf2hhlk5rk : rtDW .
mmakc333ez = kz2wpg12hz ; rtDW . ose2snqy5h = 0.0 ; rtDW . aszdge2bj3 = 0.0 ;
rtDW . fpjy00u0dg = 0.0 ; rtDW . pw2kiq0uix = 0.0 ; break ; case kz2wpg12hz :
if ( rtDW . ose2snqy5h == 1.0 ) { rtDW . mmakc333ez = pvqi0hqwtl ; rtDW .
ekxosmzqx4 = 0U ; rtDW . ose2snqy5h = 1.0 ; } break ; default : if ( ( rtDW .
fuq40i2njw == 0.0 ) && ( rtDW . ekxosmzqx4 >= ( uint32_T ) muDoubleScalarCeil
( rtB . fjz03whqln * 10.0 ) ) ) { rtDW . mmakc333ez = nf2hhlk5rk ; rtDW .
fuq40i2njw = 1.0 ; rtDW . mydlrme20h = rtDW . aszdge2bj3 ; rtDW . om5rxt5ou1
= rtDW . pw2kiq0uix ; rtDW . dhgjnuwu0n = rtDW . fpjy00u0dg ; } break ; } }
static void nbvb4sjfgq ( void ) { switch ( rtDW . opbrwbl3ga ) { case
nf2hhlk5rk : rtDW . opbrwbl3ga = kz2wpg12hz ; rtDW . fuq40i2njw = 0.0 ; rtDW
. mydlrme20h = 0.0 ; rtDW . dhgjnuwu0n = 0.0 ; rtDW . om5rxt5ou1 = 0.0 ;
break ; case kz2wpg12hz : if ( rtDW . fuq40i2njw == 1.0 ) { rtDW . opbrwbl3ga
= pvqi0hqwtl ; rtDW . pswmykzdp2 = 0U ; rtDW . fuq40i2njw = 1.0 ; } break ;
default : if ( ( rtDW . pswmykzdp2 >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . bqdwzeq2un == 0.0 ) ) { rtDW . opbrwbl3ga =
nf2hhlk5rk ; rtDW . bqdwzeq2un = 1.0 ; rtDW . onyupqnfyz = rtDW . mydlrme20h
; rtDW . a024nxxsmy = rtDW . om5rxt5ou1 ; rtDW . gmh5wpll4a = rtDW .
dhgjnuwu0n ; } break ; } } static void pzqinf52tu ( void ) { switch ( rtDW .
e2cyjfx3wk ) { case nf2hhlk5rk : rtDW . e2cyjfx3wk = kz2wpg12hz ; rtDW .
dbqcs5iwcz = 0.0 ; rtDW . moin2xmq0s = 0.0 ; rtDW . a5rmrgdlob = 0.0 ; rtDW .
kdkvsetk22 = 0.0 ; break ; case kz2wpg12hz : if ( rtDW . dbqcs5iwcz == 1.0 )
{ rtDW . e2cyjfx3wk = pvqi0hqwtl ; rtDW . o1seehfrez = 0U ; rtDW . dbqcs5iwcz
= 1.0 ; } break ; default : if ( ( rtDW . o1seehfrez >= ( uint32_T )
muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . fsdjwl2m1y ==
0.0 ) ) { rtDW . e2cyjfx3wk = nf2hhlk5rk ; rtDW . fsdjwl2m1y = 1.0 ; rtDW .
pgr4czd04f = rtDW . moin2xmq0s ; rtDW . m4fcbiifke = rtDW . kdkvsetk22 ; rtDW
. dryt1of0li = rtDW . a5rmrgdlob ; } break ; } } static void kqs1gahoze (
void ) { switch ( rtDW . e5d3vh5mtr ) { case nf2hhlk5rk : rtDW . e5d3vh5mtr =
kz2wpg12hz ; rtDW . l2l0wvnhlk = 0.0 ; rtDW . gy0j0dfq0e = 0.0 ; rtDW .
nxvvvn3icx = 0.0 ; rtDW . li03emxpnp = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . l2l0wvnhlk == 1.0 ) { rtDW . e5d3vh5mtr = pvqi0hqwtl ; rtDW .
gifcjoukwi = 0U ; rtDW . l2l0wvnhlk = 1.0 ; } break ; default : if ( ( rtDW .
gifcjoukwi >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . fuq40i2njw == 0.0 ) && ( rtDW . ose2snqy5h == 0.0 ) ) { rtDW .
e5d3vh5mtr = nf2hhlk5rk ; rtDW . fuq40i2njw = 1.0 ; rtDW . mydlrme20h = rtDW
. gy0j0dfq0e ; rtDW . om5rxt5ou1 = rtDW . li03emxpnp ; rtDW . dhgjnuwu0n =
rtDW . nxvvvn3icx ; } break ; } } static void i1umftraii ( void ) { switch (
rtDW . kac1izqly2 ) { case nf2hhlk5rk : rtDW . kac1izqly2 = kz2wpg12hz ; rtDW
. fsdjwl2m1y = 0.0 ; rtDW . pgr4czd04f = 0.0 ; rtDW . dryt1of0li = 0.0 ;
break ; case kz2wpg12hz : if ( rtDW . fsdjwl2m1y == 1.0 ) { rtDW . kac1izqly2
= pvqi0hqwtl ; rtDW . nefya5plsy = 0U ; rtDW . fsdjwl2m1y = 1.0 ; } break ;
default : if ( ( rtDW . nefya5plsy >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . dha2h4fzg4 == 0.0 ) && ( rtDW . dryt1of0li
> 0.0 ) ) { rtDW . kac1izqly2 = nf2hhlk5rk ; rtDW . dha2h4fzg4 = 1.0 ; rtDW .
pej45uuf3h = rtDW . pgr4czd04f ; rtDW . akc05dbtqw = rtDW . m4fcbiifke ; rtDW
. hpiuttxiw3 = rtDW . dryt1of0li ; rtDW . m4fcbiifke = 0.0 ; } break ; } }
static void dcu0gngzvk ( void ) { l2jeuong43 ( ) ; pyssgzzdik ( ) ;
guamzpeoof ( ) ; fghwxucwgg ( ) ; cnc1nbhrvi ( ) ; h2tw1qgz5x ( ) ;
bikaalqz1f ( ) ; obdota2gkr ( ) ; in50rsyvpk ( ) ; lifoch2utp ( ) ;
oxd5zogtmd ( ) ; pko2z4wjth ( ) ; gif0alc3qv ( ) ; nbvb4sjfgq ( ) ;
pzqinf52tu ( ) ; kqs1gahoze ( ) ; i1umftraii ( ) ; switch ( rtDW . o0phaggmga
) { case nf2hhlk5rk : rtDW . o0phaggmga = kz2wpg12hz ; rtDW . je1nwbypcu =
0.0 ; rtDW . jz1r0f4m1o = 0.0 ; rtDW . ke53mrcucn = 0.0 ; rtDW . fssgd3gtc2 =
0.0 ; break ; case kz2wpg12hz : if ( rtDW . je1nwbypcu == 1.0 ) { rtDW .
o0phaggmga = pvqi0hqwtl ; rtDW . jrqsouduhq = 0U ; rtDW . je1nwbypcu = 1.0 ;
} break ; default : if ( ( rtDW . jrqsouduhq >= ( uint32_T )
muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . hyn40d4jsd ==
0.0 ) ) { rtDW . o0phaggmga = nf2hhlk5rk ; rtDW . hyn40d4jsd = 1.0 ; rtDW .
letkwdwdyo = rtDW . jz1r0f4m1o ; rtDW . hxuj2eo4vo = rtDW . fssgd3gtc2 ; rtDW
. oj5qzckq3s = rtDW . ke53mrcucn ; } break ; } switch ( rtDW . fy3nfeqxeh ) {
case nf2hhlk5rk : rtDW . fy3nfeqxeh = kz2wpg12hz ; rtDW . meo1exeijs = 0.0 ;
rtDW . ii1wiv1gpg = 0.0 ; rtDW . aoj4uh13bn = 0.0 ; rtDW . ojv0czdmdm = 0.0 ;
break ; case kz2wpg12hz : if ( rtDW . meo1exeijs == 1.0 ) { rtDW . fy3nfeqxeh
= pvqi0hqwtl ; rtDW . d0meibhcuc = 0U ; rtDW . meo1exeijs = 1.0 ; } break ;
default : if ( ( rtDW . d0meibhcuc >= ( uint32_T ) muDoubleScalarCeil ( rtB .
fjz03whqln * 10.0 ) ) && ( rtDW . dndx30bwcx == 0.0 ) ) { rtDW . fy3nfeqxeh =
nf2hhlk5rk ; rtDW . dndx30bwcx = 1.0 ; rtDW . dpja13yknf = rtDW . ii1wiv1gpg
; rtDW . eidy4zo3j4 = rtDW . ojv0czdmdm ; rtDW . bxadpccvt4 = rtDW .
aoj4uh13bn ; } break ; } switch ( rtDW . kmzoyidp5h ) { case nf2hhlk5rk :
rtDW . kmzoyidp5h = kz2wpg12hz ; rtDW . dndx30bwcx = 0.0 ; rtDW . dpja13yknf
= 0.0 ; rtDW . bxadpccvt4 = 0.0 ; rtDW . eidy4zo3j4 = 0.0 ; break ; case
kz2wpg12hz : if ( rtDW . dndx30bwcx == 1.0 ) { rtDW . kmzoyidp5h = pvqi0hqwtl
; rtDW . hf3qsopuk3 = 0U ; rtDW . dndx30bwcx = 1.0 ; } break ; default : if (
( rtDW . hf3qsopuk3 >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln *
10.0 ) ) && ( rtDW . gk030fyem1 == 0.0 ) ) { rtDW . kmzoyidp5h = nf2hhlk5rk ;
rtDW . gk030fyem1 = 1.0 ; rtDW . pvwjary3r4 = rtDW . dpja13yknf ; rtDW .
jx5ffpwvpg = rtDW . eidy4zo3j4 ; rtDW . lwi0qugjmt = rtDW . bxadpccvt4 ; }
break ; } switch ( rtDW . owwx1zpbev ) { case nf2hhlk5rk : rtDW . owwx1zpbev
= kz2wpg12hz ; rtDW . is0ttfnzdk = 0.0 ; rtDW . ipxserfze1 = 0.0 ; rtDW .
elursf1bof = 0.0 ; rtDW . kh5cubf4hz = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . is0ttfnzdk == 1.0 ) { rtDW . owwx1zpbev = pvqi0hqwtl ; rtDW .
fytwey2u0r = 0U ; rtDW . is0ttfnzdk = 1.0 ; } break ; default : if ( ( rtDW .
fytwey2u0r >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . je1nwbypcu == 0.0 ) ) { rtDW . owwx1zpbev = nf2hhlk5rk ; rtDW .
je1nwbypcu = 1.0 ; rtDW . jz1r0f4m1o = rtDW . ipxserfze1 ; rtDW . fssgd3gtc2
= rtDW . kh5cubf4hz ; rtDW . ke53mrcucn = rtDW . elursf1bof ; } break ; }
switch ( rtDW . fg2yv0b13x ) { case nf2hhlk5rk : rtDW . fg2yv0b13x =
kz2wpg12hz ; rtDW . bqdwzeq2un = 0.0 ; rtDW . onyupqnfyz = 0.0 ; rtDW .
gmh5wpll4a = 0.0 ; rtDW . a024nxxsmy = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . bqdwzeq2un == 1.0 ) { rtDW . fg2yv0b13x = pvqi0hqwtl ; rtDW .
djm3iwzgxu = 0U ; rtDW . bqdwzeq2un = 1.0 ; } break ; case pvqi0hqwtl : if (
( rtDW . onyupqnfyz == 4.0 ) && ( rtDW . djm3iwzgxu >= ( uint32_T )
muDoubleScalarCeil ( rtB . phezy3hqfx * 10.0 ) ) ) { rtDW . fg2yv0b13x =
g0lwoaqxms ; rtDW . djm3iwzgxu = 0U ; rtB . emk21lju5k ++ ; } else { if ( (
rtDW . djm3iwzgxu >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln *
10.0 ) ) && ( rtDW . feyyhv1ejg == 0.0 ) ) { rtDW . fg2yv0b13x = nf2hhlk5rk ;
rtDW . feyyhv1ejg = 1.0 ; rtDW . m1mjnutiuz = rtDW . onyupqnfyz ; rtDW .
cv2caqkyag = rtDW . a024nxxsmy ; rtDW . nmcds41rle = rtDW . gmh5wpll4a ; } }
break ; default : if ( ( rtDW . djm3iwzgxu >= ( uint32_T ) muDoubleScalarCeil
( rtB . fjz03whqln * 10.0 ) ) && ( rtDW . feyyhv1ejg == 0.0 ) ) { rtDW .
onyupqnfyz = 0.0 ; rtDW . gmh5wpll4a = 0.0 ; rtDW . fg2yv0b13x = nf2hhlk5rk ;
rtDW . feyyhv1ejg = 1.0 ; rtDW . m1mjnutiuz = rtDW . onyupqnfyz ; rtDW .
cv2caqkyag = rtDW . a024nxxsmy ; rtDW . nmcds41rle = rtDW . gmh5wpll4a ; }
break ; } switch ( rtDW . cglv5jdbhe ) { case nf2hhlk5rk : rtDW . cglv5jdbhe
= kz2wpg12hz ; rtDW . nagfunplg2 = 0.0 ; rtDW . ldyhoi3th0 = 0.0 ; rtDW .
ngmlzhmidv = 0.0 ; rtDW . ogcd4vjlyh = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . nagfunplg2 == 1.0 ) { rtDW . cglv5jdbhe = pvqi0hqwtl ; rtDW .
itegyx3jit = 0U ; rtDW . nagfunplg2 = 1.0 ; } break ; default : if ( ( rtDW .
itegyx3jit >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . dbqcs5iwcz == 0.0 ) ) { rtDW . cglv5jdbhe = nf2hhlk5rk ; rtDW .
dbqcs5iwcz = 1.0 ; rtDW . moin2xmq0s = rtDW . ldyhoi3th0 ; rtDW . kdkvsetk22
= rtDW . ogcd4vjlyh ; rtDW . a5rmrgdlob = rtDW . ngmlzhmidv ; } break ; }
switch ( rtDW . fussrez5qj ) { case nf2hhlk5rk : rtDW . fussrez5qj =
kz2wpg12hz ; rtDW . pzbesvy3oi = 0.0 ; rtDW . hvmeczysda = 0.0 ; rtDW .
ncxtztfcfw = 0.0 ; rtDW . n43ygibiis = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . pzbesvy3oi == 1.0 ) { rtDW . fussrez5qj = pvqi0hqwtl ; rtDW .
g35rdmxw02 = 0U ; rtDW . pzbesvy3oi = 1.0 ; } break ; default : if ( ( rtDW .
g35rdmxw02 >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . nagfunplg2 == 0.0 ) ) { rtDW . fussrez5qj = nf2hhlk5rk ; rtDW .
nagfunplg2 = 1.0 ; rtDW . ldyhoi3th0 = rtDW . hvmeczysda ; rtDW . ogcd4vjlyh
= rtDW . n43ygibiis ; rtDW . ngmlzhmidv = rtDW . ncxtztfcfw ; } break ; }
switch ( rtDW . cghs2fki2b ) { case nf2hhlk5rk : rtDW . cghs2fki2b =
kz2wpg12hz ; rtDW . feyyhv1ejg = 0.0 ; rtDW . m1mjnutiuz = 0.0 ; rtDW .
nmcds41rle = 0.0 ; rtDW . cv2caqkyag = 0.0 ; break ; case kz2wpg12hz : if (
rtDW . feyyhv1ejg == 1.0 ) { rtDW . cghs2fki2b = pvqi0hqwtl ; rtDW .
onm520xe2d = 0U ; rtDW . feyyhv1ejg = 1.0 ; } break ; default : if ( ( rtDW .
onm520xe2d >= ( uint32_T ) muDoubleScalarCeil ( rtB . fjz03whqln * 10.0 ) )
&& ( rtDW . pzbesvy3oi == 0.0 ) ) { rtDW . cghs2fki2b = nf2hhlk5rk ; rtDW .
pzbesvy3oi = 1.0 ; rtDW . hvmeczysda = rtDW . m1mjnutiuz ; rtDW . n43ygibiis
= rtDW . cv2caqkyag ; rtDW . ncxtztfcfw = rtDW . nmcds41rle ; } break ; } if
( rtDW . nsceihis4p == ojrfsbgx5t ) { rtDW . nsceihis4p = jwlyizg1jy ; } else
{ rtDW . nsceihis4p = ojrfsbgx5t ; } } static void kgbrhjvpyf ( void ) { rtDW
. muqm3n4moh = 1U ; rtDW . n4yhk0zzjt = kz2wpg12hz ; rtDW . kfz44rkzff = 0U ;
rtDW . agj0darvmg = 0.0 ; rtDW . gsqk3o01dv = 0.0 ; rtDW . oszkfcwwh0 = 0.0 ;
rtDW . gkrx454lti = 1U ; rtDW . heqx2n2bs3 = kz2wpg12hz ; rtDW . dha2h4fzg4 =
0.0 ; rtDW . pej45uuf3h = 0.0 ; rtDW . hpiuttxiw3 = 0.0 ; rtDW . akc05dbtqw =
0.0 ; rtDW . ncq15skmxi = 1U ; rtDW . mz2yvfypvs = kz2wpg12hz ; rtDW .
gkgilqv5uk = 0.0 ; rtDW . hicdijuwpt = 0.0 ; rtDW . itxyfreth3 = 0.0 ; rtDW .
fcpu5l1c2n = 0.0 ; rtDW . fd4yepuw3r = 1U ; rtDW . oif5r1h22y = kz2wpg12hz ;
rtDW . hyn40d4jsd = 0.0 ; rtDW . letkwdwdyo = 0.0 ; rtDW . oj5qzckq3s = 0.0 ;
rtDW . hxuj2eo4vo = 0.0 ; rtDW . pdrmdwg3jy = 1U ; rtDW . hzd0mt5thm =
kz2wpg12hzi ; rtDW . bkczy0k22h = 0.0 ; rtDW . bydzynpfs0 = 0.0 ; rtDW .
fdntrno1m0 = 0.0 ; rtDW . h4x14diodv = 0.0 ; rtDW . ibbxyb4rh0 = 1U ; rtDW .
pa3b0d42cq = kz2wpg12hz ; rtDW . hgtf5d3a2d = 0.0 ; rtDW . ka1uo1vch2 = 0.0 ;
rtDW . par4aypkbr = 0.0 ; rtDW . amraafkuwm = 0.0 ; rtDW . o1bk5bv40q = 1U ;
rtDW . kbkjspnsdq = kz2wpg12hz ; rtDW . lbcota5ce1 = 0.0 ; rtDW . co2wqvk3mm
= 0.0 ; rtDW . b0rkuyehww = 0.0 ; rtDW . haoggbus1r = 0.0 ; rtDW . bfyhmul5qc
= 1U ; rtDW . emslxlwkut = kz2wpg12hz ; rtDW . jz0awjjmoc = 0.0 ; rtDW .
ks5dixrmib = 0.0 ; rtDW . aom1nwsm5u = 0.0 ; rtDW . dujirvadqc = 0.0 ; rtDW .
fibxlrf25e = 1U ; rtDW . gdkpis41ue = kz2wpg12hz ; rtDW . fl5filc1dn = 0.0 ;
rtDW . jgql3zds1d = 0.0 ; rtDW . k3z1hawdyy = 0.0 ; rtDW . agngepcllk = 0.0 ;
rtDW . pqcjonzr4v = 1U ; rtDW . f0utxalh2x = kz2wpg12hz ; rtDW . gk030fyem1 =
0.0 ; rtDW . pvwjary3r4 = 0.0 ; rtDW . lwi0qugjmt = 0.0 ; rtDW . ni4lgririy =
1U ; rtDW . o2wxdztuaa = kz2wpg12hz ; rtDW . m3uontosom = 0.0 ; rtDW .
duavnka4jn = 0.0 ; rtDW . hjcje1ohom = 0.0 ; rtDW . n1xsz5yxgo = 0.0 ; rtDW .
b353cpbioc = 1U ; rtDW . gxappx4nlx = kz2wpg12hz ; rtDW . ovn0rvfncf = 0.0 ;
rtDW . inpsrydjdv = 0.0 ; rtDW . exrpopdo5k = 0.0 ; rtDW . anokgjixfy = 0.0 ;
rtDW . irnttpsjl3 = 1U ; rtDW . mmakc333ez = kz2wpg12hz ; rtDW . ose2snqy5h =
0.0 ; rtDW . aszdge2bj3 = 0.0 ; rtDW . fpjy00u0dg = 0.0 ; rtDW . pw2kiq0uix =
0.0 ; rtDW . kxrjhxe0ou = 1U ; rtDW . opbrwbl3ga = kz2wpg12hz ; rtDW .
fuq40i2njw = 0.0 ; rtDW . mydlrme20h = 0.0 ; rtDW . dhgjnuwu0n = 0.0 ; rtDW .
om5rxt5ou1 = 0.0 ; rtDW . old3xy41za = 1U ; rtDW . kdkvsetk22 = 2.0 ; rtDW .
a5rmrgdlob = 0.0 ; rtDW . moin2xmq0s = 0.0 ; rtDW . e2cyjfx3wk = pvqi0hqwtl ;
rtDW . o1seehfrez = 0U ; rtDW . dbqcs5iwcz = 1.0 ; rtDW . am55xe0sw3 = 1U ;
rtDW . e5d3vh5mtr = kz2wpg12hz ; rtDW . l2l0wvnhlk = 0.0 ; rtDW . gy0j0dfq0e
= 0.0 ; rtDW . nxvvvn3icx = 0.0 ; rtDW . li03emxpnp = 0.0 ; rtDW . k1gwjhv2mz
= 1U ; rtDW . m4fcbiifke = 1.0 ; rtDW . dryt1of0li = 0.0 ; rtDW . pgr4czd04f
= 0.0 ; rtDW . kac1izqly2 = pvqi0hqwtl ; rtDW . nefya5plsy = 0U ; rtDW .
fsdjwl2m1y = 1.0 ; rtDW . eluhozh2mg = 1U ; rtDW . o0phaggmga = kz2wpg12hz ;
rtDW . je1nwbypcu = 0.0 ; rtDW . jz1r0f4m1o = 0.0 ; rtDW . ke53mrcucn = 0.0 ;
rtDW . fssgd3gtc2 = 0.0 ; rtDW . kftebazjtb = 1U ; rtDW . fy3nfeqxeh =
kz2wpg12hz ; rtDW . meo1exeijs = 0.0 ; rtDW . ii1wiv1gpg = 0.0 ; rtDW .
aoj4uh13bn = 0.0 ; rtDW . ojv0czdmdm = 0.0 ; rtDW . ftsj02ku3o = 1U ; rtDW .
kmzoyidp5h = kz2wpg12hz ; rtDW . dndx30bwcx = 0.0 ; rtDW . dpja13yknf = 0.0 ;
rtDW . bxadpccvt4 = 0.0 ; rtDW . eidy4zo3j4 = 0.0 ; rtDW . dzgke5dtts = 1U ;
rtDW . owwx1zpbev = kz2wpg12hz ; rtDW . is0ttfnzdk = 0.0 ; rtDW . ipxserfze1
= 0.0 ; rtDW . elursf1bof = 0.0 ; rtDW . kh5cubf4hz = 0.0 ; rtDW . drpukoqm3q
= 1U ; rtDW . fg2yv0b13x = kz2wpg12hz ; rtDW . bqdwzeq2un = 0.0 ; rtDW .
onyupqnfyz = 0.0 ; rtDW . gmh5wpll4a = 0.0 ; rtDW . a024nxxsmy = 0.0 ; rtDW .
mtmrtegtf1 = 1U ; rtDW . ogcd4vjlyh = 3.0 ; rtDW . ngmlzhmidv = 0.0 ; rtDW .
ldyhoi3th0 = 0.0 ; rtDW . cglv5jdbhe = pvqi0hqwtl ; rtDW . itegyx3jit = 0U ;
rtDW . nagfunplg2 = 1.0 ; rtDW . j1ugige0vf = 1U ; rtDW . n43ygibiis = 4.0 ;
rtDW . ncxtztfcfw = 0.0 ; rtDW . hvmeczysda = 0.0 ; rtDW . fussrez5qj =
pvqi0hqwtl ; rtDW . g35rdmxw02 = 0U ; rtDW . pzbesvy3oi = 1.0 ; rtDW .
gp4cddax2b = 1U ; rtDW . cghs2fki2b = kz2wpg12hz ; rtDW . feyyhv1ejg = 0.0 ;
rtDW . m1mjnutiuz = 0.0 ; rtDW . nmcds41rle = 0.0 ; rtDW . cv2caqkyag = 0.0 ;
rtDW . ieyrxl1u2b = 1U ; rtDW . nsceihis4p = ojrfsbgx5t ; } void
MdlInitialize ( void ) { uint32_T tseed ; int32_T r ; int32_T t ; real_T tmp
; tmp = muDoubleScalarFloor ( rtP . RandomNumber_Seed ) ; if (
muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; }
else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0
? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp : ( uint32_T ) tmp ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r ; if ( tseed
< 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U ) { tseed =
2147483646U ; } } rtDW . ptm4o5g5f4 = tseed ; rtDW . edcnujmoj4 = ( rtP .
RandomNumber_Maximum - rtP . RandomNumber_Minimum ) *
rt_urand_Upu32_Yd_f_pw_snf ( & rtDW . ptm4o5g5f4 ) + rtP .
RandomNumber_Minimum ; rtDW . mfdtmwnr1k = 0U ; rtDW . muqm3n4moh = 0U ; rtDW
. n4yhk0zzjt = cdft0q3m4g ; rtDW . kfz44rkzff = 0U ; rtDW . pqcjonzr4v = 0U ;
rtDW . f0utxalh2x = cdft0q3m4g ; rtDW . kvj4ix352l = 0U ; rtDW . ni4lgririy =
0U ; rtDW . o2wxdztuaa = cdft0q3m4g ; rtDW . cr2htc3uno = 0U ; rtDW .
b353cpbioc = 0U ; rtDW . gxappx4nlx = cdft0q3m4g ; rtDW . kzdd5niaph = 0U ;
rtDW . irnttpsjl3 = 0U ; rtDW . mmakc333ez = cdft0q3m4g ; rtDW . ekxosmzqx4 =
0U ; rtDW . kxrjhxe0ou = 0U ; rtDW . opbrwbl3ga = cdft0q3m4g ; rtDW .
pswmykzdp2 = 0U ; rtDW . drpukoqm3q = 0U ; rtDW . fg2yv0b13x = cdft0q3m4g ;
rtDW . djm3iwzgxu = 0U ; rtDW . mtmrtegtf1 = 0U ; rtDW . cglv5jdbhe =
cdft0q3m4g ; rtDW . itegyx3jit = 0U ; rtDW . old3xy41za = 0U ; rtDW .
e2cyjfx3wk = cdft0q3m4g ; rtDW . o1seehfrez = 0U ; rtDW . am55xe0sw3 = 0U ;
rtDW . e5d3vh5mtr = cdft0q3m4g ; rtDW . gifcjoukwi = 0U ; rtDW . k1gwjhv2mz =
0U ; rtDW . kac1izqly2 = cdft0q3m4g ; rtDW . nefya5plsy = 0U ; rtDW .
gkrx454lti = 0U ; rtDW . heqx2n2bs3 = cdft0q3m4g ; rtDW . au5vabt2mi = 0U ;
rtDW . eluhozh2mg = 0U ; rtDW . o0phaggmga = cdft0q3m4g ; rtDW . jrqsouduhq =
0U ; rtDW . kftebazjtb = 0U ; rtDW . fy3nfeqxeh = cdft0q3m4g ; rtDW .
d0meibhcuc = 0U ; rtDW . ftsj02ku3o = 0U ; rtDW . kmzoyidp5h = cdft0q3m4g ;
rtDW . hf3qsopuk3 = 0U ; rtDW . j1ugige0vf = 0U ; rtDW . fussrez5qj =
cdft0q3m4g ; rtDW . g35rdmxw02 = 0U ; rtDW . dzgke5dtts = 0U ; rtDW .
owwx1zpbev = cdft0q3m4g ; rtDW . fytwey2u0r = 0U ; rtDW . gp4cddax2b = 0U ;
rtDW . cghs2fki2b = cdft0q3m4g ; rtDW . onm520xe2d = 0U ; rtDW . ncq15skmxi =
0U ; rtDW . mz2yvfypvs = cdft0q3m4g ; rtDW . kwodmegsry = 0U ; rtDW .
fd4yepuw3r = 0U ; rtDW . oif5r1h22y = cdft0q3m4g ; rtDW . oduzdpbmb1 = 0U ;
rtDW . pdrmdwg3jy = 0U ; rtDW . hzd0mt5thm = cdft0q3m4g ; rtDW . k14hmzc4fq =
0U ; rtDW . ibbxyb4rh0 = 0U ; rtDW . pa3b0d42cq = cdft0q3m4g ; rtDW .
alka02fkkl = 0U ; rtDW . o1bk5bv40q = 0U ; rtDW . kbkjspnsdq = cdft0q3m4g ;
rtDW . pqpmykxnn5 = 0U ; rtDW . bfyhmul5qc = 0U ; rtDW . emslxlwkut =
cdft0q3m4g ; rtDW . arawbmvmg3 = 0U ; rtDW . fibxlrf25e = 0U ; rtDW .
gdkpis41ue = cdft0q3m4g ; rtDW . hjmhy1z112 = 0U ; rtDW . ieyrxl1u2b = 0U ;
rtDW . nsceihis4p = cdft0q3m4g ; rtDW . hosixhznoe = 0U ; rtDW . g4tcltg5yk =
0U ; rtDW . o3f5tl0sya = cdft0q3m4g ; rtDW . fbk2lrgz23 = 0U ; rtDW .
c55dplmdoj = 0U ; rtDW . kevtffqy21 = cdft0q3m4g ; rtDW . kw0muczhpa = 0U ;
rtDW . l4obor5hlr = cdft0q3m4g ; rtDW . agj0darvmg = 0.0 ; rtDW . dha2h4fzg4
= 0.0 ; rtDW . lxmk43h4lz = 0.0 ; rtDW . gkgilqv5uk = 0.0 ; rtDW . gk030fyem1
= 0.0 ; rtDW . dbqcs5iwcz = 0.0 ; rtDW . ose2snqy5h = 0.0 ; rtDW . fuq40i2njw
= 0.0 ; rtDW . bqdwzeq2un = 0.0 ; rtDW . nagfunplg2 = 0.0 ; rtDW . fsdjwl2m1y
= 0.0 ; rtB . pt5pd0qwow = 0.0 ; rtB . ozrcr5iiuo = 0.0 ; rtB . btro1bqhix =
0.0 ; rtB . emk21lju5k = 0.0 ; rtDW . myjlktzzs4 = 0U ; rtDW . g5rtgto115 =
0U ; rtDW . pr3zhyc5rf = 0U ; } void MdlEnable ( void ) { rtDW . myjlktzzs4 =
( ( uint32_T ) ( muDoubleScalarFloor ( ssGetTaskTime ( rtS , 1 ) / 0.1 + 0.5
) ) ) ; rtDW . pr3zhyc5rf = rtDW . myjlktzzs4 ; } void MdlStart ( void ) { {
void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL )
; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize =
16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtB . fjz03whqln = rtP .
bolge_sure_Value ; rtB . lyuuaf4tgc = rtP . asan1_Value ; rtB . hlobqmbxfo =
rtP . asan2_Value ; rtB . mmyhljpfw5 = rtP . asan3_Value ; rtB . hdisprwwrk =
rtP . asan4_Value ; rtB . phezy3hqfx = rtP . as_sure_Value ; rtB . l3ps3eg1j1
= rtP . yuk_Value ; rtDW . eehtav505d = 0 ; { void * fp = ( NULL ) ; const
char * fileNameOriginal = "yuk3a2.mat" ; char * fileName = ( char * ) malloc
( 509 ) ; if ( fileName == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"Error allocating memory for file name" ) ; return ; } strcpy ( fileName ,
fileNameOriginal ) ; { const char * blockpath = "ver_601/To File2" ; if (
slIsRapidAcceleratorSimulating ( ) ) { rt_RAccelReplaceToFilename ( blockpath
, fileName ) ; } } { const char * errMsg = ( NULL ) ; errMsg =
rtwH5LoggingCollectionCreateInstance ( 1 , & fp , rtliGetLoggingInterval (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ) ; if ( errMsg != ( NULL ) )
{ ssSetErrorStatus ( rtS , errMsg ) ; return ; } { int_T dimensions [ 1 ] = {
1 } ; errMsg = rtwH5LoggingCollectionAddElement ( 1 , fp , fileName ,
"yuk3a2" , 0 , "" , "zoh" , "double" , 1 , dimensions , 0 , 1 , 1 , 0 , 0 , 0
, 0 , 0 , 0 , 0 ) ; } if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS ,
errMsg ) ; return ; } } if ( fileName != ( NULL ) ) { free ( fileName ) ; }
rtDW . e0xe1ifujj . Count = 0 ; rtDW . e0xe1ifujj . Decimation = - 1 ; rtDW .
cc2apx5p5r . FilePtr = fp ; } MdlInitialize ( ) ; MdlEnable ( ) ; } void
MdlOutputs ( int_T tid ) { real_T d5dpzoiw1e ; real_T kxra2ylw3u ;
ZCEventType zcEvent ; srClearBC ( rtDW . mfpoxsltwf ) ; rtB . meacvw3wyh =
rtDW . edcnujmoj4 ; if ( rtP . ManualSwitch_CurrentSetting == 1 ) { rtB .
dyv5pzuc22 = rtP . sinyalizasyonaktif_Value ; } else { rtB . dyv5pzuc22 = rtP
. sinyalizasyonaktifdegil_Value ; } kxra2ylw3u = ( rtDW . eehtav505d < rtP .
PulseGenerator_Duty ) && ( rtDW . eehtav505d >= 0 ) ? rtP .
PulseGenerator_Amp : 0.0 ; if ( rtDW . eehtav505d >= rtP .
PulseGenerator_Period - 1.0 ) { rtDW . eehtav505d = 0 ; } else { rtDW .
eehtav505d ++ ; } zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX .
od24vpcvoq , ( kxra2ylw3u ) ) ; if ( zcEvent != NO_ZCEVENT ) { rtB .
oammtswjc1 = ( int8_T ) zcEvent ; rtDW . myjlktzzs4 = ( ( uint32_T ) (
muDoubleScalarFloor ( ssGetTaskTime ( rtS , 1 ) / 0.1 + 0.5 ) ) ) ; rtDW .
g5rtgto115 = rtDW . myjlktzzs4 - rtDW . pr3zhyc5rf ; rtDW . pr3zhyc5rf = rtDW
. myjlktzzs4 ; rtDW . oduzdpbmb1 += rtDW . g5rtgto115 ; rtDW . k14hmzc4fq +=
rtDW . g5rtgto115 ; rtDW . arawbmvmg3 += rtDW . g5rtgto115 ; rtDW .
hjmhy1z112 += rtDW . g5rtgto115 ; rtDW . alka02fkkl += rtDW . g5rtgto115 ;
rtDW . pqpmykxnn5 += rtDW . g5rtgto115 ; rtDW . kwodmegsry += rtDW .
g5rtgto115 ; rtDW . jrqsouduhq += rtDW . g5rtgto115 ; rtDW . fytwey2u0r +=
rtDW . g5rtgto115 ; rtDW . au5vabt2mi += rtDW . g5rtgto115 ; rtDW .
d0meibhcuc += rtDW . g5rtgto115 ; rtDW . gifcjoukwi += rtDW . g5rtgto115 ;
rtDW . kfz44rkzff += rtDW . g5rtgto115 ; rtDW . nefya5plsy += rtDW .
g5rtgto115 ; rtDW . hf3qsopuk3 += rtDW . g5rtgto115 ; rtDW . o1seehfrez +=
rtDW . g5rtgto115 ; rtDW . kzdd5niaph += rtDW . g5rtgto115 ; rtDW .
djm3iwzgxu += rtDW . g5rtgto115 ; rtDW . pswmykzdp2 += rtDW . g5rtgto115 ;
rtDW . kvj4ix352l += rtDW . g5rtgto115 ; rtDW . cr2htc3uno += rtDW .
g5rtgto115 ; rtDW . itegyx3jit += rtDW . g5rtgto115 ; rtDW . g35rdmxw02 +=
rtDW . g5rtgto115 ; rtDW . ekxosmzqx4 += rtDW . g5rtgto115 ; rtDW .
onm520xe2d += rtDW . g5rtgto115 ; if ( rtDW . fbk2lrgz23 + rtDW . g5rtgto115
<= 16383U ) { rtDW . fbk2lrgz23 = ( uint16_T ) ( rtDW . fbk2lrgz23 + rtDW .
g5rtgto115 ) ; } else { rtDW . fbk2lrgz23 = 16383U ; } rtDW . kqu2dnmhtb =
ngyyamqnyw ; if ( rtDW . kw0muczhpa == 0U ) { rtDW . kw0muczhpa = 1U ; rtDW .
l4obor5hlr = kwq0vz0dvl ; rtDW . mfdtmwnr1k = 1U ; kgbrhjvpyf ( ) ; rtDW .
hosixhznoe = 1U ; rtDW . c55dplmdoj = 1U ; rtDW . kevtffqy21 = pp45ie1dfb ;
rtDW . g4tcltg5yk = 1U ; rtDW . o3f5tl0sya = aa0hc32krx ; rtDW . fbk2lrgz23 =
0U ; } else { dcu0gngzvk ( ) ; switch ( rtDW . kevtffqy21 ) { case hlcrpoffhz
: if ( ( rtDW . mxh5c4jpih > 0.0 ) && ( rtDW . fsdjwl2m1y == 1.0 ) ) { rtDW .
mxh5c4jpih -- ; rtDW . kevtffqy21 = jzcf2bvbvd ; rtDW . lxmk43h4lz = 1.0 ; }
break ; case jzcf2bvbvd : if ( rtDW . pgr4czd04f == 1.0 ) { rtDW . kevtffqy21
= mq4imkamiu ; rtDW . lxmk43h4lz = 2.0 ; } break ; case mq4imkamiu : if (
rtDW . pgr4czd04f == 2.0 ) { rtDW . kevtffqy21 = bk2bboevdp ; rtDW .
lxmk43h4lz = 3.0 ; } break ; case bk2bboevdp : if ( rtDW . pgr4czd04f == 3.0
) { rtDW . kevtffqy21 = cfnk1zy155 ; rtDW . lxmk43h4lz = 4.0 ; } break ; case
cfnk1zy155 : if ( rtDW . pgr4czd04f == 4.0 ) { rtDW . kevtffqy21 = hlcrpoffhz
; rtDW . lxmk43h4lz = 0.0 ; } break ; case okrajdjvhr : if ( ( rtDW .
mxh5c4jpih > 0.0 ) && ( rtDW . fsdjwl2m1y == 1.0 ) ) { rtDW . mxh5c4jpih -- ;
rtDW . kevtffqy21 = jzcf2bvbvd ; rtDW . lxmk43h4lz = 1.0 ; } break ; case
fmplmpxgsw : if ( ( rtDW . mxh5c4jpih > 0.0 ) && ( rtDW . fsdjwl2m1y == 1.0 )
) { rtDW . mxh5c4jpih -- ; rtDW . kevtffqy21 = jzcf2bvbvd ; rtDW . lxmk43h4lz
= 1.0 ; } break ; case pp45ie1dfb : if ( rtB . l3ps3eg1j1 == 1.0 ) { rtDW .
kevtffqy21 = okrajdjvhr ; rtDW . lvz4sjoyft = 2.0 ; rtDW . mxh5c4jpih = 2.0 ;
} else if ( rtB . l3ps3eg1j1 == 2.0 ) { rtDW . kevtffqy21 = aeo4ffm5zc ; rtDW
. lvz4sjoyft = 3.0 ; rtDW . mxh5c4jpih = 3.0 ; } else { if ( rtB . l3ps3eg1j1
== 3.0 ) { rtDW . kevtffqy21 = fmplmpxgsw ; rtDW . lvz4sjoyft = 4.0 ; rtDW .
mxh5c4jpih = 4.0 ; } } break ; default : if ( ( rtDW . mxh5c4jpih > 0.0 ) &&
( rtDW . fsdjwl2m1y == 1.0 ) ) { rtDW . mxh5c4jpih -- ; rtDW . kevtffqy21 =
jzcf2bvbvd ; rtDW . lxmk43h4lz = 1.0 ; } break ; } if ( rtDW . o3f5tl0sya ==
knryymok1t ) { rtDW . o3f5tl0sya = aa0hc32krx ; rtDW . fbk2lrgz23 = 0U ; }
else { if ( rtDW . fbk2lrgz23 >= 9600U ) { rtDW . o3f5tl0sya = knryymok1t ;
rtDW . mxh5c4jpih += rtDW . lvz4sjoyft ; } } } rtDW . mfpoxsltwf = 4 ; }
d5dpzoiw1e = ( ( rtB . emk21lju5k + rtB . btro1bqhix ) + rtB . ozrcr5iiuo ) +
rtB . pt5pd0qwow ; if ( d5dpzoiw1e == rtB . cymbcyaldc ) { ssSetStopRequested
( rtS , 1 ) ; } if ( ssGetLogOutput ( rtS ) ) { { const char * errMsg = (
NULL ) ; void * fp = ( void * ) rtDW . cc2apx5p5r . FilePtr ; if ( fp != (
NULL ) ) { { real_T t ; void * u ; t = ssGetTaskTime ( rtS , 1 ) ; u = ( void
* ) & d5dpzoiw1e ; errMsg = rtwH5LoggingCollectionWrite ( 1 , fp , 0 , t , u
) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ;
} } } } } rtB . ibeao3ybvp = ssGetT ( rtS ) ; rtB . gtqj3hxf4f = ( rtP .
son_Value <= rtB . ibeao3ybvp ) ; if ( rtB . gtqj3hxf4f ) {
ssSetStopRequested ( rtS , 1 ) ; } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { rtB . fjz03whqln = rtP . bolge_sure_Value ;
rtB . lyuuaf4tgc = rtP . asan1_Value ; rtB . hlobqmbxfo = rtP . asan2_Value ;
rtB . mmyhljpfw5 = rtP . asan3_Value ; rtB . hdisprwwrk = rtP . asan4_Value ;
rtB . phezy3hqfx = rtP . as_sure_Value ; rtB . l3ps3eg1j1 = rtP . yuk_Value ;
rtB . cymbcyaldc = ( ( rtB . hdisprwwrk + rtB . mmyhljpfw5 ) + rtB .
hlobqmbxfo ) + rtB . lyuuaf4tgc ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate
( int_T tid ) { rtDW . edcnujmoj4 = ( rtP . RandomNumber_Maximum - rtP .
RandomNumber_Minimum ) * rt_urand_Upu32_Yd_f_pw_snf ( & rtDW . ptm4o5g5f4 ) +
rtP . RandomNumber_Minimum ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { {
const char * errMsg = ( NULL ) ; void * fp = ( void * ) rtDW . cc2apx5p5r .
FilePtr ; if ( fp != ( NULL ) ) { errMsg =
rtwH5LoggingCollectionDestroyInstance ( 1 , fp ) ; if ( errMsg != ( NULL ) )
{ ssSetErrorStatus ( rtS , errMsg ) ; return ; } } } if ( rt_slioCatalogue (
) != ( NULL ) ) { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 29 ) ;
ssSetNumBlockIO ( rtS , 17 ) ; ssSetNumBlockParams ( rtS , 18 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.1 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2863782131U ) ; ssSetChecksumVal ( rtS , 1 ,
2862256862U ) ; ssSetChecksumVal ( rtS , 2 , 4011033938U ) ; ssSetChecksumVal
( rtS , 3 , 1389313984U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } ver_601_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"ver_601" ) ; ssSetPath ( rtS , "ver_601" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , rtInf ) ; ssSetStepSize ( rtS , 0.1 ) ;
ssSetFixedStepSize ( rtS , 0.1 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 1000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } { ZCSigState * zc = ( ZCSigState * ) &
rtPrevZCX ; ssSetPrevZCSigState ( rtS , zc ) ; } { rtPrevZCX . od24vpcvoq =
UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS , 0 , 2863782131U ) ;
ssSetChecksumVal ( rtS , 1 , 2862256862U ) ; ssSetChecksumVal ( rtS , 2 ,
4011033938U ) ; ssSetChecksumVal ( rtS , 3 , 1389313984U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 2 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . mfpoxsltwf ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
