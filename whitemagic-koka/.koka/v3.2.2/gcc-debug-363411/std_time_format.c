// Koka generated module: std/time/format, koka version: 3.2.2, platform: 64-bit
#include "std_time_format.h"
kk_declare_string_literal(static, kk_std_time_format_fmt_iso_date, 10, "YYYY-MM-DD")
kk_declare_string_literal(static, kk_std_time_format_fmt_iso_time, 17, "HH:mm:ssFFFFFFFFF")
kk_declare_string_literal(static, kk_std_time_format_fmt_iso_timezone, 3, "Z C")

kk_string_t kk_std_time_format_format_weekday(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_std_time_date__weekday wd = kk_std_time_time_weekday(t, _ctx); /*std/time/date/weekday*/;
  bool _match_x822 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  if (_match_x822) {
    kk_integer_drop(n, _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_std_time_date_weekday_fs_show(wd, _ctx);
  }
  {
    kk_std_core_types__list days;
    bool _match_x823 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
    if (_match_x823) {
      kk_integer_drop(n, _ctx);
      {
        struct kk_std_time_locale_Time_locale* _con_x989 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_0 = _con_x989->lang_name;
        kk_std_core_types__list _pat_1_0 = _con_x989->day_names;
        kk_std_core_types__list _pat_2_0 = _con_x989->month_names;
        kk_std_core_types__list _pat_3 = _con_x989->month_names_short;
        kk_std_core_types__list _pat_4 = _con_x989->day_names_short;
        kk_std_core_types__list _x = _con_x989->day_names_min;
        kk_string_t _pat_5 = _con_x989->format_t;
        kk_string_t _pat_6 = _con_x989->format_tt;
        kk_string_t _pat_7 = _con_x989->format_l;
        kk_string_t _pat_8 = _con_x989->format_ll;
        kk_string_t _pat_9 = _con_x989->format_lll;
        kk_string_t _pat_10 = _con_x989->format_llll;
        if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
          kk_string_drop(_pat_9, _ctx);
          kk_string_drop(_pat_8, _ctx);
          kk_string_drop(_pat_7, _ctx);
          kk_string_drop(_pat_6, _ctx);
          kk_string_drop(_pat_5, _ctx);
          kk_std_core_types__list_drop(_pat_4, _ctx);
          kk_std_core_types__list_drop(_pat_3, _ctx);
          kk_std_core_types__list_drop(_pat_2_0, _ctx);
          kk_std_core_types__list_drop(_pat_1_0, _ctx);
          kk_string_drop(_pat_10, _ctx);
          kk_string_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(locale, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x, _ctx);
          kk_datatype_ptr_decref(locale, _ctx);
        }
        days = _x; /*list<string>*/
      }
    }
    else {
      bool _match_x824;
      bool _brw_x825 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x824 = _brw_x825; /*bool*/
      if (_match_x824) {
        struct kk_std_time_locale_Time_locale* _con_x990 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_1 = _con_x990->lang_name;
        kk_std_core_types__list _pat_1_1 = _con_x990->day_names;
        kk_std_core_types__list _pat_2_2 = _con_x990->month_names;
        kk_std_core_types__list _pat_3_1 = _con_x990->month_names_short;
        kk_std_core_types__list _x_0 = _con_x990->day_names_short;
        kk_std_core_types__list _pat_4_0 = _con_x990->day_names_min;
        kk_string_t _pat_5_0 = _con_x990->format_t;
        kk_string_t _pat_6_0 = _con_x990->format_tt;
        kk_string_t _pat_7_0 = _con_x990->format_l;
        kk_string_t _pat_8_0 = _con_x990->format_ll;
        kk_string_t _pat_9_0 = _con_x990->format_lll;
        kk_string_t _pat_10_0 = _con_x990->format_llll;
        if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
          kk_string_drop(_pat_9_0, _ctx);
          kk_string_drop(_pat_8_0, _ctx);
          kk_string_drop(_pat_7_0, _ctx);
          kk_string_drop(_pat_6_0, _ctx);
          kk_string_drop(_pat_5_0, _ctx);
          kk_std_core_types__list_drop(_pat_4_0, _ctx);
          kk_std_core_types__list_drop(_pat_3_1, _ctx);
          kk_std_core_types__list_drop(_pat_2_2, _ctx);
          kk_std_core_types__list_drop(_pat_1_1, _ctx);
          kk_string_drop(_pat_10_0, _ctx);
          kk_string_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(locale, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(locale, _ctx);
        }
        days = _x_0; /*list<string>*/
      }
      else {
        struct kk_std_time_locale_Time_locale* _con_x991 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_2 = _con_x991->lang_name;
        kk_std_core_types__list _x_1 = _con_x991->day_names;
        kk_std_core_types__list _pat_1_2 = _con_x991->month_names;
        kk_std_core_types__list _pat_2_3 = _con_x991->month_names_short;
        kk_std_core_types__list _pat_3_2 = _con_x991->day_names_short;
        kk_std_core_types__list _pat_4_2 = _con_x991->day_names_min;
        kk_string_t _pat_5_1 = _con_x991->format_t;
        kk_string_t _pat_6_1 = _con_x991->format_tt;
        kk_string_t _pat_7_1 = _con_x991->format_l;
        kk_string_t _pat_8_1 = _con_x991->format_ll;
        kk_string_t _pat_9_1 = _con_x991->format_lll;
        kk_string_t _pat_10_1 = _con_x991->format_llll;
        if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
          kk_string_drop(_pat_9_1, _ctx);
          kk_string_drop(_pat_8_1, _ctx);
          kk_string_drop(_pat_7_1, _ctx);
          kk_string_drop(_pat_6_1, _ctx);
          kk_string_drop(_pat_5_1, _ctx);
          kk_std_core_types__list_drop(_pat_4_2, _ctx);
          kk_std_core_types__list_drop(_pat_3_2, _ctx);
          kk_std_core_types__list_drop(_pat_2_3, _ctx);
          kk_std_core_types__list_drop(_pat_1_2, _ctx);
          kk_string_drop(_pat_10_1, _ctx);
          kk_string_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(locale, _ctx);
        }
        else {
          kk_std_core_types__list_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(locale, _ctx);
        }
        days = _x_1; /*list<string>*/
      }
    }
    kk_integer_t x_0_10005 = kk_std_time_date_int(wd, _ctx); /*int*/;
    kk_std_core_types__maybe m_10003;
    kk_integer_t _x_x992 = kk_integer_add_small_const(x_0_10005, -1, _ctx); /*int*/
    m_10003 = kk_std_core_list__index(days, _x_x992, _ctx); /*maybe<string>*/
    kk_string_t nothing_10004;
    kk_string_t _x_x993;
    kk_define_string_literal(, _s_x994, 1, "D", _ctx)
    _x_x993 = kk_string_dup(_s_x994, _ctx); /*string*/
    kk_string_t _x_x995 = kk_std_time_date_weekday_fs_show(wd, _ctx); /*string*/
    nothing_10004 = kk_std_core_types__lp__plus__plus__rp_(_x_x993, _x_x995, _ctx); /*string*/
    if (kk_std_core_types__is_Nothing(m_10003, _ctx)) {
      return nothing_10004;
    }
    {
      kk_box_t _box_x0 = m_10003._cons.Just.value;
      kk_string_t x = kk_string_unbox(_box_x0);
      kk_string_drop(nothing_10004, _ctx);
      kk_string_dup(x, _ctx);
      kk_std_core_types__maybe_drop(m_10003, _ctx);
      return x;
    }
  }
}

kk_string_t kk_std_time_format_format_absyear(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_drop(n, _ctx);
  kk_integer_t _x_x996;
  kk_integer_t _x_x997;
  {
    struct kk_std_time_time_Time* _con_x998 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x998->date;
    kk_std_time_date__clock _pat_3 = _con_x998->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x998->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x998->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x998->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x998->instant;
    struct kk_std_time_date_Clock* _con_x999 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1000 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1001 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x998->tzabbrv;
    kk_integer_t _pat_4 = _con_x999->hours;
    kk_integer_t _pat_5 = _con_x999->minutes;
    kk_string_t _pat_8 = _con_x1000->name;
    kk_string_t _pat_9 = _con_x1000->long_name;
    kk_string_t _pat_10 = _con_x1000->month_prefix;
    kk_function_t _pat_11 = _con_x1000->show_era;
    kk_function_t _pat_12 = _con_x1000->instant_to_dc;
    kk_function_t _pat_13 = _con_x1000->dc_to_instant;
    kk_function_t _pat_14 = _con_x1000->days_to_date;
    kk_function_t _pat_15 = _con_x1000->date_to_days;
    kk_string_t _pat_20 = _con_x1001->name;
    kk_function_t _pat_21 = _con_x1001->utc_delta;
    kk_function_t _pat_22 = _con_x1001->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_function_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_7, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
        kk_integer_drop(_pat_5, _ctx);
        kk_integer_drop(_pat_4, _ctx);
        kk_datatype_ptr_free(_pat_3, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_3, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__date_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_integer_t _x = _x_0.year;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      _x_x997 = _x; /*int*/
    }
  }
  _x_x996 = kk_integer_abs(_x_x997,kk_context()); /*int*/
  return kk_std_core_int_show(_x_x996, _ctx);
}

kk_string_t kk_std_time_format_format_calname(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x819;
  kk_string_t _x_x1002;
  {
    struct kk_std_time_time_Time* _con_x1003 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1003->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1003->clock;
    kk_std_time_calendar__calendar _x_0 = _con_x1003->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1003->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1003->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1003->instant;
    struct kk_std_time_date_Clock* _con_x1004 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1005 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1006 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_calendar__calendar_dup(_x_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x1007 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x1007->name;
      kk_string_t _pat_1 = _con_x1007->long_name;
      kk_string_t _x = _con_x1007->month_prefix;
      kk_function_t _pat_2 = _con_x1007->show_era;
      kk_function_t _pat_3 = _con_x1007->instant_to_dc;
      kk_function_t _pat_4 = _con_x1007->dc_to_instant;
      kk_function_t _pat_5 = _con_x1007->days_to_date;
      kk_function_t _pat_6 = _con_x1007->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_function_drop(_pat_6, _ctx);
        kk_function_drop(_pat_5, _ctx);
        kk_function_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_function_drop(_pat_2, _ctx);
        kk_string_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1002 = _x; /*string*/
    }
  }
  kk_string_t _x_x1008 = kk_string_empty(); /*string*/
  _match_x819 = kk_string_is_neq(_x_x1002,_x_x1008,kk_context()); /*bool*/
  if (_match_x819) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    bool _match_x820;
    bool _brw_x821 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    _match_x820 = _brw_x821; /*bool*/
    if (_match_x820) {
      struct kk_std_time_time_Time* _con_x1011 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x1011->date;
      kk_std_time_date__clock _pat_4_2 = _con_x1011->clock;
      kk_std_time_calendar__calendar _x_2 = _con_x1011->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1011->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1011->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1011->instant;
      struct kk_std_time_date_Clock* _con_x1012 = kk_std_time_date__as_Clock(_pat_4_2, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1013 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1014 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_string_t _pat_18_0 = _con_x1011->tzabbrv;
      kk_integer_t _pat_5_2 = _con_x1012->hours;
      kk_integer_t _pat_6_2 = _con_x1012->minutes;
      kk_string_t _pat_20_0 = _con_x1014->name;
      kk_function_t _pat_21_0 = _con_x1014->utc_delta;
      kk_function_t _pat_22_0 = _con_x1014->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_2, _ctx)) {
          kk_integer_drop(_pat_6_2, _ctx);
          kk_integer_drop(_pat_5_2, _ctx);
          kk_datatype_ptr_free(_pat_4_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_2, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0, _ctx)) {
          kk_function_drop(_pat_22_0, _ctx);
          kk_function_drop(_pat_21_0, _ctx);
          kk_string_drop(_pat_20_0, _ctx);
          kk_datatype_ptr_free(_pat_19_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_0, _ctx);
        }
        kk_string_drop(_pat_18_0, _ctx);
        kk_std_time_date__date_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_calendar__calendar_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        struct kk_std_time_calendar_Calendar* _con_x1015 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
        kk_string_t _pat_0_2 = _con_x1015->name;
        kk_string_t _x_1 = _con_x1015->long_name;
        kk_string_t _pat_1_2 = _con_x1015->month_prefix;
        kk_function_t _pat_2_1 = _con_x1015->show_era;
        kk_function_t _pat_3_1 = _con_x1015->instant_to_dc;
        kk_function_t _pat_4_1 = _con_x1015->dc_to_instant;
        kk_function_t _pat_5_1 = _con_x1015->days_to_date;
        kk_function_t _pat_6_1 = _con_x1015->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
          kk_function_drop(_pat_6_1, _ctx);
          kk_function_drop(_pat_5_1, _ctx);
          kk_function_drop(_pat_4_1, _ctx);
          kk_function_drop(_pat_3_1, _ctx);
          kk_function_drop(_pat_2_1, _ctx);
          kk_string_drop(_pat_1_2, _ctx);
          kk_string_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(_x_2, _ctx);
        }
        else {
          kk_string_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(_x_2, _ctx);
        }
        return _x_1;
      }
    }
    {
      struct kk_std_time_time_Time* _con_x1016 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_5 = _con_x1016->date;
      kk_std_time_date__clock _pat_4_4 = _con_x1016->clock;
      kk_std_time_calendar__calendar _x_4 = _con_x1016->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x1016->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x1016->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x1016->instant;
      struct kk_std_time_date_Clock* _con_x1017 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1018 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1019 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_string_t _pat_18_1 = _con_x1016->tzabbrv;
      kk_integer_t _pat_5_4 = _con_x1017->hours;
      kk_integer_t _pat_6_4 = _con_x1017->minutes;
      kk_string_t _pat_20_1 = _con_x1019->name;
      kk_function_t _pat_21_1 = _con_x1019->utc_delta;
      kk_function_t _pat_22_1 = _con_x1019->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_4, _ctx)) {
          kk_integer_drop(_pat_6_4, _ctx);
          kk_integer_drop(_pat_5_4, _ctx);
          kk_datatype_ptr_free(_pat_4_4, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_4, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_1, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_1, _ctx)) {
          kk_function_drop(_pat_22_1, _ctx);
          kk_function_drop(_pat_21_1, _ctx);
          kk_string_drop(_pat_20_1, _ctx);
          kk_datatype_ptr_free(_pat_19_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_1, _ctx);
        }
        kk_string_drop(_pat_18_1, _ctx);
        kk_std_time_date__date_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_calendar__calendar_dup(_x_4, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        struct kk_std_time_calendar_Calendar* _con_x1020 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
        kk_string_t _x_3 = _con_x1020->name;
        kk_string_t _pat_0_4 = _con_x1020->long_name;
        kk_string_t _pat_1_4 = _con_x1020->month_prefix;
        kk_function_t _pat_2_4 = _con_x1020->show_era;
        kk_function_t _pat_3_3 = _con_x1020->instant_to_dc;
        kk_function_t _pat_4_3 = _con_x1020->dc_to_instant;
        kk_function_t _pat_5_3 = _con_x1020->days_to_date;
        kk_function_t _pat_6_3 = _con_x1020->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_x_4, _ctx)) {
          kk_function_drop(_pat_6_3, _ctx);
          kk_function_drop(_pat_5_3, _ctx);
          kk_function_drop(_pat_4_3, _ctx);
          kk_function_drop(_pat_3_3, _ctx);
          kk_function_drop(_pat_2_4, _ctx);
          kk_string_drop(_pat_1_4, _ctx);
          kk_string_drop(_pat_0_4, _ctx);
          kk_datatype_ptr_free(_x_4, _ctx);
        }
        else {
          kk_string_dup(_x_3, _ctx);
          kk_datatype_ptr_decref(_x_4, _ctx);
        }
        return _x_3;
      }
    }
  }
}

kk_string_t kk_std_time_format_format_ampm(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_t _b_x1_2 = n; /*int*/;
  kk_std_core_sslice__sslice _x_x1021;
  kk_string_t _x_x1022;
  bool _match_x816;
  kk_integer_t _brw_x817;
  {
    struct kk_std_time_time_Time* _con_x1023 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1023->date;
    kk_std_time_date__clock _x_0 = _con_x1023->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1023->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1023->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1023->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1023->instant;
    struct kk_std_time_date_Clock* _con_x1024 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1025 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1026 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1023->tzabbrv;
    kk_string_t _pat_8 = _con_x1025->name;
    kk_string_t _pat_9 = _con_x1025->long_name;
    kk_string_t _pat_10 = _con_x1025->month_prefix;
    kk_function_t _pat_11 = _con_x1025->show_era;
    kk_function_t _pat_12 = _con_x1025->instant_to_dc;
    kk_function_t _pat_13 = _con_x1025->dc_to_instant;
    kk_function_t _pat_14 = _con_x1025->days_to_date;
    kk_function_t _pat_15 = _con_x1025->date_to_days;
    kk_string_t _pat_20 = _con_x1026->name;
    kk_function_t _pat_21 = _con_x1026->utc_delta;
    kk_function_t _pat_22 = _con_x1026->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_function_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_7, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x1027 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1 = _con_x1027->seconds;
      kk_integer_t _x = _con_x1027->hours;
      kk_integer_t _pat_0 = _con_x1027->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _brw_x817 = _x; /*int*/
    }
  }
  bool _brw_x818 = kk_integer_lte_borrow(_brw_x817,(kk_integer_from_small(11)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x817, _ctx);
  _match_x816 = _brw_x818; /*bool*/
  if (_match_x816) {
    kk_define_string_literal(, _s_x1028, 2, "am", _ctx)
    _x_x1022 = kk_string_dup(_s_x1028, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1029, 2, "pm", _ctx)
    _x_x1022 = kk_string_dup(_s_x1029, _ctx); /*string*/
  }
  kk_std_core_types__optional _x_x1030 = kk_std_core_types__new_Optional(kk_integer_box(_b_x1_2, _ctx), _ctx); /*? 7*/
  _x_x1021 = kk_std_core_sslice_first(_x_x1022, _x_x1030, _ctx); /*sslice/sslice*/
  return kk_std_core_sslice_string(_x_x1021, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10172_fun1034__t {
  struct kk_function_s _base;
  kk_string_t s;
  kk_char_t quote;
};
static kk_string_t kk_std_time_format__mlift_pquoted_10172_fun1034(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10172_fun1034(kk_string_t s, kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10172_fun1034__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10172_fun1034__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10172_fun1034, kk_context());
  _self->s = s;
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_format__mlift_pquoted_10172_fun1034(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10172_fun1034__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10172_fun1034__t*, _fself, _ctx);
  kk_string_t s = _self->s; /* string */
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_string_dup(s, _ctx);kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_string_t _x_x1035 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  kk_string_t _x_x1036;
  kk_string_t _x_x1037 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  _x_x1036 = kk_std_core_types__lp__plus__plus__rp_(s, _x_x1037, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1035, _x_x1036, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10172_fun1039__t {
  struct kk_function_s _base;
  kk_function_t next_10182;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10172_fun1039(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10172_fun1039(kk_function_t next_10182, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10172_fun1039__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10172_fun1039__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10172_fun1039, kk_context());
  _self->next_10182 = next_10182;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10172_fun1039(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10172_fun1039__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10172_fun1039__t*, _fself, _ctx);
  kk_function_t next_10182 = _self->next_10182; /* (char) -> std/text/parse/parse string */
  kk_drop_match(_self, {kk_function_dup(next_10182, _ctx);}, {}, _ctx)
  kk_string_t _x_x1040;
  kk_char_t _x_x1041 = kk_char_unbox(_b_x4, KK_OWNED, _ctx); /*char*/
  _x_x1040 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10182, (next_10182, _x_x1041, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1040);
}

kk_string_t kk_std_time_format__mlift_pquoted_10172(kk_char_t quote, kk_string_t s, kk_context_t* _ctx) { /* (quote : char, s : string) -> std/text/parse/parse string */ 
  kk_char_t x_10181 = kk_std_text_parse_char(quote, _ctx); /*char*/;
  kk_function_t next_10182 = kk_std_time_format__new_mlift_pquoted_10172_fun1034(s, quote, _ctx); /*(char) -> std/text/parse/parse string*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1038 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10172_fun1039(next_10182, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1038);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10182, (next_10182, x_10181, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10173_fun1043__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1043(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10173_fun1043(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10173_fun1043__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10173_fun1043__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10173_fun1043, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10173_fun1046__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static bool kk_std_time_format__mlift_pquoted_10173_fun1046(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10173_fun1046(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10173_fun1046__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10173_fun1046__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10173_fun1046, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_format__mlift_pquoted_10173_fun1046(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10173_fun1046__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10173_fun1046__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  return (c != quote);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10173_fun1049__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1049(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10173_fun1049(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_pquoted_10173_fun1049, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1049(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1050;
  kk_std_core_types__list _x_x1051 = kk_std_core_types__list_unbox(_b_x7, KK_OWNED, _ctx); /*list<char>*/
  _x_x1050 = kk_std_core_string_listchar_fs_string(_x_x1051, _ctx); /*string*/
  return kk_string_box(_x_x1050);
}
static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1043(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10173_fun1043__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10173_fun1043__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_0_10188;
  kk_string_t _x_x1044 = kk_string_empty(); /*string*/
  x_0_10188 = kk_std_text_parse_chars_are(_x_x1044, kk_std_time_format__new_mlift_pquoted_10173_fun1046(quote, _ctx), _ctx); /*list<char>*/
  kk_string_t _x_x1047;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10188, _ctx);
    kk_box_t _x_x1048 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10173_fun1049(_ctx), _ctx); /*2419*/
    _x_x1047 = kk_string_unbox(_x_x1048); /*string*/
  }
  else {
    _x_x1047 = kk_std_core_string_listchar_fs_string(x_0_10188, _ctx); /*string*/
  }
  return kk_string_box(_x_x1047);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10173_fun1052__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1052(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10173_fun1052(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_pquoted_10173_fun1052, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1052(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1053 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x1053);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10173_fun1056__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1056(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10173_fun1056(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10173_fun1056__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10173_fun1056__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10173_fun1056, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10173_fun1056(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10173_fun1056__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10173_fun1056__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_string_t s_16 = kk_string_unbox(_b_x14); /*string*/;
  kk_string_t _x_x1057 = kk_std_time_format__mlift_pquoted_10172(quote, s_16, _ctx); /*string*/
  return kk_string_box(_x_x1057);
}

kk_string_t kk_std_time_format__mlift_pquoted_10173(kk_char_t quote, kk_char_t wild__, kk_context_t* _ctx) { /* (quote : char, wild_ : char) -> std/text/parse/parse string */ 
  kk_string_t x_10186;
  kk_box_t _x_x1042 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_format__new_mlift_pquoted_10173_fun1043(quote, _ctx), kk_std_time_format__new_mlift_pquoted_10173_fun1052(_ctx), _ctx); /*1542*/
  x_10186 = kk_string_unbox(_x_x1042); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10186, _ctx);
    kk_box_t _x_x1055 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10173_fun1056(quote, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1055);
  }
  {
    return kk_std_time_format__mlift_pquoted_10172(quote, x_10186, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1059__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1059(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1059(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1059__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1059__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1059, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1059(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1059__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1059__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_char_t wild___33 = kk_char_unbox(_b_x18, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1060 = kk_std_time_format__mlift_pquoted_10173(quote, wild___33, _ctx); /*string*/
  return kk_string_box(_x_x1060);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1062__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1062(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1062(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1062__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1062__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1062, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_pquoted_fun1065__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static bool kk_std_time_format_pquoted_fun1065(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1065(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1065__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1065__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1065, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_format_pquoted_fun1065(kk_function_t _fself, kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1065__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1065__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  return (c != quote);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1068__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_pquoted_fun1068(kk_function_t _fself, kk_box_t _b_x20, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1068(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_pquoted_fun1068, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1068(kk_function_t _fself, kk_box_t _b_x20, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1069;
  kk_std_core_types__list _x_x1070 = kk_std_core_types__list_unbox(_b_x20, KK_OWNED, _ctx); /*list<char>*/
  _x_x1069 = kk_std_core_string_listchar_fs_string(_x_x1070, _ctx); /*string*/
  return kk_string_box(_x_x1069);
}
static kk_box_t kk_std_time_format_pquoted_fun1062(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1062__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1062__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_1_10196;
  kk_string_t _x_x1063 = kk_string_empty(); /*string*/
  x_1_10196 = kk_std_text_parse_chars_are(_x_x1063, kk_std_time_format_new_pquoted_fun1065(quote, _ctx), _ctx); /*list<char>*/
  kk_string_t _x_x1066;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10196, _ctx);
    kk_box_t _x_x1067 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1068(_ctx), _ctx); /*2419*/
    _x_x1066 = kk_string_unbox(_x_x1067); /*string*/
  }
  else {
    _x_x1066 = kk_std_core_string_listchar_fs_string(x_1_10196, _ctx); /*string*/
  }
  return kk_string_box(_x_x1066);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1071__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_pquoted_fun1071(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1071(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_pquoted_fun1071, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1071(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1072 = kk_string_empty(); /*string*/
  return kk_string_box(_x_x1072);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1075__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1075(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1075(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1075__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1075__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1075, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1075(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1075__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1075__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_string_t s_34 = kk_string_unbox(_b_x27); /*string*/;
  kk_string_t _x_x1076 = kk_std_time_format__mlift_pquoted_10172(quote, s_34, _ctx); /*string*/
  return kk_string_box(_x_x1076);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1078__t {
  struct kk_function_s _base;
  kk_string_t x_0_10193;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1078(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1078(kk_string_t x_0_10193, kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1078__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1078__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1078, kk_context());
  _self->x_0_10193 = x_0_10193;
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1078(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1078__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1078__t*, _fself, _ctx);
  kk_string_t x_0_10193 = _self->x_0_10193; /* string */
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_string_dup(x_0_10193, _ctx);kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_char_t wild___0_35 = kk_char_unbox(_b_x29, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1079;
  kk_string_t _x_x1080 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  kk_string_t _x_x1081;
  kk_string_t _x_x1082 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  _x_x1081 = kk_std_core_types__lp__plus__plus__rp_(x_0_10193, _x_x1082, _ctx); /*string*/
  _x_x1079 = kk_std_core_types__lp__plus__plus__rp_(_x_x1080, _x_x1081, _ctx); /*string*/
  return kk_string_box(_x_x1079);
}

kk_string_t kk_std_time_format_pquoted(kk_char_t quote, kk_context_t* _ctx) { /* (quote : char) -> std/text/parse/parse string */ 
  kk_char_t x_10190 = kk_std_text_parse_char(quote, _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1058 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1059(quote, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1058);
  }
  {
    kk_string_t x_0_10193;
    kk_box_t _x_x1061 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_format_new_pquoted_fun1062(quote, _ctx), kk_std_time_format_new_pquoted_fun1071(_ctx), _ctx); /*1542*/
    x_0_10193 = kk_string_unbox(_x_x1061); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10193, _ctx);
      kk_box_t _x_x1074 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1075(quote, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x1074);
    }
    {
      kk_char_t x_2_10198 = kk_std_text_parse_char(quote, _ctx); /*char*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1077 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1078(x_0_10193, quote, _ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x1077);
      }
      {
        kk_string_t _x_x1083 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
        kk_string_t _x_x1084;
        kk_string_t _x_x1085 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
        _x_x1084 = kk_std_core_types__lp__plus__plus__rp_(x_0_10193, _x_x1085, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x1083, _x_x1084, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10174_fun1087__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10174_fun1087(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10174_fun1087(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_t_10174_fun1087, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10174_fun1087(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_locale__time_locale _this_0_41 = kk_std_time_locale__time_locale_unbox(_b_x38, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  kk_string_t _x_x1088;
  {
    struct kk_std_time_locale_Time_locale* _con_x1089 = kk_std_time_locale__as_Time_locale(_this_0_41, _ctx);
    kk_string_t _pat_0_0 = _con_x1089->lang_name;
    kk_std_core_types__list _pat_1_0 = _con_x1089->day_names;
    kk_std_core_types__list _pat_2_0 = _con_x1089->month_names;
    kk_std_core_types__list _pat_3_0 = _con_x1089->month_names_short;
    kk_std_core_types__list _pat_4_0 = _con_x1089->day_names_short;
    kk_std_core_types__list _pat_5_0 = _con_x1089->day_names_min;
    kk_string_t _pat_6_0 = _con_x1089->format_t;
    kk_string_t _x_0 = _con_x1089->format_tt;
    kk_string_t _pat_7_0 = _con_x1089->format_l;
    kk_string_t _pat_8_0 = _con_x1089->format_ll;
    kk_string_t _pat_9_0 = _con_x1089->format_lll;
    kk_string_t _pat_10_0 = _con_x1089->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_this_0_41, _ctx)) {
      kk_string_drop(_pat_9_0, _ctx);
      kk_string_drop(_pat_8_0, _ctx);
      kk_string_drop(_pat_7_0, _ctx);
      kk_string_drop(_pat_6_0, _ctx);
      kk_std_core_types__list_drop(_pat_5_0, _ctx);
      kk_std_core_types__list_drop(_pat_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_10_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_this_0_41, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_this_0_41, _ctx);
    }
    _x_x1088 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1088);
}

kk_string_t kk_std_time_format__mlift_plocale_t_10174(kk_std_time_locale__time_locale locale, kk_char_t wild___0, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale, wild_@0 : char) -> std/text/parse/parse string */ 
  kk_box_t _x_x1086 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_t_10174_fun1087(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
  return kk_string_unbox(_x_x1086);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10175_fun1091__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1091(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10175_fun1091(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_t_10175_fun1091, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1091(kk_function_t _fself, kk_box_t _b_x44, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1092;
  kk_std_time_locale__time_locale _match_x808 = kk_std_time_locale__time_locale_unbox(_b_x44, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1093 = kk_std_time_locale__as_Time_locale(_match_x808, _ctx);
    kk_string_t _pat_0 = _con_x1093->lang_name;
    kk_std_core_types__list _pat_1 = _con_x1093->day_names;
    kk_std_core_types__list _pat_2 = _con_x1093->month_names;
    kk_std_core_types__list _pat_3 = _con_x1093->month_names_short;
    kk_std_core_types__list _pat_4 = _con_x1093->day_names_short;
    kk_std_core_types__list _pat_5 = _con_x1093->day_names_min;
    kk_string_t _x = _con_x1093->format_t;
    kk_string_t _pat_6 = _con_x1093->format_tt;
    kk_string_t _pat_7 = _con_x1093->format_l;
    kk_string_t _pat_8 = _con_x1093->format_ll;
    kk_string_t _pat_9 = _con_x1093->format_lll;
    kk_string_t _pat_10 = _con_x1093->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x808, _ctx)) {
      kk_string_drop(_pat_9, _ctx);
      kk_string_drop(_pat_8, _ctx);
      kk_string_drop(_pat_7, _ctx);
      kk_string_drop(_pat_6, _ctx);
      kk_std_core_types__list_drop(_pat_5, _ctx);
      kk_std_core_types__list_drop(_pat_4, _ctx);
      kk_std_core_types__list_drop(_pat_3, _ctx);
      kk_std_core_types__list_drop(_pat_2, _ctx);
      kk_string_drop(_pat_10, _ctx);
      kk_std_core_types__list_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x808, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x808, _ctx);
    }
    _x_x1092 = _x; /*string*/
  }
  return kk_string_box(_x_x1092);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10175_fun1097__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1097(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10175_fun1097(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1097__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1097__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_t_10175_fun1097, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10175_fun1098__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_string_t kk_std_time_format__mlift_plocale_t_10175_fun1098(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10175_fun1098(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1098__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1098__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_t_10175_fun1098, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10175_fun1100__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1100(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10175_fun1100(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_t_10175_fun1100, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1100(kk_function_t _fself, kk_box_t _b_x50, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1101;
  kk_std_time_locale__time_locale _match_x807 = kk_std_time_locale__time_locale_unbox(_b_x50, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1102 = kk_std_time_locale__as_Time_locale(_match_x807, _ctx);
    kk_string_t _pat_0_0_0 = _con_x1102->lang_name;
    kk_std_core_types__list _pat_1_0 = _con_x1102->day_names;
    kk_std_core_types__list _pat_2_0 = _con_x1102->month_names;
    kk_std_core_types__list _pat_3_0 = _con_x1102->month_names_short;
    kk_std_core_types__list _pat_4_0 = _con_x1102->day_names_short;
    kk_std_core_types__list _pat_5_0 = _con_x1102->day_names_min;
    kk_string_t _pat_6_0 = _con_x1102->format_t;
    kk_string_t _x_0 = _con_x1102->format_tt;
    kk_string_t _pat_7_0 = _con_x1102->format_l;
    kk_string_t _pat_8_0 = _con_x1102->format_ll;
    kk_string_t _pat_9_0 = _con_x1102->format_lll;
    kk_string_t _pat_10_0 = _con_x1102->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x807, _ctx)) {
      kk_string_drop(_pat_9_0, _ctx);
      kk_string_drop(_pat_8_0, _ctx);
      kk_string_drop(_pat_7_0, _ctx);
      kk_string_drop(_pat_6_0, _ctx);
      kk_std_core_types__list_drop(_pat_5_0, _ctx);
      kk_std_core_types__list_drop(_pat_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_10_0, _ctx);
      kk_string_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x807, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x807, _ctx);
    }
    _x_x1101 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1101);
}
static kk_string_t kk_std_time_format__mlift_plocale_t_10175_fun1098(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1098__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1098__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_box_t _x_x1099 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_t_10175_fun1100(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
  return kk_string_unbox(_x_x1099);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10175_fun1105__t {
  struct kk_function_s _base;
  kk_function_t next_10205;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1105(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10175_fun1105(kk_function_t next_10205, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1105__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1105__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_t_10175_fun1105, kk_context());
  _self->next_10205 = next_10205;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1105(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1105__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1105__t*, _fself, _ctx);
  kk_function_t next_10205 = _self->next_10205; /* (char) -> std/text/parse/parse string */
  kk_drop_match(_self, {kk_function_dup(next_10205, _ctx);}, {}, _ctx)
  kk_string_t _x_x1106;
  kk_char_t _x_x1107 = kk_char_unbox(_b_x55, KK_OWNED, _ctx); /*char*/
  _x_x1106 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10205, (next_10205, _x_x1107, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1106);
}
static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1097(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1097__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1097__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_char_t x_10204 = kk_std_text_parse_char('t', _ctx); /*char*/;
  kk_function_t next_10205 = kk_std_time_format__new_mlift_plocale_t_10175_fun1098(locale, _ctx); /*(char) -> std/text/parse/parse string*/;
  kk_string_t _x_x1103;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1104 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_t_10175_fun1105(next_10205, _ctx), _ctx); /*2419*/
    _x_x1103 = kk_string_unbox(_x_x1104); /*string*/
  }
  else {
    _x_x1103 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10205, (next_10205, x_10204, _ctx), _ctx); /*string*/
  }
  return kk_string_box(_x_x1103);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10175_fun1108__t {
  struct kk_function_s _base;
  kk_string_t default_10018;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1108(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10175_fun1108(kk_string_t default_10018, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1108__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1108__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_t_10175_fun1108, kk_context());
  _self->default_10018 = default_10018;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10175_fun1108(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10175_fun1108__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_t_10175_fun1108__t*, _fself, _ctx);
  kk_string_t default_10018 = _self->default_10018; /* string */
  kk_drop_match(_self, {kk_string_dup(default_10018, _ctx);}, {}, _ctx)
  return kk_string_box(default_10018);
}

kk_string_t kk_std_time_format__mlift_plocale_t_10175(kk_std_time_locale__time_locale locale, kk_char_t wild__, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale, wild_ : char) -> std/text/parse/parse string */ 
  kk_string_t default_10018;
  kk_box_t _x_x1090;
  kk_box_t _x_x1094;
  kk_std_time_locale__time_locale _x_x1095 = kk_std_time_locale__time_locale_dup(locale, _ctx); /*std/time/locale/time-locale*/
  _x_x1094 = kk_std_time_locale__time_locale_box(_x_x1095, _ctx); /*9903*/
  _x_x1090 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_t_10175_fun1091(_ctx), _x_x1094, _ctx); /*9904*/
  default_10018 = kk_string_unbox(_x_x1090); /*string*/
  kk_box_t _x_x1096 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_format__new_mlift_plocale_t_10175_fun1097(locale, _ctx), kk_std_time_format__new_mlift_plocale_t_10175_fun1108(default_10018, _ctx), _ctx); /*1542*/
  return kk_string_unbox(_x_x1096);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1110__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_t_fun1110(kk_function_t _fself, kk_box_t _b_x62, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1110(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1110__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1110__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1110, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1110(kk_function_t _fself, kk_box_t _b_x62, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1110__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1110__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_char_t wild___83 = kk_char_unbox(_b_x62, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1111 = kk_std_time_format__mlift_plocale_t_10175(locale, wild___83, _ctx); /*string*/
  return kk_string_box(_x_x1111);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1113__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_t_fun1113(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1113(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_t_fun1113, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1113(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1114;
  kk_std_time_locale__time_locale _match_x805 = kk_std_time_locale__time_locale_unbox(_b_x65, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1115 = kk_std_time_locale__as_Time_locale(_match_x805, _ctx);
    kk_string_t _pat_0_0 = _con_x1115->lang_name;
    kk_std_core_types__list _pat_1_0 = _con_x1115->day_names;
    kk_std_core_types__list _pat_2 = _con_x1115->month_names;
    kk_std_core_types__list _pat_3 = _con_x1115->month_names_short;
    kk_std_core_types__list _pat_4 = _con_x1115->day_names_short;
    kk_std_core_types__list _pat_5 = _con_x1115->day_names_min;
    kk_string_t _x = _con_x1115->format_t;
    kk_string_t _pat_6 = _con_x1115->format_tt;
    kk_string_t _pat_7 = _con_x1115->format_l;
    kk_string_t _pat_8 = _con_x1115->format_ll;
    kk_string_t _pat_9 = _con_x1115->format_lll;
    kk_string_t _pat_10 = _con_x1115->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x805, _ctx)) {
      kk_string_drop(_pat_9, _ctx);
      kk_string_drop(_pat_8, _ctx);
      kk_string_drop(_pat_7, _ctx);
      kk_string_drop(_pat_6, _ctx);
      kk_std_core_types__list_drop(_pat_5, _ctx);
      kk_std_core_types__list_drop(_pat_4, _ctx);
      kk_std_core_types__list_drop(_pat_3, _ctx);
      kk_std_core_types__list_drop(_pat_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_10, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_match_x805, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x805, _ctx);
    }
    _x_x1114 = _x; /*string*/
  }
  return kk_string_box(_x_x1114);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1119__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_t_fun1119(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1119(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1119__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1119__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1119, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_plocale_t_fun1120__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_string_t kk_std_time_format_plocale_t_fun1120(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1120(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1120__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1120__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1120, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_plocale_t_fun1122__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_t_fun1122(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1122(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_t_fun1122, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1122(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1123;
  kk_std_time_locale__time_locale _match_x804 = kk_std_time_locale__time_locale_unbox(_b_x71, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1124 = kk_std_time_locale__as_Time_locale(_match_x804, _ctx);
    kk_string_t _pat_0_0_0 = _con_x1124->lang_name;
    kk_std_core_types__list _pat_1_0_0 = _con_x1124->day_names;
    kk_std_core_types__list _pat_2_0 = _con_x1124->month_names;
    kk_std_core_types__list _pat_3_0 = _con_x1124->month_names_short;
    kk_std_core_types__list _pat_4_0 = _con_x1124->day_names_short;
    kk_std_core_types__list _pat_5_0 = _con_x1124->day_names_min;
    kk_string_t _pat_6_0 = _con_x1124->format_t;
    kk_string_t _x_0 = _con_x1124->format_tt;
    kk_string_t _pat_7_0 = _con_x1124->format_l;
    kk_string_t _pat_8_0 = _con_x1124->format_ll;
    kk_string_t _pat_9_0 = _con_x1124->format_lll;
    kk_string_t _pat_10_0 = _con_x1124->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x804, _ctx)) {
      kk_string_drop(_pat_9_0, _ctx);
      kk_string_drop(_pat_8_0, _ctx);
      kk_string_drop(_pat_7_0, _ctx);
      kk_string_drop(_pat_6_0, _ctx);
      kk_std_core_types__list_drop(_pat_5_0, _ctx);
      kk_std_core_types__list_drop(_pat_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_0_0, _ctx);
      kk_string_drop(_pat_10_0, _ctx);
      kk_string_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x804, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x804, _ctx);
    }
    _x_x1123 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1123);
}
static kk_string_t kk_std_time_format_plocale_t_fun1120(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1120__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1120__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_box_t _x_x1121 = kk_std_core_hnd__open_none1(kk_std_time_format_new_plocale_t_fun1122(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
  return kk_string_unbox(_x_x1121);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1127__t {
  struct kk_function_s _base;
  kk_function_t next_0_10212;
};
static kk_box_t kk_std_time_format_plocale_t_fun1127(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1127(kk_function_t next_0_10212, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1127__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1127__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1127, kk_context());
  _self->next_0_10212 = next_0_10212;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1127(kk_function_t _fself, kk_box_t _b_x76, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1127__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1127__t*, _fself, _ctx);
  kk_function_t next_0_10212 = _self->next_0_10212; /* (char) -> std/text/parse/parse string */
  kk_drop_match(_self, {kk_function_dup(next_0_10212, _ctx);}, {}, _ctx)
  kk_string_t _x_x1128;
  kk_char_t _x_x1129 = kk_char_unbox(_b_x76, KK_OWNED, _ctx); /*char*/
  _x_x1128 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_0_10212, (next_0_10212, _x_x1129, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1128);
}
static kk_box_t kk_std_time_format_plocale_t_fun1119(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1119__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1119__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_char_t x_0_10211 = kk_std_text_parse_char('t', _ctx); /*char*/;
  kk_function_t next_0_10212 = kk_std_time_format_new_plocale_t_fun1120(locale, _ctx); /*(char) -> std/text/parse/parse string*/;
  kk_string_t _x_x1125;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1126 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_t_fun1127(next_0_10212, _ctx), _ctx); /*2419*/
    _x_x1125 = kk_string_unbox(_x_x1126); /*string*/
  }
  else {
    _x_x1125 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_0_10212, (next_0_10212, x_0_10211, _ctx), _ctx); /*string*/
  }
  return kk_string_box(_x_x1125);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1130__t {
  struct kk_function_s _base;
  kk_string_t default_10018;
};
static kk_box_t kk_std_time_format_plocale_t_fun1130(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1130(kk_string_t default_10018, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1130__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1130__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1130, kk_context());
  _self->default_10018 = default_10018;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1130(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1130__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1130__t*, _fself, _ctx);
  kk_string_t default_10018 = _self->default_10018; /* string */
  kk_drop_match(_self, {kk_string_dup(default_10018, _ctx);}, {}, _ctx)
  return kk_string_box(default_10018);
}

kk_string_t kk_std_time_format_plocale_t(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
  kk_char_t x_10208 = kk_std_text_parse_char('t', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1109 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_t_fun1110(locale, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1109);
  }
  {
    kk_string_t default_10018;
    kk_box_t _x_x1112;
    kk_box_t _x_x1116;
    kk_std_time_locale__time_locale _x_x1117 = kk_std_time_locale__time_locale_dup(locale, _ctx); /*std/time/locale/time-locale*/
    _x_x1116 = kk_std_time_locale__time_locale_box(_x_x1117, _ctx); /*9903*/
    _x_x1112 = kk_std_core_hnd__open_none1(kk_std_time_format_new_plocale_t_fun1113(_ctx), _x_x1116, _ctx); /*9904*/
    default_10018 = kk_string_unbox(_x_x1112); /*string*/
    kk_box_t _x_x1118 = kk_std_text_parse__lp__bar__bar__rp_(kk_std_time_format_new_plocale_t_fun1119(locale, _ctx), kk_std_time_format_new_plocale_t_fun1130(default_10018, _ctx), _ctx); /*1542*/
    return kk_string_unbox(_x_x1118);
  }
}
 
// monadic lift

kk_string_t kk_std_time_format__mlift_plocale_l_10176(kk_char_t l, kk_string_t _c_x10144, kk_context_t* _ctx) { /* (l : char, string) -> string */ 
  bool _match_x801 = (l == ('L')); /*bool*/;
  if (_match_x801) {
    return _c_x10144;
  }
  {
    kk_string_t _x_x1131;
    kk_string_t _x_x1132;
    kk_string_t _x_x1133;
    kk_string_t _x_x1134;
    kk_string_t _x_x1135;
    kk_string_t _x_x1136;
    kk_define_string_literal(, _s_x1137, 2, "dd", _ctx)
    _x_x1136 = kk_string_dup(_s_x1137, _ctx); /*string*/
    kk_string_t _x_x1138;
    kk_define_string_literal(, _s_x1139, 1, "d", _ctx)
    _x_x1138 = kk_string_dup(_s_x1139, _ctx); /*string*/
    _x_x1135 = kk_string_replace_all(_c_x10144,_x_x1136,_x_x1138,kk_context()); /*string*/
    kk_string_t _x_x1140;
    kk_define_string_literal(, _s_x1141, 2, "dd", _ctx)
    _x_x1140 = kk_string_dup(_s_x1141, _ctx); /*string*/
    kk_string_t _x_x1142;
    kk_define_string_literal(, _s_x1143, 3, "ddd", _ctx)
    _x_x1142 = kk_string_dup(_s_x1143, _ctx); /*string*/
    _x_x1134 = kk_string_replace_all(_x_x1135,_x_x1140,_x_x1142,kk_context()); /*string*/
    kk_string_t _x_x1144;
    kk_define_string_literal(, _s_x1145, 2, "MM", _ctx)
    _x_x1144 = kk_string_dup(_s_x1145, _ctx); /*string*/
    kk_string_t _x_x1146;
    kk_define_string_literal(, _s_x1147, 1, "M", _ctx)
    _x_x1146 = kk_string_dup(_s_x1147, _ctx); /*string*/
    _x_x1133 = kk_string_replace_all(_x_x1134,_x_x1144,_x_x1146,kk_context()); /*string*/
    kk_string_t _x_x1148;
    kk_define_string_literal(, _s_x1149, 2, "MM", _ctx)
    _x_x1148 = kk_string_dup(_s_x1149, _ctx); /*string*/
    kk_string_t _x_x1150;
    kk_define_string_literal(, _s_x1151, 3, "MMM", _ctx)
    _x_x1150 = kk_string_dup(_s_x1151, _ctx); /*string*/
    _x_x1132 = kk_string_replace_all(_x_x1133,_x_x1148,_x_x1150,kk_context()); /*string*/
    kk_string_t _x_x1152;
    kk_define_string_literal(, _s_x1153, 2, "DD", _ctx)
    _x_x1152 = kk_string_dup(_s_x1153, _ctx); /*string*/
    kk_string_t _x_x1154;
    kk_define_string_literal(, _s_x1155, 1, "D", _ctx)
    _x_x1154 = kk_string_dup(_s_x1155, _ctx); /*string*/
    _x_x1131 = kk_string_replace_all(_x_x1132,_x_x1152,_x_x1154,kk_context()); /*string*/
    kk_string_t _x_x1156;
    kk_define_string_literal(, _s_x1157, 2, "DD", _ctx)
    _x_x1156 = kk_string_dup(_s_x1157, _ctx); /*string*/
    kk_string_t _x_x1158;
    kk_define_string_literal(, _s_x1159, 3, "DDD", _ctx)
    _x_x1158 = kk_string_dup(_s_x1159, _ctx); /*string*/
    return kk_string_replace_all(_x_x1131,_x_x1156,_x_x1158,kk_context());
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10177_fun1162__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1162(kk_function_t _fself, kk_box_t _b_x90, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10177_fun1162(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_l_10177_fun1162, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1162(kk_function_t _fself, kk_box_t _b_x90, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1163;
  kk_std_time_locale__time_locale _match_x800 = kk_std_time_locale__time_locale_unbox(_b_x90, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1164 = kk_std_time_locale__as_Time_locale(_match_x800, _ctx);
    kk_string_t _pat_0_0_0 = _con_x1164->lang_name;
    kk_std_core_types__list _pat_1_0 = _con_x1164->day_names;
    kk_std_core_types__list _pat_2 = _con_x1164->month_names;
    kk_std_core_types__list _pat_3 = _con_x1164->month_names_short;
    kk_std_core_types__list _pat_4 = _con_x1164->day_names_short;
    kk_std_core_types__list _pat_5 = _con_x1164->day_names_min;
    kk_string_t _pat_6 = _con_x1164->format_t;
    kk_string_t _pat_7 = _con_x1164->format_tt;
    kk_string_t _pat_8 = _con_x1164->format_l;
    kk_string_t _pat_9 = _con_x1164->format_ll;
    kk_string_t _pat_10 = _con_x1164->format_lll;
    kk_string_t _x = _con_x1164->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x800, _ctx)) {
      kk_string_drop(_pat_9, _ctx);
      kk_string_drop(_pat_8, _ctx);
      kk_string_drop(_pat_7, _ctx);
      kk_string_drop(_pat_6, _ctx);
      kk_std_core_types__list_drop(_pat_5, _ctx);
      kk_std_core_types__list_drop(_pat_4, _ctx);
      kk_std_core_types__list_drop(_pat_3, _ctx);
      kk_std_core_types__list_drop(_pat_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_10, _ctx);
      kk_string_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x800, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x800, _ctx);
    }
    _x_x1163 = _x; /*string*/
  }
  return kk_string_box(_x_x1163);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10177_fun1165__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1165(kk_function_t _fself, kk_box_t _b_x93, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10177_fun1165(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_l_10177_fun1165, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1165(kk_function_t _fself, kk_box_t _b_x93, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1166;
  kk_std_time_locale__time_locale _match_x799 = kk_std_time_locale__time_locale_unbox(_b_x93, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1167 = kk_std_time_locale__as_Time_locale(_match_x799, _ctx);
    kk_string_t _pat_0_2 = _con_x1167->lang_name;
    kk_std_core_types__list _pat_1_1 = _con_x1167->day_names;
    kk_std_core_types__list _pat_2_0 = _con_x1167->month_names;
    kk_std_core_types__list _pat_3_0 = _con_x1167->month_names_short;
    kk_std_core_types__list _pat_4_0 = _con_x1167->day_names_short;
    kk_std_core_types__list _pat_5_0 = _con_x1167->day_names_min;
    kk_string_t _pat_6_0 = _con_x1167->format_t;
    kk_string_t _pat_7_0 = _con_x1167->format_tt;
    kk_string_t _pat_8_0 = _con_x1167->format_l;
    kk_string_t _pat_9_0 = _con_x1167->format_ll;
    kk_string_t _x_0 = _con_x1167->format_lll;
    kk_string_t _pat_10_0 = _con_x1167->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x799, _ctx)) {
      kk_string_drop(_pat_9_0, _ctx);
      kk_string_drop(_pat_8_0, _ctx);
      kk_string_drop(_pat_7_0, _ctx);
      kk_string_drop(_pat_6_0, _ctx);
      kk_std_core_types__list_drop(_pat_5_0, _ctx);
      kk_std_core_types__list_drop(_pat_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_10_0, _ctx);
      kk_string_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(_match_x799, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x799, _ctx);
    }
    _x_x1166 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1166);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10177_fun1168__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1168(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10177_fun1168(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_l_10177_fun1168, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1168(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1169;
  kk_std_time_locale__time_locale _match_x797 = kk_std_time_locale__time_locale_unbox(_b_x96, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1170 = kk_std_time_locale__as_Time_locale(_match_x797, _ctx);
    kk_string_t _pat_0_3 = _con_x1170->lang_name;
    kk_std_core_types__list _pat_1_2 = _con_x1170->day_names;
    kk_std_core_types__list _pat_2_2 = _con_x1170->month_names;
    kk_std_core_types__list _pat_3_2 = _con_x1170->month_names_short;
    kk_std_core_types__list _pat_4_1 = _con_x1170->day_names_short;
    kk_std_core_types__list _pat_5_1 = _con_x1170->day_names_min;
    kk_string_t _pat_6_1 = _con_x1170->format_t;
    kk_string_t _pat_7_1 = _con_x1170->format_tt;
    kk_string_t _pat_8_1 = _con_x1170->format_l;
    kk_string_t _x_1 = _con_x1170->format_ll;
    kk_string_t _pat_9_1 = _con_x1170->format_lll;
    kk_string_t _pat_10_1 = _con_x1170->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x797, _ctx)) {
      kk_string_drop(_pat_9_1, _ctx);
      kk_string_drop(_pat_8_1, _ctx);
      kk_string_drop(_pat_7_1, _ctx);
      kk_string_drop(_pat_6_1, _ctx);
      kk_std_core_types__list_drop(_pat_5_1, _ctx);
      kk_std_core_types__list_drop(_pat_4_1, _ctx);
      kk_std_core_types__list_drop(_pat_3_2, _ctx);
      kk_std_core_types__list_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_string_drop(_pat_10_1, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(_match_x797, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x797, _ctx);
    }
    _x_x1169 = _x_1; /*string*/
  }
  return kk_string_box(_x_x1169);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10177_fun1171__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1171(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10177_fun1171(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_l_10177_fun1171, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1171(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1172;
  kk_std_time_locale__time_locale _match_x796 = kk_std_time_locale__time_locale_unbox(_b_x99, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1173 = kk_std_time_locale__as_Time_locale(_match_x796, _ctx);
    kk_string_t _pat_0_4 = _con_x1173->lang_name;
    kk_std_core_types__list _pat_1_3 = _con_x1173->day_names;
    kk_std_core_types__list _pat_2_3 = _con_x1173->month_names;
    kk_std_core_types__list _pat_3_3 = _con_x1173->month_names_short;
    kk_std_core_types__list _pat_4_3 = _con_x1173->day_names_short;
    kk_std_core_types__list _pat_5_2 = _con_x1173->day_names_min;
    kk_string_t _pat_6_2 = _con_x1173->format_t;
    kk_string_t _pat_7_2 = _con_x1173->format_tt;
    kk_string_t _x_2 = _con_x1173->format_l;
    kk_string_t _pat_8_2 = _con_x1173->format_ll;
    kk_string_t _pat_9_2 = _con_x1173->format_lll;
    kk_string_t _pat_10_2 = _con_x1173->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x796, _ctx)) {
      kk_string_drop(_pat_9_2, _ctx);
      kk_string_drop(_pat_8_2, _ctx);
      kk_string_drop(_pat_7_2, _ctx);
      kk_string_drop(_pat_6_2, _ctx);
      kk_std_core_types__list_drop(_pat_5_2, _ctx);
      kk_std_core_types__list_drop(_pat_4_3, _ctx);
      kk_std_core_types__list_drop(_pat_3_3, _ctx);
      kk_std_core_types__list_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_10_2, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(_match_x796, _ctx);
    }
    else {
      kk_string_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(_match_x796, _ctx);
    }
    _x_x1172 = _x_2; /*string*/
  }
  return kk_string_box(_x_x1172);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10177_fun1175__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1175(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10177_fun1175(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10177_fun1175__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_l_10177_fun1175__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_l_10177_fun1175, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10177_fun1175(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10177_fun1175__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_l_10177_fun1175__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_string_t _c_x10144_115 = kk_string_unbox(_b_x113); /*string*/;
  kk_string_t _x_x1176 = kk_std_time_format__mlift_plocale_l_10176(l, _c_x10144_115, _ctx); /*string*/
  return kk_string_box(_x_x1176);
}

kk_string_t kk_std_time_format__mlift_plocale_l_10177(kk_char_t _y_x10139, kk_char_t l, kk_std_time_locale__time_locale locale, kk_std_core_types__list _y_x10141, kk_context_t* _ctx) { /* (char, l : char, locale : std/time/locale/time-locale, list<char>) -> std/text/parse/parse string */ 
  kk_integer_t n;
  kk_std_core_types__list _x_x1160 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_y_x10139, _ctx), _y_x10141, _ctx); /*list<79>*/
  n = kk_std_core_list__lift_length_5730(_x_x1160, kk_integer_from_small(0), _ctx); /*int*/
  kk_string_t x_10215;
  kk_box_t _x_x1161;
  bool _match_x793 = kk_integer_gte_borrow(n,(kk_integer_from_small(4)),kk_context()); /*bool*/;
  if (_match_x793) {
    kk_integer_drop(n, _ctx);
    _x_x1161 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_l_10177_fun1162(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
  }
  else {
    bool _match_x794 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
    if (_match_x794) {
      kk_integer_drop(n, _ctx);
      _x_x1161 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_l_10177_fun1165(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
    }
    else {
      bool _match_x795;
      bool _brw_x798 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x795 = _brw_x798; /*bool*/
      if (_match_x795) {
        _x_x1161 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_l_10177_fun1168(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
      }
      else {
        _x_x1161 = kk_std_core_hnd__open_none1(kk_std_time_format__new_mlift_plocale_l_10177_fun1171(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
      }
    }
  }
  x_10215 = kk_string_unbox(_x_x1161); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10215, _ctx);
    kk_box_t _x_x1174 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_l_10177_fun1175(l, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1174);
  }
  {
    return kk_std_time_format__mlift_plocale_l_10176(l, x_10215, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10178_fun1177__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10178_fun1177(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10178_fun1177(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10178_fun1177__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_l_10178_fun1177__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_l_10178_fun1177, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10178_fun1177(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10178_fun1177__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_l_10178_fun1177__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_char_t _x_x1178 = kk_std_text_parse_char(l, _ctx); /*char*/
  return kk_char_box(_x_x1178, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10178_fun1180__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_char_t _y_x10139;
  kk_char_t l;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10178_fun1180(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10178_fun1180(kk_std_time_locale__time_locale locale, kk_char_t _y_x10139, kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10178_fun1180__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_l_10178_fun1180__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_l_10178_fun1180, kk_context());
  _self->locale = locale;
  _self->_y_x10139 = _y_x10139;
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10178_fun1180(kk_function_t _fself, kk_box_t _b_x121, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10178_fun1180__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_l_10178_fun1180__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_char_t _y_x10139 = _self->_y_x10139; /* char */
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_skip_dup(_y_x10139, _ctx);kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10141_123 = kk_std_core_types__list_unbox(_b_x121, KK_OWNED, _ctx); /*list<char>*/;
  kk_string_t _x_x1181 = kk_std_time_format__mlift_plocale_l_10177(_y_x10139, l, locale, _y_x10141_123, _ctx); /*string*/
  return kk_string_box(_x_x1181);
}

kk_string_t kk_std_time_format__mlift_plocale_l_10178(kk_char_t l, kk_std_time_locale__time_locale locale, kk_char_t _y_x10139, kk_context_t* _ctx) { /* (l : char, locale : std/time/locale/time-locale, char) -> std/text/parse/parse string */ 
  kk_std_core_types__list x_10217 = kk_std_text_parse_many_acc(kk_std_time_format__new_mlift_plocale_l_10178_fun1177(l, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10217, _ctx);
    kk_box_t _x_x1179 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_l_10178_fun1180(locale, _y_x10139, l, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1179);
  }
  {
    return kk_std_time_format__mlift_plocale_l_10177(_y_x10139, l, locale, x_10217, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1183__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_char_t l;
};
static kk_box_t kk_std_time_format_plocale_l_fun1183(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1183(kk_std_time_locale__time_locale locale, kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1183__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun1183__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun1183, kk_context());
  _self->locale = locale;
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1183(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1183__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun1183__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_char_t _y_x10139_165 = kk_char_unbox(_b_x125, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1184 = kk_std_time_format__mlift_plocale_l_10178(l, locale, _y_x10139_165, _ctx); /*string*/
  return kk_string_box(_x_x1184);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1185__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format_plocale_l_fun1185(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1185(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1185__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun1185__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun1185, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1185(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1185__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun1185__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_char_t _x_x1186 = kk_std_text_parse_char(l, _ctx); /*char*/
  return kk_char_box(_x_x1186, _ctx);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1188__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_char_t l;
  kk_char_t x_10219;
};
static kk_box_t kk_std_time_format_plocale_l_fun1188(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1188(kk_std_time_locale__time_locale locale, kk_char_t l, kk_char_t x_10219, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1188__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun1188__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun1188, kk_context());
  _self->locale = locale;
  _self->l = l;
  _self->x_10219 = x_10219;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1188(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1188__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun1188__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_char_t l = _self->l; /* char */
  kk_char_t x_10219 = _self->x_10219; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_skip_dup(l, _ctx);kk_skip_dup(x_10219, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10141_166 = kk_std_core_types__list_unbox(_b_x131, KK_OWNED, _ctx); /*list<char>*/;
  kk_string_t _x_x1189 = kk_std_time_format__mlift_plocale_l_10177(x_10219, l, locale, _y_x10141_166, _ctx); /*string*/
  return kk_string_box(_x_x1189);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_l_fun1192(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_l_fun1192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1192(kk_function_t _fself, kk_box_t _b_x138, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1193;
  kk_std_time_locale__time_locale _match_x790 = kk_std_time_locale__time_locale_unbox(_b_x138, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1194 = kk_std_time_locale__as_Time_locale(_match_x790, _ctx);
    kk_string_t _pat_0_0_0 = _con_x1194->lang_name;
    kk_std_core_types__list _pat_1_0 = _con_x1194->day_names;
    kk_std_core_types__list _pat_2_0 = _con_x1194->month_names;
    kk_std_core_types__list _pat_3_0 = _con_x1194->month_names_short;
    kk_std_core_types__list _pat_4 = _con_x1194->day_names_short;
    kk_std_core_types__list _pat_5 = _con_x1194->day_names_min;
    kk_string_t _pat_6 = _con_x1194->format_t;
    kk_string_t _pat_7 = _con_x1194->format_tt;
    kk_string_t _pat_8 = _con_x1194->format_l;
    kk_string_t _pat_9 = _con_x1194->format_ll;
    kk_string_t _pat_10 = _con_x1194->format_lll;
    kk_string_t _x = _con_x1194->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x790, _ctx)) {
      kk_string_drop(_pat_9, _ctx);
      kk_string_drop(_pat_8, _ctx);
      kk_string_drop(_pat_7, _ctx);
      kk_string_drop(_pat_6, _ctx);
      kk_std_core_types__list_drop(_pat_5, _ctx);
      kk_std_core_types__list_drop(_pat_4, _ctx);
      kk_std_core_types__list_drop(_pat_3_0, _ctx);
      kk_std_core_types__list_drop(_pat_2_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_10, _ctx);
      kk_string_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(_match_x790, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x790, _ctx);
    }
    _x_x1193 = _x; /*string*/
  }
  return kk_string_box(_x_x1193);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1195__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_l_fun1195(kk_function_t _fself, kk_box_t _b_x141, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1195(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_l_fun1195, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1195(kk_function_t _fself, kk_box_t _b_x141, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1196;
  kk_std_time_locale__time_locale _match_x789 = kk_std_time_locale__time_locale_unbox(_b_x141, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1197 = kk_std_time_locale__as_Time_locale(_match_x789, _ctx);
    kk_string_t _pat_0_2_0 = _con_x1197->lang_name;
    kk_std_core_types__list _pat_1_1 = _con_x1197->day_names;
    kk_std_core_types__list _pat_2_0_0 = _con_x1197->month_names;
    kk_std_core_types__list _pat_3_0_0 = _con_x1197->month_names_short;
    kk_std_core_types__list _pat_4_0 = _con_x1197->day_names_short;
    kk_std_core_types__list _pat_5_0 = _con_x1197->day_names_min;
    kk_string_t _pat_6_0 = _con_x1197->format_t;
    kk_string_t _pat_7_0 = _con_x1197->format_tt;
    kk_string_t _pat_8_0 = _con_x1197->format_l;
    kk_string_t _pat_9_0 = _con_x1197->format_ll;
    kk_string_t _x_0 = _con_x1197->format_lll;
    kk_string_t _pat_10_0 = _con_x1197->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x789, _ctx)) {
      kk_string_drop(_pat_9_0, _ctx);
      kk_string_drop(_pat_8_0, _ctx);
      kk_string_drop(_pat_7_0, _ctx);
      kk_string_drop(_pat_6_0, _ctx);
      kk_std_core_types__list_drop(_pat_5_0, _ctx);
      kk_std_core_types__list_drop(_pat_4_0, _ctx);
      kk_std_core_types__list_drop(_pat_3_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_2_0_0, _ctx);
      kk_std_core_types__list_drop(_pat_1_1, _ctx);
      kk_string_drop(_pat_10_0, _ctx);
      kk_string_drop(_pat_0_2_0, _ctx);
      kk_datatype_ptr_free(_match_x789, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(_match_x789, _ctx);
    }
    _x_x1196 = _x_0; /*string*/
  }
  return kk_string_box(_x_x1196);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1198__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_l_fun1198(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1198(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_l_fun1198, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1198(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1199;
  kk_std_time_locale__time_locale _match_x787 = kk_std_time_locale__time_locale_unbox(_b_x144, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1200 = kk_std_time_locale__as_Time_locale(_match_x787, _ctx);
    kk_string_t _pat_0_3 = _con_x1200->lang_name;
    kk_std_core_types__list _pat_1_2 = _con_x1200->day_names;
    kk_std_core_types__list _pat_2_2 = _con_x1200->month_names;
    kk_std_core_types__list _pat_3_2 = _con_x1200->month_names_short;
    kk_std_core_types__list _pat_4_1 = _con_x1200->day_names_short;
    kk_std_core_types__list _pat_5_1 = _con_x1200->day_names_min;
    kk_string_t _pat_6_1 = _con_x1200->format_t;
    kk_string_t _pat_7_1 = _con_x1200->format_tt;
    kk_string_t _pat_8_1 = _con_x1200->format_l;
    kk_string_t _x_1 = _con_x1200->format_ll;
    kk_string_t _pat_9_1 = _con_x1200->format_lll;
    kk_string_t _pat_10_1 = _con_x1200->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x787, _ctx)) {
      kk_string_drop(_pat_9_1, _ctx);
      kk_string_drop(_pat_8_1, _ctx);
      kk_string_drop(_pat_7_1, _ctx);
      kk_string_drop(_pat_6_1, _ctx);
      kk_std_core_types__list_drop(_pat_5_1, _ctx);
      kk_std_core_types__list_drop(_pat_4_1, _ctx);
      kk_std_core_types__list_drop(_pat_3_2, _ctx);
      kk_std_core_types__list_drop(_pat_2_2, _ctx);
      kk_std_core_types__list_drop(_pat_1_2, _ctx);
      kk_string_drop(_pat_10_1, _ctx);
      kk_string_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(_match_x787, _ctx);
    }
    else {
      kk_string_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(_match_x787, _ctx);
    }
    _x_x1199 = _x_1; /*string*/
  }
  return kk_string_box(_x_x1199);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1201__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_l_fun1201(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1201(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_l_fun1201, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1201(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1202;
  kk_std_time_locale__time_locale _match_x786 = kk_std_time_locale__time_locale_unbox(_b_x147, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1203 = kk_std_time_locale__as_Time_locale(_match_x786, _ctx);
    kk_string_t _pat_0_4 = _con_x1203->lang_name;
    kk_std_core_types__list _pat_1_3 = _con_x1203->day_names;
    kk_std_core_types__list _pat_2_3 = _con_x1203->month_names;
    kk_std_core_types__list _pat_3_3 = _con_x1203->month_names_short;
    kk_std_core_types__list _pat_4_3 = _con_x1203->day_names_short;
    kk_std_core_types__list _pat_5_2 = _con_x1203->day_names_min;
    kk_string_t _pat_6_2 = _con_x1203->format_t;
    kk_string_t _pat_7_2 = _con_x1203->format_tt;
    kk_string_t _x_2 = _con_x1203->format_l;
    kk_string_t _pat_8_2 = _con_x1203->format_ll;
    kk_string_t _pat_9_2 = _con_x1203->format_lll;
    kk_string_t _pat_10_2 = _con_x1203->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x786, _ctx)) {
      kk_string_drop(_pat_9_2, _ctx);
      kk_string_drop(_pat_8_2, _ctx);
      kk_string_drop(_pat_7_2, _ctx);
      kk_string_drop(_pat_6_2, _ctx);
      kk_std_core_types__list_drop(_pat_5_2, _ctx);
      kk_std_core_types__list_drop(_pat_4_3, _ctx);
      kk_std_core_types__list_drop(_pat_3_3, _ctx);
      kk_std_core_types__list_drop(_pat_2_3, _ctx);
      kk_std_core_types__list_drop(_pat_1_3, _ctx);
      kk_string_drop(_pat_10_2, _ctx);
      kk_string_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(_match_x786, _ctx);
    }
    else {
      kk_string_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(_match_x786, _ctx);
    }
    _x_x1202 = _x_2; /*string*/
  }
  return kk_string_box(_x_x1202);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun1205__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format_plocale_l_fun1205(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun1205(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1205__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun1205__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun1205, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun1205(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun1205__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun1205__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_string_t _c_x10144_167 = kk_string_unbox(_b_x161); /*string*/;
  kk_string_t _x_x1206 = kk_std_time_format__mlift_plocale_l_10176(l, _c_x10144_167, _ctx); /*string*/
  return kk_string_box(_x_x1206);
}

kk_string_t kk_std_time_format_plocale_l(kk_std_time_locale__time_locale locale, kk_char_t l, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale, l : char) -> std/text/parse/parse string */ 
  kk_char_t x_10219 = kk_std_text_parse_char(l, _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1182 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_l_fun1183(locale, l, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1182);
  }
  {
    kk_std_core_types__list x_0_10222 = kk_std_text_parse_many_acc(kk_std_time_format_new_plocale_l_fun1185(l, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_10222, _ctx);
      kk_box_t _x_x1187 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_l_fun1188(locale, l, x_10219, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x1187);
    }
    {
      kk_integer_t n;
      kk_std_core_types__list _x_x1190 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(x_10219, _ctx), x_0_10222, _ctx); /*list<79>*/
      n = kk_std_core_list__lift_length_5730(_x_x1190, kk_integer_from_small(0), _ctx); /*int*/
      kk_string_t x_1_10225;
      kk_box_t _x_x1191;
      bool _match_x783 = kk_integer_gte_borrow(n,(kk_integer_from_small(4)),kk_context()); /*bool*/;
      if (_match_x783) {
        kk_integer_drop(n, _ctx);
        _x_x1191 = kk_std_core_hnd__open_none1(kk_std_time_format_new_plocale_l_fun1192(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
      }
      else {
        bool _match_x784 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        if (_match_x784) {
          kk_integer_drop(n, _ctx);
          _x_x1191 = kk_std_core_hnd__open_none1(kk_std_time_format_new_plocale_l_fun1195(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
        }
        else {
          bool _match_x785;
          bool _brw_x788 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
          kk_integer_drop(n, _ctx);
          _match_x785 = _brw_x788; /*bool*/
          if (_match_x785) {
            _x_x1191 = kk_std_core_hnd__open_none1(kk_std_time_format_new_plocale_l_fun1198(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
          }
          else {
            _x_x1191 = kk_std_core_hnd__open_none1(kk_std_time_format_new_plocale_l_fun1201(_ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx); /*9904*/
          }
        }
      }
      x_1_10225 = kk_string_unbox(_x_x1191); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10225, _ctx);
        kk_box_t _x_x1204 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_l_fun1205(l, _ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x1204);
      }
      {
        bool _match_x782 = (l == ('L')); /*bool*/;
        if (_match_x782) {
          return x_1_10225;
        }
        {
          kk_string_t _x_x1207;
          kk_string_t _x_x1208;
          kk_string_t _x_x1209;
          kk_string_t _x_x1210;
          kk_string_t _x_x1211;
          kk_string_t _x_x1212;
          kk_define_string_literal(, _s_x1213, 2, "dd", _ctx)
          _x_x1212 = kk_string_dup(_s_x1213, _ctx); /*string*/
          kk_string_t _x_x1214;
          kk_define_string_literal(, _s_x1215, 1, "d", _ctx)
          _x_x1214 = kk_string_dup(_s_x1215, _ctx); /*string*/
          _x_x1211 = kk_string_replace_all(x_1_10225,_x_x1212,_x_x1214,kk_context()); /*string*/
          kk_string_t _x_x1216;
          kk_define_string_literal(, _s_x1217, 2, "dd", _ctx)
          _x_x1216 = kk_string_dup(_s_x1217, _ctx); /*string*/
          kk_string_t _x_x1218;
          kk_define_string_literal(, _s_x1219, 3, "ddd", _ctx)
          _x_x1218 = kk_string_dup(_s_x1219, _ctx); /*string*/
          _x_x1210 = kk_string_replace_all(_x_x1211,_x_x1216,_x_x1218,kk_context()); /*string*/
          kk_string_t _x_x1220;
          kk_define_string_literal(, _s_x1221, 2, "MM", _ctx)
          _x_x1220 = kk_string_dup(_s_x1221, _ctx); /*string*/
          kk_string_t _x_x1222;
          kk_define_string_literal(, _s_x1223, 1, "M", _ctx)
          _x_x1222 = kk_string_dup(_s_x1223, _ctx); /*string*/
          _x_x1209 = kk_string_replace_all(_x_x1210,_x_x1220,_x_x1222,kk_context()); /*string*/
          kk_string_t _x_x1224;
          kk_define_string_literal(, _s_x1225, 2, "MM", _ctx)
          _x_x1224 = kk_string_dup(_s_x1225, _ctx); /*string*/
          kk_string_t _x_x1226;
          kk_define_string_literal(, _s_x1227, 3, "MMM", _ctx)
          _x_x1226 = kk_string_dup(_s_x1227, _ctx); /*string*/
          _x_x1208 = kk_string_replace_all(_x_x1209,_x_x1224,_x_x1226,kk_context()); /*string*/
          kk_string_t _x_x1228;
          kk_define_string_literal(, _s_x1229, 2, "DD", _ctx)
          _x_x1228 = kk_string_dup(_s_x1229, _ctx); /*string*/
          kk_string_t _x_x1230;
          kk_define_string_literal(, _s_x1231, 1, "D", _ctx)
          _x_x1230 = kk_string_dup(_s_x1231, _ctx); /*string*/
          _x_x1207 = kk_string_replace_all(_x_x1208,_x_x1228,_x_x1230,kk_context()); /*string*/
          kk_string_t _x_x1232;
          kk_define_string_literal(, _s_x1233, 2, "DD", _ctx)
          _x_x1232 = kk_string_dup(_s_x1233, _ctx); /*string*/
          kk_string_t _x_x1234;
          kk_define_string_literal(, _s_x1235, 3, "DDD", _ctx)
          _x_x1234 = kk_string_dup(_s_x1235, _ctx); /*string*/
          return kk_string_replace_all(_x_x1207,_x_x1232,_x_x1234,kk_context());
        }
      }
    }
  }
}


// lift anonymous function
struct kk_std_time_format_plocale_fun1238__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun1238(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun1238(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun1238, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun1238(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1239;
  kk_string_t _x_x1240;
  kk_define_string_literal(, _s_x1241, 5, "\'\"tLl", _ctx)
  _x_x1240 = kk_string_dup(_s_x1241, _ctx); /*string*/
  _x_x1239 = kk_std_text_parse_none_of_many1(_x_x1240, _ctx); /*string*/
  return kk_string_box(_x_x1239);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun1243__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun1243(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun1243(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun1243, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun1243(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1244 = kk_std_time_format_pquoted('\'', _ctx); /*string*/
  return kk_string_box(_x_x1244);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun1246__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun1246(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun1246(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun1246, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun1246(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1247 = kk_std_time_format_pquoted('"', _ctx); /*string*/
  return kk_string_box(_x_x1247);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun1251__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_fun1251(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun1251(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun1251__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_fun1251__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_fun1251, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun1251(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun1251__t* _self = kk_function_as(struct kk_std_time_format_plocale_fun1251__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x1252 = kk_std_time_format_plocale_t(locale, _ctx); /*string*/
  return kk_string_box(_x_x1252);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun1256__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_fun1256(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun1256(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun1256__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_fun1256__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_fun1256, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun1256(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun1256__t* _self = kk_function_as(struct kk_std_time_format_plocale_fun1256__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x1257 = kk_std_time_format_plocale_l(locale, 'L', _ctx); /*string*/
  return kk_string_box(_x_x1257);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun1259__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_fun1259(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun1259(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun1259__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_fun1259__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_fun1259, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun1259(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun1259__t* _self = kk_function_as(struct kk_std_time_format_plocale_fun1259__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x1260 = kk_std_time_format_plocale_l(locale, 'l', _ctx); /*string*/
  return kk_string_box(_x_x1260);
}

kk_string_t kk_std_time_format_plocale(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
  kk_box_t _x_x1236;
  kk_std_core_types__list _x_x1237;
  kk_std_core_types__list _x_x1242;
  kk_std_core_types__list _x_x1245;
  kk_std_core_types__list _x_x1248;
  kk_box_t _x_x1249;
  kk_function_t _x_x1250;
  kk_std_time_locale__time_locale_dup(locale, _ctx);
  _x_x1250 = kk_std_time_format_new_plocale_fun1251(locale, _ctx); /*() -> std/text/parse/parse 176*/
  _x_x1249 = kk_function_box(_x_x1250, _ctx); /*79*/
  kk_std_core_types__list _x_x1253;
  kk_box_t _x_x1254;
  kk_function_t _x_x1255;
  kk_std_time_locale__time_locale_dup(locale, _ctx);
  _x_x1255 = kk_std_time_format_new_plocale_fun1256(locale, _ctx); /*() -> std/text/parse/parse 173*/
  _x_x1254 = kk_function_box(_x_x1255, _ctx); /*79*/
  kk_std_core_types__list _x_x1258 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun1259(locale, _ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
  _x_x1253 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1254, _x_x1258, _ctx); /*list<79>*/
  _x_x1248 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1249, _x_x1253, _ctx); /*list<79>*/
  _x_x1245 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun1246(_ctx), _ctx), _x_x1248, _ctx); /*list<79>*/
  _x_x1242 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun1243(_ctx), _ctx), _x_x1245, _ctx); /*list<79>*/
  _x_x1237 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun1238(_ctx), _ctx), _x_x1242, _ctx); /*list<79>*/
  _x_x1236 = kk_std_text_parse_choose(_x_x1237, _ctx); /*1639*/
  return kk_string_unbox(_x_x1236);
}


// lift anonymous function
struct kk_std_time_format_plocales_fun1261__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocales_fun1261(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocales_fun1261(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocales_fun1261__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocales_fun1261__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocales_fun1261, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocales_fun1261(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocales_fun1261__t* _self = kk_function_as(struct kk_std_time_format_plocales_fun1261__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x1262 = kk_std_time_format_plocale(locale, _ctx); /*string*/
  return kk_string_box(_x_x1262);
}


// lift anonymous function
struct kk_std_time_format_plocales_fun1264__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocales_fun1264(kk_function_t _fself, kk_box_t _b_x205, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocales_fun1264(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocales_fun1264, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocales_fun1264(kk_function_t _fself, kk_box_t _b_x205, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1265;
  kk_std_core_types__list _x_x1266 = kk_std_core_types__list_unbox(_b_x205, KK_OWNED, _ctx); /*list<string>*/
  _x_x1265 = kk_std_core_list_concat_fs_join(_x_x1266, _ctx); /*string*/
  return kk_string_box(_x_x1265);
}

kk_string_t kk_std_time_format_plocales(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
  kk_std_core_types__list x_10228 = kk_std_text_parse_many_acc(kk_std_time_format_new_plocales_fun1261(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10228, _ctx);
    kk_box_t _x_x1263 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocales_fun1264(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1263);
  }
  {
    return kk_std_core_list_concat_fs_join(x_10228, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_expand_locales_10180_fun1268__t {
  struct kk_function_s _base;
  kk_string_t x_1;
};
static kk_box_t kk_std_time_format__mlift_expand_locales_10180_fun1268(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_expand_locales_10180_fun1268(kk_string_t x_1, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_expand_locales_10180_fun1268__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_expand_locales_10180_fun1268__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_expand_locales_10180_fun1268, kk_context());
  _self->x_1 = x_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_expand_locales_10180_fun1268(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_expand_locales_10180_fun1268__t* _self = kk_function_as(struct kk_std_time_format__mlift_expand_locales_10180_fun1268__t*, _fself, _ctx);
  kk_string_t x_1 = _self->x_1; /* string */
  kk_drop_match(_self, {kk_string_dup(x_1, _ctx);}, {}, _ctx)
  kk_unit_t wild___210 = kk_Unit;
  kk_unit_unbox(_b_x208);
  return kk_string_box(x_1);
}

kk_string_t kk_std_time_format__mlift_expand_locales_10180(kk_std_core_types__list _y_x10156, kk_context_t* _ctx) { /* (list<string>) -> std/text/parse/parse string */ 
  kk_string_t x_1 = kk_std_core_list_concat_fs_join(_y_x10156, _ctx); /*string*/;
  kk_unit_t x_10230 = kk_Unit;
  kk_std_text_parse_eof(_ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1267 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_expand_locales_10180_fun1268(x_1, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1267);
  }
  {
    return x_1;
  }
}


// lift anonymous function
struct kk_std_time_format_expand_locales_fun1272__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_expand_locales_fun1272(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_expand_locales_fun1272(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_expand_locales_fun1272__t* _self = kk_function_alloc_as(struct kk_std_time_format_expand_locales_fun1272__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_expand_locales_fun1272, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_expand_locales_fun1273__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_expand_locales_fun1273(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_expand_locales_fun1273(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_expand_locales_fun1273__t* _self = kk_function_alloc_as(struct kk_std_time_format_expand_locales_fun1273__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_expand_locales_fun1273, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_expand_locales_fun1273(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_expand_locales_fun1273__t* _self = kk_function_as(struct kk_std_time_format_expand_locales_fun1273__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x1274 = kk_std_time_format_plocale(locale, _ctx); /*string*/
  return kk_string_box(_x_x1274);
}


// lift anonymous function
struct kk_std_time_format_expand_locales_fun1277__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_expand_locales_fun1277(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_expand_locales_fun1277(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_expand_locales_fun1277, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_expand_locales_fun1277(kk_function_t _fself, kk_box_t _b_x216, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1278;
  kk_std_core_types__list _x_x1279 = kk_std_core_types__list_unbox(_b_x216, KK_OWNED, _ctx); /*list<string>*/
  _x_x1278 = kk_std_time_format__mlift_expand_locales_10180(_x_x1279, _ctx); /*string*/
  return kk_string_box(_x_x1278);
}
static kk_box_t kk_std_time_format_expand_locales_fun1272(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_expand_locales_fun1272__t* _self = kk_function_as(struct kk_std_time_format_expand_locales_fun1272__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_10234 = kk_std_text_parse_many_acc(kk_std_time_format_new_expand_locales_fun1273(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x1275;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10234, _ctx);
    kk_box_t _x_x1276 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_expand_locales_fun1277(_ctx), _ctx); /*2419*/
    _x_x1275 = kk_string_unbox(_x_x1276); /*string*/
  }
  else {
    _x_x1275 = kk_std_time_format__mlift_expand_locales_10180(x_10234, _ctx); /*string*/
  }
  return kk_string_box(_x_x1275);
}

kk_string_t kk_std_time_format_expand_locales(kk_string_t fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (fmt : string, locale : std/time/locale/time-locale) -> string */ 
  kk_std_core_sslice__sslice input_10025;
  kk_string_t _x_x1269 = kk_string_dup(fmt, _ctx); /*string*/
  kk_integer_t _x_x1270;
  kk_string_t _x_x1271 = kk_string_dup(fmt, _ctx); /*string*/
  _x_x1270 = kk_string_len_int(_x_x1271,kk_context()); /*int*/
  input_10025 = kk_std_core_sslice__new_Sslice(_x_x1269, kk_integer_from_small(0), _x_x1270, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10024 = kk_std_text_parse_parse(input_10025, kk_std_time_format_new_expand_locales_fun1272(locale, _ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10024, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x1280 = kk_std_text_parse__as_ParseOk(perr_10024, _ctx);
    kk_box_t _box_x222 = _con_x1280->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x1280->rest;
    kk_string_t x_0 = kk_string_unbox(_box_x222);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10024, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(perr_10024, _ctx);
    }
    else {
      kk_string_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_10024, _ctx);
    }
    kk_string_drop(fmt, _ctx);
    return x_0;
  }
  {
    struct kk_std_text_parse_ParseError* _con_x1281 = kk_std_text_parse__as_ParseError(perr_10024, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x1281->rest;
    kk_string_t msg = _con_x1281->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10024, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10024, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10024, _ctx);
    }
    return fmt;
  }
}

kk_string_t kk_std_time_format_showl(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx) { /* (i : int, width : ? int) -> string */ 
  kk_string_t _own_x774 = kk_std_core_int_show(i, _ctx); /*string*/;
  kk_integer_t _brw_x773;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x224 = width._cons._Optional.value;
    kk_integer_t _uniq_width_1750 = kk_integer_unbox(_box_x224, _ctx);
    kk_integer_dup(_uniq_width_1750, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x773 = _uniq_width_1750; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x773 = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _brw_x775;
  kk_std_core_types__optional _x_x1282 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
  _brw_x775 = kk_std_core_string_pad_left(_own_x774, _brw_x773, _x_x1282, _ctx); /*string*/
  kk_integer_drop(_brw_x773, _ctx);
  return _brw_x775;
}

kk_string_t kk_std_time_format_format_day(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x768 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
  if (_match_x768) {
    kk_integer_drop(n, _ctx);
    kk_integer_t i_10028 = kk_std_time_time_day_of_year(t, _ctx); /*int*/;
    kk_string_t _own_x772 = kk_std_core_int_show(i_10028, _ctx); /*string*/;
    kk_std_core_types__optional _x_x1283 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    return kk_std_core_string_pad_left(_own_x772, kk_integer_from_small(3), _x_x1283, _ctx);
  }
  {
    bool _match_x769;
    kk_string_t _x_x1284;
    {
      struct kk_std_time_time_Time* _con_x1285 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x1285->date;
      kk_std_time_date__clock _pat_4_0 = _con_x1285->clock;
      kk_std_time_calendar__calendar _x_0 = _con_x1285->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x1285->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x1285->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1285->instant;
      struct kk_std_time_date_Clock* _con_x1286 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1287 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1288 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_calendar__calendar_dup(_x_0, _ctx);
      {
        struct kk_std_time_calendar_Calendar* _con_x1289 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
        kk_string_t _pat_0_2 = _con_x1289->name;
        kk_string_t _pat_1_0 = _con_x1289->long_name;
        kk_string_t _x = _con_x1289->month_prefix;
        kk_function_t _pat_2 = _con_x1289->show_era;
        kk_function_t _pat_3 = _con_x1289->instant_to_dc;
        kk_function_t _pat_4 = _con_x1289->dc_to_instant;
        kk_function_t _pat_5 = _con_x1289->days_to_date;
        kk_function_t _pat_6 = _con_x1289->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
          kk_function_drop(_pat_6, _ctx);
          kk_function_drop(_pat_5, _ctx);
          kk_function_drop(_pat_4, _ctx);
          kk_function_drop(_pat_3, _ctx);
          kk_function_drop(_pat_2, _ctx);
          kk_string_drop(_pat_1_0, _ctx);
          kk_string_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(_x_0, _ctx);
        }
        else {
          kk_string_dup(_x, _ctx);
          kk_datatype_ptr_decref(_x_0, _ctx);
        }
        _x_x1284 = _x; /*string*/
      }
    }
    kk_string_t _x_x1290;
    kk_define_string_literal(, _s_x1291, 1, "W", _ctx)
    _x_x1290 = kk_string_dup(_s_x1291, _ctx); /*string*/
    _match_x769 = kk_string_is_eq(_x_x1284,_x_x1290,kk_context()); /*bool*/
    if (_match_x769) {
      kk_integer_drop(n, _ctx);
      kk_integer_t _x_x1292;
      {
        struct kk_std_time_time_Time* _con_x1293 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_0 = _con_x1293->date;
        kk_std_time_date__clock _pat_3_1 = _con_x1293->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x1293->calendar;
        kk_std_time_duration__duration _pat_16_0 = _con_x1293->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0 = _con_x1293->timezone;
        kk_std_time_instant__instant _pat_23_0 = _con_x1293->instant;
        struct kk_std_time_date_Clock* _con_x1294 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1295 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1296 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
        kk_string_t _pat_18_0 = _con_x1293->tzabbrv;
        kk_integer_t _pat_4_1 = _con_x1294->hours;
        kk_integer_t _pat_5_1 = _con_x1294->minutes;
        kk_string_t _pat_8_0 = _con_x1295->name;
        kk_string_t _pat_9_0 = _con_x1295->long_name;
        kk_string_t _pat_10_0 = _con_x1295->month_prefix;
        kk_function_t _pat_11_0 = _con_x1295->show_era;
        kk_function_t _pat_12_0 = _con_x1295->instant_to_dc;
        kk_function_t _pat_13_0 = _con_x1295->dc_to_instant;
        kk_function_t _pat_14_0 = _con_x1295->days_to_date;
        kk_function_t _pat_15_0 = _con_x1295->date_to_days;
        kk_string_t _pat_20_0 = _con_x1296->name;
        kk_function_t _pat_21_0 = _con_x1296->utc_delta;
        kk_function_t _pat_22_0 = _con_x1296->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1, _ctx)) {
            kk_string_drop(_pat_9_0, _ctx);
            kk_string_drop(_pat_8_0, _ctx);
            kk_function_drop(_pat_15_0, _ctx);
            kk_function_drop(_pat_14_0, _ctx);
            kk_function_drop(_pat_13_0, _ctx);
            kk_function_drop(_pat_12_0, _ctx);
            kk_function_drop(_pat_11_0, _ctx);
            kk_string_drop(_pat_10_0, _ctx);
            kk_datatype_ptr_free(_pat_7_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_integer_drop(_pat_5_1, _ctx);
            kk_integer_drop(_pat_4_1, _ctx);
            kk_datatype_ptr_free(_pat_3_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_1, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0, _ctx)) {
            kk_function_drop(_pat_22_0, _ctx);
            kk_function_drop(_pat_21_0, _ctx);
            kk_string_drop(_pat_20_0, _ctx);
            kk_datatype_ptr_free(_pat_19_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_0, _ctx);
          }
          kk_string_drop(_pat_18_0, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_0_0, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_1 = _x_0_0.day;
          kk_integer_dup(_x_1, _ctx);
          kk_std_time_date__date_drop(_x_0_0, _ctx);
          _x_x1292 = _x_1; /*int*/
        }
      }
      return kk_std_core_int_show(_x_x1292, _ctx);
    }
    {
      kk_string_t _own_x770;
      kk_integer_t _x_x1297;
      {
        struct kk_std_time_time_Time* _con_x1298 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_1 = _con_x1298->date;
        kk_std_time_date__clock _pat_3_2 = _con_x1298->clock;
        kk_std_time_calendar__calendar _pat_7_2 = _con_x1298->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x1298->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x1298->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x1298->instant;
        struct kk_std_time_date_Clock* _con_x1299 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1300 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1301 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_string_t _pat_18_1 = _con_x1298->tzabbrv;
        kk_integer_t _pat_4_2 = _con_x1299->hours;
        kk_integer_t _pat_5_2 = _con_x1299->minutes;
        kk_string_t _pat_8_1 = _con_x1300->name;
        kk_string_t _pat_9_1 = _con_x1300->long_name;
        kk_string_t _pat_10_1 = _con_x1300->month_prefix;
        kk_function_t _pat_11_1 = _con_x1300->show_era;
        kk_function_t _pat_12_1 = _con_x1300->instant_to_dc;
        kk_function_t _pat_13_1 = _con_x1300->dc_to_instant;
        kk_function_t _pat_14_1 = _con_x1300->days_to_date;
        kk_function_t _pat_15_1 = _con_x1300->date_to_days;
        kk_string_t _pat_20_1 = _con_x1301->name;
        kk_function_t _pat_21_1 = _con_x1301->utc_delta;
        kk_function_t _pat_22_1 = _con_x1301->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_2, _ctx)) {
            kk_string_drop(_pat_9_1, _ctx);
            kk_string_drop(_pat_8_1, _ctx);
            kk_function_drop(_pat_15_1, _ctx);
            kk_function_drop(_pat_14_1, _ctx);
            kk_function_drop(_pat_13_1, _ctx);
            kk_function_drop(_pat_12_1, _ctx);
            kk_function_drop(_pat_11_1, _ctx);
            kk_string_drop(_pat_10_1, _ctx);
            kk_datatype_ptr_free(_pat_7_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_2, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_2, _ctx)) {
            kk_integer_drop(_pat_5_2, _ctx);
            kk_integer_drop(_pat_4_2, _ctx);
            kk_datatype_ptr_free(_pat_3_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_2, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_1, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_1, _ctx)) {
            kk_function_drop(_pat_22_1, _ctx);
            kk_function_drop(_pat_21_1, _ctx);
            kk_string_drop(_pat_20_1, _ctx);
            kk_datatype_ptr_free(_pat_19_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_1, _ctx);
          }
          kk_string_drop(_pat_18_1, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_0_1, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_2 = _x_0_1.day;
          kk_integer_dup(_x_2, _ctx);
          kk_std_time_date__date_drop(_x_0_1, _ctx);
          _x_x1297 = _x_2; /*int*/
        }
      }
      _own_x770 = kk_std_core_int_show(_x_x1297, _ctx); /*string*/
      kk_string_t _brw_x771;
      kk_std_core_types__optional _x_x1302 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
      _brw_x771 = kk_std_core_string_pad_left(_own_x770, n, _x_x1302, _ctx); /*string*/
      kk_integer_drop(n, _ctx);
      return _brw_x771;
    }
  }
}

kk_string_t kk_std_time_format_format_month(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  bool _match_x762 = kk_integer_lte_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  if (_match_x762) {
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    kk_char_t _b_x231_235 = '0'; /*char*/;
    kk_string_t _x_x1303;
    {
      struct kk_std_time_time_Time* _con_x1304 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_1 = _con_x1304->date;
      kk_std_time_date__clock _pat_4_0 = _con_x1304->clock;
      kk_std_time_calendar__calendar _x_0 = _con_x1304->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x1304->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x1304->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1304->instant;
      struct kk_std_time_date_Clock* _con_x1305 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1306 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1307 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_calendar__calendar_dup(_x_0, _ctx);
      {
        struct kk_std_time_calendar_Calendar* _con_x1308 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
        kk_string_t _pat_0_0 = _con_x1308->name;
        kk_string_t _pat_1 = _con_x1308->long_name;
        kk_string_t _x = _con_x1308->month_prefix;
        kk_function_t _pat_2 = _con_x1308->show_era;
        kk_function_t _pat_3 = _con_x1308->instant_to_dc;
        kk_function_t _pat_4 = _con_x1308->dc_to_instant;
        kk_function_t _pat_5 = _con_x1308->days_to_date;
        kk_function_t _pat_6 = _con_x1308->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
          kk_function_drop(_pat_6, _ctx);
          kk_function_drop(_pat_5, _ctx);
          kk_function_drop(_pat_4, _ctx);
          kk_function_drop(_pat_3, _ctx);
          kk_function_drop(_pat_2, _ctx);
          kk_string_drop(_pat_1, _ctx);
          kk_string_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(_x_0, _ctx);
        }
        else {
          kk_string_dup(_x, _ctx);
          kk_datatype_ptr_decref(_x_0, _ctx);
        }
        _x_x1303 = _x; /*string*/
      }
    }
    kk_string_t _x_x1309;
    kk_string_t _own_x766;
    kk_integer_t _x_x1310;
    {
      struct kk_std_time_time_Time* _con_x1311 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_0 = _con_x1311->date;
      kk_std_time_date__clock _pat_3_1 = _con_x1311->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x1311->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1311->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1311->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1311->instant;
      struct kk_std_time_date_Clock* _con_x1312 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1313 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1314 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_string_t _pat_18_0 = _con_x1311->tzabbrv;
      kk_integer_t _pat_4_1 = _con_x1312->hours;
      kk_integer_t _pat_5_1 = _con_x1312->minutes;
      kk_string_t _pat_8_0 = _con_x1313->name;
      kk_string_t _pat_9_0 = _con_x1313->long_name;
      kk_string_t _pat_10_0 = _con_x1313->month_prefix;
      kk_function_t _pat_11_0 = _con_x1313->show_era;
      kk_function_t _pat_12_0 = _con_x1313->instant_to_dc;
      kk_function_t _pat_13_0 = _con_x1313->dc_to_instant;
      kk_function_t _pat_14_0 = _con_x1313->days_to_date;
      kk_function_t _pat_15_0 = _con_x1313->date_to_days;
      kk_string_t _pat_20_0 = _con_x1314->name;
      kk_function_t _pat_21_0 = _con_x1314->utc_delta;
      kk_function_t _pat_22_0 = _con_x1314->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1, _ctx)) {
          kk_string_drop(_pat_9_0, _ctx);
          kk_string_drop(_pat_8_0, _ctx);
          kk_function_drop(_pat_15_0, _ctx);
          kk_function_drop(_pat_14_0, _ctx);
          kk_function_drop(_pat_13_0, _ctx);
          kk_function_drop(_pat_12_0, _ctx);
          kk_function_drop(_pat_11_0, _ctx);
          kk_string_drop(_pat_10_0, _ctx);
          kk_datatype_ptr_free(_pat_7_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_7_1, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
          kk_integer_drop(_pat_5_1, _ctx);
          kk_integer_drop(_pat_4_1, _ctx);
          kk_datatype_ptr_free(_pat_3_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_3_1, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0, _ctx)) {
          kk_function_drop(_pat_22_0, _ctx);
          kk_function_drop(_pat_21_0, _ctx);
          kk_string_drop(_pat_20_0, _ctx);
          kk_datatype_ptr_free(_pat_19_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_0, _ctx);
        }
        kk_string_drop(_pat_18_0, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_date__date_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        kk_integer_t _x_1 = _x_0_0.month;
        kk_integer_dup(_x_1, _ctx);
        kk_std_time_date__date_drop(_x_0_0, _ctx);
        _x_x1310 = _x_1; /*int*/
      }
    }
    _own_x766 = kk_std_core_int_show(_x_x1310, _ctx); /*string*/
    kk_string_t _brw_x767;
    kk_std_core_types__optional _x_x1315 = kk_std_core_types__new_Optional(kk_char_box(_b_x231_235, _ctx), _ctx); /*? 7*/
    _brw_x767 = kk_std_core_string_pad_left(_own_x766, n, _x_x1315, _ctx); /*string*/
    kk_integer_drop(n, _ctx);
    _x_x1309 = _brw_x767; /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1303, _x_x1309, _ctx);
  }
  {
    kk_std_core_types__list months;
    bool _match_x764;
    bool _brw_x765 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    _match_x764 = _brw_x765; /*bool*/
    if (_match_x764) {
      struct kk_std_time_locale_Time_locale* _con_x1316 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _pat_0_5 = _con_x1316->lang_name;
      kk_std_core_types__list _pat_1_3 = _con_x1316->day_names;
      kk_std_core_types__list _pat_2_2 = _con_x1316->month_names;
      kk_std_core_types__list _x_2 = _con_x1316->month_names_short;
      kk_std_core_types__list _pat_3_2 = _con_x1316->day_names_short;
      kk_std_core_types__list _pat_4_2 = _con_x1316->day_names_min;
      kk_string_t _pat_5_2 = _con_x1316->format_t;
      kk_string_t _pat_6_2 = _con_x1316->format_tt;
      kk_string_t _pat_7_2 = _con_x1316->format_l;
      kk_string_t _pat_8_1 = _con_x1316->format_ll;
      kk_string_t _pat_9_1 = _con_x1316->format_lll;
      kk_string_t _pat_10_1 = _con_x1316->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
        kk_string_drop(_pat_9_1, _ctx);
        kk_string_drop(_pat_8_1, _ctx);
        kk_string_drop(_pat_7_2, _ctx);
        kk_string_drop(_pat_6_2, _ctx);
        kk_string_drop(_pat_5_2, _ctx);
        kk_std_core_types__list_drop(_pat_4_2, _ctx);
        kk_std_core_types__list_drop(_pat_3_2, _ctx);
        kk_std_core_types__list_drop(_pat_2_2, _ctx);
        kk_std_core_types__list_drop(_pat_1_3, _ctx);
        kk_string_drop(_pat_10_1, _ctx);
        kk_string_drop(_pat_0_5, _ctx);
        kk_datatype_ptr_free(locale, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(locale, _ctx);
      }
      months = _x_2; /*list<string>*/
    }
    else {
      struct kk_std_time_locale_Time_locale* _con_x1317 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _pat_0_6 = _con_x1317->lang_name;
      kk_std_core_types__list _pat_1_4 = _con_x1317->day_names;
      kk_std_core_types__list _x_3 = _con_x1317->month_names;
      kk_std_core_types__list _pat_2_4 = _con_x1317->month_names_short;
      kk_std_core_types__list _pat_3_3 = _con_x1317->day_names_short;
      kk_std_core_types__list _pat_4_3 = _con_x1317->day_names_min;
      kk_string_t _pat_5_3 = _con_x1317->format_t;
      kk_string_t _pat_6_3 = _con_x1317->format_tt;
      kk_string_t _pat_7_3 = _con_x1317->format_l;
      kk_string_t _pat_8_2 = _con_x1317->format_ll;
      kk_string_t _pat_9_2 = _con_x1317->format_lll;
      kk_string_t _pat_10_2 = _con_x1317->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
        kk_string_drop(_pat_9_2, _ctx);
        kk_string_drop(_pat_8_2, _ctx);
        kk_string_drop(_pat_7_3, _ctx);
        kk_string_drop(_pat_6_3, _ctx);
        kk_string_drop(_pat_5_3, _ctx);
        kk_std_core_types__list_drop(_pat_4_3, _ctx);
        kk_std_core_types__list_drop(_pat_3_3, _ctx);
        kk_std_core_types__list_drop(_pat_2_4, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_string_drop(_pat_10_2, _ctx);
        kk_string_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(locale, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_3, _ctx);
        kk_datatype_ptr_decref(locale, _ctx);
      }
      months = _x_3; /*list<string>*/
    }
    kk_std_core_types__maybe m_10043;
    kk_integer_t _x_x1318;
    kk_integer_t _x_x1319;
    {
      struct kk_std_time_time_Time* _con_x1320 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_1 = _con_x1320->date;
      kk_std_time_date__clock _pat_3_4 = _con_x1320->clock;
      kk_std_time_calendar__calendar _pat_7_4 = _con_x1320->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x1320->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x1320->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x1320->instant;
      struct kk_std_time_date_Clock* _con_x1321 = kk_std_time_date__as_Clock(_pat_3_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1322 = kk_std_time_calendar__as_Calendar(_pat_7_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1323 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_date__date_dup(_x_0_1, _ctx);
      {
        kk_integer_t _x_4 = _x_0_1.month;
        kk_integer_dup(_x_4, _ctx);
        kk_std_time_date__date_drop(_x_0_1, _ctx);
        _x_x1319 = _x_4; /*int*/
      }
    }
    _x_x1318 = kk_integer_add_small_const(_x_x1319, -1, _ctx); /*int*/
    m_10043 = kk_std_core_list__index(months, _x_x1318, _ctx); /*maybe<string>*/
    kk_string_t nothing_10044;
    kk_string_t _x_x1324;
    kk_define_string_literal(, _s_x1325, 1, "M", _ctx)
    _x_x1324 = kk_string_dup(_s_x1325, _ctx); /*string*/
    kk_string_t _x_x1326;
    kk_string_t _own_x763;
    kk_integer_t _x_x1327;
    {
      struct kk_std_time_time_Time* _con_x1328 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_2 = _con_x1328->date;
      kk_std_time_date__clock _pat_3_5 = _con_x1328->clock;
      kk_std_time_calendar__calendar _pat_7_5 = _con_x1328->calendar;
      kk_std_time_duration__duration _pat_16_2 = _con_x1328->tzdelta;
      kk_std_time_calendar__timezone _pat_19_2 = _con_x1328->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x1328->instant;
      struct kk_std_time_date_Clock* _con_x1329 = kk_std_time_date__as_Clock(_pat_3_5, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1330 = kk_std_time_calendar__as_Calendar(_pat_7_5, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1331 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
      kk_string_t _pat_18_2 = _con_x1328->tzabbrv;
      kk_integer_t _pat_4_5 = _con_x1329->hours;
      kk_integer_t _pat_5_5 = _con_x1329->minutes;
      kk_string_t _pat_8_4 = _con_x1330->name;
      kk_string_t _pat_9_4 = _con_x1330->long_name;
      kk_string_t _pat_10_4 = _con_x1330->month_prefix;
      kk_function_t _pat_11_2 = _con_x1330->show_era;
      kk_function_t _pat_12_2 = _con_x1330->instant_to_dc;
      kk_function_t _pat_13_2 = _con_x1330->dc_to_instant;
      kk_function_t _pat_14_2 = _con_x1330->days_to_date;
      kk_function_t _pat_15_2 = _con_x1330->date_to_days;
      kk_string_t _pat_20_2 = _con_x1331->name;
      kk_function_t _pat_21_2 = _con_x1331->utc_delta;
      kk_function_t _pat_22_2 = _con_x1331->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_7_5, _ctx)) {
          kk_string_drop(_pat_9_4, _ctx);
          kk_string_drop(_pat_8_4, _ctx);
          kk_function_drop(_pat_15_2, _ctx);
          kk_function_drop(_pat_14_2, _ctx);
          kk_function_drop(_pat_13_2, _ctx);
          kk_function_drop(_pat_12_2, _ctx);
          kk_function_drop(_pat_11_2, _ctx);
          kk_string_drop(_pat_10_4, _ctx);
          kk_datatype_ptr_free(_pat_7_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_7_5, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3_5, _ctx)) {
          kk_integer_drop(_pat_5_5, _ctx);
          kk_integer_drop(_pat_4_5, _ctx);
          kk_datatype_ptr_free(_pat_3_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_3_5, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_2, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_2, _ctx)) {
          kk_function_drop(_pat_22_2, _ctx);
          kk_function_drop(_pat_21_2, _ctx);
          kk_string_drop(_pat_20_2, _ctx);
          kk_datatype_ptr_free(_pat_19_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_2, _ctx);
        }
        kk_string_drop(_pat_18_2, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_date__date_dup(_x_0_2, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        kk_integer_t _x_5 = _x_0_2.month;
        kk_integer_dup(_x_5, _ctx);
        kk_std_time_date__date_drop(_x_0_2, _ctx);
        _x_x1327 = _x_5; /*int*/
      }
    }
    _own_x763 = kk_std_core_int_show(_x_x1327, _ctx); /*string*/
    kk_std_core_types__optional _x_x1332 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _x_x1326 = kk_std_core_string_pad_left(_own_x763, kk_integer_from_small(2), _x_x1332, _ctx); /*string*/
    nothing_10044 = kk_std_core_types__lp__plus__plus__rp_(_x_x1324, _x_x1326, _ctx); /*string*/
    if (kk_std_core_types__is_Nothing(m_10043, _ctx)) {
      return nothing_10044;
    }
    {
      kk_box_t _box_x234 = m_10043._cons.Just.value;
      kk_string_t x = kk_string_unbox(_box_x234);
      kk_string_drop(nothing_10044, _ctx);
      kk_string_dup(x, _ctx);
      kk_std_core_types__maybe_drop(m_10043, _ctx);
      return x;
    }
  }
}

kk_string_t kk_std_time_format_format_year(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x739 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  if (_match_x739) {
    kk_integer_drop(n, _ctx);
    kk_integer_t _x_x1333;
    {
      struct kk_std_time_time_Time* _con_x1334 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0 = _con_x1334->date;
      kk_std_time_date__clock _pat_3 = _con_x1334->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x1334->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x1334->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x1334->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1334->instant;
      struct kk_std_time_date_Clock* _con_x1335 = kk_std_time_date__as_Clock(_pat_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1336 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1337 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_string_t _pat_18 = _con_x1334->tzabbrv;
      kk_integer_t _pat_4 = _con_x1335->hours;
      kk_integer_t _pat_5 = _con_x1335->minutes;
      kk_string_t _pat_8 = _con_x1336->name;
      kk_string_t _pat_9 = _con_x1336->long_name;
      kk_string_t _pat_10 = _con_x1336->month_prefix;
      kk_function_t _pat_11 = _con_x1336->show_era;
      kk_function_t _pat_12 = _con_x1336->instant_to_dc;
      kk_function_t _pat_13 = _con_x1336->dc_to_instant;
      kk_function_t _pat_14 = _con_x1336->days_to_date;
      kk_function_t _pat_15 = _con_x1336->date_to_days;
      kk_string_t _pat_20 = _con_x1337->name;
      kk_function_t _pat_21 = _con_x1337->utc_delta;
      kk_function_t _pat_22 = _con_x1337->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
          kk_string_drop(_pat_9, _ctx);
          kk_string_drop(_pat_8, _ctx);
          kk_function_drop(_pat_15, _ctx);
          kk_function_drop(_pat_14, _ctx);
          kk_function_drop(_pat_13, _ctx);
          kk_function_drop(_pat_12, _ctx);
          kk_function_drop(_pat_11, _ctx);
          kk_string_drop(_pat_10, _ctx);
          kk_datatype_ptr_free(_pat_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_7, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_integer_drop(_pat_5, _ctx);
          kk_integer_drop(_pat_4, _ctx);
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
          kk_function_drop(_pat_22, _ctx);
          kk_function_drop(_pat_21, _ctx);
          kk_string_drop(_pat_20, _ctx);
          kk_datatype_ptr_free(_pat_19, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19, _ctx);
        }
        kk_string_drop(_pat_18, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_date__date_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        kk_integer_t _x = _x_0.year;
        kk_integer_dup(_x, _ctx);
        kk_std_time_date__date_drop(_x_0, _ctx);
        _x_x1333 = _x; /*int*/
      }
    }
    return kk_std_core_int_show(_x_x1333, _ctx);
  }
  {
    bool _match_x740 = kk_integer_lt_borrow(n,(kk_integer_from_small(5)),kk_context()); /*bool*/;
    if (_match_x740) {
      kk_integer_t i_10052;
      kk_integer_t _x_x1338;
      {
        struct kk_std_time_time_Time* _con_x1339 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_0 = _con_x1339->date;
        kk_std_time_date__clock _pat_3_0 = _con_x1339->clock;
        kk_std_time_calendar__calendar _pat_7_0 = _con_x1339->calendar;
        kk_std_time_duration__duration _pat_16_0 = _con_x1339->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0 = _con_x1339->timezone;
        kk_std_time_instant__instant _pat_23_0 = _con_x1339->instant;
        struct kk_std_time_date_Clock* _con_x1340 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1341 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1342 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
        kk_string_t _pat_18_0 = _con_x1339->tzabbrv;
        kk_integer_t _pat_4_0 = _con_x1340->hours;
        kk_integer_t _pat_5_0 = _con_x1340->minutes;
        kk_string_t _pat_8_0 = _con_x1341->name;
        kk_string_t _pat_9_0 = _con_x1341->long_name;
        kk_string_t _pat_10_0 = _con_x1341->month_prefix;
        kk_function_t _pat_11_0 = _con_x1341->show_era;
        kk_function_t _pat_12_0 = _con_x1341->instant_to_dc;
        kk_function_t _pat_13_0 = _con_x1341->dc_to_instant;
        kk_function_t _pat_14_0 = _con_x1341->days_to_date;
        kk_function_t _pat_15_0 = _con_x1341->date_to_days;
        kk_string_t _pat_20_0 = _con_x1342->name;
        kk_function_t _pat_21_0 = _con_x1342->utc_delta;
        kk_function_t _pat_22_0 = _con_x1342->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_0, _ctx)) {
            kk_string_drop(_pat_9_0, _ctx);
            kk_string_drop(_pat_8_0, _ctx);
            kk_function_drop(_pat_15_0, _ctx);
            kk_function_drop(_pat_14_0, _ctx);
            kk_function_drop(_pat_13_0, _ctx);
            kk_function_drop(_pat_12_0, _ctx);
            kk_function_drop(_pat_11_0, _ctx);
            kk_string_drop(_pat_10_0, _ctx);
            kk_datatype_ptr_free(_pat_7_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_0, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0, _ctx)) {
            kk_integer_drop(_pat_5_0, _ctx);
            kk_integer_drop(_pat_4_0, _ctx);
            kk_datatype_ptr_free(_pat_3_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_0, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0, _ctx)) {
            kk_function_drop(_pat_22_0, _ctx);
            kk_function_drop(_pat_21_0, _ctx);
            kk_string_drop(_pat_20_0, _ctx);
            kk_datatype_ptr_free(_pat_19_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_0, _ctx);
          }
          kk_string_drop(_pat_18_0, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_0_0, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_1 = _x_0_0.year;
          kk_integer_dup(_x_1, _ctx);
          kk_std_time_date__date_drop(_x_0_0, _ctx);
          _x_x1338 = _x_1; /*int*/
        }
      }
      i_10052 = kk_integer_abs(_x_x1338,kk_context()); /*int*/
      kk_integer_t _b_x237_245 = kk_integer_dup(n, _ctx); /*int*/;
      kk_std_core_sslice__sslice _x_x1343;
      kk_char_t _b_x236_244 = '0'; /*char*/;
      kk_string_t _x_x1344;
      kk_string_t _own_x760 = kk_std_core_int_show(i_10052, _ctx); /*string*/;
      kk_string_t _brw_x761;
      kk_std_core_types__optional _x_x1345 = kk_std_core_types__new_Optional(kk_char_box(_b_x236_244, _ctx), _ctx); /*? 7*/
      _brw_x761 = kk_std_core_string_pad_left(_own_x760, n, _x_x1345, _ctx); /*string*/
      kk_integer_drop(n, _ctx);
      _x_x1344 = _brw_x761; /*string*/
      kk_std_core_types__optional _x_x1346 = kk_std_core_types__new_Optional(kk_integer_box(_b_x237_245, _ctx), _ctx); /*? 7*/
      _x_x1343 = kk_std_core_sslice_last(_x_x1344, _x_x1346, _ctx); /*sslice/sslice*/
      return kk_std_core_sslice_string(_x_x1343, _ctx);
    }
    {
      bool _match_x741;
      kk_integer_t _brw_x758;
      {
        struct kk_std_time_time_Time* _con_x1347 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_1 = _con_x1347->date;
        kk_std_time_date__clock _pat_3_1 = _con_x1347->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x1347->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x1347->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x1347->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x1347->instant;
        struct kk_std_time_date_Clock* _con_x1348 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1349 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1350 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__date_dup(_x_0_1, _ctx);
        {
          kk_integer_t _x_2 = _x_0_1.year;
          kk_integer_dup(_x_2, _ctx);
          kk_std_time_date__date_drop(_x_0_1, _ctx);
          _brw_x758 = _x_2; /*int*/
        }
      }
      bool _brw_x759 = kk_integer_gte_borrow(_brw_x758,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x758, _ctx);
      _match_x741 = _brw_x759; /*bool*/
      if (_match_x741) {
        bool _match_x747;
        kk_integer_t _brw_x756;
        {
          struct kk_std_time_time_Time* _con_x1351 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_0_2 = _con_x1351->date;
          kk_std_time_date__clock _pat_3_3 = _con_x1351->clock;
          kk_std_time_calendar__calendar _pat_7_2 = _con_x1351->calendar;
          kk_std_time_duration__duration _pat_16_2 = _con_x1351->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2 = _con_x1351->timezone;
          kk_std_time_instant__instant _pat_23_2 = _con_x1351->instant;
          struct kk_std_time_date_Clock* _con_x1352 = kk_std_time_date__as_Clock(_pat_3_3, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1353 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1354 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
          kk_std_time_date__date_dup(_x_0_2, _ctx);
          {
            kk_integer_t _x_3 = _x_0_2.year;
            kk_integer_dup(_x_3, _ctx);
            kk_std_time_date__date_drop(_x_0_2, _ctx);
            _brw_x756 = _x_3; /*int*/
          }
        }
        kk_integer_t _brw_x755 = kk_integer_from_int(9999, _ctx); /*int*/;
        bool _brw_x757 = kk_integer_lte_borrow(_brw_x756,_brw_x755,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x756, _ctx);
        kk_integer_drop(_brw_x755, _ctx);
        _match_x747 = _brw_x757; /*bool*/
        if (_match_x747) {
          kk_integer_t i_0_10057;
          kk_integer_t _x_x1355;
          {
            struct kk_std_time_time_Time* _con_x1356 = kk_std_time_time__as_Time(t, _ctx);
            kk_std_time_date__date _x_0_3 = _con_x1356->date;
            kk_std_time_date__clock _pat_3_4 = _con_x1356->clock;
            kk_std_time_calendar__calendar _pat_7_3 = _con_x1356->calendar;
            kk_std_time_duration__duration _pat_16_3 = _con_x1356->tzdelta;
            kk_std_time_calendar__timezone _pat_19_3 = _con_x1356->timezone;
            kk_std_time_instant__instant _pat_23_3 = _con_x1356->instant;
            struct kk_std_time_date_Clock* _con_x1357 = kk_std_time_date__as_Clock(_pat_3_4, _ctx);
            struct kk_std_time_calendar_Calendar* _con_x1358 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
            struct kk_std_time_calendar_Timezone* _con_x1359 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
            kk_string_t _pat_18_3 = _con_x1356->tzabbrv;
            kk_integer_t _pat_4_3 = _con_x1357->hours;
            kk_integer_t _pat_5_4 = _con_x1357->minutes;
            kk_string_t _pat_8_3 = _con_x1358->name;
            kk_string_t _pat_9_3 = _con_x1358->long_name;
            kk_string_t _pat_10_3 = _con_x1358->month_prefix;
            kk_function_t _pat_11_3 = _con_x1358->show_era;
            kk_function_t _pat_12_3 = _con_x1358->instant_to_dc;
            kk_function_t _pat_13_3 = _con_x1358->dc_to_instant;
            kk_function_t _pat_14_3 = _con_x1358->days_to_date;
            kk_function_t _pat_15_3 = _con_x1358->date_to_days;
            kk_string_t _pat_20_3 = _con_x1359->name;
            kk_function_t _pat_21_3 = _con_x1359->utc_delta;
            kk_function_t _pat_22_3 = _con_x1359->utc_inverse;
            if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_pat_7_3, _ctx)) {
                kk_string_drop(_pat_9_3, _ctx);
                kk_string_drop(_pat_8_3, _ctx);
                kk_function_drop(_pat_15_3, _ctx);
                kk_function_drop(_pat_14_3, _ctx);
                kk_function_drop(_pat_13_3, _ctx);
                kk_function_drop(_pat_12_3, _ctx);
                kk_function_drop(_pat_11_3, _ctx);
                kk_string_drop(_pat_10_3, _ctx);
                kk_datatype_ptr_free(_pat_7_3, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_7_3, _ctx);
              }
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3_4, _ctx)) {
                kk_integer_drop(_pat_5_4, _ctx);
                kk_integer_drop(_pat_4_3, _ctx);
                kk_datatype_ptr_free(_pat_3_4, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_3_4, _ctx);
              }
              kk_std_time_instant__instant_drop(_pat_23_3, _ctx);
              if kk_likely(kk_datatype_ptr_is_unique(_pat_19_3, _ctx)) {
                kk_function_drop(_pat_22_3, _ctx);
                kk_function_drop(_pat_21_3, _ctx);
                kk_string_drop(_pat_20_3, _ctx);
                kk_datatype_ptr_free(_pat_19_3, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_19_3, _ctx);
              }
              kk_string_drop(_pat_18_3, _ctx);
              kk_datatype_ptr_free(t, _ctx);
            }
            else {
              kk_std_time_date__date_dup(_x_0_3, _ctx);
              kk_datatype_ptr_decref(t, _ctx);
            }
            {
              kk_integer_t _x_4 = _x_0_3.year;
              kk_integer_dup(_x_4, _ctx);
              kk_std_time_date__date_drop(_x_0_3, _ctx);
              _x_x1355 = _x_4; /*int*/
            }
          }
          i_0_10057 = kk_integer_abs(_x_x1355,kk_context()); /*int*/
          kk_integer_t _b_x239_247 = kk_integer_dup(n, _ctx); /*int*/;
          kk_std_core_sslice__sslice _x_x1360;
          kk_char_t _b_x238_246 = '0'; /*char*/;
          kk_string_t _x_x1361;
          kk_string_t _own_x753 = kk_std_core_int_show(i_0_10057, _ctx); /*string*/;
          kk_string_t _brw_x754;
          kk_std_core_types__optional _x_x1362 = kk_std_core_types__new_Optional(kk_char_box(_b_x238_246, _ctx), _ctx); /*? 7*/
          _brw_x754 = kk_std_core_string_pad_left(_own_x753, n, _x_x1362, _ctx); /*string*/
          kk_integer_drop(n, _ctx);
          _x_x1361 = _brw_x754; /*string*/
          kk_std_core_types__optional _x_x1363 = kk_std_core_types__new_Optional(kk_integer_box(_b_x239_247, _ctx), _ctx); /*? 7*/
          _x_x1360 = kk_std_core_sslice_last(_x_x1361, _x_x1363, _ctx); /*sslice/sslice*/
          return kk_std_core_sslice_string(_x_x1360, _ctx);
        }
        {
          kk_integer_t i_1_10060;
          kk_integer_t _x_x1364;
          {
            struct kk_std_time_time_Time* _con_x1365 = kk_std_time_time__as_Time(t, _ctx);
            kk_std_time_date__date _x_0_4 = _con_x1365->date;
            kk_std_time_date__clock _pat_3_5 = _con_x1365->clock;
            kk_std_time_calendar__calendar _pat_7_4 = _con_x1365->calendar;
            kk_std_time_duration__duration _pat_16_4 = _con_x1365->tzdelta;
            kk_std_time_calendar__timezone _pat_19_4 = _con_x1365->timezone;
            kk_std_time_instant__instant _pat_23_4 = _con_x1365->instant;
            struct kk_std_time_date_Clock* _con_x1366 = kk_std_time_date__as_Clock(_pat_3_5, _ctx);
            struct kk_std_time_calendar_Calendar* _con_x1367 = kk_std_time_calendar__as_Calendar(_pat_7_4, _ctx);
            struct kk_std_time_calendar_Timezone* _con_x1368 = kk_std_time_calendar__as_Timezone(_pat_19_4, _ctx);
            kk_std_time_date__date_dup(_x_0_4, _ctx);
            {
              kk_integer_t _x_5 = _x_0_4.year;
              kk_integer_dup(_x_5, _ctx);
              kk_std_time_date__date_drop(_x_0_4, _ctx);
              _x_x1364 = _x_5; /*int*/
            }
          }
          i_1_10060 = kk_integer_abs(_x_x1364,kk_context()); /*int*/
          kk_string_t y;
          kk_string_t _own_x751 = kk_std_core_int_show(i_1_10060, _ctx); /*string*/;
          kk_string_t _brw_x752;
          kk_std_core_types__optional _x_x1369 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
          _brw_x752 = kk_std_core_string_pad_left(_own_x751, n, _x_x1369, _ctx); /*string*/
          kk_integer_drop(n, _ctx);
          y = _brw_x752; /*string*/
          bool _match_x748;
          kk_integer_t _brw_x749;
          {
            struct kk_std_time_time_Time* _con_x1370 = kk_std_time_time__as_Time(t, _ctx);
            kk_std_time_date__date _x_0_5 = _con_x1370->date;
            kk_std_time_date__clock _pat_3_6 = _con_x1370->clock;
            kk_std_time_calendar__calendar _pat_7_5 = _con_x1370->calendar;
            kk_std_time_duration__duration _pat_16_5 = _con_x1370->tzdelta;
            kk_std_time_calendar__timezone _pat_19_5 = _con_x1370->timezone;
            kk_std_time_instant__instant _pat_23_5 = _con_x1370->instant;
            struct kk_std_time_date_Clock* _con_x1371 = kk_std_time_date__as_Clock(_pat_3_6, _ctx);
            struct kk_std_time_calendar_Calendar* _con_x1372 = kk_std_time_calendar__as_Calendar(_pat_7_5, _ctx);
            struct kk_std_time_calendar_Timezone* _con_x1373 = kk_std_time_calendar__as_Timezone(_pat_19_5, _ctx);
            kk_string_t _pat_18_5 = _con_x1370->tzabbrv;
            kk_integer_t _pat_4_5 = _con_x1371->hours;
            kk_integer_t _pat_5_6 = _con_x1371->minutes;
            kk_string_t _pat_8_5 = _con_x1372->name;
            kk_string_t _pat_9_5 = _con_x1372->long_name;
            kk_string_t _pat_10_5 = _con_x1372->month_prefix;
            kk_function_t _pat_11_5 = _con_x1372->show_era;
            kk_function_t _pat_12_5 = _con_x1372->instant_to_dc;
            kk_function_t _pat_13_5 = _con_x1372->dc_to_instant;
            kk_function_t _pat_14_5 = _con_x1372->days_to_date;
            kk_function_t _pat_15_5 = _con_x1372->date_to_days;
            kk_string_t _pat_20_5 = _con_x1373->name;
            kk_function_t _pat_21_5 = _con_x1373->utc_delta;
            kk_function_t _pat_22_5 = _con_x1373->utc_inverse;
            if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_pat_7_5, _ctx)) {
                kk_string_drop(_pat_9_5, _ctx);
                kk_string_drop(_pat_8_5, _ctx);
                kk_function_drop(_pat_15_5, _ctx);
                kk_function_drop(_pat_14_5, _ctx);
                kk_function_drop(_pat_13_5, _ctx);
                kk_function_drop(_pat_12_5, _ctx);
                kk_function_drop(_pat_11_5, _ctx);
                kk_string_drop(_pat_10_5, _ctx);
                kk_datatype_ptr_free(_pat_7_5, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_7_5, _ctx);
              }
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3_6, _ctx)) {
                kk_integer_drop(_pat_5_6, _ctx);
                kk_integer_drop(_pat_4_5, _ctx);
                kk_datatype_ptr_free(_pat_3_6, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_3_6, _ctx);
              }
              kk_std_time_instant__instant_drop(_pat_23_5, _ctx);
              if kk_likely(kk_datatype_ptr_is_unique(_pat_19_5, _ctx)) {
                kk_function_drop(_pat_22_5, _ctx);
                kk_function_drop(_pat_21_5, _ctx);
                kk_string_drop(_pat_20_5, _ctx);
                kk_datatype_ptr_free(_pat_19_5, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_19_5, _ctx);
              }
              kk_string_drop(_pat_18_5, _ctx);
              kk_datatype_ptr_free(t, _ctx);
            }
            else {
              kk_std_time_date__date_dup(_x_0_5, _ctx);
              kk_datatype_ptr_decref(t, _ctx);
            }
            {
              kk_integer_t _x_6 = _x_0_5.year;
              kk_integer_dup(_x_6, _ctx);
              kk_std_time_date__date_drop(_x_0_5, _ctx);
              _brw_x749 = _x_6; /*int*/
            }
          }
          bool _brw_x750 = kk_integer_lt_borrow(_brw_x749,(kk_integer_from_small(0)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x749, _ctx);
          _match_x748 = _brw_x750; /*bool*/
          if (_match_x748) {
            kk_string_t _x_x1374;
            kk_define_string_literal(, _s_x1375, 1, "-", _ctx)
            _x_x1374 = kk_string_dup(_s_x1375, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x1374, y, _ctx);
          }
          {
            kk_string_t _x_x1376;
            kk_define_string_literal(, _s_x1377, 1, "+", _ctx)
            _x_x1376 = kk_string_dup(_s_x1377, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x1376, y, _ctx);
          }
        }
      }
      {
        kk_integer_t i_3_10065;
        kk_integer_t _x_x1378;
        {
          struct kk_std_time_time_Time* _con_x1379 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_0_6 = _con_x1379->date;
          kk_std_time_date__clock _pat_3_7 = _con_x1379->clock;
          kk_std_time_calendar__calendar _pat_7_7 = _con_x1379->calendar;
          kk_std_time_duration__duration _pat_16_6 = _con_x1379->tzdelta;
          kk_std_time_calendar__timezone _pat_19_6 = _con_x1379->timezone;
          kk_std_time_instant__instant _pat_23_6 = _con_x1379->instant;
          struct kk_std_time_date_Clock* _con_x1380 = kk_std_time_date__as_Clock(_pat_3_7, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1381 = kk_std_time_calendar__as_Calendar(_pat_7_7, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1382 = kk_std_time_calendar__as_Timezone(_pat_19_6, _ctx);
          kk_std_time_date__date_dup(_x_0_6, _ctx);
          {
            kk_integer_t _x_7 = _x_0_6.year;
            kk_integer_dup(_x_7, _ctx);
            kk_std_time_date__date_drop(_x_0_6, _ctx);
            _x_x1378 = _x_7; /*int*/
          }
        }
        i_3_10065 = kk_integer_abs(_x_x1378,kk_context()); /*int*/
        kk_string_t y_0;
        kk_string_t _own_x745 = kk_std_core_int_show(i_3_10065, _ctx); /*string*/;
        kk_string_t _brw_x746;
        kk_std_core_types__optional _x_x1383 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
        _brw_x746 = kk_std_core_string_pad_left(_own_x745, n, _x_x1383, _ctx); /*string*/
        kk_integer_drop(n, _ctx);
        y_0 = _brw_x746; /*string*/
        bool _match_x742;
        kk_integer_t _brw_x743;
        {
          struct kk_std_time_time_Time* _con_x1384 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_0_7 = _con_x1384->date;
          kk_std_time_date__clock _pat_3_8 = _con_x1384->clock;
          kk_std_time_calendar__calendar _pat_7_8 = _con_x1384->calendar;
          kk_std_time_duration__duration _pat_16_7 = _con_x1384->tzdelta;
          kk_std_time_calendar__timezone _pat_19_7 = _con_x1384->timezone;
          kk_std_time_instant__instant _pat_23_7 = _con_x1384->instant;
          struct kk_std_time_date_Clock* _con_x1385 = kk_std_time_date__as_Clock(_pat_3_8, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1386 = kk_std_time_calendar__as_Calendar(_pat_7_8, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1387 = kk_std_time_calendar__as_Timezone(_pat_19_7, _ctx);
          kk_string_t _pat_18_7 = _con_x1384->tzabbrv;
          kk_integer_t _pat_4_8 = _con_x1385->hours;
          kk_integer_t _pat_5_8 = _con_x1385->minutes;
          kk_string_t _pat_8_8 = _con_x1386->name;
          kk_string_t _pat_9_7 = _con_x1386->long_name;
          kk_string_t _pat_10_7 = _con_x1386->month_prefix;
          kk_function_t _pat_11_7 = _con_x1386->show_era;
          kk_function_t _pat_12_7 = _con_x1386->instant_to_dc;
          kk_function_t _pat_13_7 = _con_x1386->dc_to_instant;
          kk_function_t _pat_14_7 = _con_x1386->days_to_date;
          kk_function_t _pat_15_7 = _con_x1386->date_to_days;
          kk_string_t _pat_20_7 = _con_x1387->name;
          kk_function_t _pat_21_7 = _con_x1387->utc_delta;
          kk_function_t _pat_22_7 = _con_x1387->utc_inverse;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_7_8, _ctx)) {
              kk_string_drop(_pat_9_7, _ctx);
              kk_string_drop(_pat_8_8, _ctx);
              kk_function_drop(_pat_15_7, _ctx);
              kk_function_drop(_pat_14_7, _ctx);
              kk_function_drop(_pat_13_7, _ctx);
              kk_function_drop(_pat_12_7, _ctx);
              kk_function_drop(_pat_11_7, _ctx);
              kk_string_drop(_pat_10_7, _ctx);
              kk_datatype_ptr_free(_pat_7_8, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_7_8, _ctx);
            }
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3_8, _ctx)) {
              kk_integer_drop(_pat_5_8, _ctx);
              kk_integer_drop(_pat_4_8, _ctx);
              kk_datatype_ptr_free(_pat_3_8, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_3_8, _ctx);
            }
            kk_std_time_instant__instant_drop(_pat_23_7, _ctx);
            if kk_likely(kk_datatype_ptr_is_unique(_pat_19_7, _ctx)) {
              kk_function_drop(_pat_22_7, _ctx);
              kk_function_drop(_pat_21_7, _ctx);
              kk_string_drop(_pat_20_7, _ctx);
              kk_datatype_ptr_free(_pat_19_7, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_19_7, _ctx);
            }
            kk_string_drop(_pat_18_7, _ctx);
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_std_time_date__date_dup(_x_0_7, _ctx);
            kk_datatype_ptr_decref(t, _ctx);
          }
          {
            kk_integer_t _x_8 = _x_0_7.year;
            kk_integer_dup(_x_8, _ctx);
            kk_std_time_date__date_drop(_x_0_7, _ctx);
            _brw_x743 = _x_8; /*int*/
          }
        }
        bool _brw_x744 = kk_integer_lt_borrow(_brw_x743,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x743, _ctx);
        _match_x742 = _brw_x744; /*bool*/
        if (_match_x742) {
          kk_string_t _x_x1388;
          kk_define_string_literal(, _s_x1389, 1, "-", _ctx)
          _x_x1388 = kk_string_dup(_s_x1389, _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x1388, y_0, _ctx);
        }
        {
          kk_string_t _x_x1390;
          kk_define_string_literal(, _s_x1391, 1, "+", _ctx)
          _x_x1390 = kk_string_dup(_s_x1391, _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x1390, y_0, _ctx);
        }
      }
    }
  }
}

kk_string_t kk_std_time_format_format_era(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_drop(n, _ctx);
  {
    struct kk_std_time_time_Time* _con_x1392 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1392->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1392->clock;
    kk_std_time_calendar__calendar _x_0 = _con_x1392->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1392->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1392->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1392->instant;
    struct kk_std_time_date_Clock* _con_x1393 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1394 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1395 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_calendar__calendar_dup(_x_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x1396 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x1396->name;
      kk_string_t _pat_1 = _con_x1396->long_name;
      kk_string_t _pat_2 = _con_x1396->month_prefix;
      kk_function_t _x = _con_x1396->show_era;
      kk_function_t _pat_3 = _con_x1396->instant_to_dc;
      kk_function_t _pat_4 = _con_x1396->dc_to_instant;
      kk_function_t _pat_5 = _con_x1396->days_to_date;
      kk_function_t _pat_6 = _con_x1396->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_function_drop(_pat_6, _ctx);
        kk_function_drop(_pat_5, _ctx);
        kk_function_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_string_drop(_pat_2, _ctx);
        kk_string_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_function_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      kk_std_time_date__date _x_x1397;
      {
        struct kk_std_time_time_Time* _con_x1398 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_1 = _con_x1398->date;
        kk_std_time_date__clock _pat_3_1 = _con_x1398->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x1398->calendar;
        kk_std_time_duration__duration _pat_16_0 = _con_x1398->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0 = _con_x1398->timezone;
        kk_std_time_instant__instant _pat_23_0 = _con_x1398->instant;
        struct kk_std_time_date_Clock* _con_x1399 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1400 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1401 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
        kk_string_t _pat_18_0 = _con_x1398->tzabbrv;
        kk_integer_t _pat_4_1 = _con_x1399->hours;
        kk_integer_t _pat_5_1 = _con_x1399->minutes;
        kk_string_t _pat_8_0 = _con_x1400->name;
        kk_string_t _pat_9_0 = _con_x1400->long_name;
        kk_string_t _pat_10_0 = _con_x1400->month_prefix;
        kk_function_t _pat_11_0 = _con_x1400->show_era;
        kk_function_t _pat_12_0 = _con_x1400->instant_to_dc;
        kk_function_t _pat_13_0 = _con_x1400->dc_to_instant;
        kk_function_t _pat_14_0 = _con_x1400->days_to_date;
        kk_function_t _pat_15_0 = _con_x1400->date_to_days;
        kk_string_t _pat_20_0 = _con_x1401->name;
        kk_function_t _pat_21_0 = _con_x1401->utc_delta;
        kk_function_t _pat_22_0 = _con_x1401->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1, _ctx)) {
            kk_string_drop(_pat_9_0, _ctx);
            kk_string_drop(_pat_8_0, _ctx);
            kk_function_drop(_pat_15_0, _ctx);
            kk_function_drop(_pat_14_0, _ctx);
            kk_function_drop(_pat_13_0, _ctx);
            kk_function_drop(_pat_12_0, _ctx);
            kk_function_drop(_pat_11_0, _ctx);
            kk_string_drop(_pat_10_0, _ctx);
            kk_datatype_ptr_free(_pat_7_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_integer_drop(_pat_5_1, _ctx);
            kk_integer_drop(_pat_4_1, _ctx);
            kk_datatype_ptr_free(_pat_3_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_1, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0, _ctx)) {
            kk_function_drop(_pat_22_0, _ctx);
            kk_function_drop(_pat_21_0, _ctx);
            kk_string_drop(_pat_20_0, _ctx);
            kk_datatype_ptr_free(_pat_19_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_0, _ctx);
          }
          kk_string_drop(_pat_18_0, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        _x_x1397 = _x_1; /*std/time/date/date*/
      }
      return kk_function_call(kk_string_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, _x_x1397, _ctx), _ctx);
    }
  }
}

kk_string_t kk_std_time_format_format_seconds(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_t i_10073;
  kk_std_num_ddouble__ddouble _x_x1402;
  bool _match_x738;
  double _x_x1403;
  {
    struct kk_std_time_time_Time* _con_x1404 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_1 = _con_x1404->date;
    kk_std_time_date__clock _x_0 = _con_x1404->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1404->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1404->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1404->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1404->instant;
    struct kk_std_time_date_Clock* _con_x1405 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1406 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1407 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__clock_dup(_x_0, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1408 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x1408->seconds;
      kk_integer_t _pat_0_1 = _con_x1408->hours;
      kk_integer_t _pat_1_1 = _con_x1408->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      {
        double _x = _x_1.hi;
        _x_x1403 = _x; /*float64*/
      }
    }
  }
  _match_x738 = (_x_x1403 < (0x0p+0)); /*bool*/
  if (_match_x738) {
    kk_std_num_ddouble__ddouble _x_x1409;
    {
      struct kk_std_time_time_Time* _con_x1410 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_0 = _con_x1410->date;
      kk_std_time_date__clock _x_0_0 = _con_x1410->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x1410->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1410->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1410->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1410->instant;
      struct kk_std_time_date_Clock* _con_x1411 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1412 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1413 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_string_t _pat_18_0 = _con_x1410->tzabbrv;
      kk_string_t _pat_8_0 = _con_x1412->name;
      kk_string_t _pat_9_0 = _con_x1412->long_name;
      kk_string_t _pat_10_0 = _con_x1412->month_prefix;
      kk_function_t _pat_11_0 = _con_x1412->show_era;
      kk_function_t _pat_12_0 = _con_x1412->instant_to_dc;
      kk_function_t _pat_13_0 = _con_x1412->dc_to_instant;
      kk_function_t _pat_14_0 = _con_x1412->days_to_date;
      kk_function_t _pat_15_0 = _con_x1412->date_to_days;
      kk_string_t _pat_20_0 = _con_x1413->name;
      kk_function_t _pat_21_0 = _con_x1413->utc_delta;
      kk_function_t _pat_22_0 = _con_x1413->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_7_0, _ctx)) {
          kk_string_drop(_pat_9_0, _ctx);
          kk_string_drop(_pat_8_0, _ctx);
          kk_function_drop(_pat_15_0, _ctx);
          kk_function_drop(_pat_14_0, _ctx);
          kk_function_drop(_pat_13_0, _ctx);
          kk_function_drop(_pat_12_0, _ctx);
          kk_function_drop(_pat_11_0, _ctx);
          kk_string_drop(_pat_10_0, _ctx);
          kk_datatype_ptr_free(_pat_7_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_7_0, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0, _ctx)) {
          kk_function_drop(_pat_22_0, _ctx);
          kk_function_drop(_pat_21_0, _ctx);
          kk_string_drop(_pat_20_0, _ctx);
          kk_datatype_ptr_free(_pat_19_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_0, _ctx);
        }
        kk_string_drop(_pat_18_0, _ctx);
        kk_std_time_date__date_drop(_pat_0_0_1_0, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_date__clock_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        struct kk_std_time_date_Clock* _con_x1414 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0 = _con_x1414->seconds;
        kk_integer_t _pat_0_1_0 = _con_x1414->hours;
        kk_integer_t _pat_1_1_0 = _con_x1414->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
          kk_integer_drop(_pat_1_1_0, _ctx);
          kk_integer_drop(_pat_0_1_0, _ctx);
          kk_datatype_ptr_free(_x_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_0, _ctx);
        }
        _x_x1409 = _x_1_0; /*std/num/ddouble/ddouble*/
      }
    }
    _x_x1402 = kk_std_num_ddouble_ceiling(_x_x1409, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x1415;
    {
      struct kk_std_time_time_Time* _con_x1416 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_1 = _con_x1416->date;
      kk_std_time_date__clock _x_0_1 = _con_x1416->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x1416->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x1416->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x1416->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x1416->instant;
      struct kk_std_time_date_Clock* _con_x1417 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1418 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1419 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_string_t _pat_18_1 = _con_x1416->tzabbrv;
      kk_string_t _pat_8_1 = _con_x1418->name;
      kk_string_t _pat_9_1 = _con_x1418->long_name;
      kk_string_t _pat_10_1 = _con_x1418->month_prefix;
      kk_function_t _pat_11_1 = _con_x1418->show_era;
      kk_function_t _pat_12_1 = _con_x1418->instant_to_dc;
      kk_function_t _pat_13_1 = _con_x1418->dc_to_instant;
      kk_function_t _pat_14_1 = _con_x1418->days_to_date;
      kk_function_t _pat_15_1 = _con_x1418->date_to_days;
      kk_string_t _pat_20_1 = _con_x1419->name;
      kk_function_t _pat_21_1 = _con_x1419->utc_delta;
      kk_function_t _pat_22_1 = _con_x1419->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1, _ctx)) {
          kk_string_drop(_pat_9_1, _ctx);
          kk_string_drop(_pat_8_1, _ctx);
          kk_function_drop(_pat_15_1, _ctx);
          kk_function_drop(_pat_14_1, _ctx);
          kk_function_drop(_pat_13_1, _ctx);
          kk_function_drop(_pat_12_1, _ctx);
          kk_function_drop(_pat_11_1, _ctx);
          kk_string_drop(_pat_10_1, _ctx);
          kk_datatype_ptr_free(_pat_7_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_7_1, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_1, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_1, _ctx)) {
          kk_function_drop(_pat_22_1, _ctx);
          kk_function_drop(_pat_21_1, _ctx);
          kk_string_drop(_pat_20_1, _ctx);
          kk_datatype_ptr_free(_pat_19_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_1, _ctx);
        }
        kk_string_drop(_pat_18_1, _ctx);
        kk_std_time_date__date_drop(_pat_0_0_1_1, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_date__clock_dup(_x_0_1, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        struct kk_std_time_date_Clock* _con_x1420 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
        kk_std_num_ddouble__ddouble _x_1_1 = _con_x1420->seconds;
        kk_integer_t _pat_0_1_1 = _con_x1420->hours;
        kk_integer_t _pat_1_1_1 = _con_x1420->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
          kk_integer_drop(_pat_1_1_1, _ctx);
          kk_integer_drop(_pat_0_1_1, _ctx);
          kk_datatype_ptr_free(_x_0_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1, _ctx);
        }
        _x_x1415 = _x_1_1; /*std/num/ddouble/ddouble*/
      }
    }
    _x_x1402 = kk_std_num_ddouble_floor(_x_x1415, _ctx); /*std/num/ddouble/ddouble*/
  }
  i_10073 = kk_std_num_ddouble_int(_x_x1402, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_string_t _own_x736 = kk_std_core_int_show(i_10073, _ctx); /*string*/;
  kk_string_t _brw_x737;
  kk_std_core_types__optional _x_x1421 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
  _brw_x737 = kk_std_core_string_pad_left(_own_x736, n, _x_x1421, _ctx); /*string*/
  kk_integer_drop(n, _ctx);
  return _brw_x737;
}

kk_string_t kk_std_time_format_format_minutes(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t _own_x734;
  kk_integer_t _x_x1422;
  {
    struct kk_std_time_time_Time* _con_x1423 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1423->date;
    kk_std_time_date__clock _x_0 = _con_x1423->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1423->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1423->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1423->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1423->instant;
    struct kk_std_time_date_Clock* _con_x1424 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1425 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1426 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1423->tzabbrv;
    kk_string_t _pat_8 = _con_x1425->name;
    kk_string_t _pat_9 = _con_x1425->long_name;
    kk_string_t _pat_10 = _con_x1425->month_prefix;
    kk_function_t _pat_11 = _con_x1425->show_era;
    kk_function_t _pat_12 = _con_x1425->instant_to_dc;
    kk_function_t _pat_13 = _con_x1425->dc_to_instant;
    kk_function_t _pat_14 = _con_x1425->days_to_date;
    kk_function_t _pat_15 = _con_x1425->date_to_days;
    kk_string_t _pat_20 = _con_x1426->name;
    kk_function_t _pat_21 = _con_x1426->utc_delta;
    kk_function_t _pat_22 = _con_x1426->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_function_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_7, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x1427 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_1 = _con_x1427->seconds;
      kk_integer_t _pat_0_1 = _con_x1427->hours;
      kk_integer_t _x = _con_x1427->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1422 = _x; /*int*/
    }
  }
  _own_x734 = kk_std_core_int_show(_x_x1422, _ctx); /*string*/
  kk_string_t _brw_x735;
  kk_std_core_types__optional _x_x1428 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
  _brw_x735 = kk_std_core_string_pad_left(_own_x734, n, _x_x1428, _ctx); /*string*/
  kk_integer_drop(n, _ctx);
  return _brw_x735;
}

kk_string_t kk_std_time_format_format_hours(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t _own_x732;
  kk_integer_t _x_x1429;
  {
    struct kk_std_time_time_Time* _con_x1430 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1430->date;
    kk_std_time_date__clock _x_0 = _con_x1430->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1430->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1430->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1430->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1430->instant;
    struct kk_std_time_date_Clock* _con_x1431 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1432 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1433 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1430->tzabbrv;
    kk_string_t _pat_8 = _con_x1432->name;
    kk_string_t _pat_9 = _con_x1432->long_name;
    kk_string_t _pat_10 = _con_x1432->month_prefix;
    kk_function_t _pat_11 = _con_x1432->show_era;
    kk_function_t _pat_12 = _con_x1432->instant_to_dc;
    kk_function_t _pat_13 = _con_x1432->dc_to_instant;
    kk_function_t _pat_14 = _con_x1432->days_to_date;
    kk_function_t _pat_15 = _con_x1432->date_to_days;
    kk_string_t _pat_20 = _con_x1433->name;
    kk_function_t _pat_21 = _con_x1433->utc_delta;
    kk_function_t _pat_22 = _con_x1433->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_function_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_7, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x1434 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_1 = _con_x1434->seconds;
      kk_integer_t _x = _con_x1434->hours;
      kk_integer_t _pat_0_1 = _con_x1434->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1429 = _x; /*int*/
    }
  }
  _own_x732 = kk_std_core_int_show(_x_x1429, _ctx); /*string*/
  kk_string_t _brw_x733;
  kk_std_core_types__optional _x_x1435 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
  _brw_x733 = kk_std_core_string_pad_left(_own_x732, n, _x_x1435, _ctx); /*string*/
  kk_integer_drop(n, _ctx);
  return _brw_x733;
}

kk_string_t kk_std_time_format_format_hours12(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x719;
  kk_integer_t _brw_x730;
  {
    struct kk_std_time_time_Time* _con_x1436 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1436->date;
    kk_std_time_date__clock _x_0 = _con_x1436->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1436->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1436->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1436->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1436->instant;
    struct kk_std_time_date_Clock* _con_x1437 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1438 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1439 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__clock_dup(_x_0, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1440 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1 = _con_x1440->seconds;
      kk_integer_t _x = _con_x1440->hours;
      kk_integer_t _pat_0 = _con_x1440->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _brw_x730 = _x; /*int*/
    }
  }
  bool _brw_x731 = kk_integer_eq_borrow(_brw_x730,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x730, _ctx);
  _match_x719 = _brw_x731; /*bool*/
  if (_match_x719) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_integer_drop(n, _ctx);
    kk_define_string_literal(, _s_x1441, 2, "12", _ctx)
    return kk_string_dup(_s_x1441, _ctx);
  }
  {
    bool _match_x720;
    kk_integer_t _brw_x728;
    {
      struct kk_std_time_time_Time* _con_x1442 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_0 = _con_x1442->date;
      kk_std_time_date__clock _x_0_0 = _con_x1442->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x1442->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1442->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1442->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1442->instant;
      struct kk_std_time_date_Clock* _con_x1443 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1444 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1445 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__clock_dup(_x_0_0, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x1446 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_1_1 = _con_x1446->seconds;
        kk_integer_t _x_1 = _con_x1446->hours;
        kk_integer_t _pat_0_2 = _con_x1446->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(_x_0_0, _ctx);
        }
        else {
          kk_integer_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(_x_0_0, _ctx);
        }
        _brw_x728 = _x_1; /*int*/
      }
    }
    bool _brw_x729 = kk_integer_eq_borrow(_brw_x728,(kk_integer_from_small(12)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x728, _ctx);
    _match_x720 = _brw_x729; /*bool*/
    if (_match_x720) {
      kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
      kk_integer_drop(n, _ctx);
      kk_define_string_literal(, _s_x1447, 2, "12", _ctx)
      return kk_string_dup(_s_x1447, _ctx);
    }
    {
      bool _match_x721;
      kk_integer_t _brw_x726;
      {
        struct kk_std_time_time_Time* _con_x1448 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _pat_0_0_1 = _con_x1448->date;
        kk_std_time_date__clock _x_0_1 = _con_x1448->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x1448->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x1448->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x1448->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x1448->instant;
        struct kk_std_time_date_Clock* _con_x1449 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1450 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1451 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__clock_dup(_x_0_1, _ctx);
        {
          struct kk_std_time_date_Clock* _con_x1452 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
          kk_std_num_ddouble__ddouble _pat_1_2 = _con_x1452->seconds;
          kk_integer_t _x_2 = _con_x1452->hours;
          kk_integer_t _pat_0_3 = _con_x1452->minutes;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
            kk_integer_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(_x_0_1, _ctx);
          }
          else {
            kk_integer_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(_x_0_1, _ctx);
          }
          _brw_x726 = _x_2; /*int*/
        }
      }
      bool _brw_x727 = kk_integer_lte_borrow(_brw_x726,(kk_integer_from_small(11)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x726, _ctx);
      _match_x721 = _brw_x727; /*bool*/
      if (_match_x721) {
        kk_string_t _own_x724;
        kk_integer_t _x_x1453;
        {
          struct kk_std_time_time_Time* _con_x1454 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_0_2 = _con_x1454->date;
          kk_std_time_date__clock _x_0_2 = _con_x1454->clock;
          kk_std_time_calendar__calendar _pat_7_2 = _con_x1454->calendar;
          kk_std_time_duration__duration _pat_16_2 = _con_x1454->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2 = _con_x1454->timezone;
          kk_std_time_instant__instant _pat_23_2 = _con_x1454->instant;
          struct kk_std_time_date_Clock* _con_x1455 = kk_std_time_date__as_Clock(_x_0_2, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1456 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1457 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
          kk_string_t _pat_18_2 = _con_x1454->tzabbrv;
          kk_string_t _pat_8_2 = _con_x1456->name;
          kk_string_t _pat_9_2 = _con_x1456->long_name;
          kk_string_t _pat_10_2 = _con_x1456->month_prefix;
          kk_function_t _pat_11_2 = _con_x1456->show_era;
          kk_function_t _pat_12_2 = _con_x1456->instant_to_dc;
          kk_function_t _pat_13_2 = _con_x1456->dc_to_instant;
          kk_function_t _pat_14_2 = _con_x1456->days_to_date;
          kk_function_t _pat_15_2 = _con_x1456->date_to_days;
          kk_string_t _pat_20_2 = _con_x1457->name;
          kk_function_t _pat_21_2 = _con_x1457->utc_delta;
          kk_function_t _pat_22_2 = _con_x1457->utc_inverse;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_7_2, _ctx)) {
              kk_string_drop(_pat_9_2, _ctx);
              kk_string_drop(_pat_8_2, _ctx);
              kk_function_drop(_pat_15_2, _ctx);
              kk_function_drop(_pat_14_2, _ctx);
              kk_function_drop(_pat_13_2, _ctx);
              kk_function_drop(_pat_12_2, _ctx);
              kk_function_drop(_pat_11_2, _ctx);
              kk_string_drop(_pat_10_2, _ctx);
              kk_datatype_ptr_free(_pat_7_2, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_7_2, _ctx);
            }
            kk_std_time_instant__instant_drop(_pat_23_2, _ctx);
            if kk_likely(kk_datatype_ptr_is_unique(_pat_19_2, _ctx)) {
              kk_function_drop(_pat_22_2, _ctx);
              kk_function_drop(_pat_21_2, _ctx);
              kk_string_drop(_pat_20_2, _ctx);
              kk_datatype_ptr_free(_pat_19_2, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_19_2, _ctx);
            }
            kk_string_drop(_pat_18_2, _ctx);
            kk_std_time_date__date_drop(_pat_0_0_2, _ctx);
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_std_time_date__clock_dup(_x_0_2, _ctx);
            kk_datatype_ptr_decref(t, _ctx);
          }
          {
            struct kk_std_time_date_Clock* _con_x1458 = kk_std_time_date__as_Clock(_x_0_2, _ctx);
            kk_std_num_ddouble__ddouble _pat_1_3 = _con_x1458->seconds;
            kk_integer_t _x_3 = _con_x1458->hours;
            kk_integer_t _pat_0_4 = _con_x1458->minutes;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_2, _ctx)) {
              kk_integer_drop(_pat_0_4, _ctx);
              kk_datatype_ptr_free(_x_0_2, _ctx);
            }
            else {
              kk_integer_dup(_x_3, _ctx);
              kk_datatype_ptr_decref(_x_0_2, _ctx);
            }
            _x_x1453 = _x_3; /*int*/
          }
        }
        _own_x724 = kk_std_core_int_show(_x_x1453, _ctx); /*string*/
        kk_string_t _brw_x725;
        kk_std_core_types__optional _x_x1459 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
        _brw_x725 = kk_std_core_string_pad_left(_own_x724, n, _x_x1459, _ctx); /*string*/
        kk_integer_drop(n, _ctx);
        return _brw_x725;
      }
      {
        kk_integer_t i_0_10086;
        kk_integer_t _x_x1460;
        {
          struct kk_std_time_time_Time* _con_x1461 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_0_3 = _con_x1461->date;
          kk_std_time_date__clock _x_0_3 = _con_x1461->clock;
          kk_std_time_calendar__calendar _pat_7_3 = _con_x1461->calendar;
          kk_std_time_duration__duration _pat_16_3 = _con_x1461->tzdelta;
          kk_std_time_calendar__timezone _pat_19_3 = _con_x1461->timezone;
          kk_std_time_instant__instant _pat_23_3 = _con_x1461->instant;
          struct kk_std_time_date_Clock* _con_x1462 = kk_std_time_date__as_Clock(_x_0_3, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1463 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1464 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
          kk_string_t _pat_18_3 = _con_x1461->tzabbrv;
          kk_string_t _pat_8_3 = _con_x1463->name;
          kk_string_t _pat_9_3 = _con_x1463->long_name;
          kk_string_t _pat_10_3 = _con_x1463->month_prefix;
          kk_function_t _pat_11_3 = _con_x1463->show_era;
          kk_function_t _pat_12_3 = _con_x1463->instant_to_dc;
          kk_function_t _pat_13_3 = _con_x1463->dc_to_instant;
          kk_function_t _pat_14_3 = _con_x1463->days_to_date;
          kk_function_t _pat_15_3 = _con_x1463->date_to_days;
          kk_string_t _pat_20_3 = _con_x1464->name;
          kk_function_t _pat_21_3 = _con_x1464->utc_delta;
          kk_function_t _pat_22_3 = _con_x1464->utc_inverse;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_7_3, _ctx)) {
              kk_string_drop(_pat_9_3, _ctx);
              kk_string_drop(_pat_8_3, _ctx);
              kk_function_drop(_pat_15_3, _ctx);
              kk_function_drop(_pat_14_3, _ctx);
              kk_function_drop(_pat_13_3, _ctx);
              kk_function_drop(_pat_12_3, _ctx);
              kk_function_drop(_pat_11_3, _ctx);
              kk_string_drop(_pat_10_3, _ctx);
              kk_datatype_ptr_free(_pat_7_3, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_7_3, _ctx);
            }
            kk_std_time_instant__instant_drop(_pat_23_3, _ctx);
            if kk_likely(kk_datatype_ptr_is_unique(_pat_19_3, _ctx)) {
              kk_function_drop(_pat_22_3, _ctx);
              kk_function_drop(_pat_21_3, _ctx);
              kk_string_drop(_pat_20_3, _ctx);
              kk_datatype_ptr_free(_pat_19_3, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_19_3, _ctx);
            }
            kk_string_drop(_pat_18_3, _ctx);
            kk_std_time_date__date_drop(_pat_0_0_3, _ctx);
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_std_time_date__clock_dup(_x_0_3, _ctx);
            kk_datatype_ptr_decref(t, _ctx);
          }
          {
            struct kk_std_time_date_Clock* _con_x1465 = kk_std_time_date__as_Clock(_x_0_3, _ctx);
            kk_std_num_ddouble__ddouble _pat_1_4 = _con_x1465->seconds;
            kk_integer_t _x_4 = _con_x1465->hours;
            kk_integer_t _pat_0_5 = _con_x1465->minutes;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_3, _ctx)) {
              kk_integer_drop(_pat_0_5, _ctx);
              kk_datatype_ptr_free(_x_0_3, _ctx);
            }
            else {
              kk_integer_dup(_x_4, _ctx);
              kk_datatype_ptr_decref(_x_0_3, _ctx);
            }
            _x_x1460 = _x_4; /*int*/
          }
        }
        i_0_10086 = kk_integer_add_small_const(_x_x1460, -12, _ctx); /*int*/
        kk_string_t _own_x722 = kk_std_core_int_show(i_0_10086, _ctx); /*string*/;
        kk_string_t _brw_x723;
        kk_std_core_types__optional _x_x1466 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
        _brw_x723 = kk_std_core_string_pad_left(_own_x722, n, _x_x1466, _ctx); /*string*/
        kk_integer_drop(n, _ctx);
        return _brw_x723;
      }
    }
  }
}

kk_string_t kk_std_time_format_format_frac(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1468;
  {
    struct kk_std_time_time_Time* _con_x1469 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1469->date;
    kk_std_time_date__clock _x_0 = _con_x1469->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1469->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1469->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1469->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1469->instant;
    struct kk_std_time_date_Clock* _con_x1470 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1471 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1472 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1469->tzabbrv;
    kk_string_t _pat_8 = _con_x1471->name;
    kk_string_t _pat_9 = _con_x1471->long_name;
    kk_string_t _pat_10 = _con_x1471->month_prefix;
    kk_function_t _pat_11 = _con_x1471->show_era;
    kk_function_t _pat_12 = _con_x1471->instant_to_dc;
    kk_function_t _pat_13 = _con_x1471->dc_to_instant;
    kk_function_t _pat_14 = _con_x1471->days_to_date;
    kk_function_t _pat_15 = _con_x1471->date_to_days;
    kk_string_t _pat_20 = _con_x1472->name;
    kk_function_t _pat_21 = _con_x1472->utc_delta;
    kk_function_t _pat_22 = _con_x1472->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_function_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_7, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x1473 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1473->seconds;
      kk_integer_t _pat_0 = _con_x1473->hours;
      kk_integer_t _pat_1 = _con_x1473->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1468 = _x; /*std/num/ddouble/ddouble*/
    }
  }
  frac = kk_std_num_ddouble_fraction(_x_x1468, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x718;
  double _x_x1474;
  {
    double _x_1 = frac.hi;
    _x_x1474 = _x_1; /*float64*/
  }
  _match_x718 = (_x_x1474 == (0x0p+0)); /*bool*/
  if (_match_x718) {
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    kk_integer_t _b_x258_259 = n; /*int*/;
    kk_string_t _x_x1476;
    kk_std_core_types__optional _x_x1477 = kk_std_core_types__new_Optional(kk_integer_box(_b_x258_259, _ctx), _ctx); /*? 7*/
    _x_x1476 = kk_std_num_ddouble_show_fixed(frac, _x_x1477, _ctx); /*string*/
    return kk_std_core_sslice_tail(_x_x1476, _ctx);
  }
}

kk_string_t kk_std_time_format_format_frac0(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1478;
  {
    struct kk_std_time_time_Time* _con_x1479 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1479->date;
    kk_std_time_date__clock _x_0 = _con_x1479->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1479->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1479->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1479->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1479->instant;
    struct kk_std_time_date_Clock* _con_x1480 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1481 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1482 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1479->tzabbrv;
    kk_string_t _pat_8 = _con_x1481->name;
    kk_string_t _pat_9 = _con_x1481->long_name;
    kk_string_t _pat_10 = _con_x1481->month_prefix;
    kk_function_t _pat_11 = _con_x1481->show_era;
    kk_function_t _pat_12 = _con_x1481->instant_to_dc;
    kk_function_t _pat_13 = _con_x1481->dc_to_instant;
    kk_function_t _pat_14 = _con_x1481->days_to_date;
    kk_function_t _pat_15 = _con_x1481->date_to_days;
    kk_string_t _pat_20 = _con_x1482->name;
    kk_function_t _pat_21 = _con_x1482->utc_delta;
    kk_function_t _pat_22 = _con_x1482->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_function_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_7, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_7, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x1483 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1483->seconds;
      kk_integer_t _pat_0 = _con_x1483->hours;
      kk_integer_t _pat_1 = _con_x1483->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1478 = _x; /*std/num/ddouble/ddouble*/
    }
  }
  frac = kk_std_num_ddouble_fraction(_x_x1478, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x714;
  double _x_x1484;
  {
    double _x_1 = frac.hi;
    _x_x1484 = _x_1; /*float64*/
  }
  _match_x714 = (_x_x1484 == (0x0p+0)); /*bool*/
  if (_match_x714) {
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    kk_string_t _own_x716;
    kk_integer_t _b_x260_262 = kk_integer_dup(n, _ctx); /*int*/;
    kk_string_t _x_x1486;
    kk_std_core_types__optional _x_x1487 = kk_std_core_types__new_Optional(kk_integer_box(_b_x260_262, _ctx), _ctx); /*? 7*/
    _x_x1486 = kk_std_num_ddouble_show_fixed(frac, _x_x1487, _ctx); /*string*/
    _own_x716 = kk_std_core_sslice_tail(_x_x1486, _ctx); /*string*/
    kk_integer_t _brw_x715 = kk_integer_add_small_const(n, 1, _ctx); /*int*/;
    kk_string_t _brw_x717;
    kk_std_core_types__optional _x_x1488 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
    _brw_x717 = kk_std_core_string_pad_right(_own_x716, _brw_x715, _x_x1488, _ctx); /*string*/
    kk_integer_drop(_brw_x715, _ctx);
    return _brw_x717;
  }
}

kk_string_t kk_std_time_format_format_tz_offset(kk_std_time_time__time t, kk_integer_t n, kk_string_t hmsep, kk_string_t utc, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, hmsep : string, utc : string) -> string */ 
  kk_integer_drop(n, _ctx);
  kk_std_time_duration__duration _x_x1489;
  {
    struct kk_std_time_time_Time* _con_x1490 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1490->date;
    kk_std_time_date__clock _pat_4 = _con_x1490->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1490->calendar;
    kk_std_time_duration__duration _x = _con_x1490->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1490->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1490->instant;
    struct kk_std_time_date_Clock* _con_x1491 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1492 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1493 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1490->tzabbrv;
    kk_integer_t _pat_5 = _con_x1491->hours;
    kk_integer_t _pat_6 = _con_x1491->minutes;
    kk_string_t _pat_9 = _con_x1492->name;
    kk_string_t _pat_10 = _con_x1492->long_name;
    kk_string_t _pat_11 = _con_x1492->month_prefix;
    kk_function_t _pat_12 = _con_x1492->show_era;
    kk_function_t _pat_13 = _con_x1492->instant_to_dc;
    kk_function_t _pat_14 = _con_x1492->dc_to_instant;
    kk_function_t _pat_15 = _con_x1492->days_to_date;
    kk_function_t _pat_16 = _con_x1492->date_to_days;
    kk_string_t _pat_20 = _con_x1493->name;
    kk_function_t _pat_21 = _con_x1493->utc_delta;
    kk_function_t _pat_22 = _con_x1493->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_function_drop(_pat_16, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_string_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_8, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4, _ctx)) {
        kk_integer_drop(_pat_6, _ctx);
        kk_integer_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(_pat_4, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1489 = _x; /*std/time/duration/duration*/
  }
  kk_std_core_types__optional _x_x1494 = kk_std_core_types__new_Optional(kk_string_box(utc), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1495 = kk_std_core_types__new_Optional(kk_string_box(hmsep), _ctx); /*? 7*/
  return kk_std_time_time_show_tzdelta(_x_x1489, _x_x1494, _x_x1495, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_time_format_format_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t hmsep_10099;
  bool _match_x713 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  if (_match_x713) {
    hmsep_10099 = kk_string_empty(); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1497, 1, ":", _ctx)
    hmsep_10099 = kk_string_dup(_s_x1497, _ctx); /*string*/
  }
  kk_string_t utc_10100;
  bool _match_x711;
  bool _brw_x712 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x711 = _brw_x712; /*bool*/
  if (_match_x711) {
    kk_define_string_literal(, _s_x1498, 5, "+0000", _ctx)
    utc_10100 = kk_string_dup(_s_x1498, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1499, 6, "+00:00", _ctx)
    utc_10100 = kk_string_dup(_s_x1499, _ctx); /*string*/
  }
  kk_std_time_duration__duration _x_x1500;
  {
    struct kk_std_time_time_Time* _con_x1501 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1501->date;
    kk_std_time_date__clock _pat_4 = _con_x1501->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1501->calendar;
    kk_std_time_duration__duration _x = _con_x1501->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1501->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1501->instant;
    struct kk_std_time_date_Clock* _con_x1502 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1503 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1504 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1501->tzabbrv;
    kk_integer_t _pat_5 = _con_x1502->hours;
    kk_integer_t _pat_6 = _con_x1502->minutes;
    kk_string_t _pat_9 = _con_x1503->name;
    kk_string_t _pat_10 = _con_x1503->long_name;
    kk_string_t _pat_11 = _con_x1503->month_prefix;
    kk_function_t _pat_12 = _con_x1503->show_era;
    kk_function_t _pat_13 = _con_x1503->instant_to_dc;
    kk_function_t _pat_14 = _con_x1503->dc_to_instant;
    kk_function_t _pat_15 = _con_x1503->days_to_date;
    kk_function_t _pat_16 = _con_x1503->date_to_days;
    kk_string_t _pat_20 = _con_x1504->name;
    kk_function_t _pat_21 = _con_x1504->utc_delta;
    kk_function_t _pat_22 = _con_x1504->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_function_drop(_pat_16, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_string_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_8, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4, _ctx)) {
        kk_integer_drop(_pat_6, _ctx);
        kk_integer_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(_pat_4, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1500 = _x; /*std/time/duration/duration*/
  }
  kk_std_core_types__optional _x_x1505 = kk_std_core_types__new_Optional(kk_string_box(utc_10100), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1506 = kk_std_core_types__new_Optional(kk_string_box(hmsep_10099), _ctx); /*? 7*/
  return kk_std_time_time_show_tzdelta(_x_x1500, _x_x1505, _x_x1506, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_time_format_format_utc_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t utc_10105;
  bool _match_x709;
  bool _brw_x710 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x709 = _brw_x710; /*bool*/
  if (_match_x709) {
    utc_10105 = kk_string_empty(); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1508, 1, "Z", _ctx)
    utc_10105 = kk_string_dup(_s_x1508, _ctx); /*string*/
  }
  kk_std_time_duration__duration _x_x1509;
  {
    struct kk_std_time_time_Time* _con_x1510 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1510->date;
    kk_std_time_date__clock _pat_4 = _con_x1510->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1510->calendar;
    kk_std_time_duration__duration _x = _con_x1510->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1510->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1510->instant;
    struct kk_std_time_date_Clock* _con_x1511 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1512 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1513 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1510->tzabbrv;
    kk_integer_t _pat_5 = _con_x1511->hours;
    kk_integer_t _pat_6 = _con_x1511->minutes;
    kk_string_t _pat_9 = _con_x1512->name;
    kk_string_t _pat_10 = _con_x1512->long_name;
    kk_string_t _pat_11 = _con_x1512->month_prefix;
    kk_function_t _pat_12 = _con_x1512->show_era;
    kk_function_t _pat_13 = _con_x1512->instant_to_dc;
    kk_function_t _pat_14 = _con_x1512->dc_to_instant;
    kk_function_t _pat_15 = _con_x1512->days_to_date;
    kk_function_t _pat_16 = _con_x1512->date_to_days;
    kk_string_t _pat_20 = _con_x1513->name;
    kk_function_t _pat_21 = _con_x1513->utc_delta;
    kk_function_t _pat_22 = _con_x1513->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_function_drop(_pat_16, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_string_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_8, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4, _ctx)) {
        kk_integer_drop(_pat_6, _ctx);
        kk_integer_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(_pat_4, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19, _ctx)) {
        kk_function_drop(_pat_22, _ctx);
        kk_function_drop(_pat_21, _ctx);
        kk_string_drop(_pat_20, _ctx);
        kk_datatype_ptr_free(_pat_19, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19, _ctx);
      }
      kk_string_drop(_pat_18, _ctx);
      kk_std_time_date__date_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1509 = _x; /*std/time/duration/duration*/
  }
  kk_std_core_types__optional _x_x1514 = kk_std_core_types__new_Optional(kk_string_box(utc_10105), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1515;
  kk_box_t _x_x1516;
  kk_string_t _x_x1517;
  kk_define_string_literal(, _s_x1518, 1, ":", _ctx)
  _x_x1517 = kk_string_dup(_s_x1518, _ctx); /*string*/
  _x_x1516 = kk_string_box(_x_x1517); /*7*/
  _x_x1515 = kk_std_core_types__new_Optional(_x_x1516, _ctx); /*? 7*/
  return kk_std_time_time_show_tzdelta(_x_x1509, _x_x1514, _x_x1515, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_time_format_format_timestamp(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_drop(n, _ctx);
  kk_std_time_instant__instant _x_x1519;
  {
    struct kk_std_time_time_Time* _con_x1520 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1520->date;
    kk_std_time_date__clock _pat_4 = _con_x1520->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1520->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1520->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1520->timezone;
    kk_std_time_instant__instant _x = _con_x1520->instant;
    struct kk_std_time_date_Clock* _con_x1521 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1522 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1523 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1520->tzabbrv;
    kk_integer_t _pat_5 = _con_x1521->hours;
    kk_integer_t _pat_6 = _con_x1521->minutes;
    kk_string_t _pat_9 = _con_x1522->name;
    kk_string_t _pat_10 = _con_x1522->long_name;
    kk_string_t _pat_11 = _con_x1522->month_prefix;
    kk_function_t _pat_12 = _con_x1522->show_era;
    kk_function_t _pat_13 = _con_x1522->instant_to_dc;
    kk_function_t _pat_14 = _con_x1522->dc_to_instant;
    kk_function_t _pat_15 = _con_x1522->days_to_date;
    kk_function_t _pat_16 = _con_x1522->date_to_days;
    kk_string_t _pat_21 = _con_x1523->name;
    kk_function_t _pat_22 = _con_x1523->utc_delta;
    kk_function_t _pat_23 = _con_x1523->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_function_drop(_pat_16, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_string_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_datatype_ptr_free(_pat_8, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4, _ctx)) {
        kk_integer_drop(_pat_6, _ctx);
        kk_integer_drop(_pat_5, _ctx);
        kk_datatype_ptr_free(_pat_4, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20, _ctx)) {
        kk_function_drop(_pat_23, _ctx);
        kk_function_drop(_pat_22, _ctx);
        kk_string_drop(_pat_21, _ctx);
        kk_datatype_ptr_free(_pat_20, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20, _ctx);
      }
      kk_string_drop(_pat_19, _ctx);
      kk_std_time_date__date_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1519 = _x; /*std/time/instant/instant*/
  }
  kk_std_core_types__optional _x_x1524 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  return kk_std_time_instant_show_raw(_x_x1519, _x_x1524, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1527__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1527(kk_function_t _fself, kk_box_t _b_x285, kk_box_t _b_x286, kk_box_t _b_x287, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1527(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1527, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1527(kk_function_t _fself, kk_box_t _b_x285, kk_box_t _b_x286, kk_box_t _b_x287, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1528;
  kk_std_time_time__time _x_x1529 = kk_std_time_time__time_unbox(_b_x285, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1530 = kk_integer_unbox(_b_x286, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1531 = kk_std_time_locale__time_locale_unbox(_b_x287, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1528 = kk_std_time_format_format_year(_x_x1529, _x_x1530, _x_x1531, _ctx); /*string*/
  return kk_string_box(_x_x1528);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1535__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1535(kk_function_t _fself, kk_box_t _b_x295, kk_box_t _b_x296, kk_box_t _b_x297, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1535(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1535, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1535(kk_function_t _fself, kk_box_t _b_x295, kk_box_t _b_x296, kk_box_t _b_x297, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1536;
  kk_std_time_time__time _x_x1537 = kk_std_time_time__time_unbox(_b_x295, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1538 = kk_integer_unbox(_b_x296, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1539 = kk_std_time_locale__time_locale_unbox(_b_x297, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1536 = kk_std_time_format_format_month(_x_x1537, _x_x1538, _x_x1539, _ctx); /*string*/
  return kk_string_box(_x_x1536);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1543__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1543(kk_function_t _fself, kk_box_t _b_x305, kk_box_t _b_x306, kk_box_t _b_x307, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1543(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1543, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1543(kk_function_t _fself, kk_box_t _b_x305, kk_box_t _b_x306, kk_box_t _b_x307, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1544;
  kk_std_time_time__time _x_x1545 = kk_std_time_time__time_unbox(_b_x305, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1546 = kk_integer_unbox(_b_x306, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1547 = kk_std_time_locale__time_locale_unbox(_b_x307, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1544 = kk_std_time_format_format_day(_x_x1545, _x_x1546, _x_x1547, _ctx); /*string*/
  return kk_string_box(_x_x1544);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1551(kk_function_t _fself, kk_box_t _b_x315, kk_box_t _b_x316, kk_box_t _b_x317, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1551(kk_function_t _fself, kk_box_t _b_x315, kk_box_t _b_x316, kk_box_t _b_x317, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1552;
  kk_std_time_time__time _x_x1553 = kk_std_time_time__time_unbox(_b_x315, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1554 = kk_integer_unbox(_b_x316, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1555 = kk_std_time_locale__time_locale_unbox(_b_x317, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1552 = kk_std_time_format_format_hours(_x_x1553, _x_x1554, _x_x1555, _ctx); /*string*/
  return kk_string_box(_x_x1552);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1559__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1559(kk_function_t _fself, kk_box_t _b_x325, kk_box_t _b_x326, kk_box_t _b_x327, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1559(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1559, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1559(kk_function_t _fself, kk_box_t _b_x325, kk_box_t _b_x326, kk_box_t _b_x327, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1560;
  kk_std_time_time__time _x_x1561 = kk_std_time_time__time_unbox(_b_x325, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1562 = kk_integer_unbox(_b_x326, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1563 = kk_std_time_locale__time_locale_unbox(_b_x327, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1560 = kk_std_time_format_format_minutes(_x_x1561, _x_x1562, _x_x1563, _ctx); /*string*/
  return kk_string_box(_x_x1560);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1567__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1567(kk_function_t _fself, kk_box_t _b_x335, kk_box_t _b_x336, kk_box_t _b_x337, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1567(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1567, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1567(kk_function_t _fself, kk_box_t _b_x335, kk_box_t _b_x336, kk_box_t _b_x337, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1568;
  kk_std_time_time__time _x_x1569 = kk_std_time_time__time_unbox(_b_x335, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1570 = kk_integer_unbox(_b_x336, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1571 = kk_std_time_locale__time_locale_unbox(_b_x337, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1568 = kk_std_time_format_format_seconds(_x_x1569, _x_x1570, _x_x1571, _ctx); /*string*/
  return kk_string_box(_x_x1568);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1575__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1575(kk_function_t _fself, kk_box_t _b_x345, kk_box_t _b_x346, kk_box_t _b_x347, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1575(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1575, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1575(kk_function_t _fself, kk_box_t _b_x345, kk_box_t _b_x346, kk_box_t _b_x347, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1576;
  kk_std_time_time__time _x_x1577 = kk_std_time_time__time_unbox(_b_x345, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1578 = kk_integer_unbox(_b_x346, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1579 = kk_std_time_locale__time_locale_unbox(_b_x347, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1576 = kk_std_time_format_format_timezone(_x_x1577, _x_x1578, _x_x1579, _ctx); /*string*/
  return kk_string_box(_x_x1576);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1583__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1583(kk_function_t _fself, kk_box_t _b_x355, kk_box_t _b_x356, kk_box_t _b_x357, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1583(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1583, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1583(kk_function_t _fself, kk_box_t _b_x355, kk_box_t _b_x356, kk_box_t _b_x357, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1584;
  kk_std_time_time__time _x_x1585 = kk_std_time_time__time_unbox(_b_x355, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1586 = kk_integer_unbox(_b_x356, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1587 = kk_std_time_locale__time_locale_unbox(_b_x357, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1584 = kk_std_time_format_format_utc_timezone(_x_x1585, _x_x1586, _x_x1587, _ctx); /*string*/
  return kk_string_box(_x_x1584);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1591__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1591(kk_function_t _fself, kk_box_t _b_x365, kk_box_t _b_x366, kk_box_t _b_x367, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1591(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1591, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1591(kk_function_t _fself, kk_box_t _b_x365, kk_box_t _b_x366, kk_box_t _b_x367, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1592;
  kk_std_time_time__time _x_x1593 = kk_std_time_time__time_unbox(_b_x365, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1594 = kk_integer_unbox(_b_x366, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1595 = kk_std_time_locale__time_locale_unbox(_b_x367, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1592 = kk_std_time_format_format_frac0(_x_x1593, _x_x1594, _x_x1595, _ctx); /*string*/
  return kk_string_box(_x_x1592);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1599__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1599(kk_function_t _fself, kk_box_t _b_x375, kk_box_t _b_x376, kk_box_t _b_x377, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1599, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1599(kk_function_t _fself, kk_box_t _b_x375, kk_box_t _b_x376, kk_box_t _b_x377, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1600;
  kk_std_time_time__time _x_x1601 = kk_std_time_time__time_unbox(_b_x375, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1602 = kk_integer_unbox(_b_x376, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1603 = kk_std_time_locale__time_locale_unbox(_b_x377, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1600 = kk_std_time_format_format_frac(_x_x1601, _x_x1602, _x_x1603, _ctx); /*string*/
  return kk_string_box(_x_x1600);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1607(kk_function_t _fself, kk_box_t _b_x385, kk_box_t _b_x386, kk_box_t _b_x387, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1607, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1607(kk_function_t _fself, kk_box_t _b_x385, kk_box_t _b_x386, kk_box_t _b_x387, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1608;
  kk_std_time_time__time _x_x1609 = kk_std_time_time__time_unbox(_b_x385, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1610 = kk_integer_unbox(_b_x386, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1611 = kk_std_time_locale__time_locale_unbox(_b_x387, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1608 = kk_std_time_format_format_calname(_x_x1609, _x_x1610, _x_x1611, _ctx); /*string*/
  return kk_string_box(_x_x1608);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1615__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1615(kk_function_t _fself, kk_box_t _b_x395, kk_box_t _b_x396, kk_box_t _b_x397, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1615(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1615, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1615(kk_function_t _fself, kk_box_t _b_x395, kk_box_t _b_x396, kk_box_t _b_x397, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1616;
  kk_std_time_time__time _x_x1617 = kk_std_time_time__time_unbox(_b_x395, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1618 = kk_integer_unbox(_b_x396, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1619 = kk_std_time_locale__time_locale_unbox(_b_x397, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1616 = kk_std_time_format_format_era(_x_x1617, _x_x1618, _x_x1619, _ctx); /*string*/
  return kk_string_box(_x_x1616);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1623__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1623(kk_function_t _fself, kk_box_t _b_x405, kk_box_t _b_x406, kk_box_t _b_x407, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1623(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1623, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1623(kk_function_t _fself, kk_box_t _b_x405, kk_box_t _b_x406, kk_box_t _b_x407, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1624;
  kk_std_time_time__time _x_x1625 = kk_std_time_time__time_unbox(_b_x405, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1626 = kk_integer_unbox(_b_x406, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1627 = kk_std_time_locale__time_locale_unbox(_b_x407, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1624 = kk_std_time_format_format_absyear(_x_x1625, _x_x1626, _x_x1627, _ctx); /*string*/
  return kk_string_box(_x_x1624);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1631__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1631(kk_function_t _fself, kk_box_t _b_x415, kk_box_t _b_x416, kk_box_t _b_x417, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1631(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1631, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1631(kk_function_t _fself, kk_box_t _b_x415, kk_box_t _b_x416, kk_box_t _b_x417, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1632;
  kk_std_time_time__time _x_x1633 = kk_std_time_time__time_unbox(_b_x415, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1634 = kk_integer_unbox(_b_x416, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1635 = kk_std_time_locale__time_locale_unbox(_b_x417, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1632 = kk_std_time_format_format_weekday(_x_x1633, _x_x1634, _x_x1635, _ctx); /*string*/
  return kk_string_box(_x_x1632);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1639__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1639(kk_function_t _fself, kk_box_t _b_x425, kk_box_t _b_x426, kk_box_t _b_x427, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1639(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1639, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1639(kk_function_t _fself, kk_box_t _b_x425, kk_box_t _b_x426, kk_box_t _b_x427, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1640;
  kk_std_time_time__time _x_x1641 = kk_std_time_time__time_unbox(_b_x425, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1642 = kk_integer_unbox(_b_x426, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1643 = kk_std_time_locale__time_locale_unbox(_b_x427, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1640 = kk_std_time_format_format_hours12(_x_x1641, _x_x1642, _x_x1643, _ctx); /*string*/
  return kk_string_box(_x_x1640);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1647__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1647(kk_function_t _fself, kk_box_t _b_x435, kk_box_t _b_x436, kk_box_t _b_x437, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1647(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1647, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1647(kk_function_t _fself, kk_box_t _b_x435, kk_box_t _b_x436, kk_box_t _b_x437, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1648;
  kk_std_time_time__time _x_x1649 = kk_std_time_time__time_unbox(_b_x435, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1650 = kk_integer_unbox(_b_x436, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1651 = kk_std_time_locale__time_locale_unbox(_b_x437, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1648 = kk_std_time_format_format_ampm(_x_x1649, _x_x1650, _x_x1651, _ctx); /*string*/
  return kk_string_box(_x_x1648);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1655__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1655(kk_function_t _fself, kk_box_t _b_x445, kk_box_t _b_x446, kk_box_t _b_x447, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1655(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1655, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1655(kk_function_t _fself, kk_box_t _b_x445, kk_box_t _b_x446, kk_box_t _b_x447, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1656;
  kk_std_time_time__time _x_x1657 = kk_std_time_time__time_unbox(_b_x445, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1658 = kk_integer_unbox(_b_x446, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1659 = kk_std_time_locale__time_locale_unbox(_b_x447, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1656 = kk_std_time_format_format_upper_ampm(_x_x1657, _x_x1658, _x_x1659, _ctx); /*string*/
  return kk_string_box(_x_x1656);
}


// lift anonymous function
struct kk_std_time_format_formats_fun1663__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun1663(kk_function_t _fself, kk_box_t _b_x455, kk_box_t _b_x456, kk_box_t _b_x457, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun1663(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun1663, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun1663(kk_function_t _fself, kk_box_t _b_x455, kk_box_t _b_x456, kk_box_t _b_x457, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1664;
  kk_std_time_time__time _x_x1665 = kk_std_time_time__time_unbox(_b_x455, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x1666 = kk_integer_unbox(_b_x456, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x1667 = kk_std_time_locale__time_locale_unbox(_b_x457, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x1664 = kk_std_time_format_format_timestamp(_x_x1665, _x_x1666, _x_x1667, _ctx); /*string*/
  return kk_string_box(_x_x1664);
}

kk_std_core_types__list kk_std_time_format_formats;


// lift anonymous function
struct kk_std_time_format_format_pat_fun1669__t {
  struct kk_function_s _base;
  kk_char_t h;
};
static bool kk_std_time_format_format_pat_fun1669(kk_function_t _fself, kk_box_t _b_x586, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_pat_fun1669(kk_char_t h, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1669__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_pat_fun1669__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_pat_fun1669, kk_context());
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_format_format_pat_fun1669(kk_function_t _fself, kk_box_t _b_x586, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1669__t* _self = kk_function_as(struct kk_std_time_format_format_pat_fun1669__t*, _fself, _ctx);
  kk_char_t h = _self->h; /* char */
  kk_drop_match(_self, {kk_skip_dup(h, _ctx);}, {}, _ctx)
  kk_char_t c_664 = kk_char_unbox(_b_x586, KK_OWNED, _ctx); /*char*/;
  return (c_664 != h);
}


// lift anonymous function
struct kk_std_time_format_format_pat_fun1672__t {
  struct kk_function_s _base;
  kk_char_t h;
};
static bool kk_std_time_format_format_pat_fun1672(kk_function_t _fself, kk_box_t _b_x596, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_pat_fun1672(kk_char_t h, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1672__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_pat_fun1672__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_pat_fun1672, kk_context());
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_format_format_pat_fun1672(kk_function_t _fself, kk_box_t _b_x596, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1672__t* _self = kk_function_as(struct kk_std_time_format_format_pat_fun1672__t*, _fself, _ctx);
  kk_char_t h = _self->h; /* char */
  kk_drop_match(_self, {kk_skip_dup(h, _ctx);}, {}, _ctx)
  kk_char_t c_0_665 = kk_char_unbox(_b_x596, KK_OWNED, _ctx); /*char*/;
  return (c_0_665 != h);
}


// lift anonymous function
struct kk_std_time_format_format_pat_fun1674__t {
  struct kk_function_s _base;
  kk_char_t h;
};
static bool kk_std_time_format_format_pat_fun1674(kk_function_t _fself, kk_box_t _b_x606, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_pat_fun1674(kk_char_t h, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1674__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_pat_fun1674__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_pat_fun1674, kk_context());
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_format_format_pat_fun1674(kk_function_t _fself, kk_box_t _b_x606, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1674__t* _self = kk_function_as(struct kk_std_time_format_format_pat_fun1674__t*, _fself, _ctx);
  kk_char_t h = _self->h; /* char */
  kk_drop_match(_self, {kk_skip_dup(h, _ctx);}, {}, _ctx)
  kk_char_t c_0_0_666 = kk_char_unbox(_b_x606, KK_OWNED, _ctx); /*char*/;
  return (c_0_0_666 == h);
}


// lift anonymous function
struct kk_std_time_format_format_pat_fun1677__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_integer_t n;
  kk_std_core_types__list rest_0_0;
  kk_std_time_time__time t;
  kk_char_t h;
};
static kk_std_core_types__maybe kk_std_time_format_format_pat_fun1677(kk_function_t _fself, kk_box_t _b_x631, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_pat_fun1677(kk_std_time_locale__time_locale locale, kk_integer_t n, kk_std_core_types__list rest_0_0, kk_std_time_time__time t, kk_char_t h, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1677__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_pat_fun1677__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_pat_fun1677, kk_context());
  _self->locale = locale;
  _self->n = n;
  _self->rest_0_0 = rest_0_0;
  _self->t = t;
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_time_format_format_pat_fun1677(kk_function_t _fself, kk_box_t _b_x631, kk_context_t* _ctx) {
  struct kk_std_time_format_format_pat_fun1677__t* _self = kk_function_as(struct kk_std_time_format_format_pat_fun1677__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_integer_t n = _self->n; /* int */
  kk_std_core_types__list rest_0_0 = _self->rest_0_0; /* list<char> */
  kk_std_time_time__time t = _self->t; /* std/time/time/time */
  kk_char_t h = _self->h; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_integer_dup(n, _ctx);kk_std_core_types__list_dup(rest_0_0, _ctx);kk_std_time_time__time_dup(t, _ctx);kk_skip_dup(h, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple3 _match_x704 = kk_std_core_types__tuple3_unbox(_b_x631, KK_OWNED, _ctx); /*(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)*/;
  {
    kk_box_t _box_x609 = _match_x704.fst;
    kk_box_t _box_x610 = _match_x704.snd;
    kk_box_t _fun_unbox_x618 = _match_x704.thd;
    kk_char_t c_1 = kk_char_unbox(_box_x609, KK_BORROWED, _ctx);
    kk_integer_t m_0 = kk_integer_unbox(_box_x610, _ctx);
    kk_box_dup(_fun_unbox_x618, _ctx);
    kk_integer_dup(m_0, _ctx);
    kk_std_core_types__tuple3_drop(_match_x704, _ctx);
    bool _match_x705 = (c_1 != h); /*bool*/;
    if (_match_x705) {
      kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
      kk_std_core_types__list_drop(rest_0_0, _ctx);
      kk_integer_drop(n, _ctx);
      kk_integer_drop(m_0, _ctx);
      kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
      kk_box_drop(_fun_unbox_x618, _ctx);
      return kk_std_core_types__new_Nothing(_ctx);
    }
    {
      kk_integer_t _b_x624_638;
      bool _match_x706 = kk_integer_lte_borrow(n,m_0,kk_context()); /*bool*/;
      if (_match_x706) {
        kk_integer_drop(m_0, _ctx);
        _b_x624_638 = n; /*int*/
      }
      else {
        kk_integer_drop(n, _ctx);
        _b_x624_638 = m_0; /*int*/
      }
      kk_box_t _x_x1678;
      kk_std_core_types__tuple2 _x_x1679;
      kk_box_t _x_x1680;
      kk_function_t _x_x1681 = kk_function_unbox(_fun_unbox_x618, _ctx); /*(619, 620, 621) -> 622*/
      _x_x1680 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1681, (_x_x1681, kk_std_time_time__time_box(t, _ctx), kk_integer_box(_b_x624_638, _ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx), _ctx); /*622*/
      _x_x1679 = kk_std_core_types__new_Tuple2(_x_x1680, kk_std_core_types__list_box(rest_0_0, _ctx), _ctx); /*(134, 135)*/
      _x_x1678 = kk_std_core_types__tuple2_box(_x_x1679, _ctx); /*88*/
      return kk_std_core_types__new_Just(_x_x1678, _ctx);
    }
  }
}

kk_std_core_types__tuple2 kk_std_time_format_format_pat(kk_std_time_time__time t, kk_char_t h, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, h : char, fmt : list<char>, locale : std/time/locale/time-locale) -> (string, list<char>) */ 
  bool _match_x700 = (h == ('"')); /*bool*/;
  if (_match_x700) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    kk_std_core_types__tuple2 _match_x708;
    kk_std_core_types__list _x_x1668 = kk_std_core_types__list_dup(fmt, _ctx); /*list<char>*/
    _match_x708 = kk_std_core_list_span(_x_x1668, kk_std_time_format_new_format_pat_fun1669(h, _ctx), _ctx); /*(list<4921>, list<4921>)*/
    {
      kk_box_t _box_x587 = _match_x708.fst;
      kk_box_t _box_x588 = _match_x708.snd;
      kk_std_core_types__list quoted = kk_std_core_types__list_unbox(_box_x587, KK_BORROWED, _ctx);
      kk_std_core_types__list end = kk_std_core_types__list_unbox(_box_x588, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(end, _ctx);
      kk_std_core_types__list_dup(quoted, _ctx);
      kk_std_core_types__tuple2_drop(_match_x708, _ctx);
      if (kk_std_core_types__is_Nil(end, _ctx)) {
        kk_std_core_types__list_drop(quoted, _ctx);
        kk_string_t _b_x589_648 = kk_std_core_string_char_fs_string(h, _ctx); /*string*/;
        return kk_std_core_types__new_Tuple2(kk_string_box(_b_x589_648), kk_std_core_types__list_box(fmt, _ctx), _ctx);
      }
      {
        struct kk_std_core_types_Cons* _con_x1670 = kk_std_core_types__as_Cons(end, _ctx);
        kk_box_t _box_x591 = _con_x1670->head;
        kk_std_core_types__list rest = _con_x1670->tail;
        kk_std_core_types__list_drop(fmt, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(end, _ctx)) {
          kk_datatype_ptr_free(end, _ctx);
        }
        else {
          kk_std_core_types__list_dup(rest, _ctx);
          kk_datatype_ptr_decref(end, _ctx);
        }
        kk_string_t _b_x592_650 = kk_std_core_string_listchar_fs_string(quoted, _ctx); /*string*/;
        return kk_std_core_types__new_Tuple2(kk_string_box(_b_x592_650), kk_std_core_types__list_box(rest, _ctx), _ctx);
      }
    }
  }
  {
    bool _match_x701 = (h == ('\'')); /*bool*/;
    if (_match_x701) {
      kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
      kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
      kk_std_core_types__tuple2 _match_x707;
      kk_std_core_types__list _x_x1671 = kk_std_core_types__list_dup(fmt, _ctx); /*list<char>*/
      _match_x707 = kk_std_core_list_span(_x_x1671, kk_std_time_format_new_format_pat_fun1672(h, _ctx), _ctx); /*(list<4921>, list<4921>)*/
      {
        kk_box_t _box_x597 = _match_x707.fst;
        kk_box_t _box_x598 = _match_x707.snd;
        kk_std_core_types__list quoted_0 = kk_std_core_types__list_unbox(_box_x597, KK_BORROWED, _ctx);
        kk_std_core_types__list end_0 = kk_std_core_types__list_unbox(_box_x598, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(end_0, _ctx);
        kk_std_core_types__list_dup(quoted_0, _ctx);
        kk_std_core_types__tuple2_drop(_match_x707, _ctx);
        if (kk_std_core_types__is_Nil(end_0, _ctx)) {
          kk_std_core_types__list_drop(quoted_0, _ctx);
          kk_string_t _b_x599_654 = kk_std_core_string_char_fs_string(h, _ctx); /*string*/;
          return kk_std_core_types__new_Tuple2(kk_string_box(_b_x599_654), kk_std_core_types__list_box(fmt, _ctx), _ctx);
        }
        {
          struct kk_std_core_types_Cons* _con_x1673 = kk_std_core_types__as_Cons(end_0, _ctx);
          kk_box_t _box_x601 = _con_x1673->head;
          kk_std_core_types__list rest_0 = _con_x1673->tail;
          kk_std_core_types__list_drop(fmt, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(end_0, _ctx)) {
            kk_datatype_ptr_free(end_0, _ctx);
          }
          else {
            kk_std_core_types__list_dup(rest_0, _ctx);
            kk_datatype_ptr_decref(end_0, _ctx);
          }
          kk_string_t _b_x602_656 = kk_std_core_string_listchar_fs_string(quoted_0, _ctx); /*string*/;
          return kk_std_core_types__new_Tuple2(kk_string_box(_b_x602_656), kk_std_core_types__list_box(rest_0, _ctx), _ctx);
        }
      }
    }
    {
      bool _match_x702 = kk_std_core_char_is_alpha(h, _ctx); /*bool*/;
      if (_match_x702) {
        kk_std_core_types__tuple2 _match_x703 = kk_std_core_list_span(fmt, kk_std_time_format_new_format_pat_fun1674(h, _ctx), _ctx); /*(list<4921>, list<4921>)*/;
        {
          kk_box_t _box_x607 = _match_x703.fst;
          kk_box_t _box_x608 = _match_x703.snd;
          kk_std_core_types__list hs = kk_std_core_types__list_unbox(_box_x607, KK_BORROWED, _ctx);
          kk_std_core_types__list rest_0_0 = kk_std_core_types__list_unbox(_box_x608, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(hs, _ctx);
          kk_std_core_types__list_dup(rest_0_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x703, _ctx);
          kk_integer_t x_10108 = kk_std_core_list__lift_length_5730(hs, kk_integer_from_small(0), _ctx); /*int*/;
          kk_integer_t n = kk_integer_add_small_const(x_10108, 1, _ctx); /*int*/;
          kk_std_core_types__maybe m_10111;
          kk_std_core_types__list _x_x1675 = kk_std_core_types__list_dup(kk_std_time_format_formats, _ctx); /*list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>*/
          kk_function_t _x_x1676;
          kk_std_core_types__list_dup(rest_0_0, _ctx);
          _x_x1676 = kk_std_time_format_new_format_pat_fun1677(locale, n, rest_0_0, t, h, _ctx); /*(1650) -> 1652 (forall<a> maybe<a>)*/
          m_10111 = kk_std_core_list_foreach_while(_x_x1675, _x_x1676, _ctx); /*maybe<(string, list<char>)>*/
          if (kk_std_core_types__is_Nothing(m_10111, _ctx)) {
            kk_box_t _x_x1682;
            kk_string_t _x_x1683 = kk_string_empty(); /*string*/
            _x_x1682 = kk_string_box(_x_x1683); /*134*/
            return kk_std_core_types__new_Tuple2(_x_x1682, kk_std_core_types__list_box(rest_0_0, _ctx), _ctx);
          }
          {
            kk_box_t _box_x643 = m_10111._cons.Just.value;
            kk_std_core_types__tuple2 x_0 = kk_std_core_types__tuple2_unbox(_box_x643, KK_BORROWED, _ctx);
            kk_std_core_types__list_drop(rest_0_0, _ctx);
            kk_std_core_types__tuple2_dup(x_0, _ctx);
            kk_std_core_types__maybe_drop(m_10111, _ctx);
            return x_0;
          }
        }
      }
      {
        kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
        kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
        kk_string_t _b_x644_662 = kk_std_core_string_char_fs_string(h, _ctx); /*string*/;
        return kk_std_core_types__new_Tuple2(kk_string_box(_b_x644_662), kk_std_core_types__list_box(fmt, _ctx), _ctx);
      }
    }
  }
}

kk_string_t kk_std_time_format_format_list(kk_std_time_time__time t, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, fmt : list<char>, locale : std/time/locale/time-locale) -> string */ 
  if (kk_std_core_types__is_Nil(fmt, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1686 = kk_std_core_types__as_Cons(fmt, _ctx);
    kk_box_t _box_x667 = _con_x1686->head;
    kk_std_core_types__list cs = _con_x1686->tail;
    kk_char_t c = kk_char_unbox(_box_x667, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(fmt, _ctx)) {
      kk_datatype_ptr_free(fmt, _ctx);
    }
    else {
      kk_std_core_types__list_dup(cs, _ctx);
      kk_datatype_ptr_decref(fmt, _ctx);
    }
    kk_std_core_types__tuple2 _match_x699;
    kk_std_time_time__time _x_x1687 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
    kk_std_time_locale__time_locale _x_x1688 = kk_std_time_locale__time_locale_dup(locale, _ctx); /*std/time/locale/time-locale*/
    _match_x699 = kk_std_time_format_format_pat(_x_x1687, c, cs, _x_x1688, _ctx); /*(string, list<char>)*/
    {
      kk_box_t _box_x668 = _match_x699.fst;
      kk_box_t _box_x669 = _match_x699.snd;
      kk_string_t formatted = kk_string_unbox(_box_x668);
      kk_std_core_types__list rest = kk_std_core_types__list_unbox(_box_x669, KK_BORROWED, _ctx);
      kk_string_dup(formatted, _ctx);
      kk_std_core_types__list_dup(rest, _ctx);
      kk_std_core_types__tuple2_drop(_match_x699, _ctx);
      kk_string_t _x_x1689 = kk_std_time_format_format_list(t, rest, locale, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(formatted, _x_x1689, _ctx);
    }
  }
}
 
// /* Format a time according to format string `fmt` and using a optional
//    time locale (= `time-locale-en-iso`).
// 
// Letters (``a`` to ``z``) are always interpreted as a pattern where unknown letter
// patterns are ignored. Any literal text should be quote-escaped i.e. use `"'GMT'ZZ"`
// to display as `"GMT-07:00"` (in the PST time zone). Any characters other then
// an ascii letter are displayed as is.
// 
// Patterns of 2 letters are zero-padded on the left to always
// display as 2 digits. Allowed patterns:
// 
// * ``Y``: the year as a number (without zero padding) (``1970``, ``203``)
// * ``YY``, ```YYYY``: the year in upto 4 digits (``70``, ``1970``, ``0203``).
//   If the year is smaller than zero or larger than 9999, the year is displayed
//   with 5 or more digits and prepended with an explicit sign (``-00030``, ``+10345``).
// * ``M``, ``MM``: the month. (``1``, ``03``). In case of an ISO week (`cal-iso-week`)
//   or ISO month (`cal-iso-month`) calendar, the month is prefixed with ``W`` or ``M``.
// * ``MMM``, ``MMMM``: name of the month in the specified `locale`. (``Jan``, ``January``)
// * ``D``, ``DD``: the day of the month. (``1``, ``08``). If ``DD`` is used and this
//   is an ISO week calendar (`cal-iso-week`) just one digit is used for the week day.
// * ``DDD``: the day of the year. (``087``)
// * ``d``: the ISO day of the week, 1 for Monday ending in 7 for Sunday.
// * ``dd``, ``ddd``,``dddd``: the day of the week in the current `locale`. (``We``,``Wed``,``Wednesday``)
// * ``h``, ``hh``: the hours using a 12-hour clock (with am/pm). (``9``, ``09``)
// * ``H``, ``HH``: the hours using a 24-hour clock. (``21``, ``09``)
// * ``m``, ``mm``: the minutes. (``9``, ``09``)
// * ``s``, ``ss``: the whole seconds. (``8``, ``08``)
// * ``a``, ``aa``: AM/PM designation. (``a``, ``am``)
// * ``A``, ``AA``: AM/PM designation in upper-case. (``A``, ``AM``)
// * ``f``,...,``fffffffff``: upto 9 digits of a fraction of a second. Starts with a dot. (``.320``,  ``.000``)
// * ``F``,...,``FFFFFFFFF``: upto 9 digits of a fraction of a second. If not zero, starts with a dot.
//   In contrast to the ``f`` patterns displays the minimal number of required digits
//   (and is not right-padded with zeros). (``.32``)
// * ``z``: timezone offset in hours and minutes separated by a colon. Use ``+00:00`` for UTC time. (``+01:00``)
// * ``zz``: timezone offset in hours and minutes without a separator. Use ``+0000`` for UTC time. (``-0700``)
// * ``Z``: timezone offset in hours and minutes separated by a colon, use ``Z`` for UTC time.
// * ``ZZ``: timezone offset in hours and minutes separated by colon, use an empty string for UTC time.
// * ``x``: fractional seconds since `min-time`. (``63610768799.429``)
// * ``YYYYYY``: the year in [ECMAscript](https://www.ecma-international.org/ecma-262/5.1/#sec-15.9.1.15.1) 6 digits, prepended with the sign. (``+002016``,``-000023``,``+000000``)
// * ``y``: the absolute value of the year as a number (without zero padding). Useful when
//   displaying Julian (`cal-julian`) negative years as ``10 BC`` for example (e.g. ``"y E"``).
// * ``C``, ``CC``: the short or long calendar name. (The short name is empty for the standard ISO calendars).
// * ``E``: the era name, for example ``CE`` for the Gregorian calendar.
// * ``'...'``, ``"..."``: anything between quotes is displayed as is. (``'M'M`` becomes ``M11`` for November)
// 
// There are also various forms to display dates and times in a locale specific way.
// We give examples in English and Dutch. The lower-case ``l`` variants use short
// names for month- and day names.
// 
// * ``t``: hours and minutes (``3:21pm, 15:21``)
// * ``tt``: hours, minutes, and seconds (``3:21:01pm, 15:21:01``)
// * ``L``, ``l``: a date (``09/29/2016, 29.09.2016``) and (``9/29/2016, 29.9.2016``)
// * ``LL``, ``ll``: date with month name (``29 September 2016, 29 september 2016``) and (``29 Sep 2016, 29 sep 2016``)
// * ``LLL``, ``lll``: date with month name and time (``29 September 2016 1:15pm, 29 september 2016 13:15``)
// * ``LLLL``, ``llll``: date with day name, month name, and time (``Thursday, 29 September 2016 1:15pm``) and (``Thu, 29 Sep 2016 1:15pm``)
// 
// After formatting, any left- or right white space is trimmed. This allows specifiers
// like `"YYYY E C"` that display correctly even if the era or calendar name is empty.
// 
// For example, to display a time in the standard [Internet Message Format](https://tools.ietf.org/html/rfc2822#section-3.3)
// you can use `now().format("ddd, D MMM Y HH:mm:ss zz")` displayed as `"Tue, 27 Sep 2016 06:36:55 -0700"` for example.\
// A standard ISO string can be formatted as, `"YYYY-MM-DD'T'HH:mm:ssFFFFFFFFFZ C"`.
// 
// */

kk_string_t kk_std_time_format_format(kk_std_time_time__time t, kk_string_t fmt, kk_std_core_types__optional locale, kk_context_t* _ctx) { /* (t : std/time/time/time, fmt : string, locale : ? std/time/locale/time-locale) -> string */ 
  kk_std_core_types__list _x_x1690;
  kk_string_t _x_x1691;
  kk_string_t _x_x1692;
  kk_std_time_locale__time_locale _x_x1693;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x670 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x670, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    _x_x1693 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    _x_x1693 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1692 = kk_std_time_format_expand_locales(fmt, _x_x1693, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1694;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x671 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x671, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    _x_x1694 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    _x_x1694 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1691 = kk_std_time_format_expand_locales(_x_x1692, _x_x1694, _ctx); /*string*/
  _x_x1690 = kk_std_core_string_list(_x_x1691, _ctx); /*list<char>*/
  kk_std_time_locale__time_locale _x_x1695;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x672 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x672, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x1695 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x1695 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  return kk_std_time_format_format_list(t, _x_x1690, _x_x1695, _ctx);
}
 
// Show a time as a standard ISO date. Will use automatic week date
// or month date format for the  `cal-iso-week` and `cal-iso-month` calendars.

kk_string_t kk_std_time_format_show_iso_date(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : std/time/time/time) -> string */ 
  kk_std_core_types__list _x_x1696;
  kk_string_t _x_x1697;
  kk_string_t _x_x1698;
  kk_string_t _x_x1699;
  kk_define_string_literal(, _s_x1700, 10, "YYYY-MM-DD", _ctx)
  _x_x1699 = kk_string_dup(_s_x1700, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1701;
  kk_std_core_types__optional _match_x698 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x698, _ctx)) {
    kk_box_t _box_x673 = _match_x698._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x673, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(_match_x698, _ctx);
    _x_x1701 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x698, _ctx);
    _x_x1701 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1698 = kk_std_time_format_expand_locales(_x_x1699, _x_x1701, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1702;
  kk_std_core_types__optional _match_x697 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x697, _ctx)) {
    kk_box_t _box_x674 = _match_x697._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x674, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(_match_x697, _ctx);
    _x_x1702 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x697, _ctx);
    _x_x1702 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1697 = kk_std_time_format_expand_locales(_x_x1698, _x_x1702, _ctx); /*string*/
  _x_x1696 = kk_std_core_string_list(_x_x1697, _ctx); /*list<char>*/
  kk_std_time_locale__time_locale _x_x1703;
  kk_std_core_types__optional _match_x696 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x696, _ctx)) {
    kk_box_t _box_x675 = _match_x696._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x675, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
    kk_std_core_types__optional_drop(_match_x696, _ctx);
    _x_x1703 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x696, _ctx);
    _x_x1703 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  return kk_std_time_format_format_list(t, _x_x1696, _x_x1703, _ctx);
}
 
// Show a time as a standard ISO string. Will use automatic week date
// or month date format for the `cal-iso-week` and `cal-iso-month` calendars.

kk_string_t kk_std_time_format_show_iso(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : std/time/time/time) -> string */ 
  kk_string_t fmt_10119;
  kk_string_t _x_x1704;
  kk_define_string_literal(, _s_x1705, 17, "HH:mm:ssFFFFFFFFF", _ctx)
  _x_x1704 = kk_string_dup(_s_x1705, _ctx); /*string*/
  kk_string_t _x_x1706;
  kk_define_string_literal(, _s_x1707, 3, "Z C", _ctx)
  _x_x1706 = kk_string_dup(_s_x1707, _ctx); /*string*/
  fmt_10119 = kk_std_core_types__lp__plus__plus__rp_(_x_x1704, _x_x1706, _ctx); /*string*/
  kk_string_t _x_x1708;
  kk_std_time_time__time _x_x1709 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  _x_x1708 = kk_std_time_format_show_iso_date(_x_x1709, _ctx); /*string*/
  kk_string_t _x_x1710;
  kk_string_t _x_x1711;
  kk_define_string_literal(, _s_x1712, 1, "T", _ctx)
  _x_x1711 = kk_string_dup(_s_x1712, _ctx); /*string*/
  kk_string_t _x_x1713;
  kk_std_core_types__list _x_x1714;
  kk_string_t _x_x1715;
  kk_string_t _x_x1716;
  kk_std_time_locale__time_locale _x_x1717;
  kk_std_core_types__optional _match_x695 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x695, _ctx)) {
    kk_box_t _box_x676 = _match_x695._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x676, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(_match_x695, _ctx);
    _x_x1717 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x695, _ctx);
    _x_x1717 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1716 = kk_std_time_format_expand_locales(fmt_10119, _x_x1717, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1718;
  kk_std_core_types__optional _match_x694 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x694, _ctx)) {
    kk_box_t _box_x677 = _match_x694._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x677, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(_match_x694, _ctx);
    _x_x1718 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x694, _ctx);
    _x_x1718 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1715 = kk_std_time_format_expand_locales(_x_x1716, _x_x1718, _ctx); /*string*/
  _x_x1714 = kk_std_core_string_list(_x_x1715, _ctx); /*list<char>*/
  kk_std_time_locale__time_locale _x_x1719;
  kk_std_core_types__optional _match_x693 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x693, _ctx)) {
    kk_box_t _box_x678 = _match_x693._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x678, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
    kk_std_core_types__optional_drop(_match_x693, _ctx);
    _x_x1719 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x693, _ctx);
    _x_x1719 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1713 = kk_std_time_format_format_list(t, _x_x1714, _x_x1719, _ctx); /*string*/
  _x_x1710 = kk_std_core_types__lp__plus__plus__rp_(_x_x1711, _x_x1713, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1708, _x_x1710, _ctx);
}
 
// Show time as a standard [Internet Message Format](https://tools.ietf.org/html/rfc2822#section-3.3) date.
// For example `now().show-imf` returns `"Fri, 9 Oct 2016 11:57:45 -0700"`

kk_string_t kk_std_time_format_show_imf(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : std/time/time/time) -> string */ 
  kk_std_time_time__time t_0_10121;
  kk_std_core_types__optional _x_x1720;
  kk_box_t _x_x1721;
  kk_std_time_calendar__calendar _x_x1722 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  _x_x1721 = kk_std_time_calendar__calendar_box(_x_x1722, _ctx); /*7*/
  _x_x1720 = kk_std_core_types__new_Optional(_x_x1721, _ctx); /*? 7*/
  t_0_10121 = kk_std_time_time_time_fs_time(t, kk_std_core_types__new_None(_ctx), _x_x1720, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  kk_std_core_types__list _x_x1723;
  kk_string_t _x_x1724;
  kk_string_t _x_x1725;
  kk_string_t _x_x1726;
  kk_define_string_literal(, _s_x1727, 24, "ddd, D MMM Y HH:mm:ss zz", _ctx)
  _x_x1726 = kk_string_dup(_s_x1727, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1728;
  kk_std_core_types__optional _match_x692 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x692, _ctx)) {
    kk_box_t _box_x681 = _match_x692._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x681, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(_match_x692, _ctx);
    _x_x1728 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x692, _ctx);
    _x_x1728 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1725 = kk_std_time_format_expand_locales(_x_x1726, _x_x1728, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1729;
  kk_std_core_types__optional _match_x691 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x691, _ctx)) {
    kk_box_t _box_x682 = _match_x691._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x682, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(_match_x691, _ctx);
    _x_x1729 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x691, _ctx);
    _x_x1729 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1724 = kk_std_time_format_expand_locales(_x_x1725, _x_x1729, _ctx); /*string*/
  _x_x1723 = kk_std_core_string_list(_x_x1724, _ctx); /*list<char>*/
  kk_std_time_locale__time_locale _x_x1730;
  kk_std_core_types__optional _match_x690 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x690, _ctx)) {
    kk_box_t _box_x683 = _match_x690._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x683, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
    kk_std_core_types__optional_drop(_match_x690, _ctx);
    _x_x1730 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x690, _ctx);
    _x_x1730 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  return kk_std_time_format_format_list(t_0_10121, _x_x1723, _x_x1730, _ctx);
}
 
// Show the time as a human readable string in the given `locale` (=`time-locale-en`)
// For example `now().show-en` -> `"Thu, 8 Oct 2016, 12:20pm"`. Uses the `"llll"` format string.

kk_string_t kk_std_time_format_show_in_locale(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx) { /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 
  kk_std_core_types__list _x_x1731;
  kk_string_t _x_x1732;
  kk_string_t _x_x1733;
  kk_string_t _x_x1734;
  kk_define_string_literal(, _s_x1735, 4, "llll", _ctx)
  _x_x1734 = kk_string_dup(_s_x1735, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1736;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x684 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5223 = kk_std_time_locale__time_locale_unbox(_box_x684, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5223, _ctx);
    _x_x1736 = _uniq_locale_5223; /*std/time/locale/time-locale*/
  }
  else {
    _x_x1736 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1733 = kk_std_time_format_expand_locales(_x_x1734, _x_x1736, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1737;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x685 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5223_0 = kk_std_time_locale__time_locale_unbox(_box_x685, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5223_0, _ctx);
    _x_x1737 = _uniq_locale_5223_0; /*std/time/locale/time-locale*/
  }
  else {
    _x_x1737 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1732 = kk_std_time_format_expand_locales(_x_x1733, _x_x1737, _ctx); /*string*/
  _x_x1731 = kk_std_core_string_list(_x_x1732, _ctx); /*list<char>*/
  kk_std_time_locale__time_locale _x_x1738;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x686 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5223_1 = kk_std_time_locale__time_locale_unbox(_box_x686, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5223_1, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x1738 = _uniq_locale_5223_1; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x1738 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  return kk_std_time_format_format_list(t, _x_x1731, _x_x1738, _ctx);
}
 
// Show the date in human readable string in the given `locale` (=`time-locale-en`).
// For example `now().show-en-date` -> `"Thu, 8 Oct 2016"`. Uses the `"ll"` format string.

kk_string_t kk_std_time_format_show_in_locale_date(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx) { /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 
  kk_std_core_types__list _x_x1739;
  kk_string_t _x_x1740;
  kk_string_t _x_x1741;
  kk_string_t _x_x1742;
  kk_define_string_literal(, _s_x1743, 2, "ll", _ctx)
  _x_x1742 = kk_string_dup(_s_x1743, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1744;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x687 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5244 = kk_std_time_locale__time_locale_unbox(_box_x687, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5244, _ctx);
    _x_x1744 = _uniq_locale_5244; /*std/time/locale/time-locale*/
  }
  else {
    _x_x1744 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1741 = kk_std_time_format_expand_locales(_x_x1742, _x_x1744, _ctx); /*string*/
  kk_std_time_locale__time_locale _x_x1745;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x688 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5244_0 = kk_std_time_locale__time_locale_unbox(_box_x688, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5244_0, _ctx);
    _x_x1745 = _uniq_locale_5244_0; /*std/time/locale/time-locale*/
  }
  else {
    _x_x1745 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x1740 = kk_std_time_format_expand_locales(_x_x1741, _x_x1745, _ctx); /*string*/
  _x_x1739 = kk_std_core_string_list(_x_x1740, _ctx); /*list<char>*/
  kk_std_time_locale__time_locale _x_x1746;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x689 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5244_1 = kk_std_time_locale__time_locale_unbox(_box_x689, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5244_1, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x1746 = _uniq_locale_5244_1; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x1746 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  return kk_std_time_format_format_list(t, _x_x1739, _x_x1746, _ctx);
}

// initialization
void kk_std_time_format__init(kk_context_t* _ctx){
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
  kk_std_text_parse__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_time__init(_ctx);
  kk_std_time_locale__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  kk_init_string_literal(kk_std_time_format_fmt_iso_date, _ctx)
  kk_init_string_literal(kk_std_time_format_fmt_iso_time, _ctx)
  kk_init_string_literal(kk_std_time_format_fmt_iso_timezone, _ctx)
  {
    kk_box_t _x_x1525;
    kk_std_core_types__tuple3 _x_x1526 = kk_std_core_types__new_Tuple3(kk_char_box('Y', _ctx), kk_integer_box(kk_integer_from_small(6), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1527(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1525 = kk_std_core_types__tuple3_box(_x_x1526, _ctx); /*79*/
    kk_std_core_types__list _x_x1532;
    kk_box_t _x_x1533;
    kk_std_core_types__tuple3 _x_x1534 = kk_std_core_types__new_Tuple3(kk_char_box('M', _ctx), kk_integer_box(kk_integer_from_small(4), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1535(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1533 = kk_std_core_types__tuple3_box(_x_x1534, _ctx); /*79*/
    kk_std_core_types__list _x_x1540;
    kk_box_t _x_x1541;
    kk_std_core_types__tuple3 _x_x1542 = kk_std_core_types__new_Tuple3(kk_char_box('D', _ctx), kk_integer_box(kk_integer_from_small(3), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1543(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1541 = kk_std_core_types__tuple3_box(_x_x1542, _ctx); /*79*/
    kk_std_core_types__list _x_x1548;
    kk_box_t _x_x1549;
    kk_std_core_types__tuple3 _x_x1550 = kk_std_core_types__new_Tuple3(kk_char_box('H', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1551(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1549 = kk_std_core_types__tuple3_box(_x_x1550, _ctx); /*79*/
    kk_std_core_types__list _x_x1556;
    kk_box_t _x_x1557;
    kk_std_core_types__tuple3 _x_x1558 = kk_std_core_types__new_Tuple3(kk_char_box('m', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1559(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1557 = kk_std_core_types__tuple3_box(_x_x1558, _ctx); /*79*/
    kk_std_core_types__list _x_x1564;
    kk_box_t _x_x1565;
    kk_std_core_types__tuple3 _x_x1566 = kk_std_core_types__new_Tuple3(kk_char_box('s', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1567(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1565 = kk_std_core_types__tuple3_box(_x_x1566, _ctx); /*79*/
    kk_std_core_types__list _x_x1572;
    kk_box_t _x_x1573;
    kk_std_core_types__tuple3 _x_x1574 = kk_std_core_types__new_Tuple3(kk_char_box('z', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1575(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1573 = kk_std_core_types__tuple3_box(_x_x1574, _ctx); /*79*/
    kk_std_core_types__list _x_x1580;
    kk_box_t _x_x1581;
    kk_std_core_types__tuple3 _x_x1582 = kk_std_core_types__new_Tuple3(kk_char_box('Z', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1583(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1581 = kk_std_core_types__tuple3_box(_x_x1582, _ctx); /*79*/
    kk_std_core_types__list _x_x1588;
    kk_box_t _x_x1589;
    kk_std_core_types__tuple3 _x_x1590 = kk_std_core_types__new_Tuple3(kk_char_box('f', _ctx), kk_integer_box(kk_integer_from_small(8), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1591(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1589 = kk_std_core_types__tuple3_box(_x_x1590, _ctx); /*79*/
    kk_std_core_types__list _x_x1596;
    kk_box_t _x_x1597;
    kk_std_core_types__tuple3 _x_x1598 = kk_std_core_types__new_Tuple3(kk_char_box('F', _ctx), kk_integer_box(kk_integer_from_small(8), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1599(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1597 = kk_std_core_types__tuple3_box(_x_x1598, _ctx); /*79*/
    kk_std_core_types__list _x_x1604;
    kk_box_t _x_x1605;
    kk_std_core_types__tuple3 _x_x1606 = kk_std_core_types__new_Tuple3(kk_char_box('C', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1607(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1605 = kk_std_core_types__tuple3_box(_x_x1606, _ctx); /*79*/
    kk_std_core_types__list _x_x1612;
    kk_box_t _x_x1613;
    kk_std_core_types__tuple3 _x_x1614 = kk_std_core_types__new_Tuple3(kk_char_box('E', _ctx), kk_integer_box(kk_integer_from_small(1), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1615(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1613 = kk_std_core_types__tuple3_box(_x_x1614, _ctx); /*79*/
    kk_std_core_types__list _x_x1620;
    kk_box_t _x_x1621;
    kk_std_core_types__tuple3 _x_x1622 = kk_std_core_types__new_Tuple3(kk_char_box('y', _ctx), kk_integer_box(kk_integer_from_small(1), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1623(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1621 = kk_std_core_types__tuple3_box(_x_x1622, _ctx); /*79*/
    kk_std_core_types__list _x_x1628;
    kk_box_t _x_x1629;
    kk_std_core_types__tuple3 _x_x1630 = kk_std_core_types__new_Tuple3(kk_char_box('d', _ctx), kk_integer_box(kk_integer_from_small(4), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1631(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1629 = kk_std_core_types__tuple3_box(_x_x1630, _ctx); /*79*/
    kk_std_core_types__list _x_x1636;
    kk_box_t _x_x1637;
    kk_std_core_types__tuple3 _x_x1638 = kk_std_core_types__new_Tuple3(kk_char_box('h', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1639(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1637 = kk_std_core_types__tuple3_box(_x_x1638, _ctx); /*79*/
    kk_std_core_types__list _x_x1644;
    kk_box_t _x_x1645;
    kk_std_core_types__tuple3 _x_x1646 = kk_std_core_types__new_Tuple3(kk_char_box('a', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1647(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1645 = kk_std_core_types__tuple3_box(_x_x1646, _ctx); /*79*/
    kk_std_core_types__list _x_x1652;
    kk_box_t _x_x1653;
    kk_std_core_types__tuple3 _x_x1654 = kk_std_core_types__new_Tuple3(kk_char_box('A', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1655(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1653 = kk_std_core_types__tuple3_box(_x_x1654, _ctx); /*79*/
    kk_std_core_types__list _x_x1660;
    kk_box_t _x_x1661;
    kk_std_core_types__tuple3 _x_x1662 = kk_std_core_types__new_Tuple3(kk_char_box('x', _ctx), kk_integer_box(kk_integer_from_small(1), _ctx), kk_function_box(kk_std_time_format_new_formats_fun1663(_ctx), _ctx), _ctx); /*(141, 142, 143)*/
    _x_x1661 = kk_std_core_types__tuple3_box(_x_x1662, _ctx); /*79*/
    _x_x1660 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1661, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1652 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1653, _x_x1660, _ctx); /*list<79>*/
    _x_x1644 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1645, _x_x1652, _ctx); /*list<79>*/
    _x_x1636 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1637, _x_x1644, _ctx); /*list<79>*/
    _x_x1628 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1629, _x_x1636, _ctx); /*list<79>*/
    _x_x1620 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1621, _x_x1628, _ctx); /*list<79>*/
    _x_x1612 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1613, _x_x1620, _ctx); /*list<79>*/
    _x_x1604 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1605, _x_x1612, _ctx); /*list<79>*/
    _x_x1596 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1597, _x_x1604, _ctx); /*list<79>*/
    _x_x1588 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1589, _x_x1596, _ctx); /*list<79>*/
    _x_x1580 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1581, _x_x1588, _ctx); /*list<79>*/
    _x_x1572 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1573, _x_x1580, _ctx); /*list<79>*/
    _x_x1564 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1565, _x_x1572, _ctx); /*list<79>*/
    _x_x1556 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1557, _x_x1564, _ctx); /*list<79>*/
    _x_x1548 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1549, _x_x1556, _ctx); /*list<79>*/
    _x_x1540 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1541, _x_x1548, _ctx); /*list<79>*/
    _x_x1532 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1533, _x_x1540, _ctx); /*list<79>*/
    kk_std_time_format_formats = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1525, _x_x1532, _ctx); /*list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>*/
  }
}

// termination
void kk_std_time_format__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__list_drop(kk_std_time_format_formats, _ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_time_locale__done(_ctx);
  kk_std_time_time__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_text_parse__done(_ctx);
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
