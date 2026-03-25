// Koka generated module: src/metrics/@main, koka version: 3.2.2, platform: 64-bit
#include "src_metrics__main.h"


// lift anonymous function
struct kk_src_metrics__main__expr_fun35__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics__main__expr_fun35(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_expr_fun35(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics__main__expr_fun35, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_metrics__main__expr_fun35(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x36;
  kk_src_metrics__metrics_snapshot _x_x37 = kk_src_metrics__metrics_snapshot_unbox(_b_x2, KK_OWNED, _ctx); /*src/metrics/metrics-snapshot*/
  _x_x36 = kk_src_metrics_export_all(_x_x37, _ctx); /*string*/
  return kk_string_box(_x_x36);
}

kk_unit_t kk_src_metrics__main__expr(kk_context_t* _ctx) { /* () -> io () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_src_metrics__metrics_snapshot x;
  kk_string_t _x_x31;
  kk_define_string_literal(, _s_x32, 4, "test", _ctx)
  _x_x31 = kk_string_dup(_s_x32, _ctx); /*string*/
  x = kk_src_metrics_standard_ipc_metrics(_x_x31, _ctx); /*src/metrics/metrics-snapshot*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t _x_x33;
  kk_box_t _x_x34 = kk_std_core_hnd__open_none1(kk_src_metrics__main__new_expr_fun35(_ctx), kk_src_metrics__metrics_snapshot_box(x, _ctx), _ctx); /*10001*/
  _x_x33 = kk_string_unbox(_x_x34); /*string*/
  kk_std_core_console_printsln(_x_x33, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_src_metrics__main__main_fun39__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics__main__main_fun39(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun39(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics__main__main_fun39, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_metrics__main__main_fun40__t {
  struct kk_function_s _base;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_src_metrics__main__main_fun40(kk_function_t _fself, kk_function_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun40(kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun40__t* _self = kk_function_alloc_as(struct kk_src_metrics__main__main_fun40__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_metrics__main__main_fun40, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_src_metrics__main__main_fun41__t {
  struct kk_function_s _base;
  kk_function_t _b_x7;
};
static kk_unit_t kk_src_metrics__main__main_fun41(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x8, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun41(kk_function_t _b_x7, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun41__t* _self = kk_function_alloc_as(struct kk_src_metrics__main__main_fun41__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_metrics__main__main_fun41, kk_context());
  _self->_b_x7 = _b_x7;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_src_metrics__main__main_fun41(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x8, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun41__t* _self = kk_function_as(struct kk_src_metrics__main__main_fun41__t*, _fself, _ctx);
  kk_function_t _b_x7 = _self->_b_x7; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x7, _ctx);}, {}, _ctx)
  kk_box_t _x_x42 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x7, (_b_x7, _b_x8, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x42); return kk_Unit;
}
static kk_box_t kk_src_metrics__main__main_fun40(kk_function_t _fself, kk_function_t _b_x7, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun40__t* _self = kk_function_as(struct kk_src_metrics__main__main_fun40__t*, _fself, _ctx);
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_t ___wildcard_x653__45_28 = kk_src_metrics__main__new_main_fun41(_b_x7, _ctx); /*(hnd/resume-result<10002,()>) -> <console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>> ()*/;
  kk_function_drop(___wildcard_x653__45_28, _ctx);
  kk_string_t _x_x43;
  kk_define_string_literal(, _s_x44, 20, "uncaught exception: ", _ctx)
  _x_x43 = kk_string_dup(_s_x44, _ctx); /*string*/
  kk_std_core_console_prints(_x_x43, _ctx);
  kk_unit_t _x_x45 = kk_Unit;
  kk_string_t _x_x46 = kk_std_core_exn_show(x, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x46, _ctx);
  return kk_unit_box(_x_x45);
}
static kk_box_t kk_src_metrics__main__main_fun39(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_src_metrics__main__new_main_fun40(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_src_metrics__main__main_fun49__t {
  struct kk_function_s _base;
  kk_function_t _b_x9_23;
};
static kk_box_t kk_src_metrics__main__main_fun49(kk_function_t _fself, int32_t _b_x10, kk_std_core_hnd__ev _b_x11, kk_box_t _b_x12, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun49(kk_function_t _b_x9_23, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun49__t* _self = kk_function_alloc_as(struct kk_src_metrics__main__main_fun49__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_metrics__main__main_fun49, kk_context());
  _self->_b_x9_23 = _b_x9_23;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_metrics__main__main_fun49(kk_function_t _fself, int32_t _b_x10, kk_std_core_hnd__ev _b_x11, kk_box_t _b_x12, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun49__t* _self = kk_function_as(struct kk_src_metrics__main__main_fun49__t*, _fself, _ctx);
  kk_function_t _b_x9_23 = _self->_b_x9_23; /* (m : hnd/marker<<console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>>,()>, hnd/ev<exn>, x : exception) -> <console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>> 10002 */
  kk_drop_match(_self, {kk_function_dup(_b_x9_23, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x50 = kk_std_core_exn__exception_unbox(_b_x12, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x9_23, (_b_x9_23, _b_x10, _b_x11, _x_x50, _ctx), _ctx);
}


// lift anonymous function
struct kk_src_metrics__main__main_fun51__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics__main__main_fun51(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun51(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics__main__main_fun51, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_metrics__main__main_fun51(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_29 = kk_Unit;
  kk_unit_unbox(_b_x19);
  return kk_unit_box(_res_29);
}


// lift anonymous function
struct kk_src_metrics__main__main_fun52__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_metrics__main__main_fun52(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun52(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics__main__main_fun52, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_metrics__main__main_fun56__t {
  struct kk_function_s _base;
};
static kk_string_t kk_src_metrics__main__main_fun56(kk_function_t _fself, kk_src_metrics__metrics_snapshot _x1_x55, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun56(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_metrics__main__main_fun56, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_src_metrics__main__main_fun56(kk_function_t _fself, kk_src_metrics__metrics_snapshot _x1_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_src_metrics_export_all(_x1_x55, _ctx);
}


// lift anonymous function
struct kk_src_metrics__main__main_fun60__t {
  struct kk_function_s _base;
  kk_function_t _b_x13_26;
};
static kk_box_t kk_src_metrics__main__main_fun60(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_src_metrics__main__new_main_fun60(kk_function_t _b_x13_26, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun60__t* _self = kk_function_alloc_as(struct kk_src_metrics__main__main_fun60__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_metrics__main__main_fun60, kk_context());
  _self->_b_x13_26 = _b_x13_26;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_metrics__main__main_fun60(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx) {
  struct kk_src_metrics__main__main_fun60__t* _self = kk_function_as(struct kk_src_metrics__main__main_fun60__t*, _fself, _ctx);
  kk_function_t _b_x13_26 = _self->_b_x13_26; /* (snapshot : src/metrics/metrics-snapshot) -> string */
  kk_drop_match(_self, {kk_function_dup(_b_x13_26, _ctx);}, {}, _ctx)
  kk_string_t _x_x61;
  kk_src_metrics__metrics_snapshot _x_x62 = kk_src_metrics__metrics_snapshot_unbox(_b_x15, KK_OWNED, _ctx); /*src/metrics/metrics-snapshot*/
  _x_x61 = kk_function_call(kk_string_t, (kk_function_t, kk_src_metrics__metrics_snapshot, kk_context_t*), _b_x13_26, (_b_x13_26, _x_x62, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x61);
}
static kk_box_t kk_src_metrics__main__main_fun52(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_src_metrics__metrics_snapshot x_0;
  kk_string_t _x_x53;
  kk_define_string_literal(, _s_x54, 4, "test", _ctx)
  _x_x53 = kk_string_dup(_s_x54, _ctx); /*string*/
  x_0 = kk_src_metrics_standard_ipc_metrics(_x_x53, _ctx); /*src/metrics/metrics-snapshot*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_function_t _b_x13_26 = kk_src_metrics__main__new_main_fun56(_ctx); /*(snapshot : src/metrics/metrics-snapshot) -> string*/;
  kk_src_metrics__metrics_snapshot _b_x14_27 = x_0; /*src/metrics/metrics-snapshot*/;
  kk_unit_t _x_x57 = kk_Unit;
  kk_string_t _x_x58;
  kk_box_t _x_x59 = kk_std_core_hnd__open_none1(kk_src_metrics__main__new_main_fun60(_b_x13_26, _ctx), kk_src_metrics__metrics_snapshot_box(_b_x14_27, _ctx), _ctx); /*10001*/
  _x_x58 = kk_string_unbox(_x_x59); /*string*/
  kk_std_core_console_printsln(_x_x58, _ctx);
  return kk_unit_box(_x_x57);
}

kk_unit_t kk_src_metrics__main__main(kk_context_t* _ctx) { /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 
  kk_box_t _x_x38;
  kk_function_t _b_x9_23 = kk_src_metrics__main__new_main_fun39(_ctx); /*(m : hnd/marker<<console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>>,()>, hnd/ev<exn>, x : exception) -> <console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>> 10002*/;
  kk_std_core_exn__exn _x_x47;
  kk_std_core_hnd__clause1 _x_x48 = kk_std_core_hnd__new_Clause1(kk_src_metrics__main__new_main_fun49(_b_x9_23, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x47 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x48, _ctx); /*exn<10005,10006>*/
  _x_x38 = kk_std_core_exn_exn_fs__handle(_x_x47, kk_src_metrics__main__new_main_fun51(_ctx), kk_src_metrics__main__new_main_fun52(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x38); return kk_Unit;
}

// initialization
void kk_src_metrics__main__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_time_timestamp__init(_ctx);
  kk_std_num_decimal__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_int32__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_utc__init(_ctx);
  kk_std_time_chrono__init(_ctx);
  kk_std_time_timer__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_calendars__init(_ctx);
  kk_std_time_time__init(_ctx);
  kk_std_time_locale__init(_ctx);
  kk_std_time_format__init(_ctx);
  kk_std_time_parse__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_time__init(_ctx);
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  kk_src_metrics__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_metrics__main__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_src_metrics__done(_ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
  kk_std_time__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_time_parse__done(_ctx);
  kk_std_time_format__done(_ctx);
  kk_std_time_locale__done(_ctx);
  kk_std_time_time__done(_ctx);
  kk_std_time_calendars__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_timer__done(_ctx);
  kk_std_time_chrono__done(_ctx);
  kk_std_time_utc__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_text_parse__done(_ctx);
  kk_std_num_decimal__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
}

// main library entry points
void main_init(kk_context_t* _ctx) {
  kk_src_metrics__main__init(_ctx);
}
void main_run(kk_context_t* _ctx) {
  kk_src_metrics__main__main(_ctx);
}
void main_done(kk_context_t* _ctx) {
  kk_src_metrics__main__done(_ctx);
}

static void main_at_exit(void) {
  kk_context_t* _ctx = kk_get_context();
  main_done(_ctx);
}

// main program entry point
// `kk_main_start`/`kk_main_end` are only called for passing command line arguments and process timing
// (`kk_get_context()` can be used to get a context without calling `kk_main_start`)
int main(int argc, char** argv) {
  kk_assert(sizeof(size_t)==8 && sizeof(void*)==8);
  kk_context_t* _ctx = kk_main_start(argc, argv);
  main_init(_ctx); atexit(&main_at_exit);
  main_run(_ctx);
  main_done(_ctx); kk_main_end(_ctx);
  return 0;
}
