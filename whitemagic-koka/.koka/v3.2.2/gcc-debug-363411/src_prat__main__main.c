// Koka generated module: src/prat_main/@main, koka version: 3.2.2, platform: 64-bit
#include "src_prat__main__main.h"


// lift anonymous function
struct kk_src_prat__main__main__expr_fun9__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main__main__expr_fun9(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main__main__new_expr_fun9(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main__main__expr_fun9, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main__main__expr_fun9(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x10 = kk_Unit;
  kk_unit_t _x_x11 = kk_Unit;
  kk_unit_unbox(_b_x1);
  kk_src_prat__main__main__mlift_expr_10002(_x_x11, _ctx);
  return kk_unit_box(_x_x10);
}

kk_unit_t kk_src_prat__main__main__expr(kk_context_t* _ctx) { /* () -> io () */ 
  kk_unit_t x_10004 = kk_Unit;
  kk_src_prat__main_server_loop(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x8 = kk_std_core_hnd_yield_extend(kk_src_prat__main__main__new_expr_fun9(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x8); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_src_prat__main__main__main_fun12__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_src_prat__main__main__main_fun12(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main__main__new_main_fun12(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main__main__main_fun12, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_src_prat__main__main__main_fun14__t {
  struct kk_function_s _base;
};
static kk_box_t kk_src_prat__main__main__main_fun14(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx);
static kk_function_t kk_src_prat__main__main__new_main_fun14(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_src_prat__main__main__main_fun14, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_src_prat__main__main__main_fun14(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x15 = kk_Unit;
  kk_unit_t _x_x16 = kk_Unit;
  kk_unit_unbox(_b_x4);
  kk_src_prat__main__main__mlift_main_10003(_x_x16, _ctx);
  return kk_unit_box(_x_x15);
}
static kk_unit_t kk_src_prat__main__main__main_fun12(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t x_10007 = kk_Unit;
  kk_src_prat__main_server_loop(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x13 = kk_std_core_hnd_yield_extend(kk_src_prat__main__main__new_main_fun14(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x13); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}

kk_unit_t kk_src_prat__main__main__main(kk_context_t* _ctx) { /* () -> <st<global>,console/console,div,fsys,ndet,net,ui> () */ 
  kk_std_core__default_exn(kk_src_prat__main__main__new_main_fun12(_ctx), _ctx); return kk_Unit;
}

// initialization
void kk_src_prat__main__main__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_os_readline__init(_ctx);
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
  kk_src_prat__main__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_prat__main__main__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_src_prat__main__done(_ctx);
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
  kk_std_os_readline__done(_ctx);
}

// main library entry points
void main_init(kk_context_t* _ctx) {
  kk_src_prat__main__main__init(_ctx);
}
void main_run(kk_context_t* _ctx) {
  kk_src_prat__main__main__main(_ctx);
}
void main_done(kk_context_t* _ctx) {
  kk_src_prat__main__main__done(_ctx);
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
