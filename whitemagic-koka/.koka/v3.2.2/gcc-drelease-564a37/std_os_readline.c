// Koka generated module: std/os/readline, koka version: 3.2.2, platform: 64-bit
#include "std_os_readline.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_exn__error kk_os_read_line_error( kk_context_t* ctx ) {
  kk_string_t content;
  const int err = kk_os_read_line(&content,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_string_box(content),ctx);
}



kk_std_core_exn__exception kk_std_os_readline_prepend(kk_std_core_exn__exception exn, kk_string_t pre, kk_context_t* _ctx) { /* (exn : exception, pre : string) -> exception */ 
  kk_string_t _x_x17;
  kk_string_t _x_x18;
  kk_string_t _x_x19;
  kk_define_string_literal(, _s_x20, 2, ": ", _ctx)
  _x_x19 = kk_string_dup(_s_x20, _ctx); /*string*/
  kk_string_t _x_x21;
  {
    kk_string_t _x = exn.message;
    kk_string_dup(_x, _ctx);
    _x_x21 = _x; /*string*/
  }
  _x_x18 = kk_std_core_types__lp__plus__plus__rp_(_x_x19, _x_x21, _ctx); /*string*/
  _x_x17 = kk_std_core_types__lp__plus__plus__rp_(pre, _x_x18, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x22;
  {
    kk_std_core_exn__exception_info _x_0 = exn.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(exn, _ctx);
    _x_x22 = _x_0; /*exception-info*/
  }
  return kk_std_core_exn__new_Exception(_x_x17, _x_x22, _ctx);
}

kk_std_core_exn__error kk_std_os_readline_readline_err(kk_context_t* _ctx) { /* () -> console/console error<string> */ 
  return kk_os_read_line_error(kk_context());
}
 
// Read a line of input synchronously from stdin (using UTF8 encoding).
// Read characters until either a newline is encountered (not included in the result),
// or 1023 characters have been read.


// lift anonymous function
struct kk_std_os_readline_readline_fun24__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_readline_readline_fun24(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_readline_new_readline_fun24(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_readline_readline_fun24, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_readline_readline_fun24(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x25 = kk_std_os_readline_readline_err(_ctx); /*error<string>*/
  return kk_std_core_exn__error_box(_x_x25, _ctx);
}

kk_string_t kk_std_os_readline_readline(kk_context_t* _ctx) { /* () -> <console/console,exn> string */ 
  kk_std_core_exn__error _match_x12;
  kk_box_t _x_x23 = kk_std_core_hnd__open_none0(kk_std_os_readline_new_readline_fun24(_ctx), _ctx); /*9836*/
  _match_x12 = kk_std_core_exn__error_unbox(_x_x23, KK_OWNED, _ctx); /*error<string>*/
  if (kk_std_core_exn__is_Error(_match_x12, _ctx)) {
    kk_std_core_exn__exception exn = _match_x12._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x12, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,console/console>>*/;
    kk_std_core_exn__exception x;
    kk_string_t _x_x26;
    kk_string_t _x_x27;
    kk_define_string_literal(, _s_x28, 25, "unable to read from stdin", _ctx)
    _x_x27 = kk_string_dup(_s_x28, _ctx); /*string*/
    kk_string_t _x_x29;
    kk_string_t _x_x30;
    kk_define_string_literal(, _s_x31, 2, ": ", _ctx)
    _x_x30 = kk_string_dup(_s_x31, _ctx); /*string*/
    kk_string_t _x_x32;
    {
      kk_string_t _x = exn.message;
      kk_string_dup(_x, _ctx);
      _x_x32 = _x; /*string*/
    }
    _x_x29 = kk_std_core_types__lp__plus__plus__rp_(_x_x30, _x_x32, _ctx); /*string*/
    _x_x26 = kk_std_core_types__lp__plus__plus__rp_(_x_x27, _x_x29, _ctx); /*string*/
    kk_std_core_exn__exception_info _x_x33;
    {
      kk_std_core_exn__exception_info _x_0 = exn.info;
      kk_std_core_exn__exception_info_dup(_x_0, _ctx);
      kk_std_core_exn__exception_drop(exn, _ctx);
      _x_x33 = _x_0; /*exception-info*/
    }
    x = kk_std_core_exn__new_Exception(_x_x26, _x_x33, _ctx); /*exception*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_std_core_exn__error _match_x13 = kk_std_core_exn__new_Error(x, _ctx); /*error<6>*/;
    if (kk_std_core_exn__is_Error(_match_x13, _ctx)) {
      kk_std_core_exn__exception exn_0 = _match_x13._cons.Error.exception;
      kk_std_core_exn__exception_dup(exn_0, _ctx);
      kk_std_core_exn__error_drop(_match_x13, _ctx);
      kk_std_core_hnd__ev ev_10115 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
      kk_box_t _x_x34;
      {
        struct kk_std_core_hnd_Ev* _con_x35 = kk_std_core_hnd__as_Ev(ev_10115, _ctx);
        kk_box_t _box_x1 = _con_x35->hnd;
        int32_t m = _con_x35->marker;
        kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x1, KK_BORROWED, _ctx);
        kk_std_core_exn__exn_dup(h, _ctx);
        kk_std_core_hnd__clause1 _match_x14;
        kk_std_core_hnd__clause1 _brw_x15 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
        kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
        _match_x14 = _brw_x15; /*hnd/clause1<exception,276,exn,277,278>*/
        {
          kk_function_t _fun_unbox_x5 = _match_x14.clause;
          _x_x34 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x5, (_fun_unbox_x5, m, ev_10115, kk_std_core_exn__exception_box(exn_0, _ctx), _ctx), _ctx); /*46*/
        }
      }
      return kk_string_unbox(_x_x34);
    }
    {
      kk_box_t _box_x9 = _match_x13._cons.Ok.result;
      kk_string_t x_1 = kk_string_unbox(_box_x9);
      kk_string_dup(x_1, _ctx);
      kk_std_core_exn__error_drop(_match_x13, _ctx);
      return x_1;
    }
  }
  {
    kk_box_t _box_x10 = _match_x12._cons.Ok.result;
    kk_string_t line = kk_string_unbox(_box_x10);
    kk_string_dup(line, _ctx);
    kk_std_core_exn__error_drop(_match_x12, _ctx);
    return line;
  }
}

// initialization
void kk_std_os_readline__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_os_readline__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
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
