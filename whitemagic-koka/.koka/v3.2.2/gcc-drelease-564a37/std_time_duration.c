// Koka generated module: std/time/duration, koka version: 3.2.2, platform: 64-bit
#include "std_time_duration.h"
 
// A zero duration.

kk_std_time_duration__duration kk_std_time_duration_zero;

kk_std_time_duration__duration kk_std_time_duration_duration0;
 
// Create a duration from whole seconds `secs` and a fraction of seconds `frac`.

kk_std_time_duration__duration kk_std_time_duration_int_fs_duration(kk_integer_t secs, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (secs : int, frac : ? float64) -> duration */ 
  kk_std_core_types__optional frac_0_10006;
  kk_box_t _x_x102;
  double _x_x103;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x1 = frac._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x103 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x103 = 0x0p+0; /*float64*/
  }
  _x_x102 = kk_double_box(_x_x103, _ctx); /*10003*/
  frac_0_10006 = kk_std_core_types__new_Optional(_x_x102, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x104;
  bool _match_x96;
  double _x_x105;
  if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
    kk_box_t _box_x4 = frac_0_10006._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
    _x_x105 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x105 = 0x0p+0; /*float64*/
  }
  _match_x96 = (_x_x105 == (0x0p+0)); /*bool*/
  if (_match_x96) {
    kk_std_core_types__optional_drop(frac_0_10006, _ctx);
    _x_x104 = kk_std_num_ddouble_ddouble_int_exp(secs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x106 = kk_std_num_ddouble_ddouble_int_exp(secs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x107;
    double _x_x108;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x5 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x5, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x108 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x108 = 0x0p+0; /*float64*/
    }
    _x_x107 = kk_std_num_ddouble__new_Ddouble(_x_x108, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x104 = kk_std_num_ddouble__lp__plus__rp_(_x_x106, _x_x107, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x104, _ctx);
}
 
// Create a `:duration` of `n` seconds.

kk_std_time_duration__duration kk_std_time_duration_int_fs_seconds(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_std_core_types__optional frac_0_10010;
  kk_box_t _x_x109;
  double _x_x110;
  kk_std_core_types__optional _match_x95 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x95, _ctx)) {
    kk_box_t _box_x6 = _match_x95._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x95, _ctx);
    _x_x110 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x95, _ctx);
    _x_x110 = 0x0p+0; /*float64*/
  }
  _x_x109 = kk_double_box(_x_x110, _ctx); /*10003*/
  frac_0_10010 = kk_std_core_types__new_Optional(_x_x109, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x111;
  bool _match_x94;
  double _x_x112;
  if (kk_std_core_types__is_Optional(frac_0_10010, _ctx)) {
    kk_box_t _box_x9 = frac_0_10010._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x9, KK_BORROWED, _ctx);
    _x_x112 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x112 = 0x0p+0; /*float64*/
  }
  _match_x94 = (_x_x112 == (0x0p+0)); /*bool*/
  if (_match_x94) {
    kk_std_core_types__optional_drop(frac_0_10010, _ctx);
    _x_x111 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x113 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x114;
    double _x_x115;
    if (kk_std_core_types__is_Optional(frac_0_10010, _ctx)) {
      kk_box_t _box_x10 = frac_0_10010._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x10, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10010, _ctx);
      _x_x115 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10010, _ctx);
      _x_x115 = 0x0p+0; /*float64*/
    }
    _x_x114 = kk_std_num_ddouble__new_Ddouble(_x_x115, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x111 = kk_std_num_ddouble__lp__plus__rp_(_x_x113, _x_x114, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x111, _ctx);
}
 
// Convert a duration to a `:timespan`.

kk_std_time_timestamp__timestamp kk_std_time_duration_timestamp(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timestamp */ 
  kk_std_num_ddouble__ddouble _x_x116;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x116 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x117;
  kk_integer_t _x_x118;
  kk_std_core_types__optional _match_x93 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x93, _ctx)) {
    kk_box_t _box_x11 = _match_x93._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x11, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x93, _ctx);
    _x_x118 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x93, _ctx);
    _x_x118 = kk_integer_from_small(0); /*int*/
  }
  _x_x117 = kk_integer_clamp32(_x_x118,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x116, _x_x117, _ctx);
}
 
// Return the duration in rounded SI milli-seconds.

kk_integer_t kk_std_time_duration_milli_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x_x119;
  kk_std_num_ddouble__ddouble _x_x120;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x120 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x121;
  bool _match_x90;
  double _x_x122;
  kk_std_core_types__optional _match_x92 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x92, _ctx)) {
    kk_box_t _box_x12 = _match_x92._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x12, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x92, _ctx);
    _x_x122 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x92, _ctx);
    _x_x122 = 0x0p+0; /*float64*/
  }
  _match_x90 = (_x_x122 == (0x0p+0)); /*bool*/
  if (_match_x90) {
    _x_x121 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x123 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x124;
    double _x_x125;
    kk_std_core_types__optional _match_x91 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x91, _ctx)) {
      kk_box_t _box_x13 = _match_x91._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x13, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x91, _ctx);
      _x_x125 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x91, _ctx);
      _x_x125 = 0x0p+0; /*float64*/
    }
    _x_x124 = kk_std_num_ddouble__new_Ddouble(_x_x125, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x121 = kk_std_num_ddouble__lp__plus__rp_(_x_x123, _x_x124, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x_x119 = kk_std_num_ddouble__lp__star__rp_(_x_x120, _x_x121, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_int(_x_x119, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the duration in rounded SI nano-seconds.

kk_integer_t kk_std_time_duration_nano_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x_x126;
  kk_std_num_ddouble__ddouble _x_x127;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x127 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x128;
  bool _match_x87;
  double _x_x129;
  kk_std_core_types__optional _match_x89 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x89, _ctx)) {
    kk_box_t _box_x14 = _match_x89._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x89, _ctx);
    _x_x129 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x89, _ctx);
    _x_x129 = 0x0p+0; /*float64*/
  }
  _match_x87 = (_x_x129 == (0x0p+0)); /*bool*/
  if (_match_x87) {
    _x_x128 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(1000000000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x130 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(1000000000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x131;
    double _x_x132;
    kk_std_core_types__optional _match_x88 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x88, _ctx)) {
      kk_box_t _box_x15 = _match_x88._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x15, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x88, _ctx);
      _x_x132 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x88, _ctx);
      _x_x132 = 0x0p+0; /*float64*/
    }
    _x_x131 = kk_std_num_ddouble__new_Ddouble(_x_x132, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x128 = kk_std_num_ddouble__lp__plus__rp_(_x_x130, _x_x131, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x_x126 = kk_std_num_ddouble__lp__star__rp_(_x_x127, _x_x128, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble_int(_x_x126, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// The fractional seconds of a duration as a `:float64`.
// `d.seconds == d.truncate.fixed + d.fraction.fixed

double kk_std_time_duration_fraction(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> float64 */ 
  kk_std_num_ddouble__ddouble y_10247;
  bool _match_x85;
  double _x_x137;
  {
    kk_std_num_ddouble__ddouble _x_1 = d.secs;
    {
      double _x_0 = _x_1.hi;
      _x_x137 = _x_0; /*float64*/
    }
  }
  _match_x85 = (_x_x137 < (0x0p+0)); /*bool*/
  if (_match_x85) {
    kk_std_num_ddouble__ddouble _x_x138;
    {
      kk_std_num_ddouble__ddouble _x_1_0 = d.secs;
      _x_x138 = _x_1_0; /*std/time/timestamp/timespan*/
    }
    y_10247 = kk_std_num_ddouble_ceiling(_x_x138, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x139;
    {
      kk_std_num_ddouble__ddouble _x_1_1 = d.secs;
      _x_x139 = _x_1_1; /*std/time/timestamp/timespan*/
    }
    y_10247 = kk_std_num_ddouble_floor(_x_x139, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble x_10025;
  kk_std_num_ddouble__ddouble _x_x140;
  {
    kk_std_num_ddouble__ddouble _x_1_2 = d.secs;
    _x_x140 = _x_1_2; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x141;
  double _x_x142;
  double _x_x143;
  {
    double _x_0_0 = y_10247.hi;
    _x_x143 = _x_0_0; /*float64*/
  }
  _x_x142 = (-_x_x143); /*float64*/
  double _x_x144;
  double _x_x145;
  {
    double _x_0_0_0 = y_10247.lo;
    _x_x145 = _x_0_0_0; /*float64*/
  }
  _x_x144 = (-_x_x145); /*float64*/
  _x_x141 = kk_std_num_ddouble__new_Ddouble(_x_x142, _x_x144, _ctx); /*std/num/ddouble/ddouble*/
  x_10025 = kk_std_num_ddouble__lp__plus__rp_(_x_x140, _x_x141, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = x_10025.hi;
    return _x;
  }
}

bool kk_std_time_duration__lp__eq__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_10038;
  kk_std_core_types__order _match_x83;
  double _x_x153;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x153 = _x; /*float64*/
    }
  }
  double _x_x154;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x154 = _x_0; /*float64*/
    }
  }
  _match_x83 = kk_std_num_float64_cmp(_x_x153, _x_x154, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x83, _ctx)) {
    double _x_x155;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x155 = _x_1; /*float64*/
      }
    }
    double _x_x156;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x156 = _x_2; /*float64*/
      }
    }
    x_10038 = kk_std_num_float64_cmp(_x_x155, _x_x156, _ctx); /*order*/
  }
  else {
    x_10038 = _match_x83; /*order*/
  }
  kk_integer_t _brw_x81;
  if (kk_std_core_types__is_Lt(x_10038, _ctx)) {
    _brw_x81 = kk_integer_from_small(-1); /*int*/
    goto _match_x157;
  }
  if (kk_std_core_types__is_Eq(x_10038, _ctx)) {
    _brw_x81 = kk_integer_from_small(0); /*int*/
    goto _match_x157;
  }
  {
    _brw_x81 = kk_integer_from_small(1); /*int*/
  }
  _match_x157: ;
  bool _brw_x82 = kk_integer_eq_borrow(_brw_x81,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x81, _ctx);
  return _brw_x82;
}

bool kk_std_time_duration__lp__lt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_10040;
  kk_std_core_types__order _match_x80;
  double _x_x158;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x158 = _x; /*float64*/
    }
  }
  double _x_x159;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x159 = _x_0; /*float64*/
    }
  }
  _match_x80 = kk_std_num_float64_cmp(_x_x158, _x_x159, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x80, _ctx)) {
    double _x_x160;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x160 = _x_1; /*float64*/
      }
    }
    double _x_x161;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x161 = _x_2; /*float64*/
      }
    }
    x_10040 = kk_std_num_float64_cmp(_x_x160, _x_x161, _ctx); /*order*/
  }
  else {
    x_10040 = _match_x80; /*order*/
  }
  kk_integer_t _brw_x78;
  if (kk_std_core_types__is_Lt(x_10040, _ctx)) {
    _brw_x78 = kk_integer_from_small(-1); /*int*/
    goto _match_x162;
  }
  if (kk_std_core_types__is_Eq(x_10040, _ctx)) {
    _brw_x78 = kk_integer_from_small(0); /*int*/
    goto _match_x162;
  }
  {
    _brw_x78 = kk_integer_from_small(1); /*int*/
  }
  _match_x162: ;
  bool _brw_x79 = kk_integer_eq_borrow(_brw_x78,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x78, _ctx);
  return _brw_x79;
}

bool kk_std_time_duration__lp__excl__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_10042;
  kk_std_core_types__order _match_x77;
  double _x_x163;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x163 = _x; /*float64*/
    }
  }
  double _x_x164;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x164 = _x_0; /*float64*/
    }
  }
  _match_x77 = kk_std_num_float64_cmp(_x_x163, _x_x164, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x77, _ctx)) {
    double _x_x165;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x165 = _x_1; /*float64*/
      }
    }
    double _x_x166;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x166 = _x_2; /*float64*/
      }
    }
    x_10042 = kk_std_num_float64_cmp(_x_x165, _x_x166, _ctx); /*order*/
  }
  else {
    x_10042 = _match_x77; /*order*/
  }
  kk_integer_t _brw_x75;
  if (kk_std_core_types__is_Lt(x_10042, _ctx)) {
    _brw_x75 = kk_integer_from_small(-1); /*int*/
    goto _match_x167;
  }
  if (kk_std_core_types__is_Eq(x_10042, _ctx)) {
    _brw_x75 = kk_integer_from_small(0); /*int*/
    goto _match_x167;
  }
  {
    _brw_x75 = kk_integer_from_small(1); /*int*/
  }
  _match_x167: ;
  bool _brw_x76 = kk_integer_neq_borrow(_brw_x75,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x75, _ctx);
  return _brw_x76;
}

bool kk_std_time_duration__lp__lt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_10044;
  kk_std_core_types__order _match_x74;
  double _x_x168;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x168 = _x; /*float64*/
    }
  }
  double _x_x169;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x169 = _x_0; /*float64*/
    }
  }
  _match_x74 = kk_std_num_float64_cmp(_x_x168, _x_x169, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x74, _ctx)) {
    double _x_x170;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x170 = _x_1; /*float64*/
      }
    }
    double _x_x171;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x171 = _x_2; /*float64*/
      }
    }
    x_10044 = kk_std_num_float64_cmp(_x_x170, _x_x171, _ctx); /*order*/
  }
  else {
    x_10044 = _match_x74; /*order*/
  }
  kk_integer_t _brw_x72;
  if (kk_std_core_types__is_Lt(x_10044, _ctx)) {
    _brw_x72 = kk_integer_from_small(-1); /*int*/
    goto _match_x172;
  }
  if (kk_std_core_types__is_Eq(x_10044, _ctx)) {
    _brw_x72 = kk_integer_from_small(0); /*int*/
    goto _match_x172;
  }
  {
    _brw_x72 = kk_integer_from_small(1); /*int*/
  }
  _match_x172: ;
  bool _brw_x73 = kk_integer_neq_borrow(_brw_x72,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x72, _ctx);
  return _brw_x73;
}

bool kk_std_time_duration__lp__gt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_10046;
  kk_std_core_types__order _match_x71;
  double _x_x173;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x173 = _x; /*float64*/
    }
  }
  double _x_x174;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x174 = _x_0; /*float64*/
    }
  }
  _match_x71 = kk_std_num_float64_cmp(_x_x173, _x_x174, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x71, _ctx)) {
    double _x_x175;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x175 = _x_1; /*float64*/
      }
    }
    double _x_x176;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x176 = _x_2; /*float64*/
      }
    }
    x_10046 = kk_std_num_float64_cmp(_x_x175, _x_x176, _ctx); /*order*/
  }
  else {
    x_10046 = _match_x71; /*order*/
  }
  kk_integer_t _brw_x69;
  if (kk_std_core_types__is_Lt(x_10046, _ctx)) {
    _brw_x69 = kk_integer_from_small(-1); /*int*/
    goto _match_x177;
  }
  if (kk_std_core_types__is_Eq(x_10046, _ctx)) {
    _brw_x69 = kk_integer_from_small(0); /*int*/
    goto _match_x177;
  }
  {
    _brw_x69 = kk_integer_from_small(1); /*int*/
  }
  _match_x177: ;
  bool _brw_x70 = kk_integer_eq_borrow(_brw_x69,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x69, _ctx);
  return _brw_x70;
}

bool kk_std_time_duration__lp__gt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> bool */ 
  kk_std_core_types__order x_10048;
  kk_std_core_types__order _match_x68;
  double _x_x178;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x178 = _x; /*float64*/
    }
  }
  double _x_x179;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x179 = _x_0; /*float64*/
    }
  }
  _match_x68 = kk_std_num_float64_cmp(_x_x178, _x_x179, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x68, _ctx)) {
    double _x_x180;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x180 = _x_1; /*float64*/
      }
    }
    double _x_x181;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x181 = _x_2; /*float64*/
      }
    }
    x_10048 = kk_std_num_float64_cmp(_x_x180, _x_x181, _ctx); /*order*/
  }
  else {
    x_10048 = _match_x68; /*order*/
  }
  kk_integer_t _brw_x66;
  if (kk_std_core_types__is_Lt(x_10048, _ctx)) {
    _brw_x66 = kk_integer_from_small(-1); /*int*/
    goto _match_x182;
  }
  if (kk_std_core_types__is_Eq(x_10048, _ctx)) {
    _brw_x66 = kk_integer_from_small(0); /*int*/
    goto _match_x182;
  }
  {
    _brw_x66 = kk_integer_from_small(1); /*int*/
  }
  _match_x182: ;
  bool _brw_x67 = kk_integer_neq_borrow(_brw_x66,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x66, _ctx);
  return _brw_x67;
}
 
// Subtract a duration from a duration.

kk_std_time_duration__duration kk_std_time_duration__lp__dash__rp_(kk_std_time_duration__duration d, kk_std_time_duration__duration e, kk_context_t* _ctx) { /* (d : duration, e : duration) -> duration */ 
  kk_std_time_duration__duration e_0_10055;
  kk_std_num_ddouble__ddouble _x_x191;
  double _x_x192;
  double _x_x193;
  {
    kk_std_num_ddouble__ddouble _x_1 = e.secs;
    {
      double _x = _x_1.hi;
      _x_x193 = _x; /*float64*/
    }
  }
  _x_x192 = (-_x_x193); /*float64*/
  double _x_x194;
  double _x_x195;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = e.secs;
    {
      double _x_0 = _x_1_0.lo;
      _x_x195 = _x_0; /*float64*/
    }
  }
  _x_x194 = (-_x_x195); /*float64*/
  _x_x191 = kk_std_num_ddouble__new_Ddouble(_x_x192, _x_x194, _ctx); /*std/num/ddouble/ddouble*/
  e_0_10055 = kk_std_time_duration__new_Duration(_x_x191, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x196;
  kk_std_num_ddouble__ddouble _x_x197;
  {
    kk_std_num_ddouble__ddouble _x_2 = d.secs;
    _x_x197 = _x_2; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x198;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = e_0_10055.secs;
    _x_x198 = _x_0_0; /*std/time/timestamp/timespan*/
  }
  _x_x196 = kk_std_num_ddouble__lp__plus__rp_(_x_x197, _x_x198, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x196, _ctx);
}
 
// Show a duration in SI seconds.

kk_string_t kk_std_time_duration_show(kk_std_time_duration__duration d, kk_std_core_types__optional max_prec, kk_context_t* _ctx) { /* (d : duration, max-prec : ? int) -> string */ 
  kk_integer_t _b_x17_18;
  kk_integer_t _x_x199;
  kk_integer_t _x_x200;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x16 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_1391 = kk_integer_unbox(_box_x16, _ctx);
    kk_integer_dup(_uniq_max_prec_1391, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x200 = _uniq_max_prec_1391; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x200 = kk_integer_from_small(9); /*int*/
  }
  _x_x199 = kk_integer_abs(_x_x200,kk_context()); /*int*/
  _b_x17_18 = kk_integer_neg(_x_x199,kk_context()); /*int*/
  kk_string_t _x_x201;
  kk_std_num_ddouble__ddouble _x_x202;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x202 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_core_types__optional _x_x203 = kk_std_core_types__new_Optional(kk_integer_box(_b_x17_18, _ctx), _ctx); /*? 10003*/
  _x_x201 = kk_std_num_ddouble_show_fixed(_x_x202, _x_x203, _ctx); /*string*/
  kk_string_t _x_x204;
  kk_define_string_literal(, _s_x205, 1, "s", _ctx)
  _x_x204 = kk_string_dup(_s_x205, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x201, _x_x204, _ctx);
}
 
// Create a `:duration` of `n` milli-seconds.

kk_std_time_duration__duration kk_std_time_duration_int_fs_milli_seconds(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x206;
  kk_std_num_ddouble__ddouble _x_x207;
  bool _match_x61;
  double _x_x208;
  kk_std_core_types__optional _match_x63 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x63, _ctx)) {
    kk_box_t _box_x19 = _match_x63._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x63, _ctx);
    _x_x208 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x63, _ctx);
    _x_x208 = 0x0p+0; /*float64*/
  }
  _match_x61 = (_x_x208 == (0x0p+0)); /*bool*/
  if (_match_x61) {
    _x_x207 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x209 = kk_std_num_ddouble_ddouble_int_exp(n, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x210;
    double _x_x211;
    kk_std_core_types__optional _match_x62 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x62, _ctx)) {
      kk_box_t _box_x20 = _match_x62._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x20, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x62, _ctx);
      _x_x211 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x62, _ctx);
      _x_x211 = 0x0p+0; /*float64*/
    }
    _x_x210 = kk_std_num_ddouble__new_Ddouble(_x_x211, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x207 = kk_std_num_ddouble__lp__plus__rp_(_x_x209, _x_x210, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x212;
  bool _match_x58;
  double _x_x213;
  kk_std_core_types__optional _match_x60 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x60, _ctx)) {
    kk_box_t _box_x21 = _match_x60._cons._Optional.value;
    double _uniq_frac_1144_1 = kk_double_unbox(_box_x21, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x60, _ctx);
    _x_x213 = _uniq_frac_1144_1; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x60, _ctx);
    _x_x213 = 0x0p+0; /*float64*/
  }
  _match_x58 = (_x_x213 == (0x0p+0)); /*bool*/
  if (_match_x58) {
    _x_x212 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x214 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x215;
    double _x_x216;
    kk_std_core_types__optional _match_x59 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x59, _ctx)) {
      kk_box_t _box_x22 = _match_x59._cons._Optional.value;
      double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x22, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x59, _ctx);
      _x_x216 = _uniq_frac_1144_0_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x59, _ctx);
      _x_x216 = 0x0p+0; /*float64*/
    }
    _x_x215 = kk_std_num_ddouble__new_Ddouble(_x_x216, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x212 = kk_std_num_ddouble__lp__plus__rp_(_x_x214, _x_x215, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x_x206 = kk_std_num_ddouble__lp__fs__rp_(_x_x207, _x_x212, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x206, _ctx);
}
 
// Create a `:duration` of `n` minutes.

kk_std_time_duration__duration kk_std_time_duration_minutes(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10063 = kk_integer_mul(n,(kk_integer_from_small(60)),kk_context()); /*int*/;
  kk_std_core_types__optional frac_0_10066;
  kk_box_t _x_x217;
  double _x_x218;
  kk_std_core_types__optional _match_x57 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x57, _ctx)) {
    kk_box_t _box_x23 = _match_x57._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x23, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x57, _ctx);
    _x_x218 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x57, _ctx);
    _x_x218 = 0x0p+0; /*float64*/
  }
  _x_x217 = kk_double_box(_x_x218, _ctx); /*10003*/
  frac_0_10066 = kk_std_core_types__new_Optional(_x_x217, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x219;
  bool _match_x56;
  double _x_x220;
  if (kk_std_core_types__is_Optional(frac_0_10066, _ctx)) {
    kk_box_t _box_x26 = frac_0_10066._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x26, KK_BORROWED, _ctx);
    _x_x220 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x220 = 0x0p+0; /*float64*/
  }
  _match_x56 = (_x_x220 == (0x0p+0)); /*bool*/
  if (_match_x56) {
    kk_std_core_types__optional_drop(frac_0_10066, _ctx);
    _x_x219 = kk_std_num_ddouble_ddouble_int_exp(secs_10063, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x221 = kk_std_num_ddouble_ddouble_int_exp(secs_10063, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x222;
    double _x_x223;
    if (kk_std_core_types__is_Optional(frac_0_10066, _ctx)) {
      kk_box_t _box_x27 = frac_0_10066._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x27, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10066, _ctx);
      _x_x223 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10066, _ctx);
      _x_x223 = 0x0p+0; /*float64*/
    }
    _x_x222 = kk_std_num_ddouble__new_Ddouble(_x_x223, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x219 = kk_std_num_ddouble__lp__plus__rp_(_x_x221, _x_x222, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x219, _ctx);
}
 
// Create a `:duration` of `n` hours.

kk_std_time_duration__duration kk_std_time_duration_hours(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10067 = kk_integer_mul(n,(kk_integer_from_small(3600)),kk_context()); /*int*/;
  kk_std_core_types__optional frac_0_10070;
  kk_box_t _x_x224;
  double _x_x225;
  kk_std_core_types__optional _match_x55 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x55, _ctx)) {
    kk_box_t _box_x28 = _match_x55._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x28, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x55, _ctx);
    _x_x225 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x55, _ctx);
    _x_x225 = 0x0p+0; /*float64*/
  }
  _x_x224 = kk_double_box(_x_x225, _ctx); /*10003*/
  frac_0_10070 = kk_std_core_types__new_Optional(_x_x224, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x226;
  bool _match_x54;
  double _x_x227;
  if (kk_std_core_types__is_Optional(frac_0_10070, _ctx)) {
    kk_box_t _box_x31 = frac_0_10070._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x31, KK_BORROWED, _ctx);
    _x_x227 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x227 = 0x0p+0; /*float64*/
  }
  _match_x54 = (_x_x227 == (0x0p+0)); /*bool*/
  if (_match_x54) {
    kk_std_core_types__optional_drop(frac_0_10070, _ctx);
    _x_x226 = kk_std_num_ddouble_ddouble_int_exp(secs_10067, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x228 = kk_std_num_ddouble_ddouble_int_exp(secs_10067, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x229;
    double _x_x230;
    if (kk_std_core_types__is_Optional(frac_0_10070, _ctx)) {
      kk_box_t _box_x32 = frac_0_10070._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x32, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10070, _ctx);
      _x_x230 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10070, _ctx);
      _x_x230 = 0x0p+0; /*float64*/
    }
    _x_x229 = kk_std_num_ddouble__new_Ddouble(_x_x230, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x226 = kk_std_num_ddouble__lp__plus__rp_(_x_x228, _x_x229, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x226, _ctx);
}
 
// Create a `:duration` of `n` "days" (assuming 86400s in a day).

kk_std_time_duration__duration kk_std_time_duration_days(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10071 = kk_integer_mul(n,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_core_types__optional frac_0_10074;
  kk_box_t _x_x231;
  double _x_x232;
  kk_std_core_types__optional _match_x53 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x53, _ctx)) {
    kk_box_t _box_x33 = _match_x53._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x33, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x53, _ctx);
    _x_x232 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x53, _ctx);
    _x_x232 = 0x0p+0; /*float64*/
  }
  _x_x231 = kk_double_box(_x_x232, _ctx); /*10003*/
  frac_0_10074 = kk_std_core_types__new_Optional(_x_x231, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x233;
  bool _match_x52;
  double _x_x234;
  if (kk_std_core_types__is_Optional(frac_0_10074, _ctx)) {
    kk_box_t _box_x36 = frac_0_10074._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x36, KK_BORROWED, _ctx);
    _x_x234 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x234 = 0x0p+0; /*float64*/
  }
  _match_x52 = (_x_x234 == (0x0p+0)); /*bool*/
  if (_match_x52) {
    kk_std_core_types__optional_drop(frac_0_10074, _ctx);
    _x_x233 = kk_std_num_ddouble_ddouble_int_exp(secs_10071, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x235 = kk_std_num_ddouble_ddouble_int_exp(secs_10071, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x236;
    double _x_x237;
    if (kk_std_core_types__is_Optional(frac_0_10074, _ctx)) {
      kk_box_t _box_x37 = frac_0_10074._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x37, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10074, _ctx);
      _x_x237 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10074, _ctx);
      _x_x237 = 0x0p+0; /*float64*/
    }
    _x_x236 = kk_std_num_ddouble__new_Ddouble(_x_x237, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x233 = kk_std_num_ddouble__lp__plus__rp_(_x_x235, _x_x236, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x233, _ctx);
}
 
// Create a `:duration` of `n` "weeks" (assuming 7 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_weeks(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10075;
  kk_integer_t _x_x238 = kk_integer_mul(n,(kk_integer_from_small(7)),kk_context()); /*int*/
  secs_10075 = kk_integer_mul(_x_x238,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  kk_std_core_types__optional frac_0_10078;
  kk_box_t _x_x239;
  double _x_x240;
  kk_std_core_types__optional _match_x51 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x51, _ctx)) {
    kk_box_t _box_x38 = _match_x51._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x38, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x51, _ctx);
    _x_x240 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x51, _ctx);
    _x_x240 = 0x0p+0; /*float64*/
  }
  _x_x239 = kk_double_box(_x_x240, _ctx); /*10003*/
  frac_0_10078 = kk_std_core_types__new_Optional(_x_x239, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x241;
  bool _match_x50;
  double _x_x242;
  if (kk_std_core_types__is_Optional(frac_0_10078, _ctx)) {
    kk_box_t _box_x41 = frac_0_10078._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x41, KK_BORROWED, _ctx);
    _x_x242 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x242 = 0x0p+0; /*float64*/
  }
  _match_x50 = (_x_x242 == (0x0p+0)); /*bool*/
  if (_match_x50) {
    kk_std_core_types__optional_drop(frac_0_10078, _ctx);
    _x_x241 = kk_std_num_ddouble_ddouble_int_exp(secs_10075, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x243 = kk_std_num_ddouble_ddouble_int_exp(secs_10075, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x244;
    double _x_x245;
    if (kk_std_core_types__is_Optional(frac_0_10078, _ctx)) {
      kk_box_t _box_x42 = frac_0_10078._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x42, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10078, _ctx);
      _x_x245 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10078, _ctx);
      _x_x245 = 0x0p+0; /*float64*/
    }
    _x_x244 = kk_std_num_ddouble__new_Ddouble(_x_x245, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x241 = kk_std_num_ddouble__lp__plus__rp_(_x_x243, _x_x244, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x241, _ctx);
}
 
// Create a `:duration` of `n` "years" (assuming 365 days of 86400s).

kk_std_time_duration__duration kk_std_time_duration_years(kk_integer_t n, kk_context_t* _ctx) { /* (n : int) -> duration */ 
  kk_integer_t secs_10079;
  kk_integer_t _x_x246 = kk_integer_mul(n,(kk_integer_from_small(365)),kk_context()); /*int*/
  secs_10079 = kk_integer_mul(_x_x246,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  kk_std_core_types__optional frac_0_10082;
  kk_box_t _x_x247;
  double _x_x248;
  kk_std_core_types__optional _match_x49 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x49, _ctx)) {
    kk_box_t _box_x43 = _match_x49._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x43, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x49, _ctx);
    _x_x248 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x49, _ctx);
    _x_x248 = 0x0p+0; /*float64*/
  }
  _x_x247 = kk_double_box(_x_x248, _ctx); /*10003*/
  frac_0_10082 = kk_std_core_types__new_Optional(_x_x247, _ctx); /*? float64*/
  kk_std_num_ddouble__ddouble _x_x249;
  bool _match_x48;
  double _x_x250;
  if (kk_std_core_types__is_Optional(frac_0_10082, _ctx)) {
    kk_box_t _box_x46 = frac_0_10082._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x46, KK_BORROWED, _ctx);
    _x_x250 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x250 = 0x0p+0; /*float64*/
  }
  _match_x48 = (_x_x250 == (0x0p+0)); /*bool*/
  if (_match_x48) {
    kk_std_core_types__optional_drop(frac_0_10082, _ctx);
    _x_x249 = kk_std_num_ddouble_ddouble_int_exp(secs_10079, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x251 = kk_std_num_ddouble_ddouble_int_exp(secs_10079, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x252;
    double _x_x253;
    if (kk_std_core_types__is_Optional(frac_0_10082, _ctx)) {
      kk_box_t _box_x47 = frac_0_10082._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x47, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10082, _ctx);
      _x_x253 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10082, _ctx);
      _x_x253 = 0x0p+0; /*float64*/
    }
    _x_x252 = kk_std_num_ddouble__new_Ddouble(_x_x253, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x249 = kk_std_num_ddouble__lp__plus__rp_(_x_x251, _x_x252, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x249, _ctx);
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
