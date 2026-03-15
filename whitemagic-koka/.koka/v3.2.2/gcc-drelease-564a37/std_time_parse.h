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
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_optchar_11094(kk_char_t c, bool _y_x10668, kk_context_t* _ctx) { /* (c : char, bool) -> std/text/parse/parse char */ 
  if (_y_x10668) {
    return kk_std_text_parse_char(c, _ctx);
  }
  {
    return c;
  }
}

kk_char_t kk_std_time_parse_optchar(kk_char_t c, kk_context_t* _ctx); /* (c : char) -> std/text/parse/parse char */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_dash_11095(bool _y_x10671, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10671) {
    return kk_std_text_parse_char('-', _ctx);
  }
  {
    return '-';
  }
}

kk_char_t kk_std_time_parse_dash(kk_context_t* _ctx); /* () -> std/text/parse/parse char */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_colon_11096(bool _y_x10674, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10674) {
    return kk_std_text_parse_char(':', _ctx);
  }
  {
    return ':';
  }
}

kk_char_t kk_std_time_parse_colon(kk_context_t* _ctx); /* () -> std/text/parse/parse char */ 

kk_integer_t kk_std_time_parse__lift_num_10609(kk_std_core_types__list _uniq_xs_10149, kk_integer_t _uniq_z_10150, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_num_10608(kk_std_core_types__list _uniq_xs_10143, kk_integer_t _uniq_z_10144, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_num_10611_11097(kk_std_core_types__list _uniq_acc_10163, kk_integer_t _uniq_n_10162, kk_integer_t _uniq_x_10170, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_num_10611(kk_integer_t _uniq_n_10162_0, kk_std_core_types__list _uniq_acc_10163_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_num_10610(kk_integer_t _uniq_n_10159, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_num_11098(kk_std_core_types__list _y_x10685, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_num_10608(_y_x10685, kk_integer_from_small(0), _ctx);
}

kk_integer_t kk_std_time_parse_num(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_ptime_10613(kk_std_core_types__list _uniq_xs_10180, kk_integer_t _uniq_z_10181, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_ptime_10612(kk_std_core_types__list _uniq_xs_10174, kk_integer_t _uniq_z_10175, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10615_11099(kk_std_core_types__list _uniq_acc_10194, kk_integer_t _uniq_n_10193, kk_integer_t _uniq_x_10201, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10615(kk_integer_t _uniq_n_10193_0, kk_std_core_types__list _uniq_acc_10194_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10614(kk_integer_t _uniq_n_10190, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_ptime_10617(kk_std_core_types__list _uniq_xs_10211, kk_integer_t _uniq_z_10212, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_ptime_10616(kk_std_core_types__list _uniq_xs_10205, kk_integer_t _uniq_z_10206, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10619_11100(kk_std_core_types__list _uniq_acc_10225, kk_integer_t _uniq_n_10224, kk_integer_t _uniq_x_10232, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10619(kk_integer_t _uniq_n_10224_0, kk_std_core_types__list _uniq_acc_10225_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10618(kk_integer_t _uniq_n_10221, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_ptime_10621(kk_std_core_types__list _uniq_xs_10242, kk_integer_t _uniq_z_10243, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_ptime_10620(kk_std_core_types__list _uniq_xs_10236, kk_integer_t _uniq_z_10237, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10623_11101(kk_std_core_types__list _uniq_acc_10256, kk_integer_t _uniq_n_10255, kk_integer_t _uniq_x_10263, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10623(kk_integer_t _uniq_n_10255_0, kk_std_core_types__list _uniq_acc_10256_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10622(kk_integer_t _uniq_n_10252, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_ptime_10625(kk_std_core_types__list _uniq_xs_10273, kk_integer_t _uniq_z_10274, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_ptime_10624(kk_std_core_types__list _uniq_xs_10267, kk_integer_t _uniq_z_10268, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10627_11102(kk_std_core_types__list _uniq_acc_10287, kk_integer_t _uniq_n_10286, kk_integer_t _uniq_x_10294, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10627(kk_integer_t _uniq_n_10286_0, kk_std_core_types__list _uniq_acc_10287_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10626(kk_integer_t _uniq_n_10283, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_ptime_10629(kk_std_core_types__list _uniq_xs_10304, kk_integer_t _uniq_z_10305, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_ptime_10628(kk_std_core_types__list _uniq_xs_10298, kk_integer_t _uniq_z_10299, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_ptime_10631_11103(kk_std_core_types__list _uniq_acc_10318, kk_integer_t _uniq_n_10317, kk_integer_t _uniq_x_10325, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10631(kk_integer_t _uniq_n_10317_0, kk_std_core_types__list _uniq_acc_10318_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_ptime_10630(kk_integer_t _uniq_n_10314, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 
 
// monadic lift

static inline kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11104(kk_integer_t tzmin, kk_integer_t _c_x10768, kk_context_t* _ctx) { /* (tzmin : int, int) -> std/time/calendar/timezone */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<std/text/parse/parse,std/time/utc/utc>>*/;
  kk_std_time_calendar__timezone x;
  kk_std_core_types__optional _x_x2114 = kk_std_core_types__new_Optional(kk_integer_box(tzmin, _ctx), _ctx); /*? 10003*/
  x = kk_std_time_calendar_tz_fixed(_c_x10768, _x_x2114, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/timezone*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_ptime_11105(kk_std_core_types__list _y_x10765, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_ptime_10628(_y_x10765, kk_integer_from_small(0), _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11106(kk_char_t sign, kk_integer_t tzhour, kk_integer_t tzmin, kk_context_t* _ctx); /* (sign : char, tzhour : int, tzmin : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_ptime_11107(bool _y_x10761, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10761) {
    return kk_std_text_parse_char(':', _ctx);
  }
  {
    return ':';
  }
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11108(kk_char_t sign, kk_integer_t tzhour, kk_char_t wild___3, kk_context_t* _ctx); /* (sign : char, tzhour : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_ptime_11109(kk_std_core_types__list _y_x10758, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_ptime_10624(_y_x10758, kk_integer_from_small(0), _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11110(kk_char_t sign, kk_integer_t tzhour, kk_context_t* _ctx); /* (sign : char, tzhour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11111(kk_char_t sign, kk_context_t* _ctx); /* (sign : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 
 
// monadic lift

static inline kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11112(kk_char_t _c_x10772, kk_context_t* _ctx) { /* (char) -> std/time/calendar/timezone */ 
  return kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx);
}

kk_std_time_calendar__timezone kk_std_time_parse__mlift_ptime_11113(bool _y_x10770, kk_context_t* _ctx); /* (bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/calendar/timezone */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11114(kk_integer_t _c_x10740, kk_std_num_ddouble__ddouble _c_x10756, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_std_time_calendar__timezone _c_x10776, kk_context_t* _ctx); /* (int, std/num/ddouble/ddouble, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, std/time/calendar/timezone) -> std/time/time/time */ 

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11115(kk_integer_t s, kk_std_num_ddouble__ddouble _c_x10755, kk_context_t* _ctx); /* (s : int, std/num/ddouble/ddouble) -> std/num/ddouble/ddouble */ 

kk_string_t kk_std_time_parse__mlift_ptime_11116(kk_char_t wild___2, kk_context_t* _ctx); /* (wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> string */ 

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11117(kk_integer_t s, kk_string_t _c_x10754, kk_context_t* _ctx); /* (s : int, string) -> std/num/ddouble/ddouble */ 

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11118(kk_integer_t s, bool _y_x10751, kk_context_t* _ctx); /* (s : int, bool) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_ptime_11119(kk_std_core_types__list _y_x10747, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_ptime_10620(_y_x10747, kk_integer_from_small(0), _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_parse__mlift_ptime_11120(kk_integer_t s, kk_context_t* _ctx); /* (s : int) -> <std/text/parse/parse,std/time/utc/utc> std/num/ddouble/ddouble */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11121(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_std_num_ddouble__ddouble _c_x10756, kk_context_t* _ctx); /* (int, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, std/num/ddouble/ddouble) -> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11122(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, bool _y_x10746, kk_context_t* _ctx); /* (int, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_ptime_11123(bool _y_x10741, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10741) {
    return kk_std_text_parse_char(':', _ctx);
  }
  {
    return ':';
  }
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11124(kk_integer_t _c_x10740, kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_char_t wild___1, kk_context_t* _ctx); /* (int, cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_ptime_11125(kk_std_core_types__list _y_x10737, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_ptime_10616(_y_x10737, kk_integer_from_small(0), _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11126(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_integer_t _c_x10740, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, int) -> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11127(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, bool _y_x10736, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_ptime_11128(bool _y_x10731, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10731) {
    return kk_std_text_parse_char(':', _ctx);
  }
  {
    return ':';
  }
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11129(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_char_t wild___0, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_ptime_11130(kk_std_core_types__list _y_x10728, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_ptime_10612(_y_x10728, kk_integer_from_small(0), _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11131(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_integer_t hour, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, hour : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_ptime_11132(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_char_t wild__, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse_ptime(kk_std_time_date__date date, kk_std_time_calendar__calendar cal, kk_context_t* _ctx); /* (date : std/time/date/date, cal : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_integer_t kk_std_time_parse__lift_piso_10633(kk_std_core_types__list _uniq_xs_10335, kk_integer_t _uniq_z_10336, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10632(kk_std_core_types__list _uniq_xs_10329, kk_integer_t _uniq_z_10330, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10635_11133(kk_std_core_types__list _uniq_acc_10349, kk_integer_t _uniq_n_10348, kk_integer_t _uniq_x_10356, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10635(kk_integer_t _uniq_n_10348_0, kk_std_core_types__list _uniq_acc_10349_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10634(kk_integer_t _uniq_n_10345, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10637(kk_std_core_types__list _uniq_xs_10366, kk_integer_t _uniq_z_10367, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10636(kk_std_core_types__list _uniq_xs_10360, kk_integer_t _uniq_z_10361, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10639_11134(kk_std_core_types__list _uniq_acc_10380, kk_integer_t _uniq_n_10379, kk_integer_t _uniq_x_10387, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10639(kk_integer_t _uniq_n_10379_0, kk_std_core_types__list _uniq_acc_10380_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10638(kk_integer_t _uniq_n_10376, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10641(kk_std_core_types__list _uniq_xs_10397, kk_integer_t _uniq_z_10398, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10640(kk_std_core_types__list _uniq_xs_10391, kk_integer_t _uniq_z_10392, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10643_11135(kk_std_core_types__list _uniq_acc_10411, kk_integer_t _uniq_n_10410, kk_integer_t _uniq_x_10418, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10643(kk_integer_t _uniq_n_10410_0, kk_std_core_types__list _uniq_acc_10411_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10642(kk_integer_t _uniq_n_10407, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10645(kk_std_core_types__list _uniq_xs_10428, kk_integer_t _uniq_z_10429, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10644(kk_std_core_types__list _uniq_xs_10422, kk_integer_t _uniq_z_10423, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10647_11136(kk_std_core_types__list _uniq_acc_10442, kk_integer_t _uniq_n_10441, kk_integer_t _uniq_x_10449, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10647(kk_integer_t _uniq_n_10441_0, kk_std_core_types__list _uniq_acc_10442_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10646(kk_integer_t _uniq_n_10438, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10649(kk_std_core_types__list _uniq_xs_10459, kk_integer_t _uniq_z_10460, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10648(kk_std_core_types__list _uniq_xs_10453, kk_integer_t _uniq_z_10454, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10651_11137(kk_std_core_types__list _uniq_acc_10473, kk_integer_t _uniq_n_10472, kk_integer_t _uniq_x_10480, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10651(kk_integer_t _uniq_n_10472_0, kk_std_core_types__list _uniq_acc_10473_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10650(kk_integer_t _uniq_n_10469, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10653(kk_std_core_types__list _uniq_xs_10490, kk_integer_t _uniq_z_10491, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10652(kk_std_core_types__list _uniq_xs_10484, kk_integer_t _uniq_z_10485, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10655_11138(kk_std_core_types__list _uniq_acc_10504, kk_integer_t _uniq_n_10503, kk_integer_t _uniq_x_10511, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10655(kk_integer_t _uniq_n_10503_0, kk_std_core_types__list _uniq_acc_10504_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10654(kk_integer_t _uniq_n_10500, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10657(kk_std_core_types__list _uniq_xs_10521, kk_integer_t _uniq_z_10522, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10656(kk_std_core_types__list _uniq_xs_10515, kk_integer_t _uniq_z_10516, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10659_11139(kk_std_core_types__list _uniq_acc_10535, kk_integer_t _uniq_n_10534, kk_integer_t _uniq_x_10542, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10659(kk_integer_t _uniq_n_10534_0, kk_std_core_types__list _uniq_acc_10535_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10658(kk_integer_t _uniq_n_10531, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10661(kk_std_core_types__list _uniq_xs_10552, kk_integer_t _uniq_z_10553, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10660(kk_std_core_types__list _uniq_xs_10546, kk_integer_t _uniq_z_10547, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10663_11140(kk_std_core_types__list _uniq_acc_10566, kk_integer_t _uniq_n_10565, kk_integer_t _uniq_x_10573, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10663(kk_integer_t _uniq_n_10565_0, kk_std_core_types__list _uniq_acc_10566_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10662(kk_integer_t _uniq_n_10562, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 

kk_integer_t kk_std_time_parse__lift_piso_10665(kk_std_core_types__list _uniq_xs_10583, kk_integer_t _uniq_z_10584, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_integer_t kk_std_time_parse__lift_piso_10664(kk_std_core_types__list _uniq_xs_10577, kk_integer_t _uniq_z_10578, kk_context_t* _ctx); /* (list<int>, int) -> std/text/parse/parse int */ 

kk_std_core_types__list kk_std_time_parse__mlift_lift_piso_10667_11141(kk_std_core_types__list _uniq_acc_10597, kk_integer_t _uniq_n_10596, kk_integer_t _uniq_x_10604, kk_context_t* _ctx); /* (list<int>, int, int) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10667(kk_integer_t _uniq_n_10596_0, kk_std_core_types__list _uniq_acc_10597_0, kk_context_t* _ctx); /* (int, list<int>) -> std/text/parse/parse list<int> */ 

kk_std_core_types__list kk_std_time_parse__lift_piso_10666(kk_integer_t _uniq_n_10593, kk_context_t* _ctx); /* (int) -> std/text/parse/parse list<int> */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11142(kk_std_core_types__list _y_x10864, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10640(_y_x10864, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11143(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_integer_t d_2, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, m : int, year : int, d@2 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x2503;
  kk_std_time_date__date _x_x2504 = kk_std_time_date__new_Date(year, m, d_2, _ctx); /*std/time/date/date*/
  _x_x2503 = kk_std_time_date__date_box(_x_x2504, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x2503, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_piso_11144(bool _y_x10860, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10860) {
    return kk_std_text_parse_char('-', _ctx);
  }
  {
    return '-';
  }
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11145(kk_std_time_calendar__calendar calendar, kk_integer_t m, kk_integer_t year, kk_char_t wild___0, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, m : int, year : int, wild_@0 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11146(kk_std_core_types__list _y_x10857, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10636(_y_x10857, kk_integer_from_small(0), _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11147(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_integer_t m, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, year : int, m : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11148(kk_std_core_types__list _y_x10877, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10648(_y_x10877, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11149(kk_integer_t w, kk_integer_t year, kk_integer_t _c_x10880, kk_context_t* _ctx) { /* (w : int, year : int, int) -> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x2529;
  kk_std_time_date__date _x_x2530 = kk_std_time_date__new_Date(year, w, _c_x10880, _ctx); /*std/time/date/date*/
  _x_x2529 = kk_std_time_date__date_box(_x_x2530, _ctx); /*10037*/
  kk_box_t _x_x2531;
  kk_std_time_calendar__calendar _x_x2532 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_week, _ctx); /*std/time/calendar/calendar*/
  _x_x2531 = kk_std_time_calendar__calendar_box(_x_x2532, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x2529, _x_x2531, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11150(kk_integer_t w, kk_integer_t year, bool _y_x10876, kk_context_t* _ctx); /* (w : int, year : int, bool) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_piso_11151(bool _y_x10871, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10871) {
    return kk_std_text_parse_char('-', _ctx);
  }
  {
    return '-';
  }
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11152(kk_integer_t w, kk_integer_t year, kk_char_t wild___2, kk_context_t* _ctx); /* (w : int, year : int, wild_@2 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11153(kk_std_core_types__list _y_x10868, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10644(_y_x10868, kk_integer_from_small(0), _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11154(kk_integer_t year, kk_integer_t w, kk_context_t* _ctx); /* (year : int, w : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11155(kk_integer_t year, kk_char_t wild___1, kk_context_t* _ctx); /* (year : int, wild_@1 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11156(kk_std_core_types__list _y_x10881, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10652(_y_x10881, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11157(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_integer_t d_1_0, kk_context_t* _ctx) { /* (calendar : std/time/calendar/calendar, year : int, d@1@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x2575;
  kk_std_time_date__date _x_x2576 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_1_0, _ctx); /*std/time/date/date*/
  _x_x2575 = kk_std_time_date__date_box(_x_x2576, _ctx); /*10037*/
  return kk_std_core_types__new_Tuple2(_x_x2575, kk_std_time_calendar__calendar_box(calendar, _ctx), _ctx);
}
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11158(kk_std_core_types__list _y_x10892, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10660(_y_x10892, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11159(kk_integer_t m_0, kk_integer_t year, kk_integer_t d_2_0, kk_context_t* _ctx) { /* (m@0 : int, year : int, d@2@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x2577;
  kk_std_time_date__date _x_x2578 = kk_std_time_date__new_Date(year, m_0, d_2_0, _ctx); /*std/time/date/date*/
  _x_x2577 = kk_std_time_date__date_box(_x_x2578, _ctx); /*10037*/
  kk_box_t _x_x2579;
  kk_std_time_calendar__calendar _x_x2580 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x2579 = kk_std_time_calendar__calendar_box(_x_x2580, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x2577, _x_x2579, _ctx);
}
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_piso_11160(bool _y_x10888, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10888) {
    return kk_std_text_parse_char('-', _ctx);
  }
  {
    return '-';
  }
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11161(kk_integer_t m_0, kk_integer_t year, kk_char_t wild___4, kk_context_t* _ctx); /* (m@0 : int, year : int, wild_@4 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11162(kk_std_core_types__list _y_x10885, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10656(_y_x10885, kk_integer_from_small(0), _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11163(kk_integer_t year, kk_integer_t m_0, kk_context_t* _ctx); /* (year : int, m@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11164(kk_integer_t year, kk_char_t wild___3, kk_context_t* _ctx); /* (year : int, wild_@3 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11165(kk_std_core_types__list _y_x10896, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10664(_y_x10896, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11166(kk_integer_t year, kk_integer_t d_3_0, kk_context_t* _ctx) { /* (year : int, d@3@0 : int) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 
  kk_box_t _x_x2616;
  kk_std_time_date__date _x_x2617 = kk_std_time_date__new_Date(year, kk_integer_from_small(1), d_3_0, _ctx); /*std/time/date/date*/
  _x_x2616 = kk_std_time_date__date_box(_x_x2617, _ctx); /*10037*/
  kk_box_t _x_x2618;
  kk_std_time_calendar__calendar _x_x2619 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_iso_month, _ctx); /*std/time/calendar/calendar*/
  _x_x2618 = kk_std_time_calendar__calendar_box(_x_x2619, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x2616, _x_x2618, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_parse__mlift_piso_11167(kk_integer_t year, kk_char_t wild___5, kk_context_t* _ctx); /* (year : int, wild_@5 : char) -> <std/text/parse/parse,std/time/utc/utc> (std/time/date/date, std/time/calendar/calendar) */ 

kk_std_time_time__time kk_std_time_parse__mlift_piso_11168(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time default_4_10041, bool _y_x10905, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, default@4@10041 : std/time/time/time, bool) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_piso_11169(kk_std_time_calendar__calendar cal, kk_std_time_date__date date, kk_std_time_time__time default_4_10041, kk_context_t* _ctx); /* (cal : std/time/calendar/calendar, date : std/time/date/date, default@4@10041 : std/time/time/time) -> <std/time/utc/utc,std/text/parse/parse> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse__mlift_piso_11170(kk_std_core_types__tuple2 _c_x10902, kk_context_t* _ctx); /* ((std/time/date/date, std/time/calendar/calendar)) -> std/time/time/time */ 
 
// monadic lift

static inline kk_char_t kk_std_time_parse__mlift_piso_11171(bool _y_x10853, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse char */ 
  if (_y_x10853) {
    return kk_std_text_parse_char('-', _ctx);
  }
  {
    return '-';
  }
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_11172(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_char_t wild__, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, year : int, wild_ : char) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 
 
// monadic lift

static inline kk_integer_t kk_std_time_parse__mlift_piso_11173(kk_std_core_types__list _y_x10850, kk_context_t* _ctx) { /* (list<int>) -> std/text/parse/parse int */ 
  return kk_std_time_parse__lift_piso_10632(_y_x10850, kk_integer_from_small(0), _ctx);
}

kk_std_time_time__time kk_std_time_parse__mlift_piso_11174(kk_std_time_calendar__calendar calendar, kk_integer_t year, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar, year : int) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_time_time__time kk_std_time_parse_piso(kk_std_time_calendar__calendar calendar, kk_context_t* _ctx); /* (calendar : std/time/calendar/calendar) -> <std/text/parse/parse,std/time/utc/utc> std/time/time/time */ 

kk_std_core_types__maybe kk_std_time_parse__mlift_parse_iso_11175(kk_std_text_parse__parse_error _y_x10910, kk_context_t* _ctx); /* (std/text/parse/parse-error<std/time/time/time>) -> std/time/utc/utc maybe<std/time/time/time> */ 

kk_std_core_types__maybe kk_std_time_parse_parse_iso(kk_string_t s, kk_std_core_types__optional calendar, kk_context_t* _ctx); /* (s : string, calendar : ? std/time/calendar/calendar) -> std/time/utc/utc maybe<std/time/time/time> */ 

void kk_std_time_parse__init(kk_context_t* _ctx);


void kk_std_time_parse__done(kk_context_t* _ctx);

#endif // header
