#pragma once
#ifndef kk_std_time_calendar_H
#define kk_std_time_calendar_H
// Koka generated module: std/time/calendar, koka version: 3.2.2, platform: 64-bit
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
#include "std_time_instant.h"
#include "std_time_utc.h"
#include "std_time_date.h"
#include "std_num_float64.h"
#include "std_num_int32.h"

// type declarations

// type std/time/calendar/timezone
struct kk_std_time_calendar__timezone_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_calendar__timezone;
struct kk_std_time_calendar_Timezone {
  struct kk_std_time_calendar__timezone_s _base;
  kk_string_t name;
  kk_function_t utc_delta;
  kk_function_t utc_inverse;
};
static inline kk_std_time_calendar__timezone kk_std_time_calendar__base_Timezone(struct kk_std_time_calendar_Timezone* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_calendar__timezone kk_std_time_calendar__new_Timezone(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_function_t utc_delta, kk_function_t utc_inverse, kk_context_t* _ctx) {
  struct kk_std_time_calendar_Timezone* _con = kk_block_alloc_at_as(struct kk_std_time_calendar_Timezone, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->utc_delta = utc_delta;
  _con->utc_inverse = utc_inverse;
  return kk_std_time_calendar__base_Timezone(_con, _ctx);
}
static inline struct kk_std_time_calendar_Timezone* kk_std_time_calendar__as_Timezone(kk_std_time_calendar__timezone x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_calendar_Timezone*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_calendar__is_Timezone(kk_std_time_calendar__timezone x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_calendar__timezone kk_std_time_calendar__timezone_dup(kk_std_time_calendar__timezone _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_calendar__timezone_drop(kk_std_time_calendar__timezone _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_calendar__timezone_box(kk_std_time_calendar__timezone _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_calendar__timezone kk_std_time_calendar__timezone_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type std/time/calendar/calendar
struct kk_std_time_calendar__calendar_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_calendar__calendar;
struct kk_std_time_calendar_Calendar {
  struct kk_std_time_calendar__calendar_s _base;
  kk_string_t name;
  kk_string_t long_name;
  kk_string_t month_prefix;
  kk_function_t show_era;
  kk_function_t instant_to_dc;
  kk_function_t dc_to_instant;
  kk_function_t days_to_date;
  kk_function_t date_to_days;
};
static inline kk_std_time_calendar__calendar kk_std_time_calendar__base_Calendar(struct kk_std_time_calendar_Calendar* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_calendar__calendar kk_std_time_calendar__new_Calendar(kk_reuse_t _at, int32_t _cpath, kk_string_t name, kk_string_t long_name, kk_string_t month_prefix, kk_function_t show_era, kk_function_t instant_to_dc, kk_function_t dc_to_instant, kk_function_t days_to_date, kk_function_t date_to_days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_Calendar* _con = kk_block_alloc_at_as(struct kk_std_time_calendar_Calendar, _at, 8 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->name = name;
  _con->long_name = long_name;
  _con->month_prefix = month_prefix;
  _con->show_era = show_era;
  _con->instant_to_dc = instant_to_dc;
  _con->dc_to_instant = dc_to_instant;
  _con->days_to_date = days_to_date;
  _con->date_to_days = date_to_days;
  return kk_std_time_calendar__base_Calendar(_con, _ctx);
}
static inline struct kk_std_time_calendar_Calendar* kk_std_time_calendar__as_Calendar(kk_std_time_calendar__calendar x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_calendar_Calendar*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_calendar__is_Calendar(kk_std_time_calendar__calendar x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_calendar__calendar kk_std_time_calendar__calendar_dup(kk_std_time_calendar__calendar _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_calendar__calendar_drop(kk_std_time_calendar__calendar _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_calendar__calendar_box(kk_std_time_calendar__calendar _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_calendar__calendar kk_std_time_calendar__calendar_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type std/time/calendar/local-timezone
struct kk_std_time_calendar__local_timezone_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_time_calendar__local_timezone;
static inline kk_std_time_calendar__local_timezone kk_std_time_calendar__local_timezone_dup(kk_std_time_calendar__local_timezone _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_std_time_calendar__local_timezone_drop(kk_std_time_calendar__local_timezone _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_time_calendar__local_timezone_box(kk_std_time_calendar__local_timezone _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_time_calendar__local_timezone kk_std_time_calendar__local_timezone_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `name` constructor field of the `:calendar` type.

static inline kk_string_t kk_std_time_calendar_calendar_fs_name(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> string */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x577 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_string_t _x = _con_x577->name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `long-name` constructor field of the `:calendar` type.

static inline kk_string_t kk_std_time_calendar_calendar_fs_long_name(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> string */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x578 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_string_t _x = _con_x578->long_name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `month-prefix` constructor field of the `:calendar` type.

static inline kk_string_t kk_std_time_calendar_calendar_fs_month_prefix(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> string */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x579 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_string_t _x = _con_x579->month_prefix;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `show-era` constructor field of the `:calendar` type.

static inline kk_function_t kk_std_time_calendar_calendar_fs_show_era(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> ((std/time/date/date) -> string) */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x580 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_function_t _x = _con_x580->show_era;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `instant-to-dc` constructor field of the `:calendar` type.

static inline kk_function_t kk_std_time_calendar_calendar_fs_instant_to_dc(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> ((i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)) */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x581 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_function_t _x = _con_x581->instant_to_dc;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `dc-to-instant` constructor field of the `:calendar` type.

static inline kk_function_t kk_std_time_calendar_calendar_fs_dc_to_instant(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> ((std/time/date/date, std/time/date/clock, timezone, std/time/instant/timescale) -> std/time/instant/instant) */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x582 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_function_t _x = _con_x582->dc_to_instant;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `days-to-date` constructor field of the `:calendar` type.

static inline kk_function_t kk_std_time_calendar_calendar_fs_days_to_date(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> ((days : int) -> std/time/date/date) */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x583 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_function_t _x = _con_x583->days_to_date;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `date-to-days` constructor field of the `:calendar` type.

static inline kk_function_t kk_std_time_calendar_calendar_fs_date_to_days(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx) { /* (calendar : calendar) -> ((date : std/time/date/date) -> int) */ 
  {
    struct kk_std_time_calendar_Calendar* _con_x584 = kk_std_time_calendar__as_Calendar(calendar, _ctx);
    kk_function_t _x = _con_x584->date_to_days;
    return kk_function_dup(_x, _ctx);
  }
}

kk_std_time_calendar__calendar kk_std_time_calendar_calendar_fs__copy(kk_std_time_calendar__calendar _this, kk_std_core_types__optional name, kk_std_core_types__optional long_name, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_std_core_types__optional instant_to_dc, kk_std_core_types__optional dc_to_instant, kk_std_core_types__optional days_to_date, kk_std_core_types__optional date_to_days, kk_context_t* _ctx); /* (calendar, name : ? string, long-name : ? string, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string), instant-to-dc : ? ((i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)), dc-to-instant : ? ((std/time/date/date, std/time/date/clock, timezone, std/time/instant/timescale) -> std/time/instant/instant), days-to-date : ? ((days : int) -> std/time/date/date), date-to-days : ? ((date : std/time/date/date) -> int)) -> calendar */ 
 
// Automatically generated. Retrieves the `name` constructor field of the `:timezone` type.

static inline kk_string_t kk_std_time_calendar_timezone_fs_name(kk_std_time_calendar__timezone timezone, kk_context_t* _ctx) { /* (timezone : timezone) -> string */ 
  {
    struct kk_std_time_calendar_Timezone* _con_x616 = kk_std_time_calendar__as_Timezone(timezone, _ctx);
    kk_string_t _x = _con_x616->name;
    return kk_string_dup(_x, _ctx);
  }
}

bool kk_std_time_calendar__lp__eq__eq__rp_(kk_std_time_calendar__calendar c1, kk_std_time_calendar__calendar c2, kk_context_t* _ctx); /* (c1 : calendar, c2 : calendar) -> bool */ 

bool kk_std_time_calendar_timezone_fs__lp__eq__eq__rp_(kk_std_time_calendar__timezone tz1, kk_std_time_calendar__timezone tz2, kk_context_t* _ctx); /* (tz1 : timezone, tz2 : timezone) -> bool */ 
 
// A `:timezone` determines a time offset with respect to the UTC / GMT timezone. For
// using general time zones, see the [`std/time/timezone`](std_time_timezone.html) module.
// The `tz-utc` and `tz-local` time zones are used for UTC/GMT time and the local system time.
// The `name` field contains the time zone name as IANA timezone identifier.
// The `utc-delta` field returns the time zone offset
// relative to UTC (for GMT-08:00 it returns a duration of `-8*3600` seconds) and the abbreviated
// time zone name (``PDT`` for example).
// The optional `utc-inverse` field returns for an instant in the time zone, the associated UTC time.
// By default it returns `Nothing` in which case a generic algorithm is used to determine the
// inverse.


// lift anonymous function
struct kk_std_time_calendar__create_Timezone_fun626__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x57;
};
extern kk_std_core_types__maybe kk_std_time_calendar__create_Timezone_fun626(kk_function_t _fself, kk_std_time_instant__instant _b_x60, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar__new_create_Timezone_fun626(kk_box_t _fun_unbox_x57, kk_context_t* _ctx) {
  struct kk_std_time_calendar__create_Timezone_fun626__t* _self = kk_function_alloc_as(struct kk_std_time_calendar__create_Timezone_fun626__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar__create_Timezone_fun626, kk_context());
  _self->_fun_unbox_x57 = _fun_unbox_x57;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_calendar__create_Timezone_fun629__t {
  struct kk_function_s _base;
};
extern kk_std_core_types__maybe kk_std_time_calendar__create_Timezone_fun629(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar__new_create_Timezone_fun629(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar__create_Timezone_fun629, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_std_time_calendar__timezone kk_std_time_calendar__create_Timezone(kk_string_t name, kk_function_t utc_delta, kk_std_core_types__optional utc_inverse, kk_context_t* _ctx) { /* (name : string, utc-delta : (std/time/instant/instant) -> (std/time/duration/duration, string), utc-inverse : ? ((std/time/instant/instant) -> maybe<std/time/instant/instant>)) -> timezone */ 
  kk_function_t _x_x625;
  if (kk_std_core_types__is_Optional(utc_inverse, _ctx)) {
    kk_box_t _fun_unbox_x57 = utc_inverse._cons._Optional.value;
    kk_box_dup(_fun_unbox_x57, _ctx);
    kk_std_core_types__optional_drop(utc_inverse, _ctx);
    _x_x625 = kk_std_time_calendar__new_create_Timezone_fun626(_fun_unbox_x57, _ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  else {
    kk_std_core_types__optional_drop(utc_inverse, _ctx);
    _x_x625 = kk_std_time_calendar__new_create_Timezone_fun629(_ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, name, utc_delta, _x_x625, _ctx);
}
 
// Automatically generated. Retrieves the `utc-delta` constructor field of the `:timezone` type.

static inline kk_function_t kk_std_time_calendar_timezone_fs_utc_delta(kk_std_time_calendar__timezone timezone, kk_context_t* _ctx) { /* (timezone : timezone) -> ((std/time/instant/instant) -> (std/time/duration/duration, string)) */ 
  {
    struct kk_std_time_calendar_Timezone* _con_x630 = kk_std_time_calendar__as_Timezone(timezone, _ctx);
    kk_function_t _x = _con_x630->utc_delta;
    return kk_function_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `utc-inverse` constructor field of the `:timezone` type.

static inline kk_function_t kk_std_time_calendar_timezone_fs_utc_inverse(kk_std_time_calendar__timezone timezone, kk_context_t* _ctx) { /* (timezone : timezone) -> ((std/time/instant/instant) -> maybe<std/time/instant/instant>) */ 
  {
    struct kk_std_time_calendar_Timezone* _con_x631 = kk_std_time_calendar__as_Timezone(timezone, _ctx);
    kk_function_t _x = _con_x631->utc_inverse;
    return kk_function_dup(_x, _ctx);
  }
}

kk_std_time_calendar__timezone kk_std_time_calendar_timezone_fs__copy(kk_std_time_calendar__timezone _this, kk_std_core_types__optional name, kk_std_core_types__optional utc_delta, kk_std_core_types__optional utc_inverse, kk_context_t* _ctx); /* (timezone, name : ? string, utc-delta : ? ((std/time/instant/instant) -> (std/time/duration/duration, string)), utc-inverse : ? ((std/time/instant/instant) -> maybe<std/time/instant/instant>)) -> timezone */ 

kk_std_time_calendar__timezone kk_std_time_calendar_string_fs_tz_fixed(kk_string_t name, kk_std_time_duration__duration delta, kk_std_core_types__optional abbrv, kk_context_t* _ctx); /* (name : string, delta : std/time/duration/duration, abbrv : ? string) -> timezone */ 

extern kk_std_time_calendar__timezone kk_std_time_calendar_tz_utc;

kk_std_time_calendar__timezone kk_std_time_calendar_tz_fixed(kk_integer_t hours, kk_std_core_types__optional mins, kk_std_core_types__optional name, kk_std_core_types__optional abbrv, kk_std_core_types__optional hourwidth, kk_context_t* _ctx); /* (hours : int, mins : ? int, name : ? string, abbrv : ? string, hourwidth : ? int) -> timezone */ 

bool kk_std_time_calendar_is_tz_utc(kk_std_time_calendar__timezone tz, kk_context_t* _ctx); /* (tz : timezone) -> bool */ 

kk_std_time_calendar__local_timezone kk_std_time_calendar_local_get_timezone(kk_context_t* _ctx); /* () -> ndet local-timezone */ 

kk_std_core_types__tuple2 kk_std_time_calendar_local_utc_delta(kk_std_time_calendar__local_timezone tz, double i, kk_context_t* _ctx); /* (tz : local-timezone, i : float64) -> (float64, string) */ 

kk_std_time_calendar__timezone kk_std_time_calendar_tz_local(kk_context_t* _ctx); /* () -> ndet timezone */ 

kk_std_core_types__tuple2 kk_std_time_calendar_earth_timestamp_to_dc(kk_std_time_timestamp__timestamp t, kk_std_num_ddouble__ddouble tzdelta, kk_function_t days_to_date, kk_context_t* _ctx); /* (t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan, days-to-date : (int) -> std/time/date/date) -> (std/time/date/date, std/time/date/clock) */ 

kk_std_time_timestamp__timestamp kk_std_time_calendar_dc_timestamp(kk_std_time_date__date d, kk_std_time_date__clock c, kk_function_t date_to_days, kk_std_core_types__optional has_leap_seconds, kk_context_t* _ctx); /* (d : std/time/date/date, c : std/time/date/clock, date-to-days : (std/time/date/date) -> int, has-leap-seconds : ? bool) -> std/time/timestamp/timestamp */ 

bool kk_std_time_calendar_iso_is_leap(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> bool */ 

static inline kk_integer_t kk_std_time_calendar_iso_adjust(bool is_before_march, kk_integer_t year, kk_context_t* _ctx) { /* (is-before-march : bool, year : int) -> int */ 
  if (is_before_march) {
    kk_integer_drop(year, _ctx);
    return kk_integer_from_small(0);
  }
  {
    bool _match_x491 = kk_std_time_calendar_iso_is_leap(year, _ctx); /*bool*/;
    if (_match_x491) {
      return kk_integer_from_small(1);
    }
    {
      return kk_integer_from_small(2);
    }
  }
}

kk_integer_t kk_std_time_calendar_iso_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx); /* (year : int, month : int) -> int */ 

kk_integer_t kk_std_time_calendar_iso_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx); /* (year : int, doy : int) -> int */ 

kk_integer_t kk_std_time_calendar_iso_days_before_year(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> int */ 

kk_std_core_types__tuple2 kk_std_time_calendar_iso_estimate_year(kk_integer_t days, kk_context_t* _ctx); /* (days : int) -> (int, maybe<int>) */ 

kk_std_time_instant__instant kk_std_time_calendar_earth_timestamp_to_instant(kk_std_time_timestamp__timestamp t, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts, kk_context_t* _ctx); /* (t : std/time/timestamp/timestamp, tz : timezone, ts : std/time/instant/timescale) -> std/time/instant/instant */ 

kk_std_time_calendar__calendar kk_std_time_calendar_earth_calendar(kk_string_t name, kk_string_t long_name, kk_function_t days_to_date, kk_function_t date_to_days, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx); /* (name : string, long-name : string, days-to-date : (days : int) -> std/time/date/date, date-to-days : (std/time/date/date) -> int, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 

kk_std_time_calendar__calendar kk_std_time_calendar_solar_calendar(kk_string_t name, kk_string_t long_name, kk_function_t days_before_year, kk_function_t days_to_yeardoy, kk_function_t days_before_month, kk_function_t days_to_month, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx); /* (name : string, long-name : string, days-before-year : (year : int) -> int, days-to-yeardoy : (days : int) -> (int, int), days-before-month : (year : int, month : int) -> int, days-to-month : (year : int, doy : int) -> int, epoch-shift : ? int, has-year-zero : ? bool, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 

kk_std_time_calendar__calendar kk_std_time_calendar_solar_ecalendar(kk_string_t name, kk_string_t long_name, kk_function_t days_before_year, kk_function_t estimate_year, kk_function_t days_before_month, kk_function_t days_to_month, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx); /* (name : string, long-name : string, days-before-year : (year : int) -> int, estimate-year : (days : int) -> (int, maybe<int>), days-before-month : (year : int, month : int) -> int, days-to-month : (year : int, doy : int) -> int, epoch-shift : ? int, has-year-zero : ? bool, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 

kk_std_time_calendar__calendar kk_std_time_calendar_iso_calendar(kk_std_time_instant__timescale ___wildcard_x422__23, kk_string_t name, kk_std_core_types__optional long_name, kk_context_t* _ctx); /* (std/time/instant/timescale, name : string, long-name : ? string) -> calendar */ 

extern kk_std_time_calendar__calendar kk_std_time_calendar_cal_iso;

kk_std_time_instant__instant kk_std_time_calendar_date_fs_instant(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, tz : ? timezone, cal : ? calendar) -> std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_calendar_timescale_fs_instant(kk_std_time_instant__timescale tscale, kk_integer_t year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (tscale : std/time/instant/timescale, year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? int, frac : ? float64, tz : ? timezone, cal : ? calendar) -> std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_calendar_utc_fs__mlift_instant_10252(kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_integer_t year, kk_std_time_instant__timescale _c_x10227, kk_context_t* _ctx); /* (cal : ? calendar, day : ? int, frac : ? float64, hours : ? int, minutes : ? int, month : ? int, seconds : ? int, tz : ? timezone, year : int, std/time/instant/timescale) -> std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_calendar_utc_fs_instant(kk_integer_t year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? int, frac : ? float64, tz : ? timezone, cal : ? calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_calendar_utcdate_fs__mlift_instant_10253(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10229, kk_context_t* _ctx); /* (c : ? std/time/date/clock, cal : ? calendar, d : std/time/date/date, tz : ? timezone, std/time/instant/timescale) -> std/time/instant/instant */ 

kk_std_time_instant__instant kk_std_time_calendar_utcdate_fs_instant(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx); /* (d : std/time/date/date, c : ? std/time/date/clock, tz : ? timezone, cal : ? calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 

kk_std_core_types__tuple4 kk_std_time_calendar_instant_dc(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx); /* (i : std/time/instant/instant, tz : ? timezone, cal : ? calendar) -> (std/time/date/date, std/time/date/clock, std/time/duration/duration, string) */ 

kk_std_time_date__weekday kk_std_time_calendar_weekday(kk_std_time_date__date d, kk_std_time_calendar__calendar cal, kk_context_t* _ctx); /* (d : std/time/date/date, cal : calendar) -> std/time/date/weekday */ 

kk_integer_t kk_std_time_calendar_days_until(kk_std_time_calendar__calendar cal, kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx); /* (cal : calendar, d1 : std/time/date/date, d2 : std/time/date/date) -> int */ 

kk_std_time_timestamp__timestamp kk_std_time_calendar_cal_timestamp(kk_std_time_calendar__calendar cal, kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_time_date__clock c, kk_context_t* _ctx); /* (cal : calendar, ts : std/time/instant/timescale, d : std/time/date/date, c : std/time/date/clock) -> std/time/timestamp/timestamp */ 

kk_std_time_calendar__calendar kk_std_time_calendar_combine_earth_calendars(kk_string_t name, kk_string_t long_name, kk_std_time_date__date switch_date, kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_core_types__optional mb_show_era, kk_context_t* _ctx); /* (name : string, long-name : string, switch-date : std/time/date/date, cal1 : calendar, cal2 : calendar, mb-show-era : ? (maybe<(std/time/date/date) -> string>)) -> calendar */ 

kk_std_time_calendar__calendar kk_std_time_calendar_year_shift_earth_calendar(kk_string_t name, kk_string_t long_name, kk_integer_t year_shift, kk_std_time_calendar__calendar cal, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx); /* (name : string, long-name : string, year-shift : int, cal : calendar, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
 
// Create a standard [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) calendar
// using UTC time (`ts-utc-create`) given a provide leap second table (`:leaps-table`).
// This is a proleptic Gregorian
// calendar except that it uses the year 0 for 1 BCE, -1 for 2 BCE etc.
//
// You can create an ISO 8601 UTC calendar using the latest IERS leap
// second data using [`cal-utc-load`](std_time_download.html#cal_utc_load).


// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1086__t {
  struct kk_function_s _base;
};
extern kk_integer_t kk_std_time_calendar_cal_utc_create_fun1086(kk_function_t _fself, kk_integer_t _x1_x1085, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1086(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1086, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1088__t {
  struct kk_function_s _base;
};
extern kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_create_fun1088(kk_function_t _fself, kk_integer_t _x1_x1087, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1088(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1088, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1091__t {
  struct kk_function_s _base;
};
extern kk_integer_t kk_std_time_calendar_cal_utc_create_fun1091(kk_function_t _fself, kk_integer_t _x1_x1089, kk_integer_t _x2_x1090, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1091(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1091, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1094__t {
  struct kk_function_s _base;
};
extern kk_integer_t kk_std_time_calendar_cal_utc_create_fun1094(kk_function_t _fself, kk_integer_t _x1_x1092, kk_integer_t _x2_x1093, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1094(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1094, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_std_time_calendar__calendar kk_std_time_calendar_cal_utc_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : std/time/utc/leaps-table) -> calendar */ 
  kk_std_time_instant__timescale ts_utc;
  kk_string_t _x_x1079;
  kk_define_string_literal(, _s_x1080, 3, "UTC", _ctx)
  _x_x1079 = kk_string_dup(_s_x1080, _ctx); /*string*/
  ts_utc = kk_std_time_utc_utc_timescale(_x_x1079, leaps, _ctx); /*std/time/instant/timescale*/
  kk_datatype_ptr_dropn(ts_utc, (KK_I32(10)), _ctx);
  kk_string_t _x_x1081 = kk_string_empty(); /*string*/
  kk_string_t _x_x1083;
  kk_define_string_literal(, _s_x1084, 3, "ISO", _ctx)
  _x_x1083 = kk_string_dup(_s_x1084, _ctx); /*string*/
  return kk_std_time_calendar_solar_ecalendar(_x_x1081, _x_x1083, kk_std_time_calendar_new_cal_utc_create_fun1086(_ctx), kk_std_time_calendar_new_cal_utc_create_fun1088(_ctx), kk_std_time_calendar_new_cal_utc_create_fun1091(_ctx), kk_std_time_calendar_new_cal_utc_create_fun1094(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}

extern kk_std_time_calendar__calendar kk_std_time_calendar_cal_iso_sls;
 
// Create a new ISO 8601 calendar based on UTC-SLS time, i.e. UTC with smoothed leap
// seconds.


// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1114__t {
  struct kk_function_s _base;
};
extern kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1114(kk_function_t _fself, kk_integer_t _x1_x1113, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1114(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1114, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1116__t {
  struct kk_function_s _base;
};
extern kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_sls_create_fun1116(kk_function_t _fself, kk_integer_t _x1_x1115, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1116(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1116, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1119__t {
  struct kk_function_s _base;
};
extern kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1119(kk_function_t _fself, kk_integer_t _x1_x1117, kk_integer_t _x2_x1118, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1119(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1119, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1122__t {
  struct kk_function_s _base;
};
extern kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1122(kk_function_t _fself, kk_integer_t _x1_x1120, kk_integer_t _x2_x1121, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1122(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1122, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_std_time_calendar__calendar kk_std_time_calendar_cal_utc_sls_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : std/time/utc/leaps-table) -> calendar */ 
  kk_std_time_instant__timescale ts_utc_sls = kk_std_time_utc_ts_utc_sls_create(leaps, _ctx); /*std/time/instant/timescale*/;
  kk_datatype_ptr_dropn(ts_utc_sls, (KK_I32(10)), _ctx);
  kk_string_t _x_x1109;
  kk_define_string_literal(, _s_x1110, 3, "SLS", _ctx)
  _x_x1109 = kk_string_dup(_s_x1110, _ctx); /*string*/
  kk_string_t _x_x1111;
  kk_define_string_literal(, _s_x1112, 7, "ISO-SLS", _ctx)
  _x_x1111 = kk_string_dup(_s_x1112, _ctx); /*string*/
  return kk_std_time_calendar_solar_ecalendar(_x_x1109, _x_x1111, kk_std_time_calendar_new_cal_utc_sls_create_fun1114(_ctx), kk_std_time_calendar_new_cal_utc_sls_create_fun1116(_ctx), kk_std_time_calendar_new_cal_utc_sls_create_fun1119(_ctx), kk_std_time_calendar_new_cal_utc_sls_create_fun1122(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}

extern kk_std_time_calendar__calendar kk_std_time_calendar_cal_gregorian;

void kk_std_time_calendar__init(kk_context_t* _ctx);


void kk_std_time_calendar__done(kk_context_t* _ctx);

#endif // header
