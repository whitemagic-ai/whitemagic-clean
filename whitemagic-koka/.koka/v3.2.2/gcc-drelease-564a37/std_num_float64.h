#pragma once
#ifndef kk_std_num_float64_H
#define kk_std_num_float64_H
// Koka generated module: std/num/float64, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_int32.h"
#include "std_num_int64.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static inline double kk_double_abs(double d) {
  return (isfinite(d) && d < 0.0 ? -d : d);
}


// type declarations

// value declarations
 
// &pi;
#define kk_std_num_float64_pi ((double)(0x1.921fb54442d18p1))
 
// &pi;
#define kk_std_num_float64_flt_pi ((double)(0x1.921fb54442d18p1))
 
// 2&pi;
#define kk_std_num_float64_flt_twopi ((double)(0x1.921fb54442d18p2))
 
// &pi;/2
#define kk_std_num_float64_flt_pi2 ((double)(0x1.921fb54442d18p0))
 
// &pi;/4
#define kk_std_num_float64_flt_pi4 ((double)(0x1.921fb54442d18p-1))
 
// 3&pi;/4
#define kk_std_num_float64_flt_pi34 ((double)(0x1.2d97c7f3321d2p1))
 
// The [_e_](https://en.wikipedia.org/wiki/E_(mathematical_constant)) constant.
#define kk_std_num_float64_flt_e ((double)(0x1.5bf0a8b145769p1))
 
// The natural logarithm of 2
#define kk_std_num_float64_flt_ln2 ((double)(0x1.62e42fefa39efp-1))
 
// The natural logarithm of 10
#define kk_std_num_float64_flt_ln10 ((double)(0x1.26bb1bbb55516p1))
 
// The base-2 logarithm of _e_.
#define kk_std_num_float64_flt_log2e ((double)(0x1.71547652b82fep0))
 
// The base-10 logarithm of _e_.
#define kk_std_num_float64_flt_log10e ((double)(0x1.bcb7b1526e50ep-2))
 
// The square-root of 2
#define kk_std_num_float64_flt_sqrt2 ((double)(0x1.6a09e667f3bcdp0))
 
// `1.0 / sqrt(2.0)`  (= `sqrt(0.5)`)
#define kk_std_num_float64_flt_sqrt12 ((double)(0x1.6a09e667f3bcdp-1))
 
// [Euler's constant](https://en.wikipedia.org/wiki/Euler%E2%80%93Mascheroni_constant)
#define kk_std_num_float64_flt_euler ((double)(0x1.2788cfc6fb619p-1))
 
// Maximum float64 value
#define kk_std_num_float64_flt_max ((double)(0x1.fffffffffffffp1023))
 
// Smallest positive normalized float64 value
#define kk_std_num_float64_flt_min ((double)(0x1p-1022))
 
// Smallest positive subnormal value (i.e. [``DBL_TRUE_MIN``](https://en.cppreference.com/w/cpp/types/climits))
#define kk_std_num_float64_flt_true_min ((double)(0x1p-1074))
 
// Machine epsilon: the difference between 1.0 and the next representable `:float64` value.
#define kk_std_num_float64_flt_epsilon ((double)(0x1p-52))
 
// maximal precision in decimal digits of a `:float64`.

extern kk_integer_t kk_std_num_float64_flt_max_prec;
 
// Is the value negative?

static inline bool kk_std_num_float64_is_neg(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  return (d < (0x0p+0));
}
 
// Returns the largest of two floats

static inline double kk_std_num_float64_max(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_x712 = (x >= y); /*bool*/;
  if (_match_x712) {
    return x;
  }
  {
    return y;
  }
}
 
// Is this a [subnormal](https://en.wikipedia.org/wiki/Denormal_number) value?
// (i.e. `0 < d.abs < flt-min`)

static inline bool kk_std_num_float64_is_subnormal(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  bool _match_x711 = (d != (0x0p+0)); /*bool*/;
  if (_match_x711) {
    double _x_x737 = kk_double_abs(d); /*float64*/
    return (_x_x737 < (0x1p-1022));
  }
  {
    return false;
  }
}

double kk_std_num_float64_float32_fs_float64(float f, kk_context_t* _ctx); /* (f : float32) -> float64 */ 
 
// Convert an 64-bit integer to a `:float64`.

static inline double kk_std_num_float64_int64_fs_float64(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> float64 */ 
  kk_integer_t _x_x738 = kk_integer_from_int64(i,kk_context()); /*int*/
  return kk_integer_as_double(_x_x738,kk_context());
}

double kk_std_num_float64_make_neginf(kk_context_t* _ctx); /* () -> float64 */ 

extern double kk_std_num_float64_neginf;

double kk_std_num_float64_make_posinf(kk_context_t* _ctx); /* () -> float64 */ 

extern double kk_std_num_float64_posinf;
 
// Is the value positive?

static inline bool kk_std_num_float64_is_pos(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  return (d > (0x0p+0));
}
 
// Is the value zero?

static inline bool kk_std_num_float64_is_zero(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  return (d == (0x0p+0));
}
 
// Returns the smallest of two floats

static inline double kk_std_num_float64_min(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_x710 = (x <= y); /*bool*/;
  if (_match_x710) {
    return x;
  }
  {
    return y;
  }
}

double kk_std_num_float64__lift_minimum_10332(kk_std_core_types__list _uniq_xs_10250, double _uniq_z_10251, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

double kk_std_num_float64__lift_minimum_10331(kk_std_core_types__list _uniq_xs_10244, double _uniq_z_10245, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

double kk_std_num_float64_minimum(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

double kk_std_num_float64__lift_maximum_10334(kk_std_core_types__list _uniq_xs_10264, double _uniq_z_10265, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

double kk_std_num_float64__lift_maximum_10333(kk_std_core_types__list _uniq_xs_10258, double _uniq_z_10259, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

double kk_std_num_float64_maximum(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

double kk_std_num_float64_make_nan(kk_context_t* _ctx); /* () -> float64 */ 

extern double kk_std_num_float64_nan;
 
// Compare the argument to zero.

static inline kk_std_core_types__order kk_std_num_float64_sign(double d, kk_context_t* _ctx) { /* (d : float64) -> order */ 
  bool _match_x706 = (d < (0x0p+0)); /*bool*/;
  if (_match_x706) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  {
    bool _match_x707 = (d > (0x0p+0)); /*bool*/;
    if (_match_x707) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Eq(_ctx);
    }
  }
}

kk_string_t kk_std_num_float64_show_fixedx(double d, int32_t prec, kk_context_t* _ctx); /* (d : float64, prec : int32) -> string */ 

kk_string_t kk_std_num_float64_show_expx(double d, int32_t prec, kk_context_t* _ctx); /* (d : float64, prec : int32) -> string */ 

kk_string_t kk_std_num_float64_show_exp(double d, kk_std_core_types__optional precision, kk_context_t* _ctx); /* (d : float64, precision : ? int) -> string */ 

kk_string_t kk_std_num_float64_show_fixed(double d, kk_std_core_types__optional precision, kk_context_t* _ctx); /* (d : float64, precision : ? int) -> string */ 

kk_string_t kk_std_num_float64_show(double d, kk_std_core_types__optional precision, kk_context_t* _ctx); /* (d : float64, precision : ? int) -> string */ 

bool kk_std_num_float64_is_inf(double d, kk_context_t* _ctx); /* (d : float64) -> bool */ 
 
// Is this a negative zero value?

static inline bool kk_std_num_float64_is_negzero(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  bool _match_x699 = (d == (0x0p+0)); /*bool*/;
  if (_match_x699) {
    double _x_x763 = (0x1p0 / d); /*float64*/
    return (isinf(_x_x763) && signbit(_x_x763));
  }
  {
    return false;
  }
}

double kk_std_num_float64_fmadd(double x, double y, double z, kk_context_t* _ctx); /* (x : float64, y : float64, z : float64) -> float64 */ 
 
// Return the integral part of a `:float64` `d` .
// If `d >= 0.0` , return the largest integer equal or less to `d` ,
// If `d < 0.0` , return the smallest integer equal or larger to `d` .

static inline double kk_std_num_float64_truncate(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  bool _match_x698 = (d >= (0x0p+0)); /*bool*/;
  if (_match_x698) {
    return floor(d);
  }
  {
    return ceil(d);
  }
}
 
// Return the fractional part of a `:float64` `d`.
// `d.truncate + d.fraction === d`
// `(-2.4).fraction === -0.4`

static inline double kk_std_num_float64_fraction(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  double _x_x764;
  bool _match_x697 = (d >= (0x0p+0)); /*bool*/;
  if (_match_x697) {
    _x_x764 = floor(d); /*float64*/
  }
  else {
    _x_x764 = ceil(d); /*float64*/
  }
  return (d - _x_x764);
}
 
// Return the 'floored' fraction of `d`, always greater or equal to zero.
// `d.floor + d.ffraction === d`
// `(-2.4).ffraction === 0.6`

static inline double kk_std_num_float64_ffraction(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  double _x_x765 = floor(d); /*float64*/
  return (d - _x_x765);
}

double kk_std_num_float64_round_to_prec(double d, kk_integer_t prec, kk_context_t* _ctx); /* (d : float64, prec : int) -> float64 */ 

float kk_std_num_float64_float64_fs_float32(double f, kk_context_t* _ctx); /* (f : float64) -> float32 */ 
 
// Short version of `float32` for convenience, e.g. `1.337.f32`. For example:
// ```
// > 1.337.show-hex ++ " != " ++ 1.337.f32.float64.show-hex
// "0x1.5645A1CAC0831p+0 != 0x1.5645A2p+0"
// ```
// .

static inline float kk_std_num_float64_f32(double f, kk_context_t* _ctx) { /* (f : float64) -> float32 */ 
  return kk_std_num_float64_float64_fs_float32(f, _ctx);
}
 
// Return the logarithm in base `base` of a `:float64` `f`

static inline double kk_std_num_float64_log(double f, double base, kk_context_t* _ctx) { /* (f : float64, base : float64) -> float64 */ 
  double _x_x769 = log(f); /*float64*/
  double _x_x770 = log(base); /*float64*/
  return (_x_x769 / _x_x770);
}

static inline double kk_std_num_float64_log2p1(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  double _x_x771 = log1p(x); /*float64*/
  return ((0x1.71547652b82fep0) * _x_x771);
}

static inline double kk_std_num_float64_exp2m1(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  double _x_x772 = ((0x1.62e42fefa39efp-1) * x); /*float64*/
  return expm1(_x_x772);
}

double kk_std_num_float64_lnaddexp(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 

double kk_std_num_float64_logaddexp2(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 

bool kk_std_num_float64_nearly_eq(double x, double y, kk_std_core_types__optional epsilon, kk_context_t* _ctx); /* (x : float64, y : float64, epsilon : ? float64) -> bool */ 
 
// Return if two floats are nearly equal with respect to an `epsilon` of `8*flt-epsilon`.
// See also `nearly-eq` which takes an explicit `epsilon`.

static inline bool kk_std_num_float64__lp__tilde__eq__rp_(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> bool */ 
  return kk_std_num_float64_nearly_eq(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

int64_t kk_std_num_float64_float64_to_bits(double d, kk_context_t* _ctx); /* (d : float64) -> int64 */ 

double kk_std_num_float64_float64_from_bits(int64_t i, kk_context_t* _ctx); /* (i : int64) -> float64 */ 

double kk_std_num_float64_exp2i(kk_integer_t e, kk_context_t* _ctx); /* (e : int) -> float64 */ 
#define kk_std_num_float64_one_p1023 ((double)(0x1p1023))
#define kk_std_num_float64_one_m1022 ((double)(0x1p-1022))

static inline double kk_std_num_float64_mul_exp2(double x, kk_integer_t e, kk_context_t* _ctx) { /* (x : float64, e : int) -> float64 */ 
  double _x_x800 = kk_std_num_float64_exp2i(e, _ctx); /*float64*/
  return (x * _x_x800);
}

double kk_std_num_float64_ldexp(double x, kk_integer_t e, kk_context_t* _ctx); /* (x : float64, e : int) -> float64 */ 
 
// Create a float64 `d` given a mantissa `man` and exponent `exp`
// such that `man`&middot;2^`exp`^ =  `d` exactly (if it is representable
// by a `:float64`). See also `ldexp`.

static inline double kk_std_num_float64_encode(kk_integer_t man, kk_integer_t exp, kk_context_t* _ctx) { /* (man : int, exp : int) -> float64 */ 
  double _x_x808 = kk_integer_as_double(man,kk_context()); /*float64*/
  return kk_std_num_float64_ldexp(_x_x808, exp, _ctx);
}

kk_std_core_types__tuple2 kk_std_num_float64_decode_normalized(double d, kk_std_core_types__optional e_adjust, kk_context_t* _ctx); /* (d : float64, e-adjust : ? int) -> (int, int) */ 

kk_std_core_types__tuple2 kk_std_num_float64_decode(double d, kk_context_t* _ctx); /* (d : float64) -> (int, int) */ 

kk_std_core_types__tuple2 kk_std_num_float64_frexp(double x, kk_context_t* _ctx); /* (x : float64) -> (float64, int) */ 

double kk_std_num_float64_next_down(double x, kk_context_t* _ctx); /* (x : float64) -> float64 */ 

double kk_std_num_float64_next_up(double x, kk_context_t* _ctx); /* (x : float64) -> float64 */ 

kk_std_core_types__order kk_std_num_float64_cmp(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> order */ 

double kk_std_num_float64_midpoint(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 

double kk_std_num_float64_lerp(double x, double y, double t, kk_context_t* _ctx); /* (x : float64, y : float64, t : float64) -> float64 */ 

kk_string_t kk_std_num_float64_show_hex(double d, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (d : float64, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
 
// monadic lift

static inline kk_integer_t kk_std_num_float64__mlift_phexdouble_10401(kk_char_t wild___2, kk_context_t* _ctx) { /* (wild_@2 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}

double kk_std_num_float64__mlift_phexdouble_10402(kk_string_t frac, kk_string_t man, kk_integer_t _c_x10360, kk_context_t* _ctx); /* (frac : string, man : string, int) -> float64 */ 

double kk_std_num_float64__mlift_phexdouble_10403(kk_string_t frac, kk_string_t man, bool _y_x10357, kk_context_t* _ctx); /* (frac : string, man : string, bool) -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline kk_string_t kk_std_num_float64__mlift_phexdouble_10404(kk_char_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_hex_digits(_ctx);
}

double kk_std_num_float64__mlift_phexdouble_10405(kk_string_t man, kk_string_t _c_x10356, kk_context_t* _ctx); /* (man : string, string) -> float64 */ 

double kk_std_num_float64__mlift_phexdouble_10406(kk_string_t man, bool _y_x10353, kk_context_t* _ctx); /* (man : string, bool) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift_phexdouble_10407(kk_string_t man, kk_context_t* _ctx); /* (man : string) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift_phexdouble_10408(kk_char_t wild___0, kk_context_t* _ctx); /* (wild_@0 : char) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift_phexdouble_10409(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse float64 */ 

double kk_std_num_float64_phexdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 

double kk_std_num_float64_prim_parse_float64(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> float64 */ 
 
// monadic lift

static inline kk_integer_t kk_std_num_float64__mlift_pdecdouble_10410(kk_char_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10411(kk_std_core_sslice__sslice cur, kk_integer_t _c_x10370, kk_context_t* _ctx); /* (cur : sslice/sslice, int) -> float64 */ 

double kk_std_num_float64__mlift_pdecdouble_10412(kk_std_core_sslice__sslice cur, bool _y_x10367, kk_context_t* _ctx); /* (cur : sslice/sslice, bool) -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline kk_string_t kk_std_num_float64__mlift_pdecdouble_10413(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits0(_ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10414(kk_std_core_sslice__sslice cur, kk_string_t _c_x10366, kk_context_t* _ctx); /* (cur : sslice/sslice, string) -> float64 */ 

double kk_std_num_float64__mlift_pdecdouble_10415(kk_std_core_sslice__sslice cur, bool _y_x10363, kk_context_t* _ctx); /* (cur : sslice/sslice, bool) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift_pdecdouble_10416(kk_std_core_sslice__sslice cur, kk_string_t man, kk_context_t* _ctx); /* (cur : sslice/sslice, man : string) -> std/text/parse/parse float64 */ 

double kk_std_num_float64__mlift_pdecdouble_10417(kk_std_core_sslice__sslice cur, kk_context_t* _ctx); /* (cur : sslice/sslice) -> std/text/parse/parse float64 */ 

double kk_std_num_float64_pdecdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline double kk_std_num_float64__mlift_pspecial_10418(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__, _ctx);
  return kk_std_num_float64_nan;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift_pspecial_10419(kk_string_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild___0, _ctx);
  return kk_std_num_float64_posinf;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift_pspecial_10420(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild___1, _ctx);
  return kk_std_num_float64_posinf;
}

double kk_std_num_float64_pspecial(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 
 
// monadic lift

static inline double kk_std_num_float64__mlift_pdouble_10421(kk_string_t wild__, kk_context_t* _ctx) { /* (wild_ : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild__, _ctx);
  return kk_std_num_float64_nan;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift_pdouble_10422(kk_string_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild___0, _ctx);
  return kk_std_num_float64_posinf;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift_pdouble_10423(kk_string_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(wild___1, _ctx);
  return kk_std_num_float64_posinf;
}
 
// monadic lift

static inline double kk_std_num_float64__mlift_pdouble_10424(bool neg, double _c_x10386, kk_context_t* _ctx) { /* (neg : bool, float64) -> float64 */ 
  if (neg) {
    return (-_c_x10386);
  }
  {
    return _c_x10386;
  }
}

double kk_std_num_float64__mlift_pdouble_10425(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse float64 */ 

double kk_std_num_float64_pdouble(kk_context_t* _ctx); /* () -> std/text/parse/parse float64 */ 

kk_std_core_types__maybe kk_std_num_float64_parse_float64(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<float64> */ 

kk_unit_t kk_std_num_float64__lift_sum_10336(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10277, kk_context_t* _ctx); /* forall<h> (comp : local-var<h,float64>, total : local-var<h,float64>, list<float64>) -> (local<h>) () */ 

kk_unit_t kk_std_num_float64__lift_sum_10335(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10272, kk_context_t* _ctx); /* forall<h> (comp : local-var<h,float64>, total : local-var<h,float64>, list<float64>) -> (local<h>) () */ 

double kk_std_num_float64_sum(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

double kk_std_num_float64_hypot(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> float64 */ 
 
// The square of a float64

static inline double kk_std_num_float64_sqr(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  return (x * x);
}

double kk_std_num_float64_xyz_fs_hypot(double x, double y, double z, kk_context_t* _ctx); /* (x : float64, y : float64, z : float64) -> float64 */ 
 
// The maximum of the absolute values.

static inline double kk_std_num_float64_abs_max(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  double x_0_10132 = kk_double_abs(x); /*float64*/;
  double y_0_10133 = kk_double_abs(y); /*float64*/;
  bool _match_x539 = (x_0_10132 >= y_0_10133); /*bool*/;
  if (_match_x539) {
    return x_0_10132;
  }
  {
    return y_0_10133;
  }
}

double kk_std_num_float64_list_fs__lift_abs_max_10338(kk_std_core_types__list _uniq_xs_10292, double _uniq_z_10293, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

double kk_std_num_float64_list_fs__lift_abs_max_10337(kk_std_core_types__list _uniq_xs_10286, double _uniq_z_10287, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 
 
// The maximum of a list of absolute values.

static inline double kk_std_num_float64_list_fs_abs_max(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  return kk_std_num_float64_list_fs__lift_abs_max_10337(xs, 0x0p+0, _ctx);
}

double kk_std_num_float64_list_fs__lift_hypot_10340(kk_std_core_types__list _uniq_xs_10308, double _uniq_z_10309, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

double kk_std_num_float64_list_fs__lift_hypot_10339(kk_std_core_types__list _uniq_xs_10302, double _uniq_z_10303, kk_context_t* _ctx); /* (list<float64>, float64) -> float64 */ 

kk_std_core_types__list kk_std_num_float64_list_fs__trmc_lift_hypot_10342(double hi, kk_std_core_types__list _uniq_xs_10323, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (hi : float64, list<float64>, ctx<list<float64>>) -> list<float64> */ 

kk_std_core_types__list kk_std_num_float64_list_fs__lift_hypot_10342(double hi_0, kk_std_core_types__list _uniq_xs_10323_0, kk_context_t* _ctx); /* (hi : float64, list<float64>) -> list<float64> */ 

kk_std_core_types__list kk_std_num_float64_list_fs__lift_hypot_10341(double hi, kk_std_core_types__list _uniq_xs_10318, kk_context_t* _ctx); /* (hi : float64, list<float64>) -> list<float64> */ 

double kk_std_num_float64_list_fs_hypot(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<float64>) -> float64 */ 

extern double kk_std_num_float64_rad2deg;

extern double kk_std_num_float64_deg2rad;
 
// Convert radians to degrees.

static inline double kk_std_num_float64_deg(double rad_0, kk_context_t* _ctx) { /* (rad : float64) -> float64 */ 
  return (rad_0 * kk_std_num_float64_rad2deg);
}
 
// Convert degrees to radians.

static inline double kk_std_num_float64_rad(double deg_0, kk_context_t* _ctx) { /* (deg : float64) -> float64 */ 
  return (deg_0 * kk_std_num_float64_deg2rad);
}
 
// Return `x` with the sign of `y`.

static inline double kk_std_num_float64_with_sign_of(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_x529 = (y < (0x0p+0)); /*bool*/;
  if (_match_x529) {
    double _x_x1315 = kk_double_abs(x); /*float64*/
    return (-_x_x1315);
  }
  {
    return kk_double_abs(x);
  }
}

double kk_std_num_float64_atanh(double d, kk_context_t* _ctx); /* (d : float64) -> float64 */ 

double kk_std_num_float64_acosh(double d, kk_context_t* _ctx); /* (d : float64) -> float64 */ 

double kk_std_num_float64_asinh(double d, kk_context_t* _ctx); /* (d : float64) -> float64 */ 

void kk_std_num_float64__init(kk_context_t* _ctx);


void kk_std_num_float64__done(kk_context_t* _ctx);

#endif // header
