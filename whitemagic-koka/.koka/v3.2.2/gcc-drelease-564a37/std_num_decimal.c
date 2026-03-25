// Koka generated module: std/num/decimal, koka version: 3.2.2, platform: 64-bit
#include "std_num_decimal.h"

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_fs__copy(kk_std_num_decimal__decimal _this, kk_std_core_types__optional num, kk_std_core_types__optional exp, kk_context_t* _ctx) { /* (decimal, num : ? int, exp : ? int) -> decimal */ 
  kk_integer_t _x_x551;
  if (kk_std_core_types__is_Optional(num, _ctx)) {
    kk_box_t _box_x0 = num._cons._Optional.value;
    kk_integer_t _uniq_num_109 = kk_integer_unbox(_box_x0, _ctx);
    kk_integer_dup(_uniq_num_109, _ctx);
    kk_std_core_types__optional_drop(num, _ctx);
    _x_x551 = _uniq_num_109; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(num, _ctx);
    {
      kk_integer_t _x = _this.num;
      kk_integer_dup(_x, _ctx);
      _x_x551 = _x; /*int*/
    }
  }
  kk_integer_t _x_x552;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x1 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_117 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_exp_117, _ctx);
    kk_std_core_types__optional_drop(exp, _ctx);
    kk_std_num_decimal__decimal_drop(_this, _ctx);
    _x_x552 = _uniq_exp_117; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(exp, _ctx);
    {
      kk_integer_t _x_0 = _this.exp;
      kk_integer_dup(_x_0, _ctx);
      kk_std_num_decimal__decimal_drop(_this, _ctx);
      _x_x552 = _x_0; /*int*/
    }
  }
  return kk_std_num_decimal__new_Decimal(_x_x551, _x_x552, _ctx);
}
 
// The decimal zero.

kk_std_num_decimal__decimal kk_std_num_decimal_zero;
 
// The absolute value of a decimal

kk_std_num_decimal__decimal kk_std_num_decimal_abs(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool _match_x535;
  kk_integer_t _brw_x536;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _brw_x536 = _x; /*int*/
  }
  bool _brw_x537 = kk_integer_lt_borrow(_brw_x536,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x536, _ctx);
  _match_x535 = _brw_x537; /*bool*/
  if (_match_x535) {
    kk_integer_t _x_x556;
    kk_integer_t _x_x557;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x557 = _x_0; /*int*/
    }
    _x_x556 = kk_integer_neg(_x_x557,kk_context()); /*int*/
    kk_integer_t _x_x558;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x558 = _x_1; /*int*/
    }
    return kk_std_num_decimal__new_Decimal(_x_x556, _x_x558, _ctx);
  }
  {
    return x;
  }
}
 
// Create a decimal from an integer `i` with an optional
// exponent `exp` (=`0`) such that the result equals `i`&times;10^`exp`^.

kk_std_num_decimal__decimal kk_std_num_decimal_decimal_exp(kk_integer_t i, kk_std_core_types__optional exp, kk_context_t* _ctx) { /* (i : int, exp : ? int) -> decimal */ 
  kk_integer_t x;
  bool _match_x531;
  kk_integer_t _brw_x532;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x2 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_exp_619, _ctx);
    _brw_x532 = _uniq_exp_619; /*int*/
  }
  else {
    _brw_x532 = kk_integer_from_small(0); /*int*/
  }
  bool _brw_x533 = kk_integer_is_zero_borrow(_brw_x532); /*bool*/;
  kk_integer_drop(_brw_x532, _ctx);
  _match_x531 = _brw_x533; /*bool*/
  if (_match_x531) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x_x560;
    kk_integer_t _x_x561;
    if (kk_std_core_types__is_Optional(exp, _ctx)) {
      kk_box_t _box_x3 = exp._cons._Optional.value;
      kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x3, _ctx);
      kk_integer_dup(_uniq_exp_619_0, _ctx);
      _x_x561 = _uniq_exp_619_0; /*int*/
    }
    else {
      _x_x561 = kk_integer_from_small(0); /*int*/
    }
    _x_x560 = kk_integer_div(_x_x561,(kk_integer_from_small(7)),kk_context()); /*int*/
    x = kk_integer_mul((kk_integer_from_small(7)),_x_x560,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x_x562;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x4 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_exp_619_1, _ctx);
    _x_x562 = _uniq_exp_619_1; /*int*/
  }
  else {
    _x_x562 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x563 = kk_integer_dup(x, _ctx); /*int*/
  diff = kk_integer_sub(_x_x562,_x_x563,kk_context()); /*int*/
  bool _match_x530 = kk_integer_is_zero_borrow(diff); /*bool*/;
  if (_match_x530) {
    kk_integer_drop(x, _ctx);
    kk_integer_drop(diff, _ctx);
    kk_integer_t _x_x564;
    if (kk_std_core_types__is_Optional(exp, _ctx)) {
      kk_box_t _box_x5 = exp._cons._Optional.value;
      kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x5, _ctx);
      kk_integer_dup(_uniq_exp_619_2, _ctx);
      kk_std_core_types__optional_drop(exp, _ctx);
      _x_x564 = _uniq_exp_619_2; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(exp, _ctx);
      _x_x564 = kk_integer_from_small(0); /*int*/
    }
    return kk_std_num_decimal__new_Decimal(i, _x_x564, _ctx);
  }
  {
    kk_std_core_types__optional_drop(exp, _ctx);
    kk_integer_t _x_x565;
    kk_integer_t _x_x566 = kk_integer_abs(diff,kk_context()); /*int*/
    _x_x565 = kk_std_core_int_mul_exp10(i, _x_x566, _ctx); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x565, x, _ctx);
  }
}
 
// Ensure a decimal `x` has an exponent such that `x.exp <= e`.

kk_std_num_decimal__decimal kk_std_num_decimal_expand(kk_std_num_decimal__decimal x, kk_integer_t e, kk_context_t* _ctx) { /* (x : decimal, e : int) -> decimal */ 
  bool _match_x525;
  kk_integer_t _brw_x528;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x528 = _x; /*int*/
  }
  bool _brw_x529 = kk_integer_lte_borrow(_brw_x528,e,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x528, _ctx);
  _match_x525 = _brw_x529; /*bool*/
  if (_match_x525) {
    kk_integer_drop(e, _ctx);
    return x;
  }
  {
    kk_integer_t i_10019;
    kk_integer_t _x_x567;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x567 = _x_0; /*int*/
    }
    kk_integer_t _x_x568;
    kk_integer_t _x_x569;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x569 = _x_1; /*int*/
    }
    kk_integer_t _x_x570 = kk_integer_dup(e, _ctx); /*int*/
    _x_x568 = kk_integer_sub(_x_x569,_x_x570,kk_context()); /*int*/
    i_10019 = kk_std_core_int_mul_exp10(_x_x567, _x_x568, _ctx); /*int*/
    kk_integer_t x_0;
    bool _match_x527 = kk_integer_is_zero_borrow(e); /*bool*/;
    if (_match_x527) {
      x_0 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x_x571;
      kk_integer_t _x_x572 = kk_integer_dup(e, _ctx); /*int*/
      _x_x571 = kk_integer_div(_x_x572,(kk_integer_from_small(7)),kk_context()); /*int*/
      x_0 = kk_integer_mul((kk_integer_from_small(7)),_x_x571,kk_context()); /*int*/
    }
    kk_integer_t diff;
    kk_integer_t _x_x573 = kk_integer_dup(e, _ctx); /*int*/
    kk_integer_t _x_x574 = kk_integer_dup(x_0, _ctx); /*int*/
    diff = kk_integer_sub(_x_x573,_x_x574,kk_context()); /*int*/
    bool _match_x526 = kk_integer_is_zero_borrow(diff); /*bool*/;
    if (_match_x526) {
      kk_integer_drop(x_0, _ctx);
      kk_integer_drop(diff, _ctx);
      return kk_std_num_decimal__new_Decimal(i_10019, e, _ctx);
    }
    {
      kk_integer_drop(e, _ctx);
      kk_integer_t _x_x575;
      kk_integer_t _x_x576 = kk_integer_abs(diff,kk_context()); /*int*/
      _x_x575 = kk_std_core_int_mul_exp10(i_10019, _x_x576, _ctx); /*int*/
      return kk_std_num_decimal__new_Decimal(_x_x575, x_0, _ctx);
    }
  }
}
 
// Compare decimals.

kk_std_core_types__order kk_std_num_decimal_cmp(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> order */ 
  kk_integer_t e;
  bool _match_x521;
  kk_integer_t _brw_x523;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x523 = _x; /*int*/
  }
  kk_integer_t _brw_x522;
  {
    kk_integer_t _x_0 = y.exp;
    kk_integer_dup(_x_0, _ctx);
    _brw_x522 = _x_0; /*int*/
  }
  bool _brw_x524 = kk_integer_lte_borrow(_brw_x523,_brw_x522,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x523, _ctx);
  kk_integer_drop(_brw_x522, _ctx);
  _match_x521 = _brw_x524; /*bool*/
  if (_match_x521) {
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
  kk_integer_t _x_x577 = kk_integer_dup(e, _ctx); /*int*/
  xx = kk_std_num_decimal_expand(x, _x_x577, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy = kk_std_num_decimal_expand(y, e, _ctx); /*std/num/decimal/decimal*/;
  bool _match_x513;
  kk_integer_t _brw_x519;
  {
    kk_integer_t _x_1_0 = xx.num;
    kk_integer_dup(_x_1_0, _ctx);
    _brw_x519 = _x_1_0; /*int*/
  }
  kk_integer_t _brw_x518;
  {
    kk_integer_t _x_2 = yy.num;
    kk_integer_dup(_x_2, _ctx);
    _brw_x518 = _x_2; /*int*/
  }
  bool _brw_x520 = kk_integer_eq_borrow(_brw_x519,_brw_x518,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x519, _ctx);
  kk_integer_drop(_brw_x518, _ctx);
  _match_x513 = _brw_x520; /*bool*/
  if (_match_x513) {
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x514;
    kk_integer_t _brw_x516;
    {
      kk_integer_t _x_1_1 = xx.num;
      kk_integer_dup(_x_1_1, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _brw_x516 = _x_1_1; /*int*/
    }
    kk_integer_t _brw_x515;
    {
      kk_integer_t _x_2_0 = yy.num;
      kk_integer_dup(_x_2_0, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _brw_x515 = _x_2_0; /*int*/
    }
    bool _brw_x517 = kk_integer_gt_borrow(_brw_x516,_brw_x515,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x516, _ctx);
    kk_integer_drop(_brw_x515, _ctx);
    _match_x514 = _brw_x517; /*bool*/
    if (_match_x514) {
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
  kk_integer_t _x_x579;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x579 = _x; /*int*/
  }
  p = kk_std_core_int_is_exp10(_x_x579, _ctx); /*int*/
  bool b_10039 = kk_integer_gt_borrow(p,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (b_10039) {
    kk_integer_t expp;
    kk_integer_t _x_x580;
    {
      kk_integer_t _x_0 = x.exp;
      kk_integer_dup(_x_0, _ctx);
      _x_x580 = _x_0; /*int*/
    }
    kk_integer_t _x_x581 = kk_integer_dup(p, _ctx); /*int*/
    expp = kk_integer_add(_x_x580,_x_x581,kk_context()); /*int*/
    bool _match_x504;
    kk_integer_t _brw_x509;
    bool _match_x508 = kk_integer_is_zero_borrow(expp); /*bool*/;
    if (_match_x508) {
      _brw_x509 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x_x582;
      kk_integer_t _x_x583 = kk_integer_dup(expp, _ctx); /*int*/
      _x_x582 = kk_integer_div(_x_x583,(kk_integer_from_small(7)),kk_context()); /*int*/
      _brw_x509 = kk_integer_mul((kk_integer_from_small(7)),_x_x582,kk_context()); /*int*/
    }
    kk_integer_t _brw_x507;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      _brw_x507 = _x_1; /*int*/
    }
    bool _brw_x510 = kk_integer_eq_borrow(_brw_x509,_brw_x507,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x509, _ctx);
    kk_integer_drop(_brw_x507, _ctx);
    _match_x504 = _brw_x510; /*bool*/
    if (_match_x504) {
      kk_integer_drop(p, _ctx);
      kk_integer_drop(expp, _ctx);
      return x;
    }
    {
      kk_integer_t i_0_10046;
      kk_integer_t _x_x584;
      {
        kk_integer_t _x_2 = x.num;
        kk_integer_dup(_x_2, _ctx);
        kk_std_num_decimal__decimal_drop(x, _ctx);
        _x_x584 = _x_2; /*int*/
      }
      i_0_10046 = kk_std_core_int_cdiv_exp10(_x_x584, p, _ctx); /*int*/
      kk_integer_t x_1;
      bool _match_x506 = kk_integer_is_zero_borrow(expp); /*bool*/;
      if (_match_x506) {
        x_1 = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_integer_t _x_x585;
        kk_integer_t _x_x586 = kk_integer_dup(expp, _ctx); /*int*/
        _x_x585 = kk_integer_div(_x_x586,(kk_integer_from_small(7)),kk_context()); /*int*/
        x_1 = kk_integer_mul((kk_integer_from_small(7)),_x_x585,kk_context()); /*int*/
      }
      kk_integer_t diff;
      kk_integer_t _x_x587 = kk_integer_dup(expp, _ctx); /*int*/
      kk_integer_t _x_x588 = kk_integer_dup(x_1, _ctx); /*int*/
      diff = kk_integer_sub(_x_x587,_x_x588,kk_context()); /*int*/
      bool _match_x505 = kk_integer_is_zero_borrow(diff); /*bool*/;
      if (_match_x505) {
        kk_integer_drop(x_1, _ctx);
        kk_integer_drop(diff, _ctx);
        return kk_std_num_decimal__new_Decimal(i_0_10046, expp, _ctx);
      }
      {
        kk_integer_drop(expp, _ctx);
        kk_integer_t _x_x589;
        kk_integer_t _x_x590 = kk_integer_abs(diff,kk_context()); /*int*/
        _x_x589 = kk_std_core_int_mul_exp10(i_0_10046, _x_x590, _ctx); /*int*/
        return kk_std_num_decimal__new_Decimal(_x_x589, x_1, _ctx);
      }
    }
  }
  {
    kk_integer_drop(p, _ctx);
    return x;
  }
}
 
// Multiply two decimals with full precision.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__star__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_integer_t i_10052;
  kk_integer_t _x_x591;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x591 = _x; /*int*/
  }
  kk_integer_t _x_x592;
  {
    kk_integer_t _x_0 = y.num;
    kk_integer_dup(_x_0, _ctx);
    _x_x592 = _x_0; /*int*/
  }
  i_10052 = kk_integer_mul(_x_x591,_x_x592,kk_context()); /*int*/
  kk_integer_t _b_x6_7;
  kk_integer_t _x_x593;
  {
    kk_integer_t _x_1 = x.exp;
    kk_integer_dup(_x_1, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x593 = _x_1; /*int*/
  }
  kk_integer_t _x_x594;
  {
    kk_integer_t _x_2 = y.exp;
    kk_integer_dup(_x_2, _ctx);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x_x594 = _x_2; /*int*/
  }
  _b_x6_7 = kk_integer_add(_x_x593,_x_x594,kk_context()); /*int*/
  kk_std_core_types__optional exp_10053 = kk_std_core_types__new_Optional(kk_integer_box(_b_x6_7, _ctx), _ctx); /*? int*/;
  kk_integer_t x_0;
  bool _match_x501;
  kk_integer_t _brw_x502;
  if (kk_std_core_types__is_Optional(exp_10053, _ctx)) {
    kk_box_t _box_x8 = exp_10053._cons._Optional.value;
    kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x8, _ctx);
    kk_integer_dup(_uniq_exp_619, _ctx);
    _brw_x502 = _uniq_exp_619; /*int*/
  }
  else {
    _brw_x502 = kk_integer_from_small(0); /*int*/
  }
  bool _brw_x503 = kk_integer_is_zero_borrow(_brw_x502); /*bool*/;
  kk_integer_drop(_brw_x502, _ctx);
  _match_x501 = _brw_x503; /*bool*/
  if (_match_x501) {
    x_0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x_x595;
    kk_integer_t _x_x596;
    if (kk_std_core_types__is_Optional(exp_10053, _ctx)) {
      kk_box_t _box_x9 = exp_10053._cons._Optional.value;
      kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x9, _ctx);
      kk_integer_dup(_uniq_exp_619_0, _ctx);
      _x_x596 = _uniq_exp_619_0; /*int*/
    }
    else {
      _x_x596 = kk_integer_from_small(0); /*int*/
    }
    _x_x595 = kk_integer_div(_x_x596,(kk_integer_from_small(7)),kk_context()); /*int*/
    x_0 = kk_integer_mul((kk_integer_from_small(7)),_x_x595,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x_x597;
  if (kk_std_core_types__is_Optional(exp_10053, _ctx)) {
    kk_box_t _box_x10 = exp_10053._cons._Optional.value;
    kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x10, _ctx);
    kk_integer_dup(_uniq_exp_619_1, _ctx);
    _x_x597 = _uniq_exp_619_1; /*int*/
  }
  else {
    _x_x597 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x598 = kk_integer_dup(x_0, _ctx); /*int*/
  diff = kk_integer_sub(_x_x597,_x_x598,kk_context()); /*int*/
  kk_std_num_decimal__decimal z;
  bool _match_x500 = kk_integer_is_zero_borrow(diff); /*bool*/;
  if (_match_x500) {
    kk_integer_drop(x_0, _ctx);
    kk_integer_drop(diff, _ctx);
    kk_integer_t _x_x599;
    if (kk_std_core_types__is_Optional(exp_10053, _ctx)) {
      kk_box_t _box_x11 = exp_10053._cons._Optional.value;
      kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x11, _ctx);
      kk_integer_dup(_uniq_exp_619_2, _ctx);
      kk_std_core_types__optional_drop(exp_10053, _ctx);
      _x_x599 = _uniq_exp_619_2; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(exp_10053, _ctx);
      _x_x599 = kk_integer_from_small(0); /*int*/
    }
    z = kk_std_num_decimal__new_Decimal(i_10052, _x_x599, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(exp_10053, _ctx);
    kk_integer_t _x_x600;
    kk_integer_t _x_x601 = kk_integer_abs(diff,kk_context()); /*int*/
    _x_x600 = kk_std_core_int_mul_exp10(i_10052, _x_x601, _ctx); /*int*/
    z = kk_std_num_decimal__new_Decimal(_x_x600, x_0, _ctx); /*std/num/decimal/decimal*/
  }
  bool _match_x497;
  kk_integer_t _brw_x498;
  {
    kk_integer_t _x_3 = z.exp;
    kk_integer_dup(_x_3, _ctx);
    _brw_x498 = _x_3; /*int*/
  }
  bool _brw_x499 = kk_integer_lt_borrow(_brw_x498,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x498, _ctx);
  _match_x497 = _brw_x499; /*bool*/
  if (_match_x497) {
    return kk_std_num_decimal_reduce(z, _ctx);
  }
  {
    return z;
  }
}
 
// Add two decimals.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__plus__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_integer_t e;
  bool _match_x493;
  kk_integer_t _brw_x495;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x495 = _x; /*int*/
  }
  kk_integer_t _brw_x494;
  {
    kk_integer_t _x_0 = y.exp;
    kk_integer_dup(_x_0, _ctx);
    _brw_x494 = _x_0; /*int*/
  }
  bool _brw_x496 = kk_integer_lte_borrow(_brw_x495,_brw_x494,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x495, _ctx);
  kk_integer_drop(_brw_x494, _ctx);
  _match_x493 = _brw_x496; /*bool*/
  if (_match_x493) {
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
  kk_integer_t _x_x602 = kk_integer_dup(e, _ctx); /*int*/
  xx = kk_std_num_decimal_expand(x, _x_x602, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x_x603 = kk_integer_dup(e, _ctx); /*int*/
  yy = kk_std_num_decimal_expand(y, _x_x603, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x_x604;
  kk_integer_t _x_x605;
  {
    kk_integer_t _x_1_0 = xx.num;
    kk_integer_dup(_x_1_0, _ctx);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x_x605 = _x_1_0; /*int*/
  }
  kk_integer_t _x_x606;
  {
    kk_integer_t _x_2 = yy.num;
    kk_integer_dup(_x_2, _ctx);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x_x606 = _x_2; /*int*/
  }
  _x_x604 = kk_integer_add(_x_x605,_x_x606,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x_x604, e, _ctx);
}
 
// Subtract two decimals.

kk_std_num_decimal__decimal kk_std_num_decimal__lp__dash__rp_(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_std_num_decimal__decimal y_0_10074;
  kk_integer_t _x_x607;
  kk_integer_t _x_x608;
  {
    kk_integer_t _x_3 = y.num;
    kk_integer_dup(_x_3, _ctx);
    _x_x608 = _x_3; /*int*/
  }
  _x_x607 = kk_integer_neg(_x_x608,kk_context()); /*int*/
  kk_integer_t _x_x609;
  {
    kk_integer_t _x_4 = y.exp;
    kk_integer_dup(_x_4, _ctx);
    kk_std_num_decimal__decimal_drop(y, _ctx);
    _x_x609 = _x_4; /*int*/
  }
  y_0_10074 = kk_std_num_decimal__new_Decimal(_x_x607, _x_x609, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t e;
  bool _match_x489;
  kk_integer_t _brw_x491;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x491 = _x; /*int*/
  }
  kk_integer_t _brw_x490;
  {
    kk_integer_t _x_0 = y_0_10074.exp;
    kk_integer_dup(_x_0, _ctx);
    _brw_x490 = _x_0; /*int*/
  }
  bool _brw_x492 = kk_integer_lte_borrow(_brw_x491,_brw_x490,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x491, _ctx);
  kk_integer_drop(_brw_x490, _ctx);
  _match_x489 = _brw_x492; /*bool*/
  if (_match_x489) {
    kk_integer_t _x_1 = x.exp;
    kk_integer_dup(_x_1, _ctx);
    e = _x_1; /*int*/
  }
  else {
    kk_integer_t _x_0_0 = y_0_10074.exp;
    kk_integer_dup(_x_0_0, _ctx);
    e = _x_0_0; /*int*/
  }
  kk_std_num_decimal__decimal xx;
  kk_integer_t _x_x610 = kk_integer_dup(e, _ctx); /*int*/
  xx = kk_std_num_decimal_expand(x, _x_x610, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal yy;
  kk_integer_t _x_x611 = kk_integer_dup(e, _ctx); /*int*/
  yy = kk_std_num_decimal_expand(y_0_10074, _x_x611, _ctx); /*std/num/decimal/decimal*/
  kk_integer_t _x_x612;
  kk_integer_t _x_x613;
  {
    kk_integer_t _x_1_0 = xx.num;
    kk_integer_dup(_x_1_0, _ctx);
    kk_std_num_decimal__decimal_drop(xx, _ctx);
    _x_x613 = _x_1_0; /*int*/
  }
  kk_integer_t _x_x614;
  {
    kk_integer_t _x_2 = yy.num;
    kk_integer_dup(_x_2, _ctx);
    kk_std_num_decimal__decimal_drop(yy, _ctx);
    _x_x614 = _x_2; /*int*/
  }
  _x_x612 = kk_integer_add(_x_x613,_x_x614,kk_context()); /*int*/
  return kk_std_num_decimal__new_Decimal(_x_x612, e, _ctx);
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
  bool _match_x466;
  kk_integer_t _brw_x487;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _brw_x487 = _x; /*int*/
  }
  bool _brw_x488 = kk_integer_is_zero_borrow(_brw_x487); /*bool*/;
  kk_integer_drop(_brw_x487, _ctx);
  _match_x466 = _brw_x488; /*bool*/
  if (_match_x466) {
    kk_std_num_decimal__decimal_drop(y, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    kk_std_core_types__optional_drop(min_prec, _ctx);
    return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
  }
  {
    bool _match_x467;
    kk_integer_t _brw_x485;
    {
      kk_integer_t _x_0 = y.num;
      kk_integer_dup(_x_0, _ctx);
      _brw_x485 = _x_0; /*int*/
    }
    bool _brw_x486 = kk_integer_is_zero_borrow(_brw_x485); /*bool*/;
    kk_integer_drop(_brw_x485, _ctx);
    _match_x467 = _brw_x486; /*bool*/
    if (_match_x467) {
      kk_std_num_decimal__decimal_drop(y, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      kk_std_core_types__optional_drop(min_prec, _ctx);
      return kk_std_num_decimal__new_Decimal(kk_integer_from_small(0), kk_integer_from_small(0), _ctx);
    }
    {
      kk_integer_t e;
      kk_integer_t _x_x615;
      {
        kk_integer_t _x_1 = x.exp;
        kk_integer_dup(_x_1, _ctx);
        _x_x615 = _x_1; /*int*/
      }
      kk_integer_t _x_x616;
      {
        kk_integer_t _x_2 = y.exp;
        kk_integer_dup(_x_2, _ctx);
        _x_x616 = _x_2; /*int*/
      }
      e = kk_integer_sub(_x_x615,_x_x616,kk_context()); /*int*/
      kk_integer_t xdigits;
      kk_integer_t _x_x617;
      {
        kk_integer_t _x_3 = x.num;
        kk_integer_dup(_x_3, _ctx);
        _x_x617 = _x_3; /*int*/
      }
      xdigits = kk_std_core_int_count_digits(_x_x617, _ctx); /*int*/
      kk_integer_t ydigits;
      kk_integer_t _x_x618;
      {
        kk_integer_t _x_4 = y.num;
        kk_integer_dup(_x_4, _ctx);
        _x_x618 = _x_4; /*int*/
      }
      ydigits = kk_std_core_int_count_digits(_x_x618, _ctx); /*int*/
      kk_integer_t j_10099 = kk_integer_sub(ydigits,xdigits,kk_context()); /*int*/;
      kk_integer_t x_3_10096;
      bool _match_x484 = kk_integer_gte_borrow((kk_integer_from_small(0)),j_10099,kk_context()); /*bool*/;
      if (_match_x484) {
        kk_integer_drop(j_10099, _ctx);
        x_3_10096 = kk_integer_from_small(0); /*int*/
      }
      else {
        x_3_10096 = j_10099; /*int*/
      }
      kk_integer_t extra;
      kk_integer_t _x_x619;
      if (kk_std_core_types__is_Optional(min_prec, _ctx)) {
        kk_box_t _box_x12 = min_prec._cons._Optional.value;
        kk_integer_t _uniq_min_prec_666 = kk_integer_unbox(_box_x12, _ctx);
        kk_integer_dup(_uniq_min_prec_666, _ctx);
        kk_std_core_types__optional_drop(min_prec, _ctx);
        _x_x619 = _uniq_min_prec_666; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(min_prec, _ctx);
        _x_x619 = kk_integer_from_small(15); /*int*/
      }
      extra = kk_integer_add(x_3_10096,_x_x619,kk_context()); /*int*/
      kk_std_num_decimal__decimal x_0_10345;
      bool _match_x475 = kk_integer_gt_borrow(extra,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x475) {
        kk_integer_t i_0_10102;
        kk_integer_t _x_x620;
        kk_integer_t _x_x621;
        {
          kk_integer_t _x_5_0 = x.num;
          kk_integer_dup(_x_5_0, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x621 = _x_5_0; /*int*/
        }
        kk_integer_t _x_x622 = kk_integer_dup(extra, _ctx); /*int*/
        _x_x620 = kk_std_core_int_mul_exp10(_x_x621, _x_x622, _ctx); /*int*/
        kk_integer_t _x_x623;
        {
          kk_integer_t _x_6 = y.num;
          kk_integer_dup(_x_6, _ctx);
          kk_std_num_decimal__decimal_drop(y, _ctx);
          _x_x623 = _x_6; /*int*/
        }
        i_0_10102 = kk_integer_div(_x_x620,_x_x623,kk_context()); /*int*/
        kk_integer_t _b_x13_14 = kk_integer_sub(e,extra,kk_context()); /*int*/;
        kk_std_core_types__optional exp_10103 = kk_std_core_types__new_Optional(kk_integer_box(_b_x13_14, _ctx), _ctx); /*? int*/;
        kk_integer_t x_5;
        bool _match_x481;
        kk_integer_t _brw_x482;
        if (kk_std_core_types__is_Optional(exp_10103, _ctx)) {
          kk_box_t _box_x15 = exp_10103._cons._Optional.value;
          kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x15, _ctx);
          kk_integer_dup(_uniq_exp_619, _ctx);
          _brw_x482 = _uniq_exp_619; /*int*/
        }
        else {
          _brw_x482 = kk_integer_from_small(0); /*int*/
        }
        bool _brw_x483 = kk_integer_is_zero_borrow(_brw_x482); /*bool*/;
        kk_integer_drop(_brw_x482, _ctx);
        _match_x481 = _brw_x483; /*bool*/
        if (_match_x481) {
          x_5 = kk_integer_from_small(0); /*int*/
        }
        else {
          kk_integer_t _x_x624;
          kk_integer_t _x_x625;
          if (kk_std_core_types__is_Optional(exp_10103, _ctx)) {
            kk_box_t _box_x16 = exp_10103._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x16, _ctx);
            kk_integer_dup(_uniq_exp_619_0, _ctx);
            _x_x625 = _uniq_exp_619_0; /*int*/
          }
          else {
            _x_x625 = kk_integer_from_small(0); /*int*/
          }
          _x_x624 = kk_integer_div(_x_x625,(kk_integer_from_small(7)),kk_context()); /*int*/
          x_5 = kk_integer_mul((kk_integer_from_small(7)),_x_x624,kk_context()); /*int*/
        }
        kk_integer_t diff_0;
        kk_integer_t _x_x626;
        if (kk_std_core_types__is_Optional(exp_10103, _ctx)) {
          kk_box_t _box_x17 = exp_10103._cons._Optional.value;
          kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x17, _ctx);
          kk_integer_dup(_uniq_exp_619_1, _ctx);
          _x_x626 = _uniq_exp_619_1; /*int*/
        }
        else {
          _x_x626 = kk_integer_from_small(0); /*int*/
        }
        kk_integer_t _x_x627 = kk_integer_dup(x_5, _ctx); /*int*/
        diff_0 = kk_integer_sub(_x_x626,_x_x627,kk_context()); /*int*/
        bool _match_x480 = kk_integer_is_zero_borrow(diff_0); /*bool*/;
        if (_match_x480) {
          kk_integer_drop(x_5, _ctx);
          kk_integer_drop(diff_0, _ctx);
          kk_integer_t _x_x628;
          if (kk_std_core_types__is_Optional(exp_10103, _ctx)) {
            kk_box_t _box_x18 = exp_10103._cons._Optional.value;
            kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x18, _ctx);
            kk_integer_dup(_uniq_exp_619_2, _ctx);
            kk_std_core_types__optional_drop(exp_10103, _ctx);
            _x_x628 = _uniq_exp_619_2; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(exp_10103, _ctx);
            _x_x628 = kk_integer_from_small(0); /*int*/
          }
          x_0_10345 = kk_std_num_decimal__new_Decimal(i_0_10102, _x_x628, _ctx); /*std/num/decimal/decimal*/
        }
        else {
          kk_std_core_types__optional_drop(exp_10103, _ctx);
          kk_integer_t _x_x629;
          kk_integer_t _x_x630 = kk_integer_abs(diff_0,kk_context()); /*int*/
          _x_x629 = kk_std_core_int_mul_exp10(i_0_10102, _x_x630, _ctx); /*int*/
          x_0_10345 = kk_std_num_decimal__new_Decimal(_x_x629, x_5, _ctx); /*std/num/decimal/decimal*/
        }
      }
      else {
        kk_integer_t i_1_10111;
        kk_integer_t _x_x631;
        {
          kk_integer_t _x_7 = x.num;
          kk_integer_dup(_x_7, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x631 = _x_7; /*int*/
        }
        kk_integer_t _x_x632;
        {
          kk_integer_t _x_8 = y.num;
          kk_integer_dup(_x_8, _ctx);
          kk_std_num_decimal__decimal_drop(y, _ctx);
          _x_x632 = _x_8; /*int*/
        }
        i_1_10111 = kk_integer_div(_x_x631,_x_x632,kk_context()); /*int*/
        kk_integer_t _b_x19_20 = kk_integer_sub(e,extra,kk_context()); /*int*/;
        kk_std_core_types__optional exp_1_10112 = kk_std_core_types__new_Optional(kk_integer_box(_b_x19_20, _ctx), _ctx); /*? int*/;
        kk_integer_t x_8;
        bool _match_x477;
        kk_integer_t _brw_x478;
        if (kk_std_core_types__is_Optional(exp_1_10112, _ctx)) {
          kk_box_t _box_x21 = exp_1_10112._cons._Optional.value;
          kk_integer_t _uniq_exp_619_0_0 = kk_integer_unbox(_box_x21, _ctx);
          kk_integer_dup(_uniq_exp_619_0_0, _ctx);
          _brw_x478 = _uniq_exp_619_0_0; /*int*/
        }
        else {
          _brw_x478 = kk_integer_from_small(0); /*int*/
        }
        bool _brw_x479 = kk_integer_is_zero_borrow(_brw_x478); /*bool*/;
        kk_integer_drop(_brw_x478, _ctx);
        _match_x477 = _brw_x479; /*bool*/
        if (_match_x477) {
          x_8 = kk_integer_from_small(0); /*int*/
        }
        else {
          kk_integer_t _x_x633;
          kk_integer_t _x_x634;
          if (kk_std_core_types__is_Optional(exp_1_10112, _ctx)) {
            kk_box_t _box_x22 = exp_1_10112._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0_1 = kk_integer_unbox(_box_x22, _ctx);
            kk_integer_dup(_uniq_exp_619_0_1, _ctx);
            _x_x634 = _uniq_exp_619_0_1; /*int*/
          }
          else {
            _x_x634 = kk_integer_from_small(0); /*int*/
          }
          _x_x633 = kk_integer_div(_x_x634,(kk_integer_from_small(7)),kk_context()); /*int*/
          x_8 = kk_integer_mul((kk_integer_from_small(7)),_x_x633,kk_context()); /*int*/
        }
        kk_integer_t diff_0_0;
        kk_integer_t _x_x635;
        if (kk_std_core_types__is_Optional(exp_1_10112, _ctx)) {
          kk_box_t _box_x23 = exp_1_10112._cons._Optional.value;
          kk_integer_t _uniq_exp_619_0_2 = kk_integer_unbox(_box_x23, _ctx);
          kk_integer_dup(_uniq_exp_619_0_2, _ctx);
          _x_x635 = _uniq_exp_619_0_2; /*int*/
        }
        else {
          _x_x635 = kk_integer_from_small(0); /*int*/
        }
        kk_integer_t _x_x636 = kk_integer_dup(x_8, _ctx); /*int*/
        diff_0_0 = kk_integer_sub(_x_x635,_x_x636,kk_context()); /*int*/
        bool _match_x476 = kk_integer_is_zero_borrow(diff_0_0); /*bool*/;
        if (_match_x476) {
          kk_integer_drop(x_8, _ctx);
          kk_integer_drop(diff_0_0, _ctx);
          kk_integer_t _x_x637;
          if (kk_std_core_types__is_Optional(exp_1_10112, _ctx)) {
            kk_box_t _box_x24 = exp_1_10112._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0_3 = kk_integer_unbox(_box_x24, _ctx);
            kk_integer_dup(_uniq_exp_619_0_3, _ctx);
            kk_std_core_types__optional_drop(exp_1_10112, _ctx);
            _x_x637 = _uniq_exp_619_0_3; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(exp_1_10112, _ctx);
            _x_x637 = kk_integer_from_small(0); /*int*/
          }
          x_0_10345 = kk_std_num_decimal__new_Decimal(i_1_10111, _x_x637, _ctx); /*std/num/decimal/decimal*/
        }
        else {
          kk_std_core_types__optional_drop(exp_1_10112, _ctx);
          kk_integer_t _x_x638;
          kk_integer_t _x_x639 = kk_integer_abs(diff_0_0,kk_context()); /*int*/
          _x_x638 = kk_std_core_int_mul_exp10(i_1_10111, _x_x639, _ctx); /*int*/
          x_0_10345 = kk_std_num_decimal__new_Decimal(_x_x638, x_8, _ctx); /*std/num/decimal/decimal*/
        }
      }
      kk_integer_t p;
      kk_integer_t _x_x640;
      {
        kk_integer_t _x_5 = x_0_10345.num;
        kk_integer_dup(_x_5, _ctx);
        _x_x640 = _x_5; /*int*/
      }
      p = kk_std_core_int_is_exp10(_x_x640, _ctx); /*int*/
      bool b_10039 = kk_integer_gt_borrow(p,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (b_10039) {
        kk_integer_t expp;
        kk_integer_t _x_x641;
        {
          kk_integer_t _x_0_0 = x_0_10345.exp;
          kk_integer_dup(_x_0_0, _ctx);
          _x_x641 = _x_0_0; /*int*/
        }
        kk_integer_t _x_x642 = kk_integer_dup(p, _ctx); /*int*/
        expp = kk_integer_add(_x_x641,_x_x642,kk_context()); /*int*/
        bool _match_x468;
        kk_integer_t _brw_x473;
        bool _match_x472 = kk_integer_is_zero_borrow(expp); /*bool*/;
        if (_match_x472) {
          _brw_x473 = kk_integer_from_small(0); /*int*/
        }
        else {
          kk_integer_t _x_x643;
          kk_integer_t _x_x644 = kk_integer_dup(expp, _ctx); /*int*/
          _x_x643 = kk_integer_div(_x_x644,(kk_integer_from_small(7)),kk_context()); /*int*/
          _brw_x473 = kk_integer_mul((kk_integer_from_small(7)),_x_x643,kk_context()); /*int*/
        }
        kk_integer_t _brw_x471;
        {
          kk_integer_t _x_1_0 = x_0_10345.exp;
          kk_integer_dup(_x_1_0, _ctx);
          _brw_x471 = _x_1_0; /*int*/
        }
        bool _brw_x474 = kk_integer_eq_borrow(_brw_x473,_brw_x471,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x473, _ctx);
        kk_integer_drop(_brw_x471, _ctx);
        _match_x468 = _brw_x474; /*bool*/
        if (_match_x468) {
          kk_integer_drop(p, _ctx);
          kk_integer_drop(expp, _ctx);
          return x_0_10345;
        }
        {
          kk_integer_t i_0_10046;
          kk_integer_t _x_x645;
          {
            kk_integer_t _x_2_0 = x_0_10345.num;
            kk_integer_dup(_x_2_0, _ctx);
            kk_std_num_decimal__decimal_drop(x_0_10345, _ctx);
            _x_x645 = _x_2_0; /*int*/
          }
          i_0_10046 = kk_std_core_int_cdiv_exp10(_x_x645, p, _ctx); /*int*/
          kk_integer_t x_1;
          bool _match_x470 = kk_integer_is_zero_borrow(expp); /*bool*/;
          if (_match_x470) {
            x_1 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_integer_t _x_x646;
            kk_integer_t _x_x647 = kk_integer_dup(expp, _ctx); /*int*/
            _x_x646 = kk_integer_div(_x_x647,(kk_integer_from_small(7)),kk_context()); /*int*/
            x_1 = kk_integer_mul((kk_integer_from_small(7)),_x_x646,kk_context()); /*int*/
          }
          kk_integer_t diff;
          kk_integer_t _x_x648 = kk_integer_dup(expp, _ctx); /*int*/
          kk_integer_t _x_x649 = kk_integer_dup(x_1, _ctx); /*int*/
          diff = kk_integer_sub(_x_x648,_x_x649,kk_context()); /*int*/
          bool _match_x469 = kk_integer_is_zero_borrow(diff); /*bool*/;
          if (_match_x469) {
            kk_integer_drop(x_1, _ctx);
            kk_integer_drop(diff, _ctx);
            return kk_std_num_decimal__new_Decimal(i_0_10046, expp, _ctx);
          }
          {
            kk_integer_drop(expp, _ctx);
            kk_integer_t _x_x650;
            kk_integer_t _x_x651 = kk_integer_abs(diff,kk_context()); /*int*/
            _x_x650 = kk_std_core_int_mul_exp10(i_0_10046, _x_x651, _ctx); /*int*/
            return kk_std_num_decimal__new_Decimal(_x_x650, x_1, _ctx);
          }
        }
      }
      {
        kk_integer_drop(p, _ctx);
        return x_0_10345;
      }
    }
  }
}
 
// The maximum of `x` and `y`

kk_std_num_decimal__decimal kk_std_num_decimal_max(kk_std_num_decimal__decimal x, kk_std_num_decimal__decimal y, kk_context_t* _ctx) { /* (x : decimal, y : decimal) -> decimal */ 
  kk_std_core_types__order x_0_10126;
  kk_std_num_decimal__decimal _x_x656 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x_x657 = kk_std_num_decimal__decimal_dup(y, _ctx); /*std/num/decimal/decimal*/
  x_0_10126 = kk_std_num_decimal_cmp(_x_x656, _x_x657, _ctx); /*order*/
  bool _match_x455;
  kk_integer_t _brw_x456;
  if (kk_std_core_types__is_Lt(x_0_10126, _ctx)) {
    _brw_x456 = kk_integer_from_small(-1); /*int*/
    goto _match_x658;
  }
  if (kk_std_core_types__is_Eq(x_0_10126, _ctx)) {
    _brw_x456 = kk_integer_from_small(0); /*int*/
    goto _match_x658;
  }
  {
    _brw_x456 = kk_integer_from_small(1); /*int*/
  }
  _match_x658: ;
  bool _brw_x457 = kk_integer_neq_borrow(_brw_x456,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x456, _ctx);
  _match_x455 = _brw_x457; /*bool*/
  if (_match_x455) {
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
  kk_std_core_types__order x_0_10120;
  kk_std_num_decimal__decimal _x_x659 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
  kk_std_num_decimal__decimal _x_x660 = kk_std_num_decimal__decimal_dup(y, _ctx); /*std/num/decimal/decimal*/
  x_0_10120 = kk_std_num_decimal_cmp(_x_x659, _x_x660, _ctx); /*order*/
  bool _match_x452;
  kk_integer_t _brw_x453;
  if (kk_std_core_types__is_Lt(x_0_10120, _ctx)) {
    _brw_x453 = kk_integer_from_small(-1); /*int*/
    goto _match_x661;
  }
  if (kk_std_core_types__is_Eq(x_0_10120, _ctx)) {
    _brw_x453 = kk_integer_from_small(0); /*int*/
    goto _match_x661;
  }
  {
    _brw_x453 = kk_integer_from_small(1); /*int*/
  }
  _match_x661: ;
  bool _brw_x454 = kk_integer_neq_borrow(_brw_x453,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x453, _ctx);
  _match_x452 = _brw_x454; /*bool*/
  if (_match_x452) {
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
  kk_integer_t x;
  bool _match_x449;
  kk_integer_t _brw_x450;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x25 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x25, _ctx);
    kk_integer_dup(_uniq_exp_1807, _ctx);
    _brw_x450 = _uniq_exp_1807; /*int*/
  }
  else {
    _brw_x450 = kk_integer_from_small(0); /*int*/
  }
  bool _brw_x451 = kk_integer_is_zero_borrow(_brw_x450); /*bool*/;
  kk_integer_drop(_brw_x450, _ctx);
  _match_x449 = _brw_x451; /*bool*/
  if (_match_x449) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x_x662;
    kk_integer_t _x_x663;
    if (kk_std_core_types__is_Optional(exp, _ctx)) {
      kk_box_t _box_x26 = exp._cons._Optional.value;
      kk_integer_t _uniq_exp_1807_0 = kk_integer_unbox(_box_x26, _ctx);
      kk_integer_dup(_uniq_exp_1807_0, _ctx);
      _x_x663 = _uniq_exp_1807_0; /*int*/
    }
    else {
      _x_x663 = kk_integer_from_small(0); /*int*/
    }
    _x_x662 = kk_integer_div(_x_x663,(kk_integer_from_small(7)),kk_context()); /*int*/
    x = kk_integer_mul((kk_integer_from_small(7)),_x_x662,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x_x664;
  if (kk_std_core_types__is_Optional(exp, _ctx)) {
    kk_box_t _box_x27 = exp._cons._Optional.value;
    kk_integer_t _uniq_exp_1807_1 = kk_integer_unbox(_box_x27, _ctx);
    kk_integer_dup(_uniq_exp_1807_1, _ctx);
    _x_x664 = _uniq_exp_1807_1; /*int*/
  }
  else {
    _x_x664 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x665 = kk_integer_dup(x, _ctx); /*int*/
  diff = kk_integer_sub(_x_x664,_x_x665,kk_context()); /*int*/
  bool _match_x448 = kk_integer_is_zero_borrow(diff); /*bool*/;
  if (_match_x448) {
    kk_integer_drop(x, _ctx);
    kk_integer_drop(diff, _ctx);
    kk_integer_t _x_x666;
    if (kk_std_core_types__is_Optional(exp, _ctx)) {
      kk_box_t _box_x28 = exp._cons._Optional.value;
      kk_integer_t _uniq_exp_1807_2 = kk_integer_unbox(_box_x28, _ctx);
      kk_integer_dup(_uniq_exp_1807_2, _ctx);
      kk_std_core_types__optional_drop(exp, _ctx);
      _x_x666 = _uniq_exp_1807_2; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(exp, _ctx);
      _x_x666 = kk_integer_from_small(0); /*int*/
    }
    return kk_std_num_decimal__new_Decimal(i, _x_x666, _ctx);
  }
  {
    kk_std_core_types__optional_drop(exp, _ctx);
    kk_integer_t _x_x667;
    kk_integer_t _x_x668 = kk_integer_abs(diff,kk_context()); /*int*/
    _x_x667 = kk_std_core_int_mul_exp10(i, _x_x668, _ctx); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x667, x, _ctx);
  }
}
 
// Round the decimal-point number `x` to
// to a specified number of digits behind the dot `prec` (=`0`) with an optional
// rounding mode `rnd` (=`Half-even`). The precision can be negative.
// `decimal(1,485).round-to-prec(2).show == "1.48"`
// `decimal(112,49).round-to-prec(-1).show == "110"`


// lift anonymous function
struct kk_std_num_decimal_round_to_prec_fun680__t {
  struct kk_function_s _base;
  kk_integer_t p;
  kk_integer_t q;
  kk_integer_t r;
};
static kk_integer_t kk_std_num_decimal_round_to_prec_fun680(kk_function_t _fself, bool keep_on_eq, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_round_to_prec_fun680(kk_integer_t p, kk_integer_t q, kk_integer_t r, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun680__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_round_to_prec_fun680__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_round_to_prec_fun680, kk_context());
  _self->p = p;
  _self->q = q;
  _self->r = r;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_num_decimal_round_to_prec_fun680(kk_function_t _fself, bool keep_on_eq, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun680__t* _self = kk_function_as(struct kk_std_num_decimal_round_to_prec_fun680__t*, _fself, _ctx);
  kk_integer_t p = _self->p; /* int */
  kk_integer_t q = _self->q; /* int */
  kk_integer_t r = _self->r; /* int */
  kk_drop_match(_self, {kk_integer_dup(p, _ctx);kk_integer_dup(q, _ctx);kk_integer_dup(r, _ctx);}, {}, _ctx)
  kk_integer_t half;
  kk_integer_t _x_x681 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), p, _ctx); /*int*/
  half = kk_integer_div(_x_x681,(kk_integer_from_small(2)),kk_context()); /*int*/
  bool _match_x442 = kk_integer_eq_borrow(r,half,kk_context()); /*bool*/;
  if (_match_x442) {
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
    bool _match_x443;
    bool _brw_x444 = kk_integer_gt_borrow(r,half,kk_context()); /*bool*/;
    kk_integer_drop(r, _ctx);
    kk_integer_drop(half, _ctx);
    _match_x443 = _brw_x444; /*bool*/
    if (_match_x443) {
      return kk_integer_add_small_const(q, 1, _ctx);
    }
    {
      return q;
    }
  }
}


// lift anonymous function
struct kk_std_num_decimal_round_to_prec_fun695__t {
  struct kk_function_s _base;
  kk_integer_t cq_0;
  kk_integer_t p;
};
static kk_integer_t kk_std_num_decimal_round_to_prec_fun695(kk_function_t _fself, bool keep_on_eq_0, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_round_to_prec_fun695(kk_integer_t cq_0, kk_integer_t p, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun695__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_round_to_prec_fun695__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_round_to_prec_fun695, kk_context());
  _self->cq_0 = cq_0;
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_num_decimal_round_to_prec_fun695(kk_function_t _fself, bool keep_on_eq_0, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun695__t* _self = kk_function_as(struct kk_std_num_decimal_round_to_prec_fun695__t*, _fself, _ctx);
  kk_integer_t cq_0 = _self->cq_0; /* int */
  kk_integer_t p = _self->p; /* int */
  kk_drop_match(_self, {kk_integer_dup(cq_0, _ctx);kk_integer_dup(p, _ctx);}, {}, _ctx)
  kk_integer_t half_0;
  kk_integer_t _x_x696 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), p, _ctx); /*int*/
  half_0 = kk_integer_div(_x_x696,(kk_integer_from_small(2)),kk_context()); /*int*/
  bool _match_x431 = kk_integer_eq_borrow((kk_integer_from_small(0)),half_0,kk_context()); /*bool*/;
  if (_match_x431) {
    kk_integer_drop(half_0, _ctx);
    if (keep_on_eq_0) {
      return cq_0;
    }
    {
      return kk_integer_add_small_const(cq_0, 1, _ctx);
    }
  }
  {
    bool _match_x432;
    bool _brw_x433 = kk_integer_gt_borrow((kk_integer_from_small(0)),half_0,kk_context()); /*bool*/;
    kk_integer_drop(half_0, _ctx);
    _match_x432 = _brw_x433; /*bool*/
    if (_match_x432) {
      return kk_integer_add_small_const(cq_0, 1, _ctx);
    }
    {
      return cq_0;
    }
  }
}


// lift anonymous function
struct kk_std_num_decimal_round_to_prec_fun716__t {
  struct kk_function_s _base;
  kk_integer_t p;
  kk_integer_t q_0;
  kk_integer_t r_0;
};
static kk_integer_t kk_std_num_decimal_round_to_prec_fun716(kk_function_t _fself, bool keep_on_eq_1, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_round_to_prec_fun716(kk_integer_t p, kk_integer_t q_0, kk_integer_t r_0, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun716__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_round_to_prec_fun716__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_round_to_prec_fun716, kk_context());
  _self->p = p;
  _self->q_0 = q_0;
  _self->r_0 = r_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_num_decimal_round_to_prec_fun716(kk_function_t _fself, bool keep_on_eq_1, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun716__t* _self = kk_function_as(struct kk_std_num_decimal_round_to_prec_fun716__t*, _fself, _ctx);
  kk_integer_t p = _self->p; /* int */
  kk_integer_t q_0 = _self->q_0; /* int */
  kk_integer_t r_0 = _self->r_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(p, _ctx);kk_integer_dup(q_0, _ctx);kk_integer_dup(r_0, _ctx);}, {}, _ctx)
  kk_integer_t half_1;
  kk_integer_t _x_x717 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), p, _ctx); /*int*/
  half_1 = kk_integer_div(_x_x717,(kk_integer_from_small(2)),kk_context()); /*int*/
  bool _match_x421 = kk_integer_eq_borrow(r_0,half_1,kk_context()); /*bool*/;
  if (_match_x421) {
    kk_integer_drop(r_0, _ctx);
    kk_integer_drop(half_1, _ctx);
    if (keep_on_eq_1) {
      return q_0;
    }
    {
      return kk_integer_add_small_const(q_0, 1, _ctx);
    }
  }
  {
    bool _match_x422;
    bool _brw_x423 = kk_integer_gt_borrow(r_0,half_1,kk_context()); /*bool*/;
    kk_integer_drop(r_0, _ctx);
    kk_integer_drop(half_1, _ctx);
    _match_x422 = _brw_x423; /*bool*/
    if (_match_x422) {
      return kk_integer_add_small_const(q_0, 1, _ctx);
    }
    {
      return q_0;
    }
  }
}


// lift anonymous function
struct kk_std_num_decimal_round_to_prec_fun731__t {
  struct kk_function_s _base;
  kk_integer_t cq;
  kk_integer_t cr;
  kk_integer_t p;
};
static kk_integer_t kk_std_num_decimal_round_to_prec_fun731(kk_function_t _fself, bool keep_on_eq_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_round_to_prec_fun731(kk_integer_t cq, kk_integer_t cr, kk_integer_t p, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun731__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_round_to_prec_fun731__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_round_to_prec_fun731, kk_context());
  _self->cq = cq;
  _self->cr = cr;
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_std_num_decimal_round_to_prec_fun731(kk_function_t _fself, bool keep_on_eq_0_0, kk_context_t* _ctx) {
  struct kk_std_num_decimal_round_to_prec_fun731__t* _self = kk_function_as(struct kk_std_num_decimal_round_to_prec_fun731__t*, _fself, _ctx);
  kk_integer_t cq = _self->cq; /* int */
  kk_integer_t cr = _self->cr; /* int */
  kk_integer_t p = _self->p; /* int */
  kk_drop_match(_self, {kk_integer_dup(cq, _ctx);kk_integer_dup(cr, _ctx);kk_integer_dup(p, _ctx);}, {}, _ctx)
  kk_integer_t half_0_0;
  kk_integer_t _x_x732 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), p, _ctx); /*int*/
  half_0_0 = kk_integer_div(_x_x732,(kk_integer_from_small(2)),kk_context()); /*int*/
  bool _match_x410 = kk_integer_eq_borrow(cr,half_0_0,kk_context()); /*bool*/;
  if (_match_x410) {
    kk_integer_drop(half_0_0, _ctx);
    kk_integer_drop(cr, _ctx);
    if (keep_on_eq_0_0) {
      return cq;
    }
    {
      return kk_integer_add_small_const(cq, 1, _ctx);
    }
  }
  {
    bool _match_x411;
    bool _brw_x412 = kk_integer_gt_borrow(cr,half_0_0,kk_context()); /*bool*/;
    kk_integer_drop(cr, _ctx);
    kk_integer_drop(half_0_0, _ctx);
    _match_x411 = _brw_x412; /*bool*/
    if (_match_x411) {
      return kk_integer_add_small_const(cq, 1, _ctx);
    }
    {
      return cq;
    }
  }
}

kk_std_num_decimal__decimal kk_std_num_decimal_round_to_prec(kk_std_num_decimal__decimal x, kk_std_core_types__optional prec, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, prec : ? int, rnd : ? round) -> decimal */ 
  bool _match_x400;
  kk_integer_t _brw_x446;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x446 = _x; /*int*/
  }
  kk_integer_t _brw_x445;
  kk_integer_t _x_x676;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x29 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_1884 = kk_integer_unbox(_box_x29, _ctx);
    kk_integer_dup(_uniq_prec_1884, _ctx);
    _x_x676 = _uniq_prec_1884; /*int*/
  }
  else {
    _x_x676 = kk_integer_from_small(0); /*int*/
  }
  _brw_x445 = kk_integer_neg(_x_x676,kk_context()); /*int*/
  bool _brw_x447 = kk_integer_gte_borrow(_brw_x446,_brw_x445,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x446, _ctx);
  kk_integer_drop(_brw_x445, _ctx);
  _match_x400 = _brw_x447; /*bool*/
  if (_match_x400) {
    kk_std_core_types__optional_drop(rnd, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    return x;
  }
  {
    kk_std_num_decimal__decimal cx = kk_std_num_decimal_reduce(x, _ctx); /*std/num/decimal/decimal*/;
    kk_integer_t x_0_10142;
    kk_integer_t _x_x677;
    {
      kk_integer_t _x_0 = cx.exp;
      kk_integer_dup(_x_0, _ctx);
      _x_x677 = _x_0; /*int*/
    }
    x_0_10142 = kk_integer_neg(_x_x677,kk_context()); /*int*/
    kk_integer_t p;
    kk_integer_t _x_x678;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x30 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_1884_0 = kk_integer_unbox(_box_x30, _ctx);
      kk_integer_dup(_uniq_prec_1884_0, _ctx);
      _x_x678 = _uniq_prec_1884_0; /*int*/
    }
    else {
      _x_x678 = kk_integer_from_small(0); /*int*/
    }
    p = kk_integer_sub(x_0_10142,_x_x678,kk_context()); /*int*/
    bool b_10145 = kk_integer_gt_borrow(p,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (b_10145) {
      bool _match_x401 = kk_integer_lte_borrow(p,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x401) {
        kk_integer_t cq_0;
        {
          kk_integer_t _x_1 = cx.num;
          kk_integer_dup(_x_1, _ctx);
          kk_std_num_decimal__decimal_drop(cx, _ctx);
          cq_0 = _x_1; /*int*/
        }
        bool b_10006 = kk_integer_lt_borrow((kk_integer_from_small(0)),(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (b_10006) {
          kk_integer_t y_0_10012;
          kk_integer_t _x_x679 = kk_integer_dup(p, _ctx); /*int*/
          y_0_10012 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), _x_x679, _ctx); /*int*/
          kk_integer_t q = kk_integer_add_small_const(cq_0, -1, _ctx); /*int*/;
          kk_integer_t r = kk_integer_add_small_const(y_0_10012, 0, _ctx); /*int*/;
          kk_function_t round_half;
          kk_integer_dup(q, _ctx);
          kk_integer_dup(r, _ctx);
          round_half = kk_std_num_decimal_new_round_to_prec_fun680(p, q, r, _ctx); /*(keep-on-eq : bool) -> int*/
          kk_integer_t q1;
          bool _match_x438;
          bool _brw_x441 = kk_integer_is_zero_borrow(r); /*bool*/;
          kk_integer_drop(r, _ctx);
          _match_x438 = _brw_x441; /*bool*/
          if (_match_x438) {
            kk_function_drop(round_half, _ctx);
            kk_std_core_types__optional_drop(rnd, _ctx);
            q1 = q; /*int*/
          }
          else {
            if (kk_std_core_types__is_Optional(rnd, _ctx)) {
              kk_box_t _box_x31 = rnd._cons._Optional.value;
              kk_std_num_decimal__round _uniq_rnd_1888 = kk_std_num_decimal__round_unbox(_box_x31, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(rnd, _ctx);
              if (kk_std_num_decimal__is_Half_even(_uniq_rnd_1888, _ctx)) {
                bool b_10014 = kk_integer_is_odd(q,kk_context()); /*bool*/;
                bool _x_x683;
                if (b_10014) {
                  _x_x683 = false; /*bool*/
                }
                else {
                  _x_x683 = true; /*bool*/
                }
                q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x683, _ctx), _ctx); /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Half_floor(_uniq_rnd_1888, _ctx)) {
                kk_integer_drop(q, _ctx);
                q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, true, _ctx), _ctx); /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Half_ceiling(_uniq_rnd_1888, _ctx)) {
                kk_integer_drop(q, _ctx);
                q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, false, _ctx), _ctx); /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Half_truncate(_uniq_rnd_1888, _ctx)) {
                bool _x_x684;
                bool _brw_x440 = kk_integer_gt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(q, _ctx);
                _x_x684 = _brw_x440; /*bool*/
                q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x684, _ctx), _ctx); /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Half_away_from_zero(_uniq_rnd_1888, _ctx)) {
                bool _x_x685;
                bool _brw_x439 = kk_integer_lt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(q, _ctx);
                _x_x685 = _brw_x439; /*bool*/
                q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x685, _ctx), _ctx); /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Floor(_uniq_rnd_1888, _ctx)) {
                kk_function_drop(round_half, _ctx);
                q1 = q; /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Ceiling(_uniq_rnd_1888, _ctx)) {
                kk_function_drop(round_half, _ctx);
                q1 = kk_integer_add_small_const(q, 1, _ctx); /*int*/
                goto _match_x682;
              }
              if (kk_std_num_decimal__is_Truncate(_uniq_rnd_1888, _ctx)) {
                kk_function_drop(round_half, _ctx);
                bool b_0_10159 = kk_integer_lt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_0_10159) {
                  q1 = kk_integer_add_small_const(q, 1, _ctx); /*int*/
                  goto _match_x682;
                }
                {
                  q1 = q; /*int*/
                  goto _match_x682;
                }
              }
              {
                kk_function_drop(round_half, _ctx);
                bool b_1_10162 = kk_integer_gt_borrow(q,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_1_10162) {
                  q1 = kk_integer_add_small_const(q, 1, _ctx); /*int*/
                }
                else {
                  q1 = q; /*int*/
                }
              }
              _match_x682: ;
            }
            else {
              kk_std_core_types__optional_drop(rnd, _ctx);
              bool b_10014_0 = kk_integer_is_odd(q,kk_context()); /*bool*/;
              bool _x_x686;
              if (b_10014_0) {
                _x_x686 = false; /*bool*/
              }
              else {
                _x_x686 = true; /*bool*/
              }
              q1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half, (round_half, _x_x686, _ctx), _ctx); /*int*/
            }
          }
          kk_integer_t _b_x33_34;
          kk_integer_t _x_x687;
          if (kk_std_core_types__is_Optional(prec, _ctx)) {
            kk_box_t _box_x32 = prec._cons._Optional.value;
            kk_integer_t _uniq_prec_1884_1 = kk_integer_unbox(_box_x32, _ctx);
            kk_integer_dup(_uniq_prec_1884_1, _ctx);
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x687 = _uniq_prec_1884_1; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x687 = kk_integer_from_small(0); /*int*/
          }
          _b_x33_34 = kk_integer_neg(_x_x687,kk_context()); /*int*/
          kk_std_core_types__optional exp_0_10167 = kk_std_core_types__new_Optional(kk_integer_box(_b_x33_34, _ctx), _ctx); /*? int*/;
          kk_integer_t x_2;
          bool _match_x435;
          kk_integer_t _brw_x436;
          if (kk_std_core_types__is_Optional(exp_0_10167, _ctx)) {
            kk_box_t _box_x35 = exp_0_10167._cons._Optional.value;
            kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x35, _ctx);
            kk_integer_dup(_uniq_exp_619, _ctx);
            _brw_x436 = _uniq_exp_619; /*int*/
          }
          else {
            _brw_x436 = kk_integer_from_small(0); /*int*/
          }
          bool _brw_x437 = kk_integer_is_zero_borrow(_brw_x436); /*bool*/;
          kk_integer_drop(_brw_x436, _ctx);
          _match_x435 = _brw_x437; /*bool*/
          if (_match_x435) {
            x_2 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_integer_t _x_x688;
            kk_integer_t _x_x689;
            if (kk_std_core_types__is_Optional(exp_0_10167, _ctx)) {
              kk_box_t _box_x36 = exp_0_10167._cons._Optional.value;
              kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x36, _ctx);
              kk_integer_dup(_uniq_exp_619_0, _ctx);
              _x_x689 = _uniq_exp_619_0; /*int*/
            }
            else {
              _x_x689 = kk_integer_from_small(0); /*int*/
            }
            _x_x688 = kk_integer_div(_x_x689,(kk_integer_from_small(7)),kk_context()); /*int*/
            x_2 = kk_integer_mul((kk_integer_from_small(7)),_x_x688,kk_context()); /*int*/
          }
          kk_integer_t diff;
          kk_integer_t _x_x690;
          if (kk_std_core_types__is_Optional(exp_0_10167, _ctx)) {
            kk_box_t _box_x37 = exp_0_10167._cons._Optional.value;
            kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x37, _ctx);
            kk_integer_dup(_uniq_exp_619_1, _ctx);
            _x_x690 = _uniq_exp_619_1; /*int*/
          }
          else {
            _x_x690 = kk_integer_from_small(0); /*int*/
          }
          kk_integer_t _x_x691 = kk_integer_dup(x_2, _ctx); /*int*/
          diff = kk_integer_sub(_x_x690,_x_x691,kk_context()); /*int*/
          bool _match_x434 = kk_integer_is_zero_borrow(diff); /*bool*/;
          if (_match_x434) {
            kk_integer_drop(x_2, _ctx);
            kk_integer_drop(diff, _ctx);
            kk_integer_t _x_x692;
            if (kk_std_core_types__is_Optional(exp_0_10167, _ctx)) {
              kk_box_t _box_x38 = exp_0_10167._cons._Optional.value;
              kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x38, _ctx);
              kk_integer_dup(_uniq_exp_619_2, _ctx);
              kk_std_core_types__optional_drop(exp_0_10167, _ctx);
              _x_x692 = _uniq_exp_619_2; /*int*/
            }
            else {
              kk_std_core_types__optional_drop(exp_0_10167, _ctx);
              _x_x692 = kk_integer_from_small(0); /*int*/
            }
            return kk_std_num_decimal__new_Decimal(q1, _x_x692, _ctx);
          }
          {
            kk_std_core_types__optional_drop(exp_0_10167, _ctx);
            kk_integer_t _x_x693;
            kk_integer_t _x_x694 = kk_integer_abs(diff,kk_context()); /*int*/
            _x_x693 = kk_std_core_int_mul_exp10(q1, _x_x694, _ctx); /*int*/
            return kk_std_num_decimal__new_Decimal(_x_x693, x_2, _ctx);
          }
        }
        {
          kk_function_t round_half_0;
          kk_integer_dup(cq_0, _ctx);
          round_half_0 = kk_std_num_decimal_new_round_to_prec_fun695(cq_0, p, _ctx); /*(keep-on-eq@0 : bool) -> int*/
          kk_integer_t q1_0;
          bool _match_x428 = kk_integer_is_zero_borrow((kk_integer_from_small(0))); /*bool*/;
          if (_match_x428) {
            kk_function_drop(round_half_0, _ctx);
            kk_std_core_types__optional_drop(rnd, _ctx);
            q1_0 = cq_0; /*int*/
          }
          else {
            if (kk_std_core_types__is_Optional(rnd, _ctx)) {
              kk_box_t _box_x39 = rnd._cons._Optional.value;
              kk_std_num_decimal__round _uniq_rnd_1888_0 = kk_std_num_decimal__round_unbox(_box_x39, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(rnd, _ctx);
              if (kk_std_num_decimal__is_Half_even(_uniq_rnd_1888_0, _ctx)) {
                bool b_10014_1 = kk_integer_is_odd(cq_0,kk_context()); /*bool*/;
                bool _x_x698;
                if (b_10014_1) {
                  _x_x698 = false; /*bool*/
                }
                else {
                  _x_x698 = true; /*bool*/
                }
                q1_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0, (round_half_0, _x_x698, _ctx), _ctx); /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Half_floor(_uniq_rnd_1888_0, _ctx)) {
                kk_integer_drop(cq_0, _ctx);
                q1_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0, (round_half_0, true, _ctx), _ctx); /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Half_ceiling(_uniq_rnd_1888_0, _ctx)) {
                kk_integer_drop(cq_0, _ctx);
                q1_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0, (round_half_0, false, _ctx), _ctx); /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Half_truncate(_uniq_rnd_1888_0, _ctx)) {
                bool _x_x699;
                bool _brw_x430 = kk_integer_gt_borrow(cq_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(cq_0, _ctx);
                _x_x699 = _brw_x430; /*bool*/
                q1_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0, (round_half_0, _x_x699, _ctx), _ctx); /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Half_away_from_zero(_uniq_rnd_1888_0, _ctx)) {
                bool _x_x700;
                bool _brw_x429 = kk_integer_lt_borrow(cq_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(cq_0, _ctx);
                _x_x700 = _brw_x429; /*bool*/
                q1_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0, (round_half_0, _x_x700, _ctx), _ctx); /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Floor(_uniq_rnd_1888_0, _ctx)) {
                kk_function_drop(round_half_0, _ctx);
                q1_0 = cq_0; /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Ceiling(_uniq_rnd_1888_0, _ctx)) {
                kk_function_drop(round_half_0, _ctx);
                q1_0 = kk_integer_add_small_const(cq_0, 1, _ctx); /*int*/
                goto _match_x697;
              }
              if (kk_std_num_decimal__is_Truncate(_uniq_rnd_1888_0, _ctx)) {
                kk_function_drop(round_half_0, _ctx);
                bool b_0_10159_0 = kk_integer_lt_borrow(cq_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_0_10159_0) {
                  q1_0 = kk_integer_add_small_const(cq_0, 1, _ctx); /*int*/
                  goto _match_x697;
                }
                {
                  q1_0 = cq_0; /*int*/
                  goto _match_x697;
                }
              }
              {
                kk_function_drop(round_half_0, _ctx);
                bool b_1_10162_0 = kk_integer_gt_borrow(cq_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_1_10162_0) {
                  q1_0 = kk_integer_add_small_const(cq_0, 1, _ctx); /*int*/
                }
                else {
                  q1_0 = cq_0; /*int*/
                }
              }
              _match_x697: ;
            }
            else {
              kk_std_core_types__optional_drop(rnd, _ctx);
              bool b_10014_0_0 = kk_integer_is_odd(cq_0,kk_context()); /*bool*/;
              bool _x_x701;
              if (b_10014_0_0) {
                _x_x701 = false; /*bool*/
              }
              else {
                _x_x701 = true; /*bool*/
              }
              q1_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0, (round_half_0, _x_x701, _ctx), _ctx); /*int*/
            }
          }
          kk_integer_t _b_x41_42;
          kk_integer_t _x_x702;
          if (kk_std_core_types__is_Optional(prec, _ctx)) {
            kk_box_t _box_x40 = prec._cons._Optional.value;
            kk_integer_t _uniq_prec_1884_0_0 = kk_integer_unbox(_box_x40, _ctx);
            kk_integer_dup(_uniq_prec_1884_0_0, _ctx);
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x702 = _uniq_prec_1884_0_0; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x702 = kk_integer_from_small(0); /*int*/
          }
          _b_x41_42 = kk_integer_neg(_x_x702,kk_context()); /*int*/
          kk_std_core_types__optional exp_0_10167_0 = kk_std_core_types__new_Optional(kk_integer_box(_b_x41_42, _ctx), _ctx); /*? int*/;
          kk_integer_t x_2_0;
          bool _match_x425;
          kk_integer_t _brw_x426;
          if (kk_std_core_types__is_Optional(exp_0_10167_0, _ctx)) {
            kk_box_t _box_x43 = exp_0_10167_0._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0_0 = kk_integer_unbox(_box_x43, _ctx);
            kk_integer_dup(_uniq_exp_619_0_0, _ctx);
            _brw_x426 = _uniq_exp_619_0_0; /*int*/
          }
          else {
            _brw_x426 = kk_integer_from_small(0); /*int*/
          }
          bool _brw_x427 = kk_integer_is_zero_borrow(_brw_x426); /*bool*/;
          kk_integer_drop(_brw_x426, _ctx);
          _match_x425 = _brw_x427; /*bool*/
          if (_match_x425) {
            x_2_0 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_integer_t _x_x703;
            kk_integer_t _x_x704;
            if (kk_std_core_types__is_Optional(exp_0_10167_0, _ctx)) {
              kk_box_t _box_x44 = exp_0_10167_0._cons._Optional.value;
              kk_integer_t _uniq_exp_619_0_1 = kk_integer_unbox(_box_x44, _ctx);
              kk_integer_dup(_uniq_exp_619_0_1, _ctx);
              _x_x704 = _uniq_exp_619_0_1; /*int*/
            }
            else {
              _x_x704 = kk_integer_from_small(0); /*int*/
            }
            _x_x703 = kk_integer_div(_x_x704,(kk_integer_from_small(7)),kk_context()); /*int*/
            x_2_0 = kk_integer_mul((kk_integer_from_small(7)),_x_x703,kk_context()); /*int*/
          }
          kk_integer_t diff_0;
          kk_integer_t _x_x705;
          if (kk_std_core_types__is_Optional(exp_0_10167_0, _ctx)) {
            kk_box_t _box_x45 = exp_0_10167_0._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0_2 = kk_integer_unbox(_box_x45, _ctx);
            kk_integer_dup(_uniq_exp_619_0_2, _ctx);
            _x_x705 = _uniq_exp_619_0_2; /*int*/
          }
          else {
            _x_x705 = kk_integer_from_small(0); /*int*/
          }
          kk_integer_t _x_x706 = kk_integer_dup(x_2_0, _ctx); /*int*/
          diff_0 = kk_integer_sub(_x_x705,_x_x706,kk_context()); /*int*/
          bool _match_x424 = kk_integer_is_zero_borrow(diff_0); /*bool*/;
          if (_match_x424) {
            kk_integer_drop(x_2_0, _ctx);
            kk_integer_drop(diff_0, _ctx);
            kk_integer_t _x_x707;
            if (kk_std_core_types__is_Optional(exp_0_10167_0, _ctx)) {
              kk_box_t _box_x46 = exp_0_10167_0._cons._Optional.value;
              kk_integer_t _uniq_exp_619_0_3 = kk_integer_unbox(_box_x46, _ctx);
              kk_integer_dup(_uniq_exp_619_0_3, _ctx);
              kk_std_core_types__optional_drop(exp_0_10167_0, _ctx);
              _x_x707 = _uniq_exp_619_0_3; /*int*/
            }
            else {
              kk_std_core_types__optional_drop(exp_0_10167_0, _ctx);
              _x_x707 = kk_integer_from_small(0); /*int*/
            }
            return kk_std_num_decimal__new_Decimal(q1_0, _x_x707, _ctx);
          }
          {
            kk_std_core_types__optional_drop(exp_0_10167_0, _ctx);
            kk_integer_t _x_x708;
            kk_integer_t _x_x709 = kk_integer_abs(diff_0,kk_context()); /*int*/
            _x_x708 = kk_std_core_int_mul_exp10(q1_0, _x_x709, _ctx); /*int*/
            return kk_std_num_decimal__new_Decimal(_x_x708, x_2_0, _ctx);
          }
        }
      }
      {
        kk_integer_t cq;
        kk_integer_t _x_x710;
        {
          kk_integer_t _x_1_0 = cx.num;
          kk_integer_dup(_x_1_0, _ctx);
          _x_x710 = _x_1_0; /*int*/
        }
        kk_integer_t _x_x711 = kk_integer_dup(p, _ctx); /*int*/
        cq = kk_std_core_int_cdiv_exp10(_x_x710, _x_x711, _ctx); /*int*/
        kk_integer_t y_10005;
        kk_integer_t _x_x712 = kk_integer_dup(cq, _ctx); /*int*/
        kk_integer_t _x_x713 = kk_integer_dup(p, _ctx); /*int*/
        y_10005 = kk_std_core_int_mul_exp10(_x_x712, _x_x713, _ctx); /*int*/
        kk_integer_t cr;
        kk_integer_t _x_x714;
        {
          kk_integer_t _x_1_1 = cx.num;
          kk_integer_dup(_x_1_1, _ctx);
          kk_std_num_decimal__decimal_drop(cx, _ctx);
          _x_x714 = _x_1_1; /*int*/
        }
        cr = kk_integer_sub(_x_x714,y_10005,kk_context()); /*int*/
        bool b_10006_0 = kk_integer_lt_borrow(cr,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (b_10006_0) {
          kk_integer_t y_0_10012_0;
          kk_integer_t _x_x715 = kk_integer_dup(p, _ctx); /*int*/
          y_0_10012_0 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), _x_x715, _ctx); /*int*/
          kk_integer_t q_0 = kk_integer_add_small_const(cq, -1, _ctx); /*int*/;
          kk_integer_t r_0 = kk_integer_add(cr,y_0_10012_0,kk_context()); /*int*/;
          kk_function_t round_half_1;
          kk_integer_dup(q_0, _ctx);
          kk_integer_dup(r_0, _ctx);
          round_half_1 = kk_std_num_decimal_new_round_to_prec_fun716(p, q_0, r_0, _ctx); /*(keep-on-eq : bool) -> int*/
          kk_integer_t q1_1;
          bool _match_x417;
          bool _brw_x420 = kk_integer_is_zero_borrow(r_0); /*bool*/;
          kk_integer_drop(r_0, _ctx);
          _match_x417 = _brw_x420; /*bool*/
          if (_match_x417) {
            kk_function_drop(round_half_1, _ctx);
            kk_std_core_types__optional_drop(rnd, _ctx);
            q1_1 = q_0; /*int*/
          }
          else {
            if (kk_std_core_types__is_Optional(rnd, _ctx)) {
              kk_box_t _box_x47 = rnd._cons._Optional.value;
              kk_std_num_decimal__round _uniq_rnd_1888_1 = kk_std_num_decimal__round_unbox(_box_x47, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(rnd, _ctx);
              if (kk_std_num_decimal__is_Half_even(_uniq_rnd_1888_1, _ctx)) {
                bool b_10014_2 = kk_integer_is_odd(q_0,kk_context()); /*bool*/;
                bool _x_x719;
                if (b_10014_2) {
                  _x_x719 = false; /*bool*/
                }
                else {
                  _x_x719 = true; /*bool*/
                }
                q1_1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_1, (round_half_1, _x_x719, _ctx), _ctx); /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Half_floor(_uniq_rnd_1888_1, _ctx)) {
                kk_integer_drop(q_0, _ctx);
                q1_1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_1, (round_half_1, true, _ctx), _ctx); /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Half_ceiling(_uniq_rnd_1888_1, _ctx)) {
                kk_integer_drop(q_0, _ctx);
                q1_1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_1, (round_half_1, false, _ctx), _ctx); /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Half_truncate(_uniq_rnd_1888_1, _ctx)) {
                bool _x_x720;
                bool _brw_x419 = kk_integer_gt_borrow(q_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(q_0, _ctx);
                _x_x720 = _brw_x419; /*bool*/
                q1_1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_1, (round_half_1, _x_x720, _ctx), _ctx); /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Half_away_from_zero(_uniq_rnd_1888_1, _ctx)) {
                bool _x_x721;
                bool _brw_x418 = kk_integer_lt_borrow(q_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(q_0, _ctx);
                _x_x721 = _brw_x418; /*bool*/
                q1_1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_1, (round_half_1, _x_x721, _ctx), _ctx); /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Floor(_uniq_rnd_1888_1, _ctx)) {
                kk_function_drop(round_half_1, _ctx);
                q1_1 = q_0; /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Ceiling(_uniq_rnd_1888_1, _ctx)) {
                kk_function_drop(round_half_1, _ctx);
                q1_1 = kk_integer_add_small_const(q_0, 1, _ctx); /*int*/
                goto _match_x718;
              }
              if (kk_std_num_decimal__is_Truncate(_uniq_rnd_1888_1, _ctx)) {
                kk_function_drop(round_half_1, _ctx);
                bool b_0_10159_1 = kk_integer_lt_borrow(q_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_0_10159_1) {
                  q1_1 = kk_integer_add_small_const(q_0, 1, _ctx); /*int*/
                  goto _match_x718;
                }
                {
                  q1_1 = q_0; /*int*/
                  goto _match_x718;
                }
              }
              {
                kk_function_drop(round_half_1, _ctx);
                bool b_1_10162_1 = kk_integer_gt_borrow(q_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_1_10162_1) {
                  q1_1 = kk_integer_add_small_const(q_0, 1, _ctx); /*int*/
                }
                else {
                  q1_1 = q_0; /*int*/
                }
              }
              _match_x718: ;
            }
            else {
              kk_std_core_types__optional_drop(rnd, _ctx);
              bool b_10014_0_1 = kk_integer_is_odd(q_0,kk_context()); /*bool*/;
              bool _x_x722;
              if (b_10014_0_1) {
                _x_x722 = false; /*bool*/
              }
              else {
                _x_x722 = true; /*bool*/
              }
              q1_1 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_1, (round_half_1, _x_x722, _ctx), _ctx); /*int*/
            }
          }
          kk_integer_t _b_x49_50;
          kk_integer_t _x_x723;
          if (kk_std_core_types__is_Optional(prec, _ctx)) {
            kk_box_t _box_x48 = prec._cons._Optional.value;
            kk_integer_t _uniq_prec_1884_2 = kk_integer_unbox(_box_x48, _ctx);
            kk_integer_dup(_uniq_prec_1884_2, _ctx);
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x723 = _uniq_prec_1884_2; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x723 = kk_integer_from_small(0); /*int*/
          }
          _b_x49_50 = kk_integer_neg(_x_x723,kk_context()); /*int*/
          kk_std_core_types__optional exp_0_10167_1 = kk_std_core_types__new_Optional(kk_integer_box(_b_x49_50, _ctx), _ctx); /*? int*/;
          kk_integer_t x_2_1;
          bool _match_x414;
          kk_integer_t _brw_x415;
          if (kk_std_core_types__is_Optional(exp_0_10167_1, _ctx)) {
            kk_box_t _box_x51 = exp_0_10167_1._cons._Optional.value;
            kk_integer_t _uniq_exp_619_3 = kk_integer_unbox(_box_x51, _ctx);
            kk_integer_dup(_uniq_exp_619_3, _ctx);
            _brw_x415 = _uniq_exp_619_3; /*int*/
          }
          else {
            _brw_x415 = kk_integer_from_small(0); /*int*/
          }
          bool _brw_x416 = kk_integer_is_zero_borrow(_brw_x415); /*bool*/;
          kk_integer_drop(_brw_x415, _ctx);
          _match_x414 = _brw_x416; /*bool*/
          if (_match_x414) {
            x_2_1 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_integer_t _x_x724;
            kk_integer_t _x_x725;
            if (kk_std_core_types__is_Optional(exp_0_10167_1, _ctx)) {
              kk_box_t _box_x52 = exp_0_10167_1._cons._Optional.value;
              kk_integer_t _uniq_exp_619_0_4 = kk_integer_unbox(_box_x52, _ctx);
              kk_integer_dup(_uniq_exp_619_0_4, _ctx);
              _x_x725 = _uniq_exp_619_0_4; /*int*/
            }
            else {
              _x_x725 = kk_integer_from_small(0); /*int*/
            }
            _x_x724 = kk_integer_div(_x_x725,(kk_integer_from_small(7)),kk_context()); /*int*/
            x_2_1 = kk_integer_mul((kk_integer_from_small(7)),_x_x724,kk_context()); /*int*/
          }
          kk_integer_t diff_1;
          kk_integer_t _x_x726;
          if (kk_std_core_types__is_Optional(exp_0_10167_1, _ctx)) {
            kk_box_t _box_x53 = exp_0_10167_1._cons._Optional.value;
            kk_integer_t _uniq_exp_619_1_0 = kk_integer_unbox(_box_x53, _ctx);
            kk_integer_dup(_uniq_exp_619_1_0, _ctx);
            _x_x726 = _uniq_exp_619_1_0; /*int*/
          }
          else {
            _x_x726 = kk_integer_from_small(0); /*int*/
          }
          kk_integer_t _x_x727 = kk_integer_dup(x_2_1, _ctx); /*int*/
          diff_1 = kk_integer_sub(_x_x726,_x_x727,kk_context()); /*int*/
          bool _match_x413 = kk_integer_is_zero_borrow(diff_1); /*bool*/;
          if (_match_x413) {
            kk_integer_drop(x_2_1, _ctx);
            kk_integer_drop(diff_1, _ctx);
            kk_integer_t _x_x728;
            if (kk_std_core_types__is_Optional(exp_0_10167_1, _ctx)) {
              kk_box_t _box_x54 = exp_0_10167_1._cons._Optional.value;
              kk_integer_t _uniq_exp_619_2_0 = kk_integer_unbox(_box_x54, _ctx);
              kk_integer_dup(_uniq_exp_619_2_0, _ctx);
              kk_std_core_types__optional_drop(exp_0_10167_1, _ctx);
              _x_x728 = _uniq_exp_619_2_0; /*int*/
            }
            else {
              kk_std_core_types__optional_drop(exp_0_10167_1, _ctx);
              _x_x728 = kk_integer_from_small(0); /*int*/
            }
            return kk_std_num_decimal__new_Decimal(q1_1, _x_x728, _ctx);
          }
          {
            kk_std_core_types__optional_drop(exp_0_10167_1, _ctx);
            kk_integer_t _x_x729;
            kk_integer_t _x_x730 = kk_integer_abs(diff_1,kk_context()); /*int*/
            _x_x729 = kk_std_core_int_mul_exp10(q1_1, _x_x730, _ctx); /*int*/
            return kk_std_num_decimal__new_Decimal(_x_x729, x_2_1, _ctx);
          }
        }
        {
          kk_function_t round_half_0_0;
          kk_integer_dup(cq, _ctx);
          kk_integer_dup(cr, _ctx);
          round_half_0_0 = kk_std_num_decimal_new_round_to_prec_fun731(cq, cr, p, _ctx); /*(keep-on-eq@0 : bool) -> int*/
          kk_integer_t q1_0_0;
          bool _match_x406;
          bool _brw_x409 = kk_integer_is_zero_borrow(cr); /*bool*/;
          kk_integer_drop(cr, _ctx);
          _match_x406 = _brw_x409; /*bool*/
          if (_match_x406) {
            kk_function_drop(round_half_0_0, _ctx);
            kk_std_core_types__optional_drop(rnd, _ctx);
            q1_0_0 = cq; /*int*/
          }
          else {
            if (kk_std_core_types__is_Optional(rnd, _ctx)) {
              kk_box_t _box_x55 = rnd._cons._Optional.value;
              kk_std_num_decimal__round _uniq_rnd_1888_0_0 = kk_std_num_decimal__round_unbox(_box_x55, KK_BORROWED, _ctx);
              kk_std_core_types__optional_drop(rnd, _ctx);
              if (kk_std_num_decimal__is_Half_even(_uniq_rnd_1888_0_0, _ctx)) {
                bool b_10014_1_0 = kk_integer_is_odd(cq,kk_context()); /*bool*/;
                bool _x_x734;
                if (b_10014_1_0) {
                  _x_x734 = false; /*bool*/
                }
                else {
                  _x_x734 = true; /*bool*/
                }
                q1_0_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0_0, (round_half_0_0, _x_x734, _ctx), _ctx); /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Half_floor(_uniq_rnd_1888_0_0, _ctx)) {
                kk_integer_drop(cq, _ctx);
                q1_0_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0_0, (round_half_0_0, true, _ctx), _ctx); /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Half_ceiling(_uniq_rnd_1888_0_0, _ctx)) {
                kk_integer_drop(cq, _ctx);
                q1_0_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0_0, (round_half_0_0, false, _ctx), _ctx); /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Half_truncate(_uniq_rnd_1888_0_0, _ctx)) {
                bool _x_x735;
                bool _brw_x408 = kk_integer_gt_borrow(cq,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(cq, _ctx);
                _x_x735 = _brw_x408; /*bool*/
                q1_0_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0_0, (round_half_0_0, _x_x735, _ctx), _ctx); /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Half_away_from_zero(_uniq_rnd_1888_0_0, _ctx)) {
                bool _x_x736;
                bool _brw_x407 = kk_integer_lt_borrow(cq,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(cq, _ctx);
                _x_x736 = _brw_x407; /*bool*/
                q1_0_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0_0, (round_half_0_0, _x_x736, _ctx), _ctx); /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Floor(_uniq_rnd_1888_0_0, _ctx)) {
                kk_function_drop(round_half_0_0, _ctx);
                q1_0_0 = cq; /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Ceiling(_uniq_rnd_1888_0_0, _ctx)) {
                kk_function_drop(round_half_0_0, _ctx);
                q1_0_0 = kk_integer_add_small_const(cq, 1, _ctx); /*int*/
                goto _match_x733;
              }
              if (kk_std_num_decimal__is_Truncate(_uniq_rnd_1888_0_0, _ctx)) {
                kk_function_drop(round_half_0_0, _ctx);
                bool b_0_10159_0_0 = kk_integer_lt_borrow(cq,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_0_10159_0_0) {
                  q1_0_0 = kk_integer_add_small_const(cq, 1, _ctx); /*int*/
                  goto _match_x733;
                }
                {
                  q1_0_0 = cq; /*int*/
                  goto _match_x733;
                }
              }
              {
                kk_function_drop(round_half_0_0, _ctx);
                bool b_1_10162_0_0 = kk_integer_gt_borrow(cq,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                if (b_1_10162_0_0) {
                  q1_0_0 = kk_integer_add_small_const(cq, 1, _ctx); /*int*/
                }
                else {
                  q1_0_0 = cq; /*int*/
                }
              }
              _match_x733: ;
            }
            else {
              kk_std_core_types__optional_drop(rnd, _ctx);
              bool b_10014_0_0_0 = kk_integer_is_odd(cq,kk_context()); /*bool*/;
              bool _x_x737;
              if (b_10014_0_0_0) {
                _x_x737 = false; /*bool*/
              }
              else {
                _x_x737 = true; /*bool*/
              }
              q1_0_0 = kk_function_call(kk_integer_t, (kk_function_t, bool, kk_context_t*), round_half_0_0, (round_half_0_0, _x_x737, _ctx), _ctx); /*int*/
            }
          }
          kk_integer_t _b_x57_58;
          kk_integer_t _x_x738;
          if (kk_std_core_types__is_Optional(prec, _ctx)) {
            kk_box_t _box_x56 = prec._cons._Optional.value;
            kk_integer_t _uniq_prec_1884_0_1 = kk_integer_unbox(_box_x56, _ctx);
            kk_integer_dup(_uniq_prec_1884_0_1, _ctx);
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x738 = _uniq_prec_1884_0_1; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(prec, _ctx);
            _x_x738 = kk_integer_from_small(0); /*int*/
          }
          _b_x57_58 = kk_integer_neg(_x_x738,kk_context()); /*int*/
          kk_std_core_types__optional exp_0_10167_0_0 = kk_std_core_types__new_Optional(kk_integer_box(_b_x57_58, _ctx), _ctx); /*? int*/;
          kk_integer_t x_2_0_0;
          bool _match_x403;
          kk_integer_t _brw_x404;
          if (kk_std_core_types__is_Optional(exp_0_10167_0_0, _ctx)) {
            kk_box_t _box_x59 = exp_0_10167_0_0._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0_0_0 = kk_integer_unbox(_box_x59, _ctx);
            kk_integer_dup(_uniq_exp_619_0_0_0, _ctx);
            _brw_x404 = _uniq_exp_619_0_0_0; /*int*/
          }
          else {
            _brw_x404 = kk_integer_from_small(0); /*int*/
          }
          bool _brw_x405 = kk_integer_is_zero_borrow(_brw_x404); /*bool*/;
          kk_integer_drop(_brw_x404, _ctx);
          _match_x403 = _brw_x405; /*bool*/
          if (_match_x403) {
            x_2_0_0 = kk_integer_from_small(0); /*int*/
          }
          else {
            kk_integer_t _x_x739;
            kk_integer_t _x_x740;
            if (kk_std_core_types__is_Optional(exp_0_10167_0_0, _ctx)) {
              kk_box_t _box_x60 = exp_0_10167_0_0._cons._Optional.value;
              kk_integer_t _uniq_exp_619_0_1_0 = kk_integer_unbox(_box_x60, _ctx);
              kk_integer_dup(_uniq_exp_619_0_1_0, _ctx);
              _x_x740 = _uniq_exp_619_0_1_0; /*int*/
            }
            else {
              _x_x740 = kk_integer_from_small(0); /*int*/
            }
            _x_x739 = kk_integer_div(_x_x740,(kk_integer_from_small(7)),kk_context()); /*int*/
            x_2_0_0 = kk_integer_mul((kk_integer_from_small(7)),_x_x739,kk_context()); /*int*/
          }
          kk_integer_t diff_0_0;
          kk_integer_t _x_x741;
          if (kk_std_core_types__is_Optional(exp_0_10167_0_0, _ctx)) {
            kk_box_t _box_x61 = exp_0_10167_0_0._cons._Optional.value;
            kk_integer_t _uniq_exp_619_0_2_0 = kk_integer_unbox(_box_x61, _ctx);
            kk_integer_dup(_uniq_exp_619_0_2_0, _ctx);
            _x_x741 = _uniq_exp_619_0_2_0; /*int*/
          }
          else {
            _x_x741 = kk_integer_from_small(0); /*int*/
          }
          kk_integer_t _x_x742 = kk_integer_dup(x_2_0_0, _ctx); /*int*/
          diff_0_0 = kk_integer_sub(_x_x741,_x_x742,kk_context()); /*int*/
          bool _match_x402 = kk_integer_is_zero_borrow(diff_0_0); /*bool*/;
          if (_match_x402) {
            kk_integer_drop(x_2_0_0, _ctx);
            kk_integer_drop(diff_0_0, _ctx);
            kk_integer_t _x_x743;
            if (kk_std_core_types__is_Optional(exp_0_10167_0_0, _ctx)) {
              kk_box_t _box_x62 = exp_0_10167_0_0._cons._Optional.value;
              kk_integer_t _uniq_exp_619_0_3_0 = kk_integer_unbox(_box_x62, _ctx);
              kk_integer_dup(_uniq_exp_619_0_3_0, _ctx);
              kk_std_core_types__optional_drop(exp_0_10167_0_0, _ctx);
              _x_x743 = _uniq_exp_619_0_3_0; /*int*/
            }
            else {
              kk_std_core_types__optional_drop(exp_0_10167_0_0, _ctx);
              _x_x743 = kk_integer_from_small(0); /*int*/
            }
            return kk_std_num_decimal__new_Decimal(q1_0_0, _x_x743, _ctx);
          }
          {
            kk_std_core_types__optional_drop(exp_0_10167_0_0, _ctx);
            kk_integer_t _x_x744;
            kk_integer_t _x_x745 = kk_integer_abs(diff_0_0,kk_context()); /*int*/
            _x_x744 = kk_std_core_int_mul_exp10(q1_0_0, _x_x745, _ctx); /*int*/
            return kk_std_num_decimal__new_Decimal(_x_x744, x_2_0_0, _ctx);
          }
        }
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
  kk_std_core_types__optional _x_x746 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x747;
  kk_box_t _x_x748;
  kk_std_num_decimal__round _x_x749;
  if (kk_std_core_types__is_Optional(rnd, _ctx)) {
    kk_box_t _box_x64 = rnd._cons._Optional.value;
    kk_std_num_decimal__round _uniq_rnd_2225 = kk_std_num_decimal__round_unbox(_box_x64, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x749 = _uniq_rnd_2225; /*std/num/decimal/round*/
  }
  else {
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x749 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  }
  _x_x748 = kk_std_num_decimal__round_box(_x_x749, _ctx); /*10003*/
  _x_x747 = kk_std_core_types__new_Optional(_x_x748, _ctx); /*? 10003*/
  return kk_std_num_decimal_round_to_prec(x, _x_x746, _x_x747, _ctx);
}
 
// Decimal to the power of `n`

kk_std_num_decimal__decimal kk_std_num_decimal_pow(kk_std_num_decimal__decimal x, kk_integer_t n, kk_context_t* _ctx) { /* (x : decimal, n : int) -> decimal */ 
  kk_integer_t m;
  kk_integer_t _x_x751 = kk_integer_dup(n, _ctx); /*int*/
  m = kk_integer_abs(_x_x751,kk_context()); /*int*/
  kk_integer_t i_10173;
  kk_integer_t _x_x752;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _x_x752 = _x; /*int*/
  }
  kk_integer_t _x_x753 = kk_integer_dup(m, _ctx); /*int*/
  i_10173 = kk_std_core_int_pow(_x_x752, _x_x753, _ctx); /*int*/
  kk_integer_t _b_x68_69;
  kk_integer_t _x_x754;
  {
    kk_integer_t _x_0 = x.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(x, _ctx);
    _x_x754 = _x_0; /*int*/
  }
  kk_integer_t _x_x755 = kk_integer_dup(m, _ctx); /*int*/
  _b_x68_69 = kk_integer_mul(_x_x754,_x_x755,kk_context()); /*int*/
  kk_std_core_types__optional exp_10174 = kk_std_core_types__new_Optional(kk_integer_box(_b_x68_69, _ctx), _ctx); /*? int*/;
  kk_integer_t x_0;
  bool _match_x395;
  kk_integer_t _brw_x396;
  if (kk_std_core_types__is_Optional(exp_10174, _ctx)) {
    kk_box_t _box_x70 = exp_10174._cons._Optional.value;
    kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x70, _ctx);
    kk_integer_dup(_uniq_exp_619, _ctx);
    _brw_x396 = _uniq_exp_619; /*int*/
  }
  else {
    _brw_x396 = kk_integer_from_small(0); /*int*/
  }
  bool _brw_x397 = kk_integer_is_zero_borrow(_brw_x396); /*bool*/;
  kk_integer_drop(_brw_x396, _ctx);
  _match_x395 = _brw_x397; /*bool*/
  if (_match_x395) {
    x_0 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x_x756;
    kk_integer_t _x_x757;
    if (kk_std_core_types__is_Optional(exp_10174, _ctx)) {
      kk_box_t _box_x71 = exp_10174._cons._Optional.value;
      kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x71, _ctx);
      kk_integer_dup(_uniq_exp_619_0, _ctx);
      _x_x757 = _uniq_exp_619_0; /*int*/
    }
    else {
      _x_x757 = kk_integer_from_small(0); /*int*/
    }
    _x_x756 = kk_integer_div(_x_x757,(kk_integer_from_small(7)),kk_context()); /*int*/
    x_0 = kk_integer_mul((kk_integer_from_small(7)),_x_x756,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x_x758;
  if (kk_std_core_types__is_Optional(exp_10174, _ctx)) {
    kk_box_t _box_x72 = exp_10174._cons._Optional.value;
    kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x72, _ctx);
    kk_integer_dup(_uniq_exp_619_1, _ctx);
    _x_x758 = _uniq_exp_619_1; /*int*/
  }
  else {
    _x_x758 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x759 = kk_integer_dup(x_0, _ctx); /*int*/
  diff = kk_integer_sub(_x_x758,_x_x759,kk_context()); /*int*/
  kk_std_num_decimal__decimal y_0;
  bool _match_x394 = kk_integer_is_zero_borrow(diff); /*bool*/;
  if (_match_x394) {
    kk_integer_drop(x_0, _ctx);
    kk_integer_drop(diff, _ctx);
    kk_integer_t _x_x760;
    if (kk_std_core_types__is_Optional(exp_10174, _ctx)) {
      kk_box_t _box_x73 = exp_10174._cons._Optional.value;
      kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x73, _ctx);
      kk_integer_dup(_uniq_exp_619_2, _ctx);
      kk_std_core_types__optional_drop(exp_10174, _ctx);
      _x_x760 = _uniq_exp_619_2; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(exp_10174, _ctx);
      _x_x760 = kk_integer_from_small(0); /*int*/
    }
    y_0 = kk_std_num_decimal__new_Decimal(i_10173, _x_x760, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(exp_10174, _ctx);
    kk_integer_t _x_x761;
    kk_integer_t _x_x762 = kk_integer_abs(diff,kk_context()); /*int*/
    _x_x761 = kk_std_core_int_mul_exp10(i_10173, _x_x762, _ctx); /*int*/
    y_0 = kk_std_num_decimal__new_Decimal(_x_x761, x_0, _ctx); /*std/num/decimal/decimal*/
  }
  bool _match_x384;
  bool _brw_x393 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x384 = _brw_x393; /*bool*/
  if (_match_x384) {
    kk_integer_t x_2;
    bool _match_x388;
    kk_integer_t _brw_x391;
    kk_std_core_types__optional _match_x390 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x390, _ctx)) {
      kk_box_t _box_x74 = _match_x390._cons._Optional.value;
      kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x74, _ctx);
      kk_integer_dup(_uniq_exp_1807, _ctx);
      kk_std_core_types__optional_drop(_match_x390, _ctx);
      _brw_x391 = _uniq_exp_1807; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x390, _ctx);
      _brw_x391 = kk_integer_from_small(0); /*int*/
    }
    bool _brw_x392 = kk_integer_is_zero_borrow(_brw_x391); /*bool*/;
    kk_integer_drop(_brw_x391, _ctx);
    _match_x388 = _brw_x392; /*bool*/
    if (_match_x388) {
      x_2 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_integer_t _x_x763;
      kk_integer_t _x_x764;
      kk_std_core_types__optional _match_x389 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x389, _ctx)) {
        kk_box_t _box_x75 = _match_x389._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_0 = kk_integer_unbox(_box_x75, _ctx);
        kk_integer_dup(_uniq_exp_1807_0, _ctx);
        kk_std_core_types__optional_drop(_match_x389, _ctx);
        _x_x764 = _uniq_exp_1807_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x389, _ctx);
        _x_x764 = kk_integer_from_small(0); /*int*/
      }
      _x_x763 = kk_integer_div(_x_x764,(kk_integer_from_small(7)),kk_context()); /*int*/
      x_2 = kk_integer_mul((kk_integer_from_small(7)),_x_x763,kk_context()); /*int*/
    }
    kk_integer_t diff_0;
    kk_integer_t _x_x765;
    kk_std_core_types__optional _match_x387 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x387, _ctx)) {
      kk_box_t _box_x76 = _match_x387._cons._Optional.value;
      kk_integer_t _uniq_exp_1807_1 = kk_integer_unbox(_box_x76, _ctx);
      kk_integer_dup(_uniq_exp_1807_1, _ctx);
      kk_std_core_types__optional_drop(_match_x387, _ctx);
      _x_x765 = _uniq_exp_1807_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x387, _ctx);
      _x_x765 = kk_integer_from_small(0); /*int*/
    }
    kk_integer_t _x_x766 = kk_integer_dup(x_2, _ctx); /*int*/
    diff_0 = kk_integer_sub(_x_x765,_x_x766,kk_context()); /*int*/
    kk_integer_t _b_x78_79 = kk_integer_add_small_const(m, 3, _ctx); /*int*/;
    kk_std_num_decimal__decimal _x_x767;
    bool _match_x385 = kk_integer_is_zero_borrow(diff_0); /*bool*/;
    if (_match_x385) {
      kk_integer_drop(x_2, _ctx);
      kk_integer_drop(diff_0, _ctx);
      kk_integer_t _x_x768;
      kk_std_core_types__optional _match_x386 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x386, _ctx)) {
        kk_box_t _box_x77 = _match_x386._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_2 = kk_integer_unbox(_box_x77, _ctx);
        kk_integer_dup(_uniq_exp_1807_2, _ctx);
        kk_std_core_types__optional_drop(_match_x386, _ctx);
        _x_x768 = _uniq_exp_1807_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x386, _ctx);
        _x_x768 = kk_integer_from_small(0); /*int*/
      }
      _x_x767 = kk_std_num_decimal__new_Decimal(kk_integer_from_small(1), _x_x768, _ctx); /*std/num/decimal/decimal*/
    }
    else {
      kk_integer_t _x_x769;
      kk_integer_t _x_x770 = kk_integer_abs(diff_0,kk_context()); /*int*/
      _x_x769 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), _x_x770, _ctx); /*int*/
      _x_x767 = kk_std_num_decimal__new_Decimal(_x_x769, x_2, _ctx); /*std/num/decimal/decimal*/
    }
    kk_std_core_types__optional _x_x771 = kk_std_core_types__new_Optional(kk_integer_box(_b_x78_79, _ctx), _ctx); /*? 10003*/
    return kk_std_num_decimal_div(_x_x767, y_0, _x_x771, _ctx);
  }
  {
    kk_integer_drop(m, _ctx);
    return y_0;
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
  kk_std_core_types__tuple2 _match_x352 = kk_std_num_float64_decode(d, _ctx); /*(int, int)*/;
  {
    kk_box_t _box_x80 = _match_x352.fst;
    kk_box_t _box_x81 = _match_x352.snd;
    kk_integer_t man = kk_integer_unbox(_box_x80, _ctx);
    kk_integer_t exp = kk_integer_unbox(_box_x81, _ctx);
    kk_integer_dup(exp, _ctx);
    kk_integer_dup(man, _ctx);
    kk_std_core_types__tuple2_drop(_match_x352, _ctx);
    bool _match_x353 = kk_integer_gte_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x353) {
      kk_std_core_types__optional_drop(max_prec, _ctx);
      kk_integer_t i_10192;
      kk_integer_t _x_x772 = kk_std_core_int_pow(kk_integer_from_small(2), exp, _ctx); /*int*/
      i_10192 = kk_integer_mul(man,_x_x772,kk_context()); /*int*/
      kk_integer_t x;
      bool _match_x379;
      kk_integer_t _brw_x382;
      kk_std_core_types__optional _match_x381 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x381, _ctx)) {
        kk_box_t _box_x82 = _match_x381._cons._Optional.value;
        kk_integer_t _uniq_exp_1807 = kk_integer_unbox(_box_x82, _ctx);
        kk_integer_dup(_uniq_exp_1807, _ctx);
        kk_std_core_types__optional_drop(_match_x381, _ctx);
        _brw_x382 = _uniq_exp_1807; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x381, _ctx);
        _brw_x382 = kk_integer_from_small(0); /*int*/
      }
      bool _brw_x383 = kk_integer_is_zero_borrow(_brw_x382); /*bool*/;
      kk_integer_drop(_brw_x382, _ctx);
      _match_x379 = _brw_x383; /*bool*/
      if (_match_x379) {
        x = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_integer_t _x_x773;
        kk_integer_t _x_x774;
        kk_std_core_types__optional _match_x380 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x380, _ctx)) {
          kk_box_t _box_x83 = _match_x380._cons._Optional.value;
          kk_integer_t _uniq_exp_1807_0 = kk_integer_unbox(_box_x83, _ctx);
          kk_integer_dup(_uniq_exp_1807_0, _ctx);
          kk_std_core_types__optional_drop(_match_x380, _ctx);
          _x_x774 = _uniq_exp_1807_0; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x380, _ctx);
          _x_x774 = kk_integer_from_small(0); /*int*/
        }
        _x_x773 = kk_integer_div(_x_x774,(kk_integer_from_small(7)),kk_context()); /*int*/
        x = kk_integer_mul((kk_integer_from_small(7)),_x_x773,kk_context()); /*int*/
      }
      kk_integer_t diff;
      kk_integer_t _x_x775;
      kk_std_core_types__optional _match_x378 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x378, _ctx)) {
        kk_box_t _box_x84 = _match_x378._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_1 = kk_integer_unbox(_box_x84, _ctx);
        kk_integer_dup(_uniq_exp_1807_1, _ctx);
        kk_std_core_types__optional_drop(_match_x378, _ctx);
        _x_x775 = _uniq_exp_1807_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x378, _ctx);
        _x_x775 = kk_integer_from_small(0); /*int*/
      }
      kk_integer_t _x_x776 = kk_integer_dup(x, _ctx); /*int*/
      diff = kk_integer_sub(_x_x775,_x_x776,kk_context()); /*int*/
      bool _match_x376 = kk_integer_is_zero_borrow(diff); /*bool*/;
      if (_match_x376) {
        kk_integer_drop(x, _ctx);
        kk_integer_drop(diff, _ctx);
        kk_integer_t _x_x777;
        kk_std_core_types__optional _match_x377 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x377, _ctx)) {
          kk_box_t _box_x85 = _match_x377._cons._Optional.value;
          kk_integer_t _uniq_exp_1807_2 = kk_integer_unbox(_box_x85, _ctx);
          kk_integer_dup(_uniq_exp_1807_2, _ctx);
          kk_std_core_types__optional_drop(_match_x377, _ctx);
          _x_x777 = _uniq_exp_1807_2; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x377, _ctx);
          _x_x777 = kk_integer_from_small(0); /*int*/
        }
        return kk_std_num_decimal__new_Decimal(i_10192, _x_x777, _ctx);
      }
      {
        kk_integer_t _x_x778;
        kk_integer_t _x_x779 = kk_integer_abs(diff,kk_context()); /*int*/
        _x_x778 = kk_std_core_int_mul_exp10(i_10192, _x_x779, _ctx); /*int*/
        return kk_std_num_decimal__new_Decimal(_x_x778, x, _ctx);
      }
    }
    {
      kk_integer_t prec;
      bool _match_x370;
      kk_integer_t _brw_x374;
      if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
        kk_box_t _box_x86 = max_prec._cons._Optional.value;
        kk_integer_t _uniq_max_prec_2404 = kk_integer_unbox(_box_x86, _ctx);
        kk_integer_dup(_uniq_max_prec_2404, _ctx);
        _brw_x374 = _uniq_max_prec_2404; /*int*/
      }
      else {
        _brw_x374 = kk_integer_from_small(-1); /*int*/
      }
      bool _brw_x375 = kk_integer_lt_borrow(_brw_x374,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x374, _ctx);
      _match_x370 = _brw_x375; /*bool*/
      if (_match_x370) {
        kk_std_core_types__optional_drop(max_prec, _ctx);
        kk_integer_t _x_x780 = kk_integer_dup(exp, _ctx); /*int*/
        prec = kk_integer_neg(_x_x780,kk_context()); /*int*/
      }
      else {
        kk_integer_t j_10202;
        kk_integer_t _x_x781 = kk_integer_dup(exp, _ctx); /*int*/
        j_10202 = kk_integer_neg(_x_x781,kk_context()); /*int*/
        bool _match_x371;
        kk_integer_t _brw_x372;
        if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
          kk_box_t _box_x87 = max_prec._cons._Optional.value;
          kk_integer_t _uniq_max_prec_2404_0 = kk_integer_unbox(_box_x87, _ctx);
          kk_integer_dup(_uniq_max_prec_2404_0, _ctx);
          _brw_x372 = _uniq_max_prec_2404_0; /*int*/
        }
        else {
          _brw_x372 = kk_integer_from_small(-1); /*int*/
        }
        bool _brw_x373 = kk_integer_lte_borrow(_brw_x372,j_10202,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x372, _ctx);
        _match_x371 = _brw_x373; /*bool*/
        if (_match_x371) {
          kk_integer_drop(j_10202, _ctx);
          if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
            kk_box_t _box_x88 = max_prec._cons._Optional.value;
            kk_integer_t _uniq_max_prec_2404_1 = kk_integer_unbox(_box_x88, _ctx);
            kk_integer_dup(_uniq_max_prec_2404_1, _ctx);
            kk_std_core_types__optional_drop(max_prec, _ctx);
            prec = _uniq_max_prec_2404_1; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(max_prec, _ctx);
            prec = kk_integer_from_small(-1); /*int*/
          }
        }
        else {
          kk_std_core_types__optional_drop(max_prec, _ctx);
          prec = j_10202; /*int*/
        }
      }
      kk_integer_t x_1;
      bool _match_x365;
      kk_integer_t _brw_x368;
      kk_std_core_types__optional _match_x367 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x367, _ctx)) {
        kk_box_t _box_x89 = _match_x367._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_0_0 = kk_integer_unbox(_box_x89, _ctx);
        kk_integer_dup(_uniq_exp_1807_0_0, _ctx);
        kk_std_core_types__optional_drop(_match_x367, _ctx);
        _brw_x368 = _uniq_exp_1807_0_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x367, _ctx);
        _brw_x368 = kk_integer_from_small(0); /*int*/
      }
      bool _brw_x369 = kk_integer_is_zero_borrow(_brw_x368); /*bool*/;
      kk_integer_drop(_brw_x368, _ctx);
      _match_x365 = _brw_x369; /*bool*/
      if (_match_x365) {
        x_1 = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_integer_t _x_x782;
        kk_integer_t _x_x783;
        kk_std_core_types__optional _match_x366 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x366, _ctx)) {
          kk_box_t _box_x90 = _match_x366._cons._Optional.value;
          kk_integer_t _uniq_exp_1807_0_1 = kk_integer_unbox(_box_x90, _ctx);
          kk_integer_dup(_uniq_exp_1807_0_1, _ctx);
          kk_std_core_types__optional_drop(_match_x366, _ctx);
          _x_x783 = _uniq_exp_1807_0_1; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x366, _ctx);
          _x_x783 = kk_integer_from_small(0); /*int*/
        }
        _x_x782 = kk_integer_div(_x_x783,(kk_integer_from_small(7)),kk_context()); /*int*/
        x_1 = kk_integer_mul((kk_integer_from_small(7)),_x_x782,kk_context()); /*int*/
      }
      kk_integer_t diff_0;
      kk_integer_t _x_x784;
      kk_std_core_types__optional _match_x364 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x364, _ctx)) {
        kk_box_t _box_x91 = _match_x364._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_0_2 = kk_integer_unbox(_box_x91, _ctx);
        kk_integer_dup(_uniq_exp_1807_0_2, _ctx);
        kk_std_core_types__optional_drop(_match_x364, _ctx);
        _x_x784 = _uniq_exp_1807_0_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x364, _ctx);
        _x_x784 = kk_integer_from_small(0); /*int*/
      }
      kk_integer_t _x_x785 = kk_integer_dup(x_1, _ctx); /*int*/
      diff_0 = kk_integer_sub(_x_x784,_x_x785,kk_context()); /*int*/
      kk_integer_t x_3;
      bool _match_x359;
      kk_integer_t _brw_x362;
      kk_std_core_types__optional _match_x361 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x361, _ctx)) {
        kk_box_t _box_x92 = _match_x361._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_1_0 = kk_integer_unbox(_box_x92, _ctx);
        kk_integer_dup(_uniq_exp_1807_1_0, _ctx);
        kk_std_core_types__optional_drop(_match_x361, _ctx);
        _brw_x362 = _uniq_exp_1807_1_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x361, _ctx);
        _brw_x362 = kk_integer_from_small(0); /*int*/
      }
      bool _brw_x363 = kk_integer_is_zero_borrow(_brw_x362); /*bool*/;
      kk_integer_drop(_brw_x362, _ctx);
      _match_x359 = _brw_x363; /*bool*/
      if (_match_x359) {
        x_3 = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_integer_t _x_x786;
        kk_integer_t _x_x787;
        kk_std_core_types__optional _match_x360 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x360, _ctx)) {
          kk_box_t _box_x93 = _match_x360._cons._Optional.value;
          kk_integer_t _uniq_exp_1807_1_1 = kk_integer_unbox(_box_x93, _ctx);
          kk_integer_dup(_uniq_exp_1807_1_1, _ctx);
          kk_std_core_types__optional_drop(_match_x360, _ctx);
          _x_x787 = _uniq_exp_1807_1_1; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x360, _ctx);
          _x_x787 = kk_integer_from_small(0); /*int*/
        }
        _x_x786 = kk_integer_div(_x_x787,(kk_integer_from_small(7)),kk_context()); /*int*/
        x_3 = kk_integer_mul((kk_integer_from_small(7)),_x_x786,kk_context()); /*int*/
      }
      kk_integer_t diff_1;
      kk_integer_t _x_x788;
      kk_std_core_types__optional _match_x358 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x358, _ctx)) {
        kk_box_t _box_x94 = _match_x358._cons._Optional.value;
        kk_integer_t _uniq_exp_1807_1_2 = kk_integer_unbox(_box_x94, _ctx);
        kk_integer_dup(_uniq_exp_1807_1_2, _ctx);
        kk_std_core_types__optional_drop(_match_x358, _ctx);
        _x_x788 = _uniq_exp_1807_1_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x358, _ctx);
        _x_x788 = kk_integer_from_small(0); /*int*/
      }
      kk_integer_t _x_x789 = kk_integer_dup(x_3, _ctx); /*int*/
      diff_1 = kk_integer_sub(_x_x788,_x_x789,kk_context()); /*int*/
      kk_std_num_decimal__decimal _x_x790;
      bool _match_x356 = kk_integer_is_zero_borrow(diff_0); /*bool*/;
      if (_match_x356) {
        kk_integer_drop(x_1, _ctx);
        kk_integer_drop(diff_0, _ctx);
        kk_integer_t _x_x791;
        kk_std_core_types__optional _match_x357 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x357, _ctx)) {
          kk_box_t _box_x95 = _match_x357._cons._Optional.value;
          kk_integer_t _uniq_exp_1807_0_3 = kk_integer_unbox(_box_x95, _ctx);
          kk_integer_dup(_uniq_exp_1807_0_3, _ctx);
          kk_std_core_types__optional_drop(_match_x357, _ctx);
          _x_x791 = _uniq_exp_1807_0_3; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x357, _ctx);
          _x_x791 = kk_integer_from_small(0); /*int*/
        }
        _x_x790 = kk_std_num_decimal__new_Decimal(man, _x_x791, _ctx); /*std/num/decimal/decimal*/
      }
      else {
        kk_integer_t _x_x792;
        kk_integer_t _x_x793 = kk_integer_abs(diff_0,kk_context()); /*int*/
        _x_x792 = kk_std_core_int_mul_exp10(man, _x_x793, _ctx); /*int*/
        _x_x790 = kk_std_num_decimal__new_Decimal(_x_x792, x_1, _ctx); /*std/num/decimal/decimal*/
      }
      kk_std_num_decimal__decimal _x_x794;
      kk_std_num_decimal__decimal _x_x795;
      bool _match_x354 = kk_integer_is_zero_borrow(diff_1); /*bool*/;
      if (_match_x354) {
        kk_integer_drop(x_3, _ctx);
        kk_integer_drop(diff_1, _ctx);
        kk_integer_t _x_x796;
        kk_std_core_types__optional _match_x355 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x355, _ctx)) {
          kk_box_t _box_x96 = _match_x355._cons._Optional.value;
          kk_integer_t _uniq_exp_1807_1_3 = kk_integer_unbox(_box_x96, _ctx);
          kk_integer_dup(_uniq_exp_1807_1_3, _ctx);
          kk_std_core_types__optional_drop(_match_x355, _ctx);
          _x_x796 = _uniq_exp_1807_1_3; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x355, _ctx);
          _x_x796 = kk_integer_from_small(0); /*int*/
        }
        _x_x795 = kk_std_num_decimal__new_Decimal(kk_integer_from_small(2), _x_x796, _ctx); /*std/num/decimal/decimal*/
      }
      else {
        kk_integer_t _x_x797;
        kk_integer_t _x_x798 = kk_integer_abs(diff_1,kk_context()); /*int*/
        _x_x797 = kk_std_core_int_mul_exp10(kk_integer_from_small(2), _x_x798, _ctx); /*int*/
        _x_x795 = kk_std_num_decimal__new_Decimal(_x_x797, x_3, _ctx); /*std/num/decimal/decimal*/
      }
      kk_integer_t _x_x799 = kk_integer_neg(exp,kk_context()); /*int*/
      _x_x794 = kk_std_num_decimal_pow(_x_x795, _x_x799, _ctx); /*std/num/decimal/decimal*/
      kk_std_core_types__optional _x_x800 = kk_std_core_types__new_Optional(kk_integer_box(prec, _ctx), _ctx); /*? 10003*/
      return kk_std_num_decimal_div(_x_x790, _x_x794, _x_x800, _ctx);
    }
  }
}
 
// Round a `:decimal` number to an integer an optional rounding mode `rnd` (=`Half-even`).

kk_integer_t kk_std_num_decimal_int(kk_std_num_decimal__decimal x, kk_std_core_types__optional rnd, kk_context_t* _ctx) { /* (x : decimal, rnd : ? round) -> int */ 
  kk_std_num_decimal__decimal y;
  kk_std_core_types__optional _x_x802 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x803;
  kk_box_t _x_x804;
  kk_std_num_decimal__round _x_x805;
  if (kk_std_core_types__is_Optional(rnd, _ctx)) {
    kk_box_t _box_x100 = rnd._cons._Optional.value;
    kk_std_num_decimal__round _uniq_rnd_2758 = kk_std_num_decimal__round_unbox(_box_x100, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x805 = _uniq_rnd_2758; /*std/num/decimal/round*/
  }
  else {
    kk_std_core_types__optional_drop(rnd, _ctx);
    _x_x805 = kk_std_num_decimal__new_Half_even(_ctx); /*std/num/decimal/round*/
  }
  _x_x804 = kk_std_num_decimal__round_box(_x_x805, _ctx); /*10003*/
  _x_x803 = kk_std_core_types__new_Optional(_x_x804, _ctx); /*? 10003*/
  y = kk_std_num_decimal_round_to_prec(x, _x_x802, _x_x803, _ctx); /*std/num/decimal/decimal*/
  bool _match_x349;
  kk_integer_t _brw_x350;
  {
    kk_integer_t _x = y.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x350 = _x; /*int*/
  }
  bool _brw_x351 = kk_integer_gt_borrow(_brw_x350,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x350, _ctx);
  _match_x349 = _brw_x351; /*bool*/
  if (_match_x349) {
    kk_integer_t _x_x806;
    {
      kk_integer_t _x_0 = y.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x806 = _x_0; /*int*/
    }
    kk_integer_t _x_x807;
    {
      kk_integer_t _x_1 = y.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(y, _ctx);
      _x_x807 = _x_1; /*int*/
    }
    return kk_std_core_int_mul_exp10(_x_x806, _x_x807, _ctx);
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
  bool _match_x341;
  kk_integer_t _brw_x345;
  {
    kk_integer_t _x = x.num;
    kk_integer_dup(_x, _ctx);
    _brw_x345 = _x; /*int*/
  }
  bool _brw_x346 = kk_integer_eq_borrow(_brw_x345,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x345, _ctx);
  _match_x341 = _brw_x346; /*bool*/
  if (_match_x341) {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_core_types__new_Eq(_ctx);
  }
  {
    bool _match_x342;
    kk_integer_t _brw_x343;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _brw_x343 = _x_0; /*int*/
    }
    bool _brw_x344 = kk_integer_gt_borrow(_brw_x343,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x343, _ctx);
    _match_x342 = _brw_x344; /*bool*/
    if (_match_x342) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// monadic lift

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10507(kk_string_t _c_x10487, bool neg, kk_string_t whole, kk_integer_t _c_x10491, kk_context_t* _ctx) { /* (string, neg : bool, whole : string, int) -> decimal */ 
  kk_string_t _x_x1_1_10503;
  kk_string_t _x_x809 = kk_string_dup(_c_x10487, _ctx); /*string*/
  _x_x1_1_10503 = kk_std_core_types__lp__plus__plus__rp_(whole, _x_x809, _ctx); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_core_types__maybe x;
  bool _x_x810;
  kk_std_core_types__optional _match_x340 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x340, _ctx)) {
    kk_box_t _box_x104 = _match_x340._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x104);
    kk_std_core_types__optional_drop(_match_x340, _ctx);
    _x_x810 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x340, _ctx);
    _x_x810 = false; /*bool*/
  }
  x = kk_std_core_int_xparse(_x_x1_1_10503, _x_x810, _ctx); /*maybe<int>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_integer_t y_0_10497 = kk_std_core_string_chars_fs_count(_c_x10487, _ctx); /*int*/;
  kk_integer_t _b_x105_106 = kk_integer_sub(_c_x10491,y_0_10497,kk_context()); /*int*/;
  kk_std_core_types__optional _x_x2_10500 = kk_std_core_types__new_Optional(kk_integer_box(_b_x105_106, _ctx), _ctx); /*? int*/;
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_integer_t x_3;
  bool _match_x337;
  kk_integer_t _brw_x338;
  if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
    kk_box_t _box_x107 = _x_x2_10500._cons._Optional.value;
    kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x107, _ctx);
    kk_integer_dup(_uniq_exp_619, _ctx);
    _brw_x338 = _uniq_exp_619; /*int*/
  }
  else {
    _brw_x338 = kk_integer_from_small(0); /*int*/
  }
  bool _brw_x339 = kk_integer_is_zero_borrow(_brw_x338); /*bool*/;
  kk_integer_drop(_brw_x338, _ctx);
  _match_x337 = _brw_x339; /*bool*/
  if (_match_x337) {
    x_3 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_integer_t _x_x811;
    kk_integer_t _x_x812;
    if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
      kk_box_t _box_x108 = _x_x2_10500._cons._Optional.value;
      kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x108, _ctx);
      kk_integer_dup(_uniq_exp_619_0, _ctx);
      _x_x812 = _uniq_exp_619_0; /*int*/
    }
    else {
      _x_x812 = kk_integer_from_small(0); /*int*/
    }
    _x_x811 = kk_integer_div(_x_x812,(kk_integer_from_small(7)),kk_context()); /*int*/
    x_3 = kk_integer_mul((kk_integer_from_small(7)),_x_x811,kk_context()); /*int*/
  }
  kk_integer_t diff;
  kk_integer_t _x_x813;
  if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
    kk_box_t _box_x109 = _x_x2_10500._cons._Optional.value;
    kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x109, _ctx);
    kk_integer_dup(_uniq_exp_619_1, _ctx);
    _x_x813 = _uniq_exp_619_1; /*int*/
  }
  else {
    _x_x813 = kk_integer_from_small(0); /*int*/
  }
  kk_integer_t _x_x814 = kk_integer_dup(x_3, _ctx); /*int*/
  diff = kk_integer_sub(_x_x813,_x_x814,kk_context()); /*int*/
  kk_std_num_decimal__decimal x_2;
  bool _match_x336 = kk_integer_is_zero_borrow(diff); /*bool*/;
  if (_match_x336) {
    kk_integer_drop(x_3, _ctx);
    kk_integer_drop(diff, _ctx);
    kk_integer_t _x_x815;
    if (kk_std_core_types__is_Nothing(x, _ctx)) {
      _x_x815 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x110 = x._cons.Just.value;
      kk_integer_t x_1 = kk_integer_unbox(_box_x110, _ctx);
      kk_integer_dup(x_1, _ctx);
      kk_std_core_types__maybe_drop(x, _ctx);
      _x_x815 = x_1; /*int*/
    }
    kk_integer_t _x_x816;
    if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
      kk_box_t _box_x111 = _x_x2_10500._cons._Optional.value;
      kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x111, _ctx);
      kk_integer_dup(_uniq_exp_619_2, _ctx);
      kk_std_core_types__optional_drop(_x_x2_10500, _ctx);
      _x_x816 = _uniq_exp_619_2; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_x_x2_10500, _ctx);
      _x_x816 = kk_integer_from_small(0); /*int*/
    }
    x_2 = kk_std_num_decimal__new_Decimal(_x_x815, _x_x816, _ctx); /*std/num/decimal/decimal*/
  }
  else {
    kk_std_core_types__optional_drop(_x_x2_10500, _ctx);
    kk_integer_t _x_x817;
    kk_integer_t _x_x818;
    if (kk_std_core_types__is_Nothing(x, _ctx)) {
      _x_x818 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x112 = x._cons.Just.value;
      kk_integer_t x_1_0 = kk_integer_unbox(_box_x112, _ctx);
      kk_integer_dup(x_1_0, _ctx);
      kk_std_core_types__maybe_drop(x, _ctx);
      _x_x818 = x_1_0; /*int*/
    }
    kk_integer_t _x_x819 = kk_integer_abs(diff,kk_context()); /*int*/
    _x_x817 = kk_std_core_int_mul_exp10(_x_x818, _x_x819, _ctx); /*int*/
    x_2 = kk_std_num_decimal__new_Decimal(_x_x817, x_3, _ctx); /*std/num/decimal/decimal*/
  }
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  if (neg) {
    kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_std_num_decimal__decimal x_4;
    kk_integer_t _x_x820;
    kk_integer_t _x_x821;
    {
      kk_integer_t _x = x_2.num;
      kk_integer_dup(_x, _ctx);
      _x_x821 = _x; /*int*/
    }
    _x_x820 = kk_integer_neg(_x_x821,kk_context()); /*int*/
    kk_integer_t _x_x822;
    {
      kk_integer_t _x_0 = x_2.exp;
      kk_integer_dup(_x_0, _ctx);
      kk_std_num_decimal__decimal_drop(x_2, _ctx);
      _x_x822 = _x_0; /*int*/
    }
    x_4 = kk_std_num_decimal__new_Decimal(_x_x820, _x_x822, _ctx); /*std/num/decimal/decimal*/
    kk_unit_t keep_2 = kk_Unit;
    kk_evv_set(w_2,kk_context());
    return x_4;
  }
  {
    return x_2;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10508_fun826__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10508_fun826(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10508_fun826(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10508_fun826, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10508_fun826(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x827;
  kk_char_t _x_x828 = kk_char_unbox(_b_x114, KK_OWNED, _ctx); /*char*/
  _x_x827 = kk_std_num_decimal__mlift_pdecimal_10506(_x_x828, _ctx); /*int*/
  return kk_integer_box(_x_x827, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10508_fun830__t {
  struct kk_function_s _base;
  kk_string_t _c_x10487;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10508_fun830(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10508_fun830(kk_string_t _c_x10487, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10508_fun830__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10508_fun830__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10508_fun830, kk_context());
  _self->_c_x10487 = _c_x10487;
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10508_fun830(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10508_fun830__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10508_fun830__t*, _fself, _ctx);
  kk_string_t _c_x10487 = _self->_c_x10487; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(_c_x10487, _ctx);kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10491_119 = kk_integer_unbox(_b_x117, _ctx); /*int*/;
  kk_std_num_decimal__decimal _x_x831 = kk_std_num_decimal__mlift_pdecimal_10507(_c_x10487, neg, whole, _c_x10491_119, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x831, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10508(kk_string_t _c_x10487, bool neg, kk_string_t whole, bool _y_x10488, kk_context_t* _ctx) { /* (string, neg : bool, whole : string, bool) -> std/text/parse/parse decimal */ 
  kk_integer_t x_10525;
  if (_y_x10488) {
    kk_char_t x_0_10527;
    kk_string_t _x_x823;
    kk_define_string_literal(, _s_x824, 2, "eE", _ctx)
    _x_x823 = kk_string_dup(_s_x824, _ctx); /*string*/
    x_0_10527 = kk_std_text_parse_one_of(_x_x823, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x825 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10508_fun826(_ctx), _ctx); /*10001*/
      x_10525 = kk_integer_unbox(_x_x825, _ctx); /*int*/
    }
    else {
      x_10525 = kk_std_text_parse_pint(_ctx); /*int*/
    }
  }
  else {
    x_10525 = kk_integer_from_small(0); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10525, _ctx);
    kk_box_t _x_x829 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10508_fun830(_c_x10487, whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_decimal__decimal_unbox(_x_x829, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10507(_c_x10487, neg, whole, x_10525, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10510_fun835__t {
  struct kk_function_s _base;
  kk_string_t _c_x10487;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10510_fun835(kk_function_t _fself, kk_box_t _b_x127, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10510_fun835(kk_string_t _c_x10487, kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10510_fun835__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10510_fun835__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10510_fun835, kk_context());
  _self->_c_x10487 = _c_x10487;
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10510_fun835(kk_function_t _fself, kk_box_t _b_x127, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10510_fun835__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10510_fun835__t*, _fself, _ctx);
  kk_string_t _c_x10487 = _self->_c_x10487; /* string */
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(_c_x10487, _ctx);kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  bool _y_x10488_129 = kk_bool_unbox(_b_x127); /*bool*/;
  kk_std_num_decimal__decimal _x_x836 = kk_std_num_decimal__mlift_pdecimal_10508(_c_x10487, neg, whole, _y_x10488_129, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x836, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10510(bool neg, kk_string_t whole, kk_string_t _c_x10487, kk_context_t* _ctx) { /* (neg : bool, whole : string, string) -> decimal */ 
  kk_std_core_hnd__ev ev_10531 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10529;
  kk_box_t _x_x832;
  {
    struct kk_std_core_hnd_Ev* _con_x833 = kk_std_core_hnd__as_Ev(ev_10531, _ctx);
    kk_box_t _box_x120 = _con_x833->hnd;
    int32_t m = _con_x833->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x120, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x332;
    kk_std_core_hnd__clause0 _brw_x333 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x332 = _brw_x333; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x123 = _match_x332.clause;
      _x_x832 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x123, (_fun_unbox_x123, m, ev_10531, _ctx), _ctx); /*10005*/
    }
  }
  x_10529 = kk_bool_unbox(_x_x832); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x834 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10510_fun835(_c_x10487, whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_decimal__decimal_unbox(_x_x834, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10508(_c_x10487, neg, whole, x_10529, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10511_fun838__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10511_fun838(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10511_fun838(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal__mlift_pdecimal_10511_fun838, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10511_fun838(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x839;
  kk_char_t _x_x840 = kk_char_unbox(_b_x131, KK_OWNED, _ctx); /*char*/
  _x_x839 = kk_std_num_decimal__mlift_pdecimal_10509(_x_x840, _ctx); /*string*/
  return kk_string_box(_x_x839);
}


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10511_fun843__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10511_fun843(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10511_fun843(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10511_fun843__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10511_fun843__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10511_fun843, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10511_fun843(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10511_fun843__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10511_fun843__t*, _fself, _ctx);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t _c_x10487_136 = kk_string_unbox(_b_x134); /*string*/;
  kk_std_num_decimal__decimal _x_x844 = kk_std_num_decimal__mlift_pdecimal_10510(neg, whole, _c_x10487_136, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x844, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10511(bool neg, kk_string_t whole, bool _y_x10484, kk_context_t* _ctx) { /* (neg : bool, whole : string, bool) -> std/text/parse/parse decimal */ 
  kk_string_t x_10533;
  if (_y_x10484) {
    kk_char_t x_0_10535 = kk_std_text_parse_char('.', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x837 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10511_fun838(_ctx), _ctx); /*10001*/
      x_10533 = kk_string_unbox(_x_x837); /*string*/
    }
    else {
      x_10533 = kk_std_text_parse_digits(_ctx); /*string*/
    }
  }
  else {
    x_10533 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10533, _ctx);
    kk_box_t _x_x842 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10511_fun843(whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_decimal__decimal_unbox(_x_x842, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10510(neg, whole, x_10533, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10512_fun848__t {
  struct kk_function_s _base;
  kk_string_t whole;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10512_fun848(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10512_fun848(kk_string_t whole, bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10512_fun848__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10512_fun848__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10512_fun848, kk_context());
  _self->whole = whole;
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10512_fun848(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10512_fun848__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10512_fun848__t*, _fself, _ctx);
  kk_string_t whole = _self->whole; /* string */
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_string_dup(whole, _ctx);kk_skip_dup(neg, _ctx);}, {}, _ctx)
  bool _y_x10484_146 = kk_bool_unbox(_b_x144); /*bool*/;
  kk_std_num_decimal__decimal _x_x849 = kk_std_num_decimal__mlift_pdecimal_10511(neg, whole, _y_x10484_146, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x849, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10512(bool neg, kk_string_t whole, kk_context_t* _ctx) { /* (neg : bool, whole : string) -> std/text/parse/parse decimal */ 
  kk_std_core_hnd__ev ev_10539 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10537;
  kk_box_t _x_x845;
  {
    struct kk_std_core_hnd_Ev* _con_x846 = kk_std_core_hnd__as_Ev(ev_10539, _ctx);
    kk_box_t _box_x137 = _con_x846->hnd;
    int32_t m = _con_x846->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x137, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x327;
    kk_std_core_hnd__clause0 _brw_x328 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x327 = _brw_x328; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x140 = _match_x327.clause;
      _x_x845 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x140, (_fun_unbox_x140, m, ev_10539, _ctx), _ctx); /*10005*/
    }
  }
  x_10537 = kk_bool_unbox(_x_x845); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x847 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10512_fun848(whole, neg, _ctx), _ctx); /*10001*/
    return kk_std_num_decimal__decimal_unbox(_x_x847, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10511(neg, whole, x_10537, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_decimal__mlift_pdecimal_10513_fun851__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_decimal__mlift_pdecimal_10513_fun851(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal__new_mlift_pdecimal_10513_fun851(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10513_fun851__t* _self = kk_function_alloc_as(struct kk_std_num_decimal__mlift_pdecimal_10513_fun851__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal__mlift_pdecimal_10513_fun851, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal__mlift_pdecimal_10513_fun851(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  struct kk_std_num_decimal__mlift_pdecimal_10513_fun851__t* _self = kk_function_as(struct kk_std_num_decimal__mlift_pdecimal_10513_fun851__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_string_t whole_150 = kk_string_unbox(_b_x148); /*string*/;
  kk_std_num_decimal__decimal _x_x852 = kk_std_num_decimal__mlift_pdecimal_10512(neg, whole_150, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x852, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal__mlift_pdecimal_10513(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse decimal */ 
  kk_string_t x_10541 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10541, _ctx);
    kk_box_t _x_x850 = kk_std_core_hnd_yield_extend(kk_std_num_decimal__new_mlift_pdecimal_10513_fun851(neg, _ctx), _ctx); /*10001*/
    return kk_std_num_decimal__decimal_unbox(_x_x850, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_decimal__mlift_pdecimal_10512(neg, x_10541, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun854__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun854(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun854(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun854, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun854(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x855;
  bool _x_x856 = kk_bool_unbox(_b_x152); /*bool*/
  _x_x855 = kk_std_num_decimal__mlift_pdecimal_10513(_x_x856, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x855, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun858__t {
  struct kk_function_s _base;
  bool x_10543;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun858(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun858(bool x_10543, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun858__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun858__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun858, kk_context());
  _self->x_10543 = x_10543;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun858(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun858__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun858__t*, _fself, _ctx);
  bool x_10543 = _self->x_10543; /* bool */
  kk_drop_match(_self, {kk_skip_dup(x_10543, _ctx);}, {}, _ctx)
  kk_string_t whole_196 = kk_string_unbox(_b_x154); /*string*/;
  kk_std_num_decimal__decimal _x_x859 = kk_std_num_decimal__mlift_pdecimal_10512(x_10543, whole_196, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x859, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun863__t {
  struct kk_function_s _base;
  kk_string_t x_0_10546;
  bool x_10543;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun863(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun863(kk_string_t x_0_10546, bool x_10543, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun863__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun863__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun863, kk_context());
  _self->x_0_10546 = x_0_10546;
  _self->x_10543 = x_10543;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun863(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun863__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun863__t*, _fself, _ctx);
  kk_string_t x_0_10546 = _self->x_0_10546; /* string */
  bool x_10543 = _self->x_10543; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10546, _ctx);kk_skip_dup(x_10543, _ctx);}, {}, _ctx)
  bool _y_x10484_197 = kk_bool_unbox(_b_x162); /*bool*/;
  kk_std_num_decimal__decimal _x_x864 = kk_std_num_decimal__mlift_pdecimal_10511(x_10543, x_0_10546, _y_x10484_197, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x864, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun866__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun866(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun866(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun866, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun866(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x867;
  kk_char_t _x_x868 = kk_char_unbox(_b_x164, KK_OWNED, _ctx); /*char*/
  _x_x867 = kk_std_num_decimal__mlift_pdecimal_10509(_x_x868, _ctx); /*string*/
  return kk_string_box(_x_x867);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun871__t {
  struct kk_function_s _base;
  kk_string_t x_0_10546;
  bool x_10543;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun871(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun871(kk_string_t x_0_10546, bool x_10543, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun871__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun871__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun871, kk_context());
  _self->x_0_10546 = x_0_10546;
  _self->x_10543 = x_10543;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun871(kk_function_t _fself, kk_box_t _b_x167, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun871__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun871__t*, _fself, _ctx);
  kk_string_t x_0_10546 = _self->x_0_10546; /* string */
  bool x_10543 = _self->x_10543; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10546, _ctx);kk_skip_dup(x_10543, _ctx);}, {}, _ctx)
  kk_string_t _c_x10487_198 = kk_string_unbox(_b_x167); /*string*/;
  kk_std_num_decimal__decimal _x_x872 = kk_std_num_decimal__mlift_pdecimal_10510(x_10543, x_0_10546, _c_x10487_198, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x872, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun876__t {
  struct kk_function_s _base;
  kk_string_t x_0_10546;
  kk_string_t x_2_10554;
  bool x_10543;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun876(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun876(kk_string_t x_0_10546, kk_string_t x_2_10554, bool x_10543, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun876__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun876__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun876, kk_context());
  _self->x_0_10546 = x_0_10546;
  _self->x_2_10554 = x_2_10554;
  _self->x_10543 = x_10543;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun876(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun876__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun876__t*, _fself, _ctx);
  kk_string_t x_0_10546 = _self->x_0_10546; /* string */
  kk_string_t x_2_10554 = _self->x_2_10554; /* string */
  bool x_10543 = _self->x_10543; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10546, _ctx);kk_string_dup(x_2_10554, _ctx);kk_skip_dup(x_10543, _ctx);}, {}, _ctx)
  bool _y_x10488_199 = kk_bool_unbox(_b_x175); /*bool*/;
  kk_std_num_decimal__decimal _x_x877 = kk_std_num_decimal__mlift_pdecimal_10508(x_2_10554, x_10543, x_0_10546, _y_x10488_199, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x877, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun881__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun881(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun881(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_pdecimal_fun881, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun881(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x882;
  kk_char_t _x_x883 = kk_char_unbox(_b_x177, KK_OWNED, _ctx); /*char*/
  _x_x882 = kk_std_num_decimal__mlift_pdecimal_10506(_x_x883, _ctx); /*int*/
  return kk_integer_box(_x_x882, _ctx);
}


// lift anonymous function
struct kk_std_num_decimal_pdecimal_fun885__t {
  struct kk_function_s _base;
  kk_string_t x_0_10546;
  kk_string_t x_2_10554;
  bool x_10543;
};
static kk_box_t kk_std_num_decimal_pdecimal_fun885(kk_function_t _fself, kk_box_t _b_x180, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_pdecimal_fun885(kk_string_t x_0_10546, kk_string_t x_2_10554, bool x_10543, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun885__t* _self = kk_function_alloc_as(struct kk_std_num_decimal_pdecimal_fun885__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_decimal_pdecimal_fun885, kk_context());
  _self->x_0_10546 = x_0_10546;
  _self->x_2_10554 = x_2_10554;
  _self->x_10543 = x_10543;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_decimal_pdecimal_fun885(kk_function_t _fself, kk_box_t _b_x180, kk_context_t* _ctx) {
  struct kk_std_num_decimal_pdecimal_fun885__t* _self = kk_function_as(struct kk_std_num_decimal_pdecimal_fun885__t*, _fself, _ctx);
  kk_string_t x_0_10546 = _self->x_0_10546; /* string */
  kk_string_t x_2_10554 = _self->x_2_10554; /* string */
  bool x_10543 = _self->x_10543; /* bool */
  kk_drop_match(_self, {kk_string_dup(x_0_10546, _ctx);kk_string_dup(x_2_10554, _ctx);kk_skip_dup(x_10543, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10491_200 = kk_integer_unbox(_b_x180, _ctx); /*int*/;
  kk_std_num_decimal__decimal _x_x886 = kk_std_num_decimal__mlift_pdecimal_10507(x_2_10554, x_10543, x_0_10546, _c_x10491_200, _ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x886, _ctx);
}

kk_std_num_decimal__decimal kk_std_num_decimal_pdecimal(kk_context_t* _ctx) { /* () -> std/text/parse/parse decimal */ 
  bool x_10543 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x853 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun854(_ctx), _ctx); /*10001*/
    return kk_std_num_decimal__decimal_unbox(_x_x853, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_10546 = kk_std_text_parse_digits(_ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10546, _ctx);
      kk_box_t _x_x857 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun858(x_10543, _ctx), _ctx); /*10001*/
      return kk_std_num_decimal__decimal_unbox(_x_x857, KK_OWNED, _ctx);
    }
    {
      kk_std_core_hnd__ev ev_10552 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      bool x_1_10549;
      kk_box_t _x_x860;
      {
        struct kk_std_core_hnd_Ev* _con_x861 = kk_std_core_hnd__as_Ev(ev_10552, _ctx);
        kk_box_t _box_x155 = _con_x861->hnd;
        int32_t m = _con_x861->marker;
        kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x155, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h, _ctx);
        kk_std_core_hnd__clause0 _match_x323;
        kk_std_core_hnd__clause0 _brw_x324 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
        kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
        _match_x323 = _brw_x324; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
        {
          kk_function_t _fun_unbox_x158 = _match_x323.clause;
          _x_x860 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x158, (_fun_unbox_x158, m, ev_10552, _ctx), _ctx); /*10005*/
        }
      }
      x_1_10549 = kk_bool_unbox(_x_x860); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x862 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun863(x_0_10546, x_10543, _ctx), _ctx); /*10001*/
        return kk_std_num_decimal__decimal_unbox(_x_x862, KK_OWNED, _ctx);
      }
      {
        kk_string_t x_2_10554;
        if (x_1_10549) {
          kk_char_t x_3_10557 = kk_std_text_parse_char('.', _ctx); /*char*/;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x865 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun866(_ctx), _ctx); /*10001*/
            x_2_10554 = kk_string_unbox(_x_x865); /*string*/
          }
          else {
            x_2_10554 = kk_std_text_parse_digits(_ctx); /*string*/
          }
        }
        else {
          x_2_10554 = kk_string_empty(); /*string*/
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_2_10554, _ctx);
          kk_box_t _x_x870 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun871(x_0_10546, x_10543, _ctx), _ctx); /*10001*/
          return kk_std_num_decimal__decimal_unbox(_x_x870, KK_OWNED, _ctx);
        }
        {
          kk_std_core_hnd__ev ev_0_10562 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
          bool x_4_10559;
          kk_box_t _x_x873;
          {
            struct kk_std_core_hnd_Ev* _con_x874 = kk_std_core_hnd__as_Ev(ev_0_10562, _ctx);
            kk_box_t _box_x168 = _con_x874->hnd;
            int32_t m_0 = _con_x874->marker;
            kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x168, KK_BORROWED, _ctx);
            kk_std_text_parse__parse_dup(h_0, _ctx);
            kk_std_core_hnd__clause0 _match_x320;
            kk_std_core_hnd__clause0 _brw_x321 = kk_std_text_parse_pick_fs__select(h_0, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
            kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
            _match_x320 = _brw_x321; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
            {
              kk_function_t _fun_unbox_x171 = _match_x320.clause;
              _x_x873 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x171, (_fun_unbox_x171, m_0, ev_0_10562, _ctx), _ctx); /*10005*/
            }
          }
          x_4_10559 = kk_bool_unbox(_x_x873); /*bool*/
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x875 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun876(x_0_10546, x_2_10554, x_10543, _ctx), _ctx); /*10001*/
            return kk_std_num_decimal__decimal_unbox(_x_x875, KK_OWNED, _ctx);
          }
          {
            kk_integer_t x_5_10564;
            if (x_4_10559) {
              kk_char_t x_6_10567;
              kk_string_t _x_x878;
              kk_define_string_literal(, _s_x879, 2, "eE", _ctx)
              _x_x878 = kk_string_dup(_s_x879, _ctx); /*string*/
              x_6_10567 = kk_std_text_parse_one_of(_x_x878, _ctx); /*char*/
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x880 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun881(_ctx), _ctx); /*10001*/
                x_5_10564 = kk_integer_unbox(_x_x880, _ctx); /*int*/
              }
              else {
                x_5_10564 = kk_std_text_parse_pint(_ctx); /*int*/
              }
            }
            else {
              x_5_10564 = kk_integer_from_small(0); /*int*/
            }
            if (kk_yielding(kk_context())) {
              kk_integer_drop(x_5_10564, _ctx);
              kk_box_t _x_x884 = kk_std_core_hnd_yield_extend(kk_std_num_decimal_new_pdecimal_fun885(x_0_10546, x_2_10554, x_10543, _ctx), _ctx); /*10001*/
              return kk_std_num_decimal__decimal_unbox(_x_x884, KK_OWNED, _ctx);
            }
            {
              kk_string_t _x_x1_1_10503;
              kk_string_t _x_x887 = kk_string_dup(x_2_10554, _ctx); /*string*/
              _x_x1_1_10503 = kk_std_core_types__lp__plus__plus__rp_(x_0_10546, _x_x887, _ctx); /*string*/
              kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
              kk_std_core_types__maybe x_7;
              bool _x_x888;
              kk_std_core_types__optional _match_x318 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x318, _ctx)) {
                kk_box_t _box_x181 = _match_x318._cons._Optional.value;
                bool _uniq_hex_581 = kk_bool_unbox(_box_x181);
                kk_std_core_types__optional_drop(_match_x318, _ctx);
                _x_x888 = _uniq_hex_581; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x318, _ctx);
                _x_x888 = false; /*bool*/
              }
              x_7 = kk_std_core_int_xparse(_x_x1_1_10503, _x_x888, _ctx); /*maybe<int>*/
              kk_unit_t keep = kk_Unit;
              kk_evv_set(w,kk_context());
              kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
              kk_unit_t keep_0 = kk_Unit;
              kk_evv_set(w_0,kk_context());
              kk_integer_t y_0_10497 = kk_std_core_string_chars_fs_count(x_2_10554, _ctx); /*int*/;
              kk_integer_t _b_x182_183 = kk_integer_sub(x_5_10564,y_0_10497,kk_context()); /*int*/;
              kk_std_core_types__optional _x_x2_10500 = kk_std_core_types__new_Optional(kk_integer_box(_b_x182_183, _ctx), _ctx); /*? int*/;
              kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
              kk_integer_t x_10;
              bool _match_x315;
              kk_integer_t _brw_x316;
              if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
                kk_box_t _box_x184 = _x_x2_10500._cons._Optional.value;
                kk_integer_t _uniq_exp_619 = kk_integer_unbox(_box_x184, _ctx);
                kk_integer_dup(_uniq_exp_619, _ctx);
                _brw_x316 = _uniq_exp_619; /*int*/
              }
              else {
                _brw_x316 = kk_integer_from_small(0); /*int*/
              }
              bool _brw_x317 = kk_integer_is_zero_borrow(_brw_x316); /*bool*/;
              kk_integer_drop(_brw_x316, _ctx);
              _match_x315 = _brw_x317; /*bool*/
              if (_match_x315) {
                x_10 = kk_integer_from_small(0); /*int*/
              }
              else {
                kk_integer_t _x_x889;
                kk_integer_t _x_x890;
                if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
                  kk_box_t _box_x185 = _x_x2_10500._cons._Optional.value;
                  kk_integer_t _uniq_exp_619_0 = kk_integer_unbox(_box_x185, _ctx);
                  kk_integer_dup(_uniq_exp_619_0, _ctx);
                  _x_x890 = _uniq_exp_619_0; /*int*/
                }
                else {
                  _x_x890 = kk_integer_from_small(0); /*int*/
                }
                _x_x889 = kk_integer_div(_x_x890,(kk_integer_from_small(7)),kk_context()); /*int*/
                x_10 = kk_integer_mul((kk_integer_from_small(7)),_x_x889,kk_context()); /*int*/
              }
              kk_integer_t diff;
              kk_integer_t _x_x891;
              if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
                kk_box_t _box_x186 = _x_x2_10500._cons._Optional.value;
                kk_integer_t _uniq_exp_619_1 = kk_integer_unbox(_box_x186, _ctx);
                kk_integer_dup(_uniq_exp_619_1, _ctx);
                _x_x891 = _uniq_exp_619_1; /*int*/
              }
              else {
                _x_x891 = kk_integer_from_small(0); /*int*/
              }
              kk_integer_t _x_x892 = kk_integer_dup(x_10, _ctx); /*int*/
              diff = kk_integer_sub(_x_x891,_x_x892,kk_context()); /*int*/
              kk_std_num_decimal__decimal x_9;
              bool _match_x314 = kk_integer_is_zero_borrow(diff); /*bool*/;
              if (_match_x314) {
                kk_integer_drop(x_10, _ctx);
                kk_integer_drop(diff, _ctx);
                kk_integer_t _x_x893;
                if (kk_std_core_types__is_Nothing(x_7, _ctx)) {
                  _x_x893 = kk_integer_from_small(0); /*int*/
                }
                else {
                  kk_box_t _box_x187 = x_7._cons.Just.value;
                  kk_integer_t x_1_0 = kk_integer_unbox(_box_x187, _ctx);
                  kk_integer_dup(x_1_0, _ctx);
                  kk_std_core_types__maybe_drop(x_7, _ctx);
                  _x_x893 = x_1_0; /*int*/
                }
                kk_integer_t _x_x894;
                if (kk_std_core_types__is_Optional(_x_x2_10500, _ctx)) {
                  kk_box_t _box_x188 = _x_x2_10500._cons._Optional.value;
                  kk_integer_t _uniq_exp_619_2 = kk_integer_unbox(_box_x188, _ctx);
                  kk_integer_dup(_uniq_exp_619_2, _ctx);
                  kk_std_core_types__optional_drop(_x_x2_10500, _ctx);
                  _x_x894 = _uniq_exp_619_2; /*int*/
                }
                else {
                  kk_std_core_types__optional_drop(_x_x2_10500, _ctx);
                  _x_x894 = kk_integer_from_small(0); /*int*/
                }
                x_9 = kk_std_num_decimal__new_Decimal(_x_x893, _x_x894, _ctx); /*std/num/decimal/decimal*/
              }
              else {
                kk_std_core_types__optional_drop(_x_x2_10500, _ctx);
                kk_integer_t _x_x895;
                kk_integer_t _x_x896;
                if (kk_std_core_types__is_Nothing(x_7, _ctx)) {
                  _x_x896 = kk_integer_from_small(0); /*int*/
                }
                else {
                  kk_box_t _box_x189 = x_7._cons.Just.value;
                  kk_integer_t x_1_0_0 = kk_integer_unbox(_box_x189, _ctx);
                  kk_integer_dup(x_1_0_0, _ctx);
                  kk_std_core_types__maybe_drop(x_7, _ctx);
                  _x_x896 = x_1_0_0; /*int*/
                }
                kk_integer_t _x_x897 = kk_integer_abs(diff,kk_context()); /*int*/
                _x_x895 = kk_std_core_int_mul_exp10(_x_x896, _x_x897, _ctx); /*int*/
                x_9 = kk_std_num_decimal__new_Decimal(_x_x895, x_10, _ctx); /*std/num/decimal/decimal*/
              }
              kk_unit_t keep_1 = kk_Unit;
              kk_evv_set(w_1,kk_context());
              if (x_10543) {
                kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                kk_std_num_decimal__decimal x_11;
                kk_integer_t _x_x898;
                kk_integer_t _x_x899;
                {
                  kk_integer_t _x = x_9.num;
                  kk_integer_dup(_x, _ctx);
                  _x_x899 = _x; /*int*/
                }
                _x_x898 = kk_integer_neg(_x_x899,kk_context()); /*int*/
                kk_integer_t _x_x900;
                {
                  kk_integer_t _x_0 = x_9.exp;
                  kk_integer_dup(_x_0, _ctx);
                  kk_std_num_decimal__decimal_drop(x_9, _ctx);
                  _x_x900 = _x_0; /*int*/
                }
                x_11 = kk_std_num_decimal__new_Decimal(_x_x898, _x_x900, _ctx); /*std/num/decimal/decimal*/
                kk_unit_t keep_2 = kk_Unit;
                kk_evv_set(w_2,kk_context());
                return x_11;
              }
              {
                return x_9;
              }
            }
          }
        }
      }
    }
  }
}
 
// Parse a `:decimal` number.


// lift anonymous function
struct kk_std_num_decimal_parse_decimal_fun904__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_decimal_parse_decimal_fun904(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_decimal_new_parse_decimal_fun904(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_decimal_parse_decimal_fun904, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_decimal_parse_decimal_fun904(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_num_decimal__decimal _x_x905 = kk_std_num_decimal_pdecimal(_ctx); /*std/num/decimal/decimal*/
  return kk_std_num_decimal__decimal_box(_x_x905, _ctx);
}

kk_std_core_types__maybe kk_std_num_decimal_parse_decimal(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<decimal> */ 
  kk_string_t s_0_10237;
  kk_string_t _x_x901 = kk_string_trim_left(s,kk_context()); /*string*/
  s_0_10237 = kk_string_trim_right(_x_x901,kk_context()); /*string*/
  kk_std_core_sslice__sslice _b_x201_203;
  kk_string_t _x_x902 = kk_string_dup(s_0_10237, _ctx); /*string*/
  kk_integer_t _x_x903 = kk_string_len_int(s_0_10237,kk_context()); /*int*/
  _b_x201_203 = kk_std_core_sslice__new_Sslice(_x_x902, kk_integer_from_small(0), _x_x903, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10236 = kk_std_text_parse_parse_eof(_b_x201_203, kk_std_num_decimal_new_parse_decimal_fun904(_ctx), _ctx); /*std/text/parse/parse-error<std/num/decimal/decimal>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10236, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x906 = kk_std_text_parse__as_ParseOk(perr_10236, _ctx);
    kk_box_t _box_x205 = _con_x906->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x906->rest;
    kk_std_num_decimal__decimal x_0 = kk_std_num_decimal__decimal_unbox(_box_x205, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10236, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_std_num_decimal__decimal_dup(x_0, _ctx);
      kk_box_drop(_box_x205, _ctx);
      kk_datatype_ptr_free(perr_10236, _ctx);
    }
    else {
      kk_std_num_decimal__decimal_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_10236, _ctx);
    }
    return kk_std_core_types__new_Just(kk_std_num_decimal__decimal_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x907 = kk_std_text_parse__as_ParseError(perr_10236, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x907->rest;
    kk_string_t msg = _con_x907->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10236, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10236, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10236, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// lifted local: @lift-sum@10480, sum, @spec-x10477
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10472, using:
// @uniq-f@10472 = fn(@uniq-x@10467: std/num/decimal/decimal, @uniq-y@10468: std/num/decimal/decimal){
//   std/num/decimal/(+)(@uniq-y@10468, @uniq-x@10467);
// }

kk_std_num_decimal__decimal kk_std_num_decimal__lift_sum_10481(kk_std_core_types__list _uniq_xs_10470, kk_std_num_decimal__decimal _uniq_z_10471, kk_context_t* _ctx) { /* (list<decimal>, decimal) -> decimal */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10470, _ctx)) {
    struct kk_std_core_types_Cons* _con_x908 = kk_std_core_types__as_Cons(_uniq_xs_10470, _ctx);
    kk_box_t _box_x208 = _con_x908->head;
    kk_std_core_types__list _uniq_xx_10475 = _con_x908->tail;
    kk_std_num_decimal__decimal _uniq_x_10474 = kk_std_num_decimal__decimal_unbox(_box_x208, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10470, _ctx)) {
      kk_std_num_decimal__decimal_dup(_uniq_x_10474, _ctx);
      kk_box_drop(_box_x208, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10470, _ctx);
    }
    else {
      kk_std_num_decimal__decimal_dup(_uniq_x_10474, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10475, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10470, _ctx);
    }
    { // tailcall
      kk_std_num_decimal__decimal _x_x909 = kk_std_num_decimal__lp__plus__rp_(_uniq_x_10474, _uniq_z_10471, _ctx); /*std/num/decimal/decimal*/
      _uniq_xs_10470 = _uniq_xx_10475;
      _uniq_z_10471 = _x_x909;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10471;
  }
}
 
// lifted local: sum, @spec-x10469
// specialized: std/core/list/foldr, on parameters @uniq-f@10460, using:
// @uniq-f@10460 = std/num/decimal/(+)

kk_std_num_decimal__decimal kk_std_num_decimal__lift_sum_10480(kk_std_core_types__list _uniq_xs_10458, kk_std_num_decimal__decimal _uniq_z_10459, kk_context_t* _ctx) { /* (list<decimal>, decimal) -> decimal */ 
  kk_std_core_types__list _uniq_xs_0_10046_10464;
  if (kk_std_core_types__is_Nil(_uniq_xs_10458, _ctx)) {
    _uniq_xs_0_10046_10464 = kk_std_core_types__new_Nil(_ctx); /*list<std/num/decimal/decimal>*/
  }
  else {
    _uniq_xs_0_10046_10464 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_xs_10458, _ctx); /*list<std/num/decimal/decimal>*/
  }
  if (kk_std_core_types__is_Nil(_uniq_xs_0_10046_10464, _ctx)) {
    return _uniq_z_10459;
  }
  {
    return kk_std_num_decimal__lift_sum_10481(_uniq_xs_0_10046_10464, _uniq_z_10459, _ctx);
  }
}
 
// Convert a decimal to a `:float64`. This may lose precision.

double kk_std_num_decimal_float64(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> float64 */ 
  bool b_10245;
  kk_integer_t _brw_x306;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x306 = _x; /*int*/
  }
  bool _brw_x307 = kk_integer_lt_borrow(_brw_x306,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x306, _ctx);
  b_10245 = _brw_x307; /*bool*/
  if (b_10245) {
    kk_integer_t n_10251;
    kk_integer_t _x_x917;
    {
      kk_integer_t _x_3 = x.exp;
      kk_integer_dup(_x_3, _ctx);
      _x_x917 = _x_3; /*int*/
    }
    n_10251 = kk_integer_neg(_x_x917,kk_context()); /*int*/
    bool _match_x305 = kk_integer_lte_borrow(n_10251,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x305) {
      bool b_10006 = kk_integer_lt_borrow((kk_integer_from_small(0)),(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (b_10006) {
        kk_integer_t y_0_10012 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), n_10251, _ctx); /*int*/;
        kk_integer_t q;
        kk_integer_t _x_x918;
        {
          kk_integer_t _x_2 = x.num;
          kk_integer_dup(_x_2, _ctx);
          _x_x918 = _x_2; /*int*/
        }
        q = kk_integer_add_small_const(_x_x918, -1, _ctx); /*int*/
        kk_integer_t r = kk_integer_add_small_const(y_0_10012, 0, _ctx); /*int*/;
        double _x_x919 = kk_integer_as_double(q,kk_context()); /*float64*/
        double _x_x920;
        double _x_x921 = kk_integer_as_double(r,kk_context()); /*float64*/
        double _x_x922;
        double _x_x923;
        kk_integer_t _x_x924;
        {
          kk_integer_t _x_4 = x.exp;
          kk_integer_dup(_x_4, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x924 = _x_4; /*int*/
        }
        _x_x923 = kk_integer_as_double(_x_x924,kk_context()); /*float64*/
        _x_x922 = pow(10.0,_x_x923); /*float64*/
        _x_x920 = (_x_x921 * _x_x922); /*float64*/
        return (_x_x919 + _x_x920);
      }
      {
        kk_integer_drop(n_10251, _ctx);
        double _x_x925;
        kk_integer_t _x_x926;
        {
          kk_integer_t _x_2_0 = x.num;
          kk_integer_dup(_x_2_0, _ctx);
          _x_x926 = _x_2_0; /*int*/
        }
        _x_x925 = kk_integer_as_double(_x_x926,kk_context()); /*float64*/
        double _x_x927;
        double _x_x928 = kk_integer_as_double((kk_integer_from_small(0)),kk_context()); /*float64*/
        double _x_x929;
        double _x_x930;
        kk_integer_t _x_x931;
        {
          kk_integer_t _x_4_0 = x.exp;
          kk_integer_dup(_x_4_0, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x931 = _x_4_0; /*int*/
        }
        _x_x930 = kk_integer_as_double(_x_x931,kk_context()); /*float64*/
        _x_x929 = pow(10.0,_x_x930); /*float64*/
        _x_x927 = (_x_x928 * _x_x929); /*float64*/
        return (_x_x925 + _x_x927);
      }
    }
    {
      kk_integer_t cq;
      kk_integer_t _x_x932;
      {
        kk_integer_t _x_2_1 = x.num;
        kk_integer_dup(_x_2_1, _ctx);
        _x_x932 = _x_2_1; /*int*/
      }
      kk_integer_t _x_x933 = kk_integer_dup(n_10251, _ctx); /*int*/
      cq = kk_std_core_int_cdiv_exp10(_x_x932, _x_x933, _ctx); /*int*/
      kk_integer_t y_10005;
      kk_integer_t _x_x934 = kk_integer_dup(cq, _ctx); /*int*/
      kk_integer_t _x_x935 = kk_integer_dup(n_10251, _ctx); /*int*/
      y_10005 = kk_std_core_int_mul_exp10(_x_x934, _x_x935, _ctx); /*int*/
      kk_integer_t cr;
      kk_integer_t _x_x936;
      {
        kk_integer_t _x_2_2 = x.num;
        kk_integer_dup(_x_2_2, _ctx);
        _x_x936 = _x_2_2; /*int*/
      }
      cr = kk_integer_sub(_x_x936,y_10005,kk_context()); /*int*/
      bool b_10006_0 = kk_integer_lt_borrow(cr,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (b_10006_0) {
        kk_integer_t y_0_10012_0 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), n_10251, _ctx); /*int*/;
        kk_integer_t q_0 = kk_integer_add_small_const(cq, -1, _ctx); /*int*/;
        kk_integer_t r_0 = kk_integer_add(cr,y_0_10012_0,kk_context()); /*int*/;
        double _x_x937 = kk_integer_as_double(q_0,kk_context()); /*float64*/
        double _x_x938;
        double _x_x939 = kk_integer_as_double(r_0,kk_context()); /*float64*/
        double _x_x940;
        double _x_x941;
        kk_integer_t _x_x942;
        {
          kk_integer_t _x_4_1 = x.exp;
          kk_integer_dup(_x_4_1, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x942 = _x_4_1; /*int*/
        }
        _x_x941 = kk_integer_as_double(_x_x942,kk_context()); /*float64*/
        _x_x940 = pow(10.0,_x_x941); /*float64*/
        _x_x938 = (_x_x939 * _x_x940); /*float64*/
        return (_x_x937 + _x_x938);
      }
      {
        kk_integer_drop(n_10251, _ctx);
        double _x_x943 = kk_integer_as_double(cq,kk_context()); /*float64*/
        double _x_x944;
        double _x_x945 = kk_integer_as_double(cr,kk_context()); /*float64*/
        double _x_x946;
        double _x_x947;
        kk_integer_t _x_x948;
        {
          kk_integer_t _x_4_0_0 = x.exp;
          kk_integer_dup(_x_4_0_0, _ctx);
          kk_std_num_decimal__decimal_drop(x, _ctx);
          _x_x948 = _x_4_0_0; /*int*/
        }
        _x_x947 = kk_integer_as_double(_x_x948,kk_context()); /*float64*/
        _x_x946 = pow(10.0,_x_x947); /*float64*/
        _x_x944 = (_x_x945 * _x_x946); /*float64*/
        return (_x_x943 + _x_x944);
      }
    }
  }
  {
    double _x_x949;
    kk_integer_t _x_x950;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x950 = _x_0; /*int*/
    }
    _x_x949 = kk_integer_as_double(_x_x950,kk_context()); /*float64*/
    double _x_x951;
    double _x_x952;
    kk_integer_t _x_x953;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x953 = _x_1; /*int*/
    }
    _x_x952 = kk_integer_as_double(_x_x953,kk_context()); /*float64*/
    _x_x951 = pow((0x1.4p3),_x_x952); /*float64*/
    return (_x_x949 * _x_x951);
  }
}
 
// Return the 'truncated' fraction, always in the range (`-1.0`,`1.0`).
// `x.truncate + x.fraction == x`

kk_std_num_decimal__decimal kk_std_num_decimal_fraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool b_10255;
  kk_integer_t _brw_x303;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x303 = _x; /*int*/
  }
  bool _brw_x304 = kk_integer_lt_borrow(_brw_x303,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x303, _ctx);
  b_10255 = _brw_x304; /*bool*/
  if (b_10255) {
    kk_std_num_decimal__decimal y_10259;
    kk_std_num_decimal__decimal _x_x954 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x955 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x956 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Truncate(_ctx), _ctx), _ctx); /*? 10003*/
    y_10259 = kk_std_num_decimal_round_to_prec(_x_x954, _x_x955, _x_x956, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_0_10261;
    kk_integer_t _x_x957;
    kk_integer_t _x_x958;
    {
      kk_integer_t _x_4 = y_10259.num;
      kk_integer_dup(_x_4, _ctx);
      _x_x958 = _x_4; /*int*/
    }
    _x_x957 = kk_integer_neg(_x_x958,kk_context()); /*int*/
    kk_integer_t _x_x959;
    {
      kk_integer_t _x_5 = y_10259.exp;
      kk_integer_dup(_x_5, _ctx);
      kk_std_num_decimal__decimal_drop(y_10259, _ctx);
      _x_x959 = _x_5; /*int*/
    }
    y_0_10261 = kk_std_num_decimal__new_Decimal(_x_x957, _x_x959, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_x299;
    kk_integer_t _brw_x301;
    {
      kk_integer_t _x_0 = x.exp;
      kk_integer_dup(_x_0, _ctx);
      _brw_x301 = _x_0; /*int*/
    }
    kk_integer_t _brw_x300;
    {
      kk_integer_t _x_1 = y_0_10261.exp;
      kk_integer_dup(_x_1, _ctx);
      _brw_x300 = _x_1; /*int*/
    }
    bool _brw_x302 = kk_integer_lte_borrow(_brw_x301,_brw_x300,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x301, _ctx);
    kk_integer_drop(_brw_x300, _ctx);
    _match_x299 = _brw_x302; /*bool*/
    if (_match_x299) {
      kk_integer_t _x_0_0 = x.exp;
      kk_integer_dup(_x_0_0, _ctx);
      e = _x_0_0; /*int*/
    }
    else {
      kk_integer_t _x_1_0 = y_0_10261.exp;
      kk_integer_dup(_x_1_0, _ctx);
      e = _x_1_0; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x_x960 = kk_integer_dup(e, _ctx); /*int*/
    xx = kk_std_num_decimal_expand(x, _x_x960, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x_x961 = kk_integer_dup(e, _ctx); /*int*/
    yy = kk_std_num_decimal_expand(y_0_10261, _x_x961, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x_x962;
    kk_integer_t _x_x963;
    {
      kk_integer_t _x_2 = xx.num;
      kk_integer_dup(_x_2, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _x_x963 = _x_2; /*int*/
    }
    kk_integer_t _x_x964;
    {
      kk_integer_t _x_3 = yy.num;
      kk_integer_dup(_x_3, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _x_x964 = _x_3; /*int*/
    }
    _x_x962 = kk_integer_add(_x_x963,_x_x964,kk_context()); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x962, e, _ctx);
  }
  {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_num_decimal__decimal_dup(kk_std_num_decimal_zero, _ctx);
  }
}
 
// Return the 'floored' fraction, always in the range [`0`,`1.0`).
// `x.floor + x.ffraction == x`

kk_std_num_decimal__decimal kk_std_num_decimal_ffraction(kk_std_num_decimal__decimal x, kk_context_t* _ctx) { /* (x : decimal) -> decimal */ 
  bool b_10273;
  kk_integer_t _brw_x297;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x297 = _x; /*int*/
  }
  bool _brw_x298 = kk_integer_lt_borrow(_brw_x297,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x297, _ctx);
  b_10273 = _brw_x298; /*bool*/
  if (b_10273) {
    kk_std_num_decimal__decimal y_10277;
    kk_std_num_decimal__decimal _x_x965 = kk_std_num_decimal__decimal_dup(x, _ctx); /*std/num/decimal/decimal*/
    kk_std_core_types__optional _x_x966 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(0), _ctx), _ctx); /*? 10003*/
    kk_std_core_types__optional _x_x967 = kk_std_core_types__new_Optional(kk_std_num_decimal__round_box(kk_std_num_decimal__new_Floor(_ctx), _ctx), _ctx); /*? 10003*/
    y_10277 = kk_std_num_decimal_round_to_prec(_x_x965, _x_x966, _x_x967, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal y_0_10279;
    kk_integer_t _x_x968;
    kk_integer_t _x_x969;
    {
      kk_integer_t _x_4 = y_10277.num;
      kk_integer_dup(_x_4, _ctx);
      _x_x969 = _x_4; /*int*/
    }
    _x_x968 = kk_integer_neg(_x_x969,kk_context()); /*int*/
    kk_integer_t _x_x970;
    {
      kk_integer_t _x_5 = y_10277.exp;
      kk_integer_dup(_x_5, _ctx);
      kk_std_num_decimal__decimal_drop(y_10277, _ctx);
      _x_x970 = _x_5; /*int*/
    }
    y_0_10279 = kk_std_num_decimal__new_Decimal(_x_x968, _x_x970, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t e;
    bool _match_x293;
    kk_integer_t _brw_x295;
    {
      kk_integer_t _x_0 = x.exp;
      kk_integer_dup(_x_0, _ctx);
      _brw_x295 = _x_0; /*int*/
    }
    kk_integer_t _brw_x294;
    {
      kk_integer_t _x_1 = y_0_10279.exp;
      kk_integer_dup(_x_1, _ctx);
      _brw_x294 = _x_1; /*int*/
    }
    bool _brw_x296 = kk_integer_lte_borrow(_brw_x295,_brw_x294,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x295, _ctx);
    kk_integer_drop(_brw_x294, _ctx);
    _match_x293 = _brw_x296; /*bool*/
    if (_match_x293) {
      kk_integer_t _x_0_0 = x.exp;
      kk_integer_dup(_x_0_0, _ctx);
      e = _x_0_0; /*int*/
    }
    else {
      kk_integer_t _x_1_0 = y_0_10279.exp;
      kk_integer_dup(_x_1_0, _ctx);
      e = _x_1_0; /*int*/
    }
    kk_std_num_decimal__decimal xx;
    kk_integer_t _x_x971 = kk_integer_dup(e, _ctx); /*int*/
    xx = kk_std_num_decimal_expand(x, _x_x971, _ctx); /*std/num/decimal/decimal*/
    kk_std_num_decimal__decimal yy;
    kk_integer_t _x_x972 = kk_integer_dup(e, _ctx); /*int*/
    yy = kk_std_num_decimal_expand(y_0_10279, _x_x972, _ctx); /*std/num/decimal/decimal*/
    kk_integer_t _x_x973;
    kk_integer_t _x_x974;
    {
      kk_integer_t _x_2 = xx.num;
      kk_integer_dup(_x_2, _ctx);
      kk_std_num_decimal__decimal_drop(xx, _ctx);
      _x_x974 = _x_2; /*int*/
    }
    kk_integer_t _x_x975;
    {
      kk_integer_t _x_3 = yy.num;
      kk_integer_dup(_x_3, _ctx);
      kk_std_num_decimal__decimal_drop(yy, _ctx);
      _x_x975 = _x_3; /*int*/
    }
    _x_x973 = kk_integer_add(_x_x974,_x_x975,kk_context()); /*int*/
    return kk_std_num_decimal__new_Decimal(_x_x973, e, _ctx);
  }
  {
    kk_std_num_decimal__decimal_drop(x, _ctx);
    return kk_std_num_decimal__decimal_dup(kk_std_num_decimal_zero, _ctx);
  }
}
 
// The exponent of a decimal if displayed in scientific notation.
// `11.2e-1.decimal.exponent == 0`

kk_integer_t kk_std_num_decimal_exponent(kk_std_num_decimal__decimal d, kk_context_t* _ctx) { /* (d : decimal) -> int */ 
  kk_integer_t x_0_10293;
  kk_integer_t _x_x976;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x976 = _x; /*int*/
  }
  x_0_10293 = kk_std_core_int_count_digits(_x_x976, _ctx); /*int*/
  kk_integer_t x_10291;
  kk_integer_t _x_x977;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(d, _ctx);
    _x_x977 = _x_0; /*int*/
  }
  x_10291 = kk_integer_add(x_0_10293,_x_x977,kk_context()); /*int*/
  return kk_integer_add_small_const(x_10291, -1, _ctx);
}

kk_string_t kk_std_num_decimal_show_frac(kk_string_t frac, kk_integer_t prec, kk_context_t* _ctx) { /* (frac : string, prec : int) -> string */ 
  kk_string_t frac_trim;
  kk_string_t _x_x978;
  kk_define_string_literal(, _s_x979, 1, "0", _ctx)
  _x_x978 = kk_string_dup(_s_x979, _ctx); /*string*/
  frac_trim = kk_std_core_sslice_trim_right(frac, _x_x978, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_x291 = kk_integer_gte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x291) {
    kk_integer_t n;
    kk_string_t _x_x980 = kk_string_dup(frac_trim, _ctx); /*string*/
    n = kk_std_core_string_chars_fs_count(_x_x980, _ctx); /*int*/
    bool _match_x292 = kk_integer_lte_borrow(prec,n,kk_context()); /*bool*/;
    if (_match_x292) {
      kk_integer_drop(prec, _ctx);
      kk_integer_drop(n, _ctx);
      frac_full = frac_trim; /*string*/
    }
    else {
      kk_string_t s_0_10015 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10016 = kk_integer_sub(prec,n,kk_context()); /*int*/;
      kk_string_t _x_x981 = kk_std_core_string_repeatz(s_0_10015, kk_std_core_int_ssize__t(n_0_10016, _ctx), _ctx); /*string*/
      frac_full = kk_std_core_types__lp__plus__plus__rp_(frac_trim, _x_x981, _ctx); /*string*/
    }
  }
  else {
    kk_integer_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  bool _match_x290;
  kk_string_t _x_x982 = kk_string_dup(frac_full, _ctx); /*string*/
  kk_string_t _x_x983 = kk_string_empty(); /*string*/
  _match_x290 = kk_string_is_eq(_x_x982,_x_x983,kk_context()); /*bool*/
  if (_match_x290) {
    kk_string_drop(frac_full, _ctx);
    return kk_string_empty();
  }
  {
    kk_string_t _x_x986;
    kk_define_string_literal(, _s_x987, 1, ".", _ctx)
    _x_x986 = kk_string_dup(_s_x987, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x986, frac_full, _ctx);
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
  kk_integer_t x_10301;
  kk_integer_t _x_x988;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x229 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3571 = kk_integer_unbox(_box_x229, _ctx);
    kk_integer_dup(_uniq_prec_3571, _ctx);
    _x_x988 = _uniq_prec_3571; /*int*/
  }
  else {
    _x_x988 = kk_integer_from_small(-1000); /*int*/
  }
  x_10301 = kk_integer_abs(_x_x988,kk_context()); /*int*/
  kk_integer_t x_0_10293;
  kk_integer_t _x_x989;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x989 = _x; /*int*/
  }
  x_0_10293 = kk_std_core_int_count_digits(_x_x989, _ctx); /*int*/
  kk_integer_t x_10291;
  kk_integer_t _x_x990;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    _x_x990 = _x_0; /*int*/
  }
  x_10291 = kk_integer_add(x_0_10293,_x_x990,kk_context()); /*int*/
  kk_integer_t y_10302 = kk_integer_add_small_const(x_10291, -1, _ctx); /*int*/;
  kk_integer_t _b_x230_231 = kk_integer_sub(x_10301,y_10302,kk_context()); /*int*/;
  kk_std_num_decimal__decimal x_0;
  kk_std_core_types__optional _x_x991 = kk_std_core_types__new_Optional(kk_integer_box(_b_x230_231, _ctx), _ctx); /*? 10003*/
  x_0 = kk_std_num_decimal_round_to_prec(d, _x_x991, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  kk_string_t s;
  kk_integer_t _x_x992;
  kk_integer_t _x_x993;
  {
    kk_integer_t _x_1 = x_0.num;
    kk_integer_dup(_x_1, _ctx);
    _x_x993 = _x_1; /*int*/
  }
  _x_x992 = kk_integer_abs(_x_x993,kk_context()); /*int*/
  s = kk_std_core_int_show(_x_x992, _ctx); /*string*/
  kk_integer_t digits;
  kk_string_t _x_x994 = kk_string_dup(s, _ctx); /*string*/
  digits = kk_std_core_string_chars_fs_count(_x_x994, _ctx); /*int*/
  kk_integer_t x_1_10304;
  kk_integer_t _x_x995;
  {
    kk_integer_t _x_0_0 = x_0.exp;
    kk_integer_dup(_x_0_0, _ctx);
    _x_x995 = _x_0_0; /*int*/
  }
  x_1_10304 = kk_integer_add(_x_x995,digits,kk_context()); /*int*/
  kk_integer_t exp = kk_integer_add_small_const(x_1_10304, -1, _ctx); /*int*/;
  kk_string_t sign_0;
  bool _match_x287;
  kk_integer_t _brw_x288;
  {
    kk_integer_t _x_1_0 = x_0.num;
    kk_integer_dup(_x_1_0, _ctx);
    kk_std_num_decimal__decimal_drop(x_0, _ctx);
    _brw_x288 = _x_1_0; /*int*/
  }
  bool _brw_x289 = kk_integer_lt_borrow(_brw_x288,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x288, _ctx);
  _match_x287 = _brw_x289; /*bool*/
  if (_match_x287) {
    kk_define_string_literal(, _s_x996, 1, "-", _ctx)
    sign_0 = kk_string_dup(_s_x996, _ctx); /*string*/
  }
  else {
    sign_0 = kk_string_empty(); /*string*/
  }
  kk_string_t exponent_0;
  bool _match_x285 = kk_integer_eq_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x285) {
    kk_integer_drop(exp, _ctx);
    exponent_0 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x999;
    kk_define_string_literal(, _s_x1000, 1, "e", _ctx)
    _x_x999 = kk_string_dup(_s_x1000, _ctx); /*string*/
    kk_string_t _x_x1001;
    kk_string_t _x_x1002;
    bool _match_x286 = kk_integer_gt_borrow(exp,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x286) {
      kk_define_string_literal(, _s_x1003, 1, "+", _ctx)
      _x_x1002 = kk_string_dup(_s_x1003, _ctx); /*string*/
    }
    else {
      _x_x1002 = kk_string_empty(); /*string*/
    }
    kk_string_t _x_x1005 = kk_std_core_int_show(exp, _ctx); /*string*/
    _x_x1001 = kk_std_core_types__lp__plus__plus__rp_(_x_x1002, _x_x1005, _ctx); /*string*/
    exponent_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x999, _x_x1001, _ctx); /*string*/
  }
  kk_string_t frac_10313;
  kk_string_t _x_x1006 = kk_string_dup(s, _ctx); /*string*/
  frac_10313 = kk_std_core_sslice_tail(_x_x1006, _ctx); /*string*/
  kk_string_t frac_trim;
  kk_string_t _x_x1007;
  kk_define_string_literal(, _s_x1008, 1, "0", _ctx)
  _x_x1007 = kk_string_dup(_s_x1008, _ctx); /*string*/
  frac_trim = kk_std_core_sslice_trim_right(frac_10313, _x_x1007, _ctx); /*string*/
  kk_string_t frac_full;
  bool _match_x279;
  kk_integer_t _brw_x283;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x232 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3571_0 = kk_integer_unbox(_box_x232, _ctx);
    kk_integer_dup(_uniq_prec_3571_0, _ctx);
    _brw_x283 = _uniq_prec_3571_0; /*int*/
  }
  else {
    _brw_x283 = kk_integer_from_small(-1000); /*int*/
  }
  bool _brw_x284 = kk_integer_gte_borrow(_brw_x283,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x283, _ctx);
  _match_x279 = _brw_x284; /*bool*/
  if (_match_x279) {
    kk_integer_t n;
    kk_string_t _x_x1009 = kk_string_dup(frac_trim, _ctx); /*string*/
    n = kk_std_core_string_chars_fs_count(_x_x1009, _ctx); /*int*/
    bool _match_x280;
    kk_integer_t _brw_x281;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x233 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3571_1 = kk_integer_unbox(_box_x233, _ctx);
      kk_integer_dup(_uniq_prec_3571_1, _ctx);
      _brw_x281 = _uniq_prec_3571_1; /*int*/
    }
    else {
      _brw_x281 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x282 = kk_integer_lte_borrow(_brw_x281,n,kk_context()); /*bool*/;
    kk_integer_drop(_brw_x281, _ctx);
    _match_x280 = _brw_x282; /*bool*/
    if (_match_x280) {
      kk_std_core_types__optional_drop(prec, _ctx);
      kk_integer_drop(n, _ctx);
      frac_full = frac_trim; /*string*/
    }
    else {
      kk_string_t s_0_10015 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10016;
      kk_integer_t _x_x1010;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x234 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3571_2 = kk_integer_unbox(_box_x234, _ctx);
        kk_integer_dup(_uniq_prec_3571_2, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1010 = _uniq_prec_3571_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1010 = kk_integer_from_small(-1000); /*int*/
      }
      n_0_10016 = kk_integer_sub(_x_x1010,n,kk_context()); /*int*/
      kk_string_t _x_x1011 = kk_std_core_string_repeatz(s_0_10015, kk_std_core_int_ssize__t(n_0_10016, _ctx), _ctx); /*string*/
      frac_full = kk_std_core_types__lp__plus__plus__rp_(frac_trim, _x_x1011, _ctx); /*string*/
    }
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    frac_full = frac_trim; /*string*/
  }
  kk_string_t _x_x1012;
  kk_string_t _x_x1013 = kk_std_core_sslice_head(s, _ctx); /*string*/
  kk_string_t _x_x1014;
  kk_string_t _x_x1015;
  bool _match_x278;
  kk_string_t _x_x1016 = kk_string_dup(frac_full, _ctx); /*string*/
  kk_string_t _x_x1017 = kk_string_empty(); /*string*/
  _match_x278 = kk_string_is_eq(_x_x1016,_x_x1017,kk_context()); /*bool*/
  if (_match_x278) {
    kk_string_drop(frac_full, _ctx);
    _x_x1015 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x1020;
    kk_define_string_literal(, _s_x1021, 1, ".", _ctx)
    _x_x1020 = kk_string_dup(_s_x1021, _ctx); /*string*/
    _x_x1015 = kk_std_core_types__lp__plus__plus__rp_(_x_x1020, frac_full, _ctx); /*string*/
  }
  _x_x1014 = kk_std_core_types__lp__plus__plus__rp_(_x_x1015, exponent_0, _ctx); /*string*/
  _x_x1012 = kk_std_core_types__lp__plus__plus__rp_(_x_x1013, _x_x1014, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(sign_0, _x_x1012, _ctx);
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
  kk_integer_t _b_x236_237;
  kk_integer_t _x_x1022;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x235 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_3981 = kk_integer_unbox(_box_x235, _ctx);
    kk_integer_dup(_uniq_prec_3981, _ctx);
    _x_x1022 = _uniq_prec_3981; /*int*/
  }
  else {
    _x_x1022 = kk_integer_from_small(-1000); /*int*/
  }
  _b_x236_237 = kk_integer_abs(_x_x1022,kk_context()); /*int*/
  kk_std_num_decimal__decimal x;
  kk_std_core_types__optional _x_x1023 = kk_std_core_types__new_Optional(kk_integer_box(_b_x236_237, _ctx), _ctx); /*? 10003*/
  x = kk_std_num_decimal_round_to_prec(d, _x_x1023, kk_std_core_types__new_None(_ctx), _ctx); /*std/num/decimal/decimal*/
  bool _match_x261;
  kk_integer_t _brw_x276;
  {
    kk_integer_t _x = x.exp;
    kk_integer_dup(_x, _ctx);
    _brw_x276 = _x; /*int*/
  }
  bool _brw_x277 = kk_integer_gte_borrow(_brw_x276,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x276, _ctx);
  _match_x261 = _brw_x277; /*bool*/
  if (_match_x261) {
    kk_string_t frac;
    bool _match_x273;
    kk_integer_t _brw_x274;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x238 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3981_0 = kk_integer_unbox(_box_x238, _ctx);
      kk_integer_dup(_uniq_prec_3981_0, _ctx);
      _brw_x274 = _uniq_prec_3981_0; /*int*/
    }
    else {
      _brw_x274 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x275 = kk_integer_lte_borrow(_brw_x274,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x274, _ctx);
    _match_x273 = _brw_x275; /*bool*/
    if (_match_x273) {
      kk_std_core_types__optional_drop(prec, _ctx);
      frac = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x1025;
      kk_define_string_literal(, _s_x1026, 1, ".", _ctx)
      _x_x1025 = kk_string_dup(_s_x1026, _ctx); /*string*/
      kk_string_t _x_x1027;
      kk_string_t _x_x1028;
      kk_define_string_literal(, _s_x1029, 1, "0", _ctx)
      _x_x1028 = kk_string_dup(_s_x1029, _ctx); /*string*/
      kk_ssize_t _x_x1030;
      kk_integer_t _x_x1031;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x239 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3981_1 = kk_integer_unbox(_box_x239, _ctx);
        kk_integer_dup(_uniq_prec_3981_1, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1031 = _uniq_prec_3981_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1031 = kk_integer_from_small(-1000); /*int*/
      }
      _x_x1030 = kk_std_core_int_ssize__t(_x_x1031, _ctx); /*ssize_t*/
      _x_x1027 = kk_std_core_string_repeatz(_x_x1028, _x_x1030, _ctx); /*string*/
      frac = kk_std_core_types__lp__plus__plus__rp_(_x_x1025, _x_x1027, _ctx); /*string*/
    }
    kk_string_t _x_x1032;
    kk_integer_t _x_x1033;
    {
      kk_integer_t _x_0 = x.num;
      kk_integer_dup(_x_0, _ctx);
      _x_x1033 = _x_0; /*int*/
    }
    _x_x1032 = kk_std_core_int_show(_x_x1033, _ctx); /*string*/
    kk_string_t _x_x1034;
    kk_string_t _x_x1035;
    kk_string_t _x_x1036;
    kk_define_string_literal(, _s_x1037, 1, "0", _ctx)
    _x_x1036 = kk_string_dup(_s_x1037, _ctx); /*string*/
    kk_ssize_t _x_x1038;
    kk_integer_t _x_x1039;
    {
      kk_integer_t _x_1 = x.exp;
      kk_integer_dup(_x_1, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x1039 = _x_1; /*int*/
    }
    _x_x1038 = kk_std_core_int_ssize__t(_x_x1039, _ctx); /*ssize_t*/
    _x_x1035 = kk_std_core_string_repeatz(_x_x1036, _x_x1038, _ctx); /*string*/
    _x_x1034 = kk_std_core_types__lp__plus__plus__rp_(_x_x1035, frac, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1032, _x_x1034, _ctx);
  }
  {
    kk_integer_t digits;
    kk_integer_t _x_x1040;
    {
      kk_integer_t _x_2 = x.exp;
      kk_integer_dup(_x_2, _ctx);
      _x_x1040 = _x_2; /*int*/
    }
    digits = kk_integer_neg(_x_x1040,kk_context()); /*int*/
    kk_string_t sign_0;
    bool _match_x270;
    kk_integer_t _brw_x271;
    {
      kk_integer_t _x_3 = x.num;
      kk_integer_dup(_x_3, _ctx);
      _brw_x271 = _x_3; /*int*/
    }
    bool _brw_x272 = kk_integer_lt_borrow(_brw_x271,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x271, _ctx);
    _match_x270 = _brw_x272; /*bool*/
    if (_match_x270) {
      kk_define_string_literal(, _s_x1041, 1, "-", _ctx)
      sign_0 = kk_string_dup(_s_x1041, _ctx); /*string*/
    }
    else {
      sign_0 = kk_string_empty(); /*string*/
    }
    kk_integer_t i_0;
    kk_integer_t _x_x1043;
    {
      kk_integer_t _x_4 = x.num;
      kk_integer_dup(_x_4, _ctx);
      kk_std_num_decimal__decimal_drop(x, _ctx);
      _x_x1043 = _x_4; /*int*/
    }
    i_0 = kk_integer_abs(_x_x1043,kk_context()); /*int*/
    kk_integer_t man;
    kk_integer_t _x_x1044 = kk_integer_dup(i_0, _ctx); /*int*/
    kk_integer_t _x_x1045 = kk_integer_dup(digits, _ctx); /*int*/
    man = kk_std_core_int_cdiv_exp10(_x_x1044, _x_x1045, _ctx); /*int*/
    kk_integer_t y_10332;
    kk_integer_t _x_x1046 = kk_integer_dup(man, _ctx); /*int*/
    kk_integer_t _x_x1047 = kk_integer_dup(digits, _ctx); /*int*/
    y_10332 = kk_std_core_int_mul_exp10(_x_x1046, _x_x1047, _ctx); /*int*/
    kk_integer_t frac_0 = kk_integer_sub(i_0,y_10332,kk_context()); /*int*/;
    kk_string_t s_3_10335 = kk_std_core_int_show(frac_0, _ctx); /*string*/;
    kk_integer_t n_2;
    kk_string_t _x_x1048 = kk_string_dup(s_3_10335, _ctx); /*string*/
    n_2 = kk_std_core_string_chars_fs_count(_x_x1048, _ctx); /*int*/
    kk_string_t frac_1_10333;
    bool _match_x269 = kk_integer_lte_borrow(digits,n_2,kk_context()); /*bool*/;
    if (_match_x269) {
      kk_integer_drop(n_2, _ctx);
      kk_integer_drop(digits, _ctx);
      frac_1_10333 = s_3_10335; /*string*/
    }
    else {
      kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012 = kk_integer_sub(digits,n_2,kk_context()); /*int*/;
      kk_string_t _x_x1049 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
      frac_1_10333 = kk_std_core_types__lp__plus__plus__rp_(_x_x1049, s_3_10335, _ctx); /*string*/
    }
    kk_string_t frac_trim;
    kk_string_t _x_x1050;
    kk_define_string_literal(, _s_x1051, 1, "0", _ctx)
    _x_x1050 = kk_string_dup(_s_x1051, _ctx); /*string*/
    frac_trim = kk_std_core_sslice_trim_right(frac_1_10333, _x_x1050, _ctx); /*string*/
    kk_string_t frac_full;
    bool _match_x263;
    kk_integer_t _brw_x267;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x240 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3981_2 = kk_integer_unbox(_box_x240, _ctx);
      kk_integer_dup(_uniq_prec_3981_2, _ctx);
      _brw_x267 = _uniq_prec_3981_2; /*int*/
    }
    else {
      _brw_x267 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x268 = kk_integer_gte_borrow(_brw_x267,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x267, _ctx);
    _match_x263 = _brw_x268; /*bool*/
    if (_match_x263) {
      kk_integer_t n_1;
      kk_string_t _x_x1052 = kk_string_dup(frac_trim, _ctx); /*string*/
      n_1 = kk_std_core_string_chars_fs_count(_x_x1052, _ctx); /*int*/
      bool _match_x264;
      kk_integer_t _brw_x265;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x241 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3981_3 = kk_integer_unbox(_box_x241, _ctx);
        kk_integer_dup(_uniq_prec_3981_3, _ctx);
        _brw_x265 = _uniq_prec_3981_3; /*int*/
      }
      else {
        _brw_x265 = kk_integer_from_small(-1000); /*int*/
      }
      bool _brw_x266 = kk_integer_lte_borrow(_brw_x265,n_1,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x265, _ctx);
      _match_x264 = _brw_x266; /*bool*/
      if (_match_x264) {
        kk_std_core_types__optional_drop(prec, _ctx);
        kk_integer_drop(n_1, _ctx);
        frac_full = frac_trim; /*string*/
      }
      else {
        kk_string_t s_0_10015 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10016;
        kk_integer_t _x_x1053;
        if (kk_std_core_types__is_Optional(prec, _ctx)) {
          kk_box_t _box_x242 = prec._cons._Optional.value;
          kk_integer_t _uniq_prec_3981_4 = kk_integer_unbox(_box_x242, _ctx);
          kk_integer_dup(_uniq_prec_3981_4, _ctx);
          kk_std_core_types__optional_drop(prec, _ctx);
          _x_x1053 = _uniq_prec_3981_4; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(prec, _ctx);
          _x_x1053 = kk_integer_from_small(-1000); /*int*/
        }
        n_0_10016 = kk_integer_sub(_x_x1053,n_1,kk_context()); /*int*/
        kk_string_t _x_x1054 = kk_std_core_string_repeatz(s_0_10015, kk_std_core_int_ssize__t(n_0_10016, _ctx), _ctx); /*string*/
        frac_full = kk_std_core_types__lp__plus__plus__rp_(frac_trim, _x_x1054, _ctx); /*string*/
      }
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      frac_full = frac_trim; /*string*/
    }
    kk_string_t _x_x1055;
    kk_string_t _x_x1056 = kk_std_core_int_show(man, _ctx); /*string*/
    kk_string_t _x_x1057;
    bool _match_x262;
    kk_string_t _x_x1058 = kk_string_dup(frac_full, _ctx); /*string*/
    kk_string_t _x_x1059 = kk_string_empty(); /*string*/
    _match_x262 = kk_string_is_eq(_x_x1058,_x_x1059,kk_context()); /*bool*/
    if (_match_x262) {
      kk_string_drop(frac_full, _ctx);
      _x_x1057 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x1062;
      kk_define_string_literal(, _s_x1063, 1, ".", _ctx)
      _x_x1062 = kk_string_dup(_s_x1063, _ctx); /*string*/
      _x_x1057 = kk_std_core_types__lp__plus__plus__rp_(_x_x1062, frac_full, _ctx); /*string*/
    }
    _x_x1055 = kk_std_core_types__lp__plus__plus__rp_(_x_x1056, _x_x1057, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(sign_0, _x_x1055, _ctx);
  }
}
 
// Show a decimal `d` with a given precision `prec` (=`-1000`).
// The precision specifies the  number of digits after the dot (in either scientific of fixed-point notation).
// If the precision is negative, _at most_ `prec` digits are displayed, while for a positive
// precision, exactly `prec` digits behind the dot are displayed.
// This uses `show-fixed` when the exponent of `d` in scientific notation is larger than -5
// and smaller than the precision (or 15 in case of a negative precision), otherwise it uses `show-exp`.

kk_string_t kk_std_num_decimal_show(kk_std_num_decimal__decimal d, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (d : decimal, prec : ? int) -> string */ 
  kk_integer_t x_0_10293;
  kk_integer_t _x_x1064;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x1064 = _x; /*int*/
  }
  x_0_10293 = kk_std_core_int_count_digits(_x_x1064, _ctx); /*int*/
  kk_integer_t x_10291;
  kk_integer_t _x_x1065;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    _x_x1065 = _x_0; /*int*/
  }
  x_10291 = kk_integer_add(x_0_10293,_x_x1065,kk_context()); /*int*/
  kk_integer_t exp = kk_integer_add_small_const(x_10291, -1, _ctx); /*int*/;
  bool _match_x254 = kk_integer_gt_borrow(exp,(kk_integer_from_small(-5)),kk_context()); /*bool*/;
  if (_match_x254) {
    bool _match_x255;
    kk_integer_t _brw_x259;
    bool _match_x256;
    kk_integer_t _brw_x257;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x243 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3446 = kk_integer_unbox(_box_x243, _ctx);
      kk_integer_dup(_uniq_prec_3446, _ctx);
      _brw_x257 = _uniq_prec_3446; /*int*/
    }
    else {
      _brw_x257 = kk_integer_from_small(-1000); /*int*/
    }
    bool _brw_x258 = kk_integer_lt_borrow(_brw_x257,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x257, _ctx);
    _match_x256 = _brw_x258; /*bool*/
    if (_match_x256) {
      _brw_x259 = kk_integer_from_small(15); /*int*/
    }
    else {
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x244 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3446_0 = kk_integer_unbox(_box_x244, _ctx);
        kk_integer_dup(_uniq_prec_3446_0, _ctx);
        _brw_x259 = _uniq_prec_3446_0; /*int*/
      }
      else {
        _brw_x259 = kk_integer_from_small(-1000); /*int*/
      }
    }
    bool _brw_x260 = kk_integer_lt_borrow(exp,_brw_x259,kk_context()); /*bool*/;
    kk_integer_drop(exp, _ctx);
    kk_integer_drop(_brw_x259, _ctx);
    _match_x255 = _brw_x260; /*bool*/
    if (_match_x255) {
      kk_std_core_types__optional _x_x1066;
      kk_box_t _x_x1067;
      kk_integer_t _x_x1068;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x245 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3446_1 = kk_integer_unbox(_box_x245, _ctx);
        kk_integer_dup(_uniq_prec_3446_1, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1068 = _uniq_prec_3446_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1068 = kk_integer_from_small(-1000); /*int*/
      }
      _x_x1067 = kk_integer_box(_x_x1068, _ctx); /*10003*/
      _x_x1066 = kk_std_core_types__new_Optional(_x_x1067, _ctx); /*? 10003*/
      return kk_std_num_decimal_show_fixed(d, _x_x1066, _ctx);
    }
    {
      kk_std_core_types__optional _x_x1069;
      kk_box_t _x_x1070;
      kk_integer_t _x_x1071;
      if (kk_std_core_types__is_Optional(prec, _ctx)) {
        kk_box_t _box_x247 = prec._cons._Optional.value;
        kk_integer_t _uniq_prec_3446_2 = kk_integer_unbox(_box_x247, _ctx);
        kk_integer_dup(_uniq_prec_3446_2, _ctx);
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1071 = _uniq_prec_3446_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(prec, _ctx);
        _x_x1071 = kk_integer_from_small(-1000); /*int*/
      }
      _x_x1070 = kk_integer_box(_x_x1071, _ctx); /*10003*/
      _x_x1069 = kk_std_core_types__new_Optional(_x_x1070, _ctx); /*? 10003*/
      return kk_std_num_decimal_show_exp(d, _x_x1069, _ctx);
    }
  }
  {
    kk_integer_drop(exp, _ctx);
    kk_std_core_types__optional _x_x1072;
    kk_box_t _x_x1073;
    kk_integer_t _x_x1074;
    if (kk_std_core_types__is_Optional(prec, _ctx)) {
      kk_box_t _box_x249 = prec._cons._Optional.value;
      kk_integer_t _uniq_prec_3446_3 = kk_integer_unbox(_box_x249, _ctx);
      kk_integer_dup(_uniq_prec_3446_3, _ctx);
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1074 = _uniq_prec_3446_3; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(prec, _ctx);
      _x_x1074 = kk_integer_from_small(-1000); /*int*/
    }
    _x_x1073 = kk_integer_box(_x_x1074, _ctx); /*10003*/
    _x_x1072 = kk_std_core_types__new_Optional(_x_x1073, _ctx); /*? 10003*/
    return kk_std_num_decimal_show_exp(d, _x_x1072, _ctx);
  }
}
 
// Show a decimal `d` using its internal representation.

kk_string_t kk_std_num_decimal_show_raw(kk_std_num_decimal__decimal d, kk_context_t* _ctx) { /* (d : decimal) -> string */ 
  kk_string_t _x_x1075;
  kk_integer_t _x_x1076;
  {
    kk_integer_t _x = d.num;
    kk_integer_dup(_x, _ctx);
    _x_x1076 = _x; /*int*/
  }
  _x_x1075 = kk_std_core_int_show(_x_x1076, _ctx); /*string*/
  kk_string_t _x_x1077;
  kk_string_t _x_x1078;
  kk_define_string_literal(, _s_x1079, 1, "e", _ctx)
  _x_x1078 = kk_string_dup(_s_x1079, _ctx); /*string*/
  kk_string_t _x_x1080;
  kk_integer_t _x_x1081;
  {
    kk_integer_t _x_0 = d.exp;
    kk_integer_dup(_x_0, _ctx);
    kk_std_num_decimal__decimal_drop(d, _ctx);
    _x_x1081 = _x_0; /*int*/
  }
  _x_x1080 = kk_std_core_int_show(_x_x1081, _ctx); /*string*/
  _x_x1077 = kk_std_core_types__lp__plus__plus__rp_(_x_x1078, _x_x1080, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1075, _x_x1077, _ctx);
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
    kk_integer_t _x_x808 = kk_integer_dup(kk_std_num_decimal_maxprecise, _ctx); /*int*/
    kk_std_num_decimal_minprecise = kk_integer_neg(_x_x808,kk_context()); /*int*/
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
