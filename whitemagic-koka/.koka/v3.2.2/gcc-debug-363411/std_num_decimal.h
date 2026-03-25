#pragma once
#ifndef kk_std_num_decimal_H
#define kk_std_num_decimal_H
// Koka generated module: std/num/decimal, koka version: 3.2.2, platform: 64-bit
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
#include "std_num_float64.h"

// type declarations

// value type std/num/decimal/decimal
struct kk_std_num_decimal_Decimal {
  kk_integer_t num;
  kk_integer_t exp;
};
typedef struct kk_std_num_decimal_Decimal kk_std_num_decimal__decimal;
static inline kk_std_num_decimal__decimal kk_std_num_decimal__new_Decimal(kk_integer_t num, kk_integer_t exp, kk_context_t* _ctx) {
  kk_std_num_decimal__decimal _con;
  _con.num = num;
  _con.exp = exp;
  return _con;
}
static inline bool kk_std_num_decimal__is_Decimal(kk_std_num_decimal__decimal x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_num_decimal__decimal kk_std_num_decimal__decimal_dup(kk_std_num_decimal__decimal _x, kk_context_t* _ctx) {
  kk_integer_dup(_x.num, _ctx);
  kk_integer_dup(_x.exp, _ctx);
  return _x;
}
static inline void kk_std_num_decimal__decimal_drop(kk_std_num_decimal__decimal _x, kk_context_t* _ctx) {
  kk_integer_drop(_x.num, _ctx);
  kk_integer_drop(_x.exp, _ctx);
}
static inline kk_box_t kk_std_num_decimal__decimal_box(kk_std_num_decimal__decimal _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_std_num_decimal__decimal, _box, _x, 2 /* scan count */, _ctx);
  return _box;
}
static inline kk_std_num_decimal__decimal kk_std_num_decimal__decimal_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_std_num_decimal__decimal _unbox;
  kk_valuetype_unbox(kk_std_num_decimal__decimal, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// value type std/num/decimal/round
enum kk_std_num_decimal__round_e {
  kk_std_num_decimal_Half_even,
  kk_std_num_decimal_Half_ceiling,
  kk_std_num_decimal_Half_floor,
  kk_std_num_decimal_Half_truncate,
  kk_std_num_decimal_Half_away_from_zero,
  kk_std_num_decimal_Ceiling,
  kk_std_num_decimal_Floor,
  kk_std_num_decimal_Truncate,
  kk_std_num_decimal_Away_from_zero
};
typedef uint8_t kk_std_num_decimal__round;

static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_even(kk_context_t* _ctx) {
  return kk_std_num_decimal_Half_even;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_ceiling(kk_context_t* _ctx) {
  return kk_std_num_decimal_Half_ceiling;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_floor(kk_context_t* _ctx) {
  return kk_std_num_decimal_Half_floor;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_truncate(kk_context_t* _ctx) {
  return kk_std_num_decimal_Half_truncate;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Half_away_from_zero(kk_context_t* _ctx) {
  return kk_std_num_decimal_Half_away_from_zero;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Ceiling(kk_context_t* _ctx) {
  return kk_std_num_decimal_Ceiling;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Floor(kk_context_t* _ctx) {
  return kk_std_num_decimal_Floor;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Truncate(kk_context_t* _ctx) {
  return kk_std_num_decimal_Truncate;
}
static inline kk_std_num_decimal__round kk_std_num_decimal__new_Away_from_zero(kk_context_t* _ctx) {
  return kk_std_num_decimal_Away_from_zero;
}
static inline bool kk_std_num_decimal__is_Half_even(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Half_even);
}
static inline bool kk_std_num_decimal__is_Half_ceiling(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Half_ceiling);
}
static inline bool kk_std_num_decimal__is_Half_floor(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Half_floor);
}
static inline bool kk_std_num_decimal__is_Half_truncate(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Half_truncate);
}
static inline bool kk_std_num_decimal__is_Half_away_from_zero(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Half_away_from_zero);
}
static inline bool kk_std_num_decimal__is_Ceiling(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Ceiling);
}
static inline bool kk_std_num_decimal__is_Floor(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Floor);
}
static inline bool kk_std_num_decimal__is_Truncate(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Truncate);
}
static inline bool kk_std_num_decimal__is_Away_from_zero(kk_std_num_decimal__round x, kk_context_t* _ctx) {
  return (x == kk_std_num_decimal_Away_from_zero);
}
static inline kk_std_num_decimal__round kk_std_num_decimal__round_dup(kk_std_num_decimal__round _x, kk_context_t* _ctx) {
  return _x;
}
static inline void kk_std_num_decimal__round_drop(kk_std_num_decimal__round _x, kk_context_t* _ctx) {
  
}
static inline kk_box_t kk_std_num_decimal__round_box(kk_std_num_decimal__round _x, kk_context_t* _ctx) {
  return kk_enum_box(_x);
}
static inline kk_std_num_decimal__round kk_std_num_decimal__round_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return (kk_std_num_decimal__round)kk_enum_unbox(_x);
}

// value declarations
 
// Automatically generated. Retrieves the `num` constructor field of the `:decimal` type.

static inline kk_integer_t kk_std_num_decimal_decimal_fs_num(kk_std_num_decimal__decimal decimal, kk_context_t* _ctx) { /* (decimal : decimal) -> int */ 
  {
    kk_integer_t _x = decimal.num;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `exp` constructor field of the `:decimal` type.

static inline kk_integer_t kk_std_num_decimal_decimal_fs_exp(kk_std_num_decimal__decimal decimal, kk_context_t* _ctx) { /* (decimal : decimal) -> int */ 
  {
    kk_integer_t _x = decimal.exp;
    return kk_integer_dup(_x, _ctx);
  }
}

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_fs__copy(kk_std_num_decimal__decimal _this, kk_std_core_types__optional num, kk_std_core_types__optional exp, kk_context_t* _ctx); /* (decimal, num : ? int, exp : ? int) -> decimal */ 

extern kk_std_num_decimal__decimal kk_std_num_decimal_zero;
 
// Negate a decimal.

static inline kk_std_num_decimal__decimal kk_std_num_decimal__lp__tilde__rp_(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t _x_x433;
  kk_integer_t _x_x434;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x434 = _x; /*int*/
  }
  _x_x433 = kk_integer_neg(_x_x434,kk_context()); /*int*/
  kk_integer_t _x_x435;
  {
    kk_integer_t _x_0 = x.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x435 = _x_0; /*int*/
  }
  return kk_std_num_decimal__new_Decimal(_x_x433, _x_x435, _ctx);
}
 
// Is this decimal zero?

static inline bool kk_std_num_decimal_is_zero(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_integer_t _brw_x427;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _brw_x427 = _x; /*int*/
  }
  bool _brw_x428 = kk_integer_is_zero_borrow(_brw_x427); /*bool*/;
  kk_integer_drop(_brw_x427, _ctx);
  return _brw_x428;
}
 
// Is the decimal positive?

static inline bool kk_std_num_decimal_is_pos(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_integer_t _brw_x425;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _brw_x425 = _x; /*int*/
  }
  bool _brw_x426 = kk_integer_gt_borrow(_brw_x425,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x425, _ctx);
  return _brw_x426;
}
 
// Is the decimal negative?

static inline bool kk_std_num_decimal_is_neg(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_integer_t _brw_x423;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _brw_x423 = _x; /*int*/
  }
  bool _brw_x424 = kk_integer_lt_borrow(_brw_x423,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x423, _ctx);
  return _brw_x424;
}

kk_std_num_decimal__decimal kk_std_num_decimal_abs(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 
 
// round exponents to specific intervals (7) to avoid too much rescaling

static inline kk_integer_t kk_std_num_decimal_round_exp(kk_integer_t exp, kk_context_t* _ctx) { /* (exp : int) -> int */ 
  bool _match_x419 = kk_integer_is_zero_borrow(exp); /*bool*/;
  if (_match_x419) {
    kk_integer_drop(exp, _ctx);
    return kk_integer_from_small(0);
  }
  {
    kk_integer_t _x_x439 = kk_integer_div(exp,(kk_integer_from_small(7)),kk_context()); /*int*/
    return kk_integer_mul((kk_integer_from_small(7)),_x_x439,kk_context());
  }
}

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_exp(kk_integer_t i, kk_std_core_types__optional exp, kk_context_t* _ctx); /* (i : int, exp : ? int) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_expand(kk_std_num_decimal__decimal x, kk_integer_t e, kk_context_t* _ctx); /* (x : decimal, e : int) -> decimal */ 

kk_std_core_types__order kk_std_num_decimal_cmp(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> order */ 

static inline bool kk_std_num_decimal__lp__excl__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order _x_x454 = kk_std_num_decimal_cmp(x, y, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x454, kk_std_core_types__new_Eq(_ctx), _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_reduce(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__lp__star__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__lp__plus__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__lp__dash__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_div(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_std_core_types__optional min_prec, kk_context_t* _ctx); /* (x : decimal, y : decimal, min-prec : ? int) -> decimal */ 
 
// Divide two decimals using 15 digits of extra precision.

static inline kk_std_num_decimal__decimal kk_std_num_decimal__lp__fs__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  return kk_std_num_decimal_div(x, y, kk_std_core_types__new_None(_ctx), _ctx);
}

static inline bool kk_std_num_decimal__lp__lt__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order _x_x498 = kk_std_num_decimal_cmp(x, y, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x498, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_num_decimal__lp__eq__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order _x_x499 = kk_std_num_decimal_cmp(x, y, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x499, kk_std_core_types__new_Eq(_ctx), _ctx);
}

static inline bool kk_std_num_decimal__lp__gt__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order _x_x500 = kk_std_num_decimal_cmp(x, y, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x500, kk_std_core_types__new_Gt(_ctx), _ctx);
}

static inline bool kk_std_num_decimal__lp__gt__eq__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order _x_x501 = kk_std_num_decimal_cmp(x, y, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x501, kk_std_core_types__new_Lt(_ctx), _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_max(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_min(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx); /* (x : decimal, y : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_int_fs_decimal(kk_integer_t i, kk_std_core_types__optional exp, kk_context_t* _ctx); /* (i : int, exp : ? int) -> decimal */ 
 
// Increment a decimal

static inline kk_std_num_decimal__decimal kk_std_num_decimal_inc(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t _x_x511;
  kk_integer_t _x_x512;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x512 = _x; /*int*/
  }
  _x_x511 = kk_integer_add_small_const(_x_x512, 1, _ctx); /*int*/
  kk_integer_t _x_x513;
  {
    kk_integer_t _x_0 = x.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x513 = _x_0; /*int*/
  }
  return kk_std_num_decimal__new_Decimal(_x_x511, _x_x513, _ctx);
}
 
// Decrement a decimal

static inline kk_std_num_decimal__decimal kk_std_num_decimal_dec(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t _x_x514;
  kk_integer_t _x_x515;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x515 = _x; /*int*/
  }
  _x_x514 = kk_integer_add_small_const(_x_x515, -1, _ctx); /*int*/
  kk_integer_t _x_x516;
  {
    kk_integer_t _x_0 = x.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x516 = _x_0; /*int*/
  }
  return kk_std_num_decimal__new_Decimal(_x_x514, _x_x516, _ctx);
}
 
// Is this an even decimal?

static inline bool kk_std_num_decimal_is_even(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  bool b_10014;
  kk_integer_t _x_x517;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x517 = _x; /*int*/
  }
  b_10014 = kk_integer_is_odd(_x_x517,kk_context()); /*bool*/
  if (b_10014) {
    return false;
  }
  {
    return true;
  }
}

kk_std_num_decimal__decimal kk_std_num_decimal_round_to_prec(kk_std_num_decimal__decimal x, kk_std_core_types__optional prec, kk_std_core_types__optional rnd, kk_context_t* _ctx); /* (x : decimal, prec : ? int, rnd : ? round) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_round(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx); /* (x : decimal, rnd : ? round) -> decimal */ 

static inline bool kk_std_num_decimal__lp__lt__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> bool */ 
  kk_std_core_types__order _x_x536 = kk_std_num_decimal_cmp(x, y, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x536, kk_std_core_types__new_Lt(_ctx), _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_pow(kk_std_num_decimal__decimal x, kk_integer_t n, kk_context_t* _ctx); /* (x : decimal, n : int) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_float64_fs_decimal(double d, kk_std_core_types__optional max_prec, kk_context_t* _ctx); /* (d : float64, max-prec : ? int) -> decimal */ 
 
// Is this an odd decimal?

static inline bool kk_std_num_decimal_is_odd(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> bool */ 
  kk_integer_t _x_x560;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x560 = _x; /*int*/
  }
  return kk_integer_is_odd(_x_x560,kk_context());
}
 
// Automatically generated. Tests for the `Half-even` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_even(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_even(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Half-ceiling` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_ceiling(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_ceiling(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Half-floor` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_floor(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_floor(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Half-truncate` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_truncate(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_truncate(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Half-away-from-zero` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_half_away_from_zero(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Half_away_from_zero(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Ceiling` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_ceiling(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Ceiling(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Floor` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_floor(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Floor(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Truncate` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_truncate(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Truncate(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `Away-from-zero` constructor of the `:round` type.

static inline bool kk_std_num_decimal_is_away_from_zero(kk_std_num_decimal__round round_0, kk_context_t* _ctx) { /* (round : round) -> bool */ 
  if (kk_std_num_decimal__is_Away_from_zero(round_0, _ctx)) {
    return true;
  }
  {
    return false;
  }
}

kk_integer_t kk_std_num_decimal_int(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx); /* (x : decimal, rnd : ? round) -> int */ 
 
// Optimize: Use float64 division when within precision bounds.

extern kk_integer_t kk_std_num_decimal_maxexp;
#define kk_std_num_decimal_maxpd ((double)(0x1.c6bf52634p49))

extern kk_integer_t kk_std_num_decimal_maxprecise;

extern kk_integer_t kk_std_num_decimal_minprecise;

static inline bool kk_std_num_decimal_is_precise(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> bool */ 
  bool _match_x343 = kk_integer_gt_borrow(i,kk_std_num_decimal_minprecise,kk_context()); /*bool*/;
  if (_match_x343) {
    bool _brw_x344 = kk_integer_lt_borrow(i,kk_std_num_decimal_maxprecise,kk_context()); /*bool*/;
    kk_integer_drop(i, _ctx);
    return _brw_x344;
  }
  {
    kk_integer_drop(i, _ctx);
    return false;
  }
}

kk_std_core_types__order kk_std_num_decimal_sign(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> order */ 
 
// monadic lift

static inline kk_integer_t kk_std_num_decimal__mlift_pdecimal_10262(kk_char_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : char) -> std/text/parse/parse int */ 
  return kk_std_text_parse_pint(_ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10263(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp, kk_context_t* _ctx); /* (frac : string, neg : bool, whole : string, exp : int) -> std/text/parse/parse decimal */ 
 
// monadic lift

static inline kk_string_t kk_std_num_decimal__mlift_pdecimal_10264(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  return kk_std_text_parse_digits(_ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10265(bool neg, kk_string_t whole, kk_string_t frac, kk_context_t* _ctx); /* (neg : bool, whole : string, frac : string) -> std/text/parse/parse decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10266(bool neg, kk_string_t whole, kk_context_t* _ctx); /* (neg : bool, whole : string) -> std/text/parse/parse decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10267(bool neg, kk_context_t* _ctx); /* (neg : bool) -> std/text/parse/parse decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_pdecimal(kk_context_t* _ctx); /* () -> std/text/parse/parse decimal */ 
 
// monadic lift

static inline kk_std_num_decimal__decimal kk_std_num_decimal__mlift_parse_decimal_10268(kk_std_num_decimal__decimal x, kk_unit_t wild__, kk_context_t* _ctx) { /* (x : decimal, wild_ : ()) -> std/text/parse/parse decimal */ 
  return x;
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_parse_decimal_10269(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> std/text/parse/parse decimal */ 

kk_std_core_types__maybe kk_std_num_decimal_parse_decimal(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> maybe<decimal> */ 

kk_std_num_decimal__decimal kk_std_num_decimal_sum(kk_std_core_types__list ds, kk_context_t* _ctx); /* (ds : list<decimal>) -> decimal */ 
 
// Round a `:decimal` using to the largest integer that is not larger than `x`.

static inline kk_std_num_decimal__decimal kk_std_num_decimal_floor(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_std_core_types__optional _x_x694 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x695 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Floor(_ctx), _ctx), _ctx); /*? 7*/
  return kk_std_num_decimal_round_to_prec(x, _x_x694, _x_x695, _ctx);
}
 
// Round a `:decimal` to the smallest integer that is not less than `x`.

static inline kk_std_num_decimal__decimal kk_std_num_decimal_ceiling(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_std_core_types__optional _x_x696 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x697 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Ceiling(_ctx), _ctx), _ctx); /*? 7*/
  return kk_std_num_decimal_round_to_prec(x, _x_x696, _x_x697, _ctx);
}
 
// Truncate a `:decimal` to an integer by rounding towards zero.

static inline kk_std_num_decimal__decimal kk_std_num_decimal_truncate(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_std_core_types__optional _x_x698 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x699 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Truncate(_ctx), _ctx), _ctx); /*? 7*/
  return kk_std_num_decimal_round_to_prec(x, _x_x698, _x_x699, _ctx);
}

double kk_std_num_decimal_float64(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> float64 */ 

kk_std_num_decimal__decimal kk_std_num_decimal_fraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_std_num_decimal__decimal kk_std_num_decimal_ffraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx); /* (x : decimal) -> decimal */ 

kk_integer_t kk_std_num_decimal_exponent(kk_std_num_decimal__decimal d, kk_context_t* _ctx); /* (d : decimal) -> int */ 

kk_string_t kk_std_num_decimal_show_frac(kk_string_t frac, kk_integer_t prec, kk_context_t* _ctx); /* (frac : string, prec : int) -> string */ 

kk_string_t kk_std_num_decimal_show_exp(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (d : decimal, prec : ? int) -> string */ 

kk_string_t kk_std_num_decimal_show_fixed(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (d : decimal, prec : ? int) -> string */ 

kk_string_t kk_std_num_decimal_show(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx); /* (d : decimal, prec : ? int) -> string */ 

kk_string_t kk_std_num_decimal_show_raw(kk_std_num_decimal__decimal d, kk_context_t* _ctx); /* (d : decimal) -> string */ 

void kk_std_num_decimal__init(kk_context_t* _ctx);


void kk_std_num_decimal__done(kk_context_t* _ctx);

#endif // header
