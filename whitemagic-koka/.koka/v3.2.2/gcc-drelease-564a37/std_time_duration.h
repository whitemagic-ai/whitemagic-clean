#pragma once
#ifndef kk_std_time_duration_H
#define kk_std_time_duration_H
// Koka generated module: std/time/duration, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_float64.h"
#include "std_num_int32.h"

// type declarations

// value type std/time/duration/duration
struct kk_std_time_duration_Duration {
  kk_std_num_ddouble__ddouble secs;
};
typedef struct kk_std_time_duration_Duration kk_std_time_duration__duration;
static inline kk_std_time_duration__duration kk_std_time_duration__new_Duration(kk_std_num_ddouble__ddouble secs, kk_context_t* _ctx) {
  kk_std_time_duration__duration _con = { secs };
  return _con;
}
static inline bool kk_std_time_duration__is_Duration(kk_std_time_duration__duration x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_duration__duration kk_std_time_duration__duration_dup(kk_std_time_duration__duration _x, kk_context_t* _ctx) {
  kk_std_num_ddouble__ddouble_dup(_x.secs, _ctx);
  return _x;
}
static inline void kk_std_time_duration__duration_drop(kk_std_time_duration__duration _x, kk_context_t* _ctx) {
  kk_std_num_ddouble__ddouble_drop(_x.secs, _ctx);
}
static inline kk_box_t kk_std_time_duration__duration_box(kk_std_time_duration__duration _x, kk_context_t* _ctx) {
  return kk_std_num_ddouble__ddouble_box(_x.secs, _ctx);
}
static inline kk_std_time_duration__duration kk_std_time_duration__duration_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_time_duration__new_Duration(kk_std_num_ddouble__ddouble_unbox(_x, _borrow, _ctx), _ctx);
}

// value declarations
 
// Automatically generated. Retrieves the `secs` constructor field of the `:duration` type.

static inline kk_std_num_ddouble__ddouble kk_std_time_duration_duration_fs_secs(kk_std_time_duration__duration duration_0, kk_context_t* _ctx) { /* (duration : duration) -> std/time/timestamp/timespan */ 
  {
    kk_std_num_ddouble__ddouble _x = duration_0.secs;
    return _x;
  }
}

static inline kk_std_time_duration__duration kk_std_time_duration_duration_fs__copy(kk_std_time_duration__duration _this, kk_std_core_types__optional secs, kk_context_t* _ctx) { /* (duration, secs : ? std/time/timestamp/timespan) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x98;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x0 = secs._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_secs_64 = kk_std_num_ddouble__ddouble_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x98 = _uniq_secs_64; /*std/time/timestamp/timespan*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    {
      kk_std_num_ddouble__ddouble _x = _this.secs;
      _x_x98 = _x; /*std/time/timestamp/timespan*/
    }
  }
  return kk_std_time_duration__new_Duration(_x_x98, _ctx);
}

extern kk_std_time_duration__duration kk_std_time_duration_zero;

extern kk_std_time_duration__duration kk_std_time_duration_duration0;
 
// Convert a `:timespan` to a `:duration`. Be careful to only use
// use this on timespan's that are in TAI SI seconds!

static inline kk_std_time_duration__duration kk_std_time_duration_duration(kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (t : std/time/timestamp/timespan) -> duration */ 
  return kk_std_time_duration__new_Duration(t, _ctx);
}
 
// Convert a `:timestamp` to a `:duration`. Be careful to only use
// use this on timestamp's that are in TAI SI seconds and do not
// contain leap seconds!

static inline kk_std_time_duration__duration kk_std_time_duration_unsafe_duration(kk_std_time_timestamp__timestamp t, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x99 = kk_std_time_timestamp_unsafe_timespan_withleap(t, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x99, _ctx);
}
 
// Return the duration in SI seconds.

static inline kk_std_num_ddouble__ddouble kk_std_time_duration_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timespan */ 
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    return _x;
  }
}
 
// Create a duration from seconds as a `:float64`.

static inline kk_std_time_duration__duration kk_std_time_duration_float64_fs_duration(double secs, kk_context_t* _ctx) { /* (secs : float64) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x100 = kk_std_num_ddouble__new_Ddouble(secs, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x100, _ctx);
}
 
// Create a duration from seconds and a fraction as a `:float64`'s.

static inline kk_std_time_duration__duration kk_std_time_duration_float64frac_fs_duration(double secs, double frac, kk_context_t* _ctx) { /* (secs : float64, frac : float64) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x101;
  bool _match_x97 = (frac == (0x0p+0)); /*bool*/;
  if (_match_x97) {
    _x_x101 = kk_std_num_ddouble__new_Ddouble(secs, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    _x_x101 = kk_std_num_ddouble_dsum(secs, frac, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_time_duration__new_Duration(_x_x101, _ctx);
}

kk_std_time_duration__duration kk_std_time_duration_int_fs_duration(kk_integer_t secs, kk_std_core_types__optional frac, kk_context_t* _ctx); /* (secs : int, frac : ? float64) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_int_fs_seconds(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 
 
// Convert a duration to a `:timespan`.

static inline kk_std_num_ddouble__ddouble kk_std_time_duration_timespan(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> std/time/timestamp/timespan */ 
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    return _x;
  }
}

kk_std_time_timestamp__timestamp kk_std_time_duration_timestamp(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : duration) -> std/time/timestamp/timestamp */ 

kk_integer_t kk_std_time_duration_milli_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : duration) -> int */ 

kk_integer_t kk_std_time_duration_nano_seconds(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : duration) -> int */ 
 
// The whole seconds (in some time unit) of the duration as `:int``. Rounds towards zero.

static inline kk_integer_t kk_std_time_duration_truncate(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> int */ 
  kk_std_num_ddouble__ddouble _x_x133;
  bool _match_x86;
  double _x_x134;
  {
    kk_std_num_ddouble__ddouble _x_0 = d.secs;
    {
      double _x = _x_0.hi;
      _x_x134 = _x; /*float64*/
    }
  }
  _match_x86 = (_x_x134 < (0x0p+0)); /*bool*/
  if (_match_x86) {
    kk_std_num_ddouble__ddouble _x_x135;
    {
      kk_std_num_ddouble__ddouble _x_0_0 = d.secs;
      _x_x135 = _x_0_0; /*std/time/timestamp/timespan*/
    }
    _x_x133 = kk_std_num_ddouble_ceiling(_x_x135, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x136;
    {
      kk_std_num_ddouble__ddouble _x_0_1 = d.secs;
      _x_x136 = _x_0_1; /*std/time/timestamp/timespan*/
    }
    _x_x133 = kk_std_num_ddouble_floor(_x_x136, _ctx); /*std/num/ddouble/ddouble*/
  }
  return kk_std_num_ddouble_int(_x_x133, kk_std_core_types__new_None(_ctx), _ctx);
}

double kk_std_time_duration_fraction(kk_std_time_duration__duration d, kk_context_t* _ctx); /* (d : duration) -> float64 */ 
 
// Is this a negative duration?

static inline bool kk_std_time_duration_is_neg(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> bool */ 
  double _x_x146;
  {
    kk_std_num_ddouble__ddouble _x_0 = d.secs;
    {
      double _x = _x_0.hi;
      _x_x146 = _x; /*float64*/
    }
  }
  return (_x_x146 < (0x0p+0));
}
 
// Is this a zero duration?

static inline bool kk_std_time_duration_is_zero(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> bool */ 
  double _x_x147;
  {
    kk_std_num_ddouble__ddouble _x_0 = d.secs;
    {
      double _x = _x_0.hi;
      _x_x147 = _x; /*float64*/
    }
  }
  return (_x_x147 == (0x0p+0));
}
 
// Is this a positive duration?

static inline bool kk_std_time_duration_is_pos(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> bool */ 
  double _x_x148;
  {
    kk_std_num_ddouble__ddouble _x_0 = d.secs;
    {
      double _x = _x_0.hi;
      _x_x148 = _x; /*float64*/
    }
  }
  return (_x_x148 > (0x0p+0));
}
 
// Compare two `:duration`s.

static inline kk_std_core_types__order kk_std_time_duration_cmp(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> order */ 
  kk_std_core_types__order _match_x84;
  double _x_x149;
  {
    kk_std_num_ddouble__ddouble _x_3 = i.secs;
    {
      double _x = _x_3.hi;
      _x_x149 = _x; /*float64*/
    }
  }
  double _x_x150;
  {
    kk_std_num_ddouble__ddouble _x_4 = j.secs;
    {
      double _x_0 = _x_4.hi;
      _x_x150 = _x_0; /*float64*/
    }
  }
  _match_x84 = kk_std_num_float64_cmp(_x_x149, _x_x150, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x84, _ctx)) {
    double _x_x151;
    {
      kk_std_num_ddouble__ddouble _x_3_0 = i.secs;
      {
        double _x_1 = _x_3_0.lo;
        _x_x151 = _x_1; /*float64*/
      }
    }
    double _x_x152;
    {
      kk_std_num_ddouble__ddouble _x_4_0 = j.secs;
      {
        double _x_2 = _x_4_0.lo;
        _x_x152 = _x_2; /*float64*/
      }
    }
    return kk_std_num_float64_cmp(_x_x151, _x_x152, _ctx);
  }
  {
    return _match_x84;
  }
}

bool kk_std_time_duration__lp__eq__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__lt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__excl__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__lt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__gt__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 

bool kk_std_time_duration__lp__gt__eq__rp_(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx); /* (i : duration, j : duration) -> bool */ 
 
// The minimum of two durations.

static inline kk_std_time_duration__duration kk_std_time_duration_min(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> duration */ 
  bool _match_x65 = kk_std_time_duration__lp__lt__eq__rp_(i, j, _ctx); /*bool*/;
  if (_match_x65) {
    return i;
  }
  {
    return j;
  }
}
 
// The maximum of two durations.

static inline kk_std_time_duration__duration kk_std_time_duration_max(kk_std_time_duration__duration i, kk_std_time_duration__duration j, kk_context_t* _ctx) { /* (i : duration, j : duration) -> duration */ 
  bool _match_x64 = kk_std_time_duration__lp__gt__eq__rp_(i, j, _ctx); /*bool*/;
  if (_match_x64) {
    return i;
  }
  {
    return j;
  }
}
 
// Add two durations.

static inline kk_std_time_duration__duration kk_std_time_duration__lp__plus__rp_(kk_std_time_duration__duration d, kk_std_time_duration__duration e, kk_context_t* _ctx) { /* (d : duration, e : duration) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x183;
  kk_std_num_ddouble__ddouble _x_x184;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x184 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x185;
  {
    kk_std_num_ddouble__ddouble _x_0 = e.secs;
    _x_x185 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x183 = kk_std_num_ddouble__lp__plus__rp_(_x_x184, _x_x185, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x183, _ctx);
}
 
// Negate a duration.

static inline kk_std_time_duration__duration kk_std_time_duration__lp__tilde__rp_(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : duration) -> duration */ 
  kk_std_num_ddouble__ddouble _x_x186;
  double _x_x187;
  double _x_x188;
  {
    kk_std_num_ddouble__ddouble _x_1 = d.secs;
    {
      double _x = _x_1.hi;
      _x_x188 = _x; /*float64*/
    }
  }
  _x_x187 = (-_x_x188); /*float64*/
  double _x_x189;
  double _x_x190;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = d.secs;
    {
      double _x_0 = _x_1_0.lo;
      _x_x190 = _x_0; /*float64*/
    }
  }
  _x_x189 = (-_x_x190); /*float64*/
  _x_x186 = kk_std_num_ddouble__new_Ddouble(_x_x187, _x_x189, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x186, _ctx);
}

kk_std_time_duration__duration kk_std_time_duration__lp__dash__rp_(kk_std_time_duration__duration d, kk_std_time_duration__duration e, kk_context_t* _ctx); /* (d : duration, e : duration) -> duration */ 

kk_string_t kk_std_time_duration_show(kk_std_time_duration__duration d, kk_std_core_types__optional max_prec, kk_context_t* _ctx); /* (d : duration, max-prec : ? int) -> string */ 

kk_std_time_duration__duration kk_std_time_duration_int_fs_milli_seconds(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_minutes(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_hours(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_days(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_weeks(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

kk_std_time_duration__duration kk_std_time_duration_years(kk_integer_t n, kk_context_t* _ctx); /* (n : int) -> duration */ 

void kk_std_time_duration__init(kk_context_t* _ctx);


void kk_std_time_duration__done(kk_context_t* _ctx);

#endif // header
