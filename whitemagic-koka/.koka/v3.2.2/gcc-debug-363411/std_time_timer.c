// Koka generated module: std/time/timer, koka version: 3.2.2, platform: 64-bit
#include "std_time_timer.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_types__tuple2 kk_timer_ticks_tuple(kk_context_t* ctx) {
  kk_duration_t d = kk_timer_ticks(ctx);
  // the conversion has about 15 digits of precision
  // we cannot do this more precisely as the api expects the fraction between 0.0 and 2.0 (for leap seconds).
  double secs = (double)d.seconds;
  double frac = (double)d.attoseconds * 1e-18;
  return kk_std_core_types__new_Tuple2( kk_double_box(secs,ctx), kk_double_box(frac,ctx), ctx );
}

static double kk_timer_dresolution(kk_context_t* ctx) {
  int64_t asecs = kk_timer_resolution(ctx);
  return (double)asecs * 1e-18;
}


kk_std_core_types__tuple2 kk_std_time_timer_xticks(kk_context_t* _ctx) { /* () -> ndet (float64, float64) */ 
  return kk_timer_ticks_tuple(kk_context());
}
 
// Return the smallest time difference in seconds that `ticks` can measure.

double kk_std_time_timer_xticks_resolution(kk_context_t* _ctx) { /* () -> ndet float64 */ 
  return kk_timer_dresolution(kk_context());
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_time_timer__mlift_elapsed_10004(kk_std_time_duration__duration t0, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (t0 : std/time/duration/duration, x : a) -> <ndet|e> (std/time/duration/duration, a) */ 
  kk_std_time_duration__duration t1;
  kk_std_core_types__tuple2 _match_x43 = kk_std_time_timer_xticks(_ctx); /*(float64, float64)*/;
  {
    kk_box_t _box_x2 = _match_x43.fst;
    kk_box_t _box_x3 = _match_x43.snd;
    double secs_0 = kk_double_unbox(_box_x2, KK_BORROWED, _ctx);
    double frac_0 = kk_double_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x43, _ctx);
    t1 = kk_std_time_duration_float64frac_fs_duration(secs_0, frac_0, _ctx); /*std/time/duration/duration*/
  }
  kk_std_time_duration__duration _b_x4_6 = kk_std_time_duration__lp__dash__rp_(t1, t0, _ctx); /*std/time/duration/duration*/;
  return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(_b_x4_6, _ctx), x, _ctx);
}
 
// Return the number of fractional seconds that it takes to evaluate `action`.


// lift anonymous function
struct kk_std_time_timer_elapsed_fun47__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration t0;
};
static kk_box_t kk_std_time_timer_elapsed_fun47(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_std_time_timer_new_elapsed_fun47(kk_std_time_duration__duration t0, kk_context_t* _ctx) {
  struct kk_std_time_timer_elapsed_fun47__t* _self = kk_function_alloc_as(struct kk_std_time_timer_elapsed_fun47__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_timer_elapsed_fun47, kk_context());
  _self->t0 = t0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_timer_elapsed_fun47(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx) {
  struct kk_std_time_timer_elapsed_fun47__t* _self = kk_function_as(struct kk_std_time_timer_elapsed_fun47__t*, _fself, _ctx);
  kk_std_time_duration__duration t0 = _self->t0; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(t0, _ctx);}, {}, _ctx)
  kk_box_t x_0_25 = _b_x15; /*126*/;
  kk_std_time_duration__duration t1;
  kk_std_core_types__tuple2 _match_x41 = kk_std_time_timer_xticks(_ctx); /*(float64, float64)*/;
  {
    kk_box_t _box_x10 = _match_x41.fst;
    kk_box_t _box_x11 = _match_x41.snd;
    double secs_0 = kk_double_unbox(_box_x10, KK_BORROWED, _ctx);
    double frac_0 = kk_double_unbox(_box_x11, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x41, _ctx);
    t1 = kk_std_time_duration_float64frac_fs_duration(secs_0, frac_0, _ctx); /*std/time/duration/duration*/
  }
  kk_std_time_duration__duration _b_x12_21 = kk_std_time_duration__lp__dash__rp_(t1, t0, _ctx); /*std/time/duration/duration*/;
  kk_std_core_types__tuple2 _x_x48 = kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(_b_x12_21, _ctx), x_0_25, _ctx); /*(134, 135)*/
  return kk_std_core_types__tuple2_box(_x_x48, _ctx);
}

kk_std_core_types__tuple2 kk_std_time_timer_elapsed(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <ndet|e> a) -> <ndet|e> (std/time/duration/duration, a) */ 
  kk_std_time_duration__duration t0;
  kk_std_core_types__tuple2 _match_x42 = kk_std_time_timer_xticks(_ctx); /*(float64, float64)*/;
  {
    kk_box_t _box_x8 = _match_x42.fst;
    kk_box_t _box_x9 = _match_x42.snd;
    double secs = kk_double_unbox(_box_x8, KK_BORROWED, _ctx);
    double frac = kk_double_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__tuple2_drop(_match_x42, _ctx);
    t0 = kk_std_time_duration_float64frac_fs_duration(secs, frac, _ctx); /*std/time/duration/duration*/
  }
  kk_box_t x_10006 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*126*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10006, _ctx);
    kk_box_t _x_x46 = kk_std_core_hnd_yield_extend(kk_std_time_timer_new_elapsed_fun47(t0, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x46, KK_OWNED, _ctx);
  }
  {
    kk_std_time_duration__duration t1_0;
    kk_std_core_types__tuple2 _match_x40 = kk_std_time_timer_xticks(_ctx); /*(float64, float64)*/;
    {
      kk_box_t _box_x16 = _match_x40.fst;
      kk_box_t _box_x17 = _match_x40.snd;
      double secs_0_0 = kk_double_unbox(_box_x16, KK_BORROWED, _ctx);
      double frac_0_0 = kk_double_unbox(_box_x17, KK_BORROWED, _ctx);
      kk_std_core_types__tuple2_drop(_match_x40, _ctx);
      t1_0 = kk_std_time_duration_float64frac_fs_duration(secs_0_0, frac_0_0, _ctx); /*std/time/duration/duration*/
    }
    kk_std_time_duration__duration _b_x18_23 = kk_std_time_duration__lp__dash__rp_(t1_0, t0, _ctx); /*std/time/duration/duration*/;
    return kk_std_core_types__new_Tuple2(kk_std_time_duration__duration_box(_b_x18_23, _ctx), x_10006, _ctx);
  }
}
 
// monadic lift

kk_box_t kk_std_time_timer__mlift_print_elapsed_10005(kk_std_core_types__optional msg, kk_std_core_types__tuple2 _y_x10002, kk_context_t* _ctx) { /* forall<a,e> (msg : ? string, (std/time/duration/duration, a)) -> <ndet,console/console|e> a */ 
  {
    kk_box_t _box_x26 = _y_x10002.fst;
    kk_std_time_duration__duration t = kk_std_time_duration__duration_unbox(_box_x26, KK_BORROWED, _ctx);
    kk_box_t x = _y_x10002.snd;
    kk_box_dup(x, _ctx);
    kk_std_core_types__tuple2_drop(_y_x10002, _ctx);
    kk_unit_t __ = kk_Unit;
    kk_string_t _x_x49;
    kk_string_t _x_x50;
    if (kk_std_core_types__is_Optional(msg, _ctx)) {
      kk_box_t _box_x27 = msg._cons._Optional.value;
      kk_string_t _uniq_msg_139 = kk_string_unbox(_box_x27);
      kk_string_dup(_uniq_msg_139, _ctx);
      kk_std_core_types__optional_drop(msg, _ctx);
      _x_x50 = _uniq_msg_139; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(msg, _ctx);
      kk_define_string_literal(, _s_x51, 7, "elapsed", _ctx)
      _x_x50 = kk_string_dup(_s_x51, _ctx); /*string*/
    }
    kk_string_t _x_x52;
    kk_string_t _x_x53;
    kk_define_string_literal(, _s_x54, 1, " ", _ctx)
    _x_x53 = kk_string_dup(_s_x54, _ctx); /*string*/
    kk_string_t _x_x55;
    kk_std_core_types__optional _x_x56 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
    _x_x55 = kk_std_time_duration_show(t, _x_x56, _ctx); /*string*/
    _x_x52 = kk_std_core_types__lp__plus__plus__rp_(_x_x53, _x_x55, _ctx); /*string*/
    _x_x49 = kk_std_core_types__lp__plus__plus__rp_(_x_x50, _x_x52, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x49, _ctx);
    return x;
  }
}
 
// Measure the number of fractional seconds that it takes to evaluate `action`, and print `msg` postfixed with the
// measured time in millisecond resolution.


// lift anonymous function
struct kk_std_time_timer_print_elapsed_fun57__t {
  struct kk_function_s _base;
  kk_std_core_types__optional msg;
};
static kk_box_t kk_std_time_timer_print_elapsed_fun57(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx);
static kk_function_t kk_std_time_timer_new_print_elapsed_fun57(kk_std_core_types__optional msg, kk_context_t* _ctx) {
  struct kk_std_time_timer_print_elapsed_fun57__t* _self = kk_function_alloc_as(struct kk_std_time_timer_print_elapsed_fun57__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_timer_print_elapsed_fun57, kk_context());
  _self->msg = msg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_timer_print_elapsed_fun57(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx) {
  struct kk_std_time_timer_print_elapsed_fun57__t* _self = kk_function_as(struct kk_std_time_timer_print_elapsed_fun57__t*, _fself, _ctx);
  kk_std_core_types__optional msg = _self->msg; /* ? string */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(msg, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _x_x58 = kk_std_core_types__tuple2_unbox(_b_x31, KK_OWNED, _ctx); /*(std/time/duration/duration, 301)*/
  return kk_std_time_timer__mlift_print_elapsed_10005(msg, _x_x58, _ctx);
}

kk_box_t kk_std_time_timer_print_elapsed(kk_function_t action, kk_std_core_types__optional msg, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <ndet,console/console|e> a, msg : ? string) -> <ndet,console/console|e> a */ 
  kk_std_core_types__tuple2 x_10011 = kk_std_time_timer_elapsed(action, _ctx); /*(std/time/duration/duration, 301)*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2_drop(x_10011, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_time_timer_new_print_elapsed_fun57(msg, _ctx), _ctx);
  }
  {
    kk_box_t _box_x32 = x_10011.fst;
    kk_std_time_duration__duration t = kk_std_time_duration__duration_unbox(_box_x32, KK_BORROWED, _ctx);
    kk_box_t x_0 = x_10011.snd;
    kk_box_dup(x_0, _ctx);
    kk_std_core_types__tuple2_drop(x_10011, _ctx);
    kk_unit_t __ = kk_Unit;
    kk_string_t _x_x59;
    kk_string_t _x_x60;
    if (kk_std_core_types__is_Optional(msg, _ctx)) {
      kk_box_t _box_x33 = msg._cons._Optional.value;
      kk_string_t _uniq_msg_139 = kk_string_unbox(_box_x33);
      kk_string_dup(_uniq_msg_139, _ctx);
      kk_std_core_types__optional_drop(msg, _ctx);
      _x_x60 = _uniq_msg_139; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(msg, _ctx);
      kk_define_string_literal(, _s_x61, 7, "elapsed", _ctx)
      _x_x60 = kk_string_dup(_s_x61, _ctx); /*string*/
    }
    kk_string_t _x_x62;
    kk_string_t _x_x63;
    kk_define_string_literal(, _s_x64, 1, " ", _ctx)
    _x_x63 = kk_string_dup(_s_x64, _ctx); /*string*/
    kk_string_t _x_x65;
    kk_std_core_types__optional _x_x66 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
    _x_x65 = kk_std_time_duration_show(t, _x_x66, _ctx); /*string*/
    _x_x62 = kk_std_core_types__lp__plus__plus__rp_(_x_x63, _x_x65, _ctx); /*string*/
    _x_x59 = kk_std_core_types__lp__plus__plus__rp_(_x_x60, _x_x62, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x59, _ctx);
    return x_0;
  }
}

// initialization
void kk_std_time_timer__init(kk_context_t* _ctx){
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
  kk_std_num_float64__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_time_timer__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_num_float64__done(_ctx);
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
