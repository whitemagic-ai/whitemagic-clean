#pragma once
#ifndef kk_std_time_calendars_H
#define kk_std_time_calendars_H
// Koka generated module: std/time/calendars, koka version: 3.2.2, platform: 64-bit
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
#include "std_time_instant.h"
#include "std_time_utc.h"
#include "std_time_date.h"
#include "std_time_calendar.h"
#include "std_time_duration.h"

// type declarations

// value declarations

static inline kk_integer_t kk_std_time_calendars_coptic_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx) { /* (year : int, month : int) -> int */ 
  kk_integer_drop(year, _ctx);
  kk_integer_t _x_x99 = kk_integer_add_small_const(month, -1, _ctx); /*int*/
  return kk_integer_mul((kk_integer_from_small(30)),_x_x99,kk_context());
}

static inline kk_integer_t kk_std_time_calendars_coptic_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx) { /* (year : int, doy : int) -> int */ 
  kk_integer_drop(year, _ctx);
  kk_integer_t x_10002 = kk_integer_div(doy,(kk_integer_from_small(30)),kk_context()); /*int*/;
  return kk_integer_add_small_const(x_10002, 1, _ctx);
}

static inline kk_integer_t kk_std_time_calendars_coptic_days_before_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> int */ 
  kk_integer_t x_10004;
  kk_integer_t _x_x100;
  kk_integer_t _x_x101 = kk_integer_dup(year, _ctx); /*int*/
  _x_x100 = kk_integer_add_small_const(_x_x101, -1, _ctx); /*int*/
  x_10004 = kk_integer_mul((kk_integer_from_small(365)),_x_x100,kk_context()); /*int*/
  kk_integer_t y_10005 = kk_integer_div(year,(kk_integer_from_small(4)),kk_context()); /*int*/;
  return kk_integer_add(x_10004,y_10005,kk_context());
}

kk_std_core_types__tuple2 kk_std_time_calendars_coptic_estimate_year(kk_integer_t days, kk_context_t* _ctx); /* (days : int) -> (int, maybe<int>) */ 

extern kk_std_time_calendar__calendar kk_std_time_calendars_cal_coptic;

kk_std_core_types__tuple2 kk_std_time_calendars_coptic_days_to_yeardoy(kk_integer_t days, kk_context_t* _ctx); /* (days : int) -> (int, int) */ 

extern kk_std_time_calendar__calendar kk_std_time_calendars_cal_ethiopian;

static inline kk_integer_t kk_std_time_calendars_isow_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx) { /* (year : int, month : int) -> int */ 
  kk_integer_drop(year, _ctx);
  kk_integer_t _x_x134 = kk_integer_add_small_const(month, -1, _ctx); /*int*/
  return kk_integer_mul((kk_integer_from_small(7)),_x_x134,kk_context());
}

static inline kk_integer_t kk_std_time_calendars_isow_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx) { /* (year : int, doy : int) -> int */ 
  kk_integer_drop(year, _ctx);
  kk_integer_t x_10023 = kk_integer_div(doy,(kk_integer_from_small(7)),kk_context()); /*int*/;
  return kk_integer_add_small_const(x_10023, 1, _ctx);
}

kk_integer_t kk_std_time_calendars_iso_days_before_year(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> int */ 

kk_integer_t kk_std_time_calendars_isow_days_before_year(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> int */ 

kk_std_core_types__tuple2 kk_std_time_calendars_iso_estimate_year(kk_integer_t days, kk_context_t* _ctx); /* (days : int) -> (int, maybe<int>) */ 

kk_std_core_types__tuple2 kk_std_time_calendars_isow_estimate_year(kk_integer_t days, kk_context_t* _ctx); /* (days : int) -> (int, maybe<int>) */ 

extern kk_std_time_calendar__calendar kk_std_time_calendars_cal_iso_week;

kk_integer_t kk_std_time_calendars_isom_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx); /* (year : int, month : int) -> int */ 

kk_integer_t kk_std_time_calendars_isom_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx); /* (year : int, doy : int) -> int */ 

extern kk_std_time_calendar__calendar kk_std_time_calendars_cal_iso_month;

kk_integer_t kk_std_time_calendars_julian_adjust(bool is_before_march, kk_integer_t year, kk_context_t* _ctx); /* (is-before-march : bool, year : int) -> int */ 

kk_integer_t kk_std_time_calendars_julian_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx); /* (year : int, month : int) -> int */ 

kk_integer_t kk_std_time_calendars_julian_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx); /* (year : int, doy : int) -> int */ 

kk_integer_t kk_std_time_calendars_julian_days_before_year(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> int */ 

kk_std_core_types__tuple2 kk_std_time_calendars_julian_estimate_year(kk_integer_t days, kk_context_t* _ctx); /* (days : int) -> (int, maybe<int>) */ 

extern kk_std_time_calendar__calendar kk_std_time_calendars_cal_julian;

kk_std_time_calendar__calendar kk_std_time_calendars_julian_gregorian(kk_std_core_types__optional switch_date, kk_context_t* _ctx); /* (switch-date : ? std/time/date/date) -> std/time/calendar/calendar */ 

extern kk_std_time_calendar__calendar kk_std_time_calendars_cal_jg;

void kk_std_time_calendars__init(kk_context_t* _ctx);


void kk_std_time_calendars__done(kk_context_t* _ctx);

#endif // header
