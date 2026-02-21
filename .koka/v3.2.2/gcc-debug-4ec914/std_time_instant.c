// Koka generated module: std/time/instant, koka version: 3.2.2, platform: 64-bit
#include "std_time_instant.h"


// lift anonymous function
struct kk_std_time_instant_timescale_fs__copy_fun291__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x8;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_timescale_fs__copy_fun291(kk_function_t _fself, kk_std_time_duration__duration _b_x11, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_timescale_fs__new_copy_fun291(kk_box_t _fun_unbox_x8, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun291__t* _self = kk_function_alloc_as(struct kk_std_time_instant_timescale_fs__copy_fun291__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_timescale_fs__copy_fun291, kk_context());
  _self->_fun_unbox_x8 = _fun_unbox_x8;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_timescale_fs__copy_fun291(kk_function_t _fself, kk_std_time_duration__duration _b_x11, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun291__t* _self = kk_function_as(struct kk_std_time_instant_timescale_fs__copy_fun291__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x8 = _self->_fun_unbox_x8; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x8, _ctx);}, {}, _ctx)
  kk_box_t _x_x292;
  kk_function_t _x_x293 = kk_function_unbox(_fun_unbox_x8, _ctx); /*(9) -> 10*/
  _x_x292 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x293, (_x_x293, kk_std_time_duration__duration_box(_b_x11, _ctx), _ctx), _ctx); /*10*/
  return kk_std_time_timestamp__timestamp_unbox(_x_x292, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_timescale_fs__copy_fun296__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x15;
};
static kk_std_time_duration__duration kk_std_time_instant_timescale_fs__copy_fun296(kk_function_t _fself, kk_std_time_timestamp__timestamp _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_timescale_fs__new_copy_fun296(kk_box_t _fun_unbox_x15, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun296__t* _self = kk_function_alloc_as(struct kk_std_time_instant_timescale_fs__copy_fun296__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_timescale_fs__copy_fun296, kk_context());
  _self->_fun_unbox_x15 = _fun_unbox_x15;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_timescale_fs__copy_fun296(kk_function_t _fself, kk_std_time_timestamp__timestamp _b_x18, kk_context_t* _ctx) {
  struct kk_std_time_instant_timescale_fs__copy_fun296__t* _self = kk_function_as(struct kk_std_time_instant_timescale_fs__copy_fun296__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x15 = _self->_fun_unbox_x15; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x15, _ctx);}, {}, _ctx)
  kk_box_t _x_x297;
  kk_function_t _x_x298 = kk_function_unbox(_fun_unbox_x15, _ctx); /*(16) -> 17*/
  _x_x297 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x298, (_x_x298, kk_std_time_timestamp__timestamp_box(_b_x18, _ctx), _ctx), _ctx); /*17*/
  return kk_std_time_duration__duration_unbox(_x_x297, KK_OWNED, _ctx);
}

kk_std_time_instant__timescale kk_std_time_instant_timescale_fs__copy(kk_std_time_instant__timescale _this, kk_std_core_types__optional name, kk_std_core_types__optional unit, kk_std_core_types__optional from_tai_0, kk_std_core_types__optional to_tai_0, kk_std_core_types__optional mb_seconds_in_day, kk_std_core_types__optional mb_to_mjd2000, kk_std_core_types__optional mb_from_mjd2000, kk_context_t* _ctx) { /* (timescale, name : ? string, unit : ? string, from-tai : ? ((std/time/duration/duration) -> std/time/timestamp/timestamp), to-tai : ? ((std/time/timestamp/timestamp) -> std/time/duration/duration), mb-seconds-in-day : ? (maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), mb-to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), mb-from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
  kk_string_t _x_x286;
  if (kk_std_core_types__is_Optional(name, _ctx)) {
    kk_box_t _box_x3 = name._cons._Optional.value;
    kk_string_t _uniq_name_227 = kk_string_unbox(_box_x3);
    kk_string_dup(_uniq_name_227, _ctx);
    kk_std_core_types__optional_drop(name, _ctx);
    _x_x286 = _uniq_name_227; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(name, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x287 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_string_t _x = _con_x287->name;
      kk_string_dup(_x, _ctx);
      _x_x286 = _x; /*string*/
    }
  }
  kk_string_t _x_x288;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x4 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_235 = kk_string_unbox(_box_x4);
    kk_string_dup(_uniq_unit_235, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x288 = _uniq_unit_235; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x289 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_string_t _x_0 = _con_x289->unit;
      kk_string_dup(_x_0, _ctx);
      _x_x288 = _x_0; /*string*/
    }
  }
  kk_function_t _x_x290;
  if (kk_std_core_types__is_Optional(from_tai_0, _ctx)) {
    kk_box_t _fun_unbox_x8 = from_tai_0._cons._Optional.value;
    kk_box_dup(_fun_unbox_x8, _ctx);
    kk_std_core_types__optional_drop(from_tai_0, _ctx);
    _x_x290 = kk_std_time_instant_timescale_fs__new_copy_fun291(_fun_unbox_x8, _ctx); /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(from_tai_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x294 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_function_t _x_1 = _con_x294->from_tai;
      kk_function_dup(_x_1, _ctx);
      _x_x290 = _x_1; /*(std/time/duration/duration) -> std/time/timestamp/timestamp*/
    }
  }
  kk_function_t _x_x295;
  if (kk_std_core_types__is_Optional(to_tai_0, _ctx)) {
    kk_box_t _fun_unbox_x15 = to_tai_0._cons._Optional.value;
    kk_box_dup(_fun_unbox_x15, _ctx);
    kk_std_core_types__optional_drop(to_tai_0, _ctx);
    _x_x295 = kk_std_time_instant_timescale_fs__new_copy_fun296(_fun_unbox_x15, _ctx); /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
  }
  else {
    kk_std_core_types__optional_drop(to_tai_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x299 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_function_t _x_2 = _con_x299->to_tai;
      kk_function_dup(_x_2, _ctx);
      _x_x295 = _x_2; /*(std/time/timestamp/timestamp) -> std/time/duration/duration*/
    }
  }
  kk_std_core_types__maybe _x_x300;
  if (kk_std_core_types__is_Optional(mb_seconds_in_day, _ctx)) {
    kk_box_t _box_x19 = mb_seconds_in_day._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_seconds_in_day_265 = kk_std_core_types__maybe_unbox(_box_x19, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_seconds_in_day_265, _ctx);
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    _x_x300 = _uniq_mb_seconds_in_day_265; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_seconds_in_day, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x301 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_std_core_types__maybe _x_3 = _con_x301->mb_seconds_in_day;
      kk_std_core_types__maybe_dup(_x_3, _ctx);
      _x_x300 = _x_3; /*maybe<(t : std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
    }
  }
  kk_std_core_types__maybe _x_x302;
  if (kk_std_core_types__is_Optional(mb_to_mjd2000, _ctx)) {
    kk_box_t _box_x20 = mb_to_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_to_mjd2000_273 = kk_std_core_types__maybe_unbox(_box_x20, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_to_mjd2000_273, _ctx);
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    _x_x302 = _uniq_mb_to_mjd2000_273; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_to_mjd2000, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x303 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_std_core_types__maybe _x_4 = _con_x303->mb_to_mjd2000;
      kk_std_core_types__maybe_dup(_x_4, _ctx);
      _x_x302 = _x_4; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
    }
  }
  kk_std_core_types__maybe _x_x304;
  if (kk_std_core_types__is_Optional(mb_from_mjd2000, _ctx)) {
    kk_box_t _box_x21 = mb_from_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_mb_from_mjd2000_281 = kk_std_core_types__maybe_unbox(_box_x21, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_mb_from_mjd2000_281, _ctx);
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(10)), _ctx);
    _x_x304 = _uniq_mb_from_mjd2000_281; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(mb_from_mjd2000, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x305 = kk_std_time_instant__as_Timescale(_this, _ctx);
      kk_string_t _pat_0_6 = _con_x305->name;
      kk_string_t _pat_1_7 = _con_x305->unit;
      kk_function_t _pat_2_6 = _con_x305->from_tai;
      kk_function_t _pat_3_6 = _con_x305->to_tai;
      kk_std_core_types__maybe _pat_4_6 = _con_x305->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_5_6 = _con_x305->mb_to_mjd2000;
      kk_std_core_types__maybe _x_5 = _con_x305->mb_from_mjd2000;
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
      _x_x304 = _x_5; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
    }
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x286, _x_x288, _x_x290, _x_x295, _x_x300, _x_x302, _x_x304, _ctx);
}
 
// Create a new time scale given `name`, two inverse function `from-tai` and `to-tai`,
// and an optional function that returns the seconds in the day of the instant.
// The time unit defaults to `name`.

kk_std_time_instant__timescale kk_std_time_instant_timescale(kk_string_t name, kk_function_t from_tai_0, kk_function_t to_tai_0, kk_std_core_types__optional unit, kk_std_core_types__optional seconds_in_day_0, kk_std_core_types__optional to_mjd2000, kk_std_core_types__optional from_mjd2000, kk_context_t* _ctx) { /* (name : string, from-tai : (std/time/duration/duration) -> std/time/timestamp/timestamp, to-tai : (std/time/timestamp/timestamp) -> std/time/duration/duration, unit : ? string, seconds-in-day : ? (maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>), to-mjd2000 : ? (maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>), from-mjd2000 : ? (maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>)) -> timescale */ 
  kk_string_t _x_x314 = kk_string_dup(name, _ctx); /*string*/
  kk_string_t _x_x315;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x22 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_356 = kk_string_unbox(_box_x22);
    kk_string_dup(_uniq_unit_356, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    kk_string_drop(name, _ctx);
    _x_x315 = _uniq_unit_356; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x315 = name; /*string*/
  }
  kk_std_core_types__maybe _x_x316;
  if (kk_std_core_types__is_Optional(seconds_in_day_0, _ctx)) {
    kk_box_t _box_x23 = seconds_in_day_0._cons._Optional.value;
    kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x23, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
    kk_std_core_types__optional_drop(seconds_in_day_0, _ctx);
    _x_x316 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(seconds_in_day_0, _ctx);
    _x_x316 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x317;
  if (kk_std_core_types__is_Optional(to_mjd2000, _ctx)) {
    kk_box_t _box_x24 = to_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x24, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
    kk_std_core_types__optional_drop(to_mjd2000, _ctx);
    _x_x317 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(to_mjd2000, _ctx);
    _x_x317 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x318;
  if (kk_std_core_types__is_Optional(from_mjd2000, _ctx)) {
    kk_box_t _box_x25 = from_mjd2000._cons._Optional.value;
    kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x25, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
    kk_std_core_types__optional_drop(from_mjd2000, _ctx);
    _x_x318 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(from_mjd2000, _ctx);
    _x_x318 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, _x_x314, _x_x315, from_tai_0, to_tai_0, _x_x316, _x_x317, _x_x318, _ctx);
}
 
// Create a new time scale based on SI seconds (as measured on the Earth's geoid) with a given
//  `name`, a fixed `offset` (=`duration0`) from TAI (e.g. GPS = TAI - 19), and
// a `epoch-y2k` (= `timestamp0`) which is the timestamp of the 2000-01-01 date in that timescale
// e.g. for a timescale `ts`:
// `epoch-y2k = instant(2000,1,1,cal=iso-calendar(ts)).since-in(ts)`


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun325__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun325(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun325(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun325__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun325__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_tai_timescale_fun325, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_timestamp__timestamp kk_std_time_instant_tai_timescale_fun325(kk_function_t _fself, kk_std_time_duration__duration tai, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun325__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun325__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_num_ddouble__ddouble t_10019;
  kk_std_num_ddouble__ddouble _x_x326;
  {
    kk_std_num_ddouble__ddouble _x_0 = tai.secs;
    _x_x326 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x327;
  {
    kk_std_num_ddouble__ddouble _x = _uniq_offset_847.secs;
    _x_x327 = _x; /*std/time/timestamp/timespan*/
  }
  t_10019 = kk_std_num_ddouble__lp__plus__rp_(_x_x326, _x_x327, _ctx); /*std/time/timestamp/timespan*/
  int32_t _x_x328;
  kk_integer_t _x_x329;
  kk_std_core_types__optional _match_x195 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x195, _ctx)) {
    kk_box_t _box_x30 = _match_x195._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x30, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x195, _ctx);
    _x_x329 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x195, _ctx);
    _x_x329 = kk_integer_from_small(0); /*int*/
  }
  _x_x328 = kk_integer_clamp32(_x_x329,kk_context()); /*int32*/
  return kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, t_10019, _x_x328, _ctx);
}


// lift anonymous function
struct kk_std_time_instant_tai_timescale_fun330__t {
  struct kk_function_s _base;
  kk_std_time_duration__duration _uniq_offset_847;
};
static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun330(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx);
static kk_function_t kk_std_time_instant_new_tai_timescale_fun330(kk_std_time_duration__duration _uniq_offset_847, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun330__t* _self = kk_function_alloc_as(struct kk_std_time_instant_tai_timescale_fun330__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_time_instant_tai_timescale_fun330, kk_context());
  _self->_uniq_offset_847 = _uniq_offset_847;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_time_duration__duration kk_std_time_instant_tai_timescale_fun330(kk_function_t _fself, kk_std_time_timestamp__timestamp t_0, kk_context_t* _ctx) {
  struct kk_std_time_instant_tai_timescale_fun330__t* _self = kk_function_as(struct kk_std_time_instant_tai_timescale_fun330__t*, _fself, _ctx);
  kk_std_time_duration__duration _uniq_offset_847 = _self->_uniq_offset_847; /* std/time/duration/duration */
  kk_drop_match(_self, {kk_std_time_duration__duration_dup(_uniq_offset_847, _ctx);}, {}, _ctx)
  kk_std_time_timestamp__timestamp t_1_10022;
  kk_std_num_ddouble__ddouble _x_x331;
  {
    kk_std_num_ddouble__ddouble _x_1 = _uniq_offset_847.secs;
    _x_x331 = _x_1; /*std/time/timestamp/timespan*/
  }
  t_1_10022 = kk_std_time_timestamp__lp__dash__rp_(t_0, _x_x331, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x332 = kk_std_time_timestamp_unsafe_timespan_withleap(t_1_10022, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x332, _ctx);
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
    kk_std_num_ddouble__ddouble _x_x319;
    kk_std_core_types__optional _x_x320;
    kk_box_t _x_x321;
    double _x_x322;
    kk_std_core_types__optional _match_x196 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x196, _ctx)) {
      kk_box_t _box_x27 = _match_x196._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x27, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x196, _ctx);
      _x_x322 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x196, _ctx);
      _x_x322 = 0x0p+0; /*float64*/
    }
    _x_x321 = kk_double_box(_x_x322, _ctx); /*7*/
    _x_x320 = kk_std_core_types__new_Optional(_x_x321, _ctx); /*? 7*/
    _x_x319 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_small(0), _x_x320, _ctx); /*std/time/timestamp/timespan*/
    _uniq_offset_847 = kk_std_time_duration__new_Duration(_x_x319, _ctx); /*std/time/duration/duration*/
  }
  kk_string_t _x_x323;
  kk_define_string_literal(, _s_x324, 3, "TAI", _ctx)
  _x_x323 = kk_string_dup(_s_x324, _ctx); /*string*/
  kk_std_core_types__maybe _x_x333;
  kk_std_core_types__optional _match_x194 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x194, _ctx)) {
    kk_box_t _box_x31 = _match_x194._cons._Optional.value;
    kk_std_core_types__maybe _uniq_seconds_in_day_362 = kk_std_core_types__maybe_unbox(_box_x31, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_seconds_in_day_362, _ctx);
    kk_std_core_types__optional_drop(_match_x194, _ctx);
    _x_x333 = _uniq_seconds_in_day_362; /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x194, _ctx);
    _x_x333 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(std/time/timestamp/timestamp) -> std/time/timestamp/timespan>*/
  }
  kk_std_core_types__maybe _x_x334;
  kk_std_core_types__optional _match_x193 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x193, _ctx)) {
    kk_box_t _box_x32 = _match_x193._cons._Optional.value;
    kk_std_core_types__maybe _uniq_to_mjd2000_368 = kk_std_core_types__maybe_unbox(_box_x32, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_to_mjd2000_368, _ctx);
    kk_std_core_types__optional_drop(_match_x193, _ctx);
    _x_x334 = _uniq_to_mjd2000_368; /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x193, _ctx);
    _x_x334 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(t : std/time/timestamp/timestamp, tzdelta : std/time/timestamp/timespan) -> std/num/ddouble/ddouble>*/
  }
  kk_std_core_types__maybe _x_x335;
  kk_std_core_types__optional _match_x192 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x192, _ctx)) {
    kk_box_t _box_x33 = _match_x192._cons._Optional.value;
    kk_std_core_types__maybe _uniq_from_mjd2000_374 = kk_std_core_types__maybe_unbox(_box_x33, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_dup(_uniq_from_mjd2000_374, _ctx);
    kk_std_core_types__optional_drop(_match_x192, _ctx);
    _x_x335 = _uniq_from_mjd2000_374; /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x192, _ctx);
    _x_x335 = kk_std_core_types__new_Nothing(_ctx); /*maybe<(days : int, frac : std/num/ddouble/ddouble) -> std/time/timestamp/timestamp>*/
  }
  return kk_std_time_instant__new_Timescale(kk_reuse_null, 0, name, _x_x323, kk_std_time_instant_new_tai_timescale_fun325(_uniq_offset_847, _ctx), kk_std_time_instant_new_tai_timescale_fun330(_uniq_offset_847, _ctx), _x_x333, _x_x334, _x_x335, _ctx);
}
 
// The [TAI](https://en.wikipedia.org/wiki/International_Atomic_Time) (International atomic time)
// time scale is based on SI seconds measured on the Earth's geoid, with a 2000-01-01 TAI `epoch`.

kk_std_time_instant__timescale kk_std_time_instant_ts_tai;
 
// Add a time span to an instant in time.
// This is only safe if the time unit of the timespan is the
// same as that of the instant.

kk_std_time_instant__instant kk_std_time_instant_unsafe_add(kk_std_time_instant__instant i, kk_std_num_ddouble__ddouble tspan, kk_context_t* _ctx) { /* (i : instant, tspan : std/time/timestamp/timespan) -> instant */ 
  kk_std_time_timestamp__timestamp _x_x338;
  kk_std_num_ddouble__ddouble _x_x339;
  kk_std_num_ddouble__ddouble _x_x340;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_1 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x341 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x342 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x343 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
      kk_std_num_ddouble__ddouble _x = _con_x343->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x340 = _x; /*std/time/timestamp/timespan*/
    }
  }
  _x_x339 = kk_std_num_ddouble__lp__plus__rp_(_x_x340, tspan, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x344;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i.since;
    kk_std_time_instant__timescale _pat_2_1_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x345 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x346 = kk_std_time_instant__as_Timescale(_pat_2_1_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x347 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0 = _con_x347->since;
      int32_t _x_0 = _con_x347->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x344 = _x_0; /*int32*/
    }
  }
  _x_x338 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x339, _x_x344, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x348;
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x349 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x350 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
    kk_std_time_instant__timescale_dup(_x_2, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x348 = _x_2; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant__new_Instant(_x_x338, _x_x348, _ctx);
}
 
// Convert a timespan between time scales

kk_std_time_timestamp__timestamp kk_std_time_instant_convert(kk_std_time_timestamp__timestamp t, kk_std_time_instant__timescale from, kk_std_time_instant__timescale to, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, from : timescale, to : timescale) -> std/time/timestamp/timestamp */ 
  bool _match_x189;
  kk_string_t _x_x351;
  {
    struct kk_std_time_instant_Timescale* _con_x352 = kk_std_time_instant__as_Timescale(from, _ctx);
    kk_string_t _x = _con_x352->name;
    kk_string_dup(_x, _ctx);
    _x_x351 = _x; /*string*/
  }
  kk_string_t _x_x353;
  {
    struct kk_std_time_instant_Timescale* _con_x354 = kk_std_time_instant__as_Timescale(to, _ctx);
    kk_string_t _x_0 = _con_x354->name;
    kk_string_dup(_x_0, _ctx);
    _x_x353 = _x_0; /*string*/
  }
  _match_x189 = kk_string_is_eq(_x_x351,_x_x353,kk_context()); /*bool*/
  if (_match_x189) {
    kk_datatype_ptr_dropn(to, (KK_I32(10)), _ctx);
    kk_datatype_ptr_dropn(from, (KK_I32(10)), _ctx);
    return t;
  }
  {
    bool _match_x190;
    kk_string_t _x_x355;
    {
      struct kk_std_time_instant_Timescale* _con_x356 = kk_std_time_instant__as_Timescale(from, _ctx);
      kk_string_t _x_1 = _con_x356->unit;
      kk_string_dup(_x_1, _ctx);
      _x_x355 = _x_1; /*string*/
    }
    kk_string_t _x_x357;
    {
      struct kk_std_time_instant_Timescale* _con_x358 = kk_std_time_instant__as_Timescale(to, _ctx);
      kk_string_t _x_2 = _con_x358->unit;
      kk_string_dup(_x_2, _ctx);
      _x_x357 = _x_2; /*string*/
    }
    _match_x190 = kk_string_is_eq(_x_x355,_x_x357,kk_context()); /*bool*/
    if (_match_x190) {
      bool _match_x191;
      kk_string_t _x_x359;
      {
        struct kk_std_time_instant_Timescale* _con_x360 = kk_std_time_instant__as_Timescale(from, _ctx);
        kk_string_t _x_3 = _con_x360->unit;
        kk_string_dup(_x_3, _ctx);
        _x_x359 = _x_3; /*string*/
      }
      kk_string_t _x_x361;
      kk_define_string_literal(, _s_x362, 3, "UTC", _ctx)
      _x_x361 = kk_string_dup(_s_x362, _ctx); /*string*/
      _match_x191 = kk_string_is_eq(_x_x359,_x_x361,kk_context()); /*bool*/
      if (_match_x191) {
        kk_datatype_ptr_dropn(to, (KK_I32(10)), _ctx);
        kk_datatype_ptr_dropn(from, (KK_I32(10)), _ctx);
        return t;
      }
      {
        kk_std_time_duration__duration _norm_x10197;
        {
          struct kk_std_time_instant_Timescale* _con_x363 = kk_std_time_instant__as_Timescale(from, _ctx);
          kk_string_t _pat_0_6 = _con_x363->name;
          kk_string_t _pat_1_6 = _con_x363->unit;
          kk_function_t _pat_2_5 = _con_x363->from_tai;
          kk_function_t _x_5 = _con_x363->to_tai;
          kk_std_core_types__maybe _pat_3_6 = _con_x363->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_6 = _con_x363->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_5 = _con_x363->mb_from_mjd2000;
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
          _norm_x10197 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_5, (_x_5, t, _ctx), _ctx); /*std/time/duration/duration*/
        }
        {
          struct kk_std_time_instant_Timescale* _con_x364 = kk_std_time_instant__as_Timescale(to, _ctx);
          kk_string_t _pat_0_5 = _con_x364->name;
          kk_string_t _pat_1_5 = _con_x364->unit;
          kk_function_t _x_4 = _con_x364->from_tai;
          kk_function_t _pat_2_4 = _con_x364->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x364->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x364->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_4 = _con_x364->mb_from_mjd2000;
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
          return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_4, (_x_4, _norm_x10197, _ctx), _ctx);
        }
      }
    }
    {
      kk_std_time_duration__duration _norm_x10198;
      {
        struct kk_std_time_instant_Timescale* _con_x365 = kk_std_time_instant__as_Timescale(from, _ctx);
        kk_string_t _pat_0_8 = _con_x365->name;
        kk_string_t _pat_1_8 = _con_x365->unit;
        kk_function_t _pat_2_8 = _con_x365->from_tai;
        kk_function_t _x_7 = _con_x365->to_tai;
        kk_std_core_types__maybe _pat_3_8 = _con_x365->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_8 = _con_x365->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_7 = _con_x365->mb_from_mjd2000;
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
        _norm_x10198 = kk_function_call(kk_std_time_duration__duration, (kk_function_t, kk_std_time_timestamp__timestamp, kk_context_t*), _x_7, (_x_7, t, _ctx), _ctx); /*std/time/duration/duration*/
      }
      {
        struct kk_std_time_instant_Timescale* _con_x366 = kk_std_time_instant__as_Timescale(to, _ctx);
        kk_string_t _pat_0_7 = _con_x366->name;
        kk_string_t _pat_1_7 = _con_x366->unit;
        kk_function_t _x_6 = _con_x366->from_tai;
        kk_function_t _pat_2_7 = _con_x366->to_tai;
        kk_std_core_types__maybe _pat_3_7 = _con_x366->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_7 = _con_x366->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_6 = _con_x366->mb_from_mjd2000;
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
        return kk_function_call(kk_std_time_timestamp__timestamp, (kk_function_t, kk_std_time_duration__duration, kk_context_t*), _x_6, (_x_6, _norm_x10198, _ctx), _ctx);
      }
    }
  }
}
 
// Change the internal representation of an instant to use another timescale.
// Only used in special cases for efficiency. For example, when comparing an
// instant in TAI time to thousands of UTC times, it is more efficient to convert
// the TAI time to UTC first to avoid converting at each comparision.

kk_std_time_instant__instant kk_std_time_instant_use_timescale(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_context_t* _ctx) { /* (i : instant, tscale : timescale) -> instant */ 
  bool _match_x188;
  kk_string_t _x_x373;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x374 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x375 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x376 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x376->name;
      kk_string_t _pat_0 = _con_x376->unit;
      kk_function_t _pat_1 = _con_x376->from_tai;
      kk_function_t _pat_2 = _con_x376->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x376->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x376->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x376->mb_from_mjd2000;
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
      _x_x373 = _x; /*string*/
    }
  }
  kk_string_t _x_x377;
  {
    struct kk_std_time_instant_Timescale* _con_x378 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_1 = _con_x378->name;
    kk_string_dup(_x_1, _ctx);
    _x_x377 = _x_1; /*string*/
  }
  _match_x188 = kk_string_is_eq(_x_x373,_x_x377,kk_context()); /*bool*/
  if (_match_x188) {
    kk_datatype_ptr_dropn(tscale, (KK_I32(10)), _ctx);
    return i;
  }
  {
    kk_std_time_timestamp__timestamp _x_x379;
    kk_std_time_timestamp__timestamp _x_x380;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x381 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x382 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x380 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x383;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x384 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x385 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x383 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x386 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    _x_x379 = kk_std_time_instant_convert(_x_x380, _x_x383, _x_x386, _ctx); /*std/time/timestamp/timestamp*/
    return kk_std_time_instant__new_Instant(_x_x379, tscale, _ctx);
  }
}
 
// Add a duration to an instant in time.
// Note: this generally entails conversion to TAI time (`ts-tai`).
// See also `add-duration-in` and `add-days` to add
// in direct time scale units.

kk_std_time_instant__instant kk_std_time_instant__lp__plus__rp_(kk_std_time_instant__instant i, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (i : instant, d : std/time/duration/duration) -> instant */ 
  bool _match_x185;
  kk_string_t _x_x387;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x388 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x389 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x390 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x390->name;
      kk_string_t _x = _con_x390->unit;
      kk_function_t _pat_1 = _con_x390->from_tai;
      kk_function_t _pat_2 = _con_x390->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x390->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x390->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x390->mb_from_mjd2000;
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
      _x_x387 = _x; /*string*/
    }
  }
  kk_string_t _x_x391;
  kk_define_string_literal(, _s_x392, 3, "TAI", _ctx)
  _x_x391 = kk_string_dup(_s_x392, _ctx); /*string*/
  _match_x185 = kk_string_is_eq(_x_x387,_x_x391,kk_context()); /*bool*/
  if (_match_x185) {
    kk_std_time_timestamp__timestamp _x_x393;
    kk_std_num_ddouble__ddouble _x_x394;
    kk_std_num_ddouble__ddouble _x_x395;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x396 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x397 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x398 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
        kk_std_num_ddouble__ddouble _x_1 = _con_x398->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
          kk_datatype_ptr_free(_x_2, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_2, _ctx);
        }
        _x_x395 = _x_1; /*std/time/timestamp/timespan*/
      }
    }
    kk_std_num_ddouble__ddouble _x_x399;
    {
      kk_std_num_ddouble__ddouble _x_4 = d.secs;
      _x_x399 = _x_4; /*std/time/timestamp/timespan*/
    }
    _x_x394 = kk_std_num_ddouble__lp__plus__rp_(_x_x395, _x_x399, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x400;
    {
      kk_std_time_timestamp__timestamp _x_2_0 = i.since;
      kk_std_time_instant__timescale _pat_2_2_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x401 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x402 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x403 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x403->since;
        int32_t _x_0_0 = _con_x403->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_2_0, _ctx)) {
          kk_datatype_ptr_free(_x_2_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_2_0, _ctx);
        }
        _x_x400 = _x_0_0; /*int32*/
      }
    }
    _x_x393 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x394, _x_x400, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x404;
    {
      kk_std_time_timestamp__timestamp _pat_0_3 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x405 = kk_std_time_timestamp__as_Timestamp(_pat_0_3, _ctx);
      struct kk_std_time_instant_Timescale* _con_x406 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x404 = _x_3; /*std/time/instant/timescale*/
    }
    return kk_std_time_instant__new_Instant(_x_x393, _x_x404, _ctx);
  }
  {
    kk_std_time_instant__instant i_1_10054;
    bool _match_x187;
    kk_string_t _x_x407;
    {
      kk_std_time_timestamp__timestamp _pat_0_0_1 = i.since;
      kk_std_time_instant__timescale _x_0_1 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x408 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x409 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_1, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x410 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
        kk_string_t _x_5 = _con_x410->name;
        kk_string_t _pat_0_6 = _con_x410->unit;
        kk_function_t _pat_1_5 = _con_x410->from_tai;
        kk_function_t _pat_2_4 = _con_x410->to_tai;
        kk_std_core_types__maybe _pat_3_4 = _con_x410->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3 = _con_x410->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3 = _con_x410->mb_from_mjd2000;
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
        _x_x407 = _x_5; /*string*/
      }
    }
    kk_string_t _x_x411;
    kk_std_time_instant__timescale _x_x412 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
    {
      struct kk_std_time_instant_Timescale* _con_x413 = kk_std_time_instant__as_Timescale(_x_x412, _ctx);
      kk_string_t _x_1_0 = _con_x413->name;
      _x_x411 = kk_string_dup(_x_1_0, _ctx); /*string*/
    }
    _match_x187 = kk_string_is_eq(_x_x407,_x_x411,kk_context()); /*bool*/
    if (_match_x187) {
      i_1_10054 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
    }
    else {
      kk_std_time_timestamp__timestamp _x_x414;
      kk_std_time_timestamp__timestamp _x_x415;
      {
        kk_std_time_timestamp__timestamp _x_2_0_0 = i.since;
        kk_std_time_instant__timescale _pat_2_2_0_0 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x416 = kk_std_time_timestamp__as_Timestamp(_x_2_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x417 = kk_std_time_instant__as_Timescale(_pat_2_2_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_2_0_0, _ctx);
        _x_x415 = _x_2_0_0; /*std/time/timestamp/timestamp*/
      }
      kk_std_time_instant__timescale _x_x418;
      {
        kk_std_time_timestamp__timestamp _pat_0_4_0 = i.since;
        kk_std_time_instant__timescale _x_3_0 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x419 = kk_std_time_timestamp__as_Timestamp(_pat_0_4_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x420 = kk_std_time_instant__as_Timescale(_x_3_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_3_0, _ctx);
        _x_x418 = _x_3_0; /*std/time/instant/timescale*/
      }
      kk_std_time_instant__timescale _x_x421 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
      _x_x414 = kk_std_time_instant_convert(_x_x415, _x_x418, _x_x421, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x422 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
      i_1_10054 = kk_std_time_instant__new_Instant(_x_x414, _x_x422, _ctx); /*std/time/instant/instant*/
    }
    kk_std_time_instant__instant i_1_10208;
    kk_std_time_timestamp__timestamp _x_x423;
    kk_std_num_ddouble__ddouble _x_x424;
    kk_std_num_ddouble__ddouble _x_x425;
    {
      kk_std_time_timestamp__timestamp _x_6 = i_1_10054.since;
      kk_std_time_instant__timescale _pat_2_5 = i_1_10054.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x426 = kk_std_time_timestamp__as_Timestamp(_x_6, _ctx);
      struct kk_std_time_instant_Timescale* _con_x427 = kk_std_time_instant__as_Timescale(_pat_2_5, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_6, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x428 = kk_std_time_timestamp__as_Timestamp(_x_6, _ctx);
        kk_std_num_ddouble__ddouble _x_5_0 = _con_x428->since;
        if kk_likely(kk_datatype_ptr_is_unique(_x_6, _ctx)) {
          kk_datatype_ptr_free(_x_6, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_6, _ctx);
        }
        _x_x425 = _x_5_0; /*std/time/timestamp/timespan*/
      }
    }
    kk_std_num_ddouble__ddouble _x_x429;
    {
      kk_std_num_ddouble__ddouble _x_8 = d.secs;
      _x_x429 = _x_8; /*std/time/timestamp/timespan*/
    }
    _x_x424 = kk_std_num_ddouble__lp__plus__rp_(_x_x425, _x_x429, _ctx); /*std/num/ddouble/ddouble*/
    int32_t _x_x430;
    {
      kk_std_time_timestamp__timestamp _x_6_0 = i_1_10054.since;
      kk_std_time_instant__timescale _pat_2_5_0 = i_1_10054.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x431 = kk_std_time_timestamp__as_Timestamp(_x_6_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x432 = kk_std_time_instant__as_Timescale(_pat_2_5_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_6_0, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x433 = kk_std_time_timestamp__as_Timestamp(_x_6_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0_1_0 = _con_x433->since;
        int32_t _x_0_1_0 = _con_x433->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_6_0, _ctx)) {
          kk_datatype_ptr_free(_x_6_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_6_0, _ctx);
        }
        _x_x430 = _x_0_1_0; /*int32*/
      }
    }
    _x_x423 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x424, _x_x430, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x434;
    {
      kk_std_time_timestamp__timestamp _pat_0_8_0 = i_1_10054.since;
      kk_std_time_instant__timescale _x_7_0 = i_1_10054.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x435 = kk_std_time_timestamp__as_Timestamp(_pat_0_8_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x436 = kk_std_time_instant__as_Timescale(_x_7_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_7_0, _ctx);
      kk_std_time_instant__instant_drop(i_1_10054, _ctx);
      _x_x434 = _x_7_0; /*std/time/instant/timescale*/
    }
    i_1_10208 = kk_std_time_instant__new_Instant(_x_x423, _x_x434, _ctx); /*std/time/instant/instant*/
    bool _match_x186;
    kk_string_t _x_x437;
    {
      kk_std_time_timestamp__timestamp _pat_0_0_2 = i_1_10208.since;
      kk_std_time_instant__timescale _x_0_2 = i_1_10208.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x438 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x439 = kk_std_time_instant__as_Timescale(_x_0_2, _ctx);
      kk_std_time_instant__timescale_dup(_x_0_2, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x440 = kk_std_time_instant__as_Timescale(_x_0_2, _ctx);
        kk_string_t _x_7 = _con_x440->name;
        kk_string_t _pat_0_8 = _con_x440->unit;
        kk_function_t _pat_1_7 = _con_x440->from_tai;
        kk_function_t _pat_2_6 = _con_x440->to_tai;
        kk_std_core_types__maybe _pat_3_6 = _con_x440->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_4 = _con_x440->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_4 = _con_x440->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_2, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_4, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_6, _ctx);
          kk_function_drop(_pat_2_6, _ctx);
          kk_function_drop(_pat_1_7, _ctx);
          kk_string_drop(_pat_0_8, _ctx);
          kk_datatype_ptr_free(_x_0_2, _ctx);
        }
        else {
          kk_string_dup(_x_7, _ctx);
          kk_datatype_ptr_decref(_x_0_2, _ctx);
        }
        _x_x437 = _x_7; /*string*/
      }
    }
    kk_string_t _x_x441;
    {
      kk_std_time_timestamp__timestamp _pat_0_10 = i.since;
      kk_std_time_instant__timescale _x_9 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x442 = kk_std_time_timestamp__as_Timestamp(_pat_0_10, _ctx);
      struct kk_std_time_instant_Timescale* _con_x443 = kk_std_time_instant__as_Timescale(_x_9, _ctx);
      kk_std_time_instant__timescale_dup(_x_9, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x444 = kk_std_time_instant__as_Timescale(_x_9, _ctx);
        kk_string_t _x_1_1 = _con_x444->name;
        kk_string_t _pat_0_1_1 = _con_x444->unit;
        kk_function_t _pat_1_1_1 = _con_x444->from_tai;
        kk_function_t _pat_2_1_1 = _con_x444->to_tai;
        kk_std_core_types__maybe _pat_3_1_1 = _con_x444->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_1_1 = _con_x444->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_1_1 = _con_x444->mb_from_mjd2000;
        if kk_likely(kk_datatype_ptr_is_unique(_x_9, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_1_1, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_1_1, _ctx);
          kk_std_core_types__maybe_drop(_pat_3_1_1, _ctx);
          kk_function_drop(_pat_2_1_1, _ctx);
          kk_function_drop(_pat_1_1_1, _ctx);
          kk_string_drop(_pat_0_1_1, _ctx);
          kk_datatype_ptr_free(_x_9, _ctx);
        }
        else {
          kk_string_dup(_x_1_1, _ctx);
          kk_datatype_ptr_decref(_x_9, _ctx);
        }
        _x_x441 = _x_1_1; /*string*/
      }
    }
    _match_x186 = kk_string_is_eq(_x_x437,_x_x441,kk_context()); /*bool*/
    if (_match_x186) {
      kk_std_time_instant__instant_drop(i, _ctx);
      return i_1_10208;
    }
    {
      kk_std_time_timestamp__timestamp _x_x445;
      kk_std_time_timestamp__timestamp _x_x446;
      {
        kk_std_time_timestamp__timestamp _x_2_1 = i_1_10208.since;
        kk_std_time_instant__timescale _pat_2_2_1 = i_1_10208.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x447 = kk_std_time_timestamp__as_Timestamp(_x_2_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x448 = kk_std_time_instant__as_Timescale(_pat_2_2_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_2_1, _ctx);
        _x_x446 = _x_2_1; /*std/time/timestamp/timestamp*/
      }
      kk_std_time_instant__timescale _x_x449;
      {
        kk_std_time_timestamp__timestamp _pat_0_4_1 = i_1_10208.since;
        kk_std_time_instant__timescale _x_3_1 = i_1_10208.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x450 = kk_std_time_timestamp__as_Timestamp(_pat_0_4_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x451 = kk_std_time_instant__as_Timescale(_x_3_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_3_1, _ctx);
        kk_std_time_instant__instant_drop(i_1_10208, _ctx);
        _x_x449 = _x_3_1; /*std/time/instant/timescale*/
      }
      kk_std_time_instant__timescale _x_x452;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_0 = i.since;
        kk_std_time_instant__timescale _x_9_0 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x453 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x454 = kk_std_time_instant__as_Timescale(_x_9_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_0, _ctx);
        _x_x452 = _x_9_0; /*std/time/instant/timescale*/
      }
      _x_x445 = kk_std_time_instant_convert(_x_x446, _x_x449, _x_x452, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x455;
      {
        kk_std_time_timestamp__timestamp _pat_0_10_1 = i.since;
        kk_std_time_instant__timescale _x_9_1 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x456 = kk_std_time_timestamp__as_Timestamp(_pat_0_10_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x457 = kk_std_time_instant__as_Timescale(_x_9_1, _ctx);
        kk_std_time_instant__timescale_dup(_x_9_1, _ctx);
        kk_std_time_instant__instant_drop(i, _ctx);
        _x_x455 = _x_9_1; /*std/time/instant/timescale*/
      }
      return kk_std_time_instant__new_Instant(_x_x445, _x_x455, _ctx);
    }
  }
}
 
// Return the (TAI) SI second duration since the `epoch` at this instant.

kk_std_time_duration__duration kk_std_time_instant_instant_fs_duration(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10063;
  kk_std_time_timestamp__timestamp _x_x458;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x459 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x460 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x458 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x461;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x462 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x463 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x461 = _x_0; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x464 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_10063 = kk_std_time_instant_convert(_x_x458, _x_x461, _x_x464, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_num_ddouble__ddouble _x_x465 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10063, _ctx); /*std/time/timestamp/timespan*/
  return kk_std_time_duration__new_Duration(_x_x465, _ctx);
}
 
// Return the duration between to instants in time.

kk_std_time_duration__duration kk_std_time_instant__lp__dash__rp_(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10063;
  kk_std_time_timestamp__timestamp _x_x466;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x467 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x468 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x466 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x469;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x470 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x471 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x469 = _x_0; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x472 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_10063 = kk_std_time_instant_convert(_x_x466, _x_x469, _x_x472, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_timestamp__timestamp t_10063_0;
  kk_std_time_timestamp__timestamp _x_x473;
  {
    kk_std_time_timestamp__timestamp _x_1 = j.since;
    kk_std_time_instant__timescale _pat_2_1 = j.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x474 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x475 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    _x_x473 = _x_1; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x476;
  {
    kk_std_time_timestamp__timestamp _pat_0_0_0 = j.since;
    kk_std_time_instant__timescale _x_0_0 = j.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x477 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x478 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
    kk_std_time_instant__instant_drop(j, _ctx);
    _x_x476 = _x_0_0; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x479 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  t_10063_0 = kk_std_time_instant_convert(_x_x473, _x_x476, _x_x479, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration _x_x480;
  kk_std_num_ddouble__ddouble _x_x481 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10063, _ctx); /*std/time/timestamp/timespan*/
  _x_x480 = kk_std_time_duration__new_Duration(_x_x481, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration _x_x482;
  kk_std_num_ddouble__ddouble _x_x483 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10063_0, _ctx); /*std/time/timestamp/timespan*/
  _x_x482 = kk_std_time_duration__new_Duration(_x_x483, _ctx); /*std/time/duration/duration*/
  return kk_std_time_duration__lp__dash__rp_(_x_x480, _x_x482, _ctx);
}
 
// Compare two `:instant`s in time.

kk_std_core_types__order kk_std_time_instant_cmp(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> order */ 
  kk_std_time_instant__instant instant_0_10070;
  bool _match_x184;
  kk_string_t _x_x490;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = j.since;
    kk_std_time_instant__timescale _x_0 = j.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x491 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x492 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x493 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x493->name;
      kk_string_t _pat_0 = _con_x493->unit;
      kk_function_t _pat_1 = _con_x493->from_tai;
      kk_function_t _pat_2 = _con_x493->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x493->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x493->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x493->mb_from_mjd2000;
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
      _x_x490 = _x; /*string*/
    }
  }
  kk_string_t _x_x494;
  {
    kk_std_time_timestamp__timestamp _pat_0_1_0 = i.since;
    kk_std_time_instant__timescale _x_1_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x495 = kk_std_time_timestamp__as_Timestamp(_pat_0_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x496 = kk_std_time_instant__as_Timescale(_x_1_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x497 = kk_std_time_instant__as_Timescale(_x_1_0, _ctx);
      kk_string_t _x_1 = _con_x497->name;
      kk_string_t _pat_0_1 = _con_x497->unit;
      kk_function_t _pat_1_1 = _con_x497->from_tai;
      kk_function_t _pat_2_1 = _con_x497->to_tai;
      kk_std_core_types__maybe _pat_3_1 = _con_x497->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_1 = _con_x497->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_1 = _con_x497->mb_from_mjd2000;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5_1, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_1, _ctx);
        kk_std_core_types__maybe_drop(_pat_3_1, _ctx);
        kk_function_drop(_pat_2_1, _ctx);
        kk_function_drop(_pat_1_1, _ctx);
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_string_dup(_x_1, _ctx);
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x494 = _x_1; /*string*/
    }
  }
  _match_x184 = kk_string_is_eq(_x_x490,_x_x494,kk_context()); /*bool*/
  if (_match_x184) {
    instant_0_10070 = j; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x498;
    kk_std_time_timestamp__timestamp _x_x499;
    {
      kk_std_time_timestamp__timestamp _x_2 = j.since;
      kk_std_time_instant__timescale _pat_2_2 = j.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x500 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x501 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x499 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x502;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = j.since;
      kk_std_time_instant__timescale _x_3 = j.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x503 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x504 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(j, _ctx);
      _x_x502 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x505;
    {
      kk_std_time_timestamp__timestamp _pat_0_1_0_0 = i.since;
      kk_std_time_instant__timescale _x_1_0_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x506 = kk_std_time_timestamp__as_Timestamp(_pat_0_1_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x507 = kk_std_time_instant__as_Timescale(_x_1_0_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_1_0_0, _ctx);
      _x_x505 = _x_1_0_0; /*std/time/instant/timescale*/
    }
    _x_x498 = kk_std_time_instant_convert(_x_x499, _x_x502, _x_x505, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x508;
    {
      kk_std_time_timestamp__timestamp _pat_0_1_0_1 = i.since;
      kk_std_time_instant__timescale _x_1_0_1 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x509 = kk_std_time_timestamp__as_Timestamp(_pat_0_1_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x510 = kk_std_time_instant__as_Timescale(_x_1_0_1, _ctx);
      kk_std_time_instant__timescale_dup(_x_1_0_1, _ctx);
      _x_x508 = _x_1_0_1; /*std/time/instant/timescale*/
    }
    instant_0_10070 = kk_std_time_instant__new_Instant(_x_x498, _x_x508, _ctx); /*std/time/instant/instant*/
  }
  kk_std_time_timestamp__timestamp _x_x511;
  {
    kk_std_time_timestamp__timestamp _x_4 = i.since;
    kk_std_time_instant__timescale _pat_2_4 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x512 = kk_std_time_timestamp__as_Timestamp(_x_4, _ctx);
    struct kk_std_time_instant_Timescale* _con_x513 = kk_std_time_instant__as_Timescale(_pat_2_4, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_4, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x511 = _x_4; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_timestamp__timestamp _x_x514;
  {
    kk_std_time_timestamp__timestamp _x_0_0 = instant_0_10070.since;
    kk_std_time_instant__timescale _pat_2_0_0 = instant_0_10070.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x515 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x516 = kk_std_time_instant__as_Timescale(_pat_2_0_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0_0, _ctx);
    kk_std_time_instant__instant_drop(instant_0_10070, _ctx);
    _x_x514 = _x_0_0; /*std/time/timestamp/timestamp*/
  }
  return kk_std_time_timestamp_cmp(_x_x511, _x_x514, _ctx);
}
 
// Are two timescales the same?

bool kk_std_time_instant_timescale_fs__lp__eq__eq__rp_(kk_std_time_instant__timescale t1, kk_std_time_instant__timescale t2, kk_context_t* _ctx) { /* (t1 : timescale, t2 : timescale) -> bool */ 
  kk_string_t _x_x518;
  {
    struct kk_std_time_instant_Timescale* _con_x519 = kk_std_time_instant__as_Timescale(t1, _ctx);
    kk_string_t _x = _con_x519->name;
    kk_string_t _pat_0 = _con_x519->unit;
    kk_function_t _pat_1 = _con_x519->from_tai;
    kk_function_t _pat_2 = _con_x519->to_tai;
    kk_std_core_types__maybe _pat_3 = _con_x519->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4 = _con_x519->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5 = _con_x519->mb_from_mjd2000;
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
    _x_x518 = _x; /*string*/
  }
  kk_string_t _x_x520;
  {
    struct kk_std_time_instant_Timescale* _con_x521 = kk_std_time_instant__as_Timescale(t2, _ctx);
    kk_string_t _x_0 = _con_x521->name;
    kk_string_t _pat_0_0 = _con_x521->unit;
    kk_function_t _pat_1_0 = _con_x521->from_tai;
    kk_function_t _pat_2_0 = _con_x521->to_tai;
    kk_std_core_types__maybe _pat_3_0 = _con_x521->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4_0 = _con_x521->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_0 = _con_x521->mb_from_mjd2000;
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
    _x_x520 = _x_0; /*string*/
  }
  return kk_string_is_eq(_x_x518,_x_x520,kk_context());
}
 
// Given a `:duration` since the `epoch`, return a `:timespan` for that instant in time scale `ts`.

kk_std_time_timestamp__timestamp kk_std_time_instant_from_tai(kk_std_time_instant__timescale ts, kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (ts : timescale, d : std/time/duration/duration) -> std/time/timestamp/timestamp */ 
  kk_std_time_timestamp__timestamp _x_x522;
  kk_std_num_ddouble__ddouble _x_x523;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x523 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x524;
  kk_integer_t _x_x525;
  kk_std_core_types__optional _match_x183 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x183, _ctx)) {
    kk_box_t _box_x34 = _match_x183._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x34, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x183, _ctx);
    _x_x525 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x183, _ctx);
    _x_x525 = kk_integer_from_small(0); /*int*/
  }
  _x_x524 = kk_integer_clamp32(_x_x525,kk_context()); /*int32*/
  _x_x522 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x523, _x_x524, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x526 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant_convert(_x_x522, _x_x526, ts, _ctx);
}
 
// Does this timescale have leap seconds?

bool kk_std_time_instant_has_leap_seconds(kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (ts : timescale) -> bool */ 
  {
    struct kk_std_time_instant_Timescale* _con_x529 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_string_t _pat_0_0 = _con_x529->name;
    kk_string_t _pat_1_0 = _con_x529->unit;
    kk_function_t _pat_2_0 = _con_x529->from_tai;
    kk_function_t _pat_3 = _con_x529->to_tai;
    kk_std_core_types__maybe _x = _con_x529->mb_seconds_in_day;
    kk_std_core_types__maybe _pat_4 = _con_x529->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5 = _con_x529->mb_from_mjd2000;
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
  kk_std_time_timestamp__timestamp _x_x530;
  if (kk_std_core_types__is_Optional(since, _ctx)) {
    kk_box_t _box_x42 = since._cons._Optional.value;
    kk_std_time_timestamp__timestamp _uniq_since_1832 = kk_std_time_timestamp__timestamp_unbox(_box_x42, KK_BORROWED, _ctx);
    kk_std_time_timestamp__timestamp_dup(_uniq_since_1832, _ctx);
    kk_std_core_types__optional_drop(since, _ctx);
    _x_x530 = _uniq_since_1832; /*std/time/timestamp/timestamp*/
  }
  else {
    kk_std_core_types__optional_drop(since, _ctx);
    {
      kk_std_time_timestamp__timestamp _x = _this.since;
      kk_std_time_instant__timescale _pat_2 = _this.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x531 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
      struct kk_std_time_instant_Timescale* _con_x532 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x, _ctx);
      _x_x530 = _x; /*std/time/timestamp/timestamp*/
    }
  }
  kk_std_time_instant__timescale _x_x533;
  if (kk_std_core_types__is_Optional(ts, _ctx)) {
    kk_box_t _box_x43 = ts._cons._Optional.value;
    kk_std_time_instant__timescale _uniq_ts_1840 = kk_std_time_instant__timescale_unbox(_box_x43, KK_BORROWED, _ctx);
    kk_std_time_instant__timescale_dup(_uniq_ts_1840, _ctx);
    kk_std_core_types__optional_drop(ts, _ctx);
    kk_std_time_instant__instant_drop(_this, _ctx);
    _x_x533 = _uniq_ts_1840; /*std/time/instant/timescale*/
  }
  else {
    kk_std_core_types__optional_drop(ts, _ctx);
    {
      kk_std_time_timestamp__timestamp _pat_0_1 = _this.since;
      kk_std_time_instant__timescale _x_0 = _this.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x534 = kk_std_time_timestamp__as_Timestamp(_pat_0_1, _ctx);
      struct kk_std_time_instant_Timescale* _con_x535 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_std_time_instant__timescale_dup(_x_0, _ctx);
      kk_std_time_instant__instant_drop(_this, _ctx);
      _x_x533 = _x_0; /*std/time/instant/timescale*/
    }
  }
  return kk_std_time_instant__new_Instant(_x_x530, _x_x533, _ctx);
}
 
// The seconds in the day of instant `i` (in its time scale).

kk_std_num_ddouble__ddouble kk_std_time_instant_seconds_in_day(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/timestamp/timespan */ 
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x536 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x537 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x538 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0 = _con_x538->name;
      kk_string_t _pat_1 = _con_x538->unit;
      kk_function_t _pat_2 = _con_x538->from_tai;
      kk_function_t _pat_3 = _con_x538->to_tai;
      kk_std_core_types__maybe _x = _con_x538->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x538->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x538->mb_from_mjd2000;
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
        kk_box_t _fun_unbox_x47 = _x._cons.Just.value;
        kk_box_t _x_x539;
        kk_function_t _x_x544 = kk_function_unbox(_fun_unbox_x47, _ctx); /*(t : 48) -> 49*/
        kk_box_t _x_x540;
        kk_std_time_timestamp__timestamp _x_x541;
        {
          kk_std_time_timestamp__timestamp _x_1 = i.since;
          kk_std_time_instant__timescale _pat_2_1 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x542 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
          struct kk_std_time_instant_Timescale* _con_x543 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
          kk_std_time_instant__instant_drop(i, _ctx);
          _x_x541 = _x_1; /*std/time/timestamp/timestamp*/
        }
        _x_x540 = kk_std_time_timestamp__timestamp_box(_x_x541, _ctx); /*48*/
        _x_x539 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x544, (_x_x544, _x_x540, _ctx), _ctx); /*49*/
        return kk_std_num_ddouble__ddouble_unbox(_x_x539, KK_OWNED, _ctx);
      }
    }
  }
}
 
// Return days since 2000-01-01 in the time scale of the instant,
// together with the clock on that day.

kk_std_core_types__tuple2 kk_std_time_instant_days_clock(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/date/clock) */ 
  kk_std_core_types__tuple2 _match_x182;
  kk_std_time_timestamp__timestamp _x_x548;
  {
    kk_std_time_timestamp__timestamp _x_0 = i.since;
    kk_std_time_instant__timescale _pat_2_1 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x549 = kk_std_time_timestamp__as_Timestamp(_x_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x550 = kk_std_time_instant__as_Timescale(_pat_2_1, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_0, _ctx);
    _x_x548 = _x_0; /*std/time/timestamp/timestamp*/
  }
  _match_x182 = kk_std_time_timestamp_days_seconds(_x_x548, _ctx); /*(int, std/num/ddouble/ddouble)*/
  {
    kk_box_t _box_x53 = _match_x182.fst;
    kk_box_t _box_x54 = _match_x182.snd;
    kk_std_num_ddouble__ddouble secs = kk_std_num_ddouble__ddouble_unbox(_box_x54, KK_BORROWED, _ctx);
    kk_integer_t days_0 = kk_integer_unbox(_box_x53, _ctx);
    kk_integer_dup(days_0, _ctx);
    kk_std_core_types__tuple2_drop(_match_x182, _ctx);
    kk_std_time_date__clock _b_x56_58;
    kk_integer_t _x_x551;
    int32_t _x_x552;
    {
      kk_std_time_timestamp__timestamp _x_0_0 = i.since;
      kk_std_time_instant__timescale _pat_2_1_0 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x553 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
      struct kk_std_time_instant_Timescale* _con_x554 = kk_std_time_instant__as_Timescale(_pat_2_1_0, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_0_0, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      {
        struct kk_std_time_timestamp_Timestamp* _con_x555 = kk_std_time_timestamp__as_Timestamp(_x_0_0, _ctx);
        kk_std_num_ddouble__ddouble _pat_0_0 = _con_x555->since;
        int32_t _x = _con_x555->leap32;
        if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
          kk_datatype_ptr_free(_x_0_0, _ctx);
        }
        else {
          kk_datatype_ptr_decref(_x_0_0, _ctx);
        }
        _x_x552 = _x; /*int32*/
      }
    }
    _x_x551 = kk_integer_from_int(_x_x552,kk_context()); /*int*/
    _b_x56_58 = kk_std_time_date_leap_fs_clock(secs, _x_x551, _ctx); /*std/time/date/clock*/
    return kk_std_core_types__new_Tuple2(kk_integer_box(days_0, _ctx), kk_std_time_date__clock_box(_b_x56_58, _ctx), _ctx);
  }
}
 
// Return the instant in time scale `ts`, `days` and `secs` after 2000-01-01 in that timescale.

kk_std_time_instant__instant kk_std_time_instant_date_fs_instant(kk_std_time_instant__timescale ts, kk_integer_t days_0, kk_std_num_ddouble__ddouble secs, kk_std_core_types__optional leap, kk_context_t* _ctx) { /* (ts : timescale, days : int, secs : std/time/timestamp/timespan, leap : ? int) -> instant */ 
  kk_std_time_timestamp__timestamp t_10088;
  kk_std_core_types__optional _x_x556 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x557;
  kk_box_t _x_x558;
  kk_integer_t _x_x559;
  if (kk_std_core_types__is_Optional(leap, _ctx)) {
    kk_box_t _box_x60 = leap._cons._Optional.value;
    kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x60, _ctx);
    kk_integer_dup(_uniq_leap_1920, _ctx);
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x559 = _uniq_leap_1920; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(leap, _ctx);
    _x_x559 = kk_integer_from_small(0); /*int*/
  }
  _x_x558 = kk_integer_box(_x_x559, _ctx); /*7*/
  _x_x557 = kk_std_core_types__new_Optional(_x_x558, _ctx); /*? 7*/
  t_10088 = kk_std_time_timestamp_timestamp_days(days_0, _x_x556, _x_x557, _ctx); /*std/time/timestamp/timestamp*/
  return kk_std_time_instant__new_Instant(t_10088, ts, _ctx);
}
 
// Return the instant at (TAI) SI seconds duration since the `epoch`.

kk_std_time_instant__instant kk_std_time_instant_duration_fs_instant(kk_std_time_duration__duration d, kk_context_t* _ctx) { /* (d : std/time/duration/duration) -> instant */ 
  kk_std_time_timestamp__timestamp t_10090;
  kk_std_num_ddouble__ddouble _x_x560;
  {
    kk_std_num_ddouble__ddouble _x = d.secs;
    _x_x560 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x561;
  kk_integer_t _x_x562;
  kk_std_core_types__optional _match_x181 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x181, _ctx)) {
    kk_box_t _box_x64 = _match_x181._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x64, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x181, _ctx);
    _x_x562 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x181, _ctx);
    _x_x562 = kk_integer_from_small(0); /*int*/
  }
  _x_x561 = kk_integer_clamp32(_x_x562,kk_context()); /*int32*/
  t_10090 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x560, _x_x561, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x563 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10090, _x_x563, _ctx);
}
 
// Round an instant to a certain precision (`prec` is number of digits of the fraction of the second).
// Takes special care for instants that use a UTC timescale to round into leap seconds if appropriate.

kk_std_time_instant__instant kk_std_time_instant_round_to_prec(kk_std_time_instant__instant i, kk_integer_t prec, kk_context_t* _ctx) { /* (i : instant, prec : int) -> instant */ 
  bool _match_x178 = kk_integer_lt_borrow(prec,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x178) {
    kk_integer_drop(prec, _ctx);
    return i;
  }
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x564 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x565 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x566 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _pat_0_1 = _con_x566->name;
      kk_string_t _pat_1_1 = _con_x566->unit;
      kk_function_t _pat_2_0 = _con_x566->from_tai;
      kk_function_t _pat_3 = _con_x566->to_tai;
      kk_std_core_types__maybe _x = _con_x566->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x566->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x566->mb_from_mjd2000;
      kk_reuse_t _ru_x240 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_std_core_types__maybe_drop(_pat_5, _ctx);
        kk_std_core_types__maybe_drop(_pat_4, _ctx);
        kk_function_drop(_pat_3, _ctx);
        kk_reuse_t _x_x567 = kk_datatype_ptr_dropn_reuse(_pat_2_0, (KK_I32(0)), _ctx); /*@reuse*/
        _ru_x240 = _x_x567;
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
        kk_std_time_instant__instant instant_0_10099;
        bool _match_x180;
        kk_string_t _x_x568;
        {
          kk_std_time_timestamp__timestamp _pat_0_0_1 = i.since;
          kk_std_time_instant__timescale _x_0_1 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x569 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
          struct kk_std_time_instant_Timescale* _con_x570 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
          kk_std_time_instant__timescale_dup(_x_0_1, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x571 = kk_std_time_instant__as_Timescale(_x_0_1, _ctx);
            kk_string_t _x_4 = _con_x571->name;
            kk_string_t _pat_0_5 = _con_x571->unit;
            kk_function_t _pat_1_4 = _con_x571->from_tai;
            kk_function_t _pat_2_4 = _con_x571->to_tai;
            kk_std_core_types__maybe _pat_3_4 = _con_x571->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_4 = _con_x571->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_4 = _con_x571->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_4, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_4, _ctx);
              kk_function_drop(_pat_2_4, _ctx);
              kk_function_drop(_pat_1_4, _ctx);
              kk_string_drop(_pat_0_5, _ctx);
              kk_datatype_ptr_free(_x_0_1, _ctx);
            }
            else {
              kk_string_dup(_x_4, _ctx);
              kk_datatype_ptr_decref(_x_0_1, _ctx);
            }
            _x_x568 = _x_4; /*string*/
          }
        }
        kk_string_t _x_x572;
        kk_std_time_instant__timescale _x_x573 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
        {
          struct kk_std_time_instant_Timescale* _con_x574 = kk_std_time_instant__as_Timescale(_x_x573, _ctx);
          kk_string_t _x_1_1 = _con_x574->name;
          _x_x572 = kk_string_dup(_x_1_1, _ctx); /*string*/
        }
        _match_x180 = kk_string_is_eq(_x_x568,_x_x572,kk_context()); /*bool*/
        if (_match_x180) {
          instant_0_10099 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
        }
        else {
          kk_std_time_timestamp__timestamp _x_x575;
          kk_std_time_timestamp__timestamp _x_x576;
          {
            kk_std_time_timestamp__timestamp _x_2_0 = i.since;
            kk_std_time_instant__timescale _pat_2_2_1 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x577 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
            struct kk_std_time_instant_Timescale* _con_x578 = kk_std_time_instant__as_Timescale(_pat_2_2_1, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_2_0, _ctx);
            _x_x576 = _x_2_0; /*std/time/timestamp/timestamp*/
          }
          kk_std_time_instant__timescale _x_x579;
          {
            kk_std_time_timestamp__timestamp _pat_0_4_0 = i.since;
            kk_std_time_instant__timescale _x_3_0 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x580 = kk_std_time_timestamp__as_Timestamp(_pat_0_4_0, _ctx);
            struct kk_std_time_instant_Timescale* _con_x581 = kk_std_time_instant__as_Timescale(_x_3_0, _ctx);
            kk_std_time_instant__timescale_dup(_x_3_0, _ctx);
            _x_x579 = _x_3_0; /*std/time/instant/timescale*/
          }
          kk_std_time_instant__timescale _x_x582 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
          _x_x575 = kk_std_time_instant_convert(_x_x576, _x_x579, _x_x582, _ctx); /*std/time/timestamp/timestamp*/
          kk_std_time_instant__timescale _x_x583 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
          instant_0_10099 = kk_std_time_instant__new_Instant(_x_x575, _x_x583, _ctx); /*std/time/instant/instant*/
        }
        kk_std_time_instant__instant i_0_10214;
        kk_std_time_timestamp__timestamp _x_x584;
        kk_std_num_ddouble__ddouble _x_x585;
        kk_std_num_ddouble__ddouble _x_x586;
        {
          kk_std_time_timestamp__timestamp _x_2_1 = instant_0_10099.since;
          kk_std_time_instant__timescale _pat_2_3_1 = instant_0_10099.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x587 = kk_std_time_timestamp__as_Timestamp(_x_2_1, _ctx);
          struct kk_std_time_instant_Timescale* _con_x588 = kk_std_time_instant__as_Timescale(_pat_2_3_1, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_2_1, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x589 = kk_std_time_timestamp__as_Timestamp(_x_2_1, _ctx);
            kk_std_num_ddouble__ddouble _x_1_2 = _con_x589->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_2_1, _ctx)) {
              kk_datatype_ptr_free(_x_2_1, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_2_1, _ctx);
            }
            _x_x586 = _x_1_2; /*std/time/timestamp/timespan*/
          }
        }
        _x_x585 = kk_std_num_ddouble_round_to_prec(_x_x586, prec, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x590;
        {
          kk_std_time_timestamp__timestamp _x_2_1_0 = instant_0_10099.since;
          kk_std_time_instant__timescale _pat_2_3_1_0 = instant_0_10099.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x591 = kk_std_time_timestamp__as_Timestamp(_x_2_1_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x592 = kk_std_time_instant__as_Timescale(_pat_2_3_1_0, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_2_1_0, _ctx);
          kk_std_time_instant__instant_drop(instant_0_10099, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x593 = kk_std_time_timestamp__as_Timestamp(_x_2_1_0, _ctx);
            kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x593->since;
            int32_t _x_0_0_0 = _con_x593->leap32;
            if kk_likely(kk_datatype_ptr_is_unique(_x_2_1_0, _ctx)) {
              kk_datatype_ptr_free(_x_2_1_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_2_1_0, _ctx);
            }
            _x_x590 = _x_0_0_0; /*int32*/
          }
        }
        _x_x584 = kk_std_time_timestamp__new_Timestamp(_ru_x240, 0, _x_x585, _x_x590, _ctx); /*std/time/timestamp/timestamp*/
        kk_std_time_instant__timescale _x_x594 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
        i_0_10214 = kk_std_time_instant__new_Instant(_x_x584, _x_x594, _ctx); /*std/time/instant/instant*/
        bool _match_x179;
        kk_string_t _x_x595;
        {
          kk_std_time_timestamp__timestamp _pat_0_0_0 = i_0_10214.since;
          kk_std_time_instant__timescale _x_0_0 = i_0_10214.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x596 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x597 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x598 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
            kk_string_t _x_1 = _con_x598->name;
            kk_string_t _pat_0_3 = _con_x598->unit;
            kk_function_t _pat_1_3 = _con_x598->from_tai;
            kk_function_t _pat_2_2 = _con_x598->to_tai;
            kk_std_core_types__maybe _pat_3_1 = _con_x598->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_1 = _con_x598->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_1 = _con_x598->mb_from_mjd2000;
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
            _x_x595 = _x_1; /*string*/
          }
        }
        kk_string_t _x_x599;
        {
          kk_std_time_timestamp__timestamp _pat_0_5_0 = i.since;
          kk_std_time_instant__timescale _x_3_1 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x600 = kk_std_time_timestamp__as_Timestamp(_pat_0_5_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x601 = kk_std_time_instant__as_Timescale(_x_3_1, _ctx);
          kk_std_time_instant__timescale_dup(_x_3_1, _ctx);
          {
            struct kk_std_time_instant_Timescale* _con_x602 = kk_std_time_instant__as_Timescale(_x_3_1, _ctx);
            kk_string_t _x_1_0 = _con_x602->name;
            kk_string_t _pat_0_1_0 = _con_x602->unit;
            kk_function_t _pat_1_1_0 = _con_x602->from_tai;
            kk_function_t _pat_2_1_0 = _con_x602->to_tai;
            kk_std_core_types__maybe _pat_3_1_0 = _con_x602->mb_seconds_in_day;
            kk_std_core_types__maybe _pat_4_1_0 = _con_x602->mb_to_mjd2000;
            kk_std_core_types__maybe _pat_5_1_0 = _con_x602->mb_from_mjd2000;
            if kk_likely(kk_datatype_ptr_is_unique(_x_3_1, _ctx)) {
              kk_std_core_types__maybe_drop(_pat_5_1_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_4_1_0, _ctx);
              kk_std_core_types__maybe_drop(_pat_3_1_0, _ctx);
              kk_function_drop(_pat_2_1_0, _ctx);
              kk_function_drop(_pat_1_1_0, _ctx);
              kk_string_drop(_pat_0_1_0, _ctx);
              kk_datatype_ptr_free(_x_3_1, _ctx);
            }
            else {
              kk_string_dup(_x_1_0, _ctx);
              kk_datatype_ptr_decref(_x_3_1, _ctx);
            }
            _x_x599 = _x_1_0; /*string*/
          }
        }
        _match_x179 = kk_string_is_eq(_x_x595,_x_x599,kk_context()); /*bool*/
        if (_match_x179) {
          kk_std_time_instant__instant_drop(i, _ctx);
          return i_0_10214;
        }
        {
          kk_std_time_timestamp__timestamp _x_x603;
          kk_std_time_timestamp__timestamp _x_x604;
          {
            kk_std_time_timestamp__timestamp _x_2 = i_0_10214.since;
            kk_std_time_instant__timescale _pat_2_2_0 = i_0_10214.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x605 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
            struct kk_std_time_instant_Timescale* _con_x606 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
            kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
            _x_x604 = _x_2; /*std/time/timestamp/timestamp*/
          }
          kk_std_time_instant__timescale _x_x607;
          {
            kk_std_time_timestamp__timestamp _pat_0_4 = i_0_10214.since;
            kk_std_time_instant__timescale _x_3 = i_0_10214.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x608 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
            struct kk_std_time_instant_Timescale* _con_x609 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
            kk_std_time_instant__timescale_dup(_x_3, _ctx);
            kk_std_time_instant__instant_drop(i_0_10214, _ctx);
            _x_x607 = _x_3; /*std/time/instant/timescale*/
          }
          kk_std_time_instant__timescale _x_x610;
          {
            kk_std_time_timestamp__timestamp _pat_0_5_0_0 = i.since;
            kk_std_time_instant__timescale _x_3_1_0 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x611 = kk_std_time_timestamp__as_Timestamp(_pat_0_5_0_0, _ctx);
            struct kk_std_time_instant_Timescale* _con_x612 = kk_std_time_instant__as_Timescale(_x_3_1_0, _ctx);
            kk_std_time_instant__timescale_dup(_x_3_1_0, _ctx);
            _x_x610 = _x_3_1_0; /*std/time/instant/timescale*/
          }
          _x_x603 = kk_std_time_instant_convert(_x_x604, _x_x607, _x_x610, _ctx); /*std/time/timestamp/timestamp*/
          kk_std_time_instant__timescale _x_x613;
          {
            kk_std_time_timestamp__timestamp _pat_0_5_0_1 = i.since;
            kk_std_time_instant__timescale _x_3_1_1 = i.ts;
            struct kk_std_time_timestamp_Timestamp* _con_x614 = kk_std_time_timestamp__as_Timestamp(_pat_0_5_0_1, _ctx);
            struct kk_std_time_instant_Timescale* _con_x615 = kk_std_time_instant__as_Timescale(_x_3_1_1, _ctx);
            kk_std_time_instant__timescale_dup(_x_3_1_1, _ctx);
            kk_std_time_instant__instant_drop(i, _ctx);
            _x_x613 = _x_3_1_1; /*std/time/instant/timescale*/
          }
          return kk_std_time_instant__new_Instant(_x_x603, _x_x613, _ctx);
        }
      }
      {
        kk_std_time_timestamp__timestamp _x_x616;
        kk_std_num_ddouble__ddouble _x_x617;
        kk_std_num_ddouble__ddouble _x_x618;
        {
          kk_std_time_timestamp__timestamp _x_5 = i.since;
          kk_std_time_instant__timescale _pat_2_7 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x619 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
          struct kk_std_time_instant_Timescale* _con_x620 = kk_std_time_instant__as_Timescale(_pat_2_7, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_5, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x621 = kk_std_time_timestamp__as_Timestamp(_x_5, _ctx);
            kk_std_num_ddouble__ddouble _x_4_0 = _con_x621->since;
            if kk_likely(kk_datatype_ptr_is_unique(_x_5, _ctx)) {
              kk_datatype_ptr_free(_x_5, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_5, _ctx);
            }
            _x_x618 = _x_4_0; /*std/time/timestamp/timespan*/
          }
        }
        _x_x617 = kk_std_num_ddouble_round_to_prec(_x_x618, prec, _ctx); /*std/num/ddouble/ddouble*/
        int32_t _x_x622;
        {
          kk_std_time_timestamp__timestamp _x_5_0 = i.since;
          kk_std_time_instant__timescale _pat_2_7_0 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x623 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x624 = kk_std_time_instant__as_Timescale(_pat_2_7_0, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_5_0, _ctx);
          {
            struct kk_std_time_timestamp_Timestamp* _con_x625 = kk_std_time_timestamp__as_Timestamp(_x_5_0, _ctx);
            kk_std_num_ddouble__ddouble _pat_0_0_1_0 = _con_x625->since;
            int32_t _x_0_1_0 = _con_x625->leap32;
            if kk_likely(kk_datatype_ptr_is_unique(_x_5_0, _ctx)) {
              kk_datatype_ptr_free(_x_5_0, _ctx);
            }
            else {
              kk_datatype_ptr_decref(_x_5_0, _ctx);
            }
            _x_x622 = _x_0_1_0; /*int32*/
          }
        }
        _x_x616 = kk_std_time_timestamp__new_Timestamp(_ru_x240, 0, _x_x617, _x_x622, _ctx); /*std/time/timestamp/timestamp*/
        kk_std_time_instant__timescale _x_x626;
        {
          kk_std_time_timestamp__timestamp _pat_0_8 = i.since;
          kk_std_time_instant__timescale _x_6 = i.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x627 = kk_std_time_timestamp__as_Timestamp(_pat_0_8, _ctx);
          struct kk_std_time_instant_Timescale* _con_x628 = kk_std_time_instant__as_Timescale(_x_6, _ctx);
          kk_std_time_instant__timescale_dup(_x_6, _ctx);
          kk_std_time_instant__instant_drop(i, _ctx);
          _x_x626 = _x_6; /*std/time/instant/timescale*/
        }
        return kk_std_time_instant__new_Instant(_x_x616, _x_x626, _ctx);
      }
    }
  }
}
 
// The minimum of two instants.

kk_std_time_instant__instant kk_std_time_instant_min(kk_std_time_instant__instant i, kk_std_time_instant__instant j, kk_context_t* _ctx) { /* (i : instant, j : instant) -> instant */ 
  bool _match_x177;
  kk_std_core_types__order _x_x634;
  kk_std_time_instant__instant _x_x635 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x_x636 = kk_std_time_instant__instant_dup(j, _ctx); /*std/time/instant/instant*/
  _x_x634 = kk_std_time_instant_cmp(_x_x635, _x_x636, _ctx); /*order*/
  _match_x177 = kk_std_core_order__lp__excl__eq__rp_(_x_x634, kk_std_core_types__new_Gt(_ctx), _ctx); /*bool*/
  if (_match_x177) {
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
  bool _match_x176;
  kk_std_core_types__order _x_x637;
  kk_std_time_instant__instant _x_x638 = kk_std_time_instant__instant_dup(i, _ctx); /*std/time/instant/instant*/
  kk_std_time_instant__instant _x_x639 = kk_std_time_instant__instant_dup(j, _ctx); /*std/time/instant/instant*/
  _x_x637 = kk_std_time_instant_cmp(_x_x638, _x_x639, _ctx); /*order*/
  _match_x176 = kk_std_core_order__lp__excl__eq__rp_(_x_x637, kk_std_core_types__new_Lt(_ctx), _ctx); /*bool*/
  if (_match_x176) {
    kk_std_time_instant__instant_drop(j, _ctx);
    return i;
  }
  {
    kk_std_time_instant__instant_drop(i, _ctx);
    return j;
  }
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
  kk_std_time_instant__instant i_0_10111;
  bool _match_x175;
  kk_string_t _x_x647;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x648 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x649 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x650 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x650->name;
      kk_string_t _pat_0 = _con_x650->unit;
      kk_function_t _pat_1 = _con_x650->from_tai;
      kk_function_t _pat_2 = _con_x650->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x650->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x650->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x650->mb_from_mjd2000;
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
      _x_x647 = _x; /*string*/
    }
  }
  kk_string_t _x_x651;
  {
    struct kk_std_time_instant_Timescale* _con_x652 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_1 = _con_x652->name;
    kk_string_dup(_x_1, _ctx);
    _x_x651 = _x_1; /*string*/
  }
  _match_x175 = kk_string_is_eq(_x_x647,_x_x651,kk_context()); /*bool*/
  if (_match_x175) {
    kk_datatype_ptr_dropn(tscale, (KK_I32(10)), _ctx);
    i_0_10111 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x653;
    kk_std_time_timestamp__timestamp _x_x654;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x655 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x656 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x654 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x657;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x658 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x659 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x657 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x660 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    _x_x653 = kk_std_time_instant_convert(_x_x654, _x_x657, _x_x660, _ctx); /*std/time/timestamp/timestamp*/
    i_0_10111 = kk_std_time_instant__new_Instant(_x_x653, tscale, _ctx); /*std/time/instant/instant*/
  }
  kk_std_time_timestamp__timestamp _x_x661;
  kk_std_num_ddouble__ddouble _x_x662;
  kk_std_num_ddouble__ddouble _x_x663;
  {
    kk_std_time_timestamp__timestamp _x_1_0 = i_0_10111.since;
    kk_std_time_instant__timescale _pat_2_1_0 = i_0_10111.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x664 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x665 = kk_std_time_instant__as_Timescale(_pat_2_1_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x666 = kk_std_time_timestamp__as_Timestamp(_x_1_0, _ctx);
      kk_std_num_ddouble__ddouble _x_4 = _con_x666->since;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0, _ctx);
      }
      _x_x663 = _x_4; /*std/time/timestamp/timespan*/
    }
  }
  _x_x662 = kk_std_num_ddouble__lp__plus__rp_(_x_x663, t, _ctx); /*std/num/ddouble/ddouble*/
  int32_t _x_x667;
  {
    kk_std_time_timestamp__timestamp _x_1_0_0 = i_0_10111.since;
    kk_std_time_instant__timescale _pat_2_1_0_0 = i_0_10111.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x668 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x669 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1_0_0, _ctx);
    {
      struct kk_std_time_timestamp_Timestamp* _con_x670 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
      kk_std_num_ddouble__ddouble _pat_0_0_0 = _con_x670->since;
      int32_t _x_0_0 = _con_x670->leap32;
      if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0, _ctx)) {
        kk_datatype_ptr_free(_x_1_0_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_x_1_0_0, _ctx);
      }
      _x_x667 = _x_0_0; /*int32*/
    }
  }
  _x_x661 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x662, _x_x667, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x671;
  {
    kk_std_time_timestamp__timestamp _pat_0_2_0 = i_0_10111.since;
    kk_std_time_instant__timescale _x_2_0 = i_0_10111.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x672 = kk_std_time_timestamp__as_Timestamp(_pat_0_2_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x673 = kk_std_time_instant__as_Timescale(_x_2_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_2_0, _ctx);
    kk_std_time_instant__instant_drop(i_0_10111, _ctx);
    _x_x671 = _x_2_0; /*std/time/instant/timescale*/
  }
  return kk_std_time_instant__new_Instant(_x_x661, _x_x671, _ctx);
}
 
// Internal: show an instant as a raw timestamp in a given precision, postfixed with the time scale name.

kk_string_t kk_std_time_instant_show_raw(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (i : instant, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_integer_t _b_x73_78;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x72 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_2777 = kk_integer_unbox(_box_x72, _ctx);
    kk_integer_dup(_uniq_max_prec_2777, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x73_78 = _uniq_max_prec_2777; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _b_x73_78 = kk_integer_from_small(9); /*int*/
  }
  kk_integer_t _b_x75_79;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x74 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_2781 = kk_integer_unbox(_box_x74, _ctx);
    kk_integer_dup(_uniq_secs_width_2781, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x75_79 = _uniq_secs_width_2781; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _b_x75_79 = kk_integer_from_small(1); /*int*/
  }
  kk_string_t _b_x77_80;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x76 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_2785 = kk_string_unbox(_box_x76);
    kk_string_dup(_uniq_unit_2785, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x77_80 = _uniq_unit_2785; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _b_x77_80 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x675;
  kk_std_time_timestamp__timestamp _x_x676;
  {
    kk_std_time_timestamp__timestamp _x = i.since;
    kk_std_time_instant__timescale _pat_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x677 = kk_std_time_timestamp__as_Timestamp(_x, _ctx);
    struct kk_std_time_instant_Timescale* _con_x678 = kk_std_time_instant__as_Timescale(_pat_2, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x, _ctx);
    _x_x676 = _x; /*std/time/timestamp/timestamp*/
  }
  kk_std_core_types__optional _x_x679 = kk_std_core_types__new_Optional(kk_integer_box(_b_x73_78, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x680 = kk_std_core_types__new_Optional(kk_integer_box(_b_x75_79, _ctx), _ctx); /*? 7*/
  kk_std_core_types__optional _x_x681 = kk_std_core_types__new_Optional(kk_string_box(_b_x77_80), _ctx); /*? 7*/
  _x_x675 = kk_std_time_timestamp_ts_show(_x_x676, _x_x679, _x_x680, _x_x681, _ctx); /*string*/
  kk_string_t _x_x682;
  bool _match_x173;
  kk_string_t _x_x683;
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_1 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x684 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x685 = kk_std_time_instant__as_Timescale(_x_1, _ctx);
    kk_std_time_instant__timescale_dup(_x_1, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x686 = kk_std_time_instant__as_Timescale(_x_1, _ctx);
      kk_string_t _x_0 = _con_x686->name;
      kk_string_t _pat_0_1 = _con_x686->unit;
      kk_function_t _pat_1_1 = _con_x686->from_tai;
      kk_function_t _pat_2_1 = _con_x686->to_tai;
      kk_std_core_types__maybe _pat_3_1 = _con_x686->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4_1 = _con_x686->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5_0 = _con_x686->mb_from_mjd2000;
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
      _x_x683 = _x_0; /*string*/
    }
  }
  kk_string_t _x_x687 = kk_string_empty(); /*string*/
  _match_x173 = kk_string_is_eq(_x_x683,_x_x687,kk_context()); /*bool*/
  if (_match_x173) {
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x682 = kk_string_empty(); /*string*/
  }
  else {
    bool _match_x174;
    kk_string_t _x_x690;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x691 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x692 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      {
        struct kk_std_time_instant_Timescale* _con_x693 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
        kk_string_t _x_2 = _con_x693->name;
        kk_string_t _pat_0_3 = _con_x693->unit;
        kk_function_t _pat_1_3 = _con_x693->from_tai;
        kk_function_t _pat_2_3 = _con_x693->to_tai;
        kk_std_core_types__maybe _pat_3_3 = _con_x693->mb_seconds_in_day;
        kk_std_core_types__maybe _pat_4_3 = _con_x693->mb_to_mjd2000;
        kk_std_core_types__maybe _pat_5_3 = _con_x693->mb_from_mjd2000;
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
        _x_x690 = _x_2; /*string*/
      }
    }
    kk_string_t _x_x694;
    kk_define_string_literal(, _s_x695, 3, "TAI", _ctx)
    _x_x694 = kk_string_dup(_s_x695, _ctx); /*string*/
    _match_x174 = kk_string_is_eq(_x_x690,_x_x694,kk_context()); /*bool*/
    if (_match_x174) {
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x682 = kk_string_empty(); /*string*/
    }
    else {
      kk_string_t _x_x697;
      kk_define_string_literal(, _s_x698, 1, " ", _ctx)
      _x_x697 = kk_string_dup(_s_x698, _ctx); /*string*/
      kk_string_t _x_x699;
      {
        kk_std_time_timestamp__timestamp _pat_0_6 = i.since;
        kk_std_time_instant__timescale _x_5 = i.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x700 = kk_std_time_timestamp__as_Timestamp(_pat_0_6, _ctx);
        struct kk_std_time_instant_Timescale* _con_x701 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
        kk_std_time_instant__timescale_dup(_x_5, _ctx);
        kk_std_time_instant__instant_drop(i, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x702 = kk_std_time_instant__as_Timescale(_x_5, _ctx);
          kk_string_t _x_4 = _con_x702->name;
          kk_string_t _pat_0_5 = _con_x702->unit;
          kk_function_t _pat_1_5 = _con_x702->from_tai;
          kk_function_t _pat_2_5 = _con_x702->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x702->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x702->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_5 = _con_x702->mb_from_mjd2000;
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
          _x_x699 = _x_4; /*string*/
        }
      }
      _x_x682 = kk_std_core_types__lp__plus__plus__rp_(_x_x697, _x_x699, _ctx); /*string*/
    }
  }
  return kk_std_core_types__lp__plus__plus__rp_(_x_x675, _x_x682, _ctx);
}
 
// Show an instant as a number of (TAI) SI seconds since the `epoch` in a given precision.
// This can be used as an unambiguous time stamp.

kk_string_t kk_std_time_instant_instant_fs_show(kk_std_time_instant__instant i, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_context_t* _ctx) { /* (i : instant, max-prec : ? int, secs-width : ? int) -> string */ 
  kk_std_time_instant__instant _x_x703;
  bool _match_x172;
  kk_string_t _x_x704;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x705 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x706 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x707 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x707->name;
      kk_string_t _pat_0 = _con_x707->unit;
      kk_function_t _pat_1 = _con_x707->from_tai;
      kk_function_t _pat_2 = _con_x707->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x707->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x707->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x707->mb_from_mjd2000;
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
      _x_x704 = _x; /*string*/
    }
  }
  kk_string_t _x_x708;
  kk_std_time_instant__timescale _x_x709 = kk_std_time_instant_ts_tai; /*std/time/instant/timescale*/
  {
    struct kk_std_time_instant_Timescale* _con_x710 = kk_std_time_instant__as_Timescale(_x_x709, _ctx);
    kk_string_t _x_1 = _con_x710->name;
    _x_x708 = kk_string_dup(_x_1, _ctx); /*string*/
  }
  _match_x172 = kk_string_is_eq(_x_x704,_x_x708,kk_context()); /*bool*/
  if (_match_x172) {
    _x_x703 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x711;
    kk_std_time_timestamp__timestamp _x_x712;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x713 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x714 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x712 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x715;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x716 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x717 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x715 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x718 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
    _x_x711 = kk_std_time_instant_convert(_x_x712, _x_x715, _x_x718, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x719 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
    _x_x703 = kk_std_time_instant__new_Instant(_x_x711, _x_x719, _ctx); /*std/time/instant/instant*/
  }
  kk_std_core_types__optional _x_x720;
  kk_box_t _x_x721;
  kk_integer_t _x_x722;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x81 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3011 = kk_integer_unbox(_box_x81, _ctx);
    kk_integer_dup(_uniq_max_prec_3011, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x722 = _uniq_max_prec_3011; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x722 = kk_integer_from_small(9); /*int*/
  }
  _x_x721 = kk_integer_box(_x_x722, _ctx); /*7*/
  _x_x720 = kk_std_core_types__new_Optional(_x_x721, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x723;
  kk_box_t _x_x724;
  kk_integer_t _x_x725;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x83 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_3015 = kk_integer_unbox(_box_x83, _ctx);
    kk_integer_dup(_uniq_secs_width_3015, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x_x725 = _uniq_secs_width_3015; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x_x725 = kk_integer_from_small(1); /*int*/
  }
  _x_x724 = kk_integer_box(_x_x725, _ctx); /*7*/
  _x_x723 = kk_std_core_types__new_Optional(_x_x724, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x726;
  kk_box_t _x_x727;
  kk_string_t _x_x728;
  kk_define_string_literal(, _s_x729, 1, "s", _ctx)
  _x_x728 = kk_string_dup(_s_x729, _ctx); /*string*/
  _x_x727 = kk_string_box(_x_x728); /*7*/
  _x_x726 = kk_std_core_types__new_Optional(_x_x727, _ctx); /*? 7*/
  return kk_std_time_instant_show_raw(_x_x703, _x_x720, _x_x723, _x_x726, _ctx);
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

kk_std_time_instant__timescale kk_std_time_instant_ts_gps;

kk_std_time_duration__duration kk_std_time_instant_gps2000;
 
// Get the GPS time in SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_duration__duration kk_std_time_instant_gps_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10131;
  kk_std_time_timestamp__timestamp _x_x742;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x743 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x744 = kk_std_time_instant__as_Timescale(_pat_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    _x_x742 = _x_1; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x745;
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x746 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x747 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
    kk_std_time_instant__timescale_dup(_x_2, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x745 = _x_2; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x748 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_gps, _ctx); /*std/time/instant/timescale*/
  t_10131 = kk_std_time_instant_convert(_x_x742, _x_x745, _x_x748, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration d_10129;
  kk_std_num_ddouble__ddouble _x_x749 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10131, _ctx); /*std/time/timestamp/timespan*/
  d_10129 = kk_std_time_duration__new_Duration(_x_x749, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x750;
  kk_std_num_ddouble__ddouble _x_x751;
  {
    kk_std_num_ddouble__ddouble _x = d_10129.secs;
    _x_x751 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x752;
  kk_std_time_duration__duration _x_x753 = kk_std_time_instant_gps2000; /*std/time/duration/duration*/
  {
    kk_std_num_ddouble__ddouble _x_0 = _x_x753.secs;
    _x_x752 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x750 = kk_std_num_ddouble__lp__plus__rp_(_x_x751, _x_x752, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x750, _ctx);
}
 
// Create an instant from a raw GPS time since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_duration_fs_gps_instant(kk_std_time_duration__duration gps, kk_context_t* _ctx) { /* (gps : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_10136 = kk_std_time_duration__lp__dash__rp_(gps, kk_std_time_instant_gps2000, _ctx); /*std/time/duration/duration*/;
  kk_std_time_timestamp__timestamp t_10138;
  kk_std_num_ddouble__ddouble _x_x754;
  {
    kk_std_num_ddouble__ddouble _x = d_10136.secs;
    _x_x754 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x755;
  kk_integer_t _x_x756;
  kk_std_core_types__optional _match_x168 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x168, _ctx)) {
    kk_box_t _box_x98 = _match_x168._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x98, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x168, _ctx);
    _x_x756 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x168, _ctx);
    _x_x756 = kk_integer_from_small(0); /*int*/
  }
  _x_x755 = kk_integer_clamp32(_x_x756,kk_context()); /*int32*/
  t_10138 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x754, _x_x755, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x757 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10138, _x_x757, _ctx);
}
 
// Get the GPS time as weeks and SI seconds in the week since the GPS epoch (1980-01-06Z)

kk_std_core_types__tuple2 kk_std_time_instant_gps_week_timestamp(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> (int, std/time/duration/duration) */ 
  kk_std_time_duration__duration t = kk_std_time_instant_gps_timestamp(i, _ctx); /*std/time/duration/duration*/;
  kk_integer_t w;
  kk_std_num_ddouble__ddouble _x_x758;
  kk_std_num_ddouble__ddouble _x_x759;
  kk_std_num_ddouble__ddouble _x_x760;
  {
    kk_std_num_ddouble__ddouble _x = t.secs;
    _x_x760 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x761 = kk_std_num_ddouble_ddouble_int_exp(kk_integer_from_int(25200, _ctx), kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
  _x_x759 = kk_std_num_ddouble__lp__fs__rp_(_x_x760, _x_x761, _ctx); /*std/num/ddouble/ddouble*/
  _x_x758 = kk_std_num_ddouble_floor(_x_x759, _ctx); /*std/num/ddouble/ddouble*/
  w = kk_std_num_ddouble_int(_x_x758, kk_std_core_types__new_None(_ctx), _ctx); /*int*/
  kk_integer_t secs_10142;
  kk_integer_t _x_x762 = kk_integer_dup(w, _ctx); /*int*/
  secs_10142 = kk_integer_mul(_x_x762,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/
  kk_std_time_duration__duration s;
  kk_std_time_duration__duration _x_x763;
  kk_std_num_ddouble__ddouble _x_x764;
  kk_std_core_types__optional _x_x765;
  kk_box_t _x_x766;
  double _x_x767;
  kk_std_core_types__optional _match_x167 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x167, _ctx)) {
    kk_box_t _box_x99 = _match_x167._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x99, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x167, _ctx);
    _x_x767 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x167, _ctx);
    _x_x767 = 0x0p+0; /*float64*/
  }
  _x_x766 = kk_double_box(_x_x767, _ctx); /*7*/
  _x_x765 = kk_std_core_types__new_Optional(_x_x766, _ctx); /*? 7*/
  _x_x764 = kk_std_time_timestamp_int_fs_timespan(secs_10142, _x_x765, _ctx); /*std/time/timestamp/timespan*/
  _x_x763 = kk_std_time_duration__new_Duration(_x_x764, _ctx); /*std/time/duration/duration*/
  s = kk_std_time_duration__lp__dash__rp_(t, _x_x763, _ctx); /*std/time/duration/duration*/
  return kk_std_core_types__new_Tuple2(kk_integer_box(w, _ctx), kk_std_time_duration__duration_box(s, _ctx), _ctx);
}
 
// Create an instant from a GPS time in weeks and SI seconds since the GPS epoch (1980-01-06Z)

kk_std_time_instant__instant kk_std_time_instant_date_fs_gps_instant(kk_integer_t weeks, kk_std_time_duration__duration secs, kk_context_t* _ctx) { /* (weeks : int, secs : std/time/duration/duration) -> instant */ 
  kk_integer_t secs_0_10147 = kk_integer_mul(weeks,(kk_integer_from_int(25200, _ctx)),kk_context()); /*int*/;
  kk_std_time_duration__duration d_1_10145;
  kk_std_num_ddouble__ddouble _x_x768;
  kk_std_core_types__optional _x_x769;
  kk_box_t _x_x770;
  double _x_x771;
  kk_std_core_types__optional _match_x166 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x166, _ctx)) {
    kk_box_t _box_x106 = _match_x166._cons._Optional.value;
    double _uniq_frac_155 = kk_double_unbox(_box_x106, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(_match_x166, _ctx);
    _x_x771 = _uniq_frac_155; /*float64*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x166, _ctx);
    _x_x771 = 0x0p+0; /*float64*/
  }
  _x_x770 = kk_double_box(_x_x771, _ctx); /*7*/
  _x_x769 = kk_std_core_types__new_Optional(_x_x770, _ctx); /*? 7*/
  _x_x768 = kk_std_time_timestamp_int_fs_timespan(secs_0_10147, _x_x769, _ctx); /*std/time/timestamp/timespan*/
  d_1_10145 = kk_std_time_duration__new_Duration(_x_x768, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration gps_10144;
  kk_std_num_ddouble__ddouble _x_x772;
  kk_std_num_ddouble__ddouble _x_x773;
  {
    kk_std_num_ddouble__ddouble _x_0 = d_1_10145.secs;
    _x_x773 = _x_0; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x774;
  {
    kk_std_num_ddouble__ddouble _x_0_0 = secs.secs;
    _x_x774 = _x_0_0; /*std/time/timestamp/timespan*/
  }
  _x_x772 = kk_std_num_ddouble__lp__plus__rp_(_x_x773, _x_x774, _ctx); /*std/num/ddouble/ddouble*/
  gps_10144 = kk_std_time_duration__new_Duration(_x_x772, _ctx); /*std/time/duration/duration*/
  kk_std_time_duration__duration d_10149 = kk_std_time_duration__lp__dash__rp_(gps_10144, kk_std_time_instant_gps2000, _ctx); /*std/time/duration/duration*/;
  kk_std_time_timestamp__timestamp t_10151;
  kk_std_num_ddouble__ddouble _x_x775;
  {
    kk_std_num_ddouble__ddouble _x = d_10149.secs;
    _x_x775 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x776;
  kk_integer_t _x_x777;
  kk_std_core_types__optional _match_x165 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x165, _ctx)) {
    kk_box_t _box_x109 = _match_x165._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x109, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x165, _ctx);
    _x_x777 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x165, _ctx);
    _x_x777 = kk_integer_from_small(0); /*int*/
  }
  _x_x776 = kk_integer_clamp32(_x_x777,kk_context()); /*int32*/
  t_10151 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x775, _x_x776, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x778 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10151, _x_x778, _ctx);
}
 
// The [TT](https://en.wikipedia.org/wiki/Terrestrial_Time) (Terrestrial time)
// time scale is based on SI seconds with a 1977-01-01 TAI `epoch`. It is the
// continuation of TDT (Terrestrial dynamic time) and ET (Ephemeris time). TT
// is defined as: TT = TAI + 32.184s.

kk_std_time_instant__timescale kk_std_time_instant_ts_tt;

kk_std_time_duration__duration kk_std_time_instant_tt2000;
 
// Get the TT time in SI seconds since the TT epoch (1977-01-01 TAI)

kk_std_time_duration__duration kk_std_time_instant_instant_fs_tt_instant(kk_std_time_instant__instant i, kk_context_t* _ctx) { /* (i : instant) -> std/time/duration/duration */ 
  kk_std_time_timestamp__timestamp t_10158;
  kk_std_time_timestamp__timestamp _x_x787;
  {
    kk_std_time_timestamp__timestamp _x_1 = i.since;
    kk_std_time_instant__timescale _pat_2_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x788 = kk_std_time_timestamp__as_Timestamp(_x_1, _ctx);
    struct kk_std_time_instant_Timescale* _con_x789 = kk_std_time_instant__as_Timescale(_pat_2_0, _ctx);
    kk_std_time_timestamp__timestamp_dup(_x_1, _ctx);
    _x_x787 = _x_1; /*std/time/timestamp/timestamp*/
  }
  kk_std_time_instant__timescale _x_x790;
  {
    kk_std_time_timestamp__timestamp _pat_0_2 = i.since;
    kk_std_time_instant__timescale _x_2 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x791 = kk_std_time_timestamp__as_Timestamp(_pat_0_2, _ctx);
    struct kk_std_time_instant_Timescale* _con_x792 = kk_std_time_instant__as_Timescale(_x_2, _ctx);
    kk_std_time_instant__timescale_dup(_x_2, _ctx);
    kk_std_time_instant__instant_drop(i, _ctx);
    _x_x790 = _x_2; /*std/time/instant/timescale*/
  }
  kk_std_time_instant__timescale _x_x793 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tt, _ctx); /*std/time/instant/timescale*/
  t_10158 = kk_std_time_instant_convert(_x_x787, _x_x790, _x_x793, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_duration__duration d_10156;
  kk_std_num_ddouble__ddouble _x_x794 = kk_std_time_timestamp_unsafe_timespan_withleap(t_10158, _ctx); /*std/time/timestamp/timespan*/
  d_10156 = kk_std_time_duration__new_Duration(_x_x794, _ctx); /*std/time/duration/duration*/
  kk_std_num_ddouble__ddouble _x_x795;
  kk_std_num_ddouble__ddouble _x_x796;
  {
    kk_std_num_ddouble__ddouble _x = d_10156.secs;
    _x_x796 = _x; /*std/time/timestamp/timespan*/
  }
  kk_std_num_ddouble__ddouble _x_x797;
  kk_std_time_duration__duration _x_x798 = kk_std_time_instant_tt2000; /*std/time/duration/duration*/
  {
    kk_std_num_ddouble__ddouble _x_0 = _x_x798.secs;
    _x_x797 = _x_0; /*std/time/timestamp/timespan*/
  }
  _x_x795 = kk_std_num_ddouble__lp__plus__rp_(_x_x796, _x_x797, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_duration__new_Duration(_x_x795, _ctx);
}
 
// Create an instant from a raw TT time since the TT epoch (1977-01-01 TAI)

kk_std_time_instant__instant kk_std_time_instant_duration_fs_tt_instant(kk_std_time_duration__duration tt, kk_context_t* _ctx) { /* (tt : std/time/duration/duration) -> instant */ 
  kk_std_time_duration__duration d_10163 = kk_std_time_duration__lp__dash__rp_(tt, kk_std_time_instant_tt2000, _ctx); /*std/time/duration/duration*/;
  kk_std_time_timestamp__timestamp t_10165;
  kk_std_num_ddouble__ddouble _x_x799;
  {
    kk_std_num_ddouble__ddouble _x = d_10163.secs;
    _x_x799 = _x; /*std/time/timestamp/timespan*/
  }
  int32_t _x_x800;
  kk_integer_t _x_x801;
  kk_std_core_types__optional _match_x163 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x163, _ctx)) {
    kk_box_t _box_x115 = _match_x163._cons._Optional.value;
    kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x115, _ctx);
    kk_integer_dup(_uniq_leap_1214, _ctx);
    kk_std_core_types__optional_drop(_match_x163, _ctx);
    _x_x801 = _uniq_leap_1214; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x163, _ctx);
    _x_x801 = kk_integer_from_small(0); /*int*/
  }
  _x_x800 = kk_integer_clamp32(_x_x801,kk_context()); /*int32*/
  t_10165 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x799, _x_x800, _ctx); /*std/time/timestamp/timestamp*/
  kk_std_time_instant__timescale _x_x802 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
  return kk_std_time_instant__new_Instant(t_10165, _x_x802, _ctx);
}
 
// Show a timestamp with an optional maximum precision (`max-prec` (=`9`)) and
// minimum width for the seconds (=`1`).

kk_string_t kk_std_time_instant_timestamp_fs_show(kk_std_time_timestamp__timestamp t, kk_std_core_types__optional max_prec, kk_std_core_types__optional secs_width, kk_std_core_types__optional unit, kk_context_t* _ctx) { /* (t : std/time/timestamp/timestamp, max-prec : ? int, secs-width : ? int, unit : ? string) -> string */ 
  kk_std_core_types__optional _x_x803;
  kk_box_t _x_x804;
  kk_integer_t _x_x805;
  if (kk_std_core_types__is_Optional(max_prec, _ctx)) {
    kk_box_t _box_x116 = max_prec._cons._Optional.value;
    kk_integer_t _uniq_max_prec_3270 = kk_integer_unbox(_box_x116, _ctx);
    kk_integer_dup(_uniq_max_prec_3270, _ctx);
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x805 = _uniq_max_prec_3270; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(max_prec, _ctx);
    _x_x805 = kk_integer_from_small(9); /*int*/
  }
  _x_x804 = kk_integer_box(_x_x805, _ctx); /*7*/
  _x_x803 = kk_std_core_types__new_Optional(_x_x804, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x806;
  kk_box_t _x_x807;
  kk_integer_t _x_x808;
  if (kk_std_core_types__is_Optional(secs_width, _ctx)) {
    kk_box_t _box_x118 = secs_width._cons._Optional.value;
    kk_integer_t _uniq_secs_width_3274 = kk_integer_unbox(_box_x118, _ctx);
    kk_integer_dup(_uniq_secs_width_3274, _ctx);
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x_x808 = _uniq_secs_width_3274; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(secs_width, _ctx);
    _x_x808 = kk_integer_from_small(1); /*int*/
  }
  _x_x807 = kk_integer_box(_x_x808, _ctx); /*7*/
  _x_x806 = kk_std_core_types__new_Optional(_x_x807, _ctx); /*? 7*/
  kk_std_core_types__optional _x_x809;
  kk_box_t _x_x810;
  kk_string_t _x_x811;
  if (kk_std_core_types__is_Optional(unit, _ctx)) {
    kk_box_t _box_x120 = unit._cons._Optional.value;
    kk_string_t _uniq_unit_3278 = kk_string_unbox(_box_x120);
    kk_string_dup(_uniq_unit_3278, _ctx);
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x811 = _uniq_unit_3278; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(unit, _ctx);
    _x_x811 = kk_string_empty(); /*string*/
  }
  _x_x810 = kk_string_box(_x_x811); /*7*/
  _x_x809 = kk_std_core_types__new_Optional(_x_x810, _ctx); /*? 7*/
  return kk_std_time_timestamp_ts_show(t, _x_x803, _x_x806, _x_x809, _ctx);
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
  kk_std_num_ddouble__ddouble _x_x813;
  double _x_x814;
  double _x_x815;
  kk_std_num_ddouble__ddouble _x_x816 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x816.hi;
    _x_x815 = _x; /*float64*/
  }
  _x_x814 = (-_x_x815); /*float64*/
  double _x_x817;
  double _x_x818;
  kk_std_num_ddouble__ddouble _x_x819 = kk_std_time_instant_mjd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x819.lo;
    _x_x818 = _x_0; /*float64*/
  }
  _x_x817 = (-_x_x818); /*float64*/
  _x_x813 = kk_std_num_ddouble__new_Ddouble(_x_x814, _x_x817, _ctx); /*std/num/ddouble/ddouble*/
  d = kk_std_num_ddouble__lp__plus__rp_(mjd_0, _x_x813, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble days_0 = kk_std_num_ddouble_floor(d, _ctx); /*std/num/ddouble/ddouble*/;
  kk_std_num_ddouble__ddouble frac;
  kk_std_num_ddouble__ddouble _x_x820;
  double _x_x821;
  double _x_x822;
  {
    double _x_1 = days_0.hi;
    _x_x822 = _x_1; /*float64*/
  }
  _x_x821 = (-_x_x822); /*float64*/
  double _x_x823;
  double _x_x824;
  {
    double _x_0_0 = days_0.lo;
    _x_x824 = _x_0_0; /*float64*/
  }
  _x_x823 = (-_x_x824); /*float64*/
  _x_x820 = kk_std_num_ddouble__new_Ddouble(_x_x821, _x_x823, _ctx); /*std/num/ddouble/ddouble*/
  frac = kk_std_num_ddouble__lp__plus__rp_(d, _x_x820, _ctx); /*std/num/ddouble/ddouble*/
  kk_integer_t idays = kk_std_num_ddouble_int(days_0, kk_std_core_types__new_None(_ctx), _ctx); /*int*/;
  {
    struct kk_std_time_instant_Timescale* _con_x825 = kk_std_time_instant__as_Timescale(ts, _ctx);
    kk_std_core_types__maybe _x_2 = _con_x825->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_2, _ctx);
    if (kk_std_core_types__is_Nothing(_x_2, _ctx)) {
      kk_std_num_ddouble__ddouble secs_10175 = kk_std_num_ddouble__lp__star__rp_(frac, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/time/timestamp/timespan*/;
      kk_std_time_timestamp__timestamp t_10178;
      kk_std_core_types__optional _x_x826 = kk_std_core_types__new_Optional(kk_std_num_ddouble__ddouble_box(secs_10175, _ctx), _ctx); /*? 7*/
      kk_std_core_types__optional _x_x827;
      kk_box_t _x_x828;
      kk_integer_t _x_x829;
      kk_std_core_types__optional _match_x162 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x162, _ctx)) {
        kk_box_t _box_x126 = _match_x162._cons._Optional.value;
        kk_integer_t _uniq_leap_1920 = kk_integer_unbox(_box_x126, _ctx);
        kk_integer_dup(_uniq_leap_1920, _ctx);
        kk_std_core_types__optional_drop(_match_x162, _ctx);
        _x_x829 = _uniq_leap_1920; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x162, _ctx);
        _x_x829 = kk_integer_from_small(0); /*int*/
      }
      _x_x828 = kk_integer_box(_x_x829, _ctx); /*7*/
      _x_x827 = kk_std_core_types__new_Optional(_x_x828, _ctx); /*? 7*/
      t_10178 = kk_std_time_timestamp_timestamp_days(idays, _x_x826, _x_x827, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(t_10178, ts, _ctx);
    }
    {
      kk_box_t _fun_unbox_x135 = _x_2._cons.Just.value;
      kk_std_time_timestamp__timestamp _x_x830;
      kk_box_t _x_x831;
      kk_function_t _x_x832 = kk_function_unbox(_fun_unbox_x135, _ctx); /*(days : 136, frac : 137) -> 138*/
      _x_x831 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x832, (_x_x832, kk_integer_box(idays, _ctx), kk_std_num_ddouble__ddouble_box(frac, _ctx), _ctx), _ctx); /*138*/
      _x_x830 = kk_std_time_timestamp__timestamp_unbox(_x_x831, KK_OWNED, _ctx); /*std/time/timestamp/timestamp*/
      return kk_std_time_instant__new_Instant(_x_x830, ts, _ctx);
    }
  }
}
 
// Create an instant given a [julian day](https://en.wikipedia.org/wiki/Julian_day).

kk_std_time_instant__instant kk_std_time_instant_float64_fs_instant_at_jd(double jd_0, kk_std_time_instant__timescale ts, kk_context_t* _ctx) { /* (jd : float64, ts : timescale) -> instant */ 
  kk_std_num_ddouble__ddouble _x_x842;
  kk_std_num_ddouble__ddouble _x_x843 = kk_std_num_ddouble__new_Ddouble(jd_0, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
  kk_std_num_ddouble__ddouble _x_x844;
  double _x_x845;
  double _x_x846;
  kk_std_num_ddouble__ddouble _x_x847 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x = _x_x847.hi;
    _x_x846 = _x; /*float64*/
  }
  _x_x845 = (-_x_x846); /*float64*/
  double _x_x848;
  double _x_x849;
  kk_std_num_ddouble__ddouble _x_x850 = kk_std_time_instant_jd_epoch_delta; /*std/time/timestamp/timespan*/
  {
    double _x_0 = _x_x850.lo;
    _x_x849 = _x_0; /*float64*/
  }
  _x_x848 = (-_x_x849); /*float64*/
  _x_x844 = kk_std_num_ddouble__new_Ddouble(_x_x845, _x_x848, _ctx); /*std/num/ddouble/ddouble*/
  _x_x842 = kk_std_num_ddouble__lp__plus__rp_(_x_x843, _x_x844, _ctx); /*std/num/ddouble/ddouble*/
  return kk_std_time_instant_ddouble_fs_instant_at_mjd(_x_x842, ts, _ctx);
}
 
// Return the modified julian day in a given time scale `ts` for an instant `i`.
// Can also pass an optional `delta` (=`timespan0`) that is added to the raw timestamp of `i`
// before conversion (used in `std/time/time` to take timezones into account)

kk_std_num_ddouble__ddouble kk_std_time_instant_mjd(kk_std_time_instant__instant i, kk_std_time_instant__timescale tscale, kk_std_core_types__optional tzdelta, kk_context_t* _ctx) { /* (i : instant, tscale : timescale, tzdelta : ? std/time/timestamp/timespan) -> std/num/ddouble/ddouble */ 
  kk_std_time_instant__instant i0;
  bool _match_x161;
  kk_string_t _x_x851;
  {
    kk_std_time_timestamp__timestamp _pat_0_0 = i.since;
    kk_std_time_instant__timescale _x_0 = i.ts;
    struct kk_std_time_timestamp_Timestamp* _con_x852 = kk_std_time_timestamp__as_Timestamp(_pat_0_0, _ctx);
    struct kk_std_time_instant_Timescale* _con_x853 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
    kk_std_time_instant__timescale_dup(_x_0, _ctx);
    {
      struct kk_std_time_instant_Timescale* _con_x854 = kk_std_time_instant__as_Timescale(_x_0, _ctx);
      kk_string_t _x = _con_x854->name;
      kk_string_t _pat_0_1 = _con_x854->unit;
      kk_function_t _pat_1_1 = _con_x854->from_tai;
      kk_function_t _pat_2 = _con_x854->to_tai;
      kk_std_core_types__maybe _pat_3 = _con_x854->mb_seconds_in_day;
      kk_std_core_types__maybe _pat_4 = _con_x854->mb_to_mjd2000;
      kk_std_core_types__maybe _pat_5 = _con_x854->mb_from_mjd2000;
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
      _x_x851 = _x; /*string*/
    }
  }
  kk_string_t _x_x855;
  {
    struct kk_std_time_instant_Timescale* _con_x856 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _x_1 = _con_x856->name;
    kk_string_dup(_x_1, _ctx);
    _x_x855 = _x_1; /*string*/
  }
  _match_x161 = kk_string_is_eq(_x_x851,_x_x855,kk_context()); /*bool*/
  if (_match_x161) {
    i0 = i; /*std/time/instant/instant*/
  }
  else {
    kk_std_time_timestamp__timestamp _x_x857;
    kk_std_time_timestamp__timestamp _x_x858;
    {
      kk_std_time_timestamp__timestamp _x_2 = i.since;
      kk_std_time_instant__timescale _pat_2_2 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x859 = kk_std_time_timestamp__as_Timestamp(_x_2, _ctx);
      struct kk_std_time_instant_Timescale* _con_x860 = kk_std_time_instant__as_Timescale(_pat_2_2, _ctx);
      kk_std_time_timestamp__timestamp_dup(_x_2, _ctx);
      _x_x858 = _x_2; /*std/time/timestamp/timestamp*/
    }
    kk_std_time_instant__timescale _x_x861;
    {
      kk_std_time_timestamp__timestamp _pat_0_4 = i.since;
      kk_std_time_instant__timescale _x_3 = i.ts;
      struct kk_std_time_timestamp_Timestamp* _con_x862 = kk_std_time_timestamp__as_Timestamp(_pat_0_4, _ctx);
      struct kk_std_time_instant_Timescale* _con_x863 = kk_std_time_instant__as_Timescale(_x_3, _ctx);
      kk_std_time_instant__timescale_dup(_x_3, _ctx);
      kk_std_time_instant__instant_drop(i, _ctx);
      _x_x861 = _x_3; /*std/time/instant/timescale*/
    }
    kk_std_time_instant__timescale _x_x864 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    _x_x857 = kk_std_time_instant_convert(_x_x858, _x_x861, _x_x864, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x865 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
    i0 = kk_std_time_instant__new_Instant(_x_x857, _x_x865, _ctx); /*std/time/instant/instant*/
  }
  kk_std_num_ddouble__ddouble mjd_0;
  {
    struct kk_std_time_instant_Timescale* _con_x866 = kk_std_time_instant__as_Timescale(tscale, _ctx);
    kk_string_t _pat_0_0_0 = _con_x866->name;
    kk_string_t _pat_1_0_0 = _con_x866->unit;
    kk_function_t _pat_2_4 = _con_x866->from_tai;
    kk_function_t _pat_3_4 = _con_x866->to_tai;
    kk_std_core_types__maybe _pat_4_4 = _con_x866->mb_seconds_in_day;
    kk_std_core_types__maybe _x_4 = _con_x866->mb_to_mjd2000;
    kk_std_core_types__maybe _pat_5_4 = _con_x866->mb_from_mjd2000;
    kk_std_core_types__maybe_dup(_x_4, _ctx);
    if (kk_std_core_types__is_Nothing(_x_4, _ctx)) {
      kk_std_time_instant__instant i_0_10111;
      bool _match_x160;
      kk_string_t _x_x867;
      {
        kk_std_time_timestamp__timestamp _pat_0_0_1 = i0.since;
        kk_std_time_instant__timescale _x_0_0 = i0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x868 = kk_std_time_timestamp__as_Timestamp(_pat_0_0_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x869 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_0_0, _ctx);
        {
          struct kk_std_time_instant_Timescale* _con_x870 = kk_std_time_instant__as_Timescale(_x_0_0, _ctx);
          kk_string_t _x_5 = _con_x870->name;
          kk_string_t _pat_0 = _con_x870->unit;
          kk_function_t _pat_1_5 = _con_x870->from_tai;
          kk_function_t _pat_2_5 = _con_x870->to_tai;
          kk_std_core_types__maybe _pat_3_5 = _con_x870->mb_seconds_in_day;
          kk_std_core_types__maybe _pat_4_5 = _con_x870->mb_to_mjd2000;
          kk_std_core_types__maybe _pat_5_5 = _con_x870->mb_from_mjd2000;
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
            kk_std_core_types__maybe_drop(_pat_5_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_4_5, _ctx);
            kk_std_core_types__maybe_drop(_pat_3_5, _ctx);
            kk_function_drop(_pat_2_5, _ctx);
            kk_function_drop(_pat_1_5, _ctx);
            kk_string_drop(_pat_0, _ctx);
            kk_datatype_ptr_free(_x_0_0, _ctx);
          }
          else {
            kk_string_dup(_x_5, _ctx);
            kk_datatype_ptr_decref(_x_0_0, _ctx);
          }
          _x_x867 = _x_5; /*string*/
        }
      }
      kk_string_t _x_x871;
      {
        struct kk_std_time_instant_Timescale* _con_x872 = kk_std_time_instant__as_Timescale(tscale, _ctx);
        kk_string_t _x_1_0 = _con_x872->name;
        kk_string_dup(_x_1_0, _ctx);
        _x_x871 = _x_1_0; /*string*/
      }
      _match_x160 = kk_string_is_eq(_x_x867,_x_x871,kk_context()); /*bool*/
      if (_match_x160) {
        if kk_likely(kk_datatype_ptr_is_unique(tscale, _ctx)) {
          kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
          kk_std_core_types__maybe_drop(_pat_4_4, _ctx);
          kk_function_drop(_pat_3_4, _ctx);
          kk_function_drop(_pat_2_4, _ctx);
          kk_string_drop(_pat_1_0_0, _ctx);
          kk_string_drop(_pat_0_0_0, _ctx);
          kk_datatype_ptr_free(tscale, _ctx);
        }
        else {
          kk_datatype_ptr_decref(tscale, _ctx);
        }
        i_0_10111 = i0; /*std/time/instant/instant*/
      }
      else {
        kk_std_time_timestamp__timestamp _x_x873;
        kk_std_time_timestamp__timestamp _x_x874;
        {
          kk_std_time_timestamp__timestamp _x_2_0 = i0.since;
          kk_std_time_instant__timescale _pat_2_2_0 = i0.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x875 = kk_std_time_timestamp__as_Timestamp(_x_2_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x876 = kk_std_time_instant__as_Timescale(_pat_2_2_0, _ctx);
          kk_std_time_timestamp__timestamp_dup(_x_2_0, _ctx);
          _x_x874 = _x_2_0; /*std/time/timestamp/timestamp*/
        }
        kk_std_time_instant__timescale _x_x877;
        {
          kk_std_time_timestamp__timestamp _pat_0_4_0 = i0.since;
          kk_std_time_instant__timescale _x_3_0 = i0.ts;
          struct kk_std_time_timestamp_Timestamp* _con_x878 = kk_std_time_timestamp__as_Timestamp(_pat_0_4_0, _ctx);
          struct kk_std_time_instant_Timescale* _con_x879 = kk_std_time_instant__as_Timescale(_x_3_0, _ctx);
          kk_std_time_instant__timescale_dup(_x_3_0, _ctx);
          kk_std_time_instant__instant_drop(i0, _ctx);
          _x_x877 = _x_3_0; /*std/time/instant/timescale*/
        }
        kk_std_time_instant__timescale _x_x880 = kk_std_time_instant__timescale_dup(tscale, _ctx); /*std/time/instant/timescale*/
        _x_x873 = kk_std_time_instant_convert(_x_x874, _x_x877, _x_x880, _ctx); /*std/time/timestamp/timestamp*/
        i_0_10111 = kk_std_time_instant__new_Instant(_x_x873, tscale, _ctx); /*std/time/instant/instant*/
      }
      kk_std_time_instant__instant i1;
      kk_std_time_timestamp__timestamp _x_x881;
      kk_std_num_ddouble__ddouble _x_x882;
      kk_std_num_ddouble__ddouble _x_x883;
      {
        kk_std_time_timestamp__timestamp _x_1_0_0 = i_0_10111.since;
        kk_std_time_instant__timescale _pat_2_1_0_0 = i_0_10111.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x884 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x885 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x886 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0, _ctx);
          kk_std_num_ddouble__ddouble _x_4_0 = _con_x886->since;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_0_0, _ctx);
          }
          _x_x883 = _x_4_0; /*std/time/timestamp/timespan*/
        }
      }
      kk_std_num_ddouble__ddouble _x_x887;
      if (kk_std_core_types__is_Optional(tzdelta, _ctx)) {
        kk_box_t _box_x143 = tzdelta._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_tzdelta_3443 = kk_std_num_ddouble__ddouble_unbox(_box_x143, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x887 = _uniq_tzdelta_3443; /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x887 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
      }
      _x_x882 = kk_std_num_ddouble__lp__plus__rp_(_x_x883, _x_x887, _ctx); /*std/num/ddouble/ddouble*/
      int32_t _x_x888;
      {
        kk_std_time_timestamp__timestamp _x_1_0_0_0 = i_0_10111.since;
        kk_std_time_instant__timescale _pat_2_1_0_0_0 = i_0_10111.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x889 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x890 = kk_std_time_instant__as_Timescale(_pat_2_1_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_0_0, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x891 = kk_std_time_timestamp__as_Timestamp(_x_1_0_0_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_0_0_0 = _con_x891->since;
          int32_t _x_0_0_0 = _con_x891->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_1_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_1_0_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_1_0_0_0, _ctx);
          }
          _x_x888 = _x_0_0_0; /*int32*/
        }
      }
      _x_x881 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x882, _x_x888, _ctx); /*std/time/timestamp/timestamp*/
      kk_std_time_instant__timescale _x_x892;
      {
        kk_std_time_timestamp__timestamp _pat_0_2_0_0 = i_0_10111.since;
        kk_std_time_instant__timescale _x_2_0_0 = i_0_10111.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x893 = kk_std_time_timestamp__as_Timestamp(_pat_0_2_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x894 = kk_std_time_instant__as_Timescale(_x_2_0_0, _ctx);
        kk_std_time_instant__timescale_dup(_x_2_0_0, _ctx);
        kk_std_time_instant__instant_drop(i_0_10111, _ctx);
        _x_x892 = _x_2_0_0; /*std/time/instant/timescale*/
      }
      i1 = kk_std_time_instant__new_Instant(_x_x881, _x_x892, _ctx); /*std/time/instant/instant*/
      kk_std_core_types__tuple2 tuple2_10043;
      kk_std_time_timestamp__timestamp _x_x895;
      {
        kk_std_time_timestamp__timestamp _x_1_0_1 = i1.since;
        kk_std_time_instant__timescale _pat_2_0_0_1 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x896 = kk_std_time_timestamp__as_Timestamp(_x_1_0_1, _ctx);
        struct kk_std_time_instant_Timescale* _con_x897 = kk_std_time_instant__as_Timescale(_pat_2_0_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_1_0_1, _ctx);
        _x_x895 = _x_1_0_1; /*std/time/timestamp/timestamp*/
      }
      tuple2_10043 = kk_std_time_timestamp_days_seconds(_x_x895, _ctx); /*(int, std/num/ddouble/ddouble)*/
      kk_std_num_ddouble__ddouble days_0;
      kk_integer_t _x_x898;
      {
        kk_box_t _box_x144 = tuple2_10043.fst;
        kk_box_t _box_x145 = tuple2_10043.snd;
        kk_integer_t _x_0_0_1 = kk_integer_unbox(_box_x144, _ctx);
        kk_integer_dup(_x_0_0_1, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10043, _ctx);
        _x_x898 = _x_0_0_1; /*int*/
      }
      days_0 = kk_std_num_ddouble_ddouble_int_exp(_x_x898, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      kk_std_core_types__tuple2 tuple2_10044;
      kk_std_time_timestamp__timestamp _x_x899;
      {
        kk_std_time_timestamp__timestamp _x_3_0_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_2_0_1 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x900 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x901 = kk_std_time_instant__as_Timescale(_pat_2_2_0_1, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_0_0, _ctx);
        _x_x899 = _x_3_0_0; /*std/time/timestamp/timestamp*/
      }
      tuple2_10044 = kk_std_time_timestamp_days_seconds(_x_x899, _ctx); /*(int, std/num/ddouble/ddouble)*/
      kk_integer_t i_10045;
      int32_t _x_x902;
      {
        kk_std_time_timestamp__timestamp _x_3_0_0_0 = i1.since;
        kk_std_time_instant__timescale _pat_2_2_0_0_0 = i1.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x903 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x904 = kk_std_time_instant__as_Timescale(_pat_2_2_0_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_3_0_0_0, _ctx);
        kk_std_time_instant__instant_drop(i1, _ctx);
        {
          struct kk_std_time_timestamp_Timestamp* _con_x905 = kk_std_time_timestamp__as_Timestamp(_x_3_0_0_0, _ctx);
          kk_std_num_ddouble__ddouble _pat_0_0_0_0_0 = _con_x905->since;
          int32_t _x_0_0_0_0 = _con_x905->leap32;
          if kk_likely(kk_datatype_ptr_is_unique(_x_3_0_0_0, _ctx)) {
            kk_datatype_ptr_free(_x_3_0_0_0, _ctx);
          }
          else {
            kk_datatype_ptr_decref(_x_3_0_0_0, _ctx);
          }
          _x_x902 = _x_0_0_0_0; /*int32*/
        }
      }
      i_10045 = kk_integer_from_int(_x_x902,kk_context()); /*int*/
      kk_std_num_ddouble__ddouble frac;
      kk_std_num_ddouble__ddouble _x_x906;
      kk_std_num_ddouble__ddouble _x_x907;
      {
        kk_box_t _box_x146 = tuple2_10044.fst;
        kk_box_t _box_x147 = tuple2_10044.snd;
        kk_std_num_ddouble__ddouble _x_2_0_1 = kk_std_num_ddouble__ddouble_unbox(_box_x147, KK_BORROWED, _ctx);
        kk_std_core_types__tuple2_drop(tuple2_10044, _ctx);
        _x_x907 = _x_2_0_1; /*std/num/ddouble/ddouble*/
      }
      kk_std_num_ddouble__ddouble _x_x908 = kk_std_num_ddouble_ddouble_int_exp(i_10045, kk_integer_from_small(0), _ctx); /*std/num/ddouble/ddouble*/
      _x_x906 = kk_std_num_ddouble__lp__plus__rp_(_x_x907, _x_x908, _ctx); /*std/num/ddouble/ddouble*/
      frac = kk_std_num_ddouble__lp__fs__rp_(_x_x906, kk_std_time_timestamp_solar_secs_per_day, _ctx); /*std/num/ddouble/ddouble*/
      mjd_0 = kk_std_num_ddouble__lp__plus__rp_(days_0, frac, _ctx); /*std/num/ddouble/ddouble*/
    }
    else {
      kk_box_t _fun_unbox_x153 = _x_4._cons.Just.value;
      if kk_likely(kk_datatype_ptr_is_unique(tscale, _ctx)) {
        kk_std_core_types__maybe_drop(_x_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_5_4, _ctx);
        kk_std_core_types__maybe_drop(_pat_4_4, _ctx);
        kk_function_drop(_pat_3_4, _ctx);
        kk_function_drop(_pat_2_4, _ctx);
        kk_string_drop(_pat_1_0_0, _ctx);
        kk_string_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(tscale, _ctx);
      }
      else {
        kk_datatype_ptr_decref(tscale, _ctx);
      }
      kk_box_t _x_x909;
      kk_function_t _x_x916 = kk_function_unbox(_fun_unbox_x153, _ctx); /*(t : 154, tzdelta : 155) -> 156*/
      kk_box_t _x_x910;
      kk_std_time_timestamp__timestamp _x_x911;
      {
        kk_std_time_timestamp__timestamp _x_4_0_0 = i0.since;
        kk_std_time_instant__timescale _pat_2_4_0_0 = i0.ts;
        struct kk_std_time_timestamp_Timestamp* _con_x912 = kk_std_time_timestamp__as_Timestamp(_x_4_0_0, _ctx);
        struct kk_std_time_instant_Timescale* _con_x913 = kk_std_time_instant__as_Timescale(_pat_2_4_0_0, _ctx);
        kk_std_time_timestamp__timestamp_dup(_x_4_0_0, _ctx);
        kk_std_time_instant__instant_drop(i0, _ctx);
        _x_x911 = _x_4_0_0; /*std/time/timestamp/timestamp*/
      }
      _x_x910 = kk_std_time_timestamp__timestamp_box(_x_x911, _ctx); /*154*/
      kk_box_t _x_x914;
      kk_std_num_ddouble__ddouble _x_x915;
      if (kk_std_core_types__is_Optional(tzdelta, _ctx)) {
        kk_box_t _box_x159 = tzdelta._cons._Optional.value;
        kk_std_num_ddouble__ddouble _uniq_tzdelta_3443_0 = kk_std_num_ddouble__ddouble_unbox(_box_x159, KK_BORROWED, _ctx);
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x915 = _uniq_tzdelta_3443_0; /*std/time/timestamp/timespan*/
      }
      else {
        kk_std_core_types__optional_drop(tzdelta, _ctx);
        _x_x915 = kk_std_num_ddouble_zero; /*std/time/timestamp/timespan*/
      }
      _x_x914 = kk_std_num_ddouble__ddouble_box(_x_x915, _ctx); /*155*/
      _x_x909 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x916, (_x_x916, _x_x910, _x_x914, _ctx), _ctx); /*156*/
      mjd_0 = kk_std_num_ddouble__ddouble_unbox(_x_x909, KK_OWNED, _ctx); /*std/num/ddouble/ddouble*/
    }
  }
  return kk_std_num_ddouble__lp__plus__rp_(mjd_0, kk_std_time_instant_mjd_epoch_delta, _ctx);
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
  kk_std_num_int32__init(_ctx);
  kk_std_num_float64__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x336;
    kk_define_string_literal(, _s_x337, 3, "TAI", _ctx)
    _x_x336 = kk_string_dup(_s_x337, _ctx); /*string*/
    kk_std_time_instant_ts_tai = kk_std_time_instant_tai_timescale(_x_x336, kk_std_core_types__new_None(_ctx), _ctx); /*std/time/instant/timescale*/
  }
  {
    kk_std_time_timestamp__timestamp t_10090;
    kk_std_num_ddouble__ddouble _x_x730;
    kk_std_time_duration__duration _x_x731 = kk_std_time_duration_duration0; /*std/time/duration/duration*/
    {
      kk_std_num_ddouble__ddouble _x = _x_x731.secs;
      _x_x730 = _x; /*std/time/timestamp/timespan*/
    }
    int32_t _x_x732;
    kk_integer_t _x_x733;
    kk_std_core_types__optional _match_x171 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x171, _ctx)) {
      kk_box_t _box_x89 = _match_x171._cons._Optional.value;
      kk_integer_t _uniq_leap_1214 = kk_integer_unbox(_box_x89, _ctx);
      kk_integer_dup(_uniq_leap_1214, _ctx);
      kk_std_core_types__optional_drop(_match_x171, _ctx);
      _x_x733 = _uniq_leap_1214; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x171, _ctx);
      _x_x733 = kk_integer_from_small(0); /*int*/
    }
    _x_x732 = kk_integer_clamp32(_x_x733,kk_context()); /*int32*/
    t_10090 = kk_std_time_timestamp__new_Timestamp(kk_reuse_null, 0, _x_x730, _x_x732, _ctx); /*std/time/timestamp/timestamp*/
    kk_std_time_instant__timescale _x_x734 = kk_std_time_instant__timescale_dup(kk_std_time_instant_ts_tai, _ctx); /*std/time/instant/timescale*/
    kk_std_time_instant_epoch = kk_std_time_instant__new_Instant(t_10090, _x_x734, _ctx); /*std/time/instant/instant*/
  }
  {
    kk_std_time_duration__duration _b_x92_93;
    double _b_x91_94;
    kk_std_core_types__optional _match_x170 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x170, _ctx)) {
      kk_box_t _box_x90 = _match_x170._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x90, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x170, _ctx);
      _b_x91_94 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x170, _ctx);
      _b_x91_94 = 0x0p+0; /*float64*/
    }
    kk_std_num_ddouble__ddouble _x_x735;
    kk_std_core_types__optional _x_x736 = kk_std_core_types__new_Optional(kk_double_box(_b_x91_94, _ctx), _ctx); /*? 7*/
    _x_x735 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_small(-19), _x_x736, _ctx); /*std/time/timestamp/timespan*/
    _b_x92_93 = kk_std_time_duration__new_Duration(_x_x735, _ctx); /*std/time/duration/duration*/
    kk_string_t _x_x737;
    kk_define_string_literal(, _s_x738, 3, "GPS", _ctx)
    _x_x737 = kk_string_dup(_s_x738, _ctx); /*string*/
    kk_std_core_types__optional _x_x739 = kk_std_core_types__new_Optional(kk_std_time_duration__duration_box(_b_x92_93, _ctx), _ctx); /*? 7*/
    kk_std_time_instant_ts_gps = kk_std_time_instant_tai_timescale(_x_x737, _x_x739, _ctx); /*std/time/instant/timescale*/
  }
  {
    double _b_x96_97;
    kk_std_core_types__optional _match_x169 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x169, _ctx)) {
      kk_box_t _box_x95 = _match_x169._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x95, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x169, _ctx);
      _b_x96_97 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x169, _ctx);
      _b_x96_97 = 0x0p+0; /*float64*/
    }
    kk_std_num_ddouble__ddouble _x_x740;
    kk_std_core_types__optional _x_x741 = kk_std_core_types__new_Optional(kk_double_box(_b_x96_97, _ctx), _ctx); /*? 7*/
    _x_x740 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_int(630720000, _ctx), _x_x741, _ctx); /*std/time/timestamp/timespan*/
    kk_std_time_instant_gps2000 = kk_std_time_duration__new_Duration(_x_x740, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_string_t _x_x779;
    kk_define_string_literal(, _s_x780, 2, "TT", _ctx)
    _x_x779 = kk_string_dup(_s_x780, _ctx); /*string*/
    kk_std_core_types__optional _x_x781;
    kk_box_t _x_x782;
    kk_std_time_duration__duration _x_x783;
    kk_std_num_ddouble__ddouble _x_x784 = kk_std_num_ddouble__new_Ddouble(0x1.0178d4fdf3b64p5, 0x0p+0, _ctx); /*std/num/ddouble/ddouble*/
    _x_x783 = kk_std_time_duration__new_Duration(_x_x784, _ctx); /*std/time/duration/duration*/
    _x_x782 = kk_std_time_duration__duration_box(_x_x783, _ctx); /*7*/
    _x_x781 = kk_std_core_types__new_Optional(_x_x782, _ctx); /*? 7*/
    kk_std_time_instant_ts_tt = kk_std_time_instant_tai_timescale(_x_x779, _x_x781, _ctx); /*std/time/instant/timescale*/
  }
  {
    double _b_x113_114;
    kk_std_core_types__optional _match_x164 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x164, _ctx)) {
      kk_box_t _box_x112 = _match_x164._cons._Optional.value;
      double _uniq_frac_155 = kk_double_unbox(_box_x112, KK_BORROWED, _ctx);
      kk_std_core_types__optional_drop(_match_x164, _ctx);
      _b_x113_114 = _uniq_frac_155; /*float64*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x164, _ctx);
      _b_x113_114 = 0x0p+0; /*float64*/
    }
    kk_std_num_ddouble__ddouble _x_x785;
    kk_std_core_types__optional _x_x786 = kk_std_core_types__new_Optional(kk_double_box(_b_x113_114, _ctx), _ctx); /*? 7*/
    _x_x785 = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_int(630720000, _ctx), _x_x786, _ctx); /*std/time/timestamp/timespan*/
    kk_std_time_instant_tt2000 = kk_std_time_duration__new_Duration(_x_x785, _ctx); /*std/time/duration/duration*/
  }
  {
    kk_std_time_instant_jd_epoch_delta = kk_std_num_ddouble__new_Ddouble(0x1.24f804p21, 0x0p+0, _ctx); /*std/time/timestamp/timespan*/
  }
  {
    kk_std_time_instant_mjd_epoch_delta = kk_std_time_timestamp_int_fs_timespan(kk_integer_from_int(51544, _ctx), kk_std_core_types__new_None(_ctx), _ctx); /*std/time/timestamp/timespan*/
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
  kk_std_num_float64__done(_ctx);
  kk_std_num_int32__done(_ctx);
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
