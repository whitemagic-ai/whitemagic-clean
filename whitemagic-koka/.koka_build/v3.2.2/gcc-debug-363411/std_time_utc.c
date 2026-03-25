// Koka generated module: std/time/utc, koka version: 3.2.2, platform: 64-bit
#include "std_time_utc.h"
 
// runtime tag for the effect `:utc`

kk_std_core_hnd__htag kk_std_time_utc_utc_fs__tag;
 
// handler for the effect `:utc`

kk_box_t kk_std_time_utc_utc_fs__handle(kk_std_time_utc__utc hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : utc<e,b>, ret : (res : a) -> e b, action : () -> <utc|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1194 = kk_std_core_hnd__htag_dup(kk_std_time_utc_utc_fs__tag, _ctx); /*hnd/htag<std/time/utc/utc>*/
  return kk_std_core_hnd__hhandle(_x_x1194, kk_std_time_utc__utc_box(hnd, _ctx), ret, action, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_fs__copy(kk_std_time_utc__leaps_table _this, kk_std_core_types__optional expire, kk_std_core_types__optional adjusts, kk_context_t* _ctx) { /* (leaps-table, expire : ? std/time/instant/instant, adjusts : ? (list<leap-adjust>)) -> leaps-table */ 
  kk_std_time_instant__instant _x_x1197;
  if (kk_std_core_types__is_Optional(expire, _ctx)) {
    kk_box_t _box_x14 = expire._cons._Optional.value;
    kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
    kk_std_core_types__optional_drop(expire, _ctx);
    _x_x1197 = _uniq_expire_375; /*std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(expire, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1198 = kk_std_time_utc__as_Leaps_table(_this, _ctx);
      kk_std_time_instant__instant _x = _con_x1198->expire;
      kk_std_time_instant__instant_dup(_x, _ctx);
      _x_x1197 = _x; /*std/time/instant/instant*/
    }
  }
  kk_std_core_types__list _x_x1199;
  if (kk_std_core_types__is_Optional(adjusts, _ctx)) {
    kk_box_t _box_x15 = adjusts._cons._Optional.value;
    kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x15, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
    kk_std_core_types__optional_drop(adjusts, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x1199 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
  }
  else {
    kk_std_core_types__optional_drop(adjusts, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1200 = kk_std_time_utc__as_Leaps_table(_this, _ctx);
      kk_std_time_instant__instant _pat_0_1 = _con_x1200->expire;
      kk_std_core_types__list _x_0 = _con_x1200->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1199 = _x_0; /*list<std/time/utc/leap-adjust>*/
    }
  }
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x1197, _x_x1199, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc_zero;

kk_std_time_utc__leap_adjust kk_std_time_utc_leap_adjust_fs__copy(kk_std_time_utc__leap_adjust _this, kk_std_core_types__optional utc_start, kk_std_core_types__optional offset, kk_std_core_types__optional drift_start, kk_std_core_types__optional drift, kk_context_t* _ctx) { /* (leap-adjust, utc-start : ? utc-timestamp, offset : ? std/time/timestamp/timespan, drift-start : ? utc-timestamp, drift : ? std/num/ddouble/ddouble) -> leap-adjust */ 
  kk_std_time_timestamp__timestamp _x_x1217;
  if (kk_std_core_types__is_Optional(utc_start, _ctx)) {
    kk_box_t _box_x18 = utc_start._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_utc_start_473 = kk_std_time_timestamp__timestamp_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_utc_start_473, _ctx);
    kk_std_core_types__optional_drop(utc_start, _ctx);
    _x_x1217 = _uniq_utc_start_473; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(utc_start, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1218 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _x = _con_x1218->utc_start;
      kk_std_num_ddouble__ddouble _pat_2 = _con_x1218->offset;
      kk_std_time_timestamp__timestamp _pat_5 = _con_x1218->drift_start;
      kk_std_num_ddouble__ddouble _pat_8 = _con_x1218->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1219 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1220 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x, _ctx);
      _x_x1217 = _x; /*std/time/utc/utc-timestamp*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1221;
  if (kk_std_core_types__is_Optional(offset, _ctx)) {
    kk_box_t _box_x19 = offset._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_offset_481 = kk_std_num_ddouble__ddouble_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(offset, _ctx);
    _x_x1221 = _uniq_offset_481; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(offset, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1222 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_1 = _con_x1222->utc_start;
      kk_std_num_ddouble__ddouble _x_0 = _con_x1222->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1222->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1222->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1223 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1224 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      _x_x1221 = _x_0; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_time_timestamp__timestamp _x_x1225;
  if (kk_std_core_types__is_Optional(drift_start, _ctx)) {
    kk_box_t _box_x20 = drift_start._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_489 = kk_std_time_timestamp__timestamp_unbox(_box_x20, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_489, _ctx);
    kk_std_core_types__optional_drop(drift_start, _ctx);
    _x_x1225 = _uniq_drift_start_489; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1226 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_2 = _con_x1226->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_2 = _con_x1226->offset;
      kk_std_time_timestamp__timestamp _x_1 = _con_x1226->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1226->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1227 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1228 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
      _x_x1225 = _x_1; /*std/time/utc/utc-timestamp*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1229;
  if (kk_std_core_types__is_Optional(drift, _ctx)) {
    kk_box_t _box_x21 = drift._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_497 = kk_std_num_ddouble__ddouble_unbox(_box_x21, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x1229 = _uniq_drift_497; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1230 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_3 = _con_x1230->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_3 = _con_x1230->offset;
      kk_std_time_timestamp__timestamp _pat_6_3 = _con_x1230->drift_start;
      kk_std_num_ddouble__ddouble _x_2 = _con_x1230->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1231 = kk_std_time_timestamp__as_Timestamp(_pat_0_3, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1232 = kk_std_time_timestamp__as_Timestamp(_pat_6_3, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_6_3, _ctx)) {
          kk_datatype_ptr_free(_pat_6_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_6_3, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_3, _ctx)) {
          kk_datatype_ptr_free(_pat_0_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_3, _ctx);
        }
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1229 = _x_2; /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, _x_x1217, _x_x1221, _x_x1225, _x_x1229, _ctx);
}

bool kk_std_time_utc_is_zero(kk_std_time_utc__leap_adjust la, kk_context_t* _ctx) { /* (la : leap-adjust) -> bool */ 
  bool _match_x1067;
  double _x_x1233;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1234 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_0 = _con_x1234->utc_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x1234->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x1234->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1234->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1235 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1236 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    {
      double _x = _x_0.hi;
      _x_x1233 = _x; /*float64*/
    }
  }
  _match_x1067 = (_x_x1233 == (0x0p+0)); /*bool*/
  if (_match_x1067) {
    double _x_x1237;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1238 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_2 = _con_x1238->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_0 = _con_x1238->offset;
      kk_std_time_timestamp__timestamp _pat_6_0 = _con_x1238->drift_start;
      kk_std_num_ddouble__ddouble _x_2 = _con_x1238->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1239 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1240 = kk_std_time_timestamp__as_Timestamp(_pat_6_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_6_0, _ctx)) {
          kk_datatype_ptr_free(_pat_6_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_6_0, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_2, _ctx)) {
          kk_datatype_ptr_free(_pat_0_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_2, _ctx);
        }
        kk_datatype_ptr_free(la, _ctx);
      }
      else {
        kk_datatype_ptr_decref(la, _ctx);
      }
      {
        double _x_1 = _x_2.hi;
        _x_x1237 = _x_1; /*float64*/
      }
    }
    return (_x_x1237 == (0x0p+0));
  }
  {
    kk_datatype_ptr_dropn(la, (KK_I32(2)), _ctx);
    return false;
  }
}

kk_std_num_ddouble__ddouble kk_std_time_utc_ntp2000;

kk_std_time_timestamp__timestamp kk_std_time_utc_utc1958;

kk_std_time_utc__leap_adjust kk_std_time_utc_find_leap_adjust(kk_std_time_timestamp__timestamp utc_0, kk_std_core_types__list leaps, kk_context_t* _ctx) { /* (utc : utc-timestamp, leaps : list<leap-adjust>) -> leap-adjust */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(leaps, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    return kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1241 = kk_std_core_types__as_Cons(leaps, _ctx);
    kk_box_t _box_x22 = _con_x1241->head;
    kk_std_time_utc__leap_adjust la = kk_std_time_utc__leap_adjust_unbox(_box_x22, KK_BORROWED, _ctx);
    struct kk_std_time_utc_Leap_adjust* _con_x1242 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_core_types__list earlier = _con_x1241->tail;
    kk_std_time_timestamp__timestamp _pat_1 = _con_x1242->utc_start;
    kk_std_time_timestamp__timestamp _pat_3 = _con_x1242->drift_start;
    if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
      kk_datatype_ptr_free(leaps, _ctx);
    }
    else {
      kk_std_core_types__list_dup(earlier, _ctx);
      kk_std_time_utc__leap_adjust_dup(la, _ctx);
      kk_datatype_ptr_decref(leaps, _ctx);
    }
    bool _match_x1066;
    kk_std_core_types__order _x_x1243;
    kk_std_time_timestamp__timestamp _x_x1244;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1245 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _x = _con_x1245->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0 = _con_x1245->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1245->drift_start;
      kk_std_num_ddouble__ddouble _pat_8 = _con_x1245->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1246 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1247 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x, _ctx);
      _x_x1244 = _x; /*std/time/utc/utc-timestamp*/
    }
    kk_std_time_timestamp__timestamp _x_x1248 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
    _x_x1243 = kk_std_time_timestamp_cmp(_x_x1244, _x_x1248, _ctx); /*order*/
    _match_x1066 = kk_std_core_order__lp__eq__eq__rp_(_x_x1243, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
    if (_match_x1066) {
      if kk_likely(kk_datatype_ptr_is_unique(la, _ctx)) {
        kk_std_time_timestamp__timestamp_drop(_pat_3, _ctx);
        kk_std_time_timestamp__timestamp_drop(_pat_1, _ctx);
        kk_datatype_ptr_free(la, _ctx);
      }
      else {
        kk_datatype_ptr_decref(la, _ctx);
      }
      { // tailcall
        leaps = earlier;
        goto kk__tailcall;
      }
    }
    {
      kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
      kk_std_core_types__list_drop(earlier, _ctx);
      return la;
    }
  }
}

kk_std_time_utc__leap_adjust kk_std_time_utc_utc_to_leap_adjust(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : utc-timestamp) -> leap-adjust */ 
  bool _match_x1065;
  kk_std_core_types__order _x_x1249;
  kk_std_time_timestamp__timestamp _x_x1250 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
  kk_std_time_timestamp__timestamp _x_x1251 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1249 = kk_std_time_timestamp_cmp(_x_x1250, _x_x1251, _ctx); /*order*/
  _match_x1065 = kk_std_core_order__lp__eq__eq__rp_(_x_x1249, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1065) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    return kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx);
  }
  {
    kk_std_core_types__list _x_x1252;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1253 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
      kk_std_time_instant__instant _pat_0_0 = _con_x1253->expire;
      kk_std_core_types__list _x = _con_x1253->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(leaps, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x, _ctx);
        kk_datatype_ptr_decref(leaps, _ctx);
      }
      _x_x1252 = _x; /*list<std/time/utc/leap-adjust>*/
    }
    return kk_std_time_utc_find_leap_adjust(utc_0, _x_x1252, _ctx);
  }
}
 
// Get the leap-second adjustment _delta-tai_ (= TAI - UTC).
// Needs the timestamp to handle _drift_.

kk_std_num_ddouble__ddouble kk_std_time_utc_delta_tai(kk_std_time_utc__leap_adjust la, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (la : leap-adjust, utc : utc-timestamp) -> std/time/timestamp/timespan */ 
  bool _match_x1064;
  double _x_x1254;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1255 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_0 = _con_x1255->utc_start;
    kk_std_num_ddouble__ddouble _pat_3 = _con_x1255->offset;
    kk_std_time_timestamp__timestamp _pat_6 = _con_x1255->drift_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x1255->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1256 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1257 = kk_std_time_timestamp__as_Timestamp(_pat_6, _ctx);
    {
      double _x = _x_0.hi;
      _x_x1254 = _x; /*float64*/
    }
  }
  _match_x1064 = (_x_x1254 == (0x0p+0)); /*bool*/
  if (_match_x1064) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1258 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_1 = _con_x1258->utc_start;
      kk_std_num_ddouble__ddouble _x_1 = _con_x1258->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1258->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1258->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1259 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1260 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
          kk_datatype_ptr_free(_pat_5_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_0, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_1, _ctx)) {
          kk_datatype_ptr_free(_pat_0_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_1, _ctx);
        }
        kk_datatype_ptr_free(la, _ctx);
      }
      else {
        kk_datatype_ptr_decref(la, _ctx);
      }
      return _x_1;
    }
  }
  {
    kk_std_num_ddouble__ddouble days;
    kk_std_num_ddouble__ddouble _x_x1261;
    kk_std_num_ddouble__ddouble _x_x1262;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1263 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
      kk_std_num_ddouble__ddouble _x_3 = _con_x1263->since;
      if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
        kk_datatype_ptr_free(utc_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(utc_0, _ctx);
      }
      _x_x1262 = _x_3; /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble _x_x1264;
    double _x_x1265;
    double _x_x1266;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1267 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6 = _con_x1267->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1 = _con_x1267->offset;
      kk_std_time_timestamp__timestamp _x_5 = _con_x1267->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1267->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1268 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1269 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_5, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1270 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
        kk_std_num_ddouble__ddouble _x_4 = _con_x1270->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
          kk_datatype_ptr_free(_x_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_5, _ctx);
        }
        {
          double _x_2 = _x_4.hi;
          _x_x1266 = _x_2; /*float64*/
        }
      }
    }
    _x_x1265 = (-_x_x1266); /*float64*/
    double _x_x1271;
    double _x_x1272;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1273 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6_0 = _con_x1273->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1_0 = _con_x1273->offset;
      kk_std_time_timestamp__timestamp _x_5_0 = _con_x1273->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1_0 = _con_x1273->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1274 = kk_std_time_timestamp__as_Timestamp(_pat_0_6_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1275 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_5_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1276 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x1276->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5_0, _ctx)) {
          kk_datatype_ptr_free(_x_5_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_5_0, _ctx);
        }
        {
          double _x_0_0 = _x_4_0.lo;
          _x_x1272 = _x_0_0; /*float64*/
        }
      }
    }
    _x_x1271 = (-_x_x1272); /*float64*/
    _x_x1264 = kk_std_num_ddouble__new_Ddouble(_x_x1265, _x_x1271, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1261 = kk_std_num_ddouble__lp__plus__rp_(_x_x1262, _x_x1264, _ctx); /*std/num/ddouble/ddouble*/
    days = kk_std_num_ddouble__lp__fs__rp_(_x_x1261, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1277;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1278 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_7 = _con_x1278->utc_start;
      kk_std_num_ddouble__ddouble _x_6 = _con_x1278->offset;
      kk_std_time_timestamp__timestamp _pat_5_2 = _con_x1278->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_2 = _con_x1278->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1279 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1280 = kk_std_time_timestamp__as_Timestamp(_pat_5_2, _ctx);
      _x_x1277 = _x_6; /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble _x_x1281;
    kk_std_num_ddouble__ddouble _x_x1282;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1283 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_8 = _con_x1283->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_3 = _con_x1283->offset;
      kk_std_time_timestamp__timestamp _pat_6_3 = _con_x1283->drift_start;
      kk_std_num_ddouble__ddouble _x_7 = _con_x1283->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1284 = kk_std_time_timestamp__as_Timestamp(_pat_0_8, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1285 = kk_std_time_timestamp__as_Timestamp(_pat_6_3, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_6_3, _ctx)) {
          kk_datatype_ptr_free(_pat_6_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_6_3, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_8, _ctx)) {
          kk_datatype_ptr_free(_pat_0_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_8, _ctx);
        }
        kk_datatype_ptr_free(la, _ctx);
      }
      else {
        kk_datatype_ptr_decref(la, _ctx);
      }
      _x_x1282 = _x_7; /*std/num/ddouble/ddouble*/
    }
    _x_x1281 = kk_std_num_ddouble__lp__star__rp_(_x_x1282, days, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x_x1277, _x_x1281, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_to_delta_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : utc-timestamp) -> std/time/timestamp/timespan */ 
  kk_std_time_utc__leap_adjust _x_x1286;
  bool _match_x1063;
  kk_std_core_types__order _x_x1287;
  kk_std_time_timestamp__timestamp _x_x1288 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
  kk_std_time_timestamp__timestamp _x_x1289 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1287 = kk_std_time_timestamp_cmp(_x_x1288, _x_x1289, _ctx); /*order*/
  _match_x1063 = kk_std_core_order__lp__eq__eq__rp_(_x_x1287, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1063) {
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    _x_x1286 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1290 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
    kk_std_core_types__list _x_x1291;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1292 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
      kk_std_time_instant__instant _pat_0_0 = _con_x1292->expire;
      kk_std_core_types__list _x = _con_x1292->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(leaps, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x, _ctx);
        kk_datatype_ptr_decref(leaps, _ctx);
      }
      _x_x1291 = _x; /*list<std/time/utc/leap-adjust>*/
    }
    _x_x1286 = kk_std_time_utc_find_leap_adjust(_x_x1290, _x_x1291, _ctx); /*std/time/utc/leap-adjust*/
  }
  return kk_std_time_utc_delta_tai(_x_x1286, utc_0, _ctx);
}

kk_std_time_duration__duration kk_std_time_utc_utc_to_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : std/time/timestamp/timestamp) -> std/time/duration/duration */ 
  kk_std_num_ddouble__ddouble dtai;
  kk_std_time_utc__leap_adjust _x_x1293;
  bool _match_x1062;
  kk_std_core_types__order _x_x1294;
  kk_std_time_timestamp__timestamp _x_x1295 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x1296 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1294 = kk_std_time_timestamp_cmp(_x_x1295, _x_x1296, _ctx); /*order*/
  _match_x1062 = kk_std_core_order__lp__eq__eq__rp_(_x_x1294, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1062) {
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    _x_x1293 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1297 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__list _x_x1298;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1299 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
      kk_std_time_instant__instant _pat_0_0 = _con_x1299->expire;
      kk_std_core_types__list _x = _con_x1299->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(leaps, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x, _ctx);
        kk_datatype_ptr_decref(leaps, _ctx);
      }
      _x_x1298 = _x; /*list<std/time/utc/leap-adjust>*/
    }
    _x_x1293 = kk_std_time_utc_find_leap_adjust(_x_x1297, _x_x1298, _ctx); /*std/time/utc/leap-adjust*/
  }
  kk_std_time_timestamp__timestamp _x_x1300 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
  dtai = kk_std_time_utc_delta_tai(_x_x1293, _x_x1300, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp t_10032;
  kk_std_num_ddouble__ddouble _x_x1301;
  kk_std_num_ddouble__ddouble _x_x1302;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1303 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _x_0 = _con_x1303->since;
    _x_x1302 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x1301 = kk_std_num_ddouble__lp__plus__rp_(_x_x1302, dtai, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1304;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1305 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1305->since;
    int32_t _x_0_0 = _con_x1305->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
      kk_datatype_ptr_free(utc_0, _ctx);
    }
    else {
      kk_datatype_ptr_decref(utc_0, _ctx);
    }
    _x_x1304 = _x_0_0; /*int32*/
  }
  t_10032 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1301, _x_x1304, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x1306 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10032, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x1306, _ctx);
}
 
// /* Converting TAI time back to UTC is not straightforward as
// we need to estimate UTC at first as the leap table goes from UTC-to-TAI.
// Moreover, we need to detect if we crossed over a leap second, or are
// inside a leap step. Take for example the leap second of 2006-01-01
// to +33. This looks like:
// 
// UTC-to-TAI-delta:                        ... +32   |   +33 ...
// 
// UTC timestamp          189388799   189388799+1  189388800
// UTC 2005-12-31T23:59:     59          60   leap    00
//                  ---------|-----------|xxxxxxxxxxxx|-------------
//                           |           |            |
// TAI 2006-01-01T00:00:     31          32           33
// TAI timestamp:         189388831   189388832    189388833
// 
// In the code below, suppose `tai` is `189388832.5`.
// Then we estimate at first the delta `dtai0` to +33, so our
// estimate `utc0` is `189388799.5` (just before the leap step!).
// We then use `utc0` to get delta-TAI at that time, +32 and
// set the difference `diff` to `(33-32) == 1` -- the time of the
// leap second we crossed. (usually, `diff` is zero of course).
// If the difference is positive, we then check if `utc0` is in the
// leap period itself (instead of before it): that is the case if
// the delta-TAI at `utc0+diff` equals `dtai0` again.
// If we are not in a leap second, the final utc time is the
// estimate plus the time of the leap period if we crossed over it, `utc0+diff`.
// Otherwise, the same holds but we need to add `diff` as leap seconds,
// in the example ending up as `189388799.5+1`.
// */

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_from_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_duration__duration tai_since, kk_context_t* _ctx) { /* (leaps : leaps-table, tai-since : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp tai;
  kk_std_num_ddouble__ddouble _x_x1307;
  {
    kk_std_num_ddouble__ddouble _x = tai_since.secs;
    _x_x1307 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1308;
  kk_integer_t _x_x1309;
  kk_std_core_types__optional _match_x1061 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1061, _ctx)) {
    kk_box_t _box_x23 = _match_x1061._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x23, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x1061, _ctx);
    _x_x1309 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1061, _ctx);
    _x_x1309 = kk_integer_from_small(0); /*int*/
  }
  _x_x1308 = kk_integer_clamp32(_x_x1309,kk_context()); /*int32*/
  tai = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1307, _x_x1308, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble dtai0;
  kk_std_time_utc__leap_adjust _x_x1310;
  bool _match_x1060;
  kk_std_core_types__order _x_x1311;
  kk_std_time_timestamp__timestamp _x_x1312 = kk_std_time_timestamp__timestamp_dup(tai, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x1313 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1311 = kk_std_time_timestamp_cmp(_x_x1312, _x_x1313, _ctx); /*order*/
  _match_x1060 = kk_std_core_order__lp__eq__eq__rp_(_x_x1311, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1060) {
    _x_x1310 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1314 = kk_std_time_timestamp__timestamp_dup(tai, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__list _x_x1315;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1316 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
      kk_std_time_instant__instant _pat_0_0_0 = _con_x1316->expire;
      kk_std_core_types__list _x_0 = _con_x1316->adjusts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x1315 = _x_0; /*list<std/time/utc/leap-adjust>*/
    }
    _x_x1310 = kk_std_time_utc_find_leap_adjust(_x_x1314, _x_x1315, _ctx); /*std/time/utc/leap-adjust*/
  }
  kk_std_time_timestamp__timestamp _x_x1317 = kk_std_time_timestamp__timestamp_dup(tai, _ctx); /*std/time/timestamp/timestamp*/
  dtai0 = kk_std_time_utc_delta_tai(_x_x1310, _x_x1317, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp utc0 = kk_std_time_timestamp__lp__dash__rp_(tai, dtai0, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_num_ddouble__ddouble dtai1;
  kk_std_time_utc__leap_adjust _x_x1318;
  bool _match_x1059;
  kk_std_core_types__order _x_x1319;
  kk_std_time_timestamp__timestamp _x_x1320 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x1321 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1319 = kk_std_time_timestamp_cmp(_x_x1320, _x_x1321, _ctx); /*order*/
  _match_x1059 = kk_std_core_order__lp__eq__eq__rp_(_x_x1319, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1059) {
    _x_x1318 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1322 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__list _x_x1323;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1324 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
      kk_std_time_instant__instant _pat_0_0_1 = _con_x1324->expire;
      kk_std_core_types__list _x_1 = _con_x1324->adjusts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _x_x1323 = _x_1; /*list<std/time/utc/leap-adjust>*/
    }
    _x_x1318 = kk_std_time_utc_find_leap_adjust(_x_x1322, _x_x1323, _ctx); /*std/time/utc/leap-adjust*/
  }
  kk_std_time_timestamp__timestamp _x_x1325 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
  dtai1 = kk_std_time_utc_delta_tai(_x_x1318, _x_x1325, _ctx); /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble diff;
  kk_std_num_ddouble__ddouble _x_x1326;
  double _x_x1327;
  double _x_x1328;
  {
    double _x_0_0 = dtai1.hi;
    _x_x1328 = _x_0_0; /*float64*/
  }
  _x_x1327 = (-_x_x1328); /*float64*/
  double _x_x1329;
  double _x_x1330;
  {
    double _x_0_0_0 = dtai1.lo;
    _x_x1330 = _x_0_0_0; /*float64*/
  }
  _x_x1329 = (-_x_x1330); /*float64*/
  _x_x1326 = kk_std_num_ddouble__new_Ddouble(_x_x1327, _x_x1329, _ctx); /*std/num/ddouble/ddouble*/
  diff = kk_std_num_ddouble__lp__plus__rp_(dtai0, _x_x1326, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x_0_10042 = kk_std_num_ddouble_round_to_prec(diff, kk_integer_from_small(3), _ctx); /*std/num/ddouble/ddouble*/;
  bool hasgap;
  double _x_x1331;
  {
    double _x_1_0 = x_0_10042.hi;
    _x_x1331 = _x_1_0; /*float64*/
  }
  hasgap = (_x_x1331 > (0x0p+0)); /*bool*/
  bool inleap;
  if (hasgap) {
    kk_std_time_timestamp__timestamp utc_0_1_10046;
    kk_std_num_ddouble__ddouble _x_x1332;
    kk_std_num_ddouble__ddouble _x_x1333;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1334 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _x_3 = _con_x1334->since;
      _x_x1333 = _x_3; /*std/time/timestamp/timespan*/
    }
    _x_x1332 = kk_std_num_ddouble__lp__plus__rp_(_x_x1333, diff, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x1335;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1336 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_2 = _con_x1336->since;
      int32_t _x_0_2 = _con_x1336->leap32;
      _x_x1335 = _x_0_2; /*int32*/
    }
    utc_0_1_10046 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1332, _x_x1335, _ctx); /*std/time/utc/utc-timestamp*/
    kk_std_num_ddouble__ddouble x_1_10043;
    kk_std_time_utc__leap_adjust _x_x1337;
    bool _match_x1058;
    kk_std_core_types__order _x_x1338;
    kk_std_time_timestamp__timestamp _x_x1339 = kk_std_time_timestamp__timestamp_dup(utc_0_1_10046, _ctx); /*std/time/utc/utc-timestamp*/
    kk_std_time_timestamp__timestamp _x_x1340 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
    _x_x1338 = kk_std_time_timestamp_cmp(_x_x1339, _x_x1340, _ctx); /*order*/
    _match_x1058 = kk_std_core_order__lp__eq__eq__rp_(_x_x1338, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
    if (_match_x1058) {
      kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
      _x_x1337 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
    }
    else {
      kk_std_time_timestamp__timestamp _x_x1341 = kk_std_time_timestamp__timestamp_dup(utc_0_1_10046, _ctx); /*std/time/utc/utc-timestamp*/
      kk_std_core_types__list _x_x1342;
      {
        struct kk_std_time_utc_Leaps_table* _con_x1343 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
        kk_std_time_instant__instant _pat_0_0_3 = _con_x1343->expire;
        kk_std_core_types__list _x_2 = _con_x1343->adjusts;
        if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
          kk_std_time_instant__instant_drop(_pat_0_0_3, _ctx);
          kk_datatype_ptr_free(leaps, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_2, _ctx);
          kk_datatype_ptr_decref(leaps, _ctx);
        }
        _x_x1342 = _x_2; /*list<std/time/utc/leap-adjust>*/
      }
      _x_x1337 = kk_std_time_utc_find_leap_adjust(_x_x1341, _x_x1342, _ctx); /*std/time/utc/leap-adjust*/
    }
    x_1_10043 = kk_std_time_utc_delta_tai(_x_x1337, utc_0_1_10046, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_core_types__order _x_x1344;
    kk_std_core_types__order _match_x1057;
    double _x_x1345;
    {
      double _x_2_0 = x_1_10043.hi;
      _x_x1345 = _x_2_0; /*float64*/
    }
    double _x_x1346;
    {
      double _x_0_1 = dtai1.hi;
      _x_x1346 = _x_0_1; /*float64*/
    }
    _match_x1057 = kk_std_num_float64_cmp(_x_x1345, _x_x1346, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x1057, _ctx)) {
      double _x_x1347;
      {
        double _x_1_0_0 = x_1_10043.lo;
        _x_x1347 = _x_1_0_0; /*float64*/
      }
      double _x_x1348;
      {
        double _x_2_0_0 = dtai1.lo;
        _x_x1348 = _x_2_0_0; /*float64*/
      }
      _x_x1344 = kk_std_num_float64_cmp(_x_x1347, _x_x1348, _ctx); /*order*/
    }
    else {
      _x_x1344 = _match_x1057; /*order*/
    }
    inleap = kk_std_core_order__lp__excl__eq__rp_(_x_x1344, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
  }
  else {
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    inleap = false; /*bool*/
  }
  if (inleap) {
    return kk_std_time_timestamp_add_leap_seconds(utc0, diff, _ctx);
  }
  {
    kk_std_num_ddouble__ddouble _x_x1349;
    kk_std_num_ddouble__ddouble _x_x1350;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1351 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _x_4 = _con_x1351->since;
      _x_x1350 = _x_4; /*std/time/timestamp/timespan*/
    }
    _x_x1349 = kk_std_num_ddouble__lp__plus__rp_(_x_x1350, diff, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x1352;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1353 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_3_0 = _con_x1353->since;
      int32_t _x_0_3 = _con_x1353->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(utc0, _ctx)) {
        kk_datatype_ptr_free(utc0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(utc0, _ctx);
      }
      _x_x1352 = _x_0_3; /*int32*/
    }
    return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1349, _x_x1352, _ctx);
  }
}
 
// Return `Just(start,diff)` if a leap second occurred in the given day
// (`days` after 2000-01-01) with the start time and leap second gap (`diff`)

kk_std_core_types__maybe kk_std_time_utc_utc_leap_in_day(kk_std_time_utc__leaps_table leaps, kk_integer_t days, kk_context_t* _ctx) { /* (leaps : leaps-table, days : int) -> maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)> */ 
  kk_std_time_timestamp__timestamp utc0;
  kk_integer_t _x_x1354 = kk_integer_dup(days, _ctx); /*int*/
  utc0 = kk_std_time_timestamp_timestamp_days(_x_x1354, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp utc1;
  kk_integer_t _x_x1355 = kk_integer_add_small_const(days, 1, _ctx); /*int*/
  utc1 = kk_std_time_timestamp_timestamp_days(_x_x1355, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_utc__leap_adjust la1;
  bool _match_x1056;
  kk_std_core_types__order _x_x1356;
  kk_std_time_timestamp__timestamp _x_x1357 = kk_std_time_timestamp__timestamp_dup(utc1, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp _x_x1358 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1356 = kk_std_time_timestamp_cmp(_x_x1357, _x_x1358, _ctx); /*order*/
  _match_x1056 = kk_std_core_order__lp__eq__eq__rp_(_x_x1356, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1056) {
    la1 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1359 = kk_std_time_timestamp__timestamp_dup(utc1, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__list _x_x1360;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1361 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
      kk_std_time_instant__instant _pat_0_0 = _con_x1361->expire;
      kk_std_core_types__list _x = _con_x1361->adjusts;
      kk_std_core_types__list_dup(_x, _ctx);
      _x_x1360 = _x; /*list<std/time/utc/leap-adjust>*/
    }
    la1 = kk_std_time_utc_find_leap_adjust(_x_x1359, _x_x1360, _ctx); /*std/time/utc/leap-adjust*/
  }
  bool _match_x1054;
  kk_std_core_types__order _x_x1362;
  kk_std_time_timestamp__timestamp _x_x1363;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1364 = kk_std_time_utc__as_Leap_adjust(la1, _ctx);
    kk_std_time_timestamp__timestamp _x_0 = _con_x1364->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_0 = _con_x1364->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x1364->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1364->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1365 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1366 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
    _x_x1363 = _x_0; /*std/time/utc/utc-timestamp*/
  }
  kk_std_time_timestamp__timestamp _x_x1367 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
  _x_x1362 = kk_std_time_timestamp_cmp(_x_x1363, _x_x1367, _ctx); /*order*/
  _match_x1054 = kk_std_core_order__lp__eq__eq__rp_(_x_x1362, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x1054) {
    kk_std_time_timestamp__timestamp_drop(utc1, _ctx);
    kk_std_time_timestamp__timestamp_drop(utc0, _ctx);
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(la1, (KK_I32(2)), _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_num_ddouble__ddouble dtai0;
    kk_std_time_utc__leap_adjust _x_x1368;
    bool _match_x1055;
    kk_std_core_types__order _x_x1369;
    kk_std_time_timestamp__timestamp _x_x1370 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x1371 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
    _x_x1369 = kk_std_time_timestamp_cmp(_x_x1370, _x_x1371, _ctx); /*order*/
    _match_x1055 = kk_std_core_order__lp__eq__eq__rp_(_x_x1369, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
    if (_match_x1055) {
      kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
      _x_x1368 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
    }
    else {
      kk_std_time_timestamp__timestamp _x_x1372 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_core_types__list _x_x1373;
      {
        struct kk_std_time_utc_Leaps_table* _con_x1374 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
        kk_std_time_instant__instant _pat_0_0_1 = _con_x1374->expire;
        kk_std_core_types__list _x_1 = _con_x1374->adjusts;
        if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
          kk_std_time_instant__instant_drop(_pat_0_0_1, _ctx);
          kk_datatype_ptr_free(leaps, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(leaps, _ctx);
        }
        _x_x1373 = _x_1; /*list<std/time/utc/leap-adjust>*/
      }
      _x_x1368 = kk_std_time_utc_find_leap_adjust(_x_x1372, _x_x1373, _ctx); /*std/time/utc/leap-adjust*/
    }
    dtai0 = kk_std_time_utc_delta_tai(_x_x1368, utc0, _ctx); /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble dtai1;
    kk_std_time_utc__leap_adjust _x_x1375 = kk_std_time_utc__leap_adjust_dup(la1, _ctx); /*std/time/utc/leap-adjust*/
    dtai1 = kk_std_time_utc_delta_tai(_x_x1375, utc1, _ctx); /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble diff;
    kk_std_num_ddouble__ddouble _x_x1376;
    kk_std_num_ddouble__ddouble _x_x1377;
    double _x_x1378;
    double _x_x1379;
    {
      double _x_0_0 = dtai0.hi;
      _x_x1379 = _x_0_0; /*float64*/
    }
    _x_x1378 = (-_x_x1379); /*float64*/
    double _x_x1380;
    double _x_x1381;
    {
      double _x_0_0_0 = dtai0.lo;
      _x_x1381 = _x_0_0_0; /*float64*/
    }
    _x_x1380 = (-_x_x1381); /*float64*/
    _x_x1377 = kk_std_num_ddouble__new_Ddouble(_x_x1378, _x_x1380, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1376 = kk_std_num_ddouble__lp__plus__rp_(dtai1, _x_x1377, _ctx); /*std/num/ddouble/ddouble*/
    diff = kk_std_num_ddouble_round_to_prec(_x_x1376, kk_integer_from_small(3), _ctx); /*std/num/ddouble/ddouble*/
    kk_box_t _x_x1382;
    kk_std_core_types__tuple2 _x_x1383;
    kk_box_t _x_x1384;
    kk_std_time_timestamp__timestamp _x_x1385;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1386 = kk_std_time_utc__as_Leap_adjust(la1, _ctx);
      kk_std_time_timestamp__timestamp _x_1_0 = _con_x1386->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_0 = _con_x1386->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1386->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1386->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1387 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1388 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la1, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
          kk_datatype_ptr_free(_pat_5_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_0, _ctx);
        }
        kk_datatype_ptr_free(la1, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
        kk_datatype_ptr_decref(la1, _ctx);
      }
      _x_x1385 = _x_1_0; /*std/time/utc/utc-timestamp*/
    }
    _x_x1384 = kk_std_time_timestamp__timestamp_box(_x_x1385, _ctx); /*134*/
    _x_x1383 = kk_std_core_types__new_Tuple2(_x_x1384, kk_std_num_ddouble__ddouble_box(diff, _ctx), _ctx); /*(134, 135)*/
    _x_x1382 = kk_std_core_types__tuple2_box(_x_x1383, _ctx); /*88*/
    return kk_std_core_types__new_Just(_x_x1382, _ctx);
  }
}
 
// The UTC seconds in a day

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_seconds_in_day(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : std/time/timestamp/timestamp) -> std/time/timestamp/timespan */ 
  kk_std_core_types__tuple2 tuple2_10043 = kk_std_time_timestamp_days_seconds(utc_0, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_std_core_types__maybe _match_x1053;
  kk_integer_t _x_x1389;
  {
    kk_box_t _box_x30 = tuple2_10043.fst;
    kk_box_t _box_x31 = tuple2_10043.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x30, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10043, _ctx);
    _x_x1389 = _x; /*int*/
  }
  _match_x1053 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1389, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x1053, _ctx)) {
    return kk_std_time_timestamp_solar_secs_per_day;
  }
  {
    kk_box_t _box_x32 = _match_x1053._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x32, KK_BORROWED, _ctx);
    kk_box_t _box_x33 = _pat_1_0.fst;
    kk_box_t _box_x34 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x33, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x34, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1390 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    kk_std_core_types__maybe_drop(_match_x1053, _ctx);
    return kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx);
  }
}
 
// Return the modified julian day since 2000-01-01 taking leap seconds into
// account that happen any time during the day

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_to_mjd(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_std_num_ddouble__ddouble tzdelta, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : utc-timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 
  kk_std_core_types__tuple2 _match_x1050;
  kk_std_time_timestamp__timestamp _x_x1391;
  kk_std_num_ddouble__ddouble _x_x1392;
  kk_std_num_ddouble__ddouble _x_x1393;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1394 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x1394->since;
    _x_x1393 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x1392 = kk_std_num_ddouble__lp__plus__rp_(_x_x1393, tzdelta, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1395;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1396 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x1396->since;
    int32_t _x_0 = _con_x1396->leap32;
    _x_x1395 = _x_0; /*int32*/
  }
  _x_x1391 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1392, _x_x1395, _ctx); /*std/time/timestamp/timestamp*/
  _match_x1050 = kk_std_time_timestamp_days_seconds(_x_x1391, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x35 = _match_x1050.fst;
    kk_box_t _box_x36 = _match_x1050.snd;
    kk_std_num_ddouble__ddouble secs1 = kk_std_num_ddouble__ddouble_unbox(_box_x36, KK_BORROWED, _ctx);
    kk_integer_t days1 = kk_integer_unbox(_box_x35, _ctx);
    kk_integer_dup(days1, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1050, _ctx);
    kk_std_core_types__tuple2 tuple2_10043;
    kk_std_time_timestamp__timestamp _x_x1397 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
    tuple2_10043 = kk_std_time_timestamp_days_seconds(_x_x1397, _ctx); /*(int, std/num/ddouble/ddouble)*/
    kk_std_num_ddouble__ddouble frac;
    kk_std_core_types__maybe _match_x1051;
    kk_integer_t _x_x1398;
    {
      kk_box_t _box_x37 = tuple2_10043.fst;
      kk_box_t _box_x38 = tuple2_10043.snd;
      kk_integer_t _x_1 = kk_integer_unbox(_box_x37, _ctx);
      kk_integer_dup(_x_1, _ctx);
      kk_std_core_types__tuple2_drop(tuple2_10043, _ctx);
      _x_x1398 = _x_1; /*int*/
    }
    _match_x1051 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1398, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
    if (kk_std_core_types__is_Nothing(_match_x1051, _ctx)) {
      kk_integer_t i_10066;
      int32_t _x_x1399;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1400 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_3 = _con_x1400->since;
        int32_t _x_2 = _con_x1400->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
          kk_datatype_ptr_free(utc_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(utc_0, _ctx);
        }
        _x_x1399 = _x_2; /*int32*/
      }
      i_10066 = kk_integer_from_int(_x_x1399,kk_context()); /*int*/
      kk_std_num_ddouble__ddouble _x_x1401;
      kk_std_num_ddouble__ddouble _x_x1402 = kk_std_num_ddouble_ddouble_int_exp(i_10066, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x1401 = kk_std_num_ddouble__lp__plus__rp_(secs1, _x_x1402, _ctx); /*std/num/ddouble/ddouble*/
      frac = kk_std_num_ddouble__lp__fs__rp_(_x_x1401, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_box_t _box_x39 = _match_x1051._cons.Just.value;
      kk_std_core_types__tuple2 _pat_4_0 = kk_std_core_types__tuple2_unbox(_box_x39, KK_BORROWED, _ctx);
      kk_box_t _box_x40 = _pat_4_0.fst;
      kk_box_t _box_x41 = _pat_4_0.snd;
      kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x40, KK_BORROWED, _ctx);
      kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x41, KK_BORROWED, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1403 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
      kk_std_time_timestamp__timestamp_dup(start, _ctx);
      kk_std_core_types__maybe_drop(_match_x1051, _ctx);
      kk_std_num_ddouble__ddouble secs_in_day = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_num_ddouble__ddouble secs;
      bool _match_x1052;
      kk_std_core_types__order _x_x1404;
      kk_std_time_timestamp__timestamp _x_x1405 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
      _x_x1404 = kk_std_time_timestamp_cmp(_x_x1405, start, _ctx); /*order*/
      _match_x1052 = kk_std_core_order__lp__eq__eq__rp_(_x_x1404, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
      if (_match_x1052) {
        kk_integer_t i_1_10070;
        int32_t _x_x1406;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1407 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_4 = _con_x1407->since;
          int32_t _x_3 = _con_x1407->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
            kk_datatype_ptr_free(utc_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(utc_0, _ctx);
          }
          _x_x1406 = _x_3; /*int32*/
        }
        i_1_10070 = kk_integer_from_int(_x_x1406,kk_context()); /*int*/
        kk_std_num_ddouble__ddouble _x_x1408 = kk_std_num_ddouble_ddouble_int_exp(i_1_10070, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        secs = kk_std_num_ddouble__lp__plus__rp_(secs1, _x_x1408, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
        secs = kk_std_num_ddouble__lp__plus__rp_(secs1, diff, _ctx); /*std/num/ddouble/ddouble*/
      }
      frac = kk_std_num_ddouble__lp__fs__rp_(secs, secs_in_day, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble _x_x1409 = kk_std_num_ddouble_ddouble_int_exp(days1, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x_x1409, frac, _ctx);
  }
}
 
// Return UTC from the modified julian day since 2000-01-01 taking leap seconds into
// account that happen any time during the day

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_from_mjd(kk_std_time_utc__leaps_table leaps, kk_integer_t days, kk_std_num_ddouble__ddouble frac, kk_context_t* _ctx) { /* (leaps : leaps-table, days : int, frac : std/num/ddouble/ddouble) -> utc-timestamp */ 
  kk_std_core_types__maybe _match_x1047;
  kk_integer_t _x_x1410 = kk_integer_dup(days, _ctx); /*int*/
  _match_x1047 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1410, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x1047, _ctx)) {
    kk_std_num_ddouble__ddouble _b_x42_48 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core_types__optional _x_x1411 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x42_48, _ctx), _ctx); /*? 7*/
    return kk_std_time_timestamp_timestamp_days(days, _x_x1411, kk_std_core_types__new_None(_ctx), _ctx);
  }
  {
    kk_box_t _box_x43 = _match_x1047._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1 = kk_std_core_types__tuple2_unbox(_box_x43, KK_BORROWED, _ctx);
    kk_box_t _box_x44 = _pat_1.fst;
    kk_box_t _box_x45 = _pat_1.snd;
    kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x44, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x45, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1412 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
    kk_std_time_timestamp__timestamp_dup(start, _ctx);
    kk_std_core_types__maybe_drop(_match_x1047, _ctx);
    kk_std_num_ddouble__ddouble secs;
    kk_std_num_ddouble__ddouble _x_x1413 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/num/ddouble/ddouble*/
    secs = kk_std_num_ddouble__lp__star__rp_(frac, _x_x1413, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_timestamp__timestamp utc_0;
    kk_std_core_types__optional _x_x1414 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*? 7*/
    utc_0 = kk_std_time_timestamp_timestamp_days(days, _x_x1414, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
    bool _match_x1048;
    kk_std_core_types__order _x_x1415;
    kk_std_time_timestamp__timestamp _x_x1416 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x1417 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    _x_x1415 = kk_std_time_timestamp_cmp(_x_x1416, _x_x1417, _ctx); /*order*/
    _match_x1048 = kk_std_core_order__lp__eq__eq__rp_(_x_x1415, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
    if (_match_x1048) {
      if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
        kk_datatype_ptr_free(start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(start, _ctx);
      }
      return utc_0;
    }
    {
      kk_std_time_timestamp__timestamp j_0_10076;
      kk_std_num_ddouble__ddouble _x_x1418;
      kk_std_num_ddouble__ddouble _x_x1419;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1420 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _x = _con_x1420->since;
        _x_x1419 = _x; /*std/time/timestamp/timespan*/
      }
      _x_x1418 = kk_std_num_ddouble__lp__plus__rp_(_x_x1419, diff, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1421;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1422 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1422->since;
        int32_t _x_0 = _con_x1422->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
          kk_datatype_ptr_free(start, _ctx);
        }
        else {
          kk_datatype_ptr_decref(start, _ctx);
        }
        _x_x1421 = _x_0; /*int32*/
      }
      j_0_10076 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1418, _x_x1421, _ctx); /*std/time/timestamp/timestamp*/
      bool _match_x1049;
      kk_std_core_types__order _x_x1423;
      kk_std_time_timestamp__timestamp _x_x1424 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
      _x_x1423 = kk_std_time_timestamp_cmp(_x_x1424, j_0_10076, _ctx); /*order*/
      _match_x1049 = kk_std_core_order__lp__eq__eq__rp_(_x_x1423, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
      if (_match_x1049) {
        return kk_std_time_timestamp__lp__dash__rp_(utc_0, diff, _ctx);
      }
      {
        kk_std_time_timestamp__timestamp _x_x1425 = kk_std_time_timestamp__lp__dash__rp_(utc_0, diff, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_timestamp_add_leap_seconds(_x_x1425, diff, _ctx);
      }
    }
  }
}
 
// Create a new time scale based on UTC seconds with a given `name`
// and a leap second table.


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1427__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_timescale_fun1427(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1427(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1427__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1427__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1427, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_timescale_fun1427(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1427__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1427__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_from_tai(leaps, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1429__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_std_time_duration__duration kk_std_time_utc_utc_timescale_fun1429(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1429(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1429__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1429__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1429, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_utc_timescale_fun1429(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1429__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1429__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_to_tai(leaps, utc_0, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1439__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_utc_timescale_fun1439(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1439(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1439__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1439__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1439, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_utc_timescale_fun1439(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1439__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1439__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp utc_0_0_81 = kk_std_time_timestamp__timestamp_unbox(_b_x58, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_core_types__tuple2 tuple2_10043 = kk_std_time_timestamp_days_seconds(utc_0_0_81, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_std_num_ddouble__ddouble _x_x1440;
  kk_std_core_types__maybe _match_x1046;
  kk_integer_t _x_x1441;
  {
    kk_box_t _box_x50 = tuple2_10043.fst;
    kk_box_t _box_x51 = tuple2_10043.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x50, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10043, _ctx);
    _x_x1441 = _x; /*int*/
  }
  _match_x1046 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1441, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x1046, _ctx)) {
    _x_x1440 = kk_std_time_timestamp_solar_secs_per_day; /*std/time/timestamp/timespan*/
  }
  else {
    kk_box_t _box_x52 = _match_x1046._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x52, KK_BORROWED, _ctx);
    kk_box_t _box_x53 = _pat_1_0.fst;
    kk_box_t _box_x54 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x53, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x54, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1442 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    kk_std_core_types__maybe_drop(_match_x1046, _ctx);
    _x_x1440 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/time/timestamp/timespan*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1440, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1448__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_utc_timescale_fun1448(kk_function_t _fself, kk_box_t _b_x64, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1448(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1448__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1448__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1448, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_utc_timescale_fun1448(kk_function_t _fself, kk_box_t _b_x64, kk_box_t _b_x65, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1448__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1448__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp utc_1_82 = kk_std_time_timestamp__timestamp_unbox(_b_x64, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_num_ddouble__ddouble tzdelta_83 = kk_std_num_ddouble__ddouble_unbox(_b_x65, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_num_ddouble__ddouble _x_x1449 = kk_std_time_utc_utc_to_mjd(leaps, utc_1_82, tzdelta_83, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1449, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1453__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_utc_timescale_fun1453(kk_function_t _fself, kk_box_t _b_x71, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1453(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1453__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1453__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1453, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_utc_timescale_fun1453(kk_function_t _fself, kk_box_t _b_x71, kk_box_t _b_x72, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1453__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1453__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_integer_t days_84 = kk_integer_unbox(_b_x71, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble frac_85 = kk_std_num_ddouble__ddouble_unbox(_b_x72, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_timestamp__timestamp _x_x1454 = kk_std_time_utc_utc_from_mjd(leaps, days_84, frac_85, _ctx); /*std/time/utc/utc-timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1454, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_utc_timescale(kk_string_t name, kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (name : string, leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_function_t _x_x1426;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1426 = kk_std_time_utc_new_utc_timescale_fun1427(leaps, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_function_t _x_x1428;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1428 = kk_std_time_utc_new_utc_timescale_fun1429(leaps, _ctx); /*(utc@0 : std/time/timestamp/timestamp) -> std/time/duration/duration*/
  kk_std_core_types__optional _x_x1430;
  kk_box_t _x_x1431;
  kk_string_t _x_x1432;
  kk_define_string_literal(, _s_x1433, 3, "UTC", _ctx)
  _x_x1432 = kk_string_dup(_s_x1433, _ctx); /*string*/
  _x_x1431 = kk_string_box(_x_x1432); /*7*/
  _x_x1430 = kk_std_core_types__new_Optional(_x_x1431, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1434;
  kk_box_t _x_x1435;
  kk_std_core_types__maybe _x_x1436;
  kk_box_t _x_x1437;
  kk_function_t _x_x1438;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1438 = kk_std_time_utc_new_utc_timescale_fun1439(leaps, _ctx); /*(56) -> 57*/
  _x_x1437 = kk_function_box(_x_x1438, _ctx); /*88*/
  _x_x1436 = kk_std_core_types__new_Just(_x_x1437, _ctx); /*maybe<88>*/
  _x_x1435 = kk_std_core_types__maybe_box(_x_x1436, _ctx); /*7*/
  _x_x1434 = kk_std_core_types__new_Optional(_x_x1435, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1443;
  kk_box_t _x_x1444;
  kk_std_core_types__maybe _x_x1445;
  kk_box_t _x_x1446;
  kk_function_t _x_x1447;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1447 = kk_std_time_utc_new_utc_timescale_fun1448(leaps, _ctx); /*(61, 62) -> 63*/
  _x_x1446 = kk_function_box(_x_x1447, _ctx); /*88*/
  _x_x1445 = kk_std_core_types__new_Just(_x_x1446, _ctx); /*maybe<88>*/
  _x_x1444 = kk_std_core_types__maybe_box(_x_x1445, _ctx); /*7*/
  _x_x1443 = kk_std_core_types__new_Optional(_x_x1444, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1450;
  kk_box_t _x_x1451;
  kk_std_core_types__maybe _x_x1452 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_utc_new_utc_timescale_fun1453(leaps, _ctx), _ctx), _ctx); /*maybe<88>*/
  _x_x1451 = kk_std_core_types__maybe_box(_x_x1452, _ctx); /*7*/
  _x_x1450 = kk_std_core_types__new_Optional(_x_x1451, _ctx); /*? 7*/
  return kk_std_time_instant_timescale(name, _x_x1426, _x_x1428, _x_x1430, _x_x1434, _x_x1443, _x_x1450, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_upto_fun1457__t {
  struct kk_function_s _base;
  kk_std_time_timestamp__timestamp end;
};
static bool kk_std_time_utc_upto_fun1457(kk_function_t _fself, kk_box_t _b_x88, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_upto_fun1457(kk_std_time_timestamp__timestamp end, kk_context_t* _ctx) {
  struct kk_std_time_utc_upto_fun1457__t* _self = kk_function_alloc_as(struct kk_std_time_utc_upto_fun1457__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_upto_fun1457, kk_context());
  _self->end = end;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_utc_upto_fun1457(kk_function_t _fself, kk_box_t _b_x88, kk_context_t* _ctx) {
  struct kk_std_time_utc_upto_fun1457__t* _self = kk_function_as(struct kk_std_time_utc_upto_fun1457__t*, _fself, _ctx);
  kk_std_time_timestamp__timestamp end = _self->end; /* std/time/utc/utc-timestamp */
  kk_drop_match(_self, {kk_std_time_timestamp__timestamp_dup(end, _ctx);}, {}, _ctx)
  kk_std_core_types__order _x_x1458;
  kk_std_time_timestamp__timestamp _x_x1459;
  kk_std_time_utc__leap_adjust _match_x1045 = kk_std_time_utc__leap_adjust_unbox(_b_x88, KK_OWNED, _ctx); /*std/time/utc/leap-adjust*/;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1460 = kk_std_time_utc__as_Leap_adjust(_match_x1045, _ctx);
    kk_std_time_timestamp__timestamp _x_0 = _con_x1460->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_0 = _con_x1460->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x1460->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1460->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1461 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1462 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1045, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5, _ctx)) {
        kk_datatype_ptr_free(_pat_5, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5, _ctx);
      }
      kk_datatype_ptr_free(_match_x1045, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x1045, _ctx);
    }
    _x_x1459 = _x_0; /*std/time/utc/utc-timestamp*/
  }
  _x_x1458 = kk_std_time_timestamp_cmp(_x_x1459, end, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x1458, kk_std_core_types__new_Gt(_ctx), _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_upto(kk_std_time_utc__leaps_table lt, kk_std_time_timestamp__timestamp end, kk_context_t* _ctx) { /* (lt : leaps-table, end : utc-timestamp) -> leaps-table */ 
  kk_std_core_types__list _b_x89_90;
  kk_std_core_types__list _x_x1455;
  {
    struct kk_std_time_utc_Leaps_table* _con_x1456 = kk_std_time_utc__as_Leaps_table(lt, _ctx);
    kk_std_time_instant__instant _pat_0 = _con_x1456->expire;
    kk_std_core_types__list _x = _con_x1456->adjusts;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x1455 = _x; /*list<std/time/utc/leap-adjust>*/
  }
  _b_x89_90 = kk_std_core_list_drop_while(_x_x1455, kk_std_time_utc_new_upto_fun1457(end, _ctx), _ctx); /*list<std/time/utc/leap-adjust>*/
  kk_std_time_instant__instant _x_x1463;
  kk_std_core_types__optional _match_x1044 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1044, _ctx)) {
    kk_box_t _box_x94 = _match_x1044._cons._Optional.value;
    kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x94, KK_BORROWED, _ctx);
    kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
    kk_std_core_types__optional_drop(_match_x1044, _ctx);
    _x_x1463 = _uniq_expire_375; /*std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1044, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1464 = kk_std_time_utc__as_Leaps_table(lt, _ctx);
      kk_std_time_instant__instant _x_1 = _con_x1464->expire;
      kk_std_time_instant__instant_dup(_x_1, _ctx);
      _x_x1463 = _x_1; /*std/time/instant/instant*/
    }
  }
  kk_std_core_types__list _x_x1465;
  kk_std_core_types__optional _match_x1043 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x89_90, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x1043, _ctx)) {
    kk_box_t _box_x95 = _match_x1043._cons._Optional.value;
    kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x95, KK_BORROWED, _ctx);
    kk_datatype_ptr_dropn(lt, (KK_I32(3)), _ctx);
    kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
    kk_std_core_types__optional_drop(_match_x1043, _ctx);
    _x_x1465 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1043, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1466 = kk_std_time_utc__as_Leaps_table(lt, _ctx);
      kk_std_time_instant__instant _pat_0_3 = _con_x1466->expire;
      kk_std_core_types__list _x_2 = _con_x1466->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(lt, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(lt, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(lt, _ctx);
      }
      _x_x1465 = _x_2; /*list<std/time/utc/leap-adjust>*/
    }
  }
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x1463, _x_x1465, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_extend_fun1478__t {
  struct kk_function_s _base;
  kk_std_time_timestamp__timestamp end_10222;
};
static bool kk_std_time_utc_extend_fun1478(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_extend_fun1478(kk_std_time_timestamp__timestamp end_10222, kk_context_t* _ctx) {
  struct kk_std_time_utc_extend_fun1478__t* _self = kk_function_alloc_as(struct kk_std_time_utc_extend_fun1478__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_extend_fun1478, kk_context());
  _self->end_10222 = end_10222;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_utc_extend_fun1478(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  struct kk_std_time_utc_extend_fun1478__t* _self = kk_function_as(struct kk_std_time_utc_extend_fun1478__t*, _fself, _ctx);
  kk_std_time_timestamp__timestamp end_10222 = _self->end_10222; /* std/time/utc/utc-timestamp */
  kk_drop_match(_self, {kk_std_time_timestamp__timestamp_dup(end_10222, _ctx);}, {}, _ctx)
  kk_std_core_types__order _x_x1479;
  kk_std_time_timestamp__timestamp _x_x1480;
  kk_std_time_utc__leap_adjust _match_x1042 = kk_std_time_utc__leap_adjust_unbox(_b_x99, KK_OWNED, _ctx); /*std/time/utc/leap-adjust*/;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1481 = kk_std_time_utc__as_Leap_adjust(_match_x1042, _ctx);
    kk_std_time_timestamp__timestamp _x_0_0 = _con_x1481->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_0_0 = _con_x1481->offset;
    kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1481->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1481->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1482 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1483 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1042, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x1042, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_0_0, _ctx);
      kk_datatype_ptr_decref(_match_x1042, _ctx);
    }
    _x_x1480 = _x_0_0; /*std/time/utc/utc-timestamp*/
  }
  _x_x1479 = kk_std_time_timestamp_cmp(_x_x1480, end_10222, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x1479, kk_std_core_types__new_Gt(_ctx), _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_extend(kk_std_time_utc__leaps_table leap1, kk_std_time_utc__leaps_table leap2, kk_context_t* _ctx) { /* (leap1 : leaps-table, leap2 : leaps-table) -> leaps-table */ 
  kk_std_core_types__list _match_x1035;
  kk_std_core_types__list _x_x1467;
  {
    struct kk_std_time_utc_Leaps_table* _con_x1468 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
    kk_std_time_instant__instant _pat_0 = _con_x1468->expire;
    kk_std_core_types__list _x = _con_x1468->adjusts;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x1467 = _x; /*list<std/time/utc/leap-adjust>*/
  }
  _match_x1035 = kk_std_core_list_reverse_acc(kk_std_core_types__new_Nil(_ctx), _x_x1467, _ctx); /*list<1037>*/
  if (kk_std_core_types__is_Nil(_match_x1035, _ctx)) {
    kk_datatype_ptr_dropn(leap1, (KK_I32(3)), _ctx);
    return leap2;
  }
  {
    struct kk_std_core_types_Cons* _con_x1469 = kk_std_core_types__as_Cons(_match_x1035, _ctx);
    kk_box_t _box_x96 = _con_x1469->head;
    kk_std_time_utc__leap_adjust la = kk_std_time_utc__leap_adjust_unbox(_box_x96, KK_BORROWED, _ctx);
    struct kk_std_time_utc_Leap_adjust* _con_x1470 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_core_types__list _pat_5 = _con_x1469->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1035, _ctx)) {
      kk_std_core_types__list_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(_match_x1035, _ctx);
    }
    else {
      kk_std_time_utc__leap_adjust_dup(la, _ctx);
      kk_datatype_ptr_decref(_match_x1035, _ctx);
    }
    kk_std_time_timestamp__timestamp end_10222;
    kk_std_time_timestamp__timestamp _x_x1471;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1472 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _x_2_0 = _con_x1472->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_3_0 = _con_x1472->offset;
      kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x1472->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1472->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1473 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1474 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_0, _ctx)) {
          kk_datatype_ptr_free(_pat_5_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_0_0, _ctx);
        }
        kk_datatype_ptr_free(la, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_2_0, _ctx);
        kk_datatype_ptr_decref(la, _ctx);
      }
      _x_x1471 = _x_2_0; /*std/time/utc/utc-timestamp*/
    }
    kk_std_num_ddouble__ddouble _x_x1475 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_small(1), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
    end_10222 = kk_std_time_timestamp__lp__dash__rp_(_x_x1471, _x_x1475, _ctx); /*std/time/utc/utc-timestamp*/
    kk_std_core_types__list _b_x100_101;
    kk_std_core_types__list _x_x1476;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1477 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
      kk_std_time_instant__instant _pat_0_1 = _con_x1477->expire;
      kk_std_core_types__list _x_0 = _con_x1477->adjusts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x1476 = _x_0; /*list<std/time/utc/leap-adjust>*/
    }
    _b_x100_101 = kk_std_core_list_drop_while(_x_x1476, kk_std_time_utc_new_extend_fun1478(end_10222, _ctx), _ctx); /*list<std/time/utc/leap-adjust>*/
    kk_std_core_types__list _b_x107_108;
    kk_std_core_types__list _x_x1484;
    {
      struct kk_std_time_utc_Leaps_table* _con_x1485 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
      kk_std_time_instant__instant _pat_0_1_1 = _con_x1485->expire;
      kk_std_core_types__list _x_0_1 = _con_x1485->adjusts;
      kk_std_core_types__list_dup(_x_0_1, _ctx);
      _x_x1484 = _x_0_1; /*list<std/time/utc/leap-adjust>*/
    }
    kk_std_core_types__list _x_x1486;
    kk_std_time_instant__instant _match_x1039;
    kk_std_core_types__optional _match_x1041 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1041, _ctx)) {
      kk_box_t _box_x105 = _match_x1041._cons._Optional.value;
      kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x105, KK_BORROWED, _ctx);
      kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
      kk_std_core_types__optional_drop(_match_x1041, _ctx);
      _match_x1039 = _uniq_expire_375; /*std/time/instant/instant*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1041, _ctx);
      {
        struct kk_std_time_utc_Leaps_table* _con_x1487 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
        kk_std_time_instant__instant _x_1 = _con_x1487->expire;
        kk_std_time_instant__instant_dup(_x_1, _ctx);
        _match_x1039 = _x_1; /*std/time/instant/instant*/
      }
    }
    kk_std_core_types__list _match_x1038;
    kk_std_core_types__optional _match_x1040 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x100_101, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x1040, _ctx)) {
      kk_box_t _box_x106 = _match_x1040._cons._Optional.value;
      kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x106, KK_BORROWED, _ctx);
      kk_datatype_ptr_dropn(leap2, (KK_I32(3)), _ctx);
      kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
      kk_std_core_types__optional_drop(_match_x1040, _ctx);
      _match_x1038 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1040, _ctx);
      {
        struct kk_std_time_utc_Leaps_table* _con_x1488 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
        kk_std_time_instant__instant _pat_0_3 = _con_x1488->expire;
        kk_std_core_types__list _x_2 = _con_x1488->adjusts;
        if kk_likely(kk_datatype_ptr_is_unique(leap2, _ctx)) {
          kk_std_time_instant__instant_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(leap2, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_2, _ctx);
          kk_datatype_ptr_decref(leap2, _ctx);
        }
        _match_x1038 = _x_2; /*list<std/time/utc/leap-adjust>*/
      }
    }
    {
      kk_std_time_instant__instant_drop(_match_x1039, _ctx);
      _x_x1486 = _match_x1038; /*list<std/time/utc/leap-adjust>*/
    }
    _b_x107_108 = kk_std_core_list_append(_x_x1484, _x_x1486, _ctx); /*list<std/time/utc/leap-adjust>*/
    kk_std_time_instant__instant _x_x1489;
    kk_std_core_types__optional _match_x1037 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1037, _ctx)) {
      kk_box_t _box_x109 = _match_x1037._cons._Optional.value;
      kk_std_time_instant__instant _uniq_expire_375_0 = kk_std_time_instant__instant_unbox(_box_x109, KK_BORROWED, _ctx);
      kk_std_time_instant__instant_dup(_uniq_expire_375_0, _ctx);
      kk_std_core_types__optional_drop(_match_x1037, _ctx);
      _x_x1489 = _uniq_expire_375_0; /*std/time/instant/instant*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1037, _ctx);
      {
        struct kk_std_time_utc_Leaps_table* _con_x1490 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
        kk_std_time_instant__instant _x_3 = _con_x1490->expire;
        kk_std_time_instant__instant_dup(_x_3, _ctx);
        _x_x1489 = _x_3; /*std/time/instant/instant*/
      }
    }
    kk_std_core_types__list _x_x1491;
    kk_std_core_types__optional _match_x1036 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x107_108, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x1036, _ctx)) {
      kk_box_t _box_x110 = _match_x1036._cons._Optional.value;
      kk_std_core_types__list _uniq_adjusts_383_0 = kk_std_core_types__list_unbox(_box_x110, KK_BORROWED, _ctx);
      kk_datatype_ptr_dropn(leap1, (KK_I32(3)), _ctx);
      kk_std_core_types__list_dup(_uniq_adjusts_383_0, _ctx);
      kk_std_core_types__optional_drop(_match_x1036, _ctx);
      _x_x1491 = _uniq_adjusts_383_0; /*list<std/time/utc/leap-adjust>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1036, _ctx);
      {
        struct kk_std_time_utc_Leaps_table* _con_x1492 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
        kk_std_time_instant__instant _pat_0_6 = _con_x1492->expire;
        kk_std_core_types__list _x_4 = _con_x1492->adjusts;
        if kk_likely(kk_datatype_ptr_is_unique(leap1, _ctx)) {
          kk_std_time_instant__instant_drop(_pat_0_6, _ctx);
          kk_datatype_ptr_free(leap1, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_4, _ctx);
          kk_datatype_ptr_decref(leap1, _ctx);
        }
        _x_x1491 = _x_4; /*list<std/time/utc/leap-adjust>*/
      }
    }
    return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x1489, _x_x1491, _ctx);
  }
}
kk_declare_string_literal(static, kk_std_time_utc_default_iers_leap_seconds, 1125, "\n  # From: https://hpiers.obspm.fr/iers/bul/bulc/ntp/leap-seconds.list\n  #\tUpdated through IERS Bulletin C (https://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat)\n  # File expires on:  28 December 2024\n  #\n  #@\t3944332800\n  #\n  2272060800  10  # 1 Jan 1972\n  2287785600  11  # 1 Jul 1972\n  2303683200  12  # 1 Jan 1973\n  2335219200  13  # 1 Jan 1974\n  2366755200  14  # 1 Jan 1975\n  2398291200  15  # 1 Jan 1976\n  2429913600  16  # 1 Jan 1977\n  2461449600  17  # 1 Jan 1978\n  2492985600  18  # 1 Jan 1979\n  2524521600  19  # 1 Jan 1980\n  2571782400  20  # 1 Jul 1981\n  2603318400  21  # 1 Jul 1982\n  2634854400  22  # 1 Jul 1983\n  2698012800  23  # 1 Jul 1985\n  2776982400  24  # 1 Jan 1988\n  2840140800  25  # 1 Jan 1990\n  2871676800  26  # 1 Jan 1991\n  2918937600  27  # 1 Jul 1992\n  2950473600  28  # 1 Jul 1993\n  2982009600  29  # 1 Jul 1994\n  3029443200  30  # 1 Jan 1996\n  3076704000  31  # 1 Jul 1997\n  3124137600  32  # 1 Jan 1999\n  3345062400  33  # 1 Jan 2006\n  3439756800  34  # 1 Jan 2009\n  3550089600  35  # 1 Jul 2012\n  3644697600  36  # 1 Jul 2015\n  3692217600  37  # 1 Jan 2017\n  // 3723753600  35  # 1 Jan 2018")

kk_std_num_ddouble__ddouble kk_std_time_utc_jd_epoch_shift;
 
// JD to MJD

kk_std_num_ddouble__ddouble kk_std_time_utc_mjd_epoch_shift;
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10316_fun1494__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10316_fun1494(kk_function_t _fself, kk_box_t _b_x114, kk_box_t _b_x115, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10316_fun1494(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10316_fun1494, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10316_fun1494(kk_function_t _fself, kk_box_t _b_x114, kk_box_t _b_x115, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1495;
  kk_std_num_ddouble__ddouble _x_x1496 = kk_std_num_ddouble__ddouble_unbox(_b_x114, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1497;
  double _x_x1498;
  double _x_x1499;
  kk_std_num_ddouble__ddouble _match_x1034;
  kk_box_t _x_x1500 = kk_box_dup(_b_x115, _ctx); /*9984*/
  _match_x1034 = kk_std_num_ddouble__ddouble_unbox(_x_x1500, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = _match_x1034.hi;
    _x_x1499 = _x; /*float64*/
  }
  _x_x1498 = (-_x_x1499); /*float64*/
  double _x_x1501;
  double _x_x1502;
  kk_std_num_ddouble__ddouble _match_x1033 = kk_std_num_ddouble__ddouble_unbox(_b_x115, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0 = _match_x1033.lo;
    _x_x1502 = _x_0; /*float64*/
  }
  _x_x1501 = (-_x_x1502); /*float64*/
  _x_x1497 = kk_std_num_ddouble__new_Ddouble(_x_x1498, _x_x1501, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1495 = kk_std_num_ddouble__lp__plus__rp_(_x_x1496, _x_x1497, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1495, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10316_fun1504__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10316_fun1504(kk_function_t _fself, kk_box_t _b_x125, kk_box_t _b_x126, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10316_fun1504(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10316_fun1504, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10316_fun1504(kk_function_t _fself, kk_box_t _b_x125, kk_box_t _b_x126, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble t_130 = kk_std_num_ddouble__ddouble_unbox(_b_x125, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_core_types__optional leap_0_131 = kk_std_core_types__optional_unbox(_b_x126, KK_OWNED, _ctx); /*? int*/;
  kk_std_time_timestamp__timestamp _x_x1505;
  int32_t _x_x1506;
  kk_integer_t _x_x1507;
  if (kk_std_core_types__is_Optional(leap_0_131, _ctx)) {
    kk_box_t _box_x121 = leap_0_131._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x121, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(leap_0_131, _ctx);
    _x_x1507 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0_131, _ctx);
    _x_x1507 = kk_integer_from_small(0); /*int*/
  }
  _x_x1506 = kk_integer_clamp32(_x_x1507,kk_context()); /*int32*/
  _x_x1505 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_130, _x_x1506, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1505, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10316(kk_std_num_ddouble__ddouble ntpex, kk_context_t* _ctx) { /* (ntpex : std/num/ddouble/ddouble) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_std_num_ddouble__ddouble _x_x1_10280;
  kk_box_t _x_x1493 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_pexpire_10316_fun1494(_ctx), kk_std_num_ddouble__ddouble_box(ntpex, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_ntp2000, _ctx), _ctx); /*9985*/
  _x_x1_10280 = kk_std_num_ddouble__ddouble_unbox(_x_x1493, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_box_t _x_x1503 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_pexpire_10316_fun1504(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_10280, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  return kk_std_time_timestamp__timestamp_unbox(_x_x1503, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10317_fun1509__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10317_fun1509(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10317_fun1509(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10317_fun1509, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10317_fun1509(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1510 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1510, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10317_fun1511__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10317_fun1511(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10317_fun1511(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10317_fun1511, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10317_fun1511(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1512 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1512, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10317_fun1514__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10317_fun1514(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10317_fun1514(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10317_fun1514, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10317_fun1514(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1515;
  kk_std_num_ddouble__ddouble _x_x1516 = kk_std_num_ddouble__ddouble_unbox(_b_x137, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1515 = kk_std_time_utc__mlift_pexpire_10316(_x_x1516, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1515, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10317(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild___1, _ctx);
  kk_std_num_ddouble__ddouble x_10348;
  kk_box_t _x_x1508 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc__new_mlift_pexpire_10317_fun1509(_ctx), kk_std_time_utc__new_mlift_pexpire_10317_fun1511(_ctx), _ctx); /*1542*/
  x_10348 = kk_std_num_ddouble__ddouble_unbox(_x_x1508, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1513 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pexpire_10317_fun1514(_ctx), _ctx); /*2419*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1513, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pexpire_10316(x_10348, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10318_fun1518__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10318_fun1518(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10318_fun1518(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10318_fun1518, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10318_fun1518(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1519;
  kk_string_t _x_x1520 = kk_string_unbox(_b_x140); /*string*/
  _x_x1519 = kk_std_time_utc__mlift_pexpire_10317(_x_x1520, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1519, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10318(kk_string_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild___0, _ctx);
  kk_string_t x_10350 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10350, _ctx);
    kk_box_t _x_x1517 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pexpire_10318_fun1518(_ctx), _ctx); /*2419*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1517, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pexpire_10317(x_10350, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10319_fun1524__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10319_fun1524(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10319_fun1524(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10319_fun1524, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10319_fun1524(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1525;
  kk_string_t _x_x1526 = kk_string_unbox(_b_x143); /*string*/
  _x_x1525 = kk_std_time_utc__mlift_pexpire_10318(_x_x1526, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1525, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10319(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild__, _ctx);
  kk_string_t x_10352;
  kk_string_t _x_x1521;
  kk_define_string_literal(, _s_x1522, 2, "#@", _ctx)
  _x_x1521 = kk_string_dup(_s_x1522, _ctx); /*string*/
  x_10352 = kk_std_text_parse_pstring(_x_x1521, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10352, _ctx);
    kk_box_t _x_x1523 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pexpire_10319_fun1524(_ctx), _ctx); /*2419*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1523, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pexpire_10318(x_10352, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1528__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1528(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1528(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1528, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1528(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1529;
  kk_string_t _x_x1530 = kk_string_unbox(_b_x146); /*string*/
  _x_x1529 = kk_std_time_utc__mlift_pexpire_10319(_x_x1530, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1529, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1534__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1534(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1534(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1534, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1534(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1535;
  kk_string_t _x_x1536 = kk_string_unbox(_b_x148); /*string*/
  _x_x1535 = kk_std_time_utc__mlift_pexpire_10318(_x_x1536, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1535, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1538__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1538(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1538(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1538, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1538(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1539;
  kk_string_t _x_x1540 = kk_string_unbox(_b_x150); /*string*/
  _x_x1539 = kk_std_time_utc__mlift_pexpire_10317(_x_x1540, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1539, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1542__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1542(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1542(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1542, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1542(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1543 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1543, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1544__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1544(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1544(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1544, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1544(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1545 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1545, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1547__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1547(kk_function_t _fself, kk_box_t _b_x156, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1547(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1547, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1547(kk_function_t _fself, kk_box_t _b_x156, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1548;
  kk_std_num_ddouble__ddouble _x_x1549 = kk_std_num_ddouble__ddouble_unbox(_b_x156, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1548 = kk_std_time_utc__mlift_pexpire_10316(_x_x1549, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1548, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1551(kk_function_t _fself, kk_box_t _b_x160, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1551(kk_function_t _fself, kk_box_t _b_x160, kk_box_t _b_x161, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1552;
  kk_std_num_ddouble__ddouble _x_x1553 = kk_std_num_ddouble__ddouble_unbox(_b_x160, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1554;
  double _x_x1555;
  double _x_x1556;
  kk_std_num_ddouble__ddouble _match_x1029;
  kk_box_t _x_x1557 = kk_box_dup(_b_x161, _ctx); /*9984*/
  _match_x1029 = kk_std_num_ddouble__ddouble_unbox(_x_x1557, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = _match_x1029.hi;
    _x_x1556 = _x; /*float64*/
  }
  _x_x1555 = (-_x_x1556); /*float64*/
  double _x_x1558;
  double _x_x1559;
  kk_std_num_ddouble__ddouble _match_x1028 = kk_std_num_ddouble__ddouble_unbox(_b_x161, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0 = _match_x1028.lo;
    _x_x1559 = _x_0; /*float64*/
  }
  _x_x1558 = (-_x_x1559); /*float64*/
  _x_x1554 = kk_std_num_ddouble__new_Ddouble(_x_x1555, _x_x1558, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1552 = kk_std_num_ddouble__lp__plus__rp_(_x_x1553, _x_x1554, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1552, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1561__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1561(kk_function_t _fself, kk_box_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1561(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1561, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1561(kk_function_t _fself, kk_box_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble t_180 = kk_std_num_ddouble__ddouble_unbox(_b_x171, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_core_types__optional leap_0_181 = kk_std_core_types__optional_unbox(_b_x172, KK_OWNED, _ctx); /*? int*/;
  kk_std_time_timestamp__timestamp _x_x1562;
  int32_t _x_x1563;
  kk_integer_t _x_x1564;
  if (kk_std_core_types__is_Optional(leap_0_181, _ctx)) {
    kk_box_t _box_x167 = leap_0_181._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x167, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(leap_0_181, _ctx);
    _x_x1564 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap_0_181, _ctx);
    _x_x1564 = kk_integer_from_small(0); /*int*/
  }
  _x_x1563 = kk_integer_clamp32(_x_x1564,kk_context()); /*int32*/
  _x_x1562 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_180, _x_x1563, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1562, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc_pexpire(kk_context_t* _ctx) { /* () -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_t x_10354 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_string_drop(x_10354, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1527 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1528(_ctx), _ctx); /*2419*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1527, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_10357;
    kk_string_t _x_x1531;
    kk_define_string_literal(, _s_x1532, 2, "#@", _ctx)
    _x_x1531 = kk_string_dup(_s_x1532, _ctx); /*string*/
    x_0_10357 = kk_std_text_parse_pstring(_x_x1531, _ctx); /*string*/
    kk_string_drop(x_0_10357, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1533 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1534(_ctx), _ctx); /*2419*/
      return kk_std_time_timestamp__timestamp_unbox(_x_x1533, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_10360 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
      kk_string_drop(x_1_10360, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1537 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1538(_ctx), _ctx); /*2419*/
        return kk_std_time_timestamp__timestamp_unbox(_x_x1537, KK_OWNED, _ctx);
      }
      {
        kk_std_num_ddouble__ddouble x_2_10363;
        kk_box_t _x_x1541 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc_new_pexpire_fun1542(_ctx), kk_std_time_utc_new_pexpire_fun1544(_ctx), _ctx); /*1542*/
        x_2_10363 = kk_std_num_ddouble__ddouble_unbox(_x_x1541, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1546 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1547(_ctx), _ctx); /*2419*/
          return kk_std_time_timestamp__timestamp_unbox(_x_x1546, KK_OWNED, _ctx);
        }
        {
          kk_std_num_ddouble__ddouble _x_x1_10280;
          kk_box_t _x_x1550 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_pexpire_fun1551(_ctx), kk_std_num_ddouble__ddouble_box(x_2_10363, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_ntp2000, _ctx), _ctx); /*9985*/
          _x_x1_10280 = kk_std_num_ddouble__ddouble_unbox(_x_x1550, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
          kk_box_t _x_x1560 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_pexpire_fun1561(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_10280, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
          return kk_std_time_timestamp__timestamp_unbox(_x_x1560, KK_OWNED, _ctx);
        }
      }
    }
  }
}
 
// val rxexpire = regex(r"^[ \t]*#@[ \t]*(\d+)[ \t]*(?:#.*)?$", multiLine=True)


// lift anonymous function
struct kk_std_time_utc_parse_expire_fun1573__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_expire_fun1573(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_expire_fun1573(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_expire_fun1573, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_parse_expire_fun1573(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1574 = kk_std_time_utc_pexpire(_ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1574, _ctx);
}

kk_std_core_types__maybe kk_std_time_utc_parse_expire(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> maybe<std/time/timestamp/timestamp> */ 
  kk_std_core_types__maybe maybe_10101;
  kk_string_t _x_x1565;
  kk_string_t _x_x1566 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x1567;
  kk_define_string_literal(, _s_x1568, 1, " ", _ctx)
  _x_x1567 = kk_string_dup(_s_x1568, _ctx); /*string*/
  _x_x1565 = kk_std_core_sslice_trim_left(_x_x1566, _x_x1567, _ctx); /*string*/
  kk_string_t _x_x1569;
  kk_define_string_literal(, _s_x1570, 2, "#@", _ctx)
  _x_x1569 = kk_string_dup(_s_x1570, _ctx); /*string*/
  maybe_10101 = kk_std_core_sslice_starts_with(_x_x1565, _x_x1569, _ctx); /*maybe<sslice/sslice>*/
  if (kk_std_core_types__is_Just(maybe_10101, _ctx)) {
    kk_box_t _box_x182 = maybe_10101._cons.Just.value;
    kk_std_core_types__maybe_drop(maybe_10101, _ctx);
    kk_std_core_sslice__sslice _b_x183_185;
    kk_string_t _x_x1571 = kk_string_dup(line, _ctx); /*string*/
    kk_integer_t _x_x1572 = kk_string_len_int(line,kk_context()); /*int*/
    _b_x183_185 = kk_std_core_sslice__new_Sslice(_x_x1571, kk_integer_from_small(0), _x_x1572, _ctx); /*sslice/sslice*/
    kk_std_text_parse__parse_error perr_10102 = kk_std_text_parse_parse(_b_x183_185, kk_std_time_utc_new_parse_expire_fun1573(_ctx), _ctx); /*std/text/parse/parse-error<std/time/timestamp/timestamp>*/;
    if (kk_std_text_parse__is_ParseOk(perr_10102, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x1575 = kk_std_text_parse__as_ParseOk(perr_10102, _ctx);
      kk_box_t _box_x187 = _con_x1575->result;
      kk_std_core_sslice__sslice _pat_0_0 = _con_x1575->rest;
      kk_std_time_timestamp__timestamp x_0 = kk_std_time_timestamp__timestamp_unbox(_box_x187, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10102, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(perr_10102, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(x_0, _ctx);
        kk_datatype_ptr_decref(perr_10102, _ctx);
      }
      return kk_std_core_types__new_Just(kk_std_time_timestamp__timestamp_box(x_0, _ctx), _ctx);
    }
    {
      struct kk_std_text_parse_ParseError* _con_x1576 = kk_std_text_parse__as_ParseError(perr_10102, _ctx);
      kk_std_core_sslice__sslice _pat_5 = _con_x1576->rest;
      kk_string_t msg = _con_x1576->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10102, _ctx)) {
        kk_string_drop(msg, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(perr_10102, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10102, _ctx);
      }
      return kk_std_core_types__new_Nothing(_ctx);
    }
  }
  {
    kk_string_drop(line, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_parse_leap_expire_fun1579__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_utc_parse_leap_expire_fun1579(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_leap_expire_fun1579(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_leap_expire_fun1579, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_utc_parse_leap_expire_fun1579(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1580 = kk_string_unbox(_b_x192); /*string*/
  return kk_std_time_utc_parse_expire(_x_x1580, _ctx);
}

kk_std_time_instant__instant kk_std_time_utc_parse_leap_expire(kk_string_t leaps, kk_std_core_types__list adjusts, kk_context_t* _ctx) { /* (leaps : string, adjusts : list<leap-adjust>) -> std/time/instant/instant */ 
  kk_vector_t v_10011;
  kk_string_t _x_x1577;
  kk_define_string_literal(, _s_x1578, 1, "\n", _ctx)
  _x_x1577 = kk_string_dup(_s_x1578, _ctx); /*string*/
  v_10011 = kk_string_splitv(leaps,_x_x1577,kk_context()); /*vector<string>*/
  kk_std_core_types__list _b_x190_193 = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  kk_std_core_types__list utc_expires = kk_std_core_list_flatmap_maybe(_b_x190_193, kk_std_time_utc_new_parse_leap_expire_fun1579(_ctx), _ctx); /*list<std/time/timestamp/timestamp>*/;
  kk_std_num_ddouble__ddouble t_10112;
  kk_integer_t _x_x1581 = kk_integer_mul((kk_integer_from_small(182)),(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/
  t_10112 = kk_std_time_timestamp_int_fs_timespan(_x_x1581, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp nothing_0_10109;
  kk_std_num_ddouble__ddouble _x_x1582;
  kk_std_num_ddouble__ddouble _x_x1583;
  kk_std_time_utc__leap_adjust _match_x1023;
  if (kk_std_core_types__is_Cons(adjusts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1584 = kk_std_core_types__as_Cons(adjusts, _ctx);
    kk_box_t _box_x195 = _con_x1584->head;
    kk_std_time_utc__leap_adjust x_0 = kk_std_time_utc__leap_adjust_unbox(_box_x195, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(x_0, _ctx);
    _match_x1023 = x_0; /*std/time/utc/leap-adjust*/
  }
  else {
    _match_x1023 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1585 = kk_std_time_utc__as_Leap_adjust(_match_x1023, _ctx);
    kk_std_time_timestamp__timestamp _x_1 = _con_x1585->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_1 = _con_x1585->offset;
    kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1585->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1585->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1586 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1587 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1023, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x1023, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x1023, _ctx);
    }
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1588 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1588->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1583 = _x; /*std/time/timestamp/timespan*/
    }
  }
  _x_x1582 = kk_std_num_ddouble__lp__plus__rp_(_x_x1583, t_10112, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1589;
  kk_std_time_utc__leap_adjust _match_x1022;
  if (kk_std_core_types__is_Cons(adjusts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1590 = kk_std_core_types__as_Cons(adjusts, _ctx);
    kk_box_t _box_x197 = _con_x1590->head;
    kk_std_time_utc__leap_adjust x_0_0 = kk_std_time_utc__leap_adjust_unbox(_box_x197, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(x_0_0, _ctx);
    _match_x1022 = x_0_0; /*std/time/utc/leap-adjust*/
  }
  else {
    _match_x1022 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1591 = kk_std_time_utc__as_Leap_adjust(_match_x1022, _ctx);
    kk_std_time_timestamp__timestamp _x_1_0 = _con_x1591->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_1_0 = _con_x1591->offset;
    kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x1591->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1591->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1592 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1593 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1022, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_0_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_0_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x1022, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(_match_x1022, _ctx);
    }
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1594 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x1594->since;
      int32_t _x_0 = _con_x1594->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1589 = _x_0; /*int32*/
    }
  }
  nothing_0_10109 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1582, _x_x1589, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp ts_1_10116;
  kk_std_time_timestamp__timestamp _x_x1595;
  if (kk_std_core_types__is_Cons(utc_expires, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1596 = kk_std_core_types__as_Cons(utc_expires, _ctx);
    kk_box_t _box_x199 = _con_x1596->head;
    kk_std_core_types__list _pat_0_2 = _con_x1596->tail;
    kk_std_time_timestamp__timestamp x_2 = kk_std_time_timestamp__timestamp_unbox(_box_x199, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(utc_expires, _ctx)) {
      kk_std_core_types__list_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(utc_expires, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(x_2, _ctx);
      kk_datatype_ptr_decref(utc_expires, _ctx);
    }
    kk_std_time_timestamp__timestamp_drop(nothing_0_10109, _ctx);
    _x_x1595 = x_2; /*std/time/timestamp/timestamp*/
  }
  else {
    _x_x1595 = nothing_0_10109; /*std/time/timestamp/timestamp*/
  }
  ts_1_10116 = kk_std_time_timestamp__lp__dash__rp_(_x_x1595, kk_std_time_utc_ntp2000, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp t_0_10115;
  kk_std_num_ddouble__ddouble _x_x1597;
  kk_std_num_ddouble__ddouble _x_x1598;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1599 = kk_std_time_timestamp__as_Timestamp(ts_1_10116, _ctx);
    kk_std_num_ddouble__ddouble _x_2 = _con_x1599->since;
    _x_x1598 = _x_2; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1600;
  kk_std_time_utc__leap_adjust _match_x1021;
  if (kk_std_core_types__is_Cons(adjusts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1601 = kk_std_core_types__as_Cons(adjusts, _ctx);
    kk_box_t _box_x201 = _con_x1601->head;
    kk_std_core_types__list _pat_0_0_1 = _con_x1601->tail;
    kk_std_time_utc__leap_adjust x_0_1 = kk_std_time_utc__leap_adjust_unbox(_box_x201, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(adjusts, _ctx)) {
      kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(adjusts, _ctx);
    }
    else {
      kk_std_time_utc__leap_adjust_dup(x_0_1, _ctx);
      kk_datatype_ptr_decref(adjusts, _ctx);
    }
    _match_x1021 = x_0_1; /*std/time/utc/leap-adjust*/
  }
  else {
    _match_x1021 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1602 = kk_std_time_utc__as_Leap_adjust(_match_x1021, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_6_0 = _con_x1602->utc_start;
    kk_std_num_ddouble__ddouble _x_3 = _con_x1602->offset;
    kk_std_time_timestamp__timestamp _pat_5_1_0 = _con_x1602->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1602->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1603 = kk_std_time_timestamp__as_Timestamp(_pat_0_6_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1604 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1021, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_1_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_1_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_0_6_0, _ctx)) {
        kk_datatype_ptr_free(_pat_0_6_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_0_6_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x1021, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x1021, _ctx);
    }
    _x_x1600 = _x_3; /*std/time/timestamp/timespan*/
  }
  _x_x1597 = kk_std_num_ddouble__lp__plus__rp_(_x_x1598, _x_x1600, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1605;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1606 = kk_std_time_timestamp__as_Timestamp(ts_1_10116, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_1_0 = _con_x1606->since;
    int32_t _x_0_0 = _con_x1606->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts_1_10116, _ctx)) {
      kk_datatype_ptr_free(ts_1_10116, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts_1_10116, _ctx);
    }
    _x_x1605 = _x_0_0; /*int32*/
  }
  t_0_10115 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1597, _x_x1605, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1607 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_0_10115, _x_x1607, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1609__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1609(kk_function_t _fself, kk_box_t _b_x206, kk_box_t _b_x207, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1609(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1609, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1609(kk_function_t _fself, kk_box_t _b_x206, kk_box_t _b_x207, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1610;
  kk_std_num_ddouble__ddouble _x_x1611 = kk_std_num_ddouble__ddouble_unbox(_b_x206, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1612;
  double _x_x1613;
  double _x_x1614;
  kk_std_num_ddouble__ddouble _match_x1020;
  kk_box_t _x_x1615 = kk_box_dup(_b_x207, _ctx); /*9984*/
  _match_x1020 = kk_std_num_ddouble__ddouble_unbox(_x_x1615, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x_1 = _match_x1020.hi;
    _x_x1614 = _x_1; /*float64*/
  }
  _x_x1613 = (-_x_x1614); /*float64*/
  double _x_x1616;
  double _x_x1617;
  kk_std_num_ddouble__ddouble _match_x1019 = kk_std_num_ddouble__ddouble_unbox(_b_x207, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0_0 = _match_x1019.lo;
    _x_x1617 = _x_0_0; /*float64*/
  }
  _x_x1616 = (-_x_x1617); /*float64*/
  _x_x1612 = kk_std_num_ddouble__new_Ddouble(_x_x1613, _x_x1616, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1610 = kk_std_num_ddouble__lp__plus__rp_(_x_x1611, _x_x1612, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1610, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1619__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1619(kk_function_t _fself, kk_box_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1619(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1619, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1619(kk_function_t _fself, kk_box_t _b_x216, kk_box_t _b_x217, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1620;
  kk_std_num_ddouble__ddouble _x_x1621 = kk_std_num_ddouble__ddouble_unbox(_b_x216, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1622 = kk_std_num_ddouble__ddouble_unbox(_b_x217, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1620 = kk_std_num_ddouble__lp__star__rp_(_x_x1621, _x_x1622, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1620, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1624__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1624(kk_function_t _fself, kk_box_t _b_x223, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1624(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1624, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1624(kk_function_t _fself, kk_box_t _b_x223, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1625;
  kk_std_num_ddouble__ddouble _x_x1626 = kk_std_num_ddouble__ddouble_unbox(_b_x223, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1625 = kk_std_num_ddouble_round(_x_x1626, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1625, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1628__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1628(kk_function_t _fself, kk_box_t _b_x230, kk_box_t _b_x231, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1628(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1628, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1628(kk_function_t _fself, kk_box_t _b_x230, kk_box_t _b_x231, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1629;
  kk_std_num_ddouble__ddouble _x_x1630 = kk_std_num_ddouble__ddouble_unbox(_b_x230, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x1631;
  kk_integer_t _x_x1632;
  kk_std_core_types__optional _match_x1018 = kk_std_core_types__optional_unbox(_b_x231, KK_OWNED, _ctx); /*? int*/;
  if (kk_std_core_types__is_Optional(_match_x1018, _ctx)) {
    kk_box_t _box_x226 = _match_x1018._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x226, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x1018, _ctx);
    _x_x1632 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1018, _ctx);
    _x_x1632 = kk_integer_from_small(0); /*int*/
  }
  _x_x1631 = kk_integer_clamp32(_x_x1632,kk_context()); /*int32*/
  _x_x1629 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1630, _x_x1631, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1629, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1634__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1634(kk_function_t _fself, kk_box_t _b_x240, kk_box_t _b_x241, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1634(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1634, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1634(kk_function_t _fself, kk_box_t _b_x240, kk_box_t _b_x241, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1635;
  kk_std_num_ddouble__ddouble _x_x1636 = kk_std_num_ddouble__ddouble_unbox(_b_x240, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1637;
  double _x_x1638;
  double _x_x1639;
  kk_std_num_ddouble__ddouble _match_x1017;
  kk_box_t _x_x1640 = kk_box_dup(_b_x241, _ctx); /*9984*/
  _match_x1017 = kk_std_num_ddouble__ddouble_unbox(_x_x1640, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x_2 = _match_x1017.hi;
    _x_x1639 = _x_2; /*float64*/
  }
  _x_x1638 = (-_x_x1639); /*float64*/
  double _x_x1641;
  double _x_x1642;
  kk_std_num_ddouble__ddouble _match_x1016 = kk_std_num_ddouble__ddouble_unbox(_b_x241, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0_1 = _match_x1016.lo;
    _x_x1642 = _x_0_1; /*float64*/
  }
  _x_x1641 = (-_x_x1642); /*float64*/
  _x_x1637 = kk_std_num_ddouble__new_Ddouble(_x_x1638, _x_x1641, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1635 = kk_std_num_ddouble__lp__plus__rp_(_x_x1636, _x_x1637, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1635, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1644__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1644(kk_function_t _fself, kk_box_t _b_x250, kk_box_t _b_x251, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1644(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1644, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1644(kk_function_t _fself, kk_box_t _b_x250, kk_box_t _b_x251, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1645;
  kk_std_num_ddouble__ddouble _x_x1646 = kk_std_num_ddouble__ddouble_unbox(_b_x250, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1647 = kk_std_num_ddouble__ddouble_unbox(_b_x251, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1645 = kk_std_num_ddouble__lp__star__rp_(_x_x1646, _x_x1647, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1645, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1649__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1649(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1649(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1649, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1649(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1650;
  kk_std_num_ddouble__ddouble _x_x1651 = kk_std_num_ddouble__ddouble_unbox(_b_x257, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1650 = kk_std_num_ddouble_round(_x_x1651, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1650, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1653__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1653(kk_function_t _fself, kk_box_t _b_x264, kk_box_t _b_x265, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1653(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1653, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1653(kk_function_t _fself, kk_box_t _b_x264, kk_box_t _b_x265, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1654;
  kk_std_num_ddouble__ddouble _x_x1655 = kk_std_num_ddouble__ddouble_unbox(_b_x264, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x1656;
  kk_integer_t _x_x1657;
  kk_std_core_types__optional _match_x1015 = kk_std_core_types__optional_unbox(_b_x265, KK_OWNED, _ctx); /*? int*/;
  if (kk_std_core_types__is_Optional(_match_x1015, _ctx)) {
    kk_box_t _box_x260 = _match_x1015._cons._Optional.value;
    kk_integer_t _uniq_leap_1214_0 = kk_integer_unbox(_box_x260, _ctx);
    kk_integer_dup(_uniq_leap_1214_0, _ctx);
    kk_std_core_types__optional_drop(_match_x1015, _ctx);
    _x_x1657 = _uniq_leap_1214_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1015, _ctx);
    _x_x1657 = kk_integer_from_small(0); /*int*/
  }
  _x_x1656 = kk_integer_clamp32(_x_x1657,kk_context()); /*int32*/
  _x_x1654 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1655, _x_x1656, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1654, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10320_fun1659__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1659(kk_function_t _fself, kk_box_t _b_x280, kk_box_t _b_x281, kk_box_t _b_x282, kk_box_t _b_x283, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1659(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10320_fun1659, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10320_fun1659(kk_function_t _fself, kk_box_t _b_x280, kk_box_t _b_x281, kk_box_t _b_x282, kk_box_t _b_x283, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp utc_start_291 = kk_std_time_timestamp__timestamp_unbox(_b_x280, KK_OWNED, _ctx); /*std/time/utc/utc-timestamp*/;
  kk_std_num_ddouble__ddouble offset_292 = kk_std_num_ddouble__ddouble_unbox(_b_x281, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_core_types__optional drift_start_293 = kk_std_core_types__optional_unbox(_b_x282, KK_OWNED, _ctx); /*? std/time/utc/utc-timestamp*/;
  kk_std_core_types__optional drift_0_294 = kk_std_core_types__optional_unbox(_b_x283, KK_OWNED, _ctx); /*? std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1660;
  kk_std_time_timestamp__timestamp _x_x1661;
  if (kk_std_core_types__is_Optional(drift_start_293, _ctx)) {
    kk_box_t _box_x271 = drift_start_293._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_396 = kk_std_time_timestamp__timestamp_unbox(_box_x271, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_396, _ctx);
    kk_std_core_types__optional_drop(drift_start_293, _ctx);
    _x_x1661 = _uniq_drift_start_396; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start_293, _ctx);
    _x_x1661 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/utc/utc-timestamp*/
  }
  kk_std_num_ddouble__ddouble _x_x1662;
  if (kk_std_core_types__is_Optional(drift_0_294, _ctx)) {
    kk_box_t _box_x272 = drift_0_294._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_400 = kk_std_num_ddouble__ddouble_unbox(_box_x272, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift_0_294, _ctx);
    _x_x1662 = _uniq_drift_400; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift_0_294, _ctx);
    _x_x1662 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  _x_x1660 = kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, utc_start_291, offset_292, _x_x1661, _x_x1662, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1660, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10320(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___10, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@10 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___10, _ctx);
  kk_std_num_ddouble__ddouble _x_x1_2_10289;
  kk_box_t _x_x1608 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1609(_ctx), kk_std_num_ddouble__ddouble_box(mjd, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_mjd_epoch_shift, _ctx), _ctx); /*9985*/
  _x_x1_2_10289 = kk_std_num_ddouble__ddouble_unbox(_x_x1608, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_1_10288;
  kk_box_t _x_x1618 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1619(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_2_10289, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*9985*/
  _x_x1_1_10288 = kk_std_num_ddouble__ddouble_unbox(_x_x1618, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_0_10286;
  kk_box_t _x_x1623 = kk_std_core_hnd__open_none1(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1624(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_1_10288, _ctx), _ctx); /*9904*/
  _x_x1_0_10286 = kk_std_num_ddouble__ddouble_unbox(_x_x1623, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp start;
  kk_box_t _x_x1627 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1628(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_0_10286, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  start = kk_std_time_timestamp__timestamp_unbox(_x_x1627, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x1_6_10296;
  kk_box_t _x_x1633 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1634(_ctx), kk_std_num_ddouble__ddouble_box(dmjd, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_mjd_epoch_shift, _ctx), _ctx); /*9985*/
  _x_x1_6_10296 = kk_std_num_ddouble__ddouble_unbox(_x_x1633, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_5_10295;
  kk_box_t _x_x1643 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1644(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_6_10296, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*9985*/
  _x_x1_5_10295 = kk_std_num_ddouble__ddouble_unbox(_x_x1643, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_4_10293;
  kk_box_t _x_x1648 = kk_std_core_hnd__open_none1(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1649(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_5_10295, _ctx), _ctx); /*9904*/
  _x_x1_4_10293 = kk_std_num_ddouble__ddouble_unbox(_x_x1648, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp dstart;
  kk_box_t _x_x1652 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1653(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_4_10293, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  dstart = kk_std_time_timestamp__timestamp_unbox(_x_x1652, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
  kk_box_t _x_x1658;
  kk_box_t _x_x1663;
  kk_std_core_types__optional _x_x1664 = kk_std_core_types__new_Optional(kk_std_time_timestamp__timestamp_box(dstart, _ctx), _ctx); /*? 7*/
  _x_x1663 = kk_std_core_types__optional_box(_x_x1664, _ctx); /*10184*/
  kk_box_t _x_x1665;
  kk_std_core_types__optional _x_x1666 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(drift, _ctx), _ctx); /*? 7*/
  _x_x1665 = kk_std_core_types__optional_box(_x_x1666, _ctx); /*10185*/
  _x_x1658 = kk_std_core_hnd__open_none4(kk_std_time_utc__new_mlift_ptaiadjust_10320_fun1659(_ctx), kk_std_time_timestamp__timestamp_box(start, _ctx), kk_std_num_ddouble__ddouble_box(ofs, _ctx), _x_x1663, _x_x1665, _ctx); /*10186*/
  return kk_std_time_utc__leap_adjust_unbox(_x_x1658, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10321_fun1668__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble drift;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10321_fun1668(kk_function_t _fself, kk_box_t _b_x296, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10321_fun1668(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10321_fun1668__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10321_fun1668__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10321_fun1668, kk_context());
  _self->dmjd = dmjd;
  _self->drift = drift;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10321_fun1668(kk_function_t _fself, kk_box_t _b_x296, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10321_fun1668__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10321_fun1668__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble drift = _self->drift; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(drift, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_string_t wild___10_298 = kk_string_unbox(_b_x296); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1669 = kk_std_time_utc__mlift_ptaiadjust_10320(dmjd, drift, mjd, ofs, wild___10_298, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1669, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10321(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___9, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@9 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___9, _ctx);
  kk_string_t x_10366 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10366, _ctx);
    kk_box_t _x_x1667 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10321_fun1668(dmjd, drift, mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1667, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10320(dmjd, drift, mjd, ofs, x_10366, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10322_fun1673__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble drift;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10322_fun1673(kk_function_t _fself, kk_box_t _b_x300, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10322_fun1673(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10322_fun1673__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10322_fun1673__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10322_fun1673, kk_context());
  _self->dmjd = dmjd;
  _self->drift = drift;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10322_fun1673(kk_function_t _fself, kk_box_t _b_x300, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10322_fun1673__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10322_fun1673__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble drift = _self->drift; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(drift, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_string_t wild___9_302 = kk_string_unbox(_b_x300); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1674 = kk_std_time_utc__mlift_ptaiadjust_10321(dmjd, drift, mjd, ofs, wild___9_302, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1674, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10322(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___8, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@8 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___8, _ctx);
  kk_string_t x_10368;
  kk_string_t _x_x1670;
  kk_define_string_literal(, _s_x1671, 1, "S", _ctx)
  _x_x1670 = kk_string_dup(_s_x1671, _ctx); /*string*/
  x_10368 = kk_std_text_parse_pstring(_x_x1670, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10368, _ctx);
    kk_box_t _x_x1672 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10322_fun1673(dmjd, drift, mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1672, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10321(dmjd, drift, mjd, ofs, x_10368, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10323_fun1676__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble drift;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10323_fun1676(kk_function_t _fself, kk_box_t _b_x304, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10323_fun1676(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10323_fun1676__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10323_fun1676__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10323_fun1676, kk_context());
  _self->dmjd = dmjd;
  _self->drift = drift;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10323_fun1676(kk_function_t _fself, kk_box_t _b_x304, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10323_fun1676__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10323_fun1676__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble drift = _self->drift; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(drift, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_string_t wild___8_306 = kk_string_unbox(_b_x304); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1677 = kk_std_time_utc__mlift_ptaiadjust_10322(dmjd, drift, mjd, ofs, wild___8_306, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1677, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10323(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_num_ddouble__ddouble drift, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_10370 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10370, _ctx);
    kk_box_t _x_x1675 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10323_fun1676(dmjd, drift, mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1675, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10322(dmjd, drift, mjd, ofs, x_10370, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1679__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10324_fun1679(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10324_fun1679(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10324_fun1679, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10324_fun1679(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1680 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1680, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1681__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10324_fun1681(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10324_fun1681(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10324_fun1681, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10324_fun1681(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1682 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1682, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1684__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10324_fun1684(kk_function_t _fself, kk_box_t _b_x312, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10324_fun1684(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1684__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1684__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10324_fun1684, kk_context());
  _self->dmjd = dmjd;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10324_fun1684(kk_function_t _fself, kk_box_t _b_x312, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1684__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10324_fun1684__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble drift_314 = kk_std_num_ddouble__ddouble_unbox(_b_x312, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1685 = kk_std_time_utc__mlift_ptaiadjust_10323(dmjd, mjd, ofs, drift_314, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1685, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10324(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_core_types__list _y_x10249, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, list<char>) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list_drop(_y_x10249, _ctx);
  kk_std_num_ddouble__ddouble x_10372;
  kk_box_t _x_x1678 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc__new_mlift_ptaiadjust_10324_fun1679(_ctx), kk_std_time_utc__new_mlift_ptaiadjust_10324_fun1681(_ctx), _ctx); /*1542*/
  x_10372 = kk_std_num_ddouble__ddouble_unbox(_x_x1678, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1683 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10324_fun1684(dmjd, mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1683, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10323(dmjd, mjd, ofs, x_10372, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10325_fun1686__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10325_fun1686(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10325_fun1686(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10325_fun1686, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10325_fun1686(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1687 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x1687, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10325_fun1689__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10325_fun1689(kk_function_t _fself, kk_box_t _b_x320, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10325_fun1689(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10325_fun1689__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10325_fun1689__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10325_fun1689, kk_context());
  _self->dmjd = dmjd;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10325_fun1689(kk_function_t _fself, kk_box_t _b_x320, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10325_fun1689__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10325_fun1689__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10249_322 = kk_std_core_types__list_unbox(_b_x320, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x1690 = kk_std_time_utc__mlift_ptaiadjust_10324(dmjd, mjd, ofs, _y_x10249_322, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1690, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10325(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_char_t _y_x10248, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, char) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list x_10374 = kk_std_text_parse_many_acc(kk_std_time_utc__new_mlift_ptaiadjust_10325_fun1686(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10374, _ctx);
    kk_box_t _x_x1688 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10325_fun1689(dmjd, mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1688, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10324(dmjd, mjd, ofs, x_10374, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10326_fun1692__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10326_fun1692(kk_function_t _fself, kk_box_t _b_x324, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10326_fun1692(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10326_fun1692__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10326_fun1692__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10326_fun1692, kk_context());
  _self->dmjd = dmjd;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10326_fun1692(kk_function_t _fself, kk_box_t _b_x324, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10326_fun1692__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10326_fun1692__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_char_t _y_x10248_326 = kk_char_unbox(_b_x324, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x1693 = kk_std_time_utc__mlift_ptaiadjust_10325(dmjd, mjd, ofs, _y_x10248_326, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1693, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10326(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_num_ddouble__ddouble dmjd, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, dmjd : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_char_t x_10376 = kk_std_text_parse_no_digit(_ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1691 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10326_fun1692(dmjd, mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1691, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10325(dmjd, mjd, ofs, x_10376, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1695__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10327_fun1695(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10327_fun1695(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10327_fun1695, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10327_fun1695(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1696 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1696, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1697__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10327_fun1697(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10327_fun1697(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10327_fun1697, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10327_fun1697(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1698 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1698, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1700__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10327_fun1700(kk_function_t _fself, kk_box_t _b_x332, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10327_fun1700(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1700__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1700__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10327_fun1700, kk_context());
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10327_fun1700(kk_function_t _fself, kk_box_t _b_x332, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1700__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10327_fun1700__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble dmjd_334 = kk_std_num_ddouble__ddouble_unbox(_b_x332, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1701 = kk_std_time_utc__mlift_ptaiadjust_10326(mjd, ofs, dmjd_334, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1701, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10327(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_core_types__list _y_x10246, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, list<char>) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list_drop(_y_x10246, _ctx);
  kk_std_num_ddouble__ddouble x_10378;
  kk_box_t _x_x1694 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc__new_mlift_ptaiadjust_10327_fun1695(_ctx), kk_std_time_utc__new_mlift_ptaiadjust_10327_fun1697(_ctx), _ctx); /*1542*/
  x_10378 = kk_std_num_ddouble__ddouble_unbox(_x_x1694, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1699 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10327_fun1700(mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1699, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10326(mjd, ofs, x_10378, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10328_fun1702__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10328_fun1702(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10328_fun1702(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10328_fun1702, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10328_fun1702(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1703 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x1703, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10328_fun1705__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10328_fun1705(kk_function_t _fself, kk_box_t _b_x340, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10328_fun1705(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10328_fun1705__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10328_fun1705__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10328_fun1705, kk_context());
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10328_fun1705(kk_function_t _fself, kk_box_t _b_x340, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10328_fun1705__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10328_fun1705__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10246_342 = kk_std_core_types__list_unbox(_b_x340, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x1706 = kk_std_time_utc__mlift_ptaiadjust_10327(mjd, ofs, _y_x10246_342, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1706, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10328(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_char_t _y_x10245, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, char) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list x_10380 = kk_std_text_parse_many_acc(kk_std_time_utc__new_mlift_ptaiadjust_10328_fun1702(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10380, _ctx);
    kk_box_t _x_x1704 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10328_fun1705(mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1704, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10327(mjd, ofs, x_10380, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10329_fun1708__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10329_fun1708(kk_function_t _fself, kk_box_t _b_x344, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10329_fun1708(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10329_fun1708__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10329_fun1708__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10329_fun1708, kk_context());
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10329_fun1708(kk_function_t _fself, kk_box_t _b_x344, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10329_fun1708__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10329_fun1708__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_char_t _y_x10245_346 = kk_char_unbox(_b_x344, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x1709 = kk_std_time_utc__mlift_ptaiadjust_10328(mjd, ofs, _y_x10245_346, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1709, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10329(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_char_t x_10382 = kk_std_text_parse_no_digit(_ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1707 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10329_fun1708(mjd, ofs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1707, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10328(mjd, ofs, x_10382, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1711__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10330_fun1711(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10330_fun1711(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10330_fun1711, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10330_fun1711(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1712 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1712, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1713__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10330_fun1713(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10330_fun1713(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10330_fun1713, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10330_fun1713(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1714 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1714, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1716__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10330_fun1716(kk_function_t _fself, kk_box_t _b_x352, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10330_fun1716(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1716__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1716__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10330_fun1716, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10330_fun1716(kk_function_t _fself, kk_box_t _b_x352, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1716__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10330_fun1716__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble ofs_354 = kk_std_num_ddouble__ddouble_unbox(_b_x352, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1717 = kk_std_time_utc__mlift_ptaiadjust_10329(mjd, ofs_354, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1717, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10330(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___5, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, wild_@5 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___5, _ctx);
  kk_std_num_ddouble__ddouble x_10384;
  kk_box_t _x_x1710 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc__new_mlift_ptaiadjust_10330_fun1711(_ctx), kk_std_time_utc__new_mlift_ptaiadjust_10330_fun1713(_ctx), _ctx); /*1542*/
  x_10384 = kk_std_num_ddouble__ddouble_unbox(_x_x1710, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1715 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10330_fun1716(mjd, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1715, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10329(mjd, x_10384, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10331_fun1719__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10331_fun1719(kk_function_t _fself, kk_box_t _b_x356, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10331_fun1719(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10331_fun1719__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10331_fun1719__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10331_fun1719, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10331_fun1719(kk_function_t _fself, kk_box_t _b_x356, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10331_fun1719__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10331_fun1719__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___5_358 = kk_string_unbox(_b_x356); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1720 = kk_std_time_utc__mlift_ptaiadjust_10330(mjd, wild___5_358, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1720, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10331(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___4, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, wild_@4 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___4, _ctx);
  kk_string_t x_10386 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10386, _ctx);
    kk_box_t _x_x1718 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10331_fun1719(mjd, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1718, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10330(mjd, x_10386, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10332_fun1724__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10332_fun1724(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10332_fun1724(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10332_fun1724__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10332_fun1724__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10332_fun1724, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10332_fun1724(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10332_fun1724__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10332_fun1724__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___4_362 = kk_string_unbox(_b_x360); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1725 = kk_std_time_utc__mlift_ptaiadjust_10331(mjd, wild___4_362, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1725, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10332(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___3, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, wild_@3 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___3, _ctx);
  kk_string_t x_10388;
  kk_string_t _x_x1721;
  kk_define_string_literal(, _s_x1722, 8, "TAI-UTC=", _ctx)
  _x_x1721 = kk_string_dup(_s_x1722, _ctx); /*string*/
  x_10388 = kk_std_text_parse_pstring(_x_x1721, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10388, _ctx);
    kk_box_t _x_x1723 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10332_fun1724(mjd, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1723, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10331(mjd, x_10388, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10333_fun1727__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10333_fun1727(kk_function_t _fself, kk_box_t _b_x366, kk_box_t _b_x367, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10333_fun1727(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10333_fun1727, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10333_fun1727(kk_function_t _fself, kk_box_t _b_x366, kk_box_t _b_x367, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1728;
  kk_std_num_ddouble__ddouble _x_x1729 = kk_std_num_ddouble__ddouble_unbox(_b_x366, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1730;
  double _x_x1731;
  double _x_x1732;
  kk_std_num_ddouble__ddouble _match_x1002;
  kk_box_t _x_x1733 = kk_box_dup(_b_x367, _ctx); /*9984*/
  _match_x1002 = kk_std_num_ddouble__ddouble_unbox(_x_x1733, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = _match_x1002.hi;
    _x_x1732 = _x; /*float64*/
  }
  _x_x1731 = (-_x_x1732); /*float64*/
  double _x_x1734;
  double _x_x1735;
  kk_std_num_ddouble__ddouble _match_x1001 = kk_std_num_ddouble__ddouble_unbox(_b_x367, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0 = _match_x1001.lo;
    _x_x1735 = _x_0; /*float64*/
  }
  _x_x1734 = (-_x_x1735); /*float64*/
  _x_x1730 = kk_std_num_ddouble__new_Ddouble(_x_x1731, _x_x1734, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1728 = kk_std_num_ddouble__lp__plus__rp_(_x_x1729, _x_x1730, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1728, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10333_fun1737__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10333_fun1737(kk_function_t _fself, kk_box_t _b_x374, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10333_fun1737(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10333_fun1737__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10333_fun1737__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10333_fun1737, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10333_fun1737(kk_function_t _fself, kk_box_t _b_x374, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10333_fun1737__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10333_fun1737__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___3_376 = kk_string_unbox(_b_x374); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1738 = kk_std_time_utc__mlift_ptaiadjust_10332(mjd, wild___3_376, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1738, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10333(kk_std_num_ddouble__ddouble _y_x10240, kk_context_t* _ctx) { /* (std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_std_num_ddouble__ddouble mjd;
  kk_box_t _x_x1726 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10333_fun1727(_ctx), kk_std_num_ddouble__ddouble_box(_y_x10240, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_jd_epoch_shift, _ctx), _ctx); /*9985*/
  mjd = kk_std_num_ddouble__ddouble_unbox(_x_x1726, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_string_t x_0_10390 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10390, _ctx);
    kk_box_t _x_x1736 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10333_fun1737(mjd, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1736, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10332(mjd, x_0_10390, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10334_fun1740__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10334_fun1740(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10334_fun1740(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10334_fun1740, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10334_fun1740(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1741 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1741, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10334_fun1742__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10334_fun1742(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10334_fun1742(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10334_fun1742, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10334_fun1742(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1743 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1743, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10334_fun1745__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10334_fun1745(kk_function_t _fself, kk_box_t _b_x382, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10334_fun1745(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10334_fun1745, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10334_fun1745(kk_function_t _fself, kk_box_t _b_x382, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1746;
  kk_std_num_ddouble__ddouble _x_x1747 = kk_std_num_ddouble__ddouble_unbox(_b_x382, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1746 = kk_std_time_utc__mlift_ptaiadjust_10333(_x_x1747, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1746, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10334(kk_string_t wild___2, kk_context_t* _ctx) { /* (wild_@2 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___2, _ctx);
  kk_std_num_ddouble__ddouble x_10392;
  kk_box_t _x_x1739 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc__new_mlift_ptaiadjust_10334_fun1740(_ctx), kk_std_time_utc__new_mlift_ptaiadjust_10334_fun1742(_ctx), _ctx); /*1542*/
  x_10392 = kk_std_num_ddouble__ddouble_unbox(_x_x1739, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1744 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10334_fun1745(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1744, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10333(x_10392, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10335_fun1749__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10335_fun1749(kk_function_t _fself, kk_box_t _b_x385, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10335_fun1749(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10335_fun1749, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10335_fun1749(kk_function_t _fself, kk_box_t _b_x385, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1750;
  kk_string_t _x_x1751 = kk_string_unbox(_b_x385); /*string*/
  _x_x1750 = kk_std_time_utc__mlift_ptaiadjust_10334(_x_x1751, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1750, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10335(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___1, _ctx);
  kk_string_t x_10394 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10394, _ctx);
    kk_box_t _x_x1748 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10335_fun1749(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1748, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10334(x_10394, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10336_fun1755__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10336_fun1755(kk_function_t _fself, kk_box_t _b_x388, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10336_fun1755(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10336_fun1755, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10336_fun1755(kk_function_t _fself, kk_box_t _b_x388, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1756;
  kk_string_t _x_x1757 = kk_string_unbox(_b_x388); /*string*/
  _x_x1756 = kk_std_time_utc__mlift_ptaiadjust_10335(_x_x1757, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1756, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10336(kk_std_core_types__list _y_x10237, kk_context_t* _ctx) { /* (list<char>) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list_drop(_y_x10237, _ctx);
  kk_string_t x_10396;
  kk_string_t _x_x1752;
  kk_define_string_literal(, _s_x1753, 3, "=JD", _ctx)
  _x_x1752 = kk_string_dup(_s_x1753, _ctx); /*string*/
  x_10396 = kk_std_text_parse_pstring(_x_x1752, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10396, _ctx);
    kk_box_t _x_x1754 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10336_fun1755(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1754, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10335(x_10396, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10337_fun1758__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10337_fun1758(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10337_fun1758(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10337_fun1758, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10337_fun1758(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1759;
  kk_string_t _x_x1760;
  kk_define_string_literal(, _s_x1761, 1, "=", _ctx)
  _x_x1760 = kk_string_dup(_s_x1761, _ctx); /*string*/
  _x_x1759 = kk_std_text_parse_none_of(_x_x1760, _ctx); /*char*/
  return kk_char_box(_x_x1759, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10337_fun1763__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10337_fun1763(kk_function_t _fself, kk_box_t _b_x395, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10337_fun1763(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10337_fun1763, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10337_fun1763(kk_function_t _fself, kk_box_t _b_x395, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1764;
  kk_std_core_types__list _x_x1765 = kk_std_core_types__list_unbox(_b_x395, KK_OWNED, _ctx); /*list<char>*/
  _x_x1764 = kk_std_time_utc__mlift_ptaiadjust_10336(_x_x1765, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1764, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10337(kk_char_t _y_x10235, kk_context_t* _ctx) { /* (char) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list x_10398 = kk_std_text_parse_many_acc(kk_std_time_utc__new_mlift_ptaiadjust_10337_fun1758(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10398, _ctx);
    kk_box_t _x_x1762 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10337_fun1763(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1762, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10336(x_10398, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10338_fun1769__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10338_fun1769(kk_function_t _fself, kk_box_t _b_x398, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10338_fun1769(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10338_fun1769, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10338_fun1769(kk_function_t _fself, kk_box_t _b_x398, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1770;
  kk_char_t _x_x1771 = kk_char_unbox(_b_x398, KK_OWNED, _ctx); /*char*/
  _x_x1770 = kk_std_time_utc__mlift_ptaiadjust_10337(_x_x1771, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1770, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10338(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild__, _ctx);
  kk_char_t x_10400;
  kk_string_t _x_x1766;
  kk_define_string_literal(, _s_x1767, 1, "=", _ctx)
  _x_x1766 = kk_string_dup(_s_x1767, _ctx); /*string*/
  x_10400 = kk_std_text_parse_none_of(_x_x1766, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1768 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10338_fun1769(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1768, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10337(x_10400, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1773__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1773(kk_function_t _fself, kk_box_t _b_x401, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1773(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1773, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1773(kk_function_t _fself, kk_box_t _b_x401, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1774;
  kk_string_t _x_x1775 = kk_string_unbox(_b_x401); /*string*/
  _x_x1774 = kk_std_time_utc__mlift_ptaiadjust_10338(_x_x1775, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1774, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1779__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1779(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1779(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1779, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1779(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1780;
  kk_char_t _x_x1781 = kk_char_unbox(_b_x403, KK_OWNED, _ctx); /*char*/
  _x_x1780 = kk_std_time_utc__mlift_ptaiadjust_10337(_x_x1781, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1780, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1782__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1782(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1782(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1782, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1782(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1783;
  kk_string_t _x_x1784;
  kk_define_string_literal(, _s_x1785, 1, "=", _ctx)
  _x_x1784 = kk_string_dup(_s_x1785, _ctx); /*string*/
  _x_x1783 = kk_std_text_parse_none_of(_x_x1784, _ctx); /*char*/
  return kk_char_box(_x_x1783, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1787__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1787(kk_function_t _fself, kk_box_t _b_x409, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1787(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1787, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1787(kk_function_t _fself, kk_box_t _b_x409, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1788;
  kk_std_core_types__list _x_x1789 = kk_std_core_types__list_unbox(_b_x409, KK_OWNED, _ctx); /*list<char>*/
  _x_x1788 = kk_std_time_utc__mlift_ptaiadjust_10336(_x_x1789, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1788, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1793__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1793(kk_function_t _fself, kk_box_t _b_x411, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1793(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1793, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1793(kk_function_t _fself, kk_box_t _b_x411, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1794;
  kk_string_t _x_x1795 = kk_string_unbox(_b_x411); /*string*/
  _x_x1794 = kk_std_time_utc__mlift_ptaiadjust_10335(_x_x1795, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1794, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1797__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1797(kk_function_t _fself, kk_box_t _b_x413, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1797(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1797, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1797(kk_function_t _fself, kk_box_t _b_x413, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1798;
  kk_string_t _x_x1799 = kk_string_unbox(_b_x413); /*string*/
  _x_x1798 = kk_std_time_utc__mlift_ptaiadjust_10334(_x_x1799, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1798, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1801__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1801(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1801(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1801, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1801(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1802 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1802, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1803__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1803(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1803(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1803, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1803(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1804 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1804, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1806__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1806(kk_function_t _fself, kk_box_t _b_x419, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1806(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1806, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1806(kk_function_t _fself, kk_box_t _b_x419, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1807;
  kk_std_num_ddouble__ddouble _x_x1808 = kk_std_num_ddouble__ddouble_unbox(_b_x419, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1807 = kk_std_time_utc__mlift_ptaiadjust_10333(_x_x1808, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1807, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1810__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1810(kk_function_t _fself, kk_box_t _b_x423, kk_box_t _b_x424, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1810(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1810, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1810(kk_function_t _fself, kk_box_t _b_x423, kk_box_t _b_x424, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1811;
  kk_std_num_ddouble__ddouble _x_x1812 = kk_std_num_ddouble__ddouble_unbox(_b_x423, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1813;
  double _x_x1814;
  double _x_x1815;
  kk_std_num_ddouble__ddouble _match_x994;
  kk_box_t _x_x1816 = kk_box_dup(_b_x424, _ctx); /*9984*/
  _match_x994 = kk_std_num_ddouble__ddouble_unbox(_x_x1816, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = _match_x994.hi;
    _x_x1815 = _x; /*float64*/
  }
  _x_x1814 = (-_x_x1815); /*float64*/
  double _x_x1817;
  double _x_x1818;
  kk_std_num_ddouble__ddouble _match_x993 = kk_std_num_ddouble__ddouble_unbox(_b_x424, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0 = _match_x993.lo;
    _x_x1818 = _x_0; /*float64*/
  }
  _x_x1817 = (-_x_x1818); /*float64*/
  _x_x1813 = kk_std_num_ddouble__new_Ddouble(_x_x1814, _x_x1817, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1811 = kk_std_num_ddouble__lp__plus__rp_(_x_x1812, _x_x1813, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1811, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1820__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1820(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1820(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1820__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1820__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1820, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1820(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1820__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1820__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___3_583 = kk_string_unbox(_b_x431); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1821 = kk_std_time_utc__mlift_ptaiadjust_10332(mjd, wild___3_583, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1821, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1825__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1825(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1825(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1825__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1825__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1825, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1825(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1825__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1825__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___4_584 = kk_string_unbox(_b_x433); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1826 = kk_std_time_utc__mlift_ptaiadjust_10331(mjd, wild___4_584, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1826, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1828__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1828(kk_function_t _fself, kk_box_t _b_x435, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1828(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1828__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1828__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1828, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1828(kk_function_t _fself, kk_box_t _b_x435, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1828__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1828__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___5_585 = kk_string_unbox(_b_x435); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1829 = kk_std_time_utc__mlift_ptaiadjust_10330(mjd, wild___5_585, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1829, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1831__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1831(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1831(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1831, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1831(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1832 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1832, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1833__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1833(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1833(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1833, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1833(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1834 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1834, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1836__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1836(kk_function_t _fself, kk_box_t _b_x441, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1836(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1836__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1836__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1836, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1836(kk_function_t _fself, kk_box_t _b_x441, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1836__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1836__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble ofs_586 = kk_std_num_ddouble__ddouble_unbox(_b_x441, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1837 = kk_std_time_utc__mlift_ptaiadjust_10329(mjd, ofs_586, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1837, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1839__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1839(kk_function_t _fself, kk_box_t _b_x443, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1839(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1839__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1839__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1839, kk_context());
  _self->mjd = mjd;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1839(kk_function_t _fself, kk_box_t _b_x443, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1839__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1839__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_char_t _y_x10245_587 = kk_char_unbox(_b_x443, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x1840 = kk_std_time_utc__mlift_ptaiadjust_10328(mjd, x_9_10429, _y_x10245_587, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1840, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1841__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1841(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1841(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1841, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1841(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1842 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x1842, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1844__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1844(kk_function_t _fself, kk_box_t _b_x449, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1844(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1844__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1844__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1844, kk_context());
  _self->mjd = mjd;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1844(kk_function_t _fself, kk_box_t _b_x449, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1844__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1844__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10246_588 = kk_std_core_types__list_unbox(_b_x449, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x1845 = kk_std_time_utc__mlift_ptaiadjust_10327(mjd, x_9_10429, _y_x10246_588, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1845, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1847__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1847(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1847(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1847, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1847(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1848 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1848, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1849__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1849(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1849(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1849, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1849(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1850 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1850, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1852__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1852(kk_function_t _fself, kk_box_t _b_x455, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1852(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1852__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1852__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1852, kk_context());
  _self->mjd = mjd;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1852(kk_function_t _fself, kk_box_t _b_x455, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1852__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1852__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble dmjd_589 = kk_std_num_ddouble__ddouble_unbox(_b_x455, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1853 = kk_std_time_utc__mlift_ptaiadjust_10326(mjd, x_9_10429, dmjd_589, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1853, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1855__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_12_10438;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1855(kk_function_t _fself, kk_box_t _b_x457, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1855(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_12_10438, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1855__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1855__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1855, kk_context());
  _self->mjd = mjd;
  _self->x_12_10438 = x_12_10438;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1855(kk_function_t _fself, kk_box_t _b_x457, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1855__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1855__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_12_10438 = _self->x_12_10438; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_12_10438, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_char_t _y_x10248_590 = kk_char_unbox(_b_x457, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x1856 = kk_std_time_utc__mlift_ptaiadjust_10325(x_12_10438, mjd, x_9_10429, _y_x10248_590, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1856, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1857__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1857(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1857(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1857, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1857(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1858 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x1858, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1860__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_12_10438;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1860(kk_function_t _fself, kk_box_t _b_x463, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1860(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_12_10438, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1860__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1860__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1860, kk_context());
  _self->mjd = mjd;
  _self->x_12_10438 = x_12_10438;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1860(kk_function_t _fself, kk_box_t _b_x463, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1860__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1860__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_12_10438 = _self->x_12_10438; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_12_10438, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10249_591 = kk_std_core_types__list_unbox(_b_x463, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x1861 = kk_std_time_utc__mlift_ptaiadjust_10324(x_12_10438, mjd, x_9_10429, _y_x10249_591, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1861, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1863__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1863(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1863(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1863, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1863(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1864 = kk_std_num_ddouble_pddouble_sum(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1864, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1865__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1865(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1865(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1865, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1865(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1866 = kk_std_num_ddouble_pddouble_normal(_ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1866, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1868__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_12_10438;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1868(kk_function_t _fself, kk_box_t _b_x469, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1868(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_12_10438, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1868__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1868__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1868, kk_context());
  _self->mjd = mjd;
  _self->x_12_10438 = x_12_10438;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1868(kk_function_t _fself, kk_box_t _b_x469, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1868__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1868__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_12_10438 = _self->x_12_10438; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_12_10438, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble drift_592 = kk_std_num_ddouble__ddouble_unbox(_b_x469, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1869 = kk_std_time_utc__mlift_ptaiadjust_10323(x_12_10438, mjd, x_9_10429, drift_592, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1869, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1871__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_12_10438;
  kk_std_num_ddouble__ddouble x_15_10447;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1871(kk_function_t _fself, kk_box_t _b_x471, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1871(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_12_10438, kk_std_num_ddouble__ddouble x_15_10447, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1871__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1871__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1871, kk_context());
  _self->mjd = mjd;
  _self->x_12_10438 = x_12_10438;
  _self->x_15_10447 = x_15_10447;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1871(kk_function_t _fself, kk_box_t _b_x471, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1871__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1871__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_12_10438 = _self->x_12_10438; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_15_10447 = _self->x_15_10447; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_12_10438, _ctx);kk_std_num_ddouble__ddouble_dup(x_15_10447, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_string_t wild___8_593 = kk_string_unbox(_b_x471); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1872 = kk_std_time_utc__mlift_ptaiadjust_10322(x_12_10438, x_15_10447, mjd, x_9_10429, wild___8_593, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1872, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1876__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_12_10438;
  kk_std_num_ddouble__ddouble x_15_10447;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1876(kk_function_t _fself, kk_box_t _b_x473, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1876(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_12_10438, kk_std_num_ddouble__ddouble x_15_10447, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1876__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1876__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1876, kk_context());
  _self->mjd = mjd;
  _self->x_12_10438 = x_12_10438;
  _self->x_15_10447 = x_15_10447;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1876(kk_function_t _fself, kk_box_t _b_x473, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1876__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1876__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_12_10438 = _self->x_12_10438; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_15_10447 = _self->x_15_10447; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_12_10438, _ctx);kk_std_num_ddouble__ddouble_dup(x_15_10447, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_string_t wild___9_594 = kk_string_unbox(_b_x473); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1877 = kk_std_time_utc__mlift_ptaiadjust_10321(x_12_10438, x_15_10447, mjd, x_9_10429, wild___9_594, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1877, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1879__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble x_12_10438;
  kk_std_num_ddouble__ddouble x_15_10447;
  kk_std_num_ddouble__ddouble x_9_10429;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1879(kk_function_t _fself, kk_box_t _b_x475, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1879(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble x_12_10438, kk_std_num_ddouble__ddouble x_15_10447, kk_std_num_ddouble__ddouble x_9_10429, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1879__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun1879__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun1879, kk_context());
  _self->mjd = mjd;
  _self->x_12_10438 = x_12_10438;
  _self->x_15_10447 = x_15_10447;
  _self->x_9_10429 = x_9_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1879(kk_function_t _fself, kk_box_t _b_x475, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun1879__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun1879__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_12_10438 = _self->x_12_10438; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_15_10447 = _self->x_15_10447; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_9_10429 = _self->x_9_10429; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(x_12_10438, _ctx);kk_std_num_ddouble__ddouble_dup(x_15_10447, _ctx);kk_std_num_ddouble__ddouble_dup(x_9_10429, _ctx);}, {}, _ctx)
  kk_string_t wild___10_595 = kk_string_unbox(_b_x475); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1880 = kk_std_time_utc__mlift_ptaiadjust_10320(x_12_10438, x_15_10447, mjd, x_9_10429, wild___10_595, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1880, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1882__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1882(kk_function_t _fself, kk_box_t _b_x479, kk_box_t _b_x480, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1882(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1882, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1882(kk_function_t _fself, kk_box_t _b_x479, kk_box_t _b_x480, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1883;
  kk_std_num_ddouble__ddouble _x_x1884 = kk_std_num_ddouble__ddouble_unbox(_b_x479, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1885;
  double _x_x1886;
  double _x_x1887;
  kk_std_num_ddouble__ddouble _match_x992;
  kk_box_t _x_x1888 = kk_box_dup(_b_x480, _ctx); /*9984*/
  _match_x992 = kk_std_num_ddouble__ddouble_unbox(_x_x1888, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x_1 = _match_x992.hi;
    _x_x1887 = _x_1; /*float64*/
  }
  _x_x1886 = (-_x_x1887); /*float64*/
  double _x_x1889;
  double _x_x1890;
  kk_std_num_ddouble__ddouble _match_x991 = kk_std_num_ddouble__ddouble_unbox(_b_x480, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0_0 = _match_x991.lo;
    _x_x1890 = _x_0_0; /*float64*/
  }
  _x_x1889 = (-_x_x1890); /*float64*/
  _x_x1885 = kk_std_num_ddouble__new_Ddouble(_x_x1886, _x_x1889, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1883 = kk_std_num_ddouble__lp__plus__rp_(_x_x1884, _x_x1885, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1883, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1892__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1892(kk_function_t _fself, kk_box_t _b_x489, kk_box_t _b_x490, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1892(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1892, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1892(kk_function_t _fself, kk_box_t _b_x489, kk_box_t _b_x490, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1893;
  kk_std_num_ddouble__ddouble _x_x1894 = kk_std_num_ddouble__ddouble_unbox(_b_x489, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1895 = kk_std_num_ddouble__ddouble_unbox(_b_x490, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1893 = kk_std_num_ddouble__lp__star__rp_(_x_x1894, _x_x1895, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1893, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1897__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1897(kk_function_t _fself, kk_box_t _b_x496, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1897(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1897, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1897(kk_function_t _fself, kk_box_t _b_x496, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1898;
  kk_std_num_ddouble__ddouble _x_x1899 = kk_std_num_ddouble__ddouble_unbox(_b_x496, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1898 = kk_std_num_ddouble_round(_x_x1899, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1898, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1901__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1901(kk_function_t _fself, kk_box_t _b_x503, kk_box_t _b_x504, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1901(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1901, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1901(kk_function_t _fself, kk_box_t _b_x503, kk_box_t _b_x504, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1902;
  kk_std_num_ddouble__ddouble _x_x1903 = kk_std_num_ddouble__ddouble_unbox(_b_x503, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x1904;
  kk_integer_t _x_x1905;
  kk_std_core_types__optional _match_x990 = kk_std_core_types__optional_unbox(_b_x504, KK_OWNED, _ctx); /*? int*/;
  if (kk_std_core_types__is_Optional(_match_x990, _ctx)) {
    kk_box_t _box_x499 = _match_x990._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x499, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x990, _ctx);
    _x_x1905 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x990, _ctx);
    _x_x1905 = kk_integer_from_small(0); /*int*/
  }
  _x_x1904 = kk_integer_clamp32(_x_x1905,kk_context()); /*int32*/
  _x_x1902 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1903, _x_x1904, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1902, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1907__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1907(kk_function_t _fself, kk_box_t _b_x513, kk_box_t _b_x514, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1907(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1907, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1907(kk_function_t _fself, kk_box_t _b_x513, kk_box_t _b_x514, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1908;
  kk_std_num_ddouble__ddouble _x_x1909 = kk_std_num_ddouble__ddouble_unbox(_b_x513, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1910;
  double _x_x1911;
  double _x_x1912;
  kk_std_num_ddouble__ddouble _match_x989;
  kk_box_t _x_x1913 = kk_box_dup(_b_x514, _ctx); /*9984*/
  _match_x989 = kk_std_num_ddouble__ddouble_unbox(_x_x1913, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x_2 = _match_x989.hi;
    _x_x1912 = _x_2; /*float64*/
  }
  _x_x1911 = (-_x_x1912); /*float64*/
  double _x_x1914;
  double _x_x1915;
  kk_std_num_ddouble__ddouble _match_x988 = kk_std_num_ddouble__ddouble_unbox(_b_x514, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0_1 = _match_x988.lo;
    _x_x1915 = _x_0_1; /*float64*/
  }
  _x_x1914 = (-_x_x1915); /*float64*/
  _x_x1910 = kk_std_num_ddouble__new_Ddouble(_x_x1911, _x_x1914, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1908 = kk_std_num_ddouble__lp__plus__rp_(_x_x1909, _x_x1910, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1908, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1917__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1917(kk_function_t _fself, kk_box_t _b_x523, kk_box_t _b_x524, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1917(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1917, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1917(kk_function_t _fself, kk_box_t _b_x523, kk_box_t _b_x524, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1918;
  kk_std_num_ddouble__ddouble _x_x1919 = kk_std_num_ddouble__ddouble_unbox(_b_x523, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1920 = kk_std_num_ddouble__ddouble_unbox(_b_x524, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1918 = kk_std_num_ddouble__lp__star__rp_(_x_x1919, _x_x1920, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1918, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1922__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1922(kk_function_t _fself, kk_box_t _b_x530, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1922(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1922, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1922(kk_function_t _fself, kk_box_t _b_x530, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1923;
  kk_std_num_ddouble__ddouble _x_x1924 = kk_std_num_ddouble__ddouble_unbox(_b_x530, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1923 = kk_std_num_ddouble_round(_x_x1924, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1923, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1926__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1926(kk_function_t _fself, kk_box_t _b_x537, kk_box_t _b_x538, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1926(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1926, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1926(kk_function_t _fself, kk_box_t _b_x537, kk_box_t _b_x538, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1927;
  kk_std_num_ddouble__ddouble _x_x1928 = kk_std_num_ddouble__ddouble_unbox(_b_x537, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x1929;
  kk_integer_t _x_x1930;
  kk_std_core_types__optional _match_x987 = kk_std_core_types__optional_unbox(_b_x538, KK_OWNED, _ctx); /*? int*/;
  if (kk_std_core_types__is_Optional(_match_x987, _ctx)) {
    kk_box_t _box_x533 = _match_x987._cons._Optional.value;
    kk_integer_t _uniq_leap_1214_0 = kk_integer_unbox(_box_x533, _ctx);
    kk_integer_dup(_uniq_leap_1214_0, _ctx);
    kk_std_core_types__optional_drop(_match_x987, _ctx);
    _x_x1930 = _uniq_leap_1214_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x987, _ctx);
    _x_x1930 = kk_integer_from_small(0); /*int*/
  }
  _x_x1929 = kk_integer_clamp32(_x_x1930,kk_context()); /*int32*/
  _x_x1927 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1928, _x_x1929, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1927, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun1932__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun1932(kk_function_t _fself, kk_box_t _b_x553, kk_box_t _b_x554, kk_box_t _b_x555, kk_box_t _b_x556, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun1932(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun1932, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun1932(kk_function_t _fself, kk_box_t _b_x553, kk_box_t _b_x554, kk_box_t _b_x555, kk_box_t _b_x556, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp utc_start_596 = kk_std_time_timestamp__timestamp_unbox(_b_x553, KK_OWNED, _ctx); /*std/time/utc/utc-timestamp*/;
  kk_std_num_ddouble__ddouble offset_597 = kk_std_num_ddouble__ddouble_unbox(_b_x554, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_core_types__optional drift_start_598 = kk_std_core_types__optional_unbox(_b_x555, KK_OWNED, _ctx); /*? std/time/utc/utc-timestamp*/;
  kk_std_core_types__optional drift_0_0_599 = kk_std_core_types__optional_unbox(_b_x556, KK_OWNED, _ctx); /*? std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1933;
  kk_std_time_timestamp__timestamp _x_x1934;
  if (kk_std_core_types__is_Optional(drift_start_598, _ctx)) {
    kk_box_t _box_x544 = drift_start_598._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_396 = kk_std_time_timestamp__timestamp_unbox(_box_x544, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_396, _ctx);
    kk_std_core_types__optional_drop(drift_start_598, _ctx);
    _x_x1934 = _uniq_drift_start_396; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start_598, _ctx);
    _x_x1934 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/utc/utc-timestamp*/
  }
  kk_std_num_ddouble__ddouble _x_x1935;
  if (kk_std_core_types__is_Optional(drift_0_0_599, _ctx)) {
    kk_box_t _box_x545 = drift_0_0_599._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_400 = kk_std_num_ddouble__ddouble_unbox(_box_x545, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift_0_0_599, _ctx);
    _x_x1935 = _uniq_drift_400; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift_0_0_599, _ctx);
    _x_x1935 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  _x_x1933 = kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, utc_start_596, offset_597, _x_x1934, _x_x1935, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1933, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc_ptaiadjust(kk_context_t* _ctx) { /* () -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_10402 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_string_drop(x_10402, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1772 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1773(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1772, KK_OWNED, _ctx);
  }
  {
    kk_char_t x_0_10405;
    kk_string_t _x_x1776;
    kk_define_string_literal(, _s_x1777, 1, "=", _ctx)
    _x_x1776 = kk_string_dup(_s_x1777, _ctx); /*string*/
    x_0_10405 = kk_std_text_parse_none_of(_x_x1776, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1778 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1779(_ctx), _ctx); /*2419*/
      return kk_std_time_utc__leap_adjust_unbox(_x_x1778, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list x_1_10408 = kk_std_text_parse_many_acc(kk_std_time_utc_new_ptaiadjust_fun1782(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
      kk_std_core_types__list_drop(x_1_10408, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1786 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1787(_ctx), _ctx); /*2419*/
        return kk_std_time_utc__leap_adjust_unbox(_x_x1786, KK_OWNED, _ctx);
      }
      {
        kk_string_t x_2_10411;
        kk_string_t _x_x1790;
        kk_define_string_literal(, _s_x1791, 3, "=JD", _ctx)
        _x_x1790 = kk_string_dup(_s_x1791, _ctx); /*string*/
        x_2_10411 = kk_std_text_parse_pstring(_x_x1790, _ctx); /*string*/
        kk_string_drop(x_2_10411, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1792 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1793(_ctx), _ctx); /*2419*/
          return kk_std_time_utc__leap_adjust_unbox(_x_x1792, KK_OWNED, _ctx);
        }
        {
          kk_string_t x_3_10414 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
          kk_string_drop(x_3_10414, _ctx);
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1796 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1797(_ctx), _ctx); /*2419*/
            return kk_std_time_utc__leap_adjust_unbox(_x_x1796, KK_OWNED, _ctx);
          }
          {
            kk_std_num_ddouble__ddouble x_4_10417;
            kk_box_t _x_x1800 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc_new_ptaiadjust_fun1801(_ctx), kk_std_time_utc_new_ptaiadjust_fun1803(_ctx), _ctx); /*1542*/
            x_4_10417 = kk_std_num_ddouble__ddouble_unbox(_x_x1800, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x1805 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1806(_ctx), _ctx); /*2419*/
              return kk_std_time_utc__leap_adjust_unbox(_x_x1805, KK_OWNED, _ctx);
            }
            {
              kk_std_num_ddouble__ddouble mjd;
              kk_box_t _x_x1809 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1810(_ctx), kk_std_num_ddouble__ddouble_box(x_4_10417, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_jd_epoch_shift, _ctx), _ctx); /*9985*/
              mjd = kk_std_num_ddouble__ddouble_unbox(_x_x1809, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
              kk_string_t x_6_10420 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
              kk_string_drop(x_6_10420, _ctx);
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x1819 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1820(mjd, _ctx), _ctx); /*2419*/
                return kk_std_time_utc__leap_adjust_unbox(_x_x1819, KK_OWNED, _ctx);
              }
              {
                kk_string_t x_7_10423;
                kk_string_t _x_x1822;
                kk_define_string_literal(, _s_x1823, 8, "TAI-UTC=", _ctx)
                _x_x1822 = kk_string_dup(_s_x1823, _ctx); /*string*/
                x_7_10423 = kk_std_text_parse_pstring(_x_x1822, _ctx); /*string*/
                kk_string_drop(x_7_10423, _ctx);
                if (kk_yielding(kk_context())) {
                  kk_box_t _x_x1824 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1825(mjd, _ctx), _ctx); /*2419*/
                  return kk_std_time_utc__leap_adjust_unbox(_x_x1824, KK_OWNED, _ctx);
                }
                {
                  kk_string_t x_8_10426 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
                  kk_string_drop(x_8_10426, _ctx);
                  if (kk_yielding(kk_context())) {
                    kk_box_t _x_x1827 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1828(mjd, _ctx), _ctx); /*2419*/
                    return kk_std_time_utc__leap_adjust_unbox(_x_x1827, KK_OWNED, _ctx);
                  }
                  {
                    kk_std_num_ddouble__ddouble x_9_10429;
                    kk_box_t _x_x1830 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc_new_ptaiadjust_fun1831(_ctx), kk_std_time_utc_new_ptaiadjust_fun1833(_ctx), _ctx); /*1542*/
                    x_9_10429 = kk_std_num_ddouble__ddouble_unbox(_x_x1830, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                    if (kk_yielding(kk_context())) {
                      kk_box_t _x_x1835 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1836(mjd, _ctx), _ctx); /*2419*/
                      return kk_std_time_utc__leap_adjust_unbox(_x_x1835, KK_OWNED, _ctx);
                    }
                    {
                      kk_char_t x_10_10432 = kk_std_text_parse_no_digit(_ctx); /*char*/;
                      if (kk_yielding(kk_context())) {
                        kk_box_t _x_x1838 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1839(mjd, x_9_10429, _ctx), _ctx); /*2419*/
                        return kk_std_time_utc__leap_adjust_unbox(_x_x1838, KK_OWNED, _ctx);
                      }
                      {
                        kk_std_core_types__list x_11_10435 = kk_std_text_parse_many_acc(kk_std_time_utc_new_ptaiadjust_fun1841(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
                        kk_std_core_types__list_drop(x_11_10435, _ctx);
                        if (kk_yielding(kk_context())) {
                          kk_box_t _x_x1843 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1844(mjd, x_9_10429, _ctx), _ctx); /*2419*/
                          return kk_std_time_utc__leap_adjust_unbox(_x_x1843, KK_OWNED, _ctx);
                        }
                        {
                          kk_std_num_ddouble__ddouble x_12_10438;
                          kk_box_t _x_x1846 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc_new_ptaiadjust_fun1847(_ctx), kk_std_time_utc_new_ptaiadjust_fun1849(_ctx), _ctx); /*1542*/
                          x_12_10438 = kk_std_num_ddouble__ddouble_unbox(_x_x1846, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                          if (kk_yielding(kk_context())) {
                            kk_box_t _x_x1851 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1852(mjd, x_9_10429, _ctx), _ctx); /*2419*/
                            return kk_std_time_utc__leap_adjust_unbox(_x_x1851, KK_OWNED, _ctx);
                          }
                          {
                            kk_char_t x_13_10441 = kk_std_text_parse_no_digit(_ctx); /*char*/;
                            if (kk_yielding(kk_context())) {
                              kk_box_t _x_x1854 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1855(mjd, x_12_10438, x_9_10429, _ctx), _ctx); /*2419*/
                              return kk_std_time_utc__leap_adjust_unbox(_x_x1854, KK_OWNED, _ctx);
                            }
                            {
                              kk_std_core_types__list x_14_10444 = kk_std_text_parse_many_acc(kk_std_time_utc_new_ptaiadjust_fun1857(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
                              kk_std_core_types__list_drop(x_14_10444, _ctx);
                              if (kk_yielding(kk_context())) {
                                kk_box_t _x_x1859 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1860(mjd, x_12_10438, x_9_10429, _ctx), _ctx); /*2419*/
                                return kk_std_time_utc__leap_adjust_unbox(_x_x1859, KK_OWNED, _ctx);
                              }
                              {
                                kk_std_num_ddouble__ddouble x_15_10447;
                                kk_box_t _x_x1862 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_utc_new_ptaiadjust_fun1863(_ctx), kk_std_time_utc_new_ptaiadjust_fun1865(_ctx), _ctx); /*1542*/
                                x_15_10447 = kk_std_num_ddouble__ddouble_unbox(_x_x1862, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                if (kk_yielding(kk_context())) {
                                  kk_box_t _x_x1867 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1868(mjd, x_12_10438, x_9_10429, _ctx), _ctx); /*2419*/
                                  return kk_std_time_utc__leap_adjust_unbox(_x_x1867, KK_OWNED, _ctx);
                                }
                                {
                                  kk_string_t x_16_10450 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
                                  kk_string_drop(x_16_10450, _ctx);
                                  if (kk_yielding(kk_context())) {
                                    kk_box_t _x_x1870 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1871(mjd, x_12_10438, x_15_10447, x_9_10429, _ctx), _ctx); /*2419*/
                                    return kk_std_time_utc__leap_adjust_unbox(_x_x1870, KK_OWNED, _ctx);
                                  }
                                  {
                                    kk_string_t x_17_10453;
                                    kk_string_t _x_x1873;
                                    kk_define_string_literal(, _s_x1874, 1, "S", _ctx)
                                    _x_x1873 = kk_string_dup(_s_x1874, _ctx); /*string*/
                                    x_17_10453 = kk_std_text_parse_pstring(_x_x1873, _ctx); /*string*/
                                    kk_string_drop(x_17_10453, _ctx);
                                    if (kk_yielding(kk_context())) {
                                      kk_box_t _x_x1875 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1876(mjd, x_12_10438, x_15_10447, x_9_10429, _ctx), _ctx); /*2419*/
                                      return kk_std_time_utc__leap_adjust_unbox(_x_x1875, KK_OWNED, _ctx);
                                    }
                                    {
                                      kk_string_t x_18_10456 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
                                      kk_string_drop(x_18_10456, _ctx);
                                      if (kk_yielding(kk_context())) {
                                        kk_box_t _x_x1878 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun1879(mjd, x_12_10438, x_15_10447, x_9_10429, _ctx), _ctx); /*2419*/
                                        return kk_std_time_utc__leap_adjust_unbox(_x_x1878, KK_OWNED, _ctx);
                                      }
                                      {
                                        kk_std_num_ddouble__ddouble _x_x1_2_10289;
                                        kk_box_t _x_x1881 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1882(_ctx), kk_std_num_ddouble__ddouble_box(mjd, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_mjd_epoch_shift, _ctx), _ctx); /*9985*/
                                        _x_x1_2_10289 = kk_std_num_ddouble__ddouble_unbox(_x_x1881, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_std_num_ddouble__ddouble _x_x1_1_10288;
                                        kk_box_t _x_x1891 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1892(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_2_10289, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*9985*/
                                        _x_x1_1_10288 = kk_std_num_ddouble__ddouble_unbox(_x_x1891, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_std_num_ddouble__ddouble _x_x1_0_10286;
                                        kk_box_t _x_x1896 = kk_std_core_hnd__open_none1(kk_std_time_utc_new_ptaiadjust_fun1897(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_1_10288, _ctx), _ctx); /*9904*/
                                        _x_x1_0_10286 = kk_std_num_ddouble__ddouble_unbox(_x_x1896, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
                                        kk_std_time_timestamp__timestamp start;
                                        kk_box_t _x_x1900 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1901(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_0_10286, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
                                        start = kk_std_time_timestamp__timestamp_unbox(_x_x1900, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
                                        kk_std_num_ddouble__ddouble _x_x1_6_10296;
                                        kk_box_t _x_x1906 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1907(_ctx), kk_std_num_ddouble__ddouble_box(x_12_10438, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_mjd_epoch_shift, _ctx), _ctx); /*9985*/
                                        _x_x1_6_10296 = kk_std_num_ddouble__ddouble_unbox(_x_x1906, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_std_num_ddouble__ddouble _x_x1_5_10295;
                                        kk_box_t _x_x1916 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1917(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_6_10296, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*9985*/
                                        _x_x1_5_10295 = kk_std_num_ddouble__ddouble_unbox(_x_x1916, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_std_num_ddouble__ddouble _x_x1_4_10293;
                                        kk_box_t _x_x1921 = kk_std_core_hnd__open_none1(kk_std_time_utc_new_ptaiadjust_fun1922(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_5_10295, _ctx), _ctx); /*9904*/
                                        _x_x1_4_10293 = kk_std_num_ddouble__ddouble_unbox(_x_x1921, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
                                        kk_std_time_timestamp__timestamp dstart;
                                        kk_box_t _x_x1925 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun1926(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_4_10293, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
                                        dstart = kk_std_time_timestamp__timestamp_unbox(_x_x1925, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
                                        kk_box_t _x_x1931;
                                        kk_box_t _x_x1936;
                                        kk_std_core_types__optional _x_x1937 = kk_std_core_types__new_Optional(kk_std_time_timestamp__timestamp_box(dstart, _ctx), _ctx); /*? 7*/
                                        _x_x1936 = kk_std_core_types__optional_box(_x_x1937, _ctx); /*10184*/
                                        kk_box_t _x_x1938;
                                        kk_std_core_types__optional _x_x1939 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(x_15_10447, _ctx), _ctx); /*? 7*/
                                        _x_x1938 = kk_std_core_types__optional_box(_x_x1939, _ctx); /*10185*/
                                        _x_x1931 = kk_std_core_hnd__open_none4(kk_std_time_utc_new_ptaiadjust_fun1932(_ctx), kk_std_time_timestamp__timestamp_box(start, _ctx), kk_std_num_ddouble__ddouble_box(x_9_10429, _ctx), _x_x1936, _x_x1938, _ctx); /*10186*/
                                        return kk_std_time_utc__leap_adjust_unbox(_x_x1931, KK_OWNED, _ctx);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941__t {
  struct kk_function_s _base;
  kk_std_time_utc__leap_adjust x;
};
static kk_box_t kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941(kk_function_t _fself, kk_box_t _b_x601, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_parse_taiadjust_10340_fun1941(kk_std_time_utc__leap_adjust x, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941(kk_function_t _fself, kk_box_t _b_x601, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941__t* _self = kk_function_as(struct kk_std_time_utc__mlift_parse_taiadjust_10340_fun1941__t*, _fself, _ctx);
  kk_std_time_utc__leap_adjust x = _self->x; /* std/time/utc/leap-adjust */
  kk_drop_match(_self, {kk_std_time_utc__leap_adjust_dup(x, _ctx);}, {}, _ctx)
  kk_unit_t wild___603 = kk_Unit;
  kk_unit_unbox(_b_x601);
  return kk_std_time_utc__leap_adjust_box(x, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_parse_taiadjust_10340(kk_std_time_utc__leap_adjust x, kk_context_t* _ctx) { /* (x : leap-adjust) -> std/text/parse/parse leap-adjust */ 
  kk_unit_t x_0_10459 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1940 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_parse_taiadjust_10340_fun1941(x, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1940, KK_OWNED, _ctx);
  }
  {
    return x;
  }
}


// lift anonymous function
struct kk_std_time_utc_parse_taiadjust_fun1944__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_taiadjust_fun1944(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_taiadjust_fun1944(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_taiadjust_fun1944, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_utc_parse_taiadjust_fun1947__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_taiadjust_fun1947(kk_function_t _fself, kk_box_t _b_x605, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_taiadjust_fun1947(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_taiadjust_fun1947, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_parse_taiadjust_fun1947(kk_function_t _fself, kk_box_t _b_x605, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x1948;
  kk_std_time_utc__leap_adjust _x_x1949 = kk_std_time_utc__leap_adjust_unbox(_b_x605, KK_OWNED, _ctx); /*std/time/utc/leap-adjust*/
  _x_x1948 = kk_std_time_utc__mlift_parse_taiadjust_10340(_x_x1949, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1948, _ctx);
}
static kk_box_t kk_std_time_utc_parse_taiadjust_fun1944(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust x_10463 = kk_std_time_utc_ptaiadjust(_ctx); /*std/time/utc/leap-adjust*/;
  kk_std_time_utc__leap_adjust _x_x1945;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10463, (KK_I32(2)), _ctx);
    kk_box_t _x_x1946 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_parse_taiadjust_fun1947(_ctx), _ctx); /*2419*/
    _x_x1945 = kk_std_time_utc__leap_adjust_unbox(_x_x1946, KK_OWNED, _ctx); /*std/time/utc/leap-adjust*/
  }
  else {
    _x_x1945 = kk_std_time_utc__mlift_parse_taiadjust_10340(x_10463, _ctx); /*std/time/utc/leap-adjust*/
  }
  return kk_std_time_utc__leap_adjust_box(_x_x1945, _ctx);
}

kk_std_core_types__maybe kk_std_time_utc_parse_taiadjust(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> maybe<leap-adjust> */ 
  kk_std_core_sslice__sslice input_10123;
  kk_string_t _x_x1942 = kk_string_dup(line, _ctx); /*string*/
  kk_integer_t _x_x1943 = kk_string_len_int(line,kk_context()); /*int*/
  input_10123 = kk_std_core_sslice__new_Sslice(_x_x1942, kk_integer_from_small(0), _x_x1943, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10122 = kk_std_text_parse_parse(input_10123, kk_std_time_utc_new_parse_taiadjust_fun1944(_ctx), _ctx); /*std/text/parse/parse-error<std/time/utc/leap-adjust>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10122, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x1950 = kk_std_text_parse__as_ParseOk(perr_10122, _ctx);
    kk_box_t _box_x611 = _con_x1950->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x1950->rest;
    kk_std_time_utc__leap_adjust x_0 = kk_std_time_utc__leap_adjust_unbox(_box_x611, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10122, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(perr_10122, _ctx);
    }
    else {
      kk_std_time_utc__leap_adjust_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_10122, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_time_utc__leap_adjust_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x1951 = kk_std_text_parse__as_ParseError(perr_10122, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x1951->rest;
    kk_string_t msg = _con_x1951->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10122, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10122, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10122, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Parse the standard UTC leap second adjustment file in the "old" .dat format as
// in <https://maia.usno.navy.mil/ser7/tai-utc.dat>, where entries have the shape
// ````
// 1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S
// ````
// which specifies the start time (`JD 2437300.5`), new TAI-UTC offset
// (`1.4228180`s), and the drift, starting at `37300` MJD of 0.001296s per day.
// Lines that start with ``#`` are comments. As an extension you can have an
// expiration date on a line that starts with ``#@`` followed by seconds since
// the NTP epoch (1900-01-01). Just as in a standard IERS leap second file.


// lift anonymous function
struct kk_std_time_utc_parse_leap_seconds_dat_fun1955__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_utc_parse_leap_seconds_dat_fun1955(kk_function_t _fself, kk_box_t _b_x616, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_leap_seconds_dat_fun1955(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_leap_seconds_dat_fun1955, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_utc_parse_leap_seconds_dat_fun1955(kk_function_t _fself, kk_box_t _b_x616, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1956 = kk_string_unbox(_b_x616); /*string*/
  return kk_std_time_utc_parse_taiadjust(_x_x1956, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_parse_leap_seconds_dat(kk_string_t leaps, kk_context_t* _ctx) { /* (leaps : string) -> leaps-table */ 
  kk_vector_t v_10011;
  kk_string_t _x_x1952 = kk_string_dup(leaps, _ctx); /*string*/
  kk_string_t _x_x1953;
  kk_define_string_literal(, _s_x1954, 1, "\n", _ctx)
  _x_x1953 = kk_string_dup(_s_x1954, _ctx); /*string*/
  v_10011 = kk_string_splitv(_x_x1952,_x_x1953,kk_context()); /*vector<string>*/
  kk_std_core_types__list _b_x614_617 = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  kk_std_core_types__list xs_10126 = kk_std_core_list_flatmap_maybe(_b_x614_617, kk_std_time_utc_new_parse_leap_seconds_dat_fun1955(_ctx), _ctx); /*list<std/time/utc/leap-adjust>*/;
  kk_std_core_types__list adjusts = kk_std_core_list_reverse_acc(kk_std_core_types__new_Nil(_ctx), xs_10126, _ctx); /*list<std/time/utc/leap-adjust>*/;
  kk_std_time_instant__instant expire;
  kk_std_core_types__list _x_x1957 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
  expire = kk_std_time_utc_parse_leap_expire(leaps, _x_x1957, _ctx); /*std/time/instant/instant*/
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx);
}
kk_declare_string_literal(static, kk_std_time_utc_default_leap_seconds_pre72, 2922, "\n  # from: Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.\n  1958 JAN  1 =JD 2436204.5     TAI-UTC= 0.0  S + (MJD - 36204.) X 0.00073458 S\n  1958 JAN 15 =JD 2436219.29167 TAI-UTC= 0.02 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB  5 =JD 2436240.29167 TAI-UTC= 0.04 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB 19 =JD 2436254.29167 TAI-UTC= 0.06 S + (MJD - 36204.) X 0.00073458 S\n  1958 APR  9 =JD 2436303.29167 TAI-UTC= 0.08 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUN 11 =JD 2436366.29167 TAI-UTC= 0.10 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL  2 =JD 2436387.29167 TAI-UTC= 0.12 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL 16 =JD 2436401.29167 TAI-UTC= 0.14 S + (MJD - 36204.) X 0.00073458 S\n  1958 OCT 22 =JD 2436499.29167 TAI-UTC= 0.16 S + (MJD - 36204.) X 0.00073458 S\n  1958 NOV 26 =JD 2436534.29167 TAI-UTC= 0.18 S + (MJD - 36204.) X 0.00073458 S\n  1958 DEC 24 =JD 2436562.29167 TAI-UTC= 0.20 S + (MJD - 36204.) X 0.00073458 S\n\n  1959 JAN  1 =JD 2436569.5     TAI-UTC= 0.4681220 S + (MJD - 36569.) X 0.000864 S\n  1959 JAN 28 =JD 2436597.29167 TAI-UTC= 0.4881220 S + (MJD - 36569.) X 0.000864 S\n  1959 FEB 25 =JD 2436625.29167 TAI-UTC= 0.5081220 S + (MJD - 36569.) X 0.000864 S\n  1959 APR  5 =JD 2436664.29167 TAI-UTC= 0.5281220 S + (MJD - 36569.) X 0.000864 S\n  1959 AUG 26 =JD 2436807.29167 TAI-UTC= 0.5481220 S + (MJD - 36569.) X 0.000864 S\n  1959 SEP 30 =JD 2436842.29167 TAI-UTC= 0.5681220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV  4 =JD 2436877.29167 TAI-UTC= 0.5881220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV 18 =JD 2436891.29167 TAI-UTC= 0.6081220 S + (MJD - 36569.) X 0.000864 S\n  1959 DEC 16 =JD 2436919.29167 TAI-UTC= 0.6281220 S + (MJD - 36569.) X 0.000864 S\n  1960 JAN  1 =JD 2436934.5     TAI-UTC= 0.9434820 S + (MJD - 36934.) X 0.001296 S\n\n  # from: https://maia.usno.navy.mil/ser7/tai-utc.dat\n  1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S\n  1961 AUG  1 =JD 2437512.5  TAI-UTC=   1.3728180 S + (MJD - 37300.) X 0.001296 S\n  1962 JAN  1 =JD 2437665.5  TAI-UTC=   1.8458580 S + (MJD - 37665.) X 0.0011232S\n  1963 NOV  1 =JD 2438334.5  TAI-UTC=   1.9458580 S + (MJD - 37665.) X 0.0011232S\n  1964 JAN  1 =JD 2438395.5  TAI-UTC=   3.2401300 S + (MJD - 38761.) X 0.001296 S\n  1964 APR  1 =JD 2438486.5  TAI-UTC=   3.3401300 S + (MJD - 38761.) X 0.001296 S\n  1964 SEP  1 =JD 2438639.5  TAI-UTC=   3.4401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JAN  1 =JD 2438761.5  TAI-UTC=   3.5401300 S + (MJD - 38761.) X 0.001296 S\n  1965 MAR  1 =JD 2438820.5  TAI-UTC=   3.6401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JUL  1 =JD 2438942.5  TAI-UTC=   3.7401300 S + (MJD - 38761.) X 0.001296 S\n  1965 SEP  1 =JD 2439004.5  TAI-UTC=   3.8401300 S + (MJD - 38761.) X 0.001296 S\n  1966 JAN  1 =JD 2439126.5  TAI-UTC=   4.3131700 S + (MJD - 39126.) X 0.002592 S\n  1968 FEB  1 =JD 2439887.5  TAI-UTC=   4.2131700 S + (MJD - 39126.) X 0.002592 S")
 
// Leap second table upto (but not including) 1972-01-01 UTC


// lift anonymous function
struct kk_std_time_utc_leaps_table_pre1972_fun1962__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_utc_leaps_table_pre1972_fun1962(kk_function_t _fself, kk_box_t _b_x621, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_leaps_table_pre1972_fun1962(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_leaps_table_pre1972_fun1962, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_utc_leaps_table_pre1972_fun1962(kk_function_t _fself, kk_box_t _b_x621, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1963 = kk_string_unbox(_b_x621); /*string*/
  return kk_std_time_utc_parse_taiadjust(_x_x1963, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_pre1972;
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10341_fun1968__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1968(kk_function_t _fself, kk_box_t _b_x627, kk_box_t _b_x628, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10341_fun1968(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10341_fun1968, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1968(kk_function_t _fself, kk_box_t _b_x627, kk_box_t _b_x628, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1969;
  kk_integer_t _x_x1970 = kk_integer_unbox(_b_x627, _ctx); /*int*/
  kk_std_core_types__optional _x_x1971 = kk_std_core_types__optional_unbox(_b_x628, KK_OWNED, _ctx); /*? float64*/
  _x_x1969 = kk_std_time_timestamp_int_fs_timespan(_x_x1970, _x_x1971, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_num_ddouble__ddouble_box(_x_x1969, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10341_fun1973__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1973(kk_function_t _fself, kk_box_t _b_x635, kk_box_t _b_x636, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10341_fun1973(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10341_fun1973, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1973(kk_function_t _fself, kk_box_t _b_x635, kk_box_t _b_x636, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1974;
  kk_std_num_ddouble__ddouble _x_x1975 = kk_std_num_ddouble__ddouble_unbox(_b_x635, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1976;
  double _x_x1977;
  double _x_x1978;
  kk_std_num_ddouble__ddouble _match_x965;
  kk_box_t _x_x1979 = kk_box_dup(_b_x636, _ctx); /*9984*/
  _match_x965 = kk_std_num_ddouble__ddouble_unbox(_x_x1979, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = _match_x965.hi;
    _x_x1978 = _x; /*float64*/
  }
  _x_x1977 = (-_x_x1978); /*float64*/
  double _x_x1980;
  double _x_x1981;
  kk_std_num_ddouble__ddouble _match_x964 = kk_std_num_ddouble__ddouble_unbox(_b_x636, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0 = _match_x964.lo;
    _x_x1981 = _x_0; /*float64*/
  }
  _x_x1980 = (-_x_x1981); /*float64*/
  _x_x1976 = kk_std_num_ddouble__new_Ddouble(_x_x1977, _x_x1980, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1974 = kk_std_num_ddouble__lp__plus__rp_(_x_x1975, _x_x1976, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1974, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10341_fun1983__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1983(kk_function_t _fself, kk_box_t _b_x646, kk_box_t _b_x647, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10341_fun1983(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10341_fun1983, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1983(kk_function_t _fself, kk_box_t _b_x646, kk_box_t _b_x647, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1984;
  kk_std_num_ddouble__ddouble _x_x1985 = kk_std_num_ddouble__ddouble_unbox(_b_x646, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x1986;
  kk_integer_t _x_x1987;
  kk_std_core_types__optional _match_x963 = kk_std_core_types__optional_unbox(_b_x647, KK_OWNED, _ctx); /*? int*/;
  if (kk_std_core_types__is_Optional(_match_x963, _ctx)) {
    kk_box_t _box_x642 = _match_x963._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x642, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x963, _ctx);
    _x_x1987 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x963, _ctx);
    _x_x1987 = kk_integer_from_small(0); /*int*/
  }
  _x_x1986 = kk_integer_clamp32(_x_x1987,kk_context()); /*int32*/
  _x_x1984 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1985, _x_x1986, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1984, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10341_fun1989__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1989(kk_function_t _fself, kk_box_t _b_x656, kk_box_t _b_x657, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10341_fun1989(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10341_fun1989, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1989(kk_function_t _fself, kk_box_t _b_x656, kk_box_t _b_x657, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1990;
  kk_integer_t _x_x1991 = kk_integer_unbox(_b_x656, _ctx); /*int*/
  kk_std_core_types__optional _x_x1992 = kk_std_core_types__optional_unbox(_b_x657, KK_OWNED, _ctx); /*? float64*/
  _x_x1990 = kk_std_time_timestamp_int_fs_timespan(_x_x1991, _x_x1992, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_num_ddouble__ddouble_box(_x_x1990, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10341_fun1994__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1994(kk_function_t _fself, kk_box_t _b_x670, kk_box_t _b_x671, kk_box_t _b_x672, kk_box_t _b_x673, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10341_fun1994(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10341_fun1994, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10341_fun1994(kk_function_t _fself, kk_box_t _b_x670, kk_box_t _b_x671, kk_box_t _b_x672, kk_box_t _b_x673, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp utc_start_681 = kk_std_time_timestamp__timestamp_unbox(_b_x670, KK_OWNED, _ctx); /*std/time/utc/utc-timestamp*/;
  kk_std_num_ddouble__ddouble offset_682 = kk_std_num_ddouble__ddouble_unbox(_b_x671, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_core_types__optional drift_start_683 = kk_std_core_types__optional_unbox(_b_x672, KK_OWNED, _ctx); /*? std/time/utc/utc-timestamp*/;
  kk_std_core_types__optional drift_684 = kk_std_core_types__optional_unbox(_b_x673, KK_OWNED, _ctx); /*? std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1995;
  kk_std_time_timestamp__timestamp _x_x1996;
  if (kk_std_core_types__is_Optional(drift_start_683, _ctx)) {
    kk_box_t _box_x661 = drift_start_683._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_396 = kk_std_time_timestamp__timestamp_unbox(_box_x661, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_396, _ctx);
    kk_std_core_types__optional_drop(drift_start_683, _ctx);
    _x_x1996 = _uniq_drift_start_396; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start_683, _ctx);
    _x_x1996 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/utc/utc-timestamp*/
  }
  kk_std_num_ddouble__ddouble _x_x1997;
  if (kk_std_core_types__is_Optional(drift_684, _ctx)) {
    kk_box_t _box_x662 = drift_684._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_400 = kk_std_num_ddouble__ddouble_unbox(_box_x662, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift_684, _ctx);
    _x_x1997 = _uniq_drift_400; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift_684, _ctx);
    _x_x1997 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  _x_x1995 = kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, utc_start_681, offset_682, _x_x1996, _x_x1997, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1995, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10341(kk_integer_t ntpsecs, kk_integer_t adjust, kk_context_t* _ctx) { /* (ntpsecs : int, adjust : int) -> std/text/parse/parse leap-adjust */ 
  kk_std_num_ddouble__ddouble _x_x1_1_10310;
  kk_box_t _x_x1967 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_pleap_10341_fun1968(_ctx), kk_integer_box(ntpsecs, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  _x_x1_1_10310 = kk_std_num_ddouble__ddouble_unbox(_x_x1967, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_0_10308;
  kk_box_t _x_x1972 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_pleap_10341_fun1973(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_1_10310, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_ntp2000, _ctx), _ctx); /*9985*/
  _x_x1_0_10308 = kk_std_num_ddouble__ddouble_unbox(_x_x1972, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp _x_x1_10304;
  kk_box_t _x_x1982 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_pleap_10341_fun1983(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_0_10308, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  _x_x1_10304 = kk_std_time_timestamp__timestamp_unbox(_x_x1982, KK_OWNED, _ctx); /*std/time/utc/utc-timestamp*/
  kk_std_num_ddouble__ddouble _x_x2_10305;
  kk_box_t _x_x1988 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_pleap_10341_fun1989(_ctx), kk_integer_box(adjust, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  _x_x2_10305 = kk_std_num_ddouble__ddouble_unbox(_x_x1988, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_box_t _x_x1993;
  kk_box_t _x_x1998;
  kk_std_core_types__optional _x_x1999;
  kk_box_t _x_x2000;
  kk_std_time_timestamp__timestamp _x_x2001 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
  _x_x2000 = kk_std_time_timestamp__timestamp_box(_x_x2001, _ctx); /*7*/
  _x_x1999 = kk_std_core_types__new_Optional(_x_x2000, _ctx); /*? 7*/
  _x_x1998 = kk_std_core_types__optional_box(_x_x1999, _ctx); /*10184*/
  kk_box_t _x_x2002;
  kk_std_core_types__optional _x_x2003 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx), _ctx); /*? 7*/
  _x_x2002 = kk_std_core_types__optional_box(_x_x2003, _ctx); /*10185*/
  _x_x1993 = kk_std_core_hnd__open_none4(kk_std_time_utc__new_mlift_pleap_10341_fun1994(_ctx), kk_std_time_timestamp__timestamp_box(_x_x1_10304, _ctx), kk_std_num_ddouble__ddouble_box(_x_x2_10305, _ctx), _x_x1998, _x_x2002, _ctx); /*10186*/
  return kk_std_time_utc__leap_adjust_unbox(_x_x1993, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10342_fun2005__t {
  struct kk_function_s _base;
  kk_integer_t ntpsecs;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10342_fun2005(kk_function_t _fself, kk_box_t _b_x686, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10342_fun2005(kk_integer_t ntpsecs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10342_fun2005__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_pleap_10342_fun2005__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_pleap_10342_fun2005, kk_context());
  _self->ntpsecs = ntpsecs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10342_fun2005(kk_function_t _fself, kk_box_t _b_x686, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10342_fun2005__t* _self = kk_function_as(struct kk_std_time_utc__mlift_pleap_10342_fun2005__t*, _fself, _ctx);
  kk_integer_t ntpsecs = _self->ntpsecs; /* int */
  kk_drop_match(_self, {kk_integer_dup(ntpsecs, _ctx);}, {}, _ctx)
  kk_integer_t adjust_688 = kk_integer_unbox(_b_x686, _ctx); /*int*/;
  kk_std_time_utc__leap_adjust _x_x2006 = kk_std_time_utc__mlift_pleap_10341(ntpsecs, adjust_688, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2006, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10342(kk_integer_t ntpsecs, kk_string_t wild___0, kk_context_t* _ctx) { /* (ntpsecs : int, wild_@0 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___0, _ctx);
  kk_integer_t x_10465 = kk_std_text_parse_pint(_ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10465, _ctx);
    kk_box_t _x_x2004 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pleap_10342_fun2005(ntpsecs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2004, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pleap_10341(ntpsecs, x_10465, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10343_fun2008__t {
  struct kk_function_s _base;
  kk_integer_t ntpsecs;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10343_fun2008(kk_function_t _fself, kk_box_t _b_x690, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10343_fun2008(kk_integer_t ntpsecs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10343_fun2008__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_pleap_10343_fun2008__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_pleap_10343_fun2008, kk_context());
  _self->ntpsecs = ntpsecs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10343_fun2008(kk_function_t _fself, kk_box_t _b_x690, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10343_fun2008__t* _self = kk_function_as(struct kk_std_time_utc__mlift_pleap_10343_fun2008__t*, _fself, _ctx);
  kk_integer_t ntpsecs = _self->ntpsecs; /* int */
  kk_drop_match(_self, {kk_integer_dup(ntpsecs, _ctx);}, {}, _ctx)
  kk_string_t wild___0_692 = kk_string_unbox(_b_x690); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2009 = kk_std_time_utc__mlift_pleap_10342(ntpsecs, wild___0_692, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2009, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10343(kk_integer_t ntpsecs, kk_context_t* _ctx) { /* (ntpsecs : int) -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_10467 = kk_std_text_parse_whitespace(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10467, _ctx);
    kk_box_t _x_x2007 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pleap_10343_fun2008(ntpsecs, _ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2007, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pleap_10342(ntpsecs, x_10467, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10344_fun2011__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10344_fun2011(kk_function_t _fself, kk_box_t _b_x694, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10344_fun2011(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10344_fun2011, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10344_fun2011(kk_function_t _fself, kk_box_t _b_x694, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2012;
  kk_integer_t _x_x2013 = kk_integer_unbox(_b_x694, _ctx); /*int*/
  _x_x2012 = kk_std_time_utc__mlift_pleap_10343(_x_x2013, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2012, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10344(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild__, _ctx);
  kk_integer_t x_10469 = kk_std_text_parse_pint(_ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10469, _ctx);
    kk_box_t _x_x2010 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pleap_10344_fun2011(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2010, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pleap_10343(x_10469, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2015__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2015(kk_function_t _fself, kk_box_t _b_x697, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2015(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2015, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2015(kk_function_t _fself, kk_box_t _b_x697, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2016;
  kk_string_t _x_x2017 = kk_string_unbox(_b_x697); /*string*/
  _x_x2016 = kk_std_time_utc__mlift_pleap_10344(_x_x2017, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2016, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2019__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2019(kk_function_t _fself, kk_box_t _b_x699, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2019(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2019, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2019(kk_function_t _fself, kk_box_t _b_x699, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2020;
  kk_integer_t _x_x2021 = kk_integer_unbox(_b_x699, _ctx); /*int*/
  _x_x2020 = kk_std_time_utc__mlift_pleap_10343(_x_x2021, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2020, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2023__t {
  struct kk_function_s _base;
  kk_integer_t x_0_10474;
};
static kk_box_t kk_std_time_utc_pleap_fun2023(kk_function_t _fself, kk_box_t _b_x701, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2023(kk_integer_t x_0_10474, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2023__t* _self = kk_function_alloc_as(struct kk_std_time_utc_pleap_fun2023__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_pleap_fun2023, kk_context());
  _self->x_0_10474 = x_0_10474;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2023(kk_function_t _fself, kk_box_t _b_x701, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2023__t* _self = kk_function_as(struct kk_std_time_utc_pleap_fun2023__t*, _fself, _ctx);
  kk_integer_t x_0_10474 = _self->x_0_10474; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_0_10474, _ctx);}, {}, _ctx)
  kk_string_t wild___0_765 = kk_string_unbox(_b_x701); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2024 = kk_std_time_utc__mlift_pleap_10342(x_0_10474, wild___0_765, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2024, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2026__t {
  struct kk_function_s _base;
  kk_integer_t x_0_10474;
};
static kk_box_t kk_std_time_utc_pleap_fun2026(kk_function_t _fself, kk_box_t _b_x703, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2026(kk_integer_t x_0_10474, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2026__t* _self = kk_function_alloc_as(struct kk_std_time_utc_pleap_fun2026__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_pleap_fun2026, kk_context());
  _self->x_0_10474 = x_0_10474;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2026(kk_function_t _fself, kk_box_t _b_x703, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2026__t* _self = kk_function_as(struct kk_std_time_utc_pleap_fun2026__t*, _fself, _ctx);
  kk_integer_t x_0_10474 = _self->x_0_10474; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_0_10474, _ctx);}, {}, _ctx)
  kk_integer_t adjust_766 = kk_integer_unbox(_b_x703, _ctx); /*int*/;
  kk_std_time_utc__leap_adjust _x_x2027 = kk_std_time_utc__mlift_pleap_10341(x_0_10474, adjust_766, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2027, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2029__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2029(kk_function_t _fself, kk_box_t _b_x707, kk_box_t _b_x708, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2029(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2029, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2029(kk_function_t _fself, kk_box_t _b_x707, kk_box_t _b_x708, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2030;
  kk_integer_t _x_x2031 = kk_integer_unbox(_b_x707, _ctx); /*int*/
  kk_std_core_types__optional _x_x2032 = kk_std_core_types__optional_unbox(_b_x708, KK_OWNED, _ctx); /*? float64*/
  _x_x2030 = kk_std_time_timestamp_int_fs_timespan(_x_x2031, _x_x2032, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_num_ddouble__ddouble_box(_x_x2030, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2034__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2034(kk_function_t _fself, kk_box_t _b_x715, kk_box_t _b_x716, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2034(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2034, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2034(kk_function_t _fself, kk_box_t _b_x715, kk_box_t _b_x716, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2035;
  kk_std_num_ddouble__ddouble _x_x2036 = kk_std_num_ddouble__ddouble_unbox(_b_x715, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2037;
  double _x_x2038;
  double _x_x2039;
  kk_std_num_ddouble__ddouble _match_x959;
  kk_box_t _x_x2040 = kk_box_dup(_b_x716, _ctx); /*9984*/
  _match_x959 = kk_std_num_ddouble__ddouble_unbox(_x_x2040, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  {
    double _x = _match_x959.hi;
    _x_x2039 = _x; /*float64*/
  }
  _x_x2038 = (-_x_x2039); /*float64*/
  double _x_x2041;
  double _x_x2042;
  kk_std_num_ddouble__ddouble _match_x958 = kk_std_num_ddouble__ddouble_unbox(_b_x716, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  {
    double _x_0 = _match_x958.lo;
    _x_x2042 = _x_0; /*float64*/
  }
  _x_x2041 = (-_x_x2042); /*float64*/
  _x_x2037 = kk_std_num_ddouble__new_Ddouble(_x_x2038, _x_x2041, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2035 = kk_std_num_ddouble__lp__plus__rp_(_x_x2036, _x_x2037, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2035, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2044__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2044(kk_function_t _fself, kk_box_t _b_x726, kk_box_t _b_x727, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2044(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2044, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2044(kk_function_t _fself, kk_box_t _b_x726, kk_box_t _b_x727, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x2045;
  kk_std_num_ddouble__ddouble _x_x2046 = kk_std_num_ddouble__ddouble_unbox(_b_x726, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x2047;
  kk_integer_t _x_x2048;
  kk_std_core_types__optional _match_x957 = kk_std_core_types__optional_unbox(_b_x727, KK_OWNED, _ctx); /*? int*/;
  if (kk_std_core_types__is_Optional(_match_x957, _ctx)) {
    kk_box_t _box_x722 = _match_x957._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x722, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x957, _ctx);
    _x_x2048 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x957, _ctx);
    _x_x2048 = kk_integer_from_small(0); /*int*/
  }
  _x_x2047 = kk_integer_clamp32(_x_x2048,kk_context()); /*int32*/
  _x_x2045 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x2046, _x_x2047, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x2045, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2050__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2050(kk_function_t _fself, kk_box_t _b_x736, kk_box_t _b_x737, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2050(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2050, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2050(kk_function_t _fself, kk_box_t _b_x736, kk_box_t _b_x737, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2051;
  kk_integer_t _x_x2052 = kk_integer_unbox(_b_x736, _ctx); /*int*/
  kk_std_core_types__optional _x_x2053 = kk_std_core_types__optional_unbox(_b_x737, KK_OWNED, _ctx); /*? float64*/
  _x_x2051 = kk_std_time_timestamp_int_fs_timespan(_x_x2052, _x_x2053, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_num_ddouble__ddouble_box(_x_x2051, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2055__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2055(kk_function_t _fself, kk_box_t _b_x750, kk_box_t _b_x751, kk_box_t _b_x752, kk_box_t _b_x753, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2055(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2055, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2055(kk_function_t _fself, kk_box_t _b_x750, kk_box_t _b_x751, kk_box_t _b_x752, kk_box_t _b_x753, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp utc_start_767 = kk_std_time_timestamp__timestamp_unbox(_b_x750, KK_OWNED, _ctx); /*std/time/utc/utc-timestamp*/;
  kk_std_num_ddouble__ddouble offset_768 = kk_std_num_ddouble__ddouble_unbox(_b_x751, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_core_types__optional drift_start_769 = kk_std_core_types__optional_unbox(_b_x752, KK_OWNED, _ctx); /*? std/time/utc/utc-timestamp*/;
  kk_std_core_types__optional drift_770 = kk_std_core_types__optional_unbox(_b_x753, KK_OWNED, _ctx); /*? std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x2056;
  kk_std_time_timestamp__timestamp _x_x2057;
  if (kk_std_core_types__is_Optional(drift_start_769, _ctx)) {
    kk_box_t _box_x741 = drift_start_769._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_396 = kk_std_time_timestamp__timestamp_unbox(_box_x741, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_396, _ctx);
    kk_std_core_types__optional_drop(drift_start_769, _ctx);
    _x_x2057 = _uniq_drift_start_396; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start_769, _ctx);
    _x_x2057 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/utc/utc-timestamp*/
  }
  kk_std_num_ddouble__ddouble _x_x2058;
  if (kk_std_core_types__is_Optional(drift_770, _ctx)) {
    kk_box_t _box_x742 = drift_770._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_400 = kk_std_num_ddouble__ddouble_unbox(_box_x742, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift_770, _ctx);
    _x_x2058 = _uniq_drift_400; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift_770, _ctx);
    _x_x2058 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  _x_x2056 = kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, utc_start_767, offset_768, _x_x2057, _x_x2058, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2056, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc_pleap(kk_context_t* _ctx) { /* () -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_10471 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_string_drop(x_10471, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2014 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2015(_ctx), _ctx); /*2419*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2014, KK_OWNED, _ctx);
  }
  {
    kk_integer_t x_0_10474 = kk_std_text_parse_pint(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10474, _ctx);
      kk_box_t _x_x2018 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2019(_ctx), _ctx); /*2419*/
      return kk_std_time_utc__leap_adjust_unbox(_x_x2018, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_10477 = kk_std_text_parse_whitespace(_ctx); /*string*/;
      kk_string_drop(x_1_10477, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2022 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2023(x_0_10474, _ctx), _ctx); /*2419*/
        return kk_std_time_utc__leap_adjust_unbox(_x_x2022, KK_OWNED, _ctx);
      }
      {
        kk_integer_t x_2_10480 = kk_std_text_parse_pint(_ctx); /*int*/;
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_2_10480, _ctx);
          kk_box_t _x_x2025 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2026(x_0_10474, _ctx), _ctx); /*2419*/
          return kk_std_time_utc__leap_adjust_unbox(_x_x2025, KK_OWNED, _ctx);
        }
        {
          kk_std_num_ddouble__ddouble _x_x1_1_10310;
          kk_box_t _x_x2028 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_pleap_fun2029(_ctx), kk_integer_box(x_0_10474, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
          _x_x1_1_10310 = kk_std_num_ddouble__ddouble_unbox(_x_x2028, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1_0_10308;
          kk_box_t _x_x2033 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_pleap_fun2034(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_1_10310, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_utc_ntp2000, _ctx), _ctx); /*9985*/
          _x_x1_0_10308 = kk_std_num_ddouble__ddouble_unbox(_x_x2033, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
          kk_std_time_timestamp__timestamp _x_x1_10304;
          kk_box_t _x_x2043 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_pleap_fun2044(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_0_10308, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
          _x_x1_10304 = kk_std_time_timestamp__timestamp_unbox(_x_x2043, KK_OWNED, _ctx); /*std/time/utc/utc-timestamp*/
          kk_std_num_ddouble__ddouble _x_x2_10305;
          kk_box_t _x_x2049 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_pleap_fun2050(_ctx), kk_integer_box(x_2_10480, _ctx), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
          _x_x2_10305 = kk_std_num_ddouble__ddouble_unbox(_x_x2049, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
          kk_box_t _x_x2054;
          kk_box_t _x_x2059;
          kk_std_core_types__optional _x_x2060;
          kk_box_t _x_x2061;
          kk_std_time_timestamp__timestamp _x_x2062 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
          _x_x2061 = kk_std_time_timestamp__timestamp_box(_x_x2062, _ctx); /*7*/
          _x_x2060 = kk_std_core_types__new_Optional(_x_x2061, _ctx); /*? 7*/
          _x_x2059 = kk_std_core_types__optional_box(_x_x2060, _ctx); /*10184*/
          kk_box_t _x_x2063;
          kk_std_core_types__optional _x_x2064 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble_zero, _ctx), _ctx); /*? 7*/
          _x_x2063 = kk_std_core_types__optional_box(_x_x2064, _ctx); /*10185*/
          _x_x2054 = kk_std_core_hnd__open_none4(kk_std_time_utc_new_pleap_fun2055(_ctx), kk_std_time_timestamp__timestamp_box(_x_x1_10304, _ctx), kk_std_num_ddouble__ddouble_box(_x_x2_10305, _ctx), _x_x2059, _x_x2063, _ctx); /*10186*/
          return kk_std_time_utc__leap_adjust_unbox(_x_x2054, KK_OWNED, _ctx);
        }
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_utc_parse_leap_fun2073__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_leap_fun2073(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_leap_fun2073(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_leap_fun2073, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_parse_leap_fun2073(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2074 = kk_std_time_utc_pleap(_ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2074, _ctx);
}

kk_std_core_types__maybe kk_std_time_utc_parse_leap(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> maybe<leap-adjust> */ 
  kk_std_core_types__maybe maybe_10128;
  kk_string_t _x_x2065;
  kk_string_t _x_x2066 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x2067;
  kk_define_string_literal(, _s_x2068, 1, " ", _ctx)
  _x_x2067 = kk_string_dup(_s_x2068, _ctx); /*string*/
  _x_x2065 = kk_std_core_sslice_trim_left(_x_x2066, _x_x2067, _ctx); /*string*/
  kk_string_t _x_x2069;
  kk_define_string_literal(, _s_x2070, 1, "#", _ctx)
  _x_x2069 = kk_string_dup(_s_x2070, _ctx); /*string*/
  maybe_10128 = kk_std_core_sslice_starts_with(_x_x2065, _x_x2069, _ctx); /*maybe<sslice/sslice>*/
  if (kk_std_core_types__is_Just(maybe_10128, _ctx)) {
    kk_box_t _box_x771 = maybe_10128._cons.Just.value;
    kk_std_core_types__maybe_drop(maybe_10128, _ctx);
    kk_string_drop(line, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x772_774;
    kk_string_t _x_x2071 = kk_string_dup(line, _ctx); /*string*/
    kk_integer_t _x_x2072 = kk_string_len_int(line,kk_context()); /*int*/
    _b_x772_774 = kk_std_core_sslice__new_Sslice(_x_x2071, kk_integer_from_small(0), _x_x2072, _ctx); /*sslice/sslice*/
    kk_std_text_parse__parse_error perr_10129 = kk_std_text_parse_parse(_b_x772_774, kk_std_time_utc_new_parse_leap_fun2073(_ctx), _ctx); /*std/text/parse/parse-error<std/time/utc/leap-adjust>*/;
    if (kk_std_text_parse__is_ParseOk(perr_10129, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2075 = kk_std_text_parse__as_ParseOk(perr_10129, _ctx);
      kk_box_t _box_x776 = _con_x2075->result;
      kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2075->rest;
      kk_std_time_utc__leap_adjust x_0 = kk_std_time_utc__leap_adjust_unbox(_box_x776, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10129, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(perr_10129, _ctx);
      }
      else {
        kk_std_time_utc__leap_adjust_dup(x_0, _ctx);
        kk_datatype_ptr_decref(perr_10129, _ctx);
      }
      return kk_std_core_types__new_Just(kk_std_time_utc__leap_adjust_box(x_0, _ctx), _ctx);
    }
    {
      struct kk_std_text_parse_ParseError* _con_x2076 = kk_std_text_parse__as_ParseError(perr_10129, _ctx);
      kk_std_core_sslice__sslice _pat_5 = _con_x2076->rest;
      kk_string_t msg = _con_x2076->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10129, _ctx)) {
        kk_string_drop(msg, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(perr_10129, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10129, _ctx);
      }
      return kk_std_core_types__new_Nothing(_ctx);
    }
  }
}


// lift anonymous function
struct kk_std_time_utc_parse_leap_seconds_fun2080__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_utc_parse_leap_seconds_fun2080(kk_function_t _fself, kk_box_t _b_x781, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_leap_seconds_fun2080(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_leap_seconds_fun2080, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_utc_parse_leap_seconds_fun2080(kk_function_t _fself, kk_box_t _b_x781, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2081 = kk_string_unbox(_b_x781); /*string*/
  return kk_std_time_utc_parse_leap(_x_x2081, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_parse_leap_seconds(kk_string_t leaps, kk_context_t* _ctx) { /* (leaps : string) -> leaps-table */ 
  kk_vector_t v_10011;
  kk_string_t _x_x2077 = kk_string_dup(leaps, _ctx); /*string*/
  kk_string_t _x_x2078;
  kk_define_string_literal(, _s_x2079, 1, "\n", _ctx)
  _x_x2078 = kk_string_dup(_s_x2079, _ctx); /*string*/
  v_10011 = kk_string_splitv(_x_x2077,_x_x2078,kk_context()); /*vector<string>*/
  kk_std_core_types__list _b_x779_782 = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  kk_std_core_types__list xs_10131 = kk_std_core_list_flatmap_maybe(_b_x779_782, kk_std_time_utc_new_parse_leap_seconds_fun2080(_ctx), _ctx); /*list<std/time/utc/leap-adjust>*/;
  kk_std_core_types__list adjusts = kk_std_core_list_reverse_acc(kk_std_core_types__new_Nil(_ctx), xs_10131, _ctx); /*list<std/time/utc/leap-adjust>*/;
  kk_std_time_instant__instant expire;
  kk_std_core_types__list _x_x2082 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
  expire = kk_std_time_utc_parse_leap_expire(leaps, _x_x2082, _ctx); /*std/time/instant/instant*/
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx);
}
 
// Default TI leaps table has leap second information up to the compiler release (currently `leaps-table-y2017`).


// lift anonymous function
struct kk_std_time_utc_leaps_table_ti_fun2087__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_utc_leaps_table_ti_fun2087(kk_function_t _fself, kk_box_t _b_x786, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_leaps_table_ti_fun2087(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_leaps_table_ti_fun2087, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_utc_leaps_table_ti_fun2087(kk_function_t _fself, kk_box_t _b_x786, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2088 = kk_string_unbox(_b_x786); /*string*/
  return kk_std_time_utc_parse_leap(_x_x2088, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_ti;
 
// /* The [TI] (_International Time_) time scale with a 2000-01-01Z UTC epoch.
// This is the default time scale used in this library. It was a
// [proposed][TIpropose] time scale at the 2004 ITU-R meeting as a replacement of UTC
// without future leap seconds. In this library, we define TI to match
// exactly UTC up to the compiler release date (currently 2017) but ignore any
// possible future leap seconds after that date. This is the preferred time scale
// in this library as it guarantees deterministic time calculations for any
// future date, i.e. before 2017-01-01Z, TI == UTC, while after that, TI == TAI - 37s.
// */

kk_std_time_instant__timescale kk_std_time_utc_ts_ti;


// lift anonymous function
struct kk_std_time_utc__default_utc_fun2097__t {
  struct kk_function_s _base;
};
static kk_std_time_instant__timescale kk_std_time_utc__default_utc_fun2097(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_default_utc_fun2097(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__default_utc_fun2097, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_time_instant__timescale kk_std_time_utc__default_utc_fun2097(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__default_utc_fun2100__t {
  struct kk_function_s _base;
  kk_function_t _b_x789_790;
};
static kk_box_t kk_std_time_utc__default_utc_fun2100(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_default_utc_fun2100(kk_function_t _b_x789_790, kk_context_t* _ctx) {
  struct kk_std_time_utc__default_utc_fun2100__t* _self = kk_function_alloc_as(struct kk_std_time_utc__default_utc_fun2100__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__default_utc_fun2100, kk_context());
  _self->_b_x789_790 = _b_x789_790;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__default_utc_fun2100(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_utc__default_utc_fun2100__t* _self = kk_function_as(struct kk_std_time_utc__default_utc_fun2100__t*, _fself, _ctx);
  kk_function_t _b_x789_790 = _self->_b_x789_790; /* () -> 2512 std/time/instant/timescale */
  kk_drop_match(_self, {kk_function_dup(_b_x789_790, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _x_x2101 = kk_function_call(kk_std_time_instant__timescale, (kk_function_t, kk_context_t*), _b_x789_790, (_b_x789_790, _ctx), _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__timescale_box(_x_x2101, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__default_utc_fun2102__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__default_utc_fun2102(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_default_utc_fun2102(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__default_utc_fun2102, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__default_utc_fun2102(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_std_time_utc__default_utc(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <utc|e> a) -> e a */ 
  kk_function_t _b_x789_790 = kk_std_time_utc__new_default_utc_fun2097(_ctx); /*() -> 2512 std/time/instant/timescale*/;
  kk_std_time_utc__utc _x_x2098;
  kk_std_core_hnd__clause0 _x_x2099 = kk_std_core_hnd_clause_tail0(kk_std_time_utc__new_default_utc_fun2100(_b_x789_790, _ctx), _ctx); /*hnd/clause0<6948,6947,6945,6946>*/
  _x_x2098 = kk_std_time_utc__new_Hnd_utc(kk_reuse_null, 0, kk_integer_from_small(1), _x_x2099, _ctx); /*std/time/utc/utc<12,13>*/
  return kk_std_time_utc_utc_fs__handle(_x_x2098, kk_std_time_utc__new_default_utc_fun2102(_ctx), action, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table0;

kk_string_t kk_std_time_utc_leap_adjust_fs_show(kk_std_time_utc__leap_adjust l, kk_context_t* _ctx) { /* (l : leap-adjust) -> string */ 
  kk_string_t _b_x803_805;
  kk_std_time_timestamp__timestamp _x_x2104;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2105 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _x = _con_x2105->utc_start;
    kk_std_num_ddouble__ddouble _pat_2 = _con_x2105->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x2105->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x2105->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2106 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2107 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x2104 = _x; /*std/time/utc/utc-timestamp*/
  }
  _b_x803_805 = kk_std_time_instant_timestamp_fs_show(_x_x2104, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _b_x799_809;
  kk_std_num_ddouble__ddouble _x_x2108;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2109 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_0 = _con_x2109->utc_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x2109->offset;
    kk_std_time_timestamp__timestamp _pat_5_0 = _con_x2109->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0 = _con_x2109->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2110 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2111 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
    _x_x2108 = _x_0; /*std/time/timestamp/timespan*/
  }
  _b_x799_809 = kk_std_num_ddouble_show(_x_x2108, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _b_x795_813;
  kk_std_time_timestamp__timestamp _x_x2112;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2113 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_1 = _con_x2113->utc_start;
    kk_std_num_ddouble__ddouble _pat_3_1 = _con_x2113->offset;
    kk_std_time_timestamp__timestamp _x_1 = _con_x2113->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_1 = _con_x2113->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2114 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2115 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    _x_x2112 = _x_1; /*std/time/utc/utc-timestamp*/
  }
  _b_x795_813 = kk_std_time_instant_timestamp_fs_show(_x_x2112, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _b_x791_817;
  kk_std_num_ddouble__ddouble _x_x2116;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2117 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_2 = _con_x2117->utc_start;
    kk_std_num_ddouble__ddouble _pat_3_2 = _con_x2117->offset;
    kk_std_time_timestamp__timestamp _pat_6_2 = _con_x2117->drift_start;
    kk_std_num_ddouble__ddouble _x_2 = _con_x2117->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2118 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2119 = kk_std_time_timestamp__as_Timestamp(_pat_6_2, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(l, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_6_2, _ctx)) {
        kk_datatype_ptr_free(_pat_6_2, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_6_2, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_0_2, _ctx)) {
        kk_datatype_ptr_free(_pat_0_2, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_0_2, _ctx);
      }
      kk_datatype_ptr_free(l, _ctx);
    }
    else {
      kk_datatype_ptr_decref(l, _ctx);
    }
    _x_x2116 = _x_2; /*std/num/ddouble/ddouble*/
  }
  _b_x791_817 = kk_std_num_ddouble_show(_x_x2116, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_std_core_types__list _x_x2120;
  kk_std_core_types__list _x_x2121;
  kk_box_t _x_x2122;
  kk_string_t _x_x2123;
  kk_define_string_literal(, _s_x2124, 10, ": offset: ", _ctx)
  _x_x2123 = kk_string_dup(_s_x2124, _ctx); /*string*/
  _x_x2122 = kk_string_box(_x_x2123); /*79*/
  kk_std_core_types__list _x_x2125;
  kk_std_core_types__list _x_x2126;
  kk_box_t _x_x2127;
  kk_string_t _x_x2128;
  kk_define_string_literal(, _s_x2129, 15, ", drift-start: ", _ctx)
  _x_x2128 = kk_string_dup(_s_x2129, _ctx); /*string*/
  _x_x2127 = kk_string_box(_x_x2128); /*79*/
  kk_std_core_types__list _x_x2130;
  kk_std_core_types__list _x_x2131;
  kk_box_t _x_x2132;
  kk_string_t _x_x2133;
  kk_define_string_literal(, _s_x2134, 9, ", drift: ", _ctx)
  _x_x2133 = kk_string_dup(_s_x2134, _ctx); /*string*/
  _x_x2132 = kk_string_box(_x_x2133); /*79*/
  kk_std_core_types__list _x_x2135 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x791_817), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x2131 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2132, _x_x2135, _ctx); /*list<79>*/
  _x_x2130 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x795_813), _x_x2131, _ctx); /*list<79>*/
  _x_x2126 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2127, _x_x2130, _ctx); /*list<79>*/
  _x_x2125 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x799_809), _x_x2126, _ctx); /*list<79>*/
  _x_x2121 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2122, _x_x2125, _ctx); /*list<79>*/
  _x_x2120 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x803_805), _x_x2121, _ctx); /*list<79>*/
  return kk_std_core_list_concat_fs_join(_x_x2120, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_leaps_table_fs_show_fun2137__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_leaps_table_fs_show_fun2137(kk_function_t _fself, kk_box_t _b_x821, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_leaps_table_fs_new_show_fun2137(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_leaps_table_fs_show_fun2137, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_leaps_table_fs_show_fun2137(kk_function_t _fself, kk_box_t _b_x821, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2138;
  kk_std_time_utc__leap_adjust _x_x2139 = kk_std_time_utc__leap_adjust_unbox(_b_x821, KK_OWNED, _ctx); /*std/time/utc/leap-adjust*/
  _x_x2138 = kk_std_time_utc_leap_adjust_fs_show(_x_x2139, _ctx); /*string*/
  return kk_string_box(_x_x2138);
}

kk_string_t kk_std_time_utc_leaps_table_fs_show(kk_std_time_utc__leaps_table t, kk_context_t* _ctx) { /* (t : leaps-table) -> string */ 
  kk_std_core_types__list _x_x2136;
  kk_function_t _brw_x951 = kk_std_time_utc_leaps_table_fs_new_show_fun2137(_ctx); /*(2217) -> 2219 2218*/;
  kk_std_core_types__list _brw_x952;
  kk_std_core_types__list _x_x2140;
  {
    struct kk_std_time_utc_Leaps_table* _con_x2141 = kk_std_time_utc__as_Leaps_table(t, _ctx);
    kk_std_time_instant__instant _pat_0 = _con_x2141->expire;
    kk_std_core_types__list _x = _con_x2141->adjusts;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_std_time_instant__instant_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x2140 = _x; /*list<std/time/utc/leap-adjust>*/
  }
  _brw_x952 = kk_std_core_list_map(_x_x2140, _brw_x951, _ctx); /*list<2218>*/
  kk_function_drop(_brw_x951, _ctx);
  _x_x2136 = _brw_x952; /*list<2218>*/
  return kk_std_core_list_unlines(_x_x2136, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_utc_unix2000;
 
// Create an instant from raw unix seconds since the unix epoch (1970-01-01T00:00:10 TAI)
// and optional leap seconds to designate instants inside a leap seconds.

kk_std_time_instant__instant kk_std_time_utc_timespan_fs_unix_instant(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (t : std/time/timestamp/timespan, leap : ? int, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_std_num_ddouble__ddouble t_1_10142;
  kk_std_num_ddouble__ddouble _x_x2142;
  double _x_x2143;
  double _x_x2144;
  kk_std_num_ddouble__ddouble _x_x2145 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_4 = _x_x2145.hi;
    _x_x2144 = _x_4; /*float64*/
  }
  _x_x2143 = (-_x_x2144); /*float64*/
  double _x_x2146;
  double _x_x2147;
  kk_std_num_ddouble__ddouble _x_x2148 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_0_0 = _x_x2148.lo;
    _x_x2147 = _x_0_0; /*float64*/
  }
  _x_x2146 = (-_x_x2147); /*float64*/
  _x_x2142 = kk_std_num_ddouble__new_Ddouble(_x_x2143, _x_x2146, _ctx); /*std/num/ddouble/ddouble*/
  t_1_10142 = kk_std_num_ddouble__lp__plus__rp_(t, _x_x2142, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp t_0_10141;
  int32_t _x_x2149;
  kk_integer_t _x_x2150;
  if (kk_std_core_types__is_Optional(leap, _ctx)) {
    kk_box_t _box_x824 = leap._cons._Optional.value;
    kk_integer_t _uniq_leap_3018 = kk_integer_unbox(_box_x824, _ctx);
    kk_integer_dup(_uniq_leap_3018, _ctx);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2150 = _uniq_leap_3018; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2150 = kk_integer_from_small(0); /*int*/
  }
  _x_x2149 = kk_integer_clamp32(_x_x2150,kk_context()); /*int32*/
  t_0_10141 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_1_10142, _x_x2149, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__instant i_10138;
  kk_std_time_instant__timescale _x_x2151 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  i_10138 = kk_std_time_instant__new_Instant(t_0_10141, _x_x2151, _ctx); /*std/time/instant/instant*/
  bool _match_x949;
  kk_string_t _x_x2152;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i_10138.since;
    kk_std_time_instant__timescale _x_0 = i_10138.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2153 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2154 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x2155 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x2155->name;
      kk_string_t _pat_0 = _con_x2155->unit;
      kk_function_t _pat_1 = _con_x2155->from_tai;
      kk_function_t _pat_2 = _con_x2155->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x2155->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x2155->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x2155->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_3, _ctx);
        kk_function_drop(_pat_2, _ctx);
        kk_function_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x2152 = _x; /*string*/
    }
  }
  kk_string_t _x_x2156;
  kk_std_time_instant__timescale _match_x950;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x825 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3022 = kk_std_time_instant__timescale_unbox(_box_x825, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3022, _ctx);
    _match_x950 = _uniq_ts_3022; /*std/time/instant/timescale*/
  }
  else {
    _match_x950 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    struct kk_std_time_instant_Timescale* _con_x2157 = kk_std_time_instant__as_Timescale(_match_x950, _ctx);
    kk_string_t _x_1 = _con_x2157->name;
    kk_string_t _pat_0_1 = _con_x2157->unit;
    kk_function_t _pat_1_1 = _con_x2157->from_tai;
    kk_function_t _pat_2_1 = _con_x2157->to_tai;
    kk_std_core_types__maybe _pat_3_1 = _con_x2157->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_1 = _con_x2157->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_1 = _con_x2157->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x950, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
      kk_function_drop(_pat_2_1, _ctx);
      kk_function_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x950, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x950, _ctx);
    }
    _x_x2156 = _x_1; /*string*/
  }
  _match_x949 = kk_string_is_eq(_x_x2152,_x_x2156,kk_context()); /*bool*/
  if (_match_x949) {
    kk_std_core_types__optional_drop(ts, _ctx);
    return i_10138;
  }
  {
    kk_std_time_timestamp__timestamp _x_x2158;
    kk_std_time_timestamp__timestamp _x_x2159;
    {
      kk_std_time_timestamp__timestamp _x_2 = i_10138.since;
      kk_std_time_instant__timescale _pat_2_2 = i_10138.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x2160 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x2161 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x2159 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x2162;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i_10138.since;
      kk_std_time_instant__timescale _x_3 = i_10138.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x2163 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x2164 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i_10138, _ctx);
      _x_x2162 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x2165;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x826 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3022_0 = kk_std_time_instant__timescale_unbox(_box_x826, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3022_0, _ctx);
      _x_x2165 = _uniq_ts_3022_0; /*std/time/instant/timescale*/
    }
    else {
      _x_x2165 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    _x_x2158 = kk_std_time_instant_convert(_x_x2159, _x_x2162, _x_x2165, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x2166;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x827 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3022_1 = kk_std_time_instant__timescale_unbox(_box_x827, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3022_1, _ctx);
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2166 = _uniq_ts_3022_1; /*std/time/instant/timescale*/
    }
    else {
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2166 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x2158, _x_x2166, _ctx);
  }
}
 
// /* Given a Unix time stamp in (fractional) seconds (`secs`) and an optional separate
// fraction of seconds `frac` (for increased precision for nanosecond timestamps), return an `:instant`.
// that is `secs + frac` seconds after the Unix epoch (``1970-01-01Z``).
// 
// Unfortunately, Unix time stamps are [ambiguous](https://en.wikipedia.org/wiki/Unix_time).
// The seconds `secs` are interpreted as: `val days = secs / 86400` and `val dsecs = secs % 86400`,
// where `days` is the number of days since ``1970-01-01Z`` and `dsecs` is the SI seconds into
// the day. This means that one cannot represent a possible extra leap second since it
// will look as the first second of the next day. For example, here is how the time stamps look
// around the leap second of ``1973-01-01Z``:
// ````
// > instant(1972,12,31,23,59,59).unix-timestamp
// 94694399
// 
// > instant(1972,12,31,23,59,60).unix-timestamp
// 94694400
// 
// > instant(1973,1,1).unix-timestamp
// 94694400
// ````
// 
// Internally, this library uses proper `:timestamp`s that _can_ keep track of leap seconds.
// To indicate a time in a leap second, you can use a fraction `frac` that is larger than `1.0`. For example:
// ````
// > unix-instant(94694399.0).time
// 1972-12-31T23:59:59Z
// 
// > unix-instant(94694399.0,1.0).time
// 1972-12-31T23:59:60Z
// 
// > unix-instant(94694400.0).time
// 1973-01-01T00:00:00Z
// ````
// 
// This works well for systems that support [``CLOCK_UTC``](https://www.madore.org/~david/computers/unix-leap-seconds.html).
// */

kk_std_time_instant__instant kk_std_time_utc_float64_fs_unix_instant(double u, kk_std_core_types__optional frac, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (u : float64, frac : ? float64, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 
  double frac_0_10147;
  double _x_x2167;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x828 = frac._cons._Optional.value;
    double _uniq_frac_3059 = kk_double_unbox(_box_x828, KK_BORROWED, _ctx);
    _x_x2167 = _uniq_frac_3059; /*float64*/
  }
  else {
    _x_x2167 = 0x0p+0; /*float64*/
  }
  frac_0_10147 = kk_std_num_float64_fraction(_x_x2167, _ctx); /*float64*/
  kk_std_num_ddouble__ddouble t;
  bool _match_x948 = (frac_0_10147 == (0x0p+0)); /*bool*/;
  if (_match_x948) {
    t = kk_std_num_ddouble__new_Ddouble(u, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  else {
    t = kk_std_num_ddouble_dsum(u, frac_0_10147, _ctx); /*std/time/timestamp/timespan*/
  }
  kk_integer_t leap;
  double _x_x2168;
  bool _match_x947;
  double _x_x2169;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x829 = frac._cons._Optional.value;
    double _uniq_frac_3059_0 = kk_double_unbox(_box_x829, KK_BORROWED, _ctx);
    _x_x2169 = _uniq_frac_3059_0; /*float64*/
  }
  else {
    _x_x2169 = 0x0p+0; /*float64*/
  }
  _match_x947 = (_x_x2169 >= (0x0p+0)); /*bool*/
  if (_match_x947) {
    double _x_x2170;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x830 = frac._cons._Optional.value;
      double _uniq_frac_3059_1 = kk_double_unbox(_box_x830, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2170 = _uniq_frac_3059_1; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2170 = 0x0p+0; /*float64*/
    }
    _x_x2168 = floor(_x_x2170); /*float64*/
  }
  else {
    double _x_x2171;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x831 = frac._cons._Optional.value;
      double _uniq_frac_3059_2 = kk_double_unbox(_box_x831, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2171 = _uniq_frac_3059_2; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2171 = 0x0p+0; /*float64*/
    }
    _x_x2168 = ceil(_x_x2171); /*float64*/
  }
  leap = kk_integer_from_double(_x_x2168,kk_context()); /*int*/
  kk_std_core_types__optional _x_x2172 = kk_std_core_types__new_Optional(kk_integer_box(leap, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2173;
  kk_box_t _x_x2174;
  kk_std_time_instant__timescale _x_x2175;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x833 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3063 = kk_std_time_instant__timescale_unbox(_box_x833, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3063, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    _x_x2175 = _uniq_ts_3063; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    _x_x2175 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  _x_x2174 = kk_std_time_instant__timescale_box(_x_x2175, _ctx); /*7*/
  _x_x2173 = kk_std_core_types__new_Optional(_x_x2174, _ctx); /*? 7*/
  return kk_std_time_utc_timespan_fs_unix_instant(t, _x_x2172, _x_x2173, _ctx);
}
 
// Create an instant from raw unix seconds since the unix epoch (1970-01-01T00:00:10 TAI)
// Use a fraction `> 1` to indicate a time inside a leap second.

kk_std_time_instant__instant kk_std_time_utc_int_fs_unix_instant(kk_integer_t u, kk_std_core_types__optional frac, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (u : int, frac : ? float64, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 
  double d_10151;
  double _x_x2176;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x837 = frac._cons._Optional.value;
    double _uniq_frac_3114 = kk_double_unbox(_box_x837, KK_BORROWED, _ctx);
    _x_x2176 = _uniq_frac_3114; /*float64*/
  }
  else {
    _x_x2176 = 0x0p+0; /*float64*/
  }
  d_10151 = kk_std_num_float64_fraction(_x_x2176, _ctx); /*float64*/
  kk_std_num_ddouble__ddouble secs_10149;
  kk_std_num_ddouble__ddouble _x_x2177 = kk_std_num_ddouble_ddouble_int_exp(u, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2178 = kk_std_num_ddouble__new_Ddouble(d_10151, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  secs_10149 = kk_std_num_ddouble__lp__plus__rp_(_x_x2177, _x_x2178, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t leap;
  double _x_x2179;
  bool _match_x946;
  double _x_x2180;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x838 = frac._cons._Optional.value;
    double _uniq_frac_3114_0 = kk_double_unbox(_box_x838, KK_BORROWED, _ctx);
    _x_x2180 = _uniq_frac_3114_0; /*float64*/
  }
  else {
    _x_x2180 = 0x0p+0; /*float64*/
  }
  _match_x946 = (_x_x2180 >= (0x0p+0)); /*bool*/
  if (_match_x946) {
    double _x_x2181;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x839 = frac._cons._Optional.value;
      double _uniq_frac_3114_1 = kk_double_unbox(_box_x839, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2181 = _uniq_frac_3114_1; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2181 = 0x0p+0; /*float64*/
    }
    _x_x2179 = floor(_x_x2181); /*float64*/
  }
  else {
    double _x_x2182;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x840 = frac._cons._Optional.value;
      double _uniq_frac_3114_2 = kk_double_unbox(_box_x840, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2182 = _uniq_frac_3114_2; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2182 = 0x0p+0; /*float64*/
    }
    _x_x2179 = ceil(_x_x2182); /*float64*/
  }
  leap = kk_integer_from_double(_x_x2179,kk_context()); /*int*/
  kk_std_core_types__optional _x_x2183 = kk_std_core_types__new_Optional(kk_integer_box(leap, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2184;
  kk_box_t _x_x2185;
  kk_std_time_instant__timescale _x_x2186;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x842 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3118 = kk_std_time_instant__timescale_unbox(_box_x842, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3118, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    _x_x2186 = _uniq_ts_3118; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    _x_x2186 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  _x_x2185 = kk_std_time_instant__timescale_box(_x_x2186, _ctx); /*7*/
  _x_x2184 = kk_std_core_types__new_Optional(_x_x2185, _ctx); /*? 7*/
  return kk_std_time_utc_timespan_fs_unix_instant(secs_10149, _x_x2183, _x_x2184, _ctx);
}
 
// Get a standard Unix timestamp in fractional seconds since the Unix epoch (1970-01-01Z).
// Since Unix time stamps are ambiguous,
// instants inside a leap seconds show as occurring in the second after that.

kk_std_num_ddouble__ddouble kk_std_time_utc_unix_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : std/time/instant/instant) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x_x2187;
  kk_std_time_timestamp__timestamp _x_x2188;
  kk_std_time_timestamp__timestamp _x_x2189;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2190 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2191 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x2189 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x2192;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2193 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2194 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x2192 = _x_0; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x2195 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  _x_x2188 = kk_std_time_instant_convert(_x_x2189, _x_x2192, _x_x2195, _ctx); /*std/time/timestamp/timestamp*/
  _x_x2187 = kk_std_time_timestamp_unsafe_timespan_withleap(_x_x2188, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_num_ddouble__lp__plus__rp_(kk_std_time_utc_unix2000, _x_x2187, _ctx);
}
 
// [NTP](https://en.wikipedia.org/wiki/Network_Time_Protocol) time scale.
// It equals the `ts-ti` time scale.

kk_std_time_instant__timescale kk_std_time_utc_ts_ntp;
 
// Convert an NTP time in seconds since the NTP epoch (1900-01-01Z) to an instant.
// Also takes an optional `leap` argument if the NTP time is inside a leap second.

kk_std_time_instant__instant kk_std_time_utc_ntp_instant(kk_std_num_ddouble__ddouble ntp, kk_std_core_types__optional leap, kk_context_t* _ctx) { /* (ntp : std/num/ddouble/ddouble, leap : ? int) -> std/time/instant/instant */ 
  kk_std_time_timestamp__timestamp t_10156;
  kk_std_time_timestamp__timestamp _x_x2196;
  int32_t _x_x2197;
  kk_integer_t _x_x2198;
  if (kk_std_core_types__is_Optional(leap, _ctx)) {
    kk_box_t _box_x846 = leap._cons._Optional.value;
    kk_integer_t _uniq_leap_3202 = kk_integer_unbox(_box_x846, _ctx);
    kk_integer_dup(_uniq_leap_3202, _ctx);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2198 = _uniq_leap_3202; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2198 = kk_integer_from_small(0); /*int*/
  }
  _x_x2197 = kk_integer_clamp32(_x_x2198,kk_context()); /*int32*/
  _x_x2196 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, ntp, _x_x2197, _ctx); /*std/time/timestamp/timestamp*/
  t_10156 = kk_std_time_timestamp__lp__dash__rp_(_x_x2196, kk_std_time_utc_ntp2000, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x2199 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10156, _x_x2199, _ctx);
}
 
// Return the NTP time of an instant since the NTP epoch (1900-01-01)
// Since NTP time stamps are ambiguous, times inside a leap second show
// as occurring in the second after the leap second.

kk_std_num_ddouble__ddouble kk_std_time_utc_ntp_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : std/time/instant/instant) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x_x2200;
  kk_std_time_timestamp__timestamp _x_x2201;
  kk_std_time_timestamp__timestamp _x_x2202;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2203 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2204 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x2202 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x2205;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2206 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2207 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x2205 = _x_0; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x2208 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  _x_x2201 = kk_std_time_instant_convert(_x_x2202, _x_x2205, _x_x2208, _ctx); /*std/time/timestamp/timestamp*/
  _x_x2200 = kk_std_time_timestamp_unsafe_timespan_withleap(_x_x2201, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_num_ddouble__lp__plus__rp_(kk_std_time_utc_ntp2000, _x_x2200, _ctx);
}
 
// [Unix](https://en.wikipedia.org/wiki/Unix_time) time scale based on Unix seconds.
// It equals the `ts-ti` time scale.

kk_std_time_instant__timescale kk_std_time_utc_ts_unix;
 
// /*----------------------------------------------------------------------------
//   UTC-SLS to TAI conversion
// ----------------------------------------------------------------------------*/

kk_std_core_types__maybe kk_std_time_utc_utc_sls_leap_in_day(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, utc : utc-timestamp) -> maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)> */ 
  kk_std_core_types__tuple2 tuple2_10043;
  kk_std_time_timestamp__timestamp _x_x2215 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
  tuple2_10043 = kk_std_time_timestamp_days_seconds(_x_x2215, _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_std_core_types__maybe _match_x943;
  kk_integer_t _x_x2216;
  {
    kk_box_t _box_x847 = tuple2_10043.fst;
    kk_box_t _box_x848 = tuple2_10043.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x847, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10043, _ctx);
    _x_x2216 = _x; /*int*/
  }
  _match_x943 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x2216, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x943, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x849 = _match_x943._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x849, KK_BORROWED, _ctx);
    kk_box_t _box_x850 = _pat_1_0.fst;
    kk_box_t _box_x851 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x850, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x851, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2217 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
    kk_std_time_timestamp__timestamp_dup(start, _ctx);
    kk_std_core_types__maybe_drop(_match_x943, _ctx);
    kk_std_time_timestamp__timestamp ts_0_10164;
    kk_std_time_timestamp__timestamp _x_x2218 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    ts_0_10164 = kk_std_time_timestamp__lp__dash__rp_(_x_x2218, smooth, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp smooth_start;
    kk_std_num_ddouble__ddouble _x_x2219;
    kk_std_num_ddouble__ddouble _x_x2220;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2221 = kk_std_time_timestamp__as_Timestamp(ts_0_10164, _ctx);
      kk_std_num_ddouble__ddouble _x_0 = _con_x2221->since;
      _x_x2220 = _x_0; /*std/time/timestamp/timespan*/
    }
    _x_x2219 = kk_std_num_ddouble__lp__plus__rp_(_x_x2220, diff, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x2222;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2223 = kk_std_time_timestamp__as_Timestamp(ts_0_10164, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x2223->since;
      int32_t _x_0_0 = _con_x2223->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts_0_10164, _ctx)) {
        kk_datatype_ptr_free(ts_0_10164, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts_0_10164, _ctx);
      }
      _x_x2222 = _x_0_0; /*int32*/
    }
    smooth_start = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x2219, _x_x2222, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp smooth_end;
    kk_std_time_timestamp__timestamp _x_x2224 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    smooth_end = kk_std_time_timestamp_add_leap_seconds(_x_x2224, diff, _ctx); /*std/time/timestamp/timestamp*/
    bool _match_x944;
    kk_std_core_types__order _x_x2225;
    kk_std_time_timestamp__timestamp _x_x2226 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
    kk_std_time_timestamp__timestamp _x_x2227 = kk_std_time_timestamp__timestamp_dup(smooth_start, _ctx); /*std/time/timestamp/timestamp*/
    _x_x2225 = kk_std_time_timestamp_cmp(_x_x2226, _x_x2227, _ctx); /*order*/
    _match_x944 = kk_std_core_order__lp__excl__eq__rp_(_x_x2225, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
    if (_match_x944) {
      kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
        kk_datatype_ptr_free(start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(start, _ctx);
      }
      kk_std_time_timestamp__timestamp_drop(smooth_start, _ctx);
      kk_std_time_timestamp__timestamp_drop(smooth_end, _ctx);
      return kk_std_core_types__new_Nothing(_ctx);
    }
    {
      bool _match_x945;
      kk_std_core_types__order _x_x2228;
      kk_std_time_timestamp__timestamp _x_x2229 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
      kk_std_time_timestamp__timestamp _x_x2230 = kk_std_time_timestamp__timestamp_dup(smooth_end, _ctx); /*std/time/timestamp/timestamp*/
      _x_x2228 = kk_std_time_timestamp_cmp(_x_x2229, _x_x2230, _ctx); /*order*/
      _match_x945 = kk_std_core_order__lp__eq__eq__rp_(_x_x2228, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
      if (_match_x945) {
        kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
          kk_datatype_ptr_free(start, _ctx);
        }
        else {
          kk_datatype_ptr_decref(start, _ctx);
        }
        kk_std_time_timestamp__timestamp_drop(smooth_start, _ctx);
        kk_std_time_timestamp__timestamp_drop(smooth_end, _ctx);
        return kk_std_core_types__new_Nothing(_ctx);
      }
      {
        kk_std_num_ddouble__ddouble smooth_total;
        kk_std_num_ddouble__ddouble _x_x2231;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2232 = kk_std_time_timestamp__as_Timestamp(smooth_end, _ctx);
          kk_std_num_ddouble__ddouble _x_2 = _con_x2232->since;
          if kk_likely(kk_datatype_ptr_is_unique(smooth_end, _ctx)) {
            kk_datatype_ptr_free(smooth_end, _ctx);
          }
          else {
            kk_datatype_ptr_decref(smooth_end, _ctx);
          }
          _x_x2231 = _x_2; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x2233;
        double _x_x2234;
        double _x_x2235;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2236 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_3 = _con_x2236->since;
          {
            double _x_1 = _x_3.hi;
            _x_x2235 = _x_1; /*float64*/
          }
        }
        _x_x2234 = (-_x_x2235); /*float64*/
        double _x_x2237;
        double _x_x2238;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2239 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x2239->since;
          {
            double _x_0_1 = _x_3_0.lo;
            _x_x2238 = _x_0_1; /*float64*/
          }
        }
        _x_x2237 = (-_x_x2238); /*float64*/
        _x_x2233 = kk_std_num_ddouble__new_Ddouble(_x_x2234, _x_x2237, _ctx); /*std/num/ddouble/ddouble*/
        smooth_total = kk_std_num_ddouble__lp__plus__rp_(_x_x2231, _x_x2233, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble x_0_10174 = kk_std_time_timestamp_unsafe_timespan_withleap(utc_0, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_num_ddouble__ddouble dt;
        kk_std_num_ddouble__ddouble _x_x2240;
        double _x_x2241;
        double _x_x2242;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2243 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_5 = _con_x2243->since;
          {
            double _x_4 = _x_5.hi;
            _x_x2242 = _x_4; /*float64*/
          }
        }
        _x_x2241 = (-_x_x2242); /*float64*/
        double _x_x2244;
        double _x_x2245;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2246 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_5_0 = _con_x2246->since;
          {
            double _x_0_2 = _x_5_0.lo;
            _x_x2245 = _x_0_2; /*float64*/
          }
        }
        _x_x2244 = (-_x_x2245); /*float64*/
        _x_x2240 = kk_std_num_ddouble__new_Ddouble(_x_x2241, _x_x2244, _ctx); /*std/num/ddouble/ddouble*/
        dt = kk_std_num_ddouble__lp__plus__rp_(x_0_10174, _x_x2240, _ctx); /*std/num/ddouble/ddouble*/
        kk_box_t _x_x2247;
        kk_std_core_types__tuple4 _x_x2248 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_time_timestamp__timestamp_box(start, _ctx), kk_std_time_timestamp__timestamp_box(smooth_start, _ctx), kk_std_num_ddouble__ddouble_box(smooth_total, _ctx), kk_std_num_ddouble__ddouble_box(dt, _ctx), _ctx); /*(150, 151, 152, 153)*/
        _x_x2247 = kk_std_core_types__tuple4_box(_x_x2248, _ctx); /*88*/
        return kk_std_core_types__new_Just(_x_x2247, _ctx);
      }
    }
  }
}

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_from_tai(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_duration__duration tai_since, kk_context_t* _ctx) { /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, tai-since : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp utc_0;
  kk_std_time_utc__leaps_table _x_x2249 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  utc_0 = kk_std_time_utc_utc_from_tai(_x_x2249, tai_since, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_core_types__maybe _match_x942;
  kk_std_time_timestamp__timestamp _x_x2250 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
  _match_x942 = kk_std_time_utc_utc_sls_leap_in_day(leaps, smooth, _x_x2250, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x942, _ctx)) {
    return utc_0;
  }
  {
    kk_box_t _box_x862 = _match_x942._cons.Just.value;
    kk_std_core_types__tuple4 _pat_1 = kk_std_core_types__tuple4_unbox(_box_x862, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x2251 = kk_std_core_types__as_Tuple4(_pat_1, _ctx);
    kk_box_t _box_x863 = _con_x2251->fst;
    kk_box_t _box_x864 = _con_x2251->snd;
    kk_box_t _box_x865 = _con_x2251->thd;
    kk_box_t _box_x866 = _con_x2251->field4;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x863, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp smooth_start = kk_std_time_timestamp__timestamp_unbox(_box_x864, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble smooth_total = kk_std_num_ddouble__ddouble_unbox(_box_x865, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble dt = kk_std_num_ddouble__ddouble_unbox(_box_x866, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2252 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2253 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(smooth_start, _ctx);
    kk_std_core_types__maybe_drop(_match_x942, _ctx);
    kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__fs__rp_(dt, smooth, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble t_10178 = kk_std_num_ddouble__lp__star__rp_(frac, smooth_total, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_num_ddouble__ddouble _x_x2254;
    kk_std_num_ddouble__ddouble _x_x2255;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2256 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x2256->since;
      _x_x2255 = _x; /*std/time/timestamp/timespan*/
    }
    _x_x2254 = kk_std_num_ddouble__lp__plus__rp_(_x_x2255, t_10178, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x2257;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2258 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x2258->since;
      int32_t _x_0 = _con_x2258->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(smooth_start, _ctx)) {
        kk_datatype_ptr_free(smooth_start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(smooth_start, _ctx);
      }
      _x_x2257 = _x_0; /*int32*/
    }
    return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x2254, _x_x2257, _ctx);
  }
}

kk_std_time_duration__duration kk_std_time_utc_utc_sls_to_tai(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_timestamp__timestamp sls, kk_context_t* _ctx) { /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, sls : utc-timestamp) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp utc_0;
  kk_std_core_types__maybe _match_x940;
  kk_std_time_utc__leaps_table _x_x2259 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  kk_std_time_timestamp__timestamp _x_x2260 = kk_std_time_timestamp__timestamp_dup(sls, _ctx); /*std/time/utc/utc-timestamp*/
  _match_x940 = kk_std_time_utc_utc_sls_leap_in_day(_x_x2259, smooth, _x_x2260, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x940, _ctx)) {
    utc_0 = sls; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_box_t _box_x867 = _match_x940._cons.Just.value;
    kk_std_core_types__tuple4 _pat_1 = kk_std_core_types__tuple4_unbox(_box_x867, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x2261 = kk_std_core_types__as_Tuple4(_pat_1, _ctx);
    kk_box_t _box_x868 = _con_x2261->fst;
    kk_box_t _box_x869 = _con_x2261->snd;
    kk_box_t _box_x870 = _con_x2261->thd;
    kk_box_t _box_x871 = _con_x2261->field4;
    kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x868, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp smooth_start = kk_std_time_timestamp__timestamp_unbox(_box_x869, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble smooth_total = kk_std_num_ddouble__ddouble_unbox(_box_x870, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble dt = kk_std_num_ddouble__ddouble_unbox(_box_x871, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2262 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2263 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
    kk_reuse_t _ru_x1165 = kk_reuse_null; /*@reuse*/;
    kk_reuse_t _x_x2264 = kk_datatype_ptr_dropn_reuse(sls, (KK_I32(0)), _ctx); /*@reuse*/
    _ru_x1165 = _x_x2264;
    kk_std_time_timestamp__timestamp_dup(smooth_start, _ctx);
    kk_std_time_timestamp__timestamp_dup(start, _ctx);
    kk_std_core_types__maybe_drop(_match_x940, _ctx);
    kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__fs__rp_(dt, smooth_total, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble t_10180 = kk_std_num_ddouble__lp__star__rp_(frac, smooth, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_time_timestamp__timestamp utc0;
    kk_std_num_ddouble__ddouble _x_x2265;
    kk_std_num_ddouble__ddouble _x_x2266;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2267 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x2267->since;
      _x_x2266 = _x; /*std/time/timestamp/timespan*/
    }
    _x_x2265 = kk_std_num_ddouble__lp__plus__rp_(_x_x2266, t_10180, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x2268;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2269 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x2269->since;
      int32_t _x_0 = _con_x2269->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(smooth_start, _ctx)) {
        kk_datatype_ptr_free(smooth_start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(smooth_start, _ctx);
      }
      _x_x2268 = _x_0; /*int32*/
    }
    utc0 = kk_std_time_timestamp__new_Timestamp(_ru_x1165, 0, _x_x2265, _x_x2268, _ctx); /*std/time/timestamp/timestamp*/
    bool _match_x941;
    kk_std_core_types__order _x_x2270;
    kk_std_time_timestamp__timestamp _x_x2271 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x2272 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    _x_x2270 = kk_std_time_timestamp_cmp(_x_x2271, _x_x2272, _ctx); /*order*/
    _match_x941 = kk_std_core_order__lp__excl__eq__rp_(_x_x2270, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
    if (_match_x941) {
      if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
        kk_datatype_ptr_free(start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(start, _ctx);
      }
      utc_0 = utc0; /*std/time/utc/utc-timestamp*/
    }
    else {
      kk_std_num_ddouble__ddouble ldiff;
      kk_std_num_ddouble__ddouble _x_x2273;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2274 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
        kk_std_num_ddouble__ddouble _x_2 = _con_x2274->since;
        if kk_likely(kk_datatype_ptr_is_unique(utc0, _ctx)) {
          kk_datatype_ptr_free(utc0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(utc0, _ctx);
        }
        _x_x2273 = _x_2; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x2275;
      double _x_x2276;
      double _x_x2277;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2278 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x2278->since;
        {
          double _x_1 = _x_3.hi;
          _x_x2277 = _x_1; /*float64*/
        }
      }
      _x_x2276 = (-_x_x2277); /*float64*/
      double _x_x2279;
      double _x_x2280;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2281 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _x_3_0 = _con_x2281->since;
        {
          double _x_0_0 = _x_3_0.lo;
          _x_x2280 = _x_0_0; /*float64*/
        }
      }
      _x_x2279 = (-_x_x2280); /*float64*/
      _x_x2275 = kk_std_num_ddouble__new_Ddouble(_x_x2276, _x_x2279, _ctx); /*std/num/ddouble/ddouble*/
      ldiff = kk_std_num_ddouble__lp__plus__rp_(_x_x2273, _x_x2275, _ctx); /*std/num/ddouble/ddouble*/
      utc_0 = kk_std_time_timestamp_add_leap_seconds(start, ldiff, _ctx); /*std/time/utc/utc-timestamp*/
    }
  }
  return kk_std_time_utc_utc_to_tai(leaps, utc_0, _ctx);
}
 
// Create a new smoothed leap second time scale with an optional period during
// which smoothing takes place. This is 1000s for `ts-utc-sls`.


// lift anonymous function
struct kk_std_time_utc_utc_sls_timescale_fun2283__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_timescale_fun2283(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_sls_timescale_fun2283(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3638, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2283__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_sls_timescale_fun2283__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_sls_timescale_fun2283, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3638 = _uniq_smooth_3638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_timescale_fun2283(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2283__t* _self = kk_function_as(struct kk_std_time_utc_utc_sls_timescale_fun2283__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3638 = _self->_uniq_smooth_3638; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3638, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_from_tai(leaps, _uniq_smooth_3638, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_sls_timescale_fun2284__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
};
static kk_std_time_duration__duration kk_std_time_utc_utc_sls_timescale_fun2284(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_sls_timescale_fun2284(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3638, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2284__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_sls_timescale_fun2284__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_sls_timescale_fun2284, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3638 = _uniq_smooth_3638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_utc_sls_timescale_fun2284(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2284__t* _self = kk_function_as(struct kk_std_time_utc_utc_sls_timescale_fun2284__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3638 = _self->_uniq_smooth_3638; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3638, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_to_tai(leaps, _uniq_smooth_3638, utc_0, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_utc_sls_timescale(kk_string_t name, kk_std_time_utc__leaps_table leaps, kk_std_core_types__optional smooth, kk_context_t* _ctx) { /* (name : string, leaps : leaps-table, smooth : ? std/time/timestamp/timespan) -> std/time/instant/timescale */ 
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
  if (kk_std_core_types__is_Optional(smooth, _ctx)) {
    kk_box_t _box_x872 = smooth._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_smooth_3639 = kk_std_num_ddouble__ddouble_unbox(_box_x872, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(smooth, _ctx);
    _uniq_smooth_3638 = _uniq_smooth_3639; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(smooth, _ctx);
    _uniq_smooth_3638 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_small(1000), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  }
  kk_function_t _x_x2282;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2282 = kk_std_time_utc_new_utc_sls_timescale_fun2283(leaps, _uniq_smooth_3638, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_core_types__optional _x_x2285;
  kk_box_t _x_x2286;
  kk_string_t _x_x2287;
  kk_define_string_literal(, _s_x2288, 7, "UTC-SLS", _ctx)
  _x_x2287 = kk_string_dup(_s_x2288, _ctx); /*string*/
  _x_x2286 = kk_string_box(_x_x2287); /*7*/
  _x_x2285 = kk_std_core_types__new_Optional(_x_x2286, _ctx); /*? 7*/
  return kk_std_time_instant_timescale(name, _x_x2282, kk_std_time_utc_new_utc_sls_timescale_fun2284(leaps, _uniq_smooth_3638, _ctx), _x_x2285, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Create a new UTC-SLS time scale from a provided leap second table `leaps`.
// Implements a UTC time scale except without ever showing leap seconds.
// UTC-SLS is equivalent to UTC except for the last 1000 seconds of a day where
// a leap second occurs. On such day, the leap second time step (positive or negative)
// is distributed over the last 1000 seconds of the day. On the full hour, UTC
// and UTC-SLS are equal again.
//
// This is a recommended time scale to use for time stamps or communication
// with other services since it avoids any potential trouble
// with leap seconds while still being quite precise.
// See also: <https://www.cl.cam.ac.uk/~mgk25/time/utc-sls>.
//
// You can create a UTC-SLS time scale based on the latest IERS leap second
// data using [`cal-utc-sls-load`](std_time_download.html#cal_utc_sls_load).


// lift anonymous function
struct kk_std_time_utc_ts_utc_sls_create_fun2292__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_utc_sls_create_fun2292(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_sls_create_fun2292(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3638, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2292__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_sls_create_fun2292__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_sls_create_fun2292, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3638 = _uniq_smooth_3638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_utc_sls_create_fun2292(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2292__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_sls_create_fun2292__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3638 = _self->_uniq_smooth_3638; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3638, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_from_tai(leaps, _uniq_smooth_3638, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_utc_sls_create_fun2293__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
};
static kk_std_time_duration__duration kk_std_time_utc_ts_utc_sls_create_fun2293(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_sls_create_fun2293(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3638, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2293__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_sls_create_fun2293__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_sls_create_fun2293, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3638 = _uniq_smooth_3638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_ts_utc_sls_create_fun2293(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2293__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_sls_create_fun2293__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3638 = _self->_uniq_smooth_3638; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3638, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_to_tai(leaps, _uniq_smooth_3638, utc_0, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_ts_utc_sls_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
  kk_std_core_types__optional _match_x939 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x939, _ctx)) {
    kk_box_t _box_x875 = _match_x939._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_smooth_3639 = kk_std_num_ddouble__ddouble_unbox(_box_x875, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x939, _ctx);
    _uniq_smooth_3638 = _uniq_smooth_3639; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x939, _ctx);
    _uniq_smooth_3638 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_small(1000), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  }
  kk_string_t _x_x2289;
  kk_define_string_literal(, _s_x2290, 7, "UTC-SLS", _ctx)
  _x_x2289 = kk_string_dup(_s_x2290, _ctx); /*string*/
  kk_function_t _x_x2291;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2291 = kk_std_time_utc_new_ts_utc_sls_create_fun2292(leaps, _uniq_smooth_3638, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_core_types__optional _x_x2294;
  kk_box_t _x_x2295;
  kk_string_t _x_x2296;
  kk_define_string_literal(, _s_x2297, 7, "UTC-SLS", _ctx)
  _x_x2296 = kk_string_dup(_s_x2297, _ctx); /*string*/
  _x_x2295 = kk_string_box(_x_x2296); /*7*/
  _x_x2294 = kk_std_core_types__new_Optional(_x_x2295, _ctx); /*? 7*/
  return kk_std_time_instant_timescale(_x_x2289, _x_x2291, kk_std_time_utc_new_ts_utc_sls_create_fun2293(leaps, _uniq_smooth_3638, _ctx), _x_x2294, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// TI time scale with smoothed leap seconds.
// Implements a TI time scale (`ts-ti`) except without ever showing leap seconds.
// TI-SLS is equivalent to TI except for the last 1000 seconds of a day where
// a leap second occurs. On such day, the leap second time step (positive or negative)
// is distributed over the last 1000 seconds of the day. On the full hour, TI
// and TI-SLS are equal again.


// lift anonymous function
struct kk_std_time_utc_ts_ti_sls_fun2300__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_ti_sls_fun2300(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_sls_fun2300(kk_std_num_ddouble__ddouble _uniq_smooth_3638, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2300__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_ti_sls_fun2300__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_ti_sls_fun2300, kk_context());
  _self->_uniq_smooth_3638 = _uniq_smooth_3638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_ti_sls_fun2300(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2300__t* _self = kk_function_as(struct kk_std_time_utc_ts_ti_sls_fun2300__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble _uniq_smooth_3638 = _self->_uniq_smooth_3638; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3638, _ctx);}, {}, _ctx)
  kk_std_time_utc__leaps_table _x_x2301 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  return kk_std_time_utc_utc_sls_from_tai(_x_x2301, _uniq_smooth_3638, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_ti_sls_fun2302__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble _uniq_smooth_3638;
};
static kk_std_time_duration__duration kk_std_time_utc_ts_ti_sls_fun2302(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_sls_fun2302(kk_std_num_ddouble__ddouble _uniq_smooth_3638, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2302__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_ti_sls_fun2302__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_ti_sls_fun2302, kk_context());
  _self->_uniq_smooth_3638 = _uniq_smooth_3638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_ts_ti_sls_fun2302(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2302__t* _self = kk_function_as(struct kk_std_time_utc_ts_ti_sls_fun2302__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble _uniq_smooth_3638 = _self->_uniq_smooth_3638; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3638, _ctx);}, {}, _ctx)
  kk_std_time_utc__leaps_table _x_x2303 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  return kk_std_time_utc_utc_sls_to_tai(_x_x2303, _uniq_smooth_3638, utc_0, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_ts_ti_sls;
 
// Leap second table up to 2017-01-01Z.


// lift anonymous function
struct kk_std_time_utc_leaps_table_y2017_fun2311__t {
  struct kk_function_s _base;
  kk_std_time_timestamp__timestamp end_10226;
};
static bool kk_std_time_utc_leaps_table_y2017_fun2311(kk_function_t _fself, kk_box_t _b_x883, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_leaps_table_y2017_fun2311(kk_std_time_timestamp__timestamp end_10226, kk_context_t* _ctx) {
  struct kk_std_time_utc_leaps_table_y2017_fun2311__t* _self = kk_function_alloc_as(struct kk_std_time_utc_leaps_table_y2017_fun2311__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_leaps_table_y2017_fun2311, kk_context());
  _self->end_10226 = end_10226;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_utc_leaps_table_y2017_fun2311(kk_function_t _fself, kk_box_t _b_x883, kk_context_t* _ctx) {
  struct kk_std_time_utc_leaps_table_y2017_fun2311__t* _self = kk_function_as(struct kk_std_time_utc_leaps_table_y2017_fun2311__t*, _fself, _ctx);
  kk_std_time_timestamp__timestamp end_10226 = _self->end_10226; /* std/time/utc/utc-timestamp */
  kk_drop_match(_self, {kk_std_time_timestamp__timestamp_dup(end_10226, _ctx);}, {}, _ctx)
  kk_std_core_types__order _x_x2312;
  kk_std_time_timestamp__timestamp _x_x2313;
  kk_std_time_utc__leap_adjust _match_x937 = kk_std_time_utc__leap_adjust_unbox(_b_x883, KK_OWNED, _ctx); /*std/time/utc/leap-adjust*/;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2314 = kk_std_time_utc__as_Leap_adjust(_match_x937, _ctx);
    kk_std_time_timestamp__timestamp _x_0 = _con_x2314->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_0 = _con_x2314->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x2314->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x2314->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2315 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2316 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x937, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5, _ctx)) {
        kk_datatype_ptr_free(_pat_5, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5, _ctx);
      }
      kk_datatype_ptr_free(_match_x937, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x937, _ctx);
    }
    _x_x2313 = _x_0; /*std/time/utc/utc-timestamp*/
  }
  _x_x2312 = kk_std_time_timestamp_cmp(_x_x2313, end_10226, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x2312, kk_std_core_types__new_Gt(_ctx), _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_y2017;
 
// Get a list of leap second steps in a triple, NTP start time, offset just before, and the new offset at that time,
// the base offset, the drift start date and the drift rate.


// lift anonymous function
struct kk_std_time_utc_get_leap_steps_fun2329__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_get_leap_steps_fun2329(kk_function_t _fself, kk_box_t _b_x919, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_get_leap_steps_fun2329(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_get_leap_steps_fun2329, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_get_leap_steps_fun2329(kk_function_t _fself, kk_box_t _b_x919, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 las_931 = kk_std_core_types__tuple2_unbox(_b_x919, KK_OWNED, _ctx); /*(std/time/utc/leap-adjust, std/time/utc/leap-adjust)*/;
  kk_std_num_ddouble__ddouble ofs1;
  kk_std_time_utc__leap_adjust _x_x2330;
  {
    kk_box_t _box_x894 = las_931.fst;
    kk_box_t _box_x895 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_2 = kk_std_time_utc__leap_adjust_unbox(_box_x894, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_2, _ctx);
    _x_x2330 = _x_2; /*std/time/utc/leap-adjust*/
  }
  kk_std_time_timestamp__timestamp _x_x2331;
  {
    kk_box_t _box_x896 = las_931.fst;
    kk_box_t _box_x897 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_1 = kk_std_time_utc__leap_adjust_unbox(_box_x897, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_1, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2332 = kk_std_time_utc__as_Leap_adjust(_x_1, _ctx);
      kk_std_time_timestamp__timestamp _x_0 = _con_x2332->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0 = _con_x2332->offset;
      kk_std_time_timestamp__timestamp _pat_5 = _con_x2332->drift_start;
      kk_std_num_ddouble__ddouble _pat_8 = _con_x2332->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2333 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2334 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5, _ctx)) {
          kk_datatype_ptr_free(_pat_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5, _ctx);
        }
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x2331 = _x_0; /*std/time/utc/utc-timestamp*/
    }
  }
  ofs1 = kk_std_time_utc_delta_tai(_x_x2330, _x_x2331, _ctx); /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble ofs2;
  kk_std_time_utc__leap_adjust _x_x2335;
  {
    kk_box_t _box_x898 = las_931.fst;
    kk_box_t _box_x899 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_3 = kk_std_time_utc__leap_adjust_unbox(_box_x899, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_3, _ctx);
    _x_x2335 = _x_3; /*std/time/utc/leap-adjust*/
  }
  kk_std_time_timestamp__timestamp _x_x2336;
  {
    kk_box_t _box_x900 = las_931.fst;
    kk_box_t _box_x901 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_1_0 = kk_std_time_utc__leap_adjust_unbox(_box_x901, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2337 = kk_std_time_utc__as_Leap_adjust(_x_1_0, _ctx);
      kk_std_time_timestamp__timestamp _x_0_0 = _con_x2337->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_0 = _con_x2337->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x2337->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x2337->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2338 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2339 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
          kk_datatype_ptr_free(_pat_5_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_0, _ctx);
        }
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x2336 = _x_0_0; /*std/time/utc/utc-timestamp*/
    }
  }
  ofs2 = kk_std_time_utc_delta_tai(_x_x2335, _x_x2336, _ctx); /*std/time/timestamp/timespan*/
  kk_std_core_types__tuple4 _x_x2340;
  kk_box_t _x_x2341;
  kk_std_time_timestamp__timestamp _x_x2342;
  {
    kk_box_t _box_x902 = las_931.fst;
    kk_box_t _box_x903 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_1_1 = kk_std_time_utc__leap_adjust_unbox(_box_x903, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_1_1, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2343 = kk_std_time_utc__as_Leap_adjust(_x_1_1, _ctx);
      kk_std_time_timestamp__timestamp _x_0_1 = _con_x2343->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_1 = _con_x2343->offset;
      kk_std_time_timestamp__timestamp _pat_5_1 = _con_x2343->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1 = _con_x2343->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2344 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2345 = kk_std_time_timestamp__as_Timestamp(_pat_5_1, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_1, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_1, _ctx)) {
          kk_datatype_ptr_free(_pat_5_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_1, _ctx);
        }
        kk_datatype_ptr_free(_x_1_1, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_0_1, _ctx);
        kk_datatype_ptr_decref(_x_1_1, _ctx);
      }
      _x_x2342 = _x_0_1; /*std/time/utc/utc-timestamp*/
    }
  }
  _x_x2341 = kk_std_time_timestamp__timestamp_box(_x_x2342, _ctx); /*150*/
  kk_box_t _x_x2346;
  kk_std_core_types__tuple3 _x_x2347;
  kk_box_t _x_x2348;
  kk_std_num_ddouble__ddouble _x_x2349;
  {
    kk_box_t _box_x904 = las_931.fst;
    kk_box_t _box_x905 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_5 = kk_std_time_utc__leap_adjust_unbox(_box_x905, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_5, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2350 = kk_std_time_utc__as_Leap_adjust(_x_5, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_5 = _con_x2350->utc_start;
      kk_std_num_ddouble__ddouble _x_4 = _con_x2350->offset;
      kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x2350->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x2350->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2351 = kk_std_time_timestamp__as_Timestamp(_pat_0_5, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2352 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_0, _ctx)) {
          kk_datatype_ptr_free(_pat_5_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_0_0, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_5, _ctx)) {
          kk_datatype_ptr_free(_pat_0_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_5, _ctx);
        }
        kk_datatype_ptr_free(_x_5, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_5, _ctx);
      }
      _x_x2349 = _x_4; /*std/time/timestamp/timespan*/
    }
  }
  _x_x2348 = kk_std_num_ddouble__ddouble_box(_x_x2349, _ctx); /*141*/
  kk_box_t _x_x2353;
  kk_std_time_timestamp__timestamp _x_x2354;
  {
    kk_box_t _box_x906 = las_931.fst;
    kk_box_t _box_x907 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_7 = kk_std_time_utc__leap_adjust_unbox(_box_x907, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_7, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2355 = kk_std_time_utc__as_Leap_adjust(_x_7, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_7 = _con_x2355->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_2 = _con_x2355->offset;
      kk_std_time_timestamp__timestamp _x_6 = _con_x2355->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1_0 = _con_x2355->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2356 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2357 = kk_std_time_timestamp__as_Timestamp(_x_6, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_x_7, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_7, _ctx)) {
          kk_datatype_ptr_free(_pat_0_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_7, _ctx);
        }
        kk_datatype_ptr_free(_x_7, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_6, _ctx);
        kk_datatype_ptr_decref(_x_7, _ctx);
      }
      _x_x2354 = _x_6; /*std/time/utc/utc-timestamp*/
    }
  }
  _x_x2353 = kk_std_time_timestamp__timestamp_box(_x_x2354, _ctx); /*142*/
  kk_box_t _x_x2358;
  kk_std_num_ddouble__ddouble _x_x2359;
  {
    kk_box_t _box_x908 = las_931.fst;
    kk_box_t _box_x909 = las_931.snd;
    kk_std_time_utc__leap_adjust _x_9 = kk_std_time_utc__leap_adjust_unbox(_box_x909, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_x_9, _ctx);
    kk_std_core_types__tuple2_drop(las_931, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2360 = kk_std_time_utc__as_Leap_adjust(_x_9, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_9 = _con_x2360->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_3 = _con_x2360->offset;
      kk_std_time_timestamp__timestamp _pat_6_2 = _con_x2360->drift_start;
      kk_std_num_ddouble__ddouble _x_8 = _con_x2360->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2361 = kk_std_time_timestamp__as_Timestamp(_pat_0_9, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2362 = kk_std_time_timestamp__as_Timestamp(_pat_6_2, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_6_2, _ctx)) {
          kk_datatype_ptr_free(_pat_6_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_6_2, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_0_9, _ctx)) {
          kk_datatype_ptr_free(_pat_0_9, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_0_9, _ctx);
        }
        kk_datatype_ptr_free(_x_9, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_9, _ctx);
      }
      _x_x2359 = _x_8; /*std/num/ddouble/ddouble*/
    }
  }
  _x_x2358 = kk_std_num_ddouble__ddouble_box(_x_x2359, _ctx); /*143*/
  _x_x2347 = kk_std_core_types__new_Tuple3(_x_x2348, _x_x2353, _x_x2358, _ctx); /*(141, 142, 143)*/
  _x_x2346 = kk_std_core_types__tuple3_box(_x_x2347, _ctx); /*153*/
  _x_x2340 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x2341, kk_std_num_ddouble__ddouble_box(ofs1, _ctx), kk_std_num_ddouble__ddouble_box(ofs2, _ctx), _x_x2346, _ctx); /*(150, 151, 152, 153)*/
  return kk_std_core_types__tuple4_box(_x_x2340, _ctx);
}

kk_std_core_types__list kk_std_time_utc_get_leap_steps(kk_std_core_types__optional table, kk_context_t* _ctx) { /* (table : ? leaps-table) -> list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))> */ 
  kk_std_core_types__list adjusts;
  kk_std_core_types__list _x_x2323;
  kk_std_time_utc__leaps_table _match_x934;
  if (kk_std_core_types__is_Optional(table, _ctx)) {
    kk_box_t _box_x891 = table._cons._Optional.value;
    kk_std_time_utc__leaps_table _uniq_table_3727 = kk_std_time_utc__leaps_table_unbox(_box_x891, KK_BORROWED, _ctx);
    kk_std_time_utc__leaps_table_dup(_uniq_table_3727, _ctx);
    kk_std_core_types__optional_drop(table, _ctx);
    _match_x934 = _uniq_table_3727; /*std/time/utc/leaps-table*/
  }
  else {
    kk_std_core_types__optional_drop(table, _ctx);
    _match_x934 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  }
  {
    struct kk_std_time_utc_Leaps_table* _con_x2324 = kk_std_time_utc__as_Leaps_table(_match_x934, _ctx);
    kk_std_time_instant__instant _pat_0 = _con_x2324->expire;
    kk_std_core_types__list _x = _con_x2324->adjusts;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x934, _ctx)) {
      kk_std_time_instant__instant_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x934, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x934, _ctx);
    }
    _x_x2323 = _x; /*list<std/time/utc/leap-adjust>*/
  }
  adjusts = kk_std_core_list_reverse_acc(kk_std_core_types__new_Nil(_ctx), _x_x2323, _ctx); /*list<std/time/utc/leap-adjust>*/
  kk_std_core_types__list _b_x917_920;
  kk_std_core_types__list _x_x2325;
  kk_box_t _x_x2326;
  kk_std_time_utc__leap_adjust _x_x2327 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  _x_x2326 = kk_std_time_utc__leap_adjust_box(_x_x2327, _ctx); /*79*/
  kk_std_core_types__list _x_x2328 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
  _x_x2325 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2326, _x_x2328, _ctx); /*list<79>*/
  _b_x917_920 = kk_std_core_list_zip(_x_x2325, adjusts, _ctx); /*list<(std/time/utc/leap-adjust, std/time/utc/leap-adjust)>*/
  kk_function_t _brw_x932 = kk_std_time_utc_new_get_leap_steps_fun2329(_ctx); /*(2217) -> 2219 2218*/;
  kk_std_core_types__list _brw_x933 = kk_std_core_list_map(_b_x917_920, _brw_x932, _ctx); /*list<2218>*/;
  kk_function_drop(_brw_x932, _ctx);
  return _brw_x933;
}

// initialization
void kk_std_time_utc__init(kk_context_t* _ctx){
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
  kk_std_text_parse__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_num_int32__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x1192;
    kk_define_string_literal(, _s_x1193, 7, "utc@utc", _ctx)
    _x_x1192 = kk_string_dup(_s_x1193, _ctx); /*string*/
    kk_std_time_utc_utc_fs__tag = kk_std_core_hnd__new_Htag(_x_x1192, _ctx); /*hnd/htag<std/time/utc/utc>*/
  }
  {
    kk_std_time_timestamp__timestamp _x_x1203 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x1204 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_utc_zero = kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, _x_x1203, kk_std_num_ddouble_zero, _x_x1204, kk_std_num_ddouble_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    kk_std_time_utc_ntp2000 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_str("3155673600", _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_utc_utc1958 = kk_std_time_timestamp_int_fs_timestamp(kk_integer_from_int(-1325376000, _ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
  }
  kk_init_string_literal(kk_std_time_utc_default_iers_leap_seconds, _ctx)
  {
    kk_std_time_utc_jd_epoch_shift = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_utc_mjd_epoch_shift = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_int(51544, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  }
  kk_init_string_literal(kk_std_time_utc_default_leap_seconds_pre72, _ctx)
  {
    kk_vector_t v_10011;
    kk_string_t _x_x1958;
    kk_define_string_literal(, _s_x1959, 2922, "\n  # from: Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.\n  1958 JAN  1 =JD 2436204.5     TAI-UTC= 0.0  S + (MJD - 36204.) X 0.00073458 S\n  1958 JAN 15 =JD 2436219.29167 TAI-UTC= 0.02 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB  5 =JD 2436240.29167 TAI-UTC= 0.04 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB 19 =JD 2436254.29167 TAI-UTC= 0.06 S + (MJD - 36204.) X 0.00073458 S\n  1958 APR  9 =JD 2436303.29167 TAI-UTC= 0.08 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUN 11 =JD 2436366.29167 TAI-UTC= 0.10 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL  2 =JD 2436387.29167 TAI-UTC= 0.12 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL 16 =JD 2436401.29167 TAI-UTC= 0.14 S + (MJD - 36204.) X 0.00073458 S\n  1958 OCT 22 =JD 2436499.29167 TAI-UTC= 0.16 S + (MJD - 36204.) X 0.00073458 S\n  1958 NOV 26 =JD 2436534.29167 TAI-UTC= 0.18 S + (MJD - 36204.) X 0.00073458 S\n  1958 DEC 24 =JD 2436562.29167 TAI-UTC= 0.20 S + (MJD - 36204.) X 0.00073458 S\n\n  1959 JAN  1 =JD 2436569.5     TAI-UTC= 0.4681220 S + (MJD - 36569.) X 0.000864 S\n  1959 JAN 28 =JD 2436597.29167 TAI-UTC= 0.4881220 S + (MJD - 36569.) X 0.000864 S\n  1959 FEB 25 =JD 2436625.29167 TAI-UTC= 0.5081220 S + (MJD - 36569.) X 0.000864 S\n  1959 APR  5 =JD 2436664.29167 TAI-UTC= 0.5281220 S + (MJD - 36569.) X 0.000864 S\n  1959 AUG 26 =JD 2436807.29167 TAI-UTC= 0.5481220 S + (MJD - 36569.) X 0.000864 S\n  1959 SEP 30 =JD 2436842.29167 TAI-UTC= 0.5681220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV  4 =JD 2436877.29167 TAI-UTC= 0.5881220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV 18 =JD 2436891.29167 TAI-UTC= 0.6081220 S + (MJD - 36569.) X 0.000864 S\n  1959 DEC 16 =JD 2436919.29167 TAI-UTC= 0.6281220 S + (MJD - 36569.) X 0.000864 S\n  1960 JAN  1 =JD 2436934.5     TAI-UTC= 0.9434820 S + (MJD - 36934.) X 0.001296 S\n\n  # from: https://maia.usno.navy.mil/ser7/tai-utc.dat\n  1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S\n  1961 AUG  1 =JD 2437512.5  TAI-UTC=   1.3728180 S + (MJD - 37300.) X 0.001296 S\n  1962 JAN  1 =JD 2437665.5  TAI-UTC=   1.8458580 S + (MJD - 37665.) X 0.0011232S\n  1963 NOV  1 =JD 2438334.5  TAI-UTC=   1.9458580 S + (MJD - 37665.) X 0.0011232S\n  1964 JAN  1 =JD 2438395.5  TAI-UTC=   3.2401300 S + (MJD - 38761.) X 0.001296 S\n  1964 APR  1 =JD 2438486.5  TAI-UTC=   3.3401300 S + (MJD - 38761.) X 0.001296 S\n  1964 SEP  1 =JD 2438639.5  TAI-UTC=   3.4401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JAN  1 =JD 2438761.5  TAI-UTC=   3.5401300 S + (MJD - 38761.) X 0.001296 S\n  1965 MAR  1 =JD 2438820.5  TAI-UTC=   3.6401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JUL  1 =JD 2438942.5  TAI-UTC=   3.7401300 S + (MJD - 38761.) X 0.001296 S\n  1965 SEP  1 =JD 2439004.5  TAI-UTC=   3.8401300 S + (MJD - 38761.) X 0.001296 S\n  1966 JAN  1 =JD 2439126.5  TAI-UTC=   4.3131700 S + (MJD - 39126.) X 0.002592 S\n  1968 FEB  1 =JD 2439887.5  TAI-UTC=   4.2131700 S + (MJD - 39126.) X 0.002592 S", _ctx)
    _x_x1958 = kk_string_dup(_s_x1959, _ctx); /*string*/
    kk_string_t _x_x1960;
    kk_define_string_literal(, _s_x1961, 1, "\n", _ctx)
    _x_x1960 = kk_string_dup(_s_x1961, _ctx); /*string*/
    v_10011 = kk_string_splitv(_x_x1958,_x_x1960,kk_context()); /*vector<string>*/
    kk_std_core_types__list _b_x619_622 = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    kk_std_core_types__list xs_10126 = kk_std_core_list_flatmap_maybe(_b_x619_622, kk_std_time_utc_new_leaps_table_pre1972_fun1962(_ctx), _ctx); /*list<std/time/utc/leap-adjust>*/;
    kk_std_core_types__list adjusts = kk_std_core_list_reverse_acc(kk_std_core_types__new_Nil(_ctx), xs_10126, _ctx); /*list<std/time/utc/leap-adjust>*/;
    kk_std_time_instant__instant expire;
    kk_string_t _x_x1964;
    kk_define_string_literal(, _s_x1965, 2922, "\n  # from: Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.\n  1958 JAN  1 =JD 2436204.5     TAI-UTC= 0.0  S + (MJD - 36204.) X 0.00073458 S\n  1958 JAN 15 =JD 2436219.29167 TAI-UTC= 0.02 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB  5 =JD 2436240.29167 TAI-UTC= 0.04 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB 19 =JD 2436254.29167 TAI-UTC= 0.06 S + (MJD - 36204.) X 0.00073458 S\n  1958 APR  9 =JD 2436303.29167 TAI-UTC= 0.08 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUN 11 =JD 2436366.29167 TAI-UTC= 0.10 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL  2 =JD 2436387.29167 TAI-UTC= 0.12 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL 16 =JD 2436401.29167 TAI-UTC= 0.14 S + (MJD - 36204.) X 0.00073458 S\n  1958 OCT 22 =JD 2436499.29167 TAI-UTC= 0.16 S + (MJD - 36204.) X 0.00073458 S\n  1958 NOV 26 =JD 2436534.29167 TAI-UTC= 0.18 S + (MJD - 36204.) X 0.00073458 S\n  1958 DEC 24 =JD 2436562.29167 TAI-UTC= 0.20 S + (MJD - 36204.) X 0.00073458 S\n\n  1959 JAN  1 =JD 2436569.5     TAI-UTC= 0.4681220 S + (MJD - 36569.) X 0.000864 S\n  1959 JAN 28 =JD 2436597.29167 TAI-UTC= 0.4881220 S + (MJD - 36569.) X 0.000864 S\n  1959 FEB 25 =JD 2436625.29167 TAI-UTC= 0.5081220 S + (MJD - 36569.) X 0.000864 S\n  1959 APR  5 =JD 2436664.29167 TAI-UTC= 0.5281220 S + (MJD - 36569.) X 0.000864 S\n  1959 AUG 26 =JD 2436807.29167 TAI-UTC= 0.5481220 S + (MJD - 36569.) X 0.000864 S\n  1959 SEP 30 =JD 2436842.29167 TAI-UTC= 0.5681220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV  4 =JD 2436877.29167 TAI-UTC= 0.5881220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV 18 =JD 2436891.29167 TAI-UTC= 0.6081220 S + (MJD - 36569.) X 0.000864 S\n  1959 DEC 16 =JD 2436919.29167 TAI-UTC= 0.6281220 S + (MJD - 36569.) X 0.000864 S\n  1960 JAN  1 =JD 2436934.5     TAI-UTC= 0.9434820 S + (MJD - 36934.) X 0.001296 S\n\n  # from: https://maia.usno.navy.mil/ser7/tai-utc.dat\n  1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S\n  1961 AUG  1 =JD 2437512.5  TAI-UTC=   1.3728180 S + (MJD - 37300.) X 0.001296 S\n  1962 JAN  1 =JD 2437665.5  TAI-UTC=   1.8458580 S + (MJD - 37665.) X 0.0011232S\n  1963 NOV  1 =JD 2438334.5  TAI-UTC=   1.9458580 S + (MJD - 37665.) X 0.0011232S\n  1964 JAN  1 =JD 2438395.5  TAI-UTC=   3.2401300 S + (MJD - 38761.) X 0.001296 S\n  1964 APR  1 =JD 2438486.5  TAI-UTC=   3.3401300 S + (MJD - 38761.) X 0.001296 S\n  1964 SEP  1 =JD 2438639.5  TAI-UTC=   3.4401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JAN  1 =JD 2438761.5  TAI-UTC=   3.5401300 S + (MJD - 38761.) X 0.001296 S\n  1965 MAR  1 =JD 2438820.5  TAI-UTC=   3.6401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JUL  1 =JD 2438942.5  TAI-UTC=   3.7401300 S + (MJD - 38761.) X 0.001296 S\n  1965 SEP  1 =JD 2439004.5  TAI-UTC=   3.8401300 S + (MJD - 38761.) X 0.001296 S\n  1966 JAN  1 =JD 2439126.5  TAI-UTC=   4.3131700 S + (MJD - 39126.) X 0.002592 S\n  1968 FEB  1 =JD 2439887.5  TAI-UTC=   4.2131700 S + (MJD - 39126.) X 0.002592 S", _ctx)
    _x_x1964 = kk_string_dup(_s_x1965, _ctx); /*string*/
    kk_std_core_types__list _x_x1966 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
    expire = kk_std_time_utc_parse_leap_expire(_x_x1964, _x_x1966, _ctx); /*std/time/instant/instant*/
    kk_std_time_utc_leaps_table_pre1972 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx); /*std/time/utc/leaps-table*/
  }
  {
    kk_vector_t v_10011;
    kk_string_t _x_x2083;
    kk_define_string_literal(, _s_x2084, 1125, "\n  # From: https://hpiers.obspm.fr/iers/bul/bulc/ntp/leap-seconds.list\n  #\tUpdated through IERS Bulletin C (https://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat)\n  # File expires on:  28 December 2024\n  #\n  #@\t3944332800\n  #\n  2272060800  10  # 1 Jan 1972\n  2287785600  11  # 1 Jul 1972\n  2303683200  12  # 1 Jan 1973\n  2335219200  13  # 1 Jan 1974\n  2366755200  14  # 1 Jan 1975\n  2398291200  15  # 1 Jan 1976\n  2429913600  16  # 1 Jan 1977\n  2461449600  17  # 1 Jan 1978\n  2492985600  18  # 1 Jan 1979\n  2524521600  19  # 1 Jan 1980\n  2571782400  20  # 1 Jul 1981\n  2603318400  21  # 1 Jul 1982\n  2634854400  22  # 1 Jul 1983\n  2698012800  23  # 1 Jul 1985\n  2776982400  24  # 1 Jan 1988\n  2840140800  25  # 1 Jan 1990\n  2871676800  26  # 1 Jan 1991\n  2918937600  27  # 1 Jul 1992\n  2950473600  28  # 1 Jul 1993\n  2982009600  29  # 1 Jul 1994\n  3029443200  30  # 1 Jan 1996\n  3076704000  31  # 1 Jul 1997\n  3124137600  32  # 1 Jan 1999\n  3345062400  33  # 1 Jan 2006\n  3439756800  34  # 1 Jan 2009\n  3550089600  35  # 1 Jul 2012\n  3644697600  36  # 1 Jul 2015\n  3692217600  37  # 1 Jan 2017\n  // 3723753600  35  # 1 Jan 2018", _ctx)
    _x_x2083 = kk_string_dup(_s_x2084, _ctx); /*string*/
    kk_string_t _x_x2085;
    kk_define_string_literal(, _s_x2086, 1, "\n", _ctx)
    _x_x2085 = kk_string_dup(_s_x2086, _ctx); /*string*/
    v_10011 = kk_string_splitv(_x_x2083,_x_x2085,kk_context()); /*vector<string>*/
    kk_std_core_types__list _b_x784_787 = kk_std_core_vector_vlist(v_10011, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    kk_std_core_types__list xs_10131 = kk_std_core_list_flatmap_maybe(_b_x784_787, kk_std_time_utc_new_leaps_table_ti_fun2087(_ctx), _ctx); /*list<std/time/utc/leap-adjust>*/;
    kk_std_core_types__list adjusts = kk_std_core_list_reverse_acc(kk_std_core_types__new_Nil(_ctx), xs_10131, _ctx); /*list<std/time/utc/leap-adjust>*/;
    kk_std_time_instant__instant expire;
    kk_string_t _x_x2089;
    kk_define_string_literal(, _s_x2090, 1125, "\n  # From: https://hpiers.obspm.fr/iers/bul/bulc/ntp/leap-seconds.list\n  #\tUpdated through IERS Bulletin C (https://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat)\n  # File expires on:  28 December 2024\n  #\n  #@\t3944332800\n  #\n  2272060800  10  # 1 Jan 1972\n  2287785600  11  # 1 Jul 1972\n  2303683200  12  # 1 Jan 1973\n  2335219200  13  # 1 Jan 1974\n  2366755200  14  # 1 Jan 1975\n  2398291200  15  # 1 Jan 1976\n  2429913600  16  # 1 Jan 1977\n  2461449600  17  # 1 Jan 1978\n  2492985600  18  # 1 Jan 1979\n  2524521600  19  # 1 Jan 1980\n  2571782400  20  # 1 Jul 1981\n  2603318400  21  # 1 Jul 1982\n  2634854400  22  # 1 Jul 1983\n  2698012800  23  # 1 Jul 1985\n  2776982400  24  # 1 Jan 1988\n  2840140800  25  # 1 Jan 1990\n  2871676800  26  # 1 Jan 1991\n  2918937600  27  # 1 Jul 1992\n  2950473600  28  # 1 Jul 1993\n  2982009600  29  # 1 Jul 1994\n  3029443200  30  # 1 Jan 1996\n  3076704000  31  # 1 Jul 1997\n  3124137600  32  # 1 Jan 1999\n  3345062400  33  # 1 Jan 2006\n  3439756800  34  # 1 Jan 2009\n  3550089600  35  # 1 Jul 2012\n  3644697600  36  # 1 Jul 2015\n  3692217600  37  # 1 Jan 2017\n  // 3723753600  35  # 1 Jan 2018", _ctx)
    _x_x2089 = kk_string_dup(_s_x2090, _ctx); /*string*/
    kk_std_core_types__list _x_x2091 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
    expire = kk_std_time_utc_parse_leap_expire(_x_x2089, _x_x2091, _ctx); /*std/time/instant/instant*/
    kk_std_time_utc__leaps_table _x_x2092 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx); /*std/time/utc/leaps-table*/
    kk_std_time_utc__leaps_table _x_x2093 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_pre1972, _ctx); /*std/time/utc/leaps-table*/
    kk_std_time_utc_leaps_table_ti = kk_std_time_utc_extend(_x_x2092, _x_x2093, _ctx); /*std/time/utc/leaps-table*/
  }
  {
    kk_string_t _x_x2094 = kk_string_empty(); /*string*/
    kk_std_time_utc__leaps_table _x_x2096 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
    kk_std_time_utc_ts_ti = kk_std_time_utc_utc_timescale(_x_x2094, _x_x2096, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_instant__instant _x_x2103 = kk_std_time_instant__instant_dup(kk_std_time_instant_epoch, _ctx); /*std/time/instant/instant*/
    kk_std_time_utc_leaps_table0 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x2103, kk_std_core_types__new_Nil(_ctx), _ctx); /*std/time/utc/leaps-table*/
  }
  {
    kk_std_time_utc_unix2000 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_int(946684800, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_utc_ts_ntp = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_utc_ts_unix = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_num_ddouble__ddouble _uniq_smooth_3638;
    kk_std_core_types__optional _match_x938 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x938, _ctx)) {
      kk_box_t _box_x878 = _match_x938._cons._Optional.value;
      kk_std_num_ddouble__ddouble _uniq_smooth_3639 = kk_std_num_ddouble__ddouble_unbox(_box_x878, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x938, _ctx);
      _uniq_smooth_3638 = _uniq_smooth_3639; /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x938, _ctx);
      _uniq_smooth_3638 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_small(1000), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
    }
    kk_string_t _x_x2298;
    kk_define_string_literal(, _s_x2299, 6, "TI-SLS", _ctx)
    _x_x2298 = kk_string_dup(_s_x2299, _ctx); /*string*/
    kk_std_core_types__optional _x_x2304;
    kk_box_t _x_x2305;
    kk_string_t _x_x2306;
    kk_define_string_literal(, _s_x2307, 7, "UTC-SLS", _ctx)
    _x_x2306 = kk_string_dup(_s_x2307, _ctx); /*string*/
    _x_x2305 = kk_string_box(_x_x2306); /*7*/
    _x_x2304 = kk_std_core_types__new_Optional(_x_x2305, _ctx); /*? 7*/
    kk_std_time_utc_ts_ti_sls = kk_std_time_instant_timescale(_x_x2298, kk_std_time_utc_new_ts_ti_sls_fun2300(_uniq_smooth_3638, _ctx), kk_std_time_utc_new_ts_ti_sls_fun2302(_uniq_smooth_3638, _ctx), _x_x2304, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_timestamp__timestamp end_10226 = kk_std_time_timestamp_int_fs_timestamp(kk_integer_from_int(536544000, _ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/utc/utc-timestamp*/;
    kk_std_core_types__list _b_x884_885;
    kk_std_core_types__list _x_x2308;
    kk_std_time_utc__leaps_table _x_x2309 = kk_std_time_utc_leaps_table_ti; /*std/time/utc/leaps-table*/
    {
      struct kk_std_time_utc_Leaps_table* _con_x2310 = kk_std_time_utc__as_Leaps_table(_x_x2309, _ctx);
      kk_std_time_instant__instant _pat_0 = _con_x2310->expire;
      kk_std_core_types__list _x = _con_x2310->adjusts;
      _x_x2308 = kk_std_core_types__list_dup(_x, _ctx); /*list<std/time/utc/leap-adjust>*/
    }
    _b_x884_885 = kk_std_core_list_drop_while(_x_x2308, kk_std_time_utc_new_leaps_table_y2017_fun2311(end_10226, _ctx), _ctx); /*list<std/time/utc/leap-adjust>*/
    kk_std_time_instant__instant _x_x2317;
    kk_std_core_types__optional _match_x936 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x936, _ctx)) {
      kk_box_t _box_x889 = _match_x936._cons._Optional.value;
      kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x889, KK_BORROWED, _ctx);
      kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
      kk_std_core_types__optional_drop(_match_x936, _ctx);
      _x_x2317 = _uniq_expire_375; /*std/time/instant/instant*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x936, _ctx);
      kk_std_time_utc__leaps_table _x_x2318 = kk_std_time_utc_leaps_table_ti; /*std/time/utc/leaps-table*/
      {
        struct kk_std_time_utc_Leaps_table* _con_x2319 = kk_std_time_utc__as_Leaps_table(_x_x2318, _ctx);
        kk_std_time_instant__instant _x_1 = _con_x2319->expire;
        _x_x2317 = kk_std_time_instant__instant_dup(_x_1, _ctx); /*std/time/instant/instant*/
      }
    }
    kk_std_core_types__list _x_x2320;
    kk_std_core_types__optional _match_x935 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x884_885, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x935, _ctx)) {
      kk_box_t _box_x890 = _match_x935._cons._Optional.value;
      kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x890, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
      kk_std_core_types__optional_drop(_match_x935, _ctx);
      _x_x2320 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x935, _ctx);
      kk_std_time_utc__leaps_table _x_x2321 = kk_std_time_utc_leaps_table_ti; /*std/time/utc/leaps-table*/
      {
        struct kk_std_time_utc_Leaps_table* _con_x2322 = kk_std_time_utc__as_Leaps_table(_x_x2321, _ctx);
        kk_std_time_instant__instant _pat_0_3 = _con_x2322->expire;
        kk_std_core_types__list _x_2 = _con_x2322->adjusts;
        _x_x2320 = kk_std_core_types__list_dup(_x_2, _ctx); /*list<std/time/utc/leap-adjust>*/
      }
    }
    kk_std_time_utc_leaps_table_y2017 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x2317, _x_x2320, _ctx); /*std/time/utc/leaps-table*/
  }
}

// termination
void kk_std_time_utc__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_utc__leaps_table_drop(kk_std_time_utc_leaps_table_y2017, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_utc_ts_ti_sls, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_utc_ts_unix, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_utc_ts_ntp, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_utc_unix2000, _ctx);
  kk_std_time_utc__leaps_table_drop(kk_std_time_utc_leaps_table0, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_utc_ts_ti, _ctx);
  kk_std_time_utc__leaps_table_drop(kk_std_time_utc_leaps_table_ti, _ctx);
  kk_std_time_utc__leaps_table_drop(kk_std_time_utc_leaps_table_pre1972, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_utc_mjd_epoch_shift, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_utc_jd_epoch_shift, _ctx);
  kk_std_time_timestamp__timestamp_drop(kk_std_time_utc_utc1958, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_utc_ntp2000, _ctx);
  kk_std_time_utc__leap_adjust_drop(kk_std_time_utc_zero, _ctx);
  kk_std_core_hnd__htag_drop(kk_std_time_utc_utc_fs__tag, _ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
  kk_std_text_parse__done(_ctx);
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
