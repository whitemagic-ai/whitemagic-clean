// Koka generated module: std/time/format, koka version: 3.2.2, platform: 64-bit
#include "std_time_format.h"
kk_declare_string_literal(static, kk_std_time_format_fmt_iso_date, 10, "YYYY-MM-DD")
kk_declare_string_literal(static, kk_std_time_format_fmt_iso_time, 17, "HH:mm:ssFFFFFFFFF")
kk_declare_string_literal(static, kk_std_time_format_fmt_iso_timezone, 3, "Z C")

kk_string_t kk_std_time_format_format_weekday(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_std_time_date__weekday wd = kk_std_time_time_weekday(t, _ctx); /*std/time/date/weekday*/;
  bool _match_x1520 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  if (_match_x1520) {
    kk_integer_drop(n, _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_std_time_date_weekday_fs_show(wd, _ctx);
  }
  {
    kk_std_core_types__list days;
    bool _match_x1521 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
    if (_match_x1521) {
      kk_integer_drop(n, _ctx);
      {
        struct kk_std_time_locale_Time_locale* _con_x1796 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_0 = _con_x1796->lang_name;
        kk_std_core_types__list _pat_1_0 = _con_x1796->day_names;
        kk_std_core_types__list _pat_2_0 = _con_x1796->month_names;
        kk_std_core_types__list _pat_3 = _con_x1796->month_names_short;
        kk_std_core_types__list _pat_4 = _con_x1796->day_names_short;
        kk_std_core_types__list _x = _con_x1796->day_names_min;
        kk_string_t _pat_5 = _con_x1796->format_t;
        kk_string_t _pat_6 = _con_x1796->format_tt;
        kk_string_t _pat_7 = _con_x1796->format_l;
        kk_string_t _pat_8 = _con_x1796->format_ll;
        kk_string_t _pat_9 = _con_x1796->format_lll;
        kk_string_t _pat_10 = _con_x1796->format_llll;
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
      bool _match_x1522;
      bool _brw_x1523 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x1522 = _brw_x1523; /*bool*/
      if (_match_x1522) {
        struct kk_std_time_locale_Time_locale* _con_x1797 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_1 = _con_x1797->lang_name;
        kk_std_core_types__list _pat_1_1 = _con_x1797->day_names;
        kk_std_core_types__list _pat_2_2 = _con_x1797->month_names;
        kk_std_core_types__list _pat_3_1 = _con_x1797->month_names_short;
        kk_std_core_types__list _x_0 = _con_x1797->day_names_short;
        kk_std_core_types__list _pat_4_0 = _con_x1797->day_names_min;
        kk_string_t _pat_5_0 = _con_x1797->format_t;
        kk_string_t _pat_6_0 = _con_x1797->format_tt;
        kk_string_t _pat_7_0 = _con_x1797->format_l;
        kk_string_t _pat_8_0 = _con_x1797->format_ll;
        kk_string_t _pat_9_0 = _con_x1797->format_lll;
        kk_string_t _pat_10_0 = _con_x1797->format_llll;
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
        struct kk_std_time_locale_Time_locale* _con_x1798 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_2 = _con_x1798->lang_name;
        kk_std_core_types__list _x_1 = _con_x1798->day_names;
        kk_std_core_types__list _pat_1_2 = _con_x1798->month_names;
        kk_std_core_types__list _pat_2_3 = _con_x1798->month_names_short;
        kk_std_core_types__list _pat_3_2 = _con_x1798->day_names_short;
        kk_std_core_types__list _pat_4_2 = _con_x1798->day_names_min;
        kk_string_t _pat_5_1 = _con_x1798->format_t;
        kk_string_t _pat_6_1 = _con_x1798->format_tt;
        kk_string_t _pat_7_1 = _con_x1798->format_l;
        kk_string_t _pat_8_1 = _con_x1798->format_ll;
        kk_string_t _pat_9_1 = _con_x1798->format_lll;
        kk_string_t _pat_10_1 = _con_x1798->format_llll;
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
    kk_integer_t x_0_10008 = kk_std_time_date_int(wd, _ctx); /*int*/;
    kk_integer_t n_0_10007 = kk_integer_add_small_const(x_0_10008, -1, _ctx); /*int*/;
    kk_std_core_types__maybe m_10004;
    if (kk_std_core_types__is_Nil(days, _ctx)) {
      kk_integer_drop(n_0_10007, _ctx);
      m_10004 = kk_std_core_types__new_Nothing(_ctx); /*maybe<string>*/
    }
    else {
      m_10004 = kk_std_core_list__unroll_index_10029(days, n_0_10007, _ctx); /*maybe<string>*/
    }
    kk_string_t nothing_10005;
    kk_string_t _x_x1799;
    kk_define_string_literal(, _s_x1800, 1, "D", _ctx)
    _x_x1799 = kk_string_dup(_s_x1800, _ctx); /*string*/
    kk_string_t _x_x1801 = kk_std_time_date_weekday_fs_show(wd, _ctx); /*string*/
    nothing_10005 = kk_std_core_types__lp__plus__plus__rp_(_x_x1799, _x_x1801, _ctx); /*string*/
    if (kk_std_core_types__is_Nothing(m_10004, _ctx)) {
      return nothing_10005;
    }
    {
      kk_box_t _box_x0 = m_10004._cons.Just.value;
      kk_string_t x = kk_string_unbox(_box_x0);
      kk_string_drop(nothing_10005, _ctx);
      kk_string_dup(x, _ctx);
      kk_std_core_types__maybe_drop(m_10004, _ctx);
      return x;
    }
  }
}

kk_string_t kk_std_time_format_format_absyear(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_drop(n, _ctx);
  kk_integer_t _x_x1802;
  kk_integer_t _x_x1803;
  {
    struct kk_std_time_time_Time* _con_x1804 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x1804->date;
    kk_std_time_date__clock _pat_3 = _con_x1804->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1804->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1804->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1804->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1804->instant;
    struct kk_std_time_date_Clock* _con_x1805 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1806 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1807 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1804->tzabbrv;
    kk_integer_t _pat_4 = _con_x1805->hours;
    kk_integer_t _pat_5 = _con_x1805->minutes;
    kk_string_t _pat_8 = _con_x1806->name;
    kk_string_t _pat_9 = _con_x1806->long_name;
    kk_string_t _pat_10 = _con_x1806->month_prefix;
    kk_function_t _pat_11 = _con_x1806->show_era;
    kk_function_t _pat_12 = _con_x1806->instant_to_dc;
    kk_function_t _pat_13 = _con_x1806->dc_to_instant;
    kk_function_t _pat_14 = _con_x1806->days_to_date;
    kk_function_t _pat_15 = _con_x1806->date_to_days;
    kk_string_t _pat_20 = _con_x1807->name;
    kk_function_t _pat_21 = _con_x1807->utc_delta;
    kk_function_t _pat_22 = _con_x1807->utc_inverse;
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
      _x_x1803 = _x; /*int*/
    }
  }
  _x_x1802 = kk_integer_abs(_x_x1803,kk_context()); /*int*/
  return kk_std_core_int_show(_x_x1802, _ctx);
}

kk_string_t kk_std_time_format_format_calname(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x1517;
  kk_string_t _x_x1808;
  {
    struct kk_std_time_time_Time* _con_x1809 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1809->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1809->clock;
    kk_std_time_calendar__calendar _x_0 = _con_x1809->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1809->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1809->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1809->instant;
    struct kk_std_time_date_Clock* _con_x1810 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1811 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1812 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_calendar__calendar_dup(_x_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x1813 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x1813->name;
      kk_string_t _pat_1 = _con_x1813->long_name;
      kk_string_t _x = _con_x1813->month_prefix;
      kk_function_t _pat_2 = _con_x1813->show_era;
      kk_function_t _pat_3 = _con_x1813->instant_to_dc;
      kk_function_t _pat_4 = _con_x1813->dc_to_instant;
      kk_function_t _pat_5 = _con_x1813->days_to_date;
      kk_function_t _pat_6 = _con_x1813->date_to_days;
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
      _x_x1808 = _x; /*string*/
    }
  }
  kk_string_t _x_x1814 = kk_string_empty(); /*string*/
  _match_x1517 = kk_string_is_neq(_x_x1808,_x_x1814,kk_context()); /*bool*/
  if (_match_x1517) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    bool _match_x1518;
    bool _brw_x1519 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    _match_x1518 = _brw_x1519; /*bool*/
    if (_match_x1518) {
      struct kk_std_time_time_Time* _con_x1817 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x1817->date;
      kk_std_time_date__clock _pat_4_2 = _con_x1817->clock;
      kk_std_time_calendar__calendar _x_2 = _con_x1817->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1817->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1817->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1817->instant;
      struct kk_std_time_date_Clock* _con_x1818 = kk_std_time_date__as_Clock(_pat_4_2, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1819 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1820 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_string_t _pat_18_0 = _con_x1817->tzabbrv;
      kk_integer_t _pat_5_2 = _con_x1818->hours;
      kk_integer_t _pat_6_2 = _con_x1818->minutes;
      kk_string_t _pat_20_0 = _con_x1820->name;
      kk_function_t _pat_21_0 = _con_x1820->utc_delta;
      kk_function_t _pat_22_0 = _con_x1820->utc_inverse;
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
        struct kk_std_time_calendar_Calendar* _con_x1821 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
        kk_string_t _pat_0_2 = _con_x1821->name;
        kk_string_t _x_1 = _con_x1821->long_name;
        kk_string_t _pat_1_2 = _con_x1821->month_prefix;
        kk_function_t _pat_2_1 = _con_x1821->show_era;
        kk_function_t _pat_3_1 = _con_x1821->instant_to_dc;
        kk_function_t _pat_4_1 = _con_x1821->dc_to_instant;
        kk_function_t _pat_5_1 = _con_x1821->days_to_date;
        kk_function_t _pat_6_1 = _con_x1821->date_to_days;
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
      struct kk_std_time_time_Time* _con_x1822 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_5 = _con_x1822->date;
      kk_std_time_date__clock _pat_4_4 = _con_x1822->clock;
      kk_std_time_calendar__calendar _x_4 = _con_x1822->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x1822->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x1822->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x1822->instant;
      struct kk_std_time_date_Clock* _con_x1823 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1824 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1825 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_string_t _pat_18_1 = _con_x1822->tzabbrv;
      kk_integer_t _pat_5_4 = _con_x1823->hours;
      kk_integer_t _pat_6_4 = _con_x1823->minutes;
      kk_string_t _pat_20_1 = _con_x1825->name;
      kk_function_t _pat_21_1 = _con_x1825->utc_delta;
      kk_function_t _pat_22_1 = _con_x1825->utc_inverse;
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
        struct kk_std_time_calendar_Calendar* _con_x1826 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
        kk_string_t _x_3 = _con_x1826->name;
        kk_string_t _pat_0_4 = _con_x1826->long_name;
        kk_string_t _pat_1_4 = _con_x1826->month_prefix;
        kk_function_t _pat_2_4 = _con_x1826->show_era;
        kk_function_t _pat_3_3 = _con_x1826->instant_to_dc;
        kk_function_t _pat_4_3 = _con_x1826->dc_to_instant;
        kk_function_t _pat_5_3 = _con_x1826->days_to_date;
        kk_function_t _pat_6_3 = _con_x1826->date_to_days;
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
  kk_string_t s_10018;
  bool _match_x1514;
  kk_integer_t _brw_x1515;
  {
    struct kk_std_time_time_Time* _con_x1827 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1827->date;
    kk_std_time_date__clock _x_0 = _con_x1827->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1827->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1827->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1827->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1827->instant;
    struct kk_std_time_date_Clock* _con_x1828 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1829 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1830 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1827->tzabbrv;
    kk_string_t _pat_8 = _con_x1829->name;
    kk_string_t _pat_9 = _con_x1829->long_name;
    kk_string_t _pat_10 = _con_x1829->month_prefix;
    kk_function_t _pat_11 = _con_x1829->show_era;
    kk_function_t _pat_12 = _con_x1829->instant_to_dc;
    kk_function_t _pat_13 = _con_x1829->dc_to_instant;
    kk_function_t _pat_14 = _con_x1829->days_to_date;
    kk_function_t _pat_15 = _con_x1829->date_to_days;
    kk_string_t _pat_20 = _con_x1830->name;
    kk_function_t _pat_21 = _con_x1830->utc_delta;
    kk_function_t _pat_22 = _con_x1830->utc_inverse;
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
      struct kk_std_time_date_Clock* _con_x1831 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1 = _con_x1831->seconds;
      kk_integer_t _x = _con_x1831->hours;
      kk_integer_t _pat_0 = _con_x1831->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _brw_x1515 = _x; /*int*/
    }
  }
  bool _brw_x1516 = kk_integer_lte_borrow(_brw_x1515,(kk_integer_from_small(11)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1515, _ctx);
  _match_x1514 = _brw_x1516; /*bool*/
  if (_match_x1514) {
    kk_define_string_literal(, _s_x1832, 2, "am", _ctx)
    s_10018 = kk_string_dup(_s_x1832, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x1833, 2, "pm", _ctx)
    s_10018 = kk_string_dup(_s_x1833, _ctx); /*string*/
  }
  kk_std_core_types__optional n_0_10019 = kk_std_core_types__new_Optional(kk_integer_box(n, _ctx), _ctx); /*? int*/;
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s_10018, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x1834;
  bool _match_x1509;
  kk_integer_t _brw_x1512;
  if (kk_std_core_types__is_Optional(n_0_10019, _ctx)) {
    kk_box_t _box_x3 = n_0_10019._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x3, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    _brw_x1512 = _uniq_n_414; /*int*/
  }
  else {
    _brw_x1512 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x1513 = kk_integer_eq_borrow(_brw_x1512,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1512, _ctx);
  _match_x1509 = _brw_x1513; /*bool*/
  if (_match_x1509) {
    kk_std_core_types__optional_drop(n_0_10019, _ctx);
    _x_x1834 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x1510;
    kk_integer_t _x_x1835;
    if (kk_std_core_types__is_Optional(n_0_10019, _ctx)) {
      kk_box_t _box_x4 = n_0_10019._cons._Optional.value;
      kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x4, _ctx);
      kk_integer_dup(_uniq_n_414_0, _ctx);
      kk_std_core_types__optional_drop(n_0_10019, _ctx);
      _x_x1835 = _uniq_n_414_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n_0_10019, _ctx);
      _x_x1835 = kk_integer_from_small(1); /*int*/
    }
    _brw_x1510 = kk_integer_add_small_const(_x_x1835, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x1511 = kk_std_core_sslice_extend(slice_0, _brw_x1510, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x1510, _ctx);
    _x_x1834 = _brw_x1511; /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x1834, _ctx);
}
 
// lifted local: @lift-pquoted@10524, s, pquoted, @spec-x10385
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10376, using:
// @uniq-pred@10376 = fn(c: char){
//   std/core/char/(!=)(c, quote);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_pquoted_10525(kk_char_t quote, kk_std_core_sslice__sslice _uniq_slice_10375, kk_std_core_types__list _uniq_acc_10377, kk_context_t* _ctx) { /* (quote : char, sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1508;
  kk_std_core_sslice__sslice _x_x1836 = kk_std_core_sslice__sslice_dup(_uniq_slice_10375, _ctx); /*sslice/sslice*/
  _match_x1508 = kk_std_core_sslice_next(_x_x1836, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1508, _ctx)) {
    kk_box_t _box_x5 = _match_x1508._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10379 = kk_std_core_types__tuple2_unbox(_box_x5, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10379, _ctx)) {
      kk_box_t _box_x6 = _uniq_pat_0_10379.fst;
      kk_box_t _box_x7 = _uniq_pat_0_10379.snd;
      kk_char_t _uniq_c_10380 = kk_char_unbox(_box_x6, KK_BORROWED, _ctx);
      if (_uniq_c_10380 != quote) {
        kk_std_core_sslice__sslice _uniq_rest_10381 = kk_std_core_sslice__sslice_unbox(_box_x7, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10375, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10381, _ctx);
        kk_std_core_types__maybe_drop(_match_x1508, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x1837 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10380, _ctx), _uniq_acc_10377, _ctx); /*list<10021>*/
          _uniq_slice_10375 = _uniq_rest_10381;
          _uniq_acc_10377 = _x_x1837;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1508, _ctx);
    kk_std_core_types__list _b_x10_14;
    if (kk_std_core_types__is_Nil(_uniq_acc_10377, _ctx)) {
      _b_x10_14 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x10_14 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10377, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x10_14, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10375, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_format__mlift_lift_pquoted_10524_10625(kk_string_t _uniq_msg_10356, kk_std_core_types__maybe _y_x10554, kk_context_t* _ctx) { /* (string, maybe<list<char>>) -> std/text/parse/parse list<char> */ 
  if (kk_std_core_types__is_Nothing(_y_x10554, _ctx)) {
    kk_std_core_hnd__ev ev_10647 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x1838;
    {
      struct kk_std_core_hnd_Ev* _con_x1839 = kk_std_core_hnd__as_Ev(ev_10647, _ctx);
      kk_box_t _box_x16 = _con_x1839->hnd;
      int32_t m = _con_x1839->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x16, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1506;
      kk_std_core_hnd__clause1 _brw_x1507 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1506 = _brw_x1507; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x20 = _match_x1506.clause;
        _x_x1838 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x20, (_fun_unbox_x20, m, ev_10647, kk_string_box(_uniq_msg_10356), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x1838, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x24 = _y_x10554._cons.Just.value;
    kk_std_core_types__list _uniq_x_10373 = kk_std_core_types__list_unbox(_box_x24, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_x_10373, _ctx);
    kk_std_core_types__maybe_drop(_y_x10554, _ctx);
    kk_string_drop(_uniq_msg_10356, _ctx);
    return _uniq_x_10373;
  }
}
 
// lifted local: s, pquoted, @spec-x10374
// specialized: std/text/parse/chars-are, on parameters @uniq-pred@10357, using:
// @uniq-pred@10357 = fn(c: char){
//   std/core/char/(!=)(c, quote);
// }


// lift anonymous function
struct kk_std_time_format__lift_pquoted_10524_fun1842__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format__lift_pquoted_10524_fun1842(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_lift_pquoted_10524_fun1842(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_pquoted_10524_fun1842__t* _self = kk_function_alloc_as(struct kk_std_time_format__lift_pquoted_10524_fun1842__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__lift_pquoted_10524_fun1842, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__lift_pquoted_10524_fun1842(kk_function_t _fself, kk_box_t _b_x38, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_pquoted_10524_fun1842__t* _self = kk_function_as(struct kk_std_time_format__lift_pquoted_10524_fun1842__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x1843;
  kk_std_core_types__tuple2 _match_x1504;
  kk_std_core_sslice__sslice _x_x1844 = kk_std_core_sslice__sslice_unbox(_b_x38, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1504 = kk_std_time_format__lift_pquoted_10525(quote, _x_x1844, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x39 = _match_x1504.fst;
    kk_box_t _box_x40 = _match_x1504.snd;
    kk_std_core_types__list _uniq_pat_0_0_10360 = kk_std_core_types__list_unbox(_box_x39, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10361 = kk_std_core_sslice__sslice_unbox(_box_x40, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10360, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1504, _ctx);
      _x_x1843 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x1845;
    }
  }
  {
    kk_box_t _box_x41 = _match_x1504.fst;
    kk_box_t _box_x42 = _match_x1504.snd;
    kk_std_core_sslice__sslice _uniq_rest_10367 = kk_std_core_sslice__sslice_unbox(_box_x42, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10366 = kk_std_core_types__list_unbox(_box_x41, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10367, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10366, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1504, _ctx);
    kk_box_t _x_x1846;
    kk_std_core_types__tuple2 _x_x1847 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10366, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10367, _ctx), _ctx); /*(10037, 10038)*/
    _x_x1846 = kk_std_core_types__tuple2_box(_x_x1847, _ctx); /*10024*/
    _x_x1843 = kk_std_core_types__new_Just(_x_x1846, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x1845: ;
  return kk_std_core_types__maybe_box(_x_x1843, _ctx);
}


// lift anonymous function
struct kk_std_time_format__lift_pquoted_10524_fun1849__t {
  struct kk_function_s _base;
  kk_string_t _uniq_msg_10356_0;
};
static kk_box_t kk_std_time_format__lift_pquoted_10524_fun1849(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_lift_pquoted_10524_fun1849(kk_string_t _uniq_msg_10356_0, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_pquoted_10524_fun1849__t* _self = kk_function_alloc_as(struct kk_std_time_format__lift_pquoted_10524_fun1849__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__lift_pquoted_10524_fun1849, kk_context());
  _self->_uniq_msg_10356_0 = _uniq_msg_10356_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__lift_pquoted_10524_fun1849(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_pquoted_10524_fun1849__t* _self = kk_function_as(struct kk_std_time_format__lift_pquoted_10524_fun1849__t*, _fself, _ctx);
  kk_string_t _uniq_msg_10356_0 = _self->_uniq_msg_10356_0; /* string */
  kk_drop_match(_self, {kk_string_dup(_uniq_msg_10356_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10554_0_62 = kk_std_core_types__maybe_unbox(_b_x51, KK_OWNED, _ctx); /*maybe<list<char>>*/;
  kk_std_core_types__list _x_x1850 = kk_std_time_format__mlift_lift_pquoted_10524_10625(_uniq_msg_10356_0, _y_x10554_0_62, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x1850, _ctx);
}

kk_std_core_types__list kk_std_time_format__lift_pquoted_10524(kk_char_t quote, kk_string_t _uniq_msg_10356_0, kk_context_t* _ctx) { /* (quote : char, string) -> std/text/parse/parse list<char> */ 
  kk_std_core_hnd__ev ev_0_10653 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_0_10650;
  kk_box_t _x_x1840;
  {
    struct kk_std_core_hnd_Ev* _con_x1841 = kk_std_core_hnd__as_Ev(ev_0_10653, _ctx);
    kk_box_t _box_x25 = _con_x1841->hnd;
    int32_t m_0 = _con_x1841->marker;
    kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x25, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h_0, _ctx);
    kk_std_core_hnd__clause1 _match_x1503;
    kk_std_core_hnd__clause1 _brw_x1505 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
    kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
    _match_x1503 = _brw_x1505; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
    {
      kk_function_t _fun_unbox_x32 = _match_x1503.clause;
      _x_x1840 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x32, (_fun_unbox_x32, m_0, ev_0_10653, kk_function_box(kk_std_time_format__new_lift_pquoted_10524_fun1842(quote, _ctx), _ctx), _ctx), _ctx); /*10010*/
    }
  }
  x_0_10650 = kk_std_core_types__maybe_unbox(_x_x1840, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_0_10650, _ctx);
    kk_box_t _x_x1848 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_lift_pquoted_10524_fun1849(_uniq_msg_10356_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x1848, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_0_10650, _ctx)) {
    kk_std_core_hnd__ev ev_1_10656 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x1851;
    {
      struct kk_std_core_hnd_Ev* _con_x1852 = kk_std_core_hnd__as_Ev(ev_1_10656, _ctx);
      kk_box_t _box_x52 = _con_x1852->hnd;
      int32_t m_1 = _con_x1852->marker;
      kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x52, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_1, _ctx);
      kk_std_core_hnd__clause1 _match_x1501;
      kk_std_core_hnd__clause1 _brw_x1502 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
      _match_x1501 = _brw_x1502; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x56 = _match_x1501.clause;
        _x_x1851 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x56, (_fun_unbox_x56, m_1, ev_1_10656, kk_string_box(_uniq_msg_10356_0), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x1851, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x60 = x_0_10650._cons.Just.value;
    kk_std_core_types__list _uniq_x_10373_0 = kk_std_core_types__list_unbox(_box_x60, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_x_10373_0, _ctx);
    kk_std_core_types__maybe_drop(x_0_10650, _ctx);
    kk_string_drop(_uniq_msg_10356_0, _ctx);
    return _uniq_x_10373_0;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10627_fun1856__t {
  struct kk_function_s _base;
  kk_string_t _c_x10560;
  kk_char_t quote;
};
static kk_string_t kk_std_time_format__mlift_pquoted_10627_fun1856(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10627_fun1856(kk_string_t _c_x10560, kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10627_fun1856__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10627_fun1856__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10627_fun1856, kk_context());
  _self->_c_x10560 = _c_x10560;
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_format__mlift_pquoted_10627_fun1856(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10627_fun1856__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10627_fun1856__t*, _fself, _ctx);
  kk_string_t _c_x10560 = _self->_c_x10560; /* string */
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_string_dup(_c_x10560, _ctx);kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_string_t _x_x1857 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  kk_string_t _x_x1858;
  kk_string_t _x_x1859 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  _x_x1858 = kk_std_core_types__lp__plus__plus__rp_(_c_x10560, _x_x1859, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1857, _x_x1858, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10627_fun1861__t {
  struct kk_function_s _base;
  kk_function_t next_10660;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10627_fun1861(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10627_fun1861(kk_function_t next_10660, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10627_fun1861__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10627_fun1861__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10627_fun1861, kk_context());
  _self->next_10660 = next_10660;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10627_fun1861(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10627_fun1861__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10627_fun1861__t*, _fself, _ctx);
  kk_function_t next_10660 = _self->next_10660; /* (char) -> std/text/parse/parse string */
  kk_drop_match(_self, {kk_function_dup(next_10660, _ctx);}, {}, _ctx)
  kk_string_t _x_x1862;
  kk_char_t _x_x1863 = kk_char_unbox(_b_x64, KK_OWNED, _ctx); /*char*/
  _x_x1862 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10660, (next_10660, _x_x1863, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1862);
}

kk_string_t kk_std_time_format__mlift_pquoted_10627(kk_char_t quote, kk_string_t _c_x10560, kk_context_t* _ctx) { /* (quote : char, string) -> string */ 
  kk_char_t x_10659 = kk_std_text_parse_char(quote, _ctx); /*char*/;
  kk_function_t next_10660 = kk_std_time_format__new_mlift_pquoted_10627_fun1856(_c_x10560, quote, _ctx); /*(char) -> std/text/parse/parse string*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1860 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10627_fun1861(next_10660, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x1860);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10660, (next_10660, x_10659, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10628_fun1866__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1866(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10628_fun1866(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10628_fun1866__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10628_fun1866__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10628_fun1866, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1866(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10628_fun1866__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10628_fun1866__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x1867;
  kk_std_core_types__tuple2 _match_x1497;
  kk_std_core_sslice__sslice _x_x1868 = kk_std_core_sslice__sslice_unbox(_b_x79, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1497 = kk_std_time_format__lift_pquoted_10525(quote, _x_x1868, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x80 = _match_x1497.fst;
    kk_box_t _box_x81 = _match_x1497.snd;
    kk_std_core_types__list _uniq_pat_0_0_10360 = kk_std_core_types__list_unbox(_box_x80, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10361 = kk_std_core_sslice__sslice_unbox(_box_x81, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10360, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1497, _ctx);
      _x_x1867 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x1869;
    }
  }
  {
    kk_box_t _box_x82 = _match_x1497.fst;
    kk_box_t _box_x83 = _match_x1497.snd;
    kk_std_core_sslice__sslice _uniq_rest_10367 = kk_std_core_sslice__sslice_unbox(_box_x83, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10366 = kk_std_core_types__list_unbox(_box_x82, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10367, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10366, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1497, _ctx);
    kk_box_t _x_x1870;
    kk_std_core_types__tuple2 _x_x1871 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10366, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10367, _ctx), _ctx); /*(10037, 10038)*/
    _x_x1870 = kk_std_core_types__tuple2_box(_x_x1871, _ctx); /*10024*/
    _x_x1867 = kk_std_core_types__new_Just(_x_x1870, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x1869: ;
  return kk_std_core_types__maybe_box(_x_x1867, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10628_fun1873__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1873(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10628_fun1873(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_pquoted_10628_fun1873, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1873(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x1874;
  kk_string_t _x_x1875 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x_x1877 = kk_std_core_types__maybe_unbox(_b_x92, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x1874 = kk_std_time_format__mlift_lift_pquoted_10524_10625(_x_x1875, _x_x1877, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x1874, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10628_fun1884__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1884(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10628_fun1884(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_pquoted_10628_fun1884, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1884(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1885;
  kk_std_core_types__list _x_x1886 = kk_std_core_types__list_unbox(_b_x105, KK_OWNED, _ctx); /*list<char>*/
  _x_x1885 = kk_std_core_string_listchar_fs_string(_x_x1886, _ctx); /*string*/
  return kk_string_box(_x_x1885);
}


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10628_fun1889__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1889(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10628_fun1889(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10628_fun1889__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10628_fun1889__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10628_fun1889, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10628_fun1889(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10628_fun1889__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10628_fun1889__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_string_t _c_x10560_110 = kk_string_unbox(_b_x108); /*string*/;
  kk_string_t _x_x1890 = kk_std_time_format__mlift_pquoted_10627(quote, _c_x10560_110, _ctx); /*string*/
  return kk_string_box(_x_x1890);
}

kk_string_t kk_std_time_format__mlift_pquoted_10628(kk_char_t quote, bool _y_x10558, kk_context_t* _ctx) { /* (quote : char, bool) -> std/text/parse/parse string */ 
  kk_string_t x_10664;
  if (_y_x10558) {
    kk_std_core_hnd__ev ev_0_10653 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_10650;
    kk_box_t _x_x1864;
    {
      struct kk_std_core_hnd_Ev* _con_x1865 = kk_std_core_hnd__as_Ev(ev_0_10653, _ctx);
      kk_box_t _box_x66 = _con_x1865->hnd;
      int32_t m_0 = _con_x1865->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x66, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      kk_std_core_hnd__clause1 _match_x1496;
      kk_std_core_hnd__clause1 _brw_x1498 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
      _match_x1496 = _brw_x1498; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x73 = _match_x1496.clause;
        _x_x1864 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x73, (_fun_unbox_x73, m_0, ev_0_10653, kk_function_box(kk_std_time_format__new_mlift_pquoted_10628_fun1866(quote, _ctx), _ctx), _ctx), _ctx); /*10010*/
      }
    }
    x_0_10650 = kk_std_core_types__maybe_unbox(_x_x1864, KK_OWNED, _ctx); /*maybe<list<char>>*/
    kk_std_core_types__list x_0_10666;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10650, _ctx);
      kk_box_t _x_x1872 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10628_fun1873(_ctx), _ctx); /*10001*/
      x_0_10666 = kk_std_core_types__list_unbox(_x_x1872, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      if (kk_std_core_types__is_Nothing(x_0_10650, _ctx)) {
        kk_std_core_hnd__ev ev_1_10656 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_box_t _x_x1878;
        {
          struct kk_std_core_hnd_Ev* _con_x1879 = kk_std_core_hnd__as_Ev(ev_1_10656, _ctx);
          kk_box_t _box_x93 = _con_x1879->hnd;
          int32_t m_1 = _con_x1879->marker;
          kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x93, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_1, _ctx);
          kk_std_core_hnd__clause1 _match_x1494;
          kk_std_core_hnd__clause1 _brw_x1495 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
          kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
          _match_x1494 = _brw_x1495; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
          {
            kk_function_t _fun_unbox_x97 = _match_x1494.clause;
            kk_box_t _x_x1880;
            kk_string_t _x_x1881 = kk_string_empty(); /*string*/
            _x_x1880 = kk_string_box(_x_x1881); /*10009*/
            _x_x1878 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x97, (_fun_unbox_x97, m_1, ev_1_10656, _x_x1880, _ctx), _ctx); /*10010*/
          }
        }
        x_0_10666 = kk_std_core_types__list_unbox(_x_x1878, KK_OWNED, _ctx); /*list<char>*/
      }
      else {
        kk_box_t _box_x101 = x_0_10650._cons.Just.value;
        kk_std_core_types__list _uniq_x_10373_0 = kk_std_core_types__list_unbox(_box_x101, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(_uniq_x_10373_0, _ctx);
        kk_std_core_types__maybe_drop(x_0_10650, _ctx);
        x_0_10666 = _uniq_x_10373_0; /*list<char>*/
      }
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_10666, _ctx);
      kk_box_t _x_x1883 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10628_fun1884(_ctx), _ctx); /*10001*/
      x_10664 = kk_string_unbox(_x_x1883); /*string*/
    }
    else {
      x_10664 = kk_std_core_string_listchar_fs_string(x_0_10666, _ctx); /*string*/
    }
  }
  else {
    x_10664 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10664, _ctx);
    kk_box_t _x_x1888 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10628_fun1889(quote, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x1888);
  }
  {
    return kk_std_time_format__mlift_pquoted_10627(quote, x_10664, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_pquoted_10629_fun1894__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format__mlift_pquoted_10629_fun1894(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_pquoted_10629_fun1894(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10629_fun1894__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_pquoted_10629_fun1894__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_pquoted_10629_fun1894, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_pquoted_10629_fun1894(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_pquoted_10629_fun1894__t* _self = kk_function_as(struct kk_std_time_format__mlift_pquoted_10629_fun1894__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  bool _y_x10558_120 = kk_bool_unbox(_b_x118); /*bool*/;
  kk_string_t _x_x1895 = kk_std_time_format__mlift_pquoted_10628(quote, _y_x10558_120, _ctx); /*string*/
  return kk_string_box(_x_x1895);
}

kk_string_t kk_std_time_format__mlift_pquoted_10629(kk_char_t quote, kk_char_t wild__, kk_context_t* _ctx) { /* (quote : char, wild_ : char) -> std/text/parse/parse string */ 
  kk_std_core_hnd__ev ev_10670 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10668;
  kk_box_t _x_x1891;
  {
    struct kk_std_core_hnd_Ev* _con_x1892 = kk_std_core_hnd__as_Ev(ev_10670, _ctx);
    kk_box_t _box_x111 = _con_x1892->hnd;
    int32_t m = _con_x1892->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x111, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1489;
    kk_std_core_hnd__clause0 _brw_x1490 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1489 = _brw_x1490; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x114 = _match_x1489.clause;
      _x_x1891 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x114, (_fun_unbox_x114, m, ev_10670, _ctx), _ctx); /*10005*/
    }
  }
  x_10668 = kk_bool_unbox(_x_x1891); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1893 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_pquoted_10629_fun1894(quote, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x1893);
  }
  {
    return kk_std_time_format__mlift_pquoted_10628(quote, x_10668, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1897__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1897(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1897(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1897__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1897__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1897, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1897(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1897__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1897__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_char_t wild___180 = kk_char_unbox(_b_x122, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1898 = kk_std_time_format__mlift_pquoted_10629(quote, wild___180, _ctx); /*string*/
  return kk_string_box(_x_x1898);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1902__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1902(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1902(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1902__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1902__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1902, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1902(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1902__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1902__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  bool _y_x10558_181 = kk_bool_unbox(_b_x130); /*bool*/;
  kk_string_t _x_x1903 = kk_std_time_format__mlift_pquoted_10628(quote, _y_x10558_181, _ctx); /*string*/
  return kk_string_box(_x_x1903);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1906__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1906(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1906(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1906__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1906__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1906, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1906(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1906__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1906__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x1907;
  kk_std_core_types__tuple2 _match_x1484;
  kk_std_core_sslice__sslice _x_x1908 = kk_std_core_sslice__sslice_unbox(_b_x144, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1484 = kk_std_time_format__lift_pquoted_10525(quote, _x_x1908, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x145 = _match_x1484.fst;
    kk_box_t _box_x146 = _match_x1484.snd;
    kk_std_core_types__list _uniq_pat_0_0_10360 = kk_std_core_types__list_unbox(_box_x145, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10361 = kk_std_core_sslice__sslice_unbox(_box_x146, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10360, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1484, _ctx);
      _x_x1907 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x1909;
    }
  }
  {
    kk_box_t _box_x147 = _match_x1484.fst;
    kk_box_t _box_x148 = _match_x1484.snd;
    kk_std_core_sslice__sslice _uniq_rest_10367 = kk_std_core_sslice__sslice_unbox(_box_x148, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10366 = kk_std_core_types__list_unbox(_box_x147, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10367, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10366, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1484, _ctx);
    kk_box_t _x_x1910;
    kk_std_core_types__tuple2 _x_x1911 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10366, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10367, _ctx), _ctx); /*(10037, 10038)*/
    _x_x1910 = kk_std_core_types__tuple2_box(_x_x1911, _ctx); /*10024*/
    _x_x1907 = kk_std_core_types__new_Just(_x_x1910, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x1909: ;
  return kk_std_core_types__maybe_box(_x_x1907, _ctx);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1913__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_pquoted_fun1913(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1913(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_pquoted_fun1913, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1913(kk_function_t _fself, kk_box_t _b_x157, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x1914;
  kk_string_t _x_x1915 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x_x1917 = kk_std_core_types__maybe_unbox(_b_x157, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x1914 = kk_std_time_format__mlift_lift_pquoted_10524_10625(_x_x1915, _x_x1917, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x1914, _ctx);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1924__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_pquoted_fun1924(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1924(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_pquoted_fun1924, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1924(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1925;
  kk_std_core_types__list _x_x1926 = kk_std_core_types__list_unbox(_b_x170, KK_OWNED, _ctx); /*list<char>*/
  _x_x1925 = kk_std_core_string_listchar_fs_string(_x_x1926, _ctx); /*string*/
  return kk_string_box(_x_x1925);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1929__t {
  struct kk_function_s _base;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1929(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1929(kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1929__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1929__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1929, kk_context());
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1929(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1929__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1929__t*, _fself, _ctx);
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_string_t _c_x10560_182 = kk_string_unbox(_b_x173); /*string*/;
  kk_string_t _x_x1930 = kk_std_time_format__mlift_pquoted_10627(quote, _c_x10560_182, _ctx); /*string*/
  return kk_string_box(_x_x1930);
}


// lift anonymous function
struct kk_std_time_format_pquoted_fun1932__t {
  struct kk_function_s _base;
  kk_string_t x_1_10680;
  kk_char_t quote;
};
static kk_box_t kk_std_time_format_pquoted_fun1932(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_pquoted_fun1932(kk_string_t x_1_10680, kk_char_t quote, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1932__t* _self = kk_function_alloc_as(struct kk_std_time_format_pquoted_fun1932__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_pquoted_fun1932, kk_context());
  _self->x_1_10680 = x_1_10680;
  _self->quote = quote;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_pquoted_fun1932(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx) {
  struct kk_std_time_format_pquoted_fun1932__t* _self = kk_function_as(struct kk_std_time_format_pquoted_fun1932__t*, _fself, _ctx);
  kk_string_t x_1_10680 = _self->x_1_10680; /* string */
  kk_char_t quote = _self->quote; /* char */
  kk_drop_match(_self, {kk_string_dup(x_1_10680, _ctx);kk_skip_dup(quote, _ctx);}, {}, _ctx)
  kk_char_t wild___0_183 = kk_char_unbox(_b_x175, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1933;
  kk_string_t _x_x1934 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  kk_string_t _x_x1935;
  kk_string_t _x_x1936 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
  _x_x1935 = kk_std_core_types__lp__plus__plus__rp_(x_1_10680, _x_x1936, _ctx); /*string*/
  _x_x1933 = kk_std_core_types__lp__plus__plus__rp_(_x_x1934, _x_x1935, _ctx); /*string*/
  return kk_string_box(_x_x1933);
}

kk_string_t kk_std_time_format_pquoted(kk_char_t quote, kk_context_t* _ctx) { /* (quote : char) -> std/text/parse/parse string */ 
  kk_char_t x_10672 = kk_std_text_parse_char(quote, _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1896 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1897(quote, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x1896);
  }
  {
    kk_std_core_hnd__ev ev_10678 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    bool x_0_10675;
    kk_box_t _x_x1899;
    {
      struct kk_std_core_hnd_Ev* _con_x1900 = kk_std_core_hnd__as_Ev(ev_10678, _ctx);
      kk_box_t _box_x123 = _con_x1900->hnd;
      int32_t m = _con_x1900->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x123, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x1486;
      kk_std_core_hnd__clause0 _brw_x1487 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1486 = _brw_x1487; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
      {
        kk_function_t _fun_unbox_x126 = _match_x1486.clause;
        _x_x1899 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x126, (_fun_unbox_x126, m, ev_10678, _ctx), _ctx); /*10005*/
      }
    }
    x_0_10675 = kk_bool_unbox(_x_x1899); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1901 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1902(quote, _ctx), _ctx); /*10001*/
      return kk_string_unbox(_x_x1901);
    }
    {
      kk_string_t x_1_10680;
      if (x_0_10675) {
        kk_std_core_hnd__ev ev_0_10653 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_std_core_types__maybe x_0_10650;
        kk_box_t _x_x1904;
        {
          struct kk_std_core_hnd_Ev* _con_x1905 = kk_std_core_hnd__as_Ev(ev_0_10653, _ctx);
          kk_box_t _box_x131 = _con_x1905->hnd;
          int32_t m_0 = _con_x1905->marker;
          kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x131, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_0, _ctx);
          kk_std_core_hnd__clause1 _match_x1483;
          kk_std_core_hnd__clause1 _brw_x1485 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
          kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
          _match_x1483 = _brw_x1485; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
          {
            kk_function_t _fun_unbox_x138 = _match_x1483.clause;
            _x_x1904 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x138, (_fun_unbox_x138, m_0, ev_0_10653, kk_function_box(kk_std_time_format_new_pquoted_fun1906(quote, _ctx), _ctx), _ctx), _ctx); /*10010*/
          }
        }
        x_0_10650 = kk_std_core_types__maybe_unbox(_x_x1904, KK_OWNED, _ctx); /*maybe<list<char>>*/
        kk_std_core_types__list x_2_10683;
        if (kk_yielding(kk_context())) {
          kk_std_core_types__maybe_drop(x_0_10650, _ctx);
          kk_box_t _x_x1912 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1913(_ctx), _ctx); /*10001*/
          x_2_10683 = kk_std_core_types__list_unbox(_x_x1912, KK_OWNED, _ctx); /*list<char>*/
        }
        else {
          if (kk_std_core_types__is_Nothing(x_0_10650, _ctx)) {
            kk_std_core_hnd__ev ev_1_10656 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
            kk_box_t _x_x1918;
            {
              struct kk_std_core_hnd_Ev* _con_x1919 = kk_std_core_hnd__as_Ev(ev_1_10656, _ctx);
              kk_box_t _box_x158 = _con_x1919->hnd;
              int32_t m_1 = _con_x1919->marker;
              kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x158, KK_BORROWED, _ctx);
              kk_std_text_parse__parse_dup(h_1, _ctx);
              kk_std_core_hnd__clause1 _match_x1481;
              kk_std_core_hnd__clause1 _brw_x1482 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
              kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
              _match_x1481 = _brw_x1482; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
              {
                kk_function_t _fun_unbox_x162 = _match_x1481.clause;
                kk_box_t _x_x1920;
                kk_string_t _x_x1921 = kk_string_empty(); /*string*/
                _x_x1920 = kk_string_box(_x_x1921); /*10009*/
                _x_x1918 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x162, (_fun_unbox_x162, m_1, ev_1_10656, _x_x1920, _ctx), _ctx); /*10010*/
              }
            }
            x_2_10683 = kk_std_core_types__list_unbox(_x_x1918, KK_OWNED, _ctx); /*list<char>*/
          }
          else {
            kk_box_t _box_x166 = x_0_10650._cons.Just.value;
            kk_std_core_types__list _uniq_x_10373_0 = kk_std_core_types__list_unbox(_box_x166, KK_BORROWED, _ctx);
            kk_std_core_types__list_dup(_uniq_x_10373_0, _ctx);
            kk_std_core_types__maybe_drop(x_0_10650, _ctx);
            x_2_10683 = _uniq_x_10373_0; /*list<char>*/
          }
        }
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_2_10683, _ctx);
          kk_box_t _x_x1923 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1924(_ctx), _ctx); /*10001*/
          x_1_10680 = kk_string_unbox(_x_x1923); /*string*/
        }
        else {
          x_1_10680 = kk_std_core_string_listchar_fs_string(x_2_10683, _ctx); /*string*/
        }
      }
      else {
        x_1_10680 = kk_string_empty(); /*string*/
      }
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10680, _ctx);
        kk_box_t _x_x1928 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1929(quote, _ctx), _ctx); /*10001*/
        return kk_string_unbox(_x_x1928);
      }
      {
        kk_char_t x_3_10685 = kk_std_text_parse_char(quote, _ctx); /*char*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1931 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_pquoted_fun1932(x_1_10680, quote, _ctx), _ctx); /*10001*/
          return kk_string_unbox(_x_x1931);
        }
        {
          kk_string_t _x_x1937 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
          kk_string_t _x_x1938;
          kk_string_t _x_x1939 = kk_std_core_string_char_fs_string(quote, _ctx); /*string*/
          _x_x1938 = kk_std_core_types__lp__plus__plus__rp_(x_1_10680, _x_x1939, _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x1937, _x_x1938, _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_string_t kk_std_time_format__mlift_plocale_t_10630(kk_std_time_locale__time_locale locale, kk_char_t wild___0, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale, wild_@0 : char) -> std/text/parse/parse string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  {
    struct kk_std_time_locale_Time_locale* _con_x1940 = kk_std_time_locale__as_Time_locale(locale, _ctx);
    kk_string_t _pat_0_1 = _con_x1940->lang_name;
    kk_std_core_types__list _pat_1_1 = _con_x1940->day_names;
    kk_std_core_types__list _pat_2_0 = _con_x1940->month_names;
    kk_std_core_types__list _pat_3_0 = _con_x1940->month_names_short;
    kk_std_core_types__list _pat_4_0 = _con_x1940->day_names_short;
    kk_std_core_types__list _pat_5_0 = _con_x1940->day_names_min;
    kk_string_t _pat_6_0 = _con_x1940->format_t;
    kk_string_t _x_0 = _con_x1940->format_tt;
    kk_string_t _pat_7_0 = _con_x1940->format_l;
    kk_string_t _pat_8_0 = _con_x1940->format_ll;
    kk_string_t _pat_9_0 = _con_x1940->format_lll;
    kk_string_t _pat_10_0 = _con_x1940->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
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
      kk_string_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(locale, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(locale, _ctx);
    }
    return _x_0;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10631_fun1942__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10631_fun1942(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10631_fun1942(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10631_fun1942__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_t_10631_fun1942__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_t_10631_fun1942, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10631_fun1942(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10631_fun1942__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_t_10631_fun1942__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_char_t wild___0_187 = kk_char_unbox(_b_x185, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1943 = kk_std_time_format__mlift_plocale_t_10630(locale, wild___0_187, _ctx); /*string*/
  return kk_string_box(_x_x1943);
}

kk_string_t kk_std_time_format__mlift_plocale_t_10631(kk_string_t default_10023, kk_std_time_locale__time_locale locale, bool _y_x10563, kk_context_t* _ctx) { /* (default@10023 : string, locale : std/time/locale/time-locale, bool) -> std/text/parse/parse string */ 
  if (_y_x10563) {
    kk_string_drop(default_10023, _ctx);
    kk_char_t x_10693 = kk_std_text_parse_char('t', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1941 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_t_10631_fun1942(locale, _ctx), _ctx); /*10001*/
      return kk_string_unbox(_x_x1941);
    }
    {
      return kk_std_time_format__mlift_plocale_t_10630(locale, x_10693, _ctx);
    }
  }
  {
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return default_10023;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_t_10632_fun1947__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format__mlift_plocale_t_10632_fun1947(kk_function_t _fself, kk_box_t _b_x195, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_t_10632_fun1947(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10632_fun1947__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_t_10632_fun1947__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_t_10632_fun1947, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_t_10632_fun1947(kk_function_t _fself, kk_box_t _b_x195, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_t_10632_fun1947__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_t_10632_fun1947__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x1948;
  bool _y_x10563_197 = kk_bool_unbox(_b_x195); /*bool*/;
  kk_string_t _x_x1949;
  {
    struct kk_std_time_locale_Time_locale* _con_x1950 = kk_std_time_locale__as_Time_locale(locale, _ctx);
    kk_string_t _x = _con_x1950->format_t;
    kk_string_dup(_x, _ctx);
    _x_x1949 = _x; /*string*/
  }
  _x_x1948 = kk_std_time_format__mlift_plocale_t_10631(_x_x1949, locale, _y_x10563_197, _ctx); /*string*/
  return kk_string_box(_x_x1948);
}

kk_string_t kk_std_time_format__mlift_plocale_t_10632(kk_std_time_locale__time_locale locale, kk_char_t wild__, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale, wild_ : char) -> std/text/parse/parse string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_std_core_hnd__ev ev_10699 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_0_10697;
  kk_box_t _x_x1944;
  {
    struct kk_std_core_hnd_Ev* _con_x1945 = kk_std_core_hnd__as_Ev(ev_10699, _ctx);
    kk_box_t _box_x188 = _con_x1945->hnd;
    int32_t m = _con_x1945->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x188, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1472;
    kk_std_core_hnd__clause0 _brw_x1473 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1472 = _brw_x1473; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x191 = _match_x1472.clause;
      _x_x1944 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x191, (_fun_unbox_x191, m, ev_10699, _ctx), _ctx); /*10005*/
    }
  }
  x_0_10697 = kk_bool_unbox(_x_x1944); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1946 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_t_10632_fun1947(locale, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x1946);
  }
  {
    bool _y_x10563_198 = x_0_10697; /*bool*/;
    kk_string_t _x_x1951;
    {
      struct kk_std_time_locale_Time_locale* _con_x1952 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _x = _con_x1952->format_t;
      kk_string_dup(_x, _ctx);
      _x_x1951 = _x; /*string*/
    }
    return kk_std_time_format__mlift_plocale_t_10631(_x_x1951, locale, _y_x10563_198, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1954__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_t_fun1954(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1954(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1954__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1954__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1954, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1954(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1954__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1954__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_char_t wild___214 = kk_char_unbox(_b_x200, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1955 = kk_std_time_format__mlift_plocale_t_10632(locale, wild___214, _ctx); /*string*/
  return kk_string_box(_x_x1955);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1959__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_t_fun1959(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1959(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1959__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1959__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1959, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1959(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1959__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1959__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  bool _y_x10563_215 = kk_bool_unbox(_b_x208); /*bool*/;
  kk_string_t _x_x1960;
  kk_string_t _x_x1961;
  {
    struct kk_std_time_locale_Time_locale* _con_x1962 = kk_std_time_locale__as_Time_locale(locale, _ctx);
    kk_string_t _x = _con_x1962->format_t;
    kk_string_dup(_x, _ctx);
    _x_x1961 = _x; /*string*/
  }
  _x_x1960 = kk_std_time_format__mlift_plocale_t_10631(_x_x1961, locale, _y_x10563_215, _ctx); /*string*/
  return kk_string_box(_x_x1960);
}


// lift anonymous function
struct kk_std_time_format_plocale_t_fun1964__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_t_fun1964(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_t_fun1964(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1964__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_t_fun1964__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_t_fun1964, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_t_fun1964(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_t_fun1964__t* _self = kk_function_as(struct kk_std_time_format_plocale_t_fun1964__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_char_t wild___0_216 = kk_char_unbox(_b_x210, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x1965 = kk_std_time_format__mlift_plocale_t_10630(locale, wild___0_216, _ctx); /*string*/
  return kk_string_box(_x_x1965);
}

kk_string_t kk_std_time_format_plocale_t(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
  kk_char_t x_10701 = kk_std_text_parse_char('t', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1953 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_t_fun1954(locale, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x1953);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_std_core_hnd__ev ev_10709 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    bool x_1_10706;
    kk_box_t _x_x1956;
    {
      struct kk_std_core_hnd_Ev* _con_x1957 = kk_std_core_hnd__as_Ev(ev_10709, _ctx);
      kk_box_t _box_x201 = _con_x1957->hnd;
      int32_t m = _con_x1957->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x201, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x1469;
      kk_std_core_hnd__clause0 _brw_x1470 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1469 = _brw_x1470; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
      {
        kk_function_t _fun_unbox_x204 = _match_x1469.clause;
        _x_x1956 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x204, (_fun_unbox_x204, m, ev_10709, _ctx), _ctx); /*10005*/
      }
    }
    x_1_10706 = kk_bool_unbox(_x_x1956); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1958 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_t_fun1959(locale, _ctx), _ctx); /*10001*/
      return kk_string_unbox(_x_x1958);
    }
    if (x_1_10706) {
      kk_char_t x_2_10711 = kk_std_text_parse_char('t', _ctx); /*char*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1963 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_t_fun1964(locale, _ctx), _ctx); /*10001*/
        return kk_string_unbox(_x_x1963);
      }
      {
        kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
        kk_unit_t keep_0 = kk_Unit;
        kk_evv_set(w_0,kk_context());
        {
          struct kk_std_time_locale_Time_locale* _con_x1966 = kk_std_time_locale__as_Time_locale(locale, _ctx);
          kk_string_t _pat_0_1_0 = _con_x1966->lang_name;
          kk_std_core_types__list _pat_1_1_0 = _con_x1966->day_names;
          kk_std_core_types__list _pat_2_0_0 = _con_x1966->month_names;
          kk_std_core_types__list _pat_3_0 = _con_x1966->month_names_short;
          kk_std_core_types__list _pat_4_0 = _con_x1966->day_names_short;
          kk_std_core_types__list _pat_5_0 = _con_x1966->day_names_min;
          kk_string_t _pat_6_0 = _con_x1966->format_t;
          kk_string_t _x_0 = _con_x1966->format_tt;
          kk_string_t _pat_7_0 = _con_x1966->format_l;
          kk_string_t _pat_8_0 = _con_x1966->format_ll;
          kk_string_t _pat_9_0 = _con_x1966->format_lll;
          kk_string_t _pat_10_0 = _con_x1966->format_llll;
          if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
            kk_string_drop(_pat_9_0, _ctx);
            kk_string_drop(_pat_8_0, _ctx);
            kk_string_drop(_pat_7_0, _ctx);
            kk_string_drop(_pat_6_0, _ctx);
            kk_std_core_types__list_drop(_pat_5_0, _ctx);
            kk_std_core_types__list_drop(_pat_4_0, _ctx);
            kk_std_core_types__list_drop(_pat_3_0, _ctx);
            kk_std_core_types__list_drop(_pat_2_0_0, _ctx);
            kk_std_core_types__list_drop(_pat_1_1_0, _ctx);
            kk_string_drop(_pat_10_0, _ctx);
            kk_string_drop(_pat_0_1_0, _ctx);
            kk_datatype_ptr_free(locale, _ctx);
          }
          else {
            kk_string_dup(_x_0, _ctx);
            kk_datatype_ptr_decref(locale, _ctx);
          }
          return _x_0;
        }
      }
    }
    {
      struct kk_std_time_locale_Time_locale* _con_x1967 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _pat_0_0_0 = _con_x1967->lang_name;
      kk_std_core_types__list _pat_1_0_0 = _con_x1967->day_names;
      kk_std_core_types__list _pat_2_1 = _con_x1967->month_names;
      kk_std_core_types__list _pat_3_1 = _con_x1967->month_names_short;
      kk_std_core_types__list _pat_4_1 = _con_x1967->day_names_short;
      kk_std_core_types__list _pat_5_1 = _con_x1967->day_names_min;
      kk_string_t _x_1 = _con_x1967->format_t;
      kk_string_t _pat_6_1 = _con_x1967->format_tt;
      kk_string_t _pat_7_1 = _con_x1967->format_l;
      kk_string_t _pat_8_1 = _con_x1967->format_ll;
      kk_string_t _pat_9_1 = _con_x1967->format_lll;
      kk_string_t _pat_10_1 = _con_x1967->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
        kk_string_drop(_pat_9_1, _ctx);
        kk_string_drop(_pat_8_1, _ctx);
        kk_string_drop(_pat_7_1, _ctx);
        kk_string_drop(_pat_6_1, _ctx);
        kk_std_core_types__list_drop(_pat_5_1, _ctx);
        kk_std_core_types__list_drop(_pat_4_1, _ctx);
        kk_std_core_types__list_drop(_pat_3_1, _ctx);
        kk_std_core_types__list_drop(_pat_2_1, _ctx);
        kk_std_core_types__list_drop(_pat_1_0_0, _ctx);
        kk_string_drop(_pat_10_1, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(locale, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(locale, _ctx);
      }
      return _x_1;
    }
  }
}
 
// monadic lift

kk_string_t kk_std_time_format__mlift_plocale_l_10633(kk_char_t l, kk_string_t _c_x10571, kk_context_t* _ctx) { /* (l : char, string) -> string */ 
  bool _match_x1465 = (l == ('L')); /*bool*/;
  if (_match_x1465) {
    return _c_x10571;
  }
  {
    kk_string_t _x_x1968;
    kk_string_t _x_x1969;
    kk_string_t _x_x1970;
    kk_string_t _x_x1971;
    kk_string_t _x_x1972;
    kk_string_t _x_x1973;
    kk_define_string_literal(, _s_x1974, 2, "dd", _ctx)
    _x_x1973 = kk_string_dup(_s_x1974, _ctx); /*string*/
    kk_string_t _x_x1975;
    kk_define_string_literal(, _s_x1976, 1, "d", _ctx)
    _x_x1975 = kk_string_dup(_s_x1976, _ctx); /*string*/
    _x_x1972 = kk_string_replace_all(_c_x10571,_x_x1973,_x_x1975,kk_context()); /*string*/
    kk_string_t _x_x1977;
    kk_define_string_literal(, _s_x1978, 2, "dd", _ctx)
    _x_x1977 = kk_string_dup(_s_x1978, _ctx); /*string*/
    kk_string_t _x_x1979;
    kk_define_string_literal(, _s_x1980, 3, "ddd", _ctx)
    _x_x1979 = kk_string_dup(_s_x1980, _ctx); /*string*/
    _x_x1971 = kk_string_replace_all(_x_x1972,_x_x1977,_x_x1979,kk_context()); /*string*/
    kk_string_t _x_x1981;
    kk_define_string_literal(, _s_x1982, 2, "MM", _ctx)
    _x_x1981 = kk_string_dup(_s_x1982, _ctx); /*string*/
    kk_string_t _x_x1983;
    kk_define_string_literal(, _s_x1984, 1, "M", _ctx)
    _x_x1983 = kk_string_dup(_s_x1984, _ctx); /*string*/
    _x_x1970 = kk_string_replace_all(_x_x1971,_x_x1981,_x_x1983,kk_context()); /*string*/
    kk_string_t _x_x1985;
    kk_define_string_literal(, _s_x1986, 2, "MM", _ctx)
    _x_x1985 = kk_string_dup(_s_x1986, _ctx); /*string*/
    kk_string_t _x_x1987;
    kk_define_string_literal(, _s_x1988, 3, "MMM", _ctx)
    _x_x1987 = kk_string_dup(_s_x1988, _ctx); /*string*/
    _x_x1969 = kk_string_replace_all(_x_x1970,_x_x1985,_x_x1987,kk_context()); /*string*/
    kk_string_t _x_x1989;
    kk_define_string_literal(, _s_x1990, 2, "DD", _ctx)
    _x_x1989 = kk_string_dup(_s_x1990, _ctx); /*string*/
    kk_string_t _x_x1991;
    kk_define_string_literal(, _s_x1992, 1, "D", _ctx)
    _x_x1991 = kk_string_dup(_s_x1992, _ctx); /*string*/
    _x_x1968 = kk_string_replace_all(_x_x1969,_x_x1989,_x_x1991,kk_context()); /*string*/
    kk_string_t _x_x1993;
    kk_define_string_literal(, _s_x1994, 2, "DD", _ctx)
    _x_x1993 = kk_string_dup(_s_x1994, _ctx); /*string*/
    kk_string_t _x_x1995;
    kk_define_string_literal(, _s_x1996, 3, "DDD", _ctx)
    _x_x1995 = kk_string_dup(_s_x1996, _ctx); /*string*/
    return kk_string_replace_all(_x_x1968,_x_x1993,_x_x1995,kk_context());
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10634_fun2002__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10634_fun2002(kk_function_t _fself, kk_box_t _b_x222, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10634_fun2002(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10634_fun2002__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_l_10634_fun2002__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_l_10634_fun2002, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10634_fun2002(kk_function_t _fself, kk_box_t _b_x222, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10634_fun2002__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_l_10634_fun2002__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_string_t _c_x10571_224 = kk_string_unbox(_b_x222); /*string*/;
  kk_string_t _x_x2003 = kk_std_time_format__mlift_plocale_l_10633(l, _c_x10571_224, _ctx); /*string*/
  return kk_string_box(_x_x2003);
}

kk_string_t kk_std_time_format__mlift_plocale_l_10634(kk_char_t _y_x10566, kk_char_t l, kk_std_time_locale__time_locale locale, kk_std_core_types__list _y_x10568, kk_context_t* _ctx) { /* (char, l : char, locale : std/time/locale/time-locale, list<char>) -> std/text/parse/parse string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_core_types__list xs = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_y_x10566, _ctx), _y_x10568, _ctx); /*list<char>*/;
  kk_integer_t x;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    x = kk_std_core_list__unroll_lift_length_5730_10000(xs, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_string_t x_0_10718;
  bool _match_x1461 = kk_integer_gte_borrow(x,(kk_integer_from_small(4)),kk_context()); /*bool*/;
  if (_match_x1461) {
    kk_integer_drop(x, _ctx);
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    {
      struct kk_std_time_locale_Time_locale* _con_x1997 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _pat_0_0_0 = _con_x1997->lang_name;
      kk_std_core_types__list _pat_1_0 = _con_x1997->day_names;
      kk_std_core_types__list _pat_2_0 = _con_x1997->month_names;
      kk_std_core_types__list _pat_3 = _con_x1997->month_names_short;
      kk_std_core_types__list _pat_4 = _con_x1997->day_names_short;
      kk_std_core_types__list _pat_5 = _con_x1997->day_names_min;
      kk_string_t _pat_6 = _con_x1997->format_t;
      kk_string_t _pat_7 = _con_x1997->format_tt;
      kk_string_t _pat_8 = _con_x1997->format_l;
      kk_string_t _pat_9 = _con_x1997->format_ll;
      kk_string_t _pat_10 = _con_x1997->format_lll;
      kk_string_t _x = _con_x1997->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
        kk_string_drop(_pat_9, _ctx);
        kk_string_drop(_pat_8, _ctx);
        kk_string_drop(_pat_7, _ctx);
        kk_string_drop(_pat_6, _ctx);
        kk_std_core_types__list_drop(_pat_5, _ctx);
        kk_std_core_types__list_drop(_pat_4, _ctx);
        kk_std_core_types__list_drop(_pat_3, _ctx);
        kk_std_core_types__list_drop(_pat_2_0, _ctx);
        kk_std_core_types__list_drop(_pat_1_0, _ctx);
        kk_string_drop(_pat_10, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(locale, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(locale, _ctx);
      }
      x_0_10718 = _x; /*string*/
    }
  }
  else {
    bool _match_x1462 = kk_integer_eq_borrow(x,(kk_integer_from_small(3)),kk_context()); /*bool*/;
    if (_match_x1462) {
      kk_integer_drop(x, _ctx);
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      {
        struct kk_std_time_locale_Time_locale* _con_x1998 = kk_std_time_locale__as_Time_locale(locale, _ctx);
        kk_string_t _pat_0_2 = _con_x1998->lang_name;
        kk_std_core_types__list _pat_1_2 = _con_x1998->day_names;
        kk_std_core_types__list _pat_2_1 = _con_x1998->month_names;
        kk_std_core_types__list _pat_3_0 = _con_x1998->month_names_short;
        kk_std_core_types__list _pat_4_0 = _con_x1998->day_names_short;
        kk_std_core_types__list _pat_5_0 = _con_x1998->day_names_min;
        kk_string_t _pat_6_0 = _con_x1998->format_t;
        kk_string_t _pat_7_0 = _con_x1998->format_tt;
        kk_string_t _pat_8_0 = _con_x1998->format_l;
        kk_string_t _pat_9_0 = _con_x1998->format_ll;
        kk_string_t _x_0 = _con_x1998->format_lll;
        kk_string_t _pat_10_0 = _con_x1998->format_llll;
        if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
          kk_string_drop(_pat_9_0, _ctx);
          kk_string_drop(_pat_8_0, _ctx);
          kk_string_drop(_pat_7_0, _ctx);
          kk_string_drop(_pat_6_0, _ctx);
          kk_std_core_types__list_drop(_pat_5_0, _ctx);
          kk_std_core_types__list_drop(_pat_4_0, _ctx);
          kk_std_core_types__list_drop(_pat_3_0, _ctx);
          kk_std_core_types__list_drop(_pat_2_1, _ctx);
          kk_std_core_types__list_drop(_pat_1_2, _ctx);
          kk_string_drop(_pat_10_0, _ctx);
          kk_string_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(locale, _ctx);
        }
        else {
          kk_string_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(locale, _ctx);
        }
        x_0_10718 = _x_0; /*string*/
      }
    }
    else {
      bool _match_x1463;
      bool _brw_x1464 = kk_integer_eq_borrow(x,(kk_integer_from_small(2)),kk_context()); /*bool*/;
      kk_integer_drop(x, _ctx);
      _match_x1463 = _brw_x1464; /*bool*/
      if (_match_x1463) {
        kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
        kk_unit_t keep_2 = kk_Unit;
        kk_evv_set(w_2,kk_context());
        {
          struct kk_std_time_locale_Time_locale* _con_x1999 = kk_std_time_locale__as_Time_locale(locale, _ctx);
          kk_string_t _pat_0_3 = _con_x1999->lang_name;
          kk_std_core_types__list _pat_1_3 = _con_x1999->day_names;
          kk_std_core_types__list _pat_2_3 = _con_x1999->month_names;
          kk_std_core_types__list _pat_3_2 = _con_x1999->month_names_short;
          kk_std_core_types__list _pat_4_1 = _con_x1999->day_names_short;
          kk_std_core_types__list _pat_5_1 = _con_x1999->day_names_min;
          kk_string_t _pat_6_1 = _con_x1999->format_t;
          kk_string_t _pat_7_1 = _con_x1999->format_tt;
          kk_string_t _pat_8_1 = _con_x1999->format_l;
          kk_string_t _x_1 = _con_x1999->format_ll;
          kk_string_t _pat_9_1 = _con_x1999->format_lll;
          kk_string_t _pat_10_1 = _con_x1999->format_llll;
          if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
            kk_string_drop(_pat_9_1, _ctx);
            kk_string_drop(_pat_8_1, _ctx);
            kk_string_drop(_pat_7_1, _ctx);
            kk_string_drop(_pat_6_1, _ctx);
            kk_std_core_types__list_drop(_pat_5_1, _ctx);
            kk_std_core_types__list_drop(_pat_4_1, _ctx);
            kk_std_core_types__list_drop(_pat_3_2, _ctx);
            kk_std_core_types__list_drop(_pat_2_3, _ctx);
            kk_std_core_types__list_drop(_pat_1_3, _ctx);
            kk_string_drop(_pat_10_1, _ctx);
            kk_string_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(locale, _ctx);
          }
          else {
            kk_string_dup(_x_1, _ctx);
            kk_datatype_ptr_decref(locale, _ctx);
          }
          x_0_10718 = _x_1; /*string*/
        }
      }
      else {
        kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
        kk_unit_t keep_3 = kk_Unit;
        kk_evv_set(w_3,kk_context());
        {
          struct kk_std_time_locale_Time_locale* _con_x2000 = kk_std_time_locale__as_Time_locale(locale, _ctx);
          kk_string_t _pat_0_4 = _con_x2000->lang_name;
          kk_std_core_types__list _pat_1_4 = _con_x2000->day_names;
          kk_std_core_types__list _pat_2_4 = _con_x2000->month_names;
          kk_std_core_types__list _pat_3_3 = _con_x2000->month_names_short;
          kk_std_core_types__list _pat_4_3 = _con_x2000->day_names_short;
          kk_std_core_types__list _pat_5_2 = _con_x2000->day_names_min;
          kk_string_t _pat_6_2 = _con_x2000->format_t;
          kk_string_t _pat_7_2 = _con_x2000->format_tt;
          kk_string_t _x_2 = _con_x2000->format_l;
          kk_string_t _pat_8_2 = _con_x2000->format_ll;
          kk_string_t _pat_9_2 = _con_x2000->format_lll;
          kk_string_t _pat_10_2 = _con_x2000->format_llll;
          if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
            kk_string_drop(_pat_9_2, _ctx);
            kk_string_drop(_pat_8_2, _ctx);
            kk_string_drop(_pat_7_2, _ctx);
            kk_string_drop(_pat_6_2, _ctx);
            kk_std_core_types__list_drop(_pat_5_2, _ctx);
            kk_std_core_types__list_drop(_pat_4_3, _ctx);
            kk_std_core_types__list_drop(_pat_3_3, _ctx);
            kk_std_core_types__list_drop(_pat_2_4, _ctx);
            kk_std_core_types__list_drop(_pat_1_4, _ctx);
            kk_string_drop(_pat_10_2, _ctx);
            kk_string_drop(_pat_0_4, _ctx);
            kk_datatype_ptr_free(locale, _ctx);
          }
          else {
            kk_string_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(locale, _ctx);
          }
          x_0_10718 = _x_2; /*string*/
        }
      }
    }
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10718, _ctx);
    kk_box_t _x_x2001 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_l_10634_fun2002(l, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2001);
  }
  {
    return kk_std_time_format__mlift_plocale_l_10633(l, x_0_10718, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10635_fun2004__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10635_fun2004(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10635_fun2004(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10635_fun2004__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_l_10635_fun2004__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_l_10635_fun2004, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10635_fun2004(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10635_fun2004__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_l_10635_fun2004__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_char_t _x_x2005 = kk_std_text_parse_char(l, _ctx); /*char*/
  return kk_char_box(_x_x2005, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_l_10635_fun2007__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_char_t _y_x10566;
  kk_char_t l;
};
static kk_box_t kk_std_time_format__mlift_plocale_l_10635_fun2007(kk_function_t _fself, kk_box_t _b_x230, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_l_10635_fun2007(kk_std_time_locale__time_locale locale, kk_char_t _y_x10566, kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10635_fun2007__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_l_10635_fun2007__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_l_10635_fun2007, kk_context());
  _self->locale = locale;
  _self->_y_x10566 = _y_x10566;
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_l_10635_fun2007(kk_function_t _fself, kk_box_t _b_x230, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_l_10635_fun2007__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_l_10635_fun2007__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_char_t _y_x10566 = _self->_y_x10566; /* char */
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_skip_dup(_y_x10566, _ctx);kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10568_232 = kk_std_core_types__list_unbox(_b_x230, KK_OWNED, _ctx); /*list<char>*/;
  kk_string_t _x_x2008 = kk_std_time_format__mlift_plocale_l_10634(_y_x10566, l, locale, _y_x10568_232, _ctx); /*string*/
  return kk_string_box(_x_x2008);
}

kk_string_t kk_std_time_format__mlift_plocale_l_10635(kk_char_t l, kk_std_time_locale__time_locale locale, kk_char_t _y_x10566, kk_context_t* _ctx) { /* (l : char, locale : std/time/locale/time-locale, char) -> std/text/parse/parse string */ 
  kk_std_core_types__list x_10728 = kk_std_text_parse_many_acc(kk_std_time_format__new_mlift_plocale_l_10635_fun2004(l, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10728, _ctx);
    kk_box_t _x_x2006 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_l_10635_fun2007(locale, _y_x10566, l, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2006);
  }
  {
    return kk_std_time_format__mlift_plocale_l_10634(_y_x10566, l, locale, x_10728, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun2010__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_char_t l;
};
static kk_box_t kk_std_time_format_plocale_l_fun2010(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun2010(kk_std_time_locale__time_locale locale, kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2010__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun2010__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun2010, kk_context());
  _self->locale = locale;
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun2010(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2010__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun2010__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_char_t _y_x10566_250 = kk_char_unbox(_b_x234, KK_OWNED, _ctx); /*char*/;
  kk_string_t _x_x2011 = kk_std_time_format__mlift_plocale_l_10635(l, locale, _y_x10566_250, _ctx); /*string*/
  return kk_string_box(_x_x2011);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun2012__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format_plocale_l_fun2012(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun2012(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2012__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun2012__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun2012, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun2012(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2012__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun2012__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_char_t _x_x2013 = kk_std_text_parse_char(l, _ctx); /*char*/
  return kk_char_box(_x_x2013, _ctx);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun2015__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
  kk_char_t l;
  kk_char_t x_10730;
};
static kk_box_t kk_std_time_format_plocale_l_fun2015(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun2015(kk_std_time_locale__time_locale locale, kk_char_t l, kk_char_t x_10730, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2015__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun2015__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun2015, kk_context());
  _self->locale = locale;
  _self->l = l;
  _self->x_10730 = x_10730;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun2015(kk_function_t _fself, kk_box_t _b_x240, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2015__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun2015__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_char_t l = _self->l; /* char */
  kk_char_t x_10730 = _self->x_10730; /* char */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);kk_skip_dup(l, _ctx);kk_skip_dup(x_10730, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10568_251 = kk_std_core_types__list_unbox(_b_x240, KK_OWNED, _ctx); /*list<char>*/;
  kk_string_t _x_x2016 = kk_std_time_format__mlift_plocale_l_10634(x_10730, l, locale, _y_x10568_251, _ctx); /*string*/
  return kk_string_box(_x_x2016);
}


// lift anonymous function
struct kk_std_time_format_plocale_l_fun2022__t {
  struct kk_function_s _base;
  kk_char_t l;
};
static kk_box_t kk_std_time_format_plocale_l_fun2022(kk_function_t _fself, kk_box_t _b_x246, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_l_fun2022(kk_char_t l, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2022__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_l_fun2022__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_l_fun2022, kk_context());
  _self->l = l;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_l_fun2022(kk_function_t _fself, kk_box_t _b_x246, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_l_fun2022__t* _self = kk_function_as(struct kk_std_time_format_plocale_l_fun2022__t*, _fself, _ctx);
  kk_char_t l = _self->l; /* char */
  kk_drop_match(_self, {kk_skip_dup(l, _ctx);}, {}, _ctx)
  kk_string_t _c_x10571_252 = kk_string_unbox(_b_x246); /*string*/;
  kk_string_t _x_x2023 = kk_std_time_format__mlift_plocale_l_10633(l, _c_x10571_252, _ctx); /*string*/
  return kk_string_box(_x_x2023);
}

kk_string_t kk_std_time_format_plocale_l(kk_std_time_locale__time_locale locale, kk_char_t l, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale, l : char) -> std/text/parse/parse string */ 
  kk_char_t x_10730 = kk_std_text_parse_char(l, _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2009 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_l_fun2010(locale, l, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2009);
  }
  {
    kk_std_core_types__list x_0_10733 = kk_std_text_parse_many_acc(kk_std_time_format_new_plocale_l_fun2012(l, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_10733, _ctx);
      kk_box_t _x_x2014 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_l_fun2015(locale, l, x_10730, _ctx), _ctx); /*10001*/
      return kk_string_unbox(_x_x2014);
    }
    {
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
      kk_std_core_types__list xs = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(x_10730, _ctx), x_0_10733, _ctx); /*list<char>*/;
      kk_integer_t x_1;
      if (kk_std_core_types__is_Nil(xs, _ctx)) {
        x_1 = kk_integer_from_small(0); /*int*/
      }
      else {
        x_1 = kk_std_core_list__unroll_lift_length_5730_10000(xs, kk_integer_from_small(0), _ctx); /*int*/
      }
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      kk_string_t x_2_10738;
      bool _match_x1455 = kk_integer_gte_borrow(x_1,(kk_integer_from_small(4)),kk_context()); /*bool*/;
      if (_match_x1455) {
        kk_integer_drop(x_1, _ctx);
        kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
        kk_unit_t keep_0 = kk_Unit;
        kk_evv_set(w_0,kk_context());
        {
          struct kk_std_time_locale_Time_locale* _con_x2017 = kk_std_time_locale__as_Time_locale(locale, _ctx);
          kk_string_t _pat_0_0_0 = _con_x2017->lang_name;
          kk_std_core_types__list _pat_1_0_0 = _con_x2017->day_names;
          kk_std_core_types__list _pat_2_0_0 = _con_x2017->month_names;
          kk_std_core_types__list _pat_3_0 = _con_x2017->month_names_short;
          kk_std_core_types__list _pat_4 = _con_x2017->day_names_short;
          kk_std_core_types__list _pat_5 = _con_x2017->day_names_min;
          kk_string_t _pat_6 = _con_x2017->format_t;
          kk_string_t _pat_7 = _con_x2017->format_tt;
          kk_string_t _pat_8 = _con_x2017->format_l;
          kk_string_t _pat_9 = _con_x2017->format_ll;
          kk_string_t _pat_10 = _con_x2017->format_lll;
          kk_string_t _x = _con_x2017->format_llll;
          if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
            kk_string_drop(_pat_9, _ctx);
            kk_string_drop(_pat_8, _ctx);
            kk_string_drop(_pat_7, _ctx);
            kk_string_drop(_pat_6, _ctx);
            kk_std_core_types__list_drop(_pat_5, _ctx);
            kk_std_core_types__list_drop(_pat_4, _ctx);
            kk_std_core_types__list_drop(_pat_3_0, _ctx);
            kk_std_core_types__list_drop(_pat_2_0_0, _ctx);
            kk_std_core_types__list_drop(_pat_1_0_0, _ctx);
            kk_string_drop(_pat_10, _ctx);
            kk_string_drop(_pat_0_0_0, _ctx);
            kk_datatype_ptr_free(locale, _ctx);
          }
          else {
            kk_string_dup(_x, _ctx);
            kk_datatype_ptr_decref(locale, _ctx);
          }
          x_2_10738 = _x; /*string*/
        }
      }
      else {
        bool _match_x1456 = kk_integer_eq_borrow(x_1,(kk_integer_from_small(3)),kk_context()); /*bool*/;
        if (_match_x1456) {
          kk_integer_drop(x_1, _ctx);
          kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_unit_t keep_1 = kk_Unit;
          kk_evv_set(w_1,kk_context());
          {
            struct kk_std_time_locale_Time_locale* _con_x2018 = kk_std_time_locale__as_Time_locale(locale, _ctx);
            kk_string_t _pat_0_2_0 = _con_x2018->lang_name;
            kk_std_core_types__list _pat_1_2 = _con_x2018->day_names;
            kk_std_core_types__list _pat_2_1 = _con_x2018->month_names;
            kk_std_core_types__list _pat_3_0_0 = _con_x2018->month_names_short;
            kk_std_core_types__list _pat_4_0 = _con_x2018->day_names_short;
            kk_std_core_types__list _pat_5_0 = _con_x2018->day_names_min;
            kk_string_t _pat_6_0 = _con_x2018->format_t;
            kk_string_t _pat_7_0 = _con_x2018->format_tt;
            kk_string_t _pat_8_0 = _con_x2018->format_l;
            kk_string_t _pat_9_0 = _con_x2018->format_ll;
            kk_string_t _x_0 = _con_x2018->format_lll;
            kk_string_t _pat_10_0 = _con_x2018->format_llll;
            if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
              kk_string_drop(_pat_9_0, _ctx);
              kk_string_drop(_pat_8_0, _ctx);
              kk_string_drop(_pat_7_0, _ctx);
              kk_string_drop(_pat_6_0, _ctx);
              kk_std_core_types__list_drop(_pat_5_0, _ctx);
              kk_std_core_types__list_drop(_pat_4_0, _ctx);
              kk_std_core_types__list_drop(_pat_3_0_0, _ctx);
              kk_std_core_types__list_drop(_pat_2_1, _ctx);
              kk_std_core_types__list_drop(_pat_1_2, _ctx);
              kk_string_drop(_pat_10_0, _ctx);
              kk_string_drop(_pat_0_2_0, _ctx);
              kk_datatype_ptr_free(locale, _ctx);
            }
            else {
              kk_string_dup(_x_0, _ctx);
              kk_datatype_ptr_decref(locale, _ctx);
            }
            x_2_10738 = _x_0; /*string*/
          }
        }
        else {
          bool _match_x1457;
          bool _brw_x1458 = kk_integer_eq_borrow(x_1,(kk_integer_from_small(2)),kk_context()); /*bool*/;
          kk_integer_drop(x_1, _ctx);
          _match_x1457 = _brw_x1458; /*bool*/
          if (_match_x1457) {
            kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
            kk_unit_t keep_2 = kk_Unit;
            kk_evv_set(w_2,kk_context());
            {
              struct kk_std_time_locale_Time_locale* _con_x2019 = kk_std_time_locale__as_Time_locale(locale, _ctx);
              kk_string_t _pat_0_3 = _con_x2019->lang_name;
              kk_std_core_types__list _pat_1_3 = _con_x2019->day_names;
              kk_std_core_types__list _pat_2_3 = _con_x2019->month_names;
              kk_std_core_types__list _pat_3_2 = _con_x2019->month_names_short;
              kk_std_core_types__list _pat_4_1 = _con_x2019->day_names_short;
              kk_std_core_types__list _pat_5_1 = _con_x2019->day_names_min;
              kk_string_t _pat_6_1 = _con_x2019->format_t;
              kk_string_t _pat_7_1 = _con_x2019->format_tt;
              kk_string_t _pat_8_1 = _con_x2019->format_l;
              kk_string_t _x_1 = _con_x2019->format_ll;
              kk_string_t _pat_9_1 = _con_x2019->format_lll;
              kk_string_t _pat_10_1 = _con_x2019->format_llll;
              if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
                kk_string_drop(_pat_9_1, _ctx);
                kk_string_drop(_pat_8_1, _ctx);
                kk_string_drop(_pat_7_1, _ctx);
                kk_string_drop(_pat_6_1, _ctx);
                kk_std_core_types__list_drop(_pat_5_1, _ctx);
                kk_std_core_types__list_drop(_pat_4_1, _ctx);
                kk_std_core_types__list_drop(_pat_3_2, _ctx);
                kk_std_core_types__list_drop(_pat_2_3, _ctx);
                kk_std_core_types__list_drop(_pat_1_3, _ctx);
                kk_string_drop(_pat_10_1, _ctx);
                kk_string_drop(_pat_0_3, _ctx);
                kk_datatype_ptr_free(locale, _ctx);
              }
              else {
                kk_string_dup(_x_1, _ctx);
                kk_datatype_ptr_decref(locale, _ctx);
              }
              x_2_10738 = _x_1; /*string*/
            }
          }
          else {
            kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
            kk_unit_t keep_3 = kk_Unit;
            kk_evv_set(w_3,kk_context());
            {
              struct kk_std_time_locale_Time_locale* _con_x2020 = kk_std_time_locale__as_Time_locale(locale, _ctx);
              kk_string_t _pat_0_4 = _con_x2020->lang_name;
              kk_std_core_types__list _pat_1_4 = _con_x2020->day_names;
              kk_std_core_types__list _pat_2_4 = _con_x2020->month_names;
              kk_std_core_types__list _pat_3_3 = _con_x2020->month_names_short;
              kk_std_core_types__list _pat_4_3 = _con_x2020->day_names_short;
              kk_std_core_types__list _pat_5_2 = _con_x2020->day_names_min;
              kk_string_t _pat_6_2 = _con_x2020->format_t;
              kk_string_t _pat_7_2 = _con_x2020->format_tt;
              kk_string_t _x_2 = _con_x2020->format_l;
              kk_string_t _pat_8_2 = _con_x2020->format_ll;
              kk_string_t _pat_9_2 = _con_x2020->format_lll;
              kk_string_t _pat_10_2 = _con_x2020->format_llll;
              if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
                kk_string_drop(_pat_9_2, _ctx);
                kk_string_drop(_pat_8_2, _ctx);
                kk_string_drop(_pat_7_2, _ctx);
                kk_string_drop(_pat_6_2, _ctx);
                kk_std_core_types__list_drop(_pat_5_2, _ctx);
                kk_std_core_types__list_drop(_pat_4_3, _ctx);
                kk_std_core_types__list_drop(_pat_3_3, _ctx);
                kk_std_core_types__list_drop(_pat_2_4, _ctx);
                kk_std_core_types__list_drop(_pat_1_4, _ctx);
                kk_string_drop(_pat_10_2, _ctx);
                kk_string_drop(_pat_0_4, _ctx);
                kk_datatype_ptr_free(locale, _ctx);
              }
              else {
                kk_string_dup(_x_2, _ctx);
                kk_datatype_ptr_decref(locale, _ctx);
              }
              x_2_10738 = _x_2; /*string*/
            }
          }
        }
      }
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10738, _ctx);
        kk_box_t _x_x2021 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_l_fun2022(l, _ctx), _ctx); /*10001*/
        return kk_string_unbox(_x_x2021);
      }
      {
        bool _match_x1454 = (l == ('L')); /*bool*/;
        if (_match_x1454) {
          return x_2_10738;
        }
        {
          kk_string_t _x_x2024;
          kk_string_t _x_x2025;
          kk_string_t _x_x2026;
          kk_string_t _x_x2027;
          kk_string_t _x_x2028;
          kk_string_t _x_x2029;
          kk_define_string_literal(, _s_x2030, 2, "dd", _ctx)
          _x_x2029 = kk_string_dup(_s_x2030, _ctx); /*string*/
          kk_string_t _x_x2031;
          kk_define_string_literal(, _s_x2032, 1, "d", _ctx)
          _x_x2031 = kk_string_dup(_s_x2032, _ctx); /*string*/
          _x_x2028 = kk_string_replace_all(x_2_10738,_x_x2029,_x_x2031,kk_context()); /*string*/
          kk_string_t _x_x2033;
          kk_define_string_literal(, _s_x2034, 2, "dd", _ctx)
          _x_x2033 = kk_string_dup(_s_x2034, _ctx); /*string*/
          kk_string_t _x_x2035;
          kk_define_string_literal(, _s_x2036, 3, "ddd", _ctx)
          _x_x2035 = kk_string_dup(_s_x2036, _ctx); /*string*/
          _x_x2027 = kk_string_replace_all(_x_x2028,_x_x2033,_x_x2035,kk_context()); /*string*/
          kk_string_t _x_x2037;
          kk_define_string_literal(, _s_x2038, 2, "MM", _ctx)
          _x_x2037 = kk_string_dup(_s_x2038, _ctx); /*string*/
          kk_string_t _x_x2039;
          kk_define_string_literal(, _s_x2040, 1, "M", _ctx)
          _x_x2039 = kk_string_dup(_s_x2040, _ctx); /*string*/
          _x_x2026 = kk_string_replace_all(_x_x2027,_x_x2037,_x_x2039,kk_context()); /*string*/
          kk_string_t _x_x2041;
          kk_define_string_literal(, _s_x2042, 2, "MM", _ctx)
          _x_x2041 = kk_string_dup(_s_x2042, _ctx); /*string*/
          kk_string_t _x_x2043;
          kk_define_string_literal(, _s_x2044, 3, "MMM", _ctx)
          _x_x2043 = kk_string_dup(_s_x2044, _ctx); /*string*/
          _x_x2025 = kk_string_replace_all(_x_x2026,_x_x2041,_x_x2043,kk_context()); /*string*/
          kk_string_t _x_x2045;
          kk_define_string_literal(, _s_x2046, 2, "DD", _ctx)
          _x_x2045 = kk_string_dup(_s_x2046, _ctx); /*string*/
          kk_string_t _x_x2047;
          kk_define_string_literal(, _s_x2048, 1, "D", _ctx)
          _x_x2047 = kk_string_dup(_s_x2048, _ctx); /*string*/
          _x_x2024 = kk_string_replace_all(_x_x2025,_x_x2045,_x_x2047,kk_context()); /*string*/
          kk_string_t _x_x2049;
          kk_define_string_literal(, _s_x2050, 2, "DD", _ctx)
          _x_x2049 = kk_string_dup(_s_x2050, _ctx); /*string*/
          kk_string_t _x_x2051;
          kk_define_string_literal(, _s_x2052, 3, "DDD", _ctx)
          _x_x2051 = kk_string_dup(_s_x2052, _ctx); /*string*/
          return kk_string_replace_all(_x_x2024,_x_x2049,_x_x2051,kk_context());
        }
      }
    }
  }
}
 
// lifted local: @lift-plocale@10526, s, ps@10026, plocale, @spec-x10416
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10407, using:
// @uniq-pred@10407 = fn(c: char){
//   std/core/char/(!=)(c, '\x27');
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_plocale_10527(kk_std_core_sslice__sslice _uniq_slice_10406, kk_std_core_types__list _uniq_acc_10408, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1450;
  kk_std_core_sslice__sslice _x_x2053 = kk_std_core_sslice__sslice_dup(_uniq_slice_10406, _ctx); /*sslice/sslice*/
  _match_x1450 = kk_std_core_sslice_next(_x_x2053, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1450, _ctx)) {
    kk_box_t _box_x253 = _match_x1450._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10410 = kk_std_core_types__tuple2_unbox(_box_x253, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10410, _ctx)) {
      kk_box_t _box_x254 = _uniq_pat_0_10410.fst;
      kk_box_t _box_x255 = _uniq_pat_0_10410.snd;
      kk_char_t _uniq_c_10411 = kk_char_unbox(_box_x254, KK_BORROWED, _ctx);
      if (_uniq_c_10411 != ('\'')) {
        kk_std_core_sslice__sslice _uniq_rest_10412 = kk_std_core_sslice__sslice_unbox(_box_x255, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10406, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10412, _ctx);
        kk_std_core_types__maybe_drop(_match_x1450, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2054 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10411, _ctx), _uniq_acc_10408, _ctx); /*list<10021>*/
          _uniq_slice_10406 = _uniq_rest_10412;
          _uniq_acc_10408 = _x_x2054;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1450, _ctx);
    kk_std_core_types__list _b_x258_262;
    if (kk_std_core_types__is_Nil(_uniq_acc_10408, _ctx)) {
      _b_x258_262 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x258_262 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10408, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x258_262, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10406, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_format__mlift_lift_plocale_10526_10636(kk_string_t _uniq_msg_10387, kk_std_core_types__maybe _y_x10573, kk_context_t* _ctx) { /* (string, maybe<list<char>>) -> std/text/parse/parse list<char> */ 
  if (kk_std_core_types__is_Nothing(_y_x10573, _ctx)) {
    kk_std_core_hnd__ev ev_10749 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2055;
    {
      struct kk_std_core_hnd_Ev* _con_x2056 = kk_std_core_hnd__as_Ev(ev_10749, _ctx);
      kk_box_t _box_x264 = _con_x2056->hnd;
      int32_t m = _con_x2056->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x264, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1448;
      kk_std_core_hnd__clause1 _brw_x1449 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1448 = _brw_x1449; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x268 = _match_x1448.clause;
        _x_x2055 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x268, (_fun_unbox_x268, m, ev_10749, kk_string_box(_uniq_msg_10387), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x2055, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x272 = _y_x10573._cons.Just.value;
    kk_std_core_types__list _uniq_x_10404 = kk_std_core_types__list_unbox(_box_x272, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_x_10404, _ctx);
    kk_std_core_types__maybe_drop(_y_x10573, _ctx);
    kk_string_drop(_uniq_msg_10387, _ctx);
    return _uniq_x_10404;
  }
}
 
// lifted local: s, ps@10026, plocale, @spec-x10405
// specialized: std/text/parse/chars-are, on parameters @uniq-pred@10388, using:
// @uniq-pred@10388 = fn(c: char){
//   std/core/char/(!=)(c, '\x27');
// }


// lift anonymous function
struct kk_std_time_format__lift_plocale_10526_fun2059__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__lift_plocale_10526_fun2059(kk_function_t _fself, kk_box_t _b_x286, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_lift_plocale_10526_fun2059(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__lift_plocale_10526_fun2059, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__lift_plocale_10526_fun2059(kk_function_t _fself, kk_box_t _b_x286, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2060;
  kk_std_core_types__tuple2 _match_x1446;
  kk_std_core_sslice__sslice _x_x2061 = kk_std_core_sslice__sslice_unbox(_b_x286, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1446 = kk_std_time_format__lift_plocale_10527(_x_x2061, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x287 = _match_x1446.fst;
    kk_box_t _box_x288 = _match_x1446.snd;
    kk_std_core_types__list _uniq_pat_0_0_10391 = kk_std_core_types__list_unbox(_box_x287, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10392 = kk_std_core_sslice__sslice_unbox(_box_x288, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10391, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1446, _ctx);
      _x_x2060 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2062;
    }
  }
  {
    kk_box_t _box_x289 = _match_x1446.fst;
    kk_box_t _box_x290 = _match_x1446.snd;
    kk_std_core_sslice__sslice _uniq_rest_10398 = kk_std_core_sslice__sslice_unbox(_box_x290, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10397 = kk_std_core_types__list_unbox(_box_x289, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10398, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10397, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1446, _ctx);
    kk_box_t _x_x2063;
    kk_std_core_types__tuple2 _x_x2064 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10397, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10398, _ctx), _ctx); /*(10037, 10038)*/
    _x_x2063 = kk_std_core_types__tuple2_box(_x_x2064, _ctx); /*10024*/
    _x_x2060 = kk_std_core_types__new_Just(_x_x2063, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2062: ;
  return kk_std_core_types__maybe_box(_x_x2060, _ctx);
}


// lift anonymous function
struct kk_std_time_format__lift_plocale_10526_fun2066__t {
  struct kk_function_s _base;
  kk_string_t _uniq_msg_10387_0;
};
static kk_box_t kk_std_time_format__lift_plocale_10526_fun2066(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_lift_plocale_10526_fun2066(kk_string_t _uniq_msg_10387_0, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_plocale_10526_fun2066__t* _self = kk_function_alloc_as(struct kk_std_time_format__lift_plocale_10526_fun2066__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__lift_plocale_10526_fun2066, kk_context());
  _self->_uniq_msg_10387_0 = _uniq_msg_10387_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__lift_plocale_10526_fun2066(kk_function_t _fself, kk_box_t _b_x299, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_plocale_10526_fun2066__t* _self = kk_function_as(struct kk_std_time_format__lift_plocale_10526_fun2066__t*, _fself, _ctx);
  kk_string_t _uniq_msg_10387_0 = _self->_uniq_msg_10387_0; /* string */
  kk_drop_match(_self, {kk_string_dup(_uniq_msg_10387_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10573_0_310 = kk_std_core_types__maybe_unbox(_b_x299, KK_OWNED, _ctx); /*maybe<list<char>>*/;
  kk_std_core_types__list _x_x2067 = kk_std_time_format__mlift_lift_plocale_10526_10636(_uniq_msg_10387_0, _y_x10573_0_310, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x2067, _ctx);
}

kk_std_core_types__list kk_std_time_format__lift_plocale_10526(kk_string_t _uniq_msg_10387_0, kk_context_t* _ctx) { /* (string) -> std/text/parse/parse list<char> */ 
  kk_std_core_hnd__ev ev_0_10755 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_0_10752;
  kk_box_t _x_x2057;
  {
    struct kk_std_core_hnd_Ev* _con_x2058 = kk_std_core_hnd__as_Ev(ev_0_10755, _ctx);
    kk_box_t _box_x273 = _con_x2058->hnd;
    int32_t m_0 = _con_x2058->marker;
    kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x273, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h_0, _ctx);
    kk_std_core_hnd__clause1 _match_x1445;
    kk_std_core_hnd__clause1 _brw_x1447 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
    kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
    _match_x1445 = _brw_x1447; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
    {
      kk_function_t _fun_unbox_x280 = _match_x1445.clause;
      _x_x2057 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x280, (_fun_unbox_x280, m_0, ev_0_10755, kk_function_box(kk_std_time_format__new_lift_plocale_10526_fun2059(_ctx), _ctx), _ctx), _ctx); /*10010*/
    }
  }
  x_0_10752 = kk_std_core_types__maybe_unbox(_x_x2057, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_0_10752, _ctx);
    kk_box_t _x_x2065 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_lift_plocale_10526_fun2066(_uniq_msg_10387_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x2065, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_0_10752, _ctx)) {
    kk_std_core_hnd__ev ev_1_10758 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2068;
    {
      struct kk_std_core_hnd_Ev* _con_x2069 = kk_std_core_hnd__as_Ev(ev_1_10758, _ctx);
      kk_box_t _box_x300 = _con_x2069->hnd;
      int32_t m_1 = _con_x2069->marker;
      kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x300, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_1, _ctx);
      kk_std_core_hnd__clause1 _match_x1443;
      kk_std_core_hnd__clause1 _brw_x1444 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
      _match_x1443 = _brw_x1444; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x304 = _match_x1443.clause;
        _x_x2068 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x304, (_fun_unbox_x304, m_1, ev_1_10758, kk_string_box(_uniq_msg_10387_0), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x2068, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x308 = x_0_10752._cons.Just.value;
    kk_std_core_types__list _uniq_x_10404_0 = kk_std_core_types__list_unbox(_box_x308, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_x_10404_0, _ctx);
    kk_std_core_types__maybe_drop(x_0_10752, _ctx);
    kk_string_drop(_uniq_msg_10387_0, _ctx);
    return _uniq_x_10404_0;
  }
}
 
// lifted local: @lift-plocale@10528, s@0, ps@10026, plocale, @spec-x10447
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10438, using:
// @uniq-pred@10438 = fn(c@0: char){
//   std/core/char/(!=)(c@0, '\x22');
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_plocale_10529(kk_std_core_sslice__sslice _uniq_slice_10437, kk_std_core_types__list _uniq_acc_10439, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1441;
  kk_std_core_sslice__sslice _x_x2070 = kk_std_core_sslice__sslice_dup(_uniq_slice_10437, _ctx); /*sslice/sslice*/
  _match_x1441 = kk_std_core_sslice_next(_x_x2070, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1441, _ctx)) {
    kk_box_t _box_x311 = _match_x1441._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10441 = kk_std_core_types__tuple2_unbox(_box_x311, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10441, _ctx)) {
      kk_box_t _box_x312 = _uniq_pat_0_10441.fst;
      kk_box_t _box_x313 = _uniq_pat_0_10441.snd;
      kk_char_t _uniq_c_10442 = kk_char_unbox(_box_x312, KK_BORROWED, _ctx);
      if (_uniq_c_10442 != ('"')) {
        kk_std_core_sslice__sslice _uniq_rest_10443 = kk_std_core_sslice__sslice_unbox(_box_x313, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10437, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10443, _ctx);
        kk_std_core_types__maybe_drop(_match_x1441, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2071 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10442, _ctx), _uniq_acc_10439, _ctx); /*list<10021>*/
          _uniq_slice_10437 = _uniq_rest_10443;
          _uniq_acc_10439 = _x_x2071;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1441, _ctx);
    kk_std_core_types__list _b_x316_320;
    if (kk_std_core_types__is_Nil(_uniq_acc_10439, _ctx)) {
      _b_x316_320 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x316_320 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10439, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x316_320, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10437, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_time_format__mlift_lift_plocale_10528_10637(kk_string_t _uniq_msg_10418, kk_std_core_types__maybe _y_x10576, kk_context_t* _ctx) { /* (string, maybe<list<char>>) -> std/text/parse/parse list<char> */ 
  if (kk_std_core_types__is_Nothing(_y_x10576, _ctx)) {
    kk_std_core_hnd__ev ev_10761 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2072;
    {
      struct kk_std_core_hnd_Ev* _con_x2073 = kk_std_core_hnd__as_Ev(ev_10761, _ctx);
      kk_box_t _box_x322 = _con_x2073->hnd;
      int32_t m = _con_x2073->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x322, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1439;
      kk_std_core_hnd__clause1 _brw_x1440 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1439 = _brw_x1440; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x326 = _match_x1439.clause;
        _x_x2072 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x326, (_fun_unbox_x326, m, ev_10761, kk_string_box(_uniq_msg_10418), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x2072, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x330 = _y_x10576._cons.Just.value;
    kk_std_core_types__list _uniq_x_10435 = kk_std_core_types__list_unbox(_box_x330, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_x_10435, _ctx);
    kk_std_core_types__maybe_drop(_y_x10576, _ctx);
    kk_string_drop(_uniq_msg_10418, _ctx);
    return _uniq_x_10435;
  }
}
 
// lifted local: s@0, ps@10026, plocale, @spec-x10436
// specialized: std/text/parse/chars-are, on parameters @uniq-pred@10419, using:
// @uniq-pred@10419 = fn(c@0: char){
//   std/core/char/(!=)(c@0, '\x22');
// }


// lift anonymous function
struct kk_std_time_format__lift_plocale_10528_fun2076__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__lift_plocale_10528_fun2076(kk_function_t _fself, kk_box_t _b_x344, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_lift_plocale_10528_fun2076(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__lift_plocale_10528_fun2076, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__lift_plocale_10528_fun2076(kk_function_t _fself, kk_box_t _b_x344, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2077;
  kk_std_core_types__tuple2 _match_x1437;
  kk_std_core_sslice__sslice _x_x2078 = kk_std_core_sslice__sslice_unbox(_b_x344, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1437 = kk_std_time_format__lift_plocale_10529(_x_x2078, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x345 = _match_x1437.fst;
    kk_box_t _box_x346 = _match_x1437.snd;
    kk_std_core_types__list _uniq_pat_0_0_10422 = kk_std_core_types__list_unbox(_box_x345, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10423 = kk_std_core_sslice__sslice_unbox(_box_x346, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10422, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1437, _ctx);
      _x_x2077 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2079;
    }
  }
  {
    kk_box_t _box_x347 = _match_x1437.fst;
    kk_box_t _box_x348 = _match_x1437.snd;
    kk_std_core_sslice__sslice _uniq_rest_10429 = kk_std_core_sslice__sslice_unbox(_box_x348, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10428 = kk_std_core_types__list_unbox(_box_x347, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10429, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10428, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1437, _ctx);
    kk_box_t _x_x2080;
    kk_std_core_types__tuple2 _x_x2081 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10428, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10429, _ctx), _ctx); /*(10037, 10038)*/
    _x_x2080 = kk_std_core_types__tuple2_box(_x_x2081, _ctx); /*10024*/
    _x_x2077 = kk_std_core_types__new_Just(_x_x2080, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2079: ;
  return kk_std_core_types__maybe_box(_x_x2077, _ctx);
}


// lift anonymous function
struct kk_std_time_format__lift_plocale_10528_fun2083__t {
  struct kk_function_s _base;
  kk_string_t _uniq_msg_10418_0;
};
static kk_box_t kk_std_time_format__lift_plocale_10528_fun2083(kk_function_t _fself, kk_box_t _b_x357, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_lift_plocale_10528_fun2083(kk_string_t _uniq_msg_10418_0, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_plocale_10528_fun2083__t* _self = kk_function_alloc_as(struct kk_std_time_format__lift_plocale_10528_fun2083__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__lift_plocale_10528_fun2083, kk_context());
  _self->_uniq_msg_10418_0 = _uniq_msg_10418_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__lift_plocale_10528_fun2083(kk_function_t _fself, kk_box_t _b_x357, kk_context_t* _ctx) {
  struct kk_std_time_format__lift_plocale_10528_fun2083__t* _self = kk_function_as(struct kk_std_time_format__lift_plocale_10528_fun2083__t*, _fself, _ctx);
  kk_string_t _uniq_msg_10418_0 = _self->_uniq_msg_10418_0; /* string */
  kk_drop_match(_self, {kk_string_dup(_uniq_msg_10418_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10576_0_368 = kk_std_core_types__maybe_unbox(_b_x357, KK_OWNED, _ctx); /*maybe<list<char>>*/;
  kk_std_core_types__list _x_x2084 = kk_std_time_format__mlift_lift_plocale_10528_10637(_uniq_msg_10418_0, _y_x10576_0_368, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x2084, _ctx);
}

kk_std_core_types__list kk_std_time_format__lift_plocale_10528(kk_string_t _uniq_msg_10418_0, kk_context_t* _ctx) { /* (string) -> std/text/parse/parse list<char> */ 
  kk_std_core_hnd__ev ev_0_10767 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_0_10764;
  kk_box_t _x_x2074;
  {
    struct kk_std_core_hnd_Ev* _con_x2075 = kk_std_core_hnd__as_Ev(ev_0_10767, _ctx);
    kk_box_t _box_x331 = _con_x2075->hnd;
    int32_t m_0 = _con_x2075->marker;
    kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x331, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h_0, _ctx);
    kk_std_core_hnd__clause1 _match_x1436;
    kk_std_core_hnd__clause1 _brw_x1438 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
    kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
    _match_x1436 = _brw_x1438; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
    {
      kk_function_t _fun_unbox_x338 = _match_x1436.clause;
      _x_x2074 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x338, (_fun_unbox_x338, m_0, ev_0_10767, kk_function_box(kk_std_time_format__new_lift_plocale_10528_fun2076(_ctx), _ctx), _ctx), _ctx); /*10010*/
    }
  }
  x_0_10764 = kk_std_core_types__maybe_unbox(_x_x2074, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_0_10764, _ctx);
    kk_box_t _x_x2082 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_lift_plocale_10528_fun2083(_uniq_msg_10418_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x2082, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_0_10764, _ctx)) {
    kk_std_core_hnd__ev ev_1_10770 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2085;
    {
      struct kk_std_core_hnd_Ev* _con_x2086 = kk_std_core_hnd__as_Ev(ev_1_10770, _ctx);
      kk_box_t _box_x358 = _con_x2086->hnd;
      int32_t m_1 = _con_x2086->marker;
      kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x358, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_1, _ctx);
      kk_std_core_hnd__clause1 _match_x1434;
      kk_std_core_hnd__clause1 _brw_x1435 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
      _match_x1434 = _brw_x1435; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x362 = _match_x1434.clause;
        _x_x2085 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x362, (_fun_unbox_x362, m_1, ev_1_10770, kk_string_box(_uniq_msg_10418_0), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x2085, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x366 = x_0_10764._cons.Just.value;
    kk_std_core_types__list _uniq_x_10435_0 = kk_std_core_types__list_unbox(_box_x366, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_x_10435_0, _ctx);
    kk_std_core_types__maybe_drop(x_0_10764, _ctx);
    kk_string_drop(_uniq_msg_10418_0, _ctx);
    return _uniq_x_10435_0;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10639_fun2090__t {
  struct kk_function_s _base;
  kk_string_t _c_x10583;
};
static kk_string_t kk_std_time_format__mlift_plocale_10639_fun2090(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10639_fun2090(kk_string_t _c_x10583, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10639_fun2090__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_10639_fun2090__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_10639_fun2090, kk_context());
  _self->_c_x10583 = _c_x10583;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_format__mlift_plocale_10639_fun2090(kk_function_t _fself, kk_char_t wild___0, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10639_fun2090__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_10639_fun2090__t*, _fself, _ctx);
  kk_string_t _c_x10583 = _self->_c_x10583; /* string */
  kk_drop_match(_self, {kk_string_dup(_c_x10583, _ctx);}, {}, _ctx)
  kk_string_t _x_x2091 = kk_std_core_string_char_fs_string('\'', _ctx); /*string*/
  kk_string_t _x_x2092;
  kk_string_t _x_x2093 = kk_std_core_string_char_fs_string('\'', _ctx); /*string*/
  _x_x2092 = kk_std_core_types__lp__plus__plus__rp_(_c_x10583, _x_x2093, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x2091, _x_x2092, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10639_fun2095__t {
  struct kk_function_s _base;
  kk_function_t next_10774;
};
static kk_box_t kk_std_time_format__mlift_plocale_10639_fun2095(kk_function_t _fself, kk_box_t _b_x370, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10639_fun2095(kk_function_t next_10774, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10639_fun2095__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_10639_fun2095__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_10639_fun2095, kk_context());
  _self->next_10774 = next_10774;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10639_fun2095(kk_function_t _fself, kk_box_t _b_x370, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10639_fun2095__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_10639_fun2095__t*, _fself, _ctx);
  kk_function_t next_10774 = _self->next_10774; /* (char) -> std/text/parse/parse string */
  kk_drop_match(_self, {kk_function_dup(next_10774, _ctx);}, {}, _ctx)
  kk_string_t _x_x2096;
  kk_char_t _x_x2097 = kk_char_unbox(_b_x370, KK_OWNED, _ctx); /*char*/
  _x_x2096 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10774, (next_10774, _x_x2097, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x2096);
}

kk_string_t kk_std_time_format__mlift_plocale_10639(kk_string_t _c_x10583, kk_context_t* _ctx) { /* (string) -> string */ 
  kk_char_t x_10773 = kk_std_text_parse_char('\'', _ctx); /*char*/;
  kk_function_t next_10774 = kk_std_time_format__new_mlift_plocale_10639_fun2090(_c_x10583, _ctx); /*(char) -> std/text/parse/parse string*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2094 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10639_fun2095(next_10774, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2094);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10774, (next_10774, x_10773, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10640_fun2100__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2100(kk_function_t _fself, kk_box_t _b_x385, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10640_fun2100(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10640_fun2100, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2100(kk_function_t _fself, kk_box_t _b_x385, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2101;
  kk_std_core_types__tuple2 _match_x1430;
  kk_std_core_sslice__sslice _x_x2102 = kk_std_core_sslice__sslice_unbox(_b_x385, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1430 = kk_std_time_format__lift_plocale_10527(_x_x2102, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x386 = _match_x1430.fst;
    kk_box_t _box_x387 = _match_x1430.snd;
    kk_std_core_types__list _uniq_pat_0_0_10391 = kk_std_core_types__list_unbox(_box_x386, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10392 = kk_std_core_sslice__sslice_unbox(_box_x387, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10391, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1430, _ctx);
      _x_x2101 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2103;
    }
  }
  {
    kk_box_t _box_x388 = _match_x1430.fst;
    kk_box_t _box_x389 = _match_x1430.snd;
    kk_std_core_sslice__sslice _uniq_rest_10398 = kk_std_core_sslice__sslice_unbox(_box_x389, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10397 = kk_std_core_types__list_unbox(_box_x388, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10398, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10397, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1430, _ctx);
    kk_box_t _x_x2104;
    kk_std_core_types__tuple2 _x_x2105 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10397, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10398, _ctx), _ctx); /*(10037, 10038)*/
    _x_x2104 = kk_std_core_types__tuple2_box(_x_x2105, _ctx); /*10024*/
    _x_x2101 = kk_std_core_types__new_Just(_x_x2104, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2103: ;
  return kk_std_core_types__maybe_box(_x_x2101, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10640_fun2107__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2107(kk_function_t _fself, kk_box_t _b_x398, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10640_fun2107(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10640_fun2107, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2107(kk_function_t _fself, kk_box_t _b_x398, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x2108;
  kk_string_t _x_x2109 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x_x2111 = kk_std_core_types__maybe_unbox(_b_x398, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2108 = kk_std_time_format__mlift_lift_plocale_10526_10636(_x_x2109, _x_x2111, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x2108, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10640_fun2118__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2118(kk_function_t _fself, kk_box_t _b_x411, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10640_fun2118(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10640_fun2118, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2118(kk_function_t _fself, kk_box_t _b_x411, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2119;
  kk_std_core_types__list _x_x2120 = kk_std_core_types__list_unbox(_b_x411, KK_OWNED, _ctx); /*list<char>*/
  _x_x2119 = kk_std_core_string_listchar_fs_string(_x_x2120, _ctx); /*string*/
  return kk_string_box(_x_x2119);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10640_fun2123__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2123(kk_function_t _fself, kk_box_t _b_x414, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10640_fun2123(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10640_fun2123, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10640_fun2123(kk_function_t _fself, kk_box_t _b_x414, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2124;
  kk_string_t _x_x2125 = kk_string_unbox(_b_x414); /*string*/
  _x_x2124 = kk_std_time_format__mlift_plocale_10639(_x_x2125, _ctx); /*string*/
  return kk_string_box(_x_x2124);
}

kk_string_t kk_std_time_format__mlift_plocale_10640(bool _y_x10581, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse string */ 
  kk_string_t x_10777;
  if (_y_x10581) {
    kk_std_core_hnd__ev ev_0_10755 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_10752;
    kk_box_t _x_x2098;
    {
      struct kk_std_core_hnd_Ev* _con_x2099 = kk_std_core_hnd__as_Ev(ev_0_10755, _ctx);
      kk_box_t _box_x372 = _con_x2099->hnd;
      int32_t m_0 = _con_x2099->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x372, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      kk_std_core_hnd__clause1 _match_x1429;
      kk_std_core_hnd__clause1 _brw_x1431 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
      _match_x1429 = _brw_x1431; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x379 = _match_x1429.clause;
        _x_x2098 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x379, (_fun_unbox_x379, m_0, ev_0_10755, kk_function_box(kk_std_time_format__new_mlift_plocale_10640_fun2100(_ctx), _ctx), _ctx), _ctx); /*10010*/
      }
    }
    x_0_10752 = kk_std_core_types__maybe_unbox(_x_x2098, KK_OWNED, _ctx); /*maybe<list<char>>*/
    kk_std_core_types__list x_0_10779;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10752, _ctx);
      kk_box_t _x_x2106 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10640_fun2107(_ctx), _ctx); /*10001*/
      x_0_10779 = kk_std_core_types__list_unbox(_x_x2106, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      if (kk_std_core_types__is_Nothing(x_0_10752, _ctx)) {
        kk_std_core_hnd__ev ev_1_10758 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_box_t _x_x2112;
        {
          struct kk_std_core_hnd_Ev* _con_x2113 = kk_std_core_hnd__as_Ev(ev_1_10758, _ctx);
          kk_box_t _box_x399 = _con_x2113->hnd;
          int32_t m_1 = _con_x2113->marker;
          kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x399, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_1, _ctx);
          kk_std_core_hnd__clause1 _match_x1427;
          kk_std_core_hnd__clause1 _brw_x1428 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
          kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
          _match_x1427 = _brw_x1428; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
          {
            kk_function_t _fun_unbox_x403 = _match_x1427.clause;
            kk_box_t _x_x2114;
            kk_string_t _x_x2115 = kk_string_empty(); /*string*/
            _x_x2114 = kk_string_box(_x_x2115); /*10009*/
            _x_x2112 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x403, (_fun_unbox_x403, m_1, ev_1_10758, _x_x2114, _ctx), _ctx); /*10010*/
          }
        }
        x_0_10779 = kk_std_core_types__list_unbox(_x_x2112, KK_OWNED, _ctx); /*list<char>*/
      }
      else {
        kk_box_t _box_x407 = x_0_10752._cons.Just.value;
        kk_std_core_types__list _uniq_x_10404_0 = kk_std_core_types__list_unbox(_box_x407, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(_uniq_x_10404_0, _ctx);
        kk_std_core_types__maybe_drop(x_0_10752, _ctx);
        x_0_10779 = _uniq_x_10404_0; /*list<char>*/
      }
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_10779, _ctx);
      kk_box_t _x_x2117 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10640_fun2118(_ctx), _ctx); /*10001*/
      x_10777 = kk_string_unbox(_x_x2117); /*string*/
    }
    else {
      x_10777 = kk_std_core_string_listchar_fs_string(x_0_10779, _ctx); /*string*/
    }
  }
  else {
    x_10777 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10777, _ctx);
    kk_box_t _x_x2122 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10640_fun2123(_ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2122);
  }
  {
    return kk_std_time_format__mlift_plocale_10639(x_10777, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10641_fun2129__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10641_fun2129(kk_function_t _fself, kk_box_t _b_x423, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10641_fun2129(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10641_fun2129, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10641_fun2129(kk_function_t _fself, kk_box_t _b_x423, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2130;
  bool _x_x2131 = kk_bool_unbox(_b_x423); /*bool*/
  _x_x2130 = kk_std_time_format__mlift_plocale_10640(_x_x2131, _ctx); /*string*/
  return kk_string_box(_x_x2130);
}

kk_string_t kk_std_time_format__mlift_plocale_10641(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse string */ 
  kk_std_core_hnd__ev ev_10783 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10781;
  kk_box_t _x_x2126;
  {
    struct kk_std_core_hnd_Ev* _con_x2127 = kk_std_core_hnd__as_Ev(ev_10783, _ctx);
    kk_box_t _box_x416 = _con_x2127->hnd;
    int32_t m = _con_x2127->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x416, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1422;
    kk_std_core_hnd__clause0 _brw_x1423 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1422 = _brw_x1423; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x419 = _match_x1422.clause;
      _x_x2126 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x419, (_fun_unbox_x419, m, ev_10783, _ctx), _ctx); /*10005*/
    }
  }
  x_10781 = kk_bool_unbox(_x_x2126); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2128 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10641_fun2129(_ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2128);
  }
  {
    return kk_std_time_format__mlift_plocale_10640(x_10781, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10643_fun2135__t {
  struct kk_function_s _base;
  kk_string_t _c_x10588;
};
static kk_string_t kk_std_time_format__mlift_plocale_10643_fun2135(kk_function_t _fself, kk_char_t wild___0_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10643_fun2135(kk_string_t _c_x10588, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10643_fun2135__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_10643_fun2135__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_10643_fun2135, kk_context());
  _self->_c_x10588 = _c_x10588;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_time_format__mlift_plocale_10643_fun2135(kk_function_t _fself, kk_char_t wild___0_0, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10643_fun2135__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_10643_fun2135__t*, _fself, _ctx);
  kk_string_t _c_x10588 = _self->_c_x10588; /* string */
  kk_drop_match(_self, {kk_string_dup(_c_x10588, _ctx);}, {}, _ctx)
  kk_string_t _x_x2136 = kk_std_core_string_char_fs_string('"', _ctx); /*string*/
  kk_string_t _x_x2137;
  kk_string_t _x_x2138 = kk_std_core_string_char_fs_string('"', _ctx); /*string*/
  _x_x2137 = kk_std_core_types__lp__plus__plus__rp_(_c_x10588, _x_x2138, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x2136, _x_x2137, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10643_fun2140__t {
  struct kk_function_s _base;
  kk_function_t next_10786;
};
static kk_box_t kk_std_time_format__mlift_plocale_10643_fun2140(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10643_fun2140(kk_function_t next_10786, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10643_fun2140__t* _self = kk_function_alloc_as(struct kk_std_time_format__mlift_plocale_10643_fun2140__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format__mlift_plocale_10643_fun2140, kk_context());
  _self->next_10786 = next_10786;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10643_fun2140(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx) {
  struct kk_std_time_format__mlift_plocale_10643_fun2140__t* _self = kk_function_as(struct kk_std_time_format__mlift_plocale_10643_fun2140__t*, _fself, _ctx);
  kk_function_t next_10786 = _self->next_10786; /* (char) -> std/text/parse/parse string */
  kk_drop_match(_self, {kk_function_dup(next_10786, _ctx);}, {}, _ctx)
  kk_string_t _x_x2141;
  kk_char_t _x_x2142 = kk_char_unbox(_b_x426, KK_OWNED, _ctx); /*char*/
  _x_x2141 = kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10786, (next_10786, _x_x2142, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x2141);
}

kk_string_t kk_std_time_format__mlift_plocale_10643(kk_string_t _c_x10588, kk_context_t* _ctx) { /* (string) -> string */ 
  kk_char_t x_10785 = kk_std_text_parse_char('"', _ctx); /*char*/;
  kk_function_t next_10786 = kk_std_time_format__new_mlift_plocale_10643_fun2135(_c_x10588, _ctx); /*(char) -> std/text/parse/parse string*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2139 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10643_fun2140(next_10786, _ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2139);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_char_t, kk_context_t*), next_10786, (next_10786, x_10785, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10644_fun2145__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2145(kk_function_t _fself, kk_box_t _b_x441, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10644_fun2145(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10644_fun2145, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2145(kk_function_t _fself, kk_box_t _b_x441, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2146;
  kk_std_core_types__tuple2 _match_x1418;
  kk_std_core_sslice__sslice _x_x2147 = kk_std_core_sslice__sslice_unbox(_b_x441, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1418 = kk_std_time_format__lift_plocale_10529(_x_x2147, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x442 = _match_x1418.fst;
    kk_box_t _box_x443 = _match_x1418.snd;
    kk_std_core_types__list _uniq_pat_0_0_10422 = kk_std_core_types__list_unbox(_box_x442, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _uniq_pat_1_0_10423 = kk_std_core_sslice__sslice_unbox(_box_x443, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_uniq_pat_0_0_10422, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1418, _ctx);
      _x_x2146 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2148;
    }
  }
  {
    kk_box_t _box_x444 = _match_x1418.fst;
    kk_box_t _box_x445 = _match_x1418.snd;
    kk_std_core_sslice__sslice _uniq_rest_10429 = kk_std_core_sslice__sslice_unbox(_box_x445, KK_BORROWED, _ctx);
    kk_std_core_types__list _uniq_xs_10428 = kk_std_core_types__list_unbox(_box_x444, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10429, _ctx);
    kk_std_core_types__list_dup(_uniq_xs_10428, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1418, _ctx);
    kk_box_t _x_x2149;
    kk_std_core_types__tuple2 _x_x2150 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_uniq_xs_10428, _ctx), kk_std_core_sslice__sslice_box(_uniq_rest_10429, _ctx), _ctx); /*(10037, 10038)*/
    _x_x2149 = kk_std_core_types__tuple2_box(_x_x2150, _ctx); /*10024*/
    _x_x2146 = kk_std_core_types__new_Just(_x_x2149, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2148: ;
  return kk_std_core_types__maybe_box(_x_x2146, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10644_fun2152__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2152(kk_function_t _fself, kk_box_t _b_x454, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10644_fun2152(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10644_fun2152, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2152(kk_function_t _fself, kk_box_t _b_x454, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x2153;
  kk_string_t _x_x2154 = kk_string_empty(); /*string*/
  kk_std_core_types__maybe _x_x2156 = kk_std_core_types__maybe_unbox(_b_x454, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2153 = kk_std_time_format__mlift_lift_plocale_10528_10637(_x_x2154, _x_x2156, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x2153, _ctx);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10644_fun2163__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2163(kk_function_t _fself, kk_box_t _b_x467, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10644_fun2163(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10644_fun2163, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2163(kk_function_t _fself, kk_box_t _b_x467, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2164;
  kk_std_core_types__list _x_x2165 = kk_std_core_types__list_unbox(_b_x467, KK_OWNED, _ctx); /*list<char>*/
  _x_x2164 = kk_std_core_string_listchar_fs_string(_x_x2165, _ctx); /*string*/
  return kk_string_box(_x_x2164);
}


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10644_fun2168__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2168(kk_function_t _fself, kk_box_t _b_x470, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10644_fun2168(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10644_fun2168, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10644_fun2168(kk_function_t _fself, kk_box_t _b_x470, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2169;
  kk_string_t _x_x2170 = kk_string_unbox(_b_x470); /*string*/
  _x_x2169 = kk_std_time_format__mlift_plocale_10643(_x_x2170, _ctx); /*string*/
  return kk_string_box(_x_x2169);
}

kk_string_t kk_std_time_format__mlift_plocale_10644(bool _y_x10586, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse string */ 
  kk_string_t x_10789;
  if (_y_x10586) {
    kk_std_core_hnd__ev ev_0_10767 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_10764;
    kk_box_t _x_x2143;
    {
      struct kk_std_core_hnd_Ev* _con_x2144 = kk_std_core_hnd__as_Ev(ev_0_10767, _ctx);
      kk_box_t _box_x428 = _con_x2144->hnd;
      int32_t m_0 = _con_x2144->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x428, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      kk_std_core_hnd__clause1 _match_x1417;
      kk_std_core_hnd__clause1 _brw_x1419 = kk_std_text_parse_satisfy_fs__select(h_0, _ctx); /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
      _match_x1417 = _brw_x1419; /*hnd/clause1<(sslice/sslice) -> maybe<(10000, sslice/sslice)>,maybe<10000>,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x435 = _match_x1417.clause;
        _x_x2143 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x435, (_fun_unbox_x435, m_0, ev_0_10767, kk_function_box(kk_std_time_format__new_mlift_plocale_10644_fun2145(_ctx), _ctx), _ctx), _ctx); /*10010*/
      }
    }
    x_0_10764 = kk_std_core_types__maybe_unbox(_x_x2143, KK_OWNED, _ctx); /*maybe<list<char>>*/
    kk_std_core_types__list x_0_10791;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10764, _ctx);
      kk_box_t _x_x2151 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10644_fun2152(_ctx), _ctx); /*10001*/
      x_0_10791 = kk_std_core_types__list_unbox(_x_x2151, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      if (kk_std_core_types__is_Nothing(x_0_10764, _ctx)) {
        kk_std_core_hnd__ev ev_1_10770 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_box_t _x_x2157;
        {
          struct kk_std_core_hnd_Ev* _con_x2158 = kk_std_core_hnd__as_Ev(ev_1_10770, _ctx);
          kk_box_t _box_x455 = _con_x2158->hnd;
          int32_t m_1 = _con_x2158->marker;
          kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x455, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_1, _ctx);
          kk_std_core_hnd__clause1 _match_x1415;
          kk_std_core_hnd__clause1 _brw_x1416 = kk_std_text_parse_fail_fs__select(h_1, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
          kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
          _match_x1415 = _brw_x1416; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
          {
            kk_function_t _fun_unbox_x459 = _match_x1415.clause;
            kk_box_t _x_x2159;
            kk_string_t _x_x2160 = kk_string_empty(); /*string*/
            _x_x2159 = kk_string_box(_x_x2160); /*10009*/
            _x_x2157 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x459, (_fun_unbox_x459, m_1, ev_1_10770, _x_x2159, _ctx), _ctx); /*10010*/
          }
        }
        x_0_10791 = kk_std_core_types__list_unbox(_x_x2157, KK_OWNED, _ctx); /*list<char>*/
      }
      else {
        kk_box_t _box_x463 = x_0_10764._cons.Just.value;
        kk_std_core_types__list _uniq_x_10435_0 = kk_std_core_types__list_unbox(_box_x463, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(_uniq_x_10435_0, _ctx);
        kk_std_core_types__maybe_drop(x_0_10764, _ctx);
        x_0_10791 = _uniq_x_10435_0; /*list<char>*/
      }
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_10791, _ctx);
      kk_box_t _x_x2162 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10644_fun2163(_ctx), _ctx); /*10001*/
      x_10789 = kk_string_unbox(_x_x2162); /*string*/
    }
    else {
      x_10789 = kk_std_core_string_listchar_fs_string(x_0_10791, _ctx); /*string*/
    }
  }
  else {
    x_10789 = kk_string_empty(); /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10789, _ctx);
    kk_box_t _x_x2167 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10644_fun2168(_ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2167);
  }
  {
    return kk_std_time_format__mlift_plocale_10643(x_10789, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_format__mlift_plocale_10645_fun2174__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format__mlift_plocale_10645_fun2174(kk_function_t _fself, kk_box_t _b_x479, kk_context_t* _ctx);
static kk_function_t kk_std_time_format__new_mlift_plocale_10645_fun2174(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format__mlift_plocale_10645_fun2174, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format__mlift_plocale_10645_fun2174(kk_function_t _fself, kk_box_t _b_x479, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2175;
  bool _x_x2176 = kk_bool_unbox(_b_x479); /*bool*/
  _x_x2175 = kk_std_time_format__mlift_plocale_10644(_x_x2176, _ctx); /*string*/
  return kk_string_box(_x_x2175);
}

kk_string_t kk_std_time_format__mlift_plocale_10645(kk_char_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : char) -> std/text/parse/parse string */ 
  kk_std_core_hnd__ev ev_10795 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10793;
  kk_box_t _x_x2171;
  {
    struct kk_std_core_hnd_Ev* _con_x2172 = kk_std_core_hnd__as_Ev(ev_10795, _ctx);
    kk_box_t _box_x472 = _con_x2172->hnd;
    int32_t m = _con_x2172->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x472, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x1410;
    kk_std_core_hnd__clause0 _brw_x1411 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x1410 = _brw_x1411; /*hnd/clause0<bool,std/text/parse/parse,10000,10001>*/
    {
      kk_function_t _fun_unbox_x475 = _match_x1410.clause;
      _x_x2171 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x475, (_fun_unbox_x475, m, ev_10795, _ctx), _ctx); /*10005*/
    }
  }
  x_10793 = kk_bool_unbox(_x_x2171); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2173 = kk_std_core_hnd_yield_extend(kk_std_time_format__new_mlift_plocale_10645_fun2174(_ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2173);
  }
  {
    return kk_std_time_format__mlift_plocale_10644(x_10793, _ctx);
  }
}


// lift anonymous function
struct kk_std_time_format_plocale_fun2177__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun2177(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2177(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun2177, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun2177(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2178;
  kk_string_t _x_x2179;
  kk_define_string_literal(, _s_x2180, 5, "\'\"tLl", _ctx)
  _x_x2179 = kk_string_dup(_s_x2180, _ctx); /*string*/
  _x_x2178 = kk_std_text_parse_none_of_many1(_x_x2179, _ctx); /*string*/
  return kk_string_box(_x_x2178);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun2182__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun2182(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2182(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun2182, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_plocale_fun2185__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun2185(kk_function_t _fself, kk_box_t _b_x482, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2185(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun2185, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun2185(kk_function_t _fself, kk_box_t _b_x482, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2186;
  kk_char_t _x_x2187 = kk_char_unbox(_b_x482, KK_OWNED, _ctx); /*char*/
  _x_x2186 = kk_std_time_format__mlift_plocale_10641(_x_x2187, _ctx); /*string*/
  return kk_string_box(_x_x2186);
}
static kk_box_t kk_std_time_format_plocale_fun2182(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_10797 = kk_std_text_parse_char('\'', _ctx); /*char*/;
  kk_string_t _x_x2183;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2184 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_fun2185(_ctx), _ctx); /*10001*/
    _x_x2183 = kk_string_unbox(_x_x2184); /*string*/
  }
  else {
    _x_x2183 = kk_std_time_format__mlift_plocale_10641(x_10797, _ctx); /*string*/
  }
  return kk_string_box(_x_x2183);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun2189__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun2189(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2189(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun2189, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_plocale_fun2192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocale_fun2192(kk_function_t _fself, kk_box_t _b_x484, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocale_fun2192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun2192(kk_function_t _fself, kk_box_t _b_x484, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2193;
  kk_char_t _x_x2194 = kk_char_unbox(_b_x484, KK_OWNED, _ctx); /*char*/
  _x_x2193 = kk_std_time_format__mlift_plocale_10645(_x_x2194, _ctx); /*string*/
  return kk_string_box(_x_x2193);
}
static kk_box_t kk_std_time_format_plocale_fun2189(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t x_0_10799 = kk_std_text_parse_char('"', _ctx); /*char*/;
  kk_string_t _x_x2190;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2191 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocale_fun2192(_ctx), _ctx); /*10001*/
    _x_x2190 = kk_string_unbox(_x_x2191); /*string*/
  }
  else {
    _x_x2190 = kk_std_time_format__mlift_plocale_10645(x_0_10799, _ctx); /*string*/
  }
  return kk_string_box(_x_x2190);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun2198__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_fun2198(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2198(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun2198__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_fun2198__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_fun2198, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun2198(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun2198__t* _self = kk_function_as(struct kk_std_time_format_plocale_fun2198__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2199 = kk_std_time_format_plocale_t(locale, _ctx); /*string*/
  return kk_string_box(_x_x2199);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun2203__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_fun2203(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2203(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun2203__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_fun2203__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_fun2203, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun2203(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun2203__t* _self = kk_function_as(struct kk_std_time_format_plocale_fun2203__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2204 = kk_std_time_format_plocale_l(locale, 'L', _ctx); /*string*/
  return kk_string_box(_x_x2204);
}


// lift anonymous function
struct kk_std_time_format_plocale_fun2206__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocale_fun2206(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocale_fun2206(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun2206__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocale_fun2206__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocale_fun2206, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocale_fun2206(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocale_fun2206__t* _self = kk_function_as(struct kk_std_time_format_plocale_fun2206__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2207 = kk_std_time_format_plocale_l(locale, 'l', _ctx); /*string*/
  return kk_string_box(_x_x2207);
}

kk_string_t kk_std_time_format_plocale(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
  kk_std_core_types__list ps_10026;
  kk_std_core_types__list _x_x2181;
  kk_std_core_types__list _x_x2188;
  kk_std_core_types__list _x_x2195;
  kk_box_t _x_x2196;
  kk_function_t _x_x2197;
  kk_std_time_locale__time_locale_dup(locale, _ctx);
  _x_x2197 = kk_std_time_format_new_plocale_fun2198(locale, _ctx); /*() -> std/text/parse/parse 493*/
  _x_x2196 = kk_function_box(_x_x2197, _ctx); /*10021*/
  kk_std_core_types__list _x_x2200;
  kk_box_t _x_x2201;
  kk_function_t _x_x2202;
  kk_std_time_locale__time_locale_dup(locale, _ctx);
  _x_x2202 = kk_std_time_format_new_plocale_fun2203(locale, _ctx); /*() -> std/text/parse/parse 490*/
  _x_x2201 = kk_function_box(_x_x2202, _ctx); /*10021*/
  kk_std_core_types__list _x_x2205 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun2206(locale, _ctx), _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x2200 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2201, _x_x2205, _ctx); /*list<10021>*/
  _x_x2195 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2196, _x_x2200, _ctx); /*list<10021>*/
  _x_x2188 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun2189(_ctx), _ctx), _x_x2195, _ctx); /*list<10021>*/
  _x_x2181 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun2182(_ctx), _ctx), _x_x2188, _ctx); /*list<10021>*/
  ps_10026 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_std_time_format_new_plocale_fun2177(_ctx), _ctx), _x_x2181, _ctx); /*list<std/text/parse/parser<total,string>>*/
  if (kk_std_core_types__is_Nil(ps_10026, _ctx)) {
    kk_std_core_hnd__ev ev_10801 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2208;
    {
      struct kk_std_core_hnd_Ev* _con_x2209 = kk_std_core_hnd__as_Ev(ev_10801, _ctx);
      kk_box_t _box_x517 = _con_x2209->hnd;
      int32_t m = _con_x2209->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x517, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1405;
      kk_std_core_hnd__clause1 _brw_x1406 = kk_std_text_parse_fail_fs__select(h, _ctx); /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
      _match_x1405 = _brw_x1406; /*hnd/clause1<string,10000,std/text/parse/parse,10001,10002>*/
      {
        kk_function_t _fun_unbox_x521 = _match_x1405.clause;
        kk_box_t _x_x2210;
        kk_string_t _x_x2211;
        kk_define_string_literal(, _s_x2212, 23, "no further alternatives", _ctx)
        _x_x2211 = kk_string_dup(_s_x2212, _ctx); /*string*/
        _x_x2210 = kk_string_box(_x_x2211); /*10009*/
        _x_x2208 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x521, (_fun_unbox_x521, m, ev_10801, _x_x2210, _ctx), _ctx); /*10010*/
      }
    }
    return kk_string_unbox(_x_x2208);
  }
  {
    kk_box_t _x_x2213 = kk_std_text_parse__unroll_choose_10000(ps_10026, _ctx); /*10000*/
    return kk_string_unbox(_x_x2213);
  }
}
 
// monadic lift

kk_string_t kk_std_time_format__mlift_plocales_10646(kk_std_core_types__list _y_x10597, kk_context_t* _ctx) { /* (list<string>) -> std/text/parse/parse string */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_string_t x;
  if (kk_std_core_types__is_Nil(_y_x10597, _ctx)) {
    x = kk_string_empty(); /*string*/
    goto _match_x2214;
  }
  {
    struct kk_std_core_types_Cons* _con_x2216 = kk_std_core_types__as_Cons(_y_x10597, _ctx);
    kk_box_t _box_x527 = _con_x2216->head;
    kk_std_core_types__list _pat_1 = _con_x2216->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x527);
      if kk_likely(kk_datatype_ptr_is_unique(_y_x10597, _ctx)) {
        kk_datatype_ptr_free(_y_x10597, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_datatype_ptr_decref(_y_x10597, _ctx);
      }
      x = x_0; /*string*/
      goto _match_x2214;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2217 = kk_std_core_types__as_Cons(_y_x10597, _ctx);
    kk_box_t _box_x528 = _con_x2217->head;
    kk_std_core_types__list _pat_3 = _con_x2217->tail;
    struct kk_std_core_types_Cons* _con_x2218 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x529 = _con_x2218->head;
    kk_std_core_types__list _pat_4 = _con_x2218->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0_0 = kk_string_unbox(_box_x528);
      kk_string_t y = kk_string_unbox(_box_x529);
      if kk_likely(kk_datatype_ptr_is_unique(_y_x10597, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(_y_x10597, _ctx);
      }
      else {
        kk_string_dup(x_0_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(_y_x10597, _ctx);
      }
      x = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
      goto _match_x2214;
    }
  }
  {
    kk_vector_t _x_x2219 = kk_std_core_vector_unvlist(_y_x10597, _ctx); /*vector<10000>*/
    x = kk_string_join(_x_x2219,kk_context()); /*string*/
  }
  _match_x2214: ;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}


// lift anonymous function
struct kk_std_time_format_plocales_fun2220__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_plocales_fun2220(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocales_fun2220(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_plocales_fun2220__t* _self = kk_function_alloc_as(struct kk_std_time_format_plocales_fun2220__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_plocales_fun2220, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_plocales_fun2220(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_plocales_fun2220__t* _self = kk_function_as(struct kk_std_time_format_plocales_fun2220__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2221 = kk_std_time_format_plocale(locale, _ctx); /*string*/
  return kk_string_box(_x_x2221);
}


// lift anonymous function
struct kk_std_time_format_plocales_fun2223__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_plocales_fun2223(kk_function_t _fself, kk_box_t _b_x535, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_plocales_fun2223(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_plocales_fun2223, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_plocales_fun2223(kk_function_t _fself, kk_box_t _b_x535, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2224;
  kk_std_core_types__list _x_x2225 = kk_std_core_types__list_unbox(_b_x535, KK_OWNED, _ctx); /*list<string>*/
  _x_x2224 = kk_std_time_format__mlift_plocales_10646(_x_x2225, _ctx); /*string*/
  return kk_string_box(_x_x2224);
}

kk_string_t kk_std_time_format_plocales(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (locale : std/time/locale/time-locale) -> std/text/parse/parse string */ 
  kk_std_core_types__list x_10806 = kk_std_text_parse_many_acc(kk_std_time_format_new_plocales_fun2220(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10806, _ctx);
    kk_box_t _x_x2222 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_plocales_fun2223(_ctx), _ctx); /*10001*/
    return kk_string_unbox(_x_x2222);
  }
  {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10806, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x2226;
    }
    {
      struct kk_std_core_types_Cons* _con_x2228 = kk_std_core_types__as_Cons(x_10806, _ctx);
      kk_box_t _box_x536 = _con_x2228->head;
      kk_std_core_types__list _pat_1_0 = _con_x2228->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x536);
        if kk_likely(kk_datatype_ptr_is_unique(x_10806, _ctx)) {
          kk_datatype_ptr_free(x_10806, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10806, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x2226;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2229 = kk_std_core_types__as_Cons(x_10806, _ctx);
      kk_box_t _box_x537 = _con_x2229->head;
      kk_std_core_types__list _pat_3 = _con_x2229->tail;
      struct kk_std_core_types_Cons* _con_x2230 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x538 = _con_x2230->head;
      kk_std_core_types__list _pat_4 = _con_x2230->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x537);
        kk_string_t y = kk_string_unbox(_box_x538);
        if kk_likely(kk_datatype_ptr_is_unique(x_10806, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10806, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10806, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x2226;
      }
    }
    {
      kk_vector_t _x_x2231 = kk_std_core_vector_unvlist(x_10806, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x2231,kk_context()); /*string*/
    }
    _match_x2226: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x_0;
  }
}


// lift anonymous function
struct kk_std_time_format_expand_locales_fun2235__t {
  struct kk_function_s _base;
  kk_std_time_locale__time_locale locale;
};
static kk_box_t kk_std_time_format_expand_locales_fun2235(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_expand_locales_fun2235(kk_std_time_locale__time_locale locale, kk_context_t* _ctx) {
  struct kk_std_time_format_expand_locales_fun2235__t* _self = kk_function_alloc_as(struct kk_std_time_format_expand_locales_fun2235__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_expand_locales_fun2235, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_expand_locales_fun2235(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_expand_locales_fun2235__t* _self = kk_function_as(struct kk_std_time_format_expand_locales_fun2235__t*, _fself, _ctx);
  kk_std_time_locale__time_locale locale = _self->locale; /* std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_time_locale__time_locale_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2236 = kk_std_time_format_plocales(locale, _ctx); /*string*/
  return kk_string_box(_x_x2236);
}

kk_string_t kk_std_time_format_expand_locales(kk_string_t fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (fmt : string, locale : std/time/locale/time-locale) -> string */ 
  kk_std_core_sslice__sslice _b_x540_542;
  kk_string_t _x_x2232 = kk_string_dup(fmt, _ctx); /*string*/
  kk_integer_t _x_x2233;
  kk_string_t _x_x2234 = kk_string_dup(fmt, _ctx); /*string*/
  _x_x2233 = kk_string_len_int(_x_x2234,kk_context()); /*int*/
  _b_x540_542 = kk_std_core_sslice__new_Sslice(_x_x2232, kk_integer_from_small(0), _x_x2233, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036 = kk_std_text_parse_parse_eof(_b_x540_542, kk_std_time_format_new_expand_locales_fun2235(locale, _ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2237 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x544 = _con_x2237->result;
    kk_std_core_sslice__sslice _pat_0_0 = _con_x2237->rest;
    kk_string_t x_0 = kk_string_unbox(_box_x544);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(perr_10036, _ctx);
    }
    else {
      kk_string_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr_10036, _ctx);
    }
    kk_string_drop(fmt, _ctx);
    return x_0;
  }
  {
    struct kk_std_text_parse_ParseError* _con_x2238 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2238->rest;
    kk_string_t msg = _con_x2238->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr_10036, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10036, _ctx);
    }
    return fmt;
  }
}

kk_string_t kk_std_time_format_showl(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx) { /* (i : int, width : ? int) -> string */ 
  kk_string_t s_10038 = kk_std_core_int_show(i, _ctx); /*string*/;
  kk_integer_t n;
  kk_string_t _x_x2239 = kk_string_dup(s_10038, _ctx); /*string*/
  n = kk_std_core_string_chars_fs_count(_x_x2239, _ctx); /*int*/
  bool _match_x1401;
  kk_integer_t _brw_x1402;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x546 = width._cons._Optional.value;
    kk_integer_t _uniq_width_1750 = kk_integer_unbox(_box_x546, _ctx);
    kk_integer_dup(_uniq_width_1750, _ctx);
    _brw_x1402 = _uniq_width_1750; /*int*/
  }
  else {
    _brw_x1402 = kk_integer_from_small(2); /*int*/
  }
  bool _brw_x1403 = kk_integer_lte_borrow(_brw_x1402,n,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1402, _ctx);
  _match_x1401 = _brw_x1403; /*bool*/
  if (_match_x1401) {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_integer_drop(n, _ctx);
    return s_10038;
  }
  {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012;
    kk_integer_t _x_x2240;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x547 = width._cons._Optional.value;
      kk_integer_t _uniq_width_1750_0 = kk_integer_unbox(_box_x547, _ctx);
      kk_integer_dup(_uniq_width_1750_0, _ctx);
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x2240 = _uniq_width_1750_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x2240 = kk_integer_from_small(2); /*int*/
    }
    n_0_10012 = kk_integer_sub(_x_x2240,n,kk_context()); /*int*/
    kk_string_t _x_x2241 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x2241, s_10038, _ctx);
  }
}

kk_string_t kk_std_time_format_format_day(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x1397 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
  if (_match_x1397) {
    kk_integer_drop(n, _ctx);
    kk_integer_t i_10041 = kk_std_time_time_day_of_year(t, _ctx); /*int*/;
    kk_string_t s_10043 = kk_std_core_int_show(i_10041, _ctx); /*string*/;
    kk_integer_t n_0;
    kk_string_t _x_x2242 = kk_string_dup(s_10043, _ctx); /*string*/
    n_0 = kk_std_core_string_chars_fs_count(_x_x2242, _ctx); /*int*/
    bool _match_x1400 = kk_integer_lte_borrow((kk_integer_from_small(3)),n_0,kk_context()); /*bool*/;
    if (_match_x1400) {
      kk_integer_drop(n_0, _ctx);
      return s_10043;
    }
    {
      kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012 = kk_integer_sub((kk_integer_from_small(3)),n_0,kk_context()); /*int*/;
      kk_string_t _x_x2243 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x2243, s_10043, _ctx);
    }
  }
  {
    bool _match_x1398;
    kk_string_t _x_x2244;
    {
      struct kk_std_time_time_Time* _con_x2245 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_4 = _con_x2245->date;
      kk_std_time_date__clock _pat_4_1 = _con_x2245->clock;
      kk_std_time_calendar__calendar _x_0 = _con_x2245->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x2245->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x2245->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x2245->instant;
      struct kk_std_time_date_Clock* _con_x2246 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2247 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2248 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_calendar__calendar_dup(_x_0, _ctx);
      {
        struct kk_std_time_calendar_Calendar* _con_x2249 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
        kk_string_t _pat_0_3 = _con_x2249->name;
        kk_string_t _pat_1_0 = _con_x2249->long_name;
        kk_string_t _x = _con_x2249->month_prefix;
        kk_function_t _pat_2_0 = _con_x2249->show_era;
        kk_function_t _pat_3_0 = _con_x2249->instant_to_dc;
        kk_function_t _pat_4_0 = _con_x2249->dc_to_instant;
        kk_function_t _pat_5 = _con_x2249->days_to_date;
        kk_function_t _pat_6 = _con_x2249->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
          kk_function_drop(_pat_6, _ctx);
          kk_function_drop(_pat_5, _ctx);
          kk_function_drop(_pat_4_0, _ctx);
          kk_function_drop(_pat_3_0, _ctx);
          kk_function_drop(_pat_2_0, _ctx);
          kk_string_drop(_pat_1_0, _ctx);
          kk_string_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(_x_0, _ctx);
        }
        else {
          kk_string_dup(_x, _ctx);
          kk_datatype_ptr_decref(_x_0, _ctx);
        }
        _x_x2244 = _x; /*string*/
      }
    }
    kk_string_t _x_x2250;
    kk_define_string_literal(, _s_x2251, 1, "W", _ctx)
    _x_x2250 = kk_string_dup(_s_x2251, _ctx); /*string*/
    _match_x1398 = kk_string_is_eq(_x_x2244,_x_x2250,kk_context()); /*bool*/
    if (_match_x1398) {
      kk_integer_drop(n, _ctx);
      kk_integer_t _x_x2252;
      {
        struct kk_std_time_time_Time* _con_x2253 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_0 = _con_x2253->date;
        kk_std_time_date__clock _pat_3_2 = _con_x2253->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2253->calendar;
        kk_std_time_duration__duration _pat_16_0 = _con_x2253->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0 = _con_x2253->timezone;
        kk_std_time_instant__instant _pat_23_0 = _con_x2253->instant;
        struct kk_std_time_date_Clock* _con_x2254 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2255 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2256 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
        kk_string_t _pat_18_0 = _con_x2253->tzabbrv;
        kk_integer_t _pat_4_2 = _con_x2254->hours;
        kk_integer_t _pat_5_1 = _con_x2254->minutes;
        kk_string_t _pat_8_0 = _con_x2255->name;
        kk_string_t _pat_9_0 = _con_x2255->long_name;
        kk_string_t _pat_10_0 = _con_x2255->month_prefix;
        kk_function_t _pat_11_0 = _con_x2255->show_era;
        kk_function_t _pat_12_0 = _con_x2255->instant_to_dc;
        kk_function_t _pat_13_0 = _con_x2255->dc_to_instant;
        kk_function_t _pat_14_0 = _con_x2255->days_to_date;
        kk_function_t _pat_15_0 = _con_x2255->date_to_days;
        kk_string_t _pat_20_0 = _con_x2256->name;
        kk_function_t _pat_21_0 = _con_x2256->utc_delta;
        kk_function_t _pat_22_0 = _con_x2256->utc_inverse;
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
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_2, _ctx)) {
            kk_integer_drop(_pat_5_1, _ctx);
            kk_integer_drop(_pat_4_2, _ctx);
            kk_datatype_ptr_free(_pat_3_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_2, _ctx);
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
          _x_x2252 = _x_1; /*int*/
        }
      }
      return kk_std_core_int_show(_x_x2252, _ctx);
    }
    {
      kk_string_t s_0_10052;
      kk_integer_t _x_x2257;
      {
        struct kk_std_time_time_Time* _con_x2258 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_1 = _con_x2258->date;
        kk_std_time_date__clock _pat_3_3 = _con_x2258->clock;
        kk_std_time_calendar__calendar _pat_7_2 = _con_x2258->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x2258->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x2258->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x2258->instant;
        struct kk_std_time_date_Clock* _con_x2259 = kk_std_time_date__as_Clock(_pat_3_3, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2260 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2261 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_string_t _pat_18_1 = _con_x2258->tzabbrv;
        kk_integer_t _pat_4_3 = _con_x2259->hours;
        kk_integer_t _pat_5_2 = _con_x2259->minutes;
        kk_string_t _pat_8_1 = _con_x2260->name;
        kk_string_t _pat_9_1 = _con_x2260->long_name;
        kk_string_t _pat_10_1 = _con_x2260->month_prefix;
        kk_function_t _pat_11_1 = _con_x2260->show_era;
        kk_function_t _pat_12_1 = _con_x2260->instant_to_dc;
        kk_function_t _pat_13_1 = _con_x2260->dc_to_instant;
        kk_function_t _pat_14_1 = _con_x2260->days_to_date;
        kk_function_t _pat_15_1 = _con_x2260->date_to_days;
        kk_string_t _pat_20_1 = _con_x2261->name;
        kk_function_t _pat_21_1 = _con_x2261->utc_delta;
        kk_function_t _pat_22_1 = _con_x2261->utc_inverse;
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
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_3, _ctx)) {
            kk_integer_drop(_pat_5_2, _ctx);
            kk_integer_drop(_pat_4_3, _ctx);
            kk_datatype_ptr_free(_pat_3_3, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_3, _ctx);
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
          _x_x2257 = _x_2; /*int*/
        }
      }
      s_0_10052 = kk_std_core_int_show(_x_x2257, _ctx); /*string*/
      kk_integer_t n_1;
      kk_string_t _x_x2262 = kk_string_dup(s_0_10052, _ctx); /*string*/
      n_1 = kk_std_core_string_chars_fs_count(_x_x2262, _ctx); /*int*/
      bool _match_x1399 = kk_integer_lte_borrow(n,n_1,kk_context()); /*bool*/;
      if (_match_x1399) {
        kk_integer_drop(n_1, _ctx);
        kk_integer_drop(n, _ctx);
        return s_0_10052;
      }
      {
        kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10012_0 = kk_integer_sub(n,n_1,kk_context()); /*int*/;
        kk_string_t _x_x2263 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x2263, s_0_10052, _ctx);
      }
    }
  }
}

kk_string_t kk_std_time_format_format_month(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  bool _match_x1392 = kk_integer_lte_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  if (_match_x1392) {
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    kk_string_t s_10060;
    kk_integer_t _x_x2264;
    {
      struct kk_std_time_time_Time* _con_x2265 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_0 = _con_x2265->date;
      kk_std_time_date__clock _pat_3_1 = _con_x2265->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x2265->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2265->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2265->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2265->instant;
      struct kk_std_time_date_Clock* _con_x2266 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2267 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2268 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__date_dup(_x_0_0, _ctx);
      {
        kk_integer_t _x_1 = _x_0_0.month;
        kk_integer_dup(_x_1, _ctx);
        kk_std_time_date__date_drop(_x_0_0, _ctx);
        _x_x2264 = _x_1; /*int*/
      }
    }
    s_10060 = kk_std_core_int_show(_x_x2264, _ctx); /*string*/
    kk_integer_t n_0;
    kk_string_t _x_x2269 = kk_string_dup(s_10060, _ctx); /*string*/
    n_0 = kk_std_core_string_chars_fs_count(_x_x2269, _ctx); /*int*/
    kk_string_t _x_x2270;
    {
      struct kk_std_time_time_Time* _con_x2271 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_1 = _con_x2271->date;
      kk_std_time_date__clock _pat_4_0 = _con_x2271->clock;
      kk_std_time_calendar__calendar _x_0 = _con_x2271->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x2271->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x2271->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x2271->instant;
      struct kk_std_time_date_Clock* _con_x2272 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2273 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2274 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_string_t _pat_18 = _con_x2271->tzabbrv;
      kk_integer_t _pat_5_0 = _con_x2272->hours;
      kk_integer_t _pat_6_0 = _con_x2272->minutes;
      kk_string_t _pat_20 = _con_x2274->name;
      kk_function_t _pat_21 = _con_x2274->utc_delta;
      kk_function_t _pat_22 = _con_x2274->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
          kk_integer_drop(_pat_6_0, _ctx);
          kk_integer_drop(_pat_5_0, _ctx);
          kk_datatype_ptr_free(_pat_4_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_0, _ctx);
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
        kk_std_time_date__date_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_calendar__calendar_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        struct kk_std_time_calendar_Calendar* _con_x2275 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
        kk_string_t _pat_0_0 = _con_x2275->name;
        kk_string_t _pat_1 = _con_x2275->long_name;
        kk_string_t _x = _con_x2275->month_prefix;
        kk_function_t _pat_2 = _con_x2275->show_era;
        kk_function_t _pat_3 = _con_x2275->instant_to_dc;
        kk_function_t _pat_4 = _con_x2275->dc_to_instant;
        kk_function_t _pat_5 = _con_x2275->days_to_date;
        kk_function_t _pat_6 = _con_x2275->date_to_days;
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
        _x_x2270 = _x; /*string*/
      }
    }
    kk_string_t _x_x2276;
    bool _match_x1396 = kk_integer_lte_borrow(n,n_0,kk_context()); /*bool*/;
    if (_match_x1396) {
      kk_integer_drop(n_0, _ctx);
      kk_integer_drop(n, _ctx);
      _x_x2276 = s_10060; /*string*/
    }
    else {
      kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012 = kk_integer_sub(n,n_0,kk_context()); /*int*/;
      kk_string_t _x_x2277 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
      _x_x2276 = kk_std_core_types__lp__plus__plus__rp_(_x_x2277, s_10060, _ctx); /*string*/
    }
    return kk_std_core_types__lp__plus__plus__rp_(_x_x2270, _x_x2276, _ctx);
  }
  {
    kk_std_core_types__list months;
    bool _match_x1394;
    bool _brw_x1395 = kk_integer_eq_borrow(n,(kk_integer_from_small(3)),kk_context()); /*bool*/;
    kk_integer_drop(n, _ctx);
    _match_x1394 = _brw_x1395; /*bool*/
    if (_match_x1394) {
      struct kk_std_time_locale_Time_locale* _con_x2278 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _pat_0_6 = _con_x2278->lang_name;
      kk_std_core_types__list _pat_1_4 = _con_x2278->day_names;
      kk_std_core_types__list _pat_2_3 = _con_x2278->month_names;
      kk_std_core_types__list _x_2 = _con_x2278->month_names_short;
      kk_std_core_types__list _pat_3_2 = _con_x2278->day_names_short;
      kk_std_core_types__list _pat_4_2 = _con_x2278->day_names_min;
      kk_string_t _pat_5_2 = _con_x2278->format_t;
      kk_string_t _pat_6_2 = _con_x2278->format_tt;
      kk_string_t _pat_7_2 = _con_x2278->format_l;
      kk_string_t _pat_8_1 = _con_x2278->format_ll;
      kk_string_t _pat_9_1 = _con_x2278->format_lll;
      kk_string_t _pat_10_1 = _con_x2278->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
        kk_string_drop(_pat_9_1, _ctx);
        kk_string_drop(_pat_8_1, _ctx);
        kk_string_drop(_pat_7_2, _ctx);
        kk_string_drop(_pat_6_2, _ctx);
        kk_string_drop(_pat_5_2, _ctx);
        kk_std_core_types__list_drop(_pat_4_2, _ctx);
        kk_std_core_types__list_drop(_pat_3_2, _ctx);
        kk_std_core_types__list_drop(_pat_2_3, _ctx);
        kk_std_core_types__list_drop(_pat_1_4, _ctx);
        kk_string_drop(_pat_10_1, _ctx);
        kk_string_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(locale, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(locale, _ctx);
      }
      months = _x_2; /*list<string>*/
    }
    else {
      struct kk_std_time_locale_Time_locale* _con_x2279 = kk_std_time_locale__as_Time_locale(locale, _ctx);
      kk_string_t _pat_0_7 = _con_x2279->lang_name;
      kk_std_core_types__list _pat_1_5 = _con_x2279->day_names;
      kk_std_core_types__list _x_3 = _con_x2279->month_names;
      kk_std_core_types__list _pat_2_5 = _con_x2279->month_names_short;
      kk_std_core_types__list _pat_3_3 = _con_x2279->day_names_short;
      kk_std_core_types__list _pat_4_3 = _con_x2279->day_names_min;
      kk_string_t _pat_5_3 = _con_x2279->format_t;
      kk_string_t _pat_6_3 = _con_x2279->format_tt;
      kk_string_t _pat_7_3 = _con_x2279->format_l;
      kk_string_t _pat_8_2 = _con_x2279->format_ll;
      kk_string_t _pat_9_2 = _con_x2279->format_lll;
      kk_string_t _pat_10_2 = _con_x2279->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(locale, _ctx)) {
        kk_string_drop(_pat_9_2, _ctx);
        kk_string_drop(_pat_8_2, _ctx);
        kk_string_drop(_pat_7_3, _ctx);
        kk_string_drop(_pat_6_3, _ctx);
        kk_string_drop(_pat_5_3, _ctx);
        kk_std_core_types__list_drop(_pat_4_3, _ctx);
        kk_std_core_types__list_drop(_pat_3_3, _ctx);
        kk_std_core_types__list_drop(_pat_2_5, _ctx);
        kk_std_core_types__list_drop(_pat_1_5, _ctx);
        kk_string_drop(_pat_10_2, _ctx);
        kk_string_drop(_pat_0_7, _ctx);
        kk_datatype_ptr_free(locale, _ctx);
      }
      else {
        kk_std_core_types__list_dup(_x_3, _ctx);
        kk_datatype_ptr_decref(locale, _ctx);
      }
      months = _x_3; /*list<string>*/
    }
    kk_integer_t n_1_10068;
    kk_integer_t _x_x2280;
    {
      struct kk_std_time_time_Time* _con_x2281 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_1 = _con_x2281->date;
      kk_std_time_date__clock _pat_3_4 = _con_x2281->clock;
      kk_std_time_calendar__calendar _pat_7_4 = _con_x2281->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x2281->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x2281->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x2281->instant;
      struct kk_std_time_date_Clock* _con_x2282 = kk_std_time_date__as_Clock(_pat_3_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2283 = kk_std_time_calendar__as_Calendar(_pat_7_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2284 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_date__date_dup(_x_0_1, _ctx);
      {
        kk_integer_t _x_4 = _x_0_1.month;
        kk_integer_dup(_x_4, _ctx);
        kk_std_time_date__date_drop(_x_0_1, _ctx);
        _x_x2280 = _x_4; /*int*/
      }
    }
    n_1_10068 = kk_integer_add_small_const(_x_x2280, -1, _ctx); /*int*/
    kk_std_core_types__maybe m_10065;
    if (kk_std_core_types__is_Nil(months, _ctx)) {
      kk_integer_drop(n_1_10068, _ctx);
      m_10065 = kk_std_core_types__new_Nothing(_ctx); /*maybe<string>*/
    }
    else {
      m_10065 = kk_std_core_list__unroll_index_10029(months, n_1_10068, _ctx); /*maybe<string>*/
    }
    kk_string_t s_0_10075;
    kk_integer_t _x_x2285;
    {
      struct kk_std_time_time_Time* _con_x2286 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_2 = _con_x2286->date;
      kk_std_time_date__clock _pat_3_5 = _con_x2286->clock;
      kk_std_time_calendar__calendar _pat_7_5 = _con_x2286->calendar;
      kk_std_time_duration__duration _pat_16_2 = _con_x2286->tzdelta;
      kk_std_time_calendar__timezone _pat_19_2 = _con_x2286->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x2286->instant;
      struct kk_std_time_date_Clock* _con_x2287 = kk_std_time_date__as_Clock(_pat_3_5, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2288 = kk_std_time_calendar__as_Calendar(_pat_7_5, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2289 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
      kk_string_t _pat_18_2 = _con_x2286->tzabbrv;
      kk_integer_t _pat_4_6 = _con_x2287->hours;
      kk_integer_t _pat_5_5 = _con_x2287->minutes;
      kk_string_t _pat_8_4 = _con_x2288->name;
      kk_string_t _pat_9_4 = _con_x2288->long_name;
      kk_string_t _pat_10_4 = _con_x2288->month_prefix;
      kk_function_t _pat_11_2 = _con_x2288->show_era;
      kk_function_t _pat_12_2 = _con_x2288->instant_to_dc;
      kk_function_t _pat_13_2 = _con_x2288->dc_to_instant;
      kk_function_t _pat_14_2 = _con_x2288->days_to_date;
      kk_function_t _pat_15_2 = _con_x2288->date_to_days;
      kk_string_t _pat_20_2 = _con_x2289->name;
      kk_function_t _pat_21_2 = _con_x2289->utc_delta;
      kk_function_t _pat_22_2 = _con_x2289->utc_inverse;
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
          kk_integer_drop(_pat_4_6, _ctx);
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
        _x_x2285 = _x_5; /*int*/
      }
    }
    s_0_10075 = kk_std_core_int_show(_x_x2285, _ctx); /*string*/
    kk_integer_t n_2;
    kk_string_t _x_x2290 = kk_string_dup(s_0_10075, _ctx); /*string*/
    n_2 = kk_std_core_string_chars_fs_count(_x_x2290, _ctx); /*int*/
    kk_string_t nothing_10066;
    kk_string_t _x_x2291;
    kk_define_string_literal(, _s_x2292, 1, "M", _ctx)
    _x_x2291 = kk_string_dup(_s_x2292, _ctx); /*string*/
    kk_string_t _x_x2293;
    bool _match_x1393 = kk_integer_lte_borrow((kk_integer_from_small(2)),n_2,kk_context()); /*bool*/;
    if (_match_x1393) {
      kk_integer_drop(n_2, _ctx);
      _x_x2293 = s_0_10075; /*string*/
    }
    else {
      kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10012_0 = kk_integer_sub((kk_integer_from_small(2)),n_2,kk_context()); /*int*/;
      kk_string_t _x_x2294 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
      _x_x2293 = kk_std_core_types__lp__plus__plus__rp_(_x_x2294, s_0_10075, _ctx); /*string*/
    }
    nothing_10066 = kk_std_core_types__lp__plus__plus__rp_(_x_x2291, _x_x2293, _ctx); /*string*/
    if (kk_std_core_types__is_Nothing(m_10065, _ctx)) {
      return nothing_10066;
    }
    {
      kk_box_t _box_x548 = m_10065._cons.Just.value;
      kk_string_t x = kk_string_unbox(_box_x548);
      kk_string_drop(nothing_10066, _ctx);
      kk_string_dup(x, _ctx);
      kk_std_core_types__maybe_drop(m_10065, _ctx);
      return x;
    }
  }
}

kk_string_t kk_std_time_format_format_year(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x1357 = kk_integer_eq_borrow(n,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  if (_match_x1357) {
    kk_integer_drop(n, _ctx);
    kk_integer_t _x_x2295;
    {
      struct kk_std_time_time_Time* _con_x2296 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0 = _con_x2296->date;
      kk_std_time_date__clock _pat_3 = _con_x2296->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x2296->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x2296->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x2296->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x2296->instant;
      struct kk_std_time_date_Clock* _con_x2297 = kk_std_time_date__as_Clock(_pat_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2298 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2299 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_string_t _pat_18 = _con_x2296->tzabbrv;
      kk_integer_t _pat_4 = _con_x2297->hours;
      kk_integer_t _pat_5 = _con_x2297->minutes;
      kk_string_t _pat_8 = _con_x2298->name;
      kk_string_t _pat_9 = _con_x2298->long_name;
      kk_string_t _pat_10 = _con_x2298->month_prefix;
      kk_function_t _pat_11 = _con_x2298->show_era;
      kk_function_t _pat_12 = _con_x2298->instant_to_dc;
      kk_function_t _pat_13 = _con_x2298->dc_to_instant;
      kk_function_t _pat_14 = _con_x2298->days_to_date;
      kk_function_t _pat_15 = _con_x2298->date_to_days;
      kk_string_t _pat_20 = _con_x2299->name;
      kk_function_t _pat_21 = _con_x2299->utc_delta;
      kk_function_t _pat_22 = _con_x2299->utc_inverse;
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
        _x_x2295 = _x; /*int*/
      }
    }
    return kk_std_core_int_show(_x_x2295, _ctx);
  }
  {
    bool _match_x1358 = kk_integer_lt_borrow(n,(kk_integer_from_small(5)),kk_context()); /*bool*/;
    if (_match_x1358) {
      kk_integer_t i_10081;
      kk_integer_t _x_x2300;
      {
        struct kk_std_time_time_Time* _con_x2301 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_0 = _con_x2301->date;
        kk_std_time_date__clock _pat_3_1 = _con_x2301->clock;
        kk_std_time_calendar__calendar _pat_7_0 = _con_x2301->calendar;
        kk_std_time_duration__duration _pat_16_0 = _con_x2301->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0 = _con_x2301->timezone;
        kk_std_time_instant__instant _pat_23_0 = _con_x2301->instant;
        struct kk_std_time_date_Clock* _con_x2302 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2303 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2304 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
        kk_string_t _pat_18_0 = _con_x2301->tzabbrv;
        kk_integer_t _pat_4_1 = _con_x2302->hours;
        kk_integer_t _pat_5_0 = _con_x2302->minutes;
        kk_string_t _pat_8_0 = _con_x2303->name;
        kk_string_t _pat_9_0 = _con_x2303->long_name;
        kk_string_t _pat_10_0 = _con_x2303->month_prefix;
        kk_function_t _pat_11_0 = _con_x2303->show_era;
        kk_function_t _pat_12_0 = _con_x2303->instant_to_dc;
        kk_function_t _pat_13_0 = _con_x2303->dc_to_instant;
        kk_function_t _pat_14_0 = _con_x2303->days_to_date;
        kk_function_t _pat_15_0 = _con_x2303->date_to_days;
        kk_string_t _pat_20_0 = _con_x2304->name;
        kk_function_t _pat_21_0 = _con_x2304->utc_delta;
        kk_function_t _pat_22_0 = _con_x2304->utc_inverse;
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
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_integer_drop(_pat_5_0, _ctx);
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
          kk_integer_t _x_1 = _x_0_0.year;
          kk_integer_dup(_x_1, _ctx);
          kk_std_time_date__date_drop(_x_0_0, _ctx);
          _x_x2300 = _x_1; /*int*/
        }
      }
      i_10081 = kk_integer_abs(_x_x2300,kk_context()); /*int*/
      kk_string_t s_0_10084 = kk_std_core_int_show(i_10081, _ctx); /*string*/;
      kk_integer_t n_1;
      kk_string_t _x_x2305 = kk_string_dup(s_0_10084, _ctx); /*string*/
      n_1 = kk_std_core_string_chars_fs_count(_x_x2305, _ctx); /*int*/
      kk_string_t s_10079;
      bool _match_x1391 = kk_integer_lte_borrow(n,n_1,kk_context()); /*bool*/;
      if (_match_x1391) {
        kk_integer_drop(n_1, _ctx);
        s_10079 = s_0_10084; /*string*/
      }
      else {
        kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
        kk_integer_t n_0_10012;
        kk_integer_t _x_x2306 = kk_integer_dup(n, _ctx); /*int*/
        n_0_10012 = kk_integer_sub(_x_x2306,n_1,kk_context()); /*int*/
        kk_string_t _x_x2307 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
        s_10079 = kk_std_core_types__lp__plus__plus__rp_(_x_x2307, s_0_10084, _ctx); /*string*/
      }
      kk_std_core_types__optional n_0_10080 = kk_std_core_types__new_Optional(kk_integer_box(n, _ctx), _ctx); /*? int*/;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_last1(s_10079, _ctx); /*sslice/sslice*/;
      kk_std_core_sslice__sslice _x_x2308;
      bool _match_x1383;
      kk_integer_t _brw_x1389;
      if (kk_std_core_types__is_Optional(n_0_10080, _ctx)) {
        kk_box_t _box_x551 = n_0_10080._cons._Optional.value;
        kk_integer_t _uniq_n_450 = kk_integer_unbox(_box_x551, _ctx);
        kk_integer_dup(_uniq_n_450, _ctx);
        _brw_x1389 = _uniq_n_450; /*int*/
      }
      else {
        _brw_x1389 = kk_integer_from_small(1); /*int*/
      }
      bool _brw_x1390 = kk_integer_eq_borrow(_brw_x1389,(kk_integer_from_small(1)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x1389, _ctx);
      _match_x1383 = _brw_x1390; /*bool*/
      if (_match_x1383) {
        kk_std_core_types__optional_drop(n_0_10080, _ctx);
        _x_x2308 = slice_0; /*sslice/sslice*/
      }
      else {
        kk_std_core_sslice__sslice _own_x1385;
        kk_integer_t _brw_x1386;
        kk_integer_t _x_x2309;
        if (kk_std_core_types__is_Optional(n_0_10080, _ctx)) {
          kk_box_t _box_x552 = n_0_10080._cons._Optional.value;
          kk_integer_t _uniq_n_450_0 = kk_integer_unbox(_box_x552, _ctx);
          kk_integer_dup(_uniq_n_450_0, _ctx);
          _x_x2309 = _uniq_n_450_0; /*int*/
        }
        else {
          _x_x2309 = kk_integer_from_small(1); /*int*/
        }
        _brw_x1386 = kk_integer_sub((kk_integer_from_small(1)),_x_x2309,kk_context()); /*int*/
        kk_std_core_sslice__sslice _brw_x1387 = kk_std_core_sslice_advance(slice_0, _brw_x1386, _ctx); /*sslice/sslice*/;
        kk_integer_drop(_brw_x1386, _ctx);
        _own_x1385 = _brw_x1387; /*sslice/sslice*/
        kk_integer_t _brw_x1384;
        kk_integer_t _x_x2310;
        if (kk_std_core_types__is_Optional(n_0_10080, _ctx)) {
          kk_box_t _box_x553 = n_0_10080._cons._Optional.value;
          kk_integer_t _uniq_n_450_1 = kk_integer_unbox(_box_x553, _ctx);
          kk_integer_dup(_uniq_n_450_1, _ctx);
          kk_std_core_types__optional_drop(n_0_10080, _ctx);
          _x_x2310 = _uniq_n_450_1; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(n_0_10080, _ctx);
          _x_x2310 = kk_integer_from_small(1); /*int*/
        }
        _brw_x1384 = kk_integer_add_small_const(_x_x2310, -1, _ctx); /*int*/
        kk_std_core_sslice__sslice _brw_x1388 = kk_std_core_sslice_extend(_own_x1385, _brw_x1384, _ctx); /*sslice/sslice*/;
        kk_integer_drop(_brw_x1384, _ctx);
        _x_x2308 = _brw_x1388; /*sslice/sslice*/
      }
      return kk_std_core_sslice_string(_x_x2308, _ctx);
    }
    {
      bool _match_x1359;
      kk_integer_t _brw_x1381;
      {
        struct kk_std_time_time_Time* _con_x2311 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_0_1 = _con_x2311->date;
        kk_std_time_date__clock _pat_3_2 = _con_x2311->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2311->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x2311->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x2311->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x2311->instant;
        struct kk_std_time_date_Clock* _con_x2312 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2313 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2314 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__date_dup(_x_0_1, _ctx);
        {
          kk_integer_t _x_2 = _x_0_1.year;
          kk_integer_dup(_x_2, _ctx);
          kk_std_time_date__date_drop(_x_0_1, _ctx);
          _brw_x1381 = _x_2; /*int*/
        }
      }
      bool _brw_x1382 = kk_integer_gte_borrow(_brw_x1381,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x1381, _ctx);
      _match_x1359 = _brw_x1382; /*bool*/
      if (_match_x1359) {
        bool _match_x1364;
        kk_integer_t _brw_x1379;
        {
          struct kk_std_time_time_Time* _con_x2315 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_0_2 = _con_x2315->date;
          kk_std_time_date__clock _pat_3_4 = _con_x2315->clock;
          kk_std_time_calendar__calendar _pat_7_2 = _con_x2315->calendar;
          kk_std_time_duration__duration _pat_16_2 = _con_x2315->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2 = _con_x2315->timezone;
          kk_std_time_instant__instant _pat_23_2 = _con_x2315->instant;
          struct kk_std_time_date_Clock* _con_x2316 = kk_std_time_date__as_Clock(_pat_3_4, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x2317 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x2318 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
          kk_std_time_date__date_dup(_x_0_2, _ctx);
          {
            kk_integer_t _x_3 = _x_0_2.year;
            kk_integer_dup(_x_3, _ctx);
            kk_std_time_date__date_drop(_x_0_2, _ctx);
            _brw_x1379 = _x_3; /*int*/
          }
        }
        kk_integer_t _brw_x1378 = kk_integer_from_int(9999, _ctx); /*int*/;
        bool _brw_x1380 = kk_integer_lte_borrow(_brw_x1379,_brw_x1378,kk_context()); /*bool*/;
        kk_integer_drop(_brw_x1379, _ctx);
        kk_integer_drop(_brw_x1378, _ctx);
        _match_x1364 = _brw_x1380; /*bool*/
        if (_match_x1364) {
          kk_integer_t i_0_10091;
          kk_integer_t _x_x2319;
          {
            struct kk_std_time_time_Time* _con_x2320 = kk_std_time_time__as_Time(t, _ctx);
            kk_std_time_date__date _x_0_3 = _con_x2320->date;
            kk_std_time_date__clock _pat_3_6 = _con_x2320->clock;
            kk_std_time_calendar__calendar _pat_7_3 = _con_x2320->calendar;
            kk_std_time_duration__duration _pat_16_3 = _con_x2320->tzdelta;
            kk_std_time_calendar__timezone _pat_19_3 = _con_x2320->timezone;
            kk_std_time_instant__instant _pat_23_3 = _con_x2320->instant;
            struct kk_std_time_date_Clock* _con_x2321 = kk_std_time_date__as_Clock(_pat_3_6, _ctx);
            struct kk_std_time_calendar_Calendar* _con_x2322 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
            struct kk_std_time_calendar_Timezone* _con_x2323 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
            kk_string_t _pat_18_3 = _con_x2320->tzabbrv;
            kk_integer_t _pat_4_5 = _con_x2321->hours;
            kk_integer_t _pat_5_4 = _con_x2321->minutes;
            kk_string_t _pat_8_3 = _con_x2322->name;
            kk_string_t _pat_9_3 = _con_x2322->long_name;
            kk_string_t _pat_10_3 = _con_x2322->month_prefix;
            kk_function_t _pat_11_3 = _con_x2322->show_era;
            kk_function_t _pat_12_3 = _con_x2322->instant_to_dc;
            kk_function_t _pat_13_3 = _con_x2322->dc_to_instant;
            kk_function_t _pat_14_3 = _con_x2322->days_to_date;
            kk_function_t _pat_15_3 = _con_x2322->date_to_days;
            kk_string_t _pat_20_3 = _con_x2323->name;
            kk_function_t _pat_21_3 = _con_x2323->utc_delta;
            kk_function_t _pat_22_3 = _con_x2323->utc_inverse;
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
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3_6, _ctx)) {
                kk_integer_drop(_pat_5_4, _ctx);
                kk_integer_drop(_pat_4_5, _ctx);
                kk_datatype_ptr_free(_pat_3_6, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_3_6, _ctx);
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
              _x_x2319 = _x_4; /*int*/
            }
          }
          i_0_10091 = kk_integer_abs(_x_x2319,kk_context()); /*int*/
          kk_string_t s_2_10094 = kk_std_core_int_show(i_0_10091, _ctx); /*string*/;
          kk_integer_t n_3;
          kk_string_t _x_x2324 = kk_string_dup(s_2_10094, _ctx); /*string*/
          n_3 = kk_std_core_string_chars_fs_count(_x_x2324, _ctx); /*int*/
          kk_string_t s_1_10089;
          bool _match_x1377 = kk_integer_lte_borrow(n,n_3,kk_context()); /*bool*/;
          if (_match_x1377) {
            kk_integer_drop(n_3, _ctx);
            s_1_10089 = s_2_10094; /*string*/
          }
          else {
            kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
            kk_integer_t n_0_10012_0;
            kk_integer_t _x_x2325 = kk_integer_dup(n, _ctx); /*int*/
            n_0_10012_0 = kk_integer_sub(_x_x2325,n_3,kk_context()); /*int*/
            kk_string_t _x_x2326 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
            s_1_10089 = kk_std_core_types__lp__plus__plus__rp_(_x_x2326, s_2_10094, _ctx); /*string*/
          }
          kk_std_core_types__optional n_2_10090 = kk_std_core_types__new_Optional(kk_integer_box(n, _ctx), _ctx); /*? int*/;
          kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_last1(s_1_10089, _ctx); /*sslice/sslice*/;
          kk_std_core_sslice__sslice _x_x2327;
          bool _match_x1369;
          kk_integer_t _brw_x1375;
          if (kk_std_core_types__is_Optional(n_2_10090, _ctx)) {
            kk_box_t _box_x556 = n_2_10090._cons._Optional.value;
            kk_integer_t _uniq_n_450_2 = kk_integer_unbox(_box_x556, _ctx);
            kk_integer_dup(_uniq_n_450_2, _ctx);
            _brw_x1375 = _uniq_n_450_2; /*int*/
          }
          else {
            _brw_x1375 = kk_integer_from_small(1); /*int*/
          }
          bool _brw_x1376 = kk_integer_eq_borrow(_brw_x1375,(kk_integer_from_small(1)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x1375, _ctx);
          _match_x1369 = _brw_x1376; /*bool*/
          if (_match_x1369) {
            kk_std_core_types__optional_drop(n_2_10090, _ctx);
            _x_x2327 = slice_0_0; /*sslice/sslice*/
          }
          else {
            kk_std_core_sslice__sslice _own_x1371;
            kk_integer_t _brw_x1372;
            kk_integer_t _x_x2328;
            if (kk_std_core_types__is_Optional(n_2_10090, _ctx)) {
              kk_box_t _box_x557 = n_2_10090._cons._Optional.value;
              kk_integer_t _uniq_n_450_0_0 = kk_integer_unbox(_box_x557, _ctx);
              kk_integer_dup(_uniq_n_450_0_0, _ctx);
              _x_x2328 = _uniq_n_450_0_0; /*int*/
            }
            else {
              _x_x2328 = kk_integer_from_small(1); /*int*/
            }
            _brw_x1372 = kk_integer_sub((kk_integer_from_small(1)),_x_x2328,kk_context()); /*int*/
            kk_std_core_sslice__sslice _brw_x1373 = kk_std_core_sslice_advance(slice_0_0, _brw_x1372, _ctx); /*sslice/sslice*/;
            kk_integer_drop(_brw_x1372, _ctx);
            _own_x1371 = _brw_x1373; /*sslice/sslice*/
            kk_integer_t _brw_x1370;
            kk_integer_t _x_x2329;
            if (kk_std_core_types__is_Optional(n_2_10090, _ctx)) {
              kk_box_t _box_x558 = n_2_10090._cons._Optional.value;
              kk_integer_t _uniq_n_450_1_0 = kk_integer_unbox(_box_x558, _ctx);
              kk_integer_dup(_uniq_n_450_1_0, _ctx);
              kk_std_core_types__optional_drop(n_2_10090, _ctx);
              _x_x2329 = _uniq_n_450_1_0; /*int*/
            }
            else {
              kk_std_core_types__optional_drop(n_2_10090, _ctx);
              _x_x2329 = kk_integer_from_small(1); /*int*/
            }
            _brw_x1370 = kk_integer_add_small_const(_x_x2329, -1, _ctx); /*int*/
            kk_std_core_sslice__sslice _brw_x1374 = kk_std_core_sslice_extend(_own_x1371, _brw_x1370, _ctx); /*sslice/sslice*/;
            kk_integer_drop(_brw_x1370, _ctx);
            _x_x2327 = _brw_x1374; /*sslice/sslice*/
          }
          return kk_std_core_sslice_string(_x_x2327, _ctx);
        }
        {
          kk_integer_t i_1_10097;
          kk_integer_t _x_x2330;
          {
            struct kk_std_time_time_Time* _con_x2331 = kk_std_time_time__as_Time(t, _ctx);
            kk_std_time_date__date _x_0_4 = _con_x2331->date;
            kk_std_time_date__clock _pat_3_7 = _con_x2331->clock;
            kk_std_time_calendar__calendar _pat_7_4 = _con_x2331->calendar;
            kk_std_time_duration__duration _pat_16_4 = _con_x2331->tzdelta;
            kk_std_time_calendar__timezone _pat_19_4 = _con_x2331->timezone;
            kk_std_time_instant__instant _pat_23_4 = _con_x2331->instant;
            struct kk_std_time_date_Clock* _con_x2332 = kk_std_time_date__as_Clock(_pat_3_7, _ctx);
            struct kk_std_time_calendar_Calendar* _con_x2333 = kk_std_time_calendar__as_Calendar(_pat_7_4, _ctx);
            struct kk_std_time_calendar_Timezone* _con_x2334 = kk_std_time_calendar__as_Timezone(_pat_19_4, _ctx);
            kk_std_time_date__date_dup(_x_0_4, _ctx);
            {
              kk_integer_t _x_5 = _x_0_4.year;
              kk_integer_dup(_x_5, _ctx);
              kk_std_time_date__date_drop(_x_0_4, _ctx);
              _x_x2330 = _x_5; /*int*/
            }
          }
          i_1_10097 = kk_integer_abs(_x_x2330,kk_context()); /*int*/
          kk_string_t s_3_10100 = kk_std_core_int_show(i_1_10097, _ctx); /*string*/;
          kk_integer_t n_4;
          kk_string_t _x_x2335 = kk_string_dup(s_3_10100, _ctx); /*string*/
          n_4 = kk_std_core_string_chars_fs_count(_x_x2335, _ctx); /*int*/
          kk_string_t y;
          bool _match_x1368 = kk_integer_lte_borrow(n,n_4,kk_context()); /*bool*/;
          if (_match_x1368) {
            kk_integer_drop(n_4, _ctx);
            kk_integer_drop(n, _ctx);
            y = s_3_10100; /*string*/
          }
          else {
            kk_string_t s_0_10011_1 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
            kk_integer_t n_0_10012_1 = kk_integer_sub(n,n_4,kk_context()); /*int*/;
            kk_string_t _x_x2336 = kk_std_core_string_repeatz(s_0_10011_1, kk_std_core_int_ssize__t(n_0_10012_1, _ctx), _ctx); /*string*/
            y = kk_std_core_types__lp__plus__plus__rp_(_x_x2336, s_3_10100, _ctx); /*string*/
          }
          bool _match_x1365;
          kk_integer_t _brw_x1366;
          {
            struct kk_std_time_time_Time* _con_x2337 = kk_std_time_time__as_Time(t, _ctx);
            kk_std_time_date__date _x_0_5 = _con_x2337->date;
            kk_std_time_date__clock _pat_3_8 = _con_x2337->clock;
            kk_std_time_calendar__calendar _pat_7_5 = _con_x2337->calendar;
            kk_std_time_duration__duration _pat_16_5 = _con_x2337->tzdelta;
            kk_std_time_calendar__timezone _pat_19_5 = _con_x2337->timezone;
            kk_std_time_instant__instant _pat_23_5 = _con_x2337->instant;
            struct kk_std_time_date_Clock* _con_x2338 = kk_std_time_date__as_Clock(_pat_3_8, _ctx);
            struct kk_std_time_calendar_Calendar* _con_x2339 = kk_std_time_calendar__as_Calendar(_pat_7_5, _ctx);
            struct kk_std_time_calendar_Timezone* _con_x2340 = kk_std_time_calendar__as_Timezone(_pat_19_5, _ctx);
            kk_string_t _pat_18_5 = _con_x2337->tzabbrv;
            kk_integer_t _pat_4_7 = _con_x2338->hours;
            kk_integer_t _pat_5_6 = _con_x2338->minutes;
            kk_string_t _pat_8_5 = _con_x2339->name;
            kk_string_t _pat_9_5 = _con_x2339->long_name;
            kk_string_t _pat_10_5 = _con_x2339->month_prefix;
            kk_function_t _pat_11_5 = _con_x2339->show_era;
            kk_function_t _pat_12_5 = _con_x2339->instant_to_dc;
            kk_function_t _pat_13_5 = _con_x2339->dc_to_instant;
            kk_function_t _pat_14_5 = _con_x2339->days_to_date;
            kk_function_t _pat_15_5 = _con_x2339->date_to_days;
            kk_string_t _pat_20_5 = _con_x2340->name;
            kk_function_t _pat_21_5 = _con_x2340->utc_delta;
            kk_function_t _pat_22_5 = _con_x2340->utc_inverse;
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
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3_8, _ctx)) {
                kk_integer_drop(_pat_5_6, _ctx);
                kk_integer_drop(_pat_4_7, _ctx);
                kk_datatype_ptr_free(_pat_3_8, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_pat_3_8, _ctx);
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
              _brw_x1366 = _x_6; /*int*/
            }
          }
          bool _brw_x1367 = kk_integer_lt_borrow(_brw_x1366,(kk_integer_from_small(0)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x1366, _ctx);
          _match_x1365 = _brw_x1367; /*bool*/
          if (_match_x1365) {
            kk_string_t _x_x2341;
            kk_define_string_literal(, _s_x2342, 1, "-", _ctx)
            _x_x2341 = kk_string_dup(_s_x2342, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x2341, y, _ctx);
          }
          {
            kk_string_t _x_x2343;
            kk_define_string_literal(, _s_x2344, 1, "+", _ctx)
            _x_x2343 = kk_string_dup(_s_x2344, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x2343, y, _ctx);
          }
        }
      }
      {
        kk_integer_t i_3_10105;
        kk_integer_t _x_x2345;
        {
          struct kk_std_time_time_Time* _con_x2346 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_0_6 = _con_x2346->date;
          kk_std_time_date__clock _pat_3_9 = _con_x2346->clock;
          kk_std_time_calendar__calendar _pat_7_7 = _con_x2346->calendar;
          kk_std_time_duration__duration _pat_16_6 = _con_x2346->tzdelta;
          kk_std_time_calendar__timezone _pat_19_6 = _con_x2346->timezone;
          kk_std_time_instant__instant _pat_23_6 = _con_x2346->instant;
          struct kk_std_time_date_Clock* _con_x2347 = kk_std_time_date__as_Clock(_pat_3_9, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x2348 = kk_std_time_calendar__as_Calendar(_pat_7_7, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x2349 = kk_std_time_calendar__as_Timezone(_pat_19_6, _ctx);
          kk_std_time_date__date_dup(_x_0_6, _ctx);
          {
            kk_integer_t _x_7 = _x_0_6.year;
            kk_integer_dup(_x_7, _ctx);
            kk_std_time_date__date_drop(_x_0_6, _ctx);
            _x_x2345 = _x_7; /*int*/
          }
        }
        i_3_10105 = kk_integer_abs(_x_x2345,kk_context()); /*int*/
        kk_string_t s_4_10108 = kk_std_core_int_show(i_3_10105, _ctx); /*string*/;
        kk_integer_t n_5;
        kk_string_t _x_x2350 = kk_string_dup(s_4_10108, _ctx); /*string*/
        n_5 = kk_std_core_string_chars_fs_count(_x_x2350, _ctx); /*int*/
        kk_string_t y_0;
        bool _match_x1363 = kk_integer_lte_borrow(n,n_5,kk_context()); /*bool*/;
        if (_match_x1363) {
          kk_integer_drop(n_5, _ctx);
          kk_integer_drop(n, _ctx);
          y_0 = s_4_10108; /*string*/
        }
        else {
          kk_string_t s_0_10011_2 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
          kk_integer_t n_0_10012_2 = kk_integer_sub(n,n_5,kk_context()); /*int*/;
          kk_string_t _x_x2351 = kk_std_core_string_repeatz(s_0_10011_2, kk_std_core_int_ssize__t(n_0_10012_2, _ctx), _ctx); /*string*/
          y_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x2351, s_4_10108, _ctx); /*string*/
        }
        bool _match_x1360;
        kk_integer_t _brw_x1361;
        {
          struct kk_std_time_time_Time* _con_x2352 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_0_7 = _con_x2352->date;
          kk_std_time_date__clock _pat_3_10 = _con_x2352->clock;
          kk_std_time_calendar__calendar _pat_7_8 = _con_x2352->calendar;
          kk_std_time_duration__duration _pat_16_7 = _con_x2352->tzdelta;
          kk_std_time_calendar__timezone _pat_19_7 = _con_x2352->timezone;
          kk_std_time_instant__instant _pat_23_7 = _con_x2352->instant;
          struct kk_std_time_date_Clock* _con_x2353 = kk_std_time_date__as_Clock(_pat_3_10, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x2354 = kk_std_time_calendar__as_Calendar(_pat_7_8, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x2355 = kk_std_time_calendar__as_Timezone(_pat_19_7, _ctx);
          kk_string_t _pat_18_7 = _con_x2352->tzabbrv;
          kk_integer_t _pat_4_10 = _con_x2353->hours;
          kk_integer_t _pat_5_8 = _con_x2353->minutes;
          kk_string_t _pat_8_8 = _con_x2354->name;
          kk_string_t _pat_9_7 = _con_x2354->long_name;
          kk_string_t _pat_10_7 = _con_x2354->month_prefix;
          kk_function_t _pat_11_7 = _con_x2354->show_era;
          kk_function_t _pat_12_7 = _con_x2354->instant_to_dc;
          kk_function_t _pat_13_7 = _con_x2354->dc_to_instant;
          kk_function_t _pat_14_7 = _con_x2354->days_to_date;
          kk_function_t _pat_15_7 = _con_x2354->date_to_days;
          kk_string_t _pat_20_7 = _con_x2355->name;
          kk_function_t _pat_21_7 = _con_x2355->utc_delta;
          kk_function_t _pat_22_7 = _con_x2355->utc_inverse;
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
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3_10, _ctx)) {
              kk_integer_drop(_pat_5_8, _ctx);
              kk_integer_drop(_pat_4_10, _ctx);
              kk_datatype_ptr_free(_pat_3_10, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_3_10, _ctx);
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
            _brw_x1361 = _x_8; /*int*/
          }
        }
        bool _brw_x1362 = kk_integer_lt_borrow(_brw_x1361,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        kk_integer_drop(_brw_x1361, _ctx);
        _match_x1360 = _brw_x1362; /*bool*/
        if (_match_x1360) {
          kk_string_t _x_x2356;
          kk_define_string_literal(, _s_x2357, 1, "-", _ctx)
          _x_x2356 = kk_string_dup(_s_x2357, _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x2356, y_0, _ctx);
        }
        {
          kk_string_t _x_x2358;
          kk_define_string_literal(, _s_x2359, 1, "+", _ctx)
          _x_x2358 = kk_string_dup(_s_x2359, _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x2358, y_0, _ctx);
        }
      }
    }
  }
}

kk_string_t kk_std_time_format_format_era(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_drop(n, _ctx);
  {
    struct kk_std_time_time_Time* _con_x2360 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x2360->date;
    kk_std_time_date__clock _pat_4_0 = _con_x2360->clock;
    kk_std_time_calendar__calendar _x_0 = _con_x2360->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2360->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2360->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2360->instant;
    struct kk_std_time_date_Clock* _con_x2361 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2362 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2363 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_calendar__calendar_dup(_x_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2364 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x2364->name;
      kk_string_t _pat_1 = _con_x2364->long_name;
      kk_string_t _pat_2 = _con_x2364->month_prefix;
      kk_function_t _x = _con_x2364->show_era;
      kk_function_t _pat_3 = _con_x2364->instant_to_dc;
      kk_function_t _pat_4 = _con_x2364->dc_to_instant;
      kk_function_t _pat_5 = _con_x2364->days_to_date;
      kk_function_t _pat_6 = _con_x2364->date_to_days;
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
      kk_std_time_date__date _x_x2365;
      {
        struct kk_std_time_time_Time* _con_x2366 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_1 = _con_x2366->date;
        kk_std_time_date__clock _pat_3_1 = _con_x2366->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2366->calendar;
        kk_std_time_duration__duration _pat_16_0 = _con_x2366->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0 = _con_x2366->timezone;
        kk_std_time_instant__instant _pat_23_0 = _con_x2366->instant;
        struct kk_std_time_date_Clock* _con_x2367 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2368 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2369 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
        kk_string_t _pat_18_0 = _con_x2366->tzabbrv;
        kk_integer_t _pat_4_1 = _con_x2367->hours;
        kk_integer_t _pat_5_1 = _con_x2367->minutes;
        kk_string_t _pat_8_0 = _con_x2368->name;
        kk_string_t _pat_9_0 = _con_x2368->long_name;
        kk_string_t _pat_10_0 = _con_x2368->month_prefix;
        kk_function_t _pat_11_0 = _con_x2368->show_era;
        kk_function_t _pat_12_0 = _con_x2368->instant_to_dc;
        kk_function_t _pat_13_0 = _con_x2368->dc_to_instant;
        kk_function_t _pat_14_0 = _con_x2368->days_to_date;
        kk_function_t _pat_15_0 = _con_x2368->date_to_days;
        kk_string_t _pat_20_0 = _con_x2369->name;
        kk_function_t _pat_21_0 = _con_x2369->utc_delta;
        kk_function_t _pat_22_0 = _con_x2369->utc_inverse;
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
        _x_x2365 = _x_1; /*std/time/date/date*/
      }
      return kk_function_call(kk_string_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, _x_x2365, _ctx), _ctx);
    }
  }
}

kk_string_t kk_std_time_format_format_seconds(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_t i_10116;
  kk_std_num_ddouble__ddouble _x_x2370;
  bool _match_x1356;
  double _x_x2371;
  {
    struct kk_std_time_time_Time* _con_x2372 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_1 = _con_x2372->date;
    kk_std_time_date__clock _x_0 = _con_x2372->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2372->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2372->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2372->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2372->instant;
    struct kk_std_time_date_Clock* _con_x2373 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2374 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2375 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__clock_dup(_x_0, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x2376 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x2376->seconds;
      kk_integer_t _pat_0_2 = _con_x2376->hours;
      kk_integer_t _pat_1_1 = _con_x2376->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      {
        double _x = _x_1.hi;
        _x_x2371 = _x; /*float64*/
      }
    }
  }
  _match_x1356 = (_x_x2371 < (0x0p+0)); /*bool*/
  if (_match_x1356) {
    kk_std_num_ddouble__ddouble _x_x2377;
    {
      struct kk_std_time_time_Time* _con_x2378 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_0 = _con_x2378->date;
      kk_std_time_date__clock _x_0_0 = _con_x2378->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x2378->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2378->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2378->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2378->instant;
      struct kk_std_time_date_Clock* _con_x2379 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2380 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2381 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_string_t _pat_18_0 = _con_x2378->tzabbrv;
      kk_string_t _pat_8_0 = _con_x2380->name;
      kk_string_t _pat_9_0 = _con_x2380->long_name;
      kk_string_t _pat_10_0 = _con_x2380->month_prefix;
      kk_function_t _pat_11_0 = _con_x2380->show_era;
      kk_function_t _pat_12_0 = _con_x2380->instant_to_dc;
      kk_function_t _pat_13_0 = _con_x2380->dc_to_instant;
      kk_function_t _pat_14_0 = _con_x2380->days_to_date;
      kk_function_t _pat_15_0 = _con_x2380->date_to_days;
      kk_string_t _pat_20_0 = _con_x2381->name;
      kk_function_t _pat_21_0 = _con_x2381->utc_delta;
      kk_function_t _pat_22_0 = _con_x2381->utc_inverse;
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
        struct kk_std_time_date_Clock* _con_x2382 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0 = _con_x2382->seconds;
        kk_integer_t _pat_0_2_0 = _con_x2382->hours;
        kk_integer_t _pat_1_1_0 = _con_x2382->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
          kk_integer_drop(_pat_1_1_0, _ctx);
          kk_integer_drop(_pat_0_2_0, _ctx);
          kk_datatype_ptr_free(_x_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_0, _ctx);
        }
        _x_x2377 = _x_1_0; /*std/num/ddouble/ddouble*/
      }
    }
    _x_x2370 = kk_std_num_ddouble_ceiling(_x_x2377, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2383;
    {
      struct kk_std_time_time_Time* _con_x2384 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_1 = _con_x2384->date;
      kk_std_time_date__clock _x_0_1 = _con_x2384->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x2384->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x2384->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x2384->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x2384->instant;
      struct kk_std_time_date_Clock* _con_x2385 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2386 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2387 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_string_t _pat_18_1 = _con_x2384->tzabbrv;
      kk_string_t _pat_8_1 = _con_x2386->name;
      kk_string_t _pat_9_1 = _con_x2386->long_name;
      kk_string_t _pat_10_1 = _con_x2386->month_prefix;
      kk_function_t _pat_11_1 = _con_x2386->show_era;
      kk_function_t _pat_12_1 = _con_x2386->instant_to_dc;
      kk_function_t _pat_13_1 = _con_x2386->dc_to_instant;
      kk_function_t _pat_14_1 = _con_x2386->days_to_date;
      kk_function_t _pat_15_1 = _con_x2386->date_to_days;
      kk_string_t _pat_20_1 = _con_x2387->name;
      kk_function_t _pat_21_1 = _con_x2387->utc_delta;
      kk_function_t _pat_22_1 = _con_x2387->utc_inverse;
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
        struct kk_std_time_date_Clock* _con_x2388 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
        kk_std_num_ddouble__ddouble _x_1_1 = _con_x2388->seconds;
        kk_integer_t _pat_0_2_1 = _con_x2388->hours;
        kk_integer_t _pat_1_1_1 = _con_x2388->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
          kk_integer_drop(_pat_1_1_1, _ctx);
          kk_integer_drop(_pat_0_2_1, _ctx);
          kk_datatype_ptr_free(_x_0_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1, _ctx);
        }
        _x_x2383 = _x_1_1; /*std/num/ddouble/ddouble*/
      }
    }
    _x_x2370 = kk_std_num_ddouble_floor(_x_x2383, _ctx); /*std/num/ddouble/ddouble*/
  }
  i_10116 = kk_std_num_ddouble_int(_x_x2370, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_string_t s_10120 = kk_std_core_int_show(i_10116, _ctx); /*string*/;
  kk_integer_t n_0;
  kk_string_t _x_x2389 = kk_string_dup(s_10120, _ctx); /*string*/
  n_0 = kk_std_core_string_chars_fs_count(_x_x2389, _ctx); /*int*/
  bool _match_x1355 = kk_integer_lte_borrow(n,n_0,kk_context()); /*bool*/;
  if (_match_x1355) {
    kk_integer_drop(n_0, _ctx);
    kk_integer_drop(n, _ctx);
    return s_10120;
  }
  {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012 = kk_integer_sub(n,n_0,kk_context()); /*int*/;
    kk_string_t _x_x2390 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x2390, s_10120, _ctx);
  }
}

kk_string_t kk_std_time_format_format_minutes(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t s_10126;
  kk_integer_t _x_x2391;
  {
    struct kk_std_time_time_Time* _con_x2392 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_0 = _con_x2392->date;
    kk_std_time_date__clock _x_0 = _con_x2392->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2392->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2392->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2392->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2392->instant;
    struct kk_std_time_date_Clock* _con_x2393 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2394 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2395 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2392->tzabbrv;
    kk_string_t _pat_8 = _con_x2394->name;
    kk_string_t _pat_9 = _con_x2394->long_name;
    kk_string_t _pat_10 = _con_x2394->month_prefix;
    kk_function_t _pat_11 = _con_x2394->show_era;
    kk_function_t _pat_12 = _con_x2394->instant_to_dc;
    kk_function_t _pat_13 = _con_x2394->dc_to_instant;
    kk_function_t _pat_14 = _con_x2394->days_to_date;
    kk_function_t _pat_15 = _con_x2394->date_to_days;
    kk_string_t _pat_20 = _con_x2395->name;
    kk_function_t _pat_21 = _con_x2395->utc_delta;
    kk_function_t _pat_22 = _con_x2395->utc_inverse;
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
      kk_std_time_date__date_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x2396 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_1 = _con_x2396->seconds;
      kk_integer_t _pat_0_1 = _con_x2396->hours;
      kk_integer_t _x = _con_x2396->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x2391 = _x; /*int*/
    }
  }
  s_10126 = kk_std_core_int_show(_x_x2391, _ctx); /*string*/
  kk_integer_t n_0;
  kk_string_t _x_x2397 = kk_string_dup(s_10126, _ctx); /*string*/
  n_0 = kk_std_core_string_chars_fs_count(_x_x2397, _ctx); /*int*/
  bool _match_x1354 = kk_integer_lte_borrow(n,n_0,kk_context()); /*bool*/;
  if (_match_x1354) {
    kk_integer_drop(n_0, _ctx);
    kk_integer_drop(n, _ctx);
    return s_10126;
  }
  {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012 = kk_integer_sub(n,n_0,kk_context()); /*int*/;
    kk_string_t _x_x2398 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x2398, s_10126, _ctx);
  }
}

kk_string_t kk_std_time_format_format_hours(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t s_10132;
  kk_integer_t _x_x2399;
  {
    struct kk_std_time_time_Time* _con_x2400 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_0 = _con_x2400->date;
    kk_std_time_date__clock _x_0 = _con_x2400->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2400->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2400->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2400->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2400->instant;
    struct kk_std_time_date_Clock* _con_x2401 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2402 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2403 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2400->tzabbrv;
    kk_string_t _pat_8 = _con_x2402->name;
    kk_string_t _pat_9 = _con_x2402->long_name;
    kk_string_t _pat_10 = _con_x2402->month_prefix;
    kk_function_t _pat_11 = _con_x2402->show_era;
    kk_function_t _pat_12 = _con_x2402->instant_to_dc;
    kk_function_t _pat_13 = _con_x2402->dc_to_instant;
    kk_function_t _pat_14 = _con_x2402->days_to_date;
    kk_function_t _pat_15 = _con_x2402->date_to_days;
    kk_string_t _pat_20 = _con_x2403->name;
    kk_function_t _pat_21 = _con_x2403->utc_delta;
    kk_function_t _pat_22 = _con_x2403->utc_inverse;
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
      kk_std_time_date__date_drop(_pat_0_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x2404 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_1 = _con_x2404->seconds;
      kk_integer_t _x = _con_x2404->hours;
      kk_integer_t _pat_0_1 = _con_x2404->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x2399 = _x; /*int*/
    }
  }
  s_10132 = kk_std_core_int_show(_x_x2399, _ctx); /*string*/
  kk_integer_t n_0;
  kk_string_t _x_x2405 = kk_string_dup(s_10132, _ctx); /*string*/
  n_0 = kk_std_core_string_chars_fs_count(_x_x2405, _ctx); /*int*/
  bool _match_x1353 = kk_integer_lte_borrow(n,n_0,kk_context()); /*bool*/;
  if (_match_x1353) {
    kk_integer_drop(n_0, _ctx);
    kk_integer_drop(n, _ctx);
    return s_10132;
  }
  {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012 = kk_integer_sub(n,n_0,kk_context()); /*int*/;
    kk_string_t _x_x2406 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x2406, s_10132, _ctx);
  }
}

kk_string_t kk_std_time_format_format_hours12(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  bool _match_x1342;
  kk_integer_t _brw_x1351;
  {
    struct kk_std_time_time_Time* _con_x2407 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x2407->date;
    kk_std_time_date__clock _x_0 = _con_x2407->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2407->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2407->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2407->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2407->instant;
    struct kk_std_time_date_Clock* _con_x2408 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2409 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2410 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__clock_dup(_x_0, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x2411 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1 = _con_x2411->seconds;
      kk_integer_t _x = _con_x2411->hours;
      kk_integer_t _pat_0 = _con_x2411->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _brw_x1351 = _x; /*int*/
    }
  }
  bool _brw_x1352 = kk_integer_eq_borrow(_brw_x1351,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1351, _ctx);
  _match_x1342 = _brw_x1352; /*bool*/
  if (_match_x1342) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_integer_drop(n, _ctx);
    kk_define_string_literal(, _s_x2412, 2, "12", _ctx)
    return kk_string_dup(_s_x2412, _ctx);
  }
  {
    bool _match_x1343;
    kk_integer_t _brw_x1349;
    {
      struct kk_std_time_time_Time* _con_x2413 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_0 = _con_x2413->date;
      kk_std_time_date__clock _x_0_0 = _con_x2413->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x2413->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2413->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2413->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2413->instant;
      struct kk_std_time_date_Clock* _con_x2414 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2415 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2416 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__clock_dup(_x_0_0, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2417 = kk_std_time_date__as_Clock(_x_0_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_1_1 = _con_x2417->seconds;
        kk_integer_t _x_1 = _con_x2417->hours;
        kk_integer_t _pat_0_2 = _con_x2417->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(_x_0_0, _ctx);
        }
        else {
          kk_integer_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(_x_0_0, _ctx);
        }
        _brw_x1349 = _x_1; /*int*/
      }
    }
    bool _brw_x1350 = kk_integer_eq_borrow(_brw_x1349,(kk_integer_from_small(12)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1349, _ctx);
    _match_x1343 = _brw_x1350; /*bool*/
    if (_match_x1343) {
      kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
      kk_integer_drop(n, _ctx);
      kk_define_string_literal(, _s_x2418, 2, "12", _ctx)
      return kk_string_dup(_s_x2418, _ctx);
    }
    {
      bool _match_x1344;
      kk_integer_t _brw_x1347;
      {
        struct kk_std_time_time_Time* _con_x2419 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _pat_0_0_1 = _con_x2419->date;
        kk_std_time_date__clock _x_0_1 = _con_x2419->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2419->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x2419->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x2419->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x2419->instant;
        struct kk_std_time_date_Clock* _con_x2420 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2421 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2422 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__clock_dup(_x_0_1, _ctx);
        {
          struct kk_std_time_date_Clock* _con_x2423 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
          kk_std_num_ddouble__ddouble _pat_1_2 = _con_x2423->seconds;
          kk_integer_t _x_2 = _con_x2423->hours;
          kk_integer_t _pat_0_3 = _con_x2423->minutes;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
            kk_integer_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(_x_0_1, _ctx);
          }
          else {
            kk_integer_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(_x_0_1, _ctx);
          }
          _brw_x1347 = _x_2; /*int*/
        }
      }
      bool _brw_x1348 = kk_integer_lte_borrow(_brw_x1347,(kk_integer_from_small(11)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x1347, _ctx);
      _match_x1344 = _brw_x1348; /*bool*/
      if (_match_x1344) {
        kk_string_t s_10138;
        kk_integer_t _x_x2424;
        {
          struct kk_std_time_time_Time* _con_x2425 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_0_2 = _con_x2425->date;
          kk_std_time_date__clock _x_0_2 = _con_x2425->clock;
          kk_std_time_calendar__calendar _pat_7_2 = _con_x2425->calendar;
          kk_std_time_duration__duration _pat_16_2 = _con_x2425->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2 = _con_x2425->timezone;
          kk_std_time_instant__instant _pat_23_2 = _con_x2425->instant;
          struct kk_std_time_date_Clock* _con_x2426 = kk_std_time_date__as_Clock(_x_0_2, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x2427 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x2428 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
          kk_string_t _pat_18_2 = _con_x2425->tzabbrv;
          kk_string_t _pat_8_2 = _con_x2427->name;
          kk_string_t _pat_9_2 = _con_x2427->long_name;
          kk_string_t _pat_10_2 = _con_x2427->month_prefix;
          kk_function_t _pat_11_2 = _con_x2427->show_era;
          kk_function_t _pat_12_2 = _con_x2427->instant_to_dc;
          kk_function_t _pat_13_2 = _con_x2427->dc_to_instant;
          kk_function_t _pat_14_2 = _con_x2427->days_to_date;
          kk_function_t _pat_15_2 = _con_x2427->date_to_days;
          kk_string_t _pat_20_2 = _con_x2428->name;
          kk_function_t _pat_21_2 = _con_x2428->utc_delta;
          kk_function_t _pat_22_2 = _con_x2428->utc_inverse;
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
            struct kk_std_time_date_Clock* _con_x2429 = kk_std_time_date__as_Clock(_x_0_2, _ctx);
            kk_std_num_ddouble__ddouble _pat_1_3 = _con_x2429->seconds;
            kk_integer_t _x_3 = _con_x2429->hours;
            kk_integer_t _pat_0_4 = _con_x2429->minutes;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_2, _ctx)) {
              kk_integer_drop(_pat_0_4, _ctx);
              kk_datatype_ptr_free(_x_0_2, _ctx);
            }
            else {
              kk_integer_dup(_x_3, _ctx);
              kk_datatype_ptr_decref(_x_0_2, _ctx);
            }
            _x_x2424 = _x_3; /*int*/
          }
        }
        s_10138 = kk_std_core_int_show(_x_x2424, _ctx); /*string*/
        kk_integer_t n_0;
        kk_string_t _x_x2430 = kk_string_dup(s_10138, _ctx); /*string*/
        n_0 = kk_std_core_string_chars_fs_count(_x_x2430, _ctx); /*int*/
        bool _match_x1346 = kk_integer_lte_borrow(n,n_0,kk_context()); /*bool*/;
        if (_match_x1346) {
          kk_integer_drop(n_0, _ctx);
          kk_integer_drop(n, _ctx);
          return s_10138;
        }
        {
          kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
          kk_integer_t n_0_10012 = kk_integer_sub(n,n_0,kk_context()); /*int*/;
          kk_string_t _x_x2431 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x2431, s_10138, _ctx);
        }
      }
      {
        kk_integer_t i_0_10141;
        kk_integer_t _x_x2432;
        {
          struct kk_std_time_time_Time* _con_x2433 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_0_3 = _con_x2433->date;
          kk_std_time_date__clock _x_0_3 = _con_x2433->clock;
          kk_std_time_calendar__calendar _pat_7_3 = _con_x2433->calendar;
          kk_std_time_duration__duration _pat_16_3 = _con_x2433->tzdelta;
          kk_std_time_calendar__timezone _pat_19_3 = _con_x2433->timezone;
          kk_std_time_instant__instant _pat_23_3 = _con_x2433->instant;
          struct kk_std_time_date_Clock* _con_x2434 = kk_std_time_date__as_Clock(_x_0_3, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x2435 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x2436 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
          kk_string_t _pat_18_3 = _con_x2433->tzabbrv;
          kk_string_t _pat_8_3 = _con_x2435->name;
          kk_string_t _pat_9_3 = _con_x2435->long_name;
          kk_string_t _pat_10_3 = _con_x2435->month_prefix;
          kk_function_t _pat_11_3 = _con_x2435->show_era;
          kk_function_t _pat_12_3 = _con_x2435->instant_to_dc;
          kk_function_t _pat_13_3 = _con_x2435->dc_to_instant;
          kk_function_t _pat_14_3 = _con_x2435->days_to_date;
          kk_function_t _pat_15_3 = _con_x2435->date_to_days;
          kk_string_t _pat_20_3 = _con_x2436->name;
          kk_function_t _pat_21_3 = _con_x2436->utc_delta;
          kk_function_t _pat_22_3 = _con_x2436->utc_inverse;
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
            struct kk_std_time_date_Clock* _con_x2437 = kk_std_time_date__as_Clock(_x_0_3, _ctx);
            kk_std_num_ddouble__ddouble _pat_1_4 = _con_x2437->seconds;
            kk_integer_t _x_4 = _con_x2437->hours;
            kk_integer_t _pat_0_5 = _con_x2437->minutes;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_3, _ctx)) {
              kk_integer_drop(_pat_0_5, _ctx);
              kk_datatype_ptr_free(_x_0_3, _ctx);
            }
            else {
              kk_integer_dup(_x_4, _ctx);
              kk_datatype_ptr_decref(_x_0_3, _ctx);
            }
            _x_x2432 = _x_4; /*int*/
          }
        }
        i_0_10141 = kk_integer_add_small_const(_x_x2432, -12, _ctx); /*int*/
        kk_string_t s_0_10145 = kk_std_core_int_show(i_0_10141, _ctx); /*string*/;
        kk_integer_t n_1;
        kk_string_t _x_x2438 = kk_string_dup(s_0_10145, _ctx); /*string*/
        n_1 = kk_std_core_string_chars_fs_count(_x_x2438, _ctx); /*int*/
        bool _match_x1345 = kk_integer_lte_borrow(n,n_1,kk_context()); /*bool*/;
        if (_match_x1345) {
          kk_integer_drop(n_1, _ctx);
          kk_integer_drop(n, _ctx);
          return s_0_10145;
        }
        {
          kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
          kk_integer_t n_0_10012_0 = kk_integer_sub(n,n_1,kk_context()); /*int*/;
          kk_string_t _x_x2439 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x2439, s_0_10145, _ctx);
        }
      }
    }
  }
}

kk_string_t kk_std_time_format_format_frac(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_std_num_ddouble__ddouble y_10247;
  bool _match_x1341;
  double _x_x2441;
  {
    struct kk_std_time_time_Time* _con_x2442 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_1 = _con_x2442->date;
    kk_std_time_date__clock _x_0_1 = _con_x2442->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2442->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2442->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2442->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2442->instant;
    struct kk_std_time_date_Clock* _con_x2443 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2444 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2445 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__clock_dup(_x_0_1, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x2446 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x2446->seconds;
      kk_integer_t _pat_0_2 = _con_x2446->hours;
      kk_integer_t _pat_1_1 = _con_x2446->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
        kk_integer_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_x_0_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0_1, _ctx);
      }
      {
        double _x = _x_1.hi;
        _x_x2441 = _x; /*float64*/
      }
    }
  }
  _match_x1341 = (_x_x2441 < (0x0p+0)); /*bool*/
  if (_match_x1341) {
    kk_std_num_ddouble__ddouble _x_x2447;
    {
      struct kk_std_time_time_Time* _con_x2448 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_0 = _con_x2448->date;
      kk_std_time_date__clock _x_0_1_0 = _con_x2448->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x2448->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2448->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2448->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2448->instant;
      struct kk_std_time_date_Clock* _con_x2449 = kk_std_time_date__as_Clock(_x_0_1_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2450 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2451 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__clock_dup(_x_0_1_0, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2452 = kk_std_time_date__as_Clock(_x_0_1_0, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0 = _con_x2452->seconds;
        kk_integer_t _pat_0_2_0 = _con_x2452->hours;
        kk_integer_t _pat_1_1_0 = _con_x2452->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_0, _ctx)) {
          kk_integer_drop(_pat_1_1_0, _ctx);
          kk_integer_drop(_pat_0_2_0, _ctx);
          kk_datatype_ptr_free(_x_0_1_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1_0, _ctx);
        }
        _x_x2447 = _x_1_0; /*std/num/ddouble/ddouble*/
      }
    }
    y_10247 = kk_std_num_ddouble_ceiling(_x_x2447, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2453;
    {
      struct kk_std_time_time_Time* _con_x2454 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_1 = _con_x2454->date;
      kk_std_time_date__clock _x_0_1_1 = _con_x2454->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x2454->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x2454->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x2454->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x2454->instant;
      struct kk_std_time_date_Clock* _con_x2455 = kk_std_time_date__as_Clock(_x_0_1_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2456 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2457 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_date__clock_dup(_x_0_1_1, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2458 = kk_std_time_date__as_Clock(_x_0_1_1, _ctx);
        kk_std_num_ddouble__ddouble _x_1_1 = _con_x2458->seconds;
        kk_integer_t _pat_0_2_1 = _con_x2458->hours;
        kk_integer_t _pat_1_1_1 = _con_x2458->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_1, _ctx)) {
          kk_integer_drop(_pat_1_1_1, _ctx);
          kk_integer_drop(_pat_0_2_1, _ctx);
          kk_datatype_ptr_free(_x_0_1_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1_1, _ctx);
        }
        _x_x2453 = _x_1_1; /*std/num/ddouble/ddouble*/
      }
    }
    y_10247 = kk_std_num_ddouble_floor(_x_x2453, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x2459;
  {
    struct kk_std_time_time_Time* _con_x2460 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_1_2 = _con_x2460->date;
    kk_std_time_date__clock _x_0_1_2 = _con_x2460->clock;
    kk_std_time_calendar__calendar _pat_7_2 = _con_x2460->calendar;
    kk_std_time_duration__duration _pat_16_2 = _con_x2460->tzdelta;
    kk_std_time_calendar__timezone _pat_19_2 = _con_x2460->timezone;
    kk_std_time_instant__instant _pat_23_2 = _con_x2460->instant;
    struct kk_std_time_date_Clock* _con_x2461 = kk_std_time_date__as_Clock(_x_0_1_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2462 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2463 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
    kk_string_t _pat_18_2 = _con_x2460->tzabbrv;
    kk_string_t _pat_8_2 = _con_x2462->name;
    kk_string_t _pat_9_2 = _con_x2462->long_name;
    kk_string_t _pat_10_2 = _con_x2462->month_prefix;
    kk_function_t _pat_11_2 = _con_x2462->show_era;
    kk_function_t _pat_12_2 = _con_x2462->instant_to_dc;
    kk_function_t _pat_13_2 = _con_x2462->dc_to_instant;
    kk_function_t _pat_14_2 = _con_x2462->days_to_date;
    kk_function_t _pat_15_2 = _con_x2462->date_to_days;
    kk_string_t _pat_20_2 = _con_x2463->name;
    kk_function_t _pat_21_2 = _con_x2463->utc_delta;
    kk_function_t _pat_22_2 = _con_x2463->utc_inverse;
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
      kk_std_time_date__date_drop(_pat_0_0_1_2, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0_1_2, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x2464 = kk_std_time_date__as_Clock(_x_0_1_2, _ctx);
      kk_std_num_ddouble__ddouble _x_1_2 = _con_x2464->seconds;
      kk_integer_t _pat_0_2_2 = _con_x2464->hours;
      kk_integer_t _pat_1_1_2 = _con_x2464->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_2, _ctx)) {
        kk_integer_drop(_pat_1_1_2, _ctx);
        kk_integer_drop(_pat_0_2_2, _ctx);
        kk_datatype_ptr_free(_x_0_1_2, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0_1_2, _ctx);
      }
      _x_x2459 = _x_1_2; /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x2465;
  double _x_x2466;
  double _x_x2467;
  {
    double _x_0 = y_10247.hi;
    _x_x2467 = _x_0; /*float64*/
  }
  _x_x2466 = (-_x_x2467); /*float64*/
  double _x_x2468;
  double _x_x2469;
  {
    double _x_0_0 = y_10247.lo;
    _x_x2469 = _x_0_0; /*float64*/
  }
  _x_x2468 = (-_x_x2469); /*float64*/
  _x_x2465 = kk_std_num_ddouble__new_Ddouble(_x_x2466, _x_x2468, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x_x2459, _x_x2465, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x1340;
  double _x_x2470;
  {
    double _x_2 = frac.hi;
    _x_x2470 = _x_2; /*float64*/
  }
  _match_x1340 = (_x_x2470 == (0x0p+0)); /*bool*/
  if (_match_x1340) {
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    kk_integer_t _b_x559_560 = n; /*int*/;
    kk_string_t _x_x2472;
    kk_std_core_types__optional _x_x2473 = kk_std_core_types__new_Optional(kk_integer_box(_b_x559_560, _ctx), _ctx); /*? 10003*/
    _x_x2472 = kk_std_num_ddouble_show_fixed(frac, _x_x2473, _ctx); /*string*/
    return kk_std_core_sslice_tail(_x_x2472, _ctx);
  }
}

kk_string_t kk_std_time_format_format_frac0(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_std_num_ddouble__ddouble y_10247;
  bool _match_x1339;
  double _x_x2474;
  {
    struct kk_std_time_time_Time* _con_x2475 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_1 = _con_x2475->date;
    kk_std_time_date__clock _x_0_1 = _con_x2475->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2475->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2475->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2475->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2475->instant;
    struct kk_std_time_date_Clock* _con_x2476 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2477 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2478 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__clock_dup(_x_0_1, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x2479 = kk_std_time_date__as_Clock(_x_0_1, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x2479->seconds;
      kk_integer_t _pat_0_2 = _con_x2479->hours;
      kk_integer_t _pat_1_1 = _con_x2479->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
        kk_integer_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_x_0_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0_1, _ctx);
      }
      {
        double _x = _x_1.hi;
        _x_x2474 = _x; /*float64*/
      }
    }
  }
  _match_x1339 = (_x_x2474 < (0x0p+0)); /*bool*/
  if (_match_x1339) {
    kk_std_num_ddouble__ddouble _x_x2480;
    {
      struct kk_std_time_time_Time* _con_x2481 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_0 = _con_x2481->date;
      kk_std_time_date__clock _x_0_1_0 = _con_x2481->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x2481->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2481->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2481->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2481->instant;
      struct kk_std_time_date_Clock* _con_x2482 = kk_std_time_date__as_Clock(_x_0_1_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2483 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2484 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__clock_dup(_x_0_1_0, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2485 = kk_std_time_date__as_Clock(_x_0_1_0, _ctx);
        kk_std_num_ddouble__ddouble _x_1_0 = _con_x2485->seconds;
        kk_integer_t _pat_0_2_0 = _con_x2485->hours;
        kk_integer_t _pat_1_1_0 = _con_x2485->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_0, _ctx)) {
          kk_integer_drop(_pat_1_1_0, _ctx);
          kk_integer_drop(_pat_0_2_0, _ctx);
          kk_datatype_ptr_free(_x_0_1_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1_0, _ctx);
        }
        _x_x2480 = _x_1_0; /*std/num/ddouble/ddouble*/
      }
    }
    y_10247 = kk_std_num_ddouble_ceiling(_x_x2480, _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x2486;
    {
      struct kk_std_time_time_Time* _con_x2487 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_1_1 = _con_x2487->date;
      kk_std_time_date__clock _x_0_1_1 = _con_x2487->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x2487->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x2487->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x2487->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x2487->instant;
      struct kk_std_time_date_Clock* _con_x2488 = kk_std_time_date__as_Clock(_x_0_1_1, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2489 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2490 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_date__clock_dup(_x_0_1_1, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2491 = kk_std_time_date__as_Clock(_x_0_1_1, _ctx);
        kk_std_num_ddouble__ddouble _x_1_1 = _con_x2491->seconds;
        kk_integer_t _pat_0_2_1 = _con_x2491->hours;
        kk_integer_t _pat_1_1_1 = _con_x2491->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_1, _ctx)) {
          kk_integer_drop(_pat_1_1_1, _ctx);
          kk_integer_drop(_pat_0_2_1, _ctx);
          kk_datatype_ptr_free(_x_0_1_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_1_1, _ctx);
        }
        _x_x2486 = _x_1_1; /*std/num/ddouble/ddouble*/
      }
    }
    y_10247 = kk_std_num_ddouble_floor(_x_x2486, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x2492;
  {
    struct kk_std_time_time_Time* _con_x2493 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0_1_2 = _con_x2493->date;
    kk_std_time_date__clock _x_0_1_2 = _con_x2493->clock;
    kk_std_time_calendar__calendar _pat_7_2 = _con_x2493->calendar;
    kk_std_time_duration__duration _pat_16_2 = _con_x2493->tzdelta;
    kk_std_time_calendar__timezone _pat_19_2 = _con_x2493->timezone;
    kk_std_time_instant__instant _pat_23_2 = _con_x2493->instant;
    struct kk_std_time_date_Clock* _con_x2494 = kk_std_time_date__as_Clock(_x_0_1_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2495 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2496 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
    kk_string_t _pat_18_2 = _con_x2493->tzabbrv;
    kk_string_t _pat_8_2 = _con_x2495->name;
    kk_string_t _pat_9_2 = _con_x2495->long_name;
    kk_string_t _pat_10_2 = _con_x2495->month_prefix;
    kk_function_t _pat_11_2 = _con_x2495->show_era;
    kk_function_t _pat_12_2 = _con_x2495->instant_to_dc;
    kk_function_t _pat_13_2 = _con_x2495->dc_to_instant;
    kk_function_t _pat_14_2 = _con_x2495->days_to_date;
    kk_function_t _pat_15_2 = _con_x2495->date_to_days;
    kk_string_t _pat_20_2 = _con_x2496->name;
    kk_function_t _pat_21_2 = _con_x2496->utc_delta;
    kk_function_t _pat_22_2 = _con_x2496->utc_inverse;
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
      kk_std_time_date__date_drop(_pat_0_0_1_2, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(_x_0_1_2, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      struct kk_std_time_date_Clock* _con_x2497 = kk_std_time_date__as_Clock(_x_0_1_2, _ctx);
      kk_std_num_ddouble__ddouble _x_1_2 = _con_x2497->seconds;
      kk_integer_t _pat_0_2_2 = _con_x2497->hours;
      kk_integer_t _pat_1_1_2 = _con_x2497->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_2, _ctx)) {
        kk_integer_drop(_pat_1_1_2, _ctx);
        kk_integer_drop(_pat_0_2_2, _ctx);
        kk_datatype_ptr_free(_x_0_1_2, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0_1_2, _ctx);
      }
      _x_x2492 = _x_1_2; /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x2498;
  double _x_x2499;
  double _x_x2500;
  {
    double _x_0 = y_10247.hi;
    _x_x2500 = _x_0; /*float64*/
  }
  _x_x2499 = (-_x_x2500); /*float64*/
  double _x_x2501;
  double _x_x2502;
  {
    double _x_0_0 = y_10247.lo;
    _x_x2502 = _x_0_0; /*float64*/
  }
  _x_x2501 = (-_x_x2502); /*float64*/
  _x_x2498 = kk_std_num_ddouble__new_Ddouble(_x_x2499, _x_x2501, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x_x2492, _x_x2498, _ctx); /*std/num/ddouble/ddouble*/
  bool _match_x1337;
  double _x_x2503;
  {
    double _x_2 = frac.hi;
    _x_x2503 = _x_2; /*float64*/
  }
  _match_x1337 = (_x_x2503 == (0x0p+0)); /*bool*/
  if (_match_x1337) {
    kk_integer_drop(n, _ctx);
    return kk_string_empty();
  }
  {
    kk_string_t s_10154;
    kk_string_t _x_x2505;
    kk_std_core_types__optional _x_x2506;
    kk_box_t _x_x2507;
    kk_integer_t _x_x2508 = kk_integer_dup(n, _ctx); /*int*/
    _x_x2507 = kk_integer_box(_x_x2508, _ctx); /*10003*/
    _x_x2506 = kk_std_core_types__new_Optional(_x_x2507, _ctx); /*? 10003*/
    _x_x2505 = kk_std_num_ddouble_show_fixed(frac, _x_x2506, _ctx); /*string*/
    s_10154 = kk_std_core_sslice_tail(_x_x2505, _ctx); /*string*/
    kk_integer_t width_10155 = kk_integer_add_small_const(n, 1, _ctx); /*int*/;
    kk_integer_t n_0;
    kk_string_t _x_x2509 = kk_string_dup(s_10154, _ctx); /*string*/
    n_0 = kk_std_core_string_chars_fs_count(_x_x2509, _ctx); /*int*/
    bool _match_x1338 = kk_integer_lte_borrow(width_10155,n_0,kk_context()); /*bool*/;
    if (_match_x1338) {
      kk_integer_drop(width_10155, _ctx);
      kk_integer_drop(n_0, _ctx);
      return s_10154;
    }
    {
      kk_string_t s_0_10015 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
      kk_integer_t n_0_10016 = kk_integer_sub(width_10155,n_0,kk_context()); /*int*/;
      kk_string_t _x_x2510 = kk_std_core_string_repeatz(s_0_10015, kk_std_core_int_ssize__t(n_0_10016, _ctx), _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(s_10154, _x_x2510, _ctx);
    }
  }
}

kk_string_t kk_std_time_format_format_tz_offset(kk_std_time_time__time t, kk_integer_t n, kk_string_t hmsep, kk_string_t utc, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, hmsep : string, utc : string) -> string */ 
  kk_integer_drop(n, _ctx);
  kk_std_time_duration__duration _x_x2511;
  {
    struct kk_std_time_time_Time* _con_x2512 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2512->date;
    kk_std_time_date__clock _pat_4 = _con_x2512->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2512->calendar;
    kk_std_time_duration__duration _x = _con_x2512->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2512->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2512->instant;
    struct kk_std_time_date_Clock* _con_x2513 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2514 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2515 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2512->tzabbrv;
    kk_integer_t _pat_5 = _con_x2513->hours;
    kk_integer_t _pat_6 = _con_x2513->minutes;
    kk_string_t _pat_9 = _con_x2514->name;
    kk_string_t _pat_10 = _con_x2514->long_name;
    kk_string_t _pat_11 = _con_x2514->month_prefix;
    kk_function_t _pat_12 = _con_x2514->show_era;
    kk_function_t _pat_13 = _con_x2514->instant_to_dc;
    kk_function_t _pat_14 = _con_x2514->dc_to_instant;
    kk_function_t _pat_15 = _con_x2514->days_to_date;
    kk_function_t _pat_16 = _con_x2514->date_to_days;
    kk_string_t _pat_20 = _con_x2515->name;
    kk_function_t _pat_21 = _con_x2515->utc_delta;
    kk_function_t _pat_22 = _con_x2515->utc_inverse;
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
    _x_x2511 = _x; /*std/time/duration/duration*/
  }
  kk_std_core_types__optional _x_x2516 = kk_std_core_types__new_Optional(kk_string_box(utc), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2517 = kk_std_core_types__new_Optional(kk_string_box(hmsep), _ctx); /*? 10003*/
  return kk_std_time_time_show_tzdelta(_x_x2511, _x_x2516, _x_x2517, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_time_format_format_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t hmsep_10162;
  bool _match_x1336 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  if (_match_x1336) {
    hmsep_10162 = kk_string_empty(); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x2519, 1, ":", _ctx)
    hmsep_10162 = kk_string_dup(_s_x2519, _ctx); /*string*/
  }
  kk_string_t utc_10163;
  bool _match_x1334;
  bool _brw_x1335 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x1334 = _brw_x1335; /*bool*/
  if (_match_x1334) {
    kk_define_string_literal(, _s_x2520, 5, "+0000", _ctx)
    utc_10163 = kk_string_dup(_s_x2520, _ctx); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x2521, 6, "+00:00", _ctx)
    utc_10163 = kk_string_dup(_s_x2521, _ctx); /*string*/
  }
  kk_std_time_duration__duration _x_x2522;
  {
    struct kk_std_time_time_Time* _con_x2523 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2523->date;
    kk_std_time_date__clock _pat_4 = _con_x2523->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2523->calendar;
    kk_std_time_duration__duration _x = _con_x2523->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2523->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2523->instant;
    struct kk_std_time_date_Clock* _con_x2524 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2525 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2526 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2523->tzabbrv;
    kk_integer_t _pat_5 = _con_x2524->hours;
    kk_integer_t _pat_6 = _con_x2524->minutes;
    kk_string_t _pat_9 = _con_x2525->name;
    kk_string_t _pat_10 = _con_x2525->long_name;
    kk_string_t _pat_11 = _con_x2525->month_prefix;
    kk_function_t _pat_12 = _con_x2525->show_era;
    kk_function_t _pat_13 = _con_x2525->instant_to_dc;
    kk_function_t _pat_14 = _con_x2525->dc_to_instant;
    kk_function_t _pat_15 = _con_x2525->days_to_date;
    kk_function_t _pat_16 = _con_x2525->date_to_days;
    kk_string_t _pat_20 = _con_x2526->name;
    kk_function_t _pat_21 = _con_x2526->utc_delta;
    kk_function_t _pat_22 = _con_x2526->utc_inverse;
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
    _x_x2522 = _x; /*std/time/duration/duration*/
  }
  kk_std_core_types__optional _x_x2527 = kk_std_core_types__new_Optional(kk_string_box(utc_10163), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2528 = kk_std_core_types__new_Optional(kk_string_box(hmsep_10162), _ctx); /*? 10003*/
  return kk_std_time_time_show_tzdelta(_x_x2522, _x_x2527, _x_x2528, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_time_format_format_utc_timezone(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_string_t utc_10168;
  bool _match_x1332;
  bool _brw_x1333 = kk_integer_eq_borrow(n,(kk_integer_from_small(2)),kk_context()); /*bool*/;
  kk_integer_drop(n, _ctx);
  _match_x1332 = _brw_x1333; /*bool*/
  if (_match_x1332) {
    utc_10168 = kk_string_empty(); /*string*/
  }
  else {
    kk_define_string_literal(, _s_x2530, 1, "Z", _ctx)
    utc_10168 = kk_string_dup(_s_x2530, _ctx); /*string*/
  }
  kk_std_time_duration__duration _x_x2531;
  {
    struct kk_std_time_time_Time* _con_x2532 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2532->date;
    kk_std_time_date__clock _pat_4 = _con_x2532->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2532->calendar;
    kk_std_time_duration__duration _x = _con_x2532->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2532->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2532->instant;
    struct kk_std_time_date_Clock* _con_x2533 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2534 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2535 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2532->tzabbrv;
    kk_integer_t _pat_5 = _con_x2533->hours;
    kk_integer_t _pat_6 = _con_x2533->minutes;
    kk_string_t _pat_9 = _con_x2534->name;
    kk_string_t _pat_10 = _con_x2534->long_name;
    kk_string_t _pat_11 = _con_x2534->month_prefix;
    kk_function_t _pat_12 = _con_x2534->show_era;
    kk_function_t _pat_13 = _con_x2534->instant_to_dc;
    kk_function_t _pat_14 = _con_x2534->dc_to_instant;
    kk_function_t _pat_15 = _con_x2534->days_to_date;
    kk_function_t _pat_16 = _con_x2534->date_to_days;
    kk_string_t _pat_20 = _con_x2535->name;
    kk_function_t _pat_21 = _con_x2535->utc_delta;
    kk_function_t _pat_22 = _con_x2535->utc_inverse;
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
    _x_x2531 = _x; /*std/time/duration/duration*/
  }
  kk_std_core_types__optional _x_x2536 = kk_std_core_types__new_Optional(kk_string_box(utc_10168), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x2537;
  kk_box_t _x_x2538;
  kk_string_t _x_x2539;
  kk_define_string_literal(, _s_x2540, 1, ":", _ctx)
  _x_x2539 = kk_string_dup(_s_x2540, _ctx); /*string*/
  _x_x2538 = kk_string_box(_x_x2539); /*10003*/
  _x_x2537 = kk_std_core_types__new_Optional(_x_x2538, _ctx); /*? 10003*/
  return kk_std_time_time_show_tzdelta(_x_x2531, _x_x2536, _x_x2537, kk_std_core_types__new_None(_ctx), _ctx);
}

kk_string_t kk_std_time_format_format_timestamp(kk_std_time_time__time t, kk_integer_t n, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, n : int, locale : std/time/locale/time-locale) -> string */ 
  kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
  kk_integer_drop(n, _ctx);
  kk_std_time_instant__instant _x_x2541;
  {
    struct kk_std_time_time_Time* _con_x2542 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2542->date;
    kk_std_time_date__clock _pat_4 = _con_x2542->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2542->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2542->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x2542->timezone;
    kk_std_time_instant__instant _x = _con_x2542->instant;
    struct kk_std_time_date_Clock* _con_x2543 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2544 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2545 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x2542->tzabbrv;
    kk_integer_t _pat_5 = _con_x2543->hours;
    kk_integer_t _pat_6 = _con_x2543->minutes;
    kk_string_t _pat_9 = _con_x2544->name;
    kk_string_t _pat_10 = _con_x2544->long_name;
    kk_string_t _pat_11 = _con_x2544->month_prefix;
    kk_function_t _pat_12 = _con_x2544->show_era;
    kk_function_t _pat_13 = _con_x2544->instant_to_dc;
    kk_function_t _pat_14 = _con_x2544->dc_to_instant;
    kk_function_t _pat_15 = _con_x2544->days_to_date;
    kk_function_t _pat_16 = _con_x2544->date_to_days;
    kk_string_t _pat_21 = _con_x2545->name;
    kk_function_t _pat_22 = _con_x2545->utc_delta;
    kk_function_t _pat_23 = _con_x2545->utc_inverse;
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
    _x_x2541 = _x; /*std/time/instant/instant*/
  }
  kk_std_core_types__optional _x_x2546 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 10003*/
  return kk_std_time_instant_show_raw(_x_x2541, _x_x2546, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2549__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2549(kk_function_t _fself, kk_box_t _b_x584, kk_box_t _b_x585, kk_box_t _b_x586, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2549(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2549, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2549(kk_function_t _fself, kk_box_t _b_x584, kk_box_t _b_x585, kk_box_t _b_x586, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2550;
  kk_std_time_time__time _x_x2551 = kk_std_time_time__time_unbox(_b_x584, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2552 = kk_integer_unbox(_b_x585, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2553 = kk_std_time_locale__time_locale_unbox(_b_x586, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2550 = kk_std_time_format_format_year(_x_x2551, _x_x2552, _x_x2553, _ctx); /*string*/
  return kk_string_box(_x_x2550);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2557__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2557(kk_function_t _fself, kk_box_t _b_x594, kk_box_t _b_x595, kk_box_t _b_x596, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2557(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2557, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2557(kk_function_t _fself, kk_box_t _b_x594, kk_box_t _b_x595, kk_box_t _b_x596, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2558;
  kk_std_time_time__time _x_x2559 = kk_std_time_time__time_unbox(_b_x594, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2560 = kk_integer_unbox(_b_x595, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2561 = kk_std_time_locale__time_locale_unbox(_b_x596, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2558 = kk_std_time_format_format_month(_x_x2559, _x_x2560, _x_x2561, _ctx); /*string*/
  return kk_string_box(_x_x2558);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2565__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2565(kk_function_t _fself, kk_box_t _b_x604, kk_box_t _b_x605, kk_box_t _b_x606, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2565(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2565, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2565(kk_function_t _fself, kk_box_t _b_x604, kk_box_t _b_x605, kk_box_t _b_x606, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2566;
  kk_std_time_time__time _x_x2567 = kk_std_time_time__time_unbox(_b_x604, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2568 = kk_integer_unbox(_b_x605, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2569 = kk_std_time_locale__time_locale_unbox(_b_x606, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2566 = kk_std_time_format_format_day(_x_x2567, _x_x2568, _x_x2569, _ctx); /*string*/
  return kk_string_box(_x_x2566);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2573__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2573(kk_function_t _fself, kk_box_t _b_x614, kk_box_t _b_x615, kk_box_t _b_x616, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2573(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2573, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2573(kk_function_t _fself, kk_box_t _b_x614, kk_box_t _b_x615, kk_box_t _b_x616, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2574;
  kk_std_time_time__time _x_x2575 = kk_std_time_time__time_unbox(_b_x614, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2576 = kk_integer_unbox(_b_x615, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2577 = kk_std_time_locale__time_locale_unbox(_b_x616, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2574 = kk_std_time_format_format_hours(_x_x2575, _x_x2576, _x_x2577, _ctx); /*string*/
  return kk_string_box(_x_x2574);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2581__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2581(kk_function_t _fself, kk_box_t _b_x624, kk_box_t _b_x625, kk_box_t _b_x626, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2581(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2581, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2581(kk_function_t _fself, kk_box_t _b_x624, kk_box_t _b_x625, kk_box_t _b_x626, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2582;
  kk_std_time_time__time _x_x2583 = kk_std_time_time__time_unbox(_b_x624, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2584 = kk_integer_unbox(_b_x625, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2585 = kk_std_time_locale__time_locale_unbox(_b_x626, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2582 = kk_std_time_format_format_minutes(_x_x2583, _x_x2584, _x_x2585, _ctx); /*string*/
  return kk_string_box(_x_x2582);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2589__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2589(kk_function_t _fself, kk_box_t _b_x634, kk_box_t _b_x635, kk_box_t _b_x636, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2589(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2589, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2589(kk_function_t _fself, kk_box_t _b_x634, kk_box_t _b_x635, kk_box_t _b_x636, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2590;
  kk_std_time_time__time _x_x2591 = kk_std_time_time__time_unbox(_b_x634, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2592 = kk_integer_unbox(_b_x635, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2593 = kk_std_time_locale__time_locale_unbox(_b_x636, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2590 = kk_std_time_format_format_seconds(_x_x2591, _x_x2592, _x_x2593, _ctx); /*string*/
  return kk_string_box(_x_x2590);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2597__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2597(kk_function_t _fself, kk_box_t _b_x644, kk_box_t _b_x645, kk_box_t _b_x646, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2597(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2597, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2597(kk_function_t _fself, kk_box_t _b_x644, kk_box_t _b_x645, kk_box_t _b_x646, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2598;
  kk_std_time_time__time _x_x2599 = kk_std_time_time__time_unbox(_b_x644, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2600 = kk_integer_unbox(_b_x645, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2601 = kk_std_time_locale__time_locale_unbox(_b_x646, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2598 = kk_std_time_format_format_timezone(_x_x2599, _x_x2600, _x_x2601, _ctx); /*string*/
  return kk_string_box(_x_x2598);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2605__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2605(kk_function_t _fself, kk_box_t _b_x654, kk_box_t _b_x655, kk_box_t _b_x656, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2605(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2605, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2605(kk_function_t _fself, kk_box_t _b_x654, kk_box_t _b_x655, kk_box_t _b_x656, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2606;
  kk_std_time_time__time _x_x2607 = kk_std_time_time__time_unbox(_b_x654, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2608 = kk_integer_unbox(_b_x655, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2609 = kk_std_time_locale__time_locale_unbox(_b_x656, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2606 = kk_std_time_format_format_utc_timezone(_x_x2607, _x_x2608, _x_x2609, _ctx); /*string*/
  return kk_string_box(_x_x2606);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2613__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2613(kk_function_t _fself, kk_box_t _b_x664, kk_box_t _b_x665, kk_box_t _b_x666, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2613(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2613, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2613(kk_function_t _fself, kk_box_t _b_x664, kk_box_t _b_x665, kk_box_t _b_x666, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2614;
  kk_std_time_time__time _x_x2615 = kk_std_time_time__time_unbox(_b_x664, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2616 = kk_integer_unbox(_b_x665, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2617 = kk_std_time_locale__time_locale_unbox(_b_x666, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2614 = kk_std_time_format_format_frac0(_x_x2615, _x_x2616, _x_x2617, _ctx); /*string*/
  return kk_string_box(_x_x2614);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2621__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2621(kk_function_t _fself, kk_box_t _b_x674, kk_box_t _b_x675, kk_box_t _b_x676, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2621(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2621, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2621(kk_function_t _fself, kk_box_t _b_x674, kk_box_t _b_x675, kk_box_t _b_x676, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2622;
  kk_std_time_time__time _x_x2623 = kk_std_time_time__time_unbox(_b_x674, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2624 = kk_integer_unbox(_b_x675, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2625 = kk_std_time_locale__time_locale_unbox(_b_x676, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2622 = kk_std_time_format_format_frac(_x_x2623, _x_x2624, _x_x2625, _ctx); /*string*/
  return kk_string_box(_x_x2622);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2629__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2629(kk_function_t _fself, kk_box_t _b_x684, kk_box_t _b_x685, kk_box_t _b_x686, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2629(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2629, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2629(kk_function_t _fself, kk_box_t _b_x684, kk_box_t _b_x685, kk_box_t _b_x686, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2630;
  kk_std_time_time__time _x_x2631 = kk_std_time_time__time_unbox(_b_x684, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2632 = kk_integer_unbox(_b_x685, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2633 = kk_std_time_locale__time_locale_unbox(_b_x686, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2630 = kk_std_time_format_format_calname(_x_x2631, _x_x2632, _x_x2633, _ctx); /*string*/
  return kk_string_box(_x_x2630);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2637__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2637(kk_function_t _fself, kk_box_t _b_x694, kk_box_t _b_x695, kk_box_t _b_x696, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2637(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2637, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2637(kk_function_t _fself, kk_box_t _b_x694, kk_box_t _b_x695, kk_box_t _b_x696, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2638;
  kk_std_time_time__time _x_x2639 = kk_std_time_time__time_unbox(_b_x694, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2640 = kk_integer_unbox(_b_x695, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2641 = kk_std_time_locale__time_locale_unbox(_b_x696, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2638 = kk_std_time_format_format_era(_x_x2639, _x_x2640, _x_x2641, _ctx); /*string*/
  return kk_string_box(_x_x2638);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2645__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2645(kk_function_t _fself, kk_box_t _b_x704, kk_box_t _b_x705, kk_box_t _b_x706, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2645(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2645, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2645(kk_function_t _fself, kk_box_t _b_x704, kk_box_t _b_x705, kk_box_t _b_x706, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2646;
  kk_std_time_time__time _x_x2647 = kk_std_time_time__time_unbox(_b_x704, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2648 = kk_integer_unbox(_b_x705, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2649 = kk_std_time_locale__time_locale_unbox(_b_x706, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2646 = kk_std_time_format_format_absyear(_x_x2647, _x_x2648, _x_x2649, _ctx); /*string*/
  return kk_string_box(_x_x2646);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2653__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2653(kk_function_t _fself, kk_box_t _b_x714, kk_box_t _b_x715, kk_box_t _b_x716, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2653(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2653, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2653(kk_function_t _fself, kk_box_t _b_x714, kk_box_t _b_x715, kk_box_t _b_x716, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2654;
  kk_std_time_time__time _x_x2655 = kk_std_time_time__time_unbox(_b_x714, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2656 = kk_integer_unbox(_b_x715, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2657 = kk_std_time_locale__time_locale_unbox(_b_x716, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2654 = kk_std_time_format_format_weekday(_x_x2655, _x_x2656, _x_x2657, _ctx); /*string*/
  return kk_string_box(_x_x2654);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2661__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2661(kk_function_t _fself, kk_box_t _b_x724, kk_box_t _b_x725, kk_box_t _b_x726, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2661(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2661, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2661(kk_function_t _fself, kk_box_t _b_x724, kk_box_t _b_x725, kk_box_t _b_x726, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2662;
  kk_std_time_time__time _x_x2663 = kk_std_time_time__time_unbox(_b_x724, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2664 = kk_integer_unbox(_b_x725, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2665 = kk_std_time_locale__time_locale_unbox(_b_x726, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2662 = kk_std_time_format_format_hours12(_x_x2663, _x_x2664, _x_x2665, _ctx); /*string*/
  return kk_string_box(_x_x2662);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2669__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2669(kk_function_t _fself, kk_box_t _b_x734, kk_box_t _b_x735, kk_box_t _b_x736, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2669(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2669, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2669(kk_function_t _fself, kk_box_t _b_x734, kk_box_t _b_x735, kk_box_t _b_x736, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2670;
  kk_std_time_time__time _x_x2671 = kk_std_time_time__time_unbox(_b_x734, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2672 = kk_integer_unbox(_b_x735, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2673 = kk_std_time_locale__time_locale_unbox(_b_x736, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2670 = kk_std_time_format_format_ampm(_x_x2671, _x_x2672, _x_x2673, _ctx); /*string*/
  return kk_string_box(_x_x2670);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2677__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2677(kk_function_t _fself, kk_box_t _b_x744, kk_box_t _b_x745, kk_box_t _b_x746, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2677(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2677, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2677(kk_function_t _fself, kk_box_t _b_x744, kk_box_t _b_x745, kk_box_t _b_x746, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2678;
  kk_std_time_time__time _x_x2679 = kk_std_time_time__time_unbox(_b_x744, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2680 = kk_integer_unbox(_b_x745, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2681 = kk_std_time_locale__time_locale_unbox(_b_x746, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2678 = kk_std_time_format_format_upper_ampm(_x_x2679, _x_x2680, _x_x2681, _ctx); /*string*/
  return kk_string_box(_x_x2678);
}


// lift anonymous function
struct kk_std_time_format_formats_fun2685__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_formats_fun2685(kk_function_t _fself, kk_box_t _b_x754, kk_box_t _b_x755, kk_box_t _b_x756, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_formats_fun2685(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_formats_fun2685, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_formats_fun2685(kk_function_t _fself, kk_box_t _b_x754, kk_box_t _b_x755, kk_box_t _b_x756, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2686;
  kk_std_time_time__time _x_x2687 = kk_std_time_time__time_unbox(_b_x754, KK_OWNED, _ctx); /*std/time/time/time*/
  kk_integer_t _x_x2688 = kk_integer_unbox(_b_x755, _ctx); /*int*/
  kk_std_time_locale__time_locale _x_x2689 = kk_std_time_locale__time_locale_unbox(_b_x756, KK_OWNED, _ctx); /*std/time/locale/time-locale*/
  _x_x2686 = kk_std_time_format_format_timestamp(_x_x2687, _x_x2688, _x_x2689, _ctx); /*string*/
  return kk_string_box(_x_x2686);
}

kk_std_core_types__list kk_std_time_format_formats;
 
// lifted local: @lift-format-pat@10530, format-pat, @spec-x10467
// specialized: std/core/list/@unroll-lift-span@5738@10025, on parameters @uniq-predicate@10455, using:
// @uniq-predicate@10455 = fn(c: char){
//   std/core/char/(!=)(c, h);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10531(kk_char_t h, kk_std_core_types__list _uniq_ys_10456, kk_std_core_types__cctx _uniq_acc_10457, kk_context_t* _ctx) { /* (h : char, list<char>, cctx<list<char>,list<char>>) -> (list<char>, list<char>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10456, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2690 = kk_std_core_types__as_Cons(_uniq_ys_10456, _ctx);
    kk_box_t _box_x883 = _con_x2690->head;
    kk_std_core_types__list _uniq_yy_10460 = _con_x2690->tail;
    kk_char_t _uniq_y_10459 = kk_char_unbox(_box_x883, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_yy_10460, _ctx);
    bool _match_x1331 = (_uniq_y_10459 != h); /*bool*/;
    if (_match_x1331) {
      kk_reuse_t _ru_x1710 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10456, _ctx)) {
        kk_std_core_types__list_drop(_uniq_yy_10460, _ctx);
        _ru_x1710 = (kk_datatype_ptr_reuse(_uniq_ys_10456, _ctx));
      }
      else {
        kk_datatype_ptr_decref(_uniq_ys_10456, _ctx);
      }
      kk_std_core_types__list _b_x885_887 = kk_datatype_null(); /*list<char>*/;
      kk_std_core_types__list _uniq_cctx_x4824_10462 = kk_std_core_types__new_Cons(_ru_x1710, 0, kk_char_box(_uniq_y_10459, _ctx), _b_x885_887, _ctx); /*list<char>*/;
      kk_field_addr_t _uniq_cctx_x4825_10463 = kk_field_addr_create(&kk_std_core_types__as_Cons(_uniq_cctx_x4824_10462, _ctx)->tail, _ctx); /*@field-addr<list<char>>*/;
      kk_std_core_types__cctx _uniq_acc_0_10118_10464;
      kk_std_core_types__cctx _x_x2691 = kk_cctx_create((kk_std_core_types__list_box(_uniq_cctx_x4824_10462, _ctx)),_uniq_cctx_x4825_10463,kk_context()); /*cctx<10000,10001>*/
      _uniq_acc_0_10118_10464 = kk_cctx_compose(_uniq_acc_10457,_x_x2691,kk_context()); /*cctx<list<char>,list<char>>*/
      { // tailcall
        _uniq_ys_10456 = _uniq_yy_10460;
        _uniq_acc_10457 = _uniq_acc_0_10118_10464;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(_uniq_yy_10460, _ctx);
      kk_std_core_types__list _b_x900_906;
      kk_box_t _x_x2692 = kk_cctx_apply(_uniq_acc_10457,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
      _b_x900_906 = kk_std_core_types__list_unbox(_x_x2692, KK_OWNED, _ctx); /*list<char>*/
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x900_906, _ctx), kk_std_core_types__list_box(_uniq_ys_10456, _ctx), _ctx);
    }
  }
  {
    kk_std_core_types__list _b_x904_910;
    kk_box_t _x_x2693 = kk_cctx_apply(_uniq_acc_10457,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
    _b_x904_910 = kk_std_core_types__list_unbox(_x_x2693, KK_OWNED, _ctx); /*list<char>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x904_910, _ctx), kk_std_core_types__list_box(_uniq_ys_10456, _ctx), _ctx);
  }
}
 
// lifted local: format-pat, @spec-x10454
// specialized: std/core/list/span, on parameters @uniq-predicate@10450, using:
// @uniq-predicate@10450 = fn(c: char){
//   std/core/char/(!=)(c, h);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10530(kk_char_t h, kk_std_core_types__list _uniq_xs_10449, kk_context_t* _ctx) { /* (h : char, list<char>) -> (list<char>, list<char>) */ 
  kk_std_core_types__cctx _uniq_acc_10451 = kk_cctx_empty(kk_context()); /*cctx<list<char>,list<char>>*/;
  if (kk_std_core_types__is_Nil(_uniq_xs_10449, _ctx)) {
    kk_std_core_types__list _b_x916_918;
    kk_box_t _x_x2694 = kk_cctx_apply(_uniq_acc_10451,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
    _b_x916_918 = kk_std_core_types__list_unbox(_x_x2694, KK_OWNED, _ctx); /*list<char>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x916_918, _ctx), kk_std_core_types__list_box(_uniq_xs_10449, _ctx), _ctx);
  }
  {
    return kk_std_time_format__lift_format_pat_10531(h, _uniq_xs_10449, _uniq_acc_10451, _ctx);
  }
}
 
// lifted local: @lift-format-pat@10532, format-pat, @spec-x10487
// specialized: std/core/list/@unroll-lift-span@5738@10025, on parameters @uniq-predicate@10475, using:
// @uniq-predicate@10475 = fn(c@0: char){
//   std/core/char/(!=)(c@0, h);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10533(kk_char_t h, kk_std_core_types__list _uniq_ys_10476, kk_std_core_types__cctx _uniq_acc_10477, kk_context_t* _ctx) { /* (h : char, list<char>, cctx<list<char>,list<char>>) -> (list<char>, list<char>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10476, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2695 = kk_std_core_types__as_Cons(_uniq_ys_10476, _ctx);
    kk_box_t _box_x922 = _con_x2695->head;
    kk_std_core_types__list _uniq_yy_10480 = _con_x2695->tail;
    kk_char_t _uniq_y_10479 = kk_char_unbox(_box_x922, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_yy_10480, _ctx);
    bool _match_x1330 = (_uniq_y_10479 != h); /*bool*/;
    if (_match_x1330) {
      kk_reuse_t _ru_x1711 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10476, _ctx)) {
        kk_std_core_types__list_drop(_uniq_yy_10480, _ctx);
        _ru_x1711 = (kk_datatype_ptr_reuse(_uniq_ys_10476, _ctx));
      }
      else {
        kk_datatype_ptr_decref(_uniq_ys_10476, _ctx);
      }
      kk_std_core_types__list _b_x924_926 = kk_datatype_null(); /*list<char>*/;
      kk_std_core_types__list _uniq_cctx_x4824_10482 = kk_std_core_types__new_Cons(_ru_x1711, 0, kk_char_box(_uniq_y_10479, _ctx), _b_x924_926, _ctx); /*list<char>*/;
      kk_field_addr_t _uniq_cctx_x4825_10483 = kk_field_addr_create(&kk_std_core_types__as_Cons(_uniq_cctx_x4824_10482, _ctx)->tail, _ctx); /*@field-addr<list<char>>*/;
      kk_std_core_types__cctx _uniq_acc_0_10118_10484;
      kk_std_core_types__cctx _x_x2696 = kk_cctx_create((kk_std_core_types__list_box(_uniq_cctx_x4824_10482, _ctx)),_uniq_cctx_x4825_10483,kk_context()); /*cctx<10000,10001>*/
      _uniq_acc_0_10118_10484 = kk_cctx_compose(_uniq_acc_10477,_x_x2696,kk_context()); /*cctx<list<char>,list<char>>*/
      { // tailcall
        _uniq_ys_10476 = _uniq_yy_10480;
        _uniq_acc_10477 = _uniq_acc_0_10118_10484;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(_uniq_yy_10480, _ctx);
      kk_std_core_types__list _b_x939_945;
      kk_box_t _x_x2697 = kk_cctx_apply(_uniq_acc_10477,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
      _b_x939_945 = kk_std_core_types__list_unbox(_x_x2697, KK_OWNED, _ctx); /*list<char>*/
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x939_945, _ctx), kk_std_core_types__list_box(_uniq_ys_10476, _ctx), _ctx);
    }
  }
  {
    kk_std_core_types__list _b_x943_949;
    kk_box_t _x_x2698 = kk_cctx_apply(_uniq_acc_10477,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
    _b_x943_949 = kk_std_core_types__list_unbox(_x_x2698, KK_OWNED, _ctx); /*list<char>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x943_949, _ctx), kk_std_core_types__list_box(_uniq_ys_10476, _ctx), _ctx);
  }
}
 
// lifted local: format-pat, @spec-x10474
// specialized: std/core/list/span, on parameters @uniq-predicate@10470, using:
// @uniq-predicate@10470 = fn(c@0: char){
//   std/core/char/(!=)(c@0, h);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10532(kk_char_t h, kk_std_core_types__list _uniq_xs_10469, kk_context_t* _ctx) { /* (h : char, list<char>) -> (list<char>, list<char>) */ 
  kk_std_core_types__cctx _uniq_acc_10471 = kk_cctx_empty(kk_context()); /*cctx<list<char>,list<char>>*/;
  if (kk_std_core_types__is_Nil(_uniq_xs_10469, _ctx)) {
    kk_std_core_types__list _b_x955_957;
    kk_box_t _x_x2699 = kk_cctx_apply(_uniq_acc_10471,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
    _b_x955_957 = kk_std_core_types__list_unbox(_x_x2699, KK_OWNED, _ctx); /*list<char>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x955_957, _ctx), kk_std_core_types__list_box(_uniq_xs_10469, _ctx), _ctx);
  }
  {
    return kk_std_time_format__lift_format_pat_10533(h, _uniq_xs_10469, _uniq_acc_10471, _ctx);
  }
}
 
// lifted local: @lift-format-pat@10534, format-pat, @spec-x10507
// specialized: std/core/list/@unroll-lift-span@5738@10025, on parameters @uniq-predicate@10495, using:
// @uniq-predicate@10495 = fn(c@0@0: char){
//   std/core/char/(==)(c@0@0, h);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10535(kk_char_t h, kk_std_core_types__list _uniq_ys_10496, kk_std_core_types__cctx _uniq_acc_10497, kk_context_t* _ctx) { /* (h : char, list<char>, cctx<list<char>,list<char>>) -> (list<char>, list<char>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10496, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2700 = kk_std_core_types__as_Cons(_uniq_ys_10496, _ctx);
    kk_box_t _box_x961 = _con_x2700->head;
    kk_std_core_types__list _uniq_yy_10500 = _con_x2700->tail;
    kk_char_t _uniq_y_10499 = kk_char_unbox(_box_x961, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_yy_10500, _ctx);
    bool _match_x1329 = (_uniq_y_10499 == h); /*bool*/;
    if (_match_x1329) {
      kk_reuse_t _ru_x1712 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10496, _ctx)) {
        kk_std_core_types__list_drop(_uniq_yy_10500, _ctx);
        _ru_x1712 = (kk_datatype_ptr_reuse(_uniq_ys_10496, _ctx));
      }
      else {
        kk_datatype_ptr_decref(_uniq_ys_10496, _ctx);
      }
      kk_std_core_types__list _b_x963_965 = kk_datatype_null(); /*list<char>*/;
      kk_std_core_types__list _uniq_cctx_x4824_10502 = kk_std_core_types__new_Cons(_ru_x1712, 0, kk_char_box(_uniq_y_10499, _ctx), _b_x963_965, _ctx); /*list<char>*/;
      kk_field_addr_t _uniq_cctx_x4825_10503 = kk_field_addr_create(&kk_std_core_types__as_Cons(_uniq_cctx_x4824_10502, _ctx)->tail, _ctx); /*@field-addr<list<char>>*/;
      kk_std_core_types__cctx _uniq_acc_0_10118_10504;
      kk_std_core_types__cctx _x_x2701 = kk_cctx_create((kk_std_core_types__list_box(_uniq_cctx_x4824_10502, _ctx)),_uniq_cctx_x4825_10503,kk_context()); /*cctx<10000,10001>*/
      _uniq_acc_0_10118_10504 = kk_cctx_compose(_uniq_acc_10497,_x_x2701,kk_context()); /*cctx<list<char>,list<char>>*/
      { // tailcall
        _uniq_ys_10496 = _uniq_yy_10500;
        _uniq_acc_10497 = _uniq_acc_0_10118_10504;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(_uniq_yy_10500, _ctx);
      kk_std_core_types__list _b_x978_984;
      kk_box_t _x_x2702 = kk_cctx_apply(_uniq_acc_10497,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
      _b_x978_984 = kk_std_core_types__list_unbox(_x_x2702, KK_OWNED, _ctx); /*list<char>*/
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x978_984, _ctx), kk_std_core_types__list_box(_uniq_ys_10496, _ctx), _ctx);
    }
  }
  {
    kk_std_core_types__list _b_x982_988;
    kk_box_t _x_x2703 = kk_cctx_apply(_uniq_acc_10497,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
    _b_x982_988 = kk_std_core_types__list_unbox(_x_x2703, KK_OWNED, _ctx); /*list<char>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x982_988, _ctx), kk_std_core_types__list_box(_uniq_ys_10496, _ctx), _ctx);
  }
}
 
// lifted local: format-pat, @spec-x10494
// specialized: std/core/list/span, on parameters @uniq-predicate@10490, using:
// @uniq-predicate@10490 = fn(c@0@0: char){
//   std/core/char/(==)(c@0@0, h);
// }

kk_std_core_types__tuple2 kk_std_time_format__lift_format_pat_10534(kk_char_t h, kk_std_core_types__list _uniq_xs_10489, kk_context_t* _ctx) { /* (h : char, list<char>) -> (list<char>, list<char>) */ 
  kk_std_core_types__cctx _uniq_acc_10491 = kk_cctx_empty(kk_context()); /*cctx<list<char>,list<char>>*/;
  if (kk_std_core_types__is_Nil(_uniq_xs_10489, _ctx)) {
    kk_std_core_types__list _b_x994_996;
    kk_box_t _x_x2704 = kk_cctx_apply(_uniq_acc_10491,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*10000*/
    _b_x994_996 = kk_std_core_types__list_unbox(_x_x2704, KK_OWNED, _ctx); /*list<char>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x994_996, _ctx), kk_std_core_types__list_box(_uniq_xs_10489, _ctx), _ctx);
  }
  {
    return kk_std_time_format__lift_format_pat_10535(h, _uniq_xs_10489, _uniq_acc_10491, _ctx);
  }
}
 
// lifted local: @lift-format-pat@10536, format-pat, @spec-x10522
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10515, using:
// @uniq-action@10515 = fn(pattern: (char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)){
//   match (pattern) {
//     ((@skip std/core/types/Tuple3((c@1: char) : char, (m@0: int) : int, (f: (std/time/time/time, int, std/time/locale/time-locale) -> string) : (std/time/time/time, int, std/time/locale/time-locale) -> string) : (char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string) ) as @pat@9@0: (char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string))
//        -> (match ((std/core/char/(!=)(c@1, h))) {
//         ((std/core/types/True() : bool ) as @pat@10@0: bool)
//            -> std/core/types/Nothing<(string, (list :: V -> V)<char>)>;
//         ((@skip std/core/types/False() : bool ) as @pat@11: bool)
//            -> std/core/types/Just<(string, (list :: V -> V)<char>)>((std/core/types/Tuple2<string,(list :: V -> V)<char>>((f(t, (match ((std/core/int/(<=)(n, m@0))) {
//                 ((std/core/types/True() : bool ) as @pat@12: bool)
//                    -> n;
//                 ((@skip std/core/types/False() : bool ) as @pat@0@1: bool)
//                    -> m@0;
//               }), locale)), rest@0@0)));
//       });
//   };
// }

kk_std_core_types__maybe kk_std_time_format__lift_format_pat_10537(kk_char_t h, kk_std_time_locale__time_locale locale, kk_integer_t n, kk_std_core_types__list rest_0_0, kk_std_time_time__time t, kk_std_core_types__list _uniq_xs_10514, kk_context_t* _ctx) { /* (h : char, locale : std/time/locale/time-locale, n : int, rest@0@0 : list<char>, t : std/time/time/time, list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>) -> maybe<(string, list<char>)> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10514, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_core_types__list_drop(rest_0_0, _ctx);
    kk_integer_drop(n, _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x2705 = kk_std_core_types__as_Cons(_uniq_xs_10514, _ctx);
    kk_box_t _box_x1000 = _con_x2705->head;
    kk_std_core_types__list _uniq_xx_10519 = _con_x2705->tail;
    kk_std_core_types__tuple3 _uniq_x_10518 = kk_std_core_types__tuple3_unbox(_box_x1000, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10514, _ctx)) {
      kk_std_core_types__tuple3_dup(_uniq_x_10518, _ctx);
      kk_box_drop(_box_x1000, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10514, _ctx);
    }
    else {
      kk_std_core_types__tuple3_dup(_uniq_x_10518, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10519, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10514, _ctx);
    }
    {
      kk_box_t _box_x1001 = _uniq_x_10518.fst;
      kk_box_t _box_x1002 = _uniq_x_10518.snd;
      kk_box_t _fun_unbox_x1010 = _uniq_x_10518.thd;
      kk_char_t c_1 = kk_char_unbox(_box_x1001, KK_BORROWED, _ctx);
      kk_integer_t m_0 = kk_integer_unbox(_box_x1002, _ctx);
      kk_box_dup(_fun_unbox_x1010, _ctx);
      kk_integer_dup(m_0, _ctx);
      kk_std_core_types__tuple3_drop(_uniq_x_10518, _ctx);
      bool _match_x1327 = (c_1 != h); /*bool*/;
      if (_match_x1327) {
        kk_integer_drop(m_0, _ctx);
        kk_box_drop(_fun_unbox_x1010, _ctx);
        { // tailcall
          _uniq_xs_10514 = _uniq_xx_10519;
          goto kk__tailcall;
        }
      }
      {
        kk_std_core_types__list_drop(_uniq_xx_10519, _ctx);
        kk_integer_t _b_x1016_1025;
        bool _match_x1328 = kk_integer_lte_borrow(n,m_0,kk_context()); /*bool*/;
        if (_match_x1328) {
          kk_integer_drop(m_0, _ctx);
          _b_x1016_1025 = n; /*int*/
        }
        else {
          kk_integer_drop(n, _ctx);
          _b_x1016_1025 = m_0; /*int*/
        }
        kk_box_t _x_x2706;
        kk_std_core_types__tuple2 _x_x2707;
        kk_box_t _x_x2708;
        kk_function_t _x_x2709 = kk_function_unbox(_fun_unbox_x1010, _ctx); /*(1011, 1012, 1013) -> 1014*/
        _x_x2708 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x2709, (_x_x2709, kk_std_time_time__time_box(t, _ctx), kk_integer_box(_b_x1016_1025, _ctx), kk_std_time_locale__time_locale_box(locale, _ctx), _ctx), _ctx); /*1014*/
        _x_x2707 = kk_std_core_types__new_Tuple2(_x_x2708, kk_std_core_types__list_box(rest_0_0, _ctx), _ctx); /*(10037, 10038)*/
        _x_x2706 = kk_std_core_types__tuple2_box(_x_x2707, _ctx); /*10024*/
        return kk_std_core_types__new_Just(_x_x2706, _ctx);
      }
    }
  }
}
 
// lifted local: format-pat, @spec-x10513
// specialized: std/core/list/foreach-while, on parameters @uniq-action@10510, using:
// @uniq-action@10510 = fn(pattern: (char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)){
//   match (pattern) {
//     ((@skip std/core/types/Tuple3((c@1: char) : char, (m@0: int) : int, (f: (std/time/time/time, int, std/time/locale/time-locale) -> string) : (std/time/time/time, int, std/time/locale/time-locale) -> string) : (char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string) ) as @pat@9@0: (char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string))
//        -> (match ((std/core/char/(!=)(c@1, h))) {
//         ((std/core/types/True() : bool ) as @pat@10@0: bool)
//            -> std/core/types/Nothing<(string, (list :: V -> V)<char>)>;
//         ((@skip std/core/types/False() : bool ) as @pat@11: bool)
//            -> std/core/types/Just<(string, (list :: V -> V)<char>)>((std/core/types/Tuple2<string,(list :: V -> V)<char>>((f(t, (match ((std/core/int/(<=)(n, m@0))) {
//                 ((std/core/types/True() : bool ) as @pat@12: bool)
//                    -> n;
//                 ((@skip std/core/types/False() : bool ) as @pat@0@1: bool)
//                    -> m@0;
//               }), locale)), rest@0@0)));
//       });
//   };
// }

kk_std_core_types__maybe kk_std_time_format__lift_format_pat_10536(kk_char_t h, kk_std_time_locale__time_locale locale, kk_integer_t n, kk_std_core_types__list rest_0_0, kk_std_time_time__time t, kk_std_core_types__list _uniq_xs_10509, kk_context_t* _ctx) { /* (h : char, locale : std/time/locale/time-locale, n : int, rest@0@0 : list<char>, t : std/time/time/time, list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>) -> maybe<(string, list<char>)> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10509, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_core_types__list_drop(rest_0_0, _ctx);
    kk_integer_drop(n, _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    return kk_std_time_format__lift_format_pat_10537(h, locale, n, rest_0_0, t, _uniq_xs_10509, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_time_format_format_pat(kk_std_time_time__time t, kk_char_t h, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, h : char, fmt : list<char>, locale : std/time/locale/time-locale) -> (string, list<char>) */ 
  bool _match_x1321 = (h == ('"')); /*bool*/;
  if (_match_x1321) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    kk_std_core_types__tuple2 _match_x1326;
    kk_std_core_types__list _x_x2710 = kk_std_core_types__list_dup(fmt, _ctx); /*list<char>*/
    _match_x1326 = kk_std_time_format__lift_format_pat_10530(h, _x_x2710, _ctx); /*(list<char>, list<char>)*/
    {
      kk_box_t _box_x1027 = _match_x1326.fst;
      kk_box_t _box_x1028 = _match_x1326.snd;
      kk_std_core_types__list quoted = kk_std_core_types__list_unbox(_box_x1027, KK_BORROWED, _ctx);
      kk_std_core_types__list end = kk_std_core_types__list_unbox(_box_x1028, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(end, _ctx);
      kk_std_core_types__list_dup(quoted, _ctx);
      kk_std_core_types__tuple2_drop(_match_x1326, _ctx);
      if (kk_std_core_types__is_Nil(end, _ctx)) {
        kk_std_core_types__list_drop(quoted, _ctx);
        kk_string_t _b_x1029_1048 = kk_std_core_string_char_fs_string(h, _ctx); /*string*/;
        return kk_std_core_types__new_Tuple2(kk_string_box(_b_x1029_1048), kk_std_core_types__list_box(fmt, _ctx), _ctx);
      }
      {
        struct kk_std_core_types_Cons* _con_x2711 = kk_std_core_types__as_Cons(end, _ctx);
        kk_box_t _box_x1031 = _con_x2711->head;
        kk_std_core_types__list rest = _con_x2711->tail;
        kk_std_core_types__list_drop(fmt, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(end, _ctx)) {
          kk_datatype_ptr_free(end, _ctx);
        }
        else {
          kk_std_core_types__list_dup(rest, _ctx);
          kk_datatype_ptr_decref(end, _ctx);
        }
        kk_string_t _b_x1032_1050 = kk_std_core_string_listchar_fs_string(quoted, _ctx); /*string*/;
        return kk_std_core_types__new_Tuple2(kk_string_box(_b_x1032_1050), kk_std_core_types__list_box(rest, _ctx), _ctx);
      }
    }
  }
  {
    bool _match_x1322 = (h == ('\'')); /*bool*/;
    if (_match_x1322) {
      kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
      kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
      kk_std_core_types__tuple2 _match_x1325;
      kk_std_core_types__list _x_x2712 = kk_std_core_types__list_dup(fmt, _ctx); /*list<char>*/
      _match_x1325 = kk_std_time_format__lift_format_pat_10532(h, _x_x2712, _ctx); /*(list<char>, list<char>)*/
      {
        kk_box_t _box_x1034 = _match_x1325.fst;
        kk_box_t _box_x1035 = _match_x1325.snd;
        kk_std_core_types__list quoted_0 = kk_std_core_types__list_unbox(_box_x1034, KK_BORROWED, _ctx);
        kk_std_core_types__list end_0 = kk_std_core_types__list_unbox(_box_x1035, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(end_0, _ctx);
        kk_std_core_types__list_dup(quoted_0, _ctx);
        kk_std_core_types__tuple2_drop(_match_x1325, _ctx);
        if (kk_std_core_types__is_Nil(end_0, _ctx)) {
          kk_std_core_types__list_drop(quoted_0, _ctx);
          kk_string_t _b_x1036_1052 = kk_std_core_string_char_fs_string(h, _ctx); /*string*/;
          return kk_std_core_types__new_Tuple2(kk_string_box(_b_x1036_1052), kk_std_core_types__list_box(fmt, _ctx), _ctx);
        }
        {
          struct kk_std_core_types_Cons* _con_x2713 = kk_std_core_types__as_Cons(end_0, _ctx);
          kk_box_t _box_x1038 = _con_x2713->head;
          kk_std_core_types__list rest_0 = _con_x2713->tail;
          kk_std_core_types__list_drop(fmt, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(end_0, _ctx)) {
            kk_datatype_ptr_free(end_0, _ctx);
          }
          else {
            kk_std_core_types__list_dup(rest_0, _ctx);
            kk_datatype_ptr_decref(end_0, _ctx);
          }
          kk_string_t _b_x1039_1054 = kk_std_core_string_listchar_fs_string(quoted_0, _ctx); /*string*/;
          return kk_std_core_types__new_Tuple2(kk_string_box(_b_x1039_1054), kk_std_core_types__list_box(rest_0, _ctx), _ctx);
        }
      }
    }
    {
      bool _match_x1323 = kk_std_core_char_is_alpha(h, _ctx); /*bool*/;
      if (_match_x1323) {
        kk_std_core_types__tuple2 _match_x1324 = kk_std_time_format__lift_format_pat_10534(h, fmt, _ctx); /*(list<char>, list<char>)*/;
        {
          kk_box_t _box_x1041 = _match_x1324.fst;
          kk_box_t _box_x1042 = _match_x1324.snd;
          kk_std_core_types__list hs = kk_std_core_types__list_unbox(_box_x1041, KK_BORROWED, _ctx);
          kk_std_core_types__list rest_0_0 = kk_std_core_types__list_unbox(_box_x1042, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(hs, _ctx);
          kk_std_core_types__list_dup(rest_0_0, _ctx);
          kk_std_core_types__tuple2_drop(_match_x1324, _ctx);
          kk_integer_t x_10171;
          if (kk_std_core_types__is_Nil(hs, _ctx)) {
            x_10171 = kk_integer_from_small(0); /*int*/
          }
          else {
            x_10171 = kk_std_core_list__unroll_lift_length_5730_10000(hs, kk_integer_from_small(0), _ctx); /*int*/
          }
          kk_integer_t n = kk_integer_add_small_const(x_10171, 1, _ctx); /*int*/;
          kk_std_core_types__maybe m_10174;
          kk_std_core_types__list _x_x2714 = kk_std_core_types__list_dup(rest_0_0, _ctx); /*list<char>*/
          kk_std_core_types__list _x_x2715 = kk_std_core_types__list_dup(kk_std_time_format_formats, _ctx); /*list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>*/
          m_10174 = kk_std_time_format__lift_format_pat_10536(h, locale, n, _x_x2714, t, _x_x2715, _ctx); /*maybe<(string, list<char>)>*/
          if (kk_std_core_types__is_Nothing(m_10174, _ctx)) {
            kk_box_t _x_x2716;
            kk_string_t _x_x2717 = kk_string_empty(); /*string*/
            _x_x2716 = kk_string_box(_x_x2717); /*10037*/
            return kk_std_core_types__new_Tuple2(_x_x2716, kk_std_core_types__list_box(rest_0_0, _ctx), _ctx);
          }
          {
            kk_box_t _box_x1045 = m_10174._cons.Just.value;
            kk_std_core_types__tuple2 x_0 = kk_std_core_types__tuple2_unbox(_box_x1045, KK_BORROWED, _ctx);
            kk_std_core_types__list_drop(rest_0_0, _ctx);
            kk_std_core_types__tuple2_dup(x_0, _ctx);
            kk_std_core_types__maybe_drop(m_10174, _ctx);
            return x_0;
          }
        }
      }
      {
        kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
        kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
        kk_string_t _b_x1046_1058 = kk_std_core_string_char_fs_string(h, _ctx); /*string*/;
        return kk_std_core_types__new_Tuple2(kk_string_box(_b_x1046_1058), kk_std_core_types__list_box(fmt, _ctx), _ctx);
      }
    }
  }
}

kk_string_t kk_std_time_format__unroll_format_list_10000(kk_std_time_time__time t, kk_std_core_types__list fmt, kk_std_time_locale__time_locale locale, kk_context_t* _ctx) { /* (t : std/time/time/time, fmt : list<char>, locale : std/time/locale/time-locale) -> string */ 
  if (kk_std_core_types__is_Nil(fmt, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_datatype_ptr_dropn(locale, (KK_I32(12)), _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x2720 = kk_std_core_types__as_Cons(fmt, _ctx);
    kk_box_t _box_x1060 = _con_x2720->head;
    kk_std_core_types__list cs = _con_x2720->tail;
    kk_char_t c = kk_char_unbox(_box_x1060, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(fmt, _ctx)) {
      kk_datatype_ptr_free(fmt, _ctx);
    }
    else {
      kk_std_core_types__list_dup(cs, _ctx);
      kk_datatype_ptr_decref(fmt, _ctx);
    }
    kk_std_core_types__tuple2 _match_x1320;
    kk_std_time_time__time _x_x2721 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
    kk_std_time_locale__time_locale _x_x2722 = kk_std_time_locale__time_locale_dup(locale, _ctx); /*std/time/locale/time-locale*/
    _match_x1320 = kk_std_time_format_format_pat(_x_x2721, c, cs, _x_x2722, _ctx); /*(string, list<char>)*/
    {
      kk_box_t _box_x1061 = _match_x1320.fst;
      kk_box_t _box_x1062 = _match_x1320.snd;
      kk_string_t formatted = kk_string_unbox(_box_x1061);
      kk_std_core_types__list rest = kk_std_core_types__list_unbox(_box_x1062, KK_BORROWED, _ctx);
      kk_string_dup(formatted, _ctx);
      kk_std_core_types__list_dup(rest, _ctx);
      kk_std_core_types__tuple2_drop(_match_x1320, _ctx);
      kk_string_t _x_x2723 = kk_std_time_format__unroll_format_list_10000(t, rest, locale, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(formatted, _x_x2723, _ctx);
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


// lift anonymous function
struct kk_std_time_format_format_fun2729__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_format_fun2729(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_fun2729(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2729__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_fun2729__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_fun2729, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_format_fun2730__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_format_fun2730(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_fun2730(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2730__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_fun2730__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_fun2730, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_format_fun2730(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2730__t* _self = kk_function_as(struct kk_std_time_format_format_fun2730__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2731;
  kk_std_time_locale__time_locale _x_x2732;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x1063 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x1063, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2732 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2732 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2731 = kk_std_time_format_plocale(_x_x2732, _ctx); /*string*/
  return kk_string_box(_x_x2731);
}


// lift anonymous function
struct kk_std_time_format_format_fun2735__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_format_fun2735(kk_function_t _fself, kk_box_t _b_x1069, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_fun2735(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_format_fun2735, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_format_fun2735(kk_function_t _fself, kk_box_t _b_x1069, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2736;
  kk_std_core_types__list _x_x2737 = kk_std_core_types__list_unbox(_b_x1069, KK_OWNED, _ctx); /*list<string>*/
  _x_x2736 = kk_std_time_format__mlift_plocales_10646(_x_x2737, _ctx); /*string*/
  return kk_string_box(_x_x2736);
}
static kk_box_t kk_std_time_format_format_fun2729(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2729__t* _self = kk_function_as(struct kk_std_time_format_format_fun2729__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_10806 = kk_std_text_parse_many_acc(kk_std_time_format_new_format_fun2730(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2733;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10806, _ctx);
    kk_box_t _x_x2734 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_format_fun2735(_ctx), _ctx); /*10001*/
    _x_x2733 = kk_string_unbox(_x_x2734); /*string*/
  }
  else {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10806, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x2738;
    }
    {
      struct kk_std_core_types_Cons* _con_x2740 = kk_std_core_types__as_Cons(x_10806, _ctx);
      kk_box_t _box_x1070 = _con_x2740->head;
      kk_std_core_types__list _pat_1_0 = _con_x2740->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x1070);
        if kk_likely(kk_datatype_ptr_is_unique(x_10806, _ctx)) {
          kk_datatype_ptr_free(x_10806, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10806, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x2738;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2741 = kk_std_core_types__as_Cons(x_10806, _ctx);
      kk_box_t _box_x1071 = _con_x2741->head;
      kk_std_core_types__list _pat_3 = _con_x2741->tail;
      struct kk_std_core_types_Cons* _con_x2742 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1072 = _con_x2742->head;
      kk_std_core_types__list _pat_4 = _con_x2742->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x1071);
        kk_string_t y = kk_string_unbox(_box_x1072);
        if kk_likely(kk_datatype_ptr_is_unique(x_10806, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10806, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10806, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x2738;
      }
    }
    {
      kk_vector_t _x_x2743 = kk_std_core_vector_unvlist(x_10806, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x2743,kk_context()); /*string*/
    }
    _match_x2738: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    _x_x2733 = x_0; /*string*/
  }
  return kk_string_box(_x_x2733);
}


// lift anonymous function
struct kk_std_time_format_format_fun2752__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_format_fun2752(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_fun2752(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2752__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_fun2752__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_fun2752, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_format_fun2753__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_format_fun2753(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_fun2753(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2753__t* _self = kk_function_alloc_as(struct kk_std_time_format_format_fun2753__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_format_fun2753, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_format_fun2753(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2753__t* _self = kk_function_as(struct kk_std_time_format_format_fun2753__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2754;
  kk_std_time_locale__time_locale _x_x2755;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x1082 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x1082, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2755 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2755 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2754 = kk_std_time_format_plocale(_x_x2755, _ctx); /*string*/
  return kk_string_box(_x_x2754);
}


// lift anonymous function
struct kk_std_time_format_format_fun2758__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_format_fun2758(kk_function_t _fself, kk_box_t _b_x1088, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_format_fun2758(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_format_fun2758, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_format_fun2758(kk_function_t _fself, kk_box_t _b_x1088, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2759;
  kk_std_core_types__list _x_x2760 = kk_std_core_types__list_unbox(_b_x1088, KK_OWNED, _ctx); /*list<string>*/
  _x_x2759 = kk_std_time_format__mlift_plocales_10646(_x_x2760, _ctx); /*string*/
  return kk_string_box(_x_x2759);
}
static kk_box_t kk_std_time_format_format_fun2752(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_format_fun2752__t* _self = kk_function_as(struct kk_std_time_format_format_fun2752__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_1_10814 = kk_std_text_parse_many_acc(kk_std_time_format_new_format_fun2753(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2756;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10814, _ctx);
    kk_box_t _x_x2757 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_format_fun2758(_ctx), _ctx); /*10001*/
    _x_x2756 = kk_string_unbox(_x_x2757); /*string*/
  }
  else {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_2_0;
    if (kk_std_core_types__is_Nil(x_1_10814, _ctx)) {
      x_2_0 = kk_string_empty(); /*string*/
      goto _match_x2761;
    }
    {
      struct kk_std_core_types_Cons* _con_x2763 = kk_std_core_types__as_Cons(x_1_10814, _ctx);
      kk_box_t _box_x1089 = _con_x2763->head;
      kk_std_core_types__list _pat_1_1_0 = _con_x2763->tail;
      if (kk_std_core_types__is_Nil(_pat_1_1_0, _ctx)) {
        kk_string_t x_3 = kk_string_unbox(_box_x1089);
        if kk_likely(kk_datatype_ptr_is_unique(x_1_10814, _ctx)) {
          kk_datatype_ptr_free(x_1_10814, _ctx);
        }
        else {
          kk_string_dup(x_3, _ctx);
          kk_datatype_ptr_decref(x_1_10814, _ctx);
        }
        x_2_0 = x_3; /*string*/
        goto _match_x2761;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2764 = kk_std_core_types__as_Cons(x_1_10814, _ctx);
      kk_box_t _box_x1090 = _con_x2764->head;
      kk_std_core_types__list _pat_3_0_0_0 = _con_x2764->tail;
      struct kk_std_core_types_Cons* _con_x2765 = kk_std_core_types__as_Cons(_pat_3_0_0_0, _ctx);
      kk_box_t _box_x1091 = _con_x2765->head;
      kk_std_core_types__list _pat_4_0_0_0 = _con_x2765->tail;
      if (kk_std_core_types__is_Nil(_pat_4_0_0_0, _ctx)) {
        kk_string_t x_0_0_0 = kk_string_unbox(_box_x1090);
        kk_string_t y_0 = kk_string_unbox(_box_x1091);
        if kk_likely(kk_datatype_ptr_is_unique(x_1_10814, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_pat_3_0_0_0, _ctx);
          }
          else {
            kk_string_dup(y_0, _ctx);
            kk_datatype_ptr_decref(_pat_3_0_0_0, _ctx);
          }
          kk_datatype_ptr_free(x_1_10814, _ctx);
        }
        else {
          kk_string_dup(x_0_0_0, _ctx);
          kk_string_dup(y_0, _ctx);
          kk_datatype_ptr_decref(x_1_10814, _ctx);
        }
        x_2_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0_0, y_0, _ctx); /*string*/
        goto _match_x2761;
      }
    }
    {
      kk_vector_t _x_x2766 = kk_std_core_vector_unvlist(x_1_10814, _ctx); /*vector<10000>*/
      x_2_0 = kk_string_join(_x_x2766,kk_context()); /*string*/
    }
    _match_x2761: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    _x_x2756 = x_2_0; /*string*/
  }
  return kk_string_box(_x_x2756);
}

kk_string_t kk_std_time_format_format(kk_std_time_time__time t, kk_string_t fmt, kk_std_core_types__optional locale, kk_context_t* _ctx) { /* (t : std/time/time/time, fmt : string, locale : ? std/time/locale/time-locale) -> string */ 
  kk_std_core_sslice__sslice _b_x1073_1075;
  kk_string_t _x_x2725 = kk_string_dup(fmt, _ctx); /*string*/
  kk_integer_t _x_x2726;
  kk_string_t _x_x2727 = kk_string_dup(fmt, _ctx); /*string*/
  _x_x2726 = kk_string_len_int(_x_x2727,kk_context()); /*int*/
  _b_x1073_1075 = kk_std_core_sslice__new_Sslice(_x_x2725, kk_integer_from_small(0), _x_x2726, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036;
  kk_function_t _x_x2728;
  kk_std_core_types__optional_dup(locale, _ctx);
  _x_x2728 = kk_std_time_format_new_format_fun2729(locale, _ctx); /*() -> <std/text/parse/parse|10001> 10000*/
  perr_10036 = kk_std_text_parse_parse_eof(_b_x1073_1075, _x_x2728, _ctx); /*std/text/parse/parse-error<string>*/
  kk_std_core_sslice__sslice _b_x1092_1094;
  kk_string_t _x_x2744;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2745 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1078 = _con_x2745->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2745->rest;
    kk_string_t x_0_1 = kk_string_unbox(_box_x1078);
    kk_string_dup(x_0_1, _ctx);
    _x_x2744 = x_0_1; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2746 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0 = _con_x2746->rest;
    _x_x2744 = kk_string_dup(fmt, _ctx); /*string*/
  }
  kk_integer_t _x_x2747;
  kk_string_t _x_x2748;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2749 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1080 = _con_x2749->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0 = _con_x2749->rest;
    kk_string_t x_0_1_0 = kk_string_unbox(_box_x1080);
    kk_string_dup(x_0_1_0, _ctx);
    _x_x2748 = x_0_1_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2750 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0 = _con_x2750->rest;
    _x_x2748 = kk_string_dup(fmt, _ctx); /*string*/
  }
  _x_x2747 = kk_string_len_int(_x_x2748,kk_context()); /*int*/
  _b_x1092_1094 = kk_std_core_sslice__new_Sslice(_x_x2744, kk_integer_from_small(0), _x_x2747, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10185;
  kk_function_t _x_x2751;
  kk_std_core_types__optional_dup(locale, _ctx);
  _x_x2751 = kk_std_time_format_new_format_fun2752(locale, _ctx); /*() -> <std/text/parse/parse|10001> 10000*/
  perr_10185 = kk_std_text_parse_parse_eof(_b_x1092_1094, _x_x2751, _ctx); /*std/text/parse/parse-error<string>*/
  kk_std_core_types__list fmt_0_10179;
  kk_string_t _x_x2767;
  if (kk_std_text_parse__is_ParseOk(perr_10185, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2768 = kk_std_text_parse__as_ParseOk(perr_10185, _ctx);
    kk_box_t _box_x1097 = _con_x2768->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0_0_0 = _con_x2768->rest;
    kk_string_t x_0_1_0_0 = kk_string_unbox(_box_x1097);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10185, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10185, _ctx);
    }
    else {
      kk_string_dup(x_0_1_0_0, _ctx);
      kk_datatype_ptr_decref(perr_10185, _ctx);
    }
    kk_std_text_parse__parse_error_drop(perr_10036, _ctx);
    kk_string_drop(fmt, _ctx);
    _x_x2767 = x_0_1_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2769 = kk_std_text_parse__as_ParseError(perr_10185, _ctx);
    kk_std_core_sslice__sslice _pat_5_1 = _con_x2769->rest;
    kk_string_t msg_0_0 = _con_x2769->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10185, _ctx)) {
      kk_string_drop(msg_0_0, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5_1, _ctx);
      kk_datatype_ptr_free(perr_10185, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10185, _ctx);
    }
    if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2770 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
      kk_box_t _box_x1098 = _con_x2770->result;
      kk_std_core_sslice__sslice _pat_0_0_0_1 = _con_x2770->rest;
      kk_string_t x_0_1_1 = kk_string_unbox(_box_x1098);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_string_dup(x_0_1_1, _ctx);
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      kk_string_drop(fmt, _ctx);
      _x_x2767 = x_0_1_1; /*string*/
    }
    else {
      struct kk_std_text_parse_ParseError* _con_x2771 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
      kk_std_core_sslice__sslice _pat_5_0_1 = _con_x2771->rest;
      kk_string_t msg_1 = _con_x2771->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_string_drop(msg_1, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      _x_x2767 = fmt; /*string*/
    }
  }
  fmt_0_10179 = kk_std_core_string_list(_x_x2767, _ctx); /*list<char>*/
  if (kk_std_core_types__is_Nil(fmt_0_10179, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    return kk_string_empty();
  }
  {
    kk_std_time_locale__time_locale _x_x2773;
    if (kk_std_core_types__is_Optional(locale, _ctx)) {
      kk_box_t _box_x1101 = locale._cons._Optional.value;
      kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x1101, KK_BORROWED, _ctx);
      kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
      kk_std_core_types__optional_drop(locale, _ctx);
      _x_x2773 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
    }
    else {
      kk_std_core_types__optional_drop(locale, _ctx);
      _x_x2773 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
    }
    return kk_std_time_format__unroll_format_list_10000(t, fmt_0_10179, _x_x2773, _ctx);
  }
}
 
// Show a time as a standard ISO date. Will use automatic week date
// or month date format for the  `cal-iso-week` and `cal-iso-month` calendars.


// lift anonymous function
struct kk_std_time_format_show_iso_date_fun2779__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_date_fun2779(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_date_fun2779(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_date_fun2779, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_iso_date_fun2780__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_date_fun2780(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_date_fun2780(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_date_fun2780, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_date_fun2780(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2781;
  kk_std_time_locale__time_locale _x_x2782;
  kk_std_core_types__optional _match_x1317 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1317, _ctx)) {
    kk_box_t _box_x1102 = _match_x1317._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x1102, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(_match_x1317, _ctx);
    _x_x2782 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1317, _ctx);
    _x_x2782 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2781 = kk_std_time_format_plocale(_x_x2782, _ctx); /*string*/
  return kk_string_box(_x_x2781);
}


// lift anonymous function
struct kk_std_time_format_show_iso_date_fun2785__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_date_fun2785(kk_function_t _fself, kk_box_t _b_x1108, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_date_fun2785(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_date_fun2785, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_date_fun2785(kk_function_t _fself, kk_box_t _b_x1108, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2786;
  kk_std_core_types__list _x_x2787 = kk_std_core_types__list_unbox(_b_x1108, KK_OWNED, _ctx); /*list<string>*/
  _x_x2786 = kk_std_time_format__mlift_plocales_10646(_x_x2787, _ctx); /*string*/
  return kk_string_box(_x_x2786);
}
static kk_box_t kk_std_time_format_show_iso_date_fun2779(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_10820 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_iso_date_fun2780(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2783;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10820, _ctx);
    kk_box_t _x_x2784 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_iso_date_fun2785(_ctx), _ctx); /*10001*/
    _x_x2783 = kk_string_unbox(_x_x2784); /*string*/
  }
  else {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10820, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x2788;
    }
    {
      struct kk_std_core_types_Cons* _con_x2790 = kk_std_core_types__as_Cons(x_10820, _ctx);
      kk_box_t _box_x1109 = _con_x2790->head;
      kk_std_core_types__list _pat_1_0 = _con_x2790->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x1109);
        if kk_likely(kk_datatype_ptr_is_unique(x_10820, _ctx)) {
          kk_datatype_ptr_free(x_10820, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10820, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x2788;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2791 = kk_std_core_types__as_Cons(x_10820, _ctx);
      kk_box_t _box_x1110 = _con_x2791->head;
      kk_std_core_types__list _pat_3 = _con_x2791->tail;
      struct kk_std_core_types_Cons* _con_x2792 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1111 = _con_x2792->head;
      kk_std_core_types__list _pat_4 = _con_x2792->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x1110);
        kk_string_t y = kk_string_unbox(_box_x1111);
        if kk_likely(kk_datatype_ptr_is_unique(x_10820, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10820, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10820, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x2788;
      }
    }
    {
      kk_vector_t _x_x2793 = kk_std_core_vector_unvlist(x_10820, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x2793,kk_context()); /*string*/
    }
    _match_x2788: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    _x_x2783 = x_0; /*string*/
  }
  return kk_string_box(_x_x2783);
}


// lift anonymous function
struct kk_std_time_format_show_iso_date_fun2803__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_date_fun2803(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_date_fun2803(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_date_fun2803, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_iso_date_fun2804__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_date_fun2804(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_date_fun2804(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_date_fun2804, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_date_fun2804(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2805;
  kk_std_time_locale__time_locale _x_x2806;
  kk_std_core_types__optional _match_x1315 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1315, _ctx)) {
    kk_box_t _box_x1121 = _match_x1315._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x1121, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(_match_x1315, _ctx);
    _x_x2806 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1315, _ctx);
    _x_x2806 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2805 = kk_std_time_format_plocale(_x_x2806, _ctx); /*string*/
  return kk_string_box(_x_x2805);
}


// lift anonymous function
struct kk_std_time_format_show_iso_date_fun2809__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_date_fun2809(kk_function_t _fself, kk_box_t _b_x1127, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_date_fun2809(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_date_fun2809, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_date_fun2809(kk_function_t _fself, kk_box_t _b_x1127, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2810;
  kk_std_core_types__list _x_x2811 = kk_std_core_types__list_unbox(_b_x1127, KK_OWNED, _ctx); /*list<string>*/
  _x_x2810 = kk_std_time_format__mlift_plocales_10646(_x_x2811, _ctx); /*string*/
  return kk_string_box(_x_x2810);
}
static kk_box_t kk_std_time_format_show_iso_date_fun2803(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_3_10826 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_iso_date_fun2804(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2807;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_3_10826, _ctx);
    kk_box_t _x_x2808 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_iso_date_fun2809(_ctx), _ctx); /*10001*/
    _x_x2807 = kk_string_unbox(_x_x2808); /*string*/
  }
  else {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_4;
    if (kk_std_core_types__is_Nil(x_3_10826, _ctx)) {
      x_4 = kk_string_empty(); /*string*/
      goto _match_x2812;
    }
    {
      struct kk_std_core_types_Cons* _con_x2814 = kk_std_core_types__as_Cons(x_3_10826, _ctx);
      kk_box_t _box_x1128 = _con_x2814->head;
      kk_std_core_types__list _pat_1_2 = _con_x2814->tail;
      if (kk_std_core_types__is_Nil(_pat_1_2, _ctx)) {
        kk_string_t x_5 = kk_string_unbox(_box_x1128);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10826, _ctx)) {
          kk_datatype_ptr_free(x_3_10826, _ctx);
        }
        else {
          kk_string_dup(x_5, _ctx);
          kk_datatype_ptr_decref(x_3_10826, _ctx);
        }
        x_4 = x_5; /*string*/
        goto _match_x2812;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2815 = kk_std_core_types__as_Cons(x_3_10826, _ctx);
      kk_box_t _box_x1129 = _con_x2815->head;
      kk_std_core_types__list _pat_3_1 = _con_x2815->tail;
      struct kk_std_core_types_Cons* _con_x2816 = kk_std_core_types__as_Cons(_pat_3_1, _ctx);
      kk_box_t _box_x1130 = _con_x2816->head;
      kk_std_core_types__list _pat_4_1 = _con_x2816->tail;
      if (kk_std_core_types__is_Nil(_pat_4_1, _ctx)) {
        kk_string_t x_0_2 = kk_string_unbox(_box_x1129);
        kk_string_t y_0 = kk_string_unbox(_box_x1130);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10826, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_datatype_ptr_free(_pat_3_1, _ctx);
          }
          else {
            kk_string_dup(y_0, _ctx);
            kk_datatype_ptr_decref(_pat_3_1, _ctx);
          }
          kk_datatype_ptr_free(x_3_10826, _ctx);
        }
        else {
          kk_string_dup(x_0_2, _ctx);
          kk_string_dup(y_0, _ctx);
          kk_datatype_ptr_decref(x_3_10826, _ctx);
        }
        x_4 = kk_std_core_types__lp__plus__plus__rp_(x_0_2, y_0, _ctx); /*string*/
        goto _match_x2812;
      }
    }
    {
      kk_vector_t _x_x2817 = kk_std_core_vector_unvlist(x_3_10826, _ctx); /*vector<10000>*/
      x_4 = kk_string_join(_x_x2817,kk_context()); /*string*/
    }
    _match_x2812: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    _x_x2807 = x_4; /*string*/
  }
  return kk_string_box(_x_x2807);
}

kk_string_t kk_std_time_format_show_iso_date(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : std/time/time/time) -> string */ 
  kk_std_core_sslice__sslice _b_x1112_1114;
  kk_string_t _x_x2774;
  kk_define_string_literal(, _s_x2775, 10, "YYYY-MM-DD", _ctx)
  _x_x2774 = kk_string_dup(_s_x2775, _ctx); /*string*/
  kk_integer_t _x_x2776;
  kk_string_t _x_x2777;
  kk_define_string_literal(, _s_x2778, 10, "YYYY-MM-DD", _ctx)
  _x_x2777 = kk_string_dup(_s_x2778, _ctx); /*string*/
  _x_x2776 = kk_string_len_int(_x_x2777,kk_context()); /*int*/
  _b_x1112_1114 = kk_std_core_sslice__new_Sslice(_x_x2774, kk_integer_from_small(0), _x_x2776, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036 = kk_std_text_parse_parse_eof(_b_x1112_1114, kk_std_time_format_new_show_iso_date_fun2779(_ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  kk_std_core_sslice__sslice _b_x1131_1133;
  kk_string_t _x_x2794;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2795 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1117 = _con_x2795->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2795->rest;
    kk_string_t x_0_1 = kk_string_unbox(_box_x1117);
    kk_string_dup(x_0_1, _ctx);
    _x_x2794 = x_0_1; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2796 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0 = _con_x2796->rest;
    kk_define_string_literal(, _s_x2797, 10, "YYYY-MM-DD", _ctx)
    _x_x2794 = kk_string_dup(_s_x2797, _ctx); /*string*/
  }
  kk_integer_t _x_x2798;
  kk_string_t _x_x2799;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2800 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1119 = _con_x2800->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0 = _con_x2800->rest;
    kk_string_t x_0_0_0 = kk_string_unbox(_box_x1119);
    kk_string_dup(x_0_0_0, _ctx);
    _x_x2799 = x_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2801 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0 = _con_x2801->rest;
    kk_define_string_literal(, _s_x2802, 10, "YYYY-MM-DD", _ctx)
    _x_x2799 = kk_string_dup(_s_x2802, _ctx); /*string*/
  }
  _x_x2798 = kk_string_len_int(_x_x2799,kk_context()); /*int*/
  _b_x1131_1133 = kk_std_core_sslice__new_Sslice(_x_x2794, kk_integer_from_small(0), _x_x2798, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10197 = kk_std_text_parse_parse_eof(_b_x1131_1133, kk_std_time_format_new_show_iso_date_fun2803(_ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  kk_std_core_types__list fmt_0_10191;
  kk_string_t _x_x2818;
  if (kk_std_text_parse__is_ParseOk(perr_10197, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2819 = kk_std_text_parse__as_ParseOk(perr_10197, _ctx);
    kk_box_t _box_x1136 = _con_x2819->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0_0 = _con_x2819->rest;
    kk_string_t x_0_0_0_0 = kk_string_unbox(_box_x1136);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10197, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10197, _ctx);
    }
    else {
      kk_string_dup(x_0_0_0_0, _ctx);
      kk_datatype_ptr_decref(perr_10197, _ctx);
    }
    kk_std_text_parse__parse_error_drop(perr_10036, _ctx);
    _x_x2818 = x_0_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2820 = kk_std_text_parse__as_ParseError(perr_10197, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0_0 = _con_x2820->rest;
    kk_string_t msg_0_0 = _con_x2820->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10197, _ctx)) {
      kk_string_drop(msg_0_0, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10197, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10197, _ctx);
    }
    if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2821 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
      kk_box_t _box_x1137 = _con_x2821->result;
      kk_std_core_sslice__sslice _pat_0_0_1 = _con_x2821->rest;
      kk_string_t x_0_1_0 = kk_string_unbox(_box_x1137);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_string_dup(x_0_1_0, _ctx);
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      _x_x2818 = x_0_1_0; /*string*/
    }
    else {
      struct kk_std_text_parse_ParseError* _con_x2822 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
      kk_std_core_sslice__sslice _pat_5_1_0 = _con_x2822->rest;
      kk_string_t msg_1 = _con_x2822->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_string_drop(msg_1, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5_1_0, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      kk_define_string_literal(, _s_x2823, 10, "YYYY-MM-DD", _ctx)
      _x_x2818 = kk_string_dup(_s_x2823, _ctx); /*string*/
    }
  }
  fmt_0_10191 = kk_std_core_string_list(_x_x2818, _ctx); /*list<char>*/
  if (kk_std_core_types__is_Nil(fmt_0_10191, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    return kk_string_empty();
  }
  {
    kk_std_time_locale__time_locale _x_x2825;
    kk_std_core_types__optional _match_x1313 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1313, _ctx)) {
      kk_box_t _box_x1140 = _match_x1313._cons._Optional.value;
      kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x1140, KK_BORROWED, _ctx);
      kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
      kk_std_core_types__optional_drop(_match_x1313, _ctx);
      _x_x2825 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1313, _ctx);
      _x_x2825 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
    }
    return kk_std_time_format__unroll_format_list_10000(t, fmt_0_10191, _x_x2825, _ctx);
  }
}
 
// Show a time as a standard ISO string. Will use automatic week date
// or month date format for the `cal-iso-week` and `cal-iso-month` calendars.


// lift anonymous function
struct kk_std_time_format_show_iso_fun2833__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_fun2833(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_fun2833(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_fun2833, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_iso_fun2834__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_fun2834(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_fun2834(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_fun2834, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_fun2834(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2835;
  kk_std_time_locale__time_locale _x_x2836;
  kk_std_core_types__optional _match_x1312 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1312, _ctx)) {
    kk_box_t _box_x1141 = _match_x1312._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x1141, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(_match_x1312, _ctx);
    _x_x2836 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1312, _ctx);
    _x_x2836 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2835 = kk_std_time_format_plocale(_x_x2836, _ctx); /*string*/
  return kk_string_box(_x_x2835);
}


// lift anonymous function
struct kk_std_time_format_show_iso_fun2839__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_fun2839(kk_function_t _fself, kk_box_t _b_x1147, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_fun2839(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_fun2839, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_fun2839(kk_function_t _fself, kk_box_t _b_x1147, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2840;
  kk_std_core_types__list _x_x2841 = kk_std_core_types__list_unbox(_b_x1147, KK_OWNED, _ctx); /*list<string>*/
  _x_x2840 = kk_std_time_format__mlift_plocales_10646(_x_x2841, _ctx); /*string*/
  return kk_string_box(_x_x2840);
}
static kk_box_t kk_std_time_format_show_iso_fun2833(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_10806 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_iso_fun2834(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2837;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10806, _ctx);
    kk_box_t _x_x2838 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_iso_fun2839(_ctx), _ctx); /*10001*/
    _x_x2837 = kk_string_unbox(_x_x2838); /*string*/
  }
  else {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10806, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x2842;
    }
    {
      struct kk_std_core_types_Cons* _con_x2844 = kk_std_core_types__as_Cons(x_10806, _ctx);
      kk_box_t _box_x1148 = _con_x2844->head;
      kk_std_core_types__list _pat_1_0 = _con_x2844->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x1148);
        if kk_likely(kk_datatype_ptr_is_unique(x_10806, _ctx)) {
          kk_datatype_ptr_free(x_10806, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10806, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x2842;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2845 = kk_std_core_types__as_Cons(x_10806, _ctx);
      kk_box_t _box_x1149 = _con_x2845->head;
      kk_std_core_types__list _pat_3 = _con_x2845->tail;
      struct kk_std_core_types_Cons* _con_x2846 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1150 = _con_x2846->head;
      kk_std_core_types__list _pat_4 = _con_x2846->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x1149);
        kk_string_t y = kk_string_unbox(_box_x1150);
        if kk_likely(kk_datatype_ptr_is_unique(x_10806, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10806, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10806, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x2842;
      }
    }
    {
      kk_vector_t _x_x2847 = kk_std_core_vector_unvlist(x_10806, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x2847,kk_context()); /*string*/
    }
    _match_x2842: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    _x_x2837 = x_0; /*string*/
  }
  return kk_string_box(_x_x2837);
}


// lift anonymous function
struct kk_std_time_format_show_iso_fun2855__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_fun2855(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_fun2855(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_fun2855, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_iso_fun2856__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_fun2856(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_fun2856(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_fun2856, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_fun2856(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2857;
  kk_std_time_locale__time_locale _x_x2858;
  kk_std_core_types__optional _match_x1310 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1310, _ctx)) {
    kk_box_t _box_x1160 = _match_x1310._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x1160, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(_match_x1310, _ctx);
    _x_x2858 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1310, _ctx);
    _x_x2858 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2857 = kk_std_time_format_plocale(_x_x2858, _ctx); /*string*/
  return kk_string_box(_x_x2857);
}


// lift anonymous function
struct kk_std_time_format_show_iso_fun2861__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_iso_fun2861(kk_function_t _fself, kk_box_t _b_x1166, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_iso_fun2861(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_iso_fun2861, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_iso_fun2861(kk_function_t _fself, kk_box_t _b_x1166, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2862;
  kk_std_core_types__list _x_x2863 = kk_std_core_types__list_unbox(_b_x1166, KK_OWNED, _ctx); /*list<string>*/
  _x_x2862 = kk_std_time_format__mlift_plocales_10646(_x_x2863, _ctx); /*string*/
  return kk_string_box(_x_x2862);
}
static kk_box_t kk_std_time_format_show_iso_fun2855(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_1_10834 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_iso_fun2856(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2859;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10834, _ctx);
    kk_box_t _x_x2860 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_iso_fun2861(_ctx), _ctx); /*10001*/
    _x_x2859 = kk_string_unbox(_x_x2860); /*string*/
  }
  else {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_2_0;
    if (kk_std_core_types__is_Nil(x_1_10834, _ctx)) {
      x_2_0 = kk_string_empty(); /*string*/
      goto _match_x2864;
    }
    {
      struct kk_std_core_types_Cons* _con_x2866 = kk_std_core_types__as_Cons(x_1_10834, _ctx);
      kk_box_t _box_x1167 = _con_x2866->head;
      kk_std_core_types__list _pat_1_1_0 = _con_x2866->tail;
      if (kk_std_core_types__is_Nil(_pat_1_1_0, _ctx)) {
        kk_string_t x_3 = kk_string_unbox(_box_x1167);
        if kk_likely(kk_datatype_ptr_is_unique(x_1_10834, _ctx)) {
          kk_datatype_ptr_free(x_1_10834, _ctx);
        }
        else {
          kk_string_dup(x_3, _ctx);
          kk_datatype_ptr_decref(x_1_10834, _ctx);
        }
        x_2_0 = x_3; /*string*/
        goto _match_x2864;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2867 = kk_std_core_types__as_Cons(x_1_10834, _ctx);
      kk_box_t _box_x1168 = _con_x2867->head;
      kk_std_core_types__list _pat_3_0_0_0 = _con_x2867->tail;
      struct kk_std_core_types_Cons* _con_x2868 = kk_std_core_types__as_Cons(_pat_3_0_0_0, _ctx);
      kk_box_t _box_x1169 = _con_x2868->head;
      kk_std_core_types__list _pat_4_0_0_0 = _con_x2868->tail;
      if (kk_std_core_types__is_Nil(_pat_4_0_0_0, _ctx)) {
        kk_string_t x_0_0_0 = kk_string_unbox(_box_x1168);
        kk_string_t y_0 = kk_string_unbox(_box_x1169);
        if kk_likely(kk_datatype_ptr_is_unique(x_1_10834, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_pat_3_0_0_0, _ctx);
          }
          else {
            kk_string_dup(y_0, _ctx);
            kk_datatype_ptr_decref(_pat_3_0_0_0, _ctx);
          }
          kk_datatype_ptr_free(x_1_10834, _ctx);
        }
        else {
          kk_string_dup(x_0_0_0, _ctx);
          kk_string_dup(y_0, _ctx);
          kk_datatype_ptr_decref(x_1_10834, _ctx);
        }
        x_2_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0_0, y_0, _ctx); /*string*/
        goto _match_x2864;
      }
    }
    {
      kk_vector_t _x_x2869 = kk_std_core_vector_unvlist(x_1_10834, _ctx); /*vector<10000>*/
      x_2_0 = kk_string_join(_x_x2869,kk_context()); /*string*/
    }
    _match_x2864: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    _x_x2859 = x_2_0; /*string*/
  }
  return kk_string_box(_x_x2859);
}

kk_string_t kk_std_time_format_show_iso(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : std/time/time/time) -> string */ 
  kk_string_t fmt_10200;
  kk_string_t _x_x2826;
  kk_define_string_literal(, _s_x2827, 17, "HH:mm:ssFFFFFFFFF", _ctx)
  _x_x2826 = kk_string_dup(_s_x2827, _ctx); /*string*/
  kk_string_t _x_x2828;
  kk_define_string_literal(, _s_x2829, 3, "Z C", _ctx)
  _x_x2828 = kk_string_dup(_s_x2829, _ctx); /*string*/
  fmt_10200 = kk_std_core_types__lp__plus__plus__rp_(_x_x2826, _x_x2828, _ctx); /*string*/
  kk_std_core_sslice__sslice _b_x1151_1153;
  kk_string_t _x_x2830 = kk_string_dup(fmt_10200, _ctx); /*string*/
  kk_integer_t _x_x2831;
  kk_string_t _x_x2832 = kk_string_dup(fmt_10200, _ctx); /*string*/
  _x_x2831 = kk_string_len_int(_x_x2832,kk_context()); /*int*/
  _b_x1151_1153 = kk_std_core_sslice__new_Sslice(_x_x2830, kk_integer_from_small(0), _x_x2831, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036 = kk_std_text_parse_parse_eof(_b_x1151_1153, kk_std_time_format_new_show_iso_fun2833(_ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  kk_std_core_sslice__sslice _b_x1170_1172;
  kk_string_t _x_x2848;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2849 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1156 = _con_x2849->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2849->rest;
    kk_string_t x_0_1 = kk_string_unbox(_box_x1156);
    kk_string_dup(x_0_1, _ctx);
    _x_x2848 = x_0_1; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2850 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0 = _con_x2850->rest;
    _x_x2848 = kk_string_dup(fmt_10200, _ctx); /*string*/
  }
  kk_integer_t _x_x2851;
  kk_string_t _x_x2852;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2853 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1158 = _con_x2853->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0 = _con_x2853->rest;
    kk_string_t x_0_1_0 = kk_string_unbox(_box_x1158);
    kk_string_dup(x_0_1_0, _ctx);
    _x_x2852 = x_0_1_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2854 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0 = _con_x2854->rest;
    _x_x2852 = kk_string_dup(fmt_10200, _ctx); /*string*/
  }
  _x_x2851 = kk_string_len_int(_x_x2852,kk_context()); /*int*/
  _b_x1170_1172 = kk_std_core_sslice__new_Sslice(_x_x2848, kk_integer_from_small(0), _x_x2851, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10209 = kk_std_text_parse_parse_eof(_b_x1170_1172, kk_std_time_format_new_show_iso_fun2855(_ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  kk_std_core_types__list fmt_0_10203;
  kk_string_t _x_x2870;
  if (kk_std_text_parse__is_ParseOk(perr_10209, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2871 = kk_std_text_parse__as_ParseOk(perr_10209, _ctx);
    kk_box_t _box_x1175 = _con_x2871->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0_0_0 = _con_x2871->rest;
    kk_string_t x_0_1_0_0 = kk_string_unbox(_box_x1175);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10209, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10209, _ctx);
    }
    else {
      kk_string_dup(x_0_1_0_0, _ctx);
      kk_datatype_ptr_decref(perr_10209, _ctx);
    }
    kk_std_text_parse__parse_error_drop(perr_10036, _ctx);
    kk_string_drop(fmt_10200, _ctx);
    _x_x2870 = x_0_1_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2872 = kk_std_text_parse__as_ParseError(perr_10209, _ctx);
    kk_std_core_sslice__sslice _pat_5_1 = _con_x2872->rest;
    kk_string_t msg_0_0 = _con_x2872->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10209, _ctx)) {
      kk_string_drop(msg_0_0, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5_1, _ctx);
      kk_datatype_ptr_free(perr_10209, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10209, _ctx);
    }
    if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2873 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
      kk_box_t _box_x1176 = _con_x2873->result;
      kk_std_core_sslice__sslice _pat_0_0_0_1 = _con_x2873->rest;
      kk_string_t x_0_1_1 = kk_string_unbox(_box_x1176);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_string_dup(x_0_1_1, _ctx);
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      kk_string_drop(fmt_10200, _ctx);
      _x_x2870 = x_0_1_1; /*string*/
    }
    else {
      struct kk_std_text_parse_ParseError* _con_x2874 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
      kk_std_core_sslice__sslice _pat_5_0_1 = _con_x2874->rest;
      kk_string_t msg_1 = _con_x2874->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_string_drop(msg_1, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      _x_x2870 = fmt_10200; /*string*/
    }
  }
  fmt_0_10203 = kk_std_core_string_list(_x_x2870, _ctx); /*list<char>*/
  kk_string_t _x_x2875;
  kk_std_time_time__time _x_x2876 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  _x_x2875 = kk_std_time_format_show_iso_date(_x_x2876, _ctx); /*string*/
  kk_string_t _x_x2877;
  kk_string_t _x_x2878;
  kk_define_string_literal(, _s_x2879, 1, "T", _ctx)
  _x_x2878 = kk_string_dup(_s_x2879, _ctx); /*string*/
  kk_string_t _x_x2880;
  if (kk_std_core_types__is_Nil(fmt_0_10203, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    _x_x2880 = kk_string_empty(); /*string*/
  }
  else {
    kk_std_time_locale__time_locale _x_x2882;
    kk_std_core_types__optional _match_x1308 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1308, _ctx)) {
      kk_box_t _box_x1179 = _match_x1308._cons._Optional.value;
      kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x1179, KK_BORROWED, _ctx);
      kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
      kk_std_core_types__optional_drop(_match_x1308, _ctx);
      _x_x2882 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1308, _ctx);
      _x_x2882 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
    }
    _x_x2880 = kk_std_time_format__unroll_format_list_10000(t, fmt_0_10203, _x_x2882, _ctx); /*string*/
  }
  _x_x2877 = kk_std_core_types__lp__plus__plus__rp_(_x_x2878, _x_x2880, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x2875, _x_x2877, _ctx);
}
 
// Show time as a standard [Internet Message Format](https://tools.ietf.org/html/rfc2822#section-3.3) date.
// For example `now().show-imf` returns `"Fri, 9 Oct 2016 11:57:45 -0700"`


// lift anonymous function
struct kk_std_time_format_show_imf_fun2891__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_imf_fun2891(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_imf_fun2891(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_imf_fun2891, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_imf_fun2892__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_imf_fun2892(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_imf_fun2892(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_imf_fun2892, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_imf_fun2892(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2893;
  kk_std_time_locale__time_locale _x_x2894;
  kk_std_core_types__optional _match_x1307 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1307, _ctx)) {
    kk_box_t _box_x1182 = _match_x1307._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097 = kk_std_time_locale__time_locale_unbox(_box_x1182, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097, _ctx);
    kk_std_core_types__optional_drop(_match_x1307, _ctx);
    _x_x2894 = _uniq_locale_5097; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1307, _ctx);
    _x_x2894 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2893 = kk_std_time_format_plocale(_x_x2894, _ctx); /*string*/
  return kk_string_box(_x_x2893);
}


// lift anonymous function
struct kk_std_time_format_show_imf_fun2897__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_imf_fun2897(kk_function_t _fself, kk_box_t _b_x1188, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_imf_fun2897(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_imf_fun2897, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_imf_fun2897(kk_function_t _fself, kk_box_t _b_x1188, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2898;
  kk_std_core_types__list _x_x2899 = kk_std_core_types__list_unbox(_b_x1188, KK_OWNED, _ctx); /*list<string>*/
  _x_x2898 = kk_std_time_format__mlift_plocales_10646(_x_x2899, _ctx); /*string*/
  return kk_string_box(_x_x2898);
}
static kk_box_t kk_std_time_format_show_imf_fun2891(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_10840 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_imf_fun2892(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2895;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10840, _ctx);
    kk_box_t _x_x2896 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_imf_fun2897(_ctx), _ctx); /*10001*/
    _x_x2895 = kk_string_unbox(_x_x2896); /*string*/
  }
  else {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10840, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x2900;
    }
    {
      struct kk_std_core_types_Cons* _con_x2902 = kk_std_core_types__as_Cons(x_10840, _ctx);
      kk_box_t _box_x1189 = _con_x2902->head;
      kk_std_core_types__list _pat_1_0 = _con_x2902->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x1189);
        if kk_likely(kk_datatype_ptr_is_unique(x_10840, _ctx)) {
          kk_datatype_ptr_free(x_10840, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10840, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x2900;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2903 = kk_std_core_types__as_Cons(x_10840, _ctx);
      kk_box_t _box_x1190 = _con_x2903->head;
      kk_std_core_types__list _pat_3 = _con_x2903->tail;
      struct kk_std_core_types_Cons* _con_x2904 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1191 = _con_x2904->head;
      kk_std_core_types__list _pat_4 = _con_x2904->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x1190);
        kk_string_t y = kk_string_unbox(_box_x1191);
        if kk_likely(kk_datatype_ptr_is_unique(x_10840, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10840, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10840, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x2900;
      }
    }
    {
      kk_vector_t _x_x2905 = kk_std_core_vector_unvlist(x_10840, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x2905,kk_context()); /*string*/
    }
    _match_x2900: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    _x_x2895 = x_0; /*string*/
  }
  return kk_string_box(_x_x2895);
}


// lift anonymous function
struct kk_std_time_format_show_imf_fun2915__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_imf_fun2915(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_imf_fun2915(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_imf_fun2915, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_imf_fun2916__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_imf_fun2916(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_imf_fun2916(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_imf_fun2916, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_imf_fun2916(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2917;
  kk_std_time_locale__time_locale _x_x2918;
  kk_std_core_types__optional _match_x1305 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1305, _ctx)) {
    kk_box_t _box_x1201 = _match_x1305._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5097_0 = kk_std_time_locale__time_locale_unbox(_box_x1201, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5097_0, _ctx);
    kk_std_core_types__optional_drop(_match_x1305, _ctx);
    _x_x2918 = _uniq_locale_5097_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1305, _ctx);
    _x_x2918 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2917 = kk_std_time_format_plocale(_x_x2918, _ctx); /*string*/
  return kk_string_box(_x_x2917);
}


// lift anonymous function
struct kk_std_time_format_show_imf_fun2921__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_imf_fun2921(kk_function_t _fself, kk_box_t _b_x1207, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_imf_fun2921(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_imf_fun2921, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_imf_fun2921(kk_function_t _fself, kk_box_t _b_x1207, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2922;
  kk_std_core_types__list _x_x2923 = kk_std_core_types__list_unbox(_b_x1207, KK_OWNED, _ctx); /*list<string>*/
  _x_x2922 = kk_std_time_format__mlift_plocales_10646(_x_x2923, _ctx); /*string*/
  return kk_string_box(_x_x2922);
}
static kk_box_t kk_std_time_format_show_imf_fun2915(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list x_3_10846 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_imf_fun2916(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2919;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_3_10846, _ctx);
    kk_box_t _x_x2920 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_imf_fun2921(_ctx), _ctx); /*10001*/
    _x_x2919 = kk_string_unbox(_x_x2920); /*string*/
  }
  else {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_4;
    if (kk_std_core_types__is_Nil(x_3_10846, _ctx)) {
      x_4 = kk_string_empty(); /*string*/
      goto _match_x2924;
    }
    {
      struct kk_std_core_types_Cons* _con_x2926 = kk_std_core_types__as_Cons(x_3_10846, _ctx);
      kk_box_t _box_x1208 = _con_x2926->head;
      kk_std_core_types__list _pat_1_2 = _con_x2926->tail;
      if (kk_std_core_types__is_Nil(_pat_1_2, _ctx)) {
        kk_string_t x_5 = kk_string_unbox(_box_x1208);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10846, _ctx)) {
          kk_datatype_ptr_free(x_3_10846, _ctx);
        }
        else {
          kk_string_dup(x_5, _ctx);
          kk_datatype_ptr_decref(x_3_10846, _ctx);
        }
        x_4 = x_5; /*string*/
        goto _match_x2924;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2927 = kk_std_core_types__as_Cons(x_3_10846, _ctx);
      kk_box_t _box_x1209 = _con_x2927->head;
      kk_std_core_types__list _pat_3_1 = _con_x2927->tail;
      struct kk_std_core_types_Cons* _con_x2928 = kk_std_core_types__as_Cons(_pat_3_1, _ctx);
      kk_box_t _box_x1210 = _con_x2928->head;
      kk_std_core_types__list _pat_4_1 = _con_x2928->tail;
      if (kk_std_core_types__is_Nil(_pat_4_1, _ctx)) {
        kk_string_t x_0_2 = kk_string_unbox(_box_x1209);
        kk_string_t y_0 = kk_string_unbox(_box_x1210);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10846, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_datatype_ptr_free(_pat_3_1, _ctx);
          }
          else {
            kk_string_dup(y_0, _ctx);
            kk_datatype_ptr_decref(_pat_3_1, _ctx);
          }
          kk_datatype_ptr_free(x_3_10846, _ctx);
        }
        else {
          kk_string_dup(x_0_2, _ctx);
          kk_string_dup(y_0, _ctx);
          kk_datatype_ptr_decref(x_3_10846, _ctx);
        }
        x_4 = kk_std_core_types__lp__plus__plus__rp_(x_0_2, y_0, _ctx); /*string*/
        goto _match_x2924;
      }
    }
    {
      kk_vector_t _x_x2929 = kk_std_core_vector_unvlist(x_3_10846, _ctx); /*vector<10000>*/
      x_4 = kk_string_join(_x_x2929,kk_context()); /*string*/
    }
    _match_x2924: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    _x_x2919 = x_4; /*string*/
  }
  return kk_string_box(_x_x2919);
}

kk_string_t kk_std_time_format_show_imf(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : std/time/time/time) -> string */ 
  kk_std_time_time__time t_0_10211;
  kk_std_core_types__optional _x_x2883;
  kk_box_t _x_x2884;
  kk_std_time_calendar__calendar _x_x2885 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  _x_x2884 = kk_std_time_calendar__calendar_box(_x_x2885, _ctx); /*10003*/
  _x_x2883 = kk_std_core_types__new_Optional(_x_x2884, _ctx); /*? 10003*/
  t_0_10211 = kk_std_time_time_time_fs_time(t, kk_std_core_types__new_None(_ctx), _x_x2883, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  kk_std_core_sslice__sslice _b_x1192_1194;
  kk_string_t _x_x2886;
  kk_define_string_literal(, _s_x2887, 24, "ddd, D MMM Y HH:mm:ss zz", _ctx)
  _x_x2886 = kk_string_dup(_s_x2887, _ctx); /*string*/
  kk_integer_t _x_x2888;
  kk_string_t _x_x2889;
  kk_define_string_literal(, _s_x2890, 24, "ddd, D MMM Y HH:mm:ss zz", _ctx)
  _x_x2889 = kk_string_dup(_s_x2890, _ctx); /*string*/
  _x_x2888 = kk_string_len_int(_x_x2889,kk_context()); /*int*/
  _b_x1192_1194 = kk_std_core_sslice__new_Sslice(_x_x2886, kk_integer_from_small(0), _x_x2888, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036 = kk_std_text_parse_parse_eof(_b_x1192_1194, kk_std_time_format_new_show_imf_fun2891(_ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  kk_std_core_sslice__sslice _b_x1211_1213;
  kk_string_t _x_x2906;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2907 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1197 = _con_x2907->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2907->rest;
    kk_string_t x_0_1 = kk_string_unbox(_box_x1197);
    kk_string_dup(x_0_1, _ctx);
    _x_x2906 = x_0_1; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2908 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0 = _con_x2908->rest;
    kk_define_string_literal(, _s_x2909, 24, "ddd, D MMM Y HH:mm:ss zz", _ctx)
    _x_x2906 = kk_string_dup(_s_x2909, _ctx); /*string*/
  }
  kk_integer_t _x_x2910;
  kk_string_t _x_x2911;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2912 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1199 = _con_x2912->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0 = _con_x2912->rest;
    kk_string_t x_0_0_0 = kk_string_unbox(_box_x1199);
    kk_string_dup(x_0_0_0, _ctx);
    _x_x2911 = x_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2913 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0 = _con_x2913->rest;
    kk_define_string_literal(, _s_x2914, 24, "ddd, D MMM Y HH:mm:ss zz", _ctx)
    _x_x2911 = kk_string_dup(_s_x2914, _ctx); /*string*/
  }
  _x_x2910 = kk_string_len_int(_x_x2911,kk_context()); /*int*/
  _b_x1211_1213 = kk_std_core_sslice__new_Sslice(_x_x2906, kk_integer_from_small(0), _x_x2910, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10221 = kk_std_text_parse_parse_eof(_b_x1211_1213, kk_std_time_format_new_show_imf_fun2915(_ctx), _ctx); /*std/text/parse/parse-error<string>*/;
  kk_std_core_types__list fmt_0_10215;
  kk_string_t _x_x2930;
  if (kk_std_text_parse__is_ParseOk(perr_10221, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2931 = kk_std_text_parse__as_ParseOk(perr_10221, _ctx);
    kk_box_t _box_x1216 = _con_x2931->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0_0 = _con_x2931->rest;
    kk_string_t x_0_0_0_0 = kk_string_unbox(_box_x1216);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10221, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10221, _ctx);
    }
    else {
      kk_string_dup(x_0_0_0_0, _ctx);
      kk_datatype_ptr_decref(perr_10221, _ctx);
    }
    kk_std_text_parse__parse_error_drop(perr_10036, _ctx);
    _x_x2930 = x_0_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2932 = kk_std_text_parse__as_ParseError(perr_10221, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0_0 = _con_x2932->rest;
    kk_string_t msg_0_0 = _con_x2932->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10221, _ctx)) {
      kk_string_drop(msg_0_0, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10221, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10221, _ctx);
    }
    if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2933 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
      kk_box_t _box_x1217 = _con_x2933->result;
      kk_std_core_sslice__sslice _pat_0_0_1 = _con_x2933->rest;
      kk_string_t x_0_1_0 = kk_string_unbox(_box_x1217);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_string_dup(x_0_1_0, _ctx);
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      _x_x2930 = x_0_1_0; /*string*/
    }
    else {
      struct kk_std_text_parse_ParseError* _con_x2934 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
      kk_std_core_sslice__sslice _pat_5_1_0 = _con_x2934->rest;
      kk_string_t msg_1 = _con_x2934->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_string_drop(msg_1, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5_1_0, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      kk_define_string_literal(, _s_x2935, 24, "ddd, D MMM Y HH:mm:ss zz", _ctx)
      _x_x2930 = kk_string_dup(_s_x2935, _ctx); /*string*/
    }
  }
  fmt_0_10215 = kk_std_core_string_list(_x_x2930, _ctx); /*list<char>*/
  if (kk_std_core_types__is_Nil(fmt_0_10215, _ctx)) {
    kk_datatype_ptr_dropn(t_0_10211, (KK_I32(9)), _ctx);
    return kk_string_empty();
  }
  {
    kk_std_time_locale__time_locale _x_x2937;
    kk_std_core_types__optional _match_x1303 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x1303, _ctx)) {
      kk_box_t _box_x1220 = _match_x1303._cons._Optional.value;
      kk_std_time_locale__time_locale _uniq_locale_5097_1 = kk_std_time_locale__time_locale_unbox(_box_x1220, KK_BORROWED, _ctx);
      kk_std_time_locale__time_locale_dup(_uniq_locale_5097_1, _ctx);
      kk_std_core_types__optional_drop(_match_x1303, _ctx);
      _x_x2937 = _uniq_locale_5097_1; /*std/time/locale/time-locale*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x1303, _ctx);
      _x_x2937 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
    }
    return kk_std_time_format__unroll_format_list_10000(t_0_10211, fmt_0_10215, _x_x2937, _ctx);
  }
}
 
// Show the time as a human readable string in the given `locale` (=`time-locale-en`)
// For example `now().show-en` -> `"Thu, 8 Oct 2016, 12:20pm"`. Uses the `"llll"` format string.


// lift anonymous function
struct kk_std_time_format_show_in_locale_fun2944__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_fun2944(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_fun2944(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2944__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_fun2944__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_fun2944, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_in_locale_fun2945__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_fun2945(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_fun2945(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2945__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_fun2945__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_fun2945, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_fun2945(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2945__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_fun2945__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2946;
  kk_std_time_locale__time_locale _x_x2947;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x1221 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5223 = kk_std_time_locale__time_locale_unbox(_box_x1221, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5223, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2947 = _uniq_locale_5223; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2947 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2946 = kk_std_time_format_plocale(_x_x2947, _ctx); /*string*/
  return kk_string_box(_x_x2946);
}


// lift anonymous function
struct kk_std_time_format_show_in_locale_fun2950__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_in_locale_fun2950(kk_function_t _fself, kk_box_t _b_x1227, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_fun2950(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_in_locale_fun2950, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_fun2950(kk_function_t _fself, kk_box_t _b_x1227, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2951;
  kk_std_core_types__list _x_x2952 = kk_std_core_types__list_unbox(_b_x1227, KK_OWNED, _ctx); /*list<string>*/
  _x_x2951 = kk_std_time_format__mlift_plocales_10646(_x_x2952, _ctx); /*string*/
  return kk_string_box(_x_x2951);
}
static kk_box_t kk_std_time_format_show_in_locale_fun2944(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2944__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_fun2944__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_10852 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_in_locale_fun2945(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2948;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10852, _ctx);
    kk_box_t _x_x2949 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_in_locale_fun2950(_ctx), _ctx); /*10001*/
    _x_x2948 = kk_string_unbox(_x_x2949); /*string*/
  }
  else {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10852, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x2953;
    }
    {
      struct kk_std_core_types_Cons* _con_x2955 = kk_std_core_types__as_Cons(x_10852, _ctx);
      kk_box_t _box_x1228 = _con_x2955->head;
      kk_std_core_types__list _pat_1_0 = _con_x2955->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x1228);
        if kk_likely(kk_datatype_ptr_is_unique(x_10852, _ctx)) {
          kk_datatype_ptr_free(x_10852, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10852, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x2953;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2956 = kk_std_core_types__as_Cons(x_10852, _ctx);
      kk_box_t _box_x1229 = _con_x2956->head;
      kk_std_core_types__list _pat_3 = _con_x2956->tail;
      struct kk_std_core_types_Cons* _con_x2957 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1230 = _con_x2957->head;
      kk_std_core_types__list _pat_4 = _con_x2957->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x1229);
        kk_string_t y = kk_string_unbox(_box_x1230);
        if kk_likely(kk_datatype_ptr_is_unique(x_10852, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10852, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10852, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x2953;
      }
    }
    {
      kk_vector_t _x_x2958 = kk_std_core_vector_unvlist(x_10852, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x2958,kk_context()); /*string*/
    }
    _match_x2953: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    _x_x2948 = x_0; /*string*/
  }
  return kk_string_box(_x_x2948);
}


// lift anonymous function
struct kk_std_time_format_show_in_locale_fun2969__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_fun2969(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_fun2969(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2969__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_fun2969__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_fun2969, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_in_locale_fun2970__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_fun2970(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_fun2970(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2970__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_fun2970__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_fun2970, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_fun2970(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2970__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_fun2970__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x2971;
  kk_std_time_locale__time_locale _x_x2972;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x1240 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5223_0 = kk_std_time_locale__time_locale_unbox(_box_x1240, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5223_0, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2972 = _uniq_locale_5223_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x2972 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x2971 = kk_std_time_format_plocale(_x_x2972, _ctx); /*string*/
  return kk_string_box(_x_x2971);
}


// lift anonymous function
struct kk_std_time_format_show_in_locale_fun2975__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_in_locale_fun2975(kk_function_t _fself, kk_box_t _b_x1246, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_fun2975(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_in_locale_fun2975, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_fun2975(kk_function_t _fself, kk_box_t _b_x1246, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2976;
  kk_std_core_types__list _x_x2977 = kk_std_core_types__list_unbox(_b_x1246, KK_OWNED, _ctx); /*list<string>*/
  _x_x2976 = kk_std_time_format__mlift_plocales_10646(_x_x2977, _ctx); /*string*/
  return kk_string_box(_x_x2976);
}
static kk_box_t kk_std_time_format_show_in_locale_fun2969(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_fun2969__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_fun2969__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_3_10858 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_in_locale_fun2970(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x2973;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_3_10858, _ctx);
    kk_box_t _x_x2974 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_in_locale_fun2975(_ctx), _ctx); /*10001*/
    _x_x2973 = kk_string_unbox(_x_x2974); /*string*/
  }
  else {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_4;
    if (kk_std_core_types__is_Nil(x_3_10858, _ctx)) {
      x_4 = kk_string_empty(); /*string*/
      goto _match_x2978;
    }
    {
      struct kk_std_core_types_Cons* _con_x2980 = kk_std_core_types__as_Cons(x_3_10858, _ctx);
      kk_box_t _box_x1247 = _con_x2980->head;
      kk_std_core_types__list _pat_1_2 = _con_x2980->tail;
      if (kk_std_core_types__is_Nil(_pat_1_2, _ctx)) {
        kk_string_t x_5 = kk_string_unbox(_box_x1247);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10858, _ctx)) {
          kk_datatype_ptr_free(x_3_10858, _ctx);
        }
        else {
          kk_string_dup(x_5, _ctx);
          kk_datatype_ptr_decref(x_3_10858, _ctx);
        }
        x_4 = x_5; /*string*/
        goto _match_x2978;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x2981 = kk_std_core_types__as_Cons(x_3_10858, _ctx);
      kk_box_t _box_x1248 = _con_x2981->head;
      kk_std_core_types__list _pat_3_1 = _con_x2981->tail;
      struct kk_std_core_types_Cons* _con_x2982 = kk_std_core_types__as_Cons(_pat_3_1, _ctx);
      kk_box_t _box_x1249 = _con_x2982->head;
      kk_std_core_types__list _pat_4_1 = _con_x2982->tail;
      if (kk_std_core_types__is_Nil(_pat_4_1, _ctx)) {
        kk_string_t x_0_2 = kk_string_unbox(_box_x1248);
        kk_string_t y_0 = kk_string_unbox(_box_x1249);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10858, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_datatype_ptr_free(_pat_3_1, _ctx);
          }
          else {
            kk_string_dup(y_0, _ctx);
            kk_datatype_ptr_decref(_pat_3_1, _ctx);
          }
          kk_datatype_ptr_free(x_3_10858, _ctx);
        }
        else {
          kk_string_dup(x_0_2, _ctx);
          kk_string_dup(y_0, _ctx);
          kk_datatype_ptr_decref(x_3_10858, _ctx);
        }
        x_4 = kk_std_core_types__lp__plus__plus__rp_(x_0_2, y_0, _ctx); /*string*/
        goto _match_x2978;
      }
    }
    {
      kk_vector_t _x_x2983 = kk_std_core_vector_unvlist(x_3_10858, _ctx); /*vector<10000>*/
      x_4 = kk_string_join(_x_x2983,kk_context()); /*string*/
    }
    _match_x2978: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    _x_x2973 = x_4; /*string*/
  }
  return kk_string_box(_x_x2973);
}

kk_string_t kk_std_time_format_show_in_locale(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx) { /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 
  kk_std_core_sslice__sslice _b_x1231_1233;
  kk_string_t _x_x2938;
  kk_define_string_literal(, _s_x2939, 4, "llll", _ctx)
  _x_x2938 = kk_string_dup(_s_x2939, _ctx); /*string*/
  kk_integer_t _x_x2940;
  kk_string_t _x_x2941;
  kk_define_string_literal(, _s_x2942, 4, "llll", _ctx)
  _x_x2941 = kk_string_dup(_s_x2942, _ctx); /*string*/
  _x_x2940 = kk_string_len_int(_x_x2941,kk_context()); /*int*/
  _b_x1231_1233 = kk_std_core_sslice__new_Sslice(_x_x2938, kk_integer_from_small(0), _x_x2940, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036;
  kk_function_t _x_x2943;
  kk_std_core_types__optional_dup(locale, _ctx);
  _x_x2943 = kk_std_time_format_new_show_in_locale_fun2944(locale, _ctx); /*() -> <std/text/parse/parse|10001> 10000*/
  perr_10036 = kk_std_text_parse_parse_eof(_b_x1231_1233, _x_x2943, _ctx); /*std/text/parse/parse-error<string>*/
  kk_std_core_sslice__sslice _b_x1250_1252;
  kk_string_t _x_x2959;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2960 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1236 = _con_x2960->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x2960->rest;
    kk_string_t x_0_1 = kk_string_unbox(_box_x1236);
    kk_string_dup(x_0_1, _ctx);
    _x_x2959 = x_0_1; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2961 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0 = _con_x2961->rest;
    kk_define_string_literal(, _s_x2962, 4, "llll", _ctx)
    _x_x2959 = kk_string_dup(_s_x2962, _ctx); /*string*/
  }
  kk_integer_t _x_x2963;
  kk_string_t _x_x2964;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2965 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1238 = _con_x2965->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0 = _con_x2965->rest;
    kk_string_t x_0_0_0 = kk_string_unbox(_box_x1238);
    kk_string_dup(x_0_0_0, _ctx);
    _x_x2964 = x_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2966 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0 = _con_x2966->rest;
    kk_define_string_literal(, _s_x2967, 4, "llll", _ctx)
    _x_x2964 = kk_string_dup(_s_x2967, _ctx); /*string*/
  }
  _x_x2963 = kk_string_len_int(_x_x2964,kk_context()); /*int*/
  _b_x1250_1252 = kk_std_core_sslice__new_Sslice(_x_x2959, kk_integer_from_small(0), _x_x2963, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10233;
  kk_function_t _x_x2968;
  kk_std_core_types__optional_dup(locale, _ctx);
  _x_x2968 = kk_std_time_format_new_show_in_locale_fun2969(locale, _ctx); /*() -> <std/text/parse/parse|10001> 10000*/
  perr_10233 = kk_std_text_parse_parse_eof(_b_x1250_1252, _x_x2968, _ctx); /*std/text/parse/parse-error<string>*/
  kk_std_core_types__list fmt_0_10227;
  kk_string_t _x_x2984;
  if (kk_std_text_parse__is_ParseOk(perr_10233, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2985 = kk_std_text_parse__as_ParseOk(perr_10233, _ctx);
    kk_box_t _box_x1255 = _con_x2985->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0_0 = _con_x2985->rest;
    kk_string_t x_0_0_0_0 = kk_string_unbox(_box_x1255);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10233, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10233, _ctx);
    }
    else {
      kk_string_dup(x_0_0_0_0, _ctx);
      kk_datatype_ptr_decref(perr_10233, _ctx);
    }
    kk_std_text_parse__parse_error_drop(perr_10036, _ctx);
    _x_x2984 = x_0_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x2986 = kk_std_text_parse__as_ParseError(perr_10233, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0_0 = _con_x2986->rest;
    kk_string_t msg_0_0 = _con_x2986->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10233, _ctx)) {
      kk_string_drop(msg_0_0, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10233, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10233, _ctx);
    }
    if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2987 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
      kk_box_t _box_x1256 = _con_x2987->result;
      kk_std_core_sslice__sslice _pat_0_0_1 = _con_x2987->rest;
      kk_string_t x_0_1_0 = kk_string_unbox(_box_x1256);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_string_dup(x_0_1_0, _ctx);
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      _x_x2984 = x_0_1_0; /*string*/
    }
    else {
      struct kk_std_text_parse_ParseError* _con_x2988 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
      kk_std_core_sslice__sslice _pat_5_1_0 = _con_x2988->rest;
      kk_string_t msg_1 = _con_x2988->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_string_drop(msg_1, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5_1_0, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      kk_define_string_literal(, _s_x2989, 4, "llll", _ctx)
      _x_x2984 = kk_string_dup(_s_x2989, _ctx); /*string*/
    }
  }
  fmt_0_10227 = kk_std_core_string_list(_x_x2984, _ctx); /*list<char>*/
  if (kk_std_core_types__is_Nil(fmt_0_10227, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    return kk_string_empty();
  }
  {
    kk_std_time_locale__time_locale _x_x2991;
    if (kk_std_core_types__is_Optional(locale, _ctx)) {
      kk_box_t _box_x1259 = locale._cons._Optional.value;
      kk_std_time_locale__time_locale _uniq_locale_5223_1 = kk_std_time_locale__time_locale_unbox(_box_x1259, KK_BORROWED, _ctx);
      kk_std_time_locale__time_locale_dup(_uniq_locale_5223_1, _ctx);
      kk_std_core_types__optional_drop(locale, _ctx);
      _x_x2991 = _uniq_locale_5223_1; /*std/time/locale/time-locale*/
    }
    else {
      kk_std_core_types__optional_drop(locale, _ctx);
      _x_x2991 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
    }
    return kk_std_time_format__unroll_format_list_10000(t, fmt_0_10227, _x_x2991, _ctx);
  }
}
 
// Show the date in human readable string in the given `locale` (=`time-locale-en`).
// For example `now().show-en-date` -> `"Thu, 8 Oct 2016"`. Uses the `"ll"` format string.


// lift anonymous function
struct kk_std_time_format_show_in_locale_date_fun2998__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_date_fun2998(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_date_fun2998(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun2998__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_date_fun2998__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_date_fun2998, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_in_locale_date_fun2999__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_date_fun2999(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_date_fun2999(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun2999__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_date_fun2999__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_date_fun2999, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_date_fun2999(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun2999__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_date_fun2999__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x3000;
  kk_std_time_locale__time_locale _x_x3001;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x1260 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5244 = kk_std_time_locale__time_locale_unbox(_box_x1260, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5244, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x3001 = _uniq_locale_5244; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x3001 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x3000 = kk_std_time_format_plocale(_x_x3001, _ctx); /*string*/
  return kk_string_box(_x_x3000);
}


// lift anonymous function
struct kk_std_time_format_show_in_locale_date_fun3004__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_in_locale_date_fun3004(kk_function_t _fself, kk_box_t _b_x1266, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_date_fun3004(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_in_locale_date_fun3004, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_date_fun3004(kk_function_t _fself, kk_box_t _b_x1266, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x3005;
  kk_std_core_types__list _x_x3006 = kk_std_core_types__list_unbox(_b_x1266, KK_OWNED, _ctx); /*list<string>*/
  _x_x3005 = kk_std_time_format__mlift_plocales_10646(_x_x3006, _ctx); /*string*/
  return kk_string_box(_x_x3005);
}
static kk_box_t kk_std_time_format_show_in_locale_date_fun2998(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun2998__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_date_fun2998__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_10864 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_in_locale_date_fun2999(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x3002;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10864, _ctx);
    kk_box_t _x_x3003 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_in_locale_date_fun3004(_ctx), _ctx); /*10001*/
    _x_x3002 = kk_string_unbox(_x_x3003); /*string*/
  }
  else {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_0;
    if (kk_std_core_types__is_Nil(x_10864, _ctx)) {
      x_0 = kk_string_empty(); /*string*/
      goto _match_x3007;
    }
    {
      struct kk_std_core_types_Cons* _con_x3009 = kk_std_core_types__as_Cons(x_10864, _ctx);
      kk_box_t _box_x1267 = _con_x3009->head;
      kk_std_core_types__list _pat_1_0 = _con_x3009->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_1 = kk_string_unbox(_box_x1267);
        if kk_likely(kk_datatype_ptr_is_unique(x_10864, _ctx)) {
          kk_datatype_ptr_free(x_10864, _ctx);
        }
        else {
          kk_string_dup(x_1, _ctx);
          kk_datatype_ptr_decref(x_10864, _ctx);
        }
        x_0 = x_1; /*string*/
        goto _match_x3007;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x3010 = kk_std_core_types__as_Cons(x_10864, _ctx);
      kk_box_t _box_x1268 = _con_x3010->head;
      kk_std_core_types__list _pat_3 = _con_x3010->tail;
      struct kk_std_core_types_Cons* _con_x3011 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1269 = _con_x3011->head;
      kk_std_core_types__list _pat_4 = _con_x3011->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t x_0_0 = kk_string_unbox(_box_x1268);
        kk_string_t y = kk_string_unbox(_box_x1269);
        if kk_likely(kk_datatype_ptr_is_unique(x_10864, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
            kk_datatype_ptr_free(_pat_3, _ctx);
          }
          else {
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_pat_3, _ctx);
          }
          kk_datatype_ptr_free(x_10864, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(x_10864, _ctx);
        }
        x_0 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
        goto _match_x3007;
      }
    }
    {
      kk_vector_t _x_x3012 = kk_std_core_vector_unvlist(x_10864, _ctx); /*vector<10000>*/
      x_0 = kk_string_join(_x_x3012,kk_context()); /*string*/
    }
    _match_x3007: ;
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    _x_x3002 = x_0; /*string*/
  }
  return kk_string_box(_x_x3002);
}


// lift anonymous function
struct kk_std_time_format_show_in_locale_date_fun3023__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_date_fun3023(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_date_fun3023(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun3023__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_date_fun3023__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_date_fun3023, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_time_format_show_in_locale_date_fun3024__t {
  struct kk_function_s _base;
  kk_std_core_types__optional locale;
};
static kk_box_t kk_std_time_format_show_in_locale_date_fun3024(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_date_fun3024(kk_std_core_types__optional locale, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun3024__t* _self = kk_function_alloc_as(struct kk_std_time_format_show_in_locale_date_fun3024__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_format_show_in_locale_date_fun3024, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_date_fun3024(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun3024__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_date_fun3024__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_string_t _x_x3025;
  kk_std_time_locale__time_locale _x_x3026;
  if (kk_std_core_types__is_Optional(locale, _ctx)) {
    kk_box_t _box_x1279 = locale._cons._Optional.value;
    kk_std_time_locale__time_locale _uniq_locale_5244_0 = kk_std_time_locale__time_locale_unbox(_box_x1279, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(_uniq_locale_5244_0, _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x3026 = _uniq_locale_5244_0; /*std/time/locale/time-locale*/
  }
  else {
    kk_std_core_types__optional_drop(locale, _ctx);
    _x_x3026 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
  }
  _x_x3025 = kk_std_time_format_plocale(_x_x3026, _ctx); /*string*/
  return kk_string_box(_x_x3025);
}


// lift anonymous function
struct kk_std_time_format_show_in_locale_date_fun3029__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_format_show_in_locale_date_fun3029(kk_function_t _fself, kk_box_t _b_x1285, kk_context_t* _ctx);
static kk_function_t kk_std_time_format_new_show_in_locale_date_fun3029(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_format_show_in_locale_date_fun3029, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_format_show_in_locale_date_fun3029(kk_function_t _fself, kk_box_t _b_x1285, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x3030;
  kk_std_core_types__list _x_x3031 = kk_std_core_types__list_unbox(_b_x1285, KK_OWNED, _ctx); /*list<string>*/
  _x_x3030 = kk_std_time_format__mlift_plocales_10646(_x_x3031, _ctx); /*string*/
  return kk_string_box(_x_x3030);
}
static kk_box_t kk_std_time_format_show_in_locale_date_fun3023(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_format_show_in_locale_date_fun3023__t* _self = kk_function_as(struct kk_std_time_format_show_in_locale_date_fun3023__t*, _fself, _ctx);
  kk_std_core_types__optional locale = _self->locale; /* ? std/time/locale/time-locale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__list x_3_10870 = kk_std_text_parse_many_acc(kk_std_time_format_new_show_in_locale_date_fun3024(locale, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/;
  kk_string_t _x_x3027;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_3_10870, _ctx);
    kk_box_t _x_x3028 = kk_std_core_hnd_yield_extend(kk_std_time_format_new_show_in_locale_date_fun3029(_ctx), _ctx); /*10001*/
    _x_x3027 = kk_string_unbox(_x_x3028); /*string*/
  }
  else {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
    kk_string_t x_4;
    if (kk_std_core_types__is_Nil(x_3_10870, _ctx)) {
      x_4 = kk_string_empty(); /*string*/
      goto _match_x3032;
    }
    {
      struct kk_std_core_types_Cons* _con_x3034 = kk_std_core_types__as_Cons(x_3_10870, _ctx);
      kk_box_t _box_x1286 = _con_x3034->head;
      kk_std_core_types__list _pat_1_2 = _con_x3034->tail;
      if (kk_std_core_types__is_Nil(_pat_1_2, _ctx)) {
        kk_string_t x_5 = kk_string_unbox(_box_x1286);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10870, _ctx)) {
          kk_datatype_ptr_free(x_3_10870, _ctx);
        }
        else {
          kk_string_dup(x_5, _ctx);
          kk_datatype_ptr_decref(x_3_10870, _ctx);
        }
        x_4 = x_5; /*string*/
        goto _match_x3032;
      }
    }
    {
      struct kk_std_core_types_Cons* _con_x3035 = kk_std_core_types__as_Cons(x_3_10870, _ctx);
      kk_box_t _box_x1287 = _con_x3035->head;
      kk_std_core_types__list _pat_3_1 = _con_x3035->tail;
      struct kk_std_core_types_Cons* _con_x3036 = kk_std_core_types__as_Cons(_pat_3_1, _ctx);
      kk_box_t _box_x1288 = _con_x3036->head;
      kk_std_core_types__list _pat_4_1 = _con_x3036->tail;
      if (kk_std_core_types__is_Nil(_pat_4_1, _ctx)) {
        kk_string_t x_0_2 = kk_string_unbox(_box_x1287);
        kk_string_t y_0 = kk_string_unbox(_box_x1288);
        if kk_likely(kk_datatype_ptr_is_unique(x_3_10870, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
            kk_datatype_ptr_free(_pat_3_1, _ctx);
          }
          else {
            kk_string_dup(y_0, _ctx);
            kk_datatype_ptr_decref(_pat_3_1, _ctx);
          }
          kk_datatype_ptr_free(x_3_10870, _ctx);
        }
        else {
          kk_string_dup(x_0_2, _ctx);
          kk_string_dup(y_0, _ctx);
          kk_datatype_ptr_decref(x_3_10870, _ctx);
        }
        x_4 = kk_std_core_types__lp__plus__plus__rp_(x_0_2, y_0, _ctx); /*string*/
        goto _match_x3032;
      }
    }
    {
      kk_vector_t _x_x3037 = kk_std_core_vector_unvlist(x_3_10870, _ctx); /*vector<10000>*/
      x_4 = kk_string_join(_x_x3037,kk_context()); /*string*/
    }
    _match_x3032: ;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    _x_x3027 = x_4; /*string*/
  }
  return kk_string_box(_x_x3027);
}

kk_string_t kk_std_time_format_show_in_locale_date(kk_std_time_time__time t, kk_std_core_types__optional locale, kk_context_t* _ctx) { /* (t : std/time/time/time, locale : ? std/time/locale/time-locale) -> string */ 
  kk_std_core_sslice__sslice _b_x1270_1272;
  kk_string_t _x_x2992;
  kk_define_string_literal(, _s_x2993, 2, "ll", _ctx)
  _x_x2992 = kk_string_dup(_s_x2993, _ctx); /*string*/
  kk_integer_t _x_x2994;
  kk_string_t _x_x2995;
  kk_define_string_literal(, _s_x2996, 2, "ll", _ctx)
  _x_x2995 = kk_string_dup(_s_x2996, _ctx); /*string*/
  _x_x2994 = kk_string_len_int(_x_x2995,kk_context()); /*int*/
  _b_x1270_1272 = kk_std_core_sslice__new_Sslice(_x_x2992, kk_integer_from_small(0), _x_x2994, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10036;
  kk_function_t _x_x2997;
  kk_std_core_types__optional_dup(locale, _ctx);
  _x_x2997 = kk_std_time_format_new_show_in_locale_date_fun2998(locale, _ctx); /*() -> <std/text/parse/parse|10001> 10000*/
  perr_10036 = kk_std_text_parse_parse_eof(_b_x1270_1272, _x_x2997, _ctx); /*std/text/parse/parse-error<string>*/
  kk_std_core_sslice__sslice _b_x1289_1291;
  kk_string_t _x_x3013;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x3014 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1275 = _con_x3014->result;
    kk_std_core_sslice__sslice _pat_0_0_0 = _con_x3014->rest;
    kk_string_t x_0_1 = kk_string_unbox(_box_x1275);
    kk_string_dup(x_0_1, _ctx);
    _x_x3013 = x_0_1; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x3015 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0 = _con_x3015->rest;
    kk_define_string_literal(, _s_x3016, 2, "ll", _ctx)
    _x_x3013 = kk_string_dup(_s_x3016, _ctx); /*string*/
  }
  kk_integer_t _x_x3017;
  kk_string_t _x_x3018;
  if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x3019 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
    kk_box_t _box_x1277 = _con_x3019->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0 = _con_x3019->rest;
    kk_string_t x_0_0_0 = kk_string_unbox(_box_x1277);
    kk_string_dup(x_0_0_0, _ctx);
    _x_x3018 = x_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x3020 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0 = _con_x3020->rest;
    kk_define_string_literal(, _s_x3021, 2, "ll", _ctx)
    _x_x3018 = kk_string_dup(_s_x3021, _ctx); /*string*/
  }
  _x_x3017 = kk_string_len_int(_x_x3018,kk_context()); /*int*/
  _b_x1289_1291 = kk_std_core_sslice__new_Sslice(_x_x3013, kk_integer_from_small(0), _x_x3017, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error perr_10245;
  kk_function_t _x_x3022;
  kk_std_core_types__optional_dup(locale, _ctx);
  _x_x3022 = kk_std_time_format_new_show_in_locale_date_fun3023(locale, _ctx); /*() -> <std/text/parse/parse|10001> 10000*/
  perr_10245 = kk_std_text_parse_parse_eof(_b_x1289_1291, _x_x3022, _ctx); /*std/text/parse/parse-error<string>*/
  kk_std_core_types__list fmt_0_10239;
  kk_string_t _x_x3038;
  if (kk_std_text_parse__is_ParseOk(perr_10245, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x3039 = kk_std_text_parse__as_ParseOk(perr_10245, _ctx);
    kk_box_t _box_x1294 = _con_x3039->result;
    kk_std_core_sslice__sslice _pat_0_0_0_0_0 = _con_x3039->rest;
    kk_string_t x_0_0_0_0 = kk_string_unbox(_box_x1294);
    if kk_likely(kk_datatype_ptr_is_unique(perr_10245, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10245, _ctx);
    }
    else {
      kk_string_dup(x_0_0_0_0, _ctx);
      kk_datatype_ptr_decref(perr_10245, _ctx);
    }
    kk_std_text_parse__parse_error_drop(perr_10036, _ctx);
    _x_x3038 = x_0_0_0_0; /*string*/
  }
  else {
    struct kk_std_text_parse_ParseError* _con_x3040 = kk_std_text_parse__as_ParseError(perr_10245, _ctx);
    kk_std_core_sslice__sslice _pat_5_0_0_0 = _con_x3040->rest;
    kk_string_t msg_0_0 = _con_x3040->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr_10245, _ctx)) {
      kk_string_drop(msg_0_0, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5_0_0_0, _ctx);
      kk_datatype_ptr_free(perr_10245, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr_10245, _ctx);
    }
    if (kk_std_text_parse__is_ParseOk(perr_10036, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x3041 = kk_std_text_parse__as_ParseOk(perr_10036, _ctx);
      kk_box_t _box_x1295 = _con_x3041->result;
      kk_std_core_sslice__sslice _pat_0_0_1 = _con_x3041->rest;
      kk_string_t x_0_1_0 = kk_string_unbox(_box_x1295);
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_std_core_sslice__sslice_drop(_pat_0_0_1, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_string_dup(x_0_1_0, _ctx);
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      _x_x3038 = x_0_1_0; /*string*/
    }
    else {
      struct kk_std_text_parse_ParseError* _con_x3042 = kk_std_text_parse__as_ParseError(perr_10036, _ctx);
      kk_std_core_sslice__sslice _pat_5_1_0 = _con_x3042->rest;
      kk_string_t msg_1 = _con_x3042->msg;
      if kk_likely(kk_datatype_ptr_is_unique(perr_10036, _ctx)) {
        kk_string_drop(msg_1, _ctx);
        kk_std_core_sslice__sslice_drop(_pat_5_1_0, _ctx);
        kk_datatype_ptr_free(perr_10036, _ctx);
      }
      else {
        kk_datatype_ptr_decref(perr_10036, _ctx);
      }
      kk_define_string_literal(, _s_x3043, 2, "ll", _ctx)
      _x_x3038 = kk_string_dup(_s_x3043, _ctx); /*string*/
    }
  }
  fmt_0_10239 = kk_std_core_string_list(_x_x3038, _ctx); /*list<char>*/
  if (kk_std_core_types__is_Nil(fmt_0_10239, _ctx)) {
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_core_types__optional_drop(locale, _ctx);
    return kk_string_empty();
  }
  {
    kk_std_time_locale__time_locale _x_x3045;
    if (kk_std_core_types__is_Optional(locale, _ctx)) {
      kk_box_t _box_x1298 = locale._cons._Optional.value;
      kk_std_time_locale__time_locale _uniq_locale_5244_1 = kk_std_time_locale__time_locale_unbox(_box_x1298, KK_BORROWED, _ctx);
      kk_std_time_locale__time_locale_dup(_uniq_locale_5244_1, _ctx);
      kk_std_core_types__optional_drop(locale, _ctx);
      _x_x3045 = _uniq_locale_5244_1; /*std/time/locale/time-locale*/
    }
    else {
      kk_std_core_types__optional_drop(locale, _ctx);
      _x_x3045 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
    }
    return kk_std_time_format__unroll_format_list_10000(t, fmt_0_10239, _x_x3045, _ctx);
  }
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
    kk_box_t _x_x2547;
    kk_std_core_types__tuple3 _x_x2548 = kk_std_core_types__new_Tuple3(kk_char_box('Y', _ctx), kk_integer_box(kk_integer_from_small(6), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2549(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2547 = kk_std_core_types__tuple3_box(_x_x2548, _ctx); /*10021*/
    kk_std_core_types__list _x_x2554;
    kk_box_t _x_x2555;
    kk_std_core_types__tuple3 _x_x2556 = kk_std_core_types__new_Tuple3(kk_char_box('M', _ctx), kk_integer_box(kk_integer_from_small(4), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2557(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2555 = kk_std_core_types__tuple3_box(_x_x2556, _ctx); /*10021*/
    kk_std_core_types__list _x_x2562;
    kk_box_t _x_x2563;
    kk_std_core_types__tuple3 _x_x2564 = kk_std_core_types__new_Tuple3(kk_char_box('D', _ctx), kk_integer_box(kk_integer_from_small(3), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2565(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2563 = kk_std_core_types__tuple3_box(_x_x2564, _ctx); /*10021*/
    kk_std_core_types__list _x_x2570;
    kk_box_t _x_x2571;
    kk_std_core_types__tuple3 _x_x2572 = kk_std_core_types__new_Tuple3(kk_char_box('H', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2573(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2571 = kk_std_core_types__tuple3_box(_x_x2572, _ctx); /*10021*/
    kk_std_core_types__list _x_x2578;
    kk_box_t _x_x2579;
    kk_std_core_types__tuple3 _x_x2580 = kk_std_core_types__new_Tuple3(kk_char_box('m', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2581(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2579 = kk_std_core_types__tuple3_box(_x_x2580, _ctx); /*10021*/
    kk_std_core_types__list _x_x2586;
    kk_box_t _x_x2587;
    kk_std_core_types__tuple3 _x_x2588 = kk_std_core_types__new_Tuple3(kk_char_box('s', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2589(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2587 = kk_std_core_types__tuple3_box(_x_x2588, _ctx); /*10021*/
    kk_std_core_types__list _x_x2594;
    kk_box_t _x_x2595;
    kk_std_core_types__tuple3 _x_x2596 = kk_std_core_types__new_Tuple3(kk_char_box('z', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2597(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2595 = kk_std_core_types__tuple3_box(_x_x2596, _ctx); /*10021*/
    kk_std_core_types__list _x_x2602;
    kk_box_t _x_x2603;
    kk_std_core_types__tuple3 _x_x2604 = kk_std_core_types__new_Tuple3(kk_char_box('Z', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2605(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2603 = kk_std_core_types__tuple3_box(_x_x2604, _ctx); /*10021*/
    kk_std_core_types__list _x_x2610;
    kk_box_t _x_x2611;
    kk_std_core_types__tuple3 _x_x2612 = kk_std_core_types__new_Tuple3(kk_char_box('f', _ctx), kk_integer_box(kk_integer_from_small(8), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2613(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2611 = kk_std_core_types__tuple3_box(_x_x2612, _ctx); /*10021*/
    kk_std_core_types__list _x_x2618;
    kk_box_t _x_x2619;
    kk_std_core_types__tuple3 _x_x2620 = kk_std_core_types__new_Tuple3(kk_char_box('F', _ctx), kk_integer_box(kk_integer_from_small(8), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2621(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2619 = kk_std_core_types__tuple3_box(_x_x2620, _ctx); /*10021*/
    kk_std_core_types__list _x_x2626;
    kk_box_t _x_x2627;
    kk_std_core_types__tuple3 _x_x2628 = kk_std_core_types__new_Tuple3(kk_char_box('C', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2629(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2627 = kk_std_core_types__tuple3_box(_x_x2628, _ctx); /*10021*/
    kk_std_core_types__list _x_x2634;
    kk_box_t _x_x2635;
    kk_std_core_types__tuple3 _x_x2636 = kk_std_core_types__new_Tuple3(kk_char_box('E', _ctx), kk_integer_box(kk_integer_from_small(1), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2637(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2635 = kk_std_core_types__tuple3_box(_x_x2636, _ctx); /*10021*/
    kk_std_core_types__list _x_x2642;
    kk_box_t _x_x2643;
    kk_std_core_types__tuple3 _x_x2644 = kk_std_core_types__new_Tuple3(kk_char_box('y', _ctx), kk_integer_box(kk_integer_from_small(1), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2645(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2643 = kk_std_core_types__tuple3_box(_x_x2644, _ctx); /*10021*/
    kk_std_core_types__list _x_x2650;
    kk_box_t _x_x2651;
    kk_std_core_types__tuple3 _x_x2652 = kk_std_core_types__new_Tuple3(kk_char_box('d', _ctx), kk_integer_box(kk_integer_from_small(4), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2653(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2651 = kk_std_core_types__tuple3_box(_x_x2652, _ctx); /*10021*/
    kk_std_core_types__list _x_x2658;
    kk_box_t _x_x2659;
    kk_std_core_types__tuple3 _x_x2660 = kk_std_core_types__new_Tuple3(kk_char_box('h', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2661(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2659 = kk_std_core_types__tuple3_box(_x_x2660, _ctx); /*10021*/
    kk_std_core_types__list _x_x2666;
    kk_box_t _x_x2667;
    kk_std_core_types__tuple3 _x_x2668 = kk_std_core_types__new_Tuple3(kk_char_box('a', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2669(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2667 = kk_std_core_types__tuple3_box(_x_x2668, _ctx); /*10021*/
    kk_std_core_types__list _x_x2674;
    kk_box_t _x_x2675;
    kk_std_core_types__tuple3 _x_x2676 = kk_std_core_types__new_Tuple3(kk_char_box('A', _ctx), kk_integer_box(kk_integer_from_small(2), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2677(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2675 = kk_std_core_types__tuple3_box(_x_x2676, _ctx); /*10021*/
    kk_std_core_types__list _x_x2682;
    kk_box_t _x_x2683;
    kk_std_core_types__tuple3 _x_x2684 = kk_std_core_types__new_Tuple3(kk_char_box('x', _ctx), kk_integer_box(kk_integer_from_small(1), _ctx), kk_function_box(kk_std_time_format_new_formats_fun2685(_ctx), _ctx), _ctx); /*(10041, 10042, 10043)*/
    _x_x2683 = kk_std_core_types__tuple3_box(_x_x2684, _ctx); /*10021*/
    _x_x2682 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2683, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x2674 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2675, _x_x2682, _ctx); /*list<10021>*/
    _x_x2666 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2667, _x_x2674, _ctx); /*list<10021>*/
    _x_x2658 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2659, _x_x2666, _ctx); /*list<10021>*/
    _x_x2650 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2651, _x_x2658, _ctx); /*list<10021>*/
    _x_x2642 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2643, _x_x2650, _ctx); /*list<10021>*/
    _x_x2634 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2635, _x_x2642, _ctx); /*list<10021>*/
    _x_x2626 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2627, _x_x2634, _ctx); /*list<10021>*/
    _x_x2618 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2619, _x_x2626, _ctx); /*list<10021>*/
    _x_x2610 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2611, _x_x2618, _ctx); /*list<10021>*/
    _x_x2602 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2603, _x_x2610, _ctx); /*list<10021>*/
    _x_x2594 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2595, _x_x2602, _ctx); /*list<10021>*/
    _x_x2586 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2587, _x_x2594, _ctx); /*list<10021>*/
    _x_x2578 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2579, _x_x2586, _ctx); /*list<10021>*/
    _x_x2570 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2571, _x_x2578, _ctx); /*list<10021>*/
    _x_x2562 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2563, _x_x2570, _ctx); /*list<10021>*/
    _x_x2554 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2555, _x_x2562, _ctx); /*list<10021>*/
    kk_std_time_format_formats = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x2547, _x_x2554, _ctx); /*list<(char, int, (std/time/time/time, int, std/time/locale/time-locale) -> string)>*/
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
