#pragma once
#ifndef kk_std_time_date_H
#define kk_std_time_date_H
// Koka generated module: std/time/date, koka version: 3.2.2, platform: 64-bit
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

// type declarations

// type std/time/date/clock
struct kk_std_time_date__clock_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_date__clock;
struct kk_std_time_date_Clock {
  struct kk_std_time_date__clock_s _base;
  kk_integer_t hours;
  kk_integer_t minutes;
  kk_std_num_ddouble__ddouble seconds;
};
static inline kk_std_time_date__clock kk_std_time_date__base_Clock(struct kk_std_time_date_Clock* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_date__clock kk_std_time_date__new_Clock(kk_reuse_t _at, int32_t _cpath, kk_integer_t hours, kk_integer_t minutes, kk_std_num_ddouble__ddouble seconds, kk_context_t* _ctx) {
  struct kk_std_time_date_Clock* _con = kk_block_alloc_at_as(struct kk_std_time_date_Clock, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->hours = hours;
  _con->minutes = minutes;
  _con->seconds = seconds;
  return kk_std_time_date__base_Clock(_con, _ctx);
}
static inline struct kk_std_time_date_Clock* kk_std_time_date__as_Clock(kk_std_time_date__clock x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_date_Clock*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_date__is_Clock(kk_std_time_date__clock x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_date__clock kk_std_time_date__clock_dup(kk_std_time_date__clock _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_date__clock_drop(kk_std_time_date__clock _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_date__clock_box(kk_std_time_date__clock _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_date__clock kk_std_time_date__clock_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type std/time/date/date
struct kk_std_time_date_Date {
  kk_integer_t year;
  kk_integer_t month;
  kk_integer_t day;
};
typedef struct kk_std_time_date_Date kk_std_time_date__date;
static inline kk_std_time_date__date kk_std_time_date__new_Date(kk_integer_t year, kk_integer_t month, kk_integer_t day, kk_context_t* _ctx) {
  kk_std_time_date__date _con;
  _con.year = year;
  _con.month = month;
  _con.day = day;
  return _con;
}
static inline bool kk_std_time_date__is_Date(kk_std_time_date__date x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_date__date kk_std_time_date__date_dup(kk_std_time_date__date _x, kk_context_t* _ctx) {
  kk_integer_dup(_x.year, _ctx);
  kk_integer_dup(_x.month, _ctx);
  kk_integer_dup(_x.day, _ctx);
  return _x;
}
static inline void kk_std_time_date__date_drop(kk_std_time_date__date _x, kk_context_t* _ctx) {
  kk_integer_drop(_x.year, _ctx);
  kk_integer_drop(_x.month, _ctx);
  kk_integer_drop(_x.day, _ctx);
}
static inline kk_box_t kk_std_time_date__date_box(kk_std_time_date__date _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_time_date__date, _box, _x, 3 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_time_date__date kk_std_time_date__date_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_time_date__date _unbox;
  kk_valuetype_unbox(kk_std_time_date__date, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value type std/time/date/weekday
enum kk_std_time_date__weekday_e {
  kk_std_time_date_Mon,
  kk_std_time_date_Tue,
  kk_std_time_date_Wed,
  kk_std_time_date_Thu,
  kk_std_time_date_Fri,
  kk_std_time_date_Sat,
  kk_std_time_date_Sun
};
typedef uint8_t kk_std_time_date__weekday;

static inline kk_std_time_date__weekday kk_std_time_date__new_Mon(kk_context_t* _ctx) {
  return kk_std_time_date_Mon;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Tue(kk_context_t* _ctx) {
  return kk_std_time_date_Tue;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Wed(kk_context_t* _ctx) {
  return kk_std_time_date_Wed;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Thu(kk_context_t* _ctx) {
  return kk_std_time_date_Thu;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Fri(kk_context_t* _ctx) {
  return kk_std_time_date_Fri;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Sat(kk_context_t* _ctx) {
  return kk_std_time_date_Sat;
}
static inline kk_std_time_date__weekday kk_std_time_date__new_Sun(kk_context_t* _ctx) {
  return kk_std_time_date_Sun;
}
static inline bool kk_std_time_date__is_Mon(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Mon);
}
static inline bool kk_std_time_date__is_Tue(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Tue);
}
static inline bool kk_std_time_date__is_Wed(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Wed);
}
static inline bool kk_std_time_date__is_Thu(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Thu);
}
static inline bool kk_std_time_date__is_Fri(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Fri);
}
static inline bool kk_std_time_date__is_Sat(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Sat);
}
static inline bool kk_std_time_date__is_Sun(kk_std_time_date__weekday x, kk_context_t* _ctx) {
  return (x == kk_std_time_date_Sun);
}
static inline kk_std_time_date__weekday kk_std_time_date__weekday_dup(kk_std_time_date__weekday _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_std_time_date__weekday_drop(kk_std_time_date__weekday _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_time_date__weekday_box(kk_std_time_date__weekday _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_std_time_date__weekday kk_std_time_date__weekday_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_std_time_date__weekday)kk_enum_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `year` constructor field of the `:date` type.

static inline kk_integer_t kk_std_time_date_date_fs_year(kk_std_time_date__date date, kk_context_t* _ctx) { /* (date : date) -> int */ 
  {
    kk_integer_t _x = date.year;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `month` constructor field of the `:date` type.

static inline kk_integer_t kk_std_time_date_date_fs_month(kk_std_time_date__date date, kk_context_t* _ctx) { /* (date : date) -> int */ 
  {
    kk_integer_t _x = date.month;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day` constructor field of the `:date` type.

static inline kk_integer_t kk_std_time_date_date_fs_day(kk_std_time_date__date date, kk_context_t* _ctx) { /* (date : date) -> int */ 
  {
    kk_integer_t _x = date.day;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_std_time_date__date kk_std_time_date_date_fs__copy(kk_std_time_date__date _this, kk_std_core_types__optional year, kk_std_core_types__optional month, kk_std_core_types__optional day, kk_context_t* _ctx); /* (date, year : ? int, month : ? int, day : ? int) -> date */ 
 
// Automatically generated. Retrieves the `hours` constructor field of the `:clock` type.

static inline kk_integer_t kk_std_time_date_clock_fs_hours(kk_std_time_date__clock clock, kk_context_t* _ctx) { /* (clock : clock) -> int */ 
  {
    struct kk_std_time_date_Clock* _con_x175 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x175->seconds;
    kk_integer_t _x = _con_x175->hours;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `minutes` constructor field of the `:clock` type.

static inline kk_integer_t kk_std_time_date_clock_fs_minutes(kk_std_time_date__clock clock, kk_context_t* _ctx) { /* (clock : clock) -> int */ 
  {
    struct kk_std_time_date_Clock* _con_x176 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_std_num_ddouble__ddouble _pat_1 = _con_x176->seconds;
    kk_integer_t _x = _con_x176->minutes;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `seconds` constructor field of the `:clock` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_date_clock_fs_seconds(kk_std_time_date__clock clock, kk_context_t* _ctx) { /* (clock : clock) -> std/num/ddouble/ddouble */ 
  {
    struct kk_std_time_date_Clock* _con_x177 = kk_std_time_date__as_Clock(clock, _ctx);
    kk_std_num_ddouble__ddouble _x = _con_x177->seconds;
    return _x;
  }
}

kk_integer_t kk_std_time_date_int(kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (wd : weekday) -> int */ 
 
// Create an ISO weekdate where the "month" is the ISO week number.

static inline kk_std_time_date__date kk_std_time_date_weekdate(kk_integer_t year, kk_integer_t month, kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (year : int, month : int, weekday : weekday) -> date */ 
  kk_integer_t _x_x178 = kk_std_time_date_int(weekday_0, _ctx); /*int*/
  return kk_std_time_date__new_Date(year, month, _x_x178, _ctx);
}

kk_std_time_date__date kk_std_time_date__lp__plus__rp_(kk_std_time_date__date d1, kk_std_time_date__date d2, kk_context_t* _ctx); /* (d1 : date, d2 : date) -> date */ 

kk_std_time_date__clock kk_std_time_date_clock_fs__lp__plus__rp_(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx); /* (c : clock, d : clock) -> clock */ 

kk_std_time_date__weekday kk_std_time_date_weekday(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> weekday */ 
 
// Return the `:weekday` that comes `n` days after week day `wd`.

static inline kk_std_time_date__weekday kk_std_time_date_weekday_fs__lp__plus__rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx) { /* (wd : weekday, n : int) -> weekday */ 
  kk_integer_t x_10027 = kk_std_time_date_int(wd, _ctx); /*int*/;
  kk_integer_t _x_x204 = kk_integer_add(x_10027,n,kk_context()); /*int*/
  return kk_std_time_date_weekday(_x_x204, _ctx);
}
 
// Return the difference between two week days:
// `wd2 == wd1 + (wd2 - wd1)`

static inline kk_integer_t kk_std_time_date_weekday_fs__lp__dash__rp_(kk_std_time_date__weekday wd1, kk_std_time_date__weekday wd2, kk_context_t* _ctx) { /* (wd1 : weekday, wd2 : weekday) -> int */ 
  kk_integer_t x_10029 = kk_std_time_date_int(wd1, _ctx); /*int*/;
  kk_integer_t y_10030 = kk_std_time_date_int(wd2, _ctx); /*int*/;
  kk_integer_t _x_x205 = kk_integer_sub(x_10029,y_10030,kk_context()); /*int*/
  return kk_integer_mod(_x_x205,(kk_integer_from_small(7)),kk_context());
}
 
// Return the `:weekday` that comes `n` days before week day `wd`.

static inline kk_std_time_date__weekday kk_std_time_date_weekdayint_fs__lp__dash__rp_(kk_std_time_date__weekday wd, kk_integer_t n, kk_context_t* _ctx) { /* (wd : weekday, n : int) -> weekday */ 
  kk_integer_t x_10031 = kk_std_time_date_int(wd, _ctx); /*int*/;
  kk_integer_t _x_x206 = kk_integer_sub(x_10031,n,kk_context()); /*int*/
  return kk_std_time_date_weekday(_x_x206, _ctx);
}

kk_std_core_types__order kk_std_time_date_cmp(kk_std_time_date__date d, kk_std_time_date__date e, kk_context_t* _ctx); /* (d : date, e : date) -> order */ 

static inline bool kk_std_time_date__lp__eq__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order _x_x207 = kk_std_time_date_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x207, kk_std_core_types__new_Eq(_ctx), _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_date_total_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> std/num/ddouble/ddouble */ 
 
// Compare two clocks as by their total seconds.

static inline kk_std_core_types__order kk_std_time_date_clock_fs_cmp(kk_std_time_date__clock c, kk_std_time_date__clock d, kk_context_t* _ctx) { /* (c : clock, d : clock) -> order */ 
  kk_std_num_ddouble__ddouble x_10051 = kk_std_time_date_total_seconds(c, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y_10052 = kk_std_time_date_total_seconds(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_core_types__order _match_x126;
  double _x_x216;
  {
    double _x = x_10051.hi;
    _x_x216 = _x; /*float64*/
  }
  double _x_x217;
  {
    double _x_0 = y_10052.hi;
    _x_x217 = _x_0; /*float64*/
  }
  _match_x126 = kk_std_num_float64_cmp(_x_x216, _x_x217, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x126, _ctx)) {
    double _x_x218;
    {
      double _x_1 = x_10051.lo;
      _x_x218 = _x_1; /*float64*/
    }
    double _x_x219;
    {
      double _x_2 = y_10052.lo;
      _x_x219 = _x_2; /*float64*/
    }
    return kk_std_num_float64_cmp(_x_x218, _x_x219, _ctx);
  }
  {
    return _match_x126;
  }
}

static inline bool kk_std_time_date_clock_fs__lp__eq__eq__rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order _x_x220 = kk_std_time_date_clock_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x220, kk_std_core_types__new_Eq(_ctx), _ctx);
}

kk_std_core_types__order kk_std_time_date_weekday_fs_cmp(kk_std_time_date__weekday wd1, kk_std_time_date__weekday wd2, kk_context_t* _ctx); /* (wd1 : weekday, wd2 : weekday) -> order */ 

static inline bool kk_std_time_date_weekday_fs__lp__eq__eq__rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order _x_x221 = kk_std_time_date_weekday_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x221, kk_std_core_types__new_Eq(_ctx), _ctx);
}

static inline bool kk_std_time_date__lp__lt__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order _x_x222 = kk_std_time_date_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x222, kk_std_core_types__new_Lt(_ctx), _ctx);
}

static inline bool kk_std_time_date__lp__excl__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order _x_x223 = kk_std_time_date_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x223, kk_std_core_types__new_Eq(_ctx), _ctx);
}

static inline bool kk_std_time_date_clock_fs__lp__excl__eq__rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order _x_x224 = kk_std_time_date_clock_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x224, kk_std_core_types__new_Eq(_ctx), _ctx);
}

static inline bool kk_std_time_date_weekday_fs__lp__excl__eq__rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order _x_x225 = kk_std_time_date_weekday_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x225, kk_std_core_types__new_Eq(_ctx), _ctx);
}

static inline bool kk_std_time_date__lp__lt__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order _x_x226 = kk_std_time_date_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x226, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_date__lp__gt__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order _x_x227 = kk_std_time_date_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x227, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_date__lp__gt__eq__rp_(kk_std_time_date__date i, kk_std_time_date__date j, kk_context_t* _ctx) { /* (i : date, j : date) -> bool */ 
  kk_std_core_types__order _x_x228 = kk_std_time_date_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x228, kk_std_core_types__new_Lt(_ctx), _ctx);
}

kk_std_time_date__clock kk_std_time_date_clock_fs__copy(kk_std_time_date__clock _this, kk_std_core_types__optional hours, kk_std_core_types__optional minutes, kk_std_core_types__optional seconds, kk_context_t* _ctx); /* (clock, hours : ? int, minutes : ? int, seconds : ? std/num/ddouble/ddouble) -> clock */ 

kk_std_time_date__clock kk_std_time_date_intddouble_fs_clock(kk_integer_t seconds, kk_std_core_types__optional frac, kk_context_t* _ctx); /* (seconds : int, frac : ? std/num/ddouble/ddouble) -> clock */ 

kk_std_time_date__clock kk_std_time_date_ddouble_fs_clock(kk_std_num_ddouble__ddouble seconds, kk_context_t* _ctx); /* (seconds : std/num/ddouble/ddouble) -> clock */ 

kk_std_time_date__clock kk_std_time_date_intfloat64_fs_clock(kk_integer_t seconds, double frac, kk_context_t* _ctx); /* (seconds : int, frac : float64) -> clock */ 

kk_std_time_date__clock kk_std_time_date_leap_fs_clock(kk_std_num_ddouble__ddouble seconds, kk_integer_t leap, kk_context_t* _ctx); /* (seconds : std/num/ddouble/ddouble, leap : int) -> clock */ 

extern kk_std_time_date__clock kk_std_time_date_clock0;

bool kk_std_time_date_is_zero(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> bool */ 

kk_integer_t kk_std_time_date_milli_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> int */ 

kk_integer_t kk_std_time_date_nano_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> int */ 

kk_std_time_date__clock kk_std_time_date_round_to_prec(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (c : clock, prec : ? int) -> clock */ 

kk_string_t kk_std_time_date_show_seconds(kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx); /* (secs : std/num/ddouble/ddouble, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 

static inline bool kk_std_time_date_clock_fs__lp__lt__rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order _x_x294 = kk_std_time_date_clock_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x294, kk_std_core_types__new_Lt(_ctx), _ctx);
}

static inline bool kk_std_time_date_clock_fs__lp__lt__eq__rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order _x_x295 = kk_std_time_date_clock_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x295, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_date_clock_fs__lp__gt__rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order _x_x296 = kk_std_time_date_clock_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x296, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_date_clock_fs__lp__gt__eq__rp_(kk_std_time_date__clock i, kk_std_time_date__clock j, kk_context_t* _ctx) { /* (i : clock, j : clock) -> bool */ 
  kk_std_core_types__order _x_x297 = kk_std_time_date_clock_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x297, kk_std_core_types__new_Lt(_ctx), _ctx);
}
 
// Automatically generated. Tests for the `Mon` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_mon(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Mon(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Tue` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_tue(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Tue(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Wed` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_wed(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Wed(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Thu` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_thu(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Thu(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Fri` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_fri(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Fri(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Sat` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_sat(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Sat(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Sun` constructor of the `:weekday` type.

static inline bool kk_std_time_date_is_sun(kk_std_time_date__weekday weekday_0, kk_context_t* _ctx) { /* (weekday : weekday) -> bool */ 
  if (kk_std_time_date__is_Sun(weekday_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}

kk_string_t kk_std_time_date_weekday_fs_show(kk_std_time_date__weekday wd, kk_context_t* _ctx); /* (wd : weekday) -> string */ 

static inline bool kk_std_time_date_weekday_fs__lp__lt__rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order _x_x305 = kk_std_time_date_weekday_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x305, kk_std_core_types__new_Lt(_ctx), _ctx);
}

static inline bool kk_std_time_date_weekday_fs__lp__lt__eq__rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order _x_x306 = kk_std_time_date_weekday_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x306, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_time_date_weekday_fs__lp__gt__rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order _x_x307 = kk_std_time_date_weekday_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x307, kk_std_core_types__new_Gt(_ctx), _ctx);
}

kk_string_t kk_std_time_date_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx); /* (i : int, width : ? int) -> string */ 

kk_string_t kk_std_time_date_show_year(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> string */ 

kk_string_t kk_std_time_date_show(kk_std_time_date__date d, kk_std_core_types__optional month_prefix, kk_context_t* _ctx); /* (d : date, month-prefix : ? string) -> string */ 

kk_string_t kk_std_time_date_clock_fs_show(kk_std_time_date__clock c, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (c : clock, prec : ? int) -> string */ 

kk_integer_t kk_std_time_date_whole_seconds(kk_std_time_date__clock c, kk_context_t* _ctx); /* (c : clock) -> int */ 
 
// Show a `:weekday` as a 3 letter English string (`Sun.show-short == "Sun"`)

static inline kk_string_t kk_std_time_date_show_short(kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (wd : weekday) -> string */ 
  kk_integer_t _b_x70_71 = kk_integer_from_small(3); /*int*/;
  kk_std_core_sslice__sslice _x_x370;
  kk_string_t _x_x371 = kk_std_time_date_weekday_fs_show(wd, _ctx); /*string*/
  kk_std_core_types__optional _x_x372 = kk_std_core_types__new_Optional(kk_integer_box(_b_x70_71, _ctx), _ctx); /*? 7*/
  _x_x370 = kk_std_core_sslice_first(_x_x371, _x_x372, _ctx); /*sslice/sslice*/
  return kk_std_core_sslice_string(_x_x370, _ctx);
}

static inline bool kk_std_time_date_weekday_fs__lp__gt__eq__rp_(kk_std_time_date__weekday i, kk_std_time_date__weekday j, kk_context_t* _ctx) { /* (i : weekday, j : weekday) -> bool */ 
  kk_std_core_types__order _x_x373 = kk_std_time_date_weekday_fs_cmp(i, j, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x373, kk_std_core_types__new_Lt(_ctx), _ctx);
}

kk_std_time_date__date kk_std_time_date_easter(kk_integer_t year, kk_context_t* _ctx); /* (year : int) -> date */ 

void kk_std_time_date__init(kk_context_t* _ctx);


void kk_std_time_date__done(kk_context_t* _ctx);

#endif // header
