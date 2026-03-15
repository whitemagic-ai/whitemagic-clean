// Koka generated module: std/time/calendars, koka version: 3.2.2, platform: 64-bit
#include "std_time_calendars.h"

kk_std_core_types__tuple2 kk_std_time_calendars_coptic_estimate_year(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, maybe<int>) */ 
  kk_std_core_types__tuple2 _match_x98;
  kk_integer_t _x_x102 = kk_integer_add_small_const(days, 365, _ctx); /*int*/
  _match_x98 = kk_std_core_int_divmod(_x_x102, kk_integer_from_small(1461), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x0 = _match_x98.fst;
    kk_box_t _box_x1 = _match_x98.snd;
    kk_integer_t era = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_t doe = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(doe, _ctx);
    kk_integer_dup(era, _ctx);
    kk_std_core_types__tuple2_drop(_match_x98, _ctx);
    kk_integer_t x_0_10009 = kk_integer_mul((kk_integer_from_small(4)),era,kk_context()); /*int*/;
    kk_integer_t y_0_10010 = kk_integer_div(doe,(kk_integer_from_small(366)),kk_context()); /*int*/;
    kk_integer_t _b_x3_5 = kk_integer_add(x_0_10009,y_0_10010,kk_context()); /*int*/;
    kk_box_t _x_x103;
    kk_std_core_types__maybe _x_x104 = kk_std_core_types__new_Just(kk_integer_box(kk_integer_from_small(364), _ctx), _ctx); /*maybe<88>*/
    _x_x103 = kk_std_core_types__maybe_box(_x_x104, _ctx); /*135*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x3_5, _ctx), _x_x103, _ctx);
  }
}
 
// The [Coptic](https://en.wikipedia.org/wiki/Coptic_calendar) calendar.
// The calendar short name is ``CC``.


// lift anonymous function
struct kk_std_time_calendars_cal_coptic_fun110__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_coptic_fun110(kk_function_t _fself, kk_integer_t _x1_x109, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_coptic_fun110(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_coptic_fun110, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_coptic_fun110(kk_function_t _fself, kk_integer_t _x1_x109, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_coptic_days_before_year(_x1_x109, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_coptic_fun112__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendars_cal_coptic_fun112(kk_function_t _fself, kk_integer_t _x1_x111, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_coptic_fun112(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_coptic_fun112, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendars_cal_coptic_fun112(kk_function_t _fself, kk_integer_t _x1_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_coptic_estimate_year(_x1_x111, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_coptic_fun115__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_coptic_fun115(kk_function_t _fself, kk_integer_t _x1_x113, kk_integer_t _x2_x114, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_coptic_fun115(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_coptic_fun115, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_coptic_fun115(kk_function_t _fself, kk_integer_t _x1_x113, kk_integer_t _x2_x114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_coptic_days_before_month(_x1_x113, _x2_x114, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_coptic_fun118__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_coptic_fun118(kk_function_t _fself, kk_integer_t _x1_x116, kk_integer_t _x2_x117, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_coptic_fun118(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_coptic_fun118, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_coptic_fun118(kk_function_t _fself, kk_integer_t _x1_x116, kk_integer_t _x2_x117, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_coptic_doy_to_month(_x1_x116, _x2_x117, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_coptic_fun121__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendars_cal_coptic_fun121(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_coptic_fun121(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_coptic_fun121, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendars_cal_coptic_fun121(kk_function_t _fself, kk_box_t _b_x12, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x122;
  kk_std_time_date__date d_15 = kk_std_time_date__date_unbox(_b_x12, KK_OWNED, _ctx); /*std/time/date/date*/;
  bool _match_x95;
  kk_integer_t _brw_x96;
  {
    kk_integer_t _x = d_15.year;
    kk_integer_dup(_x, _ctx);
    kk_std_time_date__date_drop(d_15, _ctx);
    _brw_x96 = _x; /*int*/
  }
  bool _brw_x97 = kk_integer_gt_borrow(_brw_x96,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x96, _ctx);
  _match_x95 = _brw_x97; /*bool*/
  if (_match_x95) {
    kk_define_string_literal(, _s_x123, 4, "A.M.", _ctx)
    _x_x122 = kk_string_dup(_s_x123, _ctx); /*string*/
  }
  else {
    _x_x122 = kk_string_empty(); /*string*/
  }
  return kk_string_box(_x_x122);
}

kk_std_time_calendar__calendar kk_std_time_calendars_cal_coptic;

kk_std_core_types__tuple2 kk_std_time_calendars_coptic_days_to_yeardoy(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, int) */ 
  kk_std_core_types__tuple2 _match_x93;
  kk_integer_t _x_x125 = kk_integer_add_small_const(days, 365, _ctx); /*int*/
  _match_x93 = kk_std_core_int_divmod(_x_x125, kk_integer_from_small(1461), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x16 = _match_x93.fst;
    kk_box_t _box_x17 = _match_x93.snd;
    kk_integer_t era = kk_integer_unbox(_box_x16, _ctx);
    kk_integer_t doe = kk_integer_unbox(_box_x17, _ctx);
    kk_integer_dup(doe, _ctx);
    kk_integer_dup(era, _ctx);
    kk_std_core_types__tuple2_drop(_match_x93, _ctx);
    kk_integer_t i_10015;
    kk_integer_t _x_x126 = kk_integer_dup(doe, _ctx); /*int*/
    i_10015 = kk_integer_div(_x_x126,(kk_integer_from_small(365)),kk_context()); /*int*/
    kk_integer_t yoe;
    bool _match_x94 = kk_integer_lte_borrow(i_10015,(kk_integer_from_small(3)),kk_context()); /*bool*/;
    if (_match_x94) {
      yoe = i_10015; /*int*/
    }
    else {
      kk_integer_drop(i_10015, _ctx);
      yoe = kk_integer_from_small(3); /*int*/
    }
    kk_integer_t x_0_10017 = kk_integer_mul((kk_integer_from_small(4)),era,kk_context()); /*int*/;
    kk_integer_t y_1_10020;
    kk_integer_t _x_x127 = kk_integer_dup(yoe, _ctx); /*int*/
    y_1_10020 = kk_integer_mul((kk_integer_from_small(365)),_x_x127,kk_context()); /*int*/
    kk_integer_t _b_x18_20 = kk_integer_add(x_0_10017,yoe,kk_context()); /*int*/;
    kk_integer_t _b_x19_21 = kk_integer_sub(doe,y_1_10020,kk_context()); /*int*/;
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x18_20, _ctx), kk_integer_box(_b_x19_21, _ctx), _ctx);
  }
}
 
// The [Ethiopian](https://en.wikipedia.org/wiki/Ethiopian_calendar) calendar.
// The calendar short name is ``EC``.

kk_std_time_calendar__calendar kk_std_time_calendars_cal_ethiopian;
 
// duplicate from std/time/calendar to reduce dependencies

kk_integer_t kk_std_time_calendars_iso_days_before_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> int */ 
  kk_integer_t y = kk_integer_add_small_const(year, -1, _ctx); /*int*/;
  kk_integer_t x_0_10028;
  kk_integer_t _x_x135 = kk_integer_dup(y, _ctx); /*int*/
  x_0_10028 = kk_integer_div(_x_x135,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t y_1_10029;
  kk_integer_t _x_x136 = kk_integer_dup(y, _ctx); /*int*/
  y_1_10029 = kk_integer_div(_x_x136,(kk_integer_from_small(100)),kk_context()); /*int*/
  kk_integer_t x_10026 = kk_integer_sub(x_0_10028,y_1_10029,kk_context()); /*int*/;
  kk_integer_t y_0_10027;
  kk_integer_t _x_x137 = kk_integer_dup(y, _ctx); /*int*/
  y_0_10027 = kk_integer_div(_x_x137,(kk_integer_from_small(400)),kk_context()); /*int*/
  kk_integer_t leapdays = kk_integer_add(x_10026,y_0_10027,kk_context()); /*int*/;
  kk_integer_t x_1_10030 = kk_integer_mul((kk_integer_from_small(365)),y,kk_context()); /*int*/;
  return kk_integer_add(x_1_10030,leapdays,kk_context());
}

kk_integer_t kk_std_time_calendars_isow_days_before_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> int */ 
  kk_integer_t gdays = kk_std_time_calendars_iso_days_before_year(year, _ctx); /*int*/;
  kk_integer_t weekday;
  kk_integer_t _x_x138 = kk_integer_dup(gdays, _ctx); /*int*/
  weekday = kk_integer_mod(_x_x138,(kk_integer_from_small(7)),kk_context()); /*int*/
  kk_integer_t adjust;
  bool _match_x92 = kk_integer_lte_borrow(weekday,(kk_integer_from_small(3)),kk_context()); /*bool*/;
  if (_match_x92) {
    adjust = kk_integer_sub((kk_integer_from_small(0)),weekday,kk_context()); /*int*/
  }
  else {
    adjust = kk_integer_sub((kk_integer_from_small(7)),weekday,kk_context()); /*int*/
  }
  return kk_integer_add(gdays,adjust,kk_context());
}

kk_std_core_types__tuple2 kk_std_time_calendars_iso_estimate_year(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, maybe<int>) */ 
  kk_std_core_types__tuple2 _match_x91 = kk_std_core_int_divmod(days, kk_integer_from_int(146097, _ctx), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x22 = _match_x91.fst;
    kk_box_t _box_x23 = _match_x91.snd;
    kk_integer_t era = kk_integer_unbox(_box_x22, _ctx);
    kk_integer_t yoe = kk_integer_unbox(_box_x23, _ctx);
    kk_integer_dup(era, _ctx);
    kk_integer_dup(yoe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x91, _ctx);
    kk_integer_t y_0_10041 = kk_integer_mul((kk_integer_from_small(400)),era,kk_context()); /*int*/;
    kk_integer_t x_10038 = kk_integer_add_small_const(y_0_10041, 1, _ctx); /*int*/;
    kk_integer_t y_10039;
    kk_integer_t _x_x139 = kk_integer_mul((kk_integer_from_small(100)),yoe,kk_context()); /*int*/
    y_10039 = kk_integer_div(_x_x139,(kk_integer_from_int(36525, _ctx)),kk_context()); /*int*/
    kk_integer_t _b_x25_27 = kk_integer_add(x_10038,y_10039,kk_context()); /*int*/;
    kk_box_t _x_x140;
    kk_std_core_types__maybe _x_x141 = kk_std_core_types__new_Just(kk_integer_box(kk_integer_from_small(363), _ctx), _ctx); /*maybe<88>*/
    _x_x140 = kk_std_core_types__maybe_box(_x_x141, _ctx); /*135*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x25_27, _ctx), _x_x140, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_time_calendars_isow_estimate_year(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, maybe<int>) */ 
  kk_integer_t days_0_10080 = kk_integer_add_small_const(days, -3, _ctx); /*int*/;
  kk_std_core_types__tuple2 _match_x90 = kk_std_core_int_divmod(days_0_10080, kk_integer_from_int(146097, _ctx), _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x30 = _match_x90.fst;
    kk_box_t _box_x31 = _match_x90.snd;
    kk_integer_t era = kk_integer_unbox(_box_x30, _ctx);
    kk_integer_t yoe = kk_integer_unbox(_box_x31, _ctx);
    kk_integer_dup(era, _ctx);
    kk_integer_dup(yoe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x90, _ctx);
    kk_integer_t y_0_10041 = kk_integer_mul((kk_integer_from_small(400)),era,kk_context()); /*int*/;
    kk_integer_t x_10038 = kk_integer_add_small_const(y_0_10041, 1, _ctx); /*int*/;
    kk_integer_t y_10039;
    kk_integer_t _x_x142 = kk_integer_mul((kk_integer_from_small(100)),yoe,kk_context()); /*int*/
    y_10039 = kk_integer_div(_x_x142,(kk_integer_from_int(36525, _ctx)),kk_context()); /*int*/
    kk_integer_t _b_x33_35 = kk_integer_add(x_10038,y_10039,kk_context()); /*int*/;
    kk_box_t _x_x143;
    kk_std_core_types__maybe _x_x144 = kk_std_core_types__new_Just(kk_integer_box(kk_integer_from_small(363), _ctx), _ctx); /*maybe<88>*/
    _x_x143 = kk_std_core_types__maybe_box(_x_x144, _ctx); /*135*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x33_35, _ctx), _x_x143, _ctx);
  }
}
 
// /* The 'ISO week' calendar. This implements the [ISO week date](https://en.wikipedia.org/wiki/ISO_week_date)
// calendar the week number is interpreted as "month" number instead, i.e. every year has 52 (or 53)
// months of 7 week days each. Short name is `"IW"`.
// 
// Since its introduction in 1988, the ISO week calendar is a widely accepted standard for a weekly
// calendar. It is used mainly by businesses for fiscal year calculations.
// Weeks start on Monday (as day 1) and every common year has 52 weeks.
// Every 5 to 7 years, there is a 'leap' year with an extra week 53.
// The ISO week calendar is directly based on the Gregorian calendar.
// For example, Tuesday 2001-01-02 is denoted as 2001-W01-2 in the ISO week
// calendar: weekday 2 (Tuesday) of week 1 in 2001.
// 
// The year of an ISO week is defined as the Gregorian year that has the
// Thursday of that week, &ie; contains the most days of that week. For
// example, Thursday 2004-01-01 has week date 2004-W01-4. This means that
// sometimes the Gregorian year is different for a first- or last week:
// Wednesday 2003-12-31 falls in the first week of 2004W and has week date
// 2004-W01-3. Similarly, Saturday 2005-01-01 falls in the last (leap) week of
// 2004W and has week date 2004-W53-6.
// */


// lift anonymous function
struct kk_std_time_calendars_cal_iso_week_fun150__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_iso_week_fun150(kk_function_t _fself, kk_integer_t _x1_x149, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_week_fun150(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_week_fun150, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_iso_week_fun150(kk_function_t _fself, kk_integer_t _x1_x149, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isow_days_before_year(_x1_x149, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_iso_week_fun152__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendars_cal_iso_week_fun152(kk_function_t _fself, kk_integer_t _x1_x151, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_week_fun152(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_week_fun152, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendars_cal_iso_week_fun152(kk_function_t _fself, kk_integer_t _x1_x151, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isow_estimate_year(_x1_x151, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_iso_week_fun155__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_iso_week_fun155(kk_function_t _fself, kk_integer_t _x1_x153, kk_integer_t _x2_x154, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_week_fun155(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_week_fun155, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_iso_week_fun155(kk_function_t _fself, kk_integer_t _x1_x153, kk_integer_t _x2_x154, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isow_days_before_month(_x1_x153, _x2_x154, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_iso_week_fun158__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_iso_week_fun158(kk_function_t _fself, kk_integer_t _x1_x156, kk_integer_t _x2_x157, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_week_fun158(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_week_fun158, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_iso_week_fun158(kk_function_t _fself, kk_integer_t _x1_x156, kk_integer_t _x2_x157, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isow_doy_to_month(_x1_x156, _x2_x157, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendars_cal_iso_week;

kk_integer_t kk_std_time_calendars_isom_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx) { /* (year : int, month : int) -> int */ 
  kk_integer_drop(year, _ctx);
  kk_integer_t x_10044;
  kk_integer_t _x_x163;
  kk_integer_t _x_x164 = kk_integer_dup(month, _ctx); /*int*/
  _x_x163 = kk_integer_add_small_const(_x_x164, -1, _ctx); /*int*/
  x_10044 = kk_integer_mul((kk_integer_from_small(30)),_x_x163,kk_context()); /*int*/
  kk_integer_t y_10045;
  kk_integer_t _x_x165 = kk_integer_add_small_const(month, -1, _ctx); /*int*/
  y_10045 = kk_integer_div(_x_x165,(kk_integer_from_small(3)),kk_context()); /*int*/
  return kk_integer_add(x_10044,y_10045,kk_context());
}

kk_integer_t kk_std_time_calendars_isom_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx) { /* (year : int, doy : int) -> int */ 
  kk_integer_drop(year, _ctx);
  kk_integer_t m;
  kk_integer_t _x_x166;
  kk_integer_t _x_x167 = kk_integer_add_small_const(doy, 1, _ctx); /*int*/
  _x_x166 = kk_integer_mul((kk_integer_from_small(100)),_x_x167,kk_context()); /*int*/
  m = kk_integer_div(_x_x166,(kk_integer_from_small(3034)),kk_context()); /*int*/
  kk_integer_t i_0_10049 = kk_integer_add_small_const(m, 1, _ctx); /*int*/;
  bool _match_x89 = kk_integer_lte_borrow(i_0_10049,(kk_integer_from_small(12)),kk_context()); /*bool*/;
  if (_match_x89) {
    return i_0_10049;
  }
  {
    kk_integer_drop(i_0_10049, _ctx);
    return kk_integer_from_small(12);
  }
}
 
// /*
// <!--meta
// .calendar
//   .sans-serif;
//   border: 1px solid black;
// 
// .mheader
//   font-weight: bold;
// 
// .separator
//   padding-bottom:0.2ex;
// 
// .noborder
//   border-left:none;
//   border-right:none;
// 
// .spacer
//   border-left:none;
//   border-right:none;
//   height:0.4ex;
// 
// .month
//   td-padding-right: 1ex;
//   tr-padding-top: 0.25ex;
//   tbody-tr-1-padding-top: 0.5ex;
//   .sans-serif
// 
// -->
// This is _not_ a standard ISO calendar -- it is named this way because
// it is based directly on the standard [ISO week
// date](https://en.wikipedia.org/wiki/ISO_week_date) calendar.
// The short name of the calendar is `"IM"`.
// 
// The "ISO month" calendar takes the ISO week calendar _as is_, but divides
// it up in 12 months. This is more familiar than using week numbers to
// denote a date. A common ISO week year of 52 weeks is divided into 4
// quarters of 13 weeks each. Each quarter has 3 months of 30, 30, and 31
// days respectively. So, January has 30 days, February has 30 days too,
// March has 31 days, April has 30 days again, etc. On a leap year, we have
// an extra leap week 53 that is inserted at the end of the last month,
// &ie; adds days 32 to 38 to December. Since quarters are meant to be equal
// for business purposes, we generally don't count the leap week as part of
// the 4th quarter.
// 
// This monthly calendar has many good properties, not the least that it
// matches the Gregorian calendar dates very closely[^fn-match], and is based a widely supported standard ISO calendar. Moreover,
// it is [perennial](https://en.wikipedia.org/wiki/Perennial_calendar) where
// every date in the year always has the same weekday. For example, every
// year and every quarter always start on a Monday and end on a Sunday.
// Thanksgiving (the 4th Thursday of November) is always on November 23, and
// always 31 days before Christmas. Christmas and New year are always on
// Sunday, and there is never a Friday the 13th.
// 
// [^fn-match]: The month date always matches within 5 days of the
//     Gregorian calendar; and 90% of the time, the date is within 3 days.
// 
// When writing down a date in the monthly calendar we prefix the
// month with a capital [M]{.sans-serif} in order to distinguish these
// dates from regular Gregorian dates or ISO week dates. For example,
// 
// |-----|----------------|----------------|----------------------------------------------------------|---------------|
// | Day | Gregorian date | Month date     | Remarks                                                | ISO week date |
// +-----|:--------------:|:--------------:+----------------------------------------------------------|:-------------:+
// | Mon | 2018-01-01     | 2018-M01-01    | Matches since Monday starts the first week of the year.  | 2018-W01-1    |
// | Thu | 2016-11-24     | 2016-M11-23    | Thanksgiving, always on Thursday M11-23 every year.      | 2016-W47-5    |
// | Thu | 2013-07-04     | 2013-M07-04    | Independence day is always on Thursday M07-04.           | 2013-W27-4    |
// |-----|----------------|----------------|----------------------------------------------------------|---------------|
// | Thu | 2004-01-01     | 2004-M01-04    | Since the first week falls partly in 2003M.              | 2004-W01-4    |
// | Sun | 2005-01-02     | 2004-M12-38    | Since it is the last day of the leap week of 2004M.      | 2004-W53-7    |
// |-----|----------------|----------------|----------------------------------------------------------|---------------|
// { white-space:nowrap; col-4-white-space:normal; col-3-padding-right:1ex;   }
// 
// With the regularity of the new calendar, we can reuse the same calendar
// pattern for each quarter over and over; unlike the Gregorian calendar it
// never changes which makes planning for businesses, schools, government
// etc. much simpler. Here is the (perpetual) calendar with the
// corresponding ISO week numbers:
// 
// ~ Begin Calendar { .sans-serif; border: 1px solid #AAA; padding:1ex; }
// 
// +~~~:|~~~:|~~~:|~~~:|~~~:|~~~:|~~~:+~~~|~~~~:|~~~~:|~~~~:|~~~~:|~~~~~~~~~~~~~|
// |  Quarterly Calendar        ||||||| &quad;  | ISO week numbers   ||||             |{.noborder; text-align:center}
// |    |    |    |    |    |    |    |   | Q1  | Q2  | Q3  | Q4  |             |{.noborder; .mheader}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// | Mo | Tu | We | Th | Fr | Sa | Su |   | Jan | Apr | Jul |Oct  |             |{.mheader}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// | 1  | 2  | 3  | 4  | 5  | 6  | 7  |   | 1   | 14  | 27  | 40  |             |
// | 8  | 9  | 10 | 11 | 12 | 13 | 14 |   | 2   | 15  | 28  | 41  |             |
// | 15 | 16 | 17 | 18 | 19 | 20 | 21 |   | 3   | 16  | 29  | 42  |             |
// | 22 | 23 | 24 | 25 | 26 | 27 | 28 |   | 4   | 17  | 30  | 43  |             |
// | 29 | 30 |    |    |    |    |    |   | 5   | 18  | 31  | 44  |             |
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// |    |    |    |    |    |    |    |   |     |     |     |     |             |{.spacer}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// | Mo | Tu | We | Th | Fr | Sa | Su |   | Feb | May | Aug | Nov |             |{.mheader}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// |    |    | 1  | 2  | 3  | 4  | 5  |   | 5   | 18  | 31  | 44  |             |
// | 6  | 7  | 8  | 9  | 10 | 11 | 12 |   | 6   | 19  | 32  | 45  |             |
// | 13 | 14 | 15 | 16 | 17 | 18 | 19 |   | 7   | 20  | 33  | 46  |             |
// | 20 | 21 | 22 | 23 | 24 | 25 | 26 |   | 8   | 21  | 34  | 47  |             |
// | 27 | 28 | 29 | 30 |    |    |    |   | 9   | 22  | 35  | 48  |             |
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// |    |    |    |    |    |    |    |   |     |     |     |     |             |{.spacer}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// | Mo | Tu | We | Th | Fr | Sa | Su |   | Mar | Jun | Sep | Dec |             |{.mheader}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// |    |    |    |    | 1  | 2  | 3  |   | 9   | 22  | 35  | 48  |             |
// | 4  | 5  | 6  | 7  | 8  | 9  | 10 |   | 10  | 23  | 36  | 49  |             |
// | 11 | 12 | 13 | 14 | 15 | 16 | 17 |   | 11  | 24  | 37  | 50  |             |
// | 18 | 19 | 20 | 21 | 22 | 23 | 24 |   | 12  | 25  | 38  | 51  |             |
// | 25 | 26 | 27 | 28 | 29 | 30 | 31 |   | 13  | 26  | 39  | 52  |             |
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// |    |    |    |    |    |    |    |   |     |     |     |     |             |{.spacer}
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// |\ 32|\ 33|\ 34|\ 35|\ 36|\ 37|\ 38|   | leap week^&dagger;^     ||| 53  |             |
// |----|----|----|----|----|----|----|   |     |     |     |     |             |
// { .month; margin-left:auto; margin-right:auto }
// 
// &nbsp;
// 
// ^&dagger;^ A leap week is inserted
//   at the end of December. Upcoming years with a leap week are 2020, 2026, 2032, 2037, and 2043. In
//   general, a leap week is inserted whenever the corresponding Gregorian
//   year starts and/or ends on a Thursday.
// 
// ~ End Calendar
// 
// -- Daan Leijen, 2016.
// */


// lift anonymous function
struct kk_std_time_calendars_cal_iso_month_fun173__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_iso_month_fun173(kk_function_t _fself, kk_integer_t _x1_x172, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_month_fun173(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_month_fun173, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_iso_month_fun173(kk_function_t _fself, kk_integer_t _x1_x172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isow_days_before_year(_x1_x172, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_iso_month_fun175__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendars_cal_iso_month_fun175(kk_function_t _fself, kk_integer_t _x1_x174, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_month_fun175(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_month_fun175, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendars_cal_iso_month_fun175(kk_function_t _fself, kk_integer_t _x1_x174, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isow_estimate_year(_x1_x174, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_iso_month_fun178__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_iso_month_fun178(kk_function_t _fself, kk_integer_t _x1_x176, kk_integer_t _x2_x177, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_month_fun178(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_month_fun178, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_iso_month_fun178(kk_function_t _fself, kk_integer_t _x1_x176, kk_integer_t _x2_x177, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isom_days_before_month(_x1_x176, _x2_x177, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_iso_month_fun181__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_iso_month_fun181(kk_function_t _fself, kk_integer_t _x1_x179, kk_integer_t _x2_x180, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_iso_month_fun181(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_iso_month_fun181, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_iso_month_fun181(kk_function_t _fself, kk_integer_t _x1_x179, kk_integer_t _x2_x180, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_isom_doy_to_month(_x1_x179, _x2_x180, _ctx);
}

kk_std_time_calendar__calendar kk_std_time_calendars_cal_iso_month;

kk_integer_t kk_std_time_calendars_julian_adjust(bool is_before_march, kk_integer_t year, kk_context_t* _ctx) { /* (is-before-march : bool, year : int) -> int */ 
  if (is_before_march) {
    kk_integer_drop(year, _ctx);
    return kk_integer_from_small(0);
  }
  {
    bool _match_x86;
    kk_integer_t _brw_x87 = kk_integer_mod(year,(kk_integer_from_small(4)),kk_context()); /*int*/;
    bool _brw_x88 = kk_integer_eq_borrow(_brw_x87,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x87, _ctx);
    _match_x86 = _brw_x88; /*bool*/
    if (_match_x86) {
      return kk_integer_from_small(1);
    }
    {
      return kk_integer_from_small(2);
    }
  }
}

kk_integer_t kk_std_time_calendars_julian_days_before_month(kk_integer_t year, kk_integer_t month, kk_context_t* _ctx) { /* (year : int, month : int) -> int */ 
  bool is_before_march_10052 = kk_integer_lte_borrow(month,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_t adj;
  if (is_before_march_10052) {
    kk_integer_drop(year, _ctx);
    adj = kk_integer_from_small(0); /*int*/
  }
  else {
    bool _match_x83;
    kk_integer_t _brw_x84 = kk_integer_mod(year,(kk_integer_from_small(4)),kk_context()); /*int*/;
    bool _brw_x85 = kk_integer_eq_borrow(_brw_x84,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x84, _ctx);
    _match_x83 = _brw_x85; /*bool*/
    if (_match_x83) {
      adj = kk_integer_from_small(1); /*int*/
    }
    else {
      adj = kk_integer_from_small(2); /*int*/
    }
  }
  kk_integer_t x_0_10056 = kk_integer_mul((kk_integer_from_small(367)),month,kk_context()); /*int*/;
  kk_integer_t x_10054;
  kk_integer_t _x_x186 = kk_integer_add_small_const(x_0_10056, -362, _ctx); /*int*/
  x_10054 = kk_integer_div(_x_x186,(kk_integer_from_small(12)),kk_context()); /*int*/
  return kk_integer_sub(x_10054,adj,kk_context());
}

kk_integer_t kk_std_time_calendars_julian_doy_to_month(kk_integer_t year, kk_integer_t doy, kk_context_t* _ctx) { /* (year : int, doy : int) -> int */ 
  bool is_before_march_10058 = kk_integer_lte_borrow(doy,(kk_integer_from_small(58)),kk_context()); /*bool*/;
  kk_integer_t adj;
  if (is_before_march_10058) {
    kk_integer_drop(year, _ctx);
    adj = kk_integer_from_small(0); /*int*/
  }
  else {
    bool _match_x80;
    kk_integer_t _brw_x81 = kk_integer_mod(year,(kk_integer_from_small(4)),kk_context()); /*int*/;
    bool _brw_x82 = kk_integer_eq_borrow(_brw_x81,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x81, _ctx);
    _match_x80 = _brw_x82; /*bool*/
    if (_match_x80) {
      adj = kk_integer_from_small(1); /*int*/
    }
    else {
      adj = kk_integer_from_small(2); /*int*/
    }
  }
  kk_integer_t x_10060;
  kk_integer_t _x_x187 = kk_integer_add(doy,adj,kk_context()); /*int*/
  x_10060 = kk_integer_mul((kk_integer_from_small(12)),_x_x187,kk_context()); /*int*/
  kk_integer_t _x_x188 = kk_integer_add_small_const(x_10060, 373, _ctx); /*int*/
  return kk_integer_div(_x_x188,(kk_integer_from_small(367)),kk_context());
}

kk_integer_t kk_std_time_calendars_julian_days_before_year(kk_integer_t year, kk_context_t* _ctx) { /* (year : int) -> int */ 
  kk_integer_t leapdays;
  kk_integer_t _x_x189;
  kk_integer_t _x_x190 = kk_integer_dup(year, _ctx); /*int*/
  _x_x189 = kk_integer_add_small_const(_x_x190, -1, _ctx); /*int*/
  leapdays = kk_integer_div(_x_x189,(kk_integer_from_small(4)),kk_context()); /*int*/
  kk_integer_t x_10065;
  kk_integer_t _x_x191 = kk_integer_add_small_const(year, -1, _ctx); /*int*/
  x_10065 = kk_integer_mul((kk_integer_from_small(365)),_x_x191,kk_context()); /*int*/
  return kk_integer_add(x_10065,leapdays,kk_context());
}

kk_std_core_types__tuple2 kk_std_time_calendars_julian_estimate_year(kk_integer_t days, kk_context_t* _ctx) { /* (days : int) -> (int, maybe<int>) */ 
  kk_std_core_types__tuple2 _match_x79;
  kk_integer_t _x_x192 = kk_integer_add_small_const(days, 365, _ctx); /*int*/
  _match_x79 = kk_std_core_int_divmod(_x_x192, kk_integer_from_small(1461), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x42 = _match_x79.fst;
    kk_box_t _box_x43 = _match_x79.snd;
    kk_integer_t era = kk_integer_unbox(_box_x42, _ctx);
    kk_integer_t yoe = kk_integer_unbox(_box_x43, _ctx);
    kk_integer_dup(era, _ctx);
    kk_integer_dup(yoe, _ctx);
    kk_std_core_types__tuple2_drop(_match_x79, _ctx);
    kk_integer_t x_0_10070 = kk_integer_mul((kk_integer_from_small(4)),era,kk_context()); /*int*/;
    kk_integer_t y_0_10071 = kk_integer_div(yoe,(kk_integer_from_small(366)),kk_context()); /*int*/;
    kk_integer_t _b_x45_47 = kk_integer_add(x_0_10070,y_0_10071,kk_context()); /*int*/;
    kk_box_t _x_x193;
    kk_std_core_types__maybe _x_x194 = kk_std_core_types__new_Just(kk_integer_box(kk_integer_from_small(364), _ctx), _ctx); /*maybe<88>*/
    _x_x193 = kk_std_core_types__maybe_box(_x_x194, _ctx); /*135*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x45_47, _ctx), _x_x193, _ctx);
  }
}
 
// The [Julian calendar](https://en.wikipedia.org/wiki/Julian_calendar).
// Uses old-style ``BC`` and ``AD`` to display era's.
// The calendar short name is ``JC``.


// lift anonymous function
struct kk_std_time_calendars_cal_julian_fun200__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_julian_fun200(kk_function_t _fself, kk_integer_t _x1_x199, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_julian_fun200(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_julian_fun200, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_julian_fun200(kk_function_t _fself, kk_integer_t _x1_x199, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_julian_days_before_year(_x1_x199, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_julian_fun202__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_std_time_calendars_cal_julian_fun202(kk_function_t _fself, kk_integer_t _x1_x201, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_julian_fun202(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_julian_fun202, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__tuple2 kk_std_time_calendars_cal_julian_fun202(kk_function_t _fself, kk_integer_t _x1_x201, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_julian_estimate_year(_x1_x201, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_julian_fun205__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_julian_fun205(kk_function_t _fself, kk_integer_t _x1_x203, kk_integer_t _x2_x204, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_julian_fun205(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_julian_fun205, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_julian_fun205(kk_function_t _fself, kk_integer_t _x1_x203, kk_integer_t _x2_x204, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_julian_days_before_month(_x1_x203, _x2_x204, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_julian_fun208__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_std_time_calendars_cal_julian_fun208(kk_function_t _fself, kk_integer_t _x1_x206, kk_integer_t _x2_x207, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_julian_fun208(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_julian_fun208, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_integer_t kk_std_time_calendars_cal_julian_fun208(kk_function_t _fself, kk_integer_t _x1_x206, kk_integer_t _x2_x207, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_time_calendars_julian_doy_to_month(_x1_x206, _x2_x207, _ctx);
}


// lift anonymous function
struct kk_std_time_calendars_cal_julian_fun212__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_calendars_cal_julian_fun212(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_cal_julian_fun212(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_calendars_cal_julian_fun212, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_calendars_cal_julian_fun212(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x213;
  kk_std_time_date__date d_59 = kk_std_time_date__date_unbox(_b_x55, KK_OWNED, _ctx); /*std/time/date/date*/;
  bool _match_x76;
  kk_integer_t _brw_x77;
  {
    kk_integer_t _x = d_59.year;
    kk_integer_dup(_x, _ctx);
    kk_std_time_date__date_drop(d_59, _ctx);
    _brw_x77 = _x; /*int*/
  }
  bool _brw_x78 = kk_integer_lt_borrow(_brw_x77,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x77, _ctx);
  _match_x76 = _brw_x78; /*bool*/
  if (_match_x76) {
    kk_define_string_literal(, _s_x214, 2, "BC", _ctx)
    _x_x213 = kk_string_dup(_s_x214, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x215, 2, "AD", _ctx)
    _x_x213 = kk_string_dup(_s_x215, _ctx); /*string*/
  }
  return kk_string_box(_x_x213);
}

kk_std_time_calendar__calendar kk_std_time_calendars_cal_julian;


// lift anonymous function
struct kk_std_time_calendars_julian_gregorian_fun226__t {
  struct kk_function_s _base;
  kk_std_time_date__date _uniq_switch_date_1135;
};
static kk_box_t kk_std_time_calendars_julian_gregorian_fun226(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_std_time_calendars_new_julian_gregorian_fun226(kk_std_time_date__date _uniq_switch_date_1135, kk_context_t* _ctx) {
  struct kk_std_time_calendars_julian_gregorian_fun226__t* _self = kk_function_alloc_as(struct kk_std_time_calendars_julian_gregorian_fun226__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_calendars_julian_gregorian_fun226, kk_context());
  _self->_uniq_switch_date_1135 = _uniq_switch_date_1135;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_calendars_julian_gregorian_fun226(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  struct kk_std_time_calendars_julian_gregorian_fun226__t* _self = kk_function_as(struct kk_std_time_calendars_julian_gregorian_fun226__t*, _fself, _ctx);
  kk_std_time_date__date _uniq_switch_date_1135 = _self->_uniq_switch_date_1135; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_date__date_dup(_uniq_switch_date_1135, _ctx);}, {}, _ctx)
  kk_std_time_date__date d_68 = kk_std_time_date__date_unbox(_b_x64, KK_OWNED, _ctx); /*std/time/date/date*/;
  kk_string_t _x_x227;
  bool _match_x69;
  kk_std_core_types__order _x_x228;
  kk_std_time_date__date _x_x229 = kk_std_time_date__date_dup(d_68, _ctx); /*std/time/date/date*/
  _x_x228 = kk_std_time_date_cmp(_x_x229, _uniq_switch_date_1135, _ctx); /*order*/
  _match_x69 = kk_std_core_order__lp__eq__eq__rp_(_x_x228, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x69) {
    bool _match_x73;
    kk_integer_t _brw_x74;
    {
      kk_integer_t _x = d_68.year;
      kk_integer_dup(_x, _ctx);
      _brw_x74 = _x; /*int*/
    }
    bool _brw_x75 = kk_integer_gte_borrow(_brw_x74,(kk_integer_from_small(1500)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x74, _ctx);
    _match_x73 = _brw_x75; /*bool*/
    if (_match_x73) {
      kk_std_time_date__date_drop(d_68, _ctx);
      kk_define_string_literal(, _s_x230, 9, "CE (O.S.)", _ctx)
      _x_x227 = kk_string_dup(_s_x230, _ctx); /*string*/
    }
    else {
      kk_std_time_calendar__calendar _x_x231 = kk_std_time_calendars_cal_julian; /*std/time/calendar/calendar*/
      {
        struct kk_std_time_calendar_Calendar* _con_x232 = kk_std_time_calendar__as_Calendar(_x_x231, _ctx);
        kk_function_t _x_0 = _con_x232->show_era;
        kk_function_t _x_x233 = kk_function_dup(_x_0, _ctx); /*(std/time/date/date) -> string*/
        _x_x227 = kk_function_call(kk_string_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_x233, (_x_x233, d_68, _ctx), _ctx); /*string*/
      }
    }
  }
  else {
    bool _match_x70;
    kk_integer_t _brw_x71;
    {
      kk_integer_t _x_1 = d_68.year;
      kk_integer_dup(_x_1, _ctx);
      _brw_x71 = _x_1; /*int*/
    }
    bool _brw_x72 = kk_integer_lte_borrow(_brw_x71,(kk_integer_from_small(1926)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x71, _ctx);
    _match_x70 = _brw_x72; /*bool*/
    if (_match_x70) {
      kk_std_time_date__date_drop(d_68, _ctx);
      kk_define_string_literal(, _s_x234, 9, "CE (N.S.)", _ctx)
      _x_x227 = kk_string_dup(_s_x234, _ctx); /*string*/
    }
    else {
      kk_std_time_calendar__calendar _x_x235 = kk_std_time_calendar_cal_gregorian; /*std/time/calendar/calendar*/
      {
        struct kk_std_time_calendar_Calendar* _con_x236 = kk_std_time_calendar__as_Calendar(_x_x235, _ctx);
        kk_function_t _x_2 = _con_x236->show_era;
        kk_function_t _x_x237 = kk_function_dup(_x_2, _ctx); /*(std/time/date/date) -> string*/
        _x_x227 = kk_function_call(kk_string_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_x237, (_x_x237, d_68, _ctx), _ctx); /*string*/
      }
    }
  }
  return kk_string_box(_x_x227);
}

kk_std_time_calendar__calendar kk_std_time_calendars_julian_gregorian(kk_std_core_types__optional switch_date, kk_context_t* _ctx) { /* (switch-date : ? std/time/date/date) -> std/time/calendar/calendar */ 
  kk_std_time_date__date _uniq_switch_date_1135;
  if (kk_std_core_types__is_Optional(switch_date, _ctx)) {
    kk_box_t _box_x60 = switch_date._cons._Optional.value;
    kk_std_time_date__date _uniq_switch_date_1136 = kk_std_time_date__date_unbox(_box_x60, KK_BORROWED, _ctx);
    kk_std_time_date__date_dup(_uniq_switch_date_1136, _ctx);
    kk_std_core_types__optional_drop(switch_date, _ctx);
    _uniq_switch_date_1135 = _uniq_switch_date_1136; /*std/time/date/date*/
  }
  else {
    kk_std_core_types__optional_drop(switch_date, _ctx);
    _uniq_switch_date_1135 = kk_std_time_date__new_Date(kk_integer_from_small(1582), kk_integer_from_small(10), kk_integer_from_small(15), _ctx); /*std/time/date/date*/
  }
  kk_string_t _x_x216;
  kk_define_string_literal(, _s_x217, 2, "JG", _ctx)
  _x_x216 = kk_string_dup(_s_x217, _ctx); /*string*/
  kk_string_t _x_x218;
  kk_define_string_literal(, _s_x219, 16, "Julian-Gregorian", _ctx)
  _x_x218 = kk_string_dup(_s_x219, _ctx); /*string*/
  kk_std_time_date__date _x_x220 = kk_std_time_date__date_dup(_uniq_switch_date_1135, _ctx); /*std/time/date/date*/
  kk_std_time_calendar__calendar _x_x221 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_julian, _ctx); /*std/time/calendar/calendar*/
  kk_std_time_calendar__calendar _x_x222 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_gregorian, _ctx); /*std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x223;
  kk_box_t _x_x224;
  kk_std_core_types__maybe _x_x225 = kk_std_core_types__new_Just(kk_function_box(kk_std_time_calendars_new_julian_gregorian_fun226(_uniq_switch_date_1135, _ctx), _ctx), _ctx); /*maybe<88>*/
  _x_x224 = kk_std_core_types__maybe_box(_x_x225, _ctx); /*7*/
  _x_x223 = kk_std_core_types__new_Optional(_x_x224, _ctx); /*? 7*/
  return kk_std_time_calendar_combine_earth_calendars(_x_x216, _x_x218, _x_x220, _x_x221, _x_x222, _x_x223, _ctx);
}
 
// The combined Julian / Gregorian calendar, using the Julian calendar for dates
// before 1582-10-15 and the Gregorian calendar otherwise. It is possible to
// specify a different switch date using the `julian-gregorian` function.
// The calendar short name is ``JG``.

kk_std_time_calendar__calendar kk_std_time_calendars_cal_jg;

// initialization
void kk_std_time_calendars__init(kk_context_t* _ctx){
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
  kk_std_time_instant__init(_ctx);
  kk_std_time_utc__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_duration__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x105;
    kk_define_string_literal(, _s_x106, 2, "CC", _ctx)
    _x_x105 = kk_string_dup(_s_x106, _ctx); /*string*/
    kk_string_t _x_x107;
    kk_define_string_literal(, _s_x108, 6, "Coptic", _ctx)
    _x_x107 = kk_string_dup(_s_x108, _ctx); /*string*/
    kk_std_core_types__optional _x_x119 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_int(626515, _ctx), _ctx), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x120 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendars_new_cal_coptic_fun121(_ctx), _ctx), _ctx); /*? 7*/
    kk_std_time_calendars_cal_coptic = kk_std_time_calendar_solar_ecalendar(_x_x105, _x_x107, kk_std_time_calendars_new_cal_coptic_fun110(_ctx), kk_std_time_calendars_new_cal_coptic_fun112(_ctx), kk_std_time_calendars_new_cal_coptic_fun115(_ctx), kk_std_time_calendars_new_cal_coptic_fun118(_ctx), _x_x119, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x120, _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x128;
    kk_define_string_literal(, _s_x129, 2, "EC", _ctx)
    _x_x128 = kk_string_dup(_s_x129, _ctx); /*string*/
    kk_string_t _x_x130;
    kk_define_string_literal(, _s_x131, 9, "Ethiopian", _ctx)
    _x_x130 = kk_string_dup(_s_x131, _ctx); /*string*/
    kk_integer_t _x_x132 = kk_integer_neg((kk_integer_from_small(276)),kk_context()); /*int*/
    kk_std_time_calendar__calendar _x_x133 = kk_std_time_calendar__calendar_dup(kk_std_time_calendars_cal_coptic, _ctx); /*std/time/calendar/calendar*/
    kk_std_time_calendars_cal_ethiopian = kk_std_time_calendar_year_shift_earth_calendar(_x_x128, _x_x130, _x_x132, _x_x133, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x145;
    kk_define_string_literal(, _s_x146, 2, "IW", _ctx)
    _x_x145 = kk_string_dup(_s_x146, _ctx); /*string*/
    kk_string_t _x_x147;
    kk_define_string_literal(, _s_x148, 8, "ISO Week", _ctx)
    _x_x147 = kk_string_dup(_s_x148, _ctx); /*string*/
    kk_std_core_types__optional _x_x159;
    kk_box_t _x_x160;
    kk_string_t _x_x161;
    kk_define_string_literal(, _s_x162, 1, "W", _ctx)
    _x_x161 = kk_string_dup(_s_x162, _ctx); /*string*/
    _x_x160 = kk_string_box(_x_x161); /*7*/
    _x_x159 = kk_std_core_types__new_Optional(_x_x160, _ctx); /*? 7*/
    kk_std_time_calendars_cal_iso_week = kk_std_time_calendar_solar_ecalendar(_x_x145, _x_x147, kk_std_time_calendars_new_cal_iso_week_fun150(_ctx), kk_std_time_calendars_new_cal_iso_week_fun152(_ctx), kk_std_time_calendars_new_cal_iso_week_fun155(_ctx), kk_std_time_calendars_new_cal_iso_week_fun158(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x159, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x168;
    kk_define_string_literal(, _s_x169, 2, "IM", _ctx)
    _x_x168 = kk_string_dup(_s_x169, _ctx); /*string*/
    kk_string_t _x_x170;
    kk_define_string_literal(, _s_x171, 9, "ISO Month", _ctx)
    _x_x170 = kk_string_dup(_s_x171, _ctx); /*string*/
    kk_std_core_types__optional _x_x182;
    kk_box_t _x_x183;
    kk_string_t _x_x184;
    kk_define_string_literal(, _s_x185, 1, "M", _ctx)
    _x_x184 = kk_string_dup(_s_x185, _ctx); /*string*/
    _x_x183 = kk_string_box(_x_x184); /*7*/
    _x_x182 = kk_std_core_types__new_Optional(_x_x183, _ctx); /*? 7*/
    kk_std_time_calendars_cal_iso_month = kk_std_time_calendar_solar_ecalendar(_x_x168, _x_x170, kk_std_time_calendars_new_cal_iso_month_fun173(_ctx), kk_std_time_calendars_new_cal_iso_month_fun175(_ctx), kk_std_time_calendars_new_cal_iso_month_fun178(_ctx), kk_std_time_calendars_new_cal_iso_month_fun181(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _x_x182, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_string_t _x_x195;
    kk_define_string_literal(, _s_x196, 2, "JC", _ctx)
    _x_x195 = kk_string_dup(_s_x196, _ctx); /*string*/
    kk_string_t _x_x197;
    kk_define_string_literal(, _s_x198, 6, "Julian", _ctx)
    _x_x197 = kk_string_dup(_s_x198, _ctx); /*string*/
    kk_std_core_types__optional _x_x209 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_int(730121, _ctx), _ctx), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x210 = kk_std_core_types__new_Optional(kk_bool_box(false), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x211 = kk_std_core_types__new_Optional(kk_function_box(kk_std_time_calendars_new_cal_julian_fun212(_ctx), _ctx), _ctx); /*? 7*/
    kk_std_time_calendars_cal_julian = kk_std_time_calendar_solar_ecalendar(_x_x195, _x_x197, kk_std_time_calendars_new_cal_julian_fun200(_ctx), kk_std_time_calendars_new_cal_julian_fun202(_ctx), kk_std_time_calendars_new_cal_julian_fun205(_ctx), kk_std_time_calendars_new_cal_julian_fun208(_ctx), _x_x209, _x_x210, kk_std_core_types__new_None(_ctx), _x_x211, _ctx); /*std/time/calendar/calendar*/
  }
  {
    kk_std_time_calendars_cal_jg = kk_std_time_calendars_julian_gregorian(kk_std_core_types__new_None(_ctx), _ctx); /*std/time/calendar/calendar*/
  }
}

// termination
void kk_std_time_calendars__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_calendar__calendar_drop(kk_std_time_calendars_cal_jg, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendars_cal_julian, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendars_cal_iso_month, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendars_cal_iso_week, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendars_cal_ethiopian, _ctx);
  kk_std_time_calendar__calendar_drop(kk_std_time_calendars_cal_coptic, _ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_utc__done(_ctx);
  kk_std_time_instant__done(_ctx);
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
