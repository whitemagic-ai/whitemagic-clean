// Koka generated module: std/time/locale, koka version: 3.2.2, platform: 64-bit
#include "std_time_locale.h"
extern kk_box_t kk_std_time_locale__create_Time_locale_fun923(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x924;
  kk_std_core_sslice__sslice _x_x925;
  kk_string_t _x_x926 = kk_string_unbox(_b_x4); /*string*/
  kk_std_core_types__optional _x_x927 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x925 = kk_std_core_sslice_first(_x_x926, _x_x927, _ctx); /*sslice/sslice*/
  _x_x924 = kk_std_core_sslice_string(_x_x925, _ctx); /*string*/
  return kk_string_box(_x_x924);
}
extern kk_box_t kk_std_time_locale__create_Time_locale_fun929(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x930;
  kk_std_core_sslice__sslice _x_x931;
  kk_string_t _x_x932 = kk_string_unbox(_b_x13); /*string*/
  kk_std_core_types__optional _x_x933 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x931 = kk_std_core_sslice_first(_x_x932, _x_x933, _ctx); /*sslice/sslice*/
  _x_x930 = kk_std_core_sslice_string(_x_x931, _ctx); /*string*/
  return kk_string_box(_x_x930);
}
extern kk_box_t kk_std_time_locale__create_Time_locale_fun935(kk_function_t _fself, kk_box_t _b_x22, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x936;
  kk_std_core_sslice__sslice _x_x937;
  kk_string_t _x_x938 = kk_string_unbox(_b_x22); /*string*/
  kk_std_core_types__optional _x_x939 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? 7*/
  _x_x937 = kk_std_core_sslice_first(_x_x938, _x_x939, _ctx); /*sslice/sslice*/
  _x_x936 = kk_std_core_sslice_string(_x_x937, _ctx); /*string*/
  return kk_string_box(_x_x936);
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fs__copy(kk_std_time_locale__time_locale _this, kk_std_core_types__optional lang_name, kk_std_core_types__optional day_names, kk_std_core_types__optional month_names, kk_std_core_types__optional month_names_short, kk_std_core_types__optional day_names_short, kk_std_core_types__optional day_names_min, kk_std_core_types__optional format_t, kk_std_core_types__optional format_tt, kk_std_core_types__optional format_l, kk_std_core_types__optional format_ll, kk_std_core_types__optional format_lll, kk_std_core_types__optional format_llll, kk_context_t* _ctx) { /* (time-locale, lang-name : ? string, day-names : ? (list<string>), month-names : ? (list<string>), month-names-short : ? (list<string>), day-names-short : ? (list<string>), day-names-min : ? (list<string>), format-t : ? string, format-tt : ? string, format-l : ? string, format-ll : ? string, format-lll : ? string, format-llll : ? string) -> time-locale */ 
  kk_string_t _x_x965;
  if (kk_std_core_types__is_Optional(lang_name, _ctx)) {
    kk_box_t _box_x33 = lang_name._cons._Optional.value;
    kk_string_t _uniq_lang_name_362 = kk_string_unbox(_box_x33);
    kk_string_dup(_uniq_lang_name_362, _ctx);
    kk_std_core_types__optional_drop(lang_name, _ctx);
    _x_x965 = _uniq_lang_name_362; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(lang_name, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x966 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x = _con_x966->lang_name;
      kk_string_dup(_x, _ctx);
      _x_x965 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x967;
  if (kk_std_core_types__is_Optional(day_names, _ctx)) {
    kk_box_t _box_x34 = day_names._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_370 = kk_std_core_types__list_unbox(_box_x34, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_370, _ctx);
    kk_std_core_types__optional_drop(day_names, _ctx);
    _x_x967 = _uniq_day_names_370; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x968 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_0 = _con_x968->day_names;
      kk_std_core_types__list_dup(_x_0, _ctx);
      _x_x967 = _x_0; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x969;
  if (kk_std_core_types__is_Optional(month_names, _ctx)) {
    kk_box_t _box_x35 = month_names._cons._Optional.value;
    kk_std_core_types__list _uniq_month_names_378 = kk_std_core_types__list_unbox(_box_x35, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_month_names_378, _ctx);
    kk_std_core_types__optional_drop(month_names, _ctx);
    _x_x969 = _uniq_month_names_378; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(month_names, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x970 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_1 = _con_x970->month_names;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _x_x969 = _x_1; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x971;
  if (kk_std_core_types__is_Optional(month_names_short, _ctx)) {
    kk_box_t _box_x36 = month_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_month_names_short_386 = kk_std_core_types__list_unbox(_box_x36, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_month_names_short_386, _ctx);
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    _x_x971 = _uniq_month_names_short_386; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(month_names_short, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x972 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_2 = _con_x972->month_names_short;
      kk_std_core_types__list_dup(_x_2, _ctx);
      _x_x971 = _x_2; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x973;
  if (kk_std_core_types__is_Optional(day_names_short, _ctx)) {
    kk_box_t _box_x37 = day_names_short._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_short_394 = kk_std_core_types__list_unbox(_box_x37, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_short_394, _ctx);
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    _x_x973 = _uniq_day_names_short_394; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_short, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x974 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_3 = _con_x974->day_names_short;
      kk_std_core_types__list_dup(_x_3, _ctx);
      _x_x973 = _x_3; /*list<string>*/
    }
  }
  kk_std_core_types__list _x_x975;
  if (kk_std_core_types__is_Optional(day_names_min, _ctx)) {
    kk_box_t _box_x38 = day_names_min._cons._Optional.value;
    kk_std_core_types__list _uniq_day_names_min_402 = kk_std_core_types__list_unbox(_box_x38, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_day_names_min_402, _ctx);
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    _x_x975 = _uniq_day_names_min_402; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(day_names_min, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x976 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_std_core_types__list _x_4 = _con_x976->day_names_min;
      kk_std_core_types__list_dup(_x_4, _ctx);
      _x_x975 = _x_4; /*list<string>*/
    }
  }
  kk_string_t _x_x977;
  if (kk_std_core_types__is_Optional(format_t, _ctx)) {
    kk_box_t _box_x39 = format_t._cons._Optional.value;
    kk_string_t _uniq_format_t_410 = kk_string_unbox(_box_x39);
    kk_string_dup(_uniq_format_t_410, _ctx);
    kk_std_core_types__optional_drop(format_t, _ctx);
    _x_x977 = _uniq_format_t_410; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_t, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x978 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_5 = _con_x978->format_t;
      kk_string_dup(_x_5, _ctx);
      _x_x977 = _x_5; /*string*/
    }
  }
  kk_string_t _x_x979;
  if (kk_std_core_types__is_Optional(format_tt, _ctx)) {
    kk_box_t _box_x40 = format_tt._cons._Optional.value;
    kk_string_t _uniq_format_tt_418 = kk_string_unbox(_box_x40);
    kk_string_dup(_uniq_format_tt_418, _ctx);
    kk_std_core_types__optional_drop(format_tt, _ctx);
    _x_x979 = _uniq_format_tt_418; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_tt, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x980 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_6 = _con_x980->format_tt;
      kk_string_dup(_x_6, _ctx);
      _x_x979 = _x_6; /*string*/
    }
  }
  kk_string_t _x_x981;
  if (kk_std_core_types__is_Optional(format_l, _ctx)) {
    kk_box_t _box_x41 = format_l._cons._Optional.value;
    kk_string_t _uniq_format_l_426 = kk_string_unbox(_box_x41);
    kk_string_dup(_uniq_format_l_426, _ctx);
    kk_std_core_types__optional_drop(format_l, _ctx);
    _x_x981 = _uniq_format_l_426; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_l, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x982 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_7 = _con_x982->format_l;
      kk_string_dup(_x_7, _ctx);
      _x_x981 = _x_7; /*string*/
    }
  }
  kk_string_t _x_x983;
  if (kk_std_core_types__is_Optional(format_ll, _ctx)) {
    kk_box_t _box_x42 = format_ll._cons._Optional.value;
    kk_string_t _uniq_format_ll_434 = kk_string_unbox(_box_x42);
    kk_string_dup(_uniq_format_ll_434, _ctx);
    kk_std_core_types__optional_drop(format_ll, _ctx);
    _x_x983 = _uniq_format_ll_434; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_ll, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x984 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_8 = _con_x984->format_ll;
      kk_string_dup(_x_8, _ctx);
      _x_x983 = _x_8; /*string*/
    }
  }
  kk_string_t _x_x985;
  if (kk_std_core_types__is_Optional(format_lll, _ctx)) {
    kk_box_t _box_x43 = format_lll._cons._Optional.value;
    kk_string_t _uniq_format_lll_442 = kk_string_unbox(_box_x43);
    kk_string_dup(_uniq_format_lll_442, _ctx);
    kk_std_core_types__optional_drop(format_lll, _ctx);
    _x_x985 = _uniq_format_lll_442; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_lll, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x986 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _x_9 = _con_x986->format_lll;
      kk_string_dup(_x_9, _ctx);
      _x_x985 = _x_9; /*string*/
    }
  }
  kk_string_t _x_x987;
  if (kk_std_core_types__is_Optional(format_llll, _ctx)) {
    kk_box_t _box_x44 = format_llll._cons._Optional.value;
    kk_string_t _uniq_format_llll_450 = kk_string_unbox(_box_x44);
    kk_string_dup(_uniq_format_llll_450, _ctx);
    kk_std_core_types__optional_drop(format_llll, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(12)), _ctx);
    _x_x987 = _uniq_format_llll_450; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(format_llll, _ctx);
    {
      struct kk_std_time_locale_Time_locale* _con_x988 = kk_std_time_locale__as_Time_locale(_this, _ctx);
      kk_string_t _pat_0_11 = _con_x988->lang_name;
      kk_std_core_types__list _pat_1_12 = _con_x988->day_names;
      kk_std_core_types__list _pat_2_11 = _con_x988->month_names;
      kk_std_core_types__list _pat_3_11 = _con_x988->month_names_short;
      kk_std_core_types__list _pat_4_11 = _con_x988->day_names_short;
      kk_std_core_types__list _pat_5_11 = _con_x988->day_names_min;
      kk_string_t _pat_6_11 = _con_x988->format_t;
      kk_string_t _pat_7_11 = _con_x988->format_tt;
      kk_string_t _pat_8_11 = _con_x988->format_l;
      kk_string_t _pat_9_11 = _con_x988->format_ll;
      kk_string_t _pat_10_11 = _con_x988->format_lll;
      kk_string_t _x_10 = _con_x988->format_llll;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_string_drop(_pat_9_11, _ctx);
        kk_string_drop(_pat_8_11, _ctx);
        kk_string_drop(_pat_7_11, _ctx);
        kk_string_drop(_pat_6_11, _ctx);
        kk_std_core_types__list_drop(_pat_5_11, _ctx);
        kk_std_core_types__list_drop(_pat_4_11, _ctx);
        kk_std_core_types__list_drop(_pat_3_11, _ctx);
        kk_std_core_types__list_drop(_pat_2_11, _ctx);
        kk_std_core_types__list_drop(_pat_1_12, _ctx);
        kk_string_drop(_pat_10_11, _ctx);
        kk_string_drop(_pat_0_11, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_string_dup(_x_10, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x987 = _x_10; /*string*/
    }
  }
  return kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x965, _x_x967, _x_x969, _x_x971, _x_x973, _x_x975, _x_x977, _x_x979, _x_x981, _x_x983, _x_x985, _x_x987, _ctx);
}
 
// English time locale (`en`)


// lift anonymous function
struct kk_std_time_locale_time_locale_en_fun1063__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_en_fun1063(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_en_fun1063(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_en_fun1063, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_en_fun1063(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1064;
  kk_std_core_sslice__sslice _x_x1065;
  kk_string_t _x_x1066 = kk_string_unbox(_b_x125); /*string*/
  kk_std_core_types__optional _x_x1067 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x1065 = kk_std_core_sslice_first(_x_x1066, _x_x1067, _ctx); /*sslice/sslice*/
  _x_x1064 = kk_std_core_sslice_string(_x_x1065, _ctx); /*string*/
  return kk_string_box(_x_x1064);
}


// lift anonymous function
struct kk_std_time_locale_time_locale_en_fun1069__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_en_fun1069(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_en_fun1069(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_en_fun1069, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_en_fun1069(kk_function_t _fself, kk_box_t _b_x134, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1070;
  kk_std_core_sslice__sslice _x_x1071;
  kk_string_t _x_x1072 = kk_string_unbox(_b_x134); /*string*/
  kk_std_core_types__optional _x_x1073 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x1071 = kk_std_core_sslice_first(_x_x1072, _x_x1073, _ctx); /*sslice/sslice*/
  _x_x1070 = kk_std_core_sslice_string(_x_x1071, _ctx); /*string*/
  return kk_string_box(_x_x1070);
}


// lift anonymous function
struct kk_std_time_locale_time_locale_en_fun1075__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_en_fun1075(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_en_fun1075(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_en_fun1075, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_en_fun1075(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1076;
  kk_std_core_sslice__sslice _x_x1077;
  kk_string_t _x_x1078 = kk_string_unbox(_b_x143); /*string*/
  kk_std_core_types__optional _x_x1079 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? 7*/
  _x_x1077 = kk_std_core_sslice_first(_x_x1078, _x_x1079, _ctx); /*sslice/sslice*/
  _x_x1076 = kk_std_core_sslice_string(_x_x1077, _ctx); /*string*/
  return kk_string_box(_x_x1076);
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en;
 
// ISO English time locale (`en-iso`). Uses English names for
// months and days but displays numeric dates and times using unambigious ISO format.


// lift anonymous function
struct kk_std_time_locale_time_locale_en_iso_fun1095__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_en_iso_fun1095(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_en_iso_fun1095(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_en_iso_fun1095, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_en_iso_fun1095(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1096;
  kk_std_core_sslice__sslice _x_x1097;
  kk_string_t _x_x1098 = kk_string_unbox(_b_x154); /*string*/
  kk_std_core_types__optional _x_x1099 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x1097 = kk_std_core_sslice_first(_x_x1098, _x_x1099, _ctx); /*sslice/sslice*/
  _x_x1096 = kk_std_core_sslice_string(_x_x1097, _ctx); /*string*/
  return kk_string_box(_x_x1096);
}


// lift anonymous function
struct kk_std_time_locale_time_locale_en_iso_fun1103__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_en_iso_fun1103(kk_function_t _fself, kk_box_t _b_x163, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_en_iso_fun1103(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_en_iso_fun1103, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_en_iso_fun1103(kk_function_t _fself, kk_box_t _b_x163, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1104;
  kk_std_core_sslice__sslice _x_x1105;
  kk_string_t _x_x1106 = kk_string_unbox(_b_x163); /*string*/
  kk_std_core_types__optional _x_x1107 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x1105 = kk_std_core_sslice_first(_x_x1106, _x_x1107, _ctx); /*sslice/sslice*/
  _x_x1104 = kk_std_core_sslice_string(_x_x1105, _ctx); /*string*/
  return kk_string_box(_x_x1104);
}


// lift anonymous function
struct kk_std_time_locale_time_locale_en_iso_fun1111__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_en_iso_fun1111(kk_function_t _fself, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_en_iso_fun1111(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_en_iso_fun1111, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_en_iso_fun1111(kk_function_t _fself, kk_box_t _b_x172, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1112;
  kk_std_core_sslice__sslice _x_x1113;
  kk_string_t _x_x1114 = kk_string_unbox(_b_x172); /*string*/
  kk_std_core_types__optional _x_x1115 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? 7*/
  _x_x1113 = kk_std_core_sslice_first(_x_x1114, _x_x1115, _ctx); /*sslice/sslice*/
  _x_x1112 = kk_std_core_sslice_string(_x_x1113, _ctx); /*string*/
  return kk_string_box(_x_x1112);
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_en_iso;
 
// French time locale (`fr`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_fr;
 
// German time locale (`de`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_de;
 
// Spanish time locale (`es`)


// lift anonymous function
struct kk_std_time_locale_time_locale_es_fun1601__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_es_fun1601(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_es_fun1601(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_es_fun1601, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_es_fun1601(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1602;
  kk_std_core_sslice__sslice _x_x1603;
  kk_string_t _x_x1604 = kk_string_unbox(_b_x628); /*string*/
  kk_std_core_types__optional _x_x1605 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x1603 = kk_std_core_sslice_first(_x_x1604, _x_x1605, _ctx); /*sslice/sslice*/
  _x_x1602 = kk_std_core_sslice_string(_x_x1603, _ctx); /*string*/
  return kk_string_box(_x_x1602);
}


// lift anonymous function
struct kk_std_time_locale_time_locale_es_fun1607__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_es_fun1607(kk_function_t _fself, kk_box_t _b_x637, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_es_fun1607(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_es_fun1607, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_es_fun1607(kk_function_t _fself, kk_box_t _b_x637, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1608;
  kk_std_core_sslice__sslice _x_x1609;
  kk_string_t _x_x1610 = kk_string_unbox(_b_x637); /*string*/
  kk_std_core_types__optional _x_x1611 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(3), _ctx), _ctx); /*? 7*/
  _x_x1609 = kk_std_core_sslice_first(_x_x1610, _x_x1611, _ctx); /*sslice/sslice*/
  _x_x1608 = kk_std_core_sslice_string(_x_x1609, _ctx); /*string*/
  return kk_string_box(_x_x1608);
}


// lift anonymous function
struct kk_std_time_locale_time_locale_es_fun1613__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_locale_time_locale_es_fun1613(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_time_locale_es_fun1613(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_locale_time_locale_es_fun1613, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_locale_time_locale_es_fun1613(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1614;
  kk_std_core_sslice__sslice _x_x1615;
  kk_string_t _x_x1616 = kk_string_unbox(_b_x646); /*string*/
  kk_std_core_types__optional _x_x1617 = kk_std_core_types__new_Optional(kk_integer_box(kk_integer_from_small(2), _ctx), _ctx); /*? 7*/
  _x_x1615 = kk_std_core_sslice_first(_x_x1616, _x_x1617, _ctx); /*sslice/sslice*/
  _x_x1614 = kk_std_core_sslice_string(_x_x1615, _ctx); /*string*/
  return kk_string_box(_x_x1614);
}

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_es;
 
// Dutch time locale (`nl`)

kk_std_time_locale__time_locale kk_std_time_locale_time_locale_nl;

kk_std_core_types__list kk_std_time_locale_locales;
 
// Return a builtin locale given a locale string (e.g. ``en-GB``, ``es``);
// Use `time-locale-iso` if no particular match is found.
// Supports ``de``,``en``,``es``,``fr``,``nl`` and ``en-iso``.


// lift anonymous function
struct kk_std_time_locale_get_time_locale_fun1845__t {
  struct kk_function_s _base;
  kk_string_t locale;
};
static bool kk_std_time_locale_get_time_locale_fun1845(kk_function_t _fself, kk_box_t _b_x863, kk_context_t* _ctx);
static kk_function_t kk_std_time_locale_new_get_time_locale_fun1845(kk_string_t locale, kk_context_t* _ctx) {
  struct kk_std_time_locale_get_time_locale_fun1845__t* _self = kk_function_alloc_as(struct kk_std_time_locale_get_time_locale_fun1845__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_locale_get_time_locale_fun1845, kk_context());
  _self->locale = locale;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static bool kk_std_time_locale_get_time_locale_fun1845(kk_function_t _fself, kk_box_t _b_x863, kk_context_t* _ctx) {
  struct kk_std_time_locale_get_time_locale_fun1845__t* _self = kk_function_as(struct kk_std_time_locale_get_time_locale_fun1845__t*, _fself, _ctx);
  kk_string_t locale = _self->locale; /* string */
  kk_drop_match(_self, {kk_string_dup(locale, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe maybe_10074;
  kk_string_t _x_x1846;
  kk_std_time_locale__time_locale _match_x868 = kk_std_time_locale__time_locale_unbox(_b_x863, KK_OWNED, _ctx); /*std/time/locale/time-locale*/;
  {
    struct kk_std_time_locale_Time_locale* _con_x1847 = kk_std_time_locale__as_Time_locale(_match_x868, _ctx);
    kk_string_t _x = _con_x1847->lang_name;
    kk_std_core_types__list _pat_0_0 = _con_x1847->day_names;
    kk_std_core_types__list _pat_1_0 = _con_x1847->month_names;
    kk_std_core_types__list _pat_2_0 = _con_x1847->month_names_short;
    kk_std_core_types__list _pat_3 = _con_x1847->day_names_short;
    kk_std_core_types__list _pat_4 = _con_x1847->day_names_min;
    kk_string_t _pat_5 = _con_x1847->format_t;
    kk_string_t _pat_6 = _con_x1847->format_tt;
    kk_string_t _pat_7 = _con_x1847->format_l;
    kk_string_t _pat_8 = _con_x1847->format_ll;
    kk_string_t _pat_9 = _con_x1847->format_lll;
    kk_string_t _pat_10 = _con_x1847->format_llll;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x868, _ctx)) {
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
      kk_std_core_types__list_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(_match_x868, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x868, _ctx);
    }
    _x_x1846 = _x; /*string*/
  }
  maybe_10074 = kk_std_core_sslice_starts_with(locale, _x_x1846, _ctx); /*maybe<sslice/sslice>*/
  if (kk_std_core_types__is_Just(maybe_10074, _ctx)) {
    kk_box_t _box_x860 = maybe_10074._cons.Just.value;
    kk_std_core_types__maybe_drop(maybe_10074, _ctx);
    return true;
  }
  {
    return false;
  }
}

kk_std_time_locale__time_locale kk_std_time_locale_get_time_locale(kk_string_t locale, kk_context_t* _ctx) { /* (locale : string) -> time-locale */ 
  kk_std_core_types__maybe res;
  kk_std_core_types__list _x_x1844 = kk_std_core_types__list_dup(kk_std_time_locale_locales, _ctx); /*list<std/time/locale/time-locale>*/
  res = kk_std_core_list_find(_x_x1844, kk_std_time_locale_new_get_time_locale_fun1845(locale, _ctx), _ctx); /*maybe<std/time/locale/time-locale>*/
  if (kk_std_core_types__is_Nothing(res, _ctx)) {
    return kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx);
  }
  {
    kk_box_t _box_x867 = res._cons.Just.value;
    kk_std_time_locale__time_locale x = kk_std_time_locale__time_locale_unbox(_box_x867, KK_BORROWED, _ctx);
    kk_std_time_locale__time_locale_dup(x, _ctx);
    kk_std_core_types__maybe_drop(res, _ctx);
    return x;
  }
}

// initialization
void kk_std_time_locale__init(kk_context_t* _ctx){
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
  {
    kk_std_core_types__list day_names_10013;
    kk_box_t _x_x989;
    kk_string_t _x_x990;
    kk_define_string_literal(, _s_x991, 6, "Monday", _ctx)
    _x_x990 = kk_string_dup(_s_x991, _ctx); /*string*/
    _x_x989 = kk_string_box(_x_x990); /*79*/
    kk_std_core_types__list _x_x992;
    kk_box_t _x_x993;
    kk_string_t _x_x994;
    kk_define_string_literal(, _s_x995, 7, "Tuesday", _ctx)
    _x_x994 = kk_string_dup(_s_x995, _ctx); /*string*/
    _x_x993 = kk_string_box(_x_x994); /*79*/
    kk_std_core_types__list _x_x996;
    kk_box_t _x_x997;
    kk_string_t _x_x998;
    kk_define_string_literal(, _s_x999, 9, "Wednesday", _ctx)
    _x_x998 = kk_string_dup(_s_x999, _ctx); /*string*/
    _x_x997 = kk_string_box(_x_x998); /*79*/
    kk_std_core_types__list _x_x1000;
    kk_box_t _x_x1001;
    kk_string_t _x_x1002;
    kk_define_string_literal(, _s_x1003, 8, "Thursday", _ctx)
    _x_x1002 = kk_string_dup(_s_x1003, _ctx); /*string*/
    _x_x1001 = kk_string_box(_x_x1002); /*79*/
    kk_std_core_types__list _x_x1004;
    kk_box_t _x_x1005;
    kk_string_t _x_x1006;
    kk_define_string_literal(, _s_x1007, 6, "Friday", _ctx)
    _x_x1006 = kk_string_dup(_s_x1007, _ctx); /*string*/
    _x_x1005 = kk_string_box(_x_x1006); /*79*/
    kk_std_core_types__list _x_x1008;
    kk_box_t _x_x1009;
    kk_string_t _x_x1010;
    kk_define_string_literal(, _s_x1011, 8, "Saturday", _ctx)
    _x_x1010 = kk_string_dup(_s_x1011, _ctx); /*string*/
    _x_x1009 = kk_string_box(_x_x1010); /*79*/
    kk_std_core_types__list _x_x1012;
    kk_box_t _x_x1013;
    kk_string_t _x_x1014;
    kk_define_string_literal(, _s_x1015, 6, "Sunday", _ctx)
    _x_x1014 = kk_string_dup(_s_x1015, _ctx); /*string*/
    _x_x1013 = kk_string_box(_x_x1014); /*79*/
    _x_x1012 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1013, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1008 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1009, _x_x1012, _ctx); /*list<79>*/
    _x_x1004 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1005, _x_x1008, _ctx); /*list<79>*/
    _x_x1000 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1001, _x_x1004, _ctx); /*list<79>*/
    _x_x996 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x997, _x_x1000, _ctx); /*list<79>*/
    _x_x992 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x993, _x_x996, _ctx); /*list<79>*/
    day_names_10013 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x989, _x_x992, _ctx); /*list<string>*/
    kk_std_core_types__list month_names_10014;
    kk_box_t _x_x1016;
    kk_string_t _x_x1017;
    kk_define_string_literal(, _s_x1018, 7, "January", _ctx)
    _x_x1017 = kk_string_dup(_s_x1018, _ctx); /*string*/
    _x_x1016 = kk_string_box(_x_x1017); /*79*/
    kk_std_core_types__list _x_x1019;
    kk_box_t _x_x1020;
    kk_string_t _x_x1021;
    kk_define_string_literal(, _s_x1022, 8, "February", _ctx)
    _x_x1021 = kk_string_dup(_s_x1022, _ctx); /*string*/
    _x_x1020 = kk_string_box(_x_x1021); /*79*/
    kk_std_core_types__list _x_x1023;
    kk_box_t _x_x1024;
    kk_string_t _x_x1025;
    kk_define_string_literal(, _s_x1026, 5, "March", _ctx)
    _x_x1025 = kk_string_dup(_s_x1026, _ctx); /*string*/
    _x_x1024 = kk_string_box(_x_x1025); /*79*/
    kk_std_core_types__list _x_x1027;
    kk_box_t _x_x1028;
    kk_string_t _x_x1029;
    kk_define_string_literal(, _s_x1030, 5, "April", _ctx)
    _x_x1029 = kk_string_dup(_s_x1030, _ctx); /*string*/
    _x_x1028 = kk_string_box(_x_x1029); /*79*/
    kk_std_core_types__list _x_x1031;
    kk_box_t _x_x1032;
    kk_string_t _x_x1033;
    kk_define_string_literal(, _s_x1034, 3, "May", _ctx)
    _x_x1033 = kk_string_dup(_s_x1034, _ctx); /*string*/
    _x_x1032 = kk_string_box(_x_x1033); /*79*/
    kk_std_core_types__list _x_x1035;
    kk_box_t _x_x1036;
    kk_string_t _x_x1037;
    kk_define_string_literal(, _s_x1038, 4, "June", _ctx)
    _x_x1037 = kk_string_dup(_s_x1038, _ctx); /*string*/
    _x_x1036 = kk_string_box(_x_x1037); /*79*/
    kk_std_core_types__list _x_x1039;
    kk_box_t _x_x1040;
    kk_string_t _x_x1041;
    kk_define_string_literal(, _s_x1042, 4, "July", _ctx)
    _x_x1041 = kk_string_dup(_s_x1042, _ctx); /*string*/
    _x_x1040 = kk_string_box(_x_x1041); /*79*/
    kk_std_core_types__list _x_x1043;
    kk_box_t _x_x1044;
    kk_string_t _x_x1045;
    kk_define_string_literal(, _s_x1046, 6, "August", _ctx)
    _x_x1045 = kk_string_dup(_s_x1046, _ctx); /*string*/
    _x_x1044 = kk_string_box(_x_x1045); /*79*/
    kk_std_core_types__list _x_x1047;
    kk_box_t _x_x1048;
    kk_string_t _x_x1049;
    kk_define_string_literal(, _s_x1050, 9, "September", _ctx)
    _x_x1049 = kk_string_dup(_s_x1050, _ctx); /*string*/
    _x_x1048 = kk_string_box(_x_x1049); /*79*/
    kk_std_core_types__list _x_x1051;
    kk_box_t _x_x1052;
    kk_string_t _x_x1053;
    kk_define_string_literal(, _s_x1054, 7, "October", _ctx)
    _x_x1053 = kk_string_dup(_s_x1054, _ctx); /*string*/
    _x_x1052 = kk_string_box(_x_x1053); /*79*/
    kk_std_core_types__list _x_x1055;
    kk_box_t _x_x1056;
    kk_string_t _x_x1057;
    kk_define_string_literal(, _s_x1058, 8, "November", _ctx)
    _x_x1057 = kk_string_dup(_s_x1058, _ctx); /*string*/
    _x_x1056 = kk_string_box(_x_x1057); /*79*/
    kk_std_core_types__list _x_x1059;
    kk_box_t _x_x1060;
    kk_string_t _x_x1061;
    kk_define_string_literal(, _s_x1062, 8, "December", _ctx)
    _x_x1061 = kk_string_dup(_s_x1062, _ctx); /*string*/
    _x_x1060 = kk_string_box(_x_x1061); /*79*/
    _x_x1059 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1060, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1055 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1056, _x_x1059, _ctx); /*list<79>*/
    _x_x1051 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1052, _x_x1055, _ctx); /*list<79>*/
    _x_x1047 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1048, _x_x1051, _ctx); /*list<79>*/
    _x_x1043 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1044, _x_x1047, _ctx); /*list<79>*/
    _x_x1039 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1040, _x_x1043, _ctx); /*list<79>*/
    _x_x1035 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1036, _x_x1039, _ctx); /*list<79>*/
    _x_x1031 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1032, _x_x1035, _ctx); /*list<79>*/
    _x_x1027 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1028, _x_x1031, _ctx); /*list<79>*/
    _x_x1023 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1024, _x_x1027, _ctx); /*list<79>*/
    _x_x1019 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1020, _x_x1023, _ctx); /*list<79>*/
    month_names_10014 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1016, _x_x1019, _ctx); /*list<string>*/
    kk_std_core_types__list _uniq_month_names_short_92;
    kk_std_core_types__optional _match_x911 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x911, _ctx)) {
      kk_box_t _box_x121 = _match_x911._cons._Optional.value;
      kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x121, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
      kk_std_core_types__optional_drop(_match_x911, _ctx);
      _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x911, _ctx);
      kk_function_t _brw_x912 = kk_std_time_locale_new_time_locale_en_fun1063(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x913;
      kk_std_core_types__list _x_x1068 = kk_std_core_types__list_dup(month_names_10014, _ctx); /*list<string>*/
      _brw_x913 = kk_std_core_list_map(_x_x1068, _brw_x912, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x912, _ctx);
      _uniq_month_names_short_92 = _brw_x913; /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_short_153;
    kk_std_core_types__optional _match_x908 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x908, _ctx)) {
      kk_box_t _box_x130 = _match_x908._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x130, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
      kk_std_core_types__optional_drop(_match_x908, _ctx);
      _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x908, _ctx);
      kk_function_t _brw_x909 = kk_std_time_locale_new_time_locale_en_fun1069(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x910;
      kk_std_core_types__list _x_x1074 = kk_std_core_types__list_dup(day_names_10013, _ctx); /*list<string>*/
      _brw_x910 = kk_std_core_list_map(_x_x1074, _brw_x909, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x909, _ctx);
      _uniq_day_names_short_153 = _brw_x910; /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_min_214;
    kk_std_core_types__optional _match_x905 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x905, _ctx)) {
      kk_box_t _box_x139 = _match_x905._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x139, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
      kk_std_core_types__optional_drop(_match_x905, _ctx);
      _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x905, _ctx);
      kk_function_t _brw_x906 = kk_std_time_locale_new_time_locale_en_fun1075(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x907;
      kk_std_core_types__list _x_x1080 = kk_std_core_types__list_dup(day_names_10013, _ctx); /*list<string>*/
      _brw_x907 = kk_std_core_list_map(_x_x1080, _brw_x906, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x906, _ctx);
      _uniq_day_names_min_214 = _brw_x907; /*list<string>*/
    }
    kk_string_t _x_x1081;
    kk_define_string_literal(, _s_x1082, 2, "en", _ctx)
    _x_x1081 = kk_string_dup(_s_x1082, _ctx); /*string*/
    kk_string_t _x_x1083;
    kk_define_string_literal(, _s_x1084, 6, "h:mmaa", _ctx)
    _x_x1083 = kk_string_dup(_s_x1084, _ctx); /*string*/
    kk_string_t _x_x1085;
    kk_define_string_literal(, _s_x1086, 9, "h:mm:ssaa", _ctx)
    _x_x1085 = kk_string_dup(_s_x1086, _ctx); /*string*/
    kk_string_t _x_x1087;
    kk_define_string_literal(, _s_x1088, 10, "MM/DD/YYYY", _ctx)
    _x_x1087 = kk_string_dup(_s_x1088, _ctx); /*string*/
    kk_string_t _x_x1089;
    kk_std_core_types__optional _match_x904 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x904, _ctx)) {
      kk_box_t _box_x148 = _match_x904._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x148);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x904, _ctx);
      _x_x1089 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x904, _ctx);
      kk_define_string_literal(, _s_x1090, 11, "D MMMM YYYY", _ctx)
      _x_x1089 = kk_string_dup(_s_x1090, _ctx); /*string*/
    }
    kk_string_t _x_x1091;
    kk_std_core_types__optional _match_x903 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x903, _ctx)) {
      kk_box_t _box_x149 = _match_x903._cons._Optional.value;
      kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x149);
      kk_string_dup(_uniq_format_lll_235, _ctx);
      kk_std_core_types__optional_drop(_match_x903, _ctx);
      _x_x1091 = _uniq_format_lll_235; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x903, _ctx);
      kk_define_string_literal(, _s_x1092, 13, "D MMMM YYYY t", _ctx)
      _x_x1091 = kk_string_dup(_s_x1092, _ctx); /*string*/
    }
    kk_string_t _x_x1093;
    kk_define_string_literal(, _s_x1094, 19, "dddd, D MMMM YYYY t", _ctx)
    _x_x1093 = kk_string_dup(_s_x1094, _ctx); /*string*/
    kk_std_time_locale_time_locale_en = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1081, day_names_10013, month_names_10014, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1083, _x_x1085, _x_x1087, _x_x1089, _x_x1091, _x_x1093, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_std_core_types__list _uniq_month_names_short_92;
    kk_std_core_types__optional _match_x900 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x900, _ctx)) {
      kk_box_t _box_x150 = _match_x900._cons._Optional.value;
      kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x150, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
      kk_std_core_types__optional_drop(_match_x900, _ctx);
      _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x900, _ctx);
      kk_function_t _brw_x901 = kk_std_time_locale_new_time_locale_en_iso_fun1095(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x902;
      kk_std_core_types__list _x_x1100;
      kk_std_time_locale__time_locale _x_x1101 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
      {
        struct kk_std_time_locale_Time_locale* _con_x1102 = kk_std_time_locale__as_Time_locale(_x_x1101, _ctx);
        kk_std_core_types__list _x_0 = _con_x1102->month_names;
        _x_x1100 = kk_std_core_types__list_dup(_x_0, _ctx); /*list<string>*/
      }
      _brw_x902 = kk_std_core_list_map(_x_x1100, _brw_x901, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x901, _ctx);
      _uniq_month_names_short_92 = _brw_x902; /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_short_153;
    kk_std_core_types__optional _match_x897 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x897, _ctx)) {
      kk_box_t _box_x159 = _match_x897._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x159, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
      kk_std_core_types__optional_drop(_match_x897, _ctx);
      _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x897, _ctx);
      kk_function_t _brw_x898 = kk_std_time_locale_new_time_locale_en_iso_fun1103(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x899;
      kk_std_core_types__list _x_x1108;
      kk_std_time_locale__time_locale _x_x1109 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
      {
        struct kk_std_time_locale_Time_locale* _con_x1110 = kk_std_time_locale__as_Time_locale(_x_x1109, _ctx);
        kk_std_core_types__list _x = _con_x1110->day_names;
        _x_x1108 = kk_std_core_types__list_dup(_x, _ctx); /*list<string>*/
      }
      _brw_x899 = kk_std_core_list_map(_x_x1108, _brw_x898, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x898, _ctx);
      _uniq_day_names_short_153 = _brw_x899; /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_min_214;
    kk_std_core_types__optional _match_x894 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x894, _ctx)) {
      kk_box_t _box_x168 = _match_x894._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x168, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
      kk_std_core_types__optional_drop(_match_x894, _ctx);
      _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x894, _ctx);
      kk_function_t _brw_x895 = kk_std_time_locale_new_time_locale_en_iso_fun1111(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x896;
      kk_std_core_types__list _x_x1116;
      kk_std_time_locale__time_locale _x_x1117 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
      {
        struct kk_std_time_locale_Time_locale* _con_x1118 = kk_std_time_locale__as_Time_locale(_x_x1117, _ctx);
        kk_std_core_types__list _x_1 = _con_x1118->day_names;
        _x_x1116 = kk_std_core_types__list_dup(_x_1, _ctx); /*list<string>*/
      }
      _brw_x896 = kk_std_core_list_map(_x_x1116, _brw_x895, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x895, _ctx);
      _uniq_day_names_min_214 = _brw_x896; /*list<string>*/
    }
    kk_string_t _x_x1119;
    kk_define_string_literal(, _s_x1120, 6, "en-iso", _ctx)
    _x_x1119 = kk_string_dup(_s_x1120, _ctx); /*string*/
    kk_std_core_types__list _x_x1121;
    kk_std_time_locale__time_locale _x_x1122 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
    {
      struct kk_std_time_locale_Time_locale* _con_x1123 = kk_std_time_locale__as_Time_locale(_x_x1122, _ctx);
      kk_std_core_types__list _x_2 = _con_x1123->day_names;
      _x_x1121 = kk_std_core_types__list_dup(_x_2, _ctx); /*list<string>*/
    }
    kk_std_core_types__list _x_x1124;
    kk_std_time_locale__time_locale _x_x1125 = kk_std_time_locale_time_locale_en; /*std/time/locale/time-locale*/
    {
      struct kk_std_time_locale_Time_locale* _con_x1126 = kk_std_time_locale__as_Time_locale(_x_x1125, _ctx);
      kk_std_core_types__list _x_0_0 = _con_x1126->month_names;
      _x_x1124 = kk_std_core_types__list_dup(_x_0_0, _ctx); /*list<string>*/
    }
    kk_string_t _x_x1127;
    kk_std_core_types__optional _match_x893 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x893, _ctx)) {
      kk_box_t _box_x177 = _match_x893._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x177);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x893, _ctx);
      _x_x1127 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x893, _ctx);
      kk_define_string_literal(, _s_x1128, 5, "HH:mm", _ctx)
      _x_x1127 = kk_string_dup(_s_x1128, _ctx); /*string*/
    }
    kk_string_t _x_x1129;
    kk_std_core_types__optional _match_x892 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x892, _ctx)) {
      kk_box_t _box_x178 = _match_x892._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x178);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x892, _ctx);
      _x_x1129 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x892, _ctx);
      kk_define_string_literal(, _s_x1130, 8, "HH:mm:ss", _ctx)
      _x_x1129 = kk_string_dup(_s_x1130, _ctx); /*string*/
    }
    kk_string_t _x_x1131;
    kk_std_core_types__optional _match_x891 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x891, _ctx)) {
      kk_box_t _box_x179 = _match_x891._cons._Optional.value;
      kk_string_t _uniq_format_l_227 = kk_string_unbox(_box_x179);
      kk_string_dup(_uniq_format_l_227, _ctx);
      kk_std_core_types__optional_drop(_match_x891, _ctx);
      _x_x1131 = _uniq_format_l_227; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x891, _ctx);
      kk_define_string_literal(, _s_x1132, 10, "YYYY-MM-DD", _ctx)
      _x_x1131 = kk_string_dup(_s_x1132, _ctx); /*string*/
    }
    kk_string_t _x_x1133;
    kk_std_core_types__optional _match_x890 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x890, _ctx)) {
      kk_box_t _box_x180 = _match_x890._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x180);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x890, _ctx);
      _x_x1133 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x890, _ctx);
      kk_define_string_literal(, _s_x1134, 11, "D MMMM YYYY", _ctx)
      _x_x1133 = kk_string_dup(_s_x1134, _ctx); /*string*/
    }
    kk_string_t _x_x1135;
    kk_define_string_literal(, _s_x1136, 15, "D MMMM YYYY, tt", _ctx)
    _x_x1135 = kk_string_dup(_s_x1136, _ctx); /*string*/
    kk_string_t _x_x1137;
    kk_define_string_literal(, _s_x1138, 21, "dddd, D MMMM YYYY, tt", _ctx)
    _x_x1137 = kk_string_dup(_s_x1138, _ctx); /*string*/
    kk_std_time_locale_time_locale_en_iso = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1119, _x_x1121, _x_x1124, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1127, _x_x1129, _x_x1131, _x_x1133, _x_x1135, _x_x1137, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_string_t _x_x1139;
    kk_define_string_literal(, _s_x1140, 2, "fr", _ctx)
    _x_x1139 = kk_string_dup(_s_x1140, _ctx); /*string*/
    kk_std_core_types__list _x_x1141;
    kk_box_t _x_x1142;
    kk_string_t _x_x1143;
    kk_define_string_literal(, _s_x1144, 5, "lundi", _ctx)
    _x_x1143 = kk_string_dup(_s_x1144, _ctx); /*string*/
    _x_x1142 = kk_string_box(_x_x1143); /*79*/
    kk_std_core_types__list _x_x1145;
    kk_box_t _x_x1146;
    kk_string_t _x_x1147;
    kk_define_string_literal(, _s_x1148, 5, "mardi", _ctx)
    _x_x1147 = kk_string_dup(_s_x1148, _ctx); /*string*/
    _x_x1146 = kk_string_box(_x_x1147); /*79*/
    kk_std_core_types__list _x_x1149;
    kk_box_t _x_x1150;
    kk_string_t _x_x1151;
    kk_define_string_literal(, _s_x1152, 8, "mercredi", _ctx)
    _x_x1151 = kk_string_dup(_s_x1152, _ctx); /*string*/
    _x_x1150 = kk_string_box(_x_x1151); /*79*/
    kk_std_core_types__list _x_x1153;
    kk_box_t _x_x1154;
    kk_string_t _x_x1155;
    kk_define_string_literal(, _s_x1156, 5, "jeudi", _ctx)
    _x_x1155 = kk_string_dup(_s_x1156, _ctx); /*string*/
    _x_x1154 = kk_string_box(_x_x1155); /*79*/
    kk_std_core_types__list _x_x1157;
    kk_box_t _x_x1158;
    kk_string_t _x_x1159;
    kk_define_string_literal(, _s_x1160, 8, "vendredi", _ctx)
    _x_x1159 = kk_string_dup(_s_x1160, _ctx); /*string*/
    _x_x1158 = kk_string_box(_x_x1159); /*79*/
    kk_std_core_types__list _x_x1161;
    kk_box_t _x_x1162;
    kk_string_t _x_x1163;
    kk_define_string_literal(, _s_x1164, 6, "samedi", _ctx)
    _x_x1163 = kk_string_dup(_s_x1164, _ctx); /*string*/
    _x_x1162 = kk_string_box(_x_x1163); /*79*/
    kk_std_core_types__list _x_x1165;
    kk_box_t _x_x1166;
    kk_string_t _x_x1167;
    kk_define_string_literal(, _s_x1168, 8, "dimanche", _ctx)
    _x_x1167 = kk_string_dup(_s_x1168, _ctx); /*string*/
    _x_x1166 = kk_string_box(_x_x1167); /*79*/
    _x_x1165 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1166, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1161 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1162, _x_x1165, _ctx); /*list<79>*/
    _x_x1157 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1158, _x_x1161, _ctx); /*list<79>*/
    _x_x1153 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1154, _x_x1157, _ctx); /*list<79>*/
    _x_x1149 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1150, _x_x1153, _ctx); /*list<79>*/
    _x_x1145 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1146, _x_x1149, _ctx); /*list<79>*/
    _x_x1141 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1142, _x_x1145, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1169;
    kk_box_t _x_x1170;
    kk_string_t _x_x1171;
    kk_define_string_literal(, _s_x1172, 7, "janvier", _ctx)
    _x_x1171 = kk_string_dup(_s_x1172, _ctx); /*string*/
    _x_x1170 = kk_string_box(_x_x1171); /*79*/
    kk_std_core_types__list _x_x1173;
    kk_box_t _x_x1174;
    kk_string_t _x_x1175;
    kk_define_string_literal(, _s_x1176, 8, "f" "\xC3\xA9" "vrier", _ctx)
    _x_x1175 = kk_string_dup(_s_x1176, _ctx); /*string*/
    _x_x1174 = kk_string_box(_x_x1175); /*79*/
    kk_std_core_types__list _x_x1177;
    kk_box_t _x_x1178;
    kk_string_t _x_x1179;
    kk_define_string_literal(, _s_x1180, 4, "mars", _ctx)
    _x_x1179 = kk_string_dup(_s_x1180, _ctx); /*string*/
    _x_x1178 = kk_string_box(_x_x1179); /*79*/
    kk_std_core_types__list _x_x1181;
    kk_box_t _x_x1182;
    kk_string_t _x_x1183;
    kk_define_string_literal(, _s_x1184, 5, "avril", _ctx)
    _x_x1183 = kk_string_dup(_s_x1184, _ctx); /*string*/
    _x_x1182 = kk_string_box(_x_x1183); /*79*/
    kk_std_core_types__list _x_x1185;
    kk_box_t _x_x1186;
    kk_string_t _x_x1187;
    kk_define_string_literal(, _s_x1188, 3, "mai", _ctx)
    _x_x1187 = kk_string_dup(_s_x1188, _ctx); /*string*/
    _x_x1186 = kk_string_box(_x_x1187); /*79*/
    kk_std_core_types__list _x_x1189;
    kk_box_t _x_x1190;
    kk_string_t _x_x1191;
    kk_define_string_literal(, _s_x1192, 4, "juin", _ctx)
    _x_x1191 = kk_string_dup(_s_x1192, _ctx); /*string*/
    _x_x1190 = kk_string_box(_x_x1191); /*79*/
    kk_std_core_types__list _x_x1193;
    kk_box_t _x_x1194;
    kk_string_t _x_x1195;
    kk_define_string_literal(, _s_x1196, 7, "juillet", _ctx)
    _x_x1195 = kk_string_dup(_s_x1196, _ctx); /*string*/
    _x_x1194 = kk_string_box(_x_x1195); /*79*/
    kk_std_core_types__list _x_x1197;
    kk_box_t _x_x1198;
    kk_string_t _x_x1199;
    kk_define_string_literal(, _s_x1200, 5, "ao" "\xC3\xBB" "t", _ctx)
    _x_x1199 = kk_string_dup(_s_x1200, _ctx); /*string*/
    _x_x1198 = kk_string_box(_x_x1199); /*79*/
    kk_std_core_types__list _x_x1201;
    kk_box_t _x_x1202;
    kk_string_t _x_x1203;
    kk_define_string_literal(, _s_x1204, 9, "septembre", _ctx)
    _x_x1203 = kk_string_dup(_s_x1204, _ctx); /*string*/
    _x_x1202 = kk_string_box(_x_x1203); /*79*/
    kk_std_core_types__list _x_x1205;
    kk_box_t _x_x1206;
    kk_string_t _x_x1207;
    kk_define_string_literal(, _s_x1208, 7, "octobre", _ctx)
    _x_x1207 = kk_string_dup(_s_x1208, _ctx); /*string*/
    _x_x1206 = kk_string_box(_x_x1207); /*79*/
    kk_std_core_types__list _x_x1209;
    kk_box_t _x_x1210;
    kk_string_t _x_x1211;
    kk_define_string_literal(, _s_x1212, 8, "novembre", _ctx)
    _x_x1211 = kk_string_dup(_s_x1212, _ctx); /*string*/
    _x_x1210 = kk_string_box(_x_x1211); /*79*/
    kk_std_core_types__list _x_x1213;
    kk_box_t _x_x1214;
    kk_string_t _x_x1215;
    kk_define_string_literal(, _s_x1216, 9, "d" "\xC3\xA9" "cembre", _ctx)
    _x_x1215 = kk_string_dup(_s_x1216, _ctx); /*string*/
    _x_x1214 = kk_string_box(_x_x1215); /*79*/
    _x_x1213 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1214, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1209 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1210, _x_x1213, _ctx); /*list<79>*/
    _x_x1205 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1206, _x_x1209, _ctx); /*list<79>*/
    _x_x1201 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1202, _x_x1205, _ctx); /*list<79>*/
    _x_x1197 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1198, _x_x1201, _ctx); /*list<79>*/
    _x_x1193 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1194, _x_x1197, _ctx); /*list<79>*/
    _x_x1189 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1190, _x_x1193, _ctx); /*list<79>*/
    _x_x1185 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1186, _x_x1189, _ctx); /*list<79>*/
    _x_x1181 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1182, _x_x1185, _ctx); /*list<79>*/
    _x_x1177 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1178, _x_x1181, _ctx); /*list<79>*/
    _x_x1173 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1174, _x_x1177, _ctx); /*list<79>*/
    _x_x1169 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1170, _x_x1173, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1217;
    kk_box_t _x_x1218;
    kk_string_t _x_x1219;
    kk_define_string_literal(, _s_x1220, 5, "janv.", _ctx)
    _x_x1219 = kk_string_dup(_s_x1220, _ctx); /*string*/
    _x_x1218 = kk_string_box(_x_x1219); /*79*/
    kk_std_core_types__list _x_x1221;
    kk_box_t _x_x1222;
    kk_string_t _x_x1223;
    kk_define_string_literal(, _s_x1224, 6, "f" "\xC3\xA9" "vr.", _ctx)
    _x_x1223 = kk_string_dup(_s_x1224, _ctx); /*string*/
    _x_x1222 = kk_string_box(_x_x1223); /*79*/
    kk_std_core_types__list _x_x1225;
    kk_box_t _x_x1226;
    kk_string_t _x_x1227;
    kk_define_string_literal(, _s_x1228, 4, "mars", _ctx)
    _x_x1227 = kk_string_dup(_s_x1228, _ctx); /*string*/
    _x_x1226 = kk_string_box(_x_x1227); /*79*/
    kk_std_core_types__list _x_x1229;
    kk_box_t _x_x1230;
    kk_string_t _x_x1231;
    kk_define_string_literal(, _s_x1232, 4, "avr.", _ctx)
    _x_x1231 = kk_string_dup(_s_x1232, _ctx); /*string*/
    _x_x1230 = kk_string_box(_x_x1231); /*79*/
    kk_std_core_types__list _x_x1233;
    kk_box_t _x_x1234;
    kk_string_t _x_x1235;
    kk_define_string_literal(, _s_x1236, 3, "mai", _ctx)
    _x_x1235 = kk_string_dup(_s_x1236, _ctx); /*string*/
    _x_x1234 = kk_string_box(_x_x1235); /*79*/
    kk_std_core_types__list _x_x1237;
    kk_box_t _x_x1238;
    kk_string_t _x_x1239;
    kk_define_string_literal(, _s_x1240, 4, "juin", _ctx)
    _x_x1239 = kk_string_dup(_s_x1240, _ctx); /*string*/
    _x_x1238 = kk_string_box(_x_x1239); /*79*/
    kk_std_core_types__list _x_x1241;
    kk_box_t _x_x1242;
    kk_string_t _x_x1243;
    kk_define_string_literal(, _s_x1244, 5, "juil.", _ctx)
    _x_x1243 = kk_string_dup(_s_x1244, _ctx); /*string*/
    _x_x1242 = kk_string_box(_x_x1243); /*79*/
    kk_std_core_types__list _x_x1245;
    kk_box_t _x_x1246;
    kk_string_t _x_x1247;
    kk_define_string_literal(, _s_x1248, 5, "ao" "\xC3\xBB" "t", _ctx)
    _x_x1247 = kk_string_dup(_s_x1248, _ctx); /*string*/
    _x_x1246 = kk_string_box(_x_x1247); /*79*/
    kk_std_core_types__list _x_x1249;
    kk_box_t _x_x1250;
    kk_string_t _x_x1251;
    kk_define_string_literal(, _s_x1252, 5, "sept.", _ctx)
    _x_x1251 = kk_string_dup(_s_x1252, _ctx); /*string*/
    _x_x1250 = kk_string_box(_x_x1251); /*79*/
    kk_std_core_types__list _x_x1253;
    kk_box_t _x_x1254;
    kk_string_t _x_x1255;
    kk_define_string_literal(, _s_x1256, 4, "oct.", _ctx)
    _x_x1255 = kk_string_dup(_s_x1256, _ctx); /*string*/
    _x_x1254 = kk_string_box(_x_x1255); /*79*/
    kk_std_core_types__list _x_x1257;
    kk_box_t _x_x1258;
    kk_string_t _x_x1259;
    kk_define_string_literal(, _s_x1260, 4, "nov.", _ctx)
    _x_x1259 = kk_string_dup(_s_x1260, _ctx); /*string*/
    _x_x1258 = kk_string_box(_x_x1259); /*79*/
    kk_std_core_types__list _x_x1261;
    kk_box_t _x_x1262;
    kk_string_t _x_x1263;
    kk_define_string_literal(, _s_x1264, 5, "d" "\xC3\xA9" "c.", _ctx)
    _x_x1263 = kk_string_dup(_s_x1264, _ctx); /*string*/
    _x_x1262 = kk_string_box(_x_x1263); /*79*/
    _x_x1261 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1262, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1257 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1258, _x_x1261, _ctx); /*list<79>*/
    _x_x1253 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1254, _x_x1257, _ctx); /*list<79>*/
    _x_x1249 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1250, _x_x1253, _ctx); /*list<79>*/
    _x_x1245 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1246, _x_x1249, _ctx); /*list<79>*/
    _x_x1241 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1242, _x_x1245, _ctx); /*list<79>*/
    _x_x1237 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1238, _x_x1241, _ctx); /*list<79>*/
    _x_x1233 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1234, _x_x1237, _ctx); /*list<79>*/
    _x_x1229 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1230, _x_x1233, _ctx); /*list<79>*/
    _x_x1225 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1226, _x_x1229, _ctx); /*list<79>*/
    _x_x1221 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1222, _x_x1225, _ctx); /*list<79>*/
    _x_x1217 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1218, _x_x1221, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1265;
    kk_box_t _x_x1266;
    kk_string_t _x_x1267;
    kk_define_string_literal(, _s_x1268, 4, "lun.", _ctx)
    _x_x1267 = kk_string_dup(_s_x1268, _ctx); /*string*/
    _x_x1266 = kk_string_box(_x_x1267); /*79*/
    kk_std_core_types__list _x_x1269;
    kk_box_t _x_x1270;
    kk_string_t _x_x1271;
    kk_define_string_literal(, _s_x1272, 4, "mar.", _ctx)
    _x_x1271 = kk_string_dup(_s_x1272, _ctx); /*string*/
    _x_x1270 = kk_string_box(_x_x1271); /*79*/
    kk_std_core_types__list _x_x1273;
    kk_box_t _x_x1274;
    kk_string_t _x_x1275;
    kk_define_string_literal(, _s_x1276, 4, "mer.", _ctx)
    _x_x1275 = kk_string_dup(_s_x1276, _ctx); /*string*/
    _x_x1274 = kk_string_box(_x_x1275); /*79*/
    kk_std_core_types__list _x_x1277;
    kk_box_t _x_x1278;
    kk_string_t _x_x1279;
    kk_define_string_literal(, _s_x1280, 4, "jeu.", _ctx)
    _x_x1279 = kk_string_dup(_s_x1280, _ctx); /*string*/
    _x_x1278 = kk_string_box(_x_x1279); /*79*/
    kk_std_core_types__list _x_x1281;
    kk_box_t _x_x1282;
    kk_string_t _x_x1283;
    kk_define_string_literal(, _s_x1284, 4, "ven.", _ctx)
    _x_x1283 = kk_string_dup(_s_x1284, _ctx); /*string*/
    _x_x1282 = kk_string_box(_x_x1283); /*79*/
    kk_std_core_types__list _x_x1285;
    kk_box_t _x_x1286;
    kk_string_t _x_x1287;
    kk_define_string_literal(, _s_x1288, 4, "sam.", _ctx)
    _x_x1287 = kk_string_dup(_s_x1288, _ctx); /*string*/
    _x_x1286 = kk_string_box(_x_x1287); /*79*/
    kk_std_core_types__list _x_x1289;
    kk_box_t _x_x1290;
    kk_string_t _x_x1291;
    kk_define_string_literal(, _s_x1292, 4, "dim.", _ctx)
    _x_x1291 = kk_string_dup(_s_x1292, _ctx); /*string*/
    _x_x1290 = kk_string_box(_x_x1291); /*79*/
    _x_x1289 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1290, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1285 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1286, _x_x1289, _ctx); /*list<79>*/
    _x_x1281 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1282, _x_x1285, _ctx); /*list<79>*/
    _x_x1277 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1278, _x_x1281, _ctx); /*list<79>*/
    _x_x1273 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1274, _x_x1277, _ctx); /*list<79>*/
    _x_x1269 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1270, _x_x1273, _ctx); /*list<79>*/
    _x_x1265 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1266, _x_x1269, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1293;
    kk_box_t _x_x1294;
    kk_string_t _x_x1295;
    kk_define_string_literal(, _s_x1296, 2, "Lu", _ctx)
    _x_x1295 = kk_string_dup(_s_x1296, _ctx); /*string*/
    _x_x1294 = kk_string_box(_x_x1295); /*79*/
    kk_std_core_types__list _x_x1297;
    kk_box_t _x_x1298;
    kk_string_t _x_x1299;
    kk_define_string_literal(, _s_x1300, 2, "Ma", _ctx)
    _x_x1299 = kk_string_dup(_s_x1300, _ctx); /*string*/
    _x_x1298 = kk_string_box(_x_x1299); /*79*/
    kk_std_core_types__list _x_x1301;
    kk_box_t _x_x1302;
    kk_string_t _x_x1303;
    kk_define_string_literal(, _s_x1304, 2, "Me", _ctx)
    _x_x1303 = kk_string_dup(_s_x1304, _ctx); /*string*/
    _x_x1302 = kk_string_box(_x_x1303); /*79*/
    kk_std_core_types__list _x_x1305;
    kk_box_t _x_x1306;
    kk_string_t _x_x1307;
    kk_define_string_literal(, _s_x1308, 2, "Je", _ctx)
    _x_x1307 = kk_string_dup(_s_x1308, _ctx); /*string*/
    _x_x1306 = kk_string_box(_x_x1307); /*79*/
    kk_std_core_types__list _x_x1309;
    kk_box_t _x_x1310;
    kk_string_t _x_x1311;
    kk_define_string_literal(, _s_x1312, 2, "Ve", _ctx)
    _x_x1311 = kk_string_dup(_s_x1312, _ctx); /*string*/
    _x_x1310 = kk_string_box(_x_x1311); /*79*/
    kk_std_core_types__list _x_x1313;
    kk_box_t _x_x1314;
    kk_string_t _x_x1315;
    kk_define_string_literal(, _s_x1316, 2, "Sa", _ctx)
    _x_x1315 = kk_string_dup(_s_x1316, _ctx); /*string*/
    _x_x1314 = kk_string_box(_x_x1315); /*79*/
    kk_std_core_types__list _x_x1317;
    kk_box_t _x_x1318;
    kk_string_t _x_x1319;
    kk_define_string_literal(, _s_x1320, 2, "Di", _ctx)
    _x_x1319 = kk_string_dup(_s_x1320, _ctx); /*string*/
    _x_x1318 = kk_string_box(_x_x1319); /*79*/
    _x_x1317 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1318, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1313 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1314, _x_x1317, _ctx); /*list<79>*/
    _x_x1309 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1310, _x_x1313, _ctx); /*list<79>*/
    _x_x1305 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1306, _x_x1309, _ctx); /*list<79>*/
    _x_x1301 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1302, _x_x1305, _ctx); /*list<79>*/
    _x_x1297 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1298, _x_x1301, _ctx); /*list<79>*/
    _x_x1293 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1294, _x_x1297, _ctx); /*list<79>*/
    kk_string_t _x_x1321;
    kk_std_core_types__optional _match_x889 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x889, _ctx)) {
      kk_box_t _box_x271 = _match_x889._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x271);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x889, _ctx);
      _x_x1321 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x889, _ctx);
      kk_define_string_literal(, _s_x1322, 5, "HH:mm", _ctx)
      _x_x1321 = kk_string_dup(_s_x1322, _ctx); /*string*/
    }
    kk_string_t _x_x1323;
    kk_std_core_types__optional _match_x888 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x888, _ctx)) {
      kk_box_t _box_x272 = _match_x888._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x272);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x888, _ctx);
      _x_x1323 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x888, _ctx);
      kk_define_string_literal(, _s_x1324, 8, "HH:mm:ss", _ctx)
      _x_x1323 = kk_string_dup(_s_x1324, _ctx); /*string*/
    }
    kk_string_t _x_x1325;
    kk_define_string_literal(, _s_x1326, 10, "DD/MM/YYYY", _ctx)
    _x_x1325 = kk_string_dup(_s_x1326, _ctx); /*string*/
    kk_string_t _x_x1327;
    kk_std_core_types__optional _match_x887 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x887, _ctx)) {
      kk_box_t _box_x273 = _match_x887._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x273);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x887, _ctx);
      _x_x1327 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x887, _ctx);
      kk_define_string_literal(, _s_x1328, 11, "D MMMM YYYY", _ctx)
      _x_x1327 = kk_string_dup(_s_x1328, _ctx); /*string*/
    }
    kk_string_t _x_x1329;
    kk_std_core_types__optional _match_x886 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x886, _ctx)) {
      kk_box_t _box_x274 = _match_x886._cons._Optional.value;
      kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x274);
      kk_string_dup(_uniq_format_lll_235, _ctx);
      kk_std_core_types__optional_drop(_match_x886, _ctx);
      _x_x1329 = _uniq_format_lll_235; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x886, _ctx);
      kk_define_string_literal(, _s_x1330, 13, "D MMMM YYYY t", _ctx)
      _x_x1329 = kk_string_dup(_s_x1330, _ctx); /*string*/
    }
    kk_string_t _x_x1331;
    kk_std_core_types__optional _match_x885 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x885, _ctx)) {
      kk_box_t _box_x275 = _match_x885._cons._Optional.value;
      kk_string_t _uniq_format_llll_239 = kk_string_unbox(_box_x275);
      kk_string_dup(_uniq_format_llll_239, _ctx);
      kk_std_core_types__optional_drop(_match_x885, _ctx);
      _x_x1331 = _uniq_format_llll_239; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x885, _ctx);
      kk_define_string_literal(, _s_x1332, 18, "dddd D MMMM YYYY t", _ctx)
      _x_x1331 = kk_string_dup(_s_x1332, _ctx); /*string*/
    }
    kk_std_time_locale_time_locale_fr = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1139, _x_x1141, _x_x1169, _x_x1217, _x_x1265, _x_x1293, _x_x1321, _x_x1323, _x_x1325, _x_x1327, _x_x1329, _x_x1331, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_string_t _x_x1333;
    kk_define_string_literal(, _s_x1334, 2, "de", _ctx)
    _x_x1333 = kk_string_dup(_s_x1334, _ctx); /*string*/
    kk_std_core_types__list _x_x1335;
    kk_box_t _x_x1336;
    kk_string_t _x_x1337;
    kk_define_string_literal(, _s_x1338, 6, "Montag", _ctx)
    _x_x1337 = kk_string_dup(_s_x1338, _ctx); /*string*/
    _x_x1336 = kk_string_box(_x_x1337); /*79*/
    kk_std_core_types__list _x_x1339;
    kk_box_t _x_x1340;
    kk_string_t _x_x1341;
    kk_define_string_literal(, _s_x1342, 8, "Dienstag", _ctx)
    _x_x1341 = kk_string_dup(_s_x1342, _ctx); /*string*/
    _x_x1340 = kk_string_box(_x_x1341); /*79*/
    kk_std_core_types__list _x_x1343;
    kk_box_t _x_x1344;
    kk_string_t _x_x1345;
    kk_define_string_literal(, _s_x1346, 8, "Mittwoch", _ctx)
    _x_x1345 = kk_string_dup(_s_x1346, _ctx); /*string*/
    _x_x1344 = kk_string_box(_x_x1345); /*79*/
    kk_std_core_types__list _x_x1347;
    kk_box_t _x_x1348;
    kk_string_t _x_x1349;
    kk_define_string_literal(, _s_x1350, 10, "Donnerstag", _ctx)
    _x_x1349 = kk_string_dup(_s_x1350, _ctx); /*string*/
    _x_x1348 = kk_string_box(_x_x1349); /*79*/
    kk_std_core_types__list _x_x1351;
    kk_box_t _x_x1352;
    kk_string_t _x_x1353;
    kk_define_string_literal(, _s_x1354, 7, "Freitag", _ctx)
    _x_x1353 = kk_string_dup(_s_x1354, _ctx); /*string*/
    _x_x1352 = kk_string_box(_x_x1353); /*79*/
    kk_std_core_types__list _x_x1355;
    kk_box_t _x_x1356;
    kk_string_t _x_x1357;
    kk_define_string_literal(, _s_x1358, 7, "Samstag", _ctx)
    _x_x1357 = kk_string_dup(_s_x1358, _ctx); /*string*/
    _x_x1356 = kk_string_box(_x_x1357); /*79*/
    kk_std_core_types__list _x_x1359;
    kk_box_t _x_x1360;
    kk_string_t _x_x1361;
    kk_define_string_literal(, _s_x1362, 7, "Sonntag", _ctx)
    _x_x1361 = kk_string_dup(_s_x1362, _ctx); /*string*/
    _x_x1360 = kk_string_box(_x_x1361); /*79*/
    _x_x1359 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1360, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1355 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1356, _x_x1359, _ctx); /*list<79>*/
    _x_x1351 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1352, _x_x1355, _ctx); /*list<79>*/
    _x_x1347 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1348, _x_x1351, _ctx); /*list<79>*/
    _x_x1343 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1344, _x_x1347, _ctx); /*list<79>*/
    _x_x1339 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1340, _x_x1343, _ctx); /*list<79>*/
    _x_x1335 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1336, _x_x1339, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1363;
    kk_box_t _x_x1364;
    kk_string_t _x_x1365;
    kk_define_string_literal(, _s_x1366, 6, "Januar", _ctx)
    _x_x1365 = kk_string_dup(_s_x1366, _ctx); /*string*/
    _x_x1364 = kk_string_box(_x_x1365); /*79*/
    kk_std_core_types__list _x_x1367;
    kk_box_t _x_x1368;
    kk_string_t _x_x1369;
    kk_define_string_literal(, _s_x1370, 7, "Februar", _ctx)
    _x_x1369 = kk_string_dup(_s_x1370, _ctx); /*string*/
    _x_x1368 = kk_string_box(_x_x1369); /*79*/
    kk_std_core_types__list _x_x1371;
    kk_box_t _x_x1372;
    kk_string_t _x_x1373;
    kk_define_string_literal(, _s_x1374, 5, "M" "\xC3\xA4" "rz", _ctx)
    _x_x1373 = kk_string_dup(_s_x1374, _ctx); /*string*/
    _x_x1372 = kk_string_box(_x_x1373); /*79*/
    kk_std_core_types__list _x_x1375;
    kk_box_t _x_x1376;
    kk_string_t _x_x1377;
    kk_define_string_literal(, _s_x1378, 5, "April", _ctx)
    _x_x1377 = kk_string_dup(_s_x1378, _ctx); /*string*/
    _x_x1376 = kk_string_box(_x_x1377); /*79*/
    kk_std_core_types__list _x_x1379;
    kk_box_t _x_x1380;
    kk_string_t _x_x1381;
    kk_define_string_literal(, _s_x1382, 3, "Mai", _ctx)
    _x_x1381 = kk_string_dup(_s_x1382, _ctx); /*string*/
    _x_x1380 = kk_string_box(_x_x1381); /*79*/
    kk_std_core_types__list _x_x1383;
    kk_box_t _x_x1384;
    kk_string_t _x_x1385;
    kk_define_string_literal(, _s_x1386, 4, "Juni", _ctx)
    _x_x1385 = kk_string_dup(_s_x1386, _ctx); /*string*/
    _x_x1384 = kk_string_box(_x_x1385); /*79*/
    kk_std_core_types__list _x_x1387;
    kk_box_t _x_x1388;
    kk_string_t _x_x1389;
    kk_define_string_literal(, _s_x1390, 4, "Juli", _ctx)
    _x_x1389 = kk_string_dup(_s_x1390, _ctx); /*string*/
    _x_x1388 = kk_string_box(_x_x1389); /*79*/
    kk_std_core_types__list _x_x1391;
    kk_box_t _x_x1392;
    kk_string_t _x_x1393;
    kk_define_string_literal(, _s_x1394, 6, "August", _ctx)
    _x_x1393 = kk_string_dup(_s_x1394, _ctx); /*string*/
    _x_x1392 = kk_string_box(_x_x1393); /*79*/
    kk_std_core_types__list _x_x1395;
    kk_box_t _x_x1396;
    kk_string_t _x_x1397;
    kk_define_string_literal(, _s_x1398, 9, "September", _ctx)
    _x_x1397 = kk_string_dup(_s_x1398, _ctx); /*string*/
    _x_x1396 = kk_string_box(_x_x1397); /*79*/
    kk_std_core_types__list _x_x1399;
    kk_box_t _x_x1400;
    kk_string_t _x_x1401;
    kk_define_string_literal(, _s_x1402, 7, "Oktober", _ctx)
    _x_x1401 = kk_string_dup(_s_x1402, _ctx); /*string*/
    _x_x1400 = kk_string_box(_x_x1401); /*79*/
    kk_std_core_types__list _x_x1403;
    kk_box_t _x_x1404;
    kk_string_t _x_x1405;
    kk_define_string_literal(, _s_x1406, 8, "November", _ctx)
    _x_x1405 = kk_string_dup(_s_x1406, _ctx); /*string*/
    _x_x1404 = kk_string_box(_x_x1405); /*79*/
    kk_std_core_types__list _x_x1407;
    kk_box_t _x_x1408;
    kk_string_t _x_x1409;
    kk_define_string_literal(, _s_x1410, 8, "Dezember", _ctx)
    _x_x1409 = kk_string_dup(_s_x1410, _ctx); /*string*/
    _x_x1408 = kk_string_box(_x_x1409); /*79*/
    _x_x1407 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1408, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1403 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1404, _x_x1407, _ctx); /*list<79>*/
    _x_x1399 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1400, _x_x1403, _ctx); /*list<79>*/
    _x_x1395 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1396, _x_x1399, _ctx); /*list<79>*/
    _x_x1391 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1392, _x_x1395, _ctx); /*list<79>*/
    _x_x1387 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1388, _x_x1391, _ctx); /*list<79>*/
    _x_x1383 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1384, _x_x1387, _ctx); /*list<79>*/
    _x_x1379 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1380, _x_x1383, _ctx); /*list<79>*/
    _x_x1375 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1376, _x_x1379, _ctx); /*list<79>*/
    _x_x1371 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1372, _x_x1375, _ctx); /*list<79>*/
    _x_x1367 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1368, _x_x1371, _ctx); /*list<79>*/
    _x_x1363 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1364, _x_x1367, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1411;
    kk_box_t _x_x1412;
    kk_string_t _x_x1413;
    kk_define_string_literal(, _s_x1414, 4, "Jan.", _ctx)
    _x_x1413 = kk_string_dup(_s_x1414, _ctx); /*string*/
    _x_x1412 = kk_string_box(_x_x1413); /*79*/
    kk_std_core_types__list _x_x1415;
    kk_box_t _x_x1416;
    kk_string_t _x_x1417;
    kk_define_string_literal(, _s_x1418, 5, "Febr.", _ctx)
    _x_x1417 = kk_string_dup(_s_x1418, _ctx); /*string*/
    _x_x1416 = kk_string_box(_x_x1417); /*79*/
    kk_std_core_types__list _x_x1419;
    kk_box_t _x_x1420;
    kk_string_t _x_x1421;
    kk_define_string_literal(, _s_x1422, 4, "Mrz.", _ctx)
    _x_x1421 = kk_string_dup(_s_x1422, _ctx); /*string*/
    _x_x1420 = kk_string_box(_x_x1421); /*79*/
    kk_std_core_types__list _x_x1423;
    kk_box_t _x_x1424;
    kk_string_t _x_x1425;
    kk_define_string_literal(, _s_x1426, 4, "Apr.", _ctx)
    _x_x1425 = kk_string_dup(_s_x1426, _ctx); /*string*/
    _x_x1424 = kk_string_box(_x_x1425); /*79*/
    kk_std_core_types__list _x_x1427;
    kk_box_t _x_x1428;
    kk_string_t _x_x1429;
    kk_define_string_literal(, _s_x1430, 3, "Mai", _ctx)
    _x_x1429 = kk_string_dup(_s_x1430, _ctx); /*string*/
    _x_x1428 = kk_string_box(_x_x1429); /*79*/
    kk_std_core_types__list _x_x1431;
    kk_box_t _x_x1432;
    kk_string_t _x_x1433;
    kk_define_string_literal(, _s_x1434, 4, "Jun.", _ctx)
    _x_x1433 = kk_string_dup(_s_x1434, _ctx); /*string*/
    _x_x1432 = kk_string_box(_x_x1433); /*79*/
    kk_std_core_types__list _x_x1435;
    kk_box_t _x_x1436;
    kk_string_t _x_x1437;
    kk_define_string_literal(, _s_x1438, 4, "Jul.", _ctx)
    _x_x1437 = kk_string_dup(_s_x1438, _ctx); /*string*/
    _x_x1436 = kk_string_box(_x_x1437); /*79*/
    kk_std_core_types__list _x_x1439;
    kk_box_t _x_x1440;
    kk_string_t _x_x1441;
    kk_define_string_literal(, _s_x1442, 4, "Aug.", _ctx)
    _x_x1441 = kk_string_dup(_s_x1442, _ctx); /*string*/
    _x_x1440 = kk_string_box(_x_x1441); /*79*/
    kk_std_core_types__list _x_x1443;
    kk_box_t _x_x1444;
    kk_string_t _x_x1445;
    kk_define_string_literal(, _s_x1446, 5, "Sept.", _ctx)
    _x_x1445 = kk_string_dup(_s_x1446, _ctx); /*string*/
    _x_x1444 = kk_string_box(_x_x1445); /*79*/
    kk_std_core_types__list _x_x1447;
    kk_box_t _x_x1448;
    kk_string_t _x_x1449;
    kk_define_string_literal(, _s_x1450, 4, "Okt.", _ctx)
    _x_x1449 = kk_string_dup(_s_x1450, _ctx); /*string*/
    _x_x1448 = kk_string_box(_x_x1449); /*79*/
    kk_std_core_types__list _x_x1451;
    kk_box_t _x_x1452;
    kk_string_t _x_x1453;
    kk_define_string_literal(, _s_x1454, 4, "Nov.", _ctx)
    _x_x1453 = kk_string_dup(_s_x1454, _ctx); /*string*/
    _x_x1452 = kk_string_box(_x_x1453); /*79*/
    kk_std_core_types__list _x_x1455;
    kk_box_t _x_x1456;
    kk_string_t _x_x1457;
    kk_define_string_literal(, _s_x1458, 4, "Dez.", _ctx)
    _x_x1457 = kk_string_dup(_s_x1458, _ctx); /*string*/
    _x_x1456 = kk_string_box(_x_x1457); /*79*/
    _x_x1455 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1456, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1451 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1452, _x_x1455, _ctx); /*list<79>*/
    _x_x1447 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1448, _x_x1451, _ctx); /*list<79>*/
    _x_x1443 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1444, _x_x1447, _ctx); /*list<79>*/
    _x_x1439 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1440, _x_x1443, _ctx); /*list<79>*/
    _x_x1435 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1436, _x_x1439, _ctx); /*list<79>*/
    _x_x1431 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1432, _x_x1435, _ctx); /*list<79>*/
    _x_x1427 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1428, _x_x1431, _ctx); /*list<79>*/
    _x_x1423 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1424, _x_x1427, _ctx); /*list<79>*/
    _x_x1419 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1420, _x_x1423, _ctx); /*list<79>*/
    _x_x1415 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1416, _x_x1419, _ctx); /*list<79>*/
    _x_x1411 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1412, _x_x1415, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1459;
    kk_box_t _x_x1460;
    kk_string_t _x_x1461;
    kk_define_string_literal(, _s_x1462, 3, "Mo.", _ctx)
    _x_x1461 = kk_string_dup(_s_x1462, _ctx); /*string*/
    _x_x1460 = kk_string_box(_x_x1461); /*79*/
    kk_std_core_types__list _x_x1463;
    kk_box_t _x_x1464;
    kk_string_t _x_x1465;
    kk_define_string_literal(, _s_x1466, 3, "Di.", _ctx)
    _x_x1465 = kk_string_dup(_s_x1466, _ctx); /*string*/
    _x_x1464 = kk_string_box(_x_x1465); /*79*/
    kk_std_core_types__list _x_x1467;
    kk_box_t _x_x1468;
    kk_string_t _x_x1469;
    kk_define_string_literal(, _s_x1470, 3, "Mi.", _ctx)
    _x_x1469 = kk_string_dup(_s_x1470, _ctx); /*string*/
    _x_x1468 = kk_string_box(_x_x1469); /*79*/
    kk_std_core_types__list _x_x1471;
    kk_box_t _x_x1472;
    kk_string_t _x_x1473;
    kk_define_string_literal(, _s_x1474, 3, "Do.", _ctx)
    _x_x1473 = kk_string_dup(_s_x1474, _ctx); /*string*/
    _x_x1472 = kk_string_box(_x_x1473); /*79*/
    kk_std_core_types__list _x_x1475;
    kk_box_t _x_x1476;
    kk_string_t _x_x1477;
    kk_define_string_literal(, _s_x1478, 3, "Fr.", _ctx)
    _x_x1477 = kk_string_dup(_s_x1478, _ctx); /*string*/
    _x_x1476 = kk_string_box(_x_x1477); /*79*/
    kk_std_core_types__list _x_x1479;
    kk_box_t _x_x1480;
    kk_string_t _x_x1481;
    kk_define_string_literal(, _s_x1482, 3, "Sa.", _ctx)
    _x_x1481 = kk_string_dup(_s_x1482, _ctx); /*string*/
    _x_x1480 = kk_string_box(_x_x1481); /*79*/
    kk_std_core_types__list _x_x1483;
    kk_box_t _x_x1484;
    kk_string_t _x_x1485;
    kk_define_string_literal(, _s_x1486, 3, "So.", _ctx)
    _x_x1485 = kk_string_dup(_s_x1486, _ctx); /*string*/
    _x_x1484 = kk_string_box(_x_x1485); /*79*/
    _x_x1483 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1484, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1479 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1480, _x_x1483, _ctx); /*list<79>*/
    _x_x1475 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1476, _x_x1479, _ctx); /*list<79>*/
    _x_x1471 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1472, _x_x1475, _ctx); /*list<79>*/
    _x_x1467 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1468, _x_x1471, _ctx); /*list<79>*/
    _x_x1463 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1464, _x_x1467, _ctx); /*list<79>*/
    _x_x1459 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1460, _x_x1463, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1487;
    kk_box_t _x_x1488;
    kk_string_t _x_x1489;
    kk_define_string_literal(, _s_x1490, 2, "Mo", _ctx)
    _x_x1489 = kk_string_dup(_s_x1490, _ctx); /*string*/
    _x_x1488 = kk_string_box(_x_x1489); /*79*/
    kk_std_core_types__list _x_x1491;
    kk_box_t _x_x1492;
    kk_string_t _x_x1493;
    kk_define_string_literal(, _s_x1494, 2, "Di", _ctx)
    _x_x1493 = kk_string_dup(_s_x1494, _ctx); /*string*/
    _x_x1492 = kk_string_box(_x_x1493); /*79*/
    kk_std_core_types__list _x_x1495;
    kk_box_t _x_x1496;
    kk_string_t _x_x1497;
    kk_define_string_literal(, _s_x1498, 2, "Mi", _ctx)
    _x_x1497 = kk_string_dup(_s_x1498, _ctx); /*string*/
    _x_x1496 = kk_string_box(_x_x1497); /*79*/
    kk_std_core_types__list _x_x1499;
    kk_box_t _x_x1500;
    kk_string_t _x_x1501;
    kk_define_string_literal(, _s_x1502, 2, "Do", _ctx)
    _x_x1501 = kk_string_dup(_s_x1502, _ctx); /*string*/
    _x_x1500 = kk_string_box(_x_x1501); /*79*/
    kk_std_core_types__list _x_x1503;
    kk_box_t _x_x1504;
    kk_string_t _x_x1505;
    kk_define_string_literal(, _s_x1506, 2, "Fr", _ctx)
    _x_x1505 = kk_string_dup(_s_x1506, _ctx); /*string*/
    _x_x1504 = kk_string_box(_x_x1505); /*79*/
    kk_std_core_types__list _x_x1507;
    kk_box_t _x_x1508;
    kk_string_t _x_x1509;
    kk_define_string_literal(, _s_x1510, 2, "Sa", _ctx)
    _x_x1509 = kk_string_dup(_s_x1510, _ctx); /*string*/
    _x_x1508 = kk_string_box(_x_x1509); /*79*/
    kk_std_core_types__list _x_x1511;
    kk_box_t _x_x1512;
    kk_string_t _x_x1513;
    kk_define_string_literal(, _s_x1514, 2, "So", _ctx)
    _x_x1513 = kk_string_dup(_s_x1514, _ctx); /*string*/
    _x_x1512 = kk_string_box(_x_x1513); /*79*/
    _x_x1511 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1512, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1507 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1508, _x_x1511, _ctx); /*list<79>*/
    _x_x1503 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1504, _x_x1507, _ctx); /*list<79>*/
    _x_x1499 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1500, _x_x1503, _ctx); /*list<79>*/
    _x_x1495 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1496, _x_x1499, _ctx); /*list<79>*/
    _x_x1491 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1492, _x_x1495, _ctx); /*list<79>*/
    _x_x1487 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1488, _x_x1491, _ctx); /*list<79>*/
    kk_string_t _x_x1515;
    kk_std_core_types__optional _match_x884 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x884, _ctx)) {
      kk_box_t _box_x456 = _match_x884._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x456);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x884, _ctx);
      _x_x1515 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x884, _ctx);
      kk_define_string_literal(, _s_x1516, 5, "HH:mm", _ctx)
      _x_x1515 = kk_string_dup(_s_x1516, _ctx); /*string*/
    }
    kk_string_t _x_x1517;
    kk_std_core_types__optional _match_x883 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x883, _ctx)) {
      kk_box_t _box_x457 = _match_x883._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x457);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x883, _ctx);
      _x_x1517 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x883, _ctx);
      kk_define_string_literal(, _s_x1518, 8, "HH:mm:ss", _ctx)
      _x_x1517 = kk_string_dup(_s_x1518, _ctx); /*string*/
    }
    kk_string_t _x_x1519;
    kk_define_string_literal(, _s_x1520, 10, "DD.MM.YYYY", _ctx)
    _x_x1519 = kk_string_dup(_s_x1520, _ctx); /*string*/
    kk_string_t _x_x1521;
    kk_define_string_literal(, _s_x1522, 12, "D. MMMM YYYY", _ctx)
    _x_x1521 = kk_string_dup(_s_x1522, _ctx); /*string*/
    kk_string_t _x_x1523;
    kk_define_string_literal(, _s_x1524, 14, "D. MMMM YYYY t", _ctx)
    _x_x1523 = kk_string_dup(_s_x1524, _ctx); /*string*/
    kk_string_t _x_x1525;
    kk_define_string_literal(, _s_x1526, 20, "dddd, D. MMMM YYYY t", _ctx)
    _x_x1525 = kk_string_dup(_s_x1526, _ctx); /*string*/
    kk_std_time_locale_time_locale_de = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1333, _x_x1335, _x_x1363, _x_x1411, _x_x1459, _x_x1487, _x_x1515, _x_x1517, _x_x1519, _x_x1521, _x_x1523, _x_x1525, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_std_core_types__list day_names_10051;
    kk_box_t _x_x1527;
    kk_string_t _x_x1528;
    kk_define_string_literal(, _s_x1529, 5, "lunes", _ctx)
    _x_x1528 = kk_string_dup(_s_x1529, _ctx); /*string*/
    _x_x1527 = kk_string_box(_x_x1528); /*79*/
    kk_std_core_types__list _x_x1530;
    kk_box_t _x_x1531;
    kk_string_t _x_x1532;
    kk_define_string_literal(, _s_x1533, 6, "martes", _ctx)
    _x_x1532 = kk_string_dup(_s_x1533, _ctx); /*string*/
    _x_x1531 = kk_string_box(_x_x1532); /*79*/
    kk_std_core_types__list _x_x1534;
    kk_box_t _x_x1535;
    kk_string_t _x_x1536;
    kk_define_string_literal(, _s_x1537, 10, "mi" "\xC3\xA9" "rcoles", _ctx)
    _x_x1536 = kk_string_dup(_s_x1537, _ctx); /*string*/
    _x_x1535 = kk_string_box(_x_x1536); /*79*/
    kk_std_core_types__list _x_x1538;
    kk_box_t _x_x1539;
    kk_string_t _x_x1540;
    kk_define_string_literal(, _s_x1541, 6, "jueves", _ctx)
    _x_x1540 = kk_string_dup(_s_x1541, _ctx); /*string*/
    _x_x1539 = kk_string_box(_x_x1540); /*79*/
    kk_std_core_types__list _x_x1542;
    kk_box_t _x_x1543;
    kk_string_t _x_x1544;
    kk_define_string_literal(, _s_x1545, 7, "viernes", _ctx)
    _x_x1544 = kk_string_dup(_s_x1545, _ctx); /*string*/
    _x_x1543 = kk_string_box(_x_x1544); /*79*/
    kk_std_core_types__list _x_x1546;
    kk_box_t _x_x1547;
    kk_string_t _x_x1548;
    kk_define_string_literal(, _s_x1549, 7, "s" "\xC3\xA1" "bado", _ctx)
    _x_x1548 = kk_string_dup(_s_x1549, _ctx); /*string*/
    _x_x1547 = kk_string_box(_x_x1548); /*79*/
    kk_std_core_types__list _x_x1550;
    kk_box_t _x_x1551;
    kk_string_t _x_x1552;
    kk_define_string_literal(, _s_x1553, 7, "domingo", _ctx)
    _x_x1552 = kk_string_dup(_s_x1553, _ctx); /*string*/
    _x_x1551 = kk_string_box(_x_x1552); /*79*/
    _x_x1550 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1551, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1546 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1547, _x_x1550, _ctx); /*list<79>*/
    _x_x1542 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1543, _x_x1546, _ctx); /*list<79>*/
    _x_x1538 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1539, _x_x1542, _ctx); /*list<79>*/
    _x_x1534 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1535, _x_x1538, _ctx); /*list<79>*/
    _x_x1530 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1531, _x_x1534, _ctx); /*list<79>*/
    day_names_10051 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1527, _x_x1530, _ctx); /*list<string>*/
    kk_std_core_types__list month_names_10052;
    kk_box_t _x_x1554;
    kk_string_t _x_x1555;
    kk_define_string_literal(, _s_x1556, 5, "enero", _ctx)
    _x_x1555 = kk_string_dup(_s_x1556, _ctx); /*string*/
    _x_x1554 = kk_string_box(_x_x1555); /*79*/
    kk_std_core_types__list _x_x1557;
    kk_box_t _x_x1558;
    kk_string_t _x_x1559;
    kk_define_string_literal(, _s_x1560, 7, "febrero", _ctx)
    _x_x1559 = kk_string_dup(_s_x1560, _ctx); /*string*/
    _x_x1558 = kk_string_box(_x_x1559); /*79*/
    kk_std_core_types__list _x_x1561;
    kk_box_t _x_x1562;
    kk_string_t _x_x1563;
    kk_define_string_literal(, _s_x1564, 5, "marzo", _ctx)
    _x_x1563 = kk_string_dup(_s_x1564, _ctx); /*string*/
    _x_x1562 = kk_string_box(_x_x1563); /*79*/
    kk_std_core_types__list _x_x1565;
    kk_box_t _x_x1566;
    kk_string_t _x_x1567;
    kk_define_string_literal(, _s_x1568, 5, "abril", _ctx)
    _x_x1567 = kk_string_dup(_s_x1568, _ctx); /*string*/
    _x_x1566 = kk_string_box(_x_x1567); /*79*/
    kk_std_core_types__list _x_x1569;
    kk_box_t _x_x1570;
    kk_string_t _x_x1571;
    kk_define_string_literal(, _s_x1572, 4, "mayo", _ctx)
    _x_x1571 = kk_string_dup(_s_x1572, _ctx); /*string*/
    _x_x1570 = kk_string_box(_x_x1571); /*79*/
    kk_std_core_types__list _x_x1573;
    kk_box_t _x_x1574;
    kk_string_t _x_x1575;
    kk_define_string_literal(, _s_x1576, 5, "junio", _ctx)
    _x_x1575 = kk_string_dup(_s_x1576, _ctx); /*string*/
    _x_x1574 = kk_string_box(_x_x1575); /*79*/
    kk_std_core_types__list _x_x1577;
    kk_box_t _x_x1578;
    kk_string_t _x_x1579;
    kk_define_string_literal(, _s_x1580, 5, "julio", _ctx)
    _x_x1579 = kk_string_dup(_s_x1580, _ctx); /*string*/
    _x_x1578 = kk_string_box(_x_x1579); /*79*/
    kk_std_core_types__list _x_x1581;
    kk_box_t _x_x1582;
    kk_string_t _x_x1583;
    kk_define_string_literal(, _s_x1584, 6, "agosto", _ctx)
    _x_x1583 = kk_string_dup(_s_x1584, _ctx); /*string*/
    _x_x1582 = kk_string_box(_x_x1583); /*79*/
    kk_std_core_types__list _x_x1585;
    kk_box_t _x_x1586;
    kk_string_t _x_x1587;
    kk_define_string_literal(, _s_x1588, 10, "septiembre", _ctx)
    _x_x1587 = kk_string_dup(_s_x1588, _ctx); /*string*/
    _x_x1586 = kk_string_box(_x_x1587); /*79*/
    kk_std_core_types__list _x_x1589;
    kk_box_t _x_x1590;
    kk_string_t _x_x1591;
    kk_define_string_literal(, _s_x1592, 7, "octubre", _ctx)
    _x_x1591 = kk_string_dup(_s_x1592, _ctx); /*string*/
    _x_x1590 = kk_string_box(_x_x1591); /*79*/
    kk_std_core_types__list _x_x1593;
    kk_box_t _x_x1594;
    kk_string_t _x_x1595;
    kk_define_string_literal(, _s_x1596, 9, "noviembre", _ctx)
    _x_x1595 = kk_string_dup(_s_x1596, _ctx); /*string*/
    _x_x1594 = kk_string_box(_x_x1595); /*79*/
    kk_std_core_types__list _x_x1597;
    kk_box_t _x_x1598;
    kk_string_t _x_x1599;
    kk_define_string_literal(, _s_x1600, 9, "diciembre", _ctx)
    _x_x1599 = kk_string_dup(_s_x1600, _ctx); /*string*/
    _x_x1598 = kk_string_box(_x_x1599); /*79*/
    _x_x1597 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1598, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1593 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1594, _x_x1597, _ctx); /*list<79>*/
    _x_x1589 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1590, _x_x1593, _ctx); /*list<79>*/
    _x_x1585 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1586, _x_x1589, _ctx); /*list<79>*/
    _x_x1581 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1582, _x_x1585, _ctx); /*list<79>*/
    _x_x1577 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1578, _x_x1581, _ctx); /*list<79>*/
    _x_x1573 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1574, _x_x1577, _ctx); /*list<79>*/
    _x_x1569 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1570, _x_x1573, _ctx); /*list<79>*/
    _x_x1565 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1566, _x_x1569, _ctx); /*list<79>*/
    _x_x1561 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1562, _x_x1565, _ctx); /*list<79>*/
    _x_x1557 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1558, _x_x1561, _ctx); /*list<79>*/
    month_names_10052 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1554, _x_x1557, _ctx); /*list<string>*/
    kk_std_core_types__list _uniq_month_names_short_92;
    kk_std_core_types__optional _match_x880 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x880, _ctx)) {
      kk_box_t _box_x624 = _match_x880._cons._Optional.value;
      kk_std_core_types__list _uniq_month_names_short_93 = kk_std_core_types__list_unbox(_box_x624, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_month_names_short_93, _ctx);
      kk_std_core_types__optional_drop(_match_x880, _ctx);
      _uniq_month_names_short_92 = _uniq_month_names_short_93; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x880, _ctx);
      kk_function_t _brw_x881 = kk_std_time_locale_new_time_locale_es_fun1601(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x882;
      kk_std_core_types__list _x_x1606 = kk_std_core_types__list_dup(month_names_10052, _ctx); /*list<string>*/
      _brw_x882 = kk_std_core_list_map(_x_x1606, _brw_x881, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x881, _ctx);
      _uniq_month_names_short_92 = _brw_x882; /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_short_153;
    kk_std_core_types__optional _match_x877 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x877, _ctx)) {
      kk_box_t _box_x633 = _match_x877._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_short_154 = kk_std_core_types__list_unbox(_box_x633, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_short_154, _ctx);
      kk_std_core_types__optional_drop(_match_x877, _ctx);
      _uniq_day_names_short_153 = _uniq_day_names_short_154; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x877, _ctx);
      kk_function_t _brw_x878 = kk_std_time_locale_new_time_locale_es_fun1607(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x879;
      kk_std_core_types__list _x_x1612 = kk_std_core_types__list_dup(day_names_10051, _ctx); /*list<string>*/
      _brw_x879 = kk_std_core_list_map(_x_x1612, _brw_x878, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x878, _ctx);
      _uniq_day_names_short_153 = _brw_x879; /*list<string>*/
    }
    kk_std_core_types__list _uniq_day_names_min_214;
    kk_std_core_types__optional _match_x874 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x874, _ctx)) {
      kk_box_t _box_x642 = _match_x874._cons._Optional.value;
      kk_std_core_types__list _uniq_day_names_min_215 = kk_std_core_types__list_unbox(_box_x642, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_day_names_min_215, _ctx);
      kk_std_core_types__optional_drop(_match_x874, _ctx);
      _uniq_day_names_min_214 = _uniq_day_names_min_215; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x874, _ctx);
      kk_function_t _brw_x875 = kk_std_time_locale_new_time_locale_es_fun1613(_ctx); /*(2217) -> 2219 2218*/;
      kk_std_core_types__list _brw_x876;
      kk_std_core_types__list _x_x1618 = kk_std_core_types__list_dup(day_names_10051, _ctx); /*list<string>*/
      _brw_x876 = kk_std_core_list_map(_x_x1618, _brw_x875, _ctx); /*list<2218>*/
      kk_function_drop(_brw_x875, _ctx);
      _uniq_day_names_min_214 = _brw_x876; /*list<string>*/
    }
    kk_string_t _x_x1619;
    kk_define_string_literal(, _s_x1620, 2, "es", _ctx)
    _x_x1619 = kk_string_dup(_s_x1620, _ctx); /*string*/
    kk_string_t _x_x1621;
    kk_define_string_literal(, _s_x1622, 4, "H:mm", _ctx)
    _x_x1621 = kk_string_dup(_s_x1622, _ctx); /*string*/
    kk_string_t _x_x1623;
    kk_define_string_literal(, _s_x1624, 7, "H:mm:ss", _ctx)
    _x_x1623 = kk_string_dup(_s_x1624, _ctx); /*string*/
    kk_string_t _x_x1625;
    kk_define_string_literal(, _s_x1626, 10, "DD/MM/YYYY", _ctx)
    _x_x1625 = kk_string_dup(_s_x1626, _ctx); /*string*/
    kk_string_t _x_x1627;
    kk_define_string_literal(, _s_x1628, 21, "D \'de\' MMMM \'de\' YYYY", _ctx)
    _x_x1627 = kk_string_dup(_s_x1628, _ctx); /*string*/
    kk_string_t _x_x1629;
    kk_define_string_literal(, _s_x1630, 26, "D \'de\' MMMM \'de\' YYYY H:mm", _ctx)
    _x_x1629 = kk_string_dup(_s_x1630, _ctx); /*string*/
    kk_string_t _x_x1631;
    kk_define_string_literal(, _s_x1632, 32, "dddd, D \'de\' MMMM \'de\' YYYY H:mm", _ctx)
    _x_x1631 = kk_string_dup(_s_x1632, _ctx); /*string*/
    kk_std_time_locale_time_locale_es = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1619, day_names_10051, month_names_10052, _uniq_month_names_short_92, _uniq_day_names_short_153, _uniq_day_names_min_214, _x_x1621, _x_x1623, _x_x1625, _x_x1627, _x_x1629, _x_x1631, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_string_t _x_x1633;
    kk_define_string_literal(, _s_x1634, 2, "nl", _ctx)
    _x_x1633 = kk_string_dup(_s_x1634, _ctx); /*string*/
    kk_std_core_types__list _x_x1635;
    kk_box_t _x_x1636;
    kk_string_t _x_x1637;
    kk_define_string_literal(, _s_x1638, 7, "maandag", _ctx)
    _x_x1637 = kk_string_dup(_s_x1638, _ctx); /*string*/
    _x_x1636 = kk_string_box(_x_x1637); /*79*/
    kk_std_core_types__list _x_x1639;
    kk_box_t _x_x1640;
    kk_string_t _x_x1641;
    kk_define_string_literal(, _s_x1642, 7, "dinsdag", _ctx)
    _x_x1641 = kk_string_dup(_s_x1642, _ctx); /*string*/
    _x_x1640 = kk_string_box(_x_x1641); /*79*/
    kk_std_core_types__list _x_x1643;
    kk_box_t _x_x1644;
    kk_string_t _x_x1645;
    kk_define_string_literal(, _s_x1646, 8, "woensdag", _ctx)
    _x_x1645 = kk_string_dup(_s_x1646, _ctx); /*string*/
    _x_x1644 = kk_string_box(_x_x1645); /*79*/
    kk_std_core_types__list _x_x1647;
    kk_box_t _x_x1648;
    kk_string_t _x_x1649;
    kk_define_string_literal(, _s_x1650, 9, "donderdag", _ctx)
    _x_x1649 = kk_string_dup(_s_x1650, _ctx); /*string*/
    _x_x1648 = kk_string_box(_x_x1649); /*79*/
    kk_std_core_types__list _x_x1651;
    kk_box_t _x_x1652;
    kk_string_t _x_x1653;
    kk_define_string_literal(, _s_x1654, 7, "vrijdag", _ctx)
    _x_x1653 = kk_string_dup(_s_x1654, _ctx); /*string*/
    _x_x1652 = kk_string_box(_x_x1653); /*79*/
    kk_std_core_types__list _x_x1655;
    kk_box_t _x_x1656;
    kk_string_t _x_x1657;
    kk_define_string_literal(, _s_x1658, 8, "zaterdag", _ctx)
    _x_x1657 = kk_string_dup(_s_x1658, _ctx); /*string*/
    _x_x1656 = kk_string_box(_x_x1657); /*79*/
    kk_std_core_types__list _x_x1659;
    kk_box_t _x_x1660;
    kk_string_t _x_x1661;
    kk_define_string_literal(, _s_x1662, 6, "zondag", _ctx)
    _x_x1661 = kk_string_dup(_s_x1662, _ctx); /*string*/
    _x_x1660 = kk_string_box(_x_x1661); /*79*/
    _x_x1659 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1660, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1655 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1656, _x_x1659, _ctx); /*list<79>*/
    _x_x1651 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1652, _x_x1655, _ctx); /*list<79>*/
    _x_x1647 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1648, _x_x1651, _ctx); /*list<79>*/
    _x_x1643 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1644, _x_x1647, _ctx); /*list<79>*/
    _x_x1639 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1640, _x_x1643, _ctx); /*list<79>*/
    _x_x1635 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1636, _x_x1639, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1663;
    kk_box_t _x_x1664;
    kk_string_t _x_x1665;
    kk_define_string_literal(, _s_x1666, 7, "januari", _ctx)
    _x_x1665 = kk_string_dup(_s_x1666, _ctx); /*string*/
    _x_x1664 = kk_string_box(_x_x1665); /*79*/
    kk_std_core_types__list _x_x1667;
    kk_box_t _x_x1668;
    kk_string_t _x_x1669;
    kk_define_string_literal(, _s_x1670, 8, "februari", _ctx)
    _x_x1669 = kk_string_dup(_s_x1670, _ctx); /*string*/
    _x_x1668 = kk_string_box(_x_x1669); /*79*/
    kk_std_core_types__list _x_x1671;
    kk_box_t _x_x1672;
    kk_string_t _x_x1673;
    kk_define_string_literal(, _s_x1674, 5, "maart", _ctx)
    _x_x1673 = kk_string_dup(_s_x1674, _ctx); /*string*/
    _x_x1672 = kk_string_box(_x_x1673); /*79*/
    kk_std_core_types__list _x_x1675;
    kk_box_t _x_x1676;
    kk_string_t _x_x1677;
    kk_define_string_literal(, _s_x1678, 5, "april", _ctx)
    _x_x1677 = kk_string_dup(_s_x1678, _ctx); /*string*/
    _x_x1676 = kk_string_box(_x_x1677); /*79*/
    kk_std_core_types__list _x_x1679;
    kk_box_t _x_x1680;
    kk_string_t _x_x1681;
    kk_define_string_literal(, _s_x1682, 3, "mei", _ctx)
    _x_x1681 = kk_string_dup(_s_x1682, _ctx); /*string*/
    _x_x1680 = kk_string_box(_x_x1681); /*79*/
    kk_std_core_types__list _x_x1683;
    kk_box_t _x_x1684;
    kk_string_t _x_x1685;
    kk_define_string_literal(, _s_x1686, 4, "juni", _ctx)
    _x_x1685 = kk_string_dup(_s_x1686, _ctx); /*string*/
    _x_x1684 = kk_string_box(_x_x1685); /*79*/
    kk_std_core_types__list _x_x1687;
    kk_box_t _x_x1688;
    kk_string_t _x_x1689;
    kk_define_string_literal(, _s_x1690, 4, "juli", _ctx)
    _x_x1689 = kk_string_dup(_s_x1690, _ctx); /*string*/
    _x_x1688 = kk_string_box(_x_x1689); /*79*/
    kk_std_core_types__list _x_x1691;
    kk_box_t _x_x1692;
    kk_string_t _x_x1693;
    kk_define_string_literal(, _s_x1694, 8, "augustus", _ctx)
    _x_x1693 = kk_string_dup(_s_x1694, _ctx); /*string*/
    _x_x1692 = kk_string_box(_x_x1693); /*79*/
    kk_std_core_types__list _x_x1695;
    kk_box_t _x_x1696;
    kk_string_t _x_x1697;
    kk_define_string_literal(, _s_x1698, 9, "september", _ctx)
    _x_x1697 = kk_string_dup(_s_x1698, _ctx); /*string*/
    _x_x1696 = kk_string_box(_x_x1697); /*79*/
    kk_std_core_types__list _x_x1699;
    kk_box_t _x_x1700;
    kk_string_t _x_x1701;
    kk_define_string_literal(, _s_x1702, 7, "oktober", _ctx)
    _x_x1701 = kk_string_dup(_s_x1702, _ctx); /*string*/
    _x_x1700 = kk_string_box(_x_x1701); /*79*/
    kk_std_core_types__list _x_x1703;
    kk_box_t _x_x1704;
    kk_string_t _x_x1705;
    kk_define_string_literal(, _s_x1706, 8, "november", _ctx)
    _x_x1705 = kk_string_dup(_s_x1706, _ctx); /*string*/
    _x_x1704 = kk_string_box(_x_x1705); /*79*/
    kk_std_core_types__list _x_x1707;
    kk_box_t _x_x1708;
    kk_string_t _x_x1709;
    kk_define_string_literal(, _s_x1710, 8, "december", _ctx)
    _x_x1709 = kk_string_dup(_s_x1710, _ctx); /*string*/
    _x_x1708 = kk_string_box(_x_x1709); /*79*/
    _x_x1707 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1708, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1703 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1704, _x_x1707, _ctx); /*list<79>*/
    _x_x1699 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1700, _x_x1703, _ctx); /*list<79>*/
    _x_x1695 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1696, _x_x1699, _ctx); /*list<79>*/
    _x_x1691 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1692, _x_x1695, _ctx); /*list<79>*/
    _x_x1687 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1688, _x_x1691, _ctx); /*list<79>*/
    _x_x1683 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1684, _x_x1687, _ctx); /*list<79>*/
    _x_x1679 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1680, _x_x1683, _ctx); /*list<79>*/
    _x_x1675 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1676, _x_x1679, _ctx); /*list<79>*/
    _x_x1671 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1672, _x_x1675, _ctx); /*list<79>*/
    _x_x1667 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1668, _x_x1671, _ctx); /*list<79>*/
    _x_x1663 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1664, _x_x1667, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1711;
    kk_box_t _x_x1712;
    kk_string_t _x_x1713;
    kk_define_string_literal(, _s_x1714, 3, "jan", _ctx)
    _x_x1713 = kk_string_dup(_s_x1714, _ctx); /*string*/
    _x_x1712 = kk_string_box(_x_x1713); /*79*/
    kk_std_core_types__list _x_x1715;
    kk_box_t _x_x1716;
    kk_string_t _x_x1717;
    kk_define_string_literal(, _s_x1718, 3, "feb", _ctx)
    _x_x1717 = kk_string_dup(_s_x1718, _ctx); /*string*/
    _x_x1716 = kk_string_box(_x_x1717); /*79*/
    kk_std_core_types__list _x_x1719;
    kk_box_t _x_x1720;
    kk_string_t _x_x1721;
    kk_define_string_literal(, _s_x1722, 3, "mrt", _ctx)
    _x_x1721 = kk_string_dup(_s_x1722, _ctx); /*string*/
    _x_x1720 = kk_string_box(_x_x1721); /*79*/
    kk_std_core_types__list _x_x1723;
    kk_box_t _x_x1724;
    kk_string_t _x_x1725;
    kk_define_string_literal(, _s_x1726, 3, "apr", _ctx)
    _x_x1725 = kk_string_dup(_s_x1726, _ctx); /*string*/
    _x_x1724 = kk_string_box(_x_x1725); /*79*/
    kk_std_core_types__list _x_x1727;
    kk_box_t _x_x1728;
    kk_string_t _x_x1729;
    kk_define_string_literal(, _s_x1730, 3, "mei", _ctx)
    _x_x1729 = kk_string_dup(_s_x1730, _ctx); /*string*/
    _x_x1728 = kk_string_box(_x_x1729); /*79*/
    kk_std_core_types__list _x_x1731;
    kk_box_t _x_x1732;
    kk_string_t _x_x1733;
    kk_define_string_literal(, _s_x1734, 3, "jun", _ctx)
    _x_x1733 = kk_string_dup(_s_x1734, _ctx); /*string*/
    _x_x1732 = kk_string_box(_x_x1733); /*79*/
    kk_std_core_types__list _x_x1735;
    kk_box_t _x_x1736;
    kk_string_t _x_x1737;
    kk_define_string_literal(, _s_x1738, 3, "jul", _ctx)
    _x_x1737 = kk_string_dup(_s_x1738, _ctx); /*string*/
    _x_x1736 = kk_string_box(_x_x1737); /*79*/
    kk_std_core_types__list _x_x1739;
    kk_box_t _x_x1740;
    kk_string_t _x_x1741;
    kk_define_string_literal(, _s_x1742, 3, "aug", _ctx)
    _x_x1741 = kk_string_dup(_s_x1742, _ctx); /*string*/
    _x_x1740 = kk_string_box(_x_x1741); /*79*/
    kk_std_core_types__list _x_x1743;
    kk_box_t _x_x1744;
    kk_string_t _x_x1745;
    kk_define_string_literal(, _s_x1746, 3, "sep", _ctx)
    _x_x1745 = kk_string_dup(_s_x1746, _ctx); /*string*/
    _x_x1744 = kk_string_box(_x_x1745); /*79*/
    kk_std_core_types__list _x_x1747;
    kk_box_t _x_x1748;
    kk_string_t _x_x1749;
    kk_define_string_literal(, _s_x1750, 3, "okt", _ctx)
    _x_x1749 = kk_string_dup(_s_x1750, _ctx); /*string*/
    _x_x1748 = kk_string_box(_x_x1749); /*79*/
    kk_std_core_types__list _x_x1751;
    kk_box_t _x_x1752;
    kk_string_t _x_x1753;
    kk_define_string_literal(, _s_x1754, 3, "nov", _ctx)
    _x_x1753 = kk_string_dup(_s_x1754, _ctx); /*string*/
    _x_x1752 = kk_string_box(_x_x1753); /*79*/
    kk_std_core_types__list _x_x1755;
    kk_box_t _x_x1756;
    kk_string_t _x_x1757;
    kk_define_string_literal(, _s_x1758, 3, "dec", _ctx)
    _x_x1757 = kk_string_dup(_s_x1758, _ctx); /*string*/
    _x_x1756 = kk_string_box(_x_x1757); /*79*/
    _x_x1755 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1756, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1751 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1752, _x_x1755, _ctx); /*list<79>*/
    _x_x1747 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1748, _x_x1751, _ctx); /*list<79>*/
    _x_x1743 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1744, _x_x1747, _ctx); /*list<79>*/
    _x_x1739 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1740, _x_x1743, _ctx); /*list<79>*/
    _x_x1735 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1736, _x_x1739, _ctx); /*list<79>*/
    _x_x1731 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1732, _x_x1735, _ctx); /*list<79>*/
    _x_x1727 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1728, _x_x1731, _ctx); /*list<79>*/
    _x_x1723 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1724, _x_x1727, _ctx); /*list<79>*/
    _x_x1719 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1720, _x_x1723, _ctx); /*list<79>*/
    _x_x1715 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1716, _x_x1719, _ctx); /*list<79>*/
    _x_x1711 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1712, _x_x1715, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1759;
    kk_box_t _x_x1760;
    kk_string_t _x_x1761;
    kk_define_string_literal(, _s_x1762, 3, "ma.", _ctx)
    _x_x1761 = kk_string_dup(_s_x1762, _ctx); /*string*/
    _x_x1760 = kk_string_box(_x_x1761); /*79*/
    kk_std_core_types__list _x_x1763;
    kk_box_t _x_x1764;
    kk_string_t _x_x1765;
    kk_define_string_literal(, _s_x1766, 3, "di.", _ctx)
    _x_x1765 = kk_string_dup(_s_x1766, _ctx); /*string*/
    _x_x1764 = kk_string_box(_x_x1765); /*79*/
    kk_std_core_types__list _x_x1767;
    kk_box_t _x_x1768;
    kk_string_t _x_x1769;
    kk_define_string_literal(, _s_x1770, 3, "wo.", _ctx)
    _x_x1769 = kk_string_dup(_s_x1770, _ctx); /*string*/
    _x_x1768 = kk_string_box(_x_x1769); /*79*/
    kk_std_core_types__list _x_x1771;
    kk_box_t _x_x1772;
    kk_string_t _x_x1773;
    kk_define_string_literal(, _s_x1774, 3, "do.", _ctx)
    _x_x1773 = kk_string_dup(_s_x1774, _ctx); /*string*/
    _x_x1772 = kk_string_box(_x_x1773); /*79*/
    kk_std_core_types__list _x_x1775;
    kk_box_t _x_x1776;
    kk_string_t _x_x1777;
    kk_define_string_literal(, _s_x1778, 3, "vr.", _ctx)
    _x_x1777 = kk_string_dup(_s_x1778, _ctx); /*string*/
    _x_x1776 = kk_string_box(_x_x1777); /*79*/
    kk_std_core_types__list _x_x1779;
    kk_box_t _x_x1780;
    kk_string_t _x_x1781;
    kk_define_string_literal(, _s_x1782, 3, "za.", _ctx)
    _x_x1781 = kk_string_dup(_s_x1782, _ctx); /*string*/
    _x_x1780 = kk_string_box(_x_x1781); /*79*/
    kk_std_core_types__list _x_x1783;
    kk_box_t _x_x1784;
    kk_string_t _x_x1785;
    kk_define_string_literal(, _s_x1786, 3, "zo.", _ctx)
    _x_x1785 = kk_string_dup(_s_x1786, _ctx); /*string*/
    _x_x1784 = kk_string_box(_x_x1785); /*79*/
    _x_x1783 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1784, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1779 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1780, _x_x1783, _ctx); /*list<79>*/
    _x_x1775 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1776, _x_x1779, _ctx); /*list<79>*/
    _x_x1771 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1772, _x_x1775, _ctx); /*list<79>*/
    _x_x1767 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1768, _x_x1771, _ctx); /*list<79>*/
    _x_x1763 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1764, _x_x1767, _ctx); /*list<79>*/
    _x_x1759 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1760, _x_x1763, _ctx); /*list<79>*/
    kk_std_core_types__list _x_x1787;
    kk_box_t _x_x1788;
    kk_string_t _x_x1789;
    kk_define_string_literal(, _s_x1790, 2, "Ma", _ctx)
    _x_x1789 = kk_string_dup(_s_x1790, _ctx); /*string*/
    _x_x1788 = kk_string_box(_x_x1789); /*79*/
    kk_std_core_types__list _x_x1791;
    kk_box_t _x_x1792;
    kk_string_t _x_x1793;
    kk_define_string_literal(, _s_x1794, 2, "Di", _ctx)
    _x_x1793 = kk_string_dup(_s_x1794, _ctx); /*string*/
    _x_x1792 = kk_string_box(_x_x1793); /*79*/
    kk_std_core_types__list _x_x1795;
    kk_box_t _x_x1796;
    kk_string_t _x_x1797;
    kk_define_string_literal(, _s_x1798, 2, "Wo", _ctx)
    _x_x1797 = kk_string_dup(_s_x1798, _ctx); /*string*/
    _x_x1796 = kk_string_box(_x_x1797); /*79*/
    kk_std_core_types__list _x_x1799;
    kk_box_t _x_x1800;
    kk_string_t _x_x1801;
    kk_define_string_literal(, _s_x1802, 2, "Do", _ctx)
    _x_x1801 = kk_string_dup(_s_x1802, _ctx); /*string*/
    _x_x1800 = kk_string_box(_x_x1801); /*79*/
    kk_std_core_types__list _x_x1803;
    kk_box_t _x_x1804;
    kk_string_t _x_x1805;
    kk_define_string_literal(, _s_x1806, 2, "Vr", _ctx)
    _x_x1805 = kk_string_dup(_s_x1806, _ctx); /*string*/
    _x_x1804 = kk_string_box(_x_x1805); /*79*/
    kk_std_core_types__list _x_x1807;
    kk_box_t _x_x1808;
    kk_string_t _x_x1809;
    kk_define_string_literal(, _s_x1810, 2, "Za", _ctx)
    _x_x1809 = kk_string_dup(_s_x1810, _ctx); /*string*/
    _x_x1808 = kk_string_box(_x_x1809); /*79*/
    kk_std_core_types__list _x_x1811;
    kk_box_t _x_x1812;
    kk_string_t _x_x1813;
    kk_define_string_literal(, _s_x1814, 2, "Zo", _ctx)
    _x_x1813 = kk_string_dup(_s_x1814, _ctx); /*string*/
    _x_x1812 = kk_string_box(_x_x1813); /*79*/
    _x_x1811 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1812, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1807 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1808, _x_x1811, _ctx); /*list<79>*/
    _x_x1803 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1804, _x_x1807, _ctx); /*list<79>*/
    _x_x1799 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1800, _x_x1803, _ctx); /*list<79>*/
    _x_x1795 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1796, _x_x1799, _ctx); /*list<79>*/
    _x_x1791 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1792, _x_x1795, _ctx); /*list<79>*/
    _x_x1787 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1788, _x_x1791, _ctx); /*list<79>*/
    kk_string_t _x_x1815;
    kk_std_core_types__optional _match_x873 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x873, _ctx)) {
      kk_box_t _box_x741 = _match_x873._cons._Optional.value;
      kk_string_t _uniq_format_t_219 = kk_string_unbox(_box_x741);
      kk_string_dup(_uniq_format_t_219, _ctx);
      kk_std_core_types__optional_drop(_match_x873, _ctx);
      _x_x1815 = _uniq_format_t_219; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x873, _ctx);
      kk_define_string_literal(, _s_x1816, 5, "HH:mm", _ctx)
      _x_x1815 = kk_string_dup(_s_x1816, _ctx); /*string*/
    }
    kk_string_t _x_x1817;
    kk_std_core_types__optional _match_x872 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x872, _ctx)) {
      kk_box_t _box_x742 = _match_x872._cons._Optional.value;
      kk_string_t _uniq_format_tt_223 = kk_string_unbox(_box_x742);
      kk_string_dup(_uniq_format_tt_223, _ctx);
      kk_std_core_types__optional_drop(_match_x872, _ctx);
      _x_x1817 = _uniq_format_tt_223; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x872, _ctx);
      kk_define_string_literal(, _s_x1818, 8, "HH:mm:ss", _ctx)
      _x_x1817 = kk_string_dup(_s_x1818, _ctx); /*string*/
    }
    kk_string_t _x_x1819;
    kk_define_string_literal(, _s_x1820, 10, "DD-MM-YYYY", _ctx)
    _x_x1819 = kk_string_dup(_s_x1820, _ctx); /*string*/
    kk_string_t _x_x1821;
    kk_std_core_types__optional _match_x871 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x871, _ctx)) {
      kk_box_t _box_x743 = _match_x871._cons._Optional.value;
      kk_string_t _uniq_format_ll_231 = kk_string_unbox(_box_x743);
      kk_string_dup(_uniq_format_ll_231, _ctx);
      kk_std_core_types__optional_drop(_match_x871, _ctx);
      _x_x1821 = _uniq_format_ll_231; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x871, _ctx);
      kk_define_string_literal(, _s_x1822, 11, "D MMMM YYYY", _ctx)
      _x_x1821 = kk_string_dup(_s_x1822, _ctx); /*string*/
    }
    kk_string_t _x_x1823;
    kk_std_core_types__optional _match_x870 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x870, _ctx)) {
      kk_box_t _box_x744 = _match_x870._cons._Optional.value;
      kk_string_t _uniq_format_lll_235 = kk_string_unbox(_box_x744);
      kk_string_dup(_uniq_format_lll_235, _ctx);
      kk_std_core_types__optional_drop(_match_x870, _ctx);
      _x_x1823 = _uniq_format_lll_235; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x870, _ctx);
      kk_define_string_literal(, _s_x1824, 13, "D MMMM YYYY t", _ctx)
      _x_x1823 = kk_string_dup(_s_x1824, _ctx); /*string*/
    }
    kk_string_t _x_x1825;
    kk_std_core_types__optional _match_x869 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x869, _ctx)) {
      kk_box_t _box_x745 = _match_x869._cons._Optional.value;
      kk_string_t _uniq_format_llll_239 = kk_string_unbox(_box_x745);
      kk_string_dup(_uniq_format_llll_239, _ctx);
      kk_std_core_types__optional_drop(_match_x869, _ctx);
      _x_x1825 = _uniq_format_llll_239; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x869, _ctx);
      kk_define_string_literal(, _s_x1826, 18, "dddd D MMMM YYYY t", _ctx)
      _x_x1825 = kk_string_dup(_s_x1826, _ctx); /*string*/
    }
    kk_std_time_locale_time_locale_nl = kk_std_time_locale__new_Time_locale(kk_reuse_null, 0, _x_x1633, _x_x1635, _x_x1663, _x_x1711, _x_x1759, _x_x1787, _x_x1815, _x_x1817, _x_x1819, _x_x1821, _x_x1823, _x_x1825, _ctx); /*std/time/locale/time-locale*/
  }
  {
    kk_box_t _x_x1827;
    kk_std_time_locale__time_locale _x_x1828 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en_iso, _ctx); /*std/time/locale/time-locale*/
    _x_x1827 = kk_std_time_locale__time_locale_box(_x_x1828, _ctx); /*79*/
    kk_std_core_types__list _x_x1829;
    kk_box_t _x_x1830;
    kk_std_time_locale__time_locale _x_x1831 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_de, _ctx); /*std/time/locale/time-locale*/
    _x_x1830 = kk_std_time_locale__time_locale_box(_x_x1831, _ctx); /*79*/
    kk_std_core_types__list _x_x1832;
    kk_box_t _x_x1833;
    kk_std_time_locale__time_locale _x_x1834 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_en, _ctx); /*std/time/locale/time-locale*/
    _x_x1833 = kk_std_time_locale__time_locale_box(_x_x1834, _ctx); /*79*/
    kk_std_core_types__list _x_x1835;
    kk_box_t _x_x1836;
    kk_std_time_locale__time_locale _x_x1837 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_es, _ctx); /*std/time/locale/time-locale*/
    _x_x1836 = kk_std_time_locale__time_locale_box(_x_x1837, _ctx); /*79*/
    kk_std_core_types__list _x_x1838;
    kk_box_t _x_x1839;
    kk_std_time_locale__time_locale _x_x1840 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_fr, _ctx); /*std/time/locale/time-locale*/
    _x_x1839 = kk_std_time_locale__time_locale_box(_x_x1840, _ctx); /*79*/
    kk_std_core_types__list _x_x1841;
    kk_box_t _x_x1842;
    kk_std_time_locale__time_locale _x_x1843 = kk_std_time_locale__time_locale_dup(kk_std_time_locale_time_locale_nl, _ctx); /*std/time/locale/time-locale*/
    _x_x1842 = kk_std_time_locale__time_locale_box(_x_x1843, _ctx); /*79*/
    _x_x1841 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1842, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<79>*/
    _x_x1838 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1839, _x_x1841, _ctx); /*list<79>*/
    _x_x1835 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1836, _x_x1838, _ctx); /*list<79>*/
    _x_x1832 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1833, _x_x1835, _ctx); /*list<79>*/
    _x_x1829 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1830, _x_x1832, _ctx); /*list<79>*/
    kk_std_time_locale_locales = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1827, _x_x1829, _ctx); /*list<std/time/locale/time-locale>*/
  }
}

// termination
void kk_std_time_locale__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__list_drop(kk_std_time_locale_locales, _ctx);
  kk_std_time_locale__time_locale_drop(kk_std_time_locale_time_locale_nl, _ctx);
  kk_std_time_locale__time_locale_drop(kk_std_time_locale_time_locale_es, _ctx);
  kk_std_time_locale__time_locale_drop(kk_std_time_locale_time_locale_de, _ctx);
  kk_std_time_locale__time_locale_drop(kk_std_time_locale_time_locale_fr, _ctx);
  kk_std_time_locale__time_locale_drop(kk_std_time_locale_time_locale_en_iso, _ctx);
  kk_std_time_locale__time_locale_drop(kk_std_time_locale_time_locale_en, _ctx);
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
