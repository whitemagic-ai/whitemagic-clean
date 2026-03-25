// Koka generated module: std/num/float64, koka version: 3.2.2, platform: 64-bit
#include "std_num_float64.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static int64_t kk_double_to_bits( double d, kk_context_t* ctx ) {
  kk_unused(ctx);
  return (int64_t)kk_bits_from_double(d);
}

static double kk_double_from_bits( int64_t i, kk_context_t* ctx ) {
  kk_unused(ctx);
  return kk_bits_to_double((uint64_t)i);
}

static double kk_prim_parse_double( kk_string_t str, kk_context_t* ctx) {
  const char* s = kk_string_cbuf_borrow(str,NULL,ctx);
  char* end;
  double d = strtod(s,&end);
  kk_string_drop(str,ctx);
  return d;
}


kk_integer_t kk_std_num_float64_flt_max_prec;
 
// Extend a `:float32` to a `:float64`

double kk_std_num_float64_float32_fs_float64(float f, kk_context_t* _ctx) { /* (f : float32) -> float64 */ 
  return (double)(f);
}

double kk_std_num_float64_make_neginf(kk_context_t* _ctx) { /* () -> float64 */ 
  return -HUGE_VAL;
}
 
// Negative infinity

double kk_std_num_float64_neginf;

double kk_std_num_float64_make_posinf(kk_context_t* _ctx) { /* () -> float64 */ 
  return HUGE_VAL;
}
 
// Positive infinity

double kk_std_num_float64_posinf;
 
// lifted local: @lift-minimum@10331, minimum, @spec-x10257
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10252, using:
// @uniq-f@10252 = std/num/float64/min

double kk_std_num_float64__lift_minimum_10332(kk_std_core_types__list _uniq_xs_10250, double _uniq_z_10251, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10250, _ctx)) {
    struct kk_std_core_types_Cons* _con_x739 = kk_std_core_types__as_Cons(_uniq_xs_10250, _ctx);
    kk_box_t _box_x0 = _con_x739->head;
    kk_std_core_types__list _uniq_xx_10255 = _con_x739->tail;
    double _uniq_x_10254 = kk_double_unbox(_box_x0, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10250, _ctx)) {
      kk_box_drop(_box_x0, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10250, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10255, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10250, _ctx);
    }
    { // tailcall
      double _x_x740;
      bool _match_x709 = (_uniq_z_10251 <= _uniq_x_10254); /*bool*/;
      if (_match_x709) {
        _x_x740 = _uniq_z_10251; /*float64*/
      }
      else {
        _x_x740 = _uniq_x_10254; /*float64*/
      }
      _uniq_xs_10250 = _uniq_xx_10255;
      _uniq_z_10251 = _x_x740;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10251;
  }
}
 
// lifted local: minimum, @spec-x10249
// specialized: std/core/list/foldl, on parameters @uniq-f@10246, using:
// @uniq-f@10246 = std/num/float64/min

double kk_std_num_float64__lift_minimum_10331(kk_std_core_types__list _uniq_xs_10244, double _uniq_z_10245, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10244, _ctx)) {
    return _uniq_z_10245;
  }
  {
    return kk_std_num_float64__lift_minimum_10332(_uniq_xs_10244, _uniq_z_10245, _ctx);
  }
}
 
// Returns the smallest element of a list of floats (or `0` for the empty list)

double kk_std_num_float64_minimum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return 0x0p+0;
  }
  {
    struct kk_std_core_types_Cons* _con_x741 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1 = _con_x741->head;
    kk_std_core_types__list xx = _con_x741->tail;
    double x = kk_double_unbox(_box_x1, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_box_x1, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_num_float64__lift_minimum_10331(xx, x, _ctx);
  }
}
 
// lifted local: @lift-maximum@10333, maximum, @spec-x10271
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10266, using:
// @uniq-f@10266 = std/num/float64/max

double kk_std_num_float64__lift_maximum_10334(kk_std_core_types__list _uniq_xs_10264, double _uniq_z_10265, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10264, _ctx)) {
    struct kk_std_core_types_Cons* _con_x742 = kk_std_core_types__as_Cons(_uniq_xs_10264, _ctx);
    kk_box_t _box_x2 = _con_x742->head;
    kk_std_core_types__list _uniq_xx_10269 = _con_x742->tail;
    double _uniq_x_10268 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10264, _ctx)) {
      kk_box_drop(_box_x2, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10264, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10269, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10264, _ctx);
    }
    { // tailcall
      double _x_x743;
      bool _match_x708 = (_uniq_z_10265 >= _uniq_x_10268); /*bool*/;
      if (_match_x708) {
        _x_x743 = _uniq_z_10265; /*float64*/
      }
      else {
        _x_x743 = _uniq_x_10268; /*float64*/
      }
      _uniq_xs_10264 = _uniq_xx_10269;
      _uniq_z_10265 = _x_x743;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10265;
  }
}
 
// lifted local: maximum, @spec-x10263
// specialized: std/core/list/foldl, on parameters @uniq-f@10260, using:
// @uniq-f@10260 = std/num/float64/max

double kk_std_num_float64__lift_maximum_10333(kk_std_core_types__list _uniq_xs_10258, double _uniq_z_10259, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10258, _ctx)) {
    return _uniq_z_10259;
  }
  {
    return kk_std_num_float64__lift_maximum_10334(_uniq_xs_10258, _uniq_z_10259, _ctx);
  }
}
 
// Returns the largest element of a list of floats (or `0` for the empty list)

double kk_std_num_float64_maximum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return 0x0p+0;
  }
  {
    struct kk_std_core_types_Cons* _con_x744 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x3 = _con_x744->head;
    kk_std_core_types__list xx = _con_x744->tail;
    double x = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_box_x3, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_num_float64__lift_maximum_10333(xx, x, _ctx);
  }
}

double kk_std_num_float64_make_nan(kk_context_t* _ctx) { /* () -> float64 */ 
  return (double)NAN;
}
 
// Represents a value that is _not a number_ (NaN)

double kk_std_num_float64_nan;

kk_string_t kk_std_num_float64_show_fixedx(double d, int32_t prec, kk_context_t* _ctx) { /* (d : float64, prec : int32) -> string */ 
  return kk_double_show_fixed(d,prec,kk_context());
}

kk_string_t kk_std_num_float64_show_expx(double d, int32_t prec, kk_context_t* _ctx) { /* (d : float64, prec : int32) -> string */ 
  return kk_double_show_exp(d,prec,kk_context());
}
 
// Show a `:float64` in exponential (scientific) notation.
// The optional `precision` (= `-17`) specifies the precision.
// If `>=0` it specifies the number of digits behind the dot (up to `17` max).
// If negative, then at most the absolute value of `precision` digits behind the dot are used.

kk_string_t kk_std_num_float64_show_exp(double d, kk_std_core_types__optional precision, kk_context_t* _ctx) { /* (d : float64, precision : ? int) -> string */ 
  int32_t _x_x745;
  kk_integer_t _x_x746;
  if (kk_std_core_types__is_Optional(precision, _ctx)) {
    kk_box_t _box_x4 = precision._cons._Optional.value;
    kk_integer_t _uniq_precision_744 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_precision_744, _ctx);
    kk_std_core_types__optional_drop(precision, _ctx);
    _x_x746 = _uniq_precision_744; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(precision, _ctx);
    _x_x746 = kk_integer_from_small(-17); /*int*/
  }
  _x_x745 = kk_integer_clamp32(_x_x746,kk_context()); /*int32*/
  return kk_std_num_float64_show_expx(d, _x_x745, _ctx);
}
 
// Show a `:float64` fixed-point notation.
// The optional `precision` (= `-2`) specifies the maximum precision.
// If `>=0` it specifies the number of digits behind the dot (up to `20` max).
// If negative, then at most the absolute value of `precision` digits behind the dot are used.
// This may still show a number in exponential notation if the it is too small or large,
// in particular, for  a `d` where `d > 1.0e21` or `d < 1.0e-15`, or if
// `precision.abs > 17`, the `show-exp` routine is used.

kk_string_t kk_std_num_float64_show_fixed(double d, kk_std_core_types__optional precision, kk_context_t* _ctx) { /* (d : float64, precision : ? int) -> string */ 
  double dabs = kk_double_abs(d); /*float64*/;
  bool _match_x704 = (dabs < (0x1.203af9ee75616p-50)); /*bool*/;
  if (_match_x704) {
    int32_t _x_x747;
    kk_integer_t _x_x748;
    if (kk_std_core_types__is_Optional(precision, _ctx)) {
      kk_box_t _box_x5 = precision._cons._Optional.value;
      kk_integer_t _uniq_precision_760 = kk_integer_unbox(_box_x5, _ctx);
      kk_integer_dup(_uniq_precision_760, _ctx);
      kk_std_core_types__optional_drop(precision, _ctx);
      _x_x748 = _uniq_precision_760; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(precision, _ctx);
      _x_x748 = kk_integer_from_small(-2); /*int*/
    }
    _x_x747 = kk_integer_clamp32(_x_x748,kk_context()); /*int32*/
    return kk_std_num_float64_show_expx(d, _x_x747, _ctx);
  }
  {
    bool _match_x705 = (dabs > (0x1.b1ae4d6e2ef5p69)); /*bool*/;
    if (_match_x705) {
      int32_t _x_x749;
      kk_integer_t _x_x750;
      if (kk_std_core_types__is_Optional(precision, _ctx)) {
        kk_box_t _box_x6 = precision._cons._Optional.value;
        kk_integer_t _uniq_precision_760_0 = kk_integer_unbox(_box_x6, _ctx);
        kk_integer_dup(_uniq_precision_760_0, _ctx);
        kk_std_core_types__optional_drop(precision, _ctx);
        _x_x750 = _uniq_precision_760_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(precision, _ctx);
        _x_x750 = kk_integer_from_small(-2); /*int*/
      }
      _x_x749 = kk_integer_clamp32(_x_x750,kk_context()); /*int32*/
      return kk_std_num_float64_show_expx(d, _x_x749, _ctx);
    }
    {
      int32_t _x_x751;
      kk_integer_t _x_x752;
      if (kk_std_core_types__is_Optional(precision, _ctx)) {
        kk_box_t _box_x7 = precision._cons._Optional.value;
        kk_integer_t _uniq_precision_760_1 = kk_integer_unbox(_box_x7, _ctx);
        kk_integer_dup(_uniq_precision_760_1, _ctx);
        kk_std_core_types__optional_drop(precision, _ctx);
        _x_x752 = _uniq_precision_760_1; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(precision, _ctx);
        _x_x752 = kk_integer_from_small(-2); /*int*/
      }
      _x_x751 = kk_integer_clamp32(_x_x752,kk_context()); /*int32*/
      return kk_std_num_float64_show_fixedx(d, _x_x751, _ctx);
    }
  }
}
 
// Show a `:float64` as a string.
// If `d >= 1.0e-5` and `d < 1.0e+21`, `show-fixed` is used and otherwise `show-exp`.
// Default `precision` is `-17`.

kk_string_t kk_std_num_float64_show(double d, kk_std_core_types__optional precision, kk_context_t* _ctx) { /* (d : float64, precision : ? int) -> string */ 
  double dabs = kk_double_abs(d); /*float64*/;
  bool _match_x700 = (dabs >= (0x1.4f8b588e368f1p-17)); /*bool*/;
  if (_match_x700) {
    bool _match_x701 = (dabs < (0x1.b1ae4d6e2ef5p69)); /*bool*/;
    if (_match_x701) {
      double dabs_0 = kk_double_abs(d); /*float64*/;
      bool _match_x702 = (dabs_0 < (0x1.203af9ee75616p-50)); /*bool*/;
      if (_match_x702) {
        int32_t _x_x753;
        kk_integer_t _x_x754;
        if (kk_std_core_types__is_Optional(precision, _ctx)) {
          kk_box_t _box_x8 = precision._cons._Optional.value;
          kk_integer_t _uniq_precision_881 = kk_integer_unbox(_box_x8, _ctx);
          kk_integer_dup(_uniq_precision_881, _ctx);
          kk_std_core_types__optional_drop(precision, _ctx);
          _x_x754 = _uniq_precision_881; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(precision, _ctx);
          _x_x754 = kk_integer_from_small(-17); /*int*/
        }
        _x_x753 = kk_integer_clamp32(_x_x754,kk_context()); /*int32*/
        return kk_std_num_float64_show_expx(d, _x_x753, _ctx);
      }
      {
        bool _match_x703 = (dabs_0 > (0x1.b1ae4d6e2ef5p69)); /*bool*/;
        if (_match_x703) {
          int32_t _x_x755;
          kk_integer_t _x_x756;
          if (kk_std_core_types__is_Optional(precision, _ctx)) {
            kk_box_t _box_x9 = precision._cons._Optional.value;
            kk_integer_t _uniq_precision_881_0 = kk_integer_unbox(_box_x9, _ctx);
            kk_integer_dup(_uniq_precision_881_0, _ctx);
            kk_std_core_types__optional_drop(precision, _ctx);
            _x_x756 = _uniq_precision_881_0; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(precision, _ctx);
            _x_x756 = kk_integer_from_small(-17); /*int*/
          }
          _x_x755 = kk_integer_clamp32(_x_x756,kk_context()); /*int32*/
          return kk_std_num_float64_show_expx(d, _x_x755, _ctx);
        }
        {
          int32_t _x_x757;
          kk_integer_t _x_x758;
          if (kk_std_core_types__is_Optional(precision, _ctx)) {
            kk_box_t _box_x10 = precision._cons._Optional.value;
            kk_integer_t _uniq_precision_881_1 = kk_integer_unbox(_box_x10, _ctx);
            kk_integer_dup(_uniq_precision_881_1, _ctx);
            kk_std_core_types__optional_drop(precision, _ctx);
            _x_x758 = _uniq_precision_881_1; /*int*/
          }
          else {
            kk_std_core_types__optional_drop(precision, _ctx);
            _x_x758 = kk_integer_from_small(-17); /*int*/
          }
          _x_x757 = kk_integer_clamp32(_x_x758,kk_context()); /*int32*/
          return kk_std_num_float64_show_fixedx(d, _x_x757, _ctx);
        }
      }
    }
    {
      int32_t _x_x759;
      kk_integer_t _x_x760;
      if (kk_std_core_types__is_Optional(precision, _ctx)) {
        kk_box_t _box_x11 = precision._cons._Optional.value;
        kk_integer_t _uniq_precision_881_2 = kk_integer_unbox(_box_x11, _ctx);
        kk_integer_dup(_uniq_precision_881_2, _ctx);
        kk_std_core_types__optional_drop(precision, _ctx);
        _x_x760 = _uniq_precision_881_2; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(precision, _ctx);
        _x_x760 = kk_integer_from_small(-17); /*int*/
      }
      _x_x759 = kk_integer_clamp32(_x_x760,kk_context()); /*int32*/
      return kk_std_num_float64_show_expx(d, _x_x759, _ctx);
    }
  }
  {
    int32_t _x_x761;
    kk_integer_t _x_x762;
    if (kk_std_core_types__is_Optional(precision, _ctx)) {
      kk_box_t _box_x12 = precision._cons._Optional.value;
      kk_integer_t _uniq_precision_881_3 = kk_integer_unbox(_box_x12, _ctx);
      kk_integer_dup(_uniq_precision_881_3, _ctx);
      kk_std_core_types__optional_drop(precision, _ctx);
      _x_x762 = _uniq_precision_881_3; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(precision, _ctx);
      _x_x762 = kk_integer_from_small(-17); /*int*/
    }
    _x_x761 = kk_integer_clamp32(_x_x762,kk_context()); /*int32*/
    return kk_std_num_float64_show_expx(d, _x_x761, _ctx);
  }
}
 
// Is this value equal to negative or positive infinity ?

bool kk_std_num_float64_is_inf(double d, kk_context_t* _ctx) { /* (d : float64) -> bool */ 
  return isinf(d);
}
 
// fused multiply-add. Computes `(x*y)+z` as if to infinite precision
// with only the final result rounded back to a `:float64`.

double kk_std_num_float64_fmadd(double x, double y, double z, kk_context_t* _ctx) { /* (x : float64, y : float64, z : float64) -> float64 */ 
  return fma(x,y,z);
}
 
// Round a float64 to a specified precision. Rounds to the  even number in case of a tie.
// `123.456.round-to-prec(2) == 123.46`
// `123.456.round-to-prec(-1) == 120.0`

double kk_std_num_float64_round_to_prec(double d, kk_integer_t prec, kk_context_t* _ctx) { /* (d : float64, prec : int) -> float64 */ 
  bool _match_x696 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x696) {
    kk_integer_drop(prec, _ctx);
    return kk_double_round_even(d,kk_context());
  }
  {
    double p;
    double _x_x766 = kk_integer_as_double(prec,kk_context()); /*float64*/
    p = pow(10.0,_x_x766); /*float64*/
    double _x_x767;
    double _x_x768 = (d * p); /*float64*/
    _x_x767 = kk_double_round_even(_x_x768,kk_context()); /*float64*/
    return (_x_x767 / p);
  }
}
 
// Round a `:float64` to a `:float32`

float kk_std_num_float64_float64_fs_float32(double f, kk_context_t* _ctx) { /* (f : float64) -> float32 */ 
  return (float)(f);
}
 
// Returns `ln(exp(x) + exp(y))`.
// Avoids overflow/underflow errors.

double kk_std_num_float64_lnaddexp(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_x694 = (x == y); /*bool*/;
  if (_match_x694) {
    return (x + (0x1.62e42fefa39efp-1));
  }
  {
    double z = (x - y); /*float64*/;
    bool _match_x695 = (z > (0x0p+0)); /*bool*/;
    if (_match_x695) {
      double _x_x773;
      double _x_x774;
      double _x_x775 = (-z); /*float64*/
      _x_x774 = exp(_x_x775); /*float64*/
      _x_x773 = log1p(_x_x774); /*float64*/
      return (x + _x_x773);
    }
    {
      double _x_x776;
      double _x_x777 = exp(z); /*float64*/
      _x_x776 = log1p(_x_x777); /*float64*/
      return (y + _x_x776);
    }
  }
}
 
// Returns `log2( exp2(x) + exp2(y) )`.
// Avoids overflow/underflow errors.

double kk_std_num_float64_logaddexp2(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_x692 = (x == y); /*bool*/;
  if (_match_x692) {
    return (x + 0x1p0);
  }
  {
    double z = (x - y); /*float64*/;
    bool _match_x693 = (z > (0x0p+0)); /*bool*/;
    if (_match_x693) {
      double x_0_10015;
      double _x_x778 = (-z); /*float64*/
      x_0_10015 = exp2(_x_x778); /*float64*/
      double _x_x779;
      double _x_x780 = log1p(x_0_10015); /*float64*/
      _x_x779 = ((0x1.71547652b82fep0) * _x_x780); /*float64*/
      return (x + _x_x779);
    }
    {
      double x_1_10016 = exp2(z); /*float64*/;
      double _x_x781;
      double _x_x782 = log1p(x_1_10016); /*float64*/
      _x_x781 = ((0x1.71547652b82fep0) * _x_x782); /*float64*/
      return (y + _x_x781);
    }
  }
}
 
// Return if two floats are nearly equal with respect to some `epsilon` (=`8*flt-epsilon`).
// The epsilon is the nearest difference for numbers around 1.0. The routine automatically
// scales the epsilon for larger and smaller numbers, and for subnormal numbers.

bool kk_std_num_float64_nearly_eq(double x, double y, kk_std_core_types__optional epsilon, kk_context_t* _ctx) { /* (x : float64, y : float64, epsilon : ? float64) -> bool */ 
  double _uniq_epsilon_1690;
  if (kk_std_core_types__is_Optional(epsilon, _ctx)) {
    kk_box_t _box_x13 = epsilon._cons._Optional.value;
    double _uniq_epsilon_1691 = kk_double_unbox(_box_x13, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(epsilon, _ctx);
    _uniq_epsilon_1690 = _uniq_epsilon_1691; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(epsilon, _ctx);
    _uniq_epsilon_1690 = (0x1p3 * (0x1p-52)); /*float64*/
  }
  bool _match_x687 = (x == y); /*bool*/;
  if (_match_x687) {
    return true;
  }
  {
    double diff;
    double _x_x783 = (x - y); /*float64*/
    diff = kk_double_abs(_x_x783); /*float64*/
    bool _match_x688 = (x == (0x0p+0)); /*bool*/;
    if (_match_x688) {
      double _x_x784 = (0x1p1 * diff); /*float64*/
      double _x_x785 = (_uniq_epsilon_1690 * (0x1p-1022)); /*float64*/
      return (_x_x784 < _x_x785);
    }
    {
      bool _match_x689 = (y == (0x0p+0)); /*bool*/;
      if (_match_x689) {
        double _x_x786 = (0x1p1 * diff); /*float64*/
        double _x_x787 = (_uniq_epsilon_1690 * (0x1p-1022)); /*float64*/
        return (_x_x786 < _x_x787);
      }
      {
        bool _match_x690 = (diff < (0x1p-1022)); /*bool*/;
        if (_match_x690) {
          double _x_x788 = (0x1p1 * diff); /*float64*/
          double _x_x789 = (_uniq_epsilon_1690 * (0x1p-1022)); /*float64*/
          return (_x_x788 < _x_x789);
        }
        {
          double sum_0;
          double _x_x790 = kk_double_abs(x); /*float64*/
          double _x_x791 = kk_double_abs(y); /*float64*/
          sum_0 = (_x_x790 + _x_x791); /*float64*/
          double _x_x792;
          double _x_x793 = (0x1p1 * diff); /*float64*/
          double _x_x794;
          bool _match_x691 = (sum_0 > (0x1.fffffffffffffp1023)); /*bool*/;
          if (_match_x691) {
            _x_x794 = 0x1.fffffffffffffp1023; /*float64*/
          }
          else {
            _x_x794 = sum_0; /*float64*/
          }
          _x_x792 = (_x_x793 / _x_x794); /*float64*/
          return (_x_x792 < _uniq_epsilon_1690);
        }
      }
    }
  }
}
 
// Low-level: return the bits of a 64-bit `:float64` as in `:int64`

int64_t kk_std_num_float64_float64_to_bits(double d, kk_context_t* _ctx) { /* (d : float64) -> int64 */ 
  return kk_double_to_bits(d,kk_context());
}
 
// Low-level: create a `:float64` from the given 64-bit integer.

double kk_std_num_float64_float64_from_bits(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> float64 */ 
  return kk_double_from_bits(i,kk_context());
}
 
// Calculate 2&middot;^`e`^ for an integer `e`.
// Uses efficient bit conversion for exponents between  -1022 and 1023 and
// otherwise falls back to the regular `exp2` function converting `e` to a float64.

double kk_std_num_float64_exp2i(kk_integer_t e, kk_context_t* _ctx) { /* (e : int) -> float64 */ 
  bool _match_x685 = kk_integer_gte_borrow(e,(kk_integer_from_small(-1022)),kk_context()); /*bool*/;
  if (_match_x685) {
    bool _match_x686 = kk_integer_lte_borrow(e,(kk_integer_from_small(1023)),kk_context()); /*bool*/;
    if (_match_x686) {
      int64_t i_10017;
      kk_integer_t _x_x795 = kk_integer_add_small_const(e, 1023, _ctx); /*int*/
      i_10017 = kk_std_num_int64_int64(_x_x795, _ctx); /*int64*/
      int64_t _x_x796;
      int64_t _x_x797 = (KK_I64(52)); /*int64*/
      _x_x796 = kk_shl64(i_10017,_x_x797); /*int64*/
      return kk_std_num_float64_float64_from_bits(_x_x796, _ctx);
    }
    {
      double _x_x798 = kk_integer_as_double(e,kk_context()); /*float64*/
      return exp2(_x_x798);
    }
  }
  {
    double _x_x799 = kk_integer_as_double(e,kk_context()); /*float64*/
    return exp2(_x_x799);
  }
}
 
// 'Load exponent': returns `x`&middot;2^`e`^ for a `is-finite` `x` and
// otherwise `x` itself. See also `encode` which loads an integer mantissa.

double kk_std_num_float64_ldexp(double x, kk_integer_t e, kk_context_t* _ctx) { /* (x : float64, e : int) -> float64 */ 
  bool b_10021 = isfinite(x); /*bool*/;
  if (b_10021) {
    bool _match_x677 = kk_integer_gte_borrow(e,(kk_integer_from_small(-1022)),kk_context()); /*bool*/;
    if (_match_x677) {
      bool _match_x681 = kk_integer_lte_borrow(e,(kk_integer_from_small(1023)),kk_context()); /*bool*/;
      if (_match_x681) {
        double _x_x801 = kk_std_num_float64_exp2i(e, _ctx); /*float64*/
        return (x * _x_x801);
      }
      {
        bool _match_x682 = kk_integer_lte_borrow(e,(kk_integer_from_small(2046)),kk_context()); /*bool*/;
        if (_match_x682) {
          double x_1_10024 = (x * 0x1p1023); /*float64*/;
          kk_integer_t e_1_10025 = kk_integer_add_small_const(e, -1023, _ctx); /*int*/;
          double _x_x802 = kk_std_num_float64_exp2i(e_1_10025, _ctx); /*float64*/
          return (x_1_10024 * _x_x802);
        }
        {
          bool _match_x683 = kk_integer_lte_borrow(e,(kk_integer_from_small(3069)),kk_context()); /*bool*/;
          if (_match_x683) {
            double x_3_10028;
            double _x_x803 = (x * 0x1p1023); /*float64*/
            x_3_10028 = (_x_x803 * 0x1p1023); /*float64*/
            kk_integer_t e_2_10029 = kk_integer_add_small_const(e, -2046, _ctx); /*int*/;
            double _x_x804 = kk_std_num_float64_exp2i(e_2_10029, _ctx); /*float64*/
            return (x_3_10028 * _x_x804);
          }
          {
            kk_integer_drop(e, _ctx);
            bool _match_x684 = (x < (0x0p+0)); /*bool*/;
            if (_match_x684) {
              return kk_std_num_float64_neginf;
            }
            {
              return kk_std_num_float64_posinf;
            }
          }
        }
      }
    }
    {
      bool _match_x678 = kk_integer_gte_borrow(e,(kk_integer_from_small(-2044)),kk_context()); /*bool*/;
      if (_match_x678) {
        double x_5_10032 = (x * (0x1p-1022)); /*float64*/;
        kk_integer_t e_3_10033 = kk_integer_add_small_const(e, 1022, _ctx); /*int*/;
        double _x_x805 = kk_std_num_float64_exp2i(e_3_10033, _ctx); /*float64*/
        return (x_5_10032 * _x_x805);
      }
      {
        bool _match_x679 = kk_integer_gte_borrow(e,(kk_integer_from_small(-3066)),kk_context()); /*bool*/;
        if (_match_x679) {
          double x_7_10036;
          double _x_x806 = (x * (0x1p-1022)); /*float64*/
          x_7_10036 = (_x_x806 * (0x1p-1022)); /*float64*/
          kk_integer_t e_4_10037 = kk_integer_add_small_const(e, 2044, _ctx); /*int*/;
          double _x_x807 = kk_std_num_float64_exp2i(e_4_10037, _ctx); /*float64*/
          return (x_7_10036 * _x_x807);
        }
        {
          kk_integer_drop(e, _ctx);
          bool _match_x680 = (x < (0x0p+0)); /*bool*/;
          if (_match_x680) {
            return -0x0p+0;
          }
          {
            return 0x0p+0;
          }
        }
      }
    }
  }
  {
    kk_integer_drop(e, _ctx);
    return x;
  }
}
 
// decode a normalized float64 (i.e. not subnormal)

kk_std_core_types__tuple2 kk_std_num_float64_decode_normalized(double d, kk_std_core_types__optional e_adjust, kk_context_t* _ctx) { /* (d : float64, e-adjust : ? int) -> (int, int) */ 
  int64_t i = kk_std_num_float64_float64_to_bits(d, _ctx); /*int64*/;
  int64_t exp;
  int64_t _x_x809;
  int64_t _x_x810;
  int64_t _x_x811 = (KK_I64(52)); /*int64*/
  _x_x810 = (int64_t)kk_shr64(i,_x_x811); /*int64*/
  int64_t _x_x812 = (KK_I64(2047)); /*int64*/
  _x_x809 = _x_x810 & _x_x812; /*int64*/
  int64_t _x_x813 = (KK_I64(1043)); /*int64*/
  exp = (int64_t)((uint64_t)_x_x809 - (uint64_t)_x_x813); /*int64*/
  int64_t man;
  int64_t _x_x814;
  int64_t _x_x815 = (KK_I64(4503599627370495)); /*int64*/
  _x_x814 = i & _x_x815; /*int64*/
  int64_t _x_x816 = (KK_I64(4503599627370496)); /*int64*/
  man = (int64_t)((uint64_t)_x_x814 + (uint64_t)_x_x816); /*int64*/
  kk_integer_t x_0_10045 = kk_integer_from_int64(exp,kk_context()); /*int*/;
  kk_integer_t x_10043 = kk_integer_add_small_const(x_0_10045, -32, _ctx); /*int*/;
  kk_integer_t _b_x15_17;
  int64_t _x_x817;
  bool _match_x676 = 0 > i; /*bool*/;
  if (_match_x676) {
    int64_t _x_x818 = (KK_I64(0)); /*int64*/
    _x_x817 = (int64_t)((uint64_t)_x_x818 - (uint64_t)man); /*int64*/
  }
  else {
    _x_x817 = man; /*int64*/
  }
  _b_x15_17 = kk_integer_from_int64(_x_x817,kk_context()); /*int*/
  kk_integer_t _b_x16_18;
  kk_integer_t _x_x819;
  if (kk_std_core_types__is_Optional(e_adjust, _ctx)) {
    kk_box_t _box_x14 = e_adjust._cons._Optional.value;
    kk_integer_t _uniq_e_adjust_2777 = kk_integer_unbox(_box_x14, _ctx);
    kk_integer_dup(_uniq_e_adjust_2777, _ctx);
    kk_std_core_types__optional_drop(e_adjust, _ctx);
    _x_x819 = _uniq_e_adjust_2777; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(e_adjust, _ctx);
    _x_x819 = kk_integer_from_small(0); /*int*/
  }
  _b_x16_18 = kk_integer_add(x_10043,_x_x819,kk_context()); /*int*/
  return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x15_17, _ctx), kk_integer_box(_b_x16_18, _ctx), _ctx);
}
 
// Decode a float64 `d` into a tuple `(m,e)` of a mantissa `m` and exponent `e`
// such that `m`&middot;2^`e`^ =  `d` exactly. The mantissa `m` is
// always either 0 or in the range [2^52^, 2^53^). See also `frexp`.

kk_std_core_types__tuple2 kk_std_num_float64_decode(double d, kk_context_t* _ctx) { /* (d : float64) -> (int, int) */ 
  bool _match_x670 = (d == (0x0p+0)); /*bool*/;
  if (_match_x670) {
    return kk_std_core_types__new_Tuple2(kk_integer_box(kk_integer_from_small(0), _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx);
  }
  {
    bool _match_x671 = (d != (0x0p+0)); /*bool*/;
    if (_match_x671) {
      bool _match_x673;
      double _x_x820 = kk_double_abs(d); /*float64*/
      _match_x673 = (_x_x820 < (0x1p-1022)); /*bool*/
      if (_match_x673) {
        double d_0_10137 = (d * 0x1p54); /*float64*/;
        int64_t i = kk_std_num_float64_float64_to_bits(d_0_10137, _ctx); /*int64*/;
        int64_t exp;
        int64_t _x_x821;
        int64_t _x_x822;
        int64_t _x_x823 = (KK_I64(52)); /*int64*/
        _x_x822 = (int64_t)kk_shr64(i,_x_x823); /*int64*/
        int64_t _x_x824 = (KK_I64(2047)); /*int64*/
        _x_x821 = _x_x822 & _x_x824; /*int64*/
        int64_t _x_x825 = (KK_I64(1043)); /*int64*/
        exp = (int64_t)((uint64_t)_x_x821 - (uint64_t)_x_x825); /*int64*/
        int64_t man;
        int64_t _x_x826;
        int64_t _x_x827 = (KK_I64(4503599627370495)); /*int64*/
        _x_x826 = i & _x_x827; /*int64*/
        int64_t _x_x828 = (KK_I64(4503599627370496)); /*int64*/
        man = (int64_t)((uint64_t)_x_x826 + (uint64_t)_x_x828); /*int64*/
        kk_integer_t x_0_10045 = kk_integer_from_int64(exp,kk_context()); /*int*/;
        kk_integer_t x_10043 = kk_integer_add_small_const(x_0_10045, -32, _ctx); /*int*/;
        kk_integer_t _b_x21_29;
        int64_t _x_x829;
        bool _match_x675 = 0 > i; /*bool*/;
        if (_match_x675) {
          int64_t _x_x830 = (KK_I64(0)); /*int64*/
          _x_x829 = (int64_t)((uint64_t)_x_x830 - (uint64_t)man); /*int64*/
        }
        else {
          _x_x829 = man; /*int64*/
        }
        _b_x21_29 = kk_integer_from_int64(_x_x829,kk_context()); /*int*/
        kk_integer_t _b_x22_30 = kk_integer_add_small_const(x_10043, -54, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x21_29, _ctx), kk_integer_box(_b_x22_30, _ctx), _ctx);
      }
      {
        int64_t i_0 = kk_std_num_float64_float64_to_bits(d, _ctx); /*int64*/;
        int64_t exp_0;
        int64_t _x_x831;
        int64_t _x_x832;
        int64_t _x_x833 = (KK_I64(52)); /*int64*/
        _x_x832 = (int64_t)kk_shr64(i_0,_x_x833); /*int64*/
        int64_t _x_x834 = (KK_I64(2047)); /*int64*/
        _x_x831 = _x_x832 & _x_x834; /*int64*/
        int64_t _x_x835 = (KK_I64(1043)); /*int64*/
        exp_0 = (int64_t)((uint64_t)_x_x831 - (uint64_t)_x_x835); /*int64*/
        int64_t man_0;
        int64_t _x_x836;
        int64_t _x_x837 = (KK_I64(4503599627370495)); /*int64*/
        _x_x836 = i_0 & _x_x837; /*int64*/
        int64_t _x_x838 = (KK_I64(4503599627370496)); /*int64*/
        man_0 = (int64_t)((uint64_t)_x_x836 + (uint64_t)_x_x838); /*int64*/
        kk_integer_t x_0_10045_0 = kk_integer_from_int64(exp_0,kk_context()); /*int*/;
        kk_integer_t x_10043_0 = kk_integer_add_small_const(x_0_10045_0, -32, _ctx); /*int*/;
        kk_integer_t _b_x23_31;
        int64_t _x_x839;
        bool _match_x674 = 0 > i_0; /*bool*/;
        if (_match_x674) {
          int64_t _x_x840 = (KK_I64(0)); /*int64*/
          _x_x839 = (int64_t)((uint64_t)_x_x840 - (uint64_t)man_0); /*int64*/
        }
        else {
          _x_x839 = man_0; /*int64*/
        }
        _b_x23_31 = kk_integer_from_int64(_x_x839,kk_context()); /*int*/
        kk_integer_t _b_x24_32 = kk_integer_add_small_const(x_10043_0, 0, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x23_31, _ctx), kk_integer_box(_b_x24_32, _ctx), _ctx);
      }
    }
    {
      int64_t i_1 = kk_std_num_float64_float64_to_bits(d, _ctx); /*int64*/;
      int64_t exp_1;
      int64_t _x_x841;
      int64_t _x_x842;
      int64_t _x_x843 = (KK_I64(52)); /*int64*/
      _x_x842 = (int64_t)kk_shr64(i_1,_x_x843); /*int64*/
      int64_t _x_x844 = (KK_I64(2047)); /*int64*/
      _x_x841 = _x_x842 & _x_x844; /*int64*/
      int64_t _x_x845 = (KK_I64(1043)); /*int64*/
      exp_1 = (int64_t)((uint64_t)_x_x841 - (uint64_t)_x_x845); /*int64*/
      int64_t man_1;
      int64_t _x_x846;
      int64_t _x_x847 = (KK_I64(4503599627370495)); /*int64*/
      _x_x846 = i_1 & _x_x847; /*int64*/
      int64_t _x_x848 = (KK_I64(4503599627370496)); /*int64*/
      man_1 = (int64_t)((uint64_t)_x_x846 + (uint64_t)_x_x848); /*int64*/
      kk_integer_t x_0_10045_1 = kk_integer_from_int64(exp_1,kk_context()); /*int*/;
      kk_integer_t x_10043_1 = kk_integer_add_small_const(x_0_10045_1, -32, _ctx); /*int*/;
      kk_integer_t _b_x25_33;
      int64_t _x_x849;
      bool _match_x672 = 0 > i_1; /*bool*/;
      if (_match_x672) {
        int64_t _x_x850 = (KK_I64(0)); /*int64*/
        _x_x849 = (int64_t)((uint64_t)_x_x850 - (uint64_t)man_1); /*int64*/
      }
      else {
        _x_x849 = man_1; /*int64*/
      }
      _b_x25_33 = kk_integer_from_int64(_x_x849,kk_context()); /*int*/
      kk_integer_t _b_x26_34 = kk_integer_add_small_const(x_10043_1, 0, _ctx); /*int*/;
      return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x25_33, _ctx), kk_integer_box(_b_x26_34, _ctx), _ctx);
    }
  }
}
 
// 'Fraction/exponent': return the normalized fraction `f` and exponent `exp`
// for a number `x` such that `x == f`&middot;2^`exp`^.
// The absolute value of the fraction `f` is always in the range [0.5, 1.0), or
// one of `0.0`, `-0.0`, `neginf`, `posinf`, or `nan`.
// See also `decode` which  decodes to an integer mantissa.

kk_std_core_types__tuple2 kk_std_num_float64_frexp(double x, kk_context_t* _ctx) { /* (x : float64) -> (float64, int) */ 
  bool b_10048 = isfinite(x); /*bool*/;
  if (b_10048) {
    bool _match_x666 = (x == (0x0p+0)); /*bool*/;
    if (_match_x666) {
      bool _match_x668;
      double _x_x851 = (0x1p0 / x); /*float64*/
      _match_x668 = (isinf(_x_x851) && signbit(_x_x851)); /*bool*/
      if (_match_x668) {
        return kk_std_core_types__new_Tuple2(kk_double_box(x, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx);
      }
      {
        kk_std_core_types__tuple2 _match_x669 = kk_std_num_float64_decode(x, _ctx); /*(int, int)*/;
        {
          kk_box_t _box_x37 = _match_x669.fst;
          kk_box_t _box_x38 = _match_x669.snd;
          kk_integer_t m = kk_integer_unbox(_box_x37, _ctx);
          kk_integer_t e = kk_integer_unbox(_box_x38, _ctx);
          kk_integer_dup(e, _ctx);
          kk_integer_dup(m, _ctx);
          kk_std_core_types__tuple2_drop(_match_x669, _ctx);
          double _b_x39_49;
          double _x_x852 = kk_integer_as_double(m,kk_context()); /*float64*/
          _b_x39_49 = (_x_x852 * (0x1p-53)); /*float64*/
          kk_integer_t _b_x40_50 = kk_integer_add_small_const(e, 53, _ctx); /*int*/;
          return kk_std_core_types__new_Tuple2(kk_double_box(_b_x39_49, _ctx), kk_integer_box(_b_x40_50, _ctx), _ctx);
        }
      }
    }
    {
      kk_std_core_types__tuple2 _match_x667 = kk_std_num_float64_decode(x, _ctx); /*(int, int)*/;
      {
        kk_box_t _box_x41 = _match_x667.fst;
        kk_box_t _box_x42 = _match_x667.snd;
        kk_integer_t m_0 = kk_integer_unbox(_box_x41, _ctx);
        kk_integer_t e_0 = kk_integer_unbox(_box_x42, _ctx);
        kk_integer_dup(e_0, _ctx);
        kk_integer_dup(m_0, _ctx);
        kk_std_core_types__tuple2_drop(_match_x667, _ctx);
        double _b_x43_51;
        double _x_x853 = kk_integer_as_double(m_0,kk_context()); /*float64*/
        _b_x43_51 = (_x_x853 * (0x1p-53)); /*float64*/
        kk_integer_t _b_x44_52 = kk_integer_add_small_const(e_0, 53, _ctx); /*int*/;
        return kk_std_core_types__new_Tuple2(kk_double_box(_b_x43_51, _ctx), kk_integer_box(_b_x44_52, _ctx), _ctx);
      }
    }
  }
  {
    return kk_std_core_types__new_Tuple2(kk_double_box(x, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx);
  }
}
 
// Returns the greatest `:float64` less than `x`.
// This behaves exactly as `nextDown` in the IEEE 754-2008 standard.
// The identity `x.next-down == ~next-down(~x)` holds for all `x`.
// When `x` is finite `x == x.next-down.next-up` also holds.

double kk_std_num_float64_next_down(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  bool _match_x662 = isnan(x); /*bool*/;
  if (_match_x662) {
    return x;
  }
  {
    bool _match_x663 = (isinf(x) && signbit(x)); /*bool*/;
    if (_match_x663) {
      return x;
    }
    {
      bool _match_x664 = (x == (0x0p+0)); /*bool*/;
      if (_match_x664) {
        return (-(0x1p-1074));
      }
      {
        int64_t i = kk_std_num_float64_float64_to_bits(x, _ctx); /*int64*/;
        int64_t next;
        bool _match_x665 = 0 > i; /*bool*/;
        if (_match_x665) {
          int64_t _x_x854 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i + (uint64_t)_x_x854); /*int64*/
        }
        else {
          int64_t _x_x855 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i - (uint64_t)_x_x855); /*int64*/
        }
        return kk_std_num_float64_float64_from_bits(next, _ctx);
      }
    }
  }
}
 
// Returns the least `:float64` greater than `x`.
// This behaves exactly as `nextUp` in the IEEE 754-2008 standard.
// The identity `x.next-up == ~next-down(~x)` holds for all `x`.
// When `x` is finite `x == x.next-up.next-down` also holds.

double kk_std_num_float64_next_up(double x, kk_context_t* _ctx) { /* (x : float64) -> float64 */ 
  bool _match_x658 = isnan(x); /*bool*/;
  if (_match_x658) {
    return x;
  }
  {
    bool _match_x659 = (isinf(x) && !signbit(x)); /*bool*/;
    if (_match_x659) {
      return x;
    }
    {
      bool _match_x660 = (x == (0x0p+0)); /*bool*/;
      if (_match_x660) {
        return 0x1p-1074;
      }
      {
        int64_t i = kk_std_num_float64_float64_to_bits(x, _ctx); /*int64*/;
        int64_t next;
        bool _match_x661 = 0 > i; /*bool*/;
        if (_match_x661) {
          int64_t _x_x856 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i - (uint64_t)_x_x856); /*int64*/
        }
        else {
          int64_t _x_x857 = (KK_I64(1)); /*int64*/
          next = (int64_t)((uint64_t)i + (uint64_t)_x_x857); /*int64*/
        }
        return kk_std_num_float64_float64_from_bits(next, _ctx);
      }
    }
  }
}
 
// Compare floats using a total ordering on the `:float64`.
// The ordering follows the `totalOrder` predicate as defined in IEEE 754-2008 exactly.
// The values are ordered in following order:
// negative quiet nan,
// negative signaling nan,
// `neginf`,
// -finite,
// -0.0,
// +0.0,
// finite,
// `posinf`,
// signaling nan,
// and quiet nan.

kk_std_core_types__order kk_std_num_float64_cmp(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> order */ 
  int64_t bx = kk_std_num_float64_float64_to_bits(x, _ctx); /*int64*/;
  int64_t by = kk_std_num_float64_float64_to_bits(y, _ctx); /*int64*/;
  int64_t i_10058;
  int64_t _x_x858 = (KK_I64(63)); /*int64*/
  i_10058 = kk_sar64(bx,_x_x858); /*int64*/
  int64_t ix;
  int64_t _x_x859;
  int64_t _x_x860 = (KK_I64(1)); /*int64*/
  _x_x859 = (int64_t)kk_shr64(i_10058,_x_x860); /*int64*/
  ix = _x_x859 ^ bx; /*int64*/
  int64_t i_1_10062;
  int64_t _x_x861 = (KK_I64(63)); /*int64*/
  i_1_10062 = kk_sar64(by,_x_x861); /*int64*/
  int64_t iy;
  int64_t _x_x862;
  int64_t _x_x863 = (KK_I64(1)); /*int64*/
  _x_x862 = (int64_t)kk_shr64(i_1_10062,_x_x863); /*int64*/
  iy = _x_x862 ^ by; /*int64*/
  bool _match_x656 = (ix < iy); /*bool*/;
  if (_match_x656) {
    return kk_std_core_types__new_Lt(_ctx);
  }
  {
    bool _match_x657 = (ix > iy); /*bool*/;
    if (_match_x657) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Eq(_ctx);
    }
  }
}
 
// The midpoint is the average of `x` and `y`.
// Avoids overflow on large numbers.

double kk_std_num_float64_midpoint(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  bool _match_x650 = (x != (0x0p+0)); /*bool*/;
  if (_match_x650) {
    bool _match_x653;
    double _x_x864 = kk_double_abs(x); /*float64*/
    _match_x653 = (_x_x864 < (0x1p-1022)); /*bool*/
    if (_match_x653) {
      double _x_x865 = (x + y); /*float64*/
      return (_x_x865 / 0x1p1);
    }
    {
      bool _match_x654 = (y != (0x0p+0)); /*bool*/;
      if (_match_x654) {
        bool _match_x655;
        double _x_x866 = kk_double_abs(y); /*float64*/
        _match_x655 = (_x_x866 < (0x1p-1022)); /*bool*/
        if (_match_x655) {
          double _x_x867 = (x + y); /*float64*/
          return (_x_x867 / 0x1p1);
        }
        {
          double _x_x868 = (x / 0x1p1); /*float64*/
          double _x_x869 = (y / 0x1p1); /*float64*/
          return (_x_x868 + _x_x869);
        }
      }
      {
        double _x_x870 = (x / 0x1p1); /*float64*/
        double _x_x871 = (y / 0x1p1); /*float64*/
        return (_x_x870 + _x_x871);
      }
    }
  }
  {
    bool _match_x651 = (y != (0x0p+0)); /*bool*/;
    if (_match_x651) {
      bool _match_x652;
      double _x_x872 = kk_double_abs(y); /*float64*/
      _match_x652 = (_x_x872 < (0x1p-1022)); /*bool*/
      if (_match_x652) {
        double _x_x873 = (x + y); /*float64*/
        return (_x_x873 / 0x1p1);
      }
      {
        double _x_x874 = (x / 0x1p1); /*float64*/
        double _x_x875 = (y / 0x1p1); /*float64*/
        return (_x_x874 + _x_x875);
      }
    }
    {
      double _x_x876 = (x / 0x1p1); /*float64*/
      double _x_x877 = (y / 0x1p1); /*float64*/
      return (_x_x876 + _x_x877);
    }
  }
}
 
// Linear interpolation, calculating `x + t*(y - x)` but avoids troublesome edge cases.
// Follows the C++20 [specification](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0811r3.html).
// In particular, if `x.is-finite && y.is-finite`, then:
// - exact: `lerp(x,y,0.0) == x` and  `lerp(x,y,1.0) == y`
// - monotonic: if `x <= y` and `t1 <= t2`, then `cmp( lerp(x,y,t1), lerp(x,y,t2) ) <= Eq` (and other cases)
// - deterministic: only `lerp(x,x,flt-inf)` results in `nan`
// - bounded: `t<0.0 || t>1.0 || is-finite(lerp(x,y,t))`
// - consistent: `lerp(x,x,t) == x`

double kk_std_num_float64_lerp(double x, double y, double t, kk_context_t* _ctx) { /* (x : float64, y : float64, t : float64) -> float64 */ 
  bool _match_x628 = (x <= (0x0p+0)); /*bool*/;
  if (_match_x628) {
    bool _match_x639 = (y >= (0x0p+0)); /*bool*/;
    if (_match_x639) {
      double _x_x878 = (t * y); /*float64*/
      double _x_x879;
      double _x_x880 = (0x1p0 - t); /*float64*/
      _x_x879 = (_x_x880 * x); /*float64*/
      return (_x_x878 + _x_x879);
    }
    {
      bool _match_x640 = (x >= (0x0p+0)); /*bool*/;
      if (_match_x640) {
        bool _match_x645 = (y <= (0x0p+0)); /*bool*/;
        if (_match_x645) {
          double _x_x881 = (t * y); /*float64*/
          double _x_x882;
          double _x_x883 = (0x1p0 - t); /*float64*/
          _x_x882 = (_x_x883 * x); /*float64*/
          return (_x_x881 + _x_x882);
        }
        {
          bool _match_x646 = (t == 0x1p0); /*bool*/;
          if (_match_x646) {
            return y;
          }
          {
            double z;
            double _x_x884;
            double _x_x885 = (y - x); /*float64*/
            _x_x884 = (t * _x_x885); /*float64*/
            z = (x + _x_x884); /*float64*/
            bool x_0_10070 = (t > 0x1p0); /*bool*/;
            bool y_0_10071 = (y > x); /*bool*/;
            bool _match_x647;
            if (x_0_10070) {
              _match_x647 = y_0_10071; /*bool*/
            }
            else {
              if (y_0_10071) {
                _match_x647 = false; /*bool*/
              }
              else {
                _match_x647 = true; /*bool*/
              }
            }
            if (_match_x647) {
              bool _match_x649 = (y >= z); /*bool*/;
              if (_match_x649) {
                return y;
              }
              {
                return z;
              }
            }
            {
              bool _match_x648 = (y <= z); /*bool*/;
              if (_match_x648) {
                return y;
              }
              {
                return z;
              }
            }
          }
        }
      }
      {
        bool _match_x641 = (t == 0x1p0); /*bool*/;
        if (_match_x641) {
          return y;
        }
        {
          double z_0;
          double _x_x886;
          double _x_x887 = (y - x); /*float64*/
          _x_x886 = (t * _x_x887); /*float64*/
          z_0 = (x + _x_x886); /*float64*/
          bool x_3_10076 = (t > 0x1p0); /*bool*/;
          bool y_3_10077 = (y > x); /*bool*/;
          bool _match_x642;
          if (x_3_10076) {
            _match_x642 = y_3_10077; /*bool*/
          }
          else {
            if (y_3_10077) {
              _match_x642 = false; /*bool*/
            }
            else {
              _match_x642 = true; /*bool*/
            }
          }
          if (_match_x642) {
            bool _match_x644 = (y >= z_0); /*bool*/;
            if (_match_x644) {
              return y;
            }
            {
              return z_0;
            }
          }
          {
            bool _match_x643 = (y <= z_0); /*bool*/;
            if (_match_x643) {
              return y;
            }
            {
              return z_0;
            }
          }
        }
      }
    }
  }
  {
    bool _match_x629 = (x >= (0x0p+0)); /*bool*/;
    if (_match_x629) {
      bool _match_x634 = (y <= (0x0p+0)); /*bool*/;
      if (_match_x634) {
        double _x_x888 = (t * y); /*float64*/
        double _x_x889;
        double _x_x890 = (0x1p0 - t); /*float64*/
        _x_x889 = (_x_x890 * x); /*float64*/
        return (_x_x888 + _x_x889);
      }
      {
        bool _match_x635 = (t == 0x1p0); /*bool*/;
        if (_match_x635) {
          return y;
        }
        {
          double z_1;
          double _x_x891;
          double _x_x892 = (y - x); /*float64*/
          _x_x891 = (t * _x_x892); /*float64*/
          z_1 = (x + _x_x891); /*float64*/
          bool x_6_10082 = (t > 0x1p0); /*bool*/;
          bool y_6_10083 = (y > x); /*bool*/;
          bool _match_x636;
          if (x_6_10082) {
            _match_x636 = y_6_10083; /*bool*/
          }
          else {
            if (y_6_10083) {
              _match_x636 = false; /*bool*/
            }
            else {
              _match_x636 = true; /*bool*/
            }
          }
          if (_match_x636) {
            bool _match_x638 = (y >= z_1); /*bool*/;
            if (_match_x638) {
              return y;
            }
            {
              return z_1;
            }
          }
          {
            bool _match_x637 = (y <= z_1); /*bool*/;
            if (_match_x637) {
              return y;
            }
            {
              return z_1;
            }
          }
        }
      }
    }
    {
      bool _match_x630 = (t == 0x1p0); /*bool*/;
      if (_match_x630) {
        return y;
      }
      {
        double z_0_0;
        double _x_x893;
        double _x_x894 = (y - x); /*float64*/
        _x_x893 = (t * _x_x894); /*float64*/
        z_0_0 = (x + _x_x893); /*float64*/
        bool x_9_10088 = (t > 0x1p0); /*bool*/;
        bool y_9_10089 = (y > x); /*bool*/;
        bool _match_x631;
        if (x_9_10088) {
          _match_x631 = y_9_10089; /*bool*/
        }
        else {
          if (y_9_10089) {
            _match_x631 = false; /*bool*/
          }
          else {
            _match_x631 = true; /*bool*/
          }
        }
        if (_match_x631) {
          bool _match_x633 = (y >= z_0_0); /*bool*/;
          if (_match_x633) {
            return y;
          }
          {
            return z_0_0;
          }
        }
        {
          bool _match_x632 = (y <= z_0_0); /*bool*/;
          if (_match_x632) {
            return y;
          }
          {
            return z_0_0;
          }
        }
      }
    }
  }
}
 
// /* Show a float64 in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41).
// An advantage of this format is that it precisely represents the `:float64` and can
// reliably (and efficiently) be parsed back, i.e. `d.show-hex.parse-float64 == Just(d)`.
// The significant is the _hexadecimal_ fraction while the
// exponent after the `p` is the _decimal_ power of 2.
//  For example, ``0xA.Fp-10`` = (10 + 15/16)&middot;2^-10^  (not 2^-16^!) = 0.01068115234375.
//  Equivalently, ``0xA.Fp-10 == 0x5.78p-9 == 0x2.BCp-8 == 0x1.5Ep-7``.
// ```
// > flt-min.show-hex
// "0x1.0p-1022"
// > 0.1.show-hex
// "0x1.999999999999Ap-4"
// > flt-max.show-hex
// "0x1.FFFFFFFFFFFFFp+1023"
// > -0.0.show-hex
// "-0x0.0p+0"
// > nan.show-hex
// "NaN"
// > 0.01068115234375.show-hex
// "0x1.5Ep-7"
// ```
// .
// */

kk_string_t kk_std_num_float64_show_hex(double d, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (d : float64, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
  bool b_10094 = isfinite(d); /*bool*/;
  if (b_10094) {
    kk_std_core_types__tuple2 _match_x619 = kk_std_num_float64_decode(d, _ctx); /*(int, int)*/;
    {
      kk_box_t _box_x55 = _match_x619.fst;
      kk_box_t _box_x56 = _match_x619.snd;
      kk_integer_t m = kk_integer_unbox(_box_x55, _ctx);
      kk_integer_t e = kk_integer_unbox(_box_x56, _ctx);
      kk_integer_dup(e, _ctx);
      kk_integer_dup(m, _ctx);
      kk_std_core_types__tuple2_drop(_match_x619, _ctx);
      kk_string_t man;
      kk_integer_t _x_x895 = kk_integer_abs(m,kk_context()); /*int*/
      kk_std_core_types__optional _x_x896 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(1), _ctx), _ctx); /*? 7*/
      kk_std_core_types__optional _x_x897;
      kk_box_t _x_x898;
      bool _x_x899;
      if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
        kk_box_t _box_x58 = use_capitals._cons._Optional.value;
        bool _uniq_use_capitals_4010 = kk_bool_unbox(_box_x58);
        kk_std_core_types__optional_drop(use_capitals, _ctx);
        _x_x899 = _uniq_use_capitals_4010; /*bool*/
      }
      else {
        kk_std_core_types__optional_drop(use_capitals, _ctx);
        _x_x899 = true; /*bool*/
      }
      _x_x898 = kk_bool_box(_x_x899); /*7*/
      _x_x897 = kk_std_core_types__new_Optional(_x_x898, _ctx); /*? 7*/
      kk_std_core_types__optional _x_x900;
      kk_box_t _x_x901;
      kk_string_t _x_x902 = kk_string_empty(); /*string*/
      _x_x901 = kk_string_box(_x_x902); /*7*/
      _x_x900 = kk_std_core_types__new_Optional(_x_x901, _ctx); /*? 7*/
      man = kk_std_core_show_show_hex(_x_x895, _x_x896, _x_x897, _x_x900, _ctx); /*string*/
      kk_integer_t x_0_10097;
      kk_string_t _x_x904 = kk_string_dup(man, _ctx); /*string*/
      x_0_10097 = kk_std_core_string_chars_fs_count(_x_x904, _ctx); /*int*/
      kk_integer_t y_10096;
      kk_integer_t _x_x905 = kk_integer_add_small_const(x_0_10097, -1, _ctx); /*int*/
      y_10096 = kk_integer_mul((kk_integer_from_small(4)),_x_x905,kk_context()); /*int*/
      kk_integer_t exp0 = kk_integer_add(e,y_10096,kk_context()); /*int*/;
      kk_string_t exp;
      kk_string_t _x_x906;
      bool _match_x627 = kk_integer_gte_borrow(exp0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      if (_match_x627) {
        kk_define_string_literal(, _s_x907, 1, "+", _ctx)
        _x_x906 = kk_string_dup(_s_x907, _ctx); /*string*/
      }
      else {
        _x_x906 = kk_string_empty(); /*string*/
      }
      kk_string_t _x_x909 = kk_std_core_int_show(exp0, _ctx); /*string*/
      exp = kk_std_core_types__lp__plus__plus__rp_(_x_x906, _x_x909, _ctx); /*string*/
      kk_string_t s_10099;
      kk_string_t _x_x910;
      kk_string_t _x_x911 = kk_string_dup(man, _ctx); /*string*/
      _x_x910 = kk_std_core_sslice_tail(_x_x911, _ctx); /*string*/
      kk_string_t _x_x912;
      kk_define_string_literal(, _s_x913, 1, "0", _ctx)
      _x_x912 = kk_string_dup(_s_x913, _ctx); /*string*/
      s_10099 = kk_std_core_sslice_trim_right(_x_x910, _x_x912, _ctx); /*string*/
      kk_integer_t width_0_10100;
      bool _match_x624;
      kk_integer_t _brw_x625;
      if (kk_std_core_types__is_Optional(width, _ctx)) {
        kk_box_t _box_x64 = width._cons._Optional.value;
        kk_integer_t _uniq_width_4006 = kk_integer_unbox(_box_x64, _ctx);
        kk_integer_dup(_uniq_width_4006, _ctx);
        _brw_x625 = _uniq_width_4006; /*int*/
      }
      else {
        _brw_x625 = kk_integer_from_small(1); /*int*/
      }
      bool _brw_x626 = kk_integer_gte_borrow((kk_integer_from_small(1)),_brw_x625,kk_context()); /*bool*/;
      kk_integer_drop(_brw_x625, _ctx);
      _match_x624 = _brw_x626; /*bool*/
      if (_match_x624) {
        kk_std_core_types__optional_drop(width, _ctx);
        width_0_10100 = kk_integer_from_small(1); /*int*/
      }
      else {
        if (kk_std_core_types__is_Optional(width, _ctx)) {
          kk_box_t _box_x65 = width._cons._Optional.value;
          kk_integer_t _uniq_width_4006_0 = kk_integer_unbox(_box_x65, _ctx);
          kk_integer_dup(_uniq_width_4006_0, _ctx);
          kk_std_core_types__optional_drop(width, _ctx);
          width_0_10100 = _uniq_width_4006_0; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(width, _ctx);
          width_0_10100 = kk_integer_from_small(1); /*int*/
        }
      }
      kk_integer_t n;
      kk_string_t _x_x914 = kk_string_dup(s_10099, _ctx); /*string*/
      n = kk_std_core_string_chars_fs_count(_x_x914, _ctx); /*int*/
      kk_string_t frac;
      bool _match_x623 = kk_integer_lte_borrow(width_0_10100,n,kk_context()); /*bool*/;
      if (_match_x623) {
        kk_integer_drop(width_0_10100, _ctx);
        kk_integer_drop(n, _ctx);
        frac = s_10099; /*string*/
      }
      else {
        kk_string_t s_0_10015 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10016 = kk_integer_sub(width_0_10100,n,kk_context()); /*int*/;
        kk_string_t _x_x915 = kk_std_core_string_repeatz(s_0_10015, kk_std_core_int_ssize__t(n_0_10016, _ctx), _ctx); /*string*/
        frac = kk_std_core_types__lp__plus__plus__rp_(s_10099, _x_x915, _ctx); /*string*/
      }
      kk_string_t sign_0;
      bool _match_x620 = (d < (0x0p+0)); /*bool*/;
      if (_match_x620) {
        kk_define_string_literal(, _s_x916, 1, "-", _ctx)
        sign_0 = kk_string_dup(_s_x916, _ctx); /*string*/
      }
      else {
        bool _match_x621 = (d == (0x0p+0)); /*bool*/;
        if (_match_x621) {
          bool _match_x622;
          double _x_x917 = (0x1p0 / d); /*float64*/
          _match_x622 = (isinf(_x_x917) && signbit(_x_x917)); /*bool*/
          if (_match_x622) {
            kk_define_string_literal(, _s_x918, 1, "-", _ctx)
            sign_0 = kk_string_dup(_s_x918, _ctx); /*string*/
          }
          else {
            sign_0 = kk_string_empty(); /*string*/
          }
        }
        else {
          sign_0 = kk_string_empty(); /*string*/
        }
      }
      kk_string_t _x_x921;
      kk_string_t _x_x922;
      if (kk_std_core_types__is_Optional(pre, _ctx)) {
        kk_box_t _box_x66 = pre._cons._Optional.value;
        kk_string_t _uniq_pre_4014 = kk_string_unbox(_box_x66);
        kk_string_dup(_uniq_pre_4014, _ctx);
        kk_std_core_types__optional_drop(pre, _ctx);
        _x_x922 = _uniq_pre_4014; /*string*/
      }
      else {
        kk_std_core_types__optional_drop(pre, _ctx);
        kk_define_string_literal(, _s_x923, 2, "0x", _ctx)
        _x_x922 = kk_string_dup(_s_x923, _ctx); /*string*/
      }
      kk_string_t _x_x924;
      kk_string_t _x_x925 = kk_std_core_sslice_head(man, _ctx); /*string*/
      kk_string_t _x_x926;
      kk_string_t _x_x927;
      kk_define_string_literal(, _s_x928, 1, ".", _ctx)
      _x_x927 = kk_string_dup(_s_x928, _ctx); /*string*/
      kk_string_t _x_x929;
      kk_string_t _x_x930;
      kk_string_t _x_x931;
      kk_define_string_literal(, _s_x932, 1, "p", _ctx)
      _x_x931 = kk_string_dup(_s_x932, _ctx); /*string*/
      _x_x930 = kk_std_core_types__lp__plus__plus__rp_(_x_x931, exp, _ctx); /*string*/
      _x_x929 = kk_std_core_types__lp__plus__plus__rp_(frac, _x_x930, _ctx); /*string*/
      _x_x926 = kk_std_core_types__lp__plus__plus__rp_(_x_x927, _x_x929, _ctx); /*string*/
      _x_x924 = kk_std_core_types__lp__plus__plus__rp_(_x_x925, _x_x926, _ctx); /*string*/
      _x_x921 = kk_std_core_types__lp__plus__plus__rp_(_x_x922, _x_x924, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(sign_0, _x_x921, _ctx);
    }
  }
  {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    return kk_std_num_float64_show(d, kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// monadic lift

double kk_std_num_float64__mlift_phexdouble_10402(kk_string_t frac, kk_string_t man, kk_integer_t _c_x10360, kk_context_t* _ctx) { /* (frac : string, man : string, int) -> float64 */ 
  kk_string_t _x_x1_0_10396;
  kk_string_t _x_x933 = kk_string_dup(frac, _ctx); /*string*/
  _x_x1_0_10396 = kk_std_core_types__lp__plus__plus__rp_(man, _x_x933, _ctx); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_core_types__maybe x = kk_std_core_int_xparse(_x_x1_0_10396, true, _ctx); /*maybe<int>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_integer_t y_10391;
  kk_integer_t _x_x934 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/
  y_10391 = kk_integer_mul((kk_integer_from_small(4)),_x_x934,kk_context()); /*int*/
  kk_integer_t e = kk_integer_sub(_c_x10360,y_10391,kk_context()); /*int*/;
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  double x_2;
  double _x_x935;
  kk_integer_t _x_x936;
  if (kk_std_core_types__is_Nothing(x, _ctx)) {
    _x_x936 = kk_integer_from_small(0); /*int*/
  }
  else {
    kk_box_t _box_x67 = x._cons.Just.value;
    kk_integer_t x_1 = kk_integer_unbox(_box_x67, _ctx);
    kk_integer_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(x, _ctx);
    _x_x936 = x_1; /*int*/
  }
  _x_x935 = kk_integer_as_double(_x_x936,kk_context()); /*float64*/
  x_2 = kk_std_num_float64_ldexp(_x_x935, e, _ctx); /*float64*/
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  return x_2;
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10403_fun940__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10403_fun940(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10403_fun940(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_phexdouble_10403_fun940, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10403_fun940(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x941;
  kk_char_t _x_x942 = kk_char_unbox(_b_x69, KK_OWNED, _ctx); /*char*/
  _x_x941 = kk_std_num_float64__mlift_phexdouble_10401(_x_x942, _ctx); /*int*/
  return kk_integer_box(_x_x941, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10403_fun944__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t man;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10403_fun944(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10403_fun944(kk_string_t frac, kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10403_fun944__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_phexdouble_10403_fun944__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_phexdouble_10403_fun944, kk_context());
  _self->frac = frac;
  _self->man = man;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10403_fun944(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10403_fun944__t* _self = kk_function_as(struct kk_std_num_float64__mlift_phexdouble_10403_fun944__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(man, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10360_74 = kk_integer_unbox(_b_x72, _ctx); /*int*/;
  double _x_x945 = kk_std_num_float64__mlift_phexdouble_10402(frac, man, _c_x10360_74, _ctx); /*float64*/
  return kk_double_box(_x_x945, _ctx);
}

double kk_std_num_float64__mlift_phexdouble_10403(kk_string_t frac, kk_string_t man, bool _y_x10357, kk_context_t* _ctx) { /* (frac : string, man : string, bool) -> std/text/parse/parse float64 */ 
  kk_integer_t x_10439;
  if (_y_x10357) {
    kk_char_t x_0_10441;
    kk_string_t _x_x937;
    kk_define_string_literal(, _s_x938, 2, "pP", _ctx)
    _x_x937 = kk_string_dup(_s_x938, _ctx); /*string*/
    x_0_10441 = kk_std_text_parse_one_of(_x_x937, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x939 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10403_fun940(_ctx), _ctx); /*2419*/
      x_10439 = kk_integer_unbox(_x_x939, _ctx); /*int*/
    }
    else {
      x_10439 = kk_std_text_parse_pint(_ctx); /*int*/
    }
  }
  else {
    x_10439 = kk_integer_from_small(0); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10439, _ctx);
    kk_box_t _x_x943 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10403_fun944(frac, man, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x943, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_phexdouble_10402(frac, man, x_10439, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10405_fun951__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t man;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10405_fun951(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10405_fun951(kk_string_t frac, kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10405_fun951__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_phexdouble_10405_fun951__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_phexdouble_10405_fun951, kk_context());
  _self->frac = frac;
  _self->man = man;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10405_fun951(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10405_fun951__t* _self = kk_function_as(struct kk_std_num_float64__mlift_phexdouble_10405_fun951__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(man, _ctx);}, {}, _ctx)
  bool _y_x10357_84 = kk_bool_unbox(_b_x82); /*bool*/;
  double _x_x952 = kk_std_num_float64__mlift_phexdouble_10403(frac, man, _y_x10357_84, _ctx); /*float64*/
  return kk_double_box(_x_x952, _ctx);
}

double kk_std_num_float64__mlift_phexdouble_10405(kk_string_t man, kk_string_t _c_x10356, kk_context_t* _ctx) { /* (man : string, string) -> float64 */ 
  kk_string_t frac;
  kk_string_t _x_x946;
  kk_define_string_literal(, _s_x947, 1, "0", _ctx)
  _x_x946 = kk_string_dup(_s_x947, _ctx); /*string*/
  frac = kk_std_core_sslice_trim_right(_c_x10356, _x_x946, _ctx); /*string*/
  kk_std_core_hnd__ev ev_10445 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10443;
  kk_box_t _x_x948;
  {
    struct kk_std_core_hnd_Ev* _con_x949 = kk_std_core_hnd__as_Ev(ev_10445, _ctx);
    kk_box_t _box_x75 = _con_x949->hnd;
    int32_t m = _con_x949->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x75, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x615;
    kk_std_core_hnd__clause0 _brw_x616 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x615 = _brw_x616; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x78 = _match_x615.clause;
      _x_x948 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x78, (_fun_unbox_x78, m, ev_10445, _ctx), _ctx); /*35*/
    }
  }
  x_10443 = kk_bool_unbox(_x_x948); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x950 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10405_fun951(frac, man, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x950, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_phexdouble_10403(frac, man, x_10443, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10406_fun954__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10406_fun954(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10406_fun954(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_phexdouble_10406_fun954, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10406_fun954(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x955;
  kk_char_t _x_x956 = kk_char_unbox(_b_x86, KK_OWNED, _ctx); /*char*/
  _x_x955 = kk_std_num_float64__mlift_phexdouble_10404(_x_x956, _ctx); /*string*/
  return kk_string_box(_x_x955);
}


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10406_fun959__t {
  struct kk_function_s _base;
  kk_string_t man;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10406_fun959(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10406_fun959(kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10406_fun959__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_phexdouble_10406_fun959__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_phexdouble_10406_fun959, kk_context());
  _self->man = man;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10406_fun959(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10406_fun959__t* _self = kk_function_as(struct kk_std_num_float64__mlift_phexdouble_10406_fun959__t*, _fself, _ctx);
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(man, _ctx);}, {}, _ctx)
  kk_string_t _c_x10356_91 = kk_string_unbox(_b_x89); /*string*/;
  double _x_x960 = kk_std_num_float64__mlift_phexdouble_10405(man, _c_x10356_91, _ctx); /*float64*/
  return kk_double_box(_x_x960, _ctx);
}

double kk_std_num_float64__mlift_phexdouble_10406(kk_string_t man, bool _y_x10353, kk_context_t* _ctx) { /* (man : string, bool) -> std/text/parse/parse float64 */ 
  kk_string_t x_10447;
  if (_y_x10353) {
    kk_char_t x_0_10449 = kk_std_text_parse_char('.', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x953 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10406_fun954(_ctx), _ctx); /*2419*/
      x_10447 = kk_string_unbox(_x_x953); /*string*/
    }
    else {
      x_10447 = kk_std_text_parse_hex_digits(_ctx); /*string*/
    }
  }
  else {
    x_10447 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10447, _ctx);
    kk_box_t _x_x958 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10406_fun959(man, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x958, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_phexdouble_10405(man, x_10447, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10407_fun964__t {
  struct kk_function_s _base;
  kk_string_t man;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10407_fun964(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10407_fun964(kk_string_t man, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10407_fun964__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_phexdouble_10407_fun964__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_phexdouble_10407_fun964, kk_context());
  _self->man = man;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10407_fun964(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_phexdouble_10407_fun964__t* _self = kk_function_as(struct kk_std_num_float64__mlift_phexdouble_10407_fun964__t*, _fself, _ctx);
  kk_string_t man = _self->man; /* string */
  kk_drop_match(_self, {kk_string_dup(man, _ctx);}, {}, _ctx)
  bool _y_x10353_101 = kk_bool_unbox(_b_x99); /*bool*/;
  double _x_x965 = kk_std_num_float64__mlift_phexdouble_10406(man, _y_x10353_101, _ctx); /*float64*/
  return kk_double_box(_x_x965, _ctx);
}

double kk_std_num_float64__mlift_phexdouble_10407(kk_string_t man, kk_context_t* _ctx) { /* (man : string) -> std/text/parse/parse float64 */ 
  kk_std_core_hnd__ev ev_10453 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10451;
  kk_box_t _x_x961;
  {
    struct kk_std_core_hnd_Ev* _con_x962 = kk_std_core_hnd__as_Ev(ev_10453, _ctx);
    kk_box_t _box_x92 = _con_x962->hnd;
    int32_t m = _con_x962->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x92, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x610;
    kk_std_core_hnd__clause0 _brw_x611 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x610 = _brw_x611; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x95 = _match_x610.clause;
      _x_x961 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x95, (_fun_unbox_x95, m, ev_10453, _ctx), _ctx); /*35*/
    }
  }
  x_10451 = kk_bool_unbox(_x_x961); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x963 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10407_fun964(man, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x963, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_phexdouble_10406(man, x_10451, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10408_fun967__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10408_fun967(kk_function_t _fself, kk_box_t _b_x103, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10408_fun967(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_phexdouble_10408_fun967, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10408_fun967(kk_function_t _fself, kk_box_t _b_x103, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x968;
  kk_string_t _x_x969 = kk_string_unbox(_b_x103); /*string*/
  _x_x968 = kk_std_num_float64__mlift_phexdouble_10407(_x_x969, _ctx); /*float64*/
  return kk_double_box(_x_x968, _ctx);
}

double kk_std_num_float64__mlift_phexdouble_10408(kk_char_t wild___0, kk_context_t* _ctx) { /* (wild_@0 : char) -> std/text/parse/parse float64 */ 
  kk_string_t x_10455 = kk_std_text_parse_hex_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10455, _ctx);
    kk_box_t _x_x966 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10408_fun967(_ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x966, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_phexdouble_10407(x_10455, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_phexdouble_10409_fun973__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_phexdouble_10409_fun973(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_phexdouble_10409_fun973(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_phexdouble_10409_fun973, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_phexdouble_10409_fun973(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x974;
  kk_char_t _x_x975 = kk_char_unbox(_b_x106, KK_OWNED, _ctx); /*char*/
  _x_x974 = kk_std_num_float64__mlift_phexdouble_10408(_x_x975, _ctx); /*float64*/
  return kk_double_box(_x_x974, _ctx);
}

double kk_std_num_float64__mlift_phexdouble_10409(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse float64 */ 
  kk_char_t x_10457;
  kk_string_t _x_x970;
  kk_define_string_literal(, _s_x971, 2, "xX", _ctx)
  _x_x970 = kk_string_dup(_s_x971, _ctx); /*string*/
  x_10457 = kk_std_text_parse_one_of(_x_x970, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x972 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_phexdouble_10409_fun973(_ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x972, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_phexdouble_10408(x_10457, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun977__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun977(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun977(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun977, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun977(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x978;
  kk_char_t _x_x979 = kk_char_unbox(_b_x109, KK_OWNED, _ctx); /*char*/
  _x_x978 = kk_std_num_float64__mlift_phexdouble_10409(_x_x979, _ctx); /*float64*/
  return kk_double_box(_x_x978, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun983__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun983(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun983(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun983, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun983(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x984;
  kk_char_t _x_x985 = kk_char_unbox(_b_x111, KK_OWNED, _ctx); /*char*/
  _x_x984 = kk_std_num_float64__mlift_phexdouble_10408(_x_x985, _ctx); /*float64*/
  return kk_double_box(_x_x984, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun987__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun987(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun987(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun987, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun987(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x988;
  kk_string_t _x_x989 = kk_string_unbox(_b_x113); /*string*/
  _x_x988 = kk_std_num_float64__mlift_phexdouble_10407(_x_x989, _ctx); /*float64*/
  return kk_double_box(_x_x988, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun993__t {
  struct kk_function_s _base;
  kk_string_t x_1_10465;
};
static kk_box_t kk_std_num_float64_phexdouble_fun993(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun993(kk_string_t x_1_10465, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun993__t* _self = kk_function_alloc_as(struct kk_std_num_float64_phexdouble_fun993__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_phexdouble_fun993, kk_context());
  _self->x_1_10465 = x_1_10465;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun993(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun993__t* _self = kk_function_as(struct kk_std_num_float64_phexdouble_fun993__t*, _fself, _ctx);
  kk_string_t x_1_10465 = _self->x_1_10465; /* string */
  kk_drop_match(_self, {kk_string_dup(x_1_10465, _ctx);}, {}, _ctx)
  bool _y_x10353_148 = kk_bool_unbox(_b_x121); /*bool*/;
  double _x_x994 = kk_std_num_float64__mlift_phexdouble_10406(x_1_10465, _y_x10353_148, _ctx); /*float64*/
  return kk_double_box(_x_x994, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun996__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun996(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun996(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun996, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun996(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x997;
  kk_char_t _x_x998 = kk_char_unbox(_b_x123, KK_OWNED, _ctx); /*char*/
  _x_x997 = kk_std_num_float64__mlift_phexdouble_10404(_x_x998, _ctx); /*string*/
  return kk_string_box(_x_x997);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun1001__t {
  struct kk_function_s _base;
  kk_string_t x_1_10465;
};
static kk_box_t kk_std_num_float64_phexdouble_fun1001(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun1001(kk_string_t x_1_10465, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun1001__t* _self = kk_function_alloc_as(struct kk_std_num_float64_phexdouble_fun1001__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_phexdouble_fun1001, kk_context());
  _self->x_1_10465 = x_1_10465;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun1001(kk_function_t _fself, kk_box_t _b_x126, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun1001__t* _self = kk_function_as(struct kk_std_num_float64_phexdouble_fun1001__t*, _fself, _ctx);
  kk_string_t x_1_10465 = _self->x_1_10465; /* string */
  kk_drop_match(_self, {kk_string_dup(x_1_10465, _ctx);}, {}, _ctx)
  kk_string_t _c_x10356_149 = kk_string_unbox(_b_x126); /*string*/;
  double _x_x1002 = kk_std_num_float64__mlift_phexdouble_10405(x_1_10465, _c_x10356_149, _ctx); /*float64*/
  return kk_double_box(_x_x1002, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun1008__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x_1_10465;
};
static kk_box_t kk_std_num_float64_phexdouble_fun1008(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun1008(kk_string_t frac, kk_string_t x_1_10465, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun1008__t* _self = kk_function_alloc_as(struct kk_std_num_float64_phexdouble_fun1008__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_phexdouble_fun1008, kk_context());
  _self->frac = frac;
  _self->x_1_10465 = x_1_10465;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun1008(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun1008__t* _self = kk_function_as(struct kk_std_num_float64_phexdouble_fun1008__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x_1_10465 = _self->x_1_10465; /* string */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(x_1_10465, _ctx);}, {}, _ctx)
  bool _y_x10357_150 = kk_bool_unbox(_b_x134); /*bool*/;
  double _x_x1009 = kk_std_num_float64__mlift_phexdouble_10403(frac, x_1_10465, _y_x10357_150, _ctx); /*float64*/
  return kk_double_box(_x_x1009, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun1013__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_phexdouble_fun1013(kk_function_t _fself, kk_box_t _b_x136, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun1013(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_phexdouble_fun1013, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun1013(kk_function_t _fself, kk_box_t _b_x136, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1014;
  kk_char_t _x_x1015 = kk_char_unbox(_b_x136, KK_OWNED, _ctx); /*char*/
  _x_x1014 = kk_std_num_float64__mlift_phexdouble_10401(_x_x1015, _ctx); /*int*/
  return kk_integer_box(_x_x1014, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_phexdouble_fun1017__t {
  struct kk_function_s _base;
  kk_string_t frac;
  kk_string_t x_1_10465;
};
static kk_box_t kk_std_num_float64_phexdouble_fun1017(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_phexdouble_fun1017(kk_string_t frac, kk_string_t x_1_10465, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun1017__t* _self = kk_function_alloc_as(struct kk_std_num_float64_phexdouble_fun1017__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_phexdouble_fun1017, kk_context());
  _self->frac = frac;
  _self->x_1_10465 = x_1_10465;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_phexdouble_fun1017(kk_function_t _fself, kk_box_t _b_x139, kk_context_t* _ctx) {
  struct kk_std_num_float64_phexdouble_fun1017__t* _self = kk_function_as(struct kk_std_num_float64_phexdouble_fun1017__t*, _fself, _ctx);
  kk_string_t frac = _self->frac; /* string */
  kk_string_t x_1_10465 = _self->x_1_10465; /* string */
  kk_drop_match(_self, {kk_string_dup(frac, _ctx);kk_string_dup(x_1_10465, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10360_151 = kk_integer_unbox(_b_x139, _ctx); /*int*/;
  double _x_x1018 = kk_std_num_float64__mlift_phexdouble_10402(frac, x_1_10465, _c_x10360_151, _ctx); /*float64*/
  return kk_double_box(_x_x1018, _ctx);
}

double kk_std_num_float64_phexdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  kk_char_t x_10459 = kk_std_text_parse_char('0', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x976 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun977(_ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x976, KK_OWNED, _ctx);
  }
  {
    kk_char_t x_0_10462;
    kk_string_t _x_x980;
    kk_define_string_literal(, _s_x981, 2, "xX", _ctx)
    _x_x980 = kk_string_dup(_s_x981, _ctx); /*string*/
    x_0_10462 = kk_std_text_parse_one_of(_x_x980, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x982 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun983(_ctx), _ctx); /*2419*/
      return kk_double_unbox(_x_x982, KK_OWNED, _ctx);
    }
    {
      kk_string_t x_1_10465 = kk_std_text_parse_hex_digits(_ctx); /*string*/;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10465, _ctx);
        kk_box_t _x_x986 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun987(_ctx), _ctx); /*2419*/
        return kk_double_unbox(_x_x986, KK_OWNED, _ctx);
      }
      {
        kk_std_core_hnd__ev ev_10471 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        bool x_2_10468;
        kk_box_t _x_x990;
        {
          struct kk_std_core_hnd_Ev* _con_x991 = kk_std_core_hnd__as_Ev(ev_10471, _ctx);
          kk_box_t _box_x114 = _con_x991->hnd;
          int32_t m = _con_x991->marker;
          kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x114, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h, _ctx);
          kk_std_core_hnd__clause0 _match_x605;
          kk_std_core_hnd__clause0 _brw_x606 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
          kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
          _match_x605 = _brw_x606; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
          {
            kk_function_t _fun_unbox_x117 = _match_x605.clause;
            _x_x990 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x117, (_fun_unbox_x117, m, ev_10471, _ctx), _ctx); /*35*/
          }
        }
        x_2_10468 = kk_bool_unbox(_x_x990); /*bool*/
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x992 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun993(x_1_10465, _ctx), _ctx); /*2419*/
          return kk_double_unbox(_x_x992, KK_OWNED, _ctx);
        }
        {
          kk_string_t x_3_10473;
          if (x_2_10468) {
            kk_char_t x_4_10476 = kk_std_text_parse_char('.', _ctx); /*char*/;
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x995 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun996(_ctx), _ctx); /*2419*/
              x_3_10473 = kk_string_unbox(_x_x995); /*string*/
            }
            else {
              x_3_10473 = kk_std_text_parse_hex_digits(_ctx); /*string*/
            }
          }
          else {
            x_3_10473 = kk_string_empty(); /*string*/
          }
          if (kk_yielding(kk_context())) {
            kk_string_drop(x_3_10473, _ctx);
            kk_box_t _x_x1000 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun1001(x_1_10465, _ctx), _ctx); /*2419*/
            return kk_double_unbox(_x_x1000, KK_OWNED, _ctx);
          }
          {
            kk_string_t frac;
            kk_string_t _x_x1003;
            kk_define_string_literal(, _s_x1004, 1, "0", _ctx)
            _x_x1003 = kk_string_dup(_s_x1004, _ctx); /*string*/
            frac = kk_std_core_sslice_trim_right(x_3_10473, _x_x1003, _ctx); /*string*/
            kk_std_core_hnd__ev ev_0_10481 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
            bool x_5_10478;
            kk_box_t _x_x1005;
            {
              struct kk_std_core_hnd_Ev* _con_x1006 = kk_std_core_hnd__as_Ev(ev_0_10481, _ctx);
              kk_box_t _box_x127 = _con_x1006->hnd;
              int32_t m_0 = _con_x1006->marker;
              kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x127, KK_BORROWED, _ctx);
              kk_std_text_parse__parse_dup(h_0, _ctx);
              kk_std_core_hnd__clause0 _match_x602;
              kk_std_core_hnd__clause0 _brw_x603 = kk_std_text_parse_pick_fs__select(h_0, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
              kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
              _match_x602 = _brw_x603; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
              {
                kk_function_t _fun_unbox_x130 = _match_x602.clause;
                _x_x1005 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x130, (_fun_unbox_x130, m_0, ev_0_10481, _ctx), _ctx); /*35*/
              }
            }
            x_5_10478 = kk_bool_unbox(_x_x1005); /*bool*/
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x1007 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun1008(frac, x_1_10465, _ctx), _ctx); /*2419*/
              return kk_double_unbox(_x_x1007, KK_OWNED, _ctx);
            }
            {
              kk_integer_t x_6_10483;
              if (x_5_10478) {
                kk_char_t x_7_10486;
                kk_string_t _x_x1010;
                kk_define_string_literal(, _s_x1011, 2, "pP", _ctx)
                _x_x1010 = kk_string_dup(_s_x1011, _ctx); /*string*/
                x_7_10486 = kk_std_text_parse_one_of(_x_x1010, _ctx); /*char*/
                if (kk_yielding(kk_context())) {
                  kk_box_t _x_x1012 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun1013(_ctx), _ctx); /*2419*/
                  x_6_10483 = kk_integer_unbox(_x_x1012, _ctx); /*int*/
                }
                else {
                  x_6_10483 = kk_std_text_parse_pint(_ctx); /*int*/
                }
              }
              else {
                x_6_10483 = kk_integer_from_small(0); /*int*/
              }
              if (kk_yielding(kk_context())) {
                kk_integer_drop(x_6_10483, _ctx);
                kk_box_t _x_x1016 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_phexdouble_fun1017(frac, x_1_10465, _ctx), _ctx); /*2419*/
                return kk_double_unbox(_x_x1016, KK_OWNED, _ctx);
              }
              {
                kk_string_t _x_x1_0_10396;
                kk_string_t _x_x1019 = kk_string_dup(frac, _ctx); /*string*/
                _x_x1_0_10396 = kk_std_core_types__lp__plus__plus__rp_(x_1_10465, _x_x1019, _ctx); /*string*/
                kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                kk_std_core_types__maybe x_8 = kk_std_core_int_xparse(_x_x1_0_10396, true, _ctx); /*maybe<int>*/;
                kk_unit_t keep = kk_Unit;
                kk_evv_set(w,kk_context());
                kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                kk_unit_t keep_0 = kk_Unit;
                kk_evv_set(w_0,kk_context());
                kk_integer_t y_10391;
                kk_integer_t _x_x1020 = kk_std_core_string_chars_fs_count(frac, _ctx); /*int*/
                y_10391 = kk_integer_mul((kk_integer_from_small(4)),_x_x1020,kk_context()); /*int*/
                kk_integer_t e = kk_integer_sub(x_6_10483,y_10391,kk_context()); /*int*/;
                kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
                double x_11;
                double _x_x1021;
                kk_integer_t _x_x1022;
                if (kk_std_core_types__is_Nothing(x_8, _ctx)) {
                  _x_x1022 = kk_integer_from_small(0); /*int*/
                }
                else {
                  kk_box_t _box_x140 = x_8._cons.Just.value;
                  kk_integer_t x_10 = kk_integer_unbox(_box_x140, _ctx);
                  kk_integer_dup(x_10, _ctx);
                  kk_std_core_types__maybe_drop(x_8, _ctx);
                  _x_x1022 = x_10; /*int*/
                }
                _x_x1021 = kk_integer_as_double(_x_x1022,kk_context()); /*float64*/
                x_11 = kk_std_num_float64_ldexp(_x_x1021, e, _ctx); /*float64*/
                kk_unit_t keep_1 = kk_Unit;
                kk_evv_set(w_1,kk_context());
                return x_11;
              }
            }
          }
        }
      }
    }
  }
}
 
// Return `nan` on failure

double kk_std_num_float64_prim_parse_float64(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> float64 */ 
  return kk_prim_parse_double(s,kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10411_fun1024__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10411_fun1024(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10411_fun1024(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdecdouble_10411_fun1024, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10411_fun1024(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1025;
  kk_string_t _x_x1026 = kk_string_unbox(_b_x154); /*string*/
  _x_x1025 = kk_std_num_float64_prim_parse_float64(_x_x1026, _ctx); /*float64*/
  return kk_double_box(_x_x1025, _ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10411(kk_std_core_sslice__sslice cur, kk_integer_t _c_x10370, kk_context_t* _ctx) { /* (cur : sslice/sslice, int) -> float64 */ 
  kk_integer_drop(_c_x10370, _ctx);
  kk_string_t _x_x1_10400 = kk_std_core_sslice_string(cur, _ctx); /*string*/;
  kk_box_t _x_x1023 = kk_std_core_hnd__open_none1(kk_std_num_float64__new_mlift_pdecdouble_10411_fun1024(_ctx), kk_string_box(_x_x1_10400), _ctx); /*9904*/
  return kk_double_unbox(_x_x1023, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10412_fun1030__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10412_fun1030(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10412_fun1030(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdecdouble_10412_fun1030, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10412_fun1030(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1031;
  kk_char_t _x_x1032 = kk_char_unbox(_b_x158, KK_OWNED, _ctx); /*char*/
  _x_x1031 = kk_std_num_float64__mlift_pdecdouble_10410(_x_x1032, _ctx); /*int*/
  return kk_integer_box(_x_x1031, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10412_fun1033__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice cur;
};
static double kk_std_num_float64__mlift_pdecdouble_10412_fun1033(kk_function_t _fself, kk_integer_t _c_x10370, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10412_fun1033(kk_std_core_sslice__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10412_fun1033__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdecdouble_10412_fun1033__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdecdouble_10412_fun1033, kk_context());
  _self->cur = cur;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10412_fun1035__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10412_fun1035(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10412_fun1035(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdecdouble_10412_fun1035, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10412_fun1035(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1036;
  kk_string_t _x_x1037 = kk_string_unbox(_b_x162); /*string*/
  _x_x1036 = kk_std_num_float64_prim_parse_float64(_x_x1037, _ctx); /*float64*/
  return kk_double_box(_x_x1036, _ctx);
}
static double kk_std_num_float64__mlift_pdecdouble_10412_fun1033(kk_function_t _fself, kk_integer_t _c_x10370, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10412_fun1033__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdecdouble_10412_fun1033__t*, _fself, _ctx);
  kk_std_core_sslice__sslice cur = _self->cur; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(cur, _ctx);}, {}, _ctx)
  kk_integer_drop(_c_x10370, _ctx);
  kk_string_t _x_x1_10400 = kk_std_core_sslice_string(cur, _ctx); /*string*/;
  kk_box_t _x_x1034 = kk_std_core_hnd__open_none1(kk_std_num_float64__new_mlift_pdecdouble_10412_fun1035(_ctx), kk_string_box(_x_x1_10400), _ctx); /*9904*/
  return kk_double_unbox(_x_x1034, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10412_fun1039__t {
  struct kk_function_s _base;
  kk_function_t next_10498;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10412_fun1039(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10412_fun1039(kk_function_t next_10498, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10412_fun1039__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdecdouble_10412_fun1039__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdecdouble_10412_fun1039, kk_context());
  _self->next_10498 = next_10498;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10412_fun1039(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10412_fun1039__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdecdouble_10412_fun1039__t*, _fself, _ctx);
  kk_function_t next_10498 = _self->next_10498; /* (int) -> float64 */
  kk_drop_match(_self, {kk_function_dup(next_10498, _ctx);}, {}, _ctx)
  double _x_x1040;
  kk_integer_t _x_x1041 = kk_integer_unbox(_b_x166, _ctx); /*int*/
  _x_x1040 = kk_function_call(double, (kk_function_t, kk_integer_t, kk_context_t*), next_10498, (next_10498, _x_x1041, _ctx), _ctx); /*float64*/
  return kk_double_box(_x_x1040, _ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10412(kk_std_core_sslice__sslice cur, bool _y_x10367, kk_context_t* _ctx) { /* (cur : sslice/sslice, bool) -> std/text/parse/parse float64 */ 
  kk_integer_t x_10497;
  if (_y_x10367) {
    kk_char_t x_0_10499;
    kk_string_t _x_x1027;
    kk_define_string_literal(, _s_x1028, 2, "eE", _ctx)
    _x_x1027 = kk_string_dup(_s_x1028, _ctx); /*string*/
    x_0_10499 = kk_std_text_parse_one_of(_x_x1027, _ctx); /*char*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1029 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10412_fun1030(_ctx), _ctx); /*2419*/
      x_10497 = kk_integer_unbox(_x_x1029, _ctx); /*int*/
    }
    else {
      x_10497 = kk_std_text_parse_pint(_ctx); /*int*/
    }
  }
  else {
    x_10497 = kk_integer_from_small(0); /*int*/
  }
  kk_function_t next_10498 = kk_std_num_float64__new_mlift_pdecdouble_10412_fun1033(cur, _ctx); /*(int) -> float64*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10497, _ctx);
    kk_box_t _x_x1038 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10412_fun1039(next_10498, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1038, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(double, (kk_function_t, kk_integer_t, kk_context_t*), next_10498, (next_10498, x_10497, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10414_fun1047__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice cur;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10414_fun1047(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10414_fun1047(kk_std_core_sslice__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10414_fun1047__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdecdouble_10414_fun1047__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdecdouble_10414_fun1047, kk_context());
  _self->cur = cur;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10414_fun1047(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10414_fun1047__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdecdouble_10414_fun1047__t*, _fself, _ctx);
  kk_std_core_sslice__sslice cur = _self->cur; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(cur, _ctx);}, {}, _ctx)
  bool _y_x10367_177 = kk_bool_unbox(_b_x175); /*bool*/;
  double _x_x1048 = kk_std_num_float64__mlift_pdecdouble_10412(cur, _y_x10367_177, _ctx); /*float64*/
  return kk_double_box(_x_x1048, _ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10414(kk_std_core_sslice__sslice cur, kk_string_t _c_x10366, kk_context_t* _ctx) { /* (cur : sslice/sslice, string) -> float64 */ 
  kk_string_t frac;
  kk_string_t _x_x1042;
  kk_define_string_literal(, _s_x1043, 1, "0", _ctx)
  _x_x1042 = kk_string_dup(_s_x1043, _ctx); /*string*/
  frac = kk_std_core_sslice_trim_right(_c_x10366, _x_x1042, _ctx); /*string*/
  kk_string_drop(frac, _ctx);
  kk_std_core_hnd__ev ev_10505 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10503;
  kk_box_t _x_x1044;
  {
    struct kk_std_core_hnd_Ev* _con_x1045 = kk_std_core_hnd__as_Ev(ev_10505, _ctx);
    kk_box_t _box_x168 = _con_x1045->hnd;
    int32_t m = _con_x1045->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x168, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x590;
    kk_std_core_hnd__clause0 _brw_x591 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x590 = _brw_x591; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x171 = _match_x590.clause;
      _x_x1044 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x171, (_fun_unbox_x171, m, ev_10505, _ctx), _ctx); /*35*/
    }
  }
  x_10503 = kk_bool_unbox(_x_x1044); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1046 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10414_fun1047(cur, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1046, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_pdecdouble_10412(cur, x_10503, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10415_fun1050__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10415_fun1050(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10415_fun1050(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdecdouble_10415_fun1050, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10415_fun1050(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1051;
  kk_char_t _x_x1052 = kk_char_unbox(_b_x179, KK_OWNED, _ctx); /*char*/
  _x_x1051 = kk_std_num_float64__mlift_pdecdouble_10413(_x_x1052, _ctx); /*string*/
  return kk_string_box(_x_x1051);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10415_fun1055__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice cur;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10415_fun1055(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10415_fun1055(kk_std_core_sslice__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10415_fun1055__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdecdouble_10415_fun1055__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdecdouble_10415_fun1055, kk_context());
  _self->cur = cur;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10415_fun1055(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10415_fun1055__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdecdouble_10415_fun1055__t*, _fself, _ctx);
  kk_std_core_sslice__sslice cur = _self->cur; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(cur, _ctx);}, {}, _ctx)
  kk_string_t _c_x10366_184 = kk_string_unbox(_b_x182); /*string*/;
  double _x_x1056 = kk_std_num_float64__mlift_pdecdouble_10414(cur, _c_x10366_184, _ctx); /*float64*/
  return kk_double_box(_x_x1056, _ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10415(kk_std_core_sslice__sslice cur, bool _y_x10363, kk_context_t* _ctx) { /* (cur : sslice/sslice, bool) -> std/text/parse/parse float64 */ 
  kk_string_t x_10507;
  if (_y_x10363) {
    kk_char_t x_0_10509 = kk_std_text_parse_char('.', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1049 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10415_fun1050(_ctx), _ctx); /*2419*/
      x_10507 = kk_string_unbox(_x_x1049); /*string*/
    }
    else {
      x_10507 = kk_std_text_parse_digits0(_ctx); /*string*/
    }
  }
  else {
    x_10507 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10507, _ctx);
    kk_box_t _x_x1054 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10415_fun1055(cur, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1054, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_pdecdouble_10414(cur, x_10507, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10416_fun1060__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice cur;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10416_fun1060(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10416_fun1060(kk_std_core_sslice__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10416_fun1060__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdecdouble_10416_fun1060__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdecdouble_10416_fun1060, kk_context());
  _self->cur = cur;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10416_fun1060(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10416_fun1060__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdecdouble_10416_fun1060__t*, _fself, _ctx);
  kk_std_core_sslice__sslice cur = _self->cur; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(cur, _ctx);}, {}, _ctx)
  bool _y_x10363_194 = kk_bool_unbox(_b_x192); /*bool*/;
  double _x_x1061 = kk_std_num_float64__mlift_pdecdouble_10415(cur, _y_x10363_194, _ctx); /*float64*/
  return kk_double_box(_x_x1061, _ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10416(kk_std_core_sslice__sslice cur, kk_string_t man, kk_context_t* _ctx) { /* (cur : sslice/sslice, man : string) -> std/text/parse/parse float64 */ 
  kk_string_drop(man, _ctx);
  kk_std_core_hnd__ev ev_10513 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10511;
  kk_box_t _x_x1057;
  {
    struct kk_std_core_hnd_Ev* _con_x1058 = kk_std_core_hnd__as_Ev(ev_10513, _ctx);
    kk_box_t _box_x185 = _con_x1058->hnd;
    int32_t m = _con_x1058->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x185, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x585;
    kk_std_core_hnd__clause0 _brw_x586 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x585 = _brw_x586; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x188 = _match_x585.clause;
      _x_x1057 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x188, (_fun_unbox_x188, m, ev_10513, _ctx), _ctx); /*35*/
    }
  }
  x_10511 = kk_bool_unbox(_x_x1057); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1059 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10416_fun1060(cur, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1059, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_pdecdouble_10415(cur, x_10511, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdecdouble_10417_fun1063__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice cur;
};
static kk_box_t kk_std_num_float64__mlift_pdecdouble_10417_fun1063(kk_function_t _fself, kk_box_t _b_x196, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdecdouble_10417_fun1063(kk_std_core_sslice__sslice cur, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10417_fun1063__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdecdouble_10417_fun1063__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdecdouble_10417_fun1063, kk_context());
  _self->cur = cur;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdecdouble_10417_fun1063(kk_function_t _fself, kk_box_t _b_x196, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdecdouble_10417_fun1063__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdecdouble_10417_fun1063__t*, _fself, _ctx);
  kk_std_core_sslice__sslice cur = _self->cur; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(cur, _ctx);}, {}, _ctx)
  kk_string_t man_198 = kk_string_unbox(_b_x196); /*string*/;
  double _x_x1064 = kk_std_num_float64__mlift_pdecdouble_10416(cur, man_198, _ctx); /*float64*/
  return kk_double_box(_x_x1064, _ctx);
}

double kk_std_num_float64__mlift_pdecdouble_10417(kk_std_core_sslice__sslice cur, kk_context_t* _ctx) { /* (cur : sslice/sslice) -> std/text/parse/parse float64 */ 
  kk_string_t x_10515 = kk_std_text_parse_digits(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10515, _ctx);
    kk_box_t _x_x1062 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdecdouble_10417_fun1063(cur, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1062, KK_OWNED, _ctx);
  }
  {
    return kk_std_num_float64__mlift_pdecdouble_10416(cur, x_10515, _ctx);
  }
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1068__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1068(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1068(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun1068, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1068(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1069;
  kk_std_core_sslice__sslice _x_x1070 = kk_std_core_sslice__sslice_unbox(_b_x206, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x1069 = kk_std_num_float64__mlift_pdecdouble_10417(_x_x1070, _ctx); /*float64*/
  return kk_double_box(_x_x1069, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1072__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice x_10517;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1072(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1072(kk_std_core_sslice__sslice x_10517, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1072__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun1072__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_pdecdouble_fun1072, kk_context());
  _self->x_10517 = x_10517;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1072(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1072__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun1072__t*, _fself, _ctx);
  kk_std_core_sslice__sslice x_10517 = _self->x_10517; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(x_10517, _ctx);}, {}, _ctx)
  kk_string_t man_251 = kk_string_unbox(_b_x208); /*string*/;
  double _x_x1073 = kk_std_num_float64__mlift_pdecdouble_10416(x_10517, man_251, _ctx); /*float64*/
  return kk_double_box(_x_x1073, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1077__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice x_10517;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1077(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1077(kk_std_core_sslice__sslice x_10517, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1077__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun1077__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_pdecdouble_fun1077, kk_context());
  _self->x_10517 = x_10517;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1077(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1077__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun1077__t*, _fself, _ctx);
  kk_std_core_sslice__sslice x_10517 = _self->x_10517; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(x_10517, _ctx);}, {}, _ctx)
  bool _y_x10363_252 = kk_bool_unbox(_b_x216); /*bool*/;
  double _x_x1078 = kk_std_num_float64__mlift_pdecdouble_10415(x_10517, _y_x10363_252, _ctx); /*float64*/
  return kk_double_box(_x_x1078, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1080__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1080(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1080(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun1080, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1080(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1081;
  kk_char_t _x_x1082 = kk_char_unbox(_b_x218, KK_OWNED, _ctx); /*char*/
  _x_x1081 = kk_std_num_float64__mlift_pdecdouble_10413(_x_x1082, _ctx); /*string*/
  return kk_string_box(_x_x1081);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1085__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice x_10517;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1085(kk_function_t _fself, kk_box_t _b_x221, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1085(kk_std_core_sslice__sslice x_10517, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1085__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun1085__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_pdecdouble_fun1085, kk_context());
  _self->x_10517 = x_10517;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1085(kk_function_t _fself, kk_box_t _b_x221, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1085__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun1085__t*, _fself, _ctx);
  kk_std_core_sslice__sslice x_10517 = _self->x_10517; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(x_10517, _ctx);}, {}, _ctx)
  kk_string_t _c_x10366_253 = kk_string_unbox(_b_x221); /*string*/;
  double _x_x1086 = kk_std_num_float64__mlift_pdecdouble_10414(x_10517, _c_x10366_253, _ctx); /*float64*/
  return kk_double_box(_x_x1086, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1092__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice x_10517;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1092(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1092(kk_std_core_sslice__sslice x_10517, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1092__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun1092__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_pdecdouble_fun1092, kk_context());
  _self->x_10517 = x_10517;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1092(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1092__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun1092__t*, _fself, _ctx);
  kk_std_core_sslice__sslice x_10517 = _self->x_10517; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(x_10517, _ctx);}, {}, _ctx)
  bool _y_x10367_254 = kk_bool_unbox(_b_x229); /*bool*/;
  double _x_x1093 = kk_std_num_float64__mlift_pdecdouble_10412(x_10517, _y_x10367_254, _ctx); /*float64*/
  return kk_double_box(_x_x1093, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1097__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1097(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1097(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun1097, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1097(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x1098;
  kk_char_t _x_x1099 = kk_char_unbox(_b_x231, KK_OWNED, _ctx); /*char*/
  _x_x1098 = kk_std_num_float64__mlift_pdecdouble_10410(_x_x1099, _ctx); /*int*/
  return kk_integer_box(_x_x1098, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1101__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice x_10517;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1101(kk_function_t _fself, kk_box_t _b_x237, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1101(kk_std_core_sslice__sslice x_10517, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1101__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdecdouble_fun1101__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_pdecdouble_fun1101, kk_context());
  _self->x_10517 = x_10517;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1102__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1102(kk_function_t _fself, kk_box_t _b_x235, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1102(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun1102, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1102(kk_function_t _fself, kk_box_t _b_x235, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1103;
  kk_string_t _x_x1104 = kk_string_unbox(_b_x235); /*string*/
  _x_x1103 = kk_std_num_float64_prim_parse_float64(_x_x1104, _ctx); /*float64*/
  return kk_double_box(_x_x1103, _ctx);
}
static kk_box_t kk_std_num_float64_pdecdouble_fun1101(kk_function_t _fself, kk_box_t _b_x237, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdecdouble_fun1101__t* _self = kk_function_as(struct kk_std_num_float64_pdecdouble_fun1101__t*, _fself, _ctx);
  kk_std_core_sslice__sslice x_10517 = _self->x_10517; /* sslice/sslice */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(x_10517, _ctx);}, {}, _ctx)
  kk_integer_t _c_x10370_255 = kk_integer_unbox(_b_x237, _ctx); /*int*/;
  kk_integer_drop(_c_x10370_255, _ctx);
  kk_string_t _x_x1_10400 = kk_std_core_sslice_string(x_10517, _ctx); /*string*/;
  return kk_std_core_hnd__open_none1(kk_std_num_float64_new_pdecdouble_fun1102(_ctx), kk_string_box(_x_x1_10400), _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdecdouble_fun1106__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdecdouble_fun1106(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdecdouble_fun1106(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdecdouble_fun1106, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdecdouble_fun1106(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1107;
  kk_string_t _x_x1108 = kk_string_unbox(_b_x240); /*string*/
  _x_x1107 = kk_std_num_float64_prim_parse_float64(_x_x1108, _ctx); /*float64*/
  return kk_double_box(_x_x1107, _ctx);
}

double kk_std_num_float64_pdecdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  kk_std_core_hnd__ev ev_10520 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_sslice__sslice x_10517;
  kk_box_t _x_x1065;
  {
    struct kk_std_core_hnd_Ev* _con_x1066 = kk_std_core_hnd__as_Ev(ev_10520, _ctx);
    kk_box_t _box_x199 = _con_x1066->hnd;
    int32_t m = _con_x1066->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x199, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x581;
    kk_std_core_hnd__clause0 _brw_x582 = kk_std_text_parse_current_input_fs__select(h, _ctx); /*hnd/clause0<sslice/sslice,std/text/parse/parse,832,833>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x581 = _brw_x582; /*hnd/clause0<sslice/sslice,std/text/parse/parse,832,833>*/
    {
      kk_function_t _fun_unbox_x202 = _match_x581.clause;
      _x_x1065 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x202, (_fun_unbox_x202, m, ev_10520, _ctx), _ctx); /*35*/
    }
  }
  x_10517 = kk_std_core_sslice__sslice_unbox(_x_x1065, KK_OWNED, _ctx); /*sslice/sslice*/
  if (kk_yielding(kk_context())) {
    kk_std_core_sslice__sslice_drop(x_10517, _ctx);
    kk_box_t _x_x1067 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1068(_ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1067, KK_OWNED, _ctx);
  }
  {
    kk_string_t x_0_10522 = kk_std_text_parse_digits(_ctx); /*string*/;
    kk_string_drop(x_0_10522, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1071 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1072(x_10517, _ctx), _ctx); /*2419*/
      return kk_double_unbox(_x_x1071, KK_OWNED, _ctx);
    }
    {
      kk_std_core_hnd__ev ev_0_10528 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      bool x_1_10525;
      kk_box_t _x_x1074;
      {
        struct kk_std_core_hnd_Ev* _con_x1075 = kk_std_core_hnd__as_Ev(ev_0_10528, _ctx);
        kk_box_t _box_x209 = _con_x1075->hnd;
        int32_t m_0 = _con_x1075->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x209, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        kk_std_core_hnd__clause0 _match_x579;
        kk_std_core_hnd__clause0 _brw_x580 = kk_std_text_parse_pick_fs__select(h_0, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
        kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
        _match_x579 = _brw_x580; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
        {
          kk_function_t _fun_unbox_x212 = _match_x579.clause;
          _x_x1074 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x212, (_fun_unbox_x212, m_0, ev_0_10528, _ctx), _ctx); /*35*/
        }
      }
      x_1_10525 = kk_bool_unbox(_x_x1074); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1076 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1077(x_10517, _ctx), _ctx); /*2419*/
        return kk_double_unbox(_x_x1076, KK_OWNED, _ctx);
      }
      {
        kk_string_t x_2_10530;
        if (x_1_10525) {
          kk_char_t x_3_10533 = kk_std_text_parse_char('.', _ctx); /*char*/;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1079 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1080(_ctx), _ctx); /*2419*/
            x_2_10530 = kk_string_unbox(_x_x1079); /*string*/
          }
          else {
            x_2_10530 = kk_std_text_parse_digits0(_ctx); /*string*/
          }
        }
        else {
          x_2_10530 = kk_string_empty(); /*string*/
        }
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_2_10530, _ctx);
          kk_box_t _x_x1084 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1085(x_10517, _ctx), _ctx); /*2419*/
          return kk_double_unbox(_x_x1084, KK_OWNED, _ctx);
        }
        {
          kk_string_t frac;
          kk_string_t _x_x1087;
          kk_define_string_literal(, _s_x1088, 1, "0", _ctx)
          _x_x1087 = kk_string_dup(_s_x1088, _ctx); /*string*/
          frac = kk_std_core_sslice_trim_right(x_2_10530, _x_x1087, _ctx); /*string*/
          kk_string_drop(frac, _ctx);
          kk_std_core_hnd__ev ev_1_10538 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
          bool x_4_10535;
          kk_box_t _x_x1089;
          {
            struct kk_std_core_hnd_Ev* _con_x1090 = kk_std_core_hnd__as_Ev(ev_1_10538, _ctx);
            kk_box_t _box_x222 = _con_x1090->hnd;
            int32_t m_1 = _con_x1090->marker;
            kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x222, KK_BORROWED, _ctx);
            kk_std_text_parse__parse_dup(h_1, _ctx);
            kk_std_core_hnd__clause0 _match_x576;
            kk_std_core_hnd__clause0 _brw_x577 = kk_std_text_parse_pick_fs__select(h_1, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
            kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
            _match_x576 = _brw_x577; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
            {
              kk_function_t _fun_unbox_x225 = _match_x576.clause;
              _x_x1089 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x225, (_fun_unbox_x225, m_1, ev_1_10538, _ctx), _ctx); /*35*/
            }
          }
          x_4_10535 = kk_bool_unbox(_x_x1089); /*bool*/
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1091 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1092(x_10517, _ctx), _ctx); /*2419*/
            return kk_double_unbox(_x_x1091, KK_OWNED, _ctx);
          }
          {
            kk_integer_t x_5_10540;
            if (x_4_10535) {
              kk_char_t x_6_10543;
              kk_string_t _x_x1094;
              kk_define_string_literal(, _s_x1095, 2, "eE", _ctx)
              _x_x1094 = kk_string_dup(_s_x1095, _ctx); /*string*/
              x_6_10543 = kk_std_text_parse_one_of(_x_x1094, _ctx); /*char*/
              if (kk_yielding(kk_context())) {
                kk_box_t _x_x1096 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1097(_ctx), _ctx); /*2419*/
                x_5_10540 = kk_integer_unbox(_x_x1096, _ctx); /*int*/
              }
              else {
                x_5_10540 = kk_std_text_parse_pint(_ctx); /*int*/
              }
            }
            else {
              x_5_10540 = kk_integer_from_small(0); /*int*/
            }
            kk_integer_drop(x_5_10540, _ctx);
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x1100 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdecdouble_fun1101(x_10517, _ctx), _ctx); /*2419*/
              return kk_double_unbox(_x_x1100, KK_OWNED, _ctx);
            }
            {
              kk_string_t _x_x1_10400_0 = kk_std_core_sslice_string(x_10517, _ctx); /*string*/;
              kk_box_t _x_x1105 = kk_std_core_hnd__open_none1(kk_std_num_float64_new_pdecdouble_fun1106(_ctx), kk_string_box(_x_x1_10400_0), _ctx); /*9904*/
              return kk_double_unbox(_x_x1105, KK_OWNED, _ctx);
            }
          }
        }
      }
    }
  }
}


// lift anonymous function
struct kk_std_num_float64_pspecial_fun1109__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun1109(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun1109(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun1109, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pspecial_fun1114__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun1114(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun1114(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun1114, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pspecial_fun1114(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1115;
  kk_string_t _x_x1116 = kk_string_unbox(_b_x257); /*string*/
  _x_x1115 = kk_std_num_float64__mlift_pspecial_10418(_x_x1116, _ctx); /*float64*/
  return kk_double_box(_x_x1115, _ctx);
}
static kk_box_t kk_std_num_float64_pspecial_fun1109(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_10547;
  kk_string_t _x_x1110;
  kk_define_string_literal(, _s_x1111, 3, "nan", _ctx)
  _x_x1110 = kk_string_dup(_s_x1111, _ctx); /*string*/
  x_10547 = kk_std_text_parse_pstring(_x_x1110, _ctx); /*string*/
  kk_string_drop(x_10547, _ctx);
  double _x_x1112;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1113 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pspecial_fun1114(_ctx), _ctx); /*2419*/
    _x_x1112 = kk_double_unbox(_x_x1113, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1112 = kk_std_num_float64_nan; /*float64*/
  }
  return kk_double_box(_x_x1112, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pspecial_fun1118__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun1118(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun1118(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun1118, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pspecial_fun1123__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun1123(kk_function_t _fself, kk_box_t _b_x259, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun1123(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun1123, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pspecial_fun1123(kk_function_t _fself, kk_box_t _b_x259, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1124;
  kk_string_t _x_x1125 = kk_string_unbox(_b_x259); /*string*/
  _x_x1124 = kk_std_num_float64__mlift_pspecial_10419(_x_x1125, _ctx); /*float64*/
  return kk_double_box(_x_x1124, _ctx);
}
static kk_box_t kk_std_num_float64_pspecial_fun1118(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_0_10549;
  kk_string_t _x_x1119;
  kk_define_string_literal(, _s_x1120, 8, "infinity", _ctx)
  _x_x1119 = kk_string_dup(_s_x1120, _ctx); /*string*/
  x_0_10549 = kk_std_text_parse_pstring(_x_x1119, _ctx); /*string*/
  kk_string_drop(x_0_10549, _ctx);
  double _x_x1121;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1122 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pspecial_fun1123(_ctx), _ctx); /*2419*/
    _x_x1121 = kk_double_unbox(_x_x1122, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1121 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x_x1121, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pspecial_fun1127__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun1127(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun1127(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun1127, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pspecial_fun1132__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pspecial_fun1132(kk_function_t _fself, kk_box_t _b_x261, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pspecial_fun1132(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pspecial_fun1132, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pspecial_fun1132(kk_function_t _fself, kk_box_t _b_x261, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1133;
  kk_string_t _x_x1134 = kk_string_unbox(_b_x261); /*string*/
  _x_x1133 = kk_std_num_float64__mlift_pspecial_10420(_x_x1134, _ctx); /*float64*/
  return kk_double_box(_x_x1133, _ctx);
}
static kk_box_t kk_std_num_float64_pspecial_fun1127(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_1_10551;
  kk_string_t _x_x1128;
  kk_define_string_literal(, _s_x1129, 3, "inf", _ctx)
  _x_x1128 = kk_string_dup(_s_x1129, _ctx); /*string*/
  x_1_10551 = kk_std_text_parse_pstring(_x_x1128, _ctx); /*string*/
  kk_string_drop(x_1_10551, _ctx);
  double _x_x1130;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1131 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pspecial_fun1132(_ctx), _ctx); /*2419*/
    _x_x1130 = kk_double_unbox(_x_x1131, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1130 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x_x1130, _ctx);
}

double kk_std_num_float64_pspecial(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  kk_std_core_types__list ps_10114;
  kk_std_core_types__list _x_x1117;
  kk_std_core_types__list _x_x1126 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pspecial_fun1127(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x1117 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pspecial_fun1118(_ctx), _ctx), _x_x1126, _ctx); /*list<79>*/
  ps_10114 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pspecial_fun1109(_ctx), _ctx), _x_x1117, _ctx); /*list<std/text/parse/parser<total,float64>>*/
  if (kk_std_core_types__is_Nil(ps_10114, _ctx)) {
    kk_std_core_hnd__ev ev_10553 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x1135;
    {
      struct kk_std_core_hnd_Ev* _con_x1136 = kk_std_core_hnd__as_Ev(ev_10553, _ctx);
      kk_box_t _box_x280 = _con_x1136->hnd;
      int32_t m = _con_x1136->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x280, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x564;
      kk_std_core_hnd__clause1 _brw_x565 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x564 = _brw_x565; /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/
      {
        kk_function_t _fun_unbox_x284 = _match_x564.clause;
        kk_box_t _x_x1137;
        kk_string_t _x_x1138;
        kk_define_string_literal(, _s_x1139, 23, "no further alternatives", _ctx)
        _x_x1138 = kk_string_dup(_s_x1139, _ctx); /*string*/
        _x_x1137 = kk_string_box(_x_x1138); /*45*/
        _x_x1135 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x284, (_fun_unbox_x284, m, ev_10553, _x_x1137, _ctx), _ctx); /*46*/
      }
    }
    return kk_double_unbox(_x_x1135, KK_OWNED, _ctx);
  }
  {
    kk_box_t _x_x1140 = kk_std_text_parse__unroll_choose_10000(ps_10114, _ctx); /*1639*/
    return kk_double_unbox(_x_x1140, KK_OWNED, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1141__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1141(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1141(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1141, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1141(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1142 = kk_std_num_float64_phexdouble(_ctx); /*float64*/
  return kk_double_box(_x_x1142, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1144__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1144(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1144(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1144, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1144(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1145 = kk_std_num_float64_pdecdouble(_ctx); /*float64*/
  return kk_double_box(_x_x1145, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1147__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1147(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1147(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1147, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1148__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1148(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1148(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1148, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1153__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1153(kk_function_t _fself, kk_box_t _b_x291, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1153(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1153, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1153(kk_function_t _fself, kk_box_t _b_x291, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1154;
  kk_string_t _x_x1155 = kk_string_unbox(_b_x291); /*string*/
  _x_x1154 = kk_std_num_float64__mlift_pdouble_10421(_x_x1155, _ctx); /*float64*/
  return kk_double_box(_x_x1154, _ctx);
}
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1148(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_10556;
  kk_string_t _x_x1149;
  kk_define_string_literal(, _s_x1150, 3, "nan", _ctx)
  _x_x1149 = kk_string_dup(_s_x1150, _ctx); /*string*/
  x_10556 = kk_std_text_parse_pstring(_x_x1149, _ctx); /*string*/
  kk_string_drop(x_10556, _ctx);
  double _x_x1151;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1152 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdouble_10425_fun1153(_ctx), _ctx); /*2419*/
    _x_x1151 = kk_double_unbox(_x_x1152, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1151 = kk_std_num_float64_nan; /*float64*/
  }
  return kk_double_box(_x_x1151, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1157__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1157(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1157(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1157, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1162__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1162(kk_function_t _fself, kk_box_t _b_x293, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1162(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1162, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1162(kk_function_t _fself, kk_box_t _b_x293, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1163;
  kk_string_t _x_x1164 = kk_string_unbox(_b_x293); /*string*/
  _x_x1163 = kk_std_num_float64__mlift_pdouble_10422(_x_x1164, _ctx); /*float64*/
  return kk_double_box(_x_x1163, _ctx);
}
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1157(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_0_10558;
  kk_string_t _x_x1158;
  kk_define_string_literal(, _s_x1159, 8, "infinity", _ctx)
  _x_x1158 = kk_string_dup(_s_x1159, _ctx); /*string*/
  x_0_10558 = kk_std_text_parse_pstring(_x_x1158, _ctx); /*string*/
  kk_string_drop(x_0_10558, _ctx);
  double _x_x1160;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1161 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdouble_10425_fun1162(_ctx), _ctx); /*2419*/
    _x_x1160 = kk_double_unbox(_x_x1161, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1160 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x_x1160, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1166__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1166(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1166(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1166, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1171__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1171(kk_function_t _fself, kk_box_t _b_x295, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1171(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1171, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1171(kk_function_t _fself, kk_box_t _b_x295, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1172;
  kk_string_t _x_x1173 = kk_string_unbox(_b_x295); /*string*/
  _x_x1172 = kk_std_num_float64__mlift_pdouble_10423(_x_x1173, _ctx); /*float64*/
  return kk_double_box(_x_x1172, _ctx);
}
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1166(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_1_10560;
  kk_string_t _x_x1167;
  kk_define_string_literal(, _s_x1168, 3, "inf", _ctx)
  _x_x1167 = kk_string_dup(_s_x1168, _ctx); /*string*/
  x_1_10560 = kk_std_text_parse_pstring(_x_x1167, _ctx); /*string*/
  kk_string_drop(x_1_10560, _ctx);
  double _x_x1169;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1170 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdouble_10425_fun1171(_ctx), _ctx); /*2419*/
    _x_x1169 = kk_double_unbox(_x_x1170, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1169 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x_x1169, _ctx);
}
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1147(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list ps_0_10116;
  kk_std_core_types__list _x_x1156;
  kk_std_core_types__list _x_x1165 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1166(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x1156 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1157(_ctx), _ctx), _x_x1165, _ctx); /*list<79>*/
  ps_0_10116 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1148(_ctx), _ctx), _x_x1156, _ctx); /*list<std/text/parse/parser<total,float64>>*/
  double _x_x1174;
  if (kk_std_core_types__is_Nil(ps_0_10116, _ctx)) {
    kk_std_core_hnd__ev ev_10562 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x1175;
    {
      struct kk_std_core_hnd_Ev* _con_x1176 = kk_std_core_hnd__as_Ev(ev_10562, _ctx);
      kk_box_t _box_x314 = _con_x1176->hnd;
      int32_t m = _con_x1176->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x314, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x559;
      kk_std_core_hnd__clause1 _brw_x560 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x559 = _brw_x560; /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/
      {
        kk_function_t _fun_unbox_x318 = _match_x559.clause;
        kk_box_t _x_x1177;
        kk_string_t _x_x1178;
        kk_define_string_literal(, _s_x1179, 23, "no further alternatives", _ctx)
        _x_x1178 = kk_string_dup(_s_x1179, _ctx); /*string*/
        _x_x1177 = kk_string_box(_x_x1178); /*45*/
        _x_x1175 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x318, (_fun_unbox_x318, m, ev_10562, _x_x1177, _ctx), _ctx); /*46*/
      }
    }
    _x_x1174 = kk_double_unbox(_x_x1175, KK_OWNED, _ctx); /*float64*/
  }
  else {
    kk_box_t _x_x1180 = kk_std_text_parse__unroll_choose_10000(ps_0_10116, _ctx); /*1639*/
    _x_x1174 = kk_double_unbox(_x_x1180, KK_OWNED, _ctx); /*float64*/
  }
  return kk_double_box(_x_x1174, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1182__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1182(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1182(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64__mlift_pdouble_10425_fun1182, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1182(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_double_box(0x0p+0, _ctx);
}


// lift anonymous function
struct kk_std_num_float64__mlift_pdouble_10425_fun1190__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1190(kk_function_t _fself, kk_box_t _b_x355, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64__new_mlift_pdouble_10425_fun1190(bool neg, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdouble_10425_fun1190__t* _self = kk_function_alloc_as(struct kk_std_num_float64__mlift_pdouble_10425_fun1190__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64__mlift_pdouble_10425_fun1190, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64__mlift_pdouble_10425_fun1190(kk_function_t _fself, kk_box_t _b_x355, kk_context_t* _ctx) {
  struct kk_std_num_float64__mlift_pdouble_10425_fun1190__t* _self = kk_function_as(struct kk_std_num_float64__mlift_pdouble_10425_fun1190__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  double _x_x1191;
  double _c_x10386_357 = kk_double_unbox(_b_x355, KK_OWNED, _ctx); /*float64*/;
  if (neg) {
    _x_x1191 = (-_c_x10386_357); /*float64*/
  }
  else {
    _x_x1191 = _c_x10386_357; /*float64*/
  }
  return kk_double_box(_x_x1191, _ctx);
}

double kk_std_num_float64__mlift_pdouble_10425(bool neg, kk_context_t* _ctx) { /* (neg : bool) -> std/text/parse/parse float64 */ 
  kk_std_core_types__list ps_10115;
  kk_std_core_types__list _x_x1143;
  kk_std_core_types__list _x_x1146;
  kk_std_core_types__list _x_x1181 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1182(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x1146 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1147(_ctx), _ctx), _x_x1181, _ctx); /*list<79>*/
  _x_x1143 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1144(_ctx), _ctx), _x_x1146, _ctx); /*list<79>*/
  ps_10115 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64__new_mlift_pdouble_10425_fun1141(_ctx), _ctx), _x_x1143, _ctx); /*list<std/text/parse/parser<total,float64>>*/
  double x_3_10565;
  if (kk_std_core_types__is_Nil(ps_10115, _ctx)) {
    kk_std_core_hnd__ev ev_0_10567 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x1183;
    {
      struct kk_std_core_hnd_Ev* _con_x1184 = kk_std_core_hnd__as_Ev(ev_0_10567, _ctx);
      kk_box_t _box_x344 = _con_x1184->hnd;
      int32_t m_0 = _con_x1184->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x344, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      kk_std_core_hnd__clause1 _match_x557;
      kk_std_core_hnd__clause1 _brw_x558 = kk_std_text_parse_fail_fs__select(h_0, _ctx); /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/;
      kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
      _match_x557 = _brw_x558; /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/
      {
        kk_function_t _fun_unbox_x348 = _match_x557.clause;
        kk_box_t _x_x1185;
        kk_string_t _x_x1186;
        kk_define_string_literal(, _s_x1187, 23, "no further alternatives", _ctx)
        _x_x1186 = kk_string_dup(_s_x1187, _ctx); /*string*/
        _x_x1185 = kk_string_box(_x_x1186); /*45*/
        _x_x1183 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x348, (_fun_unbox_x348, m_0, ev_0_10567, _x_x1185, _ctx), _ctx); /*46*/
      }
    }
    x_3_10565 = kk_double_unbox(_x_x1183, KK_OWNED, _ctx); /*float64*/
  }
  else {
    kk_box_t _x_x1188 = kk_std_text_parse__unroll_choose_10000(ps_10115, _ctx); /*1639*/
    x_3_10565 = kk_double_unbox(_x_x1188, KK_OWNED, _ctx); /*float64*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1189 = kk_std_core_hnd_yield_extend(kk_std_num_float64__new_mlift_pdouble_10425_fun1190(neg, _ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1189, KK_OWNED, _ctx);
  }
  {
    double _c_x10386_358 = x_3_10565; /*float64*/;
    if (neg) {
      return (-_c_x10386_358);
    }
    {
      return _c_x10386_358;
    }
  }
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1193__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1193(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1193(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1193, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1193(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1194;
  bool _x_x1195 = kk_bool_unbox(_b_x360); /*bool*/
  _x_x1194 = kk_std_num_float64__mlift_pdouble_10425(_x_x1195, _ctx); /*float64*/
  return kk_double_box(_x_x1194, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1196__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1196(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1196(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1196, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1196(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1197 = kk_std_num_float64_phexdouble(_ctx); /*float64*/
  return kk_double_box(_x_x1197, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1199__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1199(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1199(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1199, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1199(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1200 = kk_std_num_float64_pdecdouble(_ctx); /*float64*/
  return kk_double_box(_x_x1200, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1202__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1202(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1202(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1202, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun1203__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1203(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1203(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1203, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun1208__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1208(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1208(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1208, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1208(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1209;
  kk_string_t _x_x1210 = kk_string_unbox(_b_x362); /*string*/
  _x_x1209 = kk_std_num_float64__mlift_pdouble_10421(_x_x1210, _ctx); /*float64*/
  return kk_double_box(_x_x1209, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun1203(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_0_10575;
  kk_string_t _x_x1204;
  kk_define_string_literal(, _s_x1205, 3, "nan", _ctx)
  _x_x1204 = kk_string_dup(_s_x1205, _ctx); /*string*/
  x_0_10575 = kk_std_text_parse_pstring(_x_x1204, _ctx); /*string*/
  kk_string_drop(x_0_10575, _ctx);
  double _x_x1206;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1207 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun1208(_ctx), _ctx); /*2419*/
    _x_x1206 = kk_double_unbox(_x_x1207, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1206 = kk_std_num_float64_nan; /*float64*/
  }
  return kk_double_box(_x_x1206, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1212__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1212(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1212(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1212, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun1217__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1217(kk_function_t _fself, kk_box_t _b_x364, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1217(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1217, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1217(kk_function_t _fself, kk_box_t _b_x364, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1218;
  kk_string_t _x_x1219 = kk_string_unbox(_b_x364); /*string*/
  _x_x1218 = kk_std_num_float64__mlift_pdouble_10422(_x_x1219, _ctx); /*float64*/
  return kk_double_box(_x_x1218, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun1212(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_1_10577;
  kk_string_t _x_x1213;
  kk_define_string_literal(, _s_x1214, 8, "infinity", _ctx)
  _x_x1213 = kk_string_dup(_s_x1214, _ctx); /*string*/
  x_1_10577 = kk_std_text_parse_pstring(_x_x1213, _ctx); /*string*/
  kk_string_drop(x_1_10577, _ctx);
  double _x_x1215;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1216 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun1217(_ctx), _ctx); /*2419*/
    _x_x1215 = kk_double_unbox(_x_x1216, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1215 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x_x1215, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1221__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1221(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1221(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1221, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_num_float64_pdouble_fun1226__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1226(kk_function_t _fself, kk_box_t _b_x366, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1226(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1226, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1226(kk_function_t _fself, kk_box_t _b_x366, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1227;
  kk_string_t _x_x1228 = kk_string_unbox(_b_x366); /*string*/
  _x_x1227 = kk_std_num_float64__mlift_pdouble_10423(_x_x1228, _ctx); /*float64*/
  return kk_double_box(_x_x1227, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun1221(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t x_2_10579;
  kk_string_t _x_x1222;
  kk_define_string_literal(, _s_x1223, 3, "inf", _ctx)
  _x_x1222 = kk_string_dup(_s_x1223, _ctx); /*string*/
  x_2_10579 = kk_std_text_parse_pstring(_x_x1222, _ctx); /*string*/
  kk_string_drop(x_2_10579, _ctx);
  double _x_x1224;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1225 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun1226(_ctx), _ctx); /*2419*/
    _x_x1224 = kk_double_unbox(_x_x1225, KK_OWNED, _ctx); /*float64*/
  }
  else {
    _x_x1224 = kk_std_num_float64_posinf; /*float64*/
  }
  return kk_double_box(_x_x1224, _ctx);
}
static kk_box_t kk_std_num_float64_pdouble_fun1202(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list ps_0_10116;
  kk_std_core_types__list _x_x1211;
  kk_std_core_types__list _x_x1220 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1221(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x1211 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1212(_ctx), _ctx), _x_x1220, _ctx); /*list<79>*/
  ps_0_10116 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1203(_ctx), _ctx), _x_x1211, _ctx); /*list<std/text/parse/parser<total,float64>>*/
  double _x_x1229;
  if (kk_std_core_types__is_Nil(ps_0_10116, _ctx)) {
    kk_std_core_hnd__ev ev_10581 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x1230;
    {
      struct kk_std_core_hnd_Ev* _con_x1231 = kk_std_core_hnd__as_Ev(ev_10581, _ctx);
      kk_box_t _box_x385 = _con_x1231->hnd;
      int32_t m = _con_x1231->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x385, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x551;
      kk_std_core_hnd__clause1 _brw_x552 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x551 = _brw_x552; /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/
      {
        kk_function_t _fun_unbox_x389 = _match_x551.clause;
        kk_box_t _x_x1232;
        kk_string_t _x_x1233;
        kk_define_string_literal(, _s_x1234, 23, "no further alternatives", _ctx)
        _x_x1233 = kk_string_dup(_s_x1234, _ctx); /*string*/
        _x_x1232 = kk_string_box(_x_x1233); /*45*/
        _x_x1230 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x389, (_fun_unbox_x389, m, ev_10581, _x_x1232, _ctx), _ctx); /*46*/
      }
    }
    _x_x1229 = kk_double_unbox(_x_x1230, KK_OWNED, _ctx); /*float64*/
  }
  else {
    kk_box_t _x_x1235 = kk_std_text_parse__unroll_choose_10000(ps_0_10116, _ctx); /*1639*/
    _x_x1229 = kk_double_unbox(_x_x1235, KK_OWNED, _ctx); /*float64*/
  }
  return kk_double_box(_x_x1229, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1237__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_pdouble_fun1237(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1237(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_pdouble_fun1237, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1237(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_double_box(0x0p+0, _ctx);
}


// lift anonymous function
struct kk_std_num_float64_pdouble_fun1245__t {
  struct kk_function_s _base;
  bool x_10572;
};
static kk_box_t kk_std_num_float64_pdouble_fun1245(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_pdouble_fun1245(bool x_10572, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdouble_fun1245__t* _self = kk_function_alloc_as(struct kk_std_num_float64_pdouble_fun1245__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_float64_pdouble_fun1245, kk_context());
  _self->x_10572 = x_10572;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_float64_pdouble_fun1245(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx) {
  struct kk_std_num_float64_pdouble_fun1245__t* _self = kk_function_as(struct kk_std_num_float64_pdouble_fun1245__t*, _fself, _ctx);
  bool x_10572 = _self->x_10572; /* bool */
  kk_drop_match(_self, {kk_skip_dup(x_10572, _ctx);}, {}, _ctx)
  double _c_x10386_429 = kk_double_unbox(_b_x426, KK_OWNED, _ctx); /*float64*/;
  double _x_x1246;
  if (x_10572) {
    _x_x1246 = (-_c_x10386_429); /*float64*/
  }
  else {
    _x_x1246 = _c_x10386_429; /*float64*/
  }
  return kk_double_box(_x_x1246, _ctx);
}

double kk_std_num_float64_pdouble(kk_context_t* _ctx) { /* () -> std/text/parse/parse float64 */ 
  bool x_10572 = kk_std_text_parse_sign(_ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1192 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun1193(_ctx), _ctx); /*2419*/
    return kk_double_unbox(_x_x1192, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__list ps_10115;
    kk_std_core_types__list _x_x1198;
    kk_std_core_types__list _x_x1201;
    kk_std_core_types__list _x_x1236 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1237(_ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1201 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1202(_ctx), _ctx), _x_x1236, _ctx); /*list<79>*/
    _x_x1198 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1199(_ctx), _ctx), _x_x1201, _ctx); /*list<79>*/
    ps_10115 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_num_float64_new_pdouble_fun1196(_ctx), _ctx), _x_x1198, _ctx); /*list<std/text/parse/parser<total,float64>>*/
    double x_4_10584;
    if (kk_std_core_types__is_Nil(ps_10115, _ctx)) {
      kk_std_core_hnd__ev ev_0_10587 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x1238;
      {
        struct kk_std_core_hnd_Ev* _con_x1239 = kk_std_core_hnd__as_Ev(ev_0_10587, _ctx);
        kk_box_t _box_x415 = _con_x1239->hnd;
        int32_t m_0 = _con_x1239->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x415, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        kk_std_core_hnd__clause1 _match_x549;
        kk_std_core_hnd__clause1 _brw_x550 = kk_std_text_parse_fail_fs__select(h_0, _ctx); /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/;
        kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
        _match_x549 = _brw_x550; /*hnd/clause1<string,607,std/text/parse/parse,608,609>*/
        {
          kk_function_t _fun_unbox_x419 = _match_x549.clause;
          kk_box_t _x_x1240;
          kk_string_t _x_x1241;
          kk_define_string_literal(, _s_x1242, 23, "no further alternatives", _ctx)
          _x_x1241 = kk_string_dup(_s_x1242, _ctx); /*string*/
          _x_x1240 = kk_string_box(_x_x1241); /*45*/
          _x_x1238 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x419, (_fun_unbox_x419, m_0, ev_0_10587, _x_x1240, _ctx), _ctx); /*46*/
        }
      }
      x_4_10584 = kk_double_unbox(_x_x1238, KK_OWNED, _ctx); /*float64*/
    }
    else {
      kk_box_t _x_x1243 = kk_std_text_parse__unroll_choose_10000(ps_10115, _ctx); /*1639*/
      x_4_10584 = kk_double_unbox(_x_x1243, KK_OWNED, _ctx); /*float64*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1244 = kk_std_core_hnd_yield_extend(kk_std_num_float64_new_pdouble_fun1245(x_10572, _ctx), _ctx); /*2419*/
      return kk_double_unbox(_x_x1244, KK_OWNED, _ctx);
    }
    if (x_10572) {
      return (-x_4_10584);
    }
    {
      return x_4_10584;
    }
  }
}
 
// Parse a float64 number. Can be "NaN", "Inf(inity)" (case-insensitive),
// a fix-point number (`1.2`) or in scientific notation (`-2.3e-5`).
// Also allows floats in [hexadecimal notation](https://books.google.com/books?id=FgMsCwAAQBAJ&pg=PA41) (`0xA.Fp-10`) that can
// be represented precisely (and are the preferred _round trip_ format).


// lift anonymous function
struct kk_std_num_float64_parse_float64_fun1251__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_num_float64_parse_float64_fun1251(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_num_float64_new_parse_float64_fun1251(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_num_float64_parse_float64_fun1251, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_num_float64_parse_float64_fun1251(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  double _x_x1252 = kk_std_num_float64_pdouble(_ctx); /*float64*/
  return kk_double_box(_x_x1252, _ctx);
}

kk_std_core_types__maybe kk_std_num_float64_parse_float64(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<float64> */ 
  kk_string_t s_0_10118;
  kk_string_t _x_x1247;
  kk_string_t _x_x1248 = kk_string_trim_left(s,kk_context()); /*string*/
  _x_x1247 = kk_string_trim_right(_x_x1248,kk_context()); /*string*/
  s_0_10118 = kk_std_core_string_to_lower(_x_x1247, _ctx); /*string*/
  kk_std_core_sslice__sslice _b_x430_432;
  kk_string_t _x_x1249 = kk_string_dup(s_0_10118, _ctx); /*string*/
  kk_integer_t _x_x1250 = kk_string_len_int(s_0_10118,kk_context()); /*int*/
  _b_x430_432 = kk_std_core_sslice__new_Sslice(_x_x1249, kk_integer_from_small(0), _x_x1250, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10117 = kk_std_text_parse_parse_eof(_b_x430_432, kk_std_num_float64_new_parse_float64_fun1251(_ctx), _ctx); /*std/text/parse/parse-error<float64>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10117, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x1253 = kk_std_text_parse__as_ParseOk(perr_10117, _ctx);
    kk_box_t _box_x434 = _con_x1253->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x1253->rest;
    double x_0 = kk_double_unbox(_box_x434, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10117, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_box_drop(_box_x434, _ctx);
      kk_datatype_ptr_free(perr_10117, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10117, _ctx);
    }
    return kk_std_core_types__new_Just(kk_double_box(x_0, _ctx), _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x1254 = kk_std_text_parse__as_ParseError(perr_10117, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x1254->rest;
    kk_string_t msg = _con_x1254->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10117, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10117, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10117, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// lifted local: @lift-sum@10335, sum, @spec-x10284
// specialized: std/core/list/@unroll-foreach@10016, on parameters @uniq-action@10278, using:
// @uniq-action@10278 = fn<((local :: H -> X)<(h :: H)>)>(x: float64){
//   val t : float64;
//   val c : float64;
//   val _ : ();
//   std/core/types/local-set<float64,(total :: E),(h :: H)>(total, t);
// }

kk_unit_t kk_std_num_float64__lift_sum_10336(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10277, kk_context_t* _ctx) { /* forall<h> (comp : local-var<h,float64>, total : local-var<h,float64>, list<float64>) -> (local<h>) () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10277, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1255 = kk_std_core_types__as_Cons(_uniq_xs_10277, _ctx);
    kk_box_t _box_x437 = _con_x1255->head;
    kk_std_core_types__list _uniq_xx_10281 = _con_x1255->tail;
    double _uniq_x_10280 = kk_double_unbox(_box_x437, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10277, _ctx)) {
      kk_box_drop(_box_x437, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10277, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10281, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10277, _ctx);
    }
    double t;
    double _x_x1256;
    kk_box_t _x_x1257;
    kk_ref_t _x_x1258 = kk_ref_dup(total, _ctx); /*local-var<5069,float64>*/
    _x_x1257 = kk_ref_get(_x_x1258,kk_context()); /*298*/
    _x_x1256 = kk_double_unbox(_x_x1257, KK_OWNED, _ctx); /*float64*/
    t = (_x_x1256 + _uniq_x_10280); /*float64*/
    double c;
    bool _match_x546;
    double _x_x1259;
    double _x_x1260;
    kk_box_t _x_x1261;
    kk_ref_t _x_x1262 = kk_ref_dup(total, _ctx); /*local-var<5069,float64>*/
    _x_x1261 = kk_ref_get(_x_x1262,kk_context()); /*298*/
    _x_x1260 = kk_double_unbox(_x_x1261, KK_OWNED, _ctx); /*float64*/
    _x_x1259 = kk_double_abs(_x_x1260); /*float64*/
    double _x_x1263 = kk_double_abs(_uniq_x_10280); /*float64*/
    _match_x546 = (_x_x1259 >= _x_x1263); /*bool*/
    if (_match_x546) {
      double _x_x1264;
      double _x_x1265;
      kk_box_t _x_x1266;
      kk_ref_t _x_x1267 = kk_ref_dup(total, _ctx); /*local-var<5069,float64>*/
      _x_x1266 = kk_ref_get(_x_x1267,kk_context()); /*298*/
      _x_x1265 = kk_double_unbox(_x_x1266, KK_OWNED, _ctx); /*float64*/
      _x_x1264 = (_x_x1265 - t); /*float64*/
      c = (_x_x1264 + _uniq_x_10280); /*float64*/
    }
    else {
      double _x_x1268 = (_uniq_x_10280 - t); /*float64*/
      double _x_x1269;
      kk_box_t _x_x1270;
      kk_ref_t _x_x1271 = kk_ref_dup(total, _ctx); /*local-var<5069,float64>*/
      _x_x1270 = kk_ref_get(_x_x1271,kk_context()); /*298*/
      _x_x1269 = kk_double_unbox(_x_x1270, KK_OWNED, _ctx); /*float64*/
      c = (_x_x1268 + _x_x1269); /*float64*/
    }
    double _b_x457_459;
    double _x_x1272;
    kk_box_t _x_x1273;
    kk_ref_t _x_x1274 = kk_ref_dup(comp, _ctx); /*local-var<5069,float64>*/
    _x_x1273 = kk_ref_get(_x_x1274,kk_context()); /*298*/
    _x_x1272 = kk_double_unbox(_x_x1273, KK_OWNED, _ctx); /*float64*/
    _b_x457_459 = (_x_x1272 + c); /*float64*/
    kk_unit_t __ = kk_Unit;
    kk_ref_set_borrow(comp,(kk_double_box(_b_x457_459, _ctx)),kk_context());
    kk_unit_t _uniq_x___10282 = kk_Unit;
    kk_ref_set_borrow(total,(kk_double_box(t, _ctx)),kk_context());
    { // tailcall
      _uniq_xs_10277 = _uniq_xx_10281;
      goto kk__tailcall;
    }
  }
  {
    kk_ref_drop(total, _ctx);
    kk_ref_drop(comp, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: sum, @spec-x10276
// specialized: std/core/list/foreach, on parameters @uniq-action@10273, using:
// @uniq-action@10273 = fn<((local :: H -> X)<(h :: H)>)>(x: float64){
//   val t : float64;
//   val c : float64;
//   val _ : ();
//   std/core/types/local-set<float64,(total :: E),(h :: H)>(total, t);
// }

kk_unit_t kk_std_num_float64__lift_sum_10335(kk_ref_t comp, kk_ref_t total, kk_std_core_types__list _uniq_xs_10272, kk_context_t* _ctx) { /* forall<h> (comp : local-var<h,float64>, total : local-var<h,float64>, list<float64>) -> (local<h>) () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10272, _ctx)) {
    kk_ref_drop(total, _ctx);
    kk_ref_drop(comp, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_std_num_float64__lift_sum_10336(comp, total, _uniq_xs_10272, _ctx); return kk_Unit;
  }
}
 
// Return the sum of a list of floats.
// Uses [Kahan-Babu&scaron;kan-Neumaier summation](https://en.wikipedia.org/wiki/Kahan_summation_algorithm#Further_enhancements)
// to minimize rounding errors. This
// is more precise as Kahan summation and about as fast.
// `[1.0e3,1.0e97,1.0e3,-1.0e97].sum == 2000.0`
// while
// `[1.0e3,1.0e97,1.0e3,-1.0e97].foldl(0.0,(+)) == 0.0` (!)
// A. Neumaier, _Rundungsfehleranalyse einiger Verfahren zur Summation endlicher Summen_.
// Math. Mechanik, 54:39--51, 1974.

double kk_std_num_float64_sum(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  kk_ref_t loc = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<5069,float64>*/;
  kk_ref_t loc_0 = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<5069,float64>*/;
  kk_unit_t ___0 = kk_Unit;
  kk_ref_t _x_x1275 = kk_ref_dup(loc_0, _ctx); /*local-var<5069,float64>*/
  kk_ref_t _x_x1276 = kk_ref_dup(loc, _ctx); /*local-var<5069,float64>*/
  kk_std_num_float64__lift_sum_10335(_x_x1275, _x_x1276, xs, _ctx);
  double res_0;
  double _x_x1277;
  kk_box_t _x_x1278;
  kk_ref_t _x_x1279 = kk_ref_dup(loc, _ctx); /*local-var<5069,float64>*/
  _x_x1278 = kk_ref_get(_x_x1279,kk_context()); /*298*/
  _x_x1277 = kk_double_unbox(_x_x1278, KK_OWNED, _ctx); /*float64*/
  double _x_x1280;
  kk_box_t _x_x1281;
  kk_ref_t _x_x1282 = kk_ref_dup(loc_0, _ctx); /*local-var<5069,float64>*/
  _x_x1281 = kk_ref_get(_x_x1282,kk_context()); /*298*/
  _x_x1280 = kk_double_unbox(_x_x1281, KK_OWNED, _ctx); /*float64*/
  res_0 = (_x_x1277 + _x_x1280); /*float64*/
  double res;
  kk_box_t _x_x1283 = kk_std_core_hnd_prompt_local_var(loc_0, kk_double_box(res_0, _ctx), _ctx); /*4162*/
  res = kk_double_unbox(_x_x1283, KK_OWNED, _ctx); /*float64*/
  kk_box_t _x_x1284 = kk_std_core_hnd_prompt_local_var(loc, kk_double_box(res, _ctx), _ctx); /*4162*/
  return kk_double_unbox(_x_x1284, KK_OWNED, _ctx);
}
 
// The hypotenuse of `x` and `y`: `sqrt(x*x + y*y)`.
// Prevents overflow for large numbers.

double kk_std_num_float64_hypot(double x, double y, kk_context_t* _ctx) { /* (x : float64, y : float64) -> float64 */ 
  double xx = kk_double_abs(x); /*float64*/;
  double yy = kk_double_abs(y); /*float64*/;
  double lo;
  bool _match_x545 = (xx <= yy); /*bool*/;
  if (_match_x545) {
    lo = xx; /*float64*/
  }
  else {
    lo = yy; /*float64*/
  }
  double hi;
  bool _match_x544 = (xx >= yy); /*bool*/;
  if (_match_x544) {
    hi = xx; /*float64*/
  }
  else {
    hi = yy; /*float64*/
  }
  bool _match_x543 = (hi == (0x0p+0)); /*bool*/;
  if (_match_x543) {
    return 0x0p+0;
  }
  {
    double z = (lo / hi); /*float64*/;
    double _x_x1285;
    double _x_x1286;
    double _x_x1287 = (z * z); /*float64*/
    _x_x1286 = (0x1p0 + _x_x1287); /*float64*/
    _x_x1285 = sqrt(_x_x1286); /*float64*/
    return (hi * _x_x1285);
  }
}
 
// The square root of the sum of the squares of three floats.
// Prevents overflow for large numbers.

double kk_std_num_float64_xyz_fs_hypot(double x, double y, double z, kk_context_t* _ctx) { /* (x : float64, y : float64, z : float64) -> float64 */ 
  double xx = kk_double_abs(x); /*float64*/;
  double yy = kk_double_abs(y); /*float64*/;
  double zz = kk_double_abs(z); /*float64*/;
  double x_0_10125;
  bool _match_x542 = (xx >= yy); /*bool*/;
  if (_match_x542) {
    x_0_10125 = xx; /*float64*/
  }
  else {
    x_0_10125 = yy; /*float64*/
  }
  double hi;
  bool _match_x541 = (x_0_10125 >= zz); /*bool*/;
  if (_match_x541) {
    hi = x_0_10125; /*float64*/
  }
  else {
    hi = zz; /*float64*/
  }
  bool _match_x540 = (hi == (0x0p+0)); /*bool*/;
  if (_match_x540) {
    return 0x0p+0;
  }
  {
    double x_4_10131 = (zz / hi); /*float64*/;
    double x_2_10129 = (xx / hi); /*float64*/;
    double x_3_10130 = (yy / hi); /*float64*/;
    double _x_x1288;
    double _x_x1289;
    double _x_x1290;
    double _x_x1291 = (x_2_10129 * x_2_10129); /*float64*/
    double _x_x1292 = (x_3_10130 * x_3_10130); /*float64*/
    _x_x1290 = (_x_x1291 + _x_x1292); /*float64*/
    double _x_x1293 = (x_4_10131 * x_4_10131); /*float64*/
    _x_x1289 = (_x_x1290 + _x_x1293); /*float64*/
    _x_x1288 = sqrt(_x_x1289); /*float64*/
    return (hi * _x_x1288);
  }
}
 
// lifted local: list/@lift-abs-max@10337, list/abs-max, @spec-x10299
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10294, using:
// @uniq-f@10294 = fn(m: float64, x: float64){
//   val x@0@10134 : float64
//         = std/num/float64/abs(x);
//   match ((std/num/float64/(>=)(x@0@10134, m))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10134;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m;
//   };
// }

double kk_std_num_float64_list_fs__lift_abs_max_10338(kk_std_core_types__list _uniq_xs_10292, double _uniq_z_10293, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10292, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1294 = kk_std_core_types__as_Cons(_uniq_xs_10292, _ctx);
    kk_box_t _box_x486 = _con_x1294->head;
    kk_std_core_types__list _uniq_xx_10297 = _con_x1294->tail;
    double _uniq_x_10296 = kk_double_unbox(_box_x486, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10292, _ctx)) {
      kk_box_drop(_box_x486, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10292, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10297, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10292, _ctx);
    }
    double x_0_10134 = kk_double_abs(_uniq_x_10296); /*float64*/;
    { // tailcall
      double _x_x1295;
      bool _match_x538 = (x_0_10134 >= _uniq_z_10293); /*bool*/;
      if (_match_x538) {
        _x_x1295 = x_0_10134; /*float64*/
      }
      else {
        _x_x1295 = _uniq_z_10293; /*float64*/
      }
      _uniq_xs_10292 = _uniq_xx_10297;
      _uniq_z_10293 = _x_x1295;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10293;
  }
}
 
// lifted local: list/abs-max, @spec-x10291
// specialized: std/core/list/foldl, on parameters @uniq-f@10288, using:
// @uniq-f@10288 = fn(m: float64, x: float64){
//   val x@0@10134 : float64
//         = std/num/float64/abs(x);
//   match ((std/num/float64/(>=)(x@0@10134, m))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10134;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m;
//   };
// }

double kk_std_num_float64_list_fs__lift_abs_max_10337(kk_std_core_types__list _uniq_xs_10286, double _uniq_z_10287, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10286, _ctx)) {
    return _uniq_z_10287;
  }
  {
    return kk_std_num_float64_list_fs__lift_abs_max_10338(_uniq_xs_10286, _uniq_z_10287, _ctx);
  }
}
 
// lifted local: list/@lift-hypot@10339, list/hypot, @spec-x10315
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10310, using:
// @uniq-f@10310 = fn(m: float64, x: float64){
//   val x@0@10134 : float64
//         = std/num/float64/abs(x);
//   match ((std/num/float64/(>=)(x@0@10134, m))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10134;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m;
//   };
// }

double kk_std_num_float64_list_fs__lift_hypot_10340(kk_std_core_types__list _uniq_xs_10308, double _uniq_z_10309, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10308, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1296 = kk_std_core_types__as_Cons(_uniq_xs_10308, _ctx);
    kk_box_t _box_x487 = _con_x1296->head;
    kk_std_core_types__list _uniq_xx_10313 = _con_x1296->tail;
    double _uniq_x_10312 = kk_double_unbox(_box_x487, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10308, _ctx)) {
      kk_box_drop(_box_x487, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10308, _ctx);
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10313, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10308, _ctx);
    }
    double x_0_10134 = kk_double_abs(_uniq_x_10312); /*float64*/;
    { // tailcall
      double _x_x1297;
      bool _match_x537 = (x_0_10134 >= _uniq_z_10309); /*bool*/;
      if (_match_x537) {
        _x_x1297 = x_0_10134; /*float64*/
      }
      else {
        _x_x1297 = _uniq_z_10309; /*float64*/
      }
      _uniq_xs_10308 = _uniq_xx_10313;
      _uniq_z_10309 = _x_x1297;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10309;
  }
}
 
// lifted local: list/hypot, @spec-x10307
// specialized: std/core/list/foldl, on parameters @uniq-f@10304, using:
// @uniq-f@10304 = fn(m: float64, x: float64){
//   val x@0@10134 : float64
//         = std/num/float64/abs(x);
//   match ((std/num/float64/(>=)(x@0@10134, m))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> x@0@10134;
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> m;
//   };
// }

double kk_std_num_float64_list_fs__lift_hypot_10339(kk_std_core_types__list _uniq_xs_10302, double _uniq_z_10303, kk_context_t* _ctx) { /* (list<float64>, float64) -> float64 */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10302, _ctx)) {
    return _uniq_z_10303;
  }
  {
    return kk_std_num_float64_list_fs__lift_hypot_10340(_uniq_xs_10302, _uniq_z_10303, _ctx);
  }
}
 
// lifted local: list/@lift-hypot@10341, list/hypot, @spec-x10329
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10324, using:
// @uniq-f@10324 = fn(x@0: float64){
//   val x@0@10136 : float64
//         = std/num/float64/(/)(x@0, hi);
//   std/num/float64/(*)(x@0@10136, x@0@10136);
// }

kk_std_core_types__list kk_std_num_float64_list_fs__trmc_lift_hypot_10342(double hi, kk_std_core_types__list _uniq_xs_10323, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (hi : float64, list<float64>, ctx<list<float64>>) -> list<float64> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10323, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1298 = kk_std_core_types__as_Cons(_uniq_xs_10323, _ctx);
    kk_box_t _box_x488 = _con_x1298->head;
    kk_std_core_types__list _uniq_xx_10327 = _con_x1298->tail;
    double _uniq_x_10326 = kk_double_unbox(_box_x488, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x736 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10323, _ctx)) {
      kk_box_drop(_box_x488, _ctx);
      _ru_x736 = (kk_datatype_ptr_reuse(_uniq_xs_10323, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10327, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10323, _ctx);
    }
    double x_0_10136 = (_uniq_x_10326 / hi); /*float64*/;
    double _trmc_x10347 = (x_0_10136 * x_0_10136); /*float64*/;
    kk_std_core_types__list _trmc_x10348 = kk_datatype_null(); /*list<float64>*/;
    kk_std_core_types__list _trmc_x10349 = kk_std_core_types__new_Cons(_ru_x736, 0, kk_double_box(_trmc_x10347, _ctx), _trmc_x10348, _ctx); /*list<float64>*/;
    kk_field_addr_t _b_x498_503 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10349, _ctx)->tail, _ctx); /*@field-addr<list<float64>>*/;
    kk_std_core_types__cctx _brw_x535;
    kk_std_core_types__cctx _x_x1299 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<float64>>*/
    _brw_x535 = kk_cctx_extend_linear(_x_x1299,(kk_std_core_types__list_box(_trmc_x10349, _ctx)),_b_x498_503,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x536 = kk_std_num_float64_list_fs__trmc_lift_hypot_10342(hi, _uniq_xx_10327, _brw_x535, _ctx); /*list<float64>*/;
    kk_std_core_types__cctx_drop(_brw_x535, _ctx);
    return _brw_x536;
  }
  {
    kk_box_t _x_x1300;
    kk_std_core_types__cctx _x_x1301 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<float64>>*/
    _x_x1300 = kk_cctx_apply_linear(_x_x1301,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1300, KK_OWNED, _ctx);
  }
}
 
// lifted local: list/@lift-hypot@10341, list/hypot, @spec-x10329
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10324, using:
// @uniq-f@10324 = fn(x@0: float64){
//   val x@0@10136 : float64
//         = std/num/float64/(/)(x@0, hi);
//   std/num/float64/(*)(x@0@10136, x@0@10136);
// }

kk_std_core_types__list kk_std_num_float64_list_fs__lift_hypot_10342(double hi_0, kk_std_core_types__list _uniq_xs_10323_0, kk_context_t* _ctx) { /* (hi : float64, list<float64>) -> list<float64> */ 
  kk_std_core_types__cctx _brw_x533 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x534 = kk_std_num_float64_list_fs__trmc_lift_hypot_10342(hi_0, _uniq_xs_10323_0, _brw_x533, _ctx); /*list<float64>*/;
  kk_std_core_types__cctx_drop(_brw_x533, _ctx);
  return _brw_x534;
}
 
// lifted local: list/hypot, @spec-x10322
// specialized: std/core/list/map, on parameters @uniq-f@10319, using:
// @uniq-f@10319 = fn(x@0: float64){
//   val x@0@10136 : float64
//         = std/num/float64/(/)(x@0, hi);
//   std/num/float64/(*)(x@0@10136, x@0@10136);
// }

kk_std_core_types__list kk_std_num_float64_list_fs__lift_hypot_10341(double hi, kk_std_core_types__list _uniq_xs_10318, kk_context_t* _ctx) { /* (hi : float64, list<float64>) -> list<float64> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10318, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x531 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x532 = kk_std_num_float64_list_fs__trmc_lift_hypot_10342(hi, _uniq_xs_10318, _brw_x531, _ctx); /*list<float64>*/;
    kk_std_core_types__cctx_drop(_brw_x531, _ctx);
    return _brw_x532;
  }
}
 
// The square root of the sum of squares of a list of floats.
// Prevents overflow for large numbers and uses Kahan-Babu&scaron;kan-Neumaier summation
// for precision.

double kk_std_num_float64_list_fs_hypot(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<float64>) -> float64 */ 
  double hi;
  kk_std_core_types__list _x_x1302 = kk_std_core_types__list_dup(xs, _ctx); /*list<float64>*/
  hi = kk_std_num_float64_list_fs__lift_hypot_10339(_x_x1302, 0x0p+0, _ctx); /*float64*/
  bool _match_x530 = (hi == (0x0p+0)); /*bool*/;
  if (_match_x530) {
    kk_std_core_types__list_drop(xs, _ctx);
    return 0x0p+0;
  }
  {
    kk_std_core_types__list xs_0_10630 = kk_std_num_float64_list_fs__lift_hypot_10341(hi, xs, _ctx); /*list<float64>*/;
    kk_ref_t loc = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<5069,float64>*/;
    kk_ref_t loc_0 = kk_ref_alloc((kk_double_box(0x0p+0, _ctx)),kk_context()); /*local-var<5069,float64>*/;
    kk_unit_t ___0 = kk_Unit;
    kk_ref_t _x_x1303 = kk_ref_dup(loc_0, _ctx); /*local-var<5069,float64>*/
    kk_ref_t _x_x1304 = kk_ref_dup(loc, _ctx); /*local-var<5069,float64>*/
    kk_std_num_float64__lift_sum_10335(_x_x1303, _x_x1304, xs_0_10630, _ctx);
    double res_0;
    double _x_x1305;
    kk_box_t _x_x1306;
    kk_ref_t _x_x1307 = kk_ref_dup(loc, _ctx); /*local-var<5069,float64>*/
    _x_x1306 = kk_ref_get(_x_x1307,kk_context()); /*298*/
    _x_x1305 = kk_double_unbox(_x_x1306, KK_OWNED, _ctx); /*float64*/
    double _x_x1308;
    kk_box_t _x_x1309;
    kk_ref_t _x_x1310 = kk_ref_dup(loc_0, _ctx); /*local-var<5069,float64>*/
    _x_x1309 = kk_ref_get(_x_x1310,kk_context()); /*298*/
    _x_x1308 = kk_double_unbox(_x_x1309, KK_OWNED, _ctx); /*float64*/
    res_0 = (_x_x1305 + _x_x1308); /*float64*/
    double res;
    kk_box_t _x_x1311 = kk_std_core_hnd_prompt_local_var(loc_0, kk_double_box(res_0, _ctx), _ctx); /*4162*/
    res = kk_double_unbox(_x_x1311, KK_OWNED, _ctx); /*float64*/
    kk_ref_t _b_x525_527 = loc; /*local-var<5069,float64>*/;
    double _b_x526_528 = res; /*float64*/;
    double _x_x1312;
    double _x_x1313;
    kk_box_t _x_x1314 = kk_std_core_hnd_prompt_local_var(_b_x525_527, kk_double_box(_b_x526_528, _ctx), _ctx); /*4162*/
    _x_x1313 = kk_double_unbox(_x_x1314, KK_OWNED, _ctx); /*float64*/
    _x_x1312 = sqrt(_x_x1313); /*float64*/
    return (hi * _x_x1312);
  }
}

double kk_std_num_float64_rad2deg;

double kk_std_num_float64_deg2rad;
 
// The area hyperbolic tangent of `d`

double kk_std_num_float64_atanh(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  return atanh(d);
}
 
// The area hyperbolic cosine of `d`

double kk_std_num_float64_acosh(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  return acosh(d);
}
 
// The area hyperbolic sine of `d`

double kk_std_num_float64_asinh(double d, kk_context_t* _ctx) { /* (d : float64) -> float64 */ 
  return asinh(d);
}

// initialization
void kk_std_num_float64__init(kk_context_t* _ctx){
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
  kk_std_num_int32__init(_ctx);
  kk_std_num_int64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_num_float64_flt_max_prec = kk_integer_from_small(15); /*int*/
  }
  {
    kk_std_num_float64_neginf = kk_std_num_float64_make_neginf(_ctx); /*float64*/
  }
  {
    kk_std_num_float64_posinf = kk_std_num_float64_make_posinf(_ctx); /*float64*/
  }
  {
    kk_std_num_float64_nan = kk_std_num_float64_make_nan(_ctx); /*float64*/
  }
  {
    kk_std_num_float64_rad2deg = ((0x1.68p7) / (0x1.921fb54442d18p1)); /*float64*/
  }
  {
    kk_std_num_float64_deg2rad = ((0x1.921fb54442d18p1) / (0x1.68p7)); /*float64*/
  }
}

// termination
void kk_std_num_float64__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_skip_drop(kk_std_num_float64_deg2rad, _ctx);
  kk_skip_drop(kk_std_num_float64_rad2deg, _ctx);
  kk_skip_drop(kk_std_num_float64_nan, _ctx);
  kk_skip_drop(kk_std_num_float64_posinf, _ctx);
  kk_skip_drop(kk_std_num_float64_neginf, _ctx);
  kk_integer_drop(kk_std_num_float64_flt_max_prec, _ctx);
  kk_std_num_int64__done(_ctx);
  kk_std_num_int32__done(_ctx);
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
