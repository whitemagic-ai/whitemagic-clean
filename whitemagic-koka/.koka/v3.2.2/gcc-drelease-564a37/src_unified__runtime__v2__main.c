// Koka generated module: src/unified_runtime_v2/@main, koka version: 3.2.2, platform: 64-bit
#include "src_unified__runtime__v2__main.h"


// lift anonymous function
struct kk_src_unified__runtime__v2__main__main_fun25__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__main__main_fun25(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__main__new_main_fun25(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__main__main_fun25, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_unified__runtime__v2__main__main_fun26__t {
  struct kk_function_s _base;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_src_unified__runtime__v2__main__main_fun26(kk_function_t _fself, kk_function_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__main__new_main_fun26(kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__main__main_fun26__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2__main__main_fun26__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2__main__main_fun26, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_src_unified__runtime__v2__main__main_fun27__t {
  struct kk_function_s _base;
  kk_function_t _b_x2;
};
static kk_unit_t kk_src_unified__runtime__v2__main__main_fun27(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x3, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__main__new_main_fun27(kk_function_t _b_x2, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__main__main_fun27__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2__main__main_fun27__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2__main__main_fun27, kk_context());
  _self->_b_x2 = _b_x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_src_unified__runtime__v2__main__main_fun27(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x3, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__main__main_fun27__t* _self = kk_function_as(struct kk_src_unified__runtime__v2__main__main_fun27__t*, _fself, _ctx);
  kk_function_t _b_x2 = _self->_b_x2; /* (hnd/resume-result<10000,10003>) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x2, _ctx);}, {}, _ctx)
  kk_box_t _x_x28 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x2, (_b_x2, _b_x3, _ctx), _ctx); /*10003*/
  kk_unit_unbox(_x_x28); return kk_Unit;
}
static kk_box_t kk_src_unified__runtime__v2__main__main_fun26(kk_function_t _fself, kk_function_t _b_x2, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__main__main_fun26__t* _self = kk_function_as(struct kk_src_unified__runtime__v2__main__main_fun26__t*, _fself, _ctx);
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_t ___wildcard_x653__45_18 = kk_src_unified__runtime__v2__main__new_main_fun27(_b_x2, _ctx); /*(hnd/resume-result<10002,()>) -> <console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>> ()*/;
  kk_function_drop(___wildcard_x653__45_18, _ctx);
  kk_string_t _x_x29;
  kk_define_string_literal(, _s_x30, 20, "uncaught exception: ", _ctx)
  _x_x29 = kk_string_dup(_s_x30, _ctx); /*string*/
  kk_std_core_console_prints(_x_x29, _ctx);
  kk_unit_t _x_x31 = kk_Unit;
  kk_string_t _x_x32 = kk_std_core_exn_show(x, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x32, _ctx);
  return kk_unit_box(_x_x31);
}
static kk_box_t kk_src_unified__runtime__v2__main__main_fun25(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x653__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x653__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_src_unified__runtime__v2__main__new_main_fun26(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__main__main_fun35__t {
  struct kk_function_s _base;
  kk_function_t _b_x4_15;
};
static kk_box_t kk_src_unified__runtime__v2__main__main_fun35(kk_function_t _fself, int32_t _b_x5, kk_std_core_hnd__ev _b_x6, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__main__new_main_fun35(kk_function_t _b_x4_15, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__main__main_fun35__t* _self = kk_function_alloc_as(struct kk_src_unified__runtime__v2__main__main_fun35__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_src_unified__runtime__v2__main__main_fun35, kk_context());
  _self->_b_x4_15 = _b_x4_15;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__main__main_fun35(kk_function_t _fself, int32_t _b_x5, kk_std_core_hnd__ev _b_x6, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_src_unified__runtime__v2__main__main_fun35__t* _self = kk_function_as(struct kk_src_unified__runtime__v2__main__main_fun35__t*, _fself, _ctx);
  kk_function_t _b_x4_15 = _self->_b_x4_15; /* (m : hnd/marker<<console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>>,()>, hnd/ev<exn>, x : exception) -> <console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>> 10002 */
  kk_drop_match(_self, {kk_function_dup(_b_x4_15, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x36 = kk_std_core_exn__exception_unbox(_b_x7, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x4_15, (_b_x4_15, _b_x5, _b_x6, _x_x36, _ctx), _ctx);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__main__main_fun37__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__main__main_fun37(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__main__new_main_fun37(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__main__main_fun37, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__main__main_fun37(kk_function_t _fself, kk_box_t _b_x11, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_19 = kk_Unit;
  kk_unit_unbox(_b_x11);
  return kk_unit_box(_res_19);
}


// lift anonymous function
struct kk_src_unified__runtime__v2__main__main_fun38__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_unified__runtime__v2__main__main_fun38(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_unified__runtime__v2__main__new_main_fun38(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_unified__runtime__v2__main__main_fun38, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_unified__runtime__v2__main__main_fun38(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x39;
  kk_define_string_literal(, _s_x40, 94, "{\"status\":\"started\",\"unified_runtime\":true,\"version\":\"2.0\",\"imports\":[\"gan_ying\",\"hot_paths\"]}", _ctx)
  _x_x39 = kk_string_dup(_s_x40, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x39, _ctx);
  kk_unit_t _x_x41 = kk_Unit;
  kk_src_unified__runtime__v2__unified_state _x_x42 = kk_src_unified__runtime__v2__new_Unified_state(kk_reuse_null, 0, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), 0x0p+0, _ctx); /*src/unified_runtime_v2/unified-state*/
  kk_src_unified__runtime__v2_server_loop(_x_x42, _ctx);
  return kk_unit_box(_x_x41);
}

kk_unit_t kk_src_unified__runtime__v2__main__main(kk_context_t* _ctx) { /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 
  kk_box_t _x_x24;
  kk_function_t _b_x4_15 = kk_src_unified__runtime__v2__main__new_main_fun25(_ctx); /*(m : hnd/marker<<console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>>,()>, hnd/ev<exn>, x : exception) -> <console/console,alloc<global>,div,fsys,ndet,net,read<global>,ui,write<global>> 10002*/;
  kk_std_core_exn__exn _x_x33;
  kk_std_core_hnd__clause1 _x_x34 = kk_std_core_hnd__new_Clause1(kk_src_unified__runtime__v2__main__new_main_fun35(_b_x4_15, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x33 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x34, _ctx); /*exn<10005,10006>*/
  _x_x24 = kk_std_core_exn_exn_fs__handle(_x_x33, kk_src_unified__runtime__v2__main__new_main_fun37(_ctx), kk_src_unified__runtime__v2__main__new_main_fun38(_ctx), _ctx); /*10002*/
  kk_unit_unbox(_x_x24); return kk_Unit;
}

// initialization
void kk_src_unified__runtime__v2__main__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_undiv__init(_ctx);
  kk_std_text_parse__init(_ctx);
  kk_std_num_int32__init(_ctx);
  kk_std_num_int64__init(_ctx);
  kk_std_os_readline__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_gan__ying__init(_ctx);
  kk_hot__paths__init(_ctx);
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
  kk_src_unified__runtime__v2__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_unified__runtime__v2__main__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_src_unified__runtime__v2__done(_ctx);
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
  kk_hot__paths__done(_ctx);
  kk_gan__ying__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_os_readline__done(_ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_text_parse__done(_ctx);
  kk_std_core_undiv__done(_ctx);
}

// main library entry points
void main_init(kk_context_t* _ctx) {
  kk_src_unified__runtime__v2__main__init(_ctx);
}
void main_run(kk_context_t* _ctx) {
  kk_src_unified__runtime__v2__main__main(_ctx);
}
void main_done(kk_context_t* _ctx) {
  kk_src_unified__runtime__v2__main__done(_ctx);
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
