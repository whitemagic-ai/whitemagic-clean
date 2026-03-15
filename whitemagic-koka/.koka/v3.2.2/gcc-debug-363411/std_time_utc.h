#pragma once
#ifndef kk_std_time_utc_H
#define kk_std_time_utc_H
// Koka generated module: std/time/utc, koka version: 3.2.2, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_maybe2.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_lazy.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"
#include "std_num_float64.h"
#include "std_num_ddouble.h"
#include "std_text_parse.h"
#include "std_time_timestamp.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_num_int32.h"

// type declarations

// type std/time/utc/leap-adjust
struct kk_std_time_utc__leap_adjust_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_utc__leap_adjust;
struct kk_std_time_utc_Leap_adjust {
  struct kk_std_time_utc__leap_adjust_s _base;
  kk_std_time_timestamp__timestamp utc_start;
  kk_std_time_timestamp__timestamp drift_start;
  kk_std_num_ddouble__ddouble offset;
  kk_std_num_ddouble__ddouble drift;
};
static inline kk_std_time_utc__leap_adjust kk_std_time_utc__base_Leap_adjust(struct kk_std_time_utc_Leap_adjust* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_utc__leap_adjust kk_std_time_utc__new_Leap_adjust(kk_reuse_t _at, int32_t _cpath, kk_std_time_timestamp__timestamp utc_start, kk_std_num_ddouble__ddouble offset, kk_std_time_timestamp__timestamp drift_start, kk_std_num_ddouble__ddouble drift, kk_context_t* _ctx) {
  struct kk_std_time_utc_Leap_adjust* _con = kk_block_alloc_at_as(struct kk_std_time_utc_Leap_adjust, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->utc_start = utc_start;
  _con->drift_start = drift_start;
  _con->offset = offset;
  _con->drift = drift;
  return kk_std_time_utc__base_Leap_adjust(_con, _ctx);
}
static inline struct kk_std_time_utc_Leap_adjust* kk_std_time_utc__as_Leap_adjust(kk_std_time_utc__leap_adjust x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_utc_Leap_adjust*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_utc__is_Leap_adjust(kk_std_time_utc__leap_adjust x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_utc__leap_adjust kk_std_time_utc__leap_adjust_dup(kk_std_time_utc__leap_adjust _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_utc__leap_adjust_drop(kk_std_time_utc__leap_adjust _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_utc__leap_adjust_box(kk_std_time_utc__leap_adjust _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_utc__leap_adjust kk_std_time_utc__leap_adjust_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type std/time/utc/leaps-table
struct kk_std_time_utc__leaps_table_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_utc__leaps_table;
struct kk_std_time_utc_Leaps_table {
  struct kk_std_time_utc__leaps_table_s _base;
  kk_std_time_instant__instant expire;
  kk_std_core_types__list adjusts;
};
static inline kk_std_time_utc__leaps_table kk_std_time_utc__base_Leaps_table(struct kk_std_time_utc_Leaps_table* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_utc__leaps_table kk_std_time_utc__new_Leaps_table(kk_reuse_t _at, int32_t _cpath, kk_std_time_instant__instant expire, kk_std_core_types__list adjusts, kk_context_t* _ctx) {
  struct kk_std_time_utc_Leaps_table* _con = kk_block_alloc_at_as(struct kk_std_time_utc_Leaps_table, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->expire = expire;
  _con->adjusts = adjusts;
  return kk_std_time_utc__base_Leaps_table(_con, _ctx);
}
static inline struct kk_std_time_utc_Leaps_table* kk_std_time_utc__as_Leaps_table(kk_std_time_utc__leaps_table x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_utc_Leaps_table*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_utc__is_Leaps_table(kk_std_time_utc__leaps_table x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_utc__leaps_table kk_std_time_utc__leaps_table_dup(kk_std_time_utc__leaps_table _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_utc__leaps_table_drop(kk_std_time_utc__leaps_table _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_utc__leaps_table_box(kk_std_time_utc__leaps_table _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_utc__leaps_table kk_std_time_utc__leaps_table_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type std/time/utc/utc
struct kk_std_time_utc__utc_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_utc__utc;
struct kk_std_time_utc__Hnd_utc {
  struct kk_std_time_utc__utc_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause0 _fun_utc;
};
static inline kk_std_time_utc__utc kk_std_time_utc__base_Hnd_utc(struct kk_std_time_utc__Hnd_utc* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_utc__utc kk_std_time_utc__new_Hnd_utc(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause0 _fun_utc, kk_context_t* _ctx) {
  struct kk_std_time_utc__Hnd_utc* _con = kk_block_alloc_at_as(struct kk_std_time_utc__Hnd_utc, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_utc = _fun_utc;
  return kk_std_time_utc__base_Hnd_utc(_con, _ctx);
}
static inline struct kk_std_time_utc__Hnd_utc* kk_std_time_utc__as_Hnd_utc(kk_std_time_utc__utc x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_utc__Hnd_utc*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_utc__is_Hnd_utc(kk_std_time_utc__utc x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_utc__utc kk_std_time_utc__utc_dup(kk_std_time_utc__utc _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_utc__utc_drop(kk_std_time_utc__utc _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_utc__utc_box(kk_std_time_utc__utc _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_utc__utc kk_std_time_utc__utc_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:utc` type.

static inline kk_integer_t kk_std_time_utc_utc_fs__cfc(kk_std_time_utc__utc utc_0, kk_context_t* _ctx) { /* forall<e,a> (utc : utc<e,a>) -> int */ 
  {
    struct kk_std_time_utc__Hnd_utc* _con_x1186 = kk_std_time_utc__as_Hnd_utc(utc_0, _ctx);
    kk_integer_t _x = _con_x1186->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// select `utc` operation out of effect `:utc`

static inline kk_std_core_hnd__clause0 kk_std_time_utc_utc_fs__select(kk_std_time_utc__utc hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : utc<e,a>) -> hnd/clause0<std/time/instant/timescale,utc,e,a> */ 
  {
    struct kk_std_time_utc__Hnd_utc* _con_x1187 = kk_std_time_utc__as_Hnd_utc(hnd, _ctx);
    kk_std_core_hnd__clause0 _fun_utc = _con_x1187->_fun_utc;
    return kk_std_core_hnd__clause0_dup(_fun_utc, _ctx);
  }
}
 
// Call the `fun utc` operation of the effect `:utc`

static inline kk_std_time_instant__timescale kk_std_time_utc_utc(kk_context_t* _ctx) { /* () -> utc std/time/instant/timescale */ 
  kk_std_core_hnd__ev ev_10345 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
  kk_box_t _x_x1188;
  {
    struct kk_std_core_hnd_Ev* _con_x1189 = kk_std_core_hnd__as_Ev(ev_10345, _ctx);
    kk_box_t _box_x0 = _con_x1189->hnd;
    int32_t m = _con_x1189->marker;
    kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_time_utc__utc_dup(h, _ctx);
    {
      struct kk_std_time_utc__Hnd_utc* _con_x1190 = kk_std_time_utc__as_Hnd_utc(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x1190->_cfc;
      kk_std_core_hnd__clause0 _fun_utc = _con_x1190->_fun_utc;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_fun_utc, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x3 = _fun_utc.clause;
        _x_x1188 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x3, (_fun_unbox_x3, m, ev_10345, _ctx), _ctx); /*35*/
      }
    }
  }
  return kk_std_time_instant__timescale_unbox(_x_x1188, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-utc` constructor field of the `:utc` type.

static inline kk_std_core_hnd__clause0 kk_std_time_utc_utc_fs__fun_utc(kk_std_time_utc__utc utc_0, kk_context_t* _ctx) { /* forall<e,a> (utc : utc<e,a>) -> hnd/clause0<std/time/instant/timescale,utc,e,a> */ 
  {
    struct kk_std_time_utc__Hnd_utc* _con_x1191 = kk_std_time_utc__as_Hnd_utc(utc_0, _ctx);
    kk_std_core_hnd__clause0 _x = _con_x1191->_fun_utc;
    return kk_std_core_hnd__clause0_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_std_time_utc_utc_fs__tag;

kk_box_t kk_std_time_utc_utc_fs__handle(kk_std_time_utc__utc hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : utc<e,b>, ret : (res : a) -> e b, action : () -> <utc|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `expire` constructor field of the `:leaps-table` type.

static inline kk_std_time_instant__instant kk_std_time_utc_leaps_table_fs_expire(kk_std_time_utc__leaps_table _this, kk_context_t* _ctx) { /* (leaps-table) -> std/time/instant/instant */ 
  {
    struct kk_std_time_utc_Leaps_table* _con_x1195 = kk_std_time_utc__as_Leaps_table(_this, _ctx);
    kk_std_time_instant__instant _x = _con_x1195->expire;
    return kk_std_time_instant__instant_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `adjusts` constructor field of the `:leaps-table` type.

static inline kk_std_core_types__list kk_std_time_utc_leaps_table_fs_adjusts(kk_std_time_utc__leaps_table _this, kk_context_t* _ctx) { /* (leaps-table) -> list<leap-adjust> */ 
  {
    struct kk_std_time_utc_Leaps_table* _con_x1196 = kk_std_time_utc__as_Leaps_table(_this, _ctx);
    kk_std_time_instant__instant _pat_0 = _con_x1196->expire;
    kk_std_core_types__list _x = _con_x1196->adjusts;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}

kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_fs__copy(kk_std_time_utc__leaps_table _this, kk_std_core_types__optional expire, kk_std_core_types__optional adjusts, kk_context_t* _ctx); /* (leaps-table, expire : ? std/time/instant/instant, adjusts : ? (list<leap-adjust>)) -> leaps-table */ 
 
// Leap second adjustments. For an instant `i` after `start`:
// ``TAI-offset = offset + (drift * days(i - drift-start))``

static inline kk_std_time_utc__leap_adjust kk_std_time_utc__create_Leap_adjust(kk_std_time_timestamp__timestamp utc_start, kk_std_num_ddouble__ddouble offset, kk_std_core_types__optional drift_start, kk_std_core_types__optional drift, kk_context_t* _ctx) { /* (utc-start : utc-timestamp, offset : std/time/timestamp/timespan, drift-start : ? utc-timestamp, drift : ? std/num/ddouble/ddouble) -> leap-adjust */ 
  kk_std_time_timestamp__timestamp _x_x1201;
  if (kk_std_core_types__is_Optional(drift_start, _ctx)) {
    kk_box_t _box_x16 = drift_start._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_drift_start_396 = kk_std_time_timestamp__timestamp_unbox(_box_x16, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_drift_start_396, _ctx);
    kk_std_core_types__optional_drop(drift_start, _ctx);
    _x_x1201 = _uniq_drift_start_396; /*std/time/utc/utc-timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(drift_start, _ctx);
    _x_x1201 = kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp_timestamp0, _ctx); /*std/time/utc/utc-timestamp*/
  }
  kk_std_num_ddouble__ddouble _x_x1202;
  if (kk_std_core_types__is_Optional(drift, _ctx)) {
    kk_box_t _box_x17 = drift._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_drift_400 = kk_std_num_ddouble__ddouble_unbox(_box_x17, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(drift, _ctx);
    _x_x1202 = _uniq_drift_400; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(drift, _ctx);
    _x_x1202 = kk_std_num_ddouble_zero; /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_utc__new_Leap_adjust(kk_reuse_null, 0, utc_start, offset, _x_x1201, _x_x1202, _ctx);
}

extern kk_std_time_utc__leap_adjust kk_std_time_utc_zero;
 
// Automatically generated. Retrieves the `utc-start` constructor field of the `:leap-adjust` type.

static inline kk_std_time_timestamp__timestamp kk_std_time_utc_leap_adjust_fs_utc_start(kk_std_time_utc__leap_adjust _this, kk_context_t* _ctx) { /* (leap-adjust) -> utc-timestamp */ 
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1205 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
    kk_std_time_timestamp__timestamp _x = _con_x1205->utc_start;
    kk_std_num_ddouble__ddouble _pat_2 = _con_x1205->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x1205->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1205->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1206 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1207 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    return kk_std_time_timestamp__timestamp_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `offset` constructor field of the `:leap-adjust` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_utc_leap_adjust_fs_offset(kk_std_time_utc__leap_adjust _this, kk_context_t* _ctx) { /* (leap-adjust) -> std/time/timestamp/timespan */ 
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1208 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
    kk_std_time_timestamp__timestamp _pat_0 = _con_x1208->utc_start;
    kk_std_num_ddouble__ddouble _x = _con_x1208->offset;
    kk_std_time_timestamp__timestamp _pat_5 = _con_x1208->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1208->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1209 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1210 = kk_std_time_timestamp__as_Timestamp(_pat_5, _ctx);
    return _x;
  }
}
 
// Automatically generated. Retrieves the `drift-start` constructor field of the `:leap-adjust` type.

static inline kk_std_time_timestamp__timestamp kk_std_time_utc_leap_adjust_fs_drift_start(kk_std_time_utc__leap_adjust _this, kk_context_t* _ctx) { /* (leap-adjust) -> utc-timestamp */ 
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1211 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
    kk_std_time_timestamp__timestamp _pat_0 = _con_x1211->utc_start;
    kk_std_num_ddouble__ddouble _pat_3 = _con_x1211->offset;
    kk_std_time_timestamp__timestamp _x = _con_x1211->drift_start;
    kk_std_num_ddouble__ddouble _pat_8 = _con_x1211->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1212 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1213 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    return kk_std_time_timestamp__timestamp_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `drift` constructor field of the `:leap-adjust` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_utc_leap_adjust_fs_drift(kk_std_time_utc__leap_adjust _this, kk_context_t* _ctx) { /* (leap-adjust) -> std/num/ddouble/ddouble */ 
  {
    struct kk_std_time_utc_Leap_adjust* _con_x1214 = kk_std_time_utc__as_Leap_adjust(_this, _ctx);
    kk_std_time_timestamp__timestamp _pat_0 = _con_x1214->utc_start;
    kk_std_num_ddouble__ddouble _pat_3 = _con_x1214->offset;
    kk_std_time_timestamp__timestamp _pat_6 = _con_x1214->drift_start;
    kk_std_num_ddouble__ddouble _x = _con_x1214->drift;
    struct kk_std_time_timestamp_Timestamp* _con_x1215 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_timestamp_Timestamp* _con_x1216 = kk_std_time_timestamp__as_Timestamp(_pat_6, _ctx);
    return _x;
  }
}

kk_std_time_utc__leap_adjust kk_std_time_utc_leap_adjust_fs__copy(kk_std_time_utc__leap_adjust _this, kk_std_core_types__optional utc_start, kk_std_core_types__optional offset, kk_std_core_types__optional drift_start, kk_std_core_types__optional drift, kk_context_t* _ctx); /* (leap-adjust, utc-start : ? utc-timestamp, offset : ? std/time/timestamp/timespan, drift-start : ? utc-timestamp, drift : ? std/num/ddouble/ddouble) -> leap-adjust */ 

bool kk_std_time_utc_is_zero(kk_std_time_utc__leap_adjust la, kk_context_t* _ctx); /* (la : leap-adjust) -> bool */ 

extern kk_std_num_ddouble__ddouble kk_std_time_utc_ntp2000;

extern kk_std_time_timestamp__timestamp kk_std_time_utc_utc1958;

kk_std_time_utc__leap_adjust kk_std_time_utc_find_leap_adjust(kk_std_time_timestamp__timestamp utc_0, kk_std_core_types__list leaps, kk_context_t* _ctx); /* (utc : utc-timestamp, leaps : list<leap-adjust>) -> leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc_utc_to_leap_adjust(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx); /* (leaps : leaps-table, utc : utc-timestamp) -> leap-adjust */ 

kk_std_num_ddouble__ddouble kk_std_time_utc_delta_tai(kk_std_time_utc__leap_adjust la, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx); /* (la : leap-adjust, utc : utc-timestamp) -> std/time/timestamp/timespan */ 

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_to_delta_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx); /* (leaps : leaps-table, utc : utc-timestamp) -> std/time/timestamp/timespan */ 

kk_std_time_duration__duration kk_std_time_utc_utc_to_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx); /* (leaps : leaps-table, utc : std/time/timestamp/timestamp) -> std/time/duration/duration */ 

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_from_tai(kk_std_time_utc__leaps_table leaps, kk_std_time_duration__duration tai_since, kk_context_t* _ctx); /* (leaps : leaps-table, tai-since : std/time/duration/duration) -> std/time/timestamp/timestamp */ 

kk_std_core_types__maybe kk_std_time_utc_utc_leap_in_day(kk_std_time_utc__leaps_table leaps, kk_integer_t days, kk_context_t* _ctx); /* (leaps : leaps-table, days : int) -> maybe<(std/time/timestamp/timestamp, std/time/timestamp/timespan)> */ 

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_seconds_in_day(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx); /* (leaps : leaps-table, utc : std/time/timestamp/timestamp) -> std/time/timestamp/timespan */ 

kk_std_num_ddouble__ddouble kk_std_time_utc_utc_to_mjd(kk_std_time_utc__leaps_table leaps, kk_std_time_timestamp__timestamp utc_0, kk_std_num_ddouble__ddouble tzdelta, kk_context_t* _ctx); /* (leaps : leaps-table, utc : utc-timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_from_mjd(kk_std_time_utc__leaps_table leaps, kk_integer_t days, kk_std_num_ddouble__ddouble frac, kk_context_t* _ctx); /* (leaps : leaps-table, days : int, frac : std/num/ddouble/ddouble) -> utc-timestamp */ 

kk_std_time_instant__timescale kk_std_time_utc_utc_timescale(kk_string_t name, kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx); /* (name : string, leaps : leaps-table) -> std/time/instant/timescale */ 

kk_std_time_utc__leaps_table kk_std_time_utc_upto(kk_std_time_utc__leaps_table lt, kk_std_time_timestamp__timestamp end, kk_context_t* _ctx); /* (lt : leaps-table, end : utc-timestamp) -> leaps-table */ 

kk_std_time_utc__leaps_table kk_std_time_utc_extend(kk_std_time_utc__leaps_table leap1, kk_std_time_utc__leaps_table leap2, kk_context_t* _ctx); /* (leap1 : leaps-table, leap2 : leaps-table) -> leaps-table */ 
 
// IERS leap second data valid until 2024-12-28

extern kk_std_num_ddouble__ddouble kk_std_time_utc_jd_epoch_shift;

extern kk_std_num_ddouble__ddouble kk_std_time_utc_mjd_epoch_shift;

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10316(kk_std_num_ddouble__ddouble ntpex, kk_context_t* _ctx); /* (ntpex : std/num/ddouble/ddouble) -> std/text/parse/parse std/time/timestamp/timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10317(kk_string_t wild___1, kk_context_t* _ctx); /* (wild_@1 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10318(kk_string_t wild___0, kk_context_t* _ctx); /* (wild_@0 : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_utc__mlift_pexpire_10319(kk_string_t wild__, kk_context_t* _ctx); /* (wild_ : string) -> std/text/parse/parse std/time/timestamp/timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_utc_pexpire(kk_context_t* _ctx); /* () -> std/text/parse/parse std/time/timestamp/timestamp */ 

kk_std_core_types__maybe kk_std_time_utc_parse_expire(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> maybe<std/time/timestamp/timestamp> */ 

kk_std_time_instant__instant kk_std_time_utc_parse_leap_expire(kk_string_t leaps, kk_std_core_types__list adjusts, kk_context_t* _ctx); /* (leaps : string, adjusts : list<leap-adjust>) -> std/time/instant/instant */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10320(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___10, kk_context_t* _ctx); /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@10 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10321(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___9, kk_context_t* _ctx); /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@9 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10322(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble drift, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_string_t wild___8, kk_context_t* _ctx); /* (dmjd : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, wild_@8 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10323(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_num_ddouble__ddouble drift, kk_context_t* _ctx); /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, drift : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10324(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_core_types__list _y_x10249, kk_context_t* _ctx); /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, list<char>) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10325(kk_std_num_ddouble__ddouble dmjd, kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_char_t _y_x10248, kk_context_t* _ctx); /* (dmjd : std/num/ddouble/ddouble, mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, char) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10326(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_num_ddouble__ddouble dmjd, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, dmjd : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10327(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_std_core_types__list _y_x10246, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, list<char>) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10328(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_char_t _y_x10245, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble, char) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10329(kk_std_num_ddouble__ddouble mjd, kk_std_num_ddouble__ddouble ofs, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, ofs : std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10330(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___5, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, wild_@5 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10331(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___4, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, wild_@4 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10332(kk_std_num_ddouble__ddouble mjd, kk_string_t wild___3, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, wild_@3 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10333(kk_std_num_ddouble__ddouble _y_x10240, kk_context_t* _ctx); /* (std/num/ddouble/ddouble) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10334(kk_string_t wild___2, kk_context_t* _ctx); /* (wild_@2 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10335(kk_string_t wild___1, kk_context_t* _ctx); /* (wild_@1 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10336(kk_std_core_types__list _y_x10237, kk_context_t* _ctx); /* (list<char>) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10337(kk_char_t _y_x10235, kk_context_t* _ctx); /* (char) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_ptaiadjust_10338(kk_string_t wild__, kk_context_t* _ctx); /* (wild_ : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc_ptaiadjust(kk_context_t* _ctx); /* () -> std/text/parse/parse leap-adjust */ 
 
// monadic lift

static inline kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_parse_taiadjust_10339(kk_std_time_utc__leap_adjust x, kk_unit_t wild__, kk_context_t* _ctx) { /* (x : leap-adjust, wild_ : ()) -> std/text/parse/parse leap-adjust */ 
  return x;
}

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_parse_taiadjust_10340(kk_std_time_utc__leap_adjust x, kk_context_t* _ctx); /* (x : leap-adjust) -> std/text/parse/parse leap-adjust */ 

kk_std_core_types__maybe kk_std_time_utc_parse_taiadjust(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> maybe<leap-adjust> */ 

kk_std_time_utc__leaps_table kk_std_time_utc_parse_leap_seconds_dat(kk_string_t leaps, kk_context_t* _ctx); /* (leaps : string) -> leaps-table */ 
 
// TAI leap second adjustments for dates before 1972-01-01Z are linear interpolations.
// TAI started in 1958-01-01Z. The initial official UTC time step in 1961-01-01Z was 1.422818s and before that there
// were small steps of 20ms. See Explanatory Supplement to the Astronomical Almanac, 1992 edition, pages 86--87.
// In 1958, the supplement remarks that WWC operated at an offset of _about_ -100e-10, we
// change it to -85e-10 to end up with TAI-UTC == 0 at 1958-01-01.
// (without a rate change it is a negative -0.0472380s).
// Note the JD dates are at 0.29167 as the time steps were usually at 19:00h instead of midnight.

extern kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_pre1972;

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10341(kk_integer_t ntpsecs, kk_integer_t adjust, kk_context_t* _ctx); /* (ntpsecs : int, adjust : int) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10342(kk_integer_t ntpsecs, kk_string_t wild___0, kk_context_t* _ctx); /* (ntpsecs : int, wild_@0 : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10343(kk_integer_t ntpsecs, kk_context_t* _ctx); /* (ntpsecs : int) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc__mlift_pleap_10344(kk_string_t wild__, kk_context_t* _ctx); /* (wild_ : string) -> std/text/parse/parse leap-adjust */ 

kk_std_time_utc__leap_adjust kk_std_time_utc_pleap(kk_context_t* _ctx); /* () -> std/text/parse/parse leap-adjust */ 

kk_std_core_types__maybe kk_std_time_utc_parse_leap(kk_string_t line, kk_context_t* _ctx); /* (line : string) -> maybe<leap-adjust> */ 

kk_std_time_utc__leaps_table kk_std_time_utc_parse_leap_seconds(kk_string_t leaps, kk_context_t* _ctx); /* (leaps : string) -> leaps-table */ 

extern kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_ti;

extern kk_std_time_instant__timescale kk_std_time_utc_ts_ti;

kk_box_t kk_std_time_utc__default_utc(kk_function_t action, kk_context_t* _ctx); /* forall<a,e> (action : () -> <utc|e> a) -> e a */ 

extern kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table0;

kk_string_t kk_std_time_utc_leap_adjust_fs_show(kk_std_time_utc__leap_adjust l, kk_context_t* _ctx); /* (l : leap-adjust) -> string */ 

kk_string_t kk_std_time_utc_leaps_table_fs_show(kk_std_time_utc__leaps_table t, kk_context_t* _ctx); /* (t : leaps-table) -> string */ 

extern kk_std_num_ddouble__ddouble kk_std_time_utc_unix2000;

kk_std_time_instant__instant kk_std_time_utc_timespan_fs_unix_instant(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (t : std/time/timestamp/timespan, leap : ? int, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_utc_float64_fs_unix_instant(double u, kk_std_core_types__optional frac, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (u : float64, frac : ? float64, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_utc_int_fs_unix_instant(kk_integer_t u, kk_std_core_types__optional frac, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (u : int, frac : ? float64, ts : ? std/time/instant/timescale) -> std/time/instant/instant */ 

kk_std_num_ddouble__ddouble kk_std_time_utc_unix_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : std/time/instant/instant) -> std/num/ddouble/ddouble */ 

extern kk_std_time_instant__timescale kk_std_time_utc_ts_ntp;

kk_std_time_instant__instant kk_std_time_utc_ntp_instant(kk_std_num_ddouble__ddouble ntp, kk_std_core_types__optional leap, kk_context_t* _ctx); /* (ntp : std/num/ddouble/ddouble, leap : ? int) -> std/time/instant/instant */ 

kk_std_num_ddouble__ddouble kk_std_time_utc_ntp_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : std/time/instant/instant) -> std/num/ddouble/ddouble */ 
 
// The UTC time scale.

static inline kk_std_time_instant__timescale kk_std_time_utc_ts_utc_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_string_t _x_x2209;
  kk_define_string_literal(, _s_x2210, 3, "UTC", _ctx)
  _x_x2209 = kk_string_dup(_s_x2210, _ctx); /*string*/
  return kk_std_time_utc_utc_timescale(_x_x2209, leaps, _ctx);
}
 
// [Unix](https://en.wikipedia.org/wiki/Unix_time) time scale is equal
// to the UTC time scale (`ts-utc`).

static inline kk_std_time_instant__timescale kk_std_time_utc_ts_unix_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_string_t _x_x2211;
  kk_define_string_literal(, _s_x2212, 3, "UTC", _ctx)
  _x_x2211 = kk_string_dup(_s_x2212, _ctx); /*string*/
  return kk_std_time_utc_utc_timescale(_x_x2211, leaps, _ctx);
}
 
// [NTP](https://en.wikipedia.org/wiki/Network_Time_Protocol) time scale is equal
// to the UTC time scale (`ts-utc`).

static inline kk_std_time_instant__timescale kk_std_time_utc_ts_ntp_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : leaps-table) -> std/time/instant/timescale */ 
  kk_string_t _x_x2213;
  kk_define_string_literal(, _s_x2214, 3, "UTC", _ctx)
  _x_x2213 = kk_string_dup(_s_x2214, _ctx); /*string*/
  return kk_std_time_utc_utc_timescale(_x_x2213, leaps, _ctx);
}

extern kk_std_time_instant__timescale kk_std_time_utc_ts_unix;

kk_std_core_types__maybe kk_std_time_utc_utc_sls_leap_in_day(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_timestamp__timestamp utc_0, kk_context_t* _ctx); /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, utc : utc-timestamp) -> maybe<(std/time/timestamp/timestamp, std/time/timestamp/timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan)> */ 

kk_std_time_timestamp__timestamp kk_std_time_utc_utc_sls_from_tai(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_duration__duration tai_since, kk_context_t* _ctx); /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, tai-since : std/time/duration/duration) -> std/time/timestamp/timestamp */ 

kk_std_time_duration__duration kk_std_time_utc_utc_sls_to_tai(kk_std_time_utc__leaps_table leaps, kk_std_num_ddouble__ddouble smooth, kk_std_time_timestamp__timestamp sls, kk_context_t* _ctx); /* (leaps : leaps-table, smooth : std/time/timestamp/timespan, sls : utc-timestamp) -> std/time/duration/duration */ 

kk_std_time_instant__timescale kk_std_time_utc_utc_sls_timescale(kk_string_t name, kk_std_time_utc__leaps_table leaps, kk_std_core_types__optional smooth, kk_context_t* _ctx); /* (name : string, leaps : leaps-table, smooth : ? std/time/timestamp/timespan) -> std/time/instant/timescale */ 

kk_std_time_instant__timescale kk_std_time_utc_ts_utc_sls_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx); /* (leaps : leaps-table) -> std/time/instant/timescale */ 

extern kk_std_time_instant__timescale kk_std_time_utc_ts_ti_sls;

extern kk_std_time_utc__leaps_table kk_std_time_utc_leaps_table_y2017;

kk_std_core_types__list kk_std_time_utc_get_leap_steps(kk_std_core_types__optional table, kk_context_t* _ctx); /* (table : ? leaps-table) -> list<(utc-timestamp, std/time/timestamp/timespan, std/time/timestamp/timespan, (std/time/timestamp/timespan, utc-timestamp, std/num/ddouble/ddouble))> */ 

void kk_std_time_utc__init(kk_context_t* _ctx);


void kk_std_time_utc__done(kk_context_t* _ctx);

#endif // header
