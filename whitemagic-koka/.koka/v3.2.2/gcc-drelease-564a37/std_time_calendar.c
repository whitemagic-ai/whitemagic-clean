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
struct kk_std_time_calendar_calendar_fs__copy_fun948__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x6;
};
static kk_string_t kk_std_time_calendar_calendar_fs__copy_fun948(kk_function_t _fself, kk_std_time_date__date _b_x9, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun948(kk_box_t _fun_unbox_x6, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun948__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun948__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun948, kk_context());
  _self->_fun_unbox_x6 = _fun_unbox_x6;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_calendar_fs__copy_fun948(kk_function_t _fself, kk_std_time_date__date _b_x9, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun948__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun948__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x6 = _self->_fun_unbox_x6; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x6, _ctx);}, {}, _ctx)
  kk_box_t _x_x949;
  kk_function_t _x_x950 = kk_function_unbox(_fun_unbox_x6, _ctx); /*(7) -> 8*/
  _x_x949 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x950, (_x_x950, kk_std_time_date__date_box(_b_x9, _ctx), _ctx), _ctx); /*8*/
  return kk_string_unbox(_x_x949);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun953__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x15;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_calendar_fs__copy_fun953(kk_function_t _fself, kk_std_time_instant__instant _b_x19, kk_std_time_duration__duration _b_x20, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun953(kk_box_t _fun_unbox_x15, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun953__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun953__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun953, kk_context());
  _self->_fun_unbox_x15 = _fun_unbox_x15;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_calendar_fs__copy_fun953(kk_function_t _fself, kk_std_time_instant__instant _b_x19, kk_std_time_duration__duration _b_x20, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun953__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun953__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x15 = _self->_fun_unbox_x15; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x15, _ctx);}, {}, _ctx)
  kk_box_t _x_x954;
  kk_function_t _x_x955 = kk_function_unbox(_fun_unbox_x15, _ctx); /*(i : 16, tzdelta : 17) -> 18*/
  _x_x954 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x955, (_x_x955, kk_std_time_instant__instant_box(_b_x19, _ctx), kk_std_time_duration__duration_box(_b_x20, _ctx), _ctx), _ctx); /*18*/
  return kk_std_core_types__tuple2_unbox(_x_x954, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun958__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x30;
};
static kk_std_time_instant__instant kk_std_time_calendar_calendar_fs__copy_fun958(kk_function_t _fself, kk_std_time_date__date _b_x36, kk_std_time_date__clock _b_x37, kk_std_time_calendar__timezone _b_x38, kk_std_time_instant__timescale _b_x39, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun958(kk_box_t _fun_unbox_x30, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun958__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun958__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun958, kk_context());
  _self->_fun_unbox_x30 = _fun_unbox_x30;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_calendar_fs__copy_fun958(kk_function_t _fself, kk_std_time_date__date _b_x36, kk_std_time_date__clock _b_x37, kk_std_time_calendar__timezone _b_x38, kk_std_time_instant__timescale _b_x39, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun958__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun958__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x30 = _self->_fun_unbox_x30; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x30, _ctx);}, {}, _ctx)
  kk_box_t _x_x959;
  kk_function_t _x_x960 = kk_function_unbox(_fun_unbox_x30, _ctx); /*(31, 32, 33, 34) -> 35*/
  _x_x959 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x960, (_x_x960, kk_std_time_date__date_box(_b_x36, _ctx), kk_std_time_date__clock_box(_b_x37, _ctx), kk_std_time_calendar__timezone_box(_b_x38, _ctx), kk_std_time_instant__timescale_box(_b_x39, _ctx), _ctx), _ctx); /*35*/
  return kk_std_time_instant__instant_unbox(_x_x959, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun963__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x43;
};
static kk_std_time_date__date kk_std_time_calendar_calendar_fs__copy_fun963(kk_function_t _fself, kk_integer_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun963(kk_box_t _fun_unbox_x43, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun963__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun963__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun963, kk_context());
  _self->_fun_unbox_x43 = _fun_unbox_x43;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_calendar_fs__copy_fun963(kk_function_t _fself, kk_integer_t _b_x46, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun963__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun963__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x43 = _self->_fun_unbox_x43; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x43, _ctx);}, {}, _ctx)
  kk_box_t _x_x964;
  kk_function_t _x_x965 = kk_function_unbox(_fun_unbox_x43, _ctx); /*(days : 44) -> 45*/
  _x_x964 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x965, (_x_x965, kk_integer_box(_b_x46, _ctx), _ctx), _ctx); /*45*/
  return kk_std_time_date__date_unbox(_x_x964, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_calendar_fs__copy_fun968__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x50;
};
static kk_integer_t kk_std_time_calendar_calendar_fs__copy_fun968(kk_function_t _fself, kk_std_time_date__date _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_calendar_fs__new_copy_fun968(kk_box_t _fun_unbox_x50, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun968__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_calendar_fs__copy_fun968__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_calendar_fs__copy_fun968, kk_context());
  _self->_fun_unbox_x50 = _fun_unbox_x50;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_calendar_fs__copy_fun968(kk_function_t _fself, kk_std_time_date__date _b_x53, kk_context_t* _ctx) {
  struct kk_std_time_calendar_calendar_fs__copy_fun968__t* _self = kk_function_as(struct kk_std_time_calendar_calendar_fs__copy_fun968__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x50 = _self->_fun_unbox_x50; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x50, _ctx);}, {}, _ctx)
  kk_box_t _x_x969;
  kk_function_t _x_x970 = kk_function_unbox(_fun_unbox_x50, _ctx); /*(date : 51) -> 52*/
  _x_x969 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x970, (_x_x970, kk_std_time_date__date_box(_b_x53, _ctx), _ctx), _ctx); /*52*/
  return kk_integer_unbox(_x_x969, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendar_calendar_fs__copy(kk_std_time_calendar__calendar _this, kk_std_core_types__optional name, kk_std_core_types__optional long_name, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_std_core_types__optional instant_to_dc, kk_std_core_types__optional dc_to_instant, kk_std_core_types__optional days_to_date, kk_std_core_types__optional date_to_days, kk_context_t* _ctx) { /* (calendar, name : ? string, long-name : ? string, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string), instant-to-dc : ? ((i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)), dc-to-instant : ? ((std/time/date/date, std/time/date/clock, timezone, std/time/instant/timescale) -> std/time/instant/instant), days-to-date : ? ((days : int) -> std/time/date/date), date-to-days : ? ((date : std/time/date/date) -> int)) -> calendar */ 
  kk_string_t _x_x941;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x0 = name._cons._Optional.value;
    kk_string_t _uniq_name_266 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_name_266, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x941 = _uniq_name_266; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x942 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _x = _con_x942->name;
      kk_string_dup(_x, _ctx);
      _x_x941 = _x; /*string*/
    }
  }
  kk_string_t _x_x943;
  if (kk_std_core_types__is_Optional(long_name, _ctx)) {
    kk_box_t _box_x1 = long_name._cons._Optional.value;
    kk_string_t _uniq_long_name_274 = kk_string_unbox(_box_x1);
    kk_string_dup(_uniq_long_name_274, _ctx);
    kk_std_core_types__optional_drop(long_name, _ctx);
    _x_x943 = _uniq_long_name_274; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(long_name, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x944 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _x_0 = _con_x944->long_name;
      kk_string_dup(_x_0, _ctx);
      _x_x943 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x945;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x2 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_282 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_month_prefix_282, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x945 = _uniq_month_prefix_282; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x946 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _x_1 = _con_x946->month_prefix;
      kk_string_dup(_x_1, _ctx);
      _x_x945 = _x_1; /*string*/
    }
  }
  kk_function_t _x_x947;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x6 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x6, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x947 = kk_std_time_calendar_calendar_fs__new_copy_fun948(_fun_unbox_x6, _ctx); /*(std/time/date/date) -> string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x951 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_2 = _con_x951->show_era;
      kk_function_dup(_x_2, _ctx);
      _x_x947 = _x_2; /*(std/time/date/date) -> string*/
    }
  }
  kk_function_t _x_x952;
  if (kk_std_core_types__is_Optional(instant_to_dc, _ctx)) {
    kk_box_t _fun_unbox_x15 = instant_to_dc._cons._Optional.value;
    kk_box_dup(_fun_unbox_x15, _ctx);
    kk_std_core_types__optional_drop(instant_to_dc, _ctx);
    _x_x952 = kk_std_time_calendar_calendar_fs__new_copy_fun953(_fun_unbox_x15, _ctx); /*(std/time/instant/instant, std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)*/
  }
  else {
    kk_std_core_types__optional_drop(instant_to_dc, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x956 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_3 = _con_x956->instant_to_dc;
      kk_function_dup(_x_3, _ctx);
      _x_x952 = _x_3; /*(std/time/instant/instant, std/time/duration/duration) -> (std/time/date/date, std/time/date/clock)*/
    }
  }
  kk_function_t _x_x957;
  if (kk_std_core_types__is_Optional(dc_to_instant, _ctx)) {
    kk_box_t _fun_unbox_x30 = dc_to_instant._cons._Optional.value;
    kk_box_dup(_fun_unbox_x30, _ctx);
    kk_std_core_types__optional_drop(dc_to_instant, _ctx);
    _x_x957 = kk_std_time_calendar_calendar_fs__new_copy_fun958(_fun_unbox_x30, _ctx); /*(std/time/date/date, std/time/date/clock, std/time/calendar/timezone, std/time/instant/timescale) -> std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(dc_to_instant, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x961 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_4 = _con_x961->dc_to_instant;
      kk_function_dup(_x_4, _ctx);
      _x_x957 = _x_4; /*(std/time/date/date, std/time/date/clock, std/time/calendar/timezone, std/time/instant/timescale) -> std/time/instant/instant*/
    }
  }
  kk_function_t _x_x962;
  if (kk_std_core_types__is_Optional(days_to_date, _ctx)) {
    kk_box_t _fun_unbox_x43 = days_to_date._cons._Optional.value;
    kk_box_dup(_fun_unbox_x43, _ctx);
    kk_std_core_types__optional_drop(days_to_date, _ctx);
    _x_x962 = kk_std_time_calendar_calendar_fs__new_copy_fun963(_fun_unbox_x43, _ctx); /*(int) -> std/time/date/date*/
  }
  else {
    kk_std_core_types__optional_drop(days_to_date, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x966 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_function_t _x_5 = _con_x966->days_to_date;
      kk_function_dup(_x_5, _ctx);
      _x_x962 = _x_5; /*(int) -> std/time/date/date*/
    }
  }
  kk_function_t _x_x967;
  if (kk_std_core_types__is_Optional(date_to_days, _ctx)) {
    kk_box_t _fun_unbox_x50 = date_to_days._cons._Optional.value;
    kk_box_dup(_fun_unbox_x50, _ctx);
    kk_std_core_types__optional_drop(date_to_days, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(8)), _ctx);
    _x_x967 = kk_std_time_calendar_calendar_fs__new_copy_fun968(_fun_unbox_x50, _ctx); /*(std/time/date/date) -> int*/
  }
  else {
    kk_std_core_types__optional_drop(date_to_days, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x971 = kk_std_time_calendar__as_Calendar(_this, _ctx);
      kk_string_t _pat_0_7 = _con_x971->name;
      kk_string_t _pat_1_8 = _con_x971->long_name;
      kk_string_t _pat_2_7 = _con_x971->month_prefix;
      kk_function_t _pat_3_7 = _con_x971->show_era;
      kk_function_t _pat_4_7 = _con_x971->instant_to_dc;
      kk_function_t _pat_5_7 = _con_x971->dc_to_instant;
      kk_function_t _pat_6_7 = _con_x971->days_to_date;
      kk_function_t _x_6 = _con_x971->date_to_days;
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
      _x_x967 = _x_6; /*(std/time/date/date) -> int*/
    }
  }
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, _x_x941, _x_x943, _x_x945, _x_x947, _x_x952, _x_x957, _x_x962, _x_x967, _ctx);
}
 
// Check if two calendars use the same date calculations. (Display of era names etc. may differ)

bool kk_std_time_calendar__lp__eq__eq__rp_(kk_std_time_calendar__calendar c1, kk_std_time_calendar__calendar c2, kk_context_t* _ctx) { /* (c1 : calendar, c2 : calendar) -> bool */ 
  kk_string_t _x_x973;
  {
    struct kk_std_time_calendar_Calendar* _con_x974 = kk_std_time_calendar__as_Calendar(c1, _ctx);
    kk_string_t _pat_0 = _con_x974->name;
    kk_string_t _x = _con_x974->long_name;
    kk_string_t _pat_1 = _con_x974->month_prefix;
    kk_function_t _pat_2 = _con_x974->show_era;
    kk_function_t _pat_3 = _con_x974->instant_to_dc;
    kk_function_t _pat_4 = _con_x974->dc_to_instant;
    kk_function_t _pat_5 = _con_x974->days_to_date;
    kk_function_t _pat_6 = _con_x974->date_to_days;
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
    _x_x973 = _x; /*string*/
  }
  kk_string_t _x_x975;
  {
    struct kk_std_time_calendar_Calendar* _con_x976 = kk_std_time_calendar__as_Calendar(c2, _ctx);
    kk_string_t _pat_0_0 = _con_x976->name;
    kk_string_t _x_0 = _con_x976->long_name;
    kk_string_t _pat_1_0 = _con_x976->month_prefix;
    kk_function_t _pat_2_0 = _con_x976->show_era;
    kk_function_t _pat_3_0 = _con_x976->instant_to_dc;
    kk_function_t _pat_4_0 = _con_x976->dc_to_instant;
    kk_function_t _pat_5_0 = _con_x976->days_to_date;
    kk_function_t _pat_6_0 = _con_x976->date_to_days;
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
    _x_x975 = _x_0; /*string*/
  }
  return kk_string_is_eq(_x_x973,_x_x975,kk_context());
}
 
// Same timezone?

bool kk_std_time_calendar_timezone_fs__lp__eq__eq__rp_(kk_std_time_calendar__timezone tz1, kk_std_time_calendar__timezone tz2, kk_context_t* _ctx) { /* (tz1 : timezone, tz2 : timezone) -> bool */ 
  kk_string_t _x_x977;
  {
    struct kk_std_time_calendar_Timezone* _con_x978 = kk_std_time_calendar__as_Timezone(tz1, _ctx);
    kk_string_t _x = _con_x978->name;
    kk_function_t _pat_0 = _con_x978->utc_delta;
    kk_function_t _pat_1 = _con_x978->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(tz1, _ctx)) {
      kk_function_drop(_pat_1, _ctx);
      kk_function_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(tz1, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(tz1, _ctx);
    }
    _x_x977 = _x; /*string*/
  }
  kk_string_t _x_x979;
  {
    struct kk_std_time_calendar_Timezone* _con_x980 = kk_std_time_calendar__as_Timezone(tz2, _ctx);
    kk_string_t _x_0 = _con_x980->name;
    kk_function_t _pat_0_0 = _con_x980->utc_delta;
    kk_function_t _pat_1_0 = _con_x980->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(tz2, _ctx)) {
      kk_function_drop(_pat_1_0, _ctx);
      kk_function_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(tz2, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(tz2, _ctx);
    }
    _x_x979 = _x_0; /*string*/
  }
  return kk_string_is_eq(_x_x977,_x_x979,kk_context());
}
extern kk_std_core_types__maybe kk_std_time_calendar__create_Timezone_fun982(kk_function_t _fself, kk_std_time_instant__instant _b_x60, kk_context_t* _ctx) {
  struct kk_std_time_calendar__create_Timezone_fun982__t* _self = kk_function_as(struct kk_std_time_calendar__create_Timezone_fun982__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x57 = _self->_fun_unbox_x57; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x57, _ctx);}, {}, _ctx)
  kk_box_t _x_x983;
  kk_function_t _x_x984 = kk_function_unbox(_fun_unbox_x57, _ctx); /*(58) -> 59*/
  _x_x983 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x984, (_x_x984, kk_std_time_instant__instant_box(_b_x60, _ctx), _ctx), _ctx); /*59*/
  return kk_std_core_types__maybe_unbox(_x_x983, KK_OWNED, _ctx);
}
extern kk_std_core_types__maybe kk_std_time_calendar__create_Timezone_fun985(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__instant_drop(i, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}


// lift anonymous function
struct kk_std_time_calendar_timezone_fs__copy_fun991__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x65;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_timezone_fs__copy_fun991(kk_function_t _fself, kk_std_time_instant__instant _b_x68, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_timezone_fs__new_copy_fun991(kk_box_t _fun_unbox_x65, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun991__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_timezone_fs__copy_fun991__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_timezone_fs__copy_fun991, kk_context());
  _self->_fun_unbox_x65 = _fun_unbox_x65;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_timezone_fs__copy_fun991(kk_function_t _fself, kk_std_time_instant__instant _b_x68, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun991__t* _self = kk_function_as(struct kk_std_time_calendar_timezone_fs__copy_fun991__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x65 = _self->_fun_unbox_x65; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x65, _ctx);}, {}, _ctx)
  kk_box_t _x_x992;
  kk_function_t _x_x993 = kk_function_unbox(_fun_unbox_x65, _ctx); /*(66) -> 67*/
  _x_x992 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x993, (_x_x993, kk_std_time_instant__instant_box(_b_x68, _ctx), _ctx), _ctx); /*67*/
  return kk_std_core_types__tuple2_unbox(_x_x992, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_timezone_fs__copy_fun996__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x72;
};
static kk_std_core_types__maybe kk_std_time_calendar_timezone_fs__copy_fun996(kk_function_t _fself, kk_std_time_instant__instant _b_x75, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_timezone_fs__new_copy_fun996(kk_box_t _fun_unbox_x72, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun996__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_timezone_fs__copy_fun996__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_timezone_fs__copy_fun996, kk_context());
  _self->_fun_unbox_x72 = _fun_unbox_x72;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_timezone_fs__copy_fun996(kk_function_t _fself, kk_std_time_instant__instant _b_x75, kk_context_t* _ctx) {
  struct kk_std_time_calendar_timezone_fs__copy_fun996__t* _self = kk_function_as(struct kk_std_time_calendar_timezone_fs__copy_fun996__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x72 = _self->_fun_unbox_x72; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x72, _ctx);}, {}, _ctx)
  kk_box_t _x_x997;
  kk_function_t _x_x998 = kk_function_unbox(_fun_unbox_x72, _ctx); /*(73) -> 74*/
  _x_x997 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x998, (_x_x998, kk_std_time_instant__instant_box(_b_x75, _ctx), _ctx), _ctx); /*74*/
  return kk_std_core_types__maybe_unbox(_x_x997, KK_OWNED, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_calendar_timezone_fs__copy(kk_std_time_calendar__timezone _this, kk_std_core_types__optional name, kk_std_core_types__optional utc_delta, kk_std_core_types__optional utc_inverse, kk_context_t* _ctx) { /* (timezone, name : ? string, utc-delta : ? ((std/time/instant/instant) -> (std/time/duration/duration, string)), utc-inverse : ? ((std/time/instant/instant) -> maybe<std/time/instant/instant>)) -> timezone */ 
  kk_string_t _x_x988;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x61 = name._cons._Optional.value;
    kk_string_t _uniq_name_733 = kk_string_unbox(_box_x61);
    kk_string_dup(_uniq_name_733, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x988 = _uniq_name_733; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_std_time_calendar_Timezone* _con_x989 = kk_std_time_calendar__as_Timezone(_this, _ctx);
      kk_string_t _x = _con_x989->name;
      kk_string_dup(_x, _ctx);
      _x_x988 = _x; /*string*/
    }
  }
  kk_function_t _x_x990;
  if (kk_std_core_types__is_Optional(utc_delta, _ctx)) {
    kk_box_t _fun_unbox_x65 = utc_delta._cons._Optional.value;
    kk_box_dup(_fun_unbox_x65, _ctx);
    kk_std_core_types__optional_drop(utc_delta, _ctx);
    _x_x990 = kk_std_time_calendar_timezone_fs__new_copy_fun991(_fun_unbox_x65, _ctx); /*(std/time/instant/instant) -> (std/time/duration/duration, string)*/
  }
  else {
    kk_std_core_types__optional_drop(utc_delta, _ctx);
    {
      struct kk_std_time_calendar_Timezone* _con_x994 = kk_std_time_calendar__as_Timezone(_this, _ctx);
      kk_function_t _x_0 = _con_x994->utc_delta;
      kk_function_dup(_x_0, _ctx);
      _x_x990 = _x_0; /*(std/time/instant/instant) -> (std/time/duration/duration, string)*/
    }
  }
  kk_function_t _x_x995;
  if (kk_std_core_types__is_Optional(utc_inverse, _ctx)) {
    kk_box_t _fun_unbox_x72 = utc_inverse._cons._Optional.value;
    kk_box_dup(_fun_unbox_x72, _ctx);
    kk_std_core_types__optional_drop(utc_inverse, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x995 = kk_std_time_calendar_timezone_fs__new_copy_fun996(_fun_unbox_x72, _ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  else {
    kk_std_core_types__optional_drop(utc_inverse, _ctx);
    {
      struct kk_std_time_calendar_Timezone* _con_x999 = kk_std_time_calendar__as_Timezone(_this, _ctx);
      kk_string_t _pat_0_2 = _con_x999->name;
      kk_function_t _pat_1_3 = _con_x999->utc_delta;
      kk_function_t _x_1 = _con_x999->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_function_drop(_pat_1_3, _ctx);
        kk_string_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_function_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x995 = _x_1; /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
    }
  }
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, _x_x988, _x_x990, _x_x995, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_string_fs_tz_fixed_fun1000__t {
  struct kk_function_s _base;
  kk_std_core_types__optional abbrv;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_string_fs_tz_fixed_fun1000(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_string_fs_new_tz_fixed_fun1000(kk_std_core_types__optional abbrv, kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun1000__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun1000__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_string_fs_tz_fixed_fun1000, kk_context());
  _self->abbrv = abbrv;
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_string_fs_tz_fixed_fun1000(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun1000__t* _self = kk_function_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun1000__t*, _fself, _ctx);
  kk_std_core_types__optional abbrv = _self->abbrv; /* ? string */
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(abbrv, _ctx);kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant_drop(i_0, _ctx);
  kk_box_t _x_x1001;
  kk_string_t _x_x1002;
  if (kk_std_core_types__is_Optional(abbrv, _ctx)) {
    kk_box_t _box_x76 = abbrv._cons._Optional.value;
    kk_string_t _uniq_abbrv_780 = kk_string_unbox(_box_x76);
    kk_string_dup(_uniq_abbrv_780, _ctx);
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x1002 = _uniq_abbrv_780; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x1002 = kk_string_empty(); /*string*/
  }
  _x_x1001 = kk_string_box(_x_x1002); /*10038*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(delta, _ctx), _x_x1001, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_string_fs_tz_fixed_fun1004__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__maybe kk_std_time_calendar_string_fs_tz_fixed_fun1004(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_string_fs_new_tz_fixed_fun1004(kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun1004__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun1004__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_string_fs_tz_fixed_fun1004, kk_context());
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_string_fs_tz_fixed_fun1004(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_string_fs_tz_fixed_fun1004__t* _self = kk_function_as(struct kk_std_time_calendar_string_fs_tz_fixed_fun1004__t*, _fself, _ctx);
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  bool _match_x854;
  double _x_x1005;
  {
    kk_std_num_ddouble__ddouble _x_0 = delta.secs;
    {
      double _x = _x_0.hi;
      _x_x1005 = _x; /*float64*/
    }
  }
  _match_x854 = (_x_x1005 == (0x0p+0)); /*bool*/
  if (_match_x854) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_0, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

kk_std_time_calendar__timezone kk_std_time_calendar_string_fs_tz_fixed(kk_string_t name, kk_std_time_duration__duration delta, kk_std_core_types__optional abbrv, kk_context_t* _ctx) { /* (name : string, delta : std/time/duration/duration, abbrv : ? string) -> timezone */ 
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, name, kk_std_time_calendar_string_fs_new_tz_fixed_fun1000(abbrv, delta, _ctx), kk_std_time_calendar_string_fs_new_tz_fixed_fun1004(delta, _ctx), _ctx);
}
 
// The standard UTC time zone with a 0 delta.


// lift anonymous function
struct kk_std_time_calendar_tz_utc_fun1008__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_utc_fun1008(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_utc_fun1008(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_tz_utc_fun1008, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_utc_fun1008(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__instant_drop(i_0, _ctx);
  kk_box_t _x_x1009;
  kk_string_t _x_x1010;
  kk_std_core_types__optional _match_x853 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x853, _ctx)) {
    kk_box_t _box_x83 = _match_x853._cons._Optional.value;
    kk_string_t _uniq_abbrv_780 = kk_string_unbox(_box_x83);
    kk_string_dup(_uniq_abbrv_780, _ctx);
    kk_std_core_types__optional_drop(_match_x853, _ctx);
    _x_x1010 = _uniq_abbrv_780; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x853, _ctx);
    _x_x1010 = kk_string_empty(); /*string*/
  }
  _x_x1009 = kk_string_box(_x_x1010); /*10038*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(kk_std_time_duration_zero, _ctx), _x_x1009, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_utc_fun1012__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_utc_fun1012(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_utc_fun1012(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_tz_utc_fun1012, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_utc_fun1012(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _match_x852;
  double _x_x1013;
  kk_std_time_duration__duration _x_x1014 = kk_std_time_duration_zero; /*std/time/duration/duration*/
  {
    kk_std_num_ddouble__ddouble _x_0 = _x_x1014.secs;
    {
      double _x = _x_0.hi;
      _x_x1013 = _x; /*float64*/
    }
  }
  _match_x852 = (_x_x1013 == (0x0p+0)); /*bool*/
  if (_match_x852) {
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
struct kk_std_time_calendar_tz_fixed_fun1050__t {
  struct kk_function_s _base;
  kk_std_core_types__optional abbrv;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun1050(kk_function_t _fself, kk_std_time_instant__instant i_4, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun1050(kk_std_core_types__optional abbrv, kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1050__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun1050__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun1050, kk_context());
  _self->abbrv = abbrv;
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun1050(kk_function_t _fself, kk_std_time_instant__instant i_4, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1050__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun1050__t*, _fself, _ctx);
  kk_std_core_types__optional abbrv = _self->abbrv; /* ? string */
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(abbrv, _ctx);kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant_drop(i_4, _ctx);
  kk_box_t _x_x1051;
  kk_string_t _x_x1052;
  if (kk_std_core_types__is_Optional(abbrv, _ctx)) {
    kk_box_t _box_x100 = abbrv._cons._Optional.value;
    kk_string_t _uniq_abbrv_852 = kk_string_unbox(_box_x100);
    kk_string_dup(_uniq_abbrv_852, _ctx);
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x1052 = _uniq_abbrv_852; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x1052 = kk_string_empty(); /*string*/
  }
  _x_x1051 = kk_string_box(_x_x1052); /*10038*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(delta, _ctx), _x_x1051, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun1054__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration delta;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun1054(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun1054(kk_std_time_duration__duration delta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1054__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun1054__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun1054, kk_context());
  _self->delta = delta;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun1054(kk_function_t _fself, kk_std_time_instant__instant i_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1054__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun1054__t*, _fself, _ctx);
  kk_std_time_duration__duration delta = _self->delta; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(delta, _ctx);}, {}, _ctx)
  bool _match_x840;
  double _x_x1055;
  {
    kk_std_num_ddouble__ddouble _x_0 = delta.secs;
    {
      double _x = _x_0.hi;
      _x_x1055 = _x; /*float64*/
    }
  }
  _match_x840 = (_x_x1055 == (0x0p+0)); /*bool*/
  if (_match_x840) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_0, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun1091__t {
  struct kk_function_s _base;
  kk_std_core_types__optional abbrv;
  kk_std_time_duration__duration delta_0_0;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun1091(kk_function_t _fself, kk_std_time_instant__instant i_10, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun1091(kk_std_core_types__optional abbrv, kk_std_time_duration__duration delta_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1091__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun1091__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun1091, kk_context());
  _self->abbrv = abbrv;
  _self->delta_0_0 = delta_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_fixed_fun1091(kk_function_t _fself, kk_std_time_instant__instant i_10, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1091__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun1091__t*, _fself, _ctx);
  kk_std_core_types__optional abbrv = _self->abbrv; /* ? string */
  kk_std_time_duration__duration delta_0_0 = _self->delta_0_0; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(abbrv, _ctx);kk_std_time_duration__duration_dup(delta_0_0, _ctx);}, {}, _ctx)
  kk_std_time_instant__instant_drop(i_10, _ctx);
  kk_box_t _x_x1092;
  kk_string_t _x_x1093;
  if (kk_std_core_types__is_Optional(abbrv, _ctx)) {
    kk_box_t _box_x113 = abbrv._cons._Optional.value;
    kk_string_t _uniq_abbrv_852_0 = kk_string_unbox(_box_x113);
    kk_string_dup(_uniq_abbrv_852_0, _ctx);
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x1093 = _uniq_abbrv_852_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(abbrv, _ctx);
    _x_x1093 = kk_string_empty(); /*string*/
  }
  _x_x1092 = kk_string_box(_x_x1093); /*10038*/
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(delta_0_0, _ctx), _x_x1092, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_fixed_fun1095__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration delta_0_0;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun1095(kk_function_t _fself, kk_std_time_instant__instant i_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_fixed_fun1095(kk_std_time_duration__duration delta_0_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1095__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_fixed_fun1095__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_fixed_fun1095, kk_context());
  _self->delta_0_0 = delta_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_fixed_fun1095(kk_function_t _fself, kk_std_time_instant__instant i_0_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_fixed_fun1095__t* _self = kk_function_as(struct kk_std_time_calendar_tz_fixed_fun1095__t*, _fself, _ctx);
  kk_std_time_duration__duration delta_0_0 = _self->delta_0_0; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(delta_0_0, _ctx);}, {}, _ctx)
  bool _match_x827;
  double _x_x1096;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = delta_0_0.secs;
    {
      double _x_1 = _x_0_0.hi;
      _x_x1096 = _x_1; /*float64*/
    }
  }
  _match_x827 = (_x_x1096 == (0x0p+0)); /*bool*/
  if (_match_x827) {
    return kk_std_core_types__new_Just(kk_std_time_instant__instant_box(i_0_1, _ctx), _ctx);
  }
  {
    kk_std_time_instant__instant_drop(i_0_1, _ctx);
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
  bool _match_x826 = kk_integer_is_zero_borrow(hours); /*bool*/;
  if (_match_x826) {
    bool _match_x839 = kk_integer_is_zero_borrow(_uniq_mins_843); /*bool*/;
    if (_match_x839) {
      kk_std_core_types__optional_drop(name, _ctx);
      kk_std_core_types__optional_drop(hourwidth, _ctx);
      kk_integer_drop(hours, _ctx);
      kk_std_core_types__optional_drop(abbrv, _ctx);
      kk_integer_drop(_uniq_mins_843, _ctx);
      return kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx);
    }
    {
      kk_integer_t xmins;
      bool _match_x850 = kk_integer_gt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x850) {
        kk_integer_t _x_x1015 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
        xmins = kk_integer_abs(_x_x1015,kk_context()); /*int*/
      }
      else {
        bool _match_x851 = kk_integer_lt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x851) {
          kk_integer_t i_1_10028;
          kk_integer_t _x_x1016 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
          i_1_10028 = kk_integer_abs(_x_x1016,kk_context()); /*int*/
          xmins = kk_integer_neg(i_1_10028,kk_context()); /*int*/
        }
        else {
          xmins = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
        }
      }
      kk_integer_t x_10029;
      kk_integer_t _x_x1017 = kk_integer_dup(hours, _ctx); /*int*/
      x_10029 = kk_integer_mul(_x_x1017,(kk_integer_from_small(3600)),kk_context()); /*int*/
      kk_integer_t y_10030 = kk_integer_mul(xmins,(kk_integer_from_small(60)),kk_context()); /*int*/;
      kk_integer_t secs = kk_integer_add(x_10029,y_10030,kk_context()); /*int*/;
      kk_string_t s_10034;
      kk_integer_t _x_x1018 = kk_integer_abs(hours,kk_context()); /*int*/
      s_10034 = kk_std_core_int_show(_x_x1018, _ctx); /*string*/
      kk_integer_t n;
      kk_string_t _x_x1019 = kk_string_dup(s_10034, _ctx); /*string*/
      n = kk_std_core_string_chars_fs_count(_x_x1019, _ctx); /*int*/
      kk_string_t y_0_10032;
      kk_string_t _x_x1020;
      kk_define_string_literal(, _s_x1021, 3, "UTC", _ctx)
      _x_x1020 = kk_string_dup(_s_x1021, _ctx); /*string*/
      kk_string_t _x_x1022;
      kk_string_t _x_x1023;
      bool _match_x849 = kk_integer_lt_borrow(secs,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x849) {
        kk_define_string_literal(, _s_x1024, 1, "-", _ctx)
        _x_x1023 = kk_string_dup(_s_x1024, _ctx); /*string*/
      }
      else {
        kk_define_string_literal(, _s_x1025, 1, "+", _ctx)
        _x_x1023 = kk_string_dup(_s_x1025, _ctx); /*string*/
      }
      kk_string_t _x_x1026;
      kk_string_t _x_x1027;
      bool _match_x846;
      kk_integer_t _brw_x847;
      if (kk_std_core_types__is_Optional(hourwidth, _ctx)) {
        kk_box_t _box_x91 = hourwidth._cons._Optional.value;
        kk_integer_t _uniq_hourwidth_856 = kk_integer_unbox(_box_x91, _ctx);
        kk_integer_dup(_uniq_hourwidth_856, _ctx);
        _brw_x847 = _uniq_hourwidth_856; /*int*/
      }
      else {
        _brw_x847 = kk_integer_from_small(1); /*int*/
      }
      bool _brw_x848 = kk_integer_lte_borrow(_brw_x847,n,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x847, _ctx);
      _match_x846 = _brw_x848; /*bool*/
      if (_match_x846) {
        kk_integer_drop(n, _ctx);
        kk_std_core_types__optional_drop(hourwidth, _ctx);
        _x_x1027 = s_10034; /*string*/
      }
      else {
        kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10012;
        kk_integer_t _x_x1028;
        if (kk_std_core_types__is_Optional(hourwidth, _ctx)) {
          kk_box_t _box_x92 = hourwidth._cons._Optional.value;
          kk_integer_t _uniq_hourwidth_856_0 = kk_integer_unbox(_box_x92, _ctx);
          kk_integer_dup(_uniq_hourwidth_856_0, _ctx);
          kk_std_core_types__optional_drop(hourwidth, _ctx);
          _x_x1028 = _uniq_hourwidth_856_0; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(hourwidth, _ctx);
          _x_x1028 = kk_integer_from_small(1); /*int*/
        }
        n_0_10012 = kk_integer_sub(_x_x1028,n,kk_context()); /*int*/
        kk_string_t _x_x1029 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
        _x_x1027 = kk_std_core_types__lp__plus__plus__rp_(_x_x1029, s_10034, _ctx); /*string*/
      }
      kk_string_t _x_x1030;
      bool _match_x844 = kk_integer_is_zero_borrow(_uniq_mins_843); /*bool*/;
      if (_match_x844) {
        kk_integer_drop(_uniq_mins_843, _ctx);
        _x_x1030 = kk_string_empty(); /*string*/
      }
      else {
        kk_string_t s_0_10037;
        kk_integer_t _x_x1032 = kk_integer_abs(_uniq_mins_843,kk_context()); /*int*/
        s_0_10037 = kk_std_core_int_show(_x_x1032, _ctx); /*string*/
        kk_integer_t n_0;
        kk_string_t _x_x1033 = kk_string_dup(s_0_10037, _ctx); /*string*/
        n_0 = kk_std_core_string_chars_fs_count(_x_x1033, _ctx); /*int*/
        kk_string_t _x_x1034;
        kk_define_string_literal(, _s_x1035, 1, ":", _ctx)
        _x_x1034 = kk_string_dup(_s_x1035, _ctx); /*string*/
        kk_string_t _x_x1036;
        bool _match_x845 = kk_integer_lte_borrow((kk_integer_from_small(2)),n_0,kk_context()); /*bool*/;
        if (_match_x845) {
          kk_integer_drop(n_0, _ctx);
          _x_x1036 = s_0_10037; /*string*/
        }
        else {
          kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
          kk_integer_t n_0_10012_0 = kk_integer_sub((kk_integer_from_small(2)),n_0,kk_context()); /*int*/;
          kk_string_t _x_x1037 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
          _x_x1036 = kk_std_core_types__lp__plus__plus__rp_(_x_x1037, s_0_10037, _ctx); /*string*/
        }
        _x_x1030 = kk_std_core_types__lp__plus__plus__rp_(_x_x1034, _x_x1036, _ctx); /*string*/
      }
      _x_x1026 = kk_std_core_types__lp__plus__plus__rp_(_x_x1027, _x_x1030, _ctx); /*string*/
      _x_x1022 = kk_std_core_types__lp__plus__plus__rp_(_x_x1023, _x_x1026, _ctx); /*string*/
      y_0_10032 = kk_std_core_types__lp__plus__plus__rp_(_x_x1020, _x_x1022, _ctx); /*string*/
      kk_string_t tzonename;
      bool _match_x843;
      kk_string_t _x_x1038;
      if (kk_std_core_types__is_Optional(name, _ctx)) {
        kk_box_t _box_x93 = name._cons._Optional.value;
        kk_string_t _uniq_name_848 = kk_string_unbox(_box_x93);
        kk_string_dup(_uniq_name_848, _ctx);
        _x_x1038 = _uniq_name_848; /*string*/
      }
      else {
        _x_x1038 = kk_string_empty(); /*string*/
      }
      kk_string_t _x_x1040 = kk_string_empty(); /*string*/
      _match_x843 = kk_string_is_eq(_x_x1038,_x_x1040,kk_context()); /*bool*/
      if (_match_x843) {
        kk_std_core_types__optional_drop(name, _ctx);
        tzonename = y_0_10032; /*string*/
      }
      else {
        kk_string_drop(y_0_10032, _ctx);
        if (kk_std_core_types__is_Optional(name, _ctx)) {
          kk_box_t _box_x94 = name._cons._Optional.value;
          kk_string_t _uniq_name_848_0 = kk_string_unbox(_box_x94);
          kk_string_dup(_uniq_name_848_0, _ctx);
          kk_std_core_types__optional_drop(name, _ctx);
          tzonename = _uniq_name_848_0; /*string*/
        }
        else {
          kk_std_core_types__optional_drop(name, _ctx);
          tzonename = kk_string_empty(); /*string*/
        }
      }
      kk_std_core_types__optional frac_0_10006;
      kk_box_t _x_x1043;
      double _x_x1044;
      kk_std_core_types__optional _match_x842 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x842, _ctx)) {
        kk_box_t _box_x95 = _match_x842._cons._Optional.value;
        double _uniq_frac_155 = kk_double_unbox(_box_x95, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x842, _ctx);
        _x_x1044 = _uniq_frac_155; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x842, _ctx);
        _x_x1044 = 0x0p+0; /*float64*/
      }
      _x_x1043 = kk_double_box(_x_x1044, _ctx); /*10003*/
      frac_0_10006 = kk_std_core_types__new_Optional(_x_x1043, _ctx); /*? float64*/
      kk_std_time_duration__duration delta;
      kk_std_num_ddouble__ddouble _x_x1045;
      bool _match_x841;
      double _x_x1046;
      if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
        kk_box_t _box_x98 = frac_0_10006._cons._Optional.value;
        double _uniq_frac_1144 = kk_double_unbox(_box_x98, KK_BORROWED, _ctx);
        _x_x1046 = _uniq_frac_1144; /*float64*/
      }
      else {
        _x_x1046 = 0x0p+0; /*float64*/
      }
      _match_x841 = (_x_x1046 == (0x0p+0)); /*bool*/
      if (_match_x841) {
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1045 = kk_std_num_ddouble_ddouble_int_exp(secs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble _x_x1047 = kk_std_num_ddouble_ddouble_int_exp(secs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _x_x1048;
        double _x_x1049;
        if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
          kk_box_t _box_x99 = frac_0_10006._cons._Optional.value;
          double _uniq_frac_1144_0 = kk_double_unbox(_box_x99, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(frac_0_10006, _ctx);
          _x_x1049 = _uniq_frac_1144_0; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(frac_0_10006, _ctx);
          _x_x1049 = 0x0p+0; /*float64*/
        }
        _x_x1048 = kk_std_num_ddouble__new_Ddouble(_x_x1049, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1045 = kk_std_num_ddouble__lp__plus__rp_(_x_x1047, _x_x1048, _ctx); /*std/num/ddouble/ddouble*/
      }
      delta = kk_std_time_duration__new_Duration(_x_x1045, _ctx); /*std/time/duration/duration*/
      return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, tzonename, kk_std_time_calendar_new_tz_fixed_fun1050(abbrv, delta, _ctx), kk_std_time_calendar_new_tz_fixed_fun1054(delta, _ctx), _ctx);
    }
  }
  {
    kk_integer_t xmins_0;
    bool _match_x837 = kk_integer_gt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x837) {
      kk_integer_t _x_x1056 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
      xmins_0 = kk_integer_abs(_x_x1056,kk_context()); /*int*/
    }
    else {
      bool _match_x838 = kk_integer_lt_borrow(hours,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x838) {
        kk_integer_t i_7_10051;
        kk_integer_t _x_x1057 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
        i_7_10051 = kk_integer_abs(_x_x1057,kk_context()); /*int*/
        xmins_0 = kk_integer_neg(i_7_10051,kk_context()); /*int*/
      }
      else {
        xmins_0 = kk_integer_dup(_uniq_mins_843, _ctx); /*int*/
      }
    }
    kk_integer_t x_1_10052;
    kk_integer_t _x_x1058 = kk_integer_dup(hours, _ctx); /*int*/
    x_1_10052 = kk_integer_mul(_x_x1058,(kk_integer_from_small(3600)),kk_context()); /*int*/
    kk_integer_t y_1_10053 = kk_integer_mul(xmins_0,(kk_integer_from_small(60)),kk_context()); /*int*/;
    kk_integer_t secs_0_0 = kk_integer_add(x_1_10052,y_1_10053,kk_context()); /*int*/;
    kk_string_t s_1_10057;
    kk_integer_t _x_x1059 = kk_integer_abs(hours,kk_context()); /*int*/
    s_1_10057 = kk_std_core_int_show(_x_x1059, _ctx); /*string*/
    kk_integer_t n_1;
    kk_string_t _x_x1060 = kk_string_dup(s_1_10057, _ctx); /*string*/
    n_1 = kk_std_core_string_chars_fs_count(_x_x1060, _ctx); /*int*/
    kk_string_t y_2_10055;
    kk_string_t _x_x1061;
    kk_define_string_literal(, _s_x1062, 3, "UTC", _ctx)
    _x_x1061 = kk_string_dup(_s_x1062, _ctx); /*string*/
    kk_string_t _x_x1063;
    kk_string_t _x_x1064;
    bool _match_x836 = kk_integer_lt_borrow(secs_0_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x836) {
      kk_define_string_literal(, _s_x1065, 1, "-", _ctx)
      _x_x1064 = kk_string_dup(_s_x1065, _ctx); /*string*/
    }
    else {
      kk_define_string_literal(, _s_x1066, 1, "+", _ctx)
      _x_x1064 = kk_string_dup(_s_x1066, _ctx); /*string*/
    }
    kk_string_t _x_x1067;
    kk_string_t _x_x1068;
    bool _match_x833;
    kk_integer_t _brw_x834;
    if (kk_std_core_types__is_Optional(hourwidth, _ctx)) {
      kk_box_t _box_x104 = hourwidth._cons._Optional.value;
      kk_integer_t _uniq_hourwidth_856_0_0 = kk_integer_unbox(_box_x104, _ctx);
      kk_integer_dup(_uniq_hourwidth_856_0_0, _ctx);
      _brw_x834 = _uniq_hourwidth_856_0_0; /*int*/
    }
    else {
      _brw_x834 = kk_integer_from_small(1); /*int*/
    }
    bool _brw_x835 = kk_integer_lte_borrow(_brw_x834,n_1,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x834, _ctx);
    _match_x833 = _brw_x835; /*bool*/
    if (_match_x833) {
      kk_integer_drop(n_1, _ctx);
      kk_std_core_types__optional_drop(hourwidth, _ctx);
      _x_x1068 = s_1_10057; /*string*/
    }
    else {
      kk_string_t s_0_10011_1 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012_1;
      kk_integer_t _x_x1069;
      if (kk_std_core_types__is_Optional(hourwidth, _ctx)) {
        kk_box_t _box_x105 = hourwidth._cons._Optional.value;
        kk_integer_t _uniq_hourwidth_856_0_1 = kk_integer_unbox(_box_x105, _ctx);
        kk_integer_dup(_uniq_hourwidth_856_0_1, _ctx);
        kk_std_core_types__optional_drop(hourwidth, _ctx);
        _x_x1069 = _uniq_hourwidth_856_0_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(hourwidth, _ctx);
        _x_x1069 = kk_integer_from_small(1); /*int*/
      }
      n_0_10012_1 = kk_integer_sub(_x_x1069,n_1,kk_context()); /*int*/
      kk_string_t _x_x1070 = kk_std_core_string_repeatz(s_0_10011_1, kk_std_core_int_ssize__t(n_0_10012_1, _ctx), _ctx); /*string*/
      _x_x1068 = kk_std_core_types__lp__plus__plus__rp_(_x_x1070, s_1_10057, _ctx); /*string*/
    }
    kk_string_t _x_x1071;
    bool _match_x831 = kk_integer_is_zero_borrow(_uniq_mins_843); /*bool*/;
    if (_match_x831) {
      kk_integer_drop(_uniq_mins_843, _ctx);
      _x_x1071 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t s_2_10060;
      kk_integer_t _x_x1073 = kk_integer_abs(_uniq_mins_843,kk_context()); /*int*/
      s_2_10060 = kk_std_core_int_show(_x_x1073, _ctx); /*string*/
      kk_integer_t n_2;
      kk_string_t _x_x1074 = kk_string_dup(s_2_10060, _ctx); /*string*/
      n_2 = kk_std_core_string_chars_fs_count(_x_x1074, _ctx); /*int*/
      kk_string_t _x_x1075;
      kk_define_string_literal(, _s_x1076, 1, ":", _ctx)
      _x_x1075 = kk_string_dup(_s_x1076, _ctx); /*string*/
      kk_string_t _x_x1077;
      bool _match_x832 = kk_integer_lte_borrow((kk_integer_from_small(2)),n_2,kk_context()); /*bool*/;
      if (_match_x832) {
        kk_integer_drop(n_2, _ctx);
        _x_x1077 = s_2_10060; /*string*/
      }
      else {
        kk_string_t s_0_10011_2 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10012_2 = kk_integer_sub((kk_integer_from_small(2)),n_2,kk_context()); /*int*/;
        kk_string_t _x_x1078 = kk_std_core_string_repeatz(s_0_10011_2, kk_std_core_int_ssize__t(n_0_10012_2, _ctx), _ctx); /*string*/
        _x_x1077 = kk_std_core_types__lp__plus__plus__rp_(_x_x1078, s_2_10060, _ctx); /*string*/
      }
      _x_x1071 = kk_std_core_types__lp__plus__plus__rp_(_x_x1075, _x_x1077, _ctx); /*string*/
    }
    _x_x1067 = kk_std_core_types__lp__plus__plus__rp_(_x_x1068, _x_x1071, _ctx); /*string*/
    _x_x1063 = kk_std_core_types__lp__plus__plus__rp_(_x_x1064, _x_x1067, _ctx); /*string*/
    y_2_10055 = kk_std_core_types__lp__plus__plus__rp_(_x_x1061, _x_x1063, _ctx); /*string*/
    kk_string_t tzonename_0;
    bool _match_x830;
    kk_string_t _x_x1079;
    if (kk_std_core_types__is_Optional(name, _ctx)) {
      kk_box_t _box_x106 = name._cons._Optional.value;
      kk_string_t _uniq_name_848_0_0 = kk_string_unbox(_box_x106);
      kk_string_dup(_uniq_name_848_0_0, _ctx);
      _x_x1079 = _uniq_name_848_0_0; /*string*/
    }
    else {
      _x_x1079 = kk_string_empty(); /*string*/
    }
    kk_string_t _x_x1081 = kk_string_empty(); /*string*/
    _match_x830 = kk_string_is_eq(_x_x1079,_x_x1081,kk_context()); /*bool*/
    if (_match_x830) {
      kk_std_core_types__optional_drop(name, _ctx);
      tzonename_0 = y_2_10055; /*string*/
    }
    else {
      kk_string_drop(y_2_10055, _ctx);
      if (kk_std_core_types__is_Optional(name, _ctx)) {
        kk_box_t _box_x107 = name._cons._Optional.value;
        kk_string_t _uniq_name_848_0_1 = kk_string_unbox(_box_x107);
        kk_string_dup(_uniq_name_848_0_1, _ctx);
        kk_std_core_types__optional_drop(name, _ctx);
        tzonename_0 = _uniq_name_848_0_1; /*string*/
      }
      else {
        kk_std_core_types__optional_drop(name, _ctx);
        tzonename_0 = kk_string_empty(); /*string*/
      }
    }
    kk_std_core_types__optional frac_0_10006_0;
    kk_box_t _x_x1084;
    double _x_x1085;
    kk_std_core_types__optional _match_x829 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x829, _ctx)) {
      kk_box_t _box_x108 = _match_x829._cons._Optional.value;
      double _uniq_frac_155_0 = kk_double_unbox(_box_x108, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x829, _ctx);
      _x_x1085 = _uniq_frac_155_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x829, _ctx);
      _x_x1085 = 0x0p+0; /*float64*/
    }
    _x_x1084 = kk_double_box(_x_x1085, _ctx); /*10003*/
    frac_0_10006_0 = kk_std_core_types__new_Optional(_x_x1084, _ctx); /*? float64*/
    kk_std_time_duration__duration delta_0_0;
    kk_std_num_ddouble__ddouble _x_x1086;
    bool _match_x828;
    double _x_x1087;
    if (kk_std_core_types__is_Optional(frac_0_10006_0, _ctx)) {
      kk_box_t _box_x111 = frac_0_10006_0._cons._Optional.value;
      double _uniq_frac_1144_1 = kk_double_unbox(_box_x111, KK_BORROWED, _ctx);
      _x_x1087 = _uniq_frac_1144_1; /*float64*/
    }
    else {
      _x_x1087 = 0x0p+0; /*float64*/
    }
    _match_x828 = (_x_x1087 == (0x0p+0)); /*bool*/
    if (_match_x828) {
      kk_std_core_types__optional_drop(frac_0_10006_0, _ctx);
      _x_x1086 = kk_std_num_ddouble_ddouble_int_exp(secs_0_0, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1088 = kk_std_num_ddouble_ddouble_int_exp(secs_0_0, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1089;
      double _x_x1090;
      if (kk_std_core_types__is_Optional(frac_0_10006_0, _ctx)) {
        kk_box_t _box_x112 = frac_0_10006_0._cons._Optional.value;
        double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x112, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac_0_10006_0, _ctx);
        _x_x1090 = _uniq_frac_1144_0_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(frac_0_10006_0, _ctx);
        _x_x1090 = 0x0p+0; /*float64*/
      }
      _x_x1089 = kk_std_num_ddouble__new_Ddouble(_x_x1090, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1086 = kk_std_num_ddouble__lp__plus__rp_(_x_x1088, _x_x1089, _ctx); /*std/num/ddouble/ddouble*/
    }
    delta_0_0 = kk_std_time_duration__new_Duration(_x_x1086, _ctx); /*std/time/duration/duration*/
    return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, tzonename_0, kk_std_time_calendar_new_tz_fixed_fun1091(abbrv, delta_0_0, _ctx), kk_std_time_calendar_new_tz_fixed_fun1095(delta_0_0, _ctx), _ctx);
  }
}
 
// Is this the UTC timezone?

bool kk_std_time_calendar_is_tz_utc(kk_std_time_calendar__timezone tz, kk_context_t* _ctx) { /* (tz : timezone) -> bool */ 
  kk_string_t _x_x1097;
  {
    struct kk_std_time_calendar_Timezone* _con_x1098 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x = _con_x1098->name;
    kk_function_t _pat_0 = _con_x1098->utc_delta;
    kk_function_t _pat_1 = _con_x1098->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
      kk_function_drop(_pat_1, _ctx);
      kk_function_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(tz, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(tz, _ctx);
    }
    _x_x1097 = _x; /*string*/
  }
  kk_string_t _x_x1099;
  kk_std_time_calendar__timezone _x_x1100 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x1101 = kk_std_time_calendar__as_Timezone(_x_x1100, _ctx);
    kk_string_t _x_0 = _con_x1101->name;
    _x_x1099 = kk_string_dup(_x_0, _ctx); /*string*/
  }
  return kk_string_is_eq(_x_x1097,_x_x1099,kk_context());
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
struct kk_std_time_calendar_tz_local_fun1104__t {
  struct kk_function_s _base;
  kk_std_time_calendar__local_timezone tz;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_tz_local_fun1104(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_local_fun1104(kk_std_time_calendar__local_timezone tz, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun1104__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_local_fun1104__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_local_fun1104, kk_context());
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_tz_local_fun1104(kk_function_t _fself, kk_std_time_instant__instant i_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun1104__t* _self = kk_function_as(struct kk_std_time_calendar_tz_local_fun1104__t*, _fself, _ctx);
  kk_std_time_calendar__local_timezone tz = _self->tz; /* std/time/calendar/local-timezone */
  kk_drop_match(_self, {kk_std_time_calendar__local_timezone_dup(tz, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble x_10079 = kk_std_time_utc_unix_timestamp(i_0, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__tuple2 _match_x825;
  double _x_x1105;
  {
    double _x = x_10079.hi;
    _x_x1105 = _x; /*float64*/
  }
  _match_x825 = kk_std_time_calendar_local_utc_delta(tz, _x_x1105, _ctx); /*(float64, string)*/
  {
    kk_box_t _box_x123 = _match_x825.fst;
    kk_box_t _box_x124 = _match_x825.snd;
    double ofs = kk_double_unbox(_box_x123, KK_BORROWED, _ctx);
    kk_string_t abbrv = kk_string_unbox(_box_x124);
    kk_string_dup(abbrv, _ctx);
    kk_std_core_types__tuple2_drop(_match_x825, _ctx);
    kk_box_t _x_x1106;
    kk_std_time_duration__duration _x_x1107;
    kk_std_num_ddouble__ddouble _x_x1108 = kk_std_num_ddouble__new_Ddouble(ofs, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1107 = kk_std_time_duration__new_Duration(_x_x1108, _ctx); /*std/time/duration/duration*/
    _x_x1106 = kk_std_time_duration__duration_box(_x_x1107, _ctx); /*10037*/
    return kk_std_core_types__new_Tuple2(_x_x1106, kk_string_box(abbrv), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_tz_local_fun1110__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x130;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun1110(kk_function_t _fself, kk_std_time_instant__instant _b_x133, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_local_fun1110(kk_box_t _fun_unbox_x130, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun1110__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_tz_local_fun1110__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_tz_local_fun1110, kk_context());
  _self->_fun_unbox_x130 = _fun_unbox_x130;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun1110(kk_function_t _fself, kk_std_time_instant__instant _b_x133, kk_context_t* _ctx) {
  struct kk_std_time_calendar_tz_local_fun1110__t* _self = kk_function_as(struct kk_std_time_calendar_tz_local_fun1110__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x130 = _self->_fun_unbox_x130; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x130, _ctx);}, {}, _ctx)
  kk_box_t _x_x1111;
  kk_function_t _x_x1112 = kk_function_unbox(_fun_unbox_x130, _ctx); /*(131) -> 132*/
  _x_x1111 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1112, (_x_x1112, kk_std_time_instant__instant_box(_b_x133, _ctx), _ctx), _ctx); /*132*/
  return kk_std_core_types__maybe_unbox(_x_x1111, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_tz_local_fun1113__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun1113(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_tz_local_fun1113(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_tz_local_fun1113, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_time_calendar_tz_local_fun1113(kk_function_t _fself, kk_std_time_instant__instant i, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__instant_drop(i, _ctx);
  return kk_std_core_types__new_Nothing(_ctx);
}

kk_std_time_calendar__timezone kk_std_time_calendar_tz_local(kk_context_t* _ctx) { /* () -> ndet timezone */ 
  kk_std_time_calendar__local_timezone tz = kk_std_time_calendar_local_get_timezone(_ctx); /*std/time/calendar/local-timezone*/;
  kk_string_t _x_x1102 = kk_string_empty(); /*string*/
  kk_function_t _x_x1109;
  kk_std_core_types__optional _match_x824 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x824, _ctx)) {
    kk_box_t _fun_unbox_x130 = _match_x824._cons._Optional.value;
    kk_box_dup(_fun_unbox_x130, _ctx);
    kk_std_core_types__optional_drop(_match_x824, _ctx);
    _x_x1109 = kk_std_time_calendar_new_tz_local_fun1110(_fun_unbox_x130, _ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x824, _ctx);
    _x_x1109 = kk_std_time_calendar_new_tz_local_fun1113(_ctx); /*(std/time/instant/instant) -> maybe<std/time/instant/instant>*/
  }
  return kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, _x_x1102, kk_std_time_calendar_new_tz_local_fun1104(tz, _ctx), _x_x1109, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_calendar_earth_timestamp_to_dc(kk_std_time_timestamp__timestamp t, kk_std_num_ddouble__ddouble tzdelta, kk_function_t days_to_date, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan, days-to-date : (int) -> std/time/date/date) -> (std/time/date/date, std/time/date/clock) */ 
  kk_std_core_types__tuple2 _match_x823;
  kk_std_time_timestamp__timestamp _x_x1114;
  kk_std_num_ddouble__ddouble _x_x1115;
  kk_std_num_ddouble__ddouble _x_x1116;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1117 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x1117->since;
    _x_x1116 = _x; /*std/time/timestamp/timespan*/
  }
  _x_x1115 = kk_std_num_ddouble__lp__plus__rp_(_x_x1116, tzdelta, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1118;
  {
    struct kk_std_time_timestamp_Timestamp* _con_x1119 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
    kk_std_num_ddouble__ddouble _pat_0_0 = _con_x1119->since;
    int32_t _x_0 = _con_x1119->leap32;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1118 = _x_0; /*int32*/
  }
  _x_x1114 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1115, _x_x1118, _ctx); /*std/time/timestamp/timestamp*/
  _match_x823 = kk_std_time_timestamp_days_clock(_x_x1114, _ctx); /*(int, std/time/date/clock)*/
  {
    kk_box_t _box_x136 = _match_x823.fst;
    kk_box_t _box_x137 = _match_x823.snd;
    kk_std_time_date__clock clock = kk_std_time_date__clock_unbox(_box_x137, KK_BORROWED, _ctx);
    struct kk_std_time_date_Clock* _con_x1120 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_integer_t days = kk_integer_unbox(_box_x136, _ctx);
    kk_std_time_date__clock_dup(clock, _ctx);
    kk_integer_dup(days, _ctx);
    kk_std_core_types__tuple2_drop(_match_x823, _ctx);
    kk_std_time_date__date _b_x138_140 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date, (days_to_date, days, _ctx), _ctx); /*std/time/date/date*/;
    return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x138_140, _ctx), kk_std_time_date__clock_box(clock, _ctx), _ctx);
  }
}

kk_std_time_timestamp__timestamp kk_std_time_calendar_dc_timestamp(kk_std_time_date__date d, kk_std_time_date__clock c, kk_function_t date_to_days, kk_std_core_types__optional has_leap_seconds, kk_context_t* _ctx) { /* (d : std/time/date/date, c : std/time/date/clock, date-to-days : (std/time/date/date) -> int, has-leap-seconds : ? bool) -> std/time/timestamp/timestamp */ 
  kk_std_core_types__tuple2 _match_x818;
  if (kk_std_core_types__is_Optional(has_leap_seconds, _ctx)) {
    kk_box_t _box_x142 = has_leap_seconds._cons._Optional.value;
    bool _uniq_has_leap_seconds_1384 = kk_bool_unbox(_box_x142);
    kk_std_core_types__optional_drop(has_leap_seconds, _ctx);
    if (_uniq_has_leap_seconds_1384) {
      kk_std_num_ddouble__ddouble y_10086 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(60), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_core_types__order x_0_10190;
      kk_std_core_types__order _match_x822;
      double _x_x1121;
      {
        struct kk_std_time_date_Clock* _con_x1122 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x_3 = _con_x1122->seconds;
        {
          double _x_0 = _x_3.hi;
          _x_x1121 = _x_0; /*float64*/
        }
      }
      double _x_x1123;
      {
        double _x_0_0 = y_10086.hi;
        _x_x1123 = _x_0_0; /*float64*/
      }
      _match_x822 = kk_std_num_float64_cmp(_x_x1121, _x_x1123, _ctx); /*order*/
      if (kk_std_core_types__is_Eq(_match_x822, _ctx)) {
        double _x_x1124;
        {
          struct kk_std_time_date_Clock* _con_x1125 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x1125->seconds;
          {
            double _x_1 = _x_3_0.lo;
            _x_x1124 = _x_1; /*float64*/
          }
        }
        double _x_x1126;
        {
          double _x_2 = y_10086.lo;
          _x_x1126 = _x_2; /*float64*/
        }
        x_0_10190 = kk_std_num_float64_cmp(_x_x1124, _x_x1126, _ctx); /*order*/
      }
      else {
        x_0_10190 = _match_x822; /*order*/
      }
      bool _match_x819;
      kk_integer_t _brw_x820;
      if (kk_std_core_types__is_Lt(x_0_10190, _ctx)) {
        _brw_x820 = kk_integer_from_small(-1); /*int*/
        goto _match_x1127;
      }
      if (kk_std_core_types__is_Eq(x_0_10190, _ctx)) {
        _brw_x820 = kk_integer_from_small(0); /*int*/
        goto _match_x1127;
      }
      {
        _brw_x820 = kk_integer_from_small(1); /*int*/
      }
      _match_x1127: ;
      bool _brw_x821 = kk_integer_eq_borrow(_brw_x820,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x820, _ctx);
      _match_x819 = _brw_x821; /*bool*/
      if (_match_x819) {
        kk_box_t _x_x1128;
        kk_std_num_ddouble__ddouble _x_x1129;
        {
          struct kk_std_time_date_Clock* _con_x1130 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_4 = _con_x1130->seconds;
          _x_x1129 = _x_4; /*std/num/ddouble/ddouble*/
        }
        _x_x1128 = kk_std_num_ddouble__ddouble_box(_x_x1129, _ctx); /*10037*/
        _match_x818 = kk_std_core_types__new_Tuple2(_x_x1128, kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*(10037, 10038)*/
      }
      else {
        kk_integer_t x_0_10090;
        kk_std_num_ddouble__ddouble _x_x1131;
        kk_std_num_ddouble__ddouble _x_x1132;
        {
          struct kk_std_time_date_Clock* _con_x1133 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_5 = _con_x1133->seconds;
          _x_x1132 = _x_5; /*std/num/ddouble/ddouble*/
        }
        _x_x1131 = kk_std_num_ddouble_floor(_x_x1132, _ctx); /*std/num/ddouble/ddouble*/
        x_0_10090 = kk_std_num_ddouble_int(_x_x1131, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
        kk_integer_t leap = kk_integer_add_small_const(x_0_10090, -59, _ctx); /*int*/;
        kk_std_num_ddouble__ddouble y_1_10094;
        kk_integer_t _x_x1134 = kk_integer_dup(leap, _ctx); /*int*/
        y_1_10094 = kk_std_num_ddouble_ddouble_int_exp(_x_x1134, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _b_x145_157;
        kk_std_num_ddouble__ddouble _x_x1135;
        {
          struct kk_std_time_date_Clock* _con_x1136 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_num_ddouble__ddouble _x_7 = _con_x1136->seconds;
          _x_x1135 = _x_7; /*std/num/ddouble/ddouble*/
        }
        kk_std_num_ddouble__ddouble _x_x1137;
        double _x_x1138;
        double _x_x1139;
        {
          double _x_6 = y_1_10094.hi;
          _x_x1139 = _x_6; /*float64*/
        }
        _x_x1138 = (-_x_x1139); /*float64*/
        double _x_x1140;
        double _x_x1141;
        {
          double _x_0_1 = y_1_10094.lo;
          _x_x1141 = _x_0_1; /*float64*/
        }
        _x_x1140 = (-_x_x1141); /*float64*/
        _x_x1137 = kk_std_num_ddouble__new_Ddouble(_x_x1138, _x_x1140, _ctx); /*std/num/ddouble/ddouble*/
        _b_x145_157 = kk_std_num_ddouble__lp__plus__rp_(_x_x1135, _x_x1137, _ctx); /*std/num/ddouble/ddouble*/
        _match_x818 = kk_std_core_types__new_Tuple2(kk_std_num_ddouble__ddouble_box(_b_x145_157, _ctx), kk_integer_box(leap, _ctx), _ctx); /*(10037, 10038)*/
      }
    }
    else {
      kk_box_t _x_x1142;
      kk_std_num_ddouble__ddouble _x_x1143;
      {
        struct kk_std_time_date_Clock* _con_x1144 = kk_std_time_date__as_Clock(c, _ctx);
        kk_std_num_ddouble__ddouble _x = _con_x1144->seconds;
        _x_x1143 = _x; /*std/num/ddouble/ddouble*/
      }
      _x_x1142 = kk_std_num_ddouble__ddouble_box(_x_x1143, _ctx); /*10037*/
      _match_x818 = kk_std_core_types__new_Tuple2(_x_x1142, kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*(10037, 10038)*/
    }
  }
  else {
    kk_std_core_types__optional_drop(has_leap_seconds, _ctx);
    kk_box_t _x_x1145;
    kk_std_num_ddouble__ddouble _x_x1146;
    {
      struct kk_std_time_date_Clock* _con_x1147 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _x_8 = _con_x1147->seconds;
      _x_x1146 = _x_8; /*std/num/ddouble/ddouble*/
    }
    _x_x1145 = kk_std_num_ddouble__ddouble_box(_x_x1146, _ctx); /*10037*/
    _match_x818 = kk_std_core_types__new_Tuple2(_x_x1145, kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*(10037, 10038)*/
  }
  {
    kk_box_t _box_x151 = _match_x818.fst;
    kk_box_t _box_x152 = _match_x818.snd;
    kk_std_num_ddouble__ddouble xsecs = kk_std_num_ddouble__ddouble_unbox(_box_x151, KK_BORROWED, _ctx);
    kk_integer_t leap_0 = kk_integer_unbox(_box_x152, _ctx);
    kk_integer_dup(leap_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x818, _ctx);
    kk_integer_t x_2_10098;
    kk_integer_t _x_x1148;
    {
      struct kk_std_time_date_Clock* _con_x1149 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_8 = _con_x1149->seconds;
      kk_integer_t _x_8_0 = _con_x1149->hours;
      kk_integer_dup(_x_8_0, _ctx);
      _x_x1148 = _x_8_0; /*int*/
    }
    x_2_10098 = kk_integer_mul(_x_x1148,(kk_integer_from_small(60)),kk_context()); /*int*/
    kk_integer_t i_1_10097;
    kk_integer_t _x_x1150;
    kk_integer_t _x_x1151;
    {
      struct kk_std_time_date_Clock* _con_x1152 = kk_std_time_date__as_Clock(c, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_9 = _con_x1152->seconds;
      kk_integer_t _pat_0_10 = _con_x1152->hours;
      kk_integer_t _x_9 = _con_x1152->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
        kk_integer_drop(_pat_0_10, _ctx);
        kk_datatype_ptr_free(c, _ctx);
      }
      else {
        kk_integer_dup(_x_9, _ctx);
        kk_datatype_ptr_decref(c, _ctx);
      }
      _x_x1151 = _x_9; /*int*/
    }
    _x_x1150 = kk_integer_add(x_2_10098,_x_x1151,kk_context()); /*int*/
    i_1_10097 = kk_integer_mul(_x_x1150,(kk_integer_from_small(60)),kk_context()); /*int*/
    kk_std_num_ddouble__ddouble secs;
    kk_std_num_ddouble__ddouble _x_x1153 = kk_std_num_ddouble_ddouble_int_exp(i_1_10097, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    secs = kk_std_num_ddouble__lp__plus__rp_(_x_x1153, xsecs, _ctx); /*std/num/ddouble/ddouble*/
    kk_integer_t days = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), date_to_days, (date_to_days, d, _ctx), _ctx); /*int*/;
    kk_std_core_types__optional _x_x1154 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1155 = kk_std_core_types__new_Optional(kk_integer_box(leap_0, _ctx), _ctx); /*? 10003*/
    return kk_std_time_timestamp_timestamp_days(days, _x_x1154, _x_x1155, _ctx);
  }
}

bool kk_std_time_calendar_iso_is_leap(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> bool */ 
  bool _match_x810;
  kk_integer_t _brw_x816;
  kk_integer_t _x_x1156 = kk_integer_dup(year, _ctx); /*int*/
  _brw_x816 = kk_integer_mod(_x_x1156,(kk_integer_from_small(4)),kk_context()); /*int*/
  bool _brw_x817 = kk_integer_eq_borrow(_brw_x816,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x816, _ctx);
  _match_x810 = _brw_x817; /*bool*/
  if (_match_x810) {
    bool _match_x811;
    kk_integer_t _brw_x814;
    kk_integer_t _x_x1157 = kk_integer_dup(year, _ctx); /*int*/
    _brw_x814 = kk_integer_mod(_x_x1157,(kk_integer_from_small(100)),kk_context()); /*int*/
    bool _brw_x815 = kk_integer_neq_borrow(_brw_x814,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x814, _ctx);
    _match_x811 = _brw_x815; /*bool*/
    if (_match_x811) {
      kk_integer_drop(year, _ctx);
      return true;
    }
    {
      kk_integer_t _brw_x812 = kk_integer_mod(year,(kk_integer_from_small(400)),kk_context()); /*int*/;
      bool _brw_x813 = kk_integer_eq_borrow(_brw_x812,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x812, _ctx);
      return _brw_x813;
    }
  }
  {
    kk_integer_drop(year, _ctx);
    return false;
  }
}

kk_integer_t kk_std_time_calendar_iso_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx) { /* (year : int, month : int) -> int */ 
  bool is_before_march_10102 = kk_integer_lte_borrow(month,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_t adj;
  if (is_before_march_10102) {
    kk_integer_drop(year, _ctx);
    adj = kk_integer_from_small(0); /*int*/
  }
  else {
    bool _match_x808 = kk_std_time_calendar_iso_is_leap(year, _ctx); /*bool*/;
    if (_match_x808) {
      adj = kk_integer_from_small(1); /*int*/
    }
    else {
      adj = kk_integer_from_small(2); /*int*/
    }
  }
  kk_integer_t x_0_10106 = kk_integer_mul((kk_integer_from_small(367)),month,kk_context()); /*int*/;
  kk_integer_t x_10104;
  kk_integer_t _x_x1158 = kk_integer_add_small_const(x_0_10106, -362, _ctx); /*int*/
  x_10104 = kk_integer_div(_x_x1158,(kk_integer_from_small(12)),kk_context()); /*int*/
  return kk_integer_sub(x_10104,adj,kk_context());
}

kk_integer_t kk_std_time_calendar_iso_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx) { /* (year : int, doy : int) -> int */ 
  bool is_before_march_10108 = kk_integer_lte_borrow(doy,(kk_integer_from_small(58)),kk_context()); /*bool*/;
  kk_integer_t adj;
  if (is_before_march_10108) {
    kk_integer_drop(year, _ctx);
    adj = kk_integer_from_small(0); /*int*/
  }
  else {
    bool _match_x807 = kk_std_time_calendar_iso_is_leap(year, _ctx); /*bool*/;
    if (_match_x807) {
      adj = kk_integer_from_small(1); /*int*/
    }
    else {
      adj = kk_integer_from_small(2); /*int*/
    }
  }
  kk_integer_t x_10110;
  kk_integer_t _x_x1159 = kk_integer_add(doy,adj,kk_context()); /*int*/
  x_10110 = kk_integer_mul((kk_integer_from_small(12)),_x_x1159,kk_context()); /*int*/
  kk_integer_t _x_x1160 = kk_integer_add_small_const(x_10110, 373, _ctx); /*int*/
  return kk_integer_div(_x_x1160,(kk_integer_from_small(367)),kk_context());
}

kk_integer_t kk_std_time_calendar_iso_days_before_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> int */ 
  kk_integer_t y = kk_integer_add_small_const(year, -1, _ctx); /*int*/;
  kk_integer_t x_0_10117;
  kk_integer_t _x_x1161 = kk_integer_dup(y, _ctx); /*int*/
  x_0_10117 = kk_integer_div(_x_x1161,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t y_1_10118;
  kk_integer_t _x_x1162 = kk_integer_dup(y, _ctx); /*int*/
  y_1_10118 = kk_integer_div(_x_x1162,(kk_integer_from_small(100)),kk_context()); /*int*/
  kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
  kk_integer_t y_0_10116;
  kk_integer_t _x_x1163 = kk_integer_dup(y, _ctx); /*int*/
  y_0_10116 = kk_integer_div(_x_x1163,(kk_integer_from_small(400)),kk_context()); /*int*/
  kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
  kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
  return kk_integer_add(x_1_10119,leapdays,kk_context());
}

kk_std_core_types__tuple2 kk_std_time_calendar_iso_estimate_year(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, maybe<int>) */ 
  kk_std_core_types__tuple2 _match_x806 = kk_std_core_int_divmod(days, kk_integer_from_int(146097, _ctx), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x165 = _match_x806.fst;
    kk_box_t _box_x166 = _match_x806.snd;
    kk_integer_t era = kk_integer_unbox(_box_x165, _ctx);
    kk_integer_t yoe = kk_integer_unbox(_box_x166, _ctx);
    kk_integer_dup(era, _ctx);
    kk_integer_dup(yoe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x806, _ctx);
    kk_integer_t y_0_10124 = kk_integer_mul((kk_integer_from_small(400)),era,kk_context()); /*int*/;
    kk_integer_t x_10121 = kk_integer_add_small_const(y_0_10124, 1, _ctx); /*int*/;
    kk_integer_t y_10122;
    kk_integer_t _x_x1164 = kk_integer_mul((kk_integer_from_small(100)),yoe,kk_context()); /*int*/
    y_10122 = kk_integer_div(_x_x1164,(kk_integer_from_int(36525, _ctx)),kk_context()); /*int*/
    kk_integer_t _b_x168_170 = kk_integer_add(x_10121,y_10122,kk_context()); /*int*/;
    kk_box_t _x_x1165;
    kk_std_core_types__maybe _x_x1166 = kk_std_core_types__new_Just(kk_integer_box(kk_integer_from_small(363), _ctx), _ctx); /*maybe<10024>*/
    _x_x1165 = kk_std_core_types__maybe_box(_x_x1166, _ctx); /*10038*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x168_170, _ctx), _x_x1165, _ctx);
  }
}

kk_std_time_instant__instant kk_std_time_calendar_earth_timestamp_to_instant(kk_std_time_timestamp__timestamp t, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, tz : timezone, ts : std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_std_time_instant__instant i;
  kk_std_time_timestamp__timestamp _x_x1167 = kk_std_time_timestamp__timestamp_dup(t, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1168 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
  i = kk_std_time_instant__new_Instant(_x_x1167, _x_x1168, _ctx); /*std/time/instant/instant*/
  bool _match_x803;
  kk_string_t _x_x1169;
  {
    struct kk_std_time_calendar_Timezone* _con_x1170 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x = _con_x1170->name;
    kk_string_dup(_x, _ctx);
    _x_x1169 = _x; /*string*/
  }
  kk_string_t _x_x1171;
  kk_std_time_calendar__timezone _x_x1172 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x1173 = kk_std_time_calendar__as_Timezone(_x_x1172, _ctx);
    kk_string_t _x_0 = _con_x1173->name;
    _x_x1171 = kk_string_dup(_x_0, _ctx); /*string*/
  }
  _match_x803 = kk_string_is_eq(_x_x1169,_x_x1171,kk_context()); /*bool*/
  if (_match_x803) {
    kk_datatype_ptr_dropn(tz, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
    kk_std_time_timestamp__timestamp_drop(t, _ctx);
    return i;
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1174 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _pat_0_2 = _con_x1174->name;
    kk_function_t _pat_1_1 = _con_x1174->utc_delta;
    kk_function_t _x_1 = _con_x1174->utc_inverse;
    kk_function_dup(_x_1, _ctx);
    kk_std_core_types__maybe _match_x804;
    kk_std_time_instant__instant _x_x1175 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    _match_x804 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_1, (_x_1, _x_x1175, _ctx), _ctx); /*maybe<std/time/instant/instant>*/
    if (kk_std_core_types__is_Just(_match_x804, _ctx)) {
      kk_box_t _box_x173 = _match_x804._cons.Just.value;
      kk_std_time_instant__instant inv = kk_std_time_instant__instant_unbox(_box_x173, KK_BORROWED, _ctx);
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
      kk_std_core_types__maybe_drop(_match_x804, _ctx);
      return inv;
    }
    {
      kk_std_core_types__tuple2 tuple2_10133;
      {
        struct kk_std_time_calendar_Timezone* _con_x1176 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_function_t _x_3 = _con_x1176->utc_delta;
        kk_function_dup(_x_3, _ctx);
        tuple2_10133 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_3, (_x_3, i, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      kk_std_time_timestamp__timestamp t_1_10136;
      kk_std_num_ddouble__ddouble _x_x1177;
      kk_std_num_ddouble__ddouble _x_x1178;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1179 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0 = _con_x1179->since;
        _x_x1178 = _x_1_0; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1180;
      double _x_x1181;
      double _x_x1182;
      {
        kk_box_t _box_x174 = tuple2_10133.fst;
        kk_box_t _box_x175 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2 = kk_std_time_duration__duration_unbox(_box_x174, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5 = _x_2.secs;
          {
            double _x_4 = _x_5.hi;
            _x_x1182 = _x_4; /*float64*/
          }
        }
      }
      _x_x1181 = (-_x_x1182); /*float64*/
      double _x_x1183;
      double _x_x1184;
      {
        kk_box_t _box_x176 = tuple2_10133.fst;
        kk_box_t _box_x177 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0 = kk_std_time_duration__duration_unbox(_box_x176, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0 = _x_2_0.secs;
          {
            double _x_0_0 = _x_5_0.lo;
            _x_x1184 = _x_0_0; /*float64*/
          }
        }
      }
      _x_x1183 = (-_x_x1184); /*float64*/
      _x_x1180 = kk_std_num_ddouble__new_Ddouble(_x_x1181, _x_x1183, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1177 = kk_std_num_ddouble__lp__plus__rp_(_x_x1178, _x_x1180, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1185;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1186 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_2_0 = _con_x1186->since;
        int32_t _x_2_0_0 = _con_x1186->leap32;
        _x_x1185 = _x_2_0_0; /*int32*/
      }
      t_1_10136 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1177, _x_x1185, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__instant tzi1;
      kk_std_time_instant__timescale _x_x1187 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
      tzi1 = kk_std_time_instant__new_Instant(t_1_10136, _x_x1187, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_0_10140;
      {
        struct kk_std_time_calendar_Timezone* _con_x1188 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_string_t _pat_0_8 = _con_x1188->name;
        kk_function_t _x_7 = _con_x1188->utc_delta;
        kk_function_t _pat_1_6 = _con_x1188->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
          kk_function_drop(_pat_1_6, _ctx);
          kk_string_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(tz, _ctx);
        }
        else {
          kk_function_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(tz, _ctx);
        }
        kk_std_time_instant__instant _x_x1189 = kk_std_time_instant__instant_dup(tzi1, _ctx); /*std/time/instant/instant*/
        tuple2_0_10140 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_7, (_x_7, _x_x1189, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      bool _match_x805;
      kk_std_time_duration__duration _x_x1190;
      {
        kk_box_t _box_x178 = tuple2_10133.fst;
        kk_box_t _box_x179 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_1 = kk_std_time_duration__duration_unbox(_box_x178, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10133, _ctx);
        _x_x1190 = _x_2_1; /*std/time/duration/duration*/
      }
      kk_std_time_duration__duration _x_x1191;
      {
        kk_box_t _box_x180 = tuple2_0_10140.fst;
        kk_box_t _box_x181 = tuple2_0_10140.snd;
        kk_std_time_duration__duration _x_6 = kk_std_time_duration__duration_unbox(_box_x180, KK_BORROWED, _ctx);
        _x_x1191 = _x_6; /*std/time/duration/duration*/
      }
      _match_x805 = kk_std_time_duration__lp__eq__eq__rp_(_x_x1190, _x_x1191, _ctx); /*bool*/
      if (_match_x805) {
        kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
        kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
        kk_std_time_timestamp__timestamp_drop(t, _ctx);
        return tzi1;
      }
      {
        kk_std_time_instant__instant_drop(tzi1, _ctx);
        kk_std_time_timestamp__timestamp t_3_10143;
        kk_std_num_ddouble__ddouble _x_x1192;
        kk_std_num_ddouble__ddouble _x_x1193;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1194 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
          kk_std_num_ddouble__ddouble _x_1_1 = _con_x1194->since;
          _x_x1193 = _x_1_1; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x1195;
        double _x_x1196;
        double _x_x1197;
        {
          kk_box_t _box_x182 = tuple2_0_10140.fst;
          kk_box_t _box_x183 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0 = kk_std_time_duration__duration_unbox(_box_x182, KK_BORROWED, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9 = _x_6_0.secs;
            {
              double _x_8 = _x_9.hi;
              _x_x1197 = _x_8; /*float64*/
            }
          }
        }
        _x_x1196 = (-_x_x1197); /*float64*/
        double _x_x1198;
        double _x_x1199;
        {
          kk_box_t _box_x184 = tuple2_0_10140.fst;
          kk_box_t _box_x185 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_1 = kk_std_time_duration__duration_unbox(_box_x184, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0 = _x_6_1.secs;
            {
              double _x_0_1 = _x_9_0.lo;
              _x_x1199 = _x_0_1; /*float64*/
            }
          }
        }
        _x_x1198 = (-_x_x1199); /*float64*/
        _x_x1195 = kk_std_num_ddouble__new_Ddouble(_x_x1196, _x_x1198, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1192 = kk_std_num_ddouble__lp__plus__rp_(_x_x1193, _x_x1195, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x1200;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1201 = kk_std_time_timestamp__as_Timestamp(t, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_2_1 = _con_x1201->since;
          int32_t _x_2_1_0 = _con_x1201->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_datatype_ptr_decref(t, _ctx);
          }
          _x_x1200 = _x_2_1_0; /*int32*/
        }
        t_3_10143 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1192, _x_x1200, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_instant__new_Instant(t_3_10143, ts, _ctx);
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
struct kk_std_time_calendar_earth_calendar_fun1205__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x190;
};
static kk_string_t kk_std_time_calendar_earth_calendar_fun1205(kk_function_t _fself, kk_std_time_date__date _b_x193, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun1205(kk_box_t _fun_unbox_x190, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun1205__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_earth_calendar_fun1205__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_earth_calendar_fun1205, kk_context());
  _self->_fun_unbox_x190 = _fun_unbox_x190;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_earth_calendar_fun1205(kk_function_t _fself, kk_std_time_date__date _b_x193, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun1205__t* _self = kk_function_as(struct kk_std_time_calendar_earth_calendar_fun1205__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x190 = _self->_fun_unbox_x190; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x190, _ctx);}, {}, _ctx)
  kk_box_t _x_x1206;
  kk_function_t _x_x1207 = kk_function_unbox(_fun_unbox_x190, _ctx); /*(191) -> 192*/
  _x_x1206 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1207, (_x_x1207, kk_std_time_date__date_box(_b_x193, _ctx), _ctx), _ctx); /*192*/
  return kk_string_unbox(_x_x1206);
}


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun1208__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_time_calendar_earth_calendar_fun1208(kk_function_t _fself, kk_std_time_date__date d, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun1208(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_earth_calendar_fun1208, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_std_time_calendar_earth_calendar_fun1208(kk_function_t _fself, kk_std_time_date__date d, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_date__date_drop(d, _ctx);
  return kk_string_empty();
}


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun1211__t {
  struct kk_function_s _base;
  kk_function_t days_to_date;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_earth_calendar_fun1211(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun1211(kk_function_t days_to_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun1211__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_earth_calendar_fun1211__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_earth_calendar_fun1211, kk_context());
  _self->days_to_date = days_to_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_earth_calendar_fun1211(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun1211__t* _self = kk_function_as(struct kk_std_time_calendar_earth_calendar_fun1211__t*, _fself, _ctx);
  kk_function_t days_to_date = _self->days_to_date; /* (days : int) -> std/time/date/date */
  kk_drop_match(_self, {kk_function_dup(days_to_date, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _match_x802;
  kk_std_time_timestamp__timestamp _x_x1212;
  kk_std_num_ddouble__ddouble _x_x1213;
  kk_std_num_ddouble__ddouble _x_x1214;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1215 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1216 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1217 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1217->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1214 = _x; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1218;
  {
    kk_std_num_ddouble__ddouble _x_2 = tzdelta.secs;
    _x_x1218 = _x_2; /*std/time/timestamp/timespan*/
  }
  _x_x1213 = kk_std_num_ddouble__lp__plus__rp_(_x_x1214, _x_x1218, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1219;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_2_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1220 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1221 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1222 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1222->since;
      int32_t _x_0 = _con_x1222->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1219 = _x_0; /*int32*/
    }
  }
  _x_x1212 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1213, _x_x1219, _ctx); /*std/time/timestamp/timestamp*/
  _match_x802 = kk_std_time_timestamp_days_clock(_x_x1212, _ctx); /*(int, std/time/date/clock)*/
  {
    kk_box_t _box_x194 = _match_x802.fst;
    kk_box_t _box_x195 = _match_x802.snd;
    kk_std_time_date__clock clock = kk_std_time_date__clock_unbox(_box_x195, KK_BORROWED, _ctx);
    struct kk_std_time_date_Clock* _con_x1223 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_integer_t days = kk_integer_unbox(_box_x194, _ctx);
    kk_std_time_date__clock_dup(clock, _ctx);
    kk_integer_dup(days, _ctx);
    kk_std_core_types__tuple2_drop(_match_x802, _ctx);
    kk_std_time_date__date _b_x196_220 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date, (days_to_date, days, _ctx), _ctx); /*std/time/date/date*/;
    return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x196_220, _ctx), kk_std_time_date__clock_box(clock, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_earth_calendar_fun1225__t {
  struct kk_function_s _base;
  kk_function_t date_to_days;
};
static kk_std_time_instant__instant kk_std_time_calendar_earth_calendar_fun1225(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_earth_calendar_fun1225(kk_function_t date_to_days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun1225__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_earth_calendar_fun1225__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_earth_calendar_fun1225, kk_context());
  _self->date_to_days = date_to_days;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_earth_calendar_fun1225(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_earth_calendar_fun1225__t* _self = kk_function_as(struct kk_std_time_calendar_earth_calendar_fun1225__t*, _fself, _ctx);
  kk_function_t date_to_days = _self->date_to_days; /* (std/time/date/date) -> int */
  kk_drop_match(_self, {kk_function_dup(date_to_days, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_10298;
  kk_std_core_types__optional _x_x1226;
  kk_box_t _x_x1227;
  bool _x_x1228;
  {
    struct kk_std_time_instant_Timescale* _con_x1229 = kk_std_time_instant__as_Timescale(ts_0, _ctx);
    kk_std_core_types__maybe _x_3_1 = _con_x1229->mb_seconds_in_day;
    kk_std_core_types__maybe_dup(_x_3_1, _ctx);
    if (kk_std_core_types__is_Just(_x_3_1, _ctx)) {
      kk_std_core_types__maybe_drop(_x_3_1, _ctx);
      _x_x1228 = true; /*bool*/
    }
    else {
      _x_x1228 = false; /*bool*/
    }
  }
  _x_x1227 = kk_bool_box(_x_x1228); /*10003*/
  _x_x1226 = kk_std_core_types__new_Optional(_x_x1227, _ctx); /*? 10003*/
  t_10298 = kk_std_time_calendar_dc_timestamp(d_0_0, c, date_to_days, _x_x1226, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__instant i_0;
  kk_std_time_timestamp__timestamp _x_x1230 = kk_std_time_timestamp__timestamp_dup(t_10298, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1231 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
  i_0 = kk_std_time_instant__new_Instant(_x_x1230, _x_x1231, _ctx); /*std/time/instant/instant*/
  bool _match_x799;
  kk_string_t _x_x1232;
  {
    struct kk_std_time_calendar_Timezone* _con_x1233 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x_3 = _con_x1233->name;
    kk_string_dup(_x_3, _ctx);
    _x_x1232 = _x_3; /*string*/
  }
  kk_string_t _x_x1234;
  kk_std_time_calendar__timezone _x_x1235 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x1236 = kk_std_time_calendar__as_Timezone(_x_x1235, _ctx);
    kk_string_t _x_0_0 = _con_x1236->name;
    _x_x1234 = kk_string_dup(_x_0_0, _ctx); /*string*/
  }
  _match_x799 = kk_string_is_eq(_x_x1232,_x_x1234,kk_context()); /*bool*/
  if (_match_x799) {
    kk_datatype_ptr_dropn(tz, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
    kk_std_time_timestamp__timestamp_drop(t_10298, _ctx);
    return i_0;
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1237 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _pat_0_2_0_0 = _con_x1237->name;
    kk_function_t _pat_1_1_0 = _con_x1237->utc_delta;
    kk_function_t _x_1_0_0 = _con_x1237->utc_inverse;
    kk_function_dup(_x_1_0_0, _ctx);
    kk_std_core_types__maybe _match_x800;
    kk_std_time_instant__instant _x_x1238 = kk_std_time_instant__instant_dup(i_0, _ctx); /*std/time/instant/instant*/
    _match_x800 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_1_0_0, (_x_1_0_0, _x_x1238, _ctx), _ctx); /*maybe<std/time/instant/instant>*/
    if (kk_std_core_types__is_Just(_match_x800, _ctx)) {
      kk_box_t _box_x207 = _match_x800._cons.Just.value;
      kk_std_time_instant__instant inv = kk_std_time_instant__instant_unbox(_box_x207, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
        kk_function_drop(_x_1_0_0, _ctx);
        kk_function_drop(_pat_1_1_0, _ctx);
        kk_string_drop(_pat_0_2_0_0, _ctx);
        kk_datatype_ptr_free(tz, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tz, _ctx);
      }
      kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
      kk_std_time_timestamp__timestamp_drop(t_10298, _ctx);
      kk_std_time_instant__instant_drop(i_0, _ctx);
      kk_std_time_instant__instant_dup(inv, _ctx);
      kk_std_core_types__maybe_drop(_match_x800, _ctx);
      return inv;
    }
    {
      kk_std_core_types__tuple2 tuple2_10133;
      {
        struct kk_std_time_calendar_Timezone* _con_x1239 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_function_t _x_3_0 = _con_x1239->utc_delta;
        kk_function_dup(_x_3_0, _ctx);
        tuple2_10133 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_3_0, (_x_3_0, i_0, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      kk_std_time_timestamp__timestamp t_1_10136;
      kk_std_num_ddouble__ddouble _x_x1240;
      kk_std_num_ddouble__ddouble _x_x1241;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1242 = kk_std_time_timestamp__as_Timestamp(t_10298, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0_0_0 = _con_x1242->since;
        _x_x1241 = _x_1_0_0_0; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1243;
      double _x_x1244;
      double _x_x1245;
      {
        kk_box_t _box_x208 = tuple2_10133.fst;
        kk_box_t _box_x209 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0 = kk_std_time_duration__duration_unbox(_box_x208, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5 = _x_2_0.secs;
          {
            double _x_4 = _x_5.hi;
            _x_x1245 = _x_4; /*float64*/
          }
        }
      }
      _x_x1244 = (-_x_x1245); /*float64*/
      double _x_x1246;
      double _x_x1247;
      {
        kk_box_t _box_x210 = tuple2_10133.fst;
        kk_box_t _box_x211 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_0 = kk_std_time_duration__duration_unbox(_box_x210, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0 = _x_2_0_0.secs;
          {
            double _x_0_0_0 = _x_5_0.lo;
            _x_x1247 = _x_0_0_0; /*float64*/
          }
        }
      }
      _x_x1246 = (-_x_x1247); /*float64*/
      _x_x1243 = kk_std_num_ddouble__new_Ddouble(_x_x1244, _x_x1246, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1240 = kk_std_num_ddouble__lp__plus__rp_(_x_x1241, _x_x1243, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1248;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1249 = kk_std_time_timestamp__as_Timestamp(t_10298, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_2_0_0_0 = _con_x1249->since;
        int32_t _x_2_0_0_0 = _con_x1249->leap32;
        _x_x1248 = _x_2_0_0_0; /*int32*/
      }
      t_1_10136 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1240, _x_x1248, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__instant tzi1;
      kk_std_time_instant__timescale _x_x1250 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
      tzi1 = kk_std_time_instant__new_Instant(t_1_10136, _x_x1250, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_0_10140;
      {
        struct kk_std_time_calendar_Timezone* _con_x1251 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_string_t _pat_0_8 = _con_x1251->name;
        kk_function_t _x_7 = _con_x1251->utc_delta;
        kk_function_t _pat_1_6 = _con_x1251->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
          kk_function_drop(_pat_1_6, _ctx);
          kk_string_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(tz, _ctx);
        }
        else {
          kk_function_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(tz, _ctx);
        }
        kk_std_time_instant__instant _x_x1252 = kk_std_time_instant__instant_dup(tzi1, _ctx); /*std/time/instant/instant*/
        tuple2_0_10140 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_7, (_x_7, _x_x1252, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      bool _match_x801;
      kk_std_time_duration__duration _x_x1253;
      {
        kk_box_t _box_x212 = tuple2_10133.fst;
        kk_box_t _box_x213 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_1 = kk_std_time_duration__duration_unbox(_box_x212, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10133, _ctx);
        _x_x1253 = _x_2_0_1; /*std/time/duration/duration*/
      }
      kk_std_time_duration__duration _x_x1254;
      {
        kk_box_t _box_x214 = tuple2_0_10140.fst;
        kk_box_t _box_x215 = tuple2_0_10140.snd;
        kk_std_time_duration__duration _x_6 = kk_std_time_duration__duration_unbox(_box_x214, KK_BORROWED, _ctx);
        _x_x1254 = _x_6; /*std/time/duration/duration*/
      }
      _match_x801 = kk_std_time_duration__lp__eq__eq__rp_(_x_x1253, _x_x1254, _ctx); /*bool*/
      if (_match_x801) {
        kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
        kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
        kk_std_time_timestamp__timestamp_drop(t_10298, _ctx);
        return tzi1;
      }
      {
        kk_std_time_instant__instant_drop(tzi1, _ctx);
        kk_std_time_timestamp__timestamp t_3_10143;
        kk_std_num_ddouble__ddouble _x_x1255;
        kk_std_num_ddouble__ddouble _x_x1256;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1257 = kk_std_time_timestamp__as_Timestamp(t_10298, _ctx);
          kk_std_num_ddouble__ddouble _x_1_1 = _con_x1257->since;
          _x_x1256 = _x_1_1; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x1258;
        double _x_x1259;
        double _x_x1260;
        {
          kk_box_t _box_x216 = tuple2_0_10140.fst;
          kk_box_t _box_x217 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0 = kk_std_time_duration__duration_unbox(_box_x216, KK_BORROWED, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9 = _x_6_0.secs;
            {
              double _x_8 = _x_9.hi;
              _x_x1260 = _x_8; /*float64*/
            }
          }
        }
        _x_x1259 = (-_x_x1260); /*float64*/
        double _x_x1261;
        double _x_x1262;
        {
          kk_box_t _box_x218 = tuple2_0_10140.fst;
          kk_box_t _box_x219 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_1 = kk_std_time_duration__duration_unbox(_box_x218, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0 = _x_6_1.secs;
            {
              double _x_0_1 = _x_9_0.lo;
              _x_x1262 = _x_0_1; /*float64*/
            }
          }
        }
        _x_x1261 = (-_x_x1262); /*float64*/
        _x_x1258 = kk_std_num_ddouble__new_Ddouble(_x_x1259, _x_x1261, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1255 = kk_std_num_ddouble__lp__plus__rp_(_x_x1256, _x_x1258, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x1263;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1264 = kk_std_time_timestamp__as_Timestamp(t_10298, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_2_1 = _con_x1264->since;
          int32_t _x_2_1 = _con_x1264->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(t_10298, _ctx)) {
            kk_datatype_ptr_free(t_10298, _ctx);
          }
          else {
            kk_datatype_ptr_decref(t_10298, _ctx);
          }
          _x_x1263 = _x_2_1; /*int32*/
        }
        t_3_10143 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1255, _x_x1263, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_instant__new_Instant(t_3_10143, ts_0, _ctx);
      }
    }
  }
}

kk_std_time_calendar__calendar kk_std_time_calendar_earth_calendar(kk_string_t name, kk_string_t long_name, kk_function_t days_to_date, kk_function_t date_to_days, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, days-to-date : (days : int) -> std/time/date/date, date-to-days : (std/time/date/date) -> int, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_string_t _x_x1202;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x186 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2776 = kk_string_unbox(_box_x186);
    kk_string_dup(_uniq_month_prefix_2776, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1202 = _uniq_month_prefix_2776; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1202 = kk_string_empty(); /*string*/
  }
  kk_function_t _x_x1204;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x190 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x190, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x1204 = kk_std_time_calendar_new_earth_calendar_fun1205(_fun_unbox_x190, _ctx); /*(std/time/date/date) -> string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x1204 = kk_std_time_calendar_new_earth_calendar_fun1208(_ctx); /*(std/time/date/date) -> string*/
  }
  kk_function_t _x_x1210;
  kk_function_dup(days_to_date, _ctx);
  _x_x1210 = kk_std_time_calendar_new_earth_calendar_fun1211(days_to_date, _ctx); /*(i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (10037, 10038)*/
  kk_function_t _x_x1224;
  kk_function_dup(date_to_days, _ctx);
  _x_x1224 = kk_std_time_calendar_new_earth_calendar_fun1225(date_to_days, _ctx); /*(d@0@0 : std/time/date/date, c : std/time/date/clock, tz : std/time/calendar/timezone, ts@0 : std/time/instant/timescale) -> std/time/instant/instant*/
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, name, long_name, _x_x1202, _x_x1204, _x_x1210, _x_x1224, days_to_date, date_to_days, _ctx);
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
struct kk_std_time_calendar_solar_calendar_fun1265__t {
  struct kk_function_s _base;
  kk_function_t days_before_month;
  kk_function_t days_to_month;
  kk_function_t days_to_yeardoy;
  kk_std_core_types__optional epoch_shift;
  kk_std_core_types__optional has_year_zero;
};
static kk_std_time_date__date kk_std_time_calendar_solar_calendar_fun1265(kk_function_t _fself, kk_integer_t days0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun1265(kk_function_t days_before_month, kk_function_t days_to_month, kk_function_t days_to_yeardoy, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1265__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun1265__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun1265, kk_context());
  _self->days_before_month = days_before_month;
  _self->days_to_month = days_to_month;
  _self->days_to_yeardoy = days_to_yeardoy;
  _self->epoch_shift = epoch_shift;
  _self->has_year_zero = has_year_zero;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_solar_calendar_fun1265(kk_function_t _fself, kk_integer_t days0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1265__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun1265__t*, _fself, _ctx);
  kk_function_t days_before_month = _self->days_before_month; /* (year : int, month : int) -> int */
  kk_function_t days_to_month = _self->days_to_month; /* (year : int, doy : int) -> int */
  kk_function_t days_to_yeardoy = _self->days_to_yeardoy; /* (days : int) -> (int, int) */
  kk_std_core_types__optional epoch_shift = _self->epoch_shift; /* ? int */
  kk_std_core_types__optional has_year_zero = _self->has_year_zero; /* ? bool */
  kk_drop_match(_self, {kk_function_dup(days_before_month, _ctx);kk_function_dup(days_to_month, _ctx);kk_function_dup(days_to_yeardoy, _ctx);kk_std_core_types__optional_dup(epoch_shift, _ctx);kk_std_core_types__optional_dup(has_year_zero, _ctx);}, {}, _ctx)
  kk_integer_t days_0;
  kk_integer_t _x_x1266;
  if (kk_std_core_types__is_Optional(epoch_shift, _ctx)) {
    kk_box_t _box_x222 = epoch_shift._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2855 = kk_integer_unbox(_box_x222, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2855, _ctx);
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x1266 = _uniq_epoch_shift_2855; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x1266 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  days_0 = kk_integer_add(days0,_x_x1266,kk_context()); /*int*/
  kk_std_core_types__tuple2 _match_x797 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), days_to_yeardoy, (days_to_yeardoy, days_0, _ctx), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x223 = _match_x797.fst;
    kk_box_t _box_x224 = _match_x797.snd;
    kk_integer_t y_0 = kk_integer_unbox(_box_x223, _ctx);
    kk_integer_t doy = kk_integer_unbox(_box_x224, _ctx);
    kk_integer_dup(doy, _ctx);
    kk_integer_dup(y_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x797, _ctx);
    kk_integer_t month;
    kk_integer_t _x_x1267 = kk_integer_dup(y_0, _ctx); /*int*/
    kk_integer_t _x_x1268 = kk_integer_dup(doy, _ctx); /*int*/
    month = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_integer_t, kk_context_t*), days_to_month, (days_to_month, _x_x1267, _x_x1268, _ctx), _ctx); /*int*/
    kk_integer_t y_2_10166;
    kk_integer_t _x_x1269 = kk_integer_dup(y_0, _ctx); /*int*/
    kk_integer_t _x_x1270 = kk_integer_dup(month, _ctx); /*int*/
    y_2_10166 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_integer_t, kk_context_t*), days_before_month, (days_before_month, _x_x1269, _x_x1270, _ctx), _ctx); /*int*/
    kk_integer_t x_0_10163 = kk_integer_sub(doy,y_2_10166,kk_context()); /*int*/;
    kk_integer_t day = kk_integer_add_small_const(x_0_10163, 1, _ctx); /*int*/;
    kk_integer_t year;
    if (kk_std_core_types__is_Optional(has_year_zero, _ctx)) {
      kk_box_t _box_x225 = has_year_zero._cons._Optional.value;
      bool _uniq_has_year_zero_2859 = kk_bool_unbox(_box_x225);
      kk_std_core_types__optional_drop(has_year_zero, _ctx);
      if (_uniq_has_year_zero_2859) {
        year = y_0; /*int*/
      }
      else {
        bool _match_x798 = kk_integer_gt_borrow(y_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x798) {
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
struct kk_std_time_calendar_solar_calendar_fun1271__t {
  struct kk_function_s _base;
  kk_function_t days_before_month;
  kk_function_t days_before_year;
  kk_std_core_types__optional epoch_shift;
  kk_std_core_types__optional has_year_zero;
};
static kk_integer_t kk_std_time_calendar_solar_calendar_fun1271(kk_function_t _fself, kk_std_time_date__date d_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun1271(kk_function_t days_before_month, kk_function_t days_before_year, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1271__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun1271__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun1271, kk_context());
  _self->days_before_month = days_before_month;
  _self->days_before_year = days_before_year;
  _self->epoch_shift = epoch_shift;
  _self->has_year_zero = has_year_zero;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_solar_calendar_fun1271(kk_function_t _fself, kk_std_time_date__date d_0_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1271__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun1271__t*, _fself, _ctx);
  kk_function_t days_before_month = _self->days_before_month; /* (year : int, month : int) -> int */
  kk_function_t days_before_year = _self->days_before_year; /* (year : int) -> int */
  kk_std_core_types__optional epoch_shift = _self->epoch_shift; /* ? int */
  kk_std_core_types__optional has_year_zero = _self->has_year_zero; /* ? bool */
  kk_drop_match(_self, {kk_function_dup(days_before_month, _ctx);kk_function_dup(days_before_year, _ctx);kk_std_core_types__optional_dup(epoch_shift, _ctx);kk_std_core_types__optional_dup(has_year_zero, _ctx);}, {}, _ctx)
  kk_integer_t y_3;
  if (kk_std_core_types__is_Optional(has_year_zero, _ctx)) {
    kk_box_t _box_x226 = has_year_zero._cons._Optional.value;
    bool _uniq_has_year_zero_2859_0 = kk_bool_unbox(_box_x226);
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    if (_uniq_has_year_zero_2859_0) {
      kk_integer_t _x_4 = d_0_1.year;
      kk_integer_dup(_x_4, _ctx);
      y_3 = _x_4; /*int*/
    }
    else {
      bool _match_x794;
      kk_integer_t _brw_x795;
      {
        kk_integer_t _x_5 = d_0_1.year;
        kk_integer_dup(_x_5, _ctx);
        _brw_x795 = _x_5; /*int*/
      }
      bool _brw_x796 = kk_integer_gt_borrow(_brw_x795,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x795, _ctx);
      _match_x794 = _brw_x796; /*bool*/
      if (_match_x794) {
        kk_integer_t _x_6 = d_0_1.year;
        kk_integer_dup(_x_6, _ctx);
        y_3 = _x_6; /*int*/
      }
      else {
        kk_integer_t _x_x1272;
        {
          kk_integer_t _x_7 = d_0_1.year;
          kk_integer_dup(_x_7, _ctx);
          _x_x1272 = _x_7; /*int*/
        }
        y_3 = kk_integer_add_small_const(_x_x1272, 1, _ctx); /*int*/
      }
    }
  }
  else {
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    {
      kk_integer_t _x_4_0 = d_0_1.year;
      kk_integer_dup(_x_4_0, _ctx);
      y_3 = _x_4_0; /*int*/
    }
  }
  kk_integer_t x_4_10179;
  kk_integer_t _x_x1273 = kk_integer_dup(y_3, _ctx); /*int*/
  x_4_10179 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_context_t*), days_before_year, (days_before_year, _x_x1273, _ctx), _ctx); /*int*/
  kk_integer_t y_6_10180;
  kk_integer_t _x_x1274;
  {
    kk_integer_t _x_8 = d_0_1.month;
    kk_integer_dup(_x_8, _ctx);
    _x_x1274 = _x_8; /*int*/
  }
  y_6_10180 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_integer_t, kk_context_t*), days_before_month, (days_before_month, y_3, _x_x1274, _ctx), _ctx); /*int*/
  kk_integer_t x_3_10177 = kk_integer_add(x_4_10179,y_6_10180,kk_context()); /*int*/;
  kk_integer_t y_5_10178;
  kk_integer_t _x_x1275;
  {
    kk_integer_t _x_9 = d_0_1.day;
    kk_integer_dup(_x_9, _ctx);
    kk_std_time_date__date_drop(d_0_1, _ctx);
    _x_x1275 = _x_9; /*int*/
  }
  y_5_10178 = kk_integer_add_small_const(_x_x1275, -1, _ctx); /*int*/
  kk_integer_t x_2_10175 = kk_integer_add(x_3_10177,y_5_10178,kk_context()); /*int*/;
  kk_integer_t _x_x1276;
  if (kk_std_core_types__is_Optional(epoch_shift, _ctx)) {
    kk_box_t _box_x227 = epoch_shift._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2855_0 = kk_integer_unbox(_box_x227, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2855_0, _ctx);
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x1276 = _uniq_epoch_shift_2855_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x1276 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  return kk_integer_sub(x_2_10175,_x_x1276,kk_context());
}


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun1280__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x232;
};
static kk_string_t kk_std_time_calendar_solar_calendar_fun1280(kk_function_t _fself, kk_std_time_date__date _b_x235, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun1280(kk_box_t _fun_unbox_x232, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1280__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun1280__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun1280, kk_context());
  _self->_fun_unbox_x232 = _fun_unbox_x232;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_solar_calendar_fun1280(kk_function_t _fself, kk_std_time_date__date _b_x235, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1280__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun1280__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x232 = _self->_fun_unbox_x232; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x232, _ctx);}, {}, _ctx)
  kk_box_t _x_x1281;
  kk_function_t _x_x1282 = kk_function_unbox(_fun_unbox_x232, _ctx); /*(233) -> 234*/
  _x_x1281 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1282, (_x_x1282, kk_std_time_date__date_box(_b_x235, _ctx), _ctx), _ctx); /*234*/
  return kk_string_unbox(_x_x1281);
}


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun1283__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_time_calendar_solar_calendar_fun1283(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun1283(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_solar_calendar_fun1283, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_std_time_calendar_solar_calendar_fun1283(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_date__date_drop(d_1, _ctx);
  return kk_string_empty();
}


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun1286__t {
  struct kk_function_s _base;
  kk_function_t days_to_date_10157;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_solar_calendar_fun1286(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun1286(kk_function_t days_to_date_10157, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1286__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun1286__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun1286, kk_context());
  _self->days_to_date_10157 = days_to_date_10157;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_solar_calendar_fun1286(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1286__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun1286__t*, _fself, _ctx);
  kk_function_t days_to_date_10157 = _self->days_to_date_10157; /* (days : int) -> std/time/date/date */
  kk_drop_match(_self, {kk_function_dup(days_to_date_10157, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _match_x793;
  kk_std_time_timestamp__timestamp _x_x1287;
  kk_std_num_ddouble__ddouble _x_x1288;
  kk_std_num_ddouble__ddouble _x_x1289;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_3 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1290 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1291 = kk_std_time_instant__as_Timescale(_pat_2_3, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1292 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1292->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1289 = _x; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1293;
  {
    kk_std_num_ddouble__ddouble _x_2 = tzdelta.secs;
    _x_x1293 = _x_2; /*std/time/timestamp/timespan*/
  }
  _x_x1288 = kk_std_num_ddouble__lp__plus__rp_(_x_x1289, _x_x1293, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1294;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_3_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1295 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1296 = kk_std_time_instant__as_Timescale(_pat_2_3_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1297 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1297->since;
      int32_t _x_0 = _con_x1297->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1294 = _x_0; /*int32*/
    }
  }
  _x_x1287 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1288, _x_x1294, _ctx); /*std/time/timestamp/timestamp*/
  _match_x793 = kk_std_time_timestamp_days_clock(_x_x1287, _ctx); /*(int, std/time/date/clock)*/
  {
    kk_box_t _box_x236 = _match_x793.fst;
    kk_box_t _box_x237 = _match_x793.snd;
    kk_std_time_date__clock clock = kk_std_time_date__clock_unbox(_box_x237, KK_BORROWED, _ctx);
    struct kk_std_time_date_Clock* _con_x1298 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_integer_t days = kk_integer_unbox(_box_x236, _ctx);
    kk_std_time_date__clock_dup(clock, _ctx);
    kk_integer_dup(days, _ctx);
    kk_std_core_types__tuple2_drop(_match_x793, _ctx);
    kk_std_time_date__date _b_x238_262 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date_10157, (days_to_date_10157, days, _ctx), _ctx); /*std/time/date/date*/;
    return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x238_262, _ctx), kk_std_time_date__clock_box(clock, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_solar_calendar_fun1300__t {
  struct kk_function_s _base;
  kk_function_t date_to_days_10158;
};
static kk_std_time_instant__instant kk_std_time_calendar_solar_calendar_fun1300(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_calendar_fun1300(kk_function_t date_to_days_10158, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1300__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_calendar_fun1300__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_calendar_fun1300, kk_context());
  _self->date_to_days_10158 = date_to_days_10158;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_solar_calendar_fun1300(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_calendar_fun1300__t* _self = kk_function_as(struct kk_std_time_calendar_solar_calendar_fun1300__t*, _fself, _ctx);
  kk_function_t date_to_days_10158 = _self->date_to_days_10158; /* (std/time/date/date) -> int */
  kk_drop_match(_self, {kk_function_dup(date_to_days_10158, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_10301;
  kk_std_core_types__optional _x_x1301;
  kk_box_t _x_x1302;
  bool _x_x1303;
  {
    struct kk_std_time_instant_Timescale* _con_x1304 = kk_std_time_instant__as_Timescale(ts_0, _ctx);
    kk_std_core_types__maybe _x_3_1 = _con_x1304->mb_seconds_in_day;
    kk_std_core_types__maybe_dup(_x_3_1, _ctx);
    if (kk_std_core_types__is_Just(_x_3_1, _ctx)) {
      kk_std_core_types__maybe_drop(_x_3_1, _ctx);
      _x_x1303 = true; /*bool*/
    }
    else {
      _x_x1303 = false; /*bool*/
    }
  }
  _x_x1302 = kk_bool_box(_x_x1303); /*10003*/
  _x_x1301 = kk_std_core_types__new_Optional(_x_x1302, _ctx); /*? 10003*/
  t_10301 = kk_std_time_calendar_dc_timestamp(d_0_0, c, date_to_days_10158, _x_x1301, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__instant i_0;
  kk_std_time_timestamp__timestamp _x_x1305 = kk_std_time_timestamp__timestamp_dup(t_10301, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1306 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
  i_0 = kk_std_time_instant__new_Instant(_x_x1305, _x_x1306, _ctx); /*std/time/instant/instant*/
  bool _match_x790;
  kk_string_t _x_x1307;
  {
    struct kk_std_time_calendar_Timezone* _con_x1308 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x_3 = _con_x1308->name;
    kk_string_dup(_x_3, _ctx);
    _x_x1307 = _x_3; /*string*/
  }
  kk_string_t _x_x1309;
  kk_std_time_calendar__timezone _x_x1310 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x1311 = kk_std_time_calendar__as_Timezone(_x_x1310, _ctx);
    kk_string_t _x_0_0 = _con_x1311->name;
    _x_x1309 = kk_string_dup(_x_0_0, _ctx); /*string*/
  }
  _match_x790 = kk_string_is_eq(_x_x1307,_x_x1309,kk_context()); /*bool*/
  if (_match_x790) {
    kk_datatype_ptr_dropn(tz, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
    kk_std_time_timestamp__timestamp_drop(t_10301, _ctx);
    return i_0;
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1312 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _pat_0_2_0 = _con_x1312->name;
    kk_function_t _pat_1_1_0 = _con_x1312->utc_delta;
    kk_function_t _x_1_0_0 = _con_x1312->utc_inverse;
    kk_function_dup(_x_1_0_0, _ctx);
    kk_std_core_types__maybe _match_x791;
    kk_std_time_instant__instant _x_x1313 = kk_std_time_instant__instant_dup(i_0, _ctx); /*std/time/instant/instant*/
    _match_x791 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_1_0_0, (_x_1_0_0, _x_x1313, _ctx), _ctx); /*maybe<std/time/instant/instant>*/
    if (kk_std_core_types__is_Just(_match_x791, _ctx)) {
      kk_box_t _box_x249 = _match_x791._cons.Just.value;
      kk_std_time_instant__instant inv = kk_std_time_instant__instant_unbox(_box_x249, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
        kk_function_drop(_x_1_0_0, _ctx);
        kk_function_drop(_pat_1_1_0, _ctx);
        kk_string_drop(_pat_0_2_0, _ctx);
        kk_datatype_ptr_free(tz, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tz, _ctx);
      }
      kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
      kk_std_time_timestamp__timestamp_drop(t_10301, _ctx);
      kk_std_time_instant__instant_drop(i_0, _ctx);
      kk_std_time_instant__instant_dup(inv, _ctx);
      kk_std_core_types__maybe_drop(_match_x791, _ctx);
      return inv;
    }
    {
      kk_std_core_types__tuple2 tuple2_10133;
      {
        struct kk_std_time_calendar_Timezone* _con_x1314 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_function_t _x_3_0 = _con_x1314->utc_delta;
        kk_function_dup(_x_3_0, _ctx);
        tuple2_10133 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_3_0, (_x_3_0, i_0, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      kk_std_time_timestamp__timestamp t_1_10136;
      kk_std_num_ddouble__ddouble _x_x1315;
      kk_std_num_ddouble__ddouble _x_x1316;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1317 = kk_std_time_timestamp__as_Timestamp(t_10301, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0_0_0 = _con_x1317->since;
        _x_x1316 = _x_1_0_0_0; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1318;
      double _x_x1319;
      double _x_x1320;
      {
        kk_box_t _box_x250 = tuple2_10133.fst;
        kk_box_t _box_x251 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0 = kk_std_time_duration__duration_unbox(_box_x250, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0 = _x_2_0.secs;
          {
            double _x_4_0_0 = _x_5_0.hi;
            _x_x1320 = _x_4_0_0; /*float64*/
          }
        }
      }
      _x_x1319 = (-_x_x1320); /*float64*/
      double _x_x1321;
      double _x_x1322;
      {
        kk_box_t _box_x252 = tuple2_10133.fst;
        kk_box_t _box_x253 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_0 = kk_std_time_duration__duration_unbox(_box_x252, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0_0 = _x_2_0_0.secs;
          {
            double _x_0_0_0 = _x_5_0_0.lo;
            _x_x1322 = _x_0_0_0; /*float64*/
          }
        }
      }
      _x_x1321 = (-_x_x1322); /*float64*/
      _x_x1318 = kk_std_num_ddouble__new_Ddouble(_x_x1319, _x_x1321, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1315 = kk_std_num_ddouble__lp__plus__rp_(_x_x1316, _x_x1318, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1323;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1324 = kk_std_time_timestamp__as_Timestamp(t_10301, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_2_0_0 = _con_x1324->since;
        int32_t _x_2_0_0_0 = _con_x1324->leap32;
        _x_x1323 = _x_2_0_0_0; /*int32*/
      }
      t_1_10136 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1315, _x_x1323, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__instant tzi1;
      kk_std_time_instant__timescale _x_x1325 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
      tzi1 = kk_std_time_instant__new_Instant(t_1_10136, _x_x1325, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_0_10140;
      {
        struct kk_std_time_calendar_Timezone* _con_x1326 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_string_t _pat_0_8_0 = _con_x1326->name;
        kk_function_t _x_7_0 = _con_x1326->utc_delta;
        kk_function_t _pat_1_6_0_0 = _con_x1326->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
          kk_function_drop(_pat_1_6_0_0, _ctx);
          kk_string_drop(_pat_0_8_0, _ctx);
          kk_datatype_ptr_free(tz, _ctx);
        }
        else {
          kk_function_dup(_x_7_0, _ctx);
          kk_datatype_ptr_decref(tz, _ctx);
        }
        kk_std_time_instant__instant _x_x1327 = kk_std_time_instant__instant_dup(tzi1, _ctx); /*std/time/instant/instant*/
        tuple2_0_10140 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_7_0, (_x_7_0, _x_x1327, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      bool _match_x792;
      kk_std_time_duration__duration _x_x1328;
      {
        kk_box_t _box_x254 = tuple2_10133.fst;
        kk_box_t _box_x255 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_1 = kk_std_time_duration__duration_unbox(_box_x254, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10133, _ctx);
        _x_x1328 = _x_2_0_1; /*std/time/duration/duration*/
      }
      kk_std_time_duration__duration _x_x1329;
      {
        kk_box_t _box_x256 = tuple2_0_10140.fst;
        kk_box_t _box_x257 = tuple2_0_10140.snd;
        kk_std_time_duration__duration _x_6_0 = kk_std_time_duration__duration_unbox(_box_x256, KK_BORROWED, _ctx);
        _x_x1329 = _x_6_0; /*std/time/duration/duration*/
      }
      _match_x792 = kk_std_time_duration__lp__eq__eq__rp_(_x_x1328, _x_x1329, _ctx); /*bool*/
      if (_match_x792) {
        kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
        kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
        kk_std_time_timestamp__timestamp_drop(t_10301, _ctx);
        return tzi1;
      }
      {
        kk_std_time_instant__instant_drop(tzi1, _ctx);
        kk_std_time_timestamp__timestamp t_3_10143;
        kk_std_num_ddouble__ddouble _x_x1330;
        kk_std_num_ddouble__ddouble _x_x1331;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1332 = kk_std_time_timestamp__as_Timestamp(t_10301, _ctx);
          kk_std_num_ddouble__ddouble _x_1_1 = _con_x1332->since;
          _x_x1331 = _x_1_1; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x1333;
        double _x_x1334;
        double _x_x1335;
        {
          kk_box_t _box_x258 = tuple2_0_10140.fst;
          kk_box_t _box_x259 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0_0 = kk_std_time_duration__duration_unbox(_box_x258, KK_BORROWED, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0 = _x_6_0_0.secs;
            {
              double _x_8_0 = _x_9_0.hi;
              _x_x1335 = _x_8_0; /*float64*/
            }
          }
        }
        _x_x1334 = (-_x_x1335); /*float64*/
        double _x_x1336;
        double _x_x1337;
        {
          kk_box_t _box_x260 = tuple2_0_10140.fst;
          kk_box_t _box_x261 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0_1 = kk_std_time_duration__duration_unbox(_box_x260, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0_0 = _x_6_0_1.secs;
            {
              double _x_0_1 = _x_9_0_0.lo;
              _x_x1337 = _x_0_1; /*float64*/
            }
          }
        }
        _x_x1336 = (-_x_x1337); /*float64*/
        _x_x1333 = kk_std_num_ddouble__new_Ddouble(_x_x1334, _x_x1336, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1330 = kk_std_num_ddouble__lp__plus__rp_(_x_x1331, _x_x1333, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x1338;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1339 = kk_std_time_timestamp__as_Timestamp(t_10301, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_2_1 = _con_x1339->since;
          int32_t _x_2_1 = _con_x1339->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(t_10301, _ctx)) {
            kk_datatype_ptr_free(t_10301, _ctx);
          }
          else {
            kk_datatype_ptr_decref(t_10301, _ctx);
          }
          _x_x1338 = _x_2_1; /*int32*/
        }
        t_3_10143 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1330, _x_x1338, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_instant__new_Instant(t_3_10143, ts_0, _ctx);
      }
    }
  }
}

kk_std_time_calendar__calendar kk_std_time_calendar_solar_calendar(kk_string_t name, kk_string_t long_name, kk_function_t days_before_year, kk_function_t days_to_yeardoy, kk_function_t days_before_month, kk_function_t days_to_month, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, days-before-year : (year : int) -> int, days-to-yeardoy : (days : int) -> (int, int), days-before-month : (year : int, month : int) -> int, days-to-month : (year : int, doy : int) -> int, epoch-shift : ? int, has-year-zero : ? bool, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_function_t days_to_date_10157;
  kk_function_dup(days_before_month, _ctx);
  kk_std_core_types__optional_dup(epoch_shift, _ctx);
  kk_std_core_types__optional_dup(has_year_zero, _ctx);
  days_to_date_10157 = kk_std_time_calendar_new_solar_calendar_fun1265(days_before_month, days_to_month, days_to_yeardoy, epoch_shift, has_year_zero, _ctx); /*(days0 : int) -> std/time/date/date*/
  kk_function_t date_to_days_10158 = kk_std_time_calendar_new_solar_calendar_fun1271(days_before_month, days_before_year, epoch_shift, has_year_zero, _ctx); /*(d@0@1 : std/time/date/date) -> int*/;
  kk_string_t _x_x1277;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x228 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2863 = kk_string_unbox(_box_x228);
    kk_string_dup(_uniq_month_prefix_2863, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1277 = _uniq_month_prefix_2863; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1277 = kk_string_empty(); /*string*/
  }
  kk_function_t _x_x1279;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x232 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x232, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x1279 = kk_std_time_calendar_new_solar_calendar_fun1280(_fun_unbox_x232, _ctx); /*(std/time/date/date) -> string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x1279 = kk_std_time_calendar_new_solar_calendar_fun1283(_ctx); /*(std/time/date/date) -> string*/
  }
  kk_function_t _x_x1285;
  kk_function_dup(days_to_date_10157, _ctx);
  _x_x1285 = kk_std_time_calendar_new_solar_calendar_fun1286(days_to_date_10157, _ctx); /*(i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (10037, 10038)*/
  kk_function_t _x_x1299;
  kk_function_dup(date_to_days_10158, _ctx);
  _x_x1299 = kk_std_time_calendar_new_solar_calendar_fun1300(date_to_days_10158, _ctx); /*(d@0@0 : std/time/date/date, c : std/time/date/clock, tz : std/time/calendar/timezone, ts@0 : std/time/instant/timescale) -> std/time/instant/instant*/
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, name, long_name, _x_x1277, _x_x1279, _x_x1285, _x_x1299, days_to_date_10157, date_to_days_10158, _ctx);
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
struct kk_std_time_calendar_solar_ecalendar_fun1341__t {
  struct kk_function_s _base;
  kk_function_t days_before_year;
  kk_function_t estimate_year;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_solar_ecalendar_fun1341(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_ecalendar_fun1341(kk_function_t days_before_year, kk_function_t estimate_year, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun1341__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_ecalendar_fun1341__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_ecalendar_fun1341, kk_context());
  _self->days_before_year = days_before_year;
  _self->estimate_year = estimate_year;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_solar_ecalendar_fun1341(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun1341__t* _self = kk_function_as(struct kk_std_time_calendar_solar_ecalendar_fun1341__t*, _fself, _ctx);
  kk_function_t days_before_year = _self->days_before_year; /* (year : int) -> int */
  kk_function_t estimate_year = _self->estimate_year; /* (days : int) -> (int, maybe<int>) */
  kk_drop_match(_self, {kk_function_dup(days_before_year, _ctx);kk_function_dup(estimate_year, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _match_x785;
  kk_integer_t _x_x1342 = kk_integer_dup(days, _ctx); /*int*/
  _match_x785 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_integer_t, kk_context_t*), estimate_year, (estimate_year, _x_x1342, _ctx), _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x264 = _match_x785.fst;
    kk_box_t _box_x265 = _match_x785.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x264, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x265, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x785, _ctx);
    kk_integer_t y_10193;
    kk_function_t _x_x1344 = kk_function_dup(days_before_year, _ctx); /*(year : int) -> int*/
    kk_integer_t _x_x1343 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1344, (_x_x1344, _x_x1343, _ctx), _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1345 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1345,y_10193,kk_context()); /*int*/
    bool _match_x786;
    kk_integer_t _brw_x788;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x788 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x266 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x266, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x788 = x_0; /*int*/
    }
    bool _brw_x789 = kk_integer_lte_borrow(doy1,_brw_x788,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x788, _ctx);
    _match_x786 = _brw_x789; /*bool*/
    if (_match_x786) {
      kk_function_drop(days_before_year, _ctx);
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t y_0_10197;
      kk_integer_t _x_x1346;
      kk_integer_t _x_x1347 = kk_integer_dup(approx, _ctx); /*int*/
      _x_x1346 = kk_integer_add_small_const(_x_x1347, 1, _ctx); /*int*/
      y_0_10197 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_context_t*), days_before_year, (days_before_year, _x_x1346, _ctx), _ctx); /*int*/
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x787 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x787) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x271_294 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x271_294, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_solar_ecalendar_fun1359__t {
  struct kk_function_s _base;
  kk_std_core_types__optional show_era;
};
static kk_box_t kk_std_time_calendar_solar_ecalendar_fun1359(kk_function_t _fself, kk_box_t _b_x289, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_solar_ecalendar_fun1359(kk_std_core_types__optional show_era, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun1359__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_solar_ecalendar_fun1359__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_solar_ecalendar_fun1359, kk_context());
  _self->show_era = show_era;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_solar_ecalendar_fun1359(kk_function_t _fself, kk_box_t _b_x289, kk_context_t* _ctx) {
  struct kk_std_time_calendar_solar_ecalendar_fun1359__t* _self = kk_function_as(struct kk_std_time_calendar_solar_ecalendar_fun1359__t*, _fself, _ctx);
  kk_std_core_types__optional show_era = _self->show_era; /* ? ((std/time/date/date) -> string) */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(show_era, _ctx);}, {}, _ctx)
  kk_string_t _x_x1360;
  kk_std_time_date__date _norm_x300 = kk_std_time_date__date_unbox(_b_x289, KK_OWNED, _ctx); /*std/time/date/date*/;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x282 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x282, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date _b_x285_301 = _norm_x300; /*std/time/date/date*/;
    kk_box_t _x_x1361;
    kk_function_t _x_x1362 = kk_function_unbox(_fun_unbox_x282, _ctx); /*(283) -> 284*/
    _x_x1361 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1362, (_x_x1362, kk_std_time_date__date_box(_b_x285_301, _ctx), _ctx), _ctx); /*284*/
    _x_x1360 = kk_string_unbox(_x_x1361); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    kk_std_time_date__date d_302 = _norm_x300; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_302, _ctx);
    _x_x1360 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1360);
}

kk_std_time_calendar__calendar kk_std_time_calendar_solar_ecalendar(kk_string_t name, kk_string_t long_name, kk_function_t days_before_year, kk_function_t estimate_year, kk_function_t days_before_month, kk_function_t days_to_month, kk_std_core_types__optional epoch_shift, kk_std_core_types__optional has_year_zero, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, days-before-year : (year : int) -> int, estimate-year : (days : int) -> (int, maybe<int>), days-before-month : (year : int, month : int) -> int, days-to-month : (year : int, doy : int) -> int, epoch-shift : ? int, has-year-zero : ? bool, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_function_t _x_x1340 = kk_function_dup(days_before_year, _ctx); /*(year : int) -> int*/
  kk_std_core_types__optional _x_x1348;
  kk_box_t _x_x1349;
  kk_integer_t _x_x1350;
  if (kk_std_core_types__is_Optional(epoch_shift, _ctx)) {
    kk_box_t _box_x273 = epoch_shift._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x273, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x1350 = _uniq_epoch_shift_2171; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(epoch_shift, _ctx);
    _x_x1350 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  _x_x1349 = kk_integer_box(_x_x1350, _ctx); /*10003*/
  _x_x1348 = kk_std_core_types__new_Optional(_x_x1349, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1351;
  kk_box_t _x_x1352;
  bool _x_x1353;
  if (kk_std_core_types__is_Optional(has_year_zero, _ctx)) {
    kk_box_t _box_x275 = has_year_zero._cons._Optional.value;
    bool _uniq_has_year_zero_2175 = kk_bool_unbox(_box_x275);
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    _x_x1353 = _uniq_has_year_zero_2175; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(has_year_zero, _ctx);
    _x_x1353 = true; /*bool*/
  }
  _x_x1352 = kk_bool_box(_x_x1353); /*10003*/
  _x_x1351 = kk_std_core_types__new_Optional(_x_x1352, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1354;
  kk_box_t _x_x1355;
  kk_string_t _x_x1356;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x277 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x277);
    kk_string_dup(_uniq_month_prefix_2179, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1356 = _uniq_month_prefix_2179; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1356 = kk_string_empty(); /*string*/
  }
  _x_x1355 = kk_string_box(_x_x1356); /*10003*/
  _x_x1354 = kk_std_core_types__new_Optional(_x_x1355, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1358 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_solar_ecalendar_fun1359(show_era, _ctx), _ctx), _ctx); /*? 10003*/
  return kk_std_time_calendar_solar_calendar(name, long_name, _x_x1340, kk_std_time_calendar_new_solar_ecalendar_fun1341(days_before_year, estimate_year, _ctx), days_before_month, days_to_month, _x_x1348, _x_x1351, _x_x1354, _x_x1358, _ctx);
}
 
// Create a standard ISO calendar using a particular time scale
// and calendar `name` (=`ts.name`).


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun1367__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_iso_calendar_fun1367(kk_function_t _fself, kk_integer_t _x1_x1366, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun1367(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun1367, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_iso_calendar_fun1367(kk_function_t _fself, kk_integer_t _x1_x1366, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1366, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun1368__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_iso_calendar_fun1368(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun1368(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun1368, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_iso_calendar_fun1368(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _match_x780;
  kk_integer_t _x_x1369 = kk_integer_dup(days, _ctx); /*int*/
  _match_x780 = kk_std_time_calendar_iso_estimate_year(_x_x1369, _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x304 = _match_x780.fst;
    kk_box_t _box_x305 = _match_x780.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x304, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x305, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x780, _ctx);
    kk_integer_t y_10193;
    kk_integer_t _x_x1370 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_std_time_calendar_iso_days_before_year(_x_x1370, _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1371 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1371,y_10193,kk_context()); /*int*/
    bool _match_x781;
    kk_integer_t _brw_x783;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x783 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x306 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x306, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x783 = x_0; /*int*/
    }
    bool _brw_x784 = kk_integer_lte_borrow(doy1,_brw_x783,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x783, _ctx);
    _match_x781 = _brw_x784; /*bool*/
    if (_match_x781) {
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t year_10488;
      kk_integer_t _x_x1372 = kk_integer_dup(approx, _ctx); /*int*/
      year_10488 = kk_integer_add_small_const(_x_x1372, 1, _ctx); /*int*/
      kk_integer_t y = kk_integer_add_small_const(year_10488, -1, _ctx); /*int*/;
      kk_integer_t x_0_10117;
      kk_integer_t _x_x1373 = kk_integer_dup(y, _ctx); /*int*/
      x_0_10117 = kk_integer_div(_x_x1373,(kk_integer_from_small(4)),kk_context()); /*int*/
      kk_integer_t y_1_10118;
      kk_integer_t _x_x1374 = kk_integer_dup(y, _ctx); /*int*/
      y_1_10118 = kk_integer_div(_x_x1374,(kk_integer_from_small(100)),kk_context()); /*int*/
      kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
      kk_integer_t y_0_10116;
      kk_integer_t _x_x1375 = kk_integer_dup(y, _ctx); /*int*/
      y_0_10116 = kk_integer_div(_x_x1375,(kk_integer_from_small(400)),kk_context()); /*int*/
      kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
      kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
      kk_integer_t y_0_10197 = kk_integer_add(x_1_10119,leapdays,kk_context()); /*int*/;
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x782 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x782) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x311_334 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x311_334, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun1378__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_iso_calendar_fun1378(kk_function_t _fself, kk_integer_t _x1_x1376, kk_integer_t _x2_x1377, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun1378(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun1378, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_iso_calendar_fun1378(kk_function_t _fself, kk_integer_t _x1_x1376, kk_integer_t _x2_x1377, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1376, _x2_x1377, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun1381__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_iso_calendar_fun1381(kk_function_t _fself, kk_integer_t _x1_x1379, kk_integer_t _x2_x1380, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun1381(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun1381, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_iso_calendar_fun1381(kk_function_t _fself, kk_integer_t _x1_x1379, kk_integer_t _x2_x1380, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1379, _x2_x1380, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_iso_calendar_fun1393__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_iso_calendar_fun1393(kk_function_t _fself, kk_box_t _b_x329, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_iso_calendar_fun1393(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_iso_calendar_fun1393, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_iso_calendar_fun1393(kk_function_t _fself, kk_box_t _b_x329, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1394;
  kk_std_time_date__date _norm_x340 = kk_std_time_date__date_unbox(_b_x329, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_std_core_types__optional _match_x776 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x776, _ctx)) {
    kk_box_t _fun_unbox_x322 = _match_x776._cons._Optional.value;
    kk_box_dup(_fun_unbox_x322, _ctx);
    kk_std_core_types__optional_drop(_match_x776, _ctx);
    kk_std_time_date__date _b_x325_341 = _norm_x340; /*std/time/date/date*/;
    kk_box_t _x_x1395;
    kk_function_t _x_x1396 = kk_function_unbox(_fun_unbox_x322, _ctx); /*(323) -> 324*/
    _x_x1395 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1396, (_x_x1396, kk_std_time_date__date_box(_b_x325_341, _ctx), _ctx), _ctx); /*324*/
    _x_x1394 = kk_string_unbox(_x_x1395); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x776, _ctx);
    kk_std_time_date__date d_342 = _norm_x340; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_342, _ctx);
    _x_x1394 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1394);
}

kk_std_time_calendar__calendar kk_std_time_calendar_iso_calendar(kk_std_time_instant__timescale ___wildcard_x422__23, kk_string_t name, kk_std_core_types__optional long_name, kk_context_t* _ctx) { /* (std/time/instant/timescale, name : string, long-name : ? string) -> calendar */ 
  kk_datatype_ptr_dropn(___wildcard_x422__23, (KK_I32(10)), _ctx);
  kk_string_t _x_x1364 = kk_string_dup(name, _ctx); /*string*/
  kk_string_t _x_x1365;
  if (kk_std_core_types__is_Optional(long_name, _ctx)) {
    kk_box_t _box_x303 = long_name._cons._Optional.value;
    kk_string_t _uniq_long_name_2416 = kk_string_unbox(_box_x303);
    kk_string_drop(name, _ctx);
    kk_string_dup(_uniq_long_name_2416, _ctx);
    kk_std_core_types__optional_drop(long_name, _ctx);
    _x_x1365 = _uniq_long_name_2416; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(long_name, _ctx);
    _x_x1365 = name; /*string*/
  }
  kk_std_core_types__optional _x_x1382;
  kk_box_t _x_x1383;
  kk_integer_t _x_x1384;
  kk_std_core_types__optional _match_x779 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x779, _ctx)) {
    kk_box_t _box_x313 = _match_x779._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x313, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
    kk_std_core_types__optional_drop(_match_x779, _ctx);
    _x_x1384 = _uniq_epoch_shift_2171; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x779, _ctx);
    _x_x1384 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  _x_x1383 = kk_integer_box(_x_x1384, _ctx); /*10003*/
  _x_x1382 = kk_std_core_types__new_Optional(_x_x1383, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1385;
  kk_box_t _x_x1386;
  bool _x_x1387;
  kk_std_core_types__optional _match_x778 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x778, _ctx)) {
    kk_box_t _box_x315 = _match_x778._cons._Optional.value;
    bool _uniq_has_year_zero_2175 = kk_bool_unbox(_box_x315);
    kk_std_core_types__optional_drop(_match_x778, _ctx);
    _x_x1387 = _uniq_has_year_zero_2175; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x778, _ctx);
    _x_x1387 = true; /*bool*/
  }
  _x_x1386 = kk_bool_box(_x_x1387); /*10003*/
  _x_x1385 = kk_std_core_types__new_Optional(_x_x1386, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1388;
  kk_box_t _x_x1389;
  kk_string_t _x_x1390;
  kk_std_core_types__optional _match_x777 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x777, _ctx)) {
    kk_box_t _box_x317 = _match_x777._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x317);
    kk_string_dup(_uniq_month_prefix_2179, _ctx);
    kk_std_core_types__optional_drop(_match_x777, _ctx);
    _x_x1390 = _uniq_month_prefix_2179; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x777, _ctx);
    _x_x1390 = kk_string_empty(); /*string*/
  }
  _x_x1389 = kk_string_box(_x_x1390); /*10003*/
  _x_x1388 = kk_std_core_types__new_Optional(_x_x1389, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1392 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_iso_calendar_fun1393(_ctx), _ctx), _ctx); /*? 10003*/
  return kk_std_time_calendar_solar_calendar(_x_x1364, _x_x1365, kk_std_time_calendar_new_iso_calendar_fun1367(_ctx), kk_std_time_calendar_new_iso_calendar_fun1368(_ctx), kk_std_time_calendar_new_iso_calendar_fun1378(_ctx), kk_std_time_calendar_new_iso_calendar_fun1381(_ctx), _x_x1382, _x_x1385, _x_x1388, _x_x1392, _ctx);
}
 
// The standard [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) calendar
// using TI time (`ts-ti`). This is a proleptic Gregorian
// calendar except that it uses the year 0 for 1 BCE, -1 for 2 BCE etc.
//
// This is the default calendar used in the library as it guarantees deterministic
// date calculations while still taking historical leap seconds into account.


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun1403__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_fun1403(kk_function_t _fself, kk_integer_t _x1_x1402, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun1403(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun1403, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_fun1403(kk_function_t _fself, kk_integer_t _x1_x1402, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1402, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun1404__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_fun1404(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun1404(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun1404, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_fun1404(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _match_x771;
  kk_integer_t _x_x1405 = kk_integer_dup(days, _ctx); /*int*/
  _match_x771 = kk_std_time_calendar_iso_estimate_year(_x_x1405, _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x343 = _match_x771.fst;
    kk_box_t _box_x344 = _match_x771.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x343, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x344, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x771, _ctx);
    kk_integer_t y_10193;
    kk_integer_t _x_x1406 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_std_time_calendar_iso_days_before_year(_x_x1406, _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1407 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1407,y_10193,kk_context()); /*int*/
    bool _match_x772;
    kk_integer_t _brw_x774;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x774 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x345 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x345, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x774 = x_0; /*int*/
    }
    bool _brw_x775 = kk_integer_lte_borrow(doy1,_brw_x774,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x774, _ctx);
    _match_x772 = _brw_x775; /*bool*/
    if (_match_x772) {
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t year_10489;
      kk_integer_t _x_x1408 = kk_integer_dup(approx, _ctx); /*int*/
      year_10489 = kk_integer_add_small_const(_x_x1408, 1, _ctx); /*int*/
      kk_integer_t y = kk_integer_add_small_const(year_10489, -1, _ctx); /*int*/;
      kk_integer_t x_0_10117;
      kk_integer_t _x_x1409 = kk_integer_dup(y, _ctx); /*int*/
      x_0_10117 = kk_integer_div(_x_x1409,(kk_integer_from_small(4)),kk_context()); /*int*/
      kk_integer_t y_1_10118;
      kk_integer_t _x_x1410 = kk_integer_dup(y, _ctx); /*int*/
      y_1_10118 = kk_integer_div(_x_x1410,(kk_integer_from_small(100)),kk_context()); /*int*/
      kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
      kk_integer_t y_0_10116;
      kk_integer_t _x_x1411 = kk_integer_dup(y, _ctx); /*int*/
      y_0_10116 = kk_integer_div(_x_x1411,(kk_integer_from_small(400)),kk_context()); /*int*/
      kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
      kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
      kk_integer_t y_0_10197 = kk_integer_add(x_1_10119,leapdays,kk_context()); /*int*/;
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x773 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x773) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x350_373 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x350_373, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun1414__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_fun1414(kk_function_t _fself, kk_integer_t _x1_x1412, kk_integer_t _x2_x1413, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun1414(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun1414, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_fun1414(kk_function_t _fself, kk_integer_t _x1_x1412, kk_integer_t _x2_x1413, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1412, _x2_x1413, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun1417__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_fun1417(kk_function_t _fself, kk_integer_t _x1_x1415, kk_integer_t _x2_x1416, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun1417(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun1417, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_fun1417(kk_function_t _fself, kk_integer_t _x1_x1415, kk_integer_t _x2_x1416, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1415, _x2_x1416, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_fun1429__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_cal_iso_fun1429(kk_function_t _fself, kk_box_t _b_x368, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_fun1429(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_fun1429, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_cal_iso_fun1429(kk_function_t _fself, kk_box_t _b_x368, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1430;
  kk_std_time_date__date _norm_x379 = kk_std_time_date__date_unbox(_b_x368, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_std_core_types__optional _match_x767 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x767, _ctx)) {
    kk_box_t _fun_unbox_x361 = _match_x767._cons._Optional.value;
    kk_box_dup(_fun_unbox_x361, _ctx);
    kk_std_core_types__optional_drop(_match_x767, _ctx);
    kk_std_time_date__date _b_x364_380 = _norm_x379; /*std/time/date/date*/;
    kk_box_t _x_x1431;
    kk_function_t _x_x1432 = kk_function_unbox(_fun_unbox_x361, _ctx); /*(362) -> 363*/
    _x_x1431 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1432, (_x_x1432, kk_std_time_date__date_box(_b_x364_380, _ctx), _ctx), _ctx); /*363*/
    _x_x1430 = kk_string_unbox(_x_x1431); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x767, _ctx);
    kk_std_time_date__date d_381 = _norm_x379; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_381, _ctx);
    _x_x1430 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1430);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_iso;
 
// Return the instant in time for a given `:date` and `:clock` (= `clock0`) interpreted by
// calendar `cal` (=`cal-iso`) in a timezone `tz` (=`tz-utc` by default).

kk_std_time_instant__instant kk_std_time_calendar_date_fs_instant(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, tz : ? timezone, cal : ? calendar) -> std/time/instant/instant */ 
  kk_std_time_calendar__calendar _match_x766;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x382 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2474 = kk_std_time_calendar__calendar_unbox(_box_x382, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2474, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x766 = _uniq_cal_2474; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x766 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1434 = kk_std_time_calendar__as_Calendar(_match_x766, _ctx);
    kk_string_t _pat_0 = _con_x1434->name;
    kk_string_t _pat_1 = _con_x1434->long_name;
    kk_string_t _pat_2 = _con_x1434->month_prefix;
    kk_function_t _pat_3 = _con_x1434->show_era;
    kk_function_t _pat_4 = _con_x1434->instant_to_dc;
    kk_function_t _x = _con_x1434->dc_to_instant;
    kk_function_t _pat_5 = _con_x1434->days_to_date;
    kk_function_t _pat_6 = _con_x1434->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x766, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x766, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x766, _ctx);
    }
    kk_std_time_date__clock _x_x1435;
    if (kk_std_core_types__is_Optional(c, _ctx)) {
      kk_box_t _box_x383 = c._cons._Optional.value;
      kk_std_time_date__clock _uniq_c_2466 = kk_std_time_date__clock_unbox(_box_x383, KK_BORROWED, _ctx);
      kk_std_time_date__clock_dup(_uniq_c_2466, _ctx);
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1435 = _uniq_c_2466; /*std/time/date/clock*/
    }
    else {
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1435 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    }
    kk_std_time_calendar__timezone _x_x1436;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x384 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_2470 = kk_std_time_calendar__timezone_unbox(_box_x384, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_2470, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1436 = _uniq_tz_2470; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1436 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    return kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x1435, _x_x1436, ts, _ctx), _ctx);
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
  kk_std_num_ddouble__ddouble _x_x1437;
  kk_integer_t _x_x1438;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x385 = seconds._cons._Optional.value;
    kk_integer_t _uniq_seconds_3078 = kk_integer_unbox(_box_x385, _ctx);
    kk_integer_dup(_uniq_seconds_3078, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x1438 = _uniq_seconds_3078; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x1438 = kk_integer_from_small(0); /*int*/
  }
  _x_x1437 = kk_std_num_ddouble_ddouble_int_exp(_x_x1438, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1439;
  double _x_x1440;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x386 = frac._cons._Optional.value;
    double _uniq_frac_3082 = kk_double_unbox(_box_x386, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1440 = _uniq_frac_3082; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1440 = 0x0p+0; /*float64*/
  }
  _x_x1439 = kk_std_num_ddouble__new_Ddouble(_x_x1440, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  fsecs = kk_std_num_ddouble__lp__plus__rp_(_x_x1437, _x_x1439, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_time_calendar__calendar _match_x765;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x387 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3090 = kk_std_time_calendar__calendar_unbox(_box_x387, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3090, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x765 = _uniq_cal_3090; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x765 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1441 = kk_std_time_calendar__as_Calendar(_match_x765, _ctx);
    kk_string_t _pat_0 = _con_x1441->name;
    kk_string_t _pat_1 = _con_x1441->long_name;
    kk_string_t _pat_2 = _con_x1441->month_prefix;
    kk_function_t _pat_3 = _con_x1441->show_era;
    kk_function_t _pat_4 = _con_x1441->instant_to_dc;
    kk_function_t _x = _con_x1441->dc_to_instant;
    kk_function_t _pat_5 = _con_x1441->days_to_date;
    kk_function_t _pat_6 = _con_x1441->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x765, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x765, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x765, _ctx);
    }
    kk_std_time_date__date _x_x1442;
    kk_integer_t _x_x1443;
    if (kk_std_core_types__is_Optional(month, _ctx)) {
      kk_box_t _box_x388 = month._cons._Optional.value;
      kk_integer_t _uniq_month_3062 = kk_integer_unbox(_box_x388, _ctx);
      kk_integer_dup(_uniq_month_3062, _ctx);
      kk_std_core_types__optional_drop(month, _ctx);
      _x_x1443 = _uniq_month_3062; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(month, _ctx);
      _x_x1443 = kk_integer_from_small(1); /*int*/
    }
    kk_integer_t _x_x1444;
    if (kk_std_core_types__is_Optional(day, _ctx)) {
      kk_box_t _box_x389 = day._cons._Optional.value;
      kk_integer_t _uniq_day_3066 = kk_integer_unbox(_box_x389, _ctx);
      kk_integer_dup(_uniq_day_3066, _ctx);
      kk_std_core_types__optional_drop(day, _ctx);
      _x_x1444 = _uniq_day_3066; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(day, _ctx);
      _x_x1444 = kk_integer_from_small(1); /*int*/
    }
    _x_x1442 = kk_std_time_date__new_Date(year, _x_x1443, _x_x1444, _ctx); /*std/time/date/date*/
    kk_std_time_date__clock _x_x1445;
    kk_integer_t _x_x1446;
    if (kk_std_core_types__is_Optional(hours, _ctx)) {
      kk_box_t _box_x390 = hours._cons._Optional.value;
      kk_integer_t _uniq_hours_3070 = kk_integer_unbox(_box_x390, _ctx);
      kk_integer_dup(_uniq_hours_3070, _ctx);
      kk_std_core_types__optional_drop(hours, _ctx);
      _x_x1446 = _uniq_hours_3070; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(hours, _ctx);
      _x_x1446 = kk_integer_from_small(0); /*int*/
    }
    kk_integer_t _x_x1447;
    if (kk_std_core_types__is_Optional(minutes, _ctx)) {
      kk_box_t _box_x391 = minutes._cons._Optional.value;
      kk_integer_t _uniq_minutes_3074 = kk_integer_unbox(_box_x391, _ctx);
      kk_integer_dup(_uniq_minutes_3074, _ctx);
      kk_std_core_types__optional_drop(minutes, _ctx);
      _x_x1447 = _uniq_minutes_3074; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(minutes, _ctx);
      _x_x1447 = kk_integer_from_small(0); /*int*/
    }
    _x_x1445 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x1446, _x_x1447, fsecs, _ctx); /*std/time/date/clock*/
    kk_std_time_calendar__timezone _x_x1448;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x392 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3086 = kk_std_time_calendar__timezone_unbox(_box_x392, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3086, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1448 = _uniq_tz_3086; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1448 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    return kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, _x_x1442, _x_x1445, _x_x1448, tscale, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_time_instant__instant kk_std_time_calendar_utc_fs__mlift_instant_10486(kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_integer_t year, kk_std_time_instant__timescale _c_x10451, kk_context_t* _ctx) { /* (cal : ? calendar, day : ? int, frac : ? float64, hours : ? int, minutes : ? int, month : ? int, seconds : ? int, tz : ? timezone, year : int, std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/time/utc/utc>*/;
  kk_std_num_ddouble__ddouble fsecs;
  kk_std_num_ddouble__ddouble _x_x1449;
  kk_integer_t _x_x1450;
  if (kk_std_core_types__is_Optional(seconds, _ctx)) {
    kk_box_t _box_x393 = seconds._cons._Optional.value;
    kk_integer_t _uniq_seconds_3176 = kk_integer_unbox(_box_x393, _ctx);
    kk_integer_dup(_uniq_seconds_3176, _ctx);
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x1450 = _uniq_seconds_3176; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(seconds, _ctx);
    _x_x1450 = kk_integer_from_small(0); /*int*/
  }
  _x_x1449 = kk_std_num_ddouble_ddouble_int_exp(_x_x1450, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1451;
  double _x_x1452;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x394 = frac._cons._Optional.value;
    double _uniq_frac_3180 = kk_double_unbox(_box_x394, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1452 = _uniq_frac_3180; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1452 = 0x0p+0; /*float64*/
  }
  _x_x1451 = kk_std_num_ddouble__new_Ddouble(_x_x1452, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  fsecs = kk_std_num_ddouble__lp__plus__rp_(_x_x1449, _x_x1451, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_time_instant__instant x;
  kk_std_time_calendar__calendar _match_x764;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x395 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3188 = kk_std_time_calendar__calendar_unbox(_box_x395, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3188, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x764 = _uniq_cal_3188; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x764 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1453 = kk_std_time_calendar__as_Calendar(_match_x764, _ctx);
    kk_string_t _pat_0 = _con_x1453->name;
    kk_string_t _pat_1 = _con_x1453->long_name;
    kk_string_t _pat_2 = _con_x1453->month_prefix;
    kk_function_t _pat_3 = _con_x1453->show_era;
    kk_function_t _pat_4 = _con_x1453->instant_to_dc;
    kk_function_t _x = _con_x1453->dc_to_instant;
    kk_function_t _pat_5 = _con_x1453->days_to_date;
    kk_function_t _pat_6 = _con_x1453->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x764, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x764, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x764, _ctx);
    }
    kk_std_time_date__date _x_x1454;
    kk_integer_t _x_x1455;
    if (kk_std_core_types__is_Optional(month, _ctx)) {
      kk_box_t _box_x396 = month._cons._Optional.value;
      kk_integer_t _uniq_month_3160 = kk_integer_unbox(_box_x396, _ctx);
      kk_integer_dup(_uniq_month_3160, _ctx);
      kk_std_core_types__optional_drop(month, _ctx);
      _x_x1455 = _uniq_month_3160; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(month, _ctx);
      _x_x1455 = kk_integer_from_small(1); /*int*/
    }
    kk_integer_t _x_x1456;
    if (kk_std_core_types__is_Optional(day, _ctx)) {
      kk_box_t _box_x397 = day._cons._Optional.value;
      kk_integer_t _uniq_day_3164 = kk_integer_unbox(_box_x397, _ctx);
      kk_integer_dup(_uniq_day_3164, _ctx);
      kk_std_core_types__optional_drop(day, _ctx);
      _x_x1456 = _uniq_day_3164; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(day, _ctx);
      _x_x1456 = kk_integer_from_small(1); /*int*/
    }
    _x_x1454 = kk_std_time_date__new_Date(year, _x_x1455, _x_x1456, _ctx); /*std/time/date/date*/
    kk_std_time_date__clock _x_x1457;
    kk_integer_t _x_x1458;
    if (kk_std_core_types__is_Optional(hours, _ctx)) {
      kk_box_t _box_x398 = hours._cons._Optional.value;
      kk_integer_t _uniq_hours_3168 = kk_integer_unbox(_box_x398, _ctx);
      kk_integer_dup(_uniq_hours_3168, _ctx);
      kk_std_core_types__optional_drop(hours, _ctx);
      _x_x1458 = _uniq_hours_3168; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(hours, _ctx);
      _x_x1458 = kk_integer_from_small(0); /*int*/
    }
    kk_integer_t _x_x1459;
    if (kk_std_core_types__is_Optional(minutes, _ctx)) {
      kk_box_t _box_x399 = minutes._cons._Optional.value;
      kk_integer_t _uniq_minutes_3172 = kk_integer_unbox(_box_x399, _ctx);
      kk_integer_dup(_uniq_minutes_3172, _ctx);
      kk_std_core_types__optional_drop(minutes, _ctx);
      _x_x1459 = _uniq_minutes_3172; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(minutes, _ctx);
      _x_x1459 = kk_integer_from_small(0); /*int*/
    }
    _x_x1457 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x1458, _x_x1459, fsecs, _ctx); /*std/time/date/clock*/
    kk_std_time_calendar__timezone _x_x1460;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x400 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3184 = kk_std_time_calendar__timezone_unbox(_box_x400, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3184, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1460 = _uniq_tz_3184; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1460 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    x = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, _x_x1454, _x_x1457, _x_x1460, _c_x10451, _ctx), _ctx); /*std/time/instant/instant*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}


// lift anonymous function
struct kk_std_time_calendar_utc_fs_instant_fun1464__t {
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
static kk_box_t kk_std_time_calendar_utc_fs_instant_fun1464(kk_function_t _fself, kk_box_t _b_x409, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utc_fs_new_instant_fun1464(kk_std_core_types__optional cal, kk_std_core_types__optional day, kk_std_core_types__optional frac, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional month, kk_std_core_types__optional seconds, kk_std_core_types__optional tz, kk_integer_t year, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs_instant_fun1464__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utc_fs_instant_fun1464__t, 18, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utc_fs_instant_fun1464, kk_context());
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

static kk_box_t kk_std_time_calendar_utc_fs_instant_fun1464(kk_function_t _fself, kk_box_t _b_x409, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utc_fs_instant_fun1464__t* _self = kk_function_as(struct kk_std_time_calendar_utc_fs_instant_fun1464__t*, _fself, _ctx);
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
  kk_std_time_instant__timescale _c_x10451_419 = kk_std_time_instant__timescale_unbox(_b_x409, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x1465 = kk_std_time_calendar_utc_fs__mlift_instant_10486(cal, day, frac, hours, minutes, month, seconds, tz, year, _c_x10451_419, _ctx); /*std/time/instant/instant*/
  return kk_std_time_instant__instant_box(_x_x1465, _ctx);
}

kk_std_time_instant__instant kk_std_time_calendar_utc_fs_instant(kk_integer_t year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? int, frac : ? float64, tz : ? timezone, cal : ? calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 
  kk_std_time_instant__timescale x_10491;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x401 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3195 = kk_std_time_instant__timescale_unbox(_box_x401, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3195, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10491 = _uniq_ts_3195; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10494 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x1461;
    {
      struct kk_std_core_hnd_Ev* _con_x1462 = kk_std_core_hnd__as_Ev(ev_10494, _ctx);
      kk_box_t _box_x402 = _con_x1462->hnd;
      int32_t m = _con_x1462->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x402, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x762;
      kk_std_core_hnd__clause0 _brw_x763 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x762 = _brw_x763; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x405 = _match_x762.clause;
        _x_x1461 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x405, (_fun_unbox_x405, m, ev_10494, _ctx), _ctx); /*10005*/
      }
    }
    x_10491 = kk_std_time_instant__timescale_unbox(_x_x1461, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10491, (KK_I32(10)), _ctx);
    kk_box_t _x_x1463 = kk_std_core_hnd_yield_extend(kk_std_time_calendar_utc_fs_new_instant_fun1464(cal, day, frac, hours, minutes, month, seconds, tz, year, _ctx), _ctx); /*10001*/
    return kk_std_time_instant__instant_unbox(_x_x1463, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/time/utc/utc>*/;
    kk_std_num_ddouble__ddouble fsecs;
    kk_std_num_ddouble__ddouble _x_x1466;
    kk_integer_t _x_x1467;
    if (kk_std_core_types__is_Optional(seconds, _ctx)) {
      kk_box_t _box_x410 = seconds._cons._Optional.value;
      kk_integer_t _uniq_seconds_3176 = kk_integer_unbox(_box_x410, _ctx);
      kk_integer_dup(_uniq_seconds_3176, _ctx);
      kk_std_core_types__optional_drop(seconds, _ctx);
      _x_x1467 = _uniq_seconds_3176; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(seconds, _ctx);
      _x_x1467 = kk_integer_from_small(0); /*int*/
    }
    _x_x1466 = kk_std_num_ddouble_ddouble_int_exp(_x_x1467, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1468;
    double _x_x1469;
    if (kk_std_core_types__is_Optional(frac, _ctx)) {
      kk_box_t _box_x411 = frac._cons._Optional.value;
      double _uniq_frac_3180 = kk_double_unbox(_box_x411, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x1469 = _uniq_frac_3180; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac, _ctx);
      _x_x1469 = 0x0p+0; /*float64*/
    }
    _x_x1468 = kk_std_num_ddouble__new_Ddouble(_x_x1469, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    fsecs = kk_std_num_ddouble__lp__plus__rp_(_x_x1466, _x_x1468, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_instant__instant x_0;
    kk_std_time_calendar__calendar _match_x761;
    if (kk_std_core_types__is_Optional(cal, _ctx)) {
      kk_box_t _box_x412 = cal._cons._Optional.value;
      kk_std_time_calendar__calendar _uniq_cal_3188 = kk_std_time_calendar__calendar_unbox(_box_x412, KK_BORROWED, _ctx);
      kk_std_time_calendar__calendar_dup(_uniq_cal_3188, _ctx);
      kk_std_core_types__optional_drop(cal, _ctx);
      _match_x761 = _uniq_cal_3188; /*std/time/calendar/calendar*/
    }
    else {
      kk_std_core_types__optional_drop(cal, _ctx);
      _match_x761 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
    }
    {
      struct kk_std_time_calendar_Calendar* _con_x1470 = kk_std_time_calendar__as_Calendar(_match_x761, _ctx);
      kk_string_t _pat_0_1 = _con_x1470->name;
      kk_string_t _pat_1_1 = _con_x1470->long_name;
      kk_string_t _pat_2_0 = _con_x1470->month_prefix;
      kk_function_t _pat_3_0 = _con_x1470->show_era;
      kk_function_t _pat_4 = _con_x1470->instant_to_dc;
      kk_function_t _x = _con_x1470->dc_to_instant;
      kk_function_t _pat_5 = _con_x1470->days_to_date;
      kk_function_t _pat_6 = _con_x1470->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_match_x761, _ctx)) {
        kk_function_drop(_pat_6, _ctx);
        kk_function_drop(_pat_5, _ctx);
        kk_function_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3_0, _ctx);
        kk_string_drop(_pat_2_0, _ctx);
        kk_string_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_match_x761, _ctx);
      }
      else {
        kk_function_dup(_x, _ctx);
        kk_datatype_ptr_decref(_match_x761, _ctx);
      }
      kk_std_time_date__date _x_x1471;
      kk_integer_t _x_x1472;
      if (kk_std_core_types__is_Optional(month, _ctx)) {
        kk_box_t _box_x413 = month._cons._Optional.value;
        kk_integer_t _uniq_month_3160 = kk_integer_unbox(_box_x413, _ctx);
        kk_integer_dup(_uniq_month_3160, _ctx);
        kk_std_core_types__optional_drop(month, _ctx);
        _x_x1472 = _uniq_month_3160; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(month, _ctx);
        _x_x1472 = kk_integer_from_small(1); /*int*/
      }
      kk_integer_t _x_x1473;
      if (kk_std_core_types__is_Optional(day, _ctx)) {
        kk_box_t _box_x414 = day._cons._Optional.value;
        kk_integer_t _uniq_day_3164 = kk_integer_unbox(_box_x414, _ctx);
        kk_integer_dup(_uniq_day_3164, _ctx);
        kk_std_core_types__optional_drop(day, _ctx);
        _x_x1473 = _uniq_day_3164; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(day, _ctx);
        _x_x1473 = kk_integer_from_small(1); /*int*/
      }
      _x_x1471 = kk_std_time_date__new_Date(year, _x_x1472, _x_x1473, _ctx); /*std/time/date/date*/
      kk_std_time_date__clock _x_x1474;
      kk_integer_t _x_x1475;
      if (kk_std_core_types__is_Optional(hours, _ctx)) {
        kk_box_t _box_x415 = hours._cons._Optional.value;
        kk_integer_t _uniq_hours_3168 = kk_integer_unbox(_box_x415, _ctx);
        kk_integer_dup(_uniq_hours_3168, _ctx);
        kk_std_core_types__optional_drop(hours, _ctx);
        _x_x1475 = _uniq_hours_3168; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(hours, _ctx);
        _x_x1475 = kk_integer_from_small(0); /*int*/
      }
      kk_integer_t _x_x1476;
      if (kk_std_core_types__is_Optional(minutes, _ctx)) {
        kk_box_t _box_x416 = minutes._cons._Optional.value;
        kk_integer_t _uniq_minutes_3172 = kk_integer_unbox(_box_x416, _ctx);
        kk_integer_dup(_uniq_minutes_3172, _ctx);
        kk_std_core_types__optional_drop(minutes, _ctx);
        _x_x1476 = _uniq_minutes_3172; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(minutes, _ctx);
        _x_x1476 = kk_integer_from_small(0); /*int*/
      }
      _x_x1474 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x1475, _x_x1476, fsecs, _ctx); /*std/time/date/clock*/
      kk_std_time_calendar__timezone _x_x1477;
      if (kk_std_core_types__is_Optional(tz, _ctx)) {
        kk_box_t _box_x417 = tz._cons._Optional.value;
        kk_std_time_calendar__timezone _uniq_tz_3184 = kk_std_time_calendar__timezone_unbox(_box_x417, KK_BORROWED, _ctx);
        kk_std_time_calendar__timezone_dup(_uniq_tz_3184, _ctx);
        kk_std_core_types__optional_drop(tz, _ctx);
        _x_x1477 = _uniq_tz_3184; /*std/time/calendar/timezone*/
      }
      else {
        kk_std_core_types__optional_drop(tz, _ctx);
        _x_x1477 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
      }
      x_0 = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, _x_x1471, _x_x1474, _x_x1477, x_10491, _ctx), _ctx); /*std/time/instant/instant*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x_0;
  }
}
 
// monadic lift

kk_std_time_instant__instant kk_std_time_calendar_utcdate_fs__mlift_instant_10487(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10453, kk_context_t* _ctx) { /* (c : ? std/time/date/clock, cal : ? calendar, d : std/time/date/date, tz : ? timezone, std/time/instant/timescale) -> std/time/instant/instant */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/time/utc/utc>*/;
  kk_std_time_instant__instant x;
  kk_std_time_calendar__calendar _match_x759;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x420 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3288 = kk_std_time_calendar__calendar_unbox(_box_x420, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3288, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x759 = _uniq_cal_3288; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _match_x759 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1478 = kk_std_time_calendar__as_Calendar(_match_x759, _ctx);
    kk_string_t _pat_0 = _con_x1478->name;
    kk_string_t _pat_1 = _con_x1478->long_name;
    kk_string_t _pat_2 = _con_x1478->month_prefix;
    kk_function_t _pat_3 = _con_x1478->show_era;
    kk_function_t _pat_4 = _con_x1478->instant_to_dc;
    kk_function_t _x = _con_x1478->dc_to_instant;
    kk_function_t _pat_5_0 = _con_x1478->days_to_date;
    kk_function_t _pat_6_0 = _con_x1478->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x759, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_0, _ctx);
      kk_function_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_string_drop(_pat_2, _ctx);
      kk_string_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x759, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x759, _ctx);
    }
    kk_std_time_date__clock _x_x1479;
    if (kk_std_core_types__is_Optional(c, _ctx)) {
      kk_box_t _box_x421 = c._cons._Optional.value;
      kk_std_time_date__clock _uniq_c_3280 = kk_std_time_date__clock_unbox(_box_x421, KK_BORROWED, _ctx);
      kk_std_time_date__clock_dup(_uniq_c_3280, _ctx);
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1479 = _uniq_c_3280; /*std/time/date/clock*/
    }
    else {
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1479 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    }
    kk_std_time_calendar__timezone _x_x1480;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x422 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3284 = kk_std_time_calendar__timezone_unbox(_box_x422, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3284, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1480 = _uniq_tz_3284; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1480 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    x = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x1479, _x_x1480, _c_x10453, _ctx), _ctx); /*std/time/instant/instant*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}


// lift anonymous function
struct kk_std_time_calendar_utcdate_fs_instant_fun1484__t {
  struct kk_function_s _base;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_calendar_utcdate_fs_instant_fun1484(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_utcdate_fs_new_instant_fun1484(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs_instant_fun1484__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_utcdate_fs_instant_fun1484__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_utcdate_fs_instant_fun1484, kk_context());
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendar_utcdate_fs_instant_fun1484(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx) {
  struct kk_std_time_calendar_utcdate_fs_instant_fun1484__t* _self = kk_function_as(struct kk_std_time_calendar_utcdate_fs_instant_fun1484__t*, _fself, _ctx);
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10453_436 = kk_std_time_instant__timescale_unbox(_b_x431, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x1485 = kk_std_time_calendar_utcdate_fs__mlift_instant_10487(c, cal, d, tz, _c_x10453_436, _ctx); /*std/time/instant/instant*/
  return kk_std_time_instant__instant_box(_x_x1485, _ctx);
}

kk_std_time_instant__instant kk_std_time_calendar_utcdate_fs_instant(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (d : std/time/date/date, c : ? std/time/date/clock, tz : ? timezone, cal : ? calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc std/time/instant/instant */ 
  kk_std_time_instant__timescale x_10498;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x423 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_3295 = kk_std_time_instant__timescale_unbox(_box_x423, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_3295, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10498 = _uniq_ts_3295; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10501 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x1481;
    {
      struct kk_std_core_hnd_Ev* _con_x1482 = kk_std_core_hnd__as_Ev(ev_10501, _ctx);
      kk_box_t _box_x424 = _con_x1482->hnd;
      int32_t m = _con_x1482->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x424, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x757;
      kk_std_core_hnd__clause0 _brw_x758 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x757 = _brw_x758; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x427 = _match_x757.clause;
        _x_x1481 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x427, (_fun_unbox_x427, m, ev_10501, _ctx), _ctx); /*10005*/
      }
    }
    x_10498 = kk_std_time_instant__timescale_unbox(_x_x1481, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10498, (KK_I32(10)), _ctx);
    kk_box_t _x_x1483 = kk_std_core_hnd_yield_extend(kk_std_time_calendar_utcdate_fs_new_instant_fun1484(c, cal, d, tz, _ctx), _ctx); /*10001*/
    return kk_std_time_instant__instant_unbox(_x_x1483, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/time/utc/utc>*/;
    kk_std_time_instant__instant x_0;
    kk_std_time_calendar__calendar _match_x756;
    if (kk_std_core_types__is_Optional(cal, _ctx)) {
      kk_box_t _box_x432 = cal._cons._Optional.value;
      kk_std_time_calendar__calendar _uniq_cal_3288 = kk_std_time_calendar__calendar_unbox(_box_x432, KK_BORROWED, _ctx);
      kk_std_time_calendar__calendar_dup(_uniq_cal_3288, _ctx);
      kk_std_core_types__optional_drop(cal, _ctx);
      _match_x756 = _uniq_cal_3288; /*std/time/calendar/calendar*/
    }
    else {
      kk_std_core_types__optional_drop(cal, _ctx);
      _match_x756 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
    }
    {
      struct kk_std_time_calendar_Calendar* _con_x1486 = kk_std_time_calendar__as_Calendar(_match_x756, _ctx);
      kk_string_t _pat_0_1 = _con_x1486->name;
      kk_string_t _pat_1_1 = _con_x1486->long_name;
      kk_string_t _pat_2_0 = _con_x1486->month_prefix;
      kk_function_t _pat_3_2 = _con_x1486->show_era;
      kk_function_t _pat_4 = _con_x1486->instant_to_dc;
      kk_function_t _x = _con_x1486->dc_to_instant;
      kk_function_t _pat_5_0 = _con_x1486->days_to_date;
      kk_function_t _pat_6_0 = _con_x1486->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_match_x756, _ctx)) {
        kk_function_drop(_pat_6_0, _ctx);
        kk_function_drop(_pat_5_0, _ctx);
        kk_function_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3_2, _ctx);
        kk_string_drop(_pat_2_0, _ctx);
        kk_string_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_match_x756, _ctx);
      }
      else {
        kk_function_dup(_x, _ctx);
        kk_datatype_ptr_decref(_match_x756, _ctx);
      }
      kk_std_time_date__clock _x_x1487;
      if (kk_std_core_types__is_Optional(c, _ctx)) {
        kk_box_t _box_x433 = c._cons._Optional.value;
        kk_std_time_date__clock _uniq_c_3280 = kk_std_time_date__clock_unbox(_box_x433, KK_BORROWED, _ctx);
        kk_std_time_date__clock_dup(_uniq_c_3280, _ctx);
        kk_std_core_types__optional_drop(c, _ctx);
        _x_x1487 = _uniq_c_3280; /*std/time/date/clock*/
      }
      else {
        kk_std_core_types__optional_drop(c, _ctx);
        _x_x1487 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
      }
      kk_std_time_calendar__timezone _x_x1488;
      if (kk_std_core_types__is_Optional(tz, _ctx)) {
        kk_box_t _box_x434 = tz._cons._Optional.value;
        kk_std_time_calendar__timezone _uniq_tz_3284 = kk_std_time_calendar__timezone_unbox(_box_x434, KK_BORROWED, _ctx);
        kk_std_time_calendar__timezone_dup(_uniq_tz_3284, _ctx);
        kk_std_core_types__optional_drop(tz, _ctx);
        _x_x1488 = _uniq_tz_3284; /*std/time/calendar/timezone*/
      }
      else {
        kk_std_core_types__optional_drop(tz, _ctx);
        _x_x1488 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
      }
      x_0 = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x1487, _x_x1488, x_10498, _ctx), _ctx); /*std/time/instant/instant*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x_0;
  }
}
 
// Convert an `:instant` to a `:date`, `:clock`, timezone delta and abbreviation,
// for a given timezone `tz` (=`tz-utc` by default) and calendar (=`cal-iso` by default).

kk_std_core_types__tuple4 kk_std_time_calendar_instant_dc(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? timezone, cal : ? calendar) -> (std/time/date/date, std/time/date/clock, std/time/duration/duration, string) */ 
  kk_std_time_calendar__timezone _match_x751;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x437 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3349 = kk_std_time_calendar__timezone_unbox(_box_x437, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3349, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _match_x751 = _uniq_tz_3349; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _match_x751 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1489 = kk_std_time_calendar__as_Timezone(_match_x751, _ctx);
    kk_string_t _pat_0 = _con_x1489->name;
    kk_function_t _x = _con_x1489->utc_delta;
    kk_function_t _pat_1 = _con_x1489->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x751, _ctx)) {
      kk_function_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x751, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x751, _ctx);
    }
    kk_std_core_types__tuple2 _match_x752;
    kk_std_time_instant__instant _x_x1490 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    _match_x752 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x, (_x, _x_x1490, _ctx), _ctx); /*(std/time/duration/duration, string)*/
    {
      kk_box_t _box_x438 = _match_x752.fst;
      kk_box_t _box_x439 = _match_x752.snd;
      kk_std_time_duration__duration tzdelta = kk_std_time_duration__duration_unbox(_box_x438, KK_BORROWED, _ctx);
      kk_string_t tzabbrv = kk_string_unbox(_box_x439);
      kk_string_dup(tzabbrv, _ctx);
      kk_std_core_types__tuple2_drop(_match_x752, _ctx);
      kk_std_time_calendar__calendar _match_x753;
      if (kk_std_core_types__is_Optional(cal, _ctx)) {
        kk_box_t _box_x440 = cal._cons._Optional.value;
        kk_std_time_calendar__calendar _uniq_cal_3353 = kk_std_time_calendar__calendar_unbox(_box_x440, KK_BORROWED, _ctx);
        kk_std_time_calendar__calendar_dup(_uniq_cal_3353, _ctx);
        kk_std_core_types__optional_drop(cal, _ctx);
        _match_x753 = _uniq_cal_3353; /*std/time/calendar/calendar*/
      }
      else {
        kk_std_core_types__optional_drop(cal, _ctx);
        _match_x753 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
      }
      {
        struct kk_std_time_calendar_Calendar* _con_x1491 = kk_std_time_calendar__as_Calendar(_match_x753, _ctx);
        kk_string_t _pat_0_1 = _con_x1491->name;
        kk_string_t _pat_1_0 = _con_x1491->long_name;
        kk_string_t _pat_2_0 = _con_x1491->month_prefix;
        kk_function_t _pat_3_0 = _con_x1491->show_era;
        kk_function_t _x_0 = _con_x1491->instant_to_dc;
        kk_function_t _pat_4_0 = _con_x1491->dc_to_instant;
        kk_function_t _pat_5_0 = _con_x1491->days_to_date;
        kk_function_t _pat_6 = _con_x1491->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_match_x753, _ctx)) {
          kk_function_drop(_pat_6, _ctx);
          kk_function_drop(_pat_5_0, _ctx);
          kk_function_drop(_pat_4_0, _ctx);
          kk_function_drop(_pat_3_0, _ctx);
          kk_string_drop(_pat_2_0, _ctx);
          kk_string_drop(_pat_1_0, _ctx);
          kk_string_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(_match_x753, _ctx);
        }
        else {
          kk_function_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(_match_x753, _ctx);
        }
        kk_std_core_types__tuple2 _match_x754 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_std_time_duration__duration, kk_context_t*), _x_0, (_x_0, i, tzdelta, _ctx), _ctx); /*(std/time/date/date, std/time/date/clock)*/;
        {
          kk_box_t _box_x441 = _match_x754.fst;
          kk_box_t _box_x442 = _match_x754.snd;
          kk_std_time_date__date d = kk_std_time_date__date_unbox(_box_x441, KK_BORROWED, _ctx);
          kk_std_time_date__clock c = kk_std_time_date__clock_unbox(_box_x442, KK_BORROWED, _ctx);
          struct kk_std_time_date_Clock* _con_x1492 = kk_std_time_date__as_Clock(c, _ctx);
          kk_std_time_date__clock_dup(c, _ctx);
          kk_std_time_date__date_dup(d, _ctx);
          kk_std_core_types__tuple2_drop(_match_x754, _ctx);
          return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_time_date__date_box(d, _ctx), kk_std_time_date__clock_box(c, _ctx), kk_std_time_duration__duration_box(tzdelta, _ctx), kk_string_box(tzabbrv), _ctx);
        }
      }
    }
  }
}
 
// Return the day of the week for a calendar `cal` (=`cal-iso`).

kk_std_time_date__weekday kk_std_time_calendar_weekday(kk_std_time_date__date d, kk_std_time_calendar__calendar cal, kk_context_t* _ctx) { /* (d : std/time/date/date, cal : calendar) -> std/time/date/weekday */ 
  kk_integer_t x_10223;
  {
    struct kk_std_time_calendar_Calendar* _con_x1493 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1493->name;
    kk_string_t _pat_1 = _con_x1493->long_name;
    kk_string_t _pat_2 = _con_x1493->month_prefix;
    kk_function_t _pat_3 = _con_x1493->show_era;
    kk_function_t _pat_4 = _con_x1493->instant_to_dc;
    kk_function_t _pat_5 = _con_x1493->dc_to_instant;
    kk_function_t _pat_6 = _con_x1493->days_to_date;
    kk_function_t _x = _con_x1493->date_to_days;
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
    x_10223 = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, d, _ctx), _ctx); /*int*/
  }
  kk_integer_t dow;
  kk_integer_t _x_x1494 = kk_integer_add_small_const(x_10223, 6, _ctx); /*int*/
  dow = kk_integer_mod(_x_x1494,(kk_integer_from_small(7)),kk_context()); /*int*/
  return kk_std_time_date_weekday(dow, _ctx);
}
 
// Return the days between two dates interpreted by calendar `cal`.

kk_integer_t kk_std_time_calendar_days_until(kk_std_time_calendar__calendar cal, kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx) { /* (cal : calendar, d1 : std/time/date/date, d2 : std/time/date/date) -> int */ 
  kk_integer_t x;
  {
    struct kk_std_time_calendar_Calendar* _con_x1495 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_function_t _x_0 = _con_x1495->date_to_days;
    kk_function_dup(_x_0, _ctx);
    x = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_0, (_x_0, d2, _ctx), _ctx); /*int*/
  }
  kk_integer_t y;
  {
    struct kk_std_time_calendar_Calendar* _con_x1496 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1496->name;
    kk_string_t _pat_1 = _con_x1496->long_name;
    kk_string_t _pat_2 = _con_x1496->month_prefix;
    kk_function_t _pat_3 = _con_x1496->show_era;
    kk_function_t _pat_4 = _con_x1496->instant_to_dc;
    kk_function_t _pat_5 = _con_x1496->dc_to_instant;
    kk_function_t _pat_6 = _con_x1496->days_to_date;
    kk_function_t _x = _con_x1496->date_to_days;
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
  kk_function_t _x_x1497;
  {
    struct kk_std_time_calendar_Calendar* _con_x1498 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0 = _con_x1498->name;
    kk_string_t _pat_1 = _con_x1498->long_name;
    kk_string_t _pat_2 = _con_x1498->month_prefix;
    kk_function_t _pat_3 = _con_x1498->show_era;
    kk_function_t _pat_4 = _con_x1498->instant_to_dc;
    kk_function_t _pat_5 = _con_x1498->dc_to_instant;
    kk_function_t _pat_6 = _con_x1498->days_to_date;
    kk_function_t _x = _con_x1498->date_to_days;
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
    _x_x1497 = _x; /*(date : std/time/date/date) -> int*/
  }
  kk_std_core_types__optional _x_x1499;
  kk_box_t _x_x1500;
  bool _x_x1501;
  {
    struct kk_std_time_instant_Timescale* _con_x1502 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _pat_0_0 = _con_x1502->name;
    kk_string_t _pat_1_0 = _con_x1502->unit;
    kk_function_t _pat_2_0_0 = _con_x1502->from_tai;
    kk_function_t _pat_3_0 = _con_x1502->to_tai;
    kk_std_core_types__maybe _x_0 = _con_x1502->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_0 = _con_x1502->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_0 = _con_x1502->mb_from_mjd2000;
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
      _x_x1501 = true; /*bool*/
    }
    else {
      _x_x1501 = false; /*bool*/
    }
  }
  _x_x1500 = kk_bool_box(_x_x1501); /*10003*/
  _x_x1499 = kk_std_core_types__new_Optional(_x_x1500, _ctx); /*? 10003*/
  return kk_std_time_calendar_dc_timestamp(d, c, _x_x1497, _x_x1499, _ctx);
}
 
// Create a new calendar from by combining two other calendars. The `switch-date`
// is in terms of the second calendar (`cal2`) and time after (and including) the switch
// date is displayed in `cal2` while times before it in `cal1`. This function is used
// for example for the Julian Gregorian calendar.


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1503__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal1;
  kk_std_time_calendar__calendar cal2;
  kk_std_time_date__date switch_date;
};
static kk_std_time_date__date kk_std_time_calendar_combine_earth_calendars_fun1503(kk_function_t _fself, kk_integer_t days_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1503(kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_time_date__date switch_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1503__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1503__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1503, kk_context());
  _self->cal1 = cal1;
  _self->cal2 = cal2;
  _self->switch_date = switch_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_combine_earth_calendars_fun1503(kk_function_t _fself, kk_integer_t days_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1503__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1503__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal1 = _self->cal1; /* std/time/calendar/calendar */
  kk_std_time_calendar__calendar cal2 = _self->cal2; /* std/time/calendar/calendar */
  kk_std_time_date__date switch_date = _self->switch_date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal1, _ctx);kk_std_time_calendar__calendar_dup(cal2, _ctx);kk_std_time_date__date_dup(switch_date, _ctx);}, {}, _ctx)
  kk_std_time_calendar__calendar calendar_0_10238;
  bool _match_x748;
  kk_integer_t _brw_x749;
  {
    struct kk_std_time_calendar_Calendar* _con_x1504 = kk_std_time_calendar__as_Calendar(cal2, _ctx);
    kk_function_t _x = _con_x1504->date_to_days;
    kk_function_dup(_x, _ctx);
    _brw_x749 = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, switch_date, _ctx), _ctx); /*int*/
  }
  bool _brw_x750 = kk_integer_lt_borrow(days_0,_brw_x749,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x749, _ctx);
  _match_x748 = _brw_x750; /*bool*/
  if (_match_x748) {
    kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
    calendar_0_10238 = cal1; /*std/time/calendar/calendar*/
  }
  else {
    kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
    calendar_0_10238 = cal2; /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1505 = kk_std_time_calendar__as_Calendar(calendar_0_10238, _ctx);
    kk_string_t _pat_0_6 = _con_x1505->name;
    kk_string_t _pat_1_6 = _con_x1505->long_name;
    kk_string_t _pat_2_5 = _con_x1505->month_prefix;
    kk_function_t _pat_3_3 = _con_x1505->show_era;
    kk_function_t _pat_4_2 = _con_x1505->instant_to_dc;
    kk_function_t _pat_5_2 = _con_x1505->dc_to_instant;
    kk_function_t _x_4 = _con_x1505->days_to_date;
    kk_function_t _pat_6_1 = _con_x1505->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(calendar_0_10238, _ctx)) {
      kk_function_drop(_pat_6_1, _ctx);
      kk_function_drop(_pat_5_2, _ctx);
      kk_function_drop(_pat_4_2, _ctx);
      kk_function_drop(_pat_3_3, _ctx);
      kk_string_drop(_pat_2_5, _ctx);
      kk_string_drop(_pat_1_6, _ctx);
      kk_string_drop(_pat_0_6, _ctx);
      kk_datatype_ptr_free(calendar_0_10238, _ctx);
    }
    else {
      kk_function_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(calendar_0_10238, _ctx);
    }
    return kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), _x_4, (_x_4, days_0, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1506__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal1;
  kk_std_time_calendar__calendar cal2;
  kk_std_time_date__date switch_date;
};
static kk_integer_t kk_std_time_calendar_combine_earth_calendars_fun1506(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1506(kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_time_date__date switch_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1506__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1506__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1506, kk_context());
  _self->cal1 = cal1;
  _self->cal2 = cal2;
  _self->switch_date = switch_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_combine_earth_calendars_fun1506(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1506__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1506__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal1 = _self->cal1; /* std/time/calendar/calendar */
  kk_std_time_calendar__calendar cal2 = _self->cal2; /* std/time/calendar/calendar */
  kk_std_time_date__date switch_date = _self->switch_date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal1, _ctx);kk_std_time_calendar__calendar_dup(cal2, _ctx);kk_std_time_date__date_dup(switch_date, _ctx);}, {}, _ctx)
  kk_std_core_types__order x_10067;
  kk_std_time_date__date _x_x1507 = kk_std_time_date__date_dup(d_1, _ctx); /*std/time/date/date*/
  x_10067 = kk_std_time_date_cmp(_x_x1507, switch_date, _ctx); /*order*/
  kk_std_time_calendar__calendar calendar_1_10240;
  bool _match_x745;
  kk_integer_t _brw_x746;
  if (kk_std_core_types__is_Lt(x_10067, _ctx)) {
    _brw_x746 = kk_integer_from_small(-1); /*int*/
    goto _match_x1508;
  }
  if (kk_std_core_types__is_Eq(x_10067, _ctx)) {
    _brw_x746 = kk_integer_from_small(0); /*int*/
    goto _match_x1508;
  }
  {
    _brw_x746 = kk_integer_from_small(1); /*int*/
  }
  _match_x1508: ;
  bool _brw_x747 = kk_integer_eq_borrow(_brw_x746,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x746, _ctx);
  _match_x745 = _brw_x747; /*bool*/
  if (_match_x745) {
    kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
    calendar_1_10240 = cal1; /*std/time/calendar/calendar*/
  }
  else {
    kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
    calendar_1_10240 = cal2; /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1509 = kk_std_time_calendar__as_Calendar(calendar_1_10240, _ctx);
    kk_string_t _pat_0_7 = _con_x1509->name;
    kk_string_t _pat_1_8 = _con_x1509->long_name;
    kk_string_t _pat_2_7 = _con_x1509->month_prefix;
    kk_function_t _pat_3_4 = _con_x1509->show_era;
    kk_function_t _pat_4_3 = _con_x1509->instant_to_dc;
    kk_function_t _pat_5_3 = _con_x1509->dc_to_instant;
    kk_function_t _pat_6_2 = _con_x1509->days_to_date;
    kk_function_t _x_5 = _con_x1509->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(calendar_1_10240, _ctx)) {
      kk_function_drop(_pat_6_2, _ctx);
      kk_function_drop(_pat_5_3, _ctx);
      kk_function_drop(_pat_4_3, _ctx);
      kk_function_drop(_pat_3_4, _ctx);
      kk_string_drop(_pat_2_7, _ctx);
      kk_string_drop(_pat_1_8, _ctx);
      kk_string_drop(_pat_0_7, _ctx);
      kk_datatype_ptr_free(calendar_1_10240, _ctx);
    }
    else {
      kk_function_dup(_x_5, _ctx);
      kk_datatype_ptr_decref(calendar_1_10240, _ctx);
    }
    return kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_5, (_x_5, d_1, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1512__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal1;
  kk_std_time_calendar__calendar cal2;
  kk_std_core_types__optional mb_show_era;
  kk_std_time_date__date switch_date;
};
static kk_string_t kk_std_time_calendar_combine_earth_calendars_fun1512(kk_function_t _fself, kk_std_time_date__date d_0_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1512(kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_core_types__optional mb_show_era, kk_std_time_date__date switch_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1512__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1512__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1512, kk_context());
  _self->cal1 = cal1;
  _self->cal2 = cal2;
  _self->mb_show_era = mb_show_era;
  _self->switch_date = switch_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_combine_earth_calendars_fun1512(kk_function_t _fself, kk_std_time_date__date d_0_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1512__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1512__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal1 = _self->cal1; /* std/time/calendar/calendar */
  kk_std_time_calendar__calendar cal2 = _self->cal2; /* std/time/calendar/calendar */
  kk_std_core_types__optional mb_show_era = _self->mb_show_era; /* ? (maybe<(std/time/date/date) -> string>) */
  kk_std_time_date__date switch_date = _self->switch_date; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal1, _ctx);kk_std_time_calendar__calendar_dup(cal2, _ctx);kk_std_core_types__optional_dup(mb_show_era, _ctx);kk_std_time_date__date_dup(switch_date, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x740;
  if (kk_std_core_types__is_Optional(mb_show_era, _ctx)) {
    kk_box_t _box_x461 = mb_show_era._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_show_era_3498 = kk_std_core_types__maybe_unbox(_box_x461, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_show_era_3498, _ctx);
    kk_std_core_types__optional_drop(mb_show_era, _ctx);
    _match_x740 = _uniq_mb_show_era_3498; /*maybe<(std/time/date/date) -> string>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_show_era, _ctx);
    _match_x740 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/date/date) -> string>*/
  }
  if (kk_std_core_types__is_Just(_match_x740, _ctx)) {
    kk_box_t _fun_unbox_x465 = _match_x740._cons.Just.value;
    kk_std_time_date__date_drop(switch_date, _ctx);
    kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
    kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
    kk_box_t _x_x1513;
    kk_function_t _x_x1514 = kk_function_unbox(_fun_unbox_x465, _ctx); /*(466) -> 467*/
    _x_x1513 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1514, (_x_x1514, kk_std_time_date__date_box(d_0_1, _ctx), _ctx), _ctx); /*467*/
    return kk_string_unbox(_x_x1513);
  }
  {
    kk_std_core_types__order x_10067_0;
    kk_std_time_date__date _x_x1515 = kk_std_time_date__date_dup(d_0_1, _ctx); /*std/time/date/date*/
    x_10067_0 = kk_std_time_date_cmp(_x_x1515, switch_date, _ctx); /*order*/
    kk_std_time_calendar__calendar calendar_2_10243;
    bool _match_x741;
    kk_integer_t _brw_x742;
    if (kk_std_core_types__is_Lt(x_10067_0, _ctx)) {
      _brw_x742 = kk_integer_from_small(-1); /*int*/
      goto _match_x1516;
    }
    if (kk_std_core_types__is_Eq(x_10067_0, _ctx)) {
      _brw_x742 = kk_integer_from_small(0); /*int*/
      goto _match_x1516;
    }
    {
      _brw_x742 = kk_integer_from_small(1); /*int*/
    }
    _match_x1516: ;
    bool _brw_x743 = kk_integer_eq_borrow(_brw_x742,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x742, _ctx);
    _match_x741 = _brw_x743; /*bool*/
    if (_match_x741) {
      kk_datatype_ptr_dropn(cal2, (KK_I32(8)), _ctx);
      calendar_2_10243 = cal1; /*std/time/calendar/calendar*/
    }
    else {
      kk_datatype_ptr_dropn(cal1, (KK_I32(8)), _ctx);
      calendar_2_10243 = cal2; /*std/time/calendar/calendar*/
    }
    {
      struct kk_std_time_calendar_Calendar* _con_x1517 = kk_std_time_calendar__as_Calendar(calendar_2_10243, _ctx);
      kk_string_t _pat_0_10 = _con_x1517->name;
      kk_string_t _pat_1_10 = _con_x1517->long_name;
      kk_string_t _pat_2_8 = _con_x1517->month_prefix;
      kk_function_t _x_6 = _con_x1517->show_era;
      kk_function_t _pat_3_6 = _con_x1517->instant_to_dc;
      kk_function_t _pat_4_5 = _con_x1517->dc_to_instant;
      kk_function_t _pat_5_5 = _con_x1517->days_to_date;
      kk_function_t _pat_6_4 = _con_x1517->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(calendar_2_10243, _ctx)) {
        kk_function_drop(_pat_6_4, _ctx);
        kk_function_drop(_pat_5_5, _ctx);
        kk_function_drop(_pat_4_5, _ctx);
        kk_function_drop(_pat_3_6, _ctx);
        kk_string_drop(_pat_2_8, _ctx);
        kk_string_drop(_pat_1_10, _ctx);
        kk_string_drop(_pat_0_10, _ctx);
        kk_datatype_ptr_free(calendar_2_10243, _ctx);
      }
      else {
        kk_function_dup(_x_6, _ctx);
        kk_datatype_ptr_decref(calendar_2_10243, _ctx);
      }
      return kk_function_call(kk_string_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_6, (_x_6, d_0_1, _ctx), _ctx);
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1519__t {
  struct kk_function_s _base;
  kk_function_t days_to_date;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_combine_earth_calendars_fun1519(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1519(kk_function_t days_to_date, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1519__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1519__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1519, kk_context());
  _self->days_to_date = days_to_date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_combine_earth_calendars_fun1519(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1519__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1519__t*, _fself, _ctx);
  kk_function_t days_to_date = _self->days_to_date; /* (days : int) -> std/time/date/date */
  kk_drop_match(_self, {kk_function_dup(days_to_date, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _match_x739;
  kk_std_time_timestamp__timestamp _x_x1520;
  kk_std_num_ddouble__ddouble _x_x1521;
  kk_std_num_ddouble__ddouble _x_x1522;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_3 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1523 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1524 = kk_std_time_instant__as_Timescale(_pat_2_3, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1525 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x_0 = _con_x1525->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1522 = _x_0; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1526;
  {
    kk_std_num_ddouble__ddouble _x_2 = tzdelta.secs;
    _x_x1526 = _x_2; /*std/time/timestamp/timespan*/
  }
  _x_x1521 = kk_std_num_ddouble__lp__plus__rp_(_x_x1522, _x_x1526, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1527;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_3_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1528 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1529 = kk_std_time_instant__as_Timescale(_pat_2_3_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1530 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1530->since;
      int32_t _x_0_0 = _con_x1530->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1527 = _x_0_0; /*int32*/
    }
  }
  _x_x1520 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1521, _x_x1527, _ctx); /*std/time/timestamp/timestamp*/
  _match_x739 = kk_std_time_timestamp_days_clock(_x_x1520, _ctx); /*(int, std/time/date/clock)*/
  {
    kk_box_t _box_x469 = _match_x739.fst;
    kk_box_t _box_x470 = _match_x739.snd;
    kk_std_time_date__clock clock = kk_std_time_date__clock_unbox(_box_x470, KK_BORROWED, _ctx);
    struct kk_std_time_date_Clock* _con_x1531 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_integer_t days = kk_integer_unbox(_box_x469, _ctx);
    kk_std_time_date__clock_dup(clock, _ctx);
    kk_integer_dup(days, _ctx);
    kk_std_core_types__tuple2_drop(_match_x739, _ctx);
    kk_std_time_date__date _b_x471_495 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date, (days_to_date, days, _ctx), _ctx); /*std/time/date/date*/;
    return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x471_495, _ctx), kk_std_time_date__clock_box(clock, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_combine_earth_calendars_fun1533__t {
  struct kk_function_s _base;
  kk_function_t date_to_days;
};
static kk_std_time_instant__instant kk_std_time_calendar_combine_earth_calendars_fun1533(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_combine_earth_calendars_fun1533(kk_function_t date_to_days, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1533__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_combine_earth_calendars_fun1533__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_combine_earth_calendars_fun1533, kk_context());
  _self->date_to_days = date_to_days;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_combine_earth_calendars_fun1533(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_combine_earth_calendars_fun1533__t* _self = kk_function_as(struct kk_std_time_calendar_combine_earth_calendars_fun1533__t*, _fself, _ctx);
  kk_function_t date_to_days = _self->date_to_days; /* (std/time/date/date) -> int */
  kk_drop_match(_self, {kk_function_dup(date_to_days, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_10314;
  kk_std_core_types__optional _x_x1534;
  kk_box_t _x_x1535;
  bool _x_x1536;
  {
    struct kk_std_time_instant_Timescale* _con_x1537 = kk_std_time_instant__as_Timescale(ts_0, _ctx);
    kk_std_core_types__maybe _x_3_1 = _con_x1537->mb_seconds_in_day;
    kk_std_core_types__maybe_dup(_x_3_1, _ctx);
    if (kk_std_core_types__is_Just(_x_3_1, _ctx)) {
      kk_std_core_types__maybe_drop(_x_3_1, _ctx);
      _x_x1536 = true; /*bool*/
    }
    else {
      _x_x1536 = false; /*bool*/
    }
  }
  _x_x1535 = kk_bool_box(_x_x1536); /*10003*/
  _x_x1534 = kk_std_core_types__new_Optional(_x_x1535, _ctx); /*? 10003*/
  t_10314 = kk_std_time_calendar_dc_timestamp(d_0_0, c, date_to_days, _x_x1534, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__instant i_0;
  kk_std_time_timestamp__timestamp _x_x1538 = kk_std_time_timestamp__timestamp_dup(t_10314, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1539 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
  i_0 = kk_std_time_instant__new_Instant(_x_x1538, _x_x1539, _ctx); /*std/time/instant/instant*/
  bool _match_x736;
  kk_string_t _x_x1540;
  {
    struct kk_std_time_calendar_Timezone* _con_x1541 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x_3 = _con_x1541->name;
    kk_string_dup(_x_3, _ctx);
    _x_x1540 = _x_3; /*string*/
  }
  kk_string_t _x_x1542;
  kk_std_time_calendar__timezone _x_x1543 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x1544 = kk_std_time_calendar__as_Timezone(_x_x1543, _ctx);
    kk_string_t _x_0_1 = _con_x1544->name;
    _x_x1542 = kk_string_dup(_x_0_1, _ctx); /*string*/
  }
  _match_x736 = kk_string_is_eq(_x_x1540,_x_x1542,kk_context()); /*bool*/
  if (_match_x736) {
    kk_datatype_ptr_dropn(tz, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
    kk_std_time_timestamp__timestamp_drop(t_10314, _ctx);
    return i_0;
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1545 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _pat_0_2_0 = _con_x1545->name;
    kk_function_t _pat_1_1_0 = _con_x1545->utc_delta;
    kk_function_t _x_1_0_0 = _con_x1545->utc_inverse;
    kk_function_dup(_x_1_0_0, _ctx);
    kk_std_core_types__maybe _match_x737;
    kk_std_time_instant__instant _x_x1546 = kk_std_time_instant__instant_dup(i_0, _ctx); /*std/time/instant/instant*/
    _match_x737 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_1_0_0, (_x_1_0_0, _x_x1546, _ctx), _ctx); /*maybe<std/time/instant/instant>*/
    if (kk_std_core_types__is_Just(_match_x737, _ctx)) {
      kk_box_t _box_x482 = _match_x737._cons.Just.value;
      kk_std_time_instant__instant inv = kk_std_time_instant__instant_unbox(_box_x482, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
        kk_function_drop(_x_1_0_0, _ctx);
        kk_function_drop(_pat_1_1_0, _ctx);
        kk_string_drop(_pat_0_2_0, _ctx);
        kk_datatype_ptr_free(tz, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tz, _ctx);
      }
      kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
      kk_std_time_timestamp__timestamp_drop(t_10314, _ctx);
      kk_std_time_instant__instant_drop(i_0, _ctx);
      kk_std_time_instant__instant_dup(inv, _ctx);
      kk_std_core_types__maybe_drop(_match_x737, _ctx);
      return inv;
    }
    {
      kk_std_core_types__tuple2 tuple2_10133;
      {
        struct kk_std_time_calendar_Timezone* _con_x1547 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_function_t _x_3_0 = _con_x1547->utc_delta;
        kk_function_dup(_x_3_0, _ctx);
        tuple2_10133 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_3_0, (_x_3_0, i_0, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      kk_std_time_timestamp__timestamp t_1_10136;
      kk_std_num_ddouble__ddouble _x_x1548;
      kk_std_num_ddouble__ddouble _x_x1549;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1550 = kk_std_time_timestamp__as_Timestamp(t_10314, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0_0_0 = _con_x1550->since;
        _x_x1549 = _x_1_0_0_0; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1551;
      double _x_x1552;
      double _x_x1553;
      {
        kk_box_t _box_x483 = tuple2_10133.fst;
        kk_box_t _box_x484 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0 = kk_std_time_duration__duration_unbox(_box_x483, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0 = _x_2_0.secs;
          {
            double _x_4_0 = _x_5_0.hi;
            _x_x1553 = _x_4_0; /*float64*/
          }
        }
      }
      _x_x1552 = (-_x_x1553); /*float64*/
      double _x_x1554;
      double _x_x1555;
      {
        kk_box_t _box_x485 = tuple2_10133.fst;
        kk_box_t _box_x486 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_0 = kk_std_time_duration__duration_unbox(_box_x485, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0_0 = _x_2_0_0.secs;
          {
            double _x_0_0_0 = _x_5_0_0.lo;
            _x_x1555 = _x_0_0_0; /*float64*/
          }
        }
      }
      _x_x1554 = (-_x_x1555); /*float64*/
      _x_x1551 = kk_std_num_ddouble__new_Ddouble(_x_x1552, _x_x1554, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1548 = kk_std_num_ddouble__lp__plus__rp_(_x_x1549, _x_x1551, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1556;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1557 = kk_std_time_timestamp__as_Timestamp(t_10314, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_2_0_0 = _con_x1557->since;
        int32_t _x_2_0_0_0 = _con_x1557->leap32;
        _x_x1556 = _x_2_0_0_0; /*int32*/
      }
      t_1_10136 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1548, _x_x1556, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__instant tzi1;
      kk_std_time_instant__timescale _x_x1558 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
      tzi1 = kk_std_time_instant__new_Instant(t_1_10136, _x_x1558, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_0_10140;
      {
        struct kk_std_time_calendar_Timezone* _con_x1559 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_string_t _pat_0_8_0 = _con_x1559->name;
        kk_function_t _x_7 = _con_x1559->utc_delta;
        kk_function_t _pat_1_6_0 = _con_x1559->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
          kk_function_drop(_pat_1_6_0, _ctx);
          kk_string_drop(_pat_0_8_0, _ctx);
          kk_datatype_ptr_free(tz, _ctx);
        }
        else {
          kk_function_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(tz, _ctx);
        }
        kk_std_time_instant__instant _x_x1560 = kk_std_time_instant__instant_dup(tzi1, _ctx); /*std/time/instant/instant*/
        tuple2_0_10140 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_7, (_x_7, _x_x1560, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      bool _match_x738;
      kk_std_time_duration__duration _x_x1561;
      {
        kk_box_t _box_x487 = tuple2_10133.fst;
        kk_box_t _box_x488 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_1 = kk_std_time_duration__duration_unbox(_box_x487, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10133, _ctx);
        _x_x1561 = _x_2_0_1; /*std/time/duration/duration*/
      }
      kk_std_time_duration__duration _x_x1562;
      {
        kk_box_t _box_x489 = tuple2_0_10140.fst;
        kk_box_t _box_x490 = tuple2_0_10140.snd;
        kk_std_time_duration__duration _x_6_0 = kk_std_time_duration__duration_unbox(_box_x489, KK_BORROWED, _ctx);
        _x_x1562 = _x_6_0; /*std/time/duration/duration*/
      }
      _match_x738 = kk_std_time_duration__lp__eq__eq__rp_(_x_x1561, _x_x1562, _ctx); /*bool*/
      if (_match_x738) {
        kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
        kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
        kk_std_time_timestamp__timestamp_drop(t_10314, _ctx);
        return tzi1;
      }
      {
        kk_std_time_instant__instant_drop(tzi1, _ctx);
        kk_std_time_timestamp__timestamp t_3_10143;
        kk_std_num_ddouble__ddouble _x_x1563;
        kk_std_num_ddouble__ddouble _x_x1564;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1565 = kk_std_time_timestamp__as_Timestamp(t_10314, _ctx);
          kk_std_num_ddouble__ddouble _x_1_1 = _con_x1565->since;
          _x_x1564 = _x_1_1; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x1566;
        double _x_x1567;
        double _x_x1568;
        {
          kk_box_t _box_x491 = tuple2_0_10140.fst;
          kk_box_t _box_x492 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0_0 = kk_std_time_duration__duration_unbox(_box_x491, KK_BORROWED, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9 = _x_6_0_0.secs;
            {
              double _x_8 = _x_9.hi;
              _x_x1568 = _x_8; /*float64*/
            }
          }
        }
        _x_x1567 = (-_x_x1568); /*float64*/
        double _x_x1569;
        double _x_x1570;
        {
          kk_box_t _box_x493 = tuple2_0_10140.fst;
          kk_box_t _box_x494 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0_1 = kk_std_time_duration__duration_unbox(_box_x493, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0 = _x_6_0_1.secs;
            {
              double _x_0_1_0 = _x_9_0.lo;
              _x_x1570 = _x_0_1_0; /*float64*/
            }
          }
        }
        _x_x1569 = (-_x_x1570); /*float64*/
        _x_x1566 = kk_std_num_ddouble__new_Ddouble(_x_x1567, _x_x1569, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1563 = kk_std_num_ddouble__lp__plus__rp_(_x_x1564, _x_x1566, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x1571;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1572 = kk_std_time_timestamp__as_Timestamp(t_10314, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_2_1 = _con_x1572->since;
          int32_t _x_2_1 = _con_x1572->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(t_10314, _ctx)) {
            kk_datatype_ptr_free(t_10314, _ctx);
          }
          else {
            kk_datatype_ptr_decref(t_10314, _ctx);
          }
          _x_x1571 = _x_2_1; /*int32*/
        }
        t_3_10143 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1563, _x_x1571, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_instant__new_Instant(t_3_10143, ts_0, _ctx);
      }
    }
  }
}

kk_std_time_calendar__calendar kk_std_time_calendar_combine_earth_calendars(kk_string_t name, kk_string_t long_name, kk_std_time_date__date switch_date, kk_std_time_calendar__calendar cal1, kk_std_time_calendar__calendar cal2, kk_std_core_types__optional mb_show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, switch-date : std/time/date/date, cal1 : calendar, cal2 : calendar, mb-show-era : ? (maybe<(std/time/date/date) -> string>)) -> calendar */ 
  kk_function_t days_to_date;
  kk_std_time_calendar__calendar_dup(cal1, _ctx);
  kk_std_time_calendar__calendar_dup(cal2, _ctx);
  kk_std_time_date__date_dup(switch_date, _ctx);
  days_to_date = kk_std_time_calendar_new_combine_earth_calendars_fun1503(cal1, cal2, switch_date, _ctx); /*(days@0 : int) -> std/time/date/date*/
  kk_function_t date_to_days;
  kk_std_time_calendar__calendar_dup(cal1, _ctx);
  kk_std_time_calendar__calendar_dup(cal2, _ctx);
  kk_std_time_date__date_dup(switch_date, _ctx);
  date_to_days = kk_std_time_calendar_new_combine_earth_calendars_fun1506(cal1, cal2, switch_date, _ctx); /*(d@1 : std/time/date/date) -> int*/
  kk_string_t _x_x1510;
  kk_std_core_types__optional _match_x744 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x744, _ctx)) {
    kk_box_t _box_x460 = _match_x744._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2776 = kk_string_unbox(_box_x460);
    kk_string_dup(_uniq_month_prefix_2776, _ctx);
    kk_std_core_types__optional_drop(_match_x744, _ctx);
    _x_x1510 = _uniq_month_prefix_2776; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x744, _ctx);
    _x_x1510 = kk_string_empty(); /*string*/
  }
  kk_function_t _x_x1518;
  kk_function_dup(days_to_date, _ctx);
  _x_x1518 = kk_std_time_calendar_new_combine_earth_calendars_fun1519(days_to_date, _ctx); /*(i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (10037, 10038)*/
  kk_function_t _x_x1532;
  kk_function_dup(date_to_days, _ctx);
  _x_x1532 = kk_std_time_calendar_new_combine_earth_calendars_fun1533(date_to_days, _ctx); /*(d@0@0 : std/time/date/date, c : std/time/date/clock, tz : std/time/calendar/timezone, ts@0 : std/time/instant/timescale) -> std/time/instant/instant*/
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, name, long_name, _x_x1510, kk_std_time_calendar_new_combine_earth_calendars_fun1512(cal1, cal2, mb_show_era, switch_date, _ctx), _x_x1518, _x_x1532, days_to_date, date_to_days, _ctx);
}
 
// Create a new calendar from anoter calendar `cal` by adding an offset to the
// years (`year-shift`). This is used for example to create the Ethiopian calendar
// from the Coptic calendar, by using:
// `year-shift-earth-calendar( "EC", "Ethiopian", ~276, cal-coptic )`


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1573__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_integer_t year_shift;
};
static kk_std_time_date__date kk_std_time_calendar_year_shift_earth_calendar_fun1573(kk_function_t _fself, kk_integer_t days_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1573(kk_std_time_calendar__calendar cal, kk_integer_t year_shift, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1573__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1573__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1573, kk_context());
  _self->cal = cal;
  _self->year_shift = year_shift;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_date__date kk_std_time_calendar_year_shift_earth_calendar_fun1573(kk_function_t _fself, kk_integer_t days_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1573__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1573__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_integer_t year_shift = _self->year_shift; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_integer_dup(year_shift, _ctx);}, {}, _ctx)
  kk_std_time_date__date d_0_1;
  {
    struct kk_std_time_calendar_Calendar* _con_x1574 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0_5 = _con_x1574->name;
    kk_string_t _pat_1_5 = _con_x1574->long_name;
    kk_string_t _pat_2_4 = _con_x1574->month_prefix;
    kk_function_t _pat_3_3 = _con_x1574->show_era;
    kk_function_t _pat_4_2 = _con_x1574->instant_to_dc;
    kk_function_t _pat_5_2 = _con_x1574->dc_to_instant;
    kk_function_t _x_4 = _con_x1574->days_to_date;
    kk_function_t _pat_6_0 = _con_x1574->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6_0, _ctx);
      kk_function_drop(_pat_5_2, _ctx);
      kk_function_drop(_pat_4_2, _ctx);
      kk_function_drop(_pat_3_3, _ctx);
      kk_string_drop(_pat_2_4, _ctx);
      kk_string_drop(_pat_1_5, _ctx);
      kk_string_drop(_pat_0_5, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    d_0_1 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), _x_4, (_x_4, days_0, _ctx), _ctx); /*std/time/date/date*/
  }
  kk_integer_t _b_x497_498;
  kk_integer_t _x_x1575;
  {
    kk_integer_t _x_6 = d_0_1.year;
    kk_integer_dup(_x_6, _ctx);
    _x_x1575 = _x_6; /*int*/
  }
  _b_x497_498 = kk_integer_sub(_x_x1575,year_shift,kk_context()); /*int*/
  kk_integer_t _x_x1576;
  kk_std_core_types__optional _match_x735 = kk_std_core_types__new_Optional(kk_integer_box(_b_x497_498, _ctx), _ctx); /*? 10003*/;
  if (kk_std_core_types__is_Optional(_match_x735, _ctx)) {
    kk_box_t _box_x499 = _match_x735._cons._Optional.value;
    kk_integer_t _uniq_year_102 = kk_integer_unbox(_box_x499, _ctx);
    kk_integer_dup(_uniq_year_102, _ctx);
    kk_std_core_types__optional_drop(_match_x735, _ctx);
    _x_x1576 = _uniq_year_102; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x735, _ctx);
    {
      kk_integer_t _x_5 = d_0_1.year;
      kk_integer_dup(_x_5, _ctx);
      _x_x1576 = _x_5; /*int*/
    }
  }
  kk_integer_t _x_x1577;
  kk_std_core_types__optional _match_x734 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x734, _ctx)) {
    kk_box_t _box_x500 = _match_x734._cons._Optional.value;
    kk_integer_t _uniq_month_110 = kk_integer_unbox(_box_x500, _ctx);
    kk_integer_dup(_uniq_month_110, _ctx);
    kk_std_core_types__optional_drop(_match_x734, _ctx);
    _x_x1577 = _uniq_month_110; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x734, _ctx);
    {
      kk_integer_t _x_0_0 = d_0_1.month;
      kk_integer_dup(_x_0_0, _ctx);
      _x_x1577 = _x_0_0; /*int*/
    }
  }
  kk_integer_t _x_x1578;
  kk_std_core_types__optional _match_x733 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x733, _ctx)) {
    kk_box_t _box_x501 = _match_x733._cons._Optional.value;
    kk_integer_t _uniq_day_118 = kk_integer_unbox(_box_x501, _ctx);
    kk_std_time_date__date_drop(d_0_1, _ctx);
    kk_integer_dup(_uniq_day_118, _ctx);
    kk_std_core_types__optional_drop(_match_x733, _ctx);
    _x_x1578 = _uniq_day_118; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x733, _ctx);
    {
      kk_integer_t _x_1_0 = d_0_1.day;
      kk_integer_dup(_x_1_0, _ctx);
      kk_std_time_date__date_drop(d_0_1, _ctx);
      _x_x1578 = _x_1_0; /*int*/
    }
  }
  return kk_std_time_date__new_Date(_x_x1576, _x_x1577, _x_x1578, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1579__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_integer_t year_shift;
};
static kk_integer_t kk_std_time_calendar_year_shift_earth_calendar_fun1579(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1579(kk_std_time_calendar__calendar cal, kk_integer_t year_shift, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1579__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1579__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1579, kk_context());
  _self->cal = cal;
  _self->year_shift = year_shift;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_time_calendar_year_shift_earth_calendar_fun1579(kk_function_t _fself, kk_std_time_date__date d_1, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1579__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1579__t*, _fself, _ctx);
  kk_std_time_calendar__calendar cal = _self->cal; /* std/time/calendar/calendar */
  kk_integer_t year_shift = _self->year_shift; /* int */
  kk_drop_match(_self, {kk_std_time_calendar__calendar_dup(cal, _ctx);kk_integer_dup(year_shift, _ctx);}, {}, _ctx)
  kk_integer_t _b_x502_503;
  kk_integer_t _x_x1580;
  {
    kk_integer_t _x_9 = d_1.year;
    kk_integer_dup(_x_9, _ctx);
    _x_x1580 = _x_9; /*int*/
  }
  _b_x502_503 = kk_integer_add(_x_x1580,year_shift,kk_context()); /*int*/
  {
    struct kk_std_time_calendar_Calendar* _con_x1581 = kk_std_time_calendar__as_Calendar(cal, _ctx);
    kk_string_t _pat_0_8 = _con_x1581->name;
    kk_string_t _pat_1_8 = _con_x1581->long_name;
    kk_string_t _pat_2_6 = _con_x1581->month_prefix;
    kk_function_t _pat_3_5 = _con_x1581->show_era;
    kk_function_t _pat_4_4 = _con_x1581->instant_to_dc;
    kk_function_t _pat_5_4 = _con_x1581->dc_to_instant;
    kk_function_t _pat_6_1 = _con_x1581->days_to_date;
    kk_function_t _x_7 = _con_x1581->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(cal, _ctx)) {
      kk_function_drop(_pat_6_1, _ctx);
      kk_function_drop(_pat_5_4, _ctx);
      kk_function_drop(_pat_4_4, _ctx);
      kk_function_drop(_pat_3_5, _ctx);
      kk_string_drop(_pat_2_6, _ctx);
      kk_string_drop(_pat_1_8, _ctx);
      kk_string_drop(_pat_0_8, _ctx);
      kk_datatype_ptr_free(cal, _ctx);
    }
    else {
      kk_function_dup(_x_7, _ctx);
      kk_datatype_ptr_decref(cal, _ctx);
    }
    kk_std_time_date__date _x_x1582;
    kk_integer_t _x_x1583;
    kk_std_core_types__optional _match_x732 = kk_std_core_types__new_Optional(kk_integer_box(_b_x502_503, _ctx), _ctx); /*? 10003*/;
    if (kk_std_core_types__is_Optional(_match_x732, _ctx)) {
      kk_box_t _box_x504 = _match_x732._cons._Optional.value;
      kk_integer_t _uniq_year_102_0 = kk_integer_unbox(_box_x504, _ctx);
      kk_integer_dup(_uniq_year_102_0, _ctx);
      kk_std_core_types__optional_drop(_match_x732, _ctx);
      _x_x1583 = _uniq_year_102_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x732, _ctx);
      {
        kk_integer_t _x_8 = d_1.year;
        kk_integer_dup(_x_8, _ctx);
        _x_x1583 = _x_8; /*int*/
      }
    }
    kk_integer_t _x_x1584;
    kk_std_core_types__optional _match_x731 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x731, _ctx)) {
      kk_box_t _box_x505 = _match_x731._cons._Optional.value;
      kk_integer_t _uniq_month_110_0 = kk_integer_unbox(_box_x505, _ctx);
      kk_integer_dup(_uniq_month_110_0, _ctx);
      kk_std_core_types__optional_drop(_match_x731, _ctx);
      _x_x1584 = _uniq_month_110_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x731, _ctx);
      {
        kk_integer_t _x_0_1 = d_1.month;
        kk_integer_dup(_x_0_1, _ctx);
        _x_x1584 = _x_0_1; /*int*/
      }
    }
    kk_integer_t _x_x1585;
    kk_std_core_types__optional _match_x730 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x730, _ctx)) {
      kk_box_t _box_x506 = _match_x730._cons._Optional.value;
      kk_integer_t _uniq_day_118_0 = kk_integer_unbox(_box_x506, _ctx);
      kk_std_time_date__date_drop(d_1, _ctx);
      kk_integer_dup(_uniq_day_118_0, _ctx);
      kk_std_core_types__optional_drop(_match_x730, _ctx);
      _x_x1585 = _uniq_day_118_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x730, _ctx);
      {
        kk_integer_t _x_1_1 = d_1.day;
        kk_integer_dup(_x_1_1, _ctx);
        kk_std_time_date__date_drop(d_1, _ctx);
        _x_x1585 = _x_1_1; /*int*/
      }
    }
    _x_x1582 = kk_std_time_date__new_Date(_x_x1583, _x_x1584, _x_x1585, _ctx); /*std/time/date/date*/
    return kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_7, (_x_7, _x_x1582, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1589__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x511;
};
static kk_string_t kk_std_time_calendar_year_shift_earth_calendar_fun1589(kk_function_t _fself, kk_std_time_date__date _b_x514, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1589(kk_box_t _fun_unbox_x511, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1589__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1589__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1589, kk_context());
  _self->_fun_unbox_x511 = _fun_unbox_x511;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_calendar_year_shift_earth_calendar_fun1589(kk_function_t _fself, kk_std_time_date__date _b_x514, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1589__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1589__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x511 = _self->_fun_unbox_x511; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x511, _ctx);}, {}, _ctx)
  kk_box_t _x_x1590;
  kk_function_t _x_x1591 = kk_function_unbox(_fun_unbox_x511, _ctx); /*(512) -> 513*/
  _x_x1590 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1591, (_x_x1591, kk_std_time_date__date_box(_b_x514, _ctx), _ctx), _ctx); /*513*/
  return kk_string_unbox(_x_x1590);
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1592__t {
  struct kk_function_s _base;
};
static kk_string_t kk_std_time_calendar_year_shift_earth_calendar_fun1592(kk_function_t _fself, kk_std_time_date__date d_2, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1592(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_year_shift_earth_calendar_fun1592, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_string_t kk_std_time_calendar_year_shift_earth_calendar_fun1592(kk_function_t _fself, kk_std_time_date__date d_2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_date__date_drop(d_2, _ctx);
  return kk_string_empty();
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1595__t {
  struct kk_function_s _base;
  kk_function_t days_to_date_10248;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_year_shift_earth_calendar_fun1595(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1595(kk_function_t days_to_date_10248, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1595__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1595__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1595, kk_context());
  _self->days_to_date_10248 = days_to_date_10248;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_year_shift_earth_calendar_fun1595(kk_function_t _fself, kk_std_time_instant__instant i, kk_std_time_duration__duration tzdelta, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1595__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1595__t*, _fself, _ctx);
  kk_function_t days_to_date_10248 = _self->days_to_date_10248; /* (days : int) -> std/time/date/date */
  kk_drop_match(_self, {kk_function_dup(days_to_date_10248, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _match_x729;
  kk_std_time_timestamp__timestamp _x_x1596;
  kk_std_num_ddouble__ddouble _x_x1597;
  kk_std_num_ddouble__ddouble _x_x1598;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1599 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1600 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1601 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1601->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1598 = _x; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1602;
  {
    kk_std_num_ddouble__ddouble _x_2 = tzdelta.secs;
    _x_x1602 = _x_2; /*std/time/timestamp/timespan*/
  }
  _x_x1597 = kk_std_num_ddouble__lp__plus__rp_(_x_x1598, _x_x1602, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1603;
  {
    kk_std_time_timestamp__timestamp _x_1_2 = i.since;
    kk_std_time_instant__timescale _pat_2_2_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1604 = kk_std_time_timestamp__as_Timestamp(_x_1_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1605 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_2, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1606 = kk_std_time_timestamp__as_Timestamp(_x_1_2, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1606->since;
      int32_t _x_0 = _con_x1606->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_2, _ctx)) {
        kk_datatype_ptr_free(_x_1_2, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_2, _ctx);
      }
      _x_x1603 = _x_0; /*int32*/
    }
  }
  _x_x1596 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1597, _x_x1603, _ctx); /*std/time/timestamp/timestamp*/
  _match_x729 = kk_std_time_timestamp_days_clock(_x_x1596, _ctx); /*(int, std/time/date/clock)*/
  {
    kk_box_t _box_x515 = _match_x729.fst;
    kk_box_t _box_x516 = _match_x729.snd;
    kk_std_time_date__clock clock = kk_std_time_date__clock_unbox(_box_x516, KK_BORROWED, _ctx);
    struct kk_std_time_date_Clock* _con_x1607 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_integer_t days = kk_integer_unbox(_box_x515, _ctx);
    kk_std_time_date__clock_dup(clock, _ctx);
    kk_integer_dup(days, _ctx);
    kk_std_core_types__tuple2_drop(_match_x729, _ctx);
    kk_std_time_date__date _b_x517_541 = kk_function_call(kk_std_time_date__date, (kk_function_t, kk_integer_t, kk_context_t*), days_to_date_10248, (days_to_date_10248, days, _ctx), _ctx); /*std/time/date/date*/;
    return kk_std_core_types__new_Tuple2(kk_std_time_date__date_box(_b_x517_541, _ctx), kk_std_time_date__clock_box(clock, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_time_calendar_year_shift_earth_calendar_fun1609__t {
  struct kk_function_s _base;
  kk_function_t date_to_days_10249;
};
static kk_std_time_instant__instant kk_std_time_calendar_year_shift_earth_calendar_fun1609(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_year_shift_earth_calendar_fun1609(kk_function_t date_to_days_10249, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1609__t* _self = kk_function_alloc_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1609__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendar_year_shift_earth_calendar_fun1609, kk_context());
  _self->date_to_days_10249 = date_to_days_10249;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_instant__instant kk_std_time_calendar_year_shift_earth_calendar_fun1609(kk_function_t _fself, kk_std_time_date__date d_0_0, kk_std_time_date__clock c, kk_std_time_calendar__timezone tz, kk_std_time_instant__timescale ts_0, kk_context_t* _ctx) {
  struct kk_std_time_calendar_year_shift_earth_calendar_fun1609__t* _self = kk_function_as(struct kk_std_time_calendar_year_shift_earth_calendar_fun1609__t*, _fself, _ctx);
  kk_function_t date_to_days_10249 = _self->date_to_days_10249; /* (std/time/date/date) -> int */
  kk_drop_match(_self, {kk_function_dup(date_to_days_10249, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_10317;
  kk_std_core_types__optional _x_x1610;
  kk_box_t _x_x1611;
  bool _x_x1612;
  {
    struct kk_std_time_instant_Timescale* _con_x1613 = kk_std_time_instant__as_Timescale(ts_0, _ctx);
    kk_std_core_types__maybe _x_3_1 = _con_x1613->mb_seconds_in_day;
    kk_std_core_types__maybe_dup(_x_3_1, _ctx);
    if (kk_std_core_types__is_Just(_x_3_1, _ctx)) {
      kk_std_core_types__maybe_drop(_x_3_1, _ctx);
      _x_x1612 = true; /*bool*/
    }
    else {
      _x_x1612 = false; /*bool*/
    }
  }
  _x_x1611 = kk_bool_box(_x_x1612); /*10003*/
  _x_x1610 = kk_std_core_types__new_Optional(_x_x1611, _ctx); /*? 10003*/
  t_10317 = kk_std_time_calendar_dc_timestamp(d_0_0, c, date_to_days_10249, _x_x1610, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__instant i_0;
  kk_std_time_timestamp__timestamp _x_x1614 = kk_std_time_timestamp__timestamp_dup(t_10317, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1615 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
  i_0 = kk_std_time_instant__new_Instant(_x_x1614, _x_x1615, _ctx); /*std/time/instant/instant*/
  bool _match_x726;
  kk_string_t _x_x1616;
  {
    struct kk_std_time_calendar_Timezone* _con_x1617 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _x_3 = _con_x1617->name;
    kk_string_dup(_x_3, _ctx);
    _x_x1616 = _x_3; /*string*/
  }
  kk_string_t _x_x1618;
  kk_std_time_calendar__timezone _x_x1619 = kk_std_time_calendar_tz_utc; /*std/time/calendar/timezone*/
  {
    struct kk_std_time_calendar_Timezone* _con_x1620 = kk_std_time_calendar__as_Timezone(_x_x1619, _ctx);
    kk_string_t _x_0_2 = _con_x1620->name;
    _x_x1618 = kk_string_dup(_x_0_2, _ctx); /*string*/
  }
  _match_x726 = kk_string_is_eq(_x_x1616,_x_x1618,kk_context()); /*bool*/
  if (_match_x726) {
    kk_datatype_ptr_dropn(tz, (KK_I32(3)), _ctx);
    kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
    kk_std_time_timestamp__timestamp_drop(t_10317, _ctx);
    return i_0;
  }
  {
    struct kk_std_time_calendar_Timezone* _con_x1621 = kk_std_time_calendar__as_Timezone(tz, _ctx);
    kk_string_t _pat_0_2_2_0 = _con_x1621->name;
    kk_function_t _pat_1_1_2 = _con_x1621->utc_delta;
    kk_function_t _x_1_2_0 = _con_x1621->utc_inverse;
    kk_function_dup(_x_1_2_0, _ctx);
    kk_std_core_types__maybe _match_x727;
    kk_std_time_instant__instant _x_x1622 = kk_std_time_instant__instant_dup(i_0, _ctx); /*std/time/instant/instant*/
    _match_x727 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_1_2_0, (_x_1_2_0, _x_x1622, _ctx), _ctx); /*maybe<std/time/instant/instant>*/
    if (kk_std_core_types__is_Just(_match_x727, _ctx)) {
      kk_box_t _box_x528 = _match_x727._cons.Just.value;
      kk_std_time_instant__instant inv = kk_std_time_instant__instant_unbox(_box_x528, KK_BORROWED, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
        kk_function_drop(_x_1_2_0, _ctx);
        kk_function_drop(_pat_1_1_2, _ctx);
        kk_string_drop(_pat_0_2_2_0, _ctx);
        kk_datatype_ptr_free(tz, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tz, _ctx);
      }
      kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
      kk_std_time_timestamp__timestamp_drop(t_10317, _ctx);
      kk_std_time_instant__instant_drop(i_0, _ctx);
      kk_std_time_instant__instant_dup(inv, _ctx);
      kk_std_core_types__maybe_drop(_match_x727, _ctx);
      return inv;
    }
    {
      kk_std_core_types__tuple2 tuple2_10133;
      {
        struct kk_std_time_calendar_Timezone* _con_x1623 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_function_t _x_3_0 = _con_x1623->utc_delta;
        kk_function_dup(_x_3_0, _ctx);
        tuple2_10133 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_3_0, (_x_3_0, i_0, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      kk_std_time_timestamp__timestamp t_1_10136;
      kk_std_num_ddouble__ddouble _x_x1624;
      kk_std_num_ddouble__ddouble _x_x1625;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1626 = kk_std_time_timestamp__as_Timestamp(t_10317, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0_0 = _con_x1626->since;
        _x_x1625 = _x_1_0_0; /*std/time/timestamp/timespan*/
      }
      kk_std_num_ddouble__ddouble _x_x1627;
      double _x_x1628;
      double _x_x1629;
      {
        kk_box_t _box_x529 = tuple2_10133.fst;
        kk_box_t _box_x530 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0 = kk_std_time_duration__duration_unbox(_box_x529, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0 = _x_2_0.secs;
          {
            double _x_4_0 = _x_5_0.hi;
            _x_x1629 = _x_4_0; /*float64*/
          }
        }
      }
      _x_x1628 = (-_x_x1629); /*float64*/
      double _x_x1630;
      double _x_x1631;
      {
        kk_box_t _box_x531 = tuple2_10133.fst;
        kk_box_t _box_x532 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_0 = kk_std_time_duration__duration_unbox(_box_x531, KK_BORROWED, _ctx);
        {
          kk_std_num_ddouble__ddouble _x_5_0_0 = _x_2_0_0.secs;
          {
            double _x_0_0_0 = _x_5_0_0.lo;
            _x_x1631 = _x_0_0_0; /*float64*/
          }
        }
      }
      _x_x1630 = (-_x_x1631); /*float64*/
      _x_x1627 = kk_std_num_ddouble__new_Ddouble(_x_x1628, _x_x1630, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1624 = kk_std_num_ddouble__lp__plus__rp_(_x_x1625, _x_x1627, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1632;
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1633 = kk_std_time_timestamp__as_Timestamp(t_10317, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_2_0_0 = _con_x1633->since;
        int32_t _x_2_0_0_0 = _con_x1633->leap32;
        _x_x1632 = _x_2_0_0_0; /*int32*/
      }
      t_1_10136 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1624, _x_x1632, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__instant tzi1;
      kk_std_time_instant__timescale _x_x1634 = kk_std_time_instant__timescale_dup(ts_0, _ctx); /*std/time/instant/timescale*/
      tzi1 = kk_std_time_instant__new_Instant(t_1_10136, _x_x1634, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_0_10140;
      {
        struct kk_std_time_calendar_Timezone* _con_x1635 = kk_std_time_calendar__as_Timezone(tz, _ctx);
        kk_string_t _pat_0_8_0 = _con_x1635->name;
        kk_function_t _x_7_0 = _con_x1635->utc_delta;
        kk_function_t _pat_1_6_0 = _con_x1635->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tz, _ctx)) {
          kk_function_drop(_pat_1_6_0, _ctx);
          kk_string_drop(_pat_0_8_0, _ctx);
          kk_datatype_ptr_free(tz, _ctx);
        }
        else {
          kk_function_dup(_x_7_0, _ctx);
          kk_datatype_ptr_decref(tz, _ctx);
        }
        kk_std_time_instant__instant _x_x1636 = kk_std_time_instant__instant_dup(tzi1, _ctx); /*std/time/instant/instant*/
        tuple2_0_10140 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_std_time_instant__instant, kk_context_t*), _x_7_0, (_x_7_0, _x_x1636, _ctx), _ctx); /*(std/time/duration/duration, string)*/
      }
      bool _match_x728;
      kk_std_time_duration__duration _x_x1637;
      {
        kk_box_t _box_x533 = tuple2_10133.fst;
        kk_box_t _box_x534 = tuple2_10133.snd;
        kk_std_time_duration__duration _x_2_0_1 = kk_std_time_duration__duration_unbox(_box_x533, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10133, _ctx);
        _x_x1637 = _x_2_0_1; /*std/time/duration/duration*/
      }
      kk_std_time_duration__duration _x_x1638;
      {
        kk_box_t _box_x535 = tuple2_0_10140.fst;
        kk_box_t _box_x536 = tuple2_0_10140.snd;
        kk_std_time_duration__duration _x_6_0 = kk_std_time_duration__duration_unbox(_box_x535, KK_BORROWED, _ctx);
        _x_x1638 = _x_6_0; /*std/time/duration/duration*/
      }
      _match_x728 = kk_std_time_duration__lp__eq__eq__rp_(_x_x1637, _x_x1638, _ctx); /*bool*/
      if (_match_x728) {
        kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
        kk_datatype_ptr_dropn(ts_0, (KK_I32(10)), _ctx);
        kk_std_time_timestamp__timestamp_drop(t_10317, _ctx);
        return tzi1;
      }
      {
        kk_std_time_instant__instant_drop(tzi1, _ctx);
        kk_std_time_timestamp__timestamp t_3_10143;
        kk_std_num_ddouble__ddouble _x_x1639;
        kk_std_num_ddouble__ddouble _x_x1640;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1641 = kk_std_time_timestamp__as_Timestamp(t_10317, _ctx);
          kk_std_num_ddouble__ddouble _x_1_1_0 = _con_x1641->since;
          _x_x1640 = _x_1_1_0; /*std/time/timestamp/timespan*/
        }
        kk_std_num_ddouble__ddouble _x_x1642;
        double _x_x1643;
        double _x_x1644;
        {
          kk_box_t _box_x537 = tuple2_0_10140.fst;
          kk_box_t _box_x538 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0_0 = kk_std_time_duration__duration_unbox(_box_x537, KK_BORROWED, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0 = _x_6_0_0.secs;
            {
              double _x_8_0 = _x_9_0.hi;
              _x_x1644 = _x_8_0; /*float64*/
            }
          }
        }
        _x_x1643 = (-_x_x1644); /*float64*/
        double _x_x1645;
        double _x_x1646;
        {
          kk_box_t _box_x539 = tuple2_0_10140.fst;
          kk_box_t _box_x540 = tuple2_0_10140.snd;
          kk_std_time_duration__duration _x_6_0_1 = kk_std_time_duration__duration_unbox(_box_x539, KK_BORROWED, _ctx);
          kk_std_core_types__tuple2_drop(tuple2_0_10140, _ctx);
          {
            kk_std_num_ddouble__ddouble _x_9_0_0 = _x_6_0_1.secs;
            {
              double _x_0_1_0 = _x_9_0_0.lo;
              _x_x1646 = _x_0_1_0; /*float64*/
            }
          }
        }
        _x_x1645 = (-_x_x1646); /*float64*/
        _x_x1642 = kk_std_num_ddouble__new_Ddouble(_x_x1643, _x_x1645, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1639 = kk_std_num_ddouble__lp__plus__rp_(_x_x1640, _x_x1642, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x1647;
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1648 = kk_std_time_timestamp__as_Timestamp(t_10317, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_2_1_0 = _con_x1648->since;
          int32_t _x_2_1 = _con_x1648->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(t_10317, _ctx)) {
            kk_datatype_ptr_free(t_10317, _ctx);
          }
          else {
            kk_datatype_ptr_decref(t_10317, _ctx);
          }
          _x_x1647 = _x_2_1; /*int32*/
        }
        t_3_10143 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1639, _x_x1647, _ctx); /*std/time/timestamp/timestamp*/
        return kk_std_time_instant__new_Instant(t_3_10143, ts_0, _ctx);
      }
    }
  }
}

kk_std_time_calendar__calendar kk_std_time_calendar_year_shift_earth_calendar(kk_string_t name, kk_string_t long_name, kk_integer_t year_shift, kk_std_time_calendar__calendar cal, kk_std_core_types__optional month_prefix, kk_std_core_types__optional show_era, kk_context_t* _ctx) { /* (name : string, long-name : string, year-shift : int, cal : calendar, month-prefix : ? string, show-era : ? ((std/time/date/date) -> string)) -> calendar */ 
  kk_function_t days_to_date_10248;
  kk_std_time_calendar__calendar_dup(cal, _ctx);
  kk_integer_dup(year_shift, _ctx);
  days_to_date_10248 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1573(cal, year_shift, _ctx); /*(days@0 : int) -> std/time/date/date*/
  kk_function_t date_to_days_10249 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1579(cal, year_shift, _ctx); /*(d@1 : std/time/date/date) -> int*/;
  kk_string_t _x_x1586;
  if (kk_std_core_types__is_Optional(month_prefix, _ctx)) {
    kk_box_t _box_x507 = month_prefix._cons._Optional.value;
    kk_string_t _uniq_month_prefix_3707 = kk_string_unbox(_box_x507);
    kk_string_dup(_uniq_month_prefix_3707, _ctx);
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1586 = _uniq_month_prefix_3707; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(month_prefix, _ctx);
    _x_x1586 = kk_string_empty(); /*string*/
  }
  kk_function_t _x_x1588;
  if (kk_std_core_types__is_Optional(show_era, _ctx)) {
    kk_box_t _fun_unbox_x511 = show_era._cons._Optional.value;
    kk_box_dup(_fun_unbox_x511, _ctx);
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x1588 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1589(_fun_unbox_x511, _ctx); /*(std/time/date/date) -> string*/
  }
  else {
    kk_std_core_types__optional_drop(show_era, _ctx);
    _x_x1588 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1592(_ctx); /*(std/time/date/date) -> string*/
  }
  kk_function_t _x_x1594;
  kk_function_dup(days_to_date_10248, _ctx);
  _x_x1594 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1595(days_to_date_10248, _ctx); /*(i : std/time/instant/instant, tzdelta : std/time/duration/duration) -> (10037, 10038)*/
  kk_function_t _x_x1608;
  kk_function_dup(date_to_days_10249, _ctx);
  _x_x1608 = kk_std_time_calendar_new_year_shift_earth_calendar_fun1609(date_to_days_10249, _ctx); /*(d@0@0 : std/time/date/date, c : std/time/date/clock, tz : std/time/calendar/timezone, ts@0 : std/time/instant/timescale) -> std/time/instant/instant*/
  return kk_std_time_calendar__new_Calendar(kk_reuse_null, 0, name, long_name, _x_x1586, _x_x1588, _x_x1594, _x_x1608, days_to_date_10248, date_to_days_10249, _ctx);
}
 
// Create a standard [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) calendar
// using UTC time (`ts-utc-create`) given a provide leap second table (`:leaps-table`).
// This is a proleptic Gregorian
// calendar except that it uses the year 0 for 1 BCE, -1 for 2 BCE etc.
//
// You can create an ISO 8601 UTC calendar using the latest IERS leap
// second data using [`cal-utc-load`](std_time_download.html#cal_utc_load).


// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1654__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_utc_create_fun1654(kk_function_t _fself, kk_integer_t _x1_x1653, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1654(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1654, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_utc_create_fun1654(kk_function_t _fself, kk_integer_t _x1_x1653, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1653, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1655__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_create_fun1655(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1655(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1655, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_create_fun1655(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _match_x721;
  kk_integer_t _x_x1656 = kk_integer_dup(days, _ctx); /*int*/
  _match_x721 = kk_std_time_calendar_iso_estimate_year(_x_x1656, _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x543 = _match_x721.fst;
    kk_box_t _box_x544 = _match_x721.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x543, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x544, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x721, _ctx);
    kk_integer_t y_10193;
    kk_integer_t _x_x1657 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_std_time_calendar_iso_days_before_year(_x_x1657, _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1658 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1658,y_10193,kk_context()); /*int*/
    bool _match_x722;
    kk_integer_t _brw_x724;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x724 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x545 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x545, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x724 = x_0; /*int*/
    }
    bool _brw_x725 = kk_integer_lte_borrow(doy1,_brw_x724,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x724, _ctx);
    _match_x722 = _brw_x725; /*bool*/
    if (_match_x722) {
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t year_10504;
      kk_integer_t _x_x1659 = kk_integer_dup(approx, _ctx); /*int*/
      year_10504 = kk_integer_add_small_const(_x_x1659, 1, _ctx); /*int*/
      kk_integer_t y = kk_integer_add_small_const(year_10504, -1, _ctx); /*int*/;
      kk_integer_t x_0_10117;
      kk_integer_t _x_x1660 = kk_integer_dup(y, _ctx); /*int*/
      x_0_10117 = kk_integer_div(_x_x1660,(kk_integer_from_small(4)),kk_context()); /*int*/
      kk_integer_t y_1_10118;
      kk_integer_t _x_x1661 = kk_integer_dup(y, _ctx); /*int*/
      y_1_10118 = kk_integer_div(_x_x1661,(kk_integer_from_small(100)),kk_context()); /*int*/
      kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
      kk_integer_t y_0_10116;
      kk_integer_t _x_x1662 = kk_integer_dup(y, _ctx); /*int*/
      y_0_10116 = kk_integer_div(_x_x1662,(kk_integer_from_small(400)),kk_context()); /*int*/
      kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
      kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
      kk_integer_t y_0_10197 = kk_integer_add(x_1_10119,leapdays,kk_context()); /*int*/;
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x723 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x723) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x550_573 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x550_573, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1665__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_utc_create_fun1665(kk_function_t _fself, kk_integer_t _x1_x1663, kk_integer_t _x2_x1664, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1665(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1665, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_utc_create_fun1665(kk_function_t _fself, kk_integer_t _x1_x1663, kk_integer_t _x2_x1664, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1663, _x2_x1664, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1668__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_utc_create_fun1668(kk_function_t _fself, kk_integer_t _x1_x1666, kk_integer_t _x2_x1667, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1668(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1668, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_utc_create_fun1668(kk_function_t _fself, kk_integer_t _x1_x1666, kk_integer_t _x2_x1667, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1666, _x2_x1667, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_create_fun1680__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_cal_utc_create_fun1680(kk_function_t _fself, kk_box_t _b_x568, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_create_fun1680(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_create_fun1680, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_cal_utc_create_fun1680(kk_function_t _fself, kk_box_t _b_x568, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1681;
  kk_std_time_date__date _norm_x579 = kk_std_time_date__date_unbox(_b_x568, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_std_core_types__optional _match_x717 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x717, _ctx)) {
    kk_box_t _fun_unbox_x561 = _match_x717._cons._Optional.value;
    kk_box_dup(_fun_unbox_x561, _ctx);
    kk_std_core_types__optional_drop(_match_x717, _ctx);
    kk_std_time_date__date _b_x564_580 = _norm_x579; /*std/time/date/date*/;
    kk_box_t _x_x1682;
    kk_function_t _x_x1683 = kk_function_unbox(_fun_unbox_x561, _ctx); /*(562) -> 563*/
    _x_x1682 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1683, (_x_x1683, kk_std_time_date__date_box(_b_x564_580, _ctx), _ctx), _ctx); /*563*/
    _x_x1681 = kk_string_unbox(_x_x1682); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x717, _ctx);
    kk_std_time_date__date d_581 = _norm_x579; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_581, _ctx);
    _x_x1681 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1681);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_utc_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : std/time/utc/leaps-table) -> calendar */ 
  kk_std_time_instant__timescale ts_utc = kk_std_time_utc_ts_utc_create(leaps, _ctx); /*std/time/instant/timescale*/;
  kk_datatype_ptr_dropn(ts_utc, (KK_I32(10)), _ctx);
  kk_string_t _x_x1649 = kk_string_empty(); /*string*/
  kk_string_t _x_x1651;
  kk_define_string_literal(, _s_x1652, 3, "ISO", _ctx)
  _x_x1651 = kk_string_dup(_s_x1652, _ctx); /*string*/
  kk_std_core_types__optional _x_x1669;
  kk_box_t _x_x1670;
  kk_integer_t _x_x1671;
  kk_std_core_types__optional _match_x720 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x720, _ctx)) {
    kk_box_t _box_x552 = _match_x720._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x552, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
    kk_std_core_types__optional_drop(_match_x720, _ctx);
    _x_x1671 = _uniq_epoch_shift_2171; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x720, _ctx);
    _x_x1671 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  _x_x1670 = kk_integer_box(_x_x1671, _ctx); /*10003*/
  _x_x1669 = kk_std_core_types__new_Optional(_x_x1670, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1672;
  kk_box_t _x_x1673;
  bool _x_x1674;
  kk_std_core_types__optional _match_x719 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x719, _ctx)) {
    kk_box_t _box_x554 = _match_x719._cons._Optional.value;
    bool _uniq_has_year_zero_2175 = kk_bool_unbox(_box_x554);
    kk_std_core_types__optional_drop(_match_x719, _ctx);
    _x_x1674 = _uniq_has_year_zero_2175; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x719, _ctx);
    _x_x1674 = true; /*bool*/
  }
  _x_x1673 = kk_bool_box(_x_x1674); /*10003*/
  _x_x1672 = kk_std_core_types__new_Optional(_x_x1673, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1675;
  kk_box_t _x_x1676;
  kk_string_t _x_x1677;
  kk_std_core_types__optional _match_x718 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x718, _ctx)) {
    kk_box_t _box_x556 = _match_x718._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x556);
    kk_string_dup(_uniq_month_prefix_2179, _ctx);
    kk_std_core_types__optional_drop(_match_x718, _ctx);
    _x_x1677 = _uniq_month_prefix_2179; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x718, _ctx);
    _x_x1677 = kk_string_empty(); /*string*/
  }
  _x_x1676 = kk_string_box(_x_x1677); /*10003*/
  _x_x1675 = kk_std_core_types__new_Optional(_x_x1676, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1679 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_cal_utc_create_fun1680(_ctx), _ctx), _ctx); /*? 10003*/
  return kk_std_time_calendar_solar_calendar(_x_x1649, _x_x1651, kk_std_time_calendar_new_cal_utc_create_fun1654(_ctx), kk_std_time_calendar_new_cal_utc_create_fun1655(_ctx), kk_std_time_calendar_new_cal_utc_create_fun1665(_ctx), kk_std_time_calendar_new_cal_utc_create_fun1668(_ctx), _x_x1669, _x_x1672, _x_x1675, _x_x1679, _ctx);
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
struct kk_std_time_calendar_cal_iso_sls_fun1690__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1690(kk_function_t _fself, kk_integer_t _x1_x1689, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1690(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1690, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1690(kk_function_t _fself, kk_integer_t _x1_x1689, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1689, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1691__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_sls_fun1691(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1691(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1691, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_iso_sls_fun1691(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _match_x712;
  kk_integer_t _x_x1692 = kk_integer_dup(days, _ctx); /*int*/
  _match_x712 = kk_std_time_calendar_iso_estimate_year(_x_x1692, _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x582 = _match_x712.fst;
    kk_box_t _box_x583 = _match_x712.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x582, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x583, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x712, _ctx);
    kk_integer_t y_10193;
    kk_integer_t _x_x1693 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_std_time_calendar_iso_days_before_year(_x_x1693, _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1694 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1694,y_10193,kk_context()); /*int*/
    bool _match_x713;
    kk_integer_t _brw_x715;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x715 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x584 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x584, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x715 = x_0; /*int*/
    }
    bool _brw_x716 = kk_integer_lte_borrow(doy1,_brw_x715,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x715, _ctx);
    _match_x713 = _brw_x716; /*bool*/
    if (_match_x713) {
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t year_10505;
      kk_integer_t _x_x1695 = kk_integer_dup(approx, _ctx); /*int*/
      year_10505 = kk_integer_add_small_const(_x_x1695, 1, _ctx); /*int*/
      kk_integer_t y = kk_integer_add_small_const(year_10505, -1, _ctx); /*int*/;
      kk_integer_t x_0_10117;
      kk_integer_t _x_x1696 = kk_integer_dup(y, _ctx); /*int*/
      x_0_10117 = kk_integer_div(_x_x1696,(kk_integer_from_small(4)),kk_context()); /*int*/
      kk_integer_t y_1_10118;
      kk_integer_t _x_x1697 = kk_integer_dup(y, _ctx); /*int*/
      y_1_10118 = kk_integer_div(_x_x1697,(kk_integer_from_small(100)),kk_context()); /*int*/
      kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
      kk_integer_t y_0_10116;
      kk_integer_t _x_x1698 = kk_integer_dup(y, _ctx); /*int*/
      y_0_10116 = kk_integer_div(_x_x1698,(kk_integer_from_small(400)),kk_context()); /*int*/
      kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
      kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
      kk_integer_t y_0_10197 = kk_integer_add(x_1_10119,leapdays,kk_context()); /*int*/;
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x714 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x714) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x589_612 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x589_612, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1701__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1701(kk_function_t _fself, kk_integer_t _x1_x1699, kk_integer_t _x2_x1700, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1701(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1701, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1701(kk_function_t _fself, kk_integer_t _x1_x1699, kk_integer_t _x2_x1700, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1699, _x2_x1700, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1704__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1704(kk_function_t _fself, kk_integer_t _x1_x1702, kk_integer_t _x2_x1703, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1704(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1704, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_iso_sls_fun1704(kk_function_t _fself, kk_integer_t _x1_x1702, kk_integer_t _x2_x1703, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1702, _x2_x1703, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_iso_sls_fun1716__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_cal_iso_sls_fun1716(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_iso_sls_fun1716(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_iso_sls_fun1716, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_cal_iso_sls_fun1716(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1717;
  kk_std_time_date__date _norm_x618 = kk_std_time_date__date_unbox(_b_x607, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_std_core_types__optional _match_x708 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x708, _ctx)) {
    kk_box_t _fun_unbox_x600 = _match_x708._cons._Optional.value;
    kk_box_dup(_fun_unbox_x600, _ctx);
    kk_std_core_types__optional_drop(_match_x708, _ctx);
    kk_std_time_date__date _b_x603_619 = _norm_x618; /*std/time/date/date*/;
    kk_box_t _x_x1718;
    kk_function_t _x_x1719 = kk_function_unbox(_fun_unbox_x600, _ctx); /*(601) -> 602*/
    _x_x1718 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1719, (_x_x1719, kk_std_time_date__date_box(_b_x603_619, _ctx), _ctx), _ctx); /*602*/
    _x_x1717 = kk_string_unbox(_x_x1718); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x708, _ctx);
    kk_std_time_date__date d_620 = _norm_x618; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_620, _ctx);
    _x_x1717 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1717);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_iso_sls;
 
// Create a new ISO 8601 calendar based on UTC-SLS time, i.e. UTC with smoothed leap
// seconds.


// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1726__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1726(kk_function_t _fself, kk_integer_t _x1_x1725, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1726(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1726, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1726(kk_function_t _fself, kk_integer_t _x1_x1725, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1725, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1727__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_sls_create_fun1727(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1727(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1727, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_utc_sls_create_fun1727(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _match_x703;
  kk_integer_t _x_x1728 = kk_integer_dup(days, _ctx); /*int*/
  _match_x703 = kk_std_time_calendar_iso_estimate_year(_x_x1728, _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x621 = _match_x703.fst;
    kk_box_t _box_x622 = _match_x703.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x621, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x622, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x703, _ctx);
    kk_integer_t y_10193;
    kk_integer_t _x_x1729 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_std_time_calendar_iso_days_before_year(_x_x1729, _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1730 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1730,y_10193,kk_context()); /*int*/
    bool _match_x704;
    kk_integer_t _brw_x706;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x706 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x623 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x623, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x706 = x_0; /*int*/
    }
    bool _brw_x707 = kk_integer_lte_borrow(doy1,_brw_x706,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x706, _ctx);
    _match_x704 = _brw_x707; /*bool*/
    if (_match_x704) {
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t year_10506;
      kk_integer_t _x_x1731 = kk_integer_dup(approx, _ctx); /*int*/
      year_10506 = kk_integer_add_small_const(_x_x1731, 1, _ctx); /*int*/
      kk_integer_t y = kk_integer_add_small_const(year_10506, -1, _ctx); /*int*/;
      kk_integer_t x_0_10117;
      kk_integer_t _x_x1732 = kk_integer_dup(y, _ctx); /*int*/
      x_0_10117 = kk_integer_div(_x_x1732,(kk_integer_from_small(4)),kk_context()); /*int*/
      kk_integer_t y_1_10118;
      kk_integer_t _x_x1733 = kk_integer_dup(y, _ctx); /*int*/
      y_1_10118 = kk_integer_div(_x_x1733,(kk_integer_from_small(100)),kk_context()); /*int*/
      kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
      kk_integer_t y_0_10116;
      kk_integer_t _x_x1734 = kk_integer_dup(y, _ctx); /*int*/
      y_0_10116 = kk_integer_div(_x_x1734,(kk_integer_from_small(400)),kk_context()); /*int*/
      kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
      kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
      kk_integer_t y_0_10197 = kk_integer_add(x_1_10119,leapdays,kk_context()); /*int*/;
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x705 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x705) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x628_651 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x628_651, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1737__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1737(kk_function_t _fself, kk_integer_t _x1_x1735, kk_integer_t _x2_x1736, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1737(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1737, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1737(kk_function_t _fself, kk_integer_t _x1_x1735, kk_integer_t _x2_x1736, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1735, _x2_x1736, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1740__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1740(kk_function_t _fself, kk_integer_t _x1_x1738, kk_integer_t _x2_x1739, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1740(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1740, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_utc_sls_create_fun1740(kk_function_t _fself, kk_integer_t _x1_x1738, kk_integer_t _x2_x1739, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1738, _x2_x1739, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_utc_sls_create_fun1752__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_cal_utc_sls_create_fun1752(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_utc_sls_create_fun1752(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_utc_sls_create_fun1752, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_cal_utc_sls_create_fun1752(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1753;
  kk_std_time_date__date _norm_x657 = kk_std_time_date__date_unbox(_b_x646, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_std_core_types__optional _match_x699 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x699, _ctx)) {
    kk_box_t _fun_unbox_x639 = _match_x699._cons._Optional.value;
    kk_box_dup(_fun_unbox_x639, _ctx);
    kk_std_core_types__optional_drop(_match_x699, _ctx);
    kk_std_time_date__date _b_x642_658 = _norm_x657; /*std/time/date/date*/;
    kk_box_t _x_x1754;
    kk_function_t _x_x1755 = kk_function_unbox(_fun_unbox_x639, _ctx); /*(640) -> 641*/
    _x_x1754 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1755, (_x_x1755, kk_std_time_date__date_box(_b_x642_658, _ctx), _ctx), _ctx); /*641*/
    _x_x1753 = kk_string_unbox(_x_x1754); /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x699, _ctx);
    kk_std_time_date__date d_659 = _norm_x657; /*std/time/date/date*/;
    kk_std_time_date__date_drop(d_659, _ctx);
    _x_x1753 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x1753);
}

kk_std_time_calendar__calendar kk_std_time_calendar_cal_utc_sls_create(kk_std_time_utc__leaps_table leaps, kk_context_t* _ctx) { /* (leaps : std/time/utc/leaps-table) -> calendar */ 
  kk_std_time_instant__timescale ts_utc_sls = kk_std_time_utc_ts_utc_sls_create(leaps, _ctx); /*std/time/instant/timescale*/;
  kk_datatype_ptr_dropn(ts_utc_sls, (KK_I32(10)), _ctx);
  kk_string_t _x_x1721;
  kk_define_string_literal(, _s_x1722, 3, "SLS", _ctx)
  _x_x1721 = kk_string_dup(_s_x1722, _ctx); /*string*/
  kk_string_t _x_x1723;
  kk_define_string_literal(, _s_x1724, 7, "ISO-SLS", _ctx)
  _x_x1723 = kk_string_dup(_s_x1724, _ctx); /*string*/
  kk_std_core_types__optional _x_x1741;
  kk_box_t _x_x1742;
  kk_integer_t _x_x1743;
  kk_std_core_types__optional _match_x702 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x702, _ctx)) {
    kk_box_t _box_x630 = _match_x702._cons._Optional.value;
    kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x630, _ctx);
    kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
    kk_std_core_types__optional_drop(_match_x702, _ctx);
    _x_x1743 = _uniq_epoch_shift_2171; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x702, _ctx);
    _x_x1743 = kk_integer_from_int(730119, _ctx); /*int*/
  }
  _x_x1742 = kk_integer_box(_x_x1743, _ctx); /*10003*/
  _x_x1741 = kk_std_core_types__new_Optional(_x_x1742, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1744;
  kk_box_t _x_x1745;
  bool _x_x1746;
  kk_std_core_types__optional _match_x701 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x701, _ctx)) {
    kk_box_t _box_x632 = _match_x701._cons._Optional.value;
    bool _uniq_has_year_zero_2175 = kk_bool_unbox(_box_x632);
    kk_std_core_types__optional_drop(_match_x701, _ctx);
    _x_x1746 = _uniq_has_year_zero_2175; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x701, _ctx);
    _x_x1746 = true; /*bool*/
  }
  _x_x1745 = kk_bool_box(_x_x1746); /*10003*/
  _x_x1744 = kk_std_core_types__new_Optional(_x_x1745, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1747;
  kk_box_t _x_x1748;
  kk_string_t _x_x1749;
  kk_std_core_types__optional _match_x700 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x700, _ctx)) {
    kk_box_t _box_x634 = _match_x700._cons._Optional.value;
    kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x634);
    kk_string_dup(_uniq_month_prefix_2179, _ctx);
    kk_std_core_types__optional_drop(_match_x700, _ctx);
    _x_x1749 = _uniq_month_prefix_2179; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x700, _ctx);
    _x_x1749 = kk_string_empty(); /*string*/
  }
  _x_x1748 = kk_string_box(_x_x1749); /*10003*/
  _x_x1747 = kk_std_core_types__new_Optional(_x_x1748, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1751 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_cal_utc_sls_create_fun1752(_ctx), _ctx), _ctx); /*? 10003*/
  return kk_std_time_calendar_solar_calendar(_x_x1721, _x_x1723, kk_std_time_calendar_new_cal_utc_sls_create_fun1726(_ctx), kk_std_time_calendar_new_cal_utc_sls_create_fun1727(_ctx), kk_std_time_calendar_new_cal_utc_sls_create_fun1737(_ctx), kk_std_time_calendar_new_cal_utc_sls_create_fun1740(_ctx), _x_x1741, _x_x1744, _x_x1747, _x_x1751, _ctx);
}
 
// The (proleptic) [Gregorian calendar](https://en.wikipedia.org/wiki/Gregorian_calendar).
// Just like the ISO calendar except that the year 0 does not exist, i.e. after 1 BCE (=`~1`)
// we have 1 CE (=`1`).
// The calendar short name is ``GC``.


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1762__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1762(kk_function_t _fself, kk_integer_t _x1_x1761, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1762(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1762, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1762(kk_function_t _fself, kk_integer_t _x1_x1761, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_year(_x1_x1761, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1763__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendar_cal_gregorian_fun1763(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1763(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1763, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendar_cal_gregorian_fun1763(kk_function_t _fself, kk_integer_t days, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _match_x694;
  kk_integer_t _x_x1764 = kk_integer_dup(days, _ctx); /*int*/
  _match_x694 = kk_std_time_calendar_iso_estimate_year(_x_x1764, _ctx); /*(int, maybe<int>)*/
  {
    kk_box_t _box_x660 = _match_x694.fst;
    kk_box_t _box_x661 = _match_x694.snd;
    kk_integer_t approx = kk_integer_unbox(_box_x660, _ctx);
    kk_std_core_types__maybe safe = kk_std_core_types__maybe_unbox(_box_x661, KK_BORROWED, _ctx);
    kk_integer_dup(approx, _ctx);
    kk_std_core_types__maybe_dup(safe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x694, _ctx);
    kk_integer_t y_10193;
    kk_integer_t _x_x1765 = kk_integer_dup(approx, _ctx); /*int*/
    y_10193 = kk_std_time_calendar_iso_days_before_year(_x_x1765, _ctx); /*int*/
    kk_integer_t doy1;
    kk_integer_t _x_x1766 = kk_integer_dup(days, _ctx); /*int*/
    doy1 = kk_integer_sub(_x_x1766,y_10193,kk_context()); /*int*/
    bool _match_x695;
    kk_integer_t _brw_x697;
    if (kk_std_core_types__is_Nothing(safe, _ctx)) {
      _brw_x697 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x662 = safe._cons.Just.value;
      kk_integer_t x_0 = kk_integer_unbox(_box_x662, _ctx);
      kk_integer_dup(x_0, _ctx);
      kk_std_core_types__maybe_drop(safe, _ctx);
      _brw_x697 = x_0; /*int*/
    }
    bool _brw_x698 = kk_integer_lte_borrow(doy1,_brw_x697,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x697, _ctx);
    _match_x695 = _brw_x698; /*bool*/
    if (_match_x695) {
      kk_integer_drop(days, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
    }
    {
      kk_integer_t year_10507;
      kk_integer_t _x_x1767 = kk_integer_dup(approx, _ctx); /*int*/
      year_10507 = kk_integer_add_small_const(_x_x1767, 1, _ctx); /*int*/
      kk_integer_t y = kk_integer_add_small_const(year_10507, -1, _ctx); /*int*/;
      kk_integer_t x_0_10117;
      kk_integer_t _x_x1768 = kk_integer_dup(y, _ctx); /*int*/
      x_0_10117 = kk_integer_div(_x_x1768,(kk_integer_from_small(4)),kk_context()); /*int*/
      kk_integer_t y_1_10118;
      kk_integer_t _x_x1769 = kk_integer_dup(y, _ctx); /*int*/
      y_1_10118 = kk_integer_div(_x_x1769,(kk_integer_from_small(100)),kk_context()); /*int*/
      kk_integer_t x_10115 = kk_integer_sub(x_0_10117,y_1_10118,kk_context()); /*int*/;
      kk_integer_t y_0_10116;
      kk_integer_t _x_x1770 = kk_integer_dup(y, _ctx); /*int*/
      y_0_10116 = kk_integer_div(_x_x1770,(kk_integer_from_small(400)),kk_context()); /*int*/
      kk_integer_t leapdays = kk_integer_add(x_10115,y_0_10116,kk_context()); /*int*/;
      kk_integer_t x_1_10119 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
      kk_integer_t y_0_10197 = kk_integer_add(x_1_10119,leapdays,kk_context()); /*int*/;
      kk_integer_t doy2 = kk_integer_sub(days,y_0_10197,kk_context()); /*int*/;
      bool _match_x696 = kk_integer_lt_borrow(doy2,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x696) {
        kk_integer_drop(doy2, _ctx);
        return kk_std_core_types__new_Tuple2(kk_integer_box(approx, _ctx), kk_integer_box(doy1, _ctx), _ctx);
      }
      {
        kk_integer_drop(doy1, _ctx);
        kk_integer_t _b_x667_682 = kk_integer_add_small_const(approx, 1, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x667_682, _ctx), kk_integer_box(doy2, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1773__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1773(kk_function_t _fself, kk_integer_t _x1_x1771, kk_integer_t _x2_x1772, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1773(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1773, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1773(kk_function_t _fself, kk_integer_t _x1_x1771, kk_integer_t _x2_x1772, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_days_before_month(_x1_x1771, _x2_x1772, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1776__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1776(kk_function_t _fself, kk_integer_t _x1_x1774, kk_integer_t _x2_x1775, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1776(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1776, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendar_cal_gregorian_fun1776(kk_function_t _fself, kk_integer_t _x1_x1774, kk_integer_t _x2_x1775, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendar_iso_doy_to_month(_x1_x1774, _x2_x1775, _ctx);
}


// lift anonymous function
struct kk_std_time_calendar_cal_gregorian_fun1786__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendar_cal_gregorian_fun1786(kk_function_t _fself, kk_box_t _b_x677, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendar_new_cal_gregorian_fun1786(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendar_cal_gregorian_fun1786, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendar_cal_gregorian_fun1786(kk_function_t _fself, kk_box_t _b_x677, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1787;
  kk_std_time_date__date d_0_688 = kk_std_time_date__date_unbox(_b_x677, KK_OWNED, _ctx); /*std/time/date/date*/;
  bool _match_x689;
  kk_integer_t _brw_x690;
  {
    kk_integer_t _x = d_0_688.year;
    kk_integer_dup(_x, _ctx);
    kk_std_time_date__date_drop(d_0_688, _ctx);
    _brw_x690 = _x; /*int*/
  }
  bool _brw_x691 = kk_integer_lt_borrow(_brw_x690,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x690, _ctx);
  _match_x689 = _brw_x691; /*bool*/
  if (_match_x689) {
    kk_define_string_literal(, _s_x1788, 3, "BCE", _ctx)
    _x_x1787 = kk_string_dup(_s_x1788, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1789, 2, "CE", _ctx)
    _x_x1787 = kk_string_dup(_s_x1789, _ctx); /*string*/
  }
  return kk_string_box(_x_x1787);
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x1006;
    kk_define_string_literal(, _s_x1007, 3, "UTC", _ctx)
    _x_x1006 = kk_string_dup(_s_x1007, _ctx); /*string*/
    kk_std_time_calendar_tz_utc = kk_std_time_calendar__new_Timezone(kk_reuse_null, 0, _x_x1006, kk_std_time_calendar_new_tz_utc_fun1008(_ctx), kk_std_time_calendar_new_tz_utc_fun1012(_ctx), _ctx); /*std/time/calendar/timezone*/
  }
  {
    kk_string_t _x_x1398 = kk_string_empty(); /*string*/
    kk_string_t _x_x1400;
    kk_define_string_literal(, _s_x1401, 3, "ISO", _ctx)
    _x_x1400 = kk_string_dup(_s_x1401, _ctx); /*string*/
    kk_std_core_types__optional _x_x1418;
    kk_box_t _x_x1419;
    kk_integer_t _x_x1420;
    kk_std_core_types__optional _match_x770 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x770, _ctx)) {
      kk_box_t _box_x352 = _match_x770._cons._Optional.value;
      kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x352, _ctx);
      kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
      kk_std_core_types__optional_drop(_match_x770, _ctx);
      _x_x1420 = _uniq_epoch_shift_2171; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x770, _ctx);
      _x_x1420 = kk_integer_from_int(730119, _ctx); /*int*/
    }
    _x_x1419 = kk_integer_box(_x_x1420, _ctx); /*10003*/
    _x_x1418 = kk_std_core_types__new_Optional(_x_x1419, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1421;
    kk_box_t _x_x1422;
    bool _x_x1423;
    kk_std_core_types__optional _match_x769 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x769, _ctx)) {
      kk_box_t _box_x354 = _match_x769._cons._Optional.value;
      bool _uniq_has_year_zero_2175 = kk_bool_unbox(_box_x354);
      kk_std_core_types__optional_drop(_match_x769, _ctx);
      _x_x1423 = _uniq_has_year_zero_2175; /*bool*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x769, _ctx);
      _x_x1423 = true; /*bool*/
    }
    _x_x1422 = kk_bool_box(_x_x1423); /*10003*/
    _x_x1421 = kk_std_core_types__new_Optional(_x_x1422, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1424;
    kk_box_t _x_x1425;
    kk_string_t _x_x1426;
    kk_std_core_types__optional _match_x768 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x768, _ctx)) {
      kk_box_t _box_x356 = _match_x768._cons._Optional.value;
      kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x356);
      kk_string_dup(_uniq_month_prefix_2179, _ctx);
      kk_std_core_types__optional_drop(_match_x768, _ctx);
      _x_x1426 = _uniq_month_prefix_2179; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x768, _ctx);
      _x_x1426 = kk_string_empty(); /*string*/
    }
    _x_x1425 = kk_string_box(_x_x1426); /*10003*/
    _x_x1424 = kk_std_core_types__new_Optional(_x_x1425, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1428 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_cal_iso_fun1429(_ctx), _ctx), _ctx); /*? 10003*/
    kk_std_time_calendar_cal_iso = kk_std_time_calendar_solar_calendar(_x_x1398, _x_x1400, kk_std_time_calendar_new_cal_iso_fun1403(_ctx), kk_std_time_calendar_new_cal_iso_fun1404(_ctx), kk_std_time_calendar_new_cal_iso_fun1414(_ctx), kk_std_time_calendar_new_cal_iso_fun1417(_ctx), _x_x1418, _x_x1421, _x_x1424, _x_x1428, _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x1685;
    kk_define_string_literal(, _s_x1686, 3, "SLS", _ctx)
    _x_x1685 = kk_string_dup(_s_x1686, _ctx); /*string*/
    kk_string_t _x_x1687;
    kk_define_string_literal(, _s_x1688, 7, "ISO-SLS", _ctx)
    _x_x1687 = kk_string_dup(_s_x1688, _ctx); /*string*/
    kk_std_core_types__optional _x_x1705;
    kk_box_t _x_x1706;
    kk_integer_t _x_x1707;
    kk_std_core_types__optional _match_x711 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x711, _ctx)) {
      kk_box_t _box_x591 = _match_x711._cons._Optional.value;
      kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x591, _ctx);
      kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
      kk_std_core_types__optional_drop(_match_x711, _ctx);
      _x_x1707 = _uniq_epoch_shift_2171; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x711, _ctx);
      _x_x1707 = kk_integer_from_int(730119, _ctx); /*int*/
    }
    _x_x1706 = kk_integer_box(_x_x1707, _ctx); /*10003*/
    _x_x1705 = kk_std_core_types__new_Optional(_x_x1706, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1708;
    kk_box_t _x_x1709;
    bool _x_x1710;
    kk_std_core_types__optional _match_x710 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x710, _ctx)) {
      kk_box_t _box_x593 = _match_x710._cons._Optional.value;
      bool _uniq_has_year_zero_2175 = kk_bool_unbox(_box_x593);
      kk_std_core_types__optional_drop(_match_x710, _ctx);
      _x_x1710 = _uniq_has_year_zero_2175; /*bool*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x710, _ctx);
      _x_x1710 = true; /*bool*/
    }
    _x_x1709 = kk_bool_box(_x_x1710); /*10003*/
    _x_x1708 = kk_std_core_types__new_Optional(_x_x1709, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1711;
    kk_box_t _x_x1712;
    kk_string_t _x_x1713;
    kk_std_core_types__optional _match_x709 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x709, _ctx)) {
      kk_box_t _box_x595 = _match_x709._cons._Optional.value;
      kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x595);
      kk_string_dup(_uniq_month_prefix_2179, _ctx);
      kk_std_core_types__optional_drop(_match_x709, _ctx);
      _x_x1713 = _uniq_month_prefix_2179; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x709, _ctx);
      _x_x1713 = kk_string_empty(); /*string*/
    }
    _x_x1712 = kk_string_box(_x_x1713); /*10003*/
    _x_x1711 = kk_std_core_types__new_Optional(_x_x1712, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1715 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_cal_iso_sls_fun1716(_ctx), _ctx), _ctx); /*? 10003*/
    kk_std_time_calendar_cal_iso_sls = kk_std_time_calendar_solar_calendar(_x_x1685, _x_x1687, kk_std_time_calendar_new_cal_iso_sls_fun1690(_ctx), kk_std_time_calendar_new_cal_iso_sls_fun1691(_ctx), kk_std_time_calendar_new_cal_iso_sls_fun1701(_ctx), kk_std_time_calendar_new_cal_iso_sls_fun1704(_ctx), _x_x1705, _x_x1708, _x_x1711, _x_x1715, _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x1757;
    kk_define_string_literal(, _s_x1758, 2, "GC", _ctx)
    _x_x1757 = kk_string_dup(_s_x1758, _ctx); /*string*/
    kk_string_t _x_x1759;
    kk_define_string_literal(, _s_x1760, 9, "Gregorian", _ctx)
    _x_x1759 = kk_string_dup(_s_x1760, _ctx); /*string*/
    kk_std_core_types__optional _x_x1777;
    kk_box_t _x_x1778;
    kk_integer_t _x_x1779;
    kk_std_core_types__optional _match_x693 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x693, _ctx)) {
      kk_box_t _box_x669 = _match_x693._cons._Optional.value;
      kk_integer_t _uniq_epoch_shift_2171 = kk_integer_unbox(_box_x669, _ctx);
      kk_integer_dup(_uniq_epoch_shift_2171, _ctx);
      kk_std_core_types__optional_drop(_match_x693, _ctx);
      _x_x1779 = _uniq_epoch_shift_2171; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x693, _ctx);
      _x_x1779 = kk_integer_from_int(730119, _ctx); /*int*/
    }
    _x_x1778 = kk_integer_box(_x_x1779, _ctx); /*10003*/
    _x_x1777 = kk_std_core_types__new_Optional(_x_x1778, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1780 = kk_std_core_types__new_Optional(kk_bool_box(false), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1781;
    kk_box_t _x_x1782;
    kk_string_t _x_x1783;
    kk_std_core_types__optional _match_x692 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x692, _ctx)) {
      kk_box_t _box_x672 = _match_x692._cons._Optional.value;
      kk_string_t _uniq_month_prefix_2179 = kk_string_unbox(_box_x672);
      kk_string_dup(_uniq_month_prefix_2179, _ctx);
      kk_std_core_types__optional_drop(_match_x692, _ctx);
      _x_x1783 = _uniq_month_prefix_2179; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x692, _ctx);
      _x_x1783 = kk_string_empty(); /*string*/
    }
    _x_x1782 = kk_string_box(_x_x1783); /*10003*/
    _x_x1781 = kk_std_core_types__new_Optional(_x_x1782, _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x1785 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendar_new_cal_gregorian_fun1786(_ctx), _ctx), _ctx); /*? 10003*/
    kk_std_time_calendar_cal_gregorian = kk_std_time_calendar_solar_calendar(_x_x1757, _x_x1759, kk_std_time_calendar_new_cal_gregorian_fun1762(_ctx), kk_std_time_calendar_new_cal_gregorian_fun1763(_ctx), kk_std_time_calendar_new_cal_gregorian_fun1773(_ctx), kk_std_time_calendar_new_cal_gregorian_fun1776(_ctx), _x_x1777, _x_x1780, _x_x1781, _x_x1785, _ctx); /*std/time/calendar/calendar*/
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
