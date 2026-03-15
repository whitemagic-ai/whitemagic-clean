#pragma once
#ifndef kk_std_time_locale_H
#define kk_std_time_locale_H
// Koka generated module: std/time/locale, koka version: 3.2.2, platform: 64-bit
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

// type declarations

// type std/time/locale/time-locale
struct kk_std_time_locale__time_locale_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_std_time_locale__time_locale;
struct kk_std_time_locale_Time_locale {
  struct kk_std_time_locale__time_locale_s _base;
  kk_string_t lang_name;
  kk_std_core_types__list day_names;
  kk_std_core_types__list month_names;
  kk_std_core_types__list month_names_short;
  kk_std_core_types__list day_names_short;
  kk_std_core_types__list day_names_min;
  kk_string_t format_t;
  kk_string_t format_tt;
  kk_string_t format_l;
  kk_string_t format_ll;
  kk_string_t format_lll;
  kk_string_t format_llll;
};
static inline kk_std_time_locale__time_locale kk_std_time_locale__base_Time_locale(struct kk_std_time_locale_Time_locale* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_time_locale__time_locale kk_std_time_locale__new_Time_locale(kk_reuse_t _at, int32_t _cpath, kk_string_t lang_name, kk_std_core_types__list day_names, kk_std_core_types__list month_names, kk_std_core_types__list month_names_short, kk_std_core_types__list day_names_short, kk_std_core_types__list day_names_min, kk_string_t format_t, kk_string_t format_tt, kk_string_t format_l, kk_string_t format_ll, kk_string_t format_lll, kk_string_t format_llll, kk_context_t* _ctx) {
  struct kk_std_time_locale_Time_locale* _con = kk_block_alloc_at_as(struct kk_std_time_locale_Time_locale, _at, 12 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->lang_name = lang_name;
  _con->day_names = day_names;
  _con->month_names = month_names;
  _con->month_names_short = month_names_short;
  _con->day_names_short = day_names_short;
  _con->day_names_min = day_names_min;
  _con->format_t = format_t;
  _con->format_tt = format_tt;
  _con->format_l = format_l;
  _con->format_ll = format_ll;
  _con->format_lll = format_lll;
  _con->format_llll = format_llll;
  return kk_std_time_locale__base_Time_locale(_con, _ctx);
}
static inline struct kk_std_time_locale_Time_locale* kk_std_time_locale__as_Time_locale(kk_std_time_locale__time_locale x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_time_locale_Time_locale*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_std_time_locale__is_Time_locale(kk_std_time_locale__time_locale x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_time_locale__time_locale kk_std_time_locale__time_locale_dup(kk_std_time_locale__time_locale _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_std_time_locale__time_locale_drop(kk_std_time_locale__time_locale _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_std_time_locale__time_locale_box(kk_std_time_locale__time_locale _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_std_time_locale__time_locale kk_std_time_locale__time_locale_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// The `:time-locale` describes time and date formats for a specific locale.


// lift anonymous function
struct kk_std_time_locale__create_Time_locale_fun923__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_locale__create_Time_locale_fun923(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_locale__new_create_Time_locale_fun923(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale__create_Time_locale_fun923, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_locale__create_Time_locale_fun929__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_locale__create_Time_locale_fun929(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_locale__new_create_Time_locale_fun929(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale__create_Time_locale_fun929, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_locale__create_Time_locale_fun935__t {
  struct kk_function_s _base;
};
extern kk_box_t kk_std_time_locale__create_Time_locale_fun935(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx);
static inline kk_function_t kk_std_time_locale__new_create_Time_locale_fun935(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale__create_Time_locale_fun935, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}


static inline kk_std_time_locale__time_locale kk_std_time_locale__create_Time_locale(kk_string_t lang_name, kk_std_core_types__list day_names, kk_std_core_types__list month_names, kk_std_core_types__optional month_names_short, kk_std_core_types__optional day_names_short, kk_std_core_types__optional day_names_min, kk_std_core_types__optional format_t, kk_std_core_types__optional format_tt, kk_std_core_types__optional format_l, kk_std_core_types__optional format_ll, kk_std_core_types__optional format_lll, kk_std_core_types__optional format_llll, kk_context_t* _ctx) { /* (lang-name : string, day-names : list<string>, month-names : list<string>, month-names-short : ? (list<string>), day-names-short : ? (list<string>), day-names-min : ? (list<string>), format-t : ? string, format-tt : ? string, format-l : ? string, format-ll : ? string, format-lll : ? string, format-llll : ? string) -> time-locale */ 
  kk_std_core_types__list _uniq_month_names_short_92;
  if (kk_std_core_types__is_Optional(month_names_short, _ctx)) {
    kk_box_t _box_x0 = month_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    kk_function_t _brw_x918 = kk_std_time_locale__new_create_Time_locale_fun923(_ctx); /*(2217) -> 2219 2218*/;
    kk_std_core_types__list _brw_x919;
    kk_std_core_types__list _x_x928 = kk_std_core_types__list_dup(month_names, _ctx); /*list<string>*/
    _brw_x919 = kk_std_core_list_map(_x_x928, _brw_x918, _ctx); /*list<2218>*/
    kk_function_drop(_brw_x918, _ctx);
    _uniq_month_names_short_92 = _brw_x919; /*list<string>*/
  }
  kk_std_core_types__list _uniq_day_names_short_153;
  if (kk_std_core_types__is_Optional(day_names_short, _ctx)) {
    kk_box_t _box_x9 = day_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    kk_function_t _brw_x916 = kk_std_time_locale__new_create_Time_locale_fun929(_ctx); /*(2217) -> 2219 2218*/;
    kk_std_core_types__list _brw_x917;
    kk_std_core_types__list _x_x934 = kk_std_core_types__list_dup(day_names, _ctx); /*list<string>*/
    _brw_x917 = kk_std_core_list_map(_x_x934, _brw_x916, _ctx); /*list<2218>*/
    kk_function_drop(_brw_x916, _ctx);
    _uniq_day_names_short_153 = _brw_x917; /*list<string>*/
  }
  kk_std_core_types__list _uniq_day_names_min_214;
  if (kk_std_core_types__is_Optional(day_names_min, _ctx)) {
    kk_box_t _box_x18 = day_names_min._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    kk_function_t _brw_x914 = kk_std_time_locale__new_create_Time_locale_fun935(_ctx); /*(2217) -> 2219 2218*/;
    kk_std_core_types__list _brw_x915;
    kk_std_core_types__list _x_x940 = kk_std_core_types__list_dup(day_names, _ctx); /*list<string>*/
    _brw_x915 = kk_std_core_list_map(_x_x940, _brw_x914, _ctx); /*list<2218>*/
    kk_function_drop(_brw_x914, _ctx);
    _uniq_day_names_min_214 = _brw_x915; /*list<string>*/
  }
  kk_string_t _x_x941;
  if (kk_std_core_types__is_Optional(format_t, _ctx)) {
    kk_box_t _box_x27 = format_t._cons._Optional.value;
    kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x27);
    kk_string_dup(_uniq_format_t_219, _ctx);
    kk_std_core_types__optional_drop(format_t, _ctx);
    _x_x941 = _uniq_format_t_219; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_t, _ctx);
    kk_define_string_literal(, _s_x942, 5, "HH:mm", _ctx)
    _x_x941 = kk_string_dup(_s_x942, _ctx); /*string*/
  }
  kk_string_t _x_x943;
  if (kk_std_core_types__is_Optional(format_tt, _ctx)) {
    kk_box_t _box_x28 = format_tt._cons._Optional.value;
    kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x28);
    kk_string_dup(_uniq_format_tt_223, _ctx);
    kk_std_core_types__optional_drop(format_tt, _ctx);
    _x_x943 = _uniq_format_tt_223; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_tt, _ctx);
    kk_define_string_literal(, _s_x944, 8, "HH:mm:ss", _ctx)
    _x_x943 = kk_string_dup(_s_x944, _ctx); /*string*/
  }
  kk_string_t _x_x945;
  if (kk_std_core_types__is_Optional(format_l, _ctx)) {
    kk_box_t _box_x29 = format_l._cons._Optional.value;
    kk_string_t _uniq_format_l_227 = kk_string_unbox(_box_x29);
    kk_string_dup(_uniq_format_l_227, _ctx);
    kk_std_core_types__optional_drop(format_l, _ctx);
    _x_x945 = _uniq_format_l_227; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_l, _ctx);
    kk_define_string_literal(, _s_x946, 10, "YYYY-MM-DD", _ctx)
    _x_x945 = kk_string_dup(_s_x946, _ctx); /*string*/
  }
  kk_string_t _x_x947;
  if (kk_std_core_types__is_Optional(format_ll, _ctx)) {
    kk_box_t _box_x30 = format_ll._cons._Optional.value;
    kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x30);
    kk_string_dup(_uniq_format_ll_231, _ctx);
    kk_std_core_types__optional_drop(format_ll, _ctx);
    _x_x947 = _uniq_format_ll_231; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_ll, _ctx);
    kk_define_string_literal(, _s_x948, 11, "D MMMM YYYY", _ctx)
    _x_x947 = kk_string_dup(_s_x948, _ctx); /*string*/
  }
  kk_string_t _x_x949;
  if (kk_std_core_types__is_Optional(format_lll, _ctx)) {
    kk_box_t _box_x31 = format_lll._cons._Optional.value;
    kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x31);
    kk_string_dup(_uniq_format_lll_235, _ctx);
    kk_std_core_types__optional_drop(format_lll, _ctx);
    _x_x949 = _uniq_format_lll_235; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_lll, _ctx);
    kk_define_string_literal(, _s_x950, 13, "D MMMM YYYY t", _ctx)
    _x_x949 = kk_string_dup(_s_x950, _ctx); /*string*/
  }
  kk_string_t _x_x951;
  if (kk_std_core_types__is_Optional(format_llll, _ctx)) {
    kk_box_t _box_x32 = format_llll._cons._Optional.value;
    kk_string_t _uniq_format_llll_239 = kk_string_unbox(_box_x32);
    kk_string_dup(_uniq_format_llll_239, _ctx);
    kk_std_core_types__optional_drop(format_llll, _ctx);
    _x_x951 = _uniq_format_llll_239; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_llll, _ctx);
    kk_define_string_literal(, _s_x952, 18, "dddd D MMMM YYYY t", _ctx)
    _x_x951 = kk_string_dup(_s_x952, _ctx); /*string*/
  }
  return kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, lang_name, day_names, month_names, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x941, _x_x943, _x_x945, _x_x947, _x_x949, _x_x951, _ctx);
}
 
// Automatically generated. Retrieves the `lang-name` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_lang_name(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x953 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x953->lang_name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day-names` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_day_names(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x954 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x954->day_names;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `month-names` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_month_names(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x955 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x955->month_names;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `month-names-short` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_month_names_short(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x956 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x956->month_names_short;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day-names-short` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_day_names_short(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x957 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x957->day_names_short;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day-names-min` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_day_names_min(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x958 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x958->day_names_min;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-t` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_t(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x959 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x959->format_t;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-tt` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_tt(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x960 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x960->format_tt;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-l` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_l(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x961 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x961->format_l;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-ll` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_ll(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x962 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x962->format_ll;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-lll` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_lll(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x963 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x963->format_lll;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-llll` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_llll(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x964 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x964->format_llll;
    return kk_string_dup(_x, _ctx);
  }
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fs__copy(kk_std_time_locale__time_locale _this, kk_std_core_types__optional lang_name, kk_std_core_types__optional day_names, kk_std_core_types__optional month_names, kk_std_core_types__optional month_names_short, kk_std_core_types__optional day_names_short, kk_std_core_types__optional day_names_min, kk_std_core_types__optional format_t, kk_std_core_types__optional format_tt, kk_std_core_types__optional format_l, kk_std_core_types__optional format_ll, kk_std_core_types__optional format_lll, kk_std_core_types__optional format_llll, kk_context_t* _ctx); /* (time-locale, lang-name : ? string, day-names : ? (list<string>), month-names : ? (list<string>), month-names-short : ? (list<string>), day-names-short : ? (list<string>), day-names-min : ? (list<string>), format-t : ? string, format-tt : ? string, format-l : ? string, format-ll : ? string, format-lll : ? string, format-llll : ? string) -> time-locale */ 

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en_iso;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fr;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_de;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_es;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_nl;

extern kk_std_core_types__list kk_std_time_locale_locales;

kk_std_time_locale__time_locale kk_std_time_locale_get_time_locale(kk_string_t locale, kk_context_t* _ctx); /* (locale : string) -> time-locale */ 

void kk_std_time_locale__init(kk_context_t* _ctx);


void kk_std_time_locale__done(kk_context_t* _ctx);

#endif // header
