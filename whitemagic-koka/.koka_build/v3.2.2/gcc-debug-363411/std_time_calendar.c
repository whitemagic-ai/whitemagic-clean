// Koka generated module: std/time/calendar, koka version: 3.2.2, platform: 64-bit
#include "std_time_calendar.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------
  Local time zone UTC delta
--------------------------------------------------------------------------------------------------*/

#if !defined(__STDC_WANT_LIB_EXT1__)
#define __STDC_WANT_LIB_EXT1__    // for gmtime_s
#endif
#if defined(__GLIBC__) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE               // for tm_zone and tm_gmtoff
#endif
#include <time.h>

static long kk_local_utc_delta(double unix_secs, kk_string_t* ptzname, kk_context_t* ctx) {
  // get the UTC delta in a somewhat portable way...
  bool isdst = false;
  time_t t = (time_t)unix_secs;
  #if (_WIN32 && KK_INTPTR_SIZE==8)
  if (t < 0) { t += 3155673600; } // try to avoid errors for negative times on some platforms by adding 100 years..
  #endif
  time_t loct = t;
  #if defined(_GNU_SOURCE)
    // GNU libc has the tm_zone and tm_gmtoff fields
    struct tm loctm;
    if (localtime_r(&t, &loctm) != NULL) {
      isdst = (loctm.tm_isdst != 0);
      loct  = t - loctm.tm_gmtoff + (isdst ? 3600 : 0);
    }
    else {
      loctm.tm_zone = "";
    }
  #elif defined(_WIN32) && !defined(__MINGW32__)
    struct tm gmtm;
    if (gmtime_s(&gmtm, &t) == 0) {      // switched parameters :-(
      loct = mktime(&gmtm);              // interpret gmt as local time
      struct tm loctm;
      localtime_s(&loctm, &t);           // switched parameters :-(
      isdst = (loctm.tm_isdst != 0);
    }
  #elif defined(__STDC_LIB_EXT1__)
    struct tm gmtm;
    if (gmtime_s(&t, &gmtm) != NULL) {
      loct = mktime(&gmtm);              // interpret gmt as local time
      struct tm loctm;
      localtime_s(&t, &loctm);
      isdst = (loctm.tm_isdst != 0);
    }
  #else
    struct tm* pgmtm = gmtime(&t);
    if (pgmtm != NULL) {
      loct = mktime(pgmtm);                // interpret gmt as local time
      struct tm* ploctm = localtime(&t);
      isdst = (ploctm->tm_isdst != 0);
    }
  #endif
  const time_t utc_delta = t - loct + (isdst ? 3600 : 0);   // the difference is the utc offset at that time
  if (ptzname != NULL) {
    // getting the timezone name
    #if defined(_WIN32) && !defined(__MINGW32__)
      char tzonename[256];
      size_t tznamelen;
      _get_tzname(&tznamelen, tzonename, 255, isdst ? 1 : 0); tzonename[255] = 0;
      *ptzname = kk_string_alloc_from_qutf8(tzonename, ctx);
    #elif defined(_GNU_SOURCE)
      *ptzname = kk_string_alloc_from_qutf8(loctm.tm_zone, ctx);
    #elif (_POSIX_C_SOURCE >= 1) || _XOPEN_SOURCE || _POSIX_SOURCE || __MINGW32__ // tzname
      *ptzname = kk_string_alloc_from_qutf8(tzname[isdst ? 1 : 0], ctx);
    #else
      // give up :-(
      * ptzname = kk_string_empty();
    #endif
  }
  return (long)utc_delta;
}


static kk_std_time_calendar__local_timezone kk_local_get_timezone(kk_context_t* ctx) {
  return kk_datatype_from_tag((kk_tag_t)1); // dummy value; we cannot store the local timezone as it is a global :-(
}

static kk_std_core_types__tuple2 kk_local_get_utc_delta_tuple(kk_std_time_calendar__local_timezone tz, double unix_secs, kk_context_t* ctx) {
  kk_string_t tzonename;
  long utc_delta = kk_local_utc_delta(unix_secs, &tzonename, ctx);
  return kk_std_core_types__new_Tuple2( kk_double_box((double)utc_delta,ctx), kk_string_box(tzonename), ctx );
}



// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun592__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x6;
};
static kk_string_t kk_std_time_calendar_calendar_fs__copy_fun592(kk_function_t _fself, kk_std_time_date__date _b_x9, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun592(kk_box_t _fun_unbox_x6, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun592__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun592__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun592, kk_context());
  _self->_fun_unbox_x6 = _fun_unbox_x6;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_calendar_fs__copy_fun592(kk_function_t _fself, kk_std_time_date__date _b_x9, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun592__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun592__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x6 = _self->_fun_unbox_x6; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x6, _ctx);}, {}, _ctx)
  kk_box_t _x_x593;
  kk_function_t _x_x594 = kk_function_unbox(_fun_unbox_x6, _ctx); /*(7) -> 8*/
  _x_x593 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x594, (_x_x594, kk_std_time_date__date_box(_b_x9, _ctx), _ctx), _ctx); /*8*/
  return kk_string_unbox(_x_x593);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun597__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x15;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_calendar_fs__copy_fun597(kk_function_t _fself, kk_std_time_instant__instant _b_x19, kk_std_time_duration__duration _b_x20, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun597(kk_box_t _fun_unbox_x15, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun597__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun597__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun597, kk_context());
  _self->_fun_unbox_x15 = _fun_unbox_x15;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_calendar_fs__copy_fun597(kk_function_t _fself, kk_std_time_instant__instant _b_x19, kk_std_time_duration__duration _b_x20, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun597__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun597__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x15 = _self->_fun_unbox_x15; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x15, _ctx);}, {}, _ctx)
  kk_box_t _x_x598;
  kk_function_t _x_x599 = kk_function_unbox(_fun_unbox_x15, _ctx); /*(i : 16, tzdelta : 17) -> 18*/
  _x_x598 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x599, (_x_x599, kk_std_time_instant__instant_box(_b_x19, _ctx), kk_std_time_duration__duration_box(_b_x20, _ctx), _ctx), _ctx); /*18*/
  return kk_std_core_types__tuple2_unbox(_x_x598, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun602__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x30;
};
static kk_std_time_instant__instant kk_std_time_calendar_calendar_fs__copy_fun602(kk_function_t _fself, kk_std_time_date__date _b_x36, kk_std_time_date__clock _b_x37, kk_std_time_calendar__timezone _b_x38, kk_std_time_instant__timescale _b_x39, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun602(kk_box_t _fun_unbox_x30, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun602__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun602__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun602, kk_context());
  _self->_fun_unbox_x30 = _fun_unbox_x30;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_calendar_fs__copy_fun602(kk_function_t _fself, kk_std_time_date__date _b_x36, kk_std_time_date__clock _b_x37, kk_std_time_calendar__timezone _b_x38, kk_std_time_instant__timescale _b_x39, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun602__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun602__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x30 = _self->_fun_unbox_x30; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x30, _ctx);}, {}, _ctx)
  kk_box_t _x_x603;
  kk_function_t _x_x604 = kk_function_unbox(_fun_unbox_x30, _ctx); /*(31, 32, 33, 34) -> 35*/
  _x_x603 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x604, (_x_x604, kk_std_time_date__date_box(_b_x36, _ctx), kk_std_time_date__clock_box(_b_x37, _ctx), kk_std_time_calendar__timezone_box(_b_x38, _ctx), kk_std_time_instant__timescale_box(_b_x39, _ctx), _ctx), _ctx); /*35*/
  return kk_std_time_instant__instant_unbox(_x_x603, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun607__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x43;
};
static kk_std_time_date__date kk_std_time_calendar_calendar_fs__copy_fun607(kk_function_t _fself, kk_integer_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun607(kk_box_t _fun_unbox_x43, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun607__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun607__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun607, kk_context());
  _self->_fun_unbox_x43 = _fun_unbox_x43;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_calendar_fs__copy_fun607(kk_function_t _fself, kk_integer_t _b_x46, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun607__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun607__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x43 = _self->_fun_unbox_x43; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x43, _ctx);}, {}, _ctx)
  kk_box_t _x_x608;
  kk_function_t _x_x609 = kk_function_unbox(_fun_unbox_x43, _ctx); /*(days : 44) -> 45*/
  _x_x608 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x609, (_x_x609, kk_integer_box(_b_x46, _ctx), _ctx), _ctx); /*45*/
  return kk_std_time_date__date_unbox(_x_x608, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun612__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x50;
};
static kk_integer_t kk_std_time_calendar_calendar_fs__copy_fun612(kk_function_t _fself, kk_std_time_date__date _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun612(kk_box_t _fun_unbox_x50, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun612__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun612__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun612, kk_context());
  _self->_fun_unbox_x50 = _fun_unbox_x50;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_calendar_fs__copy_fun612(kk_function_t _fself, kk_std_time_date__date _b_x53, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun612__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun612__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x50 = _self->_fun_unbox_x50; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x50, _ctx);}, {}, _ctx)
  kk_box_t _x_x613;
  kk_function_t _x_x614 = kk_function_unbox(_fun_unbox_x50, _ctx); /*(date : 51) -> 52*/
  _x_x613 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x614, (_x_x614, kk_std_time_date__date_box(_b_x53, _ctx), _ctx), _ctx); /*52*/
  return kk_integer_unbox(_x_x613, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendar_calendar_fs__copy(kk_std_time_calendar__calendar _this, kk_std_core_types__optional name, kk_std_core_types__optional long_name, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_std_core_types__optional instant_to_dc, kk_std_core_types__optional dc_to_instant, kk_std_core_types__optional days_to_date, kk_std_core_types__optional date_to_days, kk_context_t* _ctx) { /* (calendar, name : ? string, long-name : ? string, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string), instant-to-dc : ? ((i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)), dc-to-instant : ? ((std/time/date/date, std/time/date/clock, timezone, std/time/instant/timescale) -> std/time/instant/instant), days-to-date : ? ((days : int) -> std/time/date/date), date-to-days : ? ((date : std/time/date/date) -> int)) -> calendar */ 
  kk_string_t _x_x585;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_266 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_266, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x585 = _uniq_name_266; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x586 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _x = _con_x586->name;
      kk_string_dup(_x, _ctx);
      _x_x585 = _x; /*string*/
    }
  }
  kk_string_t _x_x587;
  if (kk_std_core_types__is_Optional(long_name, _ctx)) {
    kk_box_t _box_x1 = long_name._cons._Optional.value;
    kk_string_t _uniq_long_name_274 = kk_string_unbox(_box_x1);
    kk_string_dup(_uniq_long_name_274, _ctx);
    kk_std_core_types__optional_drop(long_name, _ctx);
    _x_x587 = _uniq_long_name_274; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(long_name, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x588 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _x_0 = _con_x588->long_name;
      kk_string_dup(_x_0, _ctx);
      _x_x587 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x589;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x2 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_282 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_month_prefix_282, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x589 = _uniq_month_prefix_282; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x590 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _x_1 = _con_x590->month_prefix;
      kk_string_dup(_x_1, _ctx);
      _x_x589 = _x_1; /*string*/
    }
  }
  kk_function_t _x_x591;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x6 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x6, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x591 = kk_std_time_calendar_calendar_fs__new_copy_fun592(_fun_unbox_x6, _ctx); /*(std/time/date/date) -> string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x595 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_2 = _con_x595->show_era;
      kk_function_dup(_x_2, _ctx);
      _x_x591 = _x_2; /*(std/time/date/date) -> string*/
    }
  }
  kk_function_t _x_x596;
  if (kk_std_core_types__is_Optional(instant_to_dc, _ctx)) {
    kk_box_t _fun_unbox_x15 = instant_to_dc._cons._Optional.value;
    kk_box_dup(_fun_unbox_x15, _ctx);
    kk_std_core_types__optional_drop(instant_to_dc, _ctx);
    _x_x596 = kk_std_time_calendar_calendar_fs__new_copy_fun597(_fun_unbox_x15, _ctx); /*(std/time/instant/instant, std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)*/
  }
  else {
    kk_std_core_types__optional_drop(instant_to_dc, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x600 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_3 = _con_x600->instant_to_dc;
      kk_function_dup(_x_3, _ctx);
      _x_x596 = _x_3; /*(std/time/instant/instant, std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)*/
    }
  }
  kk_function_t _x_x601;
  if (kk_std_core_types__is_Optional(dc_to_instant, _ctx)) {
    kk_box_t _fun_unbox_x30 = dc_to_instant._cons._Optional.value;
    kk_box_dup(_fun_unbox_x30, _ctx);
    kk_std_core_types__optional_drop(dc_to_instant, _ctx);
    _x_x601 = kk_std_time_calendar_calendar_fs__new_copy_fun602(_fun_unbox_x30, _ctx); /*(std/time/date/date, std/time/date/clock, std/time/calendar/timezone, std/time/instant/timescale) -> std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(dc_to_instant, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x605 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_4 = _con_x605->dc_to_instant;
      kk_function_dup(_x_4, _ctx);
      _x_x601 = _x_4; /*(std/time/date/date, std/time/date/clock, std/time/calendar/timezone, std/time/instant/timescale) -> std/time/instant/instant*/
    }
  }
  kk_function_t _x_x606;
  if (kk_std_core_types__is_Optional(days_to_date, _ctx)) {
    kk_box_t _fun_unbox_x43 = days_to_date._cons._Optional.value;
    kk_box_dup(_fun_unbox_x43, _ctx);
    kk_std_core_types__optional_drop(days_to_date, _ctx);
    _x_x606 = kk_std_time_calendar_calendar_fs__new_copy_fun607(_fun_unbox_x43, _ctx); /*(int) -> std/time/date/date*/
  }
  else {
    kk_std_core_types__optional_drop(days_to_date, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x610 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_5 = _con_x610->days_to_date;
      kk_function_dup(_x_5, _ctx);
      _x_x606 = _x_5; /*(int) -> std/time/date/date*/
    }
  }
  kk_function_t _x_x611;
  if (kk_std_core_types__is_Optional(date_to_days, _ctx)) {
    kk_box_t _fun_unbox_x50 = date_to_days._cons._Optional.value;
    kk_box_dup(_fun_unbox_x50, _ctx);
    kk_std_core_types__optional_drop(date_to_days, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(8)), _ctx);
    _x_x611 = kk_std_time_calendar_calendar_fs__new_copy_fun612(_fun_unbox_x50, _ctx); /*(std/time/date/date) -> int*/
  }
  else {
    kk_std_core_types__optional_drop(date_to_days, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x615 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _pat_0_7 = _con_x615->name;
      kk_string_t _pat_1_8 = _con_x615->long_name;
      kk_string_t _pat_2_7 = _con_x615->month_prefix;
      kk_function_t _pat_3_7 = _con_x615->show_era;
      kk_function_t _pat_4_7 = _con_x615->instant_to_dc;
      kk_function_t _pat_5_7 = _con_x615->dc_to_instant;
      kk_function_t _pat_6_7 = _con_x615->days_to_date;
      kk_function_t _x_6 = _con_x615->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_function_drop(_pat_6_7, _ctx);
        kk_function_drop(_pat_5_7, _ctx);
        kk_function_drop(_pat_4_7, _ctx);
        kk_function_drop(_pat_3_7, _ctx);
        kk_string_drop(_pat_2_7, _ctx);
        kk_string_drop(_pat_1_8, _ctx);
        kk_string_drop(_pat_0_7, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_function_dup(_x_6, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x611 = _x_6; /*(std/time/date/date) -> int*/
    }
  }
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, _x_x585, _x_x587, _x_x589, _x_x591, _x_x596, _x_x601, _x_x606, _x_x611, _ctx);
}
 
// Check if two calendars use the same date calculations. (Display of era names etc. may differ)

bool kk_std_time_calendar__lp__eq__eq__rp_(kk_std_time_calendar__calendar c1, kk_std_time_calendar__calendar c2, kk_context_t* _ctx) { /* (c1 : calendar, c2 : calendar) -> bool */ 
  kk_string_t _x_x617;
  {
    struct kk_std_time_calendar_Calendar* _con_x618 = kk_std_time_calendar__as_Calendar(c1, _ctx);
    kk_string_t _pat_0 = _con_x618->name;
    kk_string_t _x = _con_x618->long_name;
    kk_string_t _pat_1 = _con_x618->month_prefix;
    kk_function_t _pat_2 = _con_x618->show_era;
    kk_function_t _pat_3 = _con_x618->instant_to_dc;
    kk_function_t _pat_4 = _con_x618->dc_to_instant;
    kk_function_t _pat_5 = _con_x618->days_to_date;
    kk_function_t _pat_6 = _con_x618->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(c1, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_function_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(c1, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(c1, _ctx);
    }
    _x_x617 = _x; /*string*/
  }
  kk_string_t _x_x619;
  {
    struct kk_std_time_calendar_Calendar* _con_x620 = kk_std_time_calendar__as_Calendar(c2, _ctx);
    kk_string_t _pat_0_0 = _con_x620->name;
    kk_string_t _x_0 = _con_x620->long_name;
    kk_string_t _pat_1_0 = _con_x620->month_prefix;
    kk_function_t _pat_2_0 = _con_x620->show_era;
    kk_function_t _pat_3_0 = _con_x620->instant_to_dc;
    kk_function_t _pat_4_0 = _con_x620->dc_to_instant;
    kk_function_t _pat_5_0 = _con_x620->days_to_date;
    kk_function_t _pat_6_0 = _con_x620->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(c2, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_0, _ctx);
      kk_function_drop(_pat_4_0, _ctx);
      kk_function_drop(_pat_3_0, _ctx);
      kk_function_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(c2, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(c2, _ctx);
    }
    _x_x619 = _x_0; /*string*/
  }
  return kk_string_is_eq(_x_x617,_x_x619,kk_context());
}
 
// Same timezone?

bool kk_std_time_calendar_timezone_fs__lp__eq__eq__rp_(kk_std_time_calendar__timezone tz1, kk_std_time_calendar__timezone tz2, kk_context_t* _ctx) { /* (tz1 : timezone, tz2 : timezone) -> bool */ 
  kk_string_t _x_x621;
  {
    struct kk_std_time_calendar_Timezone* _con_x622 = kk_std_time_calendar__as_Timezone(tz1, _ctx);
    kk_string_t _x = _con_x622->name;
    kk_function_t _pat_0 = _con_x622->utc_delta;
    kk_function_t _pat_1 = _con_x622->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(tz1, _ctx)) {
      kk_function_drop(_pat_1, _ctx);
      kk_function_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(tz1, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(tz1, _ctx);
    }
    _x_x621 = _x; /*string*/
  }
  kk_string_t _x_x623;
  {
    struct kk_std_time_calendar_Timezone* _con_x624 = kk_std_time_calendar__as_Timezone(tz2, _ctx);
    kk_string_t _x_0 = _con_x624->name;
    kk_function_t _pat_0_0 = _con_x624->utc_delta;
    kk_function_t _pat_1_0 = _con_x624->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(tz2, _ctx)) {
      kk_function_drop(_pat_1_0, _ctx);
      kk_function_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(tz2, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(tz2, _ctx);
    }
    _x_x623 = _x_0; /*string*/
  }
  return kk_string_is_eq(_x_x621,_x_x623,kk_context());
}
extern kk_std_core_types__maybe kk_std_time_calendar__create_Timezone_fun626(kk_function_t _fself, kk_std_time_instant__instant _b_x60, kk_context_t* _ctx) {
  struct kk_std_time_calendar__create_Timezone_fun626__t* _self = kk_function_as(struct kk_std_time_calendar__create_Timezone_fun626__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x57 = _self->_fun_unbox_x57; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x57, _ctx);}, {}, _ctx)
  kk_box_t _x_x627;
  kk_function_t _x_x628 = kk_function_unbox(_fun_unbox_x57, _ctx); /*(58) -> 59*/
  _x_x627 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x628, (_x_x628, kk_std_time_instant__instant_box(_b_x60, _ctx), _ctx), _ctx); /*59*/
  return kk_std_core_types__maybe_unbox(_x_x627, KK_OWNED, _ctx);
}
extern kk_std_core_types__maybe kk_std_time_calendar__create_Timezone_fun629(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__instant_drop(i, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}


// lift anonymous function
struct kk_std_time_calendar_timezone_fs__copy_fun635__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x65;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_timezone_fs__copy_fun635(kk_function_t _fself, kk_std_time_instant__instant _b_x68, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_timezone_fs__new_copy_fun635(kk_box_t _fun_unbox_x65, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun635__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_timezone_fs__copy_fun635__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_timezone_fs__copy_fun635, kk_context());
  _self->_fun_unbox_x65 = _fun_unbox_x65;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_timezone_fs__copy_fun635(kk_function_t _fself, kk_std_time_instant__instant _b_x68, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun635__t* _self = kk_function_as(struct kk_std_time_calendar_timezone_fs__copy_fun635__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x65 = _self->_fun_unbox_x65; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x65, _ctx);}, {}, _ctx)
  kk_box_t _x_x636;
  kk_function_t _x_x637 = kk_function_unbox(_fun_unbox_x65, _ctx); /*(66) -> 67*/
  _x_x636 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x637, (_x_x637, kk_std_time_instant__instant_box(_b_x68, _ctx), _ctx), _ctx); /*67*/
  return kk_std_core_types__tuple2_unbox(_x_x636, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_timezone_fs__copy_fun640__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x72;
};
static kk_std_core_types__maybe kk_std_time_calendar_timezone_fs__copy_fun640(kk_function_t _fself, kk_std_time_instant__instant _b_x75, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_timezone_fs__new_copy_fun640(kk_box_t _fun_unbox_x72, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun640__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_timezone_fs__copy_fun640__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_timezone_fs__copy_fun640, kk_context());
  _self->_fun_unbox_x72 = _fun_unbox_x72;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_timezone_fs__copy_fun640(kk_function_t _fself, kk_std_time_instant__instant _b_x75, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun640__t* _self = kk_function_as(struct kk_std_time_calendar_timezone_fs__copy_fun640__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x72 = _self->_fun_unbox_x72; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x72, _ctx);}, {}, _ctx)
  kk_box_t _x_x641;
  kk_function_t _x_x642 = kk_function_unbox(_fun_unbox_x72, _ctx); /*(73) -> 74*/
  _x_x641 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x642, (_x_x642, kk_std_time_instant__instant_box(_b_x75, _ctx), _ctx), _ctx); /*74*/
  return kk_std_core_types__maybe_unbox(_x_x641, KK_OWNED, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_calendar_timezone_fs__copy(kk_std_time_calendar__timezone _this, kk_std_core_types__optional name, kk_std_core_types__optional utc_delta, kk_std_core_types__optional utc_inverse, kk_context_t* _ctx) { /* (timezone, name : ? string, utc-delta : ? ((std/time/instant/instant) -> (std/time/duration/duration, string)), utc-inverse : ? ((std/time/instant/instant) -> maybe<std/time/instant/instant>)) -> timezone */ 
  kk_string_t _x_x632;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x61 = name._cons._Optional.value;
    kk_string_t _uniq_name_733 = kk_string_unbox(_box_x61);
    kk_string_dup(_uniq_name_733, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x632 = _uniq_name_733; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_std_time_calendar_Timezone* _con_x633 = kk_std_time_calendar__as_Timezone(_this, _ctx);
      kk_string_t _x = _con_x633->name;
      kk_string_dup(_x, _ctx);
      _x_x632 = _x; /*string*/
    }
  }
  kk_function_t _x_x634;
  if (kk_std_core_types__is_Optional(utc_delta, _ctx)) {
    kk_box_t _fun_unbox_x65 = utc_delta._cons._Optional.value;
    kk_box_dup(_fun_unbox_x65, _ctx);
    kk_std_core_types__optional_drop(utc_delta, _ctx);
    _x_x634 = kk_std_time_calendar_timezone_fs__new_copy_fun635(_fun_unbox_x65, _ctx); /*(std/time/instant/instant) -> (std/time/duration/duration, string)*/
  }
  else {
    kk_std_core_types__optional_drop(utc_delta, _ctx);
    {
      struct kk_std_time_calendar_Timezone* _con_x638 = kk_std_time_calendar__as_Timezone(_this, _ctx);
      kk_function_t _x_0 = _con_x638->utc_delta;
      kk_function_dup(_x_0, _ctx);
      _x_x634 = _x_0; /*(std/time/instant/instant) -> (std/time/duration/duration, string)*/
    }
  }
  kk_function_t _x_x639;
  if (kk_std_core_types__is_Optional(utc_inverse, _ctx)) {
    kk_box_t _fun_unbox_x72 = utc_inverse._cons._Optional.value;
    kk_box_dup(_fun_unbox_x72, _ctx);
    kk_std_core_types__optional_drop(utc_inverse, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x639 = kk_std_time_calendar_timezone_fs__new_copy_fun640(_fun_unbox_x72, _ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  else {
    kk_std_core_types__optional_drop(utc_inverse, _ctx);
    {
      struct kk_std_time_calendar_Timezone* _con_x643 = kk_std_time_calendar__as_Timezone(_this, _ctx);
      kk_string_t _pat_0_2 = _con_x643->name;
      kk_function_t _pat_1_3 = _con_x643->utc_delta;
      kk_function_t _x_1 = _con_x643->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_function_drop(_pat_1_3, _ctx);
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_function_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x639 = _x_1; /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
    }
  }
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, _x_x632, _x_x634, _x_x639, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_string_fs_tz_fixed_fun644__t {
  struct kk_function_s _base;
  kk_std_core_types__optional abbrv;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_string_fs_tz_fixed_fun644(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_string_fs_new_tz_fixed_fun644(kk_std_core_types__optional abbrv, kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun644__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun644__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_string_fs_tz_fixed_fun644, kk_context());
  _self->abbrv = abbrv;
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_string_fs_tz_fixed_fun644(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun644__t* _self = kk_function_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun644__t*, _fself, _ctx);
  kk_std_core_types__optional abbrv = _self->abbrv; /* ? string */
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(abbrv, _ctx);kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant_drop(i_0, _ctx);
  kk_box_t _x_x645;
  kk_string_t _x_x646;
  if (kk_std_core_types__is_Optional(abbrv, _ctx)) {
    kk_box_t _box_x76 = abbrv._cons._Optional.value;
    kk_string_t _uniq_abbrv_780 = kk_string_unbox(_box_x76);
    kk_string_dup(_uniq_abbrv_780, _ctx);
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x646 = _uniq_abbrv_780; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x646 = kk_string_empty(); /*string*/
  }
  _x_x645 = kk_string_box(_x_x646); /*135*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(delta, _ctx), _x_x645, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_string_fs_tz_fixed_fun648__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__maybe kk_std_time_calendar_string_fs_tz_fixed_fun648(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_string_fs_new_tz_fixed_fun648(kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun648__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun648__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_string_fs_tz_fixed_fun648, kk_context());
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_string_fs_tz_fixed_fun648(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun648__t* _self = kk_function_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun648__t*, _fself, _ctx);
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  bool _match_x533;
  double _x_x649;
  {
    kk_std_num_ddouble__ddouble _x_0 = delta.secs;
    {
      double _x = _x_0.hi;
      _x_x649 = _x; /*float64*/
    }
  }
  _match_x533 = (_x_x649 == (0x0p+0)); /*bool*/
  if (_match_x533) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_0, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

kk_std_time_calendar__timezone kk_std_time_calendar_string_fs_tz_fixed(kk_string_t name, kk_std_time_duration__duration delta, kk_std_core_types__optional abbrv, kk_context_t* _ctx) { /* (name : string, delta : std/time/duration/duration, abbrv : ? string) -> timezone */ 
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, name, kk_std_time_calendar_string_fs_new_tz_fixed_fun644(abbrv, delta, _ctx), kk_std_time_calendar_string_fs_new_tz_fixed_fun648(delta, _ctx), _ctx);
}
 
// The standard UTC time zone with a 0 delta.


// lift anonymous function
struct kk_std_time_calendar_tz_utc_fun652__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_utc_fun652(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_utc_fun652(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_tz_utc_fun652, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_utc_fun652(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__instant_drop(i_0, _ctx);
  kk_box_t _x_x653;
  kk_string_t _x_x654;
  kk_std_core_types__optional _match_x532 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x532, _ctx)) {
    kk_box_t _box_x83 = _match_x532._cons._Optional.value;
    kk_string_t _uniq_abbrv_780 = kk_string_unbox(_box_x83);
    kk_string_dup(_uniq_abbrv_780, _ctx);
    kk_std_core_types__optional_drop(_match_x532, _ctx);
    _x_x654 = _uniq_abbrv_780; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x532, _ctx);
    _x_x654 = kk_string_empty(); /*string*/
  }
  _x_x653 = kk_string_box(_x_x654); /*135*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(kk_std_time_duration_zero, _ctx), _x_x653, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_utc_fun656__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_utc_fun656(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_utc_fun656(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_tz_utc_fun656, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_utc_fun656(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _match_x531;
  double _x_x657;
  kk_std_time_duration__duration _x_x658 = kk_std_time_duration_zero; /*std/time/duration/duration*/
  {
    kk_std_num_ddouble__ddouble _x_0 = _x_x658.secs;
    {
      double _x = _x_0.hi;
      _x_x657 = _x; /*float64*/
    }
  }
  _match_x531 = (_x_x657 == (0x0p+0)); /*bool*/
  if (_match_x531) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_0, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

kk_std_time_calendar__timezone kk_std_time_calendar_tz_utc;
 
// Create a time zone with a fixed number of hours and optional minutes (=`0`) difference from UTC/GMT.
// The time zone name and abbreviation is optional, and the default name
// will reflect the offset from UTC, for example `"UTC+1:20"`, or `"UTC-8"`.
// The default abbreviation is the empty string.
// The sign of the minutes will be matched to the hours (unless `hours` is `0`).
// For example, `tz-fixed(-1,30)` gives a time zone offset of -90 minutes, "UTC-1:30".
// Returns `tz-utc` if both `hours` and `mins` are zero.


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun688__t {
  struct kk_function_s _base;
  kk_std_core_types__optional abbrv;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun688(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun688(kk_std_core_types__optional abbrv, kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun688__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun688__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun688, kk_context());
  _self->abbrv = abbrv;
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun688(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun688__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun688__t*, _fself, _ctx);
  kk_std_core_types__optional abbrv = _self->abbrv; /* ? string */
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(abbrv, _ctx);kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant_drop(i_0, _ctx);
  kk_box_t _x_x689;
  kk_string_t _x_x690;
  if (kk_std_core_types__is_Optional(abbrv, _ctx)) {
    kk_box_t _box_x101 = abbrv._cons._Optional.value;
    kk_string_t _uniq_abbrv_852 = kk_string_unbox(_box_x101);
    kk_string_dup(_uniq_abbrv_852, _ctx);
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x690 = _uniq_abbrv_852; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x690 = kk_string_empty(); /*string*/
  }
  _x_x689 = kk_string_box(_x_x690); /*135*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(delta, _ctx), _x_x689, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun692__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun692(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun692(kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun692__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun692__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun692, kk_context());
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun692(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun692__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun692__t*, _fself, _ctx);
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  bool _match_x520;
  double _x_x693;
  {
    kk_std_num_ddouble__ddouble _x_0 = delta.secs;
    {
      double _x = _x_0.hi;
      _x_x693 = _x; /*float64*/
    }
  }
  _match_x520 = (_x_x693 == (0x0p+0)); /*bool*/
  if (_match_x520) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_0, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun723__t {
  struct kk_function_s _base;
  kk_std_core_types__optional abbrv;
  kk_std_time_duration__duration delta_0_0;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun723(kk_function_t _fself, kk_std_time_instant__instant i_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun723(kk_std_core_types__optional abbrv, kk_std_time_duration__duration delta_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun723__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun723__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun723, kk_context());
  _self->abbrv = abbrv;
  _self->delta_0_0 = delta_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun723(kk_function_t _fself, kk_std_time_instant__instant i_0_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun723__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun723__t*, _fself, _ctx);
  kk_std_core_types__optional abbrv = _self->abbrv; /* ? string */
  kk_std_time_duration__duration delta_0_0 = _self->delta_0_0; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(abbrv, _ctx);kk_std_time_duration__duration_dup(delta_0_0, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant_drop(i_0_1, _ctx);
  kk_box_t _x_x724;
  kk_string_t _x_x725;
  if (kk_std_core_types__is_Optional(abbrv, _ctx)) {
    kk_box_t _box_x115 = abbrv._cons._Optional.value;
    kk_string_t _uniq_abbrv_852_0 = kk_string_unbox(_box_x115);
    kk_string_dup(_uniq_abbrv_852_0, _ctx);
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x725 = _uniq_abbrv_852_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x725 = kk_string_empty(); /*string*/
  }
  _x_x724 = kk_string_box(_x_x725); /*135*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(delta_0_0, _ctx), _x_x724, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun727__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration delta_0_0;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun727(kk_function_t _fself, kk_std_time_instant__instant i_0_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun727(kk_std_time_duration__duration delta_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun727__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun727__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun727, kk_context());
  _self->delta_0_0 = delta_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun727(kk_function_t _fself, kk_std_time_instant__instant i_0_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun727__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun727__t*, _fself, _ctx);
  kk_std_time_duration__duration delta_0_0 = _self->delta_0_0; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(delta_0_0, _ctx);}, {}, _ctx)
  bool _match_x508;
  double _x_x728;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = delta_0_0.secs;
    {
      double _x_1 = _x_0_0.hi;
      _x_x728 = _x_1; /*float64*/
    }
  }
  _match_x508 = (_x_x728 == (0x0p+0)); /*bool*/
  if (_match_x508) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_0_0, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_0_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

kk_std_time_calendar__timezone kk_std_time_calendar_tz_fixed(kk_integer_t hours, kk_std_core_types__optional mins, kk_std_core_types__optional name, kk_std_core_types__optional abbrv, kk_std_core_types__optional hourwidth, kk_context_t* _ctx) { /* (hours : int, mins : ? int, name : ? string, abbrv : ? string, hourwidth : ? int) -> timezone */ 
  kk_integer_t _uniq_mins_843;
  if (kk_std_core_types__is_Optional(mins, _ctx)) {
    kk_box_t _box_x90 = mins._cons._Optional.value;
    kk_integer_t _uniq_mins_844 = kk_integer_unbox(_box_x90, _ctx);
    kk_integer_dup(_uniq_mins_844, _ctx);
    kk_std_core_types__optional_drop(mins, _ctx);
    _uniq_mins_843 = _uniq_mins_844; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(mins, _ctx);
    _uniq_mins_843 = kk_integer_from_small(0); /*int*/
  }
  bool _match_x507 = kk_integer_is_zero_borrow(hours); /*bool*/;
  if (_match_x507) {
    bool _match_x519 = kk_integer_is_zero_borrow(_uniq_mins_843); /*bool*/;
    if (_match_x519) {
      kk_std_core_types__optional_drop(name, _ctx);
      kk_std_core_types__optional_drop(hourwidth, _ctx);
      kk_integer_drop(hours, _ctx);
      kk_std_core_types__optional_drop(abbrv, _ctx);
      kk_integer_drop(_uniq_mins_843, _ctx);
      return kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx);
    }
    {
      kk_integer_t xmins;
      bool _match_x529 = kk_integer_gt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x529) {
        kk_integer_t _x_x659 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
        xmins = kk_integer_abs(_x_x659,kk_context()); /*int*/
      }
      else {
        bool _match_x530 = kk_integer_lt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x530) {
          kk_integer_t i_1_10021;
          kk_integer_t _x_x660 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
          i_1_10021 = kk_integer_abs(_x_x660,kk_context()); /*int*/
          xmins = kk_integer_neg(i_1_10021,kk_context()); /*int*/
        }
        else {
          xmins = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
        }
      }
      kk_integer_t x_10022;
      kk_integer_t _x_x661 = kk_integer_dup(hours, _ctx); /*int*/
      x_10022 = kk_integer_mul(_x_x661,(kk_integer_from_small(3600)),kk_context()); /*int*/
      kk_integer_t y_10023 = kk_integer_mul(xmins,(kk_integer_from_small(60)),kk_context()); /*int*/;
      kk_integer_t secs = kk_integer_add(x_10022,y_10023,kk_context()); /*int*/;
      kk_string_t y_0_10025;
      kk_string_t _x_x662;
      kk_define_string_literal(, _s_x663, 3, "UTC", _ctx)
      _x_x662 = kk_string_dup(_s_x663, _ctx); /*string*/
      kk_string_t _x_x664;
      kk_string_t _x_x665;
      bool _match_x528 = kk_integer_lt_borrow(secs,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x528) {
        kk_define_string_literal(, _s_x666, 1, "-", _ctx)
        _x_x665 = kk_string_dup(_s_x666, _ctx); /*string*/
      }
      else {
        kk_define_string_literal(, _s_x667, 1, "+", _ctx)
        _x_x665 = kk_string_dup(_s_x667, _ctx); /*string*/
      }
      kk_string_t _x_x668;
      kk_string_t _x_x669;
      kk_string_t _own_x526;
      kk_integer_t _x_x670 = kk_integer_abs(hours,kk_context()); /*int*/
      _own_x526 = kk_std_core_int_show(_x_x670, _ctx); /*string*/
      kk_integer_t _brw_x525;
      if (kk_std_core_types__is_Optional(hourwidth, _ctx)) {
        kk_box_t _box_x91 = hourwidth._cons._Optional.value;
        kk_integer_t _uniq_hourwidth_856 = kk_integer_unbox(_box_x91, _ctx);
        kk_integer_dup(_uniq_hourwidth_856, _ctx);
        kk_std_core_types__optional_drop(hourwidth, _ctx);
        _brw_x525 = _uniq_hourwidth_856; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(hourwidth, _ctx);
        _brw_x525 = kk_integer_from_small(1); /*int*/
      }
      kk_string_t _brw_x527;
      kk_std_core_types__optional _x_x671 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
      _brw_x527 = kk_std_core_string_pad_left(_own_x526, _brw_x525, _x_x671, _ctx); /*string*/
      kk_integer_drop(_brw_x525, _ctx);
      _x_x669 = _brw_x527; /*string*/
      kk_string_t _x_x672;
      bool _match_x523 = kk_integer_is_zero_borrow(_uniq_mins_843); /*bool*/;
      if (_match_x523) {
        kk_integer_drop(_uniq_mins_843, _ctx);
        _x_x672 = kk_string_empty(); /*string*/
      }
      else {
        kk_string_t _x_x674;
        kk_define_string_literal(, _s_x675, 1, ":", _ctx)
        _x_x674 = kk_string_dup(_s_x675, _ctx); /*string*/
        kk_string_t _x_x676;
        kk_string_t _own_x524;
        kk_integer_t _x_x677 = kk_integer_abs(_uniq_mins_843,kk_context()); /*int*/
        _own_x524 = kk_std_core_int_show(_x_x677, _ctx); /*string*/
        kk_std_core_types__optional _x_x678 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
        _x_x676 = kk_std_core_string_pad_left(_own_x524, kk_integer_from_small(2), _x_x678, _ctx); /*string*/
        _x_x672 = kk_std_core_types__lp__plus__plus__rp_(_x_x674, _x_x676, _ctx); /*string*/
      }
      _x_x668 = kk_std_core_types__lp__plus__plus__rp_(_x_x669, _x_x672, _ctx); /*string*/
      _x_x664 = kk_std_core_types__lp__plus__plus__rp_(_x_x665, _x_x668, _ctx); /*string*/
      y_0_10025 = kk_std_core_types__lp__plus__plus__rp_(_x_x662, _x_x664, _ctx); /*string*/
      kk_string_t tzonename;
      bool _match_x522;
      kk_string_t _x_x679;
      if (kk_std_core_types__is_Optional(name, _ctx)) {
        kk_box_t _box_x96 = name._cons._Optional.value;
        kk_string_t _uniq_name_848 = kk_string_unbox(_box_x96);
        kk_string_dup(_uniq_name_848, _ctx);
        _x_x679 = _uniq_name_848; /*string*/
      }
      else {
        _x_x679 = kk_string_empty(); /*string*/
      }
      kk_string_t _x_x681 = kk_string_empty(); /*string*/
      _match_x522 = kk_string_is_eq(_x_x679,_x_x681,kk_context()); /*bool*/
      if (_match_x522) {
        kk_std_core_types__optional_drop(name, _ctx);
        tzonename = y_0_10025; /*string*/
      }
      else {
        kk_string_drop(y_0_10025, _ctx);
        if (kk_std_core_types__is_Optional(name, _ctx)) {
          kk_box_t _box_x97 = name._cons._Optional.value;
          kk_string_t _uniq_name_848_0 = kk_string_unbox(_box_x97);
          kk_string_dup(_uniq_name_848_0, _ctx);
          kk_std_core_types__optional_drop(name, _ctx);
          tzonename = _uniq_name_848_0; /*string*/
        }
        else {
          kk_std_core_types__optional_drop(name, _ctx);
          tzonename = kk_string_empty(); /*string*/
        }
      }
      kk_std_time_duration__duration delta;
      kk_std_num_ddouble__ddouble _x_x684;
      kk_std_core_types__optional _x_x685;
      kk_box_t _x_x686;
      double _x_x687;
      kk_std_core_types__optional _match_x521 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x521, _ctx)) {
        kk_box_t _box_x98 = _match_x521._cons._Optional.value;
        double _uniq_frac_155 = kk_double_unbox(_box_x98, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x521, _ctx);
        _x_x687 = _uniq_frac_155; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x521, _ctx);
        _x_x687 = 0x0p+0; /*float64*/
      }
      _x_x686 = kk_double_box(_x_x687, _ctx); /*7*/
      _x_x685 = kk_std_core_types__new_Optional(_x_x686, _ctx); /*? 7*/
      _x_x684 = kk_std_time_timestamp_int_fs_timespan(secs, _x_x685, _ctx); /*std/time/timestamp/timespan*/
      delta = kk_std_time_duration__new_Duration(_x_x684, _ctx); /*std/time/duration/duration*/
      return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, tzonename, kk_std_time_calendar_new_tz_fixed_fun688(abbrv, delta, _ctx), kk_std_time_calendar_new_tz_fixed_fun692(delta, _ctx), _ctx);
    }
  }
  {
    kk_integer_t xmins_0;
    bool _match_x517 = kk_integer_gt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x517) {
      kk_integer_t _x_x694 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
      xmins_0 = kk_integer_abs(_x_x694,kk_context()); /*int*/
    }
    else {
      bool _match_x518 = kk_integer_lt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x518) {
        kk_integer_t i_5_10031;
        kk_integer_t _x_x695 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
        i_5_10031 = kk_integer_abs(_x_x695,kk_context()); /*int*/
        xmins_0 = kk_integer_neg(i_5_10031,kk_context()); /*int*/
      }
      else {
        xmins_0 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
      }
    }
    kk_integer_t x_1_10032;
    kk_integer_t _x_x696 = kk_integer_dup(hours, _ctx); /*int*/
    x_1_10032 = kk_integer_mul(_x_x696,(kk_integer_from_small(3600)),kk_context()); /*int*/
    kk_integer_t y_1_10033 = kk_integer_mul(xmins_0,(kk_integer_from_small(60)),kk_context()); /*int*/;
    kk_integer_t secs_0_0 = kk_integer_add(x_1_10032,y_1_10033,kk_context()); /*int*/;
    kk_string_t y_2_10035;
    kk_string_t _x_x697;
    kk_define_string_literal(, _s_x698, 3, "UTC", _ctx)
    _x_x697 = kk_string_dup(_s_x698, _ctx); /*string*/
    kk_string_t _x_x699;
    kk_string_t _x_x700;
    bool _match_x516 = kk_integer_lt_borrow(secs_0_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x516) {
      kk_define_string_literal(, _s_x701, 1, "-", _ctx)
      _x_x700 = kk_string_dup(_s_x701, _ctx); /*string*/
    }
    else {
      kk_define_string_literal(, _s_x702, 1, "+", _ctx)
      _x_x700 = kk_string_dup(_s_x702, _ctx); /*string*/
    }
    kk_string_t _x_x703;
    kk_string_t _x_x704;
    kk_string_t _own_x514;
    kk_integer_t _x_x705 = kk_integer_abs(hours,kk_context()); /*int*/
    _own_x514 = kk_std_core_int_show(_x_x705, _ctx); /*string*/
    kk_integer_t _brw_x513;
    if (kk_std_core_types__is_Optional(hourwidth, _ctx)) {
      kk_box_t _box_x105 = hourwidth._cons._Optional.value;
      kk_integer_t _uniq_hourwidth_856_0 = kk_integer_unbox(_box_x105, _ctx);
      kk_integer_dup(_uniq_hourwidth_856_0, _ctx);
      kk_std_core_types__optional_drop(hourwidth, _ctx);
      _brw_x513 = _uniq_hourwidth_856_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(hourwidth, _ctx);
      _brw_x513 = kk_integer_from_small(1); /*int*/
    }
    kk_string_t _brw_x515;
    kk_std_core_types__optional _x_x706 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _brw_x515 = kk_std_core_string_pad_left(_own_x514, _brw_x513, _x_x706, _ctx); /*string*/
    kk_integer_drop(_brw_x513, _ctx);
    _x_x704 = _brw_x515; /*string*/
    kk_string_t _x_x707;
    bool _match_x511 = kk_integer_is_zero_borrow(_uniq_mins_843); /*bool*/;
    if (_match_x511) {
      kk_integer_drop(_uniq_mins_843, _ctx);
      _x_x707 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x709;
      kk_define_string_literal(, _s_x710, 1, ":", _ctx)
      _x_x709 = kk_string_dup(_s_x710, _ctx); /*string*/
      kk_string_t _x_x711;
      kk_string_t _own_x512;
      kk_integer_t _x_x712 = kk_integer_abs(_uniq_mins_843,kk_context()); /*int*/
      _own_x512 = kk_std_core_int_show(_x_x712, _ctx); /*string*/
      kk_std_core_types__optional _x_x713 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
      _x_x711 = kk_std_core_string_pad_left(_own_x512, kk_integer_from_small(2), _x_x713, _ctx); /*string*/
      _x_x707 = kk_std_core_types__lp__plus__plus__rp_(_x_x709, _x_x711, _ctx); /*string*/
    }
    _x_x703 = kk_std_core_types__lp__plus__plus__rp_(_x_x704, _x_x707, _ctx); /*string*/
    _x_x699 = kk_std_core_types__lp__plus__plus__rp_(_x_x700, _x_x703, _ctx); /*string*/
    y_2_10035 = kk_std_core_types__lp__plus__plus__rp_(_x_x697, _x_x699, _ctx); /*string*/
    kk_string_t tzonename_0;
    bool _match_x510;
    kk_string_t _x_x714;
    if (kk_std_core_types__is_Optional(name, _ctx)) {
      kk_box_t _box_x110 = name._cons._Optional.value;
      kk_string_t _uniq_name_848_0_0 = kk_string_unbox(_box_x110);
      kk_string_dup(_uniq_name_848_0_0, _ctx);
      _x_x714 = _uniq_name_848_0_0; /*string*/
    }
    else {
      _x_x714 = kk_string_empty(); /*string*/
    }
    kk_string_t _x_x716 = kk_string_empty(); /*string*/
    _match_x510 = kk_string_is_eq(_x_x714,_x_x716,kk_context()); /*bool*/
    if (_match_x510) {
      kk_std_core_types__optional_drop(name, _ctx);
      tzonename_0 = y_2_10035; /*string*/
    }
    else {
      kk_string_drop(y_2_10035, _ctx);
      if (kk_std_core_types__is_Optional(name, _ctx)) {
        kk_box_t _box_x111 = name._cons._Optional.value;
        kk_string_t _uniq_name_848_0_1 = kk_string_unbox(_box_x111);
        kk_string_dup(_uniq_name_848_0_1, _ctx);
        kk_std_core_types__optional_drop(name, _ctx);
        tzonename_0 = _uniq_name_848_0_1; /*string*/
      }
      else {
        kk_std_core_types__optional_drop(name, _ctx);
        tzonename_0 = kk_string_empty(); /*string*/
      }
    }
    kk_std_time_duration__duration delta_0_0;
    kk_std_num_ddouble__ddouble _x_x719;
    kk_std_core_types__optional _x_x720;
    kk_box_t _x_x721;
    double _x_x722;
    kk_std_core_types__optional _match_x509 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x509, _ctx)) {
      kk_box_t _box_x112 = _match_x509._cons._Optional.value;
      double _uniq_frac_155_0 = kk_double_unbox(_box_x112, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x509, _ctx);
      _x_x722 = _uniq_frac_155_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x509, _ctx);
      _x_x722 = 0x0p+0; /*float64*/
    }
    _x_x721 = kk_double_box(_x_x722, _ctx); /*7*/
    _x_x720 = kk_std_core_types__new_Optional(_x_x721, _ctx); /*? 7*/
    _x_x719 = kk_std_time_timestamp_int_fs_timespan(secs_0_0, _x_x720, _ctx); /*std/time/timestamp/timespan*/
    delta_0_0 = kk_std_time_duration__new_Duration(_x_x719, _ctx); /*std/time/duration/duration*/
    return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, tzonename_0, kk_std_time_calendar_new_tz_fixed_fun723(abbrv, delta_0_0, _ctx), kk_std_time_calendar_new_tz_fixed_fun727(delta_0_0, _ctx), _ctx);
  }
}
 
// Is this the UTC timezone?

bool kk_std_time_calendar_is_tz_utc(kk_std_time_calendar__timezone tz, kk_context_t* _ctx) { /* (tz : timezone) -> bool */ 
  kk_string_t _x_x729;
  {
    struct kk_std_time_calendar_Timezone* _con_x730 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x = _con_x730->name;
    kk_function_t _pat_0 = _con_x730->utc_delta;
    kk_function_t _pat_1 = _con_x730->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
      kk_function_drop(_pat_1, _ctx);
      kk_function_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(tz, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(tz, _ctx);
    }
    _x_x729 = _x; /*string*/
  }
  kk_string_t _x_x731;
  kk_std_time_calendar__timezone _x_x732 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x733 = kk_std_time_calendar__as_Timezone(_x_x732, _ctx);
    kk_string_t _x_0 = _con_x733->name;
    _x_x731 = kk_string_dup(_x_0, _ctx); /*string*/
  }
  return kk_string_is_eq(_x_x729,_x_x731,kk_context());
}
 
// Get the current local timezone structure.
// The timezone name is allowed to be the empty string.

kk_std_time_calendar__local_timezone kk_std_time_calendar_local_get_timezone(kk_context_t* _ctx) { /* () -> ndet local-timezone */ 
  return kk_local_get_timezone(kk_context());
}
 
// Return the utc delta in fractional seconds given a local timezone structure
// and time `i` in fractional seconds since the UNIX epoch (1970-01-01).
// Also returns time zone abbreviation.

kk_std_core_types__tuple2 kk_std_time_calendar_local_utc_delta(kk_std_time_calendar__local_timezone tz, double i, kk_context_t* _ctx) { /* (tz : local-timezone, i : float64) -> (float64, string) */ 
  return kk_local_get_utc_delta_tuple(tz,i,kk_context());
}
 
// Return the local timezone on the current system.


// lift anonymous function
struct kk_std_time_calendar_tz_local_fun736__t {
  struct kk_function_s _base;
  kk_std_time_calendar__local_timezone tz;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_local_fun736(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_local_fun736(kk_std_time_calendar__local_timezone tz, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun736__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_local_fun736__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_local_fun736, kk_context());
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_local_fun736(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun736__t* _self = kk_function_as(struct kk_std_time_calendar_tz_local_fun736__t*, _fself, _ctx);
  kk_std_time_calendar__local_timezone tz = _self->tz; /* std/time/calendar/local-timezone */
  kk_drop_match(_self, {kk_std_time_calendar__local_timezone_dup(tz, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble x_10046;
  kk_std_num_ddouble__ddouble _x_x737;
  kk_std_time_timestamp__timestamp _x_x738;
  kk_std_time_timestamp__timestamp _x_x739;
  {
    kk_std_time_timestamp__timestamp _x_0 = i_0.since;
    kk_std_time_instant__timescale _pat_2_0 = i_0.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x740 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x741 = kk_std_time_instant__as_Timescale(_pat_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
    _x_x739 = _x_0; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x742;
  {
    kk_std_time_timestamp__timestamp _pat_0_0_0 = i_0.since;
    kk_std_time_instant__timescale _x_0_0 = i_0.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x743 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x744 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
    kk_std_time_instant__instant_drop(i_0, _ctx);
    _x_x742 = _x_0_0; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x745 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  _x_x738 = kk_std_time_instant_convert(_x_x739, _x_x742, _x_x745, _ctx); /*std/time/timestamp/timestamp*/
  _x_x737 = kk_std_time_timestamp_unsafe_timespan_withleap(_x_x738, _ctx); /*std/time/timestamp/timespan*/
  x_10046 = kk_std_num_ddouble__lp__plus__rp_(kk_std_time_utc_unix2000, _x_x737, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 _match_x506;
  double _x_x746;
  {
    double _x = x_10046.hi;
    _x_x746 = _x; /*float64*/
  }
  _match_x506 = kk_std_time_calendar_local_utc_delta(tz, _x_x746, _ctx); /*(float64, string)*/
  {
    kk_box_t _box_x125 = _match_x506.fst;
    kk_box_t _box_x126 = _match_x506.snd;
    double ofs = kk_double_unbox(_box_x125, KK_BORROWED, _ctx);
    kk_string_t abbrv = kk_string_unbox(_box_x126);
    kk_string_dup(abbrv, _ctx);
    kk_std_core_types__tuple2_drop(_match_x506, _ctx);
    kk_box_t _x_x747;
    kk_std_time_duration__duration _x_x748;
    kk_std_num_ddouble__ddouble _x_x749 = kk_std_num_ddouble__new_Ddouble(ofs, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x748 = kk_std_time_duration__new_Duration(_x_x749, _ctx); /*std/time/duration/duration*/
    _x_x747 = kk_std_time_duration__duration_box(_x_x748, _ctx); /*134*/
    return kk_std_core_types__new_Tuple2(_x_x747, kk_string_box(abbrv), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_tz_local_fun751__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x132;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun751(kk_function_t _fself, kk_std_time_instant__instant _b_x135, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_local_fun751(kk_box_t _fun_unbox_x132, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun751__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_local_fun751__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_local_fun751, kk_context());
  _self->_fun_unbox_x132 = _fun_unbox_x132;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun751(kk_function_t _fself, kk_std_time_instant__instant _b_x135, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun751__t* _self = kk_function_as(struct kk_std_time_calendar_tz_local_fun751__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x132 = _self->_fun_unbox_x132; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x132, _ctx);}, {}, _ctx)
  kk_box_t _x_x752;
  kk_function_t _x_x753 = kk_function_unbox(_fun_unbox_x132, _ctx); /*(133) -> 134*/
  _x_x752 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x753, (_x_x753, kk_std_time_instant__instant_box(_b_x135, _ctx), _ctx), _ctx); /*134*/
  return kk_std_core_types__maybe_unbox(_x_x752, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_local_fun754__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun754(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_local_fun754(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_tz_local_fun754, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun754(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__instant_drop(i, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_time_calendar__timezone kk_std_time_calendar_tz_local(kk_context_t* _ctx) { /* () -> ndet timezone */ 
  kk_std_time_calendar__local_timezone tz = kk_std_time_calendar_local_get_timezone(_ctx); /*std/time/calendar/local-timezone*/;
  kk_string_t _x_x734 = kk_string_empty(); /*string*/
  kk_function_t _x_x750;
  kk_std_core_types__optional _match_x505 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x505, _ctx)) {
    kk_box_t _fun_unbox_x132 = _match_x505._cons._Optional.value;
    kk_box_dup(_fun_unbox_x132, _ctx);
    kk_std_core_types__optional_drop(_match_x505, _ctx);
    _x_x750 = kk_std_time_calendar_new_tz_local_fun751(_fun_unbox_x132, _ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x505, _ctx);
    _x_x750 = kk_std_time_calendar_new_tz_local_fun754(_ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, _x_x734, kk_std_time_calendar_new_tz_local_fun736(tz, _ctx), _x_x750, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_calendar_earth_timestamp_to_dc(kk_std_time_timestamp__timestamp t, kk_std_num_ddouble__ddouble tzdelta, kk_function_t days_to_date, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan, days-to-date : (int) -> std/time/date/date) -> (std/time/date/date, std/time/date/clock) */ 
  kk_std_time_timestamp__timestamp ts_10049;
  kk_std_num_ddouble__ddouble _x_x755;
  kk_std_num_ddouble__ddouble _x_x756;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x757 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _x_0 = _con_x757->since;
    _x_x756 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x755 = kk_std_num_ddouble__lp__plus__rp_(_x_x756, tzdelta, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x758;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x759 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x759->since;
    int32_t _x_0_0 = _con_x759->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x758 = _x_0_0; /*int32*/
  }
  ts_10049 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x755, _x_x758, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_core_types__tuple2 _match_x503;
  kk_std_time_timestamp__timestamp _x_x760 = kk_std_time_timestamp__timestamp_dup(ts_10049, _ctx); /*std/time/timestamp/timestamp*/
  _match_x503 = kk_std_time_timestamp_days_seconds(_x_x760, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x138 = _match_x503.fst;
    kk_box_t _box_x139 = _match_x503.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x139, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x138, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x503, _ctx);
    kk_std_time_date__clock _match_x504;
    kk_integer_t _x_x761;
    int32_t _x_x762;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x763 = kk_std_time_timestamp__as_Timestamp(ts_10049, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x763->since;
      int32_t _x = _con_x763->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts_10049, _ctx)) {
        kk_datatype_ptr_free(ts_10049, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts_10049, _ctx);
      }
      _x_x762 = _x; /*int32*/
    }
    _x_x761 = kk_integer_from_int(_x_x762,kk_context()); /*int*/
    _match_x504 = kk_std_time_date_leap_fs_clock(secs, _x_x761, _ctx); /*std/time/date/clock*/
    {
      struct kk_std_time_date_Clock* _con_x764 = kk_std_time_date__as_Clock(_match_x504, _ctx);
      kk_std_time_date__date _b_x140_142 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date, (days_to_date, days_0, _ctx), _ctx); /*std/time/date/date*/;
      return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x140_142, _ctx), kk_std_time_date__clock_box(_match_x504, _ctx), _ctx);
    }
  }
}

kk_std_time_timestamp__timestamp kk_std_time_calendar_dc_timestamp(kk_std_time_date__date d, kk_std_time_date__clock c, kk_function_t date_to_days, kk_std_core_types__optional has_leap_seconds, kk_context_t* _ctx) { /* (d : std/time/date/date, c : std/time/date/clock, date-to-days : (std/time/date/date) -> int, has-leap-seconds : ? bool) -> std/time/timestamp/timestamp */ 
  kk_std_core_types__tuple2 _match_x500;
  if (kk_std_core_types__is_Optional(has_leap_seconds, _ctx)) {
    kk_box_t _box_x144 = has_leap_seconds._cons._Optional.value;
    bool _uniq_has_leap_seconds_1384 = kk_bool_unbox(_box_x144);
    kk_std_core_types__optional_drop(has_leap_seconds, _ctx);
    if (_uniq_has_leap_seconds_1384) {
      kk_std_num_ddouble__ddouble y_10055 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(60), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
      bool _match_x501;
      kk_std_core_types__order _x_x765;
      kk_std_core_types__order _match_x502;
      double _x_x766;
      {
        struct kk_std_time_date_Clock* _con_x767 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x767->seconds;
        {
          double _x_0 = _x_3.hi;
          _x_x766 = _x_0; /*float64*/
        }
      }
      double _x_x768;
      {
        double _x_0_0 = y_10055.hi;
        _x_x768 = _x_0_0; /*float64*/
      }
      _match_x502 = kk_std_num_float64_cmp(_x_x766, _x_x768, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x502, _ctx)) {
        double _x_x769;
        {
          struct kk_std_time_date_Clock* _con_x770 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x770->seconds;
          {
            double _x_1 = _x_3_0.lo;
            _x_x769 = _x_1; /*float64*/
          }
        }
        double _x_x771;
        {
          double _x_2 = y_10055.lo;
          _x_x771 = _x_2; /*float64*/
        }
        _x_x765 = kk_std_num_float64_cmp(_x_x769, _x_x771, _ctx); /*order*/
      }
      else {
        _x_x765 = _match_x502; /*order*/
      }
      _match_x501 = kk_std_core_order__lp__eq__eq__rp_(_x_x765, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
      if (_match_x501) {
        kk_box_t _x_x772;
        kk_std_num_ddouble__ddouble _x_x773;
        {
          struct kk_std_time_date_Clock* _con_x774 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_4 = _con_x774->seconds;
          _x_x773 = _x_4; /*std/num/ddouble/ddouble*/
        }
        _x_x772 = kk_std_num_ddouble__ddouble_box(_x_x773, _ctx); /*134*/
        _match_x500 = kk_std_core_types__new_Tuple2(_x_x772, kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*(134, 135)*/
      }
      else {
        kk_integer_t x_0_10059;
        kk_std_num_ddouble__ddouble _x_x775;
        kk_std_num_ddouble__ddouble _x_x776;
        {
          struct kk_std_time_date_Clock* _con_x777 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_5 = _con_x777->seconds;
          _x_x776 = _x_5; /*std/num/ddouble/ddouble*/
        }
        _x_x775 = kk_std_num_ddouble_floor(_x_x776, _ctx); /*std/num/ddouble/ddouble*/
        x_0_10059 = kk_std_num_ddouble_int(_x_x775, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
        kk_integer_t leap = kk_integer_add_small_const(x_0_10059, -59, _ctx); /*int*/;
        kk_std_num_ddouble__ddouble y_1_10063;
        kk_integer_t _x_x778 = kk_integer_dup(leap, _ctx); /*int*/
        y_1_10063 = kk_std_num_ddouble_ddouble_int_exp(_x_x778, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _b_x147_159;
        kk_std_num_ddouble__ddouble _x_x779;
        {
          struct kk_std_time_date_Clock* _con_x780 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_7 = _con_x780->seconds;
          _x_x779 = _x_7; /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x_x781;
        double _x_x782;
        double _x_x783;
        {
          double _x_6 = y_1_10063.hi;
          _x_x783 = _x_6; /*float64*/
        }
        _x_x782 = (-_x_x783); /*float64*/
        double _x_x784;
        double _x_x785;
        {
          double _x_0_1 = y_1_10063.lo;
          _x_x785 = _x_0_1; /*float64*/
        }
        _x_x784 = (-_x_x785); /*float64*/
        _x_x781 = kk_std_num_ddouble__new_Ddouble(_x_x782, _x_x784, _ctx); /*std/num/ddouble/ddouble*/
        _b_x147_159 = kk_std_num_ddouble__lp__plus__rp_(_x_x779, _x_x781, _ctx); /*std/num/ddouble/ddouble*/
        _match_x500 = kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x147_159, _ctx), kk_integer_box(leap, _ctx), _ctx); /*(134, 135)*/
      }
    }
    else {
      kk_box_t _x_x786;
      kk_std_num_ddouble__ddouble _x_x787;
      {
        struct kk_std_time_date_Clock* _con_x788 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x = _con_x788->seconds;
        _x_x787 = _x; /*std/num/ddouble/ddouble*/
      }
      _x_x786 = kk_std_num_ddouble__ddouble_box(_x_x787, _ctx); /*134*/
      _match_x500 = kk_std_core_types__new_Tuple2(_x_x786, kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*(134, 135)*/
    }
  }
  else {
    kk_std_core_types__optional_drop(has_leap_seconds, _ctx);
    kk_box_t _x_x789;
    kk_std_num_ddouble__ddouble _x_x790;
    {
      struct kk_std_time_date_Clock* _con_x791 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_8 = _con_x791->seconds;
      _x_x790 = _x_8; /*std/num/ddouble/ddouble*/
    }
    _x_x789 = kk_std_num_ddouble__ddouble_box(_x_x790, _ctx); /*134*/
    _match_x500 = kk_std_core_types__new_Tuple2(_x_x789, kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*(134, 135)*/
  }
  {
    kk_box_t _box_x153 = _match_x500.fst;
    kk_box_t _box_x154 = _match_x500.snd;
    kk_std_num_ddouble__ddouble xsecs = kk_std_num_ddouble__ddouble_unbox(_box_x153, KK_BORROWED, _ctx);
    kk_integer_t leap_0 = kk_integer_unbox(_box_x154, _ctx);
    kk_integer_dup(leap_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x500, _ctx);
    kk_integer_t x_2_10067;
    kk_integer_t _x_x792;
    {
      struct kk_std_time_date_Clock* _con_x793 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_8 = _con_x793->seconds;
      kk_integer_t _x_8_0 = _con_x793->hours;
      kk_integer_dup(_x_8_0, _ctx);
      _x_x792 = _x_8_0; /*int*/
    }
    x_2_10067 = kk_integer_mul(_x_x792,(kk_integer_from_small(60)),kk_context()); /*int*/
    kk_integer_t i_1_10066;
    kk_integer_t _x_x794;
    kk_integer_t _x_x795;
    {
      struct kk_std_time_date_Clock* _con_x796 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_9 = _con_x796->seconds;
      kk_integer_t _pat_0_9 = _con_x796->hours;
      kk_integer_t _x_9 = _con_x796->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_0_9, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_integer_dup(_x_9, _ctx);
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x795 = _x_9; /*int*/
    }
    _x_x794 = kk_integer_add(x_2_10067,_x_x795,kk_context()); /*int*/
    i_1_10066 = kk_integer_mul(_x_x794,(kk_integer_from_small(60)),kk_context()); /*int*/
    kk_std_num_ddouble__ddouble secs;
    kk_std_num_ddouble__ddouble _x_x797 = kk_std_num_ddouble_ddouble_int_exp(i_1_10066, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    secs = kk_std_num_ddouble__lp__plus__rp_(_x_x797, xsecs, _ctx); /*std/num/ddouble/ddouble*/
    kk_integer_t days = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), date_to_days, (date_to_days, d, _ctx), _ctx); /*int*/;
    kk_std_core_types__optional _x_x798 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x799 = kk_std_core_types__new_Optional(kk_integer_box(leap_0, _ctx), _ctx); /*? 7*/
    return kk_std_time_timestamp_timestamp_days(days, _x_x798, _x_x799, _ctx);
  }
}

bool kk_std_time_calendar_iso_is_leap(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> bool */ 
  bool _match_x492;
  kk_integer_t _brw_x498;
  kk_integer_t _x_x800 = kk_integer_dup(year, _ctx); /*int*/
  _brw_x498 = kk_integer_mod(_x_x800,(kk_integer_from_small(4)),kk_context()); /*int*/
  bool _brw_x499 = kk_integer_eq_borrow(_brw_x498,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x498, _ctx);
  _match_x492 = _brw_x499; /*bool*/
  if (_match_x492) {
    bool _match_x493;
    kk_integer_t _brw_x496;
    kk_integer_t _x_x801 = kk_integer_dup(year, _ctx); /*int*/
    _brw_x496 = kk_integer_mod(_x_x801,(kk_integer_from_small(100)),kk_context()); /*int*/
    bool _brw_x497 = kk_integer_neq_borrow(_brw_x496,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x496, _ctx);
    _match_x493 = _brw_x497; /*bool*/
    if (_match_x493) {
      kk_integer_drop(year, _ctx);
      return true;
    }
    {
      kk_integer_t _brw_x494 = kk_integer_mod(year,(kk_integer_from_small(400)),kk_context()); /*int*/;
      bool _brw_x495 = kk_integer_eq_borrow(_brw_x494,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x494, _ctx);
      return _brw_x495;
    }
  }
  {
    kk_integer_drop(year, _ctx);
    return false;
  }
}

kk_integer_t kk_std_time_calendar_iso_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx) { /* (year : int, month : int) -> int */ 
  bool is_before_march_10071 = kk_integer_lte_borrow(month,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_t adj;
  if (is_before_march_10071) {
    kk_integer_drop(year, _ctx);
    adj = kk_integer_from_small(0); /*int*/
  }
  else {
    bool _match_x490 = kk_std_time_calendar_iso_is_leap(year, _ctx); /*bool*/;
    if (_match_x490) {
      adj = kk_integer_from_small(1); /*int*/
    }
    else {
      adj = kk_integer_from_small(2); /*int*/
    }
  }
  kk_integer_t x_0_10075 = kk_integer_mul((kk_integer_from_small(367)),month,kk_context()); /*int*/;
  kk_integer_t x_10073;
  kk_integer_t _x_x802 = kk_integer_add_small_const(x_0_10075, -362, _ctx); /*int*/
  x_10073 = kk_integer_div(_x_x802,(kk_integer_from_small(12)),kk_context()); /*int*/
  return kk_integer_sub(x_10073,adj,kk_context());
}

kk_integer_t kk_std_time_calendar_iso_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx) { /* (year : int, doy : int) -> int */ 
  bool is_before_march_10077 = kk_integer_lte_borrow(doy,(kk_integer_from_small(58)),kk_context()); /*bool*/;
  kk_integer_t adj;
  if (is_before_march_10077) {
    kk_integer_drop(year, _ctx);
    adj = kk_integer_from_small(0); /*int*/
  }
  else {
    bool _match_x489 = kk_std_time_calendar_iso_is_leap(year, _ctx); /*bool*/;
    if (_match_x489) {
      adj = kk_integer_from_small(1); /*int*/
    }
    else {
      adj = kk_integer_from_small(2); /*int*/
    }
  }
  kk_integer_t x_10079;
  kk_integer_t _x_x803 = kk_integer_add(doy,adj,kk_context()); /*int*/
  x_10079 = kk_integer_mul((kk_integer_from_small(12)),_x_x803,kk_context()); /*int*/
  kk_integer_t _x_x804 = kk_integer_add_small_const(x_10079, 373, _ctx); /*int*/
  return kk_integer_div(_x_x804,(kk_integer_from_small(367)),kk_context());
}

kk_integer_t kk_std_time_calendar_iso_days_before_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> int */ 
  kk_integer_t y = kk_integer_add_small_const(year, -1, _ctx); /*int*/;
  kk_integer_t x_0_10086;
  kk_integer_t _x_x805 = kk_integer_dup(y, _ctx); /*int*/
  x_0_10086 = kk_integer_div(_x_x805,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t y_1_10087;
  kk_integer_t _x_x806 = kk_integer_dup(y, _ctx); /*int*/
  y_1_10087 = kk_integer_div(_x_x806,(kk_integer_from_small(100)),kk_context()); /*int*/
  kk_integer_t x_10084 = kk_integer_sub(x_0_10086,y_1_10087,kk_context()); /*int*/;
  kk_integer_t y_0_10085;
  kk_integer_t _x_x807 = kk_integer_dup(y, _ctx); /*int*/
  y_0_10085 = kk_integer_div(_x_x807,(kk_integer_from_small(400)),kk_context()); /*int*/
  kk_integer_t leapdays = kk_integer_add(x_10084,y_0_10085,kk_context()); /*int*/;
  kk_integer_t x_1_10088 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
  return kk_integer_add(x_1_10088,leapdays,kk_context());
}

kk_std_core_types__tuple2 kk_std_time_calendar_iso_estimate_year(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, maybe<int>) */ 
  kk_std_core_types__tuple2 _match_x488 = kk_std_core_int_divmod(days, kk_integer_from_int(146097, _ctx), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x167 = _match_x488.fst;
    kk_box_t _box_x168 = _match_x488.snd;
    kk_integer_t era = kk_integer_unbox(_box_x167, _ctx);
    kk_integer_t yoe = kk_integer_unbox(_box_x168, _ctx);
    kk_integer_dup(era, _ctx);
    kk_integer_dup(yoe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x488, _ctx);
    kk_integer_t y_0_10093 = kk_integer_mul((kk_integer_from_small(400)),era,kk_context()); /*int*/;
    kk_integer_t x_10090 = kk_integer_add_small_const(y_0_10093, 1, _ctx); /*int*/;
    kk_integer_t y_10091;
    kk_integer_t _x_x808 = kk_integer_mul((kk_integer_from_small(100)),yoe,kk_context()); /*int*/
    y_10091 = kk_integer_div(_x_x808,(kk_integer_from_int(36525, _ctx)),kk_context()); /*int*/
    kk_integer_t _b_x170_172 = kk_integer_add(x_10090,y_10091,kk_context()); /*int*/;
    kk_box_t _x_x809;
    kk_std_core_types__maybe _x_x810 = kk_std_core_types__new_Just(kk_integer_box(kk_integer_from_small(363), _ctx), _ctx); /*maybe<88>*/
    _x_x809 = kk_std_core_types__maybe_box(_x_x810, _ctx); /*135*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x170_172, _ctx), _x_x809, _ctx);
  }
}

kk_std_time_instant__instant kk_std_time_calendar_earth_timestamp_to_instant(kk_std_time_timestamp__timestamp t, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, tz : timezone, ts : std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_std_time_instant__instant i;
  kk_std_time_timestamp__timestamp _x_x811 = kk_std_time_timestamp__timestamp_dup(t, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x812 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
  i = kk_std_time_instant__new_Instant(_x_x811, _x_x812, _ctx); /*std/time/instant/instant*/
  bool _match_x484;
  kk_string_t _x_x813;
  {
    struct kk_std_time_calendar_Timezone* _con_x814 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x = _con_x814->name;
    kk_string_dup(_x, _ctx);
    _x_x813 = _x; /*string*/
  }
  kk_string_t _x_x815;
  kk_std_time_calendar__timezone _x_x816 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x817 = kk_std_time_calendar__as_Timezone(_x_x816, _ctx);
    kk_string_t _x_0 = _con_x817->name;
    _x_x815 = kk_string_dup(_x_0, _ctx); /*string*/
  }
  _match_x484 = kk_string_is_eq(_x_x813,_x_x815,kk_context()); /*bool*/
  if (_match_x484) {
    kk_datatype_ptr_dropn(tz, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
    kk_std_time_timestamp__timestamp_drop(t, _ctx);
    return i;
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x818 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _pat_0_2 = _con_x818->name;
    kk_function_t _pat_1_1 = _con_x818->utc_delta;
    kk_function_t _x_1 = _con_x818->utc_inverse;
    kk_function_dup(_x_1, _ctx);
    kk_std_core_types__maybe _match_x485;
    kk_std_time_instant__instant _x_x819 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    _match_x485 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_1, (_x_1, _x_x819, _ctx), _ctx); /*maybe<std/time/instant/instant>*/
    if (kk_std_core_types__is_Just(_match_x485, _ctx)) {
      kk_box_t _box_x175 = _match_x485._cons.Just.value;
      kk_std_time_instant__instant inv = kk_std_time_instant__instant_unbox(_box_x175, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
        kk_function_drop(_x_1, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(tz, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tz, _ctx);
      }
      kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
      kk_std_time_timestamp__timestamp_drop(t, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      kk_std_time_instant__instant_dup(inv, _ctx);
      kk_std_core_types__maybe_drop(_match_x485, _ctx);
      return inv;
    }
    {
      kk_std_core_types__tuple2 tuple2_10102;
      {
        struct kk_std_time_calendar_Timezone* _con_x820 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_function_t _x_3 = _con_x820->utc_delta;
        kk_function_dup(_x_3, _ctx);
        tuple2_10102 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_3, (_x_3, i, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      kk_std_time_timestamp__timestamp t_1_10105;
      kk_std_time_timestamp__timestamp _x_x821 = kk_std_time_timestamp__timestamp_dup(t, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_num_ddouble__ddouble _x_x822;
      {
        kk_box_t _box_x176 = tuple2_10102.fst;
        kk_box_t _box_x177 = tuple2_10102.snd;
        kk_std_time_duration__duration _x_2 = kk_std_time_duration__duration_unbox(_box_x176, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_4 = _x_2.secs;
          _x_x822 = _x_4; /*std/time/timestamp/timespan*/
        }
      }
      t_1_10105 = kk_std_time_timestamp__lp__dash__rp_(_x_x821, _x_x822, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__instant tzi1;
      kk_std_time_instant__timescale _x_x823 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
      tzi1 = kk_std_time_instant__new_Instant(t_1_10105, _x_x823, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_0_10107;
      {
        struct kk_std_time_calendar_Timezone* _con_x824 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_string_t _pat_0_7 = _con_x824->name;
        kk_function_t _x_6 = _con_x824->utc_delta;
        kk_function_t _pat_1_5 = _con_x824->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
          kk_function_drop(_pat_1_5, _ctx);
          kk_string_drop(_pat_0_7, _ctx);
          kk_datatype_ptr_free(tz, _ctx);
        }
        else {
          kk_function_dup(_x_6, _ctx);
          kk_datatype_ptr_decref(tz, _ctx);
        }
        kk_std_time_instant__instant _x_x825 = kk_std_time_instant__instant_dup(tzi1, _ctx); /*std/time/instant/instant*/
        tuple2_0_10107 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_6, (_x_6, _x_x825, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      bool _match_x486;
      kk_std_core_types__order _x_x826;
      kk_std_core_types__order _match_x487;
      double _x_x827;
      {
        kk_box_t _box_x178 = tuple2_10102.fst;
        kk_box_t _box_x179 = tuple2_10102.snd;
        kk_std_time_duration__duration _x_2_0 = kk_std_time_duration__duration_unbox(_box_x178, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_3_0 = _x_2_0.secs;
          {
            double _x_7 = _x_3_0.hi;
            _x_x827 = _x_7; /*float64*/
          }
        }
      }
      double _x_x828;
      {
        kk_box_t _box_x180 = tuple2_0_10107.fst;
        kk_box_t _box_x181 = tuple2_0_10107.snd;
        kk_std_time_duration__duration _x_5 = kk_std_time_duration__duration_unbox(_box_x180, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_4_0 = _x_5.secs;
          {
            double _x_0_0 = _x_4_0.hi;
            _x_x828 = _x_0_0; /*float64*/
          }
        }
      }
      _match_x487 = kk_std_num_float64_cmp(_x_x827, _x_x828, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x487, _ctx)) {
        double _x_x829;
        {
          kk_box_t _box_x182 = tuple2_10102.fst;
          kk_box_t _box_x183 = tuple2_10102.snd;
          kk_std_time_duration__duration _x_2_1 = kk_std_time_duration__duration_unbox(_box_x182, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_10102, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_3_0_0 = _x_2_1.secs;
            {
              double _x_1_0 = _x_3_0_0.lo;
              _x_x829 = _x_1_0; /*float64*/
            }
          }
        }
        double _x_x830;
        {
          kk_box_t _box_x184 = tuple2_0_10107.fst;
          kk_box_t _box_x185 = tuple2_0_10107.snd;
          kk_std_time_duration__duration _x_5_0 = kk_std_time_duration__duration_unbox(_box_x184, KK_BORROWED, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_4_0_0 = _x_5_0.secs;
            {
              double _x_2_0_0 = _x_4_0_0.lo;
              _x_x830 = _x_2_0_0; /*float64*/
            }
          }
        }
        _x_x826 = kk_std_num_float64_cmp(_x_x829, _x_x830, _ctx); /*order*/
      }
      else {
        kk_std_core_types__tuple2_drop(tuple2_10102, _ctx);
        _x_x826 = _match_x487; /*order*/
      }
      _match_x486 = kk_std_core_order__lp__eq__eq__rp_(_x_x826, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
      if (_match_x486) {
        kk_std_core_types__tuple2_drop(tuple2_0_10107, _ctx);
        kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
        kk_std_time_timestamp__timestamp_drop(t, _ctx);
        return tzi1;
      }
      {
        kk_std_time_instant__instant_drop(tzi1, _ctx);
        kk_std_time_timestamp__timestamp t_2_10112;
        kk_std_num_ddouble__ddouble _x_x831;
        {
          kk_box_t _box_x186 = tuple2_0_10107.fst;
          kk_box_t _box_x187 = tuple2_0_10107.snd;
          kk_std_time_duration__duration _x_5_1 = kk_std_time_duration__duration_unbox(_box_x186, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_0_10107, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_8 = _x_5_1.secs;
            _x_x831 = _x_8; /*std/time/timestamp/timespan*/
          }
        }
        t_2_10112 = kk_std_time_timestamp__lp__dash__rp_(t, _x_x831, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_instant__new_Instant(t_2_10112, ts, _ctx);
      }
    }
  }
}
 
// Create a calendar where we assume that each
// day has 24 hours with 60 minutes, and where minutes are 60 seconds
// (with possibly leap seconds). The function takes care of timezones,
// epoch shifts, and leap seconds, and only needs a calendar `name`,
// a function `days-to-date` to calculate a date given a number of days since the `epoch`,
// a function `date-to-days` to calculate days since the `epoch` for a given date,
// and an optional time scale to be used (=`ts-utc`).
// `month-prefix` (=`""`) is used when displaying numeric months and is set for
// the ISO week dates to `"W"` for example. The `show-era` function can be given
// to display the era of a date.


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun835__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x192;
};
static kk_string_t kk_std_time_calendar_earth_calendar_fun835(kk_function_t _fself, kk_std_time_date__date _b_x195, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun835(kk_box_t _fun_unbox_x192, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun835__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_earth_calendar_fun835__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_earth_calendar_fun835, kk_context());
  _self->_fun_unbox_x192 = _fun_unbox_x192;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_earth_calendar_fun835(kk_function_t _fself, kk_std_time_date__date _b_x195, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun835__t* _self = kk_function_as(struct kk_std_time_calendar_earth_calendar_fun835__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x192 = _self->_fun_unbox_x192; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x192, _ctx);}, {}, _ctx)
  kk_box_t _x_x836;
  kk_function_t _x_x837 = kk_function_unbox(_fun_unbox_x192, _ctx); /*(193) -> 194*/
  _x_x836 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x837, (_x_x837, kk_std_time_date__date_box(_b_x195, _ctx), _ctx), _ctx); /*194*/
  return kk_string_unbox(_x_x836);
}


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun838__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_time_calendar_earth_calendar_fun838(kk_function_t _fself, kk_std_time_date__date d, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun838(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_earth_calendar_fun838, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_std_time_calendar_earth_calendar_fun838(kk_function_t _fself, kk_std_time_date__date d, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_date__date_drop(d, _ctx);
  return kk_string_empty();
}


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun841__t {
  struct kk_function_s _base;
  kk_function_t days_to_date;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_earth_calendar_fun841(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun841(kk_function_t days_to_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun841__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_earth_calendar_fun841__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_earth_calendar_fun841, kk_context());
  _self->days_to_date = days_to_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_earth_calendar_fun841(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun841__t* _self = kk_function_as(struct kk_std_time_calendar_earth_calendar_fun841__t*, _fself, _ctx);
  kk_function_t days_to_date = _self->days_to_date; /* (days : int) -> std/time/date/date */
  kk_drop_match(_self, {kk_function_dup(days_to_date, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp ts_10049;
  kk_std_num_ddouble__ddouble _x_x842;
  kk_std_num_ddouble__ddouble _x_x843;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_0_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x844 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x845 = kk_std_time_instant__as_Timescale(_pat_2_0_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x846 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x_0 = _con_x846->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x843 = _x_0; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x847;
  {
    kk_std_num_ddouble__ddouble _x_0_1 = tzdelta.secs;
    _x_x847 = _x_0_1; /*std/time/timestamp/timespan*/
  }
  _x_x842 = kk_std_num_ddouble__lp__plus__rp_(_x_x843, _x_x847, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x848;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_0_2_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x849 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x850 = kk_std_time_instant__as_Timescale(_pat_2_0_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x851 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x851->since;
      int32_t _x_0_0 = _con_x851->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x848 = _x_0_0; /*int32*/
    }
  }
  ts_10049 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x842, _x_x848, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_core_types__tuple2 _match_x482;
  kk_std_time_timestamp__timestamp _x_x852 = kk_std_time_timestamp__timestamp_dup(ts_10049, _ctx); /*std/time/timestamp/timestamp*/
  _match_x482 = kk_std_time_timestamp_days_seconds(_x_x852, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x196 = _match_x482.fst;
    kk_box_t _box_x197 = _match_x482.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x197, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x196, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x482, _ctx);
    kk_std_time_date__clock _match_x483;
    kk_integer_t _x_x853;
    int32_t _x_x854;
    {
      struct kk_std_time_timestamp_Timestamp* _con_x855 = kk_std_time_timestamp__as_Timestamp(ts_10049, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_1 = _con_x855->since;
      int32_t _x = _con_x855->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(ts_10049, _ctx)) {
        kk_datatype_ptr_free(ts_10049, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts_10049, _ctx);
      }
      _x_x854 = _x; /*int32*/
    }
    _x_x853 = kk_integer_from_int(_x_x854,kk_context()); /*int*/
    _match_x483 = kk_std_time_date_leap_fs_clock(secs, _x_x853, _ctx); /*std/time/date/clock*/
    {
      struct kk_std_time_date_Clock* _con_x856 = kk_std_time_date__as_Clock(_match_x483, _ctx);
      kk_std_time_date__date _b_x198_208 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date, (days_to_date, days_0, _ctx), _ctx); /*std/time/date/date*/;
      return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x198_208, _ctx), kk_std_time_date__clock_box(_match_x483, _ctx), _ctx);
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun858__t {
  struct kk_function_s _base;
  kk_function_t date_to_days;
};
static kk_std_time_instant__instant kk_std_time_calendar_earth_calendar_fun858(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun858(kk_function_t date_to_days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun858__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_earth_calendar_fun858__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_earth_calendar_fun858, kk_context());
  _self->date_to_days = date_to_days;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_earth_calendar_fun858(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun858__t* _self = kk_function_as(struct kk_std_time_calendar_earth_calendar_fun858__t*, _fself, _ctx);
  kk_function_t date_to_days = _self->date_to_days; /* (std/time/date/date) -> int */
  kk_drop_match(_self, {kk_function_dup(date_to_days, _ctx);}, {}, _ctx)
  bool _b_x207_210;
  {
    struct kk_std_time_instant_Timescale* _con_x859 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_std_core_types__maybe _x_1_0_0 = _con_x859->mb_seconds_in_day;
    kk_std_core_types__maybe_dup(_x_1_0_0, _ctx);
    if (kk_std_core_types__is_Just(_x_1_0_0, _ctx)) {
      kk_std_core_types__maybe_drop(_x_1_0_0, _ctx);
      _b_x207_210 = true; /*bool*/
    }
    else {
      _b_x207_210 = false; /*bool*/
    }
  }
  kk_std_time_timestamp__timestamp _x_x860;
  kk_std_core_types__optional _x_x861 = kk_std_core_types__new_Optional(kk_bool_box(_b_x207_210), _ctx); /*? 7*/
  _x_x860 = kk_std_time_calendar_dc_timestamp(d_0_0, c, date_to_days, _x_x861, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_calendar_earth_timestamp_to_instant(_x_x860, tz, ts, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendar_earth_calendar(kk_string_t name, kk_string_t long_name, kk_function_t days_to_date, kk_function_t date_to_days, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, days-to-date : (days : int) -> std/time/date/date, date-to-days : (std/time/date/date) -> int, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_string_t _x_x832;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x188 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2782 = kk_string_unbox(_box_x188);
    kk_string_dup(_uniq_month_prefix_2782, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x832 = _uniq_month_prefix_2782; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x832 = kk_string_empty(); /*string*/
  }
  kk_function_t _x_x834;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x192 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x192, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x834 = kk_std_time_calendar_new_earth_calendar_fun835(_fun_unbox_x192, _ctx); /*(std/time/date/date) -> string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x834 = kk_std_time_calendar_new_earth_calendar_fun838(_ctx); /*(std/time/date/date) -> string*/
  }
  kk_function_t _x_x840;
  kk_function_dup(days_to_date, _ctx);
  _x_x840 = kk_std_time_calendar_new_earth_calendar_fun841(days_to_date, _ctx); /*(i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (134, 135)*/
  kk_function_t _x_x857;
  kk_function_dup(date_to_days, _ctx);
  _x_x857 = kk_std_time_calendar_new_earth_calendar_fun858(date_to_days, _ctx); /*(d@0@0 : std/time/date/date, c : std/time/date/clock, tz : std/time/calendar/timezone, ts : std/time/instant/timescale) -> std/time/instant/instant*/
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, name, long_name, _x_x832, _x_x834, _x_x840, _x_x857, days_to_date, date_to_days, _ctx);
}
 
// An abstraction over solar calendars. Almost all calendars can be defined
// in terms of this function (and `solar-ecalendar`). Given functions to
// convert days to and from a year, and day-of-the-year to and from month
// and month day, this constructs a full calendar.
// Also needs an `epoch-shift` that gives the number of days from the
// calendar epoch to the date ``2000-01-01``. By default this is `730119`
// which corresponds to a ``0001-01-01`` ISO calendar epoch. The
// `has-year-zero` (=`True`) parameter is used when the calendar has a
// year zero. The `month-prefix` (=`""`) is used for displaying numeric
// months (and is `"W"` for `cal-iso-week` for example). The `show-era` function
// can be given to display an era for a given date. Finally the `ts` (=`ts-ti`)
// gives the time scale for the calendar.


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun863__t {
  struct kk_function_s _base;
  kk_function_t days_before_month;
  kk_function_t days_to_month;
  kk_function_t days_to_yeardoy;
  kk_std_core_types__optional epoch_shift;
  kk_std_core_types__optional has_year_zero;
};
static kk_std_time_date__date kk_std_time_calendar_solar_calendar_fun863(kk_function_t _fself, kk_integer_t days0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun863(kk_function_t days_before_month, kk_function_t days_to_month, kk_function_t days_to_yeardoy, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun863__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun863__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun863, kk_context());
  _self->days_before_month = days_before_month;
  _self->days_to_month = days_to_month;
  _self->days_to_yeardoy = days_to_yeardoy;
  _self->epoch_shift = epoch_shift;
  _self->has_year_zero = has_year_zero;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_solar_calendar_fun863(kk_function_t _fself, kk_integer_t days0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun863__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun863__t*, _fself, _ctx);
  kk_function_t days_before_month = _self->days_before_month; /* (year : int, month : int) -> int */
  kk_function_t days_to_month = _self->days_to_month; /* (year : int, doy : int) -> int */
  kk_function_t days_to_yeardoy = _self->days_to_yeardoy; /* (days : int) -> (int, int) */
  kk_std_core_types__optional epoch_shift = _self->epoch_shift; /* ? int */
  kk_std_core_types__optional has_year_zero = _self->has_year_zero; /* ? bool */
  kk_drop_match(_self, {kk_function_dup(days_before_month, _ctx);kk_function_dup(days_to_month, _ctx);kk_function_dup(days_to_yeardoy, _ctx);kk_std_core_types__optional_dup(epoch_shift, _ctx);kk_std_core_types__optional_dup(has_year_zero, _ctx);}, {}, _ctx)
  kk_integer_t days;
  kk_integer_t _x_x864;
  if (kk_std_core_types__is_Optional(epoch_shift, _ctx)) {
    kk_box_t _box_x211 = epoch_shift._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2861 = kk_integer_unbox(_box_x211, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2861, _ctx);
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x864 = _uniq_epoch_shift_2861; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x864 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  days = kk_integer_add(days0,_x_x864,kk_context()); /*int*/
  kk_std_core_types__tuple2 _match_x480 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), days_to_yeardoy, (days_to_yeardoy, days, _ctx), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x212 = _match_x480.fst;
    kk_box_t _box_x213 = _match_x480.snd;
    kk_integer_t y_0 = kk_integer_unbox(_box_x212, _ctx);
    kk_integer_t doy = kk_integer_unbox(_box_x213, _ctx);
    kk_integer_dup(doy, _ctx);
    kk_integer_dup(y_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x480, _ctx);
    kk_integer_t month;
    kk_integer_t _x_x865 = kk_integer_dup(y_0, _ctx); /*int*/
    kk_integer_t _x_x866 = kk_integer_dup(doy, _ctx); /*int*/
    month = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_integer_t, kk_context_t*), days_to_month, (days_to_month, _x_x865, _x_x866, _ctx), _ctx); /*int*/
    kk_integer_t y_2_10122;
    kk_integer_t _x_x867 = kk_integer_dup(y_0, _ctx); /*int*/
    kk_integer_t _x_x868 = kk_integer_dup(month, _ctx); /*int*/
    y_2_10122 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_integer_t, kk_context_t*), days_before_month, (days_before_month, _x_x867, _x_x868, _ctx), _ctx); /*int*/
    kk_integer_t x_0_10119 = kk_integer_sub(doy,y_2_10122,kk_context()); /*int*/;
    kk_integer_t day = kk_integer_add_small_const(x_0_10119, 1, _ctx); /*int*/;
    kk_integer_t year;
    if (kk_std_core_types__is_Optional(has_year_zero, _ctx)) {
      kk_box_t _box_x214 = has_year_zero._cons._Optional.value;
      bool _uniq_has_year_zero_2865 = kk_bool_unbox(_box_x214);
      kk_std_core_types__optional_drop(has_year_zero, _ctx);
      if (_uniq_has_year_zero_2865) {
        year = y_0; /*int*/
      }
      else {
        bool _match_x481 = kk_integer_gt_borrow(y_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x481) {
          year = y_0; /*int*/
        }
        else {
          year = kk_integer_add_small_const(y_0, -1, _ctx); /*int*/
        }
      }
    }
    else {
      kk_std_core_types__optional_drop(has_year_zero, _ctx);
      year = y_0; /*int*/
    }
    return kk_std_time_date__new_Date(year, month, day, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun869__t {
  struct kk_function_s _base;
  kk_function_t days_before_month;
  kk_function_t days_before_year;
  kk_std_core_types__optional epoch_shift;
  kk_std_core_types__optional has_year_zero;
};
static kk_integer_t kk_std_time_calendar_solar_calendar_fun869(kk_function_t _fself, kk_std_time_date__date d_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun869(kk_function_t days_before_month, kk_function_t days_before_year, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun869__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun869__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun869, kk_context());
  _self->days_before_month = days_before_month;
  _self->days_before_year = days_before_year;
  _self->epoch_shift = epoch_shift;
  _self->has_year_zero = has_year_zero;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_solar_calendar_fun869(kk_function_t _fself, kk_std_time_date__date d_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun869__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun869__t*, _fself, _ctx);
  kk_function_t days_before_month = _self->days_before_month; /* (year : int, month : int) -> int */
  kk_function_t days_before_year = _self->days_before_year; /* (year : int) -> int */
  kk_std_core_types__optional epoch_shift = _self->epoch_shift; /* ? int */
  kk_std_core_types__optional has_year_zero = _self->has_year_zero; /* ? bool */
  kk_drop_match(_self, {kk_function_dup(days_before_month, _ctx);kk_function_dup(days_before_year, _ctx);kk_std_core_types__optional_dup(epoch_shift, _ctx);kk_std_core_types__optional_dup(has_year_zero, _ctx);}, {}, _ctx)
  kk_integer_t y_3;
  if (kk_std_core_types__is_Optional(has_year_zero, _ctx)) {
    kk_box_t _box_x215 = has_year_zero._cons._Optional.value;
    bool _uniq_has_year_zero_2865_0 = kk_bool_unbox(_box_x215);
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    if (_uniq_has_year_zero_2865_0) {
      kk_integer_t _x = d_0.year;
      kk_integer_dup(_x, _ctx);
      y_3 = _x; /*int*/
    }
    else {
      bool _match_x477;
      kk_integer_t _brw_x478;
      {
        kk_integer_t _x_0 = d_0.year;
        kk_integer_dup(_x_0, _ctx);
        _brw_x478 = _x_0; /*int*/
      }
      bool _brw_x479 = kk_integer_gt_borrow(_brw_x478,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x478, _ctx);
      _match_x477 = _brw_x479; /*bool*/
      if (_match_x477) {
        kk_integer_t _x_1 = d_0.year;
        kk_integer_dup(_x_1, _ctx);
        y_3 = _x_1; /*int*/
      }
      else {
        kk_integer_t _x_x870;
        {
          kk_integer_t _x_2 = d_0.year;
          kk_integer_dup(_x_2, _ctx);
          _x_x870 = _x_2; /*int*/
        }
        y_3 = kk_integer_add_small_const(_x_x870, 1, _ctx); /*int*/
      }
    }
  }
  else {
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    {
      kk_integer_t _x_3 = d_0.year;
      kk_integer_dup(_x_3, _ctx);
      y_3 = _x_3; /*int*/
    }
  }
  kk_integer_t x_4_10135;
  kk_integer_t _x_x871 = kk_integer_dup(y_3, _ctx); /*int*/
  x_4_10135 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_context_t*), days_before_year, (days_before_year, _x_x871, _ctx), _ctx); /*int*/
  kk_integer_t y_6_10136;
  kk_integer_t _x_x872;
  {
    kk_integer_t _x_3_0 = d_0.month;
    kk_integer_dup(_x_3_0, _ctx);
    _x_x872 = _x_3_0; /*int*/
  }
  y_6_10136 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_integer_t, kk_context_t*), days_before_month, (days_before_month, y_3, _x_x872, _ctx), _ctx); /*int*/
  kk_integer_t x_3_10133 = kk_integer_add(x_4_10135,y_6_10136,kk_context()); /*int*/;
  kk_integer_t y_5_10134;
  kk_integer_t _x_x873;
  {
    kk_integer_t _x_4 = d_0.day;
    kk_integer_dup(_x_4, _ctx);
    kk_std_time_date__date_drop(d_0, _ctx);
    _x_x873 = _x_4; /*int*/
  }
  y_5_10134 = kk_integer_add_small_const(_x_x873, -1, _ctx); /*int*/
  kk_integer_t x_2_10131 = kk_integer_add(x_3_10133,y_5_10134,kk_context()); /*int*/;
  kk_integer_t _x_x874;
  if (kk_std_core_types__is_Optional(epoch_shift, _ctx)) {
    kk_box_t _box_x216 = epoch_shift._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2861_0 = kk_integer_unbox(_box_x216, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2861_0, _ctx);
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x874 = _uniq_epoch_shift_2861_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x874 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  return kk_integer_sub(x_2_10131,_x_x874,kk_context());
}


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun880__t {
  struct kk_function_s _base;
  kk_std_core_types__optional show_era;
};
static kk_box_t kk_std_time_calendar_solar_calendar_fun880(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun880(kk_std_core_types__optional show_era, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun880__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun880__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun880, kk_context());
  _self->show_era = show_era;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_solar_calendar_fun880(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun880__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun880__t*, _fself, _ctx);
  kk_std_core_types__optional show_era = _self->show_era; /* ? ((std/time/date/date) -> string) */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(show_era, _ctx);}, {}, _ctx)
  kk_string_t _x_x881;
  kk_std_time_date__date _norm_x232 = kk_std_time_date__date_unbox(_b_x229, KK_OWNED, _ctx); /*std/time/date/date*/;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x222 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x222, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date _b_x225_233 = _norm_x232; /*std/time/date/date*/;
    kk_box_t _x_x882;
    kk_function_t _x_x883 = kk_function_unbox(_fun_unbox_x222, _ctx); /*(223) -> 224*/
    _x_x882 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x883, (_x_x883, kk_std_time_date__date_box(_b_x225_233, _ctx), _ctx), _ctx); /*224*/
    _x_x881 = kk_string_unbox(_x_x882); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date d_234 = _norm_x232; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_234, _ctx);
    _x_x881 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x881);
}

kk_std_time_calendar__calendar kk_std_time_calendar_solar_calendar(kk_string_t name, kk_string_t long_name, kk_function_t days_before_year, kk_function_t days_to_yeardoy, kk_function_t days_before_month, kk_function_t days_to_month, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, days-before-year : (year : int) -> int, days-to-yeardoy : (days : int) -> (int, int), days-before-month : (year : int, month : int) -> int, days-to-month : (year : int, doy : int) -> int, epoch-shift : ? int, has-year-zero : ? bool, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_function_t _x_x862;
  kk_function_dup(days_before_month, _ctx);
  kk_std_core_types__optional_dup(epoch_shift, _ctx);
  kk_std_core_types__optional_dup(has_year_zero, _ctx);
  _x_x862 = kk_std_time_calendar_new_solar_calendar_fun863(days_before_month, days_to_month, days_to_yeardoy, epoch_shift, has_year_zero, _ctx); /*(days0 : int) -> std/time/date/date*/
  kk_std_core_types__optional _x_x875;
  kk_box_t _x_x876;
  kk_string_t _x_x877;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x217 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2869 = kk_string_unbox(_box_x217);
    kk_string_dup(_uniq_month_prefix_2869, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x877 = _uniq_month_prefix_2869; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x877 = kk_string_empty(); /*string*/
  }
  _x_x876 = kk_string_box(_x_x877); /*7*/
  _x_x875 = kk_std_core_types__new_Optional(_x_x876, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x879 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_solar_calendar_fun880(show_era, _ctx), _ctx), _ctx); /*? 7*/
  return kk_std_time_calendar_earth_calendar(name, long_name, _x_x862, kk_std_time_calendar_new_solar_calendar_fun869(days_before_month, days_before_year, epoch_shift, has_year_zero, _ctx), _x_x875, _x_x879, _ctx);
}
 
// An abstraction over solar calendars. Almost all calendars can be defined
// in terms of this function (and `solar-calendar`). Given functions to
// convert days to and from a year, and day-of-the-year to and from month
// and month day, this constructs a full calendar. In contrast to `solar-calendar`
// this function just needs an estimation function from days to a year -- for most
// calendars this is much more convenient. The estimation function returns a
// conservative (i.e. lowest) estimate for the year and a `maybe<int>` that
// is the `safe-day`: if the day of the year is lower or equal to that the estimate
// is surely correct. Otherwise the wrapper will calculate the start day for the next
// year until the correct year is found.
// Also needs an `epoch-shift` that gives the number of days from the
// calendar epoch to the date ``2000-01-01``. By default this is `730119`
// which corresponds to a ``0001-01-01`` ISO calendar epoch. The
// `has-year-zero` (=`True`) parameter is used when the calendar has a
// year zero. The `month-prefix` (=`""`) is used for displaying numeric
// months (and is `"W"` for `cal-iso-week` for example). The `show-era` function
// can be given to display an era for a given date. Finally the `ts` (=`ts-utc`)
// gives the time scale for the calendar.


// lift anonymous function
struct kk_std_time_calendar_solar_ecalendar_fun886__t {
  struct kk_function_s _base;
  kk_function_t days_before_year;
  kk_function_t estimate_year;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_solar_ecalendar_fun886(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_ecalendar_fun886(kk_function_t days_before_year, kk_function_t estimate_year, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun886__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_ecalendar_fun886__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_ecalendar_fun886, kk_context());
  _self->days_before_year = days_before_year;
  _self->estimate_year = estimate_year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_solar_ecalendar_fun886(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun886__t* _self = kk_function_as(struct kk_std_time_calendar_solar_ecalendar_fun886__t*, _fself, _ctx);
  kk_function_t days_before_year = _self->days_before_year; /* (year : int) -> int */
  kk_function_t estimate_year = _self->estimate_year; /* (days : int) -> (int, maybe<int>) */
  kk_drop_match(_self, {kk_function_dup(days_before_year, _ctx);kk_function_dup(estimate_year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _match_x472;
  kk_integer_t _x_x887 = kk_integer_dup(days, _ctx); /*int*/
  _match_x472 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), estimate_year, (estimate_year, _x_x887, _ctx), _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x235 = _match_x472.fst;
    kk_box_t _box_x236 = _match_x472.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x235, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x236, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x472, _ctx);
    kk_integer_t y_10141;
    kk_function_t _x_x889 = kk_function_dup(days_before_year, _ctx); /*(year : int) -> int*/
    kk_integer_t _x_x888 = kk_integer_dup(approx, _ctx); /*int*/
    y_10141 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x889, (_x_x889, _x_x888, _ctx), _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x890 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x890,y_10141,kk_context()); /*int*/
    bool _match_x473;
    kk_integer_t _brw_x475;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x475 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x237 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x237, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x475 = x_0; /*int*/
    }
    bool _brw_x476 = kk_integer_lte_borrow(doy1,_brw_x475,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x475, _ctx);
    _match_x473 = _brw_x476; /*bool*/
    if (_match_x473) {
      kk_function_drop(days_before_year, _ctx);
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t y_0_10145;
      kk_integer_t _x_x891;
      kk_integer_t _x_x892 = kk_integer_dup(approx, _ctx); /*int*/
      _x_x891 = kk_integer_add_small_const(_x_x892, 1, _ctx); /*int*/
      y_0_10145 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_context_t*), days_before_year, (days_before_year, _x_x891, _ctx), _ctx); /*int*/
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10145,kk_context()); /*int*/;
      bool _match_x474 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x474) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x242_265 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x242_265, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_solar_ecalendar_fun904__t {
  struct kk_function_s _base;
  kk_std_core_types__optional show_era;
};
static kk_box_t kk_std_time_calendar_solar_ecalendar_fun904(kk_function_t _fself, kk_box_t _b_x260, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_ecalendar_fun904(kk_std_core_types__optional show_era, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun904__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_ecalendar_fun904__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_ecalendar_fun904, kk_context());
  _self->show_era = show_era;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_solar_ecalendar_fun904(kk_function_t _fself, kk_box_t _b_x260, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun904__t* _self = kk_function_as(struct kk_std_time_calendar_solar_ecalendar_fun904__t*, _fself, _ctx);
  kk_std_core_types__optional show_era = _self->show_era; /* ? ((std/time/date/date) -> string) */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(show_era, _ctx);}, {}, _ctx)
  kk_string_t _x_x905;
  kk_std_time_date__date _norm_x271 = kk_std_time_date__date_unbox(_b_x260, KK_OWNED, _ctx); /*std/time/date/date*/;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x253 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x253, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date _b_x256_272 = _norm_x271; /*std/time/date/date*/;
    kk_box_t _x_x906;
    kk_function_t _x_x907 = kk_function_unbox(_fun_unbox_x253, _ctx); /*(254) -> 255*/
    _x_x906 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x907, (_x_x907, kk_std_time_date__date_box(_b_x256_272, _ctx), _ctx), _ctx); /*255*/
    _x_x905 = kk_string_unbox(_x_x906); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date d_273 = _norm_x271; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_273, _ctx);
    _x_x905 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x905);
}

kk_std_time_calendar__calendar kk_std_time_calendar_solar_ecalendar(kk_string_t name, kk_string_t long_name, kk_function_t days_before_year, kk_function_t estimate_year, kk_function_t days_before_month, kk_function_t days_to_month, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, days-before-year : (year : int) -> int, estimate-year : (days : int) -> (int, maybe<int>), days-before-month : (year : int, month : int) -> int, days-to-month : (year : int, doy : int) -> int, epoch-shift : ? int, has-year-zero : ? bool, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_function_t _x_x885 = kk_function_dup(days_before_year, _ctx); /*(year : int) -> int*/
  kk_std_core_types__optional _x_x893;
  kk_box_t _x_x894;
  kk_integer_t _x_x895;
  if (kk_std_core_types__is_Optional(epoch_shift, _ctx)) {
    kk_box_t _box_x244 = epoch_shift._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2177 = kk_integer_unbox(_box_x244, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2177, _ctx);
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x895 = _uniq_epoch_shift_2177; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x895 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  _x_x894 = kk_integer_box(_x_x895, _ctx); /*7*/
  _x_x893 = kk_std_core_types__new_Optional(_x_x894, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x896;
  kk_box_t _x_x897;
  bool _x_x898;
  if (kk_std_core_types__is_Optional(has_year_zero, _ctx)) {
    kk_box_t _box_x246 = has_year_zero._cons._Optional.value;
    bool _uniq_has_year_zero_2181 = kk_bool_unbox(_box_x246);
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    _x_x898 = _uniq_has_year_zero_2181; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    _x_x898 = true; /*bool*/
  }
  _x_x897 = kk_bool_box(_x_x898); /*7*/
  _x_x896 = kk_std_core_types__new_Optional(_x_x897, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x899;
  kk_box_t _x_x900;
  kk_string_t _x_x901;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x248 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2185 = kk_string_unbox(_box_x248);
    kk_string_dup(_uniq_month_prefix_2185, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x901 = _uniq_month_prefix_2185; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x901 = kk_string_empty(); /*string*/
  }
  _x_x900 = kk_string_box(_x_x901); /*7*/
  _x_x899 = kk_std_core_types__new_Optional(_x_x900, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x903 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_solar_ecalendar_fun904(show_era, _ctx), _ctx), _ctx); /*? 7*/
  return kk_std_time_calendar_solar_calendar(name, long_name, _x_x885, kk_std_time_calendar_new_solar_ecalendar_fun886(days_before_year, estimate_year, _ctx), days_before_month, days_to_month, _x_x893, _x_x896, _x_x899, _x_x903, _ctx);
}
 
// Create a standard ISO calendar using a particular time scale
// and calendar `name` (=`ts.name`).


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun912__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_iso_calendar_fun912(kk_function_t _fself, kk_integer_t _x1_x911, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun912(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun912, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_iso_calendar_fun912(kk_function_t _fself, kk_integer_t _x1_x911, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x911, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun914__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_iso_calendar_fun914(kk_function_t _fself, kk_integer_t _x1_x913, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun914(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun914, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_iso_calendar_fun914(kk_function_t _fself, kk_integer_t _x1_x913, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_estimate_year(_x1_x913, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun917__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_iso_calendar_fun917(kk_function_t _fself, kk_integer_t _x1_x915, kk_integer_t _x2_x916, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun917(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun917, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_iso_calendar_fun917(kk_function_t _fself, kk_integer_t _x1_x915, kk_integer_t _x2_x916, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x915, _x2_x916, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun920__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_iso_calendar_fun920(kk_function_t _fself, kk_integer_t _x1_x918, kk_integer_t _x2_x919, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun920(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun920, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_iso_calendar_fun920(kk_function_t _fself, kk_integer_t _x1_x918, kk_integer_t _x2_x919, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x918, _x2_x919, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendar_iso_calendar(kk_std_time_instant__timescale ___wildcard_x422__23, kk_string_t name, kk_std_core_types__optional long_name, kk_context_t* _ctx) { /* (std/time/instant/timescale, name : string, long-name : ? string) -> calendar */ 
  kk_datatype_ptr_dropn(___wildcard_x422__23, (KK_I32(10)), _ctx);
  kk_string_t _x_x909 = kk_string_dup(name, _ctx); /*string*/
  kk_string_t _x_x910;
  if (kk_std_core_types__is_Optional(long_name, _ctx)) {
    kk_box_t _box_x274 = long_name._cons._Optional.value;
    kk_string_t _uniq_long_name_2422 = kk_string_unbox(_box_x274);
    kk_string_drop(name, _ctx);
    kk_string_dup(_uniq_long_name_2422, _ctx);
    kk_std_core_types__optional_drop(long_name, _ctx);
    _x_x910 = _uniq_long_name_2422; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(long_name, _ctx);
    _x_x910 = name; /*string*/
  }
  return kk_std_time_calendar_solar_ecalendar(_x_x909, _x_x910, kk_std_time_calendar_new_iso_calendar_fun912(_ctx), kk_std_time_calendar_new_iso_calendar_fun914(_ctx), kk_std_time_calendar_new_iso_calendar_fun917(_ctx), kk_std_time_calendar_new_iso_calendar_fun920(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// The standard [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) calendar
// using TI time (`ts-ti`). This is a proleptic Gregorian
// calendar except that it uses the year 0 for 1 BCE, -1 for 2 BCE etc.
//
// This is the default calendar used in the library as it guarantees deterministic
// date calculations while still taking historical leap seconds into account.


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun926__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_fun926(kk_function_t _fself, kk_integer_t _x1_x925, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun926(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun926, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_fun926(kk_function_t _fself, kk_integer_t _x1_x925, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x925, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun928__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_fun928(kk_function_t _fself, kk_integer_t _x1_x927, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun928(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun928, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_fun928(kk_function_t _fself, kk_integer_t _x1_x927, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_estimate_year(_x1_x927, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun931__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_fun931(kk_function_t _fself, kk_integer_t _x1_x929, kk_integer_t _x2_x930, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun931(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun931, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_fun931(kk_function_t _fself, kk_integer_t _x1_x929, kk_integer_t _x2_x930, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x929, _x2_x930, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun934__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_fun934(kk_function_t _fself, kk_integer_t _x1_x932, kk_integer_t _x2_x933, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun934(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun934, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_fun934(kk_function_t _fself, kk_integer_t _x1_x932, kk_integer_t _x2_x933, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x932, _x2_x933, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_iso;
 
// Return the instant in time for a given `:date` and `:clock` (= `clock0`) interpreted by
// calendar `cal` (=`cal-iso`) in a timezone `tz` (=`tz-utc` by default).

kk_std_time_instant__instant kk_std_time_calendar_date_fs_instant(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, tz : ? timezone, cal : ? calendar) -> std/time/instant/instant */ 
  kk_std_time_calendar__calendar _match_x471;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x275 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2480 = kk_std_time_calendar__calendar_unbox(_box_x275, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2480, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x471 = _uniq_cal_2480; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x471 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x935 = kk_std_time_calendar__as_Calendar(_match_x471, _ctx);
    kk_string_t _pat_0 = _con_x935->name;
    kk_string_t _pat_1 = _con_x935->long_name;
    kk_string_t _pat_2 = _con_x935->month_prefix;
    kk_function_t _pat_3 = _con_x935->show_era;
    kk_function_t _pat_4 = _con_x935->instant_to_dc;
    kk_function_t _x = _con_x935->dc_to_instant;
    kk_function_t _pat_5 = _con_x935->days_to_date;
    kk_function_t _pat_6 = _con_x935->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x471, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x471, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x471, _ctx);
    }
    kk_std_time_date__clock _x_x936;
    if (kk_std_core_types__is_Optional(c, _ctx)) {
      kk_box_t _box_x276 = c._cons._Optional.value;
      kk_std_time_date__clock _uniq_c_2472 = kk_std_time_date__clock_unbox(_box_x276, KK_BORROWED, _ctx);
      kk_std_time_date__clock_dup(_uniq_c_2472, _ctx);
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x936 = _uniq_c_2472; /*std/time/date/clock*/
    }
    else {
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x936 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    }
    kk_std_time_calendar__timezone _x_x937;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x277 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_2476 = kk_std_time_calendar__timezone_unbox(_box_x277, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_2476, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x937 = _uniq_tz_2476; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x937 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    return kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x936, _x_x937, ts, _ctx), _ctx);
  }
}
 
// /* Return the instant in time for a given date and clock interpreted by
//    calendar `cal` (=`cal-iso`) in a timezone `tz` (=`tz-utc` by default).
// 
//   The `month`, `day`, `hour`, `minutes` may be outside their usual ranges
//   and will be normalized during the conversion. For example, January 33 converts to February 2.
//   This makes it very easy to add- or subtract days or months to an existing time.
//   When the `seconds` or fraction of seconds `frac` add up over 60 those extra seconds are
//   interpreted as leap seconds.
// 
//   Due to timezone transitions, or leap seconds, it is possible to specify dates that never
//   happened (as it was skipped by a timezone change), or ambiguous times (as a timezone springs back).
//   In such cases, the time is always interpreted in the earlier timezone.
// */

kk_std_time_instant__instant kk_std_time_calendar_timescale_fs_instant(kk_std_time_instant__timescale tscale, kk_integer_t year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (tscale : std/time/instant/timescale, year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? int, frac : ? float64, tz : ? timezone, cal : ? calendar) -> std/time/instant/instant */ 
  kk_std_num_ddouble__ddouble fsecs;
  kk_std_num_ddouble__ddouble _x_x938;
  kk_integer_t _x_x939;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x278 = seconds._cons._Optional.value;
    kk_integer_t _uniq_seconds_3084 = kk_integer_unbox(_box_x278, _ctx);
    kk_integer_dup(_uniq_seconds_3084, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x939 = _uniq_seconds_3084; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x939 = kk_integer_from_small(0); /*int*/
  }
  _x_x938 = kk_std_num_ddouble_ddouble_int_exp(_x_x939, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x940;
  double _x_x941;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x279 = frac._cons._Optional.value;
    double _uniq_frac_3088 = kk_double_unbox(_box_x279, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x941 = _uniq_frac_3088; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x941 = 0x0p+0; /*float64*/
  }
  _x_x940 = kk_std_num_ddouble__new_Ddouble(_x_x941, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  fsecs = kk_std_num_ddouble__lp__plus__rp_(_x_x938, _x_x940, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_time_calendar__calendar _match_x470;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x280 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3096 = kk_std_time_calendar__calendar_unbox(_box_x280, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3096, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x470 = _uniq_cal_3096; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x470 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x942 = kk_std_time_calendar__as_Calendar(_match_x470, _ctx);
    kk_string_t _pat_0 = _con_x942->name;
    kk_string_t _pat_1 = _con_x942->long_name;
    kk_string_t _pat_2 = _con_x942->month_prefix;
    kk_function_t _pat_3 = _con_x942->show_era;
    kk_function_t _pat_4 = _con_x942->instant_to_dc;
    kk_function_t _x = _con_x942->dc_to_instant;
    kk_function_t _pat_5 = _con_x942->days_to_date;
    kk_function_t _pat_6 = _con_x942->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x470, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x470, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x470, _ctx);
    }
    kk_std_time_date__date _x_x943;
    kk_integer_t _x_x944;
    if (kk_std_core_types__is_Optional(month, _ctx)) {
      kk_box_t _box_x281 = month._cons._Optional.value;
      kk_integer_t _uniq_month_3068 = kk_integer_unbox(_box_x281, _ctx);
      kk_integer_dup(_uniq_month_3068, _ctx);
      kk_std_core_types__optional_drop(month, _ctx);
      _x_x944 = _uniq_month_3068; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(month, _ctx);
      _x_x944 = kk_integer_from_small(1); /*int*/
    }
    kk_integer_t _x_x945;
    if (kk_std_core_types__is_Optional(day, _ctx)) {
      kk_box_t _box_x282 = day._cons._Optional.value;
      kk_integer_t _uniq_day_3072 = kk_integer_unbox(_box_x282, _ctx);
      kk_integer_dup(_uniq_day_3072, _ctx);
      kk_std_core_types__optional_drop(day, _ctx);
      _x_x945 = _uniq_day_3072; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(day, _ctx);
      _x_x945 = kk_integer_from_small(1); /*int*/
    }
    _x_x943 = kk_std_time_date__new_Date(year, _x_x944, _x_x945, _ctx); /*std/time/date/date*/
    kk_std_time_date__clock _x_x946;
    kk_integer_t _x_x947;
    if (kk_std_core_types__is_Optional(hours, _ctx)) {
      kk_box_t _box_x283 = hours._cons._Optional.value;
      kk_integer_t _uniq_hours_3076 = kk_integer_unbox(_box_x283, _ctx);
      kk_integer_dup(_uniq_hours_3076, _ctx);
      kk_std_core_types__optional_drop(hours, _ctx);
      _x_x947 = _uniq_hours_3076; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(hours, _ctx);
      _x_x947 = kk_integer_from_small(0); /*int*/
    }
    kk_integer_t _x_x948;
    if (kk_std_core_types__is_Optional(minutes, _ctx)) {
      kk_box_t _box_x284 = minutes._cons._Optional.value;
      kk_integer_t _uniq_minutes_3080 = kk_integer_unbox(_box_x284, _ctx);
      kk_integer_dup(_uniq_minutes_3080, _ctx);
      kk_std_core_types__optional_drop(minutes, _ctx);
      _x_x948 = _uniq_minutes_3080; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(minutes, _ctx);
      _x_x948 = kk_integer_from_small(0); /*int*/
    }
    _x_x946 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x947, _x_x948, fsecs, _ctx); /*std/time/date/clock*/
    kk_std_time_calendar__timezone _x_x949;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x285 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3092 = kk_std_time_calendar__timezone_unbox(_box_x285, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3092, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x949 = _uniq_tz_3092; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x949 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    return kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, _x_x943, _x_x946, _x_x949, tscale, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951__t {
  struct kk_function_s _base;
  kk_std_time_instant__timescale _c_x10227;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours;
  kk_std_core_types__optional minutes;
  kk_std_core_types__optional month;
  kk_std_core_types__optional seconds;
  kk_std_core_types__optional tz;
  kk_integer_t year;
};
static kk_box_t kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utc_fs__new_mlift_instant_10252_fun951(kk_std_time_instant__timescale _c_x10227, kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951__t, 19, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951, kk_context());
  _self->_c_x10227 = _c_x10227;
  _self->cal = cal;
  _self->day = day;
  _self->frac = frac;
  _self->hours = hours;
  _self->minutes = minutes;
  _self->month = month;
  _self->seconds = seconds;
  _self->tz = tz;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951__t* _self = kk_function_as(struct kk_std_time_calendar_utc_fs__mlift_instant_10252_fun951__t*, _fself, _ctx);
  kk_std_time_instant__timescale _c_x10227 = _self->_c_x10227; /* std/time/instant/timescale */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day = _self->day; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours = _self->hours; /* ? int */
  kk_std_core_types__optional minutes = _self->minutes; /* ? int */
  kk_std_core_types__optional month = _self->month; /* ? int */
  kk_std_core_types__optional seconds = _self->seconds; /* ? int */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_time_instant__timescale_dup(_c_x10227, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours, _ctx);kk_std_core_types__optional_dup(minutes, _ctx);kk_std_core_types__optional_dup(month, _ctx);kk_std_core_types__optional_dup(seconds, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant _x_x952;
  kk_std_core_types__optional _x_x953;
  kk_box_t _x_x954;
  kk_integer_t _x_x955;
  if (kk_std_core_types__is_Optional(month, _ctx)) {
    kk_box_t _box_x286 = month._cons._Optional.value;
    kk_integer_t _uniq_month_3166 = kk_integer_unbox(_box_x286, _ctx);
    kk_integer_dup(_uniq_month_3166, _ctx);
    kk_std_core_types__optional_drop(month, _ctx);
    _x_x955 = _uniq_month_3166; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month, _ctx);
    _x_x955 = kk_integer_from_small(1); /*int*/
  }
  _x_x954 = kk_integer_box(_x_x955, _ctx); /*7*/
  _x_x953 = kk_std_core_types__new_Optional(_x_x954, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x956;
  kk_box_t _x_x957;
  kk_integer_t _x_x958;
  if (kk_std_core_types__is_Optional(day, _ctx)) {
    kk_box_t _box_x288 = day._cons._Optional.value;
    kk_integer_t _uniq_day_3170 = kk_integer_unbox(_box_x288, _ctx);
    kk_integer_dup(_uniq_day_3170, _ctx);
    kk_std_core_types__optional_drop(day, _ctx);
    _x_x958 = _uniq_day_3170; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day, _ctx);
    _x_x958 = kk_integer_from_small(1); /*int*/
  }
  _x_x957 = kk_integer_box(_x_x958, _ctx); /*7*/
  _x_x956 = kk_std_core_types__new_Optional(_x_x957, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x959;
  kk_box_t _x_x960;
  kk_integer_t _x_x961;
  if (kk_std_core_types__is_Optional(hours, _ctx)) {
    kk_box_t _box_x290 = hours._cons._Optional.value;
    kk_integer_t _uniq_hours_3174 = kk_integer_unbox(_box_x290, _ctx);
    kk_integer_dup(_uniq_hours_3174, _ctx);
    kk_std_core_types__optional_drop(hours, _ctx);
    _x_x961 = _uniq_hours_3174; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours, _ctx);
    _x_x961 = kk_integer_from_small(0); /*int*/
  }
  _x_x960 = kk_integer_box(_x_x961, _ctx); /*7*/
  _x_x959 = kk_std_core_types__new_Optional(_x_x960, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x962;
  kk_box_t _x_x963;
  kk_integer_t _x_x964;
  if (kk_std_core_types__is_Optional(minutes, _ctx)) {
    kk_box_t _box_x292 = minutes._cons._Optional.value;
    kk_integer_t _uniq_minutes_3178 = kk_integer_unbox(_box_x292, _ctx);
    kk_integer_dup(_uniq_minutes_3178, _ctx);
    kk_std_core_types__optional_drop(minutes, _ctx);
    _x_x964 = _uniq_minutes_3178; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes, _ctx);
    _x_x964 = kk_integer_from_small(0); /*int*/
  }
  _x_x963 = kk_integer_box(_x_x964, _ctx); /*7*/
  _x_x962 = kk_std_core_types__new_Optional(_x_x963, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x965;
  kk_box_t _x_x966;
  kk_integer_t _x_x967;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x294 = seconds._cons._Optional.value;
    kk_integer_t _uniq_seconds_3182 = kk_integer_unbox(_box_x294, _ctx);
    kk_integer_dup(_uniq_seconds_3182, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x967 = _uniq_seconds_3182; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x967 = kk_integer_from_small(0); /*int*/
  }
  _x_x966 = kk_integer_box(_x_x967, _ctx); /*7*/
  _x_x965 = kk_std_core_types__new_Optional(_x_x966, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x968;
  kk_box_t _x_x969;
  double _x_x970;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x296 = frac._cons._Optional.value;
    double _uniq_frac_3186 = kk_double_unbox(_box_x296, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x970 = _uniq_frac_3186; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x970 = 0x0p+0; /*float64*/
  }
  _x_x969 = kk_double_box(_x_x970, _ctx); /*7*/
  _x_x968 = kk_std_core_types__new_Optional(_x_x969, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x971;
  kk_box_t _x_x972;
  kk_std_time_calendar__timezone _x_x973;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x298 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3190 = kk_std_time_calendar__timezone_unbox(_box_x298, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3190, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x973 = _uniq_tz_3190; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x973 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x972 = kk_std_time_calendar__timezone_box(_x_x973, _ctx); /*7*/
  _x_x971 = kk_std_core_types__new_Optional(_x_x972, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x974;
  kk_box_t _x_x975;
  kk_std_time_calendar__calendar _x_x976;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x300 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3194 = kk_std_time_calendar__calendar_unbox(_box_x300, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3194, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x976 = _uniq_cal_3194; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x976 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x975 = kk_std_time_calendar__calendar_box(_x_x976, _ctx); /*7*/
  _x_x974 = kk_std_core_types__new_Optional(_x_x975, _ctx); /*? 7*/
  _x_x952 = kk_std_time_calendar_timescale_fs_instant(_c_x10227, year, _x_x953, _x_x956, _x_x959, _x_x962, _x_x965, _x_x968, _x_x971, _x_x974, _ctx); /*std/time/instant/instant*/
  return kk_std_time_instant__instant_box(_x_x952, _ctx);
}

kk_std_time_instant__instant kk_std_time_calendar_utc_fs__mlift_instant_10252(kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_integer_t year, kk_std_time_instant__timescale _c_x10227, kk_context_t* _ctx) { /* (cal : ? calendar, day : ? int, frac : ? float64, hours : ? int, minutes : ? int, month : ? int, seconds : ? int, tz : ? timezone, year : int, std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_box_t _x_x950 = kk_std_core_hnd__open_none0(kk_std_time_calendar_utc_fs__new_mlift_instant_10252_fun951(_c_x10227, cal, day, frac, hours, minutes, month, seconds, tz, year, _ctx), _ctx); /*9836*/
  return kk_std_time_instant__instant_unbox(_x_x950, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_utc_fs_instant_fun980__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours;
  kk_std_core_types__optional minutes;
  kk_std_core_types__optional month;
  kk_std_core_types__optional seconds;
  kk_std_core_types__optional tz;
  kk_integer_t year;
};
static kk_box_t kk_std_time_calendar_utc_fs_instant_fun980(kk_function_t _fself, kk_box_t _b_x320, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utc_fs_new_instant_fun980(kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs_instant_fun980__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utc_fs_instant_fun980__t, 18, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utc_fs_instant_fun980, kk_context());
  _self->cal = cal;
  _self->day = day;
  _self->frac = frac;
  _self->hours = hours;
  _self->minutes = minutes;
  _self->month = month;
  _self->seconds = seconds;
  _self->tz = tz;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utc_fs_instant_fun980(kk_function_t _fself, kk_box_t _b_x320, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs_instant_fun980__t* _self = kk_function_as(struct kk_std_time_calendar_utc_fs_instant_fun980__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day = _self->day; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours = _self->hours; /* ? int */
  kk_std_core_types__optional minutes = _self->minutes; /* ? int */
  kk_std_core_types__optional month = _self->month; /* ? int */
  kk_std_core_types__optional seconds = _self->seconds; /* ? int */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours, _ctx);kk_std_core_types__optional_dup(minutes, _ctx);kk_std_core_types__optional_dup(month, _ctx);kk_std_core_types__optional_dup(seconds, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10227_348 = kk_std_time_instant__timescale_unbox(_b_x320, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x981 = kk_std_time_calendar_utc_fs__mlift_instant_10252(cal, day, frac, hours, minutes, month, seconds, tz, year, _c_x10227_348, _ctx); /*std/time/instant/instant*/
  return kk_std_time_instant__instant_box(_x_x981, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_utc_fs_instant_fun982__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours;
  kk_std_core_types__optional minutes;
  kk_std_core_types__optional month;
  kk_std_core_types__optional seconds;
  kk_std_core_types__optional tz;
  kk_std_time_instant__timescale x_10254;
  kk_integer_t year;
};
static kk_box_t kk_std_time_calendar_utc_fs_instant_fun982(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utc_fs_new_instant_fun982(kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_std_time_instant__timescale x_10254, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs_instant_fun982__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utc_fs_instant_fun982__t, 19, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utc_fs_instant_fun982, kk_context());
  _self->cal = cal;
  _self->day = day;
  _self->frac = frac;
  _self->hours = hours;
  _self->minutes = minutes;
  _self->month = month;
  _self->seconds = seconds;
  _self->tz = tz;
  _self->x_10254 = x_10254;
  _self->year = year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utc_fs_instant_fun982(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs_instant_fun982__t* _self = kk_function_as(struct kk_std_time_calendar_utc_fs_instant_fun982__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day = _self->day; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours = _self->hours; /* ? int */
  kk_std_core_types__optional minutes = _self->minutes; /* ? int */
  kk_std_core_types__optional month = _self->month; /* ? int */
  kk_std_core_types__optional seconds = _self->seconds; /* ? int */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_std_time_instant__timescale x_10254 = _self->x_10254; /* std/time/instant/timescale */
  kk_integer_t year = _self->year; /* int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours, _ctx);kk_std_core_types__optional_dup(minutes, _ctx);kk_std_core_types__optional_dup(month, _ctx);kk_std_core_types__optional_dup(seconds, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_std_time_instant__timescale_dup(x_10254, _ctx);kk_integer_dup(year, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant _x_x983;
  kk_std_core_types__optional _x_x984;
  kk_box_t _x_x985;
  kk_integer_t _x_x986;
  if (kk_std_core_types__is_Optional(month, _ctx)) {
    kk_box_t _box_x321 = month._cons._Optional.value;
    kk_integer_t _uniq_month_3166 = kk_integer_unbox(_box_x321, _ctx);
    kk_integer_dup(_uniq_month_3166, _ctx);
    kk_std_core_types__optional_drop(month, _ctx);
    _x_x986 = _uniq_month_3166; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month, _ctx);
    _x_x986 = kk_integer_from_small(1); /*int*/
  }
  _x_x985 = kk_integer_box(_x_x986, _ctx); /*7*/
  _x_x984 = kk_std_core_types__new_Optional(_x_x985, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x987;
  kk_box_t _x_x988;
  kk_integer_t _x_x989;
  if (kk_std_core_types__is_Optional(day, _ctx)) {
    kk_box_t _box_x323 = day._cons._Optional.value;
    kk_integer_t _uniq_day_3170 = kk_integer_unbox(_box_x323, _ctx);
    kk_integer_dup(_uniq_day_3170, _ctx);
    kk_std_core_types__optional_drop(day, _ctx);
    _x_x989 = _uniq_day_3170; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day, _ctx);
    _x_x989 = kk_integer_from_small(1); /*int*/
  }
  _x_x988 = kk_integer_box(_x_x989, _ctx); /*7*/
  _x_x987 = kk_std_core_types__new_Optional(_x_x988, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x990;
  kk_box_t _x_x991;
  kk_integer_t _x_x992;
  if (kk_std_core_types__is_Optional(hours, _ctx)) {
    kk_box_t _box_x325 = hours._cons._Optional.value;
    kk_integer_t _uniq_hours_3174 = kk_integer_unbox(_box_x325, _ctx);
    kk_integer_dup(_uniq_hours_3174, _ctx);
    kk_std_core_types__optional_drop(hours, _ctx);
    _x_x992 = _uniq_hours_3174; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours, _ctx);
    _x_x992 = kk_integer_from_small(0); /*int*/
  }
  _x_x991 = kk_integer_box(_x_x992, _ctx); /*7*/
  _x_x990 = kk_std_core_types__new_Optional(_x_x991, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x993;
  kk_box_t _x_x994;
  kk_integer_t _x_x995;
  if (kk_std_core_types__is_Optional(minutes, _ctx)) {
    kk_box_t _box_x327 = minutes._cons._Optional.value;
    kk_integer_t _uniq_minutes_3178 = kk_integer_unbox(_box_x327, _ctx);
    kk_integer_dup(_uniq_minutes_3178, _ctx);
    kk_std_core_types__optional_drop(minutes, _ctx);
    _x_x995 = _uniq_minutes_3178; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes, _ctx);
    _x_x995 = kk_integer_from_small(0); /*int*/
  }
  _x_x994 = kk_integer_box(_x_x995, _ctx); /*7*/
  _x_x993 = kk_std_core_types__new_Optional(_x_x994, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x996;
  kk_box_t _x_x997;
  kk_integer_t _x_x998;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x329 = seconds._cons._Optional.value;
    kk_integer_t _uniq_seconds_3182 = kk_integer_unbox(_box_x329, _ctx);
    kk_integer_dup(_uniq_seconds_3182, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x998 = _uniq_seconds_3182; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x998 = kk_integer_from_small(0); /*int*/
  }
  _x_x997 = kk_integer_box(_x_x998, _ctx); /*7*/
  _x_x996 = kk_std_core_types__new_Optional(_x_x997, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x999;
  kk_box_t _x_x1000;
  double _x_x1001;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x331 = frac._cons._Optional.value;
    double _uniq_frac_3186 = kk_double_unbox(_box_x331, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1001 = _uniq_frac_3186; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1001 = 0x0p+0; /*float64*/
  }
  _x_x1000 = kk_double_box(_x_x1001, _ctx); /*7*/
  _x_x999 = kk_std_core_types__new_Optional(_x_x1000, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1002;
  kk_box_t _x_x1003;
  kk_std_time_calendar__timezone _x_x1004;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x333 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3190 = kk_std_time_calendar__timezone_unbox(_box_x333, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3190, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1004 = _uniq_tz_3190; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1004 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1003 = kk_std_time_calendar__timezone_box(_x_x1004, _ctx); /*7*/
  _x_x1002 = kk_std_core_types__new_Optional(_x_x1003, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1005;
  kk_box_t _x_x1006;
  kk_std_time_calendar__calendar _x_x1007;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x335 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3194 = kk_std_time_calendar__calendar_unbox(_box_x335, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3194, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1007 = _uniq_cal_3194; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1007 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1006 = kk_std_time_calendar__calendar_box(_x_x1007, _ctx); /*7*/
  _x_x1005 = kk_std_core_types__new_Optional(_x_x1006, _ctx); /*? 7*/
  _x_x983 = kk_std_time_calendar_timescale_fs_instant(x_10254, year, _x_x984, _x_x987, _x_x990, _x_x993, _x_x996, _x_x999, _x_x1002, _x_x1005, _ctx); /*std/time/instant/instant*/
  return kk_std_time_instant__instant_box(_x_x983, _ctx);
}

kk_std_time_instant__instant kk_std_time_calendar_utc_fs_instant(kk_integer_t year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? int, frac : ? float64, tz : ? timezone, cal : ? calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 
  kk_std_time_instant__timescale x_10254;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x312 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3201 = kk_std_time_instant__timescale_unbox(_box_x312, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3201, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10254 = _uniq_ts_3201; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10257 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x977;
    {
      struct kk_std_core_hnd_Ev* _con_x978 = kk_std_core_hnd__as_Ev(ev_10257, _ctx);
      kk_box_t _box_x313 = _con_x978->hnd;
      int32_t m = _con_x978->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x313, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x468;
      kk_std_core_hnd__clause0 _brw_x469 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x468 = _brw_x469; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x316 = _match_x468.clause;
        _x_x977 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x316, (_fun_unbox_x316, m, ev_10257, _ctx), _ctx); /*35*/
      }
    }
    x_10254 = kk_std_time_instant__timescale_unbox(_x_x977, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  kk_box_t _x_x979;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10254, (KK_I32(10)), _ctx);
    _x_x979 = kk_std_core_hnd_yield_extend(kk_std_time_calendar_utc_fs_new_instant_fun980(cal, day, frac, hours, minutes, month, seconds, tz, year, _ctx), _ctx); /*2419*/
  }
  else {
    _x_x979 = kk_std_core_hnd__open_none0(kk_std_time_calendar_utc_fs_new_instant_fun982(cal, day, frac, hours, minutes, month, seconds, tz, x_10254, year, _ctx), _ctx); /*2419*/
  }
  return kk_std_time_instant__instant_unbox(_x_x979, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009__t {
  struct kk_function_s _base;
  kk_std_time_instant__timescale _c_x10229;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utcdate_fs__new_mlift_instant_10253_fun1009(kk_std_time_instant__timescale _c_x10229, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009__t, 11, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009, kk_context());
  _self->_c_x10229 = _c_x10229;
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009__t* _self = kk_function_as(struct kk_std_time_calendar_utcdate_fs__mlift_instant_10253_fun1009__t*, _fself, _ctx);
  kk_std_time_instant__timescale _c_x10229 = _self->_c_x10229; /* std/time/instant/timescale */
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_time_instant__timescale_dup(_c_x10229, _ctx);kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant _x_x1010;
  kk_std_time_calendar__calendar _match_x466;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x349 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3294 = kk_std_time_calendar__calendar_unbox(_box_x349, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3294, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x466 = _uniq_cal_3294; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x466 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1011 = kk_std_time_calendar__as_Calendar(_match_x466, _ctx);
    kk_string_t _pat_0 = _con_x1011->name;
    kk_string_t _pat_1 = _con_x1011->long_name;
    kk_string_t _pat_2 = _con_x1011->month_prefix;
    kk_function_t _pat_3 = _con_x1011->show_era;
    kk_function_t _pat_4 = _con_x1011->instant_to_dc;
    kk_function_t _x = _con_x1011->dc_to_instant;
    kk_function_t _pat_5_0 = _con_x1011->days_to_date;
    kk_function_t _pat_6_0 = _con_x1011->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x466, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_0, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x466, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x466, _ctx);
    }
    kk_std_time_date__clock _x_x1012;
    if (kk_std_core_types__is_Optional(c, _ctx)) {
      kk_box_t _box_x350 = c._cons._Optional.value;
      kk_std_time_date__clock _uniq_c_3286 = kk_std_time_date__clock_unbox(_box_x350, KK_BORROWED, _ctx);
      kk_std_time_date__clock_dup(_uniq_c_3286, _ctx);
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1012 = _uniq_c_3286; /*std/time/date/clock*/
    }
    else {
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1012 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    }
    kk_std_time_calendar__timezone _x_x1013;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x351 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3290 = kk_std_time_calendar__timezone_unbox(_box_x351, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3290, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1013 = _uniq_tz_3290; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1013 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    _x_x1010 = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x1012, _x_x1013, _c_x10229, _ctx), _ctx); /*std/time/instant/instant*/
  }
  return kk_std_time_instant__instant_box(_x_x1010, _ctx);
}

kk_std_time_instant__instant kk_std_time_calendar_utcdate_fs__mlift_instant_10253(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10229, kk_context_t* _ctx) { /* (c : ? std/time/date/clock, cal : ? calendar, d : std/time/date/date, tz : ? timezone, std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_box_t _x_x1008 = kk_std_core_hnd__open_none0(kk_std_time_calendar_utcdate_fs__new_mlift_instant_10253_fun1009(_c_x10229, c, cal, d, tz, _ctx), _ctx); /*9836*/
  return kk_std_time_instant__instant_unbox(_x_x1008, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_utcdate_fs_instant_fun1017__t {
  struct kk_function_s _base;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_calendar_utcdate_fs_instant_fun1017(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utcdate_fs_new_instant_fun1017(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs_instant_fun1017__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utcdate_fs_instant_fun1017__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utcdate_fs_instant_fun1017, kk_context());
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utcdate_fs_instant_fun1017(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs_instant_fun1017__t* _self = kk_function_as(struct kk_std_time_calendar_utcdate_fs_instant_fun1017__t*, _fself, _ctx);
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10229_369 = kk_std_time_instant__timescale_unbox(_b_x362, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x1018 = kk_std_time_calendar_utcdate_fs__mlift_instant_10253(c, cal, d, tz, _c_x10229_369, _ctx); /*std/time/instant/instant*/
  return kk_std_time_instant__instant_box(_x_x1018, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_utcdate_fs_instant_fun1019__t {
  struct kk_function_s _base;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
  kk_std_time_instant__timescale x_10259;
};
static kk_box_t kk_std_time_calendar_utcdate_fs_instant_fun1019(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utcdate_fs_new_instant_fun1019(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale x_10259, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs_instant_fun1019__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utcdate_fs_instant_fun1019__t, 11, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utcdate_fs_instant_fun1019, kk_context());
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  _self->x_10259 = x_10259;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utcdate_fs_instant_fun1019(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs_instant_fun1019__t* _self = kk_function_as(struct kk_std_time_calendar_utcdate_fs_instant_fun1019__t*, _fself, _ctx);
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_std_time_instant__timescale x_10259 = _self->x_10259; /* std/time/instant/timescale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_std_time_instant__timescale_dup(x_10259, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant _x_x1020;
  kk_std_time_calendar__calendar _match_x463;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x363 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3294 = kk_std_time_calendar__calendar_unbox(_box_x363, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3294, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x463 = _uniq_cal_3294; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x463 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1021 = kk_std_time_calendar__as_Calendar(_match_x463, _ctx);
    kk_string_t _pat_0_1 = _con_x1021->name;
    kk_string_t _pat_1_1 = _con_x1021->long_name;
    kk_string_t _pat_2_0 = _con_x1021->month_prefix;
    kk_function_t _pat_3_2 = _con_x1021->show_era;
    kk_function_t _pat_4 = _con_x1021->instant_to_dc;
    kk_function_t _x = _con_x1021->dc_to_instant;
    kk_function_t _pat_5_0 = _con_x1021->days_to_date;
    kk_function_t _pat_6_0 = _con_x1021->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x463, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_0, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3_2, _ctx);
      kk_string_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(_match_x463, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x463, _ctx);
    }
    kk_std_time_date__clock _x_x1022;
    if (kk_std_core_types__is_Optional(c, _ctx)) {
      kk_box_t _box_x364 = c._cons._Optional.value;
      kk_std_time_date__clock _uniq_c_3286 = kk_std_time_date__clock_unbox(_box_x364, KK_BORROWED, _ctx);
      kk_std_time_date__clock_dup(_uniq_c_3286, _ctx);
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1022 = _uniq_c_3286; /*std/time/date/clock*/
    }
    else {
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1022 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    }
    kk_std_time_calendar__timezone _x_x1023;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x365 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3290 = kk_std_time_calendar__timezone_unbox(_box_x365, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3290, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1023 = _uniq_tz_3290; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1023 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    _x_x1020 = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x1022, _x_x1023, x_10259, _ctx), _ctx); /*std/time/instant/instant*/
  }
  return kk_std_time_instant__instant_box(_x_x1020, _ctx);
}

kk_std_time_instant__instant kk_std_time_calendar_utcdate_fs_instant(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (d : std/time/date/date, c : ? std/time/date/clock, tz : ? timezone, cal : ? calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 
  kk_std_time_instant__timescale x_10259;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x354 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3301 = kk_std_time_instant__timescale_unbox(_box_x354, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3301, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10259 = _uniq_ts_3301; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10262 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x1014;
    {
      struct kk_std_core_hnd_Ev* _con_x1015 = kk_std_core_hnd__as_Ev(ev_10262, _ctx);
      kk_box_t _box_x355 = _con_x1015->hnd;
      int32_t m = _con_x1015->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x355, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x464;
      kk_std_core_hnd__clause0 _brw_x465 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x464 = _brw_x465; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x358 = _match_x464.clause;
        _x_x1014 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x358, (_fun_unbox_x358, m, ev_10262, _ctx), _ctx); /*35*/
      }
    }
    x_10259 = kk_std_time_instant__timescale_unbox(_x_x1014, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  kk_box_t _x_x1016;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10259, (KK_I32(10)), _ctx);
    _x_x1016 = kk_std_core_hnd_yield_extend(kk_std_time_calendar_utcdate_fs_new_instant_fun1017(c, cal, d, tz, _ctx), _ctx); /*2419*/
  }
  else {
    _x_x1016 = kk_std_core_hnd__open_none0(kk_std_time_calendar_utcdate_fs_new_instant_fun1019(c, cal, d, tz, x_10259, _ctx), _ctx); /*2419*/
  }
  return kk_std_time_instant__instant_unbox(_x_x1016, KK_OWNED, _ctx);
}
 
// Convert an `:instant` to a `:date`, `:clock`, timezone delta and abbreviation,
// for a given timezone `tz` (=`tz-utc` by default) and calendar (=`cal-iso` by default).

kk_std_core_types__tuple4 kk_std_time_calendar_instant_dc(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? timezone, cal : ? calendar) -> (std/time/date/date, std/time/date/clock, std/time/duration/duration, string) */ 
  kk_std_time_calendar__timezone _match_x458;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x370 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3355 = kk_std_time_calendar__timezone_unbox(_box_x370, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3355, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _match_x458 = _uniq_tz_3355; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _match_x458 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1024 = kk_std_time_calendar__as_Timezone(_match_x458, _ctx);
    kk_string_t _pat_0 = _con_x1024->name;
    kk_function_t _x = _con_x1024->utc_delta;
    kk_function_t _pat_1 = _con_x1024->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x458, _ctx)) {
      kk_function_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x458, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x458, _ctx);
    }
    kk_std_core_types__tuple2 _match_x459;
    kk_std_time_instant__instant _x_x1025 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    _match_x459 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x, (_x, _x_x1025, _ctx), _ctx); /*(std/time/duration/duration, string)*/
    {
      kk_box_t _box_x371 = _match_x459.fst;
      kk_box_t _box_x372 = _match_x459.snd;
      kk_std_time_duration__duration tzdelta = kk_std_time_duration__duration_unbox(_box_x371, KK_BORROWED, _ctx);
      kk_string_t tzabbrv = kk_string_unbox(_box_x372);
      kk_string_dup(tzabbrv, _ctx);
      kk_std_core_types__tuple2_drop(_match_x459, _ctx);
      kk_std_time_calendar__calendar _match_x460;
      if (kk_std_core_types__is_Optional(cal, _ctx)) {
        kk_box_t _box_x373 = cal._cons._Optional.value;
        kk_std_time_calendar__calendar _uniq_cal_3359 = kk_std_time_calendar__calendar_unbox(_box_x373, KK_BORROWED, _ctx);
        kk_std_time_calendar__calendar_dup(_uniq_cal_3359, _ctx);
        kk_std_core_types__optional_drop(cal, _ctx);
        _match_x460 = _uniq_cal_3359; /*std/time/calendar/calendar*/
      }
      else {
        kk_std_core_types__optional_drop(cal, _ctx);
        _match_x460 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
      }
      {
        struct kk_std_time_calendar_Calendar* _con_x1026 = kk_std_time_calendar__as_Calendar(_match_x460, _ctx);
        kk_string_t _pat_0_1 = _con_x1026->name;
        kk_string_t _pat_1_0 = _con_x1026->long_name;
        kk_string_t _pat_2_0 = _con_x1026->month_prefix;
        kk_function_t _pat_3_0 = _con_x1026->show_era;
        kk_function_t _x_0 = _con_x1026->instant_to_dc;
        kk_function_t _pat_4_0 = _con_x1026->dc_to_instant;
        kk_function_t _pat_5_0 = _con_x1026->days_to_date;
        kk_function_t _pat_6 = _con_x1026->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_match_x460, _ctx)) {
          kk_function_drop(_pat_6, _ctx);
          kk_function_drop(_pat_5_0, _ctx);
          kk_function_drop(_pat_4_0, _ctx);
          kk_function_drop(_pat_3_0, _ctx);
          kk_string_drop(_pat_2_0, _ctx);
          kk_string_drop(_pat_1_0, _ctx);
          kk_string_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(_match_x460, _ctx);
        }
        else {
          kk_function_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(_match_x460, _ctx);
        }
        kk_std_core_types__tuple2 _match_x461 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_std_time_duration__duration, kk_context_t*), _x_0, (_x_0, i, tzdelta, _ctx), _ctx); /*(std/time/date/date, std/time/date/clock)*/;
        {
          kk_box_t _box_x374 = _match_x461.fst;
          kk_box_t _box_x375 = _match_x461.snd;
          kk_std_time_date__date d = kk_std_time_date__date_unbox(_box_x374, KK_BORROWED, _ctx);
          kk_std_time_date__clock c = kk_std_time_date__clock_unbox(_box_x375, KK_BORROWED, _ctx);
          struct kk_std_time_date_Clock* _con_x1027 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_time_date__clock_dup(c, _ctx);
          kk_std_time_date__date_dup(d, _ctx);
          kk_std_core_types__tuple2_drop(_match_x461, _ctx);
          return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_time_date__date_box(d, _ctx), kk_std_time_date__clock_box(c, _ctx), kk_std_time_duration__duration_box(tzdelta, _ctx), kk_string_box(tzabbrv), _ctx);
        }
      }
    }
  }
}
 
// Return the day of the week for a calendar `cal` (=`cal-iso`).

kk_std_time_date__weekday kk_std_time_calendar_weekday(kk_std_time_date__date d, kk_std_time_calendar__calendar cal, kk_context_t* _ctx) { /* (d : std/time/date/date, cal : calendar) -> std/time/date/weekday */ 
  kk_integer_t x_10163;
  {
    struct kk_std_time_calendar_Calendar* _con_x1028 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1028->name;
    kk_string_t _pat_1 = _con_x1028->long_name;
    kk_string_t _pat_2 = _con_x1028->month_prefix;
    kk_function_t _pat_3 = _con_x1028->show_era;
    kk_function_t _pat_4 = _con_x1028->instant_to_dc;
    kk_function_t _pat_5 = _con_x1028->dc_to_instant;
    kk_function_t _pat_6 = _con_x1028->days_to_date;
    kk_function_t _x = _con_x1028->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    x_10163 = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, d, _ctx), _ctx); /*int*/
  }
  kk_integer_t dow;
  kk_integer_t _x_x1029 = kk_integer_add_small_const(x_10163, 6, _ctx); /*int*/
  dow = kk_integer_mod(_x_x1029,(kk_integer_from_small(7)),kk_context()); /*int*/
  return kk_std_time_date_weekday(dow, _ctx);
}
 
// Return the days between two dates interpreted by calendar `cal`.

kk_integer_t kk_std_time_calendar_days_until(kk_std_time_calendar__calendar cal, kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx) { /* (cal : calendar, d1 : std/time/date/date, d2 : std/time/date/date) -> int */ 
  kk_integer_t x;
  {
    struct kk_std_time_calendar_Calendar* _con_x1030 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_function_t _x_0 = _con_x1030->date_to_days;
    kk_function_dup(_x_0, _ctx);
    x = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_0, (_x_0, d2, _ctx), _ctx); /*int*/
  }
  kk_integer_t y;
  {
    struct kk_std_time_calendar_Calendar* _con_x1031 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1031->name;
    kk_string_t _pat_1 = _con_x1031->long_name;
    kk_string_t _pat_2 = _con_x1031->month_prefix;
    kk_function_t _pat_3 = _con_x1031->show_era;
    kk_function_t _pat_4 = _con_x1031->instant_to_dc;
    kk_function_t _pat_5 = _con_x1031->dc_to_instant;
    kk_function_t _pat_6 = _con_x1031->days_to_date;
    kk_function_t _x = _con_x1031->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    y = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, d1, _ctx), _ctx); /*int*/
  }
  return kk_integer_sub(x,y,kk_context());
}

kk_std_time_timestamp__timestamp kk_std_time_calendar_cal_timestamp(kk_std_time_calendar__calendar cal, kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_time_date__clock c, kk_context_t* _ctx) { /* (cal : calendar, ts : std/time/instant/timescale, d : std/time/date/date, c : std/time/date/clock) -> std/time/timestamp/timestamp */ 
  kk_function_t _x_x1032;
  {
    struct kk_std_time_calendar_Calendar* _con_x1033 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1033->name;
    kk_string_t _pat_1 = _con_x1033->long_name;
    kk_string_t _pat_2 = _con_x1033->month_prefix;
    kk_function_t _pat_3 = _con_x1033->show_era;
    kk_function_t _pat_4 = _con_x1033->instant_to_dc;
    kk_function_t _pat_5 = _con_x1033->dc_to_instant;
    kk_function_t _pat_6 = _con_x1033->days_to_date;
    kk_function_t _x = _con_x1033->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    _x_x1032 = _x; /*(date : std/time/date/date) -> int*/
  }
  kk_std_core_types__optional _x_x1034;
  kk_box_t _x_x1035;
  bool _x_x1036;
  {
    struct kk_std_time_instant_Timescale* _con_x1037 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _pat_0_0 = _con_x1037->name;
    kk_string_t _pat_1_0 = _con_x1037->unit;
    kk_function_t _pat_2_0_0 = _con_x1037->from_tai;
    kk_function_t _pat_3_0 = _con_x1037->to_tai;
    kk_std_core_types__maybe _x_0 = _con_x1037->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_0 = _con_x1037->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_0 = _con_x1037->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_0, _ctx);
      kk_function_drop(_pat_3_0, _ctx);
      kk_function_drop(_pat_2_0_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_std_core_types__maybe_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(ts, _ctx);
    }
    if (kk_std_core_types__is_Just(_x_0, _ctx)) {
      kk_std_core_types__maybe_drop(_x_0, _ctx);
      _x_x1036 = true; /*bool*/
    }
    else {
      _x_x1036 = false; /*bool*/
    }
  }
  _x_x1035 = kk_bool_box(_x_x1036); /*7*/
  _x_x1034 = kk_std_core_types__new_Optional(_x_x1035, _ctx); /*? 7*/
  return kk_std_time_calendar_dc_timestamp(d, c, _x_x1032, _x_x1034, _ctx);
}
 
// Create a new calendar from by combining two other calendars. The `switch-date`
// is in terms of the second calendar (`cal2`) and time after (and including) the switch
// date is displayed in `cal2` while times before it in `cal1`. This function is used
// for example for the Julian Gregorian calendar.


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1039__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal1;
  kk_std_time_calendar__calendar cal2;
  kk_std_time_date__date switch_date;
};
static kk_std_time_date__date kk_std_time_calendar_combine_earth_calendars_fun1039(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1039(kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_time_date__date switch_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1039__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1039__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1039, kk_context());
  _self->cal1 = cal1;
  _self->cal2 = cal2;
  _self->switch_date = switch_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_combine_earth_calendars_fun1039(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1039__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1039__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal1 = _self->cal1; /* std/time/calendar/calendar */
  kk_std_time_calendar__calendar cal2 = _self->cal2; /* std/time/calendar/calendar */
  kk_std_time_date__date switch_date = _self->switch_date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal1, _ctx);kk_std_time_calendar__calendar_dup(cal2, _ctx);kk_std_time_date__date_dup(switch_date, _ctx);}, {}, _ctx)
  kk_std_time_calendar__calendar calendar_0_10170;
  bool _match_x455;
  kk_integer_t _brw_x456;
  {
    struct kk_std_time_calendar_Calendar* _con_x1040 = kk_std_time_calendar__as_Calendar(cal2, _ctx);
    kk_function_t _x = _con_x1040->date_to_days;
    kk_function_dup(_x, _ctx);
    _brw_x456 = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, switch_date, _ctx), _ctx); /*int*/
  }
  bool _brw_x457 = kk_integer_lt_borrow(days,_brw_x456,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x456, _ctx);
  _match_x455 = _brw_x457; /*bool*/
  if (_match_x455) {
    kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
    calendar_0_10170 = cal1; /*std/time/calendar/calendar*/
  }
  else {
    kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
    calendar_0_10170 = cal2; /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1041 = kk_std_time_calendar__as_Calendar(calendar_0_10170, _ctx);
    kk_string_t _pat_0_0 = _con_x1041->name;
    kk_string_t _pat_1_0 = _con_x1041->long_name;
    kk_string_t _pat_2_0 = _con_x1041->month_prefix;
    kk_function_t _pat_3_0 = _con_x1041->show_era;
    kk_function_t _pat_4_0 = _con_x1041->instant_to_dc;
    kk_function_t _pat_5_0 = _con_x1041->dc_to_instant;
    kk_function_t _x_0 = _con_x1041->days_to_date;
    kk_function_t _pat_6_0 = _con_x1041->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(calendar_0_10170, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_0, _ctx);
      kk_function_drop(_pat_4_0, _ctx);
      kk_function_drop(_pat_3_0, _ctx);
      kk_string_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(calendar_0_10170, _ctx);
    }
    else {
      kk_function_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(calendar_0_10170, _ctx);
    }
    return kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), _x_0, (_x_0, days, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1043__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal1;
  kk_std_time_calendar__calendar cal2;
  kk_std_time_date__date switch_date;
};
static kk_integer_t kk_std_time_calendar_combine_earth_calendars_fun1043(kk_function_t _fself, kk_std_time_date__date d, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1043(kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_time_date__date switch_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1043__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1043__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1043, kk_context());
  _self->cal1 = cal1;
  _self->cal2 = cal2;
  _self->switch_date = switch_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_combine_earth_calendars_fun1043(kk_function_t _fself, kk_std_time_date__date d, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1043__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1043__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal1 = _self->cal1; /* std/time/calendar/calendar */
  kk_std_time_calendar__calendar cal2 = _self->cal2; /* std/time/calendar/calendar */
  kk_std_time_date__date switch_date = _self->switch_date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal1, _ctx);kk_std_time_calendar__calendar_dup(cal2, _ctx);kk_std_time_date__date_dup(switch_date, _ctx);}, {}, _ctx)
  kk_std_time_calendar__calendar calendar_1_10172;
  bool _match_x454;
  kk_std_core_types__order _x_x1044;
  kk_std_time_date__date _x_x1045 = kk_std_time_date__date_dup(d, _ctx); /*std/time/date/date*/
  _x_x1044 = kk_std_time_date_cmp(_x_x1045, switch_date, _ctx); /*order*/
  _match_x454 = kk_std_core_order__lp__eq__eq__rp_(_x_x1044, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x454) {
    kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
    calendar_1_10172 = cal1; /*std/time/calendar/calendar*/
  }
  else {
    kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
    calendar_1_10172 = cal2; /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1046 = kk_std_time_calendar__as_Calendar(calendar_1_10172, _ctx);
    kk_string_t _pat_0_1 = _con_x1046->name;
    kk_string_t _pat_1_2 = _con_x1046->long_name;
    kk_string_t _pat_2_2 = _con_x1046->month_prefix;
    kk_function_t _pat_3_1 = _con_x1046->show_era;
    kk_function_t _pat_4_1 = _con_x1046->instant_to_dc;
    kk_function_t _pat_5_1 = _con_x1046->dc_to_instant;
    kk_function_t _pat_6_1 = _con_x1046->days_to_date;
    kk_function_t _x_1 = _con_x1046->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(calendar_1_10172, _ctx)) {
      kk_function_drop(_pat_6_1, _ctx);
      kk_function_drop(_pat_5_1, _ctx);
      kk_function_drop(_pat_4_1, _ctx);
      kk_function_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_2_2, _ctx);
      kk_string_drop(_pat_1_2, _ctx);
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(calendar_1_10172, _ctx);
    }
    else {
      kk_function_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(calendar_1_10172, _ctx);
    }
    return kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_1, (_x_1, d, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1048__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal1;
  kk_std_time_calendar__calendar cal2;
  kk_std_core_types__optional mb_show_era;
  kk_std_time_date__date switch_date;
};
static kk_box_t kk_std_time_calendar_combine_earth_calendars_fun1048(kk_function_t _fself, kk_box_t _b_x404, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1048(kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_core_types__optional mb_show_era, kk_std_time_date__date switch_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1048__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1048__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1048, kk_context());
  _self->cal1 = cal1;
  _self->cal2 = cal2;
  _self->mb_show_era = mb_show_era;
  _self->switch_date = switch_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_combine_earth_calendars_fun1048(kk_function_t _fself, kk_box_t _b_x404, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1048__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1048__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal1 = _self->cal1; /* std/time/calendar/calendar */
  kk_std_time_calendar__calendar cal2 = _self->cal2; /* std/time/calendar/calendar */
  kk_std_core_types__optional mb_show_era = _self->mb_show_era; /* ? (maybe<(std/time/date/date) -> string>) */
  kk_std_time_date__date switch_date = _self->switch_date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal1, _ctx);kk_std_time_calendar__calendar_dup(cal2, _ctx);kk_std_core_types__optional_dup(mb_show_era, _ctx);kk_std_time_date__date_dup(switch_date, _ctx);}, {}, _ctx)
  kk_string_t _x_x1049;
  kk_std_time_date__date d_0_406 = kk_std_time_date__date_unbox(_b_x404, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_std_core_types__maybe _match_x452;
  if (kk_std_core_types__is_Optional(mb_show_era, _ctx)) {
    kk_box_t _box_x393 = mb_show_era._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_show_era_3504 = kk_std_core_types__maybe_unbox(_box_x393, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_show_era_3504, _ctx);
    kk_std_core_types__optional_drop(mb_show_era, _ctx);
    _match_x452 = _uniq_mb_show_era_3504; /*maybe<(std/time/date/date) -> string>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_show_era, _ctx);
    _match_x452 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/date/date) -> string>*/
  }
  if (kk_std_core_types__is_Just(_match_x452, _ctx)) {
    kk_box_t _fun_unbox_x397 = _match_x452._cons.Just.value;
    kk_std_time_date__date_drop(switch_date, _ctx);
    kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
    kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
    kk_box_t _x_x1050;
    kk_function_t _x_x1051 = kk_function_unbox(_fun_unbox_x397, _ctx); /*(398) -> 399*/
    _x_x1050 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1051, (_x_x1051, kk_std_time_date__date_box(d_0_406, _ctx), _ctx), _ctx); /*399*/
    _x_x1049 = kk_string_unbox(_x_x1050); /*string*/
  }
  else {
    kk_std_time_calendar__calendar calendar_2_10175;
    bool _match_x453;
    kk_std_core_types__order _x_x1052;
    kk_std_time_date__date _x_x1053 = kk_std_time_date__date_dup(d_0_406, _ctx); /*std/time/date/date*/
    _x_x1052 = kk_std_time_date_cmp(_x_x1053, switch_date, _ctx); /*order*/
    _match_x453 = kk_std_core_order__lp__eq__eq__rp_(_x_x1052, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
    if (_match_x453) {
      kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
      calendar_2_10175 = cal1; /*std/time/calendar/calendar*/
    }
    else {
      kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
      calendar_2_10175 = cal2; /*std/time/calendar/calendar*/
    }
    {
      struct kk_std_time_calendar_Calendar* _con_x1054 = kk_std_time_calendar__as_Calendar(calendar_2_10175, _ctx);
      kk_string_t _pat_0_3 = _con_x1054->name;
      kk_string_t _pat_1_3 = _con_x1054->long_name;
      kk_string_t _pat_2_3 = _con_x1054->month_prefix;
      kk_function_t _x_2 = _con_x1054->show_era;
      kk_function_t _pat_3_3 = _con_x1054->instant_to_dc;
      kk_function_t _pat_4_3 = _con_x1054->dc_to_instant;
      kk_function_t _pat_5_3 = _con_x1054->days_to_date;
      kk_function_t _pat_6_3 = _con_x1054->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(calendar_2_10175, _ctx)) {
        kk_function_drop(_pat_6_3, _ctx);
        kk_function_drop(_pat_5_3, _ctx);
        kk_function_drop(_pat_4_3, _ctx);
        kk_function_drop(_pat_3_3, _ctx);
        kk_string_drop(_pat_2_3, _ctx);
        kk_string_drop(_pat_1_3, _ctx);
        kk_string_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(calendar_2_10175, _ctx);
      }
      else {
        kk_function_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(calendar_2_10175, _ctx);
      }
      _x_x1049 = kk_function_call(kk_string_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_2, (_x_2, d_0_406, _ctx), _ctx); /*string*/
    }
  }
  return kk_string_box(_x_x1049);
}

kk_std_time_calendar__calendar kk_std_time_calendar_combine_earth_calendars(kk_string_t name, kk_string_t long_name, kk_std_time_date__date switch_date, kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_core_types__optional mb_show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, switch-date : std/time/date/date, cal1 : calendar, cal2 : calendar, mb-show-era : ? (maybe<(std/time/date/date) -> string>)) -> calendar */ 
  kk_function_t _x_x1038;
  kk_std_time_calendar__calendar_dup(cal1, _ctx);
  kk_std_time_calendar__calendar_dup(cal2, _ctx);
  kk_std_time_date__date_dup(switch_date, _ctx);
  _x_x1038 = kk_std_time_calendar_new_combine_earth_calendars_fun1039(cal1, cal2, switch_date, _ctx); /*(days : int) -> std/time/date/date*/
  kk_function_t _x_x1042;
  kk_std_time_calendar__calendar_dup(cal1, _ctx);
  kk_std_time_calendar__calendar_dup(cal2, _ctx);
  kk_std_time_date__date_dup(switch_date, _ctx);
  _x_x1042 = kk_std_time_calendar_new_combine_earth_calendars_fun1043(cal1, cal2, switch_date, _ctx); /*(d : std/time/date/date) -> int*/
  kk_std_core_types__optional _x_x1047 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_combine_earth_calendars_fun1048(cal1, cal2, mb_show_era, switch_date, _ctx), _ctx), _ctx); /*? 7*/
  return kk_std_time_calendar_earth_calendar(name, long_name, _x_x1038, _x_x1042, kk_std_core_types__new_None(_ctx), _x_x1047, _ctx);
}
 
// Create a new calendar from anoter calendar `cal` by adding an offset to the
// years (`year-shift`). This is used for example to create the Ethiopian calendar
// from the Coptic calendar, by using:
// `year-shift-earth-calendar( "EC", "Ethiopian", ~276, cal-coptic )`


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1056__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_integer_t year_shift;
};
static kk_std_time_date__date kk_std_time_calendar_year_shift_earth_calendar_fun1056(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1056(kk_std_time_calendar__calendar cal, kk_integer_t year_shift, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1056__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1056__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1056, kk_context());
  _self->cal = cal;
  _self->year_shift = year_shift;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_year_shift_earth_calendar_fun1056(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1056__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1056__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_integer_t year_shift = _self->year_shift; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_integer_dup(year_shift, _ctx);}, {}, _ctx)
  kk_std_time_date__date d_0;
  {
    struct kk_std_time_calendar_Calendar* _con_x1057 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1057->name;
    kk_string_t _pat_1 = _con_x1057->long_name;
    kk_string_t _pat_2 = _con_x1057->month_prefix;
    kk_function_t _pat_3 = _con_x1057->show_era;
    kk_function_t _pat_4 = _con_x1057->instant_to_dc;
    kk_function_t _pat_5 = _con_x1057->dc_to_instant;
    kk_function_t _x = _con_x1057->days_to_date;
    kk_function_t _pat_6 = _con_x1057->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    d_0 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), _x, (_x, days, _ctx), _ctx); /*std/time/date/date*/
  }
  kk_integer_t _b_x407_408;
  kk_integer_t _x_x1058;
  {
    kk_integer_t _x_2 = d_0.year;
    kk_integer_dup(_x_2, _ctx);
    _x_x1058 = _x_2; /*int*/
  }
  _b_x407_408 = kk_integer_sub(_x_x1058,year_shift,kk_context()); /*int*/
  kk_integer_t _x_x1059;
  kk_std_core_types__optional _match_x451 = kk_std_core_types__new_Optional(kk_integer_box(_b_x407_408, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x451, _ctx)) {
    kk_box_t _box_x409 = _match_x451._cons._Optional.value;
    kk_integer_t _uniq_year_102 = kk_integer_unbox(_box_x409, _ctx);
    kk_integer_dup(_uniq_year_102, _ctx);
    kk_std_core_types__optional_drop(_match_x451, _ctx);
    _x_x1059 = _uniq_year_102; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x451, _ctx);
    {
      kk_integer_t _x_0 = d_0.year;
      kk_integer_dup(_x_0, _ctx);
      _x_x1059 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x1060;
  kk_std_core_types__optional _match_x450 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x450, _ctx)) {
    kk_box_t _box_x410 = _match_x450._cons._Optional.value;
    kk_integer_t _uniq_month_110 = kk_integer_unbox(_box_x410, _ctx);
    kk_integer_dup(_uniq_month_110, _ctx);
    kk_std_core_types__optional_drop(_match_x450, _ctx);
    _x_x1060 = _uniq_month_110; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x450, _ctx);
    {
      kk_integer_t _x_0_0 = d_0.month;
      kk_integer_dup(_x_0_0, _ctx);
      _x_x1060 = _x_0_0; /*int*/
    }
  }
  kk_integer_t _x_x1061;
  kk_std_core_types__optional _match_x449 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x449, _ctx)) {
    kk_box_t _box_x411 = _match_x449._cons._Optional.value;
    kk_integer_t _uniq_day_118 = kk_integer_unbox(_box_x411, _ctx);
    kk_std_time_date__date_drop(d_0, _ctx);
    kk_integer_dup(_uniq_day_118, _ctx);
    kk_std_core_types__optional_drop(_match_x449, _ctx);
    _x_x1061 = _uniq_day_118; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x449, _ctx);
    {
      kk_integer_t _x_1 = d_0.day;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(d_0, _ctx);
      _x_x1061 = _x_1; /*int*/
    }
  }
  return kk_std_time_date__new_Date(_x_x1059, _x_x1060, _x_x1061, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1062__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_integer_t year_shift;
};
static kk_integer_t kk_std_time_calendar_year_shift_earth_calendar_fun1062(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1062(kk_std_time_calendar__calendar cal, kk_integer_t year_shift, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1062__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1062__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1062, kk_context());
  _self->cal = cal;
  _self->year_shift = year_shift;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_year_shift_earth_calendar_fun1062(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1062__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1062__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_integer_t year_shift = _self->year_shift; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_integer_dup(year_shift, _ctx);}, {}, _ctx)
  kk_integer_t _b_x412_413;
  kk_integer_t _x_x1063;
  {
    kk_integer_t _x_5 = d_1.year;
    kk_integer_dup(_x_5, _ctx);
    _x_x1063 = _x_5; /*int*/
  }
  _b_x412_413 = kk_integer_add(_x_x1063,year_shift,kk_context()); /*int*/
  {
    struct kk_std_time_calendar_Calendar* _con_x1064 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0_4 = _con_x1064->name;
    kk_string_t _pat_1_5 = _con_x1064->long_name;
    kk_string_t _pat_2_1 = _con_x1064->month_prefix;
    kk_function_t _pat_3_1 = _con_x1064->show_era;
    kk_function_t _pat_4_1 = _con_x1064->instant_to_dc;
    kk_function_t _pat_5_1 = _con_x1064->dc_to_instant;
    kk_function_t _pat_6_0 = _con_x1064->days_to_date;
    kk_function_t _x_3 = _con_x1064->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_1, _ctx);
      kk_function_drop(_pat_4_1, _ctx);
      kk_function_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_2_1, _ctx);
      kk_string_drop(_pat_1_5, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    kk_std_time_date__date _x_x1065;
    kk_integer_t _x_x1066;
    kk_std_core_types__optional _match_x448 = kk_std_core_types__new_Optional(kk_integer_box(_b_x412_413, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x448, _ctx)) {
      kk_box_t _box_x414 = _match_x448._cons._Optional.value;
      kk_integer_t _uniq_year_102_0 = kk_integer_unbox(_box_x414, _ctx);
      kk_integer_dup(_uniq_year_102_0, _ctx);
      kk_std_core_types__optional_drop(_match_x448, _ctx);
      _x_x1066 = _uniq_year_102_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x448, _ctx);
      {
        kk_integer_t _x_4 = d_1.year;
        kk_integer_dup(_x_4, _ctx);
        _x_x1066 = _x_4; /*int*/
      }
    }
    kk_integer_t _x_x1067;
    kk_std_core_types__optional _match_x447 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x447, _ctx)) {
      kk_box_t _box_x415 = _match_x447._cons._Optional.value;
      kk_integer_t _uniq_month_110_0 = kk_integer_unbox(_box_x415, _ctx);
      kk_integer_dup(_uniq_month_110_0, _ctx);
      kk_std_core_types__optional_drop(_match_x447, _ctx);
      _x_x1067 = _uniq_month_110_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x447, _ctx);
      {
        kk_integer_t _x_0_1 = d_1.month;
        kk_integer_dup(_x_0_1, _ctx);
        _x_x1067 = _x_0_1; /*int*/
      }
    }
    kk_integer_t _x_x1068;
    kk_std_core_types__optional _match_x446 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x446, _ctx)) {
      kk_box_t _box_x416 = _match_x446._cons._Optional.value;
      kk_integer_t _uniq_day_118_0 = kk_integer_unbox(_box_x416, _ctx);
      kk_std_time_date__date_drop(d_1, _ctx);
      kk_integer_dup(_uniq_day_118_0, _ctx);
      kk_std_core_types__optional_drop(_match_x446, _ctx);
      _x_x1068 = _uniq_day_118_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x446, _ctx);
      {
        kk_integer_t _x_1_0 = d_1.day;
        kk_integer_dup(_x_1_0, _ctx);
        kk_std_time_date__date_drop(d_1, _ctx);
        _x_x1068 = _x_1_0; /*int*/
      }
    }
    _x_x1065 = kk_std_time_date__new_Date(_x_x1066, _x_x1067, _x_x1068, _ctx); /*std/time/date/date*/
    return kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_3, (_x_3, _x_x1065, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1074__t {
  struct kk_function_s _base;
  kk_std_core_types__optional show_era;
};
static kk_box_t kk_std_time_calendar_year_shift_earth_calendar_fun1074(kk_function_t _fself, kk_box_t _b_x429, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1074(kk_std_core_types__optional show_era, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1074__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1074__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1074, kk_context());
  _self->show_era = show_era;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_year_shift_earth_calendar_fun1074(kk_function_t _fself, kk_box_t _b_x429, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1074__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1074__t*, _fself, _ctx);
  kk_std_core_types__optional show_era = _self->show_era; /* ? ((std/time/date/date) -> string) */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(show_era, _ctx);}, {}, _ctx)
  kk_string_t _x_x1075;
  kk_std_time_date__date _norm_x432 = kk_std_time_date__date_unbox(_b_x429, KK_OWNED, _ctx); /*std/time/date/date*/;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x422 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x422, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date _b_x425_433 = _norm_x432; /*std/time/date/date*/;
    kk_box_t _x_x1076;
    kk_function_t _x_x1077 = kk_function_unbox(_fun_unbox_x422, _ctx); /*(423) -> 424*/
    _x_x1076 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1077, (_x_x1077, kk_std_time_date__date_box(_b_x425_433, _ctx), _ctx), _ctx); /*424*/
    _x_x1075 = kk_string_unbox(_x_x1076); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date d_434 = _norm_x432; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_434, _ctx);
    _x_x1075 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1075);
}

kk_std_time_calendar__calendar kk_std_time_calendar_year_shift_earth_calendar(kk_string_t name, kk_string_t long_name, kk_integer_t year_shift, kk_std_time_calendar__calendar cal, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, year-shift : int, cal : calendar, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_function_t _x_x1055;
  kk_std_time_calendar__calendar_dup(cal, _ctx);
  kk_integer_dup(year_shift, _ctx);
  _x_x1055 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1056(cal, year_shift, _ctx); /*(days : int) -> std/time/date/date*/
  kk_std_core_types__optional _x_x1069;
  kk_box_t _x_x1070;
  kk_string_t _x_x1071;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x417 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_3713 = kk_string_unbox(_box_x417);
    kk_string_dup(_uniq_month_prefix_3713, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1071 = _uniq_month_prefix_3713; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1071 = kk_string_empty(); /*string*/
  }
  _x_x1070 = kk_string_box(_x_x1071); /*7*/
  _x_x1069 = kk_std_core_types__new_Optional(_x_x1070, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1073 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_year_shift_earth_calendar_fun1074(show_era, _ctx), _ctx), _ctx); /*? 7*/
  return kk_std_time_calendar_earth_calendar(name, long_name, _x_x1055, kk_std_time_calendar_new_year_shift_earth_calendar_fun1062(cal, year_shift, _ctx), _x_x1069, _x_x1073, _ctx);
}
extern kk_integer_t kk_std_time_calendar_cal_utc_create_fun1086(kk_function_t _fself, kk_integer_t _x1_x1085, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1085, _ctx);
}
extern kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_create_fun1088(kk_function_t _fself, kk_integer_t _x1_x1087, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_estimate_year(_x1_x1087, _ctx);
}
extern kk_integer_t kk_std_time_calendar_cal_utc_create_fun1091(kk_function_t _fself, kk_integer_t _x1_x1089, kk_integer_t _x2_x1090, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1089, _x2_x1090, _ctx);
}
extern kk_integer_t kk_std_time_calendar_cal_utc_create_fun1094(kk_function_t _fself, kk_integer_t _x1_x1092, kk_integer_t _x2_x1093, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1092, _x2_x1093, _ctx);
}
 
// /* The standard [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) calendar
// but using TI-SLS time (`ts-ti-sls`), i.e. TI with
// [smoothed leap seconds](https://www.cl.cam.ac.uk/~mgk25/time/utc-sls/).
// 
// This calendar is equivalent to the ISO calendar except for the last 1000 seconds of a day where
// a leap second occurs. On such day, the leap second time step (positive or negative)
// is distributed over the last 1000 seconds of the day. On the full hour, ISO and ISO-SLS are equal again.
// 
// This is a recommended calendar to use for
// time stamps or communication with other services since it avoids any potential trouble
// with leap seconds while still being quite precise.
// 
// Other good properties include:
// 
// - All days have 86400 seconds, and the time 23:59:60 never appears
// - The time never differs more than one second from UTC
// - Time as always equal to UTC on the full and half hour
// */


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1100__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1100(kk_function_t _fself, kk_integer_t _x1_x1099, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1100(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1100, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1100(kk_function_t _fself, kk_integer_t _x1_x1099, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1099, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1102__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_sls_fun1102(kk_function_t _fself, kk_integer_t _x1_x1101, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1102(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1102, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_sls_fun1102(kk_function_t _fself, kk_integer_t _x1_x1101, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_estimate_year(_x1_x1101, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1105__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1105(kk_function_t _fself, kk_integer_t _x1_x1103, kk_integer_t _x2_x1104, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1105(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1105, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1105(kk_function_t _fself, kk_integer_t _x1_x1103, kk_integer_t _x2_x1104, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1103, _x2_x1104, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1108__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1108(kk_function_t _fself, kk_integer_t _x1_x1106, kk_integer_t _x2_x1107, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1108(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1108, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1108(kk_function_t _fself, kk_integer_t _x1_x1106, kk_integer_t _x2_x1107, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1106, _x2_x1107, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_iso_sls;
extern kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1114(kk_function_t _fself, kk_integer_t _x1_x1113, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1113, _ctx);
}
extern kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_sls_create_fun1116(kk_function_t _fself, kk_integer_t _x1_x1115, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_estimate_year(_x1_x1115, _ctx);
}
extern kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1119(kk_function_t _fself, kk_integer_t _x1_x1117, kk_integer_t _x2_x1118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1117, _x2_x1118, _ctx);
}
extern kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1122(kk_function_t _fself, kk_integer_t _x1_x1120, kk_integer_t _x2_x1121, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1120, _x2_x1121, _ctx);
}
 
// The (proleptic) [Gregorian calendar](https://en.wikipedia.org/wiki/Gregorian_calendar).
// Just like the ISO calendar except that the year 0 does not exist, i.e. after 1 BCE (=`~1`)
// we have 1 CE (=`1`).
// The calendar short name is ``GC``.


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1128__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1128(kk_function_t _fself, kk_integer_t _x1_x1127, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1128(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1128, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1128(kk_function_t _fself, kk_integer_t _x1_x1127, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1127, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1130__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_gregorian_fun1130(kk_function_t _fself, kk_integer_t _x1_x1129, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1130(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1130, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_gregorian_fun1130(kk_function_t _fself, kk_integer_t _x1_x1129, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_estimate_year(_x1_x1129, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1133__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1133(kk_function_t _fself, kk_integer_t _x1_x1131, kk_integer_t _x2_x1132, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1133(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1133, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1133(kk_function_t _fself, kk_integer_t _x1_x1131, kk_integer_t _x2_x1132, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1131, _x2_x1132, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1136__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1136(kk_function_t _fself, kk_integer_t _x1_x1134, kk_integer_t _x2_x1135, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1136(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1136, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1136(kk_function_t _fself, kk_integer_t _x1_x1134, kk_integer_t _x2_x1135, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1134, _x2_x1135, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1139__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_cal_gregorian_fun1139(kk_function_t _fself, kk_box_t _b_x439, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1139(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1139, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_cal_gregorian_fun1139(kk_function_t _fself, kk_box_t _b_x439, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1140;
  kk_std_time_date__date d_442 = kk_std_time_date__date_unbox(_b_x439, KK_OWNED, _ctx); /*std/time/date/date*/;
  bool _match_x443;
  kk_integer_t _brw_x444;
  {
    kk_integer_t _x = d_442.year;
    kk_integer_dup(_x, _ctx);
    kk_std_time_date__date_drop(d_442, _ctx);
    _brw_x444 = _x; /*int*/
  }
  bool _brw_x445 = kk_integer_lt_borrow(_brw_x444,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x444, _ctx);
  _match_x443 = _brw_x445; /*bool*/
  if (_match_x443) {
    kk_define_string_literal(, _s_x1141, 3, "BCE", _ctx)
    _x_x1140 = kk_string_dup(_s_x1141, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1142, 2, "CE", _ctx)
    _x_x1140 = kk_string_dup(_s_x1142, _ctx); /*string*/
  }
  return kk_string_box(_x_x1140);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_gregorian;

// initialization
void kk_std_time_calendar__init(kk_context_t* _ctx){
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
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_utc__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int32__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x650;
    kk_define_string_literal(, _s_x651, 3, "UTC", _ctx)
    _x_x650 = kk_string_dup(_s_x651, _ctx); /*string*/
    kk_std_time_calendar_tz_utc = kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, _x_x650, kk_std_time_calendar_new_tz_utc_fun652(_ctx), kk_std_time_calendar_new_tz_utc_fun656(_ctx), _ctx); /*std/time/calendar/timezone*/
  }
  {
    kk_string_t _x_x921 = kk_string_empty(); /*string*/
    kk_string_t _x_x923;
    kk_define_string_literal(, _s_x924, 3, "ISO", _ctx)
    _x_x923 = kk_string_dup(_s_x924, _ctx); /*string*/
    kk_std_time_calendar_cal_iso = kk_std_time_calendar_solar_ecalendar(_x_x921, _x_x923, kk_std_time_calendar_new_cal_iso_fun926(_ctx), kk_std_time_calendar_new_cal_iso_fun928(_ctx), kk_std_time_calendar_new_cal_iso_fun931(_ctx), kk_std_time_calendar_new_cal_iso_fun934(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x1095;
    kk_define_string_literal(, _s_x1096, 3, "SLS", _ctx)
    _x_x1095 = kk_string_dup(_s_x1096, _ctx); /*string*/
    kk_string_t _x_x1097;
    kk_define_string_literal(, _s_x1098, 7, "ISO-SLS", _ctx)
    _x_x1097 = kk_string_dup(_s_x1098, _ctx); /*string*/
    kk_std_time_calendar_cal_iso_sls = kk_std_time_calendar_solar_ecalendar(_x_x1095, _x_x1097, kk_std_time_calendar_new_cal_iso_sls_fun1100(_ctx), kk_std_time_calendar_new_cal_iso_sls_fun1102(_ctx), kk_std_time_calendar_new_cal_iso_sls_fun1105(_ctx), kk_std_time_calendar_new_cal_iso_sls_fun1108(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x1123;
    kk_define_string_literal(, _s_x1124, 2, "GC", _ctx)
    _x_x1123 = kk_string_dup(_s_x1124, _ctx); /*string*/
    kk_string_t _x_x1125;
    kk_define_string_literal(, _s_x1126, 9, "Gregorian", _ctx)
    _x_x1125 = kk_string_dup(_s_x1126, _ctx); /*string*/
    kk_std_core_types__optional _x_x1137 = kk_std_core_types__new_Optional(kk_bool_box(false), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x1138 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_cal_gregorian_fun1139(_ctx), _ctx), _ctx); /*? 7*/
    kk_std_time_calendar_cal_gregorian = kk_std_time_calendar_solar_ecalendar(_x_x1123, _x_x1125, kk_std_time_calendar_new_cal_gregorian_fun1128(_ctx), kk_std_time_calendar_new_cal_gregorian_fun1130(_ctx), kk_std_time_calendar_new_cal_gregorian_fun1133(_ctx), kk_std_time_calendar_new_cal_gregorian_fun1136(_ctx), kk_std_core_types__new_None(_ctx), _x_x1137, kk_std_core_types__new_None(_ctx), _x_x1138, _ctx); /*std/time/calendar/calendar*/
  }
}

// termination
void kk_std_time_calendar__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_calendar__calendar_drop(kk_std_time_calendar_cal_gregorian, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendar_cal_iso_sls, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendar_cal_iso, _ctx);
  kk_std_time_calendar__timezone_drop(kk_std_time_calendar_tz_utc, _ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_utc__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
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
