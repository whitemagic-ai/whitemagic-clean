// Koka generated module: std/time/instant, koka version: 3.2.2, platform: 64-bit
#include "std_time_instant.h"


// lift anonymous function
struct kk_std_time_instant_timescale_fs__copy_fun627__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x8;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_timescale_fs__copy_fun627(kk_function_t _fself, kk_std_time_duration__duration _b_x11, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_timescale_fs__new_copy_fun627(kk_box_t _fun_unbox_x8, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun627__t* _self = kk_function_alloc_as(struct kk_std_time_instant_timescale_fs__copy_fun627__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_timescale_fs__copy_fun627, kk_context());
  _self->_fun_unbox_x8 = _fun_unbox_x8;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_timescale_fs__copy_fun627(kk_function_t _fself, kk_std_time_duration__duration _b_x11, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun627__t* _self = kk_function_as(struct kk_std_time_instant_timescale_fs__copy_fun627__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x8 = _self->_fun_unbox_x8; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x8, _ctx);}, {}, _ctx)
  kk_box_t _x_x628;
  kk_function_t _x_x629 = kk_function_unbox(_fun_unbox_x8, _ctx); /*(9) -> 10*/
  _x_x628 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x629, (_x_x629, kk_std_time_duration__duration_box(_b_x11, _ctx), _ctx), _ctx); /*10*/
  return kk_std_time_timestamp__timestamp_unbox(_x_x628, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_timescale_fs__copy_fun632__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x15;
};
static kk_std_time_duration__duration kk_std_time_instant_timescale_fs__copy_fun632(kk_function_t _fself, kk_std_time_timestamp__timestamp _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_timescale_fs__new_copy_fun632(kk_box_t _fun_unbox_x15, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun632__t* _self = kk_function_alloc_as(struct kk_std_time_instant_timescale_fs__copy_fun632__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_timescale_fs__copy_fun632, kk_context());
  _self->_fun_unbox_x15 = _fun_unbox_x15;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_timescale_fs__copy_fun632(kk_function_t _fself, kk_std_time_timestamp__timestamp _b_x18, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun632__t* _self = kk_function_as(struct kk_std_time_instant_timescale_fs__copy_fun632__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x15 = _self->_fun_unbox_x15; /* 10001 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x15, _ctx);}, {}, _ctx)
  kk_box_t _x_x633;
  kk_function_t _x_x634 = kk_function_unbox(_fun_unbox_x15, _ctx); /*(16) -> 17*/
  _x_x633 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x634, (_x_x634, kk_std_time_timestamp__timestamp_box(_b_x18, _ctx), _ctx), _ctx); /*17*/
  return kk_std_time_duration__duration_unbox(_x_x633, KK_OWNED, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_timescale_fs__copy(kk_std_time_instant__timescale _this, kk_std_core_types__optional name, kk_std_core_types__optional unit, kk_std_core_types__optional from_tai_0, kk_std_core_types__optional to_tai_0, kk_std_core_types__optional mb_seconds_in_day, kk_std_core_types__optional mb_to_mjd2000, kk_std_core_types__optional mb_from_mjd2000, kk_context_t* _ctx) { /* (timescale, name : ? string, unit : ? string, from-tai : ? ((std/time/duration/duration) -> std/time/timestamp/timestamp), to-tai : ? ((std/time/timestamp/timestamp) -> std/time/duration/duration), mb-seconds-in-day : ? (maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), mb-to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), mb-from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
  kk_string_t _x_x622;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x3 = name._cons._Optional.value;
    kk_string_t _uniq_name_227 = kk_string_unbox(_box_x3);
    kk_string_dup(_uniq_name_227, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x622 = _uniq_name_227; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x623 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_string_t _x = _con_x623->name;
      kk_string_dup(_x, _ctx);
      _x_x622 = _x; /*string*/
    }
  }
  kk_string_t _x_x624;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x4 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_235 = kk_string_unbox(_box_x4);
    kk_string_dup(_uniq_unit_235, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x624 = _uniq_unit_235; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x625 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_string_t _x_0 = _con_x625->unit;
      kk_string_dup(_x_0, _ctx);
      _x_x624 = _x_0; /*string*/
    }
  }
  kk_function_t _x_x626;
  if (kk_std_core_types__is_Optional(from_tai_0, _ctx)) {
    kk_box_t _fun_unbox_x8 = from_tai_0._cons._Optional.value;
    kk_box_dup(_fun_unbox_x8, _ctx);
    kk_std_core_types__optional_drop(from_tai_0, _ctx);
    _x_x626 = kk_std_time_instant_timescale_fs__new_copy_fun627(_fun_unbox_x8, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(from_tai_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x630 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_function_t _x_1 = _con_x630->from_tai;
      kk_function_dup(_x_1, _ctx);
      _x_x626 = _x_1; /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
    }
  }
  kk_function_t _x_x631;
  if (kk_std_core_types__is_Optional(to_tai_0, _ctx)) {
    kk_box_t _fun_unbox_x15 = to_tai_0._cons._Optional.value;
    kk_box_dup(_fun_unbox_x15, _ctx);
    kk_std_core_types__optional_drop(to_tai_0, _ctx);
    _x_x631 = kk_std_time_instant_timescale_fs__new_copy_fun632(_fun_unbox_x15, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  }
  else {
    kk_std_core_types__optional_drop(to_tai_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x635 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_function_t _x_2 = _con_x635->to_tai;
      kk_function_dup(_x_2, _ctx);
      _x_x631 = _x_2; /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
    }
  }
  kk_std_core_types__maybe _x_x636;
  if (kk_std_core_types__is_Optional(mb_seconds_in_day, _ctx)) {
    kk_box_t _box_x19 = mb_seconds_in_day._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_seconds_in_day_265 = kk_std_core_types__maybe_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_seconds_in_day_265, _ctx);
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    _x_x636 = _uniq_mb_seconds_in_day_265; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x637 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_std_core_types__maybe _x_3 = _con_x637->mb_seconds_in_day;
      kk_std_core_types__maybe_dup(_x_3, _ctx);
      _x_x636 = _x_3; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
  }
  kk_std_core_types__maybe _x_x638;
  if (kk_std_core_types__is_Optional(mb_to_mjd2000, _ctx)) {
    kk_box_t _box_x20 = mb_to_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_to_mjd2000_273 = kk_std_core_types__maybe_unbox(_box_x20, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_to_mjd2000_273, _ctx);
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    _x_x638 = _uniq_mb_to_mjd2000_273; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x639 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_std_core_types__maybe _x_4 = _con_x639->mb_to_mjd2000;
      kk_std_core_types__maybe_dup(_x_4, _ctx);
      _x_x638 = _x_4; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
  }
  kk_std_core_types__maybe _x_x640;
  if (kk_std_core_types__is_Optional(mb_from_mjd2000, _ctx)) {
    kk_box_t _box_x21 = mb_from_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_from_mjd2000_281 = kk_std_core_types__maybe_unbox(_box_x21, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_from_mjd2000_281, _ctx);
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(10)), _ctx);
    _x_x640 = _uniq_mb_from_mjd2000_281; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x641 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_string_t _pat_0_6 = _con_x641->name;
      kk_string_t _pat_1_7 = _con_x641->unit;
      kk_function_t _pat_2_6 = _con_x641->from_tai;
      kk_function_t _pat_3_6 = _con_x641->to_tai;
      kk_std_core_types__maybe _pat_4_6 = _con_x641->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_5_6 = _con_x641->mb_to_mjd2000;
      kk_std_core_types__maybe _x_5 = _con_x641->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_6, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_6, _ctx);
        kk_function_drop(_pat_3_6, _ctx);
        kk_function_drop(_pat_2_6, _ctx);
        kk_string_drop(_pat_1_7, _ctx);
        kk_string_drop(_pat_0_6, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core_types__maybe_dup(_x_5, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x640 = _x_5; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x622, _x_x624, _x_x626, _x_x631, _x_x636, _x_x638, _x_x640, _ctx);
}
 
// Create a new time scale given `name`, two inverse function `from-tai` and `to-tai`,
// and an optional function that returns the seconds in the day of the instant.
// The time unit defaults to `name`.

kk_std_time_instant__timescale kk_std_time_instant_timescale(kk_string_t name, kk_function_t from_tai_0, kk_function_t to_tai_0, kk_std_core_types__optional unit, kk_std_core_types__optional seconds_in_day_0, kk_std_core_types__optional to_mjd2000, kk_std_core_types__optional from_mjd2000, kk_context_t* _ctx) { /* (name : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, unit : ? string, seconds-in-day : ? (maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
  kk_string_t _x_x650 = kk_string_dup(name, _ctx); /*string*/
  kk_string_t _x_x651;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x22 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_356 = kk_string_unbox(_box_x22);
    kk_string_dup(_uniq_unit_356, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    kk_string_drop(name, _ctx);
    _x_x651 = _uniq_unit_356; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x651 = name; /*string*/
  }
  kk_std_core_types__maybe _x_x652;
  if (kk_std_core_types__is_Optional(seconds_in_day_0, _ctx)) {
    kk_box_t _box_x23 = seconds_in_day_0._cons._Optional.value;
    kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x23, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
    kk_std_core_types__optional_drop(seconds_in_day_0, _ctx);
    _x_x652 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(seconds_in_day_0, _ctx);
    _x_x652 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x653;
  if (kk_std_core_types__is_Optional(to_mjd2000, _ctx)) {
    kk_box_t _box_x24 = to_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x24, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
    kk_std_core_types__optional_drop(to_mjd2000, _ctx);
    _x_x653 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(to_mjd2000, _ctx);
    _x_x653 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x654;
  if (kk_std_core_types__is_Optional(from_mjd2000, _ctx)) {
    kk_box_t _box_x25 = from_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x25, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
    kk_std_core_types__optional_drop(from_mjd2000, _ctx);
    _x_x654 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(from_mjd2000, _ctx);
    _x_x654 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x650, _x_x651, from_tai_0, to_tai_0, _x_x652, _x_x653, _x_x654, _ctx);
}
 
// Create a new time scale based on SI seconds (as measured on the Earth's geoid) with a given
//  `name`, a fixed `offset` (=`duration0`) from TAI (e.g. GPS = TAI - 19), and
// a `epoch-y2k` (= `timestamp0`) which is the timestamp of the 2000-01-01 date in that timescale
// e.g. for a timescale `ts`:
// `epoch-y2k = instant(2000,1,1,cal=iso-calendar(ts)).since-in(ts)`


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun664__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun664(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun664(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun664__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun664__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_tai_timescale_fun664, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun664(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun664__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun664__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_10026;
  kk_std_num_ddouble__ddouble _x_x665;
  {
    kk_std_num_ddouble__ddouble _x_0 = tai.secs;
    _x_x665 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x666;
  {
    kk_std_num_ddouble__ddouble _x = _uniq_offset_847.secs;
    _x_x666 = _x; /*std/time/timestamp/timespan*/
  }
  t_10026 = kk_std_num_ddouble__lp__plus__rp_(_x_x665, _x_x666, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x667;
  kk_integer_t _x_x668;
  kk_std_core_types__optional _match_x402 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x402, _ctx)) {
    kk_box_t _box_x32 = _match_x402._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x32, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x402, _ctx);
    _x_x668 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x402, _ctx);
    _x_x668 = kk_integer_from_small(0); /*int*/
  }
  _x_x667 = kk_integer_clamp32(_x_x668,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10026, _x_x667, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun669__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun669(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun669(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun669__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun669__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_tai_timescale_fun669, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun669(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun669__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun669__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_1_10029;
  kk_std_num_ddouble__ddouble _x_x670;
  {
    kk_std_num_ddouble__ddouble _x_1 = _uniq_offset_847.secs;
    _x_x670 = _x_1; /*std/time/timestamp/timespan*/
  }
  t_1_10029 = kk_std_time_timestamp__lp__dash__rp_(t_0, _x_x670, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x671 = kk_std_time_timestamp_unsafe_timespan_withleap(t_1_10029, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x671, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_tai_timescale(kk_string_t name, kk_std_core_types__optional offset, kk_context_t* _ctx) { /* (name : string, offset : ? std/time/duration/duration) -> timescale */ 
  kk_std_time_duration__duration _uniq_offset_847;
  if (kk_std_core_types__is_Optional(offset, _ctx)) {
    kk_box_t _box_x26 = offset._cons._Optional.value;
    kk_std_time_duration__duration _uniq_offset_848 = kk_std_time_duration__duration_unbox(_box_x26, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(offset, _ctx);
    _uniq_offset_847 = _uniq_offset_848; /*std/time/duration/duration*/
  }
  else {
    kk_std_core_types__optional_drop(offset, _ctx);
    kk_std_core_types__optional frac_0_10006;
    kk_box_t _x_x655;
    double _x_x656;
    kk_std_core_types__optional _match_x404 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x404, _ctx)) {
      kk_box_t _box_x27 = _match_x404._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x27, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x404, _ctx);
      _x_x656 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x404, _ctx);
      _x_x656 = 0x0p+0; /*float64*/
    }
    _x_x655 = kk_double_box(_x_x656, _ctx); /*10003*/
    frac_0_10006 = kk_std_core_types__new_Optional(_x_x655, _ctx); /*? float64*/
    kk_std_num_ddouble__ddouble _x_x657;
    bool _match_x403;
    double _x_x658;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x30 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x30, KK_BORROWED, _ctx);
      _x_x658 = _uniq_frac_1144; /*float64*/
    }
    else {
      _x_x658 = 0x0p+0; /*float64*/
    }
    _match_x403 = (_x_x658 == (0x0p+0)); /*bool*/
    if (_match_x403) {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x657 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x659 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x660;
      double _x_x661;
      if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
        kk_box_t _box_x31 = frac_0_10006._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x31, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x661 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x661 = 0x0p+0; /*float64*/
      }
      _x_x660 = kk_std_num_ddouble__new_Ddouble(_x_x661, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x657 = kk_std_num_ddouble__lp__plus__rp_(_x_x659, _x_x660, _ctx); /*std/num/ddouble/ddouble*/
    }
    _uniq_offset_847 = kk_std_time_duration__new_Duration(_x_x657, _ctx); /*std/time/duration/duration*/
  }
  kk_string_t _x_x662;
  kk_define_string_literal(, _s_x663, 3, "TAI", _ctx)
  _x_x662 = kk_string_dup(_s_x663, _ctx); /*string*/
  kk_std_core_types__maybe _x_x672;
  kk_std_core_types__optional _match_x401 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x401, _ctx)) {
    kk_box_t _box_x33 = _match_x401._cons._Optional.value;
    kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x33, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
    kk_std_core_types__optional_drop(_match_x401, _ctx);
    _x_x672 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x401, _ctx);
    _x_x672 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x673;
  kk_std_core_types__optional _match_x400 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x400, _ctx)) {
    kk_box_t _box_x34 = _match_x400._cons._Optional.value;
    kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x34, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
    kk_std_core_types__optional_drop(_match_x400, _ctx);
    _x_x673 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x400, _ctx);
    _x_x673 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x674;
  kk_std_core_types__optional _match_x399 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x399, _ctx)) {
    kk_box_t _box_x35 = _match_x399._cons._Optional.value;
    kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x35, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
    kk_std_core_types__optional_drop(_match_x399, _ctx);
    _x_x674 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x399, _ctx);
    _x_x674 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, name, _x_x662, kk_std_time_instant_new_tai_timescale_fun664(_uniq_offset_847, _ctx), kk_std_time_instant_new_tai_timescale_fun669(_uniq_offset_847, _ctx), _x_x672, _x_x673, _x_x674, _ctx);
}
 
// The [TAI](https://en.wikipedia.org/wiki/International_Atomic_Time) (International atomic time)
// time scale is based on SI seconds measured on the Earth's geoid, with a 2000-01-01 TAI `epoch`.


// lift anonymous function
struct kk_std_time_instant_ts_tai_fun686__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tai_fun686(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tai_fun686(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun686__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tai_fun686__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_ts_tai_fun686, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tai_fun686(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun686__t* _self = kk_function_as(struct kk_std_time_instant_ts_tai_fun686__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_10026;
  kk_std_num_ddouble__ddouble _x_x687;
  {
    kk_std_num_ddouble__ddouble _x_0 = tai.secs;
    _x_x687 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x688;
  {
    kk_std_num_ddouble__ddouble _x = _uniq_offset_847.secs;
    _x_x688 = _x; /*std/time/timestamp/timespan*/
  }
  t_10026 = kk_std_num_ddouble__lp__plus__rp_(_x_x687, _x_x688, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x689;
  kk_integer_t _x_x690;
  kk_std_core_types__optional _match_x395 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x395, _ctx)) {
    kk_box_t _box_x42 = _match_x395._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x42, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x395, _ctx);
    _x_x690 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x395, _ctx);
    _x_x690 = kk_integer_from_small(0); /*int*/
  }
  _x_x689 = kk_integer_clamp32(_x_x690,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10026, _x_x689, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_tai_fun691__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_tai_fun691(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tai_fun691(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun691__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tai_fun691__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_ts_tai_fun691, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_ts_tai_fun691(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tai_fun691__t* _self = kk_function_as(struct kk_std_time_instant_ts_tai_fun691__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_1_10029;
  kk_std_num_ddouble__ddouble _x_x692;
  {
    kk_std_num_ddouble__ddouble _x_1 = _uniq_offset_847.secs;
    _x_x692 = _x_1; /*std/time/timestamp/timespan*/
  }
  t_1_10029 = kk_std_time_timestamp__lp__dash__rp_(t_0, _x_x692, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x693 = kk_std_time_timestamp_unsafe_timespan_withleap(t_1_10029, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x693, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_tai;
 
// Add a time span to an instant in time.
// This is only safe if the time unit of the timespan is the
// same as that of the instant.

kk_std_time_instant__instant kk_std_time_instant_unsafe_add(kk_std_time_instant__instant i, kk_std_num_ddouble__ddouble tspan, kk_context_t* _ctx) { /* (i : instant, tspan : std/time/timestamp/timespan) -> instant */ 
  kk_std_time_timestamp__timestamp _x_x697;
  kk_std_num_ddouble__ddouble _x_x698;
  kk_std_num_ddouble__ddouble _x_x699;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_1 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x700 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x701 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x702 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x702->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x699 = _x; /*std/time/timestamp/timespan*/
    }
  }
  _x_x698 = kk_std_num_ddouble__lp__plus__rp_(_x_x699, tspan, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x703;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_1_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x704 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x705 = kk_std_time_instant__as_Timescale(_pat_2_1_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x706 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x706->since;
      int32_t _x_0 = _con_x706->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x703 = _x_0; /*int32*/
    }
  }
  _x_x697 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x698, _x_x703, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x707;
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x708 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x709 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
    kk_std_time_instant__timescale_dup(_x_2, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x707 = _x_2; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant__new_Instant(_x_x697, _x_x707, _ctx);
}
 
// Convert a timespan between time scales

kk_std_time_timestamp__timestamp kk_std_time_instant_convert(kk_std_time_timestamp__timestamp t, kk_std_time_instant__timescale from, kk_std_time_instant__timescale to, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, from : timescale, to : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_x389;
  kk_string_t _x_x710;
  {
    struct kk_std_time_instant_Timescale* _con_x711 = kk_std_time_instant__as_Timescale(from, _ctx);
    kk_string_t _x = _con_x711->name;
    kk_string_dup(_x, _ctx);
    _x_x710 = _x; /*string*/
  }
  kk_string_t _x_x712;
  {
    struct kk_std_time_instant_Timescale* _con_x713 = kk_std_time_instant__as_Timescale(to, _ctx);
    kk_string_t _x_0 = _con_x713->name;
    kk_string_dup(_x_0, _ctx);
    _x_x712 = _x_0; /*string*/
  }
  _match_x389 = kk_string_is_eq(_x_x710,_x_x712,kk_context()); /*bool*/
  if (_match_x389) {
    kk_datatype_ptr_dropn(to, (KK_I32(10)), _ctx);
    kk_datatype_ptr_dropn(from, (KK_I32(10)), _ctx);
    return t;
  }
  {
    bool _match_x390;
    kk_string_t _x_x714;
    {
      struct kk_std_time_instant_Timescale* _con_x715 = kk_std_time_instant__as_Timescale(from, _ctx);
      kk_string_t _x_1 = _con_x715->unit;
      kk_string_dup(_x_1, _ctx);
      _x_x714 = _x_1; /*string*/
    }
    kk_string_t _x_x716;
    {
      struct kk_std_time_instant_Timescale* _con_x717 = kk_std_time_instant__as_Timescale(to, _ctx);
      kk_string_t _x_2 = _con_x717->unit;
      kk_string_dup(_x_2, _ctx);
      _x_x716 = _x_2; /*string*/
    }
    _match_x390 = kk_string_is_eq(_x_x714,_x_x716,kk_context()); /*bool*/
    if (_match_x390) {
      bool _match_x391;
      kk_string_t _x_x718;
      {
        struct kk_std_time_instant_Timescale* _con_x719 = kk_std_time_instant__as_Timescale(from, _ctx);
        kk_string_t _x_3 = _con_x719->unit;
        kk_string_dup(_x_3, _ctx);
        _x_x718 = _x_3; /*string*/
      }
      kk_string_t _x_x720;
      kk_define_string_literal(, _s_x721, 3, "UTC", _ctx)
      _x_x720 = kk_string_dup(_s_x721, _ctx); /*string*/
      _match_x391 = kk_string_is_eq(_x_x718,_x_x720,kk_context()); /*bool*/
      if (_match_x391) {
        kk_datatype_ptr_dropn(to, (KK_I32(10)), _ctx);
        kk_datatype_ptr_dropn(from, (KK_I32(10)), _ctx);
        return t;
      }
      {
        kk_std_time_duration__duration _norm_x10278;
        {
          struct kk_std_time_instant_Timescale* _con_x722 = kk_std_time_instant__as_Timescale(from, _ctx);
          kk_string_t _pat_0_6 = _con_x722->name;
          kk_string_t _pat_1_6 = _con_x722->unit;
          kk_function_t _pat_2_5 = _con_x722->from_tai;
          kk_function_t _x_5 = _con_x722->to_tai;
          kk_std_core_types__maybe _pat_3_6 = _con_x722->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_6 = _con_x722->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_5 = _con_x722->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(from, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_6, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_6, _ctx);
            kk_function_drop(_pat_2_5, _ctx);
            kk_string_drop(_pat_1_6, _ctx);
            kk_string_drop(_pat_0_6, _ctx);
            kk_datatype_ptr_free(from, _ctx);
          }
          else {
            kk_function_dup(_x_5, _ctx);
            kk_datatype_ptr_decref(from, _ctx);
          }
          _norm_x10278 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5, (_x_5, t, _ctx), _ctx); /*std/time/duration/duration*/
        }
        {
          struct kk_std_time_instant_Timescale* _con_x723 = kk_std_time_instant__as_Timescale(to, _ctx);
          kk_string_t _pat_0_5 = _con_x723->name;
          kk_string_t _pat_1_5 = _con_x723->unit;
          kk_function_t _x_4 = _con_x723->from_tai;
          kk_function_t _pat_2_4 = _con_x723->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x723->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x723->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_4 = _con_x723->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(to, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_5, _ctx);
            kk_function_drop(_pat_2_4, _ctx);
            kk_string_drop(_pat_1_5, _ctx);
            kk_string_drop(_pat_0_5, _ctx);
            kk_datatype_ptr_free(to, _ctx);
          }
          else {
            kk_function_dup(_x_4, _ctx);
            kk_datatype_ptr_decref(to, _ctx);
          }
          return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4, (_x_4, _norm_x10278, _ctx), _ctx);
        }
      }
    }
    {
      kk_std_time_duration__duration _norm_x10279;
      {
        struct kk_std_time_instant_Timescale* _con_x724 = kk_std_time_instant__as_Timescale(from, _ctx);
        kk_string_t _pat_0_8 = _con_x724->name;
        kk_string_t _pat_1_8 = _con_x724->unit;
        kk_function_t _pat_2_8 = _con_x724->from_tai;
        kk_function_t _x_7 = _con_x724->to_tai;
        kk_std_core_types__maybe _pat_3_8 = _con_x724->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_8 = _con_x724->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_7 = _con_x724->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(from, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_7, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_8, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_8, _ctx);
          kk_function_drop(_pat_2_8, _ctx);
          kk_string_drop(_pat_1_8, _ctx);
          kk_string_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(from, _ctx);
        }
        else {
          kk_function_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(from, _ctx);
        }
        _norm_x10279 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7, (_x_7, t, _ctx), _ctx); /*std/time/duration/duration*/
      }
      {
        struct kk_std_time_instant_Timescale* _con_x725 = kk_std_time_instant__as_Timescale(to, _ctx);
        kk_string_t _pat_0_7 = _con_x725->name;
        kk_string_t _pat_1_7 = _con_x725->unit;
        kk_function_t _x_6 = _con_x725->from_tai;
        kk_function_t _pat_2_7 = _con_x725->to_tai;
        kk_std_core_types__maybe _pat_3_7 = _con_x725->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_7 = _con_x725->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_6 = _con_x725->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(to, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_6, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_7, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_7, _ctx);
          kk_function_drop(_pat_2_7, _ctx);
          kk_string_drop(_pat_1_7, _ctx);
          kk_string_drop(_pat_0_7, _ctx);
          kk_datatype_ptr_free(to, _ctx);
        }
        else {
          kk_function_dup(_x_6, _ctx);
          kk_datatype_ptr_decref(to, _ctx);
        }
        return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6, (_x_6, _norm_x10279, _ctx), _ctx);
      }
    }
  }
}
 
// Return a `:timestamp` for instant `i` in a certain time scale `tscale`.

kk_std_time_timestamp__timestamp kk_std_time_instant_timestamp_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_x386;
  kk_string_t _x_x726;
  {
    kk_std_time_timestamp__timestamp _pat_0_10 = i.since;
    kk_std_time_instant__timescale _x_9 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x727 = kk_std_time_timestamp__as_Timestamp(_pat_0_10, _ctx);
    struct kk_std_time_instant_Timescale* _con_x728 = kk_std_time_instant__as_Timescale(_x_9, _ctx);
    kk_std_time_instant__timescale_dup(_x_9, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x729 = kk_std_time_instant__as_Timescale(_x_9, _ctx);
      kk_string_t _x = _con_x729->name;
      kk_string_t _pat_0 = _con_x729->unit;
      kk_function_t _pat_1 = _con_x729->from_tai;
      kk_function_t _pat_2 = _con_x729->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x729->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x729->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x729->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_3, _ctx);
        kk_function_drop(_pat_2, _ctx);
        kk_function_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_9, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_9, _ctx);
      }
      _x_x726 = _x; /*string*/
    }
  }
  kk_string_t _x_x730;
  {
    struct kk_std_time_instant_Timescale* _con_x731 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_0 = _con_x731->name;
    kk_string_dup(_x_0, _ctx);
    _x_x730 = _x_0; /*string*/
  }
  _match_x386 = kk_string_is_eq(_x_x726,_x_x730,kk_context()); /*bool*/
  if (_match_x386) {
    kk_datatype_ptr_dropn(tscale, (KK_I32(10)), _ctx);
    {
      kk_std_time_timestamp__timestamp _x_8 = i.since;
      kk_std_time_instant__timescale _pat_2_9 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x732 = kk_std_time_timestamp__as_Timestamp(_x_8, _ctx);
      struct kk_std_time_instant_Timescale* _con_x733 = kk_std_time_instant__as_Timescale(_pat_2_9, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_8, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      return _x_8;
    }
  }
  {
    bool _match_x387;
    kk_string_t _x_x734;
    {
      kk_std_time_timestamp__timestamp _pat_0_10_0 = i.since;
      kk_std_time_instant__timescale _x_9_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x735 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x736 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_9_0, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x737 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
        kk_string_t _pat_0_2 = _con_x737->name;
        kk_string_t _x_1 = _con_x737->unit;
        kk_function_t _pat_1_1 = _con_x737->from_tai;
        kk_function_t _pat_2_1 = _con_x737->to_tai;
        kk_std_core_types__maybe _pat_3_1 = _con_x737->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_1 = _con_x737->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_1 = _con_x737->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9_0, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
          kk_function_drop(_pat_2_1, _ctx);
          kk_function_drop(_pat_1_1, _ctx);
          kk_string_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(_x_9_0, _ctx);
        }
        else {
          kk_string_dup(_x_1, _ctx);
          kk_datatype_ptr_decref(_x_9_0, _ctx);
        }
        _x_x734 = _x_1; /*string*/
      }
    }
    kk_string_t _x_x738;
    {
      struct kk_std_time_instant_Timescale* _con_x739 = kk_std_time_instant__as_Timescale(tscale, _ctx);
      kk_string_t _x_2 = _con_x739->unit;
      kk_string_dup(_x_2, _ctx);
      _x_x738 = _x_2; /*string*/
    }
    _match_x387 = kk_string_is_eq(_x_x734,_x_x738,kk_context()); /*bool*/
    if (_match_x387) {
      bool _match_x388;
      kk_string_t _x_x740;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_1 = i.since;
        kk_std_time_instant__timescale _x_9_1 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x741 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x742 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_1, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x743 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
          kk_string_t _pat_0_4 = _con_x743->name;
          kk_string_t _x_3 = _con_x743->unit;
          kk_function_t _pat_1_4 = _con_x743->from_tai;
          kk_function_t _pat_2_3 = _con_x743->to_tai;
          kk_std_core_types__maybe _pat_3_3 = _con_x743->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_3 = _con_x743->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_3 = _con_x743->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9_1, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_3, _ctx);
            kk_function_drop(_pat_2_3, _ctx);
            kk_function_drop(_pat_1_4, _ctx);
            kk_string_drop(_pat_0_4, _ctx);
            kk_datatype_ptr_free(_x_9_1, _ctx);
          }
          else {
            kk_string_dup(_x_3, _ctx);
            kk_datatype_ptr_decref(_x_9_1, _ctx);
          }
          _x_x740 = _x_3; /*string*/
        }
      }
      kk_string_t _x_x744;
      kk_define_string_literal(, _s_x745, 3, "UTC", _ctx)
      _x_x744 = kk_string_dup(_s_x745, _ctx); /*string*/
      _match_x388 = kk_string_is_eq(_x_x740,_x_x744,kk_context()); /*bool*/
      if (_match_x388) {
        kk_datatype_ptr_dropn(tscale, (KK_I32(10)), _ctx);
        {
          kk_std_time_timestamp__timestamp _x_8_0 = i.since;
          kk_std_time_instant__timescale _pat_2_9_0 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x746 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x747 = kk_std_time_instant__as_Timescale(_pat_2_9_0, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_8_0, _ctx);
          kk_std_time_instant__instant_drop(i, _ctx);
          return _x_8_0;
        }
      }
      {
        kk_std_time_duration__duration _norm_x10280;
        {
          kk_std_time_timestamp__timestamp _pat_0_10_2 = i.since;
          kk_std_time_instant__timescale _x_9_2 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x748 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_2, _ctx);
          struct kk_std_time_instant_Timescale* _con_x749 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
          kk_std_time_instant__timescale_dup(_x_9_2, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x750 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
            kk_string_t _pat_0_6 = _con_x750->name;
            kk_string_t _pat_1_6 = _con_x750->unit;
            kk_function_t _pat_2_5 = _con_x750->from_tai;
            kk_function_t _x_5 = _con_x750->to_tai;
            kk_std_core_types__maybe _pat_3_6 = _con_x750->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_6 = _con_x750->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_5 = _con_x750->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_9_2, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_6, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_6, _ctx);
              kk_function_drop(_pat_2_5, _ctx);
              kk_string_drop(_pat_1_6, _ctx);
              kk_string_drop(_pat_0_6, _ctx);
              kk_datatype_ptr_free(_x_9_2, _ctx);
            }
            else {
              kk_function_dup(_x_5, _ctx);
              kk_datatype_ptr_decref(_x_9_2, _ctx);
            }
            kk_std_time_timestamp__timestamp _x_x751;
            {
              kk_std_time_timestamp__timestamp _x_8_1 = i.since;
              kk_std_time_instant__timescale _pat_2_9_1 = i.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x752 = kk_std_time_timestamp__as_Timestamp(_x_8_1, _ctx);
              struct kk_std_time_instant_Timescale* _con_x753 = kk_std_time_instant__as_Timescale(_pat_2_9_1, _ctx);
              kk_std_time_timestamp__timestamp_dup(_x_8_1, _ctx);
              kk_std_time_instant__instant_drop(i, _ctx);
              _x_x751 = _x_8_1; /*std/time/timestamp/timestamp*/
            }
            _norm_x10280 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5, (_x_5, _x_x751, _ctx), _ctx); /*std/time/duration/duration*/
          }
        }
        {
          struct kk_std_time_instant_Timescale* _con_x754 = kk_std_time_instant__as_Timescale(tscale, _ctx);
          kk_string_t _pat_0_5 = _con_x754->name;
          kk_string_t _pat_1_5 = _con_x754->unit;
          kk_function_t _x_4 = _con_x754->from_tai;
          kk_function_t _pat_2_4 = _con_x754->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x754->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x754->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_4 = _con_x754->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(tscale, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_5, _ctx);
            kk_function_drop(_pat_2_4, _ctx);
            kk_string_drop(_pat_1_5, _ctx);
            kk_string_drop(_pat_0_5, _ctx);
            kk_datatype_ptr_free(tscale, _ctx);
          }
          else {
            kk_function_dup(_x_4, _ctx);
            kk_datatype_ptr_decref(tscale, _ctx);
          }
          return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4, (_x_4, _norm_x10280, _ctx), _ctx);
        }
      }
    }
    {
      kk_std_time_duration__duration _norm_x10281;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_3 = i.since;
        kk_std_time_instant__timescale _x_9_3 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x755 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_3, _ctx);
        struct kk_std_time_instant_Timescale* _con_x756 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_3, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x757 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
          kk_string_t _pat_0_8 = _con_x757->name;
          kk_string_t _pat_1_8 = _con_x757->unit;
          kk_function_t _pat_2_8 = _con_x757->from_tai;
          kk_function_t _x_7 = _con_x757->to_tai;
          kk_std_core_types__maybe _pat_3_8 = _con_x757->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_8 = _con_x757->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_7 = _con_x757->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9_3, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_7, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_8, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_8, _ctx);
            kk_function_drop(_pat_2_8, _ctx);
            kk_string_drop(_pat_1_8, _ctx);
            kk_string_drop(_pat_0_8, _ctx);
            kk_datatype_ptr_free(_x_9_3, _ctx);
          }
          else {
            kk_function_dup(_x_7, _ctx);
            kk_datatype_ptr_decref(_x_9_3, _ctx);
          }
          kk_std_time_timestamp__timestamp _x_x758;
          {
            kk_std_time_timestamp__timestamp _x_8_2 = i.since;
            kk_std_time_instant__timescale _pat_2_9_2 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x759 = kk_std_time_timestamp__as_Timestamp(_x_8_2, _ctx);
            struct kk_std_time_instant_Timescale* _con_x760 = kk_std_time_instant__as_Timescale(_pat_2_9_2, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_8_2, _ctx);
            kk_std_time_instant__instant_drop(i, _ctx);
            _x_x758 = _x_8_2; /*std/time/timestamp/timestamp*/
          }
          _norm_x10281 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7, (_x_7, _x_x758, _ctx), _ctx); /*std/time/duration/duration*/
        }
      }
      {
        struct kk_std_time_instant_Timescale* _con_x761 = kk_std_time_instant__as_Timescale(tscale, _ctx);
        kk_string_t _pat_0_7 = _con_x761->name;
        kk_string_t _pat_1_7 = _con_x761->unit;
        kk_function_t _x_6 = _con_x761->from_tai;
        kk_function_t _pat_2_7 = _con_x761->to_tai;
        kk_std_core_types__maybe _pat_3_7 = _con_x761->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_7 = _con_x761->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_6 = _con_x761->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(tscale, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_6, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_7, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_7, _ctx);
          kk_function_drop(_pat_2_7, _ctx);
          kk_string_drop(_pat_1_7, _ctx);
          kk_string_drop(_pat_0_7, _ctx);
          kk_datatype_ptr_free(tscale, _ctx);
        }
        else {
          kk_function_dup(_x_6, _ctx);
          kk_datatype_ptr_decref(tscale, _ctx);
        }
        return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6, (_x_6, _norm_x10281, _ctx), _ctx);
      }
    }
  }
}
 
// Change the internal representation of an instant to use another timescale.
// Only used in special cases for efficiency. For example, when comparing an
// instant in TAI time to thousands of UTC times, it is more efficient to convert
// the TAI time to UTC first to avoid converting at each comparision.

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> instant */ 
  bool _match_x385;
  kk_string_t _x_x762;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x763 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x764 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x765 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x765->name;
      kk_string_t _pat_0 = _con_x765->unit;
      kk_function_t _pat_1 = _con_x765->from_tai;
      kk_function_t _pat_2 = _con_x765->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x765->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x765->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x765->mb_from_mjd2000;
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
      _x_x762 = _x; /*string*/
    }
  }
  kk_string_t _x_x766;
  {
    struct kk_std_time_instant_Timescale* _con_x767 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_1 = _con_x767->name;
    kk_string_dup(_x_1, _ctx);
    _x_x766 = _x_1; /*string*/
  }
  _match_x385 = kk_string_is_eq(_x_x762,_x_x766,kk_context()); /*bool*/
  if (_match_x385) {
    kk_datatype_ptr_dropn(tscale, (KK_I32(10)), _ctx);
    return i;
  }
  {
    kk_std_time_timestamp__timestamp _x_x768;
    kk_std_time_instant__timescale _x_x769 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    _x_x768 = kk_std_time_instant_timestamp_in(i, _x_x769, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(_x_x768, tscale, _ctx);
  }
}
 
// Add a duration to an instant in time.
// Note: this generally entails conversion to TAI time (`ts-tai`).
// See also `add-duration-in` and `add-days` to add
// in direct time scale units.

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  bool _match_x379;
  kk_string_t _x_x770;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x771 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x772 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x773 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x773->name;
      kk_string_t _x = _con_x773->unit;
      kk_function_t _pat_1 = _con_x773->from_tai;
      kk_function_t _pat_2 = _con_x773->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x773->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x773->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x773->mb_from_mjd2000;
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
      _x_x770 = _x; /*string*/
    }
  }
  kk_string_t _x_x774;
  kk_define_string_literal(, _s_x775, 3, "TAI", _ctx)
  _x_x774 = kk_string_dup(_s_x775, _ctx); /*string*/
  _match_x379 = kk_string_is_eq(_x_x770,_x_x774,kk_context()); /*bool*/
  if (_match_x379) {
    kk_std_time_timestamp__timestamp _x_x776;
    kk_std_num_ddouble__ddouble _x_x777;
    kk_std_num_ddouble__ddouble _x_x778;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x779 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x780 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x781 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
        kk_std_num_ddouble__ddouble _x_1 = _con_x781->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
          kk_datatype_ptr_free(_x_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_2, _ctx);
        }
        _x_x778 = _x_1; /*std/time/timestamp/timespan*/
      }
    }
    kk_std_num_ddouble__ddouble _x_x782;
    {
      kk_std_num_ddouble__ddouble _x_4 = d.secs;
      _x_x782 = _x_4; /*std/time/timestamp/timespan*/
    }
    _x_x777 = kk_std_num_ddouble__lp__plus__rp_(_x_x778, _x_x782, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x783;
    {
      kk_std_time_timestamp__timestamp _x_2_0 = i.since;
      kk_std_time_instant__timescale _pat_2_2_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x784 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x785 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x786 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x786->since;
        int32_t _x_0_0 = _con_x786->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2_0, _ctx)) {
          kk_datatype_ptr_free(_x_2_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_2_0, _ctx);
        }
        _x_x783 = _x_0_0; /*int32*/
      }
    }
    _x_x776 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x777, _x_x783, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x787;
    {
      kk_std_time_timestamp__timestamp _pat_0_3 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x788 = kk_std_time_timestamp__as_Timestamp(_pat_0_3, _ctx);
      struct kk_std_time_instant_Timescale* _con_x789 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x787 = _x_3; /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x776, _x_x787, _ctx);
  }
  {
    kk_std_time_instant__instant i_2_10078;
    bool _match_x384;
    kk_string_t _x_x790;
    {
      kk_std_time_timestamp__timestamp _pat_0_0_1 = i.since;
      kk_std_time_instant__timescale _x_0_1 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x791 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x792 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_1, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x793 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
        kk_string_t _x_5 = _con_x793->name;
        kk_string_t _pat_0_6 = _con_x793->unit;
        kk_function_t _pat_1_5 = _con_x793->from_tai;
        kk_function_t _pat_2_4 = _con_x793->to_tai;
        kk_std_core_types__maybe _pat_3_4 = _con_x793->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3 = _con_x793->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3 = _con_x793->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_4, _ctx);
          kk_function_drop(_pat_2_4, _ctx);
          kk_function_drop(_pat_1_5, _ctx);
          kk_string_drop(_pat_0_6, _ctx);
          kk_datatype_ptr_free(_x_0_1, _ctx);
        }
        else {
          kk_string_dup(_x_5, _ctx);
          kk_datatype_ptr_decref(_x_0_1, _ctx);
        }
        _x_x790 = _x_5; /*string*/
      }
    }
    kk_string_t _x_x794;
    kk_std_time_instant__timescale _x_x795 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
    {
      struct kk_std_time_instant_Timescale* _con_x796 = kk_std_time_instant__as_Timescale(_x_x795, _ctx);
      kk_string_t _x_1_0 = _con_x796->name;
      _x_x794 = kk_string_dup(_x_1_0, _ctx); /*string*/
    }
    _match_x384 = kk_string_is_eq(_x_x790,_x_x794,kk_context()); /*bool*/
    if (_match_x384) {
      i_2_10078 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    }
    else {
      kk_std_time_timestamp__timestamp _x_x797;
      kk_std_time_instant__instant _x_x798 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
      kk_std_time_instant__timescale _x_x799 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
      _x_x797 = kk_std_time_instant_timestamp_in(_x_x798, _x_x799, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x800 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
      i_2_10078 = kk_std_time_instant__new_Instant(_x_x797, _x_x800, _ctx); /*std/time/instant/instant*/
    }
    kk_std_time_instant__instant i_1_10076;
    kk_std_time_timestamp__timestamp _x_x801;
    kk_std_num_ddouble__ddouble _x_x802;
    kk_std_num_ddouble__ddouble _x_x803;
    {
      kk_std_time_timestamp__timestamp _x_9 = i_2_10078.since;
      kk_std_time_instant__timescale _pat_2_8 = i_2_10078.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x804 = kk_std_time_timestamp__as_Timestamp(_x_9, _ctx);
      struct kk_std_time_instant_Timescale* _con_x805 = kk_std_time_instant__as_Timescale(_pat_2_8, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_9, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x806 = kk_std_time_timestamp__as_Timestamp(_x_9, _ctx);
        kk_std_num_ddouble__ddouble _x_8 = _con_x806->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
          kk_datatype_ptr_free(_x_9, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_9, _ctx);
        }
        _x_x803 = _x_8; /*std/time/timestamp/timespan*/
      }
    }
    kk_std_num_ddouble__ddouble _x_x807;
    {
      kk_std_num_ddouble__ddouble _x_11 = d.secs;
      _x_x807 = _x_11; /*std/time/timestamp/timespan*/
    }
    _x_x802 = kk_std_num_ddouble__lp__plus__rp_(_x_x803, _x_x807, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x808;
    {
      kk_std_time_timestamp__timestamp _x_9_0 = i_2_10078.since;
      kk_std_time_instant__timescale _pat_2_8_0 = i_2_10078.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x809 = kk_std_time_timestamp__as_Timestamp(_x_9_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x810 = kk_std_time_instant__as_Timescale(_pat_2_8_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_9_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x811 = kk_std_time_timestamp__as_Timestamp(_x_9_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_1_0 = _con_x811->since;
        int32_t _x_0_1_0 = _con_x811->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9_0, _ctx)) {
          kk_datatype_ptr_free(_x_9_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_9_0, _ctx);
        }
        _x_x808 = _x_0_1_0; /*int32*/
      }
    }
    _x_x801 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x802, _x_x808, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x812;
    {
      kk_std_time_timestamp__timestamp _pat_0_12 = i_2_10078.since;
      kk_std_time_instant__timescale _x_10 = i_2_10078.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x813 = kk_std_time_timestamp__as_Timestamp(_pat_0_12, _ctx);
      struct kk_std_time_instant_Timescale* _con_x814 = kk_std_time_instant__as_Timescale(_x_10, _ctx);
      kk_std_time_instant__timescale_dup(_x_10, _ctx);
      kk_std_time_instant__instant_drop(i_2_10078, _ctx);
      _x_x812 = _x_10; /*std/time/instant/timescale*/
    }
    i_1_10076 = kk_std_time_instant__new_Instant(_x_x801, _x_x812, _ctx); /*std/time/instant/instant*/
    bool _match_x380;
    kk_string_t _x_x815;
    {
      kk_std_time_timestamp__timestamp _pat_0_7 = i_1_10076.since;
      kk_std_time_instant__timescale _x_6 = i_1_10076.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x816 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
      struct kk_std_time_instant_Timescale* _con_x817 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
      kk_std_time_instant__timescale_dup(_x_6, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x818 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
        kk_string_t _x_5_0 = _con_x818->name;
        kk_string_t _pat_0_6_0 = _con_x818->unit;
        kk_function_t _pat_1_5_0 = _con_x818->from_tai;
        kk_function_t _pat_2_4_0 = _con_x818->to_tai;
        kk_std_core_types__maybe _pat_3_4_0 = _con_x818->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3_0 = _con_x818->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3_0 = _con_x818->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_6, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_3_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_3_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_4_0, _ctx);
          kk_function_drop(_pat_2_4_0, _ctx);
          kk_function_drop(_pat_1_5_0, _ctx);
          kk_string_drop(_pat_0_6_0, _ctx);
          kk_datatype_ptr_free(_x_6, _ctx);
        }
        else {
          kk_string_dup(_x_5_0, _ctx);
          kk_datatype_ptr_decref(_x_6, _ctx);
        }
        _x_x815 = _x_5_0; /*string*/
      }
    }
    kk_string_t _x_x819;
    {
      kk_std_time_timestamp__timestamp _pat_0_14 = i.since;
      kk_std_time_instant__timescale _x_12 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x820 = kk_std_time_timestamp__as_Timestamp(_pat_0_14, _ctx);
      struct kk_std_time_instant_Timescale* _con_x821 = kk_std_time_instant__as_Timescale(_x_12, _ctx);
      kk_std_time_instant__timescale_dup(_x_12, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x822 = kk_std_time_instant__as_Timescale(_x_12, _ctx);
        kk_string_t _x_7 = _con_x822->name;
        kk_string_t _pat_0_8 = _con_x822->unit;
        kk_function_t _pat_1_7 = _con_x822->from_tai;
        kk_function_t _pat_2_6 = _con_x822->to_tai;
        kk_std_core_types__maybe _pat_3_6 = _con_x822->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_5 = _con_x822->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_5 = _con_x822->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_12, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_6, _ctx);
          kk_function_drop(_pat_2_6, _ctx);
          kk_function_drop(_pat_1_7, _ctx);
          kk_string_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(_x_12, _ctx);
        }
        else {
          kk_string_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(_x_12, _ctx);
        }
        _x_x819 = _x_7; /*string*/
      }
    }
    _match_x380 = kk_string_is_eq(_x_x815,_x_x819,kk_context()); /*bool*/
    if (_match_x380) {
      kk_std_time_instant__instant_drop(i, _ctx);
      return i_1_10076;
    }
    {
      kk_std_time_timestamp__timestamp _x_x823;
      bool _match_x381;
      kk_string_t _x_x824;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_0 = i_1_10076.since;
        kk_std_time_instant__timescale _x_9_1 = i_1_10076.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x825 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x826 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_1, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x827 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
          kk_string_t _x_13 = _con_x827->name;
          kk_string_t _pat_0_15 = _con_x827->unit;
          kk_function_t _pat_1_13 = _con_x827->from_tai;
          kk_function_t _pat_2_11 = _con_x827->to_tai;
          kk_std_core_types__maybe _pat_3_11 = _con_x827->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_9 = _con_x827->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_10 = _con_x827->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9_1, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_10, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_9, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_11, _ctx);
            kk_function_drop(_pat_2_11, _ctx);
            kk_function_drop(_pat_1_13, _ctx);
            kk_string_drop(_pat_0_15, _ctx);
            kk_datatype_ptr_free(_x_9_1, _ctx);
          }
          else {
            kk_string_dup(_x_13, _ctx);
            kk_datatype_ptr_decref(_x_9_1, _ctx);
          }
          _x_x824 = _x_13; /*string*/
        }
      }
      kk_string_t _x_x828;
      {
        kk_std_time_timestamp__timestamp _pat_0_14_0 = i.since;
        kk_std_time_instant__timescale _x_12_0 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x829 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x830 = kk_std_time_instant__as_Timescale(_x_12_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_12_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x831 = kk_std_time_instant__as_Timescale(_x_12_0, _ctx);
          kk_string_t _x_0_2 = _con_x831->name;
          kk_string_t _pat_0_0_2 = _con_x831->unit;
          kk_function_t _pat_1_0_2 = _con_x831->from_tai;
          kk_function_t _pat_2_0_2 = _con_x831->to_tai;
          kk_std_core_types__maybe _pat_3_0_1 = _con_x831->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_0_1 = _con_x831->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_0_1 = _con_x831->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_12_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_0_1, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_0_1, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_0_1, _ctx);
            kk_function_drop(_pat_2_0_2, _ctx);
            kk_function_drop(_pat_1_0_2, _ctx);
            kk_string_drop(_pat_0_0_2, _ctx);
            kk_datatype_ptr_free(_x_12_0, _ctx);
          }
          else {
            kk_string_dup(_x_0_2, _ctx);
            kk_datatype_ptr_decref(_x_12_0, _ctx);
          }
          _x_x828 = _x_0_2; /*string*/
        }
      }
      _match_x381 = kk_string_is_eq(_x_x824,_x_x828,kk_context()); /*bool*/
      if (_match_x381) {
        kk_std_time_timestamp__timestamp _x_8_0 = i_1_10076.since;
        kk_std_time_instant__timescale _pat_2_9_0 = i_1_10076.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x832 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x833 = kk_std_time_instant__as_Timescale(_pat_2_9_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_8_0, _ctx);
        kk_std_time_instant__instant_drop(i_1_10076, _ctx);
        _x_x823 = _x_8_0; /*std/time/timestamp/timestamp*/
      }
      else {
        bool _match_x382;
        kk_string_t _x_x834;
        {
          kk_std_time_timestamp__timestamp _pat_0_10_0_0 = i_1_10076.since;
          kk_std_time_instant__timescale _x_9_0_0 = i_1_10076.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x835 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x836 = kk_std_time_instant__as_Timescale(_x_9_0_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_9_0_0, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x837 = kk_std_time_instant__as_Timescale(_x_9_0_0, _ctx);
            kk_string_t _pat_0_2_1 = _con_x837->name;
            kk_string_t _x_1_1 = _con_x837->unit;
            kk_function_t _pat_1_1_1 = _con_x837->from_tai;
            kk_function_t _pat_2_1_1 = _con_x837->to_tai;
            kk_std_core_types__maybe _pat_3_1_1 = _con_x837->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_1_1 = _con_x837->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_1_1 = _con_x837->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_9_0_0, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_1_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_1_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_1_1, _ctx);
              kk_function_drop(_pat_2_1_1, _ctx);
              kk_function_drop(_pat_1_1_1, _ctx);
              kk_string_drop(_pat_0_2_1, _ctx);
              kk_datatype_ptr_free(_x_9_0_0, _ctx);
            }
            else {
              kk_string_dup(_x_1_1, _ctx);
              kk_datatype_ptr_decref(_x_9_0_0, _ctx);
            }
            _x_x834 = _x_1_1; /*string*/
          }
        }
        kk_string_t _x_x838;
        {
          kk_std_time_timestamp__timestamp _pat_0_14_0_0 = i.since;
          kk_std_time_instant__timescale _x_12_0_0 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x839 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x840 = kk_std_time_instant__as_Timescale(_x_12_0_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_12_0_0, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x841 = kk_std_time_instant__as_Timescale(_x_12_0_0, _ctx);
            kk_string_t _pat_0_3_0 = _con_x841->name;
            kk_string_t _x_2_1 = _con_x841->unit;
            kk_function_t _pat_1_2_1 = _con_x841->from_tai;
            kk_function_t _pat_2_2_1 = _con_x841->to_tai;
            kk_std_core_types__maybe _pat_3_2_1 = _con_x841->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_2_0 = _con_x841->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_2_0 = _con_x841->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_0, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_2_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_2_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_2_1, _ctx);
              kk_function_drop(_pat_2_2_1, _ctx);
              kk_function_drop(_pat_1_2_1, _ctx);
              kk_string_drop(_pat_0_3_0, _ctx);
              kk_datatype_ptr_free(_x_12_0_0, _ctx);
            }
            else {
              kk_string_dup(_x_2_1, _ctx);
              kk_datatype_ptr_decref(_x_12_0_0, _ctx);
            }
            _x_x838 = _x_2_1; /*string*/
          }
        }
        _match_x382 = kk_string_is_eq(_x_x834,_x_x838,kk_context()); /*bool*/
        if (_match_x382) {
          bool _match_x383;
          kk_string_t _x_x842;
          {
            kk_std_time_timestamp__timestamp _pat_0_10_1 = i_1_10076.since;
            kk_std_time_instant__timescale _x_9_1_0 = i_1_10076.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x843 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_1, _ctx);
            struct kk_std_time_instant_Timescale* _con_x844 = kk_std_time_instant__as_Timescale(_x_9_1_0, _ctx);
            kk_std_time_instant__timescale_dup(_x_9_1_0, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x845 = kk_std_time_instant__as_Timescale(_x_9_1_0, _ctx);
              kk_string_t _pat_0_4_0 = _con_x845->name;
              kk_string_t _x_3_0 = _con_x845->unit;
              kk_function_t _pat_1_4_0 = _con_x845->from_tai;
              kk_function_t _pat_2_3_0 = _con_x845->to_tai;
              kk_std_core_types__maybe _pat_3_3_0 = _con_x845->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_3_1 = _con_x845->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_3_1 = _con_x845->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_9_1_0, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_3_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_3_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_3_0, _ctx);
                kk_function_drop(_pat_2_3_0, _ctx);
                kk_function_drop(_pat_1_4_0, _ctx);
                kk_string_drop(_pat_0_4_0, _ctx);
                kk_datatype_ptr_free(_x_9_1_0, _ctx);
              }
              else {
                kk_string_dup(_x_3_0, _ctx);
                kk_datatype_ptr_decref(_x_9_1_0, _ctx);
              }
              _x_x842 = _x_3_0; /*string*/
            }
          }
          kk_string_t _x_x846;
          kk_define_string_literal(, _s_x847, 3, "UTC", _ctx)
          _x_x846 = kk_string_dup(_s_x847, _ctx); /*string*/
          _match_x383 = kk_string_is_eq(_x_x842,_x_x846,kk_context()); /*bool*/
          if (_match_x383) {
            kk_std_time_timestamp__timestamp _x_8_0_0 = i_1_10076.since;
            kk_std_time_instant__timescale _pat_2_9_0_0 = i_1_10076.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x848 = kk_std_time_timestamp__as_Timestamp(_x_8_0_0, _ctx);
            struct kk_std_time_instant_Timescale* _con_x849 = kk_std_time_instant__as_Timescale(_pat_2_9_0_0, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_8_0_0, _ctx);
            kk_std_time_instant__instant_drop(i_1_10076, _ctx);
            _x_x823 = _x_8_0_0; /*std/time/timestamp/timestamp*/
          }
          else {
            kk_std_time_duration__duration _norm_x10280;
            {
              kk_std_time_timestamp__timestamp _pat_0_10_2 = i_1_10076.since;
              kk_std_time_instant__timescale _x_9_2 = i_1_10076.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x850 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_2, _ctx);
              struct kk_std_time_instant_Timescale* _con_x851 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
              kk_std_time_instant__timescale_dup(_x_9_2, _ctx);
              {
                struct kk_std_time_instant_Timescale* _con_x852 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
                kk_string_t _pat_0_6_1 = _con_x852->name;
                kk_string_t _pat_1_6_0 = _con_x852->unit;
                kk_function_t _pat_2_5_0 = _con_x852->from_tai;
                kk_function_t _x_5_1 = _con_x852->to_tai;
                kk_std_core_types__maybe _pat_3_6_0 = _con_x852->mb_seconds_in_day;
                kk_std_core_types__maybe _pat_4_6_1 = _con_x852->mb_to_mjd2000;
                kk_std_core_types__maybe _pat_5_5_0 = _con_x852->mb_from_mjd2000;
                if kk_likely(kk_datatype_ptr_is_unique(_x_9_2, _ctx)) {
                  kk_std_core_types__maybe_drop(_pat_5_5_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_4_6_1, _ctx);
                  kk_std_core_types__maybe_drop(_pat_3_6_0, _ctx);
                  kk_function_drop(_pat_2_5_0, _ctx);
                  kk_string_drop(_pat_1_6_0, _ctx);
                  kk_string_drop(_pat_0_6_1, _ctx);
                  kk_datatype_ptr_free(_x_9_2, _ctx);
                }
                else {
                  kk_function_dup(_x_5_1, _ctx);
                  kk_datatype_ptr_decref(_x_9_2, _ctx);
                }
                kk_std_time_timestamp__timestamp _x_x853;
                {
                  kk_std_time_timestamp__timestamp _x_8_1 = i_1_10076.since;
                  kk_std_time_instant__timescale _pat_2_9_1 = i_1_10076.ts;
                  struct kk_std_time_timestamp_Timestamp* _con_x854 = kk_std_time_timestamp__as_Timestamp(_x_8_1, _ctx);
                  struct kk_std_time_instant_Timescale* _con_x855 = kk_std_time_instant__as_Timescale(_pat_2_9_1, _ctx);
                  kk_std_time_timestamp__timestamp_dup(_x_8_1, _ctx);
                  kk_std_time_instant__instant_drop(i_1_10076, _ctx);
                  _x_x853 = _x_8_1; /*std/time/timestamp/timestamp*/
                }
                _norm_x10280 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5_1, (_x_5_1, _x_x853, _ctx), _ctx); /*std/time/duration/duration*/
              }
            }
            {
              kk_std_time_timestamp__timestamp _pat_0_14_0_1 = i.since;
              kk_std_time_instant__timescale _x_12_0_1 = i.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x856 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_1, _ctx);
              struct kk_std_time_instant_Timescale* _con_x857 = kk_std_time_instant__as_Timescale(_x_12_0_1, _ctx);
              kk_std_time_instant__timescale_dup(_x_12_0_1, _ctx);
              {
                struct kk_std_time_instant_Timescale* _con_x858 = kk_std_time_instant__as_Timescale(_x_12_0_1, _ctx);
                kk_string_t _pat_0_5_0 = _con_x858->name;
                kk_string_t _pat_1_5_1 = _con_x858->unit;
                kk_function_t _x_4_0 = _con_x858->from_tai;
                kk_function_t _pat_2_4_1 = _con_x858->to_tai;
                kk_std_core_types__maybe _pat_3_5_0 = _con_x858->mb_seconds_in_day;
                kk_std_core_types__maybe _pat_4_5_0 = _con_x858->mb_to_mjd2000;
                kk_std_core_types__maybe _pat_5_4_0 = _con_x858->mb_from_mjd2000;
                if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_1, _ctx)) {
                  kk_std_core_types__maybe_drop(_pat_5_4_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_4_5_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_3_5_0, _ctx);
                  kk_function_drop(_pat_2_4_1, _ctx);
                  kk_string_drop(_pat_1_5_1, _ctx);
                  kk_string_drop(_pat_0_5_0, _ctx);
                  kk_datatype_ptr_free(_x_12_0_1, _ctx);
                }
                else {
                  kk_function_dup(_x_4_0, _ctx);
                  kk_datatype_ptr_decref(_x_12_0_1, _ctx);
                }
                _x_x823 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4_0, (_x_4_0, _norm_x10280, _ctx), _ctx); /*std/time/timestamp/timestamp*/
              }
            }
          }
        }
        else {
          kk_std_time_duration__duration _norm_x10281;
          {
            kk_std_time_timestamp__timestamp _pat_0_10_3 = i_1_10076.since;
            kk_std_time_instant__timescale _x_9_3 = i_1_10076.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x859 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_3, _ctx);
            struct kk_std_time_instant_Timescale* _con_x860 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
            kk_std_time_instant__timescale_dup(_x_9_3, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x861 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
              kk_string_t _pat_0_8_0 = _con_x861->name;
              kk_string_t _pat_1_8_0 = _con_x861->unit;
              kk_function_t _pat_2_8_1 = _con_x861->from_tai;
              kk_function_t _x_7_0 = _con_x861->to_tai;
              kk_std_core_types__maybe _pat_3_8_1 = _con_x861->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_8_0 = _con_x861->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_7_0 = _con_x861->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_9_3, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_7_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_8_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_8_1, _ctx);
                kk_function_drop(_pat_2_8_1, _ctx);
                kk_string_drop(_pat_1_8_0, _ctx);
                kk_string_drop(_pat_0_8_0, _ctx);
                kk_datatype_ptr_free(_x_9_3, _ctx);
              }
              else {
                kk_function_dup(_x_7_0, _ctx);
                kk_datatype_ptr_decref(_x_9_3, _ctx);
              }
              kk_std_time_timestamp__timestamp _x_x862;
              {
                kk_std_time_timestamp__timestamp _x_8_2 = i_1_10076.since;
                kk_std_time_instant__timescale _pat_2_9_2 = i_1_10076.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x863 = kk_std_time_timestamp__as_Timestamp(_x_8_2, _ctx);
                struct kk_std_time_instant_Timescale* _con_x864 = kk_std_time_instant__as_Timescale(_pat_2_9_2, _ctx);
                kk_std_time_timestamp__timestamp_dup(_x_8_2, _ctx);
                kk_std_time_instant__instant_drop(i_1_10076, _ctx);
                _x_x862 = _x_8_2; /*std/time/timestamp/timestamp*/
              }
              _norm_x10281 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7_0, (_x_7_0, _x_x862, _ctx), _ctx); /*std/time/duration/duration*/
            }
          }
          {
            kk_std_time_timestamp__timestamp _pat_0_14_0_2 = i.since;
            kk_std_time_instant__timescale _x_12_0_2 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x865 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_2, _ctx);
            struct kk_std_time_instant_Timescale* _con_x866 = kk_std_time_instant__as_Timescale(_x_12_0_2, _ctx);
            kk_std_time_instant__timescale_dup(_x_12_0_2, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x867 = kk_std_time_instant__as_Timescale(_x_12_0_2, _ctx);
              kk_string_t _pat_0_7_0 = _con_x867->name;
              kk_string_t _pat_1_7_0 = _con_x867->unit;
              kk_function_t _x_6_0 = _con_x867->from_tai;
              kk_function_t _pat_2_7_0 = _con_x867->to_tai;
              kk_std_core_types__maybe _pat_3_7_0 = _con_x867->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_7_0 = _con_x867->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_6_1 = _con_x867->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_2, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_6_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_7_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_7_0, _ctx);
                kk_function_drop(_pat_2_7_0, _ctx);
                kk_string_drop(_pat_1_7_0, _ctx);
                kk_string_drop(_pat_0_7_0, _ctx);
                kk_datatype_ptr_free(_x_12_0_2, _ctx);
              }
              else {
                kk_function_dup(_x_6_0, _ctx);
                kk_datatype_ptr_decref(_x_12_0_2, _ctx);
              }
              _x_x823 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6_0, (_x_6_0, _norm_x10281, _ctx), _ctx); /*std/time/timestamp/timestamp*/
            }
          }
        }
      }
      kk_std_time_instant__timescale _x_x868;
      {
        kk_std_time_timestamp__timestamp _pat_0_14_1 = i.since;
        kk_std_time_instant__timescale _x_12_1 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x869 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x870 = kk_std_time_instant__as_Timescale(_x_12_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_12_1, _ctx);
        kk_std_time_instant__instant_drop(i, _ctx);
        _x_x868 = _x_12_1; /*std/time/instant/timescale*/
      }
      return kk_std_time_instant__new_Instant(_x_x823, _x_x868, _ctx);
    }
  }
}
 
// Return the duration between to instants in time.

kk_std_time_duration__duration kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10094;
  kk_std_time_instant__timescale _x_x873 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_10094 = kk_std_time_instant_timestamp_in(i, _x_x873, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration d_10091;
  kk_std_num_ddouble__ddouble _x_x874 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10094, _ctx); /*std/time/timestamp/timespan*/
  d_10091 = kk_std_time_duration__new_Duration(_x_x874, _ctx); /*std/time/duration/duration*/
  kk_std_time_timestamp__timestamp t_0_10096;
  kk_std_time_instant__timescale _x_x875 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_0_10096 = kk_std_time_instant_timestamp_in(j, _x_x875, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration e_10092;
  kk_std_num_ddouble__ddouble _x_x876 = kk_std_time_timestamp_unsafe_timespan_withleap(t_0_10096, _ctx); /*std/time/timestamp/timespan*/
  e_10092 = kk_std_time_duration__new_Duration(_x_x876, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e_0_10055;
  kk_std_num_ddouble__ddouble _x_x877;
  double _x_x878;
  double _x_x879;
  {
    kk_std_num_ddouble__ddouble _x_1 = e_10092.secs;
    {
      double _x = _x_1.hi;
      _x_x879 = _x; /*float64*/
    }
  }
  _x_x878 = (-_x_x879); /*float64*/
  double _x_x880;
  double _x_x881;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = e_10092.secs;
    {
      double _x_0 = _x_1_0.lo;
      _x_x881 = _x_0; /*float64*/
    }
  }
  _x_x880 = (-_x_x881); /*float64*/
  _x_x877 = kk_std_num_ddouble__new_Ddouble(_x_x878, _x_x880, _ctx); /*std/num/ddouble/ddouble*/
  e_0_10055 = kk_std_time_duration__new_Duration(_x_x877, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x882;
  kk_std_num_ddouble__ddouble _x_x883;
  {
    kk_std_num_ddouble__ddouble _x_2 = d_10091.secs;
    _x_x883 = _x_2; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x884;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = e_0_10055.secs;
    _x_x884 = _x_0_0; /*std/time/timestamp/timespan*/
  }
  _x_x882 = kk_std_num_ddouble__lp__plus__rp_(_x_x883, _x_x884, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x882, _ctx);
}
 
// Subtract a duration from an instant in time.

kk_std_time_instant__instant kk_std_time_instant_duration_fs__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_0_10287;
  kk_std_num_ddouble__ddouble _x_x885;
  double _x_x886;
  double _x_x887;
  {
    kk_std_num_ddouble__ddouble _x_1_1 = d.secs;
    {
      double _x_13 = _x_1_1.hi;
      _x_x887 = _x_13; /*float64*/
    }
  }
  _x_x886 = (-_x_x887); /*float64*/
  double _x_x888;
  double _x_x889;
  {
    kk_std_num_ddouble__ddouble _x_1_0_0 = d.secs;
    {
      double _x_0_2 = _x_1_0_0.lo;
      _x_x889 = _x_0_2; /*float64*/
    }
  }
  _x_x888 = (-_x_x889); /*float64*/
  _x_x885 = kk_std_num_ddouble__new_Ddouble(_x_x886, _x_x888, _ctx); /*std/num/ddouble/ddouble*/
  d_0_10287 = kk_std_time_duration__new_Duration(_x_x885, _ctx); /*std/time/duration/duration*/
  bool _match_x373;
  kk_string_t _x_x890;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x891 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x892 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x893 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x893->name;
      kk_string_t _x = _con_x893->unit;
      kk_function_t _pat_1 = _con_x893->from_tai;
      kk_function_t _pat_2 = _con_x893->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x893->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x893->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x893->mb_from_mjd2000;
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
      _x_x890 = _x; /*string*/
    }
  }
  kk_string_t _x_x894;
  kk_define_string_literal(, _s_x895, 3, "TAI", _ctx)
  _x_x894 = kk_string_dup(_s_x895, _ctx); /*string*/
  _match_x373 = kk_string_is_eq(_x_x890,_x_x894,kk_context()); /*bool*/
  if (_match_x373) {
    kk_std_time_timestamp__timestamp _x_x896;
    kk_std_num_ddouble__ddouble _x_x897;
    kk_std_num_ddouble__ddouble _x_x898;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x899 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x900 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x901 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
        kk_std_num_ddouble__ddouble _x_1 = _con_x901->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
          kk_datatype_ptr_free(_x_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_2, _ctx);
        }
        _x_x898 = _x_1; /*std/time/timestamp/timespan*/
      }
    }
    kk_std_num_ddouble__ddouble _x_x902;
    {
      kk_std_num_ddouble__ddouble _x_4 = d_0_10287.secs;
      _x_x902 = _x_4; /*std/time/timestamp/timespan*/
    }
    _x_x897 = kk_std_num_ddouble__lp__plus__rp_(_x_x898, _x_x902, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x903;
    {
      kk_std_time_timestamp__timestamp _x_2_0 = i.since;
      kk_std_time_instant__timescale _pat_2_2_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x904 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x905 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x906 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x906->since;
        int32_t _x_0_0 = _con_x906->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2_0, _ctx)) {
          kk_datatype_ptr_free(_x_2_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_2_0, _ctx);
        }
        _x_x903 = _x_0_0; /*int32*/
      }
    }
    _x_x896 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x897, _x_x903, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x907;
    {
      kk_std_time_timestamp__timestamp _pat_0_3 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x908 = kk_std_time_timestamp__as_Timestamp(_pat_0_3, _ctx);
      struct kk_std_time_instant_Timescale* _con_x909 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x907 = _x_3; /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x896, _x_x907, _ctx);
  }
  {
    kk_std_time_instant__instant i_2_10078;
    bool _match_x378;
    kk_string_t _x_x910;
    {
      kk_std_time_timestamp__timestamp _pat_0_0_1 = i.since;
      kk_std_time_instant__timescale _x_0_1 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x911 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x912 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_1, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x913 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
        kk_string_t _x_5 = _con_x913->name;
        kk_string_t _pat_0_6 = _con_x913->unit;
        kk_function_t _pat_1_5 = _con_x913->from_tai;
        kk_function_t _pat_2_4 = _con_x913->to_tai;
        kk_std_core_types__maybe _pat_3_4 = _con_x913->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3 = _con_x913->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3 = _con_x913->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_4, _ctx);
          kk_function_drop(_pat_2_4, _ctx);
          kk_function_drop(_pat_1_5, _ctx);
          kk_string_drop(_pat_0_6, _ctx);
          kk_datatype_ptr_free(_x_0_1, _ctx);
        }
        else {
          kk_string_dup(_x_5, _ctx);
          kk_datatype_ptr_decref(_x_0_1, _ctx);
        }
        _x_x910 = _x_5; /*string*/
      }
    }
    kk_string_t _x_x914;
    kk_std_time_instant__timescale _x_x915 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
    {
      struct kk_std_time_instant_Timescale* _con_x916 = kk_std_time_instant__as_Timescale(_x_x915, _ctx);
      kk_string_t _x_1_0 = _con_x916->name;
      _x_x914 = kk_string_dup(_x_1_0, _ctx); /*string*/
    }
    _match_x378 = kk_string_is_eq(_x_x910,_x_x914,kk_context()); /*bool*/
    if (_match_x378) {
      i_2_10078 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    }
    else {
      kk_std_time_timestamp__timestamp _x_x917;
      kk_std_time_instant__instant _x_x918 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
      kk_std_time_instant__timescale _x_x919 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
      _x_x917 = kk_std_time_instant_timestamp_in(_x_x918, _x_x919, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x920 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
      i_2_10078 = kk_std_time_instant__new_Instant(_x_x917, _x_x920, _ctx); /*std/time/instant/instant*/
    }
    kk_std_time_instant__instant i_1_10076;
    kk_std_time_timestamp__timestamp _x_x921;
    kk_std_num_ddouble__ddouble _x_x922;
    kk_std_num_ddouble__ddouble _x_x923;
    {
      kk_std_time_timestamp__timestamp _x_9 = i_2_10078.since;
      kk_std_time_instant__timescale _pat_2_8 = i_2_10078.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x924 = kk_std_time_timestamp__as_Timestamp(_x_9, _ctx);
      struct kk_std_time_instant_Timescale* _con_x925 = kk_std_time_instant__as_Timescale(_pat_2_8, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_9, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x926 = kk_std_time_timestamp__as_Timestamp(_x_9, _ctx);
        kk_std_num_ddouble__ddouble _x_8 = _con_x926->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
          kk_datatype_ptr_free(_x_9, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_9, _ctx);
        }
        _x_x923 = _x_8; /*std/time/timestamp/timespan*/
      }
    }
    kk_std_num_ddouble__ddouble _x_x927;
    {
      kk_std_num_ddouble__ddouble _x_11 = d_0_10287.secs;
      _x_x927 = _x_11; /*std/time/timestamp/timespan*/
    }
    _x_x922 = kk_std_num_ddouble__lp__plus__rp_(_x_x923, _x_x927, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x928;
    {
      kk_std_time_timestamp__timestamp _x_9_0 = i_2_10078.since;
      kk_std_time_instant__timescale _pat_2_8_0 = i_2_10078.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x929 = kk_std_time_timestamp__as_Timestamp(_x_9_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x930 = kk_std_time_instant__as_Timescale(_pat_2_8_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_9_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x931 = kk_std_time_timestamp__as_Timestamp(_x_9_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_1_0 = _con_x931->since;
        int32_t _x_0_1_0 = _con_x931->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9_0, _ctx)) {
          kk_datatype_ptr_free(_x_9_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_9_0, _ctx);
        }
        _x_x928 = _x_0_1_0; /*int32*/
      }
    }
    _x_x921 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x922, _x_x928, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x932;
    {
      kk_std_time_timestamp__timestamp _pat_0_12 = i_2_10078.since;
      kk_std_time_instant__timescale _x_10 = i_2_10078.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x933 = kk_std_time_timestamp__as_Timestamp(_pat_0_12, _ctx);
      struct kk_std_time_instant_Timescale* _con_x934 = kk_std_time_instant__as_Timescale(_x_10, _ctx);
      kk_std_time_instant__timescale_dup(_x_10, _ctx);
      kk_std_time_instant__instant_drop(i_2_10078, _ctx);
      _x_x932 = _x_10; /*std/time/instant/timescale*/
    }
    i_1_10076 = kk_std_time_instant__new_Instant(_x_x921, _x_x932, _ctx); /*std/time/instant/instant*/
    bool _match_x374;
    kk_string_t _x_x935;
    {
      kk_std_time_timestamp__timestamp _pat_0_7 = i_1_10076.since;
      kk_std_time_instant__timescale _x_6 = i_1_10076.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x936 = kk_std_time_timestamp__as_Timestamp(_pat_0_7, _ctx);
      struct kk_std_time_instant_Timescale* _con_x937 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
      kk_std_time_instant__timescale_dup(_x_6, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x938 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
        kk_string_t _x_5_0 = _con_x938->name;
        kk_string_t _pat_0_6_0 = _con_x938->unit;
        kk_function_t _pat_1_5_0 = _con_x938->from_tai;
        kk_function_t _pat_2_4_0 = _con_x938->to_tai;
        kk_std_core_types__maybe _pat_3_4_0 = _con_x938->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3_0 = _con_x938->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3_0 = _con_x938->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_6, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_3_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_3_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_4_0, _ctx);
          kk_function_drop(_pat_2_4_0, _ctx);
          kk_function_drop(_pat_1_5_0, _ctx);
          kk_string_drop(_pat_0_6_0, _ctx);
          kk_datatype_ptr_free(_x_6, _ctx);
        }
        else {
          kk_string_dup(_x_5_0, _ctx);
          kk_datatype_ptr_decref(_x_6, _ctx);
        }
        _x_x935 = _x_5_0; /*string*/
      }
    }
    kk_string_t _x_x939;
    {
      kk_std_time_timestamp__timestamp _pat_0_14 = i.since;
      kk_std_time_instant__timescale _x_12 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x940 = kk_std_time_timestamp__as_Timestamp(_pat_0_14, _ctx);
      struct kk_std_time_instant_Timescale* _con_x941 = kk_std_time_instant__as_Timescale(_x_12, _ctx);
      kk_std_time_instant__timescale_dup(_x_12, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x942 = kk_std_time_instant__as_Timescale(_x_12, _ctx);
        kk_string_t _x_7 = _con_x942->name;
        kk_string_t _pat_0_8 = _con_x942->unit;
        kk_function_t _pat_1_7 = _con_x942->from_tai;
        kk_function_t _pat_2_6 = _con_x942->to_tai;
        kk_std_core_types__maybe _pat_3_6 = _con_x942->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_5 = _con_x942->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_5 = _con_x942->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_12, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_6, _ctx);
          kk_function_drop(_pat_2_6, _ctx);
          kk_function_drop(_pat_1_7, _ctx);
          kk_string_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(_x_12, _ctx);
        }
        else {
          kk_string_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(_x_12, _ctx);
        }
        _x_x939 = _x_7; /*string*/
      }
    }
    _match_x374 = kk_string_is_eq(_x_x935,_x_x939,kk_context()); /*bool*/
    if (_match_x374) {
      kk_std_time_instant__instant_drop(i, _ctx);
      return i_1_10076;
    }
    {
      kk_std_time_timestamp__timestamp _x_x943;
      bool _match_x375;
      kk_string_t _x_x944;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_0 = i_1_10076.since;
        kk_std_time_instant__timescale _x_9_1 = i_1_10076.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x945 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x946 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_1, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x947 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
          kk_string_t _x_14 = _con_x947->name;
          kk_string_t _pat_0_16 = _con_x947->unit;
          kk_function_t _pat_1_14 = _con_x947->from_tai;
          kk_function_t _pat_2_12 = _con_x947->to_tai;
          kk_std_core_types__maybe _pat_3_11 = _con_x947->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_9 = _con_x947->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_10 = _con_x947->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9_1, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_10, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_9, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_11, _ctx);
            kk_function_drop(_pat_2_12, _ctx);
            kk_function_drop(_pat_1_14, _ctx);
            kk_string_drop(_pat_0_16, _ctx);
            kk_datatype_ptr_free(_x_9_1, _ctx);
          }
          else {
            kk_string_dup(_x_14, _ctx);
            kk_datatype_ptr_decref(_x_9_1, _ctx);
          }
          _x_x944 = _x_14; /*string*/
        }
      }
      kk_string_t _x_x948;
      {
        kk_std_time_timestamp__timestamp _pat_0_14_0 = i.since;
        kk_std_time_instant__timescale _x_12_0 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x949 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x950 = kk_std_time_instant__as_Timescale(_x_12_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_12_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x951 = kk_std_time_instant__as_Timescale(_x_12_0, _ctx);
          kk_string_t _x_0_3 = _con_x951->name;
          kk_string_t _pat_0_0_3 = _con_x951->unit;
          kk_function_t _pat_1_0_3 = _con_x951->from_tai;
          kk_function_t _pat_2_0_3 = _con_x951->to_tai;
          kk_std_core_types__maybe _pat_3_0_1 = _con_x951->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_0_1 = _con_x951->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_0_1 = _con_x951->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_12_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_0_1, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_0_1, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_0_1, _ctx);
            kk_function_drop(_pat_2_0_3, _ctx);
            kk_function_drop(_pat_1_0_3, _ctx);
            kk_string_drop(_pat_0_0_3, _ctx);
            kk_datatype_ptr_free(_x_12_0, _ctx);
          }
          else {
            kk_string_dup(_x_0_3, _ctx);
            kk_datatype_ptr_decref(_x_12_0, _ctx);
          }
          _x_x948 = _x_0_3; /*string*/
        }
      }
      _match_x375 = kk_string_is_eq(_x_x944,_x_x948,kk_context()); /*bool*/
      if (_match_x375) {
        kk_std_time_timestamp__timestamp _x_8_0 = i_1_10076.since;
        kk_std_time_instant__timescale _pat_2_9_0 = i_1_10076.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x952 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x953 = kk_std_time_instant__as_Timescale(_pat_2_9_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_8_0, _ctx);
        kk_std_time_instant__instant_drop(i_1_10076, _ctx);
        _x_x943 = _x_8_0; /*std/time/timestamp/timestamp*/
      }
      else {
        bool _match_x376;
        kk_string_t _x_x954;
        {
          kk_std_time_timestamp__timestamp _pat_0_10_0_0 = i_1_10076.since;
          kk_std_time_instant__timescale _x_9_0_0 = i_1_10076.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x955 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x956 = kk_std_time_instant__as_Timescale(_x_9_0_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_9_0_0, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x957 = kk_std_time_instant__as_Timescale(_x_9_0_0, _ctx);
            kk_string_t _pat_0_2_1 = _con_x957->name;
            kk_string_t _x_1_2 = _con_x957->unit;
            kk_function_t _pat_1_1_1 = _con_x957->from_tai;
            kk_function_t _pat_2_1_1 = _con_x957->to_tai;
            kk_std_core_types__maybe _pat_3_1_1 = _con_x957->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_1_1 = _con_x957->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_1_1 = _con_x957->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_9_0_0, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_1_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_1_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_1_1, _ctx);
              kk_function_drop(_pat_2_1_1, _ctx);
              kk_function_drop(_pat_1_1_1, _ctx);
              kk_string_drop(_pat_0_2_1, _ctx);
              kk_datatype_ptr_free(_x_9_0_0, _ctx);
            }
            else {
              kk_string_dup(_x_1_2, _ctx);
              kk_datatype_ptr_decref(_x_9_0_0, _ctx);
            }
            _x_x954 = _x_1_2; /*string*/
          }
        }
        kk_string_t _x_x958;
        {
          kk_std_time_timestamp__timestamp _pat_0_14_0_0 = i.since;
          kk_std_time_instant__timescale _x_12_0_0 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x959 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x960 = kk_std_time_instant__as_Timescale(_x_12_0_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_12_0_0, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x961 = kk_std_time_instant__as_Timescale(_x_12_0_0, _ctx);
            kk_string_t _pat_0_3_0 = _con_x961->name;
            kk_string_t _x_2_1 = _con_x961->unit;
            kk_function_t _pat_1_2_1 = _con_x961->from_tai;
            kk_function_t _pat_2_2_1 = _con_x961->to_tai;
            kk_std_core_types__maybe _pat_3_2_1 = _con_x961->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_2_0 = _con_x961->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_2_0 = _con_x961->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_0, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_2_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_2_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_2_1, _ctx);
              kk_function_drop(_pat_2_2_1, _ctx);
              kk_function_drop(_pat_1_2_1, _ctx);
              kk_string_drop(_pat_0_3_0, _ctx);
              kk_datatype_ptr_free(_x_12_0_0, _ctx);
            }
            else {
              kk_string_dup(_x_2_1, _ctx);
              kk_datatype_ptr_decref(_x_12_0_0, _ctx);
            }
            _x_x958 = _x_2_1; /*string*/
          }
        }
        _match_x376 = kk_string_is_eq(_x_x954,_x_x958,kk_context()); /*bool*/
        if (_match_x376) {
          bool _match_x377;
          kk_string_t _x_x962;
          {
            kk_std_time_timestamp__timestamp _pat_0_10_1 = i_1_10076.since;
            kk_std_time_instant__timescale _x_9_1_0 = i_1_10076.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x963 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_1, _ctx);
            struct kk_std_time_instant_Timescale* _con_x964 = kk_std_time_instant__as_Timescale(_x_9_1_0, _ctx);
            kk_std_time_instant__timescale_dup(_x_9_1_0, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x965 = kk_std_time_instant__as_Timescale(_x_9_1_0, _ctx);
              kk_string_t _pat_0_4_0 = _con_x965->name;
              kk_string_t _x_3_0 = _con_x965->unit;
              kk_function_t _pat_1_4_0 = _con_x965->from_tai;
              kk_function_t _pat_2_3_0 = _con_x965->to_tai;
              kk_std_core_types__maybe _pat_3_3_0 = _con_x965->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_3_1 = _con_x965->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_3_1 = _con_x965->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_9_1_0, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_3_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_3_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_3_0, _ctx);
                kk_function_drop(_pat_2_3_0, _ctx);
                kk_function_drop(_pat_1_4_0, _ctx);
                kk_string_drop(_pat_0_4_0, _ctx);
                kk_datatype_ptr_free(_x_9_1_0, _ctx);
              }
              else {
                kk_string_dup(_x_3_0, _ctx);
                kk_datatype_ptr_decref(_x_9_1_0, _ctx);
              }
              _x_x962 = _x_3_0; /*string*/
            }
          }
          kk_string_t _x_x966;
          kk_define_string_literal(, _s_x967, 3, "UTC", _ctx)
          _x_x966 = kk_string_dup(_s_x967, _ctx); /*string*/
          _match_x377 = kk_string_is_eq(_x_x962,_x_x966,kk_context()); /*bool*/
          if (_match_x377) {
            kk_std_time_timestamp__timestamp _x_8_0_0 = i_1_10076.since;
            kk_std_time_instant__timescale _pat_2_9_0_0 = i_1_10076.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x968 = kk_std_time_timestamp__as_Timestamp(_x_8_0_0, _ctx);
            struct kk_std_time_instant_Timescale* _con_x969 = kk_std_time_instant__as_Timescale(_pat_2_9_0_0, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_8_0_0, _ctx);
            kk_std_time_instant__instant_drop(i_1_10076, _ctx);
            _x_x943 = _x_8_0_0; /*std/time/timestamp/timestamp*/
          }
          else {
            kk_std_time_duration__duration _norm_x10280;
            {
              kk_std_time_timestamp__timestamp _pat_0_10_2 = i_1_10076.since;
              kk_std_time_instant__timescale _x_9_2 = i_1_10076.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x970 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_2, _ctx);
              struct kk_std_time_instant_Timescale* _con_x971 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
              kk_std_time_instant__timescale_dup(_x_9_2, _ctx);
              {
                struct kk_std_time_instant_Timescale* _con_x972 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
                kk_string_t _pat_0_6_1 = _con_x972->name;
                kk_string_t _pat_1_6_0 = _con_x972->unit;
                kk_function_t _pat_2_5_0 = _con_x972->from_tai;
                kk_function_t _x_5_1 = _con_x972->to_tai;
                kk_std_core_types__maybe _pat_3_6_0 = _con_x972->mb_seconds_in_day;
                kk_std_core_types__maybe _pat_4_6_1 = _con_x972->mb_to_mjd2000;
                kk_std_core_types__maybe _pat_5_5_0 = _con_x972->mb_from_mjd2000;
                if kk_likely(kk_datatype_ptr_is_unique(_x_9_2, _ctx)) {
                  kk_std_core_types__maybe_drop(_pat_5_5_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_4_6_1, _ctx);
                  kk_std_core_types__maybe_drop(_pat_3_6_0, _ctx);
                  kk_function_drop(_pat_2_5_0, _ctx);
                  kk_string_drop(_pat_1_6_0, _ctx);
                  kk_string_drop(_pat_0_6_1, _ctx);
                  kk_datatype_ptr_free(_x_9_2, _ctx);
                }
                else {
                  kk_function_dup(_x_5_1, _ctx);
                  kk_datatype_ptr_decref(_x_9_2, _ctx);
                }
                kk_std_time_timestamp__timestamp _x_x973;
                {
                  kk_std_time_timestamp__timestamp _x_8_1 = i_1_10076.since;
                  kk_std_time_instant__timescale _pat_2_9_1 = i_1_10076.ts;
                  struct kk_std_time_timestamp_Timestamp* _con_x974 = kk_std_time_timestamp__as_Timestamp(_x_8_1, _ctx);
                  struct kk_std_time_instant_Timescale* _con_x975 = kk_std_time_instant__as_Timescale(_pat_2_9_1, _ctx);
                  kk_std_time_timestamp__timestamp_dup(_x_8_1, _ctx);
                  kk_std_time_instant__instant_drop(i_1_10076, _ctx);
                  _x_x973 = _x_8_1; /*std/time/timestamp/timestamp*/
                }
                _norm_x10280 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5_1, (_x_5_1, _x_x973, _ctx), _ctx); /*std/time/duration/duration*/
              }
            }
            {
              kk_std_time_timestamp__timestamp _pat_0_14_0_1 = i.since;
              kk_std_time_instant__timescale _x_12_0_1 = i.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x976 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_1, _ctx);
              struct kk_std_time_instant_Timescale* _con_x977 = kk_std_time_instant__as_Timescale(_x_12_0_1, _ctx);
              kk_std_time_instant__timescale_dup(_x_12_0_1, _ctx);
              {
                struct kk_std_time_instant_Timescale* _con_x978 = kk_std_time_instant__as_Timescale(_x_12_0_1, _ctx);
                kk_string_t _pat_0_5_0 = _con_x978->name;
                kk_string_t _pat_1_5_1 = _con_x978->unit;
                kk_function_t _x_4_0 = _con_x978->from_tai;
                kk_function_t _pat_2_4_1 = _con_x978->to_tai;
                kk_std_core_types__maybe _pat_3_5_0 = _con_x978->mb_seconds_in_day;
                kk_std_core_types__maybe _pat_4_5_0 = _con_x978->mb_to_mjd2000;
                kk_std_core_types__maybe _pat_5_4_0 = _con_x978->mb_from_mjd2000;
                if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_1, _ctx)) {
                  kk_std_core_types__maybe_drop(_pat_5_4_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_4_5_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_3_5_0, _ctx);
                  kk_function_drop(_pat_2_4_1, _ctx);
                  kk_string_drop(_pat_1_5_1, _ctx);
                  kk_string_drop(_pat_0_5_0, _ctx);
                  kk_datatype_ptr_free(_x_12_0_1, _ctx);
                }
                else {
                  kk_function_dup(_x_4_0, _ctx);
                  kk_datatype_ptr_decref(_x_12_0_1, _ctx);
                }
                _x_x943 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4_0, (_x_4_0, _norm_x10280, _ctx), _ctx); /*std/time/timestamp/timestamp*/
              }
            }
          }
        }
        else {
          kk_std_time_duration__duration _norm_x10281;
          {
            kk_std_time_timestamp__timestamp _pat_0_10_3 = i_1_10076.since;
            kk_std_time_instant__timescale _x_9_3 = i_1_10076.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x979 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_3, _ctx);
            struct kk_std_time_instant_Timescale* _con_x980 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
            kk_std_time_instant__timescale_dup(_x_9_3, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x981 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
              kk_string_t _pat_0_8_0 = _con_x981->name;
              kk_string_t _pat_1_8_0 = _con_x981->unit;
              kk_function_t _pat_2_8_1 = _con_x981->from_tai;
              kk_function_t _x_7_0 = _con_x981->to_tai;
              kk_std_core_types__maybe _pat_3_8_1 = _con_x981->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_8_0 = _con_x981->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_7_0 = _con_x981->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_9_3, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_7_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_8_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_8_1, _ctx);
                kk_function_drop(_pat_2_8_1, _ctx);
                kk_string_drop(_pat_1_8_0, _ctx);
                kk_string_drop(_pat_0_8_0, _ctx);
                kk_datatype_ptr_free(_x_9_3, _ctx);
              }
              else {
                kk_function_dup(_x_7_0, _ctx);
                kk_datatype_ptr_decref(_x_9_3, _ctx);
              }
              kk_std_time_timestamp__timestamp _x_x982;
              {
                kk_std_time_timestamp__timestamp _x_8_2 = i_1_10076.since;
                kk_std_time_instant__timescale _pat_2_9_2 = i_1_10076.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x983 = kk_std_time_timestamp__as_Timestamp(_x_8_2, _ctx);
                struct kk_std_time_instant_Timescale* _con_x984 = kk_std_time_instant__as_Timescale(_pat_2_9_2, _ctx);
                kk_std_time_timestamp__timestamp_dup(_x_8_2, _ctx);
                kk_std_time_instant__instant_drop(i_1_10076, _ctx);
                _x_x982 = _x_8_2; /*std/time/timestamp/timestamp*/
              }
              _norm_x10281 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7_0, (_x_7_0, _x_x982, _ctx), _ctx); /*std/time/duration/duration*/
            }
          }
          {
            kk_std_time_timestamp__timestamp _pat_0_14_0_2 = i.since;
            kk_std_time_instant__timescale _x_12_0_2 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x985 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_2, _ctx);
            struct kk_std_time_instant_Timescale* _con_x986 = kk_std_time_instant__as_Timescale(_x_12_0_2, _ctx);
            kk_std_time_instant__timescale_dup(_x_12_0_2, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x987 = kk_std_time_instant__as_Timescale(_x_12_0_2, _ctx);
              kk_string_t _pat_0_7_0 = _con_x987->name;
              kk_string_t _pat_1_7_0 = _con_x987->unit;
              kk_function_t _x_6_0 = _con_x987->from_tai;
              kk_function_t _pat_2_7_0 = _con_x987->to_tai;
              kk_std_core_types__maybe _pat_3_7_0 = _con_x987->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_7_0 = _con_x987->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_6_1 = _con_x987->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_2, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_6_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_7_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_7_0, _ctx);
                kk_function_drop(_pat_2_7_0, _ctx);
                kk_string_drop(_pat_1_7_0, _ctx);
                kk_string_drop(_pat_0_7_0, _ctx);
                kk_datatype_ptr_free(_x_12_0_2, _ctx);
              }
              else {
                kk_function_dup(_x_6_0, _ctx);
                kk_datatype_ptr_decref(_x_12_0_2, _ctx);
              }
              _x_x943 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6_0, (_x_6_0, _norm_x10281, _ctx), _ctx); /*std/time/timestamp/timestamp*/
            }
          }
        }
      }
      kk_std_time_instant__timescale _x_x988;
      {
        kk_std_time_timestamp__timestamp _pat_0_14_1 = i.since;
        kk_std_time_instant__timescale _x_12_1 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x989 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x990 = kk_std_time_instant__as_Timescale(_x_12_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_12_1, _ctx);
        kk_std_time_instant__instant_drop(i, _ctx);
        _x_x988 = _x_12_1; /*std/time/instant/timescale*/
      }
      return kk_std_time_instant__new_Instant(_x_x943, _x_x988, _ctx);
    }
  }
}
 
// Compare two `:instant`s in time.

kk_std_core_types__order kk_std_time_instant_cmp(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> order */ 
  kk_std_time_instant__instant instant_0_10101;
  bool _match_x369;
  kk_string_t _x_x991;
  {
    kk_std_time_timestamp__timestamp _pat_0_11 = j.since;
    kk_std_time_instant__timescale _x_10 = j.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x992 = kk_std_time_timestamp__as_Timestamp(_pat_0_11, _ctx);
    struct kk_std_time_instant_Timescale* _con_x993 = kk_std_time_instant__as_Timescale(_x_10, _ctx);
    kk_std_time_instant__timescale_dup(_x_10, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x994 = kk_std_time_instant__as_Timescale(_x_10, _ctx);
      kk_string_t _x_9 = _con_x994->name;
      kk_string_t _pat_0_10 = _con_x994->unit;
      kk_function_t _pat_1_7 = _con_x994->from_tai;
      kk_function_t _pat_2_7 = _con_x994->to_tai;
      kk_std_core_types__maybe _pat_3_2 = _con_x994->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_2 = _con_x994->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_3 = _con_x994->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_10, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_2, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_2, _ctx);
        kk_function_drop(_pat_2_7, _ctx);
        kk_function_drop(_pat_1_7, _ctx);
        kk_string_drop(_pat_0_10, _ctx);
        kk_datatype_ptr_free(_x_10, _ctx);
      }
      else {
        kk_string_dup(_x_9, _ctx);
        kk_datatype_ptr_decref(_x_10, _ctx);
      }
      _x_x991 = _x_9; /*string*/
    }
  }
  kk_string_t _x_x995;
  {
    kk_std_time_timestamp__timestamp _pat_0_14 = i.since;
    kk_std_time_instant__timescale _x_12 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x996 = kk_std_time_timestamp__as_Timestamp(_pat_0_14, _ctx);
    struct kk_std_time_instant_Timescale* _con_x997 = kk_std_time_instant__as_Timescale(_x_12, _ctx);
    kk_std_time_instant__timescale_dup(_x_12, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x998 = kk_std_time_instant__as_Timescale(_x_12, _ctx);
      kk_string_t _x_11 = _con_x998->name;
      kk_string_t _pat_0_12 = _con_x998->unit;
      kk_function_t _pat_1_9 = _con_x998->from_tai;
      kk_function_t _pat_2_9 = _con_x998->to_tai;
      kk_std_core_types__maybe _pat_3_4 = _con_x998->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_4 = _con_x998->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_5 = _con_x998->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_12, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_4, _ctx);
        kk_function_drop(_pat_2_9, _ctx);
        kk_function_drop(_pat_1_9, _ctx);
        kk_string_drop(_pat_0_12, _ctx);
        kk_datatype_ptr_free(_x_12, _ctx);
      }
      else {
        kk_string_dup(_x_11, _ctx);
        kk_datatype_ptr_decref(_x_12, _ctx);
      }
      _x_x995 = _x_11; /*string*/
    }
  }
  _match_x369 = kk_string_is_eq(_x_x991,_x_x995,kk_context()); /*bool*/
  if (_match_x369) {
    instant_0_10101 = j; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x999;
    bool _match_x370;
    kk_string_t _x_x1000;
    {
      kk_std_time_timestamp__timestamp _pat_0_10_0 = j.since;
      kk_std_time_instant__timescale _x_9_0 = j.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1001 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1002 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_9_0, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x1003 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
        kk_string_t _x = _con_x1003->name;
        kk_string_t _pat_0 = _con_x1003->unit;
        kk_function_t _pat_1 = _con_x1003->from_tai;
        kk_function_t _pat_2 = _con_x1003->to_tai;
        kk_std_core_types__maybe _pat_3 = _con_x1003->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4 = _con_x1003->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5 = _con_x1003->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9_0, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5, _ctx);
          kk_std_core_types__maybe_drop(_pat_4, _ctx);
          kk_std_core_types__maybe_drop(_pat_3, _ctx);
          kk_function_drop(_pat_2, _ctx);
          kk_function_drop(_pat_1, _ctx);
          kk_string_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(_x_9_0, _ctx);
        }
        else {
          kk_string_dup(_x, _ctx);
          kk_datatype_ptr_decref(_x_9_0, _ctx);
        }
        _x_x1000 = _x; /*string*/
      }
    }
    kk_string_t _x_x1004;
    {
      kk_std_time_timestamp__timestamp _pat_0_14_0 = i.since;
      kk_std_time_instant__timescale _x_12_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1005 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1006 = kk_std_time_instant__as_Timescale(_x_12_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_12_0, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x1007 = kk_std_time_instant__as_Timescale(_x_12_0, _ctx);
        kk_string_t _x_0 = _con_x1007->name;
        kk_string_t _pat_0_0 = _con_x1007->unit;
        kk_function_t _pat_1_0 = _con_x1007->from_tai;
        kk_function_t _pat_2_0 = _con_x1007->to_tai;
        kk_std_core_types__maybe _pat_3_0 = _con_x1007->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_0 = _con_x1007->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_0 = _con_x1007->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_12_0, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_0, _ctx);
          kk_function_drop(_pat_2_0, _ctx);
          kk_function_drop(_pat_1_0, _ctx);
          kk_string_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(_x_12_0, _ctx);
        }
        else {
          kk_string_dup(_x_0, _ctx);
          kk_datatype_ptr_decref(_x_12_0, _ctx);
        }
        _x_x1004 = _x_0; /*string*/
      }
    }
    _match_x370 = kk_string_is_eq(_x_x1000,_x_x1004,kk_context()); /*bool*/
    if (_match_x370) {
      kk_std_time_timestamp__timestamp _x_8 = j.since;
      kk_std_time_instant__timescale _pat_2_9_0 = j.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1008 = kk_std_time_timestamp__as_Timestamp(_x_8, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1009 = kk_std_time_instant__as_Timescale(_pat_2_9_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_8, _ctx);
      kk_std_time_instant__instant_drop(j, _ctx);
      _x_x999 = _x_8; /*std/time/timestamp/timestamp*/
    }
    else {
      bool _match_x371;
      kk_string_t _x_x1010;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_0_0 = j.since;
        kk_std_time_instant__timescale _x_9_0_0 = j.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1011 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1012 = kk_std_time_instant__as_Timescale(_x_9_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_0_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1013 = kk_std_time_instant__as_Timescale(_x_9_0_0, _ctx);
          kk_string_t _pat_0_2 = _con_x1013->name;
          kk_string_t _x_1 = _con_x1013->unit;
          kk_function_t _pat_1_1 = _con_x1013->from_tai;
          kk_function_t _pat_2_1 = _con_x1013->to_tai;
          kk_std_core_types__maybe _pat_3_1 = _con_x1013->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_1 = _con_x1013->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_1 = _con_x1013->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_9_0_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
            kk_function_drop(_pat_2_1, _ctx);
            kk_function_drop(_pat_1_1, _ctx);
            kk_string_drop(_pat_0_2, _ctx);
            kk_datatype_ptr_free(_x_9_0_0, _ctx);
          }
          else {
            kk_string_dup(_x_1, _ctx);
            kk_datatype_ptr_decref(_x_9_0_0, _ctx);
          }
          _x_x1010 = _x_1; /*string*/
        }
      }
      kk_string_t _x_x1014;
      {
        kk_std_time_timestamp__timestamp _pat_0_14_0_0 = i.since;
        kk_std_time_instant__timescale _x_12_0_0 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1015 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1016 = kk_std_time_instant__as_Timescale(_x_12_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_12_0_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1017 = kk_std_time_instant__as_Timescale(_x_12_0_0, _ctx);
          kk_string_t _pat_0_3 = _con_x1017->name;
          kk_string_t _x_2 = _con_x1017->unit;
          kk_function_t _pat_1_2 = _con_x1017->from_tai;
          kk_function_t _pat_2_2 = _con_x1017->to_tai;
          kk_std_core_types__maybe _pat_3_2_0 = _con_x1017->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_2_0 = _con_x1017->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_2 = _con_x1017->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_2, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_2_0, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_2_0, _ctx);
            kk_function_drop(_pat_2_2, _ctx);
            kk_function_drop(_pat_1_2, _ctx);
            kk_string_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(_x_12_0_0, _ctx);
          }
          else {
            kk_string_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(_x_12_0_0, _ctx);
          }
          _x_x1014 = _x_2; /*string*/
        }
      }
      _match_x371 = kk_string_is_eq(_x_x1010,_x_x1014,kk_context()); /*bool*/
      if (_match_x371) {
        bool _match_x372;
        kk_string_t _x_x1018;
        {
          kk_std_time_timestamp__timestamp _pat_0_10_1 = j.since;
          kk_std_time_instant__timescale _x_9_1 = j.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1019 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_1, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1020 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
          kk_std_time_instant__timescale_dup(_x_9_1, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1021 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
            kk_string_t _pat_0_4 = _con_x1021->name;
            kk_string_t _x_3 = _con_x1021->unit;
            kk_function_t _pat_1_4 = _con_x1021->from_tai;
            kk_function_t _pat_2_3 = _con_x1021->to_tai;
            kk_std_core_types__maybe _pat_3_3_0 = _con_x1021->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_3_0 = _con_x1021->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_3_0 = _con_x1021->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_9_1, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_3_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_3_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_3_0, _ctx);
              kk_function_drop(_pat_2_3, _ctx);
              kk_function_drop(_pat_1_4, _ctx);
              kk_string_drop(_pat_0_4, _ctx);
              kk_datatype_ptr_free(_x_9_1, _ctx);
            }
            else {
              kk_string_dup(_x_3, _ctx);
              kk_datatype_ptr_decref(_x_9_1, _ctx);
            }
            _x_x1018 = _x_3; /*string*/
          }
        }
        kk_string_t _x_x1022;
        kk_define_string_literal(, _s_x1023, 3, "UTC", _ctx)
        _x_x1022 = kk_string_dup(_s_x1023, _ctx); /*string*/
        _match_x372 = kk_string_is_eq(_x_x1018,_x_x1022,kk_context()); /*bool*/
        if (_match_x372) {
          kk_std_time_timestamp__timestamp _x_8_0 = j.since;
          kk_std_time_instant__timescale _pat_2_9_0_0 = j.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1024 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1025 = kk_std_time_instant__as_Timescale(_pat_2_9_0_0, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_8_0, _ctx);
          kk_std_time_instant__instant_drop(j, _ctx);
          _x_x999 = _x_8_0; /*std/time/timestamp/timestamp*/
        }
        else {
          kk_std_time_duration__duration _norm_x10280;
          {
            kk_std_time_timestamp__timestamp _pat_0_10_2 = j.since;
            kk_std_time_instant__timescale _x_9_2 = j.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1026 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_2, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1027 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
            kk_std_time_instant__timescale_dup(_x_9_2, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x1028 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
              kk_string_t _pat_0_6 = _con_x1028->name;
              kk_string_t _pat_1_6 = _con_x1028->unit;
              kk_function_t _pat_2_5 = _con_x1028->from_tai;
              kk_function_t _x_5 = _con_x1028->to_tai;
              kk_std_core_types__maybe _pat_3_6 = _con_x1028->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_6 = _con_x1028->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_5_0 = _con_x1028->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_9_2, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_5_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_6, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_6, _ctx);
                kk_function_drop(_pat_2_5, _ctx);
                kk_string_drop(_pat_1_6, _ctx);
                kk_string_drop(_pat_0_6, _ctx);
                kk_datatype_ptr_free(_x_9_2, _ctx);
              }
              else {
                kk_function_dup(_x_5, _ctx);
                kk_datatype_ptr_decref(_x_9_2, _ctx);
              }
              kk_std_time_timestamp__timestamp _x_x1029;
              {
                kk_std_time_timestamp__timestamp _x_8_1 = j.since;
                kk_std_time_instant__timescale _pat_2_9_1 = j.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x1030 = kk_std_time_timestamp__as_Timestamp(_x_8_1, _ctx);
                struct kk_std_time_instant_Timescale* _con_x1031 = kk_std_time_instant__as_Timescale(_pat_2_9_1, _ctx);
                kk_std_time_timestamp__timestamp_dup(_x_8_1, _ctx);
                kk_std_time_instant__instant_drop(j, _ctx);
                _x_x1029 = _x_8_1; /*std/time/timestamp/timestamp*/
              }
              _norm_x10280 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5, (_x_5, _x_x1029, _ctx), _ctx); /*std/time/duration/duration*/
            }
          }
          {
            kk_std_time_timestamp__timestamp _pat_0_14_0_1 = i.since;
            kk_std_time_instant__timescale _x_12_0_1 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1032 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_1, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1033 = kk_std_time_instant__as_Timescale(_x_12_0_1, _ctx);
            kk_std_time_instant__timescale_dup(_x_12_0_1, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x1034 = kk_std_time_instant__as_Timescale(_x_12_0_1, _ctx);
              kk_string_t _pat_0_5 = _con_x1034->name;
              kk_string_t _pat_1_5 = _con_x1034->unit;
              kk_function_t _x_4 = _con_x1034->from_tai;
              kk_function_t _pat_2_4 = _con_x1034->to_tai;
              kk_std_core_types__maybe _pat_3_5_0 = _con_x1034->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_5_0 = _con_x1034->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_4_0 = _con_x1034->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_1, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_4_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_5_0, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_5_0, _ctx);
                kk_function_drop(_pat_2_4, _ctx);
                kk_string_drop(_pat_1_5, _ctx);
                kk_string_drop(_pat_0_5, _ctx);
                kk_datatype_ptr_free(_x_12_0_1, _ctx);
              }
              else {
                kk_function_dup(_x_4, _ctx);
                kk_datatype_ptr_decref(_x_12_0_1, _ctx);
              }
              _x_x999 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4, (_x_4, _norm_x10280, _ctx), _ctx); /*std/time/timestamp/timestamp*/
            }
          }
        }
      }
      else {
        kk_std_time_duration__duration _norm_x10281;
        {
          kk_std_time_timestamp__timestamp _pat_0_10_3 = j.since;
          kk_std_time_instant__timescale _x_9_3 = j.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1035 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_3, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1036 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
          kk_std_time_instant__timescale_dup(_x_9_3, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1037 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
            kk_string_t _pat_0_8 = _con_x1037->name;
            kk_string_t _pat_1_8_0 = _con_x1037->unit;
            kk_function_t _pat_2_8_0 = _con_x1037->from_tai;
            kk_function_t _x_7 = _con_x1037->to_tai;
            kk_std_core_types__maybe _pat_3_8 = _con_x1037->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_8 = _con_x1037->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_7 = _con_x1037->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_9_3, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_7, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_8, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_8, _ctx);
              kk_function_drop(_pat_2_8_0, _ctx);
              kk_string_drop(_pat_1_8_0, _ctx);
              kk_string_drop(_pat_0_8, _ctx);
              kk_datatype_ptr_free(_x_9_3, _ctx);
            }
            else {
              kk_function_dup(_x_7, _ctx);
              kk_datatype_ptr_decref(_x_9_3, _ctx);
            }
            kk_std_time_timestamp__timestamp _x_x1038;
            {
              kk_std_time_timestamp__timestamp _x_8_2 = j.since;
              kk_std_time_instant__timescale _pat_2_9_2 = j.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1039 = kk_std_time_timestamp__as_Timestamp(_x_8_2, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1040 = kk_std_time_instant__as_Timescale(_pat_2_9_2, _ctx);
              kk_std_time_timestamp__timestamp_dup(_x_8_2, _ctx);
              kk_std_time_instant__instant_drop(j, _ctx);
              _x_x1038 = _x_8_2; /*std/time/timestamp/timestamp*/
            }
            _norm_x10281 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7, (_x_7, _x_x1038, _ctx), _ctx); /*std/time/duration/duration*/
          }
        }
        {
          kk_std_time_timestamp__timestamp _pat_0_14_0_2 = i.since;
          kk_std_time_instant__timescale _x_12_0_2 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1041 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_0_2, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1042 = kk_std_time_instant__as_Timescale(_x_12_0_2, _ctx);
          kk_std_time_instant__timescale_dup(_x_12_0_2, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1043 = kk_std_time_instant__as_Timescale(_x_12_0_2, _ctx);
            kk_string_t _pat_0_7 = _con_x1043->name;
            kk_string_t _pat_1_7_0 = _con_x1043->unit;
            kk_function_t _x_6 = _con_x1043->from_tai;
            kk_function_t _pat_2_7_0 = _con_x1043->to_tai;
            kk_std_core_types__maybe _pat_3_7 = _con_x1043->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_7 = _con_x1043->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_6_0 = _con_x1043->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_12_0_2, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_6_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_7, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_7, _ctx);
              kk_function_drop(_pat_2_7_0, _ctx);
              kk_string_drop(_pat_1_7_0, _ctx);
              kk_string_drop(_pat_0_7, _ctx);
              kk_datatype_ptr_free(_x_12_0_2, _ctx);
            }
            else {
              kk_function_dup(_x_6, _ctx);
              kk_datatype_ptr_decref(_x_12_0_2, _ctx);
            }
            _x_x999 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6, (_x_6, _norm_x10281, _ctx), _ctx); /*std/time/timestamp/timestamp*/
          }
        }
      }
    }
    kk_std_time_instant__timescale _x_x1044;
    {
      kk_std_time_timestamp__timestamp _pat_0_14_1 = i.since;
      kk_std_time_instant__timescale _x_12_1 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1045 = kk_std_time_timestamp__as_Timestamp(_pat_0_14_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1046 = kk_std_time_instant__as_Timescale(_x_12_1, _ctx);
      kk_std_time_instant__timescale_dup(_x_12_1, _ctx);
      _x_x1044 = _x_12_1; /*std/time/instant/timescale*/
    }
    instant_0_10101 = kk_std_time_instant__new_Instant(_x_x999, _x_x1044, _ctx); /*std/time/instant/instant*/
  }
  kk_std_core_types__order _match_x364;
  kk_std_core_types__order _match_x368;
  double _x_x1047;
  {
    kk_std_time_timestamp__timestamp _x_7_0 = i.since;
    kk_std_time_instant__timescale _pat_2_5_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1048 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1049 = kk_std_time_instant__as_Timescale(_pat_2_5_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_7_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1050 = kk_std_time_timestamp__as_Timestamp(_x_7_0, _ctx);
      kk_std_num_ddouble__ddouble _x_3_0 = _con_x1050->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_7_0, _ctx)) {
        kk_datatype_ptr_free(_x_7_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_7_0, _ctx);
      }
      {
        double _x_13 = _x_3_0.hi;
        _x_x1047 = _x_13; /*float64*/
      }
    }
  }
  double _x_x1051;
  {
    kk_std_time_timestamp__timestamp _x_8_3 = instant_0_10101.since;
    kk_std_time_instant__timescale _pat_2_6_0 = instant_0_10101.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1052 = kk_std_time_timestamp__as_Timestamp(_x_8_3, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1053 = kk_std_time_instant__as_Timescale(_pat_2_6_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_8_3, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1054 = kk_std_time_timestamp__as_Timestamp(_x_8_3, _ctx);
      kk_std_num_ddouble__ddouble _x_4_0 = _con_x1054->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_8_3, _ctx)) {
        kk_datatype_ptr_free(_x_8_3, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_8_3, _ctx);
      }
      {
        double _x_0_0 = _x_4_0.hi;
        _x_x1051 = _x_0_0; /*float64*/
      }
    }
  }
  _match_x368 = kk_std_num_float64_cmp(_x_x1047, _x_x1051, _ctx); /*order*/
  if (kk_std_core_types__is_Eq(_match_x368, _ctx)) {
    double _x_x1055;
    {
      kk_std_time_timestamp__timestamp _x_7_0_0 = i.since;
      kk_std_time_instant__timescale _pat_2_5_0_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1056 = kk_std_time_timestamp__as_Timestamp(_x_7_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1057 = kk_std_time_instant__as_Timescale(_pat_2_5_0_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_7_0_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1058 = kk_std_time_timestamp__as_Timestamp(_x_7_0_0, _ctx);
        kk_std_num_ddouble__ddouble _x_3_0_0 = _con_x1058->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_7_0_0, _ctx)) {
          kk_datatype_ptr_free(_x_7_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_7_0_0, _ctx);
        }
        {
          double _x_1_0 = _x_3_0_0.lo;
          _x_x1055 = _x_1_0; /*float64*/
        }
      }
    }
    double _x_x1059;
    {
      kk_std_time_timestamp__timestamp _x_8_0_0 = instant_0_10101.since;
      kk_std_time_instant__timescale _pat_2_6_0_0 = instant_0_10101.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1060 = kk_std_time_timestamp__as_Timestamp(_x_8_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1061 = kk_std_time_instant__as_Timescale(_pat_2_6_0_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_8_0_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1062 = kk_std_time_timestamp__as_Timestamp(_x_8_0_0, _ctx);
        kk_std_num_ddouble__ddouble _x_4_0_0 = _con_x1062->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_8_0_0, _ctx)) {
          kk_datatype_ptr_free(_x_8_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_8_0_0, _ctx);
        }
        {
          double _x_2_0 = _x_4_0_0.lo;
          _x_x1059 = _x_2_0; /*float64*/
        }
      }
    }
    _match_x364 = kk_std_num_float64_cmp(_x_x1055, _x_x1059, _ctx); /*order*/
  }
  else {
    _match_x364 = _match_x368; /*order*/
  }
  if (kk_std_core_types__is_Eq(_match_x364, _ctx)) {
    kk_integer_t x_0_10008;
    int32_t _x_x1063;
    {
      kk_std_time_timestamp__timestamp _x_7_1 = i.since;
      kk_std_time_instant__timescale _pat_2_5_1 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1064 = kk_std_time_timestamp__as_Timestamp(_x_7_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1065 = kk_std_time_instant__as_Timescale(_pat_2_5_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_7_1, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1066 = kk_std_time_timestamp__as_Timestamp(_x_7_1, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_6_0 = _con_x1066->since;
        int32_t _x_5_0 = _con_x1066->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_7_1, _ctx)) {
          kk_datatype_ptr_free(_x_7_1, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_7_1, _ctx);
        }
        _x_x1063 = _x_5_0; /*int32*/
      }
    }
    x_0_10008 = kk_integer_from_int(_x_x1063,kk_context()); /*int*/
    kk_integer_t y_0_10009;
    int32_t _x_x1067;
    {
      kk_std_time_timestamp__timestamp _x_8_1_0 = instant_0_10101.since;
      kk_std_time_instant__timescale _pat_2_6_1 = instant_0_10101.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1068 = kk_std_time_timestamp__as_Timestamp(_x_8_1_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1069 = kk_std_time_instant__as_Timescale(_pat_2_6_1, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_8_1_0, _ctx);
      kk_std_time_instant__instant_drop(instant_0_10101, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x1070 = kk_std_time_timestamp__as_Timestamp(_x_8_1_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_7_0 = _con_x1070->since;
        int32_t _x_6_0 = _con_x1070->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_8_1_0, _ctx)) {
          kk_datatype_ptr_free(_x_8_1_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_8_1_0, _ctx);
        }
        _x_x1067 = _x_6_0; /*int32*/
      }
    }
    y_0_10009 = kk_integer_from_int(_x_x1067,kk_context()); /*int*/
    bool _match_x365 = kk_integer_eq_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
    if (_match_x365) {
      kk_integer_drop(y_0_10009, _ctx);
      kk_integer_drop(x_0_10008, _ctx);
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      bool _match_x366;
      bool _brw_x367 = kk_integer_gt_borrow(x_0_10008,y_0_10009,kk_context()); /*bool*/;
      kk_integer_drop(x_0_10008, _ctx);
      kk_integer_drop(y_0_10009, _ctx);
      _match_x366 = _brw_x367; /*bool*/
      if (_match_x366) {
        return kk_std_core_types__new_Gt(_ctx);
      }
      {
        return kk_std_core_types__new_Lt(_ctx);
      }
    }
  }
  {
    kk_std_time_instant__instant_drop(instant_0_10101, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    return _match_x364;
  }
}
 
// Are two timescales the same?

bool kk_std_time_instant_timescale_fs__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx) { /* (t1 : timescale, t2 : timescale) -> bool */ 
  kk_string_t _x_x1072;
  {
    struct kk_std_time_instant_Timescale* _con_x1073 = kk_std_time_instant__as_Timescale(t1, _ctx);
    kk_string_t _x = _con_x1073->name;
    kk_string_t _pat_0 = _con_x1073->unit;
    kk_function_t _pat_1 = _con_x1073->from_tai;
    kk_function_t _pat_2 = _con_x1073->to_tai;
    kk_std_core_types__maybe _pat_3 = _con_x1073->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4 = _con_x1073->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5 = _con_x1073->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(t1, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5, _ctx);
      kk_std_core_types__maybe_drop(_pat_4, _ctx);
      kk_std_core_types__maybe_drop(_pat_3, _ctx);
      kk_function_drop(_pat_2, _ctx);
      kk_function_drop(_pat_1, _ctx);
      kk_string_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(t1, _ctx);
    }
    else {
      kk_string_dup(_x, _ctx);
      kk_datatype_ptr_decref(t1, _ctx);
    }
    _x_x1072 = _x; /*string*/
  }
  kk_string_t _x_x1074;
  {
    struct kk_std_time_instant_Timescale* _con_x1075 = kk_std_time_instant__as_Timescale(t2, _ctx);
    kk_string_t _x_0 = _con_x1075->name;
    kk_string_t _pat_0_0 = _con_x1075->unit;
    kk_function_t _pat_1_0 = _con_x1075->from_tai;
    kk_function_t _pat_2_0 = _con_x1075->to_tai;
    kk_std_core_types__maybe _pat_3_0 = _con_x1075->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_0 = _con_x1075->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_0 = _con_x1075->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(t2, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_4_0, _ctx);
      kk_std_core_types__maybe_drop(_pat_3_0, _ctx);
      kk_function_drop(_pat_2_0, _ctx);
      kk_function_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(t2, _ctx);
    }
    else {
      kk_string_dup(_x_0, _ctx);
      kk_datatype_ptr_decref(t2, _ctx);
    }
    _x_x1074 = _x_0; /*string*/
  }
  return kk_string_is_eq(_x_x1072,_x_x1074,kk_context());
}
 
// Given a `:duration` since the `epoch`, return a `:timespan` for that instant in time scale `ts`.

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai(kk_std_time_instant__timescale ts, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp t_10112;
  kk_std_num_ddouble__ddouble _x_x1076;
  {
    kk_std_num_ddouble__ddouble _x_8 = d.secs;
    _x_x1076 = _x_8; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1077;
  kk_integer_t _x_x1078;
  kk_std_core_types__optional _match_x361 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x361, _ctx)) {
    kk_box_t _box_x46 = _match_x361._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x46, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x361, _ctx);
    _x_x1078 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x361, _ctx);
    _x_x1078 = kk_integer_from_small(0); /*int*/
  }
  _x_x1077 = kk_integer_clamp32(_x_x1078,kk_context()); /*int32*/
  t_10112 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1076, _x_x1077, _ctx); /*std/time/timestamp/timestamp*/
  bool _match_x358;
  kk_string_t _x_x1079;
  kk_std_time_instant__timescale _x_x1080 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  {
    struct kk_std_time_instant_Timescale* _con_x1081 = kk_std_time_instant__as_Timescale(_x_x1080, _ctx);
    kk_string_t _x = _con_x1081->name;
    _x_x1079 = kk_string_dup(_x, _ctx); /*string*/
  }
  kk_string_t _x_x1082;
  {
    struct kk_std_time_instant_Timescale* _con_x1083 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _x_0 = _con_x1083->name;
    kk_string_dup(_x_0, _ctx);
    _x_x1082 = _x_0; /*string*/
  }
  _match_x358 = kk_string_is_eq(_x_x1079,_x_x1082,kk_context()); /*bool*/
  if (_match_x358) {
    kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
    return t_10112;
  }
  {
    bool _match_x359;
    kk_string_t _x_x1084;
    kk_std_time_instant__timescale _x_x1085 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
    {
      struct kk_std_time_instant_Timescale* _con_x1086 = kk_std_time_instant__as_Timescale(_x_x1085, _ctx);
      kk_string_t _x_1 = _con_x1086->unit;
      _x_x1084 = kk_string_dup(_x_1, _ctx); /*string*/
    }
    kk_string_t _x_x1087;
    {
      struct kk_std_time_instant_Timescale* _con_x1088 = kk_std_time_instant__as_Timescale(ts, _ctx);
      kk_string_t _x_2 = _con_x1088->unit;
      kk_string_dup(_x_2, _ctx);
      _x_x1087 = _x_2; /*string*/
    }
    _match_x359 = kk_string_is_eq(_x_x1084,_x_x1087,kk_context()); /*bool*/
    if (_match_x359) {
      bool _match_x360;
      kk_string_t _x_x1089;
      kk_std_time_instant__timescale _x_x1090 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
      {
        struct kk_std_time_instant_Timescale* _con_x1091 = kk_std_time_instant__as_Timescale(_x_x1090, _ctx);
        kk_string_t _x_3 = _con_x1091->unit;
        _x_x1089 = kk_string_dup(_x_3, _ctx); /*string*/
      }
      kk_string_t _x_x1092;
      kk_define_string_literal(, _s_x1093, 3, "UTC", _ctx)
      _x_x1092 = kk_string_dup(_s_x1093, _ctx); /*string*/
      _match_x360 = kk_string_is_eq(_x_x1089,_x_x1092,kk_context()); /*bool*/
      if (_match_x360) {
        kk_datatype_ptr_dropn(ts, (KK_I32(10)), _ctx);
        return t_10112;
      }
      {
        kk_std_time_duration__duration _norm_x10282;
        kk_std_time_instant__timescale _x_x1094 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
        {
          struct kk_std_time_instant_Timescale* _con_x1095 = kk_std_time_instant__as_Timescale(_x_x1094, _ctx);
          kk_function_t _x_5 = _con_x1095->to_tai;
          kk_function_t _x_x1096 = kk_function_dup(_x_5, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
          _norm_x10282 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_x1096, (_x_x1096, t_10112, _ctx), _ctx); /*std/time/duration/duration*/
        }
        {
          struct kk_std_time_instant_Timescale* _con_x1097 = kk_std_time_instant__as_Timescale(ts, _ctx);
          kk_string_t _pat_0_5 = _con_x1097->name;
          kk_string_t _pat_1_5 = _con_x1097->unit;
          kk_function_t _x_4 = _con_x1097->from_tai;
          kk_function_t _pat_2_4 = _con_x1097->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x1097->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x1097->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_4 = _con_x1097->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_5, _ctx);
            kk_function_drop(_pat_2_4, _ctx);
            kk_string_drop(_pat_1_5, _ctx);
            kk_string_drop(_pat_0_5, _ctx);
            kk_datatype_ptr_free(ts, _ctx);
          }
          else {
            kk_function_dup(_x_4, _ctx);
            kk_datatype_ptr_decref(ts, _ctx);
          }
          return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4, (_x_4, _norm_x10282, _ctx), _ctx);
        }
      }
    }
    {
      kk_std_time_duration__duration _norm_x10283;
      kk_std_time_instant__timescale _x_x1098 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
      {
        struct kk_std_time_instant_Timescale* _con_x1099 = kk_std_time_instant__as_Timescale(_x_x1098, _ctx);
        kk_function_t _x_7 = _con_x1099->to_tai;
        kk_function_t _x_x1100 = kk_function_dup(_x_7, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
        _norm_x10283 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_x1100, (_x_x1100, t_10112, _ctx), _ctx); /*std/time/duration/duration*/
      }
      {
        struct kk_std_time_instant_Timescale* _con_x1101 = kk_std_time_instant__as_Timescale(ts, _ctx);
        kk_string_t _pat_0_7 = _con_x1101->name;
        kk_string_t _pat_1_7 = _con_x1101->unit;
        kk_function_t _x_6 = _con_x1101->from_tai;
        kk_function_t _pat_2_7 = _con_x1101->to_tai;
        kk_std_core_types__maybe _pat_3_7 = _con_x1101->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_7 = _con_x1101->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_6 = _con_x1101->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_6, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_7, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_7, _ctx);
          kk_function_drop(_pat_2_7, _ctx);
          kk_string_drop(_pat_1_7, _ctx);
          kk_string_drop(_pat_0_7, _ctx);
          kk_datatype_ptr_free(ts, _ctx);
        }
        else {
          kk_function_dup(_x_6, _ctx);
          kk_datatype_ptr_decref(ts, _ctx);
        }
        return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6, (_x_6, _norm_x10283, _ctx), _ctx);
      }
    }
  }
}
 
// Does this timescale have leap seconds?

bool kk_std_time_instant_has_leap_seconds(kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (ts : timescale) -> bool */ 
  {
    struct kk_std_time_instant_Timescale* _con_x1104 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _pat_0_0 = _con_x1104->name;
    kk_string_t _pat_1_0 = _con_x1104->unit;
    kk_function_t _pat_2_0 = _con_x1104->from_tai;
    kk_function_t _pat_3 = _con_x1104->to_tai;
    kk_std_core_types__maybe _x = _con_x1104->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4 = _con_x1104->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5 = _con_x1104->mb_from_mjd2000;
    if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
      kk_std_core_types__maybe_drop(_pat_5, _ctx);
      kk_std_core_types__maybe_drop(_pat_4, _ctx);
      kk_function_drop(_pat_3, _ctx);
      kk_function_drop(_pat_2_0, _ctx);
      kk_string_drop(_pat_1_0, _ctx);
      kk_string_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(ts, _ctx);
    }
    else {
      kk_std_core_types__maybe_dup(_x, _ctx);
      kk_datatype_ptr_decref(ts, _ctx);
    }
    if (kk_std_core_types__is_Just(_x, _ctx)) {
      kk_std_core_types__maybe_drop(_x, _ctx);
      return true;
    }
    {
      return false;
    }
  }
}

kk_std_time_instant__instant kk_std_time_instant_instant_fs__copy(kk_std_time_instant__instant _this, kk_std_core_types__optional since, kk_std_core_types__optional ts, kk_context_t* _ctx) { /* (instant, since : ? std/time/timestamp/timestamp, ts : ? timescale) -> instant */ 
  kk_std_time_timestamp__timestamp _x_x1105;
  if (kk_std_core_types__is_Optional(since, _ctx)) {
    kk_box_t _box_x54 = since._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_since_1832 = kk_std_time_timestamp__timestamp_unbox(_box_x54, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_since_1832, _ctx);
    kk_std_core_types__optional_drop(since, _ctx);
    _x_x1105 = _uniq_since_1832; /*std/time/timestamp/timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(since, _ctx);
    {
      kk_std_time_timestamp__timestamp _x = _this.since;
      kk_std_time_instant__timescale _pat_2 = _this.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1106 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1107 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x, _ctx);
      _x_x1105 = _x; /*std/time/timestamp/timestamp*/
    }
  }
  kk_std_time_instant__timescale _x_x1108;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x55 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_1840 = kk_std_time_instant__timescale_unbox(_box_x55, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_1840, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_time_instant__instant_drop(_this, _ctx);
    _x_x1108 = _uniq_ts_1840; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0_1 = _this.since;
      kk_std_time_instant__timescale _x_0 = _this.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1109 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1110 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0, _ctx);
      kk_std_time_instant__instant_drop(_this, _ctx);
      _x_x1108 = _x_0; /*std/time/instant/timescale*/
    }
  }
  return kk_std_time_instant__new_Instant(_x_x1105, _x_x1108, _ctx);
}
 
// The seconds in the day of instant `i` (in its time scale).

kk_std_num_ddouble__ddouble kk_std_time_instant_seconds_in_day(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/timestamp/timespan */ 
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1111 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1112 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1113 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x1113->name;
      kk_string_t _pat_1 = _con_x1113->unit;
      kk_function_t _pat_2 = _con_x1113->from_tai;
      kk_function_t _pat_3 = _con_x1113->to_tai;
      kk_std_core_types__maybe _x = _con_x1113->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x1113->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x1113->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_function_drop(_pat_2, _ctx);
        kk_string_drop(_pat_1, _ctx);
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_std_core_types__maybe_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      if (kk_std_core_types__is_Nothing(_x, _ctx)) {
        kk_std_time_instant__instant_drop(i, _ctx);
        return kk_std_time_timestamp_solar_secs_per_day;
      }
      {
        kk_box_t _fun_unbox_x59 = _x._cons.Just.value;
        kk_box_t _x_x1114;
        kk_function_t _x_x1119 = kk_function_unbox(_fun_unbox_x59, _ctx); /*(t : 60) -> 61*/
        kk_box_t _x_x1115;
        kk_std_time_timestamp__timestamp _x_x1116;
        {
          kk_std_time_timestamp__timestamp _x_1 = i.since;
          kk_std_time_instant__timescale _pat_2_1 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1117 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1118 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
          kk_std_time_instant__instant_drop(i, _ctx);
          _x_x1116 = _x_1; /*std/time/timestamp/timestamp*/
        }
        _x_x1115 = kk_std_time_timestamp__timestamp_box(_x_x1116, _ctx); /*60*/
        _x_x1114 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1119, (_x_x1119, _x_x1115, _ctx), _ctx); /*61*/
        return kk_std_num_ddouble__ddouble_unbox(_x_x1114, KK_OWNED, _ctx);
      }
    }
  }
}
 
// Return days since 2000-01-01 in the time scale of the instant

kk_integer_t kk_std_time_instant_days(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> int */ 
  kk_std_num_ddouble__ddouble secs;
  kk_std_num_ddouble__ddouble _x_x1120;
  {
    kk_std_time_timestamp__timestamp _x_0_1 = i.since;
    kk_std_time_instant__timescale _pat_2_1 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1121 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1122 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1123 = kk_std_time_timestamp__as_Timestamp(_x_0_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1123->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
        kk_datatype_ptr_free(_x_0_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0_1, _ctx);
      }
      _x_x1120 = _x; /*std/time/timestamp/timespan*/
    }
  }
  secs = kk_std_num_ddouble_floor(_x_x1120, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1124;
  {
    kk_std_time_timestamp__timestamp _x_0_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_1_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1125 = kk_std_time_timestamp__as_Timestamp(_x_0_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1126 = kk_std_time_instant__as_Timescale(_pat_2_1_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0_1_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1127 = kk_std_time_timestamp__as_Timestamp(_x_0_1_0, _ctx);
      kk_std_num_ddouble__ddouble _x_1 = _con_x1127->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_0_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_0_1_0, _ctx);
      }
      _x_x1124 = _x_1; /*std/time/timestamp/timespan*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1128;
  double _x_x1129;
  double _x_x1130;
  {
    double _x_0 = secs.hi;
    _x_x1130 = _x_0; /*float64*/
  }
  _x_x1129 = (-_x_x1130); /*float64*/
  double _x_x1131;
  double _x_x1132;
  {
    double _x_0_0 = secs.lo;
    _x_x1132 = _x_0_0; /*float64*/
  }
  _x_x1131 = (-_x_x1132); /*float64*/
  _x_x1128 = kk_std_num_ddouble__new_Ddouble(_x_x1129, _x_x1131, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(_x_x1124, _x_x1128, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_core_types__tuple2 tuple2_10075;
  kk_std_core_types__tuple2 _match_x357;
  kk_integer_t _x_x1133 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  _match_x357 = kk_std_core_int_divmod(_x_x1133, kk_integer_from_int(86400, _ctx), _ctx); /*(int, int)*/
  {
    kk_box_t _box_x63 = _match_x357.fst;
    kk_box_t _box_x64 = _match_x357.snd;
    kk_integer_t days_0 = kk_integer_unbox(_box_x63, _ctx);
    kk_integer_t dsecs = kk_integer_unbox(_box_x64, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_integer_dup(dsecs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x357, _ctx);
    kk_std_num_ddouble__ddouble _b_x66_68;
    kk_std_num_ddouble__ddouble _x_x1134 = kk_std_num_ddouble_ddouble_int_exp(dsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    _b_x66_68 = kk_std_num_ddouble__lp__plus__rp_(_x_x1134, frac, _ctx); /*std/num/ddouble/ddouble*/
    tuple2_10075 = kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_num_ddouble__ddouble_box(_b_x66_68, _ctx), _ctx); /*(int, std/num/ddouble/ddouble)*/
  }
  {
    kk_box_t _box_x69 = tuple2_10075.fst;
    kk_box_t _box_x70 = tuple2_10075.snd;
    kk_integer_t _x_2 = kk_integer_unbox(_box_x69, _ctx);
    kk_integer_dup(_x_2, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
    return _x_2;
  }
}
 
// Return the instant in time scale `ts`, `days` and `secs` after 2000-01-01 in that timescale.

kk_std_time_instant__instant kk_std_time_instant_date_fs_instant(kk_std_time_instant__timescale ts, kk_integer_t days_0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx) { /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : ? int) -> instant */ 
  kk_std_time_timestamp__timestamp t_10137;
  kk_std_core_types__optional _x_x1138 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1139;
  kk_box_t _x_x1140;
  kk_integer_t _x_x1141;
  if (kk_std_core_types__is_Optional(leap, _ctx)) {
    kk_box_t _box_x72 = leap._cons._Optional.value;
    kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x72, _ctx);
    kk_integer_dup(_uniq_leap_1920, _ctx);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x1141 = _uniq_leap_1920; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x1141 = kk_integer_from_small(0); /*int*/
  }
  _x_x1140 = kk_integer_box(_x_x1141, _ctx); /*10003*/
  _x_x1139 = kk_std_core_types__new_Optional(_x_x1140, _ctx); /*? 10003*/
  t_10137 = kk_std_time_timestamp_timestamp_days(days_0, _x_x1138, _x_x1139, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(t_10137, ts, _ctx);
}
 
// Return the instant at (TAI) SI seconds duration since the `epoch`.

kk_std_time_instant__instant kk_std_time_instant_duration_fs_instant(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : std/time/duration/duration) -> instant */ 
  kk_std_time_timestamp__timestamp t_10139;
  kk_std_num_ddouble__ddouble _x_x1142;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x1142 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1143;
  kk_integer_t _x_x1144;
  kk_std_core_types__optional _match_x356 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x356, _ctx)) {
    kk_box_t _box_x76 = _match_x356._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x76, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x356, _ctx);
    _x_x1144 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x356, _ctx);
    _x_x1144 = kk_integer_from_small(0); /*int*/
  }
  _x_x1143 = kk_integer_clamp32(_x_x1144,kk_context()); /*int32*/
  t_10139 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1142, _x_x1143, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1145 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10139, _x_x1145, _ctx);
}
 
// Round an instant to a certain precision (`prec` is number of digits of the fraction of the second).
// Takes special care for instants that use a UTC timescale to round into leap seconds if appropriate.

kk_std_time_instant__instant kk_std_time_instant_round_to_prec(kk_std_time_instant__instant i, kk_integer_t prec, kk_context_t* _ctx) { /* (i : instant, prec : int) -> instant */ 
  bool _match_x346 = kk_integer_lt_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x346) {
    kk_integer_drop(prec, _ctx);
    return i;
  }
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1146 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1147 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1148 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0_1 = _con_x1148->name;
      kk_string_t _pat_1_1 = _con_x1148->unit;
      kk_function_t _pat_2_0 = _con_x1148->from_tai;
      kk_function_t _pat_3 = _con_x1148->to_tai;
      kk_std_core_types__maybe _x = _con_x1148->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x1148->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x1148->mb_from_mjd2000;
      kk_reuse_t _ru_x533 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_reuse_t _x_x1149 = kk_datatype_ptr_dropn_reuse(_pat_2_0, (KK_I32(0)), _ctx); /*@reuse*/
        _ru_x533 = _x_x1149;
        kk_string_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_std_core_types__maybe_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      if (kk_std_core_types__is_Just(_x, _ctx)) {
        kk_std_core_types__maybe_drop(_x, _ctx);
        kk_std_time_instant__instant instant_1_10150;
        bool _match_x355;
        kk_string_t _x_x1150;
        {
          kk_std_time_timestamp__timestamp _pat_0_0_0 = i.since;
          kk_std_time_instant__timescale _x_0_0 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1151 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1152 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1153 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
            kk_string_t _x_1 = _con_x1153->name;
            kk_string_t _pat_0_3 = _con_x1153->unit;
            kk_function_t _pat_1_3 = _con_x1153->from_tai;
            kk_function_t _pat_2_2 = _con_x1153->to_tai;
            kk_std_core_types__maybe _pat_3_1 = _con_x1153->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_1 = _con_x1153->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_1 = _con_x1153->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
              kk_function_drop(_pat_2_2, _ctx);
              kk_function_drop(_pat_1_3, _ctx);
              kk_string_drop(_pat_0_3, _ctx);
              kk_datatype_ptr_free(_x_0_0, _ctx);
            }
            else {
              kk_string_dup(_x_1, _ctx);
              kk_datatype_ptr_decref(_x_0_0, _ctx);
            }
            _x_x1150 = _x_1; /*string*/
          }
        }
        kk_string_t _x_x1154;
        kk_std_time_instant__timescale _x_x1155 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
        {
          struct kk_std_time_instant_Timescale* _con_x1156 = kk_std_time_instant__as_Timescale(_x_x1155, _ctx);
          kk_string_t _x_1_0 = _con_x1156->name;
          _x_x1154 = kk_string_dup(_x_1_0, _ctx); /*string*/
        }
        _match_x355 = kk_string_is_eq(_x_x1150,_x_x1154,kk_context()); /*bool*/
        if (_match_x355) {
          instant_1_10150 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
        }
        else {
          kk_std_time_timestamp__timestamp _x_x1157;
          kk_std_time_instant__instant _x_x1158 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
          kk_std_time_instant__timescale _x_x1159 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
          _x_x1157 = kk_std_time_instant_timestamp_in(_x_x1158, _x_x1159, _ctx); /*std/time/timestamp/timestamp*/
          kk_std_time_instant__timescale _x_x1160 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
          instant_1_10150 = kk_std_time_instant__new_Instant(_x_x1157, _x_x1160, _ctx); /*std/time/instant/instant*/
        }
        kk_std_time_instant__instant i_1_10146;
        kk_std_time_timestamp__timestamp _x_x1161;
        kk_std_num_ddouble__ddouble _x_x1162;
        bool _match_x353 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x353) {
          kk_integer_drop(prec, _ctx);
          kk_std_num_ddouble__ddouble _x_x1163;
          {
            kk_std_time_timestamp__timestamp _x_5 = instant_1_10150.since;
            kk_std_time_instant__timescale _pat_2_6 = instant_1_10150.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1164 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1165 = kk_std_time_instant__as_Timescale(_pat_2_6, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_5, _ctx);
            {
              struct kk_std_time_timestamp_Timestamp* _con_x1166 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
              kk_std_num_ddouble__ddouble _x_4 = _con_x1166->since;
              if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
                kk_datatype_ptr_free(_x_5, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_x_5, _ctx);
              }
              _x_x1163 = _x_4; /*std/time/timestamp/timespan*/
            }
          }
          _x_x1162 = kk_std_num_ddouble_round(_x_x1163, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          bool _match_x354 = kk_integer_gt_borrow(prec,(kk_integer_from_small(31)),kk_context()); /*bool*/;
          if (_match_x354) {
            kk_integer_drop(prec, _ctx);
            {
              kk_std_time_timestamp__timestamp _x_5_0 = instant_1_10150.since;
              kk_std_time_instant__timescale _pat_2_6_0 = instant_1_10150.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1167 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1168 = kk_std_time_instant__as_Timescale(_pat_2_6_0, _ctx);
              kk_std_time_timestamp__timestamp_dup(_x_5_0, _ctx);
              {
                struct kk_std_time_timestamp_Timestamp* _con_x1169 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
                kk_std_num_ddouble__ddouble _x_0_0_0 = _con_x1169->since;
                if kk_likely(kk_datatype_ptr_is_unique(_x_5_0, _ctx)) {
                  kk_datatype_ptr_free(_x_5_0, _ctx);
                }
                else {
                  kk_datatype_ptr_decref(_x_5_0, _ctx);
                }
                _x_x1162 = _x_0_0_0; /*std/num/ddouble/ddouble*/
              }
            }
          }
          else {
            kk_std_num_ddouble__ddouble p = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, prec, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble _x_x1170;
            kk_std_num_ddouble__ddouble _x_x1171;
            kk_std_num_ddouble__ddouble _x_x1172;
            {
              kk_std_time_timestamp__timestamp _x_5_1 = instant_1_10150.since;
              kk_std_time_instant__timescale _pat_2_6_1 = instant_1_10150.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1173 = kk_std_time_timestamp__as_Timestamp(_x_5_1, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1174 = kk_std_time_instant__as_Timescale(_pat_2_6_1, _ctx);
              kk_std_time_timestamp__timestamp_dup(_x_5_1, _ctx);
              {
                struct kk_std_time_timestamp_Timestamp* _con_x1175 = kk_std_time_timestamp__as_Timestamp(_x_5_1, _ctx);
                kk_std_num_ddouble__ddouble _x_1_0_0 = _con_x1175->since;
                if kk_likely(kk_datatype_ptr_is_unique(_x_5_1, _ctx)) {
                  kk_datatype_ptr_free(_x_5_1, _ctx);
                }
                else {
                  kk_datatype_ptr_decref(_x_5_1, _ctx);
                }
                _x_x1172 = _x_1_0_0; /*std/time/timestamp/timespan*/
              }
            }
            _x_x1171 = kk_std_num_ddouble__lp__star__rp_(_x_x1172, p, _ctx); /*std/num/ddouble/ddouble*/
            _x_x1170 = kk_std_num_ddouble_round(_x_x1171, _ctx); /*std/num/ddouble/ddouble*/
            _x_x1162 = kk_std_num_ddouble__lp__fs__rp_(_x_x1170, p, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
        int32_t _x_x1176;
        {
          kk_std_time_timestamp__timestamp _x_5_2 = instant_1_10150.since;
          kk_std_time_instant__timescale _pat_2_6_2 = instant_1_10150.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1177 = kk_std_time_timestamp__as_Timestamp(_x_5_2, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1178 = kk_std_time_instant__as_Timescale(_pat_2_6_2, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_5_2, _ctx);
          kk_std_time_instant__instant_drop(instant_1_10150, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x1179 = kk_std_time_timestamp__as_Timestamp(_x_5_2, _ctx);
            kk_std_num_ddouble__ddouble _pat_0_1_0_0 = _con_x1179->since;
            int32_t _x_0_0_0_0 = _con_x1179->leap32;
            if kk_likely(kk_datatype_ptr_is_unique(_x_5_2, _ctx)) {
              kk_datatype_ptr_free(_x_5_2, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_5_2, _ctx);
            }
            _x_x1176 = _x_0_0_0_0; /*int32*/
          }
        }
        _x_x1161 = kk_std_time_timestamp__new_Timestamp(_ru_x533, 0, _x_x1162, _x_x1176, _ctx); /*std/time/timestamp/timestamp*/
        kk_std_time_instant__timescale _x_x1180 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
        i_1_10146 = kk_std_time_instant__new_Instant(_x_x1161, _x_x1180, _ctx); /*std/time/instant/instant*/
        bool _match_x349;
        kk_string_t _x_x1181;
        {
          kk_std_time_timestamp__timestamp _pat_0_4 = i_1_10146.since;
          kk_std_time_instant__timescale _x_2 = i_1_10146.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1182 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1183 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
          kk_std_time_instant__timescale_dup(_x_2, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1184 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
            kk_string_t _x_1_1 = _con_x1184->name;
            kk_string_t _pat_0_3_0 = _con_x1184->unit;
            kk_function_t _pat_1_4 = _con_x1184->from_tai;
            kk_function_t _pat_2_2_0 = _con_x1184->to_tai;
            kk_std_core_types__maybe _pat_3_1_1 = _con_x1184->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_1_1 = _con_x1184->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_1_1 = _con_x1184->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_1_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_1_1, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_1_1, _ctx);
              kk_function_drop(_pat_2_2_0, _ctx);
              kk_function_drop(_pat_1_4, _ctx);
              kk_string_drop(_pat_0_3_0, _ctx);
              kk_datatype_ptr_free(_x_2, _ctx);
            }
            else {
              kk_string_dup(_x_1_1, _ctx);
              kk_datatype_ptr_decref(_x_2, _ctx);
            }
            _x_x1181 = _x_1_1; /*string*/
          }
        }
        kk_string_t _x_x1185;
        {
          kk_std_time_timestamp__timestamp _pat_0_9 = i.since;
          kk_std_time_instant__timescale _x_6 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1186 = kk_std_time_timestamp__as_Timestamp(_pat_0_9, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1187 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
          kk_std_time_instant__timescale_dup(_x_6, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x1188 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
            kk_string_t _x_3 = _con_x1188->name;
            kk_string_t _pat_0_5 = _con_x1188->unit;
            kk_function_t _pat_1_6 = _con_x1188->from_tai;
            kk_function_t _pat_2_4 = _con_x1188->to_tai;
            kk_std_core_types__maybe _pat_3_3 = _con_x1188->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_3 = _con_x1188->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_3 = _con_x1188->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_6, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_3, _ctx);
              kk_function_drop(_pat_2_4, _ctx);
              kk_function_drop(_pat_1_6, _ctx);
              kk_string_drop(_pat_0_5, _ctx);
              kk_datatype_ptr_free(_x_6, _ctx);
            }
            else {
              kk_string_dup(_x_3, _ctx);
              kk_datatype_ptr_decref(_x_6, _ctx);
            }
            _x_x1185 = _x_3; /*string*/
          }
        }
        _match_x349 = kk_string_is_eq(_x_x1181,_x_x1185,kk_context()); /*bool*/
        if (_match_x349) {
          kk_std_time_instant__instant_drop(i, _ctx);
          return i_1_10146;
        }
        {
          kk_std_time_timestamp__timestamp _x_x1189;
          bool _match_x350;
          kk_string_t _x_x1190;
          {
            kk_std_time_timestamp__timestamp _pat_0_10 = i_1_10146.since;
            kk_std_time_instant__timescale _x_9 = i_1_10146.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1191 = kk_std_time_timestamp__as_Timestamp(_pat_0_10, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1192 = kk_std_time_instant__as_Timescale(_x_9, _ctx);
            kk_std_time_instant__timescale_dup(_x_9, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x1193 = kk_std_time_instant__as_Timescale(_x_9, _ctx);
              kk_string_t _x_7 = _con_x1193->name;
              kk_string_t _pat_0_11 = _con_x1193->unit;
              kk_function_t _pat_1_11 = _con_x1193->from_tai;
              kk_function_t _pat_2_8 = _con_x1193->to_tai;
              kk_std_core_types__maybe _pat_3_7 = _con_x1193->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_7 = _con_x1193->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_6 = _con_x1193->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_6, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_7, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_7, _ctx);
                kk_function_drop(_pat_2_8, _ctx);
                kk_function_drop(_pat_1_11, _ctx);
                kk_string_drop(_pat_0_11, _ctx);
                kk_datatype_ptr_free(_x_9, _ctx);
              }
              else {
                kk_string_dup(_x_7, _ctx);
                kk_datatype_ptr_decref(_x_9, _ctx);
              }
              _x_x1190 = _x_7; /*string*/
            }
          }
          kk_string_t _x_x1194;
          {
            kk_std_time_timestamp__timestamp _pat_0_9_0_1 = i.since;
            kk_std_time_instant__timescale _x_6_0_0 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1195 = kk_std_time_timestamp__as_Timestamp(_pat_0_9_0_1, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1196 = kk_std_time_instant__as_Timescale(_x_6_0_0, _ctx);
            kk_std_time_instant__timescale_dup(_x_6_0_0, _ctx);
            {
              struct kk_std_time_instant_Timescale* _con_x1197 = kk_std_time_instant__as_Timescale(_x_6_0_0, _ctx);
              kk_string_t _x_0_1 = _con_x1197->name;
              kk_string_t _pat_0_0_2 = _con_x1197->unit;
              kk_function_t _pat_1_0_2 = _con_x1197->from_tai;
              kk_function_t _pat_2_0_2 = _con_x1197->to_tai;
              kk_std_core_types__maybe _pat_3_0_1 = _con_x1197->mb_seconds_in_day;
              kk_std_core_types__maybe _pat_4_0_1 = _con_x1197->mb_to_mjd2000;
              kk_std_core_types__maybe _pat_5_0_1 = _con_x1197->mb_from_mjd2000;
              if kk_likely(kk_datatype_ptr_is_unique(_x_6_0_0, _ctx)) {
                kk_std_core_types__maybe_drop(_pat_5_0_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_4_0_1, _ctx);
                kk_std_core_types__maybe_drop(_pat_3_0_1, _ctx);
                kk_function_drop(_pat_2_0_2, _ctx);
                kk_function_drop(_pat_1_0_2, _ctx);
                kk_string_drop(_pat_0_0_2, _ctx);
                kk_datatype_ptr_free(_x_6_0_0, _ctx);
              }
              else {
                kk_string_dup(_x_0_1, _ctx);
                kk_datatype_ptr_decref(_x_6_0_0, _ctx);
              }
              _x_x1194 = _x_0_1; /*string*/
            }
          }
          _match_x350 = kk_string_is_eq(_x_x1190,_x_x1194,kk_context()); /*bool*/
          if (_match_x350) {
            kk_std_time_timestamp__timestamp _x_8 = i_1_10146.since;
            kk_std_time_instant__timescale _pat_2_9 = i_1_10146.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1198 = kk_std_time_timestamp__as_Timestamp(_x_8, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1199 = kk_std_time_instant__as_Timescale(_pat_2_9, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_8, _ctx);
            kk_std_time_instant__instant_drop(i_1_10146, _ctx);
            _x_x1189 = _x_8; /*std/time/timestamp/timestamp*/
          }
          else {
            bool _match_x351;
            kk_string_t _x_x1200;
            {
              kk_std_time_timestamp__timestamp _pat_0_10_0 = i_1_10146.since;
              kk_std_time_instant__timescale _x_9_0 = i_1_10146.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1201 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1202 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
              kk_std_time_instant__timescale_dup(_x_9_0, _ctx);
              {
                struct kk_std_time_instant_Timescale* _con_x1203 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
                kk_string_t _pat_0_2_1 = _con_x1203->name;
                kk_string_t _x_1_2 = _con_x1203->unit;
                kk_function_t _pat_1_1_1 = _con_x1203->from_tai;
                kk_function_t _pat_2_1_1 = _con_x1203->to_tai;
                kk_std_core_types__maybe _pat_3_1_2 = _con_x1203->mb_seconds_in_day;
                kk_std_core_types__maybe _pat_4_1_2 = _con_x1203->mb_to_mjd2000;
                kk_std_core_types__maybe _pat_5_1_2 = _con_x1203->mb_from_mjd2000;
                if kk_likely(kk_datatype_ptr_is_unique(_x_9_0, _ctx)) {
                  kk_std_core_types__maybe_drop(_pat_5_1_2, _ctx);
                  kk_std_core_types__maybe_drop(_pat_4_1_2, _ctx);
                  kk_std_core_types__maybe_drop(_pat_3_1_2, _ctx);
                  kk_function_drop(_pat_2_1_1, _ctx);
                  kk_function_drop(_pat_1_1_1, _ctx);
                  kk_string_drop(_pat_0_2_1, _ctx);
                  kk_datatype_ptr_free(_x_9_0, _ctx);
                }
                else {
                  kk_string_dup(_x_1_2, _ctx);
                  kk_datatype_ptr_decref(_x_9_0, _ctx);
                }
                _x_x1200 = _x_1_2; /*string*/
              }
            }
            kk_string_t _x_x1204;
            {
              kk_std_time_timestamp__timestamp _pat_0_9_0_1_0 = i.since;
              kk_std_time_instant__timescale _x_6_0_0_0 = i.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1205 = kk_std_time_timestamp__as_Timestamp(_pat_0_9_0_1_0, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1206 = kk_std_time_instant__as_Timescale(_x_6_0_0_0, _ctx);
              kk_std_time_instant__timescale_dup(_x_6_0_0_0, _ctx);
              {
                struct kk_std_time_instant_Timescale* _con_x1207 = kk_std_time_instant__as_Timescale(_x_6_0_0_0, _ctx);
                kk_string_t _pat_0_3_1 = _con_x1207->name;
                kk_string_t _x_2_0 = _con_x1207->unit;
                kk_function_t _pat_1_2_0 = _con_x1207->from_tai;
                kk_function_t _pat_2_2_1 = _con_x1207->to_tai;
                kk_std_core_types__maybe _pat_3_2_0 = _con_x1207->mb_seconds_in_day;
                kk_std_core_types__maybe _pat_4_2_0 = _con_x1207->mb_to_mjd2000;
                kk_std_core_types__maybe _pat_5_2_0 = _con_x1207->mb_from_mjd2000;
                if kk_likely(kk_datatype_ptr_is_unique(_x_6_0_0_0, _ctx)) {
                  kk_std_core_types__maybe_drop(_pat_5_2_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_4_2_0, _ctx);
                  kk_std_core_types__maybe_drop(_pat_3_2_0, _ctx);
                  kk_function_drop(_pat_2_2_1, _ctx);
                  kk_function_drop(_pat_1_2_0, _ctx);
                  kk_string_drop(_pat_0_3_1, _ctx);
                  kk_datatype_ptr_free(_x_6_0_0_0, _ctx);
                }
                else {
                  kk_string_dup(_x_2_0, _ctx);
                  kk_datatype_ptr_decref(_x_6_0_0_0, _ctx);
                }
                _x_x1204 = _x_2_0; /*string*/
              }
            }
            _match_x351 = kk_string_is_eq(_x_x1200,_x_x1204,kk_context()); /*bool*/
            if (_match_x351) {
              bool _match_x352;
              kk_string_t _x_x1208;
              {
                kk_std_time_timestamp__timestamp _pat_0_10_1 = i_1_10146.since;
                kk_std_time_instant__timescale _x_9_1 = i_1_10146.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x1209 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_1, _ctx);
                struct kk_std_time_instant_Timescale* _con_x1210 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
                kk_std_time_instant__timescale_dup(_x_9_1, _ctx);
                {
                  struct kk_std_time_instant_Timescale* _con_x1211 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
                  kk_string_t _pat_0_4_0 = _con_x1211->name;
                  kk_string_t _x_3_0 = _con_x1211->unit;
                  kk_function_t _pat_1_4_0 = _con_x1211->from_tai;
                  kk_function_t _pat_2_3_0 = _con_x1211->to_tai;
                  kk_std_core_types__maybe _pat_3_3_0 = _con_x1211->mb_seconds_in_day;
                  kk_std_core_types__maybe _pat_4_3_0 = _con_x1211->mb_to_mjd2000;
                  kk_std_core_types__maybe _pat_5_3_0 = _con_x1211->mb_from_mjd2000;
                  if kk_likely(kk_datatype_ptr_is_unique(_x_9_1, _ctx)) {
                    kk_std_core_types__maybe_drop(_pat_5_3_0, _ctx);
                    kk_std_core_types__maybe_drop(_pat_4_3_0, _ctx);
                    kk_std_core_types__maybe_drop(_pat_3_3_0, _ctx);
                    kk_function_drop(_pat_2_3_0, _ctx);
                    kk_function_drop(_pat_1_4_0, _ctx);
                    kk_string_drop(_pat_0_4_0, _ctx);
                    kk_datatype_ptr_free(_x_9_1, _ctx);
                  }
                  else {
                    kk_string_dup(_x_3_0, _ctx);
                    kk_datatype_ptr_decref(_x_9_1, _ctx);
                  }
                  _x_x1208 = _x_3_0; /*string*/
                }
              }
              kk_string_t _x_x1212;
              kk_define_string_literal(, _s_x1213, 3, "UTC", _ctx)
              _x_x1212 = kk_string_dup(_s_x1213, _ctx); /*string*/
              _match_x352 = kk_string_is_eq(_x_x1208,_x_x1212,kk_context()); /*bool*/
              if (_match_x352) {
                kk_std_time_timestamp__timestamp _x_8_0 = i_1_10146.since;
                kk_std_time_instant__timescale _pat_2_9_0 = i_1_10146.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x1214 = kk_std_time_timestamp__as_Timestamp(_x_8_0, _ctx);
                struct kk_std_time_instant_Timescale* _con_x1215 = kk_std_time_instant__as_Timescale(_pat_2_9_0, _ctx);
                kk_std_time_timestamp__timestamp_dup(_x_8_0, _ctx);
                kk_std_time_instant__instant_drop(i_1_10146, _ctx);
                _x_x1189 = _x_8_0; /*std/time/timestamp/timestamp*/
              }
              else {
                kk_std_time_duration__duration _norm_x10280;
                {
                  kk_std_time_timestamp__timestamp _pat_0_10_2 = i_1_10146.since;
                  kk_std_time_instant__timescale _x_9_2 = i_1_10146.ts;
                  struct kk_std_time_timestamp_Timestamp* _con_x1216 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_2, _ctx);
                  struct kk_std_time_instant_Timescale* _con_x1217 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
                  kk_std_time_instant__timescale_dup(_x_9_2, _ctx);
                  {
                    struct kk_std_time_instant_Timescale* _con_x1218 = kk_std_time_instant__as_Timescale(_x_9_2, _ctx);
                    kk_string_t _pat_0_6_0 = _con_x1218->name;
                    kk_string_t _pat_1_6_0 = _con_x1218->unit;
                    kk_function_t _pat_2_5_0 = _con_x1218->from_tai;
                    kk_function_t _x_5_3 = _con_x1218->to_tai;
                    kk_std_core_types__maybe _pat_3_6_0 = _con_x1218->mb_seconds_in_day;
                    kk_std_core_types__maybe _pat_4_6_0 = _con_x1218->mb_to_mjd2000;
                    kk_std_core_types__maybe _pat_5_5_0 = _con_x1218->mb_from_mjd2000;
                    if kk_likely(kk_datatype_ptr_is_unique(_x_9_2, _ctx)) {
                      kk_std_core_types__maybe_drop(_pat_5_5_0, _ctx);
                      kk_std_core_types__maybe_drop(_pat_4_6_0, _ctx);
                      kk_std_core_types__maybe_drop(_pat_3_6_0, _ctx);
                      kk_function_drop(_pat_2_5_0, _ctx);
                      kk_string_drop(_pat_1_6_0, _ctx);
                      kk_string_drop(_pat_0_6_0, _ctx);
                      kk_datatype_ptr_free(_x_9_2, _ctx);
                    }
                    else {
                      kk_function_dup(_x_5_3, _ctx);
                      kk_datatype_ptr_decref(_x_9_2, _ctx);
                    }
                    kk_std_time_timestamp__timestamp _x_x1219;
                    {
                      kk_std_time_timestamp__timestamp _x_8_1 = i_1_10146.since;
                      kk_std_time_instant__timescale _pat_2_9_1 = i_1_10146.ts;
                      struct kk_std_time_timestamp_Timestamp* _con_x1220 = kk_std_time_timestamp__as_Timestamp(_x_8_1, _ctx);
                      struct kk_std_time_instant_Timescale* _con_x1221 = kk_std_time_instant__as_Timescale(_pat_2_9_1, _ctx);
                      kk_std_time_timestamp__timestamp_dup(_x_8_1, _ctx);
                      kk_std_time_instant__instant_drop(i_1_10146, _ctx);
                      _x_x1219 = _x_8_1; /*std/time/timestamp/timestamp*/
                    }
                    _norm_x10280 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5_3, (_x_5_3, _x_x1219, _ctx), _ctx); /*std/time/duration/duration*/
                  }
                }
                {
                  kk_std_time_timestamp__timestamp _pat_0_9_0_1_1 = i.since;
                  kk_std_time_instant__timescale _x_6_0_0_1 = i.ts;
                  struct kk_std_time_timestamp_Timestamp* _con_x1222 = kk_std_time_timestamp__as_Timestamp(_pat_0_9_0_1_1, _ctx);
                  struct kk_std_time_instant_Timescale* _con_x1223 = kk_std_time_instant__as_Timescale(_x_6_0_0_1, _ctx);
                  kk_std_time_instant__timescale_dup(_x_6_0_0_1, _ctx);
                  {
                    struct kk_std_time_instant_Timescale* _con_x1224 = kk_std_time_instant__as_Timescale(_x_6_0_0_1, _ctx);
                    kk_string_t _pat_0_5_0 = _con_x1224->name;
                    kk_string_t _pat_1_5_0 = _con_x1224->unit;
                    kk_function_t _x_4_0 = _con_x1224->from_tai;
                    kk_function_t _pat_2_4_0 = _con_x1224->to_tai;
                    kk_std_core_types__maybe _pat_3_5_3 = _con_x1224->mb_seconds_in_day;
                    kk_std_core_types__maybe _pat_4_5_3 = _con_x1224->mb_to_mjd2000;
                    kk_std_core_types__maybe _pat_5_4_3 = _con_x1224->mb_from_mjd2000;
                    if kk_likely(kk_datatype_ptr_is_unique(_x_6_0_0_1, _ctx)) {
                      kk_std_core_types__maybe_drop(_pat_5_4_3, _ctx);
                      kk_std_core_types__maybe_drop(_pat_4_5_3, _ctx);
                      kk_std_core_types__maybe_drop(_pat_3_5_3, _ctx);
                      kk_function_drop(_pat_2_4_0, _ctx);
                      kk_string_drop(_pat_1_5_0, _ctx);
                      kk_string_drop(_pat_0_5_0, _ctx);
                      kk_datatype_ptr_free(_x_6_0_0_1, _ctx);
                    }
                    else {
                      kk_function_dup(_x_4_0, _ctx);
                      kk_datatype_ptr_decref(_x_6_0_0_1, _ctx);
                    }
                    _x_x1189 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4_0, (_x_4_0, _norm_x10280, _ctx), _ctx); /*std/time/timestamp/timestamp*/
                  }
                }
              }
            }
            else {
              kk_std_time_duration__duration _norm_x10281;
              {
                kk_std_time_timestamp__timestamp _pat_0_10_3 = i_1_10146.since;
                kk_std_time_instant__timescale _x_9_3 = i_1_10146.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x1225 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_3, _ctx);
                struct kk_std_time_instant_Timescale* _con_x1226 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
                kk_std_time_instant__timescale_dup(_x_9_3, _ctx);
                {
                  struct kk_std_time_instant_Timescale* _con_x1227 = kk_std_time_instant__as_Timescale(_x_9_3, _ctx);
                  kk_string_t _pat_0_8_3 = _con_x1227->name;
                  kk_string_t _pat_1_8_3 = _con_x1227->unit;
                  kk_function_t _pat_2_8_0 = _con_x1227->from_tai;
                  kk_function_t _x_7_0 = _con_x1227->to_tai;
                  kk_std_core_types__maybe _pat_3_8 = _con_x1227->mb_seconds_in_day;
                  kk_std_core_types__maybe _pat_4_8 = _con_x1227->mb_to_mjd2000;
                  kk_std_core_types__maybe _pat_5_7 = _con_x1227->mb_from_mjd2000;
                  if kk_likely(kk_datatype_ptr_is_unique(_x_9_3, _ctx)) {
                    kk_std_core_types__maybe_drop(_pat_5_7, _ctx);
                    kk_std_core_types__maybe_drop(_pat_4_8, _ctx);
                    kk_std_core_types__maybe_drop(_pat_3_8, _ctx);
                    kk_function_drop(_pat_2_8_0, _ctx);
                    kk_string_drop(_pat_1_8_3, _ctx);
                    kk_string_drop(_pat_0_8_3, _ctx);
                    kk_datatype_ptr_free(_x_9_3, _ctx);
                  }
                  else {
                    kk_function_dup(_x_7_0, _ctx);
                    kk_datatype_ptr_decref(_x_9_3, _ctx);
                  }
                  kk_std_time_timestamp__timestamp _x_x1228;
                  {
                    kk_std_time_timestamp__timestamp _x_8_2 = i_1_10146.since;
                    kk_std_time_instant__timescale _pat_2_9_2 = i_1_10146.ts;
                    struct kk_std_time_timestamp_Timestamp* _con_x1229 = kk_std_time_timestamp__as_Timestamp(_x_8_2, _ctx);
                    struct kk_std_time_instant_Timescale* _con_x1230 = kk_std_time_instant__as_Timescale(_pat_2_9_2, _ctx);
                    kk_std_time_timestamp__timestamp_dup(_x_8_2, _ctx);
                    kk_std_time_instant__instant_drop(i_1_10146, _ctx);
                    _x_x1228 = _x_8_2; /*std/time/timestamp/timestamp*/
                  }
                  _norm_x10281 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7_0, (_x_7_0, _x_x1228, _ctx), _ctx); /*std/time/duration/duration*/
                }
              }
              {
                kk_std_time_timestamp__timestamp _pat_0_9_0_1_2 = i.since;
                kk_std_time_instant__timescale _x_6_0_0_2 = i.ts;
                struct kk_std_time_timestamp_Timestamp* _con_x1231 = kk_std_time_timestamp__as_Timestamp(_pat_0_9_0_1_2, _ctx);
                struct kk_std_time_instant_Timescale* _con_x1232 = kk_std_time_instant__as_Timescale(_x_6_0_0_2, _ctx);
                kk_std_time_instant__timescale_dup(_x_6_0_0_2, _ctx);
                {
                  struct kk_std_time_instant_Timescale* _con_x1233 = kk_std_time_instant__as_Timescale(_x_6_0_0_2, _ctx);
                  kk_string_t _pat_0_7_0 = _con_x1233->name;
                  kk_string_t _pat_1_7_0 = _con_x1233->unit;
                  kk_function_t _x_6_0 = _con_x1233->from_tai;
                  kk_function_t _pat_2_7_0 = _con_x1233->to_tai;
                  kk_std_core_types__maybe _pat_3_7_0 = _con_x1233->mb_seconds_in_day;
                  kk_std_core_types__maybe _pat_4_7_0 = _con_x1233->mb_to_mjd2000;
                  kk_std_core_types__maybe _pat_5_6_0 = _con_x1233->mb_from_mjd2000;
                  if kk_likely(kk_datatype_ptr_is_unique(_x_6_0_0_2, _ctx)) {
                    kk_std_core_types__maybe_drop(_pat_5_6_0, _ctx);
                    kk_std_core_types__maybe_drop(_pat_4_7_0, _ctx);
                    kk_std_core_types__maybe_drop(_pat_3_7_0, _ctx);
                    kk_function_drop(_pat_2_7_0, _ctx);
                    kk_string_drop(_pat_1_7_0, _ctx);
                    kk_string_drop(_pat_0_7_0, _ctx);
                    kk_datatype_ptr_free(_x_6_0_0_2, _ctx);
                  }
                  else {
                    kk_function_dup(_x_6_0, _ctx);
                    kk_datatype_ptr_decref(_x_6_0_0_2, _ctx);
                  }
                  _x_x1189 = kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6_0, (_x_6_0, _norm_x10281, _ctx), _ctx); /*std/time/timestamp/timestamp*/
                }
              }
            }
          }
          kk_std_time_instant__timescale _x_x1234;
          {
            kk_std_time_timestamp__timestamp _pat_0_9_1_0 = i.since;
            kk_std_time_instant__timescale _x_6_1 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1235 = kk_std_time_timestamp__as_Timestamp(_pat_0_9_1_0, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1236 = kk_std_time_instant__as_Timescale(_x_6_1, _ctx);
            kk_std_time_instant__timescale_dup(_x_6_1, _ctx);
            kk_std_time_instant__instant_drop(i, _ctx);
            _x_x1234 = _x_6_1; /*std/time/instant/timescale*/
          }
          return kk_std_time_instant__new_Instant(_x_x1189, _x_x1234, _ctx);
        }
      }
      {
        kk_std_time_timestamp__timestamp _x_x1237;
        kk_std_num_ddouble__ddouble _x_x1238;
        bool _match_x347 = kk_integer_lte_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
        if (_match_x347) {
          kk_integer_drop(prec, _ctx);
          kk_std_num_ddouble__ddouble _x_x1239;
          {
            kk_std_time_timestamp__timestamp _x_8_3 = i.since;
            kk_std_time_instant__timescale _pat_2_10_4 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x1240 = kk_std_time_timestamp__as_Timestamp(_x_8_3, _ctx);
            struct kk_std_time_instant_Timescale* _con_x1241 = kk_std_time_instant__as_Timescale(_pat_2_10_4, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_8_3, _ctx);
            {
              struct kk_std_time_timestamp_Timestamp* _con_x1242 = kk_std_time_timestamp__as_Timestamp(_x_8_3, _ctx);
              kk_std_num_ddouble__ddouble _x_7_1 = _con_x1242->since;
              if kk_likely(kk_datatype_ptr_is_unique(_x_8_3, _ctx)) {
                kk_datatype_ptr_free(_x_8_3, _ctx);
              }
              else {
                kk_datatype_ptr_decref(_x_8_3, _ctx);
              }
              _x_x1239 = _x_7_1; /*std/time/timestamp/timespan*/
            }
          }
          _x_x1238 = kk_std_num_ddouble_round(_x_x1239, _ctx); /*std/num/ddouble/ddouble*/
        }
        else {
          bool _match_x348 = kk_integer_gt_borrow(prec,(kk_integer_from_small(31)),kk_context()); /*bool*/;
          if (_match_x348) {
            kk_integer_drop(prec, _ctx);
            {
              kk_std_time_timestamp__timestamp _x_8_0_0 = i.since;
              kk_std_time_instant__timescale _pat_2_10_0_0 = i.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1243 = kk_std_time_timestamp__as_Timestamp(_x_8_0_0, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1244 = kk_std_time_instant__as_Timescale(_pat_2_10_0_0, _ctx);
              kk_std_time_timestamp__timestamp_dup(_x_8_0_0, _ctx);
              {
                struct kk_std_time_timestamp_Timestamp* _con_x1245 = kk_std_time_timestamp__as_Timestamp(_x_8_0_0, _ctx);
                kk_std_num_ddouble__ddouble _x_0_1_0 = _con_x1245->since;
                if kk_likely(kk_datatype_ptr_is_unique(_x_8_0_0, _ctx)) {
                  kk_datatype_ptr_free(_x_8_0_0, _ctx);
                }
                else {
                  kk_datatype_ptr_decref(_x_8_0_0, _ctx);
                }
                _x_x1238 = _x_0_1_0; /*std/num/ddouble/ddouble*/
              }
            }
          }
          else {
            kk_std_num_ddouble__ddouble p_0 = kk_std_num_ddouble_powi(kk_std_num_ddouble_ten, prec, _ctx); /*std/num/ddouble/ddouble*/;
            kk_std_num_ddouble__ddouble _x_x1246;
            kk_std_num_ddouble__ddouble _x_x1247;
            kk_std_num_ddouble__ddouble _x_x1248;
            {
              kk_std_time_timestamp__timestamp _x_8_1_0 = i.since;
              kk_std_time_instant__timescale _pat_2_10_1_0 = i.ts;
              struct kk_std_time_timestamp_Timestamp* _con_x1249 = kk_std_time_timestamp__as_Timestamp(_x_8_1_0, _ctx);
              struct kk_std_time_instant_Timescale* _con_x1250 = kk_std_time_instant__as_Timescale(_pat_2_10_1_0, _ctx);
              kk_std_time_timestamp__timestamp_dup(_x_8_1_0, _ctx);
              {
                struct kk_std_time_timestamp_Timestamp* _con_x1251 = kk_std_time_timestamp__as_Timestamp(_x_8_1_0, _ctx);
                kk_std_num_ddouble__ddouble _x_1_1_0 = _con_x1251->since;
                if kk_likely(kk_datatype_ptr_is_unique(_x_8_1_0, _ctx)) {
                  kk_datatype_ptr_free(_x_8_1_0, _ctx);
                }
                else {
                  kk_datatype_ptr_decref(_x_8_1_0, _ctx);
                }
                _x_x1248 = _x_1_1_0; /*std/time/timestamp/timespan*/
              }
            }
            _x_x1247 = kk_std_num_ddouble__lp__star__rp_(_x_x1248, p_0, _ctx); /*std/num/ddouble/ddouble*/
            _x_x1246 = kk_std_num_ddouble_round(_x_x1247, _ctx); /*std/num/ddouble/ddouble*/
            _x_x1238 = kk_std_num_ddouble__lp__fs__rp_(_x_x1246, p_0, _ctx); /*std/num/ddouble/ddouble*/
          }
        }
        int32_t _x_x1252;
        {
          kk_std_time_timestamp__timestamp _x_8_2_0 = i.since;
          kk_std_time_instant__timescale _pat_2_10_2_0 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1253 = kk_std_time_timestamp__as_Timestamp(_x_8_2_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1254 = kk_std_time_instant__as_Timescale(_pat_2_10_2_0, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_8_2_0, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x1255 = kk_std_time_timestamp__as_Timestamp(_x_8_2_0, _ctx);
            kk_std_num_ddouble__ddouble _pat_0_1_1_0 = _con_x1255->since;
            int32_t _x_0_0_1 = _con_x1255->leap32;
            if kk_likely(kk_datatype_ptr_is_unique(_x_8_2_0, _ctx)) {
              kk_datatype_ptr_free(_x_8_2_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_8_2_0, _ctx);
            }
            _x_x1252 = _x_0_0_1; /*int32*/
          }
        }
        _x_x1237 = kk_std_time_timestamp__new_Timestamp(_ru_x533, 0, _x_x1238, _x_x1252, _ctx); /*std/time/timestamp/timestamp*/
        kk_std_time_instant__timescale _x_x1256;
        {
          kk_std_time_timestamp__timestamp _pat_0_12 = i.since;
          kk_std_time_instant__timescale _x_9_4 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x1257 = kk_std_time_timestamp__as_Timestamp(_pat_0_12, _ctx);
          struct kk_std_time_instant_Timescale* _con_x1258 = kk_std_time_instant__as_Timescale(_x_9_4, _ctx);
          kk_std_time_instant__timescale_dup(_x_9_4, _ctx);
          kk_std_time_instant__instant_drop(i, _ctx);
          _x_x1256 = _x_9_4; /*std/time/instant/timescale*/
        }
        return kk_std_time_instant__new_Instant(_x_x1237, _x_x1256, _ctx);
      }
    }
  }
}
 
// The minimum of two instants.

kk_std_time_instant__instant kk_std_time_instant_min(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> instant */ 
  kk_std_core_types__order x_10163;
  kk_std_time_instant__instant _x_x1264 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x_x1265 = kk_std_time_instant__instant_dup(j, _ctx); /*std/time/instant/instant*/
  x_10163 = kk_std_time_instant_cmp(_x_x1264, _x_x1265, _ctx); /*order*/
  bool _match_x333;
  kk_integer_t _brw_x334;
  if (kk_std_core_types__is_Lt(x_10163, _ctx)) {
    _brw_x334 = kk_integer_from_small(-1); /*int*/
    goto _match_x1266;
  }
  if (kk_std_core_types__is_Eq(x_10163, _ctx)) {
    _brw_x334 = kk_integer_from_small(0); /*int*/
    goto _match_x1266;
  }
  {
    _brw_x334 = kk_integer_from_small(1); /*int*/
  }
  _match_x1266: ;
  bool _brw_x335 = kk_integer_neq_borrow(_brw_x334,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x334, _ctx);
  _match_x333 = _brw_x335; /*bool*/
  if (_match_x333) {
    kk_std_time_instant__instant_drop(j, _ctx);
    return i;
  }
  {
    kk_std_time_instant__instant_drop(i, _ctx);
    return j;
  }
}
 
// The maximum of two instants.

kk_std_time_instant__instant kk_std_time_instant_max(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> instant */ 
  kk_std_core_types__order x_10167;
  kk_std_time_instant__instant _x_x1267 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x_x1268 = kk_std_time_instant__instant_dup(j, _ctx); /*std/time/instant/instant*/
  x_10167 = kk_std_time_instant_cmp(_x_x1267, _x_x1268, _ctx); /*order*/
  bool _match_x330;
  kk_integer_t _brw_x331;
  if (kk_std_core_types__is_Lt(x_10167, _ctx)) {
    _brw_x331 = kk_integer_from_small(-1); /*int*/
    goto _match_x1269;
  }
  if (kk_std_core_types__is_Eq(x_10167, _ctx)) {
    _brw_x331 = kk_integer_from_small(0); /*int*/
    goto _match_x1269;
  }
  {
    _brw_x331 = kk_integer_from_small(1); /*int*/
  }
  _match_x1269: ;
  bool _brw_x332 = kk_integer_neq_borrow(_brw_x331,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x331, _ctx);
  _match_x330 = _brw_x332; /*bool*/
  if (_match_x330) {
    kk_std_time_instant__instant_drop(j, _ctx);
    return i;
  }
  {
    kk_std_time_instant__instant_drop(i, _ctx);
    return j;
  }
}
 
// Add `days` days to the instant.

kk_std_time_instant__instant kk_std_time_instant_add_days(kk_std_time_instant__instant i, kk_integer_t days_0, kk_context_t* _ctx) { /* (i : instant, days : int) -> instant */ 
  kk_integer_t seconds_10054 = kk_integer_mul(days_0,(kk_integer_from_int(86400, _ctx)),kk_context()); /*int*/;
  kk_std_num_ddouble__ddouble t_10053;
  bool _match_x327;
  double _x_x1270;
  kk_std_core_types__optional _match_x329 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x329, _ctx)) {
    kk_box_t _box_x84 = _match_x329._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x84, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x329, _ctx);
    _x_x1270 = _uniq_frac_1144; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x329, _ctx);
    _x_x1270 = 0x0p+0; /*float64*/
  }
  _match_x327 = (_x_x1270 == (0x0p+0)); /*bool*/
  if (_match_x327) {
    t_10053 = kk_std_num_ddouble_ddouble_int_exp(seconds_10054, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x1271 = kk_std_num_ddouble_ddouble_int_exp(seconds_10054, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1272;
    double _x_x1273;
    kk_std_core_types__optional _match_x328 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x328, _ctx)) {
      kk_box_t _box_x85 = _match_x328._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x85, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x328, _ctx);
      _x_x1273 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x328, _ctx);
      _x_x1273 = 0x0p+0; /*float64*/
    }
    _x_x1272 = kk_std_num_ddouble__new_Ddouble(_x_x1273, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    t_10053 = kk_std_num_ddouble__lp__plus__rp_(_x_x1271, _x_x1272, _ctx); /*std/num/ddouble/ddouble*/
  }
  kk_std_time_timestamp__timestamp _x_x1274;
  kk_std_num_ddouble__ddouble _x_x1275;
  kk_std_num_ddouble__ddouble _x_x1276;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1277 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1278 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1279 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x1279->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1276 = _x; /*std/time/timestamp/timespan*/
    }
  }
  _x_x1275 = kk_std_num_ddouble__lp__plus__rp_(_x_x1276, t_10053, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1280;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_2_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1281 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1282 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1283 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x1283->since;
      int32_t _x_0 = _con_x1283->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1280 = _x_0; /*int32*/
    }
  }
  _x_x1274 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1275, _x_x1280, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1284;
  {
    kk_std_time_timestamp__timestamp _pat_0_3 = i.since;
    kk_std_time_instant__timescale _x_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1285 = kk_std_time_timestamp__as_Timestamp(_pat_0_3, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1286 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
    kk_std_time_instant__timescale_dup(_x_2, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x1284 = _x_2; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant__new_Instant(_x_x1274, _x_x1284, _ctx);
}
 
// /* Add a duration of `t` seconds of time scale `tscale`.
// This can for example be used to add Unix or NTP seconds where leap seconds
// are ignored (allthough it is recommended in that case to use
// `:time` and add logical days etc).
// ```
// > instant(2005,12,31).add-duration-in( ts-unix, (24*3600).timespan ).time
// 2006-01-01T00:00:00Z
// 
// > (instant(2005,12,31) + 24.hours).time
// 2005-12-31T23:59:60Z
// ```
// */

kk_std_time_instant__instant kk_std_time_instant_add_duration_in(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_num_ddouble__ddouble t, kk_context_t* _ctx) { /* (i : instant, tscale : timescale, t : std/time/timestamp/timespan) -> instant */ 
  kk_std_time_instant__instant i_0_10173;
  bool _match_x326;
  kk_string_t _x_x1287;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1288 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1289 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1290 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x1290->name;
      kk_string_t _pat_0 = _con_x1290->unit;
      kk_function_t _pat_1 = _con_x1290->from_tai;
      kk_function_t _pat_2 = _con_x1290->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x1290->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x1290->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x1290->mb_from_mjd2000;
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
      _x_x1287 = _x; /*string*/
    }
  }
  kk_string_t _x_x1291;
  {
    struct kk_std_time_instant_Timescale* _con_x1292 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_1 = _con_x1292->name;
    kk_string_dup(_x_1, _ctx);
    _x_x1291 = _x_1; /*string*/
  }
  _match_x326 = kk_string_is_eq(_x_x1287,_x_x1291,kk_context()); /*bool*/
  if (_match_x326) {
    kk_datatype_ptr_dropn(tscale, (KK_I32(10)), _ctx);
    i_0_10173 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1293;
    kk_std_time_instant__timescale _x_x1294 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    _x_x1293 = kk_std_time_instant_timestamp_in(i, _x_x1294, _ctx); /*std/time/timestamp/timestamp*/
    i_0_10173 = kk_std_time_instant__new_Instant(_x_x1293, tscale, _ctx); /*std/time/instant/instant*/
  }
  kk_std_time_timestamp__timestamp _x_x1295;
  kk_std_num_ddouble__ddouble _x_x1296;
  kk_std_num_ddouble__ddouble _x_x1297;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i_0_10173.since;
    kk_std_time_instant__timescale _pat_2_1_0 = i_0_10173.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1298 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1299 = kk_std_time_instant__as_Timescale(_pat_2_1_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1300 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _x_2 = _con_x1300->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1297 = _x_2; /*std/time/timestamp/timespan*/
    }
  }
  _x_x1296 = kk_std_num_ddouble__lp__plus__rp_(_x_x1297, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1301;
  {
    kk_std_time_timestamp__timestamp _x_1_0_0 = i_0_10173.since;
    kk_std_time_instant__timescale _pat_2_1_0_0 = i_0_10173.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1302 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1303 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x1304 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x1304->since;
      int32_t _x_0_0 = _con_x1304->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0_0, _ctx);
      }
      _x_x1301 = _x_0_0; /*int32*/
    }
  }
  _x_x1295 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1296, _x_x1301, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1305;
  {
    kk_std_time_timestamp__timestamp _pat_0_2_0 = i_0_10173.since;
    kk_std_time_instant__timescale _x_2_0 = i_0_10173.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1306 = kk_std_time_timestamp__as_Timestamp(_pat_0_2_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1307 = kk_std_time_instant__as_Timescale(_x_2_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_2_0, _ctx);
    kk_std_time_instant__instant_drop(i_0_10173, _ctx);
    _x_x1305 = _x_2_0; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant__new_Instant(_x_x1295, _x_x1305, _ctx);
}
 
// Internal: show an instant as a raw timestamp in a given precision, postfixed with the time scale name.

kk_string_t kk_std_time_instant_show_raw(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (i : instant, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_integer_t _b_x87_92;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x86 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_2777 = kk_integer_unbox(_box_x86, _ctx);
    kk_integer_dup(_uniq_max_prec_2777, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x87_92 = _uniq_max_prec_2777; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x87_92 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x89_93;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x88 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_2781 = kk_integer_unbox(_box_x88, _ctx);
    kk_integer_dup(_uniq_secs_width_2781, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x89_93 = _uniq_secs_width_2781; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x89_93 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _b_x91_94;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x90 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_2785 = kk_string_unbox(_box_x90);
    kk_string_dup(_uniq_unit_2785, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x91_94 = _uniq_unit_2785; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x91_94 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x1309;
  kk_std_time_timestamp__timestamp _x_x1310;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1311 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1312 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x1310 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_core_types__optional _x_x1313 = kk_std_core_types__new_Optional(kk_integer_box(_b_x87_92, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1314 = kk_std_core_types__new_Optional(kk_integer_box(_b_x89_93, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1315 = kk_std_core_types__new_Optional(kk_string_box(_b_x91_94), _ctx); /*? 10003*/
  _x_x1309 = kk_std_time_timestamp_ts_show(_x_x1310, _x_x1313, _x_x1314, _x_x1315, _ctx); /*string*/
  kk_string_t _x_x1316;
  bool _match_x324;
  kk_string_t _x_x1317;
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_1 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1318 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1319 = kk_std_time_instant__as_Timescale(_x_1, _ctx);
    kk_std_time_instant__timescale_dup(_x_1, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1320 = kk_std_time_instant__as_Timescale(_x_1, _ctx);
      kk_string_t _x_0 = _con_x1320->name;
      kk_string_t _pat_0_1 = _con_x1320->unit;
      kk_function_t _pat_1_1 = _con_x1320->from_tai;
      kk_function_t _pat_2_1 = _con_x1320->to_tai;
      kk_std_core_types__maybe _pat_3_1 = _con_x1320->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_1 = _con_x1320->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_0 = _con_x1320->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_0, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
        kk_function_drop(_pat_2_1, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_string_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1317 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x1321 = kk_string_empty(); /*string*/
  _match_x324 = kk_string_is_eq(_x_x1317,_x_x1321,kk_context()); /*bool*/
  if (_match_x324) {
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x1316 = kk_string_empty(); /*string*/
  }
  else {
    bool _match_x325;
    kk_string_t _x_x1324;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1325 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1326 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x1327 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
        kk_string_t _x_2 = _con_x1327->name;
        kk_string_t _pat_0_3 = _con_x1327->unit;
        kk_function_t _pat_1_3 = _con_x1327->from_tai;
        kk_function_t _pat_2_3 = _con_x1327->to_tai;
        kk_std_core_types__maybe _pat_3_3 = _con_x1327->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3 = _con_x1327->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3 = _con_x1327->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_3, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_3, _ctx);
          kk_function_drop(_pat_2_3, _ctx);
          kk_function_drop(_pat_1_3, _ctx);
          kk_string_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(_x_3, _ctx);
        }
        else {
          kk_string_dup(_x_2, _ctx);
          kk_datatype_ptr_decref(_x_3, _ctx);
        }
        _x_x1324 = _x_2; /*string*/
      }
    }
    kk_string_t _x_x1328;
    kk_define_string_literal(, _s_x1329, 3, "TAI", _ctx)
    _x_x1328 = kk_string_dup(_s_x1329, _ctx); /*string*/
    _match_x325 = kk_string_is_eq(_x_x1324,_x_x1328,kk_context()); /*bool*/
    if (_match_x325) {
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x1316 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x1331;
      kk_define_string_literal(, _s_x1332, 1, " ", _ctx)
      _x_x1331 = kk_string_dup(_s_x1332, _ctx); /*string*/
      kk_string_t _x_x1333;
      {
        kk_std_time_timestamp__timestamp _pat_0_6 = i.since;
        kk_std_time_instant__timescale _x_5 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1334 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1335 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
        kk_std_time_instant__timescale_dup(_x_5, _ctx);
        kk_std_time_instant__instant_drop(i, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1336 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
          kk_string_t _x_4 = _con_x1336->name;
          kk_string_t _pat_0_5 = _con_x1336->unit;
          kk_function_t _pat_1_5 = _con_x1336->from_tai;
          kk_function_t _pat_2_5 = _con_x1336->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x1336->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x1336->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_5 = _con_x1336->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_5, _ctx);
            kk_function_drop(_pat_2_5, _ctx);
            kk_function_drop(_pat_1_5, _ctx);
            kk_string_drop(_pat_0_5, _ctx);
            kk_datatype_ptr_free(_x_5, _ctx);
          }
          else {
            kk_string_dup(_x_4, _ctx);
            kk_datatype_ptr_decref(_x_5, _ctx);
          }
          _x_x1333 = _x_4; /*string*/
        }
      }
      _x_x1316 = kk_std_core_types__lp__plus__plus__rp_(_x_x1331, _x_x1333, _ctx); /*string*/
    }
  }
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1309, _x_x1316, _ctx);
}
 
// Show an instant as a number of (TAI) SI seconds since the `epoch` in a given precision.
// This can be used as an unambiguous time stamp.

kk_string_t kk_std_time_instant_instant_fs_show(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_context_t* _ctx) { /* (i : instant, max-prec : ? int, secs-width : ? int) -> string */ 
  kk_std_time_instant__instant i_0_10187;
  bool _match_x323;
  kk_string_t _x_x1337;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1338 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1339 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1340 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x1340->name;
      kk_string_t _pat_0 = _con_x1340->unit;
      kk_function_t _pat_1 = _con_x1340->from_tai;
      kk_function_t _pat_2 = _con_x1340->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x1340->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x1340->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x1340->mb_from_mjd2000;
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
      _x_x1337 = _x; /*string*/
    }
  }
  kk_string_t _x_x1341;
  kk_std_time_instant__timescale _x_x1342 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  {
    struct kk_std_time_instant_Timescale* _con_x1343 = kk_std_time_instant__as_Timescale(_x_x1342, _ctx);
    kk_string_t _x_1 = _con_x1343->name;
    _x_x1341 = kk_string_dup(_x_1, _ctx); /*string*/
  }
  _match_x323 = kk_string_is_eq(_x_x1337,_x_x1341,kk_context()); /*bool*/
  if (_match_x323) {
    i_0_10187 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1344;
    kk_std_time_instant__timescale _x_x1345 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
    _x_x1344 = kk_std_time_instant_timestamp_in(i, _x_x1345, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x1346 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
    i_0_10187 = kk_std_time_instant__new_Instant(_x_x1344, _x_x1346, _ctx); /*std/time/instant/instant*/
  }
  kk_integer_t _b_x96_100;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x95 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3011 = kk_integer_unbox(_box_x95, _ctx);
    kk_integer_dup(_uniq_max_prec_3011, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x96_100 = _uniq_max_prec_3011; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x96_100 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x98_101;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x97 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_3015 = kk_integer_unbox(_box_x97, _ctx);
    kk_integer_dup(_uniq_secs_width_3015, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x98_101 = _uniq_secs_width_3015; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x98_101 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _b_x99_102;
  kk_define_string_literal(, _s_x1347, 1, "s", _ctx)
  _b_x99_102 = kk_string_dup(_s_x1347, _ctx); /*string*/
  kk_string_t _x_x1348;
  kk_std_time_timestamp__timestamp _x_x1349;
  {
    kk_std_time_timestamp__timestamp _x_2 = i_0_10187.since;
    kk_std_time_instant__timescale _pat_2_3 = i_0_10187.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1350 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1351 = kk_std_time_instant__as_Timescale(_pat_2_3, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
    _x_x1349 = _x_2; /*std/time/timestamp/timestamp*/
  }
  kk_std_core_types__optional _x_x1352 = kk_std_core_types__new_Optional(kk_integer_box(_b_x96_100, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1353 = kk_std_core_types__new_Optional(kk_integer_box(_b_x98_101, _ctx), _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1354 = kk_std_core_types__new_Optional(kk_string_box(_b_x99_102), _ctx); /*? 10003*/
  _x_x1348 = kk_std_time_timestamp_ts_show(_x_x1349, _x_x1352, _x_x1353, _x_x1354, _ctx); /*string*/
  kk_string_t _x_x1355;
  bool _match_x321;
  kk_string_t _x_x1356;
  {
    kk_std_time_timestamp__timestamp _pat_0_2_0 = i_0_10187.since;
    kk_std_time_instant__timescale _x_1_0 = i_0_10187.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1357 = kk_std_time_timestamp__as_Timestamp(_pat_0_2_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1358 = kk_std_time_instant__as_Timescale(_x_1_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1359 = kk_std_time_instant__as_Timescale(_x_1_0, _ctx);
      kk_string_t _x_0_0 = _con_x1359->name;
      kk_string_t _pat_0_1_0 = _con_x1359->unit;
      kk_function_t _pat_1_1_0 = _con_x1359->from_tai;
      kk_function_t _pat_2_1_0 = _con_x1359->to_tai;
      kk_std_core_types__maybe _pat_3_1_0 = _con_x1359->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_1_0 = _con_x1359->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_0_0 = _con_x1359->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_0_0, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_1_0, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_1_0, _ctx);
        kk_function_drop(_pat_2_1_0, _ctx);
        kk_function_drop(_pat_1_1_0, _ctx);
        kk_string_drop(_pat_0_1_0, _ctx);
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_string_dup(_x_0_0, _ctx);
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x1356 = _x_0_0; /*string*/
    }
  }
  kk_string_t _x_x1360 = kk_string_empty(); /*string*/
  _match_x321 = kk_string_is_eq(_x_x1356,_x_x1360,kk_context()); /*bool*/
  if (_match_x321) {
    kk_std_time_instant__instant_drop(i_0_10187, _ctx);
    _x_x1355 = kk_string_empty(); /*string*/
  }
  else {
    bool _match_x322;
    kk_string_t _x_x1363;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i_0_10187.since;
      kk_std_time_instant__timescale _x_3 = i_0_10187.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x1364 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x1365 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x1366 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
        kk_string_t _x_2_0 = _con_x1366->name;
        kk_string_t _pat_0_3_0 = _con_x1366->unit;
        kk_function_t _pat_1_3_0 = _con_x1366->from_tai;
        kk_function_t _pat_2_3_0 = _con_x1366->to_tai;
        kk_std_core_types__maybe _pat_3_3_0 = _con_x1366->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3_0 = _con_x1366->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3 = _con_x1366->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_3, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_3_0, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_3_0, _ctx);
          kk_function_drop(_pat_2_3_0, _ctx);
          kk_function_drop(_pat_1_3_0, _ctx);
          kk_string_drop(_pat_0_3_0, _ctx);
          kk_datatype_ptr_free(_x_3, _ctx);
        }
        else {
          kk_string_dup(_x_2_0, _ctx);
          kk_datatype_ptr_decref(_x_3, _ctx);
        }
        _x_x1363 = _x_2_0; /*string*/
      }
    }
    kk_string_t _x_x1367;
    kk_define_string_literal(, _s_x1368, 3, "TAI", _ctx)
    _x_x1367 = kk_string_dup(_s_x1368, _ctx); /*string*/
    _match_x322 = kk_string_is_eq(_x_x1363,_x_x1367,kk_context()); /*bool*/
    if (_match_x322) {
      kk_std_time_instant__instant_drop(i_0_10187, _ctx);
      _x_x1355 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x1370;
      kk_define_string_literal(, _s_x1371, 1, " ", _ctx)
      _x_x1370 = kk_string_dup(_s_x1371, _ctx); /*string*/
      kk_string_t _x_x1372;
      {
        kk_std_time_timestamp__timestamp _pat_0_6 = i_0_10187.since;
        kk_std_time_instant__timescale _x_5 = i_0_10187.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1373 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1374 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
        kk_std_time_instant__timescale_dup(_x_5, _ctx);
        kk_std_time_instant__instant_drop(i_0_10187, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1375 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
          kk_string_t _x_4 = _con_x1375->name;
          kk_string_t _pat_0_5 = _con_x1375->unit;
          kk_function_t _pat_1_5 = _con_x1375->from_tai;
          kk_function_t _pat_2_5 = _con_x1375->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x1375->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x1375->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_5 = _con_x1375->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_5, _ctx);
            kk_function_drop(_pat_2_5, _ctx);
            kk_function_drop(_pat_1_5, _ctx);
            kk_string_drop(_pat_0_5, _ctx);
            kk_datatype_ptr_free(_x_5, _ctx);
          }
          else {
            kk_string_dup(_x_4, _ctx);
            kk_datatype_ptr_decref(_x_5, _ctx);
          }
          _x_x1372 = _x_4; /*string*/
        }
      }
      _x_x1355 = kk_std_core_types__lp__plus__plus__rp_(_x_x1370, _x_x1372, _ctx); /*string*/
    }
  }
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1348, _x_x1355, _ctx);
}
 
// Our epoch is set at 2000-01-01 TAI (which is equal to 1999-12-31T23:59:28Z UTC).
//
// Another candidate epoch could have been the standard [J2000] epoch ([`epoch-j2000`](std_time_astro.html#epoch_j2000)),
// which equals 2000-01-01T12:00:00 TT (terrestrial time).
// However, that would mean that for the most common time scales, namely UTC and TAI, there would always be a
// fractional offset (of 32.184s) for common time stamps. Moreover, by having an epoch at noon there would be
// an extra correction needed for calendar date calculations too.
//
// Similarly, the standard Unix epoch of 1970-01-01Z UTC is not ideal either since the UTC offset with TAI
// was fractional at that time (namely 8.000082s).
//
// Finally, after 1996, TAI was corrected for black-body radiation [@blackbody] which makes
// the 2000-01-01 epoch a very precisely defined point in time.
//
//
// [J2000]: https://en.wikipedia.org/wiki/Equinox_(celestial_coordinates)#J2000.0

kk_std_time_instant__instant kk_std_time_instant_epoch;
 
// The [GPS](https://en.wikipedia.org/wiki/Global_Positioning_System#Timekeeping) time scale based
// on SI seconds with a 1980-01-06 GPS epoch.
// GPS = TAI - 19s.


// lift anonymous function
struct kk_std_time_instant_ts_gps_fun1399__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_gps_fun1399(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_gps_fun1399(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun1399__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_gps_fun1399__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_ts_gps_fun1399, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_gps_fun1399(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun1399__t* _self = kk_function_as(struct kk_std_time_instant_ts_gps_fun1399__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_10026;
  kk_std_num_ddouble__ddouble _x_x1400;
  {
    kk_std_num_ddouble__ddouble _x_0 = tai.secs;
    _x_x1400 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1401;
  {
    kk_std_num_ddouble__ddouble _x = _uniq_offset_847.secs;
    _x_x1401 = _x; /*std/time/timestamp/timespan*/
  }
  t_10026 = kk_std_num_ddouble__lp__plus__rp_(_x_x1400, _x_x1401, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1402;
  kk_integer_t _x_x1403;
  kk_std_core_types__optional _match_x314 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x314, _ctx)) {
    kk_box_t _box_x117 = _match_x314._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x117, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x314, _ctx);
    _x_x1403 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x314, _ctx);
    _x_x1403 = kk_integer_from_small(0); /*int*/
  }
  _x_x1402 = kk_integer_clamp32(_x_x1403,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10026, _x_x1402, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_gps_fun1404__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_gps_fun1404(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_gps_fun1404(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun1404__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_gps_fun1404__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_ts_gps_fun1404, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_ts_gps_fun1404(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_gps_fun1404__t* _self = kk_function_as(struct kk_std_time_instant_ts_gps_fun1404__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_1_10029;
  kk_std_num_ddouble__ddouble _x_x1405;
  {
    kk_std_num_ddouble__ddouble _x_1 = _uniq_offset_847.secs;
    _x_x1405 = _x_1; /*std/time/timestamp/timespan*/
  }
  t_1_10029 = kk_std_time_timestamp__lp__dash__rp_(t_0, _x_x1405, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x1406 = kk_std_time_timestamp_unsafe_timespan_withleap(t_1_10029, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x1406, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_gps;

kk_std_time_duration__duration kk_std_time_instant_gps2000;
 
// Get the GPS time in SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_duration__duration kk_std_time_instant_gps_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10205;
  kk_std_time_instant__timescale _x_x1417 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_gps, _ctx); /*std/time/instant/timescale*/
  t_10205 = kk_std_time_instant_timestamp_in(i, _x_x1417, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration d_10203;
  kk_std_num_ddouble__ddouble _x_x1418 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10205, _ctx); /*std/time/timestamp/timespan*/
  d_10203 = kk_std_time_duration__new_Duration(_x_x1418, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x1419;
  kk_std_num_ddouble__ddouble _x_x1420;
  {
    kk_std_num_ddouble__ddouble _x = d_10203.secs;
    _x_x1420 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1421;
  kk_std_time_duration__duration _x_x1422 = kk_std_time_instant_gps2000; /*std/time/duration/duration*/
  {
    kk_std_num_ddouble__ddouble _x_0 = _x_x1422.secs;
    _x_x1421 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x1419 = kk_std_num_ddouble__lp__plus__rp_(_x_x1420, _x_x1421, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x1419, _ctx);
}
 
// Create an instant from a raw GPS time since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_duration_fs_gps_instant(kk_std_time_duration__duration gps, kk_context_t* _ctx) { /* (gps : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_10206 = kk_std_time_duration__lp__dash__rp_(gps, kk_std_time_instant_gps2000, _ctx); /*std/time/duration/duration*/;
  kk_std_time_timestamp__timestamp t_10208;
  kk_std_num_ddouble__ddouble _x_x1423;
  {
    kk_std_num_ddouble__ddouble _x = d_10206.secs;
    _x_x1423 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1424;
  kk_integer_t _x_x1425;
  kk_std_core_types__optional _match_x308 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x308, _ctx)) {
    kk_box_t _box_x126 = _match_x308._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x126, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x308, _ctx);
    _x_x1425 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x308, _ctx);
    _x_x1425 = kk_integer_from_small(0); /*int*/
  }
  _x_x1424 = kk_integer_clamp32(_x_x1425,kk_context()); /*int32*/
  t_10208 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1423, _x_x1424, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1426 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10208, _x_x1426, _ctx);
}
 
// Get the GPS time as weeks and SI seconds in the week since the GPS epoch (1980-01-06Z)

kk_std_core_types__tuple2 kk_std_time_instant_gps_week_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/duration/duration) */ 
  kk_std_time_duration__duration t = kk_std_time_instant_gps_timestamp(i, _ctx); /*std/time/duration/duration*/;
  kk_integer_t w;
  kk_std_num_ddouble__ddouble _x_x1427;
  kk_std_num_ddouble__ddouble _x_x1428;
  kk_std_num_ddouble__ddouble _x_x1429;
  {
    kk_std_num_ddouble__ddouble _x = t.secs;
    _x_x1429 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1430 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(25200, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _x_x1428 = kk_std_num_ddouble__lp__fs__rp_(_x_x1429, _x_x1430, _ctx); /*std/num/ddouble/ddouble*/
  _x_x1427 = kk_std_num_ddouble_floor(_x_x1428, _ctx); /*std/num/ddouble/ddouble*/
  w = kk_std_num_ddouble_int(_x_x1427, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_integer_t secs_10214;
  kk_integer_t _x_x1431 = kk_integer_dup(w, _ctx); /*int*/
  secs_10214 = kk_integer_mul(_x_x1431,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/
  kk_std_core_types__optional frac_0_10006;
  kk_box_t _x_x1432;
  double _x_x1433;
  kk_std_core_types__optional _match_x307 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x307, _ctx)) {
    kk_box_t _box_x127 = _match_x307._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x127, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x307, _ctx);
    _x_x1433 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x307, _ctx);
    _x_x1433 = 0x0p+0; /*float64*/
  }
  _x_x1432 = kk_double_box(_x_x1433, _ctx); /*10003*/
  frac_0_10006 = kk_std_core_types__new_Optional(_x_x1432, _ctx); /*? float64*/
  kk_std_time_duration__duration e_10213;
  kk_std_num_ddouble__ddouble _x_x1434;
  bool _match_x306;
  double _x_x1435;
  if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
    kk_box_t _box_x130 = frac_0_10006._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x130, KK_BORROWED, _ctx);
    _x_x1435 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x1435 = 0x0p+0; /*float64*/
  }
  _match_x306 = (_x_x1435 == (0x0p+0)); /*bool*/
  if (_match_x306) {
    kk_std_core_types__optional_drop(frac_0_10006, _ctx);
    _x_x1434 = kk_std_num_ddouble_ddouble_int_exp(secs_10214, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x1436 = kk_std_num_ddouble_ddouble_int_exp(secs_10214, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1437;
    double _x_x1438;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x131 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x131, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1438 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1438 = 0x0p+0; /*float64*/
    }
    _x_x1437 = kk_std_num_ddouble__new_Ddouble(_x_x1438, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1434 = kk_std_num_ddouble__lp__plus__rp_(_x_x1436, _x_x1437, _ctx); /*std/num/ddouble/ddouble*/
  }
  e_10213 = kk_std_time_duration__new_Duration(_x_x1434, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration e_0_10055;
  kk_std_num_ddouble__ddouble _x_x1439;
  double _x_x1440;
  double _x_x1441;
  {
    kk_std_num_ddouble__ddouble _x_1 = e_10213.secs;
    {
      double _x_0 = _x_1.hi;
      _x_x1441 = _x_0; /*float64*/
    }
  }
  _x_x1440 = (-_x_x1441); /*float64*/
  double _x_x1442;
  double _x_x1443;
  {
    kk_std_num_ddouble__ddouble _x_1_0 = e_10213.secs;
    {
      double _x_0_0 = _x_1_0.lo;
      _x_x1443 = _x_0_0; /*float64*/
    }
  }
  _x_x1442 = (-_x_x1443); /*float64*/
  _x_x1439 = kk_std_num_ddouble__new_Ddouble(_x_x1440, _x_x1442, _ctx); /*std/num/ddouble/ddouble*/
  e_0_10055 = kk_std_time_duration__new_Duration(_x_x1439, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration s;
  kk_std_num_ddouble__ddouble _x_x1444;
  kk_std_num_ddouble__ddouble _x_x1445;
  {
    kk_std_num_ddouble__ddouble _x_2 = t.secs;
    _x_x1445 = _x_2; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1446;
  {
    kk_std_num_ddouble__ddouble _x_0_0_0 = e_0_10055.secs;
    _x_x1446 = _x_0_0_0; /*std/time/timestamp/timespan*/
  }
  _x_x1444 = kk_std_num_ddouble__lp__plus__rp_(_x_x1445, _x_x1446, _ctx); /*std/num/ddouble/ddouble*/
  s = kk_std_time_duration__new_Duration(_x_x1444, _ctx); /*std/time/duration/duration*/
  return kk_std_core_types__new_Tuple2(kk_integer_box(w, _ctx), kk_std_time_duration__duration_box(s, _ctx), _ctx);
}
 
// Create an instant from a GPS time in weeks and SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_date_fs_gps_instant(kk_integer_t weeks, kk_std_time_duration__duration secs, kk_context_t* _ctx) { /* (weeks : int, secs : std/time/duration/duration) -> instant */ 
  kk_integer_t secs_0_10219 = kk_integer_mul(weeks,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/;
  kk_std_core_types__optional frac_0_10006;
  kk_box_t _x_x1447;
  double _x_x1448;
  kk_std_core_types__optional _match_x305 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x305, _ctx)) {
    kk_box_t _box_x136 = _match_x305._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x136, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x305, _ctx);
    _x_x1448 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x305, _ctx);
    _x_x1448 = 0x0p+0; /*float64*/
  }
  _x_x1447 = kk_double_box(_x_x1448, _ctx); /*10003*/
  frac_0_10006 = kk_std_core_types__new_Optional(_x_x1447, _ctx); /*? float64*/
  kk_std_time_duration__duration d_1_10217;
  kk_std_num_ddouble__ddouble _x_x1449;
  bool _match_x304;
  double _x_x1450;
  if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
    kk_box_t _box_x139 = frac_0_10006._cons._Optional.value;
    double _uniq_frac_1144 = kk_double_unbox(_box_x139, KK_BORROWED, _ctx);
    _x_x1450 = _uniq_frac_1144; /*float64*/
  }
  else {
    _x_x1450 = 0x0p+0; /*float64*/
  }
  _match_x304 = (_x_x1450 == (0x0p+0)); /*bool*/
  if (_match_x304) {
    kk_std_core_types__optional_drop(frac_0_10006, _ctx);
    _x_x1449 = kk_std_num_ddouble_ddouble_int_exp(secs_0_10219, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  }
  else {
    kk_std_num_ddouble__ddouble _x_x1451 = kk_std_num_ddouble_ddouble_int_exp(secs_0_10219, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    kk_std_num_ddouble__ddouble _x_x1452;
    double _x_x1453;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x140 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144_0 = kk_double_unbox(_box_x140, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1453 = _uniq_frac_1144_0; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1453 = 0x0p+0; /*float64*/
    }
    _x_x1452 = kk_std_num_ddouble__new_Ddouble(_x_x1453, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x1449 = kk_std_num_ddouble__lp__plus__rp_(_x_x1451, _x_x1452, _ctx); /*std/num/ddouble/ddouble*/
  }
  d_1_10217 = kk_std_time_duration__new_Duration(_x_x1449, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration gps_10216;
  kk_std_num_ddouble__ddouble _x_x1454;
  kk_std_num_ddouble__ddouble _x_x1455;
  {
    kk_std_num_ddouble__ddouble _x_0 = d_1_10217.secs;
    _x_x1455 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1456;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = secs.secs;
    _x_x1456 = _x_0_0; /*std/time/timestamp/timespan*/
  }
  _x_x1454 = kk_std_num_ddouble__lp__plus__rp_(_x_x1455, _x_x1456, _ctx); /*std/num/ddouble/ddouble*/
  gps_10216 = kk_std_time_duration__new_Duration(_x_x1454, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration d_10221 = kk_std_time_duration__lp__dash__rp_(gps_10216, kk_std_time_instant_gps2000, _ctx); /*std/time/duration/duration*/;
  kk_std_time_timestamp__timestamp t_10223;
  kk_std_num_ddouble__ddouble _x_x1457;
  {
    kk_std_num_ddouble__ddouble _x = d_10221.secs;
    _x_x1457 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1458;
  kk_integer_t _x_x1459;
  kk_std_core_types__optional _match_x303 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x303, _ctx)) {
    kk_box_t _box_x141 = _match_x303._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x141, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x303, _ctx);
    _x_x1459 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x303, _ctx);
    _x_x1459 = kk_integer_from_small(0); /*int*/
  }
  _x_x1458 = kk_integer_clamp32(_x_x1459,kk_context()); /*int32*/
  t_10223 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1457, _x_x1458, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1460 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10223, _x_x1460, _ctx);
}
 
// The [TT](https://en.wikipedia.org/wiki/Terrestrial_Time) (Terrestrial time)
// time scale is based on SI seconds with a 1977-01-01 TAI `epoch`. It is the
// continuation of TDT (Terrestrial dynamic time) and ET (Ephemeris time). TT
// is defined as: TT = TAI + 32.184s.


// lift anonymous function
struct kk_std_time_instant_ts_tt_fun1466__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_848;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tt_fun1466(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tt_fun1466(kk_std_time_duration__duration _uniq_offset_848, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun1466__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tt_fun1466__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_ts_tt_fun1466, kk_context());
  _self->_uniq_offset_848 = _uniq_offset_848;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_ts_tt_fun1466(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun1466__t* _self = kk_function_as(struct kk_std_time_instant_ts_tt_fun1466__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_848 = _self->_uniq_offset_848; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_848, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_10026;
  kk_std_num_ddouble__ddouble _x_x1467;
  {
    kk_std_num_ddouble__ddouble _x_0 = tai.secs;
    _x_x1467 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1468;
  {
    kk_std_num_ddouble__ddouble _x = _uniq_offset_848.secs;
    _x_x1468 = _x; /*std/time/timestamp/timespan*/
  }
  t_10026 = kk_std_num_ddouble__lp__plus__rp_(_x_x1467, _x_x1468, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x1469;
  kk_integer_t _x_x1470;
  kk_std_core_types__optional _match_x302 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x302, _ctx)) {
    kk_box_t _box_x142 = _match_x302._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x142, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x302, _ctx);
    _x_x1470 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x302, _ctx);
    _x_x1470 = kk_integer_from_small(0); /*int*/
  }
  _x_x1469 = kk_integer_clamp32(_x_x1470,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10026, _x_x1469, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_ts_tt_fun1471__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_848;
};
static kk_std_time_duration__duration kk_std_time_instant_ts_tt_fun1471(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_ts_tt_fun1471(kk_std_time_duration__duration _uniq_offset_848, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun1471__t* _self = kk_function_alloc_as(struct kk_std_time_instant_ts_tt_fun1471__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_ts_tt_fun1471, kk_context());
  _self->_uniq_offset_848 = _uniq_offset_848;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_ts_tt_fun1471(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx) {
  struct kk_std_time_instant_ts_tt_fun1471__t* _self = kk_function_as(struct kk_std_time_instant_ts_tt_fun1471__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_848 = _self->_uniq_offset_848; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_848, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_1_10029;
  kk_std_num_ddouble__ddouble _x_x1472;
  {
    kk_std_num_ddouble__ddouble _x_1 = _uniq_offset_848.secs;
    _x_x1472 = _x_1; /*std/time/timestamp/timespan*/
  }
  t_1_10029 = kk_std_time_timestamp__lp__dash__rp_(t_0, _x_x1472, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x1473 = kk_std_time_timestamp_unsafe_timespan_withleap(t_1_10029, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x1473, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_ts_tt;

kk_std_time_duration__duration kk_std_time_instant_tt2000;
 
// Get the TT time in SI seconds since the TT epoch (1977-01-01 TAI)

kk_std_time_duration__duration kk_std_time_instant_instant_fs_tt_instant(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10230;
  kk_std_time_instant__timescale _x_x1484 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tt, _ctx); /*std/time/instant/timescale*/
  t_10230 = kk_std_time_instant_timestamp_in(i, _x_x1484, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration d_10228;
  kk_std_num_ddouble__ddouble _x_x1485 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10230, _ctx); /*std/time/timestamp/timespan*/
  d_10228 = kk_std_time_duration__new_Duration(_x_x1485, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x1486;
  kk_std_num_ddouble__ddouble _x_x1487;
  {
    kk_std_num_ddouble__ddouble _x = d_10228.secs;
    _x_x1487 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x1488;
  kk_std_time_duration__duration _x_x1489 = kk_std_time_instant_tt2000; /*std/time/duration/duration*/
  {
    kk_std_num_ddouble__ddouble _x_0 = _x_x1489.secs;
    _x_x1488 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x1486 = kk_std_num_ddouble__lp__plus__rp_(_x_x1487, _x_x1488, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x1486, _ctx);
}
 
// Create an instant from a raw TT time since the TT epoch (1977-01-01 TAI)

kk_std_time_instant__instant kk_std_time_instant_duration_fs_tt_instant(kk_std_time_duration__duration tt, kk_context_t* _ctx) { /* (tt : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_10231 = kk_std_time_duration__lp__dash__rp_(tt, kk_std_time_instant_tt2000, _ctx); /*std/time/duration/duration*/;
  kk_std_time_timestamp__timestamp t_10233;
  kk_std_num_ddouble__ddouble _x_x1490;
  {
    kk_std_num_ddouble__ddouble _x = d_10231.secs;
    _x_x1490 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x1491;
  kk_integer_t _x_x1492;
  kk_std_core_types__optional _match_x296 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x296, _ctx)) {
    kk_box_t _box_x151 = _match_x296._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x151, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x296, _ctx);
    _x_x1492 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x296, _ctx);
    _x_x1492 = kk_integer_from_small(0); /*int*/
  }
  _x_x1491 = kk_integer_clamp32(_x_x1492,kk_context()); /*int32*/
  t_10233 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1490, _x_x1491, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x1493 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10233, _x_x1493, _ctx);
}
 
// Show a timestamp with an optional maximum precision (`max-prec` (=`9`)) and
// minimum width for the seconds (=`1`).

kk_string_t kk_std_time_instant_timestamp_fs_show(kk_std_time_timestamp__timestamp t, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_std_core_types__optional _x_x1494;
  kk_box_t _x_x1495;
  kk_integer_t _x_x1496;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x152 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3270 = kk_integer_unbox(_box_x152, _ctx);
    kk_integer_dup(_uniq_max_prec_3270, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x1496 = _uniq_max_prec_3270; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x1496 = kk_integer_from_small(9); /*int*/
  }
  _x_x1495 = kk_integer_box(_x_x1496, _ctx); /*10003*/
  _x_x1494 = kk_std_core_types__new_Optional(_x_x1495, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1497;
  kk_box_t _x_x1498;
  kk_integer_t _x_x1499;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x154 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_3274 = kk_integer_unbox(_box_x154, _ctx);
    kk_integer_dup(_uniq_secs_width_3274, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x_x1499 = _uniq_secs_width_3274; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x_x1499 = kk_integer_from_small(1); /*int*/
  }
  _x_x1498 = kk_integer_box(_x_x1499, _ctx); /*10003*/
  _x_x1497 = kk_std_core_types__new_Optional(_x_x1498, _ctx); /*? 10003*/
  kk_std_core_types__optional _x_x1500;
  kk_box_t _x_x1501;
  kk_string_t _x_x1502;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x156 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_3278 = kk_string_unbox(_box_x156);
    kk_string_dup(_uniq_unit_3278, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x1502 = _uniq_unit_3278; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x1502 = kk_string_empty(); /*string*/
  }
  _x_x1501 = kk_string_box(_x_x1502); /*10003*/
  _x_x1500 = kk_std_core_types__new_Optional(_x_x1501, _ctx); /*? 10003*/
  return kk_std_time_timestamp_ts_show(t, _x_x1494, _x_x1497, _x_x1500, _ctx);
}
 
// /*----------------------------------------------------------------------------
//   Julian Date
// ----------------------------------------------------------------------------*/

kk_std_num_ddouble__ddouble kk_std_time_instant_jd_epoch_delta;
 
// relative to the MJD epoch

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd_epoch_delta;
 
// Create an instant given a [modified julian day](https://en.wikipedia.org/wiki/Julian_day).
// and time scale `ts`.
// `modified-julian-day = julian-day - 2400000.5`

kk_std_time_instant__instant kk_std_time_instant_ddouble_fs_instant_at_mjd(kk_std_num_ddouble__ddouble mjd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (mjd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble d;
  kk_std_num_ddouble__ddouble _x_x1508;
  double _x_x1509;
  double _x_x1510;
  kk_std_num_ddouble__ddouble _x_x1511 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1511.hi;
    _x_x1510 = _x; /*float64*/
  }
  _x_x1509 = (-_x_x1510); /*float64*/
  double _x_x1512;
  double _x_x1513;
  kk_std_num_ddouble__ddouble _x_x1514 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x1514.lo;
    _x_x1513 = _x_0; /*float64*/
  }
  _x_x1512 = (-_x_x1513); /*float64*/
  _x_x1508 = kk_std_num_ddouble__new_Ddouble(_x_x1509, _x_x1512, _ctx); /*std/num/ddouble/ddouble*/
  d = kk_std_num_ddouble__lp__plus__rp_(mjd_0, _x_x1508, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble days_0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1515;
  double _x_x1516;
  double _x_x1517;
  {
    double _x_1 = days_0.hi;
    _x_x1517 = _x_1; /*float64*/
  }
  _x_x1516 = (-_x_x1517); /*float64*/
  double _x_x1518;
  double _x_x1519;
  {
    double _x_0_0 = days_0.lo;
    _x_x1519 = _x_0_0; /*float64*/
  }
  _x_x1518 = (-_x_x1519); /*float64*/
  _x_x1515 = kk_std_num_ddouble__new_Ddouble(_x_x1516, _x_x1518, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(d, _x_x1515, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t idays = kk_std_num_ddouble_int(days_0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  {
    struct kk_std_time_instant_Timescale* _con_x1520 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_std_core_types__maybe _x_2 = _con_x1520->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_num_ddouble__ddouble secs_10245 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_time_timestamp__timestamp t_10248;
      kk_std_core_types__optional _x_x1521 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_10245, _ctx), _ctx); /*? 10003*/
      kk_std_core_types__optional _x_x1522;
      kk_box_t _x_x1523;
      kk_integer_t _x_x1524;
      kk_std_core_types__optional _match_x292 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x292, _ctx)) {
        kk_box_t _box_x164 = _match_x292._cons._Optional.value;
        kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x164, _ctx);
        kk_integer_dup(_uniq_leap_1920, _ctx);
        kk_std_core_types__optional_drop(_match_x292, _ctx);
        _x_x1524 = _uniq_leap_1920; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x292, _ctx);
        _x_x1524 = kk_integer_from_small(0); /*int*/
      }
      _x_x1523 = kk_integer_box(_x_x1524, _ctx); /*10003*/
      _x_x1522 = kk_std_core_types__new_Optional(_x_x1523, _ctx); /*? 10003*/
      t_10248 = kk_std_time_timestamp_timestamp_days(idays, _x_x1521, _x_x1522, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(t_10248, ts, _ctx);
    }
    {
      kk_box_t _fun_unbox_x173 = _x_2._cons.Just.value;
      kk_std_time_timestamp__timestamp _x_x1525;
      kk_box_t _x_x1526;
      kk_function_t _x_x1527 = kk_function_unbox(_fun_unbox_x173, _ctx); /*(days : 174, frac : 175) -> 176*/
      _x_x1526 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1527, (_x_x1527, kk_integer_box(idays, _ctx), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx), _ctx); /*176*/
      _x_x1525 = kk_std_time_timestamp__timestamp_unbox(_x_x1526, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(_x_x1525, ts, _ctx);
    }
  }
}
 
// Create an instant given a [modified julian day](https://en.wikipedia.org/wiki/Julian_day).
// and time scale `ts`.
// `modified-julian-day = julian-day - 2400000.5`

kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_mjd(double mjd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (mjd : float64, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble d;
  kk_std_num_ddouble__ddouble _x_x1528 = kk_std_num_ddouble__new_Ddouble(mjd_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1529;
  double _x_x1530;
  double _x_x1531;
  kk_std_num_ddouble__ddouble _x_x1532 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1532.hi;
    _x_x1531 = _x; /*float64*/
  }
  _x_x1530 = (-_x_x1531); /*float64*/
  double _x_x1533;
  double _x_x1534;
  kk_std_num_ddouble__ddouble _x_x1535 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x1535.lo;
    _x_x1534 = _x_0; /*float64*/
  }
  _x_x1533 = (-_x_x1534); /*float64*/
  _x_x1529 = kk_std_num_ddouble__new_Ddouble(_x_x1530, _x_x1533, _ctx); /*std/num/ddouble/ddouble*/
  d = kk_std_num_ddouble__lp__plus__rp_(_x_x1528, _x_x1529, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble days_0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1536;
  double _x_x1537;
  double _x_x1538;
  {
    double _x_1 = days_0.hi;
    _x_x1538 = _x_1; /*float64*/
  }
  _x_x1537 = (-_x_x1538); /*float64*/
  double _x_x1539;
  double _x_x1540;
  {
    double _x_0_0 = days_0.lo;
    _x_x1540 = _x_0_0; /*float64*/
  }
  _x_x1539 = (-_x_x1540); /*float64*/
  _x_x1536 = kk_std_num_ddouble__new_Ddouble(_x_x1537, _x_x1539, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(d, _x_x1536, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t idays = kk_std_num_ddouble_int(days_0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  {
    struct kk_std_time_instant_Timescale* _con_x1541 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_std_core_types__maybe _x_2 = _con_x1541->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_num_ddouble__ddouble secs_10245 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_time_timestamp__timestamp t_10248;
      kk_std_core_types__optional _x_x1542 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_10245, _ctx), _ctx); /*? 10003*/
      kk_std_core_types__optional _x_x1543;
      kk_box_t _x_x1544;
      kk_integer_t _x_x1545;
      kk_std_core_types__optional _match_x291 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x291, _ctx)) {
        kk_box_t _box_x182 = _match_x291._cons._Optional.value;
        kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x182, _ctx);
        kk_integer_dup(_uniq_leap_1920, _ctx);
        kk_std_core_types__optional_drop(_match_x291, _ctx);
        _x_x1545 = _uniq_leap_1920; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x291, _ctx);
        _x_x1545 = kk_integer_from_small(0); /*int*/
      }
      _x_x1544 = kk_integer_box(_x_x1545, _ctx); /*10003*/
      _x_x1543 = kk_std_core_types__new_Optional(_x_x1544, _ctx); /*? 10003*/
      t_10248 = kk_std_time_timestamp_timestamp_days(idays, _x_x1542, _x_x1543, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(t_10248, ts, _ctx);
    }
    {
      kk_box_t _fun_unbox_x191 = _x_2._cons.Just.value;
      kk_std_time_timestamp__timestamp _x_x1546;
      kk_box_t _x_x1547;
      kk_function_t _x_x1548 = kk_function_unbox(_fun_unbox_x191, _ctx); /*(days : 192, frac : 193) -> 194*/
      _x_x1547 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1548, (_x_x1548, kk_integer_box(idays, _ctx), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx), _ctx); /*194*/
      _x_x1546 = kk_std_time_timestamp__timestamp_unbox(_x_x1547, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(_x_x1546, ts, _ctx);
    }
  }
}
 
// Create an instant given a [julian day](https://en.wikipedia.org/wiki/Julian_day)
// and time scale `ts` .

kk_std_time_instant__instant kk_std_time_instant_ddouble_fs_instant_at_jd(kk_std_num_ddouble__ddouble jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (jd : std/num/ddouble/ddouble, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble mjd_0_10304;
  kk_std_num_ddouble__ddouble _x_x1549;
  double _x_x1550;
  double _x_x1551;
  kk_std_num_ddouble__ddouble _x_x1552 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_3 = _x_x1552.hi;
    _x_x1551 = _x_3; /*float64*/
  }
  _x_x1550 = (-_x_x1551); /*float64*/
  double _x_x1553;
  double _x_x1554;
  kk_std_num_ddouble__ddouble _x_x1555 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0_1 = _x_x1555.lo;
    _x_x1554 = _x_0_1; /*float64*/
  }
  _x_x1553 = (-_x_x1554); /*float64*/
  _x_x1549 = kk_std_num_ddouble__new_Ddouble(_x_x1550, _x_x1553, _ctx); /*std/num/ddouble/ddouble*/
  mjd_0_10304 = kk_std_num_ddouble__lp__plus__rp_(jd_0, _x_x1549, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble d;
  kk_std_num_ddouble__ddouble _x_x1556;
  double _x_x1557;
  double _x_x1558;
  kk_std_num_ddouble__ddouble _x_x1559 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1559.hi;
    _x_x1558 = _x; /*float64*/
  }
  _x_x1557 = (-_x_x1558); /*float64*/
  double _x_x1560;
  double _x_x1561;
  kk_std_num_ddouble__ddouble _x_x1562 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x1562.lo;
    _x_x1561 = _x_0; /*float64*/
  }
  _x_x1560 = (-_x_x1561); /*float64*/
  _x_x1556 = kk_std_num_ddouble__new_Ddouble(_x_x1557, _x_x1560, _ctx); /*std/num/ddouble/ddouble*/
  d = kk_std_num_ddouble__lp__plus__rp_(mjd_0_10304, _x_x1556, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble days_0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1563;
  double _x_x1564;
  double _x_x1565;
  {
    double _x_1 = days_0.hi;
    _x_x1565 = _x_1; /*float64*/
  }
  _x_x1564 = (-_x_x1565); /*float64*/
  double _x_x1566;
  double _x_x1567;
  {
    double _x_0_0 = days_0.lo;
    _x_x1567 = _x_0_0; /*float64*/
  }
  _x_x1566 = (-_x_x1567); /*float64*/
  _x_x1563 = kk_std_num_ddouble__new_Ddouble(_x_x1564, _x_x1566, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(d, _x_x1563, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t idays = kk_std_num_ddouble_int(days_0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  {
    struct kk_std_time_instant_Timescale* _con_x1568 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_std_core_types__maybe _x_2 = _con_x1568->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_num_ddouble__ddouble secs_10245 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_time_timestamp__timestamp t_10248;
      kk_std_core_types__optional _x_x1569 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_10245, _ctx), _ctx); /*? 10003*/
      kk_std_core_types__optional _x_x1570;
      kk_box_t _x_x1571;
      kk_integer_t _x_x1572;
      kk_std_core_types__optional _match_x290 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x290, _ctx)) {
        kk_box_t _box_x200 = _match_x290._cons._Optional.value;
        kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x200, _ctx);
        kk_integer_dup(_uniq_leap_1920, _ctx);
        kk_std_core_types__optional_drop(_match_x290, _ctx);
        _x_x1572 = _uniq_leap_1920; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x290, _ctx);
        _x_x1572 = kk_integer_from_small(0); /*int*/
      }
      _x_x1571 = kk_integer_box(_x_x1572, _ctx); /*10003*/
      _x_x1570 = kk_std_core_types__new_Optional(_x_x1571, _ctx); /*? 10003*/
      t_10248 = kk_std_time_timestamp_timestamp_days(idays, _x_x1569, _x_x1570, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(t_10248, ts, _ctx);
    }
    {
      kk_box_t _fun_unbox_x209 = _x_2._cons.Just.value;
      kk_std_time_timestamp__timestamp _x_x1573;
      kk_box_t _x_x1574;
      kk_function_t _x_x1575 = kk_function_unbox(_fun_unbox_x209, _ctx); /*(days : 210, frac : 211) -> 212*/
      _x_x1574 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1575, (_x_x1575, kk_integer_box(idays, _ctx), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx), _ctx); /*212*/
      _x_x1573 = kk_std_time_timestamp__timestamp_unbox(_x_x1574, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(_x_x1573, ts, _ctx);
    }
  }
}
 
// Create an instant given a [julian day](https://en.wikipedia.org/wiki/Julian_day).

kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_jd(double jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (jd : float64, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble mjd_0_10306;
  kk_std_num_ddouble__ddouble _x_x1576 = kk_std_num_ddouble__new_Ddouble(jd_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x1577;
  double _x_x1578;
  double _x_x1579;
  kk_std_num_ddouble__ddouble _x_x1580 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_3 = _x_x1580.hi;
    _x_x1579 = _x_3; /*float64*/
  }
  _x_x1578 = (-_x_x1579); /*float64*/
  double _x_x1581;
  double _x_x1582;
  kk_std_num_ddouble__ddouble _x_x1583 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0_1 = _x_x1583.lo;
    _x_x1582 = _x_0_1; /*float64*/
  }
  _x_x1581 = (-_x_x1582); /*float64*/
  _x_x1577 = kk_std_num_ddouble__new_Ddouble(_x_x1578, _x_x1581, _ctx); /*std/num/ddouble/ddouble*/
  mjd_0_10306 = kk_std_num_ddouble__lp__plus__rp_(_x_x1576, _x_x1577, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble d;
  kk_std_num_ddouble__ddouble _x_x1584;
  double _x_x1585;
  double _x_x1586;
  kk_std_num_ddouble__ddouble _x_x1587 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x1587.hi;
    _x_x1586 = _x; /*float64*/
  }
  _x_x1585 = (-_x_x1586); /*float64*/
  double _x_x1588;
  double _x_x1589;
  kk_std_num_ddouble__ddouble _x_x1590 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x1590.lo;
    _x_x1589 = _x_0; /*float64*/
  }
  _x_x1588 = (-_x_x1589); /*float64*/
  _x_x1584 = kk_std_num_ddouble__new_Ddouble(_x_x1585, _x_x1588, _ctx); /*std/num/ddouble/ddouble*/
  d = kk_std_num_ddouble__lp__plus__rp_(mjd_0_10306, _x_x1584, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble days_0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x1591;
  double _x_x1592;
  double _x_x1593;
  {
    double _x_1 = days_0.hi;
    _x_x1593 = _x_1; /*float64*/
  }
  _x_x1592 = (-_x_x1593); /*float64*/
  double _x_x1594;
  double _x_x1595;
  {
    double _x_0_0 = days_0.lo;
    _x_x1595 = _x_0_0; /*float64*/
  }
  _x_x1594 = (-_x_x1595); /*float64*/
  _x_x1591 = kk_std_num_ddouble__new_Ddouble(_x_x1592, _x_x1594, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(d, _x_x1591, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t idays = kk_std_num_ddouble_int(days_0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  {
    struct kk_std_time_instant_Timescale* _con_x1596 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_std_core_types__maybe _x_2 = _con_x1596->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_num_ddouble__ddouble secs_10245 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/;
      kk_std_time_timestamp__timestamp t_10248;
      kk_std_core_types__optional _x_x1597 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_10245, _ctx), _ctx); /*? 10003*/
      kk_std_core_types__optional _x_x1598;
      kk_box_t _x_x1599;
      kk_integer_t _x_x1600;
      kk_std_core_types__optional _match_x289 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x289, _ctx)) {
        kk_box_t _box_x218 = _match_x289._cons._Optional.value;
        kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x218, _ctx);
        kk_integer_dup(_uniq_leap_1920, _ctx);
        kk_std_core_types__optional_drop(_match_x289, _ctx);
        _x_x1600 = _uniq_leap_1920; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x289, _ctx);
        _x_x1600 = kk_integer_from_small(0); /*int*/
      }
      _x_x1599 = kk_integer_box(_x_x1600, _ctx); /*10003*/
      _x_x1598 = kk_std_core_types__new_Optional(_x_x1599, _ctx); /*? 10003*/
      t_10248 = kk_std_time_timestamp_timestamp_days(idays, _x_x1597, _x_x1598, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(t_10248, ts, _ctx);
    }
    {
      kk_box_t _fun_unbox_x227 = _x_2._cons.Just.value;
      kk_std_time_timestamp__timestamp _x_x1601;
      kk_box_t _x_x1602;
      kk_function_t _x_x1603 = kk_function_unbox(_fun_unbox_x227, _ctx); /*(days : 228, frac : 229) -> 230*/
      _x_x1602 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1603, (_x_x1603, kk_integer_box(idays, _ctx), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx), _ctx); /*230*/
      _x_x1601 = kk_std_time_timestamp__timestamp_unbox(_x_x1602, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(_x_x1601, ts, _ctx);
    }
  }
}
 
// Return the modified julian day in a given time scale `ts` for an instant `i`.
// Can also pass an optional `delta` (=`timespan0`) that is added to the raw timestamp of `i`
// before conversion (used in `std/time/time` to take timezones into account)

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx) { /* (i : instant, tscale : timescale, tzdelta : ? std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 
  kk_std_time_instant__instant i0;
  bool _match_x288;
  kk_string_t _x_x1604;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1605 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1606 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1607 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x1607->name;
      kk_string_t _pat_0_1 = _con_x1607->unit;
      kk_function_t _pat_1_1 = _con_x1607->from_tai;
      kk_function_t _pat_2 = _con_x1607->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x1607->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x1607->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x1607->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_3, _ctx);
        kk_function_drop(_pat_2, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1604 = _x; /*string*/
    }
  }
  kk_string_t _x_x1608;
  {
    struct kk_std_time_instant_Timescale* _con_x1609 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_1 = _con_x1609->name;
    kk_string_dup(_x_1, _ctx);
    _x_x1608 = _x_1; /*string*/
  }
  _match_x288 = kk_string_is_eq(_x_x1604,_x_x1608,kk_context()); /*bool*/
  if (_match_x288) {
    i0 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1610;
    kk_std_time_instant__timescale _x_x1611 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    _x_x1610 = kk_std_time_instant_timestamp_in(i, _x_x1611, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x1612 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    i0 = kk_std_time_instant__new_Instant(_x_x1610, _x_x1612, _ctx); /*std/time/instant/instant*/
  }
  kk_std_num_ddouble__ddouble mjd_0;
  {
    struct kk_std_time_instant_Timescale* _con_x1613 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _pat_0_0_0 = _con_x1613->name;
    kk_string_t _pat_1_0_0 = _con_x1613->unit;
    kk_function_t _pat_2_2 = _con_x1613->from_tai;
    kk_function_t _pat_3_2 = _con_x1613->to_tai;
    kk_std_core_types__maybe _pat_4_2 = _con_x1613->mb_seconds_in_day;
    kk_std_core_types__maybe _x_2 = _con_x1613->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_2 = _con_x1613->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_time_instant__instant i_0_10173;
      bool _match_x287;
      kk_string_t _x_x1614;
      {
        kk_std_time_timestamp__timestamp _pat_0_0_1 = i0.since;
        kk_std_time_instant__timescale _x_0_0 = i0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1615 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1616 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1617 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
          kk_string_t _x_3 = _con_x1617->name;
          kk_string_t _pat_0 = _con_x1617->unit;
          kk_function_t _pat_1_3 = _con_x1617->from_tai;
          kk_function_t _pat_2_3 = _con_x1617->to_tai;
          kk_std_core_types__maybe _pat_3_3 = _con_x1617->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_3 = _con_x1617->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_3 = _con_x1617->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_3, _ctx);
            kk_function_drop(_pat_2_3, _ctx);
            kk_function_drop(_pat_1_3, _ctx);
            kk_string_drop(_pat_0, _ctx);
            kk_datatype_ptr_free(_x_0_0, _ctx);
          }
          else {
            kk_string_dup(_x_3, _ctx);
            kk_datatype_ptr_decref(_x_0_0, _ctx);
          }
          _x_x1614 = _x_3; /*string*/
        }
      }
      kk_string_t _x_x1618;
      {
        struct kk_std_time_instant_Timescale* _con_x1619 = kk_std_time_instant__as_Timescale(tscale, _ctx);
        kk_string_t _x_1_0 = _con_x1619->name;
        kk_string_dup(_x_1_0, _ctx);
        _x_x1618 = _x_1_0; /*string*/
      }
      _match_x287 = kk_string_is_eq(_x_x1614,_x_x1618,kk_context()); /*bool*/
      if (_match_x287) {
        if kk_likely(kk_datatype_ptr_is_unique(tscale, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_2, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_2, _ctx);
          kk_function_drop(_pat_3_2, _ctx);
          kk_function_drop(_pat_2_2, _ctx);
          kk_string_drop(_pat_1_0_0, _ctx);
          kk_string_drop(_pat_0_0_0, _ctx);
          kk_datatype_ptr_free(tscale, _ctx);
        }
        else {
          kk_datatype_ptr_decref(tscale, _ctx);
        }
        i_0_10173 = i0; /*std/time/instant/instant*/
      }
      else {
        kk_std_time_timestamp__timestamp _x_x1620;
        kk_std_time_instant__timescale _x_x1621 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
        _x_x1620 = kk_std_time_instant_timestamp_in(i0, _x_x1621, _ctx); /*std/time/timestamp/timestamp*/
        i_0_10173 = kk_std_time_instant__new_Instant(_x_x1620, tscale, _ctx); /*std/time/instant/instant*/
      }
      kk_std_time_instant__instant i1;
      kk_std_time_timestamp__timestamp _x_x1622;
      kk_std_num_ddouble__ddouble _x_x1623;
      kk_std_num_ddouble__ddouble _x_x1624;
      {
        kk_std_time_timestamp__timestamp _x_1_0_0 = i_0_10173.since;
        kk_std_time_instant__timescale _pat_2_1_0_0 = i_0_10173.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1625 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1626 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1627 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
          kk_std_num_ddouble__ddouble _x_2_0 = _con_x1627->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_0_0, _ctx);
          }
          _x_x1624 = _x_2_0; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x1628;
      if (kk_std_core_types__is_Optional(tzdelta, _ctx)) {
        kk_box_t _box_x235 = tzdelta._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_tzdelta_3443 = kk_std_num_ddouble__ddouble_unbox(_box_x235, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x1628 = _uniq_tzdelta_3443; /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x1628 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
      }
      _x_x1623 = kk_std_num_ddouble__lp__plus__rp_(_x_x1624, _x_x1628, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1629;
      {
        kk_std_time_timestamp__timestamp _x_1_0_0_0 = i_0_10173.since;
        kk_std_time_instant__timescale _pat_2_1_0_0_0 = i_0_10173.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1630 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1631 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_0_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1632 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x1632->since;
          int32_t _x_0_0_0 = _con_x1632->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_0_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_0_0_0, _ctx);
          }
          _x_x1629 = _x_0_0_0; /*int32*/
        }
      }
      _x_x1622 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1623, _x_x1629, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x1633;
      {
        kk_std_time_timestamp__timestamp _pat_0_2_0_0 = i_0_10173.since;
        kk_std_time_instant__timescale _x_2_0_0 = i_0_10173.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1634 = kk_std_time_timestamp__as_Timestamp(_pat_0_2_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1635 = kk_std_time_instant__as_Timescale(_x_2_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_2_0_0, _ctx);
        kk_std_time_instant__instant_drop(i_0_10173, _ctx);
        _x_x1633 = _x_2_0_0; /*std/time/instant/timescale*/
      }
      i1 = kk_std_time_instant__new_Instant(_x_x1622, _x_x1633, _ctx); /*std/time/instant/instant*/
      kk_std_num_ddouble__ddouble secs;
      kk_std_num_ddouble__ddouble _x_x1636;
      {
        kk_std_time_timestamp__timestamp _x_1_1 = i1.since;
        kk_std_time_instant__timescale _pat_2_0_1 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1637 = kk_std_time_timestamp__as_Timestamp(_x_1_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1638 = kk_std_time_instant__as_Timescale(_pat_2_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_1, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1639 = kk_std_time_timestamp__as_Timestamp(_x_1_1, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x1639->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_1, _ctx)) {
            kk_datatype_ptr_free(_x_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_1, _ctx);
          }
          _x_x1636 = _x_3_0; /*std/time/timestamp/timespan*/
        }
      }
      secs = kk_std_num_ddouble_floor(_x_x1636, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble frac;
      kk_std_num_ddouble__ddouble _x_x1640;
      {
        kk_std_time_timestamp__timestamp _x_1_1_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_0_1_0 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1641 = kk_std_time_timestamp__as_Timestamp(_x_1_1_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1642 = kk_std_time_instant__as_Timescale(_pat_2_0_1_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_1_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1643 = kk_std_time_timestamp__as_Timestamp(_x_1_1_0, _ctx);
          kk_std_num_ddouble__ddouble _x_1_0_1 = _con_x1643->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_1_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_1_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_1_0, _ctx);
          }
          _x_x1640 = _x_1_0_1; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x1644;
      double _x_x1645;
      double _x_x1646;
      {
        double _x_0_0_1 = secs.hi;
        _x_x1646 = _x_0_0_1; /*float64*/
      }
      _x_x1645 = (-_x_x1646); /*float64*/
      double _x_x1647;
      double _x_x1648;
      {
        double _x_0_0_0_0 = secs.lo;
        _x_x1648 = _x_0_0_0_0; /*float64*/
      }
      _x_x1647 = (-_x_x1648); /*float64*/
      _x_x1644 = kk_std_num_ddouble__new_Ddouble(_x_x1645, _x_x1647, _ctx); /*std/num/ddouble/ddouble*/
      frac = kk_std_num_ddouble__lp__plus__rp_(_x_x1640, _x_x1644, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__tuple2 tuple2_10075;
      kk_std_core_types__tuple2 _match_x286;
      kk_integer_t _x_x1649 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
      _match_x286 = kk_std_core_int_divmod(_x_x1649, kk_integer_from_int(86400, _ctx), _ctx); /*(int, int)*/
      {
        kk_box_t _box_x236 = _match_x286.fst;
        kk_box_t _box_x237 = _match_x286.snd;
        kk_integer_t days_0 = kk_integer_unbox(_box_x236, _ctx);
        kk_integer_t dsecs = kk_integer_unbox(_box_x237, _ctx);
        kk_integer_dup(days_0, _ctx);
        kk_integer_dup(dsecs, _ctx);
        kk_std_core_types__tuple2_drop(_match_x286, _ctx);
        kk_std_num_ddouble__ddouble _b_x239_241;
        kk_std_num_ddouble__ddouble _x_x1650 = kk_std_num_ddouble_ddouble_int_exp(dsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        _b_x239_241 = kk_std_num_ddouble__lp__plus__rp_(_x_x1650, frac, _ctx); /*std/num/ddouble/ddouble*/
        tuple2_10075 = kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_num_ddouble__ddouble_box(_b_x239_241, _ctx), _ctx); /*(int, std/num/ddouble/ddouble)*/
      }
      kk_std_num_ddouble__ddouble days_0_0;
      kk_integer_t _x_x1651;
      {
        kk_box_t _box_x242 = tuple2_10075.fst;
        kk_box_t _box_x243 = tuple2_10075.snd;
        kk_integer_t _x_0_1 = kk_integer_unbox(_box_x242, _ctx);
        kk_integer_dup(_x_0_1, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
        _x_x1651 = _x_0_1; /*int*/
      }
      days_0_0 = kk_std_num_ddouble_ddouble_int_exp(_x_x1651, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__tuple2 tuple2_10076;
      kk_std_time_timestamp__timestamp _x_x1652;
      {
        kk_std_time_timestamp__timestamp _x_3_0_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_2_0_1 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1653 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1654 = kk_std_time_instant__as_Timescale(_pat_2_2_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_0_0, _ctx);
        _x_x1652 = _x_3_0_0; /*std/time/timestamp/timestamp*/
      }
      tuple2_10076 = kk_std_time_timestamp_days_seconds(_x_x1652, _ctx); /*(int, std/num/ddouble/ddouble)*/
      kk_integer_t i_10077;
      int32_t _x_x1655;
      {
        kk_std_time_timestamp__timestamp _x_3_0_0_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_2_0_0_0 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1656 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1657 = kk_std_time_instant__as_Timescale(_pat_2_2_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_0_0_0, _ctx);
        kk_std_time_instant__instant_drop(i1, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1658 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_0_0_1 = _con_x1658->since;
          int32_t _x_0_0_1_0 = _con_x1658->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_3_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_3_0_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_3_0_0_0, _ctx);
          }
          _x_x1655 = _x_0_0_1_0; /*int32*/
        }
      }
      i_10077 = kk_integer_from_int(_x_x1655,kk_context()); /*int*/
      kk_std_num_ddouble__ddouble frac_0;
      kk_std_num_ddouble__ddouble _x_x1659;
      kk_std_num_ddouble__ddouble _x_x1660;
      {
        kk_box_t _box_x244 = tuple2_10076.fst;
        kk_box_t _box_x245 = tuple2_10076.snd;
        kk_std_num_ddouble__ddouble _x_2_0_1 = kk_std_num_ddouble__ddouble_unbox(_box_x245, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10076, _ctx);
        _x_x1660 = _x_2_0_1; /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x1661 = kk_std_num_ddouble_ddouble_int_exp(i_10077, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x1659 = kk_std_num_ddouble__lp__plus__rp_(_x_x1660, _x_x1661, _ctx); /*std/num/ddouble/ddouble*/
      frac_0 = kk_std_num_ddouble__lp__fs__rp_(_x_x1659, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      mjd_0 = kk_std_num_ddouble__lp__plus__rp_(days_0_0, frac_0, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_box_t _fun_unbox_x251 = _x_2._cons.Just.value;
      if kk_likely(kk_datatype_ptr_is_unique(tscale, _ctx)) {
        kk_std_core_types__maybe_drop(_x_2, _ctx);
        kk_std_core_types__maybe_drop(_pat_5_2, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_2, _ctx);
        kk_function_drop(_pat_3_2, _ctx);
        kk_function_drop(_pat_2_2, _ctx);
        kk_string_drop(_pat_1_0_0, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(tscale, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tscale, _ctx);
      }
      kk_box_t _x_x1662;
      kk_function_t _x_x1669 = kk_function_unbox(_fun_unbox_x251, _ctx); /*(t : 252, tzdelta : 253) -> 254*/
      kk_box_t _x_x1663;
      kk_std_time_timestamp__timestamp _x_x1664;
      {
        kk_std_time_timestamp__timestamp _x_4 = i0.since;
        kk_std_time_instant__timescale _pat_2_4 = i0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1665 = kk_std_time_timestamp__as_Timestamp(_x_4, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1666 = kk_std_time_instant__as_Timescale(_pat_2_4, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_4, _ctx);
        kk_std_time_instant__instant_drop(i0, _ctx);
        _x_x1664 = _x_4; /*std/time/timestamp/timestamp*/
      }
      _x_x1663 = kk_std_time_timestamp__timestamp_box(_x_x1664, _ctx); /*252*/
      kk_box_t _x_x1667;
      kk_std_num_ddouble__ddouble _x_x1668;
      if (kk_std_core_types__is_Optional(tzdelta, _ctx)) {
        kk_box_t _box_x257 = tzdelta._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_tzdelta_3443_0 = kk_std_num_ddouble__ddouble_unbox(_box_x257, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x1668 = _uniq_tzdelta_3443_0; /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x1668 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
      }
      _x_x1667 = kk_std_num_ddouble__ddouble_box(_x_x1668, _ctx); /*253*/
      _x_x1662 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1669, (_x_x1669, _x_x1663, _x_x1667, _ctx), _ctx); /*254*/
      mjd_0 = kk_std_num_ddouble__ddouble_unbox(_x_x1662, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_num_ddouble__lp__plus__rp_(mjd_0, kk_std_time_instant_mjd_epoch_delta, _ctx);
}
 
// /* Return the julian day in a given time scale `ts` for an instant `i`.
// Properly takes leap seconds into account when calculating the fraction of the day
// in a UTC calendar. For example:
// ````
// > time(2014,12,31,23,59,59).jd
// 2457023.499988425925926
// 
// > time(2015,12,31,23,59,59).jd
// 2457388.499988425925926
// 
// > time(2016,12,31,23,59,59).jd
// 2457754.499976852119767
// 
// > time(2016,12,31,23,59,60).jd
// 2457754.499988426059884
// ````
// .
// */

kk_std_num_ddouble__ddouble kk_std_time_instant_jd(kk_std_time_instant__instant i, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (i : instant, ts : timescale) -> std/num/ddouble/ddouble */ 
  kk_std_time_instant__instant i0;
  bool _match_x285;
  kk_string_t _x_x1670;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x1671 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x1672 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x1673 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x1673->name;
      kk_string_t _pat_0_1 = _con_x1673->unit;
      kk_function_t _pat_1_1 = _con_x1673->from_tai;
      kk_function_t _pat_2 = _con_x1673->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x1673->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x1673->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x1673->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_3, _ctx);
        kk_function_drop(_pat_2, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_string_dup(_x, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      _x_x1670 = _x; /*string*/
    }
  }
  kk_string_t _x_x1674;
  {
    struct kk_std_time_instant_Timescale* _con_x1675 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _x_1 = _con_x1675->name;
    kk_string_dup(_x_1, _ctx);
    _x_x1674 = _x_1; /*string*/
  }
  _match_x285 = kk_string_is_eq(_x_x1670,_x_x1674,kk_context()); /*bool*/
  if (_match_x285) {
    i0 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x1676;
    kk_std_time_instant__timescale _x_x1677 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
    _x_x1676 = kk_std_time_instant_timestamp_in(i, _x_x1677, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x1678 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
    i0 = kk_std_time_instant__new_Instant(_x_x1676, _x_x1678, _ctx); /*std/time/instant/instant*/
  }
  kk_std_num_ddouble__ddouble mjd_0;
  {
    struct kk_std_time_instant_Timescale* _con_x1679 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _pat_0_0_0 = _con_x1679->name;
    kk_string_t _pat_1_0_0 = _con_x1679->unit;
    kk_function_t _pat_2_2 = _con_x1679->from_tai;
    kk_function_t _pat_3_2 = _con_x1679->to_tai;
    kk_std_core_types__maybe _pat_4_2 = _con_x1679->mb_seconds_in_day;
    kk_std_core_types__maybe _x_2 = _con_x1679->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_2 = _con_x1679->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_time_instant__instant i_0_10173;
      bool _match_x284;
      kk_string_t _x_x1680;
      {
        kk_std_time_timestamp__timestamp _pat_0_0_1 = i0.since;
        kk_std_time_instant__timescale _x_0_0 = i0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1681 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1682 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x1683 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
          kk_string_t _x_3 = _con_x1683->name;
          kk_string_t _pat_0 = _con_x1683->unit;
          kk_function_t _pat_1_3 = _con_x1683->from_tai;
          kk_function_t _pat_2_3 = _con_x1683->to_tai;
          kk_std_core_types__maybe _pat_3_3 = _con_x1683->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_3 = _con_x1683->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_3 = _con_x1683->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_3, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_3, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_3, _ctx);
            kk_function_drop(_pat_2_3, _ctx);
            kk_function_drop(_pat_1_3, _ctx);
            kk_string_drop(_pat_0, _ctx);
            kk_datatype_ptr_free(_x_0_0, _ctx);
          }
          else {
            kk_string_dup(_x_3, _ctx);
            kk_datatype_ptr_decref(_x_0_0, _ctx);
          }
          _x_x1680 = _x_3; /*string*/
        }
      }
      kk_string_t _x_x1684;
      {
        struct kk_std_time_instant_Timescale* _con_x1685 = kk_std_time_instant__as_Timescale(ts, _ctx);
        kk_string_t _x_1_0 = _con_x1685->name;
        kk_string_dup(_x_1_0, _ctx);
        _x_x1684 = _x_1_0; /*string*/
      }
      _match_x284 = kk_string_is_eq(_x_x1680,_x_x1684,kk_context()); /*bool*/
      if (_match_x284) {
        if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_2, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_2, _ctx);
          kk_function_drop(_pat_3_2, _ctx);
          kk_function_drop(_pat_2_2, _ctx);
          kk_string_drop(_pat_1_0_0, _ctx);
          kk_string_drop(_pat_0_0_0, _ctx);
          kk_datatype_ptr_free(ts, _ctx);
        }
        else {
          kk_datatype_ptr_decref(ts, _ctx);
        }
        i_0_10173 = i0; /*std/time/instant/instant*/
      }
      else {
        kk_std_time_timestamp__timestamp _x_x1686;
        kk_std_time_instant__timescale _x_x1687 = kk_std_time_instant__timescale_dup(ts, _ctx); /*std/time/instant/timescale*/
        _x_x1686 = kk_std_time_instant_timestamp_in(i0, _x_x1687, _ctx); /*std/time/timestamp/timestamp*/
        i_0_10173 = kk_std_time_instant__new_Instant(_x_x1686, ts, _ctx); /*std/time/instant/instant*/
      }
      kk_std_time_instant__instant i1;
      kk_std_time_timestamp__timestamp _x_x1688;
      kk_std_num_ddouble__ddouble _x_x1689;
      kk_std_num_ddouble__ddouble _x_x1690;
      {
        kk_std_time_timestamp__timestamp _x_1_0_0 = i_0_10173.since;
        kk_std_time_instant__timescale _pat_2_1_0_0 = i_0_10173.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1691 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1692 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1693 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
          kk_std_num_ddouble__ddouble _x_2_0 = _con_x1693->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_0_0, _ctx);
          }
          _x_x1690 = _x_2_0; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x1694;
      kk_std_core_types__optional _match_x283 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x283, _ctx)) {
        kk_box_t _box_x258 = _match_x283._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_tzdelta_3443 = kk_std_num_ddouble__ddouble_unbox(_box_x258, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x283, _ctx);
        _x_x1694 = _uniq_tzdelta_3443; /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x283, _ctx);
        _x_x1694 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
      }
      _x_x1689 = kk_std_num_ddouble__lp__plus__rp_(_x_x1690, _x_x1694, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x1695;
      {
        kk_std_time_timestamp__timestamp _x_1_0_0_0 = i_0_10173.since;
        kk_std_time_instant__timescale _pat_2_1_0_0_0 = i_0_10173.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1696 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1697 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_0_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1698 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x1698->since;
          int32_t _x_0_0_0 = _con_x1698->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_0_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_0_0_0, _ctx);
          }
          _x_x1695 = _x_0_0_0; /*int32*/
        }
      }
      _x_x1688 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1689, _x_x1695, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x1699;
      {
        kk_std_time_timestamp__timestamp _pat_0_2_0_0 = i_0_10173.since;
        kk_std_time_instant__timescale _x_2_0_0 = i_0_10173.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1700 = kk_std_time_timestamp__as_Timestamp(_pat_0_2_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1701 = kk_std_time_instant__as_Timescale(_x_2_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_2_0_0, _ctx);
        kk_std_time_instant__instant_drop(i_0_10173, _ctx);
        _x_x1699 = _x_2_0_0; /*std/time/instant/timescale*/
      }
      i1 = kk_std_time_instant__new_Instant(_x_x1688, _x_x1699, _ctx); /*std/time/instant/instant*/
      kk_std_num_ddouble__ddouble secs;
      kk_std_num_ddouble__ddouble _x_x1702;
      {
        kk_std_time_timestamp__timestamp _x_1_1 = i1.since;
        kk_std_time_instant__timescale _pat_2_0_1 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1703 = kk_std_time_timestamp__as_Timestamp(_x_1_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1704 = kk_std_time_instant__as_Timescale(_pat_2_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_1, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1705 = kk_std_time_timestamp__as_Timestamp(_x_1_1, _ctx);
          kk_std_num_ddouble__ddouble _x_3_0 = _con_x1705->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_1, _ctx)) {
            kk_datatype_ptr_free(_x_1_1, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_1, _ctx);
          }
          _x_x1702 = _x_3_0; /*std/time/timestamp/timespan*/
        }
      }
      secs = kk_std_num_ddouble_floor(_x_x1702, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble frac;
      kk_std_num_ddouble__ddouble _x_x1706;
      {
        kk_std_time_timestamp__timestamp _x_1_1_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_0_1_0 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1707 = kk_std_time_timestamp__as_Timestamp(_x_1_1_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1708 = kk_std_time_instant__as_Timescale(_pat_2_0_1_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_1_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1709 = kk_std_time_timestamp__as_Timestamp(_x_1_1_0, _ctx);
          kk_std_num_ddouble__ddouble _x_1_0_1 = _con_x1709->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_1_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_1_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_1_0, _ctx);
          }
          _x_x1706 = _x_1_0_1; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x1710;
      double _x_x1711;
      double _x_x1712;
      {
        double _x_0_0_1 = secs.hi;
        _x_x1712 = _x_0_0_1; /*float64*/
      }
      _x_x1711 = (-_x_x1712); /*float64*/
      double _x_x1713;
      double _x_x1714;
      {
        double _x_0_0_0_0 = secs.lo;
        _x_x1714 = _x_0_0_0_0; /*float64*/
      }
      _x_x1713 = (-_x_x1714); /*float64*/
      _x_x1710 = kk_std_num_ddouble__new_Ddouble(_x_x1711, _x_x1713, _ctx); /*std/num/ddouble/ddouble*/
      frac = kk_std_num_ddouble__lp__plus__rp_(_x_x1706, _x_x1710, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__tuple2 tuple2_10075;
      kk_std_core_types__tuple2 _match_x282;
      kk_integer_t _x_x1715 = kk_std_num_ddouble_int(secs, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
      _match_x282 = kk_std_core_int_divmod(_x_x1715, kk_integer_from_int(86400, _ctx), _ctx); /*(int, int)*/
      {
        kk_box_t _box_x259 = _match_x282.fst;
        kk_box_t _box_x260 = _match_x282.snd;
        kk_integer_t days_0 = kk_integer_unbox(_box_x259, _ctx);
        kk_integer_t dsecs = kk_integer_unbox(_box_x260, _ctx);
        kk_integer_dup(days_0, _ctx);
        kk_integer_dup(dsecs, _ctx);
        kk_std_core_types__tuple2_drop(_match_x282, _ctx);
        kk_std_num_ddouble__ddouble _b_x262_264;
        kk_std_num_ddouble__ddouble _x_x1716 = kk_std_num_ddouble_ddouble_int_exp(dsecs, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        _b_x262_264 = kk_std_num_ddouble__lp__plus__rp_(_x_x1716, frac, _ctx); /*std/num/ddouble/ddouble*/
        tuple2_10075 = kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_num_ddouble__ddouble_box(_b_x262_264, _ctx), _ctx); /*(int, std/num/ddouble/ddouble)*/
      }
      kk_std_num_ddouble__ddouble days_0_0;
      kk_integer_t _x_x1717;
      {
        kk_box_t _box_x265 = tuple2_10075.fst;
        kk_box_t _box_x266 = tuple2_10075.snd;
        kk_integer_t _x_0_1 = kk_integer_unbox(_box_x265, _ctx);
        kk_integer_dup(_x_0_1, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10075, _ctx);
        _x_x1717 = _x_0_1; /*int*/
      }
      days_0_0 = kk_std_num_ddouble_ddouble_int_exp(_x_x1717, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__tuple2 tuple2_10076;
      kk_std_time_timestamp__timestamp _x_x1718;
      {
        kk_std_time_timestamp__timestamp _x_3_0_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_2_0_1 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1719 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1720 = kk_std_time_instant__as_Timescale(_pat_2_2_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_0_0, _ctx);
        _x_x1718 = _x_3_0_0; /*std/time/timestamp/timestamp*/
      }
      tuple2_10076 = kk_std_time_timestamp_days_seconds(_x_x1718, _ctx); /*(int, std/num/ddouble/ddouble)*/
      kk_integer_t i_10077;
      int32_t _x_x1721;
      {
        kk_std_time_timestamp__timestamp _x_3_0_0_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_2_0_0_0 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1722 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1723 = kk_std_time_instant__as_Timescale(_pat_2_2_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_0_0_0, _ctx);
        kk_std_time_instant__instant_drop(i1, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x1724 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_0_0_1 = _con_x1724->since;
          int32_t _x_0_0_1_0 = _con_x1724->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_3_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_3_0_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_3_0_0_0, _ctx);
          }
          _x_x1721 = _x_0_0_1_0; /*int32*/
        }
      }
      i_10077 = kk_integer_from_int(_x_x1721,kk_context()); /*int*/
      kk_std_num_ddouble__ddouble frac_0;
      kk_std_num_ddouble__ddouble _x_x1725;
      kk_std_num_ddouble__ddouble _x_x1726;
      {
        kk_box_t _box_x267 = tuple2_10076.fst;
        kk_box_t _box_x268 = tuple2_10076.snd;
        kk_std_num_ddouble__ddouble _x_2_0_1 = kk_std_num_ddouble__ddouble_unbox(_box_x268, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10076, _ctx);
        _x_x1726 = _x_2_0_1; /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x1727 = kk_std_num_ddouble_ddouble_int_exp(i_10077, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x1725 = kk_std_num_ddouble__lp__plus__rp_(_x_x1726, _x_x1727, _ctx); /*std/num/ddouble/ddouble*/
      frac_0 = kk_std_num_ddouble__lp__fs__rp_(_x_x1725, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      mjd_0 = kk_std_num_ddouble__lp__plus__rp_(days_0_0, frac_0, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_box_t _fun_unbox_x274 = _x_2._cons.Just.value;
      if kk_likely(kk_datatype_ptr_is_unique(ts, _ctx)) {
        kk_std_core_types__maybe_drop(_x_2, _ctx);
        kk_std_core_types__maybe_drop(_pat_5_2, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_2, _ctx);
        kk_function_drop(_pat_3_2, _ctx);
        kk_function_drop(_pat_2_2, _ctx);
        kk_string_drop(_pat_1_0_0, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(ts, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ts, _ctx);
      }
      kk_box_t _x_x1728;
      kk_function_t _x_x1735 = kk_function_unbox(_fun_unbox_x274, _ctx); /*(t : 275, tzdelta : 276) -> 277*/
      kk_box_t _x_x1729;
      kk_std_time_timestamp__timestamp _x_x1730;
      {
        kk_std_time_timestamp__timestamp _x_4 = i0.since;
        kk_std_time_instant__timescale _pat_2_4 = i0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x1731 = kk_std_time_timestamp__as_Timestamp(_x_4, _ctx);
        struct kk_std_time_instant_Timescale* _con_x1732 = kk_std_time_instant__as_Timescale(_pat_2_4, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_4, _ctx);
        kk_std_time_instant__instant_drop(i0, _ctx);
        _x_x1730 = _x_4; /*std/time/timestamp/timestamp*/
      }
      _x_x1729 = kk_std_time_timestamp__timestamp_box(_x_x1730, _ctx); /*275*/
      kk_box_t _x_x1733;
      kk_std_num_ddouble__ddouble _x_x1734;
      kk_std_core_types__optional _match_x281 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x281, _ctx)) {
        kk_box_t _box_x280 = _match_x281._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_tzdelta_3443_0 = kk_std_num_ddouble__ddouble_unbox(_box_x280, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x281, _ctx);
        _x_x1734 = _uniq_tzdelta_3443_0; /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x281, _ctx);
        _x_x1734 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
      }
      _x_x1733 = kk_std_num_ddouble__ddouble_box(_x_x1734, _ctx); /*276*/
      _x_x1728 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1735, (_x_x1735, _x_x1729, _x_x1733, _ctx), _ctx); /*277*/
      mjd_0 = kk_std_num_ddouble__ddouble_unbox(_x_x1728, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  kk_std_num_ddouble__ddouble _x_x1736 = kk_std_num_ddouble__lp__plus__rp_(mjd_0, kk_std_time_instant_mjd_epoch_delta, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_num_ddouble__lp__plus__rp_(_x_x1736, kk_std_time_instant_jd_epoch_delta, _ctx);
}

// initialization
void kk_std_time_instant__init(kk_context_t* _ctx){
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
  kk_std_num_ddouble__init(_ctx);
  kk_std_time_timestamp__init(_ctx);
  kk_std_time_duration__init(_ctx);
  kk_std_time_date__init(_ctx);
  kk_std_num_float64__init(_ctx);
  kk_std_num_int32__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_time_duration__duration _uniq_offset_847;
    kk_std_core_types__optional _match_x396 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x396, _ctx)) {
      kk_box_t _box_x36 = _match_x396._cons._Optional.value;
      kk_std_time_duration__duration _uniq_offset_848 = kk_std_time_duration__duration_unbox(_box_x36, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x396, _ctx);
      _uniq_offset_847 = _uniq_offset_848; /*std/time/duration/duration*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x396, _ctx);
      kk_std_core_types__optional frac_0_10006;
      kk_box_t _x_x675;
      double _x_x676;
      kk_std_core_types__optional _match_x398 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x398, _ctx)) {
        kk_box_t _box_x37 = _match_x398._cons._Optional.value;
        double _uniq_frac_155 = kk_double_unbox(_box_x37, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x398, _ctx);
        _x_x676 = _uniq_frac_155; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x398, _ctx);
        _x_x676 = 0x0p+0; /*float64*/
      }
      _x_x675 = kk_double_box(_x_x676, _ctx); /*10003*/
      frac_0_10006 = kk_std_core_types__new_Optional(_x_x675, _ctx); /*? float64*/
      kk_std_num_ddouble__ddouble _x_x677;
      bool _match_x397;
      double _x_x678;
      if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
        kk_box_t _box_x40 = frac_0_10006._cons._Optional.value;
        double _uniq_frac_1144 = kk_double_unbox(_box_x40, KK_BORROWED, _ctx);
        _x_x678 = _uniq_frac_1144; /*float64*/
      }
      else {
        _x_x678 = 0x0p+0; /*float64*/
      }
      _match_x397 = (_x_x678 == (0x0p+0)); /*bool*/
      if (_match_x397) {
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x677 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble _x_x679 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _x_x680;
        double _x_x681;
        if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
          kk_box_t _box_x41 = frac_0_10006._cons._Optional.value;
          double _uniq_frac_1144_0 = kk_double_unbox(_box_x41, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(frac_0_10006, _ctx);
          _x_x681 = _uniq_frac_1144_0; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(frac_0_10006, _ctx);
          _x_x681 = 0x0p+0; /*float64*/
        }
        _x_x680 = kk_std_num_ddouble__new_Ddouble(_x_x681, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        _x_x677 = kk_std_num_ddouble__lp__plus__rp_(_x_x679, _x_x680, _ctx); /*std/num/ddouble/ddouble*/
      }
      _uniq_offset_847 = kk_std_time_duration__new_Duration(_x_x677, _ctx); /*std/time/duration/duration*/
    }
    kk_string_t _x_x682;
    kk_define_string_literal(, _s_x683, 3, "TAI", _ctx)
    _x_x682 = kk_string_dup(_s_x683, _ctx); /*string*/
    kk_string_t _x_x684;
    kk_define_string_literal(, _s_x685, 3, "TAI", _ctx)
    _x_x684 = kk_string_dup(_s_x685, _ctx); /*string*/
    kk_std_core_types__maybe _x_x694;
    kk_std_core_types__optional _match_x394 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x394, _ctx)) {
      kk_box_t _box_x43 = _match_x394._cons._Optional.value;
      kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x43, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
      kk_std_core_types__optional_drop(_match_x394, _ctx);
      _x_x694 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x394, _ctx);
      _x_x694 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    kk_std_core_types__maybe _x_x695;
    kk_std_core_types__optional _match_x393 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x393, _ctx)) {
      kk_box_t _box_x44 = _match_x393._cons._Optional.value;
      kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x44, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
      kk_std_core_types__optional_drop(_match_x393, _ctx);
      _x_x695 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x393, _ctx);
      _x_x695 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    kk_std_core_types__maybe _x_x696;
    kk_std_core_types__optional _match_x392 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x392, _ctx)) {
      kk_box_t _box_x45 = _match_x392._cons._Optional.value;
      kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x45, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
      kk_std_core_types__optional_drop(_match_x392, _ctx);
      _x_x696 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x392, _ctx);
      _x_x696 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    kk_std_time_instant_ts_tai = kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x682, _x_x684, kk_std_time_instant_new_ts_tai_fun686(_uniq_offset_847, _ctx), kk_std_time_instant_new_ts_tai_fun691(_uniq_offset_847, _ctx), _x_x694, _x_x695, _x_x696, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_timestamp__timestamp t_10139;
    kk_std_num_ddouble__ddouble _x_x1376;
    kk_std_time_duration__duration _x_x1377 = kk_std_time_duration_duration0; /*std/time/duration/duration*/
    {
      kk_std_num_ddouble__ddouble _x = _x_x1377.secs;
      _x_x1376 = _x; /*std/time/timestamp/timespan*/
    }
    int32_t _x_x1378;
    kk_integer_t _x_x1379;
    kk_std_core_types__optional _match_x320 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x320, _ctx)) {
      kk_box_t _box_x103 = _match_x320._cons._Optional.value;
      kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x103, _ctx);
      kk_integer_dup(_uniq_leap_1214, _ctx);
      kk_std_core_types__optional_drop(_match_x320, _ctx);
      _x_x1379 = _uniq_leap_1214; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x320, _ctx);
      _x_x1379 = kk_integer_from_small(0); /*int*/
    }
    _x_x1378 = kk_integer_clamp32(_x_x1379,kk_context()); /*int32*/
    t_10139 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x1376, _x_x1378, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x1380 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
    kk_std_time_instant_epoch = kk_std_time_instant__new_Instant(t_10139, _x_x1380, _ctx); /*std/time/instant/instant*/
  }
  {
    kk_std_core_types__optional frac_0_10006;
    kk_box_t _x_x1381;
    double _x_x1382;
    kk_std_core_types__optional _match_x319 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x319, _ctx)) {
      kk_box_t _box_x104 = _match_x319._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x104, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x319, _ctx);
      _x_x1382 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x319, _ctx);
      _x_x1382 = 0x0p+0; /*float64*/
    }
    _x_x1381 = kk_double_box(_x_x1382, _ctx); /*10003*/
    frac_0_10006 = kk_std_core_types__new_Optional(_x_x1381, _ctx); /*? float64*/
    kk_std_time_duration__duration _b_x109_110;
    kk_std_num_ddouble__ddouble _x_x1383;
    bool _match_x318;
    double _x_x1384;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x107 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144_1 = kk_double_unbox(_box_x107, KK_BORROWED, _ctx);
      _x_x1384 = _uniq_frac_1144_1; /*float64*/
    }
    else {
      _x_x1384 = 0x0p+0; /*float64*/
    }
    _match_x318 = (_x_x1384 == (0x0p+0)); /*bool*/
    if (_match_x318) {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1383 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(-19), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1385 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(-19), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1386;
      double _x_x1387;
      if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
        kk_box_t _box_x108 = frac_0_10006._cons._Optional.value;
        double _uniq_frac_1144_0_0 = kk_double_unbox(_box_x108, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1387 = _uniq_frac_1144_0_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1387 = 0x0p+0; /*float64*/
      }
      _x_x1386 = kk_std_num_ddouble__new_Ddouble(_x_x1387, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1383 = kk_std_num_ddouble__lp__plus__rp_(_x_x1385, _x_x1386, _ctx); /*std/num/ddouble/ddouble*/
    }
    _b_x109_110 = kk_std_time_duration__new_Duration(_x_x1383, _ctx); /*std/time/duration/duration*/
    kk_std_time_duration__duration _uniq_offset_847;
    kk_std_core_types__optional _match_x315 = kk_std_core_types__new_Optional(kk_std_time_duration__duration_box(_b_x109_110, _ctx), _ctx); /*? 10003*/;
    if (kk_std_core_types__is_Optional(_match_x315, _ctx)) {
      kk_box_t _box_x111 = _match_x315._cons._Optional.value;
      kk_std_time_duration__duration _uniq_offset_848 = kk_std_time_duration__duration_unbox(_box_x111, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x315, _ctx);
      _uniq_offset_847 = _uniq_offset_848; /*std/time/duration/duration*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x315, _ctx);
      kk_std_core_types__optional frac_0_10006_0;
      kk_box_t _x_x1388;
      double _x_x1389;
      kk_std_core_types__optional _match_x317 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x317, _ctx)) {
        kk_box_t _box_x112 = _match_x317._cons._Optional.value;
        double _uniq_frac_155_0 = kk_double_unbox(_box_x112, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x317, _ctx);
        _x_x1389 = _uniq_frac_155_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x317, _ctx);
        _x_x1389 = 0x0p+0; /*float64*/
      }
      _x_x1388 = kk_double_box(_x_x1389, _ctx); /*10003*/
      frac_0_10006_0 = kk_std_core_types__new_Optional(_x_x1388, _ctx); /*? float64*/
      kk_std_num_ddouble__ddouble _x_x1390;
      bool _match_x316;
      double _x_x1391;
      if (kk_std_core_types__is_Optional(frac_0_10006_0, _ctx)) {
        kk_box_t _box_x115 = frac_0_10006_0._cons._Optional.value;
        double _uniq_frac_1144 = kk_double_unbox(_box_x115, KK_BORROWED, _ctx);
        _x_x1391 = _uniq_frac_1144; /*float64*/
      }
      else {
        _x_x1391 = 0x0p+0; /*float64*/
      }
      _match_x316 = (_x_x1391 == (0x0p+0)); /*bool*/
      if (_match_x316) {
        kk_std_core_types__optional_drop(frac_0_10006_0, _ctx);
        _x_x1390 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      }
      else {
        kk_std_num_ddouble__ddouble _x_x1392 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
        kk_std_num_ddouble__ddouble _x_x1393;
        double _x_x1394;
        if (kk_std_core_types__is_Optional(frac_0_10006_0, _ctx)) {
          kk_box_t _box_x116 = frac_0_10006_0._cons._Optional.value;
          double _uniq_frac_1144_0 = kk_double_unbox(_box_x116, KK_BORROWED, _ctx);
          kk_std_core_types__optional_drop(frac_0_10006_0, _ctx);
          _x_x1394 = _uniq_frac_1144_0; /*float64*/
        }
        else {
          kk_std_core_types__optional_drop(frac_0_10006_0, _ctx);
          _x_x1394 = 0x0p+0; /*float64*/
        }
        _x_x1393 = kk_std_num_ddouble__new_Ddouble(_x_x1394, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
        _x_x1390 = kk_std_num_ddouble__lp__plus__rp_(_x_x1392, _x_x1393, _ctx); /*std/num/ddouble/ddouble*/
      }
      _uniq_offset_847 = kk_std_time_duration__new_Duration(_x_x1390, _ctx); /*std/time/duration/duration*/
    }
    kk_string_t _x_x1395;
    kk_define_string_literal(, _s_x1396, 3, "GPS", _ctx)
    _x_x1395 = kk_string_dup(_s_x1396, _ctx); /*string*/
    kk_string_t _x_x1397;
    kk_define_string_literal(, _s_x1398, 3, "TAI", _ctx)
    _x_x1397 = kk_string_dup(_s_x1398, _ctx); /*string*/
    kk_std_core_types__maybe _x_x1407;
    kk_std_core_types__optional _match_x313 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x313, _ctx)) {
      kk_box_t _box_x118 = _match_x313._cons._Optional.value;
      kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x118, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
      kk_std_core_types__optional_drop(_match_x313, _ctx);
      _x_x1407 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x313, _ctx);
      _x_x1407 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    kk_std_core_types__maybe _x_x1408;
    kk_std_core_types__optional _match_x312 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x312, _ctx)) {
      kk_box_t _box_x119 = _match_x312._cons._Optional.value;
      kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x119, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
      kk_std_core_types__optional_drop(_match_x312, _ctx);
      _x_x1408 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x312, _ctx);
      _x_x1408 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    kk_std_core_types__maybe _x_x1409;
    kk_std_core_types__optional _match_x311 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x311, _ctx)) {
      kk_box_t _box_x120 = _match_x311._cons._Optional.value;
      kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x120, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
      kk_std_core_types__optional_drop(_match_x311, _ctx);
      _x_x1409 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x311, _ctx);
      _x_x1409 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    kk_std_time_instant_ts_gps = kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x1395, _x_x1397, kk_std_time_instant_new_ts_gps_fun1399(_uniq_offset_847, _ctx), kk_std_time_instant_new_ts_gps_fun1404(_uniq_offset_847, _ctx), _x_x1407, _x_x1408, _x_x1409, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_core_types__optional frac_0_10006;
    kk_box_t _x_x1410;
    double _x_x1411;
    kk_std_core_types__optional _match_x310 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x310, _ctx)) {
      kk_box_t _box_x121 = _match_x310._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x121, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x310, _ctx);
      _x_x1411 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x310, _ctx);
      _x_x1411 = 0x0p+0; /*float64*/
    }
    _x_x1410 = kk_double_box(_x_x1411, _ctx); /*10003*/
    frac_0_10006 = kk_std_core_types__new_Optional(_x_x1410, _ctx); /*? float64*/
    kk_std_num_ddouble__ddouble _x_x1412;
    bool _match_x309;
    double _x_x1413;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x124 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x124, KK_BORROWED, _ctx);
      _x_x1413 = _uniq_frac_1144; /*float64*/
    }
    else {
      _x_x1413 = 0x0p+0; /*float64*/
    }
    _match_x309 = (_x_x1413 == (0x0p+0)); /*bool*/
    if (_match_x309) {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1412 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(630720000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1414 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(630720000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1415;
      double _x_x1416;
      if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
        kk_box_t _box_x125 = frac_0_10006._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x125, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1416 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1416 = 0x0p+0; /*float64*/
      }
      _x_x1415 = kk_std_num_ddouble__new_Ddouble(_x_x1416, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1412 = kk_std_num_ddouble__lp__plus__rp_(_x_x1414, _x_x1415, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_time_instant_gps2000 = kk_std_time_duration__new_Duration(_x_x1412, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_time_duration__duration _uniq_offset_848;
    kk_std_num_ddouble__ddouble _x_x1461 = kk_std_num_ddouble__new_Ddouble(0x1.0178d4fdf3b64p5, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _uniq_offset_848 = kk_std_time_duration__new_Duration(_x_x1461, _ctx); /*std/time/duration/duration*/
    kk_string_t _x_x1462;
    kk_define_string_literal(, _s_x1463, 2, "TT", _ctx)
    _x_x1462 = kk_string_dup(_s_x1463, _ctx); /*string*/
    kk_string_t _x_x1464;
    kk_define_string_literal(, _s_x1465, 3, "TAI", _ctx)
    _x_x1464 = kk_string_dup(_s_x1465, _ctx); /*string*/
    kk_std_core_types__maybe _x_x1474;
    kk_std_core_types__optional _match_x301 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x301, _ctx)) {
      kk_box_t _box_x143 = _match_x301._cons._Optional.value;
      kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x143, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
      kk_std_core_types__optional_drop(_match_x301, _ctx);
      _x_x1474 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x301, _ctx);
      _x_x1474 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
    kk_std_core_types__maybe _x_x1475;
    kk_std_core_types__optional _match_x300 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x300, _ctx)) {
      kk_box_t _box_x144 = _match_x300._cons._Optional.value;
      kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x144, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
      kk_std_core_types__optional_drop(_match_x300, _ctx);
      _x_x1475 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x300, _ctx);
      _x_x1475 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
    kk_std_core_types__maybe _x_x1476;
    kk_std_core_types__optional _match_x299 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x299, _ctx)) {
      kk_box_t _box_x145 = _match_x299._cons._Optional.value;
      kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x145, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
      kk_std_core_types__optional_drop(_match_x299, _ctx);
      _x_x1476 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x299, _ctx);
      _x_x1476 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
    kk_std_time_instant_ts_tt = kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x1462, _x_x1464, kk_std_time_instant_new_ts_tt_fun1466(_uniq_offset_848, _ctx), kk_std_time_instant_new_ts_tt_fun1471(_uniq_offset_848, _ctx), _x_x1474, _x_x1475, _x_x1476, _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_core_types__optional frac_0_10006;
    kk_box_t _x_x1477;
    double _x_x1478;
    kk_std_core_types__optional _match_x298 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x298, _ctx)) {
      kk_box_t _box_x146 = _match_x298._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x146, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x298, _ctx);
      _x_x1478 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x298, _ctx);
      _x_x1478 = 0x0p+0; /*float64*/
    }
    _x_x1477 = kk_double_box(_x_x1478, _ctx); /*10003*/
    frac_0_10006 = kk_std_core_types__new_Optional(_x_x1477, _ctx); /*? float64*/
    kk_std_num_ddouble__ddouble _x_x1479;
    bool _match_x297;
    double _x_x1480;
    if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
      kk_box_t _box_x149 = frac_0_10006._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x149, KK_BORROWED, _ctx);
      _x_x1480 = _uniq_frac_1144; /*float64*/
    }
    else {
      _x_x1480 = 0x0p+0; /*float64*/
    }
    _match_x297 = (_x_x1480 == (0x0p+0)); /*bool*/
    if (_match_x297) {
      kk_std_core_types__optional_drop(frac_0_10006, _ctx);
      _x_x1479 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(630720000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1481 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(630720000, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1482;
      double _x_x1483;
      if (kk_std_core_types__is_Optional(frac_0_10006, _ctx)) {
        kk_box_t _box_x150 = frac_0_10006._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x150, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1483 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(frac_0_10006, _ctx);
        _x_x1483 = 0x0p+0; /*float64*/
      }
      _x_x1482 = kk_std_num_ddouble__new_Ddouble(_x_x1483, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      _x_x1479 = kk_std_num_ddouble__lp__plus__rp_(_x_x1481, _x_x1482, _ctx); /*std/num/ddouble/ddouble*/
    }
    kk_std_time_instant_tt2000 = kk_std_time_duration__new_Duration(_x_x1479, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_time_instant_jd_epoch_delta = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    bool _match_x293;
    double _x_x1504;
    kk_std_core_types__optional _match_x295 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x295, _ctx)) {
      kk_box_t _box_x161 = _match_x295._cons._Optional.value;
      double _uniq_frac_1144 = kk_double_unbox(_box_x161, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x295, _ctx);
      _x_x1504 = _uniq_frac_1144; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x295, _ctx);
      _x_x1504 = 0x0p+0; /*float64*/
    }
    _match_x293 = (_x_x1504 == (0x0p+0)); /*bool*/
    if (_match_x293) {
      kk_std_time_instant_mjd_epoch_delta = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(51544, _ctx), kk_integer_from_small(0), _ctx); /*std/time/timestamp/timespan*/
    }
    else {
      kk_std_num_ddouble__ddouble _x_x1505 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(51544, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_num_ddouble__ddouble _x_x1506;
      double _x_x1507;
      kk_std_core_types__optional _match_x294 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x294, _ctx)) {
        kk_box_t _box_x162 = _match_x294._cons._Optional.value;
        double _uniq_frac_1144_0 = kk_double_unbox(_box_x162, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(_match_x294, _ctx);
        _x_x1507 = _uniq_frac_1144_0; /*float64*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x294, _ctx);
        _x_x1507 = 0x0p+0; /*float64*/
      }
      _x_x1506 = kk_std_num_ddouble__new_Ddouble(_x_x1507, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
      kk_std_time_instant_mjd_epoch_delta = kk_std_num_ddouble__lp__plus__rp_(_x_x1505, _x_x1506, _ctx); /*std/time/timestamp/timespan*/
    }
  }
}

// termination
void kk_std_time_instant__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_num_ddouble__ddouble_drop(kk_std_time_instant_mjd_epoch_delta, _ctx);
  kk_std_num_ddouble__ddouble_drop(kk_std_time_instant_jd_epoch_delta, _ctx);
  kk_std_time_duration__duration_drop(kk_std_time_instant_tt2000, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_instant_ts_tt, _ctx);
  kk_std_time_duration__duration_drop(kk_std_time_instant_gps2000, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_instant_ts_gps, _ctx);
  kk_std_time_instant__instant_drop(kk_std_time_instant_epoch, _ctx);
  kk_std_time_instant__timescale_drop(kk_std_time_instant_ts_tai, _ctx);
  kk_std_num_int32__done(_ctx);
  kk_std_num_float64__done(_ctx);
  kk_std_time_date__done(_ctx);
  kk_std_time_duration__done(_ctx);
  kk_std_time_timestamp__done(_ctx);
  kk_std_num_ddouble__done(_ctx);
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
