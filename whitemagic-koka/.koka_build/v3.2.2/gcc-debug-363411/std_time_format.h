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
 
// monadic lift

static inline kk_string_t kk_std_time_format__mlift_pquoted_10171(kk_char_t quote, kk_string_t s, kk_char_t wild___0, kk_context_t* _ctx) { /* (quote : char, s : string, wild_@0 : char) -> std/text/parse/parse string */ 
  kk_string_t _x_x1031 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  kk_string_t _x_x1032;
  kk_string_t _x_x1033 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  _x_x1032 = kk_std_core_types__lp__plus__plus__rp_(s, _x_x1033, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1031, _x_x1032, _ctx);
}

kk_string_t kk_std_time_format__mlift_pquoted_10172(kk_char_t quote, kk_string_t s, kk_context_t* _ctx); /* (quote : char, s : string) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_pquoted_10173(kk_char_t quote, kk_char_t wild__, kk_context_t* _ctx); /* (quote : char, wild_ : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_pquoted(kk_char_t quote, kk_context_t* _ctx); /* (quote : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_t_10174(kk_std_time_locale__time_locale locale, kk_char_t wild___0, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale, wild_@0 : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_t_10175(kk_std_time_locale__time_locale locale, kk_char_t wild__, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale, wild_ : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocale_t(kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_l_10176(kk_char_t l, kk_string_t _c_x10144, kk_context_t* _ctx); /* (l : char, string) -> string */ 

kk_string_t kk_std_time_format__mlift_plocale_l_10177(kk_char_t _y_x10139, kk_char_t l, kk_std_time_locale__time_locale locale, kk_std_core_types__list _y_x10141, kk_context_t* _ctx); /* (char, l : char, locale : std/time/locale/time-locale, list<char>) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format__mlift_plocale_l_10178(kk_char_t l, kk_std_time_locale__time_locale locale, kk_char_t _y_x10139, kk_context_t* _ctx); /* (l : char, locale : std/time/locale/time-locale, char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocale_l(kk_std_time_locale__time_locale locale, kk_char_t l, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale, l : char) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocale(kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 

kk_string_t kk_std_time_format_plocales(kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
 
// monadic lift

static inline kk_string_t kk_std_time_format__mlift_expand_locales_10179(kk_string_t x_1, kk_unit_t wild__, kk_context_t* _ctx) { /* (x@1 : string, wild_ : ()) -> std/text/parse/parse string */ 
  return x_1;
}

kk_string_t kk_std_time_format__mlift_expand_locales_10180(kk_std_core_types__list _y_x10156, kk_context_t* _ctx); /* (list<string>) -> std/text/parse/parse string */ 

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
  kk_string_t _x_x1467 = kk_std_time_format_format_ampm(t, n, locale, _ctx); /*string*/
  return kk_std_core_string_to_upper(_x_x1467, _ctx);
}

kk_string_t kk_std_time_format_format_frac(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_frac0(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_tz_offset(kk_std_time_time__time t, kk_integer_t n, kk_string_t hmsep, kk_string_t utc, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, hmsep : string, utc : string) -> string */ 

kk_string_t kk_std_time_format_format_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_utc_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format_timestamp(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 

extern kk_std_core_types__list kk_std_time_format_formats;

kk_std_core_types__tuple2 kk_std_time_format_format_pat(kk_std_time_time__time t, kk_char_t h, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, h : char, fmt : list<char>, locale : std/time/locale/time-locale) -> (string, list<char>) */ 

kk_string_t kk_std_time_format_format_list(kk_std_time_time__time t, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx); /* (t : std/time/time/time, fmt : list<char>, locale : std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_format(kk_std_time_time__time t, kk_string_t fmt, kk_std_core_types__optional locale, kk_context_t* _ctx); /* (t : std/time/time/time, fmt : string, locale : ? std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_show_iso_date(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : std/time/time/time) -> string */ 

kk_string_t kk_std_time_format_show_iso(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : std/time/time/time) -> string */ 

kk_string_t kk_std_time_format_show_imf(kk_std_time_time__time t, kk_context_t* _ctx); /* (t : std/time/time/time) -> string */ 

kk_string_t kk_std_time_format_show_in_locale(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx); /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 

kk_string_t kk_std_time_format_show_in_locale_date(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx); /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 

void kk_std_time_format__init(kk_context_t* _ctx);


void kk_std_time_format__done(kk_context_t* _ctx);

#endif // header
