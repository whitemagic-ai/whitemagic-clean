// Koka generated module: std/time/time, koka version: 3.2.2, platform: 64-bit
#include "std_time_time.h"

kk_std_time_time__time kk_std_time_time_time_fs__copy(kk_std_time_time__time _this, kk_std_core_types__optional date, kk_std_core_types__optional clock, kk_std_core_types__optional calendar, kk_std_core_types__optional tzdelta, kk_std_core_types__optional tzabbrv, kk_std_core_types__optional timezone, kk_std_core_types__optional instant, kk_context_t* _ctx) { /* (time, date : ? std/time/date/date, clock : ? std/time/date/clock, calendar : ? std/time/calendar/calendar, tzdelta : ? std/time/duration/duration, tzabbrv : ? string, timezone : ? std/time/calendar/timezone, instant : ? std/time/instant/instant) -> time */ 
  kk_std_time_date__date _x_x1074;
  if (kk_std_core_types__is_Optional(date, _ctx)) {
    kk_box_t _box_x3 = date._cons._Optional.value;
    kk_std_time_date__date _uniq_date_286 = kk_std_time_date__date_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_time_date__date_dup(_uniq_date_286, _ctx);
    kk_std_core_types__optional_drop(date, _ctx);
    _x_x1074 = _uniq_date_286; /*std/time/date/date*/
  }
  else {
    kk_std_core_types__optional_drop(date, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1075 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _x = _con_x1075->date;
      kk_std_time_date__clock _pat_3 = _con_x1075->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x1075->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x1075->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x1075->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1075->instant;
      struct kk_std_time_date_Clock* _con_x1076 = kk_std_time_date__as_Clock(_pat_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1077 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1078 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_date__date_dup(_x, _ctx);
      _x_x1074 = _x; /*std/time/date/date*/
    }
  }
  kk_std_time_date__clock _x_x1079;
  if (kk_std_core_types__is_Optional(clock, _ctx)) {
    kk_box_t _box_x4 = clock._cons._Optional.value;
    kk_std_time_date__clock _uniq_clock_294 = kk_std_time_date__clock_unbox(_box_x4, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_clock_294, _ctx);
    kk_std_core_types__optional_drop(clock, _ctx);
    _x_x1079 = _uniq_clock_294; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(clock, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1080 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _pat_0_1 = _con_x1080->date;
      kk_std_time_date__clock _x_0 = _con_x1080->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x1080->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1080->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1080->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1080->instant;
      struct kk_std_time_date_Clock* _con_x1081 = kk_std_time_date__as_Clock(_x_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1082 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1083 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__clock_dup(_x_0, _ctx);
      _x_x1079 = _x_0; /*std/time/date/clock*/
    }
  }
  kk_std_time_calendar__calendar _x_x1084;
  if (kk_std_core_types__is_Optional(calendar, _ctx)) {
    kk_box_t _box_x5 = calendar._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_calendar_302 = kk_std_time_calendar__calendar_unbox(_box_x5, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_calendar_302, _ctx);
    kk_std_core_types__optional_drop(calendar, _ctx);
    _x_x1084 = _uniq_calendar_302; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(calendar, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1085 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _pat_0_2 = _con_x1085->date;
      kk_std_time_date__clock _pat_4_2 = _con_x1085->clock;
      kk_std_time_calendar__calendar _x_1 = _con_x1085->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x1085->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x1085->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x1085->instant;
      struct kk_std_time_date_Clock* _con_x1086 = kk_std_time_date__as_Clock(_pat_4_2, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1087 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1088 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_calendar__calendar_dup(_x_1, _ctx);
      _x_x1084 = _x_1; /*std/time/calendar/calendar*/
    }
  }
  kk_std_time_duration__duration _x_x1089;
  if (kk_std_core_types__is_Optional(tzdelta, _ctx)) {
    kk_box_t _box_x6 = tzdelta._cons._Optional.value;
    kk_std_time_duration__duration _uniq_tzdelta_310 = kk_std_time_duration__duration_unbox(_box_x6, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(tzdelta, _ctx);
    _x_x1089 = _uniq_tzdelta_310; /*std/time/duration/duration*/
  }
  else {
    kk_std_core_types__optional_drop(tzdelta, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1090 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x1090->date;
      kk_std_time_date__clock _pat_4_3 = _con_x1090->clock;
      kk_std_time_calendar__calendar _pat_8_2 = _con_x1090->calendar;
      kk_std_time_duration__duration _x_2 = _con_x1090->tzdelta;
      kk_std_time_calendar__timezone _pat_19_2 = _con_x1090->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x1090->instant;
      struct kk_std_time_date_Clock* _con_x1091 = kk_std_time_date__as_Clock(_pat_4_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1092 = kk_std_time_calendar__as_Calendar(_pat_8_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1093 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
      _x_x1089 = _x_2; /*std/time/duration/duration*/
    }
  }
  kk_string_t _x_x1094;
  if (kk_std_core_types__is_Optional(tzabbrv, _ctx)) {
    kk_box_t _box_x7 = tzabbrv._cons._Optional.value;
    kk_string_t _uniq_tzabbrv_318 = kk_string_unbox(_box_x7);
    kk_string_dup(_uniq_tzabbrv_318, _ctx);
    kk_std_core_types__optional_drop(tzabbrv, _ctx);
    _x_x1094 = _uniq_tzabbrv_318; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(tzabbrv, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1095 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _pat_0_4 = _con_x1095->date;
      kk_std_time_date__clock _pat_4_4 = _con_x1095->clock;
      kk_std_time_calendar__calendar _pat_8_4 = _con_x1095->calendar;
      kk_std_time_duration__duration _pat_17_3 = _con_x1095->tzdelta;
      kk_std_time_calendar__timezone _pat_19_3 = _con_x1095->timezone;
      kk_std_time_instant__instant _pat_23_3 = _con_x1095->instant;
      struct kk_std_time_date_Clock* _con_x1096 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1097 = kk_std_time_calendar__as_Calendar(_pat_8_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1098 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
      kk_string_t _x_3 = _con_x1095->tzabbrv;
      kk_string_dup(_x_3, _ctx);
      _x_x1094 = _x_3; /*string*/
    }
  }
  kk_std_time_calendar__timezone _x_x1099;
  if (kk_std_core_types__is_Optional(timezone, _ctx)) {
    kk_box_t _box_x8 = timezone._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_timezone_326 = kk_std_time_calendar__timezone_unbox(_box_x8, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_timezone_326, _ctx);
    kk_std_core_types__optional_drop(timezone, _ctx);
    _x_x1099 = _uniq_timezone_326; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(timezone, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1100 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _pat_0_5 = _con_x1100->date;
      kk_std_time_date__clock _pat_4_5 = _con_x1100->clock;
      kk_std_time_calendar__calendar _pat_8_5 = _con_x1100->calendar;
      kk_std_time_duration__duration _pat_17_4 = _con_x1100->tzdelta;
      kk_std_time_calendar__timezone _x_4 = _con_x1100->timezone;
      kk_std_time_instant__instant _pat_23_4 = _con_x1100->instant;
      struct kk_std_time_date_Clock* _con_x1101 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1102 = kk_std_time_calendar__as_Calendar(_pat_8_5, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1103 = kk_std_time_calendar__as_Timezone(_x_4, _ctx);
      kk_std_time_calendar__timezone_dup(_x_4, _ctx);
      _x_x1099 = _x_4; /*std/time/calendar/timezone*/
    }
  }
  kk_std_time_instant__instant _x_x1104;
  if (kk_std_core_types__is_Optional(instant, _ctx)) {
    kk_box_t _box_x9 = instant._cons._Optional.value;
    kk_std_time_instant__instant _uniq_instant_334 = kk_std_time_instant__instant_unbox(_box_x9, KK_BORROWED, _ctx);
    kk_std_time_instant__instant_dup(_uniq_instant_334, _ctx);
    kk_std_core_types__optional_drop(instant, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(9)), _ctx);
    _x_x1104 = _uniq_instant_334; /*std/time/instant/instant*/
  }
  else {
    kk_std_core_types__optional_drop(instant, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1105 = kk_std_time_time__as_Time(_this, _ctx);
      kk_std_time_date__date _pat_0_6 = _con_x1105->date;
      kk_std_time_date__clock _pat_4_6 = _con_x1105->clock;
      kk_std_time_calendar__calendar _pat_8_6 = _con_x1105->calendar;
      kk_std_time_duration__duration _pat_17_5 = _con_x1105->tzdelta;
      kk_std_time_calendar__timezone _pat_20_5 = _con_x1105->timezone;
      kk_std_time_instant__instant _x_5 = _con_x1105->instant;
      struct kk_std_time_date_Clock* _con_x1106 = kk_std_time_date__as_Clock(_pat_4_6, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1107 = kk_std_time_calendar__as_Calendar(_pat_8_6, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1108 = kk_std_time_calendar__as_Timezone(_pat_20_5, _ctx);
      kk_string_t _pat_19_5 = _con_x1105->tzabbrv;
      kk_integer_t _pat_5_6 = _con_x1106->hours;
      kk_integer_t _pat_6_6 = _con_x1106->minutes;
      kk_string_t _pat_9_6 = _con_x1107->name;
      kk_string_t _pat_10_6 = _con_x1107->long_name;
      kk_string_t _pat_11_6 = _con_x1107->month_prefix;
      kk_function_t _pat_12_6 = _con_x1107->show_era;
      kk_function_t _pat_13_5 = _con_x1107->instant_to_dc;
      kk_function_t _pat_14_5 = _con_x1107->dc_to_instant;
      kk_function_t _pat_15_5 = _con_x1107->days_to_date;
      kk_function_t _pat_16_5 = _con_x1107->date_to_days;
      kk_string_t _pat_21_5 = _con_x1108->name;
      kk_function_t _pat_22_5 = _con_x1108->utc_delta;
      kk_function_t _pat_23_5 = _con_x1108->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_8_6, _ctx)) {
          kk_string_drop(_pat_9_6, _ctx);
          kk_function_drop(_pat_16_5, _ctx);
          kk_function_drop(_pat_15_5, _ctx);
          kk_function_drop(_pat_14_5, _ctx);
          kk_function_drop(_pat_13_5, _ctx);
          kk_function_drop(_pat_12_6, _ctx);
          kk_string_drop(_pat_11_6, _ctx);
          kk_string_drop(_pat_10_6, _ctx);
          kk_datatype_ptr_free(_pat_8_6, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_8_6, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_6, _ctx)) {
          kk_integer_drop(_pat_6_6, _ctx);
          kk_integer_drop(_pat_5_6, _ctx);
          kk_datatype_ptr_free(_pat_4_6, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_6, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_20_5, _ctx)) {
          kk_function_drop(_pat_23_5, _ctx);
          kk_function_drop(_pat_22_5, _ctx);
          kk_string_drop(_pat_21_5, _ctx);
          kk_datatype_ptr_free(_pat_20_5, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_20_5, _ctx);
        }
        kk_string_drop(_pat_19_5, _ctx);
        kk_std_time_date__date_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_time_instant__instant_dup(_x_5, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x1104 = _x_5; /*std/time/instant/instant*/
    }
  }
  return kk_std_time_time__new_Time(kk_reuse_null, 0, _x_x1074, _x_x1079, _x_x1084, _x_x1089, _x_x1094, _x_x1099, _x_x1104, _ctx);
}
 
// The `:timescale` of the time.

kk_std_time_instant__timescale kk_std_time_time_timescale(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> std/time/instant/timescale */ 
  {
    struct kk_std_time_time_Time* _con_x1109 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1109->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1109->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1109->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1109->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1109->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1109->instant;
    struct kk_std_time_date_Clock* _con_x1110 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1111 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1112 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1109->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1110->hours;
    kk_integer_t _pat_6_0 = _con_x1110->minutes;
    kk_string_t _pat_9_0 = _con_x1111->name;
    kk_string_t _pat_10_0 = _con_x1111->long_name;
    kk_string_t _pat_11 = _con_x1111->month_prefix;
    kk_function_t _pat_12 = _con_x1111->show_era;
    kk_function_t _pat_13 = _con_x1111->instant_to_dc;
    kk_function_t _pat_14 = _con_x1111->dc_to_instant;
    kk_function_t _pat_15 = _con_x1111->days_to_date;
    kk_function_t _pat_16 = _con_x1111->date_to_days;
    kk_string_t _pat_21 = _con_x1112->name;
    kk_function_t _pat_22 = _con_x1112->utc_delta;
    kk_function_t _pat_23 = _con_x1112->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16, _ctx);
        kk_function_drop(_pat_15, _ctx);
        kk_function_drop(_pat_14, _ctx);
        kk_function_drop(_pat_13, _ctx);
        kk_function_drop(_pat_12, _ctx);
        kk_string_drop(_pat_11, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
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
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_std_time_timestamp__timestamp _pat_0 = _x_0.since;
      kk_std_time_instant__timescale _x = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1113 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1114 = kk_std_time_instant__as_Timescale(_x, _ctx);
      kk_std_time_instant__timescale_dup(_x, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      return _x;
    }
  }
}
 
// Return the year of a `:time`.

kk_integer_t kk_std_time_time_year(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  {
    struct kk_std_time_time_Time* _con_x1115 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x1115->date;
    kk_std_time_date__clock _pat_3 = _con_x1115->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1115->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1115->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1115->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1115->instant;
    struct kk_std_time_date_Clock* _con_x1116 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1117 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1118 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1115->tzabbrv;
    kk_integer_t _pat_4 = _con_x1116->hours;
    kk_integer_t _pat_5 = _con_x1116->minutes;
    kk_string_t _pat_8 = _con_x1117->name;
    kk_string_t _pat_9 = _con_x1117->long_name;
    kk_string_t _pat_10 = _con_x1117->month_prefix;
    kk_function_t _pat_11 = _con_x1117->show_era;
    kk_function_t _pat_12 = _con_x1117->instant_to_dc;
    kk_function_t _pat_13 = _con_x1117->dc_to_instant;
    kk_function_t _pat_14 = _con_x1117->days_to_date;
    kk_function_t _pat_15 = _con_x1117->date_to_days;
    kk_string_t _pat_20 = _con_x1118->name;
    kk_function_t _pat_21 = _con_x1118->utc_delta;
    kk_function_t _pat_22 = _con_x1118->utc_inverse;
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
      return _x;
    }
  }
}
 
// Return the month of a `:time`. (starting at 1)

kk_integer_t kk_std_time_time_month(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  {
    struct kk_std_time_time_Time* _con_x1119 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x1119->date;
    kk_std_time_date__clock _pat_3 = _con_x1119->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1119->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1119->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1119->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1119->instant;
    struct kk_std_time_date_Clock* _con_x1120 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1121 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1122 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1119->tzabbrv;
    kk_integer_t _pat_4 = _con_x1120->hours;
    kk_integer_t _pat_5 = _con_x1120->minutes;
    kk_string_t _pat_8 = _con_x1121->name;
    kk_string_t _pat_9 = _con_x1121->long_name;
    kk_string_t _pat_10 = _con_x1121->month_prefix;
    kk_function_t _pat_11 = _con_x1121->show_era;
    kk_function_t _pat_12 = _con_x1121->instant_to_dc;
    kk_function_t _pat_13 = _con_x1121->dc_to_instant;
    kk_function_t _pat_14 = _con_x1121->days_to_date;
    kk_function_t _pat_15 = _con_x1121->date_to_days;
    kk_string_t _pat_20 = _con_x1122->name;
    kk_function_t _pat_21 = _con_x1122->utc_delta;
    kk_function_t _pat_22 = _con_x1122->utc_inverse;
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
      kk_integer_t _x = _x_0.month;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      return _x;
    }
  }
}
 
// Return the day of the month of a `:time`. (starting at 1)

kk_integer_t kk_std_time_time_day(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  {
    struct kk_std_time_time_Time* _con_x1123 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x1123->date;
    kk_std_time_date__clock _pat_3 = _con_x1123->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1123->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1123->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1123->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1123->instant;
    struct kk_std_time_date_Clock* _con_x1124 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1125 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1126 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1123->tzabbrv;
    kk_integer_t _pat_4 = _con_x1124->hours;
    kk_integer_t _pat_5 = _con_x1124->minutes;
    kk_string_t _pat_8 = _con_x1125->name;
    kk_string_t _pat_9 = _con_x1125->long_name;
    kk_string_t _pat_10 = _con_x1125->month_prefix;
    kk_function_t _pat_11 = _con_x1125->show_era;
    kk_function_t _pat_12 = _con_x1125->instant_to_dc;
    kk_function_t _pat_13 = _con_x1125->dc_to_instant;
    kk_function_t _pat_14 = _con_x1125->days_to_date;
    kk_function_t _pat_15 = _con_x1125->date_to_days;
    kk_string_t _pat_20 = _con_x1126->name;
    kk_function_t _pat_21 = _con_x1126->utc_delta;
    kk_function_t _pat_22 = _con_x1126->utc_inverse;
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
      kk_integer_t _x = _x_0.day;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      return _x;
    }
  }
}
 
// Return the whole hours of a `:time`.

kk_integer_t kk_std_time_time_hours(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  {
    struct kk_std_time_time_Time* _con_x1127 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1127->date;
    kk_std_time_date__clock _x_0 = _con_x1127->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1127->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1127->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1127->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1127->instant;
    struct kk_std_time_date_Clock* _con_x1128 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1129 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1130 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1127->tzabbrv;
    kk_string_t _pat_8 = _con_x1129->name;
    kk_string_t _pat_9 = _con_x1129->long_name;
    kk_string_t _pat_10 = _con_x1129->month_prefix;
    kk_function_t _pat_11 = _con_x1129->show_era;
    kk_function_t _pat_12 = _con_x1129->instant_to_dc;
    kk_function_t _pat_13 = _con_x1129->dc_to_instant;
    kk_function_t _pat_14 = _con_x1129->days_to_date;
    kk_function_t _pat_15 = _con_x1129->date_to_days;
    kk_string_t _pat_20 = _con_x1130->name;
    kk_function_t _pat_21 = _con_x1130->utc_delta;
    kk_function_t _pat_22 = _con_x1130->utc_inverse;
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
      struct kk_std_time_date_Clock* _con_x1131 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1 = _con_x1131->seconds;
      kk_integer_t _x = _con_x1131->hours;
      kk_integer_t _pat_0 = _con_x1131->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      return _x;
    }
  }
}
 
// Return the whole minutes of a `:time`.

kk_integer_t kk_std_time_time_minutes(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  {
    struct kk_std_time_time_Time* _con_x1132 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1132->date;
    kk_std_time_date__clock _x_0 = _con_x1132->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1132->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1132->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1132->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1132->instant;
    struct kk_std_time_date_Clock* _con_x1133 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1134 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1135 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1132->tzabbrv;
    kk_string_t _pat_8 = _con_x1134->name;
    kk_string_t _pat_9 = _con_x1134->long_name;
    kk_string_t _pat_10 = _con_x1134->month_prefix;
    kk_function_t _pat_11 = _con_x1134->show_era;
    kk_function_t _pat_12 = _con_x1134->instant_to_dc;
    kk_function_t _pat_13 = _con_x1134->dc_to_instant;
    kk_function_t _pat_14 = _con_x1134->days_to_date;
    kk_function_t _pat_15 = _con_x1134->date_to_days;
    kk_string_t _pat_20 = _con_x1135->name;
    kk_function_t _pat_21 = _con_x1135->utc_delta;
    kk_function_t _pat_22 = _con_x1135->utc_inverse;
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
      struct kk_std_time_date_Clock* _con_x1136 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1 = _con_x1136->seconds;
      kk_integer_t _pat_0 = _con_x1136->hours;
      kk_integer_t _x = _con_x1136->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_integer_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      return _x;
    }
  }
}
 
// Return the fractional seconds of a `:time`.

kk_std_num_ddouble__ddouble kk_std_time_time_seconds(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> std/time/timestamp/timespan */ 
  {
    struct kk_std_time_time_Time* _con_x1137 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1137->date;
    kk_std_time_date__clock _x_0 = _con_x1137->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x1137->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x1137->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x1137->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x1137->instant;
    struct kk_std_time_date_Clock* _con_x1138 = kk_std_time_date__as_Clock(_x_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1139 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1140 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x1137->tzabbrv;
    kk_string_t _pat_8 = _con_x1139->name;
    kk_string_t _pat_9 = _con_x1139->long_name;
    kk_string_t _pat_10 = _con_x1139->month_prefix;
    kk_function_t _pat_11 = _con_x1139->show_era;
    kk_function_t _pat_12 = _con_x1139->instant_to_dc;
    kk_function_t _pat_13 = _con_x1139->dc_to_instant;
    kk_function_t _pat_14 = _con_x1139->days_to_date;
    kk_function_t _pat_15 = _con_x1139->date_to_days;
    kk_string_t _pat_20 = _con_x1140->name;
    kk_function_t _pat_21 = _con_x1140->utc_delta;
    kk_function_t _pat_22 = _con_x1140->utc_inverse;
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
      struct kk_std_time_date_Clock* _con_x1141 = kk_std_time_date__as_Clock(_x_0, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1141->seconds;
      kk_integer_t _pat_0 = _con_x1141->hours;
      kk_integer_t _pat_1 = _con_x1141->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_integer_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      return _x;
    }
  }
}
 
// Compare two `:time`s. Compares the actual instants in time
// and can thus compare across calendars and timezones.
// `time(2001,7,2,tz=tz-fixed("GMT+1",duration(3600))) > time(2001,7,1,23,30,0)` &quad; (`False`!)

kk_std_core_types__order kk_std_time_time_cmp(kk_std_time_time__time t1, kk_std_time_time__time t2, kk_context_t* _ctx) { /* (t1 : time, t2 : time) -> order */ 
  kk_std_time_instant__instant _x_x1142;
  {
    struct kk_std_time_time_Time* _con_x1143 = kk_std_time_time__as_Time(t1, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1143->date;
    kk_std_time_date__clock _pat_4 = _con_x1143->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1143->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1143->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1143->timezone;
    kk_std_time_instant__instant _x = _con_x1143->instant;
    struct kk_std_time_date_Clock* _con_x1144 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1145 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1146 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1143->tzabbrv;
    kk_integer_t _pat_5 = _con_x1144->hours;
    kk_integer_t _pat_6 = _con_x1144->minutes;
    kk_string_t _pat_9 = _con_x1145->name;
    kk_string_t _pat_10 = _con_x1145->long_name;
    kk_string_t _pat_11 = _con_x1145->month_prefix;
    kk_function_t _pat_12 = _con_x1145->show_era;
    kk_function_t _pat_13 = _con_x1145->instant_to_dc;
    kk_function_t _pat_14 = _con_x1145->dc_to_instant;
    kk_function_t _pat_15 = _con_x1145->days_to_date;
    kk_function_t _pat_16 = _con_x1145->date_to_days;
    kk_string_t _pat_21 = _con_x1146->name;
    kk_function_t _pat_22 = _con_x1146->utc_delta;
    kk_function_t _pat_23 = _con_x1146->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t1, _ctx)) {
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
      kk_datatype_ptr_free(t1, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(t1, _ctx);
    }
    _x_x1142 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1147;
  {
    struct kk_std_time_time_Time* _con_x1148 = kk_std_time_time__as_Time(t2, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1148->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1148->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1148->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1148->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1148->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1148->instant;
    struct kk_std_time_date_Clock* _con_x1149 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1150 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1151 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1148->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1149->hours;
    kk_integer_t _pat_6_0 = _con_x1149->minutes;
    kk_string_t _pat_9_0 = _con_x1150->name;
    kk_string_t _pat_10_0 = _con_x1150->long_name;
    kk_string_t _pat_11_0 = _con_x1150->month_prefix;
    kk_function_t _pat_12_0 = _con_x1150->show_era;
    kk_function_t _pat_13_0 = _con_x1150->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1150->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1150->days_to_date;
    kk_function_t _pat_16_0 = _con_x1150->date_to_days;
    kk_string_t _pat_21_0 = _con_x1151->name;
    kk_function_t _pat_22_0 = _con_x1151->utc_delta;
    kk_function_t _pat_23_0 = _con_x1151->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t2, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t2, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t2, _ctx);
    }
    _x_x1147 = _x_0; /*std/time/instant/instant*/
  }
  return kk_std_time_instant_cmp(_x_x1142, _x_x1147, _ctx);
}

bool kk_std_time_time__lp__eq__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> bool */ 
  kk_std_core_types__order _x_x1152;
  kk_std_time_instant__instant _x_x1153;
  {
    struct kk_std_time_time_Time* _con_x1154 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1154->date;
    kk_std_time_date__clock _pat_4 = _con_x1154->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1154->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1154->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1154->timezone;
    kk_std_time_instant__instant _x = _con_x1154->instant;
    struct kk_std_time_date_Clock* _con_x1155 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1156 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1157 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1154->tzabbrv;
    kk_integer_t _pat_5 = _con_x1155->hours;
    kk_integer_t _pat_6 = _con_x1155->minutes;
    kk_string_t _pat_9 = _con_x1156->name;
    kk_string_t _pat_10 = _con_x1156->long_name;
    kk_string_t _pat_11 = _con_x1156->month_prefix;
    kk_function_t _pat_12 = _con_x1156->show_era;
    kk_function_t _pat_13 = _con_x1156->instant_to_dc;
    kk_function_t _pat_14 = _con_x1156->dc_to_instant;
    kk_function_t _pat_15 = _con_x1156->days_to_date;
    kk_function_t _pat_16 = _con_x1156->date_to_days;
    kk_string_t _pat_21 = _con_x1157->name;
    kk_function_t _pat_22 = _con_x1157->utc_delta;
    kk_function_t _pat_23 = _con_x1157->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
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
      kk_datatype_ptr_free(i, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(i, _ctx);
    }
    _x_x1153 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1158;
  {
    struct kk_std_time_time_Time* _con_x1159 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1159->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1159->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1159->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1159->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1159->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1159->instant;
    struct kk_std_time_date_Clock* _con_x1160 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1161 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1162 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1159->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1160->hours;
    kk_integer_t _pat_6_0 = _con_x1160->minutes;
    kk_string_t _pat_9_0 = _con_x1161->name;
    kk_string_t _pat_10_0 = _con_x1161->long_name;
    kk_string_t _pat_11_0 = _con_x1161->month_prefix;
    kk_function_t _pat_12_0 = _con_x1161->show_era;
    kk_function_t _pat_13_0 = _con_x1161->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1161->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1161->days_to_date;
    kk_function_t _pat_16_0 = _con_x1161->date_to_days;
    kk_string_t _pat_21_0 = _con_x1162->name;
    kk_function_t _pat_22_0 = _con_x1162->utc_delta;
    kk_function_t _pat_23_0 = _con_x1162->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(j, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(j, _ctx);
    }
    _x_x1158 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1152 = kk_std_time_instant_cmp(_x_x1153, _x_x1158, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x1152, kk_std_core_types__new_Eq(_ctx), _ctx);
}

bool kk_std_time_time__lp__lt__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> bool */ 
  kk_std_core_types__order _x_x1163;
  kk_std_time_instant__instant _x_x1164;
  {
    struct kk_std_time_time_Time* _con_x1165 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1165->date;
    kk_std_time_date__clock _pat_4 = _con_x1165->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1165->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1165->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1165->timezone;
    kk_std_time_instant__instant _x = _con_x1165->instant;
    struct kk_std_time_date_Clock* _con_x1166 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1167 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1168 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1165->tzabbrv;
    kk_integer_t _pat_5 = _con_x1166->hours;
    kk_integer_t _pat_6 = _con_x1166->minutes;
    kk_string_t _pat_9 = _con_x1167->name;
    kk_string_t _pat_10 = _con_x1167->long_name;
    kk_string_t _pat_11 = _con_x1167->month_prefix;
    kk_function_t _pat_12 = _con_x1167->show_era;
    kk_function_t _pat_13 = _con_x1167->instant_to_dc;
    kk_function_t _pat_14 = _con_x1167->dc_to_instant;
    kk_function_t _pat_15 = _con_x1167->days_to_date;
    kk_function_t _pat_16 = _con_x1167->date_to_days;
    kk_string_t _pat_21 = _con_x1168->name;
    kk_function_t _pat_22 = _con_x1168->utc_delta;
    kk_function_t _pat_23 = _con_x1168->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
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
      kk_datatype_ptr_free(i, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(i, _ctx);
    }
    _x_x1164 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1169;
  {
    struct kk_std_time_time_Time* _con_x1170 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1170->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1170->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1170->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1170->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1170->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1170->instant;
    struct kk_std_time_date_Clock* _con_x1171 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1172 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1173 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1170->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1171->hours;
    kk_integer_t _pat_6_0 = _con_x1171->minutes;
    kk_string_t _pat_9_0 = _con_x1172->name;
    kk_string_t _pat_10_0 = _con_x1172->long_name;
    kk_string_t _pat_11_0 = _con_x1172->month_prefix;
    kk_function_t _pat_12_0 = _con_x1172->show_era;
    kk_function_t _pat_13_0 = _con_x1172->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1172->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1172->days_to_date;
    kk_function_t _pat_16_0 = _con_x1172->date_to_days;
    kk_string_t _pat_21_0 = _con_x1173->name;
    kk_function_t _pat_22_0 = _con_x1173->utc_delta;
    kk_function_t _pat_23_0 = _con_x1173->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(j, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(j, _ctx);
    }
    _x_x1169 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1163 = kk_std_time_instant_cmp(_x_x1164, _x_x1169, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x1163, kk_std_core_types__new_Lt(_ctx), _ctx);
}

bool kk_std_time_time__lp__excl__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> bool */ 
  kk_std_core_types__order _x_x1174;
  kk_std_time_instant__instant _x_x1175;
  {
    struct kk_std_time_time_Time* _con_x1176 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1176->date;
    kk_std_time_date__clock _pat_4 = _con_x1176->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1176->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1176->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1176->timezone;
    kk_std_time_instant__instant _x = _con_x1176->instant;
    struct kk_std_time_date_Clock* _con_x1177 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1178 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1179 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1176->tzabbrv;
    kk_integer_t _pat_5 = _con_x1177->hours;
    kk_integer_t _pat_6 = _con_x1177->minutes;
    kk_string_t _pat_9 = _con_x1178->name;
    kk_string_t _pat_10 = _con_x1178->long_name;
    kk_string_t _pat_11 = _con_x1178->month_prefix;
    kk_function_t _pat_12 = _con_x1178->show_era;
    kk_function_t _pat_13 = _con_x1178->instant_to_dc;
    kk_function_t _pat_14 = _con_x1178->dc_to_instant;
    kk_function_t _pat_15 = _con_x1178->days_to_date;
    kk_function_t _pat_16 = _con_x1178->date_to_days;
    kk_string_t _pat_21 = _con_x1179->name;
    kk_function_t _pat_22 = _con_x1179->utc_delta;
    kk_function_t _pat_23 = _con_x1179->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
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
      kk_datatype_ptr_free(i, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(i, _ctx);
    }
    _x_x1175 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1180;
  {
    struct kk_std_time_time_Time* _con_x1181 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1181->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1181->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1181->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1181->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1181->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1181->instant;
    struct kk_std_time_date_Clock* _con_x1182 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1183 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1184 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1181->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1182->hours;
    kk_integer_t _pat_6_0 = _con_x1182->minutes;
    kk_string_t _pat_9_0 = _con_x1183->name;
    kk_string_t _pat_10_0 = _con_x1183->long_name;
    kk_string_t _pat_11_0 = _con_x1183->month_prefix;
    kk_function_t _pat_12_0 = _con_x1183->show_era;
    kk_function_t _pat_13_0 = _con_x1183->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1183->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1183->days_to_date;
    kk_function_t _pat_16_0 = _con_x1183->date_to_days;
    kk_string_t _pat_21_0 = _con_x1184->name;
    kk_function_t _pat_22_0 = _con_x1184->utc_delta;
    kk_function_t _pat_23_0 = _con_x1184->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(j, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(j, _ctx);
    }
    _x_x1180 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1174 = kk_std_time_instant_cmp(_x_x1175, _x_x1180, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x1174, kk_std_core_types__new_Eq(_ctx), _ctx);
}

bool kk_std_time_time__lp__lt__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> bool */ 
  kk_std_core_types__order _x_x1185;
  kk_std_time_instant__instant _x_x1186;
  {
    struct kk_std_time_time_Time* _con_x1187 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1187->date;
    kk_std_time_date__clock _pat_4 = _con_x1187->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1187->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1187->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1187->timezone;
    kk_std_time_instant__instant _x = _con_x1187->instant;
    struct kk_std_time_date_Clock* _con_x1188 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1189 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1190 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1187->tzabbrv;
    kk_integer_t _pat_5 = _con_x1188->hours;
    kk_integer_t _pat_6 = _con_x1188->minutes;
    kk_string_t _pat_9 = _con_x1189->name;
    kk_string_t _pat_10 = _con_x1189->long_name;
    kk_string_t _pat_11 = _con_x1189->month_prefix;
    kk_function_t _pat_12 = _con_x1189->show_era;
    kk_function_t _pat_13 = _con_x1189->instant_to_dc;
    kk_function_t _pat_14 = _con_x1189->dc_to_instant;
    kk_function_t _pat_15 = _con_x1189->days_to_date;
    kk_function_t _pat_16 = _con_x1189->date_to_days;
    kk_string_t _pat_21 = _con_x1190->name;
    kk_function_t _pat_22 = _con_x1190->utc_delta;
    kk_function_t _pat_23 = _con_x1190->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
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
      kk_datatype_ptr_free(i, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(i, _ctx);
    }
    _x_x1186 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1191;
  {
    struct kk_std_time_time_Time* _con_x1192 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1192->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1192->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1192->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1192->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1192->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1192->instant;
    struct kk_std_time_date_Clock* _con_x1193 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1194 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1195 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1192->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1193->hours;
    kk_integer_t _pat_6_0 = _con_x1193->minutes;
    kk_string_t _pat_9_0 = _con_x1194->name;
    kk_string_t _pat_10_0 = _con_x1194->long_name;
    kk_string_t _pat_11_0 = _con_x1194->month_prefix;
    kk_function_t _pat_12_0 = _con_x1194->show_era;
    kk_function_t _pat_13_0 = _con_x1194->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1194->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1194->days_to_date;
    kk_function_t _pat_16_0 = _con_x1194->date_to_days;
    kk_string_t _pat_21_0 = _con_x1195->name;
    kk_function_t _pat_22_0 = _con_x1195->utc_delta;
    kk_function_t _pat_23_0 = _con_x1195->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(j, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(j, _ctx);
    }
    _x_x1191 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1185 = kk_std_time_instant_cmp(_x_x1186, _x_x1191, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x1185, kk_std_core_types__new_Gt(_ctx), _ctx);
}

bool kk_std_time_time__lp__gt__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> bool */ 
  kk_std_core_types__order _x_x1196;
  kk_std_time_instant__instant _x_x1197;
  {
    struct kk_std_time_time_Time* _con_x1198 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1198->date;
    kk_std_time_date__clock _pat_4 = _con_x1198->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1198->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1198->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1198->timezone;
    kk_std_time_instant__instant _x = _con_x1198->instant;
    struct kk_std_time_date_Clock* _con_x1199 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1200 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1201 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1198->tzabbrv;
    kk_integer_t _pat_5 = _con_x1199->hours;
    kk_integer_t _pat_6 = _con_x1199->minutes;
    kk_string_t _pat_9 = _con_x1200->name;
    kk_string_t _pat_10 = _con_x1200->long_name;
    kk_string_t _pat_11 = _con_x1200->month_prefix;
    kk_function_t _pat_12 = _con_x1200->show_era;
    kk_function_t _pat_13 = _con_x1200->instant_to_dc;
    kk_function_t _pat_14 = _con_x1200->dc_to_instant;
    kk_function_t _pat_15 = _con_x1200->days_to_date;
    kk_function_t _pat_16 = _con_x1200->date_to_days;
    kk_string_t _pat_21 = _con_x1201->name;
    kk_function_t _pat_22 = _con_x1201->utc_delta;
    kk_function_t _pat_23 = _con_x1201->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
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
      kk_datatype_ptr_free(i, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(i, _ctx);
    }
    _x_x1197 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1202;
  {
    struct kk_std_time_time_Time* _con_x1203 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1203->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1203->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1203->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1203->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1203->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1203->instant;
    struct kk_std_time_date_Clock* _con_x1204 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1205 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1206 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1203->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1204->hours;
    kk_integer_t _pat_6_0 = _con_x1204->minutes;
    kk_string_t _pat_9_0 = _con_x1205->name;
    kk_string_t _pat_10_0 = _con_x1205->long_name;
    kk_string_t _pat_11_0 = _con_x1205->month_prefix;
    kk_function_t _pat_12_0 = _con_x1205->show_era;
    kk_function_t _pat_13_0 = _con_x1205->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1205->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1205->days_to_date;
    kk_function_t _pat_16_0 = _con_x1205->date_to_days;
    kk_string_t _pat_21_0 = _con_x1206->name;
    kk_function_t _pat_22_0 = _con_x1206->utc_delta;
    kk_function_t _pat_23_0 = _con_x1206->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(j, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(j, _ctx);
    }
    _x_x1202 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1196 = kk_std_time_instant_cmp(_x_x1197, _x_x1202, _ctx); /*order*/
  return kk_std_core_order__lp__eq__eq__rp_(_x_x1196, kk_std_core_types__new_Gt(_ctx), _ctx);
}

bool kk_std_time_time__lp__gt__eq__rp_(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> bool */ 
  kk_std_core_types__order _x_x1207;
  kk_std_time_instant__instant _x_x1208;
  {
    struct kk_std_time_time_Time* _con_x1209 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1209->date;
    kk_std_time_date__clock _pat_4 = _con_x1209->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1209->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1209->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1209->timezone;
    kk_std_time_instant__instant _x = _con_x1209->instant;
    struct kk_std_time_date_Clock* _con_x1210 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1211 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1212 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1209->tzabbrv;
    kk_integer_t _pat_5 = _con_x1210->hours;
    kk_integer_t _pat_6 = _con_x1210->minutes;
    kk_string_t _pat_9 = _con_x1211->name;
    kk_string_t _pat_10 = _con_x1211->long_name;
    kk_string_t _pat_11 = _con_x1211->month_prefix;
    kk_function_t _pat_12 = _con_x1211->show_era;
    kk_function_t _pat_13 = _con_x1211->instant_to_dc;
    kk_function_t _pat_14 = _con_x1211->dc_to_instant;
    kk_function_t _pat_15 = _con_x1211->days_to_date;
    kk_function_t _pat_16 = _con_x1211->date_to_days;
    kk_string_t _pat_21 = _con_x1212->name;
    kk_function_t _pat_22 = _con_x1212->utc_delta;
    kk_function_t _pat_23 = _con_x1212->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(i, _ctx)) {
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
      kk_datatype_ptr_free(i, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(i, _ctx);
    }
    _x_x1208 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1213;
  {
    struct kk_std_time_time_Time* _con_x1214 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1214->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1214->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1214->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1214->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1214->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1214->instant;
    struct kk_std_time_date_Clock* _con_x1215 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1216 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1217 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1214->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1215->hours;
    kk_integer_t _pat_6_0 = _con_x1215->minutes;
    kk_string_t _pat_9_0 = _con_x1216->name;
    kk_string_t _pat_10_0 = _con_x1216->long_name;
    kk_string_t _pat_11_0 = _con_x1216->month_prefix;
    kk_function_t _pat_12_0 = _con_x1216->show_era;
    kk_function_t _pat_13_0 = _con_x1216->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1216->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1216->days_to_date;
    kk_function_t _pat_16_0 = _con_x1216->date_to_days;
    kk_string_t _pat_21_0 = _con_x1217->name;
    kk_function_t _pat_22_0 = _con_x1217->utc_delta;
    kk_function_t _pat_23_0 = _con_x1217->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(j, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(j, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(j, _ctx);
    }
    _x_x1213 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1207 = kk_std_time_instant_cmp(_x_x1208, _x_x1213, _ctx); /*order*/
  return kk_std_core_order__lp__excl__eq__rp_(_x_x1207, kk_std_core_types__new_Lt(_ctx), _ctx);
}
 
// The minimum of two times (as by their actual instant in time)

kk_std_time_time__time kk_std_time_time_min(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> time */ 
  bool _match_x770;
  kk_std_core_types__order _x_x1218;
  kk_std_time_instant__instant _x_x1219;
  {
    struct kk_std_time_time_Time* _con_x1220 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1220->date;
    kk_std_time_date__clock _pat_4 = _con_x1220->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1220->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1220->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1220->timezone;
    kk_std_time_instant__instant _x = _con_x1220->instant;
    struct kk_std_time_date_Clock* _con_x1221 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1222 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1223 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x1219 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1224;
  {
    struct kk_std_time_time_Time* _con_x1225 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1225->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1225->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1225->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1225->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1225->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1225->instant;
    struct kk_std_time_date_Clock* _con_x1226 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1227 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1228 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    _x_x1224 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1218 = kk_std_time_instant_cmp(_x_x1219, _x_x1224, _ctx); /*order*/
  _match_x770 = kk_std_core_order__lp__excl__eq__rp_(_x_x1218, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x770) {
    kk_datatype_ptr_dropn(j, (KK_I32(9)), _ctx);
    return i;
  }
  {
    kk_datatype_ptr_dropn(i, (KK_I32(9)), _ctx);
    return j;
  }
}
 
// The maximum of two times (as by their actual instant in time)

kk_std_time_time__time kk_std_time_time_max(kk_std_time_time__time i, kk_std_time_time__time j, kk_context_t* _ctx) { /* (i : time, j : time) -> time */ 
  bool _match_x769;
  kk_std_core_types__order _x_x1229;
  kk_std_time_instant__instant _x_x1230;
  {
    struct kk_std_time_time_Time* _con_x1231 = kk_std_time_time__as_Time(i, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1231->date;
    kk_std_time_date__clock _pat_4 = _con_x1231->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1231->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1231->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1231->timezone;
    kk_std_time_instant__instant _x = _con_x1231->instant;
    struct kk_std_time_date_Clock* _con_x1232 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1233 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1234 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x1230 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1235;
  {
    struct kk_std_time_time_Time* _con_x1236 = kk_std_time_time__as_Time(j, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1236->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1236->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1236->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1236->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1236->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1236->instant;
    struct kk_std_time_date_Clock* _con_x1237 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1238 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1239 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    _x_x1235 = _x_0; /*std/time/instant/instant*/
  }
  _x_x1229 = kk_std_time_instant_cmp(_x_x1230, _x_x1235, _ctx); /*order*/
  _match_x769 = kk_std_core_order__lp__excl__eq__rp_(_x_x1229, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x769) {
    kk_datatype_ptr_dropn(j, (KK_I32(9)), _ctx);
    return i;
  }
  {
    kk_datatype_ptr_dropn(i, (KK_I32(9)), _ctx);
    return j;
  }
}

bool kk_std_time_time_is_numeric(kk_string_t abbrv, kk_context_t* _ctx) { /* (abbrv : string) -> bool */ 
  bool _match_x767;
  kk_string_t _x_x1240 = kk_string_dup(abbrv, _ctx); /*string*/
  kk_string_t _x_x1241 = kk_string_empty(); /*string*/
  _match_x767 = kk_string_is_eq(_x_x1240,_x_x1241,kk_context()); /*bool*/
  if (_match_x767) {
    kk_string_drop(abbrv, _ctx);
    return true;
  }
  {
    bool _match_x768;
    kk_string_t _x_x1243;
    kk_string_t _x_x1244 = kk_string_dup(abbrv, _ctx); /*string*/
    _x_x1243 = kk_std_core_sslice_head(_x_x1244, _ctx); /*string*/
    kk_string_t _x_x1245;
    kk_define_string_literal(, _s_x1246, 1, "+", _ctx)
    _x_x1245 = kk_string_dup(_s_x1246, _ctx); /*string*/
    _match_x768 = kk_string_is_eq(_x_x1243,_x_x1245,kk_context()); /*bool*/
    if (_match_x768) {
      kk_string_drop(abbrv, _ctx);
      return true;
    }
    {
      kk_string_t _x_x1247 = kk_std_core_sslice_head(abbrv, _ctx); /*string*/
      kk_string_t _x_x1248;
      kk_define_string_literal(, _s_x1249, 1, "-", _ctx)
      _x_x1248 = kk_string_dup(_s_x1249, _ctx); /*string*/
      return kk_string_is_eq(_x_x1247,_x_x1248,kk_context());
    }
  }
}
 
// Convert an `:instant` to a `:time` value in a given timezone `tz` (=`tz-utc` by default)
// and calendar (=`cal-iso` by default).

kk_std_time_time__time kk_std_time_time_instant_fs_time(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 
  kk_std_time_instant__instant j;
  bool _match_x765;
  kk_string_t _x_x1250;
  {
    kk_std_time_timestamp__timestamp _pat_0_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1251 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1252 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1253 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x_1 = _con_x1253->name;
      kk_string_t _pat_0_1 = _con_x1253->unit;
      kk_function_t _pat_1_1 = _con_x1253->from_tai;
      kk_function_t _pat_2_1 = _con_x1253->to_tai;
      kk_std_core_types__maybe _pat_3_1 = _con_x1253->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_1 = _con_x1253->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_1 = _con_x1253->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
        kk_function_drop(_pat_2_1, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1250 = _x_1; /*string*/
    }
  }
  kk_string_t _x_x1254;
  kk_std_time_instant__timescale _match_x766;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x10 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_1777 = kk_std_time_instant__timescale_unbox(_box_x10, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_1777, _ctx);
    _match_x766 = _uniq_ts_1777; /*std/time/instant/timescale*/
  }
  else {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1255 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1256 = kk_std_time_instant__as_Timescale(_x, _ctx);
    kk_std_time_instant__timescale_dup(_x, _ctx);
    _match_x766 = _x; /*std/time/instant/timescale*/
  }
  {
    struct kk_std_time_instant_Timescale* _con_x1257 = kk_std_time_instant__as_Timescale(_match_x766, _ctx);
    kk_string_t _x_1_0 = _con_x1257->name;
    kk_string_t _pat_0_1_0 = _con_x1257->unit;
    kk_function_t _pat_1_1_0 = _con_x1257->from_tai;
    kk_function_t _pat_2_1_0 = _con_x1257->to_tai;
    kk_std_core_types__maybe _pat_3_1_0 = _con_x1257->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_1_0 = _con_x1257->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_1_0 = _con_x1257->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x766, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_1_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_1_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_3_1_0, _ctx);
      kk_function_drop(_pat_2_1_0, _ctx);
      kk_function_drop(_pat_1_1_0, _ctx);
      kk_string_drop(_pat_0_1_0, _ctx);
      kk_datatype_ptr_free(_match_x766, _ctx);
    }
    else {
      kk_string_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(_match_x766, _ctx);
    }
    _x_x1254 = _x_1_0; /*string*/
  }
  _match_x765 = kk_string_is_eq(_x_x1250,_x_x1254,kk_context()); /*bool*/
  if (_match_x765) {
    kk_std_core_types__optional_drop(ts, _ctx);
    j = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1258;
    kk_std_time_timestamp__timestamp _x_x1259;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1260 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1261 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x1259 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x1262;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1263 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1264 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      _x_x1262 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x1265;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x11 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_1777_0 = kk_std_time_instant__timescale_unbox(_box_x11, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_1777_0, _ctx);
      _x_x1265 = _uniq_ts_1777_0; /*std/time/instant/timescale*/
    }
    else {
      kk_std_time_timestamp__timestamp _pat_0_0_1 = i.since;
      kk_std_time_instant__timescale _x_4 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1266 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1267 = kk_std_time_instant__as_Timescale(_x_4, _ctx);
      kk_std_time_instant__timescale_dup(_x_4, _ctx);
      _x_x1265 = _x_4; /*std/time/instant/timescale*/
    }
    _x_x1258 = kk_std_time_instant_convert(_x_x1259, _x_x1262, _x_x1265, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x1268;
    if (kk_std_core_types__is_Optional(ts, _ctx)) {
      kk_box_t _box_x12 = ts._cons._Optional.value;
      kk_std_time_instant__timescale _uniq_ts_1777_1 = kk_std_time_instant__timescale_unbox(_box_x12, KK_BORROWED, _ctx);
      kk_std_time_instant__timescale_dup(_uniq_ts_1777_1, _ctx);
      kk_std_core_types__optional_drop(ts, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x1268 = _uniq_ts_1777_1; /*std/time/instant/timescale*/
    }
    else {
      kk_std_core_types__optional_drop(ts, _ctx);
      {
        kk_std_time_timestamp__timestamp _pat_0_0_2 = i.since;
        kk_std_time_instant__timescale _x_5 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1269 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_2, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1270 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
        kk_std_time_instant__timescale_dup(_x_5, _ctx);
        kk_std_time_instant__instant_drop(i, _ctx);
        _x_x1268 = _x_5; /*std/time/instant/timescale*/
      }
    }
    j = kk_std_time_instant__new_Instant(_x_x1258, _x_x1268, _ctx); /*std/time/instant/instant*/
  }
  kk_std_time_calendar__timezone _b_x14_23;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x13 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_1765 = kk_std_time_calendar__timezone_unbox(_box_x13, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_1765, _ctx);
    _b_x14_23 = _uniq_tz_1765; /*std/time/calendar/timezone*/
  }
  else {
    _b_x14_23 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  kk_std_time_calendar__calendar _b_x16_24;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x15 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_1769 = kk_std_time_calendar__calendar_unbox(_box_x15, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_1769, _ctx);
    _b_x16_24 = _uniq_cal_1769; /*std/time/calendar/calendar*/
  }
  else {
    _b_x16_24 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  kk_std_core_types__tuple4 _match_x764;
  kk_std_time_instant__instant _x_x1271 = kk_std_time_instant__instant_dup(j, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1272 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x14_23, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1273 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(_b_x16_24, _ctx), _ctx); /*? 7*/
  _match_x764 = kk_std_time_calendar_instant_dc(_x_x1271, _x_x1272, _x_x1273, _ctx); /*(std/time/date/date, std/time/date/clock, std/time/duration/duration, string)*/
  {
    struct kk_std_core_types_Tuple4* _con_x1274 = kk_std_core_types__as_Tuple4(_match_x764, _ctx);
    kk_box_t _box_x17 = _con_x1274->fst;
    kk_box_t _box_x18 = _con_x1274->snd;
    kk_box_t _box_x19 = _con_x1274->thd;
    kk_box_t _box_x20 = _con_x1274->field4;
    kk_std_time_date__date d = kk_std_time_date__date_unbox(_box_x17, KK_BORROWED, _ctx);
    kk_std_time_date__clock c = kk_std_time_date__clock_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_time_duration__duration tzdelta = kk_std_time_duration__duration_unbox(_box_x19, KK_BORROWED, _ctx);
    struct kk_std_time_date_Clock* _con_x1275 = kk_std_time_date__as_Clock(c, _ctx);
    kk_string_t tzabbrv = kk_string_unbox(_box_x20);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x764, _ctx)) {
      kk_box_drop(_box_x19, _ctx);
      kk_std_time_date__date_dup(d, _ctx);
      kk_box_drop(_box_x17, _ctx);
      kk_datatype_ptr_free(_match_x764, _ctx);
    }
    else {
      kk_std_time_date__clock_dup(c, _ctx);
      kk_std_time_date__date_dup(d, _ctx);
      kk_string_dup(tzabbrv, _ctx);
      kk_datatype_ptr_decref(_match_x764, _ctx);
    }
    kk_std_time_calendar__calendar _x_x1276;
    if (kk_std_core_types__is_Optional(cal, _ctx)) {
      kk_box_t _box_x21 = cal._cons._Optional.value;
      kk_std_time_calendar__calendar _uniq_cal_1769_0 = kk_std_time_calendar__calendar_unbox(_box_x21, KK_BORROWED, _ctx);
      kk_std_time_calendar__calendar_dup(_uniq_cal_1769_0, _ctx);
      kk_std_core_types__optional_drop(cal, _ctx);
      _x_x1276 = _uniq_cal_1769_0; /*std/time/calendar/calendar*/
    }
    else {
      kk_std_core_types__optional_drop(cal, _ctx);
      _x_x1276 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
    }
    kk_std_time_calendar__timezone _x_x1277;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x22 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_1765_0 = kk_std_time_calendar__timezone_unbox(_box_x22, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_1765_0, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1277 = _uniq_tz_1765_0; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1277 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    return kk_std_time_time__new_Time(kk_reuse_null, 0, d, c, _x_x1276, tzdelta, tzabbrv, _x_x1277, j, _ctx);
  }
}

kk_std_time_time__time kk_std_time_time_timescale_fs_time(kk_std_time_instant__timescale tscale, kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (tscale : std/time/instant/timescale, year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> time */ 
  kk_std_time_instant__instant _x_x1278;
  kk_std_time_instant__timescale _x_x1279 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
  kk_std_core_types__optional _x_x1280;
  kk_box_t _x_x1281;
  kk_integer_t _x_x1282;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x25 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_2098 = kk_integer_unbox(_box_x25, _ctx);
    kk_integer_dup(_uniq_month_2098, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1282 = _uniq_month_2098; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1282 = kk_integer_from_small(1); /*int*/
  }
  _x_x1281 = kk_integer_box(_x_x1282, _ctx); /*7*/
  _x_x1280 = kk_std_core_types__new_Optional(_x_x1281, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1283;
  kk_box_t _x_x1284;
  kk_integer_t _x_x1285;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x27 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_2102 = kk_integer_unbox(_box_x27, _ctx);
    kk_integer_dup(_uniq_day_2102, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x1285 = _uniq_day_2102; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x1285 = kk_integer_from_small(1); /*int*/
  }
  _x_x1284 = kk_integer_box(_x_x1285, _ctx); /*7*/
  _x_x1283 = kk_std_core_types__new_Optional(_x_x1284, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1286;
  kk_box_t _x_x1287;
  kk_integer_t _x_x1288;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x29 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_2106 = kk_integer_unbox(_box_x29, _ctx);
    kk_integer_dup(_uniq_hours_2106, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x1288 = _uniq_hours_2106; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x1288 = kk_integer_from_small(0); /*int*/
  }
  _x_x1287 = kk_integer_box(_x_x1288, _ctx); /*7*/
  _x_x1286 = kk_std_core_types__new_Optional(_x_x1287, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1289;
  kk_box_t _x_x1290;
  kk_integer_t _x_x1291;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x31 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_2110 = kk_integer_unbox(_box_x31, _ctx);
    kk_integer_dup(_uniq_minutes_2110, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x1291 = _uniq_minutes_2110; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x1291 = kk_integer_from_small(0); /*int*/
  }
  _x_x1290 = kk_integer_box(_x_x1291, _ctx); /*7*/
  _x_x1289 = kk_std_core_types__new_Optional(_x_x1290, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1292;
  kk_box_t _x_x1293;
  kk_integer_t _x_x1294;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x33 = secs._cons._Optional.value;
    kk_integer_t _uniq_secs_2114 = kk_integer_unbox(_box_x33, _ctx);
    kk_integer_dup(_uniq_secs_2114, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x1294 = _uniq_secs_2114; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x1294 = kk_integer_from_small(0); /*int*/
  }
  _x_x1293 = kk_integer_box(_x_x1294, _ctx); /*7*/
  _x_x1292 = kk_std_core_types__new_Optional(_x_x1293, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1295;
  kk_box_t _x_x1296;
  double _x_x1297;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x35 = frac._cons._Optional.value;
    double _uniq_frac_2118 = kk_double_unbox(_box_x35, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1297 = _uniq_frac_2118; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1297 = 0x0p+0; /*float64*/
  }
  _x_x1296 = kk_double_box(_x_x1297, _ctx); /*7*/
  _x_x1295 = kk_std_core_types__new_Optional(_x_x1296, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1298;
  kk_box_t _x_x1299;
  kk_std_time_calendar__timezone _x_x1300;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x37 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_2122 = kk_std_time_calendar__timezone_unbox(_box_x37, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_2122, _ctx);
    _x_x1300 = _uniq_tz_2122; /*std/time/calendar/timezone*/
  }
  else {
    _x_x1300 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1299 = kk_std_time_calendar__timezone_box(_x_x1300, _ctx); /*7*/
  _x_x1298 = kk_std_core_types__new_Optional(_x_x1299, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1301;
  kk_box_t _x_x1302;
  kk_std_time_calendar__calendar _x_x1303;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x39 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2126 = kk_std_time_calendar__calendar_unbox(_box_x39, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2126, _ctx);
    _x_x1303 = _uniq_cal_2126; /*std/time/calendar/calendar*/
  }
  else {
    _x_x1303 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1302 = kk_std_time_calendar__calendar_box(_x_x1303, _ctx); /*7*/
  _x_x1301 = kk_std_core_types__new_Optional(_x_x1302, _ctx); /*? 7*/
  _x_x1278 = kk_std_time_calendar_timescale_fs_instant(_x_x1279, year_0, _x_x1280, _x_x1283, _x_x1286, _x_x1289, _x_x1292, _x_x1295, _x_x1298, _x_x1301, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1304;
  kk_box_t _x_x1305;
  kk_std_time_calendar__timezone _x_x1306;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x41 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_2122_0 = kk_std_time_calendar__timezone_unbox(_box_x41, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_2122_0, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1306 = _uniq_tz_2122_0; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1306 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1305 = kk_std_time_calendar__timezone_box(_x_x1306, _ctx); /*7*/
  _x_x1304 = kk_std_core_types__new_Optional(_x_x1305, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1307;
  kk_box_t _x_x1308;
  kk_std_time_calendar__calendar _x_x1309;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x43 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2126_0 = kk_std_time_calendar__calendar_unbox(_box_x43, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2126_0, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1309 = _uniq_cal_2126_0; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1309 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1308 = kk_std_time_calendar__calendar_box(_x_x1309, _ctx); /*7*/
  _x_x1307 = kk_std_core_types__new_Optional(_x_x1308, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1310 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(tscale, _ctx), _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x1278, _x_x1304, _x_x1307, _x_x1310, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_time__mlift_time_10405_fun1312__t {
  struct kk_function_s _base;
  kk_std_time_instant__timescale _c_x10330;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day_0;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours_0;
  kk_std_core_types__optional minutes_0;
  kk_std_core_types__optional month_0;
  kk_std_core_types__optional secs;
  kk_std_core_types__optional tz;
  kk_integer_t year_0;
};
static kk_box_t kk_std_time_time__mlift_time_10405_fun1312(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time__new_mlift_time_10405_fun1312(kk_std_time_instant__timescale _c_x10330, kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_std_core_types__optional tz, kk_integer_t year_0, kk_context_t* _ctx) {
  struct kk_std_time_time__mlift_time_10405_fun1312__t* _self = kk_function_alloc_as(struct kk_std_time_time__mlift_time_10405_fun1312__t, 19, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time__mlift_time_10405_fun1312, kk_context());
  _self->_c_x10330 = _c_x10330;
  _self->cal = cal;
  _self->day_0 = day_0;
  _self->frac = frac;
  _self->hours_0 = hours_0;
  _self->minutes_0 = minutes_0;
  _self->month_0 = month_0;
  _self->secs = secs;
  _self->tz = tz;
  _self->year_0 = year_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time__mlift_time_10405_fun1312(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time__mlift_time_10405_fun1312__t* _self = kk_function_as(struct kk_std_time_time__mlift_time_10405_fun1312__t*, _fself, _ctx);
  kk_std_time_instant__timescale _c_x10330 = _self->_c_x10330; /* std/time/instant/timescale */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day_0 = _self->day_0; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours_0 = _self->hours_0; /* ? int */
  kk_std_core_types__optional minutes_0 = _self->minutes_0; /* ? int */
  kk_std_core_types__optional month_0 = _self->month_0; /* ? int */
  kk_std_core_types__optional secs = _self->secs; /* ? int */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_integer_t year_0 = _self->year_0; /* int */
  kk_drop_match(_self, {kk_std_time_instant__timescale_dup(_c_x10330, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day_0, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours_0, _ctx);kk_std_core_types__optional_dup(minutes_0, _ctx);kk_std_core_types__optional_dup(month_0, _ctx);kk_std_core_types__optional_dup(secs, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_integer_dup(year_0, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1313;
  kk_std_core_types__optional _x_x1314;
  kk_box_t _x_x1315;
  kk_integer_t _x_x1316;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x57 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_1854 = kk_integer_unbox(_box_x57, _ctx);
    kk_integer_dup(_uniq_month_1854, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1316 = _uniq_month_1854; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1316 = kk_integer_from_small(1); /*int*/
  }
  _x_x1315 = kk_integer_box(_x_x1316, _ctx); /*7*/
  _x_x1314 = kk_std_core_types__new_Optional(_x_x1315, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1317;
  kk_box_t _x_x1318;
  kk_integer_t _x_x1319;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x59 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_1858 = kk_integer_unbox(_box_x59, _ctx);
    kk_integer_dup(_uniq_day_1858, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x1319 = _uniq_day_1858; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x1319 = kk_integer_from_small(1); /*int*/
  }
  _x_x1318 = kk_integer_box(_x_x1319, _ctx); /*7*/
  _x_x1317 = kk_std_core_types__new_Optional(_x_x1318, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1320;
  kk_box_t _x_x1321;
  kk_integer_t _x_x1322;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x61 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_1862 = kk_integer_unbox(_box_x61, _ctx);
    kk_integer_dup(_uniq_hours_1862, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x1322 = _uniq_hours_1862; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x1322 = kk_integer_from_small(0); /*int*/
  }
  _x_x1321 = kk_integer_box(_x_x1322, _ctx); /*7*/
  _x_x1320 = kk_std_core_types__new_Optional(_x_x1321, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1323;
  kk_box_t _x_x1324;
  kk_integer_t _x_x1325;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x63 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_1866 = kk_integer_unbox(_box_x63, _ctx);
    kk_integer_dup(_uniq_minutes_1866, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x1325 = _uniq_minutes_1866; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x1325 = kk_integer_from_small(0); /*int*/
  }
  _x_x1324 = kk_integer_box(_x_x1325, _ctx); /*7*/
  _x_x1323 = kk_std_core_types__new_Optional(_x_x1324, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1326;
  kk_box_t _x_x1327;
  kk_integer_t _x_x1328;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x65 = secs._cons._Optional.value;
    kk_integer_t _uniq_secs_1870 = kk_integer_unbox(_box_x65, _ctx);
    kk_integer_dup(_uniq_secs_1870, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x1328 = _uniq_secs_1870; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x1328 = kk_integer_from_small(0); /*int*/
  }
  _x_x1327 = kk_integer_box(_x_x1328, _ctx); /*7*/
  _x_x1326 = kk_std_core_types__new_Optional(_x_x1327, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1329;
  kk_box_t _x_x1330;
  double _x_x1331;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x67 = frac._cons._Optional.value;
    double _uniq_frac_1874 = kk_double_unbox(_box_x67, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1331 = _uniq_frac_1874; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1331 = 0x0p+0; /*float64*/
  }
  _x_x1330 = kk_double_box(_x_x1331, _ctx); /*7*/
  _x_x1329 = kk_std_core_types__new_Optional(_x_x1330, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1332;
  kk_box_t _x_x1333;
  kk_std_time_calendar__timezone _x_x1334;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x69 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_1878 = kk_std_time_calendar__timezone_unbox(_box_x69, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_1878, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1334 = _uniq_tz_1878; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1334 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1333 = kk_std_time_calendar__timezone_box(_x_x1334, _ctx); /*7*/
  _x_x1332 = kk_std_core_types__new_Optional(_x_x1333, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1335;
  kk_box_t _x_x1336;
  kk_std_time_calendar__calendar _x_x1337;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x71 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_1882 = kk_std_time_calendar__calendar_unbox(_box_x71, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_1882, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1337 = _uniq_cal_1882; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1337 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1336 = kk_std_time_calendar__calendar_box(_x_x1337, _ctx); /*7*/
  _x_x1335 = kk_std_core_types__new_Optional(_x_x1336, _ctx); /*? 7*/
  _x_x1313 = kk_std_time_time_timescale_fs_time(_c_x10330, year_0, _x_x1314, _x_x1317, _x_x1320, _x_x1323, _x_x1326, _x_x1329, _x_x1332, _x_x1335, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1313, _ctx);
}

kk_std_time_time__time kk_std_time_time__mlift_time_10405(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_std_core_types__optional tz, kk_integer_t year_0, kk_std_time_instant__timescale _c_x10330, kk_context_t* _ctx) { /* (cal : ? std/time/calendar/calendar, day@0 : ? int, frac : ? float64, hours@0 : ? int, minutes@0 : ? int, month@0 : ? int, secs : ? int, tz : ? std/time/calendar/timezone, year@0 : int, std/time/instant/timescale) -> time */ 
  kk_box_t _x_x1311 = kk_std_core_hnd__open_none0(kk_std_time_time__new_mlift_time_10405_fun1312(_c_x10330, cal, day_0, frac, hours_0, minutes_0, month_0, secs, tz, year_0, _ctx), _ctx); /*9836*/
  return kk_std_time_time__time_unbox(_x_x1311, KK_OWNED, _ctx);
}
 
// /* Return the `:time` value for a given date and clock in a timezone `tz` (=`tz-utc` by default)
// interpreted by calendar `cal` (=`cal-iso`).
// 
// The `month`, `day`, `hour`, `minutes` may be outside their usual ranges
// and will be normalized during the conversion. For example, January 33 converts to February 2.
// This makes it very easy to add- or subtract days or months to an existing time.
// 
// When the `seconds` or fraction of seconds `frac` add up over 60 though, those extra seconds are
// interpreted as leap seconds.
// 
// Due to timezone transitions, or leap seconds, it is possible to specify dates that never
// happened (as it was skipped by a timezone change), or ambiguous times (as a timezone springs back).
// In such cases, the time is always interpreted in the earlier timezone.
// */


// lift anonymous function
struct kk_std_time_time_time_fun1341__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day_0;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours_0;
  kk_std_core_types__optional minutes_0;
  kk_std_core_types__optional month_0;
  kk_std_core_types__optional secs;
  kk_std_core_types__optional tz;
  kk_integer_t year_0;
};
static kk_box_t kk_std_time_time_time_fun1341(kk_function_t _fself, kk_box_t _b_x91, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_fun1341(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_std_core_types__optional tz, kk_integer_t year_0, kk_context_t* _ctx) {
  struct kk_std_time_time_time_fun1341__t* _self = kk_function_alloc_as(struct kk_std_time_time_time_fun1341__t, 18, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_time_fun1341, kk_context());
  _self->cal = cal;
  _self->day_0 = day_0;
  _self->frac = frac;
  _self->hours_0 = hours_0;
  _self->minutes_0 = minutes_0;
  _self->month_0 = month_0;
  _self->secs = secs;
  _self->tz = tz;
  _self->year_0 = year_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_time_fun1341(kk_function_t _fself, kk_box_t _b_x91, kk_context_t* _ctx) {
  struct kk_std_time_time_time_fun1341__t* _self = kk_function_as(struct kk_std_time_time_time_fun1341__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day_0 = _self->day_0; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours_0 = _self->hours_0; /* ? int */
  kk_std_core_types__optional minutes_0 = _self->minutes_0; /* ? int */
  kk_std_core_types__optional month_0 = _self->month_0; /* ? int */
  kk_std_core_types__optional secs = _self->secs; /* ? int */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_integer_t year_0 = _self->year_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day_0, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours_0, _ctx);kk_std_core_types__optional_dup(minutes_0, _ctx);kk_std_core_types__optional_dup(month_0, _ctx);kk_std_core_types__optional_dup(secs, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_integer_dup(year_0, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10330_119 = kk_std_time_instant__timescale_unbox(_b_x91, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_time__time _x_x1342 = kk_std_time_time__mlift_time_10405(cal, day_0, frac, hours_0, minutes_0, month_0, secs, tz, year_0, _c_x10330_119, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1342, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_fun1343__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day_0;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours_0;
  kk_std_core_types__optional minutes_0;
  kk_std_core_types__optional month_0;
  kk_std_core_types__optional secs;
  kk_std_core_types__optional tz;
  kk_std_time_instant__timescale x_10411;
  kk_integer_t year_0;
};
static kk_box_t kk_std_time_time_time_fun1343(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_fun1343(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_std_core_types__optional tz, kk_std_time_instant__timescale x_10411, kk_integer_t year_0, kk_context_t* _ctx) {
  struct kk_std_time_time_time_fun1343__t* _self = kk_function_alloc_as(struct kk_std_time_time_time_fun1343__t, 19, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_time_fun1343, kk_context());
  _self->cal = cal;
  _self->day_0 = day_0;
  _self->frac = frac;
  _self->hours_0 = hours_0;
  _self->minutes_0 = minutes_0;
  _self->month_0 = month_0;
  _self->secs = secs;
  _self->tz = tz;
  _self->x_10411 = x_10411;
  _self->year_0 = year_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_time_fun1343(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_time_fun1343__t* _self = kk_function_as(struct kk_std_time_time_time_fun1343__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day_0 = _self->day_0; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours_0 = _self->hours_0; /* ? int */
  kk_std_core_types__optional minutes_0 = _self->minutes_0; /* ? int */
  kk_std_core_types__optional month_0 = _self->month_0; /* ? int */
  kk_std_core_types__optional secs = _self->secs; /* ? int */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_std_time_instant__timescale x_10411 = _self->x_10411; /* std/time/instant/timescale */
  kk_integer_t year_0 = _self->year_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day_0, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours_0, _ctx);kk_std_core_types__optional_dup(minutes_0, _ctx);kk_std_core_types__optional_dup(month_0, _ctx);kk_std_core_types__optional_dup(secs, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_std_time_instant__timescale_dup(x_10411, _ctx);kk_integer_dup(year_0, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1344;
  kk_std_core_types__optional _x_x1345;
  kk_box_t _x_x1346;
  kk_integer_t _x_x1347;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x92 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_1854 = kk_integer_unbox(_box_x92, _ctx);
    kk_integer_dup(_uniq_month_1854, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1347 = _uniq_month_1854; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1347 = kk_integer_from_small(1); /*int*/
  }
  _x_x1346 = kk_integer_box(_x_x1347, _ctx); /*7*/
  _x_x1345 = kk_std_core_types__new_Optional(_x_x1346, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1348;
  kk_box_t _x_x1349;
  kk_integer_t _x_x1350;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x94 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_1858 = kk_integer_unbox(_box_x94, _ctx);
    kk_integer_dup(_uniq_day_1858, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x1350 = _uniq_day_1858; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x1350 = kk_integer_from_small(1); /*int*/
  }
  _x_x1349 = kk_integer_box(_x_x1350, _ctx); /*7*/
  _x_x1348 = kk_std_core_types__new_Optional(_x_x1349, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1351;
  kk_box_t _x_x1352;
  kk_integer_t _x_x1353;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x96 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_1862 = kk_integer_unbox(_box_x96, _ctx);
    kk_integer_dup(_uniq_hours_1862, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x1353 = _uniq_hours_1862; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x1353 = kk_integer_from_small(0); /*int*/
  }
  _x_x1352 = kk_integer_box(_x_x1353, _ctx); /*7*/
  _x_x1351 = kk_std_core_types__new_Optional(_x_x1352, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1354;
  kk_box_t _x_x1355;
  kk_integer_t _x_x1356;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x98 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_1866 = kk_integer_unbox(_box_x98, _ctx);
    kk_integer_dup(_uniq_minutes_1866, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x1356 = _uniq_minutes_1866; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x1356 = kk_integer_from_small(0); /*int*/
  }
  _x_x1355 = kk_integer_box(_x_x1356, _ctx); /*7*/
  _x_x1354 = kk_std_core_types__new_Optional(_x_x1355, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1357;
  kk_box_t _x_x1358;
  kk_integer_t _x_x1359;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x100 = secs._cons._Optional.value;
    kk_integer_t _uniq_secs_1870 = kk_integer_unbox(_box_x100, _ctx);
    kk_integer_dup(_uniq_secs_1870, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x1359 = _uniq_secs_1870; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x1359 = kk_integer_from_small(0); /*int*/
  }
  _x_x1358 = kk_integer_box(_x_x1359, _ctx); /*7*/
  _x_x1357 = kk_std_core_types__new_Optional(_x_x1358, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1360;
  kk_box_t _x_x1361;
  double _x_x1362;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x102 = frac._cons._Optional.value;
    double _uniq_frac_1874 = kk_double_unbox(_box_x102, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1362 = _uniq_frac_1874; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x1362 = 0x0p+0; /*float64*/
  }
  _x_x1361 = kk_double_box(_x_x1362, _ctx); /*7*/
  _x_x1360 = kk_std_core_types__new_Optional(_x_x1361, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1363;
  kk_box_t _x_x1364;
  kk_std_time_calendar__timezone _x_x1365;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x104 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_1878 = kk_std_time_calendar__timezone_unbox(_box_x104, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_1878, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1365 = _uniq_tz_1878; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1365 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1364 = kk_std_time_calendar__timezone_box(_x_x1365, _ctx); /*7*/
  _x_x1363 = kk_std_core_types__new_Optional(_x_x1364, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1366;
  kk_box_t _x_x1367;
  kk_std_time_calendar__calendar _x_x1368;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x106 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_1882 = kk_std_time_calendar__calendar_unbox(_box_x106, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_1882, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1368 = _uniq_cal_1882; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1368 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1367 = kk_std_time_calendar__calendar_box(_x_x1368, _ctx); /*7*/
  _x_x1366 = kk_std_core_types__new_Optional(_x_x1367, _ctx); /*? 7*/
  _x_x1344 = kk_std_time_time_timescale_fs_time(x_10411, year_0, _x_x1345, _x_x1348, _x_x1351, _x_x1354, _x_x1357, _x_x1360, _x_x1363, _x_x1366, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1344, _ctx);
}

kk_std_time_time__time kk_std_time_time_time(kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc time */ 
  kk_std_time_instant__timescale x_10411;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x83 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_1889 = kk_std_time_instant__timescale_unbox(_box_x83, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_1889, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10411 = _uniq_ts_1889; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10414 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x1338;
    {
      struct kk_std_core_hnd_Ev* _con_x1339 = kk_std_core_hnd__as_Ev(ev_10414, _ctx);
      kk_box_t _box_x84 = _con_x1339->hnd;
      int32_t m = _con_x1339->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x84, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x762;
      kk_std_core_hnd__clause0 _brw_x763 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x762 = _brw_x763; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x87 = _match_x762.clause;
        _x_x1338 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x87, (_fun_unbox_x87, m, ev_10414, _ctx), _ctx); /*35*/
      }
    }
    x_10411 = kk_std_time_instant__timescale_unbox(_x_x1338, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  kk_box_t _x_x1340;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10411, (KK_I32(10)), _ctx);
    _x_x1340 = kk_std_core_hnd_yield_extend(kk_std_time_time_new_time_fun1341(cal, day_0, frac, hours_0, minutes_0, month_0, secs, tz, year_0, _ctx), _ctx); /*2419*/
  }
  else {
    _x_x1340 = kk_std_core_hnd__open_none0(kk_std_time_time_new_time_fun1343(cal, day_0, frac, hours_0, minutes_0, month_0, secs, tz, x_10411, year_0, _ctx), _ctx); /*2419*/
  }
  return kk_std_time_time__time_unbox(_x_x1340, KK_OWNED, _ctx);
}

kk_std_time_time__time kk_std_time_time_timescale_fs_date_fs_time(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> time */ 
  kk_std_time_instant__instant _x_x1369;
  kk_std_time_calendar__calendar _match_x760;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x120 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2250 = kk_std_time_calendar__calendar_unbox(_box_x120, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2250, _ctx);
    _match_x760 = _uniq_cal_2250; /*std/time/calendar/calendar*/
  }
  else {
    _match_x760 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  {
    struct kk_std_time_calendar_Calendar* _con_x1370 = kk_std_time_calendar__as_Calendar(_match_x760, _ctx);
    kk_string_t _pat_0 = _con_x1370->name;
    kk_string_t _pat_1_0 = _con_x1370->long_name;
    kk_string_t _pat_2_0 = _con_x1370->month_prefix;
    kk_function_t _pat_3_1 = _con_x1370->show_era;
    kk_function_t _pat_4_1 = _con_x1370->instant_to_dc;
    kk_function_t _x = _con_x1370->dc_to_instant;
    kk_function_t _pat_5 = _con_x1370->days_to_date;
    kk_function_t _pat_6 = _con_x1370->date_to_days;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x760, _ctx)) {
      kk_function_drop(_pat_6, _ctx);
      kk_function_drop(_pat_5, _ctx);
      kk_function_drop(_pat_4_1, _ctx);
      kk_function_drop(_pat_3_1, _ctx);
      kk_string_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_match_x760, _ctx);
    }
    else {
      kk_function_dup(_x, _ctx);
      kk_datatype_ptr_decref(_match_x760, _ctx);
    }
    kk_std_time_date__clock _x_x1371;
    if (kk_std_core_types__is_Optional(c, _ctx)) {
      kk_box_t _box_x121 = c._cons._Optional.value;
      kk_std_time_date__clock _uniq_c_2242 = kk_std_time_date__clock_unbox(_box_x121, KK_BORROWED, _ctx);
      kk_std_time_date__clock_dup(_uniq_c_2242, _ctx);
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1371 = _uniq_c_2242; /*std/time/date/clock*/
    }
    else {
      kk_std_core_types__optional_drop(c, _ctx);
      _x_x1371 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    }
    kk_std_time_calendar__timezone _x_x1372;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x122 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_2246 = kk_std_time_calendar__timezone_unbox(_box_x122, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_2246, _ctx);
      _x_x1372 = _uniq_tz_2246; /*std/time/calendar/timezone*/
    }
    else {
      _x_x1372 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    kk_std_time_instant__timescale _x_x1373 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
    _x_x1369 = kk_function_call(kk_std_time_instant__instant, (kk_function_t, kk_std_time_date__date, kk_std_time_date__clock, kk_std_time_calendar__timezone, kk_std_time_instant__timescale, kk_context_t*), _x, (_x, d, _x_x1371, _x_x1372, _x_x1373, _ctx), _ctx); /*std/time/instant/instant*/
  }
  kk_std_core_types__optional _x_x1374;
  kk_box_t _x_x1375;
  kk_std_time_calendar__timezone _x_x1376;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x123 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_2246_0 = kk_std_time_calendar__timezone_unbox(_box_x123, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_2246_0, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1376 = _uniq_tz_2246_0; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1376 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1375 = kk_std_time_calendar__timezone_box(_x_x1376, _ctx); /*7*/
  _x_x1374 = kk_std_core_types__new_Optional(_x_x1375, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1377;
  kk_box_t _x_x1378;
  kk_std_time_calendar__calendar _x_x1379;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x125 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2250_0 = kk_std_time_calendar__calendar_unbox(_box_x125, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2250_0, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1379 = _uniq_cal_2250_0; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1379 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1378 = kk_std_time_calendar__calendar_box(_x_x1379, _ctx); /*7*/
  _x_x1377 = kk_std_core_types__new_Optional(_x_x1378, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1380 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(ts, _ctx), _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x1369, _x_x1374, _x_x1377, _x_x1380, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_time_date_fs__mlift_time_10406_fun1382__t {
  struct kk_function_s _base;
  kk_std_time_instant__timescale _c_x10332;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_time_date_fs__mlift_time_10406_fun1382(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_date_fs__new_mlift_time_10406_fun1382(kk_std_time_instant__timescale _c_x10332, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_time_date_fs__mlift_time_10406_fun1382__t* _self = kk_function_alloc_as(struct kk_std_time_time_date_fs__mlift_time_10406_fun1382__t, 11, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_date_fs__mlift_time_10406_fun1382, kk_context());
  _self->_c_x10332 = _c_x10332;
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_date_fs__mlift_time_10406_fun1382(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_date_fs__mlift_time_10406_fun1382__t* _self = kk_function_as(struct kk_std_time_time_date_fs__mlift_time_10406_fun1382__t*, _fself, _ctx);
  kk_std_time_instant__timescale _c_x10332 = _self->_c_x10332; /* std/time/instant/timescale */
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_time_instant__timescale_dup(_c_x10332, _ctx);kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1383;
  kk_std_core_types__optional _x_x1384;
  kk_box_t _x_x1385;
  kk_std_time_date__clock _x_x1386;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x131 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_1974 = kk_std_time_date__clock_unbox(_box_x131, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_1974, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x1386 = _uniq_c_1974; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x1386 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x1385 = kk_std_time_date__clock_box(_x_x1386, _ctx); /*7*/
  _x_x1384 = kk_std_core_types__new_Optional(_x_x1385, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1387;
  kk_box_t _x_x1388;
  kk_std_time_calendar__timezone _x_x1389;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x133 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_1978 = kk_std_time_calendar__timezone_unbox(_box_x133, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_1978, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1389 = _uniq_tz_1978; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1389 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1388 = kk_std_time_calendar__timezone_box(_x_x1389, _ctx); /*7*/
  _x_x1387 = kk_std_core_types__new_Optional(_x_x1388, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1390;
  kk_box_t _x_x1391;
  kk_std_time_calendar__calendar _x_x1392;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x135 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_1982 = kk_std_time_calendar__calendar_unbox(_box_x135, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_1982, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1392 = _uniq_cal_1982; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1392 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1391 = kk_std_time_calendar__calendar_box(_x_x1392, _ctx); /*7*/
  _x_x1390 = kk_std_core_types__new_Optional(_x_x1391, _ctx); /*? 7*/
  _x_x1383 = kk_std_time_time_timescale_fs_date_fs_time(_c_x10332, d, _x_x1384, _x_x1387, _x_x1390, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1383, _ctx);
}

kk_std_time_time__time kk_std_time_time_date_fs__mlift_time_10406(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10332, kk_context_t* _ctx) { /* (c : ? std/time/date/clock, cal : ? std/time/calendar/calendar, d : std/time/date/date, tz : ? std/time/calendar/timezone, std/time/instant/timescale) -> time */ 
  kk_box_t _x_x1381 = kk_std_core_hnd__open_none0(kk_std_time_time_date_fs__new_mlift_time_10406_fun1382(_c_x10332, c, cal, d, tz, _ctx), _ctx); /*9836*/
  return kk_std_time_time__time_unbox(_x_x1381, KK_OWNED, _ctx);
}
 
// Return the `:time` value for a given `:date` and `:clock` (=`clock0`) in a timezone `tz` (=`tz-utc` by default)
// interpreted by calendar `cal` (=`cal-iso`)


// lift anonymous function
struct kk_std_time_time_date_fs_time_fun1396__t {
  struct kk_function_s _base;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_time_date_fs_time_fun1396(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_date_fs_new_time_fun1396(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_time_date_fs_time_fun1396__t* _self = kk_function_alloc_as(struct kk_std_time_time_date_fs_time_fun1396__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_date_fs_time_fun1396, kk_context());
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_date_fs_time_fun1396(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  struct kk_std_time_time_date_fs_time_fun1396__t* _self = kk_function_as(struct kk_std_time_time_date_fs_time_fun1396__t*, _fself, _ctx);
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10332_163 = kk_std_time_instant__timescale_unbox(_b_x150, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_time__time _x_x1397 = kk_std_time_time_date_fs__mlift_time_10406(c, cal, d, tz, _c_x10332_163, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1397, _ctx);
}


// lift anonymous function
struct kk_std_time_time_date_fs_time_fun1398__t {
  struct kk_function_s _base;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_core_types__optional tz;
  kk_std_time_instant__timescale x_10416;
};
static kk_box_t kk_std_time_time_date_fs_time_fun1398(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_date_fs_new_time_fun1398(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_core_types__optional tz, kk_std_time_instant__timescale x_10416, kk_context_t* _ctx) {
  struct kk_std_time_time_date_fs_time_fun1398__t* _self = kk_function_alloc_as(struct kk_std_time_time_date_fs_time_fun1398__t, 11, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_date_fs_time_fun1398, kk_context());
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->tz = tz;
  _self->x_10416 = x_10416;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_date_fs_time_fun1398(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_date_fs_time_fun1398__t* _self = kk_function_as(struct kk_std_time_time_date_fs_time_fun1398__t*, _fself, _ctx);
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_std_time_instant__timescale x_10416 = _self->x_10416; /* std/time/instant/timescale */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_core_types__optional_dup(tz, _ctx);kk_std_time_instant__timescale_dup(x_10416, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x1399;
  kk_std_core_types__optional _x_x1400;
  kk_box_t _x_x1401;
  kk_std_time_date__clock _x_x1402;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x151 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_1974 = kk_std_time_date__clock_unbox(_box_x151, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_1974, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x1402 = _uniq_c_1974; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x1402 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x1401 = kk_std_time_date__clock_box(_x_x1402, _ctx); /*7*/
  _x_x1400 = kk_std_core_types__new_Optional(_x_x1401, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1403;
  kk_box_t _x_x1404;
  kk_std_time_calendar__timezone _x_x1405;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x153 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_1978 = kk_std_time_calendar__timezone_unbox(_box_x153, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_1978, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1405 = _uniq_tz_1978; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1405 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1404 = kk_std_time_calendar__timezone_box(_x_x1405, _ctx); /*7*/
  _x_x1403 = kk_std_core_types__new_Optional(_x_x1404, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1406;
  kk_box_t _x_x1407;
  kk_std_time_calendar__calendar _x_x1408;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x155 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_1982 = kk_std_time_calendar__calendar_unbox(_box_x155, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_1982, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1408 = _uniq_cal_1982; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1408 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1407 = kk_std_time_calendar__calendar_box(_x_x1408, _ctx); /*7*/
  _x_x1406 = kk_std_core_types__new_Optional(_x_x1407, _ctx); /*? 7*/
  _x_x1399 = kk_std_time_time_timescale_fs_date_fs_time(x_10416, d, _x_x1400, _x_x1403, _x_x1406, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1399, _ctx);
}

kk_std_time_time__time kk_std_time_time_date_fs_time(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (d : std/time/date/date, c : ? std/time/date/clock, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> std/time/utc/utc time */ 
  kk_std_time_instant__timescale x_10416;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x142 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_1989 = kk_std_time_instant__timescale_unbox(_box_x142, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_1989, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10416 = _uniq_ts_1989; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10419 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x1393;
    {
      struct kk_std_core_hnd_Ev* _con_x1394 = kk_std_core_hnd__as_Ev(ev_10419, _ctx);
      kk_box_t _box_x143 = _con_x1394->hnd;
      int32_t m = _con_x1394->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x143, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x758;
      kk_std_core_hnd__clause0 _brw_x759 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x758 = _brw_x759; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x146 = _match_x758.clause;
        _x_x1393 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x146, (_fun_unbox_x146, m, ev_10419, _ctx), _ctx); /*35*/
      }
    }
    x_10416 = kk_std_time_instant__timescale_unbox(_x_x1393, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  kk_box_t _x_x1395;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10416, (KK_I32(10)), _ctx);
    _x_x1395 = kk_std_core_hnd_yield_extend(kk_std_time_time_date_fs_new_time_fun1396(c, cal, d, tz, _ctx), _ctx); /*2419*/
  }
  else {
    _x_x1395 = kk_std_core_hnd__open_none0(kk_std_time_time_date_fs_new_time_fun1398(c, cal, d, tz, x_10416, _ctx), _ctx); /*2419*/
  }
  return kk_std_time_time__time_unbox(_x_x1395, KK_OWNED, _ctx);
}
 
// Convert a `:time` `t` to a new `:time` value in a potentially different
// timezone `tz` (=`t.timezone` by default) and calendar (=`t.calendar` by default).

kk_std_time_time__time kk_std_time_time_time_fs_time(kk_std_time_time__time t, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (t : time, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 
  kk_std_time_instant__instant _x_x1409;
  {
    struct kk_std_time_time_Time* _con_x1410 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_4 = _con_x1410->date;
    kk_std_time_date__clock _pat_4_4 = _con_x1410->clock;
    kk_std_time_calendar__calendar _pat_8_3 = _con_x1410->calendar;
    kk_std_time_duration__duration _pat_17_2 = _con_x1410->tzdelta;
    kk_std_time_calendar__timezone _pat_20_2 = _con_x1410->timezone;
    kk_std_time_instant__instant _x_3 = _con_x1410->instant;
    struct kk_std_time_date_Clock* _con_x1411 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1412 = kk_std_time_calendar__as_Calendar(_pat_8_3, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1413 = kk_std_time_calendar__as_Timezone(_pat_20_2, _ctx);
    kk_std_time_instant__instant_dup(_x_3, _ctx);
    _x_x1409 = _x_3; /*std/time/instant/instant*/
  }
  kk_std_core_types__optional _x_x1414;
  kk_box_t _x_x1415;
  kk_std_time_calendar__timezone _x_x1416;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x164 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_2036 = kk_std_time_calendar__timezone_unbox(_box_x164, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_2036, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1416 = _uniq_tz_2036; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1417 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0 = _con_x1417->date;
      kk_std_time_date__clock _pat_4 = _con_x1417->clock;
      kk_std_time_calendar__calendar _pat_8 = _con_x1417->calendar;
      kk_std_time_duration__duration _pat_17 = _con_x1417->tzdelta;
      kk_std_time_calendar__timezone _x = _con_x1417->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1417->instant;
      struct kk_std_time_date_Clock* _con_x1418 = kk_std_time_date__as_Clock(_pat_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1419 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1420 = kk_std_time_calendar__as_Timezone(_x, _ctx);
      kk_std_time_calendar__timezone_dup(_x, _ctx);
      _x_x1416 = _x; /*std/time/calendar/timezone*/
    }
  }
  _x_x1415 = kk_std_time_calendar__timezone_box(_x_x1416, _ctx); /*7*/
  _x_x1414 = kk_std_core_types__new_Optional(_x_x1415, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1421;
  kk_box_t _x_x1422;
  kk_std_time_calendar__calendar _x_x1423;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x166 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_2044 = kk_std_time_calendar__calendar_unbox(_box_x166, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_2044, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1423 = _uniq_cal_2044; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1424 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_1 = _con_x1424->date;
      kk_std_time_date__clock _pat_4_0 = _con_x1424->clock;
      kk_std_time_calendar__calendar _x_0 = _con_x1424->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1424->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1424->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1424->instant;
      struct kk_std_time_date_Clock* _con_x1425 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1426 = kk_std_time_calendar__as_Calendar(_x_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1427 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_calendar__calendar_dup(_x_0, _ctx);
      _x_x1423 = _x_0; /*std/time/calendar/calendar*/
    }
  }
  _x_x1422 = kk_std_time_calendar__calendar_box(_x_x1423, _ctx); /*7*/
  _x_x1421 = kk_std_core_types__new_Optional(_x_x1422, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1428;
  kk_box_t _x_x1429;
  kk_std_time_instant__timescale _x_x1430;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x168 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_2056 = kk_std_time_instant__timescale_unbox(_box_x168, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_2056, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    _x_x1430 = _uniq_ts_2056; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1431 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x1431->date;
      kk_std_time_date__clock _pat_4_3 = _con_x1431->clock;
      kk_std_time_calendar__calendar _pat_8_2 = _con_x1431->calendar;
      kk_std_time_duration__duration _pat_17_1 = _con_x1431->tzdelta;
      kk_std_time_calendar__timezone _pat_20_1 = _con_x1431->timezone;
      kk_std_time_instant__instant _x_2 = _con_x1431->instant;
      struct kk_std_time_date_Clock* _con_x1432 = kk_std_time_date__as_Clock(_pat_4_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1433 = kk_std_time_calendar__as_Calendar(_pat_8_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1434 = kk_std_time_calendar__as_Timezone(_pat_20_1, _ctx);
      kk_string_t _pat_19_1 = _con_x1431->tzabbrv;
      kk_integer_t _pat_5_2 = _con_x1432->hours;
      kk_integer_t _pat_6_2 = _con_x1432->minutes;
      kk_string_t _pat_9_2 = _con_x1433->name;
      kk_string_t _pat_10_1 = _con_x1433->long_name;
      kk_string_t _pat_11_1 = _con_x1433->month_prefix;
      kk_function_t _pat_12_1 = _con_x1433->show_era;
      kk_function_t _pat_13_1 = _con_x1433->instant_to_dc;
      kk_function_t _pat_14_1 = _con_x1433->dc_to_instant;
      kk_function_t _pat_15_1 = _con_x1433->days_to_date;
      kk_function_t _pat_16_1 = _con_x1433->date_to_days;
      kk_string_t _pat_21_1 = _con_x1434->name;
      kk_function_t _pat_22_1 = _con_x1434->utc_delta;
      kk_function_t _pat_23_1 = _con_x1434->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_8_2, _ctx)) {
          kk_string_drop(_pat_9_2, _ctx);
          kk_function_drop(_pat_16_1, _ctx);
          kk_function_drop(_pat_15_1, _ctx);
          kk_function_drop(_pat_14_1, _ctx);
          kk_function_drop(_pat_13_1, _ctx);
          kk_function_drop(_pat_12_1, _ctx);
          kk_string_drop(_pat_11_1, _ctx);
          kk_string_drop(_pat_10_1, _ctx);
          kk_datatype_ptr_free(_pat_8_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_8_2, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_3, _ctx)) {
          kk_integer_drop(_pat_6_2, _ctx);
          kk_integer_drop(_pat_5_2, _ctx);
          kk_datatype_ptr_free(_pat_4_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_3, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_20_1, _ctx)) {
          kk_function_drop(_pat_23_1, _ctx);
          kk_function_drop(_pat_22_1, _ctx);
          kk_string_drop(_pat_21_1, _ctx);
          kk_datatype_ptr_free(_pat_20_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_20_1, _ctx);
        }
        kk_string_drop(_pat_19_1, _ctx);
        kk_std_time_date__date_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_instant__instant_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        kk_std_time_timestamp__timestamp _pat_0_2 = _x_2.since;
        kk_std_time_instant__timescale _x_1 = _x_2.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1435 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1436 = kk_std_time_instant__as_Timescale(_x_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_1, _ctx);
        kk_std_time_instant__instant_drop(_x_2, _ctx);
        _x_x1430 = _x_1; /*std/time/instant/timescale*/
      }
    }
  }
  _x_x1429 = kk_std_time_instant__timescale_box(_x_x1430, _ctx); /*7*/
  _x_x1428 = kk_std_core_types__new_Optional(_x_x1429, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x1409, _x_x1414, _x_x1421, _x_x1428, _ctx);
}
 
// Round a time to a specified second precision.

kk_std_time_time__time kk_std_time_time_round_to_prec(kk_std_time_time__time t, kk_integer_t prec, kk_context_t* _ctx) { /* (t : time, prec : int) -> time */ 
  bool _match_x745 = kk_integer_lt_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x745) {
    kk_integer_drop(prec, _ctx);
    return t;
  }
  {
    kk_std_num_ddouble__ddouble secs;
    kk_std_num_ddouble__ddouble _x_x1437;
    {
      struct kk_std_time_time_Time* _con_x1438 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0 = _con_x1438->date;
      kk_std_time_date__clock _x = _con_x1438->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x1438->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x1438->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x1438->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1438->instant;
      struct kk_std_time_date_Clock* _con_x1439 = kk_std_time_date__as_Clock(_x, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1440 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1441 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_date__clock_dup(_x, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x1442 = kk_std_time_date__as_Clock(_x, _ctx);
        kk_std_num_ddouble__ddouble _x_0 = _con_x1442->seconds;
        kk_integer_t _pat_0_1 = _con_x1442->hours;
        kk_integer_t _pat_1_1 = _con_x1442->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
          kk_integer_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(_x, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x, _ctx);
        }
        _x_x1437 = _x_0; /*std/num/ddouble/ddouble*/
      }
    }
    kk_integer_t _x_x1443 = kk_integer_dup(prec, _ctx); /*int*/
    secs = kk_std_num_ddouble_round_to_prec(_x_x1437, _x_x1443, _ctx); /*std/num/ddouble/ddouble*/
    kk_std_time_instant__instant ri;
    kk_std_time_instant__instant _x_x1444;
    {
      struct kk_std_time_time_Time* _con_x1445 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_2 = _con_x1445->date;
      kk_std_time_date__clock _pat_4_0 = _con_x1445->clock;
      kk_std_time_calendar__calendar _pat_8_0 = _con_x1445->calendar;
      kk_std_time_duration__duration _pat_17_0 = _con_x1445->tzdelta;
      kk_std_time_calendar__timezone _pat_20_0 = _con_x1445->timezone;
      kk_std_time_instant__instant _x_1 = _con_x1445->instant;
      struct kk_std_time_date_Clock* _con_x1446 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1447 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1448 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
      kk_std_time_instant__instant_dup(_x_1, _ctx);
      _x_x1444 = _x_1; /*std/time/instant/instant*/
    }
    ri = kk_std_time_instant_round_to_prec(_x_x1444, prec, _ctx); /*std/time/instant/instant*/
    kk_std_num_ddouble__ddouble x_10072;
    bool _match_x756;
    double _x_x1449;
    {
      double _x_3 = secs.hi;
      _x_x1449 = _x_3; /*float64*/
    }
    _match_x756 = (_x_x1449 < (0x0p+0)); /*bool*/
    if (_match_x756) {
      x_10072 = kk_std_num_ddouble_ceiling(secs, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      x_10072 = kk_std_num_ddouble_floor(secs, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_num_ddouble__ddouble y_10073;
    bool _match_x755;
    double _x_x1450;
    {
      struct kk_std_time_time_Time* _con_x1451 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_7 = _con_x1451->date;
      kk_std_time_date__clock _x_6 = _con_x1451->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x1451->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x1451->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x1451->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x1451->instant;
      struct kk_std_time_date_Clock* _con_x1452 = kk_std_time_date__as_Clock(_x_6, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1453 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1454 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_date__clock_dup(_x_6, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x1455 = kk_std_time_date__as_Clock(_x_6, _ctx);
        kk_std_num_ddouble__ddouble _x_5 = _con_x1455->seconds;
        kk_integer_t _pat_0_6 = _con_x1455->hours;
        kk_integer_t _pat_1_6 = _con_x1455->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_6, _ctx)) {
          kk_integer_drop(_pat_1_6, _ctx);
          kk_integer_drop(_pat_0_6, _ctx);
          kk_datatype_ptr_free(_x_6, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_6, _ctx);
        }
        {
          double _x_4 = _x_5.hi;
          _x_x1450 = _x_4; /*float64*/
        }
      }
    }
    _match_x755 = (_x_x1450 < (0x0p+0)); /*bool*/
    if (_match_x755) {
      kk_std_num_ddouble__ddouble _x_x1456;
      {
        struct kk_std_time_time_Time* _con_x1457 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _pat_0_7_0 = _con_x1457->date;
        kk_std_time_date__clock _x_6_0 = _con_x1457->clock;
        kk_std_time_calendar__calendar _pat_7_1_0 = _con_x1457->calendar;
        kk_std_time_duration__duration _pat_16_1_0 = _con_x1457->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1_0 = _con_x1457->timezone;
        kk_std_time_instant__instant _pat_23_1_0 = _con_x1457->instant;
        struct kk_std_time_date_Clock* _con_x1458 = kk_std_time_date__as_Clock(_x_6_0, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1459 = kk_std_time_calendar__as_Calendar(_pat_7_1_0, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1460 = kk_std_time_calendar__as_Timezone(_pat_19_1_0, _ctx);
        kk_std_time_date__clock_dup(_x_6_0, _ctx);
        {
          struct kk_std_time_date_Clock* _con_x1461 = kk_std_time_date__as_Clock(_x_6_0, _ctx);
          kk_std_num_ddouble__ddouble _x_5_0 = _con_x1461->seconds;
          kk_integer_t _pat_0_6_0 = _con_x1461->hours;
          kk_integer_t _pat_1_6_0 = _con_x1461->minutes;
          if kk_likely(kk_datatype_ptr_is_unique(_x_6_0, _ctx)) {
            kk_integer_drop(_pat_1_6_0, _ctx);
            kk_integer_drop(_pat_0_6_0, _ctx);
            kk_datatype_ptr_free(_x_6_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_6_0, _ctx);
          }
          _x_x1456 = _x_5_0; /*std/num/ddouble/ddouble*/
        }
      }
      y_10073 = kk_std_num_ddouble_ceiling(_x_x1456, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1462;
      {
        struct kk_std_time_time_Time* _con_x1463 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _pat_0_7_1 = _con_x1463->date;
        kk_std_time_date__clock _x_6_1 = _con_x1463->clock;
        kk_std_time_calendar__calendar _pat_7_1_1 = _con_x1463->calendar;
        kk_std_time_duration__duration _pat_16_1_1 = _con_x1463->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1_1 = _con_x1463->timezone;
        kk_std_time_instant__instant _pat_23_1_1 = _con_x1463->instant;
        struct kk_std_time_date_Clock* _con_x1464 = kk_std_time_date__as_Clock(_x_6_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1465 = kk_std_time_calendar__as_Calendar(_pat_7_1_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1466 = kk_std_time_calendar__as_Timezone(_pat_19_1_1, _ctx);
        kk_std_time_date__clock_dup(_x_6_1, _ctx);
        {
          struct kk_std_time_date_Clock* _con_x1467 = kk_std_time_date__as_Clock(_x_6_1, _ctx);
          kk_std_num_ddouble__ddouble _x_5_1 = _con_x1467->seconds;
          kk_integer_t _pat_0_6_1 = _con_x1467->hours;
          kk_integer_t _pat_1_6_1 = _con_x1467->minutes;
          if kk_likely(kk_datatype_ptr_is_unique(_x_6_1, _ctx)) {
            kk_integer_drop(_pat_1_6_1, _ctx);
            kk_integer_drop(_pat_0_6_1, _ctx);
            kk_datatype_ptr_free(_x_6_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_6_1, _ctx);
          }
          _x_x1462 = _x_5_1; /*std/num/ddouble/ddouble*/
        }
      }
      y_10073 = kk_std_num_ddouble_floor(_x_x1462, _ctx); /*std/num/ddouble/ddouble*/
    }
    bool _match_x746;
    kk_std_core_types__order _x_x1468;
    kk_std_core_types__order _match_x754;
    double _x_x1469;
    {
      double _x_2 = x_10072.hi;
      _x_x1469 = _x_2; /*float64*/
    }
    double _x_x1470;
    {
      double _x_0_0 = y_10073.hi;
      _x_x1470 = _x_0_0; /*float64*/
    }
    _match_x754 = kk_std_num_float64_cmp(_x_x1469, _x_x1470, _ctx); /*order*/
    if (kk_std_core_types__is_Eq(_match_x754, _ctx)) {
      double _x_x1471;
      {
        double _x_1_0 = x_10072.lo;
        _x_x1471 = _x_1_0; /*float64*/
      }
      double _x_x1472;
      {
        double _x_2_0 = y_10073.lo;
        _x_x1472 = _x_2_0; /*float64*/
      }
      _x_x1468 = kk_std_num_float64_cmp(_x_x1471, _x_x1472, _ctx); /*order*/
    }
    else {
      _x_x1468 = _match_x754; /*order*/
    }
    _match_x746 = kk_std_core_order__lp__eq__eq__rp_(_x_x1468, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
    if (_match_x746) {
      kk_std_time_date__date _x_x1473;
      kk_std_core_types__optional _match_x753 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x753, _ctx)) {
        kk_box_t _box_x173 = _match_x753._cons._Optional.value;
        kk_std_time_date__date _uniq_date_286 = kk_std_time_date__date_unbox(_box_x173, KK_BORROWED, _ctx);
        kk_std_time_date__date_dup(_uniq_date_286, _ctx);
        kk_std_core_types__optional_drop(_match_x753, _ctx);
        _x_x1473 = _uniq_date_286; /*std/time/date/date*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x753, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1474 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _x_7 = _con_x1474->date;
          kk_std_time_date__clock _pat_3_5 = _con_x1474->clock;
          kk_std_time_calendar__calendar _pat_7_2 = _con_x1474->calendar;
          kk_std_time_duration__duration _pat_16_2 = _con_x1474->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2 = _con_x1474->timezone;
          kk_std_time_instant__instant _pat_23_2 = _con_x1474->instant;
          struct kk_std_time_date_Clock* _con_x1475 = kk_std_time_date__as_Clock(_pat_3_5, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1476 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1477 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
          kk_std_time_date__date_dup(_x_7, _ctx);
          _x_x1473 = _x_7; /*std/time/date/date*/
        }
      }
      kk_std_time_date__clock _x_x1478;
      kk_integer_t _x_x1479;
      kk_std_core_types__optional _match_x752 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x752, _ctx)) {
        kk_box_t _box_x174 = _match_x752._cons._Optional.value;
        kk_integer_t _uniq_hours_2877 = kk_integer_unbox(_box_x174, _ctx);
        kk_integer_dup(_uniq_hours_2877, _ctx);
        kk_std_core_types__optional_drop(_match_x752, _ctx);
        _x_x1479 = _uniq_hours_2877; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x752, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1480 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_0_3_0 = _con_x1480->date;
          kk_std_time_date__clock _x_7_0 = _con_x1480->clock;
          kk_std_time_calendar__calendar _pat_7_2_1 = _con_x1480->calendar;
          kk_std_time_duration__duration _pat_16_2_1 = _con_x1480->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2_1 = _con_x1480->timezone;
          kk_std_time_instant__instant _pat_23_2_1 = _con_x1480->instant;
          struct kk_std_time_date_Clock* _con_x1481 = kk_std_time_date__as_Clock(_x_7_0, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1482 = kk_std_time_calendar__as_Calendar(_pat_7_2_1, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1483 = kk_std_time_calendar__as_Timezone(_pat_19_2_1, _ctx);
          kk_std_time_date__clock_dup(_x_7_0, _ctx);
          {
            struct kk_std_time_date_Clock* _con_x1484 = kk_std_time_date__as_Clock(_x_7_0, _ctx);
            kk_std_num_ddouble__ddouble _pat_1_0_0_0_0 = _con_x1484->seconds;
            kk_integer_t _x_7_0_0 = _con_x1484->hours;
            kk_integer_t _pat_0_0_3_0_0 = _con_x1484->minutes;
            if kk_likely(kk_datatype_ptr_is_unique(_x_7_0, _ctx)) {
              kk_integer_drop(_pat_0_0_3_0_0, _ctx);
              kk_datatype_ptr_free(_x_7_0, _ctx);
            }
            else {
              kk_integer_dup(_x_7_0_0, _ctx);
              kk_datatype_ptr_decref(_x_7_0, _ctx);
            }
            _x_x1479 = _x_7_0_0; /*int*/
          }
        }
      }
      kk_integer_t _x_x1485;
      kk_std_core_types__optional _match_x751 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x751, _ctx)) {
        kk_box_t _box_x175 = _match_x751._cons._Optional.value;
        kk_integer_t _uniq_minutes_2885 = kk_integer_unbox(_box_x175, _ctx);
        kk_integer_dup(_uniq_minutes_2885, _ctx);
        kk_std_core_types__optional_drop(_match_x751, _ctx);
        _x_x1485 = _uniq_minutes_2885; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x751, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1486 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_0_4 = _con_x1486->date;
          kk_std_time_date__clock _x_8 = _con_x1486->clock;
          kk_std_time_calendar__calendar _pat_7_3_0 = _con_x1486->calendar;
          kk_std_time_duration__duration _pat_16_3_0 = _con_x1486->tzdelta;
          kk_std_time_calendar__timezone _pat_19_3_0 = _con_x1486->timezone;
          kk_std_time_instant__instant _pat_23_3_0 = _con_x1486->instant;
          struct kk_std_time_date_Clock* _con_x1487 = kk_std_time_date__as_Clock(_x_8, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1488 = kk_std_time_calendar__as_Calendar(_pat_7_3_0, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1489 = kk_std_time_calendar__as_Timezone(_pat_19_3_0, _ctx);
          kk_std_time_date__clock_dup(_x_8, _ctx);
          {
            struct kk_std_time_date_Clock* _con_x1490 = kk_std_time_date__as_Clock(_x_8, _ctx);
            kk_std_num_ddouble__ddouble _pat_1_2_0_0 = _con_x1490->seconds;
            kk_integer_t _pat_0_1_1_0 = _con_x1490->hours;
            kk_integer_t _x_0_1_0 = _con_x1490->minutes;
            if kk_likely(kk_datatype_ptr_is_unique(_x_8, _ctx)) {
              kk_integer_drop(_pat_0_1_1_0, _ctx);
              kk_datatype_ptr_free(_x_8, _ctx);
            }
            else {
              kk_integer_dup(_x_0_1_0, _ctx);
              kk_datatype_ptr_decref(_x_8, _ctx);
            }
            _x_x1485 = _x_0_1_0; /*int*/
          }
        }
      }
      _x_x1478 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x1479, _x_x1485, secs, _ctx); /*std/time/date/clock*/
      kk_std_time_calendar__calendar _x_x1491;
      kk_std_core_types__optional _match_x750 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x750, _ctx)) {
        kk_box_t _box_x176 = _match_x750._cons._Optional.value;
        kk_std_time_calendar__calendar _uniq_calendar_302 = kk_std_time_calendar__calendar_unbox(_box_x176, KK_BORROWED, _ctx);
        kk_std_time_calendar__calendar_dup(_uniq_calendar_302, _ctx);
        kk_std_core_types__optional_drop(_match_x750, _ctx);
        _x_x1491 = _uniq_calendar_302; /*std/time/calendar/calendar*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x750, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1492 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_2_1 = _con_x1492->date;
          kk_std_time_date__clock _pat_4_2_2 = _con_x1492->clock;
          kk_std_time_calendar__calendar _x_1_1 = _con_x1492->calendar;
          kk_std_time_duration__duration _pat_16_1_2 = _con_x1492->tzdelta;
          kk_std_time_calendar__timezone _pat_19_1_2 = _con_x1492->timezone;
          kk_std_time_instant__instant _pat_23_1_2 = _con_x1492->instant;
          struct kk_std_time_date_Clock* _con_x1493 = kk_std_time_date__as_Clock(_pat_4_2_2, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1494 = kk_std_time_calendar__as_Calendar(_x_1_1, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1495 = kk_std_time_calendar__as_Timezone(_pat_19_1_2, _ctx);
          kk_std_time_calendar__calendar_dup(_x_1_1, _ctx);
          _x_x1491 = _x_1_1; /*std/time/calendar/calendar*/
        }
      }
      kk_std_time_duration__duration _x_x1496;
      kk_std_core_types__optional _match_x749 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x749, _ctx)) {
        kk_box_t _box_x177 = _match_x749._cons._Optional.value;
        kk_std_time_duration__duration _uniq_tzdelta_310 = kk_std_time_duration__duration_unbox(_box_x177, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x749, _ctx);
        _x_x1496 = _uniq_tzdelta_310; /*std/time/duration/duration*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x749, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1497 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_3_0 = _con_x1497->date;
          kk_std_time_date__clock _pat_4_3_0 = _con_x1497->clock;
          kk_std_time_calendar__calendar _pat_8_2_0 = _con_x1497->calendar;
          kk_std_time_duration__duration _x_2_1 = _con_x1497->tzdelta;
          kk_std_time_calendar__timezone _pat_19_2_0 = _con_x1497->timezone;
          kk_std_time_instant__instant _pat_23_2_0 = _con_x1497->instant;
          struct kk_std_time_date_Clock* _con_x1498 = kk_std_time_date__as_Clock(_pat_4_3_0, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1499 = kk_std_time_calendar__as_Calendar(_pat_8_2_0, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1500 = kk_std_time_calendar__as_Timezone(_pat_19_2_0, _ctx);
          _x_x1496 = _x_2_1; /*std/time/duration/duration*/
        }
      }
      kk_string_t _x_x1501;
      kk_std_core_types__optional _match_x748 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x748, _ctx)) {
        kk_box_t _box_x178 = _match_x748._cons._Optional.value;
        kk_string_t _uniq_tzabbrv_318 = kk_string_unbox(_box_x178);
        kk_string_dup(_uniq_tzabbrv_318, _ctx);
        kk_std_core_types__optional_drop(_match_x748, _ctx);
        _x_x1501 = _uniq_tzabbrv_318; /*string*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x748, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1502 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_4_0 = _con_x1502->date;
          kk_std_time_date__clock _pat_4_4 = _con_x1502->clock;
          kk_std_time_calendar__calendar _pat_8_4 = _con_x1502->calendar;
          kk_std_time_duration__duration _pat_17_3 = _con_x1502->tzdelta;
          kk_std_time_calendar__timezone _pat_19_3 = _con_x1502->timezone;
          kk_std_time_instant__instant _pat_23_3 = _con_x1502->instant;
          struct kk_std_time_date_Clock* _con_x1503 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1504 = kk_std_time_calendar__as_Calendar(_pat_8_4, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1505 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
          kk_string_t _x_3_0 = _con_x1502->tzabbrv;
          kk_string_dup(_x_3_0, _ctx);
          _x_x1501 = _x_3_0; /*string*/
        }
      }
      kk_std_time_calendar__timezone _x_x1506;
      kk_std_core_types__optional _match_x747 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x747, _ctx)) {
        kk_box_t _box_x179 = _match_x747._cons._Optional.value;
        kk_std_time_calendar__timezone _uniq_timezone_326 = kk_std_time_calendar__timezone_unbox(_box_x179, KK_BORROWED, _ctx);
        kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
        kk_std_time_calendar__timezone_dup(_uniq_timezone_326, _ctx);
        kk_std_core_types__optional_drop(_match_x747, _ctx);
        _x_x1506 = _uniq_timezone_326; /*std/time/calendar/timezone*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x747, _ctx);
        {
          struct kk_std_time_time_Time* _con_x1507 = kk_std_time_time__as_Time(t, _ctx);
          kk_std_time_date__date _pat_0_5_0 = _con_x1507->date;
          kk_std_time_date__clock _pat_4_5 = _con_x1507->clock;
          kk_std_time_calendar__calendar _pat_8_5 = _con_x1507->calendar;
          kk_std_time_duration__duration _pat_17_4 = _con_x1507->tzdelta;
          kk_std_time_calendar__timezone _x_4_0 = _con_x1507->timezone;
          kk_std_time_instant__instant _pat_23_4 = _con_x1507->instant;
          struct kk_std_time_date_Clock* _con_x1508 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1509 = kk_std_time_calendar__as_Calendar(_pat_8_5, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1510 = kk_std_time_calendar__as_Timezone(_x_4_0, _ctx);
          kk_string_t _pat_19_4 = _con_x1507->tzabbrv;
          kk_integer_t _pat_5_5 = _con_x1508->hours;
          kk_integer_t _pat_6_5 = _con_x1508->minutes;
          kk_string_t _pat_9_5 = _con_x1509->name;
          kk_string_t _pat_10_5 = _con_x1509->long_name;
          kk_string_t _pat_11_4 = _con_x1509->month_prefix;
          kk_function_t _pat_12_4 = _con_x1509->show_era;
          kk_function_t _pat_13_4 = _con_x1509->instant_to_dc;
          kk_function_t _pat_14_4 = _con_x1509->dc_to_instant;
          kk_function_t _pat_15_4 = _con_x1509->days_to_date;
          kk_function_t _pat_16_4 = _con_x1509->date_to_days;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_8_5, _ctx)) {
              kk_string_drop(_pat_9_5, _ctx);
              kk_function_drop(_pat_16_4, _ctx);
              kk_function_drop(_pat_15_4, _ctx);
              kk_function_drop(_pat_14_4, _ctx);
              kk_function_drop(_pat_13_4, _ctx);
              kk_function_drop(_pat_12_4, _ctx);
              kk_string_drop(_pat_11_4, _ctx);
              kk_string_drop(_pat_10_5, _ctx);
              kk_datatype_ptr_free(_pat_8_5, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_8_5, _ctx);
            }
            if kk_likely(kk_datatype_ptr_is_unique(_pat_4_5, _ctx)) {
              kk_integer_drop(_pat_6_5, _ctx);
              kk_integer_drop(_pat_5_5, _ctx);
              kk_datatype_ptr_free(_pat_4_5, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_pat_4_5, _ctx);
            }
            kk_std_time_instant__instant_drop(_pat_23_4, _ctx);
            kk_string_drop(_pat_19_4, _ctx);
            kk_std_time_date__date_drop(_pat_0_5_0, _ctx);
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_std_time_calendar__timezone_dup(_x_4_0, _ctx);
            kk_datatype_ptr_decref(t, _ctx);
          }
          _x_x1506 = _x_4_0; /*std/time/calendar/timezone*/
        }
      }
      return kk_std_time_time__new_Time(kk_reuse_null, 0, _x_x1473, _x_x1478, _x_x1491, _x_x1496, _x_x1501, _x_x1506, ri, _ctx);
    }
    {
      kk_std_core_types__optional _x_x1511;
      kk_box_t _x_x1512;
      kk_std_time_calendar__timezone _x_x1513;
      {
        struct kk_std_time_time_Time* _con_x1514 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _pat_0_9 = _con_x1514->date;
        kk_std_time_date__clock _pat_4_4_0_0 = _con_x1514->clock;
        kk_std_time_calendar__calendar _pat_8_2_0_0 = _con_x1514->calendar;
        kk_std_time_duration__duration _pat_17_2_0_0 = _con_x1514->tzdelta;
        kk_std_time_calendar__timezone _x_8_0 = _con_x1514->timezone;
        kk_std_time_instant__instant _pat_23_2_0_0 = _con_x1514->instant;
        struct kk_std_time_date_Clock* _con_x1515 = kk_std_time_date__as_Clock(_pat_4_4_0_0, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1516 = kk_std_time_calendar__as_Calendar(_pat_8_2_0_0, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1517 = kk_std_time_calendar__as_Timezone(_x_8_0, _ctx);
        kk_std_time_calendar__timezone_dup(_x_8_0, _ctx);
        _x_x1513 = _x_8_0; /*std/time/calendar/timezone*/
      }
      _x_x1512 = kk_std_time_calendar__timezone_box(_x_x1513, _ctx); /*7*/
      _x_x1511 = kk_std_core_types__new_Optional(_x_x1512, _ctx); /*? 7*/
      kk_std_core_types__optional _x_x1518;
      kk_box_t _x_x1519;
      kk_std_time_calendar__calendar _x_x1520;
      {
        struct kk_std_time_time_Time* _con_x1521 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _pat_0_10 = _con_x1521->date;
        kk_std_time_date__clock _pat_4_5_0 = _con_x1521->clock;
        kk_std_time_calendar__calendar _x_9 = _con_x1521->calendar;
        kk_std_time_duration__duration _pat_16_3_0_0 = _con_x1521->tzdelta;
        kk_std_time_calendar__timezone _pat_19_3_0_0 = _con_x1521->timezone;
        kk_std_time_instant__instant _pat_23_3_0_0 = _con_x1521->instant;
        struct kk_std_time_date_Clock* _con_x1522 = kk_std_time_date__as_Clock(_pat_4_5_0, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1523 = kk_std_time_calendar__as_Calendar(_x_9, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1524 = kk_std_time_calendar__as_Timezone(_pat_19_3_0_0, _ctx);
        kk_string_t _pat_18_3_0_0 = _con_x1521->tzabbrv;
        kk_integer_t _pat_5_4_0 = _con_x1522->hours;
        kk_integer_t _pat_6_3_0_0 = _con_x1522->minutes;
        kk_string_t _pat_20_3_0_0 = _con_x1524->name;
        kk_function_t _pat_21_3_0_0 = _con_x1524->utc_delta;
        kk_function_t _pat_22_3_0_0 = _con_x1524->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_4_5_0, _ctx)) {
            kk_integer_drop(_pat_6_3_0_0, _ctx);
            kk_integer_drop(_pat_5_4_0, _ctx);
            kk_datatype_ptr_free(_pat_4_5_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_4_5_0, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_3_0_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_3_0_0, _ctx)) {
            kk_function_drop(_pat_22_3_0_0, _ctx);
            kk_function_drop(_pat_21_3_0_0, _ctx);
            kk_string_drop(_pat_20_3_0_0, _ctx);
            kk_datatype_ptr_free(_pat_19_3_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_3_0_0, _ctx);
          }
          kk_string_drop(_pat_18_3_0_0, _ctx);
          kk_std_time_date__date_drop(_pat_0_10, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_calendar__calendar_dup(_x_9, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        _x_x1520 = _x_9; /*std/time/calendar/calendar*/
      }
      _x_x1519 = kk_std_time_calendar__calendar_box(_x_x1520, _ctx); /*7*/
      _x_x1518 = kk_std_core_types__new_Optional(_x_x1519, _ctx); /*? 7*/
      return kk_std_time_time_instant_fs_time(ri, _x_x1511, _x_x1518, kk_std_core_types__new_None(_ctx), _ctx);
    }
  }
}
 
// pad with zeros

kk_string_t kk_std_time_time_show0(kk_integer_t i, kk_std_core_types__optional width, kk_context_t* _ctx) { /* (i : int, width : ? int) -> string */ 
  kk_string_t _own_x743 = kk_std_core_int_show(i, _ctx); /*string*/;
  kk_integer_t _brw_x742;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x184 = width._cons._Optional.value;
    kk_integer_t _uniq_width_3214 = kk_integer_unbox(_box_x184, _ctx);
    kk_integer_dup(_uniq_width_3214, _ctx);
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x742 = _uniq_width_3214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(width, _ctx);
    _brw_x742 = kk_integer_from_small(2); /*int*/
  }
  kk_string_t _brw_x744;
  kk_std_core_types__optional _x_x1525 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
  _brw_x744 = kk_std_core_string_pad_left(_own_x743, _brw_x742, _x_x1525, _ctx); /*string*/
  kk_integer_drop(_brw_x742, _ctx);
  return _brw_x744;
}
 
// Show a time zone delta.
// Optional `utc` for displaying a zero timezone delta (=`"Z"`).
// Optional `hmsep` for the hour-minute separator (=`":"`).
// Optional `hrwidth` to give the minimal width of the hour field (=`2`).

kk_string_t kk_std_time_time_show_tzdelta(kk_std_time_duration__duration delta, kk_std_core_types__optional utc, kk_std_core_types__optional hmsep, kk_std_core_types__optional hrwidth, kk_context_t* _ctx) { /* (delta : std/time/duration/duration, utc : ? string, hmsep : ? string, hrwidth : ? int) -> string */ 
  kk_integer_t dt;
  kk_std_num_ddouble__ddouble _x_x1526;
  {
    kk_std_num_ddouble__ddouble _x = delta.secs;
    _x_x1526 = _x; /*std/time/timestamp/timespan*/
  }
  dt = kk_std_num_ddouble_int(_x_x1526, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  bool _match_x726 = kk_integer_is_zero_borrow(dt); /*bool*/;
  if (_match_x726) {
    kk_std_core_types__optional_drop(hrwidth, _ctx);
    kk_std_core_types__optional_drop(hmsep, _ctx);
    kk_integer_drop(dt, _ctx);
    if (kk_std_core_types__is_Optional(utc, _ctx)) {
      kk_box_t _box_x187 = utc._cons._Optional.value;
      kk_string_t _uniq_utc_3296 = kk_string_unbox(_box_x187);
      kk_string_dup(_uniq_utc_3296, _ctx);
      kk_std_core_types__optional_drop(utc, _ctx);
      return _uniq_utc_3296;
    }
    {
      kk_std_core_types__optional_drop(utc, _ctx);
      kk_define_string_literal(, _s_x1527, 1, "Z", _ctx)
      return kk_string_dup(_s_x1527, _ctx);
    }
  }
  {
    kk_std_core_types__optional_drop(utc, _ctx);
    kk_std_core_types__tuple2 _match_x727;
    kk_integer_t _x_x1528;
    kk_integer_t _x_x1529 = kk_integer_dup(dt, _ctx); /*int*/
    _x_x1528 = kk_integer_abs(_x_x1529,kk_context()); /*int*/
    _match_x727 = kk_std_core_int_divmod(_x_x1528, kk_integer_from_small(60), _ctx); /*(int, int)*/
    {
      kk_box_t _box_x188 = _match_x727.fst;
      kk_box_t _box_x189 = _match_x727.snd;
      kk_integer_t mins = kk_integer_unbox(_box_x188, _ctx);
      kk_integer_t secs = kk_integer_unbox(_box_x189, _ctx);
      kk_integer_dup(mins, _ctx);
      kk_integer_dup(secs, _ctx);
      kk_std_core_types__tuple2_drop(_match_x727, _ctx);
      kk_integer_t i_0_10087;
      kk_integer_t _x_x1530 = kk_integer_dup(mins, _ctx); /*int*/
      i_0_10087 = kk_integer_div(_x_x1530,(kk_integer_from_small(60)),kk_context()); /*int*/
      kk_integer_t i_1_10089 = kk_integer_mod(mins,(kk_integer_from_small(60)),kk_context()); /*int*/;
      kk_string_t tz;
      kk_string_t _x_x1531;
      bool _match_x740;
      bool _brw_x741 = kk_integer_lt_borrow(dt,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(dt, _ctx);
      _match_x740 = _brw_x741; /*bool*/
      if (_match_x740) {
        kk_define_string_literal(, _s_x1532, 1, "-", _ctx)
        _x_x1531 = kk_string_dup(_s_x1532, _ctx); /*string*/
      }
      else {
        kk_define_string_literal(, _s_x1533, 1, "+", _ctx)
        _x_x1531 = kk_string_dup(_s_x1533, _ctx); /*string*/
      }
      kk_string_t _x_x1534;
      kk_string_t _x_x1535;
      kk_string_t _own_x738 = kk_std_core_int_show(i_0_10087, _ctx); /*string*/;
      kk_integer_t _brw_x737;
      if (kk_std_core_types__is_Optional(hrwidth, _ctx)) {
        kk_box_t _box_x190 = hrwidth._cons._Optional.value;
        kk_integer_t _uniq_hrwidth_3304 = kk_integer_unbox(_box_x190, _ctx);
        kk_integer_dup(_uniq_hrwidth_3304, _ctx);
        kk_std_core_types__optional_drop(hrwidth, _ctx);
        _brw_x737 = _uniq_hrwidth_3304; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(hrwidth, _ctx);
        _brw_x737 = kk_integer_from_small(2); /*int*/
      }
      kk_string_t _brw_x739;
      kk_std_core_types__optional _x_x1536 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
      _brw_x739 = kk_std_core_string_pad_left(_own_x738, _brw_x737, _x_x1536, _ctx); /*string*/
      kk_integer_drop(_brw_x737, _ctx);
      _x_x1535 = _brw_x739; /*string*/
      kk_string_t _x_x1537;
      kk_string_t _x_x1538;
      if (kk_std_core_types__is_Optional(hmsep, _ctx)) {
        kk_box_t _box_x192 = hmsep._cons._Optional.value;
        kk_string_t _uniq_hmsep_3300 = kk_string_unbox(_box_x192);
        kk_string_dup(_uniq_hmsep_3300, _ctx);
        kk_std_core_types__optional_drop(hmsep, _ctx);
        _x_x1538 = _uniq_hmsep_3300; /*string*/
      }
      else {
        kk_std_core_types__optional_drop(hmsep, _ctx);
        kk_define_string_literal(, _s_x1539, 1, ":", _ctx)
        _x_x1538 = kk_string_dup(_s_x1539, _ctx); /*string*/
      }
      kk_string_t _x_x1540;
      kk_string_t _own_x735 = kk_std_core_int_show(i_1_10089, _ctx); /*string*/;
      kk_integer_t _brw_x734;
      kk_std_core_types__optional _match_x733 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x733, _ctx)) {
        kk_box_t _box_x193 = _match_x733._cons._Optional.value;
        kk_integer_t _uniq_width_3214_0 = kk_integer_unbox(_box_x193, _ctx);
        kk_integer_dup(_uniq_width_3214_0, _ctx);
        kk_std_core_types__optional_drop(_match_x733, _ctx);
        _brw_x734 = _uniq_width_3214_0; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x733, _ctx);
        _brw_x734 = kk_integer_from_small(2); /*int*/
      }
      kk_string_t _brw_x736;
      kk_std_core_types__optional _x_x1541 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
      _brw_x736 = kk_std_core_string_pad_left(_own_x735, _brw_x734, _x_x1541, _ctx); /*string*/
      kk_integer_drop(_brw_x734, _ctx);
      _x_x1540 = _brw_x736; /*string*/
      _x_x1537 = kk_std_core_types__lp__plus__plus__rp_(_x_x1538, _x_x1540, _ctx); /*string*/
      _x_x1534 = kk_std_core_types__lp__plus__plus__rp_(_x_x1535, _x_x1537, _ctx); /*string*/
      tz = kk_std_core_types__lp__plus__plus__rp_(_x_x1531, _x_x1534, _ctx); /*string*/
      kk_string_t tzs;
      bool _match_x728 = kk_integer_is_zero_borrow(secs); /*bool*/;
      if (_match_x728) {
        kk_integer_drop(secs, _ctx);
        tzs = kk_string_empty(); /*string*/
      }
      else {
        kk_string_t _x_x1543;
        kk_define_string_literal(, _s_x1544, 1, ":", _ctx)
        _x_x1543 = kk_string_dup(_s_x1544, _ctx); /*string*/
        kk_string_t _x_x1545;
        kk_string_t _own_x731 = kk_std_core_int_show(secs, _ctx); /*string*/;
        kk_integer_t _brw_x730;
        kk_std_core_types__optional _match_x729 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x729, _ctx)) {
          kk_box_t _box_x197 = _match_x729._cons._Optional.value;
          kk_integer_t _uniq_width_3214_1 = kk_integer_unbox(_box_x197, _ctx);
          kk_integer_dup(_uniq_width_3214_1, _ctx);
          kk_std_core_types__optional_drop(_match_x729, _ctx);
          _brw_x730 = _uniq_width_3214_1; /*int*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x729, _ctx);
          _brw_x730 = kk_integer_from_small(2); /*int*/
        }
        kk_string_t _brw_x732;
        kk_std_core_types__optional _x_x1546 = kk_std_core_types__new_Optional(kk_char_box('0', _ctx), _ctx); /*? 7*/
        _brw_x732 = kk_std_core_string_pad_left(_own_x731, _brw_x730, _x_x1546, _ctx); /*string*/
        kk_integer_drop(_brw_x730, _ctx);
        _x_x1545 = _brw_x732; /*string*/
        tzs = kk_std_core_types__lp__plus__plus__rp_(_x_x1543, _x_x1545, _ctx); /*string*/
      }
      return kk_std_core_types__lp__plus__plus__rp_(tz, tzs, _ctx);
    }
  }
}

kk_string_t kk_std_time_time_show_raw(kk_std_time_time__time tp, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (tp : time, prec : ? int) -> string */ 
  kk_string_t _b_x200_203;
  {
    struct kk_std_time_time_Time* _con_x1547 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _pat_0_4 = _con_x1547->date;
    kk_std_time_date__clock _pat_4_4 = _con_x1547->clock;
    kk_std_time_calendar__calendar _x_4 = _con_x1547->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x1547->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x1547->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x1547->instant;
    struct kk_std_time_date_Clock* _con_x1548 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1549 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1550 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_std_time_calendar__calendar_dup(_x_4, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x1551 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
      kk_string_t _pat_0_3 = _con_x1551->name;
      kk_string_t _pat_1_3 = _con_x1551->long_name;
      kk_string_t _x_3 = _con_x1551->month_prefix;
      kk_function_t _pat_2_3 = _con_x1551->show_era;
      kk_function_t _pat_3_3 = _con_x1551->instant_to_dc;
      kk_function_t _pat_4_3 = _con_x1551->dc_to_instant;
      kk_function_t _pat_5_3 = _con_x1551->days_to_date;
      kk_function_t _pat_6_3 = _con_x1551->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_4, _ctx)) {
        kk_function_drop(_pat_6_3, _ctx);
        kk_function_drop(_pat_5_3, _ctx);
        kk_function_drop(_pat_4_3, _ctx);
        kk_function_drop(_pat_3_3, _ctx);
        kk_function_drop(_pat_2_3, _ctx);
        kk_string_drop(_pat_1_3, _ctx);
        kk_string_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_x_4, _ctx);
      }
      else {
        kk_string_dup(_x_3, _ctx);
        kk_datatype_ptr_decref(_x_4, _ctx);
      }
      _b_x200_203 = _x_3; /*string*/
    }
  }
  kk_string_t _x_x1552;
  kk_std_time_date__date _x_x1553;
  {
    struct kk_std_time_time_Time* _con_x1554 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _x_2 = _con_x1554->date;
    kk_std_time_date__clock _pat_3_2 = _con_x1554->clock;
    kk_std_time_calendar__calendar _pat_7_1 = _con_x1554->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x1554->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x1554->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x1554->instant;
    struct kk_std_time_date_Clock* _con_x1555 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1556 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1557 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_2, _ctx);
    _x_x1553 = _x_2; /*std/time/date/date*/
  }
  kk_std_core_types__optional _x_x1558 = kk_std_core_types__new_Optional(kk_string_box(_b_x200_203), _ctx); /*? 7*/
  _x_x1552 = kk_std_time_date_show(_x_x1553, _x_x1558, _ctx); /*string*/
  kk_string_t _x_x1559;
  kk_string_t _x_x1560;
  kk_define_string_literal(, _s_x1561, 1, "T", _ctx)
  _x_x1560 = kk_string_dup(_s_x1561, _ctx); /*string*/
  kk_string_t _x_x1562;
  kk_integer_t _b_x202_204;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x201 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_2721 = kk_integer_unbox(_box_x201, _ctx);
    kk_integer_dup(_uniq_prec_2721, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    _b_x202_204 = _uniq_prec_2721; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    _b_x202_204 = kk_integer_from_small(9); /*int*/
  }
  kk_string_t _x_x1563;
  kk_std_time_date__clock _x_x1564;
  {
    struct kk_std_time_time_Time* _con_x1565 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _pat_0_5 = _con_x1565->date;
    kk_std_time_date__clock _x_5 = _con_x1565->clock;
    kk_std_time_calendar__calendar _pat_7_3 = _con_x1565->calendar;
    kk_std_time_duration__duration _pat_16_2 = _con_x1565->tzdelta;
    kk_std_time_calendar__timezone _pat_19_2 = _con_x1565->timezone;
    kk_std_time_instant__instant _pat_23_2 = _con_x1565->instant;
    struct kk_std_time_date_Clock* _con_x1566 = kk_std_time_date__as_Clock(_x_5, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1567 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1568 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
    kk_std_time_date__clock_dup(_x_5, _ctx);
    _x_x1564 = _x_5; /*std/time/date/clock*/
  }
  kk_std_core_types__optional _x_x1569 = kk_std_core_types__new_Optional(kk_integer_box(_b_x202_204, _ctx), _ctx); /*? 7*/
  _x_x1563 = kk_std_time_date_clock_fs_show(_x_x1564, _x_x1569, _ctx); /*string*/
  kk_string_t _x_x1570;
  kk_string_t _x_x1571;
  kk_std_time_duration__duration _x_x1572;
  {
    struct kk_std_time_time_Time* _con_x1573 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _pat_0_7 = _con_x1573->date;
    kk_std_time_date__clock _pat_4_6 = _con_x1573->clock;
    kk_std_time_calendar__calendar _pat_8_4 = _con_x1573->calendar;
    kk_std_time_duration__duration _x_6 = _con_x1573->tzdelta;
    kk_std_time_calendar__timezone _pat_19_3 = _con_x1573->timezone;
    kk_std_time_instant__instant _pat_23_3 = _con_x1573->instant;
    struct kk_std_time_date_Clock* _con_x1574 = kk_std_time_date__as_Clock(_pat_4_6, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1575 = kk_std_time_calendar__as_Calendar(_pat_8_4, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1576 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
    _x_x1572 = _x_6; /*std/time/duration/duration*/
  }
  _x_x1571 = kk_std_time_time_show_tzdelta(_x_x1572, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*string*/
  kk_string_t _x_x1577;
  kk_string_t _x_x1578;
  bool _match_x723;
  kk_string_t _x_x1579;
  {
    struct kk_std_time_time_Time* _con_x1580 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _pat_0_9 = _con_x1580->date;
    kk_std_time_date__clock _pat_4_7 = _con_x1580->clock;
    kk_std_time_calendar__calendar _pat_8_5 = _con_x1580->calendar;
    kk_std_time_duration__duration _pat_17_4 = _con_x1580->tzdelta;
    kk_std_time_calendar__timezone _pat_19_4 = _con_x1580->timezone;
    kk_std_time_instant__instant _pat_23_4 = _con_x1580->instant;
    struct kk_std_time_date_Clock* _con_x1581 = kk_std_time_date__as_Clock(_pat_4_7, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1582 = kk_std_time_calendar__as_Calendar(_pat_8_5, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1583 = kk_std_time_calendar__as_Timezone(_pat_19_4, _ctx);
    kk_string_t _x_7 = _con_x1580->tzabbrv;
    kk_string_dup(_x_7, _ctx);
    _x_x1579 = _x_7; /*string*/
  }
  kk_string_t _x_x1584 = kk_string_empty(); /*string*/
  _match_x723 = kk_string_is_eq(_x_x1579,_x_x1584,kk_context()); /*bool*/
  if (_match_x723) {
    _x_x1578 = kk_string_empty(); /*string*/
  }
  else {
    bool _match_x724;
    kk_string_t _x_x1587;
    kk_string_t _x_x1588;
    {
      struct kk_std_time_time_Time* _con_x1589 = kk_std_time_time__as_Time(tp, _ctx);
      kk_std_time_date__date _pat_0_9_0 = _con_x1589->date;
      kk_std_time_date__clock _pat_4_7_0 = _con_x1589->clock;
      kk_std_time_calendar__calendar _pat_8_5_0 = _con_x1589->calendar;
      kk_std_time_duration__duration _pat_17_4_0 = _con_x1589->tzdelta;
      kk_std_time_calendar__timezone _pat_19_4_0 = _con_x1589->timezone;
      kk_std_time_instant__instant _pat_23_4_0 = _con_x1589->instant;
      struct kk_std_time_date_Clock* _con_x1590 = kk_std_time_date__as_Clock(_pat_4_7_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1591 = kk_std_time_calendar__as_Calendar(_pat_8_5_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1592 = kk_std_time_calendar__as_Timezone(_pat_19_4_0, _ctx);
      kk_string_t _x_7_0 = _con_x1589->tzabbrv;
      kk_string_dup(_x_7_0, _ctx);
      _x_x1588 = _x_7_0; /*string*/
    }
    _x_x1587 = kk_std_core_sslice_head(_x_x1588, _ctx); /*string*/
    kk_string_t _x_x1593;
    kk_define_string_literal(, _s_x1594, 1, "+", _ctx)
    _x_x1593 = kk_string_dup(_s_x1594, _ctx); /*string*/
    _match_x724 = kk_string_is_eq(_x_x1587,_x_x1593,kk_context()); /*bool*/
    if (_match_x724) {
      _x_x1578 = kk_string_empty(); /*string*/
    }
    else {
      bool _match_x725;
      kk_string_t _x_x1596;
      kk_string_t _x_x1597;
      {
        struct kk_std_time_time_Time* _con_x1598 = kk_std_time_time__as_Time(tp, _ctx);
        kk_std_time_date__date _pat_0_9_1 = _con_x1598->date;
        kk_std_time_date__clock _pat_4_7_1 = _con_x1598->clock;
        kk_std_time_calendar__calendar _pat_8_5_1 = _con_x1598->calendar;
        kk_std_time_duration__duration _pat_17_4_1 = _con_x1598->tzdelta;
        kk_std_time_calendar__timezone _pat_19_4_1 = _con_x1598->timezone;
        kk_std_time_instant__instant _pat_23_4_1 = _con_x1598->instant;
        struct kk_std_time_date_Clock* _con_x1599 = kk_std_time_date__as_Clock(_pat_4_7_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1600 = kk_std_time_calendar__as_Calendar(_pat_8_5_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1601 = kk_std_time_calendar__as_Timezone(_pat_19_4_1, _ctx);
        kk_string_t _x_7_1 = _con_x1598->tzabbrv;
        kk_string_dup(_x_7_1, _ctx);
        _x_x1597 = _x_7_1; /*string*/
      }
      _x_x1596 = kk_std_core_sslice_head(_x_x1597, _ctx); /*string*/
      kk_string_t _x_x1602;
      kk_define_string_literal(, _s_x1603, 1, "-", _ctx)
      _x_x1602 = kk_string_dup(_s_x1603, _ctx); /*string*/
      _match_x725 = kk_string_is_eq(_x_x1596,_x_x1602,kk_context()); /*bool*/
      if (_match_x725) {
        _x_x1578 = kk_string_empty(); /*string*/
      }
      else {
        kk_string_t _x_x1605;
        kk_define_string_literal(, _s_x1606, 2, " (", _ctx)
        _x_x1605 = kk_string_dup(_s_x1606, _ctx); /*string*/
        kk_string_t _x_x1607;
        kk_string_t _x_x1608;
        {
          struct kk_std_time_time_Time* _con_x1609 = kk_std_time_time__as_Time(tp, _ctx);
          kk_std_time_date__date _pat_0_10 = _con_x1609->date;
          kk_std_time_date__clock _pat_4_8 = _con_x1609->clock;
          kk_std_time_calendar__calendar _pat_8_6 = _con_x1609->calendar;
          kk_std_time_duration__duration _pat_17_5 = _con_x1609->tzdelta;
          kk_std_time_calendar__timezone _pat_19_5 = _con_x1609->timezone;
          kk_std_time_instant__instant _pat_23_5 = _con_x1609->instant;
          struct kk_std_time_date_Clock* _con_x1610 = kk_std_time_date__as_Clock(_pat_4_8, _ctx);
          struct kk_std_time_calendar_Calendar* _con_x1611 = kk_std_time_calendar__as_Calendar(_pat_8_6, _ctx);
          struct kk_std_time_calendar_Timezone* _con_x1612 = kk_std_time_calendar__as_Timezone(_pat_19_5, _ctx);
          kk_string_t _x_8 = _con_x1609->tzabbrv;
          kk_string_dup(_x_8, _ctx);
          _x_x1608 = _x_8; /*string*/
        }
        kk_string_t _x_x1613;
        kk_define_string_literal(, _s_x1614, 1, ")", _ctx)
        _x_x1613 = kk_string_dup(_s_x1614, _ctx); /*string*/
        _x_x1607 = kk_std_core_types__lp__plus__plus__rp_(_x_x1608, _x_x1613, _ctx); /*string*/
        _x_x1578 = kk_std_core_types__lp__plus__plus__rp_(_x_x1605, _x_x1607, _ctx); /*string*/
      }
    }
  }
  kk_string_t _x_x1615;
  kk_string_t _x_x1616;
  bool _match_x721;
  kk_string_t _x_x1617;
  {
    struct kk_std_time_time_Time* _con_x1618 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _pat_0_12 = _con_x1618->date;
    kk_std_time_date__clock _pat_4_10 = _con_x1618->clock;
    kk_std_time_calendar__calendar _x_10 = _con_x1618->calendar;
    kk_std_time_duration__duration _pat_16_6 = _con_x1618->tzdelta;
    kk_std_time_calendar__timezone _pat_19_6 = _con_x1618->timezone;
    kk_std_time_instant__instant _pat_23_6 = _con_x1618->instant;
    struct kk_std_time_date_Clock* _con_x1619 = kk_std_time_date__as_Clock(_pat_4_10, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1620 = kk_std_time_calendar__as_Calendar(_x_10, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1621 = kk_std_time_calendar__as_Timezone(_pat_19_6, _ctx);
    kk_std_time_calendar__calendar_dup(_x_10, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x1622 = kk_std_time_calendar__as_Calendar(_x_10, _ctx);
      kk_string_t _x_9 = _con_x1622->name;
      kk_string_t _pat_0_11 = _con_x1622->long_name;
      kk_string_t _pat_1_11 = _con_x1622->month_prefix;
      kk_function_t _pat_2_11 = _con_x1622->show_era;
      kk_function_t _pat_3_9 = _con_x1622->instant_to_dc;
      kk_function_t _pat_4_9 = _con_x1622->dc_to_instant;
      kk_function_t _pat_5_9 = _con_x1622->days_to_date;
      kk_function_t _pat_6_9 = _con_x1622->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_10, _ctx)) {
        kk_function_drop(_pat_6_9, _ctx);
        kk_function_drop(_pat_5_9, _ctx);
        kk_function_drop(_pat_4_9, _ctx);
        kk_function_drop(_pat_3_9, _ctx);
        kk_function_drop(_pat_2_11, _ctx);
        kk_string_drop(_pat_1_11, _ctx);
        kk_string_drop(_pat_0_11, _ctx);
        kk_datatype_ptr_free(_x_10, _ctx);
      }
      else {
        kk_string_dup(_x_9, _ctx);
        kk_datatype_ptr_decref(_x_10, _ctx);
      }
      _x_x1617 = _x_9; /*string*/
    }
  }
  kk_string_t _x_x1623 = kk_string_empty(); /*string*/
  _match_x721 = kk_string_is_eq(_x_x1617,_x_x1623,kk_context()); /*bool*/
  if (_match_x721) {
    _x_x1616 = kk_string_empty(); /*string*/
  }
  else {
    bool _match_x722;
    kk_string_t _x_x1626;
    {
      struct kk_std_time_time_Time* _con_x1627 = kk_std_time_time__as_Time(tp, _ctx);
      kk_std_time_date__date _pat_0_14 = _con_x1627->date;
      kk_std_time_date__clock _pat_4_13 = _con_x1627->clock;
      kk_std_time_calendar__calendar _x_12 = _con_x1627->calendar;
      kk_std_time_duration__duration _pat_16_7 = _con_x1627->tzdelta;
      kk_std_time_calendar__timezone _pat_19_7 = _con_x1627->timezone;
      kk_std_time_instant__instant _pat_23_7 = _con_x1627->instant;
      struct kk_std_time_date_Clock* _con_x1628 = kk_std_time_date__as_Clock(_pat_4_13, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1629 = kk_std_time_calendar__as_Calendar(_x_12, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1630 = kk_std_time_calendar__as_Timezone(_pat_19_7, _ctx);
      kk_std_time_calendar__calendar_dup(_x_12, _ctx);
      {
        struct kk_std_time_calendar_Calendar* _con_x1631 = kk_std_time_calendar__as_Calendar(_x_12, _ctx);
        kk_string_t _pat_0_13 = _con_x1631->name;
        kk_string_t _pat_1_13 = _con_x1631->long_name;
        kk_string_t _x_11 = _con_x1631->month_prefix;
        kk_function_t _pat_2_13 = _con_x1631->show_era;
        kk_function_t _pat_3_12 = _con_x1631->instant_to_dc;
        kk_function_t _pat_4_12 = _con_x1631->dc_to_instant;
        kk_function_t _pat_5_11 = _con_x1631->days_to_date;
        kk_function_t _pat_6_11 = _con_x1631->date_to_days;
        if kk_likely(kk_datatype_ptr_is_unique(_x_12, _ctx)) {
          kk_function_drop(_pat_6_11, _ctx);
          kk_function_drop(_pat_5_11, _ctx);
          kk_function_drop(_pat_4_12, _ctx);
          kk_function_drop(_pat_3_12, _ctx);
          kk_function_drop(_pat_2_13, _ctx);
          kk_string_drop(_pat_1_13, _ctx);
          kk_string_drop(_pat_0_13, _ctx);
          kk_datatype_ptr_free(_x_12, _ctx);
        }
        else {
          kk_string_dup(_x_11, _ctx);
          kk_datatype_ptr_decref(_x_12, _ctx);
        }
        _x_x1626 = _x_11; /*string*/
      }
    }
    kk_string_t _x_x1632 = kk_string_empty(); /*string*/
    _match_x722 = kk_string_is_neq(_x_x1626,_x_x1632,kk_context()); /*bool*/
    if (_match_x722) {
      _x_x1616 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x1635;
      kk_define_string_literal(, _s_x1636, 1, " ", _ctx)
      _x_x1635 = kk_string_dup(_s_x1636, _ctx); /*string*/
      kk_string_t _x_x1637;
      {
        struct kk_std_time_time_Time* _con_x1638 = kk_std_time_time__as_Time(tp, _ctx);
        kk_std_time_date__date _pat_0_16 = _con_x1638->date;
        kk_std_time_date__clock _pat_4_15 = _con_x1638->clock;
        kk_std_time_calendar__calendar _x_14 = _con_x1638->calendar;
        kk_std_time_duration__duration _pat_16_8 = _con_x1638->tzdelta;
        kk_std_time_calendar__timezone _pat_19_8 = _con_x1638->timezone;
        kk_std_time_instant__instant _pat_23_8 = _con_x1638->instant;
        struct kk_std_time_date_Clock* _con_x1639 = kk_std_time_date__as_Clock(_pat_4_15, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1640 = kk_std_time_calendar__as_Calendar(_x_14, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1641 = kk_std_time_calendar__as_Timezone(_pat_19_8, _ctx);
        kk_std_time_calendar__calendar_dup(_x_14, _ctx);
        {
          struct kk_std_time_calendar_Calendar* _con_x1642 = kk_std_time_calendar__as_Calendar(_x_14, _ctx);
          kk_string_t _x_13 = _con_x1642->name;
          kk_string_t _pat_0_15 = _con_x1642->long_name;
          kk_string_t _pat_1_15 = _con_x1642->month_prefix;
          kk_function_t _pat_2_15 = _con_x1642->show_era;
          kk_function_t _pat_3_14 = _con_x1642->instant_to_dc;
          kk_function_t _pat_4_14 = _con_x1642->dc_to_instant;
          kk_function_t _pat_5_14 = _con_x1642->days_to_date;
          kk_function_t _pat_6_14 = _con_x1642->date_to_days;
          if kk_likely(kk_datatype_ptr_is_unique(_x_14, _ctx)) {
            kk_function_drop(_pat_6_14, _ctx);
            kk_function_drop(_pat_5_14, _ctx);
            kk_function_drop(_pat_4_14, _ctx);
            kk_function_drop(_pat_3_14, _ctx);
            kk_function_drop(_pat_2_15, _ctx);
            kk_string_drop(_pat_1_15, _ctx);
            kk_string_drop(_pat_0_15, _ctx);
            kk_datatype_ptr_free(_x_14, _ctx);
          }
          else {
            kk_string_dup(_x_13, _ctx);
            kk_datatype_ptr_decref(_x_14, _ctx);
          }
          _x_x1637 = _x_13; /*string*/
        }
      }
      _x_x1616 = kk_std_core_types__lp__plus__plus__rp_(_x_x1635, _x_x1637, _ctx); /*string*/
    }
  }
  kk_string_t _x_x1643;
  bool _match_x719;
  kk_string_t _x_x1644;
  {
    struct kk_std_time_time_Time* _con_x1645 = kk_std_time_time__as_Time(tp, _ctx);
    kk_std_time_date__date _pat_0_1 = _con_x1645->date;
    kk_std_time_date__clock _pat_4_1 = _con_x1645->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1645->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1645->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1645->timezone;
    kk_std_time_instant__instant _x_1 = _con_x1645->instant;
    struct kk_std_time_date_Clock* _con_x1646 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1647 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1648 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x_1, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0_0 = _x_1.since;
      kk_std_time_instant__timescale _x_0 = _x_1.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1649 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1650 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0, _ctx);
      kk_std_time_instant__instant_drop(_x_1, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x1651 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
        kk_string_t _x = _con_x1651->name;
        kk_string_t _pat_0 = _con_x1651->unit;
        kk_function_t _pat_1 = _con_x1651->from_tai;
        kk_function_t _pat_2 = _con_x1651->to_tai;
        kk_std_core_types__maybe _pat_3 = _con_x1651->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4 = _con_x1651->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5 = _con_x1651->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5, _ctx);
          kk_std_core_types__maybe_drop(_pat_4, _ctx);
          kk_std_core_types__maybe_drop(_pat_3, _ctx);
          kk_function_drop(_pat_2, _ctx);
          kk_function_drop(_pat_1, _ctx);
          kk_string_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(_x_0, _ctx);
        }
        else {
          kk_string_dup(_x, _ctx);
          kk_datatype_ptr_decref(_x_0, _ctx);
        }
        _x_x1644 = _x; /*string*/
      }
    }
  }
  kk_string_t _x_x1652 = kk_string_empty(); /*string*/
  _match_x719 = kk_string_is_eq(_x_x1644,_x_x1652,kk_context()); /*bool*/
  if (_match_x719) {
    kk_datatype_ptr_dropn(tp, (KK_I32(9)), _ctx);
    _x_x1643 = kk_string_empty(); /*string*/
  }
  else {
    bool _match_x720;
    kk_string_t _x_x1655;
    {
      struct kk_std_time_time_Time* _con_x1656 = kk_std_time_time__as_Time(tp, _ctx);
      kk_std_time_date__date _pat_0_1_0 = _con_x1656->date;
      kk_std_time_date__clock _pat_4_1_0 = _con_x1656->clock;
      kk_std_time_calendar__calendar _pat_8_0_0 = _con_x1656->calendar;
      kk_std_time_duration__duration _pat_17_9 = _con_x1656->tzdelta;
      kk_std_time_calendar__timezone _pat_20_9 = _con_x1656->timezone;
      kk_std_time_instant__instant _x_1_0 = _con_x1656->instant;
      struct kk_std_time_date_Clock* _con_x1657 = kk_std_time_date__as_Clock(_pat_4_1_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1658 = kk_std_time_calendar__as_Calendar(_pat_8_0_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1659 = kk_std_time_calendar__as_Timezone(_pat_20_9, _ctx);
      kk_std_time_instant__instant_dup(_x_1_0, _ctx);
      {
        kk_std_time_timestamp__timestamp _pat_0_0_0 = _x_1_0.since;
        kk_std_time_instant__timescale _x_0_0 = _x_1_0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1660 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1661 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
        kk_std_time_instant__instant_drop(_x_1_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1662 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
          kk_string_t _x_15 = _con_x1662->name;
          kk_string_t _pat_0_17 = _con_x1662->unit;
          kk_function_t _pat_1_17 = _con_x1662->from_tai;
          kk_function_t _pat_2_17 = _con_x1662->to_tai;
          kk_std_core_types__maybe _pat_3_16 = _con_x1662->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_16 = _con_x1662->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_16 = _con_x1662->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_16, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_16, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_16, _ctx);
            kk_function_drop(_pat_2_17, _ctx);
            kk_function_drop(_pat_1_17, _ctx);
            kk_string_drop(_pat_0_17, _ctx);
            kk_datatype_ptr_free(_x_0_0, _ctx);
          }
          else {
            kk_string_dup(_x_15, _ctx);
            kk_datatype_ptr_decref(_x_0_0, _ctx);
          }
          _x_x1655 = _x_15; /*string*/
        }
      }
    }
    kk_string_t _x_x1663;
    kk_define_string_literal(, _s_x1664, 3, "UTC", _ctx)
    _x_x1663 = kk_string_dup(_s_x1664, _ctx); /*string*/
    _match_x720 = kk_string_is_eq(_x_x1655,_x_x1663,kk_context()); /*bool*/
    if (_match_x720) {
      kk_datatype_ptr_dropn(tp, (KK_I32(9)), _ctx);
      _x_x1643 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x1666;
      kk_define_string_literal(, _s_x1667, 1, " ", _ctx)
      _x_x1666 = kk_string_dup(_s_x1667, _ctx); /*string*/
      kk_string_t _x_x1668;
      {
        struct kk_std_time_time_Time* _con_x1669 = kk_std_time_time__as_Time(tp, _ctx);
        kk_std_time_date__date _pat_0_1_1 = _con_x1669->date;
        kk_std_time_date__clock _pat_4_1_1 = _con_x1669->clock;
        kk_std_time_calendar__calendar _pat_8_0_1 = _con_x1669->calendar;
        kk_std_time_duration__duration _pat_17_10 = _con_x1669->tzdelta;
        kk_std_time_calendar__timezone _pat_20_10 = _con_x1669->timezone;
        kk_std_time_instant__instant _x_1_1 = _con_x1669->instant;
        struct kk_std_time_date_Clock* _con_x1670 = kk_std_time_date__as_Clock(_pat_4_1_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x1671 = kk_std_time_calendar__as_Calendar(_pat_8_0_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x1672 = kk_std_time_calendar__as_Timezone(_pat_20_10, _ctx);
        kk_string_t _pat_19_10 = _con_x1669->tzabbrv;
        kk_integer_t _pat_5_1_1 = _con_x1670->hours;
        kk_integer_t _pat_6_1_1 = _con_x1670->minutes;
        kk_string_t _pat_9_0_1 = _con_x1671->name;
        kk_string_t _pat_10_0_1 = _con_x1671->long_name;
        kk_string_t _pat_11_10 = _con_x1671->month_prefix;
        kk_function_t _pat_12_10 = _con_x1671->show_era;
        kk_function_t _pat_13_10 = _con_x1671->instant_to_dc;
        kk_function_t _pat_14_10 = _con_x1671->dc_to_instant;
        kk_function_t _pat_15_10 = _con_x1671->days_to_date;
        kk_function_t _pat_16_10 = _con_x1671->date_to_days;
        kk_string_t _pat_21_10 = _con_x1672->name;
        kk_function_t _pat_22_10 = _con_x1672->utc_delta;
        kk_function_t _pat_23_10 = _con_x1672->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(tp, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0_1, _ctx)) {
            kk_string_drop(_pat_9_0_1, _ctx);
            kk_function_drop(_pat_16_10, _ctx);
            kk_function_drop(_pat_15_10, _ctx);
            kk_function_drop(_pat_14_10, _ctx);
            kk_function_drop(_pat_13_10, _ctx);
            kk_function_drop(_pat_12_10, _ctx);
            kk_string_drop(_pat_11_10, _ctx);
            kk_string_drop(_pat_10_0_1, _ctx);
            kk_datatype_ptr_free(_pat_8_0_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_8_0_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_4_1_1, _ctx)) {
            kk_integer_drop(_pat_6_1_1, _ctx);
            kk_integer_drop(_pat_5_1_1, _ctx);
            kk_datatype_ptr_free(_pat_4_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_4_1_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_20_10, _ctx)) {
            kk_function_drop(_pat_23_10, _ctx);
            kk_function_drop(_pat_22_10, _ctx);
            kk_string_drop(_pat_21_10, _ctx);
            kk_datatype_ptr_free(_pat_20_10, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_20_10, _ctx);
          }
          kk_string_drop(_pat_19_10, _ctx);
          kk_std_time_date__date_drop(_pat_0_1_1, _ctx);
          kk_datatype_ptr_free(tp, _ctx);
        }
        else {
          kk_std_time_instant__instant_dup(_x_1_1, _ctx);
          kk_datatype_ptr_decref(tp, _ctx);
        }
        {
          kk_std_time_timestamp__timestamp _pat_0_0_1 = _x_1_1.since;
          kk_std_time_instant__timescale _x_0_1 = _x_1_1.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1673 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1674 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
          kk_std_time_instant__timescale_dup(_x_0_1, _ctx);
          kk_std_time_instant__instant_drop(_x_1_1, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1675 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
            kk_string_t _x_16 = _con_x1675->name;
            kk_string_t _pat_0_18 = _con_x1675->unit;
            kk_function_t _pat_1_18 = _con_x1675->from_tai;
            kk_function_t _pat_2_18 = _con_x1675->to_tai;
            kk_std_core_types__maybe _pat_3_17 = _con_x1675->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_17 = _con_x1675->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_17 = _con_x1675->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_17, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_17, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_17, _ctx);
              kk_function_drop(_pat_2_18, _ctx);
              kk_function_drop(_pat_1_18, _ctx);
              kk_string_drop(_pat_0_18, _ctx);
              kk_datatype_ptr_free(_x_0_1, _ctx);
            }
            else {
              kk_string_dup(_x_16, _ctx);
              kk_datatype_ptr_decref(_x_0_1, _ctx);
            }
            _x_x1668 = _x_16; /*string*/
          }
        }
      }
      _x_x1643 = kk_std_core_types__lp__plus__plus__rp_(_x_x1666, _x_x1668, _ctx); /*string*/
    }
  }
  _x_x1615 = kk_std_core_types__lp__plus__plus__rp_(_x_x1616, _x_x1643, _ctx); /*string*/
  _x_x1577 = kk_std_core_types__lp__plus__plus__rp_(_x_x1578, _x_x1615, _ctx); /*string*/
  _x_x1570 = kk_std_core_types__lp__plus__plus__rp_(_x_x1571, _x_x1577, _ctx); /*string*/
  _x_x1562 = kk_std_core_types__lp__plus__plus__rp_(_x_x1563, _x_x1570, _ctx); /*string*/
  _x_x1559 = kk_std_core_types__lp__plus__plus__rp_(_x_x1560, _x_x1562, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1552, _x_x1559, _ctx);
}
 
// Show a `:time` in [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) format.

kk_string_t kk_std_time_time_show(kk_std_time_time__time t, kk_std_core_types__optional prec, kk_context_t* _ctx) { /* (t : time, prec : ? int) -> string */ 
  kk_std_time_time__time tp;
  kk_integer_t _x_x1676;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x205 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_2694 = kk_integer_unbox(_box_x205, _ctx);
    kk_integer_dup(_uniq_prec_2694, _ctx);
    _x_x1676 = _uniq_prec_2694; /*int*/
  }
  else {
    _x_x1676 = kk_integer_from_small(9); /*int*/
  }
  tp = kk_std_time_time_round_to_prec(t, _x_x1676, _ctx); /*std/time/time/time*/
  kk_std_core_types__optional _x_x1677;
  kk_box_t _x_x1678;
  kk_integer_t _x_x1679;
  if (kk_std_core_types__is_Optional(prec, _ctx)) {
    kk_box_t _box_x206 = prec._cons._Optional.value;
    kk_integer_t _uniq_prec_2694_0 = kk_integer_unbox(_box_x206, _ctx);
    kk_integer_dup(_uniq_prec_2694_0, _ctx);
    kk_std_core_types__optional_drop(prec, _ctx);
    _x_x1679 = _uniq_prec_2694_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(prec, _ctx);
    _x_x1679 = kk_integer_from_small(9); /*int*/
  }
  _x_x1678 = kk_integer_box(_x_x1679, _ctx); /*7*/
  _x_x1677 = kk_std_core_types__new_Optional(_x_x1678, _ctx); /*? 7*/
  return kk_std_time_time_show_raw(tp, _x_x1677, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_time__mlift_time_utc_10407_fun1681__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time__mlift_time_utc_10407_fun1681(kk_function_t _fself, kk_box_t _b_x219, kk_box_t _b_x220, kk_box_t _b_x221, kk_box_t _b_x222, kk_context_t* _ctx);
static kk_function_t kk_std_time_time__new_mlift_time_utc_10407_fun1681(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time__mlift_time_utc_10407_fun1681, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time__mlift_time_utc_10407_fun1681(kk_function_t _fself, kk_box_t _b_x219, kk_box_t _b_x220, kk_box_t _b_x221, kk_box_t _b_x222, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x1682;
  kk_std_time_instant__instant _x_x1683 = kk_std_time_instant__instant_unbox(_b_x219, KK_OWNED, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1684 = kk_std_core_types__optional_unbox(_b_x220, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x1685 = kk_std_core_types__optional_unbox(_b_x221, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x1686 = kk_std_core_types__optional_unbox(_b_x222, KK_OWNED, _ctx); /*? std/time/instant/timescale*/
  _x_x1682 = kk_std_time_time_instant_fs_time(_x_x1683, _x_x1684, _x_x1685, _x_x1686, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1682, _ctx);
}

kk_std_time_time__time kk_std_time_time__mlift_time_utc_10407(kk_std_core_types__optional cal, kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_time_instant__timescale _y_x10333, kk_context_t* _ctx) { /* (cal : ? std/time/calendar/calendar, i : std/time/instant/instant, tz : ? std/time/calendar/timezone, std/time/instant/timescale) -> std/time/utc/utc time */ 
  kk_box_t _x_x1680;
  kk_box_t _x_x1687;
  kk_std_core_types__optional _x_x1688;
  kk_box_t _x_x1689;
  kk_std_time_calendar__timezone _x_x1690;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x209 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3580 = kk_std_time_calendar__timezone_unbox(_box_x209, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3580, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1690 = _uniq_tz_3580; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1690 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1689 = kk_std_time_calendar__timezone_box(_x_x1690, _ctx); /*7*/
  _x_x1688 = kk_std_core_types__new_Optional(_x_x1689, _ctx); /*? 7*/
  _x_x1687 = kk_std_core_types__optional_box(_x_x1688, _ctx); /*10183*/
  kk_box_t _x_x1691;
  kk_std_core_types__optional _x_x1692;
  kk_box_t _x_x1693;
  kk_std_time_calendar__calendar _x_x1694;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x211 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3584 = kk_std_time_calendar__calendar_unbox(_box_x211, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3584, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1694 = _uniq_cal_3584; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1694 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1693 = kk_std_time_calendar__calendar_box(_x_x1694, _ctx); /*7*/
  _x_x1692 = kk_std_core_types__new_Optional(_x_x1693, _ctx); /*? 7*/
  _x_x1691 = kk_std_core_types__optional_box(_x_x1692, _ctx); /*10184*/
  kk_box_t _x_x1695;
  kk_std_core_types__optional _x_x1696 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(_y_x10333, _ctx), _ctx); /*? 7*/
  _x_x1695 = kk_std_core_types__optional_box(_x_x1696, _ctx); /*10185*/
  _x_x1680 = kk_std_core_hnd__open_none4(kk_std_time_time__new_mlift_time_utc_10407_fun1681(_ctx), kk_std_time_instant__instant_box(i, _ctx), _x_x1687, _x_x1691, _x_x1695, _ctx); /*10186*/
  return kk_std_time_time__time_unbox(_x_x1680, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_utc_fun1700__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_time_instant__instant i;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_time_time_utc_fun1700(kk_function_t _fself, kk_box_t _b_x238, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_utc_fun1700(kk_std_core_types__optional cal, kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_time_time_utc_fun1700__t* _self = kk_function_alloc_as(struct kk_std_time_time_time_utc_fun1700__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_time_utc_fun1700, kk_context());
  _self->cal = cal;
  _self->i = i;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_time_utc_fun1700(kk_function_t _fself, kk_box_t _b_x238, kk_context_t* _ctx) {
  struct kk_std_time_time_time_utc_fun1700__t* _self = kk_function_as(struct kk_std_time_time_time_utc_fun1700__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_instant__instant i = _self->i; /* std/time/instant/instant */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_instant__instant_dup(i, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _y_x10333_262 = kk_std_time_instant__timescale_unbox(_b_x238, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_time__time _x_x1701 = kk_std_time_time__mlift_time_utc_10407(cal, i, tz, _y_x10333_262, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1701, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_utc_fun1702__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_time_utc_fun1702(kk_function_t _fself, kk_box_t _b_x249, kk_box_t _b_x250, kk_box_t _b_x251, kk_box_t _b_x252, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_utc_fun1702(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_time_utc_fun1702, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_time_utc_fun1702(kk_function_t _fself, kk_box_t _b_x249, kk_box_t _b_x250, kk_box_t _b_x251, kk_box_t _b_x252, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x1703;
  kk_std_time_instant__instant _x_x1704 = kk_std_time_instant__instant_unbox(_b_x249, KK_OWNED, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1705 = kk_std_core_types__optional_unbox(_b_x250, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x1706 = kk_std_core_types__optional_unbox(_b_x251, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x1707 = kk_std_core_types__optional_unbox(_b_x252, KK_OWNED, _ctx); /*? std/time/instant/timescale*/
  _x_x1703 = kk_std_time_time_instant_fs_time(_x_x1704, _x_x1705, _x_x1706, _x_x1707, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1703, _ctx);
}

kk_std_time_time__time kk_std_time_time_time_utc(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 
  kk_std_core_hnd__ev ev_10432 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
  kk_std_time_instant__timescale x_10429;
  kk_box_t _x_x1697;
  {
    struct kk_std_core_hnd_Ev* _con_x1698 = kk_std_core_hnd__as_Ev(ev_10432, _ctx);
    kk_box_t _box_x231 = _con_x1698->hnd;
    int32_t m = _con_x1698->marker;
    kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x231, KK_BORROWED, _ctx);
    kk_std_time_utc__utc_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x717;
    kk_std_core_hnd__clause0 _brw_x718 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
    _match_x717 = _brw_x718; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
    {
      kk_function_t _fun_unbox_x234 = _match_x717.clause;
      _x_x1697 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x234, (_fun_unbox_x234, m, ev_10432, _ctx), _ctx); /*35*/
    }
  }
  x_10429 = kk_std_time_instant__timescale_unbox(_x_x1697, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  kk_box_t _x_x1699;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10429, (KK_I32(10)), _ctx);
    _x_x1699 = kk_std_core_hnd_yield_extend(kk_std_time_time_new_time_utc_fun1700(cal, i, tz, _ctx), _ctx); /*2419*/
  }
  else {
    kk_box_t _x_x1708;
    kk_std_core_types__optional _x_x1709;
    kk_box_t _x_x1710;
    kk_std_time_calendar__timezone _x_x1711;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x239 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_3580 = kk_std_time_calendar__timezone_unbox(_box_x239, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_3580, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1711 = _uniq_tz_3580; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x1711 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    _x_x1710 = kk_std_time_calendar__timezone_box(_x_x1711, _ctx); /*7*/
    _x_x1709 = kk_std_core_types__new_Optional(_x_x1710, _ctx); /*? 7*/
    _x_x1708 = kk_std_core_types__optional_box(_x_x1709, _ctx); /*10183*/
    kk_box_t _x_x1712;
    kk_std_core_types__optional _x_x1713;
    kk_box_t _x_x1714;
    kk_std_time_calendar__calendar _x_x1715;
    if (kk_std_core_types__is_Optional(cal, _ctx)) {
      kk_box_t _box_x241 = cal._cons._Optional.value;
      kk_std_time_calendar__calendar _uniq_cal_3584 = kk_std_time_calendar__calendar_unbox(_box_x241, KK_BORROWED, _ctx);
      kk_std_time_calendar__calendar_dup(_uniq_cal_3584, _ctx);
      kk_std_core_types__optional_drop(cal, _ctx);
      _x_x1715 = _uniq_cal_3584; /*std/time/calendar/calendar*/
    }
    else {
      kk_std_core_types__optional_drop(cal, _ctx);
      _x_x1715 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
    }
    _x_x1714 = kk_std_time_calendar__calendar_box(_x_x1715, _ctx); /*7*/
    _x_x1713 = kk_std_core_types__new_Optional(_x_x1714, _ctx); /*? 7*/
    _x_x1712 = kk_std_core_types__optional_box(_x_x1713, _ctx); /*10184*/
    kk_box_t _x_x1716;
    kk_std_core_types__optional _x_x1717 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(x_10429, _ctx), _ctx); /*? 7*/
    _x_x1716 = kk_std_core_types__optional_box(_x_x1717, _ctx); /*10185*/
    _x_x1699 = kk_std_core_hnd__open_none4(kk_std_time_time_new_time_utc_fun1702(_ctx), kk_std_time_instant__instant_box(i, _ctx), _x_x1708, _x_x1712, _x_x1716, _ctx); /*2419*/
  }
  return kk_std_time_time__time_unbox(_x_x1699, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_tai_fun1719__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_time_tai_fun1719(kk_function_t _fself, kk_box_t _b_x273, kk_box_t _b_x274, kk_box_t _b_x275, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_tai_fun1719(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_time_tai_fun1719, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_time_tai_fun1719(kk_function_t _fself, kk_box_t _b_x273, kk_box_t _b_x274, kk_box_t _b_x275, kk_box_t _b_x276, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x1720;
  kk_std_time_instant__instant _x_x1721 = kk_std_time_instant__instant_unbox(_b_x273, KK_OWNED, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1722 = kk_std_core_types__optional_unbox(_b_x274, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x1723 = kk_std_core_types__optional_unbox(_b_x275, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x1724 = kk_std_core_types__optional_unbox(_b_x276, KK_OWNED, _ctx); /*? std/time/instant/timescale*/
  _x_x1720 = kk_std_time_time_instant_fs_time(_x_x1721, _x_x1722, _x_x1723, _x_x1724, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1720, _ctx);
}

kk_std_time_time__time kk_std_time_time_time_tai(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 
  kk_box_t _x_x1718;
  kk_box_t _x_x1725;
  kk_std_core_types__optional _x_x1726;
  kk_box_t _x_x1727;
  kk_std_time_calendar__timezone _x_x1728;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x263 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3626 = kk_std_time_calendar__timezone_unbox(_box_x263, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3626, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1728 = _uniq_tz_3626; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1728 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1727 = kk_std_time_calendar__timezone_box(_x_x1728, _ctx); /*7*/
  _x_x1726 = kk_std_core_types__new_Optional(_x_x1727, _ctx); /*? 7*/
  _x_x1725 = kk_std_core_types__optional_box(_x_x1726, _ctx); /*10183*/
  kk_box_t _x_x1729;
  kk_std_core_types__optional _x_x1730;
  kk_box_t _x_x1731;
  kk_std_time_calendar__calendar _x_x1732;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x265 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3630 = kk_std_time_calendar__calendar_unbox(_box_x265, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3630, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1732 = _uniq_cal_3630; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1732 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1731 = kk_std_time_calendar__calendar_box(_x_x1732, _ctx); /*7*/
  _x_x1730 = kk_std_core_types__new_Optional(_x_x1731, _ctx); /*? 7*/
  _x_x1729 = kk_std_core_types__optional_box(_x_x1730, _ctx); /*10184*/
  kk_box_t _x_x1733;
  kk_std_core_types__optional _x_x1734;
  kk_box_t _x_x1735;
  kk_std_time_instant__timescale _x_x1736 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  _x_x1735 = kk_std_time_instant__timescale_box(_x_x1736, _ctx); /*7*/
  _x_x1734 = kk_std_core_types__new_Optional(_x_x1735, _ctx); /*? 7*/
  _x_x1733 = kk_std_core_types__optional_box(_x_x1734, _ctx); /*10185*/
  _x_x1718 = kk_std_core_hnd__open_none4(kk_std_time_time_new_time_tai_fun1719(_ctx), kk_std_time_instant__instant_box(i, _ctx), _x_x1725, _x_x1729, _x_x1733, _ctx); /*10186*/
  return kk_std_time_time__time_unbox(_x_x1718, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_gps_fun1738__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_time_gps_fun1738(kk_function_t _fself, kk_box_t _b_x295, kk_box_t _b_x296, kk_box_t _b_x297, kk_box_t _b_x298, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_gps_fun1738(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_time_gps_fun1738, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_time_gps_fun1738(kk_function_t _fself, kk_box_t _b_x295, kk_box_t _b_x296, kk_box_t _b_x297, kk_box_t _b_x298, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x1739;
  kk_std_time_instant__instant _x_x1740 = kk_std_time_instant__instant_unbox(_b_x295, KK_OWNED, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1741 = kk_std_core_types__optional_unbox(_b_x296, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x1742 = kk_std_core_types__optional_unbox(_b_x297, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x1743 = kk_std_core_types__optional_unbox(_b_x298, KK_OWNED, _ctx); /*? std/time/instant/timescale*/
  _x_x1739 = kk_std_time_time_instant_fs_time(_x_x1740, _x_x1741, _x_x1742, _x_x1743, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1739, _ctx);
}

kk_std_time_time__time kk_std_time_time_time_gps(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 
  kk_box_t _x_x1737;
  kk_box_t _x_x1744;
  kk_std_core_types__optional _x_x1745;
  kk_box_t _x_x1746;
  kk_std_time_calendar__timezone _x_x1747;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x285 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3669 = kk_std_time_calendar__timezone_unbox(_box_x285, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3669, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1747 = _uniq_tz_3669; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1747 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1746 = kk_std_time_calendar__timezone_box(_x_x1747, _ctx); /*7*/
  _x_x1745 = kk_std_core_types__new_Optional(_x_x1746, _ctx); /*? 7*/
  _x_x1744 = kk_std_core_types__optional_box(_x_x1745, _ctx); /*10183*/
  kk_box_t _x_x1748;
  kk_std_core_types__optional _x_x1749;
  kk_box_t _x_x1750;
  kk_std_time_calendar__calendar _x_x1751;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x287 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3673 = kk_std_time_calendar__calendar_unbox(_box_x287, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3673, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1751 = _uniq_cal_3673; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1751 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1750 = kk_std_time_calendar__calendar_box(_x_x1751, _ctx); /*7*/
  _x_x1749 = kk_std_core_types__new_Optional(_x_x1750, _ctx); /*? 7*/
  _x_x1748 = kk_std_core_types__optional_box(_x_x1749, _ctx); /*10184*/
  kk_box_t _x_x1752;
  kk_std_core_types__optional _x_x1753;
  kk_box_t _x_x1754;
  kk_std_time_instant__timescale _x_x1755 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_gps, _ctx); /*std/time/instant/timescale*/
  _x_x1754 = kk_std_time_instant__timescale_box(_x_x1755, _ctx); /*7*/
  _x_x1753 = kk_std_core_types__new_Optional(_x_x1754, _ctx); /*? 7*/
  _x_x1752 = kk_std_core_types__optional_box(_x_x1753, _ctx); /*10185*/
  _x_x1737 = kk_std_core_hnd__open_none4(kk_std_time_time_new_time_gps_fun1738(_ctx), kk_std_time_instant__instant_box(i, _ctx), _x_x1744, _x_x1748, _x_x1752, _ctx); /*10186*/
  return kk_std_time_time__time_unbox(_x_x1737, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_tt_fun1757__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_time_tt_fun1757(kk_function_t _fself, kk_box_t _b_x317, kk_box_t _b_x318, kk_box_t _b_x319, kk_box_t _b_x320, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_tt_fun1757(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_time_tt_fun1757, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_time_tt_fun1757(kk_function_t _fself, kk_box_t _b_x317, kk_box_t _b_x318, kk_box_t _b_x319, kk_box_t _b_x320, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x1758;
  kk_std_time_instant__instant _x_x1759 = kk_std_time_instant__instant_unbox(_b_x317, KK_OWNED, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1760 = kk_std_core_types__optional_unbox(_b_x318, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x1761 = kk_std_core_types__optional_unbox(_b_x319, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x1762 = kk_std_core_types__optional_unbox(_b_x320, KK_OWNED, _ctx); /*? std/time/instant/timescale*/
  _x_x1758 = kk_std_time_time_instant_fs_time(_x_x1759, _x_x1760, _x_x1761, _x_x1762, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1758, _ctx);
}

kk_std_time_time__time kk_std_time_time_time_tt(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 
  kk_box_t _x_x1756;
  kk_box_t _x_x1763;
  kk_std_core_types__optional _x_x1764;
  kk_box_t _x_x1765;
  kk_std_time_calendar__timezone _x_x1766;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x307 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3712 = kk_std_time_calendar__timezone_unbox(_box_x307, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3712, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1766 = _uniq_tz_3712; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1766 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1765 = kk_std_time_calendar__timezone_box(_x_x1766, _ctx); /*7*/
  _x_x1764 = kk_std_core_types__new_Optional(_x_x1765, _ctx); /*? 7*/
  _x_x1763 = kk_std_core_types__optional_box(_x_x1764, _ctx); /*10183*/
  kk_box_t _x_x1767;
  kk_std_core_types__optional _x_x1768;
  kk_box_t _x_x1769;
  kk_std_time_calendar__calendar _x_x1770;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x309 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3716 = kk_std_time_calendar__calendar_unbox(_box_x309, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3716, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1770 = _uniq_cal_3716; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1770 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1769 = kk_std_time_calendar__calendar_box(_x_x1770, _ctx); /*7*/
  _x_x1768 = kk_std_core_types__new_Optional(_x_x1769, _ctx); /*? 7*/
  _x_x1767 = kk_std_core_types__optional_box(_x_x1768, _ctx); /*10184*/
  kk_box_t _x_x1771;
  kk_std_core_types__optional _x_x1772;
  kk_box_t _x_x1773;
  kk_std_time_instant__timescale _x_x1774 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tt, _ctx); /*std/time/instant/timescale*/
  _x_x1773 = kk_std_time_instant__timescale_box(_x_x1774, _ctx); /*7*/
  _x_x1772 = kk_std_core_types__new_Optional(_x_x1773, _ctx); /*? 7*/
  _x_x1771 = kk_std_core_types__optional_box(_x_x1772, _ctx); /*10185*/
  _x_x1756 = kk_std_core_hnd__open_none4(kk_std_time_time_new_time_tt_fun1757(_ctx), kk_std_time_instant__instant_box(i, _ctx), _x_x1763, _x_x1767, _x_x1771, _ctx); /*10186*/
  return kk_std_time_time__time_unbox(_x_x1756, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_time_time_ti_fun1776__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_time_ti_fun1776(kk_function_t _fself, kk_box_t _b_x339, kk_box_t _b_x340, kk_box_t _b_x341, kk_box_t _b_x342, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_new_time_ti_fun1776(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_time_ti_fun1776, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_time_ti_fun1776(kk_function_t _fself, kk_box_t _b_x339, kk_box_t _b_x340, kk_box_t _b_x341, kk_box_t _b_x342, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_time__time _x_x1777;
  kk_std_time_instant__instant _x_x1778 = kk_std_time_instant__instant_unbox(_b_x339, KK_OWNED, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1779 = kk_std_core_types__optional_unbox(_b_x340, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x1780 = kk_std_core_types__optional_unbox(_b_x341, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/
  kk_std_core_types__optional _x_x1781 = kk_std_core_types__optional_unbox(_b_x342, KK_OWNED, _ctx); /*? std/time/instant/timescale*/
  _x_x1777 = kk_std_time_time_instant_fs_time(_x_x1778, _x_x1779, _x_x1780, _x_x1781, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x1777, _ctx);
}

kk_std_time_time__time kk_std_time_time_time_ti(kk_std_time_instant__instant i, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> std/time/utc/utc time */ 
  kk_box_t _x_x1775;
  kk_box_t _x_x1782;
  kk_std_core_types__optional _x_x1783;
  kk_box_t _x_x1784;
  kk_std_time_calendar__timezone _x_x1785;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x329 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_3755 = kk_std_time_calendar__timezone_unbox(_box_x329, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_3755, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1785 = _uniq_tz_3755; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x1785 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x1784 = kk_std_time_calendar__timezone_box(_x_x1785, _ctx); /*7*/
  _x_x1783 = kk_std_core_types__new_Optional(_x_x1784, _ctx); /*? 7*/
  _x_x1782 = kk_std_core_types__optional_box(_x_x1783, _ctx); /*10183*/
  kk_box_t _x_x1786;
  kk_std_core_types__optional _x_x1787;
  kk_box_t _x_x1788;
  kk_std_time_calendar__calendar _x_x1789;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x331 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_3759 = kk_std_time_calendar__calendar_unbox(_box_x331, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_3759, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1789 = _uniq_cal_3759; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x1789 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x1788 = kk_std_time_calendar__calendar_box(_x_x1789, _ctx); /*7*/
  _x_x1787 = kk_std_core_types__new_Optional(_x_x1788, _ctx); /*? 7*/
  _x_x1786 = kk_std_core_types__optional_box(_x_x1787, _ctx); /*10184*/
  kk_box_t _x_x1790;
  kk_std_core_types__optional _x_x1791;
  kk_box_t _x_x1792;
  kk_std_time_instant__timescale _x_x1793 = kk_std_time_instant__timescale_dup(kk_std_time_utc_ts_ti, _ctx); /*std/time/instant/timescale*/
  _x_x1792 = kk_std_time_instant__timescale_box(_x_x1793, _ctx); /*7*/
  _x_x1791 = kk_std_core_types__new_Optional(_x_x1792, _ctx); /*? 7*/
  _x_x1790 = kk_std_core_types__optional_box(_x_x1791, _ctx); /*10185*/
  _x_x1775 = kk_std_core_hnd__open_none4(kk_std_time_time_new_time_ti_fun1776(_ctx), kk_std_time_instant__instant_box(i, _ctx), _x_x1782, _x_x1786, _x_x1790, _ctx); /*10186*/
  return kk_std_time_time__time_unbox(_x_x1775, KK_OWNED, _ctx);
}
 
// Add an SI second `:duration` to a time.
// `(time(2015,12,31,23,59,59,0.5) + duration(1)).show == "2016-01-01T00:00:00.500Z"`
// `(time(2016,12,31,23,59,59,0.5) + duration(1)).show == "2016-12-31T23:59:60.500Z"` &quad; (into a leap second)

kk_std_time_time__time kk_std_time_time_duration_fs__lp__plus__rp_(kk_std_time_time__time t, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (t : time, d : std/time/duration/duration) -> time */ 
  kk_std_time_instant__instant _x_x1794;
  kk_std_time_instant__instant _x_x1795;
  {
    struct kk_std_time_time_Time* _con_x1796 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1796->date;
    kk_std_time_date__clock _pat_4 = _con_x1796->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1796->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1796->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1796->timezone;
    kk_std_time_instant__instant _x = _con_x1796->instant;
    struct kk_std_time_date_Clock* _con_x1797 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1798 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1799 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x1795 = _x; /*std/time/instant/instant*/
  }
  _x_x1794 = kk_std_time_instant__lp__plus__rp_(_x_x1795, d, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1800;
  kk_box_t _x_x1801;
  kk_std_time_calendar__timezone _x_x1802;
  {
    struct kk_std_time_time_Time* _con_x1803 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1803->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1803->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1803->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1803->tzdelta;
    kk_std_time_calendar__timezone _x_0 = _con_x1803->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x1803->instant;
    struct kk_std_time_date_Clock* _con_x1804 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1805 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1806 = kk_std_time_calendar__as_Timezone(_x_0, _ctx);
    kk_std_time_calendar__timezone_dup(_x_0, _ctx);
    _x_x1802 = _x_0; /*std/time/calendar/timezone*/
  }
  _x_x1801 = kk_std_time_calendar__timezone_box(_x_x1802, _ctx); /*7*/
  _x_x1800 = kk_std_core_types__new_Optional(_x_x1801, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1807;
  kk_box_t _x_x1808;
  kk_std_time_calendar__calendar _x_x1809;
  {
    struct kk_std_time_time_Time* _con_x1810 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_1 = _con_x1810->date;
    kk_std_time_date__clock _pat_4_1 = _con_x1810->clock;
    kk_std_time_calendar__calendar _x_1 = _con_x1810->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x1810->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x1810->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x1810->instant;
    struct kk_std_time_date_Clock* _con_x1811 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1812 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1813 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_string_t _pat_18_1 = _con_x1810->tzabbrv;
    kk_integer_t _pat_5_1 = _con_x1811->hours;
    kk_integer_t _pat_6_1 = _con_x1811->minutes;
    kk_string_t _pat_20_1 = _con_x1813->name;
    kk_function_t _pat_21_1 = _con_x1813->utc_delta;
    kk_function_t _pat_22_1 = _con_x1813->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_1, _ctx)) {
        kk_integer_drop(_pat_6_1, _ctx);
        kk_integer_drop(_pat_5_1, _ctx);
        kk_datatype_ptr_free(_pat_4_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_1, _ctx);
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
      kk_std_time_date__date_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_calendar__calendar_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1809 = _x_1; /*std/time/calendar/calendar*/
  }
  _x_x1808 = kk_std_time_calendar__calendar_box(_x_x1809, _ctx); /*7*/
  _x_x1807 = kk_std_core_types__new_Optional(_x_x1808, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x1794, _x_x1800, _x_x1807, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Add a date (years, months, days) and optional clock to a time.  Takes leap years, leap seconds, etc. into account.

kk_std_time_time__time kk_std_time_time_add_date(kk_std_time_time__time t, kk_std_time_date__date d, kk_std_core_types__optional c, kk_context_t* _ctx) { /* (t : time, d : std/time/date/date, c : ? std/time/date/clock) -> time */ 
  kk_std_time_date__clock _b_x358_361;
  kk_integer_t _x_x1814;
  kk_integer_t _x_x1815;
  {
    struct kk_std_time_time_Time* _con_x1816 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_7 = _con_x1816->date;
    kk_std_time_date__clock _x_7 = _con_x1816->clock;
    kk_std_time_calendar__calendar _pat_7_3 = _con_x1816->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x1816->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x1816->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x1816->instant;
    struct kk_std_time_date_Clock* _con_x1817 = kk_std_time_date__as_Clock(_x_7, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1818 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1819 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_std_time_date__clock_dup(_x_7, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1820 = kk_std_time_date__as_Clock(_x_7, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_6 = _con_x1820->seconds;
      kk_integer_t _x_6 = _con_x1820->hours;
      kk_integer_t _pat_0_6 = _con_x1820->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_7, _ctx)) {
        kk_integer_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(_x_7, _ctx);
      }
      else {
        kk_integer_dup(_x_6, _ctx);
        kk_datatype_ptr_decref(_x_7, _ctx);
      }
      _x_x1815 = _x_6; /*int*/
    }
  }
  kk_integer_t _x_x1821;
  kk_std_time_date__clock _match_x715;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x355 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_3845 = kk_std_time_date__clock_unbox(_box_x355, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_3845, _ctx);
    _match_x715 = _uniq_c_3845; /*std/time/date/clock*/
  }
  else {
    _match_x715 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  {
    struct kk_std_time_date_Clock* _con_x1822 = kk_std_time_date__as_Clock(_match_x715, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0_1 = _con_x1822->seconds;
    kk_integer_t _x_0_1 = _con_x1822->hours;
    kk_integer_t _pat_0_0_1 = _con_x1822->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x715, _ctx)) {
      kk_integer_drop(_pat_0_0_1, _ctx);
      kk_datatype_ptr_free(_match_x715, _ctx);
    }
    else {
      kk_integer_dup(_x_0_1, _ctx);
      kk_datatype_ptr_decref(_match_x715, _ctx);
    }
    _x_x1821 = _x_0_1; /*int*/
  }
  _x_x1814 = kk_integer_add(_x_x1815,_x_x1821,kk_context()); /*int*/
  kk_integer_t _x_x1823;
  kk_integer_t _x_x1824;
  {
    struct kk_std_time_time_Time* _con_x1825 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_7_0 = _con_x1825->date;
    kk_std_time_date__clock _x_7_0 = _con_x1825->clock;
    kk_std_time_calendar__calendar _pat_7_3_0 = _con_x1825->calendar;
    kk_std_time_duration__duration _pat_16_1_0 = _con_x1825->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1_0 = _con_x1825->timezone;
    kk_std_time_instant__instant _pat_23_1_0 = _con_x1825->instant;
    struct kk_std_time_date_Clock* _con_x1826 = kk_std_time_date__as_Clock(_x_7_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1827 = kk_std_time_calendar__as_Calendar(_pat_7_3_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1828 = kk_std_time_calendar__as_Timezone(_pat_19_1_0, _ctx);
    kk_std_time_date__clock_dup(_x_7_0, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1829 = kk_std_time_date__as_Clock(_x_7_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_1_1 = _con_x1829->seconds;
      kk_integer_t _pat_0_1_1 = _con_x1829->hours;
      kk_integer_t _x_1_1 = _con_x1829->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_7_0, _ctx)) {
        kk_integer_drop(_pat_0_1_1, _ctx);
        kk_datatype_ptr_free(_x_7_0, _ctx);
      }
      else {
        kk_integer_dup(_x_1_1, _ctx);
        kk_datatype_ptr_decref(_x_7_0, _ctx);
      }
      _x_x1824 = _x_1_1; /*int*/
    }
  }
  kk_integer_t _x_x1830;
  kk_std_time_date__clock _match_x714;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x356 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_3845_0 = kk_std_time_date__clock_unbox(_box_x356, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_3845_0, _ctx);
    _match_x714 = _uniq_c_3845_0; /*std/time/date/clock*/
  }
  else {
    _match_x714 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  {
    struct kk_std_time_date_Clock* _con_x1831 = kk_std_time_date__as_Clock(_match_x714, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_2_0 = _con_x1831->seconds;
    kk_integer_t _pat_0_2_0 = _con_x1831->hours;
    kk_integer_t _x_2_0 = _con_x1831->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x714, _ctx)) {
      kk_integer_drop(_pat_0_2_0, _ctx);
      kk_datatype_ptr_free(_match_x714, _ctx);
    }
    else {
      kk_integer_dup(_x_2_0, _ctx);
      kk_datatype_ptr_decref(_match_x714, _ctx);
    }
    _x_x1830 = _x_2_0; /*int*/
  }
  _x_x1823 = kk_integer_add(_x_x1824,_x_x1830,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x1832;
  kk_std_num_ddouble__ddouble _x_x1833;
  {
    struct kk_std_time_time_Time* _con_x1834 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_7_1 = _con_x1834->date;
    kk_std_time_date__clock _x_7_1 = _con_x1834->clock;
    kk_std_time_calendar__calendar _pat_7_3_1 = _con_x1834->calendar;
    kk_std_time_duration__duration _pat_16_1_1 = _con_x1834->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1_1 = _con_x1834->timezone;
    kk_std_time_instant__instant _pat_23_1_1 = _con_x1834->instant;
    struct kk_std_time_date_Clock* _con_x1835 = kk_std_time_date__as_Clock(_x_7_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1836 = kk_std_time_calendar__as_Calendar(_pat_7_3_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1837 = kk_std_time_calendar__as_Timezone(_pat_19_1_1, _ctx);
    kk_std_time_date__clock_dup(_x_7_1, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1838 = kk_std_time_date__as_Clock(_x_7_1, _ctx);
      kk_std_num_ddouble__ddouble _x_3_0 = _con_x1838->seconds;
      kk_integer_t _pat_0_3_0 = _con_x1838->hours;
      kk_integer_t _pat_1_3_0 = _con_x1838->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_7_1, _ctx)) {
        kk_integer_drop(_pat_1_3_0, _ctx);
        kk_integer_drop(_pat_0_3_0, _ctx);
        kk_datatype_ptr_free(_x_7_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_7_1, _ctx);
      }
      _x_x1833 = _x_3_0; /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1839;
  kk_std_time_date__clock _match_x713;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x357 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_3845_1 = kk_std_time_date__clock_unbox(_box_x357, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_3845_1, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _match_x713 = _uniq_c_3845_1; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _match_x713 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  {
    struct kk_std_time_date_Clock* _con_x1840 = kk_std_time_date__as_Clock(_match_x713, _ctx);
    kk_std_num_ddouble__ddouble _x_4_0 = _con_x1840->seconds;
    kk_integer_t _pat_0_4_0 = _con_x1840->hours;
    kk_integer_t _pat_1_4_0 = _con_x1840->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x713, _ctx)) {
      kk_integer_drop(_pat_1_4_0, _ctx);
      kk_integer_drop(_pat_0_4_0, _ctx);
      kk_datatype_ptr_free(_match_x713, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_match_x713, _ctx);
    }
    _x_x1839 = _x_4_0; /*std/num/ddouble/ddouble*/
  }
  _x_x1832 = kk_std_num_ddouble__lp__plus__rp_(_x_x1833, _x_x1839, _ctx); /*std/num/ddouble/ddouble*/
  _b_x358_361 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x1814, _x_x1823, _x_x1832, _ctx); /*std/time/date/clock*/
  kk_std_time_instant__timescale _x_x1841;
  {
    struct kk_std_time_time_Time* _con_x1842 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1842->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1842->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1842->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1842->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1842->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1842->instant;
    struct kk_std_time_date_Clock* _con_x1843 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1844 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1845 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0 = _x_0.since;
      kk_std_time_instant__timescale _x = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1846 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1847 = kk_std_time_instant__as_Timescale(_x, _ctx);
      kk_std_time_instant__timescale_dup(_x, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      _x_x1841 = _x; /*std/time/instant/timescale*/
    }
  }
  kk_std_time_date__date _x_x1848;
  kk_integer_t _x_x1849;
  kk_integer_t _x_x1850;
  {
    struct kk_std_time_time_Time* _con_x1851 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_5 = _con_x1851->date;
    kk_std_time_date__clock _pat_3_2 = _con_x1851->clock;
    kk_std_time_calendar__calendar _pat_7_1 = _con_x1851->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x1851->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x1851->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x1851->instant;
    struct kk_std_time_date_Clock* _con_x1852 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1853 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1854 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_5, _ctx);
    {
      kk_integer_t _x_1 = _x_5.year;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_x_5, _ctx);
      _x_x1850 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x1855;
  {
    kk_integer_t _x_0_0 = d.year;
    kk_integer_dup(_x_0_0, _ctx);
    _x_x1855 = _x_0_0; /*int*/
  }
  _x_x1849 = kk_integer_add(_x_x1850,_x_x1855,kk_context()); /*int*/
  kk_integer_t _x_x1856;
  kk_integer_t _x_x1857;
  {
    struct kk_std_time_time_Time* _con_x1858 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_5_0 = _con_x1858->date;
    kk_std_time_date__clock _pat_3_2_0 = _con_x1858->clock;
    kk_std_time_calendar__calendar _pat_7_1_0 = _con_x1858->calendar;
    kk_std_time_duration__duration _pat_16_0_0 = _con_x1858->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_0 = _con_x1858->timezone;
    kk_std_time_instant__instant _pat_23_0_0 = _con_x1858->instant;
    struct kk_std_time_date_Clock* _con_x1859 = kk_std_time_date__as_Clock(_pat_3_2_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1860 = kk_std_time_calendar__as_Calendar(_pat_7_1_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1861 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
    kk_std_time_date__date_dup(_x_5_0, _ctx);
    {
      kk_integer_t _x_1_0 = _x_5_0.month;
      kk_integer_dup(_x_1_0, _ctx);
      kk_std_time_date__date_drop(_x_5_0, _ctx);
      _x_x1857 = _x_1_0; /*int*/
    }
  }
  kk_integer_t _x_x1862;
  {
    kk_integer_t _x_2 = d.month;
    kk_integer_dup(_x_2, _ctx);
    _x_x1862 = _x_2; /*int*/
  }
  _x_x1856 = kk_integer_add(_x_x1857,_x_x1862,kk_context()); /*int*/
  kk_integer_t _x_x1863;
  kk_integer_t _x_x1864;
  {
    struct kk_std_time_time_Time* _con_x1865 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_5_1 = _con_x1865->date;
    kk_std_time_date__clock _pat_3_2_1 = _con_x1865->clock;
    kk_std_time_calendar__calendar _pat_7_1_1 = _con_x1865->calendar;
    kk_std_time_duration__duration _pat_16_0_1 = _con_x1865->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_1 = _con_x1865->timezone;
    kk_std_time_instant__instant _pat_23_0_1 = _con_x1865->instant;
    struct kk_std_time_date_Clock* _con_x1866 = kk_std_time_date__as_Clock(_pat_3_2_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1867 = kk_std_time_calendar__as_Calendar(_pat_7_1_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1868 = kk_std_time_calendar__as_Timezone(_pat_19_0_1, _ctx);
    kk_std_time_date__date_dup(_x_5_1, _ctx);
    {
      kk_integer_t _x_3 = _x_5_1.day;
      kk_integer_dup(_x_3, _ctx);
      kk_std_time_date__date_drop(_x_5_1, _ctx);
      _x_x1864 = _x_3; /*int*/
    }
  }
  kk_integer_t _x_x1869;
  {
    kk_integer_t _x_4 = d.day;
    kk_integer_dup(_x_4, _ctx);
    kk_std_time_date__date_drop(d, _ctx);
    _x_x1869 = _x_4; /*int*/
  }
  _x_x1863 = kk_integer_add(_x_x1864,_x_x1869,kk_context()); /*int*/
  _x_x1848 = kk_std_time_date__new_Date(_x_x1849, _x_x1856, _x_x1863, _ctx); /*std/time/date/date*/
  kk_std_core_types__optional _x_x1870 = kk_std_core_types__new_Optional(kk_std_time_date__clock_box(_b_x358_361, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1871;
  kk_box_t _x_x1872;
  kk_std_time_calendar__timezone _x_x1873;
  {
    struct kk_std_time_time_Time* _con_x1874 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_9 = _con_x1874->date;
    kk_std_time_date__clock _pat_4_5 = _con_x1874->clock;
    kk_std_time_calendar__calendar _pat_8_4 = _con_x1874->calendar;
    kk_std_time_duration__duration _pat_17_2 = _con_x1874->tzdelta;
    kk_std_time_calendar__timezone _x_8 = _con_x1874->timezone;
    kk_std_time_instant__instant _pat_23_2 = _con_x1874->instant;
    struct kk_std_time_date_Clock* _con_x1875 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1876 = kk_std_time_calendar__as_Calendar(_pat_8_4, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1877 = kk_std_time_calendar__as_Timezone(_x_8, _ctx);
    kk_std_time_calendar__timezone_dup(_x_8, _ctx);
    _x_x1873 = _x_8; /*std/time/calendar/timezone*/
  }
  _x_x1872 = kk_std_time_calendar__timezone_box(_x_x1873, _ctx); /*7*/
  _x_x1871 = kk_std_core_types__new_Optional(_x_x1872, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1878;
  kk_box_t _x_x1879;
  kk_std_time_calendar__calendar _x_x1880;
  {
    struct kk_std_time_time_Time* _con_x1881 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_10 = _con_x1881->date;
    kk_std_time_date__clock _pat_4_6 = _con_x1881->clock;
    kk_std_time_calendar__calendar _x_9 = _con_x1881->calendar;
    kk_std_time_duration__duration _pat_16_3 = _con_x1881->tzdelta;
    kk_std_time_calendar__timezone _pat_19_3 = _con_x1881->timezone;
    kk_std_time_instant__instant _pat_23_3 = _con_x1881->instant;
    struct kk_std_time_date_Clock* _con_x1882 = kk_std_time_date__as_Clock(_pat_4_6, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1883 = kk_std_time_calendar__as_Calendar(_x_9, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1884 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
    kk_string_t _pat_18_3 = _con_x1881->tzabbrv;
    kk_integer_t _pat_5_6 = _con_x1882->hours;
    kk_integer_t _pat_6_6 = _con_x1882->minutes;
    kk_string_t _pat_20_3 = _con_x1884->name;
    kk_function_t _pat_21_3 = _con_x1884->utc_delta;
    kk_function_t _pat_22_3 = _con_x1884->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_6, _ctx)) {
        kk_integer_drop(_pat_6_6, _ctx);
        kk_integer_drop(_pat_5_6, _ctx);
        kk_datatype_ptr_free(_pat_4_6, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_6, _ctx);
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
      kk_std_time_date__date_drop(_pat_0_10, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_calendar__calendar_dup(_x_9, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1880 = _x_9; /*std/time/calendar/calendar*/
  }
  _x_x1879 = kk_std_time_calendar__calendar_box(_x_x1880, _ctx); /*7*/
  _x_x1878 = kk_std_core_types__new_Optional(_x_x1879, _ctx); /*? 7*/
  return kk_std_time_time_timescale_fs_date_fs_time(_x_x1841, _x_x1848, _x_x1870, _x_x1871, _x_x1878, _ctx);
}
 
// Add a clock (hours, minutes, seconds) to a time. Takes leap years, leap seconds, etc. into account.

kk_std_time_time__time kk_std_time_time_add_clock(kk_std_time_time__time t, kk_std_time_date__clock c, kk_context_t* _ctx) { /* (t : time, c : std/time/date/clock) -> time */ 
  kk_std_time_date__clock _b_x364_367;
  kk_integer_t _x_x1885;
  kk_integer_t _x_x1886;
  {
    struct kk_std_time_time_Time* _con_x1887 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_5 = _con_x1887->date;
    kk_std_time_date__clock _x_5 = _con_x1887->clock;
    kk_std_time_calendar__calendar _pat_7_3 = _con_x1887->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x1887->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x1887->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x1887->instant;
    struct kk_std_time_date_Clock* _con_x1888 = kk_std_time_date__as_Clock(_x_5, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1889 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1890 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_std_time_date__clock_dup(_x_5, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1891 = kk_std_time_date__as_Clock(_x_5, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_2 = _con_x1891->seconds;
      kk_integer_t _x_2 = _con_x1891->hours;
      kk_integer_t _pat_0_2 = _con_x1891->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(_x_5, _ctx);
      }
      else {
        kk_integer_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(_x_5, _ctx);
      }
      _x_x1886 = _x_2; /*int*/
    }
  }
  kk_integer_t _x_x1892;
  {
    struct kk_std_time_date_Clock* _con_x1893 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_0_0 = _con_x1893->seconds;
    kk_integer_t _x_0_0 = _con_x1893->hours;
    kk_integer_dup(_x_0_0, _ctx);
    _x_x1892 = _x_0_0; /*int*/
  }
  _x_x1885 = kk_integer_add(_x_x1886,_x_x1892,kk_context()); /*int*/
  kk_integer_t _x_x1894;
  kk_integer_t _x_x1895;
  {
    struct kk_std_time_time_Time* _con_x1896 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_5_0 = _con_x1896->date;
    kk_std_time_date__clock _x_5_0 = _con_x1896->clock;
    kk_std_time_calendar__calendar _pat_7_3_0 = _con_x1896->calendar;
    kk_std_time_duration__duration _pat_16_1_0 = _con_x1896->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1_0 = _con_x1896->timezone;
    kk_std_time_instant__instant _pat_23_1_0 = _con_x1896->instant;
    struct kk_std_time_date_Clock* _con_x1897 = kk_std_time_date__as_Clock(_x_5_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1898 = kk_std_time_calendar__as_Calendar(_pat_7_3_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1899 = kk_std_time_calendar__as_Timezone(_pat_19_1_0, _ctx);
    kk_std_time_date__clock_dup(_x_5_0, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1900 = kk_std_time_date__as_Clock(_x_5_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_1_1_0 = _con_x1900->seconds;
      kk_integer_t _pat_0_1_0 = _con_x1900->hours;
      kk_integer_t _x_1_0 = _con_x1900->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_5_0, _ctx)) {
        kk_integer_drop(_pat_0_1_0, _ctx);
        kk_datatype_ptr_free(_x_5_0, _ctx);
      }
      else {
        kk_integer_dup(_x_1_0, _ctx);
        kk_datatype_ptr_decref(_x_5_0, _ctx);
      }
      _x_x1895 = _x_1_0; /*int*/
    }
  }
  kk_integer_t _x_x1901;
  {
    struct kk_std_time_date_Clock* _con_x1902 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _pat_1_2_0 = _con_x1902->seconds;
    kk_integer_t _x_2_0 = _con_x1902->minutes;
    kk_integer_dup(_x_2_0, _ctx);
    _x_x1901 = _x_2_0; /*int*/
  }
  _x_x1894 = kk_integer_add(_x_x1895,_x_x1901,kk_context()); /*int*/
  kk_std_num_ddouble__ddouble _x_x1903;
  kk_std_num_ddouble__ddouble _x_x1904;
  {
    struct kk_std_time_time_Time* _con_x1905 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_5_1 = _con_x1905->date;
    kk_std_time_date__clock _x_5_1 = _con_x1905->clock;
    kk_std_time_calendar__calendar _pat_7_3_1 = _con_x1905->calendar;
    kk_std_time_duration__duration _pat_16_1_1 = _con_x1905->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1_1 = _con_x1905->timezone;
    kk_std_time_instant__instant _pat_23_1_1 = _con_x1905->instant;
    struct kk_std_time_date_Clock* _con_x1906 = kk_std_time_date__as_Clock(_x_5_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1907 = kk_std_time_calendar__as_Calendar(_pat_7_3_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1908 = kk_std_time_calendar__as_Timezone(_pat_19_1_1, _ctx);
    kk_std_time_date__clock_dup(_x_5_1, _ctx);
    {
      struct kk_std_time_date_Clock* _con_x1909 = kk_std_time_date__as_Clock(_x_5_1, _ctx);
      kk_std_num_ddouble__ddouble _x_3 = _con_x1909->seconds;
      kk_integer_t _pat_0_3 = _con_x1909->hours;
      kk_integer_t _pat_1_3 = _con_x1909->minutes;
      if kk_likely(kk_datatype_ptr_is_unique(_x_5_1, _ctx)) {
        kk_integer_drop(_pat_1_3, _ctx);
        kk_integer_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(_x_5_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_5_1, _ctx);
      }
      _x_x1904 = _x_3; /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1910;
  {
    struct kk_std_time_date_Clock* _con_x1911 = kk_std_time_date__as_Clock(c, _ctx);
    kk_std_num_ddouble__ddouble _x_4 = _con_x1911->seconds;
    kk_integer_t _pat_0_4 = _con_x1911->hours;
    kk_integer_t _pat_1_4 = _con_x1911->minutes;
    if kk_likely(kk_datatype_ptr_is_unique(c, _ctx)) {
      kk_integer_drop(_pat_1_4, _ctx);
      kk_integer_drop(_pat_0_4, _ctx);
      kk_datatype_ptr_free(c, _ctx);
    }
    else {
      kk_datatype_ptr_decref(c, _ctx);
    }
    _x_x1910 = _x_4; /*std/num/ddouble/ddouble*/
  }
  _x_x1903 = kk_std_num_ddouble__lp__plus__rp_(_x_x1904, _x_x1910, _ctx); /*std/num/ddouble/ddouble*/
  _b_x364_367 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x1885, _x_x1894, _x_x1903, _ctx); /*std/time/date/clock*/
  kk_std_time_instant__timescale _x_x1912;
  {
    struct kk_std_time_time_Time* _con_x1913 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1913->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1913->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1913->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1913->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1913->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1913->instant;
    struct kk_std_time_date_Clock* _con_x1914 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1915 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1916 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0 = _x_0.since;
      kk_std_time_instant__timescale _x = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1917 = kk_std_time_timestamp__as_Timestamp(_pat_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1918 = kk_std_time_instant__as_Timescale(_x, _ctx);
      kk_std_time_instant__timescale_dup(_x, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      _x_x1912 = _x; /*std/time/instant/timescale*/
    }
  }
  kk_std_time_date__date _x_x1919;
  {
    struct kk_std_time_time_Time* _con_x1920 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_1 = _con_x1920->date;
    kk_std_time_date__clock _pat_3_1 = _con_x1920->clock;
    kk_std_time_calendar__calendar _pat_7_1 = _con_x1920->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x1920->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x1920->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x1920->instant;
    struct kk_std_time_date_Clock* _con_x1921 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1922 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1923 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_1, _ctx);
    _x_x1919 = _x_1; /*std/time/date/date*/
  }
  kk_std_core_types__optional _x_x1924 = kk_std_core_types__new_Optional(kk_std_time_date__clock_box(_b_x364_367, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1925;
  kk_box_t _x_x1926;
  kk_std_time_calendar__timezone _x_x1927;
  {
    struct kk_std_time_time_Time* _con_x1928 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_6 = _con_x1928->date;
    kk_std_time_date__clock _pat_4_4 = _con_x1928->clock;
    kk_std_time_calendar__calendar _pat_8_4 = _con_x1928->calendar;
    kk_std_time_duration__duration _pat_17_2 = _con_x1928->tzdelta;
    kk_std_time_calendar__timezone _x_6 = _con_x1928->timezone;
    kk_std_time_instant__instant _pat_23_2 = _con_x1928->instant;
    struct kk_std_time_date_Clock* _con_x1929 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1930 = kk_std_time_calendar__as_Calendar(_pat_8_4, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1931 = kk_std_time_calendar__as_Timezone(_x_6, _ctx);
    kk_std_time_calendar__timezone_dup(_x_6, _ctx);
    _x_x1927 = _x_6; /*std/time/calendar/timezone*/
  }
  _x_x1926 = kk_std_time_calendar__timezone_box(_x_x1927, _ctx); /*7*/
  _x_x1925 = kk_std_core_types__new_Optional(_x_x1926, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1932;
  kk_box_t _x_x1933;
  kk_std_time_calendar__calendar _x_x1934;
  {
    struct kk_std_time_time_Time* _con_x1935 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_7 = _con_x1935->date;
    kk_std_time_date__clock _pat_4_5 = _con_x1935->clock;
    kk_std_time_calendar__calendar _x_7 = _con_x1935->calendar;
    kk_std_time_duration__duration _pat_16_3 = _con_x1935->tzdelta;
    kk_std_time_calendar__timezone _pat_19_3 = _con_x1935->timezone;
    kk_std_time_instant__instant _pat_23_3 = _con_x1935->instant;
    struct kk_std_time_date_Clock* _con_x1936 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1937 = kk_std_time_calendar__as_Calendar(_x_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1938 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
    kk_string_t _pat_18_3 = _con_x1935->tzabbrv;
    kk_integer_t _pat_5_5 = _con_x1936->hours;
    kk_integer_t _pat_6_5 = _con_x1936->minutes;
    kk_string_t _pat_20_3 = _con_x1938->name;
    kk_function_t _pat_21_3 = _con_x1938->utc_delta;
    kk_function_t _pat_22_3 = _con_x1938->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_5, _ctx)) {
        kk_integer_drop(_pat_6_5, _ctx);
        kk_integer_drop(_pat_5_5, _ctx);
        kk_datatype_ptr_free(_pat_4_5, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_5, _ctx);
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
      kk_std_time_date__date_drop(_pat_0_7, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_calendar__calendar_dup(_x_7, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1934 = _x_7; /*std/time/calendar/calendar*/
  }
  _x_x1933 = kk_std_time_calendar__calendar_box(_x_x1934, _ctx); /*7*/
  _x_x1932 = kk_std_core_types__new_Optional(_x_x1933, _ctx); /*? 7*/
  return kk_std_time_time_timescale_fs_date_fs_time(_x_x1912, _x_x1919, _x_x1924, _x_x1925, _x_x1932, _ctx);
}
 
// Add  a specified number of days to a calendar time. Takes leap years etc. into account.
// `time(2016,12,31,12).add-days(1).show == "2017-01-01T12:00:00Z"` &quad; (over a leap second)
// `time(1582,10,4,cal=cal-jg).add-days(1).show == "1582-10-15T00:00:00Z JG"` &quad; (transition from Julian (`cal-julian`) to Gregorian (`cal-gregorian`) calendar)

kk_std_time_time__time kk_std_time_time_add_days(kk_std_time_time__time t, kk_integer_t days, kk_std_core_types__optional c, kk_context_t* _ctx) { /* (t : time, days : int, c : ? std/time/date/clock) -> time */ 
  kk_std_time_date__date _x_x1939 = kk_std_time_date__new_Date(kk_integer_from_small(0), kk_integer_from_small(0), days, _ctx); /*std/time/date/date*/
  kk_std_core_types__optional _x_x1940;
  kk_box_t _x_x1941;
  kk_std_time_date__clock _x_x1942;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x370 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_3985 = kk_std_time_date__clock_unbox(_box_x370, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_3985, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x1942 = _uniq_c_3985; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x1942 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x1941 = kk_std_time_date__clock_box(_x_x1942, _ctx); /*7*/
  _x_x1940 = kk_std_core_types__new_Optional(_x_x1941, _ctx); /*? 7*/
  return kk_std_time_time_add_date(t, _x_x1939, _x_x1940, _ctx);
}
 
// Add  a specified number of weeks to a calendar time.

kk_std_time_time__time kk_std_time_time_add_weeks(kk_std_time_time__time t, kk_integer_t weeks, kk_context_t* _ctx) { /* (t : time, weeks : int) -> time */ 
  kk_integer_t days_10139 = kk_integer_mul(weeks,(kk_integer_from_small(7)),kk_context()); /*int*/;
  kk_std_time_date__date _x_x1943 = kk_std_time_date__new_Date(kk_integer_from_small(0), kk_integer_from_small(0), days_10139, _ctx); /*std/time/date/date*/
  kk_std_core_types__optional _x_x1944;
  kk_box_t _x_x1945;
  kk_std_time_date__clock _x_x1946;
  kk_std_core_types__optional _match_x712 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x712, _ctx)) {
    kk_box_t _box_x373 = _match_x712._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_3985 = kk_std_time_date__clock_unbox(_box_x373, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_3985, _ctx);
    kk_std_core_types__optional_drop(_match_x712, _ctx);
    _x_x1946 = _uniq_c_3985; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x712, _ctx);
    _x_x1946 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x1945 = kk_std_time_date__clock_box(_x_x1946, _ctx); /*7*/
  _x_x1944 = kk_std_core_types__new_Optional(_x_x1945, _ctx); /*? 7*/
  return kk_std_time_time_add_date(t, _x_x1943, _x_x1944, _ctx);
}
 
// Subtract an SI second `:duration` from a time.
// `(time(2016,1,1,0,0,0,0.5) - duration(1)).show == "2015-12-31T23:59:59.500Z"`
// `(time(2017,1,1,0,0,0,0.5) - duration(1)).show == "2016-12-31T23:59:60.500Z"` &quad; (into a leap second)

kk_std_time_time__time kk_std_time_time_duration_fs__lp__dash__rp_(kk_std_time_time__time t, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (t : time, d : std/time/duration/duration) -> time */ 
  kk_std_time_duration__duration d_0_10142;
  kk_std_num_ddouble__ddouble _x_x1949;
  double _x_x1950;
  double _x_x1951;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = d.secs;
    {
      double _x_2 = _x_1_0.hi;
      _x_x1951 = _x_2; /*float64*/
    }
  }
  _x_x1950 = (-_x_x1951); /*float64*/
  double _x_x1952;
  double _x_x1953;
  {
    kk_std_num_ddouble__ddouble _x_1_0_0 = d.secs;
    {
      double _x_0_0 = _x_1_0_0.lo;
      _x_x1953 = _x_0_0; /*float64*/
    }
  }
  _x_x1952 = (-_x_x1953); /*float64*/
  _x_x1949 = kk_std_num_ddouble__new_Ddouble(_x_x1950, _x_x1952, _ctx); /*std/num/ddouble/ddouble*/
  d_0_10142 = kk_std_time_duration__new_Duration(_x_x1949, _ctx); /*std/time/duration/duration*/
  kk_std_time_instant__instant _x_x1954;
  kk_std_time_instant__instant _x_x1955;
  {
    struct kk_std_time_time_Time* _con_x1956 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1956->date;
    kk_std_time_date__clock _pat_4 = _con_x1956->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1956->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1956->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1956->timezone;
    kk_std_time_instant__instant _x = _con_x1956->instant;
    struct kk_std_time_date_Clock* _con_x1957 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1958 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1959 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x1955 = _x; /*std/time/instant/instant*/
  }
  _x_x1954 = kk_std_time_instant__lp__plus__rp_(_x_x1955, d_0_10142, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x1960;
  kk_box_t _x_x1961;
  kk_std_time_calendar__timezone _x_x1962;
  {
    struct kk_std_time_time_Time* _con_x1963 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1963->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1963->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1963->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1963->tzdelta;
    kk_std_time_calendar__timezone _x_0 = _con_x1963->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x1963->instant;
    struct kk_std_time_date_Clock* _con_x1964 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1965 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1966 = kk_std_time_calendar__as_Timezone(_x_0, _ctx);
    kk_std_time_calendar__timezone_dup(_x_0, _ctx);
    _x_x1962 = _x_0; /*std/time/calendar/timezone*/
  }
  _x_x1961 = kk_std_time_calendar__timezone_box(_x_x1962, _ctx); /*7*/
  _x_x1960 = kk_std_core_types__new_Optional(_x_x1961, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x1967;
  kk_box_t _x_x1968;
  kk_std_time_calendar__calendar _x_x1969;
  {
    struct kk_std_time_time_Time* _con_x1970 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_1 = _con_x1970->date;
    kk_std_time_date__clock _pat_4_1 = _con_x1970->clock;
    kk_std_time_calendar__calendar _x_1 = _con_x1970->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x1970->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x1970->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x1970->instant;
    struct kk_std_time_date_Clock* _con_x1971 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1972 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1973 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_string_t _pat_18_1 = _con_x1970->tzabbrv;
    kk_integer_t _pat_5_1 = _con_x1971->hours;
    kk_integer_t _pat_6_1 = _con_x1971->minutes;
    kk_string_t _pat_20_1 = _con_x1973->name;
    kk_function_t _pat_21_1 = _con_x1973->utc_delta;
    kk_function_t _pat_22_1 = _con_x1973->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_1, _ctx)) {
        kk_integer_drop(_pat_6_1, _ctx);
        kk_integer_drop(_pat_5_1, _ctx);
        kk_datatype_ptr_free(_pat_4_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_1, _ctx);
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
      kk_std_time_date__date_drop(_pat_0_1, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_calendar__calendar_dup(_x_1, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x1969 = _x_1; /*std/time/calendar/calendar*/
  }
  _x_x1968 = kk_std_time_calendar__calendar_box(_x_x1969, _ctx); /*7*/
  _x_x1967 = kk_std_core_types__new_Optional(_x_x1968, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x1954, _x_x1960, _x_x1967, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the exact SI second duration between to times.
// `(time(2016,1,1,0,0,0,0.5) - time(2015,12,31,23,59,59)).show == "1.5s"`
// `(time(2017,1,1,0,0,0,0.5) - time(2016,12,31,23,59,59)).show == "2.5s"`  &quad; (over a leap second)
// `(time(2017,1,1,0,0,0,0.5) - time(2017,1,1,2,59,59,tz=tz-fixed(3)).show == "2.5s"`  &quad; (GMT+3, and over a leap second)

kk_std_time_duration__duration kk_std_time_time__lp__dash__rp_(kk_std_time_time__time t1, kk_std_time_time__time t2, kk_context_t* _ctx) { /* (t1 : time, t2 : time) -> std/time/duration/duration */ 
  kk_std_time_instant__instant _x_x1974;
  {
    struct kk_std_time_time_Time* _con_x1975 = kk_std_time_time__as_Time(t1, _ctx);
    kk_std_time_date__date _pat_0 = _con_x1975->date;
    kk_std_time_date__clock _pat_4 = _con_x1975->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x1975->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x1975->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x1975->timezone;
    kk_std_time_instant__instant _x = _con_x1975->instant;
    struct kk_std_time_date_Clock* _con_x1976 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1977 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1978 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_string_t _pat_19 = _con_x1975->tzabbrv;
    kk_integer_t _pat_5 = _con_x1976->hours;
    kk_integer_t _pat_6 = _con_x1976->minutes;
    kk_string_t _pat_9 = _con_x1977->name;
    kk_string_t _pat_10 = _con_x1977->long_name;
    kk_string_t _pat_11 = _con_x1977->month_prefix;
    kk_function_t _pat_12 = _con_x1977->show_era;
    kk_function_t _pat_13 = _con_x1977->instant_to_dc;
    kk_function_t _pat_14 = _con_x1977->dc_to_instant;
    kk_function_t _pat_15 = _con_x1977->days_to_date;
    kk_function_t _pat_16 = _con_x1977->date_to_days;
    kk_string_t _pat_21 = _con_x1978->name;
    kk_function_t _pat_22 = _con_x1978->utc_delta;
    kk_function_t _pat_23 = _con_x1978->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t1, _ctx)) {
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
      kk_datatype_ptr_free(t1, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x, _ctx);
      kk_datatype_ptr_decref(t1, _ctx);
    }
    _x_x1974 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__instant _x_x1979;
  {
    struct kk_std_time_time_Time* _con_x1980 = kk_std_time_time__as_Time(t2, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x1980->date;
    kk_std_time_date__clock _pat_4_0 = _con_x1980->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x1980->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x1980->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x1980->timezone;
    kk_std_time_instant__instant _x_0 = _con_x1980->instant;
    struct kk_std_time_date_Clock* _con_x1981 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x1982 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x1983 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x1980->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x1981->hours;
    kk_integer_t _pat_6_0 = _con_x1981->minutes;
    kk_string_t _pat_9_0 = _con_x1982->name;
    kk_string_t _pat_10_0 = _con_x1982->long_name;
    kk_string_t _pat_11_0 = _con_x1982->month_prefix;
    kk_function_t _pat_12_0 = _con_x1982->show_era;
    kk_function_t _pat_13_0 = _con_x1982->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x1982->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x1982->days_to_date;
    kk_function_t _pat_16_0 = _con_x1982->date_to_days;
    kk_string_t _pat_21_0 = _con_x1983->name;
    kk_function_t _pat_22_0 = _con_x1983->utc_delta;
    kk_function_t _pat_23_0 = _con_x1983->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t2, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t2, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t2, _ctx);
    }
    _x_x1979 = _x_0; /*std/time/instant/instant*/
  }
  return kk_std_time_instant__lp__dash__rp_(_x_x1974, _x_x1979, _ctx);
}
 
// Copy a `:time` with optionally changing any of its attributes.
// `t.copy(month=1,day=1,hours=0,minutes=0,seconds=zero)` &quad; (copy to start of the year)
// `t.copy(month=t.month+2,day=t.day+3)                 ` &quad; (add 2 months and 3 days)
// `t.copy(tz=tz-local())                               ` &quad; (change to a different time zone)

kk_std_time_time__time kk_std_time_time_copy(kk_std_time_time__time t, kk_std_core_types__optional year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional seconds_0, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (t : time, year : ? int, month : ? int, day : ? int, hours : ? int, minutes : ? int, seconds : ? std/num/ddouble/ddouble, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 
  kk_std_time_instant__timescale _x_x1984;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x380 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_4175 = kk_std_time_instant__timescale_unbox(_box_x380, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_4175, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    _x_x1984 = _uniq_ts_4175; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1985 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_15 = _con_x1985->date;
      kk_std_time_date__clock _pat_4_9 = _con_x1985->clock;
      kk_std_time_calendar__calendar _pat_8_9 = _con_x1985->calendar;
      kk_std_time_duration__duration _pat_17_7 = _con_x1985->tzdelta;
      kk_std_time_calendar__timezone _pat_20_7 = _con_x1985->timezone;
      kk_std_time_instant__instant _x_14 = _con_x1985->instant;
      struct kk_std_time_date_Clock* _con_x1986 = kk_std_time_date__as_Clock(_pat_4_9, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1987 = kk_std_time_calendar__as_Calendar(_pat_8_9, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1988 = kk_std_time_calendar__as_Timezone(_pat_20_7, _ctx);
      kk_std_time_instant__instant_dup(_x_14, _ctx);
      {
        kk_std_time_timestamp__timestamp _pat_0_14 = _x_14.since;
        kk_std_time_instant__timescale _x_13 = _x_14.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1989 = kk_std_time_timestamp__as_Timestamp(_pat_0_14, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1990 = kk_std_time_instant__as_Timescale(_x_13, _ctx);
        kk_std_time_instant__timescale_dup(_x_13, _ctx);
        kk_std_time_instant__instant_drop(_x_14, _ctx);
        _x_x1984 = _x_13; /*std/time/instant/timescale*/
      }
    }
  }
  kk_std_time_date__date _x_x1991;
  kk_integer_t _x_x1992;
  if (kk_std_core_types__is_Optional(year_0, _ctx)) {
    kk_box_t _box_x381 = year_0._cons._Optional.value;
    kk_integer_t _uniq_year_4111 = kk_integer_unbox(_box_x381, _ctx);
    kk_integer_dup(_uniq_year_4111, _ctx);
    kk_std_core_types__optional_drop(year_0, _ctx);
    _x_x1992 = _uniq_year_4111; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(year_0, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1993 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0 = _con_x1993->date;
      kk_std_time_date__clock _pat_3 = _con_x1993->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x1993->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x1993->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x1993->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x1993->instant;
      struct kk_std_time_date_Clock* _con_x1994 = kk_std_time_date__as_Clock(_pat_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x1995 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x1996 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_date__date_dup(_x_0, _ctx);
      {
        kk_integer_t _x = _x_0.year;
        kk_integer_dup(_x, _ctx);
        kk_std_time_date__date_drop(_x_0, _ctx);
        _x_x1992 = _x; /*int*/
      }
    }
  }
  kk_integer_t _x_x1997;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x382 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_4119 = kk_integer_unbox(_box_x382, _ctx);
    kk_integer_dup(_uniq_month_4119, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x1997 = _uniq_month_4119; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    {
      struct kk_std_time_time_Time* _con_x1998 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_2 = _con_x1998->date;
      kk_std_time_date__clock _pat_3_0 = _con_x1998->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x1998->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x1998->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x1998->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x1998->instant;
      struct kk_std_time_date_Clock* _con_x1999 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2000 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2001 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__date_dup(_x_2, _ctx);
      {
        kk_integer_t _x_1 = _x_2.month;
        kk_integer_dup(_x_1, _ctx);
        kk_std_time_date__date_drop(_x_2, _ctx);
        _x_x1997 = _x_1; /*int*/
      }
    }
  }
  kk_integer_t _x_x2002;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x383 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_4127 = kk_integer_unbox(_box_x383, _ctx);
    kk_integer_dup(_uniq_day_4127, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2002 = _uniq_day_4127; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2003 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_4 = _con_x2003->date;
      kk_std_time_date__clock _pat_3_2 = _con_x2003->clock;
      kk_std_time_calendar__calendar _pat_7_1 = _con_x2003->calendar;
      kk_std_time_duration__duration _pat_16_1 = _con_x2003->tzdelta;
      kk_std_time_calendar__timezone _pat_19_1 = _con_x2003->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x2003->instant;
      struct kk_std_time_date_Clock* _con_x2004 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2005 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2006 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
      kk_std_time_date__date_dup(_x_4, _ctx);
      {
        kk_integer_t _x_3 = _x_4.day;
        kk_integer_dup(_x_3, _ctx);
        kk_std_time_date__date_drop(_x_4, _ctx);
        _x_x2002 = _x_3; /*int*/
      }
    }
  }
  _x_x1991 = kk_std_time_date__new_Date(_x_x1992, _x_x1997, _x_x2002, _ctx); /*std/time/date/date*/
  kk_std_core_types__optional _x_x2007;
  kk_box_t _x_x2008;
  kk_std_time_date__clock _x_x2009;
  kk_integer_t _x_x2010;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x384 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_4135 = kk_integer_unbox(_box_x384, _ctx);
    kk_integer_dup(_uniq_hours_4135, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2010 = _uniq_hours_4135; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2011 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_7 = _con_x2011->date;
      kk_std_time_date__clock _x_6 = _con_x2011->clock;
      kk_std_time_calendar__calendar _pat_7_2 = _con_x2011->calendar;
      kk_std_time_duration__duration _pat_16_2 = _con_x2011->tzdelta;
      kk_std_time_calendar__timezone _pat_19_2 = _con_x2011->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x2011->instant;
      struct kk_std_time_date_Clock* _con_x2012 = kk_std_time_date__as_Clock(_x_6, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2013 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2014 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
      kk_std_time_date__clock_dup(_x_6, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2015 = kk_std_time_date__as_Clock(_x_6, _ctx);
        kk_std_num_ddouble__ddouble _pat_1_7 = _con_x2015->seconds;
        kk_integer_t _x_5 = _con_x2015->hours;
        kk_integer_t _pat_0_6 = _con_x2015->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_6, _ctx)) {
          kk_integer_drop(_pat_0_6, _ctx);
          kk_datatype_ptr_free(_x_6, _ctx);
        }
        else {
          kk_integer_dup(_x_5, _ctx);
          kk_datatype_ptr_decref(_x_6, _ctx);
        }
        _x_x2010 = _x_5; /*int*/
      }
    }
  }
  kk_integer_t _x_x2016;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x385 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_4143 = kk_integer_unbox(_box_x385, _ctx);
    kk_integer_dup(_uniq_minutes_4143, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2016 = _uniq_minutes_4143; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2017 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_9 = _con_x2017->date;
      kk_std_time_date__clock _x_8 = _con_x2017->clock;
      kk_std_time_calendar__calendar _pat_7_4 = _con_x2017->calendar;
      kk_std_time_duration__duration _pat_16_3 = _con_x2017->tzdelta;
      kk_std_time_calendar__timezone _pat_19_3 = _con_x2017->timezone;
      kk_std_time_instant__instant _pat_23_3 = _con_x2017->instant;
      struct kk_std_time_date_Clock* _con_x2018 = kk_std_time_date__as_Clock(_x_8, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2019 = kk_std_time_calendar__as_Calendar(_pat_7_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2020 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
      kk_std_time_date__clock_dup(_x_8, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2021 = kk_std_time_date__as_Clock(_x_8, _ctx);
        kk_std_num_ddouble__ddouble _pat_1_9 = _con_x2021->seconds;
        kk_integer_t _pat_0_8 = _con_x2021->hours;
        kk_integer_t _x_7 = _con_x2021->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_8, _ctx)) {
          kk_integer_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(_x_8, _ctx);
        }
        else {
          kk_integer_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(_x_8, _ctx);
        }
        _x_x2016 = _x_7; /*int*/
      }
    }
  }
  kk_std_num_ddouble__ddouble _x_x2022;
  if (kk_std_core_types__is_Optional(seconds_0, _ctx)) {
    kk_box_t _box_x386 = seconds_0._cons._Optional.value;
    kk_std_num_ddouble__ddouble _uniq_seconds_4151 = kk_std_num_ddouble__ddouble_unbox(_box_x386, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(seconds_0, _ctx);
    _x_x2022 = _uniq_seconds_4151; /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_core_types__optional_drop(seconds_0, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2023 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_11 = _con_x2023->date;
      kk_std_time_date__clock _x_10 = _con_x2023->clock;
      kk_std_time_calendar__calendar _pat_7_5 = _con_x2023->calendar;
      kk_std_time_duration__duration _pat_16_4 = _con_x2023->tzdelta;
      kk_std_time_calendar__timezone _pat_19_4 = _con_x2023->timezone;
      kk_std_time_instant__instant _pat_23_4 = _con_x2023->instant;
      struct kk_std_time_date_Clock* _con_x2024 = kk_std_time_date__as_Clock(_x_10, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2025 = kk_std_time_calendar__as_Calendar(_pat_7_5, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2026 = kk_std_time_calendar__as_Timezone(_pat_19_4, _ctx);
      kk_std_time_date__clock_dup(_x_10, _ctx);
      {
        struct kk_std_time_date_Clock* _con_x2027 = kk_std_time_date__as_Clock(_x_10, _ctx);
        kk_std_num_ddouble__ddouble _x_9 = _con_x2027->seconds;
        kk_integer_t _pat_0_10 = _con_x2027->hours;
        kk_integer_t _pat_1_11 = _con_x2027->minutes;
        if kk_likely(kk_datatype_ptr_is_unique(_x_10, _ctx)) {
          kk_integer_drop(_pat_1_11, _ctx);
          kk_integer_drop(_pat_0_10, _ctx);
          kk_datatype_ptr_free(_x_10, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_10, _ctx);
        }
        _x_x2022 = _x_9; /*std/num/ddouble/ddouble*/
      }
    }
  }
  _x_x2009 = kk_std_time_date__new_Clock(kk_reuse_null, 0, _x_x2010, _x_x2016, _x_x2022, _ctx); /*std/time/date/clock*/
  _x_x2008 = kk_std_time_date__clock_box(_x_x2009, _ctx); /*7*/
  _x_x2007 = kk_std_core_types__new_Optional(_x_x2008, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2028;
  kk_box_t _x_x2029;
  kk_std_time_calendar__timezone _x_x2030;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x388 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_4159 = kk_std_time_calendar__timezone_unbox(_box_x388, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_4159, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x2030 = _uniq_tz_4159; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2031 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_12 = _con_x2031->date;
      kk_std_time_date__clock _pat_4_6 = _con_x2031->clock;
      kk_std_time_calendar__calendar _pat_8_6 = _con_x2031->calendar;
      kk_std_time_duration__duration _pat_17_5 = _con_x2031->tzdelta;
      kk_std_time_calendar__timezone _x_11 = _con_x2031->timezone;
      kk_std_time_instant__instant _pat_23_5 = _con_x2031->instant;
      struct kk_std_time_date_Clock* _con_x2032 = kk_std_time_date__as_Clock(_pat_4_6, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2033 = kk_std_time_calendar__as_Calendar(_pat_8_6, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2034 = kk_std_time_calendar__as_Timezone(_x_11, _ctx);
      kk_std_time_calendar__timezone_dup(_x_11, _ctx);
      _x_x2030 = _x_11; /*std/time/calendar/timezone*/
    }
  }
  _x_x2029 = kk_std_time_calendar__timezone_box(_x_x2030, _ctx); /*7*/
  _x_x2028 = kk_std_core_types__new_Optional(_x_x2029, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2035;
  kk_box_t _x_x2036;
  kk_std_time_calendar__calendar _x_x2037;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x390 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_4167 = kk_std_time_calendar__calendar_unbox(_box_x390, KK_BORROWED, _ctx);
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_4167, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2037 = _uniq_cal_4167; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2038 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_13 = _con_x2038->date;
      kk_std_time_date__clock _pat_4_7 = _con_x2038->clock;
      kk_std_time_calendar__calendar _x_12 = _con_x2038->calendar;
      kk_std_time_duration__duration _pat_16_6 = _con_x2038->tzdelta;
      kk_std_time_calendar__timezone _pat_19_6 = _con_x2038->timezone;
      kk_std_time_instant__instant _pat_23_6 = _con_x2038->instant;
      struct kk_std_time_date_Clock* _con_x2039 = kk_std_time_date__as_Clock(_pat_4_7, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2040 = kk_std_time_calendar__as_Calendar(_x_12, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2041 = kk_std_time_calendar__as_Timezone(_pat_19_6, _ctx);
      kk_string_t _pat_18_6 = _con_x2038->tzabbrv;
      kk_integer_t _pat_5_7 = _con_x2039->hours;
      kk_integer_t _pat_6_7 = _con_x2039->minutes;
      kk_string_t _pat_20_6 = _con_x2041->name;
      kk_function_t _pat_21_6 = _con_x2041->utc_delta;
      kk_function_t _pat_22_6 = _con_x2041->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_7, _ctx)) {
          kk_integer_drop(_pat_6_7, _ctx);
          kk_integer_drop(_pat_5_7, _ctx);
          kk_datatype_ptr_free(_pat_4_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_7, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_6, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_6, _ctx)) {
          kk_function_drop(_pat_22_6, _ctx);
          kk_function_drop(_pat_21_6, _ctx);
          kk_string_drop(_pat_20_6, _ctx);
          kk_datatype_ptr_free(_pat_19_6, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_6, _ctx);
        }
        kk_string_drop(_pat_18_6, _ctx);
        kk_std_time_date__date_drop(_pat_0_13, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_calendar__calendar_dup(_x_12, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      _x_x2037 = _x_12; /*std/time/calendar/calendar*/
    }
  }
  _x_x2036 = kk_std_time_calendar__calendar_box(_x_x2037, _ctx); /*7*/
  _x_x2035 = kk_std_core_types__new_Optional(_x_x2036, _ctx); /*? 7*/
  return kk_std_time_time_timescale_fs_date_fs_time(_x_x1984, _x_x1991, _x_x2007, _x_x2028, _x_x2035, _ctx);
}
 
// Copy a `:time` with a new `:date` and optional `:clock` (=`t.clock`), and optionally a new
// timezone (=`t.timezone`) and calendar (=`t.calendar`).

kk_std_time_time__time kk_std_time_time_copy_dc(kk_std_time_time__time t, kk_std_core_types__optional d, kk_std_core_types__optional c, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (t : time, d : ? std/time/date/date, c : ? std/time/date/clock, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> time */ 
  kk_std_time_instant__timescale _x_x2042;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x395 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_4267 = kk_std_time_instant__timescale_unbox(_box_x395, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_4267, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    _x_x2042 = _uniq_ts_4267; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2043 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_5 = _con_x2043->date;
      kk_std_time_date__clock _pat_4_5 = _con_x2043->clock;
      kk_std_time_calendar__calendar _pat_8_5 = _con_x2043->calendar;
      kk_std_time_duration__duration _pat_17_3 = _con_x2043->tzdelta;
      kk_std_time_calendar__timezone _pat_20_3 = _con_x2043->timezone;
      kk_std_time_instant__instant _x_4 = _con_x2043->instant;
      struct kk_std_time_date_Clock* _con_x2044 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2045 = kk_std_time_calendar__as_Calendar(_pat_8_5, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2046 = kk_std_time_calendar__as_Timezone(_pat_20_3, _ctx);
      kk_std_time_instant__instant_dup(_x_4, _ctx);
      {
        kk_std_time_timestamp__timestamp _pat_0_4 = _x_4.since;
        kk_std_time_instant__timescale _x_3 = _x_4.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x2047 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
        struct kk_std_time_instant_Timescale* _con_x2048 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
        kk_std_time_instant__timescale_dup(_x_3, _ctx);
        kk_std_time_instant__instant_drop(_x_4, _ctx);
        _x_x2042 = _x_3; /*std/time/instant/timescale*/
      }
    }
  }
  kk_std_time_date__date _x_x2049;
  if (kk_std_core_types__is_Optional(d, _ctx)) {
    kk_box_t _box_x396 = d._cons._Optional.value;
    kk_std_time_date__date _uniq_d_4235 = kk_std_time_date__date_unbox(_box_x396, KK_BORROWED, _ctx);
    kk_std_time_date__date_dup(_uniq_d_4235, _ctx);
    kk_std_core_types__optional_drop(d, _ctx);
    _x_x2049 = _uniq_d_4235; /*std/time/date/date*/
  }
  else {
    kk_std_core_types__optional_drop(d, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2050 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x = _con_x2050->date;
      kk_std_time_date__clock _pat_3 = _con_x2050->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x2050->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x2050->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x2050->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x2050->instant;
      struct kk_std_time_date_Clock* _con_x2051 = kk_std_time_date__as_Clock(_pat_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2052 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2053 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_std_time_date__date_dup(_x, _ctx);
      _x_x2049 = _x; /*std/time/date/date*/
    }
  }
  kk_std_core_types__optional _x_x2054;
  kk_box_t _x_x2055;
  kk_std_time_date__clock _x_x2056;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x397 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_4243 = kk_std_time_date__clock_unbox(_box_x397, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_4243, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2056 = _uniq_c_4243; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2057 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_1 = _con_x2057->date;
      kk_std_time_date__clock _x_0 = _con_x2057->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x2057->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2057->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2057->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2057->instant;
      struct kk_std_time_date_Clock* _con_x2058 = kk_std_time_date__as_Clock(_x_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2059 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2060 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__clock_dup(_x_0, _ctx);
      _x_x2056 = _x_0; /*std/time/date/clock*/
    }
  }
  _x_x2055 = kk_std_time_date__clock_box(_x_x2056, _ctx); /*7*/
  _x_x2054 = kk_std_core_types__new_Optional(_x_x2055, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2061;
  kk_box_t _x_x2062;
  kk_std_time_calendar__timezone _x_x2063;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x399 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_4251 = kk_std_time_calendar__timezone_unbox(_box_x399, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_4251, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x2063 = _uniq_tz_4251; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2064 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_2 = _con_x2064->date;
      kk_std_time_date__clock _pat_4_2 = _con_x2064->clock;
      kk_std_time_calendar__calendar _pat_8_1 = _con_x2064->calendar;
      kk_std_time_duration__duration _pat_17_1 = _con_x2064->tzdelta;
      kk_std_time_calendar__timezone _x_1 = _con_x2064->timezone;
      kk_std_time_instant__instant _pat_23_1 = _con_x2064->instant;
      struct kk_std_time_date_Clock* _con_x2065 = kk_std_time_date__as_Clock(_pat_4_2, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2066 = kk_std_time_calendar__as_Calendar(_pat_8_1, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2067 = kk_std_time_calendar__as_Timezone(_x_1, _ctx);
      kk_std_time_calendar__timezone_dup(_x_1, _ctx);
      _x_x2063 = _x_1; /*std/time/calendar/timezone*/
    }
  }
  _x_x2062 = kk_std_time_calendar__timezone_box(_x_x2063, _ctx); /*7*/
  _x_x2061 = kk_std_core_types__new_Optional(_x_x2062, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2068;
  kk_box_t _x_x2069;
  kk_std_time_calendar__calendar _x_x2070;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x401 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_4259 = kk_std_time_calendar__calendar_unbox(_box_x401, KK_BORROWED, _ctx);
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_4259, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2070 = _uniq_cal_4259; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2071 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x2071->date;
      kk_std_time_date__clock _pat_4_3 = _con_x2071->clock;
      kk_std_time_calendar__calendar _x_2 = _con_x2071->calendar;
      kk_std_time_duration__duration _pat_16_2 = _con_x2071->tzdelta;
      kk_std_time_calendar__timezone _pat_19_2 = _con_x2071->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x2071->instant;
      struct kk_std_time_date_Clock* _con_x2072 = kk_std_time_date__as_Clock(_pat_4_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2073 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2074 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
      kk_string_t _pat_18_2 = _con_x2071->tzabbrv;
      kk_integer_t _pat_5_3 = _con_x2072->hours;
      kk_integer_t _pat_6_3 = _con_x2072->minutes;
      kk_string_t _pat_20_2 = _con_x2074->name;
      kk_function_t _pat_21_2 = _con_x2074->utc_delta;
      kk_function_t _pat_22_2 = _con_x2074->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_3, _ctx)) {
          kk_integer_drop(_pat_6_3, _ctx);
          kk_integer_drop(_pat_5_3, _ctx);
          kk_datatype_ptr_free(_pat_4_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_3, _ctx);
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
        kk_std_time_date__date_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_calendar__calendar_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      _x_x2070 = _x_2; /*std/time/calendar/calendar*/
    }
  }
  _x_x2069 = kk_std_time_calendar__calendar_box(_x_x2070, _ctx); /*7*/
  _x_x2068 = kk_std_core_types__new_Optional(_x_x2069, _ctx); /*? 7*/
  return kk_std_time_time_timescale_fs_date_fs_time(_x_x2042, _x_x2049, _x_x2054, _x_x2061, _x_x2068, _ctx);
}
 
// Return the time at the start of the day of time `t`.

kk_std_time_time__time kk_std_time_time_start_of_day(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> time */ 
  kk_std_time_time__time _x_x2075 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  kk_std_core_types__optional _x_x2076;
  kk_box_t _x_x2077;
  kk_std_time_date__date _x_x2078;
  {
    struct kk_std_time_time_Time* _con_x2079 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x = _con_x2079->date;
    kk_std_time_date__clock _pat_3 = _con_x2079->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2079->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2079->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2079->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2079->instant;
    struct kk_std_time_date_Clock* _con_x2080 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2081 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2082 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2079->tzabbrv;
    kk_integer_t _pat_4 = _con_x2080->hours;
    kk_integer_t _pat_5 = _con_x2080->minutes;
    kk_string_t _pat_8 = _con_x2081->name;
    kk_string_t _pat_9 = _con_x2081->long_name;
    kk_string_t _pat_10 = _con_x2081->month_prefix;
    kk_function_t _pat_11 = _con_x2081->show_era;
    kk_function_t _pat_12 = _con_x2081->instant_to_dc;
    kk_function_t _pat_13 = _con_x2081->dc_to_instant;
    kk_function_t _pat_14 = _con_x2081->days_to_date;
    kk_function_t _pat_15 = _con_x2081->date_to_days;
    kk_string_t _pat_20 = _con_x2082->name;
    kk_function_t _pat_21 = _con_x2082->utc_delta;
    kk_function_t _pat_22 = _con_x2082->utc_inverse;
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
      kk_std_time_date__date_dup(_x, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x2078 = _x; /*std/time/date/date*/
  }
  _x_x2077 = kk_std_time_date__date_box(_x_x2078, _ctx); /*7*/
  _x_x2076 = kk_std_core_types__new_Optional(_x_x2077, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2083;
  kk_box_t _x_x2084;
  kk_std_time_date__clock _x_x2085 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  _x_x2084 = kk_std_time_date__clock_box(_x_x2085, _ctx); /*7*/
  _x_x2083 = kk_std_core_types__new_Optional(_x_x2084, _ctx); /*? 7*/
  return kk_std_time_time_copy_dc(_x_x2075, _x_x2076, _x_x2083, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the time at the start of the month of time `t`.

kk_std_time_time__time kk_std_time_time_start_of_month(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> time */ 
  kk_std_time_time__time _x_x2086 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  kk_std_core_types__optional _x_x2087;
  kk_box_t _x_x2088;
  kk_std_time_date__date _x_x2089;
  kk_integer_t _x_x2090;
  kk_std_core_types__optional _match_x711 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x711, _ctx)) {
    kk_box_t _box_x410 = _match_x711._cons._Optional.value;
    kk_integer_t _uniq_year_102 = kk_integer_unbox(_box_x410, _ctx);
    kk_integer_dup(_uniq_year_102, _ctx);
    kk_std_core_types__optional_drop(_match_x711, _ctx);
    _x_x2090 = _uniq_year_102; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x711, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2091 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0 = _con_x2091->date;
      kk_std_time_date__clock _pat_3_0 = _con_x2091->clock;
      kk_std_time_calendar__calendar _pat_7_0 = _con_x2091->calendar;
      kk_std_time_duration__duration _pat_16_0 = _con_x2091->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0 = _con_x2091->timezone;
      kk_std_time_instant__instant _pat_23_0 = _con_x2091->instant;
      struct kk_std_time_date_Clock* _con_x2092 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2093 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2094 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
      kk_std_time_date__date_dup(_x_0, _ctx);
      {
        kk_integer_t _x_1 = _x_0.year;
        kk_integer_dup(_x_1, _ctx);
        kk_std_time_date__date_drop(_x_0, _ctx);
        _x_x2090 = _x_1; /*int*/
      }
    }
  }
  kk_integer_t _x_x2095;
  kk_std_core_types__optional _match_x710 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x710, _ctx)) {
    kk_box_t _box_x411 = _match_x710._cons._Optional.value;
    kk_integer_t _uniq_month_110 = kk_integer_unbox(_box_x411, _ctx);
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_integer_dup(_uniq_month_110, _ctx);
    kk_std_core_types__optional_drop(_match_x710, _ctx);
    _x_x2095 = _uniq_month_110; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x710, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2096 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_0_0 = _con_x2096->date;
      kk_std_time_date__clock _pat_3_0_0 = _con_x2096->clock;
      kk_std_time_calendar__calendar _pat_7_0_0 = _con_x2096->calendar;
      kk_std_time_duration__duration _pat_16_0_0 = _con_x2096->tzdelta;
      kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2096->timezone;
      kk_std_time_instant__instant _pat_23_0_0 = _con_x2096->instant;
      struct kk_std_time_date_Clock* _con_x2097 = kk_std_time_date__as_Clock(_pat_3_0_0, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2098 = kk_std_time_calendar__as_Calendar(_pat_7_0_0, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2099 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
      kk_string_t _pat_18_0_0 = _con_x2096->tzabbrv;
      kk_integer_t _pat_4_0_0 = _con_x2097->hours;
      kk_integer_t _pat_5_0_0 = _con_x2097->minutes;
      kk_string_t _pat_8_0_0 = _con_x2098->name;
      kk_string_t _pat_9_0_0 = _con_x2098->long_name;
      kk_string_t _pat_10_0_0 = _con_x2098->month_prefix;
      kk_function_t _pat_11_0_0 = _con_x2098->show_era;
      kk_function_t _pat_12_0_0 = _con_x2098->instant_to_dc;
      kk_function_t _pat_13_0_0 = _con_x2098->dc_to_instant;
      kk_function_t _pat_14_0_0 = _con_x2098->days_to_date;
      kk_function_t _pat_15_0_0 = _con_x2098->date_to_days;
      kk_string_t _pat_20_0_0 = _con_x2099->name;
      kk_function_t _pat_21_0_0 = _con_x2099->utc_delta;
      kk_function_t _pat_22_0_0 = _con_x2099->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_7_0_0, _ctx)) {
          kk_string_drop(_pat_9_0_0, _ctx);
          kk_string_drop(_pat_8_0_0, _ctx);
          kk_function_drop(_pat_15_0_0, _ctx);
          kk_function_drop(_pat_14_0_0, _ctx);
          kk_function_drop(_pat_13_0_0, _ctx);
          kk_function_drop(_pat_12_0_0, _ctx);
          kk_function_drop(_pat_11_0_0, _ctx);
          kk_string_drop(_pat_10_0_0, _ctx);
          kk_datatype_ptr_free(_pat_7_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_7_0_0, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0_0, _ctx)) {
          kk_integer_drop(_pat_5_0_0, _ctx);
          kk_integer_drop(_pat_4_0_0, _ctx);
          kk_datatype_ptr_free(_pat_3_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_3_0_0, _ctx);
        }
        kk_std_time_instant__instant_drop(_pat_23_0_0, _ctx);
        if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0_0, _ctx)) {
          kk_function_drop(_pat_22_0_0, _ctx);
          kk_function_drop(_pat_21_0_0, _ctx);
          kk_string_drop(_pat_20_0_0, _ctx);
          kk_datatype_ptr_free(_pat_19_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_19_0_0, _ctx);
        }
        kk_string_drop(_pat_18_0_0, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_date__date_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        kk_integer_t _x_0_0_0 = _x_0_0.month;
        kk_integer_dup(_x_0_0_0, _ctx);
        kk_std_time_date__date_drop(_x_0_0, _ctx);
        _x_x2095 = _x_0_0_0; /*int*/
      }
    }
  }
  _x_x2089 = kk_std_time_date__new_Date(_x_x2090, _x_x2095, kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  _x_x2088 = kk_std_time_date__date_box(_x_x2089, _ctx); /*7*/
  _x_x2087 = kk_std_core_types__new_Optional(_x_x2088, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2100;
  kk_box_t _x_x2101;
  kk_std_time_date__clock _x_x2102 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  _x_x2101 = kk_std_time_date__clock_box(_x_x2102, _ctx); /*7*/
  _x_x2100 = kk_std_core_types__new_Optional(_x_x2101, _ctx); /*? 7*/
  return kk_std_time_time_copy_dc(_x_x2086, _x_x2087, _x_x2100, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the days between two times. Uses the calendar and timezone
// of the first time `t1` to determine the date of `t2`.
// ```
// days-until( time(2000,1,1), time(2000,1,1) ) == 0
// days-until( time(2000,1,1), time(2000,1,2) ) == 1
// days-until( time(2000,1,1), time(2000,1,2,tz=tz-fixed(1)) ) == 0
// days-until( time(2000,1,1), time(2000,3,1) ) == 60
// days-until( time(2000,2,1), time(2000,1,1) ) == -1
// ```

kk_integer_t kk_std_time_time_days_until(kk_std_time_time__time t1, kk_std_time_time__time t2, kk_context_t* _ctx) { /* (t1 : time, t2 : time) -> int */ 
  kk_std_time_time__time time_0_10185;
  bool _match_x708;
  kk_string_t _x_x2103;
  {
    struct kk_std_time_time_Time* _con_x2104 = kk_std_time_time__as_Time(t1, _ctx);
    kk_std_time_date__date _pat_0_1 = _con_x2104->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2104->clock;
    kk_std_time_calendar__calendar _x_1 = _con_x2104->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2104->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2104->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2104->instant;
    struct kk_std_time_date_Clock* _con_x2105 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2106 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2107 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_calendar__calendar_dup(_x_1, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2108 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
      kk_string_t _pat_0_0 = _con_x2108->name;
      kk_string_t _x_0 = _con_x2108->long_name;
      kk_string_t _pat_1_0 = _con_x2108->month_prefix;
      kk_function_t _pat_2_0 = _con_x2108->show_era;
      kk_function_t _pat_3_0 = _con_x2108->instant_to_dc;
      kk_function_t _pat_4_0 = _con_x2108->dc_to_instant;
      kk_function_t _pat_5_0 = _con_x2108->days_to_date;
      kk_function_t _pat_6_0 = _con_x2108->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_function_drop(_pat_6_0, _ctx);
        kk_function_drop(_pat_5_0, _ctx);
        kk_function_drop(_pat_4_0, _ctx);
        kk_function_drop(_pat_3_0, _ctx);
        kk_function_drop(_pat_2_0, _ctx);
        kk_string_drop(_pat_1_0, _ctx);
        kk_string_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_string_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x2103 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x2109;
  {
    struct kk_std_time_time_Time* _con_x2110 = kk_std_time_time__as_Time(t2, _ctx);
    kk_std_time_date__date _pat_0_2 = _con_x2110->date;
    kk_std_time_date__clock _pat_4_2 = _con_x2110->clock;
    kk_std_time_calendar__calendar _x_2 = _con_x2110->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x2110->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x2110->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x2110->instant;
    struct kk_std_time_date_Clock* _con_x2111 = kk_std_time_date__as_Clock(_pat_4_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2112 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2113 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_std_time_calendar__calendar_dup(_x_2, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2114 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
      kk_string_t _pat_0_0_0 = _con_x2114->name;
      kk_string_t _x_0_0 = _con_x2114->long_name;
      kk_string_t _pat_1_0_0 = _con_x2114->month_prefix;
      kk_function_t _pat_2_0_0 = _con_x2114->show_era;
      kk_function_t _pat_3_0_0 = _con_x2114->instant_to_dc;
      kk_function_t _pat_4_0_0 = _con_x2114->dc_to_instant;
      kk_function_t _pat_5_0_0 = _con_x2114->days_to_date;
      kk_function_t _pat_6_0_0 = _con_x2114->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
        kk_function_drop(_pat_6_0_0, _ctx);
        kk_function_drop(_pat_5_0_0, _ctx);
        kk_function_drop(_pat_4_0_0, _ctx);
        kk_function_drop(_pat_3_0_0, _ctx);
        kk_function_drop(_pat_2_0_0, _ctx);
        kk_string_drop(_pat_1_0_0, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(_x_2, _ctx);
      }
      else {
        kk_string_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(_x_2, _ctx);
      }
      _x_x2109 = _x_0_0; /*string*/
    }
  }
  _match_x708 = kk_string_is_eq(_x_x2103,_x_x2109,kk_context()); /*bool*/
  if (_match_x708) {
    bool _match_x709;
    kk_string_t _x_x2115;
    {
      struct kk_std_time_time_Time* _con_x2116 = kk_std_time_time__as_Time(t1, _ctx);
      kk_std_time_date__date _pat_0_4 = _con_x2116->date;
      kk_std_time_date__clock _pat_4_3 = _con_x2116->clock;
      kk_std_time_calendar__calendar _pat_8_2 = _con_x2116->calendar;
      kk_std_time_duration__duration _pat_17_2 = _con_x2116->tzdelta;
      kk_std_time_calendar__timezone _x_4 = _con_x2116->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x2116->instant;
      struct kk_std_time_date_Clock* _con_x2117 = kk_std_time_date__as_Clock(_pat_4_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2118 = kk_std_time_calendar__as_Calendar(_pat_8_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2119 = kk_std_time_calendar__as_Timezone(_x_4, _ctx);
      kk_std_time_calendar__timezone_dup(_x_4, _ctx);
      {
        struct kk_std_time_calendar_Timezone* _con_x2120 = kk_std_time_calendar__as_Timezone(_x_4, _ctx);
        kk_string_t _x_3 = _con_x2120->name;
        kk_function_t _pat_0_3 = _con_x2120->utc_delta;
        kk_function_t _pat_1_3 = _con_x2120->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(_x_4, _ctx)) {
          kk_function_drop(_pat_1_3, _ctx);
          kk_function_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(_x_4, _ctx);
        }
        else {
          kk_string_dup(_x_3, _ctx);
          kk_datatype_ptr_decref(_x_4, _ctx);
        }
        _x_x2115 = _x_3; /*string*/
      }
    }
    kk_string_t _x_x2121;
    {
      struct kk_std_time_time_Time* _con_x2122 = kk_std_time_time__as_Time(t2, _ctx);
      kk_std_time_date__date _pat_0_5 = _con_x2122->date;
      kk_std_time_date__clock _pat_4_4 = _con_x2122->clock;
      kk_std_time_calendar__calendar _pat_8_3 = _con_x2122->calendar;
      kk_std_time_duration__duration _pat_17_3 = _con_x2122->tzdelta;
      kk_std_time_calendar__timezone _x_5 = _con_x2122->timezone;
      kk_std_time_instant__instant _pat_23_3 = _con_x2122->instant;
      struct kk_std_time_date_Clock* _con_x2123 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2124 = kk_std_time_calendar__as_Calendar(_pat_8_3, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2125 = kk_std_time_calendar__as_Timezone(_x_5, _ctx);
      kk_std_time_calendar__timezone_dup(_x_5, _ctx);
      {
        struct kk_std_time_calendar_Timezone* _con_x2126 = kk_std_time_calendar__as_Timezone(_x_5, _ctx);
        kk_string_t _x_0_1 = _con_x2126->name;
        kk_function_t _pat_0_0_1 = _con_x2126->utc_delta;
        kk_function_t _pat_1_0_1 = _con_x2126->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
          kk_function_drop(_pat_1_0_1, _ctx);
          kk_function_drop(_pat_0_0_1, _ctx);
          kk_datatype_ptr_free(_x_5, _ctx);
        }
        else {
          kk_string_dup(_x_0_1, _ctx);
          kk_datatype_ptr_decref(_x_5, _ctx);
        }
        _x_x2121 = _x_0_1; /*string*/
      }
    }
    _match_x709 = kk_string_is_eq(_x_x2115,_x_x2121,kk_context()); /*bool*/
    if (_match_x709) {
      time_0_10185 = t2; /*std/time/time/time*/
    }
    else {
      kk_std_time_instant__instant _x_x2127;
      {
        struct kk_std_time_time_Time* _con_x2128 = kk_std_time_time__as_Time(t2, _ctx);
        kk_std_time_date__date _pat_0_6 = _con_x2128->date;
        kk_std_time_date__clock _pat_4_5 = _con_x2128->clock;
        kk_std_time_calendar__calendar _pat_8_4 = _con_x2128->calendar;
        kk_std_time_duration__duration _pat_17_4 = _con_x2128->tzdelta;
        kk_std_time_calendar__timezone _pat_20_4 = _con_x2128->timezone;
        kk_std_time_instant__instant _x_6 = _con_x2128->instant;
        struct kk_std_time_date_Clock* _con_x2129 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2130 = kk_std_time_calendar__as_Calendar(_pat_8_4, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2131 = kk_std_time_calendar__as_Timezone(_pat_20_4, _ctx);
        kk_string_t _pat_19_4 = _con_x2128->tzabbrv;
        kk_integer_t _pat_5_5 = _con_x2129->hours;
        kk_integer_t _pat_6_5 = _con_x2129->minutes;
        kk_string_t _pat_9_4 = _con_x2130->name;
        kk_string_t _pat_10_4 = _con_x2130->long_name;
        kk_string_t _pat_11_4 = _con_x2130->month_prefix;
        kk_function_t _pat_12_4 = _con_x2130->show_era;
        kk_function_t _pat_13_4 = _con_x2130->instant_to_dc;
        kk_function_t _pat_14_4 = _con_x2130->dc_to_instant;
        kk_function_t _pat_15_4 = _con_x2130->days_to_date;
        kk_function_t _pat_16_4 = _con_x2130->date_to_days;
        kk_string_t _pat_21_4 = _con_x2131->name;
        kk_function_t _pat_22_4 = _con_x2131->utc_delta;
        kk_function_t _pat_23_4 = _con_x2131->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t2, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_8_4, _ctx)) {
            kk_string_drop(_pat_9_4, _ctx);
            kk_function_drop(_pat_16_4, _ctx);
            kk_function_drop(_pat_15_4, _ctx);
            kk_function_drop(_pat_14_4, _ctx);
            kk_function_drop(_pat_13_4, _ctx);
            kk_function_drop(_pat_12_4, _ctx);
            kk_string_drop(_pat_11_4, _ctx);
            kk_string_drop(_pat_10_4, _ctx);
            kk_datatype_ptr_free(_pat_8_4, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_8_4, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_4_5, _ctx)) {
            kk_integer_drop(_pat_6_5, _ctx);
            kk_integer_drop(_pat_5_5, _ctx);
            kk_datatype_ptr_free(_pat_4_5, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_4_5, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_20_4, _ctx)) {
            kk_function_drop(_pat_23_4, _ctx);
            kk_function_drop(_pat_22_4, _ctx);
            kk_string_drop(_pat_21_4, _ctx);
            kk_datatype_ptr_free(_pat_20_4, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_20_4, _ctx);
          }
          kk_string_drop(_pat_19_4, _ctx);
          kk_std_time_date__date_drop(_pat_0_6, _ctx);
          kk_datatype_ptr_free(t2, _ctx);
        }
        else {
          kk_std_time_instant__instant_dup(_x_6, _ctx);
          kk_datatype_ptr_decref(t2, _ctx);
        }
        _x_x2127 = _x_6; /*std/time/instant/instant*/
      }
      kk_std_core_types__optional _x_x2132;
      kk_box_t _x_x2133;
      kk_std_time_calendar__timezone _x_x2134;
      {
        struct kk_std_time_time_Time* _con_x2135 = kk_std_time_time__as_Time(t1, _ctx);
        kk_std_time_date__date _pat_0_7 = _con_x2135->date;
        kk_std_time_date__clock _pat_4_6 = _con_x2135->clock;
        kk_std_time_calendar__calendar _pat_8_5 = _con_x2135->calendar;
        kk_std_time_duration__duration _pat_17_5 = _con_x2135->tzdelta;
        kk_std_time_calendar__timezone _x_7 = _con_x2135->timezone;
        kk_std_time_instant__instant _pat_23_5 = _con_x2135->instant;
        struct kk_std_time_date_Clock* _con_x2136 = kk_std_time_date__as_Clock(_pat_4_6, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2137 = kk_std_time_calendar__as_Calendar(_pat_8_5, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2138 = kk_std_time_calendar__as_Timezone(_x_7, _ctx);
        kk_std_time_calendar__timezone_dup(_x_7, _ctx);
        _x_x2134 = _x_7; /*std/time/calendar/timezone*/
      }
      _x_x2133 = kk_std_time_calendar__timezone_box(_x_x2134, _ctx); /*7*/
      _x_x2132 = kk_std_core_types__new_Optional(_x_x2133, _ctx); /*? 7*/
      kk_std_core_types__optional _x_x2139;
      kk_box_t _x_x2140;
      kk_std_time_calendar__calendar _x_x2141;
      {
        struct kk_std_time_time_Time* _con_x2142 = kk_std_time_time__as_Time(t1, _ctx);
        kk_std_time_date__date _pat_0_8 = _con_x2142->date;
        kk_std_time_date__clock _pat_4_7 = _con_x2142->clock;
        kk_std_time_calendar__calendar _x_8 = _con_x2142->calendar;
        kk_std_time_duration__duration _pat_16_6 = _con_x2142->tzdelta;
        kk_std_time_calendar__timezone _pat_19_6 = _con_x2142->timezone;
        kk_std_time_instant__instant _pat_23_6 = _con_x2142->instant;
        struct kk_std_time_date_Clock* _con_x2143 = kk_std_time_date__as_Clock(_pat_4_7, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2144 = kk_std_time_calendar__as_Calendar(_x_8, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2145 = kk_std_time_calendar__as_Timezone(_pat_19_6, _ctx);
        kk_std_time_calendar__calendar_dup(_x_8, _ctx);
        _x_x2141 = _x_8; /*std/time/calendar/calendar*/
      }
      _x_x2140 = kk_std_time_calendar__calendar_box(_x_x2141, _ctx); /*7*/
      _x_x2139 = kk_std_core_types__new_Optional(_x_x2140, _ctx); /*? 7*/
      time_0_10185 = kk_std_time_time_instant_fs_time(_x_x2127, _x_x2132, _x_x2139, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
    }
  }
  else {
    kk_std_time_instant__instant _x_x2146;
    {
      struct kk_std_time_time_Time* _con_x2147 = kk_std_time_time__as_Time(t2, _ctx);
      kk_std_time_date__date _pat_0_10 = _con_x2147->date;
      kk_std_time_date__clock _pat_4_8 = _con_x2147->clock;
      kk_std_time_calendar__calendar _pat_8_7 = _con_x2147->calendar;
      kk_std_time_duration__duration _pat_17_7 = _con_x2147->tzdelta;
      kk_std_time_calendar__timezone _pat_20_7 = _con_x2147->timezone;
      kk_std_time_instant__instant _x_9 = _con_x2147->instant;
      struct kk_std_time_date_Clock* _con_x2148 = kk_std_time_date__as_Clock(_pat_4_8, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2149 = kk_std_time_calendar__as_Calendar(_pat_8_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2150 = kk_std_time_calendar__as_Timezone(_pat_20_7, _ctx);
      kk_string_t _pat_19_7 = _con_x2147->tzabbrv;
      kk_integer_t _pat_5_8 = _con_x2148->hours;
      kk_integer_t _pat_6_8 = _con_x2148->minutes;
      kk_string_t _pat_9_7 = _con_x2149->name;
      kk_string_t _pat_10_7 = _con_x2149->long_name;
      kk_string_t _pat_11_7 = _con_x2149->month_prefix;
      kk_function_t _pat_12_7 = _con_x2149->show_era;
      kk_function_t _pat_13_7 = _con_x2149->instant_to_dc;
      kk_function_t _pat_14_7 = _con_x2149->dc_to_instant;
      kk_function_t _pat_15_7 = _con_x2149->days_to_date;
      kk_function_t _pat_16_7 = _con_x2149->date_to_days;
      kk_string_t _pat_21_7 = _con_x2150->name;
      kk_function_t _pat_22_7 = _con_x2150->utc_delta;
      kk_function_t _pat_23_7 = _con_x2150->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t2, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_8_7, _ctx)) {
          kk_string_drop(_pat_9_7, _ctx);
          kk_function_drop(_pat_16_7, _ctx);
          kk_function_drop(_pat_15_7, _ctx);
          kk_function_drop(_pat_14_7, _ctx);
          kk_function_drop(_pat_13_7, _ctx);
          kk_function_drop(_pat_12_7, _ctx);
          kk_string_drop(_pat_11_7, _ctx);
          kk_string_drop(_pat_10_7, _ctx);
          kk_datatype_ptr_free(_pat_8_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_8_7, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_8, _ctx)) {
          kk_integer_drop(_pat_6_8, _ctx);
          kk_integer_drop(_pat_5_8, _ctx);
          kk_datatype_ptr_free(_pat_4_8, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_8, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_20_7, _ctx)) {
          kk_function_drop(_pat_23_7, _ctx);
          kk_function_drop(_pat_22_7, _ctx);
          kk_string_drop(_pat_21_7, _ctx);
          kk_datatype_ptr_free(_pat_20_7, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_20_7, _ctx);
        }
        kk_string_drop(_pat_19_7, _ctx);
        kk_std_time_date__date_drop(_pat_0_10, _ctx);
        kk_datatype_ptr_free(t2, _ctx);
      }
      else {
        kk_std_time_instant__instant_dup(_x_9, _ctx);
        kk_datatype_ptr_decref(t2, _ctx);
      }
      _x_x2146 = _x_9; /*std/time/instant/instant*/
    }
    kk_std_core_types__optional _x_x2151;
    kk_box_t _x_x2152;
    kk_std_time_calendar__timezone _x_x2153;
    {
      struct kk_std_time_time_Time* _con_x2154 = kk_std_time_time__as_Time(t1, _ctx);
      kk_std_time_date__date _pat_0_11 = _con_x2154->date;
      kk_std_time_date__clock _pat_4_9 = _con_x2154->clock;
      kk_std_time_calendar__calendar _pat_8_8 = _con_x2154->calendar;
      kk_std_time_duration__duration _pat_17_8 = _con_x2154->tzdelta;
      kk_std_time_calendar__timezone _x_10 = _con_x2154->timezone;
      kk_std_time_instant__instant _pat_23_8 = _con_x2154->instant;
      struct kk_std_time_date_Clock* _con_x2155 = kk_std_time_date__as_Clock(_pat_4_9, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2156 = kk_std_time_calendar__as_Calendar(_pat_8_8, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2157 = kk_std_time_calendar__as_Timezone(_x_10, _ctx);
      kk_std_time_calendar__timezone_dup(_x_10, _ctx);
      _x_x2153 = _x_10; /*std/time/calendar/timezone*/
    }
    _x_x2152 = kk_std_time_calendar__timezone_box(_x_x2153, _ctx); /*7*/
    _x_x2151 = kk_std_core_types__new_Optional(_x_x2152, _ctx); /*? 7*/
    kk_std_core_types__optional _x_x2158;
    kk_box_t _x_x2159;
    kk_std_time_calendar__calendar _x_x2160;
    {
      struct kk_std_time_time_Time* _con_x2161 = kk_std_time_time__as_Time(t1, _ctx);
      kk_std_time_date__date _pat_0_12 = _con_x2161->date;
      kk_std_time_date__clock _pat_4_10 = _con_x2161->clock;
      kk_std_time_calendar__calendar _x_11 = _con_x2161->calendar;
      kk_std_time_duration__duration _pat_16_9 = _con_x2161->tzdelta;
      kk_std_time_calendar__timezone _pat_19_9 = _con_x2161->timezone;
      kk_std_time_instant__instant _pat_23_9 = _con_x2161->instant;
      struct kk_std_time_date_Clock* _con_x2162 = kk_std_time_date__as_Clock(_pat_4_10, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2163 = kk_std_time_calendar__as_Calendar(_x_11, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2164 = kk_std_time_calendar__as_Timezone(_pat_19_9, _ctx);
      kk_std_time_calendar__calendar_dup(_x_11, _ctx);
      _x_x2160 = _x_11; /*std/time/calendar/calendar*/
    }
    _x_x2159 = kk_std_time_calendar__calendar_box(_x_x2160, _ctx); /*7*/
    _x_x2158 = kk_std_core_types__new_Optional(_x_x2159, _ctx); /*? 7*/
    time_0_10185 = kk_std_time_time_instant_fs_time(_x_x2146, _x_x2151, _x_x2158, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  }
  kk_integer_t x;
  {
    struct kk_std_time_time_Time* _con_x2165 = kk_std_time_time__as_Time(t1, _ctx);
    kk_std_time_date__date _pat_0_14 = _con_x2165->date;
    kk_std_time_date__clock _pat_4_12 = _con_x2165->clock;
    kk_std_time_calendar__calendar _x_13 = _con_x2165->calendar;
    kk_std_time_duration__duration _pat_16_10 = _con_x2165->tzdelta;
    kk_std_time_calendar__timezone _pat_19_10 = _con_x2165->timezone;
    kk_std_time_instant__instant _pat_23_10 = _con_x2165->instant;
    struct kk_std_time_date_Clock* _con_x2166 = kk_std_time_date__as_Clock(_pat_4_12, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2167 = kk_std_time_calendar__as_Calendar(_x_13, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2168 = kk_std_time_calendar__as_Timezone(_pat_19_10, _ctx);
    kk_std_time_calendar__calendar_dup(_x_13, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2169 = kk_std_time_calendar__as_Calendar(_x_13, _ctx);
      kk_string_t _pat_0_0_2 = _con_x2169->name;
      kk_string_t _pat_1_0_2 = _con_x2169->long_name;
      kk_string_t _pat_2_0_1 = _con_x2169->month_prefix;
      kk_function_t _pat_3_0_1 = _con_x2169->show_era;
      kk_function_t _pat_4_0_1 = _con_x2169->instant_to_dc;
      kk_function_t _pat_5_0_1 = _con_x2169->dc_to_instant;
      kk_function_t _pat_6_0_1 = _con_x2169->days_to_date;
      kk_function_t _x_0_2 = _con_x2169->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_13, _ctx)) {
        kk_function_drop(_pat_6_0_1, _ctx);
        kk_function_drop(_pat_5_0_1, _ctx);
        kk_function_drop(_pat_4_0_1, _ctx);
        kk_function_drop(_pat_3_0_1, _ctx);
        kk_string_drop(_pat_2_0_1, _ctx);
        kk_string_drop(_pat_1_0_2, _ctx);
        kk_string_drop(_pat_0_0_2, _ctx);
        kk_datatype_ptr_free(_x_13, _ctx);
      }
      else {
        kk_function_dup(_x_0_2, _ctx);
        kk_datatype_ptr_decref(_x_13, _ctx);
      }
      kk_std_time_date__date _x_x2170;
      {
        struct kk_std_time_time_Time* _con_x2171 = kk_std_time_time__as_Time(time_0_10185, _ctx);
        kk_std_time_date__date _x = _con_x2171->date;
        kk_std_time_date__clock _pat_3 = _con_x2171->clock;
        kk_std_time_calendar__calendar _pat_7 = _con_x2171->calendar;
        kk_std_time_duration__duration _pat_16 = _con_x2171->tzdelta;
        kk_std_time_calendar__timezone _pat_19 = _con_x2171->timezone;
        kk_std_time_instant__instant _pat_23 = _con_x2171->instant;
        struct kk_std_time_date_Clock* _con_x2172 = kk_std_time_date__as_Clock(_pat_3, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2173 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2174 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
        kk_string_t _pat_18 = _con_x2171->tzabbrv;
        kk_integer_t _pat_4 = _con_x2172->hours;
        kk_integer_t _pat_5 = _con_x2172->minutes;
        kk_string_t _pat_8 = _con_x2173->name;
        kk_string_t _pat_9 = _con_x2173->long_name;
        kk_string_t _pat_10 = _con_x2173->month_prefix;
        kk_function_t _pat_11 = _con_x2173->show_era;
        kk_function_t _pat_12 = _con_x2173->instant_to_dc;
        kk_function_t _pat_13 = _con_x2173->dc_to_instant;
        kk_function_t _pat_14 = _con_x2173->days_to_date;
        kk_function_t _pat_15 = _con_x2173->date_to_days;
        kk_string_t _pat_20 = _con_x2174->name;
        kk_function_t _pat_21 = _con_x2174->utc_delta;
        kk_function_t _pat_22 = _con_x2174->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(time_0_10185, _ctx)) {
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
          kk_datatype_ptr_free(time_0_10185, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x, _ctx);
          kk_datatype_ptr_decref(time_0_10185, _ctx);
        }
        _x_x2170 = _x; /*std/time/date/date*/
      }
      x = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_0_2, (_x_0_2, _x_x2170, _ctx), _ctx); /*int*/
    }
  }
  kk_integer_t y;
  {
    struct kk_std_time_time_Time* _con_x2175 = kk_std_time_time__as_Time(t1, _ctx);
    kk_std_time_date__date _pat_0_14_0 = _con_x2175->date;
    kk_std_time_date__clock _pat_4_12_0 = _con_x2175->clock;
    kk_std_time_calendar__calendar _x_13_0 = _con_x2175->calendar;
    kk_std_time_duration__duration _pat_16_10_0 = _con_x2175->tzdelta;
    kk_std_time_calendar__timezone _pat_19_10_0 = _con_x2175->timezone;
    kk_std_time_instant__instant _pat_23_10_0 = _con_x2175->instant;
    struct kk_std_time_date_Clock* _con_x2176 = kk_std_time_date__as_Clock(_pat_4_12_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2177 = kk_std_time_calendar__as_Calendar(_x_13_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2178 = kk_std_time_calendar__as_Timezone(_pat_19_10_0, _ctx);
    kk_std_time_calendar__calendar_dup(_x_13_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2179 = kk_std_time_calendar__as_Calendar(_x_13_0, _ctx);
      kk_string_t _pat_0_13 = _con_x2179->name;
      kk_string_t _pat_1_13 = _con_x2179->long_name;
      kk_string_t _pat_2_13 = _con_x2179->month_prefix;
      kk_function_t _pat_3_11 = _con_x2179->show_era;
      kk_function_t _pat_4_11 = _con_x2179->instant_to_dc;
      kk_function_t _pat_5_11 = _con_x2179->dc_to_instant;
      kk_function_t _pat_6_11 = _con_x2179->days_to_date;
      kk_function_t _x_12 = _con_x2179->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_13_0, _ctx)) {
        kk_function_drop(_pat_6_11, _ctx);
        kk_function_drop(_pat_5_11, _ctx);
        kk_function_drop(_pat_4_11, _ctx);
        kk_function_drop(_pat_3_11, _ctx);
        kk_string_drop(_pat_2_13, _ctx);
        kk_string_drop(_pat_1_13, _ctx);
        kk_string_drop(_pat_0_13, _ctx);
        kk_datatype_ptr_free(_x_13_0, _ctx);
      }
      else {
        kk_function_dup(_x_12, _ctx);
        kk_datatype_ptr_decref(_x_13_0, _ctx);
      }
      kk_std_time_date__date _x_x2180;
      {
        struct kk_std_time_time_Time* _con_x2181 = kk_std_time_time__as_Time(t1, _ctx);
        kk_std_time_date__date _x_14 = _con_x2181->date;
        kk_std_time_date__clock _pat_3_13 = _con_x2181->clock;
        kk_std_time_calendar__calendar _pat_7_13 = _con_x2181->calendar;
        kk_std_time_duration__duration _pat_16_11 = _con_x2181->tzdelta;
        kk_std_time_calendar__timezone _pat_19_11 = _con_x2181->timezone;
        kk_std_time_instant__instant _pat_23_11 = _con_x2181->instant;
        struct kk_std_time_date_Clock* _con_x2182 = kk_std_time_date__as_Clock(_pat_3_13, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2183 = kk_std_time_calendar__as_Calendar(_pat_7_13, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2184 = kk_std_time_calendar__as_Timezone(_pat_19_11, _ctx);
        kk_string_t _pat_18_11 = _con_x2181->tzabbrv;
        kk_integer_t _pat_4_13 = _con_x2182->hours;
        kk_integer_t _pat_5_13 = _con_x2182->minutes;
        kk_string_t _pat_8_11 = _con_x2183->name;
        kk_string_t _pat_9_11 = _con_x2183->long_name;
        kk_string_t _pat_10_11 = _con_x2183->month_prefix;
        kk_function_t _pat_11_11 = _con_x2183->show_era;
        kk_function_t _pat_12_11 = _con_x2183->instant_to_dc;
        kk_function_t _pat_13_11 = _con_x2183->dc_to_instant;
        kk_function_t _pat_14_11 = _con_x2183->days_to_date;
        kk_function_t _pat_15_11 = _con_x2183->date_to_days;
        kk_string_t _pat_20_11 = _con_x2184->name;
        kk_function_t _pat_21_11 = _con_x2184->utc_delta;
        kk_function_t _pat_22_11 = _con_x2184->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t1, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_13, _ctx)) {
            kk_string_drop(_pat_9_11, _ctx);
            kk_string_drop(_pat_8_11, _ctx);
            kk_function_drop(_pat_15_11, _ctx);
            kk_function_drop(_pat_14_11, _ctx);
            kk_function_drop(_pat_13_11, _ctx);
            kk_function_drop(_pat_12_11, _ctx);
            kk_function_drop(_pat_11_11, _ctx);
            kk_string_drop(_pat_10_11, _ctx);
            kk_datatype_ptr_free(_pat_7_13, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_13, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_13, _ctx)) {
            kk_integer_drop(_pat_5_13, _ctx);
            kk_integer_drop(_pat_4_13, _ctx);
            kk_datatype_ptr_free(_pat_3_13, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_13, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_11, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_11, _ctx)) {
            kk_function_drop(_pat_22_11, _ctx);
            kk_function_drop(_pat_21_11, _ctx);
            kk_string_drop(_pat_20_11, _ctx);
            kk_datatype_ptr_free(_pat_19_11, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_11, _ctx);
          }
          kk_string_drop(_pat_18_11, _ctx);
          kk_datatype_ptr_free(t1, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_14, _ctx);
          kk_datatype_ptr_decref(t1, _ctx);
        }
        _x_x2180 = _x_14; /*std/time/date/date*/
      }
      y = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_12, (_x_12, _x_x2180, _ctx), _ctx); /*int*/
    }
  }
  return kk_integer_sub(x,y,kk_context());
}
 
// Return the day of the year of time `t` (starting at 1).

kk_integer_t kk_std_time_time_day_of_year(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  kk_integer_t x_0;
  {
    struct kk_std_time_time_Time* _con_x2185 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_1 = _con_x2185->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2185->clock;
    kk_std_time_calendar__calendar _x_1 = _con_x2185->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2185->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2185->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2185->instant;
    struct kk_std_time_date_Clock* _con_x2186 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2187 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2188 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_calendar__calendar_dup(_x_1, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2189 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
      kk_string_t _pat_0_0 = _con_x2189->name;
      kk_string_t _pat_1_0 = _con_x2189->long_name;
      kk_string_t _pat_2_0 = _con_x2189->month_prefix;
      kk_function_t _pat_3_0 = _con_x2189->show_era;
      kk_function_t _pat_4_0 = _con_x2189->instant_to_dc;
      kk_function_t _pat_5_0 = _con_x2189->dc_to_instant;
      kk_function_t _pat_6_0 = _con_x2189->days_to_date;
      kk_function_t _x_0 = _con_x2189->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_function_drop(_pat_6_0, _ctx);
        kk_function_drop(_pat_5_0, _ctx);
        kk_function_drop(_pat_4_0, _ctx);
        kk_function_drop(_pat_3_0, _ctx);
        kk_string_drop(_pat_2_0, _ctx);
        kk_string_drop(_pat_1_0, _ctx);
        kk_string_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_function_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      kk_std_time_date__date _x_x2190;
      {
        struct kk_std_time_time_Time* _con_x2191 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_4 = _con_x2191->date;
        kk_std_time_date__clock _pat_3_3 = _con_x2191->clock;
        kk_std_time_calendar__calendar _pat_7_2 = _con_x2191->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x2191->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x2191->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x2191->instant;
        struct kk_std_time_date_Clock* _con_x2192 = kk_std_time_date__as_Clock(_pat_3_3, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2193 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2194 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__date_dup(_x_4, _ctx);
        _x_x2190 = _x_4; /*std/time/date/date*/
      }
      x_0 = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_0, (_x_0, _x_x2190, _ctx), _ctx); /*int*/
    }
  }
  kk_integer_t y_0;
  {
    struct kk_std_time_time_Time* _con_x2195 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_1_0 = _con_x2195->date;
    kk_std_time_date__clock _pat_4_1_0 = _con_x2195->clock;
    kk_std_time_calendar__calendar _x_1_0 = _con_x2195->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2195->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2195->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2195->instant;
    struct kk_std_time_date_Clock* _con_x2196 = kk_std_time_date__as_Clock(_pat_4_1_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2197 = kk_std_time_calendar__as_Calendar(_x_1_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2198 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_calendar__calendar_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2199 = kk_std_time_calendar__as_Calendar(_x_1_0, _ctx);
      kk_string_t _pat_0 = _con_x2199->name;
      kk_string_t _pat_1 = _con_x2199->long_name;
      kk_string_t _pat_2 = _con_x2199->month_prefix;
      kk_function_t _pat_3 = _con_x2199->show_era;
      kk_function_t _pat_4 = _con_x2199->instant_to_dc;
      kk_function_t _pat_5 = _con_x2199->dc_to_instant;
      kk_function_t _pat_6 = _con_x2199->days_to_date;
      kk_function_t _x = _con_x2199->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_function_drop(_pat_6, _ctx);
        kk_function_drop(_pat_5, _ctx);
        kk_function_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_string_drop(_pat_2, _ctx);
        kk_string_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_function_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      kk_std_time_date__date _x_x2200;
      kk_integer_t _x_x2201;
      {
        struct kk_std_time_time_Time* _con_x2202 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_3 = _con_x2202->date;
        kk_std_time_date__clock _pat_3_2 = _con_x2202->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2202->calendar;
        kk_std_time_duration__duration _pat_16_0_0 = _con_x2202->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2202->timezone;
        kk_std_time_instant__instant _pat_23_0_0 = _con_x2202->instant;
        struct kk_std_time_date_Clock* _con_x2203 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2204 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2205 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
        kk_string_t _pat_18_0_0 = _con_x2202->tzabbrv;
        kk_integer_t _pat_4_2 = _con_x2203->hours;
        kk_integer_t _pat_5_2 = _con_x2203->minutes;
        kk_string_t _pat_8_1_0 = _con_x2204->name;
        kk_string_t _pat_9_0_0 = _con_x2204->long_name;
        kk_string_t _pat_10_0_0 = _con_x2204->month_prefix;
        kk_function_t _pat_11_0_0 = _con_x2204->show_era;
        kk_function_t _pat_12_0_0 = _con_x2204->instant_to_dc;
        kk_function_t _pat_13_0_0 = _con_x2204->dc_to_instant;
        kk_function_t _pat_14_0_0 = _con_x2204->days_to_date;
        kk_function_t _pat_15_0_0 = _con_x2204->date_to_days;
        kk_string_t _pat_20_0_0 = _con_x2205->name;
        kk_function_t _pat_21_0_0 = _con_x2205->utc_delta;
        kk_function_t _pat_22_0_0 = _con_x2205->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1, _ctx)) {
            kk_string_drop(_pat_9_0_0, _ctx);
            kk_string_drop(_pat_8_1_0, _ctx);
            kk_function_drop(_pat_15_0_0, _ctx);
            kk_function_drop(_pat_14_0_0, _ctx);
            kk_function_drop(_pat_13_0_0, _ctx);
            kk_function_drop(_pat_12_0_0, _ctx);
            kk_function_drop(_pat_11_0_0, _ctx);
            kk_string_drop(_pat_10_0_0, _ctx);
            kk_datatype_ptr_free(_pat_7_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_2, _ctx)) {
            kk_integer_drop(_pat_5_2, _ctx);
            kk_integer_drop(_pat_4_2, _ctx);
            kk_datatype_ptr_free(_pat_3_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_2, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_0_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0_0, _ctx)) {
            kk_function_drop(_pat_22_0_0, _ctx);
            kk_function_drop(_pat_21_0_0, _ctx);
            kk_string_drop(_pat_20_0_0, _ctx);
            kk_datatype_ptr_free(_pat_19_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_0_0, _ctx);
          }
          kk_string_drop(_pat_18_0_0, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_3, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_2 = _x_3.year;
          kk_integer_dup(_x_2, _ctx);
          kk_std_time_date__date_drop(_x_3, _ctx);
          _x_x2201 = _x_2; /*int*/
        }
      }
      _x_x2200 = kk_std_time_date__new_Date(_x_x2201, kk_integer_from_small(1), kk_integer_from_small(1), _ctx); /*std/time/date/date*/
      y_0 = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, _x_x2200, _ctx), _ctx); /*int*/
    }
  }
  kk_integer_t x_10205 = kk_integer_sub(x_0,y_0,kk_context()); /*int*/;
  return kk_integer_add_small_const(x_10205, 1, _ctx);
}
 
// Return the total days in the month of time `t`.

kk_integer_t kk_std_time_time_days_in_month(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  kk_std_time_date__date d2_10218;
  kk_integer_t _x_x2206;
  {
    struct kk_std_time_time_Time* _con_x2207 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x = _con_x2207->date;
    kk_std_time_date__clock _pat_3 = _con_x2207->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2207->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2207->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2207->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2207->instant;
    struct kk_std_time_date_Clock* _con_x2208 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2209 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2210 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__date_dup(_x, _ctx);
    {
      kk_integer_t _x_5 = _x.year;
      kk_integer_dup(_x_5, _ctx);
      kk_std_time_date__date_drop(_x, _ctx);
      _x_x2206 = _x_5; /*int*/
    }
  }
  kk_integer_t _x_x2211;
  kk_integer_t _x_x2212;
  {
    struct kk_std_time_time_Time* _con_x2213 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x2213->date;
    kk_std_time_date__clock _pat_3_0 = _con_x2213->clock;
    kk_std_time_calendar__calendar _pat_7_0 = _con_x2213->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2213->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2213->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2213->instant;
    struct kk_std_time_date_Clock* _con_x2214 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2215 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2216 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_0, _ctx);
    {
      kk_integer_t _x_6 = _x_0.month;
      kk_integer_dup(_x_6, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      _x_x2212 = _x_6; /*int*/
    }
  }
  _x_x2211 = kk_integer_add_small_const(_x_x2212, 1, _ctx); /*int*/
  d2_10218 = kk_std_time_date__new_Date(_x_x2206, _x_x2211, kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  kk_integer_t x;
  {
    struct kk_std_time_time_Time* _con_x2217 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_2 = _con_x2217->date;
    kk_std_time_date__clock _pat_4_2 = _con_x2217->clock;
    kk_std_time_calendar__calendar _x_2 = _con_x2217->calendar;
    kk_std_time_duration__duration _pat_16_0_0 = _con_x2217->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2217->timezone;
    kk_std_time_instant__instant _pat_23_0_0 = _con_x2217->instant;
    struct kk_std_time_date_Clock* _con_x2218 = kk_std_time_date__as_Clock(_pat_4_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2219 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2220 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
    kk_std_time_calendar__calendar_dup(_x_2, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2221 = kk_std_time_calendar__as_Calendar(_x_2, _ctx);
      kk_string_t _pat_0_0_0 = _con_x2221->name;
      kk_string_t _pat_1_0_0 = _con_x2221->long_name;
      kk_string_t _pat_2_0_0 = _con_x2221->month_prefix;
      kk_function_t _pat_3_0_0 = _con_x2221->show_era;
      kk_function_t _pat_4_0_0 = _con_x2221->instant_to_dc;
      kk_function_t _pat_5_0_0 = _con_x2221->dc_to_instant;
      kk_function_t _pat_6_0_0 = _con_x2221->days_to_date;
      kk_function_t _x_0_0 = _con_x2221->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
        kk_function_drop(_pat_6_0_0, _ctx);
        kk_function_drop(_pat_5_0_0, _ctx);
        kk_function_drop(_pat_4_0_0, _ctx);
        kk_function_drop(_pat_3_0_0, _ctx);
        kk_string_drop(_pat_2_0_0, _ctx);
        kk_string_drop(_pat_1_0_0, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(_x_2, _ctx);
      }
      else {
        kk_function_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(_x_2, _ctx);
      }
      x = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_0_0, (_x_0_0, d2_10218, _ctx), _ctx); /*int*/
    }
  }
  kk_integer_t y;
  {
    struct kk_std_time_time_Time* _con_x2222 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_2_0 = _con_x2222->date;
    kk_std_time_date__clock _pat_4_2_0 = _con_x2222->clock;
    kk_std_time_calendar__calendar _x_2_0 = _con_x2222->calendar;
    kk_std_time_duration__duration _pat_16_0_1 = _con_x2222->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_1 = _con_x2222->timezone;
    kk_std_time_instant__instant _pat_23_0_1 = _con_x2222->instant;
    struct kk_std_time_date_Clock* _con_x2223 = kk_std_time_date__as_Clock(_pat_4_2_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2224 = kk_std_time_calendar__as_Calendar(_x_2_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2225 = kk_std_time_calendar__as_Timezone(_pat_19_0_1, _ctx);
    kk_std_time_calendar__calendar_dup(_x_2_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2226 = kk_std_time_calendar__as_Calendar(_x_2_0, _ctx);
      kk_string_t _pat_0_1 = _con_x2226->name;
      kk_string_t _pat_1_1 = _con_x2226->long_name;
      kk_string_t _pat_2_1 = _con_x2226->month_prefix;
      kk_function_t _pat_3_1 = _con_x2226->show_era;
      kk_function_t _pat_4_1 = _con_x2226->instant_to_dc;
      kk_function_t _pat_5_1 = _con_x2226->dc_to_instant;
      kk_function_t _pat_6_1 = _con_x2226->days_to_date;
      kk_function_t _x_1 = _con_x2226->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_2_0, _ctx)) {
        kk_function_drop(_pat_6_1, _ctx);
        kk_function_drop(_pat_5_1, _ctx);
        kk_function_drop(_pat_4_1, _ctx);
        kk_function_drop(_pat_3_1, _ctx);
        kk_string_drop(_pat_2_1, _ctx);
        kk_string_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_2_0, _ctx);
      }
      else {
        kk_function_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_x_2_0, _ctx);
      }
      kk_std_time_date__date _x_x2227;
      kk_integer_t _x_x2228;
      {
        struct kk_std_time_time_Time* _con_x2229 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_3 = _con_x2229->date;
        kk_std_time_date__clock _pat_3_3 = _con_x2229->clock;
        kk_std_time_calendar__calendar _pat_7_2 = _con_x2229->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x2229->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x2229->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x2229->instant;
        struct kk_std_time_date_Clock* _con_x2230 = kk_std_time_date__as_Clock(_pat_3_3, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2231 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2232 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__date_dup(_x_3, _ctx);
        {
          kk_integer_t _x_3_0 = _x_3.year;
          kk_integer_dup(_x_3_0, _ctx);
          kk_std_time_date__date_drop(_x_3, _ctx);
          _x_x2228 = _x_3_0; /*int*/
        }
      }
      kk_integer_t _x_x2233;
      {
        struct kk_std_time_time_Time* _con_x2234 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_4 = _con_x2234->date;
        kk_std_time_date__clock _pat_3_4 = _con_x2234->clock;
        kk_std_time_calendar__calendar _pat_7_3 = _con_x2234->calendar;
        kk_std_time_duration__duration _pat_16_2 = _con_x2234->tzdelta;
        kk_std_time_calendar__timezone _pat_19_2 = _con_x2234->timezone;
        kk_std_time_instant__instant _pat_23_2 = _con_x2234->instant;
        struct kk_std_time_date_Clock* _con_x2235 = kk_std_time_date__as_Clock(_pat_3_4, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2236 = kk_std_time_calendar__as_Calendar(_pat_7_3, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2237 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
        kk_string_t _pat_18_2 = _con_x2234->tzabbrv;
        kk_integer_t _pat_4_4 = _con_x2235->hours;
        kk_integer_t _pat_5_4 = _con_x2235->minutes;
        kk_string_t _pat_8_2 = _con_x2236->name;
        kk_string_t _pat_9_2 = _con_x2236->long_name;
        kk_string_t _pat_10_2 = _con_x2236->month_prefix;
        kk_function_t _pat_11_2 = _con_x2236->show_era;
        kk_function_t _pat_12_2 = _con_x2236->instant_to_dc;
        kk_function_t _pat_13_2 = _con_x2236->dc_to_instant;
        kk_function_t _pat_14_2 = _con_x2236->days_to_date;
        kk_function_t _pat_15_2 = _con_x2236->date_to_days;
        kk_string_t _pat_20_2 = _con_x2237->name;
        kk_function_t _pat_21_2 = _con_x2237->utc_delta;
        kk_function_t _pat_22_2 = _con_x2237->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_3, _ctx)) {
            kk_string_drop(_pat_9_2, _ctx);
            kk_string_drop(_pat_8_2, _ctx);
            kk_function_drop(_pat_15_2, _ctx);
            kk_function_drop(_pat_14_2, _ctx);
            kk_function_drop(_pat_13_2, _ctx);
            kk_function_drop(_pat_12_2, _ctx);
            kk_function_drop(_pat_11_2, _ctx);
            kk_string_drop(_pat_10_2, _ctx);
            kk_datatype_ptr_free(_pat_7_3, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_3, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_4, _ctx)) {
            kk_integer_drop(_pat_5_4, _ctx);
            kk_integer_drop(_pat_4_4, _ctx);
            kk_datatype_ptr_free(_pat_3_4, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_4, _ctx);
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
          kk_std_time_date__date_dup(_x_4, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_4_0 = _x_4.month;
          kk_integer_dup(_x_4_0, _ctx);
          kk_std_time_date__date_drop(_x_4, _ctx);
          _x_x2233 = _x_4_0; /*int*/
        }
      }
      _x_x2227 = kk_std_time_date__new_Date(_x_x2228, _x_x2233, kk_integer_from_small(1), _ctx); /*std/time/date/date*/
      y = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_1, (_x_1, _x_x2227, _ctx), _ctx); /*int*/
    }
  }
  return kk_integer_sub(x,y,kk_context());
}
 
// Return the total days in the year of time `t`.

kk_integer_t kk_std_time_time_days_in_year(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  kk_std_time_date__date d2_10228;
  kk_integer_t _x_x2238;
  kk_integer_t _x_x2239;
  {
    struct kk_std_time_time_Time* _con_x2240 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_5 = _con_x2240->date;
    kk_std_time_date__clock _pat_3_3 = _con_x2240->clock;
    kk_std_time_calendar__calendar _pat_7_2 = _con_x2240->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x2240->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x2240->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x2240->instant;
    struct kk_std_time_date_Clock* _con_x2241 = kk_std_time_date__as_Clock(_pat_3_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2242 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2243 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_std_time_date__date_dup(_x_5, _ctx);
    {
      kk_integer_t _x_4 = _x_5.year;
      kk_integer_dup(_x_4, _ctx);
      kk_std_time_date__date_drop(_x_5, _ctx);
      _x_x2239 = _x_4; /*int*/
    }
  }
  _x_x2238 = kk_integer_add_small_const(_x_x2239, 1, _ctx); /*int*/
  d2_10228 = kk_std_time_date__new_Date(_x_x2238, kk_integer_from_small(1), kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  kk_integer_t x;
  {
    struct kk_std_time_time_Time* _con_x2244 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_1 = _con_x2244->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2244->clock;
    kk_std_time_calendar__calendar _x_1 = _con_x2244->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2244->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2244->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2244->instant;
    struct kk_std_time_date_Clock* _con_x2245 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2246 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2247 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_calendar__calendar_dup(_x_1, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2248 = kk_std_time_calendar__as_Calendar(_x_1, _ctx);
      kk_string_t _pat_0_0 = _con_x2248->name;
      kk_string_t _pat_1_0 = _con_x2248->long_name;
      kk_string_t _pat_2_0 = _con_x2248->month_prefix;
      kk_function_t _pat_3_0 = _con_x2248->show_era;
      kk_function_t _pat_4_0 = _con_x2248->instant_to_dc;
      kk_function_t _pat_5_0 = _con_x2248->dc_to_instant;
      kk_function_t _pat_6_0 = _con_x2248->days_to_date;
      kk_function_t _x_0 = _con_x2248->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_function_drop(_pat_6_0, _ctx);
        kk_function_drop(_pat_5_0, _ctx);
        kk_function_drop(_pat_4_0, _ctx);
        kk_function_drop(_pat_3_0, _ctx);
        kk_string_drop(_pat_2_0, _ctx);
        kk_string_drop(_pat_1_0, _ctx);
        kk_string_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_function_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      x = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x_0, (_x_0, d2_10228, _ctx), _ctx); /*int*/
    }
  }
  kk_integer_t y;
  {
    struct kk_std_time_time_Time* _con_x2249 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_1_0 = _con_x2249->date;
    kk_std_time_date__clock _pat_4_1_0 = _con_x2249->clock;
    kk_std_time_calendar__calendar _x_1_0 = _con_x2249->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2249->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2249->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2249->instant;
    struct kk_std_time_date_Clock* _con_x2250 = kk_std_time_date__as_Clock(_pat_4_1_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2251 = kk_std_time_calendar__as_Calendar(_x_1_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2252 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_calendar__calendar_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_calendar_Calendar* _con_x2253 = kk_std_time_calendar__as_Calendar(_x_1_0, _ctx);
      kk_string_t _pat_0 = _con_x2253->name;
      kk_string_t _pat_1 = _con_x2253->long_name;
      kk_string_t _pat_2 = _con_x2253->month_prefix;
      kk_function_t _pat_3 = _con_x2253->show_era;
      kk_function_t _pat_4 = _con_x2253->instant_to_dc;
      kk_function_t _pat_5 = _con_x2253->dc_to_instant;
      kk_function_t _pat_6 = _con_x2253->days_to_date;
      kk_function_t _x = _con_x2253->date_to_days;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_function_drop(_pat_6, _ctx);
        kk_function_drop(_pat_5, _ctx);
        kk_function_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_string_drop(_pat_2, _ctx);
        kk_string_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_function_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      kk_std_time_date__date _x_x2254;
      kk_integer_t _x_x2255;
      {
        struct kk_std_time_time_Time* _con_x2256 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_3 = _con_x2256->date;
        kk_std_time_date__clock _pat_3_2 = _con_x2256->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2256->calendar;
        kk_std_time_duration__duration _pat_16_0_0 = _con_x2256->tzdelta;
        kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2256->timezone;
        kk_std_time_instant__instant _pat_23_0_0 = _con_x2256->instant;
        struct kk_std_time_date_Clock* _con_x2257 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2258 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2259 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
        kk_string_t _pat_18_0_0 = _con_x2256->tzabbrv;
        kk_integer_t _pat_4_2 = _con_x2257->hours;
        kk_integer_t _pat_5_2 = _con_x2257->minutes;
        kk_string_t _pat_8_1_0 = _con_x2258->name;
        kk_string_t _pat_9_0_0 = _con_x2258->long_name;
        kk_string_t _pat_10_0_0 = _con_x2258->month_prefix;
        kk_function_t _pat_11_0_0 = _con_x2258->show_era;
        kk_function_t _pat_12_0_0 = _con_x2258->instant_to_dc;
        kk_function_t _pat_13_0_0 = _con_x2258->dc_to_instant;
        kk_function_t _pat_14_0_0 = _con_x2258->days_to_date;
        kk_function_t _pat_15_0_0 = _con_x2258->date_to_days;
        kk_string_t _pat_20_0_0 = _con_x2259->name;
        kk_function_t _pat_21_0_0 = _con_x2259->utc_delta;
        kk_function_t _pat_22_0_0 = _con_x2259->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1, _ctx)) {
            kk_string_drop(_pat_9_0_0, _ctx);
            kk_string_drop(_pat_8_1_0, _ctx);
            kk_function_drop(_pat_15_0_0, _ctx);
            kk_function_drop(_pat_14_0_0, _ctx);
            kk_function_drop(_pat_13_0_0, _ctx);
            kk_function_drop(_pat_12_0_0, _ctx);
            kk_function_drop(_pat_11_0_0, _ctx);
            kk_string_drop(_pat_10_0_0, _ctx);
            kk_datatype_ptr_free(_pat_7_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_2, _ctx)) {
            kk_integer_drop(_pat_5_2, _ctx);
            kk_integer_drop(_pat_4_2, _ctx);
            kk_datatype_ptr_free(_pat_3_2, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_2, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_0_0, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0_0, _ctx)) {
            kk_function_drop(_pat_22_0_0, _ctx);
            kk_function_drop(_pat_21_0_0, _ctx);
            kk_string_drop(_pat_20_0_0, _ctx);
            kk_datatype_ptr_free(_pat_19_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_0_0, _ctx);
          }
          kk_string_drop(_pat_18_0_0, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_3, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_2 = _x_3.year;
          kk_integer_dup(_x_2, _ctx);
          kk_std_time_date__date_drop(_x_3, _ctx);
          _x_x2255 = _x_2; /*int*/
        }
      }
      _x_x2254 = kk_std_time_date__new_Date(_x_x2255, kk_integer_from_small(1), kk_integer_from_small(1), _ctx); /*std/time/date/date*/
      y = kk_function_call(kk_integer_t, (kk_function_t, kk_std_time_date__date, kk_context_t*), _x, (_x, _x_x2254, _ctx), _ctx); /*int*/
    }
  }
  return kk_integer_sub(x,y,kk_context());
}
 
// Return the modified Julian date ([MJD](https://en.wikipedia.org/wiki/Julian_day#Variants))
// number for a given `:time`. This interprets the Modified Julian Date in the calendar
// system of `t` with the timezone applied.
// `time(1972,1,2,tz=tz-fixed(1)).mjd == "41318"`
// `time(1972,1,2,tz=tz-fixed(1)).instant.mjd(ts-utc).show == "41317.958333335"` &quad; (one hour earlier)
//
// Also takes leap seconds into account:
// `time(2015,12,31,12,0,0).mjd.show == "57387.5"` &quad; (exactly mid-day)
// `time(2016,12,31,12,0,0).mjd.show(9) == "57753.499994213"` &quad; (this day has a leap second, so it is just before the real middle of the day)
// `time(2016,12,31,12,0,0,0.5).mjd.show == "57753.5"` &quad; (real middle of the day)

kk_std_num_ddouble__ddouble kk_std_time_time_mjd(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> std/num/ddouble/ddouble */ 
  kk_std_time_instant__instant _x_x2260;
  {
    struct kk_std_time_time_Time* _con_x2261 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2261->date;
    kk_std_time_date__clock _pat_4 = _con_x2261->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2261->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2261->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x2261->timezone;
    kk_std_time_instant__instant _x = _con_x2261->instant;
    struct kk_std_time_date_Clock* _con_x2262 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2263 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2264 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x2260 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__timescale _x_x2265;
  {
    struct kk_std_time_time_Time* _con_x2266 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x2266->date;
    kk_std_time_date__clock _pat_4_0 = _con_x2266->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x2266->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x2266->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x2266->timezone;
    kk_std_time_instant__instant _x_0 = _con_x2266->instant;
    struct kk_std_time_date_Clock* _con_x2267 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2268 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2269 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0_0_0 = _x_0.since;
      kk_std_time_instant__timescale _x_0_0 = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x2270 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x2271 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      _x_x2265 = _x_0_0; /*std/time/instant/timescale*/
    }
  }
  kk_std_core_types__optional _x_x2272;
  kk_box_t _x_x2273;
  kk_std_num_ddouble__ddouble _x_x2274;
  {
    struct kk_std_time_time_Time* _con_x2275 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_2 = _con_x2275->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2275->clock;
    kk_std_time_calendar__calendar _pat_8_1 = _con_x2275->calendar;
    kk_std_time_duration__duration _x_2 = _con_x2275->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2275->timezone;
    kk_std_time_instant__instant _pat_23_0_0 = _con_x2275->instant;
    struct kk_std_time_date_Clock* _con_x2276 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2277 = kk_std_time_calendar__as_Calendar(_pat_8_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2278 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
    kk_string_t _pat_18_0_0 = _con_x2275->tzabbrv;
    kk_integer_t _pat_5_1 = _con_x2276->hours;
    kk_integer_t _pat_6_1 = _con_x2276->minutes;
    kk_string_t _pat_9_1 = _con_x2277->name;
    kk_string_t _pat_10_0_0 = _con_x2277->long_name;
    kk_string_t _pat_11_0_0 = _con_x2277->month_prefix;
    kk_function_t _pat_12_0_0 = _con_x2277->show_era;
    kk_function_t _pat_13_0_0 = _con_x2277->instant_to_dc;
    kk_function_t _pat_14_0_0 = _con_x2277->dc_to_instant;
    kk_function_t _pat_15_0_0 = _con_x2277->days_to_date;
    kk_function_t _pat_16_0_0 = _con_x2277->date_to_days;
    kk_string_t _pat_20_0_0 = _con_x2278->name;
    kk_function_t _pat_21_0_0 = _con_x2278->utc_delta;
    kk_function_t _pat_22_0_0 = _con_x2278->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_1, _ctx)) {
        kk_string_drop(_pat_9_1, _ctx);
        kk_function_drop(_pat_16_0_0, _ctx);
        kk_function_drop(_pat_15_0_0, _ctx);
        kk_function_drop(_pat_14_0_0, _ctx);
        kk_function_drop(_pat_13_0_0, _ctx);
        kk_function_drop(_pat_12_0_0, _ctx);
        kk_string_drop(_pat_11_0_0, _ctx);
        kk_string_drop(_pat_10_0_0, _ctx);
        kk_datatype_ptr_free(_pat_8_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_1, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_1, _ctx)) {
        kk_integer_drop(_pat_6_1, _ctx);
        kk_integer_drop(_pat_5_1, _ctx);
        kk_datatype_ptr_free(_pat_4_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_1, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23_0_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0_0, _ctx)) {
        kk_function_drop(_pat_22_0_0, _ctx);
        kk_function_drop(_pat_21_0_0, _ctx);
        kk_string_drop(_pat_20_0_0, _ctx);
        kk_datatype_ptr_free(_pat_19_0_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19_0_0, _ctx);
      }
      kk_string_drop(_pat_18_0_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble _x_1 = _x_2.secs;
      _x_x2274 = _x_1; /*std/time/timestamp/timespan*/
    }
  }
  _x_x2273 = kk_std_num_ddouble__ddouble_box(_x_x2274, _ctx); /*7*/
  _x_x2272 = kk_std_core_types__new_Optional(_x_x2273, _ctx); /*? 7*/
  return kk_std_time_instant_mjd(_x_x2260, _x_x2265, _x_x2272, _ctx);
}
 
// Return the weekday of a given time `t`.

kk_std_time_date__weekday kk_std_time_time_weekday(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> std/time/date/weekday */ 
  kk_integer_t days;
  kk_std_num_ddouble__ddouble _x_x2279;
  kk_std_num_ddouble__ddouble _x_x2280;
  kk_std_time_instant__instant _x_x2281;
  {
    struct kk_std_time_time_Time* _con_x2282 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2282->date;
    kk_std_time_date__clock _pat_4 = _con_x2282->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2282->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2282->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x2282->timezone;
    kk_std_time_instant__instant _x = _con_x2282->instant;
    struct kk_std_time_date_Clock* _con_x2283 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2284 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2285 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x2281 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__timescale _x_x2286;
  {
    struct kk_std_time_time_Time* _con_x2287 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x2287->date;
    kk_std_time_date__clock _pat_4_0 = _con_x2287->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x2287->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x2287->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x2287->timezone;
    kk_std_time_instant__instant _x_0 = _con_x2287->instant;
    struct kk_std_time_date_Clock* _con_x2288 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2289 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2290 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0_0_0 = _x_0.since;
      kk_std_time_instant__timescale _x_0_0 = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x2291 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x2292 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      _x_x2286 = _x_0_0; /*std/time/instant/timescale*/
    }
  }
  kk_std_core_types__optional _x_x2293;
  kk_box_t _x_x2294;
  kk_std_num_ddouble__ddouble _x_x2295;
  {
    struct kk_std_time_time_Time* _con_x2296 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_2 = _con_x2296->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2296->clock;
    kk_std_time_calendar__calendar _pat_8_1 = _con_x2296->calendar;
    kk_std_time_duration__duration _x_2 = _con_x2296->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2296->timezone;
    kk_std_time_instant__instant _pat_23_0_0 = _con_x2296->instant;
    struct kk_std_time_date_Clock* _con_x2297 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2298 = kk_std_time_calendar__as_Calendar(_pat_8_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2299 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
    kk_string_t _pat_18_0_0 = _con_x2296->tzabbrv;
    kk_integer_t _pat_5_1 = _con_x2297->hours;
    kk_integer_t _pat_6_1 = _con_x2297->minutes;
    kk_string_t _pat_9_1 = _con_x2298->name;
    kk_string_t _pat_10_0_0 = _con_x2298->long_name;
    kk_string_t _pat_11_0_0 = _con_x2298->month_prefix;
    kk_function_t _pat_12_0_0 = _con_x2298->show_era;
    kk_function_t _pat_13_0_0 = _con_x2298->instant_to_dc;
    kk_function_t _pat_14_0_0 = _con_x2298->dc_to_instant;
    kk_function_t _pat_15_0_0 = _con_x2298->days_to_date;
    kk_function_t _pat_16_0_0 = _con_x2298->date_to_days;
    kk_string_t _pat_20_0_0 = _con_x2299->name;
    kk_function_t _pat_21_0_0 = _con_x2299->utc_delta;
    kk_function_t _pat_22_0_0 = _con_x2299->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_1, _ctx)) {
        kk_string_drop(_pat_9_1, _ctx);
        kk_function_drop(_pat_16_0_0, _ctx);
        kk_function_drop(_pat_15_0_0, _ctx);
        kk_function_drop(_pat_14_0_0, _ctx);
        kk_function_drop(_pat_13_0_0, _ctx);
        kk_function_drop(_pat_12_0_0, _ctx);
        kk_string_drop(_pat_11_0_0, _ctx);
        kk_string_drop(_pat_10_0_0, _ctx);
        kk_datatype_ptr_free(_pat_8_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_1, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_1, _ctx)) {
        kk_integer_drop(_pat_6_1, _ctx);
        kk_integer_drop(_pat_5_1, _ctx);
        kk_datatype_ptr_free(_pat_4_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_1, _ctx);
      }
      kk_std_time_instant__instant_drop(_pat_23_0_0, _ctx);
      if kk_likely(kk_datatype_ptr_is_unique(_pat_19_0_0, _ctx)) {
        kk_function_drop(_pat_22_0_0, _ctx);
        kk_function_drop(_pat_21_0_0, _ctx);
        kk_string_drop(_pat_20_0_0, _ctx);
        kk_datatype_ptr_free(_pat_19_0_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_19_0_0, _ctx);
      }
      kk_string_drop(_pat_18_0_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_std_num_ddouble__ddouble _x_1 = _x_2.secs;
      _x_x2295 = _x_1; /*std/time/timestamp/timespan*/
    }
  }
  _x_x2294 = kk_std_num_ddouble__ddouble_box(_x_x2295, _ctx); /*7*/
  _x_x2293 = kk_std_core_types__new_Optional(_x_x2294, _ctx); /*? 7*/
  _x_x2280 = kk_std_time_instant_mjd(_x_x2281, _x_x2286, _x_x2293, _ctx); /*std/num/ddouble/ddouble*/
  _x_x2279 = kk_std_num_ddouble_floor(_x_x2280, _ctx); /*std/num/ddouble/ddouble*/
  days = kk_std_num_ddouble_int(_x_x2279, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_integer_t dow;
  kk_integer_t _x_x2300 = kk_integer_add_small_const(days, 3, _ctx); /*int*/
  dow = kk_integer_mod(_x_x2300,(kk_integer_from_small(7)),kk_context()); /*int*/
  return kk_std_time_date_weekday(dow, _ctx);
}
 
// Return the time at the start of the week (Monday) of time `t`.

kk_std_time_time__time kk_std_time_time_start_of_week(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> time */ 
  kk_std_time_date__weekday dow;
  kk_std_time_time__time _x_x2301 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  dow = kk_std_time_time_weekday(_x_x2301, _ctx); /*std/time/date/weekday*/
  bool _match_x704;
  kk_std_core_types__order _x_x2302 = kk_std_time_date_weekday_fs_cmp(dow, kk_std_time_date__new_Mon(_ctx), _ctx); /*order*/
  _match_x704 = kk_std_core_order__lp__eq__eq__rp_(_x_x2302, kk_std_core_types__new_Eq(_ctx), _ctx); /*bool*/
  if (_match_x704) {
    kk_std_time_time__time _x_x2303 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
    kk_std_core_types__optional _x_x2304;
    kk_box_t _x_x2305;
    kk_std_time_date__date _x_x2306;
    {
      struct kk_std_time_time_Time* _con_x2307 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x = _con_x2307->date;
      kk_std_time_date__clock _pat_3 = _con_x2307->clock;
      kk_std_time_calendar__calendar _pat_7 = _con_x2307->calendar;
      kk_std_time_duration__duration _pat_16 = _con_x2307->tzdelta;
      kk_std_time_calendar__timezone _pat_19 = _con_x2307->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x2307->instant;
      struct kk_std_time_date_Clock* _con_x2308 = kk_std_time_date__as_Clock(_pat_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2309 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2310 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
      kk_string_t _pat_18 = _con_x2307->tzabbrv;
      kk_integer_t _pat_4 = _con_x2308->hours;
      kk_integer_t _pat_5 = _con_x2308->minutes;
      kk_string_t _pat_8 = _con_x2309->name;
      kk_string_t _pat_9 = _con_x2309->long_name;
      kk_string_t _pat_10 = _con_x2309->month_prefix;
      kk_function_t _pat_11 = _con_x2309->show_era;
      kk_function_t _pat_12 = _con_x2309->instant_to_dc;
      kk_function_t _pat_13 = _con_x2309->dc_to_instant;
      kk_function_t _pat_14 = _con_x2309->days_to_date;
      kk_function_t _pat_15 = _con_x2309->date_to_days;
      kk_string_t _pat_20 = _con_x2310->name;
      kk_function_t _pat_21 = _con_x2310->utc_delta;
      kk_function_t _pat_22 = _con_x2310->utc_inverse;
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
        kk_std_time_date__date_dup(_x, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      _x_x2306 = _x; /*std/time/date/date*/
    }
    _x_x2305 = kk_std_time_date__date_box(_x_x2306, _ctx); /*7*/
    _x_x2304 = kk_std_core_types__new_Optional(_x_x2305, _ctx); /*? 7*/
    kk_std_core_types__optional _x_x2311;
    kk_box_t _x_x2312;
    kk_std_time_date__clock _x_x2313 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    _x_x2312 = kk_std_time_date__clock_box(_x_x2313, _ctx); /*7*/
    _x_x2311 = kk_std_core_types__new_Optional(_x_x2312, _ctx); /*? 7*/
    return kk_std_time_time_copy_dc(_x_x2303, _x_x2304, _x_x2311, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
  }
  {
    kk_integer_t y_0_10251 = kk_std_time_date_int(dow, _ctx); /*int*/;
    kk_integer_t x_10248;
    kk_integer_t _x_x2314;
    {
      struct kk_std_time_time_Time* _con_x2315 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _x_3 = _con_x2315->date;
      kk_std_time_date__clock _pat_3_2 = _con_x2315->clock;
      kk_std_time_calendar__calendar _pat_7_2 = _con_x2315->calendar;
      kk_std_time_duration__duration _pat_16_2 = _con_x2315->tzdelta;
      kk_std_time_calendar__timezone _pat_19_2 = _con_x2315->timezone;
      kk_std_time_instant__instant _pat_23_2 = _con_x2315->instant;
      struct kk_std_time_date_Clock* _con_x2316 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2317 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2318 = kk_std_time_calendar__as_Timezone(_pat_19_2, _ctx);
      kk_std_time_date__date_dup(_x_3, _ctx);
      {
        kk_integer_t _x_2 = _x_3.day;
        kk_integer_dup(_x_2, _ctx);
        kk_std_time_date__date_drop(_x_3, _ctx);
        _x_x2314 = _x_2; /*int*/
      }
    }
    x_10248 = kk_integer_sub(_x_x2314,y_0_10251,kk_context()); /*int*/
    kk_integer_t _b_x430_431 = kk_integer_add_small_const(x_10248, 1, _ctx); /*int*/;
    kk_std_time_time__time _x_x2319 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
    kk_std_core_types__optional _x_x2320;
    kk_box_t _x_x2321;
    kk_std_time_date__date _x_x2322;
    kk_integer_t _x_x2323;
    kk_std_core_types__optional _match_x707 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x707, _ctx)) {
      kk_box_t _box_x432 = _match_x707._cons._Optional.value;
      kk_integer_t _uniq_year_102 = kk_integer_unbox(_box_x432, _ctx);
      kk_integer_dup(_uniq_year_102, _ctx);
      kk_std_core_types__optional_drop(_match_x707, _ctx);
      _x_x2323 = _uniq_year_102; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x707, _ctx);
      {
        struct kk_std_time_time_Time* _con_x2324 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_1 = _con_x2324->date;
        kk_std_time_date__clock _pat_3_1 = _con_x2324->clock;
        kk_std_time_calendar__calendar _pat_7_1 = _con_x2324->calendar;
        kk_std_time_duration__duration _pat_16_1 = _con_x2324->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1 = _con_x2324->timezone;
        kk_std_time_instant__instant _pat_23_1 = _con_x2324->instant;
        struct kk_std_time_date_Clock* _con_x2325 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2326 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2327 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
        kk_std_time_date__date_dup(_x_1, _ctx);
        {
          kk_integer_t _x_4 = _x_1.year;
          kk_integer_dup(_x_4, _ctx);
          kk_std_time_date__date_drop(_x_1, _ctx);
          _x_x2323 = _x_4; /*int*/
        }
      }
    }
    kk_integer_t _x_x2328;
    kk_std_core_types__optional _match_x706 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x706, _ctx)) {
      kk_box_t _box_x433 = _match_x706._cons._Optional.value;
      kk_integer_t _uniq_month_110 = kk_integer_unbox(_box_x433, _ctx);
      kk_integer_dup(_uniq_month_110, _ctx);
      kk_std_core_types__optional_drop(_match_x706, _ctx);
      _x_x2328 = _uniq_month_110; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x706, _ctx);
      {
        struct kk_std_time_time_Time* _con_x2329 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_1_0 = _con_x2329->date;
        kk_std_time_date__clock _pat_3_1_0 = _con_x2329->clock;
        kk_std_time_calendar__calendar _pat_7_1_0 = _con_x2329->calendar;
        kk_std_time_duration__duration _pat_16_1_0 = _con_x2329->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1_0 = _con_x2329->timezone;
        kk_std_time_instant__instant _pat_23_1_0 = _con_x2329->instant;
        struct kk_std_time_date_Clock* _con_x2330 = kk_std_time_date__as_Clock(_pat_3_1_0, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2331 = kk_std_time_calendar__as_Calendar(_pat_7_1_0, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2332 = kk_std_time_calendar__as_Timezone(_pat_19_1_0, _ctx);
        kk_std_time_date__date_dup(_x_1_0, _ctx);
        {
          kk_integer_t _x_0_0 = _x_1_0.month;
          kk_integer_dup(_x_0_0, _ctx);
          kk_std_time_date__date_drop(_x_1_0, _ctx);
          _x_x2328 = _x_0_0; /*int*/
        }
      }
    }
    kk_integer_t _x_x2333;
    kk_std_core_types__optional _match_x705 = kk_std_core_types__new_Optional(kk_integer_box(_b_x430_431, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x705, _ctx)) {
      kk_box_t _box_x434 = _match_x705._cons._Optional.value;
      kk_integer_t _uniq_day_118 = kk_integer_unbox(_box_x434, _ctx);
      kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
      kk_integer_dup(_uniq_day_118, _ctx);
      kk_std_core_types__optional_drop(_match_x705, _ctx);
      _x_x2333 = _uniq_day_118; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x705, _ctx);
      {
        struct kk_std_time_time_Time* _con_x2334 = kk_std_time_time__as_Time(t, _ctx);
        kk_std_time_date__date _x_1_1 = _con_x2334->date;
        kk_std_time_date__clock _pat_3_1_1 = _con_x2334->clock;
        kk_std_time_calendar__calendar _pat_7_1_1 = _con_x2334->calendar;
        kk_std_time_duration__duration _pat_16_1_1 = _con_x2334->tzdelta;
        kk_std_time_calendar__timezone _pat_19_1_1 = _con_x2334->timezone;
        kk_std_time_instant__instant _pat_23_1_1 = _con_x2334->instant;
        struct kk_std_time_date_Clock* _con_x2335 = kk_std_time_date__as_Clock(_pat_3_1_1, _ctx);
        struct kk_std_time_calendar_Calendar* _con_x2336 = kk_std_time_calendar__as_Calendar(_pat_7_1_1, _ctx);
        struct kk_std_time_calendar_Timezone* _con_x2337 = kk_std_time_calendar__as_Timezone(_pat_19_1_1, _ctx);
        kk_string_t _pat_18_1_1 = _con_x2334->tzabbrv;
        kk_integer_t _pat_4_1_1 = _con_x2335->hours;
        kk_integer_t _pat_5_1_1 = _con_x2335->minutes;
        kk_string_t _pat_8_1_1 = _con_x2336->name;
        kk_string_t _pat_9_1_1 = _con_x2336->long_name;
        kk_string_t _pat_10_1_1 = _con_x2336->month_prefix;
        kk_function_t _pat_11_1_1 = _con_x2336->show_era;
        kk_function_t _pat_12_1_1 = _con_x2336->instant_to_dc;
        kk_function_t _pat_13_1_1 = _con_x2336->dc_to_instant;
        kk_function_t _pat_14_1_1 = _con_x2336->days_to_date;
        kk_function_t _pat_15_1_1 = _con_x2336->date_to_days;
        kk_string_t _pat_20_1_1 = _con_x2337->name;
        kk_function_t _pat_21_1_1 = _con_x2337->utc_delta;
        kk_function_t _pat_22_1_1 = _con_x2337->utc_inverse;
        if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_7_1_1, _ctx)) {
            kk_string_drop(_pat_9_1_1, _ctx);
            kk_string_drop(_pat_8_1_1, _ctx);
            kk_function_drop(_pat_15_1_1, _ctx);
            kk_function_drop(_pat_14_1_1, _ctx);
            kk_function_drop(_pat_13_1_1, _ctx);
            kk_function_drop(_pat_12_1_1, _ctx);
            kk_function_drop(_pat_11_1_1, _ctx);
            kk_string_drop(_pat_10_1_1, _ctx);
            kk_datatype_ptr_free(_pat_7_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_7_1_1, _ctx);
          }
          if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1_1, _ctx)) {
            kk_integer_drop(_pat_5_1_1, _ctx);
            kk_integer_drop(_pat_4_1_1, _ctx);
            kk_datatype_ptr_free(_pat_3_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_3_1_1, _ctx);
          }
          kk_std_time_instant__instant_drop(_pat_23_1_1, _ctx);
          if kk_likely(kk_datatype_ptr_is_unique(_pat_19_1_1, _ctx)) {
            kk_function_drop(_pat_22_1_1, _ctx);
            kk_function_drop(_pat_21_1_1, _ctx);
            kk_string_drop(_pat_20_1_1, _ctx);
            kk_datatype_ptr_free(_pat_19_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_pat_19_1_1, _ctx);
          }
          kk_string_drop(_pat_18_1_1, _ctx);
          kk_datatype_ptr_free(t, _ctx);
        }
        else {
          kk_std_time_date__date_dup(_x_1_1, _ctx);
          kk_datatype_ptr_decref(t, _ctx);
        }
        {
          kk_integer_t _x_1_0_0 = _x_1_1.day;
          kk_integer_dup(_x_1_0_0, _ctx);
          kk_std_time_date__date_drop(_x_1_1, _ctx);
          _x_x2333 = _x_1_0_0; /*int*/
        }
      }
    }
    _x_x2322 = kk_std_time_date__new_Date(_x_x2323, _x_x2328, _x_x2333, _ctx); /*std/time/date/date*/
    _x_x2321 = kk_std_time_date__date_box(_x_x2322, _ctx); /*7*/
    _x_x2320 = kk_std_core_types__new_Optional(_x_x2321, _ctx); /*? 7*/
    kk_std_core_types__optional _x_x2338;
    kk_box_t _x_x2339;
    kk_std_time_date__clock _x_x2340 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
    _x_x2339 = kk_std_time_date__clock_box(_x_x2340, _ctx); /*7*/
    _x_x2338 = kk_std_core_types__new_Optional(_x_x2339, _ctx); /*? 7*/
    return kk_std_time_time_copy_dc(_x_x2319, _x_x2320, _x_x2338, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
  }
}
 
// Return the time at the start of the year of time `t`.

kk_std_time_time__time kk_std_time_time_start_of_year(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> time */ 
  kk_std_time_time__time _x_x2341 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  kk_std_core_types__optional _x_x2342;
  kk_box_t _x_x2343;
  kk_std_time_date__date _x_x2344;
  kk_integer_t _x_x2345;
  {
    struct kk_std_time_time_Time* _con_x2346 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x2346->date;
    kk_std_time_date__clock _pat_3 = _con_x2346->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2346->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2346->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2346->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2346->instant;
    struct kk_std_time_date_Clock* _con_x2347 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2348 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2349 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2346->tzabbrv;
    kk_integer_t _pat_4 = _con_x2347->hours;
    kk_integer_t _pat_5 = _con_x2347->minutes;
    kk_string_t _pat_8 = _con_x2348->name;
    kk_string_t _pat_9 = _con_x2348->long_name;
    kk_string_t _pat_10 = _con_x2348->month_prefix;
    kk_function_t _pat_11 = _con_x2348->show_era;
    kk_function_t _pat_12 = _con_x2348->instant_to_dc;
    kk_function_t _pat_13 = _con_x2348->dc_to_instant;
    kk_function_t _pat_14 = _con_x2348->days_to_date;
    kk_function_t _pat_15 = _con_x2348->date_to_days;
    kk_string_t _pat_20 = _con_x2349->name;
    kk_function_t _pat_21 = _con_x2349->utc_delta;
    kk_function_t _pat_22 = _con_x2349->utc_inverse;
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
      _x_x2345 = _x; /*int*/
    }
  }
  _x_x2344 = kk_std_time_date__new_Date(_x_x2345, kk_integer_from_small(1), kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  _x_x2343 = kk_std_time_date__date_box(_x_x2344, _ctx); /*7*/
  _x_x2342 = kk_std_core_types__new_Optional(_x_x2343, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2350;
  kk_box_t _x_x2351;
  kk_std_time_date__clock _x_x2352 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  _x_x2351 = kk_std_time_date__clock_box(_x_x2352, _ctx); /*7*/
  _x_x2350 = kk_std_core_types__new_Optional(_x_x2351, _ctx); /*? 7*/
  return kk_std_time_time_copy_dc(_x_x2341, _x_x2342, _x_x2350, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return a `:time` as a fractional year.
// `year-frac(time(2000,7,2)) == fixed(2000.5)`

kk_std_num_ddouble__ddouble kk_std_time_time_year_frac(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble x_10263;
  kk_std_num_ddouble__ddouble _x_x2353;
  kk_std_time_instant__instant _x_x2354;
  {
    struct kk_std_time_time_Time* _con_x2355 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2355->date;
    kk_std_time_date__clock _pat_4 = _con_x2355->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2355->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2355->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x2355->timezone;
    kk_std_time_instant__instant _x = _con_x2355->instant;
    struct kk_std_time_date_Clock* _con_x2356 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2357 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2358 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x2354 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__timescale _x_x2359;
  {
    struct kk_std_time_time_Time* _con_x2360 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x2360->date;
    kk_std_time_date__clock _pat_4_0 = _con_x2360->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x2360->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x2360->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x2360->timezone;
    kk_std_time_instant__instant _x_0 = _con_x2360->instant;
    struct kk_std_time_date_Clock* _con_x2361 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2362 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2363 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_std_time_instant__instant_dup(_x_0, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0_0_0 = _x_0.since;
      kk_std_time_instant__timescale _x_0_0 = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x2364 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x2365 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      _x_x2359 = _x_0_0; /*std/time/instant/timescale*/
    }
  }
  kk_std_core_types__optional _x_x2366;
  kk_box_t _x_x2367;
  kk_std_num_ddouble__ddouble _x_x2368;
  {
    struct kk_std_time_time_Time* _con_x2369 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_2 = _con_x2369->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2369->clock;
    kk_std_time_calendar__calendar _pat_8_1 = _con_x2369->calendar;
    kk_std_time_duration__duration _x_2 = _con_x2369->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2369->timezone;
    kk_std_time_instant__instant _pat_23_0_0 = _con_x2369->instant;
    struct kk_std_time_date_Clock* _con_x2370 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2371 = kk_std_time_calendar__as_Calendar(_pat_8_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2372 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
    {
      kk_std_num_ddouble__ddouble _x_1 = _x_2.secs;
      _x_x2368 = _x_1; /*std/time/timestamp/timespan*/
    }
  }
  _x_x2367 = kk_std_num_ddouble__ddouble_box(_x_x2368, _ctx); /*7*/
  _x_x2366 = kk_std_core_types__new_Optional(_x_x2367, _ctx); /*? 7*/
  _x_x2353 = kk_std_time_instant_mjd(_x_x2354, _x_x2359, _x_x2366, _ctx); /*std/num/ddouble/ddouble*/
  x_10263 = kk_std_num_ddouble_fraction(_x_x2353, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t x_0_10264;
  kk_std_time_time__time _x_x2373 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  x_0_10264 = kk_std_time_time_day_of_year(_x_x2373, _ctx); /*int*/
  double yfrac;
  double _x_x2374;
  double _x_x2375;
  kk_integer_t _x_x2376 = kk_integer_add_small_const(x_0_10264, -1, _ctx); /*int*/
  _x_x2375 = kk_integer_as_double(_x_x2376,kk_context()); /*float64*/
  double _x_x2377;
  {
    double _x_3 = x_10263.hi;
    _x_x2377 = _x_3; /*float64*/
  }
  _x_x2374 = (_x_x2375 + _x_x2377); /*float64*/
  double _x_x2378;
  kk_integer_t _x_x2379;
  kk_std_time_time__time _x_x2380 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  _x_x2379 = kk_std_time_time_days_in_year(_x_x2380, _ctx); /*int*/
  _x_x2378 = kk_integer_as_double(_x_x2379,kk_context()); /*float64*/
  yfrac = (_x_x2374 / _x_x2378); /*float64*/
  kk_integer_t _x_x2381;
  {
    struct kk_std_time_time_Time* _con_x2382 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_1_0 = _con_x2382->date;
    kk_std_time_date__clock _pat_3_2 = _con_x2382->clock;
    kk_std_time_calendar__calendar _pat_7_2 = _con_x2382->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x2382->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x2382->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x2382->instant;
    struct kk_std_time_date_Clock* _con_x2383 = kk_std_time_date__as_Clock(_pat_3_2, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2384 = kk_std_time_calendar__as_Calendar(_pat_7_2, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2385 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_string_t _pat_18_1 = _con_x2382->tzabbrv;
    kk_integer_t _pat_4_2 = _con_x2383->hours;
    kk_integer_t _pat_5_2 = _con_x2383->minutes;
    kk_string_t _pat_8_2 = _con_x2384->name;
    kk_string_t _pat_9_2 = _con_x2384->long_name;
    kk_string_t _pat_10_1 = _con_x2384->month_prefix;
    kk_function_t _pat_11_1 = _con_x2384->show_era;
    kk_function_t _pat_12_1 = _con_x2384->instant_to_dc;
    kk_function_t _pat_13_1 = _con_x2384->dc_to_instant;
    kk_function_t _pat_14_1 = _con_x2384->days_to_date;
    kk_function_t _pat_15_1 = _con_x2384->date_to_days;
    kk_string_t _pat_20_1 = _con_x2385->name;
    kk_function_t _pat_21_1 = _con_x2385->utc_delta;
    kk_function_t _pat_22_1 = _con_x2385->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_7_2, _ctx)) {
        kk_string_drop(_pat_9_2, _ctx);
        kk_string_drop(_pat_8_2, _ctx);
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
      kk_std_time_date__date_dup(_x_1_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_integer_t _x_0_0_0 = _x_1_0.year;
      kk_integer_dup(_x_0_0_0, _ctx);
      kk_std_time_date__date_drop(_x_1_0, _ctx);
      _x_x2381 = _x_0_0_0; /*int*/
    }
  }
  kk_std_core_types__optional _x_x2386 = kk_std_core_types__new_Optional(kk_double_box(yfrac, _ctx), _ctx); /*? 7*/
  return kk_std_time_timestamp_int_fs_timespan(_x_x2381, _x_x2386, _ctx);
}
 
// Return the total months in the year of time `t`.
// For Gregorian calendars this is always 12 but some calendars have a varying number of months per year.

kk_integer_t kk_std_time_time_months_in_year(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> int */ 
  kk_std_time_date__date _b_x449_450;
  kk_integer_t _x_x2387;
  kk_integer_t _x_x2388;
  {
    struct kk_std_time_time_Time* _con_x2389 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_2 = _con_x2389->date;
    kk_std_time_date__clock _pat_3_0 = _con_x2389->clock;
    kk_std_time_calendar__calendar _pat_7_0 = _con_x2389->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2389->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2389->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2389->instant;
    struct kk_std_time_date_Clock* _con_x2390 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2391 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2392 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_2, _ctx);
    {
      kk_integer_t _x_1 = _x_2.year;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_x_2, _ctx);
      _x_x2388 = _x_1; /*int*/
    }
  }
  _x_x2387 = kk_integer_add_small_const(_x_x2388, 1, _ctx); /*int*/
  _b_x449_450 = kk_std_time_date__new_Date(_x_x2387, kk_integer_from_small(1), kk_integer_from_small(0), _ctx); /*std/time/date/date*/
  kk_std_time_time__time t_0_10269;
  kk_std_core_types__optional _x_x2393 = kk_std_core_types__new_Optional(kk_std_time_date__date_box(_b_x449_450, _ctx), _ctx); /*? 7*/
  t_0_10269 = kk_std_time_time_copy_dc(t, _x_x2393, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  {
    struct kk_std_time_time_Time* _con_x2394 = kk_std_time_time__as_Time(t_0_10269, _ctx);
    kk_std_time_date__date _x_0 = _con_x2394->date;
    kk_std_time_date__clock _pat_3 = _con_x2394->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2394->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2394->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2394->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2394->instant;
    struct kk_std_time_date_Clock* _con_x2395 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2396 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2397 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_string_t _pat_18 = _con_x2394->tzabbrv;
    kk_integer_t _pat_4 = _con_x2395->hours;
    kk_integer_t _pat_5 = _con_x2395->minutes;
    kk_string_t _pat_8 = _con_x2396->name;
    kk_string_t _pat_9 = _con_x2396->long_name;
    kk_string_t _pat_10 = _con_x2396->month_prefix;
    kk_function_t _pat_11 = _con_x2396->show_era;
    kk_function_t _pat_12 = _con_x2396->instant_to_dc;
    kk_function_t _pat_13 = _con_x2396->dc_to_instant;
    kk_function_t _pat_14 = _con_x2396->days_to_date;
    kk_function_t _pat_15 = _con_x2396->date_to_days;
    kk_string_t _pat_20 = _con_x2397->name;
    kk_function_t _pat_21 = _con_x2397->utc_delta;
    kk_function_t _pat_22 = _con_x2397->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t_0_10269, _ctx)) {
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
      kk_datatype_ptr_free(t_0_10269, _ctx);
    }
    else {
      kk_std_time_date__date_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t_0_10269, _ctx);
    }
    {
      kk_integer_t _x = _x_0.month;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      return _x;
    }
  }
}
 
// Return the `n`th week day following (and including) time `t`.
// Use `n = 1` for the first week day `wd` following `t`;
// Use `0` for the last occurrence of week day `wd` before `t`.
// `time(2016,10,10).nth-weekday(1,Sun)` &quad; (2016-10-13, first Sunday following October 10, 2016)
// `time(2016,11,16).start-of-month.nth-weekday(0,Wed)` &quad; (2016-10-26, the last Wednesday before 2016-11-01)

kk_std_time_time__time kk_std_time_time_nth_weekday(kk_std_time_time__time t, kk_integer_t n, kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (t : time, n : int, wd : std/time/date/weekday) -> time */ 
  kk_std_time_date__weekday dow;
  kk_std_time_time__time _x_x2398 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  dow = kk_std_time_time_weekday(_x_x2398, _ctx); /*std/time/date/weekday*/
  kk_integer_t x_10029 = kk_std_time_date_int(wd, _ctx); /*int*/;
  kk_integer_t y_10030 = kk_std_time_date_int(dow, _ctx); /*int*/;
  kk_integer_t inc;
  kk_integer_t _x_x2399 = kk_integer_sub(x_10029,y_10030,kk_context()); /*int*/
  inc = kk_integer_mod(_x_x2399,(kk_integer_from_small(7)),kk_context()); /*int*/
  kk_integer_t x_10279;
  kk_integer_t _x_x2400;
  {
    struct kk_std_time_time_Time* _con_x2401 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x2401->date;
    kk_std_time_date__clock _pat_3 = _con_x2401->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2401->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2401->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2401->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2401->instant;
    struct kk_std_time_date_Clock* _con_x2402 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2403 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2404 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__date_dup(_x_0, _ctx);
    {
      kk_integer_t _x = _x_0.day;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      _x_x2400 = _x; /*int*/
    }
  }
  x_10279 = kk_integer_add(_x_x2400,inc,kk_context()); /*int*/
  kk_integer_t y_10280;
  kk_integer_t _x_x2405 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
  y_10280 = kk_integer_mul((kk_integer_from_small(7)),_x_x2405,kk_context()); /*int*/
  kk_integer_t wday = kk_integer_add(x_10279,y_10280,kk_context()); /*int*/;
  kk_std_time_time__time _x_x2406 = kk_std_time_time__time_dup(t, _ctx); /*std/time/time/time*/
  kk_std_core_types__optional _x_x2407;
  kk_box_t _x_x2408;
  kk_std_time_date__date _x_x2409;
  kk_integer_t _x_x2410;
  {
    struct kk_std_time_time_Time* _con_x2411 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_2 = _con_x2411->date;
    kk_std_time_date__clock _pat_3_0 = _con_x2411->clock;
    kk_std_time_calendar__calendar _pat_7_0 = _con_x2411->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2411->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2411->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2411->instant;
    struct kk_std_time_date_Clock* _con_x2412 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2413 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2414 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_2, _ctx);
    {
      kk_integer_t _x_1 = _x_2.year;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_x_2, _ctx);
      _x_x2410 = _x_1; /*int*/
    }
  }
  kk_integer_t _x_x2415;
  {
    struct kk_std_time_time_Time* _con_x2416 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_4 = _con_x2416->date;
    kk_std_time_date__clock _pat_3_1 = _con_x2416->clock;
    kk_std_time_calendar__calendar _pat_7_1 = _con_x2416->calendar;
    kk_std_time_duration__duration _pat_16_1 = _con_x2416->tzdelta;
    kk_std_time_calendar__timezone _pat_19_1 = _con_x2416->timezone;
    kk_std_time_instant__instant _pat_23_1 = _con_x2416->instant;
    struct kk_std_time_date_Clock* _con_x2417 = kk_std_time_date__as_Clock(_pat_3_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2418 = kk_std_time_calendar__as_Calendar(_pat_7_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2419 = kk_std_time_calendar__as_Timezone(_pat_19_1, _ctx);
    kk_string_t _pat_18_1 = _con_x2416->tzabbrv;
    kk_integer_t _pat_4_1 = _con_x2417->hours;
    kk_integer_t _pat_5_1 = _con_x2417->minutes;
    kk_string_t _pat_8_1 = _con_x2418->name;
    kk_string_t _pat_9_1 = _con_x2418->long_name;
    kk_string_t _pat_10_1 = _con_x2418->month_prefix;
    kk_function_t _pat_11_1 = _con_x2418->show_era;
    kk_function_t _pat_12_1 = _con_x2418->instant_to_dc;
    kk_function_t _pat_13_1 = _con_x2418->dc_to_instant;
    kk_function_t _pat_14_1 = _con_x2418->days_to_date;
    kk_function_t _pat_15_1 = _con_x2418->date_to_days;
    kk_string_t _pat_20_1 = _con_x2419->name;
    kk_function_t _pat_21_1 = _con_x2419->utc_delta;
    kk_function_t _pat_22_1 = _con_x2419->utc_inverse;
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
      if kk_likely(kk_datatype_ptr_is_unique(_pat_3_1, _ctx)) {
        kk_integer_drop(_pat_5_1, _ctx);
        kk_integer_drop(_pat_4_1, _ctx);
        kk_datatype_ptr_free(_pat_3_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_3_1, _ctx);
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
      kk_std_time_date__date_dup(_x_4, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_integer_t _x_3 = _x_4.month;
      kk_integer_dup(_x_3, _ctx);
      kk_std_time_date__date_drop(_x_4, _ctx);
      _x_x2415 = _x_3; /*int*/
    }
  }
  _x_x2409 = kk_std_time_date__new_Date(_x_x2410, _x_x2415, wday, _ctx); /*std/time/date/date*/
  _x_x2408 = kk_std_time_date__date_box(_x_x2409, _ctx); /*7*/
  _x_x2407 = kk_std_core_types__new_Optional(_x_x2408, _ctx); /*? 7*/
  return kk_std_time_time_copy_dc(_x_x2406, _x_x2407, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the `n`th week day since the beginning of the month of time `t`.
// `time(2016,10,10).nth-weekday-of-month(2,Sun).date` &quad; (2016-10-09, Second Sunday of October 2016)
// `time(2016,10,10).nth-weekday-of-month(60,Sun).date` &quad; (2017-11-19, 60th Sunday since October 1, 2016)

kk_std_time_time__time kk_std_time_time_nth_weekday_of_month(kk_std_time_time__time t, kk_integer_t n, kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (t : time, n : int, wd : std/time/date/weekday) -> time */ 
  kk_std_time_date__date _b_x453_454;
  kk_integer_t _x_x2420;
  {
    struct kk_std_time_time_Time* _con_x2421 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x2421->date;
    kk_std_time_date__clock _pat_3 = _con_x2421->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2421->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2421->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2421->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2421->instant;
    struct kk_std_time_date_Clock* _con_x2422 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2423 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2424 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__date_dup(_x_0, _ctx);
    {
      kk_integer_t _x = _x_0.year;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      _x_x2420 = _x; /*int*/
    }
  }
  kk_integer_t _x_x2425;
  {
    struct kk_std_time_time_Time* _con_x2426 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_2 = _con_x2426->date;
    kk_std_time_date__clock _pat_3_0 = _con_x2426->clock;
    kk_std_time_calendar__calendar _pat_7_0 = _con_x2426->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2426->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2426->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2426->instant;
    struct kk_std_time_date_Clock* _con_x2427 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2428 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2429 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_2, _ctx);
    {
      kk_integer_t _x_1 = _x_2.month;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_x_2, _ctx);
      _x_x2425 = _x_1; /*int*/
    }
  }
  _b_x453_454 = kk_std_time_date__new_Date(_x_x2420, _x_x2425, kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  kk_std_time_time__time _x_x2430;
  kk_std_core_types__optional _x_x2431 = kk_std_core_types__new_Optional(kk_std_time_date__date_box(_b_x453_454, _ctx), _ctx); /*? 7*/
  _x_x2430 = kk_std_time_time_copy_dc(t, _x_x2431, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time_nth_weekday(_x_x2430, n, wd, _ctx);
}
 
// Return the first week day of the month of time `t`.
// `time(2016,10,10).first-weekday-of-month(Sun)` &quad; (2016-10-02, First Sunday of October 2016)

kk_std_time_time__time kk_std_time_time_first_weekday_of_month(kk_std_time_time__time t, kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (t : time, wd : std/time/date/weekday) -> time */ 
  kk_std_time_date__date _b_x455_456;
  kk_integer_t _x_x2432;
  {
    struct kk_std_time_time_Time* _con_x2433 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x2433->date;
    kk_std_time_date__clock _pat_3 = _con_x2433->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2433->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2433->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2433->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2433->instant;
    struct kk_std_time_date_Clock* _con_x2434 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2435 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2436 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__date_dup(_x_0, _ctx);
    {
      kk_integer_t _x = _x_0.year;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      _x_x2432 = _x; /*int*/
    }
  }
  kk_integer_t _x_x2437;
  {
    struct kk_std_time_time_Time* _con_x2438 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_2 = _con_x2438->date;
    kk_std_time_date__clock _pat_3_0 = _con_x2438->clock;
    kk_std_time_calendar__calendar _pat_7_0 = _con_x2438->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2438->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2438->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2438->instant;
    struct kk_std_time_date_Clock* _con_x2439 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2440 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2441 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_2, _ctx);
    {
      kk_integer_t _x_1 = _x_2.month;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_x_2, _ctx);
      _x_x2437 = _x_1; /*int*/
    }
  }
  _b_x455_456 = kk_std_time_date__new_Date(_x_x2432, _x_x2437, kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  kk_std_time_time__time _x_x2442;
  kk_std_core_types__optional _x_x2443 = kk_std_core_types__new_Optional(kk_std_time_date__date_box(_b_x455_456, _ctx), _ctx); /*? 7*/
  _x_x2442 = kk_std_time_time_copy_dc(t, _x_x2443, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time_nth_weekday(_x_x2442, kk_integer_from_small(1), wd, _ctx);
}
 
// Return the last week day of the month of time `t`.
// `time(2016,10,10).last-weekday-of-month(Sun).date` &quad; (2016-10-30, Last Sunday of October 2016)

kk_std_time_time__time kk_std_time_time_last_weekday_of_month(kk_std_time_time__time t, kk_std_time_date__weekday wd, kk_context_t* _ctx) { /* (t : time, wd : std/time/date/weekday) -> time */ 
  kk_std_time_date__date _b_x457_458;
  kk_integer_t _x_x2444;
  {
    struct kk_std_time_time_Time* _con_x2445 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_0 = _con_x2445->date;
    kk_std_time_date__clock _pat_3 = _con_x2445->clock;
    kk_std_time_calendar__calendar _pat_7 = _con_x2445->calendar;
    kk_std_time_duration__duration _pat_16 = _con_x2445->tzdelta;
    kk_std_time_calendar__timezone _pat_19 = _con_x2445->timezone;
    kk_std_time_instant__instant _pat_23 = _con_x2445->instant;
    struct kk_std_time_date_Clock* _con_x2446 = kk_std_time_date__as_Clock(_pat_3, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2447 = kk_std_time_calendar__as_Calendar(_pat_7, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2448 = kk_std_time_calendar__as_Timezone(_pat_19, _ctx);
    kk_std_time_date__date_dup(_x_0, _ctx);
    {
      kk_integer_t _x = _x_0.year;
      kk_integer_dup(_x, _ctx);
      kk_std_time_date__date_drop(_x_0, _ctx);
      _x_x2444 = _x; /*int*/
    }
  }
  kk_integer_t _x_x2449;
  kk_integer_t _x_x2450;
  {
    struct kk_std_time_time_Time* _con_x2451 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _x_2 = _con_x2451->date;
    kk_std_time_date__clock _pat_3_0 = _con_x2451->clock;
    kk_std_time_calendar__calendar _pat_7_0 = _con_x2451->calendar;
    kk_std_time_duration__duration _pat_16_0 = _con_x2451->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0 = _con_x2451->timezone;
    kk_std_time_instant__instant _pat_23_0 = _con_x2451->instant;
    struct kk_std_time_date_Clock* _con_x2452 = kk_std_time_date__as_Clock(_pat_3_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2453 = kk_std_time_calendar__as_Calendar(_pat_7_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2454 = kk_std_time_calendar__as_Timezone(_pat_19_0, _ctx);
    kk_std_time_date__date_dup(_x_2, _ctx);
    {
      kk_integer_t _x_1 = _x_2.month;
      kk_integer_dup(_x_1, _ctx);
      kk_std_time_date__date_drop(_x_2, _ctx);
      _x_x2450 = _x_1; /*int*/
    }
  }
  _x_x2449 = kk_integer_add_small_const(_x_x2450, 1, _ctx); /*int*/
  _b_x457_458 = kk_std_time_date__new_Date(_x_x2444, _x_x2449, kk_integer_from_small(1), _ctx); /*std/time/date/date*/
  kk_std_time_time__time t_0_10300;
  kk_std_core_types__optional _x_x2455 = kk_std_core_types__new_Optional(kk_std_time_date__date_box(_b_x457_458, _ctx), _ctx); /*? 7*/
  t_0_10300 = kk_std_time_time_copy_dc(t, _x_x2455, kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time_nth_weekday(t_0_10300, kk_integer_from_small(0), wd, _ctx);
}

kk_std_num_ddouble__ddouble kk_std_time_time_mjd_epoch_delta;

kk_std_num_ddouble__ddouble kk_std_time_time_jd_epoch_delta;
 
// /* Return the Julian date ([JD](https://en.wikipedia.org/wiki/Julian_day))
// number for a given `:time` `t`. This interprets the Julian date in the calendar of `t` with
// the timezone of `t` applied.\
// `time(-4713,11,24,12,cal=cal-tt).jd == "0"`\
// `time(1972,1,2,tz=tz-fixed(1)).jd == "2441318.5"`\
// `time(1972,1,2,tz=tz-fixed(1)).instant.jd(ts-ti).show(9) == "2441318.458333333"`
// 
// Takes leap seconds into account when calculating the fraction of the day,
// see `mjd` for examples.
// */

kk_std_num_ddouble__ddouble kk_std_time_time_jd(kk_std_time_time__time t, kk_context_t* _ctx) { /* (t : time) -> std/num/ddouble/ddouble */ 
  kk_std_num_ddouble__ddouble _b_x459_460;
  {
    struct kk_std_time_time_Time* _con_x2456 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_2 = _con_x2456->date;
    kk_std_time_date__clock _pat_4_1 = _con_x2456->clock;
    kk_std_time_calendar__calendar _pat_8_1 = _con_x2456->calendar;
    kk_std_time_duration__duration _x_2 = _con_x2456->tzdelta;
    kk_std_time_calendar__timezone _pat_19_0_0 = _con_x2456->timezone;
    kk_std_time_instant__instant _pat_23_0_0 = _con_x2456->instant;
    struct kk_std_time_date_Clock* _con_x2457 = kk_std_time_date__as_Clock(_pat_4_1, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2458 = kk_std_time_calendar__as_Calendar(_pat_8_1, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2459 = kk_std_time_calendar__as_Timezone(_pat_19_0_0, _ctx);
    {
      kk_std_num_ddouble__ddouble _x_1 = _x_2.secs;
      _b_x459_460 = _x_1; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x2460;
  kk_std_time_instant__instant _x_x2461;
  {
    struct kk_std_time_time_Time* _con_x2462 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0 = _con_x2462->date;
    kk_std_time_date__clock _pat_4 = _con_x2462->clock;
    kk_std_time_calendar__calendar _pat_8 = _con_x2462->calendar;
    kk_std_time_duration__duration _pat_17 = _con_x2462->tzdelta;
    kk_std_time_calendar__timezone _pat_20 = _con_x2462->timezone;
    kk_std_time_instant__instant _x = _con_x2462->instant;
    struct kk_std_time_date_Clock* _con_x2463 = kk_std_time_date__as_Clock(_pat_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2464 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2465 = kk_std_time_calendar__as_Timezone(_pat_20, _ctx);
    kk_std_time_instant__instant_dup(_x, _ctx);
    _x_x2461 = _x; /*std/time/instant/instant*/
  }
  kk_std_time_instant__timescale _x_x2466;
  {
    struct kk_std_time_time_Time* _con_x2467 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_0 = _con_x2467->date;
    kk_std_time_date__clock _pat_4_0 = _con_x2467->clock;
    kk_std_time_calendar__calendar _pat_8_0 = _con_x2467->calendar;
    kk_std_time_duration__duration _pat_17_0 = _con_x2467->tzdelta;
    kk_std_time_calendar__timezone _pat_20_0 = _con_x2467->timezone;
    kk_std_time_instant__instant _x_0 = _con_x2467->instant;
    struct kk_std_time_date_Clock* _con_x2468 = kk_std_time_date__as_Clock(_pat_4_0, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2469 = kk_std_time_calendar__as_Calendar(_pat_8_0, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2470 = kk_std_time_calendar__as_Timezone(_pat_20_0, _ctx);
    kk_string_t _pat_19_0 = _con_x2467->tzabbrv;
    kk_integer_t _pat_5_0 = _con_x2468->hours;
    kk_integer_t _pat_6_0 = _con_x2468->minutes;
    kk_string_t _pat_9_0 = _con_x2469->name;
    kk_string_t _pat_10_0 = _con_x2469->long_name;
    kk_string_t _pat_11_0 = _con_x2469->month_prefix;
    kk_function_t _pat_12_0 = _con_x2469->show_era;
    kk_function_t _pat_13_0 = _con_x2469->instant_to_dc;
    kk_function_t _pat_14_0 = _con_x2469->dc_to_instant;
    kk_function_t _pat_15_0 = _con_x2469->days_to_date;
    kk_function_t _pat_16_0 = _con_x2469->date_to_days;
    kk_string_t _pat_21_0 = _con_x2470->name;
    kk_function_t _pat_22_0 = _con_x2470->utc_delta;
    kk_function_t _pat_23_0 = _con_x2470->utc_inverse;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_8_0, _ctx)) {
        kk_string_drop(_pat_9_0, _ctx);
        kk_function_drop(_pat_16_0, _ctx);
        kk_function_drop(_pat_15_0, _ctx);
        kk_function_drop(_pat_14_0, _ctx);
        kk_function_drop(_pat_13_0, _ctx);
        kk_function_drop(_pat_12_0, _ctx);
        kk_string_drop(_pat_11_0, _ctx);
        kk_string_drop(_pat_10_0, _ctx);
        kk_datatype_ptr_free(_pat_8_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_8_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_4_0, _ctx)) {
        kk_integer_drop(_pat_6_0, _ctx);
        kk_integer_drop(_pat_5_0, _ctx);
        kk_datatype_ptr_free(_pat_4_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_4_0, _ctx);
      }
      if kk_likely(kk_datatype_ptr_is_unique(_pat_20_0, _ctx)) {
        kk_function_drop(_pat_23_0, _ctx);
        kk_function_drop(_pat_22_0, _ctx);
        kk_string_drop(_pat_21_0, _ctx);
        kk_datatype_ptr_free(_pat_20_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_20_0, _ctx);
      }
      kk_string_drop(_pat_19_0, _ctx);
      kk_std_time_date__date_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_std_time_instant__instant_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    {
      kk_std_time_timestamp__timestamp _pat_0_0_0 = _x_0.since;
      kk_std_time_instant__timescale _x_0_0 = _x_0.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x2471 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x2472 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
      kk_std_time_instant__instant_drop(_x_0, _ctx);
      _x_x2466 = _x_0_0; /*std/time/instant/timescale*/
    }
  }
  kk_std_core_types__optional _x_x2473 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(_b_x459_460, _ctx), _ctx); /*? 7*/
  _x_x2460 = kk_std_time_instant_mjd(_x_x2461, _x_x2466, _x_x2473, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x_x2460, kk_std_time_time_jd_epoch_delta, _ctx);
}
 
// Return the current time in an optional timezone (=`tz-utc`) and optional calendar (=`cal-iso`).

kk_std_time_time__time kk_std_time_time_timescale_fs_time_now(kk_std_time_instant__timescale ts, kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar) -> ndet time */ 
  kk_std_time_instant__instant _x_x2474;
  kk_std_core_types__optional _x_x2475 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(ts, _ctx), _ctx); /*? 7*/
  _x_x2474 = kk_std_time_chrono_now_in(_x_x2475, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x2476;
  kk_box_t _x_x2477;
  kk_std_time_calendar__timezone _x_x2478;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x462 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_5581 = kk_std_time_calendar__timezone_unbox(_box_x462, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_5581, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x2478 = _uniq_tz_5581; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x2478 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x2477 = kk_std_time_calendar__timezone_box(_x_x2478, _ctx); /*7*/
  _x_x2476 = kk_std_core_types__new_Optional(_x_x2477, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2479;
  kk_box_t _x_x2480;
  kk_std_time_calendar__calendar _x_x2481;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x464 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5585 = kk_std_time_calendar__calendar_unbox(_box_x464, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5585, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2481 = _uniq_cal_5585; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2481 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2480 = kk_std_time_calendar__calendar_box(_x_x2481, _ctx); /*7*/
  _x_x2479 = kk_std_core_types__new_Optional(_x_x2480, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x2474, _x_x2476, _x_x2479, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_time_timezone_fs__mlift_time_now_10408_fun2483__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_timezone_fs__mlift_time_now_10408_fun2483(kk_function_t _fself, kk_box_t _b_x482, kk_box_t _b_x483, kk_box_t _b_x484, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_timezone_fs__new_mlift_time_now_10408_fun2483(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_timezone_fs__mlift_time_now_10408_fun2483, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_timezone_fs__mlift_time_now_10408_fun2483(kk_function_t _fself, kk_box_t _b_x482, kk_box_t _b_x483, kk_box_t _b_x484, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__timescale ts_0_494 = kk_std_time_instant__timescale_unbox(_b_x482, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_core_types__optional tz_0_495 = kk_std_core_types__optional_unbox(_b_x483, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/;
  kk_std_core_types__optional cal_0_496 = kk_std_core_types__optional_unbox(_b_x484, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/;
  kk_std_time_calendar__timezone _b_x471_490;
  if (kk_std_core_types__is_Optional(tz_0_495, _ctx)) {
    kk_box_t _box_x470 = tz_0_495._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_5581 = kk_std_time_calendar__timezone_unbox(_box_x470, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_5581, _ctx);
    kk_std_core_types__optional_drop(tz_0_495, _ctx);
    _b_x471_490 = _uniq_tz_5581; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz_0_495, _ctx);
    _b_x471_490 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  kk_std_time_calendar__calendar _b_x473_491;
  if (kk_std_core_types__is_Optional(cal_0_496, _ctx)) {
    kk_box_t _box_x472 = cal_0_496._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5585 = kk_std_time_calendar__calendar_unbox(_box_x472, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5585, _ctx);
    kk_std_core_types__optional_drop(cal_0_496, _ctx);
    _b_x473_491 = _uniq_cal_5585; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal_0_496, _ctx);
    _b_x473_491 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  kk_std_time_time__time _x_x2484;
  kk_std_time_instant__timescale _b_x469_489 = ts_0_494; /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x2485;
  kk_std_core_types__optional _x_x2486 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(_b_x469_489, _ctx), _ctx); /*? 7*/
  _x_x2485 = kk_std_time_chrono_now_in(_x_x2486, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x2487 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x471_490, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2488 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(_b_x473_491, _ctx), _ctx); /*? 7*/
  _x_x2484 = kk_std_time_time_instant_fs_time(_x_x2485, _x_x2487, _x_x2488, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2484, _ctx);
}

kk_std_time_time__time kk_std_time_time_timezone_fs__mlift_time_now_10408(kk_std_core_types__optional cal, kk_std_core_types__optional tz, kk_std_time_instant__timescale _c_x10335, kk_context_t* _ctx) { /* (cal : ? std/time/calendar/calendar, tz : ? std/time/calendar/timezone, std/time/instant/timescale) -> time */ 
  kk_box_t _x_x2482;
  kk_box_t _x_x2489;
  kk_std_core_types__optional _x_x2490;
  kk_box_t _x_x2491;
  kk_std_time_calendar__timezone _x_x2492;
  if (kk_std_core_types__is_Optional(tz, _ctx)) {
    kk_box_t _box_x474 = tz._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_5629 = kk_std_time_calendar__timezone_unbox(_box_x474, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_5629, _ctx);
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x2492 = _uniq_tz_5629; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz, _ctx);
    _x_x2492 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x2491 = kk_std_time_calendar__timezone_box(_x_x2492, _ctx); /*7*/
  _x_x2490 = kk_std_core_types__new_Optional(_x_x2491, _ctx); /*? 7*/
  _x_x2489 = kk_std_core_types__optional_box(_x_x2490, _ctx); /*10077*/
  kk_box_t _x_x2493;
  kk_std_core_types__optional _x_x2494;
  kk_box_t _x_x2495;
  kk_std_time_calendar__calendar _x_x2496;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x476 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5633 = kk_std_time_calendar__calendar_unbox(_box_x476, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5633, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2496 = _uniq_cal_5633; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2496 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2495 = kk_std_time_calendar__calendar_box(_x_x2496, _ctx); /*7*/
  _x_x2494 = kk_std_core_types__new_Optional(_x_x2495, _ctx); /*? 7*/
  _x_x2493 = kk_std_core_types__optional_box(_x_x2494, _ctx); /*10078*/
  _x_x2482 = kk_std_core_hnd__open_none3(kk_std_time_time_timezone_fs__new_mlift_time_now_10408_fun2483(_ctx), kk_std_time_instant__timescale_box(_c_x10335, _ctx), _x_x2489, _x_x2493, _ctx); /*10079*/
  return kk_std_time_time__time_unbox(_x_x2482, KK_OWNED, _ctx);
}
 
// Return the current time in an optional timezone (=`tz-utc`) and optional calendar (=`cal-iso`).


// lift anonymous function
struct kk_std_time_time_timezone_fs_time_now_fun2500__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional tz;
};
static kk_box_t kk_std_time_time_timezone_fs_time_now_fun2500(kk_function_t _fself, kk_box_t _b_x505, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_timezone_fs_new_time_now_fun2500(kk_std_core_types__optional cal, kk_std_core_types__optional tz, kk_context_t* _ctx) {
  struct kk_std_time_time_timezone_fs_time_now_fun2500__t* _self = kk_function_alloc_as(struct kk_std_time_time_timezone_fs_time_now_fun2500__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_timezone_fs_time_now_fun2500, kk_context());
  _self->cal = cal;
  _self->tz = tz;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_timezone_fs_time_now_fun2500(kk_function_t _fself, kk_box_t _b_x505, kk_context_t* _ctx) {
  struct kk_std_time_time_timezone_fs_time_now_fun2500__t* _self = kk_function_as(struct kk_std_time_time_timezone_fs_time_now_fun2500__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional tz = _self->tz; /* ? std/time/calendar/timezone */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(tz, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10335_532 = kk_std_time_instant__timescale_unbox(_b_x505, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_time__time _x_x2501 = kk_std_time_time_timezone_fs__mlift_time_now_10408(cal, tz, _c_x10335_532, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2501, _ctx);
}


// lift anonymous function
struct kk_std_time_time_timezone_fs_time_now_fun2502__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_timezone_fs_time_now_fun2502(kk_function_t _fself, kk_box_t _b_x519, kk_box_t _b_x520, kk_box_t _b_x521, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_timezone_fs_new_time_now_fun2502(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_timezone_fs_time_now_fun2502, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_timezone_fs_time_now_fun2502(kk_function_t _fself, kk_box_t _b_x519, kk_box_t _b_x520, kk_box_t _b_x521, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_instant__timescale ts_0_533 = kk_std_time_instant__timescale_unbox(_b_x519, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_core_types__optional tz_0_534 = kk_std_core_types__optional_unbox(_b_x520, KK_OWNED, _ctx); /*? std/time/calendar/timezone*/;
  kk_std_core_types__optional cal_0_535 = kk_std_core_types__optional_unbox(_b_x521, KK_OWNED, _ctx); /*? std/time/calendar/calendar*/;
  kk_std_time_calendar__timezone _b_x508_528;
  if (kk_std_core_types__is_Optional(tz_0_534, _ctx)) {
    kk_box_t _box_x507 = tz_0_534._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_5581 = kk_std_time_calendar__timezone_unbox(_box_x507, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_5581, _ctx);
    kk_std_core_types__optional_drop(tz_0_534, _ctx);
    _b_x508_528 = _uniq_tz_5581; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(tz_0_534, _ctx);
    _b_x508_528 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  kk_std_time_calendar__calendar _b_x510_529;
  if (kk_std_core_types__is_Optional(cal_0_535, _ctx)) {
    kk_box_t _box_x509 = cal_0_535._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5585 = kk_std_time_calendar__calendar_unbox(_box_x509, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5585, _ctx);
    kk_std_core_types__optional_drop(cal_0_535, _ctx);
    _b_x510_529 = _uniq_cal_5585; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal_0_535, _ctx);
    _b_x510_529 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  kk_std_time_time__time _x_x2503;
  kk_std_time_instant__timescale _b_x506_527 = ts_0_533; /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x2504;
  kk_std_core_types__optional _x_x2505 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(_b_x506_527, _ctx), _ctx); /*? 7*/
  _x_x2504 = kk_std_time_chrono_now_in(_x_x2505, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x2506 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x508_528, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2507 = kk_std_core_types__new_Optional(kk_std_time_calendar__calendar_box(_b_x510_529, _ctx), _ctx); /*? 7*/
  _x_x2503 = kk_std_time_time_instant_fs_time(_x_x2504, _x_x2506, _x_x2507, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2503, _ctx);
}

kk_std_time_time__time kk_std_time_time_timezone_fs_time_now(kk_std_core_types__optional tz, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (tz : ? std/time/calendar/timezone, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> <ndet,std/time/utc/utc> time */ 
  kk_std_time_instant__timescale x_10434;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x497 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_5641 = kk_std_time_instant__timescale_unbox(_box_x497, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_5641, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10434 = _uniq_ts_5641; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10437 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x2497;
    {
      struct kk_std_core_hnd_Ev* _con_x2498 = kk_std_core_hnd__as_Ev(ev_10437, _ctx);
      kk_box_t _box_x498 = _con_x2498->hnd;
      int32_t m = _con_x2498->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x498, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x702;
      kk_std_core_hnd__clause0 _brw_x703 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x702 = _brw_x703; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x501 = _match_x702.clause;
        _x_x2497 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x501, (_fun_unbox_x501, m, ev_10437, _ctx), _ctx); /*35*/
      }
    }
    x_10434 = kk_std_time_instant__timescale_unbox(_x_x2497, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  kk_box_t _x_x2499;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10434, (KK_I32(10)), _ctx);
    _x_x2499 = kk_std_core_hnd_yield_extend(kk_std_time_time_timezone_fs_new_time_now_fun2500(cal, tz, _ctx), _ctx); /*2419*/
  }
  else {
    kk_box_t _x_x2508;
    kk_std_core_types__optional _x_x2509;
    kk_box_t _x_x2510;
    kk_std_time_calendar__timezone _x_x2511;
    if (kk_std_core_types__is_Optional(tz, _ctx)) {
      kk_box_t _box_x511 = tz._cons._Optional.value;
      kk_std_time_calendar__timezone _uniq_tz_5629 = kk_std_time_calendar__timezone_unbox(_box_x511, KK_BORROWED, _ctx);
      kk_std_time_calendar__timezone_dup(_uniq_tz_5629, _ctx);
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x2511 = _uniq_tz_5629; /*std/time/calendar/timezone*/
    }
    else {
      kk_std_core_types__optional_drop(tz, _ctx);
      _x_x2511 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
    }
    _x_x2510 = kk_std_time_calendar__timezone_box(_x_x2511, _ctx); /*7*/
    _x_x2509 = kk_std_core_types__new_Optional(_x_x2510, _ctx); /*? 7*/
    _x_x2508 = kk_std_core_types__optional_box(_x_x2509, _ctx); /*10077*/
    kk_box_t _x_x2512;
    kk_std_core_types__optional _x_x2513;
    kk_box_t _x_x2514;
    kk_std_time_calendar__calendar _x_x2515;
    if (kk_std_core_types__is_Optional(cal, _ctx)) {
      kk_box_t _box_x513 = cal._cons._Optional.value;
      kk_std_time_calendar__calendar _uniq_cal_5633 = kk_std_time_calendar__calendar_unbox(_box_x513, KK_BORROWED, _ctx);
      kk_std_time_calendar__calendar_dup(_uniq_cal_5633, _ctx);
      kk_std_core_types__optional_drop(cal, _ctx);
      _x_x2515 = _uniq_cal_5633; /*std/time/calendar/calendar*/
    }
    else {
      kk_std_core_types__optional_drop(cal, _ctx);
      _x_x2515 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
    }
    _x_x2514 = kk_std_time_calendar__calendar_box(_x_x2515, _ctx); /*7*/
    _x_x2513 = kk_std_core_types__new_Optional(_x_x2514, _ctx); /*? 7*/
    _x_x2512 = kk_std_core_types__optional_box(_x_x2513, _ctx); /*10078*/
    _x_x2499 = kk_std_core_hnd__open_none3(kk_std_time_time_timezone_fs_new_time_now_fun2502(_ctx), kk_std_time_instant__timescale_box(x_10434, _ctx), _x_x2508, _x_x2512, _ctx); /*2419*/
  }
  return kk_std_time_time__time_unbox(_x_x2499, KK_OWNED, _ctx);
}
 
// Return the current time in the local timezone and optional calendar (=`cal-iso`).

kk_std_time_time__time kk_std_time_time_timescale_fs_local_time_now(kk_std_time_instant__timescale ts, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, cal : ? std/time/calendar/calendar) -> ndet time */ 
  kk_std_time_calendar__timezone _b_x536_537 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/;
  kk_std_time_instant__timescale _b_x538_543 = ts; /*std/time/instant/timescale*/;
  kk_std_time_instant__instant _x_x2516;
  kk_std_core_types__optional _x_x2517 = kk_std_core_types__new_Optional(kk_std_time_instant__timescale_box(_b_x538_543, _ctx), _ctx); /*? 7*/
  _x_x2516 = kk_std_time_chrono_now_in(_x_x2517, _ctx); /*std/time/instant/instant*/
  kk_std_core_types__optional _x_x2518;
  kk_box_t _x_x2519;
  kk_std_time_calendar__timezone _x_x2520;
  kk_std_core_types__optional _match_x700 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x536_537, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x700, _ctx)) {
    kk_box_t _box_x539 = _match_x700._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_5581 = kk_std_time_calendar__timezone_unbox(_box_x539, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_5581, _ctx);
    kk_std_core_types__optional_drop(_match_x700, _ctx);
    _x_x2520 = _uniq_tz_5581; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x700, _ctx);
    _x_x2520 = kk_std_time_calendar__timezone_dup(kk_std_time_calendar_tz_utc, _ctx); /*std/time/calendar/timezone*/
  }
  _x_x2519 = kk_std_time_calendar__timezone_box(_x_x2520, _ctx); /*7*/
  _x_x2518 = kk_std_core_types__new_Optional(_x_x2519, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2521;
  kk_box_t _x_x2522;
  kk_std_time_calendar__calendar _x_x2523;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x541 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5672 = kk_std_time_calendar__calendar_unbox(_box_x541, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5672, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2523 = _uniq_cal_5672; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2523 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2522 = kk_std_time_calendar__calendar_box(_x_x2523, _ctx); /*7*/
  _x_x2521 = kk_std_core_types__new_Optional(_x_x2522, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x2516, _x_x2518, _x_x2521, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the current time in the local timezone and optional calendar (=`cal-iso`).


// lift anonymous function
struct kk_std_time_time_calendar_fs_local_time_now_fun2525__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_calendar_fs_local_time_now_fun2525(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_calendar_fs_new_local_time_now_fun2525(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_calendar_fs_local_time_now_fun2525, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_calendar_fs_local_time_now_fun2525(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2526 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2526, _ctx);
}

kk_std_time_time__time kk_std_time_time_calendar_fs_local_time_now(kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (cal : ? std/time/calendar/calendar) -> <ndet,std/time/utc/utc> time */ 
  kk_std_time_calendar__timezone _b_x547_550;
  kk_box_t _x_x2524 = kk_std_core_hnd__open_none0(kk_std_time_time_calendar_fs_new_local_time_now_fun2525(_ctx), _ctx); /*9836*/
  _b_x547_550 = kk_std_time_calendar__timezone_unbox(_x_x2524, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  kk_std_core_types__optional _x_x2527 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x547_550, _ctx), _ctx); /*? 0*/
  kk_std_core_types__optional _x_x2528;
  kk_box_t _x_x2529;
  kk_std_time_calendar__calendar _x_x2530;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x548 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5705 = kk_std_time_calendar__calendar_unbox(_box_x548, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5705, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2530 = _uniq_cal_5705; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2530 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2529 = kk_std_time_calendar__calendar_box(_x_x2530, _ctx); /*7*/
  _x_x2528 = kk_std_core_types__new_Optional(_x_x2529, _ctx); /*? 7*/
  return kk_std_time_time_timezone_fs_time_now(_x_x2527, _x_x2528, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Convert a `:time` `t` to a new `:time` value in the local time zone
// in an optional calendar (=`t.calendar` by default).

kk_std_time_time__time kk_std_time_time_local_time(kk_std_time_time__time t, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (t : time, cal : ? std/time/calendar/calendar) -> ndet time */ 
  kk_std_time_calendar__timezone _b_x553_554 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/;
  kk_std_time_instant__instant _x_x2531;
  {
    struct kk_std_time_time_Time* _con_x2532 = kk_std_time_time__as_Time(t, _ctx);
    kk_std_time_date__date _pat_0_4 = _con_x2532->date;
    kk_std_time_date__clock _pat_4_4 = _con_x2532->clock;
    kk_std_time_calendar__calendar _pat_8_3 = _con_x2532->calendar;
    kk_std_time_duration__duration _pat_17_2 = _con_x2532->tzdelta;
    kk_std_time_calendar__timezone _pat_20_2 = _con_x2532->timezone;
    kk_std_time_instant__instant _x_3 = _con_x2532->instant;
    struct kk_std_time_date_Clock* _con_x2533 = kk_std_time_date__as_Clock(_pat_4_4, _ctx);
    struct kk_std_time_calendar_Calendar* _con_x2534 = kk_std_time_calendar__as_Calendar(_pat_8_3, _ctx);
    struct kk_std_time_calendar_Timezone* _con_x2535 = kk_std_time_calendar__as_Timezone(_pat_20_2, _ctx);
    kk_std_time_instant__instant_dup(_x_3, _ctx);
    _x_x2531 = _x_3; /*std/time/instant/instant*/
  }
  kk_std_core_types__optional _x_x2536;
  kk_box_t _x_x2537;
  kk_std_time_calendar__timezone _x_x2538;
  kk_std_core_types__optional _match_x699 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x553_554, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x699, _ctx)) {
    kk_box_t _box_x555 = _match_x699._cons._Optional.value;
    kk_std_time_calendar__timezone _uniq_tz_2036 = kk_std_time_calendar__timezone_unbox(_box_x555, KK_BORROWED, _ctx);
    kk_std_time_calendar__timezone_dup(_uniq_tz_2036, _ctx);
    kk_std_core_types__optional_drop(_match_x699, _ctx);
    _x_x2538 = _uniq_tz_2036; /*std/time/calendar/timezone*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x699, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2539 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0 = _con_x2539->date;
      kk_std_time_date__clock _pat_4 = _con_x2539->clock;
      kk_std_time_calendar__calendar _pat_8 = _con_x2539->calendar;
      kk_std_time_duration__duration _pat_17 = _con_x2539->tzdelta;
      kk_std_time_calendar__timezone _x = _con_x2539->timezone;
      kk_std_time_instant__instant _pat_23 = _con_x2539->instant;
      struct kk_std_time_date_Clock* _con_x2540 = kk_std_time_date__as_Clock(_pat_4, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2541 = kk_std_time_calendar__as_Calendar(_pat_8, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2542 = kk_std_time_calendar__as_Timezone(_x, _ctx);
      kk_std_time_calendar__timezone_dup(_x, _ctx);
      _x_x2538 = _x; /*std/time/calendar/timezone*/
    }
  }
  _x_x2537 = kk_std_time_calendar__timezone_box(_x_x2538, _ctx); /*7*/
  _x_x2536 = kk_std_core_types__new_Optional(_x_x2537, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2543;
  kk_box_t _x_x2544;
  kk_std_time_calendar__calendar _x_x2545;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x557 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5737 = kk_std_time_calendar__calendar_unbox(_box_x557, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5737, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2545 = _uniq_cal_5737; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2546 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_0_0 = _con_x2546->date;
      kk_std_time_date__clock _pat_4_5 = _con_x2546->clock;
      kk_std_time_calendar__calendar _x_4 = _con_x2546->calendar;
      kk_std_time_duration__duration _pat_16_3 = _con_x2546->tzdelta;
      kk_std_time_calendar__timezone _pat_19_3 = _con_x2546->timezone;
      kk_std_time_instant__instant _pat_23_3 = _con_x2546->instant;
      struct kk_std_time_date_Clock* _con_x2547 = kk_std_time_date__as_Clock(_pat_4_5, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2548 = kk_std_time_calendar__as_Calendar(_x_4, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2549 = kk_std_time_calendar__as_Timezone(_pat_19_3, _ctx);
      kk_std_time_calendar__calendar_dup(_x_4, _ctx);
      _x_x2545 = _x_4; /*std/time/calendar/calendar*/
    }
  }
  _x_x2544 = kk_std_time_calendar__calendar_box(_x_x2545, _ctx); /*7*/
  _x_x2543 = kk_std_core_types__new_Optional(_x_x2544, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2550;
  kk_box_t _x_x2551;
  kk_std_time_instant__timescale _x_x2552;
  kk_std_core_types__optional _match_x698 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x698, _ctx)) {
    kk_box_t _box_x559 = _match_x698._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_2056 = kk_std_time_instant__timescale_unbox(_box_x559, KK_BORROWED, _ctx);
    kk_datatype_ptr_dropn(t, (KK_I32(9)), _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_2056, _ctx);
    kk_std_core_types__optional_drop(_match_x698, _ctx);
    _x_x2552 = _uniq_ts_2056; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x698, _ctx);
    {
      struct kk_std_time_time_Time* _con_x2553 = kk_std_time_time__as_Time(t, _ctx);
      kk_std_time_date__date _pat_0_3 = _con_x2553->date;
      kk_std_time_date__clock _pat_4_3 = _con_x2553->clock;
      kk_std_time_calendar__calendar _pat_8_2 = _con_x2553->calendar;
      kk_std_time_duration__duration _pat_17_1 = _con_x2553->tzdelta;
      kk_std_time_calendar__timezone _pat_20_1 = _con_x2553->timezone;
      kk_std_time_instant__instant _x_2 = _con_x2553->instant;
      struct kk_std_time_date_Clock* _con_x2554 = kk_std_time_date__as_Clock(_pat_4_3, _ctx);
      struct kk_std_time_calendar_Calendar* _con_x2555 = kk_std_time_calendar__as_Calendar(_pat_8_2, _ctx);
      struct kk_std_time_calendar_Timezone* _con_x2556 = kk_std_time_calendar__as_Timezone(_pat_20_1, _ctx);
      kk_string_t _pat_19_1 = _con_x2553->tzabbrv;
      kk_integer_t _pat_5_2 = _con_x2554->hours;
      kk_integer_t _pat_6_2 = _con_x2554->minutes;
      kk_string_t _pat_9_2 = _con_x2555->name;
      kk_string_t _pat_10_1 = _con_x2555->long_name;
      kk_string_t _pat_11_1 = _con_x2555->month_prefix;
      kk_function_t _pat_12_1 = _con_x2555->show_era;
      kk_function_t _pat_13_1 = _con_x2555->instant_to_dc;
      kk_function_t _pat_14_1 = _con_x2555->dc_to_instant;
      kk_function_t _pat_15_1 = _con_x2555->days_to_date;
      kk_function_t _pat_16_1 = _con_x2555->date_to_days;
      kk_string_t _pat_21_1 = _con_x2556->name;
      kk_function_t _pat_22_1 = _con_x2556->utc_delta;
      kk_function_t _pat_23_1 = _con_x2556->utc_inverse;
      if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_8_2, _ctx)) {
          kk_string_drop(_pat_9_2, _ctx);
          kk_function_drop(_pat_16_1, _ctx);
          kk_function_drop(_pat_15_1, _ctx);
          kk_function_drop(_pat_14_1, _ctx);
          kk_function_drop(_pat_13_1, _ctx);
          kk_function_drop(_pat_12_1, _ctx);
          kk_string_drop(_pat_11_1, _ctx);
          kk_string_drop(_pat_10_1, _ctx);
          kk_datatype_ptr_free(_pat_8_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_8_2, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_4_3, _ctx)) {
          kk_integer_drop(_pat_6_2, _ctx);
          kk_integer_drop(_pat_5_2, _ctx);
          kk_datatype_ptr_free(_pat_4_3, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_4_3, _ctx);
        }
        if kk_likely(kk_datatype_ptr_is_unique(_pat_20_1, _ctx)) {
          kk_function_drop(_pat_23_1, _ctx);
          kk_function_drop(_pat_22_1, _ctx);
          kk_string_drop(_pat_21_1, _ctx);
          kk_datatype_ptr_free(_pat_20_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_pat_20_1, _ctx);
        }
        kk_string_drop(_pat_19_1, _ctx);
        kk_std_time_date__date_drop(_pat_0_3, _ctx);
        kk_datatype_ptr_free(t, _ctx);
      }
      else {
        kk_std_time_instant__instant_dup(_x_2, _ctx);
        kk_datatype_ptr_decref(t, _ctx);
      }
      {
        kk_std_time_timestamp__timestamp _pat_0_2 = _x_2.since;
        kk_std_time_instant__timescale _x_1 = _x_2.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x2557 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
        struct kk_std_time_instant_Timescale* _con_x2558 = kk_std_time_instant__as_Timescale(_x_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_1, _ctx);
        kk_std_time_instant__instant_drop(_x_2, _ctx);
        _x_x2552 = _x_1; /*std/time/instant/timescale*/
      }
    }
  }
  _x_x2551 = kk_std_time_instant__timescale_box(_x_x2552, _ctx); /*7*/
  _x_x2550 = kk_std_core_types__new_Optional(_x_x2551, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(_x_x2531, _x_x2536, _x_x2543, _x_x2550, _ctx);
}
 
// Convert an `:instant` to a `:time` value in the local timezone, in an optional calendar (=`cal-iso` by default).

kk_std_time_time__time kk_std_time_time_instant_fs_local_time(kk_std_time_instant__instant i, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (i : std/time/instant/instant, cal : ? std/time/calendar/calendar) -> ndet time */ 
  kk_std_time_calendar__timezone _b_x564_567 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/;
  kk_std_core_types__optional _x_x2559 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x564_567, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2560;
  kk_box_t _x_x2561;
  kk_std_time_calendar__calendar _x_x2562;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x565 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5773 = kk_std_time_calendar__calendar_unbox(_box_x565, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5773, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2562 = _uniq_cal_5773; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2562 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2561 = kk_std_time_calendar__calendar_box(_x_x2562, _ctx); /*7*/
  _x_x2560 = kk_std_core_types__new_Optional(_x_x2561, _ctx); /*? 7*/
  return kk_std_time_time_instant_fs_time(i, _x_x2559, _x_x2560, kk_std_core_types__new_None(_ctx), _ctx);
}
 
// Return the `:time` value for a given date and clock in the local timezone
// interpreted by calendar `cal` (=`cal-iso`). See `instant` for roll-over behavior.

kk_std_time_time__time kk_std_time_time_timescale_fs_local_time(kk_std_time_instant__timescale ts, kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, cal : ? std/time/calendar/calendar) -> ndet time */ 
  kk_std_time_calendar__timezone _b_x581_590 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/;
  kk_std_core_types__optional _x_x2563;
  kk_box_t _x_x2564;
  kk_integer_t _x_x2565;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x569 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_5809 = kk_integer_unbox(_box_x569, _ctx);
    kk_integer_dup(_uniq_month_5809, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x2565 = _uniq_month_5809; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x2565 = kk_integer_from_small(1); /*int*/
  }
  _x_x2564 = kk_integer_box(_x_x2565, _ctx); /*7*/
  _x_x2563 = kk_std_core_types__new_Optional(_x_x2564, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2566;
  kk_box_t _x_x2567;
  kk_integer_t _x_x2568;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x571 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_5813 = kk_integer_unbox(_box_x571, _ctx);
    kk_integer_dup(_uniq_day_5813, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2568 = _uniq_day_5813; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2568 = kk_integer_from_small(1); /*int*/
  }
  _x_x2567 = kk_integer_box(_x_x2568, _ctx); /*7*/
  _x_x2566 = kk_std_core_types__new_Optional(_x_x2567, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2569;
  kk_box_t _x_x2570;
  kk_integer_t _x_x2571;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x573 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_5817 = kk_integer_unbox(_box_x573, _ctx);
    kk_integer_dup(_uniq_hours_5817, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2571 = _uniq_hours_5817; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2571 = kk_integer_from_small(0); /*int*/
  }
  _x_x2570 = kk_integer_box(_x_x2571, _ctx); /*7*/
  _x_x2569 = kk_std_core_types__new_Optional(_x_x2570, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2572;
  kk_box_t _x_x2573;
  kk_integer_t _x_x2574;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x575 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_5821 = kk_integer_unbox(_box_x575, _ctx);
    kk_integer_dup(_uniq_minutes_5821, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2574 = _uniq_minutes_5821; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2574 = kk_integer_from_small(0); /*int*/
  }
  _x_x2573 = kk_integer_box(_x_x2574, _ctx); /*7*/
  _x_x2572 = kk_std_core_types__new_Optional(_x_x2573, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2575;
  kk_box_t _x_x2576;
  kk_integer_t _x_x2577;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x577 = secs._cons._Optional.value;
    kk_integer_t _uniq_secs_5825 = kk_integer_unbox(_box_x577, _ctx);
    kk_integer_dup(_uniq_secs_5825, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x2577 = _uniq_secs_5825; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x2577 = kk_integer_from_small(0); /*int*/
  }
  _x_x2576 = kk_integer_box(_x_x2577, _ctx); /*7*/
  _x_x2575 = kk_std_core_types__new_Optional(_x_x2576, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2578;
  kk_box_t _x_x2579;
  double _x_x2580;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x579 = frac._cons._Optional.value;
    double _uniq_frac_5829 = kk_double_unbox(_box_x579, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x2580 = _uniq_frac_5829; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x2580 = 0x0p+0; /*float64*/
  }
  _x_x2579 = kk_double_box(_x_x2580, _ctx); /*7*/
  _x_x2578 = kk_std_core_types__new_Optional(_x_x2579, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2581 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x581_590, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2582;
  kk_box_t _x_x2583;
  kk_std_time_calendar__calendar _x_x2584;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x582 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5833 = kk_std_time_calendar__calendar_unbox(_box_x582, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5833, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2584 = _uniq_cal_5833; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2584 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2583 = kk_std_time_calendar__calendar_box(_x_x2584, _ctx); /*7*/
  _x_x2582 = kk_std_core_types__new_Optional(_x_x2583, _ctx); /*? 7*/
  return kk_std_time_time_timescale_fs_time(ts, year_0, _x_x2563, _x_x2566, _x_x2569, _x_x2572, _x_x2575, _x_x2578, _x_x2581, _x_x2582, _ctx);
}
 
// Return the `:time` value for a given `:date` and `:clock` (=`clock0`) in the local timezone
// interpreted by calendar `cal` (=`cal-iso`)

kk_std_time_time__time kk_std_time_time_date_fs_local_time(kk_std_time_instant__timescale ts, kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_context_t* _ctx) { /* (ts : std/time/instant/timescale, d : std/time/date/date, c : ? std/time/date/clock, cal : ? std/time/calendar/calendar) -> ndet time */ 
  kk_std_time_calendar__timezone _b_x594_598 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/;
  kk_std_core_types__optional _x_x2585;
  kk_box_t _x_x2586;
  kk_std_time_date__clock _x_x2587;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x592 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_5922 = kk_std_time_date__clock_unbox(_box_x592, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_5922, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2587 = _uniq_c_5922; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2587 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x2586 = kk_std_time_date__clock_box(_x_x2587, _ctx); /*7*/
  _x_x2585 = kk_std_core_types__new_Optional(_x_x2586, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2588 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x594_598, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2589;
  kk_box_t _x_x2590;
  kk_std_time_calendar__calendar _x_x2591;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x595 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5926 = kk_std_time_calendar__calendar_unbox(_box_x595, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5926, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2591 = _uniq_cal_5926; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2591 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2590 = kk_std_time_calendar__calendar_box(_x_x2591, _ctx); /*7*/
  _x_x2589 = kk_std_core_types__new_Optional(_x_x2590, _ctx); /*? 7*/
  return kk_std_time_time_timescale_fs_date_fs_time(ts, d, _x_x2585, _x_x2588, _x_x2589, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2593__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2593(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_dateutc_fs__new_mlift_local_time_10409_fun2593(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2593, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2593(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2594 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2594, _ctx);
}


// lift anonymous function
struct kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596__t {
  struct kk_function_s _base;
  kk_std_time_calendar__timezone _b_x601_602;
  kk_std_time_instant__timescale _c_x10338;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
};
static kk_box_t kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_dateutc_fs__new_mlift_local_time_10409_fun2596(kk_std_time_calendar__timezone _b_x601_602, kk_std_time_instant__timescale _c_x10338, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_context_t* _ctx) {
  struct kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596__t* _self = kk_function_alloc_as(struct kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596, kk_context());
  _self->_b_x601_602 = _b_x601_602;
  _self->_c_x10338 = _c_x10338;
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596__t* _self = kk_function_as(struct kk_std_time_time_dateutc_fs__mlift_local_time_10409_fun2596__t*, _fself, _ctx);
  kk_std_time_calendar__timezone _b_x601_602 = _self->_b_x601_602; /* std/time/calendar/timezone */
  kk_std_time_instant__timescale _c_x10338 = _self->_c_x10338; /* std/time/instant/timescale */
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_time_calendar__timezone_dup(_b_x601_602, _ctx);kk_std_time_instant__timescale_dup(_c_x10338, _ctx);kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2597;
  kk_std_core_types__optional _x_x2598;
  kk_box_t _x_x2599;
  kk_std_time_date__clock _x_x2600;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x604 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_5973 = kk_std_time_date__clock_unbox(_box_x604, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_5973, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2600 = _uniq_c_5973; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2600 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x2599 = kk_std_time_date__clock_box(_x_x2600, _ctx); /*7*/
  _x_x2598 = kk_std_core_types__new_Optional(_x_x2599, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2601 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x601_602, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2602;
  kk_box_t _x_x2603;
  kk_std_time_calendar__calendar _x_x2604;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x606 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5977 = kk_std_time_calendar__calendar_unbox(_box_x606, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5977, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2604 = _uniq_cal_5977; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2604 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2603 = kk_std_time_calendar__calendar_box(_x_x2604, _ctx); /*7*/
  _x_x2602 = kk_std_core_types__new_Optional(_x_x2603, _ctx); /*? 7*/
  _x_x2597 = kk_std_time_time_timescale_fs_date_fs_time(_c_x10338, d, _x_x2598, _x_x2601, _x_x2602, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2597, _ctx);
}

kk_std_time_time__time kk_std_time_time_dateutc_fs__mlift_local_time_10409(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_time_instant__timescale _c_x10338, kk_context_t* _ctx) { /* (c : ? std/time/date/clock, cal : ? std/time/calendar/calendar, d : std/time/date/date, std/time/instant/timescale) -> time */ 
  kk_std_time_calendar__timezone _b_x601_602;
  kk_box_t _x_x2592 = kk_std_core_hnd__open_none0(kk_std_time_time_dateutc_fs__new_mlift_local_time_10409_fun2593(_ctx), _ctx); /*9836*/
  _b_x601_602 = kk_std_time_calendar__timezone_unbox(_x_x2592, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
  kk_box_t _x_x2595 = kk_std_core_hnd__open_none0(kk_std_time_time_dateutc_fs__new_mlift_local_time_10409_fun2596(_b_x601_602, _c_x10338, c, cal, d, _ctx), _ctx); /*9836*/
  return kk_std_time_time__time_unbox(_x_x2595, KK_OWNED, _ctx);
}
 
// Return the `:time` value for a given `:date` and `:clock` (=`clock0`) in the local timezone
// interpreted by calendar `cal` (=`cal-iso`)


// lift anonymous function
struct kk_std_time_time_dateutc_fs_local_time_fun2608__t {
  struct kk_function_s _base;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
};
static kk_box_t kk_std_time_time_dateutc_fs_local_time_fun2608(kk_function_t _fself, kk_box_t _b_x620, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_dateutc_fs_new_local_time_fun2608(kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_context_t* _ctx) {
  struct kk_std_time_time_dateutc_fs_local_time_fun2608__t* _self = kk_function_alloc_as(struct kk_std_time_time_dateutc_fs_local_time_fun2608__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_dateutc_fs_local_time_fun2608, kk_context());
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_dateutc_fs_local_time_fun2608(kk_function_t _fself, kk_box_t _b_x620, kk_context_t* _ctx) {
  struct kk_std_time_time_dateutc_fs_local_time_fun2608__t* _self = kk_function_as(struct kk_std_time_time_dateutc_fs_local_time_fun2608__t*, _fself, _ctx);
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10338_634 = kk_std_time_instant__timescale_unbox(_b_x620, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_time__time _x_x2609 = kk_std_time_time_dateutc_fs__mlift_local_time_10409(c, cal, d, _c_x10338_634, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2609, _ctx);
}


// lift anonymous function
struct kk_std_time_time_dateutc_fs_local_time_fun2611__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_time_time_dateutc_fs_local_time_fun2611(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_dateutc_fs_new_local_time_fun2611(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_time_time_dateutc_fs_local_time_fun2611, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_time_time_dateutc_fs_local_time_fun2611(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_time_calendar__timezone _x_x2612 = kk_std_time_calendar_tz_local(_ctx); /*std/time/calendar/timezone*/
  return kk_std_time_calendar__timezone_box(_x_x2612, _ctx);
}


// lift anonymous function
struct kk_std_time_time_dateutc_fs_local_time_fun2614__t {
  struct kk_function_s _base;
  kk_std_time_calendar__timezone _b_x622_623;
  kk_std_core_types__optional c;
  kk_std_core_types__optional cal;
  kk_std_time_date__date d;
  kk_std_time_instant__timescale x_10439;
};
static kk_box_t kk_std_time_time_dateutc_fs_local_time_fun2614(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_dateutc_fs_new_local_time_fun2614(kk_std_time_calendar__timezone _b_x622_623, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_time_date__date d, kk_std_time_instant__timescale x_10439, kk_context_t* _ctx) {
  struct kk_std_time_time_dateutc_fs_local_time_fun2614__t* _self = kk_function_alloc_as(struct kk_std_time_time_dateutc_fs_local_time_fun2614__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_dateutc_fs_local_time_fun2614, kk_context());
  _self->_b_x622_623 = _b_x622_623;
  _self->c = c;
  _self->cal = cal;
  _self->d = d;
  _self->x_10439 = x_10439;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_dateutc_fs_local_time_fun2614(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_dateutc_fs_local_time_fun2614__t* _self = kk_function_as(struct kk_std_time_time_dateutc_fs_local_time_fun2614__t*, _fself, _ctx);
  kk_std_time_calendar__timezone _b_x622_623 = _self->_b_x622_623; /* std/time/calendar/timezone */
  kk_std_core_types__optional c = _self->c; /* ? std/time/date/clock */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_time_date__date d = _self->d; /* std/time/date/date */
  kk_std_time_instant__timescale x_10439 = _self->x_10439; /* std/time/instant/timescale */
  kk_drop_match(_self, {kk_std_time_calendar__timezone_dup(_b_x622_623, _ctx);kk_std_core_types__optional_dup(c, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_time_date__date_dup(d, _ctx);kk_std_time_instant__timescale_dup(x_10439, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2615;
  kk_std_core_types__optional _x_x2616;
  kk_box_t _x_x2617;
  kk_std_time_date__clock _x_x2618;
  if (kk_std_core_types__is_Optional(c, _ctx)) {
    kk_box_t _box_x625 = c._cons._Optional.value;
    kk_std_time_date__clock _uniq_c_5973 = kk_std_time_date__clock_unbox(_box_x625, KK_BORROWED, _ctx);
    kk_std_time_date__clock_dup(_uniq_c_5973, _ctx);
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2618 = _uniq_c_5973; /*std/time/date/clock*/
  }
  else {
    kk_std_core_types__optional_drop(c, _ctx);
    _x_x2618 = kk_std_time_date__clock_dup(kk_std_time_date_clock0, _ctx); /*std/time/date/clock*/
  }
  _x_x2617 = kk_std_time_date__clock_box(_x_x2618, _ctx); /*7*/
  _x_x2616 = kk_std_core_types__new_Optional(_x_x2617, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2619 = kk_std_core_types__new_Optional(kk_std_time_calendar__timezone_box(_b_x622_623, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2620;
  kk_box_t _x_x2621;
  kk_std_time_calendar__calendar _x_x2622;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x627 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_5977 = kk_std_time_calendar__calendar_unbox(_box_x627, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_5977, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2622 = _uniq_cal_5977; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2622 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2621 = kk_std_time_calendar__calendar_box(_x_x2622, _ctx); /*7*/
  _x_x2620 = kk_std_core_types__new_Optional(_x_x2621, _ctx); /*? 7*/
  _x_x2615 = kk_std_time_time_timescale_fs_date_fs_time(x_10439, d, _x_x2616, _x_x2619, _x_x2620, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2615, _ctx);
}

kk_std_time_time__time kk_std_time_time_dateutc_fs_local_time(kk_std_time_date__date d, kk_std_core_types__optional c, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (d : std/time/date/date, c : ? std/time/date/clock, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> <ndet,std/time/utc/utc> time */ 
  kk_std_time_instant__timescale x_10439;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x612 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_5985 = kk_std_time_instant__timescale_unbox(_box_x612, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_5985, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10439 = _uniq_ts_5985; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10442 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x2605;
    {
      struct kk_std_core_hnd_Ev* _con_x2606 = kk_std_core_hnd__as_Ev(ev_10442, _ctx);
      kk_box_t _box_x613 = _con_x2606->hnd;
      int32_t m = _con_x2606->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x613, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x696;
      kk_std_core_hnd__clause0 _brw_x697 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x696 = _brw_x697; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x616 = _match_x696.clause;
        _x_x2605 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x616, (_fun_unbox_x616, m, ev_10442, _ctx), _ctx); /*35*/
      }
    }
    x_10439 = kk_std_time_instant__timescale_unbox(_x_x2605, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10439, (KK_I32(10)), _ctx);
    kk_box_t _x_x2607 = kk_std_core_hnd_yield_extend(kk_std_time_time_dateutc_fs_new_local_time_fun2608(c, cal, d, _ctx), _ctx); /*2419*/
    return kk_std_time_time__time_unbox(_x_x2607, KK_OWNED, _ctx);
  }
  {
    kk_std_time_calendar__timezone _b_x622_623;
    kk_box_t _x_x2610 = kk_std_core_hnd__open_none0(kk_std_time_time_dateutc_fs_new_local_time_fun2611(_ctx), _ctx); /*9836*/
    _b_x622_623 = kk_std_time_calendar__timezone_unbox(_x_x2610, KK_OWNED, _ctx); /*std/time/calendar/timezone*/
    kk_box_t _x_x2613 = kk_std_core_hnd__open_none0(kk_std_time_time_dateutc_fs_new_local_time_fun2614(_b_x622_623, c, cal, d, x_10439, _ctx), _ctx); /*9836*/
    return kk_std_time_time__time_unbox(_x_x2613, KK_OWNED, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_time_time_year_fs__mlift_local_time_10410_fun2624__t {
  struct kk_function_s _base;
  kk_std_time_instant__timescale _c_x10340;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day_0;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours_0;
  kk_std_core_types__optional minutes_0;
  kk_std_core_types__optional month_0;
  kk_std_core_types__optional secs;
  kk_integer_t year_0;
};
static kk_box_t kk_std_time_time_year_fs__mlift_local_time_10410_fun2624(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_year_fs__new_mlift_local_time_10410_fun2624(kk_std_time_instant__timescale _c_x10340, kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_integer_t year_0, kk_context_t* _ctx) {
  struct kk_std_time_time_year_fs__mlift_local_time_10410_fun2624__t* _self = kk_function_alloc_as(struct kk_std_time_time_year_fs__mlift_local_time_10410_fun2624__t, 17, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_year_fs__mlift_local_time_10410_fun2624, kk_context());
  _self->_c_x10340 = _c_x10340;
  _self->cal = cal;
  _self->day_0 = day_0;
  _self->frac = frac;
  _self->hours_0 = hours_0;
  _self->minutes_0 = minutes_0;
  _self->month_0 = month_0;
  _self->secs = secs;
  _self->year_0 = year_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_year_fs__mlift_local_time_10410_fun2624(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_year_fs__mlift_local_time_10410_fun2624__t* _self = kk_function_as(struct kk_std_time_time_year_fs__mlift_local_time_10410_fun2624__t*, _fself, _ctx);
  kk_std_time_instant__timescale _c_x10340 = _self->_c_x10340; /* std/time/instant/timescale */
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day_0 = _self->day_0; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours_0 = _self->hours_0; /* ? int */
  kk_std_core_types__optional minutes_0 = _self->minutes_0; /* ? int */
  kk_std_core_types__optional month_0 = _self->month_0; /* ? int */
  kk_std_core_types__optional secs = _self->secs; /* ? int */
  kk_integer_t year_0 = _self->year_0; /* int */
  kk_drop_match(_self, {kk_std_time_instant__timescale_dup(_c_x10340, _ctx);kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day_0, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours_0, _ctx);kk_std_core_types__optional_dup(minutes_0, _ctx);kk_std_core_types__optional_dup(month_0, _ctx);kk_std_core_types__optional_dup(secs, _ctx);kk_integer_dup(year_0, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2625;
  kk_std_core_types__optional _x_x2626;
  kk_box_t _x_x2627;
  kk_integer_t _x_x2628;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x635 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_6033 = kk_integer_unbox(_box_x635, _ctx);
    kk_integer_dup(_uniq_month_6033, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x2628 = _uniq_month_6033; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x2628 = kk_integer_from_small(1); /*int*/
  }
  _x_x2627 = kk_integer_box(_x_x2628, _ctx); /*7*/
  _x_x2626 = kk_std_core_types__new_Optional(_x_x2627, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2629;
  kk_box_t _x_x2630;
  kk_integer_t _x_x2631;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x637 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_6037 = kk_integer_unbox(_box_x637, _ctx);
    kk_integer_dup(_uniq_day_6037, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2631 = _uniq_day_6037; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2631 = kk_integer_from_small(1); /*int*/
  }
  _x_x2630 = kk_integer_box(_x_x2631, _ctx); /*7*/
  _x_x2629 = kk_std_core_types__new_Optional(_x_x2630, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2632;
  kk_box_t _x_x2633;
  kk_integer_t _x_x2634;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x639 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_6041 = kk_integer_unbox(_box_x639, _ctx);
    kk_integer_dup(_uniq_hours_6041, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2634 = _uniq_hours_6041; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2634 = kk_integer_from_small(0); /*int*/
  }
  _x_x2633 = kk_integer_box(_x_x2634, _ctx); /*7*/
  _x_x2632 = kk_std_core_types__new_Optional(_x_x2633, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2635;
  kk_box_t _x_x2636;
  kk_integer_t _x_x2637;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x641 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_6045 = kk_integer_unbox(_box_x641, _ctx);
    kk_integer_dup(_uniq_minutes_6045, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2637 = _uniq_minutes_6045; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2637 = kk_integer_from_small(0); /*int*/
  }
  _x_x2636 = kk_integer_box(_x_x2637, _ctx); /*7*/
  _x_x2635 = kk_std_core_types__new_Optional(_x_x2636, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2638;
  kk_box_t _x_x2639;
  kk_integer_t _x_x2640;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x643 = secs._cons._Optional.value;
    kk_integer_t _uniq_secs_6049 = kk_integer_unbox(_box_x643, _ctx);
    kk_integer_dup(_uniq_secs_6049, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x2640 = _uniq_secs_6049; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x2640 = kk_integer_from_small(0); /*int*/
  }
  _x_x2639 = kk_integer_box(_x_x2640, _ctx); /*7*/
  _x_x2638 = kk_std_core_types__new_Optional(_x_x2639, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2641;
  kk_box_t _x_x2642;
  double _x_x2643;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x645 = frac._cons._Optional.value;
    double _uniq_frac_6053 = kk_double_unbox(_box_x645, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x2643 = _uniq_frac_6053; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x2643 = 0x0p+0; /*float64*/
  }
  _x_x2642 = kk_double_box(_x_x2643, _ctx); /*7*/
  _x_x2641 = kk_std_core_types__new_Optional(_x_x2642, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2644;
  kk_box_t _x_x2645;
  kk_std_time_calendar__calendar _x_x2646;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x647 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_6057 = kk_std_time_calendar__calendar_unbox(_box_x647, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_6057, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2646 = _uniq_cal_6057; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2646 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2645 = kk_std_time_calendar__calendar_box(_x_x2646, _ctx); /*7*/
  _x_x2644 = kk_std_core_types__new_Optional(_x_x2645, _ctx); /*? 7*/
  _x_x2625 = kk_std_time_time_timescale_fs_local_time(_c_x10340, year_0, _x_x2626, _x_x2629, _x_x2632, _x_x2635, _x_x2638, _x_x2641, _x_x2644, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2625, _ctx);
}

kk_std_time_time__time kk_std_time_time_year_fs__mlift_local_time_10410(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_integer_t year_0, kk_std_time_instant__timescale _c_x10340, kk_context_t* _ctx) { /* (cal : ? std/time/calendar/calendar, day@0 : ? int, frac : ? float64, hours@0 : ? int, minutes@0 : ? int, month@0 : ? int, secs : ? int, year@0 : int, std/time/instant/timescale) -> time */ 
  kk_box_t _x_x2623 = kk_std_core_hnd__open_none0(kk_std_time_time_year_fs__new_mlift_local_time_10410_fun2624(_c_x10340, cal, day_0, frac, hours_0, minutes_0, month_0, secs, year_0, _ctx), _ctx); /*9836*/
  return kk_std_time_time__time_unbox(_x_x2623, KK_OWNED, _ctx);
}
 
// Return the `:time` value for a given date and clock in the local timezone
// interpreted by calendar `cal` (=`cal-iso`). See `instant` for roll-over behavior.


// lift anonymous function
struct kk_std_time_time_year_fs_local_time_fun2650__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day_0;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours_0;
  kk_std_core_types__optional minutes_0;
  kk_std_core_types__optional month_0;
  kk_std_core_types__optional secs;
  kk_integer_t year_0;
};
static kk_box_t kk_std_time_time_year_fs_local_time_fun2650(kk_function_t _fself, kk_box_t _b_x666, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_year_fs_new_local_time_fun2650(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_integer_t year_0, kk_context_t* _ctx) {
  struct kk_std_time_time_year_fs_local_time_fun2650__t* _self = kk_function_alloc_as(struct kk_std_time_time_year_fs_local_time_fun2650__t, 16, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_year_fs_local_time_fun2650, kk_context());
  _self->cal = cal;
  _self->day_0 = day_0;
  _self->frac = frac;
  _self->hours_0 = hours_0;
  _self->minutes_0 = minutes_0;
  _self->month_0 = month_0;
  _self->secs = secs;
  _self->year_0 = year_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_year_fs_local_time_fun2650(kk_function_t _fself, kk_box_t _b_x666, kk_context_t* _ctx) {
  struct kk_std_time_time_year_fs_local_time_fun2650__t* _self = kk_function_as(struct kk_std_time_time_year_fs_local_time_fun2650__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day_0 = _self->day_0; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours_0 = _self->hours_0; /* ? int */
  kk_std_core_types__optional minutes_0 = _self->minutes_0; /* ? int */
  kk_std_core_types__optional month_0 = _self->month_0; /* ? int */
  kk_std_core_types__optional secs = _self->secs; /* ? int */
  kk_integer_t year_0 = _self->year_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day_0, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours_0, _ctx);kk_std_core_types__optional_dup(minutes_0, _ctx);kk_std_core_types__optional_dup(month_0, _ctx);kk_std_core_types__optional_dup(secs, _ctx);kk_integer_dup(year_0, _ctx);}, {}, _ctx)
  kk_std_time_instant__timescale _c_x10340_691 = kk_std_time_instant__timescale_unbox(_b_x666, KK_OWNED, _ctx); /*std/time/instant/timescale*/;
  kk_std_time_time__time _x_x2651 = kk_std_time_time_year_fs__mlift_local_time_10410(cal, day_0, frac, hours_0, minutes_0, month_0, secs, year_0, _c_x10340_691, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2651, _ctx);
}


// lift anonymous function
struct kk_std_time_time_year_fs_local_time_fun2652__t {
  struct kk_function_s _base;
  kk_std_core_types__optional cal;
  kk_std_core_types__optional day_0;
  kk_std_core_types__optional frac;
  kk_std_core_types__optional hours_0;
  kk_std_core_types__optional minutes_0;
  kk_std_core_types__optional month_0;
  kk_std_core_types__optional secs;
  kk_std_time_instant__timescale x_10444;
  kk_integer_t year_0;
};
static kk_box_t kk_std_time_time_year_fs_local_time_fun2652(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_time_time_year_fs_new_local_time_fun2652(kk_std_core_types__optional cal, kk_std_core_types__optional day_0, kk_std_core_types__optional frac, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional month_0, kk_std_core_types__optional secs, kk_std_time_instant__timescale x_10444, kk_integer_t year_0, kk_context_t* _ctx) {
  struct kk_std_time_time_year_fs_local_time_fun2652__t* _self = kk_function_alloc_as(struct kk_std_time_time_year_fs_local_time_fun2652__t, 17, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_time_year_fs_local_time_fun2652, kk_context());
  _self->cal = cal;
  _self->day_0 = day_0;
  _self->frac = frac;
  _self->hours_0 = hours_0;
  _self->minutes_0 = minutes_0;
  _self->month_0 = month_0;
  _self->secs = secs;
  _self->x_10444 = x_10444;
  _self->year_0 = year_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_time_time_year_fs_local_time_fun2652(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_time_time_year_fs_local_time_fun2652__t* _self = kk_function_as(struct kk_std_time_time_year_fs_local_time_fun2652__t*, _fself, _ctx);
  kk_std_core_types__optional cal = _self->cal; /* ? std/time/calendar/calendar */
  kk_std_core_types__optional day_0 = _self->day_0; /* ? int */
  kk_std_core_types__optional frac = _self->frac; /* ? float64 */
  kk_std_core_types__optional hours_0 = _self->hours_0; /* ? int */
  kk_std_core_types__optional minutes_0 = _self->minutes_0; /* ? int */
  kk_std_core_types__optional month_0 = _self->month_0; /* ? int */
  kk_std_core_types__optional secs = _self->secs; /* ? int */
  kk_std_time_instant__timescale x_10444 = _self->x_10444; /* std/time/instant/timescale */
  kk_integer_t year_0 = _self->year_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(cal, _ctx);kk_std_core_types__optional_dup(day_0, _ctx);kk_std_core_types__optional_dup(frac, _ctx);kk_std_core_types__optional_dup(hours_0, _ctx);kk_std_core_types__optional_dup(minutes_0, _ctx);kk_std_core_types__optional_dup(month_0, _ctx);kk_std_core_types__optional_dup(secs, _ctx);kk_std_time_instant__timescale_dup(x_10444, _ctx);kk_integer_dup(year_0, _ctx);}, {}, _ctx)
  kk_std_time_time__time _x_x2653;
  kk_std_core_types__optional _x_x2654;
  kk_box_t _x_x2655;
  kk_integer_t _x_x2656;
  if (kk_std_core_types__is_Optional(month_0, _ctx)) {
    kk_box_t _box_x667 = month_0._cons._Optional.value;
    kk_integer_t _uniq_month_6033 = kk_integer_unbox(_box_x667, _ctx);
    kk_integer_dup(_uniq_month_6033, _ctx);
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x2656 = _uniq_month_6033; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(month_0, _ctx);
    _x_x2656 = kk_integer_from_small(1); /*int*/
  }
  _x_x2655 = kk_integer_box(_x_x2656, _ctx); /*7*/
  _x_x2654 = kk_std_core_types__new_Optional(_x_x2655, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2657;
  kk_box_t _x_x2658;
  kk_integer_t _x_x2659;
  if (kk_std_core_types__is_Optional(day_0, _ctx)) {
    kk_box_t _box_x669 = day_0._cons._Optional.value;
    kk_integer_t _uniq_day_6037 = kk_integer_unbox(_box_x669, _ctx);
    kk_integer_dup(_uniq_day_6037, _ctx);
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2659 = _uniq_day_6037; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(day_0, _ctx);
    _x_x2659 = kk_integer_from_small(1); /*int*/
  }
  _x_x2658 = kk_integer_box(_x_x2659, _ctx); /*7*/
  _x_x2657 = kk_std_core_types__new_Optional(_x_x2658, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2660;
  kk_box_t _x_x2661;
  kk_integer_t _x_x2662;
  if (kk_std_core_types__is_Optional(hours_0, _ctx)) {
    kk_box_t _box_x671 = hours_0._cons._Optional.value;
    kk_integer_t _uniq_hours_6041 = kk_integer_unbox(_box_x671, _ctx);
    kk_integer_dup(_uniq_hours_6041, _ctx);
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2662 = _uniq_hours_6041; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(hours_0, _ctx);
    _x_x2662 = kk_integer_from_small(0); /*int*/
  }
  _x_x2661 = kk_integer_box(_x_x2662, _ctx); /*7*/
  _x_x2660 = kk_std_core_types__new_Optional(_x_x2661, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2663;
  kk_box_t _x_x2664;
  kk_integer_t _x_x2665;
  if (kk_std_core_types__is_Optional(minutes_0, _ctx)) {
    kk_box_t _box_x673 = minutes_0._cons._Optional.value;
    kk_integer_t _uniq_minutes_6045 = kk_integer_unbox(_box_x673, _ctx);
    kk_integer_dup(_uniq_minutes_6045, _ctx);
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2665 = _uniq_minutes_6045; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(minutes_0, _ctx);
    _x_x2665 = kk_integer_from_small(0); /*int*/
  }
  _x_x2664 = kk_integer_box(_x_x2665, _ctx); /*7*/
  _x_x2663 = kk_std_core_types__new_Optional(_x_x2664, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2666;
  kk_box_t _x_x2667;
  kk_integer_t _x_x2668;
  if (kk_std_core_types__is_Optional(secs, _ctx)) {
    kk_box_t _box_x675 = secs._cons._Optional.value;
    kk_integer_t _uniq_secs_6049 = kk_integer_unbox(_box_x675, _ctx);
    kk_integer_dup(_uniq_secs_6049, _ctx);
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x2668 = _uniq_secs_6049; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs, _ctx);
    _x_x2668 = kk_integer_from_small(0); /*int*/
  }
  _x_x2667 = kk_integer_box(_x_x2668, _ctx); /*7*/
  _x_x2666 = kk_std_core_types__new_Optional(_x_x2667, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2669;
  kk_box_t _x_x2670;
  double _x_x2671;
  if (kk_std_core_types__is_Optional(frac, _ctx)) {
    kk_box_t _box_x677 = frac._cons._Optional.value;
    double _uniq_frac_6053 = kk_double_unbox(_box_x677, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x2671 = _uniq_frac_6053; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(frac, _ctx);
    _x_x2671 = 0x0p+0; /*float64*/
  }
  _x_x2670 = kk_double_box(_x_x2671, _ctx); /*7*/
  _x_x2669 = kk_std_core_types__new_Optional(_x_x2670, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x2672;
  kk_box_t _x_x2673;
  kk_std_time_calendar__calendar _x_x2674;
  if (kk_std_core_types__is_Optional(cal, _ctx)) {
    kk_box_t _box_x679 = cal._cons._Optional.value;
    kk_std_time_calendar__calendar _uniq_cal_6057 = kk_std_time_calendar__calendar_unbox(_box_x679, KK_BORROWED, _ctx);
    kk_std_time_calendar__calendar_dup(_uniq_cal_6057, _ctx);
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2674 = _uniq_cal_6057; /*std/time/calendar/calendar*/
  }
  else {
    kk_std_core_types__optional_drop(cal, _ctx);
    _x_x2674 = kk_std_time_calendar__calendar_dup(kk_std_time_calendar_cal_iso, _ctx); /*std/time/calendar/calendar*/
  }
  _x_x2673 = kk_std_time_calendar__calendar_box(_x_x2674, _ctx); /*7*/
  _x_x2672 = kk_std_core_types__new_Optional(_x_x2673, _ctx); /*? 7*/
  _x_x2653 = kk_std_time_time_timescale_fs_local_time(x_10444, year_0, _x_x2654, _x_x2657, _x_x2660, _x_x2663, _x_x2666, _x_x2669, _x_x2672, _ctx); /*std/time/time/time*/
  return kk_std_time_time__time_box(_x_x2653, _ctx);
}

kk_std_time_time__time kk_std_time_time_year_fs_local_time(kk_integer_t year_0, kk_std_core_types__optional month_0, kk_std_core_types__optional day_0, kk_std_core_types__optional hours_0, kk_std_core_types__optional minutes_0, kk_std_core_types__optional secs, kk_std_core_types__optional frac, kk_std_core_types__optional cal, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (year : int, month : ? int, day : ? int, hours : ? int, minutes : ? int, secs : ? int, frac : ? float64, cal : ? std/time/calendar/calendar, ts : ? std/time/instant/timescale) -> <ndet,std/time/utc/utc> time */ 
  kk_std_time_instant__timescale x_10444;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x658 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_6065 = kk_std_time_instant__timescale_unbox(_box_x658, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_6065, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    x_10444 = _uniq_ts_6065; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_core_hnd__ev ev_10447 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/time/utc/utc>*/;
    kk_box_t _x_x2647;
    {
      struct kk_std_core_hnd_Ev* _con_x2648 = kk_std_core_hnd__as_Ev(ev_10447, _ctx);
      kk_box_t _box_x659 = _con_x2648->hnd;
      int32_t m = _con_x2648->marker;
      kk_std_time_utc__utc h = kk_std_time_utc__utc_unbox(_box_x659, KK_BORROWED, _ctx);
      kk_std_time_utc__utc_dup(h, _ctx);
      kk_std_core_hnd__clause0 _match_x693;
      kk_std_core_hnd__clause0 _brw_x694 = kk_std_time_utc_utc_fs__select(h, _ctx); /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x693 = _brw_x694; /*hnd/clause0<std/time/instant/timescale,std/time/utc/utc,213,214>*/
      {
        kk_function_t _fun_unbox_x662 = _match_x693.clause;
        _x_x2647 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x662, (_fun_unbox_x662, m, ev_10447, _ctx), _ctx); /*35*/
      }
    }
    x_10444 = kk_std_time_instant__timescale_unbox(_x_x2647, KK_OWNED, _ctx); /*std/time/instant/timescale*/
  }
  kk_box_t _x_x2649;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10444, (KK_I32(10)), _ctx);
    _x_x2649 = kk_std_core_hnd_yield_extend(kk_std_time_time_year_fs_new_local_time_fun2650(cal, day_0, frac, hours_0, minutes_0, month_0, secs, year_0, _ctx), _ctx); /*2419*/
  }
  else {
    _x_x2649 = kk_std_core_hnd__open_none0(kk_std_time_time_year_fs_new_local_time_fun2652(cal, day_0, frac, hours_0, minutes_0, month_0, secs, x_10444, year_0, _ctx), _ctx); /*2419*/
  }
  return kk_std_time_time__time_unbox(_x_x2649, KK_OWNED, _ctx);
}

// initialization
void kk_std_time_time__init(kk_context_t* _ctx){
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
  kk_std_num_float64__init(_ctx);
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_instant__init(_ctx);
  kk_std_time_utc__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_time_calendar__init(_ctx);
  kk_std_time_chrono__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_time_time_mjd_epoch_delta = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_int(51544, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_time_jd_epoch_delta = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
}

// termination
void kk_std_time_time__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_num_ddouble__ddouble_drop(kk_std_time_time_jd_epoch_delta, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_time_mjd_epoch_delta, _ctx);
  kk_std_time_chrono__done(_ctx);
  kk_std_time_calendar__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_utc__done(_ctx);
  kk_std_time_instant__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
  kk_std_num_float64__done(_ctx);
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
