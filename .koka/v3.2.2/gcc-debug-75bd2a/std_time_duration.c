// Koka generated module: std/time/duration, koka version: 3.2.2, platform: 64-bit
#include "std_time_duration.h"
 
// A zero duration.

kk_std_time_duration__duration kk_std_time_duration_zero;

kk_std_time_duration__duration kk_std_time_duration_duration0;
 
// Create a duration from whole seconds `secs` and a fraction of seconds `frac`.

kk_std_time_duration__duration kk_std_time_duration_int_fs_duration(kk_integer_t secs, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (secs : int, frac : ? float64) -> duration */ 
  double _b_x2_3;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x1 = frac._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _b_x2_3 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _b_x2_3 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x50;
  kk_std_core_types__optional _x_x51 = kk_std_core_types__new_Optional(kk_double_box(_b_x2_3, _ctx), _ctx); /*? 10003*/
  _x_x50 = kk_std_time_timestamp_int_fs_timespan(secs, _x_x51, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x50, _ctx);
}
 
// Create a `:duration` of `n` seconds.

kk_std_time_duration__duration kk_std_time_duration_int_fs_seconds(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  double _b_x5_6;
  kk_std_core_types__optional _match_x44 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x44, _ctx)) {
    kk_box_t _box_x4 = _match_x44._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x44, _ctx);
    _b_x5_6 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x44, _ctx);
    _b_x5_6 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x52;
  kk_std_core_types__optional _x_x53 = kk_std_core_types__new_Optional(kk_double_box(_b_x5_6, _ctx), _ctx); /*? 10003*/
  _x_x52 = kk_std_time_timestamp_int_fs_timespan(n, _x_x53, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x52, _ctx);
}
 
// Convert a duration to a `:timespan`.

kk_std_time_timestamp__timestamp kk_std_time_duration_timestamp(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timestamp */ 
  kk_std_num_ddouble__ddouble _x_x54;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x54 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x55;
  kk_integer_t _x_x56;
  kk_std_core_types__optional _match_x43 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x43, _ctx)) {
    kk_box_t _box_x7 = _match_x43._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x43, _ctx);
    _x_x56 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x43, _ctx);
    _x_x56 = kk_integer_from_small(0); /*int*/
  }
  _x_x55 = kk_integer_clamp32(_x_x56,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x54, _x_x55, _ctx);
}
 
// Subtract a duration from a duration.

kk_std_time_duration__duration kk_std_time_duration__lp__dash__rp_(kk_std_time_duration__duration d, kk_std_time_duration__duration e, kk_context_t* _ctx) { /* (d : duration, e : duration) -> duration */ 
  kk_std_time_duration__duration e_0_10038;
  kk_std_num_ddouble__ddouble _x_x123;
  double _x_x124;
  double _x_x125;
  {
    kk_std_num_ddouble__ddouble _x_1 = e.secs;
    {
      double _x = _x_1.hi;
      _x_x125 = _x; /*float64*/
    }
  }
  _x_x124 = (-_x_x125); /*float64*/
  double _x_x126;
  double _x_x127;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = e.secs;
    {
      double _x_0 = _x_1_0.lo;
      _x_x127 = _x_0; /*float64*/
    }
  }
  _x_x126 = (-_x_x127); /*float64*/
  _x_x123 = kk_std_num_ddouble__new_Ddouble(_x_x124, _x_x126, _ctx); /*std/num/ddouble/ddouble*/
  e_0_10038 = kk_std_time_duration__new_Duration(_x_x123, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x128;
  kk_std_num_ddouble__ddouble _x_x129;
  {
    kk_std_num_ddouble__ddouble _x_2 = d.secs;
    _x_x129 = _x_2; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x130;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = e_0_10038.secs;
    _x_x130 = _x_0_0; /*std/time/timestamp/timespan*/
  }
  _x_x128 = kk_std_num_ddouble__lp__plus__rp_(_x_x129, _x_x130, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x128, _ctx);
}
 
// Show a duration in SI seconds.

kk_string_t kk_std_time_duration_show(kk_std_time_duration__duration d, kk_std_core_types__optional max_prec, kk_context_t* _ctx) { /* (d : duration, max-prec : ? int) -> string */ 
  kk_integer_t _b_x9_10;
  kk_integer_t _x_x131;
  kk_integer_t _x_x132;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x8 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_1391 = kk_integer_unbox(_box_x8, _ctx);
    kk_integer_dup(_uniq_max_prec_1391, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x132 = _uniq_max_prec_1391; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x132 = kk_integer_from_small(9); /*int*/
  }
  _x_x131 = kk_integer_abs(_x_x132,kk_context()); /*int*/
  _b_x9_10 = kk_integer_neg(_x_x131,kk_context()); /*int*/
  kk_string_t _x_x133;
  kk_std_num_ddouble__ddouble _x_x134;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x134 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_core_types__optional _x_x135 = kk_std_core_types__new_Optional(kk_integer_box(_b_x9_10, _ctx), _ctx); /*? 10003*/
  _x_x133 = kk_std_num_ddouble_show_fixed(_x_x134, _x_x135, _ctx); /*string*/
  kk_string_t _x_x136;
  kk_define_string_literal(, _s_x137, 1, "s", _ctx)
  _x_x136 = kk_string_dup(_s_x137, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x133, _x_x136, _ctx);
}
 
// Create a `:duration` of `n` minutes.

kk_std_time_duration__duration kk_std_time_duration_minutes(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10042 = kk_integer_mul(n,(kk_integer_from_small(60)),kk_context()); /*int*/;
  double _b_x12_13;
  kk_std_core_types__optional _match_x30 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x30, _ctx)) {
    kk_box_t _box_x11 = _match_x30._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x11, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x30, _ctx);
    _b_x12_13 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x30, _ctx);
    _b_x12_13 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x141;
  kk_std_core_types__optional _x_x142 = kk_std_core_types__new_Optional(kk_double_box(_b_x12_13, _ctx), _ctx); /*? 10003*/
  _x_x141 = kk_std_time_timestamp_int_fs_timespan(secs_10042, _x_x142, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x141, _ctx);
}
 
// Create a `:duration` of `n` hours.

kk_std_time_duration__duration kk_std_time_duration_hours(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10044 = kk_integer_mul(n,(kk_integer_from_small(3600)),kk_context()); /*int*/;
  double _b_x15_16;
  kk_std_core_types__optional _match_x29 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x29, _ctx)) {
    kk_box_t _box_x14 = _match_x29._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x29, _ctx);
    _b_x15_16 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x29, _ctx);
    _b_x15_16 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x143;
  kk_std_core_types__optional _x_x144 = kk_std_core_types__new_Optional(kk_double_box(_b_x15_16, _ctx), _ctx); /*? 10003*/
  _x_x143 = kk_std_time_timestamp_int_fs_timespan(secs_10044, _x_x144, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x143, _ctx);
}
 
// Create a `:duration` of `n` "days" (assuming 86400s in a day).

kk_std_time_duration__duration kk_std_time_duration_days(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10046 = kk_integer_mul(n,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  double _b_x18_19;
  kk_std_core_types__optional _match_x28 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x28, _ctx)) {
    kk_box_t _box_x17 = _match_x28._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x17, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x28, _ctx);
    _b_x18_19 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x28, _ctx);
    _b_x18_19 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x145;
  kk_std_core_types__optional _x_x146 = kk_std_core_types__new_Optional(kk_double_box(_b_x18_19, _ctx), _ctx); /*? 10003*/
  _x_x145 = kk_std_time_timestamp_int_fs_timespan(secs_10046, _x_x146, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x145, _ctx);
}
 
// Create a `:duration` of `n` "weeks" (assuming 7 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_weeks(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10048;
  kk_integer_t _x_x147 = kk_integer_mul(n,(kk_integer_from_small(7)),kk_context()); /*int*/
  secs_10048 = kk_integer_mul(_x_x147,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  double _b_x21_22;
  kk_std_core_types__optional _match_x27 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x27, _ctx)) {
    kk_box_t _box_x20 = _match_x27._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x20, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x27, _ctx);
    _b_x21_22 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x27, _ctx);
    _b_x21_22 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x148;
  kk_std_core_types__optional _x_x149 = kk_std_core_types__new_Optional(kk_double_box(_b_x21_22, _ctx), _ctx); /*? 10003*/
  _x_x148 = kk_std_time_timestamp_int_fs_timespan(secs_10048, _x_x149, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x148, _ctx);
}
 
// Create a `:duration` of `n` "years" (assuming 365 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_years(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10050;
  kk_integer_t _x_x150 = kk_integer_mul(n,(kk_integer_from_small(365)),kk_context()); /*int*/
  secs_10050 = kk_integer_mul(_x_x150,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  double _b_x24_25;
  kk_std_core_types__optional _match_x26 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x26, _ctx)) {
    kk_box_t _box_x23 = _match_x26._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x23, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x26, _ctx);
    _b_x24_25 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x26, _ctx);
    _b_x24_25 = 0x0p+0; /*float64*/
  }
  kk_std_num_ddouble__ddouble _x_x151;
  kk_std_core_types__optional _x_x152 = kk_std_core_types__new_Optional(kk_double_box(_b_x24_25, _ctx), _ctx); /*? 10003*/
  _x_x151 = kk_std_time_timestamp_int_fs_timespan(secs_10050, _x_x152, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x151, _ctx);
}

// initialization
void kk_std_time_duration__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
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
  kk_std_core__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int32__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_time_duration_zero = kk_std_time_duration__new_Duration(kk_std_num_ddouble_zero, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_time_duration_duration0 = kk_std_time_duration__new_Duration(kk_std_num_ddouble_zero, _ctx); /*std/time/duration/duration*/
  }
}

// termination
void kk_std_time_duration__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_duration__duration_drop(kk_std_time_duration_duration0, _ctx);
  kk_std_time_duration__duration_drop(kk_std_time_duration_zero, _ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_core__done(_ctx);
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
}
