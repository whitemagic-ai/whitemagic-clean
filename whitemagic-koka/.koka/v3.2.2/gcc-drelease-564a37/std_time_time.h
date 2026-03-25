#pragma once
#ifndef kk_std_time_time_H
#define kk_std_time_time_H
// Koka generated module: std/time/time, koka version: 3.2.2, platform: 64-bit
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
#include "std_time_timestamp.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_utc.h"
#include "std_time_date.h"
#include "std_time_calendar.h"
#include "std_time_chrono.h"

// type declarations

// type std/time/time/time
struct kk_std_time_time__time_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_time__time;
struct kk_std_time_time_Time {
  struct kk_std_time_time__time_s _base;
  kk_std_time_date__date date;
  kk_std_time_date__clock clock;
  kk_std_time_calendar__calendar calendar;
  kk_string_t tzabbrv;
  kk_std_time_calendar__timezone timezone;
  kk_std_time_instant__instant instant;
  kk_std_time_duration__duration tzdelta;
};
static inline kk_std_time_time__time kk_std_time_time__base_Time(struct kk_std_time_time_Time* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_time__time kk_std_time_time__new_Time(kk_reuse_t _at, int32_t _cpath, kk_std_time_date__date date, kk_std_time_date__clock clock, kk_std_time_calendar__calendar calendar, kk_std_time_duration__duration tzdelta, kk_string_t tzabbrv, kk_std_time_calendar__timezone timezone, kk_std_time_instant__instant instant, kk_context_t* _ctx) {
  struct kk_std_time_time_Time* _con = kk_block_alloc_at_as(struct kk_std_time_time_Time, _at, 9 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->date = date;
  _con->clock = clock;
  _con->calendar = calendar;
  _con->tzabbrv = tzabbrv;
  _con->timezone = timezone;
  _con->instant = instant;
  _con->tzdelta = tzdelta;
  return kk_std_time_time__base_Time(_con, _ctx);
}
static inline struct kk_std_time_time_Time* kk_std_time_time__as_Time(kk_std_time_time__time x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_time_Time*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_time__is_Time(kk_std_time_time__time x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_time__time kk_std_time_time__time_dup(kk_std_time_time__time _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_time__time_drop(kk_std_time_time__time _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_time__time_box(kk_std_time_time__time _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_time__time kk_std_time_time__time_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Represents an instant in time for a certain calendar and timezone.

static inline kk_std_time_time__time kk_std_time_time__create_Time(kk_std_time_date__date date, kk_std_time_date__clock clock, kk_std_time_calendar__calendar calendar, kk_std_core_types__optional tzdelta, kk_std_core_types__optional tzabbrv, kk_std_core_types__optional timezone, kk_std_time_instant__instant instant, kk_context_t* _ctx) { /* (date : std/time/date/date, clock : std/time/date/clock, calendar : std/time/calendar/calendar, tzdelta : ? std/time/duration/duration, tzabbrv : ? string, timezone : ? std/time/calendar/timezone, instant : std/time/instant/instant) -> time */ 
  kk_std_time_duration__duration _x_x2033;
  if (kk_std_core_types__is_Optional(tzdelta, _ctx)) {
    kk_box_t _box_x0 = tzdelta._cons._Optional.value;
    kk_std_time_duration__duration _uniq_tzdelta_200 = kk_std_time_duration__duration_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(tzdelta, _ctx);
    _x_x2033 = _uniq_tzdelta_200; /*std/time/duration/duration*/
  }
  else {
    kk_std_core_types__optional_drop(tzdelta, _ctx);
    _x_x2033 = kk_std_time_duration_zero; /*std/time/duration/duration*/
  }
  kk_string_t _x_x2034;
  if (kk_std_core_types__is_Optional(tzabbrv, _ctx)) {
    kk_box_t _box_x1 = tzabbrv._cons._Optional.value;
    kk_string_t _uniq_tzabbrv_204 = kk_string_unbox(_box_x1);
    kk_string_dup(_uniq_tzabbrv_204, _ctx);
    kk_std_core_types__optional_drop(tzabbrv, _ctx);
    _x_x2034 = _uniq_tzabbrv_204; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(tzabbrv, _ctx);
    _x_x2034 = kk_string_empty(); /*string*/
  }
  kk_std_time_calendar__timezone _x_x2036;
  if (kk_std_core_types__is_Optional(timezone, _ctx)) {
    kk_box_t _box_x2 = timezone._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_timezone_208 = kk_std_time_calendar__timezone_unbox(_box_x2, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_timezone_208, _ctx);
    kk_std_core_types__optional_drop(timezone, _ctx);
    _x_x2036 = _uniq_timezone_208; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(timezone, _ctx);
    _x_x2036 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  return kk_std_time_time__new_Time(kk_reuse_null, 0, date, clock, calendar, _x_x2033, _x_x2034, _x_x2036, instant, _ctx);
}
 
// Automatically generated. Retrieves the `date` constructor field of the `:time` type.

static inline kk_std_time_date__date kk_std_time_time_time_fs_date(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> std/time/date/date */ 
  {
    struct kk_std_time_time_Time* _con_x2037 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _x = _con_x2037->date;
    kk_std_time_date__clock _pat_3 = _con_x2037->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2037->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2037->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2037->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2037->instant;
    struct kk_std_time_date_Clock* _con_x2038 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2039 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2040 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    return kk_std_time_date__date_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `clock` constructor field of the `:time` type.

static inline kk_std_time_date__clock kk_std_time_time_time_fs_clock(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> std/time/date/clock */ 
  {
    struct kk_std_time_time_Time* _con_x2041 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2041->date;
    kk_std_time_date__clock _x = _con_x2041->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2041->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2041->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2041->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2041->instant;
    struct kk_std_time_date_Clock* _con_x2042 = kk_std_time_date__as_Clock(_x, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2043 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2044 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    return kk_std_time_date__clock_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `calendar` constructor field of the `:time` type.

static inline kk_std_time_calendar__calendar kk_std_time_time_time_fs_calendar(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> std/time/calendar/calendar */ 
  {
    struct kk_std_time_time_Time* _con_x2045 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2045->date;
    kk_std_time_date__clock _pat_4 = _con_x2045->clock;
    kk_std_time_calendar__calendar _x = _con_x2045->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2045->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2045->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2045->instant;
    struct kk_std_time_date_Clock* _con_x2046 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2047 = kk_std_time_calendar__as_Calendar(_x, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2048 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    return kk_std_time_calendar__calendar_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `tzdelta` constructor field of the `:time` type.

static inline kk_std_time_duration__duration kk_std_time_time_time_fs_tzdelta(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> std/time/duration/duration */ 
  {
    struct kk_std_time_time_Time* _con_x2049 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2049->date;
    kk_std_time_date__clock _pat_4 = _con_x2049->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2049->calendar;
    kk_std_time_duration__duration _x = _con_x2049->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2049->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2049->instant;
    struct kk_std_time_date_Clock* _con_x2050 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2051 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2052 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    return _x;
  }
}
 
// Automatically generated. Retrieves the `tzabbrv` constructor field of the `:time` type.

static inline kk_string_t kk_std_time_time_time_fs_tzabbrv(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> string */ 
  {
    struct kk_std_time_time_Time* _con_x2053 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2053->date;
    kk_std_time_date__clock _pat_4 = _con_x2053->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2053->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2053->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2053->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2053->instant;
    struct kk_std_time_date_Clock* _con_x2054 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2055 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2056 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _x = _con_x2053->tzabbrv;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `timezone` constructor field of the `:time` type.

static inline kk_std_time_calendar__timezone kk_std_time_time_time_fs_timezone(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> std/time/calendar/timezone */ 
  {
    struct kk_std_time_time_Time* _con_x2057 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2057->date;
    kk_std_time_date__clock _pat_4 = _con_x2057->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2057->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2057->tzdelta;
    kk_std_time_calendar__timezone _x = _con_x2057->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2057->instant;
    struct kk_std_time_date_Clock* _con_x2058 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2059 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2060 = kk_std_time_calendar__as_Timezone(_x, _ctx);
    return kk_std_time_calendar__timezone_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `instant` constructor field of the `:time` type.

static inline kk_std_time_instant__instant kk_std_time_time_time_fs_instant(kk_std_time_time__time time_0, kk_context_t* _ctx) { /* (time : time) -> std/time/instant/instant */ 
  {
    struct kk_std_time_time_Time* _con_x2061 = kk_std_time_time__as_Time(time_0, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2061->date;
    kk_std_time_date__clock _pat_4 = _con_x2061->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2061->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2061->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x2061->timezone;
    kk_std_time_instant__instant _x = _con_x2061->instant;
    struct kk_std_time_date_Clock* _con_x2062 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2063 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2064 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    return kk_std_time_instant__instant_dup(_x, _ctx);
  }
}

kk_std_time_time__time kk_std_time_time_time_fs__copy(kk_std_time_time__time _this, kk_std_core_types__optional date, kk_std_core_types__optional clock, kk_std_core_types__optional calendar, kk_std_core_types__optional tzdelta, kk_std_core_types__optional tzabbrv, kk_std_core_types__optional timezone, kk_std_core_types__optional instant, kk_context_t* _ctx); /* (time, date : ? std/time/date/date, clock : ? std/time/date/clock, calendar : ? std/time/calendar/calendar, tzdelta : ? std/time/duration/duration, tzabbrv : ? string, timezone : ? std/time/calendar/timezone, instant : ? std/time/instant/instant) -> time */ 

kk_std_time_instant__timescale kk_std_time_time_timescale(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> std/time/instant/timescale */ 

kk_integer_t kk_std_time_time_year(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_integer_t kk_std_time_time_month(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_integer_t kk_std_time_time_day(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_integer_t kk_std_time_time_hours(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_integer_t kk_std_time_time_minutes(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_std_num_ddouble__ddouble kk_std_time_time_seconds(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> std/time/timestamp/timespan */ 

kk_std_core_types__order kk_std_time_time_cmp(kk_std_time_time__time t1, kk_std_time_time__time t2, kk_context_t* _ctx); /* (t1 : time, t2 : time) -> order */ 

bool kk_std_time_time__lp__eq__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> bool */ 

bool kk_std_time_time__lp__lt__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> bool */ 

bool kk_std_time_time__lp__excl__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> bool */ 

bool kk_std_time_time__lp__lt__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> bool */ 

bool kk_std_time_time__lp__gt__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> bool */ 

bool kk_std_time_time__lp__gt__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> bool */ 

kk_std_time_time__time kk_std_time_time_min(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> time */ 

kk_std_time_time__time kk_std_time_time_max(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx); /* (i : time, j : time) -> time */ 

bool kk_std_time_time_is_numeric(kk_string_t abbrv, kk_context_t* _ctx); /* (abbrv : string) -> bool */ 

kk_std_time_time__time kk_std_time_time_instant_fs_time(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_timescale_fs_time(kk_std_time_instant__timescale tscale, kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (tscale : std/time/instant/timescale, year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> time */ 

kk_std_time_time__time kk_std_time_time__mlift_time_10711(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_std_core_types__optional tz, kk_integer_t year_0, kk_std_time_instant__timescale _c_x10616, kk_context_t* _ctx); /* (cal : ? std/time/calendar/calendar, day@0 : ? int, frac : ? float64, hours@0 : ? int, minutes@0 : ? int, month@0 : ? int, secs : ? int, tz : ? std/time/calendar/timezone, year@0 : int, std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_time(kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_timescale_fs_date_fs_time(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> time */ 

kk_std_time_time__time kk_std_time_time_date_fs__mlift_time_10712(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10618, kk_context_t* _ctx); /* (c : ? std/time/date/clock, cal : ? std/time/calendar/calendar, d : std/time/date/date, tz : ? std/time/calendar/timezone, std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_date_fs_time(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (d : std/time/date/date, c : ? std/time/date/clock, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_time_fs_time(kk_std_time_time__time t, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (t : time, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_round_to_prec(kk_std_time_time__time t, kk_integer_t prec, kk_context_t* _ctx); /* (t : time, prec : int) -> time */ 

kk_string_t kk_std_time_time_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx); /* (i : int, width : ? int) -> string */ 

kk_string_t kk_std_time_time_show_tzdelta(kk_std_time_duration__duration delta, kk_std_core_types__optional utc, kk_std_core_types__optional hmsep, kk_std_core_types__optional hrwidth, kk_context_t* _ctx); /* (delta : std/time/duration/duration, utc : ? string, hmsep : ? string, hrwidth : ? int) -> string */ 

kk_string_t kk_std_time_time_show_raw(kk_std_time_time__time tp, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (tp : time, prec : ? int) -> string */ 

kk_string_t kk_std_time_time_show(kk_std_time_time__time t, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (t : time, prec : ? int) -> string */ 

static inline kk_string_t kk_std_time_time_show_date(kk_std_time_date__date d, kk_context_t* _ctx) { /* (d : std/time/date/date) -> string */ 
  return kk_std_time_date_show(d, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_std_time_time__time kk_std_time_time__mlift_time_utc_10713(kk_std_core_types__optional cal, kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_time_instant__timescale _y_x10619, kk_context_t* _ctx); /* (cal : ? std/time/calendar/calendar, i : std/time/instant/instant, tz : ? std/time/calendar/timezone, std/time/instant/timescale) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_time_utc(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_time_tai(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_time_gps(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_time_tt(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_time_ti(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 

kk_std_time_time__time kk_std_time_time_duration_fs__lp__plus__rp_(kk_std_time_time__time t, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (t : time, d : std/time/duration/duration) -> time */ 

kk_std_time_time__time kk_std_time_time_add_date(kk_std_time_time__time t, kk_std_time_date__date d, kk_std_core_types__optional c, kk_context_t* _ctx); /* (t : time, d : std/time/date/date, c : ? std/time/date/clock) -> time */ 

kk_std_time_time__time kk_std_time_time_add_clock(kk_std_time_time__time t, kk_std_time_date__clock c, kk_context_t* _ctx); /* (t : time, c : std/time/date/clock) -> time */ 

kk_std_time_time__time kk_std_time_time_add_days(kk_std_time_time__time t, kk_integer_t days, kk_std_core_types__optional c, kk_context_t* _ctx); /* (t : time, days : int, c : ? std/time/date/clock) -> time */ 

kk_std_time_time__time kk_std_time_time_add_weeks(kk_std_time_time__time t, kk_integer_t weeks, kk_context_t* _ctx); /* (t : time, weeks : int) -> time */ 

kk_std_time_time__time kk_std_time_time_add_months(kk_std_time_time__time t, kk_integer_t months, kk_context_t* _ctx); /* (t : time, months : int) -> time */ 

kk_std_time_time__time kk_std_time_time_add_years(kk_std_time_time__time t, kk_integer_t years, kk_context_t* _ctx); /* (t : time, years : int) -> time */ 

kk_std_time_time__time kk_std_time_time_duration_fs__lp__dash__rp_(kk_std_time_time__time t, kk_std_time_duration__duration d, kk_context_t* _ctx); /* (t : time, d : std/time/duration/duration) -> time */ 

kk_std_time_duration__duration kk_std_time_time__lp__dash__rp_(kk_std_time_time__time t1, kk_std_time_time__time t2, kk_context_t* _ctx); /* (t1 : time, t2 : time) -> std/time/duration/duration */ 

kk_std_time_time__time kk_std_time_time_copy(kk_std_time_time__time t, kk_std_core_types__optional year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional seconds_0, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (t : time, year : ? int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? std/num/ddouble/ddouble, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_copy_dc(kk_std_time_time__time t, kk_std_core_types__optional d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (t : time, d : ? std/time/date/date, c : ? std/time/date/clock, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_start_of_day(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> time */ 

kk_std_time_time__time kk_std_time_time_start_of_month(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> time */ 

kk_integer_t kk_std_time_time_days_until(kk_std_time_time__time t1, kk_std_time_time__time t2, kk_context_t* _ctx); /* (t1 : time, t2 : time) -> int */ 

kk_integer_t kk_std_time_time_day_of_year(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_integer_t kk_std_time_time_days_in_month(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_integer_t kk_std_time_time_days_in_year(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_std_num_ddouble__ddouble kk_std_time_time_mjd(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> std/num/ddouble/ddouble */ 

kk_std_time_date__weekday kk_std_time_time_weekday(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> std/time/date/weekday */ 

kk_std_time_time__time kk_std_time_time_start_of_week(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> time */ 

kk_std_time_time__time kk_std_time_time_start_of_year(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> time */ 

kk_std_num_ddouble__ddouble kk_std_time_time_year_frac(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> std/num/ddouble/ddouble */ 

kk_integer_t kk_std_time_time_months_in_year(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> int */ 

kk_std_time_time__time kk_std_time_time_nth_weekday(kk_std_time_time__time t, kk_integer_t n, kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (t : time, n : int, wd : std/time/date/weekday) -> time */ 

kk_std_time_time__time kk_std_time_time_first_weekday(kk_std_time_time__time t, kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (t : time, wd : std/time/date/weekday) -> time */ 

kk_std_time_time__time kk_std_time_time_last_weekday(kk_std_time_time__time t, kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (t : time, wd : std/time/date/weekday) -> time */ 

kk_std_time_time__time kk_std_time_time_nth_weekday_of_month(kk_std_time_time__time t, kk_integer_t n, kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (t : time, n : int, wd : std/time/date/weekday) -> time */ 

kk_std_time_time__time kk_std_time_time_first_weekday_of_month(kk_std_time_time__time t, kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (t : time, wd : std/time/date/weekday) -> time */ 

kk_std_time_time__time kk_std_time_time_last_weekday_of_month(kk_std_time_time__time t, kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (t : time, wd : std/time/date/weekday) -> time */ 

extern kk_std_num_ddouble__ddouble kk_std_time_time_mjd_epoch_delta;

extern kk_std_num_ddouble__ddouble kk_std_time_time_jd_epoch_delta;

kk_std_num_ddouble__ddouble kk_std_time_time_jd(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : time) -> std/num/ddouble/ddouble */ 

kk_std_time_time__time kk_std_time_time_timescale_fs_time_now(kk_std_time_instant__timescale ts, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (ts : std/time/instant/timescale, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> ndet time */ 

kk_std_time_time__time kk_std_time_time_timezone_fs__mlift_time_now_10714(kk_std_core_types__optional cal, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10621, kk_context_t* _ctx); /* (cal : ? std/time/calendar/calendar, tz : ? std/time/calendar/timezone, std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_timezone_fs_time_now(kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> <ndet,std/time/utc/utc> time */ 

kk_std_time_time__time kk_std_time_time_timescale_fs_local_time_now(kk_std_time_instant__timescale ts, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (ts : std/time/instant/timescale, cal : ? std/time/calendar/calendar) -> ndet time */ 

kk_std_time_time__time kk_std_time_time_calendar_fs_local_time_now(kk_std_core_types__optional cal, kk_context_t* _ctx); /* (cal : ? std/time/calendar/calendar) -> <ndet,std/time/utc/utc> time */ 

kk_std_time_time__time kk_std_time_time_local_time(kk_std_time_time__time t, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (t : time, cal : ? std/time/calendar/calendar) -> ndet time */ 

kk_std_time_time__time kk_std_time_time_instant_fs_local_time(kk_std_time_instant__instant i, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, cal : ? std/time/calendar/calendar) -> ndet time */ 

kk_std_time_time__time kk_std_time_time_timescale_fs_local_time(kk_std_time_instant__timescale ts, kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (ts : std/time/instant/timescale, year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, cal : ? std/time/calendar/calendar) -> ndet time */ 

kk_std_time_time__time kk_std_time_time_date_fs_local_time(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, cal : ? std/time/calendar/calendar) -> ndet time */ 

kk_std_time_time__time kk_std_time_time_dateutc_fs__mlift_local_time_10715(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_time_instant__timescale _c_x10624, kk_context_t* _ctx); /* (c : ? std/time/date/clock, cal : ? std/time/calendar/calendar, d : std/time/date/date, std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_dateutc_fs_local_time(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (d : std/time/date/date, c : ? std/time/date/clock, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> <ndet,std/time/utc/utc> time */ 

kk_std_time_time__time kk_std_time_time_year_fs__mlift_local_time_10716(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_integer_t year_0, kk_std_time_instant__timescale _c_x10626, kk_context_t* _ctx); /* (cal : ? std/time/calendar/calendar, day@0 : ? int, frac : ? float64, hours@0 : ? int, minutes@0 : ? int, month@0 : ? int, secs : ? int, year@0 : int, std/time/instant/timescale) -> time */ 

kk_std_time_time__time kk_std_time_time_year_fs_local_time(kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> <ndet,std/time/utc/utc> time */ 

void kk_std_time_time__init(kk_context_t* _ctx);


void kk_std_time_time__done(kk_context_t* _ctx);

#endif // header
