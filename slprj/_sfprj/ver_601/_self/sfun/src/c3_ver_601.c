/* Include files */

#include "ver_601_sfun.h"
#include "c3_ver_601.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ver_601_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define c3_event_trig                  (0)
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_m3                       ((uint8_T)1U)
#define c3_IN_Next                     ((uint8_T)1U)
#define c3_IN_Off                      ((uint8_T)2U)
#define c3_IN_On                       ((uint8_T)3U)
#define c3_IN_as1                      ((uint8_T)4U)
#define c3_IN_Next1                    ((uint8_T)1U)
#define c3_IN_Next2                    ((uint8_T)2U)
#define c3_b_IN_Off                    ((uint8_T)3U)
#define c3_b_IN_On                     ((uint8_T)4U)
#define c3_IN_as2                      ((uint8_T)4U)
#define c3_IN_tic                      ((uint8_T)1U)
#define c3_IN_toc                      ((uint8_T)2U)
#define c3_IN_as3                      ((uint8_T)4U)
#define c3_IN_as4                      ((uint8_T)4U)
#define c3_IN_A0                       ((uint8_T)1U)
#define c3_IN_A1                       ((uint8_T)2U)
#define c3_IN_A2                       ((uint8_T)3U)
#define c3_IN_A3                       ((uint8_T)4U)
#define c3_IN_A4                       ((uint8_T)5U)
#define c3_IN_az                       ((uint8_T)6U)
#define c3_IN_cok                      ((uint8_T)7U)
#define c3_IN_is_secim                 ((uint8_T)8U)
#define c3_IN_orta                     ((uint8_T)9U)
#define c3_IN_dan                      ((uint8_T)1U)
#define c3_IN_din                      ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[35] = { "txt1", "txt19", "txt2",
  "txt3", "txt24", "txt20", "txt4", "txt5", "txt18", "txt6", "txt7", "txt8",
  "txt9", "txt21", "txt22", "txt10", "txt11", "txt12", "txt13", "txt14", "txt15",
  "txt25", "txt23", "txt16", "txt17", "txt_as1", "txt_as2", "txt_as3", "txt_as4",
  "edt_as1", "edt_as2", "edt_as3", "edt_as4", "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_m_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_n_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_p_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_q_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_r_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_t_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_v_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_w_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_x_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_y_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ab_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_bb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_cb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_db_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_eb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_fb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_gb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_hb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ib_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_jb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_kb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_lb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_mb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_nb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ob_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_pb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_qb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_rb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_sb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_tb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ub_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_vb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_wb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_xb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_yb_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ac_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_bc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_cc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_dc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ec_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_fc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_gc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_hc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ic_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_jc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_kc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_lc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_mc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_nc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_oc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_pc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_qc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_rc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_sc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_tc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_uc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_vc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_wc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_xc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_yc_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ad_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_bd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_cd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_dd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ed_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_fd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_gd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_hd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_id_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_jd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_kd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ld_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_md_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_nd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_od_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_pd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_qd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_rd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_sd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_td_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ud_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_vd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xd_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_yd_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ae_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_be_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ce_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_de_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ee_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ge_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_he_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ie_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_je_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ke_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_le_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_me_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ne_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_oe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_qe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_re_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_se_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_te_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ue_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ve_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_we_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xe_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ye_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_af_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_df_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ef_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ff_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_gf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_if_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_jf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_nf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_of_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pf_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_qf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_rf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_tf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_uf_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_vf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_yf_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ag_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_bg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_cg_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_dg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_eg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_fg_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_gg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_hg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ig_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_jg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_kg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_lg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_mg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_ng_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_og_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_pg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_qg_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_rg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_sg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_tg_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_ug_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_vg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_wg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_xg_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void initialize_params_c3_ver_601(SFc3_ver_601InstanceStruct
  *chartInstance);
static void enable_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void disable_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ver_601(SFc3_ver_601InstanceStruct
  *chartInstance);
static void ext_mode_exec_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ver_601(SFc3_ver_601InstanceStruct
  *chartInstance);
static void set_sim_state_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_ver_601(SFc3_ver_601InstanceStruct *
  chartInstance);
static void finalize_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void sf_gateway_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void mdl_start_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void initSimStructsc3_ver_601(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_m1(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_m1(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r4(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r4(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r5(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r5(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_b_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r8(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r8(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_c_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r9(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_d_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r6(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r6(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_e_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r7(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r7(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_b_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_f_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r3(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r3(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_g_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r20(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_h_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r24(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_i_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r2(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r2(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_j_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r21(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_k_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r18(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_l_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_enter_internal_r1(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r1(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r19(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r22(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_m_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r17(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r12(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_c_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_n_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r15(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_d_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_o_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r14(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_p_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r10(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r11(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_q_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r16(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r23(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r13(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_r_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_s_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_is(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_is_secim(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_cok(SFc3_ver_601InstanceStruct *chartInstance);
static void c3_orta(SFc3_ver_601InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[3]);
static const mxArray *c3_b_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[8]);
static const mxArray *c3_c_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[9]);
static const mxArray *c3_d_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[6]);
static const mxArray *c3_e_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const real_T c3_u);
static const mxArray *c3_f_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[15]);
static const mxArray *c3_g_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[5]);
static const mxArray *c3_h_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const real_T c3_u[2]);
static const mxArray *c3_i_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_nargin, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_color1(SFc3_ver_601InstanceStruct *chartInstance);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int8_T c3_d_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_m1, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_h_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u);
static uint32_T c3_i_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_temporalCounter_i10, const char_T *c3_identifier);
static uint32_T c3_j_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static uint16_T c3_k_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_temporalCounter_i26, const char_T *c3_identifier);
static uint16_T c3_l_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_m_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[91]);
static void c3_n_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[91]);
static const mxArray *c3_o_emlrt_marshallIn(SFc3_ver_601InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_p_emlrt_marshallIn(SFc3_ver_601InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_ver_601InstanceStruct
  *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_ver_601InstanceStruct
  *chartInstance);
static uint32_T c3__u32_d_(SFc3_ver_601InstanceStruct *chartInstance, real_T
  c3_b, uint32_T c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T
  c3_length_src_loc);
static void init_dsm_address_info(SFc3_ver_601InstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_ver_601InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_ver_601(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  sim_mode_is_external(chartInstance->S);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c3_is_active_m1 = 0U;
  *chartInstance->c3_is_active_r1 = 0U;
  *chartInstance->c3_is_r1 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i13 = 0U;
  *chartInstance->c3_temporalCounter_i13 = 0U;
  *chartInstance->c3_is_active_r10 = 0U;
  *chartInstance->c3_is_r10 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i20 = 0U;
  *chartInstance->c3_is_active_r11 = 0U;
  *chartInstance->c3_is_r11 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i21 = 0U;
  *chartInstance->c3_is_active_r12 = 0U;
  *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i17 = 0U;
  *chartInstance->c3_temporalCounter_i17 = 0U;
  *chartInstance->c3_is_active_r13 = 0U;
  *chartInstance->c3_is_r13 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i24 = 0U;
  *chartInstance->c3_is_active_r14 = 0U;
  *chartInstance->c3_is_r14 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i19 = 0U;
  *chartInstance->c3_is_active_r15 = 0U;
  *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i18 = 0U;
  *chartInstance->c3_temporalCounter_i18 = 0U;
  *chartInstance->c3_is_active_r16 = 0U;
  *chartInstance->c3_is_r16 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i22 = 0U;
  *chartInstance->c3_is_active_r17 = 0U;
  *chartInstance->c3_is_r17 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i16 = 0U;
  *chartInstance->c3_is_active_r18 = 0U;
  *chartInstance->c3_is_r18 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i12 = 0U;
  *chartInstance->c3_is_active_r19 = 0U;
  *chartInstance->c3_is_r19 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i14 = 0U;
  *chartInstance->c3_is_active_r2 = 0U;
  *chartInstance->c3_is_r2 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i10 = 0U;
  *chartInstance->c3_is_active_r20 = 0U;
  *chartInstance->c3_is_r20 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i8 = 0U;
  *chartInstance->c3_is_active_r21 = 0U;
  *chartInstance->c3_is_r21 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i11 = 0U;
  *chartInstance->c3_is_active_r22 = 0U;
  *chartInstance->c3_is_r22 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i15 = 0U;
  *chartInstance->c3_is_active_r23 = 0U;
  *chartInstance->c3_is_r23 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i23 = 0U;
  *chartInstance->c3_is_active_r24 = 0U;
  *chartInstance->c3_is_r24 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i9 = 0U;
  *chartInstance->c3_is_active_r25 = 0U;
  *chartInstance->c3_is_r25 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i25 = 0U;
  *chartInstance->c3_is_active_r3 = 0U;
  *chartInstance->c3_is_r3 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i7 = 0U;
  *chartInstance->c3_is_active_r4 = 0U;
  *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_temporalCounter_i1 = 0U;
  *chartInstance->c3_is_active_r5 = 0U;
  *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i2 = 0U;
  *chartInstance->c3_is_active_r6 = 0U;
  *chartInstance->c3_is_r6 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i5 = 0U;
  *chartInstance->c3_is_active_r7 = 0U;
  *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i6 = 0U;
  *chartInstance->c3_temporalCounter_i6 = 0U;
  *chartInstance->c3_is_active_r8 = 0U;
  *chartInstance->c3_is_r8 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i3 = 0U;
  *chartInstance->c3_is_active_r9 = 0U;
  *chartInstance->c3_is_r9 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i4 = 0U;
  *chartInstance->c3_is_active_tictoc = 0U;
  *chartInstance->c3_is_tictoc = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_is_active_rdn = 0U;
  *chartInstance->c3_is_active_dindan = 0U;
  *chartInstance->c3_is_dindan = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_temporalCounter_i26 = 0U;
  *chartInstance->c3_is_active_is = 0U;
  *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_is_active_c3_ver_601 = 0U;
  *chartInstance->c3_is_c3_ver_601 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_vr1 = 0.0;
  *chartInstance->c3_vr2 = 0.0;
  *chartInstance->c3_j1 = 0.0;
  *chartInstance->c3_vr3 = 0.0;
  *chartInstance->c3_vr10 = 0.0;
  *chartInstance->c3_vr17 = 0.0;
  *chartInstance->c3_vr13 = 0.0;
  *chartInstance->c3_vr14 = 0.0;
  *chartInstance->c3_vr15 = 0.0;
  *chartInstance->c3_vr16 = 0.0;
  *chartInstance->c3_vr19 = 0.0;
  if (sf_get_output_port_reusable(chartInstance->S, 1) == 0) {
    *chartInstance->c3_as1 = 0.0;
  }

  if (sf_get_output_port_reusable(chartInstance->S, 2) == 0) {
    *chartInstance->c3_as2 = 0.0;
  }

  if (sf_get_output_port_reusable(chartInstance->S, 3) == 0) {
    *chartInstance->c3_as3 = 0.0;
  }

  if (sf_get_output_port_reusable(chartInstance->S, 4) == 0) {
    *chartInstance->c3_as4 = 0.0;
  }

  *chartInstance->c3_presentTicks = 0U;
  *chartInstance->c3_elapsedTicks = 0U;
  *chartInstance->c3_previousTicks = 0U;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr1, 52U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr2, 63U);
  _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 0U, 0, 0);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr3, 70U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr10, 53U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr17, 60U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr13, 56U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr14, 57U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr15, 58U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr16, 59U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr19, 62U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as1, 111U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as2, 112U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as3, 113U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as4, 114U);
  setLegacyDebuggerFlagForRuntime(chartInstance->S, true);
}

static void initialize_params_c3_ver_601(SFc3_ver_601InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  *chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor((_sfTime_ -
    sf_get_start_time(chartInstance->S)) / 0.1 + 0.5);
  *chartInstance->c3_previousTicks = *chartInstance->c3_presentTicks;
}

static void disable_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  *chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor((_sfTime_ -
    sf_get_start_time(chartInstance->S)) / 0.1 + 0.5);
  *chartInstance->c3_elapsedTicks = *chartInstance->c3_presentTicks -
    *chartInstance->c3_previousTicks;
  *chartInstance->c3_previousTicks = *chartInstance->c3_presentTicks;
  *chartInstance->c3_temporalCounter_i1 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i2 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i3 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i4 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i5 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i6 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i7 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i8 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i9 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i10 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i11 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i12 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i13 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i14 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i15 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i16 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i17 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i18 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i19 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i20 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i21 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i22 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i23 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i24 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i25 += *chartInstance->c3_elapsedTicks;
  if ((uint32_T)*chartInstance->c3_temporalCounter_i26 +
      *chartInstance->c3_elapsedTicks <= 16383U) {
    *chartInstance->c3_temporalCounter_i26 = (uint16_T)((uint32_T)
      *chartInstance->c3_temporalCounter_i26 + *chartInstance->c3_elapsedTicks);
  } else {
    *chartInstance->c3_temporalCounter_i26 = 16383U;
  }
}

static void c3_update_debugger_state_c3_ver_601(SFc3_ver_601InstanceStruct
  *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c3_is_active_c3_ver_601 == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_ver_601 == c3_IN_m3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_m1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r4 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 81U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 81U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r4 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 84U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r4 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r4 == c3_IN_as1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 85U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 85U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r4 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 83U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 83U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r5 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 86U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r5 == c3_b_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 90U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 90U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r5 == c3_IN_Next1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 87U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 87U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r5 == c3_IN_Next2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 88U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 88U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r5 == c3_b_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r8 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 100U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 100U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r8 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 103U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 103U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r8 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 101U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 101U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r8 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 102U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r9 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 104U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r9 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 107U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 107U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r9 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 105U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 105U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r9 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 106U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 106U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r6 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 91U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 91U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r6 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 94U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 94U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r6 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 92U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 92U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r6 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 93U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 93U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r7 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 95U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 95U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r7 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 98U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 98U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r7 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r7 == c3_IN_as2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 99U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 99U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r7 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 97U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 97U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r3 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 77U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 77U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r3 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 80U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 80U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r3 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 78U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 78U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r3 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 79U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 79U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r20 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 53U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r20 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r20 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r20 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r24 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 69U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 69U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r24 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r24 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 70U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r24 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 71U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_tictoc == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 108U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 108U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_tictoc == c3_IN_tic) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_tictoc == c3_IN_toc) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 110U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 110U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r2 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 49U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r2 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r2 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r2 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r21 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 57U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r21 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 60U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r21 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r21 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r18 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 41U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r18 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r18 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r18 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r1 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r1 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r1 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r1 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r19 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 45U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r19 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r19 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r19 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r22 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 61U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r22 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r22 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r22 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r17 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 37U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r17 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r17 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r17 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r12 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r12 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r12 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r12 == c3_IN_as3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r12 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r15 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 28U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r15 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r15 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r15 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r15 == c3_IN_as4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r14 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 24U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r14 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r14 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r14 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r10 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r10 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r10 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r10 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r11 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r11 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r11 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r11 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r16 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 33U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r16 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r16 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r16 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r23 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 65U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r23 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r23 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r23 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r13 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r13 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r13 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r13 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_r25 == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 73U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 73U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r25 == c3_IN_On) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 76U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 76U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r25 == c3_IN_Next) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_r25 == c3_IN_Off) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 75U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 75U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_rdn == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 111U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 111U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_is == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 115U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 115U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_is_secim) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_az) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 121U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 121U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_cok) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 122U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_orta) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 124U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 124U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_A0) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 116U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 116U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_A1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_A2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 118U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 118U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_A3) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_is == c3_IN_A4) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 120U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_active_dindan == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 112U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 112U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_dindan == c3_IN_din) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 114U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 114U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_dindan == c3_IN_dan) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 113U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 113U, *chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_ver_601(chartInstance);
}

static const mxArray *get_sim_state_c3_ver_601(SFc3_ver_601InstanceStruct
  *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  real_T c3_j_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  real_T c3_k_hoistedGlobal;
  const mxArray *c3_l_y = NULL;
  real_T c3_l_hoistedGlobal;
  const mxArray *c3_m_y = NULL;
  real_T c3_m_hoistedGlobal;
  const mxArray *c3_n_y = NULL;
  real_T c3_n_hoistedGlobal;
  const mxArray *c3_o_y = NULL;
  real_T c3_o_hoistedGlobal;
  const mxArray *c3_p_y = NULL;
  real_T c3_p_hoistedGlobal;
  const mxArray *c3_q_y = NULL;
  real_T c3_q_hoistedGlobal;
  const mxArray *c3_r_y = NULL;
  real_T c3_r_hoistedGlobal;
  const mxArray *c3_s_y = NULL;
  real_T c3_s_hoistedGlobal;
  const mxArray *c3_t_y = NULL;
  real_T c3_t_hoistedGlobal;
  const mxArray *c3_u_y = NULL;
  real_T c3_u_hoistedGlobal;
  const mxArray *c3_v_y = NULL;
  real_T c3_v_hoistedGlobal;
  const mxArray *c3_w_y = NULL;
  real_T c3_w_hoistedGlobal;
  const mxArray *c3_x_y = NULL;
  real_T c3_x_hoistedGlobal;
  const mxArray *c3_y_y = NULL;
  real_T c3_y_hoistedGlobal;
  const mxArray *c3_ab_y = NULL;
  real_T c3_ab_hoistedGlobal;
  const mxArray *c3_bb_y = NULL;
  real_T c3_bb_hoistedGlobal;
  const mxArray *c3_cb_y = NULL;
  real_T c3_cb_hoistedGlobal;
  const mxArray *c3_db_y = NULL;
  real_T c3_db_hoistedGlobal;
  const mxArray *c3_eb_y = NULL;
  real_T c3_eb_hoistedGlobal;
  const mxArray *c3_fb_y = NULL;
  real_T c3_fb_hoistedGlobal;
  const mxArray *c3_gb_y = NULL;
  real_T c3_gb_hoistedGlobal;
  const mxArray *c3_hb_y = NULL;
  real_T c3_hb_hoistedGlobal;
  const mxArray *c3_ib_y = NULL;
  real_T c3_ib_hoistedGlobal;
  const mxArray *c3_jb_y = NULL;
  real_T c3_jb_hoistedGlobal;
  const mxArray *c3_kb_y = NULL;
  real_T c3_kb_hoistedGlobal;
  const mxArray *c3_lb_y = NULL;
  real_T c3_lb_hoistedGlobal;
  const mxArray *c3_mb_y = NULL;
  real_T c3_mb_hoistedGlobal;
  const mxArray *c3_nb_y = NULL;
  real_T c3_nb_hoistedGlobal;
  const mxArray *c3_ob_y = NULL;
  real_T c3_ob_hoistedGlobal;
  const mxArray *c3_pb_y = NULL;
  real_T c3_pb_hoistedGlobal;
  const mxArray *c3_qb_y = NULL;
  real_T c3_qb_hoistedGlobal;
  const mxArray *c3_rb_y = NULL;
  real_T c3_rb_hoistedGlobal;
  const mxArray *c3_sb_y = NULL;
  real_T c3_sb_hoistedGlobal;
  const mxArray *c3_tb_y = NULL;
  real_T c3_tb_hoistedGlobal;
  const mxArray *c3_ub_y = NULL;
  real_T c3_ub_hoistedGlobal;
  const mxArray *c3_vb_y = NULL;
  real_T c3_vb_hoistedGlobal;
  const mxArray *c3_wb_y = NULL;
  real_T c3_wb_hoistedGlobal;
  const mxArray *c3_xb_y = NULL;
  real_T c3_xb_hoistedGlobal;
  const mxArray *c3_yb_y = NULL;
  real_T c3_yb_hoistedGlobal;
  const mxArray *c3_ac_y = NULL;
  real_T c3_ac_hoistedGlobal;
  const mxArray *c3_bc_y = NULL;
  real_T c3_bc_hoistedGlobal;
  const mxArray *c3_cc_y = NULL;
  real_T c3_cc_hoistedGlobal;
  const mxArray *c3_dc_y = NULL;
  real_T c3_dc_hoistedGlobal;
  const mxArray *c3_ec_y = NULL;
  real_T c3_ec_hoistedGlobal;
  const mxArray *c3_fc_y = NULL;
  real_T c3_fc_hoistedGlobal;
  const mxArray *c3_gc_y = NULL;
  real_T c3_gc_hoistedGlobal;
  const mxArray *c3_hc_y = NULL;
  real_T c3_hc_hoistedGlobal;
  const mxArray *c3_ic_y = NULL;
  real_T c3_ic_hoistedGlobal;
  const mxArray *c3_jc_y = NULL;
  real_T c3_jc_hoistedGlobal;
  const mxArray *c3_kc_y = NULL;
  real_T c3_kc_hoistedGlobal;
  const mxArray *c3_lc_y = NULL;
  real_T c3_lc_hoistedGlobal;
  const mxArray *c3_mc_y = NULL;
  real_T c3_mc_hoistedGlobal;
  const mxArray *c3_nc_y = NULL;
  real_T c3_nc_hoistedGlobal;
  const mxArray *c3_oc_y = NULL;
  real_T c3_oc_hoistedGlobal;
  const mxArray *c3_pc_y = NULL;
  real_T c3_pc_hoistedGlobal;
  const mxArray *c3_qc_y = NULL;
  real_T c3_qc_hoistedGlobal;
  const mxArray *c3_rc_y = NULL;
  real_T c3_rc_hoistedGlobal;
  const mxArray *c3_sc_y = NULL;
  real_T c3_sc_hoistedGlobal;
  const mxArray *c3_tc_y = NULL;
  real_T c3_tc_hoistedGlobal;
  const mxArray *c3_uc_y = NULL;
  real_T c3_uc_hoistedGlobal;
  const mxArray *c3_vc_y = NULL;
  real_T c3_vc_hoistedGlobal;
  const mxArray *c3_wc_y = NULL;
  real_T c3_wc_hoistedGlobal;
  const mxArray *c3_xc_y = NULL;
  real_T c3_xc_hoistedGlobal;
  const mxArray *c3_yc_y = NULL;
  real_T c3_yc_hoistedGlobal;
  const mxArray *c3_ad_y = NULL;
  real_T c3_ad_hoistedGlobal;
  const mxArray *c3_bd_y = NULL;
  real_T c3_bd_hoistedGlobal;
  const mxArray *c3_cd_y = NULL;
  real_T c3_cd_hoistedGlobal;
  const mxArray *c3_dd_y = NULL;
  real_T c3_dd_hoistedGlobal;
  const mxArray *c3_ed_y = NULL;
  real_T c3_ed_hoistedGlobal;
  const mxArray *c3_fd_y = NULL;
  real_T c3_fd_hoistedGlobal;
  const mxArray *c3_gd_y = NULL;
  real_T c3_gd_hoistedGlobal;
  const mxArray *c3_hd_y = NULL;
  real_T c3_hd_hoistedGlobal;
  const mxArray *c3_id_y = NULL;
  real_T c3_id_hoistedGlobal;
  const mxArray *c3_jd_y = NULL;
  real_T c3_jd_hoistedGlobal;
  const mxArray *c3_kd_y = NULL;
  real_T c3_kd_hoistedGlobal;
  const mxArray *c3_ld_y = NULL;
  real_T c3_ld_hoistedGlobal;
  const mxArray *c3_md_y = NULL;
  real_T c3_md_hoistedGlobal;
  const mxArray *c3_nd_y = NULL;
  real_T c3_nd_hoistedGlobal;
  const mxArray *c3_od_y = NULL;
  real_T c3_od_hoistedGlobal;
  const mxArray *c3_pd_y = NULL;
  real_T c3_pd_hoistedGlobal;
  const mxArray *c3_qd_y = NULL;
  real_T c3_qd_hoistedGlobal;
  const mxArray *c3_rd_y = NULL;
  real_T c3_rd_hoistedGlobal;
  const mxArray *c3_sd_y = NULL;
  real_T c3_sd_hoistedGlobal;
  const mxArray *c3_td_y = NULL;
  real_T c3_td_hoistedGlobal;
  const mxArray *c3_ud_y = NULL;
  real_T c3_ud_hoistedGlobal;
  const mxArray *c3_vd_y = NULL;
  real_T c3_vd_hoistedGlobal;
  const mxArray *c3_wd_y = NULL;
  real_T c3_wd_hoistedGlobal;
  const mxArray *c3_xd_y = NULL;
  real_T c3_xd_hoistedGlobal;
  const mxArray *c3_yd_y = NULL;
  real_T c3_yd_hoistedGlobal;
  const mxArray *c3_ae_y = NULL;
  real_T c3_ae_hoistedGlobal;
  const mxArray *c3_be_y = NULL;
  real_T c3_be_hoistedGlobal;
  const mxArray *c3_ce_y = NULL;
  real_T c3_ce_hoistedGlobal;
  const mxArray *c3_de_y = NULL;
  real_T c3_de_hoistedGlobal;
  const mxArray *c3_ee_y = NULL;
  real_T c3_ee_hoistedGlobal;
  const mxArray *c3_fe_y = NULL;
  real_T c3_fe_hoistedGlobal;
  const mxArray *c3_ge_y = NULL;
  uint8_T c3_ge_hoistedGlobal;
  const mxArray *c3_he_y = NULL;
  uint8_T c3_he_hoistedGlobal;
  const mxArray *c3_ie_y = NULL;
  uint8_T c3_ie_hoistedGlobal;
  const mxArray *c3_je_y = NULL;
  uint8_T c3_je_hoistedGlobal;
  const mxArray *c3_ke_y = NULL;
  uint8_T c3_ke_hoistedGlobal;
  const mxArray *c3_le_y = NULL;
  uint8_T c3_le_hoistedGlobal;
  const mxArray *c3_me_y = NULL;
  uint8_T c3_me_hoistedGlobal;
  const mxArray *c3_ne_y = NULL;
  uint8_T c3_ne_hoistedGlobal;
  const mxArray *c3_oe_y = NULL;
  uint8_T c3_oe_hoistedGlobal;
  const mxArray *c3_pe_y = NULL;
  uint8_T c3_pe_hoistedGlobal;
  const mxArray *c3_qe_y = NULL;
  uint8_T c3_qe_hoistedGlobal;
  const mxArray *c3_re_y = NULL;
  uint8_T c3_re_hoistedGlobal;
  const mxArray *c3_se_y = NULL;
  uint8_T c3_se_hoistedGlobal;
  const mxArray *c3_te_y = NULL;
  uint8_T c3_te_hoistedGlobal;
  const mxArray *c3_ue_y = NULL;
  uint8_T c3_ue_hoistedGlobal;
  const mxArray *c3_ve_y = NULL;
  uint8_T c3_ve_hoistedGlobal;
  const mxArray *c3_we_y = NULL;
  uint8_T c3_we_hoistedGlobal;
  const mxArray *c3_xe_y = NULL;
  uint8_T c3_xe_hoistedGlobal;
  const mxArray *c3_ye_y = NULL;
  uint8_T c3_ye_hoistedGlobal;
  const mxArray *c3_af_y = NULL;
  uint8_T c3_af_hoistedGlobal;
  const mxArray *c3_bf_y = NULL;
  uint8_T c3_bf_hoistedGlobal;
  const mxArray *c3_cf_y = NULL;
  uint8_T c3_cf_hoistedGlobal;
  const mxArray *c3_df_y = NULL;
  uint8_T c3_df_hoistedGlobal;
  const mxArray *c3_ef_y = NULL;
  uint8_T c3_ef_hoistedGlobal;
  const mxArray *c3_ff_y = NULL;
  uint8_T c3_ff_hoistedGlobal;
  const mxArray *c3_gf_y = NULL;
  uint8_T c3_gf_hoistedGlobal;
  const mxArray *c3_hf_y = NULL;
  uint8_T c3_hf_hoistedGlobal;
  const mxArray *c3_if_y = NULL;
  uint8_T c3_if_hoistedGlobal;
  const mxArray *c3_jf_y = NULL;
  uint8_T c3_jf_hoistedGlobal;
  const mxArray *c3_kf_y = NULL;
  uint8_T c3_kf_hoistedGlobal;
  const mxArray *c3_lf_y = NULL;
  uint8_T c3_lf_hoistedGlobal;
  const mxArray *c3_mf_y = NULL;
  uint8_T c3_mf_hoistedGlobal;
  const mxArray *c3_nf_y = NULL;
  uint8_T c3_nf_hoistedGlobal;
  const mxArray *c3_of_y = NULL;
  uint8_T c3_of_hoistedGlobal;
  const mxArray *c3_pf_y = NULL;
  uint8_T c3_pf_hoistedGlobal;
  const mxArray *c3_qf_y = NULL;
  uint8_T c3_qf_hoistedGlobal;
  const mxArray *c3_rf_y = NULL;
  uint8_T c3_rf_hoistedGlobal;
  const mxArray *c3_sf_y = NULL;
  uint8_T c3_sf_hoistedGlobal;
  const mxArray *c3_tf_y = NULL;
  uint8_T c3_tf_hoistedGlobal;
  const mxArray *c3_uf_y = NULL;
  uint8_T c3_uf_hoistedGlobal;
  const mxArray *c3_vf_y = NULL;
  uint8_T c3_vf_hoistedGlobal;
  const mxArray *c3_wf_y = NULL;
  uint8_T c3_wf_hoistedGlobal;
  const mxArray *c3_xf_y = NULL;
  uint8_T c3_xf_hoistedGlobal;
  const mxArray *c3_yf_y = NULL;
  uint8_T c3_yf_hoistedGlobal;
  const mxArray *c3_ag_y = NULL;
  uint8_T c3_ag_hoistedGlobal;
  const mxArray *c3_bg_y = NULL;
  uint8_T c3_bg_hoistedGlobal;
  const mxArray *c3_cg_y = NULL;
  uint8_T c3_cg_hoistedGlobal;
  const mxArray *c3_dg_y = NULL;
  uint8_T c3_dg_hoistedGlobal;
  const mxArray *c3_eg_y = NULL;
  uint8_T c3_eg_hoistedGlobal;
  const mxArray *c3_fg_y = NULL;
  uint8_T c3_fg_hoistedGlobal;
  const mxArray *c3_gg_y = NULL;
  uint8_T c3_gg_hoistedGlobal;
  const mxArray *c3_hg_y = NULL;
  uint8_T c3_hg_hoistedGlobal;
  const mxArray *c3_ig_y = NULL;
  uint8_T c3_ig_hoistedGlobal;
  const mxArray *c3_jg_y = NULL;
  uint8_T c3_jg_hoistedGlobal;
  const mxArray *c3_kg_y = NULL;
  uint8_T c3_kg_hoistedGlobal;
  const mxArray *c3_lg_y = NULL;
  uint8_T c3_lg_hoistedGlobal;
  const mxArray *c3_mg_y = NULL;
  uint8_T c3_mg_hoistedGlobal;
  const mxArray *c3_ng_y = NULL;
  uint8_T c3_ng_hoistedGlobal;
  const mxArray *c3_og_y = NULL;
  uint8_T c3_og_hoistedGlobal;
  const mxArray *c3_pg_y = NULL;
  uint8_T c3_pg_hoistedGlobal;
  const mxArray *c3_qg_y = NULL;
  uint32_T c3_qg_hoistedGlobal;
  const mxArray *c3_rg_y = NULL;
  uint32_T c3_rg_hoistedGlobal;
  const mxArray *c3_sg_y = NULL;
  uint32_T c3_sg_hoistedGlobal;
  const mxArray *c3_tg_y = NULL;
  uint32_T c3_tg_hoistedGlobal;
  const mxArray *c3_ug_y = NULL;
  uint32_T c3_ug_hoistedGlobal;
  const mxArray *c3_vg_y = NULL;
  uint32_T c3_vg_hoistedGlobal;
  const mxArray *c3_wg_y = NULL;
  uint32_T c3_wg_hoistedGlobal;
  const mxArray *c3_xg_y = NULL;
  uint32_T c3_xg_hoistedGlobal;
  const mxArray *c3_yg_y = NULL;
  uint32_T c3_yg_hoistedGlobal;
  const mxArray *c3_ah_y = NULL;
  uint32_T c3_ah_hoistedGlobal;
  const mxArray *c3_bh_y = NULL;
  uint32_T c3_bh_hoistedGlobal;
  const mxArray *c3_ch_y = NULL;
  uint32_T c3_ch_hoistedGlobal;
  const mxArray *c3_dh_y = NULL;
  uint32_T c3_dh_hoistedGlobal;
  const mxArray *c3_eh_y = NULL;
  uint32_T c3_eh_hoistedGlobal;
  const mxArray *c3_fh_y = NULL;
  uint32_T c3_fh_hoistedGlobal;
  const mxArray *c3_gh_y = NULL;
  uint32_T c3_gh_hoistedGlobal;
  const mxArray *c3_hh_y = NULL;
  uint32_T c3_hh_hoistedGlobal;
  const mxArray *c3_ih_y = NULL;
  uint32_T c3_ih_hoistedGlobal;
  const mxArray *c3_jh_y = NULL;
  uint32_T c3_jh_hoistedGlobal;
  const mxArray *c3_kh_y = NULL;
  uint32_T c3_kh_hoistedGlobal;
  const mxArray *c3_lh_y = NULL;
  uint16_T c3_lh_hoistedGlobal;
  const mxArray *c3_mh_y = NULL;
  uint32_T c3_mh_hoistedGlobal;
  const mxArray *c3_nh_y = NULL;
  uint32_T c3_nh_hoistedGlobal;
  const mxArray *c3_oh_y = NULL;
  uint32_T c3_oh_hoistedGlobal;
  const mxArray *c3_ph_y = NULL;
  uint32_T c3_ph_hoistedGlobal;
  const mxArray *c3_qh_y = NULL;
  uint32_T c3_qh_hoistedGlobal;
  const mxArray *c3_rh_y = NULL;
  uint32_T c3_rh_hoistedGlobal;
  const mxArray *c3_sh_y = NULL;
  const mxArray *c3_th_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(194, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_as1;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_as2;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *chartInstance->c3_as3;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *chartInstance->c3_as4;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *chartInstance->c3_dag;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *chartInstance->c3_dp1;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *chartInstance->c3_dp10;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *chartInstance->c3_dp11;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *chartInstance->c3_dp12;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *chartInstance->c3_dp13;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = *chartInstance->c3_dp14;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_l_hoistedGlobal = *chartInstance->c3_dp15;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_m_hoistedGlobal = *chartInstance->c3_dp16;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_n_hoistedGlobal = *chartInstance->c3_dp17;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_o_hoistedGlobal = *chartInstance->c3_dp18;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_p_hoistedGlobal = *chartInstance->c3_dp19;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_q_hoistedGlobal = *chartInstance->c3_dp2;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_r_hoistedGlobal = *chartInstance->c3_dp20;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_s_hoistedGlobal = *chartInstance->c3_dp21;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_s_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_t_hoistedGlobal = *chartInstance->c3_dp22;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_t_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 19, c3_u_y);
  c3_u_hoistedGlobal = *chartInstance->c3_dp23;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_u_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 20, c3_v_y);
  c3_v_hoistedGlobal = *chartInstance->c3_dp24;
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_v_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 21, c3_w_y);
  c3_w_hoistedGlobal = *chartInstance->c3_dp25;
  c3_x_y = NULL;
  sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_w_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 22, c3_x_y);
  c3_x_hoistedGlobal = *chartInstance->c3_dp3;
  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_x_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 23, c3_y_y);
  c3_y_hoistedGlobal = *chartInstance->c3_dp4;
  c3_ab_y = NULL;
  sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_y_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 24, c3_ab_y);
  c3_ab_hoistedGlobal = *chartInstance->c3_dp5;
  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_ab_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 25, c3_bb_y);
  c3_bb_hoistedGlobal = *chartInstance->c3_dp6;
  c3_cb_y = NULL;
  sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_bb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 26, c3_cb_y);
  c3_cb_hoistedGlobal = *chartInstance->c3_dp7;
  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_create("y", &c3_cb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 27, c3_db_y);
  c3_db_hoistedGlobal = *chartInstance->c3_dp8;
  c3_eb_y = NULL;
  sf_mex_assign(&c3_eb_y, sf_mex_create("y", &c3_db_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 28, c3_eb_y);
  c3_eb_hoistedGlobal = *chartInstance->c3_dp9;
  c3_fb_y = NULL;
  sf_mex_assign(&c3_fb_y, sf_mex_create("y", &c3_eb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 29, c3_fb_y);
  c3_fb_hoistedGlobal = *chartInstance->c3_j1;
  c3_gb_y = NULL;
  sf_mex_assign(&c3_gb_y, sf_mex_create("y", &c3_fb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 30, c3_gb_y);
  c3_gb_hoistedGlobal = *chartInstance->c3_sayac;
  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y", &c3_gb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 31, c3_hb_y);
  c3_hb_hoistedGlobal = *chartInstance->c3_vn10;
  c3_ib_y = NULL;
  sf_mex_assign(&c3_ib_y, sf_mex_create("y", &c3_hb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 32, c3_ib_y);
  c3_ib_hoistedGlobal = *chartInstance->c3_vn11;
  c3_jb_y = NULL;
  sf_mex_assign(&c3_jb_y, sf_mex_create("y", &c3_ib_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 33, c3_jb_y);
  c3_jb_hoistedGlobal = *chartInstance->c3_vn12;
  c3_kb_y = NULL;
  sf_mex_assign(&c3_kb_y, sf_mex_create("y", &c3_jb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 34, c3_kb_y);
  c3_kb_hoistedGlobal = *chartInstance->c3_vn13;
  c3_lb_y = NULL;
  sf_mex_assign(&c3_lb_y, sf_mex_create("y", &c3_kb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 35, c3_lb_y);
  c3_lb_hoistedGlobal = *chartInstance->c3_vn14;
  c3_mb_y = NULL;
  sf_mex_assign(&c3_mb_y, sf_mex_create("y", &c3_lb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 36, c3_mb_y);
  c3_mb_hoistedGlobal = *chartInstance->c3_vn15;
  c3_nb_y = NULL;
  sf_mex_assign(&c3_nb_y, sf_mex_create("y", &c3_mb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 37, c3_nb_y);
  c3_nb_hoistedGlobal = *chartInstance->c3_vn16;
  c3_ob_y = NULL;
  sf_mex_assign(&c3_ob_y, sf_mex_create("y", &c3_nb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 38, c3_ob_y);
  c3_ob_hoistedGlobal = *chartInstance->c3_vn17;
  c3_pb_y = NULL;
  sf_mex_assign(&c3_pb_y, sf_mex_create("y", &c3_ob_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 39, c3_pb_y);
  c3_pb_hoistedGlobal = *chartInstance->c3_vn18;
  c3_qb_y = NULL;
  sf_mex_assign(&c3_qb_y, sf_mex_create("y", &c3_pb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 40, c3_qb_y);
  c3_qb_hoistedGlobal = *chartInstance->c3_vn19;
  c3_rb_y = NULL;
  sf_mex_assign(&c3_rb_y, sf_mex_create("y", &c3_qb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 41, c3_rb_y);
  c3_rb_hoistedGlobal = *chartInstance->c3_vn2;
  c3_sb_y = NULL;
  sf_mex_assign(&c3_sb_y, sf_mex_create("y", &c3_rb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 42, c3_sb_y);
  c3_sb_hoistedGlobal = *chartInstance->c3_vn20;
  c3_tb_y = NULL;
  sf_mex_assign(&c3_tb_y, sf_mex_create("y", &c3_sb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 43, c3_tb_y);
  c3_tb_hoistedGlobal = *chartInstance->c3_vn21;
  c3_ub_y = NULL;
  sf_mex_assign(&c3_ub_y, sf_mex_create("y", &c3_tb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 44, c3_ub_y);
  c3_ub_hoistedGlobal = *chartInstance->c3_vn22;
  c3_vb_y = NULL;
  sf_mex_assign(&c3_vb_y, sf_mex_create("y", &c3_ub_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 45, c3_vb_y);
  c3_vb_hoistedGlobal = *chartInstance->c3_vn23;
  c3_wb_y = NULL;
  sf_mex_assign(&c3_wb_y, sf_mex_create("y", &c3_vb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 46, c3_wb_y);
  c3_wb_hoistedGlobal = *chartInstance->c3_vn24;
  c3_xb_y = NULL;
  sf_mex_assign(&c3_xb_y, sf_mex_create("y", &c3_wb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 47, c3_xb_y);
  c3_xb_hoistedGlobal = *chartInstance->c3_vn25;
  c3_yb_y = NULL;
  sf_mex_assign(&c3_yb_y, sf_mex_create("y", &c3_xb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 48, c3_yb_y);
  c3_yb_hoistedGlobal = *chartInstance->c3_vn3;
  c3_ac_y = NULL;
  sf_mex_assign(&c3_ac_y, sf_mex_create("y", &c3_yb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 49, c3_ac_y);
  c3_ac_hoistedGlobal = *chartInstance->c3_vn4;
  c3_bc_y = NULL;
  sf_mex_assign(&c3_bc_y, sf_mex_create("y", &c3_ac_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 50, c3_bc_y);
  c3_bc_hoistedGlobal = *chartInstance->c3_vn5;
  c3_cc_y = NULL;
  sf_mex_assign(&c3_cc_y, sf_mex_create("y", &c3_bc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 51, c3_cc_y);
  c3_cc_hoistedGlobal = *chartInstance->c3_vn6;
  c3_dc_y = NULL;
  sf_mex_assign(&c3_dc_y, sf_mex_create("y", &c3_cc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 52, c3_dc_y);
  c3_dc_hoistedGlobal = *chartInstance->c3_vn7;
  c3_ec_y = NULL;
  sf_mex_assign(&c3_ec_y, sf_mex_create("y", &c3_dc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 53, c3_ec_y);
  c3_ec_hoistedGlobal = *chartInstance->c3_vn8;
  c3_fc_y = NULL;
  sf_mex_assign(&c3_fc_y, sf_mex_create("y", &c3_ec_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 54, c3_fc_y);
  c3_fc_hoistedGlobal = *chartInstance->c3_vn9;
  c3_gc_y = NULL;
  sf_mex_assign(&c3_gc_y, sf_mex_create("y", &c3_fc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 55, c3_gc_y);
  c3_gc_hoistedGlobal = *chartInstance->c3_vr1;
  c3_hc_y = NULL;
  sf_mex_assign(&c3_hc_y, sf_mex_create("y", &c3_gc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 56, c3_hc_y);
  c3_hc_hoistedGlobal = *chartInstance->c3_vr10;
  c3_ic_y = NULL;
  sf_mex_assign(&c3_ic_y, sf_mex_create("y", &c3_hc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 57, c3_ic_y);
  c3_ic_hoistedGlobal = *chartInstance->c3_vr11;
  c3_jc_y = NULL;
  sf_mex_assign(&c3_jc_y, sf_mex_create("y", &c3_ic_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 58, c3_jc_y);
  c3_jc_hoistedGlobal = *chartInstance->c3_vr12;
  c3_kc_y = NULL;
  sf_mex_assign(&c3_kc_y, sf_mex_create("y", &c3_jc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 59, c3_kc_y);
  c3_kc_hoistedGlobal = *chartInstance->c3_vr13;
  c3_lc_y = NULL;
  sf_mex_assign(&c3_lc_y, sf_mex_create("y", &c3_kc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 60, c3_lc_y);
  c3_lc_hoistedGlobal = *chartInstance->c3_vr14;
  c3_mc_y = NULL;
  sf_mex_assign(&c3_mc_y, sf_mex_create("y", &c3_lc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 61, c3_mc_y);
  c3_mc_hoistedGlobal = *chartInstance->c3_vr15;
  c3_nc_y = NULL;
  sf_mex_assign(&c3_nc_y, sf_mex_create("y", &c3_mc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 62, c3_nc_y);
  c3_nc_hoistedGlobal = *chartInstance->c3_vr16;
  c3_oc_y = NULL;
  sf_mex_assign(&c3_oc_y, sf_mex_create("y", &c3_nc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 63, c3_oc_y);
  c3_oc_hoistedGlobal = *chartInstance->c3_vr17;
  c3_pc_y = NULL;
  sf_mex_assign(&c3_pc_y, sf_mex_create("y", &c3_oc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 64, c3_pc_y);
  c3_pc_hoistedGlobal = *chartInstance->c3_vr18;
  c3_qc_y = NULL;
  sf_mex_assign(&c3_qc_y, sf_mex_create("y", &c3_pc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 65, c3_qc_y);
  c3_qc_hoistedGlobal = *chartInstance->c3_vr19;
  c3_rc_y = NULL;
  sf_mex_assign(&c3_rc_y, sf_mex_create("y", &c3_qc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 66, c3_rc_y);
  c3_rc_hoistedGlobal = *chartInstance->c3_vr2;
  c3_sc_y = NULL;
  sf_mex_assign(&c3_sc_y, sf_mex_create("y", &c3_rc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 67, c3_sc_y);
  c3_sc_hoistedGlobal = *chartInstance->c3_vr20;
  c3_tc_y = NULL;
  sf_mex_assign(&c3_tc_y, sf_mex_create("y", &c3_sc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 68, c3_tc_y);
  c3_tc_hoistedGlobal = *chartInstance->c3_vr21;
  c3_uc_y = NULL;
  sf_mex_assign(&c3_uc_y, sf_mex_create("y", &c3_tc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 69, c3_uc_y);
  c3_uc_hoistedGlobal = *chartInstance->c3_vr22;
  c3_vc_y = NULL;
  sf_mex_assign(&c3_vc_y, sf_mex_create("y", &c3_uc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 70, c3_vc_y);
  c3_vc_hoistedGlobal = *chartInstance->c3_vr23;
  c3_wc_y = NULL;
  sf_mex_assign(&c3_wc_y, sf_mex_create("y", &c3_vc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 71, c3_wc_y);
  c3_wc_hoistedGlobal = *chartInstance->c3_vr24;
  c3_xc_y = NULL;
  sf_mex_assign(&c3_xc_y, sf_mex_create("y", &c3_wc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 72, c3_xc_y);
  c3_xc_hoistedGlobal = *chartInstance->c3_vr25;
  c3_yc_y = NULL;
  sf_mex_assign(&c3_yc_y, sf_mex_create("y", &c3_xc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 73, c3_yc_y);
  c3_yc_hoistedGlobal = *chartInstance->c3_vr3;
  c3_ad_y = NULL;
  sf_mex_assign(&c3_ad_y, sf_mex_create("y", &c3_yc_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 74, c3_ad_y);
  c3_ad_hoistedGlobal = *chartInstance->c3_vr4;
  c3_bd_y = NULL;
  sf_mex_assign(&c3_bd_y, sf_mex_create("y", &c3_ad_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 75, c3_bd_y);
  c3_bd_hoistedGlobal = *chartInstance->c3_vr5;
  c3_cd_y = NULL;
  sf_mex_assign(&c3_cd_y, sf_mex_create("y", &c3_bd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 76, c3_cd_y);
  c3_cd_hoistedGlobal = *chartInstance->c3_vr6;
  c3_dd_y = NULL;
  sf_mex_assign(&c3_dd_y, sf_mex_create("y", &c3_cd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 77, c3_dd_y);
  c3_dd_hoistedGlobal = *chartInstance->c3_vr7;
  c3_ed_y = NULL;
  sf_mex_assign(&c3_ed_y, sf_mex_create("y", &c3_dd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 78, c3_ed_y);
  c3_ed_hoistedGlobal = *chartInstance->c3_vr8;
  c3_fd_y = NULL;
  sf_mex_assign(&c3_fd_y, sf_mex_create("y", &c3_ed_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 79, c3_fd_y);
  c3_fd_hoistedGlobal = *chartInstance->c3_vr9;
  c3_gd_y = NULL;
  sf_mex_assign(&c3_gd_y, sf_mex_create("y", &c3_fd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 80, c3_gd_y);
  c3_gd_hoistedGlobal = *chartInstance->c3_vs1;
  c3_hd_y = NULL;
  sf_mex_assign(&c3_hd_y, sf_mex_create("y", &c3_gd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 81, c3_hd_y);
  c3_hd_hoistedGlobal = *chartInstance->c3_vs10;
  c3_id_y = NULL;
  sf_mex_assign(&c3_id_y, sf_mex_create("y", &c3_hd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 82, c3_id_y);
  c3_id_hoistedGlobal = *chartInstance->c3_vs11;
  c3_jd_y = NULL;
  sf_mex_assign(&c3_jd_y, sf_mex_create("y", &c3_id_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 83, c3_jd_y);
  c3_jd_hoistedGlobal = *chartInstance->c3_vs12;
  c3_kd_y = NULL;
  sf_mex_assign(&c3_kd_y, sf_mex_create("y", &c3_jd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 84, c3_kd_y);
  c3_kd_hoistedGlobal = *chartInstance->c3_vs13;
  c3_ld_y = NULL;
  sf_mex_assign(&c3_ld_y, sf_mex_create("y", &c3_kd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 85, c3_ld_y);
  c3_ld_hoistedGlobal = *chartInstance->c3_vs14;
  c3_md_y = NULL;
  sf_mex_assign(&c3_md_y, sf_mex_create("y", &c3_ld_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 86, c3_md_y);
  c3_md_hoistedGlobal = *chartInstance->c3_vs15;
  c3_nd_y = NULL;
  sf_mex_assign(&c3_nd_y, sf_mex_create("y", &c3_md_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 87, c3_nd_y);
  c3_nd_hoistedGlobal = *chartInstance->c3_vs16;
  c3_od_y = NULL;
  sf_mex_assign(&c3_od_y, sf_mex_create("y", &c3_nd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 88, c3_od_y);
  c3_od_hoistedGlobal = *chartInstance->c3_vs17;
  c3_pd_y = NULL;
  sf_mex_assign(&c3_pd_y, sf_mex_create("y", &c3_od_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 89, c3_pd_y);
  c3_pd_hoistedGlobal = *chartInstance->c3_vs18;
  c3_qd_y = NULL;
  sf_mex_assign(&c3_qd_y, sf_mex_create("y", &c3_pd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 90, c3_qd_y);
  c3_qd_hoistedGlobal = *chartInstance->c3_vs19;
  c3_rd_y = NULL;
  sf_mex_assign(&c3_rd_y, sf_mex_create("y", &c3_qd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 91, c3_rd_y);
  c3_rd_hoistedGlobal = *chartInstance->c3_vs2;
  c3_sd_y = NULL;
  sf_mex_assign(&c3_sd_y, sf_mex_create("y", &c3_rd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 92, c3_sd_y);
  c3_sd_hoistedGlobal = *chartInstance->c3_vs20;
  c3_td_y = NULL;
  sf_mex_assign(&c3_td_y, sf_mex_create("y", &c3_sd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 93, c3_td_y);
  c3_td_hoistedGlobal = *chartInstance->c3_vs21;
  c3_ud_y = NULL;
  sf_mex_assign(&c3_ud_y, sf_mex_create("y", &c3_td_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 94, c3_ud_y);
  c3_ud_hoistedGlobal = *chartInstance->c3_vs22;
  c3_vd_y = NULL;
  sf_mex_assign(&c3_vd_y, sf_mex_create("y", &c3_ud_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 95, c3_vd_y);
  c3_vd_hoistedGlobal = *chartInstance->c3_vs23;
  c3_wd_y = NULL;
  sf_mex_assign(&c3_wd_y, sf_mex_create("y", &c3_vd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 96, c3_wd_y);
  c3_wd_hoistedGlobal = *chartInstance->c3_vs24;
  c3_xd_y = NULL;
  sf_mex_assign(&c3_xd_y, sf_mex_create("y", &c3_wd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 97, c3_xd_y);
  c3_xd_hoistedGlobal = *chartInstance->c3_vs25;
  c3_yd_y = NULL;
  sf_mex_assign(&c3_yd_y, sf_mex_create("y", &c3_xd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 98, c3_yd_y);
  c3_yd_hoistedGlobal = *chartInstance->c3_vs3;
  c3_ae_y = NULL;
  sf_mex_assign(&c3_ae_y, sf_mex_create("y", &c3_yd_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 99, c3_ae_y);
  c3_ae_hoistedGlobal = *chartInstance->c3_vs4;
  c3_be_y = NULL;
  sf_mex_assign(&c3_be_y, sf_mex_create("y", &c3_ae_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 100, c3_be_y);
  c3_be_hoistedGlobal = *chartInstance->c3_vs5;
  c3_ce_y = NULL;
  sf_mex_assign(&c3_ce_y, sf_mex_create("y", &c3_be_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 101, c3_ce_y);
  c3_ce_hoistedGlobal = *chartInstance->c3_vs6;
  c3_de_y = NULL;
  sf_mex_assign(&c3_de_y, sf_mex_create("y", &c3_ce_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 102, c3_de_y);
  c3_de_hoistedGlobal = *chartInstance->c3_vs7;
  c3_ee_y = NULL;
  sf_mex_assign(&c3_ee_y, sf_mex_create("y", &c3_de_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 103, c3_ee_y);
  c3_ee_hoistedGlobal = *chartInstance->c3_vs8;
  c3_fe_y = NULL;
  sf_mex_assign(&c3_fe_y, sf_mex_create("y", &c3_ee_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 104, c3_fe_y);
  c3_fe_hoistedGlobal = *chartInstance->c3_vs9;
  c3_ge_y = NULL;
  sf_mex_assign(&c3_ge_y, sf_mex_create("y", &c3_fe_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 105, c3_ge_y);
  c3_ge_hoistedGlobal = *chartInstance->c3_is_active_c3_ver_601;
  c3_he_y = NULL;
  sf_mex_assign(&c3_he_y, sf_mex_create("y", &c3_ge_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 106, c3_he_y);
  c3_he_hoistedGlobal = *chartInstance->c3_is_active_m1;
  c3_ie_y = NULL;
  sf_mex_assign(&c3_ie_y, sf_mex_create("y", &c3_he_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 107, c3_ie_y);
  c3_ie_hoistedGlobal = *chartInstance->c3_is_active_r1;
  c3_je_y = NULL;
  sf_mex_assign(&c3_je_y, sf_mex_create("y", &c3_ie_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 108, c3_je_y);
  c3_je_hoistedGlobal = *chartInstance->c3_is_active_r2;
  c3_ke_y = NULL;
  sf_mex_assign(&c3_ke_y, sf_mex_create("y", &c3_je_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 109, c3_ke_y);
  c3_ke_hoistedGlobal = *chartInstance->c3_is_active_r3;
  c3_le_y = NULL;
  sf_mex_assign(&c3_le_y, sf_mex_create("y", &c3_ke_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 110, c3_le_y);
  c3_le_hoistedGlobal = *chartInstance->c3_is_active_r4;
  c3_me_y = NULL;
  sf_mex_assign(&c3_me_y, sf_mex_create("y", &c3_le_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 111, c3_me_y);
  c3_me_hoistedGlobal = *chartInstance->c3_is_active_r5;
  c3_ne_y = NULL;
  sf_mex_assign(&c3_ne_y, sf_mex_create("y", &c3_me_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 112, c3_ne_y);
  c3_ne_hoistedGlobal = *chartInstance->c3_is_active_r6;
  c3_oe_y = NULL;
  sf_mex_assign(&c3_oe_y, sf_mex_create("y", &c3_ne_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 113, c3_oe_y);
  c3_oe_hoistedGlobal = *chartInstance->c3_is_active_r10;
  c3_pe_y = NULL;
  sf_mex_assign(&c3_pe_y, sf_mex_create("y", &c3_oe_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 114, c3_pe_y);
  c3_pe_hoistedGlobal = *chartInstance->c3_is_active_r8;
  c3_qe_y = NULL;
  sf_mex_assign(&c3_qe_y, sf_mex_create("y", &c3_pe_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 115, c3_qe_y);
  c3_qe_hoistedGlobal = *chartInstance->c3_is_active_r9;
  c3_re_y = NULL;
  sf_mex_assign(&c3_re_y, sf_mex_create("y", &c3_qe_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 116, c3_re_y);
  c3_re_hoistedGlobal = *chartInstance->c3_is_active_r7;
  c3_se_y = NULL;
  sf_mex_assign(&c3_se_y, sf_mex_create("y", &c3_re_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 117, c3_se_y);
  c3_se_hoistedGlobal = *chartInstance->c3_is_active_r11;
  c3_te_y = NULL;
  sf_mex_assign(&c3_te_y, sf_mex_create("y", &c3_se_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 118, c3_te_y);
  c3_te_hoistedGlobal = *chartInstance->c3_is_active_r17;
  c3_ue_y = NULL;
  sf_mex_assign(&c3_ue_y, sf_mex_create("y", &c3_te_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 119, c3_ue_y);
  c3_ue_hoistedGlobal = *chartInstance->c3_is_active_r12;
  c3_ve_y = NULL;
  sf_mex_assign(&c3_ve_y, sf_mex_create("y", &c3_ue_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 120, c3_ve_y);
  c3_ve_hoistedGlobal = *chartInstance->c3_is_active_r13;
  c3_we_y = NULL;
  sf_mex_assign(&c3_we_y, sf_mex_create("y", &c3_ve_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 121, c3_we_y);
  c3_we_hoistedGlobal = *chartInstance->c3_is_active_r14;
  c3_xe_y = NULL;
  sf_mex_assign(&c3_xe_y, sf_mex_create("y", &c3_we_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 122, c3_xe_y);
  c3_xe_hoistedGlobal = *chartInstance->c3_is_active_r15;
  c3_ye_y = NULL;
  sf_mex_assign(&c3_ye_y, sf_mex_create("y", &c3_xe_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 123, c3_ye_y);
  c3_ye_hoistedGlobal = *chartInstance->c3_is_active_r16;
  c3_af_y = NULL;
  sf_mex_assign(&c3_af_y, sf_mex_create("y", &c3_ye_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 124, c3_af_y);
  c3_af_hoistedGlobal = *chartInstance->c3_is_active_r18;
  c3_bf_y = NULL;
  sf_mex_assign(&c3_bf_y, sf_mex_create("y", &c3_af_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 125, c3_bf_y);
  c3_bf_hoistedGlobal = *chartInstance->c3_is_active_r19;
  c3_cf_y = NULL;
  sf_mex_assign(&c3_cf_y, sf_mex_create("y", &c3_bf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 126, c3_cf_y);
  c3_cf_hoistedGlobal = *chartInstance->c3_is_active_r20;
  c3_df_y = NULL;
  sf_mex_assign(&c3_df_y, sf_mex_create("y", &c3_cf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 127, c3_df_y);
  c3_df_hoistedGlobal = *chartInstance->c3_is_active_r21;
  c3_ef_y = NULL;
  sf_mex_assign(&c3_ef_y, sf_mex_create("y", &c3_df_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 128, c3_ef_y);
  c3_ef_hoistedGlobal = *chartInstance->c3_is_active_r22;
  c3_ff_y = NULL;
  sf_mex_assign(&c3_ff_y, sf_mex_create("y", &c3_ef_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 129, c3_ff_y);
  c3_ff_hoistedGlobal = *chartInstance->c3_is_active_r23;
  c3_gf_y = NULL;
  sf_mex_assign(&c3_gf_y, sf_mex_create("y", &c3_ff_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 130, c3_gf_y);
  c3_gf_hoistedGlobal = *chartInstance->c3_is_active_rdn;
  c3_hf_y = NULL;
  sf_mex_assign(&c3_hf_y, sf_mex_create("y", &c3_gf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 131, c3_hf_y);
  c3_hf_hoistedGlobal = *chartInstance->c3_is_active_r24;
  c3_if_y = NULL;
  sf_mex_assign(&c3_if_y, sf_mex_create("y", &c3_hf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 132, c3_if_y);
  c3_if_hoistedGlobal = *chartInstance->c3_is_active_r25;
  c3_jf_y = NULL;
  sf_mex_assign(&c3_jf_y, sf_mex_create("y", &c3_if_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 133, c3_jf_y);
  c3_jf_hoistedGlobal = *chartInstance->c3_is_active_tictoc;
  c3_kf_y = NULL;
  sf_mex_assign(&c3_kf_y, sf_mex_create("y", &c3_jf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 134, c3_kf_y);
  c3_kf_hoistedGlobal = *chartInstance->c3_is_active_dindan;
  c3_lf_y = NULL;
  sf_mex_assign(&c3_lf_y, sf_mex_create("y", &c3_kf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 135, c3_lf_y);
  c3_lf_hoistedGlobal = *chartInstance->c3_is_active_is;
  c3_mf_y = NULL;
  sf_mex_assign(&c3_mf_y, sf_mex_create("y", &c3_lf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 136, c3_mf_y);
  c3_mf_hoistedGlobal = *chartInstance->c3_is_c3_ver_601;
  c3_nf_y = NULL;
  sf_mex_assign(&c3_nf_y, sf_mex_create("y", &c3_mf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 137, c3_nf_y);
  c3_nf_hoistedGlobal = *chartInstance->c3_is_r1;
  c3_of_y = NULL;
  sf_mex_assign(&c3_of_y, sf_mex_create("y", &c3_nf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 138, c3_of_y);
  c3_of_hoistedGlobal = *chartInstance->c3_is_r2;
  c3_pf_y = NULL;
  sf_mex_assign(&c3_pf_y, sf_mex_create("y", &c3_of_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 139, c3_pf_y);
  c3_pf_hoistedGlobal = *chartInstance->c3_is_r3;
  c3_qf_y = NULL;
  sf_mex_assign(&c3_qf_y, sf_mex_create("y", &c3_pf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 140, c3_qf_y);
  c3_qf_hoistedGlobal = *chartInstance->c3_is_r4;
  c3_rf_y = NULL;
  sf_mex_assign(&c3_rf_y, sf_mex_create("y", &c3_qf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 141, c3_rf_y);
  c3_rf_hoistedGlobal = *chartInstance->c3_is_r5;
  c3_sf_y = NULL;
  sf_mex_assign(&c3_sf_y, sf_mex_create("y", &c3_rf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 142, c3_sf_y);
  c3_sf_hoistedGlobal = *chartInstance->c3_is_r6;
  c3_tf_y = NULL;
  sf_mex_assign(&c3_tf_y, sf_mex_create("y", &c3_sf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 143, c3_tf_y);
  c3_tf_hoistedGlobal = *chartInstance->c3_is_r10;
  c3_uf_y = NULL;
  sf_mex_assign(&c3_uf_y, sf_mex_create("y", &c3_tf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 144, c3_uf_y);
  c3_uf_hoistedGlobal = *chartInstance->c3_is_r8;
  c3_vf_y = NULL;
  sf_mex_assign(&c3_vf_y, sf_mex_create("y", &c3_uf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 145, c3_vf_y);
  c3_vf_hoistedGlobal = *chartInstance->c3_is_r9;
  c3_wf_y = NULL;
  sf_mex_assign(&c3_wf_y, sf_mex_create("y", &c3_vf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 146, c3_wf_y);
  c3_wf_hoistedGlobal = *chartInstance->c3_is_r7;
  c3_xf_y = NULL;
  sf_mex_assign(&c3_xf_y, sf_mex_create("y", &c3_wf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 147, c3_xf_y);
  c3_xf_hoistedGlobal = *chartInstance->c3_is_r11;
  c3_yf_y = NULL;
  sf_mex_assign(&c3_yf_y, sf_mex_create("y", &c3_xf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 148, c3_yf_y);
  c3_yf_hoistedGlobal = *chartInstance->c3_is_r17;
  c3_ag_y = NULL;
  sf_mex_assign(&c3_ag_y, sf_mex_create("y", &c3_yf_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 149, c3_ag_y);
  c3_ag_hoistedGlobal = *chartInstance->c3_is_r12;
  c3_bg_y = NULL;
  sf_mex_assign(&c3_bg_y, sf_mex_create("y", &c3_ag_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 150, c3_bg_y);
  c3_bg_hoistedGlobal = *chartInstance->c3_is_r13;
  c3_cg_y = NULL;
  sf_mex_assign(&c3_cg_y, sf_mex_create("y", &c3_bg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 151, c3_cg_y);
  c3_cg_hoistedGlobal = *chartInstance->c3_is_r14;
  c3_dg_y = NULL;
  sf_mex_assign(&c3_dg_y, sf_mex_create("y", &c3_cg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 152, c3_dg_y);
  c3_dg_hoistedGlobal = *chartInstance->c3_is_r15;
  c3_eg_y = NULL;
  sf_mex_assign(&c3_eg_y, sf_mex_create("y", &c3_dg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 153, c3_eg_y);
  c3_eg_hoistedGlobal = *chartInstance->c3_is_r16;
  c3_fg_y = NULL;
  sf_mex_assign(&c3_fg_y, sf_mex_create("y", &c3_eg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 154, c3_fg_y);
  c3_fg_hoistedGlobal = *chartInstance->c3_is_r18;
  c3_gg_y = NULL;
  sf_mex_assign(&c3_gg_y, sf_mex_create("y", &c3_fg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 155, c3_gg_y);
  c3_gg_hoistedGlobal = *chartInstance->c3_is_r19;
  c3_hg_y = NULL;
  sf_mex_assign(&c3_hg_y, sf_mex_create("y", &c3_gg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 156, c3_hg_y);
  c3_hg_hoistedGlobal = *chartInstance->c3_is_r20;
  c3_ig_y = NULL;
  sf_mex_assign(&c3_ig_y, sf_mex_create("y", &c3_hg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 157, c3_ig_y);
  c3_ig_hoistedGlobal = *chartInstance->c3_is_r21;
  c3_jg_y = NULL;
  sf_mex_assign(&c3_jg_y, sf_mex_create("y", &c3_ig_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 158, c3_jg_y);
  c3_jg_hoistedGlobal = *chartInstance->c3_is_r22;
  c3_kg_y = NULL;
  sf_mex_assign(&c3_kg_y, sf_mex_create("y", &c3_jg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 159, c3_kg_y);
  c3_kg_hoistedGlobal = *chartInstance->c3_is_r23;
  c3_lg_y = NULL;
  sf_mex_assign(&c3_lg_y, sf_mex_create("y", &c3_kg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 160, c3_lg_y);
  c3_lg_hoistedGlobal = *chartInstance->c3_is_r24;
  c3_mg_y = NULL;
  sf_mex_assign(&c3_mg_y, sf_mex_create("y", &c3_lg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 161, c3_mg_y);
  c3_mg_hoistedGlobal = *chartInstance->c3_is_r25;
  c3_ng_y = NULL;
  sf_mex_assign(&c3_ng_y, sf_mex_create("y", &c3_mg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 162, c3_ng_y);
  c3_ng_hoistedGlobal = *chartInstance->c3_is_tictoc;
  c3_og_y = NULL;
  sf_mex_assign(&c3_og_y, sf_mex_create("y", &c3_ng_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 163, c3_og_y);
  c3_og_hoistedGlobal = *chartInstance->c3_is_dindan;
  c3_pg_y = NULL;
  sf_mex_assign(&c3_pg_y, sf_mex_create("y", &c3_og_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 164, c3_pg_y);
  c3_pg_hoistedGlobal = *chartInstance->c3_is_is;
  c3_qg_y = NULL;
  sf_mex_assign(&c3_qg_y, sf_mex_create("y", &c3_pg_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 165, c3_qg_y);
  c3_qg_hoistedGlobal = *chartInstance->c3_temporalCounter_i10;
  c3_rg_y = NULL;
  sf_mex_assign(&c3_rg_y, sf_mex_create("y", &c3_qg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 166, c3_rg_y);
  c3_rg_hoistedGlobal = *chartInstance->c3_temporalCounter_i7;
  c3_sg_y = NULL;
  sf_mex_assign(&c3_sg_y, sf_mex_create("y", &c3_rg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 167, c3_sg_y);
  c3_sg_hoistedGlobal = *chartInstance->c3_temporalCounter_i2;
  c3_tg_y = NULL;
  sf_mex_assign(&c3_tg_y, sf_mex_create("y", &c3_sg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 168, c3_tg_y);
  c3_tg_hoistedGlobal = *chartInstance->c3_temporalCounter_i5;
  c3_ug_y = NULL;
  sf_mex_assign(&c3_ug_y, sf_mex_create("y", &c3_tg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 169, c3_ug_y);
  c3_ug_hoistedGlobal = *chartInstance->c3_temporalCounter_i20;
  c3_vg_y = NULL;
  sf_mex_assign(&c3_vg_y, sf_mex_create("y", &c3_ug_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 170, c3_vg_y);
  c3_vg_hoistedGlobal = *chartInstance->c3_temporalCounter_i3;
  c3_wg_y = NULL;
  sf_mex_assign(&c3_wg_y, sf_mex_create("y", &c3_vg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 171, c3_wg_y);
  c3_wg_hoistedGlobal = *chartInstance->c3_temporalCounter_i4;
  c3_xg_y = NULL;
  sf_mex_assign(&c3_xg_y, sf_mex_create("y", &c3_wg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 172, c3_xg_y);
  c3_xg_hoistedGlobal = *chartInstance->c3_temporalCounter_i21;
  c3_yg_y = NULL;
  sf_mex_assign(&c3_yg_y, sf_mex_create("y", &c3_xg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 173, c3_yg_y);
  c3_yg_hoistedGlobal = *chartInstance->c3_temporalCounter_i16;
  c3_ah_y = NULL;
  sf_mex_assign(&c3_ah_y, sf_mex_create("y", &c3_yg_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 174, c3_ah_y);
  c3_ah_hoistedGlobal = *chartInstance->c3_temporalCounter_i24;
  c3_bh_y = NULL;
  sf_mex_assign(&c3_bh_y, sf_mex_create("y", &c3_ah_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 175, c3_bh_y);
  c3_bh_hoistedGlobal = *chartInstance->c3_temporalCounter_i19;
  c3_ch_y = NULL;
  sf_mex_assign(&c3_ch_y, sf_mex_create("y", &c3_bh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 176, c3_ch_y);
  c3_ch_hoistedGlobal = *chartInstance->c3_temporalCounter_i22;
  c3_dh_y = NULL;
  sf_mex_assign(&c3_dh_y, sf_mex_create("y", &c3_ch_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 177, c3_dh_y);
  c3_dh_hoistedGlobal = *chartInstance->c3_temporalCounter_i12;
  c3_eh_y = NULL;
  sf_mex_assign(&c3_eh_y, sf_mex_create("y", &c3_dh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 178, c3_eh_y);
  c3_eh_hoistedGlobal = *chartInstance->c3_temporalCounter_i14;
  c3_fh_y = NULL;
  sf_mex_assign(&c3_fh_y, sf_mex_create("y", &c3_eh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 179, c3_fh_y);
  c3_fh_hoistedGlobal = *chartInstance->c3_temporalCounter_i8;
  c3_gh_y = NULL;
  sf_mex_assign(&c3_gh_y, sf_mex_create("y", &c3_fh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 180, c3_gh_y);
  c3_gh_hoistedGlobal = *chartInstance->c3_temporalCounter_i11;
  c3_hh_y = NULL;
  sf_mex_assign(&c3_hh_y, sf_mex_create("y", &c3_gh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 181, c3_hh_y);
  c3_hh_hoistedGlobal = *chartInstance->c3_temporalCounter_i15;
  c3_ih_y = NULL;
  sf_mex_assign(&c3_ih_y, sf_mex_create("y", &c3_hh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 182, c3_ih_y);
  c3_ih_hoistedGlobal = *chartInstance->c3_temporalCounter_i23;
  c3_jh_y = NULL;
  sf_mex_assign(&c3_jh_y, sf_mex_create("y", &c3_ih_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 183, c3_jh_y);
  c3_jh_hoistedGlobal = *chartInstance->c3_temporalCounter_i9;
  c3_kh_y = NULL;
  sf_mex_assign(&c3_kh_y, sf_mex_create("y", &c3_jh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 184, c3_kh_y);
  c3_kh_hoistedGlobal = *chartInstance->c3_temporalCounter_i25;
  c3_lh_y = NULL;
  sf_mex_assign(&c3_lh_y, sf_mex_create("y", &c3_kh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 185, c3_lh_y);
  c3_lh_hoistedGlobal = *chartInstance->c3_temporalCounter_i26;
  c3_mh_y = NULL;
  sf_mex_assign(&c3_mh_y, sf_mex_create("y", &c3_lh_hoistedGlobal, 5, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 186, c3_mh_y);
  c3_mh_hoistedGlobal = *chartInstance->c3_temporalCounter_i13;
  c3_nh_y = NULL;
  sf_mex_assign(&c3_nh_y, sf_mex_create("y", &c3_mh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 187, c3_nh_y);
  c3_nh_hoistedGlobal = *chartInstance->c3_temporalCounter_i1;
  c3_oh_y = NULL;
  sf_mex_assign(&c3_oh_y, sf_mex_create("y", &c3_nh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 188, c3_oh_y);
  c3_oh_hoistedGlobal = *chartInstance->c3_temporalCounter_i6;
  c3_ph_y = NULL;
  sf_mex_assign(&c3_ph_y, sf_mex_create("y", &c3_oh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 189, c3_ph_y);
  c3_ph_hoistedGlobal = *chartInstance->c3_temporalCounter_i17;
  c3_qh_y = NULL;
  sf_mex_assign(&c3_qh_y, sf_mex_create("y", &c3_ph_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 190, c3_qh_y);
  c3_qh_hoistedGlobal = *chartInstance->c3_temporalCounter_i18;
  c3_rh_y = NULL;
  sf_mex_assign(&c3_rh_y, sf_mex_create("y", &c3_qh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 191, c3_rh_y);
  c3_rh_hoistedGlobal = *chartInstance->c3_previousTicks;
  c3_sh_y = NULL;
  sf_mex_assign(&c3_sh_y, sf_mex_create("y", &c3_rh_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 192, c3_sh_y);
  c3_th_y = NULL;
  sf_mex_assign(&c3_th_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 91), false);
  sf_mex_setcell(c3_y, 193, c3_th_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_st)
{
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_st));
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_ver_601(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_ver_601(SFc3_ver_601InstanceStruct *
  chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if ((*chartInstance->c3_is_r1 == c3_IN_Off) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 6) == 0.0)) {
      *chartInstance->c3_temporalCounter_i13 = 0U;
    }

    if ((*chartInstance->c3_is_r1 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 7) == 0.0)) {
      *chartInstance->c3_temporalCounter_i13 = 0U;
    }

    if ((*chartInstance->c3_is_r2 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 11) == 0.0)) {
      *chartInstance->c3_temporalCounter_i10 = 0U;
    }

    if ((*chartInstance->c3_is_r3 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 15) == 0.0)) {
      *chartInstance->c3_temporalCounter_i7 = 0U;
    }

    if ((*chartInstance->c3_is_r4 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 19) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_r4 == c3_IN_as1) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 20) == 0.0)) {
      *chartInstance->c3_temporalCounter_i1 = 0U;
    }

    if ((*chartInstance->c3_is_r5 == c3_b_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 25) == 0.0)) {
      *chartInstance->c3_temporalCounter_i2 = 0U;
    }

    if ((*chartInstance->c3_is_r6 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 29) == 0.0)) {
      *chartInstance->c3_temporalCounter_i5 = 0U;
    }

    if ((*chartInstance->c3_is_r7 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 33) == 0.0)) {
      *chartInstance->c3_temporalCounter_i6 = 0U;
    }

    if ((*chartInstance->c3_is_r7 == c3_IN_as2) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 34) == 0.0)) {
      *chartInstance->c3_temporalCounter_i6 = 0U;
    }

    if ((*chartInstance->c3_is_r8 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 38) == 0.0)) {
      *chartInstance->c3_temporalCounter_i3 = 0U;
    }

    if ((*chartInstance->c3_is_r9 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 42) == 0.0)) {
      *chartInstance->c3_temporalCounter_i4 = 0U;
    }

    if ((*chartInstance->c3_is_r10 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 46) == 0.0)) {
      *chartInstance->c3_temporalCounter_i20 = 0U;
    }

    if ((*chartInstance->c3_is_r11 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 50) == 0.0)) {
      *chartInstance->c3_temporalCounter_i21 = 0U;
    }

    if ((*chartInstance->c3_is_r12 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 54) == 0.0)) {
      *chartInstance->c3_temporalCounter_i17 = 0U;
    }

    if ((*chartInstance->c3_is_r12 == c3_IN_as3) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 55) == 0.0)) {
      *chartInstance->c3_temporalCounter_i17 = 0U;
    }

    if ((*chartInstance->c3_is_r13 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 59) == 0.0)) {
      *chartInstance->c3_temporalCounter_i24 = 0U;
    }

    if ((*chartInstance->c3_is_r14 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 63) == 0.0)) {
      *chartInstance->c3_temporalCounter_i19 = 0U;
    }

    if ((*chartInstance->c3_is_r17 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 67) == 0.0)) {
      *chartInstance->c3_temporalCounter_i16 = 0U;
    }

    if ((*chartInstance->c3_is_r18 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 71) == 0.0)) {
      *chartInstance->c3_temporalCounter_i12 = 0U;
    }

    if ((*chartInstance->c3_is_r19 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 75) == 0.0)) {
      *chartInstance->c3_temporalCounter_i14 = 0U;
    }

    if ((*chartInstance->c3_is_r20 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 79) == 0.0)) {
      *chartInstance->c3_temporalCounter_i8 = 0U;
    }

    if ((*chartInstance->c3_is_r21 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 83) == 0.0)) {
      *chartInstance->c3_temporalCounter_i11 = 0U;
    }

    if ((*chartInstance->c3_is_r22 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 87) == 0.0)) {
      *chartInstance->c3_temporalCounter_i15 = 0U;
    }

    if ((*chartInstance->c3_is_r24 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 91) == 0.0)) {
      *chartInstance->c3_temporalCounter_i9 = 0U;
    }

    if ((*chartInstance->c3_is_r15 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 95) == 0.0)) {
      *chartInstance->c3_temporalCounter_i18 = 0U;
    }

    if ((*chartInstance->c3_is_r15 == c3_IN_as4) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 96) == 0.0)) {
      *chartInstance->c3_temporalCounter_i18 = 0U;
    }

    if ((*chartInstance->c3_is_r16 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 100) == 0.0)) {
      *chartInstance->c3_temporalCounter_i22 = 0U;
    }

    if ((*chartInstance->c3_is_r23 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 104) == 0.0)) {
      *chartInstance->c3_temporalCounter_i23 = 0U;
    }

    if ((*chartInstance->c3_is_r25 == c3_IN_On) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 108) == 0.0)) {
      *chartInstance->c3_temporalCounter_i25 = 0U;
    }

    if ((*chartInstance->c3_is_dindan == c3_IN_din) && (sf_mex_sub
         (chartInstance->c3_setSimStateSideEffectsInfo,
          "setSimStateSideEffectsInfo", 1, 125) == 0.0)) {
      *chartInstance->c3_temporalCounter_i26 = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  c3_set_sim_state_side_effects_c3_ver_601(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  *chartInstance->c3_presentTicks = (uint32_T)muDoubleScalarFloor((_sfTime_ -
    sf_get_start_time(chartInstance->S)) / 0.1 + 0.5);
  *chartInstance->c3_elapsedTicks = *chartInstance->c3_presentTicks -
    *chartInstance->c3_previousTicks;
  *chartInstance->c3_previousTicks = *chartInstance->c3_presentTicks;
  *chartInstance->c3_temporalCounter_i1 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i2 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i3 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i4 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i5 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i6 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i7 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i8 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i9 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i10 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i11 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i12 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i13 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i14 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i15 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i16 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i17 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i18 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i19 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i20 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i21 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i22 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i23 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i24 += *chartInstance->c3_elapsedTicks;
  *chartInstance->c3_temporalCounter_i25 += *chartInstance->c3_elapsedTicks;
  if ((uint32_T)*chartInstance->c3_temporalCounter_i26 +
      *chartInstance->c3_elapsedTicks <= 16383U) {
    *chartInstance->c3_temporalCounter_i26 = (uint16_T)((uint32_T)
      *chartInstance->c3_temporalCounter_i26 + *chartInstance->c3_elapsedTicks);
  } else {
    *chartInstance->c3_temporalCounter_i26 = 16383U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0, *chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_yuk, 110U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_s, 109U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_d2, 108U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_random, 107U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_asan4, 106U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_asan3, 105U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_asan2, 104U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_asan1, 103U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_d1, 102U);
  *chartInstance->c3_sfEvent = c3_event_trig;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c3_event_trig,
               *chartInstance->c3_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  if (*chartInstance->c3_is_active_c3_ver_601 == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_c3_ver_601 = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_c3_ver_601 = c3_IN_m3;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_m1 = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
    c3_enter_internal_m1(chartInstance);
    *chartInstance->c3_is_active_rdn = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 111U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_is = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 115U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 125U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_is = c3_IN_is_secim;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_dindan = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 112U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 127U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_dindan = c3_IN_din;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 114U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_temporalCounter_i26 = 0U;
    if ((*chartInstance->c3_is_active_c3_ver_601 == 1U) &&
        (!(*chartInstance->c3_is_c3_ver_601 == c3_IN_m3))) {
      sf_state_inconsistency_error(chartInstance->S, 0);
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    c3_m1(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 111U,
                 *chartInstance->c3_sfEvent);
    c3_is(chartInstance);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 112U,
                 *chartInstance->c3_sfEvent);
    switch (*chartInstance->c3_is_dindan) {
     case c3_IN_dan:
      CV_STATE_EVAL(112, 0, c3_IN_dan);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 126U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_dindan = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 113U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_dindan = c3_IN_din;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 114U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i26 = 0U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 113U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_din:
      CV_STATE_EVAL(112, 0, c3_IN_din);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 124U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_xg_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_IF(124, 0, 0, *chartInstance->c3_temporalCounter_i26 >= 9600))
      {
        c3_out = true;
      } else {
        c3_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 124U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_dindan = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 114U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_dindan = c3_IN_dan;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 113U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_sd_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U,
          c3_b_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U,
          c3_b_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[89U]) {
          sf_read_before_write_error(chartInstance->S, 27U, 513U, 13, 5);
        }

        if (!chartInstance->c3_dataWrittenToVector[88U]) {
          sf_read_before_write_error(chartInstance->S, 0U, 513U, 19, 3);
        }

        *chartInstance->c3_sayac += *chartInstance->c3_dag;
        chartInstance->c3_dataWrittenToVector[89U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 114U,
                     *chartInstance->c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 114U, *chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(112, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c3_is_dindan = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 113U, *chartInstance->c3_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 112U, *chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 111U, *chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c3_event_trig,
               *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc3_ver_601(SFc3_ver_601InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_enter_internal_m1(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  uint32_T c3_f_debug_family_var_map[2];
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_h_debug_family_var_map[2];
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  uint32_T c3_i_debug_family_var_map[2];
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  *chartInstance->c3_is_active_r1 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r1(chartInstance);
  *chartInstance->c3_is_active_r2 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 49U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r2(chartInstance);
  *chartInstance->c3_is_active_r3 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 77U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r3(chartInstance);
  *chartInstance->c3_is_active_r4 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 81U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r4(chartInstance);
  *chartInstance->c3_is_active_r5 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 86U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r5(chartInstance);
  *chartInstance->c3_is_active_r6 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 91U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r6(chartInstance);
  *chartInstance->c3_is_active_r7 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 95U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r7(chartInstance);
  *chartInstance->c3_is_active_r8 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 100U, *chartInstance->c3_sfEvent);
  c3_enter_internal_r8(chartInstance);
  *chartInstance->c3_is_active_r9 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 104U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r9 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 106U, *chartInstance->c3_sfEvent);
  c3_d_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r10 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r10 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_tc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr10 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr10, 53U);
  *chartInstance->c3_dp10 = 0.0;
  chartInstance->c3_dataWrittenToVector[21U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp10, 2U);
  *chartInstance->c3_vs10 = 0.0;
  chartInstance->c3_dataWrittenToVector[23U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs10, 78U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_active_r11 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r11 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
  c3_q_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r12 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 51U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r12 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c3_sfEvent);
  c3_n_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r13 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 57U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r13 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c3_sfEvent);
  c3_r_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r14 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 24U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 61U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r14 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *chartInstance->c3_sfEvent);
  c3_p_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r17 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 37U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_if_debug_family_names,
    c3_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vn17 = 2.0;
  chartInstance->c3_dataWrittenToVector[39U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn17, 35U);
  *chartInstance->c3_vs17 = 0.0;
  chartInstance->c3_dataWrittenToVector[35U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs17, 85U);
  *chartInstance->c3_dp17 = 0.0;
  chartInstance->c3_dataWrittenToVector[40U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp17, 9U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_r17 = c3_IN_On;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_temporalCounter_i16 = 0U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_bc_debug_family_names,
    c3_c_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr17 = 1.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr17, 60U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_active_r18 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 41U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 75U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r18 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *chartInstance->c3_sfEvent);
  c3_l_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r19 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 45U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 84U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_df_debug_family_names,
    c3_d_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vn19 = 1.0;
  chartInstance->c3_dataWrittenToVector[12U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn19, 37U);
  *chartInstance->c3_vs19 = 0.0;
  chartInstance->c3_dataWrittenToVector[13U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs19, 87U);
  *chartInstance->c3_dp19 = 0.0;
  chartInstance->c3_dataWrittenToVector[90U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp19, 11U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_r19 = c3_IN_On;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_temporalCounter_i14 = 0U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ub_debug_family_names,
    c3_e_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr19 = 1.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr19, 62U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_active_r20 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 53U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r20 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *chartInstance->c3_sfEvent);
  c3_h_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r21 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 57U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 90U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r21 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c3_sfEvent);
  c3_k_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r22 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 61U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 95U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r22 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, *chartInstance->c3_sfEvent);
  c3_m_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r24 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 69U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 105U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r24 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, *chartInstance->c3_sfEvent);
  c3_i_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r15 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 28U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 65U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r15 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *chartInstance->c3_sfEvent);
  c3_o_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_r16 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 33U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 74U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_cg_debug_family_names,
    c3_f_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vn16 = 3.0;
  chartInstance->c3_dataWrittenToVector[30U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn16, 34U);
  *chartInstance->c3_vs16 = 0.0;
  chartInstance->c3_dataWrittenToVector[42U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs16, 84U);
  *chartInstance->c3_dp16 = 0.0;
  chartInstance->c3_dataWrittenToVector[26U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp16, 8U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_r16 = c3_IN_On;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_temporalCounter_i22 = 0U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_xc_debug_family_names,
    c3_g_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr16 = 1.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr16, 59U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_active_r23 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 65U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 100U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_fg_debug_family_names,
    c3_h_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vn23 = 4.0;
  chartInstance->c3_dataWrittenToVector[71U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn23, 42U);
  *chartInstance->c3_vs23 = 0.0;
  chartInstance->c3_dataWrittenToVector[68U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs23, 92U);
  *chartInstance->c3_dp23 = 0.0;
  chartInstance->c3_dataWrittenToVector[70U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp23, 16U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_r23 = c3_IN_On;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_temporalCounter_i23 = 0U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_bd_debug_family_names,
    c3_i_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr23 = 1.0;
  chartInstance->c3_dataWrittenToVector[69U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr23, 67U);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_is_active_r25 = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 73U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 108U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r25 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 75U, *chartInstance->c3_sfEvent);
  c3_s_enter_atomic_Off(chartInstance);
  *chartInstance->c3_is_active_tictoc = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 108U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 110U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_tictoc = c3_IN_tic;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
}

static void c3_m1(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *chartInstance->c3_sfEvent);
  c3_r1(chartInstance);
  c3_r2(chartInstance);
  c3_r3(chartInstance);
  c3_r4(chartInstance);
  c3_r5(chartInstance);
  c3_r6(chartInstance);
  c3_r7(chartInstance);
  c3_r8(chartInstance);
  c3_r9(chartInstance);
  c3_r10(chartInstance);
  c3_r11(chartInstance);
  c3_r12(chartInstance);
  c3_r13(chartInstance);
  c3_r14(chartInstance);
  c3_r17(chartInstance);
  c3_r18(chartInstance);
  c3_r19(chartInstance);
  c3_r20(chartInstance);
  c3_r21(chartInstance);
  c3_r22(chartInstance);
  c3_r24(chartInstance);
  c3_r15(chartInstance);
  c3_r16(chartInstance);
  c3_r23(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 73U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r25) {
   case c3_IN_Next:
    CV_STATE_EVAL(73, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 106U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r25 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r25 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 75U, *chartInstance->c3_sfEvent);
    c3_s_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 74U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(73, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 107U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_lg_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[80U]) {
      sf_read_before_write_error(chartInstance->S, 69U, 402U, 1, 4);
    }

    if (CV_EML_IF(107, 0, 0, CV_RELATIONAL_EVAL(5U, 107U, 0,
          *chartInstance->c3_vr25, 1.0, -1, 0U, *chartInstance->c3_vr25 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 107U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r25 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 75U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r25 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 76U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i25 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_hd_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr25 = 1.0;
      chartInstance->c3_dataWrittenToVector[80U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr25, 69U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 75U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 75U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(73, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 109U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_kg_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(109, 0, 0, *chartInstance->c3_temporalCounter_i25 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 404U, 1, 13))) {
      if (CV_EML_COND(109, 0, 1, CV_RELATIONAL_EVAL(5U, 109U, 0,
            *chartInstance->c3_vr23, 0.0, -1, 0U, *chartInstance->c3_vr23 == 0.0)))
      {
        CV_EML_MCDC(109, 0, 0, true);
        CV_EML_IF(109, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[69U]) {
        sf_read_before_write_error(chartInstance->S, 67U, 404U, 17, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(109, 0, 0, false);
      CV_EML_IF(109, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r25 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 76U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r25 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 74U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_id_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr23 = 1.0;
      chartInstance->c3_dataWrittenToVector[69U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr23, 67U);
      if (!chartInstance->c3_dataWrittenToVector[83U]) {
        sf_read_before_write_error(chartInstance->S, 18U, 407U, 26, 4);
      }

      *chartInstance->c3_dp23 = *chartInstance->c3_dp25;
      chartInstance->c3_dataWrittenToVector[70U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp23, 16U);
      if (!chartInstance->c3_dataWrittenToVector[82U]) {
        sf_read_before_write_error(chartInstance->S, 44U, 407U, 38, 4);
      }

      *chartInstance->c3_vn23 = *chartInstance->c3_vn25;
      chartInstance->c3_dataWrittenToVector[71U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn23, 42U);
      if (!chartInstance->c3_dataWrittenToVector[81U]) {
        sf_read_before_write_error(chartInstance->S, 94U, 407U, 50, 4);
      }

      *chartInstance->c3_vs23 = *chartInstance->c3_vs25;
      chartInstance->c3_dataWrittenToVector[68U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs23, 92U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 76U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 76U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(73, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r25 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 74U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 73U, *chartInstance->c3_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 108U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_tictoc) {
   case c3_IN_tic:
    CV_STATE_EVAL(108, 0, c3_IN_tic);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 111U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_te_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    c3_color1(chartInstance);
    _SFD_SYMBOL_SCOPE_POP();
    *chartInstance->c3_is_tictoc = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_tictoc = c3_IN_toc;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 110U, *chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 109U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_toc:
    CV_STATE_EVAL(108, 0, c3_IN_toc);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 112U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_tictoc = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 110U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_tictoc = c3_IN_tic;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 110U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(108, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_tictoc = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 109U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 108U, *chartInstance->c3_sfEvent);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c3_sfEvent);
}

static void c3_enter_internal_r4(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r4 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 83U, *chartInstance->c3_sfEvent);
  c3_enter_atomic_Off(chartInstance);
}

static void c3_r4(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  uint32_T c3_c_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  uint32_T c3_e_debug_family_var_map[3];
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  uint32_T c3_f_debug_family_var_map[2];
  real_T c3_e_nargout = 1.0;
  real_T c3_f_nargin = 0.0;
  boolean_T c3_d_out;
  real_T c3_f_nargout = 0.0;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_h_debug_family_var_map[2];
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 81U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r4) {
   case c3_IN_Next:
    CV_STATE_EVAL(81, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r4 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 83U, *chartInstance->c3_sfEvent);
    c3_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 82U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(81, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 14U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ud_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      sf_read_before_write_error(chartInstance->S, 71U, 45U, 1, 3);
    }

    if (CV_EML_IF(14, 0, 0, CV_RELATIONAL_EVAL(5U, 14U, 0,
          *chartInstance->c3_vr4, 1.0, -1, 0U, *chartInstance->c3_vr4 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 83U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r4 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 84U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i1 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
        c3_f_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr4 = 1.0;
      chartInstance->c3_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr4, 71U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 83U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 83U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(81, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 47U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_vd_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[45U]) {
      sf_read_before_write_error(chartInstance->S, 20U, 124U, 1, 3);
    }

    if (CV_EML_COND(47, 0, 0, CV_RELATIONAL_EVAL(5U, 47U, 0,
          *chartInstance->c3_dp4, 1.0, -1, 0U, *chartInstance->c3_dp4 == 1.0)) &&
        CV_EML_COND(47, 0, 1, *chartInstance->c3_temporalCounter_i1 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d2 * 10.0), 124U, 10, 13))) {
      CV_EML_MCDC(47, 0, 0, true);
      CV_EML_IF(47, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(47, 0, 0, false);
      CV_EML_IF(47, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 47U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 84U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r4 = c3_IN_as1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 85U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i1 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_g_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      (*chartInstance->c3_as1)++;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as1, 111U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_td_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(12, 0, 0, *chartInstance->c3_temporalCounter_i1 >=
                      c3__u32_d_(chartInstance, muDoubleScalarCeil
            (*chartInstance->c3_d1 * 10.0), 43U, 1, 14))) {
        if (CV_EML_COND(12, 0, 1, CV_RELATIONAL_EVAL(5U, 12U, 0,
              *chartInstance->c3_vr5, 0.0, -1, 0U, *chartInstance->c3_vr5 == 0.0)))
        {
          if (CV_EML_COND(12, 0, 2, CV_RELATIONAL_EVAL(5U, 12U, 1,
                *chartInstance->c3_dp4, 1.0, -1, 1U, *chartInstance->c3_dp4 !=
                1.0))) {
            CV_EML_MCDC(12, 0, 0, true);
            CV_EML_IF(12, 0, 0, true);
            c3_d_out = true;
          } else {
            guard1 = true;
          }
        } else {
          if (!chartInstance->c3_dataWrittenToVector[45U]) {
            sf_read_before_write_error(chartInstance->S, 20U, 43U, 27, 3);
          }

          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[3U]) {
          sf_read_before_write_error(chartInstance->S, 72U, 43U, 18, 3);
        }

        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(12, 0, 0, false);
        CV_EML_IF(12, 0, 0, false);
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 84U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r4 = c3_IN_Next;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
        c3_enter_atomic_Next(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 84U,
                     *chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 84U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_as1:
    CV_STATE_EVAL(81, 0, c3_IN_as1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 48U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_wd_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(48, 0, 0, *chartInstance->c3_temporalCounter_i1 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 125U, 1, 13))) {
      if (CV_EML_COND(48, 0, 1, CV_RELATIONAL_EVAL(5U, 48U, 0,
            *chartInstance->c3_vr5, 0.0, -1, 0U, *chartInstance->c3_vr5 == 0.0)))
      {
        CV_EML_MCDC(48, 0, 0, true);
        CV_EML_IF(48, 0, 0, true);
        c3_c_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[3U]) {
        sf_read_before_write_error(chartInstance->S, 72U, 125U, 17, 3);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(48, 0, 0, false);
      CV_EML_IF(48, 0, 0, false);
      c3_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 48U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_xd_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp4 = 0.0;
      chartInstance->c3_dataWrittenToVector[45U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp4, 20U);
      *chartInstance->c3_vs4 = 0.0;
      chartInstance->c3_dataWrittenToVector[47U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs4, 96U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 85U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
        c3_h_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp4 = 0.0;
      chartInstance->c3_dataWrittenToVector[45U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp4, 20U);
      *chartInstance->c3_vs4 = 0.0;
      chartInstance->c3_dataWrittenToVector[47U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs4, 96U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 85U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 85U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r4 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
      c3_enter_atomic_Next(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 85U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 85U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(81, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r4 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 81U, *chartInstance->c3_sfEvent);
}

static void c3_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr5 = 1.0;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr5, 72U);
  if (!chartInstance->c3_dataWrittenToVector[45U]) {
    sf_read_before_write_error(chartInstance->S, 20U, 47U, 24, 3);
  }

  *chartInstance->c3_dp5 = *chartInstance->c3_dp4;
  chartInstance->c3_dataWrittenToVector[48U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp5, 21U);
  if (!chartInstance->c3_dataWrittenToVector[46U]) {
    sf_read_before_write_error(chartInstance->S, 46U, 47U, 34, 3);
  }

  *chartInstance->c3_vn5 = *chartInstance->c3_vn4;
  chartInstance->c3_dataWrittenToVector[49U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn5, 47U);
  if (!chartInstance->c3_dataWrittenToVector[47U]) {
    sf_read_before_write_error(chartInstance->S, 96U, 47U, 44, 3);
  }

  *chartInstance->c3_vs5 = *chartInstance->c3_vs4;
  chartInstance->c3_dataWrittenToVector[50U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs5, 97U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr4 = 0.0;
  chartInstance->c3_dataWrittenToVector[4U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr4, 71U);
  *chartInstance->c3_dp4 = 0.0;
  chartInstance->c3_dataWrittenToVector[45U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp4, 20U);
  *chartInstance->c3_vs4 = 0.0;
  chartInstance->c3_dataWrittenToVector[47U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs4, 96U);
  *chartInstance->c3_vn4 = 0.0;
  chartInstance->c3_dataWrittenToVector[46U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn4, 46U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r5(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r5 = c3_b_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
  c3_b_enter_atomic_Off(chartInstance);
}

static void c3_r5(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_b0;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  boolean_T c3_b;
  boolean_T c3_y;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[3];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_c_out;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  uint32_T c3_f_debug_family_var_map[2];
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 86U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r5) {
   case c3_IN_Next1:
    CV_STATE_EVAL(86, 0, c3_IN_Next1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 87U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r5 = c3_b_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
    c3_b_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 87U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Next2:
    CV_STATE_EVAL(86, 0, c3_IN_Next2);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 80U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 88U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r5 = c3_b_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
    c3_b_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 88U, *chartInstance->c3_sfEvent);
    break;

   case c3_b_IN_Off:
    CV_STATE_EVAL(86, 0, c3_b_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_be_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[3U]) {
      sf_read_before_write_error(chartInstance->S, 72U, 52U, 1, 3);
    }

    if (CV_EML_IF(17, 0, 0, CV_RELATIONAL_EVAL(5U, 17U, 0,
          *chartInstance->c3_vr5, 1.0, -1, 0U, *chartInstance->c3_vr5 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 89U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r5 = c3_b_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 90U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i2 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr5 = 1.0;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr5, 72U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 89U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 89U, *chartInstance->c3_sfEvent);
    break;

   case c3_b_IN_On:
    CV_STATE_EVAL(86, 0, c3_b_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 79U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ae_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[48U]) {
      sf_read_before_write_error(chartInstance->S, 21U, 227U, 2, 3);
    }

    c3_b0 = (*chartInstance->c3_dp5 == 4.0);
    guard1 = false;
    guard2 = false;
    if (CV_EML_COND(79, 0, 0, CV_RELATIONAL_EVAL(5U, 79U, 0,
          *chartInstance->c3_dp5, 4.0, -1, 0U, (int32_T)c3_b0))) {
      guard2 = true;
    } else {
      if (!chartInstance->c3_dataWrittenToVector[48U]) {
        sf_read_before_write_error(chartInstance->S, 21U, 227U, 11, 3);
      }

      c3_hoistedGlobal = *chartInstance->c3_dp5;
      c3_b_hoistedGlobal = *chartInstance->c3_dp5;
      c3_b = CV_EML_COND(79, 0, 1, CV_RELATIONAL_EVAL(5U, 79U, 1,
        c3_hoistedGlobal, 0.0, -1, 0U, c3_b_hoistedGlobal == 0.0));
      c3_y = c3_b;
      if (c3_y) {
        guard2 = true;
      } else {
        guard1 = true;
      }
    }

    if (guard2) {
      if (CV_EML_COND(79, 0, 2, *chartInstance->c3_temporalCounter_i2 >=
                      c3__u32_d_(chartInstance, muDoubleScalarCeil
            (*chartInstance->c3_d1 * 10.0), 227U, 21, 13))) {
        if (CV_EML_COND(79, 0, 3, CV_RELATIONAL_EVAL(5U, 79U, 2,
              *chartInstance->c3_vr18, 0.0, -1, 0U, *chartInstance->c3_vr18 ==
              0.0)) && CV_EML_COND(79, 0, 4, CV_RELATIONAL_EVAL(5U, 79U, 3,
              *chartInstance->c3_s, 1.0, -1, 0U, *chartInstance->c3_s == 1.0)))
        {
          CV_EML_MCDC(79, 0, 0, true);
          CV_EML_IF(79, 0, 0, true);
          c3_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          sf_read_before_write_error(chartInstance->S, 61U, 227U, 37, 4);
        }

        guard1 = true;
      }
    }

    if (guard1) {
      CV_EML_MCDC(79, 0, 0, false);
      CV_EML_IF(79, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 79U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 90U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r5 = c3_IN_Next2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 88U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr18 = 1.0;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr18, 61U);
      if (!chartInstance->c3_dataWrittenToVector[48U]) {
        sf_read_before_write_error(chartInstance->S, 21U, 226U, 27, 3);
      }

      *chartInstance->c3_dp18 = *chartInstance->c3_dp5;
      chartInstance->c3_dataWrittenToVector[54U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp18, 10U);
      if (!chartInstance->c3_dataWrittenToVector[49U]) {
        sf_read_before_write_error(chartInstance->S, 47U, 226U, 38, 3);
      }

      *chartInstance->c3_vn18 = *chartInstance->c3_vn5;
      chartInstance->c3_dataWrittenToVector[55U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn18, 36U);
      if (!chartInstance->c3_dataWrittenToVector[50U]) {
        sf_read_before_write_error(chartInstance->S, 97U, 226U, 49, 3);
      }

      *chartInstance->c3_vs18 = *chartInstance->c3_vs5;
      chartInstance->c3_dataWrittenToVector[56U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs18, 86U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_yd_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(19, 0, 0, *chartInstance->c3_temporalCounter_i2 >=
                      c3__u32_d_(chartInstance, muDoubleScalarCeil
            (*chartInstance->c3_d1 * 10.0), 54U, 1, 14))) {
        if (CV_EML_COND(19, 0, 1, CV_RELATIONAL_EVAL(5U, 19U, 0,
              *chartInstance->c3_vr6, 0.0, -1, 0U, *chartInstance->c3_vr6 == 0.0)))
        {
          CV_EML_MCDC(19, 0, 0, true);
          CV_EML_IF(19, 0, 0, true);
          c3_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[1U]) {
          sf_read_before_write_error(chartInstance->S, 73U, 54U, 18, 3);
        }

        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(19, 0, 0, false);
        CV_EML_IF(19, 0, 0, false);
        c3_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 90U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r5 = c3_IN_Next1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 87U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
          c3_f_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
          c3_b_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_b_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_vr6 = 1.0;
        chartInstance->c3_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr6, 73U);
        if (!chartInstance->c3_dataWrittenToVector[48U]) {
          sf_read_before_write_error(chartInstance->S, 21U, 55U, 25, 3);
        }

        *chartInstance->c3_dp6 = *chartInstance->c3_dp5;
        chartInstance->c3_dataWrittenToVector[51U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp6, 22U);
        if (!chartInstance->c3_dataWrittenToVector[49U]) {
          sf_read_before_write_error(chartInstance->S, 47U, 55U, 35, 3);
        }

        *chartInstance->c3_vn6 = *chartInstance->c3_vn5;
        chartInstance->c3_dataWrittenToVector[52U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn6, 48U);
        if (!chartInstance->c3_dataWrittenToVector[50U]) {
          sf_read_before_write_error(chartInstance->S, 97U, 55U, 45, 3);
        }

        *chartInstance->c3_vs6 = *chartInstance->c3_vs5;
        chartInstance->c3_dataWrittenToVector[53U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs6, 98U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 90U,
                     *chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 90U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(86, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r5 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 87U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 86U, *chartInstance->c3_sfEvent);
}

static void c3_b_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr5 = 0.0;
  chartInstance->c3_dataWrittenToVector[3U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr5, 72U);
  *chartInstance->c3_dp5 = 0.0;
  chartInstance->c3_dataWrittenToVector[48U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp5, 21U);
  *chartInstance->c3_vs5 = 0.0;
  chartInstance->c3_dataWrittenToVector[50U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs5, 97U);
  *chartInstance->c3_vn5 = 0.0;
  chartInstance->c3_dataWrittenToVector[49U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn5, 47U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r8(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r8 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *chartInstance->c3_sfEvent);
  c3_c_enter_atomic_Off(chartInstance);
}

static void c3_r8(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 100U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r8) {
   case c3_IN_Next:
    CV_STATE_EVAL(100, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r8 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 101U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r8 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 102U, *chartInstance->c3_sfEvent);
    c3_c_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 101U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(100, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_de_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[2U]) {
      sf_read_before_write_error(chartInstance->S, 75U, 76U, 1, 3);
    }

    if (CV_EML_IF(29, 0, 0, CV_RELATIONAL_EVAL(5U, 29U, 0,
          *chartInstance->c3_vr8, 1.0, -1, 0U, *chartInstance->c3_vr8 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r8 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 102U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r8 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 103U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i3 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr8 = 1.0;
      chartInstance->c3_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr8, 75U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 102U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 102U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(100, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ce_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(30, 0, 0, *chartInstance->c3_temporalCounter_i3 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 77U, 1, 14))) {
      if (CV_EML_COND(30, 0, 1, CV_RELATIONAL_EVAL(5U, 30U, 0,
            *chartInstance->c3_vr9, 0.0, -1, 0U, *chartInstance->c3_vr9 == 0.0)))
      {
        CV_EML_MCDC(30, 0, 0, true);
        CV_EML_IF(30, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[5U]) {
        sf_read_before_write_error(chartInstance->S, 76U, 77U, 18, 3);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(30, 0, 0, false);
      CV_EML_IF(30, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r8 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 103U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r8 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 101U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_l_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr9 = 1.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr9, 76U);
      if (!chartInstance->c3_dataWrittenToVector[58U]) {
        sf_read_before_write_error(chartInstance->S, 24U, 80U, 24, 3);
      }

      *chartInstance->c3_dp9 = *chartInstance->c3_dp8;
      chartInstance->c3_dataWrittenToVector[57U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp9, 25U);
      if (!chartInstance->c3_dataWrittenToVector[60U]) {
        sf_read_before_write_error(chartInstance->S, 50U, 80U, 34, 3);
      }

      *chartInstance->c3_vn9 = *chartInstance->c3_vn8;
      chartInstance->c3_dataWrittenToVector[59U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn9, 51U);
      if (!chartInstance->c3_dataWrittenToVector[62U]) {
        sf_read_before_write_error(chartInstance->S, 100U, 80U, 44, 3);
      }

      *chartInstance->c3_vs9 = *chartInstance->c3_vs8;
      chartInstance->c3_dataWrittenToVector[61U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs9, 101U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 103U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 103U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(100, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r8 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 101U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 100U, *chartInstance->c3_sfEvent);
}

static void c3_c_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_m_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr8 = 0.0;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr8, 75U);
  *chartInstance->c3_dp8 = 0.0;
  chartInstance->c3_dataWrittenToVector[58U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp8, 24U);
  *chartInstance->c3_vs8 = 0.0;
  chartInstance->c3_dataWrittenToVector[62U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs8, 100U);
  *chartInstance->c3_vn8 = 0.0;
  chartInstance->c3_dataWrittenToVector[60U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn8, 50U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r9(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 104U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r9) {
   case c3_IN_Next:
    CV_STATE_EVAL(104, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r9 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 105U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r9 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 106U, *chartInstance->c3_sfEvent);
    c3_d_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 105U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(104, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_fe_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[5U]) {
      sf_read_before_write_error(chartInstance->S, 76U, 91U, 1, 3);
    }

    if (CV_EML_IF(33, 0, 0, CV_RELATIONAL_EVAL(5U, 33U, 0,
          *chartInstance->c3_vr9, 1.0, -1, 0U, *chartInstance->c3_vr9 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r9 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 106U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r9 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 107U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i4 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_n_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr9 = 1.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr9, 76U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 106U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 106U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(104, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ee_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(34, 0, 0, *chartInstance->c3_temporalCounter_i4 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 92U, 1, 14))) {
      if (CV_EML_COND(34, 0, 1, CV_RELATIONAL_EVAL(5U, 34U, 0,
            *chartInstance->c3_vr21, 0.0, -1, 0U, *chartInstance->c3_vr21 == 0.0)))
      {
        CV_EML_MCDC(34, 0, 0, true);
        CV_EML_IF(34, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[73U]) {
        sf_read_before_write_error(chartInstance->S, 65U, 92U, 18, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(34, 0, 0, false);
      CV_EML_IF(34, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r9 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 107U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r9 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 105U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_o_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr21 = 1.0;
      chartInstance->c3_dataWrittenToVector[73U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr21, 65U);
      if (!chartInstance->c3_dataWrittenToVector[57U]) {
        sf_read_before_write_error(chartInstance->S, 25U, 94U, 26, 3);
      }

      *chartInstance->c3_dp21 = *chartInstance->c3_dp9;
      chartInstance->c3_dataWrittenToVector[74U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp21, 14U);
      if (!chartInstance->c3_dataWrittenToVector[59U]) {
        sf_read_before_write_error(chartInstance->S, 51U, 94U, 37, 3);
      }

      *chartInstance->c3_vn21 = *chartInstance->c3_vn9;
      chartInstance->c3_dataWrittenToVector[75U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn21, 40U);
      if (!chartInstance->c3_dataWrittenToVector[61U]) {
        sf_read_before_write_error(chartInstance->S, 101U, 94U, 48, 3);
      }

      *chartInstance->c3_vs21 = *chartInstance->c3_vs9;
      chartInstance->c3_dataWrittenToVector[72U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs21, 90U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 107U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 107U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(104, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r9 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 105U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 104U, *chartInstance->c3_sfEvent);
}

static void c3_d_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_p_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr9 = 0.0;
  chartInstance->c3_dataWrittenToVector[5U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr9, 76U);
  *chartInstance->c3_dp9 = 0.0;
  chartInstance->c3_dataWrittenToVector[57U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp9, 25U);
  *chartInstance->c3_vs9 = 0.0;
  chartInstance->c3_dataWrittenToVector[61U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs9, 101U);
  *chartInstance->c3_vn9 = 0.0;
  chartInstance->c3_dataWrittenToVector[59U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn9, 51U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r6(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r6 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 93U, *chartInstance->c3_sfEvent);
  c3_e_enter_atomic_Off(chartInstance);
}

static void c3_r6(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 91U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r6) {
   case c3_IN_Next:
    CV_STATE_EVAL(91, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r6 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 92U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r6 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 93U, *chartInstance->c3_sfEvent);
    c3_e_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 92U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(91, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_he_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[1U]) {
      sf_read_before_write_error(chartInstance->S, 73U, 62U, 1, 3);
    }

    if (CV_EML_IF(23, 0, 0, CV_RELATIONAL_EVAL(5U, 23U, 0,
          *chartInstance->c3_vr6, 1.0, -1, 0U, *chartInstance->c3_vr6 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r6 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 93U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r6 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 94U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i5 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_q_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr6 = 1.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr6, 73U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 93U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 93U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(91, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ge_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(22, 0, 0, *chartInstance->c3_temporalCounter_i5 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 61U, 1, 14))) {
      if (CV_EML_COND(22, 0, 1, CV_RELATIONAL_EVAL(5U, 22U, 0,
            *chartInstance->c3_vr7, 0.0, -1, 0U, *chartInstance->c3_vr7 == 0.0)))
      {
        CV_EML_MCDC(22, 0, 0, true);
        CV_EML_IF(22, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[0U]) {
        sf_read_before_write_error(chartInstance->S, 74U, 61U, 18, 3);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(22, 0, 0, false);
      CV_EML_IF(22, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r6 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 94U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r6 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 92U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_r_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr7 = 1.0;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr7, 74U);
      if (!chartInstance->c3_dataWrittenToVector[51U]) {
        sf_read_before_write_error(chartInstance->S, 22U, 63U, 24, 3);
      }

      *chartInstance->c3_dp7 = *chartInstance->c3_dp6;
      chartInstance->c3_dataWrittenToVector[63U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp7, 23U);
      if (!chartInstance->c3_dataWrittenToVector[52U]) {
        sf_read_before_write_error(chartInstance->S, 48U, 63U, 34, 3);
      }

      *chartInstance->c3_vn7 = *chartInstance->c3_vn6;
      chartInstance->c3_dataWrittenToVector[19U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn7, 49U);
      if (!chartInstance->c3_dataWrittenToVector[53U]) {
        sf_read_before_write_error(chartInstance->S, 98U, 63U, 44, 3);
      }

      *chartInstance->c3_vs7 = *chartInstance->c3_vs6;
      chartInstance->c3_dataWrittenToVector[20U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs7, 99U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 94U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 94U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(91, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r6 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 92U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 91U, *chartInstance->c3_sfEvent);
}

static void c3_e_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_s_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr6 = 0.0;
  chartInstance->c3_dataWrittenToVector[1U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr6, 73U);
  *chartInstance->c3_dp6 = 0.0;
  chartInstance->c3_dataWrittenToVector[51U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp6, 22U);
  *chartInstance->c3_vs6 = 0.0;
  chartInstance->c3_dataWrittenToVector[53U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs6, 98U);
  *chartInstance->c3_vn6 = 0.0;
  chartInstance->c3_dataWrittenToVector[52U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn6, 48U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r7(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r7 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 97U, *chartInstance->c3_sfEvent);
  c3_f_enter_atomic_Off(chartInstance);
}

static void c3_r7(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  uint32_T c3_c_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  uint32_T c3_e_debug_family_var_map[3];
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  uint32_T c3_f_debug_family_var_map[2];
  real_T c3_e_nargout = 1.0;
  real_T c3_f_nargin = 0.0;
  boolean_T c3_d_out;
  real_T c3_f_nargout = 0.0;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_h_debug_family_var_map[2];
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 95U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r7) {
   case c3_IN_Next:
    CV_STATE_EVAL(95, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r7 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 97U, *chartInstance->c3_sfEvent);
    c3_f_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 96U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(95, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ke_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[0U]) {
      sf_read_before_write_error(chartInstance->S, 74U, 100U, 1, 3);
    }

    if (CV_EML_IF(38, 0, 0, CV_RELATIONAL_EVAL(5U, 38U, 0,
          *chartInstance->c3_vr7, 1.0, -1, 0U, *chartInstance->c3_vr7 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 97U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r7 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 98U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i6 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_t_debug_family_names,
        c3_f_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr7 = 1.0;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr7, 74U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 97U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 97U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(95, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 49U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_je_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[63U]) {
      sf_read_before_write_error(chartInstance->S, 23U, 127U, 1, 3);
    }

    if (CV_EML_COND(49, 0, 0, CV_RELATIONAL_EVAL(5U, 49U, 0,
          *chartInstance->c3_dp7, 2.0, -1, 0U, *chartInstance->c3_dp7 == 2.0)) &&
        CV_EML_COND(49, 0, 1, *chartInstance->c3_temporalCounter_i6 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d2 * 10.0), 127U, 8, 13))) {
      CV_EML_MCDC(49, 0, 0, true);
      CV_EML_IF(49, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(49, 0, 0, false);
      CV_EML_IF(49, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 49U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 98U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r7 = c3_IN_as2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 99U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i6 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_v_debug_family_names,
        c3_g_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      (*chartInstance->c3_as2)++;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as2, 112U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ie_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(37, 0, 0, *chartInstance->c3_temporalCounter_i6 >=
                      c3__u32_d_(chartInstance, muDoubleScalarCeil
            (*chartInstance->c3_d1 * 10.0), 99U, 1, 14))) {
        if (CV_EML_COND(37, 0, 1, CV_RELATIONAL_EVAL(5U, 37U, 0,
              *chartInstance->c3_vr8, 0.0, -1, 0U, *chartInstance->c3_vr8 == 0.0)))
        {
          CV_EML_MCDC(37, 0, 0, true);
          CV_EML_IF(37, 0, 0, true);
          c3_d_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[2U]) {
          sf_read_before_write_error(chartInstance->S, 75U, 99U, 18, 3);
        }

        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(37, 0, 0, false);
        CV_EML_IF(37, 0, 0, false);
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 98U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r7 = c3_IN_Next;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
        c3_b_enter_atomic_Next(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 98U,
                     *chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 98U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_as2:
    CV_STATE_EVAL(95, 0, c3_IN_as2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 50U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_le_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(50, 0, 0, *chartInstance->c3_temporalCounter_i6 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 128U, 1, 13))) {
      if (CV_EML_COND(50, 0, 1, CV_RELATIONAL_EVAL(5U, 50U, 0,
            *chartInstance->c3_vr8, 0.0, -1, 0U, *chartInstance->c3_vr8 == 0.0)))
      {
        CV_EML_MCDC(50, 0, 0, true);
        CV_EML_IF(50, 0, 0, true);
        c3_c_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[2U]) {
        sf_read_before_write_error(chartInstance->S, 75U, 128U, 17, 3);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(50, 0, 0, false);
      CV_EML_IF(50, 0, 0, false);
      c3_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 50U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_me_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp7 = 0.0;
      chartInstance->c3_dataWrittenToVector[63U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp7, 23U);
      *chartInstance->c3_vs7 = 0.0;
      chartInstance->c3_dataWrittenToVector[20U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs7, 99U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 99U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_w_debug_family_names,
        c3_h_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp7 = 0.0;
      chartInstance->c3_dataWrittenToVector[63U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp7, 23U);
      *chartInstance->c3_vs7 = 0.0;
      chartInstance->c3_dataWrittenToVector[20U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs7, 99U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 99U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 99U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r7 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
      c3_b_enter_atomic_Next(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 99U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 99U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(95, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r7 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 95U, *chartInstance->c3_sfEvent);
}

static void c3_b_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_u_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr8 = 1.0;
  chartInstance->c3_dataWrittenToVector[2U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr8, 75U);
  if (!chartInstance->c3_dataWrittenToVector[63U]) {
    sf_read_before_write_error(chartInstance->S, 23U, 102U, 24, 3);
  }

  *chartInstance->c3_dp8 = *chartInstance->c3_dp7;
  chartInstance->c3_dataWrittenToVector[58U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp8, 24U);
  if (!chartInstance->c3_dataWrittenToVector[19U]) {
    sf_read_before_write_error(chartInstance->S, 49U, 102U, 34, 3);
  }

  *chartInstance->c3_vn8 = *chartInstance->c3_vn7;
  chartInstance->c3_dataWrittenToVector[60U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn8, 50U);
  if (!chartInstance->c3_dataWrittenToVector[20U]) {
    sf_read_before_write_error(chartInstance->S, 99U, 102U, 44, 3);
  }

  *chartInstance->c3_vs8 = *chartInstance->c3_vs7;
  chartInstance->c3_dataWrittenToVector[62U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs8, 100U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_f_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_x_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr7 = 0.0;
  chartInstance->c3_dataWrittenToVector[0U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr7, 74U);
  *chartInstance->c3_dp7 = 0.0;
  chartInstance->c3_dataWrittenToVector[63U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp7, 23U);
  *chartInstance->c3_vs7 = 0.0;
  chartInstance->c3_dataWrittenToVector[20U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs7, 99U);
  *chartInstance->c3_vn7 = 0.0;
  chartInstance->c3_dataWrittenToVector[19U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn7, 49U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r3(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r3 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 79U, *chartInstance->c3_sfEvent);
  c3_g_enter_atomic_Off(chartInstance);
}

static void c3_r3(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 77U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r3) {
   case c3_IN_Next:
    CV_STATE_EVAL(77, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r3 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 78U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r3 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 79U, *chartInstance->c3_sfEvent);
    c3_g_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 78U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(77, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_oe_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0,
          *chartInstance->c3_vr3, 1.0, -1, 0U, *chartInstance->c3_vr3 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r3 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 79U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r3 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 80U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i7 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_y_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr3 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr3, 70U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 79U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 79U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(77, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ne_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(10, 0, 0, *chartInstance->c3_temporalCounter_i7 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 37U, 1, 14))) {
      if (CV_EML_COND(10, 0, 1, CV_RELATIONAL_EVAL(5U, 10U, 0,
            *chartInstance->c3_vr24, 0.0, -1, 0U, *chartInstance->c3_vr24 == 0.0)))
      {
        CV_EML_MCDC(10, 0, 0, true);
        CV_EML_IF(10, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[86U]) {
        sf_read_before_write_error(chartInstance->S, 68U, 37U, 18, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(10, 0, 0, false);
      CV_EML_IF(10, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r3 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 80U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r3 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 78U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ab_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr24 = 1.0;
      chartInstance->c3_dataWrittenToVector[86U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr24, 68U);
      if (!chartInstance->c3_dataWrittenToVector[11U]) {
        sf_read_before_write_error(chartInstance->S, 19U, 38U, 26, 3);
      }

      *chartInstance->c3_dp24 = *chartInstance->c3_dp3;
      chartInstance->c3_dataWrittenToVector[84U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp24, 17U);
      if (!chartInstance->c3_dataWrittenToVector[10U]) {
        sf_read_before_write_error(chartInstance->S, 45U, 38U, 37, 3);
      }

      *chartInstance->c3_vn24 = *chartInstance->c3_vn3;
      chartInstance->c3_dataWrittenToVector[85U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn24, 43U);
      if (!chartInstance->c3_dataWrittenToVector[9U]) {
        sf_read_before_write_error(chartInstance->S, 95U, 38U, 48, 3);
      }

      *chartInstance->c3_vs24 = *chartInstance->c3_vs3;
      chartInstance->c3_dataWrittenToVector[87U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs24, 93U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 80U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 80U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(77, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r3 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 78U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 77U, *chartInstance->c3_sfEvent);
}

static void c3_g_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_bb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr3 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr3, 70U);
  *chartInstance->c3_dp3 = 0.0;
  chartInstance->c3_dataWrittenToVector[11U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp3, 19U);
  *chartInstance->c3_vs3 = 0.0;
  chartInstance->c3_dataWrittenToVector[9U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs3, 95U);
  *chartInstance->c3_vn3 = 0.0;
  chartInstance->c3_dataWrittenToVector[10U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn3, 45U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r20(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 53U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r20) {
   case c3_IN_Next:
    CV_STATE_EVAL(53, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 86U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r20 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r20 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 55U, *chartInstance->c3_sfEvent);
    c3_h_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 54U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(53, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 87U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_qe_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[76U]) {
      sf_read_before_write_error(chartInstance->S, 64U, 305U, 1, 4);
    }

    if (CV_EML_IF(87, 0, 0, CV_RELATIONAL_EVAL(5U, 87U, 0,
          *chartInstance->c3_vr20, 1.0, -1, 0U, *chartInstance->c3_vr20 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 87U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r20 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 55U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r20 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 56U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i8 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_cb_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr20 = 1.0;
      chartInstance->c3_dataWrittenToVector[76U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr20, 64U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 55U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 55U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(53, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 88U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_pe_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(88, 0, 0, *chartInstance->c3_temporalCounter_i8 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 306U, 1, 14))) {
      if (CV_EML_COND(88, 0, 1, CV_RELATIONAL_EVAL(5U, 88U, 0,
            *chartInstance->c3_vr4, 0.0, -1, 0U, *chartInstance->c3_vr4 == 0.0)))
      {
        CV_EML_MCDC(88, 0, 0, true);
        CV_EML_IF(88, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[4U]) {
        sf_read_before_write_error(chartInstance->S, 71U, 306U, 18, 3);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(88, 0, 0, false);
      CV_EML_IF(88, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 88U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r20 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 56U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r20 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 54U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_db_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr4 = 1.0;
      chartInstance->c3_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr4, 71U);
      if (!chartInstance->c3_dataWrittenToVector[77U]) {
        sf_read_before_write_error(chartInstance->S, 13U, 308U, 24, 4);
      }

      *chartInstance->c3_dp4 = *chartInstance->c3_dp20;
      chartInstance->c3_dataWrittenToVector[45U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp4, 20U);
      if (!chartInstance->c3_dataWrittenToVector[78U]) {
        sf_read_before_write_error(chartInstance->S, 39U, 308U, 35, 4);
      }

      *chartInstance->c3_vn4 = *chartInstance->c3_vn20;
      chartInstance->c3_dataWrittenToVector[46U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn4, 46U);
      if (!chartInstance->c3_dataWrittenToVector[79U]) {
        sf_read_before_write_error(chartInstance->S, 89U, 308U, 46, 4);
      }

      *chartInstance->c3_vs4 = *chartInstance->c3_vs20;
      chartInstance->c3_dataWrittenToVector[47U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs4, 96U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 56U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 56U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(53, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r20 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 54U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 53U, *chartInstance->c3_sfEvent);
}

static void c3_h_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_eb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr20 = 0.0;
  chartInstance->c3_dataWrittenToVector[76U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr20, 64U);
  *chartInstance->c3_dp20 = 0.0;
  chartInstance->c3_dataWrittenToVector[77U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp20, 13U);
  *chartInstance->c3_vs20 = 0.0;
  chartInstance->c3_dataWrittenToVector[79U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs20, 89U);
  *chartInstance->c3_vn20 = 0.0;
  chartInstance->c3_dataWrittenToVector[78U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn20, 39U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r24(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 69U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r24) {
   case c3_IN_Next:
    CV_STATE_EVAL(69, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 103U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r24 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r24 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 71U, *chartInstance->c3_sfEvent);
    c3_i_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 70U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(69, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 102U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_se_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[86U]) {
      sf_read_before_write_error(chartInstance->S, 68U, 385U, 1, 4);
    }

    if (CV_EML_IF(102, 0, 0, CV_RELATIONAL_EVAL(5U, 102U, 0,
          *chartInstance->c3_vr24, 1.0, -1, 0U, *chartInstance->c3_vr24 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 102U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r24 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 71U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r24 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 72U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i9 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_fb_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr24 = 1.0;
      chartInstance->c3_dataWrittenToVector[86U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr24, 68U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 71U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 71U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(69, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 104U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_re_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(104, 0, 0, *chartInstance->c3_temporalCounter_i9 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 387U, 1, 14))) {
      if (CV_EML_COND(104, 0, 1, CV_RELATIONAL_EVAL(5U, 104U, 0,
            *chartInstance->c3_vr20, 0.0, -1, 0U, *chartInstance->c3_vr20 == 0.0)))
      {
        CV_EML_MCDC(104, 0, 0, true);
        CV_EML_IF(104, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[76U]) {
        sf_read_before_write_error(chartInstance->S, 64U, 387U, 18, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(104, 0, 0, false);
      CV_EML_IF(104, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 104U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r24 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 72U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r24 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 70U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_gb_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr20 = 1.0;
      chartInstance->c3_dataWrittenToVector[76U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr20, 64U);
      if (!chartInstance->c3_dataWrittenToVector[84U]) {
        sf_read_before_write_error(chartInstance->S, 17U, 391U, 26, 4);
      }

      *chartInstance->c3_dp20 = *chartInstance->c3_dp24;
      chartInstance->c3_dataWrittenToVector[77U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp20, 13U);
      if (!chartInstance->c3_dataWrittenToVector[85U]) {
        sf_read_before_write_error(chartInstance->S, 43U, 391U, 38, 4);
      }

      *chartInstance->c3_vn20 = *chartInstance->c3_vn24;
      chartInstance->c3_dataWrittenToVector[78U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn20, 39U);
      if (!chartInstance->c3_dataWrittenToVector[87U]) {
        sf_read_before_write_error(chartInstance->S, 93U, 391U, 50, 4);
      }

      *chartInstance->c3_vs20 = *chartInstance->c3_vs24;
      chartInstance->c3_dataWrittenToVector[79U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs20, 89U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 72U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 72U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(69, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r24 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 70U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 69U, *chartInstance->c3_sfEvent);
}

static void c3_i_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_hb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr24 = 0.0;
  chartInstance->c3_dataWrittenToVector[86U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr24, 68U);
  *chartInstance->c3_dp24 = 0.0;
  chartInstance->c3_dataWrittenToVector[84U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp24, 17U);
  *chartInstance->c3_vs24 = 0.0;
  chartInstance->c3_dataWrittenToVector[87U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs24, 93U);
  *chartInstance->c3_vn24 = 0.0;
  chartInstance->c3_dataWrittenToVector[85U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn24, 43U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r2(SFc3_ver_601InstanceStruct *chartInstance)
{
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r2 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *chartInstance->c3_sfEvent);
  c3_j_enter_atomic_Off(chartInstance);
}

static void c3_r2(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 49U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r2) {
   case c3_IN_Next:
    CV_STATE_EVAL(49, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r2 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 51U, *chartInstance->c3_sfEvent);
    c3_j_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 50U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(49, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ve_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0, *chartInstance->c3_vr2,
          1.0, -1, 0U, *chartInstance->c3_vr2 == 1.0))) {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r2 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 51U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r2 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 52U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i10 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ib_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr2 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr2, 63U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 51U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 51U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(49, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ue_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(2, 0, 0, *chartInstance->c3_temporalCounter_i10 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 12U, 1, 14)) && CV_EML_COND(2, 0, 1,
         CV_RELATIONAL_EVAL(5U, 2U, 0, *chartInstance->c3_vr3, 0.0, -1, 0U,
                            *chartInstance->c3_vr3 == 0.0))) {
      CV_EML_MCDC(2, 0, 0, true);
      CV_EML_IF(2, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(2, 0, 0, false);
      CV_EML_IF(2, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r2 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 52U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r2 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 50U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_jb_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr3 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr3, 70U);
      if (!chartInstance->c3_dataWrittenToVector[14U]) {
        sf_read_before_write_error(chartInstance->S, 12U, 25U, 24, 3);
      }

      *chartInstance->c3_dp3 = *chartInstance->c3_dp2;
      chartInstance->c3_dataWrittenToVector[11U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp3, 19U);
      if (!chartInstance->c3_dataWrittenToVector[15U]) {
        sf_read_before_write_error(chartInstance->S, 38U, 25U, 34, 3);
      }

      *chartInstance->c3_vn3 = *chartInstance->c3_vn2;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn3, 45U);
      if (!chartInstance->c3_dataWrittenToVector[16U]) {
        sf_read_before_write_error(chartInstance->S, 88U, 25U, 44, 3);
      }

      *chartInstance->c3_vs3 = *chartInstance->c3_vs2;
      chartInstance->c3_dataWrittenToVector[9U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs3, 95U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 52U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 52U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(49, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 50U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 49U, *chartInstance->c3_sfEvent);
}

static void c3_j_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_kb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr2 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr2, 63U);
  *chartInstance->c3_dp2 = 0.0;
  chartInstance->c3_dataWrittenToVector[14U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp2, 12U);
  *chartInstance->c3_vs2 = 0.0;
  chartInstance->c3_dataWrittenToVector[16U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs2, 88U);
  *chartInstance->c3_vn2 = 0.0;
  chartInstance->c3_dataWrittenToVector[15U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn2, 38U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r21(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 57U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r21) {
   case c3_IN_Next:
    CV_STATE_EVAL(57, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 92U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r21 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r21 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 59U, *chartInstance->c3_sfEvent);
    c3_k_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 58U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(57, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 91U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_xe_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[73U]) {
      sf_read_before_write_error(chartInstance->S, 65U, 313U, 1, 4);
    }

    if (CV_EML_IF(91, 0, 0, CV_RELATIONAL_EVAL(5U, 91U, 0,
          *chartInstance->c3_vr21, 1.0, -1, 0U, *chartInstance->c3_vr21 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 91U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r21 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 59U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r21 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 60U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i11 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_lb_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr21 = 1.0;
      chartInstance->c3_dataWrittenToVector[73U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr21, 65U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 59U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 59U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(57, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 93U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_we_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(93, 0, 0, *chartInstance->c3_temporalCounter_i11 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 317U, 1, 14))) {
      if (CV_EML_COND(93, 0, 1, CV_RELATIONAL_EVAL(5U, 93U, 0,
            *chartInstance->c3_vr22, 0.0, -1, 0U, *chartInstance->c3_vr22 == 0.0)))
      {
        CV_EML_MCDC(93, 0, 0, true);
        CV_EML_IF(93, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[64U]) {
        sf_read_before_write_error(chartInstance->S, 66U, 317U, 18, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(93, 0, 0, false);
      CV_EML_IF(93, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 93U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r21 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 60U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r21 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 58U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_mb_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr22 = 1.0;
      chartInstance->c3_dataWrittenToVector[64U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr22, 66U);
      if (!chartInstance->c3_dataWrittenToVector[74U]) {
        sf_read_before_write_error(chartInstance->S, 14U, 319U, 26, 4);
      }

      *chartInstance->c3_dp22 = *chartInstance->c3_dp21;
      chartInstance->c3_dataWrittenToVector[65U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp22, 15U);
      if (!chartInstance->c3_dataWrittenToVector[75U]) {
        sf_read_before_write_error(chartInstance->S, 40U, 319U, 38, 4);
      }

      *chartInstance->c3_vn22 = *chartInstance->c3_vn21;
      chartInstance->c3_dataWrittenToVector[66U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn22, 41U);
      if (!chartInstance->c3_dataWrittenToVector[72U]) {
        sf_read_before_write_error(chartInstance->S, 90U, 319U, 50, 4);
      }

      *chartInstance->c3_vs22 = *chartInstance->c3_vs21;
      chartInstance->c3_dataWrittenToVector[67U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs22, 91U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 60U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 60U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(57, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r21 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 58U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 57U, *chartInstance->c3_sfEvent);
}

static void c3_k_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_nb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr21 = 0.0;
  chartInstance->c3_dataWrittenToVector[73U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr21, 65U);
  *chartInstance->c3_dp21 = 0.0;
  chartInstance->c3_dataWrittenToVector[74U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp21, 14U);
  *chartInstance->c3_vs21 = 0.0;
  chartInstance->c3_dataWrittenToVector[72U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs21, 90U);
  *chartInstance->c3_vn21 = 0.0;
  chartInstance->c3_dataWrittenToVector[75U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn21, 40U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r18(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 41U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r18) {
   case c3_IN_Next:
    CV_STATE_EVAL(41, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 77U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r18 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r18 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 43U, *chartInstance->c3_sfEvent);
    c3_l_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 42U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(41, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 76U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_af_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[8U]) {
      sf_read_before_write_error(chartInstance->S, 61U, 219U, 1, 4);
    }

    if (CV_EML_IF(76, 0, 0, CV_RELATIONAL_EVAL(5U, 76U, 0,
          *chartInstance->c3_vr18, 1.0, -1, 0U, *chartInstance->c3_vr18 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 76U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r18 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 43U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r18 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 44U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i12 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ob_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr18 = 1.0;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr18, 61U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 43U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 43U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(41, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 78U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ye_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(78, 0, 0, *chartInstance->c3_temporalCounter_i12 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 222U, 1, 14)) && CV_EML_COND(78, 0, 1,
         CV_RELATIONAL_EVAL(5U, 78U, 0, *chartInstance->c3_vr14, 0.0, -1, 0U,
                            *chartInstance->c3_vr14 == 0.0)) && CV_EML_COND(78,
         0, 2, CV_RELATIONAL_EVAL(5U, 78U, 1, *chartInstance->c3_vr13, 0.0, -1,
          0U, *chartInstance->c3_vr13 == 0.0))) {
      CV_EML_MCDC(78, 0, 0, true);
      CV_EML_IF(78, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(78, 0, 0, false);
      CV_EML_IF(78, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 78U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r18 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 44U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r18 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 42U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_pb_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr14 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr14, 57U);
      if (!chartInstance->c3_dataWrittenToVector[54U]) {
        sf_read_before_write_error(chartInstance->S, 10U, 224U, 26, 4);
      }

      *chartInstance->c3_dp14 = *chartInstance->c3_dp18;
      chartInstance->c3_dataWrittenToVector[34U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp14, 6U);
      if (!chartInstance->c3_dataWrittenToVector[55U]) {
        sf_read_before_write_error(chartInstance->S, 36U, 224U, 38, 4);
      }

      *chartInstance->c3_vn14 = *chartInstance->c3_vn18;
      chartInstance->c3_dataWrittenToVector[33U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn14, 32U);
      if (!chartInstance->c3_dataWrittenToVector[56U]) {
        sf_read_before_write_error(chartInstance->S, 86U, 224U, 50, 4);
      }

      *chartInstance->c3_vs14 = *chartInstance->c3_vs18;
      chartInstance->c3_dataWrittenToVector[32U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs14, 82U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 44U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 44U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(41, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r18 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 42U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *chartInstance->c3_sfEvent);
}

static void c3_l_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr18 = 0.0;
  chartInstance->c3_dataWrittenToVector[8U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr18, 61U);
  *chartInstance->c3_dp18 = 0.0;
  chartInstance->c3_dataWrittenToVector[54U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp18, 10U);
  *chartInstance->c3_vs18 = 0.0;
  chartInstance->c3_dataWrittenToVector[56U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs18, 86U);
  *chartInstance->c3_vn18 = 0.0;
  chartInstance->c3_dataWrittenToVector[55U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn18, 36U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_enter_internal_r1(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_is_r1 = c3_IN_Off;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  *chartInstance->c3_temporalCounter_i13 = 0U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_tb_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr1 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr1, 52U);
  *chartInstance->c3_dp1 = 0.0;
  chartInstance->c3_dataWrittenToVector[17U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp1, 1U);
  *chartInstance->c3_vs1 = 0.0;
  chartInstance->c3_dataWrittenToVector[18U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs1, 77U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r1(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r1) {
   case c3_IN_Next:
    CV_STATE_EVAL(3, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r1 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_temporalCounter_i13 = 0U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_tb_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_vr1 = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr1, 52U);
    *chartInstance->c3_dp1 = 0.0;
    chartInstance->c3_dataWrittenToVector[17U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp1, 1U);
    *chartInstance->c3_vs1 = 0.0;
    chartInstance->c3_dataWrittenToVector[18U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs1, 77U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(3, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_cf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0, *chartInstance->c3_j1,
          0.0, -1, 4U, *chartInstance->c3_j1 > 0.0)) && CV_EML_COND(0, 0, 1,
         *chartInstance->c3_temporalCounter_i13 >= 10U)) {
      CV_EML_MCDC(0, 0, 0, true);
      CV_EML_IF(0, 0, 0, true);
      c3_out = true;
    } else {
      CV_EML_MCDC(0, 0, 0, false);
      CV_EML_IF(0, 0, 0, false);
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r1 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i13 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_rb_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr1 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr1, 52U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(3, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, *chartInstance->c3_j1,
          0.0, -1, 4U, *chartInstance->c3_j1 > 0.0))) {
      if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
            *chartInstance->c3_vr19, 1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0)))
      {
        if (CV_EML_COND(3, 0, 2, CV_RELATIONAL_EVAL(5U, 3U, 2,
              *chartInstance->c3_vs19, 0.0, -1, 0U, *chartInstance->c3_vs19 ==
              0.0)) && CV_EML_COND(3, 0, 3,
             *chartInstance->c3_temporalCounter_i13 >= c3__u32_d_(chartInstance,
              muDoubleScalarCeil(*chartInstance->c3_d2 * 10.0), 18U, 28, 13))) {
          CV_EML_MCDC(3, 0, 0, true);
          CV_EML_IF(3, 0, 0, true);
          c3_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          sf_read_before_write_error(chartInstance->S, 87U, 18U, 18, 4);
        }

        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r1 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_sb_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr19 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr19, 62U);
      *chartInstance->c3_dp19 = *chartInstance->c3_j1;
      chartInstance->c3_dataWrittenToVector[90U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp19, 11U);
      *chartInstance->c3_vs19 = 1.0;
      chartInstance->c3_dataWrittenToVector[13U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs19, 87U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c3_sfEvent);
}

static void c3_r19(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 45U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r19) {
   case c3_IN_Next:
    CV_STATE_EVAL(45, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 81U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r19 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r19 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 47U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_wb_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_vr19 = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr19, 62U);
    *chartInstance->c3_dp19 = 0.0;
    chartInstance->c3_dataWrittenToVector[90U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp19, 11U);
    *chartInstance->c3_vs19 = 0.0;
    chartInstance->c3_dataWrittenToVector[13U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs19, 87U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 46U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(45, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 82U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ff_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(82, 0, 0, CV_RELATIONAL_EVAL(5U, 82U, 0,
          *chartInstance->c3_vr19, 1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 82U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r19 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 47U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r19 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 48U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i14 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ub_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr19 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr19, 62U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 47U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 47U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(45, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 83U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ef_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(83, 0, 0, *chartInstance->c3_temporalCounter_i14 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 233U, 1, 14))) {
      if (CV_EML_COND(83, 0, 1, CV_RELATIONAL_EVAL(5U, 83U, 0,
            *chartInstance->c3_vr2, 0.0, -1, 0U, *chartInstance->c3_vr2 == 0.0)))
      {
        if (CV_EML_COND(83, 0, 2, CV_RELATIONAL_EVAL(5U, 83U, 1,
              *chartInstance->c3_vs19, 0.0, -1, 4U, *chartInstance->c3_vs19 >
              0.0))) {
          CV_EML_MCDC(83, 0, 0, true);
          CV_EML_IF(83, 0, 0, true);
          c3_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          sf_read_before_write_error(chartInstance->S, 87U, 233U, 27, 4);
        }

        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(83, 0, 0, false);
      CV_EML_IF(83, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 83U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r19 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 48U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r19 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 46U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_vb_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr2 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr2, 63U);
      if (!chartInstance->c3_dataWrittenToVector[90U]) {
        sf_read_before_write_error(chartInstance->S, 11U, 234U, 24, 4);
      }

      *chartInstance->c3_dp2 = *chartInstance->c3_dp19;
      chartInstance->c3_dataWrittenToVector[14U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp2, 12U);
      if (!chartInstance->c3_dataWrittenToVector[12U]) {
        sf_read_before_write_error(chartInstance->S, 37U, 234U, 35, 4);
      }

      *chartInstance->c3_vn2 = *chartInstance->c3_vn19;
      chartInstance->c3_dataWrittenToVector[15U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn2, 38U);
      if (!chartInstance->c3_dataWrittenToVector[13U]) {
        sf_read_before_write_error(chartInstance->S, 87U, 234U, 46, 4);
      }

      *chartInstance->c3_vs2 = *chartInstance->c3_vs19;
      chartInstance->c3_dataWrittenToVector[16U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs2, 88U);
      *chartInstance->c3_vn19 = 0.0;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn19, 37U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 48U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 48U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(45, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r19 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 46U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 45U, *chartInstance->c3_sfEvent);
}

static void c3_r22(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 61U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r22) {
   case c3_IN_Next:
    CV_STATE_EVAL(61, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 97U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r22 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r22 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 63U, *chartInstance->c3_sfEvent);
    c3_m_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 62U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(61, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 94U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_hf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[64U]) {
      sf_read_before_write_error(chartInstance->S, 66U, 320U, 1, 4);
    }

    if (CV_EML_IF(94, 0, 0, CV_RELATIONAL_EVAL(5U, 94U, 0,
          *chartInstance->c3_vr22, 1.0, -1, 0U, *chartInstance->c3_vr22 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 94U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r22 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 63U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r22 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 64U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i15 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_xb_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr22 = 1.0;
      chartInstance->c3_dataWrittenToVector[64U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr22, 66U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 63U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 63U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(61, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 96U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_gf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(96, 0, 0, *chartInstance->c3_temporalCounter_i15 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 322U, 1, 14)) && CV_EML_COND(96, 0, 1,
         CV_RELATIONAL_EVAL(5U, 96U, 0, *chartInstance->c3_vr10, 0.0, -1, 0U,
                            *chartInstance->c3_vr10 == 0.0))) {
      CV_EML_MCDC(96, 0, 0, true);
      CV_EML_IF(96, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(96, 0, 0, false);
      CV_EML_IF(96, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 96U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r22 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 64U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r22 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 62U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_yb_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr10 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr10, 53U);
      if (!chartInstance->c3_dataWrittenToVector[65U]) {
        sf_read_before_write_error(chartInstance->S, 15U, 324U, 26, 4);
      }

      *chartInstance->c3_dp10 = *chartInstance->c3_dp22;
      chartInstance->c3_dataWrittenToVector[21U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp10, 2U);
      if (!chartInstance->c3_dataWrittenToVector[66U]) {
        sf_read_before_write_error(chartInstance->S, 41U, 324U, 38, 4);
      }

      *chartInstance->c3_vn10 = *chartInstance->c3_vn22;
      chartInstance->c3_dataWrittenToVector[22U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn10, 28U);
      if (!chartInstance->c3_dataWrittenToVector[67U]) {
        sf_read_before_write_error(chartInstance->S, 91U, 324U, 50, 4);
      }

      *chartInstance->c3_vs10 = *chartInstance->c3_vs22;
      chartInstance->c3_dataWrittenToVector[23U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs10, 78U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 64U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 64U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(61, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r22 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 62U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 61U, *chartInstance->c3_sfEvent);
}

static void c3_m_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ac_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr22 = 0.0;
  chartInstance->c3_dataWrittenToVector[64U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr22, 66U);
  *chartInstance->c3_dp22 = 0.0;
  chartInstance->c3_dataWrittenToVector[65U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp22, 15U);
  *chartInstance->c3_vs22 = 0.0;
  chartInstance->c3_dataWrittenToVector[67U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs22, 91U);
  *chartInstance->c3_vn22 = 0.0;
  chartInstance->c3_dataWrittenToVector[66U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn22, 41U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r17(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 37U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r17) {
   case c3_IN_Next:
    CV_STATE_EVAL(37, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 85U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r17 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r17 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 39U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_dc_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_vr17 = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr17, 60U);
    *chartInstance->c3_dp17 = 0.0;
    chartInstance->c3_dataWrittenToVector[40U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp17, 9U);
    *chartInstance->c3_vs17 = 0.0;
    chartInstance->c3_dataWrittenToVector[35U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs17, 85U);
    *chartInstance->c3_vn17 = 0.0;
    chartInstance->c3_dataWrittenToVector[39U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn17, 35U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 38U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(37, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 45U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_kf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(45, 0, 0, CV_RELATIONAL_EVAL(5U, 45U, 0,
          *chartInstance->c3_vr17, 1.0, -1, 0U, *chartInstance->c3_vr17 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r17 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 39U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r17 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 40U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i16 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_bc_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr17 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr17, 60U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 39U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 39U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(37, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_jf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(46, 0, 0, *chartInstance->c3_temporalCounter_i16 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 118U, 1, 14)) && CV_EML_COND(46, 0, 1,
         CV_RELATIONAL_EVAL(5U, 46U, 0, *chartInstance->c3_vr19, 0.0, -1, 0U,
                            *chartInstance->c3_vr19 == 0.0))) {
      CV_EML_MCDC(46, 0, 0, true);
      CV_EML_IF(46, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(46, 0, 0, false);
      CV_EML_IF(46, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r17 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 40U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r17 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 38U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_cc_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr19 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr19, 62U);
      if (!chartInstance->c3_dataWrittenToVector[40U]) {
        sf_read_before_write_error(chartInstance->S, 9U, 239U, 26, 4);
      }

      *chartInstance->c3_dp19 = *chartInstance->c3_dp17;
      chartInstance->c3_dataWrittenToVector[90U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp19, 11U);
      if (!chartInstance->c3_dataWrittenToVector[39U]) {
        sf_read_before_write_error(chartInstance->S, 35U, 239U, 38, 4);
      }

      *chartInstance->c3_vn19 = *chartInstance->c3_vn17;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn19, 37U);
      if (!chartInstance->c3_dataWrittenToVector[35U]) {
        sf_read_before_write_error(chartInstance->S, 85U, 239U, 50, 4);
      }

      *chartInstance->c3_vs19 = *chartInstance->c3_vs17;
      chartInstance->c3_dataWrittenToVector[13U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs19, 87U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 40U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(37, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r17 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 38U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *chartInstance->c3_sfEvent);
}

static void c3_r12(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  uint32_T c3_c_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  uint32_T c3_e_debug_family_var_map[3];
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  uint32_T c3_f_debug_family_var_map[2];
  real_T c3_e_nargout = 1.0;
  real_T c3_f_nargin = 0.0;
  boolean_T c3_d_out;
  real_T c3_f_nargout = 0.0;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_h_debug_family_var_map[2];
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r12) {
   case c3_IN_Next:
    CV_STATE_EVAL(15, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 52U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r12 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, *chartInstance->c3_sfEvent);
    c3_n_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(15, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 53U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_mf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[7U]) {
      sf_read_before_write_error(chartInstance->S, 55U, 158U, 1, 4);
    }

    if (CV_EML_IF(53, 0, 0, CV_RELATIONAL_EVAL(5U, 53U, 0,
          *chartInstance->c3_vr12, 1.0, -1, 0U, *chartInstance->c3_vr12 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 53U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r12 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i17 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ec_debug_family_names,
        c3_f_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr12 = 1.0;
      chartInstance->c3_dataWrittenToVector[7U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr12, 55U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(15, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 54U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_nf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[28U]) {
      sf_read_before_write_error(chartInstance->S, 4U, 159U, 1, 4);
    }

    if (CV_EML_COND(54, 0, 0, CV_RELATIONAL_EVAL(5U, 54U, 0,
          *chartInstance->c3_dp12, 3.0, -1, 0U, *chartInstance->c3_dp12 == 3.0))
        && CV_EML_COND(54, 0, 1, *chartInstance->c3_temporalCounter_i17 >=
                       c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d2 * 10.0), 159U, 9, 13))) {
      CV_EML_MCDC(54, 0, 0, true);
      CV_EML_IF(54, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(54, 0, 0, false);
      CV_EML_IF(54, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 54U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r12 = c3_IN_as3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i17 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_gc_debug_family_names,
        c3_g_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      (*chartInstance->c3_as3)++;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as3, 113U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 55U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_lf_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_COND(55, 0, 0, *chartInstance->c3_temporalCounter_i17 >=
                      c3__u32_d_(chartInstance, muDoubleScalarCeil
            (*chartInstance->c3_d1 * 10.0), 161U, 1, 14)) && CV_EML_COND(55, 0,
           1, CV_RELATIONAL_EVAL(5U, 55U, 0, *chartInstance->c3_vr13, 0.0, -1,
            0U, *chartInstance->c3_vr13 == 0.0))) {
        CV_EML_MCDC(55, 0, 0, true);
        CV_EML_IF(55, 0, 0, true);
        c3_d_out = true;
      } else {
        CV_EML_MCDC(55, 0, 0, false);
        CV_EML_IF(55, 0, 0, false);
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 55U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r12 = c3_IN_Next;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
        c3_c_enter_atomic_Next(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                     *chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_as3:
    CV_STATE_EVAL(15, 0, c3_IN_as3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 56U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_of_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(56, 0, 0, *chartInstance->c3_temporalCounter_i17 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 162U, 1, 13)) && CV_EML_COND(56, 0, 1,
         CV_RELATIONAL_EVAL(5U, 56U, 0, *chartInstance->c3_vr13, 0.0, -1, 0U,
                            *chartInstance->c3_vr13 == 0.0))) {
      CV_EML_MCDC(56, 0, 0, true);
      CV_EML_IF(56, 0, 0, true);
      c3_c_out = true;
    } else {
      CV_EML_MCDC(56, 0, 0, false);
      CV_EML_IF(56, 0, 0, false);
      c3_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 56U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_pf_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp12 = 0.0;
      chartInstance->c3_dataWrittenToVector[28U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp12, 4U);
      *chartInstance->c3_vs12 = 0.0;
      chartInstance->c3_dataWrittenToVector[36U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs12, 80U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 19U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_hc_debug_family_names,
        c3_h_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp12 = 0.0;
      chartInstance->c3_dataWrittenToVector[28U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp12, 4U);
      *chartInstance->c3_vs12 = 0.0;
      chartInstance->c3_dataWrittenToVector[36U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs12, 80U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r12 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
      c3_c_enter_atomic_Next(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(15, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r12 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *chartInstance->c3_sfEvent);
}

static void c3_c_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_fc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr13 = 1.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr13, 56U);
  if (!chartInstance->c3_dataWrittenToVector[28U]) {
    sf_read_before_write_error(chartInstance->S, 4U, 163U, 26, 4);
  }

  *chartInstance->c3_dp13 = *chartInstance->c3_dp12;
  chartInstance->c3_dataWrittenToVector[27U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp13, 5U);
  if (!chartInstance->c3_dataWrittenToVector[38U]) {
    sf_read_before_write_error(chartInstance->S, 30U, 163U, 38, 4);
  }

  *chartInstance->c3_vn13 = *chartInstance->c3_vn12;
  chartInstance->c3_dataWrittenToVector[44U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn13, 31U);
  if (!chartInstance->c3_dataWrittenToVector[36U]) {
    sf_read_before_write_error(chartInstance->S, 80U, 163U, 50, 4);
  }

  *chartInstance->c3_vs13 = *chartInstance->c3_vs12;
  chartInstance->c3_dataWrittenToVector[37U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs13, 81U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_n_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ic_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr12 = 0.0;
  chartInstance->c3_dataWrittenToVector[7U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr12, 55U);
  *chartInstance->c3_dp12 = 0.0;
  chartInstance->c3_dataWrittenToVector[28U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp12, 4U);
  *chartInstance->c3_vs12 = 0.0;
  chartInstance->c3_dataWrittenToVector[36U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs12, 80U);
  *chartInstance->c3_vn12 = 0.0;
  chartInstance->c3_dataWrittenToVector[38U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn12, 30U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r15(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  uint32_T c3_c_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  uint32_T c3_f_debug_family_var_map[3];
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_d_out;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  uint32_T c3_h_debug_family_var_map[2];
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 28U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r15) {
   case c3_IN_Next:
    CV_STATE_EVAL(28, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 69U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r15 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 30U, *chartInstance->c3_sfEvent);
    c3_o_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 29U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(28, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 68U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_sf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(68, 0, 0, CV_RELATIONAL_EVAL(5U, 68U, 0,
          *chartInstance->c3_vr15, 1.0, -1, 0U, *chartInstance->c3_vr15 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 68U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 30U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r15 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 31U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i18 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_jc_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr15 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr15, 58U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 30U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(28, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 66U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_qf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[31U]) {
      sf_read_before_write_error(chartInstance->S, 7U, 184U, 1, 4);
    }

    if (CV_EML_COND(66, 0, 0, CV_RELATIONAL_EVAL(5U, 66U, 0,
          *chartInstance->c3_dp15, 4.0, -1, 0U, *chartInstance->c3_dp15 == 4.0))
        && CV_EML_COND(66, 0, 1, *chartInstance->c3_temporalCounter_i18 >=
                       c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d2 * 10.0), 184U, 9, 13))) {
      CV_EML_MCDC(66, 0, 0, true);
      CV_EML_IF(66, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(66, 0, 0, false);
      CV_EML_IF(66, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 66U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r15 = c3_IN_as4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 32U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i18 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_mc_debug_family_names,
        c3_g_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      (*chartInstance->c3_as4)++;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_as4, 114U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 67U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_rf_debug_family_names,
        c3_f_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(67, 0, 0, *chartInstance->c3_temporalCounter_i18 >=
                      c3__u32_d_(chartInstance, muDoubleScalarCeil
            (*chartInstance->c3_d1 * 10.0), 186U, 1, 14))) {
        if (CV_EML_COND(67, 0, 1, CV_RELATIONAL_EVAL(5U, 67U, 0,
              *chartInstance->c3_vr25, 0.0, -1, 0U, *chartInstance->c3_vr25 ==
              0.0))) {
          CV_EML_MCDC(67, 0, 0, true);
          CV_EML_IF(67, 0, 0, true);
          c3_d_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[80U]) {
          sf_read_before_write_error(chartInstance->S, 69U, 186U, 18, 4);
        }

        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(67, 0, 0, false);
        CV_EML_IF(67, 0, 0, false);
        c3_d_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 67U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 31U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_r15 = c3_IN_Next;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
        c3_d_enter_atomic_Next(chartInstance);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 31U,
                     *chartInstance->c3_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_as4:
    CV_STATE_EVAL(28, 0, c3_IN_as4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 70U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_tf_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(70, 0, 0, *chartInstance->c3_temporalCounter_i18 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 190U, 1, 13))) {
      if (CV_EML_COND(70, 0, 1, CV_RELATIONAL_EVAL(5U, 70U, 0,
            *chartInstance->c3_vr25, 0.0, -1, 0U, *chartInstance->c3_vr25 == 0.0)))
      {
        CV_EML_MCDC(70, 0, 0, true);
        CV_EML_IF(70, 0, 0, true);
        c3_c_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[80U]) {
        sf_read_before_write_error(chartInstance->S, 69U, 190U, 15, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(70, 0, 0, false);
      CV_EML_IF(70, 0, 0, false);
      c3_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 70U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_uf_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp15 = 0.0;
      chartInstance->c3_dataWrittenToVector[31U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp15, 7U);
      *chartInstance->c3_vs15 = 0.0;
      chartInstance->c3_dataWrittenToVector[43U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs15, 83U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 32U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_nc_debug_family_names,
        c3_h_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dp15 = 0.0;
      chartInstance->c3_dataWrittenToVector[31U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp15, 7U);
      *chartInstance->c3_vs15 = 0.0;
      chartInstance->c3_dataWrittenToVector[43U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs15, 83U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 32U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r15 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
      c3_d_enter_atomic_Next(chartInstance);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 32U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(28, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r15 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 29U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *chartInstance->c3_sfEvent);
}

static void c3_d_enter_atomic_Next(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_kc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr25 = 1.0;
  chartInstance->c3_dataWrittenToVector[80U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr25, 69U);
  if (!chartInstance->c3_dataWrittenToVector[31U]) {
    sf_read_before_write_error(chartInstance->S, 7U, 183U, 26, 4);
  }

  *chartInstance->c3_dp25 = *chartInstance->c3_dp15;
  chartInstance->c3_dataWrittenToVector[83U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp25, 18U);
  if (!chartInstance->c3_dataWrittenToVector[29U]) {
    sf_read_before_write_error(chartInstance->S, 33U, 183U, 38, 4);
  }

  *chartInstance->c3_vn25 = *chartInstance->c3_vn15;
  chartInstance->c3_dataWrittenToVector[82U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn25, 44U);
  if (!chartInstance->c3_dataWrittenToVector[43U]) {
    sf_read_before_write_error(chartInstance->S, 83U, 183U, 50, 4);
  }

  *chartInstance->c3_vs25 = *chartInstance->c3_vs15;
  chartInstance->c3_dataWrittenToVector[81U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs25, 94U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_o_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_lc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr15 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr15, 58U);
  *chartInstance->c3_dp15 = 0.0;
  chartInstance->c3_dataWrittenToVector[31U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp15, 7U);
  *chartInstance->c3_vs15 = 0.0;
  chartInstance->c3_dataWrittenToVector[43U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs15, 83U);
  *chartInstance->c3_vn15 = 0.0;
  chartInstance->c3_dataWrittenToVector[29U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn15, 33U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r14(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 24U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r14) {
   case c3_IN_Next:
    CV_STATE_EVAL(24, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 62U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r14 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r14 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 26U, *chartInstance->c3_sfEvent);
    c3_p_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(24, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 63U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_wf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(63, 0, 0, CV_RELATIONAL_EVAL(5U, 63U, 0,
          *chartInstance->c3_vr14, 1.0, -1, 0U, *chartInstance->c3_vr14 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 63U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r14 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 26U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r14 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 27U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i19 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_oc_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr14 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr14, 57U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 26U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(24, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 64U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_vf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(64, 0, 0, *chartInstance->c3_temporalCounter_i19 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 177U, 1, 14)) && CV_EML_COND(64, 0, 1,
         CV_RELATIONAL_EVAL(5U, 64U, 0, *chartInstance->c3_vr15, 0.0, -1, 0U,
                            *chartInstance->c3_vr15 == 0.0))) {
      CV_EML_MCDC(64, 0, 0, true);
      CV_EML_IF(64, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(64, 0, 0, false);
      CV_EML_IF(64, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 64U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r14 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 27U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r14 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 25U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_pc_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr15 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr15, 58U);
      if (!chartInstance->c3_dataWrittenToVector[34U]) {
        sf_read_before_write_error(chartInstance->S, 6U, 181U, 26, 4);
      }

      *chartInstance->c3_dp15 = *chartInstance->c3_dp14;
      chartInstance->c3_dataWrittenToVector[31U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp15, 7U);
      if (!chartInstance->c3_dataWrittenToVector[33U]) {
        sf_read_before_write_error(chartInstance->S, 32U, 181U, 38, 4);
      }

      *chartInstance->c3_vn15 = *chartInstance->c3_vn14;
      chartInstance->c3_dataWrittenToVector[29U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn15, 33U);
      if (!chartInstance->c3_dataWrittenToVector[32U]) {
        sf_read_before_write_error(chartInstance->S, 82U, 181U, 50, 4);
      }

      *chartInstance->c3_vs15 = *chartInstance->c3_vs14;
      chartInstance->c3_dataWrittenToVector[43U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs15, 83U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 27U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(24, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r14 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 25U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *chartInstance->c3_sfEvent);
}

static void c3_p_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr14 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr14, 57U);
  *chartInstance->c3_dp14 = 0.0;
  chartInstance->c3_dataWrittenToVector[34U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp14, 6U);
  *chartInstance->c3_vs14 = 0.0;
  chartInstance->c3_dataWrittenToVector[32U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs14, 82U);
  *chartInstance->c3_vn14 = 0.0;
  chartInstance->c3_dataWrittenToVector[33U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn14, 32U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r10(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r10) {
   case c3_IN_Next:
    CV_STATE_EVAL(7, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r10 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r10 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_tc_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_vr10 = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr10, 53U);
    *chartInstance->c3_dp10 = 0.0;
    chartInstance->c3_dataWrittenToVector[21U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp10, 2U);
    *chartInstance->c3_vs10 = 0.0;
    chartInstance->c3_dataWrittenToVector[23U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs10, 78U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(7, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_yf_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(25, 0, 0, CV_RELATIONAL_EVAL(5U, 25U, 0,
          *chartInstance->c3_vr10, 1.0, -1, 0U, *chartInstance->c3_vr10 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r10 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r10 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i20 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_rc_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr10 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr10, 53U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(7, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_xf_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(26, 0, 0, *chartInstance->c3_temporalCounter_i20 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 69U, 1, 14))) {
      if (CV_EML_COND(26, 0, 1, CV_RELATIONAL_EVAL(5U, 26U, 0,
            *chartInstance->c3_vr11, 0.0, -1, 0U, *chartInstance->c3_vr11 == 0.0)))
      {
        CV_EML_MCDC(26, 0, 0, true);
        CV_EML_IF(26, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[6U]) {
        sf_read_before_write_error(chartInstance->S, 54U, 69U, 18, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(26, 0, 0, false);
      CV_EML_IF(26, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r10 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r10 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_sc_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr11 = 1.0;
      chartInstance->c3_dataWrittenToVector[6U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr11, 54U);
      if (!chartInstance->c3_dataWrittenToVector[21U]) {
        sf_read_before_write_error(chartInstance->S, 2U, 72U, 26, 4);
      }

      *chartInstance->c3_dp11 = *chartInstance->c3_dp10;
      chartInstance->c3_dataWrittenToVector[24U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp11, 3U);
      if (!chartInstance->c3_dataWrittenToVector[22U]) {
        sf_read_before_write_error(chartInstance->S, 28U, 72U, 38, 4);
      }

      *chartInstance->c3_vn11 = *chartInstance->c3_vn10;
      chartInstance->c3_dataWrittenToVector[25U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn11, 29U);
      if (!chartInstance->c3_dataWrittenToVector[23U]) {
        sf_read_before_write_error(chartInstance->S, 78U, 72U, 50, 4);
      }

      *chartInstance->c3_vs11 = *chartInstance->c3_vs10;
      chartInstance->c3_dataWrittenToVector[41U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs11, 79U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(7, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r10 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *chartInstance->c3_sfEvent);
}

static void c3_r11(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r11) {
   case c3_IN_Next:
    CV_STATE_EVAL(11, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r11 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r11 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
    c3_q_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(11, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_bg_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[6U]) {
      sf_read_before_write_error(chartInstance->S, 54U, 112U, 1, 4);
    }

    if (CV_EML_IF(43, 0, 0, CV_RELATIONAL_EVAL(5U, 43U, 0,
          *chartInstance->c3_vr11, 1.0, -1, 0U, *chartInstance->c3_vr11 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r11 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r11 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i21 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_uc_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr11 = 1.0;
      chartInstance->c3_dataWrittenToVector[6U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr11, 54U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(11, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ag_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    guard1 = false;
    if (CV_EML_COND(42, 0, 0, *chartInstance->c3_temporalCounter_i21 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 110U, 1, 14))) {
      if (CV_EML_COND(42, 0, 1, CV_RELATIONAL_EVAL(5U, 42U, 0,
            *chartInstance->c3_vr12, 0.0, -1, 0U, *chartInstance->c3_vr12 == 0.0)))
      {
        CV_EML_MCDC(42, 0, 0, true);
        CV_EML_IF(42, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[7U]) {
        sf_read_before_write_error(chartInstance->S, 55U, 110U, 18, 4);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(42, 0, 0, false);
      CV_EML_IF(42, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r11 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r11 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_vc_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr12 = 1.0;
      chartInstance->c3_dataWrittenToVector[7U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr12, 55U);
      if (!chartInstance->c3_dataWrittenToVector[24U]) {
        sf_read_before_write_error(chartInstance->S, 3U, 109U, 26, 4);
      }

      *chartInstance->c3_dp12 = *chartInstance->c3_dp11;
      chartInstance->c3_dataWrittenToVector[28U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp12, 4U);
      if (!chartInstance->c3_dataWrittenToVector[25U]) {
        sf_read_before_write_error(chartInstance->S, 29U, 109U, 38, 4);
      }

      *chartInstance->c3_vn12 = *chartInstance->c3_vn11;
      chartInstance->c3_dataWrittenToVector[38U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn12, 30U);
      if (!chartInstance->c3_dataWrittenToVector[41U]) {
        sf_read_before_write_error(chartInstance->S, 79U, 109U, 50, 4);
      }

      *chartInstance->c3_vs12 = *chartInstance->c3_vs11;
      chartInstance->c3_dataWrittenToVector[36U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs12, 80U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r11 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c3_sfEvent);
}

static void c3_q_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_wc_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr11 = 0.0;
  chartInstance->c3_dataWrittenToVector[6U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr11, 54U);
  *chartInstance->c3_dp11 = 0.0;
  chartInstance->c3_dataWrittenToVector[24U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp11, 3U);
  *chartInstance->c3_vs11 = 0.0;
  chartInstance->c3_dataWrittenToVector[41U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs11, 79U);
  *chartInstance->c3_vn11 = 0.0;
  chartInstance->c3_dataWrittenToVector[25U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn11, 29U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_r16(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 33U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r16) {
   case c3_IN_Next:
    CV_STATE_EVAL(33, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 71U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r16 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r16 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 35U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_yc_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_vr16 = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr16, 59U);
    *chartInstance->c3_dp16 = 0.0;
    chartInstance->c3_dataWrittenToVector[26U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp16, 8U);
    *chartInstance->c3_vs16 = 0.0;
    chartInstance->c3_dataWrittenToVector[42U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs16, 84U);
    *chartInstance->c3_vn16 = 0.0;
    chartInstance->c3_dataWrittenToVector[30U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn16, 34U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(33, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 72U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_eg_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(72, 0, 0, CV_RELATIONAL_EVAL(5U, 72U, 0,
          *chartInstance->c3_vr16, 1.0, -1, 0U, *chartInstance->c3_vr16 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 72U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r16 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 35U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r16 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 36U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i22 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_xc_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr16 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr16, 59U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 35U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 35U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(33, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 73U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_dg_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(73, 0, 0, *chartInstance->c3_temporalCounter_i22 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 196U, 1, 13)) && CV_EML_COND(73, 0, 1,
         CV_RELATIONAL_EVAL(5U, 73U, 0, *chartInstance->c3_vr17, 0.0, -1, 0U,
                            *chartInstance->c3_vr17 == 0.0))) {
      CV_EML_MCDC(73, 0, 0, true);
      CV_EML_IF(73, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(73, 0, 0, false);
      CV_EML_IF(73, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 73U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r16 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 36U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r16 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 34U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ad_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr17 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr17, 60U);
      if (!chartInstance->c3_dataWrittenToVector[26U]) {
        sf_read_before_write_error(chartInstance->S, 8U, 197U, 26, 4);
      }

      *chartInstance->c3_dp17 = *chartInstance->c3_dp16;
      chartInstance->c3_dataWrittenToVector[40U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp17, 9U);
      if (!chartInstance->c3_dataWrittenToVector[30U]) {
        sf_read_before_write_error(chartInstance->S, 34U, 197U, 38, 4);
      }

      *chartInstance->c3_vn17 = *chartInstance->c3_vn16;
      chartInstance->c3_dataWrittenToVector[39U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn17, 35U);
      if (!chartInstance->c3_dataWrittenToVector[42U]) {
        sf_read_before_write_error(chartInstance->S, 84U, 197U, 50, 4);
      }

      *chartInstance->c3_vs17 = *chartInstance->c3_vs16;
      chartInstance->c3_dataWrittenToVector[35U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs17, 85U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 36U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 36U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(33, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r16 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 34U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, *chartInstance->c3_sfEvent);
}

static void c3_r23(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 65U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r23) {
   case c3_IN_Next:
    CV_STATE_EVAL(65, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 98U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r23 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r23 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 67U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_dd_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_vr23 = 0.0;
    chartInstance->c3_dataWrittenToVector[69U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr23, 67U);
    *chartInstance->c3_dp23 = 0.0;
    chartInstance->c3_dataWrittenToVector[70U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp23, 16U);
    *chartInstance->c3_vs23 = 0.0;
    chartInstance->c3_dataWrittenToVector[68U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs23, 92U);
    *chartInstance->c3_vn23 = 0.0;
    chartInstance->c3_dataWrittenToVector[71U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn23, 42U);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 66U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(65, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 99U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_hg_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[69U]) {
      sf_read_before_write_error(chartInstance->S, 67U, 329U, 1, 4);
    }

    if (CV_EML_IF(99, 0, 0, CV_RELATIONAL_EVAL(5U, 99U, 0,
          *chartInstance->c3_vr23, 1.0, -1, 0U, *chartInstance->c3_vr23 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 99U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r23 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 67U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r23 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 68U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i23 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_bd_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr23 = 1.0;
      chartInstance->c3_dataWrittenToVector[69U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr23, 67U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 67U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 67U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(65, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 101U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_gg_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(101, 0, 0, *chartInstance->c3_temporalCounter_i23 >=
                    c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 334U, 1, 13)) && CV_EML_COND(101, 0, 1,
         CV_RELATIONAL_EVAL(5U, 101U, 0, *chartInstance->c3_vr16, 0.0, -1, 0U,
                            *chartInstance->c3_vr16 == 0.0))) {
      CV_EML_MCDC(101, 0, 0, true);
      CV_EML_IF(101, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(101, 0, 0, false);
      CV_EML_IF(101, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 101U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r23 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 68U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r23 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 66U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_cd_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr16 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr16, 59U);
      if (!chartInstance->c3_dataWrittenToVector[70U]) {
        sf_read_before_write_error(chartInstance->S, 16U, 330U, 26, 4);
      }

      *chartInstance->c3_dp16 = *chartInstance->c3_dp23;
      chartInstance->c3_dataWrittenToVector[26U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp16, 8U);
      if (!chartInstance->c3_dataWrittenToVector[71U]) {
        sf_read_before_write_error(chartInstance->S, 42U, 330U, 38, 4);
      }

      *chartInstance->c3_vn16 = *chartInstance->c3_vn23;
      chartInstance->c3_dataWrittenToVector[30U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn16, 34U);
      if (!chartInstance->c3_dataWrittenToVector[68U]) {
        sf_read_before_write_error(chartInstance->S, 92U, 330U, 50, 4);
      }

      *chartInstance->c3_vs16 = *chartInstance->c3_vs23;
      chartInstance->c3_dataWrittenToVector[42U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs16, 84U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 68U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 68U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(65, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r23 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 66U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 65U, *chartInstance->c3_sfEvent);
}

static void c3_r13(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[2];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_r13) {
   case c3_IN_Next:
    CV_STATE_EVAL(20, 0, c3_IN_Next);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 58U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r13 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_r13 = c3_IN_Off;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, *chartInstance->c3_sfEvent);
    c3_r_enter_atomic_Off(chartInstance);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Off:
    CV_STATE_EVAL(20, 0, c3_IN_Off);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 60U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_jg_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(60, 0, 0, CV_RELATIONAL_EVAL(5U, 60U, 0,
          *chartInstance->c3_vr13, 1.0, -1, 0U, *chartInstance->c3_vr13 == 1.0)))
    {
      c3_out = true;
    } else {
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 60U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r13 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r13 = c3_IN_On;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 23U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_temporalCounter_i24 = 0U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ed_debug_family_names,
        c3_c_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr13 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr13, 56U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_On:
    CV_STATE_EVAL(20, 0, c3_IN_On);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 59U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ig_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(59, 0, 0, CV_RELATIONAL_EVAL(5U, 59U, 0,
          *chartInstance->c3_vr14, 0.0, -1, 0U, *chartInstance->c3_vr14 == 0.0))
        && CV_EML_COND(59, 0, 1, *chartInstance->c3_temporalCounter_i24 >=
                       c3__u32_d_(chartInstance, muDoubleScalarCeil
          (*chartInstance->c3_d1 * 10.0), 168U, 11, 14))) {
      CV_EML_MCDC(59, 0, 0, true);
      CV_EML_IF(59, 0, 0, true);
      c3_b_out = true;
    } else {
      CV_EML_MCDC(59, 0, 0, false);
      CV_EML_IF(59, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 59U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r13 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 23U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_r13 = c3_IN_Next;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_fd_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_vr14 = 1.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr14, 57U);
      if (!chartInstance->c3_dataWrittenToVector[27U]) {
        sf_read_before_write_error(chartInstance->S, 5U, 169U, 26, 4);
      }

      *chartInstance->c3_dp14 = *chartInstance->c3_dp13;
      chartInstance->c3_dataWrittenToVector[34U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp14, 6U);
      if (!chartInstance->c3_dataWrittenToVector[44U]) {
        sf_read_before_write_error(chartInstance->S, 31U, 169U, 38, 4);
      }

      *chartInstance->c3_vn14 = *chartInstance->c3_vn13;
      chartInstance->c3_dataWrittenToVector[33U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn14, 32U);
      if (!chartInstance->c3_dataWrittenToVector[37U]) {
        sf_read_before_write_error(chartInstance->S, 81U, 169U, 50, 4);
      }

      *chartInstance->c3_vs14 = *chartInstance->c3_vs13;
      chartInstance->c3_dataWrittenToVector[32U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs14, 82U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 23U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 23U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(20, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_r13 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, *chartInstance->c3_sfEvent);
}

static void c3_r_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_gd_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr13 = 0.0;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr13, 56U);
  *chartInstance->c3_dp13 = 0.0;
  chartInstance->c3_dataWrittenToVector[27U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp13, 5U);
  *chartInstance->c3_vs13 = 0.0;
  chartInstance->c3_dataWrittenToVector[37U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs13, 81U);
  *chartInstance->c3_vn13 = 0.0;
  chartInstance->c3_dataWrittenToVector[44U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn13, 31U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_s_enter_atomic_Off(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_jd_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  *chartInstance->c3_vr25 = 0.0;
  chartInstance->c3_dataWrittenToVector[80U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vr25, 69U);
  *chartInstance->c3_dp25 = 0.0;
  chartInstance->c3_dataWrittenToVector[83U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dp25, 18U);
  *chartInstance->c3_vs25 = 0.0;
  chartInstance->c3_dataWrittenToVector[81U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vs25, 94U);
  *chartInstance->c3_vn25 = 0.0;
  chartInstance->c3_dataWrittenToVector[82U] = true;
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_vn25, 44U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_is(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  uint32_T c3_b_debug_family_var_map[3];
  uint32_T c3_c_debug_family_var_map[3];
  uint32_T c3_d_debug_family_var_map[3];
  uint32_T c3_e_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  uint32_T c3_f_debug_family_var_map[3];
  real_T c3_nargout = 1.0;
  real_T c3_b_nargout = 1.0;
  real_T c3_c_nargout = 1.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_e_nargout = 1.0;
  real_T c3_f_nargin = 0.0;
  boolean_T c3_out;
  boolean_T c3_b_out;
  boolean_T c3_c_out;
  boolean_T c3_d_out;
  boolean_T c3_e_out;
  real_T c3_f_nargout = 1.0;
  boolean_T c3_f_out;
  uint32_T c3_g_debug_family_var_map[2];
  real_T c3_g_nargin = 0.0;
  uint32_T c3_h_debug_family_var_map[2];
  uint32_T c3_i_debug_family_var_map[2];
  uint32_T c3_j_debug_family_var_map[2];
  uint32_T c3_k_debug_family_var_map[2];
  uint32_T c3_l_debug_family_var_map[2];
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_j_nargin = 0.0;
  real_T c3_k_nargin = 0.0;
  real_T c3_l_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_k_nargout = 0.0;
  real_T c3_l_nargout = 0.0;
  uint32_T c3_m_debug_family_var_map[2];
  real_T c3_m_nargin = 0.0;
  uint32_T c3_n_debug_family_var_map[2];
  real_T c3_m_nargout = 0.0;
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 0.0;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 115U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_is) {
   case c3_IN_A0:
    CV_STATE_EVAL(115, 0, c3_IN_A0);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 128U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_sg_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[89U]) {
      sf_read_before_write_error(chartInstance->S, 27U, 748U, 1, 5);
    }

    if (CV_EML_COND(128, 0, 0, CV_RELATIONAL_EVAL(5U, 128U, 0,
          *chartInstance->c3_sayac, 0.0, -1, 4U, *chartInstance->c3_sayac > 0.0))
        && CV_EML_COND(128, 0, 1, CV_RELATIONAL_EVAL(5U, 128U, 1,
          *chartInstance->c3_vr19, 1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0)))
    {
      CV_EML_MCDC(128, 0, 0, true);
      CV_EML_IF(128, 0, 0, true);
      c3_out = true;
    } else {
      CV_EML_MCDC(128, 0, 0, false);
      CV_EML_IF(128, 0, 0, false);
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 128U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_tg_debug_family_names,
        c3_g_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[89U]) {
        sf_read_before_write_error(chartInstance->S, 27U, 748U, 24, 5);
      }

      (*chartInstance->c3_sayac)--;
      chartInstance->c3_dataWrittenToVector[89U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
      _SFD_SYMBOL_SCOPE_POP();
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 116U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_A1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_od_debug_family_names,
        c3_m_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_j1 = 1.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 500U,
        6, 4);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 116U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 116U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_A1:
    CV_STATE_EVAL(115, 0, c3_IN_A1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 120U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ug_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[90U]) {
      sf_read_before_write_error(chartInstance->S, 11U, 508U, 1, 4);
    }

    if (CV_EML_IF(120, 0, 0, CV_RELATIONAL_EVAL(5U, 120U, 0,
          *chartInstance->c3_dp19, 1.0, -1, 0U, *chartInstance->c3_dp19 == 1.0)))
    {
      c3_b_out = true;
    } else {
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 120U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_A2;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 118U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_pd_debug_family_names,
        c3_h_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_j1 = 2.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 505U,
        6, 4);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 117U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 117U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_A2:
    CV_STATE_EVAL(115, 0, c3_IN_A2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 121U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_vg_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[90U]) {
      sf_read_before_write_error(chartInstance->S, 11U, 509U, 1, 4);
    }

    if (CV_EML_IF(121, 0, 0, CV_RELATIONAL_EVAL(5U, 121U, 0,
          *chartInstance->c3_dp19, 2.0, -1, 0U, *chartInstance->c3_dp19 == 2.0)))
    {
      c3_c_out = true;
    } else {
      c3_c_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 121U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 118U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_A3;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qd_debug_family_names,
        c3_i_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_j1 = 3.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 506U,
        6, 4);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 118U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 118U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_A3:
    CV_STATE_EVAL(115, 0, c3_IN_A3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 122U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_wg_debug_family_names,
      c3_d_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[90U]) {
      sf_read_before_write_error(chartInstance->S, 11U, 510U, 1, 4);
    }

    if (CV_EML_IF(122, 0, 0, CV_RELATIONAL_EVAL(5U, 122U, 0,
          *chartInstance->c3_dp19, 3.0, -1, 0U, *chartInstance->c3_dp19 == 3.0)))
    {
      c3_d_out = true;
    } else {
      c3_d_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 122U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_A4;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 120U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_rd_debug_family_names,
        c3_j_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_j1 = 4.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 507U,
        6, 4);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 119U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 119U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_A4:
    CV_STATE_EVAL(115, 0, c3_IN_A4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 123U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_rg_debug_family_names,
      c3_e_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[90U]) {
      sf_read_before_write_error(chartInstance->S, 11U, 511U, 1, 4);
    }

    if (CV_EML_IF(123, 0, 0, CV_RELATIONAL_EVAL(5U, 123U, 0,
          *chartInstance->c3_dp19, 4.0, -1, 0U, *chartInstance->c3_dp19 == 4.0)))
    {
      c3_e_out = true;
    } else {
      c3_e_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 120U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_A0;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 116U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_nd_debug_family_names,
        c3_k_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_j1 = 0.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 747U,
        6, 4);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 120U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 120U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_az:
    CV_STATE_EVAL(115, 0, c3_IN_az);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 116U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 119U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_pg_debug_family_names,
      c3_f_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[89U]) {
      sf_read_before_write_error(chartInstance->S, 27U, 504U, 1, 5);
    }

    if (CV_EML_COND(119, 0, 0, CV_RELATIONAL_EVAL(5U, 119U, 0,
          *chartInstance->c3_sayac, 0.0, -1, 4U, *chartInstance->c3_sayac > 0.0))
        && CV_EML_COND(119, 0, 1, CV_RELATIONAL_EVAL(5U, 119U, 1,
          *chartInstance->c3_vr19, 1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0)))
    {
      CV_EML_MCDC(119, 0, 0, true);
      CV_EML_IF(119, 0, 0, true);
      c3_f_out = true;
    } else {
      CV_EML_MCDC(119, 0, 0, false);
      CV_EML_IF(119, 0, 0, false);
      c3_f_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qg_debug_family_names,
        c3_l_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[89U]) {
        sf_read_before_write_error(chartInstance->S, 27U, 504U, 24, 5);
      }

      (*chartInstance->c3_sayac)--;
      chartInstance->c3_dataWrittenToVector[89U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
      _SFD_SYMBOL_SCOPE_POP();
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 121U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_A1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_od_debug_family_names,
        c3_n_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_j1 = 1.0;
      _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 500U,
        6, 4);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 121U,
                   *chartInstance->c3_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 121U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_cok:
    CV_STATE_EVAL(115, 0, c3_IN_cok);
    c3_cok(chartInstance);
    break;

   case c3_IN_is_secim:
    CV_STATE_EVAL(115, 0, c3_IN_is_secim);
    c3_is_secim(chartInstance);
    break;

   case c3_IN_orta:
    CV_STATE_EVAL(115, 0, c3_IN_orta);
    c3_orta(chartInstance);
    break;

   default:
    CV_STATE_EVAL(115, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 116U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 115U, *chartInstance->c3_sfEvent);
}

static void c3_is_secim(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  uint32_T c3_d_debug_family_var_map[3];
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  boolean_T c3_c_out;
  uint32_T c3_e_debug_family_var_map[2];
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 0.0;
  uint32_T c3_f_debug_family_var_map[2];
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 113U,
               *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_mg_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  if (CV_EML_IF(113, 0, 0, CV_RELATIONAL_EVAL(5U, 113U, 0,
        *chartInstance->c3_yuk, 1.0, -1, 0U, *chartInstance->c3_yuk == 1.0))) {
    c3_out = true;
  } else {
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 113U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_is = c3_IN_az;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 121U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_kd_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_dag = 2.0;
    chartInstance->c3_dataWrittenToVector[88U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dag, 0U);
    *chartInstance->c3_sayac = 2.0;
    chartInstance->c3_dataWrittenToVector[89U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 114U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_og_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_IF(114, 0, 0, CV_RELATIONAL_EVAL(5U, 114U, 0,
          *chartInstance->c3_yuk, 2.0, -1, 0U, *chartInstance->c3_yuk == 2.0)))
    {
      c3_b_out = true;
    } else {
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 114U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_is = c3_IN_orta;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 124U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_md_debug_family_names,
        c3_e_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      *chartInstance->c3_dag = 3.0;
      chartInstance->c3_dataWrittenToVector[88U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dag, 0U);
      *chartInstance->c3_sayac = 3.0;
      chartInstance->c3_dataWrittenToVector[89U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 115U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_ng_debug_family_names,
        c3_d_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_b_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
        c3_b_sf_marshallOut, c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_IF(115, 0, 0, CV_RELATIONAL_EVAL(5U, 115U, 0,
            *chartInstance->c3_yuk, 3.0, -1, 0U, *chartInstance->c3_yuk == 3.0)))
      {
        c3_c_out = true;
      } else {
        c3_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 115U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 123U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_is = c3_IN_cok;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 122U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_ld_debug_family_names,
          c3_f_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
          c3_b_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_b_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_dag = 4.0;
        chartInstance->c3_dataWrittenToVector[88U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dag, 0U);
        *chartInstance->c3_sayac = 4.0;
        chartInstance->c3_dataWrittenToVector[89U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 123U,
                     *chartInstance->c3_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 123U, *chartInstance->c3_sfEvent);
}

static void c3_cok(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 118U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 119U,
               *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_pg_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[89U]) {
    sf_read_before_write_error(chartInstance->S, 27U, 504U, 1, 5);
  }

  if (CV_EML_COND(119, 0, 0, CV_RELATIONAL_EVAL(5U, 119U, 0,
        *chartInstance->c3_sayac, 0.0, -1, 4U, *chartInstance->c3_sayac > 0.0)) &&
      CV_EML_COND(119, 0, 1, CV_RELATIONAL_EVAL(5U, 119U, 1,
        *chartInstance->c3_vr19, 1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0)))
  {
    CV_EML_MCDC(119, 0, 0, true);
    CV_EML_IF(119, 0, 0, true);
    c3_out = true;
  } else {
    CV_EML_MCDC(119, 0, 0, false);
    CV_EML_IF(119, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qg_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[89U]) {
      sf_read_before_write_error(chartInstance->S, 27U, 504U, 24, 5);
    }

    (*chartInstance->c3_sayac)--;
    chartInstance->c3_dataWrittenToVector[89U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
    _SFD_SYMBOL_SCOPE_POP();
    *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 122U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_is = c3_IN_A1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_od_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_j1 = 1.0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 500U, 6,
      4);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 122U,
                 *chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 122U, *chartInstance->c3_sfEvent);
}

static void c3_orta(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  uint32_T c3_c_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 119U,
               *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_pg_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
    c3_b_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[89U]) {
    sf_read_before_write_error(chartInstance->S, 27U, 504U, 1, 5);
  }

  if (CV_EML_COND(119, 0, 0, CV_RELATIONAL_EVAL(5U, 119U, 0,
        *chartInstance->c3_sayac, 0.0, -1, 4U, *chartInstance->c3_sayac > 0.0)) &&
      CV_EML_COND(119, 0, 1, CV_RELATIONAL_EVAL(5U, 119U, 1,
        *chartInstance->c3_vr19, 1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0)))
  {
    CV_EML_MCDC(119, 0, 0, true);
    CV_EML_IF(119, 0, 0, true);
    c3_out = true;
  } else {
    CV_EML_MCDC(119, 0, 0, false);
    CV_EML_IF(119, 0, 0, false);
    c3_out = false;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 119U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_qg_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[89U]) {
      sf_read_before_write_error(chartInstance->S, 27U, 504U, 24, 5);
    }

    (*chartInstance->c3_sayac)--;
    chartInstance->c3_dataWrittenToVector[89U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_sayac, 27U);
    _SFD_SYMBOL_SCOPE_POP();
    *chartInstance->c3_is_is = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 124U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_is = c3_IN_A1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 117U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_od_debug_family_names,
      c3_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_b_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_j1 = 1.0;
    _SFD_DATA_RANGE_CHECK_MIN_MAX(*chartInstance->c3_j1, 26U, 0.0, 2.0, 500U, 6,
      4);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 124U,
                 *chartInstance->c3_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 124U, *chartInstance->c3_sfEvent);
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[3])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 3), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[8])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 8), false);
  return c3_y;
}

static const mxArray *c3_c_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[9])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 9), false);
  return c3_y;
}

static const mxArray *c3_d_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[6])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 6), false);
  return c3_y;
}

static const mxArray *c3_e_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const real_T c3_u)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_f_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[15])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 15), false);
  return c3_y;
}

static const mxArray *c3_g_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const char_T c3_u[5])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 5), false);
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance, const real_T c3_u[2])
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  return c3_y;
}

static const mxArray *c3_i_emlrt_marshallOut(SFc3_ver_601InstanceStruct
  *chartInstance)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 10, 0U, 1U, 0U, 2, 1, 0), false);
  return c3_y;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  const mxArray *c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = sf_mex_dup(*(const mxArray **)c3_inData);
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_nargin, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargin), &c3_thisId);
  sf_mex_destroy(&c3_nargin);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargin;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_nargin = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargin), &c3_thisId);
  sf_mex_destroy(&c3_nargin);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b1, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_ver_601_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_color1(SFc3_ver_601InstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[35];
  const mxArray *c3_txt1 = NULL;
  const mxArray *c3_txt19 = NULL;
  const mxArray *c3_txt2 = NULL;
  const mxArray *c3_txt3 = NULL;
  const mxArray *c3_txt24 = NULL;
  const mxArray *c3_txt20 = NULL;
  const mxArray *c3_txt4 = NULL;
  const mxArray *c3_txt5 = NULL;
  const mxArray *c3_txt18 = NULL;
  const mxArray *c3_txt6 = NULL;
  const mxArray *c3_txt7 = NULL;
  const mxArray *c3_txt8 = NULL;
  const mxArray *c3_txt9 = NULL;
  const mxArray *c3_txt21 = NULL;
  const mxArray *c3_txt22 = NULL;
  const mxArray *c3_txt10 = NULL;
  const mxArray *c3_txt11 = NULL;
  const mxArray *c3_txt12 = NULL;
  const mxArray *c3_txt13 = NULL;
  const mxArray *c3_txt14 = NULL;
  const mxArray *c3_txt15 = NULL;
  const mxArray *c3_txt25 = NULL;
  const mxArray *c3_txt23 = NULL;
  const mxArray *c3_txt16 = NULL;
  const mxArray *c3_txt17 = NULL;
  const mxArray *c3_txt_as1 = NULL;
  const mxArray *c3_txt_as2 = NULL;
  const mxArray *c3_txt_as3 = NULL;
  const mxArray *c3_txt_as4 = NULL;
  const mxArray *c3_edt_as1 = NULL;
  const mxArray *c3_edt_as2 = NULL;
  const mxArray *c3_edt_as3 = NULL;
  const mxArray *c3_edt_as4 = NULL;
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  static char_T c3_cv0[3] = { 'T', 'a', 'g' };

  static char_T c3_cv1[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1' };

  static char_T c3_cv2[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '9' };

  static char_T c3_cv3[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2' };

  static char_T c3_cv4[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '3' };

  static char_T c3_cv5[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2', '4' };

  static char_T c3_cv6[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2', '0' };

  static char_T c3_cv7[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '4' };

  static char_T c3_cv8[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '5' };

  static char_T c3_cv9[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '8' };

  static char_T c3_cv10[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '6' };

  static char_T c3_cv11[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '7' };

  static char_T c3_cv12[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '8' };

  static char_T c3_cv13[8] = { 't', 'e', 'x', 't', '_', 'v', 'r', '9' };

  static char_T c3_cv14[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2', '1' };

  static char_T c3_cv15[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2', '2' };

  static char_T c3_cv16[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '0' };

  static char_T c3_cv17[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '1' };

  static char_T c3_cv18[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '2' };

  static char_T c3_cv19[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '3' };

  static char_T c3_cv20[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '4' };

  static char_T c3_cv21[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '5' };

  static char_T c3_cv22[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2', '5' };

  static char_T c3_cv23[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '2', '3' };

  static char_T c3_cv24[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '6' };

  static char_T c3_cv25[9] = { 't', 'e', 'x', 't', '_', 'v', 'r', '1', '7' };

  static char_T c3_cv26[8] = { 't', 'e', 'x', 't', '_', 'a', 's', '1' };

  static char_T c3_cv27[8] = { 't', 'e', 'x', 't', '_', 'a', 's', '2' };

  static char_T c3_cv28[8] = { 't', 'e', 'x', 't', '_', 'a', 's', '3' };

  static char_T c3_cv29[8] = { 't', 'e', 'x', 't', '_', 'a', 's', '4' };

  static char_T c3_cv30[8] = { 'e', 'd', 'i', 't', '_', 'a', 's', '1' };

  static char_T c3_cv31[6] = { 'S', 't', 'r', 'i', 'n', 'g' };

  static char_T c3_cv32[8] = { 'e', 'd', 'i', 't', '_', 'a', 's', '2' };

  static char_T c3_cv33[8] = { 'e', 'd', 'i', 't', '_', 'a', 's', '3' };

  static char_T c3_cv34[8] = { 'e', 'd', 'i', 't', '_', 'a', 's', '4' };

  static char_T c3_cv35[15] = { 'B', 'a', 'c', 'k', 'g', 'r', 'o', 'u', 'n', 'd',
    'C', 'o', 'l', 'o', 'r' };

  static char_T c3_cv36[5] = { 'w', 'h', 'i', 't', 'e' };

  static char_T c3_cv37[5] = { 'g', 'r', 'e', 'e', 'n' };

  real_T c3_dv0[2];
  real_T c3_dv1[2];
  real_T c3_dv2[2];
  real_T c3_dv3[2];
  real_T c3_dv4[2];
  real_T c3_dv5[2];
  real_T c3_dv6[2];
  real_T c3_dv7[2];
  real_T c3_dv8[2];
  real_T c3_dv9[2];
  real_T c3_dv10[2];
  real_T c3_dv11[2];
  real_T c3_dv12[2];
  real_T c3_dv13[2];
  real_T c3_dv14[2];
  real_T c3_dv15[2];
  real_T c3_dv16[2];
  real_T c3_dv17[2];
  real_T c3_dv18[2];
  real_T c3_dv19[2];
  real_T c3_dv20[2];
  real_T c3_dv21[2];
  real_T c3_dv22[2];
  real_T c3_dv23[2];
  static char_T c3_cv38[6] = { 'y', 'e', 'l', 'l', 'o', 'w' };

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 35U, 35U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt1, 0U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt19, 1U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt2, 2U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt3, 3U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt24, 4U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt20, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt4, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt5, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt18, 8U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt6, 9U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt7, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt8, 11U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt9, 12U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt21, 13U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt22, 14U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt10, 15U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt11, 16U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt12, 17U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt13, 18U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt14, 19U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt15, 20U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt25, 21U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt23, 22U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt16, 23U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt17, 24U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt_as1, 25U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt_as2, 26U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt_as3, 27U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_txt_as4, 28U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_edt_as1, 29U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_edt_as2, 30U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_edt_as3, 31U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_edt_as4, 32U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 33U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 34U, c3_b_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(2, 0);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 3);
  sf_mex_assign(&c3_txt1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv1)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 4);
  sf_mex_assign(&c3_txt19, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv2)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 5);
  sf_mex_assign(&c3_txt2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv3)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 6);
  sf_mex_assign(&c3_txt3, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv4)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 7);
  sf_mex_assign(&c3_txt24, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv5)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 8);
  sf_mex_assign(&c3_txt20, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv6)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 9);
  sf_mex_assign(&c3_txt4, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv7)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 10);
  sf_mex_assign(&c3_txt5, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv8)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 11);
  sf_mex_assign(&c3_txt18, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv9)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 12);
  sf_mex_assign(&c3_txt6, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv10)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 13);
  sf_mex_assign(&c3_txt7, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv11)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 14);
  sf_mex_assign(&c3_txt8, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv12)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 15);
  sf_mex_assign(&c3_txt9, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv13)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 16);
  sf_mex_assign(&c3_txt21, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv14)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 17);
  sf_mex_assign(&c3_txt22, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv15)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 18);
  sf_mex_assign(&c3_txt10, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv16)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 19);
  sf_mex_assign(&c3_txt11, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv17)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 20);
  sf_mex_assign(&c3_txt12, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv18)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 21);
  sf_mex_assign(&c3_txt13, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv19)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 22);
  sf_mex_assign(&c3_txt14, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv20)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 23);
  sf_mex_assign(&c3_txt15, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv21)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 24);
  sf_mex_assign(&c3_txt25, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv22)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 25);
  sf_mex_assign(&c3_txt23, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv23)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 26);
  sf_mex_assign(&c3_txt16, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv24)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 27);
  sf_mex_assign(&c3_txt17, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_c_emlrt_marshallOut(chartInstance, c3_cv25)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 29);
  sf_mex_assign(&c3_txt_as1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv26)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 30);
  sf_mex_assign(&c3_txt_as2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv27)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 31);
  sf_mex_assign(&c3_txt_as3, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv28)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 32);
  sf_mex_assign(&c3_txt_as4, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv29)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 34);
  sf_mex_assign(&c3_edt_as1, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv30)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 35);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                    (c3_edt_as1), 14, c3_d_emlrt_marshallOut(chartInstance,
    c3_cv31), 14, c3_e_emlrt_marshallOut(chartInstance, *chartInstance->c3_as1));
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 36);
  sf_mex_assign(&c3_edt_as2, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv32)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 37);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                    (c3_edt_as2), 14, c3_d_emlrt_marshallOut(chartInstance,
    c3_cv31), 14, c3_e_emlrt_marshallOut(chartInstance, *chartInstance->c3_as2));
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 38);
  sf_mex_assign(&c3_edt_as3, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv33)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 39);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                    (c3_edt_as3), 14, c3_d_emlrt_marshallOut(chartInstance,
    c3_cv31), 14, c3_e_emlrt_marshallOut(chartInstance, *chartInstance->c3_as3));
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 40);
  sf_mex_assign(&c3_edt_as4, sf_mex_call_debug(sfGlobalDebugInstanceStruct,
    "findobj", 1U, 2U, 14, c3_emlrt_marshallOut(chartInstance, c3_cv0), 14,
    c3_b_emlrt_marshallOut(chartInstance, c3_cv34)), false);
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 41);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                    (c3_edt_as4), 14, c3_d_emlrt_marshallOut(chartInstance,
    c3_cv31), 14, c3_e_emlrt_marshallOut(chartInstance, *chartInstance->c3_as4));
  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 43);
  if (CV_EML_IF(2, 1, 0, CV_RELATIONAL_EVAL(4U, 2U, 0, *chartInstance->c3_vr1,
        1.0, -1, 0U, *chartInstance->c3_vr1 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 44);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt1), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 46);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt1), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 49);
  if (CV_EML_IF(2, 1, 1, CV_RELATIONAL_EVAL(4U, 2U, 1, *chartInstance->c3_vr2,
        1.0, -1, 0U, *chartInstance->c3_vr2 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 50);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt2), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 51);
    if (!chartInstance->c3_dataWrittenToVector[15U]) {
      sf_read_before_write_error(chartInstance->S, 38U, 460U, 1467, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[14U]) {
      sf_read_before_write_error(chartInstance->S, 12U, 460U, 1471, 3);
    }

    c3_dv0[0] = *chartInstance->c3_vn2;
    c3_dv0[1] = *chartInstance->c3_dp2;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt2), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv0));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 53);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt2), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 54);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt2), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 57);
  if (CV_EML_IF(2, 1, 2, CV_RELATIONAL_EVAL(4U, 2U, 2, *chartInstance->c3_vr3,
        1.0, -1, 0U, *chartInstance->c3_vr3 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 58);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt3), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 59);
    if (!chartInstance->c3_dataWrittenToVector[10U]) {
      sf_read_before_write_error(chartInstance->S, 45U, 460U, 1614, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[11U]) {
      sf_read_before_write_error(chartInstance->S, 19U, 460U, 1618, 3);
    }

    c3_dv1[0] = *chartInstance->c3_vn3;
    c3_dv1[1] = *chartInstance->c3_dp3;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt3), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv1));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 61);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt3), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 62);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt3), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 65);
  if (!chartInstance->c3_dataWrittenToVector[4U]) {
    sf_read_before_write_error(chartInstance->S, 71U, 460U, 1698, 3);
  }

  if (CV_EML_IF(2, 1, 3, CV_RELATIONAL_EVAL(4U, 2U, 3, *chartInstance->c3_vr4,
        1.0, -1, 0U, *chartInstance->c3_vr4 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 66);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt4), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 67);
    if (!chartInstance->c3_dataWrittenToVector[46U]) {
      sf_read_before_write_error(chartInstance->S, 46U, 460U, 1761, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[45U]) {
      sf_read_before_write_error(chartInstance->S, 20U, 460U, 1765, 3);
    }

    c3_dv2[0] = *chartInstance->c3_vn4;
    c3_dv2[1] = *chartInstance->c3_dp4;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt4), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv2));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 69);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt4), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 70);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt4), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 73);
  if (!chartInstance->c3_dataWrittenToVector[3U]) {
    sf_read_before_write_error(chartInstance->S, 72U, 460U, 1845, 3);
  }

  if (CV_EML_IF(2, 1, 4, CV_RELATIONAL_EVAL(4U, 2U, 4, *chartInstance->c3_vr5,
        1.0, -1, 0U, *chartInstance->c3_vr5 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 74);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt5), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 75);
    if (!chartInstance->c3_dataWrittenToVector[49U]) {
      sf_read_before_write_error(chartInstance->S, 47U, 460U, 1908, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[48U]) {
      sf_read_before_write_error(chartInstance->S, 21U, 460U, 1912, 3);
    }

    c3_dv3[0] = *chartInstance->c3_vn5;
    c3_dv3[1] = *chartInstance->c3_dp5;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt5), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv3));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 77);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt5), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 78);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt5), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 81);
  if (!chartInstance->c3_dataWrittenToVector[1U]) {
    sf_read_before_write_error(chartInstance->S, 73U, 460U, 1992, 3);
  }

  if (CV_EML_IF(2, 1, 5, CV_RELATIONAL_EVAL(4U, 2U, 5, *chartInstance->c3_vr6,
        1.0, -1, 0U, *chartInstance->c3_vr6 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 82);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt6), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 83);
    if (!chartInstance->c3_dataWrittenToVector[52U]) {
      sf_read_before_write_error(chartInstance->S, 48U, 460U, 2055, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[51U]) {
      sf_read_before_write_error(chartInstance->S, 22U, 460U, 2059, 3);
    }

    c3_dv4[0] = *chartInstance->c3_vn6;
    c3_dv4[1] = *chartInstance->c3_dp6;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt6), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv4));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 85);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt6), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 86);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt6), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 89);
  if (!chartInstance->c3_dataWrittenToVector[0U]) {
    sf_read_before_write_error(chartInstance->S, 74U, 460U, 2142, 3);
  }

  if (CV_EML_IF(2, 1, 6, CV_RELATIONAL_EVAL(4U, 2U, 6, *chartInstance->c3_vr7,
        1.0, -1, 0U, *chartInstance->c3_vr7 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 90);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt7), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 91);
    if (!chartInstance->c3_dataWrittenToVector[19U]) {
      sf_read_before_write_error(chartInstance->S, 49U, 460U, 2205, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[63U]) {
      sf_read_before_write_error(chartInstance->S, 23U, 460U, 2209, 3);
    }

    c3_dv5[0] = *chartInstance->c3_vn7;
    c3_dv5[1] = *chartInstance->c3_dp7;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt7), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv5));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 93);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt7), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 94);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt7), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 97);
  if (!chartInstance->c3_dataWrittenToVector[2U]) {
    sf_read_before_write_error(chartInstance->S, 75U, 460U, 2295, 3);
  }

  if (CV_EML_IF(2, 1, 7, CV_RELATIONAL_EVAL(4U, 2U, 7, *chartInstance->c3_vr8,
        1.0, -1, 0U, *chartInstance->c3_vr8 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 98);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt8), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 99);
    if (!chartInstance->c3_dataWrittenToVector[60U]) {
      sf_read_before_write_error(chartInstance->S, 50U, 460U, 2358, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[58U]) {
      sf_read_before_write_error(chartInstance->S, 24U, 460U, 2362, 3);
    }

    c3_dv6[0] = *chartInstance->c3_vn8;
    c3_dv6[1] = *chartInstance->c3_dp8;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt8), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv6));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 101);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt8), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 102);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt8), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 105);
  if (!chartInstance->c3_dataWrittenToVector[5U]) {
    sf_read_before_write_error(chartInstance->S, 76U, 460U, 2450, 3);
  }

  if (CV_EML_IF(2, 1, 8, CV_RELATIONAL_EVAL(4U, 2U, 8, *chartInstance->c3_vr9,
        1.0, -1, 0U, *chartInstance->c3_vr9 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 106);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt9), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 107);
    if (!chartInstance->c3_dataWrittenToVector[59U]) {
      sf_read_before_write_error(chartInstance->S, 51U, 460U, 2513, 3);
    }

    if (!chartInstance->c3_dataWrittenToVector[57U]) {
      sf_read_before_write_error(chartInstance->S, 25U, 460U, 2517, 3);
    }

    c3_dv7[0] = *chartInstance->c3_vn9;
    c3_dv7[1] = *chartInstance->c3_dp9;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt9), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv7));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 109);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt9), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 110);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt9), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 113);
  if (CV_EML_IF(2, 1, 9, CV_RELATIONAL_EVAL(4U, 2U, 9, *chartInstance->c3_vr10,
        1.0, -1, 0U, *chartInstance->c3_vr10 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 114);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt10), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 115);
    if (!chartInstance->c3_dataWrittenToVector[22U]) {
      sf_read_before_write_error(chartInstance->S, 28U, 460U, 2669, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[21U]) {
      sf_read_before_write_error(chartInstance->S, 2U, 460U, 2674, 4);
    }

    c3_dv8[0] = *chartInstance->c3_vn10;
    c3_dv8[1] = *chartInstance->c3_dp10;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt10), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv8));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 117);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt10), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 118);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt10), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 120);
  if (!chartInstance->c3_dataWrittenToVector[6U]) {
    sf_read_before_write_error(chartInstance->S, 54U, 460U, 2762, 4);
  }

  if (CV_EML_IF(2, 1, 10, CV_RELATIONAL_EVAL(4U, 2U, 10, *chartInstance->c3_vr11,
        1.0, -1, 0U, *chartInstance->c3_vr11 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 121);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt11), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 122);
    if (!chartInstance->c3_dataWrittenToVector[25U]) {
      sf_read_before_write_error(chartInstance->S, 29U, 460U, 2828, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[24U]) {
      sf_read_before_write_error(chartInstance->S, 3U, 460U, 2833, 4);
    }

    c3_dv9[0] = *chartInstance->c3_vn11;
    c3_dv9[1] = *chartInstance->c3_dp11;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt11), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv9));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 124);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt11), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 125);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt11), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, MAX_int8_T);
  if (!chartInstance->c3_dataWrittenToVector[7U]) {
    sf_read_before_write_error(chartInstance->S, 55U, 460U, 2921, 4);
  }

  if (CV_EML_IF(2, 1, 11, CV_RELATIONAL_EVAL(4U, 2U, 11, *chartInstance->c3_vr12,
        1.0, -1, 0U, *chartInstance->c3_vr12 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 128);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt12), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 129);
    if (!chartInstance->c3_dataWrittenToVector[38U]) {
      sf_read_before_write_error(chartInstance->S, 30U, 460U, 2987, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[28U]) {
      sf_read_before_write_error(chartInstance->S, 4U, 460U, 2992, 4);
    }

    c3_dv10[0] = *chartInstance->c3_vn12;
    c3_dv10[1] = *chartInstance->c3_dp12;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt12), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv10));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 131);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt12), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 132);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt12), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 134);
  if (CV_EML_IF(2, 1, 12, CV_RELATIONAL_EVAL(4U, 2U, 12, *chartInstance->c3_vr13,
        1.0, -1, 0U, *chartInstance->c3_vr13 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 135);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt13), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 136);
    if (!chartInstance->c3_dataWrittenToVector[44U]) {
      sf_read_before_write_error(chartInstance->S, 31U, 460U, 3146, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[27U]) {
      sf_read_before_write_error(chartInstance->S, 5U, 460U, 3151, 4);
    }

    c3_dv11[0] = *chartInstance->c3_vn13;
    c3_dv11[1] = *chartInstance->c3_dp13;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt13), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv11));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 138);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt13), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 139);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt13), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 141);
  if (CV_EML_IF(2, 1, 13, CV_RELATIONAL_EVAL(4U, 2U, 13, *chartInstance->c3_vr14,
        1.0, -1, 0U, *chartInstance->c3_vr14 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 142);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt14), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 143);
    if (!chartInstance->c3_dataWrittenToVector[33U]) {
      sf_read_before_write_error(chartInstance->S, 32U, 460U, 3305, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[34U]) {
      sf_read_before_write_error(chartInstance->S, 6U, 460U, 3310, 4);
    }

    c3_dv12[0] = *chartInstance->c3_vn14;
    c3_dv12[1] = *chartInstance->c3_dp14;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt14), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv12));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 145);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt14), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 146);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt14), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 148);
  if (CV_EML_IF(2, 1, 14, CV_RELATIONAL_EVAL(4U, 2U, 14, *chartInstance->c3_vr15,
        1.0, -1, 0U, *chartInstance->c3_vr15 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 149);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt15), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 150);
    if (!chartInstance->c3_dataWrittenToVector[29U]) {
      sf_read_before_write_error(chartInstance->S, 33U, 460U, 3464, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[31U]) {
      sf_read_before_write_error(chartInstance->S, 7U, 460U, 3469, 4);
    }

    c3_dv13[0] = *chartInstance->c3_vn15;
    c3_dv13[1] = *chartInstance->c3_dp15;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt15), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv13));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 152);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt15), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 153);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt15), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 155);
  if (CV_EML_IF(2, 1, 15, CV_RELATIONAL_EVAL(4U, 2U, 15, *chartInstance->c3_vr16,
        1.0, -1, 0U, *chartInstance->c3_vr16 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 156);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt16), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 157);
    if (!chartInstance->c3_dataWrittenToVector[30U]) {
      sf_read_before_write_error(chartInstance->S, 34U, 460U, 3623, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[26U]) {
      sf_read_before_write_error(chartInstance->S, 8U, 460U, 3628, 4);
    }

    c3_dv14[0] = *chartInstance->c3_vn16;
    c3_dv14[1] = *chartInstance->c3_dp16;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt16), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv14));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 159);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt16), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 160);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt16), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 162);
  if (CV_EML_IF(2, 1, 16, CV_RELATIONAL_EVAL(4U, 2U, 16, *chartInstance->c3_vr17,
        1.0, -1, 0U, *chartInstance->c3_vr17 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 163);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt17), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 164);
    if (!chartInstance->c3_dataWrittenToVector[39U]) {
      sf_read_before_write_error(chartInstance->S, 35U, 460U, 3782, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[40U]) {
      sf_read_before_write_error(chartInstance->S, 9U, 460U, 3787, 4);
    }

    c3_dv15[0] = *chartInstance->c3_vn17;
    c3_dv15[1] = *chartInstance->c3_dp17;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt17), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv15));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 166);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt17), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 167);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt17), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 169);
  if (!chartInstance->c3_dataWrittenToVector[8U]) {
    sf_read_before_write_error(chartInstance->S, 61U, 460U, 3875, 4);
  }

  if (CV_EML_IF(2, 1, 17, CV_RELATIONAL_EVAL(4U, 2U, 17, *chartInstance->c3_vr18,
        1.0, -1, 0U, *chartInstance->c3_vr18 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 170);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt18), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 171);
    if (!chartInstance->c3_dataWrittenToVector[55U]) {
      sf_read_before_write_error(chartInstance->S, 36U, 460U, 3941, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[54U]) {
      sf_read_before_write_error(chartInstance->S, 10U, 460U, 3946, 4);
    }

    c3_dv16[0] = *chartInstance->c3_vn18;
    c3_dv16[1] = *chartInstance->c3_dp18;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt18), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv16));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 173);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt18), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 174);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt18), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 176);
  if (CV_EML_IF(2, 1, 18, CV_RELATIONAL_EVAL(4U, 2U, 18, *chartInstance->c3_vr19,
        1.0, -1, 0U, *chartInstance->c3_vr19 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 177);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt19), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 178);
    if (!chartInstance->c3_dataWrittenToVector[12U]) {
      sf_read_before_write_error(chartInstance->S, 37U, 460U, 4100, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[90U]) {
      sf_read_before_write_error(chartInstance->S, 11U, 460U, 4105, 4);
    }

    c3_dv17[0] = *chartInstance->c3_vn19;
    c3_dv17[1] = *chartInstance->c3_dp19;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt19), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv17));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 180);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt19), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 181);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt19), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 183);
  if (!chartInstance->c3_dataWrittenToVector[76U]) {
    sf_read_before_write_error(chartInstance->S, 64U, 460U, 4193, 4);
  }

  if (CV_EML_IF(2, 1, 19, CV_RELATIONAL_EVAL(4U, 2U, 19, *chartInstance->c3_vr20,
        1.0, -1, 0U, *chartInstance->c3_vr20 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 184);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt20), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 185);
    if (!chartInstance->c3_dataWrittenToVector[78U]) {
      sf_read_before_write_error(chartInstance->S, 39U, 460U, 4259, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[77U]) {
      sf_read_before_write_error(chartInstance->S, 13U, 460U, 4264, 4);
    }

    c3_dv18[0] = *chartInstance->c3_vn20;
    c3_dv18[1] = *chartInstance->c3_dp20;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt20), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv18));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 187);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt20), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 188);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt20), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 190);
  if (!chartInstance->c3_dataWrittenToVector[73U]) {
    sf_read_before_write_error(chartInstance->S, 65U, 460U, 4352, 4);
  }

  if (CV_EML_IF(2, 1, 20, CV_RELATIONAL_EVAL(4U, 2U, 20, *chartInstance->c3_vr21,
        1.0, -1, 0U, *chartInstance->c3_vr21 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 191);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt21), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 192);
    if (!chartInstance->c3_dataWrittenToVector[75U]) {
      sf_read_before_write_error(chartInstance->S, 40U, 460U, 4418, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[74U]) {
      sf_read_before_write_error(chartInstance->S, 14U, 460U, 4423, 4);
    }

    c3_dv19[0] = *chartInstance->c3_vn21;
    c3_dv19[1] = *chartInstance->c3_dp21;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt21), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv19));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 194);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt21), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 195);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt21), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 197);
  if (!chartInstance->c3_dataWrittenToVector[64U]) {
    sf_read_before_write_error(chartInstance->S, 66U, 460U, 4511, 4);
  }

  if (CV_EML_IF(2, 1, 21, CV_RELATIONAL_EVAL(4U, 2U, 21, *chartInstance->c3_vr22,
        1.0, -1, 0U, *chartInstance->c3_vr22 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 198);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt22), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 199);
    if (!chartInstance->c3_dataWrittenToVector[66U]) {
      sf_read_before_write_error(chartInstance->S, 41U, 460U, 4577, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[65U]) {
      sf_read_before_write_error(chartInstance->S, 15U, 460U, 4582, 4);
    }

    c3_dv20[0] = *chartInstance->c3_vn22;
    c3_dv20[1] = *chartInstance->c3_dp22;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt22), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv20));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 201);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt22), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 202);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt22), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 204);
  if (!chartInstance->c3_dataWrittenToVector[69U]) {
    sf_read_before_write_error(chartInstance->S, 67U, 460U, 4670, 4);
  }

  if (CV_EML_IF(2, 1, 22, CV_RELATIONAL_EVAL(4U, 2U, 22, *chartInstance->c3_vr23,
        1.0, -1, 0U, *chartInstance->c3_vr23 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 205);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt23), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 206);
    if (!chartInstance->c3_dataWrittenToVector[71U]) {
      sf_read_before_write_error(chartInstance->S, 42U, 460U, 4736, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[70U]) {
      sf_read_before_write_error(chartInstance->S, 16U, 460U, 4741, 4);
    }

    c3_dv21[0] = *chartInstance->c3_vn23;
    c3_dv21[1] = *chartInstance->c3_dp23;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt23), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv21));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 208);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt23), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 209);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt23), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 211);
  if (!chartInstance->c3_dataWrittenToVector[86U]) {
    sf_read_before_write_error(chartInstance->S, 68U, 460U, 4829, 4);
  }

  if (CV_EML_IF(2, 1, 23, CV_RELATIONAL_EVAL(4U, 2U, 23, *chartInstance->c3_vr24,
        1.0, -1, 0U, *chartInstance->c3_vr24 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 212);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt24), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 213);
    if (!chartInstance->c3_dataWrittenToVector[85U]) {
      sf_read_before_write_error(chartInstance->S, 43U, 460U, 4895, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[84U]) {
      sf_read_before_write_error(chartInstance->S, 17U, 460U, 4900, 4);
    }

    c3_dv22[0] = *chartInstance->c3_vn24;
    c3_dv22[1] = *chartInstance->c3_dp24;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt24), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv22));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 215);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt24), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 216);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt24), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 218);
  if (!chartInstance->c3_dataWrittenToVector[80U]) {
    sf_read_before_write_error(chartInstance->S, 69U, 460U, 4988, 4);
  }

  if (CV_EML_IF(2, 1, 24, CV_RELATIONAL_EVAL(4U, 2U, 24, *chartInstance->c3_vr25,
        1.0, -1, 0U, *chartInstance->c3_vr25 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 219);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt25), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv37));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 220);
    if (!chartInstance->c3_dataWrittenToVector[82U]) {
      sf_read_before_write_error(chartInstance->S, 44U, 460U, 5054, 4);
    }

    if (!chartInstance->c3_dataWrittenToVector[83U]) {
      sf_read_before_write_error(chartInstance->S, 18U, 460U, 5059, 4);
    }

    c3_dv23[0] = *chartInstance->c3_vn25;
    c3_dv23[1] = *chartInstance->c3_dp25;
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt25), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_h_emlrt_marshallOut(chartInstance, c3_dv23));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 222);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt25), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 223);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt25), 14, c3_d_emlrt_marshallOut(chartInstance,
      c3_cv31), 14, c3_i_emlrt_marshallOut(chartInstance));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 226);
  if (!chartInstance->c3_dataWrittenToVector[45U]) {
    sf_read_before_write_error(chartInstance->S, 20U, 460U, 5148, 3);
  }

  if (CV_EML_IF(2, 1, 25, CV_RELATIONAL_EVAL(4U, 2U, 25, *chartInstance->c3_dp4,
        1.0, -1, 0U, *chartInstance->c3_dp4 == 1.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 227);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as1), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_d_emlrt_marshallOut(chartInstance, c3_cv38));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 229);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as1), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 232);
  if (!chartInstance->c3_dataWrittenToVector[63U]) {
    sf_read_before_write_error(chartInstance->S, 23U, 460U, 5256, 3);
  }

  if (CV_EML_IF(2, 1, 26, CV_RELATIONAL_EVAL(4U, 2U, 26, *chartInstance->c3_dp7,
        2.0, -1, 0U, *chartInstance->c3_dp7 == 2.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 233);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as2), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_d_emlrt_marshallOut(chartInstance, c3_cv38));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 235);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as2), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 238);
  if (!chartInstance->c3_dataWrittenToVector[28U]) {
    sf_read_before_write_error(chartInstance->S, 4U, 460U, 5368, 4);
  }

  if (CV_EML_IF(2, 1, 27, CV_RELATIONAL_EVAL(4U, 2U, 27, *chartInstance->c3_dp12,
        3.0, -1, 0U, *chartInstance->c3_dp12 == 3.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 239);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as3), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_d_emlrt_marshallOut(chartInstance, c3_cv38));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 241);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as3), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 244);
  if (!chartInstance->c3_dataWrittenToVector[31U]) {
    sf_read_before_write_error(chartInstance->S, 7U, 460U, 5481, 4);
  }

  if (CV_EML_IF(2, 1, 28, CV_RELATIONAL_EVAL(4U, 2U, 28, *chartInstance->c3_dp15,
        4.0, -1, 0U, *chartInstance->c3_dp15 == 4.0))) {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 245);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as4), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_d_emlrt_marshallOut(chartInstance, c3_cv38));
  } else {
    _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, 247);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "set", 0U, 3U, 14, sf_mex_dup
                      (c3_txt_as4), 14, c3_f_emlrt_marshallOut(chartInstance,
      c3_cv35), 14, c3_g_emlrt_marshallOut(chartInstance, c3_cv36));
  }

  _SFD_EML_CALL(2U, *chartInstance->c3_sfEvent, -247);
  _SFD_SYMBOL_SCOPE_POP();
  sf_mex_destroy(&c3_txt1);
  sf_mex_destroy(&c3_txt19);
  sf_mex_destroy(&c3_txt2);
  sf_mex_destroy(&c3_txt3);
  sf_mex_destroy(&c3_txt24);
  sf_mex_destroy(&c3_txt20);
  sf_mex_destroy(&c3_txt4);
  sf_mex_destroy(&c3_txt5);
  sf_mex_destroy(&c3_txt18);
  sf_mex_destroy(&c3_txt6);
  sf_mex_destroy(&c3_txt7);
  sf_mex_destroy(&c3_txt8);
  sf_mex_destroy(&c3_txt9);
  sf_mex_destroy(&c3_txt21);
  sf_mex_destroy(&c3_txt22);
  sf_mex_destroy(&c3_txt10);
  sf_mex_destroy(&c3_txt11);
  sf_mex_destroy(&c3_txt12);
  sf_mex_destroy(&c3_txt13);
  sf_mex_destroy(&c3_txt14);
  sf_mex_destroy(&c3_txt15);
  sf_mex_destroy(&c3_txt25);
  sf_mex_destroy(&c3_txt23);
  sf_mex_destroy(&c3_txt16);
  sf_mex_destroy(&c3_txt17);
  sf_mex_destroy(&c3_txt_as1);
  sf_mex_destroy(&c3_txt_as2);
  sf_mex_destroy(&c3_txt_as3);
  sf_mex_destroy(&c3_txt_as4);
  sf_mex_destroy(&c3_edt_as1);
  sf_mex_destroy(&c3_edt_as2);
  sf_mex_destroy(&c3_edt_as3);
  sf_mex_destroy(&c3_edt_as4);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int8_T c3_d_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int8_T c3_y;
  int8_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 2, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_trig;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int8_T c3_y;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_b_trig = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_trig), &c3_thisId);
  sf_mex_destroy(&c3_b_trig);
  *(int8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_is_active_m1, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_active_m1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_m1);
  return c3_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_is_active_m1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)chartInstanceVoid;
  c3_b_is_active_m1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_active_m1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_m1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_h_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u)
{
  boolean_T c3_bv0[91];
  int32_T c3_i2;
  *chartInstance->c3_as1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "as1");
  *chartInstance->c3_as2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "as2");
  *chartInstance->c3_as3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "as3");
  *chartInstance->c3_as4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "as4");
  *chartInstance->c3_dag = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 4)), "dag");
  *chartInstance->c3_dp1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 5)), "dp1");
  *chartInstance->c3_dp10 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 6)), "dp10");
  *chartInstance->c3_dp11 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 7)), "dp11");
  *chartInstance->c3_dp12 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 8)), "dp12");
  *chartInstance->c3_dp13 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 9)), "dp13");
  *chartInstance->c3_dp14 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 10)), "dp14");
  *chartInstance->c3_dp15 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 11)), "dp15");
  *chartInstance->c3_dp16 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 12)), "dp16");
  *chartInstance->c3_dp17 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 13)), "dp17");
  *chartInstance->c3_dp18 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 14)), "dp18");
  *chartInstance->c3_dp19 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 15)), "dp19");
  *chartInstance->c3_dp2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 16)), "dp2");
  *chartInstance->c3_dp20 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 17)), "dp20");
  *chartInstance->c3_dp21 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 18)), "dp21");
  *chartInstance->c3_dp22 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 19)), "dp22");
  *chartInstance->c3_dp23 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 20)), "dp23");
  *chartInstance->c3_dp24 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 21)), "dp24");
  *chartInstance->c3_dp25 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 22)), "dp25");
  *chartInstance->c3_dp3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 23)), "dp3");
  *chartInstance->c3_dp4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 24)), "dp4");
  *chartInstance->c3_dp5 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 25)), "dp5");
  *chartInstance->c3_dp6 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 26)), "dp6");
  *chartInstance->c3_dp7 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 27)), "dp7");
  *chartInstance->c3_dp8 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 28)), "dp8");
  *chartInstance->c3_dp9 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 29)), "dp9");
  *chartInstance->c3_j1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 30)), "j1");
  *chartInstance->c3_sayac = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 31)), "sayac");
  *chartInstance->c3_vn10 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 32)), "vn10");
  *chartInstance->c3_vn11 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 33)), "vn11");
  *chartInstance->c3_vn12 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 34)), "vn12");
  *chartInstance->c3_vn13 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 35)), "vn13");
  *chartInstance->c3_vn14 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 36)), "vn14");
  *chartInstance->c3_vn15 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 37)), "vn15");
  *chartInstance->c3_vn16 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 38)), "vn16");
  *chartInstance->c3_vn17 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 39)), "vn17");
  *chartInstance->c3_vn18 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 40)), "vn18");
  *chartInstance->c3_vn19 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 41)), "vn19");
  *chartInstance->c3_vn2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 42)), "vn2");
  *chartInstance->c3_vn20 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 43)), "vn20");
  *chartInstance->c3_vn21 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 44)), "vn21");
  *chartInstance->c3_vn22 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 45)), "vn22");
  *chartInstance->c3_vn23 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 46)), "vn23");
  *chartInstance->c3_vn24 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 47)), "vn24");
  *chartInstance->c3_vn25 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 48)), "vn25");
  *chartInstance->c3_vn3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 49)), "vn3");
  *chartInstance->c3_vn4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 50)), "vn4");
  *chartInstance->c3_vn5 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 51)), "vn5");
  *chartInstance->c3_vn6 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 52)), "vn6");
  *chartInstance->c3_vn7 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 53)), "vn7");
  *chartInstance->c3_vn8 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 54)), "vn8");
  *chartInstance->c3_vn9 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 55)), "vn9");
  *chartInstance->c3_vr1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 56)), "vr1");
  *chartInstance->c3_vr10 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 57)), "vr10");
  *chartInstance->c3_vr11 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 58)), "vr11");
  *chartInstance->c3_vr12 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 59)), "vr12");
  *chartInstance->c3_vr13 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 60)), "vr13");
  *chartInstance->c3_vr14 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 61)), "vr14");
  *chartInstance->c3_vr15 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 62)), "vr15");
  *chartInstance->c3_vr16 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 63)), "vr16");
  *chartInstance->c3_vr17 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 64)), "vr17");
  *chartInstance->c3_vr18 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 65)), "vr18");
  *chartInstance->c3_vr19 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 66)), "vr19");
  *chartInstance->c3_vr2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 67)), "vr2");
  *chartInstance->c3_vr20 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 68)), "vr20");
  *chartInstance->c3_vr21 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 69)), "vr21");
  *chartInstance->c3_vr22 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 70)), "vr22");
  *chartInstance->c3_vr23 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 71)), "vr23");
  *chartInstance->c3_vr24 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 72)), "vr24");
  *chartInstance->c3_vr25 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 73)), "vr25");
  *chartInstance->c3_vr3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 74)), "vr3");
  *chartInstance->c3_vr4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 75)), "vr4");
  *chartInstance->c3_vr5 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 76)), "vr5");
  *chartInstance->c3_vr6 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 77)), "vr6");
  *chartInstance->c3_vr7 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 78)), "vr7");
  *chartInstance->c3_vr8 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 79)), "vr8");
  *chartInstance->c3_vr9 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 80)), "vr9");
  *chartInstance->c3_vs1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 81)), "vs1");
  *chartInstance->c3_vs10 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 82)), "vs10");
  *chartInstance->c3_vs11 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 83)), "vs11");
  *chartInstance->c3_vs12 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 84)), "vs12");
  *chartInstance->c3_vs13 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 85)), "vs13");
  *chartInstance->c3_vs14 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 86)), "vs14");
  *chartInstance->c3_vs15 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 87)), "vs15");
  *chartInstance->c3_vs16 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 88)), "vs16");
  *chartInstance->c3_vs17 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 89)), "vs17");
  *chartInstance->c3_vs18 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 90)), "vs18");
  *chartInstance->c3_vs19 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 91)), "vs19");
  *chartInstance->c3_vs2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 92)), "vs2");
  *chartInstance->c3_vs20 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 93)), "vs20");
  *chartInstance->c3_vs21 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 94)), "vs21");
  *chartInstance->c3_vs22 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 95)), "vs22");
  *chartInstance->c3_vs23 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 96)), "vs23");
  *chartInstance->c3_vs24 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 97)), "vs24");
  *chartInstance->c3_vs25 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 98)), "vs25");
  *chartInstance->c3_vs3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 99)), "vs3");
  *chartInstance->c3_vs4 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 100)), "vs4");
  *chartInstance->c3_vs5 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 101)), "vs5");
  *chartInstance->c3_vs6 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 102)), "vs6");
  *chartInstance->c3_vs7 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 103)), "vs7");
  *chartInstance->c3_vs8 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 104)), "vs8");
  *chartInstance->c3_vs9 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 105)), "vs9");
  *chartInstance->c3_is_active_c3_ver_601 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 106)), "is_active_c3_ver_601");
  *chartInstance->c3_is_active_m1 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 107)), "is_active_m1");
  *chartInstance->c3_is_active_r1 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 108)), "is_active_r1");
  *chartInstance->c3_is_active_r2 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 109)), "is_active_r2");
  *chartInstance->c3_is_active_r3 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 110)), "is_active_r3");
  *chartInstance->c3_is_active_r4 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 111)), "is_active_r4");
  *chartInstance->c3_is_active_r5 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 112)), "is_active_r5");
  *chartInstance->c3_is_active_r6 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 113)), "is_active_r6");
  *chartInstance->c3_is_active_r10 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 114)), "is_active_r10");
  *chartInstance->c3_is_active_r8 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 115)), "is_active_r8");
  *chartInstance->c3_is_active_r9 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 116)), "is_active_r9");
  *chartInstance->c3_is_active_r7 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 117)), "is_active_r7");
  *chartInstance->c3_is_active_r11 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 118)), "is_active_r11");
  *chartInstance->c3_is_active_r17 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 119)), "is_active_r17");
  *chartInstance->c3_is_active_r12 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 120)), "is_active_r12");
  *chartInstance->c3_is_active_r13 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 121)), "is_active_r13");
  *chartInstance->c3_is_active_r14 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 122)), "is_active_r14");
  *chartInstance->c3_is_active_r15 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 123)), "is_active_r15");
  *chartInstance->c3_is_active_r16 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 124)), "is_active_r16");
  *chartInstance->c3_is_active_r18 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 125)), "is_active_r18");
  *chartInstance->c3_is_active_r19 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 126)), "is_active_r19");
  *chartInstance->c3_is_active_r20 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 127)), "is_active_r20");
  *chartInstance->c3_is_active_r21 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 128)), "is_active_r21");
  *chartInstance->c3_is_active_r22 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 129)), "is_active_r22");
  *chartInstance->c3_is_active_r23 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 130)), "is_active_r23");
  *chartInstance->c3_is_active_rdn = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 131)), "is_active_rdn");
  *chartInstance->c3_is_active_r24 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 132)), "is_active_r24");
  *chartInstance->c3_is_active_r25 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 133)), "is_active_r25");
  *chartInstance->c3_is_active_tictoc = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 134)), "is_active_tictoc");
  *chartInstance->c3_is_active_dindan = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 135)), "is_active_dindan");
  *chartInstance->c3_is_active_is = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 136)), "is_active_is");
  *chartInstance->c3_is_c3_ver_601 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 137)), "is_c3_ver_601");
  *chartInstance->c3_is_r1 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 138)), "is_r1");
  *chartInstance->c3_is_r2 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 139)), "is_r2");
  *chartInstance->c3_is_r3 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 140)), "is_r3");
  *chartInstance->c3_is_r4 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 141)), "is_r4");
  *chartInstance->c3_is_r5 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 142)), "is_r5");
  *chartInstance->c3_is_r6 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 143)), "is_r6");
  *chartInstance->c3_is_r10 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 144)), "is_r10");
  *chartInstance->c3_is_r8 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 145)), "is_r8");
  *chartInstance->c3_is_r9 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 146)), "is_r9");
  *chartInstance->c3_is_r7 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 147)), "is_r7");
  *chartInstance->c3_is_r11 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 148)), "is_r11");
  *chartInstance->c3_is_r17 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 149)), "is_r17");
  *chartInstance->c3_is_r12 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 150)), "is_r12");
  *chartInstance->c3_is_r13 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 151)), "is_r13");
  *chartInstance->c3_is_r14 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 152)), "is_r14");
  *chartInstance->c3_is_r15 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 153)), "is_r15");
  *chartInstance->c3_is_r16 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 154)), "is_r16");
  *chartInstance->c3_is_r18 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 155)), "is_r18");
  *chartInstance->c3_is_r19 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 156)), "is_r19");
  *chartInstance->c3_is_r20 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 157)), "is_r20");
  *chartInstance->c3_is_r21 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 158)), "is_r21");
  *chartInstance->c3_is_r22 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 159)), "is_r22");
  *chartInstance->c3_is_r23 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 160)), "is_r23");
  *chartInstance->c3_is_r24 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 161)), "is_r24");
  *chartInstance->c3_is_r25 = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 162)), "is_r25");
  *chartInstance->c3_is_tictoc = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 163)), "is_tictoc");
  *chartInstance->c3_is_dindan = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 164)), "is_dindan");
  *chartInstance->c3_is_is = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 165)), "is_is");
  *chartInstance->c3_temporalCounter_i10 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 166)), "temporalCounter_i10");
  *chartInstance->c3_temporalCounter_i7 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 167)), "temporalCounter_i7");
  *chartInstance->c3_temporalCounter_i2 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 168)), "temporalCounter_i2");
  *chartInstance->c3_temporalCounter_i5 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 169)), "temporalCounter_i5");
  *chartInstance->c3_temporalCounter_i20 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 170)), "temporalCounter_i20");
  *chartInstance->c3_temporalCounter_i3 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 171)), "temporalCounter_i3");
  *chartInstance->c3_temporalCounter_i4 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 172)), "temporalCounter_i4");
  *chartInstance->c3_temporalCounter_i21 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 173)), "temporalCounter_i21");
  *chartInstance->c3_temporalCounter_i16 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 174)), "temporalCounter_i16");
  *chartInstance->c3_temporalCounter_i24 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 175)), "temporalCounter_i24");
  *chartInstance->c3_temporalCounter_i19 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 176)), "temporalCounter_i19");
  *chartInstance->c3_temporalCounter_i22 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 177)), "temporalCounter_i22");
  *chartInstance->c3_temporalCounter_i12 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 178)), "temporalCounter_i12");
  *chartInstance->c3_temporalCounter_i14 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 179)), "temporalCounter_i14");
  *chartInstance->c3_temporalCounter_i8 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 180)), "temporalCounter_i8");
  *chartInstance->c3_temporalCounter_i11 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 181)), "temporalCounter_i11");
  *chartInstance->c3_temporalCounter_i15 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 182)), "temporalCounter_i15");
  *chartInstance->c3_temporalCounter_i23 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 183)), "temporalCounter_i23");
  *chartInstance->c3_temporalCounter_i9 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 184)), "temporalCounter_i9");
  *chartInstance->c3_temporalCounter_i25 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 185)), "temporalCounter_i25");
  *chartInstance->c3_temporalCounter_i26 = c3_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 186)), "temporalCounter_i26");
  *chartInstance->c3_temporalCounter_i13 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 187)), "temporalCounter_i13");
  *chartInstance->c3_temporalCounter_i1 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 188)), "temporalCounter_i1");
  *chartInstance->c3_temporalCounter_i6 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 189)), "temporalCounter_i6");
  *chartInstance->c3_temporalCounter_i17 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 190)), "temporalCounter_i17");
  *chartInstance->c3_temporalCounter_i18 = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 191)), "temporalCounter_i18");
  *chartInstance->c3_previousTicks = c3_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 192)), "previousTicks");
  c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 193)),
                        "dataWrittenToVector", c3_bv0);
  for (c3_i2 = 0; c3_i2 < 91; c3_i2++) {
    chartInstance->c3_dataWrittenToVector[c3_i2] = c3_bv0[c3_i2];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 194)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
}

static uint32_T c3_i_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_temporalCounter_i10, const char_T *c3_identifier)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_temporalCounter_i10), &c3_thisId);
  sf_mex_destroy(&c3_b_temporalCounter_i10);
  return c3_y;
}

static uint32_T c3_j_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static uint16_T c3_k_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_temporalCounter_i26, const char_T *c3_identifier)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_temporalCounter_i26), &c3_thisId);
  sf_mex_destroy(&c3_b_temporalCounter_i26);
  return c3_y;
}

static uint16_T c3_l_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_m_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_b_dataWrittenToVector, const char_T *c3_identifier,
  boolean_T c3_y[91])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_n_emlrt_marshallIn(SFc3_ver_601InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T c3_y[91])
{
  boolean_T c3_bv1[91];
  int32_T c3_i3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 91);
  for (c3_i3 = 0; c3_i3 < 91; c3_i3++) {
    c3_y[c3_i3] = c3_bv1[c3_i3];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_o_emlrt_marshallIn(SFc3_ver_601InstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_p_emlrt_marshallIn(SFc3_ver_601InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc3_ver_601InstanceStruct
  *chartInstance, int32_T c3_ssid)
{
  (void)chartInstance;
  (void)c3_ssid;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_ver_601InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static uint32_T c3__u32_d_(SFc3_ver_601InstanceStruct *chartInstance, real_T
  c3_b, uint32_T c3_ssid_src_loc, int32_T c3_offset_src_loc, int32_T
  c3_length_src_loc)
{
  uint32_T c3_a;
  (void)chartInstance;
  c3_a = (uint32_T)c3_b;
  if ((c3_b < 0.0) || ((real_T)c3_a != muDoubleScalarFloor(c3_b))) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW, c3_ssid_src_loc, c3_offset_src_loc,
      c3_length_src_loc);
  }

  return c3_a;
}

static void init_dsm_address_info(SFc3_ver_601InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_ver_601InstanceStruct *chartInstance)
{
  chartInstance->c3_trig = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 9))[0U];
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c3_is_active_c3_ver_601 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_is_c3_ver_601 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_is_active_m1 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_is_r4 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 4);
  chartInstance->c3_is_active_r4 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_is_r5 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 6);
  chartInstance->c3_is_active_r5 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_is_r8 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 8);
  chartInstance->c3_is_active_r8 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_is_r9 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 10);
  chartInstance->c3_is_active_r9 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 11);
  chartInstance->c3_is_r6 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 12);
  chartInstance->c3_is_active_r6 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 13);
  chartInstance->c3_is_r7 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 14);
  chartInstance->c3_is_active_r7 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 15);
  chartInstance->c3_is_r3 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 16);
  chartInstance->c3_is_active_r3 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 17);
  chartInstance->c3_is_r20 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 18);
  chartInstance->c3_is_active_r20 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 19);
  chartInstance->c3_is_r24 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 20);
  chartInstance->c3_is_active_r24 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 21);
  chartInstance->c3_is_tictoc = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
    22);
  chartInstance->c3_is_active_tictoc = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 23);
  chartInstance->c3_is_r2 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 24);
  chartInstance->c3_is_active_r2 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 25);
  chartInstance->c3_is_r21 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 26);
  chartInstance->c3_is_active_r21 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 27);
  chartInstance->c3_is_r18 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 28);
  chartInstance->c3_is_active_r18 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 29);
  chartInstance->c3_is_r1 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 30);
  chartInstance->c3_is_active_r1 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 31);
  chartInstance->c3_is_r19 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 32);
  chartInstance->c3_is_active_r19 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 33);
  chartInstance->c3_is_r22 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 34);
  chartInstance->c3_is_active_r22 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 35);
  chartInstance->c3_is_r17 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 36);
  chartInstance->c3_is_active_r17 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 37);
  chartInstance->c3_is_r12 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 38);
  chartInstance->c3_is_active_r12 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 39);
  chartInstance->c3_is_r15 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 40);
  chartInstance->c3_is_active_r15 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 41);
  chartInstance->c3_is_r14 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 42);
  chartInstance->c3_is_active_r14 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 43);
  chartInstance->c3_is_r10 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 44);
  chartInstance->c3_is_active_r10 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 45);
  chartInstance->c3_is_r11 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 46);
  chartInstance->c3_is_active_r11 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 47);
  chartInstance->c3_is_r16 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 48);
  chartInstance->c3_is_active_r16 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 49);
  chartInstance->c3_is_r23 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 50);
  chartInstance->c3_is_active_r23 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 51);
  chartInstance->c3_is_r13 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 52);
  chartInstance->c3_is_active_r13 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 53);
  chartInstance->c3_is_r25 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 54);
  chartInstance->c3_is_active_r25 = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 55);
  chartInstance->c3_is_active_rdn = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 56);
  chartInstance->c3_is_is = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 57);
  chartInstance->c3_is_active_is = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 58);
  chartInstance->c3_is_dindan = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
    59);
  chartInstance->c3_is_active_dindan = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 60);
  chartInstance->c3_vr1 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 61);
  chartInstance->c3_vr2 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 62);
  chartInstance->c3_j1 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 63);
  chartInstance->c3_vr7 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 64);
  chartInstance->c3_vr6 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 65);
  chartInstance->c3_vr8 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 66);
  chartInstance->c3_vr5 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 67);
  chartInstance->c3_vr3 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 68);
  chartInstance->c3_vr4 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 69);
  chartInstance->c3_as1 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_vr9 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 70);
  chartInstance->c3_vr11 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 71);
  chartInstance->c3_vr12 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 72);
  chartInstance->c3_vr10 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 73);
  chartInstance->c3_as2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_vr17 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 74);
  chartInstance->c3_vr13 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 75);
  chartInstance->c3_as3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_vr14 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 76);
  chartInstance->c3_vr15 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 77);
  chartInstance->c3_vr16 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 78);
  chartInstance->c3_as4 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_d1 = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c3_vr18 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 79);
  chartInstance->c3_vr19 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 80);
  chartInstance->c3_vs3 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 81);
  chartInstance->c3_vn3 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 82);
  chartInstance->c3_dp3 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 83);
  chartInstance->c3_vn19 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 84);
  chartInstance->c3_vs19 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 85);
  chartInstance->c3_dp2 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 86);
  chartInstance->c3_vn2 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 87);
  chartInstance->c3_vs2 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 88);
  chartInstance->c3_dp1 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 89);
  chartInstance->c3_vs1 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 90);
  chartInstance->c3_vn7 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 91);
  chartInstance->c3_vs7 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 92);
  chartInstance->c3_dp10 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 93);
  chartInstance->c3_vn10 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 94);
  chartInstance->c3_vs10 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 95);
  chartInstance->c3_dp11 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 96);
  chartInstance->c3_vn11 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 97);
  chartInstance->c3_dp16 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 98);
  chartInstance->c3_dp13 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 99);
  chartInstance->c3_dp12 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 100);
  chartInstance->c3_vn15 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 101);
  chartInstance->c3_vn16 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 102);
  chartInstance->c3_dp15 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 103);
  chartInstance->c3_vs14 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 104);
  chartInstance->c3_vn14 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 105);
  chartInstance->c3_dp14 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 106);
  chartInstance->c3_vs17 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 107);
  chartInstance->c3_vs12 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 108);
  chartInstance->c3_vs13 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 109);
  chartInstance->c3_vn12 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 110);
  chartInstance->c3_vn17 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 111);
  chartInstance->c3_dp17 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 112);
  chartInstance->c3_vs11 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 113);
  chartInstance->c3_vs16 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 114);
  chartInstance->c3_vs15 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 115);
  chartInstance->c3_vn13 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 116);
  chartInstance->c3_dp4 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 117);
  chartInstance->c3_vn4 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 118);
  chartInstance->c3_vs4 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 119);
  chartInstance->c3_dp5 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 120);
  chartInstance->c3_vn5 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 121);
  chartInstance->c3_vs5 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 122);
  chartInstance->c3_dp6 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 123);
  chartInstance->c3_vn6 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 124);
  chartInstance->c3_vs6 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 125);
  chartInstance->c3_dp18 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 126);
  chartInstance->c3_vn18 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 127);
  chartInstance->c3_vs18 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 128);
  chartInstance->c3_dp9 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 129);
  chartInstance->c3_dp8 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 130);
  chartInstance->c3_vn9 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 131);
  chartInstance->c3_vn8 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 132);
  chartInstance->c3_vs9 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 133);
  chartInstance->c3_vs8 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 134);
  chartInstance->c3_dp7 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 135);
  chartInstance->c3_vr22 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 136);
  chartInstance->c3_dp22 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 137);
  chartInstance->c3_vn22 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 138);
  chartInstance->c3_vs22 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 139);
  chartInstance->c3_vs23 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 140);
  chartInstance->c3_vr23 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 141);
  chartInstance->c3_dp23 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 142);
  chartInstance->c3_vn23 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 143);
  chartInstance->c3_vs21 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 144);
  chartInstance->c3_vr21 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 145);
  chartInstance->c3_dp21 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 146);
  chartInstance->c3_vn21 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 147);
  chartInstance->c3_vr20 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 148);
  chartInstance->c3_dp20 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 149);
  chartInstance->c3_vn20 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 150);
  chartInstance->c3_vs20 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 151);
  chartInstance->c3_asan1 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_asan2 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_asan3 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_asan4 = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_random = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_d2 = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c3_vr25 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 152);
  chartInstance->c3_vs25 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 153);
  chartInstance->c3_vn25 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 154);
  chartInstance->c3_dp25 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 155);
  chartInstance->c3_dp24 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 156);
  chartInstance->c3_vn24 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 157);
  chartInstance->c3_vr24 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 158);
  chartInstance->c3_vs24 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 159);
  chartInstance->c3_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    7);
  chartInstance->c3_yuk = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_dag = (real_T *)ssGetDWork_wrapper(chartInstance->S, 160);
  chartInstance->c3_sayac = (real_T *)ssGetDWork_wrapper(chartInstance->S, 161);
  chartInstance->c3_dp19 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 162);
  chartInstance->c3_temporalCounter_i1 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 163);
  chartInstance->c3_temporalCounter_i2 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 164);
  chartInstance->c3_temporalCounter_i3 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 165);
  chartInstance->c3_temporalCounter_i4 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 166);
  chartInstance->c3_temporalCounter_i5 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 167);
  chartInstance->c3_temporalCounter_i6 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 168);
  chartInstance->c3_temporalCounter_i7 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 169);
  chartInstance->c3_temporalCounter_i8 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 170);
  chartInstance->c3_temporalCounter_i9 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 171);
  chartInstance->c3_temporalCounter_i10 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 172);
  chartInstance->c3_temporalCounter_i11 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 173);
  chartInstance->c3_temporalCounter_i12 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 174);
  chartInstance->c3_temporalCounter_i13 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 175);
  chartInstance->c3_temporalCounter_i14 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 176);
  chartInstance->c3_temporalCounter_i15 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 177);
  chartInstance->c3_temporalCounter_i16 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 178);
  chartInstance->c3_temporalCounter_i17 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 179);
  chartInstance->c3_temporalCounter_i18 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 180);
  chartInstance->c3_temporalCounter_i19 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 181);
  chartInstance->c3_temporalCounter_i20 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 182);
  chartInstance->c3_temporalCounter_i21 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 183);
  chartInstance->c3_temporalCounter_i22 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 184);
  chartInstance->c3_temporalCounter_i23 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 185);
  chartInstance->c3_temporalCounter_i24 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 186);
  chartInstance->c3_temporalCounter_i25 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 187);
  chartInstance->c3_temporalCounter_i26 = (uint16_T *)ssGetDWork_wrapper
    (chartInstance->S, 188);
  chartInstance->c3_presentTicks = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 189);
  chartInstance->c3_elapsedTicks = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 190);
  chartInstance->c3_previousTicks = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 191);
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c3_ver_601_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2481832068U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3693149244U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3166182858U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2417075557U);
}

mxArray* sf_c3_ver_601_get_post_codegen_info(void);
mxArray *sf_c3_ver_601_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dytnL4QkBPGq3QhYPUSG5D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,102,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,19,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,19,"type",mxType);
    }

    mxSetField(mxData,19,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,20,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,20,"type",mxType);
    }

    mxSetField(mxData,20,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,21,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,21,"type",mxType);
    }

    mxSetField(mxData,21,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,22,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,22,"type",mxType);
    }

    mxSetField(mxData,22,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,23,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,23,"type",mxType);
    }

    mxSetField(mxData,23,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,24,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,24,"type",mxType);
    }

    mxSetField(mxData,24,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,25,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,25,"type",mxType);
    }

    mxSetField(mxData,25,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,26,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,26,"type",mxType);
    }

    mxSetField(mxData,26,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,27,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,27,"type",mxType);
    }

    mxSetField(mxData,27,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,28,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,28,"type",mxType);
    }

    mxSetField(mxData,28,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,29,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,29,"type",mxType);
    }

    mxSetField(mxData,29,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,30,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,30,"type",mxType);
    }

    mxSetField(mxData,30,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,31,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,31,"type",mxType);
    }

    mxSetField(mxData,31,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,32,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,32,"type",mxType);
    }

    mxSetField(mxData,32,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,33,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,33,"type",mxType);
    }

    mxSetField(mxData,33,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,34,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,34,"type",mxType);
    }

    mxSetField(mxData,34,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,35,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,35,"type",mxType);
    }

    mxSetField(mxData,35,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,36,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,36,"type",mxType);
    }

    mxSetField(mxData,36,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,37,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,37,"type",mxType);
    }

    mxSetField(mxData,37,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,38,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,38,"type",mxType);
    }

    mxSetField(mxData,38,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,39,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,39,"type",mxType);
    }

    mxSetField(mxData,39,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,40,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,40,"type",mxType);
    }

    mxSetField(mxData,40,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,41,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,41,"type",mxType);
    }

    mxSetField(mxData,41,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,42,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,42,"type",mxType);
    }

    mxSetField(mxData,42,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,43,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,43,"type",mxType);
    }

    mxSetField(mxData,43,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,44,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,44,"type",mxType);
    }

    mxSetField(mxData,44,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,45,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,45,"type",mxType);
    }

    mxSetField(mxData,45,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,46,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,46,"type",mxType);
    }

    mxSetField(mxData,46,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,47,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,47,"type",mxType);
    }

    mxSetField(mxData,47,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,48,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,48,"type",mxType);
    }

    mxSetField(mxData,48,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,49,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,49,"type",mxType);
    }

    mxSetField(mxData,49,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,50,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,50,"type",mxType);
    }

    mxSetField(mxData,50,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,51,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,51,"type",mxType);
    }

    mxSetField(mxData,51,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,52,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,52,"type",mxType);
    }

    mxSetField(mxData,52,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,53,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,53,"type",mxType);
    }

    mxSetField(mxData,53,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,54,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,54,"type",mxType);
    }

    mxSetField(mxData,54,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,55,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,55,"type",mxType);
    }

    mxSetField(mxData,55,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,56,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,56,"type",mxType);
    }

    mxSetField(mxData,56,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,57,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,57,"type",mxType);
    }

    mxSetField(mxData,57,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,58,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,58,"type",mxType);
    }

    mxSetField(mxData,58,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,59,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,59,"type",mxType);
    }

    mxSetField(mxData,59,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,60,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,60,"type",mxType);
    }

    mxSetField(mxData,60,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,61,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,61,"type",mxType);
    }

    mxSetField(mxData,61,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,62,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,62,"type",mxType);
    }

    mxSetField(mxData,62,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,63,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,63,"type",mxType);
    }

    mxSetField(mxData,63,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,64,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,64,"type",mxType);
    }

    mxSetField(mxData,64,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,65,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,65,"type",mxType);
    }

    mxSetField(mxData,65,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,66,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,66,"type",mxType);
    }

    mxSetField(mxData,66,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,67,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,67,"type",mxType);
    }

    mxSetField(mxData,67,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,68,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,68,"type",mxType);
    }

    mxSetField(mxData,68,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,69,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,69,"type",mxType);
    }

    mxSetField(mxData,69,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,70,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,70,"type",mxType);
    }

    mxSetField(mxData,70,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,71,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,71,"type",mxType);
    }

    mxSetField(mxData,71,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,72,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,72,"type",mxType);
    }

    mxSetField(mxData,72,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,73,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,73,"type",mxType);
    }

    mxSetField(mxData,73,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,74,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,74,"type",mxType);
    }

    mxSetField(mxData,74,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,75,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,75,"type",mxType);
    }

    mxSetField(mxData,75,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,76,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,76,"type",mxType);
    }

    mxSetField(mxData,76,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,77,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,77,"type",mxType);
    }

    mxSetField(mxData,77,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,78,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,78,"type",mxType);
    }

    mxSetField(mxData,78,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,79,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,79,"type",mxType);
    }

    mxSetField(mxData,79,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,80,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,80,"type",mxType);
    }

    mxSetField(mxData,80,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,81,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,81,"type",mxType);
    }

    mxSetField(mxData,81,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,82,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,82,"type",mxType);
    }

    mxSetField(mxData,82,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,83,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,83,"type",mxType);
    }

    mxSetField(mxData,83,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,84,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,84,"type",mxType);
    }

    mxSetField(mxData,84,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,85,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,85,"type",mxType);
    }

    mxSetField(mxData,85,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,86,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,86,"type",mxType);
    }

    mxSetField(mxData,86,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,87,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,87,"type",mxType);
    }

    mxSetField(mxData,87,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,88,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,88,"type",mxType);
    }

    mxSetField(mxData,88,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,89,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,89,"type",mxType);
    }

    mxSetField(mxData,89,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,90,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,90,"type",mxType);
    }

    mxSetField(mxData,90,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,91,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,91,"type",mxType);
    }

    mxSetField(mxData,91,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,92,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,92,"type",mxType);
    }

    mxSetField(mxData,92,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,93,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,93,"type",mxType);
    }

    mxSetField(mxData,93,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,94,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,94,"type",mxType);
    }

    mxSetField(mxData,94,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,95,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,95,"type",mxType);
    }

    mxSetField(mxData,95,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,96,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,96,"type",mxType);
    }

    mxSetField(mxData,96,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,97,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,97,"type",mxType);
    }

    mxSetField(mxData,97,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,98,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,98,"type",mxType);
    }

    mxSetField(mxData,98,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,99,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,99,"type",mxType);
    }

    mxSetField(mxData,99,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,100,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,100,"type",mxType);
    }

    mxSetField(mxData,100,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,101,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,101,"type",mxType);
    }

    mxSetField(mxData,101,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_ver_601_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ver_601_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ver_601_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("ext_mode");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_ver_601_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_ver_601_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_ver_601(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[129],T\"as1\",},{M[1],M[134],T\"as2\",},{M[1],M[204],T\"as3\",},{M[1],M[208],T\"as4\",},{M[3],M[518],T\"dag\",},{M[3],M[256],T\"dp1\",},{M[3],M[261],T\"dp10\",},{M[3],M[264],T\"dp11\",},{M[3],M[268],T\"dp12\",},{M[3],M[267],T\"dp13\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[274],T\"dp14\",},{M[3],M[271],T\"dp15\",},{M[3],M[266],T\"dp16\",},{M[3],M[280],T\"dp17\",},{M[3],M[294],T\"dp18\",},{M[3],M[520],T\"dp19\",},{M[3],M[248],T\"dp2\",},{M[3],M[349],T\"dp20\",},{M[3],M[346],T\"dp21\",},{M[3],M[337],T\"dp22\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[342],T\"dp23\",},{M[3],M[421],T\"dp24\",},{M[3],M[420],T\"dp25\",},{M[3],M[244],T\"dp3\",},{M[3],M[285],T\"dp4\",},{M[3],M[288],T\"dp5\",},{M[3],M[291],T\"dp6\",},{M[3],M[303],T\"dp7\",},{M[3],M[298],T\"dp8\",},{M[3],M[297],T\"dp9\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[22],T\"j1\",},{M[3],M[519],T\"sayac\",},{M[3],M[262],T\"vn10\",},{M[3],M[265],T\"vn11\",},{M[3],M[278],T\"vn12\",},{M[3],M[284],T\"vn13\",},{M[3],M[273],T\"vn14\",},{M[3],M[269],T\"vn15\",},{M[3],M[270],T\"vn16\",},{M[3],M[279],T\"vn17\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[295],T\"vn18\",},{M[3],M[245],T\"vn19\",},{M[3],M[249],T\"vn2\",},{M[3],M[350],T\"vn20\",},{M[3],M[347],T\"vn21\",},{M[3],M[338],T\"vn22\",},{M[3],M[343],T\"vn23\",},{M[3],M[422],T\"vn24\",},{M[3],M[419],T\"vn25\",},{M[3],M[243],T\"vn3\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[286],T\"vn4\",},{M[3],M[289],T\"vn5\",},{M[3],M[292],T\"vn6\",},{M[3],M[259],T\"vn7\",},{M[3],M[300],T\"vn8\",},{M[3],M[299],T\"vn9\",},{M[3],M[8],T\"vr1\",},{M[3],M[133],T\"vr10\",},{M[3],M[131],T\"vr11\",},{M[3],M[132],T\"vr12\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[203],T\"vr13\",},{M[3],M[205],T\"vr14\",},{M[3],M[206],T\"vr15\",},{M[3],M[207],T\"vr16\",},{M[3],M[202],T\"vr17\",},{M[3],M[230],T\"vr18\",},{M[3],M[241],T\"vr19\",},{M[3],M[19],T\"vr2\",},{M[3],M[348],T\"vr20\",},{M[3],M[345],T\"vr21\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[336],T\"vr22\",},{M[3],M[341],T\"vr23\",},{M[3],M[423],T\"vr24\",},{M[3],M[417],T\"vr25\",},{M[3],M[88],T\"vr3\",},{M[3],M[89],T\"vr4\",},{M[3],M[87],T\"vr5\",},{M[3],M[85],T\"vr6\",},{M[3],M[84],T\"vr7\",},{M[3],M[86],T\"vr8\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[130],T\"vr9\",},{M[3],M[258],T\"vs1\",},{M[3],M[263],T\"vs10\",},{M[3],M[281],T\"vs11\",},{M[3],M[276],T\"vs12\",},{M[3],M[277],T\"vs13\",},{M[3],M[272],T\"vs14\",},{M[3],M[283],T\"vs15\",},{M[3],M[282],T\"vs16\",},{M[3],M[275],T\"vs17\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[296],T\"vs18\",},{M[3],M[246],T\"vs19\",},{M[3],M[250],T\"vs2\",},{M[3],M[351],T\"vs20\",},{M[3],M[344],T\"vs21\",},{M[3],M[339],T\"vs22\",},{M[3],M[340],T\"vs23\",},{M[3],M[424],T\"vs24\",},{M[3],M[418],T\"vs25\",},{M[3],M[242],T\"vs3\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[287],T\"vs4\",},{M[3],M[290],T\"vs5\",},{M[3],M[293],T\"vs6\",},{M[3],M[260],T\"vs7\",},{M[3],M[302],T\"vs8\",},{M[3],M[301],T\"vs9\",},{M[8],M[0],T\"is_active_c3_ver_601\",},{M[8],M[1],T\"is_active_m1\",},{M[8],M[2],T\"is_active_r1\",},{M[8],M[13],T\"is_active_r2\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[42],T\"is_active_r3\",},{M[8],M[50],T\"is_active_r4\",},{M[8],M[57],T\"is_active_r5\",},{M[8],M[64],T\"is_active_r6\",},{M[8],M[74],T\"is_active_r10\",},{M[8],M[81],T\"is_active_r8\",},{M[8],M[97],T\"is_active_r9\",},{M[8],M[105],T\"is_active_r7\",},{M[8],M[113],T\"is_active_r11\",},{M[8],M[121],T\"is_active_r17\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[160],T\"is_active_r12\",},{M[8],M[172],T\"is_active_r13\",},{M[8],M[179],T\"is_active_r14\",},{M[8],M[187],T\"is_active_r15\",},{M[8],M[200],T\"is_active_r16\",},{M[8],M[221],T\"is_active_r18\",},{M[8],M[237],T\"is_active_r19\",},{M[8],M[311],T\"is_active_r20\",},{M[8],M[316],T\"is_active_r21\",},{M[8],M[327],T\"is_active_r22\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[8],M[333],T\"is_active_r23\",},{M[8],M[352],T\"is_active_rdn\",},{M[8],M[389],T\"is_active_r24\",},{M[8],M[408],T\"is_active_r25\",},{M[8],M[453],T\"is_active_tictoc\",},{M[8],M[521],T\"is_active_dindan\",},{M[8],M[522],T\"is_active_is\",},{M[9],M[0],T\"is_c3_ver_601\",},{M[9],M[2],T\"is_r1\",},{M[9],M[13],T\"is_r2\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[42],T\"is_r3\",},{M[9],M[50],T\"is_r4\",},{M[9],M[57],T\"is_r5\",},{M[9],M[64],T\"is_r6\",},{M[9],M[74],T\"is_r10\",},{M[9],M[81],T\"is_r8\",},{M[9],M[97],T\"is_r9\",},{M[9],M[105],T\"is_r7\",},{M[9],M[113],T\"is_r11\",},{M[9],M[121],T\"is_r17\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[160],T\"is_r12\",},{M[9],M[172],T\"is_r13\",},{M[9],M[179],T\"is_r14\",},{M[9],M[187],T\"is_r15\",},{M[9],M[200],T\"is_r16\",},{M[9],M[221],T\"is_r18\",},{M[9],M[237],T\"is_r19\",},{M[9],M[311],T\"is_r20\",},{M[9],M[316],T\"is_r21\",},{M[9],M[327],T\"is_r22\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[9],M[333],T\"is_r23\",},{M[9],M[389],T\"is_r24\",},{M[9],M[408],T\"is_r25\",},{M[9],M[453],T\"is_tictoc\",},{M[9],M[521],T\"is_dindan\",},{M[9],M[522],T\"is_is\",},{M[11],M[0],T\"temporalCounter_i10\",S'et','os','ct'{{T\"at\",M[14],M[1]}}},{M[11],M[0],T\"temporalCounter_i7\",S'et','os','ct'{{T\"at\",M[41],M[1]}}},{M[11],M[0],T\"temporalCounter_i2\",S'et','os','ct'{{T\"at\",M[58],M[1]}}},{M[11],M[0],T\"temporalCounter_i5\",S'et','os','ct'{{T\"at\",M[65],M[1]}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[11],M[0],T\"temporalCounter_i20\",S'et','os','ct'{{T\"at\",M[73],M[1]}}},{M[11],M[0],T\"temporalCounter_i3\",S'et','os','ct'{{T\"at\",M[82],M[1]}}},{M[11],M[0],T\"temporalCounter_i4\",S'et','os','ct'{{T\"at\",M[96],M[1]}}},{M[11],M[0],T\"temporalCounter_i21\",S'et','os','ct'{{T\"at\",M[111],M[1]}}},{M[11],M[0],T\"temporalCounter_i16\",S'et','os','ct'{{T\"at\",M[120],M[1]}}},{M[11],M[0],T\"temporalCounter_i24\",S'et','os','ct'{{T\"at\",M[170],M[1]}}},{M[11],M[0],T\"temporalCounter_i19\",S'et','os','ct'{{T\"at\",M[180],M[1]}}},{M[11],M[0],T\"temporalCounter_i22\",S'et','os','ct'{{T\"at\",M[198],M[1]}}},{M[11],M[0],T\"temporalCounter_i12\",S'et','os','ct'{{T\"at\",M[223],M[1]}}},{M[11],M[0],T\"temporalCounter_i14\",S'et','os','ct'{{T\"at\",M[235],M[1]}}}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[11],M[0],T\"temporalCounter_i8\",S'et','os','ct'{{T\"at\",M[307],M[1]}}},{M[11],M[0],T\"temporalCounter_i11\",S'et','os','ct'{{T\"at\",M[318],M[1]}}},{M[11],M[0],T\"temporalCounter_i15\",S'et','os','ct'{{T\"at\",M[326],M[1]}}},{M[11],M[0],T\"temporalCounter_i23\",S'et','os','ct'{{T\"at\",M[331],M[1]}}},{M[11],M[0],T\"temporalCounter_i9\",S'et','os','ct'{{T\"at\",M[390],M[1]}}},{M[11],M[0],T\"temporalCounter_i25\",S'et','os','ct'{{T\"at\",M[405],M[1]}}},{M[11],M[0],T\"temporalCounter_i26\",S'et','os','ct'{{T\"at\",M[512],M[1]}}},{M[11],M[0],T\"temporalCounter_i13\",S'et','os','ct'{{T\"at\",M1x2[3 4],M[1]}}},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[49 122],M[1]}}},{M[11],M[0],T\"temporalCounter_i6\",S'et','os','ct'{{T\"at\",M1x2[104 126],M[1]}}}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[11],M[0],T\"temporalCounter_i17\",S'et','os','ct'{{T\"at\",M1x2[157 165],M[1]}}},{M[11],M[0],T\"temporalCounter_i18\",S'et','os','ct'{{T\"at\",M1x2[191 193],M[1]}}},{M[13],M[0],T\"previousTicks\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 194, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ver_601_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_ver_601InstanceStruct *) chartInstance,
    msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ver_601InstanceStruct *chartInstance = (SFc3_ver_601InstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ver_601MachineNumber_,
           3,
           125,
           129,
           0,
           115,
           1,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ver_601MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ver_601MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ver_601MachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,0,0,0,"dag");
          _SFD_SET_DATA_PROPS(1,0,0,0,"dp1");
          _SFD_SET_DATA_PROPS(2,0,0,0,"dp10");
          _SFD_SET_DATA_PROPS(3,0,0,0,"dp11");
          _SFD_SET_DATA_PROPS(4,0,0,0,"dp12");
          _SFD_SET_DATA_PROPS(5,0,0,0,"dp13");
          _SFD_SET_DATA_PROPS(6,0,0,0,"dp14");
          _SFD_SET_DATA_PROPS(7,0,0,0,"dp15");
          _SFD_SET_DATA_PROPS(8,0,0,0,"dp16");
          _SFD_SET_DATA_PROPS(9,0,0,0,"dp17");
          _SFD_SET_DATA_PROPS(10,0,0,0,"dp18");
          _SFD_SET_DATA_PROPS(11,0,0,0,"dp19");
          _SFD_SET_DATA_PROPS(12,0,0,0,"dp2");
          _SFD_SET_DATA_PROPS(13,0,0,0,"dp20");
          _SFD_SET_DATA_PROPS(14,0,0,0,"dp21");
          _SFD_SET_DATA_PROPS(15,0,0,0,"dp22");
          _SFD_SET_DATA_PROPS(16,0,0,0,"dp23");
          _SFD_SET_DATA_PROPS(17,0,0,0,"dp24");
          _SFD_SET_DATA_PROPS(18,0,0,0,"dp25");
          _SFD_SET_DATA_PROPS(19,0,0,0,"dp3");
          _SFD_SET_DATA_PROPS(20,0,0,0,"dp4");
          _SFD_SET_DATA_PROPS(21,0,0,0,"dp5");
          _SFD_SET_DATA_PROPS(22,0,0,0,"dp6");
          _SFD_SET_DATA_PROPS(23,0,0,0,"dp7");
          _SFD_SET_DATA_PROPS(24,0,0,0,"dp8");
          _SFD_SET_DATA_PROPS(25,0,0,0,"dp9");
          _SFD_SET_DATA_PROPS(26,0,0,0,"j1");
          _SFD_SET_DATA_PROPS(27,0,0,0,"sayac");
          _SFD_SET_DATA_PROPS(28,0,0,0,"vn10");
          _SFD_SET_DATA_PROPS(29,0,0,0,"vn11");
          _SFD_SET_DATA_PROPS(30,0,0,0,"vn12");
          _SFD_SET_DATA_PROPS(31,0,0,0,"vn13");
          _SFD_SET_DATA_PROPS(32,0,0,0,"vn14");
          _SFD_SET_DATA_PROPS(33,0,0,0,"vn15");
          _SFD_SET_DATA_PROPS(34,0,0,0,"vn16");
          _SFD_SET_DATA_PROPS(35,0,0,0,"vn17");
          _SFD_SET_DATA_PROPS(36,0,0,0,"vn18");
          _SFD_SET_DATA_PROPS(37,0,0,0,"vn19");
          _SFD_SET_DATA_PROPS(38,0,0,0,"vn2");
          _SFD_SET_DATA_PROPS(39,0,0,0,"vn20");
          _SFD_SET_DATA_PROPS(40,0,0,0,"vn21");
          _SFD_SET_DATA_PROPS(41,0,0,0,"vn22");
          _SFD_SET_DATA_PROPS(42,0,0,0,"vn23");
          _SFD_SET_DATA_PROPS(43,0,0,0,"vn24");
          _SFD_SET_DATA_PROPS(44,0,0,0,"vn25");
          _SFD_SET_DATA_PROPS(45,0,0,0,"vn3");
          _SFD_SET_DATA_PROPS(46,0,0,0,"vn4");
          _SFD_SET_DATA_PROPS(47,0,0,0,"vn5");
          _SFD_SET_DATA_PROPS(48,0,0,0,"vn6");
          _SFD_SET_DATA_PROPS(49,0,0,0,"vn7");
          _SFD_SET_DATA_PROPS(50,0,0,0,"vn8");
          _SFD_SET_DATA_PROPS(51,0,0,0,"vn9");
          _SFD_SET_DATA_PROPS(52,0,0,0,"vr1");
          _SFD_SET_DATA_PROPS(53,0,0,0,"vr10");
          _SFD_SET_DATA_PROPS(54,0,0,0,"vr11");
          _SFD_SET_DATA_PROPS(55,0,0,0,"vr12");
          _SFD_SET_DATA_PROPS(56,0,0,0,"vr13");
          _SFD_SET_DATA_PROPS(57,0,0,0,"vr14");
          _SFD_SET_DATA_PROPS(58,0,0,0,"vr15");
          _SFD_SET_DATA_PROPS(59,0,0,0,"vr16");
          _SFD_SET_DATA_PROPS(60,0,0,0,"vr17");
          _SFD_SET_DATA_PROPS(61,0,0,0,"vr18");
          _SFD_SET_DATA_PROPS(62,0,0,0,"vr19");
          _SFD_SET_DATA_PROPS(63,0,0,0,"vr2");
          _SFD_SET_DATA_PROPS(64,0,0,0,"vr20");
          _SFD_SET_DATA_PROPS(65,0,0,0,"vr21");
          _SFD_SET_DATA_PROPS(66,0,0,0,"vr22");
          _SFD_SET_DATA_PROPS(67,0,0,0,"vr23");
          _SFD_SET_DATA_PROPS(68,0,0,0,"vr24");
          _SFD_SET_DATA_PROPS(69,0,0,0,"vr25");
          _SFD_SET_DATA_PROPS(70,0,0,0,"vr3");
          _SFD_SET_DATA_PROPS(71,0,0,0,"vr4");
          _SFD_SET_DATA_PROPS(72,0,0,0,"vr5");
          _SFD_SET_DATA_PROPS(73,0,0,0,"vr6");
          _SFD_SET_DATA_PROPS(74,0,0,0,"vr7");
          _SFD_SET_DATA_PROPS(75,0,0,0,"vr8");
          _SFD_SET_DATA_PROPS(76,0,0,0,"vr9");
          _SFD_SET_DATA_PROPS(77,0,0,0,"vs1");
          _SFD_SET_DATA_PROPS(78,0,0,0,"vs10");
          _SFD_SET_DATA_PROPS(79,0,0,0,"vs11");
          _SFD_SET_DATA_PROPS(80,0,0,0,"vs12");
          _SFD_SET_DATA_PROPS(81,0,0,0,"vs13");
          _SFD_SET_DATA_PROPS(82,0,0,0,"vs14");
          _SFD_SET_DATA_PROPS(83,0,0,0,"vs15");
          _SFD_SET_DATA_PROPS(84,0,0,0,"vs16");
          _SFD_SET_DATA_PROPS(85,0,0,0,"vs17");
          _SFD_SET_DATA_PROPS(86,0,0,0,"vs18");
          _SFD_SET_DATA_PROPS(87,0,0,0,"vs19");
          _SFD_SET_DATA_PROPS(88,0,0,0,"vs2");
          _SFD_SET_DATA_PROPS(89,0,0,0,"vs20");
          _SFD_SET_DATA_PROPS(90,0,0,0,"vs21");
          _SFD_SET_DATA_PROPS(91,0,0,0,"vs22");
          _SFD_SET_DATA_PROPS(92,0,0,0,"vs23");
          _SFD_SET_DATA_PROPS(93,0,0,0,"vs24");
          _SFD_SET_DATA_PROPS(94,0,0,0,"vs25");
          _SFD_SET_DATA_PROPS(95,0,0,0,"vs3");
          _SFD_SET_DATA_PROPS(96,0,0,0,"vs4");
          _SFD_SET_DATA_PROPS(97,0,0,0,"vs5");
          _SFD_SET_DATA_PROPS(98,0,0,0,"vs6");
          _SFD_SET_DATA_PROPS(99,0,0,0,"vs7");
          _SFD_SET_DATA_PROPS(100,0,0,0,"vs8");
          _SFD_SET_DATA_PROPS(101,0,0,0,"vs9");
          _SFD_SET_DATA_PROPS(102,1,1,0,"d1");
          _SFD_SET_DATA_PROPS(103,1,1,0,"asan1");
          _SFD_SET_DATA_PROPS(104,1,1,0,"asan2");
          _SFD_SET_DATA_PROPS(105,1,1,0,"asan3");
          _SFD_SET_DATA_PROPS(106,1,1,0,"asan4");
          _SFD_SET_DATA_PROPS(107,1,1,0,"random");
          _SFD_SET_DATA_PROPS(108,1,1,0,"d2");
          _SFD_SET_DATA_PROPS(109,1,1,0,"s");
          _SFD_SET_DATA_PROPS(110,1,1,0,"yuk");
          _SFD_SET_DATA_PROPS(111,2,0,1,"as1");
          _SFD_SET_DATA_PROPS(112,2,0,1,"as2");
          _SFD_SET_DATA_PROPS(113,2,0,1,"as3");
          _SFD_SET_DATA_PROPS(114,2,0,1,"as4");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,1,0);
          _SFD_STATE_INFO(1,1,1);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,1);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,1);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,1);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,1);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(23,0,0);
          _SFD_STATE_INFO(24,0,1);
          _SFD_STATE_INFO(25,0,0);
          _SFD_STATE_INFO(26,0,0);
          _SFD_STATE_INFO(27,0,0);
          _SFD_STATE_INFO(28,0,1);
          _SFD_STATE_INFO(29,0,0);
          _SFD_STATE_INFO(30,0,0);
          _SFD_STATE_INFO(31,0,0);
          _SFD_STATE_INFO(32,0,0);
          _SFD_STATE_INFO(33,0,1);
          _SFD_STATE_INFO(34,0,0);
          _SFD_STATE_INFO(35,0,0);
          _SFD_STATE_INFO(36,0,0);
          _SFD_STATE_INFO(37,0,1);
          _SFD_STATE_INFO(38,0,0);
          _SFD_STATE_INFO(39,0,0);
          _SFD_STATE_INFO(40,0,0);
          _SFD_STATE_INFO(41,0,1);
          _SFD_STATE_INFO(42,0,0);
          _SFD_STATE_INFO(43,0,0);
          _SFD_STATE_INFO(44,0,0);
          _SFD_STATE_INFO(45,0,1);
          _SFD_STATE_INFO(46,0,0);
          _SFD_STATE_INFO(47,0,0);
          _SFD_STATE_INFO(48,0,0);
          _SFD_STATE_INFO(49,0,1);
          _SFD_STATE_INFO(50,0,0);
          _SFD_STATE_INFO(51,0,0);
          _SFD_STATE_INFO(52,0,0);
          _SFD_STATE_INFO(53,0,1);
          _SFD_STATE_INFO(54,0,0);
          _SFD_STATE_INFO(55,0,0);
          _SFD_STATE_INFO(56,0,0);
          _SFD_STATE_INFO(57,0,1);
          _SFD_STATE_INFO(58,0,0);
          _SFD_STATE_INFO(59,0,0);
          _SFD_STATE_INFO(60,0,0);
          _SFD_STATE_INFO(61,0,1);
          _SFD_STATE_INFO(62,0,0);
          _SFD_STATE_INFO(63,0,0);
          _SFD_STATE_INFO(64,0,0);
          _SFD_STATE_INFO(65,0,1);
          _SFD_STATE_INFO(66,0,0);
          _SFD_STATE_INFO(67,0,0);
          _SFD_STATE_INFO(68,0,0);
          _SFD_STATE_INFO(69,0,1);
          _SFD_STATE_INFO(70,0,0);
          _SFD_STATE_INFO(71,0,0);
          _SFD_STATE_INFO(72,0,0);
          _SFD_STATE_INFO(73,0,1);
          _SFD_STATE_INFO(74,0,0);
          _SFD_STATE_INFO(75,0,0);
          _SFD_STATE_INFO(76,0,0);
          _SFD_STATE_INFO(77,0,1);
          _SFD_STATE_INFO(78,0,0);
          _SFD_STATE_INFO(79,0,0);
          _SFD_STATE_INFO(80,0,0);
          _SFD_STATE_INFO(81,0,1);
          _SFD_STATE_INFO(82,0,0);
          _SFD_STATE_INFO(83,0,0);
          _SFD_STATE_INFO(84,0,0);
          _SFD_STATE_INFO(85,0,0);
          _SFD_STATE_INFO(86,0,1);
          _SFD_STATE_INFO(87,0,0);
          _SFD_STATE_INFO(88,0,0);
          _SFD_STATE_INFO(89,0,0);
          _SFD_STATE_INFO(90,0,0);
          _SFD_STATE_INFO(91,0,1);
          _SFD_STATE_INFO(92,0,0);
          _SFD_STATE_INFO(93,0,0);
          _SFD_STATE_INFO(94,0,0);
          _SFD_STATE_INFO(95,0,1);
          _SFD_STATE_INFO(96,0,0);
          _SFD_STATE_INFO(97,0,0);
          _SFD_STATE_INFO(98,0,0);
          _SFD_STATE_INFO(99,0,0);
          _SFD_STATE_INFO(100,0,1);
          _SFD_STATE_INFO(101,0,0);
          _SFD_STATE_INFO(102,0,0);
          _SFD_STATE_INFO(103,0,0);
          _SFD_STATE_INFO(104,0,1);
          _SFD_STATE_INFO(105,0,0);
          _SFD_STATE_INFO(106,0,0);
          _SFD_STATE_INFO(107,0,0);
          _SFD_STATE_INFO(108,0,1);
          _SFD_STATE_INFO(109,0,0);
          _SFD_STATE_INFO(110,0,0);
          _SFD_STATE_INFO(111,1,1);
          _SFD_STATE_INFO(112,0,1);
          _SFD_STATE_INFO(113,0,0);
          _SFD_STATE_INFO(114,0,0);
          _SFD_STATE_INFO(115,0,1);
          _SFD_STATE_INFO(116,0,0);
          _SFD_STATE_INFO(117,0,0);
          _SFD_STATE_INFO(118,0,0);
          _SFD_STATE_INFO(119,0,0);
          _SFD_STATE_INFO(120,0,0);
          _SFD_STATE_INFO(121,0,0);
          _SFD_STATE_INFO(122,0,0);
          _SFD_STATE_INFO(123,0,0);
          _SFD_STATE_INFO(124,0,0);
          _SFD_STATE_INFO(2,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,111);
          _SFD_ST_SUBSTATE_COUNT(1,26);
          _SFD_ST_SUBSTATE_INDEX(1,0,3);
          _SFD_ST_SUBSTATE_INDEX(1,1,49);
          _SFD_ST_SUBSTATE_INDEX(1,2,77);
          _SFD_ST_SUBSTATE_INDEX(1,3,81);
          _SFD_ST_SUBSTATE_INDEX(1,4,86);
          _SFD_ST_SUBSTATE_INDEX(1,5,91);
          _SFD_ST_SUBSTATE_INDEX(1,6,95);
          _SFD_ST_SUBSTATE_INDEX(1,7,100);
          _SFD_ST_SUBSTATE_INDEX(1,8,104);
          _SFD_ST_SUBSTATE_INDEX(1,9,7);
          _SFD_ST_SUBSTATE_INDEX(1,10,11);
          _SFD_ST_SUBSTATE_INDEX(1,11,15);
          _SFD_ST_SUBSTATE_INDEX(1,12,20);
          _SFD_ST_SUBSTATE_INDEX(1,13,24);
          _SFD_ST_SUBSTATE_INDEX(1,14,37);
          _SFD_ST_SUBSTATE_INDEX(1,15,41);
          _SFD_ST_SUBSTATE_INDEX(1,16,45);
          _SFD_ST_SUBSTATE_INDEX(1,17,53);
          _SFD_ST_SUBSTATE_INDEX(1,18,57);
          _SFD_ST_SUBSTATE_INDEX(1,19,61);
          _SFD_ST_SUBSTATE_INDEX(1,20,69);
          _SFD_ST_SUBSTATE_INDEX(1,21,28);
          _SFD_ST_SUBSTATE_INDEX(1,22,33);
          _SFD_ST_SUBSTATE_INDEX(1,23,65);
          _SFD_ST_SUBSTATE_INDEX(1,24,73);
          _SFD_ST_SUBSTATE_INDEX(1,25,108);
          _SFD_ST_SUBSTATE_COUNT(3,3);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_INDEX(3,2,6);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(49,3);
          _SFD_ST_SUBSTATE_INDEX(49,0,50);
          _SFD_ST_SUBSTATE_INDEX(49,1,51);
          _SFD_ST_SUBSTATE_INDEX(49,2,52);
          _SFD_ST_SUBSTATE_COUNT(50,0);
          _SFD_ST_SUBSTATE_COUNT(51,0);
          _SFD_ST_SUBSTATE_COUNT(52,0);
          _SFD_ST_SUBSTATE_COUNT(77,3);
          _SFD_ST_SUBSTATE_INDEX(77,0,78);
          _SFD_ST_SUBSTATE_INDEX(77,1,79);
          _SFD_ST_SUBSTATE_INDEX(77,2,80);
          _SFD_ST_SUBSTATE_COUNT(78,0);
          _SFD_ST_SUBSTATE_COUNT(79,0);
          _SFD_ST_SUBSTATE_COUNT(80,0);
          _SFD_ST_SUBSTATE_COUNT(81,4);
          _SFD_ST_SUBSTATE_INDEX(81,0,82);
          _SFD_ST_SUBSTATE_INDEX(81,1,83);
          _SFD_ST_SUBSTATE_INDEX(81,2,84);
          _SFD_ST_SUBSTATE_INDEX(81,3,85);
          _SFD_ST_SUBSTATE_COUNT(82,0);
          _SFD_ST_SUBSTATE_COUNT(83,0);
          _SFD_ST_SUBSTATE_COUNT(84,0);
          _SFD_ST_SUBSTATE_COUNT(85,0);
          _SFD_ST_SUBSTATE_COUNT(86,4);
          _SFD_ST_SUBSTATE_INDEX(86,0,87);
          _SFD_ST_SUBSTATE_INDEX(86,1,88);
          _SFD_ST_SUBSTATE_INDEX(86,2,89);
          _SFD_ST_SUBSTATE_INDEX(86,3,90);
          _SFD_ST_SUBSTATE_COUNT(87,0);
          _SFD_ST_SUBSTATE_COUNT(88,0);
          _SFD_ST_SUBSTATE_COUNT(89,0);
          _SFD_ST_SUBSTATE_COUNT(90,0);
          _SFD_ST_SUBSTATE_COUNT(91,3);
          _SFD_ST_SUBSTATE_INDEX(91,0,92);
          _SFD_ST_SUBSTATE_INDEX(91,1,93);
          _SFD_ST_SUBSTATE_INDEX(91,2,94);
          _SFD_ST_SUBSTATE_COUNT(92,0);
          _SFD_ST_SUBSTATE_COUNT(93,0);
          _SFD_ST_SUBSTATE_COUNT(94,0);
          _SFD_ST_SUBSTATE_COUNT(95,4);
          _SFD_ST_SUBSTATE_INDEX(95,0,96);
          _SFD_ST_SUBSTATE_INDEX(95,1,97);
          _SFD_ST_SUBSTATE_INDEX(95,2,98);
          _SFD_ST_SUBSTATE_INDEX(95,3,99);
          _SFD_ST_SUBSTATE_COUNT(96,0);
          _SFD_ST_SUBSTATE_COUNT(97,0);
          _SFD_ST_SUBSTATE_COUNT(98,0);
          _SFD_ST_SUBSTATE_COUNT(99,0);
          _SFD_ST_SUBSTATE_COUNT(100,3);
          _SFD_ST_SUBSTATE_INDEX(100,0,101);
          _SFD_ST_SUBSTATE_INDEX(100,1,102);
          _SFD_ST_SUBSTATE_INDEX(100,2,103);
          _SFD_ST_SUBSTATE_COUNT(101,0);
          _SFD_ST_SUBSTATE_COUNT(102,0);
          _SFD_ST_SUBSTATE_COUNT(103,0);
          _SFD_ST_SUBSTATE_COUNT(104,3);
          _SFD_ST_SUBSTATE_INDEX(104,0,105);
          _SFD_ST_SUBSTATE_INDEX(104,1,106);
          _SFD_ST_SUBSTATE_INDEX(104,2,107);
          _SFD_ST_SUBSTATE_COUNT(105,0);
          _SFD_ST_SUBSTATE_COUNT(106,0);
          _SFD_ST_SUBSTATE_COUNT(107,0);
          _SFD_ST_SUBSTATE_COUNT(7,3);
          _SFD_ST_SUBSTATE_INDEX(7,0,8);
          _SFD_ST_SUBSTATE_INDEX(7,1,9);
          _SFD_ST_SUBSTATE_INDEX(7,2,10);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,3);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_INDEX(11,2,14);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,4);
          _SFD_ST_SUBSTATE_INDEX(15,0,16);
          _SFD_ST_SUBSTATE_INDEX(15,1,17);
          _SFD_ST_SUBSTATE_INDEX(15,2,18);
          _SFD_ST_SUBSTATE_INDEX(15,3,19);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,3);
          _SFD_ST_SUBSTATE_INDEX(20,0,21);
          _SFD_ST_SUBSTATE_INDEX(20,1,22);
          _SFD_ST_SUBSTATE_INDEX(20,2,23);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(23,0);
          _SFD_ST_SUBSTATE_COUNT(24,3);
          _SFD_ST_SUBSTATE_INDEX(24,0,25);
          _SFD_ST_SUBSTATE_INDEX(24,1,26);
          _SFD_ST_SUBSTATE_INDEX(24,2,27);
          _SFD_ST_SUBSTATE_COUNT(25,0);
          _SFD_ST_SUBSTATE_COUNT(26,0);
          _SFD_ST_SUBSTATE_COUNT(27,0);
          _SFD_ST_SUBSTATE_COUNT(37,3);
          _SFD_ST_SUBSTATE_INDEX(37,0,38);
          _SFD_ST_SUBSTATE_INDEX(37,1,39);
          _SFD_ST_SUBSTATE_INDEX(37,2,40);
          _SFD_ST_SUBSTATE_COUNT(38,0);
          _SFD_ST_SUBSTATE_COUNT(39,0);
          _SFD_ST_SUBSTATE_COUNT(40,0);
          _SFD_ST_SUBSTATE_COUNT(41,3);
          _SFD_ST_SUBSTATE_INDEX(41,0,42);
          _SFD_ST_SUBSTATE_INDEX(41,1,43);
          _SFD_ST_SUBSTATE_INDEX(41,2,44);
          _SFD_ST_SUBSTATE_COUNT(42,0);
          _SFD_ST_SUBSTATE_COUNT(43,0);
          _SFD_ST_SUBSTATE_COUNT(44,0);
          _SFD_ST_SUBSTATE_COUNT(45,3);
          _SFD_ST_SUBSTATE_INDEX(45,0,46);
          _SFD_ST_SUBSTATE_INDEX(45,1,47);
          _SFD_ST_SUBSTATE_INDEX(45,2,48);
          _SFD_ST_SUBSTATE_COUNT(46,0);
          _SFD_ST_SUBSTATE_COUNT(47,0);
          _SFD_ST_SUBSTATE_COUNT(48,0);
          _SFD_ST_SUBSTATE_COUNT(53,3);
          _SFD_ST_SUBSTATE_INDEX(53,0,54);
          _SFD_ST_SUBSTATE_INDEX(53,1,55);
          _SFD_ST_SUBSTATE_INDEX(53,2,56);
          _SFD_ST_SUBSTATE_COUNT(54,0);
          _SFD_ST_SUBSTATE_COUNT(55,0);
          _SFD_ST_SUBSTATE_COUNT(56,0);
          _SFD_ST_SUBSTATE_COUNT(57,3);
          _SFD_ST_SUBSTATE_INDEX(57,0,58);
          _SFD_ST_SUBSTATE_INDEX(57,1,59);
          _SFD_ST_SUBSTATE_INDEX(57,2,60);
          _SFD_ST_SUBSTATE_COUNT(58,0);
          _SFD_ST_SUBSTATE_COUNT(59,0);
          _SFD_ST_SUBSTATE_COUNT(60,0);
          _SFD_ST_SUBSTATE_COUNT(61,3);
          _SFD_ST_SUBSTATE_INDEX(61,0,62);
          _SFD_ST_SUBSTATE_INDEX(61,1,63);
          _SFD_ST_SUBSTATE_INDEX(61,2,64);
          _SFD_ST_SUBSTATE_COUNT(62,0);
          _SFD_ST_SUBSTATE_COUNT(63,0);
          _SFD_ST_SUBSTATE_COUNT(64,0);
          _SFD_ST_SUBSTATE_COUNT(69,3);
          _SFD_ST_SUBSTATE_INDEX(69,0,70);
          _SFD_ST_SUBSTATE_INDEX(69,1,71);
          _SFD_ST_SUBSTATE_INDEX(69,2,72);
          _SFD_ST_SUBSTATE_COUNT(70,0);
          _SFD_ST_SUBSTATE_COUNT(71,0);
          _SFD_ST_SUBSTATE_COUNT(72,0);
          _SFD_ST_SUBSTATE_COUNT(28,4);
          _SFD_ST_SUBSTATE_INDEX(28,0,29);
          _SFD_ST_SUBSTATE_INDEX(28,1,30);
          _SFD_ST_SUBSTATE_INDEX(28,2,31);
          _SFD_ST_SUBSTATE_INDEX(28,3,32);
          _SFD_ST_SUBSTATE_COUNT(29,0);
          _SFD_ST_SUBSTATE_COUNT(30,0);
          _SFD_ST_SUBSTATE_COUNT(31,0);
          _SFD_ST_SUBSTATE_COUNT(32,0);
          _SFD_ST_SUBSTATE_COUNT(33,3);
          _SFD_ST_SUBSTATE_INDEX(33,0,34);
          _SFD_ST_SUBSTATE_INDEX(33,1,35);
          _SFD_ST_SUBSTATE_INDEX(33,2,36);
          _SFD_ST_SUBSTATE_COUNT(34,0);
          _SFD_ST_SUBSTATE_COUNT(35,0);
          _SFD_ST_SUBSTATE_COUNT(36,0);
          _SFD_ST_SUBSTATE_COUNT(65,3);
          _SFD_ST_SUBSTATE_INDEX(65,0,66);
          _SFD_ST_SUBSTATE_INDEX(65,1,67);
          _SFD_ST_SUBSTATE_INDEX(65,2,68);
          _SFD_ST_SUBSTATE_COUNT(66,0);
          _SFD_ST_SUBSTATE_COUNT(67,0);
          _SFD_ST_SUBSTATE_COUNT(68,0);
          _SFD_ST_SUBSTATE_COUNT(73,3);
          _SFD_ST_SUBSTATE_INDEX(73,0,74);
          _SFD_ST_SUBSTATE_INDEX(73,1,75);
          _SFD_ST_SUBSTATE_INDEX(73,2,76);
          _SFD_ST_SUBSTATE_COUNT(74,0);
          _SFD_ST_SUBSTATE_COUNT(75,0);
          _SFD_ST_SUBSTATE_COUNT(76,0);
          _SFD_ST_SUBSTATE_COUNT(108,2);
          _SFD_ST_SUBSTATE_INDEX(108,0,109);
          _SFD_ST_SUBSTATE_INDEX(108,1,110);
          _SFD_ST_SUBSTATE_COUNT(109,0);
          _SFD_ST_SUBSTATE_COUNT(110,0);
          _SFD_ST_SUBSTATE_COUNT(111,2);
          _SFD_ST_SUBSTATE_INDEX(111,0,115);
          _SFD_ST_SUBSTATE_INDEX(111,1,112);
          _SFD_ST_SUBSTATE_COUNT(115,9);
          _SFD_ST_SUBSTATE_INDEX(115,0,116);
          _SFD_ST_SUBSTATE_INDEX(115,1,117);
          _SFD_ST_SUBSTATE_INDEX(115,2,118);
          _SFD_ST_SUBSTATE_INDEX(115,3,119);
          _SFD_ST_SUBSTATE_INDEX(115,4,120);
          _SFD_ST_SUBSTATE_INDEX(115,5,121);
          _SFD_ST_SUBSTATE_INDEX(115,6,122);
          _SFD_ST_SUBSTATE_INDEX(115,7,123);
          _SFD_ST_SUBSTATE_INDEX(115,8,124);
          _SFD_ST_SUBSTATE_COUNT(116,0);
          _SFD_ST_SUBSTATE_COUNT(117,0);
          _SFD_ST_SUBSTATE_COUNT(118,0);
          _SFD_ST_SUBSTATE_COUNT(119,0);
          _SFD_ST_SUBSTATE_COUNT(120,0);
          _SFD_ST_SUBSTATE_COUNT(121,0);
          _SFD_ST_SUBSTATE_COUNT(122,0);
          _SFD_ST_SUBSTATE_COUNT(123,0);
          _SFD_ST_SUBSTATE_COUNT(124,0);
          _SFD_ST_SUBSTATE_COUNT(112,2);
          _SFD_ST_SUBSTATE_INDEX(112,0,113);
          _SFD_ST_SUBSTATE_INDEX(112,1,114);
          _SFD_ST_SUBSTATE_COUNT(113,0);
          _SFD_ST_SUBSTATE_COUNT(114,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,26,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(23,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(24,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(25,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(26,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(27,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(28,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(29,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(30,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(31,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(32,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(33,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(34,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(35,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(36,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(37,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(38,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(39,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(40,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(41,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(42,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(43,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(44,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(45,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(46,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(47,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(48,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(49,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(50,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(51,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(52,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(53,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(54,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(55,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(56,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(57,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(58,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(59,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(60,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(61,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(62,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(63,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(64,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(65,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(66,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(67,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(68,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(69,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(70,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(71,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(72,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(73,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(74,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(75,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(76,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(77,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(78,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(79,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(80,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(81,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(82,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(83,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(84,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(85,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(86,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(87,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(88,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(89,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(90,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(91,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(92,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(93,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(94,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(95,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(96,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(97,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(98,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(99,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(100,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(101,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(102,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(103,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(104,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(105,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(106,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(107,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(108,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(109,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(110,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(111,2,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(112,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(113,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(114,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(115,9,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(116,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(117,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(118,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(119,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(120,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(121,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(122,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(123,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(124,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(47,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(48,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(79,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(80,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(29,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(28,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(34,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(33,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(37,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(49,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(38,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(50,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(88,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(87,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(89,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(86,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(104,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(102,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(103,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(105,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(110,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(111,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(112,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(93,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(91,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(92,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(90,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(78,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(76,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(77,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(75,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(84,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(83,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(82,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(81,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(96,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(94,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(97,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(95,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(44,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(46,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(85,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(55,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(53,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(54,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(56,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(52,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(51,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(66,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(67,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(68,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(69,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(70,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(65,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(64,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(63,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(62,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(61,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(26,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(27,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(42,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(43,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(41,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(40,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(74,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(73,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(72,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(71,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(100,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(101,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(99,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(98,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(59,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(60,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(58,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(57,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(109,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(107,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(106,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(108,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(125,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(113,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(115,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(114,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(117,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(116,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(118,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(119,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(123,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(128,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(120,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(121,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(122,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(127,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(124,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(126,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,1,0,29,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(2,0,"color1",0,-1,5585);
        _SFD_CV_INIT_EML_IF(2,1,0,1306,1315,1353,1399);
        _SFD_CV_INIT_EML_IF(2,1,1,1401,1410,1478,1546);
        _SFD_CV_INIT_EML_IF(2,1,2,1548,1557,1625,1693);
        _SFD_CV_INIT_EML_IF(2,1,3,1695,1704,1772,1840);
        _SFD_CV_INIT_EML_IF(2,1,4,1842,1851,1919,1987);
        _SFD_CV_INIT_EML_IF(2,1,5,1989,1998,2066,2135);
        _SFD_CV_INIT_EML_IF(2,1,6,2139,2148,2218,2288);
        _SFD_CV_INIT_EML_IF(2,1,7,2292,2301,2371,2441);
        _SFD_CV_INIT_EML_IF(2,1,8,2447,2456,2526,2596);
        _SFD_CV_INIT_EML_IF(2,1,9,2600,2610,2684,2756);
        _SFD_CV_INIT_EML_IF(2,1,10,2759,2769,2843,2915);
        _SFD_CV_INIT_EML_IF(2,1,11,2918,2928,3002,3074);
        _SFD_CV_INIT_EML_IF(2,1,12,3077,3087,3161,3233);
        _SFD_CV_INIT_EML_IF(2,1,13,3236,3246,3320,3392);
        _SFD_CV_INIT_EML_IF(2,1,14,3395,3405,3479,3551);
        _SFD_CV_INIT_EML_IF(2,1,15,3554,3564,3638,3710);
        _SFD_CV_INIT_EML_IF(2,1,16,3713,3723,3797,3869);
        _SFD_CV_INIT_EML_IF(2,1,17,3872,3882,3956,4028);
        _SFD_CV_INIT_EML_IF(2,1,18,4031,4041,4115,4187);
        _SFD_CV_INIT_EML_IF(2,1,19,4190,4200,4274,4346);
        _SFD_CV_INIT_EML_IF(2,1,20,4349,4359,4433,4505);
        _SFD_CV_INIT_EML_IF(2,1,21,4508,4518,4592,4664);
        _SFD_CV_INIT_EML_IF(2,1,22,4667,4677,4751,4823);
        _SFD_CV_INIT_EML_IF(2,1,23,4826,4836,4910,4982);
        _SFD_CV_INIT_EML_IF(2,1,24,4985,4995,5069,5141);
        _SFD_CV_INIT_EML_IF(2,1,25,5145,5154,5198,5247);
        _SFD_CV_INIT_EML_IF(2,1,26,5253,5262,5306,5357);
        _SFD_CV_INIT_EML_IF(2,1,27,5365,5375,5419,5470);
        _SFD_CV_INIT_EML_IF(2,1,28,5478,5488,5532,5582);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,0,1309,1315,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,1,1404,1410,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,2,1551,1557,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,3,1698,1704,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,4,1845,1851,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,5,1992,1998,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,6,2142,2148,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,7,2295,2301,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,8,2450,2456,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,9,2603,2610,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,10,2762,2769,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,11,2921,2928,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,12,3080,3087,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,13,3239,3246,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,14,3398,3405,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,15,3557,3564,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,16,3716,3723,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,17,3875,3882,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,18,4034,4041,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,19,4193,4200,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,20,4352,4359,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,21,4511,4518,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,22,4670,4677,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,23,4829,4836,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,24,4988,4995,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,25,5148,5154,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,26,5256,5262,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,27,5368,5375,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(2,1,28,5481,5488,-1,0);
        _SFD_CV_INIT_EML(84,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(82,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(85,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(83,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(90,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(87,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(88,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(89,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(103,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(101,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(102,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(107,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(105,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(106,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(94,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(92,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(93,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(98,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(96,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(99,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(97,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(80,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(78,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(79,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(56,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(54,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(55,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(72,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(70,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(71,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(109,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(52,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(50,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(51,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(60,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(58,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(59,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(44,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(42,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(43,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(48,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(46,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(47,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(64,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(62,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(63,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(40,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(38,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(39,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(18,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(16,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(17,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(31,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(29,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(30,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(32,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(27,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(25,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(26,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(14,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(13,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(36,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(35,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(34,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(68,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(66,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(67,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(23,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(21,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(22,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(76,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(74,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(75,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(121,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(122,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(124,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(116,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(117,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(118,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(119,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(120,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(113,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(12,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(12,0,0,1,33,1,33);

        {
          static int condStart[] = { 1, 18, 27 };

          static int condEnd[] = { 15, 24, 33 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(12,0,0,1,33,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,1,27,33,-1,1);
        _SFD_CV_INIT_EML(14,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(14,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(14,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(47,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(47,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 10 };

          static int condEnd[] = { 7, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(47,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(47,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(48,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(48,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(48,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(48,0,0,17,23,-1,0);
        _SFD_CV_INIT_EML(19,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(19,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(19,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(19,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML(79,0,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(79,0,0,1,51,1,48);

        {
          static int condStart[] = { 2, 11, 21, 37, 47 };

          static int condEnd[] = { 8, 17, 34, 44, 51 };

          static int pfixExpr[] = { 0, 1, -2, 2, -3, 3, -3, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(79,0,0,1,51,5,0,&(condStart[0]),&(condEnd[0]),9,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(79,0,0,2,8,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(79,0,1,11,17,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(79,0,2,37,44,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(79,0,3,47,51,-1,0);
        _SFD_CV_INIT_EML(17,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(17,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(17,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(30,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(30,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(30,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(30,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML(29,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(29,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(29,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(34,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(34,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(34,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(34,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(33,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(33,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(33,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(22,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(22,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(22,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(22,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML(23,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(23,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(23,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(37,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(37,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(37,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(37,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML(49,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(49,0,0,1,21,1,21);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 7, 21 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(49,0,0,1,21,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(49,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(38,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(38,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(38,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(50,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(50,0,0,1,23,1,23);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 23 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(50,0,0,1,23,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(50,0,0,17,23,-1,0);
        _SFD_CV_INIT_EML(10,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(10,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(10,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(11,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(88,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(88,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(88,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(88,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML(87,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(87,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(87,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(104,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(104,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(104,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(104,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(102,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(102,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(102,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(111,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML(5,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,7,1,7);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML(93,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(93,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(93,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(93,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(91,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(91,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(91,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(78,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(78,0,0,1,35,1,35);

        {
          static int condStart[] = { 1, 18, 28 };

          static int condEnd[] = { 15, 25, 35 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(78,0,0,1,35,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(78,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(78,0,1,28,35,-1,0);
        _SFD_CV_INIT_EML(76,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(76,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(76,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,41,1,41);

        {
          static int condStart[] = { 1, 8, 18, 28 };

          static int condEnd[] = { 5, 15, 25, 41 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,41,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,5,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,8,15,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,2,18,25,-1,0);
        _SFD_CV_INIT_EML(0,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(0,0,0,1,21,1,21);

        {
          static int condStart[] = { 2, 9 };

          static int condEnd[] = { 6, 21 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,0,2,21,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,2,6,-1,4);
        _SFD_CV_INIT_EML(84,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(83,0,0,0,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_IF(83,0,0,1,33,1,33);

        {
          static int condStart[] = { 1, 18, 27 };

          static int condEnd[] = { 15, 24, 33 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_EML_MCDC(83,0,0,1,33,3,0,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(83,0,0,18,24,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(83,0,1,27,33,-1,4);
        _SFD_CV_INIT_EML(82,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(82,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(82,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(96,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(96,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(96,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(96,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(94,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(94,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(94,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(44,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(46,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(46,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(46,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(46,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(45,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(45,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(45,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(55,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(55,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(55,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(55,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(53,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(53,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(53,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(54,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(54,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 9 };

          static int condEnd[] = { 8, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(54,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(54,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(56,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(56,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 14, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(56,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(56,0,0,15,22,-1,0);
        _SFD_CV_INIT_EML(66,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(66,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 9 };

          static int condEnd[] = { 8, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(66,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(66,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(67,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(67,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(67,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(67,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(68,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(68,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(68,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(70,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(70,0,0,1,22,1,22);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 14, 22 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(70,0,0,1,22,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(70,0,0,15,22,-1,0);
        _SFD_CV_INIT_EML(64,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(64,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(64,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(64,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(63,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(63,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(63,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(26,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(26,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(26,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(26,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(25,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(25,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(25,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(42,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(42,0,0,1,25,1,25);

        {
          static int condStart[] = { 1, 18 };

          static int condEnd[] = { 15, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(42,0,0,1,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(42,0,0,18,25,-1,0);
        _SFD_CV_INIT_EML(43,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(43,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(43,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(74,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(73,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(73,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(73,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(73,0,0,17,24,-1,0);
        _SFD_CV_INIT_EML(72,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(72,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(72,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(100,0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(101,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(101,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(101,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(101,0,0,17,24,-1,0);
        _SFD_CV_INIT_EML(99,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(99,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(99,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(59,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(59,0,0,1,25,1,25);

        {
          static int condStart[] = { 2, 11 };

          static int condEnd[] = { 9, 25 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(59,0,0,2,25,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(59,0,0,2,9,-1,0);
        _SFD_CV_INIT_EML(60,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(60,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(60,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(109,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(109,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 17 };

          static int condEnd[] = { 14, 24 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(109,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(109,0,0,17,24,-1,0);
        _SFD_CV_INIT_EML(107,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(107,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(107,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(113,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(113,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(113,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(115,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(115,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(115,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(114,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(114,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(114,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(119,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(119,0,0,1,16,1,16);

        {
          static int condStart[] = { 1, 9 };

          static int condEnd[] = { 8, 16 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(119,0,0,1,16,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(119,0,0,1,8,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(119,0,1,9,16,-1,0);
        _SFD_CV_INIT_EML(123,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(123,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(123,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(128,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(128,0,0,1,16,1,16);

        {
          static int condStart[] = { 1, 9 };

          static int condEnd[] = { 8, 16 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(128,0,0,1,16,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(128,0,0,1,8,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(128,0,1,9,16,-1,0);
        _SFD_CV_INIT_EML(120,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(120,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(120,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(121,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(121,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(121,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(122,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(122,0,0,1,8,1,8);
        _SFD_CV_INIT_EML_RELATIONAL(122,0,0,1,8,-1,0);
        _SFD_CV_INIT_EML(124,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(124,0,0,1,15,1,15);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(58,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(59,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(60,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(61,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(62,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(63,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(64,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(65,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(66,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(67,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(68,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(69,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(70,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(71,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(72,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(73,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(74,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(75,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(76,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(77,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(78,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(79,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(80,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(81,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(82,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(83,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(84,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(85,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(86,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(87,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(88,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(89,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(90,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(91,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(92,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(93,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(94,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(95,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(96,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(97,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(98,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(99,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(100,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(101,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(102,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(103,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(104,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(105,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(106,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(107,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(108,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(109,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(110,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(111,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(112,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(113,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(114,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ver_601MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ver_601InstanceStruct *chartInstance = (SFc3_ver_601InstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(52U, chartInstance->c3_vr1);
        _SFD_SET_DATA_VALUE_PTR(63U, chartInstance->c3_vr2);
        _SFD_SET_DATA_VALUE_PTR(26U, chartInstance->c3_j1);
        _SFD_SET_DATA_VALUE_PTR(74U, chartInstance->c3_vr7);
        _SFD_SET_DATA_VALUE_PTR(73U, chartInstance->c3_vr6);
        _SFD_SET_DATA_VALUE_PTR(75U, chartInstance->c3_vr8);
        _SFD_SET_DATA_VALUE_PTR(72U, chartInstance->c3_vr5);
        _SFD_SET_DATA_VALUE_PTR(70U, chartInstance->c3_vr3);
        _SFD_SET_DATA_VALUE_PTR(71U, chartInstance->c3_vr4);
        _SFD_SET_DATA_VALUE_PTR(111U, chartInstance->c3_as1);
        _SFD_SET_DATA_VALUE_PTR(76U, chartInstance->c3_vr9);
        _SFD_SET_DATA_VALUE_PTR(54U, chartInstance->c3_vr11);
        _SFD_SET_DATA_VALUE_PTR(55U, chartInstance->c3_vr12);
        _SFD_SET_DATA_VALUE_PTR(53U, chartInstance->c3_vr10);
        _SFD_SET_DATA_VALUE_PTR(112U, chartInstance->c3_as2);
        _SFD_SET_DATA_VALUE_PTR(60U, chartInstance->c3_vr17);
        _SFD_SET_DATA_VALUE_PTR(56U, chartInstance->c3_vr13);
        _SFD_SET_DATA_VALUE_PTR(113U, chartInstance->c3_as3);
        _SFD_SET_DATA_VALUE_PTR(57U, chartInstance->c3_vr14);
        _SFD_SET_DATA_VALUE_PTR(58U, chartInstance->c3_vr15);
        _SFD_SET_DATA_VALUE_PTR(59U, chartInstance->c3_vr16);
        _SFD_SET_DATA_VALUE_PTR(114U, chartInstance->c3_as4);
        _SFD_SET_DATA_VALUE_PTR(102U, chartInstance->c3_d1);
        _SFD_SET_DATA_VALUE_PTR(61U, chartInstance->c3_vr18);
        _SFD_SET_DATA_VALUE_PTR(62U, chartInstance->c3_vr19);
        _SFD_SET_DATA_VALUE_PTR(95U, chartInstance->c3_vs3);
        _SFD_SET_DATA_VALUE_PTR(45U, chartInstance->c3_vn3);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c3_dp3);
        _SFD_SET_DATA_VALUE_PTR(37U, chartInstance->c3_vn19);
        _SFD_SET_DATA_VALUE_PTR(87U, chartInstance->c3_vs19);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c3_dp2);
        _SFD_SET_DATA_VALUE_PTR(38U, chartInstance->c3_vn2);
        _SFD_SET_DATA_VALUE_PTR(88U, chartInstance->c3_vs2);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_dp1);
        _SFD_SET_DATA_VALUE_PTR(77U, chartInstance->c3_vs1);
        _SFD_SET_DATA_VALUE_PTR(49U, chartInstance->c3_vn7);
        _SFD_SET_DATA_VALUE_PTR(99U, chartInstance->c3_vs7);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_dp10);
        _SFD_SET_DATA_VALUE_PTR(28U, chartInstance->c3_vn10);
        _SFD_SET_DATA_VALUE_PTR(78U, chartInstance->c3_vs10);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_dp11);
        _SFD_SET_DATA_VALUE_PTR(29U, chartInstance->c3_vn11);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c3_dp16);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_dp13);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_dp12);
        _SFD_SET_DATA_VALUE_PTR(33U, chartInstance->c3_vn15);
        _SFD_SET_DATA_VALUE_PTR(34U, chartInstance->c3_vn16);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_dp15);
        _SFD_SET_DATA_VALUE_PTR(82U, chartInstance->c3_vs14);
        _SFD_SET_DATA_VALUE_PTR(32U, chartInstance->c3_vn14);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_dp14);
        _SFD_SET_DATA_VALUE_PTR(85U, chartInstance->c3_vs17);
        _SFD_SET_DATA_VALUE_PTR(80U, chartInstance->c3_vs12);
        _SFD_SET_DATA_VALUE_PTR(81U, chartInstance->c3_vs13);
        _SFD_SET_DATA_VALUE_PTR(30U, chartInstance->c3_vn12);
        _SFD_SET_DATA_VALUE_PTR(35U, chartInstance->c3_vn17);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_dp17);
        _SFD_SET_DATA_VALUE_PTR(79U, chartInstance->c3_vs11);
        _SFD_SET_DATA_VALUE_PTR(84U, chartInstance->c3_vs16);
        _SFD_SET_DATA_VALUE_PTR(83U, chartInstance->c3_vs15);
        _SFD_SET_DATA_VALUE_PTR(31U, chartInstance->c3_vn13);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c3_dp4);
        _SFD_SET_DATA_VALUE_PTR(46U, chartInstance->c3_vn4);
        _SFD_SET_DATA_VALUE_PTR(96U, chartInstance->c3_vs4);
        _SFD_SET_DATA_VALUE_PTR(21U, chartInstance->c3_dp5);
        _SFD_SET_DATA_VALUE_PTR(47U, chartInstance->c3_vn5);
        _SFD_SET_DATA_VALUE_PTR(97U, chartInstance->c3_vs5);
        _SFD_SET_DATA_VALUE_PTR(22U, chartInstance->c3_dp6);
        _SFD_SET_DATA_VALUE_PTR(48U, chartInstance->c3_vn6);
        _SFD_SET_DATA_VALUE_PTR(98U, chartInstance->c3_vs6);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_dp18);
        _SFD_SET_DATA_VALUE_PTR(36U, chartInstance->c3_vn18);
        _SFD_SET_DATA_VALUE_PTR(86U, chartInstance->c3_vs18);
        _SFD_SET_DATA_VALUE_PTR(25U, chartInstance->c3_dp9);
        _SFD_SET_DATA_VALUE_PTR(24U, chartInstance->c3_dp8);
        _SFD_SET_DATA_VALUE_PTR(51U, chartInstance->c3_vn9);
        _SFD_SET_DATA_VALUE_PTR(50U, chartInstance->c3_vn8);
        _SFD_SET_DATA_VALUE_PTR(101U, chartInstance->c3_vs9);
        _SFD_SET_DATA_VALUE_PTR(100U, chartInstance->c3_vs8);
        _SFD_SET_DATA_VALUE_PTR(23U, chartInstance->c3_dp7);
        _SFD_SET_DATA_VALUE_PTR(66U, chartInstance->c3_vr22);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c3_dp22);
        _SFD_SET_DATA_VALUE_PTR(41U, chartInstance->c3_vn22);
        _SFD_SET_DATA_VALUE_PTR(91U, chartInstance->c3_vs22);
        _SFD_SET_DATA_VALUE_PTR(92U, chartInstance->c3_vs23);
        _SFD_SET_DATA_VALUE_PTR(67U, chartInstance->c3_vr23);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c3_dp23);
        _SFD_SET_DATA_VALUE_PTR(42U, chartInstance->c3_vn23);
        _SFD_SET_DATA_VALUE_PTR(90U, chartInstance->c3_vs21);
        _SFD_SET_DATA_VALUE_PTR(65U, chartInstance->c3_vr21);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c3_dp21);
        _SFD_SET_DATA_VALUE_PTR(40U, chartInstance->c3_vn21);
        _SFD_SET_DATA_VALUE_PTR(64U, chartInstance->c3_vr20);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c3_dp20);
        _SFD_SET_DATA_VALUE_PTR(39U, chartInstance->c3_vn20);
        _SFD_SET_DATA_VALUE_PTR(89U, chartInstance->c3_vs20);
        _SFD_SET_DATA_VALUE_PTR(103U, chartInstance->c3_asan1);
        _SFD_SET_DATA_VALUE_PTR(104U, chartInstance->c3_asan2);
        _SFD_SET_DATA_VALUE_PTR(105U, chartInstance->c3_asan3);
        _SFD_SET_DATA_VALUE_PTR(106U, chartInstance->c3_asan4);
        _SFD_SET_DATA_VALUE_PTR(107U, chartInstance->c3_random);
        _SFD_SET_DATA_VALUE_PTR(108U, chartInstance->c3_d2);
        _SFD_SET_DATA_VALUE_PTR(69U, chartInstance->c3_vr25);
        _SFD_SET_DATA_VALUE_PTR(94U, chartInstance->c3_vs25);
        _SFD_SET_DATA_VALUE_PTR(44U, chartInstance->c3_vn25);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c3_dp25);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c3_dp24);
        _SFD_SET_DATA_VALUE_PTR(43U, chartInstance->c3_vn24);
        _SFD_SET_DATA_VALUE_PTR(68U, chartInstance->c3_vr24);
        _SFD_SET_DATA_VALUE_PTR(93U, chartInstance->c3_vs24);
        _SFD_SET_DATA_VALUE_PTR(109U, chartInstance->c3_s);
        _SFD_SET_DATA_VALUE_PTR(110U, chartInstance->c3_yuk);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_dag);
        _SFD_SET_DATA_VALUE_PTR(27U, chartInstance->c3_sayac);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c3_dp19);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "snHgYlxHXaRNpbr3Gbq7pf";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_ver_601_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c3_ver_601(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_ver_601InstanceStruct*) chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_ver_601InstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
  initialize_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_ver_601(void *chartInstanceVar)
{
  enable_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_ver_601(void *chartInstanceVar)
{
  disable_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_ver_601(void *chartInstanceVar)
{
  sf_gateway_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_ver_601(void *chartInstanceVar)
{
  ext_mode_exec_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_ver_601(SimStruct* S)
{
  return get_sim_state_c3_ver_601((SFc3_ver_601InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_ver_601(SimStruct* S, const mxArray *st)
{
  set_sim_state_c3_ver_601((SFc3_ver_601InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_ver_601(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ver_601InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ver_601_optimization_info();
    }

    finalize_c3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_ver_601((SFc3_ver_601InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ver_601(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_ver_601((SFc3_ver_601InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c3_ver_601_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x10'varName','path'{{T\"is_active_c3_ver_601\",T\"is_active_c3_ver_601\"},{T\"is_c3_ver_601\",T\"is_c3_ver_601\"},{T\"is_active_m1\",T\"m3.m1.is_active_m1\"},{T\"is_r4\",T\"m3.m1.r4.is_r4\"},{T\"is_active_r4\",T\"m3.m1.r4.is_active_r4\"},{T\"is_r5\",T\"m3.m1.r5.is_r5\"},{T\"is_active_r5\",T\"m3.m1.r5.is_active_r5\"},{T\"is_r8\",T\"m3.m1.r8.is_r8\"},{T\"is_active_r8\",T\"m3.m1.r8.is_active_r8\"},{T\"is_r9\",T\"m3.m1.r9.is_r9\"}}",
    "100 S1x10'varName','path'{{T\"is_active_r9\",T\"m3.m1.r9.is_active_r9\"},{T\"is_r6\",T\"m3.m1.r6.is_r6\"},{T\"is_active_r6\",T\"m3.m1.r6.is_active_r6\"},{T\"is_r7\",T\"m3.m1.r7.is_r7\"},{T\"is_active_r7\",T\"m3.m1.r7.is_active_r7\"},{T\"is_r3\",T\"m3.m1.r3.is_r3\"},{T\"is_active_r3\",T\"m3.m1.r3.is_active_r3\"},{T\"is_r20\",T\"m3.m1.r20.is_r20\"},{T\"is_active_r20\",T\"m3.m1.r20.is_active_r20\"},{T\"is_r24\",T\"m3.m1.r24.is_r24\"}}",
    "100 S1x10'varName','path'{{T\"is_active_r24\",T\"m3.m1.r24.is_active_r24\"},{T\"is_tictoc\",T\"m3.m1.tictoc.is_tictoc\"},{T\"is_active_tictoc\",T\"m3.m1.tictoc.is_active_tictoc\"},{T\"is_r2\",T\"m3.m1.r2.is_r2\"},{T\"is_active_r2\",T\"m3.m1.r2.is_active_r2\"},{T\"is_r21\",T\"m3.m1.r21.is_r21\"},{T\"is_active_r21\",T\"m3.m1.r21.is_active_r21\"},{T\"is_r18\",T\"m3.m1.r18.is_r18\"},{T\"is_active_r18\",T\"m3.m1.r18.is_active_r18\"},{T\"is_r1\",T\"m3.m1.r1.is_r1\"}}",
    "100 S1x10'varName','path'{{T\"is_active_r1\",T\"m3.m1.r1.is_active_r1\"},{T\"is_r19\",T\"m3.m1.r19.is_r19\"},{T\"is_active_r19\",T\"m3.m1.r19.is_active_r19\"},{T\"is_r22\",T\"m3.m1.r22.is_r22\"},{T\"is_active_r22\",T\"m3.m1.r22.is_active_r22\"},{T\"is_r17\",T\"m3.m1.r17.is_r17\"},{T\"is_active_r17\",T\"m3.m1.r17.is_active_r17\"},{T\"is_r12\",T\"m3.m1.r12.is_r12\"},{T\"is_active_r12\",T\"m3.m1.r12.is_active_r12\"},{T\"is_r15\",T\"m3.m1.r15.is_r15\"}}",
    "100 S1x10'varName','path'{{T\"is_active_r15\",T\"m3.m1.r15.is_active_r15\"},{T\"is_r14\",T\"m3.m1.r14.is_r14\"},{T\"is_active_r14\",T\"m3.m1.r14.is_active_r14\"},{T\"is_r10\",T\"m3.m1.r10.is_r10\"},{T\"is_active_r10\",T\"m3.m1.r10.is_active_r10\"},{T\"is_r11\",T\"m3.m1.r11.is_r11\"},{T\"is_active_r11\",T\"m3.m1.r11.is_active_r11\"},{T\"is_r16\",T\"m3.m1.r16.is_r16\"},{T\"is_active_r16\",T\"m3.m1.r16.is_active_r16\"},{T\"is_r23\",T\"m3.m1.r23.is_r23\"}}",
    "100 S1x10'varName','path'{{T\"is_active_r23\",T\"m3.m1.r23.is_active_r23\"},{T\"is_r13\",T\"m3.m1.r13.is_r13\"},{T\"is_active_r13\",T\"m3.m1.r13.is_active_r13\"},{T\"is_r25\",T\"m3.m1.r25.is_r25\"},{T\"is_active_r25\",T\"m3.m1.r25.is_active_r25\"},{T\"is_active_rdn\",T\"m3.rdn.is_active_rdn\"},{T\"is_is\",T\"m3.rdn.is.is_is\"},{T\"is_active_is\",T\"m3.rdn.is.is_active_is\"},{T\"is_dindan\",T\"m3.rdn.dindan.is_dindan\"},{T\"is_active_dindan\",T\"m3.rdn.dindan.is_active_dindan\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 60, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint16\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],}}",
    "100 S1x2'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id','maxStringLength'{{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],},{T\"uint32\",,,,,,,M[0],M[],M[-1],M[-1],}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 192, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 1857175768U, 2373387450U, 2371071418U,
    1253993700U };

  return checksum;
}

static void mdlSetWorkWidths_c3_ver_601(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetInputPortDirectFeedThrough(S, 2, 1);
  ssSetInputPortDirectFeedThrough(S, 3, 1);
  ssSetInputPortDirectFeedThrough(S, 4, 1);
  ssSetInputPortDirectFeedThrough(S, 5, 1);
  ssSetInputPortDirectFeedThrough(S, 6, 1);
  ssSetInputPortDirectFeedThrough(S, 7, 1);
  ssSetInputPortDirectFeedThrough(S, 8, 1);
  ssSetInputPortDirectFeedThrough(S, 9, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ver_601_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
    }

    ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1779153230U));
  ssSetChecksum1(S,(437585836U));
  ssSetChecksum2(S,(2587010084U));
  ssSetChecksum3(S,(311898088U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ver_601(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_ver_601(SimStruct *S)
{
  SFc3_ver_601InstanceStruct *chartInstance;
  chartInstance = (SFc3_ver_601InstanceStruct *)utMalloc(sizeof
    (SFc3_ver_601InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_ver_601InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_ver_601;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_ver_601;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_ver_601;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ver_601;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ver_601;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_ver_601;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_ver_601;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c3_ver_601;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ver_601;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ver_601;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_ver_601;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = sf_opaque_ext_mode_exec_c3_ver_601;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0, NULL, NULL);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_ver_601(chartInstance);
}

void c3_ver_601_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ver_601(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ver_601(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ver_601(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ver_601_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
