// Koka generated module: std/num/int64, koka version: 3.2.2, platform: 64-bit
#include "std_num_int64.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2023, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_types__tuple2 kk_umul64x_wide( int64_t x, int64_t y, kk_context_t* ctx ) {
  uint64_t hi;
  uint64_t lo = kk_umul64_wide((uint64_t)x, (uint64_t)y, &hi);
  return kk_std_core_types__new_Tuple2( kk_int64_box((int64_t)hi,ctx), kk_int64_box((int64_t)lo,ctx), ctx );
}

static kk_std_core_types__tuple2 kk_imul64x_wide( int64_t x, int64_t y, kk_context_t* ctx ) {
  int64_t hi;
  uint64_t lo = kk_imul64_wide(x, y, &hi);
  return kk_std_core_types__new_Tuple2( kk_int64_box(hi,ctx), kk_int64_box((int64_t)lo,ctx), ctx );
}

static kk_std_core_types__tuple2 kk_clmul64x_wide( int64_t x, int64_t y, kk_context_t* ctx ) {
  uint64_t hi;
  uint64_t lo = kk_clmul64_wide((uint64_t)x, (uint64_t)y, &hi);
  return kk_std_core_types__new_Tuple2( kk_int64_box((int64_t)hi,ctx), kk_int64_box((int64_t)lo,ctx), ctx );
}

 
// clamp an `:int` to fit in an `:int64_t`.

int64_t kk_std_num_int64_int64(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int64 */ 
  return kk_integer_clamp64(i,kk_context());
}
 
// The 64-bit integer for 1.

int64_t kk_std_num_int64_one;
 
// The 64-bit integer for zero.

int64_t kk_std_num_int64_zero;
 
// The maximal integer value before overflow happens

int64_t kk_std_num_int64_max_int64;
 
// The minimal integer value before underflow happens

int64_t kk_std_num_int64_min_int64;
 
// The number of bits in an `:int64` (always 64)

int64_t kk_std_num_int64_bits_int64;
 
// Convert an `:int` to `:int64` but interpret the `int` as an unsigned 64-bit value.
// `i` is clamped between `0` and `0xFFFF_FFFF_FFFF_FFFF`.
// `0x7FFF_FFFF_FFFF_FFFF.uint64 == 0x7FFF_FFFF_FFFF_FFFF.int64 == max-int64`
// `0x8000_0000_0000_0000.uint64 == -0x8000_0000_0000_0000.int64 == min-int64`
// `0xFFFF_FFFF_FFFF_FFFF.uint64 == -1.int64`

int64_t kk_std_num_int64_int_fs_uint64(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int64 */ 
  kk_integer_t _x_x306;
  bool _match_x287;
  kk_integer_t _brw_x288 = kk_integer_from_int64(kk_std_num_int64_max_int64,kk_context()); /*int*/;
  bool _brw_x289 = kk_integer_gt_borrow(i,_brw_x288,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x288, _ctx);
  _match_x287 = _brw_x289; /*bool*/
  if (_match_x287) {
    _x_x306 = kk_integer_sub(i,(kk_integer_from_str("18446744073709551616", _ctx)),kk_context()); /*int*/
  }
  else {
    _x_x306 = i; /*int*/
  }
  return kk_std_num_int64_int64(_x_x306, _ctx);
}
 
// Show an `:int64` in hexadecimal notation
// The `width`  parameter specifies how wide the hex value is where `'0'`  is used to align.
// The `use-capitals` parameter (= `True`) determines if capital letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_num_int64_show_hex(int64_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int64, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
  kk_integer_t _x_x307 = kk_integer_from_int64(i,kk_context()); /*int*/
  kk_std_core_types__optional _x_x308;
  kk_box_t _x_x309;
  kk_integer_t _x_x310;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x4 = width._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x4, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _x_x310 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _x_x310 = kk_integer_from_small(1); /*int*/
  }
  _x_x309 = kk_integer_box(_x_x310, _ctx); /*7*/
  _x_x308 = kk_std_core_types__new_Optional(_x_x309, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x311;
  kk_box_t _x_x312;
  bool _x_x313;
  if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
    kk_box_t _box_x6 = use_capitals._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x6);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x313 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x313 = true; /*bool*/
  }
  _x_x312 = kk_bool_box(_x_x313); /*7*/
  _x_x311 = kk_std_core_types__new_Optional(_x_x312, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x314;
  kk_box_t _x_x315;
  kk_string_t _x_x316;
  if (kk_std_core_types__is_Optional(pre, _ctx)) {
    kk_box_t _box_x8 = pre._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x8);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x_x316 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_define_string_literal(, _s_x317, 2, "0x", _ctx)
    _x_x316 = kk_string_dup(_s_x317, _ctx); /*string*/
  }
  _x_x315 = kk_string_box(_x_x316); /*7*/
  _x_x314 = kk_std_core_types__new_Optional(_x_x315, _ctx); /*? 7*/
  return kk_std_core_show_show_hex(_x_x307, _x_x308, _x_x311, _x_x314, _ctx);
}
 
// Show an `:int64` in hexadecimal notation interpreted as an unsigned 64-bit value.
// The `width`  parameter specifies how wide the hex value is where `'0'`  is used to align.
// The `use-capitals` parameter (= `True`) determines if capital letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number.

kk_string_t kk_std_num_int64_show_hex64(int64_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int64, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
  kk_integer_t _x_x318 = kk_std_num_int64_int64_fs_uint(i, _ctx); /*int*/
  kk_std_core_types__optional _x_x319;
  kk_box_t _x_x320;
  kk_integer_t _x_x321;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x13 = width._cons._Optional.value;
    kk_integer_t _uniq_width_629 = kk_integer_unbox(_box_x13, _ctx);
    kk_integer_dup(_uniq_width_629, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _x_x321 = _uniq_width_629; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _x_x321 = kk_integer_from_small(16); /*int*/
  }
  _x_x320 = kk_integer_box(_x_x321, _ctx); /*7*/
  _x_x319 = kk_std_core_types__new_Optional(_x_x320, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x322;
  kk_box_t _x_x323;
  bool _x_x324;
  if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
    kk_box_t _box_x15 = use_capitals._cons._Optional.value;
    bool _uniq_use_capitals_633 = kk_bool_unbox(_box_x15);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x324 = _uniq_use_capitals_633; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x324 = true; /*bool*/
  }
  _x_x323 = kk_bool_box(_x_x324); /*7*/
  _x_x322 = kk_std_core_types__new_Optional(_x_x323, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x325;
  kk_box_t _x_x326;
  kk_string_t _x_x327;
  if (kk_std_core_types__is_Optional(pre, _ctx)) {
    kk_box_t _box_x17 = pre._cons._Optional.value;
    kk_string_t _uniq_pre_637 = kk_string_unbox(_box_x17);
    kk_string_dup(_uniq_pre_637, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x_x327 = _uniq_pre_637; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_define_string_literal(, _s_x328, 2, "0x", _ctx)
    _x_x327 = kk_string_dup(_s_x328, _ctx); /*string*/
  }
  _x_x326 = kk_string_box(_x_x327); /*7*/
  _x_x325 = kk_std_core_types__new_Optional(_x_x326, _ctx); /*? 7*/
  return kk_std_core_show_show_hex(_x_x318, _x_x319, _x_x322, _x_x325, _ctx);
}
 
// Return the absolute value of an integer.
// Raises an exception if the `:int64` is `min-int64`
// (since the negation of `min-int64` equals itself and is still negative)

int64_t kk_std_num_int64_abs(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> exn int64 */ 
  bool _x_x1_10209 = 0 > i; /*bool*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (_x_x1_10209) {
    bool _match_x279 = (i > kk_std_num_int64_min_int64); /*bool*/;
    if (_match_x279) {
      kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<exn>*/;
      int64_t x_0;
      int64_t _x_x334 = (KK_I64(0)); /*int64*/
      x_0 = (int64_t)((uint64_t)_x_x334 - (uint64_t)i); /*int64*/
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_0,kk_context());
      return x_0;
    }
    {
      kk_std_core_hnd__ev ev_10219 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
      kk_box_t _x_x335;
      {
        struct kk_std_core_hnd_Ev* _con_x336 = kk_std_core_hnd__as_Ev(ev_10219, _ctx);
        kk_box_t _box_x22 = _con_x336->hnd;
        int32_t m = _con_x336->marker;
        kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x22, KK_BORROWED, _ctx);
        kk_std_core_exn__exn_dup(h, _ctx);
        kk_std_core_hnd__clause1 _match_x280;
        kk_std_core_hnd__clause1 _brw_x282 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
        kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
        _match_x280 = _brw_x282; /*hnd/clause1<exception,276,exn,277,278>*/
        {
          kk_function_t _fun_unbox_x26 = _match_x280.clause;
          kk_box_t _x_x337;
          kk_std_core_exn__exception _x_x338;
          kk_string_t _x_x339;
          kk_define_string_literal(, _s_x340, 79, "std/num/int64/abs: cannot make min-int64 into a positive int64 without overflow", _ctx)
          _x_x339 = kk_string_dup(_s_x340, _ctx); /*string*/
          kk_std_core_exn__exception_info _x_x341;
          kk_std_core_types__optional _match_x281 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x281, _ctx)) {
            kk_box_t _box_x30 = _match_x281._cons._Optional.value;
            kk_std_core_exn__exception_info _uniq_info_399 = kk_std_core_exn__exception_info_unbox(_box_x30, KK_BORROWED, _ctx);
            kk_std_core_exn__exception_info_dup(_uniq_info_399, _ctx);
            kk_std_core_types__optional_drop(_match_x281, _ctx);
            _x_x341 = _uniq_info_399; /*exception-info*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x281, _ctx);
            _x_x341 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
          }
          _x_x338 = kk_std_core_exn__new_Exception(_x_x339, _x_x341, _ctx); /*exception*/
          _x_x337 = kk_std_core_exn__exception_box(_x_x338, _ctx); /*45*/
          _x_x335 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x26, (_fun_unbox_x26, m, ev_10219, _x_x337, _ctx), _ctx); /*46*/
        }
      }
      return kk_int64_unbox(_x_x335, KK_OWNED, _ctx);
    }
  }
  {
    return i;
  }
}
 
// Return the absolute value of an integer.
// Returns 0 if the `:int64` is `min-int64`
// (since the negation of `min-int64` equals itself and is still negative)

int64_t kk_std_num_int64_abs0(int64_t i, kk_context_t* _ctx) { /* (i : int64) -> int64 */ 
  bool b_10011 = 0 > i; /*bool*/;
  if (b_10011) {
    bool _match_x278 = (i > kk_std_num_int64_min_int64); /*bool*/;
    if (_match_x278) {
      int64_t _x_x342 = (KK_I64(0)); /*int64*/
      return (int64_t)((uint64_t)_x_x342 - (uint64_t)i);
    }
    {
      return (KK_I64(0));
    }
  }
  {
    return i;
  }
}
 
// Wide carry-less multiplication (or _xor_ multiplication) to `(hi,lo)`,
// where `(hi,lo).int == hi.int * 0x1_0000_0000_0000_0000 + lo.uint`.
// See also <https://en.wikipedia.org/wiki/Carry-less_product>.

kk_std_core_types__tuple2 kk_std_num_int64_clmul_wide(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> (int64, int64) */ 
  return kk_clmul64x_wide(x,y,kk_context());
}
 
// Full 64x64 to 128-bit unsigned multiply to `(hi,lo)`.
// where `umul(x,y).uint == x.uint * y.uint`

kk_std_core_types__tuple2 kk_std_num_int64_umul(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> (int64, int64) */ 
  return kk_umul64x_wide(i,j,kk_context());
}
 
// Full 64x64 to 128-bit signed multiply to `(hi,lo)`.
// where `imul(x,y).int == x.int * y.int`

kk_std_core_types__tuple2 kk_std_num_int64_imul(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> (int64, int64) */ 
  return kk_imul64x_wide(i,j,kk_context());
}
 
// Truncated division (as in C). See also `(/):(x : int64, y : int64) -> int64`.

int64_t kk_std_num_int64_cdiv(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> exn int64 */ 
  bool _match_x267 = 0 == j; /*bool*/;
  if (_match_x267) {
    kk_std_core_hnd__ev ev_10222 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x349;
    {
      struct kk_std_core_hnd_Ev* _con_x350 = kk_std_core_hnd__as_Ev(ev_10222, _ctx);
      kk_box_t _box_x31 = _con_x350->hnd;
      int32_t m = _con_x350->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x31, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x273;
      kk_std_core_hnd__clause1 _brw_x275 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x273 = _brw_x275; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x35 = _match_x273.clause;
        kk_box_t _x_x351;
        kk_std_core_exn__exception _x_x352;
        kk_string_t _x_x353;
        kk_define_string_literal(, _s_x354, 36, "std/num/int64/cdiv: division by zero", _ctx)
        _x_x353 = kk_string_dup(_s_x354, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x355;
        kk_std_core_types__optional _match_x274 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x274, _ctx)) {
          kk_box_t _box_x39 = _match_x274._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_399 = kk_std_core_exn__exception_info_unbox(_box_x39, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_399, _ctx);
          kk_std_core_types__optional_drop(_match_x274, _ctx);
          _x_x355 = _uniq_info_399; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x274, _ctx);
          _x_x355 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x352 = kk_std_core_exn__new_Exception(_x_x353, _x_x355, _ctx); /*exception*/
        _x_x351 = kk_std_core_exn__exception_box(_x_x352, _ctx); /*45*/
        _x_x349 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x35, (_fun_unbox_x35, m, ev_10222, _x_x351, _ctx), _ctx); /*46*/
      }
    }
    return kk_int64_unbox(_x_x349, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<exn>*/;
    int64_t x_0 = (KK_I64(-1)); /*int64*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    bool _match_x268 = (j == x_0); /*bool*/;
    if (_match_x268) {
      bool _match_x269 = (i == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_x269) {
        kk_std_core_hnd__ev ev_0_10227 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
        kk_box_t _x_x356;
        {
          struct kk_std_core_hnd_Ev* _con_x357 = kk_std_core_hnd__as_Ev(ev_0_10227, _ctx);
          kk_box_t _box_x40 = _con_x357->hnd;
          int32_t m_0 = _con_x357->marker;
          kk_std_core_exn__exn h_0 = kk_std_core_exn__exn_unbox(_box_x40, KK_BORROWED, _ctx);
          kk_std_core_exn__exn_dup(h_0, _ctx);
          kk_std_core_hnd__clause1 _match_x270;
          kk_std_core_hnd__clause1 _brw_x272 = kk_std_core_exn_throw_exn_fs__select(h_0, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
          kk_datatype_ptr_dropn(h_0, (KK_I32(2)), _ctx);
          _match_x270 = _brw_x272; /*hnd/clause1<exception,276,exn,277,278>*/
          {
            kk_function_t _fun_unbox_x44 = _match_x270.clause;
            kk_box_t _x_x358;
            kk_std_core_exn__exception _x_x359;
            kk_string_t _x_x360;
            kk_define_string_literal(, _s_x361, 66, "std/num/int64/cdiv: division overflow in cdiv(min-int64, -1.int64)", _ctx)
            _x_x360 = kk_string_dup(_s_x361, _ctx); /*string*/
            kk_std_core_exn__exception_info _x_x362;
            kk_std_core_types__optional _match_x271 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x271, _ctx)) {
              kk_box_t _box_x48 = _match_x271._cons._Optional.value;
              kk_std_core_exn__exception_info _uniq_info_399_0 = kk_std_core_exn__exception_info_unbox(_box_x48, KK_BORROWED, _ctx);
              kk_std_core_exn__exception_info_dup(_uniq_info_399_0, _ctx);
              kk_std_core_types__optional_drop(_match_x271, _ctx);
              _x_x362 = _uniq_info_399_0; /*exception-info*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x271, _ctx);
              _x_x362 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
            }
            _x_x359 = kk_std_core_exn__new_Exception(_x_x360, _x_x362, _ctx); /*exception*/
            _x_x358 = kk_std_core_exn__exception_box(_x_x359, _ctx); /*45*/
            _x_x356 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x44, (_fun_unbox_x44, m_0, ev_0_10227, _x_x358, _ctx), _ctx); /*46*/
          }
        }
        return kk_int64_unbox(_x_x356, KK_OWNED, _ctx);
      }
      {
        return i / j;
      }
    }
    {
      return i / j;
    }
  }
}
 
// Truncated modulus (as in C). See also `(%):(x : int64, y : int64) -> int64`.

int64_t kk_std_num_int64_cmod(int64_t i, int64_t j, kk_context_t* _ctx) { /* (i : int64, j : int64) -> exn int64 */ 
  bool _match_x258 = 0 == j; /*bool*/;
  if (_match_x258) {
    kk_std_core_hnd__ev ev_10230 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x363;
    {
      struct kk_std_core_hnd_Ev* _con_x364 = kk_std_core_hnd__as_Ev(ev_10230, _ctx);
      kk_box_t _box_x49 = _con_x364->hnd;
      int32_t m = _con_x364->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x49, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x264;
      kk_std_core_hnd__clause1 _brw_x266 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x264 = _brw_x266; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x53 = _match_x264.clause;
        kk_box_t _x_x365;
        kk_std_core_exn__exception _x_x366;
        kk_string_t _x_x367;
        kk_define_string_literal(, _s_x368, 35, "std/num/int64/cmod: modulus by zero", _ctx)
        _x_x367 = kk_string_dup(_s_x368, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x369;
        kk_std_core_types__optional _match_x265 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x265, _ctx)) {
          kk_box_t _box_x57 = _match_x265._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_399 = kk_std_core_exn__exception_info_unbox(_box_x57, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_399, _ctx);
          kk_std_core_types__optional_drop(_match_x265, _ctx);
          _x_x369 = _uniq_info_399; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x265, _ctx);
          _x_x369 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x366 = kk_std_core_exn__new_Exception(_x_x367, _x_x369, _ctx); /*exception*/
        _x_x365 = kk_std_core_exn__exception_box(_x_x366, _ctx); /*45*/
        _x_x363 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x53, (_fun_unbox_x53, m, ev_10230, _x_x365, _ctx), _ctx); /*46*/
      }
    }
    return kk_int64_unbox(_x_x363, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<exn>*/;
    int64_t x_0 = (KK_I64(-1)); /*int64*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    bool _match_x259 = (j == x_0); /*bool*/;
    if (_match_x259) {
      bool _match_x260 = (i == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_x260) {
        kk_std_core_hnd__ev ev_0_10235 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
        kk_box_t _x_x370;
        {
          struct kk_std_core_hnd_Ev* _con_x371 = kk_std_core_hnd__as_Ev(ev_0_10235, _ctx);
          kk_box_t _box_x58 = _con_x371->hnd;
          int32_t m_0 = _con_x371->marker;
          kk_std_core_exn__exn h_0 = kk_std_core_exn__exn_unbox(_box_x58, KK_BORROWED, _ctx);
          kk_std_core_exn__exn_dup(h_0, _ctx);
          kk_std_core_hnd__clause1 _match_x261;
          kk_std_core_hnd__clause1 _brw_x263 = kk_std_core_exn_throw_exn_fs__select(h_0, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
          kk_datatype_ptr_dropn(h_0, (KK_I32(2)), _ctx);
          _match_x261 = _brw_x263; /*hnd/clause1<exception,276,exn,277,278>*/
          {
            kk_function_t _fun_unbox_x62 = _match_x261.clause;
            kk_box_t _x_x372;
            kk_std_core_exn__exception _x_x373;
            kk_string_t _x_x374;
            kk_define_string_literal(, _s_x375, 65, "std/num/int64/cmod: modulus overflow in cmod(min-int64, -1.int64)", _ctx)
            _x_x374 = kk_string_dup(_s_x375, _ctx); /*string*/
            kk_std_core_exn__exception_info _x_x376;
            kk_std_core_types__optional _match_x262 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x262, _ctx)) {
              kk_box_t _box_x66 = _match_x262._cons._Optional.value;
              kk_std_core_exn__exception_info _uniq_info_399_0 = kk_std_core_exn__exception_info_unbox(_box_x66, KK_BORROWED, _ctx);
              kk_std_core_exn__exception_info_dup(_uniq_info_399_0, _ctx);
              kk_std_core_types__optional_drop(_match_x262, _ctx);
              _x_x376 = _uniq_info_399_0; /*exception-info*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x262, _ctx);
              _x_x376 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
            }
            _x_x373 = kk_std_core_exn__new_Exception(_x_x374, _x_x376, _ctx); /*exception*/
            _x_x372 = kk_std_core_exn__exception_box(_x_x373, _ctx); /*45*/
            _x_x370 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x62, (_fun_unbox_x62, m_0, ev_0_10235, _x_x372, _ctx), _ctx); /*46*/
          }
        }
        return kk_int64_unbox(_x_x370, KK_OWNED, _ctx);
      }
      {
        return i % j;
      }
    }
    {
      return i % j;
    }
  }
}
 
// /*
// Euclidean-0 division.
// Euclidean division is defined as: For any `D`  and `d`  where `d!=0` , we have:
// 
// 1. `D == d*(D/d) + (D%d)`
// 2. `D%d`  is always positive where `0 <= D%d < abs(d)`
// 
// Moreover, Euclidean-0 is a total function, for the case where `d==0`  we have
// that `D%0 == D`  and `D/0 == 0` . So property (1) still holds, but not property (2).
// Useful laws that hold for Euclidean-0 division:
// 
// * `D/(-d) == -(D/d)`
// * `D%(-d) == D%d`
// * `D/(2^n) == sar(D,n)         `  (with `0 <= n <= 63`)
// * `D%(2^n) == D & ((2^n) - 1)  `  (with `0 <= n <= 63`)
// 
// Note that an interesting edge case is `min-int64 / -1` which equals `min-int64` since in modulo 64-bit
// arithmetic `min-int64 == -1 * min-int64 == -1 * (min-int64 / -1) + (min-int64 % -1)` satisfying property (1).
// Of course `(min-int64 + 1) / -1` is again positive (namely `max-int64`).
// 
// See also _Division and modulus for computer scientists, Daan Leijen, 2001_
// [pdf](https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/divmodnote-letter.pdf) .
// */

int64_t kk_std_num_int64__lp__fs__rp_(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> int64 */ 
  bool _match_x251;
  int64_t _x_x378 = (KK_I64(0)); /*int64*/
  _match_x251 = (y == _x_x378); /*bool*/
  if (_match_x251) {
    return (KK_I64(0));
  }
  {
    bool _match_x252;
    int64_t _x_x379 = (KK_I64(-1)); /*int64*/
    _match_x252 = (y == _x_x379); /*bool*/
    if (_match_x252) {
      bool _match_x255 = (x == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_x255) {
        return x;
      }
      {
        int64_t q = x / y; /*int64*/;
        int64_t r = x % y; /*int64*/;
        bool _match_x256;
        int64_t _x_x380 = (KK_I64(0)); /*int64*/
        _match_x256 = (r >= _x_x380); /*bool*/
        if (_match_x256) {
          return q;
        }
        {
          bool _match_x257;
          int64_t _x_x381 = (KK_I64(0)); /*int64*/
          _match_x257 = (y > _x_x381); /*bool*/
          if (_match_x257) {
            int64_t _x_x382 = (KK_I64(1)); /*int64*/
            return (int64_t)((uint64_t)q - (uint64_t)_x_x382);
          }
          {
            int64_t _x_x383 = (KK_I64(1)); /*int64*/
            return (int64_t)((uint64_t)q + (uint64_t)_x_x383);
          }
        }
      }
    }
    {
      int64_t q_0 = x / y; /*int64*/;
      int64_t r_0 = x % y; /*int64*/;
      bool _match_x253;
      int64_t _x_x384 = (KK_I64(0)); /*int64*/
      _match_x253 = (r_0 >= _x_x384); /*bool*/
      if (_match_x253) {
        return q_0;
      }
      {
        bool _match_x254;
        int64_t _x_x385 = (KK_I64(0)); /*int64*/
        _match_x254 = (y > _x_x385); /*bool*/
        if (_match_x254) {
          int64_t _x_x386 = (KK_I64(1)); /*int64*/
          return (int64_t)((uint64_t)q_0 - (uint64_t)_x_x386);
        }
        {
          int64_t _x_x387 = (KK_I64(1)); /*int64*/
          return (int64_t)((uint64_t)q_0 + (uint64_t)_x_x387);
        }
      }
    }
  }
}
 
// Euclidean-0 modulus. See `(/):(x : int64, y : int64) -> int64` division for more information.

int64_t kk_std_num_int64__lp__perc__rp_(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> int64 */ 
  bool _match_x244;
  int64_t _x_x388 = (KK_I64(0)); /*int64*/
  _match_x244 = (y == _x_x388); /*bool*/
  if (_match_x244) {
    return x;
  }
  {
    bool _match_x245;
    int64_t _x_x389 = (KK_I64(-1)); /*int64*/
    _match_x245 = (y == _x_x389); /*bool*/
    if (_match_x245) {
      bool _match_x248 = (x == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_x248) {
        return (KK_I64(0));
      }
      {
        int64_t r = x % y; /*int64*/;
        bool _match_x249;
        int64_t _x_x390 = (KK_I64(0)); /*int64*/
        _match_x249 = (r >= _x_x390); /*bool*/
        if (_match_x249) {
          return r;
        }
        {
          bool _match_x250;
          int64_t _x_x391 = (KK_I64(0)); /*int64*/
          _match_x250 = (y > _x_x391); /*bool*/
          if (_match_x250) {
            return (int64_t)((uint64_t)r + (uint64_t)y);
          }
          {
            return (int64_t)((uint64_t)r - (uint64_t)y);
          }
        }
      }
    }
    {
      int64_t r_0 = x % y; /*int64*/;
      bool _match_x246;
      int64_t _x_x392 = (KK_I64(0)); /*int64*/
      _match_x246 = (r_0 >= _x_x392); /*bool*/
      if (_match_x246) {
        return r_0;
      }
      {
        bool _match_x247;
        int64_t _x_x393 = (KK_I64(0)); /*int64*/
        _match_x247 = (y > _x_x393); /*bool*/
        if (_match_x247) {
          return (int64_t)((uint64_t)r_0 + (uint64_t)y);
        }
        {
          return (int64_t)((uint64_t)r_0 - (uint64_t)y);
        }
      }
    }
  }
}

kk_std_core_types__tuple2 kk_std_num_int64_divmod(int64_t x, int64_t y, kk_context_t* _ctx) { /* (x : int64, y : int64) -> (int64, int64) */ 
  bool _match_x237 = 0 == y; /*bool*/;
  if (_match_x237) {
    return kk_std_core_types__new_Tuple2(kk_int64_box(kk_std_num_int64_zero, _ctx), kk_int64_box(x, _ctx), _ctx);
  }
  {
    bool _match_x238;
    int64_t _x_x394 = (KK_I64(-1)); /*int64*/
    _match_x238 = (y == _x_x394); /*bool*/
    if (_match_x238) {
      bool _match_x241 = (x == kk_std_num_int64_min_int64); /*bool*/;
      if (_match_x241) {
        int64_t _b_x70_86 = (KK_I64(0)); /*int64*/;
        return kk_std_core_types__new_Tuple2(kk_int64_box(x, _ctx), kk_int64_box(_b_x70_86, _ctx), _ctx);
      }
      {
        int64_t q = x / y; /*int64*/;
        int64_t r = x % y; /*int64*/;
        bool _match_x242;
        int64_t _x_x395 = (KK_I64(0)); /*int64*/
        _match_x242 = (r >= _x_x395); /*bool*/
        if (_match_x242) {
          return kk_std_core_types__new_Tuple2(kk_int64_box(q, _ctx), kk_int64_box(r, _ctx), _ctx);
        }
        {
          bool _match_x243;
          int64_t _x_x396 = (KK_I64(0)); /*int64*/
          _match_x243 = (y > _x_x396); /*bool*/
          if (_match_x243) {
            int64_t _b_x73_89;
            int64_t _x_x397 = (KK_I64(1)); /*int64*/
            _b_x73_89 = (int64_t)((uint64_t)q - (uint64_t)_x_x397); /*int64*/
            int64_t _b_x74_90 = (int64_t)((uint64_t)r + (uint64_t)y); /*int64*/;
            return kk_std_core_types__new_Tuple2(kk_int64_box(_b_x73_89, _ctx), kk_int64_box(_b_x74_90, _ctx), _ctx);
          }
          {
            int64_t _b_x75_91;
            int64_t _x_x398 = (KK_I64(1)); /*int64*/
            _b_x75_91 = (int64_t)((uint64_t)q + (uint64_t)_x_x398); /*int64*/
            int64_t _b_x76_92 = (int64_t)((uint64_t)r - (uint64_t)y); /*int64*/;
            return kk_std_core_types__new_Tuple2(kk_int64_box(_b_x75_91, _ctx), kk_int64_box(_b_x76_92, _ctx), _ctx);
          }
        }
      }
    }
    {
      int64_t q_0 = x / y; /*int64*/;
      int64_t r_0 = x % y; /*int64*/;
      bool _match_x239;
      int64_t _x_x399 = (KK_I64(0)); /*int64*/
      _match_x239 = (r_0 >= _x_x399); /*bool*/
      if (_match_x239) {
        return kk_std_core_types__new_Tuple2(kk_int64_box(q_0, _ctx), kk_int64_box(r_0, _ctx), _ctx);
      }
      {
        bool _match_x240;
        int64_t _x_x400 = (KK_I64(0)); /*int64*/
        _match_x240 = (y > _x_x400); /*bool*/
        if (_match_x240) {
          int64_t _b_x79_95;
          int64_t _x_x401 = (KK_I64(1)); /*int64*/
          _b_x79_95 = (int64_t)((uint64_t)q_0 - (uint64_t)_x_x401); /*int64*/
          int64_t _b_x80_96 = (int64_t)((uint64_t)r_0 + (uint64_t)y); /*int64*/;
          return kk_std_core_types__new_Tuple2(kk_int64_box(_b_x79_95, _ctx), kk_int64_box(_b_x80_96, _ctx), _ctx);
        }
        {
          int64_t _b_x81_97;
          int64_t _x_x402 = (KK_I64(1)); /*int64*/
          _b_x81_97 = (int64_t)((uint64_t)q_0 + (uint64_t)_x_x402); /*int64*/
          int64_t _b_x82_98 = (int64_t)((uint64_t)r_0 - (uint64_t)y); /*int64*/;
          return kk_std_core_types__new_Tuple2(kk_int64_box(_b_x81_97, _ctx), kk_int64_box(_b_x82_98, _ctx), _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_box_t kk_std_num_int64_range_fs__mlift_fold_int64_10213(int64_t end, kk_function_t f, int64_t start, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (end : int64, f : (int64, a) -> e a, start : int64, x : a) -> e a */ 
  int64_t _x_x403;
  int64_t _x_x404 = (KK_I64(1)); /*int64*/
  _x_x403 = (int64_t)((uint64_t)start + (uint64_t)_x_x404); /*int64*/
  return kk_std_num_int64_range_fs_fold_int64(_x_x403, end, x, f, _ctx);
}


// lift anonymous function
struct kk_std_num_int64_range_fs_fold_int64_fun406__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  int64_t end_0;
  int64_t start_0;
};
static kk_box_t kk_std_num_int64_range_fs_fold_int64_fun406(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx);
static kk_function_t kk_std_num_int64_range_fs_new_fold_int64_fun406(kk_function_t f_0, int64_t end_0, int64_t start_0, kk_context_t* _ctx) {
  struct kk_std_num_int64_range_fs_fold_int64_fun406__t* _self = kk_function_alloc_as(struct kk_std_num_int64_range_fs_fold_int64_fun406__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_int64_range_fs_fold_int64_fun406, kk_context());
  _self->f_0 = f_0;
  _self->end_0 = end_0;
  _self->start_0 = start_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_int64_range_fs_fold_int64_fun406(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx) {
  struct kk_std_num_int64_range_fs_fold_int64_fun406__t* _self = kk_function_as(struct kk_std_num_int64_range_fs_fold_int64_fun406__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (int64, 3525) -> 3526 3525 */
  int64_t end_0 = _self->end_0; /* int64 */
  int64_t start_0 = _self->start_0; /* int64 */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_skip_dup(end_0, _ctx);kk_skip_dup(start_0, _ctx);}, {}, _ctx)
  return kk_std_num_int64_range_fs__mlift_fold_int64_10213(end_0, f_0, start_0, x_1, _ctx);
}

kk_box_t kk_std_num_int64_range_fs_fold_int64(int64_t start_0, int64_t end_0, kk_box_t init, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,e> (start : int64, end : int64, init : a, f : (int64, a) -> e a) -> e a */ 
  kk__tailcall: ;
  bool _match_x235 = (start_0 > end_0); /*bool*/;
  if (_match_x235) {
    kk_function_drop(f_0, _ctx);
    return init;
  }
  {
    kk_box_t x_0_10238;
    kk_function_t _x_x405 = kk_function_dup(f_0, _ctx); /*(int64, 3525) -> 3526 3525*/
    x_0_10238 = kk_function_call(kk_box_t, (kk_function_t, int64_t, kk_box_t, kk_context_t*), _x_x405, (_x_x405, start_0, init, _ctx), _ctx); /*3525*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10238, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_num_int64_range_fs_new_fold_int64_fun406(f_0, end_0, start_0, _ctx), _ctx);
    }
    { // tailcall
      int64_t _x_x407;
      int64_t _x_x408 = (KK_I64(1)); /*int64*/
      _x_x407 = (int64_t)((uint64_t)start_0 + (uint64_t)_x_x408); /*int64*/
      start_0 = _x_x407;
      init = x_0_10238;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_num_int64_range_fs__mlift_lift_for_while64_4126_10214(kk_function_t action, int64_t end, int64_t i, kk_std_core_types__maybe _y_x10195, kk_context_t* _ctx) { /* forall<a,e> (action : (int64) -> e maybe<a>, end : int64, i : int64, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10195, _ctx)) {
    int64_t i_0_10029;
    int64_t _x_x411 = (KK_I64(1)); /*int64*/
    i_0_10029 = (int64_t)((uint64_t)i + (uint64_t)_x_x411); /*int64*/
    return kk_std_num_int64_range_fs__lift_for_while64_4126(action, end, i_0_10029, _ctx);
  }
  {
    kk_box_t x = _y_x10195._cons.Just.value;
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Just(x, _ctx);
  }
}
 
// lifted local: range/for-while64, rep


// lift anonymous function
struct kk_std_num_int64_range_fs__lift_for_while64_4126_fun414__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  int64_t end_0;
  int64_t i_0;
};
static kk_box_t kk_std_num_int64_range_fs__lift_for_while64_4126_fun414(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx);
static kk_function_t kk_std_num_int64_range_fs__new_lift_for_while64_4126_fun414(kk_function_t action_0, int64_t end_0, int64_t i_0, kk_context_t* _ctx) {
  struct kk_std_num_int64_range_fs__lift_for_while64_4126_fun414__t* _self = kk_function_alloc_as(struct kk_std_num_int64_range_fs__lift_for_while64_4126_fun414__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_num_int64_range_fs__lift_for_while64_4126_fun414, kk_context());
  _self->action_0 = action_0;
  _self->end_0 = end_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_num_int64_range_fs__lift_for_while64_4126_fun414(kk_function_t _fself, kk_box_t _b_x100, kk_context_t* _ctx) {
  struct kk_std_num_int64_range_fs__lift_for_while64_4126_fun414__t* _self = kk_function_as(struct kk_std_num_int64_range_fs__lift_for_while64_4126_fun414__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (int64) -> 3634 maybe<3633> */
  int64_t end_0 = _self->end_0; /* int64 */
  int64_t i_0 = _self->i_0; /* int64 */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_skip_dup(end_0, _ctx);kk_skip_dup(i_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10195_0_102 = kk_std_core_types__maybe_unbox(_b_x100, KK_OWNED, _ctx); /*maybe<3633>*/;
  kk_std_core_types__maybe _x_x415 = kk_std_num_int64_range_fs__mlift_lift_for_while64_4126_10214(action_0, end_0, i_0, _y_x10195_0_102, _ctx); /*maybe<3633>*/
  return kk_std_core_types__maybe_box(_x_x415, _ctx);
}

kk_std_core_types__maybe kk_std_num_int64_range_fs__lift_for_while64_4126(kk_function_t action_0, int64_t end_0, int64_t i_0, kk_context_t* _ctx) { /* forall<a,e> (action : (int64) -> e maybe<a>, end : int64, i : int64) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_x233 = (i_0 <= end_0); /*bool*/;
  if (_match_x233) {
    kk_std_core_types__maybe x_0_10241;
    kk_function_t _x_x412 = kk_function_dup(action_0, _ctx); /*(int64) -> 3634 maybe<3633>*/
    x_0_10241 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, int64_t, kk_context_t*), _x_x412, (_x_x412, i_0, _ctx), _ctx); /*maybe<3633>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10241, _ctx);
      kk_box_t _x_x413 = kk_std_core_hnd_yield_extend(kk_std_num_int64_range_fs__new_lift_for_while64_4126_fun414(action_0, end_0, i_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x413, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10241, _ctx)) {
      int64_t i_0_10029_0;
      int64_t _x_x416 = (KK_I64(1)); /*int64*/
      i_0_10029_0 = (int64_t)((uint64_t)i_0 + (uint64_t)_x_x416); /*int64*/
      { // tailcall
        i_0 = i_0_10029_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t x_1 = x_0_10241._cons.Just.value;
      kk_function_drop(action_0, _ctx);
      return kk_std_core_types__new_Just(x_1, _ctx);
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

kk_std_core_types__list kk_std_num_int64__trmc_list64(int64_t lo_0, int64_t hi_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int64, hi : int64, ctx<list<int64>>) -> list<int64> */ 
  kk__tailcall: ;
  bool _match_x232 = (lo_0 <= hi_0); /*bool*/;
  if (_match_x232) {
    kk_std_core_types__list _trmc_x10176 = kk_datatype_null(); /*list<int64>*/;
    kk_std_core_types__list _trmc_x10177 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_int64_box(lo_0, _ctx), _trmc_x10176, _ctx); /*list<int64>*/;
    kk_field_addr_t _b_x112_117 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10177, _ctx)->tail, _ctx); /*@field-addr<list<int64>>*/;
    { // tailcall
      int64_t _x_x420;
      int64_t _x_x421 = (KK_I64(1)); /*int64*/
      _x_x420 = (int64_t)((uint64_t)lo_0 + (uint64_t)_x_x421); /*int64*/
      kk_std_core_types__cctx _x_x422 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10177, _ctx)),_b_x112_117,kk_context()); /*ctx<0>*/
      lo_0 = _x_x420;
      _acc = _x_x422;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x423 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x423, KK_OWNED, _ctx);
  }
}

kk_std_core_types__list kk_std_num_int64_list64(int64_t lo_0_0, int64_t hi_0_0, kk_context_t* _ctx) { /* (lo : int64, hi : int64) -> list<int64> */ 
  kk_std_core_types__cctx _x_x424 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_num_int64__trmc_list64(lo_0_0, hi_0_0, _x_x424, _ctx);
}

int64_t kk_std_num_int64__unroll_sumacc64_10000(kk_std_core_types__list xs, int64_t acc, kk_context_t* _ctx) { /* (xs : list<int64>, acc : int64) -> int64 */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x425 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x123 = _con_x425->head;
    kk_std_core_types__list xx = _con_x425->tail;
    int64_t x = kk_int64_unbox(_box_x123, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_box_x123, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      int64_t _x_x426 = (int64_t)((uint64_t)acc + (uint64_t)x); /*int64*/
      xs = xx;
      acc = _x_x426;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// carry-less multiply by -1 gives the _prefix sum_

kk_string_t kk_std_num_int64_test_prefix_sum(kk_context_t* _ctx) { /* () -> string */ 
  int64_t x = (KK_I64(1295)); /*int64*/;
  int64_t i_10036;
  int64_t _x_x427 = (KK_I64(-1)); /*int64*/
  i_10036 = (int64_t)kk_clmul64((uint64_t)x,(uint64_t)_x_x427); /*int64*/
  kk_integer_t _x_x428 = kk_integer_from_int64(i_10036,kk_context()); /*int*/
  kk_std_core_types__optional _x_x429;
  kk_box_t _x_x430;
  kk_integer_t _x_x431;
  kk_std_core_types__optional _match_x231 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x231, _ctx)) {
    kk_box_t _box_x124 = _match_x231._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x124, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(_match_x231, _ctx);
    _x_x431 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x231, _ctx);
    _x_x431 = kk_integer_from_small(1); /*int*/
  }
  _x_x430 = kk_integer_box(_x_x431, _ctx); /*7*/
  _x_x429 = kk_std_core_types__new_Optional(_x_x430, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x432;
  kk_box_t _x_x433;
  bool _x_x434;
  kk_std_core_types__optional _match_x230 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x230, _ctx)) {
    kk_box_t _box_x126 = _match_x230._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x126);
    kk_std_core_types__optional_drop(_match_x230, _ctx);
    _x_x434 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x230, _ctx);
    _x_x434 = true; /*bool*/
  }
  _x_x433 = kk_bool_box(_x_x434); /*7*/
  _x_x432 = kk_std_core_types__new_Optional(_x_x433, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x435;
  kk_box_t _x_x436;
  kk_string_t _x_x437;
  kk_std_core_types__optional _match_x229 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x229, _ctx)) {
    kk_box_t _box_x128 = _match_x229._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x128);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(_match_x229, _ctx);
    _x_x437 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x229, _ctx);
    kk_define_string_literal(, _s_x438, 2, "0x", _ctx)
    _x_x437 = kk_string_dup(_s_x438, _ctx); /*string*/
  }
  _x_x436 = kk_string_box(_x_x437); /*7*/
  _x_x435 = kk_std_core_types__new_Optional(_x_x436, _ctx); /*? 7*/
  return kk_std_core_show_show_hex(_x_x428, _x_x429, _x_x432, _x_x435, _ctx);
}
 
// carry-less multiply of x by x spreads the bits

kk_string_t kk_std_num_int64_test_bit_spread1(kk_context_t* _ctx) { /* () -> string */ 
  int64_t x = (KK_I64(1535)); /*int64*/;
  int64_t i_10040 = (int64_t)kk_clmul64((uint64_t)x,(uint64_t)x); /*int64*/;
  kk_integer_t _x_x439 = kk_integer_from_int64(i_10040,kk_context()); /*int*/
  kk_std_core_types__optional _x_x440;
  kk_box_t _x_x441;
  kk_integer_t _x_x442;
  kk_std_core_types__optional _match_x228 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x228, _ctx)) {
    kk_box_t _box_x133 = _match_x228._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x133, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(_match_x228, _ctx);
    _x_x442 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x228, _ctx);
    _x_x442 = kk_integer_from_small(1); /*int*/
  }
  _x_x441 = kk_integer_box(_x_x442, _ctx); /*7*/
  _x_x440 = kk_std_core_types__new_Optional(_x_x441, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x443;
  kk_box_t _x_x444;
  bool _x_x445;
  kk_std_core_types__optional _match_x227 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x227, _ctx)) {
    kk_box_t _box_x135 = _match_x227._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x135);
    kk_std_core_types__optional_drop(_match_x227, _ctx);
    _x_x445 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x227, _ctx);
    _x_x445 = true; /*bool*/
  }
  _x_x444 = kk_bool_box(_x_x445); /*7*/
  _x_x443 = kk_std_core_types__new_Optional(_x_x444, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x446;
  kk_box_t _x_x447;
  kk_string_t _x_x448;
  kk_std_core_types__optional _match_x226 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x226, _ctx)) {
    kk_box_t _box_x137 = _match_x226._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x137);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(_match_x226, _ctx);
    _x_x448 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x226, _ctx);
    kk_define_string_literal(, _s_x449, 2, "0x", _ctx)
    _x_x448 = kk_string_dup(_s_x449, _ctx); /*string*/
  }
  _x_x447 = kk_string_box(_x_x448); /*7*/
  _x_x446 = kk_std_core_types__new_Optional(_x_x447, _ctx); /*? 7*/
  return kk_std_core_show_show_hex(_x_x439, _x_x440, _x_x443, _x_x446, _ctx);
}

kk_string_t kk_std_num_int64_test_bit_spread2(kk_context_t* _ctx) { /* () -> string */ 
  int64_t x = (KK_I64(1531)); /*int64*/;
  int64_t i_10044 = (int64_t)kk_clmul64((uint64_t)x,(uint64_t)x); /*int64*/;
  kk_integer_t _x_x450 = kk_integer_from_int64(i_10044,kk_context()); /*int*/
  kk_std_core_types__optional _x_x451;
  kk_box_t _x_x452;
  kk_integer_t _x_x453;
  kk_std_core_types__optional _match_x225 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x225, _ctx)) {
    kk_box_t _box_x142 = _match_x225._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x142, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(_match_x225, _ctx);
    _x_x453 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x225, _ctx);
    _x_x453 = kk_integer_from_small(1); /*int*/
  }
  _x_x452 = kk_integer_box(_x_x453, _ctx); /*7*/
  _x_x451 = kk_std_core_types__new_Optional(_x_x452, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x454;
  kk_box_t _x_x455;
  bool _x_x456;
  kk_std_core_types__optional _match_x224 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x224, _ctx)) {
    kk_box_t _box_x144 = _match_x224._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x144);
    kk_std_core_types__optional_drop(_match_x224, _ctx);
    _x_x456 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x224, _ctx);
    _x_x456 = true; /*bool*/
  }
  _x_x455 = kk_bool_box(_x_x456); /*7*/
  _x_x454 = kk_std_core_types__new_Optional(_x_x455, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x457;
  kk_box_t _x_x458;
  kk_string_t _x_x459;
  kk_std_core_types__optional _match_x223 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x223, _ctx)) {
    kk_box_t _box_x146 = _match_x223._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x146);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(_match_x223, _ctx);
    _x_x459 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x223, _ctx);
    kk_define_string_literal(, _s_x460, 2, "0x", _ctx)
    _x_x459 = kk_string_dup(_s_x460, _ctx); /*string*/
  }
  _x_x458 = kk_string_box(_x_x459); /*7*/
  _x_x457 = kk_std_core_types__new_Optional(_x_x458, _ctx); /*? 7*/
  return kk_std_core_show_show_hex(_x_x450, _x_x451, _x_x454, _x_x457, _ctx);
}

kk_string_t kk_std_num_int64_test_clmulr1(kk_context_t* _ctx) { /* () -> string */ 
  int64_t x = (KK_I64(51)); /*int64*/;
  int64_t i_10048 = kk_bits_zip64(x); /*int64*/;
  int64_t i_0_10052;
  int64_t _x_x463 = (int64_t)kk_clmul64((uint64_t)x,(uint64_t)x); /*int64*/
  int64_t _x_x464 = (int64_t)kk_clmulr64((uint64_t)x,(uint64_t)x); /*int64*/
  i_0_10052 = _x_x463 | _x_x464; /*int64*/
  kk_integer_t _b_x152_163;
  kk_std_core_types__optional _match_x222 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x222, _ctx)) {
    kk_box_t _box_x151 = _match_x222._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x151, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(_match_x222, _ctx);
    _b_x152_163 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x222, _ctx);
    _b_x152_163 = kk_integer_from_small(1); /*int*/
  }
  bool _b_x154_164;
  kk_std_core_types__optional _match_x221 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x221, _ctx)) {
    kk_box_t _box_x153 = _match_x221._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x153);
    kk_std_core_types__optional_drop(_match_x221, _ctx);
    _b_x154_164 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x221, _ctx);
    _b_x154_164 = true; /*bool*/
  }
  kk_string_t _b_x156_165;
  kk_std_core_types__optional _match_x220 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x220, _ctx)) {
    kk_box_t _box_x155 = _match_x220._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x155);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(_match_x220, _ctx);
    _b_x156_165 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x220, _ctx);
    kk_define_string_literal(, _s_x465, 2, "0x", _ctx)
    _b_x156_165 = kk_string_dup(_s_x465, _ctx); /*string*/
  }
  kk_string_t _x_x466;
  kk_integer_t _x_x467 = kk_integer_from_int64(i_10048,kk_context()); /*int*/
  kk_std_core_types__optional _x_x468 = kk_std_core_types__new_Optional(kk_integer_box(_b_x152_163, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x469 = kk_std_core_types__new_Optional(kk_bool_box(_b_x154_164), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x470 = kk_std_core_types__new_Optional(kk_string_box(_b_x156_165), _ctx); /*? 7*/
  _x_x466 = kk_std_core_show_show_hex(_x_x467, _x_x468, _x_x469, _x_x470, _ctx); /*string*/
  kk_string_t _x_x471;
  kk_integer_t _b_x158_166;
  kk_std_core_types__optional _match_x219 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x219, _ctx)) {
    kk_box_t _box_x157 = _match_x219._cons._Optional.value;
    kk_integer_t _uniq_width_578_0 = kk_integer_unbox(_box_x157, _ctx);
    kk_integer_dup(_uniq_width_578_0, _ctx);
    kk_std_core_types__optional_drop(_match_x219, _ctx);
    _b_x158_166 = _uniq_width_578_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x219, _ctx);
    _b_x158_166 = kk_integer_from_small(1); /*int*/
  }
  bool _b_x160_167;
  kk_std_core_types__optional _match_x218 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x218, _ctx)) {
    kk_box_t _box_x159 = _match_x218._cons._Optional.value;
    bool _uniq_use_capitals_582_0 = kk_bool_unbox(_box_x159);
    kk_std_core_types__optional_drop(_match_x218, _ctx);
    _b_x160_167 = _uniq_use_capitals_582_0; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x218, _ctx);
    _b_x160_167 = true; /*bool*/
  }
  kk_string_t _b_x162_168;
  kk_std_core_types__optional _match_x217 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x217, _ctx)) {
    kk_box_t _box_x161 = _match_x217._cons._Optional.value;
    kk_string_t _uniq_pre_586_0 = kk_string_unbox(_box_x161);
    kk_string_dup(_uniq_pre_586_0, _ctx);
    kk_std_core_types__optional_drop(_match_x217, _ctx);
    _b_x162_168 = _uniq_pre_586_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x217, _ctx);
    kk_define_string_literal(, _s_x472, 2, "0x", _ctx)
    _b_x162_168 = kk_string_dup(_s_x472, _ctx); /*string*/
  }
  kk_string_t _x_x473;
  kk_define_string_literal(, _s_x474, 4, " == ", _ctx)
  _x_x473 = kk_string_dup(_s_x474, _ctx); /*string*/
  kk_string_t _x_x475;
  kk_integer_t _x_x476 = kk_integer_from_int64(i_0_10052,kk_context()); /*int*/
  kk_std_core_types__optional _x_x477 = kk_std_core_types__new_Optional(kk_integer_box(_b_x158_166, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x478 = kk_std_core_types__new_Optional(kk_bool_box(_b_x160_167), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x479 = kk_std_core_types__new_Optional(kk_string_box(_b_x162_168), _ctx); /*? 7*/
  _x_x475 = kk_std_core_show_show_hex(_x_x476, _x_x477, _x_x478, _x_x479, _ctx); /*string*/
  _x_x471 = kk_std_core_types__lp__plus__plus__rp_(_x_x473, _x_x475, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x466, _x_x471, _ctx);
}

kk_string_t kk_std_num_int64_test_clmulr2(kk_context_t* _ctx) { /* () -> string */ 
  int64_t x = (KK_I64(81986702028889840)); /*int64*/;
  int64_t i_10057 = kk_bits_zip64(x); /*int64*/;
  int64_t i_0_10061;
  int64_t _x_x480 = (int64_t)kk_clmul64((uint64_t)x,(uint64_t)x); /*int64*/
  int64_t _x_x481 = (int64_t)kk_clmulr64((uint64_t)x,(uint64_t)x); /*int64*/
  i_0_10061 = _x_x480 | _x_x481; /*int64*/
  kk_integer_t _b_x170_181;
  kk_std_core_types__optional _match_x216 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x216, _ctx)) {
    kk_box_t _box_x169 = _match_x216._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x169, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(_match_x216, _ctx);
    _b_x170_181 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x216, _ctx);
    _b_x170_181 = kk_integer_from_small(1); /*int*/
  }
  bool _b_x172_182;
  kk_std_core_types__optional _match_x215 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x215, _ctx)) {
    kk_box_t _box_x171 = _match_x215._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x171);
    kk_std_core_types__optional_drop(_match_x215, _ctx);
    _b_x172_182 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x215, _ctx);
    _b_x172_182 = true; /*bool*/
  }
  kk_string_t _b_x174_183;
  kk_std_core_types__optional _match_x214 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x214, _ctx)) {
    kk_box_t _box_x173 = _match_x214._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x173);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(_match_x214, _ctx);
    _b_x174_183 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x214, _ctx);
    kk_define_string_literal(, _s_x482, 2, "0x", _ctx)
    _b_x174_183 = kk_string_dup(_s_x482, _ctx); /*string*/
  }
  kk_string_t _x_x483;
  kk_integer_t _x_x484 = kk_integer_from_int64(i_10057,kk_context()); /*int*/
  kk_std_core_types__optional _x_x485 = kk_std_core_types__new_Optional(kk_integer_box(_b_x170_181, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x486 = kk_std_core_types__new_Optional(kk_bool_box(_b_x172_182), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x487 = kk_std_core_types__new_Optional(kk_string_box(_b_x174_183), _ctx); /*? 7*/
  _x_x483 = kk_std_core_show_show_hex(_x_x484, _x_x485, _x_x486, _x_x487, _ctx); /*string*/
  kk_string_t _x_x488;
  kk_integer_t _b_x176_184;
  kk_std_core_types__optional _match_x213 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x213, _ctx)) {
    kk_box_t _box_x175 = _match_x213._cons._Optional.value;
    kk_integer_t _uniq_width_578_0 = kk_integer_unbox(_box_x175, _ctx);
    kk_integer_dup(_uniq_width_578_0, _ctx);
    kk_std_core_types__optional_drop(_match_x213, _ctx);
    _b_x176_184 = _uniq_width_578_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x213, _ctx);
    _b_x176_184 = kk_integer_from_small(1); /*int*/
  }
  bool _b_x178_185;
  kk_std_core_types__optional _match_x212 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x212, _ctx)) {
    kk_box_t _box_x177 = _match_x212._cons._Optional.value;
    bool _uniq_use_capitals_582_0 = kk_bool_unbox(_box_x177);
    kk_std_core_types__optional_drop(_match_x212, _ctx);
    _b_x178_185 = _uniq_use_capitals_582_0; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x212, _ctx);
    _b_x178_185 = true; /*bool*/
  }
  kk_string_t _b_x180_186;
  kk_std_core_types__optional _match_x211 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x211, _ctx)) {
    kk_box_t _box_x179 = _match_x211._cons._Optional.value;
    kk_string_t _uniq_pre_586_0 = kk_string_unbox(_box_x179);
    kk_string_dup(_uniq_pre_586_0, _ctx);
    kk_std_core_types__optional_drop(_match_x211, _ctx);
    _b_x180_186 = _uniq_pre_586_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x211, _ctx);
    kk_define_string_literal(, _s_x489, 2, "0x", _ctx)
    _b_x180_186 = kk_string_dup(_s_x489, _ctx); /*string*/
  }
  kk_string_t _x_x490;
  kk_define_string_literal(, _s_x491, 4, " == ", _ctx)
  _x_x490 = kk_string_dup(_s_x491, _ctx); /*string*/
  kk_string_t _x_x492;
  kk_integer_t _x_x493 = kk_integer_from_int64(i_0_10061,kk_context()); /*int*/
  kk_std_core_types__optional _x_x494 = kk_std_core_types__new_Optional(kk_integer_box(_b_x176_184, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x495 = kk_std_core_types__new_Optional(kk_bool_box(_b_x178_185), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x496 = kk_std_core_types__new_Optional(kk_string_box(_b_x180_186), _ctx); /*? 7*/
  _x_x492 = kk_std_core_show_show_hex(_x_x493, _x_x494, _x_x495, _x_x496, _ctx); /*string*/
  _x_x488 = kk_std_core_types__lp__plus__plus__rp_(_x_x490, _x_x492, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x483, _x_x488, _ctx);
}

kk_string_t kk_std_num_int64_test_clmulrev1(kk_context_t* _ctx) { /* () -> string */ 
  int64_t x = (KK_I64(305419896)); /*int64*/;
  int64_t y;
  int64_t _x_x500 = (KK_I64(2309737967)); /*int64*/
  y = kk_bits_bswap64(_x_x500); /*int64*/
  int64_t i_10066 = (int64_t)kk_clmulr64((uint64_t)x,(uint64_t)y); /*int64*/;
  int64_t i_0_10070;
  int64_t _x_x501;
  int64_t _x_x502 = kk_bits_reverse64(x); /*int64*/
  int64_t _x_x503 = kk_bits_reverse64(y); /*int64*/
  _x_x501 = (int64_t)kk_clmul64((uint64_t)_x_x502,(uint64_t)_x_x503); /*int64*/
  i_0_10070 = kk_bits_reverse64(_x_x501); /*int64*/
  kk_integer_t _b_x188_199;
  kk_std_core_types__optional _match_x210 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x210, _ctx)) {
    kk_box_t _box_x187 = _match_x210._cons._Optional.value;
    kk_integer_t _uniq_width_578 = kk_integer_unbox(_box_x187, _ctx);
    kk_integer_dup(_uniq_width_578, _ctx);
    kk_std_core_types__optional_drop(_match_x210, _ctx);
    _b_x188_199 = _uniq_width_578; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x210, _ctx);
    _b_x188_199 = kk_integer_from_small(1); /*int*/
  }
  bool _b_x190_200;
  kk_std_core_types__optional _match_x209 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x209, _ctx)) {
    kk_box_t _box_x189 = _match_x209._cons._Optional.value;
    bool _uniq_use_capitals_582 = kk_bool_unbox(_box_x189);
    kk_std_core_types__optional_drop(_match_x209, _ctx);
    _b_x190_200 = _uniq_use_capitals_582; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x209, _ctx);
    _b_x190_200 = true; /*bool*/
  }
  kk_string_t _b_x192_201;
  kk_std_core_types__optional _match_x208 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x208, _ctx)) {
    kk_box_t _box_x191 = _match_x208._cons._Optional.value;
    kk_string_t _uniq_pre_586 = kk_string_unbox(_box_x191);
    kk_string_dup(_uniq_pre_586, _ctx);
    kk_std_core_types__optional_drop(_match_x208, _ctx);
    _b_x192_201 = _uniq_pre_586; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x208, _ctx);
    kk_define_string_literal(, _s_x504, 2, "0x", _ctx)
    _b_x192_201 = kk_string_dup(_s_x504, _ctx); /*string*/
  }
  kk_string_t _x_x505;
  kk_integer_t _x_x506 = kk_integer_from_int64(i_10066,kk_context()); /*int*/
  kk_std_core_types__optional _x_x507 = kk_std_core_types__new_Optional(kk_integer_box(_b_x188_199, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x508 = kk_std_core_types__new_Optional(kk_bool_box(_b_x190_200), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x509 = kk_std_core_types__new_Optional(kk_string_box(_b_x192_201), _ctx); /*? 7*/
  _x_x505 = kk_std_core_show_show_hex(_x_x506, _x_x507, _x_x508, _x_x509, _ctx); /*string*/
  kk_string_t _x_x510;
  kk_integer_t _b_x194_202;
  kk_std_core_types__optional _match_x207 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x207, _ctx)) {
    kk_box_t _box_x193 = _match_x207._cons._Optional.value;
    kk_integer_t _uniq_width_578_0 = kk_integer_unbox(_box_x193, _ctx);
    kk_integer_dup(_uniq_width_578_0, _ctx);
    kk_std_core_types__optional_drop(_match_x207, _ctx);
    _b_x194_202 = _uniq_width_578_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x207, _ctx);
    _b_x194_202 = kk_integer_from_small(1); /*int*/
  }
  bool _b_x196_203;
  kk_std_core_types__optional _match_x206 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x206, _ctx)) {
    kk_box_t _box_x195 = _match_x206._cons._Optional.value;
    bool _uniq_use_capitals_582_0 = kk_bool_unbox(_box_x195);
    kk_std_core_types__optional_drop(_match_x206, _ctx);
    _b_x196_203 = _uniq_use_capitals_582_0; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x206, _ctx);
    _b_x196_203 = true; /*bool*/
  }
  kk_string_t _b_x198_204;
  kk_std_core_types__optional _match_x205 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x205, _ctx)) {
    kk_box_t _box_x197 = _match_x205._cons._Optional.value;
    kk_string_t _uniq_pre_586_0 = kk_string_unbox(_box_x197);
    kk_string_dup(_uniq_pre_586_0, _ctx);
    kk_std_core_types__optional_drop(_match_x205, _ctx);
    _b_x198_204 = _uniq_pre_586_0; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x205, _ctx);
    kk_define_string_literal(, _s_x511, 2, "0x", _ctx)
    _b_x198_204 = kk_string_dup(_s_x511, _ctx); /*string*/
  }
  kk_string_t _x_x512;
  kk_define_string_literal(, _s_x513, 4, " == ", _ctx)
  _x_x512 = kk_string_dup(_s_x513, _ctx); /*string*/
  kk_string_t _x_x514;
  kk_integer_t _x_x515 = kk_integer_from_int64(i_0_10070,kk_context()); /*int*/
  kk_std_core_types__optional _x_x516 = kk_std_core_types__new_Optional(kk_integer_box(_b_x194_202, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x517 = kk_std_core_types__new_Optional(kk_bool_box(_b_x196_203), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x518 = kk_std_core_types__new_Optional(kk_string_box(_b_x198_204), _ctx); /*? 7*/
  _x_x514 = kk_std_core_show_show_hex(_x_x515, _x_x516, _x_x517, _x_x518, _ctx); /*string*/
  _x_x510 = kk_std_core_types__lp__plus__plus__rp_(_x_x512, _x_x514, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x505, _x_x510, _ctx);
}

// initialization
void kk_std_num_int64__init(kk_context_t* _ctx){
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
  kk_std_core_undiv__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_num_int64_one = (KK_I64(1)); /*int64*/
  }
  {
    kk_std_num_int64_zero = (KK_I64(0)); /*int64*/
  }
  {
    kk_std_num_int64_max_int64 = (KK_I64(9223372036854775807)); /*int64*/
  }
  {
    kk_std_num_int64_min_int64 = (INT64_MIN); /*int64*/
  }
  {
    kk_std_num_int64_bits_int64 = (KK_I64(64)); /*int64*/
  }
}

// termination
void kk_std_num_int64__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_skip_drop(kk_std_num_int64_bits_int64, _ctx);
  kk_skip_drop(kk_std_num_int64_min_int64, _ctx);
  kk_skip_drop(kk_std_num_int64_max_int64, _ctx);
  kk_skip_drop(kk_std_num_int64_zero, _ctx);
  kk_skip_drop(kk_std_num_int64_one, _ctx);
  kk_std_core_undiv__done(_ctx);
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
