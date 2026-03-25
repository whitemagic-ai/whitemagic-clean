#pragma once
#ifndef kk_std_num_ddouble_H
#define kk_std_num_ddouble_H
// Koka generated module: std/num/ddouble, koka version: 3.2.2, platform: 64-bit
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
#include "std_core_undiv.h"
#include "std_num_float64.h"
#include "std_num_decimal.h"
#include "std_text_parse.h"

// type declarations

// value type std/num/ddouble/ddouble
struct kk_std_num_ddouble_Ddouble {
  double hi;
  double lo;
};
typedef struct kk_std_num_ddouble_Ddouble kk_std_num_ddouble__ddouble;
static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__new_Ddouble(double hi, double lo, kk_context_t* _ctx) {
  kk_std_num_ddouble__ddouble _con;
  _con.hi = hi;
  _con.lo = lo;
  return _con;
}
static inline bool kk_std_num_ddouble__is_Ddouble(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__ddouble_dup(kk_std_num_ddouble__ddouble _x, kk_context_t* _ctx) {
  kk_skip_dup(_x.hi, _ctx);
  kk_skip_dup(_x.lo, _ctx);
  return _x;
}
static inline void kk_std_num_ddouble__ddouble_drop(kk_std_num_ddouble__ddouble _x, kk_context_t* _ctx) {
  kk_skip_drop(_x.hi, _ctx);
  kk_skip_drop(_x.lo, _ctx);
}
static inline kk_box_t kk_std_num_ddouble__ddouble_box(kk_std_num_ddouble__ddouble _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_ddouble__ddouble, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__ddouble_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_num_ddouble__ddouble _unbox;
  kk_valuetype_unbox(kk_std_num_ddouble__ddouble, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value type std/num/ddouble/edouble
struct kk_std_num_ddouble_Edouble {
  double num;
  double err;
};
typedef struct kk_std_num_ddouble_Edouble kk_std_num_ddouble__edouble;
static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__new_Edouble(double num, double err, kk_context_t* _ctx) {
  kk_std_num_ddouble__edouble _con;
  _con.num = num;
  _con.err = err;
  return _con;
}
static inline bool kk_std_num_ddouble__is_Edouble(kk_std_num_ddouble__edouble x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__edouble_dup(kk_std_num_ddouble__edouble _x, kk_context_t* _ctx) {
  kk_skip_dup(_x.num, _ctx);
  kk_skip_dup(_x.err, _ctx);
  return _x;
}
static inline void kk_std_num_ddouble__edouble_drop(kk_std_num_ddouble__edouble _x, kk_context_t* _ctx) {
  kk_skip_drop(_x.num, _ctx);
  kk_skip_drop(_x.err, _ctx);
}
static inline kk_box_t kk_std_num_ddouble__edouble_box(kk_std_num_ddouble__edouble _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_ddouble__edouble, _box, _x, 0 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_ddouble__edouble kk_std_num_ddouble__edouble_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_num_ddouble__edouble _unbox;
  kk_valuetype_unbox(kk_std_num_ddouble__edouble, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value declarations
 
// Automatically generated. Retrieves the `hi` constructor field of the `:ddouble` type.

static inline double kk_std_num_ddouble_ddouble_fs_hi(kk_std_num_ddouble__ddouble ddouble_0, kk_context_t* _ctx) { /* (ddouble : ddouble) -> float64 */ 
  {
    double _x = ddouble_0.hi;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `lo` constructor field of the `:ddouble` type.

static inline double kk_std_num_ddouble_ddouble_fs_lo(kk_std_num_ddouble__ddouble ddouble_0, kk_context_t* _ctx) { /* (ddouble : ddouble) -> float64 */ 
  {
    double _x = ddouble_0.lo;
    return _x;
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_fs__copy(kk_std_num_ddouble__ddouble _this, kk_std_core_types__optional hi, kk_std_core_types__optional lo, kk_context_t* _ctx); /* (ddouble, hi : ? float64, lo : ? float64) -> ddouble */ 
 
// Create a `:ddouble` from a `:float64`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_float64_fs_ddouble(double d, kk_context_t* _ctx) { /* (d : float64) -> ddouble */ 
  return kk_std_num_ddouble__new_Ddouble(d, 0x0p+0, _ctx);
}

extern kk_integer_t kk_std_num_ddouble_maxprecise;
 
// Compare two `:ddouble` values.

static inline kk_std_core_types__order kk_std_num_ddouble_cmp(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> order */ 
  kk_std_core_types__order _match_x987;
  double _x_x1004;
  {
    double _x = x.hi;
    _x_x1004 = _x; /*float64*/
  }
  double _x_x1005;
  {
    double _x_0 = y.hi;
    _x_x1005 = _x_0; /*float64*/
  }
  _match_x987 = kk_std_num_float64_cmp(_x_x1004, _x_x1005, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x987, _ctx)) {
    double _x_x1006;
    {
      double _x_1 = x.lo;
      _x_x1006 = _x_1; /*float64*/
    }
    double _x_x1007;
    {
      double _x_2 = y.lo;
      _x_x1007 = _x_2; /*float64*/
    }
    return kk_std_num_float64_cmp(_x_x1006, _x_x1007, _ctx);
  }
  {
    return _match_x987;
  }
}

bool kk_std_num_ddouble__lp__excl__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 

bool kk_std_num_ddouble__lp__gt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 

bool kk_std_num_ddouble__lp__lt__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 
 
// Negate a `:ddouble`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__tilde__rp_(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double _x_x1023;
  double _x_x1024;
  {
    double _x = x.hi;
    _x_x1024 = _x; /*float64*/
  }
  _x_x1023 = (-_x_x1024); /*float64*/
  double _x_x1025;
  double _x_x1026;
  {
    double _x_0 = x.lo;
    _x_x1026 = _x_0; /*float64*/
  }
  _x_x1025 = (-_x_x1026); /*float64*/
  return kk_std_num_ddouble__new_Ddouble(_x_x1023, _x_x1025, _ctx);
}

extern kk_integer_t kk_std_num_ddouble_minprecise;

bool kk_std_num_ddouble_is_precise(kk_integer_t i, kk_context_t* _ctx); /* (i : int) -> bool */ 

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_nan;
 
// Is this `:ddouble` equal to is-zero

static inline bool kk_std_num_ddouble_is_zero(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x_x1027;
  {
    double _x = x.hi;
    _x_x1027 = _x; /*float64*/
  }
  return (_x_x1027 == (0x0p+0));
}
 
// Is this `:ddouble` negative?

static inline bool kk_std_num_ddouble_is_neg(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x_x1028;
  {
    double _x = x.hi;
    _x_x1028 = _x; /*float64*/
  }
  return (_x_x1028 < (0x0p+0));
}
 
// Is this a finite `:ddouble`? (i.e. not `is-nan` or `is-inf`)

static inline bool kk_std_num_ddouble_is_finite(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  bool _match_x974;
  double _x_x1029;
  {
    double _x = x.hi;
    _x_x1029 = _x; /*float64*/
  }
  _match_x974 = isfinite(_x_x1029); /*bool*/
  if (_match_x974) {
    double _x_x1030;
    {
      double _x_0 = x.lo;
      _x_x1030 = _x_0; /*float64*/
    }
    return isfinite(_x_x1030);
  }
  {
    return false;
  }
}

bool kk_std_num_ddouble__lp__eq__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 
 
// Automatically generated. Retrieves the `num` constructor field of the `:edouble` type.

static inline double kk_std_num_ddouble_edouble_fs_num(kk_std_num_ddouble__edouble edouble, kk_context_t* _ctx) { /* (edouble : edouble) -> float64 */ 
  {
    double _x = edouble.num;
    return _x;
  }
}
 
// Automatically generated. Retrieves the `err` constructor field of the `:edouble` type.

static inline double kk_std_num_ddouble_edouble_fs_err(kk_std_num_ddouble__edouble edouble, kk_context_t* _ctx) { /* (edouble : edouble) -> float64 */ 
  {
    double _x = edouble.err;
    return _x;
  }
}
 
// Return the absolute value.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x970;
  double _x_x1036;
  {
    double _x = x.hi;
    _x_x1036 = _x; /*float64*/
  }
  _match_x970 = (_x_x1036 < (0x0p+0)); /*bool*/
  if (_match_x970) {
    double _x_x1037;
    double _x_x1038;
    {
      double _x_0 = x.hi;
      _x_x1038 = _x_0; /*float64*/
    }
    _x_x1037 = (-_x_x1038); /*float64*/
    double _x_x1039;
    double _x_x1040;
    {
      double _x_0_0 = x.lo;
      _x_x1040 = _x_0_0; /*float64*/
    }
    _x_x1039 = (-_x_x1040); /*float64*/
    return kk_std_num_ddouble__new_Ddouble(_x_x1037, _x_x1039, _ctx);
  }
  {
    return x;
  }
}
 
// Convert a `:ddouble` to a `:float64` (losing precision)

static inline double kk_std_num_ddouble_float64(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> float64 */ 
  {
    double _x = x.hi;
    return _x;
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dquicksum(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> ddouble */ 
 
// often called `twoproduct` in literature (see [@shewchuk])

static inline kk_std_num_ddouble__edouble kk_std_num_ddouble_prod(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> edouble */ 
  double z = (x * y); /*float64*/;
  double err;
  double _x_x1043 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(x, y, _x_x1043, _ctx); /*float64*/
  return kk_std_num_ddouble__new_Edouble(z, err, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__star__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__edouble kk_std_num_ddouble_quicksum(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> edouble */ 

kk_std_num_ddouble__edouble kk_std_num_ddouble_sum(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> edouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__plus__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 
 
// Subtract two values.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__dash__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x_x1101;
  double _x_x1102;
  double _x_x1103;
  {
    double _x = y.hi;
    _x_x1103 = _x; /*float64*/
  }
  _x_x1102 = (-_x_x1103); /*float64*/
  double _x_x1104;
  double _x_x1105;
  {
    double _x_0 = y.lo;
    _x_x1105 = _x_0; /*float64*/
  }
  _x_x1104 = (-_x_x1105); /*float64*/
  _x_x1101 = kk_std_num_ddouble__new_Ddouble(_x_x1102, _x_x1104, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1101, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__fs__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_dsum(double x, double y, kk_context_t* _ctx); /* (x : float64, y : float64) -> ddouble */ 
 
// Create a `:ddouble` as the sum of two `:float64`'s.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> ddouble */ 
  bool _match_x958 = (y == (0x0p+0)); /*bool*/;
  if (_match_x958) {
    return kk_std_num_ddouble__new_Ddouble(x, 0x0p+0, _ctx);
  }
  {
    return kk_std_num_ddouble_dsum(x, y, _ctx);
  }
}

static inline kk_std_num_ddouble__edouble kk_std_num_ddouble_prodsqr(double x, kk_context_t* _ctx) { /* (x : float64) -> edouble */ 
  double z = (x * x); /*float64*/;
  double err;
  double _x_x1138 = (-z); /*float64*/
  err = kk_std_num_float64_fmadd(x, x, _x_x1138, _ctx); /*float64*/
  return kk_std_num_ddouble__new_Edouble(z, err, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqr(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr_acc(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble acc, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, acc : ddouble, n : int) -> ddouble */ 

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_one;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_npwr(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, n : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_powi(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, n : int) -> ddouble */ 

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_ten;
 
// Return 10 to the power of `exp`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_powi10(kk_integer_t exp_0, kk_context_t* _ctx) { /* (exp : int) -> ddouble */ 
  return kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, exp_0, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_mul_exp10(kk_std_num_ddouble__ddouble x, kk_integer_t exp_0, kk_context_t* _ctx); /* (x : ddouble, exp : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_small_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx); /* (i : int, e : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ddouble_int_exp(kk_integer_t i, kk_integer_t e, kk_context_t* _ctx); /* (i : int, e : int) -> ddouble */ 
 
// Create a `:ddouble` from an `:int`.
// A `:ddouble` can represent integers precisely up to 30 digits.
// If an integer is passed that is out of range an infinity is returned.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_int_fs_ddouble(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> ddouble */ 
  return kk_std_num_ddouble_ddouble_int_exp(i, kk_integer_from_small(0), _ctx);
}
 
// monadic lift

static inline kk_integer_t kk_std_num_ddouble__mlift_pddouble_normal_11161(kk_char_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11162(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t _c_x11107, kk_context_t* _ctx); /* (frac : string, neg : bool, whole : string, int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11163(kk_string_t frac, bool neg, kk_string_t whole, bool _y_x11104, kk_context_t* _ctx); /* (frac : string, neg : bool, whole : string, bool) -> std/text/parse/parse ddouble */ 
 
// monadic lift

static inline kk_string_t kk_std_num_ddouble__mlift_pddouble_normal_11164(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits(_ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11165(bool neg, kk_string_t whole, kk_string_t _c_x11103, kk_context_t* _ctx); /* (neg : bool, whole : string, string) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11166(bool neg, kk_string_t whole, bool _y_x11100, kk_context_t* _ctx); /* (neg : bool, whole : string, bool) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11167(bool neg, kk_string_t whole, kk_context_t* _ctx); /* (neg : bool, whole : string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_normal_11168(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_normal(kk_context_t* _ctx); /* () -> std/text/parse/parse ddouble */ 
 
// monadic lift

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_11169(double hi, double lo, kk_context_t* _ctx) { /* (hi : float64, lo : float64) -> std/text/parse/parse ddouble */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1318 = kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1319 = kk_std_num_ddouble__new_Ddouble(lo, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(_x_x1318, _x_x1319, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_11170(double hi, kk_string_t wild___0, kk_context_t* _ctx); /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_sum_11171(double hi, kk_context_t* _ctx); /* (hi : float64) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble_sum(kk_context_t* _ctx); /* () -> std/text/parse/parse ddouble */ 
 
// monadic lift

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11172(double hi, double lo, kk_context_t* _ctx) { /* (hi : float64, lo : float64) -> std/text/parse/parse ddouble */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1342 = kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1343 = kk_std_num_ddouble__new_Ddouble(lo, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(_x_x1342, _x_x1343, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11173(double hi, kk_string_t wild___0, kk_context_t* _ctx); /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11174(double hi, kk_context_t* _ctx); /* (hi : float64) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_pddouble_11175(bool _y_x11112, kk_context_t* _ctx); /* (bool) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pddouble(kk_context_t* _ctx); /* () -> std/text/parse/parse ddouble */ 
 
// monadic lift

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11176(double hi, double lo, kk_context_t* _ctx) { /* (hi : float64, lo : float64) -> std/text/parse/parse ddouble */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_num_ddouble__ddouble x;
  kk_std_num_ddouble__ddouble _x_x1376 = kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1377 = kk_std_num_ddouble__new_Ddouble(lo, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  x = kk_std_num_ddouble__lp__plus__rp_(_x_x1376, _x_x1377, _ctx); /*std/num/ddouble/ddouble*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11177(double hi, kk_string_t wild___0, kk_context_t* _ctx); /* (hi : float64, wild_@0 : string) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11178(double hi, kk_context_t* _ctx); /* (hi : float64) -> std/text/parse/parse ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__mlift_parse_ddouble_11179(bool _y_x11119, kk_context_t* _ctx); /* (bool) -> std/text/parse/parse ddouble */ 

kk_std_core_types__maybe kk_std_num_ddouble_parse_ddouble(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<ddouble> */ 
 
// Parse a floating point number with up to 31 digits precision.
// Return `dd-nan` if the string is an invalid number.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_string_fs_ddouble(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> ddouble */ 
  kk_std_core_types__maybe m_10162 = kk_std_num_ddouble_parse_ddouble(s, _ctx); /*maybe<std/num/ddouble/ddouble>*/;
  if (kk_std_core_types__is_Nothing(m_10162, _ctx)) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    kk_box_t _box_x186 = m_10162._cons.Just.value;
    kk_std_num_ddouble__ddouble x = kk_std_num_ddouble__ddouble_unbox(_box_x186, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(m_10162, _ctx);
    return x;
  }
}
 
// Decrement by one.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_dec(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x_x1404;
  double _x_x1405;
  double _x_x1406;
  kk_std_num_ddouble__ddouble _x_x1407 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x = _x_x1407.hi;
    _x_x1406 = _x; /*float64*/
  }
  _x_x1405 = (-_x_x1406); /*float64*/
  double _x_x1408;
  double _x_x1409;
  kk_std_num_ddouble__ddouble _x_x1410 = kk_std_num_ddouble_one; /*std/num/ddouble/ddouble*/
  {
    double _x_0 = _x_x1410.lo;
    _x_x1409 = _x_0; /*float64*/
  }
  _x_x1408 = (-_x_x1409); /*float64*/
  _x_x1404 = kk_std_num_ddouble__new_Ddouble(_x_x1405, _x_x1408, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1404, _ctx);
}

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_zero;

kk_unit_t kk_std_num_ddouble_list_fs__lift_sum_11071(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10969, kk_context_t* _ctx); /* forall<h> (comp : local-var<h,ddouble>, total : local-var<h,ddouble>, list<ddouble>) -> (local<h>) () */ 

kk_unit_t kk_std_num_ddouble_list_fs__lift_sum_11070(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10964, kk_context_t* _ctx); /* forall<h> (comp : local-var<h,ddouble>, total : local-var<h,ddouble>, list<ddouble>) -> (local<h>) () */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_sum(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<ddouble>) -> ddouble */ 

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_twopi;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi2;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi4;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi16;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_pi34;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_e;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_ln2;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_ln10;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log2e;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_log10e;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt2;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_sqrt12;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_euler;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_epsilon8;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_max;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_min;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_true_min;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_posinf;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_dd_neginf;
 
// maximal precision in decimal digits of a `:ddouble`.

extern kk_integer_t kk_std_num_ddouble_dd_max_prec;

extern kk_integer_t kk_std_num_ddouble_dd_default_prec;

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_two;
 
// Is this `:ddouble` positive?

static inline bool kk_std_num_ddouble_is_pos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x_x1457;
  {
    double _x = x.hi;
    _x_x1457 = _x; /*float64*/
  }
  return (_x_x1457 > (0x0p+0));
}
 
// Is this `:ddouble` not-a-number?

static inline bool kk_std_num_ddouble_is_nan(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  bool _match_x868;
  double _x_x1458;
  {
    double _x = x.hi;
    _x_x1458 = _x; /*float64*/
  }
  _match_x868 = isnan(_x_x1458); /*bool*/
  if (_match_x868) {
    return true;
  }
  {
    double _x_x1459;
    {
      double _x_0 = x.lo;
      _x_x1459 = _x_0; /*float64*/
    }
    return isnan(_x_x1459);
  }
}
 
// Is this an infinite value.

static inline bool kk_std_num_ddouble_is_inf(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x_x1460;
  {
    double _x = x.hi;
    _x_x1460 = _x; /*float64*/
  }
  return kk_std_num_float64_is_inf(_x_x1460, _ctx);
}
 
// Does `x` equal positive infinity?

static inline bool kk_std_num_ddouble_is_posinf(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x_x1461;
  {
    double _x = x.hi;
    _x_x1461 = _x; /*float64*/
  }
  return (isinf(_x_x1461) && !signbit(_x_x1461));
}
 
// Does `x` equal negative infinity?

static inline bool kk_std_num_ddouble_is_neginf(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> bool */ 
  double _x_x1462;
  {
    double _x = x.hi;
    _x_x1462 = _x; /*float64*/
  }
  return (isinf(_x_x1462) && signbit(_x_x1462));
}

bool kk_std_num_ddouble__lp__gt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 

bool kk_std_num_ddouble__lp__lt__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> bool */ 
 
// Return the sign of the `:ddouble`.

static inline kk_std_core_types__order kk_std_num_ddouble_is_sign(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> order */ 
  bool _match_x860;
  double _x_x1473;
  {
    double _x = x.hi;
    _x_x1473 = _x; /*float64*/
  }
  _match_x860 = (_x_x1473 == (0x0p+0)); /*bool*/
  if (_match_x860) {
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x861;
    double _x_x1474;
    {
      double _x_0 = x.hi;
      _x_x1474 = _x_0; /*float64*/
    }
    _match_x861 = (_x_x1474 < (0x0p+0)); /*bool*/
    if (_match_x861) {
      return kk_std_core_types__new_Lt(_ctx);
    }
    {
      return kk_std_core_types__new_Gt(_ctx);
    }
  }
}
 
// The minimum of `x` and `y`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_min(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x859 = kk_std_num_ddouble__lp__lt__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_x859) {
    return x;
  }
  {
    return y;
  }
}
 
// The maximum of `x` and `y`

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_max(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  bool _match_x858 = kk_std_num_ddouble__lp__gt__eq__rp_(x, y, _ctx); /*bool*/;
  if (_match_x858) {
    return x;
  }
  {
    return y;
  }
}

kk_std_num_ddouble__edouble kk_std_num_ddouble_edouble_fs__copy(kk_std_num_ddouble__edouble _this, kk_std_core_types__optional num, kk_std_core_types__optional err, kk_context_t* _ctx); /* (edouble, num : ? float64, err : ? float64) -> edouble */ 
 
// Increment by one.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_inc(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  return kk_std_num_ddouble__lp__plus__rp_(x, kk_std_num_ddouble_one, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lp__perc__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_core_types__tuple2 kk_std_num_ddouble_divrem(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> (ddouble, ddouble) */ 

kk_std_num_decimal__decimal kk_std_num_ddouble_decimal(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : ? int) -> std/num/decimal/decimal */ 

kk_integer_t kk_std_num_ddouble_int(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional nonfin, kk_context_t* _ctx); /* (x : ddouble, nonfin : ? int) -> int */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_floor(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ceiling(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// Round towards zero.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_truncate(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  bool _match_x828;
  double _x_x1545;
  {
    double _x = x.hi;
    _x_x1545 = _x; /*float64*/
  }
  _match_x828 = (_x_x1545 < (0x0p+0)); /*bool*/
  if (_match_x828) {
    return kk_std_num_ddouble_ceiling(x, _ctx);
  }
  {
    return kk_std_num_ddouble_floor(x, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_fraction(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The _floored_ fraction of `x`. This is always positive, such that `x.floor + x.ffraction == x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ffraction(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble y_10249 = kk_std_num_ddouble_floor(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble _x_x1552;
  double _x_x1553;
  double _x_x1554;
  {
    double _x = y_10249.hi;
    _x_x1554 = _x; /*float64*/
  }
  _x_x1553 = (-_x_x1554); /*float64*/
  double _x_x1555;
  double _x_x1556;
  {
    double _x_0 = y_10249.lo;
    _x_x1556 = _x_0; /*float64*/
  }
  _x_x1555 = (-_x_x1556); /*float64*/
  _x_x1552 = kk_std_num_ddouble__new_Ddouble(_x_x1553, _x_x1555, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(x, _x_x1552, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_round_to_prec(kk_std_num_ddouble__ddouble x, kk_integer_t prec, kk_context_t* _ctx); /* (x : ddouble, prec : int) -> ddouble */ 
 
// 'Load exponent': returns `x`&middot;2^`exp`^.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_ldexp(kk_std_num_ddouble__ddouble x, kk_integer_t exp_0, kk_context_t* _ctx) { /* (x : ddouble, exp : int) -> ddouble */ 
  double _x_x1559;
  double _x_x1560;
  {
    double _x = x.hi;
    _x_x1560 = _x; /*float64*/
  }
  kk_integer_t _x_x1561 = kk_integer_dup(exp_0, _ctx); /*int*/
  _x_x1559 = kk_std_num_float64_ldexp(_x_x1560, _x_x1561, _ctx); /*float64*/
  double _x_x1562;
  double _x_x1563;
  {
    double _x_0 = x.lo;
    _x_x1563 = _x_0; /*float64*/
  }
  _x_x1562 = kk_std_num_float64_ldexp(_x_x1563, exp_0, _ctx); /*float64*/
  return kk_std_num_ddouble__new_Ddouble(_x_x1559, _x_x1562, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_float64_fs_ddouble_exp(double d, kk_integer_t e, kk_context_t* _ctx); /* (d : float64, e : int) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_int_fs_ddouble_exp(kk_integer_t i, kk_integer_t exp_0, kk_context_t* _ctx); /* (i : int, exp : int) -> ddouble */ 
 
// Decode a `:ddouble` `d` into two doubles `(hi,lo)` such that `d` equals  `hi`+`lo`,
// where `lo` &le; 0.5&middot;ulp(`hi`).

static inline kk_std_core_types__tuple2 kk_std_num_ddouble_decode(kk_std_num_ddouble__ddouble d, kk_context_t* _ctx) { /* (d : ddouble) -> (float64, float64) */ 
  kk_box_t _x_x1602;
  double _x_x1603;
  {
    double _x = d.hi;
    _x_x1603 = _x; /*float64*/
  }
  _x_x1602 = kk_double_box(_x_x1603, _ctx); /*10037*/
  kk_box_t _x_x1604;
  double _x_x1605;
  {
    double _x_0 = d.lo;
    _x_x1605 = _x_0; /*float64*/
  }
  _x_x1604 = kk_double_box(_x_x1605, _ctx); /*10038*/
  return kk_std_core_types__new_Tuple2(_x_x1602, _x_x1604, _ctx);
}
 
// Encode a `:ddouble` `d` from two doubles `(hi,lo)` such that `d` equals  `hi`+`lo`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_encode(double hi, double lo, kk_context_t* _ctx) { /* (hi : float64, lo : float64) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x_x1606 = kk_std_num_ddouble__new_Ddouble(hi, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1607 = kk_std_num_ddouble__new_Ddouble(lo, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x_x1606, _x_x1607, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sqrt(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// Multiply `x` by a `:float64` `p` where `p` must be a power of 2.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_mul_pwr2(kk_std_num_ddouble__ddouble x, double p, kk_context_t* _ctx) { /* (x : ddouble, p : float64) -> ddouble */ 
  double _x_x1640;
  double _x_x1641;
  {
    double _x = x.hi;
    _x_x1641 = _x; /*float64*/
  }
  _x_x1640 = (_x_x1641 * p); /*float64*/
  double _x_x1642;
  double _x_x1643;
  {
    double _x_0 = x.lo;
    _x_x1643 = _x_0; /*float64*/
  }
  _x_x1642 = (_x_x1643 * p); /*float64*/
  return kk_std_num_ddouble__new_Ddouble(_x_x1640, _x_x1642, _ctx);
}

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_half(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double _x_x1644;
  double _x_x1645;
  {
    double _x = x.hi;
    _x_x1645 = _x; /*float64*/
  }
  _x_x1644 = (_x_x1645 * (0x1p-1)); /*float64*/
  double _x_x1646;
  double _x_x1647;
  {
    double _x_0 = x.lo;
    _x_x1647 = _x_0; /*float64*/
  }
  _x_x1646 = (_x_x1647 * (0x1p-1)); /*float64*/
  return kk_std_num_ddouble__new_Ddouble(_x_x1644, _x_x1646, _ctx);
}

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_twice(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  double _x_x1648;
  double _x_x1649;
  {
    double _x = x.hi;
    _x_x1649 = _x; /*float64*/
  }
  _x_x1648 = (_x_x1649 * 0x1p1); /*float64*/
  double _x_x1650;
  double _x_x1651;
  {
    double _x_0 = x.lo;
    _x_x1651 = _x_0; /*float64*/
  }
  _x_x1650 = (_x_x1651 * 0x1p1); /*float64*/
  return kk_std_num_ddouble__new_Ddouble(_x_x1648, _x_x1650, _ctx);
}

extern kk_std_core_types__list kk_std_num_ddouble_exp_factors;

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp_approx(kk_std_num_ddouble__ddouble p, kk_std_num_ddouble__ddouble t, kk_std_num_ddouble__ddouble r, double eps, kk_std_core_types__list fs, kk_std_core_types__optional s, kk_context_t* _ctx); /* (p : ddouble, t : ddouble, r : ddouble, eps : float64, fs : list<ddouble>, s : ? ddouble) -> ddouble */ 

kk_unit_t kk_std_num_ddouble__lift_exp_11073(kk_ref_t acc, kk_integer_t _uniq_end_10985, kk_integer_t _uniq_i_10986, kk_context_t* _ctx); /* forall<h> (acc : local-var<h,ddouble>, int, int) -> (local<h>) () */ 

kk_unit_t kk_std_num_ddouble__lift_exp_11072(kk_ref_t acc, kk_integer_t _uniq_n_10977, kk_context_t* _ctx); /* forall<h> (acc : local-var<h,ddouble>, int) -> (local<h>) () */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ln(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_pow(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp10(kk_std_num_ddouble__ddouble exp_0, kk_context_t* _ctx); /* (exp : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2(kk_std_num_ddouble__ddouble exp_0, kk_context_t* _ctx); /* (exp : ddouble) -> ddouble */ 

kk_string_t kk_std_num_ddouble_show(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : ? int) -> string */ 

kk_string_t kk_std_num_ddouble_show_hex(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx); /* (x : ddouble, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 

kk_string_t kk_std_num_ddouble_show_exp(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : ? int) -> string */ 

kk_string_t kk_std_num_ddouble_show_fixed(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : ? int) -> string */ 

kk_string_t kk_std_num_ddouble_show_sum(kk_std_num_ddouble__ddouble x, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (x : ddouble, prec : ? int) -> string */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_nroot(kk_std_num_ddouble__ddouble x, kk_integer_t n, kk_context_t* _ctx); /* (x : ddouble, n : int) -> ddouble */ 

extern kk_std_num_ddouble__ddouble kk_std_num_ddouble_one_half;
 
// Return the logarithm in some base `b` of a `:ddouble` `x`

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_log(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble base, kk_context_t* _ctx) { /* (x : ddouble, base : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x_x2086 = kk_std_num_ddouble_ln(x, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x2087 = kk_std_num_ddouble_ln(base, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__fs__rp_(_x_x2086, _x_x2087, _ctx);
}
 
// The logarithm in base 10 of `x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_log10(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x_x2088 = kk_std_num_ddouble_ln(x, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__fs__rp_(_x_x2088, kk_std_num_ddouble_dd_ln10, _ctx);
}
 
// The logarithm in base 2 of `x`.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_log2(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble _x_x2089 = kk_std_num_ddouble_ln(x, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__fs__rp_(_x_x2089, kk_std_num_ddouble_dd_ln2, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_ln1p(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_expm1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_log2p1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_exp2m1(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_lnaddexp(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_logaddexp2(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

bool kk_std_num_ddouble_nearly_eq(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_core_types__optional epsilon, kk_context_t* _ctx); /* (x : ddouble, y : ddouble, epsilon : ? ddouble) -> bool */ 
 
// Return if two `:ddouble`s are nearly equal with respect to an `epsilon` of `10*dd-epsilon`.
// See also `nearly-eq` which takes an explicit `epsilon`.

static inline bool kk_std_num_ddouble__lp__tilde__eq__rp_(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> bool */ 
  return kk_std_num_ddouble_nearly_eq(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_xyz_fs_hypot(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble z, kk_context_t* _ctx); /* (x : ddouble, y : ddouble, z : ddouble) -> ddouble */ 
 
// The maximum of the absolute values.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_abs_max(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx) { /* (x : ddouble, y : ddouble) -> ddouble */ 
  kk_std_num_ddouble__ddouble x_0_10484 = kk_std_num_ddouble_abs(x, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble y_0_10485 = kk_std_num_ddouble_abs(y, _ctx); /*std/num/ddouble/ddouble*/;
  bool _match_x684 = kk_std_num_ddouble__lp__gt__eq__rp_(x_0_10484, y_0_10485, _ctx); /*bool*/;
  if (_match_x684) {
    return x_0_10484;
  }
  {
    return y_0_10485;
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_abs_max_11075(kk_std_core_types__list _uniq_xs_11007, kk_std_num_ddouble__ddouble _uniq_z_11008, kk_context_t* _ctx); /* (list<ddouble>, ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_abs_max_11074(kk_std_core_types__list _uniq_xs_10993, kk_std_num_ddouble__ddouble _uniq_z_10994, kk_context_t* _ctx); /* (list<ddouble>, ddouble) -> ddouble */ 
 
// The maximum of a list of absolute values.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_abs_max(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<ddouble>) -> ddouble */ 
  return kk_std_num_ddouble_list_fs__lift_abs_max_11074(xs, kk_std_num_ddouble_zero, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_hypot_11077(kk_std_core_types__list _uniq_xs_11031, kk_std_num_ddouble__ddouble _uniq_z_11032, kk_context_t* _ctx); /* (list<ddouble>, ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs__lift_hypot_11076(kk_std_core_types__list _uniq_xs_11017, kk_std_num_ddouble__ddouble _uniq_z_11018, kk_context_t* _ctx); /* (list<ddouble>, ddouble) -> ddouble */ 

kk_std_core_types__list kk_std_num_ddouble_list_fs__trmc_lift_hypot_11079(kk_std_num_ddouble__ddouble hi, kk_std_core_types__list _uniq_xs_11046, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (hi : ddouble, list<ddouble>, ctx<list<ddouble>>) -> list<ddouble> */ 

kk_std_core_types__list kk_std_num_ddouble_list_fs__lift_hypot_11079(kk_std_num_ddouble__ddouble hi_0, kk_std_core_types__list _uniq_xs_11046_0, kk_context_t* _ctx); /* (hi : ddouble, list<ddouble>) -> list<ddouble> */ 

kk_std_core_types__list kk_std_num_ddouble_list_fs__lift_hypot_11078(kk_std_num_ddouble__ddouble hi, kk_std_core_types__list _uniq_xs_11041, kk_context_t* _ctx); /* (hi : ddouble, list<ddouble>) -> list<ddouble> */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_list_fs_hypot(kk_std_core_types__list xs, kk_context_t* _ctx); /* (xs : list<ddouble>) -> ddouble */ 

extern kk_std_core_types__list kk_std_num_ddouble_ch_factors;

extern kk_vector_t kk_std_num_ddouble_sin16_table;
 
// Return sin(i*pi/16) for 0 <= i <= 8

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_sin16(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> ddouble */ 
  kk_std_core_types__maybe m_10492;
  kk_std_core_types__maybe _brw_x672 = kk_std_core_vector_at(kk_std_num_ddouble_sin16_table, i, _ctx); /*maybe<10000>*/;
  kk_integer_drop(i, _ctx);
  m_10492 = _brw_x672; /*maybe<std/num/ddouble/ddouble>*/
  if (kk_std_core_types__is_Nothing(m_10492, _ctx)) {
    return kk_std_num_ddouble_dd_nan;
  }
  {
    kk_box_t _box_x496 = m_10492._cons.Just.value;
    kk_std_num_ddouble__ddouble x = kk_std_num_ddouble__ddouble_unbox(_box_x496, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(m_10492, _ctx);
    return x;
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lift_sincos_11081(kk_std_num_ddouble__ddouble s2, kk_std_core_types__list _uniq_xs_11060, kk_std_num_ddouble__ddouble _uniq_z_11061, kk_context_t* _ctx); /* (s2 : ddouble, list<ddouble>, ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble__lift_sincos_11080(kk_std_num_ddouble__ddouble s2, kk_std_core_types__list _uniq_xs_11054, kk_std_num_ddouble__ddouble _uniq_z_11055, kk_context_t* _ctx); /* (s2 : ddouble, list<ddouble>, ddouble) -> ddouble */ 

kk_std_core_types__tuple2 kk_std_num_ddouble_sincos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx); /* (rad : ddouble) -> (ddouble, ddouble) */ 
 
// The sine function of a given angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_sin(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> ddouble */ 
  kk_std_core_types__tuple2 tuple2_10540 = kk_std_num_ddouble_sincos(rad, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  {
    kk_box_t _box_x553 = tuple2_10540.fst;
    kk_box_t _box_x554 = tuple2_10540.snd;
    kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x553, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10540, _ctx);
    return _x;
  }
}
 
// The cosine function of a given angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_cos(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> ddouble */ 
  kk_std_core_types__tuple2 tuple2_10541 = kk_std_num_ddouble_sincos(rad, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  {
    kk_box_t _box_x555 = tuple2_10541.fst;
    kk_box_t _box_x556 = tuple2_10541.snd;
    kk_std_num_ddouble__ddouble _x = kk_std_num_ddouble__ddouble_unbox(_box_x556, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10541, _ctx);
    return _x;
  }
}
 
// The tangent of a given angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_tan(kk_std_num_ddouble__ddouble rad, kk_context_t* _ctx) { /* (rad : ddouble) -> ddouble */ 
  kk_std_core_types__tuple2 _match_x616 = kk_std_num_ddouble_sincos(rad, _ctx); /*(std/num/ddouble/ddouble, std/num/ddouble/ddouble)*/;
  {
    kk_box_t _box_x557 = _match_x616.fst;
    kk_box_t _box_x558 = _match_x616.snd;
    kk_std_num_ddouble__ddouble s = kk_std_num_ddouble__ddouble_unbox(_box_x557, KK_BORROWED, _ctx);
    kk_std_num_ddouble__ddouble c = kk_std_num_ddouble__ddouble_unbox(_box_x558, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x616, _ctx);
    return kk_std_num_ddouble__lp__fs__rp_(s, c, _ctx);
  }
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_with_sign_of(kk_std_num_ddouble__ddouble x, kk_std_num_ddouble__ddouble y, kk_context_t* _ctx); /* (x : ddouble, y : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan2(kk_std_num_ddouble__ddouble y, kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (y : ddouble, x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asin(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acos(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 
 
// The arc-tangent of `x`. Returns the angle in radians.

static inline kk_std_num_ddouble__ddouble kk_std_num_ddouble_atan(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx) { /* (x : ddouble) -> ddouble */ 
  return kk_std_num_ddouble_atan2(x, kk_std_num_ddouble_one, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_num_ddouble_sinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_cosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_tanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_asinh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_acosh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

kk_std_num_ddouble__ddouble kk_std_num_ddouble_atanh(kk_std_num_ddouble__ddouble x, kk_context_t* _ctx); /* (x : ddouble) -> ddouble */ 

void kk_std_num_ddouble__init(kk_context_t* _ctx);


void kk_std_num_ddouble__done(kk_context_t* _ctx);

#endif // header
