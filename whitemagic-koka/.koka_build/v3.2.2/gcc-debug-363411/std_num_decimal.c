// Koka generated module: std/num/decimal, koka version: 3.2.2, platform: 64-bit
#include "std_num_decimal.h"

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_fs__copy(kk_std_num_decimal__decimal _this, kk_std_core_types__optional num, kk_std_core_types__optional exp, kk_context_t* _ctx) { /* (decimal, num : ? int, exp : ? int) -> decimal */ 
  kk_integer_t _x_x431;
  if (kk_std_core_types__is_Optional(num, _ctx)) {
    kk_box_t _box_x0 = num._cons._Optional.value;
    kk_integer_t _uniq_num_109 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_num_109, _ctx);
    kk_std_core_types__optional_drop(num, _ctx);
    _x_x431 = _uniq_num_109; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(num, _ctx);
    {
      kk_integer_t _x = _this.num;
      kk_integer_dup(_x, _ctx);
      _x_x431 = _x; /*int*/
    }
  }
  kk_integer_t _x_x432;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x1 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_117 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_exp_117, _ctx);
    kk_std_core_types__optional_drop(exp, _ctx);
    kk_std_num_decimal__decimal_drop(_this, _ctx);
    _x_x432 = _uniq_exp_117; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(exp, _ctx);
    {
      kk_integer_t _x_0 = _this.exp;
      kk_integer_dup(_x_0, _ctx);
      kk_std_num_decimal__decimal_drop(_this, _ctx);
      _x_x432 = _x_0; /*int*/
    }
  }
  return kk_std_num_decimal__new_Decimal(_x_x431, _x_x432, _ctx);
}
 
// The decimal zero.

kk_std_num_decimal__decimal kk_std_num_decimal_zero;
 
// The absolute value of a decimal

kk_std_num_decimal__decimal kk_std_num_decimal_abs(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool _match_x420;
  kk_integer_t _brw_x421;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _brw_x421 = _x; /*int*/
  }
  bool _brw_x422 = kk_integer_lt_borrow(_brw_x421,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x421, _ctx);
  _match_x420 = _brw_x422; /*bool*/
  if (_match_x420) {
    kk_integer_t _x_x436;
    kk_integer_t _x_x437;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x437 = _x_0; /*int*/
    }
    _x_x436 = kk_integer_neg(_x_x437,kk_context()); /*int*/
    kk_integer_t _x_x438;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x438 = _x_1; /*int*/
    }
    return kk_std_num_decimal__new_Decimal(_x_x436, _x_x438, _ctx);
  }
  {
    return x;
  }
}
 
// Create a decimal from an integer `i` with an optional
// exponent `exp` (=`0`) such that the result equals `i`&times;10^`exp`^.

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_exp(kk_integer_t i, kk_std_core_types__optional exp, kk_context_t* _ctx) { /* (i : int, exp : ? int) -> decimal */ 
  kk_integer_t x;
  bool _match_x416;
  kk_integer_t _brw_x417;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x2 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_exp_619, _ctx);
    _brw_x417 = _uniq_exp_619; /*int*/
  }
  else {
    _brw_x417 = kk_integer_from_small(0); /*int*/
  }
  bool _brw_x418 = kk_integer_is_zero_borrow(_brw_x417); /*bool*/;
  kk_integer_drop(_brw_x417, _ctx);
  _match_x416 = _brw_x418; /*bool*/
  if (_match_x416) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x_x440;
    kk_integer_t _x_x441;
    if (kk_std_core_types__is_Optional(exp, _ctx)) {
      kk_box_t _box_x3 = exp._cons._Optional.value;
      kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x3, _ctx);
      kk_integer_dup(_uniq_exp_619_0, _ctx);
      _x_x441 = _uniq_exp_619_0; /*int*/
    }
    else {
      _x_x441 = kk_integer_from_small(0); /*int*/
    }
    _x_x440 = kk_integer_div(_x_x441,(kk_integer_from_small(7)),kk_context()); /*int*/
    x = kk_integer_mul((kk_integer_from_small(7)),_x_x440,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x_x442;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x4 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_exp_619_1, _ctx);
    _x_x442 = _uniq_exp_619_1; /*int*/
  }
  else {
    _x_x442 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x443 = kk_integer_dup(x, _ctx); /*int*/
  diff = kk_integer_sub(_x_x442,_x_x443,kk_context()); /*int*/
  bool _match_x415 = kk_integer_is_zero_borrow(diff); /*bool*/;
  if (_match_x415) {
    kk_integer_drop(x, _ctx);
    kk_integer_drop(diff, _ctx);
    kk_integer_t _x_x444;
    if (kk_std_core_types__is_Optional(exp, _ctx)) {
      kk_box_t _box_x5 = exp._cons._Optional.value;
      kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x5, _ctx);
      kk_integer_dup(_uniq_exp_619_2, _ctx);
      kk_std_core_types__optional_drop(exp, _ctx);
      _x_x444 = _uniq_exp_619_2; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(exp, _ctx);
      _x_x444 = kk_integer_from_small(0); /*int*/
    }
    return kk_std_num_decimal__new_Decimal(i, _x_x444, _ctx);
  }
  {
    kk_std_core_types__optional_drop(exp, _ctx);
    kk_integer_t _x_x445;
    kk_integer_t _x_x446 = kk_integer_abs(diff,kk_context()); /*int*/
    _x_x445 = kk_std_core_int_mul_exp10(i, _x_x446, _ctx); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x445, x, _ctx);
  }
}
 
// Ensure a decimal `x` has an exponent such that `x.exp <= e`.

kk_std_num_decimal__decimal kk_std_num_decimal_expand(kk_std_num_decimal__decimal x, kk_integer_t e, kk_context_t* _ctx) { /* (x : decimal, e : int) -> decimal */ 
  bool _match_x412;
  kk_integer_t _brw_x413;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x413 = _x; /*int*/
  }
  bool _brw_x414 = kk_integer_lte_borrow(_brw_x413,e,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x413, _ctx);
  _match_x412 = _brw_x414; /*bool*/
  if (_match_x412) {
    kk_integer_drop(e, _ctx);
    return x;
  }
  {
    kk_integer_t _x_x447;
    kk_integer_t _x_x448;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x448 = _x_0; /*int*/
    }
    kk_integer_t _x_x449;
    kk_integer_t _x_x450;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x450 = _x_1; /*int*/
    }
    kk_integer_t _x_x451 = kk_integer_dup(e, _ctx); /*int*/
    _x_x449 = kk_integer_sub(_x_x450,_x_x451,kk_context()); /*int*/
    _x_x447 = kk_std_core_int_mul_exp10(_x_x448, _x_x449, _ctx); /*int*/
    kk_std_core_types__optional _x_x452 = kk_std_core_types__new_Optional(kk_integer_box(e, _ctx), _ctx); /*? 7*/
    return kk_std_num_decimal_decimal_exp(_x_x447, _x_x452, _ctx);
  }
}
 
// Compare decimals.

kk_std_core_types__order kk_std_num_decimal_cmp(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> order */ 
  kk_integer_t e;
  bool _match_x408;
  kk_integer_t _brw_x410;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x410 = _x; /*int*/
  }
  kk_integer_t _brw_x409;
  {
    kk_integer_t _x_0 = y.exp;
    kk_integer_dup(_x_0, _ctx);
    _brw_x409 = _x_0; /*int*/
  }
  bool _brw_x411 = kk_integer_lte_borrow(_brw_x410,_brw_x409,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x410, _ctx);
  kk_integer_drop(_brw_x409, _ctx);
  _match_x408 = _brw_x411; /*bool*/
  if (_match_x408) {
    kk_integer_t _x_1 = x.exp;
    kk_integer_dup(_x_1, _ctx);
    e = _x_1; /*int*/
  }
  else {
    kk_integer_t _x_0_0 = y.exp;
    kk_integer_dup(_x_0_0, _ctx);
    e = _x_0_0; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x_x453 = kk_integer_dup(e, _ctx); /*int*/
  xx = kk_std_num_decimal_expand(x, _x_x453, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy = kk_std_num_decimal_expand(y, e, _ctx); /*std/num/decimal/decimal*/;
  bool _match_x400;
  kk_integer_t _brw_x406;
  {
    kk_integer_t _x_1_0 = xx.num;
    kk_integer_dup(_x_1_0, _ctx);
    _brw_x406 = _x_1_0; /*int*/
  }
  kk_integer_t _brw_x405;
  {
    kk_integer_t _x_2 = yy.num;
    kk_integer_dup(_x_2, _ctx);
    _brw_x405 = _x_2; /*int*/
  }
  bool _brw_x407 = kk_integer_eq_borrow(_brw_x406,_brw_x405,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x406, _ctx);
  kk_integer_drop(_brw_x405, _ctx);
  _match_x400 = _brw_x407; /*bool*/
  if (_match_x400) {
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x401;
    kk_integer_t _brw_x403;
    {
      kk_integer_t _x_1_1 = xx.num;
      kk_integer_dup(_x_1_1, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _brw_x403 = _x_1_1; /*int*/
    }
    kk_integer_t _brw_x402;
    {
      kk_integer_t _x_2_0 = yy.num;
      kk_integer_dup(_x_2_0, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _brw_x402 = _x_2_0; /*int*/
    }
    bool _brw_x404 = kk_integer_gt_borrow(_brw_x403,_brw_x402,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x403, _ctx);
    kk_integer_drop(_brw_x402, _ctx);
    _match_x401 = _brw_x404; /*bool*/
    if (_match_x401) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Choose an exponent that minimizes memory usage.

kk_std_num_decimal__decimal kk_std_num_decimal_reduce(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  kk_integer_t p;
  kk_integer_t _x_x455;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x455 = _x; /*int*/
  }
  p = kk_std_core_int_is_exp10(_x_x455, _ctx); /*int*/
  bool b_10032 = kk_integer_gt_borrow(p,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (b_10032) {
    kk_integer_t expp;
    kk_integer_t _x_x456;
    {
      kk_integer_t _x_0 = x.exp;
      kk_integer_dup(_x_0, _ctx);
      _x_x456 = _x_0; /*int*/
    }
    kk_integer_t _x_x457 = kk_integer_dup(p, _ctx); /*int*/
    expp = kk_integer_add(_x_x456,_x_x457,kk_context()); /*int*/
    bool _match_x395;
    kk_integer_t _brw_x398;
    bool _match_x397 = kk_integer_is_zero_borrow(expp); /*bool*/;
    if (_match_x397) {
      _brw_x398 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x_x458;
      kk_integer_t _x_x459 = kk_integer_dup(expp, _ctx); /*int*/
      _x_x458 = kk_integer_div(_x_x459,(kk_integer_from_small(7)),kk_context()); /*int*/
      _brw_x398 = kk_integer_mul((kk_integer_from_small(7)),_x_x458,kk_context()); /*int*/
    }
    kk_integer_t _brw_x396;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      _brw_x396 = _x_1; /*int*/
    }
    bool _brw_x399 = kk_integer_eq_borrow(_brw_x398,_brw_x396,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x398, _ctx);
    kk_integer_drop(_brw_x396, _ctx);
    _match_x395 = _brw_x399; /*bool*/
    if (_match_x395) {
      kk_integer_drop(p, _ctx);
      kk_integer_drop(expp, _ctx);
      return x;
    }
    {
      kk_integer_t _x_x460;
      kk_integer_t _x_x461;
      {
        kk_integer_t _x_2 = x.num;
        kk_integer_dup(_x_2, _ctx);
        kk_std_num_decimal__decimal_drop(x, _ctx);
        _x_x461 = _x_2; /*int*/
      }
      _x_x460 = kk_std_core_int_cdiv_exp10(_x_x461, p, _ctx); /*int*/
      kk_std_core_types__optional _x_x462 = kk_std_core_types__new_Optional(kk_integer_box(expp, _ctx), _ctx); /*? 7*/
      return kk_std_num_decimal_decimal_exp(_x_x460, _x_x462, _ctx);
    }
  }
  {
    kk_integer_drop(p, _ctx);
    return x;
  }
}
 
// Multiply two decimals with full precision.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__star__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_integer_t _b_x10_11;
  kk_integer_t _x_x463;
  {
    kk_integer_t _x_1 = x.exp;
    kk_integer_dup(_x_1, _ctx);
    _x_x463 = _x_1; /*int*/
  }
  kk_integer_t _x_x464;
  {
    kk_integer_t _x_2 = y.exp;
    kk_integer_dup(_x_2, _ctx);
    _x_x464 = _x_2; /*int*/
  }
  _b_x10_11 = kk_integer_add(_x_x463,_x_x464,kk_context()); /*int*/
  kk_std_num_decimal__decimal z;
  kk_integer_t _x_x465;
  kk_integer_t _x_x466;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x466 = _x; /*int*/
  }
  kk_integer_t _x_x467;
  {
    kk_integer_t _x_0 = y.num;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x_x467 = _x_0; /*int*/
  }
  _x_x465 = kk_integer_mul(_x_x466,_x_x467,kk_context()); /*int*/
  kk_std_core_types__optional _x_x468 = kk_std_core_types__new_Optional(kk_integer_box(_b_x10_11, _ctx), _ctx); /*? 7*/
  z = kk_std_num_decimal_decimal_exp(_x_x465, _x_x468, _ctx); /*std/num/decimal/decimal*/
  bool _match_x392;
  kk_integer_t _brw_x393;
  {
    kk_integer_t _x_3 = z.exp;
    kk_integer_dup(_x_3, _ctx);
    _brw_x393 = _x_3; /*int*/
  }
  bool _brw_x394 = kk_integer_lt_borrow(_brw_x393,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x393, _ctx);
  _match_x392 = _brw_x394; /*bool*/
  if (_match_x392) {
    return kk_std_num_decimal_reduce(z, _ctx);
  }
  {
    return z;
  }
}
 
// Add two decimals.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__plus__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_integer_t e;
  bool _match_x388;
  kk_integer_t _brw_x390;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x390 = _x; /*int*/
  }
  kk_integer_t _brw_x389;
  {
    kk_integer_t _x_0 = y.exp;
    kk_integer_dup(_x_0, _ctx);
    _brw_x389 = _x_0; /*int*/
  }
  bool _brw_x391 = kk_integer_lte_borrow(_brw_x390,_brw_x389,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x390, _ctx);
  kk_integer_drop(_brw_x389, _ctx);
  _match_x388 = _brw_x391; /*bool*/
  if (_match_x388) {
    kk_integer_t _x_1 = x.exp;
    kk_integer_dup(_x_1, _ctx);
    e = _x_1; /*int*/
  }
  else {
    kk_integer_t _x_0_0 = y.exp;
    kk_integer_dup(_x_0_0, _ctx);
    e = _x_0_0; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x_x469 = kk_integer_dup(e, _ctx); /*int*/
  xx = kk_std_num_decimal_expand(x, _x_x469, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x_x470 = kk_integer_dup(e, _ctx); /*int*/
  yy = kk_std_num_decimal_expand(y, _x_x470, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x_x471;
  kk_integer_t _x_x472;
  {
    kk_integer_t _x_1_0 = xx.num;
    kk_integer_dup(_x_1_0, _ctx);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x_x472 = _x_1_0; /*int*/
  }
  kk_integer_t _x_x473;
  {
    kk_integer_t _x_2 = yy.num;
    kk_integer_dup(_x_2, _ctx);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x_x473 = _x_2; /*int*/
  }
  _x_x471 = kk_integer_add(_x_x472,_x_x473,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x_x471, e, _ctx);
}
 
// Subtract two decimals.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__dash__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_std_num_decimal__decimal y_0_10225;
  kk_integer_t _x_x474;
  kk_integer_t _x_x475;
  {
    kk_integer_t _x_3 = y.num;
    kk_integer_dup(_x_3, _ctx);
    _x_x475 = _x_3; /*int*/
  }
  _x_x474 = kk_integer_neg(_x_x475,kk_context()); /*int*/
  kk_integer_t _x_x476;
  {
    kk_integer_t _x_0_0 = y.exp;
    kk_integer_dup(_x_0_0, _ctx);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x_x476 = _x_0_0; /*int*/
  }
  y_0_10225 = kk_std_num_decimal__new_Decimal(_x_x474, _x_x476, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t e;
  bool _match_x384;
  kk_integer_t _brw_x386;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x386 = _x; /*int*/
  }
  kk_integer_t _brw_x385;
  {
    kk_integer_t _x_0 = y_0_10225.exp;
    kk_integer_dup(_x_0, _ctx);
    _brw_x385 = _x_0; /*int*/
  }
  bool _brw_x387 = kk_integer_lte_borrow(_brw_x386,_brw_x385,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x386, _ctx);
  kk_integer_drop(_brw_x385, _ctx);
  _match_x384 = _brw_x387; /*bool*/
  if (_match_x384) {
    kk_integer_t _x_1 = x.exp;
    kk_integer_dup(_x_1, _ctx);
    e = _x_1; /*int*/
  }
  else {
    kk_integer_t _x_0_1 = y_0_10225.exp;
    kk_integer_dup(_x_0_1, _ctx);
    e = _x_0_1; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x_x477 = kk_integer_dup(e, _ctx); /*int*/
  xx = kk_std_num_decimal_expand(x, _x_x477, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x_x478 = kk_integer_dup(e, _ctx); /*int*/
  yy = kk_std_num_decimal_expand(y_0_10225, _x_x478, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x_x479;
  kk_integer_t _x_x480;
  {
    kk_integer_t _x_1_0 = xx.num;
    kk_integer_dup(_x_1_0, _ctx);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x_x480 = _x_1_0; /*int*/
  }
  kk_integer_t _x_x481;
  {
    kk_integer_t _x_2 = yy.num;
    kk_integer_dup(_x_2, _ctx);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x_x481 = _x_2; /*int*/
  }
  _x_x479 = kk_integer_add(_x_x480,_x_x481,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x_x479, e, _ctx);
}
 
// /* Divide two decimals with a given extra precision `min-prec` (=`15`).
// The `min-prec` is the number of extra digits used to calculate inexact
// divisions.
// 
// Note: the division uses up to `min-prec` precision using `Floor` rounding
// for the last digit if the result is  inexact. To round differently, you can
// for example divide with larger precision and use `round-to-prec`.
// ```
// > div( decimal(2), decimal(3), 0 )
// 0
// > div( decimal(2), decimal(3), 1 )
// 0.6
// > div( decimal(2), decimal(3) )  // default precision is 15
// 0.6666666666666666
// > div( decimal(2), decimal(3) ).round-to-prec(6)
// 0.666667
// ```
// .
// */

kk_std_num_decimal__decimal kk_std_num_decimal_div(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_std_core_types__optional min_prec, kk_context_t* _ctx) { /* (x : decimal, y : decimal, min-prec : ? int) -> decimal */ 
  bool _match_x376;
  kk_integer_t _brw_x382;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _brw_x382 = _x; /*int*/
  }
  bool _brw_x383 = kk_integer_is_zero_borrow(_brw_x382); /*bool*/;
  kk_integer_drop(_brw_x382, _ctx);
  _match_x376 = _brw_x383; /*bool*/
  if (_match_x376) {
    kk_std_num_decimal__decimal_drop(y, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    kk_std_core_types__optional_drop(min_prec, _ctx);
    return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
  }
  {
    bool _match_x377;
    kk_integer_t _brw_x380;
    {
      kk_integer_t _x_0 = y.num;
      kk_integer_dup(_x_0, _ctx);
      _brw_x380 = _x_0; /*int*/
    }
    bool _brw_x381 = kk_integer_is_zero_borrow(_brw_x380); /*bool*/;
    kk_integer_drop(_brw_x380, _ctx);
    _match_x377 = _brw_x381; /*bool*/
    if (_match_x377) {
      kk_std_num_decimal__decimal_drop(y, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      kk_std_core_types__optional_drop(min_prec, _ctx);
      return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
    }
    {
      kk_integer_t e;
      kk_integer_t _x_x482;
      {
        kk_integer_t _x_1 = x.exp;
        kk_integer_dup(_x_1, _ctx);
        _x_x482 = _x_1; /*int*/
      }
      kk_integer_t _x_x483;
      {
        kk_integer_t _x_2 = y.exp;
        kk_integer_dup(_x_2, _ctx);
        _x_x483 = _x_2; /*int*/
      }
      e = kk_integer_sub(_x_x482,_x_x483,kk_context()); /*int*/
      kk_integer_t xdigits;
      kk_integer_t _x_x484;
      {
        kk_integer_t _x_3 = x.num;
        kk_integer_dup(_x_3, _ctx);
        _x_x484 = _x_3; /*int*/
      }
      xdigits = kk_std_core_int_count_digits(_x_x484, _ctx); /*int*/
      kk_integer_t ydigits;
      kk_integer_t _x_x485;
      {
        kk_integer_t _x_4 = y.num;
        kk_integer_dup(_x_4, _ctx);
        _x_x485 = _x_4; /*int*/
      }
      ydigits = kk_std_core_int_count_digits(_x_x485, _ctx); /*int*/
      kk_integer_t j_10072 = kk_integer_sub(ydigits,xdigits,kk_context()); /*int*/;
      kk_integer_t x_3_10069;
      bool _match_x379 = kk_integer_gte_borrow((kk_integer_from_small(0)),j_10072,kk_context()); /*bool*/;
      if (_match_x379) {
        kk_integer_drop(j_10072, _ctx);
        x_3_10069 = kk_integer_from_small(0); /*int*/
      }
      else {
        x_3_10069 = j_10072; /*int*/
      }
      kk_integer_t extra;
      kk_integer_t _x_x486;
      if (kk_std_core_types__is_Optional(min_prec, _ctx)) {
        kk_box_t _box_x12 = min_prec._cons._Optional.value;
        kk_integer_t _uniq_min_prec_666 = kk_integer_unbox(_box_x12, _ctx);
        kk_integer_dup(_uniq_min_prec_666, _ctx);
        kk_std_core_types__optional_drop(min_prec, _ctx);
        _x_x486 = _uniq_min_prec_666; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(min_prec, _ctx);
        _x_x486 = kk_integer_from_small(15); /*int*/
      }
      extra = kk_integer_add(x_3_10069,_x_x486,kk_context()); /*int*/
      kk_std_num_decimal__decimal _x_x487;
      bool _match_x378 = kk_integer_gt_borrow(extra,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x378) {
        kk_integer_t _b_x13_15;
        kk_integer_t _x_x488 = kk_integer_dup(extra, _ctx); /*int*/
        _b_x13_15 = kk_integer_sub(e,_x_x488,kk_context()); /*int*/
        kk_integer_t _x_x489;
        kk_integer_t _x_x490;
        kk_integer_t _x_x491;
        {
          kk_integer_t _x_5 = x.num;
          kk_integer_dup(_x_5, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x491 = _x_5; /*int*/
        }
        _x_x490 = kk_std_core_int_mul_exp10(_x_x491, extra, _ctx); /*int*/
        kk_integer_t _x_x492;
        {
          kk_integer_t _x_6 = y.num;
          kk_integer_dup(_x_6, _ctx);
          kk_std_num_decimal__decimal_drop(y, _ctx);
          _x_x492 = _x_6; /*int*/
        }
        _x_x489 = kk_integer_div(_x_x490,_x_x492,kk_context()); /*int*/
        kk_std_core_types__optional _x_x493 = kk_std_core_types__new_Optional(kk_integer_box(_b_x13_15, _ctx), _ctx); /*? 7*/
        _x_x487 = kk_std_num_decimal_decimal_exp(_x_x489, _x_x493, _ctx); /*std/num/decimal/decimal*/
      }
      else {
        kk_integer_t _b_x14_16 = kk_integer_sub(e,extra,kk_context()); /*int*/;
        kk_integer_t _x_x494;
        kk_integer_t _x_x495;
        {
          kk_integer_t _x_7 = x.num;
          kk_integer_dup(_x_7, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x495 = _x_7; /*int*/
        }
        kk_integer_t _x_x496;
        {
          kk_integer_t _x_8 = y.num;
          kk_integer_dup(_x_8, _ctx);
          kk_std_num_decimal__decimal_drop(y, _ctx);
          _x_x496 = _x_8; /*int*/
        }
        _x_x494 = kk_integer_div(_x_x495,_x_x496,kk_context()); /*int*/
        kk_std_core_types__optional _x_x497 = kk_std_core_types__new_Optional(kk_integer_box(_b_x14_16, _ctx), _ctx); /*? 7*/
        _x_x487 = kk_std_num_decimal_decimal_exp(_x_x494, _x_x497, _ctx); /*std/num/decimal/decimal*/
      }
      return kk_std_num_decimal_reduce(_x_x487, _ctx);
    }
  }
}
 
// The maximum of `x` and `y`

kk_std_num_decimal__decimal kk_std_num_decimal_max(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  bool _match_x375;
  kk_std_core_types__order _x_x502;
  kk_std_num_decimal__decimal _x_x503 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x_x504 = kk_std_num_decimal__decimal_dup(y, _ctx); /*std/num/decimal/decimal*/
  _x_x502 = kk_std_num_decimal_cmp(_x_x503, _x_x504, _ctx); /*order*/
  _match_x375 = kk_std_core_order__lp__excl__eq__rp_(_x_x502, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x375) {
    kk_std_num_decimal__decimal_drop(y, _ctx);
    return x;
  }
  {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return y;
  }
}
 
// The minimum of `x` and `y`.

kk_std_num_decimal__decimal kk_std_num_decimal_min(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  bool _match_x374;
  kk_std_core_types__order _x_x505;
  kk_std_num_decimal__decimal _x_x506 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x_x507 = kk_std_num_decimal__decimal_dup(y, _ctx); /*std/num/decimal/decimal*/
  _x_x505 = kk_std_num_decimal_cmp(_x_x506, _x_x507, _ctx); /*order*/
  _match_x374 = kk_std_core_order__lp__excl__eq__rp_(_x_x505, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x374) {
    kk_std_num_decimal__decimal_drop(y, _ctx);
    return x;
  }
  {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return y;
  }
}
 
// Create a decimal from an integer `i` with an optional
// exponent `exp` (=`0`) such that the result equals `i`&times;10^`exp`^.

kk_std_num_decimal__decimal kk_std_num_decimal_int_fs_decimal(kk_integer_t i, kk_std_core_types__optional exp, kk_context_t* _ctx) { /* (i : int, exp : ? int) -> decimal */ 
  kk_std_core_types__optional _x_x508;
  kk_box_t _x_x509;
  kk_integer_t _x_x510;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x17 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x17, _ctx);
    kk_integer_dup(_uniq_exp_1807, _ctx);
    kk_std_core_types__optional_drop(exp, _ctx);
    _x_x510 = _uniq_exp_1807; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(exp, _ctx);
    _x_x510 = kk_integer_from_small(0); /*int*/
  }
  _x_x509 = kk_integer_box(_x_x510, _ctx); /*7*/
  _x_x508 = kk_std_core_types__new_Optional(_x_x509, _ctx); /*? 7*/
  return kk_std_num_decimal_decimal_exp(i, _x_x508, _ctx);
}
 
// Round the decimal-point number `x` to
// to a specified number of digits behind the dot `prec` (=`0`) with an optional
// rounding mode `rnd` (=`Half-even`). The precision can be negative.
// `decimal(1,485).round-to-prec(2).show == "1.48"`
// `decimal(112,49).round-to-prec(-1).show == "110"`


// lift anonymous function
struct kk_std_num_decimal_round_to_prec_fun523__t {
  struct kk_function_s _base;
  kk_integer_t p;
  kk_integer_t q;
  kk_integer_t r;
};
static kk_integer_t kk_std_num_decimal_round_to_prec_fun523(kk_function_t _fself, bool keep_on_eq, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_round_to_prec_fun523(kk_integer_t p, kk_integer_t q, kk_integer_t r, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun523__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_round_to_prec_fun523__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_round_to_prec_fun523, kk_context());
  _self->p = p;
  _self->q = q;
  _self->r = r;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_num_decimal_round_to_prec_fun523(kk_function_t _fself, bool keep_on_eq, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun523__t* _self = kk_function_as(struct kk_std_num_decimal_round_to_prec_fun523__t*, _fself, _ctx);
  kk_integer_t p = _self->p; /* int */
  kk_integer_t q = _self->q; /* int */
  kk_integer_t r = _self->r; /* int */
  kk_drop_match(_self, {kk_integer_dup(p, _ctx);kk_integer_dup(q, _ctx);kk_integer_dup(r, _ctx);}, {}, _ctx)
  kk_integer_t half;
  kk_integer_t _x_x524 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), p, _ctx); /*int*/
  half = kk_integer_div(_x_x524,(kk_integer_from_small(2)),kk_context()); /*int*/
  bool _match_x368 = kk_integer_eq_borrow(r,half,kk_context()); /*bool*/;
  if (_match_x368) {
    kk_integer_drop(r, _ctx);
    kk_integer_drop(half, _ctx);
    if (keep_on_eq) {
      return q;
    }
    {
      return kk_integer_add_small_const(q, 1, _ctx);
    }
  }
  {
    bool _match_x369;
    bool _brw_x370 = kk_integer_gt_borrow(r,half,kk_context()); /*bool*/;
    kk_integer_drop(r, _ctx);
    kk_integer_drop(half, _ctx);
    _match_x369 = _brw_x370; /*bool*/
    if (_match_x369) {
      return kk_integer_add_small_const(q, 1, _ctx);
    }
    {
      return q;
    }
  }
}

kk_std_num_decimal__decimal kk_std_num_decimal_round_to_prec(kk_std_num_decimal__decimal x, kk_std_core_types__optional prec, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, prec : ? int, rnd : ? round) -> decimal */ 
  bool _match_x362;
  kk_integer_t _brw_x372;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x372 = _x; /*int*/
  }
  kk_integer_t _brw_x371;
  kk_integer_t _x_x518;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x20 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_1884 = kk_integer_unbox(_box_x20, _ctx);
    kk_integer_dup(_uniq_prec_1884, _ctx);
    _x_x518 = _uniq_prec_1884; /*int*/
  }
  else {
    _x_x518 = kk_integer_from_small(0); /*int*/
  }
  _brw_x371 = kk_integer_neg(_x_x518,kk_context()); /*int*/
  bool _brw_x373 = kk_integer_gte_borrow(_brw_x372,_brw_x371,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x372, _ctx);
  kk_integer_drop(_brw_x371, _ctx);
  _match_x362 = _brw_x373; /*bool*/
  if (_match_x362) {
    kk_std_core_types__optional_drop(rnd, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    return x;
  }
  {
    kk_std_num_decimal__decimal cx = kk_std_num_decimal_reduce(x, _ctx); /*std/num/decimal/decimal*/;
    kk_integer_t x_0_10096;
    kk_integer_t _x_x519;
    {
      kk_integer_t _x_0 = cx.exp;
      kk_integer_dup(_x_0, _ctx);
      _x_x519 = _x_0; /*int*/
    }
    x_0_10096 = kk_integer_neg(_x_x519,kk_context()); /*int*/
    kk_integer_t p;
    kk_integer_t _x_x520;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x21 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_1884_0 = kk_integer_unbox(_box_x21, _ctx);
      kk_integer_dup(_uniq_prec_1884_0, _ctx);
      _x_x520 = _uniq_prec_1884_0; /*int*/
    }
    else {
      _x_x520 = kk_integer_from_small(0); /*int*/
    }
    p = kk_integer_sub(x_0_10096,_x_x520,kk_context()); /*int*/
    bool b_10099 = kk_integer_gt_borrow(p,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (b_10099) {
      kk_std_core_types__tuple2 _match_x363;
      kk_integer_t _x_x521;
      {
        kk_integer_t _x_1 = cx.num;
        kk_integer_dup(_x_1, _ctx);
        kk_std_num_decimal__decimal_drop(cx, _ctx);
        _x_x521 = _x_1; /*int*/
      }
      kk_integer_t _x_x522 = kk_integer_dup(p, _ctx); /*int*/
      _match_x363 = kk_std_core_int_divmod_exp10(_x_x521, _x_x522, _ctx); /*(int, int)*/
      {
        kk_box_t _box_x22 = _match_x363.fst;
        kk_box_t _box_x23 = _match_x363.snd;
        kk_integer_t q = kk_integer_unbox(_box_x22, _ctx);
        kk_integer_t r = kk_integer_unbox(_box_x23, _ctx);
        kk_integer_dup(q, _ctx);
        kk_integer_dup(r, _ctx);
        kk_std_core_types__tuple2_drop(_match_x363, _ctx);
        kk_function_t round_half;
        kk_integer_dup(q, _ctx);
        kk_integer_dup(r, _ctx);
        round_half = kk_std_num_decimal_new_round_to_prec_fun523(p, q, r, _ctx); /*(keep-on-eq : bool) -> int*/
        kk_integer_t q1;
        bool _match_x364;
        bool _brw_x367 = kk_integer_is_zero_borrow(r); /*bool*/;
        kk_integer_drop(r, _ctx);
        _match_x364 = _brw_x367; /*bool*/
        if (_match_x364) {
          kk_function_drop(round_half, _ctx);
          kk_std_core_types__optional_drop(rnd, _ctx);
          q1 = q; /*int*/
        }
        else {
          if (kk_std_core_types__is_Optional(rnd, _ctx)) {
            kk_box_t _box_x24 = rnd._cons._Optional.value;
            kk_std_num_decimal__round _uniq_rnd_1888 = kk_std_num_decimal__round_unbox(_box_x24, KK_BORROWED, _ctx);
            kk_std_core_types__optional_drop(rnd, _ctx);
            if (kk_std_num_decimal__is_Half_even(_uniq_rnd_1888, _ctx)) {
              bool b_10014 = kk_integer_is_odd(q,kk_context()); /*bool*/;
              bool _x_x526;
              if (b_10014) {
                _x_x526 = false; /*bool*/
              }
              else {
                _x_x526 = true; /*bool*/
              }
              q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x526, _ctx), _ctx); /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Half_floor(_uniq_rnd_1888, _ctx)) {
              kk_integer_drop(q, _ctx);
              q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, true, _ctx), _ctx); /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Half_ceiling(_uniq_rnd_1888, _ctx)) {
              kk_integer_drop(q, _ctx);
              q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, false, _ctx), _ctx); /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Half_truncate(_uniq_rnd_1888, _ctx)) {
              bool _x_x527;
              bool _brw_x366 = kk_integer_gt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(q, _ctx);
              _x_x527 = _brw_x366; /*bool*/
              q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x527, _ctx), _ctx); /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Half_away_from_zero(_uniq_rnd_1888, _ctx)) {
              bool _x_x528;
              bool _brw_x365 = kk_integer_lt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(q, _ctx);
              _x_x528 = _brw_x365; /*bool*/
              q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x528, _ctx), _ctx); /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Floor(_uniq_rnd_1888, _ctx)) {
              kk_function_drop(round_half, _ctx);
              q1 = q; /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Ceiling(_uniq_rnd_1888, _ctx)) {
              kk_function_drop(round_half, _ctx);
              q1 = kk_integer_add_small_const(q, 1, _ctx); /*int*/
              goto _match_x525;
            }
            if (kk_std_num_decimal__is_Truncate(_uniq_rnd_1888, _ctx)) {
              kk_function_drop(round_half, _ctx);
              bool b_0_10111 = kk_integer_lt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              if (b_0_10111) {
                q1 = kk_integer_add_small_const(q, 1, _ctx); /*int*/
                goto _match_x525;
              }
              {
                q1 = q; /*int*/
                goto _match_x525;
              }
            }
            {
              kk_function_drop(round_half, _ctx);
              bool b_1_10114 = kk_integer_gt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              if (b_1_10114) {
                q1 = kk_integer_add_small_const(q, 1, _ctx); /*int*/
              }
              else {
                q1 = q; /*int*/
              }
            }
            _match_x525: ;
          }
          else {
            kk_std_core_types__optional_drop(rnd, _ctx);
            bool b_10014_0 = kk_integer_is_odd(q,kk_context()); /*bool*/;
            bool _x_x529;
            if (b_10014_0) {
              _x_x529 = false; /*bool*/
            }
            else {
              _x_x529 = true; /*bool*/
            }
            q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x529, _ctx), _ctx); /*int*/
          }
        }
        kk_integer_t _b_x26_27;
        kk_integer_t _x_x530;
        if (kk_std_core_types__is_Optional(prec, _ctx)) {
          kk_box_t _box_x25 = prec._cons._Optional.value;
          kk_integer_t _uniq_prec_1884_1 = kk_integer_unbox(_box_x25, _ctx);
          kk_integer_dup(_uniq_prec_1884_1, _ctx);
          kk_std_core_types__optional_drop(prec, _ctx);
          _x_x530 = _uniq_prec_1884_1; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(prec, _ctx);
          _x_x530 = kk_integer_from_small(0); /*int*/
        }
        _b_x26_27 = kk_integer_neg(_x_x530,kk_context()); /*int*/
        kk_std_core_types__optional _x_x531 = kk_std_core_types__new_Optional(kk_integer_box(_b_x26_27, _ctx), _ctx); /*? 7*/
        return kk_std_num_decimal_decimal_exp(q1, _x_x531, _ctx);
      }
    }
    {
      kk_std_core_types__optional_drop(rnd, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      kk_integer_drop(p, _ctx);
      return cx;
    }
  }
}
 
// Round a `:decimal` number to a whole number with an optional rounding mode (=`Half-even`).

kk_std_num_decimal__decimal kk_std_num_decimal_round(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, rnd : ? round) -> decimal */ 
  kk_std_core_types__optional _x_x532 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x533;
  kk_box_t _x_x534;
  kk_std_num_decimal__round _x_x535;
  if (kk_std_core_types__is_Optional(rnd, _ctx)) {
    kk_box_t _box_x29 = rnd._cons._Optional.value;
    kk_std_num_decimal__round _uniq_rnd_2229 = kk_std_num_decimal__round_unbox(_box_x29, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x535 = _uniq_rnd_2229; /*std/num/decimal/round*/
  }
  else {
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x535 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  }
  _x_x534 = kk_std_num_decimal__round_box(_x_x535, _ctx); /*7*/
  _x_x533 = kk_std_core_types__new_Optional(_x_x534, _ctx); /*? 7*/
  return kk_std_num_decimal_round_to_prec(x, _x_x532, _x_x533, _ctx);
}
 
// Decimal to the power of `n`

kk_std_num_decimal__decimal kk_std_num_decimal_pow(kk_std_num_decimal__decimal x, kk_integer_t n, kk_context_t* _ctx) { /* (x : decimal, n : int) -> decimal */ 
  kk_integer_t m;
  kk_integer_t _x_x537 = kk_integer_dup(n, _ctx); /*int*/
  m = kk_integer_abs(_x_x537,kk_context()); /*int*/
  kk_integer_t _b_x33_34;
  kk_integer_t _x_x538;
  {
    kk_integer_t _x_0 = x.exp;
    kk_integer_dup(_x_0, _ctx);
    _x_x538 = _x_0; /*int*/
  }
  kk_integer_t _x_x539 = kk_integer_dup(m, _ctx); /*int*/
  _b_x33_34 = kk_integer_mul(_x_x538,_x_x539,kk_context()); /*int*/
  kk_std_num_decimal__decimal y;
  kk_integer_t _x_x540;
  kk_integer_t _x_x541;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x541 = _x; /*int*/
  }
  kk_integer_t _x_x542 = kk_integer_dup(m, _ctx); /*int*/
  _x_x540 = kk_std_core_int_pow(_x_x541, _x_x542, _ctx); /*int*/
  kk_std_core_types__optional _x_x543 = kk_std_core_types__new_Optional(kk_integer_box(_b_x33_34, _ctx), _ctx); /*? 7*/
  y = kk_std_num_decimal_decimal_exp(_x_x540, _x_x543, _ctx); /*std/num/decimal/decimal*/
  bool _match_x359;
  bool _brw_x361 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x359 = _brw_x361; /*bool*/
  if (_match_x359) {
    kk_integer_t _b_x37_39 = kk_integer_add_small_const(m, 3, _ctx); /*int*/;
    kk_integer_t _b_x36_38;
    kk_std_core_types__optional _match_x360 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x360, _ctx)) {
      kk_box_t _box_x35 = _match_x360._cons._Optional.value;
      kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x35, _ctx);
      kk_integer_dup(_uniq_exp_1807, _ctx);
      kk_std_core_types__optional_drop(_match_x360, _ctx);
      _b_x36_38 = _uniq_exp_1807; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x360, _ctx);
      _b_x36_38 = kk_integer_from_small(0); /*int*/
    }
    kk_std_num_decimal__decimal _x_x544;
    kk_std_core_types__optional _x_x545 = kk_std_core_types__new_Optional(kk_integer_box(_b_x36_38, _ctx), _ctx); /*? 7*/
    _x_x544 = kk_std_num_decimal_decimal_exp(kk_integer_from_small(1), _x_x545, _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x546 = kk_std_core_types__new_Optional(kk_integer_box(_b_x37_39, _ctx), _ctx); /*? 7*/
    return kk_std_num_decimal_div(_x_x544, y, _x_x546, _ctx);
  }
  {
    kk_integer_drop(m, _ctx);
    return y;
  }
}
 
// /* Create a decimal from a `:float64` with a specified maximal precision (=`-1`).
// Use a negative maximal precision to create a decimal that precisely represents the `:float64`.
// Note: creating a `:decimal` from a `:float64` may lose precision and give surprising results as many decimal
// fractions cannot be represented precisely by a `:float64`.
// Also, `decimal(i,exp)` is more efficient and better when when exact representations
// are required. For example:
// ```
// > decimal(1.1)
// 1.100000000000000088817841970012523233890533447265625
// > decimal(1.1,17)
// 1.10000000000000008
// > decimal(11,-1)
// 1.1
// ```
// .
// */

kk_std_num_decimal__decimal kk_std_num_decimal_float64_fs_decimal(double d, kk_std_core_types__optional max_prec, kk_context_t* _ctx) { /* (d : float64, max-prec : ? int) -> decimal */ 
  kk_std_core_types__tuple2 _match_x348 = kk_std_num_float64_decode(d, _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x40 = _match_x348.fst;
    kk_box_t _box_x41 = _match_x348.snd;
    kk_integer_t man = kk_integer_unbox(_box_x40, _ctx);
    kk_integer_t exp = kk_integer_unbox(_box_x41, _ctx);
    kk_integer_dup(exp, _ctx);
    kk_integer_dup(man, _ctx);
    kk_std_core_types__tuple2_drop(_match_x348, _ctx);
    bool _match_x349 = kk_integer_gte_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x349) {
      kk_std_core_types__optional_drop(max_prec, _ctx);
      kk_integer_t i_10127;
      kk_integer_t _x_x547 = kk_std_core_int_pow(kk_integer_from_small(2), exp, _ctx); /*int*/
      i_10127 = kk_integer_mul(man,_x_x547,kk_context()); /*int*/
      kk_std_core_types__optional _x_x548;
      kk_box_t _x_x549;
      kk_integer_t _x_x550;
      kk_std_core_types__optional _match_x358 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x358, _ctx)) {
        kk_box_t _box_x42 = _match_x358._cons._Optional.value;
        kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x42, _ctx);
        kk_integer_dup(_uniq_exp_1807, _ctx);
        kk_std_core_types__optional_drop(_match_x358, _ctx);
        _x_x550 = _uniq_exp_1807; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x358, _ctx);
        _x_x550 = kk_integer_from_small(0); /*int*/
      }
      _x_x549 = kk_integer_box(_x_x550, _ctx); /*7*/
      _x_x548 = kk_std_core_types__new_Optional(_x_x549, _ctx); /*? 7*/
      return kk_std_num_decimal_decimal_exp(i_10127, _x_x548, _ctx);
    }
    {
      kk_integer_t prec;
      bool _match_x352;
      kk_integer_t _brw_x356;
      if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
        kk_box_t _box_x44 = max_prec._cons._Optional.value;
        kk_integer_t _uniq_max_prec_2408 = kk_integer_unbox(_box_x44, _ctx);
        kk_integer_dup(_uniq_max_prec_2408, _ctx);
        _brw_x356 = _uniq_max_prec_2408; /*int*/
      }
      else {
        _brw_x356 = kk_integer_from_small(-1); /*int*/
      }
      bool _brw_x357 = kk_integer_lt_borrow(_brw_x356,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x356, _ctx);
      _match_x352 = _brw_x357; /*bool*/
      if (_match_x352) {
        kk_std_core_types__optional_drop(max_prec, _ctx);
        kk_integer_t _x_x551 = kk_integer_dup(exp, _ctx); /*int*/
        prec = kk_integer_neg(_x_x551,kk_context()); /*int*/
      }
      else {
        kk_integer_t j_10132;
        kk_integer_t _x_x552 = kk_integer_dup(exp, _ctx); /*int*/
        j_10132 = kk_integer_neg(_x_x552,kk_context()); /*int*/
        bool _match_x353;
        kk_integer_t _brw_x354;
        if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
          kk_box_t _box_x45 = max_prec._cons._Optional.value;
          kk_integer_t _uniq_max_prec_2408_0 = kk_integer_unbox(_box_x45, _ctx);
          kk_integer_dup(_uniq_max_prec_2408_0, _ctx);
          _brw_x354 = _uniq_max_prec_2408_0; /*int*/
        }
        else {
          _brw_x354 = kk_integer_from_small(-1); /*int*/
        }
        bool _brw_x355 = kk_integer_lte_borrow(_brw_x354,j_10132,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x354, _ctx);
        _match_x353 = _brw_x355; /*bool*/
        if (_match_x353) {
          kk_integer_drop(j_10132, _ctx);
          if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
            kk_box_t _box_x46 = max_prec._cons._Optional.value;
            kk_integer_t _uniq_max_prec_2408_1 = kk_integer_unbox(_box_x46, _ctx);
            kk_integer_dup(_uniq_max_prec_2408_1, _ctx);
            kk_std_core_types__optional_drop(max_prec, _ctx);
            prec = _uniq_max_prec_2408_1; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(max_prec, _ctx);
            prec = kk_integer_from_small(-1); /*int*/
          }
        }
        else {
          kk_std_core_types__optional_drop(max_prec, _ctx);
          prec = j_10132; /*int*/
        }
      }
      kk_integer_t _b_x48_53;
      kk_std_core_types__optional _match_x351 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x351, _ctx)) {
        kk_box_t _box_x47 = _match_x351._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_0 = kk_integer_unbox(_box_x47, _ctx);
        kk_integer_dup(_uniq_exp_1807_0, _ctx);
        kk_std_core_types__optional_drop(_match_x351, _ctx);
        _b_x48_53 = _uniq_exp_1807_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x351, _ctx);
        _b_x48_53 = kk_integer_from_small(0); /*int*/
      }
      kk_std_num_decimal__decimal _x_x553;
      kk_std_core_types__optional _x_x554 = kk_std_core_types__new_Optional(kk_integer_box(_b_x48_53, _ctx), _ctx); /*? 7*/
      _x_x553 = kk_std_num_decimal_decimal_exp(man, _x_x554, _ctx); /*std/num/decimal/decimal*/
      kk_std_num_decimal__decimal _x_x555;
      kk_integer_t _b_x50_54;
      kk_std_core_types__optional _match_x350 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x350, _ctx)) {
        kk_box_t _box_x49 = _match_x350._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_1 = kk_integer_unbox(_box_x49, _ctx);
        kk_integer_dup(_uniq_exp_1807_1, _ctx);
        kk_std_core_types__optional_drop(_match_x350, _ctx);
        _b_x50_54 = _uniq_exp_1807_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x350, _ctx);
        _b_x50_54 = kk_integer_from_small(0); /*int*/
      }
      kk_std_num_decimal__decimal _x_x556;
      kk_std_core_types__optional _x_x557 = kk_std_core_types__new_Optional(kk_integer_box(_b_x50_54, _ctx), _ctx); /*? 7*/
      _x_x556 = kk_std_num_decimal_decimal_exp(kk_integer_from_small(2), _x_x557, _ctx); /*std/num/decimal/decimal*/
      kk_integer_t _x_x558 = kk_integer_neg(exp,kk_context()); /*int*/
      _x_x555 = kk_std_num_decimal_pow(_x_x556, _x_x558, _ctx); /*std/num/decimal/decimal*/
      kk_std_core_types__optional _x_x559 = kk_std_core_types__new_Optional(kk_integer_box(prec, _ctx), _ctx); /*? 7*/
      return kk_std_num_decimal_div(_x_x553, _x_x555, _x_x559, _ctx);
    }
  }
}
 
// Round a `:decimal` number to an integer an optional rounding mode `rnd` (=`Half-even`).

kk_integer_t kk_std_num_decimal_int(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, rnd : ? round) -> int */ 
  kk_std_num_decimal__decimal y;
  kk_std_core_types__optional _x_x561 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x562;
  kk_box_t _x_x563;
  kk_std_num_decimal__round _x_x564;
  if (kk_std_core_types__is_Optional(rnd, _ctx)) {
    kk_box_t _box_x57 = rnd._cons._Optional.value;
    kk_std_num_decimal__round _uniq_rnd_2762 = kk_std_num_decimal__round_unbox(_box_x57, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x564 = _uniq_rnd_2762; /*std/num/decimal/round*/
  }
  else {
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x564 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  }
  _x_x563 = kk_std_num_decimal__round_box(_x_x564, _ctx); /*7*/
  _x_x562 = kk_std_core_types__new_Optional(_x_x563, _ctx); /*? 7*/
  y = kk_std_num_decimal_round_to_prec(x, _x_x561, _x_x562, _ctx); /*std/num/decimal/decimal*/
  bool _match_x345;
  kk_integer_t _brw_x346;
  {
    kk_integer_t _x = y.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x346 = _x; /*int*/
  }
  bool _brw_x347 = kk_integer_gt_borrow(_brw_x346,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x346, _ctx);
  _match_x345 = _brw_x347; /*bool*/
  if (_match_x345) {
    kk_integer_t _x_x565;
    {
      kk_integer_t _x_0 = y.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x565 = _x_0; /*int*/
    }
    kk_integer_t _x_x566;
    {
      kk_integer_t _x_1 = y.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(y, _ctx);
      _x_x566 = _x_1; /*int*/
    }
    return kk_std_core_int_mul_exp10(_x_x565, _x_x566, _ctx);
  }
  {
    kk_integer_t _x_2 = y.num;
    kk_integer_dup(_x_2, _ctx);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    return _x_2;
  }
}

kk_integer_t kk_std_num_decimal_maxexp;

kk_integer_t kk_std_num_decimal_maxprecise;

kk_integer_t kk_std_num_decimal_minprecise;
 
// The sign of a decimal number.

kk_std_core_types__order kk_std_num_decimal_sign(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> order */ 
  bool _match_x337;
  kk_integer_t _brw_x341;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _brw_x341 = _x; /*int*/
  }
  bool _brw_x342 = kk_integer_eq_borrow(_brw_x341,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x341, _ctx);
  _match_x337 = _brw_x342; /*bool*/
  if (_match_x337) {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x338;
    kk_integer_t _brw_x339;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _brw_x339 = _x_0; /*int*/
    }
    bool _brw_x340 = kk_integer_gt_borrow(_brw_x339,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x339, _ctx);
    _match_x338 = _brw_x340; /*bool*/
    if (_match_x338) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10263_fun570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun570(kk_function_t _fself, kk_box_t _b_x65, kk_box_t _b_x66, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10263_fun570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10263_fun570, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun570(kk_function_t _fself, kk_box_t _b_x65, kk_box_t _b_x66, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x571;
  kk_string_t _x_x572 = kk_string_unbox(_b_x65); /*string*/
  bool _x_x573;
  kk_std_core_types__optional _match_x336 = kk_std_core_types__optional_unbox(_b_x66, KK_OWNED, _ctx); /*? bool*/;
  if (kk_std_core_types__is_Optional(_match_x336, _ctx)) {
    kk_box_t _box_x61 = _match_x336._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x61);
    kk_std_core_types__optional_drop(_match_x336, _ctx);
    _x_x573 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x336, _ctx);
    _x_x573 = false; /*bool*/
  }
  _x_x571 = kk_std_core_int_xparse(_x_x572, _x_x573, _ctx); /*maybe<int>*/
  return kk_std_core_types__maybe_box(_x_x571, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10263_fun575__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun575(kk_function_t _fself, kk_box_t _b_x76, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10263_fun575(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10263_fun575, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun575(kk_function_t _fself, kk_box_t _b_x76, kk_box_t _b_x77, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x576;
  kk_std_core_types__maybe _match_x335 = kk_std_core_types__maybe_unbox(_b_x76, KK_OWNED, _ctx); /*maybe<int>*/;
  if (kk_std_core_types__is_Nothing(_match_x335, _ctx)) {
    _x_x576 = kk_integer_unbox(_b_x77, _ctx); /*int*/
  }
  else {
    kk_box_t _box_x72 = _match_x335._cons.Just.value;
    kk_integer_t x = kk_integer_unbox(_box_x72, _ctx);
    kk_integer_dup(x, _ctx);
    kk_std_core_types__maybe_drop(_match_x335, _ctx);
    kk_box_drop(_b_x77, _ctx);
    _x_x576 = x; /*int*/
  }
  return kk_integer_box(_x_x576, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10263_fun578__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun578(kk_function_t _fself, kk_box_t _b_x88, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10263_fun578(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10263_fun578, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun578(kk_function_t _fself, kk_box_t _b_x88, kk_box_t _b_x89, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x579;
  kk_integer_t _x_x580 = kk_integer_unbox(_b_x88, _ctx); /*int*/
  kk_std_core_types__optional _x_x581 = kk_std_core_types__optional_unbox(_b_x89, KK_OWNED, _ctx); /*? int*/
  _x_x579 = kk_std_num_decimal_decimal_exp(_x_x580, _x_x581, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x579, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10263_fun585__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun585(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10263_fun585(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10263_fun585, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10263_fun585(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal x_1_98 = kk_std_num_decimal__decimal_unbox(_b_x95, KK_OWNED, _ctx); /*std/num/decimal/decimal*/;
  kk_std_num_decimal__decimal _x_x586;
  kk_integer_t _x_x587;
  kk_integer_t _x_x588;
  {
    kk_integer_t _x = x_1_98.num;
    kk_integer_dup(_x, _ctx);
    _x_x588 = _x; /*int*/
  }
  _x_x587 = kk_integer_neg(_x_x588,kk_context()); /*int*/
  kk_integer_t _x_x589;
  {
    kk_integer_t _x_0 = x_1_98.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(x_1_98, _ctx);
    _x_x589 = _x_0; /*int*/
  }
  _x_x586 = kk_std_num_decimal__new_Decimal(_x_x587, _x_x589, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x586, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10263(kk_string_t frac, bool neg, kk_string_t whole, kk_integer_t exp, kk_context_t* _ctx) { /* (frac : string, neg : bool, whole : string, exp : int) -> std/text/parse/parse decimal */ 
  kk_string_t _x_x1_1_10259;
  kk_string_t _x_x568 = kk_string_dup(frac, _ctx); /*string*/
  _x_x1_1_10259 = kk_std_core_types__lp__plus__plus__rp_(whole, _x_x568, _ctx); /*string*/
  kk_std_core_types__maybe _x_x1_0_10257;
  kk_box_t _x_x569 = kk_std_core_hnd__open_none2(kk_std_num_decimal__new_mlift_pdecimal_10263_fun570(_ctx), kk_string_box(_x_x1_1_10259), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
  _x_x1_0_10257 = kk_std_core_types__maybe_unbox(_x_x569, KK_OWNED, _ctx); /*maybe<int>*/
  kk_integer_t _x_x1_10255;
  kk_box_t _x_x574 = kk_std_core_hnd__open_none2(kk_std_num_decimal__new_mlift_pdecimal_10263_fun575(_ctx), kk_std_core_types__maybe_box(_x_x1_0_10257, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*9985*/
  _x_x1_10255 = kk_integer_unbox(_x_x574, _ctx); /*int*/
  kk_integer_t y_10253 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/;
  kk_integer_t _b_x83_84 = kk_integer_sub(exp,y_10253,kk_context()); /*int*/;
  kk_std_num_decimal__decimal i;
  kk_box_t _x_x577;
  kk_box_t _x_x582;
  kk_std_core_types__optional _x_x583 = kk_std_core_types__new_Optional(kk_integer_box(_b_x83_84, _ctx), _ctx); /*? 7*/
  _x_x582 = kk_std_core_types__optional_box(_x_x583, _ctx); /*9984*/
  _x_x577 = kk_std_core_hnd__open_none2(kk_std_num_decimal__new_mlift_pdecimal_10263_fun578(_ctx), kk_integer_box(_x_x1_10255, _ctx), _x_x582, _ctx); /*9985*/
  i = kk_std_num_decimal__decimal_unbox(_x_x577, KK_OWNED, _ctx); /*std/num/decimal/decimal*/
  if (neg) {
    kk_box_t _x_x584 = kk_std_core_hnd__open_none1(kk_std_num_decimal__new_mlift_pdecimal_10263_fun585(_ctx), kk_std_num_decimal__decimal_box(i, _ctx), _ctx); /*9904*/
    return kk_std_num_decimal__decimal_unbox(_x_x584, KK_OWNED, _ctx);
  }
  {
    return i;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10265_fun591__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun591(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10265_fun591(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10265_fun591, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10265_fun596__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun596(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10265_fun596(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10265_fun596, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun596(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x597;
  kk_char_t _x_x598 = kk_char_unbox(_b_x100, KK_OWNED, _ctx); /*char*/
  _x_x597 = kk_std_num_decimal__mlift_pdecimal_10262(_x_x598, _ctx); /*int*/
  return kk_integer_box(_x_x597, _ctx);
}
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun591(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_0_10272;
  kk_string_t _x_x592;
  kk_define_string_literal(, _s_x593, 2, "eE", _ctx)
  _x_x592 = kk_string_dup(_s_x593, _ctx); /*string*/
  x_0_10272 = kk_std_text_parse_one_of(_x_x592, _ctx); /*char*/
  kk_integer_t _x_x594;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x595 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10265_fun596(_ctx), _ctx); /*2419*/
    _x_x594 = kk_integer_unbox(_x_x595, _ctx); /*int*/
  }
  else {
    _x_x594 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x_x594, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10265_fun599__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun599(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10265_fun599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10265_fun599, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun599(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(0), _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10265_fun601__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun601(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10265_fun601(kk_string_t frac, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10265_fun601__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10265_fun601__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10265_fun601, kk_context());
  _self->frac = frac;
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10265_fun601(kk_function_t _fself, kk_box_t _b_x107, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10265_fun601__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10265_fun601__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_integer_t exp_109 = kk_integer_unbox(_b_x107, _ctx); /*int*/;
  kk_std_num_decimal__decimal _x_x602 = kk_std_num_decimal__mlift_pdecimal_10263(frac, neg, whole, exp_109, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x602, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10265(bool neg, kk_string_t whole, kk_string_t frac, kk_context_t* _ctx) { /* (neg : bool, whole : string, frac : string) -> std/text/parse/parse decimal */ 
  kk_integer_t x_10270;
  kk_box_t _x_x590 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_decimal__new_mlift_pdecimal_10265_fun591(_ctx), kk_std_num_decimal__new_mlift_pdecimal_10265_fun599(_ctx), _ctx); /*1542*/
  x_10270 = kk_integer_unbox(_x_x590, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10270, _ctx);
    kk_box_t _x_x600 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10265_fun601(frac, whole, neg, _ctx), _ctx); /*2419*/
    return kk_std_num_decimal__decimal_unbox(_x_x600, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10263(frac, neg, whole, x_10270, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10266_fun604__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun604(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10266_fun604(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10266_fun604, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10266_fun607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun607(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10266_fun607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10266_fun607, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun607(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x608;
  kk_char_t _x_x609 = kk_char_unbox(_b_x111, KK_OWNED, _ctx); /*char*/
  _x_x608 = kk_std_num_decimal__mlift_pdecimal_10264(_x_x609, _ctx); /*string*/
  return kk_string_box(_x_x608);
}
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun604(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_0_10276 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x_x605;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x606 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10266_fun607(_ctx), _ctx); /*2419*/
    _x_x605 = kk_string_unbox(_x_x606); /*string*/
  }
  else {
    _x_x605 = kk_std_text_parse_digits(_ctx); /*string*/
  }
  return kk_string_box(_x_x605);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10266_fun610__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun610(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10266_fun610(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10266_fun610, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun610(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x611 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x611);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10266_fun614__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun614(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10266_fun614(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10266_fun614__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10266_fun614__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10266_fun614, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10266_fun614(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10266_fun614__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10266_fun614__t*, _fself, _ctx);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t frac_120 = kk_string_unbox(_b_x118); /*string*/;
  kk_std_num_decimal__decimal _x_x615 = kk_std_num_decimal__mlift_pdecimal_10265(neg, whole, frac_120, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x615, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10266(bool neg, kk_string_t whole, kk_context_t* _ctx) { /* (neg : bool, whole : string) -> std/text/parse/parse decimal */ 
  kk_string_t x_10274;
  kk_box_t _x_x603 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_decimal__new_mlift_pdecimal_10266_fun604(_ctx), kk_std_num_decimal__new_mlift_pdecimal_10266_fun610(_ctx), _ctx); /*1542*/
  x_10274 = kk_string_unbox(_x_x603); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10274, _ctx);
    kk_box_t _x_x613 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10266_fun614(whole, neg, _ctx), _ctx); /*2419*/
    return kk_std_num_decimal__decimal_unbox(_x_x613, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10265(neg, whole, x_10274, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10267_fun617__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10267_fun617(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10267_fun617(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10267_fun617__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10267_fun617__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10267_fun617, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10267_fun617(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10267_fun617__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10267_fun617__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t whole_124 = kk_string_unbox(_b_x122); /*string*/;
  kk_std_num_decimal__decimal _x_x618 = kk_std_num_decimal__mlift_pdecimal_10266(neg, whole_124, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x618, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10267(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse decimal */ 
  kk_string_t x_10278 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10278, _ctx);
    kk_box_t _x_x616 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10267_fun617(neg, _ctx), _ctx); /*2419*/
    return kk_std_num_decimal__decimal_unbox(_x_x616, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10266(neg, x_10278, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun620__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun620(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun620(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun620, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun620(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x621;
  bool _x_x622 = kk_bool_unbox(_b_x126); /*bool*/
  _x_x621 = kk_std_num_decimal__mlift_pdecimal_10267(_x_x622, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x621, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun624__t {
  struct kk_function_s _base;
  bool x_10280;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun624(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun624(bool x_10280, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun624__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun624__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun624, kk_context());
  _self->x_10280 = x_10280;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun624(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun624__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun624__t*, _fself, _ctx);
  bool x_10280 = _self->x_10280; /* bool */
  kk_drop_match(_self, {kk_skip_dup(x_10280, _ctx);}, {}, _ctx)
  kk_string_t whole_188 = kk_string_unbox(_b_x128); /*string*/;
  kk_std_num_decimal__decimal _x_x625 = kk_std_num_decimal__mlift_pdecimal_10266(x_10280, whole_188, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x625, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun627__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun627(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun627(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun627, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun630__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun630(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun630(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun630, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun630(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x631;
  kk_char_t _x_x632 = kk_char_unbox(_b_x130, KK_OWNED, _ctx); /*char*/
  _x_x631 = kk_std_num_decimal__mlift_pdecimal_10264(_x_x632, _ctx); /*string*/
  return kk_string_box(_x_x631);
}
static kk_box_t kk_std_num_decimal_pdecimal_fun627(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_2_10289 = kk_std_text_parse_char('.', _ctx); /*char*/;
  kk_string_t _x_x628;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x629 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun630(_ctx), _ctx); /*2419*/
    _x_x628 = kk_string_unbox(_x_x629); /*string*/
  }
  else {
    _x_x628 = kk_std_text_parse_digits(_ctx); /*string*/
  }
  return kk_string_box(_x_x628);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun633__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun633(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun633(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun633, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun633(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x634 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x634);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun637__t {
  struct kk_function_s _base;
  kk_string_t x_0_10283;
  bool x_10280;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun637(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun637(kk_string_t x_0_10283, bool x_10280, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun637__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun637__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun637, kk_context());
  _self->x_0_10283 = x_0_10283;
  _self->x_10280 = x_10280;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun637(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun637__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun637__t*, _fself, _ctx);
  kk_string_t x_0_10283 = _self->x_0_10283; /* string */
  bool x_10280 = _self->x_10280; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10283, _ctx);kk_skip_dup(x_10280, _ctx);}, {}, _ctx)
  kk_string_t frac_189 = kk_string_unbox(_b_x137); /*string*/;
  kk_std_num_decimal__decimal _x_x638 = kk_std_num_decimal__mlift_pdecimal_10265(x_10280, x_0_10283, frac_189, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x638, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun640__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun640(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun640(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun640, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun645__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun645(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun645(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun645, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun645(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x646;
  kk_char_t _x_x647 = kk_char_unbox(_b_x139, KK_OWNED, _ctx); /*char*/
  _x_x646 = kk_std_num_decimal__mlift_pdecimal_10262(_x_x647, _ctx); /*int*/
  return kk_integer_box(_x_x646, _ctx);
}
static kk_box_t kk_std_num_decimal_pdecimal_fun640(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_4_10294;
  kk_string_t _x_x641;
  kk_define_string_literal(, _s_x642, 2, "eE", _ctx)
  _x_x641 = kk_string_dup(_s_x642, _ctx); /*string*/
  x_4_10294 = kk_std_text_parse_one_of(_x_x641, _ctx); /*char*/
  kk_integer_t _x_x643;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x644 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun645(_ctx), _ctx); /*2419*/
    _x_x643 = kk_integer_unbox(_x_x644, _ctx); /*int*/
  }
  else {
    _x_x643 = kk_std_text_parse_pint(_ctx); /*int*/
  }
  return kk_integer_box(_x_x643, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun648__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun648(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun648(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun648, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun648(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_integer_box(kk_integer_from_small(0), _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun650__t {
  struct kk_function_s _base;
  kk_string_t x_0_10283;
  kk_string_t x_1_10286;
  bool x_10280;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun650(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun650(kk_string_t x_0_10283, kk_string_t x_1_10286, bool x_10280, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun650__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun650__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun650, kk_context());
  _self->x_0_10283 = x_0_10283;
  _self->x_1_10286 = x_1_10286;
  _self->x_10280 = x_10280;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun650(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun650__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun650__t*, _fself, _ctx);
  kk_string_t x_0_10283 = _self->x_0_10283; /* string */
  kk_string_t x_1_10286 = _self->x_1_10286; /* string */
  bool x_10280 = _self->x_10280; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10283, _ctx);kk_string_dup(x_1_10286, _ctx);kk_skip_dup(x_10280, _ctx);}, {}, _ctx)
  kk_integer_t exp_190 = kk_integer_unbox(_b_x146, _ctx); /*int*/;
  kk_std_num_decimal__decimal _x_x651 = kk_std_num_decimal__mlift_pdecimal_10263(x_1_10286, x_10280, x_0_10283, exp_190, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x651, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun654__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun654(kk_function_t _fself, kk_box_t _b_x151, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun654(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun654, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun654(kk_function_t _fself, kk_box_t _b_x151, kk_box_t _b_x152, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x655;
  kk_string_t _x_x656 = kk_string_unbox(_b_x151); /*string*/
  bool _x_x657;
  kk_std_core_types__optional _match_x327 = kk_std_core_types__optional_unbox(_b_x152, KK_OWNED, _ctx); /*? bool*/;
  if (kk_std_core_types__is_Optional(_match_x327, _ctx)) {
    kk_box_t _box_x147 = _match_x327._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x147);
    kk_std_core_types__optional_drop(_match_x327, _ctx);
    _x_x657 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x327, _ctx);
    _x_x657 = false; /*bool*/
  }
  _x_x655 = kk_std_core_int_xparse(_x_x656, _x_x657, _ctx); /*maybe<int>*/
  return kk_std_core_types__maybe_box(_x_x655, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun659__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun659(kk_function_t _fself, kk_box_t _b_x162, kk_box_t _b_x163, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun659(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun659, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun659(kk_function_t _fself, kk_box_t _b_x162, kk_box_t _b_x163, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x660;
  kk_std_core_types__maybe _match_x326 = kk_std_core_types__maybe_unbox(_b_x162, KK_OWNED, _ctx); /*maybe<int>*/;
  if (kk_std_core_types__is_Nothing(_match_x326, _ctx)) {
    _x_x660 = kk_integer_unbox(_b_x163, _ctx); /*int*/
  }
  else {
    kk_box_t _box_x158 = _match_x326._cons.Just.value;
    kk_integer_t x_5 = kk_integer_unbox(_box_x158, _ctx);
    kk_integer_dup(x_5, _ctx);
    kk_std_core_types__maybe_drop(_match_x326, _ctx);
    kk_box_drop(_b_x163, _ctx);
    _x_x660 = x_5; /*int*/
  }
  return kk_integer_box(_x_x660, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun662__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun662(kk_function_t _fself, kk_box_t _b_x174, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun662(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun662, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun662(kk_function_t _fself, kk_box_t _b_x174, kk_box_t _b_x175, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x663;
  kk_integer_t _x_x664 = kk_integer_unbox(_b_x174, _ctx); /*int*/
  kk_std_core_types__optional _x_x665 = kk_std_core_types__optional_unbox(_b_x175, KK_OWNED, _ctx); /*? int*/
  _x_x663 = kk_std_num_decimal_decimal_exp(_x_x664, _x_x665, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x663, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun669__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun669(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun669(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun669, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun669(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal x_1_0_191 = kk_std_num_decimal__decimal_unbox(_b_x181, KK_OWNED, _ctx); /*std/num/decimal/decimal*/;
  kk_std_num_decimal__decimal _x_x670;
  kk_integer_t _x_x671;
  kk_integer_t _x_x672;
  {
    kk_integer_t _x = x_1_0_191.num;
    kk_integer_dup(_x, _ctx);
    _x_x672 = _x; /*int*/
  }
  _x_x671 = kk_integer_neg(_x_x672,kk_context()); /*int*/
  kk_integer_t _x_x673;
  {
    kk_integer_t _x_0 = x_1_0_191.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(x_1_0_191, _ctx);
    _x_x673 = _x_0; /*int*/
  }
  _x_x670 = kk_std_num_decimal__new_Decimal(_x_x671, _x_x673, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x670, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_pdecimal(kk_context_t* _ctx) { /* () -> std/text/parse/parse decimal */ 
  bool x_10280 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x619 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun620(_ctx), _ctx); /*2419*/
    return kk_std_num_decimal__decimal_unbox(_x_x619, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_10283 = kk_std_text_parse_digits(_ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10283, _ctx);
      kk_box_t _x_x623 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun624(x_10280, _ctx), _ctx); /*2419*/
      return kk_std_num_decimal__decimal_unbox(_x_x623, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_10286;
      kk_box_t _x_x626 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_decimal_new_pdecimal_fun627(_ctx), kk_std_num_decimal_new_pdecimal_fun633(_ctx), _ctx); /*1542*/
      x_1_10286 = kk_string_unbox(_x_x626); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10286, _ctx);
        kk_box_t _x_x636 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun637(x_0_10283, x_10280, _ctx), _ctx); /*2419*/
        return kk_std_num_decimal__decimal_unbox(_x_x636, KK_OWNED, _ctx);
      }
      {
        kk_integer_t x_3_10291;
        kk_box_t _x_x639 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_num_decimal_new_pdecimal_fun640(_ctx), kk_std_num_decimal_new_pdecimal_fun648(_ctx), _ctx); /*1542*/
        x_3_10291 = kk_integer_unbox(_x_x639, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_3_10291, _ctx);
          kk_box_t _x_x649 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun650(x_0_10283, x_1_10286, x_10280, _ctx), _ctx); /*2419*/
          return kk_std_num_decimal__decimal_unbox(_x_x649, KK_OWNED, _ctx);
        }
        {
          kk_string_t _x_x1_1_10259;
          kk_string_t _x_x652 = kk_string_dup(x_1_10286, _ctx); /*string*/
          _x_x1_1_10259 = kk_std_core_types__lp__plus__plus__rp_(x_0_10283, _x_x652, _ctx); /*string*/
          kk_std_core_types__maybe _x_x1_0_10257;
          kk_box_t _x_x653 = kk_std_core_hnd__open_none2(kk_std_num_decimal_new_pdecimal_fun654(_ctx), kk_string_box(_x_x1_1_10259), kk_std_core_types__optional_box(kk_std_core_types__new_None(_ctx), _ctx), _ctx); /*9985*/
          _x_x1_0_10257 = kk_std_core_types__maybe_unbox(_x_x653, KK_OWNED, _ctx); /*maybe<int>*/
          kk_integer_t _x_x1_10255;
          kk_box_t _x_x658 = kk_std_core_hnd__open_none2(kk_std_num_decimal_new_pdecimal_fun659(_ctx), kk_std_core_types__maybe_box(_x_x1_0_10257, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*9985*/
          _x_x1_10255 = kk_integer_unbox(_x_x658, _ctx); /*int*/
          kk_integer_t y_10253 = kk_std_core_string_chars_fs_count(x_1_10286, _ctx); /*int*/;
          kk_integer_t _b_x169_170 = kk_integer_sub(x_3_10291,y_10253,kk_context()); /*int*/;
          kk_std_num_decimal__decimal i;
          kk_box_t _x_x661;
          kk_box_t _x_x666;
          kk_std_core_types__optional _x_x667 = kk_std_core_types__new_Optional(kk_integer_box(_b_x169_170, _ctx), _ctx); /*? 7*/
          _x_x666 = kk_std_core_types__optional_box(_x_x667, _ctx); /*9984*/
          _x_x661 = kk_std_core_hnd__open_none2(kk_std_num_decimal_new_pdecimal_fun662(_ctx), kk_integer_box(_x_x1_10255, _ctx), _x_x666, _ctx); /*9985*/
          i = kk_std_num_decimal__decimal_unbox(_x_x661, KK_OWNED, _ctx); /*std/num/decimal/decimal*/
          if (x_10280) {
            kk_box_t _x_x668 = kk_std_core_hnd__open_none1(kk_std_num_decimal_new_pdecimal_fun669(_ctx), kk_std_num_decimal__decimal_box(i, _ctx), _ctx); /*9904*/
            return kk_std_num_decimal__decimal_unbox(_x_x668, KK_OWNED, _ctx);
          }
          {
            return i;
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_parse_decimal_10269_fun675__t {
  struct kk_function_s _base;
  kk_std_num_decimal__decimal x;
};
static kk_box_t kk_std_num_decimal__mlift_parse_decimal_10269_fun675(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_parse_decimal_10269_fun675(kk_std_num_decimal__decimal x, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_parse_decimal_10269_fun675__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_parse_decimal_10269_fun675__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_parse_decimal_10269_fun675, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_parse_decimal_10269_fun675(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_parse_decimal_10269_fun675__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_parse_decimal_10269_fun675__t*, _fself, _ctx);
  kk_std_num_decimal__decimal x = _self->x; /* std/num/decimal/decimal */
  kk_drop_match(_self, {kk_std_num_decimal__decimal_dup(x, _ctx);}, {}, _ctx)
  kk_unit_t wild___195 = kk_Unit;
  kk_unit_unbox(_b_x193);
  return kk_std_num_decimal__decimal_box(x, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_parse_decimal_10269(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> std/text/parse/parse decimal */ 
  kk_unit_t x_0_10296 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x674 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_parse_decimal_10269_fun675(x, _ctx), _ctx); /*2419*/
    return kk_std_num_decimal__decimal_unbox(_x_x674, KK_OWNED, _ctx);
  }
  {
    return x;
  }
}
 
// Parse a `:decimal` number.


// lift anonymous function
struct kk_std_num_decimal_parse_decimal_fun679__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_parse_decimal_fun679(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_parse_decimal_fun679(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_parse_decimal_fun679, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_decimal_parse_decimal_fun682__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_parse_decimal_fun682(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_parse_decimal_fun682(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_parse_decimal_fun682, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_parse_decimal_fun682(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x683;
  kk_std_num_decimal__decimal _x_x684 = kk_std_num_decimal__decimal_unbox(_b_x197, KK_OWNED, _ctx); /*std/num/decimal/decimal*/
  _x_x683 = kk_std_num_decimal__mlift_parse_decimal_10269(_x_x684, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x683, _ctx);
}
static kk_box_t kk_std_num_decimal_parse_decimal_fun679(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal x_10300 = kk_std_num_decimal_pdecimal(_ctx); /*std/num/decimal/decimal*/;
  kk_std_num_decimal__decimal _x_x680;
  if (kk_yielding(kk_context())) {
    kk_std_num_decimal__decimal_drop(x_10300, _ctx);
    kk_box_t _x_x681 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_parse_decimal_fun682(_ctx), _ctx); /*2419*/
    _x_x680 = kk_std_num_decimal__decimal_unbox(_x_x681, KK_OWNED, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    _x_x680 = kk_std_num_decimal__mlift_parse_decimal_10269(x_10300, _ctx); /*std/num/decimal/decimal*/
  }
  return kk_std_num_decimal__decimal_box(_x_x680, _ctx);
}

kk_std_core_types__maybe kk_std_num_decimal_parse_decimal(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<decimal> */ 
  kk_string_t s_0_10156;
  kk_string_t _x_x676 = kk_string_trim_left(s,kk_context()); /*string*/
  s_0_10156 = kk_string_trim_right(_x_x676,kk_context()); /*string*/
  kk_std_core_sslice__sslice input_10154;
  kk_string_t _x_x677 = kk_string_dup(s_0_10156, _ctx); /*string*/
  kk_integer_t _x_x678 = kk_string_len_int(s_0_10156,kk_context()); /*int*/
  input_10154 = kk_std_core_sslice__new_Sslice(_x_x677, kk_integer_from_small(0), _x_x678, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10153 = kk_std_text_parse_parse(input_10154, kk_std_num_decimal_new_parse_decimal_fun679(_ctx), _ctx); /*std/text/parse/parse-error<std/num/decimal/decimal>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10153, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x685 = kk_std_text_parse__as_ParseOk(perr_10153, _ctx);
    kk_box_t _box_x203 = _con_x685->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x685->rest;
    kk_std_num_decimal__decimal x_0 = kk_std_num_decimal__decimal_unbox(_box_x203, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10153, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_std_num_decimal__decimal_dup(x_0, _ctx);
      kk_box_drop(_box_x203, _ctx);
      kk_datatype_ptr_free(perr_10153, _ctx);
    }
    else {
      kk_std_num_decimal__decimal_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_10153, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_num_decimal__decimal_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x686 = kk_std_text_parse__as_ParseError(perr_10153, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x686->rest;
    kk_string_t msg = _con_x686->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10153, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10153, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10153, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Take the sum of a list of decimal numbers (0 for the empty list).


// lift anonymous function
struct kk_std_num_decimal_sum_fun690__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_sum_fun690(kk_function_t _fself, kk_box_t _b_x209, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_sum_fun690(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_sum_fun690, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_sum_fun690(kk_function_t _fself, kk_box_t _b_x209, kk_box_t _b_x210, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x691;
  kk_std_num_decimal__decimal _x_x692 = kk_std_num_decimal__decimal_unbox(_b_x209, KK_OWNED, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x_x693 = kk_std_num_decimal__decimal_unbox(_b_x210, KK_OWNED, _ctx); /*std/num/decimal/decimal*/
  _x_x691 = kk_std_num_decimal__lp__plus__rp_(_x_x692, _x_x693, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x691, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_sum(kk_std_core_types__list ds, kk_context_t* _ctx) { /* (ds : list<decimal>) -> decimal */ 
  kk_box_t _x_x687;
  kk_box_t _x_x688;
  kk_std_num_decimal__decimal _x_x689 = kk_std_num_decimal__decimal_dup(kk_std_num_decimal_zero, _ctx); /*std/num/decimal/decimal*/
  _x_x688 = kk_std_num_decimal__decimal_box(_x_x689, _ctx); /*1245*/
  _x_x687 = kk_std_core_list_foldr(ds, _x_x688, kk_std_num_decimal_new_sum_fun690(_ctx), _ctx); /*1245*/
  return kk_std_num_decimal__decimal_unbox(_x_x687, KK_OWNED, _ctx);
}
 
// Convert a decimal to a `:float64`. This may lose precision.

double kk_std_num_decimal_float64(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> float64 */ 
  bool b_10164;
  kk_integer_t _brw_x318;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x318 = _x; /*int*/
  }
  bool _brw_x319 = kk_integer_lt_borrow(_brw_x318,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x318, _ctx);
  b_10164 = _brw_x319; /*bool*/
  if (b_10164) {
    kk_std_core_types__tuple2 _match_x317;
    kk_integer_t _x_x700;
    {
      kk_integer_t _x_2 = x.num;
      kk_integer_dup(_x_2, _ctx);
      _x_x700 = _x_2; /*int*/
    }
    kk_integer_t _x_x701;
    kk_integer_t _x_x702;
    {
      kk_integer_t _x_3 = x.exp;
      kk_integer_dup(_x_3, _ctx);
      _x_x702 = _x_3; /*int*/
    }
    _x_x701 = kk_integer_neg(_x_x702,kk_context()); /*int*/
    _match_x317 = kk_std_core_int_divmod_exp10(_x_x700, _x_x701, _ctx); /*(int, int)*/
    {
      kk_box_t _box_x226 = _match_x317.fst;
      kk_box_t _box_x227 = _match_x317.snd;
      kk_integer_t q = kk_integer_unbox(_box_x226, _ctx);
      kk_integer_t r = kk_integer_unbox(_box_x227, _ctx);
      kk_integer_dup(q, _ctx);
      kk_integer_dup(r, _ctx);
      kk_std_core_types__tuple2_drop(_match_x317, _ctx);
      double _x_x703 = kk_integer_as_double(q,kk_context()); /*float64*/
      double _x_x704;
      double _x_x705 = kk_integer_as_double(r,kk_context()); /*float64*/
      double _x_x706;
      double _x_x707;
      kk_integer_t _x_x708;
      {
        kk_integer_t _x_4 = x.exp;
        kk_integer_dup(_x_4, _ctx);
        kk_std_num_decimal__decimal_drop(x, _ctx);
        _x_x708 = _x_4; /*int*/
      }
      _x_x707 = kk_integer_as_double(_x_x708,kk_context()); /*float64*/
      _x_x706 = pow(10.0,_x_x707); /*float64*/
      _x_x704 = (_x_x705 * _x_x706); /*float64*/
      return (_x_x703 + _x_x704);
    }
  }
  {
    double _x_x709;
    kk_integer_t _x_x710;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x710 = _x_0; /*int*/
    }
    _x_x709 = kk_integer_as_double(_x_x710,kk_context()); /*float64*/
    double _x_x711;
    double _x_x712;
    kk_integer_t _x_x713;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x713 = _x_1; /*int*/
    }
    _x_x712 = kk_integer_as_double(_x_x713,kk_context()); /*float64*/
    _x_x711 = pow((0x1.4p3),_x_x712); /*float64*/
    return (_x_x709 * _x_x711);
  }
}
 
// Return the 'truncated' fraction, always in the range (`-1.0`,`1.0`).
// `x.truncate + x.fraction == x`

kk_std_num_decimal__decimal kk_std_num_decimal_fraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool b_10172;
  kk_integer_t _brw_x315;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x315 = _x; /*int*/
  }
  bool _brw_x316 = kk_integer_lt_borrow(_brw_x315,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x315, _ctx);
  b_10172 = _brw_x316; /*bool*/
  if (b_10172) {
    kk_std_num_decimal__decimal y_10176;
    kk_std_num_decimal__decimal _x_x714 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x715 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x716 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Truncate(_ctx), _ctx), _ctx); /*? 7*/
    y_10176 = kk_std_num_decimal_round_to_prec(_x_x714, _x_x715, _x_x716, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_10228;
    kk_integer_t _x_x717;
    kk_integer_t _x_x718;
    {
      kk_integer_t _x_0_1 = y_10176.num;
      kk_integer_dup(_x_0_1, _ctx);
      _x_x718 = _x_0_1; /*int*/
    }
    _x_x717 = kk_integer_neg(_x_x718,kk_context()); /*int*/
    kk_integer_t _x_x719;
    {
      kk_integer_t _x_1_0 = y_10176.exp;
      kk_integer_dup(_x_1_0, _ctx);
      kk_std_num_decimal__decimal_drop(y_10176, _ctx);
      _x_x719 = _x_1_0; /*int*/
    }
    y_10228 = kk_std_num_decimal__new_Decimal(_x_x717, _x_x719, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_x311;
    kk_integer_t _brw_x313;
    {
      kk_integer_t _x_0 = x.exp;
      kk_integer_dup(_x_0, _ctx);
      _brw_x313 = _x_0; /*int*/
    }
    kk_integer_t _brw_x312;
    {
      kk_integer_t _x_0_0 = y_10228.exp;
      kk_integer_dup(_x_0_0, _ctx);
      _brw_x312 = _x_0_0; /*int*/
    }
    bool _brw_x314 = kk_integer_lte_borrow(_brw_x313,_brw_x312,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x313, _ctx);
    kk_integer_drop(_brw_x312, _ctx);
    _match_x311 = _brw_x314; /*bool*/
    if (_match_x311) {
      kk_integer_t _x_0_2 = x.exp;
      kk_integer_dup(_x_0_2, _ctx);
      e = _x_0_2; /*int*/
    }
    else {
      kk_integer_t _x_0_0_0 = y_10228.exp;
      kk_integer_dup(_x_0_0_0, _ctx);
      e = _x_0_0_0; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x_x720 = kk_integer_dup(e, _ctx); /*int*/
    xx = kk_std_num_decimal_expand(x, _x_x720, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x_x721 = kk_integer_dup(e, _ctx); /*int*/
    yy = kk_std_num_decimal_expand(y_10228, _x_x721, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x_x722;
    kk_integer_t _x_x723;
    {
      kk_integer_t _x_1 = xx.num;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _x_x723 = _x_1; /*int*/
    }
    kk_integer_t _x_x724;
    {
      kk_integer_t _x_2 = yy.num;
      kk_integer_dup(_x_2, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _x_x724 = _x_2; /*int*/
    }
    _x_x722 = kk_integer_add(_x_x723,_x_x724,kk_context()); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x722, e, _ctx);
  }
  {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_num_decimal__decimal_dup(kk_std_num_decimal_zero, _ctx);
  }
}
 
// Return the 'floored' fraction, always in the range [`0`,`1.0`).
// `x.floor + x.ffraction == x`

kk_std_num_decimal__decimal kk_std_num_decimal_ffraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool b_10180;
  kk_integer_t _brw_x309;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x309 = _x; /*int*/
  }
  bool _brw_x310 = kk_integer_lt_borrow(_brw_x309,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x309, _ctx);
  b_10180 = _brw_x310; /*bool*/
  if (b_10180) {
    kk_std_num_decimal__decimal y_10184;
    kk_std_num_decimal__decimal _x_x725 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x726 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 7*/
    kk_std_core_types__optional _x_x727 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Floor(_ctx), _ctx), _ctx); /*? 7*/
    y_10184 = kk_std_num_decimal_round_to_prec(_x_x725, _x_x726, _x_x727, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_10231;
    kk_integer_t _x_x728;
    kk_integer_t _x_x729;
    {
      kk_integer_t _x_0_1 = y_10184.num;
      kk_integer_dup(_x_0_1, _ctx);
      _x_x729 = _x_0_1; /*int*/
    }
    _x_x728 = kk_integer_neg(_x_x729,kk_context()); /*int*/
    kk_integer_t _x_x730;
    {
      kk_integer_t _x_1_0 = y_10184.exp;
      kk_integer_dup(_x_1_0, _ctx);
      kk_std_num_decimal__decimal_drop(y_10184, _ctx);
      _x_x730 = _x_1_0; /*int*/
    }
    y_10231 = kk_std_num_decimal__new_Decimal(_x_x728, _x_x730, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_x305;
    kk_integer_t _brw_x307;
    {
      kk_integer_t _x_0 = x.exp;
      kk_integer_dup(_x_0, _ctx);
      _brw_x307 = _x_0; /*int*/
    }
    kk_integer_t _brw_x306;
    {
      kk_integer_t _x_0_0 = y_10231.exp;
      kk_integer_dup(_x_0_0, _ctx);
      _brw_x306 = _x_0_0; /*int*/
    }
    bool _brw_x308 = kk_integer_lte_borrow(_brw_x307,_brw_x306,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x307, _ctx);
    kk_integer_drop(_brw_x306, _ctx);
    _match_x305 = _brw_x308; /*bool*/
    if (_match_x305) {
      kk_integer_t _x_0_2 = x.exp;
      kk_integer_dup(_x_0_2, _ctx);
      e = _x_0_2; /*int*/
    }
    else {
      kk_integer_t _x_0_0_0 = y_10231.exp;
      kk_integer_dup(_x_0_0_0, _ctx);
      e = _x_0_0_0; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x_x731 = kk_integer_dup(e, _ctx); /*int*/
    xx = kk_std_num_decimal_expand(x, _x_x731, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x_x732 = kk_integer_dup(e, _ctx); /*int*/
    yy = kk_std_num_decimal_expand(y_10231, _x_x732, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x_x733;
    kk_integer_t _x_x734;
    {
      kk_integer_t _x_1 = xx.num;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _x_x734 = _x_1; /*int*/
    }
    kk_integer_t _x_x735;
    {
      kk_integer_t _x_2 = yy.num;
      kk_integer_dup(_x_2, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _x_x735 = _x_2; /*int*/
    }
    _x_x733 = kk_integer_add(_x_x734,_x_x735,kk_context()); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x733, e, _ctx);
  }
  {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_num_decimal__decimal_dup(kk_std_num_decimal_zero, _ctx);
  }
}
 
// The exponent of a decimal if displayed in scientific notation.
// `11.2e-1.decimal.exponent == 0`

kk_integer_t kk_std_num_decimal_exponent(kk_std_num_decimal__decimal d, kk_context_t* _ctx) { /* (d : decimal) -> int */ 
  kk_integer_t x_0_10190;
  kk_integer_t _x_x736;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x736 = _x; /*int*/
  }
  x_0_10190 = kk_std_core_int_count_digits(_x_x736, _ctx); /*int*/
  kk_integer_t x_10188;
  kk_integer_t _x_x737;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(d, _ctx);
    _x_x737 = _x_0; /*int*/
  }
  x_10188 = kk_integer_add(x_0_10190,_x_x737,kk_context()); /*int*/
  return kk_integer_add_small_const(x_10188, -1, _ctx);
}

kk_string_t kk_std_num_decimal_show_frac(kk_string_t frac, kk_integer_t prec, kk_context_t* _ctx) { /* (frac : string, prec : int) -> string */ 
  kk_string_t frac_trim;
  kk_string_t _x_x738;
  kk_define_string_literal(, _s_x739, 1, "0", _ctx)
  _x_x738 = kk_string_dup(_s_x739, _ctx); /*string*/
  frac_trim = kk_std_core_sslice_trim_right(frac, _x_x738, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_x303 = kk_integer_gte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x303) {
    kk_string_t _brw_x304;
    kk_std_core_types__optional _x_x740 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _brw_x304 = kk_std_core_string_pad_right(frac_trim, prec, _x_x740, _ctx); /*string*/
    kk_integer_drop(prec, _ctx);
    frac_full = _brw_x304; /*string*/
  }
  else {
    kk_integer_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  bool _match_x302;
  kk_string_t _x_x741 = kk_string_dup(frac_full, _ctx); /*string*/
  kk_string_t _x_x742 = kk_string_empty(); /*string*/
  _match_x302 = kk_string_is_eq(_x_x741,_x_x742,kk_context()); /*bool*/
  if (_match_x302) {
    kk_string_drop(frac_full, _ctx);
    return kk_string_empty();
  }
  {
    kk_string_t _x_x745;
    kk_define_string_literal(, _s_x746, 1, ".", _ctx)
    _x_x745 = kk_string_dup(_s_x746, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x745, frac_full, _ctx);
  }
}
 
// /* Show a decimal `d` with a given precision `prec` (=`-1000`) in scientific notation.
// The precision specifies the  number of digits after the dot, i.e.
// the number of significant digits is `prec+1`.
// If the precision is negative, _at most_ `prec` digits are displayed, and if
// it is positive exactly `prec` digits are used.
// ```
// > decimal(1,-1).show-exp
// "1e-1"
// > 1.1.decimal.show-exp
// "1.100000000000000088817841970012523233890533447265625"
// > 1.1.decimal.show-exp(-20)
// "1.10000000000000008882"
// > 0.125.decimal.show-exp(-20)
// "1.25e-1"
// > 0.125.decimal.show-exp(20)
// "1.25000000000000000000e-1"
// ```
// .
// */

kk_string_t kk_std_num_decimal_show_exp(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : ? int) -> string */ 
  kk_integer_t x_10195;
  kk_integer_t _x_x747;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x238 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3575 = kk_integer_unbox(_box_x238, _ctx);
    kk_integer_dup(_uniq_prec_3575, _ctx);
    _x_x747 = _uniq_prec_3575; /*int*/
  }
  else {
    _x_x747 = kk_integer_from_small(-1000); /*int*/
  }
  x_10195 = kk_integer_abs(_x_x747,kk_context()); /*int*/
  kk_integer_t x_0_10190;
  kk_integer_t _x_x748;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x748 = _x; /*int*/
  }
  x_0_10190 = kk_std_core_int_count_digits(_x_x748, _ctx); /*int*/
  kk_integer_t x_10188;
  kk_integer_t _x_x749;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    _x_x749 = _x_0; /*int*/
  }
  x_10188 = kk_integer_add(x_0_10190,_x_x749,kk_context()); /*int*/
  kk_integer_t y_10196 = kk_integer_add_small_const(x_10188, -1, _ctx); /*int*/;
  kk_integer_t _b_x239_240 = kk_integer_sub(x_10195,y_10196,kk_context()); /*int*/;
  kk_std_num_decimal__decimal x_0;
  kk_std_core_types__optional _x_x750 = kk_std_core_types__new_Optional(kk_integer_box(_b_x239_240, _ctx), _ctx); /*? 7*/
  x_0 = kk_std_num_decimal_round_to_prec(d, _x_x750, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  kk_string_t s;
  kk_integer_t _x_x751;
  kk_integer_t _x_x752;
  {
    kk_integer_t _x_1 = x_0.num;
    kk_integer_dup(_x_1, _ctx);
    _x_x752 = _x_1; /*int*/
  }
  _x_x751 = kk_integer_abs(_x_x752,kk_context()); /*int*/
  s = kk_std_core_int_show(_x_x751, _ctx); /*string*/
  kk_integer_t digits;
  kk_string_t _x_x753 = kk_string_dup(s, _ctx); /*string*/
  digits = kk_std_core_string_chars_fs_count(_x_x753, _ctx); /*int*/
  kk_integer_t x_1_10198;
  kk_integer_t _x_x754;
  {
    kk_integer_t _x_0_0 = x_0.exp;
    kk_integer_dup(_x_0_0, _ctx);
    _x_x754 = _x_0_0; /*int*/
  }
  x_1_10198 = kk_integer_add(_x_x754,digits,kk_context()); /*int*/
  kk_integer_t exp = kk_integer_add_small_const(x_1_10198, -1, _ctx); /*int*/;
  kk_string_t sign_0;
  bool _match_x299;
  kk_integer_t _brw_x300;
  {
    kk_integer_t _x_1_0 = x_0.num;
    kk_integer_dup(_x_1_0, _ctx);
    kk_std_num_decimal__decimal_drop(x_0, _ctx);
    _brw_x300 = _x_1_0; /*int*/
  }
  bool _brw_x301 = kk_integer_lt_borrow(_brw_x300,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x300, _ctx);
  _match_x299 = _brw_x301; /*bool*/
  if (_match_x299) {
    kk_define_string_literal(, _s_x755, 1, "-", _ctx)
    sign_0 = kk_string_dup(_s_x755, _ctx); /*string*/
  }
  else {
    sign_0 = kk_string_empty(); /*string*/
  }
  kk_string_t exponent_0;
  bool _match_x297 = kk_integer_eq_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x297) {
    kk_integer_drop(exp, _ctx);
    exponent_0 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x758;
    kk_define_string_literal(, _s_x759, 1, "e", _ctx)
    _x_x758 = kk_string_dup(_s_x759, _ctx); /*string*/
    kk_string_t _x_x760;
    kk_string_t _x_x761;
    bool _match_x298 = kk_integer_gt_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x298) {
      kk_define_string_literal(, _s_x762, 1, "+", _ctx)
      _x_x761 = kk_string_dup(_s_x762, _ctx); /*string*/
    }
    else {
      _x_x761 = kk_string_empty(); /*string*/
    }
    kk_string_t _x_x764 = kk_std_core_int_show(exp, _ctx); /*string*/
    _x_x760 = kk_std_core_types__lp__plus__plus__rp_(_x_x761, _x_x764, _ctx); /*string*/
    exponent_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x758, _x_x760, _ctx); /*string*/
  }
  kk_string_t frac_10233;
  kk_string_t _x_x765 = kk_string_dup(s, _ctx); /*string*/
  frac_10233 = kk_std_core_sslice_tail(_x_x765, _ctx); /*string*/
  kk_string_t frac_trim;
  kk_string_t _x_x766;
  kk_define_string_literal(, _s_x767, 1, "0", _ctx)
  _x_x766 = kk_string_dup(_s_x767, _ctx); /*string*/
  frac_trim = kk_std_core_sslice_trim_right(frac_10233, _x_x766, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_x292;
  kk_integer_t _brw_x295;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x241 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3575_0 = kk_integer_unbox(_box_x241, _ctx);
    kk_integer_dup(_uniq_prec_3575_0, _ctx);
    _brw_x295 = _uniq_prec_3575_0; /*int*/
  }
  else {
    _brw_x295 = kk_integer_from_small(-1000); /*int*/
  }
  bool _brw_x296 = kk_integer_gte_borrow(_brw_x295,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x295, _ctx);
  _match_x292 = _brw_x296; /*bool*/
  if (_match_x292) {
    kk_integer_t _brw_x293;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x242 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3575_1 = kk_integer_unbox(_box_x242, _ctx);
      kk_integer_dup(_uniq_prec_3575_1, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _brw_x293 = _uniq_prec_3575_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _brw_x293 = kk_integer_from_small(-1000); /*int*/
    }
    kk_string_t _brw_x294;
    kk_std_core_types__optional _x_x768 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _brw_x294 = kk_std_core_string_pad_right(frac_trim, _brw_x293, _x_x768, _ctx); /*string*/
    kk_integer_drop(_brw_x293, _ctx);
    frac_full = _brw_x294; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  kk_string_t _x_x769;
  kk_string_t _x_x770 = kk_std_core_sslice_head(s, _ctx); /*string*/
  kk_string_t _x_x771;
  kk_string_t _x_x772;
  bool _match_x291;
  kk_string_t _x_x773 = kk_string_dup(frac_full, _ctx); /*string*/
  kk_string_t _x_x774 = kk_string_empty(); /*string*/
  _match_x291 = kk_string_is_eq(_x_x773,_x_x774,kk_context()); /*bool*/
  if (_match_x291) {
    kk_string_drop(frac_full, _ctx);
    _x_x772 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x777;
    kk_define_string_literal(, _s_x778, 1, ".", _ctx)
    _x_x777 = kk_string_dup(_s_x778, _ctx); /*string*/
    _x_x772 = kk_std_core_types__lp__plus__plus__rp_(_x_x777, frac_full, _ctx); /*string*/
  }
  _x_x771 = kk_std_core_types__lp__plus__plus__rp_(_x_x772, exponent_0, _ctx); /*string*/
  _x_x769 = kk_std_core_types__lp__plus__plus__rp_(_x_x770, _x_x771, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(sign_0, _x_x769, _ctx);
}
 
// /* Show a decimal `d` with a given precision `prec` (=`-1000`) in fixed-point notation.
// The precision specifies the  number of digits after the dot.
// If the precision is negative, _at most_  `prec` digits after the dot are displayed,
// while for a positive precision, exactly `prec` digits are used.
// ```
// > decimal(1,-1).show-fixed
// "0.1"
// > 0.1.decimal.show-fixed
// "0.1000000000000000055511151231257827021181583404541015625"
// > 0.1.decimal.show-fixed(20)
// "0.1000000000000000555"
// > 0.1.decimal.show-fixed(-20)
// "0.1000000000000000555"
// > decimal(1,-1).show-fixed(20)
// "0.1000000000000000000"
// ```
// .
// */

kk_string_t kk_std_num_decimal_show_fixed(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : ? int) -> string */ 
  kk_integer_t _b_x246_247;
  kk_integer_t _x_x779;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x245 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3985 = kk_integer_unbox(_box_x245, _ctx);
    kk_integer_dup(_uniq_prec_3985, _ctx);
    _x_x779 = _uniq_prec_3985; /*int*/
  }
  else {
    _x_x779 = kk_integer_from_small(-1000); /*int*/
  }
  _b_x246_247 = kk_integer_abs(_x_x779,kk_context()); /*int*/
  kk_std_num_decimal__decimal x;
  kk_std_core_types__optional _x_x780 = kk_std_core_types__new_Optional(kk_integer_box(_b_x246_247, _ctx), _ctx); /*? 7*/
  x = kk_std_num_decimal_round_to_prec(d, _x_x780, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  bool _match_x274;
  kk_integer_t _brw_x289;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x289 = _x; /*int*/
  }
  bool _brw_x290 = kk_integer_gte_borrow(_brw_x289,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x289, _ctx);
  _match_x274 = _brw_x290; /*bool*/
  if (_match_x274) {
    kk_string_t frac;
    bool _match_x286;
    kk_integer_t _brw_x287;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x248 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3985_0 = kk_integer_unbox(_box_x248, _ctx);
      kk_integer_dup(_uniq_prec_3985_0, _ctx);
      _brw_x287 = _uniq_prec_3985_0; /*int*/
    }
    else {
      _brw_x287 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x288 = kk_integer_lte_borrow(_brw_x287,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x287, _ctx);
    _match_x286 = _brw_x288; /*bool*/
    if (_match_x286) {
      kk_std_core_types__optional_drop(prec, _ctx);
      frac = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x782;
      kk_define_string_literal(, _s_x783, 1, ".", _ctx)
      _x_x782 = kk_string_dup(_s_x783, _ctx); /*string*/
      kk_string_t _x_x784;
      kk_string_t _x_x785;
      kk_define_string_literal(, _s_x786, 1, "0", _ctx)
      _x_x785 = kk_string_dup(_s_x786, _ctx); /*string*/
      kk_ssize_t _x_x787;
      kk_integer_t _x_x788;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x249 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3985_1 = kk_integer_unbox(_box_x249, _ctx);
        kk_integer_dup(_uniq_prec_3985_1, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x788 = _uniq_prec_3985_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x788 = kk_integer_from_small(-1000); /*int*/
      }
      _x_x787 = kk_std_core_int_ssize__t(_x_x788, _ctx); /*ssize_t*/
      _x_x784 = kk_std_core_string_repeatz(_x_x785, _x_x787, _ctx); /*string*/
      frac = kk_std_core_types__lp__plus__plus__rp_(_x_x782, _x_x784, _ctx); /*string*/
    }
    kk_string_t _x_x789;
    kk_integer_t _x_x790;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x790 = _x_0; /*int*/
    }
    _x_x789 = kk_std_core_int_show(_x_x790, _ctx); /*string*/
    kk_string_t _x_x791;
    kk_string_t _x_x792;
    kk_string_t _x_x793;
    kk_define_string_literal(, _s_x794, 1, "0", _ctx)
    _x_x793 = kk_string_dup(_s_x794, _ctx); /*string*/
    kk_ssize_t _x_x795;
    kk_integer_t _x_x796;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x796 = _x_1; /*int*/
    }
    _x_x795 = kk_std_core_int_ssize__t(_x_x796, _ctx); /*ssize_t*/
    _x_x792 = kk_std_core_string_repeatz(_x_x793, _x_x795, _ctx); /*string*/
    _x_x791 = kk_std_core_types__lp__plus__plus__rp_(_x_x792, frac, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x789, _x_x791, _ctx);
  }
  {
    kk_integer_t digits;
    kk_integer_t _x_x797;
    {
      kk_integer_t _x_2 = x.exp;
      kk_integer_dup(_x_2, _ctx);
      _x_x797 = _x_2; /*int*/
    }
    digits = kk_integer_neg(_x_x797,kk_context()); /*int*/
    kk_string_t sign_0;
    bool _match_x283;
    kk_integer_t _brw_x284;
    {
      kk_integer_t _x_3 = x.num;
      kk_integer_dup(_x_3, _ctx);
      _brw_x284 = _x_3; /*int*/
    }
    bool _brw_x285 = kk_integer_lt_borrow(_brw_x284,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x284, _ctx);
    _match_x283 = _brw_x285; /*bool*/
    if (_match_x283) {
      kk_define_string_literal(, _s_x798, 1, "-", _ctx)
      sign_0 = kk_string_dup(_s_x798, _ctx); /*string*/
    }
    else {
      sign_0 = kk_string_empty(); /*string*/
    }
    kk_integer_t i_0;
    kk_integer_t _x_x800;
    {
      kk_integer_t _x_4 = x.num;
      kk_integer_dup(_x_4, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x800 = _x_4; /*int*/
    }
    i_0 = kk_integer_abs(_x_x800,kk_context()); /*int*/
    kk_integer_t man;
    kk_integer_t _x_x801 = kk_integer_dup(i_0, _ctx); /*int*/
    kk_integer_t _x_x802 = kk_integer_dup(digits, _ctx); /*int*/
    man = kk_std_core_int_cdiv_exp10(_x_x801, _x_x802, _ctx); /*int*/
    kk_integer_t y_10220;
    kk_integer_t _x_x803 = kk_integer_dup(man, _ctx); /*int*/
    kk_integer_t _x_x804 = kk_integer_dup(digits, _ctx); /*int*/
    y_10220 = kk_std_core_int_mul_exp10(_x_x803, _x_x804, _ctx); /*int*/
    kk_integer_t frac_0 = kk_integer_sub(i_0,y_10220,kk_context()); /*int*/;
    kk_string_t frac_1_10235;
    kk_string_t _own_x281 = kk_std_core_int_show(frac_0, _ctx); /*string*/;
    kk_string_t _brw_x282;
    kk_std_core_types__optional _x_x805 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _brw_x282 = kk_std_core_string_pad_left(_own_x281, digits, _x_x805, _ctx); /*string*/
    kk_integer_drop(digits, _ctx);
    frac_1_10235 = _brw_x282; /*string*/
    kk_string_t frac_trim;
    kk_string_t _x_x806;
    kk_define_string_literal(, _s_x807, 1, "0", _ctx)
    _x_x806 = kk_string_dup(_s_x807, _ctx); /*string*/
    frac_trim = kk_std_core_sslice_trim_right(frac_1_10235, _x_x806, _ctx); /*string*/
    kk_string_t frac_full;
    bool _match_x276;
    kk_integer_t _brw_x279;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x252 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3985_2 = kk_integer_unbox(_box_x252, _ctx);
      kk_integer_dup(_uniq_prec_3985_2, _ctx);
      _brw_x279 = _uniq_prec_3985_2; /*int*/
    }
    else {
      _brw_x279 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x280 = kk_integer_gte_borrow(_brw_x279,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x279, _ctx);
    _match_x276 = _brw_x280; /*bool*/
    if (_match_x276) {
      kk_integer_t _brw_x277;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x253 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3985_3 = kk_integer_unbox(_box_x253, _ctx);
        kk_integer_dup(_uniq_prec_3985_3, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _brw_x277 = _uniq_prec_3985_3; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _brw_x277 = kk_integer_from_small(-1000); /*int*/
      }
      kk_string_t _brw_x278;
      kk_std_core_types__optional _x_x808 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
      _brw_x278 = kk_std_core_string_pad_right(frac_trim, _brw_x277, _x_x808, _ctx); /*string*/
      kk_integer_drop(_brw_x277, _ctx);
      frac_full = _brw_x278; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      frac_full = frac_trim; /*string*/
    }
    kk_string_t _x_x809;
    kk_string_t _x_x810 = kk_std_core_int_show(man, _ctx); /*string*/
    kk_string_t _x_x811;
    bool _match_x275;
    kk_string_t _x_x812 = kk_string_dup(frac_full, _ctx); /*string*/
    kk_string_t _x_x813 = kk_string_empty(); /*string*/
    _match_x275 = kk_string_is_eq(_x_x812,_x_x813,kk_context()); /*bool*/
    if (_match_x275) {
      kk_string_drop(frac_full, _ctx);
      _x_x811 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x816;
      kk_define_string_literal(, _s_x817, 1, ".", _ctx)
      _x_x816 = kk_string_dup(_s_x817, _ctx); /*string*/
      _x_x811 = kk_std_core_types__lp__plus__plus__rp_(_x_x816, frac_full, _ctx); /*string*/
    }
    _x_x809 = kk_std_core_types__lp__plus__plus__rp_(_x_x810, _x_x811, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(sign_0, _x_x809, _ctx);
  }
}
 
// Show a decimal `d` with a given precision `prec` (=`-1000`).
// The precision specifies the  number of digits after the dot (in either scientific of fixed-point notation).
// If the precision is negative, _at most_ `prec` digits are displayed, while for a positive
// precision, exactly `prec` digits behind the dot are displayed.
// This uses `show-fixed` when the exponent of `d` in scientific notation is larger than -5
// and smaller than the precision (or 15 in case of a negative precision), otherwise it uses `show-exp`.

kk_string_t kk_std_num_decimal_show(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : ? int) -> string */ 
  kk_integer_t x_0_10190;
  kk_integer_t _x_x818;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x818 = _x; /*int*/
  }
  x_0_10190 = kk_std_core_int_count_digits(_x_x818, _ctx); /*int*/
  kk_integer_t x_10188;
  kk_integer_t _x_x819;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    _x_x819 = _x_0; /*int*/
  }
  x_10188 = kk_integer_add(x_0_10190,_x_x819,kk_context()); /*int*/
  kk_integer_t exp = kk_integer_add_small_const(x_10188, -1, _ctx); /*int*/;
  bool _match_x267 = kk_integer_gt_borrow(exp,(kk_integer_from_small(-5)),kk_context()); /*bool*/;
  if (_match_x267) {
    bool _match_x268;
    kk_integer_t _brw_x272;
    bool _match_x269;
    kk_integer_t _brw_x270;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x256 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3450 = kk_integer_unbox(_box_x256, _ctx);
      kk_integer_dup(_uniq_prec_3450, _ctx);
      _brw_x270 = _uniq_prec_3450; /*int*/
    }
    else {
      _brw_x270 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x271 = kk_integer_lt_borrow(_brw_x270,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x270, _ctx);
    _match_x269 = _brw_x271; /*bool*/
    if (_match_x269) {
      _brw_x272 = kk_integer_from_small(15); /*int*/
    }
    else {
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x257 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3450_0 = kk_integer_unbox(_box_x257, _ctx);
        kk_integer_dup(_uniq_prec_3450_0, _ctx);
        _brw_x272 = _uniq_prec_3450_0; /*int*/
      }
      else {
        _brw_x272 = kk_integer_from_small(-1000); /*int*/
      }
    }
    bool _brw_x273 = kk_integer_lt_borrow(exp,_brw_x272,kk_context()); /*bool*/;
    kk_integer_drop(exp, _ctx);
    kk_integer_drop(_brw_x272, _ctx);
    _match_x268 = _brw_x273; /*bool*/
    if (_match_x268) {
      kk_std_core_types__optional _x_x820;
      kk_box_t _x_x821;
      kk_integer_t _x_x822;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x258 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3450_1 = kk_integer_unbox(_box_x258, _ctx);
        kk_integer_dup(_uniq_prec_3450_1, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x822 = _uniq_prec_3450_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x822 = kk_integer_from_small(-1000); /*int*/
      }
      _x_x821 = kk_integer_box(_x_x822, _ctx); /*7*/
      _x_x820 = kk_std_core_types__new_Optional(_x_x821, _ctx); /*? 7*/
      return kk_std_num_decimal_show_fixed(d, _x_x820, _ctx);
    }
    {
      kk_std_core_types__optional _x_x823;
      kk_box_t _x_x824;
      kk_integer_t _x_x825;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x260 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3450_2 = kk_integer_unbox(_box_x260, _ctx);
        kk_integer_dup(_uniq_prec_3450_2, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x825 = _uniq_prec_3450_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x825 = kk_integer_from_small(-1000); /*int*/
      }
      _x_x824 = kk_integer_box(_x_x825, _ctx); /*7*/
      _x_x823 = kk_std_core_types__new_Optional(_x_x824, _ctx); /*? 7*/
      return kk_std_num_decimal_show_exp(d, _x_x823, _ctx);
    }
  }
  {
    kk_integer_drop(exp, _ctx);
    kk_std_core_types__optional _x_x826;
    kk_box_t _x_x827;
    kk_integer_t _x_x828;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x262 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3450_3 = kk_integer_unbox(_box_x262, _ctx);
      kk_integer_dup(_uniq_prec_3450_3, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x828 = _uniq_prec_3450_3; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x828 = kk_integer_from_small(-1000); /*int*/
    }
    _x_x827 = kk_integer_box(_x_x828, _ctx); /*7*/
    _x_x826 = kk_std_core_types__new_Optional(_x_x827, _ctx); /*? 7*/
    return kk_std_num_decimal_show_exp(d, _x_x826, _ctx);
  }
}
 
// Show a decimal `d` using its internal representation.

kk_string_t kk_std_num_decimal_show_raw(kk_std_num_decimal__decimal d, kk_context_t* _ctx) { /* (d : decimal) -> string */ 
  kk_string_t _x_x829;
  kk_integer_t _x_x830;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x830 = _x; /*int*/
  }
  _x_x829 = kk_std_core_int_show(_x_x830, _ctx); /*string*/
  kk_string_t _x_x831;
  kk_string_t _x_x832;
  kk_define_string_literal(, _s_x833, 1, "e", _ctx)
  _x_x832 = kk_string_dup(_s_x833, _ctx); /*string*/
  kk_string_t _x_x834;
  kk_integer_t _x_x835;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(d, _ctx);
    _x_x835 = _x_0; /*int*/
  }
  _x_x834 = kk_std_core_int_show(_x_x835, _ctx); /*string*/
  _x_x831 = kk_std_core_types__lp__plus__plus__rp_(_x_x832, _x_x834, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x829, _x_x831, _ctx);
}

// initialization
void kk_std_num_decimal__init(kk_context_t* _ctx){
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
  kk_std_text_parse__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_num_decimal_zero = kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/decimal/decimal*/
  }
  {
    kk_std_num_decimal_maxexp = kk_integer_from_small(308); /*int*/
  }
  {
    kk_std_num_decimal_maxprecise = kk_integer_from_double((0x1.c6bf52634p49),kk_context()); /*int*/
  }
  {
    kk_integer_t _x_x567 = kk_integer_dup(kk_std_num_decimal_maxprecise, _ctx); /*int*/
    kk_std_num_decimal_minprecise = kk_integer_neg(_x_x567,kk_context()); /*int*/
  }
}

// termination
void kk_std_num_decimal__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_std_num_decimal_minprecise, _ctx);
  kk_integer_drop(kk_std_num_decimal_maxprecise, _ctx);
  kk_integer_drop(kk_std_num_decimal_maxexp, _ctx);
  kk_std_num_decimal__decimal_drop(kk_std_num_decimal_zero, _ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_text_parse__done(_ctx);
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
