#pragma once
#ifndef kk_std_time_format_H
#define kk_std_time_format_H
// Koka generated module: std/time/format, koka version: 3.2.2, platform: 64-bit
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
#include "std_core_undiv.h"
#include "std_text_parse.h"
#include "std_num_ddouble.h"
#include "std_time_timestamp.h"
#include "std_time_duration.h"
#include "std_time_instant.h"
#include "std_time_date.h"
#include "std_time_calendar.h"
#include "std_time_time.h"
#include "std_time_locale.h"
#include "std_num_float64.h"

// type declarations

// value declarations

kk_string_t kk_std_time_format_format_weekday(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_absyear(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_calname(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_ampm(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_pquoted_10525(kk_char_t quote, kk_std_core_sslice__sslice _uniq_slice_10375, kk_std_core_types__list _uniq_acc_10377, kk_context_t* _ctx); /* (quote : char, sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 

kk_std_core_types__list kk_std_time_format__mlift_lift_pquoted_10524_10625(kk_string_t _uniq_msg_10356, kk_std_core_types__maybe _y_x10554, kk_context_t* _ctx); /* (string, maybe<list<char>>) -> std/text/parse/parse list<char> */ 

kk_std_core_types__list kk_std_time_format__lift_pquoted_10524(kk_char_t quote, kk_string_t _uniq_msg_10356_0, kk_context_t* _ctx); /* (quote : char, string) -> std/text/parse/parse list<char> */ 
 
// monadic lift

static inline kk_string_t kk_std_time_format__mlift_pquoted_10626(kk_string_t _c_x10560, kk_char_t quote, kk_char_t wild___0, kk_context_t* _ctx) { /* (string, quote : char, wild_@0 : char) -> std/text/parse/parse string */ 
  kk_string_t _x_x1853 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  kk_string_t _x_x1854;
  kk_string_t _x_x1855 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  _x_x1854 = kk_std_core_types__lp__plus__plus__rp_(_c_x10560, _x_x1855, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1853, _x_x1854, _ctx);
}

kk_string_t kk_std_time_format__mlift_pquoted_10627(kk_char_t quote, kk_string_t _c_x10560, kk_context_t* _ctx); /* (quote : char, string) -> string */ 

kk_string_t kk_std_time_format__mlift_pquoted_10628(kk_char_t quote, bool _y_x10558, kk_context_t* _ctx); /* (quote : char, bool) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_pquoted_10629(kk_char_t quote, kk_char_t wild__, kk_context_t* _ctx); /* (quote : char, wild_ : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_pquoted(kk_char_t quote, kk_context_t* _ctx); /* (quote : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_t_10630(kk_std_time_locale__time_locale locale, kk_char_t wild___0, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale, wild_@0 : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_t_10631(kk_string_t default_10023, kk_std_time_locale__time_locale locale, bool _y_x10563, kk_context_t* _ctx); /* (default@10023 : string, locale : std/time/locale/time-locale, bool) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_t_10632(kk_std_time_locale__time_locale locale, kk_char_t wild__, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale, wild_ : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocale_t(kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_l_10633(kk_char_t l, kk_string_t _c_x10571, kk_context_t* _ctx); /* (l : char, string) -> string */ 

kk_string_t kk_std_time_format__mlift_plocale_l_10634(kk_char_t _y_x10566, kk_char_t l, kk_std_time_locale__time_locale locale, kk_std_core_types__list _y_x10568, kk_context_t* _ctx); /* (char, l : char, locale : std/time/locale/time-locale, list<char>) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_l_10635(kk_char_t l, kk_std_time_locale__time_locale locale, kk_char_t _y_x10566, kk_context_t* _ctx); /* (l : char, locale : std/time/locale/time-locale, char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocale_l(kk_std_time_locale__time_locale locale, kk_char_t l, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale, l : char) -> std/text/parse/parse string */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_plocale_10527(kk_std_core_sslice__sslice _uniq_slice_10406, kk_std_core_types__list _uniq_acc_10408, kk_context_t* _ctx); /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 

kk_std_core_types__list kk_std_time_format__mlift_lift_plocale_10526_10636(kk_string_t _uniq_msg_10387, kk_std_core_types__maybe _y_x10573, kk_context_t* _ctx); /* (string, maybe<list<char>>) -> std/text/parse/parse list<char> */ 

kk_std_core_types__list kk_std_time_format__lift_plocale_10526(kk_string_t _uniq_msg_10387_0, kk_context_t* _ctx); /* (string) -> std/text/parse/parse list<char> */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_plocale_10529(kk_std_core_sslice__sslice _uniq_slice_10437, kk_std_core_types__list _uniq_acc_10439, kk_context_t* _ctx); /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 

kk_std_core_types__list kk_std_time_format__mlift_lift_plocale_10528_10637(kk_string_t _uniq_msg_10418, kk_std_core_types__maybe _y_x10576, kk_context_t* _ctx); /* (string, maybe<list<char>>) -> std/text/parse/parse list<char> */ 

kk_std_core_types__list kk_std_time_format__lift_plocale_10528(kk_string_t _uniq_msg_10418_0, kk_context_t* _ctx); /* (string) -> std/text/parse/parse list<char> */ 
 
// monadic lift

static inline kk_string_t kk_std_time_format__mlift_plocale_10638(kk_string_t _c_x10583, kk_char_t wild___0, kk_context_t* _ctx) { /* (string, wild_@0 : char) -> std/text/parse/parse string */ 
  kk_string_t _x_x2087 = kk_std_core_string_char_fs_string('\'', _ctx); /*string*/
  kk_string_t _x_x2088;
  kk_string_t _x_x2089 = kk_std_core_string_char_fs_string('\'', _ctx); /*string*/
  _x_x2088 = kk_std_core_types__lp__plus__plus__rp_(_c_x10583, _x_x2089, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x2087, _x_x2088, _ctx);
}

kk_string_t kk_std_time_format__mlift_plocale_10639(kk_string_t _c_x10583, kk_context_t* _ctx); /* (string) -> string */ 

kk_string_t kk_std_time_format__mlift_plocale_10640(bool _y_x10581, kk_context_t* _ctx); /* (bool) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_10641(kk_char_t wild__, kk_context_t* _ctx); /* (wild_ : char) -> std/text/parse/parse string */ 
 
// monadic lift

static inline kk_string_t kk_std_time_format__mlift_plocale_10642(kk_string_t _c_x10588, kk_char_t wild___0_0, kk_context_t* _ctx) { /* (string, wild_@0@0 : char) -> std/text/parse/parse string */ 
  kk_string_t _x_x2132 = kk_std_core_string_char_fs_string('"', _ctx); /*string*/
  kk_string_t _x_x2133;
  kk_string_t _x_x2134 = kk_std_core_string_char_fs_string('"', _ctx); /*string*/
  _x_x2133 = kk_std_core_types__lp__plus__plus__rp_(_c_x10588, _x_x2134, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x2132, _x_x2133, _ctx);
}

kk_string_t kk_std_time_format__mlift_plocale_10643(kk_string_t _c_x10588, kk_context_t* _ctx); /* (string) -> string */ 

kk_string_t kk_std_time_format__mlift_plocale_10644(bool _y_x10586, kk_context_t* _ctx); /* (bool) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_10645(kk_char_t wild___1, kk_context_t* _ctx); /* (wild_@1 : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocale(kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocales_10646(kk_std_core_types__list _y_x10597, kk_context_t* _ctx); /* (list<string>) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocales(kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_expand_locales(kk_string_t fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (fmt : string, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_showl(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx); /* (i : int, width : ? int) -> string */ 

kk_string_t kk_std_time_format_format_day(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_month(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_year(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_era(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_seconds(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_minutes(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_hours(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_hours12(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

static inline kk_string_t kk_std_time_format_format_upper_ampm(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_string_t _x_x2440 = kk_std_time_format_format_ampm(t, n, locale, _ctx); /*string*/
  return kk_std_core_string_to_upper(_x_x2440, _ctx);
}

kk_string_t kk_std_time_format_format_frac(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_frac0(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_tz_offset(kk_std_time_time__time t, kk_integer_t n, kk_string_t hmsep, kk_string_t utc, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, hmsep : string, utc : string) -> string */ 

kk_string_t kk_std_time_format_format_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_utc_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_timestamp(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

extern kk_std_core_types__list kk_std_time_format_formats;

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10531(kk_char_t h, kk_std_core_types__list _uniq_ys_10456, kk_std_core_types__cctx _uniq_acc_10457, kk_context_t* _ctx); /* (h : char, list<char>, cctx<list<char>,list<char>>) -> (list<char>, list<char>) */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10530(kk_char_t h, kk_std_core_types__list _uniq_xs_10449, kk_context_t* _ctx); /* (h : char, list<char>) -> (list<char>, list<char>) */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10533(kk_char_t h, kk_std_core_types__list _uniq_ys_10476, kk_std_core_types__cctx _uniq_acc_10477, kk_context_t* _ctx); /* (h : char, list<char>, cctx<list<char>,list<char>>) -> (list<char>, list<char>) */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10532(kk_char_t h, kk_std_core_types__list _uniq_xs_10469, kk_context_t* _ctx); /* (h : char, list<char>) -> (list<char>, list<char>) */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10535(kk_char_t h, kk_std_core_types__list _uniq_ys_10496, kk_std_core_types__cctx _uniq_acc_10497, kk_context_t* _ctx); /* (h : char, list<char>, cctx<list<char>,list<char>>) -> (list<char>, list<char>) */ 

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10534(kk_char_t h, kk_std_core_types__list _uniq_xs_10489, kk_context_t* _ctx); /* (h : char, list<char>) -> (list<char>, list<char>) */ 

kk_std_core_types__maybe kk_std_time_format__lift_format_pat_10537(kk_char_t h, kk_std_time_locale__time_locale locale, kk_integer_t n, kk_std_core_types__list rest_0_0, kk_std_time_time__time t, kk_std_core_types__list _uniq_xs_10514, kk_context_t* _ctx); /* (h : char, locale : std/time/locale/time-locale, n : int, rest@0@0 : list<char>, t : std/time/time/time, list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>) -> maybe<(string, list<char>)> */ 

kk_std_core_types__maybe kk_std_time_format__lift_format_pat_10536(kk_char_t h, kk_std_time_locale__time_locale locale, kk_integer_t n, kk_std_core_types__list rest_0_0, kk_std_time_time__time t, kk_std_core_types__list _uniq_xs_10509, kk_context_t* _ctx); /* (h : char, locale : std/time/locale/time-locale, n : int, rest@0@0 : list<char>, t : std/time/time/time, list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>) -> maybe<(string, list<char>)> */ 

kk_std_core_types__tuple2 kk_std_time_format_format_pat(kk_std_time_time__time t, kk_char_t h, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, h : char, fmt : list<char>, locale : std/time/locale/time-locale) -> (string, list<char>) */ 

kk_string_t kk_std_time_format__unroll_format_list_10000(kk_std_time_time__time t, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, fmt : list<char>, locale : std/time/locale/time-locale) -> string */ 
 
// unrolling of singleton matches of std/time/format/@unroll-format-list@10000

static inline kk_string_t kk_std_time_format_format_list(kk_std_time_time__time t, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, fmt : list<char>, locale : std/time/locale/time-locale) -> string */ 
  if (kk_std_core_types__is_Nil(fmt, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_string_empty();
  }
  {
    return kk_std_time_format__unroll_format_list_10000(t, fmt, locale, _ctx);
  }
}

kk_string_t kk_std_time_format_format(kk_std_time_time__time t, kk_string_t fmt, kk_std_core_types__optional locale, kk_context_t* _ctx); /* (t : std/time/time/time, fmt : string, locale : ? std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_show_iso_date(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : std/time/time/time) -> string */ 

kk_string_t kk_std_time_format_show_iso(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : std/time/time/time) -> string */ 

kk_string_t kk_std_time_format_show_imf(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : std/time/time/time) -> string */ 

kk_string_t kk_std_time_format_show_in_locale(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx); /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_show_in_locale_date(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx); /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 

void kk_std_time_format__init(kk_context_t* _ctx);


void kk_std_time_format__done(kk_context_t* _ctx);

#endif // header
