// Koka generated module: std/time/timestamp, koka version: 3.2.2, platform: 64-bit
#include "std_time_timestamp.h"

kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan0;

kk_integer_t kk_std_time_timestamp_isolar_secs_per_day;

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_fs__copy(kk_std_time_timestamp__timestamp _this, kk_std_core_types__optional since, kk_std_core_types__optional leap32, kk_context_t* _ctx) { /* (timestamp, since : ? timespan, leap32 : ? int32) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x124;
  if (kk_std_core_types__is_Optional(since, _ctx)) {
    kk_box_t _box_x0 = since._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_since_97 = kk_std_num_ddouble__ddouble_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(since, _ctx);
    _x_x124 = _uniq_since_97; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(since, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x125 = kk_std_time_timestamp__as_Timestamp(_this, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x125->since;
      _x_x124 = _x; /*std/time/timestamp/timespan*/
    }
  }
  int32_t _x_x126;
  if (kk_std_core_types__is_Optional(leap32, _ctx)) {
    kk_box_t _box_x1 = leap32._cons._Optional.value;
    int32_t _uniq_leap32_105 = kk_int32_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(leap32, _ctx);
    kk_std_time_timestamp__timestamp_drop(_this, _ctx);
    _x_x126 = _uniq_leap32_105; /*int32*/
  }
  else {
    kk_std_core_types__optional_drop(leap32, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x127 = kk_std_time_timestamp__as_Timestamp(_this, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_1 = _con_x127->since;
      int32_t _x_0 = _con_x127->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x126 = _x_0; /*int32*/
    }
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x124, _x_x126, _ctx);
}
 
// Compare two `:timestamp`s.

kk_std_core_types__order kk_std_time_timestamp_cmp(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> order */ 
  kk_std_core_types__order _match_x92;
  kk_std_core_types__order _match_x96;
  double _x_x130;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x131 = kk_std_time_timestamp__as_Timestamp(i, _ctx);
    kk_std_num_ddouble__ddouble _x_3 = _con_x131->since;
    {
      double _x = _x_3.hi;
      _x_x130 = _x; /*float64*/
    }
  }
  double _x_x132;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x133 = kk_std_time_timestamp__as_Timestamp(j, _ctx);
    kk_std_num_ddouble__ddouble _x_4 = _con_x133->since;
    {
      double _x_0 = _x_4.hi;
      _x_x132 = _x_0; /*float64*/
    }
  }
  _match_x96 = kk_std_num_float64_cmp(_x_x130, _x_x132, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x96, _ctx)) {
    double _x_x134;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x135 = kk_std_time_timestamp__as_Timestamp(i, _ctx);
      kk_std_num_ddouble__ddouble _x_3_0 = _con_x135->since;
      {
        double _x_1 = _x_3_0.lo;
        _x_x134 = _x_1; /*float64*/
      }
    }
    double _x_x136;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x137 = kk_std_time_timestamp__as_Timestamp(j, _ctx);
      kk_std_num_ddouble__ddouble _x_4_0 = _con_x137->since;
      {
        double _x_2 = _x_4_0.lo;
        _x_x136 = _x_2; /*float64*/
      }
    }
    _match_x92 = kk_std_num_float64_cmp(_x_x134, _x_x136, _ctx); /*order*/
  }
  else {
    _match_x92 = _match_x96; /*order*/
  }
  if (kk_std_core_types__is_Eq(_match_x92, _ctx)) {
    kk_integer_t x_0_10008;
    int32_t _x_x138;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x139 = kk_std_time_timestamp__as_Timestamp(i, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_6 = _con_x139->since;
      int32_t _x_5 = _con_x139->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
        kk_datatype_ptr_free(i, _ctx);
      }
      else {
        kk_datatype_ptr_decref(i, _ctx);
      }
      _x_x138 = _x_5; /*int32*/
    }
    x_0_10008 = kk_integer_from_int(_x_x138,kk_context()); /*int*/
    kk_integer_t y_0_10009;
    int32_t _x_x140;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x141 = kk_std_time_timestamp__as_Timestamp(j, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_7 = _con_x141->since;
      int32_t _x_6 = _con_x141->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
        kk_datatype_ptr_free(j, _ctx);
      }
      else {
        kk_datatype_ptr_decref(j, _ctx);
      }
      _x_x140 = _x_6; /*int32*/
    }
    y_0_10009 = kk_integer_from_int(_x_x140,kk_context()); /*int*/
    bool _match_x93 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
    if (_match_x93) {
      kk_integer_drop(y_0_10009, _ctx);
      kk_integer_drop(x_0_10008, _ctx);
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      bool _match_x94;
      bool _brw_x95 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      kk_integer_drop(x_0_10008, _ctx);
      kk_integer_drop(y_0_10009, _ctx);
      _match_x94 = _brw_x95; /*bool*/
      if (_match_x94) {
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
    return _match_x92;
  }
}
 
// Add a time span to a time stamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__plus__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (ts : timestamp, t : timespan) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x148;
  kk_std_num_ddouble__ddouble _x_x149;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x150 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x150->since;
    _x_x149 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x148 = kk_std_num_ddouble__lp__plus__rp_(_x_x149, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x151;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x152 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x152->since;
    int32_t _x_0 = _con_x152->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x151 = _x_0; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x148, _x_x151, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_int_fs_timespan(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx) { /* (seconds : int, frac : ? float64) -> timespan */ 
  bool _match_x91;
  double _x_x153;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x2 = frac._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    _x_x153 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x153 = 0x0p+0; /*float64*/
  }
  _match_x91 = (_x_x153 == (0x0p+0)); /*bool*/
  if (_match_x91) {
    kk_std_core_types__optional_drop(frac, _ctx);
    return kk_std_num_ddouble_ddouble_int_exp(seconds, kk_integer_from_small(0), _ctx);
  }
  {
    kk_std_num_ddouble__ddouble _x_x154 = kk_std_num_ddouble_ddouble_int_exp(seconds, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x155;
    double _x_x156;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x3 = frac._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x156 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x156 = 0x0p+0; /*float64*/
    }
    _x_x155 = kk_std_num_ddouble__new_Ddouble(_x_x156, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x_x154, _x_x155, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_solar_secs_per_day;
 
// The time stamp at 2000-01-01

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp0;
 
// Create a time stamp from a `:timespan` since 2000-01-01 and possible leap seconds.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap_0, kk_context_t* _ctx) { /* (t : timespan, leap : ? int) -> timestamp */ 
  int32_t _x_x161;
  kk_integer_t _x_x162;
  if (kk_std_core_types__is_Optional(leap_0, _ctx)) {
    kk_box_t _box_x6 = leap_0._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x6, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x162 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x162 = kk_integer_from_small(0); /*int*/
  }
  _x_x161 = kk_integer_clamp32(_x_x162,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t, _x_x161, _ctx);
}
 
// Create a time stamp from an integer timespan since 2000-01-01 and possible leap seconds.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_int_fs_timestamp(kk_integer_t t, kk_std_core_types__optional frac, kk_std_core_types__optional leap_0, kk_context_t* _ctx) { /* (t : int, frac : ? float64, leap : ? int) -> timestamp */ 
  kk_std_num_ddouble__ddouble t_0_10022;
  kk_std_num_ddouble__ddouble _x_x163 = kk_std_num_ddouble_ddouble_int_exp(t, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x164;
  double _x_x165;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x7 = frac._cons._Optional.value;
    double _uniq_frac_1231 = kk_double_unbox(_box_x7, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x165 = _uniq_frac_1231; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x165 = 0x0p+0; /*float64*/
  }
  _x_x164 = kk_std_num_ddouble__new_Ddouble(_x_x165, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  t_0_10022 = kk_std_num_ddouble__lp__plus__rp_(_x_x163, _x_x164, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x166;
  kk_integer_t _x_x167;
  if (kk_std_core_types__is_Optional(leap_0, _ctx)) {
    kk_box_t _box_x8 = leap_0._cons._Optional.value;
    kk_integer_t _uniq_leap_1235 = kk_integer_unbox(_box_x8, _ctx);
    kk_integer_dup(_uniq_leap_1235, _ctx);
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x167 = _uniq_leap_1235; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x167 = kk_integer_from_small(0); /*int*/
  }
  _x_x166 = kk_integer_clamp32(_x_x167,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_0_10022, _x_x166, _ctx);
}
 
// Timestamp from days, seconds into the day and possible leap second.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_days(kk_integer_t days_0, kk_std_core_types__optional secs, kk_std_core_types__optional leap_0, kk_context_t* _ctx) { /* (days : int, secs : ? timespan, leap : ? int) -> timestamp */ 
  kk_integer_t seconds_10084 = kk_integer_mul(days_0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble t_10026;
  kk_std_num_ddouble__ddouble _x_x168;
  bool _match_x84;
  double _x_x169;
  kk_std_core_types__optional _match_x86 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x86, _ctx)) {
    kk_box_t _box_x9 = _match_x86._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x86, _ctx);
    _x_x169 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x86, _ctx);
    _x_x169 = 0x0p+0; /*float64*/
  }
  _match_x84 = (_x_x169 == (0x0p+0)); /*bool*/
  if (_match_x84) {
    _x_x168 = kk_std_num_ddouble_ddouble_int_exp(seconds_10084, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x170 = kk_std_num_ddouble_ddouble_int_exp(seconds_10084, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x171;
    double _x_x172;
    kk_std_core_types__optional _match_x85 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x85, _ctx)) {
      kk_box_t _box_x10 = _match_x85._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x10, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x85, _ctx);
      _x_x172 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x85, _ctx);
      _x_x172 = 0x0p+0; /*float64*/
    }
    _x_x171 = kk_std_num_ddouble__new_Ddouble(_x_x172, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x168 = kk_std_num_ddouble__lp__plus__rp_(_x_x170, _x_x171, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x173;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x11 = secs._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_secs_1270 = kk_std_num_ddouble__ddouble_unbox(_box_x11, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x173 = _uniq_secs_1270; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x173 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
  }
  t_10026 = kk_std_num_ddouble__lp__plus__rp_(_x_x168, _x_x173, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x174;
  kk_integer_t _x_x175;
  if (kk_std_core_types__is_Optional(leap_0, _ctx)) {
    kk_box_t _box_x12 = leap_0._cons._Optional.value;
    kk_integer_t _uniq_leap_1274 = kk_integer_unbox(_box_x12, _ctx);
    kk_integer_dup(_uniq_leap_1274, _ctx);
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x175 = _uniq_leap_1274; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0, _ctx);
    _x_x175 = kk_integer_from_small(0); /*int*/
  }
  _x_x174 = kk_integer_clamp32(_x_x175,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10026, _x_x174, _ctx);
}
 
// Add `days` days to a timestamp

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_days(kk_std_time_timestamp__timestamp ts, kk_integer_t days_0, kk_context_t* _ctx) { /* (ts : timestamp, days : int) -> timestamp */ 
  kk_integer_t seconds_10086 = kk_integer_mul(days_0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble t_10029;
  bool _match_x81;
  double _x_x176;
  kk_std_core_types__optional _match_x83 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x83, _ctx)) {
    kk_box_t _box_x13 = _match_x83._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x13, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x83, _ctx);
    _x_x176 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x83, _ctx);
    _x_x176 = 0x0p+0; /*float64*/
  }
  _match_x81 = (_x_x176 == (0x0p+0)); /*bool*/
  if (_match_x81) {
    t_10029 = kk_std_num_ddouble_ddouble_int_exp(seconds_10086, kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x177 = kk_std_num_ddouble_ddouble_int_exp(seconds_10086, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x178;
    double _x_x179;
    kk_std_core_types__optional _match_x82 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x82, _ctx)) {
      kk_box_t _box_x14 = _match_x82._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x14, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x82, _ctx);
      _x_x179 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x82, _ctx);
      _x_x179 = 0x0p+0; /*float64*/
    }
    _x_x178 = kk_std_num_ddouble__new_Ddouble(_x_x179, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_10029 = kk_std_num_ddouble__lp__plus__rp_(_x_x177, _x_x178, _ctx); /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x180;
  kk_std_num_ddouble__ddouble _x_x181;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x182 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x182->since;
    _x_x181 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x180 = kk_std_num_ddouble__lp__plus__rp_(_x_x181, t_10029, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x183;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x184 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x184->since;
    int32_t _x_0 = _con_x184->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x183 = _x_0; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x180, _x_x183, _ctx);
}
 
// Subtract a time span from a time stamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__dash__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (ts : timestamp, t : timespan) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x185;
  kk_std_num_ddouble__ddouble _x_x186;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x187 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x187->since;
    _x_x186 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x188;
  double _x_x189;
  double _x_x190;
  {
    double _x = t.hi;
    _x_x190 = _x; /*float64*/
  }
  _x_x189 = (-_x_x190); /*float64*/
  double _x_x191;
  double _x_x192;
  {
    double _x_0 = t.lo;
    _x_x192 = _x_0; /*float64*/
  }
  _x_x191 = (-_x_x192); /*float64*/
  _x_x188 = kk_std_num_ddouble__new_Ddouble(_x_x189, _x_x191, _ctx); /*std/num/ddouble/ddouble*/
  _x_x185 = kk_std_num_ddouble__lp__plus__rp_(_x_x186, _x_x188, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x193;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x194 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_2 = _con_x194->since;
    int32_t _x_2 = _con_x194->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x193 = _x_2; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x185, _x_x193, _ctx);
}
 
// Return days and seconds into the day, disregarding leap seconds.

kk_std_core_types__tuple2 kk_std_time_timestamp_days_seconds(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> (int, std/num/ddouble/ddouble) */ 
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x_x195;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x196 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x196->since;
    _x_x195 = _x; /*std/time/timestamp/timespan*/
  }
  secs = kk_std_num_ddouble_floor(_x_x195, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x197;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x198 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x198->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x197 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x199;
  double _x_x200;
  double _x_x201;
  {
    double _x_0 = secs.hi;
    _x_x201 = _x_0; /*float64*/
  }
  _x_x200 = (-_x_x201); /*float64*/
  double _x_x202;
  double _x_x203;
  {
    double _x_0_0 = secs.lo;
    _x_x203 = _x_0_0; /*float64*/
  }
  _x_x202 = (-_x_x203); /*float64*/
  _x_x199 = kk_std_num_ddouble__new_Ddouble(_x_x200, _x_x202, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x_x197, _x_x199, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 _match_x80;
  kk_integer_t _x_x204 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_x80 = kk_std_core_int_divmod(_x_x204, kk_integer_from_int(86400, _ctx), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x15 = _match_x80.fst;
    kk_box_t _box_x16 = _match_x80.snd;
    kk_integer_t days_0 = kk_integer_unbox(_box_x15, _ctx);
    kk_integer_t dsecs = kk_integer_unbox(_box_x16, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_integer_dup(dsecs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x80, _ctx);
    kk_std_num_ddouble__ddouble _b_x18_20;
    kk_std_num_ddouble__ddouble _x_x205 = kk_std_num_ddouble_ddouble_int_exp(dsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _b_x18_20 = kk_std_num_ddouble__lp__plus__rp_(_x_x205, frac, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_num_ddouble__ddouble_box(_b_x18_20, _ctx), _ctx);
  }
}
 
// Return days and clock into the day, handling possible leap seconds.

kk_std_core_types__tuple2 kk_std_time_timestamp_days_clock(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> (int, std/time/date/clock) */ 
  kk_std_core_types__tuple2 _match_x79;
  kk_std_time_timestamp__timestamp _x_x206 = kk_std_time_timestamp__timestamp_dup(ts, _ctx); /*std/time/timestamp/timestamp*/
  _match_x79 = kk_std_time_timestamp_days_seconds(_x_x206, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x21 = _match_x79.fst;
    kk_box_t _box_x22 = _match_x79.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x22, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x21, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x79, _ctx);
    kk_std_time_date__clock _b_x24_26;
    kk_integer_t _x_x207;
    int32_t _x_x208;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x209 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x209->since;
      int32_t _x = _con_x209->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
        kk_datatype_ptr_free(ts, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts, _ctx);
      }
      _x_x208 = _x; /*int32*/
    }
    _x_x207 = kk_integer_from_int(_x_x208,kk_context()); /*int*/
    _b_x24_26 = kk_std_time_date_leap_fs_clock(secs, _x_x207, _ctx); /*std/time/date/clock*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_time_date__clock_box(_b_x24_26, _ctx), _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_seconds_into_day(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> std/num/ddouble/ddouble */ 
  kk_std_core_types__tuple2 tuple2_10044;
  kk_std_time_timestamp__timestamp _x_x210 = kk_std_time_timestamp__timestamp_dup(ts, _ctx); /*std/time/timestamp/timestamp*/
  tuple2_10044 = kk_std_time_timestamp_days_seconds(_x_x210, _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_integer_t i_10045;
  int32_t _x_x211;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x212 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x212->since;
    int32_t _x_0 = _con_x212->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x211 = _x_0; /*int32*/
  }
  i_10045 = kk_integer_from_int(_x_x211,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x213;
  {
    kk_box_t _box_x29 = tuple2_10044.fst;
    kk_box_t _box_x30 = tuple2_10044.snd;
    kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x30, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10044, _ctx);
    _x_x213 = _x; /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble _x_x214 = kk_std_num_ddouble_ddouble_int_exp(i_10045, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x_x213, _x_x214, _ctx);
}
 
// The time span since 2000-01-01 including time inside a possible leap second.

kk_std_num_ddouble__ddouble kk_std_time_timestamp_unsafe_timespan_withleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> timespan */ 
  kk_integer_t seconds_10088;
  int32_t _x_x215;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x216 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x216->since;
    int32_t _x_0 = _con_x216->leap32;
    _x_x215 = _x_0; /*int32*/
  }
  seconds_10088 = kk_integer_from_int(_x_x215,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x217;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x218 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x218->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x217 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x219;
  bool _match_x76;
  double _x_x220;
  kk_std_core_types__optional _match_x78 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x78, _ctx)) {
    kk_box_t _box_x31 = _match_x78._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x31, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x78, _ctx);
    _x_x220 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x78, _ctx);
    _x_x220 = 0x0p+0; /*float64*/
  }
  _match_x76 = (_x_x220 == (0x0p+0)); /*bool*/
  if (_match_x76) {
    _x_x219 = kk_std_num_ddouble_ddouble_int_exp(seconds_10088, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x221 = kk_std_num_ddouble_ddouble_int_exp(seconds_10088, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x222;
    double _x_x223;
    kk_std_core_types__optional _match_x77 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x77, _ctx)) {
      kk_box_t _box_x32 = _match_x77._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x32, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x77, _ctx);
      _x_x223 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x77, _ctx);
      _x_x223 = 0x0p+0; /*float64*/
    }
    _x_x222 = kk_std_num_ddouble__new_Ddouble(_x_x223, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x219 = kk_std_num_ddouble__lp__plus__rp_(_x_x221, _x_x222, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble__lp__plus__rp_(_x_x217, _x_x219, _ctx);
}
 
// Round a time stamp to a certain precision (`prec` is number of digits of the fraction of the second).

kk_std_time_timestamp__timestamp kk_std_time_timestamp_round_to_prec(kk_std_time_timestamp__timestamp t, kk_integer_t prec, kk_context_t* _ctx) { /* (t : timestamp, prec : int) -> timestamp */ 
  kk_std_num_ddouble__ddouble _x_x225;
  kk_std_num_ddouble__ddouble _x_x226;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x227 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x227->since;
    _x_x226 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x225 = kk_std_num_ddouble_round_to_prec(_x_x226, prec, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x228;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x229 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x229->since;
    int32_t _x_0 = _con_x229->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x228 = _x_0; /*int32*/
  }
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x225, _x_x228, _ctx);
}
 
// Add `leaps` leap seconds to the timestamp.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_leap_seconds(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble leaps, kk_context_t* _ctx) { /* (ts : timestamp, leaps : timespan) -> timestamp */ 
  bool b_10054;
  double _x_x230;
  {
    double _x = leaps.hi;
    _x_x230 = _x; /*float64*/
  }
  b_10054 = (_x_x230 > (0x0p+0)); /*bool*/
  if (b_10054) {
    kk_std_num_ddouble__ddouble y_10057;
    bool _match_x73;
    double _x_x231;
    kk_std_core_types__optional _match_x75 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x75, _ctx)) {
      kk_box_t _box_x33 = _match_x75._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x33, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x75, _ctx);
      _x_x231 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x75, _ctx);
      _x_x231 = 0x0p+0; /*float64*/
    }
    _match_x73 = (_x_x231 == (0x0p+0)); /*bool*/
    if (_match_x73) {
      y_10057 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x232 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x233;
      double _x_x234;
      kk_std_core_types__optional _match_x74 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x74, _ctx)) {
        kk_box_t _box_x34 = _match_x74._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x34, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x74, _ctx);
        _x_x234 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x74, _ctx);
        _x_x234 = 0x0p+0; /*float64*/
      }
      _x_x233 = kk_std_num_ddouble__new_Ddouble(_x_x234, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      y_10057 = kk_std_num_ddouble__lp__plus__rp_(_x_x232, _x_x233, _ctx); /*std/num/ddouble/ddouble*/
    }
    bool _match_x63;
    kk_std_core_types__order _x_x235;
    kk_std_core_types__order _match_x72;
    double _x_x236;
    {
      double _x_0 = leaps.hi;
      _x_x236 = _x_0; /*float64*/
    }
    double _x_x237;
    {
      double _x_0_0 = y_10057.hi;
      _x_x237 = _x_0_0; /*float64*/
    }
    _match_x72 = kk_std_num_float64_cmp(_x_x236, _x_x237, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x72, _ctx)) {
      double _x_x238;
      {
        double _x_1 = leaps.lo;
        _x_x238 = _x_1; /*float64*/
      }
      double _x_x239;
      {
        double _x_2 = y_10057.lo;
        _x_x239 = _x_2; /*float64*/
      }
      _x_x235 = kk_std_num_float64_cmp(_x_x238, _x_x239, _ctx); /*order*/
    }
    else {
      _x_x235 = _match_x72; /*order*/
    }
    _match_x63 = kk_std_core_order__lp__eq__eq__rp_(_x_x235, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
    if (_match_x63) {
      bool _match_x65;
      kk_integer_t _brw_x70;
      int32_t _x_x240;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x241 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_3 = _con_x241->since;
        int32_t _x_3 = _con_x241->leap32;
        _x_x240 = _x_3; /*int32*/
      }
      _brw_x70 = kk_integer_from_int(_x_x240,kk_context()); /*int*/
      bool _brw_x71 = kk_integer_is_zero_borrow(_brw_x70); /*bool*/;
      kk_integer_drop(_brw_x70, _ctx);
      _match_x65 = _brw_x71; /*bool*/
      if (_match_x65) {
        kk_std_num_ddouble__ddouble y_0_10061;
        bool _match_x67;
        double _x_x242;
        kk_std_core_types__optional _match_x69 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x69, _ctx)) {
          kk_box_t _box_x35 = _match_x69._cons._Optional.value;
          double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x35, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(_match_x69, _ctx);
          _x_x242 = _uniq_frac_1144_0_0; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x69, _ctx);
          _x_x242 = 0x0p+0; /*float64*/
        }
        _match_x67 = (_x_x242 == (0x0p+0)); /*bool*/
        if (_match_x67) {
          y_0_10061 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_num_ddouble__ddouble _x_x243 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x244;
          double _x_x245;
          kk_std_core_types__optional _match_x68 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x68, _ctx)) {
            kk_box_t _box_x36 = _match_x68._cons._Optional.value;
            double _uniq_frac_1144_0_1 = kk_double_unbox(_box_x36, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(_match_x68, _ctx);
            _x_x245 = _uniq_frac_1144_0_1; /*float64*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x68, _ctx);
            _x_x245 = 0x0p+0; /*float64*/
          }
          _x_x244 = kk_std_num_ddouble__new_Ddouble(_x_x245, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          y_0_10061 = kk_std_num_ddouble__lp__plus__rp_(_x_x243, _x_x244, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x_x246;
        kk_std_num_ddouble__ddouble _x_x247;
        kk_std_num_ddouble__ddouble _x_x248;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x249 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
          kk_std_num_ddouble__ddouble _x_5 = _con_x249->since;
          if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
            kk_datatype_ptr_free(ts, _ctx);
          }
          else {
            kk_datatype_ptr_decref(ts, _ctx);
          }
          _x_x248 = _x_5; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x250;
        double _x_x251;
        double _x_x252;
        {
          double _x_4 = y_0_10061.hi;
          _x_x252 = _x_4; /*float64*/
        }
        _x_x251 = (-_x_x252); /*float64*/
        double _x_x253;
        double _x_x254;
        {
          double _x_0_1 = y_0_10061.lo;
          _x_x254 = _x_0_1; /*float64*/
        }
        _x_x253 = (-_x_x254); /*float64*/
        _x_x250 = kk_std_num_ddouble__new_Ddouble(_x_x251, _x_x253, _ctx); /*std/num/ddouble/ddouble*/
        _x_x247 = kk_std_num_ddouble__lp__plus__rp_(_x_x248, _x_x250, _ctx); /*std/num/ddouble/ddouble*/
        _x_x246 = kk_std_num_ddouble__lp__plus__rp_(_x_x247, leaps, _ctx); /*std/num/ddouble/ddouble*/
        return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x246, (KK_I32(1)), _ctx);
      }
      {
        kk_std_num_ddouble__ddouble _x_x255;
        kk_std_num_ddouble__ddouble _x_x256;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x257 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
          kk_std_num_ddouble__ddouble _x_6 = _con_x257->since;
          _x_x256 = _x_6; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x258 = kk_std_num_ddouble_fraction(leaps, _ctx); /*std/num/ddouble/ddouble*/
        _x_x255 = kk_std_num_ddouble__lp__plus__rp_(_x_x256, _x_x258, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x259;
        int32_t _x_x260;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x261 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_7 = _con_x261->since;
          int32_t _x_7 = _con_x261->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
            kk_datatype_ptr_free(ts, _ctx);
          }
          else {
            kk_datatype_ptr_decref(ts, _ctx);
          }
          _x_x260 = _x_7; /*int32*/
        }
        int32_t _x_x262;
        kk_integer_t _x_x263;
        kk_std_num_ddouble__ddouble _x_x264;
        bool _match_x66;
        double _x_x265;
        {
          double _x_8 = leaps.hi;
          _x_x265 = _x_8; /*float64*/
        }
        _match_x66 = (_x_x265 < (0x0p+0)); /*bool*/
        if (_match_x66) {
          _x_x264 = kk_std_num_ddouble_ceiling(leaps, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          _x_x264 = kk_std_num_ddouble_floor(leaps, _ctx); /*std/num/ddouble/ddouble*/
        }
        _x_x263 = kk_std_num_ddouble_int(_x_x264, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
        _x_x262 = kk_integer_clamp32(_x_x263,kk_context()); /*int32*/
        _x_x259 = (int32_t)((uint32_t)_x_x260 + (uint32_t)_x_x262); /*int32*/
        return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x255, _x_x259, _ctx);
      }
    }
    {
      kk_std_num_ddouble__ddouble _x_x266;
      kk_std_num_ddouble__ddouble _x_x267;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x268 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
        kk_std_num_ddouble__ddouble _x_9 = _con_x268->since;
        _x_x267 = _x_9; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x269 = kk_std_num_ddouble_fraction(leaps, _ctx); /*std/num/ddouble/ddouble*/
      _x_x266 = kk_std_num_ddouble__lp__plus__rp_(_x_x267, _x_x269, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x270;
      int32_t _x_x271;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x272 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_10 = _con_x272->since;
        int32_t _x_10 = _con_x272->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
          kk_datatype_ptr_free(ts, _ctx);
        }
        else {
          kk_datatype_ptr_decref(ts, _ctx);
        }
        _x_x271 = _x_10; /*int32*/
      }
      int32_t _x_x273;
      kk_integer_t _x_x274;
      kk_std_num_ddouble__ddouble _x_x275;
      bool _match_x64;
      double _x_x276;
      {
        double _x_11 = leaps.hi;
        _x_x276 = _x_11; /*float64*/
      }
      _match_x64 = (_x_x276 < (0x0p+0)); /*bool*/
      if (_match_x64) {
        _x_x275 = kk_std_num_ddouble_ceiling(leaps, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        _x_x275 = kk_std_num_ddouble_floor(leaps, _ctx); /*std/num/ddouble/ddouble*/
      }
      _x_x274 = kk_std_num_ddouble_int(_x_x275, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
      _x_x273 = kk_integer_clamp32(_x_x274,kk_context()); /*int32*/
      _x_x270 = (int32_t)((uint32_t)_x_x271 + (uint32_t)_x_x273); /*int32*/
      return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x266, _x_x270, _ctx);
    }
  }
  {
    return ts;
  }
}
 
// The minimum of two timestamps.

kk_std_time_timestamp__timestamp kk_std_time_timestamp_min(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> timestamp */ 
  bool _match_x62;
  kk_std_core_types__order _x_x277;
  kk_std_time_timestamp__timestamp _x_x278 = kk_std_time_timestamp__timestamp_dup(i, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x279 = kk_std_time_timestamp__timestamp_dup(j, _ctx); /*std/time/timestamp/timestamp*/
  _x_x277 = kk_std_time_timestamp_cmp(_x_x278, _x_x279, _ctx); /*order*/
  _match_x62 = kk_std_core_order__lp__excl__eq__rp_(_x_x277, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x62) {
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
  bool _match_x61;
  kk_std_core_types__order _x_x280;
  kk_std_time_timestamp__timestamp _x_x281 = kk_std_time_timestamp__timestamp_dup(i, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x282 = kk_std_time_timestamp__timestamp_dup(j, _ctx); /*std/time/timestamp/timestamp*/
  _x_x280 = kk_std_time_timestamp_cmp(_x_x281, _x_x282, _ctx); /*order*/
  _match_x61 = kk_std_core_order__lp__excl__eq__rp_(_x_x280, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x61) {
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
  bool _match_x58;
  kk_integer_t _brw_x59;
  int32_t _x_x283;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x284 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _pat_0 = _con_x284->since;
    int32_t _x = _con_x284->leap32;
    _x_x283 = _x; /*int32*/
  }
  _brw_x59 = kk_integer_from_int(_x_x283,kk_context()); /*int*/
  bool _brw_x60 = kk_integer_is_zero_borrow(_brw_x59); /*bool*/;
  kk_integer_drop(_brw_x59, _ctx);
  _match_x58 = _brw_x60; /*bool*/
  if (_match_x58) {
    l = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x286;
    kk_define_string_literal(, _s_x287, 3, " (+", _ctx)
    _x_x286 = kk_string_dup(_s_x287, _ctx); /*string*/
    kk_string_t _x_x288;
    kk_string_t _x_x289;
    kk_integer_t _x_x290;
    int32_t _x_x291;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x292 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x292->since;
      int32_t _x_0 = _con_x292->leap32;
      _x_x291 = _x_0; /*int32*/
    }
    _x_x290 = kk_integer_from_int(_x_x291,kk_context()); /*int*/
    _x_x289 = kk_std_core_int_show(_x_x290, _ctx); /*string*/
    kk_string_t _x_x293;
    kk_define_string_literal(, _s_x294, 6, " leap)", _ctx)
    _x_x293 = kk_string_dup(_s_x294, _ctx); /*string*/
    _x_x288 = kk_std_core_types__lp__plus__plus__rp_(_x_x289, _x_x293, _ctx); /*string*/
    l = kk_std_core_types__lp__plus__plus__rp_(_x_x286, _x_x288, _ctx); /*string*/
  }
  kk_integer_t _b_x38_43;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x37 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_1871 = kk_integer_unbox(_box_x37, _ctx);
    kk_integer_dup(_uniq_max_prec_1871, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x38_43 = _uniq_max_prec_1871; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x38_43 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x40_44;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x39 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_1875 = kk_integer_unbox(_box_x39, _ctx);
    kk_integer_dup(_uniq_secs_width_1875, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x40_44 = _uniq_secs_width_1875; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x40_44 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _b_x42_45;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x41 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_1879 = kk_string_unbox(_box_x41);
    kk_string_dup(_uniq_unit_1879, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x42_45 = _uniq_unit_1879; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x42_45 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x296;
  kk_std_num_ddouble__ddouble _x_x297;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x298 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x298->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    _x_x297 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_core_types__optional _x_x299 = kk_std_core_types__new_Optional(kk_integer_box(_b_x38_43, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x300 = kk_std_core_types__new_Optional(kk_integer_box(_b_x40_44, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x301 = kk_std_core_types__new_Optional(kk_string_box(_b_x42_45), _ctx); /*? 10003*/
  _x_x296 = kk_std_time_date_show_seconds(_x_x297, _x_x299, _x_x300, _x_x301, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x296, l, _ctx);
}
 
// Show a day stamp

kk_string_t kk_std_time_timestamp_ts_show_days(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (ts : timestamp, prec : ? int) -> string */ 
  kk_std_core_types__tuple2 _match_x56;
  kk_std_time_timestamp__timestamp _x_x302 = kk_std_time_timestamp__timestamp_dup(ts, _ctx); /*std/time/timestamp/timestamp*/
  _match_x56 = kk_std_time_timestamp_days_seconds(_x_x302, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x46 = _match_x56.fst;
    kk_box_t _box_x47 = _match_x56.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x47, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x46, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x56, _ctx);
    kk_integer_t _b_x48_49;
    int32_t _x_x303;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x304 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x304->since;
      int32_t _x = _con_x304->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
        kk_datatype_ptr_free(ts, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts, _ctx);
      }
      _x_x303 = _x; /*int32*/
    }
    _b_x48_49 = kk_integer_from_int(_x_x303,kk_context()); /*int*/
    kk_std_time_timestamp__timestamp _arg_x2159;
    int32_t _x_x305;
    kk_integer_t _x_x306;
    kk_std_core_types__optional _match_x57 = kk_std_core_types__new_Optional(kk_integer_box(_b_x48_49, _ctx), _ctx); /*? 10003*/;
    if (kk_std_core_types__is_Optional(_match_x57, _ctx)) {
      kk_box_t _box_x50 = _match_x57._cons._Optional.value;
      kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x50, _ctx);
      kk_integer_dup(_uniq_leap_1214, _ctx);
      kk_std_core_types__optional_drop(_match_x57, _ctx);
      _x_x306 = _uniq_leap_1214; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x57, _ctx);
      _x_x306 = kk_integer_from_small(0); /*int*/
    }
    _x_x305 = kk_integer_clamp32(_x_x306,kk_context()); /*int32*/
    _arg_x2159 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, secs, _x_x305, _ctx); /*std/time/timestamp/timestamp*/
    kk_string_t _x_x307 = kk_std_core_int_show(days_0, _ctx); /*string*/
    kk_string_t _x_x308;
    kk_integer_t _b_x52_54;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x51 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_2026 = kk_integer_unbox(_box_x51, _ctx);
      kk_integer_dup(_uniq_prec_2026, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x52_54 = _uniq_prec_2026; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _b_x52_54 = kk_integer_from_small(9); /*int*/
    }
    kk_string_t _b_x53_55;
    kk_define_string_literal(, _s_x309, 1, "s", _ctx)
    _b_x53_55 = kk_string_dup(_s_x309, _ctx); /*string*/
    kk_string_t _x_x310;
    kk_define_string_literal(, _s_x311, 2, "d ", _ctx)
    _x_x310 = kk_string_dup(_s_x311, _ctx); /*string*/
    kk_string_t _x_x312;
    kk_std_core_types__optional _x_x313 = kk_std_core_types__new_Optional(kk_integer_box(_b_x52_54, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x314 = kk_std_core_types__new_Optional(kk_string_box(_b_x53_55), _ctx); /*? 10003*/
    _x_x312 = kk_std_time_timestamp_ts_show(_arg_x2159, _x_x313, kk_std_core_types__new_None(_ctx), _x_x314, _ctx); /*string*/
    _x_x308 = kk_std_core_types__lp__plus__plus__rp_(_x_x310, _x_x312, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x307, _x_x308, _ctx);
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
    bool _match_x87;
    double _x_x157;
    kk_std_core_types__optional _match_x89 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x89, _ctx)) {
      kk_box_t _box_x4 = _match_x89._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x4, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x89, _ctx);
      _x_x157 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x89, _ctx);
      _x_x157 = 0x0p+0; /*float64*/
    }
    _match_x87 = (_x_x157 == (0x0p+0)); /*bool*/
    if (_match_x87) {
      kk_std_time_timestamp_solar_secs_per_day = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(86400, _ctx), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x158 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(86400, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x159;
      double _x_x160;
      kk_std_core_types__optional _match_x88 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x88, _ctx)) {
        kk_box_t _box_x5 = _match_x88._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x5, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x88, _ctx);
        _x_x160 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x88, _ctx);
        _x_x160 = 0x0p+0; /*float64*/
      }
      _x_x159 = kk_std_num_ddouble__new_Ddouble(_x_x160, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_timestamp_solar_secs_per_day = kk_std_num_ddouble__lp__plus__rp_(_x_x158, _x_x159, _ctx); /*std/time/timestamp/timespan*/
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
