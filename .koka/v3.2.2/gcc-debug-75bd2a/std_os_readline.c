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
  kk_string_t _x_x16;
  kk_string_t _x_x17;
  kk_string_t _x_x18;
  kk_define_string_literal(, _s_x19, 2, ": ", _ctx)
  _x_x18 = kk_string_dup(_s_x19, _ctx); /*string*/
  kk_string_t _x_x20;
  {
    kk_string_t _x = exn.message;
    kk_string_dup(_x, _ctx);
    _x_x20 = _x; /*string*/
  }
  _x_x17 = kk_std_core_types__lp__plus__plus__rp_(_x_x18, _x_x20, _ctx); /*string*/
  _x_x16 = kk_std_core_types__lp__plus__plus__rp_(pre, _x_x17, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x21;
  {
    kk_std_core_exn__exception_info _x_0 = exn.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(exn, _ctx);
    _x_x21 = _x_0; /*exception-info*/
  }
  return kk_std_core_exn__new_Exception(_x_x16, _x_x21, _ctx);
}

kk_std_core_exn__error kk_std_os_readline_readline_err(kk_context_t* _ctx) { /* () -> console/console error<string> */ 
  return kk_os_read_line_error(kk_context());
}
 
// Read a line of input synchronously from stdin (using UTF8 encoding).
// Read characters until either a newline is encountered (not included in the result),
// or 1023 characters have been read.


// lift anonymous function
struct kk_std_os_readline_readline_fun23__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_readline_readline_fun23(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_readline_new_readline_fun23(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_readline_readline_fun23, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_readline_readline_fun23(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x24 = kk_std_os_readline_readline_err(_ctx); /*error<string>*/
  return kk_std_core_exn__error_box(_x_x24, _ctx);
}


// lift anonymous function
struct kk_std_os_readline_readline_fun27__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_readline_readline_fun27(kk_function_t _fself, kk_box_t _b_x4, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_os_readline_new_readline_fun27(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_readline_readline_fun27, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_readline_readline_fun27(kk_function_t _fself, kk_box_t _b_x4, kk_box_t _b_x5, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__exception _x_x28;
  kk_std_core_exn__exception exn_0_13 = kk_std_core_exn__exception_unbox(_b_x4, KK_OWNED, _ctx); /*exception*/;
  kk_string_t pre_14 = kk_string_unbox(_b_x5); /*string*/;
  kk_string_t _x_x29;
  kk_string_t _x_x30;
  kk_string_t _x_x31;
  kk_define_string_literal(, _s_x32, 2, ": ", _ctx)
  _x_x31 = kk_string_dup(_s_x32, _ctx); /*string*/
  kk_string_t _x_x33;
  {
    kk_string_t _x = exn_0_13.message;
    kk_string_dup(_x, _ctx);
    _x_x33 = _x; /*string*/
  }
  _x_x30 = kk_std_core_types__lp__plus__plus__rp_(_x_x31, _x_x33, _ctx); /*string*/
  _x_x29 = kk_std_core_types__lp__plus__plus__rp_(pre_14, _x_x30, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x34;
  {
    kk_std_core_exn__exception_info _x_0 = exn_0_13.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(exn_0_13, _ctx);
    _x_x34 = _x_0; /*exception-info*/
  }
  _x_x28 = kk_std_core_exn__new_Exception(_x_x29, _x_x34, _ctx); /*exception*/
  return kk_std_core_exn__exception_box(_x_x28, _ctx);
}

kk_string_t kk_std_os_readline_readline(kk_context_t* _ctx) { /* () -> <console/console,exn> string */ 
  kk_std_core_exn__error _match_x15;
  kk_box_t _x_x22 = kk_std_core_hnd__open_none0(kk_std_os_readline_new_readline_fun23(_ctx), _ctx); /*9836*/
  _match_x15 = kk_std_core_exn__error_unbox(_x_x22, KK_OWNED, _ctx); /*error<string>*/
  if (kk_std_core_exn__is_Error(_match_x15, _ctx)) {
    kk_std_core_exn__exception exn = _match_x15._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x15, _ctx);
    kk_std_core_exn__error _b_x6_9;
    kk_std_core_exn__exception _x_x25;
    kk_box_t _x_x26;
    kk_box_t _x_x35;
    kk_string_t _x_x36;
    kk_define_string_literal(, _s_x37, 25, "unable to read from stdin", _ctx)
    _x_x36 = kk_string_dup(_s_x37, _ctx); /*string*/
    _x_x35 = kk_string_box(_x_x36); /*9984*/
    _x_x26 = kk_std_core_hnd__open_none2(kk_std_os_readline_new_readline_fun27(_ctx), kk_std_core_exn__exception_box(exn, _ctx), _x_x35, _ctx); /*9985*/
    _x_x25 = kk_std_core_exn__exception_unbox(_x_x26, KK_OWNED, _ctx); /*exception*/
    _b_x6_9 = kk_std_core_exn__new_Error(_x_x25, _ctx); /*error<string>*/
    kk_box_t _x_x38 = kk_std_core_exn_untry(_b_x6_9, _ctx); /*804*/
    return kk_string_unbox(_x_x38);
  }
  {
    kk_box_t _box_x7 = _match_x15._cons.Ok.result;
    kk_string_t line = kk_string_unbox(_box_x7);
    kk_string_dup(line, _ctx);
    kk_std_core_exn__error_drop(_match_x15, _ctx);
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
