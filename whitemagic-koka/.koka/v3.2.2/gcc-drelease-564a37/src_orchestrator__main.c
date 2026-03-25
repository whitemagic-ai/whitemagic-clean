// Koka generated module: src/orchestrator/@main, koka version: 3.2.2, platform: 64-bit
#include "src_orchestrator__main.h"
extern kk_unit_t kk_src_orchestrator__main__main_fun0(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_src_orchestrator_main(_ctx); return kk_Unit;
}

// initialization
void kk_src_orchestrator__main__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_time_timestamp__init(_ctx);
  kk_std_num_decimal__init(_ctx);
  kk_std_os_path__init(_ctx);
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
  kk_std_os_readline__init(_ctx);
  kk_std_os_process__init(_ctx);
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
  kk_src_orchestrator__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_orchestrator__main__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_src_orchestrator__done(_ctx);
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
  kk_std_os_process__done(_ctx);
  kk_std_os_readline__done(_ctx);
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
  kk_std_os_path__done(_ctx);
  kk_std_num_decimal__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
}

// main library entry points
void main_init(kk_context_t* _ctx) {
  kk_src_orchestrator__main__init(_ctx);
}
void main_run(kk_context_t* _ctx) {
  kk_src_orchestrator__main__main(_ctx);
}
void main_done(kk_context_t* _ctx) {
  kk_src_orchestrator__main__done(_ctx);
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
