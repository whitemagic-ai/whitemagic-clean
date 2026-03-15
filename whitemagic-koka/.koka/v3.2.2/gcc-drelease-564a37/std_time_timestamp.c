// Koka generated module: std/time/timestamp, koka version: 3.2.2, platform: 64-bit
#include "std_time_timestamp.h"

kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan0;

kk_integer_t kk_std_time_timestamp_isolar_secs_per_day;

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_fs__copy(kk_std_time_timestamp__timestamp _this, kk_std_core_types__optional since, kk_std_core_types__optional leap32, kk_context_t* _ctx) { /* (timestamp, since : ? timespan, leap32 : ? int32) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x162;
  if (kk_std_core_types__is_Optional(since, _ctx)) {
    kk_box_t _box_x0 = since._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_since_97 = kk_std_num_ddouble__ddouble_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(since, _ctx);
    _x_x162 = _uniq_since_97; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(since, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x163 = kk_std_time_timestamp__as_Timestamp(_this, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x163->since;
      _x_x162 = _x; /*std/time/timestamp/timespan*/
    }
  }
  int32_t _x_x164;
  if (kk_std_core_types__is_Optional(leap32, _ctx)) {
    kk_box_t _box_x1 = leap32._cons._Optional.value;
    int32_t _uniq_leap32_105 = kk_int32_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(leap32, _ctx);
    kk_std_time_timestamp__timestamp_drop(_this, _ctx);
    _x_x164 = _uniq_leap32_105; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(leap32, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x165 = kk_std_time_timestamp__as_Timestamp(_this, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_1 = _con_x165->since;
      int32_t _x_0 = _con_x165->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x164 = _x_0; /*int32*/
    }
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x162, _x_x164, _ctx);
}
 
// Compare two `:timestamp`s.

kk_std_core_types__order kk_std_time_timestamp_cmp(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> order */ 
  kk_std_core_types__order _match_x129;
  kk_std_core_types__order _match_x133;
  double _x_x168;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x169 = kk_std_time_timestamp__as_Timestamp(i, _ctx);
    kk_std_num_ddouble__ddouble _x_3 = _con_x169->since;
    {
      double _x = _x_3.hi;
      _x_x168 = _x; /*float64*/
    }
  }
  double _x_x170;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x171 = kk_std_time_timestamp__as_Timestamp(j, _ctx);
    kk_std_num_ddouble__ddouble _x_4 = _con_x171->since;
    {
      double _x_0 = _x_4.hi;
      _x_x170 = _x_0; /*float64*/
    }
  }
  _match_x133 = kk_std_num_float64_cmp(_x_x168, _x_x170, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x133, _ctx)) {
    double _x_x172;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x173 = kk_std_time_timestamp__as_Timestamp(i, _ctx);
      kk_std_num_ddouble__ddouble _x_3_0 = _con_x173->since;
      {
        double _x_1 = _x_3_0.lo;
        _x_x172 = _x_1; /*float64*/
      }
    }
    double _x_x174;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x175 = kk_std_time_timestamp__as_Timestamp(j, _ctx);
      kk_std_num_ddouble__ddouble _x_4_0 = _con_x175->since;
      {
        double _x_2 = _x_4_0.lo;
        _x_x174 = _x_2; /*float64*/
      }
    }
    _match_x129 = kk_std_num_float64_cmp(_x_x172, _x_x174, _ctx); /*order*/
  }
  else {
    _match_x129 = _match_x133; /*order*/
  }
  if (kk_std_core_types__is_Eq(_match_x129, _ctx)) {
    kk_integer_t x_0_10008;
    int32_t _x_x176;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x177 = kk_std_time_timestamp__as_Timestamp(i, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_6 = _con_x177->since;
      int32_t _x_5 = _con_x177->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
        kk_datatype_ptr_free(i, _ctx);
      }
      else {
        kk_datatype_ptr_decref(i, _ctx);
      }
      _x_x176 = _x_5; /*int32*/
    }
    x_0_10008 = kk_integer_from_int(_x_x176,kk_context()); /*int*/
    kk_integer_t y_0_10009;
    int32_t _x_x178;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x179 = kk_std_time_timestamp__as_Timestamp(j, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_7 = _con_x179->since;
      int32_t _x_6 = _con_x179->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
        kk_datatype_ptr_free(j, _ctx);
      }
      else {
        kk_datatype_ptr_decref(j, _ctx);
      }
      _x_x178 = _x_6; /*int32*/
    }
    y_0_10009 = kk_integer_from_int(_x_x178,kk_context()); /*int*/
    bool _match_x130 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
    if (_match_x130) {
      kk_integer_drop(y_0_10009, _ctx);
      kk_integer_drop(x_0_10008, _ctx);
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      bool _match_x131;
      bool _brw_x132 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      kk_integer_drop(x_0_10008, _ctx);
      kk_integer_drop(y_0_10009, _ctx);
      _match_x131 = _brw_x132; /*bool*/
      if (_match_x131) {
        return kk_std_core_types__new_Gt(_ctx);
      }
      {
        return kk_std_core_types__new_Lt(_ctx);
      }
    }
  }
  {
    kk_std_time_timestamp__timestamp_drop(j, _ctx);
    kk_std_time_timestamp__timestamp_drop(i, _ctx);
    return _match_x129;
  }
}
 
// Add a time span to a time stamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__plus__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (ts : timestamp, t : timespan) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x186;
  kk_std_num_ddouble__ddouble _x_x187;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x188 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x188->since;
    _x_x187 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x186 = kk_std_num_ddouble__lp__plus__rp_(_x_x187, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x189;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x190 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x190->since;
    int32_t _x_0 = _con_x190->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x189 = _x_0; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x186, _x_x189, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_int_fs_timespan(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (seconds : int, frac : ? float64) -> timespan */ 
  bool _match_x116;
  double _x_x191;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x2 = frac._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    _x_x191 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x191 = 0x0p+0; /*float64*/
  }
  _match_x116 = (_x_x191 == (0x0p+0)); /*bool*/
  if (_match_x116) {
    kk_std_core_types__optional_drop(frac, _ctx);
    return kk_std_num_ddouble_ddouble_int_exp(seconds, kk_integer_from_small(0), _ctx);
  }
  {
    kk_std_num_ddouble__ddouble _x_x192 = kk_std_num_ddouble_ddouble_int_exp(seconds, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x193;
    double _x_x194;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x3 = frac._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x194 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x194 = 0x0p+0; /*float64*/
    }
    _x_x193 = kk_std_num_ddouble__new_Ddouble(_x_x194, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x_x192, _x_x193, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_solar_secs_per_day;
 
// The time stamp at 2000-01-01

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp0;
 
// Create a time stamp from a `:timespan` since 2000-01-01 and possible leap seconds.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap_0, kk_context_t* _ctx) { /* (t : timespan, leap : ? int) -> timestamp */ 
  int32_t _x_x199;
  kk_integer_t _x_x200;
  if (kk_std_core_types__is_Optional(leap_0, _ctx)) {
    kk_box_t _box_x6 = leap_0._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x200 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x200 = kk_integer_from_small(0); /*int*/
  }
  _x_x199 = kk_integer_clamp32(_x_x200,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t, _x_x199, _ctx);
}
 
// Create a time stamp from an integer timespan since 2000-01-01 and possible leap seconds.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_int_fs_timestamp(kk_integer_t t, kk_std_core_types__optional frac, kk_std_core_types__optional leap_0, kk_context_t* _ctx) { /* (t : int, frac : ? float64, leap : ? int) -> timestamp */ 
  kk_std_num_ddouble__ddouble t_0_10040;
  kk_std_num_ddouble__ddouble _x_x201 = kk_std_num_ddouble_ddouble_int_exp(t, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x202;
  double _x_x203;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x7 = frac._cons._Optional.value;
    double _uniq_frac_1231 = kk_double_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x203 = _uniq_frac_1231; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x203 = 0x0p+0; /*float64*/
  }
  _x_x202 = kk_std_num_ddouble__new_Ddouble(_x_x203, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  t_0_10040 = kk_std_num_ddouble__lp__plus__rp_(_x_x201, _x_x202, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x204;
  kk_integer_t _x_x205;
  if (kk_std_core_types__is_Optional(leap_0, _ctx)) {
    kk_box_t _box_x8 = leap_0._cons._Optional.value;
    kk_integer_t _uniq_leap_1235 = kk_integer_unbox(_box_x8, _ctx);
    kk_integer_dup(_uniq_leap_1235, _ctx);
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x205 = _uniq_leap_1235; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x205 = kk_integer_from_small(0); /*int*/
  }
  _x_x204 = kk_integer_clamp32(_x_x205,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_0_10040, _x_x204, _ctx);
}
 
// Timestamp from days, seconds into the day and possible leap second.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_days(kk_integer_t days_0, kk_std_core_types__optional secs, kk_std_core_types__optional leap_0, kk_context_t* _ctx) { /* (days : int, secs : ? timespan, leap : ? int) -> timestamp */ 
  kk_integer_t seconds_10046 = kk_integer_mul(days_0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble t_10044;
  kk_std_num_ddouble__ddouble _x_x206;
  bool _match_x109;
  double _x_x207;
  kk_std_core_types__optional _match_x111 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x111, _ctx)) {
    kk_box_t _box_x9 = _match_x111._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x111, _ctx);
    _x_x207 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x111, _ctx);
    _x_x207 = 0x0p+0; /*float64*/
  }
  _match_x109 = (_x_x207 == (0x0p+0)); /*bool*/
  if (_match_x109) {
    _x_x206 = kk_std_num_ddouble_ddouble_int_exp(seconds_10046, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x208 = kk_std_num_ddouble_ddouble_int_exp(seconds_10046, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x209;
    double _x_x210;
    kk_std_core_types__optional _match_x110 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x110, _ctx)) {
      kk_box_t _box_x10 = _match_x110._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x10, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x110, _ctx);
      _x_x210 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x110, _ctx);
      _x_x210 = 0x0p+0; /*float64*/
    }
    _x_x209 = kk_std_num_ddouble__new_Ddouble(_x_x210, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x206 = kk_std_num_ddouble__lp__plus__rp_(_x_x208, _x_x209, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x211;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x11 = secs._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_secs_1270 = kk_std_num_ddouble__ddouble_unbox(_box_x11, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x211 = _uniq_secs_1270; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x211 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
  }
  t_10044 = kk_std_num_ddouble__lp__plus__rp_(_x_x206, _x_x211, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x212;
  kk_integer_t _x_x213;
  if (kk_std_core_types__is_Optional(leap_0, _ctx)) {
    kk_box_t _box_x12 = leap_0._cons._Optional.value;
    kk_integer_t _uniq_leap_1274 = kk_integer_unbox(_box_x12, _ctx);
    kk_integer_dup(_uniq_leap_1274, _ctx);
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x213 = _uniq_leap_1274; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x213 = kk_integer_from_small(0); /*int*/
  }
  _x_x212 = kk_integer_clamp32(_x_x213,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10044, _x_x212, _ctx);
}
 
// Add `days` days to a timestamp

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_days(kk_std_time_timestamp__timestamp ts, kk_integer_t days_0, kk_context_t* _ctx) { /* (ts : timestamp, days : int) -> timestamp */ 
  kk_integer_t seconds_10054 = kk_integer_mul(days_0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble t_10053;
  bool _match_x106;
  double _x_x214;
  kk_std_core_types__optional _match_x108 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x108, _ctx)) {
    kk_box_t _box_x13 = _match_x108._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x13, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x108, _ctx);
    _x_x214 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x108, _ctx);
    _x_x214 = 0x0p+0; /*float64*/
  }
  _match_x106 = (_x_x214 == (0x0p+0)); /*bool*/
  if (_match_x106) {
    t_10053 = kk_std_num_ddouble_ddouble_int_exp(seconds_10054, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x215 = kk_std_num_ddouble_ddouble_int_exp(seconds_10054, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x216;
    double _x_x217;
    kk_std_core_types__optional _match_x107 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x107, _ctx)) {
      kk_box_t _box_x14 = _match_x107._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x14, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x107, _ctx);
      _x_x217 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x107, _ctx);
      _x_x217 = 0x0p+0; /*float64*/
    }
    _x_x216 = kk_std_num_ddouble__new_Ddouble(_x_x217, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_10053 = kk_std_num_ddouble__lp__plus__rp_(_x_x215, _x_x216, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x218;
  kk_std_num_ddouble__ddouble _x_x219;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x220 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x220->since;
    _x_x219 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x218 = kk_std_num_ddouble__lp__plus__rp_(_x_x219, t_10053, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x221;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x222 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x222->since;
    int32_t _x_0 = _con_x222->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x221 = _x_0; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x218, _x_x221, _ctx);
}
 
// Subtract a time span from a time stamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__dash__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (ts : timestamp, t : timespan) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x223;
  kk_std_num_ddouble__ddouble _x_x224;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x225 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x225->since;
    _x_x224 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x226;
  double _x_x227;
  double _x_x228;
  {
    double _x = t.hi;
    _x_x228 = _x; /*float64*/
  }
  _x_x227 = (-_x_x228); /*float64*/
  double _x_x229;
  double _x_x230;
  {
    double _x_0 = t.lo;
    _x_x230 = _x_0; /*float64*/
  }
  _x_x229 = (-_x_x230); /*float64*/
  _x_x226 = kk_std_num_ddouble__new_Ddouble(_x_x227, _x_x229, _ctx); /*std/num/ddouble/ddouble*/
  _x_x223 = kk_std_num_ddouble__lp__plus__rp_(_x_x224, _x_x226, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x231;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x232 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_2 = _con_x232->since;
    int32_t _x_2 = _con_x232->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x231 = _x_2; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x223, _x_x231, _ctx);
}
 
// Return days and seconds into the day, disregarding leap seconds.

kk_std_core_types__tuple2 kk_std_time_timestamp_days_seconds(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> (int, std/num/ddouble/ddouble) */ 
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x_x233;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x234 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x234->since;
    _x_x233 = _x; /*std/time/timestamp/timespan*/
  }
  secs = kk_std_num_ddouble_floor(_x_x233, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x235;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x236 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x236->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x235 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x237;
  double _x_x238;
  double _x_x239;
  {
    double _x_0 = secs.hi;
    _x_x239 = _x_0; /*float64*/
  }
  _x_x238 = (-_x_x239); /*float64*/
  double _x_x240;
  double _x_x241;
  {
    double _x_0_0 = secs.lo;
    _x_x241 = _x_0_0; /*float64*/
  }
  _x_x240 = (-_x_x241); /*float64*/
  _x_x237 = kk_std_num_ddouble__new_Ddouble(_x_x238, _x_x240, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x_x235, _x_x237, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 _match_x105;
  kk_integer_t _x_x242 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_x105 = kk_std_core_int_divmod(_x_x242, kk_integer_from_int(86400, _ctx), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x15 = _match_x105.fst;
    kk_box_t _box_x16 = _match_x105.snd;
    kk_integer_t days_0 = kk_integer_unbox(_box_x15, _ctx);
    kk_integer_t dsecs = kk_integer_unbox(_box_x16, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_integer_dup(dsecs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x105, _ctx);
    kk_std_num_ddouble__ddouble _b_x18_20;
    kk_std_num_ddouble__ddouble _x_x243 = kk_std_num_ddouble_ddouble_int_exp(dsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _b_x18_20 = kk_std_num_ddouble__lp__plus__rp_(_x_x243, frac, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_num_ddouble__ddouble_box(_b_x18_20, _ctx), _ctx);
  }
}
 
// Return days and clock into the day, handling possible leap seconds.

kk_std_core_types__tuple2 kk_std_time_timestamp_days_clock(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> (int, std/time/date/clock) */ 
  kk_std_core_types__tuple2 _match_x101;
  kk_std_time_timestamp__timestamp _x_x244 = kk_std_time_timestamp__timestamp_dup(ts, _ctx); /*std/time/timestamp/timestamp*/
  _match_x101 = kk_std_time_timestamp_days_seconds(_x_x244, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x21 = _match_x101.fst;
    kk_box_t _box_x22 = _match_x101.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x22, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x21, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x101, _ctx);
    kk_integer_t leap_0_10072;
    int32_t _x_x245;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x246 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_1 = _con_x246->since;
      int32_t _x = _con_x246->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
        kk_datatype_ptr_free(ts, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts, _ctx);
      }
      _x_x245 = _x; /*int32*/
    }
    leap_0_10072 = kk_integer_from_int(_x_x245,kk_context()); /*int*/
    kk_integer_t seconds_0_10092;
    kk_std_num_ddouble__ddouble _x_x247 = kk_std_num_ddouble_floor(secs, _ctx); /*std/num/ddouble/ddouble*/
    seconds_0_10092 = kk_std_num_ddouble_int(_x_x247, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
    kk_std_num_ddouble__ddouble _b_x23_24;
    kk_std_num_ddouble__ddouble _x_x248 = kk_std_num_ddouble_ffraction(secs, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x249 = kk_std_num_ddouble_ddouble_int_exp(leap_0_10072, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _b_x23_24 = kk_std_num_ddouble__lp__plus__rp_(_x_x248, _x_x249, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_date__clock _b_x31_33;
    kk_std_core_types__tuple2 _match_x102 = kk_std_core_int_divmod(seconds_0_10092, kk_integer_from_small(60), _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x25 = _match_x102.fst;
      kk_box_t _box_x26 = _match_x102.snd;
      kk_integer_t hm = kk_integer_unbox(_box_x25, _ctx);
      kk_integer_t s = kk_integer_unbox(_box_x26, _ctx);
      kk_integer_dup(hm, _ctx);
      kk_integer_dup(s, _ctx);
      kk_std_core_types__tuple2_drop(_match_x102, _ctx);
      kk_std_core_types__tuple2 _match_x103 = kk_std_core_int_divmod(hm, kk_integer_from_small(60), _ctx); /*(int, int)*/;
      {
        kk_box_t _box_x27 = _match_x103.fst;
        kk_box_t _box_x28 = _match_x103.snd;
        kk_integer_t h = kk_integer_unbox(_box_x27, _ctx);
        kk_integer_t m = kk_integer_unbox(_box_x28, _ctx);
        kk_integer_dup(h, _ctx);
        kk_integer_dup(m, _ctx);
        kk_std_core_types__tuple2_drop(_match_x103, _ctx);
        kk_std_num_ddouble__ddouble _x_x250;
        kk_std_num_ddouble__ddouble _x_x251 = kk_std_num_ddouble_ddouble_int_exp(s, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _x_x252;
        kk_std_core_types__optional _match_x104 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x23_24, _ctx), _ctx); /*? 0*/;
        if (kk_std_core_types__is_Optional(_match_x104, _ctx)) {
          kk_box_t _box_x29 = _match_x104._cons._Optional.value;
          kk_std_num_ddouble__ddouble _uniq_frac_2896 = kk_std_num_ddouble__ddouble_unbox(_box_x29, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(_match_x104, _ctx);
          _x_x252 = _uniq_frac_2896; /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x104, _ctx);
          _x_x252 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
        }
        _x_x250 = kk_std_num_ddouble__lp__plus__rp_(_x_x251, _x_x252, _ctx); /*std/num/ddouble/ddouble*/
        _b_x31_33 = kk_std_time_date__new_Clock(kk_reuse_null, 0, h, m, _x_x250, _ctx); /*std/time/date/clock*/
      }
    }
    return kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_time_date__clock_box(_b_x31_33, _ctx), _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_seconds_into_day(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> std/num/ddouble/ddouble */ 
  kk_std_core_types__tuple2 tuple2_10076;
  kk_std_time_timestamp__timestamp _x_x253 = kk_std_time_timestamp__timestamp_dup(ts, _ctx); /*std/time/timestamp/timestamp*/
  tuple2_10076 = kk_std_time_timestamp_days_seconds(_x_x253, _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_integer_t i_10077;
  int32_t _x_x254;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x255 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x255->since;
    int32_t _x_0 = _con_x255->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x254 = _x_0; /*int32*/
  }
  i_10077 = kk_integer_from_int(_x_x254,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x256;
  {
    kk_box_t _box_x36 = tuple2_10076.fst;
    kk_box_t _box_x37 = tuple2_10076.snd;
    kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x37, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10076, _ctx);
    _x_x256 = _x; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x257 = kk_std_num_ddouble_ddouble_int_exp(i_10077, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x_x256, _x_x257, _ctx);
}
 
// The time span since 2000-01-01 including time inside a possible leap second.

kk_std_num_ddouble__ddouble kk_std_time_timestamp_unsafe_timespan_withleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> timespan */ 
  kk_integer_t seconds_10081;
  int32_t _x_x258;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x259 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_1 = _con_x259->since;
    int32_t _x_0 = _con_x259->leap32;
    _x_x258 = _x_0; /*int32*/
  }
  seconds_10081 = kk_integer_from_int(_x_x258,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x260;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x261 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x261->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x260 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x262;
  bool _match_x98;
  double _x_x263;
  kk_std_core_types__optional _match_x100 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x100, _ctx)) {
    kk_box_t _box_x38 = _match_x100._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x38, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x100, _ctx);
    _x_x263 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x100, _ctx);
    _x_x263 = 0x0p+0; /*float64*/
  }
  _match_x98 = (_x_x263 == (0x0p+0)); /*bool*/
  if (_match_x98) {
    _x_x262 = kk_std_num_ddouble_ddouble_int_exp(seconds_10081, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x264 = kk_std_num_ddouble_ddouble_int_exp(seconds_10081, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x265;
    double _x_x266;
    kk_std_core_types__optional _match_x99 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x99, _ctx)) {
      kk_box_t _box_x39 = _match_x99._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x39, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x99, _ctx);
      _x_x266 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x99, _ctx);
      _x_x266 = 0x0p+0; /*float64*/
    }
    _x_x265 = kk_std_num_ddouble__new_Ddouble(_x_x266, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x262 = kk_std_num_ddouble__lp__plus__rp_(_x_x264, _x_x265, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(_x_x260, _x_x262, _ctx);
}
 
// Round a time stamp to a certain precision (`prec` is number of digits of the fraction of the second).

kk_std_time_timestamp__timestamp kk_std_time_timestamp_round_to_prec(kk_std_time_timestamp__timestamp t, kk_integer_t prec, kk_context_t* _ctx) { /* (t : timestamp, prec : int) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x268;
  bool _match_x96 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x96) {
    kk_integer_drop(prec, _ctx);
    kk_std_num_ddouble__ddouble _x_x269;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x270 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x270->since;
      _x_x269 = _x; /*std/time/timestamp/timespan*/
    }
    _x_x268 = kk_std_num_ddouble_round(_x_x269, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_x97 = kk_integer_gt_borrow(prec,(kk_integer_from_small(31)),kk_context()); /*bool*/;
    if (_match_x97) {
      kk_integer_drop(prec, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x271 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
        kk_std_num_ddouble__ddouble _x_0 = _con_x271->since;
        _x_x268 = _x_0; /*std/num/ddouble/ddouble*/
      }
    }
    else {
      kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, prec, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble _x_x272;
      kk_std_num_ddouble__ddouble _x_x273;
      kk_std_num_ddouble__ddouble _x_x274;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x275 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
        kk_std_num_ddouble__ddouble _x_1 = _con_x275->since;
        _x_x274 = _x_1; /*std/time/timestamp/timespan*/
      }
      _x_x273 = kk_std_num_ddouble__lp__star__rp_(_x_x274, p, _ctx); /*std/num/ddouble/ddouble*/
      _x_x272 = kk_std_num_ddouble_round(_x_x273, _ctx); /*std/num/ddouble/ddouble*/
      _x_x268 = kk_std_num_ddouble__lp__fs__rp_(_x_x272, p, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  int32_t _x_x276;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x277 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_1 = _con_x277->since;
    int32_t _x_0_0 = _con_x277->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x276 = _x_0_0; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x268, _x_x276, _ctx);
}
 
// Add `leaps` leap seconds to the timestamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_leap_seconds(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble leaps, kk_context_t* _ctx) { /* (ts : timestamp, leaps : timespan) -> timestamp */ 
  bool b_10094;
  double _x_x278;
  {
    double _x = leaps.hi;
    _x_x278 = _x; /*float64*/
  }
  b_10094 = (_x_x278 > (0x0p+0)); /*bool*/
  if (b_10094) {
    kk_std_num_ddouble__ddouble y_10097;
    bool _match_x93;
    double _x_x279;
    kk_std_core_types__optional _match_x95 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x95, _ctx)) {
      kk_box_t _box_x40 = _match_x95._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x40, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x95, _ctx);
      _x_x279 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x95, _ctx);
      _x_x279 = 0x0p+0; /*float64*/
    }
    _match_x93 = (_x_x279 == (0x0p+0)); /*bool*/
    if (_match_x93) {
      y_10097 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x280 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x281;
      double _x_x282;
      kk_std_core_types__optional _match_x94 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x94, _ctx)) {
        kk_box_t _box_x41 = _match_x94._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x41, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x94, _ctx);
        _x_x282 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x94, _ctx);
        _x_x282 = 0x0p+0; /*float64*/
      }
      _x_x281 = kk_std_num_ddouble__new_Ddouble(_x_x282, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      y_10097 = kk_std_num_ddouble__lp__plus__rp_(_x_x280, _x_x281, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_core_types__order x_0_10190;
    kk_std_core_types__order _match_x92;
    double _x_x283;
    {
      double _x_0 = leaps.hi;
      _x_x283 = _x_0; /*float64*/
    }
    double _x_x284;
    {
      double _x_0_0 = y_10097.hi;
      _x_x284 = _x_0_0; /*float64*/
    }
    _match_x92 = kk_std_num_float64_cmp(_x_x283, _x_x284, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x92, _ctx)) {
      double _x_x285;
      {
        double _x_1 = leaps.lo;
        _x_x285 = _x_1; /*float64*/
      }
      double _x_x286;
      {
        double _x_2 = y_10097.lo;
        _x_x286 = _x_2; /*float64*/
      }
      x_0_10190 = kk_std_num_float64_cmp(_x_x285, _x_x286, _ctx); /*order*/
    }
    else {
      x_0_10190 = _match_x92; /*order*/
    }
    bool _match_x81;
    kk_integer_t _brw_x90;
    if (kk_std_core_types__is_Lt(x_0_10190, _ctx)) {
      _brw_x90 = kk_integer_from_small(-1); /*int*/
      goto _match_x287;
    }
    if (kk_std_core_types__is_Eq(x_0_10190, _ctx)) {
      _brw_x90 = kk_integer_from_small(0); /*int*/
      goto _match_x287;
    }
    {
      _brw_x90 = kk_integer_from_small(1); /*int*/
    }
    _match_x287: ;
    bool _brw_x91 = kk_integer_eq_borrow(_brw_x90,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x90, _ctx);
    _match_x81 = _brw_x91; /*bool*/
    if (_match_x81) {
      bool _match_x83;
      kk_integer_t _brw_x88;
      int32_t _x_x288;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x289 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_5 = _con_x289->since;
        int32_t _x_3 = _con_x289->leap32;
        _x_x288 = _x_3; /*int32*/
      }
      _brw_x88 = kk_integer_from_int(_x_x288,kk_context()); /*int*/
      bool _brw_x89 = kk_integer_is_zero_borrow(_brw_x88); /*bool*/;
      kk_integer_drop(_brw_x88, _ctx);
      _match_x83 = _brw_x89; /*bool*/
      if (_match_x83) {
        kk_std_num_ddouble__ddouble y_0_10107;
        bool _match_x85;
        double _x_x290;
        kk_std_core_types__optional _match_x87 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x87, _ctx)) {
          kk_box_t _box_x42 = _match_x87._cons._Optional.value;
          double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x42, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(_match_x87, _ctx);
          _x_x290 = _uniq_frac_1144_0_0; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x87, _ctx);
          _x_x290 = 0x0p+0; /*float64*/
        }
        _match_x85 = (_x_x290 == (0x0p+0)); /*bool*/
        if (_match_x85) {
          y_0_10107 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_num_ddouble__ddouble _x_x291 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x292;
          double _x_x293;
          kk_std_core_types__optional _match_x86 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x86, _ctx)) {
            kk_box_t _box_x43 = _match_x86._cons._Optional.value;
            double _uniq_frac_1144_0_1 = kk_double_unbox(_box_x43, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(_match_x86, _ctx);
            _x_x293 = _uniq_frac_1144_0_1; /*float64*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x86, _ctx);
            _x_x293 = 0x0p+0; /*float64*/
          }
          _x_x292 = kk_std_num_ddouble__new_Ddouble(_x_x293, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          y_0_10107 = kk_std_num_ddouble__lp__plus__rp_(_x_x291, _x_x292, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x_x294;
        kk_std_num_ddouble__ddouble _x_x295;
        kk_std_num_ddouble__ddouble _x_x296;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x297 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
          kk_std_num_ddouble__ddouble _x_5 = _con_x297->since;
          if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
            kk_datatype_ptr_free(ts, _ctx);
          }
          else {
            kk_datatype_ptr_decref(ts, _ctx);
          }
          _x_x296 = _x_5; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x298;
        double _x_x299;
        double _x_x300;
        {
          double _x_4 = y_0_10107.hi;
          _x_x300 = _x_4; /*float64*/
        }
        _x_x299 = (-_x_x300); /*float64*/
        double _x_x301;
        double _x_x302;
        {
          double _x_0_1 = y_0_10107.lo;
          _x_x302 = _x_0_1; /*float64*/
        }
        _x_x301 = (-_x_x302); /*float64*/
        _x_x298 = kk_std_num_ddouble__new_Ddouble(_x_x299, _x_x301, _ctx); /*std/num/ddouble/ddouble*/
        _x_x295 = kk_std_num_ddouble__lp__plus__rp_(_x_x296, _x_x298, _ctx); /*std/num/ddouble/ddouble*/
        _x_x294 = kk_std_num_ddouble__lp__plus__rp_(_x_x295, leaps, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x294, (KK_I32(1)), _ctx);
      }
      {
        kk_std_num_ddouble__ddouble _x_x303;
        kk_std_num_ddouble__ddouble _x_x304;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x305 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
          kk_std_num_ddouble__ddouble _x_6 = _con_x305->since;
          _x_x304 = _x_6; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x306 = kk_std_num_ddouble_fraction(leaps, _ctx); /*std/num/ddouble/ddouble*/
        _x_x303 = kk_std_num_ddouble__lp__plus__rp_(_x_x304, _x_x306, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x307;
        int32_t _x_x308;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x309 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_10 = _con_x309->since;
          int32_t _x_7 = _con_x309->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
            kk_datatype_ptr_free(ts, _ctx);
          }
          else {
            kk_datatype_ptr_decref(ts, _ctx);
          }
          _x_x308 = _x_7; /*int32*/
        }
        int32_t _x_x310;
        kk_integer_t _x_x311;
        kk_std_num_ddouble__ddouble _x_x312;
        bool _match_x84;
        double _x_x313;
        {
          double _x_8 = leaps.hi;
          _x_x313 = _x_8; /*float64*/
        }
        _match_x84 = (_x_x313 < (0x0p+0)); /*bool*/
        if (_match_x84) {
          _x_x312 = kk_std_num_ddouble_ceiling(leaps, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          _x_x312 = kk_std_num_ddouble_floor(leaps, _ctx); /*std/num/ddouble/ddouble*/
        }
        _x_x311 = kk_std_num_ddouble_int(_x_x312, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
        _x_x310 = kk_integer_clamp32(_x_x311,kk_context()); /*int32*/
        _x_x307 = (int32_t)((uint32_t)_x_x308 + (uint32_t)_x_x310); /*int32*/
        return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x303, _x_x307, _ctx);
      }
    }
    {
      kk_std_num_ddouble__ddouble _x_x314;
      kk_std_num_ddouble__ddouble _x_x315;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x316 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
        kk_std_num_ddouble__ddouble _x_9 = _con_x316->since;
        _x_x315 = _x_9; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x317 = kk_std_num_ddouble_fraction(leaps, _ctx); /*std/num/ddouble/ddouble*/
      _x_x314 = kk_std_num_ddouble__lp__plus__rp_(_x_x315, _x_x317, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x318;
      int32_t _x_x319;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x320 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_13 = _con_x320->since;
        int32_t _x_10 = _con_x320->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
          kk_datatype_ptr_free(ts, _ctx);
        }
        else {
          kk_datatype_ptr_decref(ts, _ctx);
        }
        _x_x319 = _x_10; /*int32*/
      }
      int32_t _x_x321;
      kk_integer_t _x_x322;
      kk_std_num_ddouble__ddouble _x_x323;
      bool _match_x82;
      double _x_x324;
      {
        double _x_11 = leaps.hi;
        _x_x324 = _x_11; /*float64*/
      }
      _match_x82 = (_x_x324 < (0x0p+0)); /*bool*/
      if (_match_x82) {
        _x_x323 = kk_std_num_ddouble_ceiling(leaps, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        _x_x323 = kk_std_num_ddouble_floor(leaps, _ctx); /*std/num/ddouble/ddouble*/
      }
      _x_x322 = kk_std_num_ddouble_int(_x_x323, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
      _x_x321 = kk_integer_clamp32(_x_x322,kk_context()); /*int32*/
      _x_x318 = (int32_t)((uint32_t)_x_x319 + (uint32_t)_x_x321); /*int32*/
      return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x314, _x_x318, _ctx);
    }
  }
  {
    return ts;
  }
}
 
// The minimum of two timestamps.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_min(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> timestamp */ 
  kk_std_core_types__order x_10020;
  kk_std_time_timestamp__timestamp _x_x325 = kk_std_time_timestamp__timestamp_dup(i, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x326 = kk_std_time_timestamp__timestamp_dup(j, _ctx); /*std/time/timestamp/timestamp*/
  x_10020 = kk_std_time_timestamp_cmp(_x_x325, _x_x326, _ctx); /*order*/
  bool _match_x78;
  kk_integer_t _brw_x79;
  if (kk_std_core_types__is_Lt(x_10020, _ctx)) {
    _brw_x79 = kk_integer_from_small(-1); /*int*/
    goto _match_x327;
  }
  if (kk_std_core_types__is_Eq(x_10020, _ctx)) {
    _brw_x79 = kk_integer_from_small(0); /*int*/
    goto _match_x327;
  }
  {
    _brw_x79 = kk_integer_from_small(1); /*int*/
  }
  _match_x327: ;
  bool _brw_x80 = kk_integer_neq_borrow(_brw_x79,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x79, _ctx);
  _match_x78 = _brw_x80; /*bool*/
  if (_match_x78) {
    kk_std_time_timestamp__timestamp_drop(j, _ctx);
    return i;
  }
  {
    kk_std_time_timestamp__timestamp_drop(i, _ctx);
    return j;
  }
}
 
// The maximum of two timestamps.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_max(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> timestamp */ 
  kk_std_core_types__order x_10024;
  kk_std_time_timestamp__timestamp _x_x328 = kk_std_time_timestamp__timestamp_dup(i, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x329 = kk_std_time_timestamp__timestamp_dup(j, _ctx); /*std/time/timestamp/timestamp*/
  x_10024 = kk_std_time_timestamp_cmp(_x_x328, _x_x329, _ctx); /*order*/
  bool _match_x75;
  kk_integer_t _brw_x76;
  if (kk_std_core_types__is_Lt(x_10024, _ctx)) {
    _brw_x76 = kk_integer_from_small(-1); /*int*/
    goto _match_x330;
  }
  if (kk_std_core_types__is_Eq(x_10024, _ctx)) {
    _brw_x76 = kk_integer_from_small(0); /*int*/
    goto _match_x330;
  }
  {
    _brw_x76 = kk_integer_from_small(1); /*int*/
  }
  _match_x330: ;
  bool _brw_x77 = kk_integer_neq_borrow(_brw_x76,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x76, _ctx);
  _match_x75 = _brw_x77; /*bool*/
  if (_match_x75) {
    kk_std_time_timestamp__timestamp_drop(j, _ctx);
    return i;
  }
  {
    kk_std_time_timestamp__timestamp_drop(i, _ctx);
    return j;
  }
}
 
// Show a time stamp.

kk_string_t kk_std_time_timestamp_ts_show(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (ts : timestamp, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_string_t l;
  bool _match_x72;
  kk_integer_t _brw_x73;
  int32_t _x_x331;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x332 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0 = _con_x332->since;
    int32_t _x = _con_x332->leap32;
    _x_x331 = _x; /*int32*/
  }
  _brw_x73 = kk_integer_from_int(_x_x331,kk_context()); /*int*/
  bool _brw_x74 = kk_integer_is_zero_borrow(_brw_x73); /*bool*/;
  kk_integer_drop(_brw_x73, _ctx);
  _match_x72 = _brw_x74; /*bool*/
  if (_match_x72) {
    l = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x334;
    kk_define_string_literal(, _s_x335, 3, " (+", _ctx)
    _x_x334 = kk_string_dup(_s_x335, _ctx); /*string*/
    kk_string_t _x_x336;
    kk_string_t _x_x337;
    kk_integer_t _x_x338;
    int32_t _x_x339;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x340 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x340->since;
      int32_t _x_0 = _con_x340->leap32;
      _x_x339 = _x_0; /*int32*/
    }
    _x_x338 = kk_integer_from_int(_x_x339,kk_context()); /*int*/
    _x_x337 = kk_std_core_int_show(_x_x338, _ctx); /*string*/
    kk_string_t _x_x341;
    kk_define_string_literal(, _s_x342, 6, " leap)", _ctx)
    _x_x341 = kk_string_dup(_s_x342, _ctx); /*string*/
    _x_x336 = kk_std_core_types__lp__plus__plus__rp_(_x_x337, _x_x341, _ctx); /*string*/
    l = kk_std_core_types__lp__plus__plus__rp_(_x_x334, _x_x336, _ctx); /*string*/
  }
  kk_integer_t _b_x45_50;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x44 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_1871 = kk_integer_unbox(_box_x44, _ctx);
    kk_integer_dup(_uniq_max_prec_1871, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x45_50 = _uniq_max_prec_1871; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x45_50 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x47_51;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x46 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_1875 = kk_integer_unbox(_box_x46, _ctx);
    kk_integer_dup(_uniq_secs_width_1875, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x47_51 = _uniq_secs_width_1875; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x47_51 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _b_x49_52;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x48 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_1879 = kk_string_unbox(_box_x48);
    kk_string_dup(_uniq_unit_1879, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x49_52 = _uniq_unit_1879; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x49_52 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x344;
  kk_std_num_ddouble__ddouble _x_x345;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x346 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x346->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x345 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_core_types__optional _x_x347 = kk_std_core_types__new_Optional(kk_integer_box(_b_x45_50, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x348 = kk_std_core_types__new_Optional(kk_integer_box(_b_x47_51, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x349 = kk_std_core_types__new_Optional(kk_string_box(_b_x49_52), _ctx); /*? 10003*/
  _x_x344 = kk_std_time_date_show_seconds(_x_x345, _x_x347, _x_x348, _x_x349, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x344, l, _ctx);
}
 
// Show a day stamp

kk_string_t kk_std_time_timestamp_ts_show_days(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (ts : timestamp, prec : ? int) -> string */ 
  kk_std_core_types__tuple2 _match_x66;
  kk_std_time_timestamp__timestamp _x_x350 = kk_std_time_timestamp__timestamp_dup(ts, _ctx); /*std/time/timestamp/timestamp*/
  _match_x66 = kk_std_time_timestamp_days_seconds(_x_x350, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x53 = _match_x66.fst;
    kk_box_t _box_x54 = _match_x66.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x54, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x53, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x66, _ctx);
    kk_integer_t _b_x55_56;
    int32_t _x_x351;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x352 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x352->since;
      int32_t _x = _con_x352->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
        kk_datatype_ptr_free(ts, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts, _ctx);
      }
      _x_x351 = _x; /*int32*/
    }
    _b_x55_56 = kk_integer_from_int(_x_x351,kk_context()); /*int*/
    kk_std_time_timestamp__timestamp _arg_x2159;
    int32_t _x_x353;
    kk_integer_t _x_x354;
    kk_std_core_types__optional _match_x71 = kk_std_core_types__new_Optional(kk_integer_box(_b_x55_56, _ctx), _ctx); /*? 10003*/;
    if (kk_std_core_types__is_Optional(_match_x71, _ctx)) {
      kk_box_t _box_x57 = _match_x71._cons._Optional.value;
      kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x57, _ctx);
      kk_integer_dup(_uniq_leap_1214, _ctx);
      kk_std_core_types__optional_drop(_match_x71, _ctx);
      _x_x354 = _uniq_leap_1214; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x71, _ctx);
      _x_x354 = kk_integer_from_small(0); /*int*/
    }
    _x_x353 = kk_integer_clamp32(_x_x354,kk_context()); /*int32*/
    _arg_x2159 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, secs, _x_x353, _ctx); /*std/time/timestamp/timestamp*/
    kk_string_t l;
    bool _match_x68;
    kk_integer_t _brw_x69;
    int32_t _x_x355;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x356 = kk_std_time_timestamp__as_Timestamp(_arg_x2159, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_1 = _con_x356->since;
      int32_t _x_0 = _con_x356->leap32;
      _x_x355 = _x_0; /*int32*/
    }
    _brw_x69 = kk_integer_from_int(_x_x355,kk_context()); /*int*/
    bool _brw_x70 = kk_integer_is_zero_borrow(_brw_x69); /*bool*/;
    kk_integer_drop(_brw_x69, _ctx);
    _match_x68 = _brw_x70; /*bool*/
    if (_match_x68) {
      l = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x358;
      kk_define_string_literal(, _s_x359, 3, " (+", _ctx)
      _x_x358 = kk_string_dup(_s_x359, _ctx); /*string*/
      kk_string_t _x_x360;
      kk_string_t _x_x361;
      kk_integer_t _x_x362;
      int32_t _x_x363;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x364 = kk_std_time_timestamp__as_Timestamp(_arg_x2159, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_2 = _con_x364->since;
        int32_t _x_1 = _con_x364->leap32;
        _x_x363 = _x_1; /*int32*/
      }
      _x_x362 = kk_integer_from_int(_x_x363,kk_context()); /*int*/
      _x_x361 = kk_std_core_int_show(_x_x362, _ctx); /*string*/
      kk_string_t _x_x365;
      kk_define_string_literal(, _s_x366, 6, " leap)", _ctx)
      _x_x365 = kk_string_dup(_s_x366, _ctx); /*string*/
      _x_x360 = kk_std_core_types__lp__plus__plus__rp_(_x_x361, _x_x365, _ctx); /*string*/
      l = kk_std_core_types__lp__plus__plus__rp_(_x_x358, _x_x360, _ctx); /*string*/
    }
    kk_string_t _x_x367 = kk_std_core_int_show(days_0, _ctx); /*string*/
    kk_string_t _x_x368;
    kk_string_t _x_x369;
    kk_define_string_literal(, _s_x370, 2, "d ", _ctx)
    _x_x369 = kk_string_dup(_s_x370, _ctx); /*string*/
    kk_string_t _x_x371;
    kk_integer_t _b_x59_63;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x58 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_2026 = kk_integer_unbox(_box_x58, _ctx);
      kk_integer_dup(_uniq_prec_2026, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x59_63 = _uniq_prec_2026; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x59_63 = kk_integer_from_small(9); /*int*/
    }
    kk_integer_t _b_x61_64;
    kk_std_core_types__optional _match_x67 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x67, _ctx)) {
      kk_box_t _box_x60 = _match_x67._cons._Optional.value;
      kk_integer_t _uniq_secs_width_1875 = kk_integer_unbox(_box_x60, _ctx);
      kk_integer_dup(_uniq_secs_width_1875, _ctx);
      kk_std_core_types__optional_drop(_match_x67, _ctx);
      _b_x61_64 = _uniq_secs_width_1875; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x67, _ctx);
      _b_x61_64 = kk_integer_from_small(1); /*int*/
    }
    kk_string_t _b_x62_65;
    kk_define_string_literal(, _s_x372, 1, "s", _ctx)
    _b_x62_65 = kk_string_dup(_s_x372, _ctx); /*string*/
    kk_string_t _x_x373;
    kk_std_num_ddouble__ddouble _x_x374;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x375 = kk_std_time_timestamp__as_Timestamp(_arg_x2159, _ctx);
      kk_std_num_ddouble__ddouble _x_2 = _con_x375->since;
      if kk_likely(kk_datatype_ptr_is_unique(_arg_x2159, _ctx)) {
        kk_datatype_ptr_free(_arg_x2159, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_arg_x2159, _ctx);
      }
      _x_x374 = _x_2; /*std/time/timestamp/timespan*/
    }
    kk_std_core_types__optional _x_x376 = kk_std_core_types__new_Optional(kk_integer_box(_b_x59_63, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x377 = kk_std_core_types__new_Optional(kk_integer_box(_b_x61_64, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x378 = kk_std_core_types__new_Optional(kk_string_box(_b_x62_65), _ctx); /*? 10003*/
    _x_x373 = kk_std_time_date_show_seconds(_x_x374, _x_x376, _x_x377, _x_x378, _ctx); /*string*/
    _x_x371 = kk_std_core_types__lp__plus__plus__rp_(_x_x373, l, _ctx); /*string*/
    _x_x368 = kk_std_core_types__lp__plus__plus__rp_(_x_x369, _x_x371, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x367, _x_x368, _ctx);
  }
}

// initialization
void kk_std_time_timestamp__init(kk_context_t* _ctx){
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
  kk_std_num_float64__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_num_int32__init(_ctx);
  kk_std_time_date__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_time_timestamp_timespan0 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_timestamp_isolar_secs_per_day = kk_integer_from_int(86400, _ctx); /*int*/
  }
  {
    bool _match_x112;
    double _x_x195;
    kk_std_core_types__optional _match_x114 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x114, _ctx)) {
      kk_box_t _box_x4 = _match_x114._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x114, _ctx);
      _x_x195 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x114, _ctx);
      _x_x195 = 0x0p+0; /*float64*/
    }
    _match_x112 = (_x_x195 == (0x0p+0)); /*bool*/
    if (_match_x112) {
      kk_std_time_timestamp_solar_secs_per_day = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(86400, _ctx), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x196 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(86400, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x197;
      double _x_x198;
      kk_std_core_types__optional _match_x113 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x113, _ctx)) {
        kk_box_t _box_x5 = _match_x113._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x5, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x113, _ctx);
        _x_x198 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x113, _ctx);
        _x_x198 = 0x0p+0; /*float64*/
      }
      _x_x197 = kk_std_num_ddouble__new_Ddouble(_x_x198, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_timestamp_solar_secs_per_day = kk_std_num_ddouble__lp__plus__rp_(_x_x196, _x_x197, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  {
    kk_std_time_timestamp_timestamp0 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, kk_std_num_ddouble_zero, kk_std_num_int32_zero, _ctx); /*std/time/timestamp/timestamp*/
  }
}

// termination
void kk_std_time_timestamp__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_timestamp__timestamp_drop(kk_std_time_timestamp_timestamp0, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_timestamp_solar_secs_per_day, _ctx);
  kk_integer_drop(kk_std_time_timestamp_isolar_secs_per_day, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_timestamp_timespan0, _ctx);
  kk_std_time_date__done(_ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_num_float64__done(_ctx);
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
