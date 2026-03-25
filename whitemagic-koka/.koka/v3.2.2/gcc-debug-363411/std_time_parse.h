#pragma once
#ifndef kk_std_time_parse_H
#define kk_std_time_parse_H
// Koka generated module: std/time/parse, koka version: 3.2.2, platform: 64-bit
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
#include "std_text_parse.h"
#include "std_num_ddouble.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_date.h"
#include "std_time_calendar.h"
#include "std_time_calendars.h"
#include "std_time_time.h"
#include "std_time_locale.h"
#include "std_time_utc.h"

// type declarations

// value declarations


// lift anonymous function
struct kk_std_time_parse_optchar_fun1394__t {
  struct kk_function_s _base;
  kk_char_t c;
};
extern kk_box_t kk_std_time_parse_optchar_fun1394(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse_new_optchar_fun1394(kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_time_parse_optchar_fun1394__t* _self = kk_function_alloc_as(struct kk_std_time_parse_optchar_fun1394__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_optchar_fun1394, kk_context());
  _self->c = c;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse_optchar_fun1396__t {
  struct kk_function_s _base;
  kk_char_t c;
};
extern kk_box_t kk_std_time_parse_optchar_fun1396(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse_new_optchar_fun1396(kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_time_parse_optchar_fun1396__t* _self = kk_function_alloc_as(struct kk_std_time_parse_optchar_fun1396__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse_optchar_fun1396, kk_context());
  _self->c = c;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_char_t kk_std_time_parse_optchar(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> std/text/parse/parse char */ 
  kk_box_t _x_x1393 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_optchar_fun1394(c, _ctx), kk_std_time_parse_new_optchar_fun1396(c, _ctx), _ctx); /*1542*/
  return kk_char_unbox(_x_x1393, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_dash_fun1398__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_parse_dash_fun1398(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse_new_dash_fun1398(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_dash_fun1398, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_dash_fun1400__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_parse_dash_fun1400(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse_new_dash_fun1400(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_dash_fun1400, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_char_t kk_std_time_parse_dash(kk_context_t* _ctx) { /* () -> std/text/parse/parse char */ 
  kk_box_t _x_x1397 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_dash_fun1398(_ctx), kk_std_time_parse_new_dash_fun1400(_ctx), _ctx); /*1542*/
  return kk_char_unbox(_x_x1397, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_parse_colon_fun1402__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_parse_colon_fun1402(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse_new_colon_fun1402(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_colon_fun1402, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_parse_colon_fun1404__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_parse_colon_fun1404(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse_new_colon_fun1404(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse_colon_fun1404, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_char_t kk_std_time_parse_colon(kk_context_t* _ctx) { /* () -> std/text/parse/parse char */ 
  kk_box_t _x_x1401 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse_new_colon_fun1402(_ctx), kk_std_time_parse_new_colon_fun1404(_ctx), _ctx); /*1542*/
  return kk_char_unbox(_x_x1401, KK_OWNED, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_num_10253(kk_std_core_types__list _y_x10049, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse_num(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> std/text/parse/parse int */ 

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10254(kk_integer_t tzmin, kk_integer_t _c_x10083, kk_context_t* _ctx); /* (tzmin : int, int) -> std/time/calendar/timezone */ 

kk_integer_t kk_std_time_parse__mlift_ptime_10255(kk_std_core_types__list _y_x10080, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10256(kk_char_t sign, kk_integer_t tzhour, kk_integer_t tzmin, kk_context_t* _ctx); /* (sign : char, tzhour : int, tzmin : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10257(kk_char_t sign, kk_integer_t tzhour, kk_char_t wild___3, kk_context_t* _ctx); /* (sign : char, tzhour : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 

kk_integer_t kk_std_time_parse__mlift_ptime_10258(kk_std_core_types__list _y_x10074, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10259(kk_char_t sign, kk_integer_t tzhour, kk_context_t* _ctx); /* (sign : char, tzhour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10260(kk_char_t sign, kk_context_t* _ctx); /* (sign : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
 
// monadic lift

static inline kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_10261(kk_char_t wild___4, kk_context_t* _ctx) { /* (wild_@4 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
  return kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10262(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_std_num_ddouble__ddouble secs, kk_std_time_calendar__timezone tzone, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int, secs : std/num/ddouble/ddouble, tzone : std/time/calendar/timezone) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10263(kk_integer_t s, kk_std_num_ddouble__ddouble _c_x10071, kk_context_t* _ctx); /* (s : int, std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */ 
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_ptime_10264_fun1491__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_parse__mlift_ptime_10264_fun1491(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse__new_mlift_ptime_10264_fun1491(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_parse__mlift_ptime_10264_fun1491, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_string_t kk_std_time_parse__mlift_ptime_10264(kk_char_t wild___2, kk_context_t* _ctx) { /* (wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> string */ 
  kk_ssize_t _b_x164_166 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_box_t _x_x1490 = kk_std_core_hnd__open_at0(_b_x164_166, kk_std_time_parse__new_mlift_ptime_10264_fun1491(_ctx), _ctx); /*10426*/
  return kk_string_unbox(_x_x1490);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10265(kk_integer_t s, kk_string_t f, kk_context_t* _ctx); /* (s : int, f : string) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 

kk_integer_t kk_std_time_parse__mlift_ptime_10266(kk_std_core_types__list _y_x10065, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_10267(kk_integer_t s, kk_context_t* _ctx); /* (s : int) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10268(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int, secs : std/num/ddouble/ddouble) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10269(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_char_t wild___1, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_integer_t kk_std_time_parse__mlift_ptime_10270(kk_std_core_types__list _y_x10058, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10271(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t min, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, min : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10272(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_char_t wild___0, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_integer_t kk_std_time_parse__mlift_ptime_10273(kk_std_core_types__list _y_x10052, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10274(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_10275(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_char_t wild__, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse_ptime(kk_std_time_date__date date, kk_std_time_calendar__calendar cal, kk_context_t* _ctx); /* (date : std/time/date/date, cal : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift


// lift anonymous function
struct kk_std_time_parse__mlift_piso_10276_fun1774__t {
  struct kk_function_s _base;
  kk_std_time_calendar__calendar cal;
  kk_std_time_date__date date;
};
extern kk_box_t kk_std_time_parse__mlift_piso_10276_fun1774(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse__new_mlift_piso_10276_fun1774(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10276_fun1774__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10276_fun1774__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10276_fun1774, kk_context());
  _self->cal = cal;
  _self->date = date;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_parse__mlift_piso_10276_fun1776__t {
  struct kk_function_s _base;
  kk_std_time_time__time default_4_10039;
};
extern kk_box_t kk_std_time_parse__mlift_piso_10276_fun1776(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_parse__new_mlift_piso_10276_fun1776(kk_std_time_time__time default_4_10039, kk_context_t* _ctx) {
  struct kk_std_time_parse__mlift_piso_10276_fun1776__t* _self = kk_function_alloc_as(struct kk_std_time_parse__mlift_piso_10276_fun1776__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_parse__mlift_piso_10276_fun1776, kk_context());
  _self->default_4_10039 = default_4_10039;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_time_time__time kk_std_time_parse__mlift_piso_10276(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time default_4_10039, kk_context_t* _ctx) { /* (cal : std/time/calendar/calendar, date : std/time/date/date, default@4@10039 : std/time/time/time) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time */ 
  kk_box_t _x_x1773 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_parse__new_mlift_piso_10276_fun1774(cal, date, _ctx), kk_std_time_parse__new_mlift_piso_10276_fun1776(default_4_10039, _ctx), _ctx); /*1542*/
  return kk_std_time_time__time_unbox(_x_x1773, KK_OWNED, _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10277(kk_std_core_types__list _y_x10100, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10278(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_integer_t d_2, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, m : int, year : int, d@2 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x1780;
  kk_std_time_date__date _x_x1781 = kk_std_time_date__new_Date(year, m, d_2, _ctx); /*std/time/date/date*/
  _x_x1780 = kk_std_time_date__date_box(_x_x1781, _ctx); /*134*/
  return kk_std_core_types__new_Tuple2(_x_x1780, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10279(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_char_t wild___0, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, m : int, year : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_integer_t kk_std_time_parse__mlift_piso_10280(kk_std_core_types__list _y_x10094, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10281(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_integer_t m, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, year : int, m : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_integer_t kk_std_time_parse__mlift_piso_10282(kk_std_core_types__list _y_x10110, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10283(kk_integer_t w, kk_integer_t year, kk_integer_t d_0_0, kk_context_t* _ctx) { /* (w : int, year : int, d@0@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x1815;
  kk_std_time_date__date _x_x1816 = kk_std_time_date__new_Date(year, w, d_0_0, _ctx); /*std/time/date/date*/
  _x_x1815 = kk_std_time_date__date_box(_x_x1816, _ctx); /*134*/
  kk_box_t _x_x1817;
  kk_std_time_calendar__calendar _x_x1818 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_week, _ctx); /*std/time/calendar/calendar*/
  _x_x1817 = kk_std_time_calendar__calendar_box(_x_x1818, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x1815, _x_x1817, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10284(kk_integer_t w, kk_integer_t year, kk_char_t wild___2, kk_context_t* _ctx); /* (w : int, year : int, wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_integer_t kk_std_time_parse__mlift_piso_10285(kk_std_core_types__list _y_x10104, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10286(kk_integer_t year, kk_integer_t w, kk_context_t* _ctx); /* (year : int, w : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10287(kk_integer_t year, kk_char_t wild___1, kk_context_t* _ctx); /* (year : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_integer_t kk_std_time_parse__mlift_piso_10288(kk_std_core_types__list _y_x10114, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10289(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_integer_t d_1_0, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int, d@1@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x1871;
  kk_std_time_date__date _x_x1872 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_1_0, _ctx); /*std/time/date/date*/
  _x_x1871 = kk_std_time_date__date_box(_x_x1872, _ctx); /*134*/
  return kk_std_core_types__new_Tuple2(_x_x1871, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}

kk_integer_t kk_std_time_parse__mlift_piso_10290(kk_std_core_types__list _y_x10124, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10291(kk_integer_t m_0, kk_integer_t year, kk_integer_t d_2_0, kk_context_t* _ctx) { /* (m@0 : int, year : int, d@2@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x1876;
  kk_std_time_date__date _x_x1877 = kk_std_time_date__new_Date(year, m_0, d_2_0, _ctx); /*std/time/date/date*/
  _x_x1876 = kk_std_time_date__date_box(_x_x1877, _ctx); /*134*/
  kk_box_t _x_x1878;
  kk_std_time_calendar__calendar _x_x1879 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x1878 = kk_std_time_calendar__calendar_box(_x_x1879, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x1876, _x_x1878, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10292(kk_integer_t m_0, kk_integer_t year, kk_char_t wild___4, kk_context_t* _ctx); /* (m@0 : int, year : int, wild_@4 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_integer_t kk_std_time_parse__mlift_piso_10293(kk_std_core_types__list _y_x10118, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10294(kk_integer_t year, kk_integer_t m_0, kk_context_t* _ctx); /* (year : int, m@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10295(kk_integer_t year, kk_char_t wild___3, kk_context_t* _ctx); /* (year : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_integer_t kk_std_time_parse__mlift_piso_10296(kk_std_core_types__list _y_x10128, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10297(kk_integer_t year, kk_integer_t d_3_0, kk_context_t* _ctx) { /* (year : int, d@3@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x1930;
  kk_std_time_date__date _x_x1931 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_3_0, _ctx); /*std/time/date/date*/
  _x_x1930 = kk_std_time_date__date_box(_x_x1931, _ctx); /*134*/
  kk_box_t _x_x1932;
  kk_std_time_calendar__calendar _x_x1933 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x1932 = kk_std_time_calendar__calendar_box(_x_x1933, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x1930, _x_x1932, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_10298(kk_integer_t year, kk_char_t wild___5, kk_context_t* _ctx); /* (year : int, wild_@5 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_std_time_time__time kk_std_time_parse__mlift_piso_10299(kk_std_core_types__tuple2 _y_x10131, kk_context_t* _ctx); /* ((std/time/date/date, std/time/calendar/calendar)) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_piso_10300(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_char_t wild__, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, year : int, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_integer_t kk_std_time_parse__mlift_piso_10301(kk_std_core_types__list _y_x10088, kk_context_t* _ctx); /* (list<int>) -> std/text/parse/parse int */ 

kk_std_time_time__time kk_std_time_parse__mlift_piso_10302(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, year : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse_piso(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift

static inline kk_std_time_time__time kk_std_time_parse__mlift_parse_iso_10303(kk_std_time_time__time x, kk_unit_t wild__, kk_context_t* _ctx) { /* (x : std/time/time/time, wild_ : ()) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
  return x;
}

kk_std_time_time__time kk_std_time_parse__mlift_parse_iso_10304(kk_std_time_time__time x, kk_context_t* _ctx); /* (x : std/time/time/time) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_core_types__maybe kk_std_time_parse__mlift_parse_iso_10305(kk_std_text_parse__parse_error _y_x10138, kk_context_t* _ctx); /* (std/text/parse/parse-error<std/time/time/time>) -> std/time/utc/utc maybe<std/time/time/time> */ 

kk_std_core_types__maybe kk_std_time_parse_parse_iso(kk_string_t s, kk_std_core_types__optional calendar, kk_context_t* _ctx); /* (s : string, calendar : ? std/time/calendar/calendar) -> std/time/utc/utc maybe<std/time/time/time> */ 

void kk_std_time_parse__init(kk_context_t* _ctx);


void kk_std_time_parse__done(kk_context_t* _ctx);

#endif // header
