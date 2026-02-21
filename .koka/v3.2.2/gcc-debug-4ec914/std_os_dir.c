// Koka generated module: std/os/dir, koka version: 3.2.2, platform: 64-bit
#include "std_os_dir.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_exn__error kk_os_ensure_dir_error( kk_string_t path, kk_integer_t mode, kk_context_t* ctx ) {
  int m  = kk_integer_clamp32(mode,ctx);
  const int err = kk_os_ensure_dir(path,m,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}

static kk_std_core_exn__error kk_os_copy_file_error( kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* ctx ) {
  const int err = kk_os_copy_file(from,to,preserve_mtime,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}

static kk_std_core_exn__error kk_os_list_directory_prim( kk_string_t dir, kk_context_t* ctx ) {
  kk_vector_t contents;
  const int err = kk_os_list_directory(dir,&contents,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_vector_box(contents,ctx),ctx);
}


kk_std_core_exn__exception kk_std_os_dir_prepend(kk_std_core_exn__exception exn, kk_string_t pre, kk_context_t* _ctx) { /* (exn : exception, pre : string) -> exception */ 
  kk_string_t _x_x404;
  kk_string_t _x_x405;
  kk_string_t _x_x406;
  kk_define_string_literal(, _s_x407, 2, ": ", _ctx)
  _x_x406 = kk_string_dup(_s_x407, _ctx); /*string*/
  kk_string_t _x_x408;
  {
    kk_string_t _x = exn.message;
    kk_string_dup(_x, _ctx);
    _x_x408 = _x; /*string*/
  }
  _x_x405 = kk_std_core_types__lp__plus__plus__rp_(_x_x406, _x_x408, _ctx); /*string*/
  _x_x404 = kk_std_core_types__lp__plus__plus__rp_(pre, _x_x405, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x409;
  {
    kk_std_core_exn__exception_info _x_0 = exn.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(exn, _ctx);
    _x_x409 = _x_0; /*exception-info*/
  }
  return kk_std_core_exn__new_Exception(_x_x404, _x_x409, _ctx);
}

kk_std_core_exn__error kk_std_os_dir_prim_copy_file(kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* _ctx) { /* (from : string, to : string, preserve-mtime : bool) -> fsys error<()> */ 
  return kk_os_copy_file_error(from,to,preserve_mtime,kk_context());
}
 
// Copy a file.


// lift anonymous function
struct kk_std_os_dir_copy_file_fun411__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun411(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun411(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun411, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun411(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x412;
  kk_std_os_path__path _x_x413 = kk_std_os_path__path_unbox(_b_x2, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x412 = kk_std_os_path_string(_x_x413, _ctx); /*string*/
  return kk_string_box(_x_x412);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun417__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun417(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun417(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun417, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun417(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x418;
  kk_std_os_path__path _x_x419 = kk_std_os_path__path_unbox(_b_x7, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x418 = kk_std_os_path_string(_x_x419, _ctx); /*string*/
  return kk_string_box(_x_x418);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun423__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun423(kk_function_t _fself, kk_box_t _b_x15, kk_box_t _b_x16, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun423(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun423, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun423(kk_function_t _fself, kk_box_t _b_x15, kk_box_t _b_x16, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x424;
  kk_string_t _x_x425 = kk_string_unbox(_b_x15); /*string*/
  kk_string_t _x_x426 = kk_string_unbox(_b_x16); /*string*/
  bool _x_x427 = kk_bool_unbox(_b_x17); /*bool*/
  _x_x424 = kk_std_os_dir_prim_copy_file(_x_x425, _x_x426, _x_x427, _ctx); /*error<()>*/
  return kk_std_core_exn__error_box(_x_x424, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun435__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun435(kk_function_t _fself, kk_box_t _b_x20, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun435(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun435, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun435(kk_function_t _fself, kk_box_t _b_x20, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x436;
  kk_string_t _x_x437;
  kk_std_os_path__path _x_x438 = kk_std_os_path__path_unbox(_b_x20, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x437 = kk_std_os_path_string(_x_x438, _ctx); /*string*/
  _x_x436 = kk_std_core_show_string_fs_show(_x_x437, _ctx); /*string*/
  return kk_string_box(_x_x436);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun444__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun444(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun444(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun444, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun444(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path p_0_51 = kk_std_os_path__path_unbox(_b_x23, KK_OWNED, _ctx); /*std/os/path/path*/;
  kk_string_t _x_x445;
  kk_string_t _x_x446 = kk_std_os_path_string(p_0_51, _ctx); /*string*/
  _x_x445 = kk_std_core_show_string_fs_show(_x_x446, _ctx); /*string*/
  return kk_string_box(_x_x445);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun448__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun448(kk_function_t _fself, kk_box_t _b_x31, kk_box_t _b_x32, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun448(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun448, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun448(kk_function_t _fself, kk_box_t _b_x31, kk_box_t _b_x32, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__exception _x_x449;
  kk_string_t _x_x450;
  kk_string_t _x_x451 = kk_string_unbox(_b_x32); /*string*/
  kk_string_t _x_x452;
  kk_string_t _x_x453;
  kk_define_string_literal(, _s_x454, 2, ": ", _ctx)
  _x_x453 = kk_string_dup(_s_x454, _ctx); /*string*/
  kk_string_t _x_x455;
  kk_std_core_exn__exception _match_x400;
  kk_box_t _x_x456 = kk_box_dup(_b_x31, _ctx); /*9983*/
  _match_x400 = kk_std_core_exn__exception_unbox(_x_x456, KK_OWNED, _ctx); /*exception*/
  {
    kk_string_t _x = _match_x400.message;
    kk_string_dup(_x, _ctx);
    kk_std_core_exn__exception_drop(_match_x400, _ctx);
    _x_x455 = _x; /*string*/
  }
  _x_x452 = kk_std_core_types__lp__plus__plus__rp_(_x_x453, _x_x455, _ctx); /*string*/
  _x_x450 = kk_std_core_types__lp__plus__plus__rp_(_x_x451, _x_x452, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x457;
  kk_std_core_exn__exception _match_x399 = kk_std_core_exn__exception_unbox(_b_x31, KK_OWNED, _ctx); /*exception*/;
  {
    kk_std_core_exn__exception_info _x_0 = _match_x399.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(_match_x399, _ctx);
    _x_x457 = _x_0; /*exception-info*/
  }
  _x_x449 = kk_std_core_exn__new_Exception(_x_x450, _x_x457, _ctx); /*exception*/
  return kk_std_core_exn__exception_box(_x_x449, _ctx);
}

kk_unit_t kk_std_os_dir_copy_file(kk_std_os_path__path from, kk_std_os_path__path to, kk_std_core_types__optional preserve_mtime, kk_context_t* _ctx) { /* (from : std/os/path/path, to : std/os/path/path, preserve-mtime : ? bool) -> <exn,fsys> () */ 
  kk_string_t _x_x1_10057;
  kk_box_t _x_x410;
  kk_box_t _x_x414;
  kk_std_os_path__path _x_x415 = kk_std_os_path__path_dup(from, _ctx); /*std/os/path/path*/
  _x_x414 = kk_std_os_path__path_box(_x_x415, _ctx); /*9903*/
  _x_x410 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun411(_ctx), _x_x414, _ctx); /*9904*/
  _x_x1_10057 = kk_string_unbox(_x_x410); /*string*/
  kk_string_t _x_x2_10058;
  kk_box_t _x_x416;
  kk_box_t _x_x420;
  kk_std_os_path__path _x_x421 = kk_std_os_path__path_dup(to, _ctx); /*std/os/path/path*/
  _x_x420 = kk_std_os_path__path_box(_x_x421, _ctx); /*9903*/
  _x_x416 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun417(_ctx), _x_x420, _ctx); /*9904*/
  _x_x2_10058 = kk_string_unbox(_x_x416); /*string*/
  kk_std_core_exn__error _match_x396;
  kk_box_t _x_x422;
  kk_box_t _x_x428;
  bool _x_x429;
  if (kk_std_core_types__is_Optional(preserve_mtime, _ctx)) {
    kk_box_t _box_x10 = preserve_mtime._cons._Optional.value;
    bool _uniq_preserve_mtime_101 = kk_bool_unbox(_box_x10);
    kk_std_core_types__optional_drop(preserve_mtime, _ctx);
    _x_x429 = _uniq_preserve_mtime_101; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(preserve_mtime, _ctx);
    _x_x429 = true; /*bool*/
  }
  _x_x428 = kk_bool_box(_x_x429); /*10078*/
  _x_x422 = kk_std_core_hnd__open_none3(kk_std_os_dir_new_copy_file_fun423(_ctx), kk_string_box(_x_x1_10057), kk_string_box(_x_x2_10058), _x_x428, _ctx); /*10079*/
  _match_x396 = kk_std_core_exn__error_unbox(_x_x422, KK_OWNED, _ctx); /*error<()>*/
  if (kk_std_core_exn__is_Error(_match_x396, _ctx)) {
    kk_std_core_exn__exception exn = _match_x396._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x396, _ctx);
    kk_string_t _x_x2_0_10063;
    kk_string_t _x_x430;
    kk_define_string_literal(, _s_x431, 15, "unable to copy ", _ctx)
    _x_x430 = kk_string_dup(_s_x431, _ctx); /*string*/
    kk_string_t _x_x432;
    kk_string_t _x_x433;
    kk_box_t _x_x434 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun435(_ctx), kk_std_os_path__path_box(from, _ctx), _ctx); /*9904*/
    _x_x433 = kk_string_unbox(_x_x434); /*string*/
    kk_string_t _x_x439;
    kk_string_t _x_x440;
    kk_define_string_literal(, _s_x441, 4, " to ", _ctx)
    _x_x440 = kk_string_dup(_s_x441, _ctx); /*string*/
    kk_string_t _x_x442;
    kk_box_t _x_x443 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun444(_ctx), kk_std_os_path__path_box(to, _ctx), _ctx); /*9904*/
    _x_x442 = kk_string_unbox(_x_x443); /*string*/
    _x_x439 = kk_std_core_types__lp__plus__plus__rp_(_x_x440, _x_x442, _ctx); /*string*/
    _x_x432 = kk_std_core_types__lp__plus__plus__rp_(_x_x433, _x_x439, _ctx); /*string*/
    _x_x2_0_10063 = kk_std_core_types__lp__plus__plus__rp_(_x_x430, _x_x432, _ctx); /*string*/
    kk_std_core_exn__exception exn_0_10002;
    kk_box_t _x_x447 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_file_fun448(_ctx), kk_std_core_exn__exception_box(exn, _ctx), kk_string_box(_x_x2_0_10063), _ctx); /*9985*/
    exn_0_10002 = kk_std_core_exn__exception_unbox(_x_x447, KK_OWNED, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_10093 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x458;
    {
      struct kk_std_core_hnd_Ev* _con_x459 = kk_std_core_hnd__as_Ev(ev_10093, _ctx);
      kk_box_t _box_x38 = _con_x459->hnd;
      int32_t m = _con_x459->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x38, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x397;
      kk_std_core_hnd__clause1 _brw_x398 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x397 = _brw_x398; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x42 = _match_x397.clause;
        _x_x458 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x42, (_fun_unbox_x42, m, ev_10093, kk_std_core_exn__exception_box(exn_0_10002, _ctx), _ctx), _ctx); /*46*/
      }
    }
    kk_unit_unbox(_x_x458); return kk_Unit;
  }
  {
    kk_std_os_path__path_drop(to, _ctx);
    kk_std_os_path__path_drop(from, _ctx);
    kk_std_core_exn__error_drop(_match_x396, _ctx);
    kk_Unit; return kk_Unit;
  }
}

kk_std_core_exn__error kk_std_os_dir_ensure_dir_err(kk_string_t path, kk_integer_t mode, kk_context_t* _ctx) { /* (path : string, mode : int) -> fsys error<()> */ 
  return kk_os_ensure_dir_error(path,mode,kk_context());
}
 
// Ensure a directory path exists


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun461__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun461(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun461(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun461, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_ensure_dir_fun461(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x462;
  kk_std_os_path__path _x_x463 = kk_std_os_path__path_unbox(_b_x54, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x462 = kk_std_os_path_string(_x_x463, _ctx); /*string*/
  return kk_string_box(_x_x462);
}


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun467__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun467(kk_function_t _fself, kk_box_t _b_x60, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun467(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun467, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_ensure_dir_fun467(kk_function_t _fself, kk_box_t _b_x60, kk_box_t _b_x61, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x468;
  kk_string_t _x_x469 = kk_string_unbox(_b_x60); /*string*/
  kk_integer_t _x_x470 = kk_integer_unbox(_b_x61, _ctx); /*int*/
  _x_x468 = kk_std_os_dir_ensure_dir_err(_x_x469, _x_x470, _ctx); /*error<()>*/
  return kk_std_core_exn__error_box(_x_x468, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun475__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun475(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun475(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun475, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_ensure_dir_fun475(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x476;
  kk_string_t _x_x477;
  kk_std_os_path__path _x_x478 = kk_std_os_path__path_unbox(_b_x64, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x477 = kk_std_os_path_string(_x_x478, _ctx); /*string*/
  _x_x476 = kk_std_core_show_string_fs_show(_x_x477, _ctx); /*string*/
  return kk_string_box(_x_x476);
}


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun480__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun480(kk_function_t _fself, kk_box_t _b_x71, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun480(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun480, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_ensure_dir_fun480(kk_function_t _fself, kk_box_t _b_x71, kk_box_t _b_x72, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__exception _x_x481;
  kk_string_t _x_x482;
  kk_string_t _x_x483 = kk_string_unbox(_b_x72); /*string*/
  kk_string_t _x_x484;
  kk_string_t _x_x485;
  kk_define_string_literal(, _s_x486, 2, ": ", _ctx)
  _x_x485 = kk_string_dup(_s_x486, _ctx); /*string*/
  kk_string_t _x_x487;
  kk_std_core_exn__exception _match_x395;
  kk_box_t _x_x488 = kk_box_dup(_b_x71, _ctx); /*9983*/
  _match_x395 = kk_std_core_exn__exception_unbox(_x_x488, KK_OWNED, _ctx); /*exception*/
  {
    kk_string_t _x = _match_x395.message;
    kk_string_dup(_x, _ctx);
    kk_std_core_exn__exception_drop(_match_x395, _ctx);
    _x_x487 = _x; /*string*/
  }
  _x_x484 = kk_std_core_types__lp__plus__plus__rp_(_x_x485, _x_x487, _ctx); /*string*/
  _x_x482 = kk_std_core_types__lp__plus__plus__rp_(_x_x483, _x_x484, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x489;
  kk_std_core_exn__exception _match_x394 = kk_std_core_exn__exception_unbox(_b_x71, KK_OWNED, _ctx); /*exception*/;
  {
    kk_std_core_exn__exception_info _x_0 = _match_x394.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(_match_x394, _ctx);
    _x_x489 = _x_0; /*exception-info*/
  }
  _x_x481 = kk_std_core_exn__new_Exception(_x_x482, _x_x489, _ctx); /*exception*/
  return kk_std_core_exn__exception_box(_x_x481, _ctx);
}

kk_unit_t kk_std_os_dir_ensure_dir(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> <exn,fsys> () */ 
  kk_string_t _x_x1_10066;
  kk_box_t _x_x460;
  kk_box_t _x_x464;
  kk_std_os_path__path _x_x465 = kk_std_os_path__path_dup(dir, _ctx); /*std/os/path/path*/
  _x_x464 = kk_std_os_path__path_box(_x_x465, _ctx); /*9903*/
  _x_x460 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_ensure_dir_fun461(_ctx), _x_x464, _ctx); /*9904*/
  _x_x1_10066 = kk_string_unbox(_x_x460); /*string*/
  kk_std_core_exn__error _match_x391;
  kk_box_t _x_x466 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_ensure_dir_fun467(_ctx), kk_string_box(_x_x1_10066), kk_integer_box(kk_integer_from_small(-1), _ctx), _ctx); /*9985*/
  _match_x391 = kk_std_core_exn__error_unbox(_x_x466, KK_OWNED, _ctx); /*error<()>*/
  if (kk_std_core_exn__is_Error(_match_x391, _ctx)) {
    kk_std_core_exn__exception exn = _match_x391._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x391, _ctx);
    kk_string_t _x_x2_0_10070;
    kk_string_t _x_x471;
    kk_define_string_literal(, _s_x472, 27, "unable to create directory ", _ctx)
    _x_x471 = kk_string_dup(_s_x472, _ctx); /*string*/
    kk_string_t _x_x473;
    kk_box_t _x_x474 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_ensure_dir_fun475(_ctx), kk_std_os_path__path_box(dir, _ctx), _ctx); /*9904*/
    _x_x473 = kk_string_unbox(_x_x474); /*string*/
    _x_x2_0_10070 = kk_std_core_types__lp__plus__plus__rp_(_x_x471, _x_x473, _ctx); /*string*/
    kk_std_core_exn__exception exn_0_10005;
    kk_box_t _x_x479 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_ensure_dir_fun480(_ctx), kk_std_core_exn__exception_box(exn, _ctx), kk_string_box(_x_x2_0_10070), _ctx); /*9985*/
    exn_0_10005 = kk_std_core_exn__exception_unbox(_x_x479, KK_OWNED, _ctx); /*exception*/
    kk_std_core_hnd__ev ev_10096 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x490;
    {
      struct kk_std_core_hnd_Ev* _con_x491 = kk_std_core_hnd__as_Ev(ev_10096, _ctx);
      kk_box_t _box_x78 = _con_x491->hnd;
      int32_t m = _con_x491->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x78, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x392;
      kk_std_core_hnd__clause1 _brw_x393 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x392 = _brw_x393; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x82 = _match_x392.clause;
        _x_x490 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x82, (_fun_unbox_x82, m, ev_10096, kk_std_core_exn__exception_box(exn_0_10005, _ctx), _ctx), _ctx); /*46*/
      }
    }
    kk_unit_unbox(_x_x490); return kk_Unit;
  }
  {
    kk_box_t _box_x86 = _match_x391._cons.Ok.result;
    kk_unit_t _pat_3_0 = kk_unit_unbox(_box_x86);
    kk_std_os_path__path_drop(dir, _ctx);
    kk_std_core_exn__error_drop(_match_x391, _ctx);
    kk_Unit; return kk_Unit;
  }
}

bool kk_std_os_dir_prim_is_dir(kk_string_t dir, kk_context_t* _ctx) { /* (dir : string) -> fsys bool */ 
  return kk_os_is_directory(dir,kk_context());
}

kk_std_core_exn__error kk_std_os_dir_prim_list_dir(kk_string_t dir, kk_context_t* _ctx) { /* (dir : string) -> fsys error<vector<string>> */ 
  return kk_os_list_directory_prim(dir,kk_context());
}
 
// List directory contents (excluding `.` and `..`).
// Returns a list of full paths (not just the names in the directory).


// lift anonymous function
struct kk_std_os_dir_list_directory_fun494__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_fun494(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun494(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_fun494, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_fun494(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x495;
  kk_std_os_path__path _x_x496 = kk_std_os_path__path_unbox(_b_x92, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x495 = kk_std_os_path_string(_x_x496, _ctx); /*string*/
  return kk_string_box(_x_x495);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_fun500__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_fun500(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun500(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_fun500, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_fun500(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x501;
  kk_string_t _x_x502 = kk_string_unbox(_b_x97); /*string*/
  _x_x501 = kk_std_os_dir_prim_list_dir(_x_x502, _ctx); /*error<vector<string>>*/
  return kk_std_core_exn__error_box(_x_x501, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_fun505__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir;
};
static kk_box_t kk_std_os_dir_list_directory_fun505(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun505(kk_std_os_path__path dir, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_fun505__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_fun505__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_fun505, kk_context());
  _self->dir = dir;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_os_dir_list_directory_fun507__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_fun507(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun507(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_fun507, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_fun507(kk_function_t _fself, kk_box_t _b_x109, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x508;
  kk_string_t _x_x509 = kk_string_unbox(_b_x109); /*string*/
  _x_x508 = kk_std_os_path_path(_x_x509, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x508, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_fun510__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_fun510(kk_function_t _fself, kk_box_t _b_x115, kk_box_t _b_x116, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun510(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_fun510, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_fun510(kk_function_t _fself, kk_box_t _b_x115, kk_box_t _b_x116, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x511;
  kk_std_os_path__path _x_x512 = kk_std_os_path__path_unbox(_b_x115, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x513 = kk_std_os_path__path_unbox(_b_x116, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x511 = kk_std_os_path__lp__fs__rp_(_x_x512, _x_x513, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x511, _ctx);
}
static kk_box_t kk_std_os_dir_list_directory_fun505(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_fun505__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_fun505__t*, _fself, _ctx);
  kk_std_os_path__path dir = _self->dir; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir, _ctx);}, {}, _ctx)
  kk_string_t name_127 = kk_string_unbox(_b_x119); /*string*/;
  kk_std_os_path__path _x_x2_10075;
  kk_box_t _x_x506 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_list_directory_fun507(_ctx), kk_string_box(name_127), _ctx); /*9904*/
  _x_x2_10075 = kk_std_os_path__path_unbox(_x_x506, KK_OWNED, _ctx); /*std/os/path/path*/
  return kk_std_core_hnd__open_none2(kk_std_os_dir_new_list_directory_fun510(_ctx), kk_std_os_path__path_box(dir, _ctx), kk_std_os_path__path_box(_x_x2_10075, _ctx), _ctx);
}

kk_std_core_types__list kk_std_os_dir_list_directory(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> <exn,fsys> list<std/os/path/path> */ 
  kk_string_t _x_x1_10072;
  kk_box_t _x_x493;
  kk_box_t _x_x497;
  kk_std_os_path__path _x_x498 = kk_std_os_path__path_dup(dir, _ctx); /*std/os/path/path*/
  _x_x497 = kk_std_os_path__path_box(_x_x498, _ctx); /*9903*/
  _x_x493 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_list_directory_fun494(_ctx), _x_x497, _ctx); /*9904*/
  _x_x1_10072 = kk_string_unbox(_x_x493); /*string*/
  kk_std_core_exn__error _match_x386;
  kk_box_t _x_x499 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_list_directory_fun500(_ctx), kk_string_box(_x_x1_10072), _ctx); /*9904*/
  _match_x386 = kk_std_core_exn__error_unbox(_x_x499, KK_OWNED, _ctx); /*error<vector<string>>*/
  if (kk_std_core_exn__is_Error(_match_x386, _ctx)) {
    kk_std_core_exn__exception exn = _match_x386._cons.Error.exception;
    kk_std_os_path__path_drop(dir, _ctx);
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x386, _ctx);
    kk_std_core_hnd__ev ev_10099 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x503;
    {
      struct kk_std_core_hnd_Ev* _con_x504 = kk_std_core_hnd__as_Ev(ev_10099, _ctx);
      kk_box_t _box_x98 = _con_x504->hnd;
      int32_t m = _con_x504->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x98, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x389;
      kk_std_core_hnd__clause1 _brw_x390 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,276,exn,277,278>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x389 = _brw_x390; /*hnd/clause1<exception,276,exn,277,278>*/
      {
        kk_function_t _fun_unbox_x102 = _match_x389.clause;
        _x_x503 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x102, (_fun_unbox_x102, m, ev_10099, kk_std_core_exn__exception_box(exn, _ctx), _ctx), _ctx); /*46*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x503, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x106 = _match_x386._cons.Ok.result;
    kk_vector_t contents = kk_vector_unbox(_box_x106, _ctx);
    kk_vector_dup(contents, _ctx);
    kk_std_core_exn__error_drop(_match_x386, _ctx);
    kk_std_core_types__list _b_x117_122 = kk_std_core_vector_vlist(contents, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    kk_function_t _brw_x387 = kk_std_os_dir_new_list_directory_fun505(dir, _ctx); /*(2217) -> 2219 9985*/;
    kk_std_core_types__list _brw_x388 = kk_std_core_list_map(_b_x117_122, _brw_x387, _ctx); /*list<2218>*/;
    kk_function_drop(_brw_x387, _ctx);
    return _brw_x388;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10086(kk_std_core_types__list all, kk_std_core_types__list _y_x10019, kk_context_t* _ctx) { /* (all : list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  return kk_std_core_list_append(all, _y_x10019, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun514__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth;
};
static kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10087_fun514(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10087_fun514(kk_std_core_types__optional max_depth, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun514__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun514__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_list_directory_recursive_10087_fun514, kk_context());
  _self->max_depth = max_depth;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10087_fun514(kk_function_t _fself, kk_box_t _b_x132, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun514__t* _self = kk_function_as(struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun514__t*, _fself, _ctx);
  kk_std_core_types__optional max_depth = _self->max_depth; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth, _ctx);}, {}, _ctx)
  kk_integer_t _b_x129_135;
  kk_integer_t _x_x515;
  if (kk_std_core_types__is_Optional(max_depth, _ctx)) {
    kk_box_t _box_x128 = max_depth._cons._Optional.value;
    kk_integer_t _uniq_max_depth_548_0 = kk_integer_unbox(_box_x128, _ctx);
    kk_integer_dup(_uniq_max_depth_548_0, _ctx);
    kk_std_core_types__optional_drop(max_depth, _ctx);
    _x_x515 = _uniq_max_depth_548_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_depth, _ctx);
    _x_x515 = kk_integer_from_small(1000); /*int*/
  }
  _b_x129_135 = kk_integer_add_small_const(_x_x515, -1, _ctx); /*int*/
  kk_std_os_path__path _x_x516 = kk_std_os_path__path_unbox(_b_x132, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_core_types__optional _x_x517 = kk_std_core_types__new_Optional(kk_integer_box(_b_x129_135, _ctx), _ctx); /*? 7*/
  return kk_std_os_dir_list_directory_recursive(_x_x516, _x_x517, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun519__t {
  struct kk_function_s _base;
  kk_std_core_types__list all_0;
};
static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10087_fun519(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10087_fun519(kk_std_core_types__list all_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun519__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun519__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_list_directory_recursive_10087_fun519, kk_context());
  _self->all_0 = all_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10087_fun519(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun519__t* _self = kk_function_as(struct kk_std_os_dir__mlift_list_directory_recursive_10087_fun519__t*, _fself, _ctx);
  kk_std_core_types__list all_0 = _self->all_0; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(all_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10019_0_140 = kk_std_core_types__list_unbox(_b_x138, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x520 = kk_std_os_dir__mlift_list_directory_recursive_10086(all_0, _y_x10019_0_140, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x520, _ctx);
}

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10087(kk_std_core_types__list all_0, kk_std_core_types__optional max_depth, kk_std_core_types__list dirs, kk_context_t* _ctx) { /* (all : list<std/os/path/path>, max-depth : ? int, dirs : list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 
  kk_std_core_types__list x_10102 = kk_std_core_list_flatmap(dirs, kk_std_os_dir__new_mlift_list_directory_recursive_10087_fun514(max_depth, _ctx), _ctx); /*list<std/os/path/path>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10102, _ctx);
    kk_box_t _x_x518 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_list_directory_recursive_10087_fun519(all_0, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x518, KK_OWNED, _ctx);
  }
  {
    return kk_std_os_dir__mlift_list_directory_recursive_10086(all_0, x_10102, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun522__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir__mlift_list_directory_recursive_10088_fun522(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10088_fun522(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_list_directory_recursive_10088_fun522, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun524__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10088_fun524(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10088_fun524(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_list_directory_recursive_10088_fun524, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10088_fun524(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x525;
  kk_std_os_path__path _x_x526 = kk_std_os_path__path_unbox(_b_x143, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x525 = kk_std_os_dir_is_directory(_x_x526, _ctx); /*bool*/
  return kk_bool_box(_x_x525);
}
static bool kk_std_os_dir__mlift_list_directory_recursive_10088_fun522(kk_function_t _fself, kk_box_t _b_x146, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x523 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift_list_directory_recursive_10088_fun524(_ctx), _b_x146, _ctx); /*9904*/
  return kk_bool_unbox(_x_x523);
}


// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun528__t {
  struct kk_function_s _base;
  kk_std_core_types__list all_1;
  kk_std_core_types__optional max_depth_0;
};
static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10088_fun528(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10088_fun528(kk_std_core_types__list all_1, kk_std_core_types__optional max_depth_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun528__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun528__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_list_directory_recursive_10088_fun528, kk_context());
  _self->all_1 = all_1;
  _self->max_depth_0 = max_depth_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10088_fun528(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun528__t* _self = kk_function_as(struct kk_std_os_dir__mlift_list_directory_recursive_10088_fun528__t*, _fself, _ctx);
  kk_std_core_types__list all_1 = _self->all_1; /* list<std/os/path/path> */
  kk_std_core_types__optional max_depth_0 = _self->max_depth_0; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(all_1, _ctx);kk_std_core_types__optional_dup(max_depth_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list dirs_0_155 = kk_std_core_types__list_unbox(_b_x153, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x529 = kk_std_os_dir__mlift_list_directory_recursive_10087(all_1, max_depth_0, dirs_0_155, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x529, _ctx);
}

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10088(kk_std_core_types__optional max_depth_0, kk_std_core_types__list all_1, kk_context_t* _ctx) { /* (max-depth : ? int, all : list<std/os/path/path>) -> <exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__list x_0_10104;
  kk_std_core_types__list _x_x521 = kk_std_core_types__list_dup(all_1, _ctx); /*list<std/os/path/path>*/
  x_0_10104 = kk_std_core_list_filter(_x_x521, kk_std_os_dir__new_mlift_list_directory_recursive_10088_fun522(_ctx), _ctx); /*list<std/os/path/path>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10104, _ctx);
    kk_box_t _x_x527 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_list_directory_recursive_10088_fun528(all_1, max_depth_0, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x527, KK_OWNED, _ctx);
  }
  {
    return kk_std_os_dir__mlift_list_directory_recursive_10087(all_1, max_depth_0, x_0_10104, _ctx);
  }
}
 
// Recursively list all the entries under a directory.


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun531__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth_1;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun531(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun531(kk_std_core_types__optional max_depth_1, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun531__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun531__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun531, kk_context());
  _self->max_depth_1 = max_depth_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun531(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun531__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun531__t*, _fself, _ctx);
  kk_std_core_types__optional max_depth_1 = _self->max_depth_1; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth_1, _ctx);}, {}, _ctx)
  kk_std_core_types__list all_2_186 = kk_std_core_types__list_unbox(_b_x158, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x532 = kk_std_os_dir__mlift_list_directory_recursive_10088(max_depth_1, all_2_186, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x532, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun534__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir_list_directory_recursive_fun534(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun534(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_recursive_fun534, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun536__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun536(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun536(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_recursive_fun536, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun536(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x537;
  kk_std_os_path__path _x_x538 = kk_std_os_path__path_unbox(_b_x161, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x537 = kk_std_os_dir_is_directory(_x_x538, _ctx); /*bool*/
  return kk_bool_box(_x_x537);
}
static bool kk_std_os_dir_list_directory_recursive_fun534(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x535 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_list_directory_recursive_fun536(_ctx), _b_x164, _ctx); /*9904*/
  return kk_bool_unbox(_x_x535);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun540__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth_1;
  kk_std_core_types__list x_1_10106;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun540(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun540(kk_std_core_types__optional max_depth_1, kk_std_core_types__list x_1_10106, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun540__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun540__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun540, kk_context());
  _self->max_depth_1 = max_depth_1;
  _self->x_1_10106 = x_1_10106;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun540(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun540__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun540__t*, _fself, _ctx);
  kk_std_core_types__optional max_depth_1 = _self->max_depth_1; /* ? int */
  kk_std_core_types__list x_1_10106 = _self->x_1_10106; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth_1, _ctx);kk_std_core_types__list_dup(x_1_10106, _ctx);}, {}, _ctx)
  kk_std_core_types__list dirs_1_187 = kk_std_core_types__list_unbox(_b_x171, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x541 = kk_std_os_dir__mlift_list_directory_recursive_10087(x_1_10106, max_depth_1, dirs_1_187, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x541, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun542__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth_1;
};
static kk_std_core_types__list kk_std_os_dir_list_directory_recursive_fun542(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun542(kk_std_core_types__optional max_depth_1, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun542__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun542__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun542, kk_context());
  _self->max_depth_1 = max_depth_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__list kk_std_os_dir_list_directory_recursive_fun542(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun542__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun542__t*, _fself, _ctx);
  kk_std_core_types__optional max_depth_1 = _self->max_depth_1; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth_1, _ctx);}, {}, _ctx)
  kk_integer_t _b_x173_179;
  kk_integer_t _x_x543;
  if (kk_std_core_types__is_Optional(max_depth_1, _ctx)) {
    kk_box_t _box_x172 = max_depth_1._cons._Optional.value;
    kk_integer_t _uniq_max_depth_548_0_0 = kk_integer_unbox(_box_x172, _ctx);
    kk_integer_dup(_uniq_max_depth_548_0_0, _ctx);
    kk_std_core_types__optional_drop(max_depth_1, _ctx);
    _x_x543 = _uniq_max_depth_548_0_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_depth_1, _ctx);
    _x_x543 = kk_integer_from_small(1000); /*int*/
  }
  _b_x173_179 = kk_integer_add_small_const(_x_x543, -1, _ctx); /*int*/
  kk_std_os_path__path _x_x544 = kk_std_os_path__path_unbox(_b_x176, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_core_types__optional _x_x545 = kk_std_core_types__new_Optional(kk_integer_box(_b_x173_179, _ctx), _ctx); /*? 7*/
  return kk_std_os_dir_list_directory_recursive(_x_x544, _x_x545, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun547__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_1_10106;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun547(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun547(kk_std_core_types__list x_1_10106, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun547__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun547__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun547, kk_context());
  _self->x_1_10106 = x_1_10106;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun547(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun547__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun547__t*, _fself, _ctx);
  kk_std_core_types__list x_1_10106 = _self->x_1_10106; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_1_10106, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10019_1_188 = kk_std_core_types__list_unbox(_b_x182, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x548 = kk_std_os_dir__mlift_list_directory_recursive_10086(x_1_10106, _y_x10019_1_188, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x548, _ctx);
}

kk_std_core_types__list kk_std_os_dir_list_directory_recursive(kk_std_os_path__path dir, kk_std_core_types__optional max_depth_1, kk_context_t* _ctx) { /* (dir : std/os/path/path, max-depth : ? int) -> <pure,fsys> list<std/os/path/path> */ 
  bool _match_x378;
  kk_integer_t _brw_x382;
  if (kk_std_core_types__is_Optional(max_depth_1, _ctx)) {
    kk_box_t _box_x156 = max_depth_1._cons._Optional.value;
    kk_integer_t _uniq_max_depth_548 = kk_integer_unbox(_box_x156, _ctx);
    kk_integer_dup(_uniq_max_depth_548, _ctx);
    _brw_x382 = _uniq_max_depth_548; /*int*/
  }
  else {
    _brw_x382 = kk_integer_from_small(1000); /*int*/
  }
  bool _brw_x383 = kk_integer_lt_borrow(_brw_x382,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x382, _ctx);
  _match_x378 = _brw_x383; /*bool*/
  if (_match_x378) {
    kk_std_core_types__optional_drop(max_depth_1, _ctx);
    kk_std_os_path__path_drop(dir, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__list x_1_10106 = kk_std_os_dir_list_directory(dir, _ctx); /*list<std/os/path/path>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_10106, _ctx);
      kk_box_t _x_x530 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_list_directory_recursive_fun531(max_depth_1, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x530, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list x_2_10109;
      kk_std_core_types__list _x_x533 = kk_std_core_types__list_dup(x_1_10106, _ctx); /*list<std/os/path/path>*/
      x_2_10109 = kk_std_core_list_filter(_x_x533, kk_std_os_dir_new_list_directory_recursive_fun534(_ctx), _ctx); /*list<std/os/path/path>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_2_10109, _ctx);
        kk_box_t _x_x539 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_list_directory_recursive_fun540(max_depth_1, x_1_10106, _ctx), _ctx); /*2419*/
        return kk_std_core_types__list_unbox(_x_x539, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list x_3_10112 = kk_std_core_list_flatmap(x_2_10109, kk_std_os_dir_new_list_directory_recursive_fun542(max_depth_1, _ctx), _ctx); /*list<std/os/path/path>*/;
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_3_10112, _ctx);
          kk_box_t _x_x546 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_list_directory_recursive_fun547(x_1_10106, _ctx), _ctx); /*2419*/
          return kk_std_core_types__list_unbox(_x_x546, KK_OWNED, _ctx);
        }
        {
          return kk_std_core_list_append(x_1_10106, x_3_10112, _ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10089_fun549__t {
  struct kk_function_s _base;
  kk_std_os_path__path to;
};
static kk_unit_t kk_std_os_dir__mlift_copy_directory_10089_fun549(kk_function_t _fself, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10089_fun549(kk_std_os_path__path to, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10089_fun549__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10089_fun549__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10089_fun549, kk_context());
  _self->to = to;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10089_fun551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10089_fun551(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10089_fun551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_copy_directory_10089_fun551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10089_fun551(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _b_x189_190;
  kk_std_core_types__list _x_x552;
  kk_std_os_path__path _match_x377;
  kk_box_t _x_x553 = kk_box_dup(_b_x194, _ctx); /*9903*/
  _match_x377 = kk_std_os_path__path_unbox(_x_x553, KK_OWNED, _ctx); /*std/os/path/path*/
  {
    kk_std_core_types__list _x_1_0 = _match_x377.parts;
    kk_std_core_types__list_dup(_x_1_0, _ctx);
    kk_std_os_path__path_drop(_match_x377, _ctx);
    _x_x552 = _x_1_0; /*list<string>*/
  }
  _b_x189_190 = kk_std_core_list_take(_x_x552, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_std_os_path__path _x_x554;
  kk_string_t _x_x555 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x557;
  kk_std_core_types__optional _match_x375 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x189_190, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x375, _ctx)) {
    kk_box_t _box_x191 = _match_x375._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136_0 = kk_std_core_types__list_unbox(_box_x191, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136_0, _ctx);
    kk_std_core_types__optional_drop(_match_x375, _ctx);
    kk_box_drop(_b_x194, _ctx);
    _x_x557 = _uniq_parts_136_0; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x375, _ctx);
    kk_std_os_path__path _match_x376 = kk_std_os_path__path_unbox(_b_x194, KK_OWNED, _ctx); /*std/os/path/path*/;
    {
      kk_std_core_types__list _x_0_0 = _match_x376.parts;
      kk_std_core_types__list_dup(_x_0_0, _ctx);
      kk_std_os_path__path_drop(_match_x376, _ctx);
      _x_x557 = _x_0_0; /*list<string>*/
    }
  }
  _x_x554 = kk_std_os_path__new_Path(_x_x555, _x_x557, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x554, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10089_fun562__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10089_fun562(kk_function_t _fself, kk_box_t _b_x201, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10089_fun562(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_copy_directory_10089_fun562, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10089_fun562(kk_function_t _fself, kk_box_t _b_x201, kk_box_t _b_x202, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x563;
  kk_std_os_path__path _x_x564 = kk_std_os_path__path_unbox(_b_x201, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x565 = kk_std_os_path__path_unbox(_b_x202, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x563 = kk_std_os_path__lp__fs__rp_(_x_x564, _x_x565, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x563, _ctx);
}
static kk_unit_t kk_std_os_dir__mlift_copy_directory_10089_fun549(kk_function_t _fself, kk_box_t _b_x205, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10089_fun549__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10089_fun549__t*, _fself, _ctx);
  kk_std_os_path__path to = _self->to; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to, _ctx);}, {}, _ctx)
  kk_std_os_path__path _x_x2_0_10081;
  kk_box_t _x_x550;
  kk_box_t _x_x558 = kk_box_dup(_b_x205, _ctx); /*3031*/
  _x_x550 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift_copy_directory_10089_fun551(_ctx), _x_x558, _ctx); /*9904*/
  _x_x2_0_10081 = kk_std_os_path__path_unbox(_x_x550, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x559 = kk_std_os_path__path_unbox(_b_x205, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x560;
  kk_box_t _x_x561 = kk_std_core_hnd__open_none2(kk_std_os_dir__new_mlift_copy_directory_10089_fun562(_ctx), kk_std_os_path__path_box(to, _ctx), kk_std_os_path__path_box(_x_x2_0_10081, _ctx), _ctx); /*9985*/
  _x_x560 = kk_std_os_path__path_unbox(_x_x561, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_dir_copy_directory(_x_x559, _x_x560, _ctx); return kk_Unit;
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10089(kk_std_core_types__list dirs, kk_std_os_path__path to, kk_unit_t wild___0, kk_context_t* _ctx) { /* (dirs : list<std/os/path/path>, to : std/os/path/path, wild_@0 : ()) -> <exn,fsys,div> () */ 
  kk_std_core_list_foreach(dirs, kk_std_os_dir__new_mlift_copy_directory_10089_fun549(to, _ctx), _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10090_fun567__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_0;
};
static kk_unit_t kk_std_os_dir__mlift_copy_directory_10090_fun567(kk_function_t _fself, kk_box_t _b_x230, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10090_fun567(kk_std_os_path__path to_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10090_fun567__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10090_fun567__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10090_fun567, kk_context());
  _self->to_0 = to_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10090_fun569__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10090_fun569(kk_function_t _fself, kk_box_t _b_x219, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10090_fun569(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_copy_directory_10090_fun569, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10090_fun569(kk_function_t _fself, kk_box_t _b_x219, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _b_x214_215;
  kk_std_core_types__list _x_x570;
  kk_std_os_path__path _match_x374;
  kk_box_t _x_x571 = kk_box_dup(_b_x219, _ctx); /*9903*/
  _match_x374 = kk_std_os_path__path_unbox(_x_x571, KK_OWNED, _ctx); /*std/os/path/path*/
  {
    kk_std_core_types__list _x_1 = _match_x374.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    kk_std_os_path__path_drop(_match_x374, _ctx);
    _x_x570 = _x_1; /*list<string>*/
  }
  _b_x214_215 = kk_std_core_list_take(_x_x570, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_std_os_path__path _x_x572;
  kk_string_t _x_x573 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x575;
  kk_std_core_types__optional _match_x372 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x214_215, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x372, _ctx)) {
    kk_box_t _box_x216 = _match_x372._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136 = kk_std_core_types__list_unbox(_box_x216, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136, _ctx);
    kk_std_core_types__optional_drop(_match_x372, _ctx);
    kk_box_drop(_b_x219, _ctx);
    _x_x575 = _uniq_parts_136; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x372, _ctx);
    kk_std_os_path__path _match_x373 = kk_std_os_path__path_unbox(_b_x219, KK_OWNED, _ctx); /*std/os/path/path*/;
    {
      kk_std_core_types__list _x_0 = _match_x373.parts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      kk_std_os_path__path_drop(_match_x373, _ctx);
      _x_x575 = _x_0; /*list<string>*/
    }
  }
  _x_x572 = kk_std_os_path__new_Path(_x_x573, _x_x575, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x572, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10090_fun580__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10090_fun580(kk_function_t _fself, kk_box_t _b_x226, kk_box_t _b_x227, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10090_fun580(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_copy_directory_10090_fun580, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10090_fun580(kk_function_t _fself, kk_box_t _b_x226, kk_box_t _b_x227, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x581;
  kk_std_os_path__path _x_x582 = kk_std_os_path__path_unbox(_b_x226, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x583 = kk_std_os_path__path_unbox(_b_x227, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x581 = kk_std_os_path__lp__fs__rp_(_x_x582, _x_x583, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x581, _ctx);
}
static kk_unit_t kk_std_os_dir__mlift_copy_directory_10090_fun567(kk_function_t _fself, kk_box_t _b_x230, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10090_fun567__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10090_fun567__t*, _fself, _ctx);
  kk_std_os_path__path to_0 = _self->to_0; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_0, _ctx);}, {}, _ctx)
  kk_std_os_path__path _x_x2_10078;
  kk_box_t _x_x568;
  kk_box_t _x_x576 = kk_box_dup(_b_x230, _ctx); /*3031*/
  _x_x568 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift_copy_directory_10090_fun569(_ctx), _x_x576, _ctx); /*9904*/
  _x_x2_10078 = kk_std_os_path__path_unbox(_x_x568, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x577 = kk_std_os_path__path_unbox(_b_x230, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x578;
  kk_box_t _x_x579 = kk_std_core_hnd__open_none2(kk_std_os_dir__new_mlift_copy_directory_10090_fun580(_ctx), kk_std_os_path__path_box(to_0, _ctx), kk_std_os_path__path_box(_x_x2_10078, _ctx), _ctx); /*9985*/
  _x_x578 = kk_std_os_path__path_unbox(_x_x579, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_dir_copy_file(_x_x577, _x_x578, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10090_fun585__t {
  struct kk_function_s _base;
  kk_std_core_types__list dirs_0;
  kk_std_os_path__path to_0;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10090_fun585(kk_function_t _fself, kk_box_t _b_x238, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10090_fun585(kk_std_core_types__list dirs_0, kk_std_os_path__path to_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10090_fun585__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10090_fun585__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10090_fun585, kk_context());
  _self->dirs_0 = dirs_0;
  _self->to_0 = to_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10090_fun585(kk_function_t _fself, kk_box_t _b_x238, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10090_fun585__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10090_fun585__t*, _fself, _ctx);
  kk_std_core_types__list dirs_0 = _self->dirs_0; /* list<std/os/path/path> */
  kk_std_os_path__path to_0 = _self->to_0; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__list_dup(dirs_0, _ctx);kk_std_os_path__path_dup(to_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_0_240 = kk_Unit;
  kk_unit_unbox(_b_x238);
  kk_unit_t _x_x586 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10089(dirs_0, to_0, wild___0_0_240, _ctx);
  return kk_unit_box(_x_x586);
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10090(kk_std_os_path__path to_0, kk_std_core_types__tuple2 _y_x10023, kk_context_t* _ctx) { /* (to : std/os/path/path, (list<std/os/path/path>, list<std/os/path/path>)) -> <fsys,div,exn> () */ 
  {
    kk_box_t _box_x212 = _y_x10023.fst;
    kk_box_t _box_x213 = _y_x10023.snd;
    kk_std_core_types__list dirs_0 = kk_std_core_types__list_unbox(_box_x212, KK_BORROWED, _ctx);
    kk_std_core_types__list files = kk_std_core_types__list_unbox(_box_x213, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(dirs_0, _ctx);
    kk_std_core_types__list_dup(files, _ctx);
    kk_std_core_types__tuple2_drop(_y_x10023, _ctx);
    kk_unit_t x_10115 = kk_Unit;
    kk_function_t _x_x566;
    kk_std_os_path__path_dup(to_0, _ctx);
    _x_x566 = kk_std_os_dir__new_mlift_copy_directory_10090_fun567(to_0, _ctx); /*(3031) -> 3032 ()*/
    kk_std_core_list_foreach(files, _x_x566, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x584 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_copy_directory_10090_fun585(dirs_0, to_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x584); return kk_Unit;
    }
    {
      kk_std_os_dir__mlift_copy_directory_10089(dirs_0, to_0, x_10115, _ctx); return kk_Unit;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10091_fun587__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir__mlift_copy_directory_10091_fun587(kk_function_t _fself, kk_box_t _b_x246, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10091_fun587(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_copy_directory_10091_fun587, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10091_fun589__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10091_fun589(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10091_fun589(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__mlift_copy_directory_10091_fun589, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10091_fun589(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x590;
  kk_std_os_path__path _x_x591 = kk_std_os_path__path_unbox(_b_x243, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x590 = kk_std_os_dir_is_directory(_x_x591, _ctx); /*bool*/
  return kk_bool_box(_x_x590);
}
static bool kk_std_os_dir__mlift_copy_directory_10091_fun587(kk_function_t _fself, kk_box_t _b_x246, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x588 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_mlift_copy_directory_10091_fun589(_ctx), _b_x246, _ctx); /*9904*/
  return kk_bool_unbox(_x_x588);
}


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10091_fun593__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_1;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10091_fun593(kk_function_t _fself, kk_box_t _b_x253, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10091_fun593(kk_std_os_path__path to_1, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10091_fun593__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10091_fun593__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10091_fun593, kk_context());
  _self->to_1 = to_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10091_fun593(kk_function_t _fself, kk_box_t _b_x253, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10091_fun593__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10091_fun593__t*, _fself, _ctx);
  kk_std_os_path__path to_1 = _self->to_1; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_1, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _y_x10023_0_255 = kk_std_core_types__tuple2_unbox(_b_x253, KK_OWNED, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  kk_unit_t _x_x594 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10090(to_1, _y_x10023_0_255, _ctx);
  return kk_unit_box(_x_x594);
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10091(kk_std_os_path__path to_1, kk_std_core_types__list all, kk_context_t* _ctx) { /* (to : std/os/path/path, all : list<std/os/path/path>) -> <exn,fsys> () */ 
  kk_std_core_types__tuple2 x_0_10117;
  kk_function_t _brw_x369 = kk_std_os_dir__new_mlift_copy_directory_10091_fun587(_ctx); /*(2758) -> 2759 bool*/;
  kk_std_core_types__tuple2 _brw_x370 = kk_std_core_list_partition(all, _brw_x369, _ctx); /*(list<2758>, list<2758>)*/;
  kk_function_drop(_brw_x369, _ctx);
  x_0_10117 = _brw_x370; /*(list<std/os/path/path>, list<std/os/path/path>)*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2_drop(x_0_10117, _ctx);
    kk_box_t _x_x592 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_copy_directory_10091_fun593(to_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x592); return kk_Unit;
  }
  {
    kk_std_os_dir__mlift_copy_directory_10090(to_1, x_0_10117, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10092_fun596__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_2;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10092_fun596(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10092_fun596(kk_std_os_path__path to_2, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10092_fun596__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10092_fun596__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10092_fun596, kk_context());
  _self->to_2 = to_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10092_fun596(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10092_fun596__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10092_fun596__t*, _fself, _ctx);
  kk_std_os_path__path to_2 = _self->to_2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_2, _ctx);}, {}, _ctx)
  kk_std_core_types__list all_0_259 = kk_std_core_types__list_unbox(_b_x257, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_unit_t _x_x597 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10091(to_2, all_0_259, _ctx);
  return kk_unit_box(_x_x597);
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10092(kk_std_os_path__path dir, kk_std_os_path__path to_2, kk_unit_t wild__, kk_context_t* _ctx) { /* (dir : std/os/path/path, to : std/os/path/path, wild_ : ()) -> <exn,fsys> () */ 
  kk_std_core_types__list x_1_10119 = kk_std_os_dir_list_directory(dir, _ctx); /*list<std/os/path/path>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10119, _ctx);
    kk_box_t _x_x595 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_copy_directory_10092_fun596(to_2, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x595); return kk_Unit;
  }
  {
    kk_std_os_dir__mlift_copy_directory_10091(to_2, x_1_10119, _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun600__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir_0;
  kk_std_os_path__path to_3;
};
static kk_box_t kk_std_os_dir_copy_directory_fun600(kk_function_t _fself, kk_box_t _b_x261, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun600(kk_std_os_path__path dir_0, kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun600__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun600__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun600, kk_context());
  _self->dir_0 = dir_0;
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun600(kk_function_t _fself, kk_box_t _b_x261, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun600__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun600__t*, _fself, _ctx);
  kk_std_os_path__path dir_0 = _self->dir_0; /* std/os/path/path */
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir_0, _ctx);kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_330 = kk_Unit;
  kk_unit_unbox(_b_x261);
  kk_unit_t _x_x601 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10092(dir_0, to_3, wild___1_330, _ctx);
  return kk_unit_box(_x_x601);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun603__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_3;
};
static kk_box_t kk_std_os_dir_copy_directory_fun603(kk_function_t _fself, kk_box_t _b_x263, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun603(kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun603__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun603__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun603, kk_context());
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun603(kk_function_t _fself, kk_box_t _b_x263, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun603__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun603__t*, _fself, _ctx);
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_std_core_types__list all_1_331 = kk_std_core_types__list_unbox(_b_x263, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_unit_t _x_x604 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10091(to_3, all_1_331, _ctx);
  return kk_unit_box(_x_x604);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun605__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir_copy_directory_fun605(kk_function_t _fself, kk_box_t _b_x269, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun605(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun605, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_dir_copy_directory_fun607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun607(kk_function_t _fself, kk_box_t _b_x266, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun607, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun607(kk_function_t _fself, kk_box_t _b_x266, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x608;
  kk_std_os_path__path _x_x609 = kk_std_os_path__path_unbox(_b_x266, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x608 = kk_std_os_dir_is_directory(_x_x609, _ctx); /*bool*/
  return kk_bool_box(_x_x608);
}
static bool kk_std_os_dir_copy_directory_fun605(kk_function_t _fself, kk_box_t _b_x269, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x606 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun607(_ctx), _b_x269, _ctx); /*9904*/
  return kk_bool_unbox(_x_x606);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun611__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_3;
};
static kk_box_t kk_std_os_dir_copy_directory_fun611(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun611(kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun611__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun611__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun611, kk_context());
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun611(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun611__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun611__t*, _fself, _ctx);
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _y_x10023_1_332 = kk_std_core_types__tuple2_unbox(_b_x276, KK_OWNED, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  kk_unit_t _x_x612 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10090(to_3, _y_x10023_1_332, _ctx);
  return kk_unit_box(_x_x612);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun614__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_3;
};
static kk_unit_t kk_std_os_dir_copy_directory_fun614(kk_function_t _fself, kk_box_t _b_x295, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun614(kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun614__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun614__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun614, kk_context());
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_os_dir_copy_directory_fun616__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun616(kk_function_t _fself, kk_box_t _b_x284, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun616(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun616, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun616(kk_function_t _fself, kk_box_t _b_x284, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _b_x279_280;
  kk_std_core_types__list _x_x617;
  kk_std_os_path__path _match_x364;
  kk_box_t _x_x618 = kk_box_dup(_b_x284, _ctx); /*9903*/
  _match_x364 = kk_std_os_path__path_unbox(_x_x618, KK_OWNED, _ctx); /*std/os/path/path*/
  {
    kk_std_core_types__list _x_1_1 = _match_x364.parts;
    kk_std_core_types__list_dup(_x_1_1, _ctx);
    kk_std_os_path__path_drop(_match_x364, _ctx);
    _x_x617 = _x_1_1; /*list<string>*/
  }
  _b_x279_280 = kk_std_core_list_take(_x_x617, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_std_os_path__path _x_x619;
  kk_string_t _x_x620 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x622;
  kk_std_core_types__optional _match_x362 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x279_280, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x362, _ctx)) {
    kk_box_t _box_x281 = _match_x362._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136_1 = kk_std_core_types__list_unbox(_box_x281, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136_1, _ctx);
    kk_std_core_types__optional_drop(_match_x362, _ctx);
    kk_box_drop(_b_x284, _ctx);
    _x_x622 = _uniq_parts_136_1; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x362, _ctx);
    kk_std_os_path__path _match_x363 = kk_std_os_path__path_unbox(_b_x284, KK_OWNED, _ctx); /*std/os/path/path*/;
    {
      kk_std_core_types__list _x_0_1 = _match_x363.parts;
      kk_std_core_types__list_dup(_x_0_1, _ctx);
      kk_std_os_path__path_drop(_match_x363, _ctx);
      _x_x622 = _x_0_1; /*list<string>*/
    }
  }
  _x_x619 = kk_std_os_path__new_Path(_x_x620, _x_x622, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x619, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun627__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun627(kk_function_t _fself, kk_box_t _b_x291, kk_box_t _b_x292, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun627(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun627, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun627(kk_function_t _fself, kk_box_t _b_x291, kk_box_t _b_x292, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x628;
  kk_std_os_path__path _x_x629 = kk_std_os_path__path_unbox(_b_x291, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x630 = kk_std_os_path__path_unbox(_b_x292, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x628 = kk_std_os_path__lp__fs__rp_(_x_x629, _x_x630, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x628, _ctx);
}
static kk_unit_t kk_std_os_dir_copy_directory_fun614(kk_function_t _fself, kk_box_t _b_x295, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun614__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun614__t*, _fself, _ctx);
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_std_os_path__path _x_x2_10078_0;
  kk_box_t _x_x615;
  kk_box_t _x_x623 = kk_box_dup(_b_x295, _ctx); /*3031*/
  _x_x615 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun616(_ctx), _x_x623, _ctx); /*9904*/
  _x_x2_10078_0 = kk_std_os_path__path_unbox(_x_x615, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x624 = kk_std_os_path__path_unbox(_b_x295, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x625;
  kk_box_t _x_x626 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_directory_fun627(_ctx), kk_std_os_path__path_box(to_3, _ctx), kk_std_os_path__path_box(_x_x2_10078_0, _ctx), _ctx); /*9985*/
  _x_x625 = kk_std_os_path__path_unbox(_x_x626, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_dir_copy_file(_x_x624, _x_x625, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun632__t {
  struct kk_function_s _base;
  kk_std_core_types__list dirs_1;
  kk_std_os_path__path to_3;
};
static kk_box_t kk_std_os_dir_copy_directory_fun632(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun632(kk_std_core_types__list dirs_1, kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun632__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun632__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun632, kk_context());
  _self->dirs_1 = dirs_1;
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun632(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun632__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun632__t*, _fself, _ctx);
  kk_std_core_types__list dirs_1 = _self->dirs_1; /* list<std/os/path/path> */
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__list_dup(dirs_1, _ctx);kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_1_333 = kk_Unit;
  kk_unit_unbox(_b_x303);
  kk_unit_t _x_x633 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10089(dirs_1, to_3, wild___0_1_333, _ctx);
  return kk_unit_box(_x_x633);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun634__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_3;
};
static kk_unit_t kk_std_os_dir_copy_directory_fun634(kk_function_t _fself, kk_box_t _b_x320, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun634(kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun634__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun634__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun634, kk_context());
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_os_dir_copy_directory_fun636__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun636(kk_function_t _fself, kk_box_t _b_x309, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun636(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun636, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun636(kk_function_t _fself, kk_box_t _b_x309, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _b_x304_305;
  kk_std_core_types__list _x_x637;
  kk_std_os_path__path _match_x361;
  kk_box_t _x_x638 = kk_box_dup(_b_x309, _ctx); /*9903*/
  _match_x361 = kk_std_os_path__path_unbox(_x_x638, KK_OWNED, _ctx); /*std/os/path/path*/
  {
    kk_std_core_types__list _x_1_0_0 = _match_x361.parts;
    kk_std_core_types__list_dup(_x_1_0_0, _ctx);
    kk_std_os_path__path_drop(_match_x361, _ctx);
    _x_x637 = _x_1_0_0; /*list<string>*/
  }
  _b_x304_305 = kk_std_core_list_take(_x_x637, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_std_os_path__path _x_x639;
  kk_string_t _x_x640 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x642;
  kk_std_core_types__optional _match_x359 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x304_305, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x359, _ctx)) {
    kk_box_t _box_x306 = _match_x359._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136_0_0 = kk_std_core_types__list_unbox(_box_x306, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136_0_0, _ctx);
    kk_std_core_types__optional_drop(_match_x359, _ctx);
    kk_box_drop(_b_x309, _ctx);
    _x_x642 = _uniq_parts_136_0_0; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x359, _ctx);
    kk_std_os_path__path _match_x360 = kk_std_os_path__path_unbox(_b_x309, KK_OWNED, _ctx); /*std/os/path/path*/;
    {
      kk_std_core_types__list _x_0_0_0 = _match_x360.parts;
      kk_std_core_types__list_dup(_x_0_0_0, _ctx);
      kk_std_os_path__path_drop(_match_x360, _ctx);
      _x_x642 = _x_0_0_0; /*list<string>*/
    }
  }
  _x_x639 = kk_std_os_path__new_Path(_x_x640, _x_x642, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x639, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun647__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_directory_fun647(kk_function_t _fself, kk_box_t _b_x316, kk_box_t _b_x317, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun647(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_directory_fun647, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun647(kk_function_t _fself, kk_box_t _b_x316, kk_box_t _b_x317, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x648;
  kk_std_os_path__path _x_x649 = kk_std_os_path__path_unbox(_b_x316, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x650 = kk_std_os_path__path_unbox(_b_x317, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x648 = kk_std_os_path__lp__fs__rp_(_x_x649, _x_x650, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x648, _ctx);
}
static kk_unit_t kk_std_os_dir_copy_directory_fun634(kk_function_t _fself, kk_box_t _b_x320, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun634__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun634__t*, _fself, _ctx);
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_std_os_path__path _x_x2_0_10081_0;
  kk_box_t _x_x635;
  kk_box_t _x_x643 = kk_box_dup(_b_x320, _ctx); /*3031*/
  _x_x635 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_directory_fun636(_ctx), _x_x643, _ctx); /*9904*/
  _x_x2_0_10081_0 = kk_std_os_path__path_unbox(_x_x635, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x644 = kk_std_os_path__path_unbox(_b_x320, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x645;
  kk_box_t _x_x646 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_directory_fun647(_ctx), kk_std_os_path__path_box(to_3, _ctx), kk_std_os_path__path_box(_x_x2_0_10081_0, _ctx), _ctx); /*9985*/
  _x_x645 = kk_std_os_path__path_unbox(_x_x646, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_dir_copy_directory(_x_x644, _x_x645, _ctx); return kk_Unit;
}

kk_unit_t kk_std_os_dir_copy_directory(kk_std_os_path__path dir_0, kk_std_os_path__path to_3, kk_context_t* _ctx) { /* (dir : std/os/path/path, to : std/os/path/path) -> <pure,fsys> () */ 
  kk_unit_t x_2_10121 = kk_Unit;
  kk_std_os_path__path _x_x598 = kk_std_os_path__path_dup(to_3, _ctx); /*std/os/path/path*/
  kk_std_os_dir_ensure_dir(_x_x598, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x599 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun600(dir_0, to_3, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x599); return kk_Unit;
  }
  {
    kk_std_core_types__list x_3_10124 = kk_std_os_dir_list_directory(dir_0, _ctx); /*list<std/os/path/path>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_3_10124, _ctx);
      kk_box_t _x_x602 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun603(to_3, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x602); return kk_Unit;
    }
    {
      kk_std_core_types__tuple2 x_4_10127;
      kk_function_t _brw_x365 = kk_std_os_dir_new_copy_directory_fun605(_ctx); /*(2758) -> 2759 bool*/;
      kk_std_core_types__tuple2 _brw_x366 = kk_std_core_list_partition(x_3_10124, _brw_x365, _ctx); /*(list<2758>, list<2758>)*/;
      kk_function_drop(_brw_x365, _ctx);
      x_4_10127 = _brw_x366; /*(list<std/os/path/path>, list<std/os/path/path>)*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__tuple2_drop(x_4_10127, _ctx);
        kk_box_t _x_x610 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun611(to_3, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x610); return kk_Unit;
      }
      {
        kk_box_t _box_x277 = x_4_10127.fst;
        kk_box_t _box_x278 = x_4_10127.snd;
        kk_std_core_types__list dirs_1 = kk_std_core_types__list_unbox(_box_x277, KK_BORROWED, _ctx);
        kk_std_core_types__list files_0 = kk_std_core_types__list_unbox(_box_x278, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(dirs_1, _ctx);
        kk_std_core_types__list_dup(files_0, _ctx);
        kk_std_core_types__tuple2_drop(x_4_10127, _ctx);
        kk_unit_t x_5_10130 = kk_Unit;
        kk_function_t _x_x613;
        kk_std_os_path__path_dup(to_3, _ctx);
        _x_x613 = kk_std_os_dir_new_copy_directory_fun614(to_3, _ctx); /*(3031) -> 3032 ()*/
        kk_std_core_list_foreach(files_0, _x_x613, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x631 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun632(dirs_1, to_3, _ctx), _ctx); /*2419*/
          kk_unit_unbox(_x_x631); return kk_Unit;
        }
        {
          kk_std_core_list_foreach(dirs_1, kk_std_os_dir_new_copy_directory_fun634(to_3, _ctx), _ctx); return kk_Unit;
        }
      }
    }
  }
}
 
// Copy a file to a directory


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun652__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun652(kk_function_t _fself, kk_box_t _b_x340, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun652(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun652, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun652(kk_function_t _fself, kk_box_t _b_x340, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _b_x335_336;
  kk_std_core_types__list _x_x653;
  kk_std_os_path__path _match_x354;
  kk_box_t _x_x654 = kk_box_dup(_b_x340, _ctx); /*9903*/
  _match_x354 = kk_std_os_path__path_unbox(_x_x654, KK_OWNED, _ctx); /*std/os/path/path*/
  {
    kk_std_core_types__list _x_1 = _match_x354.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    kk_std_os_path__path_drop(_match_x354, _ctx);
    _x_x653 = _x_1; /*list<string>*/
  }
  _b_x335_336 = kk_std_core_list_take(_x_x653, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_std_os_path__path _x_x655;
  kk_string_t _x_x656 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x658;
  kk_std_core_types__optional _match_x352 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x335_336, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x352, _ctx)) {
    kk_box_t _box_x337 = _match_x352._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136 = kk_std_core_types__list_unbox(_box_x337, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136, _ctx);
    kk_std_core_types__optional_drop(_match_x352, _ctx);
    kk_box_drop(_b_x340, _ctx);
    _x_x658 = _uniq_parts_136; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x352, _ctx);
    kk_std_os_path__path _match_x353 = kk_std_os_path__path_unbox(_b_x340, KK_OWNED, _ctx); /*std/os/path/path*/;
    {
      kk_std_core_types__list _x_0 = _match_x353.parts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      kk_std_os_path__path_drop(_match_x353, _ctx);
      _x_x658 = _x_0; /*list<string>*/
    }
  }
  _x_x655 = kk_std_os_path__new_Path(_x_x656, _x_x658, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x655, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_to_dir_fun663__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_to_dir_fun663(kk_function_t _fself, kk_box_t _b_x347, kk_box_t _b_x348, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_to_dir_fun663(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_to_dir_fun663, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_to_dir_fun663(kk_function_t _fself, kk_box_t _b_x347, kk_box_t _b_x348, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x664;
  kk_std_os_path__path _x_x665 = kk_std_os_path__path_unbox(_b_x347, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x666 = kk_std_os_path__path_unbox(_b_x348, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x664 = kk_std_os_path__lp__fs__rp_(_x_x665, _x_x666, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x664, _ctx);
}

kk_unit_t kk_std_os_dir_copy_file_to_dir(kk_std_os_path__path from, kk_std_os_path__path dir, kk_context_t* _ctx) { /* (from : std/os/path/path, dir : std/os/path/path) -> <exn,fsys> () */ 
  kk_std_os_path__path _x_x2_10084;
  kk_box_t _x_x651;
  kk_box_t _x_x659;
  kk_std_os_path__path _x_x660 = kk_std_os_path__path_dup(from, _ctx); /*std/os/path/path*/
  _x_x659 = kk_std_os_path__path_box(_x_x660, _ctx); /*9903*/
  _x_x651 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_to_dir_fun652(_ctx), _x_x659, _ctx); /*9904*/
  _x_x2_10084 = kk_std_os_path__path_unbox(_x_x651, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_path__path _x_x661;
  kk_box_t _x_x662 = kk_std_core_hnd__open_none2(kk_std_os_dir_new_copy_file_to_dir_fun663(_ctx), kk_std_os_path__path_box(dir, _ctx), kk_std_os_path__path_box(_x_x2_10084, _ctx), _ctx); /*9985*/
  _x_x661 = kk_std_os_path__path_unbox(_x_x662, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_std_os_dir_copy_file(from, _x_x661, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}

bool kk_std_os_dir_prim_is_file(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fsys bool */ 
  return kk_os_is_file(path,kk_context());
}

// initialization
void kk_std_os_dir__init(kk_context_t* _ctx){
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
  kk_std_os_path__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_os_dir__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_os_path__done(_ctx);
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
