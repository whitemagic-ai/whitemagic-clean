// Koka generated module: std/time/utc, koka version: 3.2.2, platform: 64-bit
#include "std_time_utc.h"
 
// runtime tag for the effect `:utc`

kk_std_core_hnd__htag kk_std_time_utc_utc_fs__tag;
 
// handler for the effect `:utc`

kk_box_t kk_std_time_utc_utc_fs__handle(kk_std_time_utc__utc hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : utc<e,b>, ret : (res : a) -> e b, action : () -> <utc|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x1339 = kk_std_core_hnd__htag_dup(kk_std_time_utc_utc_fs__tag, _ctx); /*hnd/htag<std/time/utc/utc>*/
  return kk_std_core_hnd__hhandle(_x_x1339, kk_std_time_utc__utc_box(hnd, _ctx), ret, action, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_fs__copy(kk_std_time_utc__leaps_table _this, kk_std_core_types__optional expire, kk_std_core_types__optional adjusts, kk_context_t* _ctx) { /* (leaps-table, expire : ? std/time/instant/instant, adjusts : ? (list<leap-adjust>)) -> leaps-table */ 
  kk_std_time_instant__instant _x_x1342;
  if (kk_std_core_types__is_Optional(expire, _ctx)) {
    kk_box_t _box_x14 = expire._cons._Optional.value;
    kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x14, KK_BORROWED, _ctx);
    kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
    kk_std_core_types__optional_drop(expire, _ctx);
    _x_x1342 = _uniq_expire_375; /*std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(expire, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1343 = kk_std_time_utc__as_Leaps_table(_this, _ctx);
      kk_std_time_instant__instant _x = _con_x1343->expire;
      kk_std_time_instant__instant_dup(_x, _ctx);
      _x_x1342 = _x; /*std/time/instant/instant*/
    }
  }
  kk_std_core_types__list _x_x1344;
  if (kk_std_core_types__is_Optional(adjusts, _ctx)) {
    kk_box_t _box_x15 = adjusts._cons._Optional.value;
    kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x15, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
    kk_std_core_types__optional_drop(adjusts, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x1344 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
  }
  else {
    kk_std_core_types__optional_drop(adjusts, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1345 = kk_std_time_utc__as_Leaps_table(_this, _ctx);
      kk_std_time_instant__instant _pat_0_1 = _con_x1345->expire;
      kk_std_core_types__list _x_0 = _con_x1345->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1344 = _x_0; /*list<std/time/utc/leap-adjust>*/
    }
  }
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x1342, _x_x1344, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc_zero;

kk_std_time_utc__leap_adjust kk_std_time_utc_leap_adjust_fs__copy(kk_std_time_utc__leap_adjust _this, kk_std_core_types__optional utc_start, kk_std_core_types__optional offset, kk_std_core_types__optional drift_start, kk_std_core_types__optional drift, kk_context_t* _ctx) { /* (leap-adjust, utc-start : ? utc-timestamp, offset : ? std/time/timestamp/timespan, drift-start : ? utc-timestamp, drift : ? std/num/ddouble/ddouble) -> leap-adjust */ 
  kk_std_time_timestamp__timestamp _x_x1362;
  if (kk_std_core_types__is_Optional(utc_start, _ctx)) {
    kk_box_t _box_x18 = utc_start._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_utc_start_473 = kk_std_time_timestamp__timestamp_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_utc_start_473, _ctx);
    kk_std_core_types__optional_drop(utc_start, _ctx);
    _x_x1362 = _uniq_utc_start_473; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(utc_start, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1363 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _x = _con_x1363->utc_start;
      kk_std_num_ddouble__ddouble _pat_2 = _con_x1363->offset;
      kk_std_time_timestamp__timestamp _pat_5 = _con_x1363->drift_start;
      kk_std_num_ddouble__ddouble _pat_8 = _con_x1363->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1364 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1365 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x, _ctx);
      _x_x1362 = _x; /*std/time/utc/utc-timestamp*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1366;
  if (kk_std_core_types__is_Optional(offset, _ctx)) {
    kk_box_t _box_x19 = offset._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_offset_481 = kk_std_num_ddouble__ddouble_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(offset, _ctx);
    _x_x1366 = _uniq_offset_481; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(offset, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1367 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_1 = _con_x1367->utc_start;
      kk_std_num_ddouble__ddouble _x_0 = _con_x1367->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1367->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1367->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1368 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1369 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      _x_x1366 = _x_0; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_time_timestamp__timestamp _x_x1370;
  if (kk_std_core_types__is_Optional(drift_start, _ctx)) {
    kk_box_t _box_x20 = drift_start._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_489 = kk_std_time_timestamp__timestamp_unbox(_box_x20, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_489, _ctx);
    kk_std_core_types__optional_drop(drift_start, _ctx);
    _x_x1370 = _uniq_drift_start_489; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1371 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_2 = _con_x1371->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_2 = _con_x1371->offset;
      kk_std_time_timestamp__timestamp _x_1 = _con_x1371->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1371->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1372 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1373 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
      _x_x1370 = _x_1; /*std/time/utc/utc-timestamp*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1374;
  if (kk_std_core_types__is_Optional(drift, _ctx)) {
    kk_box_t _box_x21 = drift._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_497 = kk_std_num_ddouble__ddouble_unbox(_box_x21, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x1374 = _uniq_drift_497; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1375 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_3 = _con_x1375->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_3 = _con_x1375->offset;
      kk_std_time_timestamp__timestamp _pat_6_3 = _con_x1375->drift_start;
      kk_std_num_ddouble__ddouble _x_2 = _con_x1375->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1376 = kk_std_time_timestamp__as_Timestamp(_pat_0_3, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1377 = kk_std_time_timestamp__as_Timestamp(_pat_6_3, _ctx);
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
      _x_x1374 = _x_2; /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, _x_x1362, _x_x1366, _x_x1370, _x_x1374, _ctx);
}

bool kk_std_time_utc_is_zero(kk_std_time_utc__leap_adjust la, kk_context_t* _ctx) { /* (la : leap-adjust) -> bool */ 
  bool _match_x1094;
  double _x_x1378;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1379 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_0 = _con_x1379->utc_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x1379->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x1379->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1379->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1380 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1381 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    {
      double _x = _x_0.hi;
      _x_x1378 = _x; /*float64*/
    }
  }
  _match_x1094 = (_x_x1378 == (0x0p+0)); /*bool*/
  if (_match_x1094) {
    double _x_x1382;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1383 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_2 = _con_x1383->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_0 = _con_x1383->offset;
      kk_std_time_timestamp__timestamp _pat_6_0 = _con_x1383->drift_start;
      kk_std_num_ddouble__ddouble _x_2 = _con_x1383->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1384 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1385 = kk_std_time_timestamp__as_Timestamp(_pat_6_0, _ctx);
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
        _x_x1382 = _x_1; /*float64*/
      }
    }
    return (_x_x1382 == (0x0p+0));
  }
  {
    kk_datatype_ptr_dropn(la, (KK_I32(2)), _ctx);
    return false;
  }
}

kk_std_num_ddouble__ddouble kk_std_time_utc_ntp2000;

kk_std_time_timestamp__timestamp kk_std_time_utc_utc1958;

kk_std_time_utc__leap_adjust kk_std_time_utc__unroll_find_leap_adjust_10000(kk_std_time_timestamp__timestamp utc_0, kk_std_core_types__list leaps, kk_context_t* _ctx) { /* (utc : utc-timestamp, leaps : list<leap-adjust>) -> leap-adjust */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(leaps, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    return kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1395 = kk_std_core_types__as_Cons(leaps, _ctx);
    kk_box_t _box_x26 = _con_x1395->head;
    kk_std_time_utc__leap_adjust la = kk_std_time_utc__leap_adjust_unbox(_box_x26, KK_BORROWED, _ctx);
    struct kk_std_time_utc_Leap_adjust* _con_x1396 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_core_types__list earlier = _con_x1395->tail;
    kk_std_time_timestamp__timestamp _pat_1 = _con_x1396->utc_start;
    kk_std_time_timestamp__timestamp _pat_3 = _con_x1396->drift_start;
    if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
      kk_datatype_ptr_free(leaps, _ctx);
    }
    else {
      kk_std_core_types__list_dup(earlier, _ctx);
      kk_std_time_utc__leap_adjust_dup(la, _ctx);
      kk_datatype_ptr_decref(leaps, _ctx);
    }
    kk_std_core_types__order x_10022;
    kk_std_core_types__order _match_x1084;
    kk_std_core_types__order _match_x1088;
    double _x_x1397;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1398 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _x_7 = _con_x1398->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_1 = _con_x1398->offset;
      kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x1398->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1398->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1399 = kk_std_time_timestamp__as_Timestamp(_x_7, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1400 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_7, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1401 = kk_std_time_timestamp__as_Timestamp(_x_7, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x1401->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_7, _ctx)) {
          kk_datatype_ptr_free(_x_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_7, _ctx);
        }
        {
          double _x = _x_3.hi;
          _x_x1397 = _x; /*float64*/
        }
      }
    }
    double _x_x1402;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1403 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
      kk_std_num_ddouble__ddouble _x_4 = _con_x1403->since;
      {
        double _x_0 = _x_4.hi;
        _x_x1402 = _x_0; /*float64*/
      }
    }
    _match_x1088 = kk_std_num_float64_cmp(_x_x1397, _x_x1402, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x1088, _ctx)) {
      double _x_x1404;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1405 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
        kk_std_time_timestamp__timestamp _x_7_0 = _con_x1405->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_0_1_0 = _con_x1405->offset;
        kk_std_time_timestamp__timestamp _pat_5_0_0_0 = _con_x1405->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1405->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1406 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1407 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_7_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1408 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x1408->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_7_0, _ctx)) {
            kk_datatype_ptr_free(_x_7_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_7_0, _ctx);
          }
          {
            double _x_1 = _x_3_0.lo;
            _x_x1404 = _x_1; /*float64*/
          }
        }
      }
      double _x_x1409;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1410 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x1410->since;
        {
          double _x_2 = _x_4_0.lo;
          _x_x1409 = _x_2; /*float64*/
        }
      }
      _match_x1084 = kk_std_num_float64_cmp(_x_x1404, _x_x1409, _ctx); /*order*/
    }
    else {
      _match_x1084 = _match_x1088; /*order*/
    }
    if (kk_std_core_types__is_Eq(_match_x1084, _ctx)) {
      kk_integer_t x_0_10008;
      int32_t _x_x1411;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1412 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
        kk_std_time_timestamp__timestamp _x_7_1 = _con_x1412->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_0_1_1 = _con_x1412->offset;
        kk_std_time_timestamp__timestamp _pat_5_0_0_1 = _con_x1412->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_1 = _con_x1412->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1413 = kk_std_time_timestamp__as_Timestamp(_x_7_1, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1414 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_7_1, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1415 = kk_std_time_timestamp__as_Timestamp(_x_7_1, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_6 = _con_x1415->since;
          int32_t _x_5 = _con_x1415->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_7_1, _ctx)) {
            kk_datatype_ptr_free(_x_7_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_7_1, _ctx);
          }
          _x_x1411 = _x_5; /*int32*/
        }
      }
      x_0_10008 = kk_integer_from_int(_x_x1411,kk_context()); /*int*/
      kk_integer_t y_0_10009;
      int32_t _x_x1416;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1417 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_7 = _con_x1417->since;
        int32_t _x_6 = _con_x1417->leap32;
        _x_x1416 = _x_6; /*int32*/
      }
      y_0_10009 = kk_integer_from_int(_x_x1416,kk_context()); /*int*/
      bool _match_x1085 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      if (_match_x1085) {
        kk_integer_drop(y_0_10009, _ctx);
        kk_integer_drop(x_0_10008, _ctx);
        x_10022 = kk_std_core_types__new_Eq(_ctx); /*order*/
      }
      else {
        bool _match_x1086;
        bool _brw_x1087 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
        kk_integer_drop(x_0_10008, _ctx);
        kk_integer_drop(y_0_10009, _ctx);
        _match_x1086 = _brw_x1087; /*bool*/
        if (_match_x1086) {
          x_10022 = kk_std_core_types__new_Gt(_ctx); /*order*/
        }
        else {
          x_10022 = kk_std_core_types__new_Lt(_ctx); /*order*/
        }
      }
    }
    else {
      x_10022 = _match_x1084; /*order*/
    }
    bool _match_x1081;
    kk_integer_t _brw_x1082;
    if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
      _brw_x1082 = kk_integer_from_small(-1); /*int*/
      goto _match_x1418;
    }
    if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
      _brw_x1082 = kk_integer_from_small(0); /*int*/
      goto _match_x1418;
    }
    {
      _brw_x1082 = kk_integer_from_small(1); /*int*/
    }
    _match_x1418: ;
    bool _brw_x1083 = kk_integer_eq_borrow(_brw_x1082,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1082, _ctx);
    _match_x1081 = _brw_x1083; /*bool*/
    if (_match_x1081) {
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
  kk_std_core_types__order x_10016;
  kk_std_time_timestamp__timestamp _x_x1419 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
  kk_std_time_timestamp__timestamp _x_x1420 = kk_std_time_timestamp__timestamp_dup(kk_std_time_utc_utc1958, _ctx); /*std/time/timestamp/timestamp*/
  x_10016 = kk_std_time_timestamp_cmp(_x_x1419, _x_x1420, _ctx); /*order*/
  bool _match_x1078;
  kk_integer_t _brw_x1079;
  if (kk_std_core_types__is_Lt(x_10016, _ctx)) {
    _brw_x1079 = kk_integer_from_small(-1); /*int*/
    goto _match_x1421;
  }
  if (kk_std_core_types__is_Eq(x_10016, _ctx)) {
    _brw_x1079 = kk_integer_from_small(0); /*int*/
    goto _match_x1421;
  }
  {
    _brw_x1079 = kk_integer_from_small(1); /*int*/
  }
  _match_x1421: ;
  bool _brw_x1080 = kk_integer_eq_borrow(_brw_x1079,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1079, _ctx);
  _match_x1078 = _brw_x1080; /*bool*/
  if (_match_x1078) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    return kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx);
  }
  {
    struct kk_std_time_utc_Leaps_table* _con_x1422 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
    kk_std_time_instant__instant _pat_0_1 = _con_x1422->expire;
    kk_std_core_types__list _x = _con_x1422->adjusts;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(leaps, _ctx);
      }
      else {
        kk_datatype_ptr_decref(leaps, _ctx);
      }
      return kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx);
    }
    {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x1423;
      {
        struct kk_std_time_utc_Leaps_table* _con_x1424 = kk_std_time_utc__as_Leaps_table(leaps, _ctx);
        kk_std_time_instant__instant _pat_0_1_0 = _con_x1424->expire;
        kk_std_core_types__list _x_0 = _con_x1424->adjusts;
        if kk_likely(kk_datatype_ptr_is_unique(leaps, _ctx)) {
          kk_std_time_instant__instant_drop(_pat_0_1_0, _ctx);
          kk_datatype_ptr_free(leaps, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(leaps, _ctx);
        }
        _x_x1423 = _x_0; /*list<std/time/utc/leap-adjust>*/
      }
      return kk_std_time_utc__unroll_find_leap_adjust_10000(utc_0, _x_x1423, _ctx);
    }
  }
}
 
// Get the leap-second adjustment _delta-tai_ (= TAI - UTC).
// Needs the timestamp to handle _drift_.

kk_std_num_ddouble__ddouble kk_std_time_utc_delta_tai(kk_std_time_utc__leap_adjust la, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (la : leap-adjust, utc : utc-timestamp) -> std/time/timestamp/timespan */ 
  bool _match_x1077;
  double _x_x1425;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1426 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_0 = _con_x1426->utc_start;
    kk_std_num_ddouble__ddouble _pat_3 = _con_x1426->offset;
    kk_std_time_timestamp__timestamp _pat_6 = _con_x1426->drift_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x1426->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1427 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1428 = kk_std_time_timestamp__as_Timestamp(_pat_6, _ctx);
    {
      double _x = _x_0.hi;
      _x_x1425 = _x; /*float64*/
    }
  }
  _match_x1077 = (_x_x1425 == (0x0p+0)); /*bool*/
  if (_match_x1077) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1429 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_1 = _con_x1429->utc_start;
      kk_std_num_ddouble__ddouble _x_1 = _con_x1429->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1429->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1429->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1430 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1431 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
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
    kk_std_num_ddouble__ddouble _x_x1432;
    kk_std_num_ddouble__ddouble _x_x1433;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1434 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
      kk_std_num_ddouble__ddouble _x_3 = _con_x1434->since;
      if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
        kk_datatype_ptr_free(utc_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(utc_0, _ctx);
      }
      _x_x1433 = _x_3; /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble _x_x1435;
    double _x_x1436;
    double _x_x1437;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1438 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6 = _con_x1438->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1 = _con_x1438->offset;
      kk_std_time_timestamp__timestamp _x_5 = _con_x1438->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1438->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1439 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1440 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_5, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1441 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
        kk_std_num_ddouble__ddouble _x_4 = _con_x1441->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
          kk_datatype_ptr_free(_x_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_5, _ctx);
        }
        {
          double _x_2 = _x_4.hi;
          _x_x1437 = _x_2; /*float64*/
        }
      }
    }
    _x_x1436 = (-_x_x1437); /*float64*/
    double _x_x1442;
    double _x_x1443;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1444 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6_0 = _con_x1444->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1_0 = _con_x1444->offset;
      kk_std_time_timestamp__timestamp _x_5_0 = _con_x1444->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1_0 = _con_x1444->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1445 = kk_std_time_timestamp__as_Timestamp(_pat_0_6_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1446 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_5_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1447 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x1447->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5_0, _ctx)) {
          kk_datatype_ptr_free(_x_5_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_5_0, _ctx);
        }
        {
          double _x_0_0 = _x_4_0.lo;
          _x_x1443 = _x_0_0; /*float64*/
        }
      }
    }
    _x_x1442 = (-_x_x1443); /*float64*/
    _x_x1435 = kk_std_num_ddouble__new_Ddouble(_x_x1436, _x_x1442, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1432 = kk_std_num_ddouble__lp__plus__rp_(_x_x1433, _x_x1435, _ctx); /*std/num/ddouble/ddouble*/
    days = kk_std_num_ddouble__lp__fs__rp_(_x_x1432, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1448;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1449 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_7 = _con_x1449->utc_start;
      kk_std_num_ddouble__ddouble _x_6 = _con_x1449->offset;
      kk_std_time_timestamp__timestamp _pat_5_2 = _con_x1449->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_2 = _con_x1449->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1450 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1451 = kk_std_time_timestamp__as_Timestamp(_pat_5_2, _ctx);
      _x_x1448 = _x_6; /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble _x_x1452;
    kk_std_num_ddouble__ddouble _x_x1453;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1454 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_8 = _con_x1454->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_3 = _con_x1454->offset;
      kk_std_time_timestamp__timestamp _pat_6_3 = _con_x1454->drift_start;
      kk_std_num_ddouble__ddouble _x_7 = _con_x1454->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1455 = kk_std_time_timestamp__as_Timestamp(_pat_0_8, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1456 = kk_std_time_timestamp__as_Timestamp(_pat_6_3, _ctx);
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
      _x_x1453 = _x_7; /*std/num/ddouble/ddouble*/
    }
    _x_x1452 = kk_std_num_ddouble__lp__star__rp_(_x_x1453, days, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x_x1448, _x_x1452, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_to_delta_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : utc-timestamp) -> std/time/timestamp/timespan */ 
  kk_std_time_utc__leap_adjust la_10038;
  kk_std_time_timestamp__timestamp _x_x1457 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
  la_10038 = kk_std_time_utc_utc_to_leap_adjust(leaps, _x_x1457, _ctx); /*std/time/utc/leap-adjust*/
  bool _match_x1076;
  double _x_x1458;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1459 = kk_std_time_utc__as_Leap_adjust(la_10038, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_0 = _con_x1459->utc_start;
    kk_std_num_ddouble__ddouble _pat_3 = _con_x1459->offset;
    kk_std_time_timestamp__timestamp _pat_6 = _con_x1459->drift_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x1459->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1460 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1461 = kk_std_time_timestamp__as_Timestamp(_pat_6, _ctx);
    {
      double _x = _x_0.hi;
      _x_x1458 = _x; /*float64*/
    }
  }
  _match_x1076 = (_x_x1458 == (0x0p+0)); /*bool*/
  if (_match_x1076) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1462 = kk_std_time_utc__as_Leap_adjust(la_10038, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_1 = _con_x1462->utc_start;
      kk_std_num_ddouble__ddouble _x_1 = _con_x1462->offset;
      kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1462->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1462->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1463 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1464 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la_10038, _ctx)) {
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
        kk_datatype_ptr_free(la_10038, _ctx);
      }
      else {
        kk_datatype_ptr_decref(la_10038, _ctx);
      }
      return _x_1;
    }
  }
  {
    kk_std_num_ddouble__ddouble days;
    kk_std_num_ddouble__ddouble _x_x1465;
    kk_std_num_ddouble__ddouble _x_x1466;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1467 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
      kk_std_num_ddouble__ddouble _x_3 = _con_x1467->since;
      if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
        kk_datatype_ptr_free(utc_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(utc_0, _ctx);
      }
      _x_x1466 = _x_3; /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble _x_x1468;
    double _x_x1469;
    double _x_x1470;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1471 = kk_std_time_utc__as_Leap_adjust(la_10038, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6 = _con_x1471->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1 = _con_x1471->offset;
      kk_std_time_timestamp__timestamp _x_5 = _con_x1471->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1471->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1472 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1473 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_5, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1474 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
        kk_std_num_ddouble__ddouble _x_4 = _con_x1474->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
          kk_datatype_ptr_free(_x_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_5, _ctx);
        }
        {
          double _x_2 = _x_4.hi;
          _x_x1470 = _x_2; /*float64*/
        }
      }
    }
    _x_x1469 = (-_x_x1470); /*float64*/
    double _x_x1475;
    double _x_x1476;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1477 = kk_std_time_utc__as_Leap_adjust(la_10038, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6_0 = _con_x1477->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1_0 = _con_x1477->offset;
      kk_std_time_timestamp__timestamp _x_5_0 = _con_x1477->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_1_0 = _con_x1477->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1478 = kk_std_time_timestamp__as_Timestamp(_pat_0_6_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1479 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_5_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1480 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x1480->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5_0, _ctx)) {
          kk_datatype_ptr_free(_x_5_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_5_0, _ctx);
        }
        {
          double _x_0_0 = _x_4_0.lo;
          _x_x1476 = _x_0_0; /*float64*/
        }
      }
    }
    _x_x1475 = (-_x_x1476); /*float64*/
    _x_x1468 = kk_std_num_ddouble__new_Ddouble(_x_x1469, _x_x1475, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1465 = kk_std_num_ddouble__lp__plus__rp_(_x_x1466, _x_x1468, _ctx); /*std/num/ddouble/ddouble*/
    days = kk_std_num_ddouble__lp__fs__rp_(_x_x1465, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1481;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1482 = kk_std_time_utc__as_Leap_adjust(la_10038, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_7 = _con_x1482->utc_start;
      kk_std_num_ddouble__ddouble _x_6 = _con_x1482->offset;
      kk_std_time_timestamp__timestamp _pat_5_2 = _con_x1482->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_2 = _con_x1482->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1483 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1484 = kk_std_time_timestamp__as_Timestamp(_pat_5_2, _ctx);
      _x_x1481 = _x_6; /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble _x_x1485;
    kk_std_num_ddouble__ddouble _x_x1486;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1487 = kk_std_time_utc__as_Leap_adjust(la_10038, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_8 = _con_x1487->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_3 = _con_x1487->offset;
      kk_std_time_timestamp__timestamp _pat_6_3 = _con_x1487->drift_start;
      kk_std_num_ddouble__ddouble _x_7 = _con_x1487->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1488 = kk_std_time_timestamp__as_Timestamp(_pat_0_8, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1489 = kk_std_time_timestamp__as_Timestamp(_pat_6_3, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la_10038, _ctx)) {
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
        kk_datatype_ptr_free(la_10038, _ctx);
      }
      else {
        kk_datatype_ptr_decref(la_10038, _ctx);
      }
      _x_x1486 = _x_7; /*std/num/ddouble/ddouble*/
    }
    _x_x1485 = kk_std_num_ddouble__lp__star__rp_(_x_x1486, days, _ctx); /*std/num/ddouble/ddouble*/
    return kk_std_num_ddouble__lp__plus__rp_(_x_x1481, _x_x1485, _ctx);
  }
}

kk_std_time_duration__duration kk_std_time_utc_utc_to_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : std/time/timestamp/timestamp) -> std/time/duration/duration */ 
  kk_std_num_ddouble__ddouble dtai;
  kk_std_time_timestamp__timestamp _x_x1490 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
  dtai = kk_std_time_utc_utc_to_delta_tai(leaps, _x_x1490, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp t_10050;
  kk_std_num_ddouble__ddouble _x_x1491;
  kk_std_num_ddouble__ddouble _x_x1492;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1493 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x1493->since;
    _x_x1492 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x1491 = kk_std_num_ddouble__lp__plus__rp_(_x_x1492, dtai, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1494;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1495 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x1495->since;
    int32_t _x_0 = _con_x1495->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
      kk_datatype_ptr_free(utc_0, _ctx);
    }
    else {
      kk_datatype_ptr_decref(utc_0, _ctx);
    }
    _x_x1494 = _x_0; /*int32*/
  }
  t_10050 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1491, _x_x1494, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x1496 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10050, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x1496, _ctx);
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
  kk_std_num_ddouble__ddouble _x_x1497;
  {
    kk_std_num_ddouble__ddouble _x = tai_since.secs;
    _x_x1497 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1498;
  kk_integer_t _x_x1499;
  kk_std_core_types__optional _match_x1075 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1075, _ctx)) {
    kk_box_t _box_x27 = _match_x1075._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x27, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x1075, _ctx);
    _x_x1499 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1075, _ctx);
    _x_x1499 = kk_integer_from_small(0); /*int*/
  }
  _x_x1498 = kk_integer_clamp32(_x_x1499,kk_context()); /*int32*/
  tai = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1497, _x_x1498, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble dtai0;
  kk_std_time_utc__leaps_table _x_x1500 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  kk_std_time_timestamp__timestamp _x_x1501 = kk_std_time_timestamp__timestamp_dup(tai, _ctx); /*std/time/timestamp/timestamp*/
  dtai0 = kk_std_time_utc_utc_to_delta_tai(_x_x1500, _x_x1501, _ctx); /*std/time/timestamp/timespan*/
  kk_std_time_timestamp__timestamp utc0 = kk_std_time_timestamp__lp__dash__rp_(tai, dtai0, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_num_ddouble__ddouble dtai1;
  kk_std_time_utc__leaps_table _x_x1502 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  kk_std_time_timestamp__timestamp _x_x1503 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
  dtai1 = kk_std_time_utc_utc_to_delta_tai(_x_x1502, _x_x1503, _ctx); /*std/time/timestamp/timespan*/
  kk_std_num_ddouble__ddouble diff;
  kk_std_num_ddouble__ddouble _x_x1504;
  double _x_x1505;
  double _x_x1506;
  {
    double _x_0 = dtai1.hi;
    _x_x1506 = _x_0; /*float64*/
  }
  _x_x1505 = (-_x_x1506); /*float64*/
  double _x_x1507;
  double _x_x1508;
  {
    double _x_0_0 = dtai1.lo;
    _x_x1508 = _x_0_0; /*float64*/
  }
  _x_x1507 = (-_x_x1508); /*float64*/
  _x_x1504 = kk_std_num_ddouble__new_Ddouble(_x_x1505, _x_x1507, _ctx); /*std/num/ddouble/ddouble*/
  diff = kk_std_num_ddouble__lp__plus__rp_(dtai0, _x_x1504, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble x_0_10056;
  bool _match_x1069 = kk_integer_lte_borrow((kk_integer_from_small(3)),(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1069) {
    x_0_10056 = kk_std_num_ddouble_round(diff, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    bool _match_x1070 = kk_integer_gt_borrow((kk_integer_from_small(3)),(kk_integer_from_small(31)),kk_context()); /*bool*/;
    if (_match_x1070) {
      x_0_10056 = diff; /*std/num/ddouble/ddouble*/
    }
    else {
      kk_integer_t n_0_10105 = kk_integer_abs((kk_integer_from_small(3)),kk_context()); /*int*/;
      kk_std_num_ddouble__ddouble p;
      bool _match_x1072 = kk_integer_eq_borrow(n_0_10105,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x1072) {
        kk_integer_drop(n_0_10105, _ctx);
        bool _match_x1074;
        double _x_x1509;
        kk_std_num_ddouble__ddouble _x_x1510 = kk_std_num_ddouble_ten; /*std/num/ddouble/ddouble*/
        {
          double _x_1 = _x_x1510.hi;
          _x_x1509 = _x_1; /*float64*/
        }
        _match_x1074 = (_x_x1509 == (0x0p+0)); /*bool*/
        if (_match_x1074) {
          p = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
        }
        else {
          p = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
        }
      }
      else {
        bool _match_x1073 = kk_integer_eq_borrow(n_0_10105,(kk_integer_from_small(1)),kk_context()); /*bool*/;
        if (_match_x1073) {
          kk_integer_drop(n_0_10105, _ctx);
          p = kk_std_num_ddouble_ten; /*std/num/ddouble/ddouble*/
        }
        else {
          p = kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble_ten, kk_std_num_ddouble_one, n_0_10105, _ctx); /*std/num/ddouble/ddouble*/
        }
      }
      kk_std_num_ddouble__ddouble p_0;
      bool _match_x1071 = kk_integer_lt_borrow((kk_integer_from_small(3)),(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x1071) {
        p_0 = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, p, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        p_0 = p; /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x1511;
      kk_std_num_ddouble__ddouble _x_x1512 = kk_std_num_ddouble__lp__star__rp_(diff, p_0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1511 = kk_std_num_ddouble_round(_x_x1512, _ctx); /*std/num/ddouble/ddouble*/
      x_0_10056 = kk_std_num_ddouble__lp__fs__rp_(_x_x1511, p_0, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  bool hasgap;
  double _x_x1513;
  {
    double _x_1_0 = x_0_10056.hi;
    _x_x1513 = _x_1_0; /*float64*/
  }
  hasgap = (_x_x1513 > (0x0p+0)); /*bool*/
  bool inleap;
  if (hasgap) {
    kk_std_time_timestamp__timestamp utc_0_10062;
    kk_std_num_ddouble__ddouble _x_x1514;
    kk_std_num_ddouble__ddouble _x_x1515;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1516 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _x_12 = _con_x1516->since;
      _x_x1515 = _x_12; /*std/time/timestamp/timespan*/
    }
    _x_x1514 = kk_std_num_ddouble__lp__plus__rp_(_x_x1515, diff, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x1517;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1518 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_3 = _con_x1518->since;
      int32_t _x_0_3 = _con_x1518->leap32;
      _x_x1517 = _x_0_3; /*int32*/
    }
    utc_0_10062 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1514, _x_x1517, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_utc__leap_adjust la_10065;
    kk_std_time_timestamp__timestamp _x_x1519 = kk_std_time_timestamp__timestamp_dup(utc_0_10062, _ctx); /*std/time/utc/utc-timestamp*/
    la_10065 = kk_std_time_utc_utc_to_leap_adjust(leaps, _x_x1519, _ctx); /*std/time/utc/leap-adjust*/
    kk_std_num_ddouble__ddouble x_2_10059;
    bool _match_x1068;
    double _x_x1520;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1521 = kk_std_time_utc__as_Leap_adjust(la_10065, _ctx);
      kk_std_time_timestamp__timestamp _pat_0_6 = _con_x1521->utc_start;
      kk_std_num_ddouble__ddouble _pat_3_1_0 = _con_x1521->offset;
      kk_std_time_timestamp__timestamp _pat_6_0 = _con_x1521->drift_start;
      kk_std_num_ddouble__ddouble _x_4 = _con_x1521->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1522 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1523 = kk_std_time_timestamp__as_Timestamp(_pat_6_0, _ctx);
      {
        double _x_3 = _x_4.hi;
        _x_x1520 = _x_3; /*float64*/
      }
    }
    _match_x1068 = (_x_x1520 == (0x0p+0)); /*bool*/
    if (_match_x1068) {
      kk_std_time_timestamp__timestamp_drop(utc_0_10062, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1524 = kk_std_time_utc__as_Leap_adjust(la_10065, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_7 = _con_x1524->utc_start;
        kk_std_num_ddouble__ddouble _x_5 = _con_x1524->offset;
        kk_std_time_timestamp__timestamp _pat_5_2 = _con_x1524->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1524->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1525 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1526 = kk_std_time_timestamp__as_Timestamp(_pat_5_2, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(la_10065, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_2, _ctx)) {
            kk_datatype_ptr_free(_pat_5_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_2, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_7, _ctx)) {
            kk_datatype_ptr_free(_pat_0_7, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_7, _ctx);
          }
          kk_datatype_ptr_free(la_10065, _ctx);
        }
        else {
          kk_datatype_ptr_decref(la_10065, _ctx);
        }
        x_2_10059 = _x_5; /*std/time/timestamp/timespan*/
      }
    }
    else {
      kk_std_num_ddouble__ddouble days;
      kk_std_num_ddouble__ddouble _x_x1527;
      kk_std_num_ddouble__ddouble _x_x1528;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1529 = kk_std_time_timestamp__as_Timestamp(utc_0_10062, _ctx);
        kk_std_num_ddouble__ddouble _x_7 = _con_x1529->since;
        if kk_likely(kk_datatype_ptr_is_unique(utc_0_10062, _ctx)) {
          kk_datatype_ptr_free(utc_0_10062, _ctx);
        }
        else {
          kk_datatype_ptr_decref(utc_0_10062, _ctx);
        }
        _x_x1528 = _x_7; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1530;
      double _x_x1531;
      double _x_x1532;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1533 = kk_std_time_utc__as_Leap_adjust(la_10065, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_12 = _con_x1533->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_3 = _con_x1533->offset;
        kk_std_time_timestamp__timestamp _x_9 = _con_x1533->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_2 = _con_x1533->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1534 = kk_std_time_timestamp__as_Timestamp(_pat_0_12, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1535 = kk_std_time_timestamp__as_Timestamp(_x_9, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_9, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1536 = kk_std_time_timestamp__as_Timestamp(_x_9, _ctx);
          kk_std_num_ddouble__ddouble _x_8 = _con_x1536->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
            kk_datatype_ptr_free(_x_9, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_9, _ctx);
          }
          {
            double _x_6 = _x_8.hi;
            _x_x1532 = _x_6; /*float64*/
          }
        }
      }
      _x_x1531 = (-_x_x1532); /*float64*/
      double _x_x1537;
      double _x_x1538;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1539 = kk_std_time_utc__as_Leap_adjust(la_10065, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_12_0 = _con_x1539->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_3_0 = _con_x1539->offset;
        kk_std_time_timestamp__timestamp _x_9_0 = _con_x1539->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_2_0 = _con_x1539->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1540 = kk_std_time_timestamp__as_Timestamp(_pat_0_12_0, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1541 = kk_std_time_timestamp__as_Timestamp(_x_9_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_9_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1542 = kk_std_time_timestamp__as_Timestamp(_x_9_0, _ctx);
          kk_std_num_ddouble__ddouble _x_8_0 = _con_x1542->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9_0, _ctx)) {
            kk_datatype_ptr_free(_x_9_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_9_0, _ctx);
          }
          {
            double _x_0_2 = _x_8_0.lo;
            _x_x1538 = _x_0_2; /*float64*/
          }
        }
      }
      _x_x1537 = (-_x_x1538); /*float64*/
      _x_x1530 = kk_std_num_ddouble__new_Ddouble(_x_x1531, _x_x1537, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1527 = kk_std_num_ddouble__lp__plus__rp_(_x_x1528, _x_x1530, _ctx); /*std/num/ddouble/ddouble*/
      days = kk_std_num_ddouble__lp__fs__rp_(_x_x1527, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1543;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1544 = kk_std_time_utc__as_Leap_adjust(la_10065, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_13 = _con_x1544->utc_start;
        kk_std_num_ddouble__ddouble _x_10 = _con_x1544->offset;
        kk_std_time_timestamp__timestamp _pat_5_4 = _con_x1544->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_3 = _con_x1544->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1545 = kk_std_time_timestamp__as_Timestamp(_pat_0_13, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1546 = kk_std_time_timestamp__as_Timestamp(_pat_5_4, _ctx);
        _x_x1543 = _x_10; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1547;
      kk_std_num_ddouble__ddouble _x_x1548;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1549 = kk_std_time_utc__as_Leap_adjust(la_10065, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_14 = _con_x1549->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_5 = _con_x1549->offset;
        kk_std_time_timestamp__timestamp _pat_6_4 = _con_x1549->drift_start;
        kk_std_num_ddouble__ddouble _x_11 = _con_x1549->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1550 = kk_std_time_timestamp__as_Timestamp(_pat_0_14, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1551 = kk_std_time_timestamp__as_Timestamp(_pat_6_4, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(la_10065, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_6_4, _ctx)) {
            kk_datatype_ptr_free(_pat_6_4, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_6_4, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_14, _ctx)) {
            kk_datatype_ptr_free(_pat_0_14, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_14, _ctx);
          }
          kk_datatype_ptr_free(la_10065, _ctx);
        }
        else {
          kk_datatype_ptr_decref(la_10065, _ctx);
        }
        _x_x1548 = _x_11; /*std/num/ddouble/ddouble*/
      }
      _x_x1547 = kk_std_num_ddouble__lp__star__rp_(_x_x1548, days, _ctx); /*std/num/ddouble/ddouble*/
      x_2_10059 = kk_std_num_ddouble__lp__plus__rp_(_x_x1543, _x_x1547, _ctx); /*std/time/timestamp/timespan*/
    }
    kk_std_core_types__order x_0_10006;
    kk_std_core_types__order _match_x1067;
    double _x_x1552;
    {
      double _x_2 = x_2_10059.hi;
      _x_x1552 = _x_2; /*float64*/
    }
    double _x_x1553;
    {
      double _x_0_1 = dtai1.hi;
      _x_x1553 = _x_0_1; /*float64*/
    }
    _match_x1067 = kk_std_num_float64_cmp(_x_x1552, _x_x1553, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x1067, _ctx)) {
      double _x_x1554;
      {
        double _x_1_0_0 = x_2_10059.lo;
        _x_x1554 = _x_1_0_0; /*float64*/
      }
      double _x_x1555;
      {
        double _x_2_0 = dtai1.lo;
        _x_x1555 = _x_2_0; /*float64*/
      }
      x_0_10006 = kk_std_num_float64_cmp(_x_x1554, _x_x1555, _ctx); /*order*/
    }
    else {
      x_0_10006 = _match_x1067; /*order*/
    }
    kk_integer_t _brw_x1065;
    if (kk_std_core_types__is_Lt(x_0_10006, _ctx)) {
      _brw_x1065 = kk_integer_from_small(-1); /*int*/
      goto _match_x1556;
    }
    if (kk_std_core_types__is_Eq(x_0_10006, _ctx)) {
      _brw_x1065 = kk_integer_from_small(0); /*int*/
      goto _match_x1556;
    }
    {
      _brw_x1065 = kk_integer_from_small(1); /*int*/
    }
    _match_x1556: ;
    bool _brw_x1066 = kk_integer_neq_borrow(_brw_x1065,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1065, _ctx);
    inleap = _brw_x1066; /*bool*/
  }
  else {
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    inleap = false; /*bool*/
  }
  if (inleap) {
    return kk_std_time_timestamp_add_leap_seconds(utc0, diff, _ctx);
  }
  {
    kk_std_num_ddouble__ddouble _x_x1557;
    kk_std_num_ddouble__ddouble _x_x1558;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1559 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _x_13 = _con_x1559->since;
      _x_x1558 = _x_13; /*std/time/timestamp/timespan*/
    }
    _x_x1557 = kk_std_num_ddouble__lp__plus__rp_(_x_x1558, diff, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x1560;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1561 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_4 = _con_x1561->since;
      int32_t _x_0_4 = _con_x1561->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(utc0, _ctx)) {
        kk_datatype_ptr_free(utc0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(utc0, _ctx);
      }
      _x_x1560 = _x_0_4; /*int32*/
    }
    return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1557, _x_x1560, _ctx);
  }
}
 
// Return `Just(start,diff)` if a leap second occurred in the given day
// (`days` after 2000-01-01) with the start time and leap second gap (`diff`)

kk_std_core_types__maybe kk_std_time_utc_utc_leap_in_day(kk_std_time_utc__leaps_table leaps, kk_integer_t days, kk_context_t* _ctx) { /* (leaps : leaps-table, days : int) -> maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)> */ 
  kk_std_time_timestamp__timestamp utc0;
  kk_integer_t _x_x1562 = kk_integer_dup(days, _ctx); /*int*/
  utc0 = kk_std_time_timestamp_timestamp_days(_x_x1562, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp utc1;
  kk_integer_t _x_x1563 = kk_integer_add_small_const(days, 1, _ctx); /*int*/
  utc1 = kk_std_time_timestamp_timestamp_days(_x_x1563, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_utc__leap_adjust la1;
  kk_std_time_utc__leaps_table _x_x1564 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  kk_std_time_timestamp__timestamp _x_x1565 = kk_std_time_timestamp__timestamp_dup(utc1, _ctx); /*std/time/timestamp/timestamp*/
  la1 = kk_std_time_utc_utc_to_leap_adjust(_x_x1564, _x_x1565, _ctx); /*std/time/utc/leap-adjust*/
  kk_std_core_types__order x_10016;
  kk_std_core_types__order _match_x1060;
  kk_std_core_types__order _match_x1064;
  double _x_x1566;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1567 = kk_std_time_utc__as_Leap_adjust(la1, _ctx);
    kk_std_time_timestamp__timestamp _x_7 = _con_x1567->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_0_1 = _con_x1567->offset;
    kk_std_time_timestamp__timestamp _pat_5_1 = _con_x1567->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1567->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1568 = kk_std_time_timestamp__as_Timestamp(_x_7, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1569 = kk_std_time_timestamp__as_Timestamp(_pat_5_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_7, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1570 = kk_std_time_timestamp__as_Timestamp(_x_7, _ctx);
      kk_std_num_ddouble__ddouble _x_3 = _con_x1570->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_7, _ctx)) {
        kk_datatype_ptr_free(_x_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_7, _ctx);
      }
      {
        double _x = _x_3.hi;
        _x_x1566 = _x; /*float64*/
      }
    }
  }
  double _x_x1571;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1572 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
    kk_std_num_ddouble__ddouble _x_4 = _con_x1572->since;
    {
      double _x_0 = _x_4.hi;
      _x_x1571 = _x_0; /*float64*/
    }
  }
  _match_x1064 = kk_std_num_float64_cmp(_x_x1566, _x_x1571, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x1064, _ctx)) {
    double _x_x1573;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1574 = kk_std_time_utc__as_Leap_adjust(la1, _ctx);
      kk_std_time_timestamp__timestamp _x_7_0 = _con_x1574->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_1_0 = _con_x1574->offset;
      kk_std_time_timestamp__timestamp _pat_5_1_0 = _con_x1574->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1574->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1575 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1576 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_7_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1577 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
        kk_std_num_ddouble__ddouble _x_3_0 = _con_x1577->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_7_0, _ctx)) {
          kk_datatype_ptr_free(_x_7_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_7_0, _ctx);
        }
        {
          double _x_1 = _x_3_0.lo;
          _x_x1573 = _x_1; /*float64*/
        }
      }
    }
    double _x_x1578;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1579 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _x_4_0 = _con_x1579->since;
      {
        double _x_2 = _x_4_0.lo;
        _x_x1578 = _x_2; /*float64*/
      }
    }
    _match_x1060 = kk_std_num_float64_cmp(_x_x1573, _x_x1578, _ctx); /*order*/
  }
  else {
    _match_x1060 = _match_x1064; /*order*/
  }
  if (kk_std_core_types__is_Eq(_match_x1060, _ctx)) {
    kk_integer_t x_0_10008;
    int32_t _x_x1580;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1581 = kk_std_time_utc__as_Leap_adjust(la1, _ctx);
      kk_std_time_timestamp__timestamp _x_7_1 = _con_x1581->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_1_1 = _con_x1581->offset;
      kk_std_time_timestamp__timestamp _pat_5_1_1 = _con_x1581->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0_1 = _con_x1581->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1582 = kk_std_time_timestamp__as_Timestamp(_x_7_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1583 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_7_1, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1584 = kk_std_time_timestamp__as_Timestamp(_x_7_1, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_6 = _con_x1584->since;
        int32_t _x_5 = _con_x1584->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_7_1, _ctx)) {
          kk_datatype_ptr_free(_x_7_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_7_1, _ctx);
        }
        _x_x1580 = _x_5; /*int32*/
      }
    }
    x_0_10008 = kk_integer_from_int(_x_x1580,kk_context()); /*int*/
    kk_integer_t y_0_10009;
    int32_t _x_x1585;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1586 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_7 = _con_x1586->since;
      int32_t _x_6 = _con_x1586->leap32;
      _x_x1585 = _x_6; /*int32*/
    }
    y_0_10009 = kk_integer_from_int(_x_x1585,kk_context()); /*int*/
    bool _match_x1061 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
    if (_match_x1061) {
      kk_integer_drop(y_0_10009, _ctx);
      kk_integer_drop(x_0_10008, _ctx);
      x_10016 = kk_std_core_types__new_Eq(_ctx); /*order*/
    }
    else {
      bool _match_x1062;
      bool _brw_x1063 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      kk_integer_drop(x_0_10008, _ctx);
      kk_integer_drop(y_0_10009, _ctx);
      _match_x1062 = _brw_x1063; /*bool*/
      if (_match_x1062) {
        x_10016 = kk_std_core_types__new_Gt(_ctx); /*order*/
      }
      else {
        x_10016 = kk_std_core_types__new_Lt(_ctx); /*order*/
      }
    }
  }
  else {
    x_10016 = _match_x1060; /*order*/
  }
  bool _match_x1051;
  kk_integer_t _brw_x1058;
  if (kk_std_core_types__is_Lt(x_10016, _ctx)) {
    _brw_x1058 = kk_integer_from_small(-1); /*int*/
    goto _match_x1587;
  }
  if (kk_std_core_types__is_Eq(x_10016, _ctx)) {
    _brw_x1058 = kk_integer_from_small(0); /*int*/
    goto _match_x1587;
  }
  {
    _brw_x1058 = kk_integer_from_small(1); /*int*/
  }
  _match_x1587: ;
  bool _brw_x1059 = kk_integer_eq_borrow(_brw_x1058,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1058, _ctx);
  _match_x1051 = _brw_x1059; /*bool*/
  if (_match_x1051) {
    kk_std_time_timestamp__timestamp_drop(utc1, _ctx);
    kk_std_time_timestamp__timestamp_drop(utc0, _ctx);
    kk_datatype_ptr_dropn(leaps, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(la1, (KK_I32(2)), _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_num_ddouble__ddouble dtai0 = kk_std_time_utc_utc_to_delta_tai(leaps, utc0, _ctx); /*std/time/timestamp/timespan*/;
    kk_std_num_ddouble__ddouble dtai1;
    kk_std_time_utc__leap_adjust _x_x1588 = kk_std_time_utc__leap_adjust_dup(la1, _ctx); /*std/time/utc/leap-adjust*/
    dtai1 = kk_std_time_utc_delta_tai(_x_x1588, utc1, _ctx); /*std/time/timestamp/timespan*/
    kk_std_num_ddouble__ddouble x_0_10085;
    kk_std_num_ddouble__ddouble _x_x1589;
    double _x_x1590;
    double _x_x1591;
    {
      double _x_0_0 = dtai0.hi;
      _x_x1591 = _x_0_0; /*float64*/
    }
    _x_x1590 = (-_x_x1591); /*float64*/
    double _x_x1592;
    double _x_x1593;
    {
      double _x_0_0_0 = dtai0.lo;
      _x_x1593 = _x_0_0_0; /*float64*/
    }
    _x_x1592 = (-_x_x1593); /*float64*/
    _x_x1589 = kk_std_num_ddouble__new_Ddouble(_x_x1590, _x_x1592, _ctx); /*std/num/ddouble/ddouble*/
    x_0_10085 = kk_std_num_ddouble__lp__plus__rp_(dtai1, _x_x1589, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble diff;
    bool _match_x1052 = kk_integer_lte_borrow((kk_integer_from_small(3)),(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x1052) {
      diff = kk_std_num_ddouble_round(x_0_10085, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      bool _match_x1053 = kk_integer_gt_borrow((kk_integer_from_small(3)),(kk_integer_from_small(31)),kk_context()); /*bool*/;
      if (_match_x1053) {
        diff = x_0_10085; /*std/num/ddouble/ddouble*/
      }
      else {
        kk_integer_t n_0_10105 = kk_integer_abs((kk_integer_from_small(3)),kk_context()); /*int*/;
        kk_std_num_ddouble__ddouble p;
        bool _match_x1055 = kk_integer_eq_borrow(n_0_10105,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x1055) {
          kk_integer_drop(n_0_10105, _ctx);
          bool _match_x1057;
          double _x_x1594;
          kk_std_num_ddouble__ddouble _x_x1595 = kk_std_num_ddouble_ten; /*std/num/ddouble/ddouble*/
          {
            double _x_8 = _x_x1595.hi;
            _x_x1594 = _x_8; /*float64*/
          }
          _match_x1057 = (_x_x1594 == (0x0p+0)); /*bool*/
          if (_match_x1057) {
            p = kk_std_num_ddouble_dd_nan; /*std/num/ddouble/ddouble*/
          }
          else {
            p = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
          }
        }
        else {
          bool _match_x1056 = kk_integer_eq_borrow(n_0_10105,(kk_integer_from_small(1)),kk_context()); /*bool*/;
          if (_match_x1056) {
            kk_integer_drop(n_0_10105, _ctx);
            p = kk_std_num_ddouble_ten; /*std/num/ddouble/ddouble*/
          }
          else {
            p = kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble_ten, kk_std_num_ddouble_one, n_0_10105, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
        kk_std_num_ddouble__ddouble p_0;
        bool _match_x1054 = kk_integer_lt_borrow((kk_integer_from_small(3)),(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x1054) {
          p_0 = kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble_one, p, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          p_0 = p; /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x_x1596;
        kk_std_num_ddouble__ddouble _x_x1597 = kk_std_num_ddouble__lp__star__rp_(x_0_10085, p_0, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1596 = kk_std_num_ddouble_round(_x_x1597, _ctx); /*std/num/ddouble/ddouble*/
        diff = kk_std_num_ddouble__lp__fs__rp_(_x_x1596, p_0, _ctx); /*std/num/ddouble/ddouble*/
      }
    }
    kk_box_t _x_x1598;
    kk_std_core_types__tuple2 _x_x1599;
    kk_box_t _x_x1600;
    kk_std_time_timestamp__timestamp _x_x1601;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1602 = kk_std_time_utc__as_Leap_adjust(la1, _ctx);
      kk_std_time_timestamp__timestamp _x_1_0 = _con_x1602->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_2_0 = _con_x1602->offset;
      kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x1602->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0_0_0 = _con_x1602->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1603 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1604 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(la1, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_0, _ctx)) {
          kk_datatype_ptr_free(_pat_5_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_5_0_0, _ctx);
        }
        kk_datatype_ptr_free(la1, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
        kk_datatype_ptr_decref(la1, _ctx);
      }
      _x_x1601 = _x_1_0; /*std/time/utc/utc-timestamp*/
    }
    _x_x1600 = kk_std_time_timestamp__timestamp_box(_x_x1601, _ctx); /*10037*/
    _x_x1599 = kk_std_core_types__new_Tuple2(_x_x1600, kk_std_num_ddouble__ddouble_box(diff, _ctx), _ctx); /*(10037, 10038)*/
    _x_x1598 = kk_std_core_types__tuple2_box(_x_x1599, _ctx); /*10024*/
    return kk_std_core_types__new_Just(_x_x1598, _ctx);
  }
}
 
// The UTC seconds in a day

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_seconds_in_day(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : std/time/timestamp/timestamp) -> std/time/timestamp/timespan */ 
  kk_std_core_types__tuple2 tuple2_10075 = kk_std_time_timestamp_days_seconds(utc_0, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_std_core_types__maybe _match_x1050;
  kk_integer_t _x_x1605;
  {
    kk_box_t _box_x34 = tuple2_10075.fst;
    kk_box_t _box_x35 = tuple2_10075.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x34, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    _x_x1605 = _x; /*int*/
  }
  _match_x1050 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1605, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x1050, _ctx)) {
    return kk_std_time_timestamp_solar_secs_per_day;
  }
  {
    kk_box_t _box_x36 = _match_x1050._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x36, KK_BORROWED, _ctx);
    kk_box_t _box_x37 = _pat_1_0.fst;
    kk_box_t _box_x38 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x37, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x38, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1606 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    kk_std_core_types__maybe_drop(_match_x1050, _ctx);
    return kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx);
  }
}
 
// Return the modified julian day since 2000-01-01 taking leap seconds into
// account that happen any time during the day

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_to_mjd(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_std_num_ddouble__ddouble tzdelta, kk_context_t* _ctx) { /* (leaps : leaps-table, utc : utc-timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 
  kk_std_time_timestamp__timestamp ts_10091;
  kk_std_num_ddouble__ddouble _x_x1607;
  kk_std_num_ddouble__ddouble _x_x1608;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1609 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _x_2 = _con_x1609->since;
    _x_x1608 = _x_2; /*std/time/timestamp/timespan*/
  }
  _x_x1607 = kk_std_num_ddouble__lp__plus__rp_(_x_x1608, tzdelta, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1610;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1611 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_1 = _con_x1611->since;
    int32_t _x_0_1 = _con_x1611->leap32;
    _x_x1610 = _x_0_1; /*int32*/
  }
  ts_10091 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1607, _x_x1610, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x_x1612;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1613 = kk_std_time_timestamp__as_Timestamp(ts_10091, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x1613->since;
    _x_x1612 = _x; /*std/time/timestamp/timespan*/
  }
  secs = kk_std_num_ddouble_floor(_x_x1612, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1614;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1615 = kk_std_time_timestamp__as_Timestamp(ts_10091, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x1615->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts_10091, _ctx)) {
      kk_datatype_ptr_free(ts_10091, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts_10091, _ctx);
    }
    _x_x1614 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1616;
  double _x_x1617;
  double _x_x1618;
  {
    double _x_0 = secs.hi;
    _x_x1618 = _x_0; /*float64*/
  }
  _x_x1617 = (-_x_x1618); /*float64*/
  double _x_x1619;
  double _x_x1620;
  {
    double _x_0_0 = secs.lo;
    _x_x1620 = _x_0_0; /*float64*/
  }
  _x_x1619 = (-_x_x1620); /*float64*/
  _x_x1616 = kk_std_num_ddouble__new_Ddouble(_x_x1617, _x_x1619, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x_x1614, _x_x1616, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 _match_x1044;
  kk_integer_t _x_x1621 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_x1044 = kk_std_core_int_divmod(_x_x1621, kk_integer_from_int(86400, _ctx), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x39 = _match_x1044.fst;
    kk_box_t _box_x40 = _match_x1044.snd;
    kk_integer_t days_0 = kk_integer_unbox(_box_x39, _ctx);
    kk_integer_t dsecs = kk_integer_unbox(_box_x40, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_integer_dup(dsecs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1044, _ctx);
    kk_std_num_ddouble__ddouble _match_x1045;
    kk_std_num_ddouble__ddouble _x_x1622 = kk_std_num_ddouble_ddouble_int_exp(dsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _match_x1045 = kk_std_num_ddouble__lp__plus__rp_(_x_x1622, frac, _ctx); /*std/num/ddouble/ddouble*/
    {
      kk_std_core_types__tuple2 tuple2_10075;
      kk_std_time_timestamp__timestamp _x_x1623 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
      tuple2_10075 = kk_std_time_timestamp_days_seconds(_x_x1623, _ctx); /*(int, std/num/ddouble/ddouble)*/
      kk_std_num_ddouble__ddouble frac_0;
      kk_std_core_types__maybe _match_x1046;
      kk_integer_t _x_x1624;
      {
        kk_box_t _box_x41 = tuple2_10075.fst;
        kk_box_t _box_x42 = tuple2_10075.snd;
        kk_integer_t _x_3 = kk_integer_unbox(_box_x41, _ctx);
        kk_integer_dup(_x_3, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
        _x_x1624 = _x_3; /*int*/
      }
      _match_x1046 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1624, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
      if (kk_std_core_types__is_Nothing(_match_x1046, _ctx)) {
        kk_integer_t i_10095;
        int32_t _x_x1625;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1626 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_5 = _con_x1626->since;
          int32_t _x_4 = _con_x1626->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
            kk_datatype_ptr_free(utc_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(utc_0, _ctx);
          }
          _x_x1625 = _x_4; /*int32*/
        }
        i_10095 = kk_integer_from_int(_x_x1625,kk_context()); /*int*/
        kk_std_num_ddouble__ddouble _x_x1627;
        kk_std_num_ddouble__ddouble _x_x1628 = kk_std_num_ddouble_ddouble_int_exp(i_10095, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        _x_x1627 = kk_std_num_ddouble__lp__plus__rp_(_match_x1045, _x_x1628, _ctx); /*std/num/ddouble/ddouble*/
        frac_0 = kk_std_num_ddouble__lp__fs__rp_(_x_x1627, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        kk_box_t _box_x43 = _match_x1046._cons.Just.value;
        kk_std_core_types__tuple2 _pat_4_0 = kk_std_core_types__tuple2_unbox(_box_x43, KK_BORROWED, _ctx);
        kk_box_t _box_x44 = _pat_4_0.fst;
        kk_box_t _box_x45 = _pat_4_0.snd;
        kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x44, KK_BORROWED, _ctx);
        kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x45, KK_BORROWED, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1629 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_time_timestamp__timestamp_dup(start, _ctx);
        kk_std_core_types__maybe_drop(_match_x1046, _ctx);
        kk_std_num_ddouble__ddouble secs_in_day = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/num/ddouble/ddouble*/;
        kk_std_core_types__order x_10016;
        kk_std_time_timestamp__timestamp _x_x1630 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
        x_10016 = kk_std_time_timestamp_cmp(_x_x1630, start, _ctx); /*order*/
        kk_std_num_ddouble__ddouble secs_0;
        bool _match_x1047;
        kk_integer_t _brw_x1048;
        if (kk_std_core_types__is_Lt(x_10016, _ctx)) {
          _brw_x1048 = kk_integer_from_small(-1); /*int*/
          goto _match_x1631;
        }
        if (kk_std_core_types__is_Eq(x_10016, _ctx)) {
          _brw_x1048 = kk_integer_from_small(0); /*int*/
          goto _match_x1631;
        }
        {
          _brw_x1048 = kk_integer_from_small(1); /*int*/
        }
        _match_x1631: ;
        bool _brw_x1049 = kk_integer_eq_borrow(_brw_x1048,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x1048, _ctx);
        _match_x1047 = _brw_x1049; /*bool*/
        if (_match_x1047) {
          kk_integer_t i_1_10099;
          int32_t _x_x1632;
          {
            struct kk_std_time_timestamp_Timestamp* _con_x1633 = kk_std_time_timestamp__as_Timestamp(utc_0, _ctx);
            kk_std_num_ddouble__ddouble _pat_0_7 = _con_x1633->since;
            int32_t _x_5 = _con_x1633->leap32;
            if kk_likely(kk_datatype_ptr_is_unique(utc_0, _ctx)) {
              kk_datatype_ptr_free(utc_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(utc_0, _ctx);
            }
            _x_x1632 = _x_5; /*int32*/
          }
          i_1_10099 = kk_integer_from_int(_x_x1632,kk_context()); /*int*/
          kk_std_num_ddouble__ddouble _x_x1634 = kk_std_num_ddouble_ddouble_int_exp(i_1_10099, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
          secs_0 = kk_std_num_ddouble__lp__plus__rp_(_match_x1045, _x_x1634, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
          secs_0 = kk_std_num_ddouble__lp__plus__rp_(_match_x1045, diff, _ctx); /*std/num/ddouble/ddouble*/
        }
        frac_0 = kk_std_num_ddouble__lp__fs__rp_(secs_0, secs_in_day, _ctx); /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x1635 = kk_std_num_ddouble_ddouble_int_exp(days_0, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      return kk_std_num_ddouble__lp__plus__rp_(_x_x1635, frac_0, _ctx);
    }
  }
}
 
// Return UTC from the modified julian day since 2000-01-01 taking leap seconds into
// account that happen any time during the day

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_from_mjd(kk_std_time_utc__leaps_table leaps, kk_integer_t days, kk_std_num_ddouble__ddouble frac, kk_context_t* _ctx) { /* (leaps : leaps-table, days : int, frac : std/num/ddouble/ddouble) -> utc-timestamp */ 
  kk_std_core_types__maybe _match_x1037;
  kk_integer_t _x_x1636 = kk_integer_dup(days, _ctx); /*int*/
  _match_x1037 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1636, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x1037, _ctx)) {
    kk_std_num_ddouble__ddouble _b_x46_52 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_core_types__optional _x_x1637 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x46_52, _ctx), _ctx); /*? 10003*/
    return kk_std_time_timestamp_timestamp_days(days, _x_x1637, kk_std_core_types__new_None(_ctx), _ctx);
  }
  {
    kk_box_t _box_x47 = _match_x1037._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1 = kk_std_core_types__tuple2_unbox(_box_x47, KK_BORROWED, _ctx);
    kk_box_t _box_x48 = _pat_1.fst;
    kk_box_t _box_x49 = _pat_1.snd;
    kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x48, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x49, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1638 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
    kk_std_time_timestamp__timestamp_dup(start, _ctx);
    kk_std_core_types__maybe_drop(_match_x1037, _ctx);
    kk_std_num_ddouble__ddouble secs;
    kk_std_num_ddouble__ddouble _x_x1639 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/num/ddouble/ddouble*/
    secs = kk_std_num_ddouble__lp__star__rp_(frac, _x_x1639, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_timestamp__timestamp utc_0;
    kk_std_core_types__optional _x_x1640 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*? 10003*/
    utc_0 = kk_std_time_timestamp_timestamp_days(days, _x_x1640, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__order x_10016;
    kk_std_time_timestamp__timestamp _x_x1641 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x1642 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    x_10016 = kk_std_time_timestamp_cmp(_x_x1641, _x_x1642, _ctx); /*order*/
    bool _match_x1038;
    kk_integer_t _brw_x1042;
    if (kk_std_core_types__is_Lt(x_10016, _ctx)) {
      _brw_x1042 = kk_integer_from_small(-1); /*int*/
      goto _match_x1643;
    }
    if (kk_std_core_types__is_Eq(x_10016, _ctx)) {
      _brw_x1042 = kk_integer_from_small(0); /*int*/
      goto _match_x1643;
    }
    {
      _brw_x1042 = kk_integer_from_small(1); /*int*/
    }
    _match_x1643: ;
    bool _brw_x1043 = kk_integer_eq_borrow(_brw_x1042,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1042, _ctx);
    _match_x1038 = _brw_x1043; /*bool*/
    if (_match_x1038) {
      if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
        kk_datatype_ptr_free(start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(start, _ctx);
      }
      return utc_0;
    }
    {
      kk_std_time_timestamp__timestamp j_0_10105;
      kk_std_num_ddouble__ddouble _x_x1644;
      kk_std_num_ddouble__ddouble _x_x1645;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1646 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _x = _con_x1646->since;
        _x_x1645 = _x; /*std/time/timestamp/timespan*/
      }
      _x_x1644 = kk_std_num_ddouble__lp__plus__rp_(_x_x1645, diff, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1647;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1648 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1648->since;
        int32_t _x_0 = _con_x1648->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(start, _ctx)) {
          kk_datatype_ptr_free(start, _ctx);
        }
        else {
          kk_datatype_ptr_decref(start, _ctx);
        }
        _x_x1647 = _x_0; /*int32*/
      }
      j_0_10105 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1644, _x_x1647, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_core_types__order x_10022;
      kk_std_time_timestamp__timestamp _x_x1649 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
      x_10022 = kk_std_time_timestamp_cmp(_x_x1649, j_0_10105, _ctx); /*order*/
      bool _match_x1039;
      kk_integer_t _brw_x1040;
      if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
        _brw_x1040 = kk_integer_from_small(-1); /*int*/
        goto _match_x1650;
      }
      if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
        _brw_x1040 = kk_integer_from_small(0); /*int*/
        goto _match_x1650;
      }
      {
        _brw_x1040 = kk_integer_from_small(1); /*int*/
      }
      _match_x1650: ;
      bool _brw_x1041 = kk_integer_eq_borrow(_brw_x1040,(kk_integer_from_small(1)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x1040, _ctx);
      _match_x1039 = _brw_x1041; /*bool*/
      if (_match_x1039) {
        return kk_std_time_timestamp__lp__dash__rp_(utc_0, diff, _ctx);
      }
      {
        kk_std_time_timestamp__timestamp _x_x1651 = kk_std_time_timestamp__lp__dash__rp_(utc_0, diff, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_timestamp_add_leap_seconds(_x_x1651, diff, _ctx);
      }
    }
  }
}
 
// Create a new time scale based on UTC seconds with a given `name`
// and a leap second table.


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1655__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_timescale_fun1655(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1655(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1655__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1655__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1655, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_timescale_fun1655(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1655__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1655__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_from_tai(leaps, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1657__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_std_time_duration__duration kk_std_time_utc_utc_timescale_fun1657(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1657(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1657__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1657__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1657, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_utc_timescale_fun1657(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0_1, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1657__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1657__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_to_tai(leaps, utc_0_1, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1661__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_utc_timescale_fun1661(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1661(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1661__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1661__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1661, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_utc_timescale_fun1661(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1661__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1661__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1662;
  kk_std_time_timestamp__timestamp utc_0_0_77 = kk_std_time_timestamp__timestamp_unbox(_b_x61, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_core_types__tuple2 tuple2_10075 = kk_std_time_timestamp_days_seconds(utc_0_0_77, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_std_core_types__maybe _match_x1036;
  kk_integer_t _x_x1663;
  {
    kk_box_t _box_x53 = tuple2_10075.fst;
    kk_box_t _box_x54 = tuple2_10075.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x53, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    _x_x1663 = _x; /*int*/
  }
  _match_x1036 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x1663, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x1036, _ctx)) {
    _x_x1662 = kk_std_time_timestamp_solar_secs_per_day; /*std/time/timestamp/timespan*/
  }
  else {
    kk_box_t _box_x55 = _match_x1036._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x55, KK_BORROWED, _ctx);
    kk_box_t _box_x56 = _pat_1_0.fst;
    kk_box_t _box_x57 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x56, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x57, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1664 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    kk_std_core_types__maybe_drop(_match_x1036, _ctx);
    _x_x1662 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/time/timestamp/timespan*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x1662, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1668__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_utc_timescale_fun1668(kk_function_t _fself, kk_box_t _b_x66, kk_box_t _b_x67, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1668(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1668__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1668__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1668, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_utc_timescale_fun1668(kk_function_t _fself, kk_box_t _b_x66, kk_box_t _b_x67, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1668__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1668__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x1669;
  kk_std_time_timestamp__timestamp utc_1_78 = kk_std_time_timestamp__timestamp_unbox(_b_x66, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_num_ddouble__ddouble tzdelta_79 = kk_std_num_ddouble__ddouble_unbox(_b_x67, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  _x_x1669 = kk_std_time_utc_utc_to_mjd(leaps, utc_1_78, tzdelta_79, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1669, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_timescale_fun1671__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_utc_timescale_fun1671(kk_function_t _fself, kk_box_t _b_x72, kk_box_t _b_x73, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_timescale_fun1671(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1671__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_timescale_fun1671__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_timescale_fun1671, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_utc_timescale_fun1671(kk_function_t _fself, kk_box_t _b_x72, kk_box_t _b_x73, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_timescale_fun1671__t* _self = kk_function_as(struct kk_std_time_utc_utc_timescale_fun1671__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp _x_x1672;
  kk_integer_t days_80 = kk_integer_unbox(_b_x72, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble frac_81 = kk_std_num_ddouble__ddouble_unbox(_b_x73, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  _x_x1672 = kk_std_time_utc_utc_from_mjd(leaps, days_80, frac_81, _ctx); /*std/time/utc/utc-timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1672, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_utc_timescale(kk_string_t name, kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (name : string, leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_string_t _x_x1652;
  kk_define_string_literal(, _s_x1653, 3, "UTC", _ctx)
  _x_x1652 = kk_string_dup(_s_x1653, _ctx); /*string*/
  kk_function_t _x_x1654;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1654 = kk_std_time_utc_new_utc_timescale_fun1655(leaps, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_function_t _x_x1656;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1656 = kk_std_time_utc_new_utc_timescale_fun1657(leaps, _ctx); /*(utc@0@1 : std/time/timestamp/timestamp) -> std/time/duration/duration*/
  kk_std_core_types__maybe _x_x1658;
  kk_box_t _x_x1659;
  kk_function_t _x_x1660;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1660 = kk_std_time_utc_new_utc_timescale_fun1661(leaps, _ctx); /*(59) -> 60*/
  _x_x1659 = kk_function_box(_x_x1660, _ctx); /*10024*/
  _x_x1658 = kk_std_core_types__new_Just(_x_x1659, _ctx); /*maybe<10024>*/
  kk_std_core_types__maybe _x_x1665;
  kk_box_t _x_x1666;
  kk_function_t _x_x1667;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x1667 = kk_std_time_utc_new_utc_timescale_fun1668(leaps, _ctx); /*(63, 64) -> 65*/
  _x_x1666 = kk_function_box(_x_x1667, _ctx); /*10024*/
  _x_x1665 = kk_std_core_types__new_Just(_x_x1666, _ctx); /*maybe<10024>*/
  kk_std_core_types__maybe _x_x1670 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_utc_new_utc_timescale_fun1671(leaps, _ctx), _ctx), _ctx); /*maybe<10024>*/
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, name, _x_x1652, _x_x1654, _x_x1656, _x_x1658, _x_x1665, _x_x1670, _ctx);
}
 
// lifted local: @lift-upto@10648, upto, @spec-x10516
// specialized: std/core/list/@unroll-drop-while@10006, on parameters @uniq-predicate@10509, using:
// @uniq-predicate@10509 = fn(la: std/time/utc/leap-adjust){
//   val x@10022 : order
//         = match ((match ((std/num/float64/cmp((match (la) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                -> (match (@x@0@1) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3: float64) : float64, (@pat@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5: std/time/timestamp/timestamp)
//                    -> (match (@x@3) {
//                     ((@skip std/num/ddouble/Ddouble((@x@0: float64) : float64, (@pat@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3: std/num/ddouble/ddouble)
//                        -> @x@0;
//                   });
//               });
//           }), (match (end) {
//             ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4: float64) : float64, (@pat@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@4: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6: std/time/timestamp/timestamp)
//                -> (match (@x@4) {
//                 ((@skip std/num/ddouble/Ddouble((@x@0@0: float64) : float64, (@pat@0@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@1@2: std/num/ddouble/ddouble)
//                    -> @x@0@0;
//               });
//           })))) {
//           ((std/core/types/Eq() : order ) as @pat@2@2: order)
//              -> std/num/float64/cmp((match (la) {
//                 ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                    -> (match (@x@0@1) {
//                     ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0: float64) : float64, (@pat@1@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: std/time/timestamp/timestamp)
//                        -> (match (@x@3@0) {
//                         ((@skip std/num/ddouble/Ddouble((@pat@0@1: float64) : float64, (@x@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@0: std/num/ddouble/ddouble)
//                            -> @x@1;
//                       });
//                   });
//               }), (match (end) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4@0: float64) : float64, (@pat@1@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0: std/time/timestamp/timestamp)
//                    -> (match (@x@4@0) {
//                     ((@skip std/num/ddouble/Ddouble((@pat@0@2: float64) : float64, (@x@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@4: std/num/ddouble/ddouble)
//                        -> @x@2;
//                   });
//               }));
//           (ord: order)
//              -> ord;
//         })) {
//           ((std/core/types/Eq() : order ) as @pat@7: order)
//              -> val x@0@10008 : int;
//                 val y@0@10009 : int;
//             (match ((std/core/int/(==)(x@0@10008, y@0@10009))) {
//               ((std/core/types/True() : bool ) as @pat@8: bool)
//                  -> std/core/types/Eq;
//               ((@skip std/core/types/False() : bool ) as @pat@0@5: bool)
//                  -> (match ((std/core/int/(>)(x@0@10008, y@0@10009))) {
//                   ((std/core/types/True() : bool ) as @pat@1@2@0: bool)
//                      -> std/core/types/Gt;
//                   ((@skip std/core/types/False() : bool ) as @pat@2@2@0: bool)
//                      -> std/core/types/Lt;
//                 });
//             });
//           (ord@0: order)
//              -> ord@0;
//         };
//   std/core/int/(==)((match (x@10022) {
//       ((std/core/types/Lt() : order ) as @pat@3@1: order)
//          -> -1;
//       ((std/core/types/Eq() : order ) as @pat@0@0@1: order)
//          -> 0;
//       ((@skip std/core/types/Gt() : order ) as @pat@1@0@1: order)
//          -> 1;
//     }), 1);
// }

kk_std_core_types__list kk_std_time_utc__lift_upto_10649(kk_std_time_timestamp__timestamp end, kk_std_core_types__list _uniq_xs_10508, kk_context_t* _ctx) { /* (end : utc-timestamp, list<leap-adjust>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10508, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1673 = kk_std_core_types__as_Cons(_uniq_xs_10508, _ctx);
    kk_box_t _box_x82 = _con_x1673->head;
    kk_std_core_types__list _uniq_xx_10512 = _con_x1673->tail;
    kk_std_time_utc__leap_adjust _uniq_x_10511 = kk_std_time_utc__leap_adjust_unbox(_box_x82, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_uniq_x_10511, _ctx);
    kk_std_core_types__list_dup(_uniq_xx_10512, _ctx);
    kk_std_core_types__order x_10022;
    kk_std_core_types__order _match_x1031;
    kk_std_core_types__order _match_x1035;
    double _x_x1674;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1675 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10511, _ctx);
      kk_std_time_timestamp__timestamp _x_0_1 = _con_x1675->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_1 = _con_x1675->offset;
      kk_std_time_timestamp__timestamp _pat_5_1 = _con_x1675->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1675->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1676 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1677 = kk_std_time_timestamp__as_Timestamp(_pat_5_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_0_1, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1678 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x1678->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
          kk_datatype_ptr_free(_x_0_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1, _ctx);
        }
        {
          double _x_0 = _x_3.hi;
          _x_x1674 = _x_0; /*float64*/
        }
      }
    }
    double _x_x1679;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1680 = kk_std_time_timestamp__as_Timestamp(end, _ctx);
      kk_std_num_ddouble__ddouble _x_4 = _con_x1680->since;
      {
        double _x_0_0 = _x_4.hi;
        _x_x1679 = _x_0_0; /*float64*/
      }
    }
    _match_x1035 = kk_std_num_float64_cmp(_x_x1674, _x_x1679, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x1035, _ctx)) {
      double _x_x1681;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1682 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10511, _ctx);
        kk_std_time_timestamp__timestamp _x_0_1_0 = _con_x1682->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_0_1_0 = _con_x1682->offset;
        kk_std_time_timestamp__timestamp _pat_5_1_0 = _con_x1682->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1682->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1683 = kk_std_time_timestamp__as_Timestamp(_x_0_1_0, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1684 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_0_1_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1685 = kk_std_time_timestamp__as_Timestamp(_x_0_1_0, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x1685->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_0, _ctx)) {
            kk_datatype_ptr_free(_x_0_1_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_0_1_0, _ctx);
          }
          {
            double _x_1 = _x_3_0.lo;
            _x_x1681 = _x_1; /*float64*/
          }
        }
      }
      double _x_x1686;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1687 = kk_std_time_timestamp__as_Timestamp(end, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x1687->since;
        {
          double _x_2 = _x_4_0.lo;
          _x_x1686 = _x_2; /*float64*/
        }
      }
      _match_x1031 = kk_std_num_float64_cmp(_x_x1681, _x_x1686, _ctx); /*order*/
    }
    else {
      _match_x1031 = _match_x1035; /*order*/
    }
    if (kk_std_core_types__is_Eq(_match_x1031, _ctx)) {
      kk_integer_t x_0_10008;
      int32_t _x_x1688;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1689 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10511, _ctx);
        kk_std_time_timestamp__timestamp _x_0_1_1 = _con_x1689->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_0_1_1 = _con_x1689->offset;
        kk_std_time_timestamp__timestamp _pat_5_1_1 = _con_x1689->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_1 = _con_x1689->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1690 = kk_std_time_timestamp__as_Timestamp(_x_0_1_1, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1691 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_1, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_uniq_x_10511, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_1_1, _ctx)) {
            kk_datatype_ptr_free(_pat_5_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_1_1, _ctx);
          }
          kk_datatype_ptr_free(_uniq_x_10511, _ctx);
        }
        else {
          kk_std_time_timestamp__timestamp_dup(_x_0_1_1, _ctx);
          kk_datatype_ptr_decref(_uniq_x_10511, _ctx);
        }
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1692 = kk_std_time_timestamp__as_Timestamp(_x_0_1_1, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_6 = _con_x1692->since;
          int32_t _x_5 = _con_x1692->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_1, _ctx)) {
            kk_datatype_ptr_free(_x_0_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_0_1_1, _ctx);
          }
          _x_x1688 = _x_5; /*int32*/
        }
      }
      x_0_10008 = kk_integer_from_int(_x_x1688,kk_context()); /*int*/
      kk_integer_t y_0_10009;
      int32_t _x_x1693;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1694 = kk_std_time_timestamp__as_Timestamp(end, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_7 = _con_x1694->since;
        int32_t _x_6 = _con_x1694->leap32;
        _x_x1693 = _x_6; /*int32*/
      }
      y_0_10009 = kk_integer_from_int(_x_x1693,kk_context()); /*int*/
      bool _match_x1032 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      if (_match_x1032) {
        kk_integer_drop(y_0_10009, _ctx);
        kk_integer_drop(x_0_10008, _ctx);
        x_10022 = kk_std_core_types__new_Eq(_ctx); /*order*/
      }
      else {
        bool _match_x1033;
        bool _brw_x1034 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
        kk_integer_drop(x_0_10008, _ctx);
        kk_integer_drop(y_0_10009, _ctx);
        _match_x1033 = _brw_x1034; /*bool*/
        if (_match_x1033) {
          x_10022 = kk_std_core_types__new_Gt(_ctx); /*order*/
        }
        else {
          x_10022 = kk_std_core_types__new_Lt(_ctx); /*order*/
        }
      }
    }
    else {
      kk_datatype_ptr_dropn(_uniq_x_10511, (KK_I32(2)), _ctx);
      x_10022 = _match_x1031; /*order*/
    }
    bool _match_x1028;
    kk_integer_t _brw_x1029;
    if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
      _brw_x1029 = kk_integer_from_small(-1); /*int*/
      goto _match_x1695;
    }
    if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
      _brw_x1029 = kk_integer_from_small(0); /*int*/
      goto _match_x1695;
    }
    {
      _brw_x1029 = kk_integer_from_small(1); /*int*/
    }
    _match_x1695: ;
    bool _brw_x1030 = kk_integer_eq_borrow(_brw_x1029,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1029, _ctx);
    _match_x1028 = _brw_x1030; /*bool*/
    if (_match_x1028) {
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10508, _ctx)) {
        kk_std_core_types__list_drop(_uniq_xx_10512, _ctx);
        kk_datatype_ptr_dropn(_uniq_x_10511, (KK_I32(2)), _ctx);
        kk_datatype_ptr_free(_uniq_xs_10508, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_uniq_xs_10508, _ctx);
      }
      { // tailcall
        _uniq_xs_10508 = _uniq_xx_10512;
        goto kk__tailcall;
      }
    }
    {
      kk_std_time_timestamp__timestamp_drop(end, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10512, _ctx);
      return _uniq_xs_10508;
    }
  }
  {
    kk_std_time_timestamp__timestamp_drop(end, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: upto, @spec-x10507
// specialized: std/core/list/drop-while, on parameters @uniq-predicate@10504, using:
// @uniq-predicate@10504 = fn(la: std/time/utc/leap-adjust){
//   val x@10022 : order
//         = match ((match ((std/num/float64/cmp((match (la) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                -> (match (@x@0@1) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3: float64) : float64, (@pat@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5: std/time/timestamp/timestamp)
//                    -> (match (@x@3) {
//                     ((@skip std/num/ddouble/Ddouble((@x@0: float64) : float64, (@pat@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3: std/num/ddouble/ddouble)
//                        -> @x@0;
//                   });
//               });
//           }), (match (end) {
//             ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4: float64) : float64, (@pat@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@4: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6: std/time/timestamp/timestamp)
//                -> (match (@x@4) {
//                 ((@skip std/num/ddouble/Ddouble((@x@0@0: float64) : float64, (@pat@0@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@1@2: std/num/ddouble/ddouble)
//                    -> @x@0@0;
//               });
//           })))) {
//           ((std/core/types/Eq() : order ) as @pat@2@2: order)
//              -> std/num/float64/cmp((match (la) {
//                 ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                    -> (match (@x@0@1) {
//                     ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0: float64) : float64, (@pat@1@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: std/time/timestamp/timestamp)
//                        -> (match (@x@3@0) {
//                         ((@skip std/num/ddouble/Ddouble((@pat@0@1: float64) : float64, (@x@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@0: std/num/ddouble/ddouble)
//                            -> @x@1;
//                       });
//                   });
//               }), (match (end) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4@0: float64) : float64, (@pat@1@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0: std/time/timestamp/timestamp)
//                    -> (match (@x@4@0) {
//                     ((@skip std/num/ddouble/Ddouble((@pat@0@2: float64) : float64, (@x@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@4: std/num/ddouble/ddouble)
//                        -> @x@2;
//                   });
//               }));
//           (ord: order)
//              -> ord;
//         })) {
//           ((std/core/types/Eq() : order ) as @pat@7: order)
//              -> val x@0@10008 : int;
//                 val y@0@10009 : int;
//             (match ((std/core/int/(==)(x@0@10008, y@0@10009))) {
//               ((std/core/types/True() : bool ) as @pat@8: bool)
//                  -> std/core/types/Eq;
//               ((@skip std/core/types/False() : bool ) as @pat@0@5: bool)
//                  -> (match ((std/core/int/(>)(x@0@10008, y@0@10009))) {
//                   ((std/core/types/True() : bool ) as @pat@1@2@0: bool)
//                      -> std/core/types/Gt;
//                   ((@skip std/core/types/False() : bool ) as @pat@2@2@0: bool)
//                      -> std/core/types/Lt;
//                 });
//             });
//           (ord@0: order)
//              -> ord@0;
//         };
//   std/core/int/(==)((match (x@10022) {
//       ((std/core/types/Lt() : order ) as @pat@3@1: order)
//          -> -1;
//       ((std/core/types/Eq() : order ) as @pat@0@0@1: order)
//          -> 0;
//       ((@skip std/core/types/Gt() : order ) as @pat@1@0@1: order)
//          -> 1;
//     }), 1);
// }

kk_std_core_types__list kk_std_time_utc__lift_upto_10648(kk_std_time_timestamp__timestamp end, kk_std_core_types__list _uniq_xs_10503, kk_context_t* _ctx) { /* (end : utc-timestamp, list<leap-adjust>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10503, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(end, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_time_utc__lift_upto_10649(end, _uniq_xs_10503, _ctx);
  }
}

kk_std_time_utc__leaps_table kk_std_time_utc_upto(kk_std_time_utc__leaps_table lt, kk_std_time_timestamp__timestamp end, kk_context_t* _ctx) { /* (lt : leaps-table, end : utc-timestamp) -> leaps-table */ 
  kk_std_core_types__list _b_x83_84;
  kk_std_core_types__list _x_x1696;
  {
    struct kk_std_time_utc_Leaps_table* _con_x1697 = kk_std_time_utc__as_Leaps_table(lt, _ctx);
    kk_std_time_instant__instant _pat_0 = _con_x1697->expire;
    kk_std_core_types__list _x = _con_x1697->adjusts;
    kk_std_core_types__list_dup(_x, _ctx);
    _x_x1696 = _x; /*list<std/time/utc/leap-adjust>*/
  }
  _b_x83_84 = kk_std_time_utc__lift_upto_10648(end, _x_x1696, _ctx); /*list<std/time/utc/leap-adjust>*/
  kk_std_time_instant__instant _x_x1698;
  kk_std_core_types__optional _match_x1027 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1027, _ctx)) {
    kk_box_t _box_x85 = _match_x1027._cons._Optional.value;
    kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x85, KK_BORROWED, _ctx);
    kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
    kk_std_core_types__optional_drop(_match_x1027, _ctx);
    _x_x1698 = _uniq_expire_375; /*std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1027, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1699 = kk_std_time_utc__as_Leaps_table(lt, _ctx);
      kk_std_time_instant__instant _x_1_0 = _con_x1699->expire;
      kk_std_time_instant__instant_dup(_x_1_0, _ctx);
      _x_x1698 = _x_1_0; /*std/time/instant/instant*/
    }
  }
  kk_std_core_types__list _x_x1700;
  kk_std_core_types__optional _match_x1026 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x83_84, _ctx), _ctx); /*? 10003*/;
  if (kk_std_core_types__is_Optional(_match_x1026, _ctx)) {
    kk_box_t _box_x86 = _match_x1026._cons._Optional.value;
    kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x86, KK_BORROWED, _ctx);
    kk_datatype_ptr_dropn(lt, (KK_I32(3)), _ctx);
    kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
    kk_std_core_types__optional_drop(_match_x1026, _ctx);
    _x_x1700 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1026, _ctx);
    {
      struct kk_std_time_utc_Leaps_table* _con_x1701 = kk_std_time_utc__as_Leaps_table(lt, _ctx);
      kk_std_time_instant__instant _pat_0_4_1 = _con_x1701->expire;
      kk_std_core_types__list _x_2_0 = _con_x1701->adjusts;
      if kk_likely(kk_datatype_ptr_is_unique(lt, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_4_1, _ctx);
        kk_datatype_ptr_free(lt, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_2_0, _ctx);
        kk_datatype_ptr_decref(lt, _ctx);
      }
      _x_x1700 = _x_2_0; /*list<std/time/utc/leap-adjust>*/
    }
  }
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x1698, _x_x1700, _ctx);
}
 
// lifted local: @lift-extend@10650, extend, @spec-x10531
// specialized: std/core/list/@unroll-drop-while@10006, on parameters @uniq-predicate@10524, using:
// @uniq-predicate@10524 = fn(la@0: std/time/utc/leap-adjust){
//   val x@10022 : order
//         = match ((match ((std/num/float64/cmp((match (la@0) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@7@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@6: int32) : int32) : std/time/timestamp/timestamp ) as @x@3@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@1@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@11: std/time/utc/leap-adjust)
//                -> (match (@x@3@1) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0: float64) : float64, (@pat@1@0@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@3: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: std/time/timestamp/timestamp)
//                    -> (match (@x@3) {
//                     ((@skip std/num/ddouble/Ddouble((@x@1: float64) : float64, (@pat@0@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@6: std/num/ddouble/ddouble)
//                        -> @x@1;
//                   });
//               });
//           }), (match (end@10131) {
//             ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4: float64) : float64, (@pat@1@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@4: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0: std/time/timestamp/timestamp)
//                -> (match (@x@4) {
//                 ((@skip std/num/ddouble/Ddouble((@x@0@1: float64) : float64, (@pat@0@0@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@1@3: std/num/ddouble/ddouble)
//                    -> @x@0@1;
//               });
//           })))) {
//           ((std/core/types/Eq() : order ) as @pat@2@2: order)
//              -> std/num/float64/cmp((match (la@0) {
//                 ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@7@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@6: int32) : int32) : std/time/timestamp/timestamp ) as @x@3@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@1@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@11: std/time/utc/leap-adjust)
//                    -> (match (@x@3@1) {
//                     ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0@0: float64) : float64, (@pat@1@0@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0@0: std/time/timestamp/timestamp)
//                        -> (match (@x@3@0) {
//                         ((@skip std/num/ddouble/Ddouble((@pat@0@1@1: float64) : float64, (@x@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@1: std/num/ddouble/ddouble)
//                            -> @x@1@1;
//                       });
//                   });
//               }), (match (end@10131) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4@0: float64) : float64, (@pat@1@1@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0@0: std/time/timestamp/timestamp)
//                    -> (match (@x@4@0) {
//                     ((@skip std/num/ddouble/Ddouble((@pat@0@2@1: float64) : float64, (@x@2@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@4@0: std/num/ddouble/ddouble)
//                        -> @x@2@1;
//                   });
//               }));
//           (ord: order)
//              -> ord;
//         })) {
//           ((std/core/types/Eq() : order ) as @pat@7@0: order)
//              -> val x@0@10008 : int;
//                 val y@0@10009 : int;
//             (match ((std/core/int/(==)(x@0@10008, y@0@10009))) {
//               ((std/core/types/True() : bool ) as @pat@8: bool)
//                  -> std/core/types/Eq;
//               ((@skip std/core/types/False() : bool ) as @pat@0@5@0: bool)
//                  -> (match ((std/core/int/(>)(x@0@10008, y@0@10009))) {
//                   ((std/core/types/True() : bool ) as @pat@1@2@0: bool)
//                      -> std/core/types/Gt;
//                   ((@skip std/core/types/False() : bool ) as @pat@2@2@0: bool)
//                      -> std/core/types/Lt;
//                 });
//             });
//           (ord@0: order)
//              -> ord@0;
//         };
//   std/core/int/(==)((match (x@10022) {
//       ((std/core/types/Lt() : order ) as @pat@10@2: order)
//          -> -1;
//       ((std/core/types/Eq() : order ) as @pat@0@6@0: order)
//          -> 0;
//       ((@skip std/core/types/Gt() : order ) as @pat@1@5: order)
//          -> 1;
//     }), 1);
// }

kk_std_core_types__list kk_std_time_utc__lift_extend_10651(kk_std_time_timestamp__timestamp end_10131, kk_std_core_types__list _uniq_xs_10523, kk_context_t* _ctx) { /* (end@10131 : utc-timestamp, list<leap-adjust>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10523, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1702 = kk_std_core_types__as_Cons(_uniq_xs_10523, _ctx);
    kk_box_t _box_x87 = _con_x1702->head;
    kk_std_core_types__list _uniq_xx_10527 = _con_x1702->tail;
    kk_std_time_utc__leap_adjust _uniq_x_10526 = kk_std_time_utc__leap_adjust_unbox(_box_x87, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_uniq_x_10526, _ctx);
    kk_std_core_types__list_dup(_uniq_xx_10527, _ctx);
    kk_std_core_types__order x_10022;
    kk_std_core_types__order _match_x1021;
    kk_std_core_types__order _match_x1025;
    double _x_x1703;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x1704 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10526, _ctx);
      kk_std_time_timestamp__timestamp _x_3_1 = _con_x1704->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_4_0 = _con_x1704->offset;
      kk_std_time_timestamp__timestamp _pat_5_0_1 = _con_x1704->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1704->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x1705 = kk_std_time_timestamp__as_Timestamp(_x_3_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x1706 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_3_1, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1707 = kk_std_time_timestamp__as_Timestamp(_x_3_1, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x1707->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_3_1, _ctx)) {
          kk_datatype_ptr_free(_x_3_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_3_1, _ctx);
        }
        {
          double _x_1 = _x_3.hi;
          _x_x1703 = _x_1; /*float64*/
        }
      }
    }
    double _x_x1708;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1709 = kk_std_time_timestamp__as_Timestamp(end_10131, _ctx);
      kk_std_num_ddouble__ddouble _x_4 = _con_x1709->since;
      {
        double _x_0_1 = _x_4.hi;
        _x_x1708 = _x_0_1; /*float64*/
      }
    }
    _match_x1025 = kk_std_num_float64_cmp(_x_x1703, _x_x1708, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x1025, _ctx)) {
      double _x_x1710;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1711 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10526, _ctx);
        kk_std_time_timestamp__timestamp _x_3_1_0 = _con_x1711->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_4_0_0 = _con_x1711->offset;
        kk_std_time_timestamp__timestamp _pat_5_0_1_0 = _con_x1711->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1711->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1712 = kk_std_time_timestamp__as_Timestamp(_x_3_1_0, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1713 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_1_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_1_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1714 = kk_std_time_timestamp__as_Timestamp(_x_3_1_0, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x1714->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_3_1_0, _ctx)) {
            kk_datatype_ptr_free(_x_3_1_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_3_1_0, _ctx);
          }
          {
            double _x_1_1 = _x_3_0.lo;
            _x_x1710 = _x_1_1; /*float64*/
          }
        }
      }
      double _x_x1715;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1716 = kk_std_time_timestamp__as_Timestamp(end_10131, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x1716->since;
        {
          double _x_2_1 = _x_4_0.lo;
          _x_x1715 = _x_2_1; /*float64*/
        }
      }
      _match_x1021 = kk_std_num_float64_cmp(_x_x1710, _x_x1715, _ctx); /*order*/
    }
    else {
      _match_x1021 = _match_x1025; /*order*/
    }
    if (kk_std_core_types__is_Eq(_match_x1021, _ctx)) {
      kk_integer_t x_0_10008;
      int32_t _x_x1717;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x1718 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10526, _ctx);
        kk_std_time_timestamp__timestamp _x_3_1_1 = _con_x1718->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_4_0_1 = _con_x1718->offset;
        kk_std_time_timestamp__timestamp _pat_5_0_1_1 = _con_x1718->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_1 = _con_x1718->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x1719 = kk_std_time_timestamp__as_Timestamp(_x_3_1_1, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x1720 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_1_1, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_uniq_x_10526, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_1_1, _ctx)) {
            kk_datatype_ptr_free(_pat_5_0_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_0_1_1, _ctx);
          }
          kk_datatype_ptr_free(_uniq_x_10526, _ctx);
        }
        else {
          kk_std_time_timestamp__timestamp_dup(_x_3_1_1, _ctx);
          kk_datatype_ptr_decref(_uniq_x_10526, _ctx);
        }
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1721 = kk_std_time_timestamp__as_Timestamp(_x_3_1_1, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_6 = _con_x1721->since;
          int32_t _x_5 = _con_x1721->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_3_1_1, _ctx)) {
            kk_datatype_ptr_free(_x_3_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_3_1_1, _ctx);
          }
          _x_x1717 = _x_5; /*int32*/
        }
      }
      x_0_10008 = kk_integer_from_int(_x_x1717,kk_context()); /*int*/
      kk_integer_t y_0_10009;
      int32_t _x_x1722;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1723 = kk_std_time_timestamp__as_Timestamp(end_10131, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_7 = _con_x1723->since;
        int32_t _x_6_0 = _con_x1723->leap32;
        _x_x1722 = _x_6_0; /*int32*/
      }
      y_0_10009 = kk_integer_from_int(_x_x1722,kk_context()); /*int*/
      bool _match_x1022 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      if (_match_x1022) {
        kk_integer_drop(y_0_10009, _ctx);
        kk_integer_drop(x_0_10008, _ctx);
        x_10022 = kk_std_core_types__new_Eq(_ctx); /*order*/
      }
      else {
        bool _match_x1023;
        bool _brw_x1024 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
        kk_integer_drop(x_0_10008, _ctx);
        kk_integer_drop(y_0_10009, _ctx);
        _match_x1023 = _brw_x1024; /*bool*/
        if (_match_x1023) {
          x_10022 = kk_std_core_types__new_Gt(_ctx); /*order*/
        }
        else {
          x_10022 = kk_std_core_types__new_Lt(_ctx); /*order*/
        }
      }
    }
    else {
      kk_datatype_ptr_dropn(_uniq_x_10526, (KK_I32(2)), _ctx);
      x_10022 = _match_x1021; /*order*/
    }
    bool _match_x1018;
    kk_integer_t _brw_x1019;
    if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
      _brw_x1019 = kk_integer_from_small(-1); /*int*/
      goto _match_x1724;
    }
    if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
      _brw_x1019 = kk_integer_from_small(0); /*int*/
      goto _match_x1724;
    }
    {
      _brw_x1019 = kk_integer_from_small(1); /*int*/
    }
    _match_x1724: ;
    bool _brw_x1020 = kk_integer_eq_borrow(_brw_x1019,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1019, _ctx);
    _match_x1018 = _brw_x1020; /*bool*/
    if (_match_x1018) {
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10523, _ctx)) {
        kk_std_core_types__list_drop(_uniq_xx_10527, _ctx);
        kk_datatype_ptr_dropn(_uniq_x_10526, (KK_I32(2)), _ctx);
        kk_datatype_ptr_free(_uniq_xs_10523, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_uniq_xs_10523, _ctx);
      }
      { // tailcall
        _uniq_xs_10523 = _uniq_xx_10527;
        goto kk__tailcall;
      }
    }
    {
      kk_std_time_timestamp__timestamp_drop(end_10131, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10527, _ctx);
      return _uniq_xs_10523;
    }
  }
  {
    kk_std_time_timestamp__timestamp_drop(end_10131, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: extend, @spec-x10522
// specialized: std/core/list/drop-while, on parameters @uniq-predicate@10519, using:
// @uniq-predicate@10519 = fn(la@0: std/time/utc/leap-adjust){
//   val x@10022 : order
//         = match ((match ((std/num/float64/cmp((match (la@0) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@7@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@6: int32) : int32) : std/time/timestamp/timestamp ) as @x@3@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@1@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@11: std/time/utc/leap-adjust)
//                -> (match (@x@3@1) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0: float64) : float64, (@pat@1@0@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@3: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: std/time/timestamp/timestamp)
//                    -> (match (@x@3) {
//                     ((@skip std/num/ddouble/Ddouble((@x@1: float64) : float64, (@pat@0@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@6: std/num/ddouble/ddouble)
//                        -> @x@1;
//                   });
//               });
//           }), (match (end@10131) {
//             ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4: float64) : float64, (@pat@1@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@4: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0: std/time/timestamp/timestamp)
//                -> (match (@x@4) {
//                 ((@skip std/num/ddouble/Ddouble((@x@0@1: float64) : float64, (@pat@0@0@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@1@3: std/num/ddouble/ddouble)
//                    -> @x@0@1;
//               });
//           })))) {
//           ((std/core/types/Eq() : order ) as @pat@2@2: order)
//              -> std/num/float64/cmp((match (la@0) {
//                 ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@7@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@6: int32) : int32) : std/time/timestamp/timestamp ) as @x@3@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@1@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@11: std/time/utc/leap-adjust)
//                    -> (match (@x@3@1) {
//                     ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0@0: float64) : float64, (@pat@1@0@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0@0: std/time/timestamp/timestamp)
//                        -> (match (@x@3@0) {
//                         ((@skip std/num/ddouble/Ddouble((@pat@0@1@1: float64) : float64, (@x@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@1: std/num/ddouble/ddouble)
//                            -> @x@1@1;
//                       });
//                   });
//               }), (match (end@10131) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4@0: float64) : float64, (@pat@1@1@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0@0: std/time/timestamp/timestamp)
//                    -> (match (@x@4@0) {
//                     ((@skip std/num/ddouble/Ddouble((@pat@0@2@1: float64) : float64, (@x@2@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@4@0: std/num/ddouble/ddouble)
//                        -> @x@2@1;
//                   });
//               }));
//           (ord: order)
//              -> ord;
//         })) {
//           ((std/core/types/Eq() : order ) as @pat@7@0: order)
//              -> val x@0@10008 : int;
//                 val y@0@10009 : int;
//             (match ((std/core/int/(==)(x@0@10008, y@0@10009))) {
//               ((std/core/types/True() : bool ) as @pat@8: bool)
//                  -> std/core/types/Eq;
//               ((@skip std/core/types/False() : bool ) as @pat@0@5@0: bool)
//                  -> (match ((std/core/int/(>)(x@0@10008, y@0@10009))) {
//                   ((std/core/types/True() : bool ) as @pat@1@2@0: bool)
//                      -> std/core/types/Gt;
//                   ((@skip std/core/types/False() : bool ) as @pat@2@2@0: bool)
//                      -> std/core/types/Lt;
//                 });
//             });
//           (ord@0: order)
//              -> ord@0;
//         };
//   std/core/int/(==)((match (x@10022) {
//       ((std/core/types/Lt() : order ) as @pat@10@2: order)
//          -> -1;
//       ((std/core/types/Eq() : order ) as @pat@0@6@0: order)
//          -> 0;
//       ((@skip std/core/types/Gt() : order ) as @pat@1@5: order)
//          -> 1;
//     }), 1);
// }

kk_std_core_types__list kk_std_time_utc__lift_extend_10650(kk_std_time_timestamp__timestamp end_10131, kk_std_core_types__list _uniq_xs_10518, kk_context_t* _ctx) { /* (end@10131 : utc-timestamp, list<leap-adjust>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10518, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(end_10131, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_time_utc__lift_extend_10651(end_10131, _uniq_xs_10518, _ctx);
  }
}

kk_std_time_utc__leaps_table kk_std_time_utc_extend(kk_std_time_utc__leaps_table leap1, kk_std_time_utc__leaps_table leap2, kk_context_t* _ctx) { /* (leap1 : leaps-table, leap2 : leaps-table) -> leaps-table */ 
  {
    struct kk_std_time_utc_Leaps_table* _con_x1725 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
    kk_std_time_instant__instant _pat_0_0 = _con_x1725->expire;
    kk_std_core_types__list _x = _con_x1725->adjusts;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(leap1, _ctx)) {
        kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(leap1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(leap1, _ctx);
      }
      return leap2;
    }
    {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _match_x1006;
      kk_std_core_types__list _x_x1726;
      {
        struct kk_std_time_utc_Leaps_table* _con_x1727 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
        kk_std_time_instant__instant _pat_0_0_0 = _con_x1727->expire;
        kk_std_core_types__list _x_0 = _con_x1727->adjusts;
        kk_std_core_types__list_dup(_x_0, _ctx);
        _x_x1726 = _x_0; /*list<std/time/utc/leap-adjust>*/
      }
      _match_x1006 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x1726, _ctx); /*list<10001>*/
      if (kk_std_core_types__is_Nil(_match_x1006, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(leap1, _ctx)) {
          kk_std_core_types__list_drop(_x, _ctx);
          kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(leap1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(leap1, _ctx);
        }
        return leap2;
      }
      {
        struct kk_std_core_types_Cons* _con_x1728 = kk_std_core_types__as_Cons(_match_x1006, _ctx);
        kk_box_t _box_x88 = _con_x1728->head;
        kk_std_time_utc__leap_adjust la = kk_std_time_utc__leap_adjust_unbox(_box_x88, KK_BORROWED, _ctx);
        struct kk_std_time_utc_Leap_adjust* _con_x1729 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
        kk_std_core_types__list _pat_5 = _con_x1728->tail;
        if kk_likely(kk_datatype_ptr_is_unique(_match_x1006, _ctx)) {
          kk_std_core_types__list_drop(_pat_5, _ctx);
          kk_datatype_ptr_free(_match_x1006, _ctx);
        }
        else {
          kk_std_time_utc__leap_adjust_dup(la, _ctx);
          kk_datatype_ptr_decref(_match_x1006, _ctx);
        }
        kk_std_num_ddouble__ddouble t_10133;
        bool _match_x1015;
        double _x_x1730;
        kk_std_core_types__optional _match_x1017 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x1017, _ctx)) {
          kk_box_t _box_x89 = _match_x1017._cons._Optional.value;
          double _uniq_frac_1144 = kk_double_unbox(_box_x89, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(_match_x1017, _ctx);
          _x_x1730 = _uniq_frac_1144; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1017, _ctx);
          _x_x1730 = 0x0p+0; /*float64*/
        }
        _match_x1015 = (_x_x1730 == (0x0p+0)); /*bool*/
        if (_match_x1015) {
          t_10133 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          kk_std_num_ddouble__ddouble _x_x1731 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
          kk_std_num_ddouble__ddouble _x_x1732;
          double _x_x1733;
          kk_std_core_types__optional _match_x1016 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x1016, _ctx)) {
            kk_box_t _box_x90 = _match_x1016._cons._Optional.value;
            double _uniq_frac_1144_0 = kk_double_unbox(_box_x90, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(_match_x1016, _ctx);
            _x_x1733 = _uniq_frac_1144_0; /*float64*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x1016, _ctx);
            _x_x1733 = 0x0p+0; /*float64*/
          }
          _x_x1732 = kk_std_num_ddouble__new_Ddouble(_x_x1733, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
          t_10133 = kk_std_num_ddouble__lp__plus__rp_(_x_x1731, _x_x1732, _ctx); /*std/num/ddouble/ddouble*/
        }
        kk_std_time_timestamp__timestamp end_10131;
        kk_std_num_ddouble__ddouble _x_x1734;
        kk_std_num_ddouble__ddouble _x_x1735;
        {
          struct kk_std_time_utc_Leap_adjust* _con_x1736 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
          kk_std_time_timestamp__timestamp _x_7 = _con_x1736->utc_start;
          kk_std_num_ddouble__ddouble _pat_2_9 = _con_x1736->offset;
          kk_std_time_timestamp__timestamp _pat_5_1 = _con_x1736->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_1 = _con_x1736->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x1737 = kk_std_time_timestamp__as_Timestamp(_x_7, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x1738 = kk_std_time_timestamp__as_Timestamp(_pat_5_1, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_7, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x1739 = kk_std_time_timestamp__as_Timestamp(_x_7, _ctx);
            kk_std_num_ddouble__ddouble _x_1_0 = _con_x1739->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_7, _ctx)) {
              kk_datatype_ptr_free(_x_7, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_7, _ctx);
            }
            _x_x1735 = _x_1_0; /*std/time/timestamp/timespan*/
          }
        }
        kk_std_num_ddouble__ddouble _x_x1740;
        double _x_x1741;
        double _x_x1742;
        {
          double _x_6 = t_10133.hi;
          _x_x1742 = _x_6; /*float64*/
        }
        _x_x1741 = (-_x_x1742); /*float64*/
        double _x_x1743;
        double _x_x1744;
        {
          double _x_0_0 = t_10133.lo;
          _x_x1744 = _x_0_0; /*float64*/
        }
        _x_x1743 = (-_x_x1744); /*float64*/
        _x_x1740 = kk_std_num_ddouble__new_Ddouble(_x_x1741, _x_x1743, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1734 = kk_std_num_ddouble__lp__plus__rp_(_x_x1735, _x_x1740, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x1745;
        {
          struct kk_std_time_utc_Leap_adjust* _con_x1746 = kk_std_time_utc__as_Leap_adjust(la, _ctx);
          kk_std_time_timestamp__timestamp _x_7_0 = _con_x1746->utc_start;
          kk_std_num_ddouble__ddouble _pat_2_9_0 = _con_x1746->offset;
          kk_std_time_timestamp__timestamp _pat_5_1_0 = _con_x1746->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_1_0 = _con_x1746->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x1747 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x1748 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(la, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_5_1_0, _ctx)) {
              kk_datatype_ptr_free(_pat_5_1_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_5_1_0, _ctx);
            }
            kk_datatype_ptr_free(la, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_7_0, _ctx);
            kk_datatype_ptr_decref(la, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x1749 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
            kk_std_num_ddouble__ddouble _pat_0_2_0 = _con_x1749->since;
            int32_t _x_2_0 = _con_x1749->leap32;
            if kk_likely(kk_datatype_ptr_is_unique(_x_7_0, _ctx)) {
              kk_datatype_ptr_free(_x_7_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_7_0, _ctx);
            }
            _x_x1745 = _x_2_0; /*int32*/
          }
        }
        end_10131 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1734, _x_x1745, _ctx); /*std/time/timestamp/timestamp*/
        kk_std_core_types__list _b_x91_92;
        kk_std_core_types__list _x_x1750;
        {
          struct kk_std_time_utc_Leaps_table* _con_x1751 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
          kk_std_time_instant__instant _pat_0_5 = _con_x1751->expire;
          kk_std_core_types__list _x_2 = _con_x1751->adjusts;
          kk_std_core_types__list_dup(_x_2, _ctx);
          _x_x1750 = _x_2; /*list<std/time/utc/leap-adjust>*/
        }
        _b_x91_92 = kk_std_time_utc__lift_extend_10650(end_10131, _x_x1750, _ctx); /*list<std/time/utc/leap-adjust>*/
        kk_std_core_types__optional _arg_x1615 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x91_92, _ctx), _ctx); /*? (list<std/time/utc/leap-adjust>)*/;
        kk_std_core_types__list _b_x97_98;
        {
          struct kk_std_time_utc_Leaps_table* _con_x1752 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
          kk_std_time_instant__instant _pat_0_3 = _con_x1752->expire;
          kk_std_core_types__list _x_0_2 = _con_x1752->adjusts;
          kk_std_core_types__list_dup(_x_0_2, _ctx);
          if (kk_std_core_types__is_Nil(_x_0_2, _ctx)) {
            kk_std_time_instant__instant _match_x1013;
            kk_std_core_types__optional _match_x1014 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x1014, _ctx)) {
              kk_box_t _box_x93 = _match_x1014._cons._Optional.value;
              kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x93, KK_BORROWED, _ctx);
              kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
              kk_std_core_types__optional_drop(_match_x1014, _ctx);
              _match_x1013 = _uniq_expire_375; /*std/time/instant/instant*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x1014, _ctx);
              {
                struct kk_std_time_utc_Leaps_table* _con_x1753 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
                kk_std_time_instant__instant _x_4_1 = _con_x1753->expire;
                kk_std_time_instant__instant_dup(_x_4_1, _ctx);
                _match_x1013 = _x_4_1; /*std/time/instant/instant*/
              }
            }
            kk_std_core_types__list _match_x1012;
            if (kk_std_core_types__is_Optional(_arg_x1615, _ctx)) {
              kk_box_t _box_x94 = _arg_x1615._cons._Optional.value;
              kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x94, KK_BORROWED, _ctx);
              kk_datatype_ptr_dropn(leap2, (KK_I32(3)), _ctx);
              kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
              kk_std_core_types__optional_drop(_arg_x1615, _ctx);
              _match_x1012 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
            }
            else {
              kk_std_core_types__optional_drop(_arg_x1615, _ctx);
              {
                struct kk_std_time_utc_Leaps_table* _con_x1754 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
                kk_std_time_instant__instant _pat_0_10 = _con_x1754->expire;
                kk_std_core_types__list _x_5_0 = _con_x1754->adjusts;
                if kk_likely(kk_datatype_ptr_is_unique(leap2, _ctx)) {
                  kk_std_time_instant__instant_drop(_pat_0_10, _ctx);
                  kk_datatype_ptr_free(leap2, _ctx);
                }
                else {
                  kk_std_core_types__list_dup(_x_5_0, _ctx);
                  kk_datatype_ptr_decref(leap2, _ctx);
                }
                _match_x1012 = _x_5_0; /*list<std/time/utc/leap-adjust>*/
              }
            }
            {
              kk_std_time_instant__instant_drop(_match_x1013, _ctx);
              _b_x97_98 = _match_x1012; /*list<std/time/utc/leap-adjust>*/
            }
          }
          else {
            kk_std_core_types__list_drop(_x_0_2, _ctx);
            kk_std_core_types__list _x_x1755;
            {
              struct kk_std_time_utc_Leaps_table* _con_x1756 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
              kk_std_time_instant__instant _pat_0_3_1 = _con_x1756->expire;
              kk_std_core_types__list _x_0_3 = _con_x1756->adjusts;
              kk_std_core_types__list_dup(_x_0_3, _ctx);
              _x_x1755 = _x_0_3; /*list<std/time/utc/leap-adjust>*/
            }
            kk_std_core_types__list _x_x1757;
            kk_std_time_instant__instant _match_x1010;
            kk_std_core_types__optional _match_x1011 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x1011, _ctx)) {
              kk_box_t _box_x95 = _match_x1011._cons._Optional.value;
              kk_std_time_instant__instant _uniq_expire_375_0 = kk_std_time_instant__instant_unbox(_box_x95, KK_BORROWED, _ctx);
              kk_std_time_instant__instant_dup(_uniq_expire_375_0, _ctx);
              kk_std_core_types__optional_drop(_match_x1011, _ctx);
              _match_x1010 = _uniq_expire_375_0; /*std/time/instant/instant*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x1011, _ctx);
              {
                struct kk_std_time_utc_Leaps_table* _con_x1758 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
                kk_std_time_instant__instant _x_4_1_0 = _con_x1758->expire;
                kk_std_time_instant__instant_dup(_x_4_1_0, _ctx);
                _match_x1010 = _x_4_1_0; /*std/time/instant/instant*/
              }
            }
            kk_std_core_types__list _match_x1009;
            if (kk_std_core_types__is_Optional(_arg_x1615, _ctx)) {
              kk_box_t _box_x96 = _arg_x1615._cons._Optional.value;
              kk_std_core_types__list _uniq_adjusts_383_0 = kk_std_core_types__list_unbox(_box_x96, KK_BORROWED, _ctx);
              kk_datatype_ptr_dropn(leap2, (KK_I32(3)), _ctx);
              kk_std_core_types__list_dup(_uniq_adjusts_383_0, _ctx);
              kk_std_core_types__optional_drop(_arg_x1615, _ctx);
              _match_x1009 = _uniq_adjusts_383_0; /*list<std/time/utc/leap-adjust>*/
            }
            else {
              kk_std_core_types__optional_drop(_arg_x1615, _ctx);
              {
                struct kk_std_time_utc_Leaps_table* _con_x1759 = kk_std_time_utc__as_Leaps_table(leap2, _ctx);
                kk_std_time_instant__instant _pat_0_10_0 = _con_x1759->expire;
                kk_std_core_types__list _x_5_0_0 = _con_x1759->adjusts;
                if kk_likely(kk_datatype_ptr_is_unique(leap2, _ctx)) {
                  kk_std_time_instant__instant_drop(_pat_0_10_0, _ctx);
                  kk_datatype_ptr_free(leap2, _ctx);
                }
                else {
                  kk_std_core_types__list_dup(_x_5_0_0, _ctx);
                  kk_datatype_ptr_decref(leap2, _ctx);
                }
                _match_x1009 = _x_5_0_0; /*list<std/time/utc/leap-adjust>*/
              }
            }
            {
              kk_std_time_instant__instant_drop(_match_x1010, _ctx);
              _x_x1757 = _match_x1009; /*list<std/time/utc/leap-adjust>*/
            }
            _b_x97_98 = kk_std_core_list__unroll_append_10004(_x_x1755, _x_x1757, _ctx); /*list<std/time/utc/leap-adjust>*/
          }
        }
        kk_std_time_instant__instant _x_x1760;
        kk_std_core_types__optional _match_x1008 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x1008, _ctx)) {
          kk_box_t _box_x99 = _match_x1008._cons._Optional.value;
          kk_std_time_instant__instant _uniq_expire_375_0_0 = kk_std_time_instant__instant_unbox(_box_x99, KK_BORROWED, _ctx);
          kk_std_time_instant__instant_dup(_uniq_expire_375_0_0, _ctx);
          kk_std_core_types__optional_drop(_match_x1008, _ctx);
          _x_x1760 = _uniq_expire_375_0_0; /*std/time/instant/instant*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1008, _ctx);
          {
            struct kk_std_time_utc_Leaps_table* _con_x1761 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
            kk_std_time_instant__instant _x_8 = _con_x1761->expire;
            kk_std_time_instant__instant_dup(_x_8, _ctx);
            _x_x1760 = _x_8; /*std/time/instant/instant*/
          }
        }
        kk_std_core_types__list _x_x1762;
        kk_std_core_types__optional _match_x1007 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x97_98, _ctx), _ctx); /*? 10003*/;
        if (kk_std_core_types__is_Optional(_match_x1007, _ctx)) {
          kk_box_t _box_x100 = _match_x1007._cons._Optional.value;
          kk_std_core_types__list _uniq_adjusts_383_0_0 = kk_std_core_types__list_unbox(_box_x100, KK_BORROWED, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(leap1, _ctx)) {
            kk_std_core_types__list_drop(_x, _ctx);
            kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
            kk_datatype_ptr_free(leap1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(leap1, _ctx);
          }
          kk_std_core_types__list_dup(_uniq_adjusts_383_0_0, _ctx);
          kk_std_core_types__optional_drop(_match_x1007, _ctx);
          _x_x1762 = _uniq_adjusts_383_0_0; /*list<std/time/utc/leap-adjust>*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1007, _ctx);
          {
            struct kk_std_time_utc_Leaps_table* _con_x1763 = kk_std_time_utc__as_Leaps_table(leap1, _ctx);
            kk_std_time_instant__instant _pat_0_16 = _con_x1763->expire;
            kk_std_core_types__list _x_9 = _con_x1763->adjusts;
            if kk_likely(kk_datatype_ptr_is_unique(leap1, _ctx)) {
              kk_std_time_instant__instant_drop(_pat_0_16, _ctx);
              kk_datatype_ptr_free(leap1, _ctx);
            }
            else {
              kk_std_core_types__list_dup(_x_9, _ctx);
              kk_datatype_ptr_decref(leap1, _ctx);
            }
            _x_x1762 = _x_9; /*list<std/time/utc/leap-adjust>*/
          }
        }
        return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x1760, _x_x1762, _ctx);
      }
    }
  }
}
kk_declare_string_literal(static, kk_std_time_utc_default_iers_leap_seconds, 1125, "\n  # From: https://hpiers.obspm.fr/iers/bul/bulc/ntp/leap-seconds.list\n  #\tUpdated through IERS Bulletin C (https://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat)\n  # File expires on:  28 December 2024\n  #\n  #@\t3944332800\n  #\n  2272060800  10  # 1 Jan 1972\n  2287785600  11  # 1 Jul 1972\n  2303683200  12  # 1 Jan 1973\n  2335219200  13  # 1 Jan 1974\n  2366755200  14  # 1 Jan 1975\n  2398291200  15  # 1 Jan 1976\n  2429913600  16  # 1 Jan 1977\n  2461449600  17  # 1 Jan 1978\n  2492985600  18  # 1 Jan 1979\n  2524521600  19  # 1 Jan 1980\n  2571782400  20  # 1 Jul 1981\n  2603318400  21  # 1 Jul 1982\n  2634854400  22  # 1 Jul 1983\n  2698012800  23  # 1 Jul 1985\n  2776982400  24  # 1 Jan 1988\n  2840140800  25  # 1 Jan 1990\n  2871676800  26  # 1 Jan 1991\n  2918937600  27  # 1 Jul 1992\n  2950473600  28  # 1 Jul 1993\n  2982009600  29  # 1 Jul 1994\n  3029443200  30  # 1 Jan 1996\n  3076704000  31  # 1 Jul 1997\n  3124137600  32  # 1 Jan 1999\n  3345062400  33  # 1 Jan 2006\n  3439756800  34  # 1 Jan 2009\n  3550089600  35  # 1 Jul 2012\n  3644697600  36  # 1 Jul 2015\n  3692217600  37  # 1 Jan 2017\n  // 3723753600  35  # 1 Jan 2018")

kk_std_num_ddouble__ddouble kk_std_time_utc_jd_epoch_shift;
 
// JD to MJD

kk_std_num_ddouble__ddouble kk_std_time_utc_mjd_epoch_shift;
 
// monadic lift

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10787(kk_std_num_ddouble__ddouble ntpex, kk_context_t* _ctx) { /* (ntpex : std/num/ddouble/ddouble) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1768;
  double _x_x1769;
  double _x_x1770;
  kk_std_num_ddouble__ddouble _x_x1771 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1771.hi;
    _x_x1770 = _x; /*float64*/
  }
  _x_x1769 = (-_x_x1770); /*float64*/
  double _x_x1772;
  double _x_x1773;
  kk_std_num_ddouble__ddouble _x_x1774 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x1774.lo;
    _x_x1773 = _x_0; /*float64*/
  }
  _x_x1772 = (-_x_x1773); /*float64*/
  _x_x1768 = kk_std_num_ddouble__new_Ddouble(_x_x1769, _x_x1772, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(ntpex, _x_x1768, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_time_timestamp__timestamp x_1;
  int32_t _x_x1775;
  kk_integer_t _x_x1776;
  kk_std_core_types__optional _match_x1002 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1002, _ctx)) {
    kk_box_t _box_x103 = _match_x1002._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x103, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x1002, _ctx);
    _x_x1776 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1002, _ctx);
    _x_x1776 = kk_integer_from_small(0); /*int*/
  }
  _x_x1775 = kk_integer_clamp32(_x_x1776,kk_context()); /*int32*/
  x_1 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, x, _x_x1775, _ctx); /*std/time/timestamp/timestamp*/
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return x_1;
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10788_fun1778__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10788_fun1778(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10788_fun1778(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10788_fun1778, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10788_fun1778(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1779;
  kk_std_num_ddouble__ddouble _x_x1780 = kk_std_num_ddouble__ddouble_unbox(_b_x105, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1779 = kk_std_time_utc__mlift_pexpire_10787(_x_x1780, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1779, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10788(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild___1, _ctx);
  kk_std_num_ddouble__ddouble x_10827 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1777 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pexpire_10788_fun1778(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1777, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pexpire_10787(x_10827, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10789_fun1782__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10789_fun1782(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10789_fun1782(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10789_fun1782, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10789_fun1782(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1783;
  kk_string_t _x_x1784 = kk_string_unbox(_b_x108); /*string*/
  _x_x1783 = kk_std_time_utc__mlift_pexpire_10788(_x_x1784, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1783, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10789(kk_string_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild___0, _ctx);
  kk_string_t x_10829 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10829, _ctx);
    kk_box_t _x_x1781 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pexpire_10789_fun1782(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1781, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pexpire_10788(x_10829, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pexpire_10790_fun1788__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pexpire_10790_fun1788(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pexpire_10790_fun1788(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pexpire_10790_fun1788, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pexpire_10790_fun1788(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1789;
  kk_string_t _x_x1790 = kk_string_unbox(_b_x111); /*string*/
  _x_x1789 = kk_std_time_utc__mlift_pexpire_10789(_x_x1790, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1789, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10790(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild__, _ctx);
  kk_string_t x_10831;
  kk_string_t _x_x1785;
  kk_define_string_literal(, _s_x1786, 2, "#@", _ctx)
  _x_x1785 = kk_string_dup(_s_x1786, _ctx); /*string*/
  x_10831 = kk_std_text_parse_pstring(_x_x1785, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10831, _ctx);
    kk_box_t _x_x1787 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pexpire_10790_fun1788(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1787, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pexpire_10789(x_10831, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1792__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1792(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1792(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1792, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1792(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1793;
  kk_string_t _x_x1794 = kk_string_unbox(_b_x114); /*string*/
  _x_x1793 = kk_std_time_utc__mlift_pexpire_10790(_x_x1794, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1793, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1798__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1798(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1798(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1798, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1798(kk_function_t _fself, kk_box_t _b_x116, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1799;
  kk_string_t _x_x1800 = kk_string_unbox(_b_x116); /*string*/
  _x_x1799 = kk_std_time_utc__mlift_pexpire_10789(_x_x1800, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1799, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1802__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1802(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1802(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1802, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1802(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1803;
  kk_string_t _x_x1804 = kk_string_unbox(_b_x118); /*string*/
  _x_x1803 = kk_std_time_utc__mlift_pexpire_10788(_x_x1804, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1803, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pexpire_fun1806__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pexpire_fun1806(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pexpire_fun1806(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pexpire_fun1806, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pexpire_fun1806(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1807;
  kk_std_num_ddouble__ddouble _x_x1808 = kk_std_num_ddouble__ddouble_unbox(_b_x120, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1807 = kk_std_time_utc__mlift_pexpire_10787(_x_x1808, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1807, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc_pexpire(kk_context_t* _ctx) { /* () -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_t x_10833 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_string_drop(x_10833, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1791 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1792(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1791, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_10836;
    kk_string_t _x_x1795;
    kk_define_string_literal(, _s_x1796, 2, "#@", _ctx)
    _x_x1795 = kk_string_dup(_s_x1796, _ctx); /*string*/
    x_0_10836 = kk_std_text_parse_pstring(_x_x1795, _ctx); /*string*/
    kk_string_drop(x_0_10836, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1797 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1798(_ctx), _ctx); /*10001*/
      return kk_std_time_timestamp__timestamp_unbox(_x_x1797, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_10839 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
      kk_string_drop(x_1_10839, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1801 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1802(_ctx), _ctx); /*10001*/
        return kk_std_time_timestamp__timestamp_unbox(_x_x1801, KK_OWNED, _ctx);
      }
      {
        kk_std_num_ddouble__ddouble x_2_10842 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1805 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pexpire_fun1806(_ctx), _ctx); /*10001*/
          return kk_std_time_timestamp__timestamp_unbox(_x_x1805, KK_OWNED, _ctx);
        }
        {
          kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_num_ddouble__ddouble x_3;
          kk_std_num_ddouble__ddouble _x_x1809;
          double _x_x1810;
          double _x_x1811;
          kk_std_num_ddouble__ddouble _x_x1812 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
          {
            double _x = _x_x1812.hi;
            _x_x1811 = _x; /*float64*/
          }
          _x_x1810 = (-_x_x1811); /*float64*/
          double _x_x1813;
          double _x_x1814;
          kk_std_num_ddouble__ddouble _x_x1815 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
          {
            double _x_0 = _x_x1815.lo;
            _x_x1814 = _x_0; /*float64*/
          }
          _x_x1813 = (-_x_x1814); /*float64*/
          _x_x1809 = kk_std_num_ddouble__new_Ddouble(_x_x1810, _x_x1813, _ctx); /*std/num/ddouble/ddouble*/
          x_3 = kk_std_num_ddouble__lp__plus__rp_(x_2_10842, _x_x1809, _ctx); /*std/num/ddouble/ddouble*/
          kk_unit_t keep = kk_Unit;
          kk_evv_set(w,kk_context());
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_time_timestamp__timestamp x_5;
          int32_t _x_x1816;
          kk_integer_t _x_x1817;
          kk_std_core_types__optional _match_x998 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x998, _ctx)) {
            kk_box_t _box_x121 = _match_x998._cons._Optional.value;
            kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x121, _ctx);
            kk_integer_dup(_uniq_leap_1214, _ctx);
            kk_std_core_types__optional_drop(_match_x998, _ctx);
            _x_x1817 = _uniq_leap_1214; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x998, _ctx);
            _x_x1817 = kk_integer_from_small(0); /*int*/
          }
          _x_x1816 = kk_integer_clamp32(_x_x1817,kk_context()); /*int32*/
          x_5 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, x_3, _x_x1816, _ctx); /*std/time/timestamp/timestamp*/
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          return x_5;
        }
      }
    }
  }
}
 
// monadic lift

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_parse_expire_10791(kk_std_num_ddouble__ddouble ntpex, kk_context_t* _ctx) { /* (ntpex : std/num/ddouble/ddouble) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1818;
  double _x_x1819;
  double _x_x1820;
  kk_std_num_ddouble__ddouble _x_x1821 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1821.hi;
    _x_x1820 = _x; /*float64*/
  }
  _x_x1819 = (-_x_x1820); /*float64*/
  double _x_x1822;
  double _x_x1823;
  kk_std_num_ddouble__ddouble _x_x1824 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x1824.lo;
    _x_x1823 = _x_0; /*float64*/
  }
  _x_x1822 = (-_x_x1823); /*float64*/
  _x_x1818 = kk_std_num_ddouble__new_Ddouble(_x_x1819, _x_x1822, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(ntpex, _x_x1818, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_time_timestamp__timestamp x_1;
  int32_t _x_x1825;
  kk_integer_t _x_x1826;
  kk_std_core_types__optional _match_x993 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x993, _ctx)) {
    kk_box_t _box_x126 = _match_x993._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x126, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x993, _ctx);
    _x_x1826 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x993, _ctx);
    _x_x1826 = kk_integer_from_small(0); /*int*/
  }
  _x_x1825 = kk_integer_clamp32(_x_x1826,kk_context()); /*int32*/
  x_1 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, x, _x_x1825, _ctx); /*std/time/timestamp/timestamp*/
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return x_1;
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_parse_expire_10792_fun1828__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_parse_expire_10792_fun1828(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_parse_expire_10792_fun1828(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_parse_expire_10792_fun1828, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_parse_expire_10792_fun1828(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1829;
  kk_std_num_ddouble__ddouble _x_x1830 = kk_std_num_ddouble__ddouble_unbox(_b_x128, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1829 = kk_std_time_utc__mlift_parse_expire_10791(_x_x1830, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1829, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_parse_expire_10792(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild___1, _ctx);
  kk_std_num_ddouble__ddouble x_10857 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1827 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_parse_expire_10792_fun1828(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1827, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_parse_expire_10791(x_10857, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_parse_expire_10793_fun1832__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_parse_expire_10793_fun1832(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_parse_expire_10793_fun1832(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_parse_expire_10793_fun1832, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_parse_expire_10793_fun1832(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1833;
  kk_string_t _x_x1834 = kk_string_unbox(_b_x131); /*string*/
  _x_x1833 = kk_std_time_utc__mlift_parse_expire_10792(_x_x1834, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1833, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_parse_expire_10793(kk_string_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild___0, _ctx);
  kk_string_t x_10859 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10859, _ctx);
    kk_box_t _x_x1831 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_parse_expire_10793_fun1832(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1831, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_parse_expire_10792(x_10859, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_parse_expire_10794_fun1838__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_parse_expire_10794_fun1838(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_parse_expire_10794_fun1838(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_parse_expire_10794_fun1838, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_parse_expire_10794_fun1838(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1839;
  kk_string_t _x_x1840 = kk_string_unbox(_b_x134); /*string*/
  _x_x1839 = kk_std_time_utc__mlift_parse_expire_10793(_x_x1840, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1839, _ctx);
}

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_parse_expire_10794(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 
  kk_string_drop(wild__, _ctx);
  kk_string_t x_10861;
  kk_string_t _x_x1835;
  kk_define_string_literal(, _s_x1836, 2, "#@", _ctx)
  _x_x1835 = kk_string_dup(_s_x1836, _ctx); /*string*/
  x_10861 = kk_std_text_parse_pstring(_x_x1835, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10861, _ctx);
    kk_box_t _x_x1837 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_parse_expire_10794_fun1838(_ctx), _ctx); /*10001*/
    return kk_std_time_timestamp__timestamp_unbox(_x_x1837, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_parse_expire_10793(x_10861, _ctx);
  }
}
 
// val rxexpire = regex(r"^[ \t]*#@[ \t]*(\d+)[ \t]*(?:#.*)?$", multiLine=True)


// lift anonymous function
struct kk_std_time_utc_parse_expire_fun1856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_expire_fun1856(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_expire_fun1856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_expire_fun1856, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_utc_parse_expire_fun1859__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_expire_fun1859(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_expire_fun1859(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_expire_fun1859, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_parse_expire_fun1859(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x1860;
  kk_string_t _x_x1861 = kk_string_unbox(_b_x140); /*string*/
  _x_x1860 = kk_std_time_utc__mlift_parse_expire_10794(_x_x1861, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x1860, _ctx);
}
static kk_box_t kk_std_time_utc_parse_expire_fun1856(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_10863 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_std_time_timestamp__timestamp _x_x1857;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10863, _ctx);
    kk_box_t _x_x1858 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_parse_expire_fun1859(_ctx), _ctx); /*10001*/
    _x_x1857 = kk_std_time_timestamp__timestamp_unbox(_x_x1858, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
  }
  else {
    _x_x1857 = kk_std_time_utc__mlift_parse_expire_10794(x_10863, _ctx); /*std/time/timestamp/timestamp*/
  }
  return kk_std_time_timestamp__timestamp_box(_x_x1857, _ctx);
}

kk_std_core_types__maybe kk_std_time_utc_parse_expire(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> maybe<std/time/timestamp/timestamp> */ 
  kk_string_t s_10155;
  kk_string_t _x_x1841 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x1842;
  kk_define_string_literal(, _s_x1843, 1, " ", _ctx)
  _x_x1842 = kk_string_dup(_s_x1843, _ctx); /*string*/
  s_10155 = kk_std_core_sslice_trim_left(_x_x1841, _x_x1842, _ctx); /*string*/
  kk_std_core_types__maybe maybe_10154;
  bool _match_x989;
  kk_string_t _x_x1844 = kk_string_dup(s_10155, _ctx); /*string*/
  kk_string_t _x_x1845;
  kk_define_string_literal(, _s_x1846, 2, "#@", _ctx)
  _x_x1845 = kk_string_dup(_s_x1846, _ctx); /*string*/
  _match_x989 = kk_string_starts_with(_x_x1844,_x_x1845,kk_context()); /*bool*/
  if (_match_x989) {
    kk_integer_t x_10081;
    kk_string_t _x_x1847 = kk_string_dup(s_10155, _ctx); /*string*/
    x_10081 = kk_string_len_int(_x_x1847,kk_context()); /*int*/
    kk_integer_t y_10082;
    kk_string_t _x_x1848;
    kk_define_string_literal(, _s_x1849, 2, "#@", _ctx)
    _x_x1848 = kk_string_dup(_s_x1849, _ctx); /*string*/
    y_10082 = kk_string_len_int(_x_x1848,kk_context()); /*int*/
    kk_std_core_sslice__sslice _b_x136_137;
    kk_integer_t _x_x1850;
    kk_string_t _x_x1851;
    kk_define_string_literal(, _s_x1852, 2, "#@", _ctx)
    _x_x1851 = kk_string_dup(_s_x1852, _ctx); /*string*/
    _x_x1850 = kk_string_len_int(_x_x1851,kk_context()); /*int*/
    kk_integer_t _x_x1853 = kk_integer_sub(x_10081,y_10082,kk_context()); /*int*/
    _b_x136_137 = kk_std_core_sslice__new_Sslice(s_10155, _x_x1850, _x_x1853, _ctx); /*sslice/sslice*/
    maybe_10154 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x136_137, _ctx), _ctx); /*maybe<sslice/sslice>*/
  }
  else {
    kk_string_drop(s_10155, _ctx);
    maybe_10154 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
  }
  if (kk_std_core_types__is_Just(maybe_10154, _ctx)) {
    kk_box_t _box_x138 = maybe_10154._cons.Just.value;
    kk_std_core_types__maybe_drop(maybe_10154, _ctx);
    kk_std_core_sslice__sslice _b_x141_143;
    kk_string_t _x_x1854 = kk_string_dup(line, _ctx); /*string*/
    kk_integer_t _x_x1855 = kk_string_len_int(line,kk_context()); /*int*/
    _b_x141_143 = kk_std_core_sslice__new_Sslice(_x_x1854, kk_integer_from_small(0), _x_x1855, _ctx); /*sslice/sslice*/
    kk_std_text_parse__parse_error perr_10157 = kk_std_text_parse_parse(_b_x141_143, kk_std_time_utc_new_parse_expire_fun1856(_ctx), _ctx); /*std/text/parse/parse-error<std/time/timestamp/timestamp>*/;
    if (kk_std_text_parse__is_ParseOk(perr_10157, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x1862 = kk_std_text_parse__as_ParseOk(perr_10157, _ctx);
      kk_box_t _box_x146 = _con_x1862->result;
      kk_std_core_sslice__sslice _pat_0_0_0 = _con_x1862->rest;
      kk_std_time_timestamp__timestamp x_0 = kk_std_time_timestamp__timestamp_unbox(_box_x146, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10157, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(perr_10157, _ctx);
      }
      else {
        kk_std_time_timestamp__timestamp_dup(x_0, _ctx);
        kk_datatype_ptr_decref(perr_10157, _ctx);
      }
      return kk_std_core_types__new_Just(kk_std_time_timestamp__timestamp_box(x_0, _ctx), _ctx);
    }
    {
      struct kk_std_text_parse_ParseError* _con_x1863 = kk_std_text_parse__as_ParseError(perr_10157, _ctx);
      kk_std_core_sslice__sslice _pat_5 = _con_x1863->rest;
      kk_string_t msg = _con_x1863->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10157, _ctx)) {
        kk_string_drop(msg, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(perr_10157, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10157, _ctx);
      }
      return kk_std_core_types__new_Nothing(_ctx);
    }
  }
  {
    kk_string_drop(line, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// lifted local: @lift-parse-leap-expire@10652, parse-leap-expire, @spec-x10547
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10539, using:
// @uniq-f@10539 = std/time/utc/parse-expire

kk_std_core_types__list kk_std_time_utc__trmc_lift_parse_leap_expire_10653(kk_std_core_types__list _uniq_xs_10538, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<std/time/timestamp/timestamp>>) -> list<std/time/timestamp/timestamp> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10538, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1864 = kk_std_core_types__as_Cons(_uniq_xs_10538, _ctx);
    kk_box_t _box_x149 = _con_x1864->head;
    kk_std_core_types__list _uniq_xx_10542 = _con_x1864->tail;
    kk_string_t _uniq_x_10541 = kk_string_unbox(_box_x149);
    kk_reuse_t _ru_x1204 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10538, _ctx)) {
      _ru_x1204 = (kk_datatype_ptr_reuse(_uniq_xs_10538, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10541, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10542, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10538, _ctx);
    }
    kk_std_core_types__maybe _match_x987 = kk_std_time_utc_parse_expire(_uniq_x_10541, _ctx); /*maybe<std/time/timestamp/timestamp>*/;
    if (kk_std_core_types__is_Just(_match_x987, _ctx)) {
      kk_box_t _box_x150 = _match_x987._cons.Just.value;
      kk_std_time_timestamp__timestamp _uniq_y_10544 = kk_std_time_timestamp__timestamp_unbox(_box_x150, KK_BORROWED, _ctx);
      kk_std_time_timestamp__timestamp_dup(_uniq_y_10544, _ctx);
      kk_std_core_types__maybe_drop(_match_x987, _ctx);
      kk_std_core_types__list _trmc_x10674 = kk_datatype_null(); /*list<std/time/timestamp/timestamp>*/;
      kk_std_core_types__list _trmc_x10675 = kk_std_core_types__new_Cons(_ru_x1204, 0, kk_std_time_timestamp__timestamp_box(_uniq_y_10544, _ctx), _trmc_x10674, _ctx); /*list<std/time/timestamp/timestamp>*/;
      kk_field_addr_t _b_x160_165 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10675, _ctx)->tail, _ctx); /*@field-addr<list<std/time/timestamp/timestamp>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1865 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10675, _ctx)),_b_x160_165,kk_context()); /*ctx<0>*/
        _uniq_xs_10538 = _uniq_xx_10542;
        _acc = _x_x1865;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1204,kk_context());
      { // tailcall
        _uniq_xs_10538 = _uniq_xx_10542;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x1866 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1866, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-parse-leap-expire@10652, parse-leap-expire, @spec-x10547
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10539, using:
// @uniq-f@10539 = std/time/utc/parse-expire

kk_std_core_types__list kk_std_time_utc__lift_parse_leap_expire_10653(kk_std_core_types__list _uniq_xs_10538_0, kk_context_t* _ctx) { /* (list<string>) -> list<std/time/timestamp/timestamp> */ 
  kk_std_core_types__cctx _x_x1867 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_time_utc__trmc_lift_parse_leap_expire_10653(_uniq_xs_10538_0, _x_x1867, _ctx);
}
 
// lifted local: parse-leap-expire, @spec-x10537
// specialized: std/core/list/flatmap-maybe, on parameters @uniq-f@10534, using:
// @uniq-f@10534 = std/time/utc/parse-expire

kk_std_core_types__list kk_std_time_utc__lift_parse_leap_expire_10652(kk_std_core_types__list _uniq_xs_10533, kk_context_t* _ctx) { /* (list<string>) -> list<std/time/timestamp/timestamp> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10533, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x1868 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_std_time_utc__trmc_lift_parse_leap_expire_10653(_uniq_xs_10533, _x_x1868, _ctx);
  }
}

kk_std_time_instant__instant kk_std_time_utc_parse_leap_expire(kk_string_t leaps, kk_std_core_types__list adjusts, kk_context_t* _ctx) { /* (leaps : string, adjusts : list<leap-adjust>) -> std/time/instant/instant */ 
  kk_vector_t v_10019;
  kk_string_t _x_x1869;
  kk_define_string_literal(, _s_x1870, 1, "\n", _ctx)
  _x_x1869 = kk_string_dup(_s_x1870, _ctx); /*string*/
  v_10019 = kk_string_splitv(leaps,_x_x1869,kk_context()); /*vector<string>*/
  kk_std_core_types__list utc_expires;
  kk_std_core_types__list _x_x1871 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/
  utc_expires = kk_std_time_utc__lift_parse_leap_expire_10652(_x_x1871, _ctx); /*list<std/time/timestamp/timestamp>*/
  kk_integer_t seconds_10169 = kk_integer_mul((kk_integer_from_small(182)),(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble t_10167;
  bool _match_x984;
  double _x_x1872;
  kk_std_core_types__optional _match_x986 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x986, _ctx)) {
    kk_box_t _box_x171 = _match_x986._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x171, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x986, _ctx);
    _x_x1872 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x986, _ctx);
    _x_x1872 = 0x0p+0; /*float64*/
  }
  _match_x984 = (_x_x1872 == (0x0p+0)); /*bool*/
  if (_match_x984) {
    t_10167 = kk_std_num_ddouble_ddouble_int_exp(seconds_10169, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x1873 = kk_std_num_ddouble_ddouble_int_exp(seconds_10169, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1874;
    double _x_x1875;
    kk_std_core_types__optional _match_x985 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x985, _ctx)) {
      kk_box_t _box_x172 = _match_x985._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x172, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x985, _ctx);
      _x_x1875 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x985, _ctx);
      _x_x1875 = 0x0p+0; /*float64*/
    }
    _x_x1874 = kk_std_num_ddouble__new_Ddouble(_x_x1875, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_10167 = kk_std_num_ddouble__lp__plus__rp_(_x_x1873, _x_x1874, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_time_timestamp__timestamp nothing_0_10164;
  kk_std_num_ddouble__ddouble _x_x1876;
  kk_std_num_ddouble__ddouble _x_x1877;
  kk_std_time_utc__leap_adjust _match_x983;
  if (kk_std_core_types__is_Cons(adjusts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1878 = kk_std_core_types__as_Cons(adjusts, _ctx);
    kk_box_t _box_x173 = _con_x1878->head;
    kk_std_time_utc__leap_adjust x_0 = kk_std_time_utc__leap_adjust_unbox(_box_x173, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(x_0, _ctx);
    _match_x983 = x_0; /*std/time/utc/leap-adjust*/
  }
  else {
    _match_x983 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1879 = kk_std_time_utc__as_Leap_adjust(_match_x983, _ctx);
    kk_std_time_timestamp__timestamp _x_1 = _con_x1879->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_1 = _con_x1879->offset;
    kk_std_time_timestamp__timestamp _pat_5_0 = _con_x1879->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1879->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1880 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1881 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x983, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x983, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x983, _ctx);
    }
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1882 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1882->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1877 = _x; /*std/time/timestamp/timespan*/
    }
  }
  _x_x1876 = kk_std_num_ddouble__lp__plus__rp_(_x_x1877, t_10167, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1883;
  kk_std_time_utc__leap_adjust _match_x982;
  if (kk_std_core_types__is_Cons(adjusts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1884 = kk_std_core_types__as_Cons(adjusts, _ctx);
    kk_box_t _box_x175 = _con_x1884->head;
    kk_std_time_utc__leap_adjust x_0_0 = kk_std_time_utc__leap_adjust_unbox(_box_x175, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(x_0_0, _ctx);
    _match_x982 = x_0_0; /*std/time/utc/leap-adjust*/
  }
  else {
    _match_x982 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1885 = kk_std_time_utc__as_Leap_adjust(_match_x982, _ctx);
    kk_std_time_timestamp__timestamp _x_1_0 = _con_x1885->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_1_0 = _con_x1885->offset;
    kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x1885->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0 = _con_x1885->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1886 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1887 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x982, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_0_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_0_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x982, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(_match_x982, _ctx);
    }
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1888 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x1888->since;
      int32_t _x_0 = _con_x1888->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1883 = _x_0; /*int32*/
    }
  }
  nothing_0_10164 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1876, _x_x1883, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp ts_1_10173;
  kk_std_num_ddouble__ddouble _x_x1889;
  kk_std_num_ddouble__ddouble _x_x1890;
  kk_std_time_timestamp__timestamp _match_x981;
  if (kk_std_core_types__is_Cons(utc_expires, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1891 = kk_std_core_types__as_Cons(utc_expires, _ctx);
    kk_box_t _box_x177 = _con_x1891->head;
    kk_std_time_timestamp__timestamp x_2 = kk_std_time_timestamp__timestamp_unbox(_box_x177, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(x_2, _ctx);
    _match_x981 = x_2; /*std/time/timestamp/timestamp*/
  }
  else {
    _match_x981 = kk_std_time_timestamp__timestamp_dup(nothing_0_10164, _ctx); /*std/time/timestamp/timestamp*/
  }
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1892 = kk_std_time_timestamp__as_Timestamp(_match_x981, _ctx);
    kk_std_num_ddouble__ddouble _x_1_0_0 = _con_x1892->since;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x981, _ctx)) {
      kk_datatype_ptr_free(_match_x981, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x981, _ctx);
    }
    _x_x1890 = _x_1_0_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1893;
  double _x_x1894;
  double _x_x1895;
  kk_std_num_ddouble__ddouble _x_x1896 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x_2 = _x_x1896.hi;
    _x_x1895 = _x_2; /*float64*/
  }
  _x_x1894 = (-_x_x1895); /*float64*/
  double _x_x1897;
  double _x_x1898;
  kk_std_num_ddouble__ddouble _x_x1899 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x_0_0 = _x_x1899.lo;
    _x_x1898 = _x_0_0; /*float64*/
  }
  _x_x1897 = (-_x_x1898); /*float64*/
  _x_x1893 = kk_std_num_ddouble__new_Ddouble(_x_x1894, _x_x1897, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1889 = kk_std_num_ddouble__lp__plus__rp_(_x_x1890, _x_x1893, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1900;
  kk_std_time_timestamp__timestamp _match_x980;
  if (kk_std_core_types__is_Cons(utc_expires, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1901 = kk_std_core_types__as_Cons(utc_expires, _ctx);
    kk_box_t _box_x179 = _con_x1901->head;
    kk_std_core_types__list _pat_0_2_1_0 = _con_x1901->tail;
    kk_std_time_timestamp__timestamp x_2_0 = kk_std_time_timestamp__timestamp_unbox(_box_x179, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(utc_expires, _ctx)) {
      kk_std_core_types__list_drop(_pat_0_2_1_0, _ctx);
      kk_datatype_ptr_free(utc_expires, _ctx);
    }
    else {
      kk_std_time_timestamp__timestamp_dup(x_2_0, _ctx);
      kk_datatype_ptr_decref(utc_expires, _ctx);
    }
    kk_std_time_timestamp__timestamp_drop(nothing_0_10164, _ctx);
    _match_x980 = x_2_0; /*std/time/timestamp/timestamp*/
  }
  else {
    _match_x980 = nothing_0_10164; /*std/time/timestamp/timestamp*/
  }
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1902 = kk_std_time_timestamp__as_Timestamp(_match_x980, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_2_0 = _con_x1902->since;
    int32_t _x_2_0 = _con_x1902->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x980, _ctx)) {
      kk_datatype_ptr_free(_match_x980, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x980, _ctx);
    }
    _x_x1900 = _x_2_0; /*int32*/
  }
  ts_1_10173 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1889, _x_x1900, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp t_0_10172;
  kk_std_num_ddouble__ddouble _x_x1903;
  kk_std_num_ddouble__ddouble _x_x1904;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1905 = kk_std_time_timestamp__as_Timestamp(ts_1_10173, _ctx);
    kk_std_num_ddouble__ddouble _x_2_1 = _con_x1905->since;
    _x_x1904 = _x_2_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1906;
  kk_std_time_utc__leap_adjust _match_x979;
  if (kk_std_core_types__is_Cons(adjusts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1907 = kk_std_core_types__as_Cons(adjusts, _ctx);
    kk_box_t _box_x181 = _con_x1907->head;
    kk_std_core_types__list _pat_0_0_3 = _con_x1907->tail;
    kk_std_time_utc__leap_adjust x_0_1 = kk_std_time_utc__leap_adjust_unbox(_box_x181, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(adjusts, _ctx)) {
      kk_std_core_types__list_drop(_pat_0_0_3, _ctx);
      kk_datatype_ptr_free(adjusts, _ctx);
    }
    else {
      kk_std_time_utc__leap_adjust_dup(x_0_1, _ctx);
      kk_datatype_ptr_decref(adjusts, _ctx);
    }
    _match_x979 = x_0_1; /*std/time/utc/leap-adjust*/
  }
  else {
    _match_x979 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1908 = kk_std_time_utc__as_Leap_adjust(_match_x979, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_7_0 = _con_x1908->utc_start;
    kk_std_num_ddouble__ddouble _x_3 = _con_x1908->offset;
    kk_std_time_timestamp__timestamp _pat_5_1_0 = _con_x1908->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x1908->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1909 = kk_std_time_timestamp__as_Timestamp(_pat_0_7_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1910 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x979, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_5_1_0, _ctx)) {
        kk_datatype_ptr_free(_pat_5_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_5_1_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_0_7_0, _ctx)) {
        kk_datatype_ptr_free(_pat_0_7_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_0_7_0, _ctx);
      }
      kk_datatype_ptr_free(_match_x979, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x979, _ctx);
    }
    _x_x1906 = _x_3; /*std/time/timestamp/timespan*/
  }
  _x_x1903 = kk_std_num_ddouble__lp__plus__rp_(_x_x1904, _x_x1906, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1911;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1912 = kk_std_time_timestamp__as_Timestamp(ts_1_10173, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_2_0 = _con_x1912->since;
    int32_t _x_0_0_0 = _con_x1912->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts_1_10173, _ctx)) {
      kk_datatype_ptr_free(ts_1_10173, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts_1_10173, _ctx);
    }
    _x_x1911 = _x_0_0_0; /*int32*/
  }
  t_0_10172 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1903, _x_x1911, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1913 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_0_10172, _x_x1913, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10795_fun1922__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1922(kk_function_t _fself, kk_box_t _b_x186, kk_box_t _b_x187, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1922(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10795_fun1922, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1922(kk_function_t _fself, kk_box_t _b_x186, kk_box_t _b_x187, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1923;
  kk_std_num_ddouble__ddouble _x_x1924 = kk_std_num_ddouble__ddouble_unbox(_b_x186, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1925 = kk_std_num_ddouble__ddouble_unbox(_b_x187, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1923 = kk_std_num_ddouble__lp__star__rp_(_x_x1924, _x_x1925, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1923, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10795_fun1927__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1927(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1927(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10795_fun1927, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1927(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1928;
  kk_std_num_ddouble__ddouble _x_x1929 = kk_std_num_ddouble__ddouble_unbox(_b_x193, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1928 = kk_std_num_ddouble_round(_x_x1929, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1928, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10795_fun1940__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1940(kk_function_t _fself, kk_box_t _b_x200, kk_box_t _b_x201, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1940(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10795_fun1940, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1940(kk_function_t _fself, kk_box_t _b_x200, kk_box_t _b_x201, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1941;
  kk_std_num_ddouble__ddouble _x_x1942 = kk_std_num_ddouble__ddouble_unbox(_b_x200, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1943 = kk_std_num_ddouble__ddouble_unbox(_b_x201, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1941 = kk_std_num_ddouble__lp__star__rp_(_x_x1942, _x_x1943, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1941, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10795_fun1945__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1945(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1945(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10795_fun1945, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10795_fun1945(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x1946;
  kk_std_num_ddouble__ddouble _x_x1947 = kk_std_num_ddouble__ddouble_unbox(_b_x207, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1946 = kk_std_num_ddouble_round(_x_x1947, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x1946, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10795(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___10, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@10 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___10, _ctx);
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1914;
  double _x_x1915;
  double _x_x1916;
  kk_std_num_ddouble__ddouble _x_x1917 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
  {
    double _x_1 = _x_x1917.hi;
    _x_x1916 = _x_1; /*float64*/
  }
  _x_x1915 = (-_x_x1916); /*float64*/
  double _x_x1918;
  double _x_x1919;
  kk_std_num_ddouble__ddouble _x_x1920 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
  {
    double _x_0_0 = _x_x1920.lo;
    _x_x1919 = _x_0_0; /*float64*/
  }
  _x_x1918 = (-_x_x1919); /*float64*/
  _x_x1914 = kk_std_num_ddouble__new_Ddouble(_x_x1915, _x_x1918, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(mjd, _x_x1914, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_std_num_ddouble__ddouble _x_x1_1_10759;
  kk_box_t _x_x1921 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1922(_ctx), kk_std_num_ddouble__ddouble_box(x, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*10002*/
  _x_x1_1_10759 = kk_std_num_ddouble__ddouble_unbox(_x_x1921, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_0_10757;
  kk_box_t _x_x1926 = kk_std_core_hnd__open_none1(kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1927(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_1_10759, _ctx), _ctx); /*10001*/
  _x_x1_0_10757 = kk_std_num_ddouble__ddouble_unbox(_x_x1926, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_time_timestamp__timestamp x_1;
  int32_t _x_x1930;
  kk_integer_t _x_x1931;
  kk_std_core_types__optional _match_x978 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x978, _ctx)) {
    kk_box_t _box_x196 = _match_x978._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x196, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x978, _ctx);
    _x_x1931 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x978, _ctx);
    _x_x1931 = kk_integer_from_small(0); /*int*/
  }
  _x_x1930 = kk_integer_clamp32(_x_x1931,kk_context()); /*int32*/
  x_1 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1_0_10757, _x_x1930, _ctx); /*std/time/timestamp/timestamp*/
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x_2;
  kk_std_num_ddouble__ddouble _x_x1932;
  double _x_x1933;
  double _x_x1934;
  kk_std_num_ddouble__ddouble _x_x1935 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
  {
    double _x_2 = _x_x1935.hi;
    _x_x1934 = _x_2; /*float64*/
  }
  _x_x1933 = (-_x_x1934); /*float64*/
  double _x_x1936;
  double _x_x1937;
  kk_std_num_ddouble__ddouble _x_x1938 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
  {
    double _x_0_1 = _x_x1938.lo;
    _x_x1937 = _x_0_1; /*float64*/
  }
  _x_x1936 = (-_x_x1937); /*float64*/
  _x_x1932 = kk_std_num_ddouble__new_Ddouble(_x_x1933, _x_x1936, _ctx); /*std/num/ddouble/ddouble*/
  x_2 = kk_std_num_ddouble__lp__plus__rp_(dmjd, _x_x1932, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_std_num_ddouble__ddouble _x_x1_5_10766;
  kk_box_t _x_x1939 = kk_std_core_hnd__open_none2(kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1940(_ctx), kk_std_num_ddouble__ddouble_box(x_2, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*10002*/
  _x_x1_5_10766 = kk_std_num_ddouble__ddouble_unbox(_x_x1939, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1_4_10764;
  kk_box_t _x_x1944 = kk_std_core_hnd__open_none1(kk_std_time_utc__new_mlift_ptaiadjust_10795_fun1945(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_5_10766, _ctx), _ctx); /*10001*/
  _x_x1_4_10764 = kk_std_num_ddouble__ddouble_unbox(_x_x1944, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
  kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_time_timestamp__timestamp x_3;
  int32_t _x_x1948;
  kk_integer_t _x_x1949;
  kk_std_core_types__optional _match_x977 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x977, _ctx)) {
    kk_box_t _box_x210 = _match_x977._cons._Optional.value;
    kk_integer_t _uniq_leap_1214_0 = kk_integer_unbox(_box_x210, _ctx);
    kk_integer_dup(_uniq_leap_1214_0, _ctx);
    kk_std_core_types__optional_drop(_match_x977, _ctx);
    _x_x1949 = _uniq_leap_1214_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x977, _ctx);
    _x_x1949 = kk_integer_from_small(0); /*int*/
  }
  _x_x1948 = kk_integer_clamp32(_x_x1949,kk_context()); /*int32*/
  x_3 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1_4_10764, _x_x1948, _ctx); /*std/time/timestamp/timestamp*/
  kk_unit_t keep_2 = kk_Unit;
  kk_evv_set(w_2,kk_context());
  kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_3 = kk_Unit;
  kk_evv_set(w_3,kk_context());
  return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, x_1, ofs, x_3, drift, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10796_fun1951__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble drift;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10796_fun1951(kk_function_t _fself, kk_box_t _b_x212, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10796_fun1951(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10796_fun1951__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10796_fun1951__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10796_fun1951, kk_context());
  _self->dmjd = dmjd;
  _self->drift = drift;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10796_fun1951(kk_function_t _fself, kk_box_t _b_x212, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10796_fun1951__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10796_fun1951__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble drift = _self->drift; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(drift, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_string_t wild___10_214 = kk_string_unbox(_b_x212); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1952 = kk_std_time_utc__mlift_ptaiadjust_10795(dmjd, drift, mjd, ofs, wild___10_214, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1952, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10796(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___9, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@9 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___9, _ctx);
  kk_string_t x_10883 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10883, _ctx);
    kk_box_t _x_x1950 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10796_fun1951(dmjd, drift, mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1950, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10795(dmjd, drift, mjd, ofs, x_10883, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10797_fun1956__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble drift;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10797_fun1956(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10797_fun1956(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10797_fun1956__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10797_fun1956__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10797_fun1956, kk_context());
  _self->dmjd = dmjd;
  _self->drift = drift;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10797_fun1956(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10797_fun1956__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10797_fun1956__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble drift = _self->drift; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(drift, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_string_t wild___9_218 = kk_string_unbox(_b_x216); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1957 = kk_std_time_utc__mlift_ptaiadjust_10796(dmjd, drift, mjd, ofs, wild___9_218, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1957, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10797(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___8, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@8 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___8, _ctx);
  kk_string_t x_10885;
  kk_string_t _x_x1953;
  kk_define_string_literal(, _s_x1954, 1, "S", _ctx)
  _x_x1953 = kk_string_dup(_s_x1954, _ctx); /*string*/
  x_10885 = kk_std_text_parse_pstring(_x_x1953, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10885, _ctx);
    kk_box_t _x_x1955 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10797_fun1956(dmjd, drift, mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1955, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10796(dmjd, drift, mjd, ofs, x_10885, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10798_fun1959__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble drift;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10798_fun1959(kk_function_t _fself, kk_box_t _b_x220, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10798_fun1959(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10798_fun1959__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10798_fun1959__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10798_fun1959, kk_context());
  _self->dmjd = dmjd;
  _self->drift = drift;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10798_fun1959(kk_function_t _fself, kk_box_t _b_x220, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10798_fun1959__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10798_fun1959__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble drift = _self->drift; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(drift, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_string_t wild___8_222 = kk_string_unbox(_b_x220); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1960 = kk_std_time_utc__mlift_ptaiadjust_10797(dmjd, drift, mjd, ofs, wild___8_222, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1960, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10798(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_num_ddouble__ddouble drift, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_10887 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10887, _ctx);
    kk_box_t _x_x1958 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10798_fun1959(dmjd, drift, mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1958, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10797(dmjd, drift, mjd, ofs, x_10887, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10799_fun1962__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10799_fun1962(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10799_fun1962(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10799_fun1962__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10799_fun1962__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10799_fun1962, kk_context());
  _self->dmjd = dmjd;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10799_fun1962(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10799_fun1962__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10799_fun1962__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble drift_226 = kk_std_num_ddouble__ddouble_unbox(_b_x224, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1963 = kk_std_time_utc__mlift_ptaiadjust_10798(dmjd, mjd, ofs, drift_226, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1963, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10799(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_core_types__list _y_x10715, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, list<char>) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list_drop(_y_x10715, _ctx);
  kk_std_num_ddouble__ddouble x_10889 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1961 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10799_fun1962(dmjd, mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1961, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10798(dmjd, mjd, ofs, x_10889, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10800_fun1964__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10800_fun1964(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10800_fun1964(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10800_fun1964, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10800_fun1964(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1965 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x1965, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10800_fun1967__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10800_fun1967(kk_function_t _fself, kk_box_t _b_x232, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10800_fun1967(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10800_fun1967__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10800_fun1967__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10800_fun1967, kk_context());
  _self->dmjd = dmjd;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10800_fun1967(kk_function_t _fself, kk_box_t _b_x232, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10800_fun1967__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10800_fun1967__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10715_234 = kk_std_core_types__list_unbox(_b_x232, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x1968 = kk_std_time_utc__mlift_ptaiadjust_10799(dmjd, mjd, ofs, _y_x10715_234, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1968, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10800(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_char_t _y_x10714, kk_context_t* _ctx) { /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, char) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list x_10891 = kk_std_text_parse_many_acc(kk_std_time_utc__new_mlift_ptaiadjust_10800_fun1964(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10891, _ctx);
    kk_box_t _x_x1966 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10800_fun1967(dmjd, mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1966, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10799(dmjd, mjd, ofs, x_10891, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10801_fun1970__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble dmjd;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10801_fun1970(kk_function_t _fself, kk_box_t _b_x236, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10801_fun1970(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10801_fun1970__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10801_fun1970__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10801_fun1970, kk_context());
  _self->dmjd = dmjd;
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10801_fun1970(kk_function_t _fself, kk_box_t _b_x236, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10801_fun1970__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10801_fun1970__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble dmjd = _self->dmjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(dmjd, _ctx);kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_char_t _y_x10714_238 = kk_char_unbox(_b_x236, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x1971 = kk_std_time_utc__mlift_ptaiadjust_10800(dmjd, mjd, ofs, _y_x10714_238, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1971, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10801(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_num_ddouble__ddouble dmjd, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, dmjd : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_char_t x_10893 = kk_std_text_parse_no_digit(_ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1969 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10801_fun1970(dmjd, mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1969, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10800(dmjd, mjd, ofs, x_10893, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10802_fun1973__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10802_fun1973(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10802_fun1973(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10802_fun1973__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10802_fun1973__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10802_fun1973, kk_context());
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10802_fun1973(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10802_fun1973__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10802_fun1973__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble dmjd_242 = kk_std_num_ddouble__ddouble_unbox(_b_x240, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1974 = kk_std_time_utc__mlift_ptaiadjust_10801(mjd, ofs, dmjd_242, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1974, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10802(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_core_types__list _y_x10712, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, list<char>) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list_drop(_y_x10712, _ctx);
  kk_std_num_ddouble__ddouble x_10895 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1972 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10802_fun1973(mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1972, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10801(mjd, ofs, x_10895, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10803_fun1975__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10803_fun1975(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10803_fun1975(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10803_fun1975, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10803_fun1975(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x1976 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x1976, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10803_fun1978__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10803_fun1978(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10803_fun1978(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10803_fun1978__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10803_fun1978__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10803_fun1978, kk_context());
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10803_fun1978(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10803_fun1978__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10803_fun1978__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10712_250 = kk_std_core_types__list_unbox(_b_x248, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x1979 = kk_std_time_utc__mlift_ptaiadjust_10802(mjd, ofs, _y_x10712_250, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1979, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10803(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_char_t _y_x10711, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, char) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list x_10897 = kk_std_text_parse_many_acc(kk_std_time_utc__new_mlift_ptaiadjust_10803_fun1975(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10897, _ctx);
    kk_box_t _x_x1977 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10803_fun1978(mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1977, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10802(mjd, ofs, x_10897, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10804_fun1981__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
  kk_std_num_ddouble__ddouble ofs;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10804_fun1981(kk_function_t _fself, kk_box_t _b_x252, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10804_fun1981(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10804_fun1981__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10804_fun1981__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10804_fun1981, kk_context());
  _self->mjd = mjd;
  _self->ofs = ofs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10804_fun1981(kk_function_t _fself, kk_box_t _b_x252, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10804_fun1981__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10804_fun1981__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble ofs = _self->ofs; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);kk_std_num_ddouble__ddouble_dup(ofs, _ctx);}, {}, _ctx)
  kk_char_t _y_x10711_254 = kk_char_unbox(_b_x252, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x1982 = kk_std_time_utc__mlift_ptaiadjust_10803(mjd, ofs, _y_x10711_254, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1982, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10804(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_char_t x_10899 = kk_std_text_parse_no_digit(_ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1980 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10804_fun1981(mjd, ofs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1980, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10803(mjd, ofs, x_10899, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10805_fun1984__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10805_fun1984(kk_function_t _fself, kk_box_t _b_x256, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10805_fun1984(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10805_fun1984__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10805_fun1984__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10805_fun1984, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10805_fun1984(kk_function_t _fself, kk_box_t _b_x256, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10805_fun1984__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10805_fun1984__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble ofs_258 = kk_std_num_ddouble__ddouble_unbox(_b_x256, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x1985 = kk_std_time_utc__mlift_ptaiadjust_10804(mjd, ofs_258, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1985, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10805(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___5, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, wild_@5 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___5, _ctx);
  kk_std_num_ddouble__ddouble x_10901 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1983 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10805_fun1984(mjd, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1983, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10804(mjd, x_10901, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10806_fun1987__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10806_fun1987(kk_function_t _fself, kk_box_t _b_x260, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10806_fun1987(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10806_fun1987__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10806_fun1987__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10806_fun1987, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10806_fun1987(kk_function_t _fself, kk_box_t _b_x260, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10806_fun1987__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10806_fun1987__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___5_262 = kk_string_unbox(_b_x260); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1988 = kk_std_time_utc__mlift_ptaiadjust_10805(mjd, wild___5_262, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1988, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10806(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___4, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, wild_@4 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___4, _ctx);
  kk_string_t x_10903 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10903, _ctx);
    kk_box_t _x_x1986 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10806_fun1987(mjd, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1986, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10805(mjd, x_10903, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10807_fun1992__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble mjd;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10807_fun1992(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10807_fun1992(kk_std_num_ddouble__ddouble mjd, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10807_fun1992__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10807_fun1992__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10807_fun1992, kk_context());
  _self->mjd = mjd;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10807_fun1992(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10807_fun1992__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10807_fun1992__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble mjd = _self->mjd; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(mjd, _ctx);}, {}, _ctx)
  kk_string_t wild___4_266 = kk_string_unbox(_b_x264); /*string*/;
  kk_std_time_utc__leap_adjust _x_x1993 = kk_std_time_utc__mlift_ptaiadjust_10806(mjd, wild___4_266, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x1993, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10807(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___3, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, wild_@3 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___3, _ctx);
  kk_string_t x_10905;
  kk_string_t _x_x1989;
  kk_define_string_literal(, _s_x1990, 8, "TAI-UTC=", _ctx)
  _x_x1989 = kk_string_dup(_s_x1990, _ctx); /*string*/
  x_10905 = kk_std_text_parse_pstring(_x_x1989, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10905, _ctx);
    kk_box_t _x_x1991 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10807_fun1992(mjd, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x1991, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10806(mjd, x_10905, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10808_fun2002__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10808_fun2002(kk_function_t _fself, kk_box_t _b_x268, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10808_fun2002(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10808_fun2002__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_ptaiadjust_10808_fun2002__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_ptaiadjust_10808_fun2002, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10808_fun2002(kk_function_t _fself, kk_box_t _b_x268, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_ptaiadjust_10808_fun2002__t* _self = kk_function_as(struct kk_std_time_utc__mlift_ptaiadjust_10808_fun2002__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x = _self->x; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x, _ctx);}, {}, _ctx)
  kk_string_t wild___3_270 = kk_string_unbox(_b_x268); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2003 = kk_std_time_utc__mlift_ptaiadjust_10807(x, wild___3_270, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2003, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10808(kk_std_num_ddouble__ddouble _y_x10706, kk_context_t* _ctx) { /* (std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1994;
  double _x_x1995;
  double _x_x1996;
  kk_std_num_ddouble__ddouble _x_x1997 = kk_std_time_utc_jd_epoch_shift; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1997.hi;
    _x_x1996 = _x; /*float64*/
  }
  _x_x1995 = (-_x_x1996); /*float64*/
  double _x_x1998;
  double _x_x1999;
  kk_std_num_ddouble__ddouble _x_x2000 = kk_std_time_utc_jd_epoch_shift; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x2000.lo;
    _x_x1999 = _x_0; /*float64*/
  }
  _x_x1998 = (-_x_x1999); /*float64*/
  _x_x1994 = kk_std_num_ddouble__new_Ddouble(_x_x1995, _x_x1998, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(_y_x10706, _x_x1994, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t x_1_10910 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_1_10910, _ctx);
    kk_box_t _x_x2001 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10808_fun2002(x, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2001, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10807(x, x_1_10910, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10809_fun2005__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10809_fun2005(kk_function_t _fself, kk_box_t _b_x272, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10809_fun2005(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10809_fun2005, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10809_fun2005(kk_function_t _fself, kk_box_t _b_x272, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2006;
  kk_std_num_ddouble__ddouble _x_x2007 = kk_std_num_ddouble__ddouble_unbox(_b_x272, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2006 = kk_std_time_utc__mlift_ptaiadjust_10808(_x_x2007, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2006, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10809(kk_string_t wild___2, kk_context_t* _ctx) { /* (wild_@2 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___2, _ctx);
  kk_std_num_ddouble__ddouble x_10912 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2004 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10809_fun2005(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2004, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10808(x_10912, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10810_fun2009__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10810_fun2009(kk_function_t _fself, kk_box_t _b_x275, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10810_fun2009(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10810_fun2009, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10810_fun2009(kk_function_t _fself, kk_box_t _b_x275, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2010;
  kk_string_t _x_x2011 = kk_string_unbox(_b_x275); /*string*/
  _x_x2010 = kk_std_time_utc__mlift_ptaiadjust_10809(_x_x2011, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2010, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10810(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___1, _ctx);
  kk_string_t x_10914 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10914, _ctx);
    kk_box_t _x_x2008 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10810_fun2009(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2008, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10809(x_10914, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10811_fun2015__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10811_fun2015(kk_function_t _fself, kk_box_t _b_x278, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10811_fun2015(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10811_fun2015, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10811_fun2015(kk_function_t _fself, kk_box_t _b_x278, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2016;
  kk_string_t _x_x2017 = kk_string_unbox(_b_x278); /*string*/
  _x_x2016 = kk_std_time_utc__mlift_ptaiadjust_10810(_x_x2017, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2016, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10811(kk_std_core_types__list _y_x10703, kk_context_t* _ctx) { /* (list<char>) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list_drop(_y_x10703, _ctx);
  kk_string_t x_10916;
  kk_string_t _x_x2012;
  kk_define_string_literal(, _s_x2013, 3, "=JD", _ctx)
  _x_x2012 = kk_string_dup(_s_x2013, _ctx); /*string*/
  x_10916 = kk_std_text_parse_pstring(_x_x2012, _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10916, _ctx);
    kk_box_t _x_x2014 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10811_fun2015(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2014, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10810(x_10916, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10812_fun2018__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10812_fun2018(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10812_fun2018(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10812_fun2018, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10812_fun2018(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2019;
  kk_string_t _x_x2020;
  kk_define_string_literal(, _s_x2021, 1, "=", _ctx)
  _x_x2020 = kk_string_dup(_s_x2021, _ctx); /*string*/
  _x_x2019 = kk_std_text_parse_none_of(_x_x2020, _ctx); /*char*/
  return kk_char_box(_x_x2019, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10812_fun2023__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10812_fun2023(kk_function_t _fself, kk_box_t _b_x285, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10812_fun2023(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10812_fun2023, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10812_fun2023(kk_function_t _fself, kk_box_t _b_x285, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2024;
  kk_std_core_types__list _x_x2025 = kk_std_core_types__list_unbox(_b_x285, KK_OWNED, _ctx); /*list<char>*/
  _x_x2024 = kk_std_time_utc__mlift_ptaiadjust_10811(_x_x2025, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2024, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10812(kk_char_t _y_x10701, kk_context_t* _ctx) { /* (char) -> std/text/parse/parse leap-adjust */ 
  kk_std_core_types__list x_10918 = kk_std_text_parse_many_acc(kk_std_time_utc__new_mlift_ptaiadjust_10812_fun2018(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10918, _ctx);
    kk_box_t _x_x2022 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10812_fun2023(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2022, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10811(x_10918, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_ptaiadjust_10813_fun2029__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10813_fun2029(kk_function_t _fself, kk_box_t _b_x288, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_ptaiadjust_10813_fun2029(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_ptaiadjust_10813_fun2029, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_ptaiadjust_10813_fun2029(kk_function_t _fself, kk_box_t _b_x288, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2030;
  kk_char_t _x_x2031 = kk_char_unbox(_b_x288, KK_OWNED, _ctx); /*char*/
  _x_x2030 = kk_std_time_utc__mlift_ptaiadjust_10812(_x_x2031, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2030, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10813(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild__, _ctx);
  kk_char_t x_10920;
  kk_string_t _x_x2026;
  kk_define_string_literal(, _s_x2027, 1, "=", _ctx)
  _x_x2026 = kk_string_dup(_s_x2027, _ctx); /*string*/
  x_10920 = kk_std_text_parse_none_of(_x_x2026, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2028 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_ptaiadjust_10813_fun2029(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2028, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_ptaiadjust_10812(x_10920, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2033__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2033(kk_function_t _fself, kk_box_t _b_x291, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2033(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2033, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2033(kk_function_t _fself, kk_box_t _b_x291, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2034;
  kk_string_t _x_x2035 = kk_string_unbox(_b_x291); /*string*/
  _x_x2034 = kk_std_time_utc__mlift_ptaiadjust_10813(_x_x2035, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2034, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2039__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2039(kk_function_t _fself, kk_box_t _b_x293, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2039(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2039, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2039(kk_function_t _fself, kk_box_t _b_x293, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2040;
  kk_char_t _x_x2041 = kk_char_unbox(_b_x293, KK_OWNED, _ctx); /*char*/
  _x_x2040 = kk_std_time_utc__mlift_ptaiadjust_10812(_x_x2041, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2040, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2042__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2042(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2042(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2042, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2042(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2043;
  kk_string_t _x_x2044;
  kk_define_string_literal(, _s_x2045, 1, "=", _ctx)
  _x_x2044 = kk_string_dup(_s_x2045, _ctx); /*string*/
  _x_x2043 = kk_std_text_parse_none_of(_x_x2044, _ctx); /*char*/
  return kk_char_box(_x_x2043, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2047__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2047(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2047(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2047, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2047(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2048;
  kk_std_core_types__list _x_x2049 = kk_std_core_types__list_unbox(_b_x299, KK_OWNED, _ctx); /*list<char>*/
  _x_x2048 = kk_std_time_utc__mlift_ptaiadjust_10811(_x_x2049, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2048, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2053__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2053(kk_function_t _fself, kk_box_t _b_x301, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2053(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2053, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2053(kk_function_t _fself, kk_box_t _b_x301, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2054;
  kk_string_t _x_x2055 = kk_string_unbox(_b_x301); /*string*/
  _x_x2054 = kk_std_time_utc__mlift_ptaiadjust_10810(_x_x2055, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2054, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2057__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2057(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2057(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2057, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2057(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2058;
  kk_string_t _x_x2059 = kk_string_unbox(_b_x303); /*string*/
  _x_x2058 = kk_std_time_utc__mlift_ptaiadjust_10809(_x_x2059, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2058, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2061__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2061(kk_function_t _fself, kk_box_t _b_x305, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2061(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2061, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2061(kk_function_t _fself, kk_box_t _b_x305, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2062;
  kk_std_num_ddouble__ddouble _x_x2063 = kk_std_num_ddouble__ddouble_unbox(_b_x305, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2062 = kk_std_time_utc__mlift_ptaiadjust_10808(_x_x2063, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2062, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2072__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2072(kk_function_t _fself, kk_box_t _b_x307, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2072(kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2072__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2072__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2072, kk_context());
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2072(kk_function_t _fself, kk_box_t _b_x307, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2072__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2072__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_string_t wild___3_387 = kk_string_unbox(_b_x307); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2073 = kk_std_time_utc__mlift_ptaiadjust_10807(x_5, wild___3_387, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2073, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2077__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2077(kk_function_t _fself, kk_box_t _b_x309, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2077(kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2077__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2077__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2077, kk_context());
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2077(kk_function_t _fself, kk_box_t _b_x309, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2077__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2077__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_string_t wild___4_388 = kk_string_unbox(_b_x309); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2078 = kk_std_time_utc__mlift_ptaiadjust_10806(x_5, wild___4_388, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2078, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2080__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2080(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2080(kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2080__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2080__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2080, kk_context());
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2080(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2080__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2080__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_string_t wild___5_389 = kk_string_unbox(_b_x311); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2081 = kk_std_time_utc__mlift_ptaiadjust_10805(x_5, wild___5_389, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2081, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2083__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2083(kk_function_t _fself, kk_box_t _b_x313, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2083(kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2083__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2083__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2083, kk_context());
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2083(kk_function_t _fself, kk_box_t _b_x313, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2083__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2083__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble ofs_390 = kk_std_num_ddouble__ddouble_unbox(_b_x313, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x2084 = kk_std_time_utc__mlift_ptaiadjust_10804(x_5, ofs_390, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2084, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2086__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2086(kk_function_t _fself, kk_box_t _b_x315, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2086(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2086__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2086__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2086, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2086(kk_function_t _fself, kk_box_t _b_x315, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2086__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2086__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_char_t _y_x10711_391 = kk_char_unbox(_b_x315, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x2087 = kk_std_time_utc__mlift_ptaiadjust_10803(x_5, x_10_10952, _y_x10711_391, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2087, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2088__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2088(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2088(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2088, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2088(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2089 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x2089, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2091__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2091(kk_function_t _fself, kk_box_t _b_x321, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2091(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2091__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2091__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2091, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2091(kk_function_t _fself, kk_box_t _b_x321, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2091__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2091__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10712_392 = kk_std_core_types__list_unbox(_b_x321, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x2092 = kk_std_time_utc__mlift_ptaiadjust_10802(x_5, x_10_10952, _y_x10712_392, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2092, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2094__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2094(kk_function_t _fself, kk_box_t _b_x323, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2094(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2094__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2094__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2094, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2094(kk_function_t _fself, kk_box_t _b_x323, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2094__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2094__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble dmjd_393 = kk_std_num_ddouble__ddouble_unbox(_b_x323, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x2095 = kk_std_time_utc__mlift_ptaiadjust_10801(x_5, x_10_10952, dmjd_393, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2095, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2097__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_13_10961;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2097(kk_function_t _fself, kk_box_t _b_x325, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2097(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_13_10961, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2097__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2097__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2097, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_13_10961 = x_13_10961;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2097(kk_function_t _fself, kk_box_t _b_x325, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2097__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2097__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_13_10961 = _self->x_13_10961; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_10961, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_char_t _y_x10714_394 = kk_char_unbox(_b_x325, KK_OWNED, _ctx); /*char*/;
  kk_std_time_utc__leap_adjust _x_x2098 = kk_std_time_utc__mlift_ptaiadjust_10800(x_13_10961, x_5, x_10_10952, _y_x10714_394, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2098, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2099__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2099(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2099(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2099, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2099(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2100 = kk_std_text_parse_no_digit(_ctx); /*char*/
  return kk_char_box(_x_x2100, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2102__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_13_10961;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2102(kk_function_t _fself, kk_box_t _b_x331, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2102(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_13_10961, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2102__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2102__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2102, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_13_10961 = x_13_10961;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2102(kk_function_t _fself, kk_box_t _b_x331, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2102__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2102__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_13_10961 = _self->x_13_10961; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_10961, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10715_395 = kk_std_core_types__list_unbox(_b_x331, KK_OWNED, _ctx); /*list<char>*/;
  kk_std_time_utc__leap_adjust _x_x2103 = kk_std_time_utc__mlift_ptaiadjust_10799(x_13_10961, x_5, x_10_10952, _y_x10715_395, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2103, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2105__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_13_10961;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2105(kk_function_t _fself, kk_box_t _b_x333, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2105(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_13_10961, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2105__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2105__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2105, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_13_10961 = x_13_10961;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2105(kk_function_t _fself, kk_box_t _b_x333, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2105__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2105__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_13_10961 = _self->x_13_10961; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_10961, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble drift_396 = kk_std_num_ddouble__ddouble_unbox(_b_x333, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leap_adjust _x_x2106 = kk_std_time_utc__mlift_ptaiadjust_10798(x_13_10961, x_5, x_10_10952, drift_396, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2106, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2108__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_13_10961;
  kk_std_num_ddouble__ddouble x_16_10970;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2108(kk_function_t _fself, kk_box_t _b_x335, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2108(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_13_10961, kk_std_num_ddouble__ddouble x_16_10970, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2108__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2108__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2108, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_13_10961 = x_13_10961;
  _self->x_16_10970 = x_16_10970;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2108(kk_function_t _fself, kk_box_t _b_x335, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2108__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2108__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_13_10961 = _self->x_13_10961; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_16_10970 = _self->x_16_10970; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_10961, _ctx);kk_std_num_ddouble__ddouble_dup(x_16_10970, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_string_t wild___8_397 = kk_string_unbox(_b_x335); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2109 = kk_std_time_utc__mlift_ptaiadjust_10797(x_13_10961, x_16_10970, x_5, x_10_10952, wild___8_397, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2109, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2113__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_13_10961;
  kk_std_num_ddouble__ddouble x_16_10970;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2113(kk_function_t _fself, kk_box_t _b_x337, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2113(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_13_10961, kk_std_num_ddouble__ddouble x_16_10970, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2113__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2113__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2113, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_13_10961 = x_13_10961;
  _self->x_16_10970 = x_16_10970;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2113(kk_function_t _fself, kk_box_t _b_x337, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2113__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2113__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_13_10961 = _self->x_13_10961; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_16_10970 = _self->x_16_10970; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_10961, _ctx);kk_std_num_ddouble__ddouble_dup(x_16_10970, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_string_t wild___9_398 = kk_string_unbox(_b_x337); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2114 = kk_std_time_utc__mlift_ptaiadjust_10796(x_13_10961, x_16_10970, x_5, x_10_10952, wild___9_398, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2114, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2116__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble x_10_10952;
  kk_std_num_ddouble__ddouble x_13_10961;
  kk_std_num_ddouble__ddouble x_16_10970;
  kk_std_num_ddouble__ddouble x_5;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2116(kk_function_t _fself, kk_box_t _b_x339, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2116(kk_std_num_ddouble__ddouble x_10_10952, kk_std_num_ddouble__ddouble x_13_10961, kk_std_num_ddouble__ddouble x_16_10970, kk_std_num_ddouble__ddouble x_5, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2116__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ptaiadjust_fun2116__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ptaiadjust_fun2116, kk_context());
  _self->x_10_10952 = x_10_10952;
  _self->x_13_10961 = x_13_10961;
  _self->x_16_10970 = x_16_10970;
  _self->x_5 = x_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2116(kk_function_t _fself, kk_box_t _b_x339, kk_context_t* _ctx) {
  struct kk_std_time_utc_ptaiadjust_fun2116__t* _self = kk_function_as(struct kk_std_time_utc_ptaiadjust_fun2116__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble x_10_10952 = _self->x_10_10952; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_13_10961 = _self->x_13_10961; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_16_10970 = _self->x_16_10970; /* std/num/ddouble/ddouble */
  kk_std_num_ddouble__ddouble x_5 = _self->x_5; /* std/num/ddouble/ddouble */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(x_10_10952, _ctx);kk_std_num_ddouble__ddouble_dup(x_13_10961, _ctx);kk_std_num_ddouble__ddouble_dup(x_16_10970, _ctx);kk_std_num_ddouble__ddouble_dup(x_5, _ctx);}, {}, _ctx)
  kk_string_t wild___10_399 = kk_string_unbox(_b_x339); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2117 = kk_std_time_utc__mlift_ptaiadjust_10795(x_13_10961, x_16_10970, x_5, x_10_10952, wild___10_399, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2117, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2126__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2126(kk_function_t _fself, kk_box_t _b_x343, kk_box_t _b_x344, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2126(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2126, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2126(kk_function_t _fself, kk_box_t _b_x343, kk_box_t _b_x344, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2127;
  kk_std_num_ddouble__ddouble _x_x2128 = kk_std_num_ddouble__ddouble_unbox(_b_x343, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2129 = kk_std_num_ddouble__ddouble_unbox(_b_x344, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2127 = kk_std_num_ddouble__lp__star__rp_(_x_x2128, _x_x2129, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2127, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2131__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2131(kk_function_t _fself, kk_box_t _b_x350, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2131(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2131, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2131(kk_function_t _fself, kk_box_t _b_x350, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2132;
  kk_std_num_ddouble__ddouble _x_x2133 = kk_std_num_ddouble__ddouble_unbox(_b_x350, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2132 = kk_std_num_ddouble_round(_x_x2133, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2132, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2144__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2144(kk_function_t _fself, kk_box_t _b_x357, kk_box_t _b_x358, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2144(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2144, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2144(kk_function_t _fself, kk_box_t _b_x357, kk_box_t _b_x358, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2145;
  kk_std_num_ddouble__ddouble _x_x2146 = kk_std_num_ddouble__ddouble_unbox(_b_x357, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2147 = kk_std_num_ddouble__ddouble_unbox(_b_x358, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2145 = kk_std_num_ddouble__lp__star__rp_(_x_x2146, _x_x2147, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2145, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ptaiadjust_fun2149__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ptaiadjust_fun2149(kk_function_t _fself, kk_box_t _b_x364, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ptaiadjust_fun2149(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ptaiadjust_fun2149, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ptaiadjust_fun2149(kk_function_t _fself, kk_box_t _b_x364, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2150;
  kk_std_num_ddouble__ddouble _x_x2151 = kk_std_num_ddouble__ddouble_unbox(_b_x364, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2150 = kk_std_num_ddouble_round(_x_x2151, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2150, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc_ptaiadjust(kk_context_t* _ctx) { /* () -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_10922 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_string_drop(x_10922, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2032 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2033(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2032, KK_OWNED, _ctx);
  }
  {
    kk_char_t x_0_10925;
    kk_string_t _x_x2036;
    kk_define_string_literal(, _s_x2037, 1, "=", _ctx)
    _x_x2036 = kk_string_dup(_s_x2037, _ctx); /*string*/
    x_0_10925 = kk_std_text_parse_none_of(_x_x2036, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2038 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2039(_ctx), _ctx); /*10001*/
      return kk_std_time_utc__leap_adjust_unbox(_x_x2038, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list x_1_10928 = kk_std_text_parse_many_acc(kk_std_time_utc_new_ptaiadjust_fun2042(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
      kk_std_core_types__list_drop(x_1_10928, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2046 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2047(_ctx), _ctx); /*10001*/
        return kk_std_time_utc__leap_adjust_unbox(_x_x2046, KK_OWNED, _ctx);
      }
      {
        kk_string_t x_2_10931;
        kk_string_t _x_x2050;
        kk_define_string_literal(, _s_x2051, 3, "=JD", _ctx)
        _x_x2050 = kk_string_dup(_s_x2051, _ctx); /*string*/
        x_2_10931 = kk_std_text_parse_pstring(_x_x2050, _ctx); /*string*/
        kk_string_drop(x_2_10931, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x2052 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2053(_ctx), _ctx); /*10001*/
          return kk_std_time_utc__leap_adjust_unbox(_x_x2052, KK_OWNED, _ctx);
        }
        {
          kk_string_t x_3_10934 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
          kk_string_drop(x_3_10934, _ctx);
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x2056 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2057(_ctx), _ctx); /*10001*/
            return kk_std_time_utc__leap_adjust_unbox(_x_x2056, KK_OWNED, _ctx);
          }
          {
            kk_std_num_ddouble__ddouble x_4_10937 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x2060 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2061(_ctx), _ctx); /*10001*/
              return kk_std_time_utc__leap_adjust_unbox(_x_x2060, KK_OWNED, _ctx);
            }
            {
              kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
              kk_std_num_ddouble__ddouble x_5;
              kk_std_num_ddouble__ddouble _x_x2064;
              double _x_x2065;
              double _x_x2066;
              kk_std_num_ddouble__ddouble _x_x2067 = kk_std_time_utc_jd_epoch_shift; /*std/time/timestamp/timespan*/
              {
                double _x = _x_x2067.hi;
                _x_x2066 = _x; /*float64*/
              }
              _x_x2065 = (-_x_x2066); /*float64*/
              double _x_x2068;
              double _x_x2069;
              kk_std_num_ddouble__ddouble _x_x2070 = kk_std_time_utc_jd_epoch_shift; /*std/time/timestamp/timespan*/
              {
                double _x_0 = _x_x2070.lo;
                _x_x2069 = _x_0; /*float64*/
              }
              _x_x2068 = (-_x_x2069); /*float64*/
              _x_x2064 = kk_std_num_ddouble__new_Ddouble(_x_x2065, _x_x2068, _ctx); /*std/num/ddouble/ddouble*/
              x_5 = kk_std_num_ddouble__lp__plus__rp_(x_4_10937, _x_x2064, _ctx); /*std/num/ddouble/ddouble*/
              kk_unit_t keep = kk_Unit;
              kk_evv_set(w,kk_context());
              kk_string_t x_7_10943 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
              kk_string_drop(x_7_10943, _ctx);
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x2071 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2072(x_5, _ctx), _ctx); /*10001*/
                return kk_std_time_utc__leap_adjust_unbox(_x_x2071, KK_OWNED, _ctx);
              }
              {
                kk_string_t x_8_10946;
                kk_string_t _x_x2074;
                kk_define_string_literal(, _s_x2075, 8, "TAI-UTC=", _ctx)
                _x_x2074 = kk_string_dup(_s_x2075, _ctx); /*string*/
                x_8_10946 = kk_std_text_parse_pstring(_x_x2074, _ctx); /*string*/
                kk_string_drop(x_8_10946, _ctx);
                if (kk_yielding(kk_context())) {
                  kk_box_t _x_x2076 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2077(x_5, _ctx), _ctx); /*10001*/
                  return kk_std_time_utc__leap_adjust_unbox(_x_x2076, KK_OWNED, _ctx);
                }
                {
                  kk_string_t x_9_10949 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
                  kk_string_drop(x_9_10949, _ctx);
                  if (kk_yielding(kk_context())) {
                    kk_box_t _x_x2079 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2080(x_5, _ctx), _ctx); /*10001*/
                    return kk_std_time_utc__leap_adjust_unbox(_x_x2079, KK_OWNED, _ctx);
                  }
                  {
                    kk_std_num_ddouble__ddouble x_10_10952 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
                    if (kk_yielding(kk_context())) {
                      kk_box_t _x_x2082 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2083(x_5, _ctx), _ctx); /*10001*/
                      return kk_std_time_utc__leap_adjust_unbox(_x_x2082, KK_OWNED, _ctx);
                    }
                    {
                      kk_char_t x_11_10955 = kk_std_text_parse_no_digit(_ctx); /*char*/;
                      if (kk_yielding(kk_context())) {
                        kk_box_t _x_x2085 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2086(x_10_10952, x_5, _ctx), _ctx); /*10001*/
                        return kk_std_time_utc__leap_adjust_unbox(_x_x2085, KK_OWNED, _ctx);
                      }
                      {
                        kk_std_core_types__list x_12_10958 = kk_std_text_parse_many_acc(kk_std_time_utc_new_ptaiadjust_fun2088(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
                        kk_std_core_types__list_drop(x_12_10958, _ctx);
                        if (kk_yielding(kk_context())) {
                          kk_box_t _x_x2090 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2091(x_10_10952, x_5, _ctx), _ctx); /*10001*/
                          return kk_std_time_utc__leap_adjust_unbox(_x_x2090, KK_OWNED, _ctx);
                        }
                        {
                          kk_std_num_ddouble__ddouble x_13_10961 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
                          if (kk_yielding(kk_context())) {
                            kk_box_t _x_x2093 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2094(x_10_10952, x_5, _ctx), _ctx); /*10001*/
                            return kk_std_time_utc__leap_adjust_unbox(_x_x2093, KK_OWNED, _ctx);
                          }
                          {
                            kk_char_t x_14_10964 = kk_std_text_parse_no_digit(_ctx); /*char*/;
                            if (kk_yielding(kk_context())) {
                              kk_box_t _x_x2096 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2097(x_10_10952, x_13_10961, x_5, _ctx), _ctx); /*10001*/
                              return kk_std_time_utc__leap_adjust_unbox(_x_x2096, KK_OWNED, _ctx);
                            }
                            {
                              kk_std_core_types__list x_15_10967 = kk_std_text_parse_many_acc(kk_std_time_utc_new_ptaiadjust_fun2099(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
                              kk_std_core_types__list_drop(x_15_10967, _ctx);
                              if (kk_yielding(kk_context())) {
                                kk_box_t _x_x2101 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2102(x_10_10952, x_13_10961, x_5, _ctx), _ctx); /*10001*/
                                return kk_std_time_utc__leap_adjust_unbox(_x_x2101, KK_OWNED, _ctx);
                              }
                              {
                                kk_std_num_ddouble__ddouble x_16_10970 = kk_std_num_ddouble_pddouble(_ctx); /*std/num/ddouble/ddouble*/;
                                if (kk_yielding(kk_context())) {
                                  kk_box_t _x_x2104 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2105(x_10_10952, x_13_10961, x_5, _ctx), _ctx); /*10001*/
                                  return kk_std_time_utc__leap_adjust_unbox(_x_x2104, KK_OWNED, _ctx);
                                }
                                {
                                  kk_string_t x_17_10973 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
                                  kk_string_drop(x_17_10973, _ctx);
                                  if (kk_yielding(kk_context())) {
                                    kk_box_t _x_x2107 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2108(x_10_10952, x_13_10961, x_16_10970, x_5, _ctx), _ctx); /*10001*/
                                    return kk_std_time_utc__leap_adjust_unbox(_x_x2107, KK_OWNED, _ctx);
                                  }
                                  {
                                    kk_string_t x_18_10976;
                                    kk_string_t _x_x2110;
                                    kk_define_string_literal(, _s_x2111, 1, "S", _ctx)
                                    _x_x2110 = kk_string_dup(_s_x2111, _ctx); /*string*/
                                    x_18_10976 = kk_std_text_parse_pstring(_x_x2110, _ctx); /*string*/
                                    kk_string_drop(x_18_10976, _ctx);
                                    if (kk_yielding(kk_context())) {
                                      kk_box_t _x_x2112 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2113(x_10_10952, x_13_10961, x_16_10970, x_5, _ctx), _ctx); /*10001*/
                                      return kk_std_time_utc__leap_adjust_unbox(_x_x2112, KK_OWNED, _ctx);
                                    }
                                    {
                                      kk_string_t x_19_10979 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
                                      kk_string_drop(x_19_10979, _ctx);
                                      if (kk_yielding(kk_context())) {
                                        kk_box_t _x_x2115 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_ptaiadjust_fun2116(x_10_10952, x_13_10961, x_16_10970, x_5, _ctx), _ctx); /*10001*/
                                        return kk_std_time_utc__leap_adjust_unbox(_x_x2115, KK_OWNED, _ctx);
                                      }
                                      {
                                        kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                                        kk_std_num_ddouble__ddouble x_20;
                                        kk_std_num_ddouble__ddouble _x_x2118;
                                        double _x_x2119;
                                        double _x_x2120;
                                        kk_std_num_ddouble__ddouble _x_x2121 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
                                        {
                                          double _x_1 = _x_x2121.hi;
                                          _x_x2120 = _x_1; /*float64*/
                                        }
                                        _x_x2119 = (-_x_x2120); /*float64*/
                                        double _x_x2122;
                                        double _x_x2123;
                                        kk_std_num_ddouble__ddouble _x_x2124 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
                                        {
                                          double _x_0_0 = _x_x2124.lo;
                                          _x_x2123 = _x_0_0; /*float64*/
                                        }
                                        _x_x2122 = (-_x_x2123); /*float64*/
                                        _x_x2118 = kk_std_num_ddouble__new_Ddouble(_x_x2119, _x_x2122, _ctx); /*std/num/ddouble/ddouble*/
                                        x_20 = kk_std_num_ddouble__lp__plus__rp_(x_5, _x_x2118, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_unit_t keep_0 = kk_Unit;
                                        kk_evv_set(w_0,kk_context());
                                        kk_std_num_ddouble__ddouble _x_x1_1_10759;
                                        kk_box_t _x_x2125 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun2126(_ctx), kk_std_num_ddouble__ddouble_box(x_20, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*10002*/
                                        _x_x1_1_10759 = kk_std_num_ddouble__ddouble_unbox(_x_x2125, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_std_num_ddouble__ddouble _x_x1_0_10757;
                                        kk_box_t _x_x2130 = kk_std_core_hnd__open_none1(kk_std_time_utc_new_ptaiadjust_fun2131(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_1_10759, _ctx), _ctx); /*10001*/
                                        _x_x1_0_10757 = kk_std_num_ddouble__ddouble_unbox(_x_x2130, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
                                        kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                                        kk_std_time_timestamp__timestamp x_21;
                                        int32_t _x_x2134;
                                        kk_integer_t _x_x2135;
                                        kk_std_core_types__optional _match_x958 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
                                        if (kk_std_core_types__is_Optional(_match_x958, _ctx)) {
                                          kk_box_t _box_x353 = _match_x958._cons._Optional.value;
                                          kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x353, _ctx);
                                          kk_integer_dup(_uniq_leap_1214, _ctx);
                                          kk_std_core_types__optional_drop(_match_x958, _ctx);
                                          _x_x2135 = _uniq_leap_1214; /*int*/
                                        }
                                        else {
                                          kk_std_core_types__optional_drop(_match_x958, _ctx);
                                          _x_x2135 = kk_integer_from_small(0); /*int*/
                                        }
                                        _x_x2134 = kk_integer_clamp32(_x_x2135,kk_context()); /*int32*/
                                        x_21 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1_0_10757, _x_x2134, _ctx); /*std/time/timestamp/timestamp*/
                                        kk_unit_t keep_1 = kk_Unit;
                                        kk_evv_set(w_1,kk_context());
                                        kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                                        kk_std_num_ddouble__ddouble x_22;
                                        kk_std_num_ddouble__ddouble _x_x2136;
                                        double _x_x2137;
                                        double _x_x2138;
                                        kk_std_num_ddouble__ddouble _x_x2139 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
                                        {
                                          double _x_2 = _x_x2139.hi;
                                          _x_x2138 = _x_2; /*float64*/
                                        }
                                        _x_x2137 = (-_x_x2138); /*float64*/
                                        double _x_x2140;
                                        double _x_x2141;
                                        kk_std_num_ddouble__ddouble _x_x2142 = kk_std_time_utc_mjd_epoch_shift; /*std/time/timestamp/timespan*/
                                        {
                                          double _x_0_1 = _x_x2142.lo;
                                          _x_x2141 = _x_0_1; /*float64*/
                                        }
                                        _x_x2140 = (-_x_x2141); /*float64*/
                                        _x_x2136 = kk_std_num_ddouble__new_Ddouble(_x_x2137, _x_x2140, _ctx); /*std/num/ddouble/ddouble*/
                                        x_22 = kk_std_num_ddouble__lp__plus__rp_(x_13_10961, _x_x2136, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_unit_t keep_2 = kk_Unit;
                                        kk_evv_set(w_2,kk_context());
                                        kk_std_num_ddouble__ddouble _x_x1_5_10766;
                                        kk_box_t _x_x2143 = kk_std_core_hnd__open_none2(kk_std_time_utc_new_ptaiadjust_fun2144(_ctx), kk_std_num_ddouble__ddouble_box(x_22, _ctx), kk_std_num_ddouble__ddouble_box(kk_std_time_timestamp_solar_secs_per_day, _ctx), _ctx); /*10002*/
                                        _x_x1_5_10766 = kk_std_num_ddouble__ddouble_unbox(_x_x2143, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
                                        kk_std_num_ddouble__ddouble _x_x1_4_10764;
                                        kk_box_t _x_x2148 = kk_std_core_hnd__open_none1(kk_std_time_utc_new_ptaiadjust_fun2149(_ctx), kk_std_num_ddouble__ddouble_box(_x_x1_5_10766, _ctx), _ctx); /*10001*/
                                        _x_x1_4_10764 = kk_std_num_ddouble__ddouble_unbox(_x_x2148, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/
                                        kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                                        kk_std_time_timestamp__timestamp x_23;
                                        int32_t _x_x2152;
                                        kk_integer_t _x_x2153;
                                        kk_std_core_types__optional _match_x957 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
                                        if (kk_std_core_types__is_Optional(_match_x957, _ctx)) {
                                          kk_box_t _box_x367 = _match_x957._cons._Optional.value;
                                          kk_integer_t _uniq_leap_1214_0 = kk_integer_unbox(_box_x367, _ctx);
                                          kk_integer_dup(_uniq_leap_1214_0, _ctx);
                                          kk_std_core_types__optional_drop(_match_x957, _ctx);
                                          _x_x2153 = _uniq_leap_1214_0; /*int*/
                                        }
                                        else {
                                          kk_std_core_types__optional_drop(_match_x957, _ctx);
                                          _x_x2153 = kk_integer_from_small(0); /*int*/
                                        }
                                        _x_x2152 = kk_integer_clamp32(_x_x2153,kk_context()); /*int32*/
                                        x_23 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1_4_10764, _x_x2152, _ctx); /*std/time/timestamp/timestamp*/
                                        kk_unit_t keep_3 = kk_Unit;
                                        kk_evv_set(w_3,kk_context());
                                        kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                                        kk_unit_t keep_4 = kk_Unit;
                                        kk_evv_set(w_4,kk_context());
                                        return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, x_21, x_10_10952, x_23, x_16_10970, _ctx);
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


// lift anonymous function
struct kk_std_time_utc_parse_taiadjust_fun2156__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_taiadjust_fun2156(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_taiadjust_fun2156(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_taiadjust_fun2156, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_parse_taiadjust_fun2156(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2157 = kk_std_time_utc_ptaiadjust(_ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2157, _ctx);
}

kk_std_core_types__maybe kk_std_time_utc_parse_taiadjust(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> maybe<leap-adjust> */ 
  kk_std_core_sslice__sslice _b_x400_402;
  kk_string_t _x_x2154 = kk_string_dup(line, _ctx); /*string*/
  kk_integer_t _x_x2155 = kk_string_len_int(line,kk_context()); /*int*/
  _b_x400_402 = kk_std_core_sslice__new_Sslice(_x_x2154, kk_integer_from_small(0), _x_x2155, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10179 = kk_std_text_parse_parse_eof(_b_x400_402, kk_std_time_utc_new_parse_taiadjust_fun2156(_ctx), _ctx); /*std/text/parse/parse-error<std/time/utc/leap-adjust>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10179, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2158 = kk_std_text_parse__as_ParseOk(perr_10179, _ctx);
    kk_box_t _box_x404 = _con_x2158->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x2158->rest;
    kk_std_time_utc__leap_adjust x_0 = kk_std_time_utc__leap_adjust_unbox(_box_x404, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10179, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(perr_10179, _ctx);
    }
    else {
      kk_std_time_utc__leap_adjust_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_10179, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_time_utc__leap_adjust_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x2159 = kk_std_text_parse__as_ParseError(perr_10179, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2159->rest;
    kk_string_t msg = _con_x2159->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10179, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10179, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10179, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// lifted local: @lift-parse-leap-seconds-dat@10654, parse-leap-seconds-dat, @spec-x10562
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10554, using:
// @uniq-f@10554 = std/time/utc/parse-taiadjust

kk_std_core_types__list kk_std_time_utc__trmc_lift_parse_leap_seconds_dat_10655(kk_std_core_types__list _uniq_xs_10553, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<leap-adjust>>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10553, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2160 = kk_std_core_types__as_Cons(_uniq_xs_10553, _ctx);
    kk_box_t _box_x407 = _con_x2160->head;
    kk_std_core_types__list _uniq_xx_10557 = _con_x2160->tail;
    kk_string_t _uniq_x_10556 = kk_string_unbox(_box_x407);
    kk_reuse_t _ru_x1221 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10553, _ctx)) {
      _ru_x1221 = (kk_datatype_ptr_reuse(_uniq_xs_10553, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10556, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10557, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10553, _ctx);
    }
    kk_std_core_types__maybe _match_x937 = kk_std_time_utc_parse_taiadjust(_uniq_x_10556, _ctx); /*maybe<std/time/utc/leap-adjust>*/;
    if (kk_std_core_types__is_Just(_match_x937, _ctx)) {
      kk_box_t _box_x408 = _match_x937._cons.Just.value;
      kk_std_time_utc__leap_adjust _uniq_y_10559 = kk_std_time_utc__leap_adjust_unbox(_box_x408, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_uniq_y_10559, _ctx);
      kk_std_core_types__maybe_drop(_match_x937, _ctx);
      kk_std_core_types__list _trmc_x10676 = kk_datatype_null(); /*list<std/time/utc/leap-adjust>*/;
      kk_std_core_types__list _trmc_x10677 = kk_std_core_types__new_Cons(_ru_x1221, 0, kk_std_time_utc__leap_adjust_box(_uniq_y_10559, _ctx), _trmc_x10676, _ctx); /*list<std/time/utc/leap-adjust>*/;
      kk_field_addr_t _b_x418_423 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10677, _ctx)->tail, _ctx); /*@field-addr<list<std/time/utc/leap-adjust>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2161 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10677, _ctx)),_b_x418_423,kk_context()); /*ctx<0>*/
        _uniq_xs_10553 = _uniq_xx_10557;
        _acc = _x_x2161;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1221,kk_context());
      { // tailcall
        _uniq_xs_10553 = _uniq_xx_10557;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x2162 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2162, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-parse-leap-seconds-dat@10654, parse-leap-seconds-dat, @spec-x10562
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10554, using:
// @uniq-f@10554 = std/time/utc/parse-taiadjust

kk_std_core_types__list kk_std_time_utc__lift_parse_leap_seconds_dat_10655(kk_std_core_types__list _uniq_xs_10553_0, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  kk_std_core_types__cctx _x_x2163 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_time_utc__trmc_lift_parse_leap_seconds_dat_10655(_uniq_xs_10553_0, _x_x2163, _ctx);
}
 
// lifted local: parse-leap-seconds-dat, @spec-x10552
// specialized: std/core/list/flatmap-maybe, on parameters @uniq-f@10549, using:
// @uniq-f@10549 = std/time/utc/parse-taiadjust

kk_std_core_types__list kk_std_time_utc__lift_parse_leap_seconds_dat_10654(kk_std_core_types__list _uniq_xs_10548, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10548, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x2164 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_std_time_utc__trmc_lift_parse_leap_seconds_dat_10655(_uniq_xs_10548, _x_x2164, _ctx);
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

kk_std_time_utc__leaps_table kk_std_time_utc_parse_leap_seconds_dat(kk_string_t leaps, kk_context_t* _ctx) { /* (leaps : string) -> leaps-table */ 
  kk_vector_t v_10019;
  kk_string_t _x_x2165 = kk_string_dup(leaps, _ctx); /*string*/
  kk_string_t _x_x2166;
  kk_define_string_literal(, _s_x2167, 1, "\n", _ctx)
  _x_x2166 = kk_string_dup(_s_x2167, _ctx); /*string*/
  v_10019 = kk_string_splitv(_x_x2165,_x_x2166,kk_context()); /*vector<string>*/
  kk_std_core_types__list xs_10181;
  kk_std_core_types__list _x_x2168 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/
  xs_10181 = kk_std_time_utc__lift_parse_leap_seconds_dat_10654(_x_x2168, _ctx); /*list<std/time/utc/leap-adjust>*/
  kk_std_core_types__list adjusts;
  if (kk_std_core_types__is_Nil(xs_10181, _ctx)) {
    adjusts = kk_std_core_types__new_Nil(_ctx); /*list<std/time/utc/leap-adjust>*/
  }
  else {
    adjusts = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs_10181, _ctx); /*list<std/time/utc/leap-adjust>*/
  }
  kk_std_time_instant__instant expire;
  kk_std_core_types__list _x_x2169 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
  expire = kk_std_time_utc_parse_leap_expire(leaps, _x_x2169, _ctx); /*std/time/instant/instant*/
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx);
}
kk_declare_string_literal(static, kk_std_time_utc_default_leap_seconds_pre72, 2922, "\n  # from: Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.\n  1958 JAN  1 =JD 2436204.5     TAI-UTC= 0.0  S + (MJD - 36204.) X 0.00073458 S\n  1958 JAN 15 =JD 2436219.29167 TAI-UTC= 0.02 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB  5 =JD 2436240.29167 TAI-UTC= 0.04 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB 19 =JD 2436254.29167 TAI-UTC= 0.06 S + (MJD - 36204.) X 0.00073458 S\n  1958 APR  9 =JD 2436303.29167 TAI-UTC= 0.08 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUN 11 =JD 2436366.29167 TAI-UTC= 0.10 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL  2 =JD 2436387.29167 TAI-UTC= 0.12 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL 16 =JD 2436401.29167 TAI-UTC= 0.14 S + (MJD - 36204.) X 0.00073458 S\n  1958 OCT 22 =JD 2436499.29167 TAI-UTC= 0.16 S + (MJD - 36204.) X 0.00073458 S\n  1958 NOV 26 =JD 2436534.29167 TAI-UTC= 0.18 S + (MJD - 36204.) X 0.00073458 S\n  1958 DEC 24 =JD 2436562.29167 TAI-UTC= 0.20 S + (MJD - 36204.) X 0.00073458 S\n\n  1959 JAN  1 =JD 2436569.5     TAI-UTC= 0.4681220 S + (MJD - 36569.) X 0.000864 S\n  1959 JAN 28 =JD 2436597.29167 TAI-UTC= 0.4881220 S + (MJD - 36569.) X 0.000864 S\n  1959 FEB 25 =JD 2436625.29167 TAI-UTC= 0.5081220 S + (MJD - 36569.) X 0.000864 S\n  1959 APR  5 =JD 2436664.29167 TAI-UTC= 0.5281220 S + (MJD - 36569.) X 0.000864 S\n  1959 AUG 26 =JD 2436807.29167 TAI-UTC= 0.5481220 S + (MJD - 36569.) X 0.000864 S\n  1959 SEP 30 =JD 2436842.29167 TAI-UTC= 0.5681220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV  4 =JD 2436877.29167 TAI-UTC= 0.5881220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV 18 =JD 2436891.29167 TAI-UTC= 0.6081220 S + (MJD - 36569.) X 0.000864 S\n  1959 DEC 16 =JD 2436919.29167 TAI-UTC= 0.6281220 S + (MJD - 36569.) X 0.000864 S\n  1960 JAN  1 =JD 2436934.5     TAI-UTC= 0.9434820 S + (MJD - 36934.) X 0.001296 S\n\n  # from: https://maia.usno.navy.mil/ser7/tai-utc.dat\n  1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S\n  1961 AUG  1 =JD 2437512.5  TAI-UTC=   1.3728180 S + (MJD - 37300.) X 0.001296 S\n  1962 JAN  1 =JD 2437665.5  TAI-UTC=   1.8458580 S + (MJD - 37665.) X 0.0011232S\n  1963 NOV  1 =JD 2438334.5  TAI-UTC=   1.9458580 S + (MJD - 37665.) X 0.0011232S\n  1964 JAN  1 =JD 2438395.5  TAI-UTC=   3.2401300 S + (MJD - 38761.) X 0.001296 S\n  1964 APR  1 =JD 2438486.5  TAI-UTC=   3.3401300 S + (MJD - 38761.) X 0.001296 S\n  1964 SEP  1 =JD 2438639.5  TAI-UTC=   3.4401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JAN  1 =JD 2438761.5  TAI-UTC=   3.5401300 S + (MJD - 38761.) X 0.001296 S\n  1965 MAR  1 =JD 2438820.5  TAI-UTC=   3.6401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JUL  1 =JD 2438942.5  TAI-UTC=   3.7401300 S + (MJD - 38761.) X 0.001296 S\n  1965 SEP  1 =JD 2439004.5  TAI-UTC=   3.8401300 S + (MJD - 38761.) X 0.001296 S\n  1966 JAN  1 =JD 2439126.5  TAI-UTC=   4.3131700 S + (MJD - 39126.) X 0.002592 S\n  1968 FEB  1 =JD 2439887.5  TAI-UTC=   4.2131700 S + (MJD - 39126.) X 0.002592 S")
 
// lifted local: @lift-leaps-table-pre1972@10656, leaps-table-pre1972, @spec-x10577
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10569, using:
// @uniq-f@10569 = std/time/utc/parse-taiadjust

kk_std_core_types__list kk_std_time_utc__trmc_lift_leaps_table_pre1972_10657(kk_std_core_types__list _uniq_xs_10568, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<leap-adjust>>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10568, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2170 = kk_std_core_types__as_Cons(_uniq_xs_10568, _ctx);
    kk_box_t _box_x429 = _con_x2170->head;
    kk_std_core_types__list _uniq_xx_10572 = _con_x2170->tail;
    kk_string_t _uniq_x_10571 = kk_string_unbox(_box_x429);
    kk_reuse_t _ru_x1222 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10568, _ctx)) {
      _ru_x1222 = (kk_datatype_ptr_reuse(_uniq_xs_10568, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10571, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10572, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10568, _ctx);
    }
    kk_std_core_types__maybe _match_x936 = kk_std_time_utc_parse_taiadjust(_uniq_x_10571, _ctx); /*maybe<std/time/utc/leap-adjust>*/;
    if (kk_std_core_types__is_Just(_match_x936, _ctx)) {
      kk_box_t _box_x430 = _match_x936._cons.Just.value;
      kk_std_time_utc__leap_adjust _uniq_y_10574 = kk_std_time_utc__leap_adjust_unbox(_box_x430, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_uniq_y_10574, _ctx);
      kk_std_core_types__maybe_drop(_match_x936, _ctx);
      kk_std_core_types__list _trmc_x10678 = kk_datatype_null(); /*list<std/time/utc/leap-adjust>*/;
      kk_std_core_types__list _trmc_x10679 = kk_std_core_types__new_Cons(_ru_x1222, 0, kk_std_time_utc__leap_adjust_box(_uniq_y_10574, _ctx), _trmc_x10678, _ctx); /*list<std/time/utc/leap-adjust>*/;
      kk_field_addr_t _b_x440_445 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10679, _ctx)->tail, _ctx); /*@field-addr<list<std/time/utc/leap-adjust>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2171 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10679, _ctx)),_b_x440_445,kk_context()); /*ctx<0>*/
        _uniq_xs_10568 = _uniq_xx_10572;
        _acc = _x_x2171;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1222,kk_context());
      { // tailcall
        _uniq_xs_10568 = _uniq_xx_10572;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x2172 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2172, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-leaps-table-pre1972@10656, leaps-table-pre1972, @spec-x10577
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10569, using:
// @uniq-f@10569 = std/time/utc/parse-taiadjust

kk_std_core_types__list kk_std_time_utc__lift_leaps_table_pre1972_10657(kk_std_core_types__list _uniq_xs_10568_0, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  kk_std_core_types__cctx _x_x2173 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_time_utc__trmc_lift_leaps_table_pre1972_10657(_uniq_xs_10568_0, _x_x2173, _ctx);
}
 
// lifted local: leaps-table-pre1972, @spec-x10567
// specialized: std/core/list/flatmap-maybe, on parameters @uniq-f@10564, using:
// @uniq-f@10564 = std/time/utc/parse-taiadjust

kk_std_core_types__list kk_std_time_utc__lift_leaps_table_pre1972_10656(kk_std_core_types__list _uniq_xs_10563, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10563, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x2174 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_std_time_utc__trmc_lift_leaps_table_pre1972_10657(_uniq_xs_10563, _x_x2174, _ctx);
  }
}
 
// Leap second table upto (but not including) 1972-01-01 UTC

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_pre1972;
 
// monadic lift

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10814(kk_integer_t ntpsecs, kk_integer_t adjust, kk_context_t* _ctx) { /* (ntpsecs : int, adjust : int) -> std/text/parse/parse leap-adjust */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  bool _match_x933;
  double _x_x2183;
  kk_std_core_types__optional _match_x935 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x935, _ctx)) {
    kk_box_t _box_x451 = _match_x935._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x451, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x935, _ctx);
    _x_x2183 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x935, _ctx);
    _x_x2183 = 0x0p+0; /*float64*/
  }
  _match_x933 = (_x_x2183 == (0x0p+0)); /*bool*/
  if (_match_x933) {
    x = kk_std_num_ddouble_ddouble_int_exp(ntpsecs, kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2184 = kk_std_num_ddouble_ddouble_int_exp(ntpsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2185;
    double _x_x2186;
    kk_std_core_types__optional _match_x934 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x934, _ctx)) {
      kk_box_t _box_x452 = _match_x934._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x452, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x934, _ctx);
      _x_x2186 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x934, _ctx);
      _x_x2186 = 0x0p+0; /*float64*/
    }
    _x_x2185 = kk_std_num_ddouble__new_Ddouble(_x_x2186, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    x = kk_std_num_ddouble__lp__plus__rp_(_x_x2184, _x_x2185, _ctx); /*std/time/timestamp/timespan*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x_0;
  kk_std_num_ddouble__ddouble _x_x2187;
  double _x_x2188;
  double _x_x2189;
  kk_std_num_ddouble__ddouble _x_x2190 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x2190.hi;
    _x_x2189 = _x; /*float64*/
  }
  _x_x2188 = (-_x_x2189); /*float64*/
  double _x_x2191;
  double _x_x2192;
  kk_std_num_ddouble__ddouble _x_x2193 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x2193.lo;
    _x_x2192 = _x_0; /*float64*/
  }
  _x_x2191 = (-_x_x2192); /*float64*/
  _x_x2187 = kk_std_num_ddouble__new_Ddouble(_x_x2188, _x_x2191, _ctx); /*std/num/ddouble/ddouble*/
  x_0 = kk_std_num_ddouble__lp__plus__rp_(x, _x_x2187, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_time_timestamp__timestamp x_2;
  int32_t _x_x2194;
  kk_integer_t _x_x2195;
  kk_std_core_types__optional _match_x932 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x932, _ctx)) {
    kk_box_t _box_x453 = _match_x932._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x453, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x932, _ctx);
    _x_x2195 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x932, _ctx);
    _x_x2195 = kk_integer_from_small(0); /*int*/
  }
  _x_x2194 = kk_integer_clamp32(_x_x2195,kk_context()); /*int32*/
  x_2 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, x_0, _x_x2194, _ctx); /*std/time/timestamp/timestamp*/
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x_3;
  bool _match_x929;
  double _x_x2196;
  kk_std_core_types__optional _match_x931 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x931, _ctx)) {
    kk_box_t _box_x454 = _match_x931._cons._Optional.value;
    double _uniq_frac_1144_1 = kk_double_unbox(_box_x454, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x931, _ctx);
    _x_x2196 = _uniq_frac_1144_1; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x931, _ctx);
    _x_x2196 = 0x0p+0; /*float64*/
  }
  _match_x929 = (_x_x2196 == (0x0p+0)); /*bool*/
  if (_match_x929) {
    x_3 = kk_std_num_ddouble_ddouble_int_exp(adjust, kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2197 = kk_std_num_ddouble_ddouble_int_exp(adjust, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2198;
    double _x_x2199;
    kk_std_core_types__optional _match_x930 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x930, _ctx)) {
      kk_box_t _box_x455 = _match_x930._cons._Optional.value;
      double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x455, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x930, _ctx);
      _x_x2199 = _uniq_frac_1144_0_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x930, _ctx);
      _x_x2199 = 0x0p+0; /*float64*/
    }
    _x_x2198 = kk_std_num_ddouble__new_Ddouble(_x_x2199, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    x_3 = kk_std_num_ddouble__lp__plus__rp_(_x_x2197, _x_x2198, _ctx); /*std/time/timestamp/timespan*/
  }
  kk_unit_t keep_2 = kk_Unit;
  kk_evv_set(w_2,kk_context());
  kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_3 = kk_Unit;
  kk_evv_set(w_3,kk_context());
  kk_std_time_timestamp__timestamp _x_x2200 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, x_2, x_3, _x_x2200, kk_std_num_ddouble_zero, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10815_fun2202__t {
  struct kk_function_s _base;
  kk_integer_t ntpsecs;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10815_fun2202(kk_function_t _fself, kk_box_t _b_x457, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10815_fun2202(kk_integer_t ntpsecs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10815_fun2202__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_pleap_10815_fun2202__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_pleap_10815_fun2202, kk_context());
  _self->ntpsecs = ntpsecs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10815_fun2202(kk_function_t _fself, kk_box_t _b_x457, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10815_fun2202__t* _self = kk_function_as(struct kk_std_time_utc__mlift_pleap_10815_fun2202__t*, _fself, _ctx);
  kk_integer_t ntpsecs = _self->ntpsecs; /* int */
  kk_drop_match(_self, {kk_integer_dup(ntpsecs, _ctx);}, {}, _ctx)
  kk_integer_t adjust_459 = kk_integer_unbox(_b_x457, _ctx); /*int*/;
  kk_std_time_utc__leap_adjust _x_x2203 = kk_std_time_utc__mlift_pleap_10814(ntpsecs, adjust_459, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2203, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10815(kk_integer_t ntpsecs, kk_string_t wild___0, kk_context_t* _ctx) { /* (ntpsecs : int, wild_@0 : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild___0, _ctx);
  kk_integer_t x_11018 = kk_std_text_parse_pint(_ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11018, _ctx);
    kk_box_t _x_x2201 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pleap_10815_fun2202(ntpsecs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2201, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pleap_10814(ntpsecs, x_11018, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10816_fun2205__t {
  struct kk_function_s _base;
  kk_integer_t ntpsecs;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10816_fun2205(kk_function_t _fself, kk_box_t _b_x461, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10816_fun2205(kk_integer_t ntpsecs, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10816_fun2205__t* _self = kk_function_alloc_as(struct kk_std_time_utc__mlift_pleap_10816_fun2205__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__mlift_pleap_10816_fun2205, kk_context());
  _self->ntpsecs = ntpsecs;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10816_fun2205(kk_function_t _fself, kk_box_t _b_x461, kk_context_t* _ctx) {
  struct kk_std_time_utc__mlift_pleap_10816_fun2205__t* _self = kk_function_as(struct kk_std_time_utc__mlift_pleap_10816_fun2205__t*, _fself, _ctx);
  kk_integer_t ntpsecs = _self->ntpsecs; /* int */
  kk_drop_match(_self, {kk_integer_dup(ntpsecs, _ctx);}, {}, _ctx)
  kk_string_t wild___0_463 = kk_string_unbox(_b_x461); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2206 = kk_std_time_utc__mlift_pleap_10815(ntpsecs, wild___0_463, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2206, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10816(kk_integer_t ntpsecs, kk_context_t* _ctx) { /* (ntpsecs : int) -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_11020 = kk_std_text_parse_whitespace(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_11020, _ctx);
    kk_box_t _x_x2204 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pleap_10816_fun2205(ntpsecs, _ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2204, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pleap_10815(ntpsecs, x_11020, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_utc__mlift_pleap_10817_fun2208__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__mlift_pleap_10817_fun2208(kk_function_t _fself, kk_box_t _b_x465, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_mlift_pleap_10817_fun2208(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__mlift_pleap_10817_fun2208, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__mlift_pleap_10817_fun2208(kk_function_t _fself, kk_box_t _b_x465, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2209;
  kk_integer_t _x_x2210 = kk_integer_unbox(_b_x465, _ctx); /*int*/
  _x_x2209 = kk_std_time_utc__mlift_pleap_10816(_x_x2210, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2209, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10817(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse leap-adjust */ 
  kk_string_drop(wild__, _ctx);
  kk_integer_t x_11022 = kk_std_text_parse_pint(_ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_11022, _ctx);
    kk_box_t _x_x2207 = kk_std_core_hnd_yield_extend(kk_std_time_utc__new_mlift_pleap_10817_fun2208(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2207, KK_OWNED, _ctx);
  }
  {
    return kk_std_time_utc__mlift_pleap_10816(x_11022, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2212__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2212(kk_function_t _fself, kk_box_t _b_x468, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2212(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2212, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2212(kk_function_t _fself, kk_box_t _b_x468, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2213;
  kk_string_t _x_x2214 = kk_string_unbox(_b_x468); /*string*/
  _x_x2213 = kk_std_time_utc__mlift_pleap_10817(_x_x2214, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2213, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2216__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_pleap_fun2216(kk_function_t _fself, kk_box_t _b_x470, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2216(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_pleap_fun2216, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2216(kk_function_t _fself, kk_box_t _b_x470, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2217;
  kk_integer_t _x_x2218 = kk_integer_unbox(_b_x470, _ctx); /*int*/
  _x_x2217 = kk_std_time_utc__mlift_pleap_10816(_x_x2218, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2217, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2220__t {
  struct kk_function_s _base;
  kk_integer_t x_0_11027;
};
static kk_box_t kk_std_time_utc_pleap_fun2220(kk_function_t _fself, kk_box_t _b_x472, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2220(kk_integer_t x_0_11027, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2220__t* _self = kk_function_alloc_as(struct kk_std_time_utc_pleap_fun2220__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_pleap_fun2220, kk_context());
  _self->x_0_11027 = x_0_11027;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2220(kk_function_t _fself, kk_box_t _b_x472, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2220__t* _self = kk_function_as(struct kk_std_time_utc_pleap_fun2220__t*, _fself, _ctx);
  kk_integer_t x_0_11027 = _self->x_0_11027; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_0_11027, _ctx);}, {}, _ctx)
  kk_string_t wild___0_484 = kk_string_unbox(_b_x472); /*string*/;
  kk_std_time_utc__leap_adjust _x_x2221 = kk_std_time_utc__mlift_pleap_10815(x_0_11027, wild___0_484, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2221, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_pleap_fun2223__t {
  struct kk_function_s _base;
  kk_integer_t x_0_11027;
};
static kk_box_t kk_std_time_utc_pleap_fun2223(kk_function_t _fself, kk_box_t _b_x474, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_pleap_fun2223(kk_integer_t x_0_11027, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2223__t* _self = kk_function_alloc_as(struct kk_std_time_utc_pleap_fun2223__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_pleap_fun2223, kk_context());
  _self->x_0_11027 = x_0_11027;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_pleap_fun2223(kk_function_t _fself, kk_box_t _b_x474, kk_context_t* _ctx) {
  struct kk_std_time_utc_pleap_fun2223__t* _self = kk_function_as(struct kk_std_time_utc_pleap_fun2223__t*, _fself, _ctx);
  kk_integer_t x_0_11027 = _self->x_0_11027; /* int */
  kk_drop_match(_self, {kk_integer_dup(x_0_11027, _ctx);}, {}, _ctx)
  kk_integer_t adjust_485 = kk_integer_unbox(_b_x474, _ctx); /*int*/;
  kk_std_time_utc__leap_adjust _x_x2224 = kk_std_time_utc__mlift_pleap_10814(x_0_11027, adjust_485, _ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2224, _ctx);
}

kk_std_time_utc__leap_adjust kk_std_time_utc_pleap(kk_context_t* _ctx) { /* () -> std/text/parse/parse leap-adjust */ 
  kk_string_t x_11024 = kk_std_text_parse_whitespace0(_ctx); /*string*/;
  kk_string_drop(x_11024, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2211 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2212(_ctx), _ctx); /*10001*/
    return kk_std_time_utc__leap_adjust_unbox(_x_x2211, KK_OWNED, _ctx);
  }
  {
    kk_integer_t x_0_11027 = kk_std_text_parse_pint(_ctx); /*int*/;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_11027, _ctx);
      kk_box_t _x_x2215 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2216(_ctx), _ctx); /*10001*/
      return kk_std_time_utc__leap_adjust_unbox(_x_x2215, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_11030 = kk_std_text_parse_whitespace(_ctx); /*string*/;
      kk_string_drop(x_1_11030, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x2219 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2220(x_0_11027, _ctx), _ctx); /*10001*/
        return kk_std_time_utc__leap_adjust_unbox(_x_x2219, KK_OWNED, _ctx);
      }
      {
        kk_integer_t x_2_11033 = kk_std_text_parse_pint(_ctx); /*int*/;
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_2_11033, _ctx);
          kk_box_t _x_x2222 = kk_std_core_hnd_yield_extend(kk_std_time_utc_new_pleap_fun2223(x_0_11027, _ctx), _ctx); /*10001*/
          return kk_std_time_utc__leap_adjust_unbox(_x_x2222, KK_OWNED, _ctx);
        }
        {
          kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_num_ddouble__ddouble x_3;
          bool _match_x923;
          double _x_x2225;
          kk_std_core_types__optional _match_x925 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x925, _ctx)) {
            kk_box_t _box_x475 = _match_x925._cons._Optional.value;
            double _uniq_frac_1144 = kk_double_unbox(_box_x475, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(_match_x925, _ctx);
            _x_x2225 = _uniq_frac_1144; /*float64*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x925, _ctx);
            _x_x2225 = 0x0p+0; /*float64*/
          }
          _match_x923 = (_x_x2225 == (0x0p+0)); /*bool*/
          if (_match_x923) {
            x_3 = kk_std_num_ddouble_ddouble_int_exp(x_0_11027, kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
          }
          else {
            kk_std_num_ddouble__ddouble _x_x2226 = kk_std_num_ddouble_ddouble_int_exp(x_0_11027, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble _x_x2227;
            double _x_x2228;
            kk_std_core_types__optional _match_x924 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x924, _ctx)) {
              kk_box_t _box_x476 = _match_x924._cons._Optional.value;
              double _uniq_frac_1144_0 = kk_double_unbox(_box_x476, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(_match_x924, _ctx);
              _x_x2228 = _uniq_frac_1144_0; /*float64*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x924, _ctx);
              _x_x2228 = 0x0p+0; /*float64*/
            }
            _x_x2227 = kk_std_num_ddouble__new_Ddouble(_x_x2228, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            x_3 = kk_std_num_ddouble__lp__plus__rp_(_x_x2226, _x_x2227, _ctx); /*std/time/timestamp/timespan*/
          }
          kk_unit_t keep = kk_Unit;
          kk_evv_set(w,kk_context());
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_num_ddouble__ddouble x_4;
          kk_std_num_ddouble__ddouble _x_x2229;
          double _x_x2230;
          double _x_x2231;
          kk_std_num_ddouble__ddouble _x_x2232 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
          {
            double _x = _x_x2232.hi;
            _x_x2231 = _x; /*float64*/
          }
          _x_x2230 = (-_x_x2231); /*float64*/
          double _x_x2233;
          double _x_x2234;
          kk_std_num_ddouble__ddouble _x_x2235 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
          {
            double _x_0 = _x_x2235.lo;
            _x_x2234 = _x_0; /*float64*/
          }
          _x_x2233 = (-_x_x2234); /*float64*/
          _x_x2229 = kk_std_num_ddouble__new_Ddouble(_x_x2230, _x_x2233, _ctx); /*std/num/ddouble/ddouble*/
          x_4 = kk_std_num_ddouble__lp__plus__rp_(x_3, _x_x2229, _ctx); /*std/num/ddouble/ddouble*/
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_time_timestamp__timestamp x_6;
          int32_t _x_x2236;
          kk_integer_t _x_x2237;
          kk_std_core_types__optional _match_x922 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x922, _ctx)) {
            kk_box_t _box_x477 = _match_x922._cons._Optional.value;
            kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x477, _ctx);
            kk_integer_dup(_uniq_leap_1214, _ctx);
            kk_std_core_types__optional_drop(_match_x922, _ctx);
            _x_x2237 = _uniq_leap_1214; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x922, _ctx);
            _x_x2237 = kk_integer_from_small(0); /*int*/
          }
          _x_x2236 = kk_integer_clamp32(_x_x2237,kk_context()); /*int32*/
          x_6 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, x_4, _x_x2236, _ctx); /*std/time/timestamp/timestamp*/
          kk_unit_t keep_1 = kk_Unit;
          kk_evv_set(w_1,kk_context());
          kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_num_ddouble__ddouble x_7;
          bool _match_x919;
          double _x_x2238;
          kk_std_core_types__optional _match_x921 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x921, _ctx)) {
            kk_box_t _box_x478 = _match_x921._cons._Optional.value;
            double _uniq_frac_1144_1 = kk_double_unbox(_box_x478, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(_match_x921, _ctx);
            _x_x2238 = _uniq_frac_1144_1; /*float64*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x921, _ctx);
            _x_x2238 = 0x0p+0; /*float64*/
          }
          _match_x919 = (_x_x2238 == (0x0p+0)); /*bool*/
          if (_match_x919) {
            x_7 = kk_std_num_ddouble_ddouble_int_exp(x_2_11033, kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
          }
          else {
            kk_std_num_ddouble__ddouble _x_x2239 = kk_std_num_ddouble_ddouble_int_exp(x_2_11033, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
            kk_std_num_ddouble__ddouble _x_x2240;
            double _x_x2241;
            kk_std_core_types__optional _match_x920 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x920, _ctx)) {
              kk_box_t _box_x479 = _match_x920._cons._Optional.value;
              double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x479, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(_match_x920, _ctx);
              _x_x2241 = _uniq_frac_1144_0_0; /*float64*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x920, _ctx);
              _x_x2241 = 0x0p+0; /*float64*/
            }
            _x_x2240 = kk_std_num_ddouble__new_Ddouble(_x_x2241, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
            x_7 = kk_std_num_ddouble__lp__plus__rp_(_x_x2239, _x_x2240, _ctx); /*std/time/timestamp/timespan*/
          }
          kk_unit_t keep_2 = kk_Unit;
          kk_evv_set(w_2,kk_context());
          kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_unit_t keep_3 = kk_Unit;
          kk_evv_set(w_3,kk_context());
          kk_std_time_timestamp__timestamp _x_x2242 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
          return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, x_6, x_7, _x_x2242, kk_std_num_ddouble_zero, _ctx);
        }
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_utc_parse_leap_fun2258__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_parse_leap_fun2258(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_parse_leap_fun2258(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_parse_leap_fun2258, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_parse_leap_fun2258(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leap_adjust _x_x2259 = kk_std_time_utc_pleap(_ctx); /*std/time/utc/leap-adjust*/
  return kk_std_time_utc__leap_adjust_box(_x_x2259, _ctx);
}

kk_std_core_types__maybe kk_std_time_utc_parse_leap(kk_string_t line, kk_context_t* _ctx) { /* (line : string) -> maybe<leap-adjust> */ 
  kk_string_t s_10184;
  kk_string_t _x_x2243 = kk_string_dup(line, _ctx); /*string*/
  kk_string_t _x_x2244;
  kk_define_string_literal(, _s_x2245, 1, " ", _ctx)
  _x_x2244 = kk_string_dup(_s_x2245, _ctx); /*string*/
  s_10184 = kk_std_core_sslice_trim_left(_x_x2243, _x_x2244, _ctx); /*string*/
  kk_std_core_types__maybe maybe_10183;
  bool _match_x914;
  kk_string_t _x_x2246 = kk_string_dup(s_10184, _ctx); /*string*/
  kk_string_t _x_x2247;
  kk_define_string_literal(, _s_x2248, 1, "#", _ctx)
  _x_x2247 = kk_string_dup(_s_x2248, _ctx); /*string*/
  _match_x914 = kk_string_starts_with(_x_x2246,_x_x2247,kk_context()); /*bool*/
  if (_match_x914) {
    kk_integer_t x_10081;
    kk_string_t _x_x2249 = kk_string_dup(s_10184, _ctx); /*string*/
    x_10081 = kk_string_len_int(_x_x2249,kk_context()); /*int*/
    kk_integer_t y_10082;
    kk_string_t _x_x2250;
    kk_define_string_literal(, _s_x2251, 1, "#", _ctx)
    _x_x2250 = kk_string_dup(_s_x2251, _ctx); /*string*/
    y_10082 = kk_string_len_int(_x_x2250,kk_context()); /*int*/
    kk_std_core_sslice__sslice _b_x486_487;
    kk_integer_t _x_x2252;
    kk_string_t _x_x2253;
    kk_define_string_literal(, _s_x2254, 1, "#", _ctx)
    _x_x2253 = kk_string_dup(_s_x2254, _ctx); /*string*/
    _x_x2252 = kk_string_len_int(_x_x2253,kk_context()); /*int*/
    kk_integer_t _x_x2255 = kk_integer_sub(x_10081,y_10082,kk_context()); /*int*/
    _b_x486_487 = kk_std_core_sslice__new_Sslice(s_10184, _x_x2252, _x_x2255, _ctx); /*sslice/sslice*/
    maybe_10183 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x486_487, _ctx), _ctx); /*maybe<sslice/sslice>*/
  }
  else {
    kk_string_drop(s_10184, _ctx);
    maybe_10183 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
  }
  if (kk_std_core_types__is_Just(maybe_10183, _ctx)) {
    kk_box_t _box_x488 = maybe_10183._cons.Just.value;
    kk_std_core_types__maybe_drop(maybe_10183, _ctx);
    kk_string_drop(line, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x489_491;
    kk_string_t _x_x2256 = kk_string_dup(line, _ctx); /*string*/
    kk_integer_t _x_x2257 = kk_string_len_int(line,kk_context()); /*int*/
    _b_x489_491 = kk_std_core_sslice__new_Sslice(_x_x2256, kk_integer_from_small(0), _x_x2257, _ctx); /*sslice/sslice*/
    kk_std_text_parse__parse_error perr_10186 = kk_std_text_parse_parse(_b_x489_491, kk_std_time_utc_new_parse_leap_fun2258(_ctx), _ctx); /*std/text/parse/parse-error<std/time/utc/leap-adjust>*/;
    if (kk_std_text_parse__is_ParseOk(perr_10186, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2260 = kk_std_text_parse__as_ParseOk(perr_10186, _ctx);
      kk_box_t _box_x493 = _con_x2260->result;
      kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2260->rest;
      kk_std_time_utc__leap_adjust x_0 = kk_std_time_utc__leap_adjust_unbox(_box_x493, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10186, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(perr_10186, _ctx);
      }
      else {
        kk_std_time_utc__leap_adjust_dup(x_0, _ctx);
        kk_datatype_ptr_decref(perr_10186, _ctx);
      }
      return kk_std_core_types__new_Just(kk_std_time_utc__leap_adjust_box(x_0, _ctx), _ctx);
    }
    {
      struct kk_std_text_parse_ParseError* _con_x2261 = kk_std_text_parse__as_ParseError(perr_10186, _ctx);
      kk_std_core_sslice__sslice _pat_5 = _con_x2261->rest;
      kk_string_t msg = _con_x2261->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10186, _ctx)) {
        kk_string_drop(msg, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(perr_10186, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10186, _ctx);
      }
      return kk_std_core_types__new_Nothing(_ctx);
    }
  }
}
 
// lifted local: @lift-parse-leap-seconds@10658, parse-leap-seconds, @spec-x10592
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10584, using:
// @uniq-f@10584 = std/time/utc/parse-leap

kk_std_core_types__list kk_std_time_utc__trmc_lift_parse_leap_seconds_10659(kk_std_core_types__list _uniq_xs_10583, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<leap-adjust>>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10583, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2262 = kk_std_core_types__as_Cons(_uniq_xs_10583, _ctx);
    kk_box_t _box_x496 = _con_x2262->head;
    kk_std_core_types__list _uniq_xx_10587 = _con_x2262->tail;
    kk_string_t _uniq_x_10586 = kk_string_unbox(_box_x496);
    kk_reuse_t _ru_x1225 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10583, _ctx)) {
      _ru_x1225 = (kk_datatype_ptr_reuse(_uniq_xs_10583, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10586, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10587, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10583, _ctx);
    }
    kk_std_core_types__maybe _match_x913 = kk_std_time_utc_parse_leap(_uniq_x_10586, _ctx); /*maybe<std/time/utc/leap-adjust>*/;
    if (kk_std_core_types__is_Just(_match_x913, _ctx)) {
      kk_box_t _box_x497 = _match_x913._cons.Just.value;
      kk_std_time_utc__leap_adjust _uniq_y_10589 = kk_std_time_utc__leap_adjust_unbox(_box_x497, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_uniq_y_10589, _ctx);
      kk_std_core_types__maybe_drop(_match_x913, _ctx);
      kk_std_core_types__list _trmc_x10680 = kk_datatype_null(); /*list<std/time/utc/leap-adjust>*/;
      kk_std_core_types__list _trmc_x10681 = kk_std_core_types__new_Cons(_ru_x1225, 0, kk_std_time_utc__leap_adjust_box(_uniq_y_10589, _ctx), _trmc_x10680, _ctx); /*list<std/time/utc/leap-adjust>*/;
      kk_field_addr_t _b_x507_512 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10681, _ctx)->tail, _ctx); /*@field-addr<list<std/time/utc/leap-adjust>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2263 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10681, _ctx)),_b_x507_512,kk_context()); /*ctx<0>*/
        _uniq_xs_10583 = _uniq_xx_10587;
        _acc = _x_x2263;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1225,kk_context());
      { // tailcall
        _uniq_xs_10583 = _uniq_xx_10587;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x2264 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2264, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-parse-leap-seconds@10658, parse-leap-seconds, @spec-x10592
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10584, using:
// @uniq-f@10584 = std/time/utc/parse-leap

kk_std_core_types__list kk_std_time_utc__lift_parse_leap_seconds_10659(kk_std_core_types__list _uniq_xs_10583_0, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  kk_std_core_types__cctx _x_x2265 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_time_utc__trmc_lift_parse_leap_seconds_10659(_uniq_xs_10583_0, _x_x2265, _ctx);
}
 
// lifted local: parse-leap-seconds, @spec-x10582
// specialized: std/core/list/flatmap-maybe, on parameters @uniq-f@10579, using:
// @uniq-f@10579 = std/time/utc/parse-leap

kk_std_core_types__list kk_std_time_utc__lift_parse_leap_seconds_10658(kk_std_core_types__list _uniq_xs_10578, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10578, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x2266 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_std_time_utc__trmc_lift_parse_leap_seconds_10659(_uniq_xs_10578, _x_x2266, _ctx);
  }
}

kk_std_time_utc__leaps_table kk_std_time_utc_parse_leap_seconds(kk_string_t leaps, kk_context_t* _ctx) { /* (leaps : string) -> leaps-table */ 
  kk_vector_t v_10019;
  kk_string_t _x_x2267 = kk_string_dup(leaps, _ctx); /*string*/
  kk_string_t _x_x2268;
  kk_define_string_literal(, _s_x2269, 1, "\n", _ctx)
  _x_x2268 = kk_string_dup(_s_x2269, _ctx); /*string*/
  v_10019 = kk_string_splitv(_x_x2267,_x_x2268,kk_context()); /*vector<string>*/
  kk_std_core_types__list xs_10188;
  kk_std_core_types__list _x_x2270 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/
  xs_10188 = kk_std_time_utc__lift_parse_leap_seconds_10658(_x_x2270, _ctx); /*list<std/time/utc/leap-adjust>*/
  kk_std_core_types__list adjusts;
  if (kk_std_core_types__is_Nil(xs_10188, _ctx)) {
    adjusts = kk_std_core_types__new_Nil(_ctx); /*list<std/time/utc/leap-adjust>*/
  }
  else {
    adjusts = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs_10188, _ctx); /*list<std/time/utc/leap-adjust>*/
  }
  kk_std_time_instant__instant expire;
  kk_std_core_types__list _x_x2271 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
  expire = kk_std_time_utc_parse_leap_expire(leaps, _x_x2271, _ctx); /*std/time/instant/instant*/
  return kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx);
}
 
// lifted local: @lift-leaps-table-ti@10660, leaps-table-ti, @spec-x10607
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10599, using:
// @uniq-f@10599 = std/time/utc/parse-leap

kk_std_core_types__list kk_std_time_utc__trmc_lift_leaps_table_ti_10661(kk_std_core_types__list _uniq_xs_10598, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<leap-adjust>>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10598, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2272 = kk_std_core_types__as_Cons(_uniq_xs_10598, _ctx);
    kk_box_t _box_x518 = _con_x2272->head;
    kk_std_core_types__list _uniq_xx_10602 = _con_x2272->tail;
    kk_string_t _uniq_x_10601 = kk_string_unbox(_box_x518);
    kk_reuse_t _ru_x1226 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10598, _ctx)) {
      _ru_x1226 = (kk_datatype_ptr_reuse(_uniq_xs_10598, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10601, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10602, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10598, _ctx);
    }
    kk_std_core_types__maybe _match_x912 = kk_std_time_utc_parse_leap(_uniq_x_10601, _ctx); /*maybe<std/time/utc/leap-adjust>*/;
    if (kk_std_core_types__is_Just(_match_x912, _ctx)) {
      kk_box_t _box_x519 = _match_x912._cons.Just.value;
      kk_std_time_utc__leap_adjust _uniq_y_10604 = kk_std_time_utc__leap_adjust_unbox(_box_x519, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_uniq_y_10604, _ctx);
      kk_std_core_types__maybe_drop(_match_x912, _ctx);
      kk_std_core_types__list _trmc_x10682 = kk_datatype_null(); /*list<std/time/utc/leap-adjust>*/;
      kk_std_core_types__list _trmc_x10683 = kk_std_core_types__new_Cons(_ru_x1226, 0, kk_std_time_utc__leap_adjust_box(_uniq_y_10604, _ctx), _trmc_x10682, _ctx); /*list<std/time/utc/leap-adjust>*/;
      kk_field_addr_t _b_x529_534 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10683, _ctx)->tail, _ctx); /*@field-addr<list<std/time/utc/leap-adjust>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2273 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10683, _ctx)),_b_x529_534,kk_context()); /*ctx<0>*/
        _uniq_xs_10598 = _uniq_xx_10602;
        _acc = _x_x2273;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1226,kk_context());
      { // tailcall
        _uniq_xs_10598 = _uniq_xx_10602;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x2274 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2274, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-leaps-table-ti@10660, leaps-table-ti, @spec-x10607
// specialized: std/core/list/@unroll-flatmap-maybe@10027, on parameters @uniq-f@10599, using:
// @uniq-f@10599 = std/time/utc/parse-leap

kk_std_core_types__list kk_std_time_utc__lift_leaps_table_ti_10661(kk_std_core_types__list _uniq_xs_10598_0, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  kk_std_core_types__cctx _x_x2275 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_time_utc__trmc_lift_leaps_table_ti_10661(_uniq_xs_10598_0, _x_x2275, _ctx);
}
 
// lifted local: leaps-table-ti, @spec-x10597
// specialized: std/core/list/flatmap-maybe, on parameters @uniq-f@10594, using:
// @uniq-f@10594 = std/time/utc/parse-leap

kk_std_core_types__list kk_std_time_utc__lift_leaps_table_ti_10660(kk_std_core_types__list _uniq_xs_10593, kk_context_t* _ctx) { /* (list<string>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10593, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x2276 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_std_time_utc__trmc_lift_leaps_table_ti_10661(_uniq_xs_10593, _x_x2276, _ctx);
  }
}
 
// Default TI leaps table has leap second information up to the compiler release (currently `leaps-table-y2017`).

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


// lift anonymous function
struct kk_std_time_utc_ts_ti_fun2291__t {
  struct kk_function_s _base;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_ti_fun2291(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_fun2291(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ts_ti_fun2291, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_ti_fun2291(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leaps_table _x_x2292 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  return kk_std_time_utc_utc_from_tai(_x_x2292, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_ti_fun2293__t {
  struct kk_function_s _base;
};
static kk_std_time_duration__duration kk_std_time_utc_ts_ti_fun2293(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_fun2293(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ts_ti_fun2293, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_ts_ti_fun2293(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_utc__leaps_table _x_x2294 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  return kk_std_time_utc_utc_to_tai(_x_x2294, utc_0_1, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_ti_fun2296__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ts_ti_fun2296(kk_function_t _fself, kk_box_t _b_x548, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_fun2296(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ts_ti_fun2296, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ts_ti_fun2296(kk_function_t _fself, kk_box_t _b_x548, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2297;
  kk_std_time_timestamp__timestamp utc_0_0_564 = kk_std_time_timestamp__timestamp_unbox(_b_x548, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_core_types__tuple2 tuple2_10075 = kk_std_time_timestamp_days_seconds(utc_0_0_564, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_std_core_types__maybe _match_x911;
  kk_std_time_utc__leaps_table _x_x2298 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  kk_integer_t _x_x2299;
  {
    kk_box_t _box_x540 = tuple2_10075.fst;
    kk_box_t _box_x541 = tuple2_10075.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x540, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    _x_x2299 = _x; /*int*/
  }
  _match_x911 = kk_std_time_utc_utc_leap_in_day(_x_x2298, _x_x2299, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x911, _ctx)) {
    _x_x2297 = kk_std_time_timestamp_solar_secs_per_day; /*std/time/timestamp/timespan*/
  }
  else {
    kk_box_t _box_x542 = _match_x911._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x542, KK_BORROWED, _ctx);
    kk_box_t _box_x543 = _pat_1_0.fst;
    kk_box_t _box_x544 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x543, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x544, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2300 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    kk_std_core_types__maybe_drop(_match_x911, _ctx);
    _x_x2297 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/time/timestamp/timespan*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x2297, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_ti_fun2302__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ts_ti_fun2302(kk_function_t _fself, kk_box_t _b_x553, kk_box_t _b_x554, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_fun2302(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ts_ti_fun2302, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ts_ti_fun2302(kk_function_t _fself, kk_box_t _b_x553, kk_box_t _b_x554, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_ddouble__ddouble _x_x2303;
  kk_std_time_timestamp__timestamp utc_1_565 = kk_std_time_timestamp__timestamp_unbox(_b_x553, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_num_ddouble__ddouble tzdelta_566 = kk_std_num_ddouble__ddouble_unbox(_b_x554, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  kk_std_time_utc__leaps_table _x_x2304 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  _x_x2303 = kk_std_time_utc_utc_to_mjd(_x_x2304, utc_1_565, tzdelta_566, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2303, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_ti_fun2306__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc_ts_ti_fun2306(kk_function_t _fself, kk_box_t _b_x559, kk_box_t _b_x560, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_fun2306(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc_ts_ti_fun2306, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc_ts_ti_fun2306(kk_function_t _fself, kk_box_t _b_x559, kk_box_t _b_x560, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_timestamp__timestamp _x_x2307;
  kk_integer_t days_567 = kk_integer_unbox(_b_x559, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble frac_568 = kk_std_num_ddouble__ddouble_unbox(_b_x560, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_time_utc__leaps_table _x_x2308 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  _x_x2307 = kk_std_time_utc_utc_from_mjd(_x_x2308, days_567, frac_568, _ctx); /*std/time/utc/utc-timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x2307, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_ts_ti;


// lift anonymous function
struct kk_std_time_utc__default_utc_fun2309__t {
  struct kk_function_s _base;
};
static kk_std_time_instant__timescale kk_std_time_utc__default_utc_fun2309(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_default_utc_fun2309(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__default_utc_fun2309, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_time_instant__timescale kk_std_time_utc__default_utc_fun2309(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__default_utc_fun2312__t {
  struct kk_function_s _base;
  kk_function_t _b_x569_570;
};
static kk_box_t kk_std_time_utc__default_utc_fun2312(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_default_utc_fun2312(kk_function_t _b_x569_570, kk_context_t* _ctx) {
  struct kk_std_time_utc__default_utc_fun2312__t* _self = kk_function_alloc_as(struct kk_std_time_utc__default_utc_fun2312__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc__default_utc_fun2312, kk_context());
  _self->_b_x569_570 = _b_x569_570;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc__default_utc_fun2312(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_utc__default_utc_fun2312__t* _self = kk_function_as(struct kk_std_time_utc__default_utc_fun2312__t*, _fself, _ctx);
  kk_function_t _b_x569_570 = _self->_b_x569_570; /* () -> 2510 std/time/instant/timescale */
  kk_drop_match(_self, {kk_function_dup(_b_x569_570, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _x_x2313 = kk_function_call(kk_std_time_instant__timescale, (kk_function_t, kk_context_t*), _b_x569_570, (_b_x569_570, _ctx), _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__timescale_box(_x_x2313, _ctx);
}


// lift anonymous function
struct kk_std_time_utc__default_utc_fun2314__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_utc__default_utc_fun2314(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc__new_default_utc_fun2314(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_utc__default_utc_fun2314, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_utc__default_utc_fun2314(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_std_time_utc__default_utc(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <utc|e> a) -> e a */ 
  kk_function_t _b_x569_570 = kk_std_time_utc__new_default_utc_fun2309(_ctx); /*() -> 2510 std/time/instant/timescale*/;
  kk_std_time_utc__utc _x_x2310;
  kk_std_core_hnd__clause0 _x_x2311 = kk_std_core_hnd_clause_tail0(kk_std_time_utc__new_default_utc_fun2312(_b_x569_570, _ctx), _ctx); /*hnd/clause0<10003,10002,10000,10001>*/
  _x_x2310 = kk_std_time_utc__new_Hnd_utc(kk_reuse_null, 0, kk_integer_from_small(1), _x_x2311, _ctx); /*std/time/utc/utc<12,13>*/
  return kk_std_time_utc_utc_fs__handle(_x_x2310, kk_std_time_utc__new_default_utc_fun2314(_ctx), action, _ctx);
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table0;

kk_string_t kk_std_time_utc_leap_adjust_fs_show(kk_std_time_utc__leap_adjust l, kk_context_t* _ctx) { /* (l : leap-adjust) -> string */ 
  kk_string_t _b_x595_597;
  kk_std_time_timestamp__timestamp _x_x2316;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2317 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _x = _con_x2317->utc_start;
    kk_std_num_ddouble__ddouble _pat_2_1 = _con_x2317->offset;
    kk_std_time_timestamp__timestamp _pat_5_0 = _con_x2317->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x2317->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2318 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2319 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x2316 = _x; /*std/time/utc/utc-timestamp*/
  }
  kk_std_core_types__optional _x_x2320;
  kk_box_t _x_x2321;
  kk_integer_t _x_x2322;
  kk_std_core_types__optional _match_x910 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x910, _ctx)) {
    kk_box_t _box_x571 = _match_x910._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3270 = kk_integer_unbox(_box_x571, _ctx);
    kk_integer_dup(_uniq_max_prec_3270, _ctx);
    kk_std_core_types__optional_drop(_match_x910, _ctx);
    _x_x2322 = _uniq_max_prec_3270; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x910, _ctx);
    _x_x2322 = kk_integer_from_small(9); /*int*/
  }
  _x_x2321 = kk_integer_box(_x_x2322, _ctx); /*10003*/
  _x_x2320 = kk_std_core_types__new_Optional(_x_x2321, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2323;
  kk_box_t _x_x2324;
  kk_integer_t _x_x2325;
  kk_std_core_types__optional _match_x909 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x909, _ctx)) {
    kk_box_t _box_x573 = _match_x909._cons._Optional.value;
    kk_integer_t _uniq_secs_width_3274 = kk_integer_unbox(_box_x573, _ctx);
    kk_integer_dup(_uniq_secs_width_3274, _ctx);
    kk_std_core_types__optional_drop(_match_x909, _ctx);
    _x_x2325 = _uniq_secs_width_3274; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x909, _ctx);
    _x_x2325 = kk_integer_from_small(1); /*int*/
  }
  _x_x2324 = kk_integer_box(_x_x2325, _ctx); /*10003*/
  _x_x2323 = kk_std_core_types__new_Optional(_x_x2324, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2326;
  kk_box_t _x_x2327;
  kk_string_t _x_x2328;
  kk_std_core_types__optional _match_x908 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x908, _ctx)) {
    kk_box_t _box_x575 = _match_x908._cons._Optional.value;
    kk_string_t _uniq_unit_3278 = kk_string_unbox(_box_x575);
    kk_string_dup(_uniq_unit_3278, _ctx);
    kk_std_core_types__optional_drop(_match_x908, _ctx);
    _x_x2328 = _uniq_unit_3278; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x908, _ctx);
    _x_x2328 = kk_string_empty(); /*string*/
  }
  _x_x2327 = kk_string_box(_x_x2328); /*10003*/
  _x_x2326 = kk_std_core_types__new_Optional(_x_x2327, _ctx); /*? 10003*/
  _b_x595_597 = kk_std_time_timestamp_ts_show(_x_x2316, _x_x2320, _x_x2323, _x_x2326, _ctx); /*string*/
  kk_string_t _b_x591_604;
  kk_std_num_ddouble__ddouble _x_x2330;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2331 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_2 = _con_x2331->utc_start;
    kk_std_num_ddouble__ddouble _x_0 = _con_x2331->offset;
    kk_std_time_timestamp__timestamp _pat_5_1 = _con_x2331->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_0 = _con_x2331->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2332 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2333 = kk_std_time_timestamp__as_Timestamp(_pat_5_1, _ctx);
    _x_x2330 = _x_0; /*std/time/timestamp/timespan*/
  }
  _b_x591_604 = kk_std_num_ddouble_show(_x_x2330, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _b_x587_608;
  kk_std_time_timestamp__timestamp _x_x2334;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2335 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_4 = _con_x2335->utc_start;
    kk_std_num_ddouble__ddouble _pat_3_4 = _con_x2335->offset;
    kk_std_time_timestamp__timestamp _x_1 = _con_x2335->drift_start;
    kk_std_num_ddouble__ddouble _pat_8_1 = _con_x2335->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2336 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2337 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    _x_x2334 = _x_1; /*std/time/utc/utc-timestamp*/
  }
  kk_std_core_types__optional _x_x2338;
  kk_box_t _x_x2339;
  kk_integer_t _x_x2340;
  kk_std_core_types__optional _match_x907 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x907, _ctx)) {
    kk_box_t _box_x577 = _match_x907._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3270_0 = kk_integer_unbox(_box_x577, _ctx);
    kk_integer_dup(_uniq_max_prec_3270_0, _ctx);
    kk_std_core_types__optional_drop(_match_x907, _ctx);
    _x_x2340 = _uniq_max_prec_3270_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x907, _ctx);
    _x_x2340 = kk_integer_from_small(9); /*int*/
  }
  _x_x2339 = kk_integer_box(_x_x2340, _ctx); /*10003*/
  _x_x2338 = kk_std_core_types__new_Optional(_x_x2339, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2341;
  kk_box_t _x_x2342;
  kk_integer_t _x_x2343;
  kk_std_core_types__optional _match_x906 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x906, _ctx)) {
    kk_box_t _box_x579 = _match_x906._cons._Optional.value;
    kk_integer_t _uniq_secs_width_3274_0 = kk_integer_unbox(_box_x579, _ctx);
    kk_integer_dup(_uniq_secs_width_3274_0, _ctx);
    kk_std_core_types__optional_drop(_match_x906, _ctx);
    _x_x2343 = _uniq_secs_width_3274_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x906, _ctx);
    _x_x2343 = kk_integer_from_small(1); /*int*/
  }
  _x_x2342 = kk_integer_box(_x_x2343, _ctx); /*10003*/
  _x_x2341 = kk_std_core_types__new_Optional(_x_x2342, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2344;
  kk_box_t _x_x2345;
  kk_string_t _x_x2346;
  kk_std_core_types__optional _match_x905 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x905, _ctx)) {
    kk_box_t _box_x581 = _match_x905._cons._Optional.value;
    kk_string_t _uniq_unit_3278_0 = kk_string_unbox(_box_x581);
    kk_string_dup(_uniq_unit_3278_0, _ctx);
    kk_std_core_types__optional_drop(_match_x905, _ctx);
    _x_x2346 = _uniq_unit_3278_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x905, _ctx);
    _x_x2346 = kk_string_empty(); /*string*/
  }
  _x_x2345 = kk_string_box(_x_x2346); /*10003*/
  _x_x2344 = kk_std_core_types__new_Optional(_x_x2345, _ctx); /*? 10003*/
  _b_x587_608 = kk_std_time_timestamp_ts_show(_x_x2334, _x_x2338, _x_x2341, _x_x2344, _ctx); /*string*/
  kk_string_t _b_x583_615;
  kk_std_num_ddouble__ddouble _x_x2348;
  {
    struct kk_std_time_utc_Leap_adjust* _con_x2349 = kk_std_time_utc__as_Leap_adjust(l, _ctx);
    kk_std_time_timestamp__timestamp _pat_0_5 = _con_x2349->utc_start;
    kk_std_num_ddouble__ddouble _pat_3_5 = _con_x2349->offset;
    kk_std_time_timestamp__timestamp _pat_6_3 = _con_x2349->drift_start;
    kk_std_num_ddouble__ddouble _x_2 = _con_x2349->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x2350 = kk_std_time_timestamp__as_Timestamp(_pat_0_5, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2351 = kk_std_time_timestamp__as_Timestamp(_pat_6_3, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(l, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_6_3, _ctx)) {
        kk_datatype_ptr_free(_pat_6_3, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_6_3, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_0_5, _ctx)) {
        kk_datatype_ptr_free(_pat_0_5, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_0_5, _ctx);
      }
      kk_datatype_ptr_free(l, _ctx);
    }
    else {
      kk_datatype_ptr_decref(l, _ctx);
    }
    _x_x2348 = _x_2; /*std/num/ddouble/ddouble*/
  }
  _b_x583_615 = kk_std_num_ddouble_show(_x_x2348, kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_std_core_types__list xs_10199;
  kk_std_core_types__list _x_x2352;
  kk_box_t _x_x2353;
  kk_string_t _x_x2354;
  kk_define_string_literal(, _s_x2355, 10, ": offset: ", _ctx)
  _x_x2354 = kk_string_dup(_s_x2355, _ctx); /*string*/
  _x_x2353 = kk_string_box(_x_x2354); /*10021*/
  kk_std_core_types__list _x_x2356;
  kk_std_core_types__list _x_x2357;
  kk_box_t _x_x2358;
  kk_string_t _x_x2359;
  kk_define_string_literal(, _s_x2360, 15, ", drift-start: ", _ctx)
  _x_x2359 = kk_string_dup(_s_x2360, _ctx); /*string*/
  _x_x2358 = kk_string_box(_x_x2359); /*10021*/
  kk_std_core_types__list _x_x2361;
  kk_std_core_types__list _x_x2362;
  kk_box_t _x_x2363;
  kk_string_t _x_x2364;
  kk_define_string_literal(, _s_x2365, 9, ", drift: ", _ctx)
  _x_x2364 = kk_string_dup(_s_x2365, _ctx); /*string*/
  _x_x2363 = kk_string_box(_x_x2364); /*10021*/
  kk_std_core_types__list _x_x2366 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x583_615), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x2362 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2363, _x_x2366, _ctx); /*list<10021>*/
  _x_x2361 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x587_608), _x_x2362, _ctx); /*list<10021>*/
  _x_x2357 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2358, _x_x2361, _ctx); /*list<10021>*/
  _x_x2356 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x591_604), _x_x2357, _ctx); /*list<10021>*/
  _x_x2352 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2353, _x_x2356, _ctx); /*list<10021>*/
  xs_10199 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x595_597), _x_x2352, _ctx); /*list<string>*/
  if (kk_std_core_types__is_Nil(xs_10199, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x2368 = kk_std_core_types__as_Cons(xs_10199, _ctx);
    kk_box_t _box_x617 = _con_x2368->head;
    kk_std_core_types__list _pat_1 = _con_x2368->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x617);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10199, _ctx)) {
        kk_datatype_ptr_free(xs_10199, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10199, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2369 = kk_std_core_types__as_Cons(xs_10199, _ctx);
    kk_box_t _box_x618 = _con_x2369->head;
    kk_std_core_types__list _pat_3 = _con_x2369->tail;
    struct kk_std_core_types_Cons* _con_x2370 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x619 = _con_x2370->head;
    kk_std_core_types__list _pat_4 = _con_x2370->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x618);
      kk_string_t y = kk_string_unbox(_box_x619);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10199, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_10199, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_10199, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x2371 = kk_std_core_vector_unvlist(xs_10199, _ctx); /*vector<10000>*/
    return kk_string_join(_x_x2371,kk_context());
  }
}
 
// lifted local: leaps-table/@lift-show@10662, leaps-table/show, @spec-x10619
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10614, using:
// @uniq-f@10614 = std/time/utc/leap-adjust/show

kk_std_core_types__list kk_std_time_utc_leaps_table_fs__trmc_lift_show_10663(kk_std_core_types__list _uniq_xs_10613, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<leap-adjust>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10613, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2372 = kk_std_core_types__as_Cons(_uniq_xs_10613, _ctx);
    kk_box_t _box_x620 = _con_x2372->head;
    kk_std_core_types__list _uniq_xx_10617 = _con_x2372->tail;
    kk_std_time_utc__leap_adjust _uniq_x_10616 = kk_std_time_utc__leap_adjust_unbox(_box_x620, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1233 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10613, _ctx)) {
      _ru_x1233 = (kk_datatype_ptr_reuse(_uniq_xs_10613, _ctx));
    }
    else {
      kk_std_time_utc__leap_adjust_dup(_uniq_x_10616, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10617, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10613, _ctx);
    }
    kk_string_t _trmc_x10684 = kk_std_time_utc_leap_adjust_fs_show(_uniq_x_10616, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10685 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10686 = kk_std_core_types__new_Cons(_ru_x1233, 0, kk_string_box(_trmc_x10684), _trmc_x10685, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x630_635 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10686, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x903;
    kk_std_core_types__cctx _x_x2373 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x903 = kk_cctx_extend_linear(_x_x2373,(kk_std_core_types__list_box(_trmc_x10686, _ctx)),_b_x630_635,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x904 = kk_std_time_utc_leaps_table_fs__trmc_lift_show_10663(_uniq_xx_10617, _brw_x903, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x903, _ctx);
    return _brw_x904;
  }
  {
    kk_box_t _x_x2374;
    kk_std_core_types__cctx _x_x2375 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x2374 = kk_cctx_apply_linear(_x_x2375,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2374, KK_OWNED, _ctx);
  }
}
 
// lifted local: leaps-table/@lift-show@10662, leaps-table/show, @spec-x10619
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10614, using:
// @uniq-f@10614 = std/time/utc/leap-adjust/show

kk_std_core_types__list kk_std_time_utc_leaps_table_fs__lift_show_10663(kk_std_core_types__list _uniq_xs_10613_0, kk_context_t* _ctx) { /* (list<leap-adjust>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x901 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x902 = kk_std_time_utc_leaps_table_fs__trmc_lift_show_10663(_uniq_xs_10613_0, _brw_x901, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x901, _ctx);
  return _brw_x902;
}
 
// lifted local: leaps-table/show, @spec-x10612
// specialized: std/core/list/map, on parameters @uniq-f@10609, using:
// @uniq-f@10609 = std/time/utc/leap-adjust/show

kk_std_core_types__list kk_std_time_utc_leaps_table_fs__lift_show_10662(kk_std_core_types__list _uniq_xs_10608, kk_context_t* _ctx) { /* (list<leap-adjust>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10608, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x899 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x900 = kk_std_time_utc_leaps_table_fs__trmc_lift_show_10663(_uniq_xs_10608, _brw_x899, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x899, _ctx);
    return _brw_x900;
  }
}

kk_string_t kk_std_time_utc_leaps_table_fs_show(kk_std_time_utc__leaps_table t, kk_context_t* _ctx) { /* (t : leaps-table) -> string */ 
  kk_std_core_types__list xs_10212;
  kk_std_core_types__list _x_x2376;
  {
    struct kk_std_time_utc_Leaps_table* _con_x2377 = kk_std_time_utc__as_Leaps_table(t, _ctx);
    kk_std_time_instant__instant _pat_0_0 = _con_x2377->expire;
    kk_std_core_types__list _x = _con_x2377->adjusts;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x2376 = _x; /*list<std/time/utc/leap-adjust>*/
  }
  xs_10212 = kk_std_time_utc_leaps_table_fs__lift_show_10662(_x_x2376, _ctx); /*list<string>*/
  if (kk_std_core_types__is_Nil(xs_10212, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x2379 = kk_std_core_types__as_Cons(xs_10212, _ctx);
    kk_box_t _box_x641 = _con_x2379->head;
    kk_std_core_types__list _pat_1 = _con_x2379->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x641);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10212, _ctx)) {
        kk_datatype_ptr_free(xs_10212, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10212, _ctx);
      }
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs_10212, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2380 = kk_std_core_types__as_Cons(xs_10212, _ctx);
    kk_box_t _box_x642 = _con_x2380->head;
    kk_std_core_types__list _pat_3 = _con_x2380->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x2381 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x643 = _con_x2381->head;
      kk_std_core_types__list _pat_4 = _con_x2381->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x2382;
        kk_define_string_literal(, _s_x2383, 1, "\n", _ctx)
        _x_x2382 = kk_string_dup(_s_x2383, _ctx); /*string*/
        kk_string_t _x_x2384 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x2382,_x_x2384,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x642);
          kk_string_t y = kk_string_unbox(_box_x643);
          if kk_likely(kk_datatype_ptr_is_unique(xs_10212, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs_10212, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs_10212, _ctx);
          }
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x2386 = kk_std_core_vector_unvlist(xs_10212, _ctx); /*vector<10000>*/
    kk_string_t _x_x2387;
    kk_define_string_literal(, _s_x2388, 1, "\n", _ctx)
    _x_x2387 = kk_string_dup(_s_x2388, _ctx); /*string*/
    return kk_string_join_with(_x_x2386,_x_x2387,kk_context());
  }
}

kk_std_num_ddouble__ddouble kk_std_time_utc_unix2000;
 
// Create an instant from raw unix seconds since the unix epoch (1970-01-01T00:00:10 TAI)
// and optional leap seconds to designate instants inside a leap seconds.

kk_std_time_instant__instant kk_std_time_utc_timespan_fs_unix_instant(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (t : std/time/timestamp/timespan, leap : ? int, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_std_num_ddouble__ddouble t_1_10220;
  kk_std_num_ddouble__ddouble _x_x2393;
  double _x_x2394;
  double _x_x2395;
  kk_std_num_ddouble__ddouble _x_x2396 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_2 = _x_x2396.hi;
    _x_x2395 = _x_2; /*float64*/
  }
  _x_x2394 = (-_x_x2395); /*float64*/
  double _x_x2397;
  double _x_x2398;
  kk_std_num_ddouble__ddouble _x_x2399 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_0_0 = _x_x2399.lo;
    _x_x2398 = _x_0_0; /*float64*/
  }
  _x_x2397 = (-_x_x2398); /*float64*/
  _x_x2393 = kk_std_num_ddouble__new_Ddouble(_x_x2394, _x_x2397, _ctx); /*std/num/ddouble/ddouble*/
  t_1_10220 = kk_std_num_ddouble__lp__plus__rp_(t, _x_x2393, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_time_timestamp__timestamp t_0_10219;
  int32_t _x_x2400;
  kk_integer_t _x_x2401;
  if (kk_std_core_types__is_Optional(leap, _ctx)) {
    kk_box_t _box_x646 = leap._cons._Optional.value;
    kk_integer_t _uniq_leap_3016 = kk_integer_unbox(_box_x646, _ctx);
    kk_integer_dup(_uniq_leap_3016, _ctx);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2401 = _uniq_leap_3016; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2401 = kk_integer_from_small(0); /*int*/
  }
  _x_x2400 = kk_integer_clamp32(_x_x2401,kk_context()); /*int32*/
  t_0_10219 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_1_10220, _x_x2400, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__instant i_10216;
  kk_std_time_instant__timescale _x_x2402 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  i_10216 = kk_std_time_instant__new_Instant(t_0_10219, _x_x2402, _ctx); /*std/time/instant/instant*/
  bool _match_x894;
  kk_string_t _x_x2403;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i_10216.since;
    kk_std_time_instant__timescale _x_0 = i_10216.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2404 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2405 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x2406 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x2406->name;
      kk_string_t _pat_0 = _con_x2406->unit;
      kk_function_t _pat_1 = _con_x2406->from_tai;
      kk_function_t _pat_2 = _con_x2406->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x2406->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x2406->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x2406->mb_from_mjd2000;
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
      _x_x2403 = _x; /*string*/
    }
  }
  kk_string_t _x_x2407;
  kk_std_time_instant__timescale _match_x895;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x647 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3020 = kk_std_time_instant__timescale_unbox(_box_x647, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3020, _ctx);
    _match_x895 = _uniq_ts_3020; /*std/time/instant/timescale*/
  }
  else {
    _match_x895 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    struct kk_std_time_instant_Timescale* _con_x2408 = kk_std_time_instant__as_Timescale(_match_x895, _ctx);
    kk_string_t _x_1 = _con_x2408->name;
    kk_string_t _pat_0_1 = _con_x2408->unit;
    kk_function_t _pat_1_1 = _con_x2408->from_tai;
    kk_function_t _pat_2_1 = _con_x2408->to_tai;
    kk_std_core_types__maybe _pat_3_1 = _con_x2408->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_1 = _con_x2408->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_1 = _con_x2408->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x895, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
      kk_function_drop(_pat_2_1, _ctx);
      kk_function_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x895, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x895, _ctx);
    }
    _x_x2407 = _x_1; /*string*/
  }
  _match_x894 = kk_string_is_eq(_x_x2403,_x_x2407,kk_context()); /*bool*/
  if (_match_x894) {
    kk_std_core_types__optional_drop(ts, _ctx);
    return i_10216;
  }
  {
    kk_std_time_timestamp__timestamp _x_x2409;
    kk_std_time_instant__timescale _x_x2410;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x648 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3020_0 = kk_std_time_instant__timescale_unbox(_box_x648, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3020_0, _ctx);
      _x_x2410 = _uniq_ts_3020_0; /*std/time/instant/timescale*/
    }
    else {
      _x_x2410 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    _x_x2409 = kk_std_time_instant_timestamp_in(i_10216, _x_x2410, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x2411;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x649 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3020_1 = kk_std_time_instant__timescale_unbox(_box_x649, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3020_1, _ctx);
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2411 = _uniq_ts_3020_1; /*std/time/instant/timescale*/
    }
    else {
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2411 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x2409, _x_x2411, _ctx);
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
  double frac_0_10225;
  double _x_x2412;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x650 = frac._cons._Optional.value;
    double _uniq_frac_3057 = kk_double_unbox(_box_x650, KK_BORROWED, _ctx);
    _x_x2412 = _uniq_frac_3057; /*float64*/
  }
  else {
    _x_x2412 = 0x0p+0; /*float64*/
  }
  frac_0_10225 = kk_std_num_float64_fraction(_x_x2412, _ctx); /*float64*/
  kk_std_num_ddouble__ddouble t;
  bool _match_x893 = (frac_0_10225 == (0x0p+0)); /*bool*/;
  if (_match_x893) {
    t = kk_std_num_ddouble__new_Ddouble(u, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    t = kk_std_num_ddouble_dsum(u, frac_0_10225, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_integer_t leap;
  double _x_x2413;
  bool _match_x892;
  double _x_x2414;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x651 = frac._cons._Optional.value;
    double _uniq_frac_3057_0 = kk_double_unbox(_box_x651, KK_BORROWED, _ctx);
    _x_x2414 = _uniq_frac_3057_0; /*float64*/
  }
  else {
    _x_x2414 = 0x0p+0; /*float64*/
  }
  _match_x892 = (_x_x2414 >= (0x0p+0)); /*bool*/
  if (_match_x892) {
    double _x_x2415;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x652 = frac._cons._Optional.value;
      double _uniq_frac_3057_1 = kk_double_unbox(_box_x652, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2415 = _uniq_frac_3057_1; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2415 = 0x0p+0; /*float64*/
    }
    _x_x2413 = floor(_x_x2415); /*float64*/
  }
  else {
    double _x_x2416;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x653 = frac._cons._Optional.value;
      double _uniq_frac_3057_2 = kk_double_unbox(_box_x653, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2416 = _uniq_frac_3057_2; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2416 = 0x0p+0; /*float64*/
    }
    _x_x2413 = ceil(_x_x2416); /*float64*/
  }
  leap = kk_integer_from_double(_x_x2413,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble t_2_10234;
  kk_std_num_ddouble__ddouble _x_x2417;
  double _x_x2418;
  double _x_x2419;
  kk_std_num_ddouble__ddouble _x_x2420 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_2 = _x_x2420.hi;
    _x_x2419 = _x_2; /*float64*/
  }
  _x_x2418 = (-_x_x2419); /*float64*/
  double _x_x2421;
  double _x_x2422;
  kk_std_num_ddouble__ddouble _x_x2423 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_0_0 = _x_x2423.lo;
    _x_x2422 = _x_0_0; /*float64*/
  }
  _x_x2421 = (-_x_x2422); /*float64*/
  _x_x2417 = kk_std_num_ddouble__new_Ddouble(_x_x2418, _x_x2421, _ctx); /*std/num/ddouble/ddouble*/
  t_2_10234 = kk_std_num_ddouble__lp__plus__rp_(t, _x_x2417, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_time_timestamp__timestamp t_1_10233 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_2_10234, kk_integer_clamp32(leap,kk_context()), _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__instant i_10230;
  kk_std_time_instant__timescale _x_x2424 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  i_10230 = kk_std_time_instant__new_Instant(t_1_10233, _x_x2424, _ctx); /*std/time/instant/instant*/
  bool _match_x890;
  kk_string_t _x_x2425;
  {
    kk_std_time_timestamp__timestamp _pat_0_0_0 = i_10230.since;
    kk_std_time_instant__timescale _x_0 = i_10230.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2426 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2427 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x2428 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x2428->name;
      kk_string_t _pat_0_2_0 = _con_x2428->unit;
      kk_function_t _pat_1_1 = _con_x2428->from_tai;
      kk_function_t _pat_2_1 = _con_x2428->to_tai;
      kk_std_core_types__maybe _pat_3_1_0 = _con_x2428->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_1 = _con_x2428->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x2428->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_1_0, _ctx);
        kk_function_drop(_pat_2_1, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_2_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x2425 = _x; /*string*/
    }
  }
  kk_string_t _x_x2429;
  kk_std_time_instant__timescale _match_x891;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x654 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3061 = kk_std_time_instant__timescale_unbox(_box_x654, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3061, _ctx);
    _match_x891 = _uniq_ts_3061; /*std/time/instant/timescale*/
  }
  else {
    _match_x891 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    struct kk_std_time_instant_Timescale* _con_x2430 = kk_std_time_instant__as_Timescale(_match_x891, _ctx);
    kk_string_t _x_1 = _con_x2430->name;
    kk_string_t _pat_0_1_0_0 = _con_x2430->unit;
    kk_function_t _pat_1_1_0 = _con_x2430->from_tai;
    kk_function_t _pat_2_1_0 = _con_x2430->to_tai;
    kk_std_core_types__maybe _pat_3_1_0_0 = _con_x2430->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_1_0 = _con_x2430->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_1 = _con_x2430->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x891, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_1_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_3_1_0_0, _ctx);
      kk_function_drop(_pat_2_1_0, _ctx);
      kk_function_drop(_pat_1_1_0, _ctx);
      kk_string_drop(_pat_0_1_0_0, _ctx);
      kk_datatype_ptr_free(_match_x891, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x891, _ctx);
    }
    _x_x2429 = _x_1; /*string*/
  }
  _match_x890 = kk_string_is_eq(_x_x2425,_x_x2429,kk_context()); /*bool*/
  if (_match_x890) {
    kk_std_core_types__optional_drop(ts, _ctx);
    return i_10230;
  }
  {
    kk_std_time_timestamp__timestamp _x_x2431;
    kk_std_time_instant__timescale _x_x2432;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x655 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3061_0 = kk_std_time_instant__timescale_unbox(_box_x655, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3061_0, _ctx);
      _x_x2432 = _uniq_ts_3061_0; /*std/time/instant/timescale*/
    }
    else {
      _x_x2432 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    _x_x2431 = kk_std_time_instant_timestamp_in(i_10230, _x_x2432, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x2433;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x656 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3061_1 = kk_std_time_instant__timescale_unbox(_box_x656, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3061_1, _ctx);
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2433 = _uniq_ts_3061_1; /*std/time/instant/timescale*/
    }
    else {
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2433 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x2431, _x_x2433, _ctx);
  }
}
 
// Create an instant from raw unix seconds since the unix epoch (1970-01-01T00:00:10 TAI)
// Use a fraction `> 1` to indicate a time inside a leap second.

kk_std_time_instant__instant kk_std_time_utc_int_fs_unix_instant(kk_integer_t u, kk_std_core_types__optional frac, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (u : int, frac : ? float64, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 
  double d_10240;
  double _x_x2434;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x657 = frac._cons._Optional.value;
    double _uniq_frac_3112 = kk_double_unbox(_box_x657, KK_BORROWED, _ctx);
    _x_x2434 = _uniq_frac_3112; /*float64*/
  }
  else {
    _x_x2434 = 0x0p+0; /*float64*/
  }
  d_10240 = kk_std_num_float64_fraction(_x_x2434, _ctx); /*float64*/
  kk_std_num_ddouble__ddouble secs_10238;
  kk_std_num_ddouble__ddouble _x_x2435 = kk_std_num_ddouble_ddouble_int_exp(u, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2436 = kk_std_num_ddouble__new_Ddouble(d_10240, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  secs_10238 = kk_std_num_ddouble__lp__plus__rp_(_x_x2435, _x_x2436, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t leap;
  double _x_x2437;
  bool _match_x889;
  double _x_x2438;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x658 = frac._cons._Optional.value;
    double _uniq_frac_3112_0 = kk_double_unbox(_box_x658, KK_BORROWED, _ctx);
    _x_x2438 = _uniq_frac_3112_0; /*float64*/
  }
  else {
    _x_x2438 = 0x0p+0; /*float64*/
  }
  _match_x889 = (_x_x2438 >= (0x0p+0)); /*bool*/
  if (_match_x889) {
    double _x_x2439;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x659 = frac._cons._Optional.value;
      double _uniq_frac_3112_1 = kk_double_unbox(_box_x659, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2439 = _uniq_frac_3112_1; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2439 = 0x0p+0; /*float64*/
    }
    _x_x2437 = floor(_x_x2439); /*float64*/
  }
  else {
    double _x_x2440;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x660 = frac._cons._Optional.value;
      double _uniq_frac_3112_2 = kk_double_unbox(_box_x660, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2440 = _uniq_frac_3112_2; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x2440 = 0x0p+0; /*float64*/
    }
    _x_x2437 = ceil(_x_x2440); /*float64*/
  }
  leap = kk_integer_from_double(_x_x2437,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble t_2_10249;
  kk_std_num_ddouble__ddouble _x_x2441;
  double _x_x2442;
  double _x_x2443;
  kk_std_num_ddouble__ddouble _x_x2444 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_2 = _x_x2444.hi;
    _x_x2443 = _x_2; /*float64*/
  }
  _x_x2442 = (-_x_x2443); /*float64*/
  double _x_x2445;
  double _x_x2446;
  kk_std_num_ddouble__ddouble _x_x2447 = kk_std_time_utc_unix2000; /*std/time/timestamp/timespan*/
  {
    double _x_0_0 = _x_x2447.lo;
    _x_x2446 = _x_0_0; /*float64*/
  }
  _x_x2445 = (-_x_x2446); /*float64*/
  _x_x2441 = kk_std_num_ddouble__new_Ddouble(_x_x2442, _x_x2445, _ctx); /*std/num/ddouble/ddouble*/
  t_2_10249 = kk_std_num_ddouble__lp__plus__rp_(secs_10238, _x_x2441, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_time_timestamp__timestamp t_1_10248 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_2_10249, kk_integer_clamp32(leap,kk_context()), _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_time_instant__instant i_0_10245;
  kk_std_time_instant__timescale _x_x2448 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  i_0_10245 = kk_std_time_instant__new_Instant(t_1_10248, _x_x2448, _ctx); /*std/time/instant/instant*/
  bool _match_x887;
  kk_string_t _x_x2449;
  {
    kk_std_time_timestamp__timestamp _pat_0_0_0_0 = i_0_10245.since;
    kk_std_time_instant__timescale _x_0 = i_0_10245.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x2450 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x2451 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x2452 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x2452->name;
      kk_string_t _pat_0_1_0 = _con_x2452->unit;
      kk_function_t _pat_1_1 = _con_x2452->from_tai;
      kk_function_t _pat_2_1_0 = _con_x2452->to_tai;
      kk_std_core_types__maybe _pat_3_1 = _con_x2452->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x2452->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x2452->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
        kk_function_drop(_pat_2_1_0, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x2449 = _x; /*string*/
    }
  }
  kk_string_t _x_x2453;
  kk_std_time_instant__timescale _match_x888;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x661 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3116 = kk_std_time_instant__timescale_unbox(_box_x661, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3116, _ctx);
    _match_x888 = _uniq_ts_3116; /*std/time/instant/timescale*/
  }
  else {
    _match_x888 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    struct kk_std_time_instant_Timescale* _con_x2454 = kk_std_time_instant__as_Timescale(_match_x888, _ctx);
    kk_string_t _x_1 = _con_x2454->name;
    kk_string_t _pat_0_1_0_0 = _con_x2454->unit;
    kk_function_t _pat_1_1_0 = _con_x2454->from_tai;
    kk_function_t _pat_2_1_0_0 = _con_x2454->to_tai;
    kk_std_core_types__maybe _pat_3_1_0 = _con_x2454->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_1 = _con_x2454->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_1 = _con_x2454->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x888, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
      kk_std_core_types__maybe_drop(_pat_3_1_0, _ctx);
      kk_function_drop(_pat_2_1_0_0, _ctx);
      kk_function_drop(_pat_1_1_0, _ctx);
      kk_string_drop(_pat_0_1_0_0, _ctx);
      kk_datatype_ptr_free(_match_x888, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x888, _ctx);
    }
    _x_x2453 = _x_1; /*string*/
  }
  _match_x887 = kk_string_is_eq(_x_x2449,_x_x2453,kk_context()); /*bool*/
  if (_match_x887) {
    kk_std_core_types__optional_drop(ts, _ctx);
    return i_0_10245;
  }
  {
    kk_std_time_timestamp__timestamp _x_x2455;
    kk_std_time_instant__timescale _x_x2456;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x662 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3116_0 = kk_std_time_instant__timescale_unbox(_box_x662, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3116_0, _ctx);
      _x_x2456 = _uniq_ts_3116_0; /*std/time/instant/timescale*/
    }
    else {
      _x_x2456 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    _x_x2455 = kk_std_time_instant_timestamp_in(i_0_10245, _x_x2456, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x2457;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x663 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_3116_1 = kk_std_time_instant__timescale_unbox(_box_x663, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_3116_1, _ctx);
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2457 = _uniq_ts_3116_1; /*std/time/instant/timescale*/
    }
    else {
      kk_std_core_types__optional_drop(ts, _ctx);
      _x_x2457 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x2455, _x_x2457, _ctx);
  }
}
 
// Get a standard Unix timestamp in fractional seconds since the Unix epoch (1970-01-01Z).
// Since Unix time stamps are ambiguous,
// instants inside a leap seconds show as occurring in the second after that.

kk_std_num_ddouble__ddouble kk_std_time_utc_unix_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : std/time/instant/instant) -> std/num/ddouble/ddouble */ 
  kk_std_time_timestamp__timestamp ts_10253;
  kk_std_time_instant__timescale _x_x2458 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  ts_10253 = kk_std_time_instant_timestamp_in(i, _x_x2458, _ctx); /*std/time/timestamp/timestamp*/
  kk_integer_t seconds_10081;
  int32_t _x_x2459;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x2460 = kk_std_time_timestamp__as_Timestamp(ts_10253, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_1 = _con_x2460->since;
    int32_t _x_0 = _con_x2460->leap32;
    _x_x2459 = _x_0; /*int32*/
  }
  seconds_10081 = kk_integer_from_int(_x_x2459,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x2461;
  kk_std_num_ddouble__ddouble _x_x2462;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x2463 = kk_std_time_timestamp__as_Timestamp(ts_10253, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x2463->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts_10253, _ctx)) {
      kk_datatype_ptr_free(ts_10253, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts_10253, _ctx);
    }
    _x_x2462 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x2464;
  bool _match_x884;
  double _x_x2465;
  kk_std_core_types__optional _match_x886 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x886, _ctx)) {
    kk_box_t _box_x664 = _match_x886._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x664, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x886, _ctx);
    _x_x2465 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x886, _ctx);
    _x_x2465 = 0x0p+0; /*float64*/
  }
  _match_x884 = (_x_x2465 == (0x0p+0)); /*bool*/
  if (_match_x884) {
    _x_x2464 = kk_std_num_ddouble_ddouble_int_exp(seconds_10081, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2466 = kk_std_num_ddouble_ddouble_int_exp(seconds_10081, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2467;
    double _x_x2468;
    kk_std_core_types__optional _match_x885 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x885, _ctx)) {
      kk_box_t _box_x665 = _match_x885._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x665, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x885, _ctx);
      _x_x2468 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x885, _ctx);
      _x_x2468 = 0x0p+0; /*float64*/
    }
    _x_x2467 = kk_std_num_ddouble__new_Ddouble(_x_x2468, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2464 = kk_std_num_ddouble__lp__plus__rp_(_x_x2466, _x_x2467, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x_x2461 = kk_std_num_ddouble__lp__plus__rp_(_x_x2462, _x_x2464, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(kk_std_time_utc_unix2000, _x_x2461, _ctx);
}
 
// [NTP](https://en.wikipedia.org/wiki/Network_Time_Protocol) time scale.
// It equals the `ts-ti` time scale.

kk_std_time_instant__timescale kk_std_time_utc_ts_ntp;
 
// Convert an NTP time in seconds since the NTP epoch (1900-01-01Z) to an instant.
// Also takes an optional `leap` argument if the NTP time is inside a leap second.

kk_std_time_instant__instant kk_std_time_utc_ntp_instant(kk_std_num_ddouble__ddouble ntp, kk_std_core_types__optional leap, kk_context_t* _ctx) { /* (ntp : std/num/ddouble/ddouble, leap : ? int) -> std/time/instant/instant */ 
  kk_std_time_timestamp__timestamp ts_0_10256;
  int32_t _x_x2469;
  kk_integer_t _x_x2470;
  if (kk_std_core_types__is_Optional(leap, _ctx)) {
    kk_box_t _box_x666 = leap._cons._Optional.value;
    kk_integer_t _uniq_leap_3200 = kk_integer_unbox(_box_x666, _ctx);
    kk_integer_dup(_uniq_leap_3200, _ctx);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2470 = _uniq_leap_3200; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x2470 = kk_integer_from_small(0); /*int*/
  }
  _x_x2469 = kk_integer_clamp32(_x_x2470,kk_context()); /*int32*/
  ts_0_10256 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, ntp, _x_x2469, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp t_10255;
  kk_std_num_ddouble__ddouble _x_x2471;
  kk_std_num_ddouble__ddouble _x_x2472;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x2473 = kk_std_time_timestamp__as_Timestamp(ts_0_10256, _ctx);
    kk_std_num_ddouble__ddouble _x_1 = _con_x2473->since;
    _x_x2472 = _x_1; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x2474;
  double _x_x2475;
  double _x_x2476;
  kk_std_num_ddouble__ddouble _x_x2477 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x2477.hi;
    _x_x2476 = _x; /*float64*/
  }
  _x_x2475 = (-_x_x2476); /*float64*/
  double _x_x2478;
  double _x_x2479;
  kk_std_num_ddouble__ddouble _x_x2480 = kk_std_time_utc_ntp2000; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x2480.lo;
    _x_x2479 = _x_0; /*float64*/
  }
  _x_x2478 = (-_x_x2479); /*float64*/
  _x_x2474 = kk_std_num_ddouble__new_Ddouble(_x_x2475, _x_x2478, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2471 = kk_std_num_ddouble__lp__plus__rp_(_x_x2472, _x_x2474, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x2481;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x2482 = kk_std_time_timestamp__as_Timestamp(ts_0_10256, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_2 = _con_x2482->since;
    int32_t _x_2 = _con_x2482->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(ts_0_10256, _ctx)) {
      kk_datatype_ptr_free(ts_0_10256, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts_0_10256, _ctx);
    }
    _x_x2481 = _x_2; /*int32*/
  }
  t_10255 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x2471, _x_x2481, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x2483 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10255, _x_x2483, _ctx);
}
 
// Return the NTP time of an instant since the NTP epoch (1900-01-01)
// Since NTP time stamps are ambiguous, times inside a leap second show
// as occurring in the second after the leap second.

kk_std_num_ddouble__ddouble kk_std_time_utc_ntp_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : std/time/instant/instant) -> std/num/ddouble/ddouble */ 
  kk_std_time_timestamp__timestamp ts_10260;
  kk_std_time_instant__timescale _x_x2484 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  ts_10260 = kk_std_time_instant_timestamp_in(i, _x_x2484, _ctx); /*std/time/timestamp/timestamp*/
  kk_integer_t seconds_10081;
  int32_t _x_x2485;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x2486 = kk_std_time_timestamp__as_Timestamp(ts_10260, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_1 = _con_x2486->since;
    int32_t _x_0 = _con_x2486->leap32;
    _x_x2485 = _x_0; /*int32*/
  }
  seconds_10081 = kk_integer_from_int(_x_x2485,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x2487;
  kk_std_num_ddouble__ddouble _x_x2488;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x2489 = kk_std_time_timestamp__as_Timestamp(ts_10260, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x2489->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts_10260, _ctx)) {
      kk_datatype_ptr_free(ts_10260, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts_10260, _ctx);
    }
    _x_x2488 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x2490;
  bool _match_x881;
  double _x_x2491;
  kk_std_core_types__optional _match_x883 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x883, _ctx)) {
    kk_box_t _box_x667 = _match_x883._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x667, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x883, _ctx);
    _x_x2491 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x883, _ctx);
    _x_x2491 = 0x0p+0; /*float64*/
  }
  _match_x881 = (_x_x2491 == (0x0p+0)); /*bool*/
  if (_match_x881) {
    _x_x2490 = kk_std_num_ddouble_ddouble_int_exp(seconds_10081, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2492 = kk_std_num_ddouble_ddouble_int_exp(seconds_10081, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2493;
    double _x_x2494;
    kk_std_core_types__optional _match_x882 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x882, _ctx)) {
      kk_box_t _box_x668 = _match_x882._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x668, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x882, _ctx);
      _x_x2494 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x882, _ctx);
      _x_x2494 = 0x0p+0; /*float64*/
    }
    _x_x2493 = kk_std_num_ddouble__new_Ddouble(_x_x2494, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x2490 = kk_std_num_ddouble__lp__plus__rp_(_x_x2492, _x_x2493, _ctx); /*std/num/ddouble/ddouble*/
  }
  _x_x2487 = kk_std_num_ddouble__lp__plus__rp_(_x_x2488, _x_x2490, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(kk_std_time_utc_ntp2000, _x_x2487, _ctx);
}
 
// The UTC time scale.


// lift anonymous function
struct kk_std_time_utc_ts_utc_create_fun2500__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_utc_create_fun2500(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_create_fun2500(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2500__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_create_fun2500__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_create_fun2500, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_utc_create_fun2500(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2500__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_create_fun2500__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_from_tai(leaps, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_utc_create_fun2502__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_std_time_duration__duration kk_std_time_utc_ts_utc_create_fun2502(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_create_fun2502(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2502__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_create_fun2502__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_create_fun2502, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_ts_utc_create_fun2502(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0_1, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2502__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_create_fun2502__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_to_tai(leaps, utc_0_1, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_utc_create_fun2506__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_ts_utc_create_fun2506(kk_function_t _fself, kk_box_t _b_x677, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_create_fun2506(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2506__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_create_fun2506__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_create_fun2506, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ts_utc_create_fun2506(kk_function_t _fself, kk_box_t _b_x677, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2506__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_create_fun2506__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x2507;
  kk_std_time_timestamp__timestamp utc_0_0_693 = kk_std_time_timestamp__timestamp_unbox(_b_x677, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_core_types__tuple2 tuple2_10075 = kk_std_time_timestamp_days_seconds(utc_0_0_693, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  kk_std_core_types__maybe _match_x880;
  kk_integer_t _x_x2508;
  {
    kk_box_t _box_x669 = tuple2_10075.fst;
    kk_box_t _box_x670 = tuple2_10075.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x669, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    _x_x2508 = _x; /*int*/
  }
  _match_x880 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x2508, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x880, _ctx)) {
    _x_x2507 = kk_std_time_timestamp_solar_secs_per_day; /*std/time/timestamp/timespan*/
  }
  else {
    kk_box_t _box_x671 = _match_x880._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x671, KK_BORROWED, _ctx);
    kk_box_t _box_x672 = _pat_1_0.fst;
    kk_box_t _box_x673 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x672, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x673, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2509 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    kk_std_core_types__maybe_drop(_match_x880, _ctx);
    _x_x2507 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_timestamp_solar_secs_per_day, diff, _ctx); /*std/time/timestamp/timespan*/
  }
  return kk_std_num_ddouble__ddouble_box(_x_x2507, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_utc_create_fun2513__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_ts_utc_create_fun2513(kk_function_t _fself, kk_box_t _b_x682, kk_box_t _b_x683, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_create_fun2513(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2513__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_create_fun2513__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_create_fun2513, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ts_utc_create_fun2513(kk_function_t _fself, kk_box_t _b_x682, kk_box_t _b_x683, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2513__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_create_fun2513__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble _x_x2514;
  kk_std_time_timestamp__timestamp utc_1_694 = kk_std_time_timestamp__timestamp_unbox(_b_x682, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/;
  kk_std_num_ddouble__ddouble tzdelta_695 = kk_std_num_ddouble__ddouble_unbox(_b_x683, KK_OWNED, _ctx); /*std/time/timestamp/timespan*/;
  _x_x2514 = kk_std_time_utc_utc_to_mjd(leaps, utc_1_694, tzdelta_695, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__ddouble_box(_x_x2514, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_utc_create_fun2516__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
};
static kk_box_t kk_std_time_utc_ts_utc_create_fun2516(kk_function_t _fself, kk_box_t _b_x688, kk_box_t _b_x689, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_create_fun2516(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2516__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_create_fun2516__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_create_fun2516, kk_context());
  _self->leaps = leaps;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_utc_ts_utc_create_fun2516(kk_function_t _fself, kk_box_t _b_x688, kk_box_t _b_x689, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_create_fun2516__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_create_fun2516__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp _x_x2517;
  kk_integer_t days_696 = kk_integer_unbox(_b_x688, _ctx); /*int*/;
  kk_std_num_ddouble__ddouble frac_697 = kk_std_num_ddouble__ddouble_unbox(_b_x689, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/;
  _x_x2517 = kk_std_time_utc_utc_from_mjd(leaps, days_696, frac_697, _ctx); /*std/time/utc/utc-timestamp*/
  return kk_std_time_timestamp__timestamp_box(_x_x2517, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_ts_utc_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_string_t _x_x2495;
  kk_define_string_literal(, _s_x2496, 3, "UTC", _ctx)
  _x_x2495 = kk_string_dup(_s_x2496, _ctx); /*string*/
  kk_string_t _x_x2497;
  kk_define_string_literal(, _s_x2498, 3, "UTC", _ctx)
  _x_x2497 = kk_string_dup(_s_x2498, _ctx); /*string*/
  kk_function_t _x_x2499;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2499 = kk_std_time_utc_new_ts_utc_create_fun2500(leaps, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_function_t _x_x2501;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2501 = kk_std_time_utc_new_ts_utc_create_fun2502(leaps, _ctx); /*(utc@0@1 : std/time/timestamp/timestamp) -> std/time/duration/duration*/
  kk_std_core_types__maybe _x_x2503;
  kk_box_t _x_x2504;
  kk_function_t _x_x2505;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2505 = kk_std_time_utc_new_ts_utc_create_fun2506(leaps, _ctx); /*(675) -> 676*/
  _x_x2504 = kk_function_box(_x_x2505, _ctx); /*10024*/
  _x_x2503 = kk_std_core_types__new_Just(_x_x2504, _ctx); /*maybe<10024>*/
  kk_std_core_types__maybe _x_x2510;
  kk_box_t _x_x2511;
  kk_function_t _x_x2512;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2512 = kk_std_time_utc_new_ts_utc_create_fun2513(leaps, _ctx); /*(679, 680) -> 681*/
  _x_x2511 = kk_function_box(_x_x2512, _ctx); /*10024*/
  _x_x2510 = kk_std_core_types__new_Just(_x_x2511, _ctx); /*maybe<10024>*/
  kk_std_core_types__maybe _x_x2515 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_utc_new_ts_utc_create_fun2516(leaps, _ctx), _ctx), _ctx); /*maybe<10024>*/
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x2495, _x_x2497, _x_x2499, _x_x2501, _x_x2503, _x_x2510, _x_x2515, _ctx);
}
 
// [Unix](https://en.wikipedia.org/wiki/Unix_time) time scale based on Unix seconds.
// It equals the `ts-ti` time scale.

kk_std_time_instant__timescale kk_std_time_utc_ts_unix;
 
// /*----------------------------------------------------------------------------
//   UTC-SLS to TAI conversion
// ----------------------------------------------------------------------------*/

kk_std_core_types__maybe kk_std_time_utc_utc_sls_leap_in_day(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) { /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, utc : utc-timestamp) -> maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)> */ 
  kk_std_core_types__tuple2 tuple2_10075;
  kk_std_time_timestamp__timestamp _x_x2518 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
  tuple2_10075 = kk_std_time_timestamp_days_seconds(_x_x2518, _ctx); /*(int, std/num/ddouble/ddouble)*/
  kk_std_core_types__maybe _match_x873;
  kk_integer_t _x_x2519;
  {
    kk_box_t _box_x698 = tuple2_10075.fst;
    kk_box_t _box_x699 = tuple2_10075.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x698, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    _x_x2519 = _x; /*int*/
  }
  _match_x873 = kk_std_time_utc_utc_leap_in_day(leaps, _x_x2519, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x873, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x700 = _match_x873._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1_0 = kk_std_core_types__tuple2_unbox(_box_x700, KK_BORROWED, _ctx);
    kk_box_t _box_x701 = _pat_1_0.fst;
    kk_box_t _box_x702 = _pat_1_0.snd;
    kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x701, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble diff = kk_std_num_ddouble__ddouble_unbox(_box_x702, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2520 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
    kk_std_time_timestamp__timestamp_dup(start, _ctx);
    kk_std_core_types__maybe_drop(_match_x873, _ctx);
    kk_std_time_timestamp__timestamp ts_0_10271;
    kk_std_time_timestamp__timestamp _x_x2521 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    ts_0_10271 = kk_std_time_timestamp__lp__dash__rp_(_x_x2521, smooth, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp smooth_start;
    kk_std_num_ddouble__ddouble _x_x2522;
    kk_std_num_ddouble__ddouble _x_x2523;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2524 = kk_std_time_timestamp__as_Timestamp(ts_0_10271, _ctx);
      kk_std_num_ddouble__ddouble _x_0 = _con_x2524->since;
      _x_x2523 = _x_0; /*std/time/timestamp/timespan*/
    }
    _x_x2522 = kk_std_num_ddouble__lp__plus__rp_(_x_x2523, diff, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x2525;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2526 = kk_std_time_timestamp__as_Timestamp(ts_0_10271, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x2526->since;
      int32_t _x_0_0 = _con_x2526->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts_0_10271, _ctx)) {
        kk_datatype_ptr_free(ts_0_10271, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts_0_10271, _ctx);
      }
      _x_x2525 = _x_0_0; /*int32*/
    }
    smooth_start = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x2522, _x_x2525, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp smooth_end;
    kk_std_time_timestamp__timestamp _x_x2527 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    smooth_end = kk_std_time_timestamp_add_leap_seconds(_x_x2527, diff, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__order x_10020;
    kk_std_time_timestamp__timestamp _x_x2528 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
    kk_std_time_timestamp__timestamp _x_x2529 = kk_std_time_timestamp__timestamp_dup(smooth_start, _ctx); /*std/time/timestamp/timestamp*/
    x_10020 = kk_std_time_timestamp_cmp(_x_x2528, _x_x2529, _ctx); /*order*/
    bool _match_x874;
    kk_integer_t _brw_x878;
    if (kk_std_core_types__is_Lt(x_10020, _ctx)) {
      _brw_x878 = kk_integer_from_small(-1); /*int*/
      goto _match_x2530;
    }
    if (kk_std_core_types__is_Eq(x_10020, _ctx)) {
      _brw_x878 = kk_integer_from_small(0); /*int*/
      goto _match_x2530;
    }
    {
      _brw_x878 = kk_integer_from_small(1); /*int*/
    }
    _match_x2530: ;
    bool _brw_x879 = kk_integer_neq_borrow(_brw_x878,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x878, _ctx);
    _match_x874 = _brw_x879; /*bool*/
    if (_match_x874) {
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
      kk_std_core_types__order x_10022;
      kk_std_time_timestamp__timestamp _x_x2531 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/utc/utc-timestamp*/
      kk_std_time_timestamp__timestamp _x_x2532 = kk_std_time_timestamp__timestamp_dup(smooth_end, _ctx); /*std/time/timestamp/timestamp*/
      x_10022 = kk_std_time_timestamp_cmp(_x_x2531, _x_x2532, _ctx); /*order*/
      bool _match_x875;
      kk_integer_t _brw_x876;
      if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
        _brw_x876 = kk_integer_from_small(-1); /*int*/
        goto _match_x2533;
      }
      if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
        _brw_x876 = kk_integer_from_small(0); /*int*/
        goto _match_x2533;
      }
      {
        _brw_x876 = kk_integer_from_small(1); /*int*/
      }
      _match_x2533: ;
      bool _brw_x877 = kk_integer_eq_borrow(_brw_x876,(kk_integer_from_small(1)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x876, _ctx);
      _match_x875 = _brw_x877; /*bool*/
      if (_match_x875) {
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
        kk_std_num_ddouble__ddouble _x_x2534;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2535 = kk_std_time_timestamp__as_Timestamp(smooth_end, _ctx);
          kk_std_num_ddouble__ddouble _x_2 = _con_x2535->since;
          if kk_likely(kk_datatype_ptr_is_unique(smooth_end, _ctx)) {
            kk_datatype_ptr_free(smooth_end, _ctx);
          }
          else {
            kk_datatype_ptr_decref(smooth_end, _ctx);
          }
          _x_x2534 = _x_2; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x2536;
        double _x_x2537;
        double _x_x2538;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2539 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_3 = _con_x2539->since;
          {
            double _x_1 = _x_3.hi;
            _x_x2538 = _x_1; /*float64*/
          }
        }
        _x_x2537 = (-_x_x2538); /*float64*/
        double _x_x2540;
        double _x_x2541;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2542 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x2542->since;
          {
            double _x_0_1 = _x_3_0.lo;
            _x_x2541 = _x_0_1; /*float64*/
          }
        }
        _x_x2540 = (-_x_x2541); /*float64*/
        _x_x2536 = kk_std_num_ddouble__new_Ddouble(_x_x2537, _x_x2540, _ctx); /*std/num/ddouble/ddouble*/
        smooth_total = kk_std_num_ddouble__lp__plus__rp_(_x_x2534, _x_x2536, _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble x_0_10281 = kk_std_time_timestamp_unsafe_timespan_withleap(utc_0, _ctx); /*std/time/timestamp/timespan*/;
        kk_std_num_ddouble__ddouble dt;
        kk_std_num_ddouble__ddouble _x_x2543;
        double _x_x2544;
        double _x_x2545;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2546 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_5 = _con_x2546->since;
          {
            double _x_4 = _x_5.hi;
            _x_x2545 = _x_4; /*float64*/
          }
        }
        _x_x2544 = (-_x_x2545); /*float64*/
        double _x_x2547;
        double _x_x2548;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2549 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
          kk_std_num_ddouble__ddouble _x_5_0 = _con_x2549->since;
          {
            double _x_0_2 = _x_5_0.lo;
            _x_x2548 = _x_0_2; /*float64*/
          }
        }
        _x_x2547 = (-_x_x2548); /*float64*/
        _x_x2543 = kk_std_num_ddouble__new_Ddouble(_x_x2544, _x_x2547, _ctx); /*std/num/ddouble/ddouble*/
        dt = kk_std_num_ddouble__lp__plus__rp_(x_0_10281, _x_x2543, _ctx); /*std/num/ddouble/ddouble*/
        kk_box_t _x_x2550;
        kk_std_core_types__tuple4 _x_x2551 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_time_timestamp__timestamp_box(start, _ctx), kk_std_time_timestamp__timestamp_box(smooth_start, _ctx), kk_std_num_ddouble__ddouble_box(smooth_total, _ctx), kk_std_num_ddouble__ddouble_box(dt, _ctx), _ctx); /*(10046, 10047, 10048, 10049)*/
        _x_x2550 = kk_std_core_types__tuple4_box(_x_x2551, _ctx); /*10024*/
        return kk_std_core_types__new_Just(_x_x2550, _ctx);
      }
    }
  }
}

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_from_tai(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_duration__duration tai_since, kk_context_t* _ctx) { /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, tai-since : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp utc_0;
  kk_std_time_utc__leaps_table _x_x2552 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  utc_0 = kk_std_time_utc_utc_from_tai(_x_x2552, tai_since, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_core_types__maybe _match_x872;
  kk_std_time_timestamp__timestamp _x_x2553 = kk_std_time_timestamp__timestamp_dup(utc_0, _ctx); /*std/time/timestamp/timestamp*/
  _match_x872 = kk_std_time_utc_utc_sls_leap_in_day(leaps, smooth, _x_x2553, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x872, _ctx)) {
    return utc_0;
  }
  {
    kk_box_t _box_x713 = _match_x872._cons.Just.value;
    kk_std_core_types__tuple4 _pat_1 = kk_std_core_types__tuple4_unbox(_box_x713, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x2554 = kk_std_core_types__as_Tuple4(_pat_1, _ctx);
    kk_box_t _box_x714 = _con_x2554->fst;
    kk_box_t _box_x715 = _con_x2554->snd;
    kk_box_t _box_x716 = _con_x2554->thd;
    kk_box_t _box_x717 = _con_x2554->field4;
    kk_std_time_timestamp__timestamp _pat_2 = kk_std_time_timestamp__timestamp_unbox(_box_x714, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp smooth_start = kk_std_time_timestamp__timestamp_unbox(_box_x715, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble smooth_total = kk_std_num_ddouble__ddouble_unbox(_box_x716, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble dt = kk_std_num_ddouble__ddouble_unbox(_box_x717, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2555 = kk_std_time_timestamp__as_Timestamp(_pat_2, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2556 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
    kk_std_time_timestamp__timestamp_drop(utc_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(smooth_start, _ctx);
    kk_std_core_types__maybe_drop(_match_x872, _ctx);
    kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__fs__rp_(dt, smooth, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble t_10285 = kk_std_num_ddouble__lp__star__rp_(frac, smooth_total, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble _x_x2557;
    kk_std_num_ddouble__ddouble _x_x2558;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2559 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x2559->since;
      _x_x2558 = _x; /*std/time/timestamp/timespan*/
    }
    _x_x2557 = kk_std_num_ddouble__lp__plus__rp_(_x_x2558, t_10285, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x2560;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2561 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x2561->since;
      int32_t _x_0 = _con_x2561->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(smooth_start, _ctx)) {
        kk_datatype_ptr_free(smooth_start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(smooth_start, _ctx);
      }
      _x_x2560 = _x_0; /*int32*/
    }
    return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x2557, _x_x2560, _ctx);
  }
}

kk_std_time_duration__duration kk_std_time_utc_utc_sls_to_tai(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_timestamp__timestamp sls, kk_context_t* _ctx) { /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, sls : utc-timestamp) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp utc_0;
  kk_std_core_types__maybe _match_x868;
  kk_std_time_utc__leaps_table _x_x2562 = kk_std_time_utc__leaps_table_dup(leaps, _ctx); /*std/time/utc/leaps-table*/
  kk_std_time_timestamp__timestamp _x_x2563 = kk_std_time_timestamp__timestamp_dup(sls, _ctx); /*std/time/utc/utc-timestamp*/
  _match_x868 = kk_std_time_utc_utc_sls_leap_in_day(_x_x2562, smooth, _x_x2563, _ctx); /*maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)>*/
  if (kk_std_core_types__is_Nothing(_match_x868, _ctx)) {
    utc_0 = sls; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_box_t _box_x718 = _match_x868._cons.Just.value;
    kk_std_core_types__tuple4 _pat_1 = kk_std_core_types__tuple4_unbox(_box_x718, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x2564 = kk_std_core_types__as_Tuple4(_pat_1, _ctx);
    kk_box_t _box_x719 = _con_x2564->fst;
    kk_box_t _box_x720 = _con_x2564->snd;
    kk_box_t _box_x721 = _con_x2564->thd;
    kk_box_t _box_x722 = _con_x2564->field4;
    kk_std_time_timestamp__timestamp start = kk_std_time_timestamp__timestamp_unbox(_box_x719, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp smooth_start = kk_std_time_timestamp__timestamp_unbox(_box_x720, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble smooth_total = kk_std_num_ddouble__ddouble_unbox(_box_x721, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble dt = kk_std_num_ddouble__ddouble_unbox(_box_x722, KK_BORROWED, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2565 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x2566 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
    kk_reuse_t _ru_x1261 = kk_reuse_null; /*@reuse*/;
    kk_reuse_t _x_x2567 = kk_datatype_ptr_dropn_reuse(sls, (KK_I32(0)), _ctx); /*@reuse*/
    _ru_x1261 = _x_x2567;
    kk_std_time_timestamp__timestamp_dup(smooth_start, _ctx);
    kk_std_time_timestamp__timestamp_dup(start, _ctx);
    kk_std_core_types__maybe_drop(_match_x868, _ctx);
    kk_std_num_ddouble__ddouble frac = kk_std_num_ddouble__lp__fs__rp_(dt, smooth_total, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_num_ddouble__ddouble t_10287 = kk_std_num_ddouble__lp__star__rp_(frac, smooth, _ctx); /*std/num/ddouble/ddouble*/;
    kk_std_time_timestamp__timestamp utc0;
    kk_std_num_ddouble__ddouble _x_x2568;
    kk_std_num_ddouble__ddouble _x_x2569;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2570 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x2570->since;
      _x_x2569 = _x; /*std/time/timestamp/timespan*/
    }
    _x_x2568 = kk_std_num_ddouble__lp__plus__rp_(_x_x2569, t_10287, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x2571;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2572 = kk_std_time_timestamp__as_Timestamp(smooth_start, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x2572->since;
      int32_t _x_0 = _con_x2572->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(smooth_start, _ctx)) {
        kk_datatype_ptr_free(smooth_start, _ctx);
      }
      else {
        kk_datatype_ptr_decref(smooth_start, _ctx);
      }
      _x_x2571 = _x_0; /*int32*/
    }
    utc0 = kk_std_time_timestamp__new_Timestamp(_ru_x1261, 0, _x_x2568, _x_x2571, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__order x_10020;
    kk_std_time_timestamp__timestamp _x_x2573 = kk_std_time_timestamp__timestamp_dup(utc0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x2574 = kk_std_time_timestamp__timestamp_dup(start, _ctx); /*std/time/timestamp/timestamp*/
    x_10020 = kk_std_time_timestamp_cmp(_x_x2573, _x_x2574, _ctx); /*order*/
    bool _match_x869;
    kk_integer_t _brw_x870;
    if (kk_std_core_types__is_Lt(x_10020, _ctx)) {
      _brw_x870 = kk_integer_from_small(-1); /*int*/
      goto _match_x2575;
    }
    if (kk_std_core_types__is_Eq(x_10020, _ctx)) {
      _brw_x870 = kk_integer_from_small(0); /*int*/
      goto _match_x2575;
    }
    {
      _brw_x870 = kk_integer_from_small(1); /*int*/
    }
    _match_x2575: ;
    bool _brw_x871 = kk_integer_neq_borrow(_brw_x870,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x870, _ctx);
    _match_x869 = _brw_x871; /*bool*/
    if (_match_x869) {
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
      kk_std_num_ddouble__ddouble _x_x2576;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2577 = kk_std_time_timestamp__as_Timestamp(utc0, _ctx);
        kk_std_num_ddouble__ddouble _x_2 = _con_x2577->since;
        if kk_likely(kk_datatype_ptr_is_unique(utc0, _ctx)) {
          kk_datatype_ptr_free(utc0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(utc0, _ctx);
        }
        _x_x2576 = _x_2; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x2578;
      double _x_x2579;
      double _x_x2580;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2581 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x2581->since;
        {
          double _x_1 = _x_3.hi;
          _x_x2580 = _x_1; /*float64*/
        }
      }
      _x_x2579 = (-_x_x2580); /*float64*/
      double _x_x2582;
      double _x_x2583;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2584 = kk_std_time_timestamp__as_Timestamp(start, _ctx);
        kk_std_num_ddouble__ddouble _x_3_0 = _con_x2584->since;
        {
          double _x_0_0 = _x_3_0.lo;
          _x_x2583 = _x_0_0; /*float64*/
        }
      }
      _x_x2582 = (-_x_x2583); /*float64*/
      _x_x2578 = kk_std_num_ddouble__new_Ddouble(_x_x2579, _x_x2582, _ctx); /*std/num/ddouble/ddouble*/
      ldiff = kk_std_num_ddouble__lp__plus__rp_(_x_x2576, _x_x2578, _ctx); /*std/num/ddouble/ddouble*/
      utc_0 = kk_std_time_timestamp_add_leap_seconds(start, ldiff, _ctx); /*std/time/utc/utc-timestamp*/
    }
  }
  return kk_std_time_utc_utc_to_tai(leaps, utc_0, _ctx);
}
 
// Create a new smoothed leap second time scale with an optional period during
// which smoothing takes place. This is 1000s for `ts-utc-sls`.


// lift anonymous function
struct kk_std_time_utc_utc_sls_timescale_fun2592__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_timescale_fun2592(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_sls_timescale_fun2592(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3636, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2592__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_sls_timescale_fun2592__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_sls_timescale_fun2592, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3636 = _uniq_smooth_3636;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_timescale_fun2592(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2592__t* _self = kk_function_as(struct kk_std_time_utc_utc_sls_timescale_fun2592__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3636 = _self->_uniq_smooth_3636; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3636, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_from_tai(leaps, _uniq_smooth_3636, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_utc_sls_timescale_fun2593__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
};
static kk_std_time_duration__duration kk_std_time_utc_utc_sls_timescale_fun2593(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_utc_sls_timescale_fun2593(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3636, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2593__t* _self = kk_function_alloc_as(struct kk_std_time_utc_utc_sls_timescale_fun2593__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_utc_sls_timescale_fun2593, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3636 = _uniq_smooth_3636;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_utc_sls_timescale_fun2593(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_utc_sls_timescale_fun2593__t* _self = kk_function_as(struct kk_std_time_utc_utc_sls_timescale_fun2593__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3636 = _self->_uniq_smooth_3636; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3636, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_to_tai(leaps, _uniq_smooth_3636, utc_0, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_utc_sls_timescale(kk_string_t name, kk_std_time_utc__leaps_table leaps, kk_std_core_types__optional smooth, kk_context_t* _ctx) { /* (name : string, leaps : leaps-table, smooth : ? std/time/timestamp/timespan) -> std/time/instant/timescale */ 
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
  if (kk_std_core_types__is_Optional(smooth, _ctx)) {
    kk_box_t _box_x723 = smooth._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_smooth_3637 = kk_std_num_ddouble__ddouble_unbox(_box_x723, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(smooth, _ctx);
    _uniq_smooth_3636 = _uniq_smooth_3637; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(smooth, _ctx);
    bool _match_x865;
    double _x_x2585;
    kk_std_core_types__optional _match_x867 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x867, _ctx)) {
      kk_box_t _box_x724 = _match_x867._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x724, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x867, _ctx);
      _x_x2585 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x867, _ctx);
      _x_x2585 = 0x0p+0; /*float64*/
    }
    _match_x865 = (_x_x2585 == (0x0p+0)); /*bool*/
    if (_match_x865) {
      _uniq_smooth_3636 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x2586 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2587;
      double _x_x2588;
      kk_std_core_types__optional _match_x866 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x866, _ctx)) {
        kk_box_t _box_x725 = _match_x866._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x725, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x866, _ctx);
        _x_x2588 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x866, _ctx);
        _x_x2588 = 0x0p+0; /*float64*/
      }
      _x_x2587 = kk_std_num_ddouble__new_Ddouble(_x_x2588, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _uniq_smooth_3636 = kk_std_num_ddouble__lp__plus__rp_(_x_x2586, _x_x2587, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  kk_string_t _x_x2589;
  kk_define_string_literal(, _s_x2590, 7, "UTC-SLS", _ctx)
  _x_x2589 = kk_string_dup(_s_x2590, _ctx); /*string*/
  kk_function_t _x_x2591;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2591 = kk_std_time_utc_new_utc_sls_timescale_fun2592(leaps, _uniq_smooth_3636, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_core_types__maybe _x_x2594;
  kk_std_core_types__optional _match_x864 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x864, _ctx)) {
    kk_box_t _box_x726 = _match_x864._cons._Optional.value;
    kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x726, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
    kk_std_core_types__optional_drop(_match_x864, _ctx);
    _x_x2594 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x864, _ctx);
    _x_x2594 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x2595;
  kk_std_core_types__optional _match_x863 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x863, _ctx)) {
    kk_box_t _box_x727 = _match_x863._cons._Optional.value;
    kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x727, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
    kk_std_core_types__optional_drop(_match_x863, _ctx);
    _x_x2595 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x863, _ctx);
    _x_x2595 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x2596;
  kk_std_core_types__optional _match_x862 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x862, _ctx)) {
    kk_box_t _box_x728 = _match_x862._cons._Optional.value;
    kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x728, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
    kk_std_core_types__optional_drop(_match_x862, _ctx);
    _x_x2596 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x862, _ctx);
    _x_x2596 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, name, _x_x2589, _x_x2591, kk_std_time_utc_new_utc_sls_timescale_fun2593(leaps, _uniq_smooth_3636, _ctx), _x_x2594, _x_x2595, _x_x2596, _ctx);
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
struct kk_std_time_utc_ts_utc_sls_create_fun2606__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_utc_sls_create_fun2606(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_sls_create_fun2606(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3636, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2606__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_sls_create_fun2606__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_sls_create_fun2606, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3636 = _uniq_smooth_3636;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_utc_sls_create_fun2606(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2606__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_sls_create_fun2606__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3636 = _self->_uniq_smooth_3636; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3636, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_from_tai(leaps, _uniq_smooth_3636, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_utc_sls_create_fun2607__t {
  struct kk_function_s _base;
  kk_std_time_utc__leaps_table leaps;
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
};
static kk_std_time_duration__duration kk_std_time_utc_ts_utc_sls_create_fun2607(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_utc_sls_create_fun2607(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble _uniq_smooth_3636, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2607__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_utc_sls_create_fun2607__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_utc_sls_create_fun2607, kk_context());
  _self->leaps = leaps;
  _self->_uniq_smooth_3636 = _uniq_smooth_3636;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_ts_utc_sls_create_fun2607(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_utc_sls_create_fun2607__t* _self = kk_function_as(struct kk_std_time_utc_ts_utc_sls_create_fun2607__t*, _fself, _ctx);
  kk_std_time_utc__leaps_table leaps = _self->leaps; /* std/time/utc/leaps-table */
  kk_std_num_ddouble__ddouble _uniq_smooth_3636 = _self->_uniq_smooth_3636; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_time_utc__leaps_table_dup(leaps, _ctx);kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3636, _ctx);}, {}, _ctx)
  return kk_std_time_utc_utc_sls_to_tai(leaps, _uniq_smooth_3636, utc_0, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_ts_utc_sls_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
  kk_std_core_types__optional _match_x858 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x858, _ctx)) {
    kk_box_t _box_x729 = _match_x858._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_smooth_3637 = kk_std_num_ddouble__ddouble_unbox(_box_x729, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x858, _ctx);
    _uniq_smooth_3636 = _uniq_smooth_3637; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x858, _ctx);
    bool _match_x859;
    double _x_x2597;
    kk_std_core_types__optional _match_x861 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x861, _ctx)) {
      kk_box_t _box_x730 = _match_x861._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x730, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x861, _ctx);
      _x_x2597 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x861, _ctx);
      _x_x2597 = 0x0p+0; /*float64*/
    }
    _match_x859 = (_x_x2597 == (0x0p+0)); /*bool*/
    if (_match_x859) {
      _uniq_smooth_3636 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x2598 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2599;
      double _x_x2600;
      kk_std_core_types__optional _match_x860 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x860, _ctx)) {
        kk_box_t _box_x731 = _match_x860._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x731, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x860, _ctx);
        _x_x2600 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x860, _ctx);
        _x_x2600 = 0x0p+0; /*float64*/
      }
      _x_x2599 = kk_std_num_ddouble__new_Ddouble(_x_x2600, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _uniq_smooth_3636 = kk_std_num_ddouble__lp__plus__rp_(_x_x2598, _x_x2599, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  kk_string_t _x_x2601;
  kk_define_string_literal(, _s_x2602, 7, "UTC-SLS", _ctx)
  _x_x2601 = kk_string_dup(_s_x2602, _ctx); /*string*/
  kk_string_t _x_x2603;
  kk_define_string_literal(, _s_x2604, 7, "UTC-SLS", _ctx)
  _x_x2603 = kk_string_dup(_s_x2604, _ctx); /*string*/
  kk_function_t _x_x2605;
  kk_std_time_utc__leaps_table_dup(leaps, _ctx);
  _x_x2605 = kk_std_time_utc_new_ts_utc_sls_create_fun2606(leaps, _uniq_smooth_3636, _ctx); /*(tai : std/time/duration/duration) -> std/time/timestamp/timestamp*/
  kk_std_core_types__maybe _x_x2608;
  kk_std_core_types__optional _match_x857 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x857, _ctx)) {
    kk_box_t _box_x732 = _match_x857._cons._Optional.value;
    kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x732, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
    kk_std_core_types__optional_drop(_match_x857, _ctx);
    _x_x2608 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x857, _ctx);
    _x_x2608 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x2609;
  kk_std_core_types__optional _match_x856 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x856, _ctx)) {
    kk_box_t _box_x733 = _match_x856._cons._Optional.value;
    kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x733, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
    kk_std_core_types__optional_drop(_match_x856, _ctx);
    _x_x2609 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x856, _ctx);
    _x_x2609 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x2610;
  kk_std_core_types__optional _match_x855 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x855, _ctx)) {
    kk_box_t _box_x734 = _match_x855._cons._Optional.value;
    kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x734, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
    kk_std_core_types__optional_drop(_match_x855, _ctx);
    _x_x2610 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x855, _ctx);
    _x_x2610 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x2601, _x_x2603, _x_x2605, kk_std_time_utc_new_ts_utc_sls_create_fun2607(leaps, _uniq_smooth_3636, _ctx), _x_x2608, _x_x2609, _x_x2610, _ctx);
}
 
// TI time scale with smoothed leap seconds.
// Implements a TI time scale (`ts-ti`) except without ever showing leap seconds.
// TI-SLS is equivalent to TI except for the last 1000 seconds of a day where
// a leap second occurs. On such day, the leap second time step (positive or negative)
// is distributed over the last 1000 seconds of the day. On the full hour, TI
// and TI-SLS are equal again.


// lift anonymous function
struct kk_std_time_utc_ts_ti_sls_fun2619__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
};
static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_ti_sls_fun2619(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_sls_fun2619(kk_std_num_ddouble__ddouble _uniq_smooth_3636, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2619__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_ti_sls_fun2619__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_ti_sls_fun2619, kk_context());
  _self->_uniq_smooth_3636 = _uniq_smooth_3636;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_utc_ts_ti_sls_fun2619(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2619__t* _self = kk_function_as(struct kk_std_time_utc_ts_ti_sls_fun2619__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble _uniq_smooth_3636 = _self->_uniq_smooth_3636; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3636, _ctx);}, {}, _ctx)
  kk_std_time_utc__leaps_table _x_x2620 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  return kk_std_time_utc_utc_sls_from_tai(_x_x2620, _uniq_smooth_3636, tai, _ctx);
}


// lift anonymous function
struct kk_std_time_utc_ts_ti_sls_fun2621__t {
  struct kk_function_s _base;
  kk_std_num_ddouble__ddouble _uniq_smooth_3636;
};
static kk_std_time_duration__duration kk_std_time_utc_ts_ti_sls_fun2621(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_utc_new_ts_ti_sls_fun2621(kk_std_num_ddouble__ddouble _uniq_smooth_3636, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2621__t* _self = kk_function_alloc_as(struct kk_std_time_utc_ts_ti_sls_fun2621__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_utc_ts_ti_sls_fun2621, kk_context());
  _self->_uniq_smooth_3636 = _uniq_smooth_3636;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_utc_ts_ti_sls_fun2621(kk_function_t _fself, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx) {
  struct kk_std_time_utc_ts_ti_sls_fun2621__t* _self = kk_function_as(struct kk_std_time_utc_ts_ti_sls_fun2621__t*, _fself, _ctx);
  kk_std_num_ddouble__ddouble _uniq_smooth_3636 = _self->_uniq_smooth_3636; /* std/time/timestamp/timespan */
  kk_drop_match(_self, {kk_std_num_ddouble__ddouble_dup(_uniq_smooth_3636, _ctx);}, {}, _ctx)
  kk_std_time_utc__leaps_table _x_x2622 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  return kk_std_time_utc_utc_sls_to_tai(_x_x2622, _uniq_smooth_3636, utc_0, _ctx);
}

kk_std_time_instant__timescale kk_std_time_utc_ts_ti_sls;
 
// lifted local: @lift-leaps-table-y2017@10664, leaps-table-y2017, @spec-x10633
// specialized: std/core/list/@unroll-drop-while@10006, on parameters @uniq-predicate@10626, using:
// @uniq-predicate@10626 = fn(la: std/time/utc/leap-adjust){
//   val x@10022 : order
//         = match ((match ((std/num/float64/cmp((match (la) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                -> (match (@x@0@1) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3: float64) : float64, (@pat@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5: std/time/timestamp/timestamp)
//                    -> (match (@x@3) {
//                     ((@skip std/num/ddouble/Ddouble((@x@0: float64) : float64, (@pat@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3: std/num/ddouble/ddouble)
//                        -> @x@0;
//                   });
//               });
//           }), (match (end@10328) {
//             ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4: float64) : float64, (@pat@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@4: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6: std/time/timestamp/timestamp)
//                -> (match (@x@4) {
//                 ((@skip std/num/ddouble/Ddouble((@x@0@0: float64) : float64, (@pat@0@0@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@1@2: std/num/ddouble/ddouble)
//                    -> @x@0@0;
//               });
//           })))) {
//           ((std/core/types/Eq() : order ) as @pat@2@2: order)
//              -> std/num/float64/cmp((match (la) {
//                 ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                    -> (match (@x@0@1) {
//                     ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0: float64) : float64, (@pat@1@0@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: std/time/timestamp/timestamp)
//                        -> (match (@x@3@0) {
//                         ((@skip std/num/ddouble/Ddouble((@pat@0@1: float64) : float64, (@x@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@0: std/num/ddouble/ddouble)
//                            -> @x@1;
//                       });
//                   });
//               }), (match (end@10328) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4@0: float64) : float64, (@pat@1@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0: std/time/timestamp/timestamp)
//                    -> (match (@x@4@0) {
//                     ((@skip std/num/ddouble/Ddouble((@pat@0@2: float64) : float64, (@x@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@4: std/num/ddouble/ddouble)
//                        -> @x@2;
//                   });
//               }));
//           (ord: order)
//              -> ord;
//         })) {
//           ((std/core/types/Eq() : order ) as @pat@7: order)
//              -> val x@0@10008 : int;
//                 val y@0@10009 : int;
//             (match ((std/core/int/(==)(x@0@10008, y@0@10009))) {
//               ((std/core/types/True() : bool ) as @pat@8: bool)
//                  -> std/core/types/Eq;
//               ((@skip std/core/types/False() : bool ) as @pat@0@5: bool)
//                  -> (match ((std/core/int/(>)(x@0@10008, y@0@10009))) {
//                   ((std/core/types/True() : bool ) as @pat@1@2@0: bool)
//                      -> std/core/types/Gt;
//                   ((@skip std/core/types/False() : bool ) as @pat@2@2@0: bool)
//                      -> std/core/types/Lt;
//                 });
//             });
//           (ord@0: order)
//              -> ord@0;
//         };
//   std/core/int/(==)((match (x@10022) {
//       ((std/core/types/Lt() : order ) as @pat@3@1: order)
//          -> -1;
//       ((std/core/types/Eq() : order ) as @pat@0@0@2: order)
//          -> 0;
//       ((@skip std/core/types/Gt() : order ) as @pat@1@0@1: order)
//          -> 1;
//     }), 1);
// }

kk_std_core_types__list kk_std_time_utc__lift_leaps_table_y2017_10665(kk_std_time_timestamp__timestamp end_10328, kk_std_core_types__list _uniq_xs_10625, kk_context_t* _ctx) { /* (end@10328 : utc-timestamp, list<leap-adjust>) -> list<leap-adjust> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10625, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2626 = kk_std_core_types__as_Cons(_uniq_xs_10625, _ctx);
    kk_box_t _box_x741 = _con_x2626->head;
    kk_std_core_types__list _uniq_xx_10629 = _con_x2626->tail;
    kk_std_time_utc__leap_adjust _uniq_x_10628 = kk_std_time_utc__leap_adjust_unbox(_box_x741, KK_BORROWED, _ctx);
    kk_std_time_utc__leap_adjust_dup(_uniq_x_10628, _ctx);
    kk_std_core_types__list_dup(_uniq_xx_10629, _ctx);
    kk_std_core_types__order x_10022;
    kk_std_core_types__order _match_x843;
    kk_std_core_types__order _match_x847;
    double _x_x2627;
    {
      struct kk_std_time_utc_Leap_adjust* _con_x2628 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10628, _ctx);
      kk_std_time_timestamp__timestamp _x_0_1 = _con_x2628->utc_start;
      kk_std_num_ddouble__ddouble _pat_2_0_1 = _con_x2628->offset;
      kk_std_time_timestamp__timestamp _pat_5_1 = _con_x2628->drift_start;
      kk_std_num_ddouble__ddouble _pat_8_0 = _con_x2628->drift;
      struct kk_std_time_timestamp_Timestamp* _con_x2629 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
      struct kk_std_time_timestamp_Timestamp* _con_x2630 = kk_std_time_timestamp__as_Timestamp(_pat_5_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_0_1, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2631 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x2631->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
          kk_datatype_ptr_free(_x_0_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1, _ctx);
        }
        {
          double _x_0 = _x_3.hi;
          _x_x2627 = _x_0; /*float64*/
        }
      }
    }
    double _x_x2632;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x2633 = kk_std_time_timestamp__as_Timestamp(end_10328, _ctx);
      kk_std_num_ddouble__ddouble _x_4 = _con_x2633->since;
      {
        double _x_0_0 = _x_4.hi;
        _x_x2632 = _x_0_0; /*float64*/
      }
    }
    _match_x847 = kk_std_num_float64_cmp(_x_x2627, _x_x2632, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x847, _ctx)) {
      double _x_x2634;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2635 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10628, _ctx);
        kk_std_time_timestamp__timestamp _x_0_1_0 = _con_x2635->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_0_1_0 = _con_x2635->offset;
        kk_std_time_timestamp__timestamp _pat_5_1_0 = _con_x2635->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_0 = _con_x2635->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2636 = kk_std_time_timestamp__as_Timestamp(_x_0_1_0, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2637 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_0_1_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2638 = kk_std_time_timestamp__as_Timestamp(_x_0_1_0, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x2638->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_0, _ctx)) {
            kk_datatype_ptr_free(_x_0_1_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_0_1_0, _ctx);
          }
          {
            double _x_1 = _x_3_0.lo;
            _x_x2634 = _x_1; /*float64*/
          }
        }
      }
      double _x_x2639;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2640 = kk_std_time_timestamp__as_Timestamp(end_10328, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0 = _con_x2640->since;
        {
          double _x_2 = _x_4_0.lo;
          _x_x2639 = _x_2; /*float64*/
        }
      }
      _match_x843 = kk_std_num_float64_cmp(_x_x2634, _x_x2639, _ctx); /*order*/
    }
    else {
      _match_x843 = _match_x847; /*order*/
    }
    if (kk_std_core_types__is_Eq(_match_x843, _ctx)) {
      kk_integer_t x_0_10008;
      int32_t _x_x2641;
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2642 = kk_std_time_utc__as_Leap_adjust(_uniq_x_10628, _ctx);
        kk_std_time_timestamp__timestamp _x_0_1_1 = _con_x2642->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_0_1_1 = _con_x2642->offset;
        kk_std_time_timestamp__timestamp _pat_5_1_1 = _con_x2642->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_0_1 = _con_x2642->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2643 = kk_std_time_timestamp__as_Timestamp(_x_0_1_1, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2644 = kk_std_time_timestamp__as_Timestamp(_pat_5_1_1, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_uniq_x_10628, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_1_1, _ctx)) {
            kk_datatype_ptr_free(_pat_5_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_1_1, _ctx);
          }
          kk_datatype_ptr_free(_uniq_x_10628, _ctx);
        }
        else {
          kk_std_time_timestamp__timestamp_dup(_x_0_1_1, _ctx);
          kk_datatype_ptr_decref(_uniq_x_10628, _ctx);
        }
        {
          struct kk_std_time_timestamp_Timestamp* _con_x2645 = kk_std_time_timestamp__as_Timestamp(_x_0_1_1, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_6 = _con_x2645->since;
          int32_t _x_5 = _con_x2645->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_1, _ctx)) {
            kk_datatype_ptr_free(_x_0_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_0_1_1, _ctx);
          }
          _x_x2641 = _x_5; /*int32*/
        }
      }
      x_0_10008 = kk_integer_from_int(_x_x2641,kk_context()); /*int*/
      kk_integer_t y_0_10009;
      int32_t _x_x2646;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x2647 = kk_std_time_timestamp__as_Timestamp(end_10328, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_7 = _con_x2647->since;
        int32_t _x_6 = _con_x2647->leap32;
        _x_x2646 = _x_6; /*int32*/
      }
      y_0_10009 = kk_integer_from_int(_x_x2646,kk_context()); /*int*/
      bool _match_x844 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      if (_match_x844) {
        kk_integer_drop(y_0_10009, _ctx);
        kk_integer_drop(x_0_10008, _ctx);
        x_10022 = kk_std_core_types__new_Eq(_ctx); /*order*/
      }
      else {
        bool _match_x845;
        bool _brw_x846 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
        kk_integer_drop(x_0_10008, _ctx);
        kk_integer_drop(y_0_10009, _ctx);
        _match_x845 = _brw_x846; /*bool*/
        if (_match_x845) {
          x_10022 = kk_std_core_types__new_Gt(_ctx); /*order*/
        }
        else {
          x_10022 = kk_std_core_types__new_Lt(_ctx); /*order*/
        }
      }
    }
    else {
      kk_datatype_ptr_dropn(_uniq_x_10628, (KK_I32(2)), _ctx);
      x_10022 = _match_x843; /*order*/
    }
    bool _match_x840;
    kk_integer_t _brw_x841;
    if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
      _brw_x841 = kk_integer_from_small(-1); /*int*/
      goto _match_x2648;
    }
    if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
      _brw_x841 = kk_integer_from_small(0); /*int*/
      goto _match_x2648;
    }
    {
      _brw_x841 = kk_integer_from_small(1); /*int*/
    }
    _match_x2648: ;
    bool _brw_x842 = kk_integer_eq_borrow(_brw_x841,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x841, _ctx);
    _match_x840 = _brw_x842; /*bool*/
    if (_match_x840) {
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10625, _ctx)) {
        kk_std_core_types__list_drop(_uniq_xx_10629, _ctx);
        kk_datatype_ptr_dropn(_uniq_x_10628, (KK_I32(2)), _ctx);
        kk_datatype_ptr_free(_uniq_xs_10625, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_uniq_xs_10625, _ctx);
      }
      { // tailcall
        _uniq_xs_10625 = _uniq_xx_10629;
        goto kk__tailcall;
      }
    }
    {
      kk_std_time_timestamp__timestamp_drop(end_10328, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10629, _ctx);
      return _uniq_xs_10625;
    }
  }
  {
    kk_std_time_timestamp__timestamp_drop(end_10328, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: leaps-table-y2017, @spec-x10624
// specialized: std/core/list/drop-while, on parameters @uniq-predicate@10621, using:
// @uniq-predicate@10621 = fn(la: std/time/utc/leap-adjust){
//   val x@10022 : order
//         = match ((match ((std/num/float64/cmp((match (la) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                -> (match (@x@0@1) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3: float64) : float64, (@pat@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5: std/time/timestamp/timestamp)
//                    -> (match (@x@3) {
//                     ((@skip std/num/ddouble/Ddouble((@x@0: float64) : float64, (@pat@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3: std/num/ddouble/ddouble)
//                        -> @x@0;
//                   });
//               });
//           }), (match (end@10328) {
//             ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4: float64) : float64, (@pat@1@1: float64) : float64) : std/num/ddouble/ddouble ) as @x@4: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6: std/time/timestamp/timestamp)
//                -> (match (@x@4) {
//                 ((@skip std/num/ddouble/Ddouble((@x@0@0: float64) : float64, (@pat@0@0@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@1@2: std/num/ddouble/ddouble)
//                    -> @x@0@0;
//               });
//           })))) {
//           ((std/core/types/Eq() : order ) as @pat@2@2: order)
//              -> std/num/float64/cmp((match (la) {
//                 ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@1@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0@0: float64) : float64, (@pat@4@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@0@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@1: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@0: float64) : float64, (@pat@10@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@0: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@4@0: std/time/utc/leap-adjust)
//                    -> (match (@x@0@1) {
//                     ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@3@0: float64) : float64, (@pat@1@0@0@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@3@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@0@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: std/time/timestamp/timestamp)
//                        -> (match (@x@3@0) {
//                         ((@skip std/num/ddouble/Ddouble((@pat@0@1: float64) : float64, (@x@1: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@0: std/num/ddouble/ddouble)
//                            -> @x@1;
//                       });
//                   });
//               }), (match (end@10328) {
//                 ((@skip std/time/timestamp/Timestamp(((@skip std/num/ddouble/Ddouble((@pat@0@4@0: float64) : float64, (@pat@1@1@0: float64) : float64) : std/num/ddouble/ddouble ) as @x@4@0: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@1@0: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@0: std/time/timestamp/timestamp)
//                    -> (match (@x@4@0) {
//                     ((@skip std/num/ddouble/Ddouble((@pat@0@2: float64) : float64, (@x@2: float64) : float64) : std/num/ddouble/ddouble ) as @pat@4: std/num/ddouble/ddouble)
//                        -> @x@2;
//                   });
//               }));
//           (ord: order)
//              -> ord;
//         })) {
//           ((std/core/types/Eq() : order ) as @pat@7: order)
//              -> val x@0@10008 : int;
//                 val y@0@10009 : int;
//             (match ((std/core/int/(==)(x@0@10008, y@0@10009))) {
//               ((std/core/types/True() : bool ) as @pat@8: bool)
//                  -> std/core/types/Eq;
//               ((@skip std/core/types/False() : bool ) as @pat@0@5: bool)
//                  -> (match ((std/core/int/(>)(x@0@10008, y@0@10009))) {
//                   ((std/core/types/True() : bool ) as @pat@1@2@0: bool)
//                      -> std/core/types/Gt;
//                   ((@skip std/core/types/False() : bool ) as @pat@2@2@0: bool)
//                      -> std/core/types/Lt;
//                 });
//             });
//           (ord@0: order)
//              -> ord@0;
//         };
//   std/core/int/(==)((match (x@10022) {
//       ((std/core/types/Lt() : order ) as @pat@3@1: order)
//          -> -1;
//       ((std/core/types/Eq() : order ) as @pat@0@0@2: order)
//          -> 0;
//       ((@skip std/core/types/Gt() : order ) as @pat@1@0@1: order)
//          -> 1;
//     }), 1);
// }

kk_std_core_types__list kk_std_time_utc__lift_leaps_table_y2017_10664(kk_std_time_timestamp__timestamp end_10328, kk_std_core_types__list _uniq_xs_10620, kk_context_t* _ctx) { /* (end@10328 : utc-timestamp, list<leap-adjust>) -> list<leap-adjust> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10620, _ctx)) {
    kk_std_time_timestamp__timestamp_drop(end_10328, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_time_utc__lift_leaps_table_y2017_10665(end_10328, _uniq_xs_10620, _ctx);
  }
}
 
// Leap second table up to 2017-01-01Z.

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_y2017;
 
// lifted local: @lift-get-leap-steps@10666, get-leap-steps, @spec-x10646
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10641, using:
// @uniq-f@10641 = fn(las: (std/time/utc/leap-adjust, std/time/utc/leap-adjust)){
//   val ofs1 : std/time/timestamp/timespan;
//   val ofs2 : std/time/timestamp/timespan;
//   std/core/types/Tuple4<std/time/utc/utc-timestamp,std/time/timestamp/timespan,std/time/timestamp/timespan,(std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble)>((match (las) {
//       ((@skip std/core/types/Tuple2((@pat@0@3: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@1: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@11: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//          -> (match (@x@1) {
//           ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@2: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0: float64) : float64, (@pat@4@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9: float64) : float64, (@pat@10: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@5: std/time/utc/leap-adjust)
//              -> @x@0;
//         });
//     }), ofs1, ofs2, (std/core/types/Tuple3<std/time/timestamp/timespan,std/time/utc/utc-timestamp,std/num/ddouble/ddouble>((match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@27: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@23: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@35: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@23) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@18: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@16: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@26: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@11: float64) : float64, (@pat@4@11: float64) : float64) : std/num/ddouble/ddouble ) as @x@22: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@10: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@10: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@11: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@10: float64) : float64, (@pat@10@10: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@10: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@34: std/time/utc/leap-adjust)
//                -> @x@22;
//           });
//       }), (match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@29: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@25: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@37: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@25) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@19: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@17: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@28: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@4@12: float64) : float64, (@pat@5@12: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@12: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@11: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@11: int32) : int32) : std/time/timestamp/timestamp ) as @x@24: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@11: float64) : float64, (@pat@10@11: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@11: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@36: std/time/utc/leap-adjust)
//                -> @x@24;
//           });
//       }), (match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@31: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@27: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@39: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@27) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@20: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@18: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@30: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@4@13: float64) : float64, (@pat@5@13: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@13: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@7@12: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@8@12: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@12: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@12: float64) : float64, (@pat@10@12: float64) : float64) : std/num/ddouble/ddouble ) as @x@26: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@38: std/time/utc/leap-adjust)
//                -> @x@26;
//           });
//       }))));
// }

kk_std_core_types__list kk_std_time_utc__trmc_lift_get_leap_steps_10667(kk_std_core_types__list _uniq_xs_10640, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<(leap-adjust, leap-adjust)>, ctx<list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))>>) -> list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10640, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2663 = kk_std_core_types__as_Cons(_uniq_xs_10640, _ctx);
    kk_box_t _box_x748 = _con_x2663->head;
    kk_std_core_types__list _uniq_xx_10644 = _con_x2663->tail;
    kk_std_core_types__tuple2 _uniq_x_10643 = kk_std_core_types__tuple2_unbox(_box_x748, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1276 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10640, _ctx)) {
      kk_std_core_types__tuple2_dup(_uniq_x_10643, _ctx);
      kk_box_drop(_box_x748, _ctx);
      _ru_x1276 = (kk_datatype_ptr_reuse(_uniq_xs_10640, _ctx));
    }
    else {
      kk_std_core_types__tuple2_dup(_uniq_x_10643, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10644, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10640, _ctx);
    }
    kk_std_num_ddouble__ddouble ofs1;
    bool _match_x835;
    double _x_x2664;
    {
      kk_box_t _box_x749 = _uniq_x_10643.fst;
      kk_box_t _box_x750 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_11 = kk_std_time_utc__leap_adjust_unbox(_box_x749, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_11, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2665 = kk_std_time_utc__as_Leap_adjust(_x_11, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_5 = _con_x2665->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_1 = _con_x2665->offset;
        kk_std_time_timestamp__timestamp _pat_6_0 = _con_x2665->drift_start;
        kk_std_num_ddouble__ddouble _x_3 = _con_x2665->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2666 = kk_std_time_timestamp__as_Timestamp(_pat_0_5, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2667 = kk_std_time_timestamp__as_Timestamp(_pat_6_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_11, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_6_0, _ctx)) {
            kk_datatype_ptr_free(_pat_6_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_6_0, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_5, _ctx)) {
            kk_datatype_ptr_free(_pat_0_5, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_5, _ctx);
          }
          kk_datatype_ptr_free(_x_11, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_11, _ctx);
        }
        {
          double _x_2 = _x_3.hi;
          _x_x2664 = _x_2; /*float64*/
        }
      }
    }
    _match_x835 = (_x_x2664 == (0x0p+0)); /*bool*/
    if (_match_x835) {
      kk_box_t _box_x751 = _uniq_x_10643.fst;
      kk_box_t _box_x752 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_11_0 = kk_std_time_utc__leap_adjust_unbox(_box_x751, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_11_0, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2668 = kk_std_time_utc__as_Leap_adjust(_x_11_0, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_6 = _con_x2668->utc_start;
        kk_std_num_ddouble__ddouble _x_4 = _con_x2668->offset;
        kk_std_time_timestamp__timestamp _pat_5_2 = _con_x2668->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_1 = _con_x2668->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2669 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2670 = kk_std_time_timestamp__as_Timestamp(_pat_5_2, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_11_0, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_2, _ctx)) {
            kk_datatype_ptr_free(_pat_5_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_2, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_6, _ctx)) {
            kk_datatype_ptr_free(_pat_0_6, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_6, _ctx);
          }
          kk_datatype_ptr_free(_x_11_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_11_0, _ctx);
        }
        ofs1 = _x_4; /*std/time/timestamp/timespan*/
      }
    }
    else {
      kk_std_num_ddouble__ddouble days;
      kk_std_num_ddouble__ddouble _x_x2671;
      kk_std_num_ddouble__ddouble _x_x2672;
      {
        kk_box_t _box_x753 = _uniq_x_10643.fst;
        kk_box_t _box_x754 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_1 = kk_std_time_utc__leap_adjust_unbox(_box_x754, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_1, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2673 = kk_std_time_utc__as_Leap_adjust(_x_1, _ctx);
          kk_std_time_timestamp__timestamp _x_0_0 = _con_x2673->utc_start;
          kk_std_num_ddouble__ddouble _pat_2_1 = _con_x2673->offset;
          kk_std_time_timestamp__timestamp _pat_5_0 = _con_x2673->drift_start;
          kk_std_num_ddouble__ddouble _pat_8 = _con_x2673->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2674 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2675 = kk_std_time_timestamp__as_Timestamp(_pat_5_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0, _ctx)) {
              kk_datatype_ptr_free(_pat_5_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_5_0, _ctx);
            }
            kk_datatype_ptr_free(_x_1, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_0_0, _ctx);
            kk_datatype_ptr_decref(_x_1, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x2676 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
            kk_std_num_ddouble__ddouble _x_6 = _con_x2676->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
              kk_datatype_ptr_free(_x_0_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_0_0, _ctx);
            }
            _x_x2672 = _x_6; /*std/time/timestamp/timespan*/
          }
        }
      }
      kk_std_num_ddouble__ddouble _x_x2677;
      double _x_x2678;
      double _x_x2679;
      {
        kk_box_t _box_x755 = _uniq_x_10643.fst;
        kk_box_t _box_x756 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_11_1 = kk_std_time_utc__leap_adjust_unbox(_box_x755, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_11_1, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2680 = kk_std_time_utc__as_Leap_adjust(_x_11_1, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_11 = _con_x2680->utc_start;
          kk_std_num_ddouble__ddouble _pat_3_3 = _con_x2680->offset;
          kk_std_time_timestamp__timestamp _x_8 = _con_x2680->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_2 = _con_x2680->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2681 = kk_std_time_timestamp__as_Timestamp(_pat_0_11, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2682 = kk_std_time_timestamp__as_Timestamp(_x_8, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_11_1, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_11, _ctx)) {
              kk_datatype_ptr_free(_pat_0_11, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_11, _ctx);
            }
            kk_datatype_ptr_free(_x_11_1, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_8, _ctx);
            kk_datatype_ptr_decref(_x_11_1, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x2683 = kk_std_time_timestamp__as_Timestamp(_x_8, _ctx);
            kk_std_num_ddouble__ddouble _x_7 = _con_x2683->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_8, _ctx)) {
              kk_datatype_ptr_free(_x_8, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_8, _ctx);
            }
            {
              double _x_5 = _x_7.hi;
              _x_x2679 = _x_5; /*float64*/
            }
          }
        }
      }
      _x_x2678 = (-_x_x2679); /*float64*/
      double _x_x2684;
      double _x_x2685;
      {
        kk_box_t _box_x757 = _uniq_x_10643.fst;
        kk_box_t _box_x758 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_11_2 = kk_std_time_utc__leap_adjust_unbox(_box_x757, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_11_2, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2686 = kk_std_time_utc__as_Leap_adjust(_x_11_2, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_11_0 = _con_x2686->utc_start;
          kk_std_num_ddouble__ddouble _pat_3_3_0 = _con_x2686->offset;
          kk_std_time_timestamp__timestamp _x_8_0 = _con_x2686->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_2_0 = _con_x2686->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2687 = kk_std_time_timestamp__as_Timestamp(_pat_0_11_0, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2688 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_11_2, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_11_0, _ctx)) {
              kk_datatype_ptr_free(_pat_0_11_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_11_0, _ctx);
            }
            kk_datatype_ptr_free(_x_11_2, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_8_0, _ctx);
            kk_datatype_ptr_decref(_x_11_2, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x2689 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
            kk_std_num_ddouble__ddouble _x_7_0 = _con_x2689->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_8_0, _ctx)) {
              kk_datatype_ptr_free(_x_8_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_8_0, _ctx);
            }
            {
              double _x_0_0_0 = _x_7_0.lo;
              _x_x2685 = _x_0_0_0; /*float64*/
            }
          }
        }
      }
      _x_x2684 = (-_x_x2685); /*float64*/
      _x_x2677 = kk_std_num_ddouble__new_Ddouble(_x_x2678, _x_x2684, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2671 = kk_std_num_ddouble__lp__plus__rp_(_x_x2672, _x_x2677, _ctx); /*std/num/ddouble/ddouble*/
      days = kk_std_num_ddouble__lp__fs__rp_(_x_x2671, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2690;
      {
        kk_box_t _box_x759 = _uniq_x_10643.fst;
        kk_box_t _box_x760 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_11_3 = kk_std_time_utc__leap_adjust_unbox(_box_x759, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_11_3, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2691 = kk_std_time_utc__as_Leap_adjust(_x_11_3, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_12 = _con_x2691->utc_start;
          kk_std_num_ddouble__ddouble _x_9 = _con_x2691->offset;
          kk_std_time_timestamp__timestamp _pat_5_4 = _con_x2691->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_3 = _con_x2691->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2692 = kk_std_time_timestamp__as_Timestamp(_pat_0_12, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2693 = kk_std_time_timestamp__as_Timestamp(_pat_5_4, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_11_3, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_5_4, _ctx)) {
              kk_datatype_ptr_free(_pat_5_4, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_5_4, _ctx);
            }
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_12, _ctx)) {
              kk_datatype_ptr_free(_pat_0_12, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_12, _ctx);
            }
            kk_datatype_ptr_free(_x_11_3, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_11_3, _ctx);
          }
          _x_x2690 = _x_9; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x2694;
      kk_std_num_ddouble__ddouble _x_x2695;
      {
        kk_box_t _box_x761 = _uniq_x_10643.fst;
        kk_box_t _box_x762 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_11_4 = kk_std_time_utc__leap_adjust_unbox(_box_x761, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_11_4, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2696 = kk_std_time_utc__as_Leap_adjust(_x_11_4, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_13 = _con_x2696->utc_start;
          kk_std_num_ddouble__ddouble _pat_3_5 = _con_x2696->offset;
          kk_std_time_timestamp__timestamp _pat_6_4 = _con_x2696->drift_start;
          kk_std_num_ddouble__ddouble _x_10 = _con_x2696->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2697 = kk_std_time_timestamp__as_Timestamp(_pat_0_13, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2698 = kk_std_time_timestamp__as_Timestamp(_pat_6_4, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_11_4, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_6_4, _ctx)) {
              kk_datatype_ptr_free(_pat_6_4, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_6_4, _ctx);
            }
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_13, _ctx)) {
              kk_datatype_ptr_free(_pat_0_13, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_13, _ctx);
            }
            kk_datatype_ptr_free(_x_11_4, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_11_4, _ctx);
          }
          _x_x2695 = _x_10; /*std/num/ddouble/ddouble*/
        }
      }
      _x_x2694 = kk_std_num_ddouble__lp__star__rp_(_x_x2695, days, _ctx); /*std/num/ddouble/ddouble*/
      ofs1 = kk_std_num_ddouble__lp__plus__rp_(_x_x2690, _x_x2694, _ctx); /*std/time/timestamp/timespan*/
    }
    kk_std_num_ddouble__ddouble ofs2;
    bool _match_x834;
    double _x_x2699;
    {
      kk_box_t _box_x763 = _uniq_x_10643.fst;
      kk_box_t _box_x764 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_21 = kk_std_time_utc__leap_adjust_unbox(_box_x764, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_21, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2700 = kk_std_time_utc__as_Leap_adjust(_x_21, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_16 = _con_x2700->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_6 = _con_x2700->offset;
        kk_std_time_timestamp__timestamp _pat_6_5 = _con_x2700->drift_start;
        kk_std_num_ddouble__ddouble _x_13 = _con_x2700->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2701 = kk_std_time_timestamp__as_Timestamp(_pat_0_16, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2702 = kk_std_time_timestamp__as_Timestamp(_pat_6_5, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_21, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_6_5, _ctx)) {
            kk_datatype_ptr_free(_pat_6_5, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_6_5, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_16, _ctx)) {
            kk_datatype_ptr_free(_pat_0_16, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_16, _ctx);
          }
          kk_datatype_ptr_free(_x_21, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_21, _ctx);
        }
        {
          double _x_12 = _x_13.hi;
          _x_x2699 = _x_12; /*float64*/
        }
      }
    }
    _match_x834 = (_x_x2699 == (0x0p+0)); /*bool*/
    if (_match_x834) {
      kk_box_t _box_x765 = _uniq_x_10643.fst;
      kk_box_t _box_x766 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_21_0 = kk_std_time_utc__leap_adjust_unbox(_box_x766, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_21_0, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2703 = kk_std_time_utc__as_Leap_adjust(_x_21_0, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_17 = _con_x2703->utc_start;
        kk_std_num_ddouble__ddouble _x_14 = _con_x2703->offset;
        kk_std_time_timestamp__timestamp _pat_5_7 = _con_x2703->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_6 = _con_x2703->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2704 = kk_std_time_timestamp__as_Timestamp(_pat_0_17, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2705 = kk_std_time_timestamp__as_Timestamp(_pat_5_7, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_21_0, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_7, _ctx)) {
            kk_datatype_ptr_free(_pat_5_7, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_7, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_17, _ctx)) {
            kk_datatype_ptr_free(_pat_0_17, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_17, _ctx);
          }
          kk_datatype_ptr_free(_x_21_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_21_0, _ctx);
        }
        ofs2 = _x_14; /*std/time/timestamp/timespan*/
      }
    }
    else {
      kk_std_num_ddouble__ddouble days_0;
      kk_std_num_ddouble__ddouble _x_x2706;
      kk_std_num_ddouble__ddouble _x_x2707;
      {
        kk_box_t _box_x767 = _uniq_x_10643.fst;
        kk_box_t _box_x768 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_1_0 = kk_std_time_utc__leap_adjust_unbox(_box_x768, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_1_0, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2708 = kk_std_time_utc__as_Leap_adjust(_x_1_0, _ctx);
          kk_std_time_timestamp__timestamp _x_0_1 = _con_x2708->utc_start;
          kk_std_num_ddouble__ddouble _pat_2_1_0 = _con_x2708->offset;
          kk_std_time_timestamp__timestamp _pat_5_0_0 = _con_x2708->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_7 = _con_x2708->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2709 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2710 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_0, _ctx)) {
              kk_datatype_ptr_free(_pat_5_0_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_5_0_0, _ctx);
            }
            kk_datatype_ptr_free(_x_1_0, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_0_1, _ctx);
            kk_datatype_ptr_decref(_x_1_0, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x2711 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
            kk_std_num_ddouble__ddouble _x_16 = _con_x2711->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
              kk_datatype_ptr_free(_x_0_1, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_0_1, _ctx);
            }
            _x_x2707 = _x_16; /*std/time/timestamp/timespan*/
          }
        }
      }
      kk_std_num_ddouble__ddouble _x_x2712;
      double _x_x2713;
      double _x_x2714;
      {
        kk_box_t _box_x769 = _uniq_x_10643.fst;
        kk_box_t _box_x770 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_21_1 = kk_std_time_utc__leap_adjust_unbox(_box_x770, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_21_1, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2715 = kk_std_time_utc__as_Leap_adjust(_x_21_1, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_22 = _con_x2715->utc_start;
          kk_std_num_ddouble__ddouble _pat_3_8 = _con_x2715->offset;
          kk_std_time_timestamp__timestamp _x_18 = _con_x2715->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_7_0 = _con_x2715->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2716 = kk_std_time_timestamp__as_Timestamp(_pat_0_22, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2717 = kk_std_time_timestamp__as_Timestamp(_x_18, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_21_1, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_22, _ctx)) {
              kk_datatype_ptr_free(_pat_0_22, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_22, _ctx);
            }
            kk_datatype_ptr_free(_x_21_1, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_18, _ctx);
            kk_datatype_ptr_decref(_x_21_1, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x2718 = kk_std_time_timestamp__as_Timestamp(_x_18, _ctx);
            kk_std_num_ddouble__ddouble _x_17 = _con_x2718->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_18, _ctx)) {
              kk_datatype_ptr_free(_x_18, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_18, _ctx);
            }
            {
              double _x_15 = _x_17.hi;
              _x_x2714 = _x_15; /*float64*/
            }
          }
        }
      }
      _x_x2713 = (-_x_x2714); /*float64*/
      double _x_x2719;
      double _x_x2720;
      {
        kk_box_t _box_x771 = _uniq_x_10643.fst;
        kk_box_t _box_x772 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_21_2 = kk_std_time_utc__leap_adjust_unbox(_box_x772, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_21_2, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2721 = kk_std_time_utc__as_Leap_adjust(_x_21_2, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_22_0 = _con_x2721->utc_start;
          kk_std_num_ddouble__ddouble _pat_3_8_0 = _con_x2721->offset;
          kk_std_time_timestamp__timestamp _x_18_0 = _con_x2721->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_7_1 = _con_x2721->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2722 = kk_std_time_timestamp__as_Timestamp(_pat_0_22_0, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2723 = kk_std_time_timestamp__as_Timestamp(_x_18_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_21_2, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_22_0, _ctx)) {
              kk_datatype_ptr_free(_pat_0_22_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_22_0, _ctx);
            }
            kk_datatype_ptr_free(_x_21_2, _ctx);
          }
          else {
            kk_std_time_timestamp__timestamp_dup(_x_18_0, _ctx);
            kk_datatype_ptr_decref(_x_21_2, _ctx);
          }
          {
            struct kk_std_time_timestamp_Timestamp* _con_x2724 = kk_std_time_timestamp__as_Timestamp(_x_18_0, _ctx);
            kk_std_num_ddouble__ddouble _x_17_0 = _con_x2724->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_18_0, _ctx)) {
              kk_datatype_ptr_free(_x_18_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_18_0, _ctx);
            }
            {
              double _x_0_1_0 = _x_17_0.lo;
              _x_x2720 = _x_0_1_0; /*float64*/
            }
          }
        }
      }
      _x_x2719 = (-_x_x2720); /*float64*/
      _x_x2712 = kk_std_num_ddouble__new_Ddouble(_x_x2713, _x_x2719, _ctx); /*std/num/ddouble/ddouble*/
      _x_x2706 = kk_std_num_ddouble__lp__plus__rp_(_x_x2707, _x_x2712, _ctx); /*std/num/ddouble/ddouble*/
      days_0 = kk_std_num_ddouble__lp__fs__rp_(_x_x2706, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2725;
      {
        kk_box_t _box_x773 = _uniq_x_10643.fst;
        kk_box_t _box_x774 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_21_3 = kk_std_time_utc__leap_adjust_unbox(_box_x774, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_21_3, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2726 = kk_std_time_utc__as_Leap_adjust(_x_21_3, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_23 = _con_x2726->utc_start;
          kk_std_num_ddouble__ddouble _x_19 = _con_x2726->offset;
          kk_std_time_timestamp__timestamp _pat_5_9 = _con_x2726->drift_start;
          kk_std_num_ddouble__ddouble _pat_8_8 = _con_x2726->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2727 = kk_std_time_timestamp__as_Timestamp(_pat_0_23, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2728 = kk_std_time_timestamp__as_Timestamp(_pat_5_9, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_21_3, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_5_9, _ctx)) {
              kk_datatype_ptr_free(_pat_5_9, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_5_9, _ctx);
            }
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_23, _ctx)) {
              kk_datatype_ptr_free(_pat_0_23, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_23, _ctx);
            }
            kk_datatype_ptr_free(_x_21_3, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_21_3, _ctx);
          }
          _x_x2725 = _x_19; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x2729;
      kk_std_num_ddouble__ddouble _x_x2730;
      {
        kk_box_t _box_x775 = _uniq_x_10643.fst;
        kk_box_t _box_x776 = _uniq_x_10643.snd;
        kk_std_time_utc__leap_adjust _x_21_4 = kk_std_time_utc__leap_adjust_unbox(_box_x776, KK_BORROWED, _ctx);
        kk_std_time_utc__leap_adjust_dup(_x_21_4, _ctx);
        {
          struct kk_std_time_utc_Leap_adjust* _con_x2731 = kk_std_time_utc__as_Leap_adjust(_x_21_4, _ctx);
          kk_std_time_timestamp__timestamp _pat_0_24 = _con_x2731->utc_start;
          kk_std_num_ddouble__ddouble _pat_3_10 = _con_x2731->offset;
          kk_std_time_timestamp__timestamp _pat_6_9 = _con_x2731->drift_start;
          kk_std_num_ddouble__ddouble _x_20 = _con_x2731->drift;
          struct kk_std_time_timestamp_Timestamp* _con_x2732 = kk_std_time_timestamp__as_Timestamp(_pat_0_24, _ctx);
          struct kk_std_time_timestamp_Timestamp* _con_x2733 = kk_std_time_timestamp__as_Timestamp(_pat_6_9, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_x_21_4, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_6_9, _ctx)) {
              kk_datatype_ptr_free(_pat_6_9, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_6_9, _ctx);
            }
            if kk_likely(kk_datatype_ptr_is_unique(_pat_0_24, _ctx)) {
              kk_datatype_ptr_free(_pat_0_24, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_0_24, _ctx);
            }
            kk_datatype_ptr_free(_x_21_4, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_21_4, _ctx);
          }
          _x_x2730 = _x_20; /*std/num/ddouble/ddouble*/
        }
      }
      _x_x2729 = kk_std_num_ddouble__lp__star__rp_(_x_x2730, days_0, _ctx); /*std/num/ddouble/ddouble*/
      ofs2 = kk_std_num_ddouble__lp__plus__rp_(_x_x2725, _x_x2729, _ctx); /*std/time/timestamp/timespan*/
    }
    kk_std_core_types__list _trmc_x10687 = kk_datatype_null(); /*list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>*/;
    kk_std_core_types__list _trmc_x10688;
    kk_box_t _x_x2734;
    kk_std_core_types__tuple4 _x_x2735;
    kk_box_t _x_x2736;
    kk_std_time_timestamp__timestamp _x_x2737;
    {
      kk_box_t _box_x777 = _uniq_x_10643.fst;
      kk_box_t _box_x778 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_1_1 = kk_std_time_utc__leap_adjust_unbox(_box_x778, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_1_1, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2738 = kk_std_time_utc__as_Leap_adjust(_x_1_1, _ctx);
        kk_std_time_timestamp__timestamp _x_0_2 = _con_x2738->utc_start;
        kk_std_num_ddouble__ddouble _pat_2_1_1 = _con_x2738->offset;
        kk_std_time_timestamp__timestamp _pat_5_0_1 = _con_x2738->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_10 = _con_x2738->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2739 = kk_std_time_timestamp__as_Timestamp(_x_0_2, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2740 = kk_std_time_timestamp__as_Timestamp(_pat_5_0_1, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_1_1, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_0_1, _ctx)) {
            kk_datatype_ptr_free(_pat_5_0_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_0_1, _ctx);
          }
          kk_datatype_ptr_free(_x_1_1, _ctx);
        }
        else {
          kk_std_time_timestamp__timestamp_dup(_x_0_2, _ctx);
          kk_datatype_ptr_decref(_x_1_1, _ctx);
        }
        _x_x2737 = _x_0_2; /*std/time/utc/utc-timestamp*/
      }
    }
    _x_x2736 = kk_std_time_timestamp__timestamp_box(_x_x2737, _ctx); /*10046*/
    kk_box_t _x_x2741;
    kk_std_core_types__tuple3 _x_x2742;
    kk_box_t _x_x2743;
    kk_std_num_ddouble__ddouble _x_x2744;
    {
      kk_box_t _box_x779 = _uniq_x_10643.fst;
      kk_box_t _box_x780 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_23 = kk_std_time_utc__leap_adjust_unbox(_box_x780, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_23, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2745 = kk_std_time_utc__as_Leap_adjust(_x_23, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_26 = _con_x2745->utc_start;
        kk_std_num_ddouble__ddouble _x_22 = _con_x2745->offset;
        kk_std_time_timestamp__timestamp _pat_5_11_0 = _con_x2745->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_10_0 = _con_x2745->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2746 = kk_std_time_timestamp__as_Timestamp(_pat_0_26, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2747 = kk_std_time_timestamp__as_Timestamp(_pat_5_11_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_23, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_5_11_0, _ctx)) {
            kk_datatype_ptr_free(_pat_5_11_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_5_11_0, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_26, _ctx)) {
            kk_datatype_ptr_free(_pat_0_26, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_26, _ctx);
          }
          kk_datatype_ptr_free(_x_23, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_23, _ctx);
        }
        _x_x2744 = _x_22; /*std/time/timestamp/timespan*/
      }
    }
    _x_x2743 = kk_std_num_ddouble__ddouble_box(_x_x2744, _ctx); /*10041*/
    kk_box_t _x_x2748;
    kk_std_time_timestamp__timestamp _x_x2749;
    {
      kk_box_t _box_x781 = _uniq_x_10643.fst;
      kk_box_t _box_x782 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_25 = kk_std_time_utc__leap_adjust_unbox(_box_x782, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_25, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2750 = kk_std_time_utc__as_Leap_adjust(_x_25, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_28 = _con_x2750->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_12 = _con_x2750->offset;
        kk_std_time_timestamp__timestamp _x_24 = _con_x2750->drift_start;
        kk_std_num_ddouble__ddouble _pat_8_11 = _con_x2750->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2751 = kk_std_time_timestamp__as_Timestamp(_pat_0_28, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2752 = kk_std_time_timestamp__as_Timestamp(_x_24, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_25, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_28, _ctx)) {
            kk_datatype_ptr_free(_pat_0_28, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_28, _ctx);
          }
          kk_datatype_ptr_free(_x_25, _ctx);
        }
        else {
          kk_std_time_timestamp__timestamp_dup(_x_24, _ctx);
          kk_datatype_ptr_decref(_x_25, _ctx);
        }
        _x_x2749 = _x_24; /*std/time/utc/utc-timestamp*/
      }
    }
    _x_x2748 = kk_std_time_timestamp__timestamp_box(_x_x2749, _ctx); /*10042*/
    kk_box_t _x_x2753;
    kk_std_num_ddouble__ddouble _x_x2754;
    {
      kk_box_t _box_x783 = _uniq_x_10643.fst;
      kk_box_t _box_x784 = _uniq_x_10643.snd;
      kk_std_time_utc__leap_adjust _x_27 = kk_std_time_utc__leap_adjust_unbox(_box_x784, KK_BORROWED, _ctx);
      kk_std_time_utc__leap_adjust_dup(_x_27, _ctx);
      kk_std_core_types__tuple2_drop(_uniq_x_10643, _ctx);
      {
        struct kk_std_time_utc_Leap_adjust* _con_x2755 = kk_std_time_utc__as_Leap_adjust(_x_27, _ctx);
        kk_std_time_timestamp__timestamp _pat_0_30 = _con_x2755->utc_start;
        kk_std_num_ddouble__ddouble _pat_3_13 = _con_x2755->offset;
        kk_std_time_timestamp__timestamp _pat_6_12 = _con_x2755->drift_start;
        kk_std_num_ddouble__ddouble _x_26 = _con_x2755->drift;
        struct kk_std_time_timestamp_Timestamp* _con_x2756 = kk_std_time_timestamp__as_Timestamp(_pat_0_30, _ctx);
        struct kk_std_time_timestamp_Timestamp* _con_x2757 = kk_std_time_timestamp__as_Timestamp(_pat_6_12, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_x_27, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_6_12, _ctx)) {
            kk_datatype_ptr_free(_pat_6_12, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_6_12, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0_30, _ctx)) {
            kk_datatype_ptr_free(_pat_0_30, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_0_30, _ctx);
          }
          kk_datatype_ptr_free(_x_27, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_27, _ctx);
        }
        _x_x2754 = _x_26; /*std/num/ddouble/ddouble*/
      }
    }
    _x_x2753 = kk_std_num_ddouble__ddouble_box(_x_x2754, _ctx); /*10043*/
    _x_x2742 = kk_std_core_types__new_Tuple3(_x_x2743, _x_x2748, _x_x2753, _ctx); /*(10041, 10042, 10043)*/
    _x_x2741 = kk_std_core_types__tuple3_box(_x_x2742, _ctx); /*10049*/
    _x_x2735 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x2736, kk_std_num_ddouble__ddouble_box(ofs1, _ctx), kk_std_num_ddouble__ddouble_box(ofs2, _ctx), _x_x2741, _ctx); /*(10046, 10047, 10048, 10049)*/
    _x_x2734 = kk_std_core_types__tuple4_box(_x_x2735, _ctx); /*10021*/
    _trmc_x10688 = kk_std_core_types__new_Cons(_ru_x1276, 0, _x_x2734, _trmc_x10687, _ctx); /*list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>*/
    kk_field_addr_t _b_x808_813 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10688, _ctx)->tail, _ctx); /*@field-addr<list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>>*/;
    kk_std_core_types__cctx _brw_x832;
    kk_std_core_types__cctx _x_x2758 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>>*/
    _brw_x832 = kk_cctx_extend_linear(_x_x2758,(kk_std_core_types__list_box(_trmc_x10688, _ctx)),_b_x808_813,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x833 = kk_std_time_utc__trmc_lift_get_leap_steps_10667(_uniq_xx_10644, _brw_x832, _ctx); /*list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>*/;
    kk_std_core_types__cctx_drop(_brw_x832, _ctx);
    return _brw_x833;
  }
  {
    kk_box_t _x_x2759;
    kk_std_core_types__cctx _x_x2760 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>>*/
    _x_x2759 = kk_cctx_apply_linear(_x_x2760,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2759, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-get-leap-steps@10666, get-leap-steps, @spec-x10646
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10641, using:
// @uniq-f@10641 = fn(las: (std/time/utc/leap-adjust, std/time/utc/leap-adjust)){
//   val ofs1 : std/time/timestamp/timespan;
//   val ofs2 : std/time/timestamp/timespan;
//   std/core/types/Tuple4<std/time/utc/utc-timestamp,std/time/timestamp/timespan,std/time/timestamp/timespan,(std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble)>((match (las) {
//       ((@skip std/core/types/Tuple2((@pat@0@3: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@1: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@11: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//          -> (match (@x@1) {
//           ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@2: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0: float64) : float64, (@pat@4@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9: float64) : float64, (@pat@10: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@5: std/time/utc/leap-adjust)
//              -> @x@0;
//         });
//     }), ofs1, ofs2, (std/core/types/Tuple3<std/time/timestamp/timespan,std/time/utc/utc-timestamp,std/num/ddouble/ddouble>((match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@27: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@23: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@35: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@23) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@18: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@16: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@26: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@11: float64) : float64, (@pat@4@11: float64) : float64) : std/num/ddouble/ddouble ) as @x@22: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@10: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@10: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@11: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@10: float64) : float64, (@pat@10@10: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@10: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@34: std/time/utc/leap-adjust)
//                -> @x@22;
//           });
//       }), (match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@29: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@25: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@37: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@25) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@19: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@17: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@28: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@4@12: float64) : float64, (@pat@5@12: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@12: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@11: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@11: int32) : int32) : std/time/timestamp/timestamp ) as @x@24: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@11: float64) : float64, (@pat@10@11: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@11: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@36: std/time/utc/leap-adjust)
//                -> @x@24;
//           });
//       }), (match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@31: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@27: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@39: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@27) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@20: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@18: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@30: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@4@13: float64) : float64, (@pat@5@13: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@13: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@7@12: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@8@12: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@12: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@12: float64) : float64, (@pat@10@12: float64) : float64) : std/num/ddouble/ddouble ) as @x@26: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@38: std/time/utc/leap-adjust)
//                -> @x@26;
//           });
//       }))));
// }

kk_std_core_types__list kk_std_time_utc__lift_get_leap_steps_10667(kk_std_core_types__list _uniq_xs_10640_0, kk_context_t* _ctx) { /* (list<(leap-adjust, leap-adjust)>) -> list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))> */ 
  kk_std_core_types__cctx _brw_x830 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x831 = kk_std_time_utc__trmc_lift_get_leap_steps_10667(_uniq_xs_10640_0, _brw_x830, _ctx); /*list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>*/;
  kk_std_core_types__cctx_drop(_brw_x830, _ctx);
  return _brw_x831;
}
 
// lifted local: get-leap-steps, @spec-x10639
// specialized: std/core/list/map, on parameters @uniq-f@10636, using:
// @uniq-f@10636 = fn(las: (std/time/utc/leap-adjust, std/time/utc/leap-adjust)){
//   val ofs1 : std/time/timestamp/timespan;
//   val ofs2 : std/time/timestamp/timespan;
//   std/core/types/Tuple4<std/time/utc/utc-timestamp,std/time/timestamp/timespan,std/time/timestamp/timespan,(std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble)>((match (las) {
//       ((@skip std/core/types/Tuple2((@pat@0@3: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@1: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@11: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//          -> (match (@x@1) {
//           ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@0@2: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@1@1: int32) : int32) : std/time/timestamp/timestamp ) as @x@0: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@0: float64) : float64, (@pat@4@0: float64) : float64) : std/num/ddouble/ddouble ) as @pat@2@1: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@0: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9: float64) : float64, (@pat@10: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@5: std/time/utc/leap-adjust)
//              -> @x@0;
//         });
//     }), ofs1, ofs2, (std/core/types/Tuple3<std/time/timestamp/timespan,std/time/utc/utc-timestamp,std/num/ddouble/ddouble>((match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@27: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@23: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@35: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@23) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@18: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@16: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@26: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@3@11: float64) : float64, (@pat@4@11: float64) : float64) : std/num/ddouble/ddouble ) as @x@22: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@10: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@10: int32) : int32) : std/time/timestamp/timestamp ) as @pat@5@11: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@10: float64) : float64, (@pat@10@10: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@10: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@34: std/time/utc/leap-adjust)
//                -> @x@22;
//           });
//       }), (match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@29: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@25: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@37: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@25) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@19: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@17: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@28: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@4@12: float64) : float64, (@pat@5@12: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@12: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@6@11: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@7@11: int32) : int32) : std/time/timestamp/timestamp ) as @x@24: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@11: float64) : float64, (@pat@10@11: float64) : float64) : std/num/ddouble/ddouble ) as @pat@8@11: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@36: std/time/utc/leap-adjust)
//                -> @x@24;
//           });
//       }), (match (las) {
//         ((@skip std/core/types/Tuple2((@pat@0@31: std/time/utc/leap-adjust) : std/time/utc/leap-adjust, (@x@27: std/time/utc/leap-adjust) : std/time/utc/leap-adjust) : (std/time/utc/leap-adjust, std/time/utc/leap-adjust) ) as @pat@39: (std/time/utc/leap-adjust, std/time/utc/leap-adjust))
//            -> (match (@x@27) {
//             ((@skip std/time/utc/Leap-adjust(((@skip std/time/timestamp/Timestamp((@pat@1@20: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@2@18: int32) : int32) : std/time/timestamp/timestamp ) as @pat@0@30: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@4@13: float64) : float64, (@pat@5@13: float64) : float64) : std/num/ddouble/ddouble ) as @pat@3@13: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), ((@skip std/time/timestamp/Timestamp((@pat@7@12: (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble)) : (std/time/timestamp/timespan == 1 std/num/ddouble/ddouble), (@pat@8@12: int32) : int32) : std/time/timestamp/timestamp ) as @pat@6@12: (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp)) : (std/time/utc/utc-timestamp == 1 std/time/timestamp/timestamp), ((@skip std/num/ddouble/Ddouble((@pat@9@12: float64) : float64, (@pat@10@12: float64) : float64) : std/num/ddouble/ddouble ) as @x@26: std/num/ddouble/ddouble) : std/num/ddouble/ddouble) : std/time/utc/leap-adjust ) as @pat@38: std/time/utc/leap-adjust)
//                -> @x@26;
//           });
//       }))));
// }

kk_std_core_types__list kk_std_time_utc__lift_get_leap_steps_10666(kk_std_core_types__list _uniq_xs_10635, kk_context_t* _ctx) { /* (list<(leap-adjust, leap-adjust)>) -> list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10635, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x828 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x829 = kk_std_time_utc__trmc_lift_get_leap_steps_10667(_uniq_xs_10635, _brw_x828, _ctx); /*list<(std/time/utc/utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, std/time/utc/utc-timestamp, std/num/ddouble/ddouble))>*/;
    kk_std_core_types__cctx_drop(_brw_x828, _ctx);
    return _brw_x829;
  }
}
 
// Get a list of leap second steps in a triple, NTP start time, offset just before, and the new offset at that time,
// the base offset, the drift start date and the drift rate.

kk_std_core_types__list kk_std_time_utc_get_leap_steps(kk_std_core_types__optional table, kk_context_t* _ctx) { /* (table : ? leaps-table) -> list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))> */ 
  kk_std_core_types__list adjusts;
  kk_std_time_utc__leaps_table _match_x826;
  if (kk_std_core_types__is_Optional(table, _ctx)) {
    kk_box_t _box_x819 = table._cons._Optional.value;
    kk_std_time_utc__leaps_table _uniq_table_3725 = kk_std_time_utc__leaps_table_unbox(_box_x819, KK_BORROWED, _ctx);
    kk_std_time_utc__leaps_table_dup(_uniq_table_3725, _ctx);
    _match_x826 = _uniq_table_3725; /*std/time/utc/leaps-table*/
  }
  else {
    _match_x826 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
  }
  {
    struct kk_std_time_utc_Leaps_table* _con_x2761 = kk_std_time_utc__as_Leaps_table(_match_x826, _ctx);
    kk_std_time_instant__instant _pat_0_0 = _con_x2761->expire;
    kk_std_core_types__list _x = _con_x2761->adjusts;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x826, _ctx)) {
      kk_std_time_instant__instant_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_match_x826, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x826, _ctx);
    }
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      kk_std_core_types__optional_drop(table, _ctx);
      adjusts = kk_std_core_types__new_Nil(_ctx); /*list<std/time/utc/leap-adjust>*/
    }
    else {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x2762;
      kk_std_time_utc__leaps_table _match_x827;
      if (kk_std_core_types__is_Optional(table, _ctx)) {
        kk_box_t _box_x820 = table._cons._Optional.value;
        kk_std_time_utc__leaps_table _uniq_table_3725_0 = kk_std_time_utc__leaps_table_unbox(_box_x820, KK_BORROWED, _ctx);
        kk_std_time_utc__leaps_table_dup(_uniq_table_3725_0, _ctx);
        kk_std_core_types__optional_drop(table, _ctx);
        _match_x827 = _uniq_table_3725_0; /*std/time/utc/leaps-table*/
      }
      else {
        kk_std_core_types__optional_drop(table, _ctx);
        _match_x827 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_ti, _ctx); /*std/time/utc/leaps-table*/
      }
      {
        struct kk_std_time_utc_Leaps_table* _con_x2763 = kk_std_time_utc__as_Leaps_table(_match_x827, _ctx);
        kk_std_time_instant__instant _pat_0_0_0 = _con_x2763->expire;
        kk_std_core_types__list _x_0 = _con_x2763->adjusts;
        if kk_likely(kk_datatype_ptr_is_unique(_match_x827, _ctx)) {
          kk_std_time_instant__instant_drop(_pat_0_0_0, _ctx);
          kk_datatype_ptr_free(_match_x827, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(_match_x827, _ctx);
        }
        _x_x2762 = _x_0; /*list<std/time/utc/leap-adjust>*/
      }
      adjusts = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x2762, _ctx); /*list<std/time/utc/leap-adjust>*/
    }
  }
  kk_std_core_types__list xs_0_10343;
  kk_box_t _x_x2764;
  kk_std_time_utc__leap_adjust _x_x2765 = kk_std_time_utc__leap_adjust_dup(kk_std_time_utc_zero, _ctx); /*std/time/utc/leap-adjust*/
  _x_x2764 = kk_std_time_utc__leap_adjust_box(_x_x2765, _ctx); /*10021*/
  kk_std_core_types__list _x_x2766 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
  xs_0_10343 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2764, _x_x2766, _ctx); /*list<std/time/utc/leap-adjust>*/
  kk_std_core_types__list _own_x825;
  if (kk_std_core_types__is_Nil(xs_0_10343, _ctx)) {
    kk_std_core_types__list_drop(adjusts, _ctx);
    _own_x825 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
  }
  else {
    _own_x825 = kk_std_core_list__unroll_zip_10019(xs_0_10343, adjusts, _ctx); /*forall<a> list<a>*/
  }
  return kk_std_time_utc__lift_get_leap_steps_10666(_own_x825, _ctx);
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
    kk_string_t _x_x1337;
    kk_define_string_literal(, _s_x1338, 7, "utc@utc", _ctx)
    _x_x1337 = kk_string_dup(_s_x1338, _ctx); /*string*/
    kk_std_time_utc_utc_fs__tag = kk_std_core_hnd__new_Htag(_x_x1337, _ctx); /*hnd/htag<std/time/utc/utc>*/
  }
  {
    kk_std_time_timestamp__timestamp _x_x1348 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_timestamp__timestamp _x_x1349 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_utc_zero = kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, _x_x1348, kk_std_num_ddouble_zero, _x_x1349, kk_std_num_ddouble_zero, _ctx); /*std/time/utc/leap-adjust*/
  }
  {
    bool _match_x1091;
    double _x_x1386;
    kk_std_core_types__optional _match_x1093 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1093, _ctx)) {
      kk_box_t _box_x22 = _match_x1093._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x22, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x1093, _ctx);
      _x_x1386 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1093, _ctx);
      _x_x1386 = 0x0p+0; /*float64*/
    }
    _match_x1091 = (_x_x1386 == (0x0p+0)); /*bool*/
    if (_match_x1091) {
      kk_std_time_utc_ntp2000 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_str("3155673600", _ctx), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1387 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_str("3155673600", _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1388;
      double _x_x1389;
      kk_std_core_types__optional _match_x1092 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x1092, _ctx)) {
        kk_box_t _box_x23 = _match_x1092._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x23, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x1092, _ctx);
        _x_x1389 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x1092, _ctx);
        _x_x1389 = 0x0p+0; /*float64*/
      }
      _x_x1388 = kk_std_num_ddouble__new_Ddouble(_x_x1389, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_utc_ntp2000 = kk_std_num_ddouble__lp__plus__rp_(_x_x1387, _x_x1388, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  {
    kk_std_num_ddouble__ddouble t_0_10040;
    kk_std_num_ddouble__ddouble _x_x1390 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(-1325376000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1391;
    double _x_x1392;
    kk_std_core_types__optional _match_x1090 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1090, _ctx)) {
      kk_box_t _box_x24 = _match_x1090._cons._Optional.value;
      double _uniq_frac_1231 = kk_double_unbox(_box_x24, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x1090, _ctx);
      _x_x1392 = _uniq_frac_1231; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1090, _ctx);
      _x_x1392 = 0x0p+0; /*float64*/
    }
    _x_x1391 = kk_std_num_ddouble__new_Ddouble(_x_x1392, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_0_10040 = kk_std_num_ddouble__lp__plus__rp_(_x_x1390, _x_x1391, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x1393;
    kk_integer_t _x_x1394;
    kk_std_core_types__optional _match_x1089 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1089, _ctx)) {
      kk_box_t _box_x25 = _match_x1089._cons._Optional.value;
      kk_integer_t _uniq_leap_1235 = kk_integer_unbox(_box_x25, _ctx);
      kk_integer_dup(_uniq_leap_1235, _ctx);
      kk_std_core_types__optional_drop(_match_x1089, _ctx);
      _x_x1394 = _uniq_leap_1235; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1089, _ctx);
      _x_x1394 = kk_integer_from_small(0); /*int*/
    }
    _x_x1393 = kk_integer_clamp32(_x_x1394,kk_context()); /*int32*/
    kk_std_time_utc_utc1958 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_0_10040, _x_x1393, _ctx); /*std/time/timestamp/timestamp*/
  }
  kk_init_string_literal(kk_std_time_utc_default_iers_leap_seconds, _ctx)
  {
    kk_std_time_utc_jd_epoch_shift = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    bool _match_x1003;
    double _x_x1764;
    kk_std_core_types__optional _match_x1005 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1005, _ctx)) {
      kk_box_t _box_x101 = _match_x1005._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x101, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x1005, _ctx);
      _x_x1764 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1005, _ctx);
      _x_x1764 = 0x0p+0; /*float64*/
    }
    _match_x1003 = (_x_x1764 == (0x0p+0)); /*bool*/
    if (_match_x1003) {
      kk_std_time_utc_mjd_epoch_shift = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(51544, _ctx), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1765 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(51544, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1766;
      double _x_x1767;
      kk_std_core_types__optional _match_x1004 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x1004, _ctx)) {
        kk_box_t _box_x102 = _match_x1004._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x102, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x1004, _ctx);
        _x_x1767 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x1004, _ctx);
        _x_x1767 = 0x0p+0; /*float64*/
      }
      _x_x1766 = kk_std_num_ddouble__new_Ddouble(_x_x1767, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_utc_mjd_epoch_shift = kk_std_num_ddouble__lp__plus__rp_(_x_x1765, _x_x1766, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  kk_init_string_literal(kk_std_time_utc_default_leap_seconds_pre72, _ctx)
  {
    kk_vector_t v_10019;
    kk_string_t _x_x2175;
    kk_define_string_literal(, _s_x2176, 2922, "\n  # from: Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.\n  1958 JAN  1 =JD 2436204.5     TAI-UTC= 0.0  S + (MJD - 36204.) X 0.00073458 S\n  1958 JAN 15 =JD 2436219.29167 TAI-UTC= 0.02 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB  5 =JD 2436240.29167 TAI-UTC= 0.04 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB 19 =JD 2436254.29167 TAI-UTC= 0.06 S + (MJD - 36204.) X 0.00073458 S\n  1958 APR  9 =JD 2436303.29167 TAI-UTC= 0.08 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUN 11 =JD 2436366.29167 TAI-UTC= 0.10 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL  2 =JD 2436387.29167 TAI-UTC= 0.12 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL 16 =JD 2436401.29167 TAI-UTC= 0.14 S + (MJD - 36204.) X 0.00073458 S\n  1958 OCT 22 =JD 2436499.29167 TAI-UTC= 0.16 S + (MJD - 36204.) X 0.00073458 S\n  1958 NOV 26 =JD 2436534.29167 TAI-UTC= 0.18 S + (MJD - 36204.) X 0.00073458 S\n  1958 DEC 24 =JD 2436562.29167 TAI-UTC= 0.20 S + (MJD - 36204.) X 0.00073458 S\n\n  1959 JAN  1 =JD 2436569.5     TAI-UTC= 0.4681220 S + (MJD - 36569.) X 0.000864 S\n  1959 JAN 28 =JD 2436597.29167 TAI-UTC= 0.4881220 S + (MJD - 36569.) X 0.000864 S\n  1959 FEB 25 =JD 2436625.29167 TAI-UTC= 0.5081220 S + (MJD - 36569.) X 0.000864 S\n  1959 APR  5 =JD 2436664.29167 TAI-UTC= 0.5281220 S + (MJD - 36569.) X 0.000864 S\n  1959 AUG 26 =JD 2436807.29167 TAI-UTC= 0.5481220 S + (MJD - 36569.) X 0.000864 S\n  1959 SEP 30 =JD 2436842.29167 TAI-UTC= 0.5681220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV  4 =JD 2436877.29167 TAI-UTC= 0.5881220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV 18 =JD 2436891.29167 TAI-UTC= 0.6081220 S + (MJD - 36569.) X 0.000864 S\n  1959 DEC 16 =JD 2436919.29167 TAI-UTC= 0.6281220 S + (MJD - 36569.) X 0.000864 S\n  1960 JAN  1 =JD 2436934.5     TAI-UTC= 0.9434820 S + (MJD - 36934.) X 0.001296 S\n\n  # from: https://maia.usno.navy.mil/ser7/tai-utc.dat\n  1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S\n  1961 AUG  1 =JD 2437512.5  TAI-UTC=   1.3728180 S + (MJD - 37300.) X 0.001296 S\n  1962 JAN  1 =JD 2437665.5  TAI-UTC=   1.8458580 S + (MJD - 37665.) X 0.0011232S\n  1963 NOV  1 =JD 2438334.5  TAI-UTC=   1.9458580 S + (MJD - 37665.) X 0.0011232S\n  1964 JAN  1 =JD 2438395.5  TAI-UTC=   3.2401300 S + (MJD - 38761.) X 0.001296 S\n  1964 APR  1 =JD 2438486.5  TAI-UTC=   3.3401300 S + (MJD - 38761.) X 0.001296 S\n  1964 SEP  1 =JD 2438639.5  TAI-UTC=   3.4401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JAN  1 =JD 2438761.5  TAI-UTC=   3.5401300 S + (MJD - 38761.) X 0.001296 S\n  1965 MAR  1 =JD 2438820.5  TAI-UTC=   3.6401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JUL  1 =JD 2438942.5  TAI-UTC=   3.7401300 S + (MJD - 38761.) X 0.001296 S\n  1965 SEP  1 =JD 2439004.5  TAI-UTC=   3.8401300 S + (MJD - 38761.) X 0.001296 S\n  1966 JAN  1 =JD 2439126.5  TAI-UTC=   4.3131700 S + (MJD - 39126.) X 0.002592 S\n  1968 FEB  1 =JD 2439887.5  TAI-UTC=   4.2131700 S + (MJD - 39126.) X 0.002592 S", _ctx)
    _x_x2175 = kk_string_dup(_s_x2176, _ctx); /*string*/
    kk_string_t _x_x2177;
    kk_define_string_literal(, _s_x2178, 1, "\n", _ctx)
    _x_x2177 = kk_string_dup(_s_x2178, _ctx); /*string*/
    v_10019 = kk_string_splitv(_x_x2175,_x_x2177,kk_context()); /*vector<string>*/
    kk_std_core_types__list xs_10181;
    kk_std_core_types__list _x_x2179 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/
    xs_10181 = kk_std_time_utc__lift_leaps_table_pre1972_10656(_x_x2179, _ctx); /*list<std/time/utc/leap-adjust>*/
    kk_std_core_types__list adjusts;
    if (kk_std_core_types__is_Nil(xs_10181, _ctx)) {
      adjusts = kk_std_core_types__new_Nil(_ctx); /*list<std/time/utc/leap-adjust>*/
    }
    else {
      adjusts = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs_10181, _ctx); /*list<std/time/utc/leap-adjust>*/
    }
    kk_std_time_instant__instant expire;
    kk_string_t _x_x2180;
    kk_define_string_literal(, _s_x2181, 2922, "\n  # from: Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.\n  1958 JAN  1 =JD 2436204.5     TAI-UTC= 0.0  S + (MJD - 36204.) X 0.00073458 S\n  1958 JAN 15 =JD 2436219.29167 TAI-UTC= 0.02 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB  5 =JD 2436240.29167 TAI-UTC= 0.04 S + (MJD - 36204.) X 0.00073458 S\n  1958 FEB 19 =JD 2436254.29167 TAI-UTC= 0.06 S + (MJD - 36204.) X 0.00073458 S\n  1958 APR  9 =JD 2436303.29167 TAI-UTC= 0.08 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUN 11 =JD 2436366.29167 TAI-UTC= 0.10 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL  2 =JD 2436387.29167 TAI-UTC= 0.12 S + (MJD - 36204.) X 0.00073458 S\n  1958 JUL 16 =JD 2436401.29167 TAI-UTC= 0.14 S + (MJD - 36204.) X 0.00073458 S\n  1958 OCT 22 =JD 2436499.29167 TAI-UTC= 0.16 S + (MJD - 36204.) X 0.00073458 S\n  1958 NOV 26 =JD 2436534.29167 TAI-UTC= 0.18 S + (MJD - 36204.) X 0.00073458 S\n  1958 DEC 24 =JD 2436562.29167 TAI-UTC= 0.20 S + (MJD - 36204.) X 0.00073458 S\n\n  1959 JAN  1 =JD 2436569.5     TAI-UTC= 0.4681220 S + (MJD - 36569.) X 0.000864 S\n  1959 JAN 28 =JD 2436597.29167 TAI-UTC= 0.4881220 S + (MJD - 36569.) X 0.000864 S\n  1959 FEB 25 =JD 2436625.29167 TAI-UTC= 0.5081220 S + (MJD - 36569.) X 0.000864 S\n  1959 APR  5 =JD 2436664.29167 TAI-UTC= 0.5281220 S + (MJD - 36569.) X 0.000864 S\n  1959 AUG 26 =JD 2436807.29167 TAI-UTC= 0.5481220 S + (MJD - 36569.) X 0.000864 S\n  1959 SEP 30 =JD 2436842.29167 TAI-UTC= 0.5681220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV  4 =JD 2436877.29167 TAI-UTC= 0.5881220 S + (MJD - 36569.) X 0.000864 S\n  1959 NOV 18 =JD 2436891.29167 TAI-UTC= 0.6081220 S + (MJD - 36569.) X 0.000864 S\n  1959 DEC 16 =JD 2436919.29167 TAI-UTC= 0.6281220 S + (MJD - 36569.) X 0.000864 S\n  1960 JAN  1 =JD 2436934.5     TAI-UTC= 0.9434820 S + (MJD - 36934.) X 0.001296 S\n\n  # from: https://maia.usno.navy.mil/ser7/tai-utc.dat\n  1961 JAN  1 =JD 2437300.5  TAI-UTC=   1.4228180 S + (MJD - 37300.) X 0.001296 S\n  1961 AUG  1 =JD 2437512.5  TAI-UTC=   1.3728180 S + (MJD - 37300.) X 0.001296 S\n  1962 JAN  1 =JD 2437665.5  TAI-UTC=   1.8458580 S + (MJD - 37665.) X 0.0011232S\n  1963 NOV  1 =JD 2438334.5  TAI-UTC=   1.9458580 S + (MJD - 37665.) X 0.0011232S\n  1964 JAN  1 =JD 2438395.5  TAI-UTC=   3.2401300 S + (MJD - 38761.) X 0.001296 S\n  1964 APR  1 =JD 2438486.5  TAI-UTC=   3.3401300 S + (MJD - 38761.) X 0.001296 S\n  1964 SEP  1 =JD 2438639.5  TAI-UTC=   3.4401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JAN  1 =JD 2438761.5  TAI-UTC=   3.5401300 S + (MJD - 38761.) X 0.001296 S\n  1965 MAR  1 =JD 2438820.5  TAI-UTC=   3.6401300 S + (MJD - 38761.) X 0.001296 S\n  1965 JUL  1 =JD 2438942.5  TAI-UTC=   3.7401300 S + (MJD - 38761.) X 0.001296 S\n  1965 SEP  1 =JD 2439004.5  TAI-UTC=   3.8401300 S + (MJD - 38761.) X 0.001296 S\n  1966 JAN  1 =JD 2439126.5  TAI-UTC=   4.3131700 S + (MJD - 39126.) X 0.002592 S\n  1968 FEB  1 =JD 2439887.5  TAI-UTC=   4.2131700 S + (MJD - 39126.) X 0.002592 S", _ctx)
    _x_x2180 = kk_string_dup(_s_x2181, _ctx); /*string*/
    kk_std_core_types__list _x_x2182 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
    expire = kk_std_time_utc_parse_leap_expire(_x_x2180, _x_x2182, _ctx); /*std/time/instant/instant*/
    kk_std_time_utc_leaps_table_pre1972 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx); /*std/time/utc/leaps-table*/
  }
  {
    kk_vector_t v_10019;
    kk_string_t _x_x2277;
    kk_define_string_literal(, _s_x2278, 1125, "\n  # From: https://hpiers.obspm.fr/iers/bul/bulc/ntp/leap-seconds.list\n  #\tUpdated through IERS Bulletin C (https://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat)\n  # File expires on:  28 December 2024\n  #\n  #@\t3944332800\n  #\n  2272060800  10  # 1 Jan 1972\n  2287785600  11  # 1 Jul 1972\n  2303683200  12  # 1 Jan 1973\n  2335219200  13  # 1 Jan 1974\n  2366755200  14  # 1 Jan 1975\n  2398291200  15  # 1 Jan 1976\n  2429913600  16  # 1 Jan 1977\n  2461449600  17  # 1 Jan 1978\n  2492985600  18  # 1 Jan 1979\n  2524521600  19  # 1 Jan 1980\n  2571782400  20  # 1 Jul 1981\n  2603318400  21  # 1 Jul 1982\n  2634854400  22  # 1 Jul 1983\n  2698012800  23  # 1 Jul 1985\n  2776982400  24  # 1 Jan 1988\n  2840140800  25  # 1 Jan 1990\n  2871676800  26  # 1 Jan 1991\n  2918937600  27  # 1 Jul 1992\n  2950473600  28  # 1 Jul 1993\n  2982009600  29  # 1 Jul 1994\n  3029443200  30  # 1 Jan 1996\n  3076704000  31  # 1 Jul 1997\n  3124137600  32  # 1 Jan 1999\n  3345062400  33  # 1 Jan 2006\n  3439756800  34  # 1 Jan 2009\n  3550089600  35  # 1 Jul 2012\n  3644697600  36  # 1 Jul 2015\n  3692217600  37  # 1 Jan 2017\n  // 3723753600  35  # 1 Jan 2018", _ctx)
    _x_x2277 = kk_string_dup(_s_x2278, _ctx); /*string*/
    kk_string_t _x_x2279;
    kk_define_string_literal(, _s_x2280, 1, "\n", _ctx)
    _x_x2279 = kk_string_dup(_s_x2280, _ctx); /*string*/
    v_10019 = kk_string_splitv(_x_x2277,_x_x2279,kk_context()); /*vector<string>*/
    kk_std_core_types__list xs_10188;
    kk_std_core_types__list _x_x2281 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<10000>*/
    xs_10188 = kk_std_time_utc__lift_leaps_table_ti_10660(_x_x2281, _ctx); /*list<std/time/utc/leap-adjust>*/
    kk_std_core_types__list adjusts;
    if (kk_std_core_types__is_Nil(xs_10188, _ctx)) {
      adjusts = kk_std_core_types__new_Nil(_ctx); /*list<std/time/utc/leap-adjust>*/
    }
    else {
      adjusts = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs_10188, _ctx); /*list<std/time/utc/leap-adjust>*/
    }
    kk_std_time_instant__instant expire;
    kk_string_t _x_x2282;
    kk_define_string_literal(, _s_x2283, 1125, "\n  # From: https://hpiers.obspm.fr/iers/bul/bulc/ntp/leap-seconds.list\n  #\tUpdated through IERS Bulletin C (https://hpiers.obspm.fr/iers/bul/bulc/bulletinc.dat)\n  # File expires on:  28 December 2024\n  #\n  #@\t3944332800\n  #\n  2272060800  10  # 1 Jan 1972\n  2287785600  11  # 1 Jul 1972\n  2303683200  12  # 1 Jan 1973\n  2335219200  13  # 1 Jan 1974\n  2366755200  14  # 1 Jan 1975\n  2398291200  15  # 1 Jan 1976\n  2429913600  16  # 1 Jan 1977\n  2461449600  17  # 1 Jan 1978\n  2492985600  18  # 1 Jan 1979\n  2524521600  19  # 1 Jan 1980\n  2571782400  20  # 1 Jul 1981\n  2603318400  21  # 1 Jul 1982\n  2634854400  22  # 1 Jul 1983\n  2698012800  23  # 1 Jul 1985\n  2776982400  24  # 1 Jan 1988\n  2840140800  25  # 1 Jan 1990\n  2871676800  26  # 1 Jan 1991\n  2918937600  27  # 1 Jul 1992\n  2950473600  28  # 1 Jul 1993\n  2982009600  29  # 1 Jul 1994\n  3029443200  30  # 1 Jan 1996\n  3076704000  31  # 1 Jul 1997\n  3124137600  32  # 1 Jan 1999\n  3345062400  33  # 1 Jan 2006\n  3439756800  34  # 1 Jan 2009\n  3550089600  35  # 1 Jul 2012\n  3644697600  36  # 1 Jul 2015\n  3692217600  37  # 1 Jan 2017\n  // 3723753600  35  # 1 Jan 2018", _ctx)
    _x_x2282 = kk_string_dup(_s_x2283, _ctx); /*string*/
    kk_std_core_types__list _x_x2284 = kk_std_core_types__list_dup(adjusts, _ctx); /*list<std/time/utc/leap-adjust>*/
    expire = kk_std_time_utc_parse_leap_expire(_x_x2282, _x_x2284, _ctx); /*std/time/instant/instant*/
    kk_std_time_utc__leaps_table _x_x2285 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, expire, adjusts, _ctx); /*std/time/utc/leaps-table*/
    kk_std_time_utc__leaps_table _x_x2286 = kk_std_time_utc__leaps_table_dup(kk_std_time_utc_leaps_table_pre1972, _ctx); /*std/time/utc/leaps-table*/
    kk_std_time_utc_leaps_table_ti = kk_std_time_utc_extend(_x_x2285, _x_x2286, _ctx); /*std/time/utc/leaps-table*/
  }
  {
    kk_string_t _x_x2287 = kk_string_empty(); /*string*/
    kk_string_t _x_x2289;
    kk_define_string_literal(, _s_x2290, 3, "UTC", _ctx)
    _x_x2289 = kk_string_dup(_s_x2290, _ctx); /*string*/
    kk_std_core_types__maybe _x_x2295 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_utc_new_ts_ti_fun2296(_ctx), _ctx), _ctx); /*maybe<10024>*/
    kk_std_core_types__maybe _x_x2301 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_utc_new_ts_ti_fun2302(_ctx), _ctx), _ctx); /*maybe<10024>*/
    kk_std_core_types__maybe _x_x2305 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_utc_new_ts_ti_fun2306(_ctx), _ctx), _ctx); /*maybe<10024>*/
    kk_std_time_utc_ts_ti = kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x2287, _x_x2289, kk_std_time_utc_new_ts_ti_fun2291(_ctx), kk_std_time_utc_new_ts_ti_fun2293(_ctx), _x_x2295, _x_x2301, _x_x2305, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_instant__instant _x_x2315 = kk_std_time_instant__instant_dup(kk_std_time_instant_epoch, _ctx); /*std/time/instant/instant*/
    kk_std_time_utc_leaps_table0 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x2315, kk_std_core_types__new_Nil(_ctx), _ctx); /*std/time/utc/leaps-table*/
  }
  {
    bool _match_x896;
    double _x_x2389;
    kk_std_core_types__optional _match_x898 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x898, _ctx)) {
      kk_box_t _box_x644 = _match_x898._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x644, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x898, _ctx);
      _x_x2389 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x898, _ctx);
      _x_x2389 = 0x0p+0; /*float64*/
    }
    _match_x896 = (_x_x2389 == (0x0p+0)); /*bool*/
    if (_match_x896) {
      kk_std_time_utc_unix2000 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(946684800, _ctx), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x2390 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(946684800, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x2391;
      double _x_x2392;
      kk_std_core_types__optional _match_x897 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x897, _ctx)) {
        kk_box_t _box_x645 = _match_x897._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x645, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x897, _ctx);
        _x_x2392 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x897, _ctx);
        _x_x2392 = 0x0p+0; /*float64*/
      }
      _x_x2391 = kk_std_num_ddouble__new_Ddouble(_x_x2392, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_utc_unix2000 = kk_std_num_ddouble__lp__plus__rp_(_x_x2390, _x_x2391, _ctx); /*std/time/timestamp/timespan*/
    }
  }
  {
    kk_std_time_utc_ts_ntp = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_utc_ts_unix = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_num_ddouble__ddouble _uniq_smooth_3636;
    kk_std_core_types__optional _match_x851 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x851, _ctx)) {
      kk_box_t _box_x735 = _match_x851._cons._Optional.value;
      kk_std_num_ddouble__ddouble _uniq_smooth_3637 = kk_std_num_ddouble__ddouble_unbox(_box_x735, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x851, _ctx);
      _uniq_smooth_3636 = _uniq_smooth_3637; /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x851, _ctx);
      bool _match_x852;
      double _x_x2611;
      kk_std_core_types__optional _match_x854 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x854, _ctx)) {
        kk_box_t _box_x736 = _match_x854._cons._Optional.value;
        double _uniq_frac_1144 = kk_double_unbox(_box_x736, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x854, _ctx);
        _x_x2611 = _uniq_frac_1144; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x854, _ctx);
        _x_x2611 = 0x0p+0; /*float64*/
      }
      _match_x852 = (_x_x2611 == (0x0p+0)); /*bool*/
      if (_match_x852) {
        _uniq_smooth_3636 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_num_ddouble__ddouble _x_x2612 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(1000), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _x_x2613;
        double _x_x2614;
        kk_std_core_types__optional _match_x853 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x853, _ctx)) {
          kk_box_t _box_x737 = _match_x853._cons._Optional.value;
          double _uniq_frac_1144_0 = kk_double_unbox(_box_x737, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(_match_x853, _ctx);
          _x_x2614 = _uniq_frac_1144_0; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x853, _ctx);
          _x_x2614 = 0x0p+0; /*float64*/
        }
        _x_x2613 = kk_std_num_ddouble__new_Ddouble(_x_x2614, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        _uniq_smooth_3636 = kk_std_num_ddouble__lp__plus__rp_(_x_x2612, _x_x2613, _ctx); /*std/time/timestamp/timespan*/
      }
    }
    kk_string_t _x_x2615;
    kk_define_string_literal(, _s_x2616, 6, "TI-SLS", _ctx)
    _x_x2615 = kk_string_dup(_s_x2616, _ctx); /*string*/
    kk_string_t _x_x2617;
    kk_define_string_literal(, _s_x2618, 7, "UTC-SLS", _ctx)
    _x_x2617 = kk_string_dup(_s_x2618, _ctx); /*string*/
    kk_std_core_types__maybe _x_x2623;
    kk_std_core_types__optional _match_x850 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x850, _ctx)) {
      kk_box_t _box_x738 = _match_x850._cons._Optional.value;
      kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x738, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
      kk_std_core_types__optional_drop(_match_x850, _ctx);
      _x_x2623 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x850, _ctx);
      _x_x2623 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    kk_std_core_types__maybe _x_x2624;
    kk_std_core_types__optional _match_x849 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x849, _ctx)) {
      kk_box_t _box_x739 = _match_x849._cons._Optional.value;
      kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x739, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
      kk_std_core_types__optional_drop(_match_x849, _ctx);
      _x_x2624 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x849, _ctx);
      _x_x2624 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    kk_std_core_types__maybe _x_x2625;
    kk_std_core_types__optional _match_x848 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x848, _ctx)) {
      kk_box_t _box_x740 = _match_x848._cons._Optional.value;
      kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x740, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
      kk_std_core_types__optional_drop(_match_x848, _ctx);
      _x_x2625 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x848, _ctx);
      _x_x2625 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    kk_std_time_utc_ts_ti_sls = kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x2615, _x_x2617, kk_std_time_utc_new_ts_ti_sls_fun2619(_uniq_smooth_3636, _ctx), kk_std_time_utc_new_ts_ti_sls_fun2621(_uniq_smooth_3636, _ctx), _x_x2623, _x_x2624, _x_x2625, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_num_ddouble__ddouble t_0_10040;
    kk_std_num_ddouble__ddouble _x_x2649 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(536544000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x2650;
    double _x_x2651;
    kk_std_core_types__optional _match_x839 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x839, _ctx)) {
      kk_box_t _box_x742 = _match_x839._cons._Optional.value;
      double _uniq_frac_1231 = kk_double_unbox(_box_x742, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x839, _ctx);
      _x_x2651 = _uniq_frac_1231; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x839, _ctx);
      _x_x2651 = 0x0p+0; /*float64*/
    }
    _x_x2650 = kk_std_num_ddouble__new_Ddouble(_x_x2651, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_0_10040 = kk_std_num_ddouble__lp__plus__rp_(_x_x2649, _x_x2650, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_timestamp__timestamp end_10328;
    int32_t _x_x2652;
    kk_integer_t _x_x2653;
    kk_std_core_types__optional _match_x838 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x838, _ctx)) {
      kk_box_t _box_x743 = _match_x838._cons._Optional.value;
      kk_integer_t _uniq_leap_1235 = kk_integer_unbox(_box_x743, _ctx);
      kk_integer_dup(_uniq_leap_1235, _ctx);
      kk_std_core_types__optional_drop(_match_x838, _ctx);
      _x_x2653 = _uniq_leap_1235; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x838, _ctx);
      _x_x2653 = kk_integer_from_small(0); /*int*/
    }
    _x_x2652 = kk_integer_clamp32(_x_x2653,kk_context()); /*int32*/
    end_10328 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_0_10040, _x_x2652, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_core_types__list _b_x744_745;
    kk_std_core_types__list _x_x2654;
    kk_std_time_utc__leaps_table _x_x2655 = kk_std_time_utc_leaps_table_ti; /*std/time/utc/leaps-table*/
    {
      struct kk_std_time_utc_Leaps_table* _con_x2656 = kk_std_time_utc__as_Leaps_table(_x_x2655, _ctx);
      kk_std_time_instant__instant _pat_0 = _con_x2656->expire;
      kk_std_core_types__list _x = _con_x2656->adjusts;
      _x_x2654 = kk_std_core_types__list_dup(_x, _ctx); /*list<std/time/utc/leap-adjust>*/
    }
    _b_x744_745 = kk_std_time_utc__lift_leaps_table_y2017_10664(end_10328, _x_x2654, _ctx); /*list<std/time/utc/leap-adjust>*/
    kk_std_time_instant__instant _x_x2657;
    kk_std_core_types__optional _match_x837 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x837, _ctx)) {
      kk_box_t _box_x746 = _match_x837._cons._Optional.value;
      kk_std_time_instant__instant _uniq_expire_375 = kk_std_time_instant__instant_unbox(_box_x746, KK_BORROWED, _ctx);
      kk_std_time_instant__instant_dup(_uniq_expire_375, _ctx);
      kk_std_core_types__optional_drop(_match_x837, _ctx);
      _x_x2657 = _uniq_expire_375; /*std/time/instant/instant*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x837, _ctx);
      kk_std_time_utc__leaps_table _x_x2658 = kk_std_time_utc_leaps_table_ti; /*std/time/utc/leaps-table*/
      {
        struct kk_std_time_utc_Leaps_table* _con_x2659 = kk_std_time_utc__as_Leaps_table(_x_x2658, _ctx);
        kk_std_time_instant__instant _x_1_0 = _con_x2659->expire;
        _x_x2657 = kk_std_time_instant__instant_dup(_x_1_0, _ctx); /*std/time/instant/instant*/
      }
    }
    kk_std_core_types__list _x_x2660;
    kk_std_core_types__optional _match_x836 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x744_745, _ctx), _ctx); /*? 10003*/;
    if (kk_std_core_types__is_Optional(_match_x836, _ctx)) {
      kk_box_t _box_x747 = _match_x836._cons._Optional.value;
      kk_std_core_types__list _uniq_adjusts_383 = kk_std_core_types__list_unbox(_box_x747, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_adjusts_383, _ctx);
      kk_std_core_types__optional_drop(_match_x836, _ctx);
      _x_x2660 = _uniq_adjusts_383; /*list<std/time/utc/leap-adjust>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x836, _ctx);
      kk_std_time_utc__leaps_table _x_x2661 = kk_std_time_utc_leaps_table_ti; /*std/time/utc/leaps-table*/
      {
        struct kk_std_time_utc_Leaps_table* _con_x2662 = kk_std_time_utc__as_Leaps_table(_x_x2661, _ctx);
        kk_std_time_instant__instant _pat_0_4_1 = _con_x2662->expire;
        kk_std_core_types__list _x_2_0 = _con_x2662->adjusts;
        _x_x2660 = kk_std_core_types__list_dup(_x_2_0, _ctx); /*list<std/time/utc/leap-adjust>*/
      }
    }
    kk_std_time_utc_leaps_table_y2017 = kk_std_time_utc__new_Leaps_table(kk_reuse_null, 0, _x_x2657, _x_x2660, _ctx); /*std/time/utc/leaps-table*/
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
