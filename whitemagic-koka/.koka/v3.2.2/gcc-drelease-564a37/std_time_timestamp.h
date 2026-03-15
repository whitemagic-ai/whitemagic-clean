#pragma once
#ifndef kk_std_time_timestamp_H
#define kk_std_time_timestamp_H
// Koka generated module: std/time/timestamp, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_int32.h"
#include "std_time_date.h"

// type declarations

// type std/time/timestamp/timestamp
struct kk_std_time_timestamp__timestamp_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_timestamp__timestamp;
struct kk_std_time_timestamp_Timestamp {
  struct kk_std_time_timestamp__timestamp_s _base;
  kk_std_num_ddouble__ddouble since;
  int32_t leap32;
};
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__base_Timestamp(struct kk_std_time_timestamp_Timestamp* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__new_Timestamp(kk_reuse_t _at, int32_t _cpath, kk_std_num_ddouble__ddouble since, int32_t leap32, kk_context_t* _ctx) {
  struct kk_std_time_timestamp_Timestamp* _con = kk_block_alloc_at_as(struct kk_std_time_timestamp_Timestamp, _at, 0 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->since = since;
  _con->leap32 = leap32;
  return kk_std_time_timestamp__base_Timestamp(_con, _ctx);
}
static inline struct kk_std_time_timestamp_Timestamp* kk_std_time_timestamp__as_Timestamp(kk_std_time_timestamp__timestamp x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_timestamp_Timestamp*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_timestamp__is_Timestamp(kk_std_time_timestamp__timestamp x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__timestamp_dup(kk_std_time_timestamp__timestamp _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_timestamp__timestamp_drop(kk_std_time_timestamp__timestamp _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_timestamp__timestamp_box(kk_std_time_timestamp__timestamp _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_timestamp__timestamp kk_std_time_timestamp__timestamp_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// A zero-valued timespan.

extern kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan0;

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_float64_fs_timespan(double secs, kk_context_t* _ctx) { /* (secs : float64) -> timespan */ 
  return kk_std_num_ddouble__new_Ddouble(secs, 0x0p+0, _ctx);
}
 
// Timespan from a `:ddouble`. Just for convenience as `:timespan` is an alias

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_ddouble_fs_timespan(kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx) { /* (secs : std/num/ddouble/ddouble) -> timespan */ 
  return secs;
}
 
// Seconds in a solar day, 86400.

extern kk_integer_t kk_std_time_timestamp_isolar_secs_per_day;
 
// Automatically generated. Retrieves the `since` constructor field of the `:timestamp` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_timestamp_fs_since(kk_std_time_timestamp__timestamp timestamp_0, kk_context_t* _ctx) { /* (timestamp : timestamp) -> timespan */ 
  {
    struct kk_std_time_timestamp_Timestamp* _con_x160 = kk_std_time_timestamp__as_Timestamp(timestamp_0, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x160->since;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `leap32` constructor field of the `:timestamp` type.

static inline int32_t kk_std_time_timestamp_timestamp_fs_leap32(kk_std_time_timestamp__timestamp timestamp_0, kk_context_t* _ctx) { /* (timestamp : timestamp) -> int32 */ 
  {
    struct kk_std_time_timestamp_Timestamp* _con_x161 = kk_std_time_timestamp__as_Timestamp(timestamp_0, _ctx);
    kk_std_num_ddouble__ddouble _pat_0 = _con_x161->since;
    int32_t _x = _con_x161->leap32;
    return _x;
  }
}

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_fs__copy(kk_std_time_timestamp__timestamp _this, kk_std_core_types__optional since, kk_std_core_types__optional leap32, kk_context_t* _ctx); /* (timestamp, since : ? timespan, leap32 : ? int32) -> timestamp */ 

static inline kk_integer_t kk_std_time_timestamp_leap(kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (t : timestamp) -> int */ 
  int32_t _x_x166;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x167 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _pat_0 = _con_x167->since;
    int32_t _x = _con_x167->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x166 = _x; /*int32*/
  }
  return kk_integer_from_int(_x_x166,kk_context());
}

kk_std_core_types__order kk_std_time_timestamp_cmp(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> order */ 

static inline bool kk_std_time_timestamp__lp__eq__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_10014 = kk_std_time_timestamp_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x127;
  if (kk_std_core_types__is_Lt(x_10014, _ctx)) {
    _brw_x127 = kk_integer_from_small(-1); /*int*/
    goto _match_x180;
  }
  if (kk_std_core_types__is_Eq(x_10014, _ctx)) {
    _brw_x127 = kk_integer_from_small(0); /*int*/
    goto _match_x180;
  }
  {
    _brw_x127 = kk_integer_from_small(1); /*int*/
  }
  _match_x180: ;
  bool _brw_x128 = kk_integer_eq_borrow(_brw_x127,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x127, _ctx);
  return _brw_x128;
}

static inline bool kk_std_time_timestamp__lp__lt__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_10016 = kk_std_time_timestamp_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x125;
  if (kk_std_core_types__is_Lt(x_10016, _ctx)) {
    _brw_x125 = kk_integer_from_small(-1); /*int*/
    goto _match_x181;
  }
  if (kk_std_core_types__is_Eq(x_10016, _ctx)) {
    _brw_x125 = kk_integer_from_small(0); /*int*/
    goto _match_x181;
  }
  {
    _brw_x125 = kk_integer_from_small(1); /*int*/
  }
  _match_x181: ;
  bool _brw_x126 = kk_integer_eq_borrow(_brw_x125,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x125, _ctx);
  return _brw_x126;
}

static inline bool kk_std_time_timestamp__lp__excl__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_10018 = kk_std_time_timestamp_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x123;
  if (kk_std_core_types__is_Lt(x_10018, _ctx)) {
    _brw_x123 = kk_integer_from_small(-1); /*int*/
    goto _match_x182;
  }
  if (kk_std_core_types__is_Eq(x_10018, _ctx)) {
    _brw_x123 = kk_integer_from_small(0); /*int*/
    goto _match_x182;
  }
  {
    _brw_x123 = kk_integer_from_small(1); /*int*/
  }
  _match_x182: ;
  bool _brw_x124 = kk_integer_neq_borrow(_brw_x123,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x123, _ctx);
  return _brw_x124;
}

static inline bool kk_std_time_timestamp__lp__lt__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_10020 = kk_std_time_timestamp_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x121;
  if (kk_std_core_types__is_Lt(x_10020, _ctx)) {
    _brw_x121 = kk_integer_from_small(-1); /*int*/
    goto _match_x183;
  }
  if (kk_std_core_types__is_Eq(x_10020, _ctx)) {
    _brw_x121 = kk_integer_from_small(0); /*int*/
    goto _match_x183;
  }
  {
    _brw_x121 = kk_integer_from_small(1); /*int*/
  }
  _match_x183: ;
  bool _brw_x122 = kk_integer_neq_borrow(_brw_x121,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x121, _ctx);
  return _brw_x122;
}

static inline bool kk_std_time_timestamp__lp__gt__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_10022 = kk_std_time_timestamp_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x119;
  if (kk_std_core_types__is_Lt(x_10022, _ctx)) {
    _brw_x119 = kk_integer_from_small(-1); /*int*/
    goto _match_x184;
  }
  if (kk_std_core_types__is_Eq(x_10022, _ctx)) {
    _brw_x119 = kk_integer_from_small(0); /*int*/
    goto _match_x184;
  }
  {
    _brw_x119 = kk_integer_from_small(1); /*int*/
  }
  _match_x184: ;
  bool _brw_x120 = kk_integer_eq_borrow(_brw_x119,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x119, _ctx);
  return _brw_x120;
}

static inline bool kk_std_time_timestamp__lp__gt__eq__rp_(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx) { /* (i : timestamp, j : timestamp) -> bool */ 
  kk_std_core_types__order x_10024 = kk_std_time_timestamp_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x117;
  if (kk_std_core_types__is_Lt(x_10024, _ctx)) {
    _brw_x117 = kk_integer_from_small(-1); /*int*/
    goto _match_x185;
  }
  if (kk_std_core_types__is_Eq(x_10024, _ctx)) {
    _brw_x117 = kk_integer_from_small(0); /*int*/
    goto _match_x185;
  }
  {
    _brw_x117 = kk_integer_from_small(1); /*int*/
  }
  _match_x185: ;
  bool _brw_x118 = kk_integer_neq_borrow(_brw_x117,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x117, _ctx);
  return _brw_x118;
}

kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__plus__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx); /* (ts : timestamp, t : timespan) -> timestamp */ 

kk_std_num_ddouble__ddouble kk_std_time_timestamp_int_fs_timespan(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx); /* (seconds : int, frac : ? float64) -> timespan */ 

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_tuple64_fs_timespan(double secs, double frac, kk_context_t* _ctx) { /* (secs : float64, frac : float64) -> timespan */ 
  bool _match_x115 = (frac == (0x0p+0)); /*bool*/;
  if (_match_x115) {
    return kk_std_num_ddouble__new_Ddouble(secs, 0x0p+0, _ctx);
  }
  {
    return kk_std_num_ddouble_dsum(secs, frac, _ctx);
  }
}
 
// Divide using `div` to allow for different timespan representations

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_div(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (x : timespan, y : timespan, prec : ? int) -> timespan */ 
  kk_std_core_types__optional_drop(prec, _ctx);
  return kk_std_num_ddouble__lp__fs__rp_(x, y, _ctx);
}

extern kk_std_num_ddouble__ddouble kk_std_time_timestamp_solar_secs_per_day;

extern kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp0;

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp(kk_std_num_ddouble__ddouble t, kk_std_core_types__optional leap_0, kk_context_t* _ctx); /* (t : timespan, leap : ? int) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_int_fs_timestamp(kk_integer_t t, kk_std_core_types__optional frac, kk_std_core_types__optional leap_0, kk_context_t* _ctx); /* (t : int, frac : ? float64, leap : ? int) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_timestamp_days(kk_integer_t days_0, kk_std_core_types__optional secs, kk_std_core_types__optional leap_0, kk_context_t* _ctx); /* (days : int, secs : ? timespan, leap : ? int) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_days(kk_std_time_timestamp__timestamp ts, kk_integer_t days_0, kk_context_t* _ctx); /* (ts : timestamp, days : int) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp__lp__dash__rp_(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx); /* (ts : timestamp, t : timespan) -> timestamp */ 

kk_std_core_types__tuple2 kk_std_time_timestamp_days_seconds(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> (int, std/num/ddouble/ddouble) */ 

kk_std_core_types__tuple2 kk_std_time_timestamp_days_clock(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> (int, std/time/date/clock) */ 

static inline kk_integer_t kk_std_time_timestamp_days(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> int */ 
  kk_std_core_types__tuple2 tuple2_10075 = kk_std_time_timestamp_days_seconds(ts, _ctx); /*(int, std/num/ddouble/ddouble)*/;
  {
    kk_box_t _box_x34 = tuple2_10075.fst;
    kk_box_t _box_x35 = tuple2_10075.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x34, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    return _x;
  }
}

kk_std_num_ddouble__ddouble kk_std_time_timestamp_seconds_into_day(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> std/num/ddouble/ddouble */ 

kk_std_num_ddouble__ddouble kk_std_time_timestamp_unsafe_timespan_withleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx); /* (ts : timestamp) -> timespan */ 
 
// The time span since 2000-01-01 for time scales that do not have
// leap seconds and where every day is 86400s. For time scales
// with leap seconds, this effectively ignores any leap seconds.

static inline kk_std_num_ddouble__ddouble kk_std_time_timestamp_timespan_noleap(kk_std_time_timestamp__timestamp ts, kk_context_t* _ctx) { /* (ts : timestamp) -> timespan */ 
  {
    struct kk_std_time_timestamp_Timestamp* _con_x267 = kk_std_time_timestamp__as_Timestamp(ts, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x267->since;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_datatype_ptr_decref(ts, _ctx);
    }
    return _x;
  }
}

kk_std_time_timestamp__timestamp kk_std_time_timestamp_round_to_prec(kk_std_time_timestamp__timestamp t, kk_integer_t prec, kk_context_t* _ctx); /* (t : timestamp, prec : int) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_add_leap_seconds(kk_std_time_timestamp__timestamp ts, kk_std_num_ddouble__ddouble leaps, kk_context_t* _ctx); /* (ts : timestamp, leaps : timespan) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_min(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> timestamp */ 

kk_std_time_timestamp__timestamp kk_std_time_timestamp_max(kk_std_time_timestamp__timestamp i, kk_std_time_timestamp__timestamp j, kk_context_t* _ctx); /* (i : timestamp, j : timestamp) -> timestamp */ 

kk_string_t kk_std_time_timestamp_ts_show(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx); /* (ts : timestamp, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 

kk_string_t kk_std_time_timestamp_ts_show_days(kk_std_time_timestamp__timestamp ts, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (ts : timestamp, prec : ? int) -> string */ 

void kk_std_time_timestamp__init(kk_context_t* _ctx);


void kk_std_time_timestamp__done(kk_context_t* _ctx);

#endif // header
