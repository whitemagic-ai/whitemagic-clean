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
#include "std_num_float64.h"
#include "std_num_int32.h"

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
  kk_std_core_types__maybe _x_x612;
  if (kk_std_core_types__is_Optional(mb_seconds_in_day, _ctx)) {
    kk_box_t _box_x0 = mb_seconds_in_day._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_seconds_in_day_129 = kk_std_core_types__maybe_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_seconds_in_day_129, _ctx);
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    _x_x612 = _uniq_mb_seconds_in_day_129; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    _x_x612 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x613;
  if (kk_std_core_types__is_Optional(mb_to_mjd2000, _ctx)) {
    kk_box_t _box_x1 = mb_to_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_to_mjd2000_135 = kk_std_core_types__maybe_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_to_mjd2000_135, _ctx);
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    _x_x613 = _uniq_mb_to_mjd2000_135; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    _x_x613 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x614;
  if (kk_std_core_types__is_Optional(mb_from_mjd2000, _ctx)) {
    kk_box_t _box_x2 = mb_from_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_from_mjd2000_141 = kk_std_core_types__maybe_unbox(_box_x2, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_from_mjd2000_141, _ctx);
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    _x_x614 = _uniq_mb_from_mjd2000_141; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    _x_x614 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, name, unit, from_tai_0, to_tai_0, _x_x612, _x_x613, _x_x614, _ctx);
}
 
// Automatically generated. Retrieves the `name` constructor field of the `:timescale` type.

static inline kk_string_t kk_std_time_instant_timescale_fs_name(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> string */ 
  {
    struct kk_std_time_instant_Timescale* _con_x615 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_string_t _x = _con_x615->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `unit` constructor field of the `:timescale` type.

static inline kk_string_t kk_std_time_instant_timescale_fs_unit(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> string */ 
  {
    struct kk_std_time_instant_Timescale* _con_x616 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_string_t _x = _con_x616->unit;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `from-tai` constructor field of the `:timescale` type.

static inline kk_function_t kk_std_time_instant_timescale_fs_from_tai(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> ((std/time/duration/duration) -> std/time/timestamp/timestamp) */ 
  {
    struct kk_std_time_instant_Timescale* _con_x617 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_function_t _x = _con_x617->from_tai;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `to-tai` constructor field of the `:timescale` type.

static inline kk_function_t kk_std_time_instant_timescale_fs_to_tai(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> ((std/time/timestamp/timestamp) -> std/time/duration/duration) */ 
  {
    struct kk_std_time_instant_Timescale* _con_x618 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_function_t _x = _con_x618->to_tai;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `mb-seconds-in-day` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_timescale_fs_mb_seconds_in_day(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan> */ 
  {
    struct kk_std_time_instant_Timescale* _con_x619 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_std_core_types__maybe _x = _con_x619->mb_seconds_in_day;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `mb-to-mjd2000` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_timescale_fs_mb_to_mjd2000(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble> */ 
  {
    struct kk_std_time_instant_Timescale* _con_x620 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_std_core_types__maybe _x = _con_x620->mb_to_mjd2000;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `mb-from-mjd2000` constructor field of the `:timescale` type.

static inline kk_std_core_types__maybe kk_std_time_instant_timescale_fs_mb_from_mjd2000(kk_std_time_instant__timescale timescale_0, kk_context_t* _ctx) { /* (timescale : timescale) -> maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp> */ 
  {
    struct kk_std_time_instant_Timescale* _con_x621 = kk_std_time_instant__as_Timescale(timescale_0, _ctx);
    kk_std_core_types__maybe _x = _con_x621->mb_from_mjd2000;
    return kk_std_core_types__maybe_dup(_x, _ctx);
  }
}

kk_std_time_instant__timescale kk_std_time_instant_timescale_fs__copy(kk_std_time_instant__timescale _this, kk_std_core_types__optional name, kk_std_core_types__optional unit, kk_std_core_types__optional from_tai_0, kk_std_core_types__optional to_tai_0, kk_std_core_types__optional mb_seconds_in_day, kk_std_core_types__optional mb_to_mjd2000, kk_std_core_types__optional mb_from_mjd2000, kk_context_t* _ctx); /* (timescale, name : ? string, unit : ? string, from-tai : ? ((std/time/duration/duration) -> std/time/timestamp/timestamp), to-tai : ? ((std/time/timestamp/timestamp) -> std/time/duration/duration), mb-seconds-in-day : ? (maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), mb-to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), mb-from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
 
// Automatically generated. Retrieves the `since` constructor field of the `:instant` type.

static inline kk_std_time_timestamp__timestamp kk_std_time_instant_instant_fs_since(kk_std_time_instant__instant instant, kk_context_t* _ctx) { /* (instant : instant) -> std/time/timestamp/timestamp */ 
  {
    kk_std_time_timestamp__timestamp _x = instant.since;
    kk_std_time_instant__timescale _pat_2 = instant.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x642 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x643 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    return kk_std_time_timestamp__timestamp_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `ts` constructor field of the `:instant` type.

static inline kk_std_time_instant__timescale kk_std_time_instant_instant_fs_ts(kk_std_time_instant__instant instant, kk_context_t* _ctx) { /* (instant : instant) -> timescale */ 
  {
    kk_std_time_timestamp__timestamp _pat_0 = instant.since;
    kk_std_time_instant__timescale _x = instant.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x644 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x645 = kk_std_time_instant__as_Timescale(_x, _ctx);
    return kk_std_time_instant__timescale_dup(_x, _ctx);
  }
}
 
// Return the time scale that instant `i` uses.

static inline kk_std_time_instant__timescale kk_std_time_instant_instant_fs_timescale(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> timescale */ 
  {
    kk_std_time_timestamp__timestamp _pat_0 = i.since;
    kk_std_time_instant__timescale _x = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x646 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x647 = kk_std_time_instant__as_Timescale(_x, _ctx);
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
    struct kk_std_time_timestamp_Timestamp* _con_x648 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x649 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
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

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx); /* (i : instant, tscale : timescale) -> std/time/timestamp/timestamp */ 

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx); /* (i : instant, tscale : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (i : instant, d : std/time/duration/duration) -> instant */ 
 
// Return the (TAI) SI second duration since the `epoch` at this instant.

static inline kk_std_time_duration__duration kk_std_time_instant_instant_fs_duration(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10090;
  kk_std_time_instant__timescale _x_x871 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_10090 = kk_std_time_instant_timestamp_in(i, _x_x871, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x872 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10090, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x872, _ctx);
}

kk_std_time_duration__duration kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> std/time/duration/duration */ 

kk_std_time_instant__instant kk_std_time_instant_duration_fs__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (i : instant, d : std/time/duration/duration) -> instant */ 

kk_std_core_types__order kk_std_time_instant_cmp(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> order */ 

static inline bool kk_std_time_instant__lp__eq__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_10108 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x362;
  if (kk_std_core_types__is_Lt(x_10108, _ctx)) {
    _brw_x362 = kk_integer_from_small(-1); /*int*/
    goto _match_x1071;
  }
  if (kk_std_core_types__is_Eq(x_10108, _ctx)) {
    _brw_x362 = kk_integer_from_small(0); /*int*/
    goto _match_x1071;
  }
  {
    _brw_x362 = kk_integer_from_small(1); /*int*/
  }
  _match_x1071: ;
  bool _brw_x363 = kk_integer_eq_borrow(_brw_x362,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x362, _ctx);
  return _brw_x363;
}

bool kk_std_time_instant_timescale_fs__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx); /* (t1 : timescale, t2 : timescale) -> bool */ 

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai(kk_std_time_instant__timescale ts, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
 
// Return the `:duration` since the `epoch` for a timestamp `t` interpreted in time scale `ts`.

static inline kk_std_time_duration__duration kk_std_time_instant_to_tai(kk_std_time_instant__timescale ts, kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (ts : timescale, t : std/time/timestamp/timestamp) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_0_10125;
  kk_std_time_instant__timescale _x_x1102 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_0_10125 = kk_std_time_instant_convert(t, ts, _x_x1102, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x1103 = kk_std_time_timestamp_unsafe_timespan_withleap(t_0_10125, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x1103, _ctx);
}

bool kk_std_time_instant_has_leap_seconds(kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (ts : timescale) -> bool */ 

kk_std_time_instant__instant kk_std_time_instant_instant_fs__copy(kk_std_time_instant__instant _this, kk_std_core_types__optional since, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (instant, since : ? std/time/timestamp/timestamp, ts : ? timescale) -> instant */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_seconds_in_day(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> std/time/timestamp/timespan */ 

kk_integer_t kk_std_time_instant_days(kk_std_time_instant__instant i, kk_context_t* _ctx); /* (i : instant) -> int */ 
 
// Return days since 2000-01-01 in the time scale of the instant,
// together with the clock on that day.

static inline kk_std_core_types__tuple2 kk_std_time_instant_days_clock(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/date/clock) */ 
  kk_std_time_timestamp__timestamp _x_x1135;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1136 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1137 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x1135 = _x; /*std/time/timestamp/timestamp*/
  }
  return kk_std_time_timestamp_days_clock(_x_x1135, _ctx);
}
 
// Create an instant from a time stamp `t` interpreted in time scale `ts`.
// Be careful to ensure that `t` should indeed be interpreted in the given time scale.

static inline kk_std_time_instant__instant kk_std_time_instant_timescale_fs_instant(kk_std_time_instant__timescale ts, kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (ts : timescale, t : std/time/timestamp/timestamp) -> instant */ 
  return kk_std_time_instant__new_Instant(t, ts, _ctx);
}

kk_std_time_instant__instant kk_std_time_instant_date_fs_instant(kk_std_time_instant__timescale ts, kk_integer_t days_0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx); /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : ? int) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_duration_fs_instant(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : std/time/duration/duration) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_round_to_prec(kk_std_time_instant__instant i, kk_integer_t prec, kk_context_t* _ctx); /* (i : instant, prec : int) -> instant */ 

static inline bool kk_std_time_instant__lp__lt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_10159 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x344;
  if (kk_std_core_types__is_Lt(x_10159, _ctx)) {
    _brw_x344 = kk_integer_from_small(-1); /*int*/
    goto _match_x1259;
  }
  if (kk_std_core_types__is_Eq(x_10159, _ctx)) {
    _brw_x344 = kk_integer_from_small(0); /*int*/
    goto _match_x1259;
  }
  {
    _brw_x344 = kk_integer_from_small(1); /*int*/
  }
  _match_x1259: ;
  bool _brw_x345 = kk_integer_eq_borrow(_brw_x344,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x344, _ctx);
  return _brw_x345;
}

static inline bool kk_std_time_instant__lp__excl__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_10161 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x342;
  if (kk_std_core_types__is_Lt(x_10161, _ctx)) {
    _brw_x342 = kk_integer_from_small(-1); /*int*/
    goto _match_x1260;
  }
  if (kk_std_core_types__is_Eq(x_10161, _ctx)) {
    _brw_x342 = kk_integer_from_small(0); /*int*/
    goto _match_x1260;
  }
  {
    _brw_x342 = kk_integer_from_small(1); /*int*/
  }
  _match_x1260: ;
  bool _brw_x343 = kk_integer_neq_borrow(_brw_x342,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x342, _ctx);
  return _brw_x343;
}

static inline bool kk_std_time_instant__lp__lt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_10163 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x340;
  if (kk_std_core_types__is_Lt(x_10163, _ctx)) {
    _brw_x340 = kk_integer_from_small(-1); /*int*/
    goto _match_x1261;
  }
  if (kk_std_core_types__is_Eq(x_10163, _ctx)) {
    _brw_x340 = kk_integer_from_small(0); /*int*/
    goto _match_x1261;
  }
  {
    _brw_x340 = kk_integer_from_small(1); /*int*/
  }
  _match_x1261: ;
  bool _brw_x341 = kk_integer_neq_borrow(_brw_x340,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x340, _ctx);
  return _brw_x341;
}

static inline bool kk_std_time_instant__lp__gt__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_10165 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x338;
  if (kk_std_core_types__is_Lt(x_10165, _ctx)) {
    _brw_x338 = kk_integer_from_small(-1); /*int*/
    goto _match_x1262;
  }
  if (kk_std_core_types__is_Eq(x_10165, _ctx)) {
    _brw_x338 = kk_integer_from_small(0); /*int*/
    goto _match_x1262;
  }
  {
    _brw_x338 = kk_integer_from_small(1); /*int*/
  }
  _match_x1262: ;
  bool _brw_x339 = kk_integer_eq_borrow(_brw_x338,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x338, _ctx);
  return _brw_x339;
}

static inline bool kk_std_time_instant__lp__gt__eq__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> bool */ 
  kk_std_core_types__order x_10167 = kk_std_time_instant_cmp(i, j, _ctx); /*order*/;
  kk_integer_t _brw_x336;
  if (kk_std_core_types__is_Lt(x_10167, _ctx)) {
    _brw_x336 = kk_integer_from_small(-1); /*int*/
    goto _match_x1263;
  }
  if (kk_std_core_types__is_Eq(x_10167, _ctx)) {
    _brw_x336 = kk_integer_from_small(0); /*int*/
    goto _match_x1263;
  }
  {
    _brw_x336 = kk_integer_from_small(1); /*int*/
  }
  _match_x1263: ;
  bool _brw_x337 = kk_integer_neq_borrow(_brw_x336,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x336, _ctx);
  return _brw_x337;
}

kk_std_time_instant__instant kk_std_time_instant_min(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_max(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx); /* (i : instant, j : instant) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_add_days(kk_std_time_instant__instant i, kk_integer_t days_0, kk_context_t* _ctx); /* (i : instant, days : int) -> instant */ 

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

kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_mjd(double mjd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (mjd : float64, ts : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_ddouble_fs_instant_at_jd(kk_std_num_ddouble__ddouble jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (jd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 

kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_jd(double jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (jd : float64, ts : timescale) -> instant */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx); /* (i : instant, tscale : timescale, tzdelta : ? std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 

kk_std_num_ddouble__ddouble kk_std_time_instant_jd(kk_std_time_instant__instant i, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (i : instant, ts : timescale) -> std/num/ddouble/ddouble */ 

void kk_std_time_instant__init(kk_context_t* _ctx);


void kk_std_time_instant__done(kk_context_t* _ctx);

#endif // header
