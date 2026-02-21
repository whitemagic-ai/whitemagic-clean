#pragma once
#ifndef kk_std_time_instant_H
#define kk_std_time_instant_H
// Koka generated module: std/time/instant, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_ddouble.h"
#include "std_time_timestamp.h"
#include "std_time_duration.h"
#include "std_time_date.h"
#include "std_num_int32.h"
#include "std_num_float64.h"

// type declarations

// type std/time/instant/timescale
struct kk_std_time_instant__timescale_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_instant__timescale;
struct kk_std_time_instant_Timescale {
  struct kk_std_time_instant__timescale_s _base;
  kk_string_t name;
  kk_string_t unit;
  kk_function_t from_tai;
  kk_function_t to_tai;
  kk_std_core_types__maybe mb_seconds_in_day;
  kk_std_core_types__maybe mb_to_mjd2000;
  kk_std_core_types__maybe mb_from_mjd2000;
};
static inline kk_std_time_instant__timescale kk_std_time_instant__base_Timescale(struct kk_std_time_instant_Timescale* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_instant__timescale kk_std_time_instant__new_Timescale(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_string_t unit, kk_function_t from_tai, kk_function_t to_tai, kk_std_core_types__maybe mb_seconds_in_day, kk_std_core_types__maybe mb_to_mjd2000, kk_std_core_types__maybe mb_from_mjd2000, kk_context_t* _ctx) {
  struct kk_std_time_instant_Timescale* _con = kk_block_alloc_at_as(struct kk_std_time_instant_Timescale, _at, 10 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->unit = unit;
  _con->from_tai = from_tai;
  _con->to_tai = to_tai;
  _con->mb_seconds_in_day = mb_seconds_in_day;
  _con->mb_to_mjd2000 = mb_to_mjd2000;
  _con->mb_from_mjd2000 = mb_from_mjd2000;
  return kk_std_time_instant__base_Timescale(_con, _ctx);
}
static inline struct kk_std_time_instant_Timescale* kk_std_time_instant__as_Timescale(kk_std_time_instant__timescale x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_instant_Timescale*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_instant__is_Timescale(kk_std_time_instant__timescale x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_instant__timescale kk_std_time_instant__timescale_dup(kk_std_time_instant__timescale _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_instant__timescale_drop(kk_std_time_instant__timescale _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_instant__timescale_box(kk_std_time_instant__timescale _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_instant__timescale kk_std_time_instant__timescale_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type std/time/instant/instant
struct kk_std_time_instant_Instant {
  kk_std_time_timestamp__timestamp since;
  kk_std_time_instant__timescale ts;
};
typedef struct kk_std_time_instant_Instant kk_std_time_instant__instant;
static inline kk_std_time_instant__instant kk_std_time_instant__new_Instant(kk_std_time_timestamp__timestamp since, kk_std_time_instant__timescale ts, kk_context_t* _ctx) {
  kk_std_time_instant__instant _con;
  _con.since = since;
  _con.ts = ts;
  return _con;
}
static inline bool kk_std_time_instant__is_Instant(kk_std_time_instant__instant x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_instant__instant kk_std_time_instant__instant_dup(kk_std_time_instant__instant _x, kk_context_t* _ctx) {
  kk_std_time_timestamp__timestamp_dup(_x.since, _ctx);
  kk_std_time_instant__timescale_dup(_x.ts, _ctx);
  return _x;
}
static inline void kk_std_time_instant__instant_drop(kk_std_time_instant__instant _x, kk_context_t* _ctx) {
  kk_std_time_timestamp__timestamp_drop(_x.since, _ctx);
  kk_std_time_instant__timescale_drop(_x.ts, _ctx);
}
static inline kk_box_t kk_std_time_instant__instant_box(kk_std_time_instant__instant _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_time_instant__instant, _box, _x, 2 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_time_instant__instant kk_std_time_instant__instant_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_time_instant__instant _unbox;
  kk_valuetype_unbox(kk_std_time_instant__instant, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value declarations
 
// A time scale defines how time is measured: the rate and unit of time,
// and how it can be converted to- and from TAI.
// For time calculations, usually the [TAI](https://en.wikipedia.org/wiki/International_Atomic_Time)
// (international atomic time) time scale (`ts-tai`) is used which is time measured as SI seconds on the Earths geoid.
// Another common time scale is UTC (`std/time/utc/ts-utc`) which also uses SI second time units but can contain leap seconds.

static inline kk_std_time_instant__timescale kk_std_time_instant__create_Timescale(kk_string_t name, kk_string_t unit, kk_function_t from_tai_0, kk_function_t to_tai_0, kk_std_core_types__optional mb_seconds_in_day, kk_std_core_types__optional mb_to_mjd2000, kk_std_core_types__optional mb_from_mjd2000, kk_context_t* _ctx) { /* (name : string, unit : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, mb-seconds-in-day : ? (maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), mb-to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), mb-from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
  kk_std_core_types__maybe _x_x276;
  if (kk_std_core_types__is_Optional(mb_seconds_in_day, _ctx)) {
    kk_box_t _box_x0 = mb_seconds_in_day._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_seconds_in_day_129 = kk_std_core_types__maybe_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_seconds_in_day_129, _ctx);
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    _x_x276 = _uniq_mb_seconds_in_day_129; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    _x_x276 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x277;
  if (kk_std_core_types__is_Optional(mb_to_mjd2000, _ctx)) {
    kk_box_t _box_x1 = mb_to_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_to_mjd2000_135 = kk_std_core_types__maybe_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_to_mjd2000_135, _ctx);
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    _x_x277 = _uniq_mb_to_mjd2000_135; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    _x_x277 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x278;
  if (kk_std_core_types__is_Optional(mb_from_mjd2000, _ctx)) {
    kk_box_t _box_x2 = mb_from_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_from_mjd2000_141 = kk_std_core_types__maybe_unbox(_box_x2, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_from_mjd2000_141, _ctx);
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    _x_x278 = _uniq_mb_from_mjd2000_141; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    _x_x278 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, name, unit, from_tai_0, to_tai_0, _x_x276, _x_x277, _x_x278, _ctx);
}
 
// Automatically generated. Retrieves the `name` constructor field of the `:timescale` type.

static inline kk_string_t kk_std_time_instant_timescale_fs_name(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> string */ 
  {
    struct kk_std_time_instant_Timescale* _con_x279 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_string_t _x = _con_x279->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `unit` constructor field of the `:timescale` type.

static inline kk_string_t kk_std_time_instant_timescale_fs_unit(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> string */ 
  {
    struct kk_std_time_instant_Timescale* _con_x280 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_string_t _x = _con_x280->unit;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `from-tai` constructor field of the `:timescale` type.

static inline kk_function_t kk_std_time_instant_timescale_fs_from_tai(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> ((std/time/duration/duration) -> std/time/timestamp/timestamp) */ 
  {
    struct kk_std_time_instant_Timescale* _con_x281 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_function_t _x = _con_x281->from_tai;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `to-tai` constructor field of the `:timescale` type.

static inline kk_function_t kk_std_time_instant_timescale_fs_to_tai(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> ((std/time/timestamp/timestamp) -> std/time/duration/duration) */ 
  {
    struct kk_std_time_instant_Timescale* _con_x282 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_function_t _x = _con_x282->to_tai;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `mb-seconds-in-day` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_timescale_fs_mb_seconds_in_day(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan> */ 
  {
    struct kk_std_time_instant_Timescale* _con_x283 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_std_core_types__maybe _x = _con_x283->mb_seconds_in_day;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `mb-to-mjd2000` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_timescale_fs_mb_to_mjd2000(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble> */ 
  {
    struct kk_std_time_instant_Timescale* _con_x284 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_std_core_types__maybe _x = _con_x284->mb_to_mjd2000;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `mb-from-mjd2000` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_timescale_fs_mb_from_mjd2000(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp> */ 
  {
    struct kk_std_time_instant_Timescale* _con_x285 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_std_core_types__maybe _x = _con_x285->mb_from_mjd2000;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}

kk_std_time_instant__timescale kk_std_time_instant_timescale_fs__copy(kk_std_time_instant__timescale _this, kk_std_core_types__optional name, kk_std_core_types__optional unit, kk_std_core_types__optional from_tai_0, kk_std_core_types__optional to_tai_0, kk_std_core_types__optional mb_seconds_in_day, kk_std_core_types__optional mb_to_mjd2000, kk_std_core_types__optional mb_from_mjd2000, kk_context_t* _ctx); /* (timescale, name : ? string, unit : ? string, from-tai : ? ((std/time/duration/duration) -> std/time/timestamp/timestamp), to-tai : ? ((std/time/timestamp/timestamp) -> std/time/duration/duration), mb-seconds-in-day : ? (maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), mb-to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), mb-from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
 
// Automatically generated. Retrieves the `since` constructor field of the `:instant` type.

static inline kk_std_time_timestamp__timestamp kk_std_time_instant_instant_fs_since(kk_std_time_instant__instant instant, kk_context_t* _ctx) { /* (instant : instant) -> std/time/timestamp/timestamp */ 
  {
    kk_std_time_timestamp__timestamp _x = instant.since;
    kk_std_time_instant__timescale _pat_2 = instant.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x306 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x307 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    return kk_std_time_timestamp__timestamp_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `ts` constructor field of the `:instant` type.

static inline kk_std_time_instant__timescale kk_std_time_instant_instant_fs_ts(kk_std_time_instant__instant instant, kk_context_t* _ctx) { /* (instant : instant) -> timescale */ 
  {
    kk_std_time_timestamp__timestamp _pat_0 = instant.since;
    kk_std_time_instant__timescale _x = instant.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x308 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x309 = kk_std_time_instant__as_Timescale(_x, _ctx);
    return kk_std_time_instant__timescale_dup(_x, _ctx);
  }
}
 
// Return the time scale that instant `i` uses.

static inline kk_std_time_instant__timescale kk_std_time_instant_instant_fs_timescale(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> timescale */ 
  {
    kk_std_time_timestamp__timestamp _pat_0 = i.since;
    kk_std_time_instant__timescale _x = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x310 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x311 = kk_std_time_instant__as_Timescale(_x, _ctx);
    kk_std_time_instant__timescale_dup(_x, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    return _x;
  }
}
 
// Return `:timestamp` since 2000-01-01 in the time scale of the instant

static inline kk_std_time_timestamp__timestamp kk_std_time_instant_instant_fs_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/timestamp/timestamp */ 
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x312 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x313 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    return _x;
  }
}

kk_std_time_instant__timescale kk_std_time_instant_timescale(kk_string_t name, kk_function_t from_tai_0, kk_function_t to_tai_0, kk_std_core_types__optional unit, kk_std_core_types__optional seconds_in_day_0, kk_std_core_types__optional to_mjd2000, kk_std_core_types__optional from_mjd2000, kk_context_t* _ctx); /* (name : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, unit : ? string, seconds-in-day : ? (maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 

kk_std_time_instant__timescale kk_std_time_instant_tai_timescale(kk_string_t name, kk_std_core_types__optional offset, kk_context_t* _ctx); /* (name : string, offset : ? std/time/duration/duration) -> timescale */ 

extern kk_std_time_instant__timescale kk_std_time_instant_ts_tai;

kk_std_time_instant__instant kk_std_time_instant_unsafe_add(kk_std_time_instant__instant i, kk_std_num_ddouble__ddouble tspan, kk_context_t* _ctx); /* (i : instant, tspan : std/time/timestamp/timespan) -> instant */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_convert(kk_std_time_timestamp__timestamp t, kk_std_time_instant__timescale from, kk_std_time_instant__timescale to, kk_context_t* _ctx); /* (t : std/time/timestamp/timestamp, from : timescale, to : timescale) -> std/time/timestamp/timestamp */ 
 
// Return a `:timestamp` for instant `i` in a certain time scale `tscale`.

static inline kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp _x_x367;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x368 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x369 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x367 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x370;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x371 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x372 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x370 = _x_0; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant_convert(_x_x367, _x_x370, tscale, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx); /* (i : instant, tscale : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (i : instant, d : std/time/duration/duration) -> instant */ 

kk_std_time_duration__duration kk_std_time_instant_instant_fs_duration(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/duration/duration */ 

kk_std_time_duration__duration kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> std/time/duration/duration */ 
 
// Subtract a duration from an instant in time.

static inline kk_std_time_instant__instant kk_std_time_instant_duration_fs__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration _x_x484;
  kk_std_num_ddouble__ddouble _x_x485;
  double _x_x486;
  double _x_x487;
  {
    kk_std_num_ddouble__ddouble _x_1 = d.secs;
    {
      double _x = _x_1.hi;
      _x_x487 = _x; /*float64*/
    }
  }
  _x_x486 = (-_x_x487); /*float64*/
  double _x_x488;
  double _x_x489;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = d.secs;
    {
      double _x_0 = _x_1_0.lo;
      _x_x489 = _x_0; /*float64*/
    }
  }
  _x_x488 = (-_x_x489); /*float64*/
  _x_x485 = kk_std_num_ddouble__new_Ddouble(_x_x486, _x_x488, _ctx); /*std/num/ddouble/ddouble*/
  _x_x484 = kk_std_time_duration__new_Duration(_x_x485, _ctx); /*std/time/duration/duration*/
  return kk_std_time_instant__lp__plus__rp_(i, _x_x484, _ctx);
}

kk_std_core_types__order kk_std_time_instant_cmp(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> order */ 

static inline bool kk_std_time_instant__lp__eq__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order _x_x517 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x517, kk_std_core_types__new_Eq(_ctx), _ctx);
}

bool kk_std_time_instant_timescale_fs__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx); /* (t1 : timescale, t2 : timescale) -> bool */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai(kk_std_time_instant__timescale ts, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
 
// Return the `:duration` since the `epoch` for a timestamp `t` interpreted in time scale `ts`.

static inline kk_std_time_duration__duration kk_std_time_instant_to_tai(kk_std_time_instant__timescale ts, kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (ts : timescale, t : std/time/timestamp/timestamp) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_0_10075;
  kk_std_time_instant__timescale _x_x527 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_0_10075 = kk_std_time_instant_convert(t, ts, _x_x527, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x528 = kk_std_time_timestamp_unsafe_timespan_withleap(t_0_10075, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x528, _ctx);
}

bool kk_std_time_instant_has_leap_seconds(kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (ts : timescale) -> bool */ 

kk_std_time_instant__instant kk_std_time_instant_instant_fs__copy(kk_std_time_instant__instant _this, kk_std_core_types__optional since, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (instant, since : ? std/time/timestamp/timestamp, ts : ? timescale) -> instant */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_seconds_in_day(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/timestamp/timespan */ 
 
// Return days since 2000-01-01 in the time scale of the instant

static inline kk_integer_t kk_std_time_instant_days(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> int */ 
  kk_std_core_types__tuple2 tuple2_10043;
  kk_std_time_timestamp__timestamp _x_x545;
  {
    kk_std_time_timestamp__timestamp _x_0 = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x546 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x547 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x545 = _x_0; /*std/time/timestamp/timestamp*/
  }
  tuple2_10043 = kk_std_time_timestamp_days_seconds(_x_x545, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x51 = tuple2_10043.fst;
    kk_box_t _box_x52 = tuple2_10043.snd;
    kk_integer_t _x = kk_integer_unbox(_box_x51, _ctx);
    kk_integer_dup(_x, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10043, _ctx);
    return _x;
  }
}

kk_std_core_types__tuple2 kk_std_time_instant_days_clock(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> (int, std/time/date/clock) */ 
 
// Create an instant from a time stamp `t` interpreted in time scale `ts`.
// Be careful to ensure that `t` should indeed be interpreted in the given time scale.

static inline kk_std_time_instant__instant kk_std_time_instant_timescale_fs_instant(kk_std_time_instant__timescale ts, kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (ts : timescale, t : std/time/timestamp/timestamp) -> instant */ 
  return kk_std_time_instant__new_Instant(t, ts, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_date_fs_instant(kk_std_time_instant__timescale ts, kk_integer_t days_0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx); /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : ? int) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_duration_fs_instant(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : std/time/duration/duration) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_round_to_prec(kk_std_time_instant__instant i, kk_integer_t prec, kk_context_t* _ctx); /* (i : instant, prec : int) -> instant */ 

static inline bool kk_std_time_instant__lp__lt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order _x_x629 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x629, kk_std_core_types__new_Lt(_ctx), _ctx);
}

static inline bool kk_std_time_instant__lp__excl__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order _x_x630 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x630, kk_std_core_types__new_Eq(_ctx), _ctx);
}

static inline bool kk_std_time_instant__lp__lt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order _x_x631 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x631, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_instant__lp__gt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order _x_x632 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x632, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_instant__lp__gt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order _x_x633 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x633, kk_std_core_types__new_Lt(_ctx), _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_min(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_max(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> instant */ 
 
// Add `days` days to the instant.

static inline kk_std_time_instant__instant kk_std_time_instant_add_days(kk_std_time_instant__instant i, kk_integer_t days_0, kk_context_t* _ctx) { /* (i : instant, days : int) -> instant */ 
  kk_std_time_timestamp__timestamp _x_x640;
  kk_std_time_timestamp__timestamp _x_x641;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x642 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x643 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x641 = _x; /*std/time/timestamp/timestamp*/
  }
  _x_x640 = kk_std_time_timestamp_add_days(_x_x641, days_0, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x644;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x645 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x646 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x644 = _x_0; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant__new_Instant(_x_x640, _x_x644, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_add_duration_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx); /* (i : instant, tscale : timescale, t : std/time/timestamp/timespan) -> instant */ 

kk_string_t kk_std_time_instant_show_raw(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx); /* (i : instant, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 

kk_string_t kk_std_time_instant_instant_fs_show(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_context_t* _ctx); /* (i : instant, max-prec : ? int, secs-width : ? int) -> string */ 

extern kk_std_time_instant__instant kk_std_time_instant_epoch;

extern kk_std_time_instant__timescale kk_std_time_instant_ts_gps;

extern kk_std_time_duration__duration kk_std_time_instant_gps2000;

kk_std_time_duration__duration kk_std_time_instant_gps_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/duration/duration */ 

kk_std_time_instant__instant kk_std_time_instant_duration_fs_gps_instant(kk_std_time_duration__duration gps, kk_context_t* _ctx); /* (gps : std/time/duration/duration) -> instant */ 

kk_std_core_types__tuple2 kk_std_time_instant_gps_week_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> (int, std/time/duration/duration) */ 

kk_std_time_instant__instant kk_std_time_instant_date_fs_gps_instant(kk_integer_t weeks, kk_std_time_duration__duration secs, kk_context_t* _ctx); /* (weeks : int, secs : std/time/duration/duration) -> instant */ 

extern kk_std_time_instant__timescale kk_std_time_instant_ts_tt;

extern kk_std_time_duration__duration kk_std_time_instant_tt2000;

kk_std_time_duration__duration kk_std_time_instant_instant_fs_tt_instant(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/duration/duration */ 

kk_std_time_instant__instant kk_std_time_instant_duration_fs_tt_instant(kk_std_time_duration__duration tt, kk_context_t* _ctx); /* (tt : std/time/duration/duration) -> instant */ 

kk_string_t kk_std_time_instant_timestamp_fs_show(kk_std_time_timestamp__timestamp t, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx); /* (t : std/time/timestamp/timestamp, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 

extern kk_std_num_ddouble__ddouble kk_std_time_instant_jd_epoch_delta;

extern kk_std_num_ddouble__ddouble kk_std_time_instant_mjd_epoch_delta;

kk_std_time_instant__instant kk_std_time_instant_ddouble_fs_instant_at_mjd(kk_std_num_ddouble__ddouble mjd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (mjd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 
 
// Create an instant given a [modified julian day](https://en.wikipedia.org/wiki/Julian_day).
// and time scale `ts`.
// `modified-julian-day = julian-day - 2400000.5`

static inline kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_mjd(double mjd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (mjd : float64, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble _x_x833 = kk_std_num_ddouble__new_Ddouble(mjd_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_instant_ddouble_fs_instant_at_mjd(_x_x833, ts, _ctx);
}
 
// Create an instant given a [julian day](https://en.wikipedia.org/wiki/Julian_day)
// and time scale `ts` .

static inline kk_std_time_instant__instant kk_std_time_instant_ddouble_fs_instant_at_jd(kk_std_num_ddouble__ddouble jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (jd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble _x_x834;
  kk_std_num_ddouble__ddouble _x_x835;
  double _x_x836;
  double _x_x837;
  kk_std_num_ddouble__ddouble _x_x838 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x838.hi;
    _x_x837 = _x; /*float64*/
  }
  _x_x836 = (-_x_x837); /*float64*/
  double _x_x839;
  double _x_x840;
  kk_std_num_ddouble__ddouble _x_x841 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x841.lo;
    _x_x840 = _x_0; /*float64*/
  }
  _x_x839 = (-_x_x840); /*float64*/
  _x_x835 = kk_std_num_ddouble__new_Ddouble(_x_x836, _x_x839, _ctx); /*std/num/ddouble/ddouble*/
  _x_x834 = kk_std_num_ddouble__lp__plus__rp_(jd_0, _x_x835, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_instant_ddouble_fs_instant_at_mjd(_x_x834, ts, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_jd(double jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (jd : float64, ts : timescale) -> instant */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx); /* (i : instant, tscale : timescale, tzdelta : ? std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 
 
// /* Return the julian day in a given time scale `ts` for an instant `i`.
// Properly takes leap seconds into account when calculating the fraction of the day
// in a UTC calendar. For example:
// ````
// > time(2014,12,31,23,59,59).jd
// 2457023.499988425925926
// 
// > time(2015,12,31,23,59,59).jd
// 2457388.499988425925926
// 
// > time(2016,12,31,23,59,59).jd
// 2457754.499976852119767
// 
// > time(2016,12,31,23,59,60).jd
// 2457754.499988426059884
// ````
// .
// */

static inline kk_std_num_ddouble__ddouble kk_std_time_instant_jd(kk_std_time_instant__instant i, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (i : instant, ts : timescale) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _x_x917 = kk_std_time_instant_mjd(i, ts, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x_x917, kk_std_time_instant_jd_epoch_delta, _ctx);
}

void kk_std_time_instant__init(kk_context_t* _ctx);


void kk_std_time_instant__done(kk_context_t* _ctx);

#endif // header
