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

kk_std_core_types__list kk_std_time_locale__trmc_lift_create_Time_locale_10404(kk_std_core_types__list _uniq_xs_10233, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10404(kk_std_core_types__list _uniq_xs_10233_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10403(kk_std_core_types__list _uniq_xs_10228, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_create_Time_locale_10406(kk_std_core_types__list _uniq_xs_10246, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10406(kk_std_core_types__list _uniq_xs_10246_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10405(kk_std_core_types__list _uniq_xs_10241, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_create_Time_locale_10408(kk_std_core_types__list _uniq_xs_10259, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10408(kk_std_core_types__list _uniq_xs_10259_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_create_Time_locale_10407(kk_std_core_types__list _uniq_xs_10254, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 
 
// The `:time-locale` describes time and date formats for a specific locale.

static inline kk_std_time_locale__time_locale kk_std_time_locale__create_Time_locale(kk_string_t lang_name, kk_std_core_types__list day_names, kk_std_core_types__list month_names, kk_std_core_types__optional month_names_short, kk_std_core_types__optional day_names_short, kk_std_core_types__optional day_names_min, kk_std_core_types__optional format_t, kk_std_core_types__optional format_tt, kk_std_core_types__optional format_l, kk_std_core_types__optional format_ll, kk_std_core_types__optional format_lll, kk_std_core_types__optional format_llll, kk_context_t* _ctx) { /* (lang-name : string, day-names : list<string>, month-names : list<string>, month-names-short : ? (list<string>), day-names-short : ? (list<string>), day-names-min : ? (list<string>), format-t : ? string, format-tt : ? string, format-l : ? string, format-ll : ? string, format-lll : ? string, format-llll : ? string) -> time-locale */ 
  kk_std_core_types__list _uniq_month_names_short_92;
  if (kk_std_core_types__is_Optional(month_names_short, _ctx)) {
    kk_box_t _box_x75 = month_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x75, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    kk_std_core_types__list _x_x1265 = kk_std_core_types__list_dup(month_names, _ctx); /*list<string>*/
    _uniq_month_names_short_92 = kk_std_time_locale__lift_create_Time_locale_10403(_x_x1265, _ctx); /*list<string>*/
  }
  kk_std_core_types__list _uniq_day_names_short_153;
  if (kk_std_core_types__is_Optional(day_names_short, _ctx)) {
    kk_box_t _box_x76 = day_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x76, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    kk_std_core_types__list _x_x1266 = kk_std_core_types__list_dup(day_names, _ctx); /*list<string>*/
    _uniq_day_names_short_153 = kk_std_time_locale__lift_create_Time_locale_10405(_x_x1266, _ctx); /*list<string>*/
  }
  kk_std_core_types__list _uniq_day_names_min_214;
  if (kk_std_core_types__is_Optional(day_names_min, _ctx)) {
    kk_box_t _box_x77 = day_names_min._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x77, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    kk_std_core_types__list _x_x1267 = kk_std_core_types__list_dup(day_names, _ctx); /*list<string>*/
    _uniq_day_names_min_214 = kk_std_time_locale__lift_create_Time_locale_10407(_x_x1267, _ctx); /*list<string>*/
  }
  kk_string_t _x_x1268;
  if (kk_std_core_types__is_Optional(format_t, _ctx)) {
    kk_box_t _box_x78 = format_t._cons._Optional.value;
    kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x78);
    kk_string_dup(_uniq_format_t_219, _ctx);
    kk_std_core_types__optional_drop(format_t, _ctx);
    _x_x1268 = _uniq_format_t_219; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_t, _ctx);
    kk_define_string_literal(, _s_x1269, 5, "HH:mm", _ctx)
    _x_x1268 = kk_string_dup(_s_x1269, _ctx); /*string*/
  }
  kk_string_t _x_x1270;
  if (kk_std_core_types__is_Optional(format_tt, _ctx)) {
    kk_box_t _box_x79 = format_tt._cons._Optional.value;
    kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x79);
    kk_string_dup(_uniq_format_tt_223, _ctx);
    kk_std_core_types__optional_drop(format_tt, _ctx);
    _x_x1270 = _uniq_format_tt_223; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_tt, _ctx);
    kk_define_string_literal(, _s_x1271, 8, "HH:mm:ss", _ctx)
    _x_x1270 = kk_string_dup(_s_x1271, _ctx); /*string*/
  }
  kk_string_t _x_x1272;
  if (kk_std_core_types__is_Optional(format_l, _ctx)) {
    kk_box_t _box_x80 = format_l._cons._Optional.value;
    kk_string_t _uniq_format_l_227 = kk_string_unbox(_box_x80);
    kk_string_dup(_uniq_format_l_227, _ctx);
    kk_std_core_types__optional_drop(format_l, _ctx);
    _x_x1272 = _uniq_format_l_227; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_l, _ctx);
    kk_define_string_literal(, _s_x1273, 10, "YYYY-MM-DD", _ctx)
    _x_x1272 = kk_string_dup(_s_x1273, _ctx); /*string*/
  }
  kk_string_t _x_x1274;
  if (kk_std_core_types__is_Optional(format_ll, _ctx)) {
    kk_box_t _box_x81 = format_ll._cons._Optional.value;
    kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x81);
    kk_string_dup(_uniq_format_ll_231, _ctx);
    kk_std_core_types__optional_drop(format_ll, _ctx);
    _x_x1274 = _uniq_format_ll_231; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_ll, _ctx);
    kk_define_string_literal(, _s_x1275, 11, "D MMMM YYYY", _ctx)
    _x_x1274 = kk_string_dup(_s_x1275, _ctx); /*string*/
  }
  kk_string_t _x_x1276;
  if (kk_std_core_types__is_Optional(format_lll, _ctx)) {
    kk_box_t _box_x82 = format_lll._cons._Optional.value;
    kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x82);
    kk_string_dup(_uniq_format_lll_235, _ctx);
    kk_std_core_types__optional_drop(format_lll, _ctx);
    _x_x1276 = _uniq_format_lll_235; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_lll, _ctx);
    kk_define_string_literal(, _s_x1277, 13, "D MMMM YYYY t", _ctx)
    _x_x1276 = kk_string_dup(_s_x1277, _ctx); /*string*/
  }
  kk_string_t _x_x1278;
  if (kk_std_core_types__is_Optional(format_llll, _ctx)) {
    kk_box_t _box_x83 = format_llll._cons._Optional.value;
    kk_string_t _uniq_format_llll_239 = kk_string_unbox(_box_x83);
    kk_string_dup(_uniq_format_llll_239, _ctx);
    kk_std_core_types__optional_drop(format_llll, _ctx);
    _x_x1278 = _uniq_format_llll_239; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_llll, _ctx);
    kk_define_string_literal(, _s_x1279, 18, "dddd D MMMM YYYY t", _ctx)
    _x_x1278 = kk_string_dup(_s_x1279, _ctx); /*string*/
  }
  return kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, lang_name, day_names, month_names, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1268, _x_x1270, _x_x1272, _x_x1274, _x_x1276, _x_x1278, _ctx);
}
 
// Automatically generated. Retrieves the `lang-name` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_lang_name(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1280 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1280->lang_name;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day-names` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_day_names(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1281 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x1281->day_names;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `month-names` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_month_names(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1282 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x1282->month_names;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `month-names-short` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_month_names_short(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1283 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x1283->month_names_short;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day-names-short` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_day_names_short(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1284 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x1284->day_names_short;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `day-names-min` constructor field of the `:time-locale` type.

static inline kk_std_core_types__list kk_std_time_locale_time_locale_fs_day_names_min(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> list<string> */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1285 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_std_core_types__list _x = _con_x1285->day_names_min;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-t` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_t(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1286 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1286->format_t;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-tt` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_tt(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1287 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1287->format_tt;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-l` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_l(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1288 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1288->format_l;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-ll` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_ll(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1289 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1289->format_ll;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-lll` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_lll(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1290 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1290->format_lll;
    return kk_string_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `format-llll` constructor field of the `:time-locale` type.

static inline kk_string_t kk_std_time_locale_time_locale_fs_format_llll(kk_std_time_locale__time_locale _this, kk_context_t* _ctx) { /* (time-locale) -> string */ 
  {
    struct kk_std_time_locale_Time_locale* _con_x1291 = kk_std_time_locale__as_Time_locale(_this, _ctx);
    kk_string_t _x = _con_x1291->format_llll;
    return kk_string_dup(_x, _ctx);
  }
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fs__copy(kk_std_time_locale__time_locale _this, kk_std_core_types__optional lang_name, kk_std_core_types__optional day_names, kk_std_core_types__optional month_names, kk_std_core_types__optional month_names_short, kk_std_core_types__optional day_names_short, kk_std_core_types__optional day_names_min, kk_std_core_types__optional format_t, kk_std_core_types__optional format_tt, kk_std_core_types__optional format_l, kk_std_core_types__optional format_ll, kk_std_core_types__optional format_lll, kk_std_core_types__optional format_llll, kk_context_t* _ctx); /* (time-locale, lang-name : ? string, day-names : ? (list<string>), month-names : ? (list<string>), month-names-short : ? (list<string>), day-names-short : ? (list<string>), day-names-min : ? (list<string>), format-t : ? string, format-tt : ? string, format-l : ? string, format-ll : ? string, format-lll : ? string, format-llll : ? string) -> time-locale */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_10410(kk_std_core_types__list _uniq_xs_10272, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10410(kk_std_core_types__list _uniq_xs_10272_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10409(kk_std_core_types__list _uniq_xs_10267, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_10412(kk_std_core_types__list _uniq_xs_10285, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10412(kk_std_core_types__list _uniq_xs_10285_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10411(kk_std_core_types__list _uniq_xs_10280, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_10414(kk_std_core_types__list _uniq_xs_10298, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10414(kk_std_core_types__list _uniq_xs_10298_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_10413(kk_std_core_types__list _uniq_xs_10293, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en;

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_iso_10416(kk_std_core_types__list _uniq_xs_10311, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10416(kk_std_core_types__list _uniq_xs_10311_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10415(kk_std_core_types__list _uniq_xs_10306, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_iso_10418(kk_std_core_types__list _uniq_xs_10324, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10418(kk_std_core_types__list _uniq_xs_10324_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10417(kk_std_core_types__list _uniq_xs_10319, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_en_iso_10420(kk_std_core_types__list _uniq_xs_10337, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10420(kk_std_core_types__list _uniq_xs_10337_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_en_iso_10419(kk_std_core_types__list _uniq_xs_10332, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en_iso;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fr;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_de;

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_es_10422(kk_std_core_types__list _uniq_xs_10350, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10422(kk_std_core_types__list _uniq_xs_10350_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10421(kk_std_core_types__list _uniq_xs_10345, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_es_10424(kk_std_core_types__list _uniq_xs_10363, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10424(kk_std_core_types__list _uniq_xs_10363_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10423(kk_std_core_types__list _uniq_xs_10358, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__trmc_lift_time_locale_es_10426(kk_std_core_types__list _uniq_xs_10376, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10426(kk_std_core_types__list _uniq_xs_10376_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_std_time_locale__lift_time_locale_es_10425(kk_std_core_types__list _uniq_xs_10371, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_es;

extern kk_std_time_locale__time_locale kk_std_time_locale_time_locale_nl;

extern kk_std_core_types__list kk_std_time_locale_locales;

kk_std_core_types__maybe kk_std_time_locale__lift_get_time_locale_10428(kk_string_t locale, kk_std_core_types__list _uniq_xs_10393, kk_context_t* _ctx); /* (locale : string, list<time-locale>) -> maybe<time-locale> */ 

kk_std_core_types__maybe kk_std_time_locale__lift_get_time_locale_10427(kk_string_t locale, kk_std_core_types__list _uniq_xs_10384, kk_context_t* _ctx); /* (locale : string, list<time-locale>) -> maybe<time-locale> */ 

kk_std_time_locale__time_locale kk_std_time_locale_get_time_locale(kk_string_t locale, kk_context_t* _ctx); /* (locale : string) -> time-locale */ 

void kk_std_time_locale__init(kk_context_t* _ctx);


void kk_std_time_locale__done(kk_context_t* _ctx);

#endif // header
